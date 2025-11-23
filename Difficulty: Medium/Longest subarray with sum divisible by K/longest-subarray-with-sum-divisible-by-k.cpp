// User function template for C++
class Solution {
  public:
    int longestSubarrayDivK(vector<int>& arr, int k) {
        unordered_map<int ,int>remainderMap;
        remainderMap[0]=-1;
        
        long long prefixSum=0;
        int maxLength=0;
        
        for(int i=0;i<arr.size();i++){
            prefixSum+=arr[i];
            
            int remainder =prefixSum % k;
            if(remainder < 0){
                remainder +=k;
            }
            if(remainderMap.find(remainder)!=remainderMap.end()){
                int length =i-remainderMap[remainder];
                maxLength =max(maxLength ,length);
            }
            else{
                remainderMap[remainder]=i;
            }
        }
        return maxLength;
    }
};