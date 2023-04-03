import java.util.Scanner;
/**
 * Scrieți o metoda care sa calculeze factorialul unui numar n citit de la tastatura.
 */
public class Exercise3{
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int n=scanner.nextInt();
        int factorial=1;
        for(int i=2;i<=n;i++)
            factorial*=i;
        System.out.println("Factorialul este " + factorial);
    }
}
