---
title: "day_0140 "
date: 2025-09-21T09:43:41+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0140 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Trie:
    def __init__(self):
        self.children = [None] * 26
        self.is_end = False

    def insert(self, word):
        node = self
        for c in word:
            idx = ord(c) - ord('a')
            if node.children[idx] is None:
                node.children[idx] = Trie()
            node = node.children[idx]
        node.is_end = True

    def search(self, word):
        node = self
        for c in word:
            idx = ord(c) - ord('a')
            if node.children[idx] is None:
                return False
            node = node.children[idx]
        return node.is_end


class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        def dfs(s):
            if not s:
                return [[]]
            res = []
            for i in range(1, len(s) + 1):
                if trie.search(s[:i]):
                    for v in dfs(s[i:]):
                        res.append([s[:i]] + v)
            return res

        trie = Trie()
        for w in wordDict:
            trie.insert(w)
        ans = dfs(s)
        return [' '.join(v) for v in ans] 
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

## LeetCode_0140  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Trie:
    def __init__(self):
        self.children = [None] * 26  # 26个字母的子节点数组
        self.is_end = False  # 标记当前节点是否为单词结尾

    def insert(self, word):
        node = self
        for c in word:
            idx = ord(c) - ord('a')  # 计算字符在字母表中的索引
            if node.children[idx] is None:  # 如果子节点不存在
                node.children[idx] = Trie()  # 创建新的Trie节点
            node = node.children[idx]  # 移动到子节点
        node.is_end = True  # 标记单词结尾

    def search(self, word):
        node = self
        for c in word:
            idx = ord(c) - ord('a')  # 计算字符索引
            if node.children[idx] is None:  # 如果子节点不存在
                return False  # 单词不存在
            node = node.children[idx]  # 移动到子节点
        return node.is_end  # 返回是否为完整单词


class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        def dfs(s):
            if not s:  # 如果字符串为空
                return [[]]  # 返回空列表的列表
            res = []
            for i in range(1, len(s) + 1):  # 遍历所有可能的分割点
                if trie.search(s[:i]):  # 如果前缀是字典中的单词
                    for v in dfs(s[i:]):  # 递归处理剩余部分
                        res.append([s[:i]] + v)  # 合并结果
            return res

        trie = Trie()  # 创建Trie树
        for w in wordDict:  # 将字典中的所有单词插入Trie
            trie.insert(w)
        ans = dfs(s)  # 深度优先搜索所有可能的分割方式
        return [' '.join(v) for v in ans]  # 将单词列表转换为空格分隔的字符串
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

## LeetCode_0140  数学解释

```python 
class Trie:
    def __init__(self):
        self.children = [None] * 26
        self.is_end = False

    def insert(self, word):
        node = self
        for c in word:
            idx = ord(c) - ord('a')
            if node.children[idx] is None:
                node.children[idx] = Trie()
            node = node.children[idx]
        node.is_end = True

    def search(self, word):
        node = self
        for c in word:
            idx = ord(c) - ord('a')
            if node.children[idx] is None:
                return False
            node = node.children[idx]
        return node.is_end


class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        def dfs(s):
            if not s:
                return [[]]
            res = []
            for i in range(1, len(s) + 1):
                if trie.search(s[:i]):
                    for v in dfs(s[i:]):
                        res.append([s[:i]] + v)
            return res

        trie = Trie()
        for w in wordDict:
            trie.insert(w)
        ans = dfs(s)
        return [' '.join(v) for v in ans] 
```


这段代码实现了一个基于**字典树(Trie)**和**深度优先搜索(DFS)**的解决方案，用于解决单词拆分问题。

## 数学思想解释：

### 1. **树结构思想 (Tree Structure)**
- **字典树(Trie)**：使用树形结构存储字典，每个节点代表一个字符，路径代表单词
- **空间优化**：通过共享前缀来节省存储空间，具有相同前缀的单词共享路径
- **时间复杂度**：插入和查询操作的时间复杂度为 O(L)，其中 L 是单词长度

### 2. **递归与分治思想 (Recursion & Divide and Conquer)**
- **问题分解**：将长字符串 s 分解为 `s[:i]` 和 `s[i:]` 两个子问题
- **递归关系**：`dfs(s) = 所有可能的 [s[:i]] + dfs(s[i:])` 的组合，其中 s[:i] 是字典中的单词
- **基本情况**：当 s 为空字符串时，返回空列表 [[]]

### 3. **组合数学思想 (Combinatorics)**
- **路径枚举**：DFS 遍历所有可能的单词分割方式
- **解空间构建**：通过递归构建所有有效的单词组合
- **结果生成**：将内部列表结构转换为空格分隔的字符串

### 4. **动态规划思想 (Dynamic Programming) - 隐含**
- **记忆化搜索**：虽然代码中没有显式使用记忆化，但 DFS 的递归结构体现了动态规划的重叠子问题特性
- **最优子结构**：问题的解可以由子问题的解组合而成

## 算法流程：
1. **预处理**：将字典构建为 Trie 树，优化查询效率
2. **递归分割**：对于字符串 s，尝试所有可能的前缀分割
3. **验证与组合**：如果前缀是字典中的单词，递归处理剩余部分并组合结果
4. **结果转换**：将内部列表格式转换为要求的输出格式

这种解法体现了**树结构存储优化**和**递归分治求解**的数学思想，通过合理的数据结构和算法设计高效解决了单词拆分问题。

