import java.util.Arrays;
import java.util.Random;

public class Sorts {
    //插入排序
    public static void insertSort1(int[] array){
        for (int i = 0; i < array.length - 1; i++){
            // 有序区间   [0， i]
            // 无序区间  [i + 1, array.length)
            // 待插入的数据是 array[i + 1]
            // 插入过程在有序区间内查找

            int key = array[i + 1];
            int j;
            for (j = i; j >= 0; j--){
                if (key >= array[j]){
                    break;
                }
            }
            //j + 1 放 key 的位置
            for (int k = i; k > j; k--){
                array[k + 1] = array[k];
            }
            array[j + 1] = key;
        }
    }
    public static void insertSort2(int[] array){
        for (int i = 0; i < array.length - 1; i++){
            int key = array[i + 1];
            int j;
            for (j = i; j >= 0 && key < array[j]; j--){
                array[j + 1] = array[j];
            }
            array[j + 1] = key;
        }
    }
    //希尔排序
    private static void insertSortWithGap(int[] array, int gap){
        for (int i = 0; i < array.length - gap; i++){
            int key = array[i + gap];
            int j;
            for (j = i; j >= 0 && key < array[j]; j -= gap){
                array[j + gap] = array[j];
            }
            array[j + gap] = key;
        }
    }
    public static void shellSort(int[] array){
        int gap = array.length;
        while (true){
            gap = gap / 3 + 1;
            insertSortWithGap(array, gap);
            if (gap == 1){
                return;
            }
        }
    }

    private static  int[] buildSortedArray(int n){
        int[] array = new int[n];
        for (int i = 0; i < n; i++){
            array[i] = i;
        }
        return array;
    }

    private static int[] buildReversedSortedArray(int n){
        int[] array = new int[n];
        for (int i = 0; i < n; i++){
            array[i] = n - i;
        }
        return array;
    }

    private static int[] buildRandomArray(int n){
        Random random = new Random(20190828);
        int[] array = new int[n];
        for (int i = 0; i < n; i++){
            array[i] = random.nextInt(n);
        }
        return array;
    }

    private static int[] buildEqualsArray(int n){
        int[] array = new int[n];
        for (int i = 0; i < n; i++){
            array[i] = n;
        }
        return array;
    }

    public static void selectSort(int[] array){
        //每次选最大的数
        for (int i = 0; i < array.length - 1; i++){
            //无序区间[0, array.length - i)
            //有序区间[array.length - i, array.length)
            int max = 0;
            for (int j = 1; j < array.length - i; j++){
                if (array[j] >= array[max]){
                    max = j;
                }
            }
            //交换最大的数和无序区间的最后一个数
            swap(array, max, array.length - i - 1);
        }
    }

    public static void selectSortVersion2(int[] array){
        int low = 0;
        int high = array.length - 1;
        //无序区间是[low, high]
        //无序区间的长度 <= 1
        while (low < high){
            int min = low;
            int max = low;

            for (int i = low + 1; i <= high; i++){
                if (array[i] > array[max]){
                    max = i;
                }
                if (array[i] < array[min]){
                    min = i;
                }
                swap(array, min, low);
                if (max == low){
                    max = min;
                }
                swap(array, max, high);

                low++;
                high--;
            }
        }
    }

    private static void swap(int[] array, int i, int j){
        int t = array[i];
        array[i] = array[j];
        array[j] = t;
    }

    public static void heapSort(int[] array){
        createHeap(array, array.length);
        for (int i = 0; i < array.length - 1; i++){
            //无序 [0, array.length - i)
            swap(array, 0 ,array.length - i - 1);
            //无序 [0, array.length - i - 1)
            //无序区间的长度： array.length - i - 1
            heapify(array, array.length - i - 1, 0);
        }
    }

    public static void createHeap(int[] array, int length) {
        for (int i = (length - 2) / 2; i >= 0; i--) {
            heapify(array, length, i);
        }
    }

    //直接选择排序
    public static void heapify(int[] array, int length, int index) {
        int left = 2 * index + 1;
        while (left < length) {
            int max = left;
            if (left + 1 < length && array[left + 1] > array[left]) {
                max = left + 1;
            }
            if (array[index] >= array[max]) {
                break;
            }
            swap(array, index, max);
            index = max;
            left = 2 * index + 1;
        }
    }

    //冒泡排序
    public static void bubbleSort(int[] array){
        for (int i = 0; i < array.length - 1; i++){
            //无序区间是[0, array.length - i)
            boolean sorted = true;
            for (int j = 0; j < array.length - i - 1; j++){
                if (array[j] > array[j + 1]){
                    swap(array, j, j + 1);
                    sorted = false;
                }
            }
            if (sorted){
                break;
            }
        }
    }

    /*//退化版的选择排序
    public static void sort(int[] array){
        for (int i = 0; i < array.length - 1; i++){
            for (int j = 0; j < array.length - i; j++){
                if (array[j] > array[array.length - i -1]){
                    swap(array, j, array.length - i - 1);
                }
            }
        }
    }*/

    //快速排序
    public static void quickSort(int[] array){
        quickSortInternal(array, 0, array.length - 1);
    }
    //[left, right]
    public static void quickSortInternal(int[] array, int left, int right){
        if (left >= right){
            return;
        }
        //1、确定基准值：array[right] 作为基准值
        //2、遍历，小的左，大的右
        //int pivotIndex = partition1(array, left, right);
        //int pivotIndex = partition2(array, left, right);
        //int pivotIndex = partition3(array, left, right);
        int[] indices = partition4(array, left ,right);
        //分出的两个小区间
        //[left, pivotIndex - 1]
        //[pivotIndex + 1, right]
        //3、治
        //quickSortInternal(array, left, pivotIndex - 1);
        //quickSortInternal(array, pivotIndex + 1, right);
        quickSortInternal(array, left, indices[0] - 1);
        quickSortInternal(array, indices[1] + 1, right);
    }

    //方式一Hover
    private static int partition1(int[] array, int left, int right){
        int pivot = array[right];
        int less = left;
        int great = right;
        while (less < great){
            while (less < great && array[less] <= pivot){
                less++;
            }
            while (less < great && array[great] >= pivot){
                great--;
            }
            swap(array, less, great);
        }
        swap(array, right, less);
        return less;
    }

    //方式二：挖坑法(效率较高)
    private static int partition2(int[] array, int left, int right){
        int pivot = array[right];
        int less = left;
        int great = right;
        while (less < great){
            while (less < great && array[less] <= pivot){
                less++;
            }
            array[great] = array[less];
            while (less < great && array[great] >= pivot){
                great--;
            }
            array[less] = array[great];
        }
        array[less] = pivot;
        return less;
    }

    //方式三：前后下标
    public static int partition3(int[] array, int left, int right){
        int pivot = array[right];
        int less = left;  //蓝色的箭头
        // 准则：
        //[left, less) < pivot
        //[less, i)  >= pivot
        //[i, right)  ?
        for (int i = left; i < right; i++){ //红色的箭头
            if (array[i] < pivot){
                swap(array, less, i);
                less++;
            }
        }
        swap(array, less, right);
        return less;
    }

    //方式四：把和基准相等的情况单独处理
    public static int[] partition4(int[] array, int left, int right){
        int pivot = array[right];
        int less = left;
        int great = right;
        int i = left;
        while(i < great){
            if (array[i] == pivot){
                i++;
            }else if (array[i] < pivot){
                swap(array, i, less);
                i++;
                less++;
            }else{
                while (i < great && array[great] > pivot){
                    great--;
                }
                swap(array, i, great);
            }
        }
        return new int[]{less, great - 1};
    }

    public static void main(String[] args) {
        //测试有序/ 无序/ 随机值 / 完全相等的
        int[] array;

        //array = buildReversedSortedArray(1000000);
        //array = buildSortedArray(1000000);
        //array = buildRandomArray(10);
        array = buildRandomArray(50);
        //array = buildEqualsArray(10);
        System.out.println(Arrays.toString(array));
        long begin = System.nanoTime();  //纳秒
        //insertSort1(array);
        //System.out.println(Arrays.toString(array));
        //insertSort1(array);
        //shellSort(array);
        //selectSort(array);
        //selectSortVersion2(array);
        //heapSort(array);
        quickSort(array);
        long end = System.nanoTime();    //纳秒
        System.out.println(end - begin);
        System.out.println(Arrays.toString(array));
    }
}

