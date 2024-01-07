package Model.Statements;

import Model.ADTs.DictionaryInterface;
import Model.Exceptions.MyException;
import Model.Expressions.ExpressionInterface;
import Model.PrgState;
import Model.Types.StringType;
import Model.Values.StringValue;
import Model.Values.ValueInterface;

import java.io.BufferedReader;
import java.io.IOException;

public class CloseRFileStmt implements StatementInterface{
    private ExpressionInterface exp;

    public CloseRFileStmt(ExpressionInterface exp){
        this.exp = exp;
    }

    @Override
    public PrgState execute(PrgState state) throws MyException {
        DictionaryInterface<String, ValueInterface> symTable = state.getSymTable();
        ValueInterface val = exp.eval(symTable, state.getHeap());
        if (val.getType().equals(new StringType())) {
            DictionaryInterface<StringValue, BufferedReader> fileTable= state.getFileTable();
            StringValue stringVal = (StringValue)val;
            if (fileTable.isDefined(stringVal)){
                BufferedReader bufferedReader = fileTable.lookup(stringVal);
                try {
                    bufferedReader.close();
                }
                catch (IOException e){
                    throw new MyException("The file could not be closed!");
                }
                fileTable.remove(stringVal);
            }
            else {
                throw new MyException("The file " + stringVal.getValue() + "does not exist in the File Table!");
            }
        }
        else {
            throw new MyException("The value could not be evaluated to a string value!");
        }
        return null;
    }

    public String toString(){
        return "close(" + exp + ")";
    }
}
