class TrieNode {
public:
    TrieNode* children[26];
    bool isTerminal;
    TrieNode() {
        for (auto& it : children) {it = nullptr; }  this->isTerminal = false;}
};
class Trie {
    TrieNode* root;
public:
    Trie() { root = new TrieNode(); }
    void insert(string word) {
        TrieNode* p = root;
        for (auto& ch : word) {
            int ind = ch - 'a';
            if (!p->children[ind]) {
                p->children[ind] = new TrieNode();
            }
            p = p->children[ind];
        } p->isTerminal = true;
    }
    bool search(string word) {
        TrieNode* p = root;
        for (auto& ch : word) {
            int ind = ch - 'a';
            if (!p->children[ind]) {
                return false;
            }
            p = p->children[ind];
        } return (p->isTerminal);
    }
    bool startsWith(string prefix) {
        TrieNode* child = root;
        for (auto ch : prefix) {
            if (child->children[ch - 'a'] == nullptr) {
                return false;
            } else {
                child = child->children[ch - 'a'];
            }
        }return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
