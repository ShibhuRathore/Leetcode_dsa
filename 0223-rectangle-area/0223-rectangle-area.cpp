class Solution {
public:
// total area =area1+area2 
// ans = totalarea-overlapping area
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        //overlapping condition
       int overlapped_width=max(0,min(ax2,bx2)-max(bx1,ax1));
       int overlapped_height=max(0,min(by2,ay2)-max(by1,ay1));
       int overlapped_area=overlapped_width*overlapped_height;
       int area1=(ax2-ax1)*(ay2-ay1);
       int area2=(bx2-bx1)*(by2-by1);
       return area1+area2-overlapped_area;
            
     
    }
};