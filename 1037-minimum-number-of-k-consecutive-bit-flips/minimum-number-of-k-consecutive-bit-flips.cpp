class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> isFlipped(n, 0);
        int flips = 0;
        int result = 0;

        for (int i = 0; i < n; ++i) {
            // Adjust the number of flips based on whether we have ended a flip
            // k steps back
            if (i >= k) {
                flips -= isFlipped[i - k];
            }

            // If the current element is 0 and needs flipping
            if ((nums[i] + flips) % 2 == 0) {
                // If there are not enough elements left to flip, return -1
                if (i + k > n)
                    return -1;

                // Perform a flip
                isFlipped[i] = 1;
                flips++;
                result++;
            }
        }

        return result;
    }
};