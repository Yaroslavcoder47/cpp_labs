.686
PUBLIC @calculateSqrt@8
.model flat
.code
@calculateSqrt@8 proc
finit  
fld dword ptr[edx] 
fld dword ptr[edx]
_loop:
; доделать с правильным вызовом в стеке
fld1
fld1
fadd
fdivp st(1), st(0)

fld st(1) 
fld st(0)

fld1
fld1
fadd

fdivp st(2), st(0) ; st(2)

fmulp st(1), st(0)
faddp st(1), st(0)

loop _loop

ret

@calculateSqrt@8 endp
end

