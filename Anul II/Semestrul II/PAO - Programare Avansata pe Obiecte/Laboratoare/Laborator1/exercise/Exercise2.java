import java.util.Scanner;
/**
 * Scrieți un program care sa compare doua numere a și b citite de la tastatura si sa afiseze numarul mai
 * mare.
 */
public class Exercise2 {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int a=scanner.nextInt(),b=scanner.nextInt();
        System.out.println(a>b ? a : b);
    }
}
