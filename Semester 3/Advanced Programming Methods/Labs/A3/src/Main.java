import Controller.Controller;
import Model.Expressions.ArithmeticExpression;
import Model.Expressions.ValueExpression;
import Model.Expressions.VarExpression;
import Model.PrgState;
import Model.Statements.*;
import Model.Types.BoolType;
import Model.Types.IntType;
import Model.Types.StringType;
import Model.Values.BoolValue;
import Model.Values.IntValue;
import Model.Values.StringValue;
import Repository.RepositoryInterface;
import Repository.Repository;
import View.TextMenu;

import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;
import View.*;

public class Main {
    public static void main(String[] args) {
        StatementInterface ex1 = new CompStmt(new VarDeclStmt("v", new IntType()),
                new CompStmt(new AssignStmt("v", new ValueExpression(new IntValue(2))), new PrintStmt(new VarExpression("v"))));

        PrgState prg1 = new PrgState(ex1);
        RepositoryInterface repo1 = new Repository(prg1,"log1.txt");
        Controller controller1 = new Controller(repo1);

        StatementInterface ex2 = new CompStmt(new VarDeclStmt("a", new IntType()),
                new CompStmt(new VarDeclStmt("b", new IntType()),
                        new CompStmt(new AssignStmt("a", new ArithmeticExpression('+', new ValueExpression(new IntValue(2)), new
                                ArithmeticExpression('*', new ValueExpression(new IntValue(3)), new ValueExpression(new IntValue(5))))),
                                new CompStmt(new AssignStmt("b", new ArithmeticExpression('+', new VarExpression("a"), new ValueExpression(new
                                        IntValue(1)))), new PrintStmt(new VarExpression("b"))))));

        PrgState prg2 = new PrgState(ex2);
        RepositoryInterface repo2 = new Repository(prg2,"log2.txt");
        Controller controller2 = new Controller(repo2);


        StatementInterface ex3 = new CompStmt(new VarDeclStmt("a", new BoolType()),
                new CompStmt(new VarDeclStmt("v", new IntType()),
                        new CompStmt(new AssignStmt("a", new ValueExpression(new BoolValue(false))),
                                new CompStmt(new IfStmt(new VarExpression("a"), new AssignStmt("v", new ValueExpression(new
                                        IntValue(2))), new AssignStmt("v", new ValueExpression(new IntValue(3)))), new PrintStmt(new
                                        VarExpression("v"))))));

        PrgState prg3 = new PrgState(ex3);
        RepositoryInterface repo3 = new Repository(prg3,"log3.txt");
        Controller controller3 = new Controller(repo3);


        StatementInterface ex4 = new CompStmt(new VarDeclStmt("varf", new StringType()),
                new CompStmt(new AssignStmt("varf", new ValueExpression(new StringValue("C:\\SEMESTRUL 3 UBB\\MAP\\LABS\\HWLAB3\\test.in"))),
                        new CompStmt(new OpenRFileStmt(new VarExpression("varf")), new CompStmt(new VarDeclStmt("varc", new IntType()),
                                new CompStmt( new ReadFileStmt(new VarExpression("varf"), "varc"),
                                        new CompStmt(new PrintStmt(new VarExpression("varc")),
                                                new CompStmt(new ReadFileStmt(new VarExpression("varf"), "varc"),
                                                        new CompStmt(new PrintStmt(new VarExpression("varc")), new CloseRFileStmt(new VarExpression("varf"))))))))));


        PrgState prg4 = new PrgState(ex4);
        RepositoryInterface repo4 = new Repository(prg4,"log4.txt");
        Controller controller4 = new Controller(repo4);



        TextMenu menu = new TextMenu();
        menu.addCommand(new ExitCommand("0", "exit"));
        menu.addCommand(new RunExample("1", ex1.toString(), controller1));
        menu.addCommand(new RunExample("2", ex2.toString(), controller2));
        menu.addCommand(new RunExample("3", ex3.toString(), controller3));
        menu.addCommand(new RunExample("4", ex4.toString(), controller4));
        menu.show();

;
    }
}
