---
title: "day_0187 "
date: 2025-09-21T08:12:13+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0187 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        cnt = Counter()
        ans = []
        for i in range(len(s) - 10 + 1):
            t = s[i : i + 10]
            cnt[t] += 1
            if cnt[t] == 2:
                ans.append(t)
        return ans 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> cnt;
        vector<string> ans;
        for (int i = 0, n = s.size() - 10 + 1; i < n; ++i) {
            auto t = s.substr(i, 10);
            if (++cnt[t] == 2) {
                ans.emplace_back(t);
            }
        }
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        Map<String, Integer> cnt = new HashMap<>();
        List<String> ans = new ArrayList<>();
        for (int i = 0; i < s.length() - 10 + 1; ++i) {
            String t = s.substring(i, i + 10);
            if (cnt.merge(t, 1, Integer::sum) == 2) {
                ans.add(t);
            }
        }
        return ans;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0187  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        cnt = Counter()  # 创建计数器用于统计DNA序列出现次数
        ans = []  # 存储结果列表
        for i in range(len(s) - 10 + 1):  # 遍历所有可能的10个字符长度的子串
            t = s[i : i + 10]  # 提取当前位置开始的10个字符DNA序列
            cnt[t] += 1  # 该序列计数加1
            if cnt[t] == 2:  # 当序列第二次出现时（避免重复添加）
                ans.append(t)  # 添加到结果列表中
        return ans  # 返回所有重复出现的DNA序列
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> cnt;
        vector<string> ans;
        for (int i = 0, n = s.size() - 10 + 1; i < n; ++i) {
            auto t = s.substr(i, 10);
            if (++cnt[t] == 2) {
                ans.emplace_back(t);
            }
        }
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        Map<String, Integer> cnt = new HashMap<>();
        List<String> ans = new ArrayList<>();
        for (int i = 0; i < s.length() - 10 + 1; ++i) {
            String t = s.substring(i, i + 10);
            if (cnt.merge(t, 1, Integer::sum) == 2) {
                ans.add(t);
            }
        }
        return ans;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0187  数学解释

```python 
class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        cnt = Counter()
        ans = []
        for i in range(len(s) - 10 + 1):
            t = s[i : i + 10]
            cnt[t] += 1
            if cnt[t] == 2:
                ans.append(t)
        return ans 
```


这段代码使用了**滑动窗口**和**哈希计数**的数学思想：

1. **滑动窗口思想**：
   - 窗口大小为10（DNA序列长度）
   - 通过循环 `for i in range(len(s) - 10 + 1)` 让窗口在字符串上滑动
   - 每次提取窗口内的子串 `s[i : i + 10]`

2. **哈希计数思想**：
   - 使用 `Counter()` 作为哈希表记录每个10字符序列的出现次数
   - 当某个序列第二次出现时（`cnt[t] == 2`），将其加入结果列表
   - 这样避免了重复添加同一序列多次

3. **数学优化**：
   - 只在计数等于2时添加，确保结果中每个重复序列只出现一次
   - 时间复杂度：O(n)，其中n为字符串长度
   - 空间复杂度：O(n)，最坏情况下需要存储所有不同的10字符序列

这种解法通过滑动窗口遍历所有可能的10字符子串，并用哈希表高效统计重复情况，是处理这类"固定长度子串重复检测"问题的典型方法。

