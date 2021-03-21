class Solution {
public:
    int smallestFactorization(int a) {
        if (a <= 9) {
            return a;
        }

        string res = "";
        string tmp = "";
        for (int i = 9; i > 1; i--) {
            while (!(a % i)) {
                tmp = to_string('0' + i);
                res = tmp + res;
                a /= i;
            }
        }

        return atoll(res.c_str()) > INT_MAX ? 0 : atoi(res.c_str());
    }
};
