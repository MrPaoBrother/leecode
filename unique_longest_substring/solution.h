
#include <iostream>
#include <map>
using namespace std;
/*
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 */
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        map<char, int> filterMap;
        int ans = 0;
        for (int i=0, j = 0; j < s.length(); j++)
        {
            if (filterMap.find(s[j]) != filterMap.end())
            {
                i = max(filterMap[s[j]], i);
            }
            ans = max(ans, j - i + 1);
            filterMap[s[j]] = j + 1;
        }
        return ans;
    }
};