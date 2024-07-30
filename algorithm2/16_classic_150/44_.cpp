/*************************
 * @file   : 44_.cpp
 * @encode : UTF-8
 * @note   : 查找和最小的 K 对数字 https://leetcode.cn/problems/find-k-pairs-with-smallest-sums/description/?envType=study-plan-v2&envId=top-interview-150
 * @date   : 2024/7/21 11
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"

using namespace std;

class Solution {
public:
    // 输入的数组是有序的
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> ans;
        priority_queue<tuple<int, int, int>> pq;
        // 初始化
        for (int i = 0; i < min(n, k); i++) { // 至多 k 个
            // nums2 的最小值 与 nums1的最小 -> 最大, 配对
            pq.emplace(-nums1[i] - nums2[0], i, 0); // 取相反数变成小顶堆
        }
        while (ans.size() < k) {
            auto [_, i, j] = pq.top();
            pq.pop();
            ans.push_back({nums1[i], nums2[j]});
            // 换句话说，在 (i,j) 出堆时，只需将 (i,j+1) 入堆，无需将 (i+1,j) 入堆。
            if (j + 1 < m) {
                pq.emplace(-nums1[i] - nums2[j + 1], i, j + 1);
            }
        }
        return ans;
    }
};


int main() {
    vector<int> nums1 = {1, 1, 2}, nums2 = {1, 2, 3};
    int k = 2;

    Solution so;
    for (auto cs: so.kSmallestPairs(nums1, nums2, k)) {
        for (auto c: cs) {
            cout << c << " ";
        }
        cout << endl;
    }
    return 0;
}