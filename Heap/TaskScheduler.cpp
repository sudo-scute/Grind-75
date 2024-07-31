int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char ch : tasks) {
            freq[ch - 'A']++;
        }
        sort(freq.begin(), freq.end());
        int blocks = freq[25] - 1; // e.g. A   A   A ; freq[A] = 3 ; blocks = 2
        int emptySpaces = blocks * n;
        for (int i = 24; i >= 0; i--) { // filling inside the blocks
            emptySpaces -=
                min(blocks,
                    freq[i]); // e.g. blocks = 2 ; freq[i] = 3 ; then filling
                              // can only be done inside block so only 2 chars
                              // are gonna placed inside blocks and remaining
                              // are gonna pushed after last char
        }
        if (emptySpaces < 0) { // all the chars can fill inside the blocks then
                               // there will be no empty space
            emptySpaces = 0;
        }
        return tasks.size() + emptySpaces;
}
