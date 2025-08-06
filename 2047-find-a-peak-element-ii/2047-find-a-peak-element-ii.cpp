class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int m=mat.size();
    int n=mat[0].size();
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        int maxi=0;
       for (int i = 0; i < m; i++) {
                if (mat[i][mid] > mat[maxi][mid]) {
                    maxi= i;
                }
            }
        int left=mid>0?mat[maxi][mid-1]:-1;
        int right=mid<n-1?mat[maxi][mid+1]:-1;
        if(mat[maxi][mid]>left &&mat[maxi][mid]>right){
            return{maxi,mid};
        }
        else if(mat[maxi][mid]>left){low=mid+1;}

        else{
        high=mid-1;
        }

    }
    return {-1,-1};
    }       
};