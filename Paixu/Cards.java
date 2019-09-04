package Paixu;

import java.util.Comparator;

public class Cards {
    //A - K
    int rank;
    //红桃 / 方块 / 黑桃 / 梅花
    int suit;
}
class DouDiZhuComparator implements Comparator<Cards>{
    // 2 最大   3 最小
    @Override
    public int compare(Cards o1, Cards o2){
        return o1.suit - o2.suit;
    }
}
