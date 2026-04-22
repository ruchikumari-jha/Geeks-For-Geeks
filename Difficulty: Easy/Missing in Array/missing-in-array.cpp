// class Solution {
//   public:
//     int missingNum(vector<int>& arr) {
//         // code here
        
//     }
// };

class Solution {
public:
    int missingNum(vector<int>& arr) {
        int n = arr.size() + 1;

        int xor1 = 0, xor2 = 0;

        // XOR from 1 to n
        for (int i = 1; i <= n; i++) {
            xor1 ^= i;
        }

        // XOR array elements
        for (int num : arr) {
            xor2 ^= num;
        }

        return xor1 ^ xor2;
    }
};