package list;

public class Main {
    public static void main(String[] args) {
        list list = new MyArrayList();
        list.add(1);
        list.add(2);
        list.add(3);
        String r = list.toString();
        System.out.println(r);
    }
}
