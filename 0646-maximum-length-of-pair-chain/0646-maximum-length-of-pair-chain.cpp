class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
       sort(pairs.begin(),pairs.end(),[](const vector<int>&a, const vector<int>&b){
        return a[1]<b[1];
       });
       int count=1;
       int endpoint=pairs[0][1];
       for(int i=1;i<pairs.size();i++){
        int start=pairs[i][0];
        int end=pairs[i][1];
        if(start>endpoint){
            count++;
            endpoint =end;
        }
       }
       return count;
    }
};