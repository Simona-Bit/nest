//打印杨辉三角
import java.util.ArrayList;
import java.util.List;

public class Yanghuisanjiao {
    //方法一：
   public static List<List<Integer>> generate0(int numRows) {
        List<List<Integer>> list = new ArrayList<>(numRows);//每一个顺序表的元素类型都是另一个顺序表的引用
        //list 是一种引用，List 类型的接口引用（java语法）
        //list 逻辑上是一种线性表
        //线性表的元素类型是List<Integer>
        //             (java语法)List 类型的接口引用
        //                       元素类型是Integer 类类型的引用
        //                       Integer 是 int 的包装类
        for (int i = 0; i < numRows; i++){
            list.add(new ArrayList<>(100));
        }
        list.get(0).add(1);
        list.get(1).add(1);
        list.get(1).add(1);
        for (int i = 2; i < numRows; i++) {
            List<Integer> nums = list.get(i);
            nums.add(1);
            for (int j = 1; j < i; j++) {
                int num = list.get(i - 1).get(j - 1)
                        + list.get(i - 1).get(j);
                nums.add(num);
            }
            nums.add(1);
        }
        return list;
   }
   //方法二
    public static List<List<Integer>> generate1 (int numRows){
       List<List<Integer>> list;
       list = new ArrayList<>();
       for (int i = 0; i < numRows; i++){
           List<Integer> nums = new ArrayList<>();
           nums.add(1);
           for (int j = 0; j <= i - 2; j++){
               List<Integer> preNums = list.get(i - 1);
               int p = preNums.get(j);
               int q = preNums.get(j + 1);
               int n = p + q;
               nums.add(n);
           }
           if (i != 0){
               nums.add(1);
           }
           list.add(nums);
       }
       return list;
    }

    //方法三:先把1都填进去，再进行修改相应的位置
    public static List<List<Integer>> generate2 (int numRows){
       List<List<Integer>> list = new ArrayList<>(numRows);
       for (int i = 0; i < numRows; i++) {
           List<Integer> arrayList = new ArrayList<>(i + 1);
           list.add(arrayList);
           for (int j = 0; j <= i; j++) {
               arrayList.add(1);
               if (i > 1 && j > 0 && j < i) {
                   int answer = list.get(i - 1).get(j - 1) + list.get(i - 1).get(j);
                   arrayList.set(j, answer);
               }
           }
       }
       return list;
    }

    private static void printPascalsTriangle(Yanghuisanjiao s, int n){
        System.out.println(s.generate0(n));
        System.out.println(s.generate1(n));
        System.out.println(s.generate2(n));
    }

    public static void main(String[] args) {
        Yanghuisanjiao yanghuisanjiao = new Yanghuisanjiao();
        printPascalsTriangle(yanghuisanjiao, 10);
    }
}
