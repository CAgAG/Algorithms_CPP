/*************************
 * @file   : func.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/2/15 14
 *************************/

#include "iostream"
#include "string"

using namespace std;

int main() {
    string s1(2, 'k');
    string s2 = "hello";
    cout << s1 << endl;

    // 拼接
    cout << s1 + s2 << endl;
    string s3;
    s3.append(s1);
    cout << s3 << endl;

    // 对比
    cout << s3.compare(s1) << endl;
    cout << (s3 + "o").compare(s1) << endl;  // 此时(s3 + "o") 比 s1 多一个字符 ‘o’

    // 子串
    string s4 = s2.substr(1, 3);  // (开始位置，取几个)
    cout << s4 << endl;

    // 判断为 空
    string s5 = "";
    cout << s5.empty() << endl;

    // 查找
    /* find：从前往后查找子串或字符出现的位置。
     * rfind：从后往前查找子串或字符出现的位置。
     * 只找一次 */
    string s6 = "hello hello";
    cout << s6.find("el") << endl;
    cout << s6.rfind("el") << endl;

    /* find_first_of：从前往后查找何处出现另一个字符串中包含的字符。例如：s1.find_first_of("abc") ==> 查找s1中第一次出现"abc"中任一字符的位置
     * find_last_of：从后往前查找何处出现另一个字符串中包含的字符。
     * find_first_not_of：从前往后查找何处出现另一个字符串中没有包含的字符。
     * find_last_not_of：从后往前查找何处出现另一个字符串中没有包含的字符。
     */

    return 0;
}
