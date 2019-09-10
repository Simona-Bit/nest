package Practiceti;

import java.util.*;
// 给定仅有小写字母组成的字符串数组 A，
// 返回列表中的每个字符串中都显示的全部字符（包括重复字符）组成的列表。
// 例如，如果一个字符在每个字符串中出现 3 次，但不是 4 次，则需要在最终答案中包含该字符 3 次。
// 你可以按任意顺序返回答案。
/*
    示例 1：
    输入：["bella","label","roller"] 输出：["e","l","l"]
    示例 2：
    输入：["cool","lock","cook"] 输出：["c","o"]

    提示：
    1 <= A.length <= 1001 <= A[i].length <= 100A[i][j] 是小写字母
    相关标签 
    数组哈希表
    两个数组的交集 II
 */
public class Solution2 {
    public List<String> commonChars(String[] A) {
        List<String> result = new ArrayList<>();
        //数组为空或者长度小于2，直接返回空结果
        if (A == null || A.length < 2){
            return result;
        }

        //使用 Map统计每个字符串中字符出现的次数，并把 Map结果放入到 List中
        List<Map<Character, Integer>> list = new ArrayList<>();
        for (String a: A){
            Map<Character, Integer> map = new HashMap<>();
            for (char c: a.toCharArray()){
                if (map.containsKey(c)){
                    map.put(c, map.get(c) + 1);
                }else {
                    map.put(c, 1);
                }
            }
            list.add(map);
        }

        //获取所有 Map中 key的交集（相当于获取每个字符串中都出现的字符）
        Set<Character> retainSet = list.get(0).keySet();
        for (int i = 1; i < list.size(); i++){
            retainSet.retainAll(list.get(i).keySet());
        }

        //循环 key的交集，并把获取到的次数最小的值为结果
        //比如字符串1中a出现了3次，字符串2出现了3次，字符串3出现了1次，那么这3个集合中重复的a的个数就为1
        Iterator<Character> iterator = retainSet.iterator();
        while (iterator.hasNext()){
            Character current = iterator.next();
            int minCount = list.get(0).get(current);
            for (int i = 1; i < list.size(); i++){
                Integer cnt = list.get(i).get(current);
                if (cnt < minCount){
                    minCount = cnt;
                }
            }
            for (int i = 0; i < minCount; i++){
                result.add(current + "");
            }
        }
        return result;
    }
}
