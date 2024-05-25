class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>m;
        for(int i=1;i<=nums.size();++i){
            m[i]++;
        }
        for(auto value:nums){
            m[value]++;
        }
        for(auto value:m){
            if(value.second==1){
                ans.push_back(value.first);
            }
        }
        return ans;
    }
};