public class Main {
	public static void learnIdentifier() {
		// int 998;		// 用数字开头，错误
		// int *aaa;		// *开头不可以
		// int $98;		// 编译没问题，不建议用
		// int 我其实可以;	// 编译没问题，没这么用
		// int for;		// 关键字不能用
	}
	
	public static void learnUnicode() {
		String a = "中国";
		String b = "\u4e2d\u56fd";
		
		System.out.println(a);
		System.out.println(b);
	}
	
	public static void learnLiteral() {
		//byte a = 127;
		//int a = 100L;
		int a = 0xFF;
		int b = 0b11;
		int c = 99;
	}
	
	public static void learnTypeCast() {
		long a = 100L;
		int b = 100;
		
		int c = (int)a;	// long -> int 要强转
		long d = b;		// int -> long 不需要
	}
	
	public static void learnDefaultValue() {
		int a;
		
		a = 10;
		
		System.out.println(a);
	}
	
	public static void learnRange() {
		System.out.println("byte 型的范围");
		System.out.println(Byte.MIN_VALUE);
		System.out.println(Byte.MAX_VALUE);
	}
	
	public static void learnStringAdd() {
		int a = 3;
		int b = 4;
		
		System.out.println("结果是" + a + b);
		System.out.println("结果是" + (a + b));
	}
	
	public static void main(String[] args) {
		learnUnicode();
		learnRange();
		learnStringAdd();
	}
}