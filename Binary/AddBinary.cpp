// adding 2 binary numbers represented by strings
// code similar to add 2 arrays
string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int l1 = a.length();
        int l2 = b.length();

        int i = 0;
        int j = 0;
        string sum = "" ;
        string carry = "0";

        // looop until one string ends
        while(i < l1 && j < l2){

            if(a[i] == '1' && b[j] == '1'){
                sum += carry; // carry condition included
                carry = "1";
            }
            else if(a[i] == '0' && b[j] == '0'){
                sum += carry; // carry condition included
                carry = "0";
            }
            else{
                // a[i] != b[j]
                // using carry also in it

                if(carry == "1"){
                    sum += "0";
                    carry = "1";
                }
                // carry = 0 a[i] + b[j] == 1 + carry ==> sum = 1 carry = 0
                else{
                    sum += "1";
                    carry = "0";
                }

            }

            i++;
            j++;
        }

        // for first string (if incompleted) 
        while(i < l1){
            if(a[i] == '0'){
                sum += carry;
                carry = "0";
            }
            else{
                //a[i] == "1"
                if(carry == "1"){
                    sum += "0";
                    carry = "1";
                }
                else{
                    //carry = 0
                    sum += a[i];
                }
            }

            i++;
        }


        // for second string (if incompleted) 
        while(j < l2){
            if(b[j] == '0'){
                sum += carry;
                carry = "0";
            }
            else{
                //b[j] == "1"
                if(carry == "1"){
                    sum += "0";
                    carry = "1";
                }
                else{
                    //carry = 0
                    sum += b[j];
                }
            }
            j++;
        }

        // finally at last if carry is left
        if(carry == "1")
        sum += carry;

        reverse(sum.begin() , sum.end());
        return sum;
    }
