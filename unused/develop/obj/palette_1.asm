;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.1.4 #12246 (Mac OS X x86_64)
;--------------------------------------------------------
	.module palette_1
	.optsdcc -mgbz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _palette_1
	.globl ___bank_palette_1
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
___bank_palette_1	=	0x00ff
_palette_1:
	.db #0xff	; 255
	.db #0xd0	; 208
	.db #0xe4	; 228
	.dw #0x7fff
	.dw #0x56b5
	.dw #0x294a
	.dw #0x0000
	.dw #0x7fff
	.dw #0x56b5
	.dw #0x294a
	.dw #0x0000
	.dw #0x7fff
	.dw #0x56b5
	.dw #0x294a
	.dw #0x0000
	.dw #0x7fff
	.dw #0x56b5
	.dw #0x294a
	.dw #0x0000
	.dw #0x7fff
	.dw #0x56b5
	.dw #0x294a
	.dw #0x0000
	.dw #0x7fff
	.dw #0x56b5
	.dw #0x294a
	.dw #0x0000
	.dw #0x7fff
	.dw #0x56b5
	.dw #0x294a
	.dw #0x0000
	.dw #0x7fff
	.dw #0x56b5
	.dw #0x294a
	.dw #0x0000
	.area _INITIALIZER
	.area _CABS (ABS)
