import java.util.*;
public class CollectionDemo {
    public static void main(String[] args) {
        Collection<String>collection = new ArrayList<>();
        collection.add("2019");
        collection.add("08");
        collection.add("18");
        System.out.println(collection.size());
        System.out.println(collection.isEmpty());
        System.out.println(Arrays.toString(collection.toArray()));
        collection.remove("2019");
        System.out.println(collection.size());
        System.out.println(collection.isEmpty());
        System.out.println(Arrays.toString(collection.toArray()));
        collection.clear();
        System.out.println(collection.size());
        System.out.println(collection.isEmpty());
        System.out.println(Arrays.toString(collection.toArray()));
    }
}
