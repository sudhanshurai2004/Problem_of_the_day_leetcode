class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = "";
        int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
        
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;
            if (i >= 0) sum += num1[i--] - '0';
            if (j >= 0) sum += num2[j--] - '0';
            carry = sum / 10;
            res += to_string(sum % 10);
        }
        
        reverse(res.begin(), res.end());
        return res;
    }

    bool check(string n1, string n2, string remain) {
        if (remain.empty()) return true;
        
        string n3 = addStrings(n1, n2);
        
        if (remain.rfind(n3, 0) != 0) return false;
        
        return check(n2, n3, remain.substr(n3.size()));
    }

    bool isAdditiveNumber(string num) {
        int n = num.size();
        if (n < 3) return false;

        for (int i = 0; i < n / 2; i++) {
            if (num[0] == '0' && i > 0) break;
            string n1 = num.substr(0, i + 1);

            for (int j = i + 1; n - 1 - j >= max(i + 1, j - i); j++) {
                if (num[i + 1] == '0' && j > i + 1) break;
                string n2 = num.substr(i + 1, j - i);

                string remain = num.substr(j + 1);
                if (check(n1, n2, remain)) {
                    return true;
                }
            }
        }
        return false;
    }
};