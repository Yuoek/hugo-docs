---
title: "day_0077 "
date: 2025-09-14T08:43:54+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0077 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        def dfs(i: int):
            if len(t) == k:
                ans.append(t[:])
                return
            if i > n:
                return
            t.append(i)
            dfs(i + 1)
            t.pop()
            dfs(i + 1)

        ans = []
        t = []
        dfs(1)
        return ans 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> t;
        function<void(int)> dfs = [&](int i) {
            if (t.size() == k) {
                ans.emplace_back(t);
                return;
            }
            if (i > n) {
                return;
            }
            t.emplace_back(i);
            dfs(i + 1);
            t.pop_back();
            dfs(i + 1);
        };
        dfs(1);
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    private List<List<Integer>> ans = new ArrayList<>();
    private List<Integer> t = new ArrayList<>();
    private int n;
    private int k;

    public List<List<Integer>> combine(int n, int k) {
        this.n = n;
        this.k = k;
        dfs(1);
        return ans;
    }

    private void dfs(int i) {
        if (t.size() == k) {
            ans.add(new ArrayList<>(t));
            return;
        }
        if (i > n) {
            return;
        }
        t.add(i);
        dfs(i + 1);
        t.remove(t.size() - 1);
        dfs(i + 1);
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0077  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        def dfs(i: int):
            if len(t) == k:  # 如果当前组合长度等于k，说明找到了一个有效组合
                ans.append(t[:])  # 将当前组合的副本添加到结果列表中
                return
            if i > n:  # 如果当前数字超过n，说明已经遍历完所有可能
                return
            t.append(i)  # 选择当前数字i
            dfs(i + 1)   # 递归处理下一个数字
            t.pop()      # 回溯，撤销选择当前数字i
            dfs(i + 1)   # 不选择当前数字i，直接处理下一个数字

        ans = []  # 存储所有组合的结果列表
        t = []    # 临时存储当前组合
        dfs(1)    # 从数字1开始深度优先搜索
        return ans  # 返回所有组合的结果
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> t;
        function<void(int)> dfs = [&](int i) {
            if (t.size() == k) {
                ans.emplace_back(t);
                return;
            }
            if (i > n) {
                return;
            }
            t.emplace_back(i);
            dfs(i + 1);
            t.pop_back();
            dfs(i + 1);
        };
        dfs(1);
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    private List<List<Integer>> ans = new ArrayList<>();
    private List<Integer> t = new ArrayList<>();
    private int n;
    private int k;

    public List<List<Integer>> combine(int n, int k) {
        this.n = n;
        this.k = k;
        dfs(1);
        return ans;
    }

    private void dfs(int i) {
        if (t.size() == k) {
            ans.add(new ArrayList<>(t));
            return;
        }
        if (i > n) {
            return;
        }
        t.add(i);
        dfs(i + 1);
        t.remove(t.size() - 1);
        dfs(i + 1);
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0077  数学解释

```python 
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        def dfs(i: int):
            if len(t) == k:
                ans.append(t[:])
                return
            if i > n:
                return
            t.append(i)
            dfs(i + 1)
            t.pop()
            dfs(i + 1)

        ans = []
        t = []
        dfs(1)
        return ans 
```


这段代码使用了**回溯法（Backtracking）**的数学思想来解决组合问题。具体分析如下：

### 核心数学思想：
1. **组合数学（Combinatorics）**：从n个不同元素中选取k个元素的所有组合（不考虑顺序）
2. **递归与回溯**：通过深度优先搜索（DFS）遍历所有可能的组合路径

### 算法执行过程：
- **状态表示**：使用列表`t`记录当前正在构建的组合
- **递归终止条件**：
  - 当`t`的长度等于k时，找到一个有效组合，保存副本
  - 当当前数字i超过n时，终止当前分支
- **两种选择**：
  - **包含当前数字**：将i加入组合，递归处理i+1
  - **不包含当前数字**：直接递归处理i+1
- **回溯操作**：在递归返回后移除最后添加的数字（`t.pop()`），恢复状态

### 数学特性：
- **时间复杂度**：O(C(n,k) × k)，因为共有C(n,k)种组合，每种组合需要O(k)时间复制
- **空间复杂度**：O(k)用于递归调用栈和临时组合存储

### 示例说明（n=4, k=2）：
代码会生成所有6种组合：[1,2], [1,3], [1,4], [2,3], [2,4], [3,4]，完美体现了组合数学的C(4,2)=6种可能。

这种回溯方法系统地探索了所有可能的组合，确保不重复不遗漏，是解决组合问题的经典范式。


