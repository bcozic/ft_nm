section .text
global _ft_fast_strlen

_ft_fast_strlen:
	push rbp
	mov rbp, rsp
	mov r8, 0xFEFEFEFEFEFEFEFF
	mov r9, 0x8080808080808080
	mov rax, -9
chr_zero:
	add rax, 8
	mov rsi, qword[rdi + rax + 1]
	mov r11, rsi
	add rsi, r8
	not r11
	and r11, r9
	and r11, rsi
	jz chr_zero
find_zero:
	inc rax
	cmp byte [rdi + rax], 0
	jz end_len
	inc rax
	cmp byte [rdi + rax], 0
	jz end_len
	inc rax
	cmp byte [rdi + rax], 0
	jz end_len
	inc rax
	cmp byte [rdi + rax], 0
	jnz find_zero
end_len:
	leave
	ret
