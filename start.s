.text
.global _start

_start:
	  b start
    .word 0x00000000
	  .word 0x00000000
	  .word 0x00000000
	  .word 0x00000000
	  .word 0x00000000
	  .word 0x00000000
	  .word 0x00000000
start:
	  b main
