	.text
	.globl	code_to_execute
code_to_execute:
	leaq	data_flag, %rax
	movq	$1, (%rax)
	retq
	
	.data
	.globl data_flag
data_flag:
	.quad 0x0
