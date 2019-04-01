/*
 * Store in a 10-length array.
 */
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        else if (x == 0)
            return true;
        
        char a_index[10];
        long base = 1;
        unsigned char maxLength = 0;
        int i = 0;
        
        for (; (i < 10 && x >= base); i++) {
            a_index[i] = x / base % 10;
            base *= 10;
            if (a_index[i])
                maxLength = i + 1;
        }
        
        for (i = 0; i < maxLength / 2; i++) {
            if (a_index[i] != a_index[maxLength - i - 1])
                break;
        }
        
        return (i == maxLength / 2);
    }
};

/*
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        else if (x == 0)
            return true;
        
        int x_copy = x;
        long x_reverse = 0;
        while (x_copy) {
            x_reverse = x_reverse * 10 + x_copy % 10;
            x_copy /= 10;
        }
        
        return (x_reverse == x);
    }
};
*/