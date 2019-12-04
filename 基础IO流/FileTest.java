package io.learning;

import org.junit.Test;

import java.io.File;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class FileTest {
    public void test1(){
        File file = new File("F:\\Java_\\idea代码\\jdbc-demo\\jdbc-demo.iml");
        System.out.println(file);
        // 创建文件不建议创建到相对路径下，建议创建到绝对路径下

        File f = new File("f:/");
        //返回的是file类型的数组
        for (File fs : f.listFiles()){
            System.out.println(fs.getPath());
        }
    }

    // 实现一个方法,把自己某个目录下的所有子文件夹和子文件获取并打印
    @Test
    public void test2(){
        File dir = new File("F:\\Java_\\所有课件\\JavaWeb课件.zip");
        List<File> files = listFiles(dir);
        // files.stream().forEach(System.out::println); // 直接获取每一行数据并打印出来（file打印）
        // file类型的数据 获取所有并打印
        files.stream().forEach((fs)->{
            System.out.println(fs.getPath());
        });
    }

    // 递归
    public List<File> listFiles(File file){
        // 用数组返回
        List<File> list = new ArrayList<>();
        list.add(file);
        //System.out.println(file.getPath());
        //判断是否为文件夹
        if (file.isDirectory()){
            for (File f : file.listFiles()){
                //list.add(f); 这里添加就会重复添加文件夹
                if (f.isDirectory()){
                    // fileFiles(文件夹)
                    listFiles(f);
                }else {
                    //文件未添加，需添加
                    list.add(f);
                    //System.out.println(f.getPath());
                }
            }
        }
        return list;
    }

    public static void main(String[] args) {
        test3();
    }

    public static void test3(){
        // 给定多个测试用例，每个测试用例如下：
        // 4
        // 5 6 7
        // 11
        // 输出：abc
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()){
            //System.out.println("hasNext");
            int i1 = sc.nextInt();
           // System.out.println("i1");
            int i2 = sc.nextInt();
           // System.out.println("i2");
            int i3 = sc.nextInt();
            //System.out.println("i3");
            int i4 = sc.nextInt();
           // System.out.println("i4");
            int i5 = sc.nextInt();
           // System.out.println("i5");
            // 1、要么对于每个有明确结束标识api的api，需要明确返回这个标识，对于scanner就是标识符
            // 2、流关闭
            System.out.println("abc");
        }
    }
}
