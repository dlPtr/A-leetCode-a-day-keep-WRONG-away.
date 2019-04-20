class Solution {
public:
    string convert(string src, int numRows) {
        int srcLen = src.length();

        if (0 == srcLen || numRows <= 0) {
            return src;
        }
        if (srcLen <= 2 || numRows == 1) {
            return src;
        }

        string retStr;
        for (int i = 1; i <= numRows; i++) {
            int stepRepeat = 2 * (numRows - 1);
            int stepSymme  = 2 * (numRows - i);

            for (int j = 0; (i + j * stepRepeat) <= srcLen; j++) {
                int base_i = i + j * stepRepeat;
                /* Add this character into retStr first(This is valid via for check) */
                retStr.append(1, src[base_i - 1]);

                /* Add symmetrical value and Note that boundary value no symmetrical value */
                if (1 == i || numRows == i) {
                    continue;
                }
                /* Check if valid */
                else if (base_i + stepSymme <= srcLen){
                    retStr.append(1, src[base_i + stepSymme - 1]);
                }
            }

        }
        return retStr;
    }
};