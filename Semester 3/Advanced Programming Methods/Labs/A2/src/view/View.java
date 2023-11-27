package view;
import controller.Controller;
import exceptions.MyExceptions;
import model.IVehicle;
import model.Car;
import model.Bicycle;
import model.Motorcycle;
import repository.IRepository;
import repository.Repository;

public class View {
    public static void main(String[] args) throws MyExceptions{

        IRepository repository;
        try{
            repository = new Repository(6);
        }catch(MyExceptions exception){
            System.out.println(exception.getMessage());
            return;
        }
        Controller controller = new Controller(repository);
        Bicycle b1 = new Bicycle("red", "Ghost", 2018);
        Bicycle b2 = new Bicycle("blue", "Cube", 2023);
        Car c1 = new Car("blue", "BMW", 2021);
        Car c2 = new Car("purple", "Mercedes", 2020);
        Motorcycle m1 = new Motorcycle("blue", "Yamaha", 2019);
        Motorcycle m2 = new Motorcycle("green", "Harley Davidson", 2010);

        try {
            controller.addVehicle(b1);
            controller.addVehicle(b2);
            controller.addVehicle(c1);
            controller.addVehicle(c2);
            controller.addVehicle(m1);
            controller.addVehicle(m2);
        }catch (MyExceptions me){
            System.out.println(me.getMessage());
        }
        controller.removeVehicle(1);
        System.out.println("---Show vehicles after removal---");
        for (IVehicle vehicle : controller.getVehicles())
            System.out.println(vehicle.toString());
        System.out.println("---Showing filtered vehicles---");
        for (IVehicle vehicle : controller.filter("blue"))
            System.out.println(vehicle.toString());
    }
}
