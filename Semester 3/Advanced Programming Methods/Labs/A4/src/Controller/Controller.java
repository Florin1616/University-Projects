package Controller;
import Model.*;
import Model.ADTs.StackInterface;
import Model.Exceptions.MyException;
import Model.Statements.StatementInterface;
import Model.Values.RefValue;
import Model.Values.ValueInterface;
import Repository.RepositoryInterface;

import java.util.List;
import java.util.Map;
import java.io.IOException;
import java.util.stream.Collectors;
import java.util.Collection;
import java.util.stream.Stream;

public class Controller {
    private RepositoryInterface repository;

    public Controller(RepositoryInterface repository) {
        this.repository = repository;
    }

    PrgState oneStep(PrgState state) throws MyException {
        //PrgState state = repository.getCrtPrgState();
        StackInterface<StatementInterface> stack = state.getStack();
        if (stack.isEmpty())
            throw new MyException("Stack is empty!");
        StatementInterface currentStatement = stack.pop();
        return currentStatement.execute(state);
    }

    public void allStep() throws MyException, IOException {
        PrgState prgState = repository.getCrtPrgState();
        repository.logPrgStateExec(prgState);
        while (!prgState.getStack().isEmpty()) {
            PrgState state_to_print = oneStep(prgState);
            if (state_to_print != null) {
                repository.logPrgStateExec(state_to_print);

                List<Integer> addressesToKeep = Stream.concat(getAddrFromSymTable(prgState.getSymTable().getContent().values()).stream(),
                        getAddrFromSymTable(prgState.getHeap().getContent().values()).stream()).toList();

                prgState.getHeap().setContent(safeGarbageCollector(addressesToKeep, prgState.getHeap().getContent()));
            }
        }
        repository.logPrgStateExec(prgState);
    }

//    public void setCurrentProgram(int i) {
//        repository.setCurrentProgram(i);
//    }

    Map<Integer, ValueInterface> safeGarbageCollector(List<Integer> addresses, Map<Integer, ValueInterface> heap) {
        return heap.entrySet().stream()
                .filter(elem -> addresses.contains(elem.getKey()) || heap.containsKey(elem.getKey()))
                .collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue));
    }

    List<Integer> getAddrFromSymTable(Collection<ValueInterface> symTableValues) {
        return symTableValues.stream()
                .filter(v -> v instanceof RefValue)
                .map(v -> {
                    RefValue v1 = (RefValue) v;
                    return v1.getAddress();
                })
                .collect(Collectors.toList());

    }




}
