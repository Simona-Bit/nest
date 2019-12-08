package net.learning;

import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.Socket;

//客户端
public class TcpClient {
    private static final String HOST = "";
    private static final int PORT = 9999;
    public static void main(String[] args) {
        try {
            Socket socket = new Socket(HOST,PORT);
            OutputStream os = socket.getOutputStream();
            PrintWriter pw = new PrintWriter(os,true);
            pw.println("Hello");
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
        }
    }
}
