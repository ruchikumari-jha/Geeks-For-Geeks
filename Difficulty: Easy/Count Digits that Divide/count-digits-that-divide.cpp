class Solution {
public:
    int evenlyDivides(int n) {
        int temp = n;
        int count = 0;

        while(n > 0) {
            int digit = n % 10;   // get last digit
            if(digit != 0 && temp % digit == 0) {
                count++;          // valid divisor
            }
            n = n / 10;           // remove last digit
        }

        return count;
    }
};