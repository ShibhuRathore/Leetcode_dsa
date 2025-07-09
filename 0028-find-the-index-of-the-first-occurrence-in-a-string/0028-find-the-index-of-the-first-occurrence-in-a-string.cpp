class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=needle.length();
        int ans=-1;
        if(needle.length()>haystack.length()) return -1;
        for(int i=0;i<haystack.size();i++){
            if(haystack.substr(i,n)==needle){
                ans=i;
                break;
            }
        }
        return ans;
    }
};