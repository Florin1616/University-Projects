package Model.Statements;
import Model.*;
import Model.ADTs.DictionaryInterface;
import Model.ADTs.HeapInterface;
import Model.ADTs.MyStack;
import Model.ADTs.StackInterface;
import Model.Exceptions.MyException;
import Model.Expressions.ExpressionInterface;
import Model.Types.RefType;
import Model.Values.RefValue;
import Model.Values.ValueInterface;

public class NewHeapStmt implements StatementInterface{
    String var_name;
    ExpressionInterface exp;
    public NewHeapStmt(String var_name, ExpressionInterface exp) {
        this.var_name = var_name;
        this.exp = exp;
    }

    @Override
    public PrgState execute(PrgState state) throws MyException {
        StackInterface<StatementInterface> stack = state.getStack();
        DictionaryInterface<String, ValueInterface> symTbl = state.getSymTable();
        HeapInterface heap = state.getHeap();
        if(symTbl.isDefined(var_name)){
            if(symTbl.lookup(var_name).getType() instanceof RefType){
                ValueInterface val = exp.eval(symTbl, heap);
                ValueInterface tblVal = symTbl.lookup(var_name);
                if(val.getType().equals(((RefType)(tblVal.getType())).getInner())){
                    int addr = heap.allocate(val);
                    symTbl.update(var_name, new RefValue(val.getType(), addr));
                }
                else{
                    throw new MyException("Value's type is not correct!");
                }
            }
            else{
                throw new MyException("Value's type is not reference!");
            }
        }
        else{
            throw new MyException("Value is not declared!");
        }
        state.setSymTable(symTbl);
        state.setHeap(heap);
        state.setExeStack(stack);
        return null;
    }

    @Override
    public String toString(){
        return "new(" + var_name + ", " + exp + ")";
    }

    }

