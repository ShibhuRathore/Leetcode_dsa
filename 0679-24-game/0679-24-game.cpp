class Solution {
public:
    double helper(double a, string sign, double b) {
        if (sign == "+") return a + b;
        else if (sign == "-") return a - b;
        else if (sign == "*") return a * b;
        else if (sign == "/") return b != 0 ? a / b : 1e9; // avoid division by zero
        return 0;
    }

    bool judgePoint24(vector<int>& cards) {
        int n = cards.size();
        vector<string> option = {"+", "-", "*", "/"};
        const double eps = 1e-6;
        for(int i=0;i<4;i++){
            double a = cards[i];
            for(int j=0;j<4;j++){
                if(j==i) continue;
                double b = cards[j];
                for(int k=0;k<4;k++){
                    if(k==i||k==j) continue;
                    double c = cards[k];
                    for(int l=0;l<4;l++){
                        if(l==i||l==j||l==k) continue;
                        double d = cards[l];

                        // Case 1: (a op b) op (c op d)
                        for(auto op1 : option)
                            for(auto op2 : option)
                                for(auto op3 : option){
                                    double x = helper(a, op1, b);
                                    double y = helper(c, op2, d);
                                    double ans = helper(x, op3, y);
                                    if(abs(ans - 24) < eps) return true;
                                }

                        // Case 2: ((a op b) op c) op d
                        for(auto op1 : option)
                            for(auto op2 : option)
                                for(auto op3 : option){
                                    double x = helper(a, op1, b);
                                    double y = helper(x, op2, c);
                                    double ans = helper(y, op3, d);
                                    if(abs(ans - 24) < eps) return true;
                                }

                        // Case 3: (a op (b op c)) op d
                        for(auto op1 : option)
                            for(auto op2 : option)
                                for(auto op3 : option){
                                    double x = helper(b, op1, c);
                                    double y = helper(a, op2, x);
                                    double ans = helper(y, op3, d);
                                    if(abs(ans - 24) < eps) return true;
                                }

                        // Case 4: a op ((b op c) op d)
                        for(auto op1 : option)
                            for(auto op2 : option)
                                for(auto op3 : option){
                                    double x = helper(b, op1, c);
                                    double y = helper(x, op2, d);
                                    double ans = helper(a, op3, y);
                                    if(abs(ans - 24) < eps) return true;
                                }

                        // Case 5: a op (b op (c op d))
                        for(auto op1 : option)
                            for(auto op2 : option)
                                for(auto op3 : option){
                                    double x = helper(c, op1, d);
                                    double y = helper(b, op2, x);
                                    double ans = helper(a, op3, y);
                                    if(abs(ans - 24) < eps) return true;
                                }

                    }
                }
            }
        }
        return false;
    }
};