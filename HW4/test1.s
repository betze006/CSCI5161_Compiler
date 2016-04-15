	.text
main:
	sw $ra, 0($sp)
	sw $fp, -4($sp)
	add $fp, $sp, -4
	add $sp, $sp, -8
	lw $2, _framesize_main
	sub $sp, $sp, $2
	sw $8, 32($sp)
	sw $9, 28($sp)
	sw $10, 24($sp)
	sw $11, 20($sp)
	sw $12, 16($sp)
	sw $13, 12($sp)
	sw $14, 8($sp)
	sw $15, 4($sp)

_begin_main:
	li $8, 100
	sw $8, _globalint
	lw $8, _globalint
	li $9, 20
	mul $10, $8, $9
	li $9, 5
	sub $8, $10, $9
	sw $8, -16($fp)
	lw $8, -16($fp)
	li $9, 5
	div $10, $8, $9
	sw $10, -20($fp)
	lw $10, -20($fp)
	li $v0, 1
	move $a0, $10
	syscall

_end_main:
	lw $8, 32($sp)
	lw $9, 28($sp)
	lw $10, 24($sp)
	lw $11, 20($sp)
	lw $12, 16($sp)
	lw $13, 12($sp)
	lw $14, 8($sp)
	lw $15, 4($sp)
	lw $ra, 4($fp)
	add $sp, $fp, 4
	lw $fp, 0($fp)
	li $v0, 10
	syscall

	.data
_framesize_main: .word 36
_g: .word 0
_globalint: .word 0

