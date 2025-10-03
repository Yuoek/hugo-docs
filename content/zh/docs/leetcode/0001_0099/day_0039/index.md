---
title: "day_0039 "
date: 2025-09-14T10:29:51+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0039 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        def dfs(i: int, s: int):
            if s == 0:
                ans.append(t[:])
                return
            if s < candidates[i]:
                return
            for j in range(i, len(candidates)):
                t.append(candidates[j])
                dfs(j, s - candidates[j])
                t.pop()

        candidates.sort()
        t = []
        ans = []
        dfs(0, target)
        return ans 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> t;
        function<void(int, int)> dfs = [&](int i, int s) {
            if (s == 0) {
                ans.emplace_back(t);
                return;
            }
            if (s < candidates[i]) {
                return;
            }
            for (int j = i; j < candidates.size(); ++j) {
                t.push_back(candidates[j]);
                dfs(j, s - candidates[j]);
                t.pop_back();
            }
        };
        dfs(0, target);
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
    private int[] candidates;

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);
        this.candidates = candidates;
        dfs(0, target);
        return ans;
    }

    private void dfs(int i, int s) {
        if (s == 0) {
            ans.add(new ArrayList(t));
            return;
        }
        if (s < candidates[i]) {
            return;
        }
        for (int j = i; j < candidates.length; ++j) {
            t.add(candidates[j]);
            dfs(j, s - candidates[j]);
            t.remove(t.size() - 1);
        }
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0039  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        def dfs(i: int, s: int):
            if s == 0:  # 如果当前和等于目标值，说明找到了一组解
                ans.append(t[:])  # 将当前组合添加到结果中（使用切片复制列表）
                return
            if s < candidates[i]:  # 如果当前和已经小于最小候选数，无法继续搜索
                return
            for j in range(i, len(candidates)):  # 从当前位置开始遍历候选数
                t.append(candidates[j])  # 将当前候选数加入临时组合
                dfs(j, s - candidates[j])  # 递归搜索，允许重复使用当前数字
                t.pop()  # 回溯，移除最后一个数字尝试其他组合

        candidates.sort()  # 先对候选数组进行排序，便于剪枝
        t = []  # 临时列表，存储当前组合
        ans = []  # 结果列表，存储所有有效组合
        dfs(0, target)  # 从第一个数字开始深度优先搜索
        return ans  # 返回所有满足条件的组合
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> t;
        function<void(int, int)> dfs = [&](int i, int s) {
            if (s == 0) {
                ans.emplace_back(t);
                return;
            }
            if (s < candidates[i]) {
                return;
            }
            for (int j = i; j < candidates.size(); ++j) {
                t.push_back(candidates[j]);
                dfs(j, s - candidates[j]);
                t.pop_back();
            }
        };
        dfs(0, target);
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
    private int[] candidates;

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);
        this.candidates = candidates;
        dfs(0, target);
        return ans;
    }

    private void dfs(int i, int s) {
        if (s == 0) {
            ans.add(new ArrayList(t));
            return;
        }
        if (s < candidates[i]) {
            return;
        }
        for (int j = i; j < candidates.length; ++j) {
            t.add(candidates[j]);
            dfs(j, s - candidates[j]);
            t.remove(t.size() - 1);
        }
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0039  数学解释

```python 
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        def dfs(i: int, s: int):
            if s == 0:
                ans.append(t[:])
                return
            if s < candidates[i]:
                return
            for j in range(i, len(candidates)):
                t.append(candidates[j])
                dfs(j, s - candidates[j])
                t.pop()

        candidates.sort()
        t = []
        ans = []
        dfs(0, target)
        return ans 
```


这段代码使用了**回溯法（Backtracking）** 和**深度优先搜索（DFS）** 的数学思想来解决组合求和问题。

## 核心数学思想：

1. **递归与回溯（Recursion & Backtracking）**
   - 通过递归尝试所有可能的组合
   - 当发现当前路径不可能达到目标时，回溯到上一步尝试其他选择

2. **剪枝优化（Pruning）**
   - `if s < candidates[i]: return` 提前终止不可能的分支
   - 排序后从当前索引开始遍历，避免重复组合

3. **组合数学中的无重复选择问题**
   - 允许重复选择同一元素（`range(i, len(candidates))`中的`j`从`i`开始）
   - 寻找所有和为target的组合，顺序无关（通过排序和从当前索引开始避免重复）

## 算法流程：
1. 排序候选数组（便于剪枝）
2. 从第一个元素开始深度优先搜索
3. 每次选择当前或后面的元素（避免重复组合）
4. 当和等于target时记录结果
5. 当和超过target时回溯

## 时间复杂度：O(2^n)
最坏情况下需要遍历所有可能的组合，但由于剪枝优化，实际运行效率更高。

这种解法体现了**穷举+剪枝**的经典算法设计思想，通过数学上的约束条件来减少不必要的计算。


