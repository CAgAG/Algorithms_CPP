/*************************
 * @file   : 51_.cpp
 * @encode : UTF-8
 * @note   : 文本左右对齐 https://leetcode.cn/problems/text-justification/description/?envType=study-plan-v2&envId=top-interview-150
 * @date   : 2024/7/25 09
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {

        vector<string> ret;
        int cur_i = 0;
        int n = words.size();

        while (cur_i < n) {
            int cur_str_len_sum = words[cur_i].size();
            vector<string> ele = {words[cur_i]};

            bool last_ele = false;
            while (cur_str_len_sum <= maxWidth) {
                cur_i++;
                if (cur_i >= n) {
                    last_ele = true;
                    break;
                }
                ele.push_back(words[cur_i]);
                cur_str_len_sum += words[cur_i].size() + 1;
            }
            if (!last_ele) {
                cur_str_len_sum -= ele[ele.size() - 1].size() + 1;
                ele.pop_back();
            }

            if (ele.size() == 1) {
                string ipt = ele[0];
                while (ipt.size() < maxWidth) {
                    ipt += ' ';
                }
                ret.push_back(ipt);
            } else {
                int m = ele.size();
                cur_str_len_sum -= m - 1;
                if (!last_ele) {
                    while (cur_str_len_sum < maxWidth) {
                        for (int i = 0; i < m - 1; ++i) {
                            ele[i] = ele[i] + ' ';
                            cur_str_len_sum++;
                            if (cur_str_len_sum >= maxWidth) {
                                break;
                            }
                        }
                    }
                } else {
                    int last_i = ele.size() - 1;
                    for (int i = 0; i < m - 1; ++i) {
                        ele[i] = ele[i] + ' ';
                        cur_str_len_sum++;
                        if (cur_str_len_sum >= maxWidth) {
                            break;
                        }
                    }

                    while (cur_str_len_sum < maxWidth) {
                        ele[last_i] = ele[last_i] + ' ';
                        cur_str_len_sum++;
                        if (cur_str_len_sum >= maxWidth) {
                            break;
                        }
                    }
                }

                string ipt = "";
                for (int i = 0; i < m; ++i) {
                    ipt += ele[i];
                }
                ret.push_back(ipt);
            }
        }

        return ret;
    }
};

int main() {
    vector<string> nums = {
                           "computer.", "Art", "is", "everything", "else", "we", "do"};
    Solution so;

    for (auto s: so.fullJustify(nums, 16)) {
        cout << s << endl;
    }
    cout << endl;

    return 0;
}
