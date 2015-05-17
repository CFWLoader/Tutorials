	.file	"fifo2-IPCviaNamedPipe.c"
	.section	.rodata
	.align 8
.LC0:
	.string	"Usage: $s <some combination of O_RDONLY O_WRONLY O_NONBLOCK>.\n"
.LC1:
	.string	"O_RDONLY"
.LC2:
	.string	"O_WRONLY"
.LC3:
	.string	"O_NONBLOCK"
.LC4:
	.string	"/tmp/myFifo"
.LC5:
	.string	"Could not create fifo %s.\n"
.LC6:
	.string	"Process %d opening FIFO.\n"
.LC7:
	.string	"Process %d result %d.\n"
.LC8:
	.string	"Process %d finished.\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	%edi, -36(%rbp)
	movq	%rsi, -48(%rbp)
	movl	$0, -4(%rbp)
	cmpl	$1, -36(%rbp)
	jg	.L2
	movq	-48(%rbp), %rax
	movq	(%rax), %rdx
	movq	stderr(%rip), %rax
	movl	$.LC0, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	movl	$1, %edi
	call	exit
.L2:
	movq	-48(%rbp), %rax
	movq	%rax, -16(%rbp)
	movl	$1, -8(%rbp)
	jmp	.L3
.L7:
	addq	$8, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	(%rax), %rax
	movl	$8, %edx
	movl	$.LC1, %esi
	movq	%rax, %rdi
	call	strncmp
	testl	%eax, %eax
	movq	-16(%rbp), %rax
	movq	(%rax), %rax
	movl	$8, %edx
	movl	$.LC2, %esi
	movq	%rax, %rdi
	call	strncmp
	testl	%eax, %eax
	jne	.L5
	orl	$1, -4(%rbp)
.L5:
	movq	-16(%rbp), %rax
	movq	(%rax), %rax
	movl	$10, %edx
	movl	$.LC3, %esi
	movq	%rax, %rdi
	call	strncmp
	testl	%eax, %eax
	jne	.L6
	orl	$2048, -4(%rbp)
.L6:
	addl	$1, -8(%rbp)
.L3:
	movl	-8(%rbp), %eax
	cmpl	-36(%rbp), %eax
	jl	.L7
	movl	$0, %esi
	movl	$.LC4, %edi
	call	access
	cmpl	$-1, %eax
	jne	.L8
	movl	$511, %esi
	movl	$.LC4, %edi
	call	mkfifo
	movl	%eax, -20(%rbp)
	cmpl	$0, -20(%rbp)
	je	.L8
	movq	stderr(%rip), %rax
	movl	$.LC4, %edx
	movl	$.LC5, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	movl	$1, %edi
	call	exit
.L8:
	call	getpid
	movl	%eax, %esi
	movl	$.LC6, %edi
	movl	$0, %eax
	call	printf
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC4, %edi
	movl	$0, %eax
	call	open
	movl	%eax, -20(%rbp)
	call	getpid
	movl	-20(%rbp), %edx
	movl	%eax, %esi
	movl	$.LC7, %edi
	movl	$0, %eax
	call	printf
	movl	$5, %edi
	call	sleep
	cmpl	$-1, -20(%rbp)
	je	.L9
	movl	-20(%rbp), %eax
	movl	%eax, %edi
	call	close
.L9:
	call	getpid
	movl	%eax, %esi
	movl	$.LC8, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %edi
	call	exit
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.3 20140911 (Red Hat 4.8.3-7)"
	.section	.note.GNU-stack,"",@progbits
