section .text
global _ft_strncat
extern _ft_strlen

_ft_strncat:
			push rbp
			mov rbp, rsp
			push rdi
end_str1:
			mov rcx, -1
			mov rax, 0
			repnz scasb
			sub rdi, 1
			push rdi
end_str2:
			mov rdi, rsi
			mov r9, rsi
			mov rcx, rdx
			repnz scasb
			mov rcx, rdi
			sub rcx, r9
cpy_string:
			pop rdi
			rep movsb
			cmp byte [rdi - 1], 0
			je end_fcnt
			mov byte [rdi], 0
end_fcnt:
			pop rax
return:
			leave
			ret
