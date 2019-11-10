package lesson2;

public class InterruptThread {
    public static void main(String[] args) {
        /*Thread thread = new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    Thread.sleep(5000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        });
        thread.start();
        thread.interrupt();//中断操作*/

        Thread thread2 = new Thread(new Runnable() {
            @Override
            public void run() {
                //无sleep无中断
                while (true){

                }
            }
        });
        thread2.start();
        thread2.interrupt();
    }
}
