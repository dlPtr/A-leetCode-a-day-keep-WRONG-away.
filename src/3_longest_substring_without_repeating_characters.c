int lengthOfLongestSubstring(char* s) {
    int cLastPos[256] = {-1};
    memset(cLastPos, -1, sizeof(cLastPos)); /* Cause -1 is 0xffffffff */
    
    int maxLength = 0;
    int length = strlen(s);
    int suffix = -1; /* 第一个重复的字符的下标 */
    #define MAX(MAX_I, MAX_J)   ((MAX_I) > (MAX_J) ? (MAX_I) : (MAX_J))
    for (int i = 0; i < length; i++) {
        suffix = MAX(suffix, cLastPos[s[i]]);
        maxLength = MAX(maxLength, i - suffix);
        cLastPos[s[i]] = i;
    }
    
    return maxLength;
}