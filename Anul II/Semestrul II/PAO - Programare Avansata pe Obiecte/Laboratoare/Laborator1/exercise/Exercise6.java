import java.util.Scanner;
/**
 * Cititi de la tastatura n note, numere intregi, intr-un vector. Cand cititi valoarea -1 de la tastatura, citirea
 * notelor se opreste si programul afiseaza media acestora.
 */
public class Exercise6{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int[] note = new int[101];
        int numarNote=0,notaCurenta=1,suma=0;
        do{
            notaCurenta=sc.nextInt();
            note[numarNote++]=notaCurenta;
            suma+=notaCurenta;
        }while(notaCurenta!=-1);
        System.out.println(suma + " " + (suma*1.0/numarNote) + " " + numarNote);
    }
}
