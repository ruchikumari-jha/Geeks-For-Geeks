class Solution {
public:
    int minSwaps(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> vec(n);
        for (int i = 0; i < n; i++) {
            vec[i].first = arr[i];
            vec[i].second = i;
        }
        
        // Sort by value
        sort(vec.begin(), vec.end());
        
        vector<bool> visited(n, false);
        int swaps = 0;
        
        for (int i = 0; i < n; i++) {
            // If already visited or already in correct position
            if (visited[i] || vec[i].second == i) {
                continue;
            }
            
            // Start a new cycle
            int cycle_size = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = vec[j].second;  // Go to original position of the element that should be here
                cycle_size++;
            }
            
            // For this cycle, add (cycle_size - 1) swaps
            if (cycle_size > 1) {
                swaps += (cycle_size - 1);
            }
        }
        
        return swaps;
    }
};