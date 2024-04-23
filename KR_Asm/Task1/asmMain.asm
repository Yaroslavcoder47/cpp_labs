.686
PUBLIC @calculateSqrt@8
.model flat
.data
	n dd ? ; количество строк
	m dd ? ; количество столбцов
	mSize dd ?
	bSize dd 0
.code

@calculateSqrt@8 proc
finit  
fld dword ptr[edx] 
fld dword ptr[edx]
_loop:

fld1
fld1
fadd
fdivp st(1), st(0) ; x/2 a
fld st(0) ; x/2 x/2 a

fld1
fld1
fadd
fmul ; x x/2 a
fld st(2)
fld1
fld1
fadd

fdivp st(1), st(0) ; a/2 x/2 x a

;fdivrp st(0), st(1)
fdivrp
faddp st(1), st(0)
   
loop _loop

ret
@calculateSqrt@8 endp


_CreateVectorB proc
push ebp
mov ebp, esp
mov edi, [ebp + 8]
xor ecx, ecx
mov eax, [ebp + 12]
mov n, eax
mov eax, [ebp + 16]
mov m, eax
mov ebx, [ebp + 20]

mov eax, 4
mul m
mov mSize, eax
xor eax, eax

firstLoop_:
	cmp ecx, n
	je end_
	mov esi, 0
	mov edx, [edi + esi*4]
	inc esi
secondLoop_:
	cmp esi, m
	je contFirstLoop_
	cmp edx, [edi + esi*4]
	je addElement_
	inc esi
	jmp secondLoop_
addElement_:
	;mov esi, bSize
	mov [ebx + eax*4], esi
	inc eax
contFirstLoop_:
	add edi, mSize
	inc ecx
	jmp firstLoop_
end_:
pop ebp
ret
_CreateVectorB endp
end