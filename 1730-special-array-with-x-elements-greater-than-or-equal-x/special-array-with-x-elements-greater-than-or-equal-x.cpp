class Solution {
public:
    int specialArray(vector<int>& nums) {
        int x = 0;
        int n = nums.size();
        for (int x = 0; x <= n; x++) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] >= x) {
                    cnt++;
                }
            }
            if (cnt == x) {
                return x;
            }
        }

        return -1;
    }
};