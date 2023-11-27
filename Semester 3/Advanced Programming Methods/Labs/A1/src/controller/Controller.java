package controller;

import exceptions.MyExceptions;
import model.IVehicle;
import repository.IRepository;
public class Controller {
    IRepository repository;

    public IVehicle[] filter(String color){
        //@SuppressWarnings("MismatchedReadAndWriteOfArray")
        IVehicle[] copy = new IVehicle[repository.getSize()];
        int size = 0;
        for(IVehicle vehicle : repository.getAllObjects())
            if(vehicle.getColor() == color)
                copy[size++] = vehicle;
        IVehicle[] vehicles_to_return = new IVehicle[size];
        if(size > 0)
            System.arraycopy(copy, 0, vehicles_to_return,0, size);
        return vehicles_to_return;
    }

    public Controller(IRepository _repo){
        repository = _repo;
    }

    public void addVehicle(IVehicle vehicle) throws MyExceptions{
        repository.addObject(vehicle);
    }

    public void removeVehicle(int position) throws MyExceptions{
        repository.removeObject(position);
    }

    public IVehicle[] getVehicles(){
        return repository.getAllObjects();
    }
}
