---
title: "day_0047 "
date: 2025-09-14T10:12:22+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0047 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        def dfs(i: int):
            if i == n:
                ans.append(t[:])
                return
            for j in range(n):
                if vis[j] or (j and nums[j] == nums[j - 1] and not vis[j - 1]):
                    continue
                t[i] = nums[j]
                vis[j] = True
                dfs(i + 1)
                vis[j] = False

        n = len(nums)
        nums.sort()
        ans = []
        t = [0] * n
        vis = [False] * n
        dfs(0)
        return ans 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        ranges::sort(nums);
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> t(n);
        vector<bool> vis(n);
        auto dfs = [&](this auto&& dfs, int i) {
            if (i == n) {
                ans.emplace_back(t);
                return;
            }
            for (int j = 0; j < n; ++j) {
                if (vis[j] || (j && nums[j] == nums[j - 1] && !vis[j - 1])) {
                    continue;
                }
                t[i] = nums[j];
                vis[j] = true;
                dfs(i + 1);
                vis[j] = false;
            }
        };
        dfs(0);
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
    private int[] nums;
    private boolean[] vis;

    public List<List<Integer>> permuteUnique(int[] nums) {
        Arrays.sort(nums);
        this.nums = nums;
        vis = new boolean[nums.length];
        dfs(0);
        return ans;
    }

    private void dfs(int i) {
        if (i == nums.length) {
            ans.add(new ArrayList<>(t));
            return;
        }
        for (int j = 0; j < nums.length; ++j) {
            if (vis[j] || (j > 0 && nums[j] == nums[j - 1] && !vis[j - 1])) {
                continue;
            }
            t.add(nums[j]);
            vis[j] = true;
            dfs(i + 1);
            vis[j] = false;
            t.remove(t.size() - 1);
        }
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0047  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        def dfs(i: int):
            if i == n:  # 如果已经填完所有位置
                ans.append(t[:])  # 将当前排列加入结果集（使用切片复制）
                return
            for j in range(n):  # 遍历所有数字
                # 跳过已使用的数字，或者相同数字但前一个相同数字未被使用（避免重复）
                if vis[j] or (j and nums[j] == nums[j - 1] and not vis[j - 1]):
                    continue
                t[i] = nums[j]  # 将当前数字填入位置i
                vis[j] = True  # 标记该数字已使用
                dfs(i + 1)  # 递归处理下一个位置
                vis[j] = False  # 回溯，取消标记

        n = len(nums)  # 获取数组长度
        nums.sort()  # 排序以便处理重复数字
        ans = []  # 存储所有不重复排列的结果
        t = [0] * n  # 临时数组，存储当前排列
        vis = [False] * n  # 标记数组，记录数字是否已被使用
        dfs(0)  # 从第0个位置开始深度优先搜索
        return ans  # 返回所有不重复的排列
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        ranges::sort(nums);
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> t(n);
        vector<bool> vis(n);
        auto dfs = [&](this auto&& dfs, int i) {
            if (i == n) {
                ans.emplace_back(t);
                return;
            }
            for (int j = 0; j < n; ++j) {
                if (vis[j] || (j && nums[j] == nums[j - 1] && !vis[j - 1])) {
                    continue;
                }
                t[i] = nums[j];
                vis[j] = true;
                dfs(i + 1);
                vis[j] = false;
            }
        };
        dfs(0);
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
    private int[] nums;
    private boolean[] vis;

    public List<List<Integer>> permuteUnique(int[] nums) {
        Arrays.sort(nums);
        this.nums = nums;
        vis = new boolean[nums.length];
        dfs(0);
        return ans;
    }

    private void dfs(int i) {
        if (i == nums.length) {
            ans.add(new ArrayList<>(t));
            return;
        }
        for (int j = 0; j < nums.length; ++j) {
            if (vis[j] || (j > 0 && nums[j] == nums[j - 1] && !vis[j - 1])) {
                continue;
            }
            t.add(nums[j]);
            vis[j] = true;
            dfs(i + 1);
            vis[j] = false;
            t.remove(t.size() - 1);
        }
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0047  数学解释

```python 
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        def dfs(i: int):
            if i == n:
                ans.append(t[:])
                return
            for j in range(n):
                if vis[j] or (j and nums[j] == nums[j - 1] and not vis[j - 1]):
                    continue
                t[i] = nums[j]
                vis[j] = True
                dfs(i + 1)
                vis[j] = False

        n = len(nums)
        nums.sort()
        ans = []
        t = [0] * n
        vis = [False] * n
        dfs(0)
        return ans 
```


这段代码使用了**回溯法（Backtracking）** 和**剪枝（Pruning）** 的数学思想来解决排列问题，具体来说：

## 核心数学思想

### 1. 回溯法（Backtracking）
- **状态空间树**：将排列问题建模为一棵树，每个节点代表一个部分排列
- **深度优先搜索**：通过递归遍历所有可能的排列组合
- **状态恢复**：在递归返回时撤销当前选择（`vis[j] = False`）

### 2. 剪枝优化（Pruning）
- **排序预处理**：`nums.sort()` 将相同数字聚集在一起
- **重复排列检测**：条件 `(j and nums[j] == nums[j - 1] and not vis[j - 1])` 是关键
  - 当当前数字与前一个数字相同，且前一个数字未被使用时，跳过当前选择
  - 这确保了相同数字的相对顺序，避免生成重复排列

### 3. 组合数学
- **排列生成**：生成所有 n! 个排列（去重后）
- **重复元素处理**：对于有重复元素的集合，实际排列数为 n!/(n₁!·n₂!·...·nₖ!)，其中 nᵢ 是每个重复元素的个数

## 算法流程
1. **排序**：将输入数组排序，使相同元素相邻
2. **回溯搜索**：从第一个位置开始，尝试所有可能的数字
3. **剪枝条件**：跳过已使用的数字和会导致重复排列的情况
4. **终止条件**：当填满所有位置时，保存当前排列

这种方法的数学本质是通过**系统性地枚举所有可能性**，同时利用**数学约束条件**来避免不必要的计算，确保生成所有唯一排列。

