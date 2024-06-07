class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        // set<int> num;
        // set<int> unique_nums(nums.begin(), nums.end());
        // nums.assign(unique_nums.begin(), unique_nums.end());
        // return unique_nums.size();
        int i = 0;
        int n = a.size();

        for(int j = 1 ; j < n ; j++){
            if(a[i]!=a[j]){
                i++;
                a[i]=a[j];
            }
        }

        return i+1;

    }
};