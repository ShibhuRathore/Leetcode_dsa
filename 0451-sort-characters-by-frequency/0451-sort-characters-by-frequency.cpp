class Solution {
public:

   
    string frequencySort(string s) {
        unordered_map<char,int>mp;
         for (char c : s) {
            mp[c]++;  // Count frequency
        }
        string ans="";
        while(!mp.empty()){
            int max_freq=INT_MIN;
            char c=' ';
            int freq=0;

            for(auto &p:mp){
                 freq=p.second;
                if(freq>max_freq){
                    max_freq=freq;
                    c=p.first;
                }
                
               
            }
            while(max_freq){
                    ans+=c;
                    max_freq--;
                }
                 mp.erase(c);
        }
        return ans;
    }
};