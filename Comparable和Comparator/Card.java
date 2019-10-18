import java.util.Comparator;

public class Card {
    // A - K
    int rank;
    // 红桃 / 方块 / 黑桃 / 梅花
    int suit;
}

class DouDiZhuComparator implements Comparator<Card> {
    // 2 最大  3 最小
    @Override
    public int compare(Card o1, Card o2) {
        return o1.suit - o2.suit;
    }
}
