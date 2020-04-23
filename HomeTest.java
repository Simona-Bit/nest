package com.skd.test;

public class HomeTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		/*
		2：定义一些变量，验证以下各种运算符规律
		01：关系运算符:  > >= < <= != ==
		02：算术运算符： + - * / % ++ --
		03：逻辑运算符:  && || ! & | 
		04：位运算符     & | ~ ^
		05：组合运算
			+= -= /= *= %=
			以int为例*/
		int a=6,b=3;
		System.out.println("a="+a+" b="+b);
		//运算符注意运算结果
		boolean guanXi=a!=b;
		System.out.println("a!=b?---"+guanXi);
		System.out.println("=============算术运算符=========================");
		//取余       运算的成员必须是整数
		System.out.println("a%b="+(a%b));
		//逻辑运算符      参与运算的元素类型       运算的结果类型
		//           布尔                                      布尔
		//双与或有短路现象         a&&b&&c&&d
		//单                                   a&&b&&c&&(x+y++*2>3)   注重式子的结果和过程    
		//位运算       最快的运算
		System.out.println("=============位运算=========================");
		System.out.println("a&b="+(a&b));//a&b=2
		/*
		 * 0000 0110
		 * 0000 0011
		 * 0000 0010
		 */
		boolean x=true,y=false;
		System.out.println("x&y="+(x&y));
		
	    a=a<<2;
	    //左移两位
	    // 0000 0110
	    // 0001 1000
	    System.out.println("a="+a);
		System.out.println("=============组合运算=========================");
        //+= -= /= *= %=
		/*
		 * a+=2
		 * a=a+2
		 */
		a+=2;
		System.out.println("a="+a);
		/*
		 * 使用两种不同类型来演示类型转换的规律
			小转大 自然转
			大转小  强制类型转换
		 */
		int x1=8;
		float f1=x1;
		System.out.println("x1="+x1+" f1="+f1);
		
		double d1=8.88,d2=7.77;
		int i1=(int)d1;//强制类型转换
		int xx1=(int)(d1*d2);
		int xx2=(int)d1*(int)d2;
		System.out.println("d1="+d1+" i1="+i1);
		System.out.println(xx1+"======"+xx2);
	}
}
