.686
PUBLIC @mul2fastCall@4
.model flat
.code
@mul2fastCall@4 proc
 mov eax,ecx ;первый параметр
 mov ebx, 2 ;второй параметр
 cdq
 imul ebx
 ret
@mul2fastCall@4 endp
end


PUBLIC @mul2StdCall@4
.model flat
.code
@mul2StdCall@4 proc
 mov eax,ecx ;первый параметр
 mov ebx, 2 ;второй параметр
 cdq
 imul ebx
 ret
@mul2StdCall@4 endp
end

PUBLIC @palindromfastCall@8
.model flat
.code
@palindromfastCall@8
	mov 
