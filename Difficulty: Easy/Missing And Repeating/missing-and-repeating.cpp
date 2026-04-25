class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();

        long long S = 0, P = 0;

        // Actual sum and square sum
        for (int num : arr) {
            S += num;
            P += 1LL * num * num;
        }

        // Expected sum and square sum
        long long SN = 1LL * n * (n + 1) / 2;
        long long PN = 1LL * n * (n + 1) * (2 * n + 1) / 6;

        long long val1 = SN - S;          // missing - repeating
        long long val2 = PN - P;          // missing^2 - repeating^2

        val2 = val2 / val1;               // missing + repeating

        long long missing = (val1 + val2) / 2;
        long long repeating = missing - val1;

        return {(int)repeating, (int)missing};
    }
};