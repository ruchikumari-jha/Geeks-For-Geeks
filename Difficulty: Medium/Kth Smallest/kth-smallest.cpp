class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int>pq;
        
        for(int num :arr){
            if(pq.size()<k){
            pq.push(num);
            }
            else if(num <pq.top()){
                pq.pop();
                pq.push(num);
            }
        }
        return pq.top();
    }
};