.686
PUBLIC @calcExpression@8
.model flat
.data
	p dd 0
	num dd 5
	num1 dd 0.5

	fa dq ?
	fc dq ?
	a dq -10.0
	b dq 10.0
	c_ dq ?
	two dd 2
	four dd 4
	eleven dd 11
	pointTwo dq -0.2
	trash dq ?
	length_ dq ?
	precision dq 0.0001
.code

@calcExpression@8 proc ; ecx - x, edx - y
finit
fld dword ptr[ecx]
fld dword ptr[edx]
fsubp st(1), st(0)
fabs
fld dword ptr[ecx]
fld dword ptr[edx]
fdivp st(1), st(0)
fld dword ptr[edx]
fld dword ptr[ecx]
fdivp st(1), st(0)
fadd
fcos
fmul
ret
@calcExpression@8 endp


_solveEquation proc
push ebp
mov ebp, esp
finit
while_:
	fld a
	fld b
	fadd ST(0), ST(1)
	fild two
	fdiv ST(1), ST(0)
	fstp [trash]
	fstp qword ptr[c_]
	fstp [trash]

	fld a
	fld a
	fmul ST(0), ST(1)
	fld pointTwo
	fmul ST(0), ST(1)
	fild four
	fadd ST(1), ST(0)
	fistp [trash]
	fild eleven
	fadd ST(0), ST(3)
	fdiv ST(1), ST(0)
	fild two
	fadd ST(0), ST(2)
	fstp qword ptr[fa]
	fstp [trash]
	fstp [trash]
	fstp [trash]
	fstp [trash]

	fld c_
	fld c_
	fmul ST(0), ST(1)
	fld pointTwo
	fmul ST(0), ST(1)
	fild four
	fadd ST(1), ST(0)
	fistp [trash]
	fild eleven
	fadd ST(0), ST(3)
	fdiv ST(1), ST(0)
	fild two
	fadd ST(0), ST(2)
	fstp qword ptr[fc]
	fstp [trash]
	fstp [trash]
	fstp [trash]
	fstp [trash]
	
	fld a
	fld b
	fsub ST(0), ST(1)
	fstp qword ptr [length_]
	fstp [trash]

; compare with needed precision
	fld length_
	fld precision
	fcom
	fstsw ax
	sahf
	ja out_
	fstp[trash]
	fstp[trash]

	fldz
	fld fc
	fld fa
	fmul ST(0), ST(1)
	fcom ST(2)
	fstsw ax
	sahf
	jb bChange_
	ja aChange_

bChange_ :
  fld c_
  fstp qword ptr[b]
  fld b
  fstp[trash]
  fstp[trash]
  fstp[trash]
  jmp while_

aChange_ :
  fld c_
  fstp qword ptr[a]
  fstp[trash]
  fstp[trash]
  fstp[trash]
  jmp while_

out_:
	fld c_
	mov esp, ebp
	pop ebp
	ret
_solveEquation endp


@calcPi@8 proc
finit
fld1
fldz
mainLoop_:
	fld1
	fld1
	fadd
	fld st(2)
	fmul
	fld1
	fsub ; 1 0 1
	fld1
	fdivrp st(1), st(0)
	fadd
	fxch
	fld1
	fadd; увеличили k на 1
	fxch
	loop mainLoop_
fild dword ptr[edx]
fmul st(0), st(1)
fsqrt
ret
@calcPi@8 endp


@calcLn@4 proc
finit
fld1
fldz
sumLoop_:
	fld st(1)
	fld1
	fadd
	fistp dword ptr[p]
	mov eax, p
	and eax, 1
	jz zeroEq_
	fld1
	fchs
	fld st(2)
	fdivp st(1), st(0)
	fadd
	jmp contLoop_
zeroEq_:
	fld1
	fld st(2)
	fdivp st(1), st(0)
	fadd
contLoop_:
	fxch
	fld1
	fadd
	fxch
	loop sumLoop_	
ret
@calcLn@4 endp


@calcIntegral@4 proc
finit
fld1
fld1
fadd
fldpi
fmul
fild dword ptr[ecx]
fdivp st(1), st(0)
fld st(0)
fldz
mainLoop_:
	cmp dword ptr [ecx], 1
	je contCalc_
	fld st(1)
	fld st(0)
	fmul
	fsin
	fld st(2)
	fild dword ptr[num]
	fmul
	fadd
	fadd
	;fadd st(1), st(2)
	fxch
	fld st(2)
	fadd
	fxch
	dec dword ptr [ecx]
	jmp mainLoop_
contCalc_:
	fld1
	fld1
	fadd
	fmul
	fld st(1)
	fld st(0)
	fmul
	fsin
	fld st(2)
	fild dword ptr[num]
	fmul
	fadd
	fadd
	fld st(2)
	fld1
	fld1
	fadd
	fdivp st(1), st(0)
	fmul
ret
@calcIntegral@4 endp


@powerFunc@4 proc
finit
cmp ecx, 0
je zeroPower_
cmp ecx, 1
je firstPower_
fld dword ptr[num1]
fld dword ptr[num1]
mainLoop_:
	cmp ecx, 1
	je end_
	fmul st(0), st(1)
	dec ecx
	jmp mainLoop_
zeroPower_:
	fld1
	jmp end_
firstPower_:
	fld dword ptr[num1]
end_:
ret
@powerFunc@4 endp
end