.686
PUBLIC _Palindrome@8
.model flat
.code
_Palindrome@8 proc

push ebp
mov ebp, esp
mov esi, [ebp+8]
mov ecx, [ebp+12]
dec ecx
mov edx, 0
checkLoop_:
	cmp ecx, edx
	jl preEnd_
	mov al, byte ptr[esi + ecx]
	mov bl, byte ptr[esi + edx]
	cmp al, bl
	jne preEndNot_
	inc edx
	dec ecx
	jmp checkLoop_
preEnd_:
	mov eax, 1
	jmp end_
preEndNot_:
	mov eax, 0
end_:
pop ebp
ret 8
_Palindrome@8 endp
end