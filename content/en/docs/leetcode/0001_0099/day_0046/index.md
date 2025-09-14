---
title: "day_0046 "
date: 2025-09-14T10:14:27+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0046 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        def dfs(i: int):
            if i >= n:
                ans.append(t[:])
                return
            for j, x in enumerate(nums):
                if not vis[j]:
                    vis[j] = True
                    t[i] = x
                    dfs(i + 1)
                    vis[j] = False

        n = len(nums)
        vis = [False] * n
        t = [0] * n
        ans = []
        dfs(0)
        return ans 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> t(n);
        vector<bool> vis(n);
        auto dfs = [&](this auto&& dfs, int i) -> void {
            if (i == n) {
                ans.emplace_back(t);
                return;
            }
            for (int j = 0; j < n; ++j) {
                if (!vis[j]) {
                    vis[j] = true;
                    t[i] = nums[j];
                    dfs(i + 1);
                    vis[j] = false;
                }
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
    private boolean[] vis;
    private int[] nums;

    public List<List<Integer>> permute(int[] nums) {
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
            if (!vis[j]) {
                vis[j] = true;
                t.add(nums[j]);
                dfs(i + 1);
                t.remove(t.size() - 1);
                vis[j] = false;
            }
        }
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0046  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        def dfs(i: int):
            if i >= n:  # 如果当前索引i已经达到数组长度，说明已经生成了一个完整排列
                ans.append(t[:])  # 将当前排列的副本添加到结果列表中（使用副本避免引用问题）
                return
            for j, x in enumerate(nums):  # 遍历数组中的每个元素
                if not vis[j]:  # 如果当前元素还没有被使用过
                    vis[j] = True  # 标记该元素为已使用
                    t[i] = x  # 将当前元素放入排列的第i个位置
                    dfs(i + 1)  # 递归处理下一个位置
                    vis[j] = False  # 回溯，取消标记，尝试其他可能性

        n = len(nums)  # 获取数组长度
        vis = [False] * n  # 创建访问标记数组，记录每个元素是否已被使用
        t = [0] * n  # 创建临时数组，用于存储当前正在构建的排列
        ans = []  # 存储所有排列结果的列表
        dfs(0)  # 从第0个位置开始深度优先搜索
        return ans  # 返回所有排列结果
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> t(n);
        vector<bool> vis(n);
        auto dfs = [&](this auto&& dfs, int i) -> void {
            if (i == n) {
                ans.emplace_back(t);
                return;
            }
            for (int j = 0; j < n; ++j) {
                if (!vis[j]) {
                    vis[j] = true;
                    t[i] = nums[j];
                    dfs(i + 1);
                    vis[j] = false;
                }
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
    private boolean[] vis;
    private int[] nums;

    public List<List<Integer>> permute(int[] nums) {
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
            if (!vis[j]) {
                vis[j] = true;
                t.add(nums[j]);
                dfs(i + 1);
                t.remove(t.size() - 1);
                vis[j] = false;
            }
        }
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0046  数学解释

```python 
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        def dfs(i: int):
            if i >= n:
                ans.append(t[:])
                return
            for j, x in enumerate(nums):
                if not vis[j]:
                    vis[j] = True
                    t[i] = x
                    dfs(i + 1)
                    vis[j] = False

        n = len(nums)
        vis = [False] * n
        t = [0] * n
        ans = []
        dfs(0)
        return ans 
```


这段代码使用了**回溯法（Backtracking）** 的数学思想来生成所有排列。具体来说：

**数学原理：**
1. **排列组合**：n个不同元素的排列数为n!，每个排列都是元素的一种特定顺序
2. **递归构造**：通过递归方式逐步构建排列，每次选择一个未被使用的元素

**算法思想解释：**
- **深度优先搜索（DFS）**：递归地探索所有可能的排列路径
- **回溯机制**：当一条路径探索完成后，撤销最后的选择（vis[j] = False），返回上一层尝试其他选择
- **剪枝**：通过vis数组标记已使用的元素，避免重复选择同一元素

**数学过程：**
1. 从位置i=0开始，尝试所有未被使用的元素
2. 对于每个选择x，标记为已使用，放入位置i
3. 递归处理位置i+1
4. 递归返回后，撤销选择（回溯），尝试其他可能性

**时间复杂度**：O(n×n!)，因为有n!个排列，每个排列需要O(n)时间构造
**空间复杂度**：O(n)，递归栈深度和辅助数组大小

这种回溯方法系统地枚举了所有可能的排列，确保不重不漏，是解决排列问题的经典数学思想应用。


