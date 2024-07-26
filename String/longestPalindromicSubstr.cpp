// just like manacher algorithm 
// checking if we can expand palindrome to left and right of curr char
int expand(string &s , int l , int r){

        int len = 0;
        while( l >= 0 && r < s.length() && s[l] == s[r]){
            l--;
            r++;
        }

        return (r - l - 1);
}

string longestPalindrome(string s) {
        if(s == ""){return s;}
        int start = 0; 
        int end = 0;
        int maxLen = 0;
        for(int  i = 0 ; i < s.length() ;i++){
            int includeWithODD = expand(s , i , i);  
            int includeWithEVEN = expand(s , i , i+1);
            maxLen = max(includeWithODD , includeWithEVEN);

            if(maxLen > end - start){
                start = i - (maxLen-1)/2;
                end = i + (maxLen)/2;
            }
        }

        return s.substr(start , end - start + 1);
}
