/*************************
 * @file   : hash.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/2/15 15
 *************************/

/* 给定一个模式串t。给定Q组询问，每组询问给定一个待匹配串s。对于每组询问，分别回答给定的待匹配串s是否包含串t作为子串。 */

#include <iostream>
#include <string>
#include <functional>

using namespace std;

bool containsSubstring(const string& s, const string& t) {
    hash<string> hash_fn;
    size_t hash_t = hash_fn(t);
    int s_len = s.size();
    int t_len = t.size();

    for (int i = 0; i < s_len - t_len; ++i) {
        string sub_s = s.substr(i, t_len);
        size_t hash_sub_s = hash_fn(sub_s);
        if (hash_sub_s == hash_t) {
            return true;
        }
    }

    return false;
}

int main() {
    string t = "world";
    string s = "hello, world, dlorw";
    if (containsSubstring(s, t)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
