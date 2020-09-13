class Solution {
public:
	int flipgame(vector<int>& fronts, vector<int>& backs) {
		/* 保存非两面都一致的数字 */
		unordered_set<int> dupNums;
		int min = INT_MAX;

		for (int idx = 0; idx < fronts.size(); idx++) {
			/* 正反面相同的数，插入集合 */
			if (fronts[idx] == backs[idx]) {
				dupNums.insert(fronts[idx]);
				continue;
			}
		}

		for (int idx = 0; idx < fronts.size(); idx++) {
			/* 正反面不同的情况下，也要判断之前是否已经插入到了dupNums集合中 */
			if (dupNums.find(fronts[idx]) == end(dupNums)) {
				min = (fronts[idx] < min) ? fronts[idx] : min;
			}

			if (dupNums.find(backs[idx]) == end(dupNums)) {
				min = (backs[idx] < min ? backs[idx] : min);
			}
		}

		return (min % INT_MAX);
	}
};