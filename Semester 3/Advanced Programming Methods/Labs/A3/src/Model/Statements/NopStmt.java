package Model.Statements;

import Model.Exceptions.MyException;
import Model.PrgState;

public class NopStmt implements StatementInterface{
    @Override
    public PrgState execute(PrgState state) throws MyException {
        return state;
    }
}
