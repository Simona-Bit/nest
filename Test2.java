import java.util.Arrays;
public class Test2{
	public static int max(int[] array){
		//推荐这里使用foreach
		int maxValue = Integer.MIN_VALUE;
		//int maxValue = array[0];
		for(int item : array){
			if(item > maxValue){
				maxValue = item;
			}
		}
	    return maxValue;
	}
	
	public static int indexOf(int[] array, int key){
		//便利整个数组,array.length表示长度，求下标
		for(int i = 0; i < array.length; i++){
			if(array[i] == key){
				return i;
			}
		}
        return -1;		
	}
	
	//去掉一个最高分，去掉一个最低分后的平均分
	public static double average(int[] scores){
		int minValue = scores[0];
		int maxValue = scores[0];
		int sum = scores[0];
		
		for(int i = 1; i < scores.length; i++){
			if(scores[i] < minValue){
				minValue = scores[i];
			}
			
			if(scores[i] > maxValue){
				maxValue = scores[i];
			}
			sum += scores[i];//sum = sum + scores[i];
		}
		return(double)(sum - minValue - maxValue)/(scores.length - 2);
    }
	
	public static int[] copyOf(int[] src,int newLength){
		//newLength可能大于 src.length;
		//newLength可能小于等于 src.length;
		int[] dest = new int[newLength];
		//利用默认值的值,每一个元素都是0
		int minLength = src.length < newLength ? src.length : newLength;
	
		for(int i = 0; i < minLength; i++){
			dest[i] = src[i];
		}
		return dest;
	}
	
	public static void main(String[] args){
		//初始化一个数组出来
		int[] array = new int[]{1, 2, 3, 4, 5, 6, 7};
		
		int maxValue = max(array);
		System.out.println("最大值是" + maxValue);
		
		int index = indexOf(array,19);
		System.out.println("19的下标是" + index);
		
		double averageScore = average(array);
		System.out.printf("平均分是 %.4f%n", averageScore);
		
        //int dest = new int[newLength];
        //System.out.println("");		
	}
}