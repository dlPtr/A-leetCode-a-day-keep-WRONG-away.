int lengthOfLongestSubstring(char* s) {
    int charLastPos[256] = {-1};
    int maxLength = 0;
    int length = strlen(s);
    int suffix = 0;
    #define MAX(MAX_I, MAX_J)   ((MAX_I) > (MAX_J) ? (MAX_I) : (MAX_J))
    for (int i = 0; i < length; i++) {
        suffix = MAX(suffix, charLastPos[s[i]] + 1);
        maxLength = MAX(maxLength, i - suffix);
        charLastPos[s[i]] = i;
    }
    
    return maxLength + 1;
}