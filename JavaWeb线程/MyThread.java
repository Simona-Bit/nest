package lesson2;

public class MyThread {
    public static void main(String[] args) throws InterruptedException {
        Thread thread = new Thread(new Runnable() {
            @Override
            public void run() {
                System.out.println("明天要剁手了");
            }
        });
        thread.start();
        //不调用join时，创建线程会耗时较长，下边的main方法的代码会先执行
        //如果调用join，表示thread（线程的引用）会加入当前线程
        thread.join();//进入阻塞状态
        //下边代码常常先执行：因为以上创建线程部分很耗时
        System.out.println("今天还是要上课");
        /*Runnable runnable = new Runnable() {
            @Override
            public void run() {

            }
        };
        Thread thread = new Thread(runnable);
        thread.start();*/
    }
}
