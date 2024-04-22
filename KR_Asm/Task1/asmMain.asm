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

; 2 - ������ �� a
; 1 ������ �� b
; 2 �� �������� ��������
mov currentPosElementB, edx

mov edi, [ebp + 8]; ��������� �� a
mov eax, 0; ������ �� ������� ������� a
mov ebx, 0; ������ �� �������� ������� a
mov ecx, 0; ������ �� �������� ������� a ��� ���������
mov esi, [ebp + 20] ; ��������� �� b
mov edx, 0; ������ �� ������� b ��� ��� ����������
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
	mov num, eax ; ��� ���������� �������� �������� ������� ������� ������
	mul num1
	add eax, ebx

	mov eax, [edi + eax*4]
	mov currentElement, eax ; ����� �� ��������� �������� �������� a[i][j]
	mov ecx, ebx
	inc ecx
thirdLoop_:
	cmp ecx, [ebp + 16]
	je contSecondLoop_
	; ���������� �������� ��� ���������
	mov eax, num
	mul num1
	add eax, ecx
	
	mov edx, currentElement ; ������� � eax �������� a[i][j]
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