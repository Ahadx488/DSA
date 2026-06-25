class Solution {
public:
    string add(string a, string b) {
        string res = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';

            res.push_back(sum % 10 + '0');
            carry = sum / 10;
        }

        reverse(res.begin(), res.end());
        return res;
    }

    bool check(string a, string b, int idx, string &num) {
        while (idx < num.size()) {
            string c = add(a, b);

            if (idx + c.size() > num.size())
                return false;

            if (num.substr(idx, c.size()) != c)
                return false;

            idx += c.size();
            a = b;
            b = c;
        }

        return true;
    }

    bool isAdditiveNumber(string num) {
        int n = num.size();

        for (int i = 1; i < n; i++) {

            if (num[0] == '0' && i > 1)
                break;

            string a = num.substr(0, i);

            for (int j = 1; i + j < n; j++) {

                if (num[i] == '0' && j > 1)
                    break;

                string b = num.substr(i, j);

                if (check(a, b, i + j, num))
                    return true;
            }
        }

        return false;
    }
};