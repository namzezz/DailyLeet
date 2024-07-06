class Solution {
public:
    int passThePillow(int n, int time) {
        int fullR = time/(n-1);
        int extraTime = time % (n-1);

        if(fullR % 2 == 0){
            return extraTime + 1;
        } else {
            return n - extraTime;
        }
    }
};