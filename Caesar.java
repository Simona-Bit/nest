import java.util.Scanner;
public class Caesar {
	public static void main(String[] args) {
		System.out.println("A:���ܣ�B:���ܣ���ѡ��");
		Scanner scanner = new Scanner(System.in);
		String s1 = scanner.nextLine();//��ȡ�ַ���
		if(s1.equalsIgnoreCase("A")) {
			System.out.println("���������ģ� ");
			Scanner sc = new Scanner(System.in);
			String s = sc.nextLine();
			System.out.println("��������Կ�� ");
			Scanner sc1 = new Scanner(System.in);
			int key = sc1.nextInt();
			Encryptionkey(s,key);
		}else if(s1.equalsIgnoreCase("B")) {
			System.out.println("���������ģ� ");
			Scanner sc = new Scanner(System.in);
			String s = sc.nextLine();
			System.out.println("��������Կ�� ");
			Scanner sc1 = new Scanner(System.in);
			int key = sc1.nextInt();
			Decryptkey(s,key);
		}	
	}
	
	public static void Encryptionkey(String str, int k) {
		//����
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
			string += c;//�����ܺ���ַ������ַ���
		}
		System.out.println(str + "���ܺ�Ϊ�� "+string);
	}
	
	public static void Decryptkey(String str,int n) {
		//����
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
			string += c;//�����ܺ���ַ������ַ���
		}
		System.out.println(str+"���ܺ�Ϊ�� "+string);
	}
}
