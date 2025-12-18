class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &arr, int target) {
        vector<vector<int>> result;
        int n = arr.size();
        
        if (n < 4) return result;
        
        // Sort the array
        sort(arr.begin(), arr.end());
        
        for (int i = 0; i < n - 3; i++) {
            // Skip duplicates for i
            if (i > 0 && arr[i] == arr[i - 1]) continue;
            
            // Early termination if smallest possible sum > target
            if ((long long)arr[i] + arr[i + 1] + arr[i + 2] + arr[i + 3] > target) break;
            
            // Early skip if largest possible sum < target
            if ((long long)arr[i] + arr[n - 3] + arr[n - 2] + arr[n - 1] < target) continue;
            
            for (int j = i + 1; j < n - 2; j++) {
                // Skip duplicates for j
                if (j > i + 1 && arr[j] == arr[j - 1]) continue;
                
                // Early termination if smallest possible sum > target
                if ((long long)arr[i] + arr[j] + arr[j + 1] + arr[j + 2] > target) break;
                
                // Early skip if largest possible sum < target
                if ((long long)arr[i] + arr[j] + arr[n - 2] + arr[n - 1] < target) continue;
                
                int left = j + 1;
                int right = n - 1;
                
                while (left < right) {
                    long long sum = (long long)arr[i] + arr[j] + arr[left] + arr[right];
                    
                    if (sum == target) {
                        result.push_back({arr[i], arr[j], arr[left], arr[right]});
                        
                        // Skip duplicates for left pointer
                        while (left < right && arr[left] == arr[left + 1]) left++;
                        // Skip duplicates for right pointer
                        while (left < right && arr[right] == arr[right - 1]) right--;
                        
                        left++;
                        right--;
                    } 
                    else if (sum < target) {
                        left++;
                    } 
                    else {
                        right--;
                    }
                }
            }
        }
        
        return result;
    }
};