class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>s_store(26,0);
        vector<int>t_store(26,0);

        for(int i=0;i<s.size();i++){
            char ch=s[i];
            char cht=t[i];
            s_store[ch-'a']++;
            t_store[cht-'a']++;
        }
         int moves=0;
        for(int i =0;i<26;i++){
            if(s_store[i]>t_store[i]){
            int diff=(s_store[i]-t_store[i]);
            moves+=diff;
            }
          
        }
        return moves;
    }
};