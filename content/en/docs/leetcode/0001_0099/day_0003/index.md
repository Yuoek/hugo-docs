---
title: "day_0003 "
date: 2025-09-14T11:44:51+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0003 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        cnt = Counter()
        ans = l = 0
        for r, c in enumerate(s):
            cnt[c] += 1
            while cnt[c] > 1:
                cnt[s[l]] -= 1
                l += 1
            ans = max(ans, r - l + 1)
        return ans 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int cnt[128]{};
        int ans = 0, n = s.size();
        for (int l = 0, r = 0; r < n; ++r) {
            ++cnt[s[r]];
            while (cnt[s[r]] > 1) {
                --cnt[s[l++]];
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int[] cnt = new int[128];
        int ans = 0, n = s.length();
        for (int l = 0, r = 0; r < n; ++r) {
            char c = s.charAt(r);
            ++cnt[c];
            while (cnt[c] > 1) {
                --cnt[s.charAt(l++)];
            }
            ans = Math.max(ans, r - l + 1);
        }
        return ans;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0003  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python 
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        cnt = Counter()  # 创建计数器，用于统计字符出现次数
        ans = l = 0  # ans记录最长子串长度，l是滑动窗口左边界
        for r, c in enumerate(s):  # 遍历字符串，r是右边界，c是当前字符
            cnt[c] += 1  # 当前字符计数加1
            while cnt[c] > 1:  # 如果当前字符重复出现
                cnt[s[l]] -= 1  # 左边界字符计数减1
                l += 1  # 左边界右移
            ans = max(ans, r - l + 1)  # 更新最大长度
        return ans  # 返回结果
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int cnt[128]{};
        int ans = 0, n = s.size();
        for (int l = 0, r = 0; r < n; ++r) {
            ++cnt[s[r]];
            while (cnt[s[r]] > 1) {
                --cnt[s[l++]];
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int[] cnt = new int[128];
        int ans = 0, n = s.length();
        for (int l = 0, r = 0; r < n; ++r) {
            char c = s.charAt(r);
            ++cnt[c];
            while (cnt[c] > 1) {
                --cnt[s.charAt(l++)];
            }
            ans = Math.max(ans, r - l + 1);
        }
        return ans;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0003  数学解释

```python 
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        cnt = Counter()
        ans = l = 0
        for r, c in enumerate(s):
            cnt[c] += 1
            while cnt[c] > 1:
                cnt[s[l]] -= 1
                l += 1
            ans = max(ans, r - l + 1)
        return ans 
```


这段代码使用了**滑动窗口（双指针）** 的数学思想来解决最长无重复字符子串问题：

## 核心数学思想：
1. **集合与计数**：使用哈希表（Counter）记录窗口中每个字符的出现次数
2. **滑动窗口优化**：通过左右指针维护一个无重复字符的连续子串

## 数学原理：
- **窗口不变式**：保证窗口 [l, r] 内的所有字符都是唯一的（cnt[c] ≤ 1）
- **单调性**：右指针 r 单调向右移动，左指针 l 在需要时向右移动（不会回退）
- **最优子结构**：当前窗口是以 r 结尾的最长无重复子串

## 算法步骤：
1. 右指针 r 向右扩展，增加字符计数
2. 当某个字符计数 >1（出现重复）时，左指针 l 向右收缩，直到消除重复
3. 每次更新最大窗口长度 ans = max(ans, r-l+1)

## 时间复杂度：O(n)
- 每个字符最多被左右指针各访问一次
- 虽然内层有 while 循环，但总体是线性时间复杂度

这种解法体现了**贪心思想**和**双指针技巧**的完美结合，通过维护一个合法的滑动窗口来高效解决问题。


