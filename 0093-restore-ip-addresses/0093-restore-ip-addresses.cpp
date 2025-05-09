class Solution {
public:
    bool check(string s){
        int n=s.size();
      
        if(n==1){
            return true;
        }

        if(n>3||s[0]=='0'){
            return false;
        }
 
        int val=stoi(s);
        if(val>255){
            return false;
        }

        return true;
    }
    vector<string> restoreIpAddresses(string s) {
        int n=s.size();
       
        vector<string>ans;
      
        if(n>12){
            return ans;
        }

        
        for(int i=1;i<=3;i++){//for the length before first '.'
            for(int j=1;j<=3;j++){//for the length between first and second '.'
                for(int k=1;k<=3;k++){//for the length between second and third '.'
 
                    if(i+j+k<n&&i+j+k+3>=n){
                     
                        string a=s.substr(0,i);
                        string b=s.substr(i,j);
                        string c=s.substr(j+i,k);
                        string d=s.substr(i+j+k);
     
                        if(check(a)&&check(b)&&check(c)&&check(d)){
                            ans.push_back(a+"."+b+"."+c+"."+d);
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};