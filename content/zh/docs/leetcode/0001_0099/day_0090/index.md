---
title: "day_0090 "
date: 2025-09-13T21:47:06+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0090 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        def dfs(i: int):
            if i == len(nums):
                ans.append(t[:])
                return
            t.append(nums[i])
            dfs(i + 1)
            x = t.pop()
            while i + 1 < len(nums) and nums[i + 1] == x:
                i += 1
            dfs(i + 1)

        nums.sort()
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
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        ranges::sort(nums);
        vector<vector<int>> ans;
        vector<int> t;
        int n = nums.size();
        auto dfs = [&](this auto&& dfs, int i) {
            if (i >= n) {
                ans.push_back(t);
                return;
            }
            t.push_back(nums[i]);
            dfs(i + 1);
            t.pop_back();
            while (i + 1 < n && nums[i + 1] == nums[i]) {
                ++i;
            }
            dfs(i + 1);
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

    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        this.nums = nums;
        dfs(0);
        return ans;
    }

    private void dfs(int i) {
        if (i >= nums.length) {
            ans.add(new ArrayList<>(t));
            return;
        }
        t.add(nums[i]);
        dfs(i + 1);
        int x = t.remove(t.size() - 1);
        while (i + 1 < nums.length && nums[i + 1] == x) {
            ++i;
        }
        dfs(i + 1);
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0090  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        # 定义深度优先搜索（DFS）函数
        def dfs(i: int):
            # 如果当前索引已经到达数组末尾，将当前路径（t）加入答案列表（ans）并返回
            if i == len(nums):
                ans.append(t[:])  # 将当前路径的拷贝加入结果集
                return
            # 将当前数字加入路径
            t.append(nums[i])
            dfs(i + 1)  # 递归处理下一个数字
            # 回溯：移除最后一个数字
            x = t.pop()
            # 跳过所有与当前数字相同的后续数字（去重）
            while i + 1 < len(nums) and nums[i + 1] == x:
                i += 1
            # 递归处理跳过后的下一个数字
            dfs(i + 1)

        # 对数组进行排序，以便相同的数字相邻，方便去重
        nums.sort()
        ans = []  # 存储所有子集的结果列表
        t = []    # 当前路径（子集）
        dfs(0)    # 从索引 0 开始深度优先搜索
        return ans  # 返回所有子集
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        ranges::sort(nums);
        vector<vector<int>> ans;
        vector<int> t;
        int n = nums.size();
        auto dfs = [&](this auto&& dfs, int i) {
            if (i >= n) {
                ans.push_back(t);
                return;
            }
            t.push_back(nums[i]);
            dfs(i + 1);
            t.pop_back();
            while (i + 1 < n && nums[i + 1] == nums[i]) {
                ++i;
            }
            dfs(i + 1);
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

    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        this.nums = nums;
        dfs(0);
        return ans;
    }

    private void dfs(int i) {
        if (i >= nums.length) {
            ans.add(new ArrayList<>(t));
            return;
        }
        t.add(nums[i]);
        dfs(i + 1);
        int x = t.remove(t.size() - 1);
        while (i + 1 < nums.length && nums[i + 1] == x) {
            ++i;
        }
        dfs(i + 1);
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0090  数学解释

```python 
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        def dfs(i: int):
            if i == len(nums):
                ans.append(t[:])
                return
            t.append(nums[i])
            dfs(i + 1)
            x = t.pop()
            while i + 1 < len(nums) and nums[i + 1] == x:
                i += 1
            dfs(i + 1)

        nums.sort()
        ans = []
        t = []
        dfs(0)
        return ans 
```


这段代码的功能是解决**子集 II**问题（LeetCode第90题）。它生成一个数组的所有子集，同时确保结果中没有重复的子集。以下是从数学思想角度对代码的解释。

---

### 1. **问题背景**
给定一个可能包含重复元素的整数数组 `nums`，我们需要返回所有可能的子集（幂集），并且结果中不能包含重复的子集。

从数学角度来看，这实际上是一个**组合问题**，但需要额外处理重复情况。

---

### 2. **数学思想**
1. **幂集的定义**  
   对于一个长度为 \\( n \\) 的数组 `nums`，其幂集是所有可能子集的集合。  
   一个集合的幂集大小为 \\( 2^n \\)（因为每个元素都有两种状态：选中或不选中）。

2. **重复元素的处理**  
   如果数组中存在重复元素，直接生成的幂集可能包含重复的子集。为避免重复，需要在递归过程中跳过连续相同的元素。

3. **递归构造子集**  
   - 对于每个元素，有两种选择：将其包含在当前子集中或不包含。
   - 通过递归，逐步构造所有可能的子集。

---

### 3. **代码解读与数学分析**
#### (1) **代码结构**
- `nums.sort()`：先对数组排序。排序的目的是将相同的元素排列在一起，方便后续去重处理。
- `dfs(i)`：深度优先搜索（DFS）递归函数，用于构造子集。
  - 参数 `i` 表示当前处理的数组下标。
  - 递归过程中，维护一个临时数组 `t`，表示当前构造的子集。

#### (2) **递归的数学意义**
- **递归的基本思想**：  
  每次递归有两种选择：
  1. **选中当前元素 `nums[i]`**：将其加入临时数组 `t`。
  2. **跳过当前元素 `nums[i]`**：不将其加入 `t`。
  
  通过这两种选择，递归构造出所有可能的子集。

- **递归终止条件**：  
  当 `i == len(nums)` 时，表示已经处理完数组中的所有元素，此时将当前子集 `t` 加入答案 `ans` 中。

#### (3) **去重的数学处理**
- **问题**：如果数组中有重复元素，直接递归会生成重复的子集。例如，对于输入 `[1, 2, 2]`，可能会生成两个 `[1, 2]`。
- **解决方法**：  
  当跳过当前元素时，检查下一个元素是否与当前元素相同。如果相同，则跳过所有重复的元素，避免生成重复的子集。

  数学上，这相当于对相同的元素只进行一次选择。

  ```python
  while i + 1 < len(nums) and nums[i + 1] == x:
      i += 1
  ```
  这段代码跳过了所有值为 `x` 的重复元素。

#### (4) **时间复杂度分析**
- 对于一个长度为 \\( n \\) 的数组，理论上有 \\( 2^n \\) 个子集。
- 由于排序操作需要 \\( O(n \log n) \\)，再加上递归过程中避免重复，实际复杂度比 \\( O(2^n) \\) 略低。

---

### 4. **完整流程**
以下是算法的完整执行流程：
1. **排序数组**：确保重复元素相邻。
2. **递归构造子集**：
   - 对于每个元素，选择包含或不包含。
   - 遇到重复元素时，跳过重复值，避免生成重复子集。
3. **终止递归**：当遍历到数组末尾时，将当前子集加入结果。

---

### 5. **示例分析**
#### 输入：
```python
nums = [1, 2, 2]
```

#### 排序：
```python
nums = [1, 2, 2]
```

#### 递归过程：
- 初始调用：`dfs(0)`，`t = []`，`ans = []`
- 选择 `1`：`t = [1]`，递归调用 `dfs(1)`
  - 选择 `2`：`t = [1, 2]`，递归调用 `dfs(2)`
    - 选择 `2`：`t = [1, 2, 2]`，递归调用 `dfs(3)`，加入结果。
    - 跳过 `2`：`t = [1, 2]`，递归调用 `dfs(3)`，加入结果。
  - 跳过 `2`：`t = [1]`，递归调用 `dfs(3)`，加入结果。
- 跳过 `1`：`t = []`，递归调用 `dfs(1)`
  - 选择 `2`：`t = [2]`，递归调用 `dfs(2)`
    - 选择 `2`：`t = [2, 2]`，递归调用 `dfs(3)`，加入结果。
    - 跳过 `2`：`t = [2]`，递归调用 `dfs(3)`，加入结果。
  - 跳过 `2`：`t = []`，递归调用 `dfs(3)`，加入结果。

#### 输出：
```python
ans = [[], [1], [1, 2], [1, 2, 2], [2], [2, 2]]
```

---

### 6. **总结**
这段代码通过**排序 + 跳过重复值**的方式，利用递归生成所有子集，避免了重复子集的生成。它结合了**数学中的组合思想**和**算法中的剪枝技巧**，高效地解决了问题。

