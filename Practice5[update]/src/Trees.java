import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

//递归求二叉树前序/中序/后序遍历
class Node{
    char value;
    Node right = null;
    Node left = null;
    Node(char value){
        this.value = value;
    }
}
public class Trees {
    private static Node buildTree(){
        Node A = new Node('A');
        Node B = new Node('B');
        Node C = new Node('C');
        Node D = new Node('D');
        Node E = new Node('E');
        Node F = new Node('F');
        Node G = new Node('G');
        Node H = new Node('H');
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

    public static List<Character> preOrder(Node root){
        if (root == null){
            return new ArrayList<>();
        }
        List<Character> list = new ArrayList<>();
        List<Character> leftPreOrder = preOrder(root.left);
        List<Character> rightPreOrder = preOrder(root.right);
        list.add(root.value);
        list.addAll(leftPreOrder);
        list.addAll(rightPreOrder);
        return list;
    }

    public static void preOrderTraversal(Node root){
        if (root == null){
            return;
        }
        //根 + 左子树 + 右子树
        System.out.println(root.value);
        preOrderTraversal(root.left);
        preOrderTraversal(root.right);
    }
    public static void inOrderTraversal(Node root){
        if (root == null){
            return;
        }
        //左子树 + 根 + 右子树
        inOrderTraversal(root.left);
        System.out.println(root.value);
        inOrderTraversal(root.right);
    }
    public static void postOrderTraversal(Node root){
        if (root == null){
            return;
        }
        //左子树 + 右子树 + 根
        postOrderTraversal(root.left);
        postOrderTraversal(root.right);
        System.out.println(root.value);
    }

    //计算二叉树中的结点个数
    public static int count = 0;
    //方法一：
    public static void calcCount1(Node root){
        if (root == null){
            return;
        }
        count++;
        calcCount1(root.left);
        calcCount1(root.right);
    }
    //方法二：
    public static int calcCount2(Node root){
        if (root == null){
            return 0;
        }
        int left = calcCount2(root.left);
        int right = calcCount2(root.right);
        int count = left + right + 1;
        return count;
    }

    //遍历方法求叶子结点
    public static int leafCount = 0;
    public static int calcLeafCount1(Node root){
        if (root == null){
            return count;
        }
        calcLeafCount1(root.left);
        //代表是叶子结点
        if (root.left == null && root.right == null){
            leafCount++;
        }
        calcLeafCount1(root.right);
        return count;
    }

    //汇总方法求叶子结点
    public static int calcLeafCount2(Node root){
        if (root == null){
            return 0;
        }
        //代表只有一个结点的树
        if (root.left == null && root.right == null){
            return 1;
        }
        int left = calcLeafCount2(root.left);
        int right = calcLeafCount2(root.right);
        return left + right;
    }

    //计算二叉树的高度
    public static int calcHeight(Node root){
        if (root == null){
            return 0;
        }
        int left = calcHeight(root.left);
        int right = calcHeight(root.right);
        int height = Math.max(left, right) + 1;
        return height;
    }

    //计算二叉树第k 层的结点个数
    public static int calcKLevel(Node root, int k){
        if (root == null){
            return 0;
        }
        if (k == 1){
            return 1;
        }
        int left = calcKLevel(root.left, k - 1);
        int right = calcKLevel(root.right, k - 1);
        int count = left + right;
        return count;
    }
    //查找
    //方法一：
    public static Node search(Node root, char val){
        if (root == null){
            return null;
        }
        if (root.value == val){
            return root;
        }
        //去左子树查找
        Node left = search(root.left, val);
        if (left != null){
            return left;
        }
        Node right = search(root.right, val);
        if (right != null) {
            return right;
        }
        return null;
    }
    //方法二：
    public static boolean search1(Node root,char val){
        if (root == null){
            return false;
        }
        if (root.value == val){
            return true;
        }
        if(search1(root.left, val)){
            return true;
        }
        return search1(root.right, val);
    }

    //判断两个树是否为镜像树
    public static boolean isMirror(Node p, Node q) {
        if (p == null && q == null) {
            return true;
        }
        if (p == null || q == null) {
            return false;
        }
        return p.value == q.value
                && isMirror(p.left, q.right)
                && isMirror(p.right, q.left);
    }

    //判断两个树是否相同
    public static boolean isSameTree(Node p, Node q) {
        if (p == null || q == null) {
            if (p == null && q == null) {
                return true;
            }
            return false;
        }
        return p.value == q.value
                && isSameTree(p.left, q.left)
                && isSameTree(p.right, q.right);
    }s
    //判断是否为另一个树的子树（相同或包含，相同已写，在此判断包含）
    public static boolean isSubTree(Node p, Node q){
        if (p == null){
            return false;
        }
        return isSameTree(p, q)|| isSubTree(p.left, q)|| isSubTree(p.right, q);
    }

    //二叉树的还原
    //方法一：前序 + 中序
    public static Node buildTree1(List<Character> preorder, List<Character> inorder){
        if (preorder.size() == 0){
            return null;
        }
        char rootValue = preorder.get(0);
        int leftCount = inorder.indexOf(rootValue);
        Node root = new Node(rootValue);
        List<Character> leftPreorder = preorder.subList(1, 1 + leftCount);
        List<Character> leftInorder = inorder.subList(0, leftCount);
        Node left = buildTree1(leftPreorder, leftInorder);
        root.left = left;
        List<Character> rightPreorder = preorder.subList(1 + leftCount, preorder.size());
        List<Character> rightInorder = inorder.subList(leftCount + 1, inorder.size());
        Node right = buildTree1(rightPreorder, rightInorder);
        root.right = right;
        return root;
    }
    //方法二：中序 + 后序
    /*public static Node buildTree2(List<Character> inorder, List<Character> postorder){

    }*/


    public static void main(String[] args) {
        Node root = buildTree();
        preOrderTraversal(root);
        System.out.println("===================");
        inOrderTraversal(root);
        System.out.println("===================");
        postOrderTraversal(root);
        List<Character> preorder = Arrays.asList('A','B','D','E','G','C','F','H');
        List<Character> inorder = Arrays.asList('D','B','G','E','A','C','F','H');
        Node root1 = buildTree1(preorder, inorder);
        System.out.println("成功");
    }
}

