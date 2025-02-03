// 1. Write a Java program to convert an integer number to a binary number.


import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter an integer: ");
        int num = scanner.nextInt();
        
        String binary = "";

        while (num > 0) {
            binary = (num % 2) + binary;
            num /= 2;
        }

        System.out.println("Binary representation: " + (binary.isEmpty() ? "0" : binary));
        scanner.close();
    }
}


// 2. Write a Java program to count letters, spaces, numbers and other characters in an input string.


import java.util.*;
public class Main {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String input = scanner.nextLine();

        int letters = 0, spaces = 0, numbers = 0, others = 0;

        for (int i = 0; i < input.length(); i++) {
            char ch = input.charAt(i);
            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
                letters++;
            } else if (ch >= '0' && ch <= '9') {
                numbers++;
            } else if (ch == ' ') {
                spaces++;
            } else {
                others++;
            }
        }

        System.out.println("Letters: " + letters);
        System.out.println("Spaces: " + spaces);
        System.out.println("Numbers: " + numbers);
        System.out.println("Other characters: " + others);

        scanner.close();
    }
}
