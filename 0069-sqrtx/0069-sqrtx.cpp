class Solution {
public:
    int mySqrt(int x) {
        int s=1;
        int e=x;
        long   mid=s+(e-s)/2;
        int ans=0;
        while(s<=e){
            if(mid*mid==x)return mid;
            else if (mid*mid<x) {
                 s=mid+1;
                 ans=mid;
            }
            else{
             
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }
};