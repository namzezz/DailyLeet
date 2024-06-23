class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        // Deques to store the indices of the max and min elements of the
        // current window
        deque<int> maxDeque, minDeque;
        int left = 0, right;

        for (right = 0; right < nums.size(); ++right) {
            // Remove elements from the back of maxDeque if they are less than
            // the current element
            while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[right])
                maxDeque.pop_back();
            // Remove elements from the back of minDeque if they are greater
            // than the current element
            while (!minDeque.empty() && nums[minDeque.back()] >= nums[right])
                minDeque.pop_back();

            // Add the current element index to both deques
            maxDeque.push_back(right);
            minDeque.push_back(right);

            // Ensure the difference between the max and min elements is within
            // the limit
            if (nums[maxDeque.front()] - nums[minDeque.front()] > limit) {
                // Adjust the left pointer to shrink the window
                if (maxDeque.front() == left)
                    maxDeque.pop_front();
                if (minDeque.front() == left)
                    minDeque.pop_front();
                ++left;
            }
        }
        // The length of the longest subarray
        return right - left;
    }
};