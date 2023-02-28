//problema 2
//2 10 mul 5 div 7 6 sub add
.data
	sir: .space 100
	//sir: .asciz "2 10 mul 5 div 7 6 sub add"
	formatScanf: .asciz "%s"
	formatPrintf: .asciz "%d\n" 
	delim: .asciz " "
	aux: .space 4 
	Add: .asciz "add"
	Sub: .asciz "sub"
	Mul: .asciz "mul"
	Div: .asciz "div"
	nr: .space 4
.text

.global main
	
main:
	pushl $sir
	call gets
	popl %ebx
	
	pushl $delim
	pushl $sir
	call strtok
	popl %ebx
	popl %ebx
	
	movl %eax, aux
	
	pushl aux
	call atoi
	popl %ebx
	
	jmp stiva
	
et_for:
	pushl $delim
	pushl $0
	call strtok
	popl %ebx
	popl %ebx
	
	cmp $0, %eax
	je exit 
	
	movl %eax, aux
	
	pushl aux
	call atoi
	popl %ebx
	
	jmp stiva
	
stiva:
	cmp $0, %eax
	jne numar
	cmp $0, %eax
	je operatie
numar:
	pushl %eax
	jmp et_for
operatie:
	
	//comparatie cu add
	pushl aux
	pushl $Add
	call strcmp 
	popl %ebx
	popl %ebx
	
	cmp $0, %eax
	je op_add
	
	//comparatie cu sub
	pushl aux
	pushl $Sub
	call strcmp 
	popl %ebx
	popl %ebx
	
	cmp $0, %eax
	je op_sub
	
	//comparatie cu mul
	pushl aux
	pushl $Mul
	call strcmp 
	popl %ebx
	popl %ebx
	
	cmp $0, %eax
	je op_mul
	
	//comparatie cu div
	pushl aux
	pushl $Div
	call strcmp 
	popl %ebx
	popl %ebx
	
	cmp $0, %eax
	je op_div

op_add:
	popl %ebx
	movl %ebx,nr
	popl %ebx
	addl nr,%ebx
	pushl %ebx
	jmp et_for
	
op_sub:
	popl %ebx
	movl %ebx,nr
	popl %ebx
	subl nr,%ebx
	pushl %ebx
	jmp et_for
	
	
op_mul:
	popl %ebx
	movl %ebx, nr
	popl %eax
	mull nr 
	pushl %eax
	jmp et_for
	
op_div:
	xorl %edx, %edx
	popl %ebx
	movl %ebx, nr
	popl %eax
	divl nr 
	pushl %eax
	jmp et_for
exit:
	pushl $formatPrintf
	call printf
	popl %ebx
	popl %ebx
	mov $1, %eax
	xorl %ebx,%ebx
	int $0x80
	