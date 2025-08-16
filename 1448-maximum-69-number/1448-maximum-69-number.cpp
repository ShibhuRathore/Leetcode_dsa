class Solution {
public:
    int maximum69Number (int num) {
        vector<int>temp;
        string str=to_string(num);
        for(int i =0;i<str.length();i++){
            char ch=str[i];
            if(ch=='6'){
                str[i]='9';
                temp.push_back(stoi(str));
                str[i]='6';
              continue;
            }
        }
         if (temp.empty()) return num;
        return *max_element(temp.begin(),temp.end());
    }
};