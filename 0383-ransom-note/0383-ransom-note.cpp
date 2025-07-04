class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
       unordered_map<char,int>mp;
       for(auto &ms:magazine){
           mp[ms]++;
       }
       for(auto &rs:ransomNote){
        if(mp[rs]>0){
            mp[rs]--;
        }
      else{

                return false;
      }
        
       }
       return true;
    }
};