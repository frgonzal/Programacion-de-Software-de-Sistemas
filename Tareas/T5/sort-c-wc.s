	.file	"sort-c-wc.c"
	.option nopic
	.attribute arch, "rv32i2p0_m2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.align	2
	.globl	wordsn
	.type	wordsn, @function
wordsn:
	mv	a5,a0			## a5 = s
	lbu	a4,0(a0)		## a4 = s
	beq	a4,zero,.L9  	## caso en el que no hay palabra
	li	a0,0 			## 
	li	a3,32
	j	.L8
.L3:
	addi	a5,a5,1		## 
	j	.L6
.L5:
	addi	a0,a0,1
.L6:
	lbu	a4,0(a5)		## c = *s
	beq	a4,zero,.L12	## c == 0 ==> ret
.L8:
	beq	a4,a3,.L3
	lbu	a4,0(a5)
	beq	a4,a3,.L5
.L4:
	beq	a4,zero,.L5
	addi	a5,a5,1
	lbu	a4,0(a5)
	bne	a4,a3,.L4
	j	.L5
.L12:				## retorno final
	ret
.L9:
	li	a0,0		## solo util en la primera cond
	ret
	.size	wordsn, .-wordsn
	.align	2
	.globl	strCmp
	.type	strCmp, @function
strCmp:
	addi	sp,sp,-16
	sw	ra,12(sp)
	sw	s0,8(sp)
	sw	s1,4(sp)
	mv	s1,a1
	call	wordsn
	mv	s0,a0
	mv	a0,s1
	call	wordsn
	sub	a0,s0,a0
	lw	ra,12(sp)
	lw	s0,8(sp)
	lw	s1,4(sp)
	addi	sp,sp,16
	jr	ra
	.size	strCmp, .-strCmp
	.align	2
	.globl	sort
	.type	sort, @function
sort:
	addi	sp,sp,-32
	sw	ra,28(sp)
	sw	s0,24(sp)
	sw	s1,20(sp)
	sw	s2,16(sp)
	sw	s3,12(sp)
	sw	s4,8(sp)
	slli	s3,a1,2
	addi	s3,s3,-4
	add	s3,a0,s3
	bgeu	a0,s3,.L15
	mv	s4,a0
	mv	s0,a0
	j	.L19
.L17:
	sw	s2,0(s0)
	sw	s1,4(s0)
	mv	s0,s4
.L19:
	lw	s1,0(s0)
	lw	s2,4(s0)
	mv	a1,s2
	mv	a0,s1
	call	strCmp
	bgt	a0,zero,.L17
	addi	s0,s0,4
	bgtu	s3,s0,.L19
.L15:
	lw	ra,28(sp)
	lw	s0,24(sp)
	lw	s1,20(sp)
	lw	s2,16(sp)
	lw	s3,12(sp)
	lw	s4,8(sp)
	addi	sp,sp,32
	jr	ra
	.size	sort, .-sort
	.ident	"GCC: (GNU) 11.1.0"
