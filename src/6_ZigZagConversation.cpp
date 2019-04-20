/*
 * 思路:(把zig zag画成V形状，然后遍历行，每次处理一行所有的字符)
 * X     X     X
 *  P   S R   X X
 *   X X   X X   X
 *    X     X
 * 1、确定步长(步长即跳到同一行下一个对称点或者重复点的距离)
 *     1.1 对称点(P 的对称点为 S)步长为 stepSymme  = 2 * (numRows - i).
 *     1.2 重复点(P 的重复点为 R)步长为 stepRepeat = 2 * (numRows - 1).
 * 2、找到这一行对应的字符
 *     2.1 根据步长算出各点位置
 *     2.2 判断这个位置上的字符是否有效
 *         2.2.1 是否为V的头和尾
 *         2.2.2 这个点是否有字符
 * 3、加入 retStr
 */
class Solution {
public:
    string convert(string src, int numRows) {
        int srcLen = src.length();

        /* Actually I'm thinking we shoule return what when para is illegal! */
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