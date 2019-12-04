package io.learning;

import org.junit.Test;
import java.io.*;
import java.nio.charset.StandardCharsets;

public class FileInputStreamTest {
    @Test
    public void test1(){
        try {
            System.out.println(System.getProperty("user.dir"));
            File f = new File("F:\\Java_\\idea代码\\jdbc-demo\\src\\io\\learning\\text.txt");
            System.out.println(f.exists());
            FileInputStream fis = new FileInputStream(f);
            byte[] bytes = new byte[1024];
            int len = 0;
            while ((len = fis.read(bytes)) != -1){
                String s = new String(bytes, 0, len);
                System.out.println(s);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @Test
    public void test2(){
        try {
            System.out.println(System.getProperty("user.dir"));
            File f = new File("F:\\Java_\\idea代码\\jdbc-demo\\src\\io\\learning\\text.txt");
            System.out.println(f.exists());
            FileReader fr = new FileReader(f);
            char[] chars = new char[1024];
            int len = 0;
            while ((len = fr.read(chars)) != -1){
                String s = new String(chars,0,len);
                System.out.println(s);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @Test
    public void test3(){
        try {
            System.out.println(System.getProperty("user.dir"));
            File f = new File("F:\\Java_\\idea代码\\jdbc-demo\\src\\io\\learning\\text.txt");
            System.out.println(f.exists());
            FileInputStream fis = new FileInputStream(f);
            BufferedInputStream bis = new BufferedInputStream(fis);
            byte[] bytes = new byte[1024];
            int len = 0;
            while ((len = bis.read(bytes)) != -1){
                String s = new String(bytes, 0, len);
                System.out.println(s);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @Test
    public void test4(){
        try {
            System.out.println(System.getProperty("user.dir"));
            File f = new File("F:\\Java_\\idea代码\\jdbc-demo\\src\\io\\learning\\text.txt");
            System.out.println(f.exists());
            FileReader fr = new FileReader(f);
            BufferedReader br = new BufferedReader(fr);
            String s;
            while ((s = br.readLine()) != null){
                System.out.println(s);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @Test
    public void test5(){
        try {
            System.out.println(System.getProperty("user.dir"));
            File f = new File("F:\\Java_\\idea代码\\jdbc-demo\\src\\io\\learning\\text.txt");
            System.out.println(f.exists());
            FileWriter fw = new FileWriter(f);
            BufferedWriter bw = new BufferedWriter(fw);
            bw.write("1=123");
            bw.write("唐诗");
            bw.newLine();
            bw.write("宋词");
            bw.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @Test
    public void test6(){
        try {
            System.out.println(System.getProperty("user.dir"));
            File f = new File("F:\\Java_\\idea代码\\jdbc-demo\\src\\io\\learning\\text.txt");//文件为与US_ASCII对应的类型，这里没有改
            System.out.println(f.exists());
            FileInputStream fis = new FileInputStream(f);
            InputStreamReader isr = new InputStreamReader(
                    fis,StandardCharsets.US_ASCII);//转换必须用同种转换
            char[] chars = new char[1024];
            int len = 0;
            while ((len = isr.read(chars)) != -1){
                System.out.println(new String(chars,0,len));
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
