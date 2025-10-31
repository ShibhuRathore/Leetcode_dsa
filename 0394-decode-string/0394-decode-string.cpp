class Solution {
public:
    string decodeString(string s) {
        stack<int>numst;
        stack<string>charst;
        int currdigit=0;
        string currstr="";
        for(auto &ch:s){
            if(isdigit(ch)){currdigit=currdigit*10+ch-'0';}
            else if(ch=='['){numst.push(currdigit);currdigit=0; charst.push(currstr);currstr="";}
            else if(ch==']'){
            int size=numst.top(); numst.pop();
            string prevstr=charst.top();charst.pop();
            string temp=""; 
            while(size--)temp+=currstr;
            currstr=prevstr+temp;
            
            }
            else{
                currstr+=ch;
            }
        }
        return currstr;
    }
};