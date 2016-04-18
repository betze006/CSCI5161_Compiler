	.text
foo:
	sw $ra, -12($sp)
	lw $8, 0($sp)
	move $11, $8
	lw $8, -4($sp)
	move $9, $11
	add $8, $8, $9
	lw $ra, -12($sp)
	lw $sp, -8($sp)
	move $2, $8
	jr $ra
main:
	add $sp, $sp, -4
	sw $ra, -4($sp)
	li $8, 1
	sw $8, -728($sp)
	li $8, 3
	sw $8, -736($sp)
# intfoo(inta,intb){returna+b;}intmain(){intarray[10][6][3];intx=1,y,z=3,w,i;

# floata,b,c;

	lw $8, -728($sp)
	li $8, 1
	move $11, $8
	sw $8, -760($sp)
	li $8, 3
	move $12, $8
	sw $8, -764($sp)
	sw $sp, -768($sp)
	add $sp, $sp, -760
	jal foo
	move $8, $2
	sw $8, -728($sp)
	lw $8, -732($sp)
	li $8, 1
	move $13, $8
	li $8, 1
	move $9, $13
	add $8, $8, $9
	sw $8, -732($sp)
# x=foo(1,3);y=1+1;

	lw $8, -748($sp)
	li $8, 0x40866666
	sw $8, -748($sp)
# a=4.2;

	lw $8, -752($sp)
	li $8, 2
	mtc1 $8, $f0
	cvt.s.w $f0, $f0
	mfc1 $8, $f0
	sw $8, -752($sp)
# b=2;

	lw $8, -8($sp)
	li $8, 1
	move $13, $8
	li $8, 2
	move $14, $8
	li $8, 0
	move $15, $8
	la $10, -8($sp)
	move $9, $15
	li $8, 4
	mul $8, $8, $9
	sub $10, $10, $8
	move $9, $14
	li $8, 12
	mul $8, $8, $9
	sub $10, $10, $8
	move $9, $13
	li $8, 72
	mul $8, $8, $9
	sub $10, $10, $8
	lw $8, 0($10)
	li $8, 0x402ccccd
	mtc1 $8, $f0
	cvt.w.s $f0, $f0
	mfc1 $8, $f0
	sw $8, 0($10)
# array[1][2][0]=2.7;

	la $8, _0_const_string
	move $14, $8
	sw $8, -760($sp)
	move $9, $14
	move $a0, $9
	li $v0, 4
	syscall
# write("Enter an integer:");

# 

	lw $8, -8($sp)
	li $8, 6
	move $13, $8
	li $8, 4
	move $14, $8
	li $8, 1
	move $15, $8
	la $10, -8($sp)
	move $9, $15
	li $8, 4
	mul $8, $8, $9
	sub $10, $10, $8
	move $9, $14
	li $8, 12
	mul $8, $8, $9
	sub $10, $10, $8
	move $9, $13
	li $8, 72
	mul $8, $8, $9
	sub $10, $10, $8
	lw $8, 0($10)
	li $v0, 5
	syscall
	move $8, $v0
	sw $8, 0($10)
# array[6][4][1]=read();

	lw $8, -8($sp)
	li $8, 1
	move $13, $8
	li $8, 2
	move $14, $8
	li $8, 0
	move $15, $8
	la $10, -8($sp)
	move $9, $15
	li $8, 4
	mul $8, $8, $9
	sub $10, $10, $8
	move $9, $14
	li $8, 12
	mul $8, $8, $9
	sub $10, $10, $8
	move $9, $13
	li $8, 72
	mul $8, $8, $9
	sub $10, $10, $8
	lw $8, 0($10)
	move $13, $8
	sw $8, -760($sp)
	move $9, $13
	move $a0, $9
	li $v0, 1
	syscall
# write(array[1][2][0]);

# 

<<<<<<< HEAD
	la $8, _1_const_string
	move $14, $8
=======
	la $8, _0_const_string
	move $13, $8
>>>>>>> 94b19e55650158f9b5436483ee33350e098f6b6c
	sw $8, -760($sp)
	move $9, $13
	move $a0, $9
	li $v0, 4
	syscall
# write("\n");

# 

	lw $8, -8($sp)
	li $8, 6
	move $13, $8
	li $8, 4
	move $14, $8
	li $8, 1
	move $15, $8
	la $10, -8($sp)
	move $9, $15
	li $8, 4
	mul $8, $8, $9
	sub $10, $10, $8
	move $9, $14
	li $8, 12
	mul $8, $8, $9
	sub $10, $10, $8
	move $9, $13
	li $8, 72
	mul $8, $8, $9
	sub $10, $10, $8
	lw $8, 0($10)
	move $13, $8
	sw $8, -760($sp)
	move $9, $13
	move $a0, $9
	li $v0, 1
	syscall
# write(array[6][4][1]);

# 

<<<<<<< HEAD
	la $8, _2_const_string
	move $14, $8
	sw $8, -760($sp)
	move $9, $14
	move $a0, $9
	li $v0, 4
	syscall
# write("\n");

# 

	li $8, 5
	move $14, $8
	sw $8, -760($sp)
	sw $sp, -764($sp)
	add $sp, $sp, -760
	jal recursive
	move $8, $2
	move $15, $8
	sw $8, -760($sp)
	move $9, $15
	move $a0, $9
	li $v0, 1
	syscall
# write(recursive(5));

# 

	la $8, _3_const_string
	move $15, $8
=======
	la $8, _1_const_string
	move $13, $8
>>>>>>> 94b19e55650158f9b5436483ee33350e098f6b6c
	sw $8, -760($sp)
	move $9, $13
	move $a0, $9
	li $v0, 4
	syscall
# write("\n");

# 

_Test1:
	lw $8, -748($sp)
	move $13, $8
	li $8, 4
	move $9, $13
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
<<<<<<< HEAD
	beqz $8, _Lexit_or_else21
	la $8, _4_const_string
	move $15, $8
=======
	beqz $8, _Lexit_or_else1
	la $8, _2_const_string
	move $13, $8
>>>>>>> 94b19e55650158f9b5436483ee33350e098f6b6c
	sw $8, -760($sp)
	move $9, $13
	move $a0, $9
	li $v0, 4
	syscall
# if(a>4){write("True\n");

<<<<<<< HEAD
	j _Lexit21
_Lexit_or_else21:
	la $8, _5_const_string
	move $15, $8
=======
_Test2:
	lw $8, -732($sp)
	move $13, $8
	li $8, 1
	move $9, $13
	sgt $8, $9, $8
	beqz $8, _Lexit_or_else2
	la $8, _3_const_string
	move $13, $8
	sw $8, -760($sp)
	move $9, $13
	move $a0, $9
	li $v0, 4
	syscall
# if(y>1){write("Nested if ok\n");

_Lexit_or_else2:
# }}

	j _Lexit1
_Lexit_or_else1:
	la $8, _4_const_string
	move $13, $8
>>>>>>> 94b19e55650158f9b5436483ee33350e098f6b6c
	sw $8, -760($sp)
	move $9, $13
	move $a0, $9
	li $v0, 4
	syscall
# else{write("False\n");

_Lexit1:
# }

	lw $8, -744($sp)
	li $8, 0
	sw $8, -744($sp)
# i=0;

_Test3:
	lw $8, -744($sp)
	move $13, $8
	li $8, 3
	move $9, $13
	sle $8, $9, $8
	move $13, $8
	sw $8, -760($sp)
	beqz $8, _Lexit3
	lw $8, -744($sp)
	move $14, $8
	sw $8, -764($sp)
	move $9, $14
	move $a0, $9
	li $v0, 1
	syscall
# while(i<=3){write(i);

<<<<<<< HEAD
	la $8, _6_const_string
	move $16, $8
=======
	la $8, _5_const_string
	move $14, $8
>>>>>>> 94b19e55650158f9b5436483ee33350e098f6b6c
	sw $8, -764($sp)
	move $9, $14
	move $a0, $9
	li $v0, 4
	syscall
# write("\n");

# 

	lw $8, -744($sp)
	lw $8, -744($sp)
	move $14, $8
	li $8, 1
	move $9, $14
	add $8, $8, $9
	sw $8, -744($sp)
# i=i+1;

	j _Test3
_Lexit3:
# }

	li $8, 3
	sw $8, -744($sp)
_Test4:
	lw $8, -744($sp)
	move $14, $8
	li $8, 0
	move $9, $14
	sge $8, $9, $8
	move $14, $8
	sw $8, -764($sp)
	beqz $8, _Lexit4
	j _Body4
_Inc4:
	lw $8, -744($sp)
	move $15, $8
	li $8, 1
	move $9, $15
	sub $8, $9, $8
	sw $8, -744($sp)
	j _Test4
_Body4:
	lw $8, -744($sp)
	move $15, $8
	sw $8, -768($sp)
	move $9, $15
	move $a0, $9
	li $v0, 1
	syscall
# for(i=3;i>=0;i=i-1){write(i);

<<<<<<< HEAD
	la $8, _7_const_string
	move $17, $8
=======
	la $8, _6_const_string
	move $15, $8
>>>>>>> 94b19e55650158f9b5436483ee33350e098f6b6c
	sw $8, -768($sp)
	move $9, $15
	move $a0, $9
	li $v0, 4
	syscall
# write("\n");

# 

	j _Inc4
_Lexit4:
# }

	lw $8, -756($sp)
	lw $8, -748($sp)
	move $15, $8
	lw $8, -728($sp)
	move $9, $15
	mtc1 $8, $f0
	cvt.s.w $f0, $f0
	mfc1 $8, $f0
	mtc1 $8, $f0
	mtc1 $9, $f2
	mul.s $f0, $f2, $f0
	mfc1 $8, $f0
	move $15, $8
	lw $8, -752($sp)
	move $9, $15
	mtc1 $8, $f0
	mtc1 $9, $f2
	add.s $f0, $f2, $f0
	mfc1 $8, $f0
	sw $8, -756($sp)
# c=a*x+b;

	lw $8, -756($sp)
	move $15, $8
	sw $8, -768($sp)
	move $9, $15
	mtc1 $9, $f12
	li $v0, 2
	syscall
# write(c);

# 

<<<<<<< HEAD
	la $8, _8_const_string
	move $17, $8
=======
	la $8, _7_const_string
	move $15, $8
>>>>>>> 94b19e55650158f9b5436483ee33350e098f6b6c
	sw $8, -768($sp)
	move $9, $15
	move $a0, $9
	li $v0, 4
	syscall
# write("\n");

# 

	lw $8, -732($sp)
	lw $8, -748($sp)
	move $15, $8
	lw $8, -728($sp)
	move $9, $15
	mtc1 $8, $f0
	cvt.s.w $f0, $f0
	mfc1 $8, $f0
	mtc1 $8, $f0
	mtc1 $9, $f2
	mul.s $f0, $f2, $f0
	mfc1 $8, $f0
	move $15, $8
	li $8, 2
	move $9, $15
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
	sw $8, -732($sp)
# y=a*x+2;

	lw $8, -732($sp)
	move $15, $8
	sw $8, -768($sp)
	move $9, $15
	move $a0, $9
	li $v0, 1
	syscall
# write(y);

# 

<<<<<<< HEAD
	la $8, _9_const_string
	move $17, $8
=======
	la $8, _8_const_string
	move $15, $8
>>>>>>> 94b19e55650158f9b5436483ee33350e098f6b6c
	sw $8, -768($sp)
	move $9, $15
	move $a0, $9
	li $v0, 4
	syscall
# write("\nHello!\n");

# 

_Test51:
	li $8, 2
	move $17, $8
	li $8, 0
	move $9, $17
	sgt $8, $9, $8
	bnez $8, _short_T1
	li $8, 2
	move $17, $8
	li $8, 1
	move $9, $17
	slt $8, $9, $8
	beqz $8, _short_F3
	li $8, 3
	move $17, $8
	li $8, 2
	move $9, $17
	sgt $8, $9, $8
	beqz $8, _short_F3
_short_T3:
	li $8, 1
	j _short_E3
_short_F3:
	li $8, 0
_short_E3:
	bnez $8, _short_T1
_short_F1:
	li $8, 0
	j _short_E1
_short_T1:
	li $8, 1
_short_E1:
	beqz $8, _Lexit_or_else51
	la $8, _10_const_string
	move $17, $8
	sw $8, -768($sp)
	move $9, $17
	move $a0, $9
	li $v0, 4
	syscall
# if((2>0)||((2<1)&&(3>2))){write("TRUE\n");

	j _Lexit51
_Lexit_or_else51:
	la $8, _11_const_string
	move $17, $8
	sw $8, -768($sp)
	move $9, $17
	move $a0, $9
	li $v0, 4
	syscall
# }else{write("FALSE\n");

_Lexit51:
# }

	li $8, 0
	lw $ra, -4($sp)
	lw $sp, 0($sp)
	move $2, $8
	jr $ra
# return0;

	.data
_0_const_string:
	.asciiz "Enter an integer:"
_1_const_string:
	.asciiz "\n"
_2_const_string:
<<<<<<< HEAD
	.asciiz "\n"
_3_const_string:
	.asciiz "\n"
=======
	.asciiz "True\n"
_3_const_string:
	.asciiz "Nested if ok\n"
>>>>>>> 94b19e55650158f9b5436483ee33350e098f6b6c
_4_const_string:
	.asciiz "True\n"
_5_const_string:
	.asciiz "False\n"
_6_const_string:
	.asciiz "\n"
_7_const_string:
	.asciiz "\n"
_8_const_string:
	.asciiz "\n"
_9_const_string:
	.asciiz "\nHello!\n"
_10_const_string:
	.asciiz "TRUE\n"
_11_const_string:
	.asciiz "FALSE\n"
