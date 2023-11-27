package Model.Expressions;
import Model.Exceptions.MyException;
import Model.Values.ValueInterface;
import Model.ADTs.DictionaryInterface;
public interface ExpressionInterface {
     ValueInterface eval(DictionaryInterface<String,ValueInterface> tbl) throws MyException;

}
