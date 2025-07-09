class Solution {
public:
  
    int lengthOfLongestSubstring(string s) {
        int maxLength=0;
        string temp="";
     for(int i=0;i<s.length();i++){
        if(temp.find(s[i])==string::npos){
            temp+=s[i];
            maxLength=max(maxLength,(int)temp.length());
        }
        else{
            int pos=temp.find(s[i]);
            temp=temp.substr(pos+1,temp.length()-pos-1);
            temp+=s[i];
        }}
        return maxLength;
     }
};