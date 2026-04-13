//made binary tree in java

class TreeNode {
    int value;
    TreeNode leftChild, rightChild;

    public TreeNode(int value) {
        this.value = value;
        this.leftChild = null;
        this.rightChild = null;
    }
}

class CompleteBinaryTree {
    private TreeNode rootNode;

    public CompleteBinaryTree() {
        this.rootNode = null;
    }

    // Insert a node into the complete binary tree
    public void insert(int value) {
        TreeNode newNode = new TreeNode(value);
        if (rootNode == null) {
            rootNode = newNode;
            return;
        }

        // Perform level-order traversal to find the correct position
        java.util.Queue<TreeNode> nodeQueue = new java.util.LinkedList<>();
        nodeQueue.add(rootNode);

        while (!nodeQueue.isEmpty()) {
            TreeNode currentNode = nodeQueue.poll();

            if (currentNode.leftChild == null) {
                currentNode.leftChild = newNode;
                break;
            } else {
                nodeQueue.add(currentNode.leftChild);
            }

            if (currentNode.rightChild == null) {
                currentNode.rightChild = newNode;
                break;
            } else {
                nodeQueue.add(currentNode.rightChild);
            }
        }
    }

    // Perform level-order traversal to display the tree
    public void levelOrderTraversal() {
        if (rootNode == null) {
            System.out.println("Tree is empty.");
            return;
        }

        java.util.Queue<TreeNode> nodeQueue = new java.util.LinkedList<>();
        nodeQueue.add(rootNode);

        while (!nodeQueue.isEmpty()) {
            TreeNode currentNode = nodeQueue.poll();
            System.out.print(currentNode.value + " ");

            if (currentNode.leftChild != null) {
                nodeQueue.add(currentNode.leftChild);
            }

            if (currentNode.rightChild != null) {
                nodeQueue.add(currentNode.rightChild);
            }
        }
        System.out.println();
    }

    public static void main(String[] args) {
        CompleteBinaryTree tree = new CompleteBinaryTree();

        tree.insert(1);
        tree.insert(2);
        tree.insert(3);
        tree.insert(4);
        tree.insert(5);
        tree.insert(6);

        System.out.println("Level-order traversal of the complete binary tree:");
        tree.levelOrderTraversal();
    }
}