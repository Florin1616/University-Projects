package repository;

import exceptions.MyExceptions;
import model.IVehicle;

import javax.swing.*;

public class Repository implements IRepository{
    IVehicle[] vehicles;
    int size;

    public Repository(int capacity) throws MyExceptions{
        if(capacity <= 0)
            throw new MyExceptions("The capacity of the repository must be greater than 0");
        vehicles = new IVehicle[capacity];
    }
    @Override
    public void addObject(IVehicle vehicle) throws MyExceptions {
        if(size == vehicles.length)
            throw new MyExceptions("There is no more space");
        vehicles[size++] = vehicle;

    }

    @Override
    public void removeObject(int position) throws MyExceptions {
        if(position >= size || position < 0)
            throw new MyExceptions("Invalid position!");
        for(int i = position; i+1 < size; ++i)
            vehicles[i] = vehicles[i+1];
        --size;
    }

    @Override
    public IVehicle getPos(int position) throws MyExceptions {
        if(position >= size || position < 0)
            throw new MyExceptions("Invalid position!");
        return vehicles[position];
    }

    @Override
    public IVehicle[] getAllObjects() {
        IVehicle[] copy = new IVehicle[size];
        if(copy.length >=0) System.arraycopy(vehicles,0,copy,0,copy.length);
        return copy;
    }

    @Override
    public int getSize() {
        return size;
    }
}
