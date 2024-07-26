// just like checking if permutations of p exist in s
// sliding window
vector<int> findAnagrams(string s, string p) {
        if(p.length() > s.length()){
            return {};
        }

        int pLen = p.length();
        int sLen = s.length();

        vector<int>count1(26 , 0);
        vector<int>count2(26 , 0);

        int l = 0;
        int r = pLen;

        // filling char count for both p and s for same length
        for (int i = 0 ; i < pLen ; i++) {
            count1[p[i] - 'a']++;
            count2[s[i] - 'a']++;
        }

        vector<int> ans;
        // both count arrays same then push starting index in ans vector
        if (count1 == count2) {
            ans.push_back(l);
        }
        l++;

        for(int i = r ; i < sLen ; i++){
            count2[s[i] - 'a']++;  // adding new char
            count2[s[l-1] - 'a']--; // removing last char

            // again checking 
            if(count1 == count2){
                ans.push_back(l);
            }
            l++;

        }
        return ans;
    }
