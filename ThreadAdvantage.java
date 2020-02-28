package lesson2;

import java.util.Date;
import java.util.LinkedList;
import java.util.List;
import java.util.Random;

public class ThreadAdvantage {
    public static List<String> randomList(){
        //随机数
        char[] chars = {'a','b','c','z','A','Z'};
        List<String> list = new LinkedList<>();
        for(int i=0; i<10_0000; i++){
            int random = new Random().nextInt(chars.length);
            char c = chars[random];
            list.add(String.valueOf(c));
            //list.add("dddd");
        }
        return list;
    }

    public static void main(String[] args) throws InterruptedException {
        List<String> list = randomList();
        //创建10个线程，每个线程获取list中的10000个元素
        //时间java.util.Date、
        //jdk1.8 -> LocalDateTime
        long start = System.currentTimeMillis();
       // long start = new Date().getTime();
        Thread[] threads = new Thread[10];
        for(int i=0; i<10; i++){
            final int k = i;
            threads[i] = new Thread(new Runnable() {
                @Override
                public void run() {
                    Thread current = Thread.currentThread();
                    System.out.println("id="+current.getId()+",name="+current.getName());
                  //  System.out.println(threads[k].getName());
                    for (int j=0; j<10000; j++){
                        list.get(k*10000 + j);//k:匿名内部类只能调用外部final方法
                    }
                }
            },"我的线程"+k);
            threads[i].start();
        }
        //第一种做法：线程让步：yield
//        while(Thread.activeCount()>1){
//           Thread.yield();
//        }
        //第二种做法：调用线程加入/等待：join
        for(Thread thread : threads){
            thread.join();
        }//当前线程（main方法的地方）阻塞，调用线程（子线程）运行
        long end = System.currentTimeMillis();
        System.out.println("耗时："+(end - start)+"毫秒");
    }
}
