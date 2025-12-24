#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<double> getMedian(vector<int>& arr) {
        vector<double> res;
        priority_queue<int> maxHeap; // smaller half
        priority_queue<int, vector<int>, greater<int>> minHeap; // larger half

        for (int i = 0; i < arr.size(); i++) {
            int num = arr[i];

            // Insert into appropriate heap
            if (maxHeap.empty() || num <= maxHeap.top()) {
                maxHeap.push(num);
            } else {
                minHeap.push(num);
            }

            // Rebalance heaps
            if (maxHeap.size() > minHeap.size() + 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            } else if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }

            // Calculate median
            if (maxHeap.size() == minHeap.size()) {
                res.push_back((maxHeap.top() + minHeap.top()) / 2.0);
            } else {
                res.push_back(maxHeap.top());
            }
        }

        return res;
    }
};     
    

