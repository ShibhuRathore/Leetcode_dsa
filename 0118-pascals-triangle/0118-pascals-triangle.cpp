class Solution {
public:
    vector<vector<int>> generate(int n) {
    vector<vector<int>>result;
    for(int i=0;i<n;i++){
        vector<int>row(i+1,1);
        for(int j=1;j<row.size()-1;j++){
            row[j]=result[i-1][j-1]+result[i-1][j];
        }
        result.push_back(row);
    }
    return result;
    }
};