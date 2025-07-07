class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char>mp;
        int i=0;
       for(auto &ch:key){
        if (ch == ' ') continue; 
        if(!mp.count(ch)){
              mp[ch]='a'+i;
            i++;
        }
        
       } 
       string temp="";
       for(auto &ch:message){
        if(ch==' '){
            temp+=' ';
        }
        else{

        temp=temp+mp[ch];
        }
       }
       return temp;
    }

};