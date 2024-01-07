package Model.Statements;
import Model.PrgState;
import Model.Exceptions.MyException;
public interface StatementInterface {
    PrgState execute(PrgState state) throws MyException;

//    StatementInterface deepCopy();

}
