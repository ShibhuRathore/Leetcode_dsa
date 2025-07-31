class Solution {
public:
    bool isValidIPV4(string IP) {
        if (IP.back() == '.') return false; 
        vector<string> parts;
        string part;
        stringstream ss(IP);

        while (getline(ss, part, '.')) parts.push_back(part);
        if (parts.size() != 4) return false;

        for (auto &p : parts) {
            if (p.empty()) return false;                           // No empty segment
            if (p.size() > 1 && p[0] == '0') return false;        // No leading zero
             if (p.size() > 3) return false; 
            for (auto &ch : p) {
                if (!isdigit(ch)) return false;                  // All must be digits
            }
            if (stoi(p) > 255) return false;                     // Range check AFTER digit validation
        }
        return true;
    }

    bool isValidIPV6(string IP) {
        if (IP.back() == ':') return false;
        vector<string> parts;
        string part;
        stringstream ss(IP);

        while (getline(ss, part, ':')) parts.push_back(part);
        if (parts.size() != 8) return false;

        for (auto &p : parts) {
            if (p.empty()) return false;                        // No empty block
            if (p.size() > 4) return false;                     // Max 4 hex chars
            for (auto &ch : p) {
                if (!isxdigit(ch)) return false;               // Only hex digits
            }
        }
        return true;
    }

    string validIPAddress(string str) {
        if (str.find('.') != string::npos) {
            if (isValidIPV4(str)) return "IPv4";
        }
        else if (str.find(':') != string::npos) {
            if (isValidIPV6(str)) return "IPv6";
        }
        return "Neither";
    }
};
