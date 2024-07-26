bool op(string str){
        if(str == "+" || str == "-" || str == "/" || str == "*"){
            return true;
        }
        return false;
  }
// pushing digits in stack
// when operator comes then pop out the top 2 stack elem and apply op on it
// push back the result in stack again
int evalRPN(vector<string>& tokens) {
        stack<int>s;
        int len = tokens.size();
        string curr = "";
        int fir,sec;
        for(int i = 0 ; i < len ; i++){
            curr = tokens[i];
            // means its a digit
            if(!op(curr)){
                s.push((stoi(curr)));
            }
            else{
                sec = s.top();
                s.pop();
                fir = s.top();
                s.pop();
                if(curr == "+"){
                    s.push(fir + sec);
                }
                else if(curr == "-"){
                    s.push(fir - sec);
                }
                else if(curr == "/"){
                    s.push(fir / sec);
                }
                else{
                    s.push(fir * sec);
                }
            }
        }
            return s.top();
}
