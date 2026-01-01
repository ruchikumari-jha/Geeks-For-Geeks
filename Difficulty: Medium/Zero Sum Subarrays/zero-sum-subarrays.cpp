class Solution {
public:
    template<typename T>
    long long findSubarray(vector<T> arr) {
        unordered_map<long long, int> prefixSumCount;
        long long prefixSum = 0;
        long long count = 0;
        
        prefixSumCount[0] = 1;
        
        for (int i = 0; i < arr.size(); i++) {
            prefixSum += arr[i];
            
            if (prefixSumCount.find(prefixSum) != prefixSumCount.end()) {
                count += prefixSumCount[prefixSum];
            }
            
            prefixSumCount[prefixSum]++;
        }
        
        return count;
    }
    
    // This will work for both vector<int> and vector<long long>
};