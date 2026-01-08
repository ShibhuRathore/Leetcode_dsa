class Solution {
public:
// Brute Force -> TC-O(N) and SC->O(N)
    // vector<int> funcl(vector<int>&height){
    //     int maxleft=height[0];
    //     int n=height.size();
    //     vector<int>lefth(n);
    //     lefth[0]=height[0];
    //     for(int i=1;i<height.size();i++){
    //         if(height[i]>maxleft){
    //             maxleft=height[i];
    //         }
    //         lefth[i]=maxleft;
    //     }
    //     return lefth;
    // }
    //   vector<int> funcr(vector<int>&height){
    //     int n=height.size();
    //     int maxright=height[n-1];
    //     vector<int>righth(n);
    //     righth[n-1]=height[n-1];
    //     for(int i=n-1;i>=0;i--){
    //         if(height[i]>maxright){
    //             maxright=height[i];
    //         }
    //         righth[i]=maxright;
    //     }
    //     return righth;
    // }
    int trap(vector<int>& height) {
    //     int n=height.size();
    //     vector<int> leftMax=funcl(height);
    //     vector<int> rightMax=funcr(height);
    //     int sum=0;
    //     for(int i=0;i<n;i++){
    //         int h=min(leftMax[i],rightMax[i])-height[i];
    //         sum+=h;
    //     }
    //     return sum;

// optimized 2 pointer approach -> TC-O(N). and SC->O(1)
    int left=0;
    int right =height.size()-1;
    int leftmax=height[left];
    int rightmax=height[right];
    int ans=0;
    while(left<right){
        if(leftmax<rightmax){
            left++;
            leftmax=max(height[left],leftmax);
            ans+=leftmax-height[left];
        }
        else{
            right--;
            rightmax=max(height[right],rightmax);
            ans+=rightmax-height[right];
        }
    }    
    return ans;  
    }
};