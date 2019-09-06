import java.util.*;

public class Demo2 {
    public static void main(String[] args) {
        String s = "900 google.mail.com";
        String[] t = s.split(" ");
        System.out.println(t[0]);
        System.out.println(t[1]);
        int n = Integer.valueOf(t[0]);//将String 类型转成 Integer 类型，求域名出现的个数
        String[] u = t[1].split("\\.");
        System.out.println(u[0]);
        System.out.println(u[1]);
        System.out.println(u[2]);
        String[] v = {"google", "com"};
        String w = String.join(".", v);
        System.out.println(w);
    }
}
