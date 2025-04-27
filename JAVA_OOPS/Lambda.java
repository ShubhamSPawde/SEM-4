import java.util.*;

interface Calculator {
    int calculate(int a, int b);
}

public class Lambda {
    public static void main(String[] args) {
        Calculator Addition = (int x, int y) -> {
            return x+y;
        };

        Calculator Substraction = (int x, int y) -> {
            return x-y;
        };

        Calculator Division = (int x, int y) -> {
            try{
                return x/y;
            }catch(ArithmeticException e){
                System.out.println(e.getMessage());
                return 0;
            }
        };

        Calculator Multiplication = (int x, int y) -> {
            return x * y;
        };

        System.out.println("Addition : " + Addition.calculate(10, 11));
        System.out.println("Substraction : " + Substraction.calculate(10, 11));
        System.out.println("Multiplication : " + Multiplication.calculate(10, 11));
        System.out.println("Division : " + Division.calculate(10, 0));
        System.out.println("Division : " + Division.calculate(10, 2));
    }
}
