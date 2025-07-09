class Solution {
public:

    bool repeatedSubstringPattern(string s) {
        int n=s.length();
        for(int length=1;length<=n/2;length++){
            if(n%length!=0)continue;
            int times=n/length;
                string sub=s.substr(0,length);
                string temp="";
            for(int i=1;i<=times;i++){
                temp+=sub;
            }
            if(temp==s) return true;
        }
        return false;
    }
};