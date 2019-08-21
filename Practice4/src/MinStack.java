import java.util.Stack;

public class MinStack {
    Stack<Integer> normal = new Stack<>();
    Stack<Integer> min = new Stack<>();
    public MinStack(){}  //构造方法

    public void push(int x){
        normal.push(x);
        if (min.empty()){
        min.push(x);
        }else {
            int m = min.peek();
            if (x < m){
                min.push(x);
            }else {
                min.push(m);
            }
        }
    }

    public void pop(){
        normal.pop();
        min.pop();
    }

    public int top(){
        return normal.peek();//查看此堆栈顶部的对象
    }

    public int getMin(){
        return min.peek();
    }
}
