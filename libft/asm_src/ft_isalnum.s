section .text
global _ft_isalnum
extern _ft_isalpha
extern _ft_isdigit
 
_ft_isalnum:
			push rbp
			mov rbp, rsp
is_lowercase:
			cmp rdi, 'z'
			jg false
			cmp rdi, 'a'
			jge true
is_upcase:
			cmp rdi, 'Z'
			jg false
			cmp rdi, 'A'
			jge true
is_num:
			cmp rdi, '9'
			jg false
			cmp rdi, '0'
			jge true
false:
			mov rax, 0
			leave
			ret
true:
			mov rax, 1
			leave
			ret