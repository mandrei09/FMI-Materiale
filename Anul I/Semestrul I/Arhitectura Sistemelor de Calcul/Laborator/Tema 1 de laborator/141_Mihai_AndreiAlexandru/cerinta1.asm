//problema1
//A78801C00A7890EC04

.data
	sir: .space 100 	
	binar: .space 400	
	indexb: .long 0
	suma: .long 0
	caz: .space 4
	
	Let: .asciz "let"
	Add: .asciz "add"
	Sub: .asciz "sub"
	Mul: .asciz "mul"
	Div: .asciz "div"
	
	enter: .asciz "\n"
	multiplicator: .space 4
	minus: .asciz "-"
	formatPrintfm: .asciz "%s"
		
	formatScanf: .asciz "%s"
	formatPrintfs: .asciz "%s "
	formatPrintfd: .asciz "%d "
	
.text

.global main

main:
	pushl $sir
	pushl $formatScanf
	call scanf
	popl %ebx
	popl %ebx
	movl $sir, %edi
	movl $binar, %esi
	xorl %ecx,%ecx
	
et_for1:
	movb (%edi,%ecx,1), %al
	
	cmp $0, %al
	je initializare
	cmp $48, %al
	je binar_0
	
	cmp $49, %al
	je binar_1
	
	cmp $50, %al
	je binar_2
	
	cmp $51, %al
	je binar_3
	
	cmp $52 ,%al
	je binar_4
	
	cmp $53, %al
	je binar_5
	
	cmp $54, %al
	je binar_6
	
	cmp $55, %al
	je binar_7
	
	cmp $56, %al
	je binar_8
	
	cmp $57, %al
	je binar_9
	
	cmp $65, %al
	je binar_A
	
	cmp $66, %al
	je binar_B
	
	cmp $67, %al
	je binar_C
	
	cmp $68, %al
	je binar_D
	
	cmp $69, %al
	je binar_E
	
	cmp $70, %al
	je binar_F
	
cont:
	incl %ecx
	jmp et_for1

initializare:
	movl $-1,%ecx
	jmp et_for2
	
et_for2:
	incl %ecx
	movb (%esi,%ecx,1), %al
	cmp $0, %al
	je exit
	incl %ecx
	movb (%esi,%ecx,1), %al
	cmp $48 ,%al
	je et_00
	cmp $49, %al
	je et_10
	
et_00:
	movl $0,caz
	movl $0, suma
	incl %ecx
	movb (%esi,%ecx,1), %al
	cmp $49 , %al
	je et_01
	incl %ecx
	movb (%esi,%ecx,1), %al
	cmp $49, %al
	je neg_00
	cmp $48, %al
	je poz_00
	
et_01:
	movl $1,caz
	addl $2, %ecx
	movb (%esi,%ecx,1), %al
	movl $0,suma
	cmp $49, %al
	je add_2_7
	jmp cont_2_6
	
et_10:
	movl $2,caz
	movl $0,suma
	addl $3, %ecx
	movb (%esi,%ecx,1), %al
	cmp $49,%al
	je add_2_7
	jmp cont_2_6
	
neg_00:
	movl $-1, multiplicator
	incl %ecx
	movb (%esi,%ecx,1), %al
	cmp $49,%al
	je add_2_7
	jmp cont_2_6

poz_00:
	movl $1, multiplicator
	incl %ecx
	movb (%esi,%ecx,1), %al
	cmp $49,%al
	je add_2_7
	jmp cont_2_6

add_2_7:
	addl $128, suma
	jmp cont_2_6

cont_2_6:
	incl %ecx
	movb (%esi,%ecx,1), %al
	cmp $49,%al
	je add_2_6
	jmp cont_2_5

add_2_6:
	addl $64, suma
	jmp cont_2_5

cont_2_5:
	incl %ecx
	movb (%esi,%ecx,1), %al
	cmp $49,%al
	je add_2_5
	jmp cont_2_4

add_2_5:
	addl $32, suma
	jmp cont_2_4

cont_2_4:
	incl %ecx
	movb (%esi,%ecx,1), %al
	cmp $49,%al
	je add_2_4
	jmp cont_2_3

add_2_4:
	addl $16, suma
	jmp cont_2_3

cont_2_3:
	incl %ecx
	movb (%esi,%ecx,1), %al
	cmp $49,%al
	je add_2_3
	jmp cont_2_2

add_2_3:
	addl $8, suma
	jmp cont_2_2

cont_2_2:
	incl %ecx
	movb (%esi,%ecx,1), %al
	cmp $49,%al
	je add_2_2
	jmp cont_2_1

add_2_2:
	addl $4, suma
	jmp cont_2_1

cont_2_1:
	incl %ecx
	movb (%esi,%ecx,1), %al
	cmp $49,%al
	je add_2_1
	jmp cont_2_0

add_2_1:
	addl $2, suma
	jmp cont_2_0

cont_2_0:
	incl %ecx
	movb (%esi,%ecx,1), %al
	cmp $49,%al
	je add_2_0
	jmp afis
	
add_2_0:
	addl $1, suma
	jmp afis
	
afis:
	cmp $0, caz
	je af_00
	cmp $1, caz
	je af_01
	cmp $2,caz
	je af_10
	
af_00:
	movl suma,%eax
	
	cmp $-1, multiplicator
	je af_neg_00
	jmp cont_af_00
	
af_neg_00:
	pushl %eax
	pushl %ecx
	
	pushl $minus
	pushl $formatPrintfm
	call printf
	popl %ebx
	popl %ebx
	
	popl %ecx
	popl %eax
	jmp cont_af_00
	
cont_af_00:
	pushl %ecx
	pushl %eax
	pushl $formatPrintfd
	call printf
	popl %eax
	popl %ebx
	popl %ecx
	
	jmp et_for2
	
af_01:
	pushl %ecx
	pushl $suma
	pushl $formatPrintfs
	call printf
	popl %ebx
	popl %ebx
	popl %ecx
	
	jmp et_for2
	
af_10:
	cmp $0, suma
	je af_let 
	cmp $1, suma
	je af_add
	cmp $2, suma
	je af_sub 
	cmp $3, suma
	je af_mul
	cmp $4, suma
	je af_div
	jmp et_for2 
	 
af_let:
	pushl %ecx
	pushl $Let
	pushl $formatPrintfs
	call printf
	popl %ebx
	popl %ebx
	popl %ecx
	
	jmp et_for2 

af_add:
	pushl %ecx
	pushl $Add
	pushl $formatPrintfs
	call printf
	popl %ebx
	popl %ebx
	popl %ecx
	
	jmp et_for2 

af_sub:
	pushl %ecx
	pushl $Sub
	pushl $formatPrintfs
	call printf
	popl %ebx
	popl %ebx
	popl %ecx

	jmp et_for2 

af_mul:
	pushl %ecx
	pushl $Mul
	pushl $formatPrintfs
	call printf
	popl %ebx
	popl %ebx
	popl %ecx
	
	jmp et_for2 

af_div:
	pushl %ecx
	pushl $Div
	pushl $formatPrintfs
	call printf
	popl %ebx
	popl %ebx
	popl %ecx
	
	jmp et_for2 

binar_0:
	pushl %ecx
	movl indexb, %ecx
	movb $48, (%esi, %ecx, 1)
	incl %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	addl $4, indexb
	popl %ecx
	jmp cont
	
binar_1:
	pushl %ecx
	movl indexb, %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	addl $4, indexb
	popl %ecx
	jmp cont
	
binar_2:
	pushl %ecx
	movl indexb, %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	movl $48,(%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	addl $4, indexb
	popl %ecx
	jmp cont
	
binar_3:
	pushl %ecx
	movl indexb, %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	movl $48 ,(%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	addl $4, indexb
	popl %ecx
	jmp cont
	
binar_4:
	pushl %ecx
	movl indexb, %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	addl $4, indexb
	popl %ecx
	jmp cont
	
binar_5:
	pushl %ecx
	movl indexb, %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	addl $4, indexb
	popl %ecx
	jmp cont
	
binar_6:
	pushl %ecx
	movl indexb, %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	addl $4, indexb
	popl %ecx
	jmp cont
	
binar_7:
	pushl %ecx
	movl indexb, %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	addl $4, indexb
	popl %ecx
	jmp cont
	
binar_8:
	pushl %ecx
	movl indexb, %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	addl $4, indexb
	popl %ecx
	jmp cont
	
binar_9:
	pushl %ecx
	movl indexb, %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	addl $4, indexb
	popl %ecx
	jmp cont
	
binar_A:
	pushl %ecx
	movl indexb, %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	addl $4, indexb
	popl %ecx
	jmp cont
	
binar_B:
	pushl %ecx
	movl indexb, %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	addl $4, indexb
	popl %ecx
	jmp cont
	
binar_C:
	pushl %ecx
	movl indexb, %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	addl $4, indexb
	popl %ecx
	jmp cont
	
binar_D:
	pushl %ecx
	movl indexb, %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $48,(%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	addl $4, indexb
	popl %ecx
	jmp cont
	
binar_E:
	pushl %ecx
	movl indexb, %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $48, (%esi, %ecx, 1)
	incl %ecx
	addl $4, indexb
	popl %ecx
	jmp cont
	
binar_F:
	pushl %ecx
	movl indexb, %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	movl $49, (%esi, %ecx, 1)
	incl %ecx
	addl $4, indexb
	popl %ecx
	jmp cont
	
exit:
	pushl %ecx
	pushl $enter
	pushl $formatPrintfs
	call printf
	popl %ebx
	popl %ebx
	popl %ecx
	movl $1,%eax 
	xorl %ebx, %ebx
	int $0x80
	