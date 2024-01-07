package Model.Statements;

import Model.ADTs.*;
import Model.Exceptions.MyException;
import Model.PrgState;

import javax.swing.plaf.nimbus.State;
import Model.*;
import Model.Values.StringValue;
import Model.Values.ValueInterface;

import java.io.BufferedReader;
import java.util.Map;

public class ForkStmt implements StatementInterface {
    private StatementInterface statement;

    public ForkStmt(StatementInterface stmt){
        this.statement = stmt;
    }

    @Override
    public PrgState execute(PrgState state ) throws MyException {
        DictionaryInterface<String, ValueInterface> symbolTable = state.getSymTable();
        ListInterface<ValueInterface> out = state.getOut();
        DictionaryInterface<StringValue, BufferedReader> fileTable = state.getFileTable();
        HeapInterface heap = state.getHeap();
        MyStack<StatementInterface> newStk = new MyStack<StatementInterface>();
        DictionaryInterface<String, ValueInterface> newSymTable = new MyDictionary<String, ValueInterface>();
        for (Map.Entry<String, ValueInterface> entry: symbolTable.getContent().entrySet()) {
            newSymTable.update(new String(entry.getKey()), entry.getValue().deepCopy());
        }

        return new PrgState(newStk, newSymTable, out, fileTable, heap, statement);
    }


    @Override
    public String toString() {
        return "fork(" + this.statement.toString() + ")";
    }
}
