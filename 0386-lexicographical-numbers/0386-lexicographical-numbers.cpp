class Solution {
    public:
    void solve( int i,int n,vector<int>&result){
        if (i>n){
            return;
        }
        result.push_back(i);
        for(int append=0;append<=9;append++){
            int newnum=10*i+append;
            if(newnum<=n){
                solve(newnum,n,result);
            }
        }
    }
    vector<int> lexicalOrder(int n) {
     vector<int>result;
    for( int i=1;i<=9;i++){
        solve(i,n,result);
    }
    return result;}
};