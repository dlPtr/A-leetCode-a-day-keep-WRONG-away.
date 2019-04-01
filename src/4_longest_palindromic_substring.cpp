class Solution {
public:
	string longestPalindrome(string s) {
		if (s.size() <= 1) {
			return s;
		}

		
		int s_len = s.size();
		int start = 0;
		int max = 1;

		/* Can't use bool dp[1000][1000] (Too long..) */
        vector<vector<bool> > dp(s_len,vector<bool>(s_len));

		/* Init */
		for (int i = 0; i < s_len - 1; i++) {
			dp[i][i] = 1;
			if (s[i] == s[i + 1]) {
				dp[i][i + 1] = true;
				start = i;
				max = 2;
			}
		}
		dp[s_len - 1][s_len - 1] = true;

		/* 根据子串长度来遍历 */
		for (int l = 3; l <= s_len; l++) {
			for (int i = 0; i < s_len - l + 1; i++) {
				if (s[i] == s[i + l - 1] && dp[i + 1][i + l - 2] == true) {
					dp[i][i + l - 1] = true;
					max = l;
					start = i;
				}
			}
		}

		return s.substr(start, max);
	}
};