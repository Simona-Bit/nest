package lesson4;

public class Sington {

    //饿汉模式
    public static final Sington SINGTON = new Sington();
    public static Sington getInstance(){
        return SINGTON;
    }

    //懒汉模式
    private volatile static Sington SINGTON2 = null;
    public static Sington getInstance2(){
        // 多个线程可以同时进入这行代码进行判断，都判断为null
        if (SINGTON2 == null){
            SINGTON2 = new Sington();
        }
        return SINGTON2;
    }

    //synchronized第一种写法
    public synchronized static Sington getInstance3(){
        /*synchronized (Sington.class){

        }*/
        // 多个线程可以同时进入这行代码进行判断，都判断为null
        if (SINGTON2 == null){
            SINGTON2 = new Sington();
        }
        return SINGTON2;
    }

    //synchronized第二种写法
    public static Sington getInstance4(){
        // 多个线程可以同时进入这行代码进行判断，都判断为null
        if (SINGTON2 == null){ //读操作
            //synchronized保证写操作安全性，volatile保证读操作性能效率
            synchronized (Sington.class){  //获取锁
                // 可以分解成三步操作：
                // 1、分配对象的内存空间
                // 2、执行对象初始化
                // 3、把对象赋给引用
                // 可能重排序为1 3 2的执行顺序
                if (SINGTON2 ==null){ // 写操作
                    SINGTON2 = new Sington();  //实例化
                }
            } //释放锁
        }
        return SINGTON2;
    }

    private Sington(){
        // nothing to do
    }

    public static void main(String[] args) {
        for (int i = 0; i<10; i++){
            new Thread(new Runnable() {
                @Override
                public void run() {
                    Sington.getInstance2();
                }
            }).start();
        }
    }
}
