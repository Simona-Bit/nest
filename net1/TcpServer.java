package net.learning;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

//服务端
public class TcpServer {
    private static final int PORT = 9999; //给定一个本地IP
    public static void main(String[] args) {
        try {
            ServerSocket server = new ServerSocket(PORT);
            Socket socket = server.accept();  //accept()方法接收服务端发起的一些请求,返回一个Socket对象
            InputStream inputStream = socket.getInputStream();//输入流接收到之后进行处理解析
            InputStreamReader isr = new InputStreamReader(inputStream);//字节字符转换流
            BufferedReader reader = new BufferedReader(isr);
            String data = null;
            while ((data=reader.readLine())!= null){
                System.out.println(data);
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
        }
    }
}
