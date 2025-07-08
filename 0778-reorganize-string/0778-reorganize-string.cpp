class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>mp;
        for(auto &ch:s){
            mp[ch]++;
        }
        priority_queue<pair<int , char>> pq;
        for(auto &[node,freq]:mp){
            pq.push({freq,node});
        }
        string result="";
       while(pq.size()>=2){
        auto[freq1,ch1]=pq.top(); pq.pop();
        auto[freq2,ch2]=pq.top();pq.pop();
        result+=ch1;
        result+=ch2;
        freq1--;
        freq2--;
        if(freq1>0){pq.push({freq1,ch1});}
        if(freq2>0){pq.push({freq2,ch2});}

       }
       if(!pq.empty()){
          auto [freq,ch1]=pq.top();
          pq.pop();
          if(freq>1) return "";
          result+=ch1;
       }
       return result;
    }
};