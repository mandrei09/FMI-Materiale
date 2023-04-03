import java.util.Scanner;
/**
 * Cititi de la tastatura n numere. Elementele citite vor fi organizate in doi vectori diferiti, in functie de
 * paritate (de ex: elementele pare in vectorul x, iar cele impare in vectorul y).
 */

public class Exercise5{
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int n=scanner.nextInt(),x,p=0,q=0,i;
        int[] a = new int[101], b= new int[101];
        for(i=0;i<n;i++){
            x=scanner.nextInt();
            if (x%2==0)
                a[p++]=x;
            else b[q++]=x;
        }
        System.out.println();
        for(i=0;i<p;i++)
            System.out.print(a[i] + " ");
        System.out.println();
        for(i=0;i<q;i++)
            System.out.print(b[i] + " ");
    }
}