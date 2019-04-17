class Solution {
public:
    int reverse(int x) {
    	long long tmp = 0;
    	while (x) {
    		tmp = tmp * 10 + x % 10;
    		x /= 10;
    	}

    	return (tmp > INT_MAX || tmp < INT_MIN) ? 0 : tmp;
    }
};