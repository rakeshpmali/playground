	.file	"bst.c"
	.text
	.p2align 4,,15
	.globl	FindMin
	.type	FindMin, @function
FindMin:
.LFB39:
	.cfi_startproc
	testq	%rdi, %rdi
	je	.L4
	movq	8(%rdi), %rax
	testq	%rax, %rax
	jne	.L3
	jmp	.L9
	.p2align 4,,10
	.p2align 3
.L8:
	movq	%rdx, %rax
.L3:
	movq	8(%rax), %rdx
	testq	%rdx, %rdx
	jne	.L8
	rep ret
.L4:
	xorl	%eax, %eax
	ret
.L9:
	movq	%rdi, %rax
	.p2align 4,,7
	ret
	.cfi_endproc
.LFE39:
	.size	FindMin, .-FindMin
	.p2align 4,,15
	.globl	FindMax
	.type	FindMax, @function
FindMax:
.LFB40:
	.cfi_startproc
	testq	%rdi, %rdi
	je	.L13
	movq	16(%rdi), %rax
	testq	%rax, %rax
	jne	.L12
	jmp	.L17
	.p2align 4,,10
	.p2align 3
.L16:
	movq	%rdx, %rax
.L12:
	movq	16(%rax), %rdx
	testq	%rdx, %rdx
	jne	.L16
	rep ret
.L13:
	xorl	%eax, %eax
	ret
.L17:
	movq	%rdi, %rax
	.p2align 4,,7
	ret
	.cfi_endproc
.LFE40:
	.size	FindMax, .-FindMax
	.p2align 4,,15
	.globl	Insert
	.type	Insert, @function
Insert:
.LFB41:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	%rdi, %rbx
	subq	$16, %rsp
	.cfi_def_cfa_offset 32
	testq	%rdi, %rdi
	je	.L24
	cmpl	(%rdi), %esi
	jg	.L25
	jl	.L26
.L20:
	addq	$16, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	movq	%rbx, %rax
	popq	%rbx
	.cfi_def_cfa_offset 8
	.p2align 4,,1
	ret
	.p2align 4,,10
	.p2align 3
.L25:
	.cfi_restore_state
	movq	16(%rdi), %rdi
	call	Insert
	movq	%rax, 16(%rbx)
	addq	$16, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	movq	%rbx, %rax
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L26:
	.cfi_restore_state
	movq	8(%rdi), %rdi
	call	Insert
	movq	%rax, 8(%rbx)
	addq	$16, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	movq	%rbx, %rax
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L24:
	.cfi_restore_state
	movl	$24, %edi
	movl	%esi, 12(%rsp)
	call	malloc
	movl	12(%rsp), %esi
	movq	$0, 16(%rax)
	movq	%rax, %rbx
	movq	$0, 8(%rax)
	movl	%esi, (%rax)
	jmp	.L20
	.cfi_endproc
.LFE41:
	.size	Insert, .-Insert
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"Element Not Found"
	.text
	.p2align 4,,15
	.globl	Delete
	.type	Delete, @function
Delete:
.LFB42:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movq	%rdi, %rbx
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	testq	%rdi, %rdi
	je	.L38
	cmpl	%esi, (%rdi)
	jg	.L39
	jl	.L40
	movq	16(%rdi), %rbp
	testq	%rbp, %rbp
	.p2align 4,,2
	je	.L32
	cmpq	$0, 8(%rdi)
	je	.L33
	movq	%rbp, %rcx
	jmp	.L35
	.p2align 4,,10
	.p2align 3
.L41:
	movq	%rdx, %rcx
.L35:
	movq	8(%rcx), %rdx
	testq	%rdx, %rdx
	jne	.L41
	movl	(%rcx), %eax
	movq	%rbp, %rdi
	movl	%eax, (%rbx)
	movl	(%rcx), %esi
	call	Delete
	movq	%rax, 16(%rbx)
.L29:
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	movq	%rbx, %rax
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L32:
	.cfi_restore_state
	movq	8(%rdi), %rbp
.L33:
	movq	%rbx, %rdi
	movq	%rbp, %rbx
	call	free
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	movq	%rbx, %rax
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L39:
	.cfi_restore_state
	movq	8(%rdi), %rdi
	call	Delete
	movq	%rax, 8(%rbx)
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	movq	%rbx, %rax
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L40:
	.cfi_restore_state
	movq	16(%rdi), %rdi
	call	Delete
	movq	%rax, 16(%rbx)
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	movq	%rbx, %rax
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
.L38:
	.cfi_restore_state
	movl	$.LC0, %esi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk
	jmp	.L29
	.cfi_endproc
.LFE42:
	.size	Delete, .-Delete
	.p2align 4,,15
	.globl	Find
	.type	Find, @function
Find:
.LFB43:
	.cfi_startproc
	.p2align 4,,10
	.p2align 3
.L46:
	testq	%rdi, %rdi
	je	.L48
	cmpl	%esi, (%rdi)
	jl	.L51
	jle	.L49
	movq	8(%rdi), %rdi
	.p2align 4,,5
	jmp	.L46
	.p2align 4,,10
	.p2align 3
.L51:
	movq	16(%rdi), %rdi
	jmp	.L46
	.p2align 4,,10
	.p2align 3
.L48:
	xorl	%eax, %eax
	ret
	.p2align 4,,10
	.p2align 3
.L49:
	movq	%rdi, %rax
	ret
	.cfi_endproc
.LFE43:
	.size	Find, .-Find
	.section	.rodata.str1.1
.LC1:
	.string	"%d "
	.text
	.p2align 4,,15
	.globl	PrintInorder
	.type	PrintInorder, @function
PrintInorder:
.LFB44:
	.cfi_startproc
	testq	%rdi, %rdi
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	%rdi, %rbx
	je	.L52
	.p2align 4,,10
	.p2align 3
.L58:
	movq	8(%rbx), %rdi
	call	PrintInorder
	movl	(%rbx), %edx
	xorl	%eax, %eax
	movl	$.LC1, %esi
	movl	$1, %edi
	call	__printf_chk
	movq	16(%rbx), %rbx
	testq	%rbx, %rbx
	jne	.L58
.L52:
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE44:
	.size	PrintInorder, .-PrintInorder
	.p2align 4,,15
	.globl	PrintPreorder
	.type	PrintPreorder, @function
PrintPreorder:
.LFB45:
	.cfi_startproc
	testq	%rdi, %rdi
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	%rdi, %rbx
	je	.L61
	.p2align 4,,10
	.p2align 3
.L67:
	movl	(%rbx), %edx
	movl	$.LC1, %esi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk
	movq	8(%rbx), %rdi
	call	PrintPreorder
	movq	16(%rbx), %rbx
	testq	%rbx, %rbx
	jne	.L67
.L61:
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE45:
	.size	PrintPreorder, .-PrintPreorder
	.p2align 4,,15
	.globl	PrintPostorder
	.type	PrintPostorder, @function
PrintPostorder:
.LFB46:
	.cfi_startproc
	testq	%rdi, %rdi
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	%rdi, %rbx
	je	.L70
	movq	8(%rdi), %rdi
	call	PrintPostorder
	movq	16(%rbx), %rdi
	call	PrintPostorder
	movl	(%rbx), %edx
	movl	$.LC1, %esi
	movl	$1, %edi
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	xorl	%eax, %eax
	jmp	__printf_chk
	.p2align 4,,10
	.p2align 3
.L70:
	.cfi_restore_state
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE46:
	.size	PrintPostorder, .-PrintPostorder
	.section	.rodata.str1.1
.LC2:
	.string	"Element 8 Found"
.LC3:
	.string	"Element 2 not found"
.LC4:
	.string	"Element 6 Found"
.LC5:
	.string	"Minimum element is %d\n"
.LC6:
	.string	"Maximum element is %d\n"
.LC7:
	.string	"Element 8 not found"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB47:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$24, %edi
	call	malloc
	movl	$-1, %esi
	movq	%rax, %rdi
	movl	$5, (%rax)
	movq	$0, 16(%rax)
	movq	$0, 8(%rax)
	call	Insert
	movl	$3, %esi
	movq	%rax, %rdi
	call	Insert
	movl	$-14, %esi
	movq	%rax, %rdi
	call	Insert
	movl	$8, %esi
	movq	%rax, %rdi
	call	Insert
	movl	$10, %esi
	movq	%rax, %rdi
	call	Insert
	movl	$9, %esi
	movq	%rax, %rdi
	call	Insert
	movl	$6, %esi
	movq	%rax, %rdi
	call	Insert
	movq	%rax, %rdi
	movq	%rax, %rbx
	call	PrintInorder
	movl	$10, %edi
	call	putchar
	movq	%rbx, %rdi
	movl	$5, %esi
	call	Delete
	movl	$-1, %esi
	movq	%rax, %rdi
	call	Delete
	movq	%rax, %rdi
	movq	%rax, %rbx
	call	PrintInorder
	movl	$10, %edi
	call	putchar
	testq	%rbx, %rbx
	je	.L74
	movq	8(%rbx), %rdx
	testq	%rdx, %rdx
	jne	.L76
	jmp	.L101
	.p2align 4,,10
	.p2align 3
.L98:
	movq	%rax, %rdx
.L76:
	movq	8(%rdx), %rax
	testq	%rax, %rax
	jne	.L98
.L75:
	movl	(%rdx), %edx
	xorl	%eax, %eax
	movl	$.LC5, %esi
	movl	$1, %edi
	call	__printf_chk
	movq	16(%rbx), %rdx
	testq	%rdx, %rdx
	jne	.L88
	jmp	.L102
	.p2align 4,,10
	.p2align 3
.L77:
	movq	%rax, %rdx
.L88:
	movq	16(%rdx), %rax
	testq	%rax, %rax
	jne	.L77
.L78:
	movl	(%rdx), %edx
	movl	$.LC6, %esi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk
	movq	%rbx, %rdx
	jmp	.L89
	.p2align 4,,10
	.p2align 3
.L100:
	movq	16(%rdx), %rdx
	testq	%rdx, %rdx
	je	.L79
.L89:
	movl	(%rdx), %eax
	cmpl	$7, %eax
	jle	.L100
	cmpl	$8, %eax
	je	.L82
	movq	8(%rdx), %rdx
	testq	%rdx, %rdx
	jne	.L89
.L79:
	movl	$.LC7, %edi
	call	puts
	jmp	.L87
	.p2align 4,,10
	.p2align 3
.L84:
	cmpl	$2, %eax
	je	.L86
	movq	8(%rbx), %rbx
	testq	%rbx, %rbx
	je	.L83
.L87:
	movl	(%rbx), %eax
	cmpl	$1, %eax
	jg	.L84
	movq	16(%rbx), %rbx
	testq	%rbx, %rbx
	jne	.L87
.L83:
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	movl	$.LC3, %edi
	jmp	puts
.L86:
	.cfi_restore_state
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	movl	$.LC4, %edi
	jmp	puts
.L82:
	.cfi_restore_state
	movl	$.LC2, %edi
	call	puts
	jmp	.L87
.L74:
	movl	0, %edx
	movl	$.LC5, %esi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk
	movl	0, %edx
	movl	$.LC6, %esi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk
	movl	$.LC7, %edi
	call	puts
	jmp	.L83
.L102:
	movq	%rbx, %rdx
	jmp	.L78
.L101:
	movq	%rbx, %rdx
	.p2align 4,,5
	jmp	.L75
	.cfi_endproc
.LFE47:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
