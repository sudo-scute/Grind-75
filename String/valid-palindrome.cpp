bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
  
        while (i <= j) {
            //continue statement restricts the code from going through further conditions
            if(!isalnum(s[i])){
                i++;
                continue;
            }
            if(!isalnum(s[j])){
                j--;
                continue;
            }
            // at last i and j will stop at alnum chars and then comparison
            if((tolower(s[i]) == tolower(s[j]))){
                i++;
                j--;
            }
            // not matching alnum chars
            else{
                return false;
            }

        }

        return true;
}
