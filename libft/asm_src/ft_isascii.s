section .text
global _ft_isascii
 
_ft_isascii:
			push rbp
			mov rbp, rsp
			cmp rdi, 0x7f
			jg false
			cmp rdi, 0x00
			jge true
false:
			mov rax, 0
			leave
			ret
true:
			mov rax, 1
			leave
			ret