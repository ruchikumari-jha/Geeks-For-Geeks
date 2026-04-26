class Solution {
public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int i = 0, j = 0;
        int platforms = 0, maxPlatforms = 0;
        int n = arr.size();

        while(i < n && j < n) {
            if(arr[i] <= dep[j]) {
                platforms++;      // train arrives
                i++;
            } else {
                platforms--;      // train departs
                j++;
            }
            maxPlatforms = max(maxPlatforms, platforms);
        }

        return maxPlatforms;
    }
};
