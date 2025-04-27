class Shape {
    double area() {
        return 0.0;
    }

    void display() {
        System.out.println("This is Display");
    }

    void add(int a, int b) {
        System.out.println("Sum of Integer : " + (a + b));
    }

    void add(double a, double b) {
        System.out.println("Sum of Double : " + (a + b));
    }
}

class Rectangle extends Shape {
    double length;
    double breadth;

    public Rectangle(double length, double breadth) {
        this.length = length;
        this.breadth = breadth;
    }

    double area() {
        return (this.length) * (this.breadth);
    }

    void display() {
        System.out.println("This is Rectagle");
    }
}

class Circle extends Shape {
    double radius;

    Circle(double radius) {
        this.radius = radius;
    }

    double area() {
        return 3.14 * radius * radius;
    }

    void display() {
        System.out.println("This is Circle");
    }

}

public class Polymorphism {
    public static void main(String[] args) {
        
        Rectangle r = new Rectangle(10, 8);
        r.display();
        printArea(r);

        Circle c = new Circle(100);
        c.display();
        printArea(c);

        r.add(2, 3);
        r.add(2.5, 3.5);
    }

    static void printArea(Shape shape) {
        System.out.println("Area : " + shape.area());
    }
}
