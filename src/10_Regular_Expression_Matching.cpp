class Solution {
public:
    bool isMatch(string s, string p) {
        // 1：当p为空时，若s为空则true，否之为false
        if (p.empty()) return s.empty();
        
        // 2：当p长度为1时，若s长度为1且可匹配时则为true，否之为false
        if (p.size() == 1) {
            return (s.size() == 1 && (s[0] == p[0] || p[0] == '.'));
        }
        
        // 3.1：当p的第二个字符不为通配符时，则要判断第一个字符是否相等，如果不相等则显然是
        //  不匹配的；如果匹配则可以除掉第一个字符的影响，递归调用自己。
        if (p[1] != '*') {
            if (s.empty()) return false;
            return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
        }
        
        // 3.4：当p的第二个字符为通配符时，则要根据情况，逐一根据通配符匹配前面字符的次数去调用自己，
        //  如果匹配上就是true，均匹配不上就会执行到最后面的return false了。
        if (isMatch(s, p.substr(2)))
            return true;
        else {
            while (!s.empty() && (s[0] == p[0] || p[0] == '.')) {
                s = s.substr(1);
                if (isMatch(s, p.substr(2)))
                    return true;
            }
        }
        
        // 前面的情况均匹配失败了
        return false;
    }
};