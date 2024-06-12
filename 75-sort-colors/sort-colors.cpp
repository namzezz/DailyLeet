class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count[3] = {0};
        for(int x: nums)
            count[x]++;
        int n = nums.size(), c = 0;

        for(int x = 0 ; x < 3 ; x++){
            fill(nums.begin()+c, nums.begin()+c+count[x], x);
            c+=count[x];
        }
    }
};