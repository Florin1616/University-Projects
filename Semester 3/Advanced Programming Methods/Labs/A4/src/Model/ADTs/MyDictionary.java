package Model.ADTs;

import Model.Exceptions.MyException;

import java.util.HashMap;
import java.util.Map;

public class MyDictionary<K,V> implements DictionaryInterface<K,V> {
    private Map<K,V> map;
    public MyDictionary(){
        map = new HashMap<K,V>();
    }
    @Override
    public void add(K id,V value) throws MyException {
        if (map.containsKey(id))
            throw new MyException("Element already exists!");
        map.put(id,value);
    }

    public Map<K, V> getContent() {
        return map;
    }

    @Override
    public void remove(K key) throws MyException {
        if(!map.containsKey(key)){
            throw new MyException("The key does not exist in the dictionary!");
        }
        map.remove(key);
    }

    @Override
    public void update(K key, V value) {
        map.put(key,value);
    }

    @Override
    public boolean isDefined(K id) {
        return map.containsKey(id);
    }

    @Override
    public Object lookup(Object key) {
        return map.get(key);
    }

//    @Override
//    public String toString() {
//        String result ="{";
//        for (K key : map.keySet())
//            result+= key.toString() + " -> " + map.get(key).toString() + ";";
//        result+="}";
//        return result;
//    }
    @Override
    public String toString() {
        String s = "";
        for (Map.Entry<K, V> h : this.map.entrySet()) {
            s += h.getKey() + "->" + h.getValue() + " | ";
        }
        return s;
    }
}
