class Solution {
public:
   double r, x,y;
    Solution(double radius, double x_center, double y_center) {
        this->r=radius;
        this->x=x_center;
        this->y=y_center;
    }
    
    vector<double> randPoint() {
        double theta=((double)rand()/RAND_MAX)*M_PI*2;
        double R=sqrt(((double)rand()/RAND_MAX))*r;
        double new_x=x+R*cos(theta);
        double new_y=y+R*sin(theta);
        return {new_x,new_y};

    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */