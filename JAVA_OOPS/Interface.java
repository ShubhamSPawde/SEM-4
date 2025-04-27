import java.util.*;

interface Shape{
    public double area();
    public double perimeter();
}

class Circle implements Shape{
    int radius;
    public Circle(int radius){
        this.radius = radius;
    }

    public double area(){
        return 3.14 * (this.radius) * (this.radius);
    }

    public double perimeter(){
        return 2 * 3.14 * (this.radius);
    }
} 

class Rectangle implements Shape{
    double length, breadth;
    public Rectangle(double length, double breadth){
        this.length = length;
        this.breadth = breadth;
    }

    public double area(){
        return (this.length) * (this.breadth);
    }

    public double perimeter(){
        return 2 * (this.length + this.breadth);
    }
}

interface Printable {
    public void printDetails();
}

interface Scannable{
    public void scanDocument();
}

class PrinterScanner implements Printable, Scannable{
    public void printDetails(){
        System.out.println("Printing document");
    }

    public void scanDocument(){
        System.out.println("Scanning document");
    }
}

public class Interface {
    public static void main(String[] args) {

        Shape circle = new Circle(10000);
        System.out.println("Area : " + circle.area() + " Perimeter : " + circle.perimeter());
        Shape rect = new Rectangle(10, 20);
        System.out.println("Area : " + rect.area() + " Perimeter : " + rect.perimeter());

        PrinterScanner p = new PrinterScanner();
        p.scanDocument();
        p.printDetails();

        
    }
}
