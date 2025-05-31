class Solution {
public:

    long long ispossible( long long a, long long b, long long c,long long mid){
     long long ab=lcm(a,b);
     long long ac=lcm(a,c);
     long long bc=lcm(b,c);
     long long abc=lcm(ab,c);
     return (mid/a)+(mid/c)+(mid/b)-(mid/ab)-(mid/ac)-(mid/bc)+(mid/abc);
    }
    int nthUglyNumber(int n, int a, int b, int c) {
       long long low=1, high=2e18, ans=0;
       while(low<=high){
        long long mid=low+(high-low)/2;
        if(ispossible(a,b,c,mid)>=n){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
       }
       return (int)  ans;
    }
};