import java.util.HashSet;
import java.util.Set;

public class P3 {
    public int numJewelsInStones(String s, String t){
        Set<Character> jewels = new HashSet<>();
        for (char ch : s.toCharArray()){
            jewels.add(ch);
        }
        int count = 0;
        for (char ch : t.toCharArray()){
            if (jewels.contains(ch)){
                count++;
            }
        }
        return count;
    }
}
