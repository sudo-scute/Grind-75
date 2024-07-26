// always prefer vector of fixed smaller size over map for faster searching
// due to contiguous nature of vector elements
string minWindow(string s, string t) {

        vector<int>t_freq(128,0); // for freq of chars of t
        vector<int>currentWindFreq(128,0); // for freq of char of current window
        for(char ch : t){
            t_freq[ch]++;
        }

        int starti = 0; // starting index of final ans

        int minLen = INT_MAX; // length of minimum window

        int count = t.length(); // must have no. of chars of t
        
        int i = 0;

        for(int j = 0;  j < s.length() ; j++){
            currentWindFreq[s[j]]++;  // increased the freq of char of current window

            // if we got the needed char in current window then --count
            if(currentWindFreq[s[j]] <= t_freq[s[j]]){
                --count;
            }

            // reducing the length of current window while count == 0 // all needed chars are gotten
            while(count == 0){

                while(i <= j){
                        // availability     >   demand
                    if(currentWindFreq[s[j]] > t_freq[s[j]]){
                        currentWindFreq[s[j]]--;
                    }
                    else{
                        // availability == demand 
                        break;
                    }
                    i++;  // decremented the length by increasing starting index
                }

                // ans updation if current length is smaller
                if(j - i + 1 < minLen){
                    starti = i;
                    minLen = j - i + 1;
                }

                // try to reduce the window size by moving the left pointer
                currentWindFreq[s[i]]--;

                // if the char at left pointer was needed, increment count
                if (currentWindFreq[s[i]] < t_freq[s[i]]) {
                    count++;
                }
                i++; // increment left pointer
            }
        }


        return minLen == INT_MAX ? "" : s.substr(starti , minLen);
}
