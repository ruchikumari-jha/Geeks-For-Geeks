class Solution {
  public:
    vector<int> getMinMax(vector<int> &arr) {
        int n=arr.size();
        
        if(n==0) return{};
        
        int min_val=arr[0];
        int max_val=arr[0];
        
        for(int i=1;i<n;i++){
            if(arr[i] < min_val){
                min_val = arr[i];
            }
            if(arr[i] > max_val){
                max_val =arr[i];
            }
        }
        return {min_val, max_val};
        
        
    }
};