int maxArea(int* height, int heightSize) {
    int maxarea=INT_MIN;
    int left=0;
    int right=heightSize-1;
    while(left<right){
        int currheight =0;
        if(height[left]<height[right])currheight=height[left];
        else{currheight=height[right];}
        int Area=(right-left)*(currheight);
        if(maxarea<Area)maxarea=Area;
        if(height[left]<height[right])left++;
    else right--;
    }
    return maxarea;
}