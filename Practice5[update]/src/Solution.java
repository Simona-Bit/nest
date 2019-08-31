//二叉树的前序遍历
import sun.reflect.generics.tree.Tree;

import java.util.ArrayList;
import java.util.List;
class TreeNode{
    char val;
    TreeNode left = null;
    TreeNode right = null;
    TreeNode(char val){
        this.val = val;
    }
}
public class Solution {
    private static TreeNode buildTrees(){
        TreeNode A = new TreeNode('A');
        TreeNode B = new TreeNode('B');
        TreeNode C = new TreeNode('C');
        TreeNode D = new TreeNode('D');
        TreeNode E = new TreeNode('E');
        TreeNode F = new TreeNode('F');
        TreeNode G = new TreeNode('G');
        TreeNode H = new TreeNode('H');
        A.left = B; B.left = D;
        B.right = E; E.right = H;
        A.right = C; C.left = F;
        C.right = G; D.right = null;
        D.left = null; E.left = null;
        H.left = null; H.right = null;
        F.right = null;F.left = null;
        G.left = null;G.right = null;
        return A;
    }
    public static List<Character> preorderTraversal(TreeNode root) { //创建了好多list 有好多ArrayList 对象，最后进行合并返回一个ArrayList
        if (root == null) {
            return new ArrayList<>();
        }
        List<Character> list = new ArrayList<>();
        List<Character> leftpreOrder = preorderTraversal(root.left);
        List<Character> rightpreOrder = preorderTraversal(root.right);
        list.add(root.val);
        list.addAll(leftpreOrder);
        list.addAll(rightpreOrder);
        return list;
    }
    public  static List<Character> inorderTraversal(TreeNode root){
        if (root == null){
            return new ArrayList<>();
        }
        List<Character> leftinOrder = inorderTraversal(root.left);
        List<Character> list = new ArrayList<>();
        List<Character> rightinOrder = inorderTraversal(root.right);
        list.addAll(leftinOrder);
        list.add(root.val);
        list.addAll(rightinOrder);
        return list;
    }
    public  static List<Character> postorderTraversal(TreeNode root){
        if (root == null){
            return new ArrayList<>();
        }
        List<Character> leftpostOrder = postorderTraversal(root.left);
        List<Character> rightpostOrder = postorderTraversal(root.right);
        List<Character> list = new ArrayList<>();
        list.addAll(leftpostOrder);
        list.addAll(rightpostOrder);
        list.add(root.val);
        return list;
    }

    public static void main(String[] args) {
        TreeNode root = buildTrees();
        System.out.println(preorderTraversal(root));
        System.out.println(inorderTraversal(root));
        System.out.println(postorderTraversal(root));
    }

}
