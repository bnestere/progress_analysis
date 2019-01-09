	.text
	.file	"pp_begin_test.bc"
	.align	16, 0x90
	.type	pp_begin,@function
pp_begin:                               # @pp_begin
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp0:
	.cfi_def_cfa_offset 16
.Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp2:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movl	$186, %edi
	xorl	%eax, %eax
	callq	syscall
	andl	$1023, %eax             # imm = 0x3FF
	movl	%eax, -28(%rbp)
	movq	$-1, -40(%rbp)
	movq	-24(%rbp), %rax
	cmpq	$-1, trust_pp_nos(,%rax,8)
	je	.LBB0_1
# BB#2:                                 # %if.else
	movq	-24(%rbp), %rax
	cmpq	$0, trust_pp_nos(,%rax,8)
	jne	.LBB0_4
# BB#3:                                 # %if.then6
	movq	-24(%rbp), %rsi
	movl	$.L.str1, %edi
	xorl	%eax, %eax
	callq	printf
	movq	-24(%rbp), %rax
	movslq	-28(%rbp), %rcx
	shlq	$11, %rcx
	shlq	$4, %rax
	leaq	duration_check_pp_nos(%rcx,%rax), %rsi
	movq	%rsi, -48(%rbp)
	xorl	%edi, %edi
	callq	clock_gettime
.LBB0_4:                                # %if.end11
	movq	-24(%rbp), %rax
	movslq	-28(%rbp), %rcx
	shlq	$10, %rcx
	cmpq	$0, active_pps(%rcx,%rax,8)
	jne	.LBB0_6
# BB#5:                                 # %if.then17
	movq	-16(%rbp), %rsi
	movl	$329, %edi              # imm = 0x149
	xorl	%eax, %eax
	callq	syscall
	movq	%rax, -40(%rbp)
	movq	-24(%rbp), %rcx
	movslq	-28(%rbp), %rdx
	shlq	$10, %rdx
	movq	%rax, active_pps(%rdx,%rcx,8)
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rax
	movl	(%rax), %edx
	movl	4(%rax), %ecx
	movl	8(%rax), %r8d
	movl	$.L.str2, %edi
	xorl	%eax, %eax
	callq	printf
.LBB0_6:                                # %if.end23
	movq	-40(%rbp), %rax
	movq	%rax, -8(%rbp)
	jmp	.LBB0_7
.LBB0_1:                                # %if.then
	movq	-24(%rbp), %rsi
	movl	$.L.str, %edi
	xorl	%eax, %eax
	callq	printf
	movq	$-1, -8(%rbp)
.LBB0_7:                                # %return
	movq	-8(%rbp), %rax
	addq	$48, %rsp
	popq	%rbp
	retq
.Ltmp3:
	.size	pp_begin, .Ltmp3-pp_begin
	.cfi_endproc

	.type	trust_pp_nos,@object    # @trust_pp_nos
	.local	trust_pp_nos
	.comm	trust_pp_nos,1024,16
	.type	duration_check_pp_nos,@object # @duration_check_pp_nos
	.local	duration_check_pp_nos
	.comm	duration_check_pp_nos,2097152,16
	.type	active_pps,@object      # @active_pps
	.local	active_pps
	.comm	active_pps,1048576,16
	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"Ignoring PP %lu\n"
	.size	.L.str, 17

	.type	.L.str1,@object         # @.str1
.L.str1:
	.asciz	"Testing the waters... pp %ld\n"
	.size	.L.str1, 30

	.type	.L.str2,@object         # @.str2
.L.str2:
	.asciz	"Beginning progress period %ld: wss %d, reuse %d, rsrc %d\n"
	.size	.L.str2, 58


	.ident	"clang version 3.6.2 (tags/RELEASE_362/final)"
	.section	".note.GNU-stack","",@progbits
