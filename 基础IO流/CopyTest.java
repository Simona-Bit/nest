package io.learning;

import org.junit.Test;

import java.io.*;

public class CopyTest {
    @Test
    public void test1(){
        try {
            FileInputStream fis = null;
            FileOutputStream fos = null;
            try {
                File f = new File("F:\\Java_\\所有课件\\JavaWeb课件.zip");
                fis = new FileInputStream(f);
                File dest = new File("F:\\Java_\\所有课件\\1.rar");
                fos = new FileOutputStream(dest);
                byte[] bytes = new byte[1024];
                int len = 0;
                while ((len = fis.read(bytes)) != -1){
                    fos.write(bytes,0,len);
                }
            } finally {
                if (fis != null)
                    fis.close();
                if (fos != null)
                    fos.close();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @Test
    public void test2(){
        try {
            FileInputStream fis = null;
            FileOutputStream fos = null;
            BufferedInputStream bis = null;
            BufferedOutputStream bos = null;
            try {
                File f = new File("F:\\Java_\\所有课件\\JavaWeb课件.zip");
                fis = new FileInputStream(f);
                bis = new BufferedInputStream(fis);
                File dest = new File("F:\\Java_\\所有课件\\1.rar");
                fos = new FileOutputStream(dest);
                bos = new BufferedOutputStream(fos);
                byte[] bytes = new byte[1024];
                int len = 0;
                while ((len = fis.read(bytes)) != -1){
                    fos.write(bytes,0,len);
                }
            } finally {
                if (fis != null)
                    fis.close();
                if (fos != null)
                    fos.close();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
