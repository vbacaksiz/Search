 .code
find 	proc
		mov ebx,0
L1:		mov eax,dword ptr[rcx]
		add ebx,1
		cmp eax,dword ptr[rdx]
		je L3
		cmp eax,0
		je L2
		add rcx,4
		jmp L1
L2:		mov eax,-1
		ret
L3:		mov r10,0
		jmp L4
L4:		add r10,4
		add rcx,4
		add rdx,4
		mov eax,dword ptr[rdx]
		cmp eax,0
		je L5
		mov eax,dword ptr[rcx]
		cmp eax,0
		je L2
		mov eax,dword ptr[rdx]
		cmp eax,dword ptr[rcx]
		je L4
		sub rdx,r10
		sub r10,4
		sub rcx,r10
		jmp L1
L5:		mov eax,ebx
		ret
find	endp
end