package repository;
import model.IVehicle;
import exceptions.MyExceptions;

import java.lang.annotation.IncompleteAnnotationException;

public interface IRepository {
    void addObject(IVehicle vehicle) throws MyExceptions;
    void removeObject(int position) throws MyExceptions;
    IVehicle getPos(int position) throws MyExceptions;
    IVehicle[] getAllObjects();
    int getSize();

}
