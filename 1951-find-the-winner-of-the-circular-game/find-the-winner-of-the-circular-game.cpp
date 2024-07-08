class Solution {
public:
    void josephus(vector <int> &v, int start, int k){
        if(v.size() == 1){
            return;
        }

        start += k;
        int s = v.size();
        start%=s;  //remainder so that index does not go above size of array
        v.erase(v.begin()+start);
        josephus(v,start,k);
    }
    int findTheWinner(int n, int k) {
        vector<int> v(n);
        k--;

        for(int i = 1 ; i<=n ; i++){
            v[i-1] = i;
        }

        josephus(v,0,k);
        return v[0];
    }
};