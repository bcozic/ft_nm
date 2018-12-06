%define SYSCALL(nb)		0x2000000 | nb
%define WRITE			4
%define STDOUT			1
%define ERROR				-1

section .data
	string:
		.null db "(null)", 10
		.len equ $ - string.null

section .text
	global _ft_puts
	extern _ft_strlen

	_ft_puts:
		push rbp
		mov rbp, rsp
		mov r9, rdi
		cmp r9, 0
		jz put_null
		call _ft_strlen
	put_string:
		mov rdx, rax
		mov rsi, r9
		mov rdi, STDOUT
		mov rax, SYSCALL(WRITE)
		syscall
		cmp rax, ERROR
		je return
	put_endl:
		lea rsi, [rel endl + 1]
		mov rdx, 1
		mov rax, SYSCALL(WRITE)
		syscall
		cmp rax, ERROR
		je return
	endl:
		mov rax, 10
		leave
		ret

	put_null:
		lea rsi, [rel string.null]
		mov rdi, STDOUT
		mov rdx, string.len
		mov rax, SYSCALL(WRITE)
		syscall
		cmp rax, ERROR
		je return
		mov rax, 10
	return:
		leave
		ret
