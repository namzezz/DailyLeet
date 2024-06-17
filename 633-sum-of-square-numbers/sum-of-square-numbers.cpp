class Solution {
public:
    bool judgeSquareSum(int c) {
        long long left = 0;
        long long right = static_cast<long long>(sqrt(c));

        while (left <= right) {
            if (left * left + right * right == c) {
                return true;
            } else if (left * left + right * right > c) {
                right--;
            } else {
                left++;
            }
        }

        return false;
    }
};