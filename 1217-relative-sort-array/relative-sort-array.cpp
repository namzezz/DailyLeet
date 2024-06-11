class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mapp;
        vector<int> rem, res;

        for (int i = 0; i < arr2.size(); i++) {
            mapp[arr2[i]] = 0;
        }

        for (int i = 0; i < arr1.size(); i++) {
            if (mapp.find(arr1[i]) != mapp.end()) {
                mapp[arr1[i]]++;
            } else {
                rem.push_back(arr1[i]);
            }
        }

        sort(rem.begin(), rem.end());

        for (int i = 0; i < arr2.size(); i++) {
            for (int j = 0; j < mapp[arr2[i]]; j++) {
                res.push_back(arr2[i]);
            }
        }

        for (int i = 0; i < rem.size(); i++) {
            res.push_back(rem[i]);
        }
        return res;
    }
};