section .text
global _ft_strcat
extern _ft_strlen

_ft_strcat:
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
			mov rcx, -1
			repnz scasb
			mov rcx, rdi
			sub rcx, r9
			sub rdi, 1
cpy_string:
			pop rdi
			rep movsb
end_fcnt:
			pop rax
return:
			leave
			ret
