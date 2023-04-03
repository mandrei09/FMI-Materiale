import java.util.Scanner;
/**
 * Fiind dat un numar n, scrieti o metoda care insumeaza toti multiplii de 3 si 5 pana la n (inclusiv).
 */

public class Exercise4 {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int n=scanner.nextInt();
        int s=0;
        for(int i=1;i<=n;i++)
            if(i%3==0 || i%5==0)
                s+=i;
        System.out.println("Suma este " + s);
    }
}

