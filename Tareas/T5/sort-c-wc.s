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
	mv	a4,a0
	lbu	a5,0(a0)
	beq	a5,zero,.L9
	li	a0,0
	li	a3,32
	j	.L3
.L10:
	lbu	a5,1(a4)
	addi	a4,a4,1
	j	.L5
.L6:
	addi	a0,a0,1
.L5:
	beq	a5,zero,.L1
.L3:
	beq	a5,a3,.L10
	beq	a5,zero,.L6
.L7:
	addi	a4,a4,1
	lbu	a5,0(a4)
	beq	a5,a3,.L6
	bne	a5,zero,.L7
	j	.L6
.L9:
	mv	a0,a5
.L1:
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
	bgeu	a0,s3,.L13
	mv	s4,a0
	mv	s0,a0
	j	.L17
.L15:
	sw	s2,0(s0)
	sw	s1,4(s0)
	mv	s0,s4
.L17:
	lw	s1,0(s0)
	lw	s2,4(s0)
	mv	a1,s2
	mv	a0,s1
	call	strCmp
	bgt	a0,zero,.L15
	addi	s0,s0,4
	bgtu	s3,s0,.L17
.L13:
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
