import java.util.*;

public class Solution {
    private static void swap(ArrayList<PokeCard> list, int i, int j){
        PokeCard tmpI = list.get(i);
        PokeCard tmpJ = list.get(j);
        list.set(i, tmpJ);
        list.set(j, tmpI);
    }
    public static void main(String[] args) {
        ArrayList<PokeCard> cards = new ArrayList<>(52);
        String[] colors = {"♥","♦","♠","♣"};
        for (int i = 0; i < 4; i++){
            for (int j = 1; j <= 13; j++){
                PokeCard card = new PokeCard(j, colors[i]);
                cards.add(card);
            }
        }
        System.out.println(cards);

        //洗牌
        /*Random random = new Random(20190820);
        for (int i = 0; i < 10; i++){
            System.out.println(random.nextInt(20));
        }//固定的随机数*/

       Random random = new Random(20190820);
        //理论符合均匀分布，但不会证明
        for(int i = 51; i > 0; i--){
            int j = random.nextInt(i);
            swap(cards, i, j);
        }
        System.out.println(cards);

        //有三个人，每人抓五张牌,依次抓取
        ArrayList<PokeCard> A = new ArrayList<>();
        ArrayList<PokeCard> B = new ArrayList<>();
        ArrayList<PokeCard> C = new ArrayList<>();

        System.out.println(cards.subList(52 - 15, 52));
        for (int i = 0; i < 15; i++){
            PokeCard card = cards.remove(cards.size() - 1);//尾删
            switch (i % 3){
                case 0:
                    A.add(card); break;
                case 1:
                    B.add(card); break;
                case 2:
                    C.add(card); break;
            }
        }
        System.out.println(cards.size());
        System.out.println(A);
        System.out.println(B);
        System.out.println(C);

        //A 抓到手里的牌中，有没有[红心 A]
        PokeCard heartA = new PokeCard(6,"♠");

        for (PokeCard card : A){
            //如何判断 card 是不是红心 A
            //自定义类如何判断两个对象相等？
            if (card.equals(heartA)){
                System.out.println("包含");
            }
        }
        if (A.contains(heartA)){
            System.out.println("包含");
        }else {
            System.out.println("不包含");
        }

        /*System.out.println(A);
        for (int i = 0; i < A.size(); i++){
            PokeCard o = A.get(i);
            if (o.equals(heartA)){
                A.remove(i);
            }
        }
        System.out.println(A);*/

        //迭代器
        System.out.println(A);
        Iterator<PokeCard> it = A.iterator();
        while (it.hasNext()) {
            PokeCard o = it.next();
            if (o.equals(heartA)){
                it.remove();
            }
        }
        System.out.println(A);

        Iterator<PokeCard> it1 = A.iterator();
        while (it1.hasNext()){
            System.out.println(it1.next());
        }

        ListIterator<PokeCard> it2 = A.listIterator();
        System.out.println(it2.next());
        System.out.println(it2.next());
        System.out.println(it2.previous());
    }
}