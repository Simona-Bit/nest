import java.util.*;

public class SetDemo {
    public static void main(String[] args){
        Set<String> set = new HashSet<>();
        set.add("hello");
        set.add("bit");
        set.add("hello");
        set.add("java");
        set.add("bit");

        System.out.println(set);
        System.out.println(set.contains("hello"));
        System.out.println(set.contains("chen"));

        Iterator<String> it = set.iterator();
        while (it.hasNext()){
            System.out.println(it.next());
        }
        for (String s : set){
            System.out.println(s);
        }
    }
}
