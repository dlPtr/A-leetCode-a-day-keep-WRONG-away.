/*
公司里有 n 名员工，每个员工的 ID 都是独一无二的，编号从 0 到 n - 1。公司的总负责人通过 headID 进行标识。

在 manager 数组中，每个员工都有一个直属负责人，其中 manager[i] 是第 i 名员工的直属负责人。对于总负责人，manager[headID] = -1。题目保证从属关系可以用树结构显示。

公司总负责人想要向公司所有员工通告一条紧急消息。他将会首先通知他的直属下属们，然后由这些下属通知他们的下属，直到所有的员工都得知这条紧急消息。

第 i 名员工需要 informTime[i] 分钟来通知它的所有直属下属（也就是说在 informTime[i] 分钟后，他的所有直属下属都可以开始传播这一消息）。

返回通知所有员工这一紧急消息所需要的 分钟数 。

示例 1：

输入：n = 1, headID = 0, manager = [-1], informTime = [0]
输出：0
解释：公司总负责人是该公司的唯一一名员工。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/time-needed-to-inform-all-employees
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:

	int get_max_time_dfs(int idx, vector<int>& informTime) {
		int max_time = 0;

		for (auto each : tree[idx]) {
			max_time = max(max_time, get_max_time_dfs(each, informTime));
		}

		return max_time + informTime[idx];
	}

	int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
		int idx = 0;

		/* 初始化 */
		tree = vector<vector<int>>(n);
		for (; idx < n; idx++) {
			/* boss没有上级，不需要保存管理关系 */
			if (idx == headID) {
				continue;
			}

			/* 记录下每个员工的管理者与其之间的关系 */
			tree[manager[idx]].push_back(idx);
		}

		return get_max_time_dfs(headID, informTime);
	}

private:
	vector<vector<int>> tree;
};