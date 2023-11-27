package Model.ADTs;
import java.io.BufferedReader;
import java.util.*;
import Model.Exceptions.MyException;
import Model.Values.StringValue;

public interface DictionaryInterface<K,V> {
    void add(K key, V value) throws MyException;

    //void add(StringValue key, BufferedReader value) throws MyException;

    public void remove(K key) throws MyException;
    public void update(K key, V value);
    boolean isDefined(K id);
    public V lookup(K key);
    String toString();

}
