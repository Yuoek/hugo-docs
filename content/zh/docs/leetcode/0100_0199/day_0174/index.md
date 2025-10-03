---
title: "day_0174 "
date: 2025-09-21T08:40:03+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0174 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        m, n = len(dungeon), len(dungeon[0])
        dp = [[inf] * (n + 1) for _ in range(m + 1)]
        dp[m][n - 1] = dp[m - 1][n] = 1
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j])
        return dp[0][0] 
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

## LeetCode_0174  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        m, n = len(dungeon), len(dungeon[0])  # 获取地牢的行数和列数
        dp = [[inf] * (n + 1) for _ in range(m + 1)]  # 初始化DP表，用无穷大填充边界
        dp[m][n - 1] = dp[m - 1][n] = 1  # 设置终点右侧和下侧的最小初始生命值为1
        for i in range(m - 1, -1, -1):  # 从右下角向左上角反向遍历
            for j in range(n - 1, -1, -1):  # 遍历每一列
                # 计算当前位置所需的最小生命值：取右侧和下侧的最小值，减去当前格子值，且至少为1
                dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j])
        return dp[0][0]  # 返回起点所需的最小初始生命值
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

## LeetCode_0174  数学解释

```python 
class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        m, n = len(dungeon), len(dungeon[0])
        dp = [[inf] * (n + 1) for _ in range(m + 1)]
        dp[m][n - 1] = dp[m - 1][n] = 1
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j])
        return dp[0][0] 
```


这段代码使用了**动态规划**和**逆向思维**的数学思想来解决"地下城游戏"问题：

## 核心数学思想

### 1. 逆向动态规划 (Reverse DP)
- **正向思考的局限性**：从起点到终点计算最小生命值需要考虑所有路径，难以处理
- **逆向思维**：从终点反推到起点，确定每个位置需要的最小生命值
- **数学原理**：`dp[i][j]` 表示从位置(i,j)到终点所需的最小初始生命值

### 2. 状态转移方程
```python
dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j])
```
- **数学含义**：当前位置的最小生命值 = 下个位置的最小需求 - 当前格子值
- **max(1, ...)**：确保生命值至少为1（不能为负数或零）
- **min(向下, 向右)**：选择最优（最小需求）的路径

### 3. 边界条件处理
```python
dp[m][n-1] = dp[m-1][n] = 1
```
- **数学意义**：终点右侧和下方的虚拟边界设为1
- **目的**：确保终点位置的计算正确：`dp[m-1][n-1] = max(1, 1 - dungeon[m-1][n-1])`

### 4. 最优化原理
- **贝尔曼最优性原理**：最优路径的子路径也是最优的
- **应用**：从终点开始，每个位置都选择到终点的最优（最小生命需求）路径

## 算法复杂度
- **时间复杂度**：O(m×n)，遍历每个格子一次
- **空间复杂度**：O(m×n)，使用二维DP数组存储中间结果

这种逆向DP方法巧妙地避免了正向计算中需要同时跟踪当前生命值和最小生命值的复杂性。
