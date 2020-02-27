import java.util.LinkedList;
import java.util.Queue;

public class isBalanced {
    public static int Height(TreeNode root){
        if (root == null){
            return 0;
        }
        int left = Height(root.left);
        int right = Height(root.right);
        int height = Math.max(left, right) + 1;
        return height;
    }

    //平衡二叉树
    public static boolean isBalanced(TreeNode root){
        if (root == null){
            return true;
        }
        boolean leftBalande = isBalanced(root.left);
        if (!leftBalande){
            return false;
        }
        boolean rightBalance = isBalanced(root.right);
        if (!rightBalance){
            return false;
        }
        int leftHeight = Height(root.left);
        int rightHeight = Height(root.right);
        int diff = leftHeight - rightHeight;//高度差
        if (diff > 1 || diff < -1){
            return false;
        }
        return true;
    }
    //查找结点是否在树中
    public static boolean search(TreeNode root, TreeNode n){
        if (root == null){
            return false;
        }
        if (root == n){
            return true;
        }
        if(search(root.left, n)){
            return true;
        }
        return search(root.right, n);
    }
    //查找最近的公共祖先
    public TreeNode lowestCommonAncester(TreeNode root, TreeNode p, TreeNode q){
        if (root == p || root == q){
            return root;
        }
        boolean pInLeft = search(root.left, p);
        boolean qInLeft = search(root.left, q);
        if (pInLeft && qInLeft){
            return lowestCommonAncester(root.left, p, q);
        }
        if (!pInLeft && !qInLeft) {
            return lowestCommonAncester(root.right, p, q);
        }
        return root;
    }
}
