package Model;
import Model.ADTs.*;
import Model.Exceptions.MyException;
import Model.Statements.StatementInterface;
import Model.Values.StringValue;
import Model.Values.ValueInterface;
import Model.Values.ValueInterface;
import com.sun.jdi.Value;

import javax.swing.plaf.nimbus.State;
import java.io.BufferedReader;
import java.util.Map;
import java.util.Vector;

public class PrgState {
    private StackInterface<StatementInterface> executionStack;
    private DictionaryInterface<String, ValueInterface> symbolTable;
    private ListInterface<ValueInterface> outputList;
    private StatementInterface originalProgram;
    private DictionaryInterface<StringValue, BufferedReader> fileTable;
    private HeapInterface heap;

//    private Integer id_thread;
//
//    static Vector<Integer> usedId = new Vector<>();
    private static int stateID;
    private static int freeID = 0;

    public static synchronized int getNewPrgStateID() {
        ++freeID;
        return freeID;
    }


//    public PrgState(StackInterface<StatementInterface> stk, DictionaryInterface<String, ValueInterface> symtbl, ListInterface<ValueInterface> ot,DictionaryInterface<StringValue, BufferedReader> ft,StatementInterface prg, HeapInterface heap){
//        this.executionStack = stk;
//        this.symbolTable = symtbl;
//        this.outputList = ot;
//        this.fileTable = ft;
//        this.originalProgram = prg;
//        this.heap = heap;
//        this.executionStack.push(prg);
//
//        stateID = getNewPrgStateID();
////        usedId.add(id_thread);
//
//    }
//return new PrgState(newStk, newSymTable, out, fileTable, heap, statement);
    public PrgState(StackInterface<StatementInterface> executionStack, DictionaryInterface<String, ValueInterface> symbolTable, ListInterface<ValueInterface> outputConsole, DictionaryInterface<StringValue, BufferedReader> fileTable, HeapInterface heapTable, StatementInterface originalProgram) {
        this.executionStack = executionStack;
        this.symbolTable = symbolTable;
        this.outputList = outputConsole;
        this.fileTable = fileTable;
        this.heap = heapTable;
        this.originalProgram = originalProgram;

        stateID = getNewPrgStateID();

        this.executionStack.push(originalProgram);

    }

    public PrgState(StatementInterface originalProgram){
        this.executionStack = new MyStack<>();
        this.symbolTable = new MyDictionary<>();
        this.outputList = new MyList<>();
        this.originalProgram = originalProgram;
        this.fileTable = new MyDictionary<>();
        this.heap = new MyHeap();
        this.executionStack.push(originalProgram);

        stateID = getNewPrgStateID();
    }

//    private int generateId() {
//        int newId = 1;
//        while (usedId.contains(newId)) {
//            newId++;
//        }
//        return newId;
//    }

    public boolean isNotCompleted() {
        return !executionStack.isEmpty();
    }

    public Integer getId_thread() {
        return stateID;
    }

    public void setId_thread(Integer id_thread) {
        this.stateID = id_thread;
    }


    public PrgState oneStep() throws MyException {
        if (executionStack.isEmpty())
            throw new MyException("Stack empty");
        StatementInterface currentStatement = executionStack.pop();
        return currentStatement.execute(this);
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

    public HeapInterface getHeap(){
        return heap;
    }

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

    public void setHeap(HeapInterface gHeap){
        heap = gHeap;
    }


    public StatementInterface getOriginalProgram(){
        return originalProgram;
    }


    @Override
    public String toString() {
        StringBuilder str = new StringBuilder();
        str.append("Thread number id: ").append(stateID).append("\n");
        str.append("Program state\n");
        str.append("File Table: ").append(fileTable).append(" \n");
        str.append("Exe Stack: ").append(executionStack).append(" \n");
        str.append("Sym Table: ").append(symbolTable).append(" \n");
        str.append("Heap: ").append(heap).append(" \n");
        str.append("Output Console: ").append(outputList).append(" \n");
        str.append("\n");
        return str.toString();
    }


}
