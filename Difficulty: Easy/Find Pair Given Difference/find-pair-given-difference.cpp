class Solution {
public:
    bool findPair(vector<int>& arr, int X) {
        unordered_set<int> seen;
        
        for (int num : arr) {
            // Check if there exists an element in 'seen' such that |num - elem| == X
            if (seen.find(num - X) != seen.end() || seen.find(num + X) != seen.end()) {
                return true;
            }
            seen.insert(num);
        }
        
        return false;
    }
};
