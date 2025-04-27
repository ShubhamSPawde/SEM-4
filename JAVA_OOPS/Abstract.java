import java.util.*;

abstract class Employee {
    String name;
    int id;
    abstract int calculateSalary(int wage);
    void displayDetails(){
        System.out.println("Name : " + name + " ID : " + id);
    }
}

class FullTimeEmployee extends Employee{
    public FullTimeEmployee(String name, int id){
        this.id = id;
        this.name = name;
    }

    int calculateSalary(int wage){
        return 12 * wage;
    }
}

class PartTimeEmployee extends Employee{
    
    public PartTimeEmployee(String name, int id){
        this.name = name;
        this.id = id;
    }

    int calculateSalary(int wage){
        return 12 * 24 * wage;
    }
}

abstract class Vehicle{
    String Model, Manufacturer;
    
    abstract int fuelEfficiency();
    void displayDetails(){
        System.out.println("Model : " + Model + "Manufacturer : " + Manufacturer);
    }
}

class Car extends Vehicle{
    String enginetype;
    public Car(String model, String manufacturer, String enginetype){
        this.Model = model;
        this.Manufacturer = manufacturer;
        this.enginetype = enginetype;
    }
    int fuelEfficiency(){
        if((this.enginetype).equals("A")){
            return 1000;
        }else{
            return 100;
        }
    }
}

class Truck extends Vehicle{
    int cargocapacity;
    public Truck(String model, String manufacturer, int cargocapacity){
        this.Model = model;
        this.Manufacturer = manufacturer;
        this.cargocapacity = cargocapacity;
    }
    int fuelEfficiency(){
        if(this.cargocapacity == 100){
            return 1000;
        }
        else if(this.cargocapacity < 100){
            return 600;
        }else{
            return 300;
        }
    }
}

public class Abstract {
    public static void main(String[] args) {
        
        Employee ft = new FullTimeEmployee("A", 1000);
        ft.displayDetails();
        System.out.println("Salary : " + ft.calculateSalary(100));
        
        Employee pt = new PartTimeEmployee("B", 500);
        pt.displayDetails();
        System.out.println("Salary : " + pt.calculateSalary(100));

        Vehicle car = new Car("ABC", "XYZ", "A");
        car.displayDetails();
        System.out.println("Fuel Efficiency : " + car.fuelEfficiency());

        Vehicle truck = new Truck("PQR", "PLM", 100);
        truck.displayDetails();
        System.out.println("Fuel Efficiency : " + truck.fuelEfficiency());

    }
}
