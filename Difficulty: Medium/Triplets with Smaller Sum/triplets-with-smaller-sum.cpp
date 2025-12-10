
class Solution {
public:
    long long countTriplets(int n, long long sum, long long arr[]) {
        sort(arr, arr + n);
        long long ans = 0;
        
        for (int i = 0; i < n - 2; i++) {
            int j = i + 1, k = n - 1;
            
            while (j < k) {
                if (arr[i] + arr[j] + arr[k] >= sum) {
                    k--;
                } else {
                    // All elements from j+1 to k will also satisfy the condition
                    ans += (k - j);
                    j++;
                }
            }
        }
        
        return ans;
    }
};