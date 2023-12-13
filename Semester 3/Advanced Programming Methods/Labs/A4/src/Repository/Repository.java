package Repository;

import Model.Exceptions.MyException;
import Model.PrgState;
import Model.Statements.StatementInterface;

import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class Repository implements RepositoryInterface{
    private  String logFilePath;
    private PrgState program_state;
    private StatementInterface originalProgram;

    @Override
    public List<PrgState> getPrgList() {
        return null;
    }


//    public Repository(String givenFileName){
//        logFilePath = givenFileName;
//        this.states = new ArrayList<>();
//    }
//    public Repository(){
//        this.states = new ArrayList<>();
//        this.logFilePath = "";
//    }
    public Repository(PrgState prgstate, String logFilePath){
        this.program_state = prgstate;
        this.logFilePath = logFilePath;
    }

//    public Repository(PrgState prgState, String logFilePath) throws IOException{
//        this.originalProgram = prgState.getOriginalProgram();
//        this.logFilePath = logFilePath;
//        File file = new File(logFilePath);
//        file.createNewFile();
//        try (FileWriter fileWriter = new FileWriter(file)) {
//            fileWriter.write("");
//        }
//        catch (IOException e) {
//            throw new MyException("The file could not be opened!");
//        }
//        states = new LinkedList<>();
//    }

    @Override
    public void logPrgStateExec(PrgState state) throws IOException {
        try {
            PrintWriter logfile=new PrintWriter(new BufferedWriter(new FileWriter(logFilePath,true)));
            logfile.write(state.toString());
            logfile.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
//        PrintWriter logFile = new PrintWriter(new BufferedWriter(new FileWriter(logFilePath, true)));
//        logFile.write(state.toString());
//        logFile.close();

    }

    @Override
    public PrgState getCrtPrgState() {
        return program_state;
    }

//    public void setCurrentProgram(int i){
//        this.index = i;
//    }

    @Override
    public StatementInterface getOriginalProgram() {
        return originalProgram;
    }



//    public void addPrgState(PrgState state) {
//        states.add(state);
//
//    }
}
