package Tree;

import sun.reflect.generics.tree.Tree;

import javax.xml.bind.Element;
import java.util.*;

class TreeNode {
    int val;
    TreeNode left = null;
    TreeNode right = null;
    TreeNode(int val){
        this.val = val;
    }
}
public class Solution{
    //层序遍历
    public static void levelOrder1(TreeNode root){
        if (root == null){
            return;
        }
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);

        while(!queue.isEmpty()){
            TreeNode front = queue.poll();
            System.out.println(front.val);
            if (front.left != null){
                queue.add(front.left);
            }
            if (front.right != null){
                queue.add(front.right);
            }
        }
    }

    private static class Element{ //自行创建
        TreeNode node;
        int level;
        /*Element(TreeNode node, int level){
            this.level = level;
            this.node = node;
        }*/
    }
    //层序遍历（线性表）
    //输出{{A},{B,C},{D}}
    public static List<List<Integer>> levelOrder(TreeNode root){
        List<List<Integer>> retList = new ArrayList<>();
        if (root == null){
            return retList;
        }
        Queue<Element> queue = new LinkedList<>();
        Element e = new Element();
        e.node = root;
        e.level = 0;        //Element e = new Element(root, 0);
        queue.add(e);
        while (!queue.isEmpty()){
            Element front = queue.poll();
            //如果层数等于线性表的大小，则需要线性表中再加一个线性表，在线性表以层数为下标添加元素
            if(front.level == retList.size()){  //长度和level相等
                retList.add(new ArrayList<>());
            }
            retList.get(front.level).add(front.node.val);

            if (front.node.left != null){
                Element l = new Element();
                l.node = front.node.left;
                l.level = front.level + 1;
                queue.add(l);       //queue.add(new Element(front.node.left, front.level + 1));
            }
            if (front.node.right != null){
                Element r = new Element();
                r.node = front.node.right;
                r.level = front.level + 1;
                queue.add(r);      //queue.add(new Element(front.node.right, front.level + 1));
            }
        }
        return retList;
    }

    //判断是否是完全二叉树
    public static boolean isCompleteTree(TreeNode root){
        //层序遍历，直到遇到 null
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);

        while (true){
            TreeNode front = queue.poll();
            if (front == null){
                break;
            }
            queue.add(front.left);
            queue.add(front.right);
        }

        //判断队列中剩余元素是否都是 null
        while (!queue.isEmpty()){
            TreeNode node = queue.poll();  //poll弹出
            if (node != null){
                return false;
            }
        }
        return true;
    }

    //非递归前序
    public static void preorderNoR(TreeNode root){
        Stack<TreeNode> stack = new Stack<>();
        TreeNode cur = root;

        while (!stack.empty() || cur != null){
            while (cur != null){
                System.out.println(cur.val);
                stack.push(cur);
                cur = cur.left;
            }
            TreeNode top = stack.pop();
            cur = top.right;
        }
    }
    //非递归中序
    public static void inorderNoR(TreeNode root){
        Stack<TreeNode> stack = new Stack<>();
        TreeNode cur = root;

        while (!stack.empty() || cur != null){
            while (cur != null){
                stack.push(cur);
                cur = cur.left;
            }
            TreeNode top = stack.pop();
            System.out.println(top.val);
            cur = top.right;
        }
    }
    //非递归后序
    public static void postorderNoR(TreeNode root){
        Stack<TreeNode> stack = new Stack<>();
        TreeNode cur = root;
        TreeNode last = null;  //上一次被三次完整经过的结点

        while (!stack.empty() || cur != null){
            while (cur != null){
                stack.push(cur);
                cur = cur.left;
            }
            TreeNode top = stack.peek();  //peek取栈顶元素
            if (top.right == null || top.right == last) {
                stack.pop();  //pop出栈并删除
                System.out.println(top.val);
                last = top;
            }else {
                cur = top.right;
            }
        }
    }

    public static void main(String[] args) {
        TreeNode n1 = new TreeNode(1);
        n1.left = new TreeNode(2);
        n1.right = new TreeNode(3);
        n1.left.left = new TreeNode(4);
        preorderNoR(n1);
        System.out.println("==========");
        inorderNoR(n1);
        System.out.println("==========");
        postorderNoR(n1);
        System.out.println("==========");
        isCompleteTree(n1);
        System.out.println("==========");
        levelOrder1(n1);
        System.out.println("==========");
        List<List<Integer>> list = levelOrder(n1);
        System.out.println(list);
    }
}
