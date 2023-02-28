//tema 2 de laborator
.data

	n: .space 4
	m: .space 4
	x: .space 1000
	v: .space 1000
	ap: .space 1000
	elementCurent : .space 4
	ok: .long 0
	n3: .space 4
	trei: .long 3
	formatScanf: .asciz "%d"
	formatPrintf: .asciz "%d "
	formatPrintfs: .asciz "%s"
	enter: .asciz "\n"
	nu: .long -1
	
.text

.global main

backtracking:

	pushl %ebp
	movl %esp, %ebp
	
	movl 12(%ebp),%ecx
	//indicele la care am ramas

	movl 8(%ebp), %edx
	//k, nivelul de stiva

	movl $ap, %edi 

	movl ok,%eax
	cmp $0, %eax
	je verificare_pf

	jmp final

verificare_pf:

	movl $x, %edi
	movl (%edi,%edx,4),%eax

	movl $ap, %edi

	cmp $0, %eax
	je for_backtracking
	//if (x[k]==0)

	jmp punct_fix

punct_fix:

	movl $x, %edi
	movl (%edi,%edx,4),%ecx
	//%ecx=x[k]
	movl %ecx,(%esi, %edx,4)
	//v[k]=%ecx ==> v[k]=x[k]

	movl $ap, %edi

	movl (%edi, %ecx,4), %eax
	incl %eax
	movl %eax, (%edi, %ecx,4)
	//ap[x[k]]++;

	pushl %ecx
	pushl %edi

	pushl %edx
	call valid
	popl %edx

	popl %edi
	popl %ecx

	cmp $0,%eax
	jne element_valid

scad_ap:

	movl (%edi, %ecx, 4), %eax
	subl $1, %eax
	movl %eax, (%edi, %ecx, 4)

	//ap[v[k]]--
	
	jmp for_end

for_backtracking:
	
	//conditiile de oprire ale for-ului
	cmp n, %ecx
	jg for_end
	
	cmp $1,ok
	je nu_exista

	//cmp $0, %edx
	//jle nu_exista
	
	movl %ecx, (%esi,%edx,4) 

	//==> v[k]=i

	pushl %edi

	movl $ap, %edi
	movl (%edi, %ecx, 4), %eax
	incl %eax
	movl %eax, (%edi, %ecx, 4)

	popl %edi

	//ap[i]++;

	pushl %edi
	pushl %ecx
	
	pushl %edx
	call valid 
	//==> valid va returna 0 sau 1 in %eax
	popl %edx
	
	popl %ecx
	popl %edi
	
	cmp $0,%eax
	jne element_valid

scadere_aparitie:

	movl (%edi, %ecx, 4), %eax
	subl $1, %eax
	movl %eax, (%edi, %ecx, 4)

	//ap[v[k]]--;

for_backtr_cont:

	incl %ecx
	jmp for_backtracking
	
element_valid:
	
	cmp n3, %edx
	je final
	//==>am termiant de format array-ul rezultat, urmeaza sa il afisam pe ecran
	
	jmp pas_recursiv 
	//==> nu am terminat de format rezultatul, deci apelam backtracking(k+1)
	
final:

	cmp $1, %eax
	je af_rez

pas_recursiv:

	addl $1, %edx
	
	movl $1, %ecx

	pushl %ecx

	pushl %edx
	call backtracking
	popl %ebx

	popl %ecx

valid:

	pushl %ebp
	movl %esp, %ebp
	movl 8(%ebp),%edx
	//argumentul k
	
aparitii:

	pushl %edi

	movl $ap, %edi

	movl (%edi, %ecx, 4), %eax

	popl %edi

	cmp $3, %eax
	jg ret0

	jmp cont_valid


ret0:

	popl %ebp
	
	xorl %eax, %eax
	ret
	
cont_valid:
	
	movl %edx, %ecx
	//==> %ecx=k-1

cont_valid_for:
	
	subl $1, %ecx
	
	cmp $0,%ecx
	je ret1
	
	movl (%esi,%edx,4),%eax 
	//==> %eax=v[k]
	
	movl (%esi,%ecx,4),%ebx 
	//==> %ebx=v[i]
	
	
	cmp %eax, %ebx
	je distanta
	
	jmp cont_valid_for
	
distanta:

	movl %edx, %eax
	subl %ecx, %eax 
	// ==> k-i
	
	cmp m, %eax
	
	jle ret0
	jmp ret1
	
ret1:
	popl %ebp
	
	movl $1, %eax
	ret 

af_rez:

	movl n3, %edx
	
	pushl %ecx
	
	pushl %edx
	call afisare_rezultat
	popl %edx
	
	popl %ecx

	jmp nu_exista
	
afisare_rezultat:

	movl $1, ok

	pushl %ebp
	movl %esp, %ebp
	
	movl 8(%ebp),%edx
	//argumentul k
	
	movl $1, %ecx
	
et_afisare_rezultat:
	
	cmp %edx,%ecx
	jg exit_afisare
	
	movl (%esi, %ecx, 4), %eax
	
	pushl %edx
	pushl %ecx
	
	pushl %eax
	pushl $formatPrintf
	call printf
	popl %ebx
	popl %ebx
	
	popl %ecx
	popl %edx
	
	incl %ecx
	jmp et_afisare_rezultat
	
exit_afisare:

	popl %ebp
	ret

main:
	//citire date
	
	pushl $n
	pushl $formatScanf
	call scanf
	popl %ebx
	popl %ebx
	
	pushl $m
	pushl $formatScanf
	call scanf
	popl %ebx
	popl %ebx

	movl $1,%ecx

	movl $x,%edi 
	//adresa array-ului initial

	movl $v,%esi 
	//adresa array-ului rezultat

	movl n, %eax
	
	//formam 3*n in variabila 3n
	mull trei
	movl %eax,n3

citire_array:
	
	cmp n3, %ecx
	jg initializare

	pushl %ecx
	
	//citire elemente array x

	pushl $elementCurent
	pushl $formatScanf
	call scanf 
	popl %ebx
	popl %ebx
	
	popl %ecx
	
	movl elementCurent, %eax
	movl %eax, (%edi, %ecx, 4)
	
	incl %ecx
	jmp citire_array

initializare:

	movl $1,%ecx
	
initializare_for:

	cmp n3, %ecx
	jg initializare_ap
	
	movl $0, (%esi, %ecx, 4)
	
	incl %ecx
	jmp initializare_for

initializare_ap:

	movl $1, %ecx
	movl $ap, %edi

initializare_ap_for:

	cmp n, %ecx
	jg bktr
	
	movl $0, (%edi, %ecx, 4)
	
	incl %ecx
	jmp initializare_ap_for

bktr:
	movl $1, %edx 
	movl $1,%ecx
	
	pushl %ecx
	
	pushl %edx
	//==> backtracking(1)
	call backtracking
	popl %edx
	
	popl %ecx
	
af_back:

	popl %ebp
	ret

for_end:

	popl %ebp
	
	subl $1, %edx

	movl (%esi, %edx,4), %ecx

	//continuam pe nivelul anterior de unde am ramas

	movl $ap, %edi
	movl (%edi, %ecx, 4), %eax
	subl $1, %eax
	movl %eax, (%edi, %ecx, 4)

	//ap[v[k]]--;

	push %edi

	movl $x, %edi
	movl (%edi, %edx, 4), %ebx

	cmp $0, %ebx
	jne for_end

	popl %edi

	//daca ne intorcem pe un punct fix, mergem inapoi pana cand nu mai gasim altul

	incl %ecx

	pushl %ecx

	pushl %edx
	call backtracking 
	popl %edx

	popl %ecx

nu_exista:

	movl ok, %eax
	cmp $0, %eax
	je af_m1
	jmp exit

af_m1:

	pushl nu
	pushl $formatPrintf
	call printf
	popl %ebx
	popl %ebx

exit:
	
	//afisam '\n'
	pushl $enter
	pushl $formatPrintfs
	call printf
	popl %ebx
	popl %ebx
	
	movl $1,%eax 
	xorl %ebx, %ebx
	int $0x80
