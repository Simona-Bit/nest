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
        A.left = B; B.left = D; B.right = E; E.right = H;
        A.right = C; C.left = F; C.right = G; D.right = null;
        D.left = null; E.left = null; H.left = null; H.right = null;
        F.right = null;F.left = null;G.left = null;G.right = null;
        return A;
    }
    public static void preOrderTraversal(Node root){
        if (root == null){
            return;
        }
        System.out.println(root.value);
        preOrderTraversal(root.left);
        preOrderTraversal(root.right);
    }
    public static void inOrderTraversal(Node root){
        if (root == null){
            return;
        }
        inOrderTraversal(root.left);
        System.out.println(root.value);
        inOrderTraversal(root.right);
    }
    public static void postOrderTraversal(Node root){
        if (root == null){
            return;
        }
        postOrderTraversal(root.left);
        postOrderTraversal(root.right);
        System.out.println(root.value);
    }

    public static void main(String[] args) {
        Node root = buildTree();
        preOrderTraversal(root);
        System.out.println("===================");
        inOrderTraversal(root);
        System.out.println("===================");
        postOrderTraversal(root);
    }
}

