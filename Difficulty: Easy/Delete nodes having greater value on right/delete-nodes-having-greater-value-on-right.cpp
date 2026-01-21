class Solution {
public:
    Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    Node* compute(Node* head) {
        if (!head || !head->next) return head;
        
        // Step 1: Reverse
        head = reverse(head);
        
        // Step 2: Delete nodes having smaller value than max so far
        Node* curr = head;
        Node* maxNode = head;
        Node* prev = nullptr;
        
        while (curr) {
            if (curr->data < maxNode->data) {
                // Delete curr
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            } else {
                maxNode = curr;
                prev = curr;
                curr = curr->next;
            }
        }
        
        // Step 3: Reverse again
        head = reverse(head);
        return head;
    }
};