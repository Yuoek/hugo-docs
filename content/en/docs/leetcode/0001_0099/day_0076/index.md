---
title: "day_0076 "
date: 2025-09-14T08:46:10+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0076 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        need = Counter(t)
        window = Counter()
        cnt = l = 0
        k, mi = -1, inf
        for r, c in enumerate(s):
            window[c] += 1
            if need[c] >= window[c]:
                cnt += 1
            while cnt == len(t):
                if r - l + 1 < mi:
                    mi = r - l + 1
                    k = l
                if need[s[l]] >= window[s[l]]:
                    cnt -= 1
                window[s[l]] -= 1
                l += 1
        return "" if k < 0 else s[k : k + mi] 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128, 0);
        vector<int> window(128, 0);
        for (char c : t) {
            ++need[c];
        }

        int m = s.length(), n = t.length();
        int k = -1, mi = m + 1, cnt = 0;

        for (int l = 0, r = 0; r < m; ++r) {
            char c = s[r];
            if (++window[c] <= need[c]) {
                ++cnt;
            }

            while (cnt == n) {
                if (r - l + 1 < mi) {
                    mi = r - l + 1;
                    k = l;
                }

                c = s[l];
                if (window[c] <= need[c]) {
                    --cnt;
                }
                --window[c];
                ++l;
            }
        }

        return k < 0 ? "" : s.substr(k, mi);
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public String minWindow(String s, String t) {
        int[] need = new int[128];
        int[] window = new int[128];
        for (char c : t.toCharArray()) {
            ++need[c];
        }
        int m = s.length(), n = t.length();
        int k = -1, mi = m + 1, cnt = 0;
        for (int l = 0, r = 0; r < m; ++r) {
            char c = s.charAt(r);
            if (++window[c] <= need[c]) {
                ++cnt;
            }
            while (cnt == n) {
                if (r - l + 1 < mi) {
                    mi = r - l + 1;
                    k = l;
                }
                c = s.charAt(l);
                if (window[c] <= need[c]) {
                    --cnt;
                }
                --window[c];
                ++l;
            }
        }
        return k < 0 ? "" : s.substring(k, k + mi);
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0076  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        need = Counter(t)  # 统计目标字符串t中每个字符的出现次数
        window = Counter()  # 创建滑动窗口的字符计数器
        cnt = l = 0  # cnt: 当前窗口中满足t要求的字符数量, l: 窗口左指针
        k, mi = -1, inf  # k: 最小窗口起始位置, mi: 最小窗口长度
        
        # 遍历字符串s，r为右指针，c为当前字符
        for r, c in enumerate(s):
            window[c] += 1  # 将当前字符加入窗口计数
            
            # 如果当前字符在t中，且窗口中的数量不超过t中的需求数量
            if need[c] >= window[c]:
                cnt += 1  # 增加满足条件的字符计数
            
            # 当窗口中包含t的所有字符时，尝试收缩左边界
            while cnt == len(t):
                # 如果当前窗口比之前记录的最小窗口更小
                if r - l + 1 < mi:
                    mi = r - l + 1  # 更新最小窗口长度
                    k = l  # 记录最小窗口的起始位置
                
                # 如果左边界字符是t中的必需字符
                if need[s[l]] >= window[s[l]]:
                    cnt -= 1  # 减少满足条件的字符计数
                
                window[s[l]] -= 1  # 从窗口中移除左边界字符
                l += 1  # 左指针右移
        
        # 如果找到有效窗口则返回子串，否则返回空字符串
        return "" if k < 0 else s[k : k + mi] 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128, 0);
        vector<int> window(128, 0);
        for (char c : t) {
            ++need[c];
        }

        int m = s.length(), n = t.length();
        int k = -1, mi = m + 1, cnt = 0;

        for (int l = 0, r = 0; r < m; ++r) {
            char c = s[r];
            if (++window[c] <= need[c]) {
                ++cnt;
            }

            while (cnt == n) {
                if (r - l + 1 < mi) {
                    mi = r - l + 1;
                    k = l;
                }

                c = s[l];
                if (window[c] <= need[c]) {
                    --cnt;
                }
                --window[c];
                ++l;
            }
        }

        return k < 0 ? "" : s.substr(k, mi);
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public String minWindow(String s, String t) {
        int[] need = new int[128];
        int[] window = new int[128];
        for (char c : t.toCharArray()) {
            ++need[c];
        }
        int m = s.length(), n = t.length();
        int k = -1, mi = m + 1, cnt = 0;
        for (int l = 0, r = 0; r < m; ++r) {
            char c = s.charAt(r);
            if (++window[c] <= need[c]) {
                ++cnt;
            }
            while (cnt == n) {
                if (r - l + 1 < mi) {
                    mi = r - l + 1;
                    k = l;
                }
                c = s.charAt(l);
                if (window[c] <= need[c]) {
                    --cnt;
                }
                --window[c];
                ++l;
            }
        }
        return k < 0 ? "" : s.substring(k, k + mi);
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0076  数学解释

```python 
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        need = Counter(t)
        window = Counter()
        cnt = l = 0
        k, mi = -1, inf
        for r, c in enumerate(s):
            window[c] += 1
            if need[c] >= window[c]:
                cnt += 1
            while cnt == len(t):
                if r - l + 1 < mi:
                    mi = r - l + 1
                    k = l
                if need[s[l]] >= window[s[l]]:
                    cnt -= 1
                window[s[l]] -= 1
                l += 1
        return "" if k < 0 else s[k : k + mi] 
```


这段代码使用了**滑动窗口**和**哈希表**的数学思想来解决最小覆盖子串问题。

## 核心数学思想：

1. **滑动窗口（双指针）**
   - 使用左右指针l和r维护一个动态窗口
   - 右指针r扩展窗口，左指针l收缩窗口
   - 时间复杂度：O(n)，每个元素最多被访问两次

2. **哈希表计数**
   - `need`：记录目标字符串t中每个字符的需求量
   - `window`：记录当前窗口中每个字符的数量
   - 通过比较两个哈希表来判断窗口是否满足条件

3. **有效字符计数策略**
   - `cnt`变量记录当前窗口中满足t需求的字符总数
   - 只有当`window[c] ≤ need[c]`时，增加cnt（避免重复计数）
   - 这种计数方式确保了数学上的准确性

## 数学原理：

设窗口为s[l:r+1]，算法保证：
- 当cnt = len(t)时，窗口包含t的所有字符
- 通过收缩左边界寻找最小满足条件的窗口
- 使用mi记录最小窗口长度，k记录最小窗口起始位置

## 算法步骤：
1. 右指针扩展窗口，更新字符计数
2. 当窗口满足条件时，尝试收缩左边界
3. 记录最小窗口的位置和长度
4. 返回最小窗口子串

这种方法的数学优雅性在于它通过巧妙的计数和双指针移动，高效地找到了最优解。


