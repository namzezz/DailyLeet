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
        
        // If there are characters with odd frequencies, we are
        // guaranteed to have at least one letter left unmatched,
        // which can make the center of an odd length palindrome.
        if(oddCnt>1){
            return s.length()-oddCnt+1;
        }else{
            return s.length();
        }
        
    }
};