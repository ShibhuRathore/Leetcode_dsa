class Solution {
public:
    vector<int> partitionLabels(string s) {
     vector<int>result;
     vector<int>mp(26,-1);
     for(int i=0;i<s.length();i++){
        mp[s[i]-'a']=i;
     }
    int n=s.length();
    int maxlength=0;
    int i=0;
     while(i<n){
        int end=mp[s[i]-'a'];
        int j=i;
        while(j<end){
            end=max(end,mp[s[j]-'a']);
            j++;
        }
       maxlength=j-i+1;
       result.push_back(maxlength);
       i=j+1;
     }
     return result;
    }
};