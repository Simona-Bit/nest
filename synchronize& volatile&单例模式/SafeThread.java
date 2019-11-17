package lesson4;

public class SafeThread {
    public static int COUNT; //初始化值默认为0

    public static void main(String[] args) {
        //开启20个线程，每个线程对COUNT进行++操作10000次
        //预期结果：200000
        Object object = new Object();
        for (int i = 0; i<20; i++){
            new Thread(new Runnable() {
                @Override
                public void run() {
                   // Object object = new Object();
                    for (int j = 0; j < 10000; j++){
                        //COUNT++; //非原子性
                        //第一种方法：静态类对象锁定
                        increment();
                        decrement();
                        // 第二种：对实例对象锁定
                        /*synchronized (object){
                            COUNT++;
                        }*/
                    }
                }
            }).start();
        }
        while (Thread.activeCount()>2){ // >2用run跑，>1用Debug跑
            Thread.yield();
        }
        System.out.println(COUNT);
    }
    //表示为同步方法，轮流执行，每个线程不能同时进行操作，而是依次进行操作
    public synchronized static void increment(){
        COUNT++;
    }
    /*public static void increment(){
        synchronized (SafeThread.class){
            COUNT++;
        }
    }*/
    public synchronized static void decrement(){
        COUNT--;
    }
    public synchronized void increment2(){

    }

    /*public synchronized void increment2(){
        synchronized (this){

        }
    }*/
}
