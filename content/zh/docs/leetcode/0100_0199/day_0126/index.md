---
title: "day_0126 "
date: 2025-09-21T10:09:32+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0126 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def findLadders(
        self, beginWord: str, endWord: str, wordList: List[str]
    ) -> List[List[str]]:
        def dfs(path, cur):
            if cur == beginWord:
                ans.append(path[::-1])
                return
            for precursor in prev[cur]:
                path.append(precursor)
                dfs(path, precursor)
                path.pop()

        ans = []
        words = set(wordList)
        if endWord not in words:
            return ans
        words.discard(beginWord)
        dist = {beginWord: 0}
        prev = defaultdict(set)
        q = deque([beginWord])
        found = False
        step = 0
        while q and not found:
            step += 1
            for i in range(len(q), 0, -1):
                p = q.popleft()
                s = list(p)
                for i in range(len(s)):
                    ch = s[i]
                    for j in range(26):
                        s[i] = chr(ord('a') + j)
                        t = ''.join(s)
                        if dist.get(t, 0) == step:
                            prev[t].add(p)
                        if t not in words:
                            continue
                        prev[t].add(p)
                        words.discard(t)
                        q.append(t)
                        dist[t] = step
                        if endWord == t:
                            found = True
                    s[i] = ch
        if found:
            path = [endWord]
            dfs(path, endWord)
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

## LeetCode_0126  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def findLadders(
        self, beginWord: str, endWord: str, wordList: List[str]
    ) -> List[List[str]]:
        def dfs(path, cur):  # 深度优先搜索构建路径
            if cur == beginWord:  # 如果当前单词等于起始单词
                ans.append(path[::-1])  # 将反转后的路径加入结果
                return
            for precursor in prev[cur]:  # 遍历当前单词的前驱单词
                path.append(precursor)  # 将前驱加入路径
                dfs(path, precursor)  # 递归搜索
                path.pop()  # 回溯

        ans = []  # 存储所有最短转换序列
        words = set(wordList)  # 将单词列表转为集合便于查找
        if endWord not in words:  # 如果结束单词不在单词列表中
            return ans  # 直接返回空结果
        words.discard(beginWord)  # 移除起始单词
        dist = {beginWord: 0}  # 记录每个单词到起始单词的最短距离
        prev = defaultdict(set)  # 记录每个单词的前驱单词集合
        q = deque([beginWord])  # 初始化队列
        found = False  # 标记是否找到结束单词
        step = 0  # 当前步数
        while q and not found:  # BFS搜索
            step += 1  # 步数增加
            for i in range(len(q), 0, -1):  # 遍历当前层的所有单词
                p = q.popleft()  # 取出队列中的单词
                s = list(p)  # 将单词转为字符列表便于修改
                for i in range(len(s)):  # 遍历单词的每个字符位置
                    ch = s[i]  # 保存原始字符
                    for j in range(26):  # 尝试所有可能的字母替换
                        s[i] = chr(ord('a') + j)  # 替换字符
                        t = ''.join(s)  # 重新组合成单词
                        if dist.get(t, 0) == step:  # 如果该单词在当前步数已被访问
                            prev[t].add(p)  # 添加前驱关系
                        if t not in words:  # 如果单词不在集合中
                            continue  # 跳过
                        prev[t].add(p)  # 添加前驱关系
                        words.discard(t)  # 从集合中移除已访问单词
                        q.append(t)  # 加入队列
                        dist[t] = step  # 记录距离
                        if endWord == t:  # 如果找到结束单词
                            found = True  # 设置找到标志
                    s[i] = ch  # 恢复原始字符
        if found:  # 如果找到结束单词
            path = [endWord]  # 初始化路径
            dfs(path, endWord)  # 深度优先搜索构建所有路径
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

## LeetCode_0126  数学解释

```python 
class Solution:
    def findLadders(
        self, beginWord: str, endWord: str, wordList: List[str]
    ) -> List[List[str]]:
        def dfs(path, cur):
            if cur == beginWord:
                ans.append(path[::-1])
                return
            for precursor in prev[cur]:
                path.append(precursor)
                dfs(path, precursor)
                path.pop()

        ans = []
        words = set(wordList)
        if endWord not in words:
            return ans
        words.discard(beginWord)
        dist = {beginWord: 0}
        prev = defaultdict(set)
        q = deque([beginWord])
        found = False
        step = 0
        while q and not found:
            step += 1
            for i in range(len(q), 0, -1):
                p = q.popleft()
                s = list(p)
                for i in range(len(s)):
                    ch = s[i]
                    for j in range(26):
                        s[i] = chr(ord('a') + j)
                        t = ''.join(s)
                        if dist.get(t, 0) == step:
                            prev[t].add(p)
                        if t not in words:
                            continue
                        prev[t].add(p)
                        words.discard(t)
                        q.append(t)
                        dist[t] = step
                        if endWord == t:
                            found = True
                    s[i] = ch
        if found:
            path = [endWord]
            dfs(path, endWord)
        return ans 
```


这段代码使用了**广度优先搜索（BFS）**和**深度优先搜索（DFS）**相结合的方法来解决单词接龙问题，寻找从beginWord到endWord的最短转换序列。

## 核心数学思想：

### 1. 图论建模
将问题抽象为图结构：
- 每个单词作为图中的一个节点
- 如果两个单词只有一个字母不同，则在它们之间建立一条边

### 2. 广度优先搜索（BFS）
- **目的**：找到从beginWord到endWord的最短路径（最小转换次数）
- **数学原理**：BFS按层次遍历，首次遇到目标节点时的路径即为最短路径
- **实现**：使用队列按层次遍历所有可能的转换

### 3. 动态规划思想
- 维护`dist`字典记录每个单词到起点的最短距离
- 维护`prev`字典记录每个单词的前驱节点集合（所有可能的最短路径前驱）

### 4. 深度优先搜索（DFS）
- **目的**：从终点回溯所有最短路径
- **数学原理**：利用BFS构建的前驱关系图，DFS遍历所有可能的路径
- **实现**：递归回溯，构建完整路径

### 5. 集合运算优化
- 使用`set`数据结构快速判断单词是否存在和去重
- `words.discard(t)`避免重复访问，提高效率

## 算法流程：
1. **BFS构建前驱图**：从起点开始，逐层探索所有可能的转换
2. **记录最短距离**：确保只考虑最短路径上的节点
3. **DFS回溯路径**：从终点开始，沿着前驱关系回溯所有最短路径

这种方法结合了BFS的最短路径搜索优势和DFS的路径回溯能力，时间复杂度主要取决于单词长度和字母表大小（26^n，n为单词长度）。

