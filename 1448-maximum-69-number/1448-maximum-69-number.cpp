class Solution {
public:
    int maximum69Number (int num) {
        string str = to_string(num);
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '6') {
                str[i] = '9';  // flip the first '6' we see
                break;         // only flip once for max value
            }
        }
        return stoi(str);
    }
};
