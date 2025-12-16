#include <vector>
using namespace std;

class Solution {
public:
    // Merge function to count inversions during merging
    long long merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp(high - low + 1);
        int i = low, j = mid + 1, k = 0;
        long long inv_count = 0;

        while (i <= mid && j <= high) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                // arr[i] > arr[j] → inversion
                inv_count += (mid - i + 1);
                temp[k++] = arr[j++];
            }
        }

        // Copy remaining elements
        while (i <= mid)
            temp[k++] = arr[i++];
        while (j <= high)
            temp[k++] = arr[j++];

        // Copy back to original array
        for (int idx = 0; idx < k; idx++)
            arr[low + idx] = temp[idx];

        return inv_count;
    }

    // Recursive merge sort function
    long long mergeSort(vector<int>& arr, int low, int high) {
        long long inv_count = 0;
        if (low < high) {
            int mid = low + (high - low) / 2;
            inv_count += mergeSort(arr, low, mid);
            inv_count += mergeSort(arr, mid + 1, high);
            inv_count += merge(arr, low, mid, high);
        }
        return inv_count;
    }

    // Main function
    long long int inversionCount(vector<int> &arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};