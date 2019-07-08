//线性表
class List{
	private int size;  //保存线性表中的数据个数
	
	List(){
		size = 0;
	}
	
	public void pushFront(int val){
		insert(0,val);
	}
	
	public void pushBack(int val){
		insert(size,val);
	}
	
	public void insert(int index,int val){
		size++;
	}
	
	public int getSize(){
		return size;
	}
}


//顺序表 extends 线性表
class ArrayList extends List{
	//private int[] array = new array[10];
	private int[] array;
	
	//这里其实可以不写
	ArrayList(){
		super();
		array = new int[10];
	}
	
	//重写
	//注解
	@Override
	public void insert(int index,int val){
		//不考虑扩容
		for(int i = getSize(); i > index; i--){
			array[i] = array[i - 1];
		}
		
		array[index] = val;
		
		super.insert(index, val);
	}
	
	public void display(){
		for(int i = 0; i < getSize(); i++){
			System.out.println(array[i]);
		}
	}
}

public class Course0623{
	public static void main(String[] args){
		ArrayList List = new ArrayList();
		List.pushBack(1);
		List.pushBack(2);
		List.pushBack(3);
		List.pushFront(10);
		List.pushFront(20);
		List.pushFront(30);
		List.insert(3, 100);
		
		List.display();
	}
}