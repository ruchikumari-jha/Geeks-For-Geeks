// class Solution {
//   public:
//     int getSecondLargest(vector<int> &arr) {
//         if(arr.size() < 2){
//             return -1;
//         }
//         int largest =-1;
//         int second_largest=-1;
        
//         for(int i=0;i<arr.size();i++){
//             if(arr[i]<largest){
//                 second_largest=largest;
//                 largest=arr[i];
//             }
//             else if(arr[i]> second_largest && arr[i]!=largest){
//                 second_largest=arr[i];
//             }
//         }
//         return second_largest;


        
//     }
// };
class Solution{
    public:
    int getSecondLargest(vector<int> &arr){
        if(arr.size()<2){
            return -1;
        }
        int largest =-1;
        int second_largest=-1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>largest){
                second_largest=largest;
                largest=arr[i];
            }
            else if(arr[i]>second_largest && arr[i]!=largest){
                second_largest=arr[i];
            }
        }
        return second_largest;
    }
};