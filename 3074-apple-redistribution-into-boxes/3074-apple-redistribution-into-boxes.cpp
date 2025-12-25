class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int m=apple.size();
        int n=capacity.size();
        sort(capacity.rbegin(),capacity.rend());
        int total=accumulate(apple.begin(),apple.end(),0);
        int count=0;
        for(int i=0;i<n;i++){
            if(total<=0)break;
            total-=capacity[i];
            count++;
        }
        return count;
    }
};