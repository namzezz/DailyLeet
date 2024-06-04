class Solution {
public:
    int longestPalindrome(string s) {
        int oddCnt = 0;
        unordered_map<char, int> pal;

        for(char ch : s){
            pal[ch]++;
            if(pal[ch]%2==1){
               oddCnt++;
            }else{
                oddCnt--;
            }
            
        }

        if(oddCnt>1){
            return s.length()-oddCnt+1;
        }else{
            return s.length();
        }
        
    }
};