class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
       int count_M=0;
       int count_P=0;
       int count_G=0;
       int index_M=0;
       int index_P=0;
       int index_G=0;
     
       for(int i=0;i<garbage.size();i++){
        string s=garbage[i];
        for(int j=0;j<s.size();j++){
            char ch=s[j];
            if(ch=='M'){
                count_M+=1;
                index_M=i;
            }
            if(ch=='P'){
                count_P+=1;
                index_P=i;
            }
            if(ch=='G'){
                count_G+=1;
                index_G=i;
            }
        }
       } 
       for( int i=0;i<index_P;i++){
        count_P+=travel[i];
       }
        for( int i=0;i<index_G;i++){
        count_G+=travel[i];
       } 
       for( int i=0;i<index_M;i++){
        count_M+=travel[i];
       }
       return count_M+count_P+count_G;
    }
};