class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        // Edge case
        if (n <= 1) return 0;
        if (arr[0] == 0) return -1;

        int jumps = 0;
        int currEnd = 0;
        int farthest = 0;

        for (int i = 0; i < n - 1; i++) {
            // Update farthest reachable index
            farthest = max(farthest, i + arr[i]);

            // If we reached the end of current jump range
            if (i == currEnd) {
                jumps++;
                currEnd = farthest;

                // If we can't move forward
                if (currEnd <= i) return -1;
            }
        }

        return jumps;
    }
};