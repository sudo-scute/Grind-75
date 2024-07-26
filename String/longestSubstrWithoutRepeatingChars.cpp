// map to store last indices of a char
// while traversing string if char is found in map then increase starting index to (lastSeen[curr] + 1)
int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        int len = 0;
        int n = s.length();
        map<char, int> lastSeen; // last seen indices of chars 
        while (j < n) {
            char ch = s[j];
            // means current char is already present at some index
            if (lastSeen.find(ch) != lastSeen.end() && lastSeen[ch] >= i) {
                i = lastSeen[ch] + 1; //updating i just 1 index further
            } 
            len = max(len , j - i  + 1);
            lastSeen[ch] = j; // updating last seen index of current char
            j++;
        }
        return len;
}
