class Solution {
public:
    bool checkOverlap(int r, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        auto clamp=[](int value,int low,int high){
            return max(low,min(value,high));
        };
        int closest_x=clamp(x_center,x1,x2);
        int closest_y=clamp(y_center,y1,y2);
        int dx=(closest_x-x_center);
        int dy=(closest_y-y_center);
        return dx*dx+dy*dy<=r*r;
    }
};