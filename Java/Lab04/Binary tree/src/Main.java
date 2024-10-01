class BST<T extends Comparable<T>> {
    private class Node {
        private T key;
        private Node left, right;

        Node(T key) {
            this.key = key;
            left = right = null;
        }

        public Node getLeft() {
            return left;
        }

        public Node getRight() {
            return right;
        }

        public void setLeft(Node left) {
            this.left = left;
        }

        public void setRight(Node right) {
            this.right = right;
        }

        public T getKey() {
            return key;
        }

        public void setKey(T key) {
            this.key = key;
        }
    }
    private Node root;

    BST() {
        root = null;
    }

    public void insert(T key) {
        root = insertRec(root, key);
    }

    private Node insertRec(Node root, T key) {
        if (root == null) {
            root = new Node(key);
            return root;
        }
        if (key.compareTo(root.getKey()) < 0) {
            root.setLeft(insertRec(root.getLeft(), key));
        } else if (key.compareTo(root.getKey()) > 0) {
            root.setRight(insertRec(root.getRight(), key));
        }
        return root;
    }

    public void delete(T key) {
        root = deleteRec(root, key);
    }

    private Node deleteRec(Node root, T key) {
        if (root == null) {
            return root;
        }
        if (key.compareTo(root.getKey()) < 0) {
            root.setLeft(deleteRec(root.getLeft(), key));
        } else if (key.compareTo(root.getKey()) > 0) {
            root.setRight(deleteRec(root.getRight(), key));
        } else {
            if (root.getLeft() == null) {
                return root.getRight();
            } else if (root.getRight() == null) {
                return root.getLeft();
            }
            root.setKey(minValue(root.getRight()));
            root.setRight(deleteRec(root.getRight(), root.getKey()));
        }
        return root;
    }

    private T minValue(Node root) {
        while (root.getLeft() != null) {
            root = root.getLeft();
        }
        return root.getKey();
    }

    public void preOrderTraversal() {
        preOrderTraversal(root);
    }

    private void preOrderTraversal(Node node) {
        if (node == null) {
            return;
        }
        System.out.print(node.getKey().toString() + " ");
        preOrderTraversal(node.getLeft());
        preOrderTraversal(node.getRight());
    }

    public void postOrderTraversal() {
        postOrderTraversal(root);
    }

    private void postOrderTraversal(Node node) {
        if (node == null) {
            return;
        }
        postOrderTraversal(node.getLeft());
        postOrderTraversal(node.getRight());
        System.out.print(node.getKey().toString() + " ");
    }

    public void inOrderTraversal() {
        inOrderTraversal(root);
    }

    private void inOrderTraversal(Node node) {
        if (node == null) {
            return;
        }
        inOrderTraversal(node.getLeft());
        System.out.print(node.getKey().toString() + " ");
        inOrderTraversal(node.getRight());
    }


}

public class Main{
    public static void main(String[] args) {
        BST<Integer> bst = new BST<Integer>();
        bst.insert(2);
        bst.insert(5);
        bst.insert(4);
        bst.insert(1);
        bst.insert(3);

        bst.preOrderTraversal();
    }
}
