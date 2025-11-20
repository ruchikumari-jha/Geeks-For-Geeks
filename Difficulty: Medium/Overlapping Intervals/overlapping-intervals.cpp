class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
       int n=arr.size();
       if(n<=1) return arr;
       sort(arr.begin(),arr.end());
       
       vector<vector<int>>result;
       result.push_back(arr[0]);
       
       for(int i=1;i<n;i++){
           if(arr[i][0] <=result.back()[1]){
               result.back()[1]=max(result.back()[1],arr[i][1]);
           }
           else{
               result.push_back(arr[i]);
           }
       }
       return result;
    }
};