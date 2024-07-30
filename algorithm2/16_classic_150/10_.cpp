/*************************
 * @file   : 10_.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/7/8 16
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;


class Solution {
public:
    int hIndex(vector<int> &citations) {
        int ret = 0;
        sort(citations.begin(), citations.end());

        int n = citations.size();
        for (int i = n - 1; i >= 0; --i) {
            int in_ = n - i;
            int out_ = n - in_;
            int h = citations[i];

            if (h >= in_) {
                ret = max(ret, in_);
            }
        }

        return ret;
    }
};

int main() {
    vector<int> nums = {3, 0, 6, 1, 5};

    Solution so;
    cout << so.hIndex(nums) << endl;

    return 0;
}