public class linkedlist {
    Node head; // head of the list

    // Node class
    static class Node {
        int data;
        Node next;

        // Constructor for making the linked list
        Node(int d) {
            data = d;
            next = null;
        }
    }

    // Function to insert a new node at the end
    public void insertNode(int data) {
        // Create a new node with the given data
        Node newNode = new Node(data);
        // If the linked list is empty, then make the new node as head
        if (head == null) {
            head = newNode;
        // Else traverse till the last node and insert the new node there
        } else {
            Node last = head;
            while (last.next != null) {
                last = last.next;
            }
            last.next = newNode;
        }
    }

    // Function to display the linked list
    public void displayList() {
        Node currentNode = head;
        while (currentNode != null) {
            System.out.print(currentNode.data + " ");
            currentNode = currentNode.next;
        }
        System.out.println();
    }

    // Main method to test the functions
    public static void main(String[] args) {
        linkedlist list = new linkedlist();

        list.insertNode(1);
        list.insertNode(2);
        list.insertNode(3);
        list.insertNode(4);

        list.displayList(); // Output: 1 2 3 4
    }
}