class Group{
		//属性
		String name;
		int num;
		//方法
		//构造方法
		//1、定义类的时候，没有明确的给出构造方法
		
		Group(String n,int m){
			name = n;
			num = m;
		}
		void print(String welcome){
			System.out.printf("%s %s 的 %d 位同学们%n",welcome,name,num);
		}
	}
	
	class B{
		int sum;
		
		B(int a, int b, int c){
			System.out.println(a + b + c);
			sum = a + b + c;
		}
		
		void print(){
			System.out.println(sum);
		}
	}
public class Test4{
	public static void main(String[] args){
		Group group = new Group("java10班",50);
		group.print("欢迎来到比特，");
		
		B b = new B(1, 2, 3);
		b.print();
	}
}