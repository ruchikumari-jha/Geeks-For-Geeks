class Solution {
public:
    Node* reverse(Node* head) {
        if (!head || !head->next) return head;
        
        Node* curr = head;
        Node* temp = nullptr;
        
        while (curr) {
            // Swap prev and next pointers
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            
            // Move to next node (original next is now in prev)
            curr = curr->prev;
        }
        
        // After loop, temp holds the second last node's original prev
        // Actually, temp is the new head (last node of original list)
        if (temp) {
            head = temp->prev;
        }
        return head;
    }
};