.686
PUBLIC @mul2fastCall@4
.model flat
.code
@mul2fastCall@4 proc
 mov eax,ecx ;������ ��������
 mov ebx, 2 ;������ ��������
 cdq
 imul ebx
 ret
@mul2fastCall@4 endp
end


PUBLIC @mul2StdCall@4
.model flat
.code
@mul2StdCall@4 proc
 mov eax,ecx ;������ ��������
 mov ebx, 2 ;������ ��������
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
