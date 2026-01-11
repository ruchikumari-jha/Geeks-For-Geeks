/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
public:
    // Function to delete a node without head pointer
    void deleteNode(Node* del_node) {
        // If node is NULL or last node, return
        if (del_node == NULL || del_node->next == NULL) {
            return;
        }
        
        // Copy data from next node to current node
        del_node->data = del_node->next->data;
        
        // Store the next node to delete
        Node* temp = del_node->next;
        
        // Point current node to next of next node
        del_node->next = del_node->next->next;
        
        // Delete the next node
        delete temp;
    }
};