---
title: "day_0159 "
date: 2025-09-21T09:10:56+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0159 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def lengthOfLongestSubstringTwoDistinct(self, s: str) -> int:
        cnt = Counter()
        ans = j = 0
        for i, c in enumerate(s):
            cnt[c] += 1
            while len(cnt) > 2:
                cnt[s[j]] -= 1
                if cnt[s[j]] == 0:
                    cnt.pop(s[j])
                j += 1
            ans = max(ans, i - j + 1)
        return ans 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0159  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python 
class Solution:
    def lengthOfLongestSubstringTwoDistinct(self, s: str) -> int:
        cnt = Counter()  # 创建计数器来跟踪字符出现次数
        ans = j = 0  # ans记录最大长度，j是滑动窗口左边界
        for i, c in enumerate(s):  # i是滑动窗口右边界，c是当前字符
            cnt[c] += 1  # 当前字符计数加1
            while len(cnt) > 2:  # 当窗口中字符种类超过2种时
                cnt[s[j]] -= 1  # 左边界字符计数减1
                if cnt[s[j]] == 0:  # 如果该字符计数归零
                    cnt.pop(s[j])  # 从计数器中移除该字符
                j += 1  # 左边界右移
            ans = max(ans, i - j + 1)  # 更新最大长度
        return ans  # 返回结果
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0159  数学解释

```python 
class Solution:
    def lengthOfLongestSubstringTwoDistinct(self, s: str) -> int:
        cnt = Counter()
        ans = j = 0
        for i, c in enumerate(s):
            cnt[c] += 1
            while len(cnt) > 2:
                cnt[s[j]] -= 1
                if cnt[s[j]] == 0:
                    cnt.pop(s[j])
                j += 1
            ans = max(ans, i - j + 1)
        return ans 
```


这段代码使用了**滑动窗口（Sliding Window）**和**哈希表（Hash Table）**的数学思想来解决最长最多包含两个不同字符的子串问题。

## 数学思想解析：

### 1. 滑动窗口（双指针）
- 维护一个窗口 `[j, i]`，其中 `j` 是左指针，`i` 是右指针
- 窗口内的子串始终满足条件（最多包含两个不同字符）
- 当条件被破坏时（出现第三个不同字符），移动左指针 `j` 来收缩窗口

### 2. 哈希表计数
- 使用 `Counter`（哈希表）来记录窗口中每个字符的出现次数
- 当某个字符计数降为0时，从哈希表中移除该字符
- `len(cnt)` 表示当前窗口中不同字符的数量

### 3. 贪心思想
- 每次右指针 `i` 向右移动扩展窗口
- 当条件不满足时，尽可能少地移动左指针 `j`（只移动到刚好满足条件为止）
- 这样能保证找到以每个位置结尾的最长有效子串

## 时间复杂度分析：
- 每个字符最多被访问两次（右指针一次，左指针一次）
- 时间复杂度：O(n)，其中 n 是字符串长度
- 空间复杂度：O(1)，因为最多只存储3个键值对（即使字符串很长）

这种解法巧妙地运用了滑动窗口和哈希表的组合，在O(n)时间内高效解决了问题。

