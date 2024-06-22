class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int count = 0, left = 0, right = 0, oddCount = 0, result = 0;

        while (right < nums.size()) {
            // Increase the count of odd numbers
            if (nums[right] % 2 != 0) {
                oddCount++;
                count = 0;
            }

            // When we have exactly k odd numbers
            while (oddCount == k) {
                if (nums[left] % 2 != 0) {
                    oddCount--;
                }
                left++;
                count++;
            }

            // Add the count of valid subarrays
            result += count;
            right++;
        }

        return result;
    }
};
