import java.util.Arrays;
public class LargestPerimeter1 {
    public int largestPerimeter(int[] A) {
        int len = A.length;
        Arrays.sort(A);
        for(int i = len - 3;i >= 0;i--)
            if(A[i] + A[i+1] > A[i+2])                  //两条小边加起来大于最大边，则能构成三角形
                return A[i] + A[i+1] + A[i+2];
        return 0;
    }
}
