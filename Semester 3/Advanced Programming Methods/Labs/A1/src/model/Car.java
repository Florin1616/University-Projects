package model;

public class Car implements IVehicle{
    String color;
    String manufacturer;
    int yearOfRelease;
    public Car(String _color, String _manufacturer, int _yearOfRelease){
        color = _color;
        manufacturer = _manufacturer;
        yearOfRelease = _yearOfRelease;
    }
    @Override
    public String getColor() {
        return color;
    }
    public String getManufacturer() {
        return manufacturer;
    }
    public int getYearOfRelease(){
        return yearOfRelease;
    }


    @Override
    public String toString(){
        return "Car with color: " + color + " Year of release: " + yearOfRelease + " Manufacturer: " + manufacturer;
    }
}
