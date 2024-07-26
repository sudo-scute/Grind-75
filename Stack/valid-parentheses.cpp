bool isValid(string s) {

        stack <char>st;
        for(int i = 0 ; i < s.length() ; i++){
            char ch = s[i];

            // opening brackets simply push in stack
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }

            // closing brackets
            else{

              if(!st.empty()){
                char topa = st.top();
                    if((topa == '(' && ch == ')')|| (topa == '{' && ch == '}') || (topa == '[' && ch == ']')){
                        st.pop();
                    }

                    else{
                        return false;
                    }
                }

                else{
                        return false;
                    }

            }
        }

        if(st.empty()){
            return true;
        }
        else{
            return false;
        }


    }
