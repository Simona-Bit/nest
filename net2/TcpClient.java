package net.learning;

import java.io.*;
import java.net.Socket;
import java.util.Scanner;

//客户端
public class TcpClient {
    private static final String HOST = "";
    private static final int PORT = 9999;
    public static void main(String[] args) {
        try {
            Socket socket = new Socket(HOST,PORT);
            // 客户端发送数据IO流
            OutputStream os = socket.getOutputStream();
            PrintWriter pw = new PrintWriter(os,true);
            // 客户端接收数据IO流
            InputStream is = socket.getInputStream();
            InputStreamReader isr = new InputStreamReader(is);
            BufferedReader br = new BufferedReader(isr);
            // 接收数据台输入数据
            Scanner sc = new Scanner(System.in);
            while (sc.hasNext()){
                String line = sc.nextLine();
                pw.println(line);
                String content = br.readLine(); //必须放在发送数据之后，否则客户端和服务端都在读取，无法执行
                System.out.println("rev:"+content);
            }
            pw.println("Hello");
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
        }
    }
}
