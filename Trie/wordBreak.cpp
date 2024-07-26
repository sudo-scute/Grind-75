// basic trie implementation 
class TrieNode {
public:
    char val;
    TrieNode* children[26];
    bool isTerminal;
    TrieNode(char ch) {
        this->val = ch;
        for (auto& it : children) {
            it = nullptr;
        }
        this->isTerminal = false;
    }
};
class Trie {
public:
    TrieNode* root;
    Trie() { root = new TrieNode('\0'); }

    void insert(string word) {
        TrieNode* p = root;
        for (auto& ch : word) {
            int ind = ch - 'a';
            if (!p->children[ind]) {
                p->children[ind] = new TrieNode(ch);
            }
            p = p->children[ind];
        }
        p->isTerminal = true;
    }

    TrieNode* returnRoot(){
        return root;
    }
};

// final ans
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie* tyre = new Trie();

        // inserting all words of dictionary in trie
        for (auto word : wordDict) {
            tyre->insert(word);
        }
        
        int n = s.length();

        // dp[i] = true if substring [0,....,i-1] is found in wordDict
        vector<bool>dp(n + 1 , false);

        dp[0] = true;  // "" string can be segmented

        for(int i = 0; i < n ; i++){

            // curr char not found in trie
            if(dp[i] == false){
                continue; // move ahead and check for next index
            }
            else{
                TrieNode* node = tyre->returnRoot();
                for(int j = i; j < n ; j++){

                    int ind = s[j] - 'a';

                    // element not found so no further checking for this string ==> i++
                    if(node->children[ind] == nullptr){
                        break;
                    }
                    node = node->children[ind];
                    if(node->isTerminal == true){
                        dp[j+1] = true;
                    }
                }


            }
        }

        return dp[n];
    }
};
