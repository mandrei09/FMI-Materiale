//problema 3
//x 1 let 2 x add y 3 let x y add mul
.data
	sir: .space 100
	alfabet: .space 104
	//sir: .asciz "x 1 let 2 x add y 3 let x y add mul"
	formatScanf: .asciz "%s"
	formatPrintf: .asciz "%d\n" 
	delim: .asciz " "
	aux: .space 4 
	Let: .asciz "let"
	Add: .asciz "add"
	Sub: .asciz "sub"
	Mul: .asciz "mul"
	Div: .asciz "div"
	nr: .space 4
	n: .long 26
	pozitie: .long 0
	elementCurent: .space 1
.text

.global main
	
main:
	pushl $sir
	call gets
	popl %ebx

	movl $alfabet, %edi
	xorl %ecx, %ecx
	
et_for_init:
	cmp n, %ecx
	je cont
	movl $-1 ,%eax
	movl %eax, (%edi,%ecx,4)
	incl %ecx
	jmp et_for_init
	
cont:
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
	je op_or_var
numar:
	pushl %eax
	jmp et_for
	
op_or_var:
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
	
	//comparatie cu let
	pushl aux
	pushl $Let
	call strcmp 
	popl %ebx
	popl %ebx
	
	cmp $0, %eax
	je op_let
	
	jmp variabila
	
variabila:
	//variabila
	movl aux, %esi
	xorl %eax, %eax
	xorl %ecx, %ecx
	movb (%esi, %ecx, 1), %al
	subl $97, %eax 
	movl (%edi, %eax, 4) ,%ecx
	
	cmp $-1, %ecx
	je stiva_var
	
	cmp $-1, %ecx
	jne var_val

stiva_var:
	pushl aux
	jmp et_for
	
var_val:
	xorl %ecx, %ecx
	movb (%esi, %ecx, 1), %al 
	//
	subl $97, %eax 
	movl (%edi, %eax, 4), %ecx
	pushl %ecx
	jmp et_for

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
	
op_let:
	popl %ebx
	movl %ebx, nr 
	popl %esi
	xorl %ecx, %ecx
	movb (%esi, %ecx, 1), %al 
	//
	subl $97, %eax 
	movl nr, %ecx
	movl %ecx, (%edi, %eax, 4)
	jmp et_for
	
exit:
	pushl $formatPrintf
	call printf
	popl %ebx
	popl %ebx
	
	mov $1, %eax
	xorl %ebx,%ebx
	int $0x80
	