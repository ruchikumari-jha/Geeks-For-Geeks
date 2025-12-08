class Solution {
public:
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3) {
        vector<int> result;
        
        // Use arr1 as base, check each element in arr2 and arr3
        for (int i = 0; i < arr1.size(); i++) {
            // Skip duplicates
            if (i > 0 && arr1[i] == arr1[i-1]) continue;
            
            // Check if element exists in arr2 and arr3
            if (binary_search(arr2.begin(), arr2.end(), arr1[i]) &&
                binary_search(arr3.begin(), arr3.end(), arr1[i])) {
                result.push_back(arr1[i]);
            }
        }
        
        return result.empty() ? vector<int>{-1} : result;
    }
};