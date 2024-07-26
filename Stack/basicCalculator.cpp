int calculate(string s) {
        stack<int> nums, oper;
        int result = 0; // store intermediate results
        int sign = 1;   // store sign of previous result
        int num = 0;    // store current number

        for (char ch : s) {

            if (isdigit(ch)) {
                 // creates a num until an operator comes like 124
                num = num * 10 +(ch -'0');
            }

            else {
                result += num * sign; // add the num with prev sign eg. 1+  ==> res = +1
                num = 0;  // for letting new numbers in

                switch (ch) {
                case '+':
                    sign = 1;
                    break;
                case '-':
                    sign = -1;
                    break;
                case '(': {
                    // first storing the previous calculations in stacks
                    nums.push(result); // stored the previous result
                    oper.push(sign);
                    result = 0;
                    sign = 1; // when going into ( bracket then initial sign = 1
                    break;
                }
                case ')': {
                    if(!oper.empty()){
                        result = oper.top() * result + nums.top();
                        oper.pop();
                        nums.pop();
                    }
                    break;
                }
                }
            }
        }
        result += sign * num;
        return result;
    }
