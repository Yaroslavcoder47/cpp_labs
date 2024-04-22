.686
PUBLIC @calculateSqrt@8
.model flat
.data
	num dd ?
	num1 dd ?
	addres dd ?
	currentElement dd ?
	currentPosElementB dd ?
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

; 2 - проход по a
; 1 проход по b
; 2 на хранение массивов
mov currentPosElementB, edx

mov edi, [ebp + 8]; указатель на a
mov eax, 0; проход по строкам массива a
mov ebx, 0; проход по столбцам массива a
mov ecx, 0; проход по столбцам массива a для сравнения
mov esi, [ebp + 20] ; указатель на b
mov edx, 0; проход по массиву b при его заполнении
mov eax, [ebp + 12]
mov num1, eax
xor eax, eax
firstLoop_:
	cmp eax, [ebp + 12]
	je end_
	xor ebx, ebx
secondLoop_:
	cmp ebx, [ebp + 16]
	je contFirstLoop_
	mov num, eax ; для временного хранения значения индекса текущей строки
	mul num1
	add eax, ebx

	mov eax, [edi + eax*4]
	mov currentElement, eax ; чтобы не испротить значение элемента a[i][j]
	mov ecx, ebx
	inc ecx
thirdLoop_:
	cmp ecx, [ebp + 16]
	je contSecondLoop_
	; подготовка элемента для сравнения
	mov eax, num
	mul num1
	add eax, ecx
	
	mov edx, currentElement ; вернули в eax значение a[i][j]
	cmp edx, [edi + eax*4]
	je addNumber_
	inc ecx
	jmp thirdLoop_
contSecondLoop_:
	inc ebx
	jmp secondLoop_
addNumber_:
	mov edx, currentPosElementB
	mov eax, num
	mov [esi + edx * 4], eax
	inc edx
contFirstLoop_:
	mov eax, num
	inc eax
	jmp firstLoop_
end_:
pop ebp
ret
_CreateVectorB endp

end