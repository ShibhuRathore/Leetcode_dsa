class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char>result;
        result.push_back(chars[0]);
        int count=1;
        for(int i=1;i<chars.size();i++){
            if(chars[i]==chars[i-1]){count++;}
            else{
                if(count>1){
                    string count_str=to_string(count);
                    for(auto &ch:count_str){
                        result.push_back(ch);
                    }
                }
                result.push_back(chars[i]);
                count=1;
            }
        }
        if (count > 1) {
            string count_str = to_string(count);
            for (auto &ch : count_str) {
                result.push_back(ch);
            }
        }
        chars=result;
        return result.size();
    }
};