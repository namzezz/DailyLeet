class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> num;
        set<int> unique_nums(nums.begin(), nums.end());
        nums.assign(unique_nums.begin(), unique_nums.end());
        return unique_nums.size();
    }
};