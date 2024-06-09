class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
       unordered_map<int, int> rem = {{0, 1}};
        int sum = 0, count = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum = (sum + nums[i]) % k;
            if(sum < 0) sum += k;
            if (rem.find(sum) != rem.end()) {
                count += rem[sum];
                rem[sum]++;
            } else {
                rem[sum] = 1;
            }
        }

        return count;
    }  
        
        
    
};