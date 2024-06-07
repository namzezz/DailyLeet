class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;
    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    string searchRoot(const string& word) {
        TrieNode* node = root;
        string prefix = "";
        for (char ch : word) {
            int index = ch - 'a';
            if (!node->children[index]) {
                break;
            }
            node = node->children[index];
            prefix += ch;
            if (node->isEndOfWord) {
                return prefix;
            }
        }
        return word;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for (const string& root : dictionary) {
            trie.insert(root);
        }

        istringstream iss(sentence);
        string word;
        string result = "";
        
        while (iss >> word) {
            if (!result.empty()) {
                result += " ";
            }
            result += trie.searchRoot(word);
        }

        return result;
    }
};