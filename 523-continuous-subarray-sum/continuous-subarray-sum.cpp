class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> rem;
        int sum = 0;
        rem[0] = -1;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int r = sum % k;
            //numbers with same remainder after division with k will have their sums divisible by k.
            if (rem.find(r) != rem.end()) {
                //check if length of subarray is >2 rem[r] gives the index at which the number is
                if (i - rem[r] >= 2) {
                    return true;
                }
            } else {
                rem[r] = i;
            }
        }

        return false;
    }
};