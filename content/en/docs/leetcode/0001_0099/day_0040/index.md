---
title: "day_0040 "
date: 2025-09-14T10:25:50+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0040 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        def dfs(i: int, s: int):
            if s == 0:
                ans.append(t[:])
                return
            if i >= len(candidates) or s < candidates[i]:
                return
            for j in range(i, len(candidates)):
                if j > i and candidates[j] == candidates[j - 1]:
                    continue
                t.append(candidates[j])
                dfs(j + 1, s - candidates[j])
                t.pop()

        candidates.sort()
        ans = []
        t = []
        dfs(0, target)
        return ans 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> t;
        function<void(int, int)> dfs = [&](int i, int s) {
            if (s == 0) {
                ans.emplace_back(t);
                return;
            }
            if (i >= candidates.size() || s < candidates[i]) {
                return;
            }
            for (int j = i; j < candidates.size(); ++j) {
                if (j > i && candidates[j] == candidates[j - 1]) {
                    continue;
                }
                t.emplace_back(candidates[j]);
                dfs(j + 1, s - candidates[j]);
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

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        this.candidates = candidates;
        dfs(0, target);
        return ans;
    }

    private void dfs(int i, int s) {
        if (s == 0) {
            ans.add(new ArrayList<>(t));
            return;
        }
        if (i >= candidates.length || s < candidates[i]) {
            return;
        }
        for (int j = i; j < candidates.length; ++j) {
            if (j > i && candidates[j] == candidates[j - 1]) {
                continue;
            }
            t.add(candidates[j]);
            dfs(j + 1, s - candidates[j]);
            t.remove(t.size() - 1);
        }
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0040  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        def dfs(i: int, s: int):
            if s == 0:  # 如果当前和等于目标值，说明找到了一组解
                ans.append(t[:])  # 将当前组合添加到结果中（使用切片复制列表）
                return
            if i >= len(candidates) or s < candidates[i]:  # 如果索引越界或当前和小于最小候选数
                return  # 直接返回，无法继续搜索
            for j in range(i, len(candidates)):  # 从当前位置开始遍历候选数组
                if j > i and candidates[j] == candidates[j - 1]:  # 跳过重复元素，避免重复组合
                    continue
                t.append(candidates[j])  # 将当前候选数添加到临时组合中
                dfs(j + 1, s - candidates[j])  # 递归搜索下一个位置，更新剩余和
                t.pop()  # 回溯，移除最后一个添加的数

        candidates.sort()  # 先对候选数组排序，便于去重和剪枝
        ans = []  # 存储所有符合条件的组合
        t = []  # 临时存储当前组合
        dfs(0, target)  # 从第0个位置开始深度优先搜索
        return ans  # 返回所有找到的组合
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> t;
        function<void(int, int)> dfs = [&](int i, int s) {
            if (s == 0) {
                ans.emplace_back(t);
                return;
            }
            if (i >= candidates.size() || s < candidates[i]) {
                return;
            }
            for (int j = i; j < candidates.size(); ++j) {
                if (j > i && candidates[j] == candidates[j - 1]) {
                    continue;
                }
                t.emplace_back(candidates[j]);
                dfs(j + 1, s - candidates[j]);
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

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        this.candidates = candidates;
        dfs(0, target);
        return ans;
    }

    private void dfs(int i, int s) {
        if (s == 0) {
            ans.add(new ArrayList<>(t));
            return;
        }
        if (i >= candidates.length || s < candidates[i]) {
            return;
        }
        for (int j = i; j < candidates.length; ++j) {
            if (j > i && candidates[j] == candidates[j - 1]) {
                continue;
            }
            t.add(candidates[j]);
            dfs(j + 1, s - candidates[j]);
            t.remove(t.size() - 1);
        }
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0040  数学解释

```python 
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        def dfs(i: int, s: int):
            if s == 0:
                ans.append(t[:])
                return
            if i >= len(candidates) or s < candidates[i]:
                return
            for j in range(i, len(candidates)):
                if j > i and candidates[j] == candidates[j - 1]:
                    continue
                t.append(candidates[j])
                dfs(j + 1, s - candidates[j])
                t.pop()

        candidates.sort()
        ans = []
        t = []
        dfs(0, target)
        return ans 
```


这段代码使用了**回溯法（Backtracking）** 和**剪枝（Pruning）** 的数学思想来解决组合总和问题。具体来说：

## 核心数学思想

1. **回溯法（深度优先搜索）**
   - 通过递归尝试所有可能的组合
   - 使用栈（列表t）记录当前路径
   - 当达到目标值时保存结果，否则回溯尝试其他选择

2. **排序与去重**
   - 先对候选数组排序，便于处理重复元素和剪枝
   - 跳过重复元素：`if j > i and candidates[j] == candidates[j - 1]: continue`
   - 避免生成重复的组合

3. **剪枝优化**
   - 提前终止无效分支：`if s < candidates[i]: return`
   - 当剩余和小于当前候选数时，后续更大的数更不可能满足条件
   - 减少不必要的递归调用

## 数学过程描述

设候选数组为排序后的序列：c[0] ≤ c[1] ≤ ... ≤ c[n-1]

对于每个位置i，算法：
1. 选择c[i]并递归处理剩余和s-c[i]
2. 跳过c[i]（通过循环继续下一个不同元素）
3. 当s=0时找到有效解
4. 当s<0或i超出范围时回溯

时间复杂度：最坏情况O(2ⁿ)，但由于剪枝优化，实际运行效率更高。

这种方法的数学本质是**系统地遍历解空间树**，同时利用排序和剪枝策略**避免重复计算和无效搜索**。


