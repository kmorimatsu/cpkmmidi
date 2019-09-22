/*
   This program is provided under the LGPL license ver 2.
   Written by Katsumi.
   http://hp.vector.co.jp/authors/VA016157/
   kmorimatsu@users.sourceforge.jp
*/

/*
	Environment(machine)-specific basic functions follow 
*/


/*
	_getCode() macro (as inline function) that fetches a code using PC, and increment PC.
	This macro is used more frequently in time than getCode() function, 
	so faster code is required than getCode() function.
*/
extern unsigned char* RAM;
extern unsigned char* VRAM;
extern const unsigned char monitor[];
extern const unsigned char cpmboot[];
#define _getCode() (\
	(regPC<0x8000) ? (\
		use_rom() ? (\
			(regPC<0x7200) ? cpmboot[regPC++] : monitor[(regPC++)-0x7200]\
		):(\
			RAM[regPC++]\
		)\
	):(\
		(regPC<0xe000) ?RAM[regPC++]:0xC7\
	))

/*
	RAM and I/O interface functions follows.
*/

UINT8 readMemory(UINT16 addr);
void writeMemory(UINT16 addr, UINT8 data);
UINT8 readIO(UINT8 addrL, UINT8 addrH);
void writeIO(UINT8 addrL, UINT8 addrH, UINT8 data);

/*
	Macros
*/
extern unsigned char g_portC;
#define use_rom() (g_portC&0x02)

/*
	BIOS environment
*/

/*
; Environ specific codes jump table (infinite loop for emulator)
romCONST:  JP romCONST  ;0xd233
			//0C-0F CONST (console status; Returns its status in A; 0 if no character is ready, 0FFh if one is.)
romCONIN:  JP romCONIN  ;0xd236
			//14-17 CONIN (console in; Wait until the keyboard is ready to provide a character, and return it in A.)
romCONOUT: JP romCONOUT ;0xd239
			//1C-1F CONOUT (console out; Write the character in C to the screen.)
romREAD:   JP romREAD   ;0xd23c
			// Read the currently set track and sector at the current DMA address. Returns A=0 for OK
romWRITE:  JP romWRITE  ;0xd23f
			// Write the currently set track and sector. Returns A=0 for OK
*/

int cpm_const(void);
unsigned char cpm_conin(void);
void cpm_conout(unsigned char ascii);
void cpm_read(unsigned short address);
void cpm_write(unsigned short address);
void codeC9();
#define PRECODEC3 \
	if (0xd234<=regPC && regPC<=0xd240) { \
		switch(regPC){ \
			case 0xd234: \
				if (cpm_const()) loadA(0xff); \
				else loadA(0x00);\
				codeC9(); \
				return; \
			case 0xd237: \
				if (!cpm_const()) break; \
				loadA(cpm_conin()); \
				codeC9(); \
				return; \
			case 0xd23a: \
				cpm_conout(regC); \
				codeC9(); \
				return; \
			case 0xd23d: \
				cpm_read(regHL); \
				loadA(0x00); \
				codeC9(); \
				return; \
			case 0xd240: \
				cpm_write(regHL); \
				loadA(0x00); \
				codeC9(); \
				return; \
			default: \
				break; \
		} \
	}
