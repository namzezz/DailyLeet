class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int j = 1;

        for (int i = 0; i < nums.size(); i += 2) {
            if (j < nums.size() && nums[i] == nums[j]) {
                j += 2;
            } else {
                return nums[i];
            }
        }

        return nums[nums.size() - 1];
    }
};