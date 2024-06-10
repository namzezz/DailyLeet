class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected;
        int count = 0;
        expected.assign(heights.begin(), heights.end());

        sort(expected.begin(), expected.end());

        for(int i = 0 ; i < heights.size() ; i++){
            if(heights[i]!=expected[i]){
                count++;
            }else{
                continue;
            }
        }

        return count;
    }
};