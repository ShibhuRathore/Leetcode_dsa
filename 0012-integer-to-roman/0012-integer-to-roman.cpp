class Solution {
public:
    string intToRoman(int num) {
        vector<string> roman={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        vector<int>val={1000,900,500,400,100,90,50,40,10,9,5,4,1};

        string result="";
        while(num>0){
            for(int i=0;i<val.size();i++){
                if(num>=val[i]){
                    result+=roman[i];
                    num-=val[i];
                    break;
                }
            }
        }
        return result;
    }
};