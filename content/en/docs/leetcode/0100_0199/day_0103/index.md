---
title: "day_0103 "
date: 2025-09-21T10:48:05+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0103 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        ans = []
        if root is None:
            return ans
        q = deque([root])
        ans = []
        left = 1
        while q:
            t = []
            for _ in range(len(q)):
                node = q.popleft()
                t.append(node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            ans.append(t if left else t[::-1])
            left ^= 1
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

## LeetCode_0103  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        ans = []  # 存储最终结果的列表
        if root is None:  # 如果根节点为空，直接返回空列表
            return ans
        q = deque([root])  # 创建双端队列，初始包含根节点
        ans = []  # 初始化结果列表
        left = 1  # 方向标志：1表示从左到右，0表示从右到左
        while q:  # 当队列不为空时循环
            t = []  # 临时列表，存储当前层的节点值
            for _ in range(len(q)):  # 遍历当前层的所有节点
                node = q.popleft()  # 从队列左侧取出节点
                t.append(node.val)  # 将节点值添加到临时列表
                if node.left:  # 如果存在左子节点
                    q.append(node.left)  # 将左子节点加入队列
                if node.right:  # 如果存在右子节点
                    q.append(node.right)  # 将右子节点加入队列
            ans.append(t if left else t[::-1])  # 根据方向标志决定是否反转当前层结果
            left ^= 1  # 切换方向标志（1变0，0变1）
        return ans  # 返回最终的锯齿形层序遍历结果
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

## LeetCode_0103  数学解释

```python 
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        ans = []
        if root is None:
            return ans
        q = deque([root])
        ans = []
        left = 1
        while q:
            t = []
            for _ in range(len(q)):
                node = q.popleft()
                t.append(node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            ans.append(t if left else t[::-1])
            left ^= 1
        return ans 
```


这段代码实现了二叉树的锯齿形层次遍历（Zigzag Level Order Traversal），主要运用了以下数学思想：

## 1. 广度优先搜索（BFS）
- 使用队列（deque）实现层次遍历
- 每一层节点按顺序处理，确保层次结构的完整性
- 时间复杂度：O(n)，空间复杂度：O(n)

## 2. 布尔代数思想
```python
left ^= 1  # 异或操作实现0和1的交替切换
```
- 使用异或运算（XOR）在0和1之间切换
- 数学原理：1 XOR 1 = 0，0 XOR 1 = 1
- 相当于模2加法：left = (left + 1) % 2

## 3. 奇偶性判断
- `left`变量记录当前层的奇偶性
- 奇数层（left=1）：从左到右输出
- 偶数层（left=0）：从右到左输出（通过`t[::-1]`反转）

## 4. 队列长度作为循环控制
```python
for _ in range(len(q)):
```
- 每次处理当前层的所有节点
- 确保层次遍历的正确性

## 数学抽象
这实际上是一个在二叉树上的交替方向遍历问题，可以看作：
- 在层次遍历的基础上增加方向控制
- 使用二进制状态（0/1）控制遍历方向
- 体现了状态机思想：每个状态决定下一个状态的行为

这种实现简洁高效，充分利用了队列数据结构和位运算的数学特性。


