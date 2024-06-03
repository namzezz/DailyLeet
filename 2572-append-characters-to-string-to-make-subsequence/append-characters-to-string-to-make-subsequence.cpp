class Solution {
public:
    int appendCharacters(string s, string t) {
        int si = 0, ti = 0;
        int n = s.length(), m = t.length();
        //increment both si and ti if there is a match, if no match move si
        while(si < n && ti < m){
            if(s[si] == t[ti]){
                ti++;
            }
            si++;
        }
        //leftover string t is returned 
         //if t = "coding" and t_index is 2:
        //Remaining characters = t[2:] = "ding".
        //Number of characters to append = 5 - 2 = 3.
        return m - ti;
    }
};

/*Initialize pointers for s and t.
Traverse through s using a while loop.
Check character match and move pointers accordingly.
Calculate remaining characters of t and return the count.
This approach efficiently finds the minimum number of characters to append to s to make t a subsequence of s.*/