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
	jl end_
	mov eax, [esi + ecx]
	mov ebx, [esi + edx]
	cmp eax, ebx
	jne end_
	inc edx
	dec ecx
	jmp checkLoop_
end_:
pop ebp
ret 8
_Palindrome@8 endp
end