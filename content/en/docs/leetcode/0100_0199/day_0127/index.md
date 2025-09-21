---
title: "day_0127 "
date: 2025-09-21T10:07:43+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0127 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        words = set(wordList)
        q = deque([beginWord])
        ans = 1
        while q:
            ans += 1
            for _ in range(len(q)):
                s = q.popleft()
                s = list(s)
                for i in range(len(s)):
                    ch = s[i]
                    for j in range(26):
                        s[i] = chr(ord('a') + j)
                        t = ''.join(s)
                        if t not in words:
                            continue
                        if t == endWord:
                            return ans
                        q.append(t)
                        words.remove(t)
                    s[i] = ch
        return 0 
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

## LeetCode_0127  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python 
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        words = set(wordList)  # 将单词列表转为集合，便于快速查找
        q = deque([beginWord])  # 初始化队列，从起始单词开始
        ans = 1  # 初始步数为1（包含起始单词）
        while q:  # 当队列不为空时循环
            ans += 1  # 每处理完一层，步数加1
            for _ in range(len(q)):  # 处理当前层的所有单词
                s = q.popleft()  # 取出队列中的单词
                s = list(s)  # 将字符串转为字符列表便于修改
                for i in range(len(s)):  # 遍历单词的每个位置
                    ch = s[i]  # 保存原始字符
                    for j in range(26):  # 尝试26个字母替换
                        s[i] = chr(ord('a') + j)  # 替换当前位置的字符
                        t = ''.join(s)  # 重新组合成字符串
                        if t not in words:  # 如果新单词不在字典中，跳过
                            continue
                        if t == endWord:  # 如果找到目标单词，返回当前步数
                            return ans
                        q.append(t)  # 将新单词加入队列
                        words.remove(t)  # 从字典中移除，避免重复访问
                    s[i] = ch  # 恢复原始字符，继续尝试下一个位置
        return 0  # 如果无法转换，返回0
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

## LeetCode_0127  数学解释

```python 
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        words = set(wordList)
        q = deque([beginWord])
        ans = 1
        while q:
            ans += 1
            for _ in range(len(q)):
                s = q.popleft()
                s = list(s)
                for i in range(len(s)):
                    ch = s[i]
                    for j in range(26):
                        s[i] = chr(ord('a') + j)
                        t = ''.join(s)
                        if t not in words:
                            continue
                        if t == endWord:
                            return ans
                        q.append(t)
                        words.remove(t)
                    s[i] = ch
        return 0 
```


这段代码使用了**广度优先搜索（Breadth-First Search, BFS）** 的数学思想来解决单词接龙问题。

## 核心数学思想：

1. **图论建模**：将单词转换问题建模为图
   - 每个单词是一个节点
   - 如果两个单词只有一个字母不同，则在它们之间建立边
   - 问题转化为寻找从 beginWord 到 endWord 的最短路径

2. **广度优先搜索**：
   - BFS 按层遍历，保证找到的路径是最短的（最少转换次数）
   - 队列 `q` 存储当前层的所有节点
   - `ans` 记录当前所在的层数（即转换次数）

3. **状态空间搜索**：
   - 对于每个单词，生成所有可能的一次转换结果
   - 通过 `words.remove(t)` 避免重复访问（相当于标记已访问节点）
   - 使用集合 `words` 进行快速查找和去重

4. **组合数学**：
   - 每个长度为 L 的单词有 26×L 种可能的一次转换
   - 但只有存在于字典中的转换才是有效边

## 算法复杂度：
- 时间复杂度：O(N×L×26)，其中 N 是单词数量，L 是单词长度
- 空间复杂度：O(N)，用于存储队列和单词集合

当找到目标单词时立即返回当前层数，确保找到的是最短转换路径。如果队列耗尽仍未找到，返回 0 表示无法转换。

