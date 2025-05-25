class Solution {
public:
    int totalFruit(vector<int>& fruits) {
      int left=0;
      unordered_map<int,int> mp;
      int maxlen=INT_MIN;
      int len=0;
      for( int right=0;right<fruits.size();right++){
        mp[fruits[right]]++;
        while(mp.size()>2){
            mp[fruits[left]]--;
            if(mp[fruits[left]]==0){
                mp.erase(fruits[left]);
            }
            left++;
        }
        
        len=right-left+1;
        maxlen=max(maxlen,len);
      }
      return maxlen;
    }
};