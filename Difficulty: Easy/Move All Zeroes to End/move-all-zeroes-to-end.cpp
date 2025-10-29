class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        int n=arr.size();
        int nonZeroPos=0;
        
        for(int i=0;i<n;i++){
            if(arr[i]!=0){
                arr[nonZeroPos]=arr[i];
                nonZeroPos++;
            }
        }
        while(nonZeroPos <n){
            arr[nonZeroPos]=0;
            nonZeroPos++;
        }
        
    }
};