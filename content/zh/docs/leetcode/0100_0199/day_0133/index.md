---
title: "day_0133 "
date: 2025-09-21T09:55:54+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}



## LeetCode_0133 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional


class Solution:
    def cloneGraph(self, node: Optional["Node"]) -> Optional["Node"]:
        def dfs(node):
            if node is None:
                return None
            if node in g:
                return g[node]
            cloned = Node(node.val)
            g[node] = cloned
            for nxt in node.neighbors:
                cloned.neighbors.append(dfs(nxt))
            return cloned

        g = defaultdict()
        return dfs(node) 
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

## LeetCode_0133  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python 
"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val  # 节点值
        self.neighbors = neighbors if neighbors is not None else []  # 邻居节点列表
"""

from typing import Optional
from collections import defaultdict  # 导入defaultdict用于创建字典


class Solution:
    def cloneGraph(self, node: Optional["Node"]) -> Optional["Node"]:
        def dfs(node):
            if node is None:  # 如果节点为空，直接返回None
                return None
            if node in g:  # 如果节点已经在字典中，说明已经克隆过，直接返回克隆节点
                return g[node]
            cloned = Node(node.val)  # 创建当前节点的克隆节点
            g[node] = cloned  # 将原节点和克隆节点映射关系存入字典
            for nxt in node.neighbors:  # 遍历当前节点的所有邻居节点
                cloned.neighbors.append(dfs(nxt))  # 递归克隆邻居节点并添加到克隆节点的邻居列表中
            return cloned  # 返回克隆节点

        g = defaultdict()  # 创建字典用于存储原节点到克隆节点的映射
        return dfs(node)  # 从起始节点开始深度优先搜索克隆整个图
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

## LeetCode_0133  数学解释

```python 
"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional


class Solution:
    def cloneGraph(self, node: Optional["Node"]) -> Optional["Node"]:
        def dfs(node):
            if node is None:
                return None
            if node in g:
                return g[node]
            cloned = Node(node.val)
            g[node] = cloned
            for nxt in node.neighbors:
                cloned.neighbors.append(dfs(nxt))
            return cloned

        g = defaultdict()
        return dfs(node) 
```


这段代码使用了**图论**和**深度优先搜索(DFS)**的数学思想，具体体现在：

## 核心数学思想：
1. **图的同构映射**：通过创建原图节点到克隆节点的映射关系，保持图的结构不变
2. **递归与数学归纳法**：DFS递归过程体现了数学归纳法的思想
   - 基础情况：空节点返回None
   - 归纳步骤：假设已克隆所有邻居，然后构建当前节点的克隆

## 具体数学原理：
- **函数映射**：`g: V → V'` 定义了原图节点到克隆节点的双射函数
- **避免循环引用**：通过映射表`g`记录已访问节点，防止无限递归（类似动态规划的记忆化）
- **保持邻接关系**：`cloned.neighbors.append(dfs(nxt))` 确保克隆图的邻接矩阵与原图相同

## 时间复杂度分析：
- 时间复杂度：O(V+E)，其中V是顶点数，E是边数
- 空间复杂度：O(V)，用于存储映射关系和递归栈

这种解法体现了**递归思维**和**映射保持结构**的重要数学概念，是图论中克隆问题的经典解决方案。


