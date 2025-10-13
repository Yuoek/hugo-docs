---
title: "2470_最小公倍数等于 K 的子数组数目"
date: 2025-10-08T18:39:18+08:00
weight: 8
tags: [二分查找, 二叉搜索树, 二叉树, 动态规划, 双指针, 哈希表, 图, 堆（优先队列）, 字典树, 字符串, 广度优先搜索, 排序, 数学, 数据库, 数组, 数论, 最短路, 树, 深度优先搜索, 贪心]
---

{{< markmap >}}
### [2470_最小公倍数等于 K 的子数组数目](#2470)
#### [数组](#2470)
#### [数学](#2470)
#### [数论](#2470)
### [2471_逐层排序二叉树所需的最少操作数目](#2471)
#### [树](#2471)
#### [广度优先搜索](#2471)
#### [二叉树](#2471)
### [2472_不重叠回文子字符串的最大数目](#2472)
#### [贪心](#2472)
#### [双指针](#2472)
#### [字符串](#2472)
#### [动态规划](#2472)
### [2473_购买苹果的最低成本 🔒](#2473)
#### [图](#2473)
#### [数组](#2473)
#### [最短路](#2473)
#### [堆（优先队列）](#2473)
### [2474_购买量严格增加的客户 🔒](#2474)
#### [数据库](#2474)
### [2475_数组中不等三元组的数目](#2475)
#### [数组](#2475)
#### [哈希表](#2475)
#### [排序](#2475)
### [2476_二叉搜索树最近节点查询](#2476)
#### [树](#2476)
#### [深度优先搜索](#2476)
#### [二叉搜索树](#2476)
#### [数组](#2476)
#### [二分查找](#2476)
#### [二叉树](#2476)
### [2477_到达首都的最少油耗](#2477)
#### [树](#2477)
#### [深度优先搜索](#2477)
#### [广度优先搜索](#2477)
#### [图](#2477)
### [2478_完美分割的方案数](#2478)
#### [字符串](#2478)
#### [动态规划](#2478)
### [2479_两个不重叠子树的最大异或值 🔒](#2479)
#### [树](#2479)
#### [深度优先搜索](#2479)
#### [图](#2479)
#### [字典树](#2479)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2470_最小公倍数等于 K 的子数组数目
___
#### 数组
___
#### 数学
___
#### 数论
---
### 2471_逐层排序二叉树所需的最少操作数目
___
#### 树
___
#### 广度优先搜索
___
#### 二叉树
---
### 2472_不重叠回文子字符串的最大数目
___
#### 贪心
___
#### 双指针
___
#### 字符串
___
#### 动态规划
---
### 2473_购买苹果的最低成本 🔒
___
#### 图
___
#### 数组
___
#### 最短路
___
#### 堆（优先队列）
---
### 2474_购买量严格增加的客户 🔒
___
#### 数据库
---
### 2475_数组中不等三元组的数目
___
#### 数组
___
#### 哈希表
___
#### 排序
---
### 2476_二叉搜索树最近节点查询
___
#### 树
___
#### 深度优先搜索
___
#### 二叉搜索树
___
#### 数组
___
#### 二分查找
___
#### 二叉树
---
### 2477_到达首都的最少油耗
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 图
---
### 2478_完美分割的方案数
___
#### 字符串
___
#### 动态规划
---
### 2479_两个不重叠子树的最大异或值 🔒
___
#### 树
___
#### 深度优先搜索
___
#### 图
___
#### 字典树
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉搜索树 | 二叉树 |
| 动态规划 | 双指针 | 哈希表 |
| 图 | 堆（优先队列） | 字典树 |
| 字符串 | 广度优先搜索 | 排序 |
| 数学 | 数据库 | 数组 |
| 数论 | 最短路 | 树 |
| 深度优先搜索 | 贪心 |  |

# [2470. 最小公倍数等于 K 的子数组数目](https://leetcode.cn/problems/number-of-subarrays-with-lcm-equal-to-k){#2470}

{{< tabs "2470" >}}

{{% tab "python" %}}
```python
class Solution:
    def subarrayLCM(self, nums: List[int], k: int) -> int:
        n = len(nums)
        ans = 0
        for i in range(n):
            a = nums[i]
            for b in nums[i:]:
                x = lcm(a, b)
                ans += x == k
                a = x
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int subarrayLCM(int[] nums, int k) {
        int n = nums.length;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int a = nums[i];
            for (int j = i; j < n; ++j) {
                int b = nums[j];
                int x = lcm(a, b);
                if (x == k) {
                    ++ans;
                }
                a = x;
            }
        }
        return ans;
    }

    private int lcm(int a, int b) {
        return a * b / gcd(a, b);
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int a = nums[i];
            for (int j = i; j < n; ++j) {
                int b = nums[j];
                int x = lcm(a, b);
                ans += x == k;
                a = x;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func subarrayLCM(nums []int, k int) (ans int) {
	for i, a := range nums {
		for _, b := range nums[i:] {
			x := lcm(a, b)
			if x == k {
				ans++
			}
			a = x
		}
	}
	return
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func lcm(a, b int) int {
	return a * b / gcd(a, b)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code> 和一个整数 <code>k</code> ，请你统计并返回 <code>nums</code> 的 <strong>子数组</strong> 中满足 <em>元素最小公倍数为 <code>k</code> </em>的子数组数目。</p>

<p><strong>子数组</strong> 是数组中一个连续非空的元素序列。</p>

<p><strong>数组的最小公倍数</strong> 是可被所有数组元素整除的最小正整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1 ：</strong></p>

<pre><strong>输入：</strong>nums = [3,6,2,7,1], k = 6
<strong>输出：</strong>4
<strong>解释：</strong>以 6 为最小公倍数的子数组是：
- [<em><strong>3</strong></em>,<em><strong>6</strong></em>,2,7,1]
- [<em><strong>3</strong></em>,<em><strong>6</strong></em>,<em><strong>2</strong></em>,7,1]
- [3,<em><strong>6</strong></em>,2,7,1]
- [3,<em><strong>6</strong></em>,<em><strong>2</strong></em>,7,1]
</pre>

<p><strong>示例 2 ：</strong></p>

<pre><strong>输入：</strong>nums = [3], k = 2
<strong>输出：</strong>0
<strong>解释：</strong>不存在以 2 为最小公倍数的子数组。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i], k &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

枚举每个数作为子数组的第一个数，然后枚举每个数作为子数组的最后一个数，计算这个子数组的最小公倍数，如果最小公倍数等于 $k$，则答案加一。

时间复杂度 $O(n^2)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def subarrayLCM(self, nums: List[int], k: int) -> int:
        n = len(nums)
        ans = 0
        for i in range(n):
            a = nums[i]
            for b in nums[i:]:
                x = lcm(a, b)
                ans += x == k
                a = x
        return ans
```

#### Java

```java
class Solution {
    public int subarrayLCM(int[] nums, int k) {
        int n = nums.length;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int a = nums[i];
            for (int j = i; j < n; ++j) {
                int b = nums[j];
                int x = lcm(a, b);
                if (x == k) {
                    ++ans;
                }
                a = x;
            }
        }
        return ans;
    }

    private int lcm(int a, int b) {
        return a * b / gcd(a, b);
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int a = nums[i];
            for (int j = i; j < n; ++j) {
                int b = nums[j];
                int x = lcm(a, b);
                ans += x == k;
                a = x;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func subarrayLCM(nums []int, k int) (ans int) {
	for i, a := range nums {
		for _, b := range nums[i:] {
			x := lcm(a, b)
			if x == k {
				ans++
			}
			a = x
		}
	}
	return
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func lcm(a, b int) int {
	return a * b / gcd(a, b)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2471. 逐层排序二叉树所需的最少操作数目](https://leetcode.cn/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level){#2471}

{{< tabs "2471" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minimumOperations(self, root: Optional[TreeNode]) -> int:
        def swap(arr, i, j):
            arr[i], arr[j] = arr[j], arr[i]

        def f(t):
            n = len(t)
            m = {v: i for i, v in enumerate(sorted(t))}
            for i in range(n):
                t[i] = m[t[i]]
            ans = 0
            for i in range(n):
                while t[i] != i:
                    swap(t, i, t[i])
                    ans += 1
            return ans

        q = deque([root])
        ans = 0
        while q:
            t = []
            for _ in range(len(q)):
                node = q.popleft()
                t.append(node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            ans += f(t)
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
    public int minimumOperations(TreeNode root) {
        Deque<TreeNode> q = new ArrayDeque<>();
        q.offer(root);
        int ans = 0;
        while (!q.isEmpty()) {
            List<Integer> t = new ArrayList<>();
            for (int n = q.size(); n > 0; --n) {
                TreeNode node = q.poll();
                t.add(node.val);
                if (node.left != null) {
                    q.offer(node.left);
                }
                if (node.right != null) {
                    q.offer(node.right);
                }
            }
            ans += f(t);
        }
        return ans;
    }

    private int f(List<Integer> t) {
        int n = t.size();
        List<Integer> alls = new ArrayList<>(t);
        alls.sort((a, b) -> a - b);
        Map<Integer, Integer> m = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            m.put(alls.get(i), i);
        }
        int[] arr = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = m.get(t.get(i));
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            while (arr[i] != i) {
                swap(arr, i, arr[i]);
                ++ans;
            }
        }
        return ans;
    }

    private void swap(int[] arr, int i, int j) {
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q{{root}};
        int ans = 0;
        auto f = [](vector<int>& t) {
            int n = t.size();
            vector<int> alls(t.begin(), t.end());
            sort(alls.begin(), alls.end());
            unordered_map<int, int> m;
            int ans = 0;
            for (int i = 0; i < n; ++i) m[alls[i]] = i;
            for (int i = 0; i < n; ++i) t[i] = m[t[i]];
            for (int i = 0; i < n; ++i) {
                while (t[i] != i) {
                    swap(t[i], t[t[i]]);
                    ++ans;
                }
            }
            return ans;
        };
        while (!q.empty()) {
            vector<int> t;
            for (int n = q.size(); n; --n) {
                auto node = q.front();
                q.pop();
                t.emplace_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans += f(t);
        }
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
func minimumOperations(root *TreeNode) (ans int) {
	f := func(t []int) int {
		var alls []int
		for _, v := range t {
			alls = append(alls, v)
		}
		sort.Ints(alls)
		m := make(map[int]int)
		for i, v := range alls {
			m[v] = i
		}
		for i := range t {
			t[i] = m[t[i]]
		}
		res := 0
		for i := range t {
			for t[i] != i {
				t[i], t[t[i]] = t[t[i]], t[i]
				res++
			}
		}
		return res
	}

	q := []*TreeNode{root}
	for len(q) > 0 {
		t := []int{}
		for n := len(q); n > 0; n-- {
			node := q[0]
			q = q[1:]
			t = append(t, node.Val)
			if node.Left != nil {
				q = append(q, node.Left)
			}
			if node.Right != nil {
				q = append(q, node.Right)
			}
		}
		ans += f(t)
	}
	return
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

function minimumOperations(root: TreeNode | null): number {
    const queue = [root];
    let ans = 0;
    while (queue.length !== 0) {
        const n = queue.length;
        const row: number[] = [];
        for (let i = 0; i < n; i++) {
            const { val, left, right } = queue.shift();
            row.push(val);
            left && queue.push(left);
            right && queue.push(right);
        }
        for (let i = 0; i < n - 1; i++) {
            let minIdx = i;
            for (let j = i + 1; j < n; j++) {
                if (row[j] < row[minIdx]) {
                    minIdx = j;
                }
            }
            if (i !== minIdx) {
                [row[i], row[minIdx]] = [row[minIdx], row[i]];
                ans++;
            }
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::cell::RefCell;
use std::collections::VecDeque;
use std::rc::Rc;
impl Solution {
    pub fn minimum_operations(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut queue = VecDeque::new();
        queue.push_back(root);
        let mut ans = 0;
        while !queue.is_empty() {
            let n = queue.len();
            let mut row = Vec::new();
            for _ in 0..n {
                let mut node = queue.pop_front().unwrap();
                let mut node = node.as_mut().unwrap().borrow_mut();
                row.push(node.val);
                if node.left.is_some() {
                    queue.push_back(node.left.take());
                }
                if node.right.is_some() {
                    queue.push_back(node.right.take());
                }
            }
            for i in 0..n - 1 {
                let mut min_idx = i;
                for j in i + 1..n {
                    if row[j] < row[min_idx] {
                        min_idx = j;
                    }
                }
                if i != min_idx {
                    row.swap(i, min_idx);
                    ans += 1;
                }
            }
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

<p>给你一个 <strong>值互不相同</strong> 的二叉树的根节点 <code>root</code> 。</p>

<p>在一步操作中，你可以选择 <strong>同一层</strong> 上任意两个节点，交换这两个节点的值。</p>

<p>返回每一层按 <strong>严格递增顺序</strong> 排序所需的最少操作数目。</p>

<p>节点的 <strong>层数</strong> 是该节点和根节点之间的路径的边数。</p>

<p>&nbsp;</p>

<p><strong>示例 1 ：</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2400-2499/2471.Minimum%20Number%20of%20Operations%20to%20Sort%20a%20Binary%20Tree%20by%20Level/images/image-20220918174006-2.png" style="width: 500px; height: 324px;">
<pre><strong>输入：</strong>root = [1,4,3,7,6,8,5,null,null,null,null,9,null,10]
<strong>输出：</strong>3
<strong>解释：</strong>
- 交换 4 和 3 。第 2 层变为 [3,4] 。
- 交换 7 和 5 。第 3 层变为 [5,6,8,7] 。
- 交换 8 和 7 。第 3 层变为 [5,6,7,8] 。
共计用了 3 步操作，所以返回 3 。
可以证明 3 是需要的最少操作数目。
</pre>

<p><strong>示例 2 ：</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2400-2499/2471.Minimum%20Number%20of%20Operations%20to%20Sort%20a%20Binary%20Tree%20by%20Level/images/image-20220918174026-3.png" style="width: 400px; height: 303px;">
<pre><strong>输入：</strong>root = [1,3,2,7,6,5,4]
<strong>输出：</strong>3
<strong>解释：
</strong>- 交换 3 和 2 。第 2 层变为 [2,3] 。 
- 交换 7 和 4 。第 3 层变为 [4,6,5,7] 。 
- 交换 6 和 5 。第 3 层变为 [4,5,6,7] 。
共计用了 3 步操作，所以返回 3 。 
可以证明 3 是需要的最少操作数目。
</pre>

<p><strong>示例 3 ：</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2400-2499/2471.Minimum%20Number%20of%20Operations%20to%20Sort%20a%20Binary%20Tree%20by%20Level/images/image-20220918174052-4.png" style="width: 400px; height: 274px;">
<pre><strong>输入：</strong>root = [1,2,3,4,5,6]
<strong>输出：</strong>0
<strong>解释：</strong>每一层已经按递增顺序排序，所以返回 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点的数目在范围 <code>[1, 10<sup>5</sup>]</code> 。</li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
	<li>树中的所有值 <strong>互不相同</strong> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS + 离散化 + 元素交换

我们先通过 `BFS` 遍历二叉树，找到每一层的节点值，然后对每一层的节点值进行排序，如果排序后的节点值与原节点值不同，则说明需要交换元素，交换元素的次数即为该层需要的操作数。

时间复杂度 $O(n \times \log n)$。其中 $n$ 为二叉树的节点数。

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
    def minimumOperations(self, root: Optional[TreeNode]) -> int:
        def swap(arr, i, j):
            arr[i], arr[j] = arr[j], arr[i]

        def f(t):
            n = len(t)
            m = {v: i for i, v in enumerate(sorted(t))}
            for i in range(n):
                t[i] = m[t[i]]
            ans = 0
            for i in range(n):
                while t[i] != i:
                    swap(t, i, t[i])
                    ans += 1
            return ans

        q = deque([root])
        ans = 0
        while q:
            t = []
            for _ in range(len(q)):
                node = q.popleft()
                t.append(node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            ans += f(t)
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
    public int minimumOperations(TreeNode root) {
        Deque<TreeNode> q = new ArrayDeque<>();
        q.offer(root);
        int ans = 0;
        while (!q.isEmpty()) {
            List<Integer> t = new ArrayList<>();
            for (int n = q.size(); n > 0; --n) {
                TreeNode node = q.poll();
                t.add(node.val);
                if (node.left != null) {
                    q.offer(node.left);
                }
                if (node.right != null) {
                    q.offer(node.right);
                }
            }
            ans += f(t);
        }
        return ans;
    }

    private int f(List<Integer> t) {
        int n = t.size();
        List<Integer> alls = new ArrayList<>(t);
        alls.sort((a, b) -> a - b);
        Map<Integer, Integer> m = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            m.put(alls.get(i), i);
        }
        int[] arr = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = m.get(t.get(i));
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            while (arr[i] != i) {
                swap(arr, i, arr[i]);
                ++ans;
            }
        }
        return ans;
    }

    private void swap(int[] arr, int i, int j) {
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q{{root}};
        int ans = 0;
        auto f = [](vector<int>& t) {
            int n = t.size();
            vector<int> alls(t.begin(), t.end());
            sort(alls.begin(), alls.end());
            unordered_map<int, int> m;
            int ans = 0;
            for (int i = 0; i < n; ++i) m[alls[i]] = i;
            for (int i = 0; i < n; ++i) t[i] = m[t[i]];
            for (int i = 0; i < n; ++i) {
                while (t[i] != i) {
                    swap(t[i], t[t[i]]);
                    ++ans;
                }
            }
            return ans;
        };
        while (!q.empty()) {
            vector<int> t;
            for (int n = q.size(); n; --n) {
                auto node = q.front();
                q.pop();
                t.emplace_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans += f(t);
        }
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
func minimumOperations(root *TreeNode) (ans int) {
	f := func(t []int) int {
		var alls []int
		for _, v := range t {
			alls = append(alls, v)
		}
		sort.Ints(alls)
		m := make(map[int]int)
		for i, v := range alls {
			m[v] = i
		}
		for i := range t {
			t[i] = m[t[i]]
		}
		res := 0
		for i := range t {
			for t[i] != i {
				t[i], t[t[i]] = t[t[i]], t[i]
				res++
			}
		}
		return res
	}

	q := []*TreeNode{root}
	for len(q) > 0 {
		t := []int{}
		for n := len(q); n > 0; n-- {
			node := q[0]
			q = q[1:]
			t = append(t, node.Val)
			if node.Left != nil {
				q = append(q, node.Left)
			}
			if node.Right != nil {
				q = append(q, node.Right)
			}
		}
		ans += f(t)
	}
	return
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

function minimumOperations(root: TreeNode | null): number {
    const queue = [root];
    let ans = 0;
    while (queue.length !== 0) {
        const n = queue.length;
        const row: number[] = [];
        for (let i = 0; i < n; i++) {
            const { val, left, right } = queue.shift();
            row.push(val);
            left && queue.push(left);
            right && queue.push(right);
        }
        for (let i = 0; i < n - 1; i++) {
            let minIdx = i;
            for (let j = i + 1; j < n; j++) {
                if (row[j] < row[minIdx]) {
                    minIdx = j;
                }
            }
            if (i !== minIdx) {
                [row[i], row[minIdx]] = [row[minIdx], row[i]];
                ans++;
            }
        }
    }
    return ans;
}
```

#### Rust

```rust
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::cell::RefCell;
use std::collections::VecDeque;
use std::rc::Rc;
impl Solution {
    pub fn minimum_operations(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut queue = VecDeque::new();
        queue.push_back(root);
        let mut ans = 0;
        while !queue.is_empty() {
            let n = queue.len();
            let mut row = Vec::new();
            for _ in 0..n {
                let mut node = queue.pop_front().unwrap();
                let mut node = node.as_mut().unwrap().borrow_mut();
                row.push(node.val);
                if node.left.is_some() {
                    queue.push_back(node.left.take());
                }
                if node.right.is_some() {
                    queue.push_back(node.right.take());
                }
            }
            for i in 0..n - 1 {
                let mut min_idx = i;
                for j in i + 1..n {
                    if row[j] < row[min_idx] {
                        min_idx = j;
                    }
                }
                if i != min_idx {
                    row.swap(i, min_idx);
                    ans += 1;
                }
            }
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

# [2472. 不重叠回文子字符串的最大数目](https://leetcode.cn/problems/maximum-number-of-non-overlapping-palindrome-substrings){#2472}

{{< tabs "2472" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxPalindromes(self, s: str, k: int) -> int:
        @cache
        def dfs(i):
            if i >= n:
                return 0
            ans = dfs(i + 1)
            for j in range(i + k - 1, n):
                if dp[i][j]:
                    ans = max(ans, 1 + dfs(j + 1))
            return ans

        n = len(s)
        dp = [[True] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                dp[i][j] = s[i] == s[j] and dp[i + 1][j - 1]
        ans = dfs(0)
        dfs.cache_clear()
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private boolean[][] dp;
    private int[] f;
    private String s;
    private int n;
    private int k;

    public int maxPalindromes(String s, int k) {
        n = s.length();
        f = new int[n];
        this.s = s;
        this.k = k;
        dp = new boolean[n][n];
        for (int i = 0; i < n; ++i) {
            Arrays.fill(dp[i], true);
            f[i] = -1;
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                dp[i][j] = s.charAt(i) == s.charAt(j) && dp[i + 1][j - 1];
            }
        }
        return dfs(0);
    }

    private int dfs(int i) {
        if (i >= n) {
            return 0;
        }
        if (f[i] != -1) {
            return f[i];
        }
        int ans = dfs(i + 1);
        for (int j = i + k - 1; j < n; ++j) {
            if (dp[i][j]) {
                ans = Math.max(ans, 1 + dfs(j + 1));
            }
        }
        f[i] = ans;
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, true));
        vector<int> f(n, -1);
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
            }
        }
        function<int(int)> dfs = [&](int i) -> int {
            if (i >= n) return 0;
            if (f[i] != -1) return f[i];
            int ans = dfs(i + 1);
            for (int j = i + k - 1; j < n; ++j) {
                if (dp[i][j]) {
                    ans = max(ans, 1 + dfs(j + 1));
                }
            }
            f[i] = ans;
            return ans;
        };
        return dfs(0);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxPalindromes(s string, k int) int {
	n := len(s)
	dp := make([][]bool, n)
	f := make([]int, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]bool, n)
		f[i] = -1
		for j := 0; j < n; j++ {
			dp[i][j] = true
		}
	}
	for i := n - 1; i >= 0; i-- {
		for j := i + 1; j < n; j++ {
			dp[i][j] = s[i] == s[j] && dp[i+1][j-1]
		}
	}
	var dfs func(int) int
	dfs = func(i int) int {
		if i >= n {
			return 0
		}
		if f[i] != -1 {
			return f[i]
		}
		ans := dfs(i + 1)
		for j := i + k - 1; j < n; j++ {
			if dp[i][j] {
				ans = max(ans, 1+dfs(j+1))
			}
		}
		f[i] = ans
		return ans
	}
	return dfs(0)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>s</code> 和一个 <strong>正</strong> 整数 <code>k</code> 。</p>

<p>从字符串 <code>s</code> 中选出一组满足下述条件且 <strong>不重叠</strong> 的子字符串：</p>

<ul>
	<li>每个子字符串的长度 <strong>至少</strong> 为 <code>k</code> 。</li>
	<li>每个子字符串是一个 <strong>回文串</strong> 。</li>
</ul>

<p>返回最优方案中能选择的子字符串的 <strong>最大</strong> 数目。</p>

<p><strong>子字符串</strong> 是字符串中一个连续的字符序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1 ：</strong></p>

<pre>
<strong>输入：</strong>s = "abaccdbbd", k = 3
<strong>输出：</strong>2
<strong>解释：</strong>可以选择 s = "<em><strong>aba</strong></em>cc<em><strong>dbbd</strong></em>" 中斜体加粗的子字符串。"aba" 和 "dbbd" 都是回文，且长度至少为 k = 3 。
可以证明，无法选出两个以上的有效子字符串。
</pre>

<p><strong>示例 2 ：</strong></p>

<pre>
<strong>输入：</strong>s = "adbcda", k = 2
<strong>输出：</strong>0
<strong>解释：</strong>字符串中不存在长度至少为 2 的回文子字符串。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= s.length &lt;= 2000</code></li>
	<li><code>s</code> 仅由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：预处理 + 记忆化搜索

预处理字符串 $s$，得到 $dp[i][j]$ 表示字符串 $s[i,..j]$ 是否为回文串。

然后定义函数 $dfs(i)$ 表示从字符串 $s[i,..]$ 中选出最多的不重叠回文子串的个数，即：

$$
\begin{aligned}
dfs(i) &= \begin{cases}
0, & i \geq n \\
\max\{dfs(i + 1), \max_{j \geq i + k - 1} \{dfs(j + 1) + 1\}\}, & i < n
\end{cases}
\end{aligned}
$$

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxPalindromes(self, s: str, k: int) -> int:
        @cache
        def dfs(i):
            if i >= n:
                return 0
            ans = dfs(i + 1)
            for j in range(i + k - 1, n):
                if dp[i][j]:
                    ans = max(ans, 1 + dfs(j + 1))
            return ans

        n = len(s)
        dp = [[True] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                dp[i][j] = s[i] == s[j] and dp[i + 1][j - 1]
        ans = dfs(0)
        dfs.cache_clear()
        return ans
```

#### Java

```java
class Solution {
    private boolean[][] dp;
    private int[] f;
    private String s;
    private int n;
    private int k;

    public int maxPalindromes(String s, int k) {
        n = s.length();
        f = new int[n];
        this.s = s;
        this.k = k;
        dp = new boolean[n][n];
        for (int i = 0; i < n; ++i) {
            Arrays.fill(dp[i], true);
            f[i] = -1;
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                dp[i][j] = s.charAt(i) == s.charAt(j) && dp[i + 1][j - 1];
            }
        }
        return dfs(0);
    }

    private int dfs(int i) {
        if (i >= n) {
            return 0;
        }
        if (f[i] != -1) {
            return f[i];
        }
        int ans = dfs(i + 1);
        for (int j = i + k - 1; j < n; ++j) {
            if (dp[i][j]) {
                ans = Math.max(ans, 1 + dfs(j + 1));
            }
        }
        f[i] = ans;
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, true));
        vector<int> f(n, -1);
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
            }
        }
        function<int(int)> dfs = [&](int i) -> int {
            if (i >= n) return 0;
            if (f[i] != -1) return f[i];
            int ans = dfs(i + 1);
            for (int j = i + k - 1; j < n; ++j) {
                if (dp[i][j]) {
                    ans = max(ans, 1 + dfs(j + 1));
                }
            }
            f[i] = ans;
            return ans;
        };
        return dfs(0);
    }
};
```

#### Go

```go
func maxPalindromes(s string, k int) int {
	n := len(s)
	dp := make([][]bool, n)
	f := make([]int, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]bool, n)
		f[i] = -1
		for j := 0; j < n; j++ {
			dp[i][j] = true
		}
	}
	for i := n - 1; i >= 0; i-- {
		for j := i + 1; j < n; j++ {
			dp[i][j] = s[i] == s[j] && dp[i+1][j-1]
		}
	}
	var dfs func(int) int
	dfs = func(i int) int {
		if i >= n {
			return 0
		}
		if f[i] != -1 {
			return f[i]
		}
		ans := dfs(i + 1)
		for j := i + k - 1; j < n; j++ {
			if dp[i][j] {
				ans = max(ans, 1+dfs(j+1))
			}
		}
		f[i] = ans
		return ans
	}
	return dfs(0)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2473. 购买苹果的最低成本 🔒](https://leetcode.cn/problems/minimum-cost-to-buy-apples){#2473}

{{< tabs "2473" >}}

{{% tab "python" %}}
```python
class Solution:
    def minCost(
        self, n: int, roads: List[List[int]], appleCost: List[int], k: int
    ) -> List[int]:
        def dijkstra(i):
            q = [(0, i)]
            dist = [inf] * n
            dist[i] = 0
            ans = inf
            while q:
                d, u = heappop(q)
                ans = min(ans, appleCost[u] + d * (k + 1))
                for v, w in g[u]:
                    if dist[v] > dist[u] + w:
                        dist[v] = dist[u] + w
                        heappush(q, (dist[v], v))
            return ans

        g = defaultdict(list)
        for a, b, c in roads:
            a, b = a - 1, b - 1
            g[a].append((b, c))
            g[b].append((a, c))
        return [dijkstra(i) for i in range(n)]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int k;
    private int[] cost;
    private int[] dist;
    private List<int[]>[] g;
    private static final int INF = 0x3f3f3f3f;

    public long[] minCost(int n, int[][] roads, int[] appleCost, int k) {
        cost = appleCost;
        g = new List[n];
        dist = new int[n];
        this.k = k;
        for (int i = 0; i < n; ++i) {
            g[i] = new ArrayList<>();
        }
        for (var e : roads) {
            int a = e[0] - 1, b = e[1] - 1, c = e[2];
            g[a].add(new int[] {b, c});
            g[b].add(new int[] {a, c});
        }
        long[] ans = new long[n];
        for (int i = 0; i < n; ++i) {
            ans[i] = dijkstra(i);
        }
        return ans;
    }

    private long dijkstra(int u) {
        PriorityQueue<int[]> q = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        q.offer(new int[] {0, u});
        Arrays.fill(dist, INF);
        dist[u] = 0;
        long ans = Long.MAX_VALUE;
        while (!q.isEmpty()) {
            var p = q.poll();
            int d = p[0];
            u = p[1];
            ans = Math.min(ans, cost[u] + (long) (k + 1) * d);
            for (var ne : g[u]) {
                int v = ne[0], w = ne[1];
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    q.offer(new int[] {dist[v], v});
                }
            }
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
using ll = long long;
using pii = pair<int, int>;

class Solution {
public:
    const int inf = 0x3f3f3f3f;

    vector<long long> minCost(int n, vector<vector<int>>& roads, vector<int>& appleCost, int k) {
        vector<vector<pii>> g(n);
        for (auto& e : roads) {
            int a = e[0] - 1, b = e[1] - 1, c = e[2];
            g[a].push_back({b, c});
            g[b].push_back({a, c});
        }
        int dist[n];
        auto dijkstra = [&](int u) {
            memset(dist, 63, sizeof dist);
            priority_queue<pii, vector<pii>, greater<pii>> q;
            q.push({0, u});
            dist[u] = 0;
            ll ans = LONG_MAX;
            while (!q.empty()) {
                auto p = q.top();
                q.pop();
                int d = p.first;
                u = p.second;
                ans = min(ans, appleCost[u] + 1ll * d * (k + 1));
                for (auto& ne : g[u]) {
                    auto [v, w] = ne;
                    if (dist[v] > dist[u] + w) {
                        dist[v] = dist[u] + w;
                        q.push({dist[v], v});
                    }
                }
            }
            return ans;
        };
        vector<ll> ans(n);
        for (int i = 0; i < n; ++i) ans[i] = dijkstra(i);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minCost(n int, roads [][]int, appleCost []int, k int) []int64 {
	g := make([]pairs, n)
	for _, e := range roads {
		a, b, c := e[0]-1, e[1]-1, e[2]
		g[a] = append(g[a], pair{b, c})
		g[b] = append(g[b], pair{a, c})
	}
	const inf int = 0x3f3f3f3f
	dist := make([]int, n)
	dijkstra := func(u int) int64 {
		var ans int64 = math.MaxInt64
		for i := range dist {
			dist[i] = inf
		}
		dist[u] = 0
		q := make(pairs, 0)
		heap.Push(&q, pair{0, u})
		for len(q) > 0 {
			p := heap.Pop(&q).(pair)
			d := p.first
			u = p.second
			ans = min(ans, int64(appleCost[u]+d*(k+1)))
			for _, ne := range g[u] {
				v, w := ne.first, ne.second
				if dist[v] > dist[u]+w {
					dist[v] = dist[u] + w
					heap.Push(&q, pair{dist[v], v})
				}
			}
		}
		return ans
	}
	ans := make([]int64, n)
	for i := range ans {
		ans[i] = dijkstra(i)
	}
	return ans
}

type pair struct{ first, second int }

var _ heap.Interface = (*pairs)(nil)

type pairs []pair

func (a pairs) Len() int { return len(a) }
func (a pairs) Less(i int, j int) bool {
	return a[i].first < a[j].first || a[i].first == a[j].first && a[i].second < a[j].second
}
func (a pairs) Swap(i int, j int) { a[i], a[j] = a[j], a[i] }
func (a *pairs) Push(x any)       { *a = append(*a, x.(pair)) }
func (a *pairs) Pop() any         { l := len(*a); t := (*a)[l-1]; *a = (*a)[:l-1]; return t }
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个正整数&nbsp; <code>n</code>，表示从 <code>1</code> 到 <code>n</code> 的 <code>n</code> 个城市。还给你一个&nbsp;<strong>二维&nbsp;</strong>数组 <code>roads</code>，其中 <code>roads[i] = [a<sub>i</sub>, b<sub>i</sub>, cost<sub>i</sub>]</code> 表示在城市 <code>a<sub>i</sub></code> 和 <code>b<sub>i</sub></code> 之间有一条双向道路，其旅行成本等于 <code>cost<sub>i</sub></code>。</p>

<p>&nbsp;</p>

<p>你可以在&nbsp;<strong>任何&nbsp;</strong>城市买到苹果，但是有些城市买苹果的费用不同。给定数组 <code>appleCost</code> ，其中 <code>appleCost[i]</code>&nbsp;是从城市 <code>i</code> 购买一个苹果的成本。</p>

<p>你从某个城市开始，穿越各种道路，最终从&nbsp;<strong>任何一个&nbsp;</strong>城市买&nbsp;<strong>一个&nbsp;</strong>苹果。在你买了那个苹果之后，你必须回到你&nbsp;<strong>开始的&nbsp;</strong>城市，但现在所有道路的成本将&nbsp;<strong>乘以&nbsp;</strong>一个给定的因子 <code>k</code>。</p>

<p>给定整数 <code>k</code>，返回<em>一个大小为 <code>n</code> 的从 1 开始的数组 <code>answer</code>，其中 <code>answer[i]</code>&nbsp;是从城市 <code>i</code> 开始购买一个苹果的&nbsp;<strong>最小&nbsp;</strong>总成本。</em></p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2400-2499/2473.Minimum%20Cost%20to%20Buy%20Apples/images/graph55.png" style="width: 241px; height: 309px;" />
<pre>
<strong>输入:</strong> n = 4, roads = [[1,2,4],[2,3,2],[2,4,5],[3,4,1],[1,3,4]], appleCost = [56,42,102,301], k = 2
<strong>输出:</strong> [54,42,48,51]
<strong>解释:</strong> 每个起始城市的最低费用如下:
- 从城市 1 开始:你走路径 1 -&gt; 2，在城市 2 买一个苹果，最后走路径 2 -&gt; 1。总成本是 4 + 42 + 4 * 2 = 54。
- 从城市 2 开始:你直接在城市 2 买一个苹果。总费用是 42。
- 从城市 3 开始:你走路径 3 -&gt; 2，在城市 2 买一个苹果，最后走路径 2 -&gt; 3。总成本是 2 + 42 + 2 * 2 = 48。
- 从城市 4 开始:你走路径 4 -&gt; 3 -&gt; 2，然后你在城市 2 购买，最后走路径 2 -&gt; 3 -&gt; 4。总成本是 1 + 2 + 42 + 1 * 2 + 2 * 2 = 51。
</pre>

<p><strong class="example">示例 2:</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2400-2499/2473.Minimum%20Cost%20to%20Buy%20Apples/images/graph4.png" style="width: 167px; height: 309px;" />
<pre>
<strong>输入:</strong> n = 3, roads = [[1,2,5],[2,3,1],[3,1,2]], appleCost = [2,3,1], k = 3
<strong>输出:</strong> [2,3,1]
<strong>解释:</strong> 在起始城市买苹果总是最优的。</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 1000</code></li>
	<li><code>1 &lt;= roads.length &lt;= 1000</code></li>
	<li><code>1 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt;= n</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li><code>1 &lt;= cost<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
	<li><code>appleCost.length == n</code></li>
	<li><code>1 &lt;= appleCost[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= 100</code></li>
	<li>
	<p data-group="1-1">没有重复的边。</p>
	</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：堆优化版 Dijkstra 算法

我们枚举起点，对于每个起点，使用 Dijkstra 算法求出到其他所有点的最短距离，更新最小值即可。

时间复杂度 $O(n \times m \times \log m)$，其中 $n$ 和 $m$ 分别是城市数量和道路数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minCost(
        self, n: int, roads: List[List[int]], appleCost: List[int], k: int
    ) -> List[int]:
        def dijkstra(i):
            q = [(0, i)]
            dist = [inf] * n
            dist[i] = 0
            ans = inf
            while q:
                d, u = heappop(q)
                ans = min(ans, appleCost[u] + d * (k + 1))
                for v, w in g[u]:
                    if dist[v] > dist[u] + w:
                        dist[v] = dist[u] + w
                        heappush(q, (dist[v], v))
            return ans

        g = defaultdict(list)
        for a, b, c in roads:
            a, b = a - 1, b - 1
            g[a].append((b, c))
            g[b].append((a, c))
        return [dijkstra(i) for i in range(n)]
```

#### Java

```java
class Solution {
    private int k;
    private int[] cost;
    private int[] dist;
    private List<int[]>[] g;
    private static final int INF = 0x3f3f3f3f;

    public long[] minCost(int n, int[][] roads, int[] appleCost, int k) {
        cost = appleCost;
        g = new List[n];
        dist = new int[n];
        this.k = k;
        for (int i = 0; i < n; ++i) {
            g[i] = new ArrayList<>();
        }
        for (var e : roads) {
            int a = e[0] - 1, b = e[1] - 1, c = e[2];
            g[a].add(new int[] {b, c});
            g[b].add(new int[] {a, c});
        }
        long[] ans = new long[n];
        for (int i = 0; i < n; ++i) {
            ans[i] = dijkstra(i);
        }
        return ans;
    }

    private long dijkstra(int u) {
        PriorityQueue<int[]> q = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        q.offer(new int[] {0, u});
        Arrays.fill(dist, INF);
        dist[u] = 0;
        long ans = Long.MAX_VALUE;
        while (!q.isEmpty()) {
            var p = q.poll();
            int d = p[0];
            u = p[1];
            ans = Math.min(ans, cost[u] + (long) (k + 1) * d);
            for (var ne : g[u]) {
                int v = ne[0], w = ne[1];
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    q.offer(new int[] {dist[v], v});
                }
            }
        }
        return ans;
    }
}
```

#### C++

```cpp
using ll = long long;
using pii = pair<int, int>;

class Solution {
public:
    const int inf = 0x3f3f3f3f;

    vector<long long> minCost(int n, vector<vector<int>>& roads, vector<int>& appleCost, int k) {
        vector<vector<pii>> g(n);
        for (auto& e : roads) {
            int a = e[0] - 1, b = e[1] - 1, c = e[2];
            g[a].push_back({b, c});
            g[b].push_back({a, c});
        }
        int dist[n];
        auto dijkstra = [&](int u) {
            memset(dist, 63, sizeof dist);
            priority_queue<pii, vector<pii>, greater<pii>> q;
            q.push({0, u});
            dist[u] = 0;
            ll ans = LONG_MAX;
            while (!q.empty()) {
                auto p = q.top();
                q.pop();
                int d = p.first;
                u = p.second;
                ans = min(ans, appleCost[u] + 1ll * d * (k + 1));
                for (auto& ne : g[u]) {
                    auto [v, w] = ne;
                    if (dist[v] > dist[u] + w) {
                        dist[v] = dist[u] + w;
                        q.push({dist[v], v});
                    }
                }
            }
            return ans;
        };
        vector<ll> ans(n);
        for (int i = 0; i < n; ++i) ans[i] = dijkstra(i);
        return ans;
    }
};
```

#### Go

```go
func minCost(n int, roads [][]int, appleCost []int, k int) []int64 {
	g := make([]pairs, n)
	for _, e := range roads {
		a, b, c := e[0]-1, e[1]-1, e[2]
		g[a] = append(g[a], pair{b, c})
		g[b] = append(g[b], pair{a, c})
	}
	const inf int = 0x3f3f3f3f
	dist := make([]int, n)
	dijkstra := func(u int) int64 {
		var ans int64 = math.MaxInt64
		for i := range dist {
			dist[i] = inf
		}
		dist[u] = 0
		q := make(pairs, 0)
		heap.Push(&q, pair{0, u})
		for len(q) > 0 {
			p := heap.Pop(&q).(pair)
			d := p.first
			u = p.second
			ans = min(ans, int64(appleCost[u]+d*(k+1)))
			for _, ne := range g[u] {
				v, w := ne.first, ne.second
				if dist[v] > dist[u]+w {
					dist[v] = dist[u] + w
					heap.Push(&q, pair{dist[v], v})
				}
			}
		}
		return ans
	}
	ans := make([]int64, n)
	for i := range ans {
		ans[i] = dijkstra(i)
	}
	return ans
}

type pair struct{ first, second int }

var _ heap.Interface = (*pairs)(nil)

type pairs []pair

func (a pairs) Len() int { return len(a) }
func (a pairs) Less(i int, j int) bool {
	return a[i].first < a[j].first || a[i].first == a[j].first && a[i].second < a[j].second
}
func (a pairs) Swap(i int, j int) { a[i], a[j] = a[j], a[i] }
func (a *pairs) Push(x any)       { *a = append(*a, x.(pair)) }
func (a *pairs) Pop() any         { l := len(*a); t := (*a)[l-1]; *a = (*a)[:l-1]; return t }
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2474. 购买量严格增加的客户 🔒](https://leetcode.cn/problems/customers-with-strictly-increasing-purchases){#2474}

{{< tabs "2474" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    customer_id
FROM
    (
        SELECT
            customer_id,
            YEAR(order_date),
            SUM(price) AS total,
            YEAR(order_date) - RANK() OVER (
                PARTITION BY customer_id
                ORDER BY SUM(price)
            ) AS rk
        FROM Orders
        GROUP BY customer_id, YEAR(order_date)
    ) AS t
GROUP BY customer_id
HAVING COUNT(DISTINCT rk) = 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Orders</code></p>

<pre>
+--------------+------+
| Column Name  | Type |
+--------------+------+
| order_id     | int  |
| customer_id  | int  |
| order_date   | date |
| price        | int  |
+--------------+------+
order_id 是该表的主键。
每行包含订单的 id、订购该订单的客户 id、订单日期和价格。
</pre>

<p>&nbsp;</p>

<p>编写一个 SQL 查询，报告&nbsp;<strong>总购买量&nbsp;</strong>每年严格增加的客户 id。</p>

<ul>
	<li>客户在一年内的&nbsp;<strong>总购买量&nbsp;</strong>是该年订单价格的总和。如果某一年客户没有下任何订单，我们认为总购买量为 <code>0</code>。</li>
	<li>对于每个客户，要考虑的第一个年是他们&nbsp;<strong>第一次下单&nbsp;</strong>的年份。</li>
	<li>对于每个客户，要考虑的最后一年是他们&nbsp;<strong>最后一次下单&nbsp;</strong>的年份。</li>
</ul>

<p>以&nbsp;<strong>任意顺序&nbsp;</strong>返回结果表。</p>

<p>查询结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
Orders 表:
+----------+-------------+------------+-------+
| order_id | customer_id | order_date | price |
+----------+-------------+------------+-------+
| 1        | 1           | 2019-07-01 | 1100  |
| 2        | 1           | 2019-11-01 | 1200  |
| 3        | 1           | 2020-05-26 | 3000  |
| 4        | 1           | 2021-08-31 | 3100  |
| 5        | 1           | 2022-12-07 | 4700  |
| 6        | 2           | 2015-01-01 | 700   |
| 7        | 2           | 2017-11-07 | 1000  |
| 8        | 3           | 2017-01-01 | 900   |
| 9        | 3           | 2018-11-07 | 900   |
+----------+-------------+------------+-------+
<strong>输出:</strong> 
+-------------+
| customer_id |
+-------------+
| 1           |
+-------------+
<strong>解释:</strong> 
客户 1: 第一年是 2019 年，最后一年是 2022 年
  - 2019: 1100 + 1200 = 2300
  - 2020: 3000
  - 2021: 3100
  - 2022: 4700
  我们可以看到总购买量每年都在严格增加，所以我们在答案中包含了客户 1。

客户 2: 第一年是2015年，最后一年是2017年
  - 2015: 700
  - 2016: 0
  - 2017: 1000
  我们没有把客户 2 包括在答案中，因为总的购买量并没有严格地增加。请注意，客户 2 在 2016 年没有购买任何物品。

客户 3: 第一年是 2017 年，最后一年是 2018 年
  - 2017: 900
  - 2018: 900</pre>

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
SELECT
    customer_id
FROM
    (
        SELECT
            customer_id,
            YEAR(order_date),
            SUM(price) AS total,
            YEAR(order_date) - RANK() OVER (
                PARTITION BY customer_id
                ORDER BY SUM(price)
            ) AS rk
        FROM Orders
        GROUP BY customer_id, YEAR(order_date)
    ) AS t
GROUP BY customer_id
HAVING COUNT(DISTINCT rk) = 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2475. 数组中不等三元组的数目](https://leetcode.cn/problems/number-of-unequal-triplets-in-array){#2475}

{{< tabs "2475" >}}

{{% tab "python" %}}
```python
class Solution:
    def unequalTriplets(self, nums: List[int]) -> int:
        cnt = Counter(nums)
        n = len(nums)
        ans = a = 0
        for b in cnt.values():
            c = n - a - b
            ans += a * b * c
            a += b
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int unequalTriplets(int[] nums) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int v : nums) {
            cnt.merge(v, 1, Integer::sum);
        }
        int ans = 0, a = 0;
        int n = nums.length;
        for (int b : cnt.values()) {
            int c = n - a - b;
            ans += a * b * c;
            a += b;
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
    int unequalTriplets(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int& v : nums) {
            ++cnt[v];
        }
        int ans = 0, a = 0;
        int n = nums.size();
        for (auto& [_, b] : cnt) {
            int c = n - a - b;
            ans += a * b * c;
            a += b;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func unequalTriplets(nums []int) (ans int) {
	cnt := map[int]int{}
	for _, v := range nums {
		cnt[v]++
	}
	a, n := 0, len(nums)
	for _, b := range cnt {
		c := n - a - b
		ans += a * b * c
		a += b
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function unequalTriplets(nums: number[]): number {
    const n = nums.length;
    const cnt = new Map<number, number>();
    for (const num of nums) {
        cnt.set(num, (cnt.get(num) ?? 0) + 1);
    }
    let ans = 0;
    let a = 0;
    for (const b of cnt.values()) {
        const c = n - a - b;
        ans += a * b * c;
        a += b;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn unequal_triplets(nums: Vec<i32>) -> i32 {
        let mut ans = 0;
        let mut nums = nums;
        nums.sort();
        let n = nums.len();

        for i in 1..n - 1 {
            let mut l = 0;
            let mut r = i;
            while l < r {
                let mid = (l + r) >> 1;
                if nums[mid] >= nums[i] {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            let j = r;

            let mut l = i + 1;
            let mut r = n;
            while l < r {
                let mid = (l + r) >> 1;
                if nums[mid] > nums[i] {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            let k = r;

            ans += j * (n - k);
        }

        ans as i32
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始的正整数数组 <code>nums</code> 。请你找出并统计满足下述条件的三元组 <code>(i, j, k)</code> 的数目：</p>

<ul>
	<li><code>0 &lt;= i &lt; j &lt; k &lt; nums.length</code></li>
	<li><code>nums[i]</code>、<code>nums[j]</code> 和 <code>nums[k]</code> <strong>两两不同</strong> 。
	<ul>
		<li>换句话说：<code>nums[i] != nums[j]</code>、<code>nums[i] != nums[k]</code> 且 <code>nums[j] != nums[k]</code> 。</li>
	</ul>
	</li>
</ul>

<p>返回满足上述条件三元组的数目<em>。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [4,4,2,4,3]
<strong>输出：</strong>3
<strong>解释：</strong>下面列出的三元组均满足题目条件：
- (0, 2, 4) 因为 4 != 2 != 3
- (1, 2, 4) 因为 4 != 2 != 3
- (2, 3, 4) 因为 2 != 4 != 3
共计 3 个三元组，返回 3 。
注意 (2, 0, 4) 不是有效的三元组，因为 2 &gt; 0 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,1,1,1]
<strong>输出：</strong>0
<strong>解释：</strong>不存在满足条件的三元组，所以返回 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：暴力枚举

我们可以直接枚举所有的三元组 $(i, j, k)$，统计所有符合条件的数量。

时间复杂度 $O(n^3)$，其中 $n$ 为数组 $nums$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def unequalTriplets(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0
        for i in range(n):
            for j in range(i + 1, n):
                for k in range(j + 1, n):
                    ans += (
                        nums[i] != nums[j] and nums[j] != nums[k] and nums[i] != nums[k]
                    )
        return ans
```

#### Java

```java
class Solution {
    public int unequalTriplets(int[] nums) {
        int n = nums.length;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (nums[i] != nums[j] && nums[j] != nums[k] && nums[i] != nums[k]) {
                        ++ans;
                    }
                }
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
    int unequalTriplets(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (nums[i] != nums[j] && nums[j] != nums[k] && nums[i] != nums[k]) {
                        ++ans;
                    }
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func unequalTriplets(nums []int) (ans int) {
	n := len(nums)
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			for k := j + 1; k < n; k++ {
				if nums[i] != nums[j] && nums[j] != nums[k] && nums[i] != nums[k] {
					ans++
				}
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function unequalTriplets(nums: number[]): number {
    const n = nums.length;
    let ans = 0;
    for (let i = 0; i < n - 2; i++) {
        for (let j = i + 1; j < n - 1; j++) {
            for (let k = j + 1; k < n; k++) {
                if (nums[i] !== nums[j] && nums[j] !== nums[k] && nums[i] !== nums[k]) {
                    ans++;
                }
            }
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn unequal_triplets(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut ans = 0;
        for i in 0..n - 2 {
            for j in i + 1..n - 1 {
                for k in j + 1..n {
                    if nums[i] != nums[j] && nums[j] != nums[k] && nums[i] != nums[k] {
                        ans += 1;
                    }
                }
            }
        }
        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：排序 + 枚举中间元素 + 二分查找

我们也可以先对数组 $nums$ 进行排序。

然后遍历 $nums$，枚举中间元素 $nums[j]$，利用二分查找，在 $nums[j]$ 左侧找到最近的下标 $i$，使得 $nums[i] \lt nums[j]$ 成立；在 $nums[j]$ 右侧找到最近的下标 $k$，使得 $nums[k] \gt nums[j]$ 成立。那么以 $nums[j]$ 作为中间元素，且符合条件的三元组数量为 $(i + 1) \times (n - k)$，累加到答案中。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def unequalTriplets(self, nums: List[int]) -> int:
        nums.sort()
        ans, n = 0, len(nums)
        for j in range(1, n - 1):
            i = bisect_left(nums, nums[j], hi=j) - 1
            k = bisect_right(nums, nums[j], lo=j + 1)
            ans += (i >= 0 and k < n) * (i + 1) * (n - k)
        return ans
```

#### Java

```java
class Solution {
    public int unequalTriplets(int[] nums) {
        Arrays.sort(nums);
        int ans = 0, n = nums.length;
        for (int j = 1; j < n - 1; ++j) {
            int i = search(nums, nums[j], 0, j) - 1;
            int k = search(nums, nums[j] + 1, j + 1, n);
            if (i >= 0 && k < n) {
                ans += (i + 1) * (n - k);
            }
        }
        return ans;
    }

    private int search(int[] nums, int x, int left, int right) {
        while (left < right) {
            int mid = (left + right) >> 1;
            if (nums[mid] >= x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0, n = nums.size();
        for (int j = 1; j < n - 1; ++j) {
            int i = lower_bound(nums.begin(), nums.begin() + j, nums[j]) - nums.begin() - 1;
            int k = upper_bound(nums.begin() + j + 1, nums.end(), nums[j]) - nums.begin();
            if (i >= 0 && k < n) {
                ans += (i + 1) * (n - k);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func unequalTriplets(nums []int) (ans int) {
	sort.Ints(nums)
	n := len(nums)
	for j := 1; j < n-1; j++ {
		i := sort.Search(j, func(h int) bool { return nums[h] >= nums[j] }) - 1
		k := sort.Search(n, func(h int) bool { return h > j && nums[h] > nums[j] })
		if i >= 0 && k < n {
			ans += (i + 1) * (n - k)
		}
	}
	return
}
```

#### TypeScript

```ts
function unequalTriplets(nums: number[]): number {
    const n = nums.length;
    const cnt = new Map<number, number>();
    for (const num of nums) {
        cnt.set(num, (cnt.get(num) ?? 0) + 1);
    }
    let ans = 0;
    let a = 0;
    for (const b of cnt.values()) {
        const c = n - a - b;
        ans += a * b * c;
        a += b;
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::HashMap;
impl Solution {
    pub fn unequal_triplets(nums: Vec<i32>) -> i32 {
        let mut cnt = HashMap::new();
        for num in nums.iter() {
            *cnt.entry(num).or_insert(0) += 1;
        }
        let n = nums.len();
        let mut ans = 0;
        let mut a = 0;
        for v in cnt.values() {
            let b = n - a - v;
            ans += v * a * b;
            a += v;
        }
        ans as i32
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三：哈希表

我们还可以使用哈希表 $cnt$ 来统计数组 $nums$ 中每个元素的数量。

然后遍历哈希表 $cnt$，枚举中间元素的个数 $b$，左侧元素个数记为 $a$，那么右侧元素个数有 $c = n - a - b$，此时符合条件的三元组数量为 $a \times b \times c$，累加到答案中。接着更新 $a = a + b$，继续枚举中间元素的个数 $b$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def unequalTriplets(self, nums: List[int]) -> int:
        cnt = Counter(nums)
        n = len(nums)
        ans = a = 0
        for b in cnt.values():
            c = n - a - b
            ans += a * b * c
            a += b
        return ans
```

#### Java

```java
class Solution {
    public int unequalTriplets(int[] nums) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int v : nums) {
            cnt.merge(v, 1, Integer::sum);
        }
        int ans = 0, a = 0;
        int n = nums.length;
        for (int b : cnt.values()) {
            int c = n - a - b;
            ans += a * b * c;
            a += b;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int& v : nums) {
            ++cnt[v];
        }
        int ans = 0, a = 0;
        int n = nums.size();
        for (auto& [_, b] : cnt) {
            int c = n - a - b;
            ans += a * b * c;
            a += b;
        }
        return ans;
    }
};
```

#### Go

```go
func unequalTriplets(nums []int) (ans int) {
	cnt := map[int]int{}
	for _, v := range nums {
		cnt[v]++
	}
	a, n := 0, len(nums)
	for _, b := range cnt {
		c := n - a - b
		ans += a * b * c
		a += b
	}
	return
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn unequal_triplets(nums: Vec<i32>) -> i32 {
        let cnt = nums.iter().fold(HashMap::new(), |mut map, &n| {
            *map.entry(n).or_insert(0) += 1;
            map
        });

        let mut ans = 0;
        let n = nums.len();
        let mut a = 0;
        for &b in cnt.values() {
            let c = n - a - b;
            ans += a * b * c;
            a += b;
        }

        ans as i32
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法四

<!-- tabs:start -->

#### Rust

```rust
impl Solution {
    pub fn unequal_triplets(nums: Vec<i32>) -> i32 {
        let mut ans = 0;
        let mut nums = nums;
        nums.sort();
        let n = nums.len();

        for i in 1..n - 1 {
            let mut l = 0;
            let mut r = i;
            while l < r {
                let mid = (l + r) >> 1;
                if nums[mid] >= nums[i] {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            let j = r;

            let mut l = i + 1;
            let mut r = n;
            while l < r {
                let mid = (l + r) >> 1;
                if nums[mid] > nums[i] {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            let k = r;

            ans += j * (n - k);
        }

        ans as i32
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2476. 二叉搜索树最近节点查询](https://leetcode.cn/problems/closest-nodes-queries-in-a-binary-search-tree){#2476}

{{< tabs "2476" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def closestNodes(
        self, root: Optional[TreeNode], queries: List[int]
    ) -> List[List[int]]:
        def dfs(root: Optional[TreeNode]):
            if root is None:
                return
            dfs(root.left)
            nums.append(root.val)
            dfs(root.right)

        nums = []
        dfs(root)
        ans = []
        for x in queries:
            i = bisect_left(nums, x + 1) - 1
            j = bisect_left(nums, x)
            mi = nums[i] if 0 <= i < len(nums) else -1
            mx = nums[j] if 0 <= j < len(nums) else -1
            ans.append([mi, mx])
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
    private List<Integer> nums = new ArrayList<>();

    public List<List<Integer>> closestNodes(TreeNode root, List<Integer> queries) {
        dfs(root);
        List<List<Integer>> ans = new ArrayList<>();
        for (int x : queries) {
            int i = Collections.binarySearch(nums, x + 1);
            int j = Collections.binarySearch(nums, x);
            i = i < 0 ? -i - 2 : i - 1;
            j = j < 0 ? -j - 1 : j;
            int mi = i >= 0 && i < nums.size() ? nums.get(i) : -1;
            int mx = j >= 0 && j < nums.size() ? nums.get(j) : -1;
            ans.add(List.of(mi, mx));
        }
        return ans;
    }

    private void dfs(TreeNode root) {
        if (root == null) {
            return;
        }
        dfs(root.left);
        nums.add(root.val);
        dfs(root.right);
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
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> nums;
        function<void(TreeNode*)> dfs = [&](TreeNode* root) {
            if (!root) {
                return;
            }
            dfs(root->left);
            nums.push_back(root->val);
            dfs(root->right);
        };
        dfs(root);
        vector<vector<int>> ans;
        int n = nums.size();
        for (int& x : queries) {
            int i = lower_bound(nums.begin(), nums.end(), x + 1) - nums.begin() - 1;
            int j = lower_bound(nums.begin(), nums.end(), x) - nums.begin();
            int mi = i >= 0 && i < n ? nums[i] : -1;
            int mx = j >= 0 && j < n ? nums[j] : -1;
            ans.push_back({mi, mx});
        }
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
func closestNodes(root *TreeNode, queries []int) (ans [][]int) {
	nums := []int{}
	var dfs func(*TreeNode)
	dfs = func(root *TreeNode) {
		if root == nil {
			return
		}
		dfs(root.Left)
		nums = append(nums, root.Val)
		dfs(root.Right)
	}
	dfs(root)
	for _, x := range queries {
		i := sort.SearchInts(nums, x+1) - 1
		j := sort.SearchInts(nums, x)
		mi, mx := -1, -1
		if i >= 0 {
			mi = nums[i]
		}
		if j < len(nums) {
			mx = nums[j]
		}
		ans = append(ans, []int{mi, mx})
	}
	return
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

function closestNodes(root: TreeNode | null, queries: number[]): number[][] {
    const nums: number[] = [];
    const dfs = (root: TreeNode | null) => {
        if (!root) {
            return;
        }
        dfs(root.left);
        nums.push(root.val);
        dfs(root.right);
    };
    const search = (x: number): number => {
        let [l, r] = [0, nums.length];
        while (l < r) {
            const mid = (l + r) >> 1;
            if (nums[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };
    dfs(root);
    const ans: number[][] = [];
    for (const x of queries) {
        const i = search(x + 1) - 1;
        const j = search(x);
        const mi = i >= 0 ? nums[i] : -1;
        const mx = j < nums.length ? nums[j] : -1;
        ans.push([mi, mx]);
    }
    return ans;
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
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    private List<int> nums = new List<int>();

    public IList<IList<int>> ClosestNodes(TreeNode root, IList<int> queries) {
        Dfs(root);
        List<IList<int>> ans = new List<IList<int>>();
        foreach (int x in queries) {
            int i = nums.BinarySearch(x + 1);
            int j = nums.BinarySearch(x);
            i = i < 0 ? -i - 2 : i - 1;
            j = j < 0 ? -j - 1 : j;
            int mi = i >= 0 && i < nums.Count ? nums[i] : -1;
            int mx = j >= 0 && j < nums.Count ? nums[j] : -1;
            ans.Add(new List<int> {mi, mx});
        }
        return ans;
    }

    private void Dfs(TreeNode root) {
        if (root == null) {
            return;
        }
        Dfs(root.left);
        nums.Add(root.val);
        Dfs(root.right);
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 <strong>二叉搜索树</strong> 的根节点 <code>root</code> ，和一个由正整数组成、长度为 <code>n</code> 的数组 <code>queries</code> 。</p>

<p>请你找出一个长度为 <code>n</code> 的 <strong>二维</strong> 答案数组 <code>answer</code> ，其中 <code>answer[i] = [min<sub>i</sub>, max<sub>i</sub>]</code> ：</p>

<ul>
	<li><code>min<sub>i</sub></code> 是树中小于等于&nbsp;<code>queries[i]</code> 的 <strong>最大值</strong> 。如果不存在这样的值，则使用 <code>-1</code> 代替。</li>
	<li><code>max<sub>i</sub></code> 是树中大于等于&nbsp;<code>queries[i]</code> 的 <strong>最小值</strong> 。如果不存在这样的值，则使用 <code>-1</code> 代替。</li>
</ul>

<p>返回数组 <code>answer</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1 ：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2400-2499/2476.Closest%20Nodes%20Queries%20in%20a%20Binary%20Search%20Tree/images/bstreeedrawioo.png" style="width: 261px; height: 281px;" /></p>

<pre>
<strong>输入：</strong>root = [6,2,13,1,4,9,15,null,null,null,null,null,null,14], queries = [2,5,16]
<strong>输出：</strong>[[2,2],[4,6],[15,-1]]
<strong>解释：</strong>按下面的描述找出并返回查询的答案：
- 树中小于等于 2 的最大值是 2 ，且大于等于 2 的最小值也是 2 。所以第一个查询的答案是 [2,2] 。
- 树中小于等于 5 的最大值是 4 ，且大于等于 5 的最小值是 6 。所以第二个查询的答案是 [4,6] 。
- 树中小于等于 16 的最大值是 15 ，且大于等于 16 的最小值不存在。所以第三个查询的答案是 [15,-1] 。
</pre>

<p><strong>示例 2 ：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2400-2499/2476.Closest%20Nodes%20Queries%20in%20a%20Binary%20Search%20Tree/images/bstttreee.png" style="width: 101px; height: 121px;" /></p>

<pre>
<strong>输入：</strong>root = [4,null,9], queries = [3]
<strong>输出：</strong>[[-1,4]]
<strong>解释：</strong>树中不存在小于等于 3 的最大值，且大于等于 3 的最小值是 4 。所以查询的答案是 [-1,4] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点的数目在范围 <code>[2, 10<sup>5</sup>]</code> 内</li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>6</sup></code></li>
	<li><code>n == queries.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= queries[i] &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：中序遍历 + 二分查找

由于题目中给出的是一棵二叉搜索树，因此我们可以通过中序遍历得到一个有序数组，然后对于每个查询，我们可以通过二分查找得到小于等于该查询值的最大值和大于等于该查询值的最小值。

时间复杂度 $O(n + m \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 和 $m$ 分别是二叉搜索树中的节点数和查询数。

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
    def closestNodes(
        self, root: Optional[TreeNode], queries: List[int]
    ) -> List[List[int]]:
        def dfs(root: Optional[TreeNode]):
            if root is None:
                return
            dfs(root.left)
            nums.append(root.val)
            dfs(root.right)

        nums = []
        dfs(root)
        ans = []
        for x in queries:
            i = bisect_left(nums, x + 1) - 1
            j = bisect_left(nums, x)
            mi = nums[i] if 0 <= i < len(nums) else -1
            mx = nums[j] if 0 <= j < len(nums) else -1
            ans.append([mi, mx])
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
    private List<Integer> nums = new ArrayList<>();

    public List<List<Integer>> closestNodes(TreeNode root, List<Integer> queries) {
        dfs(root);
        List<List<Integer>> ans = new ArrayList<>();
        for (int x : queries) {
            int i = Collections.binarySearch(nums, x + 1);
            int j = Collections.binarySearch(nums, x);
            i = i < 0 ? -i - 2 : i - 1;
            j = j < 0 ? -j - 1 : j;
            int mi = i >= 0 && i < nums.size() ? nums.get(i) : -1;
            int mx = j >= 0 && j < nums.size() ? nums.get(j) : -1;
            ans.add(List.of(mi, mx));
        }
        return ans;
    }

    private void dfs(TreeNode root) {
        if (root == null) {
            return;
        }
        dfs(root.left);
        nums.add(root.val);
        dfs(root.right);
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
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> nums;
        function<void(TreeNode*)> dfs = [&](TreeNode* root) {
            if (!root) {
                return;
            }
            dfs(root->left);
            nums.push_back(root->val);
            dfs(root->right);
        };
        dfs(root);
        vector<vector<int>> ans;
        int n = nums.size();
        for (int& x : queries) {
            int i = lower_bound(nums.begin(), nums.end(), x + 1) - nums.begin() - 1;
            int j = lower_bound(nums.begin(), nums.end(), x) - nums.begin();
            int mi = i >= 0 && i < n ? nums[i] : -1;
            int mx = j >= 0 && j < n ? nums[j] : -1;
            ans.push_back({mi, mx});
        }
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
func closestNodes(root *TreeNode, queries []int) (ans [][]int) {
	nums := []int{}
	var dfs func(*TreeNode)
	dfs = func(root *TreeNode) {
		if root == nil {
			return
		}
		dfs(root.Left)
		nums = append(nums, root.Val)
		dfs(root.Right)
	}
	dfs(root)
	for _, x := range queries {
		i := sort.SearchInts(nums, x+1) - 1
		j := sort.SearchInts(nums, x)
		mi, mx := -1, -1
		if i >= 0 {
			mi = nums[i]
		}
		if j < len(nums) {
			mx = nums[j]
		}
		ans = append(ans, []int{mi, mx})
	}
	return
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

function closestNodes(root: TreeNode | null, queries: number[]): number[][] {
    const nums: number[] = [];
    const dfs = (root: TreeNode | null) => {
        if (!root) {
            return;
        }
        dfs(root.left);
        nums.push(root.val);
        dfs(root.right);
    };
    const search = (x: number): number => {
        let [l, r] = [0, nums.length];
        while (l < r) {
            const mid = (l + r) >> 1;
            if (nums[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };
    dfs(root);
    const ans: number[][] = [];
    for (const x of queries) {
        const i = search(x + 1) - 1;
        const j = search(x);
        const mi = i >= 0 ? nums[i] : -1;
        const mx = j < nums.length ? nums[j] : -1;
        ans.push([mi, mx]);
    }
    return ans;
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
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    private List<int> nums = new List<int>();

    public IList<IList<int>> ClosestNodes(TreeNode root, IList<int> queries) {
        Dfs(root);
        List<IList<int>> ans = new List<IList<int>>();
        foreach (int x in queries) {
            int i = nums.BinarySearch(x + 1);
            int j = nums.BinarySearch(x);
            i = i < 0 ? -i - 2 : i - 1;
            j = j < 0 ? -j - 1 : j;
            int mi = i >= 0 && i < nums.Count ? nums[i] : -1;
            int mx = j >= 0 && j < nums.Count ? nums[j] : -1;
            ans.Add(new List<int> {mi, mx});
        }
        return ans;
    }

    private void Dfs(TreeNode root) {
        if (root == null) {
            return;
        }
        Dfs(root.left);
        nums.Add(root.val);
        Dfs(root.right);
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2477. 到达首都的最少油耗](https://leetcode.cn/problems/minimum-fuel-cost-to-report-to-the-capital){#2477}

{{< tabs "2477" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumFuelCost(self, roads: List[List[int]], seats: int) -> int:
        def dfs(a: int, fa: int) -> int:
            nonlocal ans
            sz = 1
            for b in g[a]:
                if b != fa:
                    t = dfs(b, a)
                    ans += ceil(t / seats)
                    sz += t
            return sz

        g = defaultdict(list)
        for a, b in roads:
            g[a].append(b)
            g[b].append(a)
        ans = 0
        dfs(0, -1)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private List<Integer>[] g;
    private int seats;
    private long ans;

    public long minimumFuelCost(int[][] roads, int seats) {
        int n = roads.length + 1;
        g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        this.seats = seats;
        for (var e : roads) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        dfs(0, -1);
        return ans;
    }

    private int dfs(int a, int fa) {
        int sz = 1;
        for (int b : g[a]) {
            if (b != fa) {
                int t = dfs(b, a);
                ans += (t + seats - 1) / seats;
                sz += t;
            }
        }
        return sz;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<int> g[n];
        for (auto& e : roads) {
            int a = e[0], b = e[1];
            g[a].emplace_back(b);
            g[b].emplace_back(a);
        }
        long long ans = 0;
        function<int(int, int)> dfs = [&](int a, int fa) {
            int sz = 1;
            for (int b : g[a]) {
                if (b != fa) {
                    int t = dfs(b, a);
                    ans += (t + seats - 1) / seats;
                    sz += t;
                }
            }
            return sz;
        };
        dfs(0, -1);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumFuelCost(roads [][]int, seats int) (ans int64) {
	n := len(roads) + 1
	g := make([][]int, n)
	for _, e := range roads {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	var dfs func(int, int) int
	dfs = func(a, fa int) int {
		sz := 1
		for _, b := range g[a] {
			if b != fa {
				t := dfs(b, a)
				ans += int64((t + seats - 1) / seats)
				sz += t
			}
		}
		return sz
	}
	dfs(0, -1)
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumFuelCost(roads: number[][], seats: number): number {
    const n = roads.length + 1;
    const g: number[][] = Array.from({ length: n }, () => []);
    for (const [a, b] of roads) {
        g[a].push(b);
        g[b].push(a);
    }
    let ans = 0;
    const dfs = (a: number, fa: number): number => {
        let sz = 1;
        for (const b of g[a]) {
            if (b !== fa) {
                const t = dfs(b, a);
                ans += Math.ceil(t / seats);
                sz += t;
            }
        }
        return sz;
    };
    dfs(0, -1);
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn minimum_fuel_cost(roads: Vec<Vec<i32>>, seats: i32) -> i64 {
        let n = roads.len() + 1;
        let mut g: Vec<Vec<usize>> = vec![vec![]; n];
        for road in roads.iter() {
            let a = road[0] as usize;
            let b = road[1] as usize;
            g[a].push(b);
            g[b].push(a);
        }
        let mut ans = 0;
        fn dfs(a: usize, fa: i32, g: &Vec<Vec<usize>>, ans: &mut i64, seats: i32) -> i32 {
            let mut sz = 1;
            for &b in g[a].iter() {
                if (b as i32) != fa {
                    let t = dfs(b, a as i32, g, ans, seats);
                    *ans += ((t + seats - 1) / seats) as i64;
                    sz += t;
                }
            }
            sz
        }
        dfs(0, -1, &g, &mut ans, seats);
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

<p>给你一棵 <code>n</code>&nbsp;个节点的树（一个无向、连通、无环图），每个节点表示一个城市，编号从&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n - 1</code>&nbsp;，且恰好有&nbsp;<code>n - 1</code>&nbsp;条路。<code>0</code>&nbsp;是首都。给你一个二维整数数组&nbsp;<code>roads</code>&nbsp;，其中&nbsp;<code>roads[i] = [a<sub>i</sub>, b<sub>i</sub>]</code>&nbsp;，表示城市&nbsp;<code>a<sub>i</sub></code> 和&nbsp;<code>b<sub>i</sub></code>&nbsp;之间有一条&nbsp;<strong>双向路</strong>&nbsp;。</p>

<p>每个城市里有一个代表，他们都要去首都参加一个会议。</p>

<p>每座城市里有一辆车。给你一个整数&nbsp;<code>seats</code>&nbsp;表示每辆车里面座位的数目。</p>

<p>城市里的代表可以选择乘坐所在城市的车，或者乘坐其他城市的车。相邻城市之间一辆车的油耗是一升汽油。</p>

<p>请你返回到达首都最少需要多少升汽油。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2400-2499/2477.Minimum%20Fuel%20Cost%20to%20Report%20to%20the%20Capital/images/a4c380025e3ff0c379525e96a7d63a3.png" style="width: 303px; height: 332px;"></p>

<pre><b>输入：</b>roads = [[0,1],[0,2],[0,3]], seats = 5
<b>输出：</b>3
<b>解释：</b>
- 代表 1 直接到达首都，消耗 1 升汽油。
- 代表 2 直接到达首都，消耗 1 升汽油。
- 代表 3 直接到达首都，消耗 1 升汽油。
最少消耗 3 升汽油。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2400-2499/2477.Minimum%20Fuel%20Cost%20to%20Report%20to%20the%20Capital/images/2.png" style="width: 274px; height: 340px;"></p>

<pre><b>输入：</b>roads = [[3,1],[3,2],[1,0],[0,4],[0,5],[4,6]], seats = 2
<b>输出：</b>7
<b>解释：</b>
- 代表 2 到达城市 3 ，消耗 1 升汽油。
- 代表 2 和代表 3 一起到达城市 1 ，消耗 1 升汽油。
- 代表 2 和代表 3 一起到达首都，消耗 1 升汽油。
- 代表 1 直接到达首都，消耗 1 升汽油。
- 代表 5 直接到达首都，消耗 1 升汽油。
- 代表 6 到达城市 4 ，消耗 1 升汽油。
- 代表 4 和代表 6 一起到达首都，消耗 1 升汽油。
最少消耗 7 升汽油。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2400-2499/2477.Minimum%20Fuel%20Cost%20to%20Report%20to%20the%20Capital/images/efcf7f7be6830b8763639cfd01b690a.png" style="width: 108px; height: 86px;"></p>

<pre><b>输入：</b>roads = [], seats = 1
<b>输出：</b>0
<b>解释：</b>没有代表需要从别的城市到达首都。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>roads.length == n - 1</code></li>
	<li><code>roads[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; n</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li><code>roads</code>&nbsp;表示一棵合法的树。</li>
	<li><code>1 &lt;= seats &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + DFS

根据题目描述，我们可以发现，所有车只会往首都（节点 $0$）开。

假设有一个节点 $a$，它的下一个节点为 $b$，节点 $a$ 需要经过节点 $b$ 才能到达首都。为了使得节点 $a$ 的车辆（油耗）尽可能少，我们应该贪心地让节点 $a$ 的子节点先汇聚到节点 $a$，然后按照座位数 $seats$ 分配车辆，那么到达节点 $b$ 需要的最少车辆（油耗）就是 $\lceil \frac{sz}{seats} \rceil$。其中 $sz$ 表示以节点 $a$ 为根的子树的节点数。

我们从节点 $0$ 开始进行深度优先搜索，用一个变量 $sz$ 统计以当前节点为根节点的子树的节点数。初始时 $sz = 1$，表示当前节点本身。然后我们遍历当前节点的所有子节点，对于每个子节点 $b$，我们递归地计算以 $b$ 为根节点的子树的节点数 $t$，并将 $t$ 累加到 $sz$ 上，然后我们将 $\lceil \frac{t}{seats} \rceil$ 累加到答案上。最后返回 $sz$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为节点数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumFuelCost(self, roads: List[List[int]], seats: int) -> int:
        def dfs(a: int, fa: int) -> int:
            nonlocal ans
            sz = 1
            for b in g[a]:
                if b != fa:
                    t = dfs(b, a)
                    ans += ceil(t / seats)
                    sz += t
            return sz

        g = defaultdict(list)
        for a, b in roads:
            g[a].append(b)
            g[b].append(a)
        ans = 0
        dfs(0, -1)
        return ans
```

#### Java

```java
class Solution {
    private List<Integer>[] g;
    private int seats;
    private long ans;

    public long minimumFuelCost(int[][] roads, int seats) {
        int n = roads.length + 1;
        g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        this.seats = seats;
        for (var e : roads) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        dfs(0, -1);
        return ans;
    }

    private int dfs(int a, int fa) {
        int sz = 1;
        for (int b : g[a]) {
            if (b != fa) {
                int t = dfs(b, a);
                ans += (t + seats - 1) / seats;
                sz += t;
            }
        }
        return sz;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<int> g[n];
        for (auto& e : roads) {
            int a = e[0], b = e[1];
            g[a].emplace_back(b);
            g[b].emplace_back(a);
        }
        long long ans = 0;
        function<int(int, int)> dfs = [&](int a, int fa) {
            int sz = 1;
            for (int b : g[a]) {
                if (b != fa) {
                    int t = dfs(b, a);
                    ans += (t + seats - 1) / seats;
                    sz += t;
                }
            }
            return sz;
        };
        dfs(0, -1);
        return ans;
    }
};
```

#### Go

```go
func minimumFuelCost(roads [][]int, seats int) (ans int64) {
	n := len(roads) + 1
	g := make([][]int, n)
	for _, e := range roads {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	var dfs func(int, int) int
	dfs = func(a, fa int) int {
		sz := 1
		for _, b := range g[a] {
			if b != fa {
				t := dfs(b, a)
				ans += int64((t + seats - 1) / seats)
				sz += t
			}
		}
		return sz
	}
	dfs(0, -1)
	return
}
```

#### TypeScript

```ts
function minimumFuelCost(roads: number[][], seats: number): number {
    const n = roads.length + 1;
    const g: number[][] = Array.from({ length: n }, () => []);
    for (const [a, b] of roads) {
        g[a].push(b);
        g[b].push(a);
    }
    let ans = 0;
    const dfs = (a: number, fa: number): number => {
        let sz = 1;
        for (const b of g[a]) {
            if (b !== fa) {
                const t = dfs(b, a);
                ans += Math.ceil(t / seats);
                sz += t;
            }
        }
        return sz;
    };
    dfs(0, -1);
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn minimum_fuel_cost(roads: Vec<Vec<i32>>, seats: i32) -> i64 {
        let n = roads.len() + 1;
        let mut g: Vec<Vec<usize>> = vec![vec![]; n];
        for road in roads.iter() {
            let a = road[0] as usize;
            let b = road[1] as usize;
            g[a].push(b);
            g[b].push(a);
        }
        let mut ans = 0;
        fn dfs(a: usize, fa: i32, g: &Vec<Vec<usize>>, ans: &mut i64, seats: i32) -> i32 {
            let mut sz = 1;
            for &b in g[a].iter() {
                if (b as i32) != fa {
                    let t = dfs(b, a as i32, g, ans, seats);
                    *ans += ((t + seats - 1) / seats) as i64;
                    sz += t;
                }
            }
            sz
        }
        dfs(0, -1, &g, &mut ans, seats);
        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2478. 完美分割的方案数](https://leetcode.cn/problems/number-of-beautiful-partitions){#2478}

{{< tabs "2478" >}}

{{% tab "python" %}}
```python
class Solution:
    def beautifulPartitions(self, s: str, k: int, minLength: int) -> int:
        primes = '2357'
        if s[0] not in primes or s[-1] in primes:
            return 0
        mod = 10**9 + 7
        n = len(s)
        f = [[0] * (k + 1) for _ in range(n + 1)]
        g = [[0] * (k + 1) for _ in range(n + 1)]
        f[0][0] = g[0][0] = 1
        for i, c in enumerate(s, 1):
            if i >= minLength and c not in primes and (i == n or s[i] in primes):
                for j in range(1, k + 1):
                    f[i][j] = g[i - minLength][j - 1]
            for j in range(k + 1):
                g[i][j] = (g[i - 1][j] + f[i][j]) % mod
        return f[n][k]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int beautifulPartitions(String s, int k, int minLength) {
        int n = s.length();
        if (!prime(s.charAt(0)) || prime(s.charAt(n - 1))) {
            return 0;
        }
        int[][] f = new int[n + 1][k + 1];
        int[][] g = new int[n + 1][k + 1];
        f[0][0] = 1;
        g[0][0] = 1;
        final int mod = (int) 1e9 + 7;
        for (int i = 1; i <= n; ++i) {
            if (i >= minLength && !prime(s.charAt(i - 1)) && (i == n || prime(s.charAt(i)))) {
                for (int j = 1; j <= k; ++j) {
                    f[i][j] = g[i - minLength][j - 1];
                }
            }
            for (int j = 0; j <= k; ++j) {
                g[i][j] = (g[i - 1][j] + f[i][j]) % mod;
            }
        }
        return f[n][k];
    }

    private boolean prime(char c) {
        return c == '2' || c == '3' || c == '5' || c == '7';
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int beautifulPartitions(string s, int k, int minLength) {
        int n = s.size();
        auto prime = [](char c) {
            return c == '2' || c == '3' || c == '5' || c == '7';
        };
        if (!prime(s[0]) || prime(s[n - 1])) return 0;
        vector<vector<int>> f(n + 1, vector<int>(k + 1));
        vector<vector<int>> g(n + 1, vector<int>(k + 1));
        f[0][0] = g[0][0] = 1;
        const int mod = 1e9 + 7;
        for (int i = 1; i <= n; ++i) {
            if (i >= minLength && !prime(s[i - 1]) && (i == n || prime(s[i]))) {
                for (int j = 1; j <= k; ++j) {
                    f[i][j] = g[i - minLength][j - 1];
                }
            }
            for (int j = 0; j <= k; ++j) {
                g[i][j] = (g[i - 1][j] + f[i][j]) % mod;
            }
        }
        return f[n][k];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func beautifulPartitions(s string, k int, minLength int) int {
	prime := func(c byte) bool {
		return c == '2' || c == '3' || c == '5' || c == '7'
	}
	n := len(s)
	if !prime(s[0]) || prime(s[n-1]) {
		return 0
	}
	const mod int = 1e9 + 7
	f := make([][]int, n+1)
	g := make([][]int, n+1)
	for i := range f {
		f[i] = make([]int, k+1)
		g[i] = make([]int, k+1)
	}
	f[0][0], g[0][0] = 1, 1
	for i := 1; i <= n; i++ {
		if i >= minLength && !prime(s[i-1]) && (i == n || prime(s[i])) {
			for j := 1; j <= k; j++ {
				f[i][j] = g[i-minLength][j-1]
			}
		}
		for j := 0; j <= k; j++ {
			g[i][j] = (g[i-1][j] + f[i][j]) % mod
		}
	}
	return f[n][k]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function beautifulPartitions(s: string, k: number, minLength: number): number {
    const prime = (c: string): boolean => {
        return c === '2' || c === '3' || c === '5' || c === '7';
    };

    const n: number = s.length;
    if (!prime(s[0]) || prime(s[n - 1])) return 0;

    const f: number[][] = new Array(n + 1).fill(0).map(() => new Array(k + 1).fill(0));
    const g: number[][] = new Array(n + 1).fill(0).map(() => new Array(k + 1).fill(0));
    const mod: number = 1e9 + 7;

    f[0][0] = g[0][0] = 1;

    for (let i = 1; i <= n; ++i) {
        if (i >= minLength && !prime(s[i - 1]) && (i === n || prime(s[i]))) {
            for (let j = 1; j <= k; ++j) {
                f[i][j] = g[i - minLength][j - 1];
            }
        }
        for (let j = 0; j <= k; ++j) {
            g[i][j] = (g[i - 1][j] + f[i][j]) % mod;
        }
    }

    return f[n][k];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串&nbsp;<code>s</code>&nbsp;，每个字符是数字&nbsp;<code>'1'</code>&nbsp;到&nbsp;<code>'9'</code>&nbsp;，再给你两个整数&nbsp;<code>k</code> 和&nbsp;<code>minLength</code>&nbsp;。</p>

<p>如果对 <code>s</code>&nbsp;的分割满足以下条件，那么我们认为它是一个 <strong>完美</strong>&nbsp;分割：</p>

<ul>
	<li><code>s</code>&nbsp;被分成 <code>k</code>&nbsp;段互不相交的子字符串。</li>
	<li>每个子字符串长度都 <strong>至少</strong>&nbsp;为&nbsp;<code>minLength</code>&nbsp;。</li>
	<li>每个子字符串的第一个字符都是一个 <b>质数</b> 数字，最后一个字符都是一个 <strong>非质数</strong>&nbsp;数字。质数数字为&nbsp;<code>'2'</code>&nbsp;，<code>'3'</code>&nbsp;，<code>'5'</code>&nbsp;和&nbsp;<code>'7'</code>&nbsp;，剩下的都是非质数数字。</li>
</ul>

<p>请你返回 <code>s</code>&nbsp;的 <strong>完美</strong>&nbsp;分割数目。由于答案可能很大，请返回答案对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;<strong>取余</strong>&nbsp;后的结果。</p>

<p>一个 <strong>子字符串</strong>&nbsp;是字符串中一段连续字符串序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>s = "23542185131", k = 3, minLength = 2
<b>输出：</b>3
<b>解释：</b>存在 3 种完美分割方案：
"2354 | 218 | 5131"
"2354 | 21851 | 31"
"2354218 | 51 | 31"
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>s = "23542185131", k = 3, minLength = 3
<b>输出：</b>1
<b>解释：</b>存在一种完美分割方案："2354 | 218 | 5131" 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>s = "3312958", k = 3, minLength = 1
<b>输出：</b>1
<b>解释：</b>存在一种完美分割方案："331 | 29 | 58" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k, minLength &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code>&nbsp;每个字符都为数字&nbsp;<code>'1'</code>&nbsp;到&nbsp;<code>'9'</code> 之一。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示前 $i$ 个字符分割成 $j$ 段的方案数。初始化 $f[0][0] = 1$，其余 $f[i][j] = 0$。

首先，我们需要判断第 $i$ 个字符是否能成为第 $j$ 段的最后一个字符，它需要同时满足以下条件：

1. 第 $i$ 个字符是一个非质数；
1. 第 $i+1$ 个字符是一个质数，或者第 $i$ 个字符是整个字符串的最后一个字符。

如果第 $i$ 个字符不能成为第 $j$ 段的最后一个字符，那么 $f[i][j]=0$。否则有：

$$
f[i][j]=\sum_{t=0}^{i-minLength}f[t][j-1]
$$

也就是说，我们要枚举上一段的结尾是哪个字符。这里我们用前缀和数组 $g[i][j] = \sum_{t=0}^{i}f[t][j]$ 来优化枚举的时间复杂度。

那么有：

$$
f[i][j]=g[i-minLength][j-1]
$$

时间复杂度 $O(n \times k)$，空间复杂度 $O(n \times k)$。其中 $n$ 和 $k$ 分别是字符串 $s$ 的长度和分割的段数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def beautifulPartitions(self, s: str, k: int, minLength: int) -> int:
        primes = '2357'
        if s[0] not in primes or s[-1] in primes:
            return 0
        mod = 10**9 + 7
        n = len(s)
        f = [[0] * (k + 1) for _ in range(n + 1)]
        g = [[0] * (k + 1) for _ in range(n + 1)]
        f[0][0] = g[0][0] = 1
        for i, c in enumerate(s, 1):
            if i >= minLength and c not in primes and (i == n or s[i] in primes):
                for j in range(1, k + 1):
                    f[i][j] = g[i - minLength][j - 1]
            for j in range(k + 1):
                g[i][j] = (g[i - 1][j] + f[i][j]) % mod
        return f[n][k]
```

#### Java

```java
class Solution {
    public int beautifulPartitions(String s, int k, int minLength) {
        int n = s.length();
        if (!prime(s.charAt(0)) || prime(s.charAt(n - 1))) {
            return 0;
        }
        int[][] f = new int[n + 1][k + 1];
        int[][] g = new int[n + 1][k + 1];
        f[0][0] = 1;
        g[0][0] = 1;
        final int mod = (int) 1e9 + 7;
        for (int i = 1; i <= n; ++i) {
            if (i >= minLength && !prime(s.charAt(i - 1)) && (i == n || prime(s.charAt(i)))) {
                for (int j = 1; j <= k; ++j) {
                    f[i][j] = g[i - minLength][j - 1];
                }
            }
            for (int j = 0; j <= k; ++j) {
                g[i][j] = (g[i - 1][j] + f[i][j]) % mod;
            }
        }
        return f[n][k];
    }

    private boolean prime(char c) {
        return c == '2' || c == '3' || c == '5' || c == '7';
    }
}
```

#### C++

```cpp
class Solution {
public:
    int beautifulPartitions(string s, int k, int minLength) {
        int n = s.size();
        auto prime = [](char c) {
            return c == '2' || c == '3' || c == '5' || c == '7';
        };
        if (!prime(s[0]) || prime(s[n - 1])) return 0;
        vector<vector<int>> f(n + 1, vector<int>(k + 1));
        vector<vector<int>> g(n + 1, vector<int>(k + 1));
        f[0][0] = g[0][0] = 1;
        const int mod = 1e9 + 7;
        for (int i = 1; i <= n; ++i) {
            if (i >= minLength && !prime(s[i - 1]) && (i == n || prime(s[i]))) {
                for (int j = 1; j <= k; ++j) {
                    f[i][j] = g[i - minLength][j - 1];
                }
            }
            for (int j = 0; j <= k; ++j) {
                g[i][j] = (g[i - 1][j] + f[i][j]) % mod;
            }
        }
        return f[n][k];
    }
};
```

#### Go

```go
func beautifulPartitions(s string, k int, minLength int) int {
	prime := func(c byte) bool {
		return c == '2' || c == '3' || c == '5' || c == '7'
	}
	n := len(s)
	if !prime(s[0]) || prime(s[n-1]) {
		return 0
	}
	const mod int = 1e9 + 7
	f := make([][]int, n+1)
	g := make([][]int, n+1)
	for i := range f {
		f[i] = make([]int, k+1)
		g[i] = make([]int, k+1)
	}
	f[0][0], g[0][0] = 1, 1
	for i := 1; i <= n; i++ {
		if i >= minLength && !prime(s[i-1]) && (i == n || prime(s[i])) {
			for j := 1; j <= k; j++ {
				f[i][j] = g[i-minLength][j-1]
			}
		}
		for j := 0; j <= k; j++ {
			g[i][j] = (g[i-1][j] + f[i][j]) % mod
		}
	}
	return f[n][k]
}
```

#### TypeScript

```ts
function beautifulPartitions(s: string, k: number, minLength: number): number {
    const prime = (c: string): boolean => {
        return c === '2' || c === '3' || c === '5' || c === '7';
    };

    const n: number = s.length;
    if (!prime(s[0]) || prime(s[n - 1])) return 0;

    const f: number[][] = new Array(n + 1).fill(0).map(() => new Array(k + 1).fill(0));
    const g: number[][] = new Array(n + 1).fill(0).map(() => new Array(k + 1).fill(0));
    const mod: number = 1e9 + 7;

    f[0][0] = g[0][0] = 1;

    for (let i = 1; i <= n; ++i) {
        if (i >= minLength && !prime(s[i - 1]) && (i === n || prime(s[i]))) {
            for (let j = 1; j <= k; ++j) {
                f[i][j] = g[i - minLength][j - 1];
            }
        }
        for (let j = 0; j <= k; ++j) {
            g[i][j] = (g[i - 1][j] + f[i][j]) % mod;
        }
    }

    return f[n][k];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2479. 两个不重叠子树的最大异或值 🔒](https://leetcode.cn/problems/maximum-xor-of-two-non-overlapping-subtrees){#2479}

{{< tabs "2479" >}}

{{% tab "python" %}}
```python
class Trie:
    def __init__(self):
        self.children = [None] * 2

    def insert(self, x):
        node = self
        for i in range(47, -1, -1):
            v = (x >> i) & 1
            if node.children[v] is None:
                node.children[v] = Trie()
            node = node.children[v]

    def search(self, x):
        node = self
        res = 0
        for i in range(47, -1, -1):
            v = (x >> i) & 1
            if node is None:
                return res
            if node.children[v ^ 1]:
                res = res << 1 | 1
                node = node.children[v ^ 1]
            else:
                res <<= 1
                node = node.children[v]
        return res


class Solution:
    def maxXor(self, n: int, edges: List[List[int]], values: List[int]) -> int:
        def dfs1(i, fa):
            t = values[i]
            for j in g[i]:
                if j != fa:
                    t += dfs1(j, i)
            s[i] = t
            return t

        def dfs2(i, fa):
            nonlocal ans
            ans = max(ans, tree.search(s[i]))
            for j in g[i]:
                if j != fa:
                    dfs2(j, i)
            tree.insert(s[i])

        g = defaultdict(list)
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
        s = [0] * n
        dfs1(0, -1)
        ans = 0
        tree = Trie()
        dfs2(0, -1)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Trie {
    Trie[] children = new Trie[2];

    void insert(long x) {
        Trie node = this;
        for (int i = 47; i >= 0; --i) {
            int v = (int) (x >> i) & 1;
            if (node.children[v] == null) {
                node.children[v] = new Trie();
            }
            node = node.children[v];
        }
    }

    long search(long x) {
        Trie node = this;
        long res = 0;
        for (int i = 47; i >= 0; --i) {
            int v = (int) (x >> i) & 1;
            if (node == null) {
                return res;
            }
            if (node.children[v ^ 1] != null) {
                res = res << 1 | 1;
                node = node.children[v ^ 1];
            } else {
                res <<= 1;
                node = node.children[v];
            }
        }
        return res;
    }
}

class Solution {
    private List<Integer>[] g;
    private int[] vals;
    private long[] s;
    private Trie tree;
    private long ans;

    public long maxXor(int n, int[][] edges, int[] values) {
        g = new List[n];
        s = new long[n];
        vals = values;
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        dfs1(0, -1);
        tree = new Trie();
        dfs2(0, -1);
        return ans;
    }

    private void dfs2(int i, int fa) {
        ans = Math.max(ans, tree.search(s[i]));
        for (int j : g[i]) {
            if (j != fa) {
                dfs2(j, i);
            }
        }
        tree.insert(s[i]);
    }

    private long dfs1(int i, int fa) {
        long t = vals[i];
        for (int j : g[i]) {
            if (j != fa) {
                t += dfs1(j, i);
            }
        }
        s[i] = t;
        return t;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
using ll = long long;

class Trie {
public:
    vector<Trie*> children;
    string v;
    Trie()
        : children(2) {}

    void insert(ll x) {
        Trie* node = this;
        for (int i = 47; ~i; --i) {
            int v = (x >> i) & 1;
            if (!node->children[v]) node->children[v] = new Trie();
            node = node->children[v];
        }
    }

    ll search(ll x) {
        Trie* node = this;
        ll res = 0;
        for (int i = 47; ~i; --i) {
            if (!node) return res;
            int v = (x >> i) & 1;
            if (node->children[v ^ 1]) {
                res = res << 1 | 1;
                node = node->children[v ^ 1];
            } else {
                res <<= 1;
                node = node->children[v];
            }
        }
        return res;
    }
};

class Solution {
public:
    long long maxXor(int n, vector<vector<int>>& edges, vector<int>& values) {
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].emplace_back(b);
            g[b].emplace_back(a);
        }
        vector<ll> s(n);
        function<ll(int, int)> dfs1 = [&](int i, int fa) -> ll {
            ll t = values[i];
            for (int j : g[i]) {
                if (j != fa) t += dfs1(j, i);
            }
            s[i] = t;
            return t;
        };
        dfs1(0, -1);
        Trie tree;
        ll ans = 0;
        function<void(int, int)> dfs2 = [&](int i, int fa) {
            ans = max(ans, tree.search(s[i]));
            for (int j : g[i]) {
                if (j != fa) {
                    dfs2(j, i);
                }
            }
            tree.insert(s[i]);
        };
        dfs2(0, -1);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Trie struct {
	children [2]*Trie
}

func newTrie() *Trie {
	return &Trie{}
}

func (this *Trie) insert(x int) {
	node := this
	for i := 47; i >= 0; i-- {
		v := (x >> i) & 1
		if node.children[v] == nil {
			node.children[v] = newTrie()
		}
		node = node.children[v]
	}
}

func (this *Trie) search(x int) int {
	node := this
	res := 0
	for i := 47; i >= 0; i-- {
		v := (x >> i) & 1
		if node == nil {
			return res
		}
		if node.children[v^1] != nil {
			res = res<<1 | 1
			node = node.children[v^1]
		} else {
			res <<= 1
			node = node.children[v]
		}
	}
	return res
}

func maxXor(n int, edges [][]int, values []int) int64 {
	g := make([][]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	s := make([]int, n)
	var dfs1 func(i, fa int) int
	dfs1 = func(i, fa int) int {
		t := values[i]
		for _, j := range g[i] {
			if j != fa {
				t += dfs1(j, i)
			}
		}
		s[i] = t
		return t
	}
	dfs1(0, -1)
	ans := 0
	tree := newTrie()
	var dfs2 func(i, fa int)
	dfs2 = func(i, fa int) {
		ans = max(ans, tree.search(s[i]))
		for _, j := range g[i] {
			if j != fa {
				dfs2(j, i)
			}
		}
		tree.insert(s[i])
	}
	dfs2(0, -1)
	return int64(ans)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有一个无向树，有 <code>n</code> 个节点，节点标记为从 <code>0</code> 到 <code>n - 1</code>。给定整数 <code>n</code> 和一个长度为 <code>n - 1</code> 的 2 维整数数组 <code>edges</code>，其中 <code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> 表示在树中的节点 <code>a<sub>i</sub></code> 和 <code>b<sub>i</sub></code> 之间有一条边。树的根节点是标记为 <code>0</code> 的节点。</p>

<p data-group="1-1">每个节点都有一个相关联的 <strong>值</strong>。给定一个长度为 n 的数组 <code>values</code>，其中 <code>values[i]</code> 是第 <code>i</code> 个节点的&nbsp;<strong>值</strong>。</p>

<p>选择任意两个&nbsp;<strong>不重叠&nbsp;</strong>的子树。你的&nbsp;<strong>分数&nbsp;</strong>是这些子树中值的和的逐位异或。</p>

<p>返回<em>你能达到的最大分数</em>。<em>如果不可能找到两个不重叠的子树</em>，则返回 <code>0</code>。</p>

<p><strong>注意</strong>：</p>

<ul>
	<li>节点的&nbsp;<strong>子树&nbsp;</strong>是由该节点及其所有子节点组成的树。</li>
	<li>如果两个子树不共享&nbsp;<strong>任何公共&nbsp;</strong>节点，则它们是&nbsp;<strong>不重叠&nbsp;</strong>的。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2400-2499/2479.Maximum%20XOR%20of%20Two%20Non-Overlapping%20Subtrees/images/treemaxxor.png" style="width: 346px; height: 249px;" />
<pre>
<strong>输入:</strong> n = 6, edges = [[0,1],[0,2],[1,3],[1,4],[2,5]], values = [2,8,3,6,2,5]
<strong>输出:</strong> 24
<strong>解释:</strong> 节点 1 的子树的和值为 16，而节点 2 的子树的和值为 8，因此选择这些节点将得到 16 XOR 8 = 24 的分数。可以证明，这是我们能得到的最大可能分数。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2400-2499/2479.Maximum%20XOR%20of%20Two%20Non-Overlapping%20Subtrees/images/tree3drawio.png" style="width: 240px; height: 261px;" />
<pre>
<strong>输入:</strong> n = 3, edges = [[0,1],[1,2]], values = [4,6,1]
<strong>输出:</strong> 0
<strong>解释:</strong> 不可能选择两个不重叠的子树，所以我们只返回 0。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; n</code></li>
	<li><code>values.length == n</code></li>
	<li><code>1 &lt;= values[i] &lt;= 10<sup>9</sup></code></li>
	<li>保证 <code>edges</code> 代表一个有效的树。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归 + 0-1 前缀树

我们先递归预处理出每个节点的子树和，记录在数组 $s$ 中。

然后使用 0-1 前缀树维护遍历过的子树和，可以方便快速查找下一个子树和与之前的子树和的最大异或值。

由于子树不能重叠，因此，我们先查询最大异或值，递归结束后，再将当前子树和插入到前缀树中。

时间复杂度 $O(n \times log M)$，其中 $n$ 为节点个数，而 $M$ 为子树和的最大值。

<!-- tabs:start -->

#### Python3

```python
class Trie:
    def __init__(self):
        self.children = [None] * 2

    def insert(self, x):
        node = self
        for i in range(47, -1, -1):
            v = (x >> i) & 1
            if node.children[v] is None:
                node.children[v] = Trie()
            node = node.children[v]

    def search(self, x):
        node = self
        res = 0
        for i in range(47, -1, -1):
            v = (x >> i) & 1
            if node is None:
                return res
            if node.children[v ^ 1]:
                res = res << 1 | 1
                node = node.children[v ^ 1]
            else:
                res <<= 1
                node = node.children[v]
        return res


class Solution:
    def maxXor(self, n: int, edges: List[List[int]], values: List[int]) -> int:
        def dfs1(i, fa):
            t = values[i]
            for j in g[i]:
                if j != fa:
                    t += dfs1(j, i)
            s[i] = t
            return t

        def dfs2(i, fa):
            nonlocal ans
            ans = max(ans, tree.search(s[i]))
            for j in g[i]:
                if j != fa:
                    dfs2(j, i)
            tree.insert(s[i])

        g = defaultdict(list)
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
        s = [0] * n
        dfs1(0, -1)
        ans = 0
        tree = Trie()
        dfs2(0, -1)
        return ans
```

#### Java

```java
class Trie {
    Trie[] children = new Trie[2];

    void insert(long x) {
        Trie node = this;
        for (int i = 47; i >= 0; --i) {
            int v = (int) (x >> i) & 1;
            if (node.children[v] == null) {
                node.children[v] = new Trie();
            }
            node = node.children[v];
        }
    }

    long search(long x) {
        Trie node = this;
        long res = 0;
        for (int i = 47; i >= 0; --i) {
            int v = (int) (x >> i) & 1;
            if (node == null) {
                return res;
            }
            if (node.children[v ^ 1] != null) {
                res = res << 1 | 1;
                node = node.children[v ^ 1];
            } else {
                res <<= 1;
                node = node.children[v];
            }
        }
        return res;
    }
}

class Solution {
    private List<Integer>[] g;
    private int[] vals;
    private long[] s;
    private Trie tree;
    private long ans;

    public long maxXor(int n, int[][] edges, int[] values) {
        g = new List[n];
        s = new long[n];
        vals = values;
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        dfs1(0, -1);
        tree = new Trie();
        dfs2(0, -1);
        return ans;
    }

    private void dfs2(int i, int fa) {
        ans = Math.max(ans, tree.search(s[i]));
        for (int j : g[i]) {
            if (j != fa) {
                dfs2(j, i);
            }
        }
        tree.insert(s[i]);
    }

    private long dfs1(int i, int fa) {
        long t = vals[i];
        for (int j : g[i]) {
            if (j != fa) {
                t += dfs1(j, i);
            }
        }
        s[i] = t;
        return t;
    }
}
```

#### C++

```cpp
using ll = long long;

class Trie {
public:
    vector<Trie*> children;
    string v;
    Trie()
        : children(2) {}

    void insert(ll x) {
        Trie* node = this;
        for (int i = 47; ~i; --i) {
            int v = (x >> i) & 1;
            if (!node->children[v]) node->children[v] = new Trie();
            node = node->children[v];
        }
    }

    ll search(ll x) {
        Trie* node = this;
        ll res = 0;
        for (int i = 47; ~i; --i) {
            if (!node) return res;
            int v = (x >> i) & 1;
            if (node->children[v ^ 1]) {
                res = res << 1 | 1;
                node = node->children[v ^ 1];
            } else {
                res <<= 1;
                node = node->children[v];
            }
        }
        return res;
    }
};

class Solution {
public:
    long long maxXor(int n, vector<vector<int>>& edges, vector<int>& values) {
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].emplace_back(b);
            g[b].emplace_back(a);
        }
        vector<ll> s(n);
        function<ll(int, int)> dfs1 = [&](int i, int fa) -> ll {
            ll t = values[i];
            for (int j : g[i]) {
                if (j != fa) t += dfs1(j, i);
            }
            s[i] = t;
            return t;
        };
        dfs1(0, -1);
        Trie tree;
        ll ans = 0;
        function<void(int, int)> dfs2 = [&](int i, int fa) {
            ans = max(ans, tree.search(s[i]));
            for (int j : g[i]) {
                if (j != fa) {
                    dfs2(j, i);
                }
            }
            tree.insert(s[i]);
        };
        dfs2(0, -1);
        return ans;
    }
};
```

#### Go

```go
type Trie struct {
	children [2]*Trie
}

func newTrie() *Trie {
	return &Trie{}
}

func (this *Trie) insert(x int) {
	node := this
	for i := 47; i >= 0; i-- {
		v := (x >> i) & 1
		if node.children[v] == nil {
			node.children[v] = newTrie()
		}
		node = node.children[v]
	}
}

func (this *Trie) search(x int) int {
	node := this
	res := 0
	for i := 47; i >= 0; i-- {
		v := (x >> i) & 1
		if node == nil {
			return res
		}
		if node.children[v^1] != nil {
			res = res<<1 | 1
			node = node.children[v^1]
		} else {
			res <<= 1
			node = node.children[v]
		}
	}
	return res
}

func maxXor(n int, edges [][]int, values []int) int64 {
	g := make([][]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	s := make([]int, n)
	var dfs1 func(i, fa int) int
	dfs1 = func(i, fa int) int {
		t := values[i]
		for _, j := range g[i] {
			if j != fa {
				t += dfs1(j, i)
			}
		}
		s[i] = t
		return t
	}
	dfs1(0, -1)
	ans := 0
	tree := newTrie()
	var dfs2 func(i, fa int)
	dfs2 = func(i, fa int) {
		ans = max(ans, tree.search(s[i]))
		for _, j := range g[i] {
			if j != fa {
				dfs2(j, i)
			}
		}
		tree.insert(s[i])
	}
	dfs2(0, -1)
	return int64(ans)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
