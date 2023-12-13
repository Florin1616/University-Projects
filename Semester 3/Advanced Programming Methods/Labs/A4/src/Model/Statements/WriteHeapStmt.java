package Model.Statements;

import Model.ADTs.DictionaryInterface;
import Model.ADTs.HeapInterface;
import Model.Exceptions.MyException;
import Model.Expressions.ExpressionInterface;
import Model.Expressions.ValueExpression;
import Model.PrgState;
import Model.Types.RefType;
import Model.Values.RefValue;
import Model.Values.ValueInterface;
import com.sun.jdi.Value;

public class WriteHeapStmt implements StatementInterface{
    private String variableName;
    private ExpressionInterface exp;

    public WriteHeapStmt(String variableName, ExpressionInterface exp) {
        this.variableName = variableName;
        this.exp = exp;
    }
    @Override
    public PrgState execute(PrgState state) throws MyException{
        DictionaryInterface<String, ValueInterface> symTable = state.getSymTable();
        HeapInterface heap = state.getHeap();
        if (symTable.isDefined(variableName)) {
            if (symTable.lookup(variableName).getType() instanceof RefType) {
                RefValue refVal = (RefValue) symTable.lookup(variableName);
                if (heap.contains(refVal.getAddress())) {
                    ValueInterface val = exp.eval(symTable, heap);

                    if (symTable.lookup(variableName).getType().equals(new RefType(val.getType()))) {
                        int address = refVal.getAddress();
                        heap.update(address, val);
                    }
                    else {
                        throw new MyException("The pointing variable has a different type than the evaluated expression.");
                    }
                }
                else {
                    throw new MyException("The address to which " + variableName + " points is not in the heap");
                }
            }
            else {
                throw new MyException(variableName + " is not a reference variable");
            }
        }
        else {
            throw new MyException(variableName + " is not defined");
        }

        return null;
    }
    @Override
    public String toString() {
        return "wH(" + variableName + "," + exp + ")";
    }
}
