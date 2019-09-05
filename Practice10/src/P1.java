import java.util.*;

public class P1 {
    private static Map<Integer, Integer> count(int[] numbers){
        // key: 数字
        //value: 该数字出现的次数
        Map<Integer, Integer> map = new HashMap<>();

        for (int n : numbers){
            // 判断下 n 在不在 map 中
            // 不在，出现次数是1
            // 在，出现次数 + 1
            int c = map.getOrDefault(n, 0);
            //判断查找的数字key 是否存在，若存在则返回它出现的次数，否则返回设定值0
            map.put(n, c + 1);
            //记录查找的数字 key 出现的次数
        }
        return map;
    }

    public static void main(String[] args) {
        int[] numbers = {3, 1, 2, 4, 9, 2, 3, 1, 5, 8, 7, 2, 3};
        Map<Integer, Integer> map = count(numbers);
        System.out.println(map);

        /*
        * keySet();  //取出所有的 key 所有的数字
        * values();  //取出的所有的 value 所有的出现次数
        * entrySet(); // 所有的 数字及其出现次数的键值对
        * */
        for (Map.Entry<Integer, Integer> entry : map.entrySet()){
            int number = entry.getKey();
            int cnt = entry.getValue();
            if (cnt == 1){
                System.out.println(number);
            }
        }
    }
}
