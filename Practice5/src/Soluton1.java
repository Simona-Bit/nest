import java.util.ArrayList;
import java.util.List;

class Node1{
    int val;
    Node1 left;
    Node1 right;
}
public class Soluton1 {
    private List<Integer> list;

    private void preOrder(Node1 root){
        if (root == null){
            return;
        }
        list.add(root.val);
        preOrder(root.left);
        preOrder(root.right);
    }

    public List<Integer> preorderTraversal(Node1 root){
        list = new ArrayList<>();
        preOrder(root);
        return list;
    }
}
