import java.util.LinkedList;
import java.util.Random;

public class LinkedListDemo {
    public static void main(String[] args) {
        LinkedList<String> list = new LinkedList<>();
        /*list.push("C");
        list.push("JavaSE");
        list.push("数据结构");
        list.push("操作系统");
        list.push("计算机体系原理");
        System.out.println(list.pop());*/
        list.addLast("C");
        list.addLast("JavaSE");
        list.addLast("数据结构");
        list.addLast("操作系统");
        list.get(2);
        System.out.println(list.poll());
        System.out.println(list.pollFirst());
        System.out.println(list.pollLast());
        System.out.println(list.size());

        Random random = new Random(20190820);
        System.out.println(random.nextInt(52));
        System.out.println(random.nextInt(52));

    }
}
