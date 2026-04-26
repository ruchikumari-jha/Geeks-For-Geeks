class Solution {
public:
    int largest(vector<int> &arr) {
        int maxVal = arr[0];   // assume first element is largest
        
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] > maxVal) {
                maxVal = arr[i];   // update max
            }
        }
        
        return maxVal;
    }
};
