import java.util.Scanner;

public class InputOutputExample {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner scanner = new Scanner(System.in);

        // Prompt the user to enter some input
        System.out.print("Enter some text: ");

        // Read the input entered by the user
        String userInput = scanner.nextLine();

        // Print the input entered by the user
        System.out.println("You entered: " + userInput);

        // Close the scanner to release system resources
        scanner.close();
    }
}
