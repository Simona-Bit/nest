package lesson4;

import java.io.File;

public class FileOperator {
    private volatile File file;
    // 对文件的读和写操作
    public void read(){ //可以同时读
        // String = file.read 伪代码
    }
    public synchronized void write(){ // 写-写互斥
        // file.write(String) 伪代码
    }

    public static void main(String[] args) {
        FileOperator operator = new FileOperator();
        for (int i = 0; i < 10; i++){
            new Thread(new Runnable() {
                @Override
                public void run() {
                    operator.write();
                }
            }).start();
        }
        for (int i = 0; i < 10; i++){
            new Thread(new Runnable() {
                @Override
                public void run() {
                    operator.read();
                }
            }).start();
        }
    }
}
