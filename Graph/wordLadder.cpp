class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        queue<pair<string, int>> q;

        q.push({beginWord, 1});

        unordered_set<string> st(wordList.begin(), wordList.end());

        st.erase(beginWord); // if in case its present in set

        while (!q.empty()) {
            string word = q.front().first;
            int step = q.front().second;
            q.pop();
            if (word == endWord)
                return step;

            // gonna replace each char of current word with a-z and each index
            for (int i = 0; i < word.length(); i++) {
                char original = word[i];

                // changing a single char from current word and finding if new word is present in set or not
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch; // actual changing

                    // checking if new word is present or not 
                    if (st.find(word) != st.end()) {
                        st.erase(word);
                        q.push({word, step + 1});
                    }
                }

                // reverting to original char
                word[i] = original;
            }
        }
        return 0;
    }
};
