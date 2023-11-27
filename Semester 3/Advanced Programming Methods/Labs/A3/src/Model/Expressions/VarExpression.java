package Model.Expressions;

import Model.ADTs.DictionaryInterface;
import Model.Exceptions.MyException;
import Model.Values.ValueInterface;

public class VarExpression implements ExpressionInterface {
    String id;

    public VarExpression(String s) {
        id = s;
    }
    @Override
    public ValueInterface eval(DictionaryInterface<String, ValueInterface> tbl) throws MyException {
        return tbl.lookup(id);
    }

    @Override
    public String toString(){
        return id;
    }
}
