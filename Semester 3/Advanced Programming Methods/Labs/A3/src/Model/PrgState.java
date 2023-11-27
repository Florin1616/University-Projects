package Model;
import Model.ADTs.*;
import Model.Statements.StatementInterface;
import Model.Values.StringValue;
import Model.Values.ValueInterface;
import Model.Values.ValueInterface;

import javax.swing.plaf.nimbus.State;
import java.io.BufferedReader;
import java.util.Map;

public class PrgState {
    private StackInterface<StatementInterface> executionStack;
    private DictionaryInterface<String, ValueInterface> symbolTable;
    private ListInterface<ValueInterface> outputList;
    private StatementInterface originalProgram;
    private DictionaryInterface<StringValue, BufferedReader> fileTable;

    public PrgState(StackInterface<StatementInterface> stk, DictionaryInterface<String, ValueInterface> symtbl, ListInterface<ValueInterface> ot,DictionaryInterface<StringValue, BufferedReader> ft,StatementInterface prg){
        this.executionStack = stk;
        this.symbolTable = symtbl;
        this.outputList = ot;
        this.fileTable = ft;
        this.originalProgram = prg;
        this.executionStack.push(prg);
    }

    public PrgState(StatementInterface originalProgram){
        this.executionStack = new MyStack<>();
        this.symbolTable = new MyDictionary<>();
        this.outputList = new MyList<>();
        this.originalProgram = originalProgram;
        this.fileTable = new MyDictionary<>();
        this.executionStack.push(originalProgram);
    }

    public StackInterface<StatementInterface> getStack(){
        return executionStack;
    }

    public DictionaryInterface<String, ValueInterface> getSymTable(){
        return symbolTable;
    }

    public ListInterface<ValueInterface> getOut(){
        return outputList;
    }

    public DictionaryInterface<StringValue, BufferedReader> getFileTable() {return fileTable; }

    public void setExeStack(StackInterface<StatementInterface> stack){
        executionStack = stack;
    }

    public void setSymTable(DictionaryInterface<String, ValueInterface> symtbl){
        symbolTable = symtbl;
    }

    public void setOut(ListInterface<ValueInterface> outConsole){
        outputList = outConsole;
    }

    public void setFileTable(DictionaryInterface<StringValue, BufferedReader> fileTable){
        this.fileTable = fileTable;
    }

    public StatementInterface getOriginalProgram(){
        return originalProgram;
    }


    @Override
    public String toString() {
        StringBuilder str = new StringBuilder();
        str.append("Program state\n");
        str.append("File Table: ").append(fileTable).append(" \n");
        str.append("Exe Stack: ").append(executionStack).append(" \n");
        str.append("Sym Table: ").append(symbolTable).append(" \n");
        str.append("Output Console: ").append(outputList).append(" \n");
        str.append("\n");
        return str.toString();
    }


}
