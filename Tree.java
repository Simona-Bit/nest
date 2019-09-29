import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Stack;

class Node {
    int val;
    Node left;
    Node right;
}
public class Tree {
    public static void postOrder(Node root) {
        Stack<Node> stack = new Stack<>();
        Node cur = root;
        Node last = null;   // 上一个被打印的结点

        while (cur != null || !stack.isEmpty()) {
            while (cur != null) {
                cur = cur.left;
                stack.push(cur);
            }
            Node top = stack.peek();
            if (top.right == null || top.right == last) {
                System.out.println(top.val);
                stack.pop();
                last = top;
            } else {
                cur = top.right;
            }
        }
    }

    public static List<List<Integer>> levelOrder2(Node root) {
        return null;
    }
    public static void levelOrder(Node root) {
        if (root == null) {return;}
        Queue<Node> queue = new LinkedList<>();
        queue.offer(root);
        while (!queue.isEmpty()) {
            Node front = queue.poll();
            System.out.println(front.val);
            if (front.left != null) {
                queue.offer(front.left);
            }
            if (front.right != null) {
                queue.offer(front.right);
            }
        }
    }

    public static boolean isSameTree(Node p, Node q) {
        if (p == null && q == null) {
            return true;
        }
        if (p == null || q == null) {
            return false;
        }

        return p.val == q.val && isSameTree(p.left, q.left)
                && isSameTree(p.right, q.right);
    }
}
