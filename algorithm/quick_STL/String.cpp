#include "iostream"
#include "string"
#include "cstring"
#include "cstdlib"

using namespace std;

/* cstring
 * strlen() 字符串长度
 * strcmp() 字符串比较
 * strcpy() 字符串拷贝
 *
 * memset() 通过赋值暴力清空
 * memcpy() 暴力拷贝
 */

/* string 可以看成是 vector<char>
 * 详细函数可以参考 vector
 * .append() 拼接字符串(字符)  操作运算符: +=
 * .compare() 相当于 strcmp() 字符串比较  操作运算符: ==
 * .replace() 替换
 * .insert() 插入
 */

int main() {

    // 在C++中将字符串（str）转换为字符数组可以使用std::string类的成员函数.c_str()
    string str = "hello";
    char str2[]  = "world";

    str.push_back(',');
    str.append(str2);
    cout << str << " " << sizeof(str.c_str()) << " " << str.size() << endl;
    memset((void *) str.c_str(), 0, str.size());
    cout << str << endl;

    /* string& replace(size_t pos, size_t len, const string& str);
        从位置pos开始，替换长度为len的子串为str。
     * string& replace(size_t pos, size_t len, const char* s);
        从位置pos开始，替换长度为len的子串为字符数组s。
     * string& replace(size_t pos, size_t len, size_t n, char c);
        从位置pos开始，替换长度为len的子串为n个字符c。
     * string& replace(iterator first, iterator last, const string& str);
        用str替换[first, last)范围内的子串。
     * string& replace(iterator first, iterator last, const char* s);
        用字符数组s替换[first, last)范围内的子串。
     * string& replace(iterator first, iterator last, const char* s, size_t n);
        用字符数组s的前n个字符替换[first, last)范围内的子串。
     * string& replace(iterator first, iterator last, size_t n, char c);
        用n个字符c替换[first, last)范围内的子串。
     */
    str = "hello";
    string str3 = str.replace(str.begin(), str.begin() + 2, "p");
    cout << str3 << endl;

    return 0;
}