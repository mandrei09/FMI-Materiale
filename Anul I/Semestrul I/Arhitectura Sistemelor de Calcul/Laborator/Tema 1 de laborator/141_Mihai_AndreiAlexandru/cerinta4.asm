//problema 4
//x 2 3 1 2 3 4 5 6 let M -2 add
// probleme la rot
.data
	matrice: .space 1600
	n: .long -1
	m: .long -1
	i: .long 0
	j: .long 0
	poz: .space 4
	elemente: .space 4
	nr: .space 4
	div: .space 4
	aux: .space 4 
	ok: .long 0
	m_unu: .long -1
	sir: .space 100
	//sir: .asciz "x 2 3 1 2 3 4 5 6 let M -2 add"
	delim: .asciz " "
	Add: .asciz "add"
	Sub: .asciz "sub"
	Mul: .asciz "mul"
	Div: .asciz "div"
	Let: .asciz "let"
	Rot: .asciz "rot90d"
	formatScanf: .asciz "%s"
	formatPrintf: .asciz "%d "
	formatPrintfs: .asciz "%s"
	newline: .asciz "\n"
	zero: .asciz "0"
	
.text

.global main

main:
	pushl $sir
	call gets
	popl %ebx
	
	movl $matrice, %edi

	pushl $delim
	pushl $sir
	call strtok
	popl %ebx
	popl %ebx
	
	movl %eax, aux
	
	pushl aux
	call atoi
	popl %ebx
	
	xorl %ecx, %ecx
	jmp stiva
	
et_for:
	pushl %ecx
	pushl $delim
	pushl $0
	call strtok
	popl %ebx
	popl %ebx
	popl %ecx
	
	cmp $0, %eax
	je afisare
	
	movl %eax, aux
	
	pushl %ecx
	pushl aux
	call atoi
	popl %ebx
	popl %ecx
	
	jmp stiva
	
stiva:
	cmp $0, %eax
	jne numar
	cmp $0, %eax
	je op_or_var
	
numar:
	cmp $-1,n
	je adaugare_n
	
	cmp $-1,m
	je adaugare_m

	cmp $0, ok
	je adaugare_matrice
	
	pushl %eax
	
	jmp et_for
	
adaugare_n:
	xorl %ecx, %ecx
	movl %eax,n
	jmp et_for

adaugare_m:
	movl %eax,m
	mull n 
	movl %eax, elemente
	jmp et_for
	
adaugare_matrice:
	movl %eax,(%edi,%ecx,4)
	incl %ecx
	jmp et_for

op_or_var:
	//comparate cu 0
	pushl %ecx
	
	pushl aux
	pushl $zero
	call strcmp 
	popl %ebx
	popl %ebx
	
	popl %ecx
	
	cmp $0, %eax
	je numar
	
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
	
	//comparatie cu rot
	pushl aux
	pushl $Rot
	call strcmp 
	popl %ebx
	popl %ebx
	
	cmp $0, %eax
	je op_rot
	
	jmp variabila
	
variabila:
	jmp et_for
	
op_add:
	popl %ebx
	movl %ebx,nr  
	xorl %ecx, %ecx
matrice_add:
	cmp elemente, %ecx
	je et_for 
	movl (%edi, %ecx, 4), %eax
	addl nr, %eax
	movl %eax, (%edi,%ecx,4)
	incl %ecx
	jmp matrice_add
	
op_sub:
	popl %ebx
	movl %ebx,nr  
	xorl %ecx, %ecx
matrice_sub:
	cmp elemente, %ecx
	je et_for 
	movl (%edi, %ecx, 4), %eax
	subl nr, %eax
	movl %eax, (%edi,%ecx,4)
	incl %ecx
	jmp matrice_sub
	
op_mul:
	popl %ebx
	movl %ebx, nr
	xorl %ecx, %ecx
matrice_mul:
	cmp elemente, %ecx
	je et_for 
	movl (%edi, %ecx, 4), %eax
	mull nr
	movl %eax, (%edi,%ecx,4)
	incl %ecx
	jmp matrice_mul
	
op_div:
	popl %ebx
	movl %ebx, nr
	movl %ebx, div
	xorl %ecx, %ecx
matrice_div:
	movl div, %ebx
	movl %ebx, nr
	
	cmp elemente, %ecx
	je et_for 
	movl (%edi, %ecx, 4), %eax
	cmp $0, %eax
	jge div_pp
	cmp $0, %eax
	jl div_np
div_pp: 
	//1) edi[ecx]>0 && nr>0
	cmp $0, nr
	jl div_pn
	
	xorl %edx, %edx
	divl nr
	movl %eax, (%edi,%ecx,4)
	incl %ecx
	jmp matrice_div
div_pn:
	//2) edi[ecx]>0 && nr<0
	movl %eax, %ebx
	movl nr, %eax
	mull m_unu
	movl %eax, nr
	movl %ebx, %eax
	xorl %edx, %edx
	divl nr
	mull m_unu
	movl %eax, (%edi,%ecx,4)
	incl %ecx
	jmp matrice_div
	
div_np:
	//3) edi[ecx]<0 && nr>0
	cmp $0, nr
	jl div_nn
	
	mull m_unu
	xorl %edx, %edx
	divl nr
	mull m_unu
	movl %eax, (%edi,%ecx,4)
	incl %ecx
	jmp matrice_div
div_nn:
	//4) edi[ecx]<0 && nr<0
	mull m_unu
	movl %eax, %ebx
	movl nr, %eax
	mull m_unu
	movl %eax, nr
	movl %ebx, %eax
	xorl %edx, %edx
	divl nr
	movl %eax, (%edi,%ecx,4)
	incl %ecx
	jmp matrice_div
	
op_rot:
	pushl m
	pushl $formatPrintf
	call printf
	popl %ebx
	popl %ebx

	pushl n
	pushl $formatPrintf
	call printf
	popl %ebx
	popl %ebx
	
	movl $0,i
	movl $0,j
	movl elemente, %ecx
	
	movl n, %ebx
	cmp m,%ebx
	jge init_1
	
	cmp m,%ebx
	jl init_2

init_1:
	subl m, %ecx
	movl %ecx, poz
	jmp rot_1
	
rot_1:
	//n>m, deci lucrez cu m
	movl i,%ebx
	cmp %ebx, elemente
	je exit
	
	movl j, %ebx
	cmp %ebx,n
	je incr_1
	
	movl (%edi, %ecx, 4),%eax
	
	pushl %ecx
	
	pushl %eax
	pushl $formatPrintf
	call printf
	incl i
	incl j
	popl %ebx
	popl %ebx
	
	popl %ecx
	
	subl m,%ecx
	jmp rot_1
	
incr_1:
	incl poz
	mov poz, %ecx
	movl $0,j
	jmp rot_1
	
init_2:
	subl m, %ecx
	movl %ecx, poz
	jmp rot_2

rot_2:
	movl i, %ebx
	cmp %ebx, elemente
	je exit
	
	movl j,%ebx
	cmp %ebx,n
	je incr_2
	
	movl (%edi, %ecx, 4),%eax
	
	pushl %ecx
	
	pushl %eax
	pushl $formatPrintf
	call printf
	incl i
	incl j
	popl %ebx
	popl %ebx
	
	popl %ecx
	
	subl m,%ecx
	jmp rot_2

incr_2:
	incl poz
	mov poz, %ecx
	movl $0,j
	jmp rot_2
	
op_let:
	movl $1, ok
	xorl %ecx, %ecx
	jmp et_for
		
afisare:
	pushl n
	pushl $formatPrintf
	call printf
	popl %ebx
	popl %ebx

	pushl m
	pushl $formatPrintf
	call printf
	popl %ebx
	popl %ebx
	
	xorl %ecx, %ecx
	jmp af_matrice
	
af_matrice:
	cmp elemente, %ecx
	je exit
	
	movl (%edi, %ecx, 4), %eax
	pushl %ecx
	
	pushl %eax
	pushl $formatPrintf
	call printf
	popl %ebx
	popl %ebx
	
	popl %ecx
	
	incl %ecx
	jmp af_matrice
	
exit:
	pushl $newline
	pushl $formatPrintfs
	call printf
	popl %ebx
	popl %ebx
	
	mov $1, %eax
	xorl %ebx,%ebx
	int $0x80
	