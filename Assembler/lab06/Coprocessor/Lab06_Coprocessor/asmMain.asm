.686
PUBLIC @calcExpression@8
.model flat
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
end