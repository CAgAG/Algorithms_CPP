/*************************
 * @file   : 9_split_candy.cpp
 * @encode : UTF-8
 * @note   : 分发糖果 https://leetcode.cn/problems/candy/description/
 * @date   : 2024/4/14 22
 *************************/
// 评分相等可以不管给多给少糖果

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

// 每个孩子至少分配到 1 个糖果。
// 相邻的孩子中，评分高的孩子必须获得更多的糖果。

class Solution {
public:
    int candy(vector<int> &ratings) {
        vector<int> candy(ratings.size(), 1);

        // 右边评分大于左边的情况
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candy[i] = candy[i - 1] + 1;
            }
        }

        // 左孩子大于右孩子的情况（从后向前遍历: 因为 rating[5]与rating[4]的比较 要利用上 rating[5]与rating[6]的比较结果）
        for (int i = ratings.size() - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                /* 如果 ratings[i] > ratings[i + 1]，此时candyVec[i]（第i个小孩的糖果数量）就有两个选择了，
                 * 一个是candyVec[i + 1] + 1（从右边这个加1得到的糖果数量），注意这个结果不一定满足第二个条件
                 * 一个是candyVec[i]（之前比较右孩子大于左孩子得到的糖果数量）。 其实就是服从第一轮的分配
                 */
                // 局部最优：取candyVec[i + 1] + 1 和 candyVec[i] 最大的糖果数量，保证第i个小孩的糖果数量既大于左边的也大于右边的
                candy[i] = max(candy[i + 1] + 1, candy[i]);
            }
        }


        int ret = 0;
        for (int i = 0; i < candy.size(); ++i) {
            ret += candy[i];
        }
        return ret;
    }
};

int main() {
    vector<int> ratings = {1, 3, 4, 5, 2};

    Solution so;
    cout << so.candy(ratings) << endl;

    return 0;
}