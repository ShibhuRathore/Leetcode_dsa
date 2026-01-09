/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    int *ans=(int*)malloc((numsSize-k+1)*sizeof(int));
    int *dq=(int*)malloc(numsSize*sizeof(int));
    int head=0;
    int tail=0;
    int ansidx=0;
     for(int i=0;i<numsSize;i++){
        if(head<tail && dq[head]<=i-k)head++;
        while(head<tail && nums[i]>=nums[dq[tail-1]])tail--;
        dq[tail++]=i;
        if(i>=k-1)ans[ansidx++]=nums[dq[head]];
     }
     *returnSize=ansidx;
     return ans;
}