package Model.Statements;

import Model.ADTs.ListInterface;
import Model.ADTs.StackInterface;
import Model.Exceptions.MyException;
import Model.PrgState;
import Model.Expressions.ExpressionInterface;
import Model.Values.ValueInterface;

public class PrintStmt implements StatementInterface{
    ExpressionInterface expression;

    public PrintStmt(ExpressionInterface expr) {
        expression = expr;
    }
    @Override
    public String toString(){
        return "print(" + expression.toString() +")";
    }
    @Override
    public PrgState execute(PrgState state) throws MyException {
        StackInterface<StatementInterface> stack = state.getStack();
        ListInterface<ValueInterface> outConsole = state.getOut();
        outConsole.add(expression.eval(state.getSymTable()));
        state.setExeStack(stack);
        state.setOut(outConsole);
        return null;
    }
}
