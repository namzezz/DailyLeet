class Solution {
public:
    int climbStairs(int n) {
       if ( n == 0 || n == 1){
        return 1;
       }
       int prev = 1;
       int prev2 = 1;

       for(int i = 2 ; i <= n ; i++){
        int curr_i = prev + prev2;
        prev2 = prev;
        prev = curr_i;
       }

       return prev;
    }
};