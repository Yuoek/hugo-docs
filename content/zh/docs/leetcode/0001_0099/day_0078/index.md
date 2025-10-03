---
title: 'day_0078 '
date: 2025-09-14T08:41:33+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0078 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        def dfs(i: int):
            if i == len(nums):
                ans.append(t[:])
                return
            dfs(i + 1)
            t.append(nums[i])
            dfs(i + 1)
            t.pop()

        ans = []
        t = []
        dfs(0)
        return ans 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> t;
        function<void(int)> dfs = [&](int i) -> void {
            if (i == nums.size()) {
                ans.push_back(t);
                return;
            }
            dfs(i + 1);
            t.push_back(nums[i]);
            dfs(i + 1);
            t.pop_back();
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

    public List<List<Integer>> subsets(int[] nums) {
        this.nums = nums;
        dfs(0);
        return ans;
    }

    private void dfs(int i) {
        if (i == nums.length) {
            ans.add(new ArrayList<>(t));
            return;
        }
        dfs(i + 1);
        t.add(nums[i]);
        dfs(i + 1);
        t.remove(t.size() - 1);
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0078  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python 
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        def dfs(i: int):
            if i == len(nums):  # 递归终止条件：已经处理完所有元素
                ans.append(t[:])  # 将当前子集添加到结果中（使用切片复制避免引用问题）
                return
            dfs(i + 1)  # 不选择当前元素，继续递归
            t.append(nums[i])  # 选择当前元素，添加到临时子集
            dfs(i + 1)  # 选择当前元素后继续递归
            t.pop()  # 回溯，移除当前选择的元素

        ans = []  # 存储所有子集的结果列表
        t = []  # 临时存储当前构建的子集
        dfs(0)  # 从索引0开始深度优先搜索
        return ans  # 返回所有子集
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> t;
        function<void(int)> dfs = [&](int i) -> void {
            if (i == nums.size()) {
                ans.push_back(t);
                return;
            }
            dfs(i + 1);
            t.push_back(nums[i]);
            dfs(i + 1);
            t.pop_back();
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

    public List<List<Integer>> subsets(int[] nums) {
        this.nums = nums;
        dfs(0);
        return ans;
    }

    private void dfs(int i) {
        if (i == nums.length) {
            ans.add(new ArrayList<>(t));
            return;
        }
        dfs(i + 1);
        t.add(nums[i]);
        dfs(i + 1);
        t.remove(t.size() - 1);
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0078  数学解释

```python 
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        def dfs(i: int):
            if i == len(nums):
                ans.append(t[:])
                return
            dfs(i + 1)
            t.append(nums[i])
            dfs(i + 1)
            t.pop()

        ans = []
        t = []
        dfs(0)
        return ans 
```


这段代码使用了**回溯法**和**深度优先搜索(DFS)** 的数学思想来生成所有子集。

## 核心数学思想：二进制枚举与决策树

### 1. 组合数学视角
对于包含n个元素的集合，共有2ⁿ个子集。每个元素都有"选"或"不选"两种可能，这对应着二进制表示（0表示不选，1表示选）。

### 2. 递归树结构
代码构建了一个深度为n的二叉树：
- 每个节点代表一个决策点（处理第i个元素）
- 左分支：不选择当前元素
- 右分支：选择当前元素

### 3. 回溯机制
- `t.append(nums[i])`：选择当前元素
- `t.pop()`：撤销选择（回溯）
- `ans.append(t[:])`：保存当前子集的副本

### 4. 时间复杂度分析
- 时间复杂度：O(n × 2ⁿ) - 每个叶子节点需要O(n)时间复制子集
- 空间复杂度：O(n) - 递归栈深度和临时列表t的大小

这种算法优雅地体现了**递归与回溯**的数学美，通过系统性地探索所有可能的组合来解决问题。


