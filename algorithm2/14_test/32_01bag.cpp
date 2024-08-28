/*************************
 * @file   : 32_01bag.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/15 10
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;


int num_length, bag_weight;

int main() {

    while (cin >> num_length >> bag_weight) {
        vector<int> W;
        int wi;
        vector<int> V;
        int vi;
        for (int i = 0; i < num_length; ++i) {
            cin >> wi;
            W.push_back(wi);
        }
        for (int i = 0; i < num_length; ++i) {
            cin >> vi;
            V.push_back(vi);
        }

        vector<int> dp = vector<int>(bag_weight + 1, 0);

        for (int i = 0; i < num_length; ++i) {
            for (int j = bag_weight; j >= W[i]; --j) {
                dp[j] = max(dp[j], dp[j - W[i]] + V[i]);
            }
        }
        cout << dp[bag_weight] << endl;
    }

    return 0;
}