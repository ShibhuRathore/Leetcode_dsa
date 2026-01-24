class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxlen=INT_MIN, n=s.length(),i=0,j=0,maxfreq=INT_MIN;
        unordered_map<char,int>mp;
        for(j=0;j<n;j++){
            mp[s[j]]++;
            maxfreq=max(maxfreq,mp[s[j]]);
            while((j-i+1)-maxfreq>k){
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
            }
            maxlen=max((j-i+1),maxlen);
        }
        return maxlen;
    }
};