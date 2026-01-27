class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        vector<int>prefix(n+1,0);
        int max_ele=0;
        for(int i=1;i<=n;i++){
            prefix[i]=gain[i-1]+prefix[i-1];
            max_ele=max(max_ele,prefix[i]);
        }
        return max_ele;
    }
};