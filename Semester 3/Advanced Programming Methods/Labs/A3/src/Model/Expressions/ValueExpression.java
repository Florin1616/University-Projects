package Model.Expressions;

import Model.ADTs.DictionaryInterface;
import Model.Exceptions.MyException;
import Model.Values.IntValue;
import Model.Values.ValueInterface;

public class ValueExpression implements ExpressionInterface {
    ValueInterface e;

    public ValueExpression(ValueInterface deepCopy) {
        e = deepCopy;
    }

    @Override
    public String toString() {
        return e.toString();
    }

    @Override
    public ValueInterface eval(DictionaryInterface<String, ValueInterface> tbl) throws MyException {
        return e;
    }

}
