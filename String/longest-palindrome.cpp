// simple char count
// adding even lengths to ans 
// adding odd length - 1 to ans first
// then finally adding 1 more if any char is found with odd frequency

int longestPalindrome(string s) {
        map<char, int> mapi;
        int len = 0;
        bool odd = false;
        for (int i = 0; i < s.length(); i++) {
            mapi[s[i]]++;
        }
        for (auto it : mapi) {
            if (it.second % 2 == 0) {
                len += it.second;
            } else {
                len += it.second - 1; // if 3 then add only 2 of them
                odd = true;
            }
        }

        if (odd == true) {
            len += 1; // if any odd freq char found earlier then adding 1 char
                      // which was left
        }

        return len;
}
