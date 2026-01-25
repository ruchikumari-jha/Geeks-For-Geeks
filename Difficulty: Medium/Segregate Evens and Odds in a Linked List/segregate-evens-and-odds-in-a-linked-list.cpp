class Solution {
public:
    Node* divide(Node* head) {
        if (!head || !head->next) return head;
        
        Node* evenStart = NULL;
        Node* evenEnd = NULL;
        Node* oddStart = NULL;
        Node* oddEnd = NULL;
        Node* current = head;
        
        while (current != NULL) {
            int value = current->data;
            
            // If even
            if (value % 2 == 0) {
                if (evenStart == NULL) {
                    evenStart = current;
                    evenEnd = evenStart;
                } else {
                    evenEnd->next = current;
                    evenEnd = evenEnd->next;
                }
            }
            // If odd
            else {
                if (oddStart == NULL) {
                    oddStart = current;
                    oddEnd = oddStart;
                } else {
                    oddEnd->next = current;
                    oddEnd = oddEnd->next;
                }
            }
            current = current->next;
        }
        
        // Connect even list to odd list
        if (evenStart == NULL) {
            return oddStart;
        }
        
        evenEnd->next = oddStart;
        
        // Make sure the last node's next is NULL
        if (oddEnd != NULL) {
            oddEnd->next = NULL;
        }
        
        return evenStart;
    }
};