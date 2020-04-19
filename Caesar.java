import java.util.Scanner;
public class Caesar {
	public static void main(String[] args) {
		System.out.println("A:加密，B:解密，请选择：");
		Scanner scanner = new Scanner(System.in);
		String s1 = scanner.nextLine();//获取字符串
		if(s1.equalsIgnoreCase("A")) {
			System.out.println("请输入明文： ");
			Scanner sc = new Scanner(System.in);
			String s = sc.nextLine();
			System.out.println("请输入密钥： ");
			Scanner sc1 = new Scanner(System.in);
			int key = sc1.nextInt();
			Encryptionkey(s,key);
		}else if(s1.equalsIgnoreCase("B")) {
			System.out.println("请输入密文： ");
			Scanner sc = new Scanner(System.in);
			String s = sc.nextLine();
			System.out.println("请输入密钥： ");
			Scanner sc1 = new Scanner(System.in);
			int key = sc1.nextInt();
			Decryptkey(s,key);
		}	
	}
	
	public static void Encryptionkey(String str, int k) {
		//加密
		String string = " ";
		for(int i=0; i<str.length(); i++) {
			char c = str.charAt(i);
			if (c>='a' && c<='z') {
				c += k % 26;
				if(c<'a')
					c += 26;
				if(c>'z')
					c -= 26;
			}else if (c>='A' && c<='Z') {
				c += k % 26;
				if(c<'A') 
					c += 26;
				if(c>'Z')
					c -= 26;
			}
			string += c;//将解密后的字符连成字符串
		}
		System.out.println(str + "加密后为： "+string);
	}
	
	public static void Decryptkey(String str,int n) {
		//解密
		int k = Integer.parseInt("-"+n);
		String string = " ";
		for (int i = 0; i < str.length(); i++) {
			char c = str.charAt(i);
			if (c>='a' && c<='z') {
				c += k % 26;
				if(c<'a')
					c += 26;
				if(c>'z')
					c -= 26;
			}else if (c>='A' && c<='Z') {
				c += k % 26;
				if(c<'A') 
					c += 26;
				if(c>'Z')
					c -= 26;
			}
			string += c;//将解密后的字符连成字符串
		}
		System.out.println(str+"解密后为： "+string);
	}
}
