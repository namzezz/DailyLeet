class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxOne = 0;
        int k = 0;

        for(int i = 0 ; i<nums.size() ; i++){
            if(nums[i]==1){
                k++;
                if (k > maxOne){
                    maxOne = k;
                }
            }else{
                k = 0;
            }
        }

        return maxOne;
    }
};