class Solution {
public:
    double medianOf2(vector<int>& a, vector<int>& b) {
        // Ensure a is the smaller array for binary search optimization
        if (a.size() > b.size()) {
            return medianOf2(b, a);
        }
        
        int n = a.size();
        int m = b.size();
        
        int low = 0, high = n;
        
        while (low <= high) {
            int partitionA = (low + high) / 2;
            int partitionB = (n + m + 1) / 2 - partitionA;
            
            // Edge cases: if partition is at 0 or at the end
            int maxLeftA = (partitionA == 0) ? INT_MIN : a[partitionA - 1];
            int minRightA = (partitionA == n) ? INT_MAX : a[partitionA];
            
            int maxLeftB = (partitionB == 0) ? INT_MIN : b[partitionB - 1];
            int minRightB = (partitionB == m) ? INT_MAX : b[partitionB];
            
            // Check if partition is correct
            if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
                // Found correct partition
                if ((n + m) % 2 == 0) {
                    // Even total length: average of two middle elements
                    return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2.0;
                } else {
                    // Odd total length: middle element
                    return max(maxLeftA, maxLeftB);
                }
            }
            else if (maxLeftA > minRightB) {
                // Too far right in A, move left
                high = partitionA - 1;
            } else {
                // Too far left in A, move right
                low = partitionA + 1;
            }
        }
        
        // Should never reach here for valid inputs
        return 0.0;
    }
};