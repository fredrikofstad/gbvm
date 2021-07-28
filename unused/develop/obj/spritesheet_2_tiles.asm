;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.1.4 #12246 (Mac OS X x86_64)
;--------------------------------------------------------
	.module spritesheet_2_tiles
	.optsdcc -mgbz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _spritesheet_2_tiles
	.globl ___bank_spritesheet_2_tiles
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area _DABS (ABS)
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area _HOME
	.area _GSINIT
	.area _GSFINAL
	.area _GSINIT
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area _HOME
	.area _HOME
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area _CODE_255
	.area _CODE_255
___bank_spritesheet_2_tiles	=	0x00ff
_spritesheet_2_tiles:
	.dw #0x0004
	.db #0x7f	; 127
	.db #0x7f	; 127
	.db #0x69	; 105	'i'
	.db #0x7e	; 126
	.db #0x74	; 116	't'
	.db #0x7f	; 127
	.db #0x2a	; 42
	.db #0x3f	; 63
	.db #0x14	; 20
	.db #0x1f	; 31
	.db #0x0a	; 10
	.db #0x0f	; 15
	.db #0x04	; 4
	.db #0x07	; 7
	.db #0x03	; 3
	.db #0x03	; 3
	.db #0x02	; 2
	.db #0x03	; 3
	.db #0x03	; 3
	.db #0x03	; 3
	.db #0x02	; 2
	.db #0x03	; 3
	.db #0x03	; 3
	.db #0x03	; 3
	.db #0x0e	; 14
	.db #0x0f	; 15
	.db #0x33	; 51	'3'
	.db #0x3f	; 63
	.db #0x47	; 71	'G'
	.db #0x78	; 120	'x'
	.db #0x31	; 49	'1'
	.db #0x3e	; 62
	.db #0xfe	; 254
	.db #0xfe	; 254
	.db #0xfa	; 250
	.db #0x06	; 6
	.db #0x32	; 50	'2'
	.db #0xce	; 206
	.db #0x64	; 100	'd'
	.db #0x9c	; 156
	.db #0x48	; 72	'H'
	.db #0xb8	; 184
	.db #0x90	; 144
	.db #0x70	; 112	'p'
	.db #0xa0	; 160
	.db #0x60	; 96
	.db #0xc0	; 192
	.db #0xc0	; 192
	.db #0x40	; 64
	.db #0xc0	; 192
	.db #0xc0	; 192
	.db #0x40	; 64
	.db #0xc0	; 192
	.db #0x40	; 64
	.db #0xc0	; 192
	.db #0x40	; 64
	.db #0xf0	; 240
	.db #0x70	; 112	'p'
	.db #0xcc	; 204
	.db #0x7c	; 124
	.db #0xf2	; 242
	.db #0x0e	; 14
	.db #0xcc	; 204
	.db #0x3c	; 60
	.area _INITIALIZER
	.area _CABS (ABS)