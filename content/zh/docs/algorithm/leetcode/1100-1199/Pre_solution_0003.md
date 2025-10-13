---
title: "1120_子树的最大平均值 🔒"
date: 2025-10-08T18:36:57+08:00
weight: 3
tags: [二叉树, 位运算, 前缀和, 动态规划, 单调栈, 哈希表, 图, 广度优先搜索, 排序, 数据库, 数组, 栈, 树, 深度优先搜索, 状态压缩, 计数, 计数排序]
---

{{< markmap >}}
### [1120_子树的最大平均值 🔒](#1120)
#### [树](#1120)
#### [深度优先搜索](#1120)
#### [二叉树](#1120)
### [1121_将数组分成几个递增序列 🔒](#1121)
#### [数组](#1121)
#### [计数](#1121)
### [1122_数组的相对排序](#1122)
#### [数组](#1122)
#### [哈希表](#1122)
#### [计数排序](#1122)
#### [排序](#1122)
### [1123_最深叶节点的最近公共祖先](#1123)
#### [树](#1123)
#### [深度优先搜索](#1123)
#### [广度优先搜索](#1123)
#### [哈希表](#1123)
#### [二叉树](#1123)
### [1124_表现良好的最长时间段](#1124)
#### [栈](#1124)
#### [数组](#1124)
#### [哈希表](#1124)
#### [前缀和](#1124)
#### [单调栈](#1124)
### [1125_最小的必要团队](#1125)
#### [位运算](#1125)
#### [数组](#1125)
#### [动态规划](#1125)
#### [状态压缩](#1125)
### [1126_查询活跃业务 🔒](#1126)
#### [数据库](#1126)
### [1127_用户购买平台 🔒](#1127)
#### [数据库](#1127)
### [1128_等价多米诺骨牌对的数量](#1128)
#### [数组](#1128)
#### [哈希表](#1128)
#### [计数](#1128)
### [1129_颜色交替的最短路径](#1129)
#### [广度优先搜索](#1129)
#### [图](#1129)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1120_子树的最大平均值 🔒
___
#### 树
___
#### 深度优先搜索
___
#### 二叉树
---
### 1121_将数组分成几个递增序列 🔒
___
#### 数组
___
#### 计数
---
### 1122_数组的相对排序
___
#### 数组
___
#### 哈希表
___
#### 计数排序
___
#### 排序
---
### 1123_最深叶节点的最近公共祖先
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 哈希表
___
#### 二叉树
---
### 1124_表现良好的最长时间段
___
#### 栈
___
#### 数组
___
#### 哈希表
___
#### 前缀和
___
#### 单调栈
---
### 1125_最小的必要团队
___
#### 位运算
___
#### 数组
___
#### 动态规划
___
#### 状态压缩
---
### 1126_查询活跃业务 🔒
___
#### 数据库
---
### 1127_用户购买平台 🔒
___
#### 数据库
---
### 1128_等价多米诺骨牌对的数量
___
#### 数组
___
#### 哈希表
___
#### 计数
---
### 1129_颜色交替的最短路径
___
#### 广度优先搜索
___
#### 图
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二叉树 | 位运算 | 前缀和 |
| 动态规划 | 单调栈 | 哈希表 |
| 图 | 广度优先搜索 | 排序 |
| 数据库 | 数组 | 栈 |
| 树 | 深度优先搜索 | 状态压缩 |
| 计数 | 计数排序 |  |

# [1120. 子树的最大平均值 🔒](https://leetcode.cn/problems/maximum-average-subtree){#1120}

{{< tabs "1120" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maximumAverageSubtree(self, root: Optional[TreeNode]) -> float:
        def dfs(root):
            if root is None:
                return 0, 0
            ls, ln = dfs(root.left)
            rs, rn = dfs(root.right)
            s = root.val + ls + rs
            n = 1 + ln + rn
            nonlocal ans
            ans = max(ans, s / n)
            return s, n

        ans = 0
        dfs(root)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private double ans;

    public double maximumAverageSubtree(TreeNode root) {
        dfs(root);
        return ans;
    }

    private int[] dfs(TreeNode root) {
        if (root == null) {
            return new int[2];
        }
        var l = dfs(root.left);
        var r = dfs(root.right);
        int s = root.val + l[0] + r[0];
        int n = 1 + l[1] + r[1];
        ans = Math.max(ans, s * 1.0 / n);
        return new int[] {s, n};
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    double maximumAverageSubtree(TreeNode* root) {
        double ans = 0;
        auto dfs = [&](this auto&& dfs, TreeNode* root) -> pair<int, int> {
            if (!root) {
                return {0, 0};
            }
            auto [ls, ln] = dfs(root->left);
            auto [rs, rn] = dfs(root->right);
            int s = root->val + ls + rs;
            int n = 1 + ln + rn;
            ans = max(ans, s * 1.0 / n);
            return {s, n};
        };
        dfs(root);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func maximumAverageSubtree(root *TreeNode) (ans float64) {
	var dfs func(*TreeNode) [2]int
	dfs = func(root *TreeNode) [2]int {
		if root == nil {
			return [2]int{}
		}
		l, r := dfs(root.Left), dfs(root.Right)
		s := root.Val + l[0] + r[0]
		n := 1 + l[1] + r[1]
		ans = math.Max(ans, float64(s)/float64(n))
		return [2]int{s, n}
	}
	dfs(root)
	return
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一棵二叉树的根节点&nbsp;<code>root</code>，找出这棵树的 <strong>每一棵</strong> 子树的 <strong>平均值</strong> 中的 <strong>最大</strong> 值。</p>

<p>子树是树中的任意节点和它的所有后代构成的集合。</p>

<p>树的平均值是树中节点值的总和除以节点数。</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1100-1199/1120.Maximum%20Average%20Subtree/images/1308_example_1.png" style="height: 123px; width: 132px;"></p>

<pre><strong>输入：</strong>[5,6,1]
<strong>输出：</strong>6.00000
<strong>解释： </strong>
以 value = 5 的节点作为子树的根节点，得到的平均值为 (5 + 6 + 1) / 3 = 4。
以 value = 6 的节点作为子树的根节点，得到的平均值为 6 / 1 = 6。
以 value = 1 的节点作为子树的根节点，得到的平均值为 1 / 1 = 1。
所以答案取最大值 6。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li>树中的节点数介于&nbsp;<code>1</code> 到&nbsp;<code>5000</code>之间。</li>
	<li>每个节点的值介于&nbsp;<code>0</code> 到&nbsp;<code>100000</code>&nbsp;之间。</li>
	<li>如果结果与标准答案的误差不超过&nbsp;<code>10^-5</code>，那么该结果将被视为正确答案。</li>
</ol>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归

我们可以使用递归的方法，对于每个节点，计算以该节点为根的子树的节点和以及节点个数，然后计算平均值，与当前最大值比较，更新最大值。

因此，我们设计一个函数 $dfs(root)$，表示以 $root$ 为根的子树的节点和以及节点个数，返回值为一个长度为 $2$ 的数组，其中第一个元素表示节点和，第二个元素表示节点个数。

函数 $dfs(root)$ 的递归过程如下：

-   如果 $root$ 为空，返回 $[0, 0]$；
-   否则，计算 $root$ 的左子树的节点和以及节点个数，记为 $[ls, ln]$；计算 $root$ 的右子树的节点和以及节点个数，记为 $[rs, rn]$。那么以 $root$ 为根的子树的节点和为 $root.val + ls + rs$，节点个数为 $1 + ln + rn$，计算平均值，与当前最大值比较，更新最大值；
-   返回 $[root.val + ls + rs, 1 + ln + rn]$。

最后，返回最大值即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为二叉树的节点个数。

<!-- tabs:start -->

#### Python3

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maximumAverageSubtree(self, root: Optional[TreeNode]) -> float:
        def dfs(root):
            if root is None:
                return 0, 0
            ls, ln = dfs(root.left)
            rs, rn = dfs(root.right)
            s = root.val + ls + rs
            n = 1 + ln + rn
            nonlocal ans
            ans = max(ans, s / n)
            return s, n

        ans = 0
        dfs(root)
        return ans
```

#### Java

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private double ans;

    public double maximumAverageSubtree(TreeNode root) {
        dfs(root);
        return ans;
    }

    private int[] dfs(TreeNode root) {
        if (root == null) {
            return new int[2];
        }
        var l = dfs(root.left);
        var r = dfs(root.right);
        int s = root.val + l[0] + r[0];
        int n = 1 + l[1] + r[1];
        ans = Math.max(ans, s * 1.0 / n);
        return new int[] {s, n};
    }
}
```

#### C++

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    double maximumAverageSubtree(TreeNode* root) {
        double ans = 0;
        auto dfs = [&](this auto&& dfs, TreeNode* root) -> pair<int, int> {
            if (!root) {
                return {0, 0};
            }
            auto [ls, ln] = dfs(root->left);
            auto [rs, rn] = dfs(root->right);
            int s = root->val + ls + rs;
            int n = 1 + ln + rn;
            ans = max(ans, s * 1.0 / n);
            return {s, n};
        };
        dfs(root);
        return ans;
    }
};
```

#### Go

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func maximumAverageSubtree(root *TreeNode) (ans float64) {
	var dfs func(*TreeNode) [2]int
	dfs = func(root *TreeNode) [2]int {
		if root == nil {
			return [2]int{}
		}
		l, r := dfs(root.Left), dfs(root.Right)
		s := root.Val + l[0] + r[0]
		n := 1 + l[1] + r[1]
		ans = math.Max(ans, float64(s)/float64(n))
		return [2]int{s, n}
	}
	dfs(root)
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1121. 将数组分成几个递增序列 🔒](https://leetcode.cn/problems/divide-array-into-increasing-sequences){#1121}

{{< tabs "1121" >}}

{{% tab "python" %}}
```python
class Solution:
    def canDivideIntoSubsequences(self, nums: List[int], k: int) -> bool:
        mx = max(len(list(x)) for _, x in groupby(nums))
        return mx * k <= len(nums)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean canDivideIntoSubsequences(int[] nums, int k) {
        int cnt = 0;
        int a = 0;
        for (int b : nums) {
            cnt = a == b ? cnt + 1 : 1;
            if (cnt * k > nums.length) {
                return false;
            }
            a = b;
        }
        return true;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool canDivideIntoSubsequences(vector<int>& nums, int k) {
        int cnt = 0;
        int a = 0;
        for (int& b : nums) {
            cnt = a == b ? cnt + 1 : 1;
            if (cnt * k > nums.size()) {
                return false;
            }
            a = b;
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func canDivideIntoSubsequences(nums []int, k int) bool {
	cnt, a := 0, 0
	for _, b := range nums {
		cnt++
		if a != b {
			cnt = 1
		}
		if cnt*k > len(nums) {
			return false
		}
		a = b
	}
	return true
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 <strong>非递减</strong> 的正整数数组&nbsp;<code>nums</code>&nbsp;和整数&nbsp;<code>K</code>，判断该数组是否可以被分成一个或几个&nbsp;<strong>长度至少&nbsp;为 </strong><code>K</code><strong> 的 不相交的递增子序列</strong>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,2,3,3,4,4], K = 3
<strong>输出：</strong>true
<strong>解释：</strong>
该数组可以分成两个子序列 [1,2,3,4] 和 [2,3,4]，每个子序列的长度都至少是 3。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [5,6,6,7,8], K = 3
<strong>输出：</strong>false
<strong>解释：</strong>
没有办法根据条件来划分数组。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>1 &lt;= nums.length&nbsp;&lt;= 10^5</code></li>
	<li><code>1 &lt;= K &lt;= nums.length</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10^5</code></li>
</ol>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：脑筋急转弯

我们假设可以将数组分成 $m$ 个长度至少为 $k$ 的严格递增子序列，如果数组中出现次数最多的数字的个数为 $cnt$，那么这 $cnt$ 个数字必须在不同的子序列中，所以 $m \geq cnt$，又因为 $m$ 个子序列的长度至少为 $k$，因此，子序列的个数越少越好，所以 $m = cnt$。那么 $cnt \times k \leq n$，才能满足题意。因此，我们只需要统计数组中出现次数最多的数字的个数 $cnt$，然后判断 $cnt \times k \leq n$ 即可。如果是，返回 `true`，否则返回 `false`。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canDivideIntoSubsequences(self, nums: List[int], k: int) -> bool:
        mx = max(len(list(x)) for _, x in groupby(nums))
        return mx * k <= len(nums)
```

#### Java

```java
class Solution {
    public boolean canDivideIntoSubsequences(int[] nums, int k) {
        Map<Integer, Integer> cnt = new HashMap<>();
        int mx = 0;
        for (int x : nums) {
            mx = Math.max(mx, cnt.merge(x, 1, Integer::sum));
        }
        return mx * k <= nums.length;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool canDivideIntoSubsequences(vector<int>& nums, int k) {
        int cnt = 0;
        int a = 0;
        for (int& b : nums) {
            cnt = a == b ? cnt + 1 : 1;
            if (cnt * k > nums.size()) {
                return false;
            }
            a = b;
        }
        return true;
    }
};
```

#### Go

```go
func canDivideIntoSubsequences(nums []int, k int) bool {
	cnt, a := 0, 0
	for _, b := range nums {
		cnt++
		if a != b {
			cnt = 1
		}
		if cnt*k > len(nums) {
			return false
		}
		a = b
	}
	return true
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Java

```java
class Solution {
    public boolean canDivideIntoSubsequences(int[] nums, int k) {
        int cnt = 0;
        int a = 0;
        for (int b : nums) {
            cnt = a == b ? cnt + 1 : 1;
            if (cnt * k > nums.length) {
                return false;
            }
            a = b;
        }
        return true;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1122. 数组的相对排序](https://leetcode.cn/problems/relative-sort-array){#1122}

{{< tabs "1122" >}}

{{% tab "python" %}}
```python
class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        cnt = Counter(arr1)
        ans = []
        for x in arr2:
            ans.extend([x] * cnt[x])
            cnt.pop(x)
        mi, mx = min(arr1), max(arr1)
        for x in range(mi, mx + 1):
            ans.extend([x] * cnt[x])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        int[] cnt = new int[1001];
        int mi = 1001, mx = 0;
        for (int x : arr1) {
            ++cnt[x];
            mi = Math.min(mi, x);
            mx = Math.max(mx, x);
        }
        int m = arr1.length;
        int[] ans = new int[m];
        int i = 0;
        for (int x : arr2) {
            while (cnt[x] > 0) {
                --cnt[x];
                ans[i++] = x;
            }
        }
        for (int x = mi; x <= mx; ++x) {
            while (cnt[x] > 0) {
                --cnt[x];
                ans[i++] = x;
            }
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> cnt(1001);
        for (int x : arr1) {
            ++cnt[x];
        }
        auto [mi, mx] = minmax_element(arr1.begin(), arr1.end());
        vector<int> ans;
        for (int x : arr2) {
            while (cnt[x]) {
                ans.push_back(x);
                --cnt[x];
            }
        }
        for (int x = *mi; x <= *mx; ++x) {
            while (cnt[x]) {
                ans.push_back(x);
                --cnt[x];
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func relativeSortArray(arr1 []int, arr2 []int) []int {
	cnt := make([]int, 1001)
	mi, mx := 1001, 0
	for _, x := range arr1 {
		cnt[x]++
		mi = min(mi, x)
		mx = max(mx, x)
	}
	ans := make([]int, 0, len(arr1))
	for _, x := range arr2 {
		for cnt[x] > 0 {
			ans = append(ans, x)
			cnt[x]--
		}
	}
	for x := mi; x <= mx; x++ {
		for cnt[x] > 0 {
			ans = append(ans, x)
			cnt[x]--
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function relativeSortArray(arr1: number[], arr2: number[]): number[] {
    const cnt = Array(1001).fill(0);
    let mi = Number.POSITIVE_INFINITY;
    let mx = Number.NEGATIVE_INFINITY;

    for (const x of arr1) {
        cnt[x]++;
        mi = Math.min(mi, x);
        mx = Math.max(mx, x);
    }

    const ans: number[] = [];
    for (const x of arr2) {
        while (cnt[x]) {
            cnt[x]--;
            ans.push(x);
        }
    }

    for (let i = mi; i <= mx; i++) {
        while (cnt[i]) {
            cnt[i]--;
            ans.push(i);
        }
    }

    return ans;
}
```
{{% /tab %}}
{{% tab "swift" %}}
```swift
class Solution {
    func relativeSortArray(_ arr1: [Int], _ arr2: [Int]) -> [Int] {
        var cnt = [Int](repeating: 0, count: 1001)
        for x in arr1 {
            cnt[x] += 1
        }

        guard let mi = arr1.min(), let mx = arr1.max() else {
            return []
        }

        var ans = [Int]()
        for x in arr2 {
            while cnt[x] > 0 {
                ans.append(x)
                cnt[x] -= 1
            }
        }

        for x in mi...mx {
            while cnt[x] > 0 {
                ans.append(x)
                cnt[x] -= 1
            }
        }

        return ans
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个数组，<code>arr1</code> 和&nbsp;<code>arr2</code>，<code>arr2</code>&nbsp;中的元素各不相同，<code>arr2</code> 中的每个元素都出现在&nbsp;<code>arr1</code>&nbsp;中。</p>

<p>对 <code>arr1</code>&nbsp;中的元素进行排序，使 <code>arr1</code> 中项的相对顺序和&nbsp;<code>arr2</code>&nbsp;中的相对顺序相同。未在&nbsp;<code>arr2</code>&nbsp;中出现过的元素需要按照升序放在&nbsp;<code>arr1</code>&nbsp;的末尾。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
<strong>输出：</strong>[2,2,2,1,4,3,3,9,6,7,19]
</pre>

<p><strong>示例 &nbsp;2:</strong></p>

<pre>
<strong>输入：</strong>arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6]
<strong>输出：</strong>[22,28,8,6,17,44]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr1.length, arr2.length &lt;= 1000</code></li>
	<li><code>0 &lt;= arr1[i], arr2[i] &lt;= 1000</code></li>
	<li><code>arr2</code>&nbsp;中的元素&nbsp;<code>arr2[i]</code>&nbsp;&nbsp;<strong>各不相同</strong>&nbsp;</li>
	<li><code>arr2</code> 中的每个元素&nbsp;<code>arr2[i]</code>&nbsp;都出现在&nbsp;<code>arr1</code>&nbsp;中</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：自定义排序

我们先用哈希表 $pos$ 记录数组 $arr2$ 中每个元素的位置。然后，我们将数组 $arr1$ 中的每个元素映射成一个二元组 $(pos.get(x, 1000 + x), x)$，并对二元组进行排序。最后我们取出所有二元组的第二个元素并返回即可。

时间复杂度 $O(n \times \log n + m)$，空间复杂度 $O(n + m)$。其中 $n$ 和 $m$ 分别是数组 $arr1$ 和 $arr2$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        pos = {x: i for i, x in enumerate(arr2)}
        return sorted(arr1, key=lambda x: pos.get(x, 1000 + x))
```

#### Java

```java
class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        Map<Integer, Integer> pos = new HashMap<>(arr2.length);
        for (int i = 0; i < arr2.length; ++i) {
            pos.put(arr2[i], i);
        }
        int[][] arr = new int[arr1.length][0];
        for (int i = 0; i < arr.length; ++i) {
            arr[i] = new int[] {arr1[i], pos.getOrDefault(arr1[i], arr2.length + arr1[i])};
        }
        Arrays.sort(arr, (a, b) -> a[1] - b[1]);
        for (int i = 0; i < arr.length; ++i) {
            arr1[i] = arr[i][0];
        }
        return arr1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> pos;
        for (int i = 0; i < arr2.size(); ++i) {
            pos[arr2[i]] = i;
        }
        vector<pair<int, int>> arr;
        for (int i = 0; i < arr1.size(); ++i) {
            int j = pos.count(arr1[i]) ? pos[arr1[i]] : arr2.size();
            arr.emplace_back(j, arr1[i]);
        }
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr1.size(); ++i) {
            arr1[i] = arr[i].second;
        }
        return arr1;
    }
};
```

#### Go

```go
func relativeSortArray(arr1 []int, arr2 []int) []int {
	pos := map[int]int{}
	for i, x := range arr2 {
		pos[x] = i
	}
	arr := make([][2]int, len(arr1))
	for i, x := range arr1 {
		if p, ok := pos[x]; ok {
			arr[i] = [2]int{p, x}
		} else {
			arr[i] = [2]int{len(arr2), x}
		}
	}
	sort.Slice(arr, func(i, j int) bool {
		return arr[i][0] < arr[j][0] || arr[i][0] == arr[j][0] && arr[i][1] < arr[j][1]
	})
	for i, x := range arr {
		arr1[i] = x[1]
	}
	return arr1
}
```

#### TypeScript

```ts
function relativeSortArray(arr1: number[], arr2: number[]): number[] {
    const pos: Map<number, number> = new Map();
    for (let i = 0; i < arr2.length; ++i) {
        pos.set(arr2[i], i);
    }
    const arr: number[][] = [];
    for (const x of arr1) {
        const j = pos.get(x) ?? arr2.length;
        arr.push([j, x]);
    }
    arr.sort((a, b) => a[0] - b[0] || a[1] - b[1]);
    return arr.map(a => a[1]);
}
```

#### Swift

```swift
class Solution {
    func relativeSortArray(_ arr1: [Int], _ arr2: [Int]) -> [Int] {
        var pos = [Int: Int]()
        for (i, x) in arr2.enumerated() {
            pos[x] = i
        }
        var arr = [(Int, Int)]()
        for x in arr1 {
            let j = pos[x] ?? arr2.count
            arr.append((j, x))
        }
        arr.sort { $0.0 < $1.0 || ($0.0 == $1.0 && $0.1 < $1.1) }
        return arr.map { $0.1 }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：计数排序

我们可以使用计数排序的思想，首先统计数组 $arr1$ 中每个元素的出现次数，然后按照数组 $arr2$ 中的顺序，将 $arr1$ 中的元素按照出现次数放入答案数组 $ans$ 中。最后，我们遍历 $arr1$ 中的所有元素，将未在 $arr2$ 中出现的元素按照升序放入答案数组 $ans$ 的末尾。

时间复杂度 $O(n + m)$，空间复杂度 $O(n)$。其中 $n$ 和 $m$ 分别是数组 $arr1$ 和 $arr2$ 的长度。

<!-- solution:start -->

#### Python3

```python
class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        cnt = Counter(arr1)
        ans = []
        for x in arr2:
            ans.extend([x] * cnt[x])
            cnt.pop(x)
        mi, mx = min(arr1), max(arr1)
        for x in range(mi, mx + 1):
            ans.extend([x] * cnt[x])
        return ans
```

#### Java

```java
class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        int[] cnt = new int[1001];
        int mi = 1001, mx = 0;
        for (int x : arr1) {
            ++cnt[x];
            mi = Math.min(mi, x);
            mx = Math.max(mx, x);
        }
        int m = arr1.length;
        int[] ans = new int[m];
        int i = 0;
        for (int x : arr2) {
            while (cnt[x] > 0) {
                --cnt[x];
                ans[i++] = x;
            }
        }
        for (int x = mi; x <= mx; ++x) {
            while (cnt[x] > 0) {
                --cnt[x];
                ans[i++] = x;
            }
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> cnt(1001);
        for (int x : arr1) {
            ++cnt[x];
        }
        auto [mi, mx] = minmax_element(arr1.begin(), arr1.end());
        vector<int> ans;
        for (int x : arr2) {
            while (cnt[x]) {
                ans.push_back(x);
                --cnt[x];
            }
        }
        for (int x = *mi; x <= *mx; ++x) {
            while (cnt[x]) {
                ans.push_back(x);
                --cnt[x];
            }
        }
        return ans;
    }
};
```

#### Go

```go
func relativeSortArray(arr1 []int, arr2 []int) []int {
	cnt := make([]int, 1001)
	mi, mx := 1001, 0
	for _, x := range arr1 {
		cnt[x]++
		mi = min(mi, x)
		mx = max(mx, x)
	}
	ans := make([]int, 0, len(arr1))
	for _, x := range arr2 {
		for cnt[x] > 0 {
			ans = append(ans, x)
			cnt[x]--
		}
	}
	for x := mi; x <= mx; x++ {
		for cnt[x] > 0 {
			ans = append(ans, x)
			cnt[x]--
		}
	}
	return ans
}
```

#### TypeScript

```ts
function relativeSortArray(arr1: number[], arr2: number[]): number[] {
    const cnt = Array(1001).fill(0);
    let mi = Number.POSITIVE_INFINITY;
    let mx = Number.NEGATIVE_INFINITY;

    for (const x of arr1) {
        cnt[x]++;
        mi = Math.min(mi, x);
        mx = Math.max(mx, x);
    }

    const ans: number[] = [];
    for (const x of arr2) {
        while (cnt[x]) {
            cnt[x]--;
            ans.push(x);
        }
    }

    for (let i = mi; i <= mx; i++) {
        while (cnt[i]) {
            cnt[i]--;
            ans.push(i);
        }
    }

    return ans;
}
```

#### Swift

```swift
class Solution {
    func relativeSortArray(_ arr1: [Int], _ arr2: [Int]) -> [Int] {
        var cnt = [Int](repeating: 0, count: 1001)
        for x in arr1 {
            cnt[x] += 1
        }

        guard let mi = arr1.min(), let mx = arr1.max() else {
            return []
        }

        var ans = [Int]()
        for x in arr2 {
            while cnt[x] > 0 {
                ans.append(x)
                cnt[x] -= 1
            }
        }

        for x in mi...mx {
            while cnt[x] > 0 {
                ans.append(x)
                cnt[x] -= 1
            }
        }

        return ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1123. 最深叶节点的最近公共祖先](https://leetcode.cn/problems/lowest-common-ancestor-of-deepest-leaves){#1123}

{{< tabs "1123" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def lcaDeepestLeaves(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def dfs(root):
            if root is None:
                return None, 0
            l, d1 = dfs(root.left)
            r, d2 = dfs(root.right)
            if d1 > d2:
                return l, d1 + 1
            if d1 < d2:
                return r, d2 + 1
            return root, d1 + 1

        return dfs(root)[0]
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode lcaDeepestLeaves(TreeNode root) {
        return dfs(root).getKey();
    }

    private Pair<TreeNode, Integer> dfs(TreeNode root) {
        if (root == null) {
            return new Pair<>(null, 0);
        }
        Pair<TreeNode, Integer> l = dfs(root.left);
        Pair<TreeNode, Integer> r = dfs(root.right);
        int d1 = l.getValue(), d2 = r.getValue();
        if (d1 > d2) {
            return new Pair<>(l.getKey(), d1 + 1);
        }
        if (d1 < d2) {
            return new Pair<>(r.getKey(), d2 + 1);
        }
        return new Pair<>(root, d1 + 1);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        auto dfs = [&](this auto&& dfs, TreeNode* root) -> pair<TreeNode*, int> {
            if (!root) {
                return {nullptr, 0};
            }
            auto [l, d1] = dfs(root->left);
            auto [r, d2] = dfs(root->right);
            if (d1 > d2) {
                return {l, d1 + 1};
            }
            if (d1 < d2) {
                return {r, d2 + 1};
            }
            return {root, d1 + 1};
        };
        return dfs(root).first;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
type pair struct {
	first  *TreeNode
	second int
}

func lcaDeepestLeaves(root *TreeNode) *TreeNode {
	var dfs func(root *TreeNode) pair
	dfs = func(root *TreeNode) pair {
		if root == nil {
			return pair{nil, 0}
		}
		l, r := dfs(root.Left), dfs(root.Right)
		d1, d2 := l.second, r.second
		if d1 > d2 {
			return pair{l.first, d1 + 1}
		}
		if d1 < d2 {
			return pair{r.first, d2 + 1}
		}
		return pair{root, d1 + 1}
	}
	return dfs(root).first
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function lcaDeepestLeaves(root: TreeNode | null): TreeNode | null {
    const dfs = (root: TreeNode | null): [TreeNode | null, number] => {
        if (root === null) {
            return [null, 0];
        }
        const [l, d1] = dfs(root.left);
        const [r, d2] = dfs(root.right);
        if (d1 > d2) {
            return [l, d1 + 1];
        }
        if (d1 < d2) {
            return [r, d2 + 1];
        }
        return [root, d1 + 1];
    };
    return dfs(root)[0];
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val = 0, TreeNode left = null, TreeNode right = null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    public TreeNode LcaDeepestLeaves(TreeNode root) {
        (TreeNode, int) Dfs(TreeNode root) {
            if (root == null) {
                return (null, 0);
            }

            var l = Dfs(root.left);
            var r = Dfs(root.right);
            int d1 = l.Item2;
            int d2 = r.Item2;

            if (d1 > d2) {
                return (l.Item1, d1 + 1);
            }
            if (d1 < d2) {
                return (r.Item1, d2 + 1);
            }
            return (root, d1 + 1);
        }

        return Dfs(root).Item1;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个有根节点<meta charset="UTF-8" />&nbsp;<code>root</code>&nbsp;的二叉树，返回它&nbsp;<em>最深的叶节点的最近公共祖先</em>&nbsp;。</p>

<p>回想一下：</p>

<ul>
	<li><strong>叶节点</strong> 是二叉树中没有子节点的节点</li>
	<li>树的根节点的&nbsp;<strong>深度&nbsp;</strong>为&nbsp;<code>0</code>，如果某一节点的深度为&nbsp;<code>d</code>，那它的子节点的深度就是&nbsp;<code>d+1</code></li>
	<li>如果我们假定 <code>A</code> 是一组节点&nbsp;<code>S</code>&nbsp;的 <strong>最近公共祖先</strong>，<code>S</code>&nbsp;中的每个节点都在以 <code>A</code> 为根节点的子树中，且 <code>A</code>&nbsp;的深度达到此条件下可能的最大值。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1100-1199/1123.Lowest%20Common%20Ancestor%20of%20Deepest%20Leaves/images/sketch1.png" style="height: 340px; width: 400px;" />
<pre>
<strong>输入：</strong>root = [3,5,1,6,2,0,8,null,null,7,4]
<strong>输出：</strong>[2,7,4]
<strong>解释：</strong>我们返回值为 2 的节点，在图中用黄色标记。
在图中用蓝色标记的是树的最深的节点。
注意，节点 6、0 和 8 也是叶节点，但是它们的深度是 2 ，而节点 7 和 4 的深度是 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>root = [1]
<strong>输出：</strong>[1]
<strong>解释：</strong>根节点是树中最深的节点，它是它本身的最近公共祖先。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>root = [0,1,3,null,2]
<strong>输出：</strong>[2]
<strong>解释：</strong>树中最深的叶节点是 2 ，最近公共祖先是它自己。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中的节点数将在<meta charset="UTF-8" />&nbsp;<code>[1, 1000]</code>&nbsp;的范围内。</li>
	<li><code>0 &lt;= Node.val &lt;= 1000</code></li>
	<li>每个节点的值都是&nbsp;<strong>独一无二</strong>&nbsp;的。</li>
</ul>

<p>&nbsp;</p>

<p><strong>注意：</strong>本题与力扣 865 重复：<a href="https://leetcode.cn/problems/smallest-subtree-with-all-the-deepest-nodes/">https://leetcode.cn/problems/smallest-subtree-with-all-the-deepest-nodes/</a></p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们设计一个函数 $dfs(root)$，它将返回一个二元组 $(l, d)$，其中 $l$ 是节点 $root$ 的最深公共祖先，而 $d$ 是节点 $root$ 的深度。函数 $dfs(root)$ 的执行逻辑如下：

-   如果 $root$ 为空，则返回二元组 $(None, 0)$；
-   否则，我们递归调用 $dfs(root.left)$ 和 $dfs(root.right)$，得到二元组 $(l, d_1)$ 和 $(r, d_2)$。如果 $d_1 \gt d_2$，则 $root$ 的最深公共祖先节点为 $l$，深度为 $d_1 + 1$；如果 $d_1 \lt d_2$，则 $root$ 的最深公共祖先节点为 $r$，深度为 $d_2 + 1$；如果 $d_1 = d_2$，则 $root$ 的最深公共祖先节点为 $root$，深度为 $d_1 + 1$。

我们在主函数中调用 $dfs(root)$，并返回其返回值的第一个元素，即可得到最深公共祖先节点。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是二叉树的节点数。

<!-- tabs:start -->

#### Python3

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def lcaDeepestLeaves(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def dfs(root):
            if root is None:
                return None, 0
            l, d1 = dfs(root.left)
            r, d2 = dfs(root.right)
            if d1 > d2:
                return l, d1 + 1
            if d1 < d2:
                return r, d2 + 1
            return root, d1 + 1

        return dfs(root)[0]
```

#### Java

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode lcaDeepestLeaves(TreeNode root) {
        return dfs(root).getKey();
    }

    private Pair<TreeNode, Integer> dfs(TreeNode root) {
        if (root == null) {
            return new Pair<>(null, 0);
        }
        Pair<TreeNode, Integer> l = dfs(root.left);
        Pair<TreeNode, Integer> r = dfs(root.right);
        int d1 = l.getValue(), d2 = r.getValue();
        if (d1 > d2) {
            return new Pair<>(l.getKey(), d1 + 1);
        }
        if (d1 < d2) {
            return new Pair<>(r.getKey(), d2 + 1);
        }
        return new Pair<>(root, d1 + 1);
    }
}
```

#### C++

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        auto dfs = [&](this auto&& dfs, TreeNode* root) -> pair<TreeNode*, int> {
            if (!root) {
                return {nullptr, 0};
            }
            auto [l, d1] = dfs(root->left);
            auto [r, d2] = dfs(root->right);
            if (d1 > d2) {
                return {l, d1 + 1};
            }
            if (d1 < d2) {
                return {r, d2 + 1};
            }
            return {root, d1 + 1};
        };
        return dfs(root).first;
    }
};
```

#### Go

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
type pair struct {
	first  *TreeNode
	second int
}

func lcaDeepestLeaves(root *TreeNode) *TreeNode {
	var dfs func(root *TreeNode) pair
	dfs = func(root *TreeNode) pair {
		if root == nil {
			return pair{nil, 0}
		}
		l, r := dfs(root.Left), dfs(root.Right)
		d1, d2 := l.second, r.second
		if d1 > d2 {
			return pair{l.first, d1 + 1}
		}
		if d1 < d2 {
			return pair{r.first, d2 + 1}
		}
		return pair{root, d1 + 1}
	}
	return dfs(root).first
}
```

#### TypeScript

```ts
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function lcaDeepestLeaves(root: TreeNode | null): TreeNode | null {
    const dfs = (root: TreeNode | null): [TreeNode | null, number] => {
        if (root === null) {
            return [null, 0];
        }
        const [l, d1] = dfs(root.left);
        const [r, d2] = dfs(root.right);
        if (d1 > d2) {
            return [l, d1 + 1];
        }
        if (d1 < d2) {
            return [r, d2 + 1];
        }
        return [root, d1 + 1];
    };
    return dfs(root)[0];
}
```

#### C#

```cs
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val = 0, TreeNode left = null, TreeNode right = null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    public TreeNode LcaDeepestLeaves(TreeNode root) {
        (TreeNode, int) Dfs(TreeNode root) {
            if (root == null) {
                return (null, 0);
            }

            var l = Dfs(root.left);
            var r = Dfs(root.right);
            int d1 = l.Item2;
            int d2 = r.Item2;

            if (d1 > d2) {
                return (l.Item1, d1 + 1);
            }
            if (d1 < d2) {
                return (r.Item1, d2 + 1);
            }
            return (root, d1 + 1);
        }

        return Dfs(root).Item1;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1124. 表现良好的最长时间段](https://leetcode.cn/problems/longest-well-performing-interval){#1124}

{{< tabs "1124" >}}

{{% tab "python" %}}
```python
class Solution:
    def longestWPI(self, hours: List[int]) -> int:
        ans = s = 0
        pos = {}
        for i, x in enumerate(hours):
            s += 1 if x > 8 else -1
            if s > 0:
                ans = i + 1
            elif s - 1 in pos:
                ans = max(ans, i - pos[s - 1])
            if s not in pos:
                pos[s] = i
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int longestWPI(int[] hours) {
        int ans = 0, s = 0;
        Map<Integer, Integer> pos = new HashMap<>();
        for (int i = 0; i < hours.length; ++i) {
            s += hours[i] > 8 ? 1 : -1;
            if (s > 0) {
                ans = i + 1;
            } else if (pos.containsKey(s - 1)) {
                ans = Math.max(ans, i - pos.get(s - 1));
            }
            pos.putIfAbsent(s, i);
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int ans = 0, s = 0;
        unordered_map<int, int> pos;
        for (int i = 0; i < hours.size(); ++i) {
            s += hours[i] > 8 ? 1 : -1;
            if (s > 0) {
                ans = i + 1;
            } else if (pos.count(s - 1)) {
                ans = max(ans, i - pos[s - 1]);
            }
            if (!pos.count(s)) {
                pos[s] = i;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func longestWPI(hours []int) (ans int) {
	s := 0
	pos := map[int]int{}
	for i, x := range hours {
		if x > 8 {
			s++
		} else {
			s--
		}
		if s > 0 {
			ans = i + 1
		} else if j, ok := pos[s-1]; ok {
			ans = max(ans, i-j)
		}
		if _, ok := pos[s]; !ok {
			pos[s] = i
		}
	}
	return
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一份工作时间表&nbsp;<code>hours</code>，上面记录着某一位员工每天的工作小时数。</p>

<p>我们认为当员工一天中的工作小时数大于&nbsp;<code>8</code> 小时的时候，那么这一天就是「<strong>劳累的一天</strong>」。</p>

<p>所谓「表现良好的时间段」，意味在这段时间内，「劳累的天数」是严格<strong> 大于</strong>「不劳累的天数」。</p>

<p>请你返回「表现良好时间段」的最大长度。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>hours = [9,9,6,0,6,6,9]
<strong>输出：</strong>3
<strong>解释：</strong>最长的表现良好时间段是 [9,9,6]。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>hours = [6,6,6]
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= hours.length &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= hours[i] &lt;= 16</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和 + 哈希表

我们可以利用前缀和的思想，维护一个变量 $s$，表示从下标 $0$ 到当前下标的这一段，「劳累的天数」与「不劳累的天数」的差值。如果 $s$ 大于 $0$，说明从下标 $0$ 到当前下标的这一段，满足「表现良好的时间段」。另外，用哈希表 $pos$ 记录每个 $s$ 第一次出现的下标。

接下来，我们遍历数组 `hours`，对于每个下标 $i$：

-   如果 $hours[i] \gt 8$，我们就让 $s$ 加 $1$，否则减 $1$。
-   如果 $s$ 大于 $0$，说明从下标 $0$ 到当前下标的这一段，满足「表现良好的时间段」，我们更新结果 $ans = i + 1$。否则，如果 $s - 1$ 在哈希表 $pos$ 中，记 $j = pos[s - 1]$，说明从下标 $j + 1$ 到当前下标 $i$ 的这一段，满足「表现良好的时间段」，我们更新结果 $ans = \max(ans, i - j)$。
-   然后，如果 $s$ 不在哈希表 $pos$ 中，我们就记录 $pos[s] = i$。

遍历结束后，返回答案即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 `hours` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestWPI(self, hours: List[int]) -> int:
        ans = s = 0
        pos = {}
        for i, x in enumerate(hours):
            s += 1 if x > 8 else -1
            if s > 0:
                ans = i + 1
            elif s - 1 in pos:
                ans = max(ans, i - pos[s - 1])
            if s not in pos:
                pos[s] = i
        return ans
```

#### Java

```java
class Solution {
    public int longestWPI(int[] hours) {
        int ans = 0, s = 0;
        Map<Integer, Integer> pos = new HashMap<>();
        for (int i = 0; i < hours.length; ++i) {
            s += hours[i] > 8 ? 1 : -1;
            if (s > 0) {
                ans = i + 1;
            } else if (pos.containsKey(s - 1)) {
                ans = Math.max(ans, i - pos.get(s - 1));
            }
            pos.putIfAbsent(s, i);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int ans = 0, s = 0;
        unordered_map<int, int> pos;
        for (int i = 0; i < hours.size(); ++i) {
            s += hours[i] > 8 ? 1 : -1;
            if (s > 0) {
                ans = i + 1;
            } else if (pos.count(s - 1)) {
                ans = max(ans, i - pos[s - 1]);
            }
            if (!pos.count(s)) {
                pos[s] = i;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func longestWPI(hours []int) (ans int) {
	s := 0
	pos := map[int]int{}
	for i, x := range hours {
		if x > 8 {
			s++
		} else {
			s--
		}
		if s > 0 {
			ans = i + 1
		} else if j, ok := pos[s-1]; ok {
			ans = max(ans, i-j)
		}
		if _, ok := pos[s]; !ok {
			pos[s] = i
		}
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1125. 最小的必要团队](https://leetcode.cn/problems/smallest-sufficient-team){#1125}

{{< tabs "1125" >}}

{{% tab "python" %}}
```python
class Solution:
    def smallestSufficientTeam(
        self, req_skills: List[str], people: List[List[str]]
    ) -> List[int]:
        d = {s: i for i, s in enumerate(req_skills)}
        m, n = len(req_skills), len(people)
        p = [0] * n
        for i, ss in enumerate(people):
            for s in ss:
                p[i] |= 1 << d[s]
        f = [inf] * (1 << m)
        g = [0] * (1 << m)
        h = [0] * (1 << m)
        f[0] = 0
        for i in range(1 << m):
            if f[i] == inf:
                continue
            for j in range(n):
                if f[i] + 1 < f[i | p[j]]:
                    f[i | p[j]] = f[i] + 1
                    g[i | p[j]] = j
                    h[i | p[j]] = i
        i = (1 << m) - 1
        ans = []
        while i:
            ans.append(g[i])
            i = h[i]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] smallestSufficientTeam(String[] req_skills, List<List<String>> people) {
        Map<String, Integer> d = new HashMap<>();
        int m = req_skills.length;
        int n = people.size();
        for (int i = 0; i < m; ++i) {
            d.put(req_skills[i], i);
        }
        int[] p = new int[n];
        for (int i = 0; i < n; ++i) {
            for (var s : people.get(i)) {
                p[i] |= 1 << d.get(s);
            }
        }
        int[] f = new int[1 << m];
        int[] g = new int[1 << m];
        int[] h = new int[1 << m];
        final int inf = 1 << 30;
        Arrays.fill(f, inf);
        f[0] = 0;
        for (int i = 0; i < 1 << m; ++i) {
            if (f[i] == inf) {
                continue;
            }
            for (int j = 0; j < n; ++j) {
                if (f[i] + 1 < f[i | p[j]]) {
                    f[i | p[j]] = f[i] + 1;
                    g[i | p[j]] = j;
                    h[i | p[j]] = i;
                }
            }
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = (1 << m) - 1; i != 0; i = h[i]) {
            ans.add(g[i]);
        }
        return ans.stream().mapToInt(Integer::intValue).toArray();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string, int> d;
        int m = req_skills.size(), n = people.size();
        for (int i = 0; i < m; ++i) {
            d[req_skills[i]] = i;
        }
        int p[n];
        memset(p, 0, sizeof(p));
        for (int i = 0; i < n; ++i) {
            for (auto& s : people[i]) {
                p[i] |= 1 << d[s];
            }
        }
        int f[1 << m];
        int g[1 << m];
        int h[1 << m];
        memset(f, 63, sizeof(f));
        f[0] = 0;
        for (int i = 0; i < 1 << m; ++i) {
            if (f[i] == 0x3f3f3f3f) {
                continue;
            }
            for (int j = 0; j < n; ++j) {
                if (f[i] + 1 < f[i | p[j]]) {
                    f[i | p[j]] = f[i] + 1;
                    g[i | p[j]] = j;
                    h[i | p[j]] = i;
                }
            }
        }
        vector<int> ans;
        for (int i = (1 << m) - 1; i; i = h[i]) {
            ans.push_back(g[i]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func smallestSufficientTeam(req_skills []string, people [][]string) (ans []int) {
	d := map[string]int{}
	for i, s := range req_skills {
		d[s] = i
	}
	m, n := len(req_skills), len(people)
	p := make([]int, n)
	for i, ss := range people {
		for _, s := range ss {
			p[i] |= 1 << d[s]
		}
	}
	const inf = 1 << 30
	f := make([]int, 1<<m)
	g := make([]int, 1<<m)
	h := make([]int, 1<<m)
	for i := range f {
		f[i] = inf
	}
	f[0] = 0
	for i := range f {
		if f[i] == inf {
			continue
		}
		for j := 0; j < n; j++ {
			if f[i]+1 < f[i|p[j]] {
				f[i|p[j]] = f[i] + 1
				g[i|p[j]] = j
				h[i|p[j]] = i
			}
		}
	}
	for i := 1<<m - 1; i != 0; i = h[i] {
		ans = append(ans, g[i])
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function smallestSufficientTeam(req_skills: string[], people: string[][]): number[] {
    const d: Map<string, number> = new Map();
    const m = req_skills.length;
    const n = people.length;
    for (let i = 0; i < m; ++i) {
        d.set(req_skills[i], i);
    }
    const p: number[] = new Array(n).fill(0);
    for (let i = 0; i < n; ++i) {
        for (const s of people[i]) {
            p[i] |= 1 << d.get(s)!;
        }
    }
    const inf = 1 << 30;
    const f: number[] = new Array(1 << m).fill(inf);
    const g: number[] = new Array(1 << m).fill(0);
    const h: number[] = new Array(1 << m).fill(0);
    f[0] = 0;
    for (let i = 0; i < 1 << m; ++i) {
        if (f[i] === inf) {
            continue;
        }
        for (let j = 0; j < n; ++j) {
            if (f[i] + 1 < f[i | p[j]]) {
                f[i | p[j]] = f[i] + 1;
                g[i | p[j]] = j;
                h[i | p[j]] = i;
            }
        }
    }
    const ans: number[] = [];
    for (let i = (1 << m) - 1; i; i = h[i]) {
        ans.push(g[i]);
    }
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>作为项目经理，你规划了一份需求的技能清单 <code>req_skills</code>，并打算从备选人员名单 <code>people</code> 中选出些人组成一个「必要团队」（ 编号为 <code>i</code> 的备选人员 <code>people[i]</code> 含有一份该备选人员掌握的技能列表）。</p>

<p>所谓「必要团队」，就是在这个团队中，对于所需求的技能列表 <code>req_skills</code> 中列出的每项技能，团队中至少有一名成员已经掌握。可以用每个人的编号来表示团队中的成员：</p>

<ul>
	<li>例如，团队 <code>team = [0, 1, 3]</code> 表示掌握技能分别为 <code>people[0]</code>，<code>people[1]</code>，和 <code>people[3]</code> 的备选人员。</li>
</ul>

<p>请你返回 <strong>任一</strong> 规模最小的必要团队，团队成员用人员编号表示。你可以按 <strong>任意顺序</strong> 返回答案，题目数据保证答案存在。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>req_skills = ["java","nodejs","reactjs"], people = [["java"],["nodejs"],["nodejs","reactjs"]]
<strong>输出：</strong>[0,2]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>req_skills = ["algorithms","math","java","reactjs","csharp","aws"], people = [["algorithms","math","java"],["algorithms","math","reactjs"],["java","csharp","aws"],["reactjs","csharp"],["csharp","math"],["aws","java"]]
<strong>输出：</strong>[1,2]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= req_skills.length <= 16</code></li>
	<li><code>1 <= req_skills[i].length <= 16</code></li>
	<li><code>req_skills[i]</code> 由小写英文字母组成</li>
	<li><code>req_skills</code> 中的所有字符串 <strong>互不相同</strong></li>
	<li><code>1 <= people.length <= 60</code></li>
	<li><code>0 <= people[i].length <= 16</code></li>
	<li><code>1 <= people[i][j].length <= 16</code></li>
	<li><code>people[i][j]</code> 由小写英文字母组成</li>
	<li><code>people[i]</code> 中的所有字符串 <strong>互不相同</strong></li>
	<li><code>people[i]</code> 中的每个技能是 <code>req_skills</code> 中的技能</li>
	<li>题目数据保证「必要团队」一定存在</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：状态压缩动态规划

我们注意到，技能清单 `req_skills` 的长度不超过 $16$，因此，我们可以用一个长度不超过 $16$ 的二进制数来表示每一种技能是否被掌握。不妨记数组 `req_skills` 的长度为 $m$，数组 `people` 的长度为 $n$。

我们先将 `req_skills` 中的每个技能映射到一个编号，即 $d[s]$ 表示技能 $s$ 的编号。然后，我们遍历 `people` 中的每个人，将其掌握的技能用二进制数表示，即 $p[i]$ 表示编号为 $i$ 的人掌握的技能。

接下来，我们定义以下三个数组，其中：

-   数组 $f[i]$ 表示掌握技能集合为 $i$ 的最少人数，其中 $i$ 的二进制表示中的每一位为 $1$ 的位置，表示对应的技能被掌握。初始时 $f[0] = 0$，其余位置均为无穷大。
-   数组 $g[i]$ 表示掌握技能集合为 $i$ 的最少人数时，最后一个人的编号。
-   数组 $h[i]$ 表示掌握技能集合为 $i$ 的最少人数时，上一个技能集合状态。

我们在 $[0,..2^m-1]$ 的范围内枚举每个技能集合，对于每个技能集合 $i$：

我们枚举 `people` 中的每个人 $j$，如果 $f[i] + 1 \lt f[i | p[j]]$，说明 $f[i | p[j]]$ 可以通过 $f[i]$ 转移得到，此时，我们更新 $f[i | p[j]]$ 为 $f[i] + 1$，并将 $g[i | p[j]]$ 更新为 $j$，同时将 $h[i | p[j]]$ 更新为 $i$。即当前技能集合状态为 $i | p[j]$ 时，最后一个人的编号为 $j$，上一个技能集合状态为 $i$。这里符号 $|$ 表示按位或运算。

最后，我们从技能集合 $i=2^m-1$ 开始，找到此时最后一个人的编号 $g[i]$，将其加入答案中，然后将 $i$ 更新为 $h[i]$，不断地向前回溯，直到 $i=0$，即可得到最小的必要团队中的人员编号。

时间复杂度 $O(2^m \times n)$，空间复杂度 $O(2^m)$。其中 $m$ 和 $n$ 分别为 `req_skills` 和 `people` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def smallestSufficientTeam(
        self, req_skills: List[str], people: List[List[str]]
    ) -> List[int]:
        d = {s: i for i, s in enumerate(req_skills)}
        m, n = len(req_skills), len(people)
        p = [0] * n
        for i, ss in enumerate(people):
            for s in ss:
                p[i] |= 1 << d[s]
        f = [inf] * (1 << m)
        g = [0] * (1 << m)
        h = [0] * (1 << m)
        f[0] = 0
        for i in range(1 << m):
            if f[i] == inf:
                continue
            for j in range(n):
                if f[i] + 1 < f[i | p[j]]:
                    f[i | p[j]] = f[i] + 1
                    g[i | p[j]] = j
                    h[i | p[j]] = i
        i = (1 << m) - 1
        ans = []
        while i:
            ans.append(g[i])
            i = h[i]
        return ans
```

#### Java

```java
class Solution {
    public int[] smallestSufficientTeam(String[] req_skills, List<List<String>> people) {
        Map<String, Integer> d = new HashMap<>();
        int m = req_skills.length;
        int n = people.size();
        for (int i = 0; i < m; ++i) {
            d.put(req_skills[i], i);
        }
        int[] p = new int[n];
        for (int i = 0; i < n; ++i) {
            for (var s : people.get(i)) {
                p[i] |= 1 << d.get(s);
            }
        }
        int[] f = new int[1 << m];
        int[] g = new int[1 << m];
        int[] h = new int[1 << m];
        final int inf = 1 << 30;
        Arrays.fill(f, inf);
        f[0] = 0;
        for (int i = 0; i < 1 << m; ++i) {
            if (f[i] == inf) {
                continue;
            }
            for (int j = 0; j < n; ++j) {
                if (f[i] + 1 < f[i | p[j]]) {
                    f[i | p[j]] = f[i] + 1;
                    g[i | p[j]] = j;
                    h[i | p[j]] = i;
                }
            }
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = (1 << m) - 1; i != 0; i = h[i]) {
            ans.add(g[i]);
        }
        return ans.stream().mapToInt(Integer::intValue).toArray();
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string, int> d;
        int m = req_skills.size(), n = people.size();
        for (int i = 0; i < m; ++i) {
            d[req_skills[i]] = i;
        }
        int p[n];
        memset(p, 0, sizeof(p));
        for (int i = 0; i < n; ++i) {
            for (auto& s : people[i]) {
                p[i] |= 1 << d[s];
            }
        }
        int f[1 << m];
        int g[1 << m];
        int h[1 << m];
        memset(f, 63, sizeof(f));
        f[0] = 0;
        for (int i = 0; i < 1 << m; ++i) {
            if (f[i] == 0x3f3f3f3f) {
                continue;
            }
            for (int j = 0; j < n; ++j) {
                if (f[i] + 1 < f[i | p[j]]) {
                    f[i | p[j]] = f[i] + 1;
                    g[i | p[j]] = j;
                    h[i | p[j]] = i;
                }
            }
        }
        vector<int> ans;
        for (int i = (1 << m) - 1; i; i = h[i]) {
            ans.push_back(g[i]);
        }
        return ans;
    }
};
```

#### Go

```go
func smallestSufficientTeam(req_skills []string, people [][]string) (ans []int) {
	d := map[string]int{}
	for i, s := range req_skills {
		d[s] = i
	}
	m, n := len(req_skills), len(people)
	p := make([]int, n)
	for i, ss := range people {
		for _, s := range ss {
			p[i] |= 1 << d[s]
		}
	}
	const inf = 1 << 30
	f := make([]int, 1<<m)
	g := make([]int, 1<<m)
	h := make([]int, 1<<m)
	for i := range f {
		f[i] = inf
	}
	f[0] = 0
	for i := range f {
		if f[i] == inf {
			continue
		}
		for j := 0; j < n; j++ {
			if f[i]+1 < f[i|p[j]] {
				f[i|p[j]] = f[i] + 1
				g[i|p[j]] = j
				h[i|p[j]] = i
			}
		}
	}
	for i := 1<<m - 1; i != 0; i = h[i] {
		ans = append(ans, g[i])
	}
	return
}
```

#### TypeScript

```ts
function smallestSufficientTeam(req_skills: string[], people: string[][]): number[] {
    const d: Map<string, number> = new Map();
    const m = req_skills.length;
    const n = people.length;
    for (let i = 0; i < m; ++i) {
        d.set(req_skills[i], i);
    }
    const p: number[] = new Array(n).fill(0);
    for (let i = 0; i < n; ++i) {
        for (const s of people[i]) {
            p[i] |= 1 << d.get(s)!;
        }
    }
    const inf = 1 << 30;
    const f: number[] = new Array(1 << m).fill(inf);
    const g: number[] = new Array(1 << m).fill(0);
    const h: number[] = new Array(1 << m).fill(0);
    f[0] = 0;
    for (let i = 0; i < 1 << m; ++i) {
        if (f[i] === inf) {
            continue;
        }
        for (let j = 0; j < n; ++j) {
            if (f[i] + 1 < f[i | p[j]]) {
                f[i | p[j]] = f[i] + 1;
                g[i | p[j]] = j;
                h[i | p[j]] = i;
            }
        }
    }
    const ans: number[] = [];
    for (let i = (1 << m) - 1; i; i = h[i]) {
        ans.push(g[i]);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1126. 查询活跃业务 🔒](https://leetcode.cn/problems/active-businesses){#1126}

{{< tabs "1126" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            business_id,
            occurences > AVG(occurences) OVER (PARTITION BY event_type) AS mark
        FROM Events
    )
SELECT business_id
FROM T
WHERE mark = 1
GROUP BY 1
HAVING COUNT(1) > 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>事件表：<code>Events</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| business_id   | int     |
| event_type    | varchar |
| occurrences   | int     | 
+---------------+---------+
(business_id, event_type) 是这个表的主键（具有唯一值的列的组合）。
表中的每一行记录了某种类型的事件在某些业务中多次发生的信息。
</pre>

<p>&nbsp;</p>

<p><strong>平均活动</strong> 是指有特定 <code>event_type</code> 的具有该事件的所有公司的 <code>occurrences</code>&nbsp;的均值。</p>

<p><strong>活跃业务</strong> 是指具有&nbsp;<strong>多个</strong> <code>event_type</code>&nbsp;的业务，它们的 <code>occurrences</code> <strong>严格大于</strong> 该事件的平均活动次数。</p>

<p>写一个解决方案，找到所有 <strong>活跃业务</strong>。</p>

<p>以 <strong>任意顺序</strong> 返回结果表。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Events table:
+-------------+------------+-------------+
| business_id | event_type | occurrences |
+-------------+------------+-------------+
| 1           | reviews    | 7           |
| 3           | reviews    | 3           |
| 1           | ads        | 11          |
| 2           | ads        | 7           |
| 3           | ads        | 6           |
| 1           | page views | 3           |
| 2           | page views | 12          |
+-------------+------------+-------------+
<strong>输出：</strong>
+-------------+
| business_id |
+-------------+
| 1           |
+-------------+ 
<strong>解释：</strong>
每次活动的平均活动可计算如下:
- 'reviews': (7+3)/2 = 5
- 'ads': (11+7+6)/3 = 8
- 'page views': (3+12)/2 = 7.5
id=1 的业务有 7 个 'reviews' 事件(多于 5 个)和 11 个 'ads' 事件(多于 8 个)，所以它是一个活跃的业务。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT business_id
FROM
    EVENTS AS t1
    JOIN (
        SELECT
            event_type,
            AVG(occurences) AS occurences
        FROM EVENTS
        GROUP BY event_type
    ) AS t2
        ON t1.event_type = t2.event_type
WHERE t1.occurences > t2.occurences
GROUP BY business_id
HAVING COUNT(1) > 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            business_id,
            occurences > AVG(occurences) OVER (PARTITION BY event_type) AS mark
        FROM Events
    )
SELECT business_id
FROM T
WHERE mark = 1
GROUP BY 1
HAVING COUNT(1) > 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1127. 用户购买平台 🔒](https://leetcode.cn/problems/user-purchase-platform){#1127}

{{< tabs "1127" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    P AS (
        SELECT DISTINCT spend_date, 'desktop' AS platform FROM Spending
        UNION
        SELECT DISTINCT spend_date, 'mobile' FROM Spending
        UNION
        SELECT DISTINCT spend_date, 'both' FROM Spending
    ),
    T AS (
        SELECT
            user_id,
            spend_date,
            SUM(amount) AS amount,
            IF(COUNT(platform) = 1, platform, 'both') AS platform
        FROM Spending
        GROUP BY 1, 2
    )
SELECT
    p.*,
    IFNULL(SUM(amount), 0) AS total_amount,
    COUNT(t.user_id) AS total_users
FROM
    P AS p
    LEFT JOIN T AS t USING (spend_date, platform)
GROUP BY 1, 2;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>支出表: <code>Spending</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| user_id     | int     |
| spend_date  | date    |
| platform    | enum    | 
| amount      | int     |
+-------------+---------+
这张表记录了用户在一个在线购物网站的支出历史，该在线购物平台同时拥有桌面端（'desktop'）和手机端（'mobile'）的应用程序。
(user_id, spend_date, platform) 是这张表的主键(具有唯一值的列的组合)。
平台列 platform 是一种 ENUM ，类型为（'desktop', 'mobile'）。</pre>

<p>&nbsp;</p>

<p>编写解决方案找出每天&nbsp;<strong>仅&nbsp;</strong>使用手机端用户、<strong>仅&nbsp;</strong>使用桌面端用户和&nbsp;<strong>同时&nbsp;</strong>使用桌面端和手机端的用户人数和总支出金额。</p>

<p>以 <strong>任意顺序</strong> 返回结果表。</p>

<p>返回结果格式如下例所示：</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<code><strong>输入：</strong>
Spending</code> table:
+---------+------------+----------+--------+
| user_id | spend_date | platform | amount |
+---------+------------+----------+--------+
| 1       | 2019-07-01 | mobile   | 100    |
| 1       | 2019-07-01 | desktop  | 100    |
| 2       | 2019-07-01 | mobile   | 100    |
| 2       | 2019-07-02 | mobile   | 100    |
| 3       | 2019-07-01 | desktop  | 100    |
| 3       | 2019-07-02 | desktop  | 100    |
+---------+------------+----------+--------+
<strong>输出：</strong>
+------------+----------+--------------+-------------+
| spend_date | platform | total_amount | total_users |
+------------+----------+--------------+-------------+
| 2019-07-01 | desktop  | 100          | 1           |
| 2019-07-01 | mobile   | 100          | 1           |
| 2019-07-01 | both     | 200          | 1           |
| 2019-07-02 | desktop  | 100          | 1           |
| 2019-07-02 | mobile   | 100          | 1           |
| 2019-07-02 | both     | 0            | 0           |
+------------+----------+--------------+-------------+ 
<strong>解释：</strong>
在 2019-07-01, 用户1 <strong>同时 </strong>使用桌面端和手机端购买, 用户2 <strong>仅 </strong>使用了手机端购买，而用户3 <strong>仅 </strong>使用了桌面端购买。
在 2019-07-02, 用户2 <strong>仅 </strong>使用了手机端购买, 用户3 <strong>仅 </strong>使用了桌面端购买，且没有用户 <strong>同时 </strong>使用桌面端和手机端购买。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    P AS (
        SELECT DISTINCT spend_date, 'desktop' AS platform FROM Spending
        UNION
        SELECT DISTINCT spend_date, 'mobile' FROM Spending
        UNION
        SELECT DISTINCT spend_date, 'both' FROM Spending
    ),
    T AS (
        SELECT
            user_id,
            spend_date,
            SUM(amount) AS amount,
            IF(COUNT(platform) = 1, platform, 'both') AS platform
        FROM Spending
        GROUP BY 1, 2
    )
SELECT
    p.*,
    IFNULL(SUM(amount), 0) AS total_amount,
    COUNT(t.user_id) AS total_users
FROM
    P AS p
    LEFT JOIN T AS t USING (spend_date, platform)
GROUP BY 1, 2;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1128. 等价多米诺骨牌对的数量](https://leetcode.cn/problems/number-of-equivalent-domino-pairs){#1128}

{{< tabs "1128" >}}

{{% tab "python" %}}
```python
class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        cnt = Counter()
        ans = 0
        for a, b in dominoes:
            x = a * 10 + b if a < b else b * 10 + a
            ans += cnt[x]
            cnt[x] += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numEquivDominoPairs(int[][] dominoes) {
        int[] cnt = new int[100];
        int ans = 0;
        for (var e : dominoes) {
            int x = e[0] < e[1] ? e[0] * 10 + e[1] : e[1] * 10 + e[0];
            ans += cnt[x]++;
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int cnt[100]{};
        int ans = 0;
        for (auto& e : dominoes) {
            int x = e[0] < e[1] ? e[0] * 10 + e[1] : e[1] * 10 + e[0];
            ans += cnt[x]++;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numEquivDominoPairs(dominoes [][]int) (ans int) {
	cnt := [100]int{}
	for _, e := range dominoes {
		x := e[0]*10 + e[1]
		if e[0] > e[1] {
			x = e[1]*10 + e[0]
		}
		ans += cnt[x]
		cnt[x]++
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numEquivDominoPairs(dominoes: number[][]): number {
    const cnt: number[] = new Array(100).fill(0);
    let ans = 0;

    for (const [a, b] of dominoes) {
        const key = a < b ? a * 10 + b : b * 10 + a;
        ans += cnt[key];
        cnt[key]++;
    }

    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn num_equiv_domino_pairs(dominoes: Vec<Vec<i32>>) -> i32 {
        let mut cnt = [0i32; 100];
        let mut ans = 0;

        for d in dominoes {
            let a = d[0] as usize;
            let b = d[1] as usize;
            let key = if a < b { a * 10 + b } else { b * 10 + a };
            ans += cnt[key];
            cnt[key] += 1;
        }

        ans
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一组多米诺骨牌 <code>dominoes</code> 。</p>

<p>形式上，<code>dominoes[i] = [a, b]</code> 与 <code>dominoes[j] = [c, d]</code> <strong>等价</strong> 当且仅当 (<code>a == c</code> 且 <code>b == d</code>) 或者 (<code>a == d</code> 且 <code>b == c</code>) 。即一张骨牌可以通过旋转 <code>0</code>&nbsp;度或 <code>180</code> 度得到另一张多米诺骨牌。</p>

<p>在&nbsp;<code>0 &lt;= i &lt; j &lt; dominoes.length</code>&nbsp;的前提下，找出满足&nbsp;<code>dominoes[i]</code> 和&nbsp;<code>dominoes[j]</code>&nbsp;等价的骨牌对 <code>(i, j)</code> 的数量。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>dominoes = [[1,2],[2,1],[3,4],[5,6]]
<strong>输出：</strong>1
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>dominoes = [[1,2],[1,2],[1,1],[1,2],[2,2]]
<strong>输出：</strong>3
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= dominoes.length &lt;= 4 * 10<sup>4</sup></code></li>
	<li><code>dominoes[i].length == 2</code></li>
	<li><code>1 &lt;= dominoes[i][j] &lt;= 9</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们可以将每个多米诺骨牌的两个数字按照大小顺序拼接成一个两位数，这样就可以将等价的多米诺骨牌拼接成相同的两位数。例如，`[1, 2]` 和 `[2, 1]` 拼接成的两位数都是 `12`，`[3, 4]` 和 `[4, 3]` 拼接成的两位数都是 `34`。

然后我们遍历所有的多米诺骨牌，用一个哈希表或者一个长度为 $100$ 的数组 $cnt$ 记录每个两位数出现的次数。对于每个多米诺骨牌，我们拼接成的两位数为 $x$，那么答案就会增加 $cnt[x]$，接着我们将 $cnt[x]$ 的值加 $1$。继续遍历下一个多米诺骨牌，就可以统计出所有等价的多米诺骨牌对的数量。

时间复杂度 $O(n)$，空间复杂度 $O(C)$。其中 $n$ 是多米诺骨牌的数量，而 $C$ 是多米诺骨牌中拼接成的两位数的最大数量，即 $100$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        cnt = Counter()
        ans = 0
        for a, b in dominoes:
            x = a * 10 + b if a < b else b * 10 + a
            ans += cnt[x]
            cnt[x] += 1
        return ans
```

#### Java

```java
class Solution {
    public int numEquivDominoPairs(int[][] dominoes) {
        int[] cnt = new int[100];
        int ans = 0;
        for (var e : dominoes) {
            int x = e[0] < e[1] ? e[0] * 10 + e[1] : e[1] * 10 + e[0];
            ans += cnt[x]++;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int cnt[100]{};
        int ans = 0;
        for (auto& e : dominoes) {
            int x = e[0] < e[1] ? e[0] * 10 + e[1] : e[1] * 10 + e[0];
            ans += cnt[x]++;
        }
        return ans;
    }
};
```

#### Go

```go
func numEquivDominoPairs(dominoes [][]int) (ans int) {
	cnt := [100]int{}
	for _, e := range dominoes {
		x := e[0]*10 + e[1]
		if e[0] > e[1] {
			x = e[1]*10 + e[0]
		}
		ans += cnt[x]
		cnt[x]++
	}
	return
}
```

#### TypeScript

```ts
function numEquivDominoPairs(dominoes: number[][]): number {
    const cnt: number[] = new Array(100).fill(0);
    let ans = 0;

    for (const [a, b] of dominoes) {
        const key = a < b ? a * 10 + b : b * 10 + a;
        ans += cnt[key];
        cnt[key]++;
    }

    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn num_equiv_domino_pairs(dominoes: Vec<Vec<i32>>) -> i32 {
        let mut cnt = [0i32; 100];
        let mut ans = 0;

        for d in dominoes {
            let a = d[0] as usize;
            let b = d[1] as usize;
            let key = if a < b { a * 10 + b } else { b * 10 + a };
            ans += cnt[key];
            cnt[key] += 1;
        }

        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1129. 颜色交替的最短路径](https://leetcode.cn/problems/shortest-path-with-alternating-colors){#1129}

{{< tabs "1129" >}}

{{% tab "python" %}}
```python
class Solution:
    def shortestAlternatingPaths(
        self, n: int, redEdges: List[List[int]], blueEdges: List[List[int]]
    ) -> List[int]:
        g = [defaultdict(list), defaultdict(list)]
        for i, j in redEdges:
            g[0][i].append(j)
        for i, j in blueEdges:
            g[1][i].append(j)
        ans = [-1] * n
        vis = set()
        q = deque([(0, 0), (0, 1)])
        d = 0
        while q:
            for _ in range(len(q)):
                i, c = q.popleft()
                if ans[i] == -1:
                    ans[i] = d
                vis.add((i, c))
                c ^= 1
                for j in g[c][i]:
                    if (j, c) not in vis:
                        q.append((j, c))
            d += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] shortestAlternatingPaths(int n, int[][] redEdges, int[][] blueEdges) {
        List<Integer>[][] g = new List[2][n];
        for (var f : g) {
            Arrays.setAll(f, k -> new ArrayList<>());
        }
        for (var e : redEdges) {
            g[0][e[0]].add(e[1]);
        }
        for (var e : blueEdges) {
            g[1][e[0]].add(e[1]);
        }
        Deque<int[]> q = new ArrayDeque<>();
        q.offer(new int[] {0, 0});
        q.offer(new int[] {0, 1});
        boolean[][] vis = new boolean[n][2];
        int[] ans = new int[n];
        Arrays.fill(ans, -1);
        int d = 0;
        while (!q.isEmpty()) {
            for (int k = q.size(); k > 0; --k) {
                var p = q.poll();
                int i = p[0], c = p[1];
                if (ans[i] == -1) {
                    ans[i] = d;
                }
                vis[i][c] = true;
                c ^= 1;
                for (int j : g[c][i]) {
                    if (!vis[j][c]) {
                        q.offer(new int[] {j, c});
                    }
                }
            }
            ++d;
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<vector<int>>> g(2, vector<vector<int>>(n));
        for (auto& e : redEdges) {
            g[0][e[0]].push_back(e[1]);
        }
        for (auto& e : blueEdges) {
            g[1][e[0]].push_back(e[1]);
        }
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        q.emplace(0, 1);
        bool vis[n][2];
        memset(vis, false, sizeof vis);
        vector<int> ans(n, -1);
        int d = 0;
        while (!q.empty()) {
            for (int k = q.size(); k; --k) {
                auto [i, c] = q.front();
                q.pop();
                if (ans[i] == -1) {
                    ans[i] = d;
                }
                vis[i][c] = true;
                c ^= 1;
                for (int& j : g[c][i]) {
                    if (!vis[j][c]) {
                        q.emplace(j, c);
                    }
                }
            }
            ++d;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func shortestAlternatingPaths(n int, redEdges [][]int, blueEdges [][]int) []int {
	g := [2][][]int{}
	for i := range g {
		g[i] = make([][]int, n)
	}
	for _, e := range redEdges {
		g[0][e[0]] = append(g[0][e[0]], e[1])
	}
	for _, e := range blueEdges {
		g[1][e[0]] = append(g[1][e[0]], e[1])
	}
	type pair struct{ i, c int }
	q := []pair{pair{0, 0}, pair{0, 1}}
	ans := make([]int, n)
	vis := make([][2]bool, n)
	for i := range ans {
		ans[i] = -1
	}
	d := 0
	for len(q) > 0 {
		for k := len(q); k > 0; k-- {
			p := q[0]
			q = q[1:]
			i, c := p.i, p.c
			if ans[i] == -1 {
				ans[i] = d
			}
			vis[i][c] = true
			c ^= 1
			for _, j := range g[c][i] {
				if !vis[j][c] {
					q = append(q, pair{j, c})
				}
			}
		}
		d++
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function shortestAlternatingPaths(
    n: number,
    redEdges: number[][],
    blueEdges: number[][],
): number[] {
    const g: [Graph, Graph] = [{}, {}];
    const ans = Array(n).fill(-1);
    const vis = Array.from({ length: n }, () => Array.from({ length: 2 }, () => false));
    let q: Vertex[] = [
        [0, 0],
        [0, 1],
    ];
    vis[0][0] = vis[0][1] = true;
    let d = 0;
    for (const [i, j] of redEdges) {
        (g[0][i] ??= []).push(j);
    }
    for (const [i, j] of blueEdges) {
        (g[1][i] ??= []).push(j);
    }
    while (q.length) {
        const qNext: Vertex[] = [];
        for (let [i, color] of q) {
            if (ans[i] === -1) {
                ans[i] = d;
            }
            color ^= 1;
            for (const j of g[color][i] ?? []) {
                if (!vis[j][color]) {
                    vis[j][color] = true;
                    qNext.push([j, color as Color]);
                }
            }
        }
        q = qNext;
        d++;
    }
    return ans;
}

type Graph = Record<number, number[]>;
type Color = 0 | 1;
type Vertex = [number, Color];
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个整数 <code>n</code>，即有向图中的节点数，其中节点标记为 <code>0</code> 到 <code>n - 1</code>。图中的每条边为红色或者蓝色，并且可能存在自环或平行边。</p>

<p>给定两个数组&nbsp;<code>redEdges</code>&nbsp;和&nbsp;<code>blueEdges</code>，其中：</p>

<ul>
	<li><code>redEdges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code>&nbsp;表示图中存在一条从节点&nbsp;<code>a<sub>i</sub></code>&nbsp;到节点&nbsp;<code>b<sub>i</sub></code>&nbsp;的红色有向边，</li>
	<li><code>blueEdges[j] = [u<sub>j</sub>, v<sub>j</sub>]</code>&nbsp;表示图中存在一条从节点&nbsp;<code>u<sub>j</sub></code>&nbsp;到节点&nbsp;<code>v<sub>j</sub></code>&nbsp;的蓝色有向边。</li>
</ul>

<p>返回长度为 <code>n</code> 的数组&nbsp;<code>answer</code>，其中&nbsp;<code>answer[X]</code>&nbsp;是从节点&nbsp;<code>0</code>&nbsp;到节点&nbsp;<code>X</code>&nbsp;的红色边和蓝色边交替出现的最短路径的长度。如果不存在这样的路径，那么 <code>answer[x] = -1</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 3, red_edges = [[0,1],[1,2]], blue_edges = []
<strong>输出：</strong>[0,1,-1]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 3, red_edges = [[0,1]], blue_edges = [[2,1]]
<strong>输出：</strong>[0,1,-1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>0 &lt;= redEdges.length,&nbsp;blueEdges.length &lt;= 400</code></li>
	<li><code>redEdges[i].length == blueEdges[j].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub>, u<sub>j</sub>, v<sub>j</sub>&nbsp;&lt; n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS

题目实际上是最短路问题，我们可以考虑使用 BFS 来解决。

首先，我们对所有的边进行预处理，将所有的边按照颜色分类，存储到多维数组 $g$ 中。其中 $g[0]$ 存储所有红色边，而 $g[1]$ 存储所有蓝色边。

接着，我们定义以下数据结构或变量：

-   队列 $q$：用来存储当前搜索到的节点，以及当前边的颜色；
-   集合 $vis$：用来存储已经搜索过的节点，以及当前边的颜色；
-   变量 $d$：用来表示当前搜索的层数，即当前搜索到的节点到起点的距离；
-   数组 $ans$：用来存储每个节点到起点的最短距离。初始时，我们将 $ans$ 数组中的所有元素初始化为 $-1$，表示所有节点到起点的距离都未知。

我们首先将起点 $0$ 和起点边的颜色 $0$ 或 $1$ 入队，表示从起点出发，且当前是红色或蓝色边。

接下来，我们开始进行 BFS 搜索。我们每次从队列中取出一个节点 $(i, c)$，如果当前节点的答案还未更新，则将当前节点的答案更新为当前层数 $d$，即 $ans[i] = d$。然后，我们将当前边的颜色 $c$ 取反，即如果当前边为红色，则将其变为蓝色，反之亦然。我们取出颜色对应的所有边，如果边的另一端节点 $j$ 未被搜索过，则将其入队。

搜索结束后，返回答案数组即可。

时间复杂度 $O(n + m)$，空间复杂度 $O(n + m)$。其中 $n$ 和 $m$ 分别为节点数和边数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def shortestAlternatingPaths(
        self, n: int, redEdges: List[List[int]], blueEdges: List[List[int]]
    ) -> List[int]:
        g = [defaultdict(list), defaultdict(list)]
        for i, j in redEdges:
            g[0][i].append(j)
        for i, j in blueEdges:
            g[1][i].append(j)
        ans = [-1] * n
        vis = set()
        q = deque([(0, 0), (0, 1)])
        d = 0
        while q:
            for _ in range(len(q)):
                i, c = q.popleft()
                if ans[i] == -1:
                    ans[i] = d
                vis.add((i, c))
                c ^= 1
                for j in g[c][i]:
                    if (j, c) not in vis:
                        q.append((j, c))
            d += 1
        return ans
```

#### Java

```java
class Solution {
    public int[] shortestAlternatingPaths(int n, int[][] redEdges, int[][] blueEdges) {
        List<Integer>[][] g = new List[2][n];
        for (var f : g) {
            Arrays.setAll(f, k -> new ArrayList<>());
        }
        for (var e : redEdges) {
            g[0][e[0]].add(e[1]);
        }
        for (var e : blueEdges) {
            g[1][e[0]].add(e[1]);
        }
        Deque<int[]> q = new ArrayDeque<>();
        q.offer(new int[] {0, 0});
        q.offer(new int[] {0, 1});
        boolean[][] vis = new boolean[n][2];
        int[] ans = new int[n];
        Arrays.fill(ans, -1);
        int d = 0;
        while (!q.isEmpty()) {
            for (int k = q.size(); k > 0; --k) {
                var p = q.poll();
                int i = p[0], c = p[1];
                if (ans[i] == -1) {
                    ans[i] = d;
                }
                vis[i][c] = true;
                c ^= 1;
                for (int j : g[c][i]) {
                    if (!vis[j][c]) {
                        q.offer(new int[] {j, c});
                    }
                }
            }
            ++d;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<vector<int>>> g(2, vector<vector<int>>(n));
        for (auto& e : redEdges) {
            g[0][e[0]].push_back(e[1]);
        }
        for (auto& e : blueEdges) {
            g[1][e[0]].push_back(e[1]);
        }
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        q.emplace(0, 1);
        bool vis[n][2];
        memset(vis, false, sizeof vis);
        vector<int> ans(n, -1);
        int d = 0;
        while (!q.empty()) {
            for (int k = q.size(); k; --k) {
                auto [i, c] = q.front();
                q.pop();
                if (ans[i] == -1) {
                    ans[i] = d;
                }
                vis[i][c] = true;
                c ^= 1;
                for (int& j : g[c][i]) {
                    if (!vis[j][c]) {
                        q.emplace(j, c);
                    }
                }
            }
            ++d;
        }
        return ans;
    }
};
```

#### Go

```go
func shortestAlternatingPaths(n int, redEdges [][]int, blueEdges [][]int) []int {
	g := [2][][]int{}
	for i := range g {
		g[i] = make([][]int, n)
	}
	for _, e := range redEdges {
		g[0][e[0]] = append(g[0][e[0]], e[1])
	}
	for _, e := range blueEdges {
		g[1][e[0]] = append(g[1][e[0]], e[1])
	}
	type pair struct{ i, c int }
	q := []pair{pair{0, 0}, pair{0, 1}}
	ans := make([]int, n)
	vis := make([][2]bool, n)
	for i := range ans {
		ans[i] = -1
	}
	d := 0
	for len(q) > 0 {
		for k := len(q); k > 0; k-- {
			p := q[0]
			q = q[1:]
			i, c := p.i, p.c
			if ans[i] == -1 {
				ans[i] = d
			}
			vis[i][c] = true
			c ^= 1
			for _, j := range g[c][i] {
				if !vis[j][c] {
					q = append(q, pair{j, c})
				}
			}
		}
		d++
	}
	return ans
}
```

#### TypeScript

```ts
function shortestAlternatingPaths(
    n: number,
    redEdges: number[][],
    blueEdges: number[][],
): number[] {
    const g: [Graph, Graph] = [{}, {}];
    const ans = Array(n).fill(-1);
    const vis = Array.from({ length: n }, () => Array.from({ length: 2 }, () => false));
    let q: Vertex[] = [
        [0, 0],
        [0, 1],
    ];
    vis[0][0] = vis[0][1] = true;
    let d = 0;
    for (const [i, j] of redEdges) {
        (g[0][i] ??= []).push(j);
    }
    for (const [i, j] of blueEdges) {
        (g[1][i] ??= []).push(j);
    }
    while (q.length) {
        const qNext: Vertex[] = [];
        for (let [i, color] of q) {
            if (ans[i] === -1) {
                ans[i] = d;
            }
            color ^= 1;
            for (const j of g[color][i] ?? []) {
                if (!vis[j][color]) {
                    vis[j][color] = true;
                    qNext.push([j, color as Color]);
                }
            }
        }
        q = qNext;
        d++;
    }
    return ans;
}

type Graph = Record<number, number[]>;
type Color = 0 | 1;
type Vertex = [number, Color];
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
