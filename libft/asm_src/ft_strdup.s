section .text
global _ft_strdup
extern _ft_strlen
extern _ft_malloc
extern _memcpy

_ft_strdup:
			push rbp
			mov rbp, rsp
len:
			mov r9, rdi
			mov rcx, -1
			mov rax, 0
			repnz scasb
			sub rdi, r9
			mov rax, rdi
			push r9
			push rax
call_malloc:
			call _ft_malloc
			cmp rax, 0
			jz end_strdup
end_call:
			mov rdi, rax
			pop rcx
			pop rsi
call_memcpy:
			rep movsb
end_strdup:
			leave
			ret