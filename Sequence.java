package ThreadLearning;

public class Sequence {
    public static void main(String[] args) {
        //启动0-9编号的10个线程，每个线程打印它的编号(无序，0-9无法体现，改到100)
        for (int i = 0; i < 10; i++){
            final int j = i;
            Runnable r = new Runnable() {
                @Override
                public void run() {
                    System.out.println(j);
                }
            };
            Thread t = new Thread(r);
            t.start();
        }
    }
}
