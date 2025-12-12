class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return -1;

        // Step 1: Find candidate for majority element
        int candidate = arr[0], count = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] == candidate) {
                count++;
            } else {
                count--;
            }
            if (count == 0) {
                candidate = arr[i];
                count = 1;
            }
        }

        // Step 2: Verify if candidate is actually majority
        count = 0;
        for (int num : arr) {
            if (num == candidate) {
                count++;
            }
        }

        if (count > n / 2) {
            return candidate;
        }
        return -1;
    }
};