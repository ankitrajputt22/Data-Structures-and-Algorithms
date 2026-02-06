// Definition for a binary tree node
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    
    // Constructors
    TreeNode() {}
    TreeNode(int val) { 
        this.val = val; 
    }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

public class L3 {
    public static void main(String[] args) {
        // Create a simple binary tree
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);
        
        // Tree structure:
        //     1
        //    / \
        //   2   3
        //  / \
        // 4   5
        
        System.out.println("Root value: " + root.val);
        System.out.println("Left child value: " + root.left.val);
        System.out.println("Right child value: " + root.right.val);
        System.out.println("Left grandchild values: " + root.left.left.val + " and " + root.left.right.val);
        
        // Demonstrate tree traversal
        System.out.print("Inorder traversal: ");
        inorder(root);
    }
    
    // Inorder traversal method
    public static void inorder(TreeNode node) {
        if (node == null) return;
        inorder(node.left);
        System.out.print(node.val + " ");
        inorder(node.right);
    }
}