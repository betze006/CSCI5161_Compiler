
	.text
f_test:
	sw $ra, 0($sp)
	sw $fp, -4($sp)
	add $fp, $sp, -4
	add $sp, $sp, -8
	lw $2, _framesize_f_test
	sub $sp, $sp, $2
	sw $8, 32($sp)
	sw $9, 28($sp)
	sw $10, 24($sp)
	sw $11, 20($sp)
	sw $12, 16($sp)
	sw $13, 12($sp)
	sw $14, 8($sp)
	sw $15, 4($sp)

_begin_f_test:
	li $8, 1
	li $9, 1
	li $10, 1
	li $11, 1
	li $12, 1
	li $13, 1
	li $14, 1
	li $15, 1
	li $16, 1
	li $17, 1
	li $18, 1
	li $19, 1
	sw $19, -4($fp)
	sw $18, -8($fp)
	sw $17, -12($fp)
	sw $16, -16($fp)
	sw $15, -20($fp)
	sw $14, -24($fp)
	sw $13, -28($fp)
	sw $12, -32($fp)
	sw $11, -36($fp)
	sw $10, -40($fp)
	sw $9, -44($fp)
	sw $8, -48($fp)
	lw $8, 0($fp)
	lw $9, -16($fp)
	add $10, $8, $9
	move $v0, $10

_end_f_test:
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
	jr $ra

	.data
_framesize_f_test: .word 32

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
	li $9, 100
	li $8, 100
	li $11, 100
	li $12, 100
	li $13, 100
	addi $sp, $sp, -4
	jal f_test
	addi $sp, $sp, 4
	li $v0, 1
	move $a0, $0
	syscall
	li $14, 0
	move $v0, $14

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
