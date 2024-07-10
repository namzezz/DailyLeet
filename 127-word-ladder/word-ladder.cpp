class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        queue<pair<string,int>> q;
        q.push({beginWord, 1});

        set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);
       
        
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if (word == endWord){
                return steps;
            }
            for(int i = 0 ; i < word.size() ; i++){
                //og char the word[i];
                char og = word[i];
                for(char ch = 'a' ; ch <= 'z' ; ch++){
                    //change og char to see if it exists in wordlist
                    word[i] = ch;
                    //it exista in cell then delete that word from set and add word,steps+! to queue
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word, steps+1});
                    }
                }
                word[i] = og;
            }
        }

        return 0;
        
    }
};