#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        int len = n + m;
        
        int gap = (len + 1) / 2; // ceil division
        
        while (gap > 0) {
            int i = 0;
            int j = gap;
            
            while (j < len) {
                // Get elements at i and j in combined array
                int elem_i, elem_j;
                
                if (i < n) elem_i = a[i];
                else elem_i = b[i - n];
                
                if (j < n) elem_j = a[j];
                else elem_j = b[j - n];
                
                if (elem_i > elem_j) {
                    // Swap
                    if (i < n && j < n) swap(a[i], a[j]);
                    else if (i < n && j >= n) swap(a[i], b[j - n]);
                    else if (i >= n && j >= n) swap(b[i - n], b[j - n]);
                }
                
                i++;
                j++;
            }
            
            if (gap == 1) break;
            gap = (gap + 1) / 2;
        }
    }
};