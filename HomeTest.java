package com.skd.test;

public class HomeTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		/*
		2������һЩ��������֤���¸������������
		01����ϵ�����:  > >= < <= != ==
		02������������� + - * / % ++ --
		03���߼������:  && || ! & | 
		04��λ�����     & | ~ ^
		05���������
			+= -= /= *= %=
			��intΪ��*/
		int a=6,b=3;
		System.out.println("a="+a+" b="+b);
		//�����ע��������
		boolean guanXi=a!=b;
		System.out.println("a!=b?---"+guanXi);
		System.out.println("=============���������=========================");
		//ȡ��       ����ĳ�Ա����������
		System.out.println("a%b="+(a%b));
		//�߼������      ���������Ԫ������       ����Ľ������
		//           ����                                      ����
		//˫����ж�·����         a&&b&&c&&d
		//��                                   a&&b&&c&&(x+y++*2>3)   ע��ʽ�ӵĽ���͹���    
		//λ����       ��������
		System.out.println("=============λ����=========================");
		System.out.println("a&b="+(a&b));//a&b=2
		/*
		 * 0000 0110
		 * 0000 0011
		 * 0000 0010
		 */
		boolean x=true,y=false;
		System.out.println("x&y="+(x&y));
		
	    a=a<<2;
	    //������λ
	    // 0000 0110
	    // 0001 1000
	    System.out.println("a="+a);
		System.out.println("=============�������=========================");
        //+= -= /= *= %=
		/*
		 * a+=2
		 * a=a+2
		 */
		a+=2;
		System.out.println("a="+a);
		/*
		 * ʹ�����ֲ�ͬ��������ʾ����ת���Ĺ���
			Сת�� ��Ȼת
			��תС  ǿ������ת��
		 */
		int x1=8;
		float f1=x1;
		System.out.println("x1="+x1+" f1="+f1);
		
		double d1=8.88,d2=7.77;
		int i1=(int)d1;//ǿ������ת��
		int xx1=(int)(d1*d2);
		int xx2=(int)d1*(int)d2;
		System.out.println("d1="+d1+" i1="+i1);
		System.out.println(xx1+"======"+xx2);
	}
}
