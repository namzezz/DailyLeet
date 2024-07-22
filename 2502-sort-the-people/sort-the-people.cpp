class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>> com;

        for(int i = 0 ; i < names.size() ; i++){
            com.push_back({heights[i], names[i]});
        }

        sort(com.rbegin(), com.rend());

        for(int i = 0 ; i < names.size() ; i++){
            names[i] = com[i].second;
        }

        return names;
    }
};