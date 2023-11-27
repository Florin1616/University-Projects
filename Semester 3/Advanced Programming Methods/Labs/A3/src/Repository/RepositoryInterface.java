package Repository;
import Model.Exceptions.MyException;
import Model.PrgState;
import Model.Statements.StatementInterface;

import javax.swing.event.InternalFrameEvent;
import java.io.IOException;
import java.util.List;

public interface RepositoryInterface {
    public List<PrgState> getPrgList();
    PrgState getCrtPrgState();
    StatementInterface getOriginalProgram();
    //void printPrgState(PrgState state) throws MyException;
    //void addPrgState(PrgState state);
    //void setCurrentProgram(int i);

    void logPrgStateExec(PrgState state) throws IOException;
}
