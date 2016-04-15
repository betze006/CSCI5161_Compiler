	.text
main:
	li $8, 1
	sw $8, -4($sp)
	li $8, 3
	sw $8, -12($sp)
	li $8, 0x40133333
	sw $8, -20($sp)
	lw $8, -4($sp)
	li $8, 2
	sw $8, -4($sp)
	lw $8, -8($sp)
	li $8, 1
	move $10, $8
	li $8, 1
	move $9, $10
	add $8, $8, $9
	move $10, $8
	li $8, 1
	move $9, $10
	add $8, $8, $9
	move $10, $8
	li $8, 1
	move $9, $10
	add $8, $8, $9
	move $10, $8
	li $8, 1
	move $9, $10
	add $8, $8, $9
	move $10, $8
	li $8, 1
	move $9, $10
	add $8, $8, $9
	move $10, $8
	li $8, 1
	move $9, $10
	add $8, $8, $9
	move $10, $8
	li $8, 1
	move $9, $10
	add $8, $8, $9
	move $10, $8
	li $8, 1
	move $9, $10
	add $8, $8, $9
	move $10, $8
	li $8, 1
	move $9, $10
	add $8, $8, $9
	move $10, $8
	li $8, 1
	move $9, $10
	add $8, $8, $9
	move $10, $8
	li $8, 1
	move $9, $10
	add $8, $8, $9
	move $10, $8
	li $8, 1
	move $9, $10
	add $8, $8, $9
	move $10, $8
	li $8, 1
	move $9, $10
	add $8, $8, $9
	move $10, $8
	li $8, 1
	move $9, $10
	add $8, $8, $9
	move $10, $8
	li $8, 1
	move $9, $10
	add $8, $8, $9
	move $10, $8
	li $8, 1
	move $9, $10
	add $8, $8, $9
	move $10, $8
	li $8, 1
	move $9, $10
	add $8, $8, $9
	move $10, $8
	li $8, 1
	move $9, $10
	add $8, $8, $9
	move $10, $8
	li $8, 1
	move $9, $10
	add $8, $8, $9
	move $10, $8
	li $8, 1
	move $9, $10
	add $8, $8, $9
	move $10, $8
	li $8, 1
	move $9, $10
	add $8, $8, $9
	move $10, $8
	li $8, 1
	move $9, $10
	add $8, $8, $9
	move $10, $8
	li $8, 1
	move $9, $10
	add $8, $8, $9
	move $10, $8
	li $8, 1
	move $9, $10
	add $8, $8, $9
	move $10, $8
	li $8, 1
	move $9, $10
	add $8, $8, $9
	move $10, $8
	li $8, 1
	move $9, $10
	add $8, $8, $9
	move $10, $8
	li $8, 1
	move $9, $10
	add $8, $8, $9
	sw $8, -8($sp)
	lw $8, -8($sp)
	move $10, $8
	li $8, 8
	move $9, $10
	mul $8, $8, $9
	move $10, $8
	li $8, 2
	move $11, $8
	li $8, 1
	move $9, $11
	div $8, $9, $8
	move $9, $10
	add $8, $8, $9
	move $10, $8
	move $9, $10
	move $a0, $9
	li $v0, 1
	syscall
	la $8, _0_const_string
	move $10, $8
	move $9, $10
	move $a0, $9
	li $v0, 4
	syscall
	li $8, 0
	move $2, $8
	jr $ra
	.data
_0_const_string:
	.asciiz "\nHello!\n"
