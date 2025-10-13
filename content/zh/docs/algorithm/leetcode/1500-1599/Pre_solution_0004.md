---
title: "1530_好叶子节点对的数量"
date: 2025-10-08T18:37:33+08:00
weight: 4
tags: [二分查找, 二叉树, 交互, 动态规划, 双指针, 字符串, 数学, 数据库, 数组, 枚举, 树, 模拟, 深度优先搜索, 矩阵, 贪心]
---

{{< markmap >}}
### [1530_好叶子节点对的数量](#1530)
#### [树](#1530)
#### [深度优先搜索](#1530)
#### [二叉树](#1530)
### [1531_压缩字符串 II](#1531)
#### [字符串](#1531)
#### [动态规划](#1531)
### [1532_最近的三笔订单 🔒](#1532)
#### [数据库](#1532)
### [1533_找到最大整数的索引 🔒](#1533)
#### [数组](#1533)
#### [二分查找](#1533)
#### [交互](#1533)
### [1534_统计好三元组](#1534)
#### [数组](#1534)
#### [枚举](#1534)
### [1535_找出数组游戏的赢家](#1535)
#### [数组](#1535)
#### [模拟](#1535)
### [1536_排布二进制网格的最少交换次数](#1536)
#### [贪心](#1536)
#### [数组](#1536)
#### [矩阵](#1536)
### [1537_最大得分](#1537)
#### [贪心](#1537)
#### [数组](#1537)
#### [双指针](#1537)
#### [动态规划](#1537)
### [1538_找出隐藏数组中出现次数最多的元素 🔒](#1538)
#### [数组](#1538)
#### [数学](#1538)
#### [交互](#1538)
### [1539_第 k 个缺失的正整数](#1539)
#### [数组](#1539)
#### [二分查找](#1539)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1530_好叶子节点对的数量
___
#### 树
___
#### 深度优先搜索
___
#### 二叉树
---
### 1531_压缩字符串 II
___
#### 字符串
___
#### 动态规划
---
### 1532_最近的三笔订单 🔒
___
#### 数据库
---
### 1533_找到最大整数的索引 🔒
___
#### 数组
___
#### 二分查找
___
#### 交互
---
### 1534_统计好三元组
___
#### 数组
___
#### 枚举
---
### 1535_找出数组游戏的赢家
___
#### 数组
___
#### 模拟
---
### 1536_排布二进制网格的最少交换次数
___
#### 贪心
___
#### 数组
___
#### 矩阵
---
### 1537_最大得分
___
#### 贪心
___
#### 数组
___
#### 双指针
___
#### 动态规划
---
### 1538_找出隐藏数组中出现次数最多的元素 🔒
___
#### 数组
___
#### 数学
___
#### 交互
---
### 1539_第 k 个缺失的正整数
___
#### 数组
___
#### 二分查找
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉树 | 交互 |
| 动态规划 | 双指针 | 字符串 |
| 数学 | 数据库 | 数组 |
| 枚举 | 树 | 模拟 |
| 深度优先搜索 | 矩阵 | 贪心 |

# [1530. 好叶子节点对的数量](https://leetcode.cn/problems/number-of-good-leaf-nodes-pairs){#1530}

{{< tabs "1530" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countPairs(self, root: TreeNode, distance: int) -> int:
        def dfs(root, cnt, i):
            if root is None or i >= distance:
                return
            if root.left is None and root.right is None:
                cnt[i] += 1
                return
            dfs(root.left, cnt, i + 1)
            dfs(root.right, cnt, i + 1)

        if root is None:
            return 0
        ans = self.countPairs(root.left, distance) + self.countPairs(
            root.right, distance
        )
        cnt1 = Counter()
        cnt2 = Counter()
        dfs(root.left, cnt1, 1)
        dfs(root.right, cnt2, 1)

        for k1, v1 in cnt1.items():
            for k2, v2 in cnt2.items():
                if k1 + k2 <= distance:
                    ans += v1 * v2
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
    public int countPairs(TreeNode root, int distance) {
        if (root == null) {
            return 0;
        }
        int ans = countPairs(root.left, distance) + countPairs(root.right, distance);
        int[] cnt1 = new int[distance];
        int[] cnt2 = new int[distance];
        dfs(root.left, cnt1, 1);
        dfs(root.right, cnt2, 1);
        for (int i = 0; i < distance; ++i) {
            for (int j = 0; j < distance; ++j) {
                if (i + j <= distance) {
                    ans += cnt1[i] * cnt2[j];
                }
            }
        }
        return ans;
    }

    void dfs(TreeNode root, int[] cnt, int i) {
        if (root == null || i >= cnt.length) {
            return;
        }
        if (root.left == null && root.right == null) {
            ++cnt[i];
            return;
        }
        dfs(root.left, cnt, i + 1);
        dfs(root.right, cnt, i + 1);
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
    int countPairs(TreeNode* root, int distance) {
        if (!root) return 0;
        int ans = countPairs(root->left, distance) + countPairs(root->right, distance);
        vector<int> cnt1(distance);
        vector<int> cnt2(distance);
        dfs(root->left, cnt1, 1);
        dfs(root->right, cnt2, 1);
        for (int i = 0; i < distance; ++i) {
            for (int j = 0; j < distance; ++j) {
                if (i + j <= distance) {
                    ans += cnt1[i] * cnt2[j];
                }
            }
        }
        return ans;
    }

    void dfs(TreeNode* root, vector<int>& cnt, int i) {
        if (!root || i >= cnt.size()) return;
        if (!root->left && !root->right) {
            ++cnt[i];
            return;
        }
        dfs(root->left, cnt, i + 1);
        dfs(root->right, cnt, i + 1);
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
func countPairs(root *TreeNode, distance int) int {
	if root == nil {
		return 0
	}
	ans := countPairs(root.Left, distance) + countPairs(root.Right, distance)
	cnt1 := make([]int, distance)
	cnt2 := make([]int, distance)
	dfs(root.Left, cnt1, 1)
	dfs(root.Right, cnt2, 1)
	for i, v1 := range cnt1 {
		for j, v2 := range cnt2 {
			if i+j <= distance {
				ans += v1 * v2
			}
		}
	}
	return ans
}

func dfs(root *TreeNode, cnt []int, i int) {
	if root == nil || i >= len(cnt) {
		return
	}
	if root.Left == nil && root.Right == nil {
		cnt[i]++
		return
	}
	dfs(root.Left, cnt, i+1)
	dfs(root.Right, cnt, i+1)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countPairs(root: TreeNode | null, distance: number): number {
    const pairs: number[][] = [];

    const dfs = (node: TreeNode | null): number[][] => {
        if (!node) return [];
        if (!node.left && !node.right) return [[node.val, 1]];

        const left = dfs(node.left);
        const right = dfs(node.right);

        for (const [x, dx] of left) {
            for (const [y, dy] of right) {
                if (dx + dy <= distance) {
                    pairs.push([x, y]);
                }
            }
        }

        const res: number[][] = [];
        for (const arr of [left, right]) {
            for (const x of arr) {
                if (++x[1] <= distance) res.push(x);
            }
        }

        return res;
    };

    dfs(root);

    return pairs.length;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} distance
 * @return {number}
 */
var countPairs = function (root, distance) {
    const pairs = [];

    const dfs = node => {
        if (!node) return [];
        if (!node.left && !node.right) return [[node.val, 1]];

        const left = dfs(node.left);
        const right = dfs(node.right);

        for (const [x, dx] of left) {
            for (const [y, dy] of right) {
                if (dx + dy <= distance) {
                    pairs.push([x, y]);
                }
            }
        }

        const res = [];
        for (const arr of [left, right]) {
            for (const x of arr) {
                if (++x[1] <= distance) res.push(x);
            }
        }

        return res;
    };

    dfs(root);

    return pairs.length;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你二叉树的根节点 <code>root</code> 和一个整数 <code>distance</code> 。</p>

<p>如果二叉树中两个 <strong>叶</strong> 节点之间的 <strong>最短路径长度</strong> 小于或者等于 <code>distance</code> ，那它们就可以构成一组 <strong>好叶子节点对</strong> 。</p>

<p>返回树中 <strong>好叶子节点对的数量</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p>&nbsp;</p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1530.Number%20of%20Good%20Leaf%20Nodes%20Pairs/images/e1.jpg" style="height: 321px; width: 321px;"></p>

<pre><strong>输入：</strong>root = [1,2,3,null,4], distance = 3
<strong>输出：</strong>1
<strong>解释：</strong>树的叶节点是 3 和 4 ，它们之间的最短路径的长度是 3 。这是唯一的好叶子节点对。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1530.Number%20of%20Good%20Leaf%20Nodes%20Pairs/images/e2.jpg" style="height: 321px; width: 441px;"></p>

<pre><strong>输入：</strong>root = [1,2,3,4,5,6,7], distance = 3
<strong>输出：</strong>2
<strong>解释：</strong>好叶子节点对为 [4,5] 和 [6,7] ，最短路径长度都是 2 。但是叶子节点对 [4,6] 不满足要求，因为它们之间的最短路径长度为 4 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>root = [7,1,4,6,null,5,3,null,null,null,null,null,2], distance = 3
<strong>输出：</strong>1
<strong>解释：</strong>唯一的好叶子节点对是 [2,5] 。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>root = [100], distance = 1
<strong>输出：</strong>0
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>root = [1,1,1], distance = 2
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>tree</code> 的节点数在 <code>[1, 2^10]</code> 范围内。</li>
	<li>每个节点的值都在 <code>[1, 100]</code> 之间。</li>
	<li><code>1 &lt;= distance &lt;= 10</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归

题目求一个二叉树好叶子节点的对数，答案可以拆分为三部分之和：左子树好叶子节点的对数、右子树好叶子节点的对数，以及左子树叶子节点与右子树叶子节点组成的好叶子节点的对数。

递归求解即可。

时间复杂度 $O(n \times distance^2 \times h)$，其中 $n$ 是二叉树的节点数，而 $h$ 是二叉树的高度。

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
    def countPairs(self, root: TreeNode, distance: int) -> int:
        def dfs(root, cnt, i):
            if root is None or i >= distance:
                return
            if root.left is None and root.right is None:
                cnt[i] += 1
                return
            dfs(root.left, cnt, i + 1)
            dfs(root.right, cnt, i + 1)

        if root is None:
            return 0
        ans = self.countPairs(root.left, distance) + self.countPairs(
            root.right, distance
        )
        cnt1 = Counter()
        cnt2 = Counter()
        dfs(root.left, cnt1, 1)
        dfs(root.right, cnt2, 1)

        for k1, v1 in cnt1.items():
            for k2, v2 in cnt2.items():
                if k1 + k2 <= distance:
                    ans += v1 * v2
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
    public int countPairs(TreeNode root, int distance) {
        if (root == null) {
            return 0;
        }
        int ans = countPairs(root.left, distance) + countPairs(root.right, distance);
        int[] cnt1 = new int[distance];
        int[] cnt2 = new int[distance];
        dfs(root.left, cnt1, 1);
        dfs(root.right, cnt2, 1);
        for (int i = 0; i < distance; ++i) {
            for (int j = 0; j < distance; ++j) {
                if (i + j <= distance) {
                    ans += cnt1[i] * cnt2[j];
                }
            }
        }
        return ans;
    }

    void dfs(TreeNode root, int[] cnt, int i) {
        if (root == null || i >= cnt.length) {
            return;
        }
        if (root.left == null && root.right == null) {
            ++cnt[i];
            return;
        }
        dfs(root.left, cnt, i + 1);
        dfs(root.right, cnt, i + 1);
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
    int countPairs(TreeNode* root, int distance) {
        if (!root) return 0;
        int ans = countPairs(root->left, distance) + countPairs(root->right, distance);
        vector<int> cnt1(distance);
        vector<int> cnt2(distance);
        dfs(root->left, cnt1, 1);
        dfs(root->right, cnt2, 1);
        for (int i = 0; i < distance; ++i) {
            for (int j = 0; j < distance; ++j) {
                if (i + j <= distance) {
                    ans += cnt1[i] * cnt2[j];
                }
            }
        }
        return ans;
    }

    void dfs(TreeNode* root, vector<int>& cnt, int i) {
        if (!root || i >= cnt.size()) return;
        if (!root->left && !root->right) {
            ++cnt[i];
            return;
        }
        dfs(root->left, cnt, i + 1);
        dfs(root->right, cnt, i + 1);
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
func countPairs(root *TreeNode, distance int) int {
	if root == nil {
		return 0
	}
	ans := countPairs(root.Left, distance) + countPairs(root.Right, distance)
	cnt1 := make([]int, distance)
	cnt2 := make([]int, distance)
	dfs(root.Left, cnt1, 1)
	dfs(root.Right, cnt2, 1)
	for i, v1 := range cnt1 {
		for j, v2 := range cnt2 {
			if i+j <= distance {
				ans += v1 * v2
			}
		}
	}
	return ans
}

func dfs(root *TreeNode, cnt []int, i int) {
	if root == nil || i >= len(cnt) {
		return
	}
	if root.Left == nil && root.Right == nil {
		cnt[i]++
		return
	}
	dfs(root.Left, cnt, i+1)
	dfs(root.Right, cnt, i+1)
}
```

#### TypeScript

```ts
function countPairs(root: TreeNode | null, distance: number): number {
    const pairs: number[][] = [];

    const dfs = (node: TreeNode | null): number[][] => {
        if (!node) return [];
        if (!node.left && !node.right) return [[node.val, 1]];

        const left = dfs(node.left);
        const right = dfs(node.right);

        for (const [x, dx] of left) {
            for (const [y, dy] of right) {
                if (dx + dy <= distance) {
                    pairs.push([x, y]);
                }
            }
        }

        const res: number[][] = [];
        for (const arr of [left, right]) {
            for (const x of arr) {
                if (++x[1] <= distance) res.push(x);
            }
        }

        return res;
    };

    dfs(root);

    return pairs.length;
}
```

#### JavaScript

```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} distance
 * @return {number}
 */
var countPairs = function (root, distance) {
    const pairs = [];

    const dfs = node => {
        if (!node) return [];
        if (!node.left && !node.right) return [[node.val, 1]];

        const left = dfs(node.left);
        const right = dfs(node.right);

        for (const [x, dx] of left) {
            for (const [y, dy] of right) {
                if (dx + dy <= distance) {
                    pairs.push([x, y]);
                }
            }
        }

        const res = [];
        for (const arr of [left, right]) {
            for (const x of arr) {
                if (++x[1] <= distance) res.push(x);
            }
        }

        return res;
    };

    dfs(root);

    return pairs.length;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1531. 压缩字符串 II](https://leetcode.cn/problems/string-compression-ii){#1531}

{{< tabs "1531" >}}

{{% tab "java" %}}
```java
class Solution {
    public int getLengthOfOptimalCompression(String s, int k) {
        // dp[i][k] := the length of the optimal compression of s[i..n) with at most
        // k deletion
        dp = new int[s.length()][k + 1];
        Arrays.stream(dp).forEach(A -> Arrays.fill(A, K_MAX));
        return compression(s, 0, k);
    }

    private static final int K_MAX = 101;
    private int[][] dp;

    private int compression(final String s, int i, int k) {
        if (k < 0) {
            return K_MAX;
        }
        if (i == s.length() || s.length() - i <= k) {
            return 0;
        }
        if (dp[i][k] != K_MAX) {
            return dp[i][k];
        }
        int maxFreq = 0;
        int[] count = new int[128];
        // Make letters in s[i..j] be the same.
        // Keep the letter that has the maximum frequency in this range and remove
        // the other letters.
        for (int j = i; j < s.length(); ++j) {
            maxFreq = Math.max(maxFreq, ++count[s.charAt(j)]);
            dp[i][k] = Math.min(
                dp[i][k], getLength(maxFreq) + compression(s, j + 1, k - (j - i + 1 - maxFreq)));
        }
        return dp[i][k];
    }

    // Returns the length to compress `maxFreq`.
    private int getLength(int maxFreq) {
        if (maxFreq == 1) {
            return 1; // c
        }
        if (maxFreq < 10) {
            return 2; // [1-9]c
        }
        if (maxFreq < 100) {
            return 3; // [1-9][0-9]c
        }
        return 4; // [1-9][0-9][0-9]c
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><a href="https://baike.baidu.com/item/%E8%A1%8C%E7%A8%8B%E9%95%BF%E5%BA%A6%E7%BC%96%E7%A0%81/2931940?fr=aladdin" target="_blank">行程长度编码</a> 是一种常用的字符串压缩方法，它将连续的相同字符（重复 2 次或更多次）替换为字符和表示字符计数的数字（行程长度）。例如，用此方法压缩字符串 <code>&quot;aabccc&quot;</code> ，将 <code>&quot;aa&quot;</code> 替换为 <code>&quot;a2&quot;</code> ，<code>&quot;ccc&quot;</code> 替换为` <code>&quot;c3&quot;</code> 。因此压缩后的字符串变为 <code>&quot;a2bc3&quot;</code> 。</p>

<p>注意，本问题中，压缩时没有在单个字符后附加计数 <code>&#39;1&#39;</code> 。</p>

<p>给你一个字符串 <code>s</code> 和一个整数 <code>k</code> 。你需要从字符串 <code>s</code> 中删除最多 <code>k</code> 个字符，以使 <code>s</code> 的行程长度编码长度最小。</p>

<p>请你返回删除最多 <code>k</code> 个字符后，<code>s</code> <strong>行程长度编码的最小长度</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = &quot;aaabcccd&quot;, k = 2
<strong>输出：</strong>4
<strong>解释：</strong>在不删除任何内容的情况下，压缩后的字符串是 &quot;a3bc3d&quot; ，长度为 6 。最优的方案是删除 &#39;b&#39; 和 &#39;d&#39;，这样一来，压缩后的字符串为 &quot;a3c3&quot; ，长度是 4 。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = &quot;aabbaa&quot;, k = 2
<strong>输出：</strong>2
<strong>解释：</strong>如果删去两个 &#39;b&#39; 字符，那么压缩后的字符串是长度为 2 的 &quot;a4&quot; 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = &quot;aaaaaaaaaaa&quot;, k = 0
<strong>输出：</strong>3
<strong>解释：</strong>由于 k 等于 0 ，不能删去任何字符。压缩后的字符串是 &quot;a11&quot; ，长度为 3 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>0 &lt;= k &lt;= s.length</code></li>
	<li><code>s</code> 仅包含小写英文字母</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### Java

```java
class Solution {
    public int getLengthOfOptimalCompression(String s, int k) {
        // dp[i][k] := the length of the optimal compression of s[i..n) with at most
        // k deletion
        dp = new int[s.length()][k + 1];
        Arrays.stream(dp).forEach(A -> Arrays.fill(A, K_MAX));
        return compression(s, 0, k);
    }

    private static final int K_MAX = 101;
    private int[][] dp;

    private int compression(final String s, int i, int k) {
        if (k < 0) {
            return K_MAX;
        }
        if (i == s.length() || s.length() - i <= k) {
            return 0;
        }
        if (dp[i][k] != K_MAX) {
            return dp[i][k];
        }
        int maxFreq = 0;
        int[] count = new int[128];
        // Make letters in s[i..j] be the same.
        // Keep the letter that has the maximum frequency in this range and remove
        // the other letters.
        for (int j = i; j < s.length(); ++j) {
            maxFreq = Math.max(maxFreq, ++count[s.charAt(j)]);
            dp[i][k] = Math.min(
                dp[i][k], getLength(maxFreq) + compression(s, j + 1, k - (j - i + 1 - maxFreq)));
        }
        return dp[i][k];
    }

    // Returns the length to compress `maxFreq`.
    private int getLength(int maxFreq) {
        if (maxFreq == 1) {
            return 1; // c
        }
        if (maxFreq < 10) {
            return 2; // [1-9]c
        }
        if (maxFreq < 100) {
            return 3; // [1-9][0-9]c
        }
        return 4; // [1-9][0-9][0-9]c
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1532. 最近的三笔订单 🔒](https://leetcode.cn/problems/the-most-recent-three-orders){#1532}

{{< tabs "1532" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            *,
            ROW_NUMBER() OVER (
                PARTITION BY customer_id
                ORDER BY order_date DESC
            ) AS rk
        FROM
            Orders
            JOIN Customers USING (customer_id)
    )
SELECT name AS customer_name, customer_id, order_id, order_date
FROM T
WHERE rk <= 3
ORDER BY 1, 2, 4 DESC;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Customers</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| customer_id   | int     |
| name          | varchar |
+---------------+---------+
customer_id 是该表具有唯一值的列
该表包含消费者的信息
</pre>

<p>&nbsp;</p>

<p>表：<code>Orders</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| order_id      | int     |
| order_date    | date    |
| customer_id   | int     |
| cost          | int     |
+---------------+---------+
order_id 是该表具有唯一值的列
该表包含 id 为 customer_id 的消费者的订单信息
每一个消费者<strong> 每天一笔订单</strong>
</pre>

<p>&nbsp;</p>

<p>写一个解决方案，找到每个用户的最近三笔订单。如果用户的订单少于 3 笔，则返回他的全部订单。</p>

<p>返回的结果按照 <code>customer_name</code>&nbsp;<strong>升序&nbsp;</strong>排列。如果有相同的排名，则按照 <code>customer_id</code> <strong>升序&nbsp;</strong>排列。如果排名还有相同，则按照 <code>order_date</code> <strong>降序&nbsp;</strong>排列。</p>

<p>结果格式如下例所示：</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入：</strong>
<code>Customers</code>
+-------------+-----------+
| customer_id | name      |
+-------------+-----------+
| 1           | Winston   |
| 2           | Jonathan  |
| 3           | Annabelle |
| 4           | Marwan    |
| 5           | Khaled    |
+-------------+-----------+

<code>Orders</code>
+----------+------------+-------------+------+
| order_id | order_date | customer_id | cost |
+----------+------------+-------------+------+
| 1        | 2020-07-31 | 1           | 30   |
| 2        | 2020-07-30 | 2           | 40   |
| 3        | 2020-07-31 | 3           | 70   |
| 4        | 2020-07-29 | 4           | 100  |
| 5        | 2020-06-10 | 1           | 1010 |
| 6        | 2020-08-01 | 2           | 102  |
| 7        | 2020-08-01 | 3           | 111  |
| 8        | 2020-08-03 | 1           | 99   |
| 9        | 2020-08-07 | 2           | 32   |
| 10       | 2020-07-15 | 1           | 2    |
+----------+------------+-------------+------+
<strong>输出：</strong>
+---------------+-------------+----------+------------+
| customer_name | customer_id | order_id | order_date |
+---------------+-------------+----------+------------+
| Annabelle     | 3           | 7        | 2020-08-01 |
| Annabelle     | 3           | 3        | 2020-07-31 |
| Jonathan      | 2           | 9        | 2020-08-07 |
| Jonathan      | 2           | 6        | 2020-08-01 |
| Jonathan      | 2           | 2        | 2020-07-30 |
| Marwan        | 4           | 4        | 2020-07-29 |
| Winston       | 1           | 8        | 2020-08-03 |
| Winston       | 1           | 1        | 2020-07-31 |
| Winston       | 1           | 10       | 2020-07-15 |
+---------------+-------------+----------+------------+
<strong>解释：</strong>
Winston 有 4 笔订单, 排除了 "2020-06-10" 的订单, 因为它是最老的订单。
Annabelle 只有 2 笔订单, 全部返回。
Jonathan 恰好有 3 笔订单。
Marwan 只有 1 笔订单。
结果表我们按照 customer_name 升序排列，customer_id 升序排列，order_date 降序排列。
</pre>

<p>&nbsp;</p>

<p><strong>进阶：</strong></p>

<ul>
	<li>你能写出最近&nbsp;<code>n</code>&nbsp;笔订单的通用解决方案吗?</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：等值连接 + 窗口函数

我们可以使用等值连接，将 `Customers` 表和 `Orders` 表按照 `customer_id` 进行连接，然后使用 `row_number()` 窗口函数来为每个消费者的订单按照 `order_date` 降序排列，并为每个消费者的订单添加一个序号，最后筛选出序号小于等于 $3$ 的订单即可。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            *,
            ROW_NUMBER() OVER (
                PARTITION BY customer_id
                ORDER BY order_date DESC
            ) AS rk
        FROM
            Orders
            JOIN Customers USING (customer_id)
    )
SELECT name AS customer_name, customer_id, order_id, order_date
FROM T
WHERE rk <= 3
ORDER BY 1, 2, 4 DESC;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1533. 找到最大整数的索引 🔒](https://leetcode.cn/problems/find-the-index-of-the-large-integer){#1533}

{{< tabs "1533" >}}

{{% tab "python" %}}
```python
# """
# This is ArrayReader's API interface.
# You should not implement it, or speculate about its implementation
# """
# class ArrayReader(object):
# 	 # Compares the sum of arr[l..r] with the sum of arr[x..y]
# 	 # return 1 if sum(arr[l..r]) > sum(arr[x..y])
# 	 # return 0 if sum(arr[l..r]) == sum(arr[x..y])
# 	 # return -1 if sum(arr[l..r]) < sum(arr[x..y])
#    def compareSub(self, l: int, r: int, x: int, y: int) -> int:
#
# 	 # Returns the length of the array
#    def length(self) -> int:
#


class Solution:
    def getIndex(self, reader: 'ArrayReader') -> int:
        left, right = 0, reader.length() - 1
        while left < right:
            t1, t2, t3 = (
                left,
                left + (right - left) // 3,
                left + ((right - left) // 3) * 2 + 1,
            )
            cmp = reader.compareSub(t1, t2, t2 + 1, t3)
            if cmp == 0:
                left = t3 + 1
            elif cmp == 1:
                right = t2
            else:
                left, right = t2 + 1, t3
        return left
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * // This is ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface ArrayReader {
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y]
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     public int compareSub(int l, int r, int x, int y) {}
 *
 *     // Returns the length of the array
 *     public int length() {}
 * }
 */

class Solution {
    public int getIndex(ArrayReader reader) {
        int left = 0, right = reader.length() - 1;
        while (left < right) {
            int t1 = left, t2 = left + (right - left) / 3, t3 = left + (right - left) / 3 * 2 + 1;
            int cmp = reader.compareSub(t1, t2, t2 + 1, t3);
            if (cmp == 0) {
                left = t3 + 1;
            } else if (cmp == 1) {
                right = t2;
            } else {
                left = t2 + 1;
                right = t3;
            }
        }
        return left;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y]
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     int compareSub(int l, int r, int x, int y);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:
    int getIndex(ArrayReader& reader) {
        int left = 0, right = reader.length() - 1;
        while (left < right) {
            int t1 = left, t2 = left + (right - left) / 3, t3 = left + (right - left) / 3 * 2 + 1;
            int cmp = reader.compareSub(t1, t2, t2 + 1, t3);
            if (cmp == 0) {
                left = t3 + 1;
            } else if (cmp == 1) {
                right = t2;
            } else {
                left = t2 + 1;
                right = t3;
            }
        }
        return left;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * type ArrayReader struct {
 * }
 * // Compares the sum of arr[l..r] with the sum of arr[x..y]
 * // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 * // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 * // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 * func (this *ArrayReader) compareSub(l, r, x, y int) int {}
 *
 * // Returns the length of the array
 * func (this *ArrayReader) length() int {}
 */

func getIndex(reader *ArrayReader) int {
	left, right := 0, reader.length()-1
	for left < right {
		t1, t2, t3 := left, left+(right-left)/3, left+(right-left)/3*2+1
		cmp := reader.compareSub(t1, t2, t2+1, t3)
		if cmp == 0 {
			left = t3 + 1
		} else if cmp == 1 {
			right = t2
		} else {
			left, right = t2+1, t3
		}
	}
	return left
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>我们有这样一个整数数组&nbsp;<code>arr</code>&nbsp;，除了一个最大的整数外，其他所有整数都相等。你不能直接访问该数组，你需要通过&nbsp;<strong>API</strong> <code>ArrayReader</code>&nbsp;来间接访问，这个 API&nbsp;有以下成员函数：</p>

<ul>
	<li><code>int compareSub(int l, int r, int x, int y)</code>：其中&nbsp;<code>0 &lt;= l, r, x, y &lt;&nbsp;ArrayReader.length()</code>，&nbsp;<code>l &lt;= r</code>&nbsp;且&nbsp;<code>x &lt;= y</code>。这个函数比较子数组&nbsp;<code>arr[l..r]</code>&nbsp;与子数组&nbsp;<code>arr[x..y]</code>&nbsp;的和。该函数返回：

    <ul>
    	<li><strong>1</strong>&nbsp;若&nbsp;<code>arr[l]+arr[l+1]+...+arr[r] &gt; arr[x]+arr[x+1]+...+arr[y]</code>&nbsp;。</li>
    	<li><strong>0</strong>&nbsp;若&nbsp;<code>arr[l]+arr[l+1]+...+arr[r] == arr[x]+arr[x+1]+...+arr[y]</code>&nbsp;。</li>
    	<li><strong>-1</strong>&nbsp;若&nbsp;<code>arr[l]+arr[l+1]+...+arr[r] &lt; arr[x]+arr[x+1]+...+arr[y]</code>&nbsp;。</li>
    </ul>
    </li>
    <li><code>int length()</code>：返回数组的长度。</li>

</ul>

<p>你最多可以调用函数&nbsp;<code>compareSub()</code>&nbsp;<strong>20 次</strong>。你可以认为这两个函数的时间复杂度都为&nbsp;<code>O(1)</code>&nbsp;。</p>

<p>返回<em>&nbsp;<code>arr</code>&nbsp;中最大整数的索引。</em></p>

<ul>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入:</strong> arr = [7,7,7,7,10,7,7,7]
<strong>输出:</strong> 4
<strong>解释:</strong> API 的调用如下：
reader.compareSub(0, 0, 1, 1) // 返回 0。比较子数组 (0, 0) 与子数组 (1, 1) （即比较 arr[0] 和 arr[1]）。
因此我们知道 arr[0] 和 arr[1] 不包含最大元素。
reader.compareSub(2, 2, 3, 3) // 返回 0。我们可以排除 arr[2] 和 arr[3]。
reader.compareSub(4, 4, 5, 5) // 返回 1。因此，可以确定 arr[4] 是数组中最大的元素。
注意，我们只调用了 3 次 compareSub，所以这个答案是有效的。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> nums = [6,6,12]
<strong>输出:</strong> 2
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>2 &lt;= arr.length&nbsp;&lt;= 5 * 10<sup>5</sup></code></li>
	<li><code>1 &lt;= arr[i] &lt;= 100</code></li>
	<li><code>arr</code>&nbsp;中除一个最大元素外，其余所有元素都相等。</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶</strong></p>

<ul>
	<li>如果&nbsp;<code>arr</code>&nbsp;中有两个整数比其他数大呢？</li>
	<li>如果有一个数比其他数大，另一个数比其他数小呢？</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### Python3

```python
# """
# This is ArrayReader's API interface.
# You should not implement it, or speculate about its implementation
# """
# class ArrayReader(object):
# 	 # Compares the sum of arr[l..r] with the sum of arr[x..y]
# 	 # return 1 if sum(arr[l..r]) > sum(arr[x..y])
# 	 # return 0 if sum(arr[l..r]) == sum(arr[x..y])
# 	 # return -1 if sum(arr[l..r]) < sum(arr[x..y])
#    def compareSub(self, l: int, r: int, x: int, y: int) -> int:
#
# 	 # Returns the length of the array
#    def length(self) -> int:
#


class Solution:
    def getIndex(self, reader: 'ArrayReader') -> int:
        left, right = 0, reader.length() - 1
        while left < right:
            t1, t2, t3 = (
                left,
                left + (right - left) // 3,
                left + ((right - left) // 3) * 2 + 1,
            )
            cmp = reader.compareSub(t1, t2, t2 + 1, t3)
            if cmp == 0:
                left = t3 + 1
            elif cmp == 1:
                right = t2
            else:
                left, right = t2 + 1, t3
        return left
```

#### Java

```java
/**
 * // This is ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface ArrayReader {
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y]
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     public int compareSub(int l, int r, int x, int y) {}
 *
 *     // Returns the length of the array
 *     public int length() {}
 * }
 */

class Solution {
    public int getIndex(ArrayReader reader) {
        int left = 0, right = reader.length() - 1;
        while (left < right) {
            int t1 = left, t2 = left + (right - left) / 3, t3 = left + (right - left) / 3 * 2 + 1;
            int cmp = reader.compareSub(t1, t2, t2 + 1, t3);
            if (cmp == 0) {
                left = t3 + 1;
            } else if (cmp == 1) {
                right = t2;
            } else {
                left = t2 + 1;
                right = t3;
            }
        }
        return left;
    }
}
```

#### C++

```cpp
/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y]
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     int compareSub(int l, int r, int x, int y);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:
    int getIndex(ArrayReader& reader) {
        int left = 0, right = reader.length() - 1;
        while (left < right) {
            int t1 = left, t2 = left + (right - left) / 3, t3 = left + (right - left) / 3 * 2 + 1;
            int cmp = reader.compareSub(t1, t2, t2 + 1, t3);
            if (cmp == 0) {
                left = t3 + 1;
            } else if (cmp == 1) {
                right = t2;
            } else {
                left = t2 + 1;
                right = t3;
            }
        }
        return left;
    }
};
```

#### Go

```go
/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * type ArrayReader struct {
 * }
 * // Compares the sum of arr[l..r] with the sum of arr[x..y]
 * // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 * // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 * // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 * func (this *ArrayReader) compareSub(l, r, x, y int) int {}
 *
 * // Returns the length of the array
 * func (this *ArrayReader) length() int {}
 */

func getIndex(reader *ArrayReader) int {
	left, right := 0, reader.length()-1
	for left < right {
		t1, t2, t3 := left, left+(right-left)/3, left+(right-left)/3*2+1
		cmp := reader.compareSub(t1, t2, t2+1, t3)
		if cmp == 0 {
			left = t3 + 1
		} else if cmp == 1 {
			right = t2
		} else {
			left, right = t2+1, t3
		}
	}
	return left
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1534. 统计好三元组](https://leetcode.cn/problems/count-good-triplets){#1534}

{{< tabs "1534" >}}

{{% tab "python" %}}
```python
class Solution:
    def countGoodTriplets(self, arr: List[int], a: int, b: int, c: int) -> int:
        ans, n = 0, len(arr)
        for i in range(n):
            for j in range(i + 1, n):
                for k in range(j + 1, n):
                    ans += (
                        abs(arr[i] - arr[j]) <= a
                        and abs(arr[j] - arr[k]) <= b
                        and abs(arr[i] - arr[k]) <= c
                    )
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countGoodTriplets(int[] arr, int a, int b, int c) {
        int n = arr.length;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (Math.abs(arr[i] - arr[j]) <= a && Math.abs(arr[j] - arr[k]) <= b
                        && Math.abs(arr[i] - arr[k]) <= c) {
                        ++ans;
                    }
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
class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    ans += abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c;
                }
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countGoodTriplets(arr []int, a int, b int, c int) (ans int) {
	n := len(arr)
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			for k := j + 1; k < n; k++ {
				if abs(arr[i]-arr[j]) <= a && abs(arr[j]-arr[k]) <= b && abs(arr[i]-arr[k]) <= c {
					ans++
				}
			}
		}
	}
	return
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countGoodTriplets(arr: number[], a: number, b: number, c: number): number {
    let n = arr.length;
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        for (let j = i + 1; j < n; ++j) {
            for (let k = j + 1; k < n; ++k) {
                if (
                    Math.abs(arr[i] - arr[j]) <= a &&
                    Math.abs(arr[j] - arr[k]) <= b &&
                    Math.abs(arr[i] - arr[k]) <= c
                ) {
                    ++ans;
                }
            }
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn count_good_triplets(arr: Vec<i32>, a: i32, b: i32, c: i32) -> i32 {
        let n = arr.len();
        let mut ans = 0;

        for i in 0..n {
            for j in i + 1..n {
                for k in j + 1..n {
                    if (arr[i] - arr[j]).abs() <= a && (arr[j] - arr[k]).abs() <= b && (arr[i] - arr[k]).abs() <= c {
                        ans += 1;
                    }
                }
            }
        }

        ans
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int CountGoodTriplets(int[] arr, int a, int b, int c) {
        int n = arr.Length;
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (Math.Abs(arr[i] - arr[j]) <= a && Math.Abs(arr[j] - arr[k]) <= b && Math.Abs(arr[i] - arr[k]) <= c) {
                        ++ans;
                    }
                }
            }
        }

        return ans;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>arr</code> ，以及 <code>a</code>、<code>b</code> 、<code>c</code> 三个整数。请你统计其中好三元组的数量。</p>

<p>如果三元组 <code>(arr[i], arr[j], arr[k])</code> 满足下列全部条件，则认为它是一个 <strong>好三元组</strong> 。</p>

<ul>
	<li><code>0 &lt;= i &lt; j &lt; k &lt;&nbsp;arr.length</code></li>
	<li><code>|arr[i] - arr[j]| &lt;= a</code></li>
	<li><code>|arr[j] - arr[k]| &lt;= b</code></li>
	<li><code>|arr[i] - arr[k]| &lt;= c</code></li>
</ul>

<p>其中 <code>|x|</code> 表示 <code>x</code> 的绝对值。</p>

<p>返回 <strong>好三元组的数量</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [3,0,1,1,9,7], a = 7, b = 2, c = 3
<strong>输出：</strong>4
<strong>解释：</strong>一共有 4 个好三元组：[(3,0,1), (3,0,1), (3,1,1), (0,1,1)] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = [1,1,2,2,3], a = 0, b = 0, c = 1
<strong>输出：</strong>0
<strong>解释：</strong>不存在满足所有条件的三元组。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= arr.length &lt;= 100</code></li>
	<li><code>0 &lt;= arr[i] &lt;= 1000</code></li>
	<li><code>0 &lt;= a, b, c &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们可以枚举所有的 $i$, $j$ 和 $k$，其中 $i \lt j \lt k$，判断是否同时满足 $|\textit{arr}[i] - \textit{arr}[j]| \le a$，$|\textit{arr}[j] - \textit{arr}[k]| \le b$ 和 $|\textit{arr}[i] - \textit{arr}[k]| \le c$，如果满足则将答案加一。

枚举结束后，即可得到答案。

时间复杂度 $O(n^3)$，其中 $n$ 为数组 $\textit{arr}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countGoodTriplets(self, arr: List[int], a: int, b: int, c: int) -> int:
        ans, n = 0, len(arr)
        for i in range(n):
            for j in range(i + 1, n):
                for k in range(j + 1, n):
                    ans += (
                        abs(arr[i] - arr[j]) <= a
                        and abs(arr[j] - arr[k]) <= b
                        and abs(arr[i] - arr[k]) <= c
                    )
        return ans
```

#### Java

```java
class Solution {
    public int countGoodTriplets(int[] arr, int a, int b, int c) {
        int n = arr.length;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (Math.abs(arr[i] - arr[j]) <= a && Math.abs(arr[j] - arr[k]) <= b
                        && Math.abs(arr[i] - arr[k]) <= c) {
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
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    ans += abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func countGoodTriplets(arr []int, a int, b int, c int) (ans int) {
	n := len(arr)
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			for k := j + 1; k < n; k++ {
				if abs(arr[i]-arr[j]) <= a && abs(arr[j]-arr[k]) <= b && abs(arr[i]-arr[k]) <= c {
					ans++
				}
			}
		}
	}
	return
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```

#### TypeScript

```ts
function countGoodTriplets(arr: number[], a: number, b: number, c: number): number {
    let n = arr.length;
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        for (let j = i + 1; j < n; ++j) {
            for (let k = j + 1; k < n; ++k) {
                if (
                    Math.abs(arr[i] - arr[j]) <= a &&
                    Math.abs(arr[j] - arr[k]) <= b &&
                    Math.abs(arr[i] - arr[k]) <= c
                ) {
                    ++ans;
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
    pub fn count_good_triplets(arr: Vec<i32>, a: i32, b: i32, c: i32) -> i32 {
        let n = arr.len();
        let mut ans = 0;

        for i in 0..n {
            for j in i + 1..n {
                for k in j + 1..n {
                    if (arr[i] - arr[j]).abs() <= a && (arr[j] - arr[k]).abs() <= b && (arr[i] - arr[k]).abs() <= c {
                        ans += 1;
                    }
                }
            }
        }

        ans
    }
}
```

#### C#

```cs
public class Solution {
    public int CountGoodTriplets(int[] arr, int a, int b, int c) {
        int n = arr.Length;
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (Math.Abs(arr[i] - arr[j]) <= a && Math.Abs(arr[j] - arr[k]) <= b && Math.Abs(arr[i] - arr[k]) <= c) {
                        ++ans;
                    }
                }
            }
        }

        return ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1535. 找出数组游戏的赢家](https://leetcode.cn/problems/find-the-winner-of-an-array-game){#1535}

{{< tabs "1535" >}}

{{% tab "python" %}}
```python
class Solution:
    def getWinner(self, arr: List[int], k: int) -> int:
        mx = arr[0]
        cnt = 0
        for x in arr[1:]:
            if mx < x:
                mx = x
                cnt = 1
            else:
                cnt += 1
            if cnt == k:
                break
        return mx
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int getWinner(int[] arr, int k) {
        int mx = arr[0];
        for (int i = 1, cnt = 0; i < arr.length; ++i) {
            if (mx < arr[i]) {
                mx = arr[i];
                cnt = 1;
            } else {
                ++cnt;
            }
            if (cnt == k) {
                break;
            }
        }
        return mx;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int mx = arr[0];
        for (int i = 1, cnt = 0; i < arr.size(); ++i) {
            if (mx < arr[i]) {
                mx = arr[i];
                cnt = 1;
            } else {
                ++cnt;
            }
            if (cnt == k) {
                break;
            }
        }
        return mx;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getWinner(arr []int, k int) int {
	mx, cnt := arr[0], 0
	for _, x := range arr[1:] {
		if mx < x {
			mx = x
			cnt = 1
		} else {
			cnt++
		}
		if cnt == k {
			break
		}
	}
	return mx
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function getWinner(arr: number[], k: number): number {
    let mx = arr[0];
    let cnt = 0;
    for (const x of arr.slice(1)) {
        if (mx < x) {
            mx = x;
            cnt = 1;
        } else {
            ++cnt;
        }
        if (cnt === k) {
            break;
        }
    }
    return mx;
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int GetWinner(int[] arr, int k) {
        int maxElement = arr[0], count = 0;
        for (int i = 1; i < arr.Length; i++) {
            if (maxElement < arr[i]) {
                maxElement = arr[i];
                count = 1;
            } else {
                count++;
            }
            if (count == k) {
                break;
            }
        }
        return maxElement;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个由 <strong>不同</strong> 整数组成的整数数组 <code>arr</code> 和一个整数 <code>k</code> 。</p>

<p>每回合游戏都在数组的前两个元素（即 <code>arr[0]</code> 和 <code>arr[1]</code> ）之间进行。比较 <code>arr[0]</code> 与 <code>arr[1]</code> 的大小，较大的整数将会取得这一回合的胜利并保留在位置 <code>0</code> ，较小的整数移至数组的末尾。当一个整数赢得 <code>k</code> 个连续回合时，游戏结束，该整数就是比赛的 <strong>赢家</strong> 。</p>

<p>返回赢得比赛的整数。</p>

<p>题目数据 <strong>保证</strong> 游戏存在赢家。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [2,1,3,5,4,6,7], k = 2
<strong>输出：</strong>5
<strong>解释：</strong>一起看一下本场游戏每回合的情况：
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1535.Find%20the%20Winner%20of%20an%20Array%20Game/images/q-example.png" style="height: 90px; width: 400px;">
因此将进行 4 回合比赛，其中 5 是赢家，因为它连胜 2 回合。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = [3,2,1], k = 10
<strong>输出：</strong>3
<strong>解释：</strong>3 将会在前 10 个回合中连续获胜。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>arr = [1,9,8,2,3,7,6,4,5], k = 7
<strong>输出：</strong>9
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>arr = [1,11,22,33,44,55,66,77,88,99], k = 1000000000
<strong>输出：</strong>99
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= arr.length &lt;= 10^5</code></li>
	<li><code>1 &lt;= arr[i] &lt;= 10^6</code></li>
	<li><code>arr</code> 所含的整数 <strong>各不相同</strong> 。</li>
	<li><code>1 &lt;= k &lt;= 10^9</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：脑筋急转弯

我们注意到，每次会比较数组的前两个元素，不管结果怎么样，下一次的比较，一定是轮到了数组中的下一个元素和当前的胜者进行比较。因此，如果循环了 $n-1$ 次，那么最后的胜者一定是数组中的最大元素。否则，如果某个元素连续胜出了 $k$ 次，那么这个元素就是最后的胜者。

时间复杂度 $O(n)$，其中 $n$ 是数组的长度。空间复杂度 $O(1)$。

相似题目：

-   [3175. 找到连续赢 K 场比赛的第一位玩家](https://github.com/doocs/leetcode/blob/main/solution/3100-3199/3175.Find%20The%20First%20Player%20to%20win%20K%20Games%20in%20a%20Row/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getWinner(self, arr: List[int], k: int) -> int:
        mx = arr[0]
        cnt = 0
        for x in arr[1:]:
            if mx < x:
                mx = x
                cnt = 1
            else:
                cnt += 1
            if cnt == k:
                break
        return mx
```

#### Java

```java
class Solution {
    public int getWinner(int[] arr, int k) {
        int mx = arr[0];
        for (int i = 1, cnt = 0; i < arr.length; ++i) {
            if (mx < arr[i]) {
                mx = arr[i];
                cnt = 1;
            } else {
                ++cnt;
            }
            if (cnt == k) {
                break;
            }
        }
        return mx;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int mx = arr[0];
        for (int i = 1, cnt = 0; i < arr.size(); ++i) {
            if (mx < arr[i]) {
                mx = arr[i];
                cnt = 1;
            } else {
                ++cnt;
            }
            if (cnt == k) {
                break;
            }
        }
        return mx;
    }
};
```

#### Go

```go
func getWinner(arr []int, k int) int {
	mx, cnt := arr[0], 0
	for _, x := range arr[1:] {
		if mx < x {
			mx = x
			cnt = 1
		} else {
			cnt++
		}
		if cnt == k {
			break
		}
	}
	return mx
}
```

#### TypeScript

```ts
function getWinner(arr: number[], k: number): number {
    let mx = arr[0];
    let cnt = 0;
    for (const x of arr.slice(1)) {
        if (mx < x) {
            mx = x;
            cnt = 1;
        } else {
            ++cnt;
        }
        if (cnt === k) {
            break;
        }
    }
    return mx;
}
```

#### C#

```cs
public class Solution {
    public int GetWinner(int[] arr, int k) {
        int maxElement = arr[0], count = 0;
        for (int i = 1; i < arr.Length; i++) {
            if (maxElement < arr[i]) {
                maxElement = arr[i];
                count = 1;
            } else {
                count++;
            }
            if (count == k) {
                break;
            }
        }
        return maxElement;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1536. 排布二进制网格的最少交换次数](https://leetcode.cn/problems/minimum-swaps-to-arrange-a-binary-grid){#1536}

{{< tabs "1536" >}}

{{% tab "python" %}}
```python
class Solution:
    def minSwaps(self, grid: List[List[int]]) -> int:
        n = len(grid)
        pos = [-1] * n
        for i in range(n):
            for j in range(n - 1, -1, -1):
                if grid[i][j] == 1:
                    pos[i] = j
                    break
        ans = 0
        for i in range(n):
            k = -1
            for j in range(i, n):
                if pos[j] <= i:
                    ans += j - i
                    k = j
                    break
            if k == -1:
                return -1
            while k > i:
                pos[k], pos[k - 1] = pos[k - 1], pos[k]
                k -= 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minSwaps(int[][] grid) {
        int n = grid.length;
        int[] pos = new int[n];
        Arrays.fill(pos, -1);
        for (int i = 0; i < n; ++i) {
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == 1) {
                    pos[i] = j;
                    break;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int k = -1;
            for (int j = i; j < n; ++j) {
                if (pos[j] <= i) {
                    ans += j - i;
                    k = j;
                    break;
                }
            }
            if (k == -1) {
                return -1;
            }
            for (; k > i; --k) {
                int t = pos[k];
                pos[k] = pos[k - 1];
                pos[k - 1] = t;
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
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> pos(n, -1);
        for (int i = 0; i < n; ++i) {
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == 1) {
                    pos[i] = j;
                    break;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int k = -1;
            for (int j = i; j < n; ++j) {
                if (pos[j] <= i) {
                    ans += j - i;
                    k = j;
                    break;
                }
            }
            if (k == -1) {
                return -1;
            }
            for (; k > i; --k) {
                swap(pos[k], pos[k - 1]);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minSwaps(grid [][]int) (ans int) {
	n := len(grid)
	pos := make([]int, n)
	for i := range pos {
		pos[i] = -1
	}
	for i := 0; i < n; i++ {
		for j := n - 1; j >= 0; j-- {
			if grid[i][j] == 1 {
				pos[i] = j
				break
			}
		}
	}
	for i := 0; i < n; i++ {
		k := -1
		for j := i; j < n; j++ {
			if pos[j] <= i {
				ans += j - i
				k = j
				break
			}
		}
		if k == -1 {
			return -1
		}
		for ; k > i; k-- {
			pos[k], pos[k-1] = pos[k-1], pos[k]
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minSwaps(grid: number[][]): number {
    const n = grid.length;
    const pos: number[] = Array(n).fill(-1);
    for (let i = 0; i < n; ++i) {
        for (let j = n - 1; ~j; --j) {
            if (grid[i][j] === 1) {
                pos[i] = j;
                break;
            }
        }
    }
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        let k = -1;
        for (let j = i; j < n; ++j) {
            if (pos[j] <= i) {
                ans += j - i;
                k = j;
                break;
            }
        }
        if (k === -1) {
            return -1;
        }
        for (; k > i; --k) {
            [pos[k], pos[k - 1]] = [pos[k - 1], pos[k]];
        }
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

<p>给你一个&nbsp;<code>n&nbsp;x n</code>&nbsp;的二进制网格&nbsp;<code>grid</code>，每一次操作中，你可以选择网格的&nbsp;<strong>相邻两行</strong>&nbsp;进行交换。</p>

<p>一个符合要求的网格需要满足主对角线以上的格子全部都是 <strong>0</strong>&nbsp;。</p>

<p>请你返回使网格满足要求的最少操作次数，如果无法使网格符合要求，请你返回 <strong>-1</strong>&nbsp;。</p>

<p>主对角线指的是从&nbsp;<code>(1, 1)</code>&nbsp;到&nbsp;<code>(n, n)</code>&nbsp;的这些格子。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1536.Minimum%20Swaps%20to%20Arrange%20a%20Binary%20Grid/images/fw.jpg" style="height: 141px; width: 750px;"></p>

<pre><strong>输入：</strong>grid = [[0,0,1],[1,1,0],[1,0,0]]
<strong>输出：</strong>3
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1536.Minimum%20Swaps%20to%20Arrange%20a%20Binary%20Grid/images/e2.jpg" style="height: 270px; width: 270px;"></p>

<pre><strong>输入：</strong>grid = [[0,1,1,0],[0,1,1,0],[0,1,1,0],[0,1,1,0]]
<strong>输出：</strong>-1
<strong>解释：</strong>所有行都是一样的，交换相邻行无法使网格符合要求。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1536.Minimum%20Swaps%20to%20Arrange%20a%20Binary%20Grid/images/e3.jpg" style="height: 210px; width: 210px;"></p>

<pre><strong>输入：</strong>grid = [[1,0,0],[1,1,0],[1,1,1]]
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= n&nbsp;&lt;= 200</code></li>
	<li><code>grid[i][j]</code>&nbsp;要么是&nbsp;<code>0</code>&nbsp;要么是&nbsp;<code>1</code>&nbsp;。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

我们逐行处理，对于第 $i$ 行，最后一个 $1$ 所在的位置必须小于等于 $i$，我们在 $[i, n)$ 中找到第一个满足条件的行，记为 $k$。然后从第 $k$ 行开始，依次向上交换相邻的两行，直到第 $i$ 行。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 是网格的边长。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minSwaps(self, grid: List[List[int]]) -> int:
        n = len(grid)
        pos = [-1] * n
        for i in range(n):
            for j in range(n - 1, -1, -1):
                if grid[i][j] == 1:
                    pos[i] = j
                    break
        ans = 0
        for i in range(n):
            k = -1
            for j in range(i, n):
                if pos[j] <= i:
                    ans += j - i
                    k = j
                    break
            if k == -1:
                return -1
            while k > i:
                pos[k], pos[k - 1] = pos[k - 1], pos[k]
                k -= 1
        return ans
```

#### Java

```java
class Solution {
    public int minSwaps(int[][] grid) {
        int n = grid.length;
        int[] pos = new int[n];
        Arrays.fill(pos, -1);
        for (int i = 0; i < n; ++i) {
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == 1) {
                    pos[i] = j;
                    break;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int k = -1;
            for (int j = i; j < n; ++j) {
                if (pos[j] <= i) {
                    ans += j - i;
                    k = j;
                    break;
                }
            }
            if (k == -1) {
                return -1;
            }
            for (; k > i; --k) {
                int t = pos[k];
                pos[k] = pos[k - 1];
                pos[k - 1] = t;
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
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> pos(n, -1);
        for (int i = 0; i < n; ++i) {
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == 1) {
                    pos[i] = j;
                    break;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int k = -1;
            for (int j = i; j < n; ++j) {
                if (pos[j] <= i) {
                    ans += j - i;
                    k = j;
                    break;
                }
            }
            if (k == -1) {
                return -1;
            }
            for (; k > i; --k) {
                swap(pos[k], pos[k - 1]);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minSwaps(grid [][]int) (ans int) {
	n := len(grid)
	pos := make([]int, n)
	for i := range pos {
		pos[i] = -1
	}
	for i := 0; i < n; i++ {
		for j := n - 1; j >= 0; j-- {
			if grid[i][j] == 1 {
				pos[i] = j
				break
			}
		}
	}
	for i := 0; i < n; i++ {
		k := -1
		for j := i; j < n; j++ {
			if pos[j] <= i {
				ans += j - i
				k = j
				break
			}
		}
		if k == -1 {
			return -1
		}
		for ; k > i; k-- {
			pos[k], pos[k-1] = pos[k-1], pos[k]
		}
	}
	return
}
```

#### TypeScript

```ts
function minSwaps(grid: number[][]): number {
    const n = grid.length;
    const pos: number[] = Array(n).fill(-1);
    for (let i = 0; i < n; ++i) {
        for (let j = n - 1; ~j; --j) {
            if (grid[i][j] === 1) {
                pos[i] = j;
                break;
            }
        }
    }
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        let k = -1;
        for (let j = i; j < n; ++j) {
            if (pos[j] <= i) {
                ans += j - i;
                k = j;
                break;
            }
        }
        if (k === -1) {
            return -1;
        }
        for (; k > i; --k) {
            [pos[k], pos[k - 1]] = [pos[k - 1], pos[k]];
        }
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1537. 最大得分](https://leetcode.cn/problems/get-the-maximum-score){#1537}

{{< tabs "1537" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxSum(self, nums1: List[int], nums2: List[int]) -> int:
        mod = 10**9 + 7
        m, n = len(nums1), len(nums2)
        i = j = 0
        f = g = 0
        while i < m or j < n:
            if i == m:
                g += nums2[j]
                j += 1
            elif j == n:
                f += nums1[i]
                i += 1
            elif nums1[i] < nums2[j]:
                f += nums1[i]
                i += 1
            elif nums1[i] > nums2[j]:
                g += nums2[j]
                j += 1
            else:
                f = g = max(f, g) + nums1[i]
                i += 1
                j += 1
        return max(f, g) % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxSum(int[] nums1, int[] nums2) {
        final int mod = (int) 1e9 + 7;
        int m = nums1.length, n = nums2.length;
        int i = 0, j = 0;
        long f = 0, g = 0;
        while (i < m || j < n) {
            if (i == m) {
                g += nums2[j++];
            } else if (j == n) {
                f += nums1[i++];
            } else if (nums1[i] < nums2[j]) {
                f += nums1[i++];
            } else if (nums1[i] > nums2[j]) {
                g += nums2[j++];
            } else {
                f = g = Math.max(f, g) + nums1[i];
                i++;
                j++;
            }
        }
        return (int) (Math.max(f, g) % mod);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        const int mod = 1e9 + 7;
        int m = nums1.size(), n = nums2.size();
        int i = 0, j = 0;
        long long f = 0, g = 0;
        while (i < m || j < n) {
            if (i == m) {
                g += nums2[j++];
            } else if (j == n) {
                f += nums1[i++];
            } else if (nums1[i] < nums2[j]) {
                f += nums1[i++];
            } else if (nums1[i] > nums2[j]) {
                g += nums2[j++];
            } else {
                f = g = max(f, g) + nums1[i];
                i++;
                j++;
            }
        }
        return max(f, g) % mod;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxSum(nums1 []int, nums2 []int) int {
	const mod int = 1e9 + 7
	m, n := len(nums1), len(nums2)
	i, j := 0, 0
	f, g := 0, 0
	for i < m || j < n {
		if i == m {
			g += nums2[j]
			j++
		} else if j == n {
			f += nums1[i]
			i++
		} else if nums1[i] < nums2[j] {
			f += nums1[i]
			i++
		} else if nums1[i] > nums2[j] {
			g += nums2[j]
			j++
		} else {
			f = max(f, g) + nums1[i]
			g = f
			i++
			j++
		}
	}
	return max(f, g) % mod
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxSum(nums1: number[], nums2: number[]): number {
    const mod = 1e9 + 7;
    const m = nums1.length;
    const n = nums2.length;
    let [f, g] = [0, 0];
    let [i, j] = [0, 0];
    while (i < m || j < n) {
        if (i === m) {
            g += nums2[j++];
        } else if (j === n) {
            f += nums1[i++];
        } else if (nums1[i] < nums2[j]) {
            f += nums1[i++];
        } else if (nums1[i] > nums2[j]) {
            g += nums2[j++];
        } else {
            f = g = Math.max(f, g) + nums1[i];
            i++;
            j++;
        }
    }
    return Math.max(f, g) % mod;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你有两个 <strong>有序</strong>&nbsp;且数组内元素互不相同的数组&nbsp;<code>nums1</code> 和&nbsp;<code>nums2</code>&nbsp;。</p>

<p>一条&nbsp;<strong>合法路径</strong>&nbsp;定义如下：</p>

<ul>
	<li>选择数组 <code>nums1</code> 或者 <code>nums2</code> 开始遍历（从下标 0 处开始）。</li>
	<li>从左到右遍历当前数组。</li>
	<li>如果你遇到了 <code>nums1</code>&nbsp;和 <code>nums2</code>&nbsp;中都存在的值，那么你可以切换路径到另一个数组对应数字处继续遍历（但在合法路径中重复数字只会被统计一次）。</li>
</ul>

<p><strong>得分</strong> 定义为合法路径中不同数字的和。</p>

<p>请你返回 <em>所有可能 <strong>合法路径</strong> 中的最大得分。</em>由于答案可能很大，请你将它对 10^9 + 7 取余后返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1537.Get%20the%20Maximum%20Score/images/sample_1_1893.png" style="height: 163px; width: 538px;" /></strong></p>

<pre>
<strong>输入：</strong>nums1 = [2,4,5,8,10], nums2 = [4,6,8,9]
<strong>输出：</strong>30
<strong>解释：</strong>合法路径包括：
[2,4,5,8,10], [2,4,5,8,9], [2,4,6,8,9], [2,4,6,8,10],（从 nums1 开始遍历）
[4,6,8,9], [4,5,8,10], [4,5,8,9], [4,6,8,10]  （从 nums2 开始遍历）
最大得分为上图中的绿色路径 <strong>[2,4,6,8,10]</strong>&nbsp;。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [1,3,5,7,9], nums2 = [3,5,100]
<strong>输出：</strong>109
<strong>解释：</strong>最大得分由路径 <strong>[1,3,5,100]</strong> 得到。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [1,2,3,4,5], nums2 = [6,7,8,9,10]
<strong>输出：</strong>40
<strong>解释：</strong>nums1 和 nums2 之间无相同数字。
最大得分由路径[6,7,8,9,10]得到。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length, nums2.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums1[i], nums2[i] &lt;= 10<sup>7</sup></code></li>
	<li><code>nums1</code> 和&nbsp;<code>nums2</code>&nbsp;都是严格递增的数组。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxSum(self, nums1: List[int], nums2: List[int]) -> int:
        mod = 10**9 + 7
        m, n = len(nums1), len(nums2)
        i = j = 0
        f = g = 0
        while i < m or j < n:
            if i == m:
                g += nums2[j]
                j += 1
            elif j == n:
                f += nums1[i]
                i += 1
            elif nums1[i] < nums2[j]:
                f += nums1[i]
                i += 1
            elif nums1[i] > nums2[j]:
                g += nums2[j]
                j += 1
            else:
                f = g = max(f, g) + nums1[i]
                i += 1
                j += 1
        return max(f, g) % mod
```

#### Java

```java
class Solution {
    public int maxSum(int[] nums1, int[] nums2) {
        final int mod = (int) 1e9 + 7;
        int m = nums1.length, n = nums2.length;
        int i = 0, j = 0;
        long f = 0, g = 0;
        while (i < m || j < n) {
            if (i == m) {
                g += nums2[j++];
            } else if (j == n) {
                f += nums1[i++];
            } else if (nums1[i] < nums2[j]) {
                f += nums1[i++];
            } else if (nums1[i] > nums2[j]) {
                g += nums2[j++];
            } else {
                f = g = Math.max(f, g) + nums1[i];
                i++;
                j++;
            }
        }
        return (int) (Math.max(f, g) % mod);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        const int mod = 1e9 + 7;
        int m = nums1.size(), n = nums2.size();
        int i = 0, j = 0;
        long long f = 0, g = 0;
        while (i < m || j < n) {
            if (i == m) {
                g += nums2[j++];
            } else if (j == n) {
                f += nums1[i++];
            } else if (nums1[i] < nums2[j]) {
                f += nums1[i++];
            } else if (nums1[i] > nums2[j]) {
                g += nums2[j++];
            } else {
                f = g = max(f, g) + nums1[i];
                i++;
                j++;
            }
        }
        return max(f, g) % mod;
    }
};
```

#### Go

```go
func maxSum(nums1 []int, nums2 []int) int {
	const mod int = 1e9 + 7
	m, n := len(nums1), len(nums2)
	i, j := 0, 0
	f, g := 0, 0
	for i < m || j < n {
		if i == m {
			g += nums2[j]
			j++
		} else if j == n {
			f += nums1[i]
			i++
		} else if nums1[i] < nums2[j] {
			f += nums1[i]
			i++
		} else if nums1[i] > nums2[j] {
			g += nums2[j]
			j++
		} else {
			f = max(f, g) + nums1[i]
			g = f
			i++
			j++
		}
	}
	return max(f, g) % mod
}
```

#### TypeScript

```ts
function maxSum(nums1: number[], nums2: number[]): number {
    const mod = 1e9 + 7;
    const m = nums1.length;
    const n = nums2.length;
    let [f, g] = [0, 0];
    let [i, j] = [0, 0];
    while (i < m || j < n) {
        if (i === m) {
            g += nums2[j++];
        } else if (j === n) {
            f += nums1[i++];
        } else if (nums1[i] < nums2[j]) {
            f += nums1[i++];
        } else if (nums1[i] > nums2[j]) {
            g += nums2[j++];
        } else {
            f = g = Math.max(f, g) + nums1[i];
            i++;
            j++;
        }
    }
    return Math.max(f, g) % mod;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1538. 找出隐藏数组中出现次数最多的元素 🔒](https://leetcode.cn/problems/guess-the-majority-in-a-hidden-array){#1538}

{{< tabs "1538" >}}

{{% tab "python" %}}
```python
# """
# This is the ArrayReader's API interface.
# You should not implement it, or speculate about its implementation
# """
# class ArrayReader(object):
# 	 # Compares 4 different elements in the array
# 	 # return 4 if the values of the 4 elements are the same (0 or 1).
# 	 # return 2 if three elements have a value equal to 0 and one element has value equal to 1 or vice versa.
# 	 # return 0 : if two element have a value equal to 0 and two elements have a value equal to 1.
#    def query(self, a: int, b: int, c: int, d: int) -> int:
#
# 	 # Returns the length of the array
#    def length(self) -> int:
#


class Solution:
    def guessMajority(self, reader: "ArrayReader") -> int:
        n = reader.length()
        x = reader.query(0, 1, 2, 3)
        a, b = 1, 0
        k = 0
        for i in range(4, n):
            if reader.query(0, 1, 2, i) == x:
                a += 1
            else:
                b += 1
                k = i

        y = reader.query(0, 1, 2, 4)
        if reader.query(1, 2, 3, 4) == y:
            a += 1
        else:
            b += 1
            k = 0
        if reader.query(0, 2, 3, 4) == y:
            a += 1
        else:
            b += 1
            k = 1
        if reader.query(0, 1, 3, 4) == y:
            a += 1
        else:
            b += 1
            k = 2

        if a == b:
            return -1
        return 3 if a > b else k
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface ArrayReader {
 *   public:
 *     // Compares 4 different elements in the array
 *     // return 4 if the values of the 4 elements are the same (0 or 1).
 *     // return 2 if three elements have a value equal to 0 and one element has value equal to 1 or
 * vice versa.
 *     // return 0 : if two element have a value equal to 0 and two elements have a value equal
 * to 1. public int query(int a, int b, int c, int d);
 *
 *     // Returns the length of the array
 *     public int length();
 * };
 */

class Solution {
    public int guessMajority(ArrayReader reader) {
        int n = reader.length();
        int x = reader.query(0, 1, 2, 3);
        int a = 1, b = 0;
        int k = 0;
        for (int i = 4; i < n; ++i) {
            if (reader.query(0, 1, 2, i) == x) {
                ++a;
            } else {
                ++b;
                k = i;
            }
        }

        int y = reader.query(0, 1, 2, 4);
        if (reader.query(1, 2, 3, 4) == y) {
            ++a;
        } else {
            ++b;
            k = 0;
        }
        if (reader.query(0, 2, 3, 4) == y) {
            ++a;
        } else {
            ++b;
            k = 1;
        }
        if (reader.query(0, 1, 3, 4) == y) {
            ++a;
        } else {
            ++b;
            k = 2;
        }
        if (a == b) {
            return -1;
        }
        return a > b ? 3 : k;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares 4 different elements in the array
 *     // return 4 if the values of the 4 elements are the same (0 or 1).
 *     // return 2 if three elements have a value equal to 0 and one element has value equal to 1 or vice versa.
 *     // return 0 : if two element have a value equal to 0 and two elements have a value equal to 1.
 *     int query(int a, int b, int c, int d);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:
    int guessMajority(ArrayReader& reader) {
        int n = reader.length();
        int x = reader.query(0, 1, 2, 3);
        int a = 1, b = 0;
        int k = 0;
        for (int i = 4; i < n; ++i) {
            if (reader.query(0, 1, 2, i) == x) {
                ++a;
            } else {
                ++b;
                k = i;
            }
        }

        int y = reader.query(0, 1, 2, 4);
        if (reader.query(1, 2, 3, 4) == y) {
            ++a;
        } else {
            ++b;
            k = 0;
        }
        if (reader.query(0, 2, 3, 4) == y) {
            ++a;
        } else {
            ++b;
            k = 1;
        }
        if (reader.query(0, 1, 3, 4) == y) {
            ++a;
        } else {
            ++b;
            k = 2;
        }
        if (a == b) {
            return -1;
        }
        return a > b ? 3 : k;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * type ArrayReader struct {
 * }
 * // Compares 4 different elements in the array
 * // return 4 if the values of the 4 elements are the same (0 or 1).
 * // return 2 if three elements have a value equal to 0 and one element has value equal to 1 or vice versa.
 * // return 0 : if two element have a value equal to 0 and two elements have a value equal to 1.
 * func (this *ArrayReader) query(a, b, c, d int) int {}
 *
 * // Returns the length of the array
 * func (this *ArrayReader) length() int {}
 */

func guessMajority(reader *ArrayReader) int {
	n := reader.length()
	x := reader.query(0, 1, 2, 3)
	a, b := 1, 0
	k := 0
	for i := 4; i < n; i++ {
		if reader.query(0, 1, 2, i) == x {
			a++
		} else {
			b++
			k = i
		}
	}

	y := reader.query(0, 1, 2, 4)
	if reader.query(1, 2, 3, 4) == y {
		a++
	} else {
		b++
		k = 0
	}
	if reader.query(0, 2, 3, 4) == y {
		a++
	} else {
		b++
		k = 1
	}
	if reader.query(0, 1, 3, 4) == y {
		a++
	} else {
		b++
		k = 2
	}
	if a == b {
		return -1
	}
	if a > b {
		return 3
	}
	return k
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *     // Compares 4 different elements in the array
 *     // return 4 if the values of the 4 elements are the same (0 or 1).
 *     // return 2 if three elements have a value equal to 0 and one element has value equal to 1 or vice versa.
 *     // return 0 : if two element have a value equal to 0 and two elements have a value equal to 1.
 *     query(a: number, b: number, c: number, d: number): number { };
 *
 *     // Returns the length of the array
 *     length(): number { };
 * };
 */

function guessMajority(reader: ArrayReader): number {
    const n = reader.length();
    const x = reader.query(0, 1, 2, 3);
    let a = 1;
    let b = 0;
    let k = 0;
    for (let i = 4; i < n; ++i) {
        if (reader.query(0, 1, 2, i) === x) {
            ++a;
        } else {
            ++b;
            k = i;
        }
    }
    const y = reader.query(0, 1, 2, 4);
    if (reader.query(1, 2, 3, 4) === y) {
        ++a;
    } else {
        ++b;
        k = 0;
    }
    if (reader.query(0, 2, 3, 4) === y) {
        ++a;
    } else {
        ++b;
        k = 1;
    }
    if (reader.query(0, 1, 3, 4) === y) {
        ++a;
    } else {
        ++b;
        k = 2;
    }
    if (a === b) {
        return -1;
    }
    return a > b ? 3 : k;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个整数数组&nbsp;<code>nums</code>，且&nbsp;<code>nums</code>&nbsp;中的所有整数都为 <strong>0</strong> 或 <strong>1</strong>。你不能直接访问这个数组，你需要使用&nbsp;API <code>ArrayReader</code>&nbsp;，该 API 含有下列成员函数：</p>

<ul>
	<li><code>int query(int a, int b, int c, int d)</code>：其中&nbsp;<code>0 &lt;= a &lt; b &lt; c &lt; d&nbsp;&lt;&nbsp;ArrayReader.length()</code>&nbsp;。此函数查询以这四个参数为下标的元素并返回：

    <ul>
    	<li><strong>4 </strong>: 当这四个元素相同（0 或 1）时。</li>
    	<li><strong>2</strong>&nbsp;: 当其中三个元素的值等于 0 且一个元素等于 1 时，或当其中三个元素的值等于 1&nbsp;且一个元素等于 0&nbsp;时。</li>
    	<li><strong>0&nbsp;</strong>: 当其中两个元素等于 0 且两个元素等于 1 时。</li>
    </ul>
    </li>
    <li><code>int length()</code>：返回数组的长度。</li>

</ul>

<p>你可以调用&nbsp;<code>query()</code>&nbsp;最多&nbsp;<strong>2 * n 次</strong>，其中 n 等于&nbsp;<code>ArrayReader.length()</code>。</p>

<p>返回&nbsp;<code>nums</code>&nbsp;中出现次数最多的值的<strong>任意</strong>索引，若所有的值出现次数均相同，返回&nbsp;-1。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入:</strong> nums = [0,0,1,0,1,1,1,1]
<strong>输出:</strong> 5
<strong>解释:</strong> API 的调用情况如下：
reader.length() // 返回 8，因为隐藏数组中有 8 个元素。
reader.query(0,1,2,3) // 返回 2，查询元素 nums[0], nums[1], nums[2], nums[3] 间的比较。
// 三个元素等于 0 且一个元素等于 1 或出现相反情况。
reader.query(4,5,6,7) // 返回 4，因为 nums[4], nums[5], nums[6], nums[7] 有相同值。
我们可以推断，最常出现的值在最后 4 个元素中。
索引 2, 4, 6, 7 也是正确答案。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> nums = [0,0,1,1,0]
<strong>输出:</strong> 0
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> nums = [1,0,1,0,1,0,1,0]
<strong>输出:</strong> -1
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>5 &lt;= nums.length&nbsp;&lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 1</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>要找到出现次数最多的元素，需要至少调用&nbsp;<code>query()</code>&nbsp;多少次？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：脑筋急转弯

我们先调用 `reader.query(0, 1, 2, 3)`，将得到的结果记为 $x$。

接下来，我们从下标 $4$ 开始遍历，每次调用 `reader.query(0, 1, 2, i)`，如果结果与 $x$ 相同，我们就将 $a$ 的值加一，否则将 $b$ 的值加一，同时将 $k$ 的值更新为 $i$。

然后，我们还需要判断下标 $0, 1, 2$ 与下标 $3$ 的元素是否相同，如果相同，我们将 $a$ 的值加一，否则将 $b$ 的值加一，同时将 $k$ 的值更新为对应的下标。

最后，如果 $a=b$，说明数组中 $0$ 和 $1$ 的个数相同，我们返回 $-1$；否则，如果 $a \gt b$，返回 $3$，否则返回 $k$。

时间复杂度 $O(n)$，其中 $n$ 是数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
# """
# This is the ArrayReader's API interface.
# You should not implement it, or speculate about its implementation
# """
# class ArrayReader(object):
# 	 # Compares 4 different elements in the array
# 	 # return 4 if the values of the 4 elements are the same (0 or 1).
# 	 # return 2 if three elements have a value equal to 0 and one element has value equal to 1 or vice versa.
# 	 # return 0 : if two element have a value equal to 0 and two elements have a value equal to 1.
#    def query(self, a: int, b: int, c: int, d: int) -> int:
#
# 	 # Returns the length of the array
#    def length(self) -> int:
#


class Solution:
    def guessMajority(self, reader: "ArrayReader") -> int:
        n = reader.length()
        x = reader.query(0, 1, 2, 3)
        a, b = 1, 0
        k = 0
        for i in range(4, n):
            if reader.query(0, 1, 2, i) == x:
                a += 1
            else:
                b += 1
                k = i

        y = reader.query(0, 1, 2, 4)
        if reader.query(1, 2, 3, 4) == y:
            a += 1
        else:
            b += 1
            k = 0
        if reader.query(0, 2, 3, 4) == y:
            a += 1
        else:
            b += 1
            k = 1
        if reader.query(0, 1, 3, 4) == y:
            a += 1
        else:
            b += 1
            k = 2

        if a == b:
            return -1
        return 3 if a > b else k
```

#### Java

```java
/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface ArrayReader {
 *   public:
 *     // Compares 4 different elements in the array
 *     // return 4 if the values of the 4 elements are the same (0 or 1).
 *     // return 2 if three elements have a value equal to 0 and one element has value equal to 1 or
 * vice versa.
 *     // return 0 : if two element have a value equal to 0 and two elements have a value equal
 * to 1. public int query(int a, int b, int c, int d);
 *
 *     // Returns the length of the array
 *     public int length();
 * };
 */

class Solution {
    public int guessMajority(ArrayReader reader) {
        int n = reader.length();
        int x = reader.query(0, 1, 2, 3);
        int a = 1, b = 0;
        int k = 0;
        for (int i = 4; i < n; ++i) {
            if (reader.query(0, 1, 2, i) == x) {
                ++a;
            } else {
                ++b;
                k = i;
            }
        }

        int y = reader.query(0, 1, 2, 4);
        if (reader.query(1, 2, 3, 4) == y) {
            ++a;
        } else {
            ++b;
            k = 0;
        }
        if (reader.query(0, 2, 3, 4) == y) {
            ++a;
        } else {
            ++b;
            k = 1;
        }
        if (reader.query(0, 1, 3, 4) == y) {
            ++a;
        } else {
            ++b;
            k = 2;
        }
        if (a == b) {
            return -1;
        }
        return a > b ? 3 : k;
    }
}
```

#### C++

```cpp
/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares 4 different elements in the array
 *     // return 4 if the values of the 4 elements are the same (0 or 1).
 *     // return 2 if three elements have a value equal to 0 and one element has value equal to 1 or vice versa.
 *     // return 0 : if two element have a value equal to 0 and two elements have a value equal to 1.
 *     int query(int a, int b, int c, int d);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:
    int guessMajority(ArrayReader& reader) {
        int n = reader.length();
        int x = reader.query(0, 1, 2, 3);
        int a = 1, b = 0;
        int k = 0;
        for (int i = 4; i < n; ++i) {
            if (reader.query(0, 1, 2, i) == x) {
                ++a;
            } else {
                ++b;
                k = i;
            }
        }

        int y = reader.query(0, 1, 2, 4);
        if (reader.query(1, 2, 3, 4) == y) {
            ++a;
        } else {
            ++b;
            k = 0;
        }
        if (reader.query(0, 2, 3, 4) == y) {
            ++a;
        } else {
            ++b;
            k = 1;
        }
        if (reader.query(0, 1, 3, 4) == y) {
            ++a;
        } else {
            ++b;
            k = 2;
        }
        if (a == b) {
            return -1;
        }
        return a > b ? 3 : k;
    }
};
```

#### Go

```go
/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * type ArrayReader struct {
 * }
 * // Compares 4 different elements in the array
 * // return 4 if the values of the 4 elements are the same (0 or 1).
 * // return 2 if three elements have a value equal to 0 and one element has value equal to 1 or vice versa.
 * // return 0 : if two element have a value equal to 0 and two elements have a value equal to 1.
 * func (this *ArrayReader) query(a, b, c, d int) int {}
 *
 * // Returns the length of the array
 * func (this *ArrayReader) length() int {}
 */

func guessMajority(reader *ArrayReader) int {
	n := reader.length()
	x := reader.query(0, 1, 2, 3)
	a, b := 1, 0
	k := 0
	for i := 4; i < n; i++ {
		if reader.query(0, 1, 2, i) == x {
			a++
		} else {
			b++
			k = i
		}
	}

	y := reader.query(0, 1, 2, 4)
	if reader.query(1, 2, 3, 4) == y {
		a++
	} else {
		b++
		k = 0
	}
	if reader.query(0, 2, 3, 4) == y {
		a++
	} else {
		b++
		k = 1
	}
	if reader.query(0, 1, 3, 4) == y {
		a++
	} else {
		b++
		k = 2
	}
	if a == b {
		return -1
	}
	if a > b {
		return 3
	}
	return k
}
```

#### TypeScript

```ts
/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *     // Compares 4 different elements in the array
 *     // return 4 if the values of the 4 elements are the same (0 or 1).
 *     // return 2 if three elements have a value equal to 0 and one element has value equal to 1 or vice versa.
 *     // return 0 : if two element have a value equal to 0 and two elements have a value equal to 1.
 *     query(a: number, b: number, c: number, d: number): number { };
 *
 *     // Returns the length of the array
 *     length(): number { };
 * };
 */

function guessMajority(reader: ArrayReader): number {
    const n = reader.length();
    const x = reader.query(0, 1, 2, 3);
    let a = 1;
    let b = 0;
    let k = 0;
    for (let i = 4; i < n; ++i) {
        if (reader.query(0, 1, 2, i) === x) {
            ++a;
        } else {
            ++b;
            k = i;
        }
    }
    const y = reader.query(0, 1, 2, 4);
    if (reader.query(1, 2, 3, 4) === y) {
        ++a;
    } else {
        ++b;
        k = 0;
    }
    if (reader.query(0, 2, 3, 4) === y) {
        ++a;
    } else {
        ++b;
        k = 1;
    }
    if (reader.query(0, 1, 3, 4) === y) {
        ++a;
    } else {
        ++b;
        k = 2;
    }
    if (a === b) {
        return -1;
    }
    return a > b ? 3 : k;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1539. 第 k 个缺失的正整数](https://leetcode.cn/problems/kth-missing-positive-number){#1539}

{{< tabs "1539" >}}

{{% tab "python" %}}
```python
class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        if arr[0] > k:
            return k
        left, right = 0, len(arr)
        while left < right:
            mid = (left + right) >> 1
            if arr[mid] - mid - 1 >= k:
                right = mid
            else:
                left = mid + 1
        return arr[left - 1] + k - (arr[left - 1] - (left - 1) - 1)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findKthPositive(int[] arr, int k) {
        if (arr[0] > k) {
            return k;
        }
        int left = 0, right = arr.length;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (arr[mid] - mid - 1 >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return arr[left - 1] + k - (arr[left - 1] - (left - 1) - 1);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if (arr[0] > k) return k;
        int left = 0, right = arr.size();
        while (left < right) {
            int mid = (left + right) >> 1;
            if (arr[mid] - mid - 1 >= k)
                right = mid;
            else
                left = mid + 1;
        }
        return arr[left - 1] + k - (arr[left - 1] - (left - 1) - 1);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findKthPositive(arr []int, k int) int {
	if arr[0] > k {
		return k
	}
	left, right := 0, len(arr)
	for left < right {
		mid := (left + right) >> 1
		if arr[mid]-mid-1 >= k {
			right = mid
		} else {
			left = mid + 1
		}
	}
	return arr[left-1] + k - (arr[left-1] - (left - 1) - 1)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 <strong>严格升序排列</strong>&nbsp;的正整数数组 <code>arr</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;。</p>

<p>请你找到这个数组里第&nbsp;<code>k</code>&nbsp;个缺失的正整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr = [2,3,4,7,11], k = 5
<strong>输出：</strong>9
<strong>解释：</strong>缺失的正整数包括 [1,5,6,8,9,10,12,13,...] 。第 5 个缺失的正整数为 9 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr = [1,2,3,4], k = 2
<strong>输出：</strong>6
<strong>解释：</strong>缺失的正整数包括 [5,6,7,...] 。第 2 个缺失的正整数为 6 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 1000</code></li>
	<li><code>1 &lt;= arr[i] &lt;= 1000</code></li>
	<li><code>1 &lt;= k &lt;= 1000</code></li>
	<li>对于所有&nbsp;<code>1 &lt;= i &lt; j &lt;= arr.length</code>&nbsp;的 <code>i</code>&nbsp;和 <code>j</code> 满足&nbsp;<code>arr[i] &lt; arr[j]</code>&nbsp;</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong></p>

<p>你可以设计一个时间复杂度小于 O(n) 的算法解决此问题吗？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        if arr[0] > k:
            return k
        left, right = 0, len(arr)
        while left < right:
            mid = (left + right) >> 1
            if arr[mid] - mid - 1 >= k:
                right = mid
            else:
                left = mid + 1
        return arr[left - 1] + k - (arr[left - 1] - (left - 1) - 1)
```

#### Java

```java
class Solution {
    public int findKthPositive(int[] arr, int k) {
        if (arr[0] > k) {
            return k;
        }
        int left = 0, right = arr.length;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (arr[mid] - mid - 1 >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return arr[left - 1] + k - (arr[left - 1] - (left - 1) - 1);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if (arr[0] > k) return k;
        int left = 0, right = arr.size();
        while (left < right) {
            int mid = (left + right) >> 1;
            if (arr[mid] - mid - 1 >= k)
                right = mid;
            else
                left = mid + 1;
        }
        return arr[left - 1] + k - (arr[left - 1] - (left - 1) - 1);
    }
};
```

#### Go

```go
func findKthPositive(arr []int, k int) int {
	if arr[0] > k {
		return k
	}
	left, right := 0, len(arr)
	for left < right {
		mid := (left + right) >> 1
		if arr[mid]-mid-1 >= k {
			right = mid
		} else {
			left = mid + 1
		}
	}
	return arr[left-1] + k - (arr[left-1] - (left - 1) - 1)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
