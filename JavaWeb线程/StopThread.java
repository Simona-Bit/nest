package lesson2;

public class StopThread {
    //中断线程：interrupt()中断动作
    //interrupted()判断是否中断
    //isinterrupted()判断是否中断

    /**
     * 是否被中断：默认没有被中断
     */
    private static volatile boolean myInterrupted;//volatile可有可无，专用于多线程，安全严谨的写法

    public static void main(String[] args) throws InterruptedException {
        new Thread(new Runnable() {
            @Override
            public void run() {
                while(!myInterrupted){
                    System.out.println("hello");
                    //匿名内部类中的异常必须捕获处理
                    try {
                        Thread.sleep(1000);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
        }).start();
        Thread.sleep(5000);//阻塞5秒，再向下执行
        myInterrupted = true;
    }
}
