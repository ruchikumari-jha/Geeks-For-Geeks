class Solution {
public:
    bool removeLoop(Node* head) {
        if (!head || !head->next) return false;

        Node *slow = head, *fast = head;

        // Step 1: Detect loop
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                break; // Loop detected
            }
        }

        // No loop
        if (slow != fast) return false;

        // Step 2: Find the start of the loop
        slow = head;
        // Special case: if loop starts at head (pos = 0)
        if (slow == fast) {
            // Move fast to the last node
            while (fast->next != slow) {
                fast = fast->next;
            }
        } else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        // Step 3: Remove the loop
        fast->next = nullptr;
        return true;
    }
};