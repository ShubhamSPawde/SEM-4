class InvalidAgeException extends Exception{
    InvalidAgeException(String m){
        super(m);
    }
}

public class ExceptionHandling {
    public static void main(String[] args) {
        
        try{
            int c = 5 / 0;
        }catch(ArithmeticException e){
            System.out.println("Cannot divide by zero : "+e.getMessage());
        }

        int[] arr = {1, 2, 3, 4, 5};
        try{
            arr[5] = 10;
        }catch(IndexOutOfBoundsException e){
            System.out.println("Invalid idx : " + e.getMessage());
        }

        String num = "123e";
        try {
            int n = Integer.parseInt(num);
        } catch (NumberFormatException e) {
            System.out.println("Invalid number format : "+e.getMessage());
        }

        int age = 17;
        try{
            if(age < 18){
                throw new InvalidAgeException("age is less than 18");
            }
        }catch(Exception e){
            System.out.println(e.getMessage());
        }

        try {
            checkNumber(-10);  
        } catch (IllegalArgumentException e) {
            System.out.println("Exception caught: " + e.getMessage());
        }

    }

    static void checkNumber(int num) throws IllegalArgumentException {
        if (num < 0) {
            throw new IllegalArgumentException("Number cannot be negative!");
        } else {
            System.out.println("Number is positive: " + num);
        }
    }
    
}