section .text
global _ft_isalpha
 
_ft_isalpha:
			push rbp
			mov rbp, rsp
; is min
			cmp rdi, 'z'
			jg false
			cmp rdi, 'a'
			jge true
; is maj
			cmp rdi, 'Z'
			jg false
			cmp rdi, 'A'
			jge true
false:
			mov rax, 0
			leave
			ret
true:
			mov rax, 1
			leave
			ret