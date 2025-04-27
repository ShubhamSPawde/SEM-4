import java.util.*;

// Single level inheritence

class Vehicle{
    public void display(){
        System.out.println("I am Vehicle");
    }
}

class Car extends Vehicle{
    public void speed(){
        System.out.println("I show speed");
    }
}

// Multilevel Inheritance

class Person{
    int age;
    String name;
    public Person(String name, int age){
        this.name = name;
        this.age = age;
    }
    void displayDetails(){
        System.out.println("Name : " + this.name + " age : "+ this.age);
    }
}

class Employee extends Person {
    int employeeId;
    int salary;
    
    public Employee(String name, int age, int employeeId, int salary) {
        super(name, age);
        this.employeeId = employeeId;
        this.salary = salary;
    }

    void showEmployeeDetails(){
        System.out.println("EmployeeId : " + this.employeeId +" Salary : "+ this.salary);
    }
}

class Manager extends Employee{
    int teamSize;
    String depertment;
    
    public Manager(String name, int age, int employeeId, int salary, int teamSize, String depertment) {
        super(name, age, employeeId, salary);
        this.teamSize = teamSize;
        this.depertment = depertment;
    }

    void showMangerDetails(){
        System.out.println("Department : " + this.depertment + " Team Size : " + this.teamSize);
    }
}

// Hierarchical Inheritance

class Animal{
    String name;
    int age;
    public Animal(String name, int age){
        this.name = name;
        this.age = age;
    }
    void speak(){
        System.out.println("Animal speaks");
    }
}

class Dog extends Animal{   
    String bread;
    public Dog(String name, int age, String bread){
        super(name, age);
        this.bread = bread;
    }
    void bark(){
        System.out.println("Dog speaks");
    }
}

class Cat extends Animal{
    String color;
    public Cat(String name, int age, String color){
        super(name, age);
        this.color = color;
    }
    void meow(){
        System.out.println("Cat speaks");
    }
}

class Parent{
    void show(){
        System.out.println("I am show");
    }
}
class Child extends Parent{
    void show(){
        super.show();
    }
}

interface Printable {
    void show();    
}

interface Showable{
    void show();
}

class Print implements Printable, Showable{
    public void show(){
        System.out.println("I am showing ;) Print");    
    }
}

public class Inheritance{
    public static void main(String[] args){
        Vehicle v = new Car();
        v.display();

        Manager m = new Manager("A", 30, 101, 700000, 10, "Production" );
        m.showMangerDetails();
        m.showEmployeeDetails();
        m.displayDetails();

        Dog dog = new Dog("Tommy", 10, "GermanSheferd");
        dog.bark();
        dog.speak();

        Cat cat = new Cat("mau", 5, "balack");
        cat.meow();
        cat.speak();

        Child c = new Child();
        c.show();

        Print p = new Print();
        p.show();
    }
}