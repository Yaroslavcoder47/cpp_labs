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
end