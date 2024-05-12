import java.util.Scanner;
public class simpleCalculator {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        System.out.println("Entern num1: ");
        int num1 = scanner.nextInt();
        int num2 = scanner.nextInt();
        scanner.nextLine();
        System.out.println("Enter operation symbol: ");
        String operator = scanner.nextLine();
        int result = 0;
        switch(operator){
            case "+":
                result = addnums(num1,num2);
                break;
            case "-":
                result = subnums(num1,num2);
                break;
            case "*":
                result = mulnums(num1,num2);
                break;
            case "/":
                result = dividenums(num1,num2);
                break;
            default:
                System.out.println("Invalid operator!");
                scanner.close();
        }
        System.out.println("Result is : "+result);
    }
    public static int addnums(int n, int m){
        return n+m;
    }
    public static int subnums(int n, int m){
        return n-m;
    }
    public static int mulnums(int n,int m){
        return n*m;
    }
    public static int dividenums(int n,int m){
        return n/m;
    }
    
}
