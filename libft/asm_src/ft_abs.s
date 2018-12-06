section .text
global _ft_abs

_ft_abs:
	push rbp
	mov rbp, rsp
	cmp rdi, 0x7FFFFFFF
	jle end
	neg rdi
end:
	mov rax, rdi
	leave
	ret
