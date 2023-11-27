package model;

public class Bicycle implements IVehicle{
    String color;
    String manufacturer;
    int yearOfRelease;
    public Bicycle(String _color, String _manufacturer, int _yearOfRelease){
        color = _color;
        manufacturer = _manufacturer;
        yearOfRelease = _yearOfRelease;
    }
    @Override
    public String getColor() {
        return color;
    }

    public String getManufacturer(){
        return manufacturer;
    }
    public int getYearOfRelease(){
        return yearOfRelease;
    }

    @Override
    public String toString(){
        return "Bicycle with color: " + color + " Year of release: " + yearOfRelease + " Manufacturer: " + manufacturer;
    }
}
