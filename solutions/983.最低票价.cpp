/*
 * @lc app=leetcode.cn id=983 lang=cpp
 *
 * [983] 最低票价
 */

// @lc code=start
// 先用题解mark之后细细研究
class Solution {
    unordered_set<int> dayset;
    vector<int> costs;
    int memo[366] = {0};
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        this->costs = costs;
        for (int d: days) {
            dayset.insert(d);
        }
        memset(memo, -1, sizeof(memo));
        return dp(1);
    }
    int dp(int i) {
        if (i > 365) {
            return 0;
        }
        if (memo[i] != -1) {
            return memo[i];
        }
        if (dayset.count(i)) {
            memo[i] = min(min(dp(i + 1) + costs[0], dp(i + 7) + costs[1]), dp(i + 30) + costs[2]);
        }
        else {
            memo[i] = dp(i + 1);
        }
        return memo[i];
    }

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/minimum-cost-for-tickets/solution/zui-di-piao-jie-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    
};
// @lc code=end

