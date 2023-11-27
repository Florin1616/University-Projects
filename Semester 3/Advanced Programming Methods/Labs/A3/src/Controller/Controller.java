package Controller;
import Model.*;
import Model.ADTs.StackInterface;
import Model.Exceptions.MyException;
import Model.Statements.StatementInterface;
import Repository.Repository;
import Repository.RepositoryInterface;

import java.io.IOException;

public class Controller {
    private RepositoryInterface repository;
    public Controller(RepositoryInterface repository){
        this.repository = repository;
    }

    PrgState oneStep(PrgState state) throws MyException{
        //PrgState state = repository.getCrtPrgState();
        StackInterface<StatementInterface> stack = state.getStack();
        if(stack.isEmpty())
            throw new MyException("Stack is empty!");
        StatementInterface currentStatement = stack.pop();
        return currentStatement.execute(state);
    }

    public void allStep() throws MyException, IOException {
        PrgState prgState = repository.getCrtPrgState();
        repository.logPrgStateExec(prgState);
        //System.out.println(prgState);
        while (!prgState.getStack().isEmpty()) {
            PrgState state_to_print = oneStep(prgState);
            if(state_to_print != null)
                //System.out.println(state_to_print);
                repository.logPrgStateExec(state_to_print);

        }
        repository.logPrgStateExec(prgState);
    }
//    public void setCurrentProgram(int i) {
//        repository.setCurrentProgram(i);
//    }

}
