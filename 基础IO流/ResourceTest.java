package io.learning;

import org.junit.Test;

import java.io.IOException;
import java.io.InputStream;

public class ResourceTest {
    /*
     * 推荐写相对路径时的api
     * */
    @Test
    public void test1(){
        InputStream is = ResourceTest.class
                .getClassLoader()
                .getResourceAsStream("test1.txt");
        System.out.println(is);
    }

    @Test
    public void test2(){
        InputStream is = ResourceTest.class
                .getClassLoader()
                .getResourceAsStream("../../test1.txt");
        System.out.println(is);
    }
}
