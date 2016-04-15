	.text
main:
	li $8, 1
	sw $8, -4($sp)
	li $8, 3
	sw $8, -12($sp)
# intmain(){intx=1,y,z=3,w;floata,b,c;

	lw $8, -20($sp)
	li $8, 0x3f8ccccd
	sw $8, -20($sp)
	lw $8, -24($sp)
	li $8, 0x400ccccd
	sw $8, -24($sp)
# a=1.1;b=2.2;

	lw $8, -28($sp)
	lw $8, -20($sp)
	move $10, $8
	lw $8, -24($sp)
	move $9, $10
	mtc1 $8, $f0
	mtc1 $9, $f2
	add.s $f0, $f0, $f2
	mfc1 $8, $f0
	sw $8, -28($sp)
# c=a+b;

	lw $8, -4($sp)
	li $8, 2
	sw $8, -4($sp)
# x=2;

	lw $8, -8($sp)
	li $8, 1
	move $10, $8
	li $8, 1
	move $9, $10
	add $8, $8, $9
	sw $8, -8($sp)
# y=1+1;

	la $8, _0_const_string
	move $10, $8
	move $9, $10
	move $a0, $9
	li $v0, 4
	syscall
# write("\n");

# 

	lw $8, -28($sp)
	move $10, $8
	move $9, $10
	mtc1 $9, $f12
	li $v0, 2
	syscall
# write(c);

# 

	la $8, _1_const_string
	move $10, $8
	move $9, $10
	move $a0, $9
	li $v0, 4
	syscall
# write("\n");

# 

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
# write(y*8+2/1);

# 

	la $8, _2_const_string
	move $10, $8
	move $9, $10
	move $a0, $9
	li $v0, 4
	syscall
# write("\nHello!\n");

# 

	li $8, 0
	move $2, $8
	jr $ra
# return0;

	.data
_0_const_string:
	.asciiz "\n"
_1_const_string:
	.asciiz "\n"
_2_const_string:
	.asciiz "\nHello!\n"
