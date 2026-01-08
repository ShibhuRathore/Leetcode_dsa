class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int>mp;
        int n=s.length();
        int i=0;
        int maxlen=0;
        for(int j=0;j<n;j++){
           while(i<=j&&mp.find(s[j])!=mp.end()){
              mp[s[i]]--;
              if(mp[s[i]]==0)mp.erase(s[i]);
              i++;
           }
           mp[s[j]]++;
           maxlen=max((j-i+1),maxlen);
        }
        return maxlen;
     }
};