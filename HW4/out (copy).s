	.text
foo:
	sw $ra, -4($sp)
	li $8, 1
	lw $ra, -4($sp)
	lw $sp, 0($sp)
	move $2, $8
	jr $ra
main:
	sw $ra, -4($sp)
	li $8, 1
	sw $8, -8($sp)
	li $8, 3
	sw $8, -16($sp)
# intfoo(){return1;}intmain(){intx=1,y,z=3,w,i;floata,b,c;

	lw $8, -8($sp)
	li $8, 1
	sw $8, -8($sp)
	lw $8, -12($sp)
	li $8, 1
	move $10, $8
	li $8, 1
	move $9, $10
	add $8, $8, $9
	sw $8, -12($sp)
# x=1;y=1+1;

	lw $8, -28($sp)
	li $8, 0x40866666
	sw $8, -28($sp)
# a=4.2;

	lw $8, -32($sp)
	li $8, 2
	mtc1 $8, $f0
	cvt.s.w $f0, $f0
	mfc1 $8, $f0
	sw $8, -32($sp)
# b=2;

	la $8, _0_const_string
	move $10, $8
	move $9, $10
	move $a0, $9
	li $v0, 4
	syscall
# write("\n");

# 

_Test11:
	lw $8, -28($sp)
	move $10, $8
	li $8, 4
	move $9, $10
	mtc1 $8, $f0
	cvt.s.w $f0, $f0
	mfc1 $8, $f0
	mtc1 $8, $f0
	mtc1 $9, $f2
	c.le.s $f2, $f0
	bc1t FP1_clear
	li $8, 1
	j FP1_exit
FP1_clear:
	li $8, 0
FP1_exit:
	beqz $8, _Lexit_or_else11
	la $8, _1_const_string
	move $10, $8
	move $9, $10
	move $a0, $9
	li $v0, 4
	syscall
# if(a>4){write("True\n");

	j _Lexit11
_Lexit_or_else11:
	la $8, _2_const_string
	move $10, $8
	move $9, $10
	move $a0, $9
	li $v0, 4
	syscall
# }else{write("False\n");

_Lexit11:
# }

	lw $8, -24($sp)
	li $8, 0
	sw $8, -24($sp)
# i=0;

_Test21:
	lw $8, -24($sp)
	move $10, $8
	li $8, 3
	move $9, $10
	sle $8, $9, $8
	move $10, $8
	beqz $8, _Lexit21
	lw $8, -24($sp)
	move $11, $8
	move $9, $11
	move $a0, $9
	li $v0, 1
	syscall
# while(i<=3){write(i);

	la $8, _3_const_string
	move $11, $8
	move $9, $11
	move $a0, $9
	li $v0, 4
	syscall
# write("\n");

# 

	lw $8, -24($sp)
	lw $8, -24($sp)
	move $11, $8
	li $8, 1
	move $9, $11
	add $8, $8, $9
	sw $8, -24($sp)
# i=i+1;

	j _Test21
_Lexit21:
# }

	li $8, 3
	sw $8, -24($sp)
_Test31:
	lw $8, -24($sp)
	move $11, $8
	li $8, 0
	move $9, $11
	sge $8, $9, $8
	move $11, $8
	beqz $8, _Lexit31
	j _Body31
_Inc31:
	lw $8, -24($sp)
	move $12, $8
	li $8, 1
	move $9, $12
	sub $8, $9, $8
	sw $8, -24($sp)
	j _Test31
_Body31:
	lw $8, -24($sp)
	move $12, $8
	move $9, $12
	move $a0, $9
	li $v0, 1
	syscall
# for(i=3;i>=0;i=i-1){write(i);

	la $8, _4_const_string
	move $12, $8
	move $9, $12
	move $a0, $9
	li $v0, 4
	syscall
# write("\n");

# 

	j _Inc31
_Lexit31:
# }

	lw $8, -36($sp)
	lw $8, -28($sp)
	move $12, $8
	lw $8, -8($sp)
	move $9, $12
	mtc1 $8, $f0
	cvt.s.w $f0, $f0
	mfc1 $8, $f0
	mtc1 $8, $f0
	mtc1 $9, $f2
	mul.s $f0, $f2, $f0
	mfc1 $8, $f0
	move $12, $8
	lw $8, -32($sp)
	move $9, $12
	mtc1 $8, $f0
	mtc1 $9, $f2
	add.s $f0, $f2, $f0
	mfc1 $8, $f0
	sw $8, -36($sp)
# c=a*x+b;

	lw $8, -36($sp)
	move $12, $8
	move $9, $12
	mtc1 $9, $f12
	li $v0, 2
	syscall
# write(c);

# 

	la $8, _5_const_string
	move $12, $8
	move $9, $12
	move $a0, $9
	li $v0, 4
	syscall
# write("\n");

# 

	lw $8, -12($sp)
	lw $8, -28($sp)
	move $12, $8
	lw $8, -8($sp)
	move $9, $12
	mtc1 $8, $f0
	cvt.s.w $f0, $f0
	mfc1 $8, $f0
	mtc1 $8, $f0
	mtc1 $9, $f2
	mul.s $f0, $f2, $f0
	mfc1 $8, $f0
	move $12, $8
	li $8, 2
	move $9, $12
	mtc1 $8, $f0
	cvt.s.w $f0, $f0
	mfc1 $8, $f0
	mtc1 $8, $f0
	mtc1 $9, $f2
	add.s $f0, $f2, $f0
	mfc1 $8, $f0
	mtc1 $8, $f0
	cvt.w.s $f0, $f0
	mfc1 $8, $f0
	sw $8, -12($sp)
# y=a*x+2;

	lw $8, -12($sp)
	move $12, $8
	move $9, $12
	move $a0, $9
	li $v0, 1
	syscall
# write(y);

# 

	la $8, _6_const_string
	move $12, $8
	move $9, $12
	move $a0, $9
	li $v0, 4
	syscall
# write("\nHello!\n");

# 

	li $8, 0
	lw $ra, -4($sp)
	lw $sp, 0($sp)
	move $2, $8
	jr $ra
# return0;

	.data
_0_const_string:
	.asciiz "\n"
_1_const_string:
	.asciiz "True\n"
_2_const_string:
	.asciiz "False\n"
_3_const_string:
	.asciiz "\n"
_4_const_string:
	.asciiz "\n"
_5_const_string:
	.asciiz "\n"
_6_const_string:
	.asciiz "\nHello!\n"
