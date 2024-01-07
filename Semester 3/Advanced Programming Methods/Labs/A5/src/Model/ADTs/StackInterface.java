package Model.ADTs;
import java.util.ArrayList;
import Model.Exceptions.MyException;
public interface StackInterface<T> {
    T pop() throws MyException;
    void push(T value);
    boolean isEmpty();
    String toString();
}
