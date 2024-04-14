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



_DelSymbol@12 proc
push ebp
mov ebp, esp
mov esi, [ebp+8] ; начало строки
mov ecx, [ebp+12] ; длина строки

;mov bl, [ebp+16] Ч удал€емый элемент
mov edx, 0
mainLoop_:
	cmp ecx, edx
	je end_
	mov bl, [ebp+16]
	cmp bl, [esi + edx]
	jne contMainLoop_
	mov ebx, edx
	dec ecx
loopChange_:
	cmp ebx, ecx
	je preContMainLoop_
	mov al, [esi + ebx + 1]
	mov [esi + ebx], al
	inc ebx
	jmp loopChange_
preContMainLoop_:
	mov dword ptr[esi + ebx], 0
	dec edx
contMainLoop_:
	inc edx
	jmp mainLoop_
end_:
mov eax, esi
pop ebp
ret 12 
_DelSymbol@12 endp


@CountNumbers@8 proc
xor eax, eax
mov bl, 48
mov bh, 57
mov esi, 0
mainLoop_:
	cmp esi, ecx
	je end_
	mov edi, esi
secondLoop_:
	cmp edi, ecx
	je endLoop_
	cmp [edx + edi], bl
	jl endLoop_
	cmp [edx + edi], bh
	jg endLoop_
	inc edi
	jmp secondLoop_
endLoop_:
	sub edi, esi
	cmp edi, 0
	je contmainLoop_
	cmp edi, eax
	jl contmainLoop_
	mov eax, edi
	add esi, edi
	dec esi
contmainLoop_:
	inc esi
	jmp mainLoop_
end_:
ret
@CountNumbers@8 endp


@ChangeLetters@8 proc
xor eax, eax
mov bl, 97
mov bh, 122
mov esi, 0
cmp [edx], bl
jl mainLoop_
cmp [edx], bh
jg mainLoop_
mov eax, [edx]
sub eax, 32
mov [edx], eax

mainLoop_:
	cmp esi, ecx
	je end_
	cmp byte ptr[edx + esi], 32
	jne contMainLoop_
	cmp [edx + esi + 1], bl
	jl contMainLoop_
	cmp [edx + esi + 1], bh
	jg contMainLoop_
	xor eax, eax
	mov eax, [edx + esi + 1]
	sub eax, 32
	mov [edx + esi + 1], eax
contMainLoop_:
	inc esi
	jmp mainLoop_
end_:
ret
@ChangeLetters@8 endp

end