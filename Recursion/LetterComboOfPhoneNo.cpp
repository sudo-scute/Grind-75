void keyPad(string& digits, string& temp, vector<string>& ans, int ind,vector<string>& mapping , int siz) {

        if(ind == siz){
            ans.push_back(temp);
            return;
        }       
        int x = digits[ind] - '0';   // getting the no. outta digits
        string cutout = mapping[x];

        int len = cutout.size();
  
        //hovering over the cutout  -- "abc"
        for(int i = 0 ; i < len; i++){

            temp.push_back(cutout[i]);
            // now temp = "a"
            // moving onwards to next digit of digits string 
            keyPad(digits, temp, ans, ind + 1, mapping ,siz);

            temp.pop_back();  // when coming back
        }
    }

// eg. string = "23" then possible combinations are ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// 2 - "abc"    // 3 - "def
vector<string> letterCombinations(string digits) {
        vector<string> ans;   // stores all the combos

        if(digits == ""){
            return ans;
        }

        int ind = 0; // for hovering over the digits string
        string temp = "";  // stores the string mapped with that number
        int siz = digits.size();
        vector<string> mapping = {"",    "",    "abc",  "def", "ghi","jkl", "mno", "pqrs", "tuv", "wxyz"};
        keyPad(digits, temp, ans, ind, mapping , siz);
        return ans;
    }
