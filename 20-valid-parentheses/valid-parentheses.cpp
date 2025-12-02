class Solution {
public:
    bool isValid(string s) {

        if(s.size() % 2 == 1){              //matching  happen when string is Odd
            return false;
        }

    vector<char> v;

    for(int i = 0; i<s.size(); i++){
        
        char ch = s[i];

        if(ch == '(' || ch == '[' || ch == '{'){
            v.push_back( ch );
        }
        else{                                        //if the input is closing bracket
            if(v.size() > 0)                         //if array having some existing char
            {           
                if(ch == '}' && v.back()== '{'){
                    v.pop_back();
                }else if (ch == ']' && v.back()=='['){
                    v.pop_back();
                }else if(ch == ')' && v.back()=='('){
                    v.pop_back();
                }else{
                    return false;
                }
            }else{                      //and we have no opening
                return false;
            }   
        }
    }

    if(v.size()==0) 
        return true;
    else
        return false;
    }
};