class Solution {
public:
    Node* removeDuplicates(Node* head) {
        if (!head || !head->next) return head;
        
        Node* dummy = new Node(0);
        dummy->next = head;
        unordered_set<int> seen;
        Node* curr = dummy;
        
        while (curr->next) {
            if (seen.find(curr->next->data) != seen.end()) {
                // Skip duplicate
                curr->next = curr->next->next;
            } else {
                seen.insert(curr->next->data);
                curr = curr->next;
            }
        }
        
        return dummy->next;
    }
};