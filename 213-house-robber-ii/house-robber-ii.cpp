class Solution {
public:
    int calculate(vector<int>& nums) {
        int prev = 0;
        int prev2 = 0;

        for (int i = 0; i < nums.size(); i++) {
            int take = nums[i];

            if (i > 1) {
                take += prev2;
            }

            int nottake = 0 + prev;

            int curri = max(take, nottake);
            
            prev2 = prev;
            prev = curri;
        }

        return prev;
    }

int rob(vector<int>& nums) {
        vector<int> temp1, temp2;
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        for(int i = 0 ; i < n ; i++){
            if(i!=0){
                temp1.push_back(nums[i]);
            }
            if(i!=n-1){
                temp2.push_back(nums[i]);
            }
        }

        return max(calculate(temp1), calculate(temp2));

    }
};