import java.util.Scanner;
class Node{
    char val;
    Node left;
    Node right;
}
class ReturnValue{
    Node root;   //构建出树的根结点
    int used;   //构建过程中用掉的值的个数
}

public class Main {
    private static ReturnValue buildTree(char[] preorder){
        return null;
    }

    private static void inorderTravesal(Node root){
        if (root == null){
            return;
        }
        inorderTravesal(root.left);
        System.out.println(root.val + "");
        inorderTravesal(root.right);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String preorderLine = scanner.nextLine();
        char[] preOrder = preorderLine.toCharArray();
        ReturnValue rv = buildTree(preOrder);
        inorderTravesal(rv.root);
    }
}