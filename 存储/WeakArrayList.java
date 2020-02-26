class Person{
    private String name;
    private String age;

    public Person(String name, String age) {
        this.name = name;
        this.age = age;
    }

    @Override
    public String toString() {
        return "Person{" +
                "name='" + name + '\'' +
                ", age='" + age + '\'' +
                '}';
    }
}
public class WeakArrayList {
    private Object[] array = new Object[10];
    private int size = 0;

    private void add(Object o){
        array[size++] = o;
    }
    private Object get(int index){
        return array[index];
    }

    public static void main(String[] args) {
        WeakArrayList list = new WeakArrayList();
        list.add(new Person("xi","4"));
        String s = (String)list.get(0);//编译错误
    }
}
