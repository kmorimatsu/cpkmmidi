/*
   This file is provided under the LGPL license ver 2.1.
   Written by Katsumi.
   https://github.com/kmorimatsu/
*/

#include "z80.h"
#include "peripheral.h"
#include "monitor.h"
#include "./main.h"

#define VIDEOHEIGHT 30

// RAM implementation for 0x0000 - 0xdfff
unsigned char* RAM=(unsigned char*)0xa0002000;

unsigned char g_portC;
int g_cursor;
unsigned char g_cursorchar;
unsigned char g_blinktimer;
unsigned char g_caps;
unsigned char g_cpmkeybuff[8];
unsigned char g_cpmkeybuffwrite;
unsigned char g_cpmkeybuffread;

void peripheral_init(void){
	// Use rom when starting
	g_portC=0xff;
	// Clear cursor
	g_cursor=0;
	g_cursorchar=0x20;
	g_blinktimer=0;
	// Initialize key
	g_caps=0;
	led_green();
	g_cpmkeybuffwrite=0;
	g_cpmkeybuffread=0;
	// Enable software intterupt for key
	IPC0bits.CS0IP=3;
	IPC0bits.CS0IS=0;
	IFS0bits.CS0IF=0;
	IEC0bits.CS0IE=1;
}

UINT8 readMemory(UINT16 addr){
	if (addr<0x8000) {
		if (use_rom()) {
			if (addr<0x7200) return cpmboot[addr];
			else return monitor[addr-0x7200];
		} else {
			return RAM[addr];
		}
	} else if (addr<0xe000) {
		return RAM[addr];
	} else return 0xC7; // RST00
}

void writeMemory(UINT16 addr, UINT8 data){
	if (addr<0x8000) {
		if (use_rom()) return; // ROM region cannot be written.
		RAM[addr]=data;
	} else if (addr<0xe000) {
		RAM[addr]=data;
	} else return;
}

// Only Port C1 is used for ROM/RAM selection.
UINT8 readIO(UINT8 addrL, UINT8 addrH){
	switch (addrL&0x03) {
		case 0: // PORT A
		case 1: // PORT B
			return 0xff; 
		case 2: // PORT C
			return g_portC;
		default: // control
			return 0xff; 
	}
}
void writeIO(UINT8 addrL, UINT8 addrH, UINT8 data){
	switch (addrL&0x03) {
		case 0: // PORT A
		case 1: // PORT B
			return;
		case 2: // PORT C
			g_portC=data;
			return;
		default: // control
			// portC-controling code will be here
			if (data&0x80) return; // Ignore configuration
			if (data&0x01) {
				// set bit
				data&=0x0e;
				data>>=1;
				data=1<<data;
				data|=g_portC;
				writeIO(0x02,addrH,data);
			} else {
				// clear bit
				data&=0x0e;
				data>>=1;
				data=1<<data;
				data^=0xff;
				data&=g_portC;
				writeIO(0x02,addrH,data);
			}
			return;
	}
}

void cpm_conout(unsigned char ascii){
	// Restore cursor
	if (g_blinktimer<30) {
		printchar(g_cursor,g_cursorchar);
	}
	switch(ascii){
		case 0x00: // null
		case 0x02: // ^B
		case 0x03: // ^C
		case 0x04: // ^D
		case 0x05: // ^E
		case 0x0c: // ^L
		case 0x0e: // ^N
		case 0x0f: // ^O
		case 0x10: // ^P
		case 0x11: // ^Q
		case 0x12: // ^R
		case 0x13: // ^S
		case 0x14: // ^T
		case 0x15: // ^U
		case 0x16: // ^V
		case 0x17: // ^W
		case 0x19: // ^Y
			break;
		case 0x01: // ^A
			g_cursor--;
			if (g_cursor<0) g_cursor=0;
			break;
		case 0x06: // ^F
			g_cursor++;
			if (80*24<=g_cursor) g_cursor=80*24-1;
			break;
		case 0x07: // ^G
			printchar(g_cursor,0x20);
			break;
		case 0x09: // ^I (TAB)
			if ((g_cursor%80)<70) {
				g_cursor+=10-(g_cursor%10);
			}
			break;
		case 0x08: // ^H (BS)
			g_cursor--;
			if (g_cursor<0) g_cursor=0;
			printchar(g_cursor,0x20);
			break;
		case 0x0a: // (^J) LF
			g_cursor+=80;
			break;
		case 0x0b: // ^K
			/*for(var i=g_cursor;i<parseInt(g_cursor/80)*80+80;i++){
				this.write(i,0x20);
			}*/
			if (80<=g_cursor) g_cursor-=80;
			break;
		case 0x0d: // ^M (CR)
			g_cursor=g_cursor/80;
			g_cursor=g_cursor*80;
			break;
		case 0x18: // ^X
/*			for(var i=i<parseInt(g_cursor/80)*80;i<g_cursor;i++){
				this.write(i,0x20);
			}
			g_cursor=1+g_cursor/80;
			g_cursor=g_cursor*80;
*/
			break;
		case 0x7f: // DEL
			break;
		case 0x1a: // ^Z
			clearscreen();
			g_cursor=0;
			break;
		case 0x1c: // ^\
			g_cursor++;
			break;
		case 0x1d: // ^]
			if (0<g_cursor) g_cursor--;
			break;
		case 0x1e: // ^^
			g_cursor=0;
			break;
		default:
			printchar(g_cursor,ascii);
			g_cursor++;
			break;
	}
	// Check if scroll up is needed.
	if (80*VIDEOHEIGHT<=g_cursor) {
		vertical_scroll();
		g_cursor-=80;
	}
	// Update cursor
	g_cursorchar=VRAM[g_cursor];
	g_blinktimer=58;
	// Reset Z80 timer
	reset_g_timer1();
}

int cpm_const(void){
	return (g_cpmkeybuffread!=g_cpmkeybuffwrite);
}
unsigned char cpm_conin(void){
	unsigned char ret;
	ret=g_cpmkeybuff[g_cpmkeybuffread++];
	g_cpmkeybuffread&=7;
	return ret;
}


const unsigned char keytable_nonshift[]={
	'1','3','5','7','9','-',0,0,  // line 0
	'2','4','6','8','0',0,0,0,    // line 1
	'q','e','t','u','o','=',0,0 , // line 2
	'w','r','y','i','p',0,0,0,    // line 3
	'a','d','g','j','l',0,0,0,    // line 4
	's','f','h','k',';',0,0,0,    // line 5
	'z','c','b','m','.',0,0,0,    // line 6
	'x','v','n',',','/',0,0,0,    // line 7
	0,0x08,0,0x0c,0x0d,0,0,0,     // line 8
	0x1e,0x20,0x0a,0,0,0,0,0,     // line 9
};

const unsigned char keytable_shift[]={
	'!','#','%','\'',')','+',0,0, // line 0
	'"','$','&','(',0,0,0,0,      // line 1
	'<',0,']','@',':','*',0,0,    // line 2
	'>','[','\\','?','^',0,0,0,   // line 3
	0,0,0,0,0,0,0,0,              // line 4
	0,0,0,0,0,0,0,0,              // line 5
	0,0,0,0,0,0,0,0,              // line 6
	0,0,0,'`',0,0,0,0,            // line 7
	0,0,0,0x01,0x0a,0,0,0,        // line 8
	0x1a,0x20,0x0b,0,0,0,0,0,     // line 9
};

const unsigned char keytable_caps[]={
	'1','3','5','7','9','-',0,0,  // line 0
	'2','4','6','8','0',0,0,0,    // line 1
	'Q','E','T','U','O','=',0,0 , // line 2
	'W','R','Y','I','P',0,0,0,    // line 3
	'A','D','G','J','L',0,0,0,    // line 4
	'S','F','H','K',';',0,0,0,    // line 5
	'Z','C','B','M','.',0,0,0,    // line 6
	'X','V','N',',','/',0,0,0,    // line 7
	0,0x08,0,0x0c,0x0d,0,0,0,     // line 8
	0x1e,0x20,0x0a,0,0,0,0,0,     // line 9
};

char keypos(unsigned char data) {
	if (data&0x1) return 0;
	if (data&0x2) return 1;
	if (data&0x4) return 2;
	if (data&0x8) return 3;
	if (data&0x10) return 4;
	if (data&0x20) return 5;
	if (data&0x40) return 6;
	if (data&0x80) return 7;
	return -1;
}
unsigned char key_ascii(void){
	unsigned char keydata;
	if (g_keymatrix2[8]&0x21) {
		// Shift key is pressed.
		if (keydata=g_keymatrix2[0]) return keytable_shift[0x00+keypos(keydata)];
		if (keydata=g_keymatrix2[1]) return keytable_shift[0x08+keypos(keydata)];
		if (keydata=g_keymatrix2[2]) return keytable_shift[0x10+keypos(keydata)];
		if (keydata=g_keymatrix2[3]) return keytable_shift[0x18+keypos(keydata)];
		if (keydata=g_keymatrix2[4]) return keytable_shift[0x20+keypos(keydata)];
		if (keydata=g_keymatrix2[5]) return keytable_shift[0x28+keypos(keydata)];
		if (keydata=g_keymatrix2[6]) return keytable_shift[0x30+keypos(keydata)];
		if (keydata=g_keymatrix2[7]) return keytable_shift[0x38+keypos(keydata)];
		if (keydata=(g_keymatrix2[8]&0xde)) return keytable_shift[0x40+keypos(keydata)];
		if (keydata=g_keymatrix2[9]) return keytable_shift[0x48+keypos(keydata)];
		return 0;
	} else if (g_caps) {
		// Caps key is locked.
		if (keydata=g_keymatrix2[0]) return keytable_caps[0x00+keypos(keydata)];
		if (keydata=g_keymatrix2[1]) return keytable_caps[0x08+keypos(keydata)];
		if (keydata=g_keymatrix2[2]) return keytable_caps[0x10+keypos(keydata)];
		if (keydata=g_keymatrix2[3]) return keytable_caps[0x18+keypos(keydata)];
		if (keydata=g_keymatrix2[4]) return keytable_caps[0x20+keypos(keydata)];
		if (keydata=g_keymatrix2[5]) return keytable_caps[0x28+keypos(keydata)];
		if (keydata=g_keymatrix2[6]) return keytable_caps[0x30+keypos(keydata)];
		if (keydata=g_keymatrix2[7]) return keytable_caps[0x38+keypos(keydata)];
		if (keydata=(g_keymatrix2[8]&0xde)) return keytable_caps[0x40+keypos(keydata)];
		if (keydata=g_keymatrix2[9]) return keytable_caps[0x48+keypos(keydata)];
		return 0;
	} else {
		// Shift key is not pressed.
		if (keydata=g_keymatrix2[0]) return keytable_nonshift[0x00+keypos(keydata)];
		if (keydata=g_keymatrix2[1]) return keytable_nonshift[0x08+keypos(keydata)];
		if (keydata=g_keymatrix2[2]) return keytable_nonshift[0x10+keypos(keydata)];
		if (keydata=g_keymatrix2[3]) return keytable_nonshift[0x18+keypos(keydata)];
		if (keydata=g_keymatrix2[4]) return keytable_nonshift[0x20+keypos(keydata)];
		if (keydata=g_keymatrix2[5]) return keytable_nonshift[0x28+keypos(keydata)];
		if (keydata=g_keymatrix2[6]) return keytable_nonshift[0x30+keypos(keydata)];
		if (keydata=g_keymatrix2[7]) return keytable_nonshift[0x38+keypos(keydata)];
		if (keydata=(g_keymatrix2[8]&0xde)) return keytable_nonshift[0x40+keypos(keydata)];
		if (keydata=g_keymatrix2[9]) return keytable_nonshift[0x48+keypos(keydata)];
		return 0;
	}
}

void __ISR(_CORE_SOFTWARE_0_VECTOR,IPL3SOFT) CS0Hanlder(void){
	static unsigned char s_prevchar=0;
	static unsigned char s_prevcaps=0;
	unsigned char curchar;
	// Drop flag
	IFS0bits.CS0IF=0;
	// Read key
	curchar=key_ascii();
	// Check ctrl
	if (g_keymatrix2[9]&0x80) {
		if ('A'<=curchar && curchar <='_' || 'a'<=curchar && curchar<='z') {
			curchar&=0x1f;
		}
	}
	// Update buffer if key is just pressed
	if (s_prevchar!=curchar && curchar) {
		g_cpmkeybuff[g_cpmkeybuffwrite++]=curchar;
		g_cpmkeybuffwrite&=7;
	}
	// Update static data
	s_prevchar=curchar;
	// Check caps key
	curchar=g_keymatrix2[6]&0x20;
	if (s_prevcaps!=curchar && curchar) {
		if (g_caps) {
			g_caps=0;
			led_green();
		} else {
			g_caps=1;
			led_red();
		}
	}
	// Update static data
	s_prevcaps=curchar;
	// Blink cursor
	g_blinktimer++;
	if (59<g_blinktimer) {
		g_blinktimer=0;
		printchar(g_cursor,0x7f);
	} else if (30==g_blinktimer) {
		printchar(g_cursor,g_cursorchar);
	}
}
