package lesson3;

import java.util.ArrayList;
import java.util.List;

public class UnsafeThread {
    //public static int COUNT; //初始化值默认为0

    public static void main(String[] args) {
        //开启20个线程，每个线程对COUNT进行++操作10000次
        //预期结果：200000
        /*//Thread[] threads = new Thread[20];
        for (int i = 0; i < 20; i++){
            Thread thread = new Thread(new Runnable() {
                @Override
                public void run() {
                    for (int j = 0; j<10000; j++){
                        COUNT++;
                        System.out.println(COUNT);
                    }
                }
            });
            thread.start();
        }*/

        /*for (int i = 0; i<20; i++){
            new Thread(new Runnable() {
                @Override
                public void run() {
                    for (int j = 0; j < 10000; j++){
                        COUNT++;
                    }
                }
            }).start();
        }
        while (Thread.activeCount()>1){
            Thread.yield();
        }
        System.out.println(COUNT);*/

        List<Integer> list = new ArrayList<>();
        for (int i = 0; i<20; i++){
            final int k = i;
            new Thread(new Runnable() {
                @Override
                public void run() {
                    for (int j = 0; j < 10000; j++){
                       // COUNT++;
                        list.add(k * 10000 + j);
                        //list放在堆里，可以共享；i放在栈空间，必须用final，匿名内部类只能调用外部final方法
                    }
                }
            }).start();
        }
        while (Thread.activeCount()>1){
            Thread.yield();
        }
        System.out.println(list.size());
    }
}
