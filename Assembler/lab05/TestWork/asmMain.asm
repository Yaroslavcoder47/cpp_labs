.686
PUBLIC @mul2@4
.model flat
.code
@mul2@4 proc
 mov eax,ecx ;������ ��������
 mov ebx, 2 ;������ ��������
 cdq
 imul ebx
 ret
@mul2@4 endp
end