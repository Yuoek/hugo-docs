---
title: "day_0049 "
date: 2025-09-14T10:09:02+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0049 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d = defaultdict(list)
        for s in strs:
            k = ''.join(sorted(s))
            d[k].append(s)
        return list(d.values()) 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> d;
        for (auto& s : strs) {
            string k = s;
            sort(k.begin(), k.end());
            d[k].emplace_back(s);
        }
        vector<vector<string>> ans;
        for (auto& [_, v] : d) ans.emplace_back(v);
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> d = new HashMap<>();
        for (String s : strs) {
            char[] t = s.toCharArray();
            Arrays.sort(t);
            String k = String.valueOf(t);
            d.computeIfAbsent(k, key -> new ArrayList<>()).add(s);
        }
        return new ArrayList<>(d.values());
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0049  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d = defaultdict(list)  # 创建默认值为列表的字典
        for s in strs:  # 遍历字符串列表中的每个字符串
            k = ''.join(sorted(s))  # 将字符串排序后重新组合作为键
            d[k].append(s)  # 将原字符串添加到对应键的列表中
        return list(d.values())  # 返回字典中所有值组成的列表
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> d;
        for (auto& s : strs) {
            string k = s;
            sort(k.begin(), k.end());
            d[k].emplace_back(s);
        }
        vector<vector<string>> ans;
        for (auto& [_, v] : d) ans.emplace_back(v);
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> d = new HashMap<>();
        for (String s : strs) {
            char[] t = s.toCharArray();
            Arrays.sort(t);
            String k = String.valueOf(t);
            d.computeIfAbsent(k, key -> new ArrayList<>()).add(s);
        }
        return new ArrayList<>(d.values());
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0049  数学解释

```python 
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d = defaultdict(list)
        for s in strs:
            k = ''.join(sorted(s))
            d[k].append(s)
        return list(d.values()) 
```

这段代码使用了**哈希映射**的数学思想来解决字母异位词分组问题。

数学原理分析：
1. **等价关系**：字母异位词之间构成等价关系（自反、对称、传递）
2. **规范化表示**：通过排序将每个单词转换为规范形式（按字母顺序排列的字符串）
3. **哈希函数**：使用排序后的字符串作为哈希键，将具有相同规范形式的单词映射到同一分组

数学特性：
- **确定性**：相同的输入总是产生相同的哈希键
- **完备性**：所有字母异位词都会映射到相同的哈希键
- **区分性**：非字母异位词会映射到不同的哈希键

时间复杂度分析：
设n为单词数量，m为平均单词长度
- 排序每个单词：O(m log m)
- 总体复杂度：O(n × m log m)

空间复杂度：O(n × m)（存储所有单词）

这种解法巧妙地利用了数学上的等价类划分思想，通过规范化表示将问题转化为简单的哈希映射问题。


