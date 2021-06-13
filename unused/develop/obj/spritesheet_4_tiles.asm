;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.1.4 #12246 (Mac OS X x86_64)
;--------------------------------------------------------
	.module spritesheet_4_tiles
	.optsdcc -mgbz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _spritesheet_4_tiles
	.globl ___bank_spritesheet_4_tiles
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
___bank_spritesheet_4_tiles	=	0x00ff
_spritesheet_4_tiles:
	.dw #0x0004
	.db #0x07	; 7
	.db #0x07	; 7
	.db #0x08	; 8
	.db #0x0f	; 15
	.db #0x11	; 17
	.db #0x1e	; 30
	.db #0x20	; 32
	.db #0x3f	; 63
	.db #0x20	; 32
	.db #0x3f	; 63
	.db #0x2e	; 46
	.db #0x3f	; 63
	.db #0x3f	; 63
	.db #0x30	; 48	'0'
	.db #0x3f	; 63
	.db #0x3f	; 63
	.db #0x3a	; 58
	.db #0x3f	; 63
	.db #0x39	; 57	'9'
	.db #0x36	; 54	'6'
	.db #0x3f	; 63
	.db #0x38	; 56	'8'
	.db #0x2f	; 47
	.db #0x39	; 57	'9'
	.db #0x2f	; 47
	.db #0x34	; 52	'4'
	.db #0x6f	; 111	'o'
	.db #0x74	; 116	't'
	.db #0x47	; 71	'G'
	.db #0x7b	; 123
	.db #0x81	; 129
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xe0	; 224
	.db #0x10	; 16
	.db #0xf0	; 240
	.db #0xe8	; 232
	.db #0x18	; 24
	.db #0x64	; 100	'd'
	.db #0x9c	; 156
	.db #0x1c	; 28
	.db #0xfc	; 252
	.db #0xdc	; 220
	.db #0xe4	; 228
	.db #0xf4	; 244
	.db #0x1c	; 28
	.db #0xfc	; 252
	.db #0xfc	; 252
	.db #0x5c	; 92
	.db #0xfc	; 252
	.db #0x9c	; 156
	.db #0x6c	; 108	'l'
	.db #0xfc	; 252
	.db #0x1c	; 28
	.db #0xf4	; 244
	.db #0x9c	; 156
	.db #0xf4	; 244
	.db #0x2c	; 44
	.db #0xf4	; 244
	.db #0x2c	; 44
	.db #0xe2	; 226
	.db #0xde	; 222
	.db #0x81	; 129
	.db #0x7f	; 127
	.area _INITIALIZER
	.area _CABS (ABS)
