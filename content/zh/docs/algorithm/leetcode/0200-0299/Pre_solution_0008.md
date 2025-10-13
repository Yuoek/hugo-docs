---
title: "0270_最接近的二叉搜索树值 🔒"
date: 2025-10-08T18:35:28+08:00
weight: 8
tags: [二分查找, 二叉搜索树, 二叉树, 交互, 动态规划, 双指针, 图, 堆（优先队列）, 字符串, 广度优先搜索, 排序, 数学, 数组, 栈, 树, 深度优先搜索, 计数排序, 设计, 递归]
---

{{< markmap >}}
### [0270_最接近的二叉搜索树值 🔒](#270)
#### [树](#270)
#### [深度优先搜索](#270)
#### [二叉搜索树](#270)
#### [二分查找](#270)
#### [二叉树](#270)
### [0271_字符串的编码与解码 🔒](#271)
#### [设计](#271)
#### [数组](#271)
#### [字符串](#271)
### [0272_最接近的二叉搜索树值 II 🔒](#272)
#### [栈](#272)
#### [树](#272)
#### [深度优先搜索](#272)
#### [二叉搜索树](#272)
#### [双指针](#272)
#### [二叉树](#272)
#### [堆（优先队列）](#272)
### [0273_整数转换英文表示](#273)
#### [递归](#273)
#### [数学](#273)
#### [字符串](#273)
### [0274_H 指数](#274)
#### [数组](#274)
#### [计数排序](#274)
#### [排序](#274)
### [0275_H 指数 II](#275)
#### [数组](#275)
#### [二分查找](#275)
### [0276_栅栏涂色 🔒](#276)
#### [动态规划](#276)
### [0277_搜寻名人 🔒](#277)
#### [图](#277)
#### [双指针](#277)
#### [交互](#277)
### [0278_第一个错误的版本](#278)
#### [二分查找](#278)
#### [交互](#278)
### [0279_完全平方数](#279)
#### [广度优先搜索](#279)
#### [数学](#279)
#### [动态规划](#279)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0270_最接近的二叉搜索树值 🔒
___
#### 树
___
#### 深度优先搜索
___
#### 二叉搜索树
___
#### 二分查找
___
#### 二叉树
---
### 0271_字符串的编码与解码 🔒
___
#### 设计
___
#### 数组
___
#### 字符串
---
### 0272_最接近的二叉搜索树值 II 🔒
___
#### 栈
___
#### 树
___
#### 深度优先搜索
___
#### 二叉搜索树
___
#### 双指针
___
#### 二叉树
___
#### 堆（优先队列）
---
### 0273_整数转换英文表示
___
#### 递归
___
#### 数学
___
#### 字符串
---
### 0274_H 指数
___
#### 数组
___
#### 计数排序
___
#### 排序
---
### 0275_H 指数 II
___
#### 数组
___
#### 二分查找
---
### 0276_栅栏涂色 🔒
___
#### 动态规划
---
### 0277_搜寻名人 🔒
___
#### 图
___
#### 双指针
___
#### 交互
---
### 0278_第一个错误的版本
___
#### 二分查找
___
#### 交互
---
### 0279_完全平方数
___
#### 广度优先搜索
___
#### 数学
___
#### 动态规划
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉搜索树 | 二叉树 |
| 交互 | 动态规划 | 双指针 |
| 图 | 堆（优先队列） | 字符串 |
| 广度优先搜索 | 排序 | 数学 |
| 数组 | 栈 | 树 |
| 深度优先搜索 | 计数排序 | 设计 |
| 递归 |  |  |

# [270. 最接近的二叉搜索树值 🔒](https://leetcode.cn/problems/closest-binary-search-tree-value){#270}

{{< tabs "270" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def closestValue(self, root: Optional[TreeNode], target: float) -> int:
        ans, diff = root.val, inf
        while root:
            nxt = abs(root.val - target)
            if nxt < diff or (nxt == diff and root.val < ans):
                diff = nxt
                ans = root.val
            root = root.left if target < root.val else root.right
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
    public int closestValue(TreeNode root, double target) {
        int ans = root.val;
        double diff = Double.MAX_VALUE;
        while (root != null) {
            double nxt = Math.abs(root.val - target);
            if (nxt < diff || (nxt == diff && root.val < ans)) {
                diff = nxt;
                ans = root.val;
            }
            root = target < root.val ? root.left : root.right;
        }
        return ans;
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
    int closestValue(TreeNode* root, double target) {
        int ans = root->val;
        double diff = INT_MAX;
        while (root) {
            double nxt = abs(root->val - target);
            if (nxt < diff || (nxt == diff && root->val < ans)) {
                diff = nxt;
                ans = root->val;
            }
            root = target < root->val ? root->left : root->right;
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
func closestValue(root *TreeNode, target float64) int {
	ans := root.Val
	diff := math.MaxFloat64
	for root != nil {
		nxt := math.Abs(float64(root.Val) - target)
		if nxt < diff || (nxt == diff && root.Val < ans) {
			diff = nxt
			ans = root.Val
		}
		if float64(root.Val) > target {
			root = root.Left
		} else {
			root = root.Right
		}
	}
	return ans
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

function closestValue(root: TreeNode | null, target: number): number {
    let ans = 0;
    let diff = Number.POSITIVE_INFINITY;

    while (root) {
        const nxt = Math.abs(root.val - target);
        if (nxt < diff || (nxt === diff && root.val < ans)) {
            diff = nxt;
            ans = root.val;
        }
        root = target < root.val ? root.left : root.right;
    }
    return ans;
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
 * @param {number} target
 * @return {number}
 */
var closestValue = function (root, target) {
    let ans = root.val;
    let diff = Infinity;
    while (root) {
        const nxt = Math.abs(root.val - target);
        if (nxt < diff || (nxt === diff && root.val < ans)) {
            diff = nxt;
            ans = root.val;
        }
        root = target < root.val ? root.left : root.right;
    }
    return ans;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

给你二叉搜索树的根节点 <code>root</code> 和一个目标值 <code>target</code> ，请在该二叉搜索树中找到最接近目标值 <code>target</code> 的数值。如果有多个答案，返回最小的那个。

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0200-0299/0270.Closest%20Binary%20Search%20Tree%20Value/images/closest1-1-tree.jpg" style="width: 292px; height: 302px;" />
<pre>
<strong>输入：</strong>root = [4,2,5,1,3], target = 3.714286
<strong>输出：</strong>4
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>root = [1], target = 4.428571
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点的数目在范围 <code>[1, 10<sup>4</sup>]</code> 内</li>
	<li><code>0 &lt;= Node.val &lt;= 10<sup>9</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= target &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归

我们定义一个递归函数 $\textit{dfs}(node)$，表示从当前节点 $node$ 开始，寻找最接近目标值 $target$ 的节点。我们可以通过比较当前节点的值与目标值的差的绝对值，来更新答案，如果目标值小于当前节点的值，我们就递归地搜索左子树，否则我们递归地搜索右子树。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是二叉搜索树的节点数。

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
    def closestValue(self, root: Optional[TreeNode], target: float) -> int:
        def dfs(node: Optional[TreeNode]):
            if node is None:
                return
            nxt = abs(target - node.val)
            nonlocal ans, diff
            if nxt < diff or (nxt == diff and node.val < ans):
                diff = nxt
                ans = node.val
            node = node.left if target < node.val else node.right
            dfs(node)

        ans = 0
        diff = inf
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
    private int ans;
    private double target;
    private double diff = Double.MAX_VALUE;

    public int closestValue(TreeNode root, double target) {
        this.target = target;
        dfs(root);
        return ans;
    }

    private void dfs(TreeNode node) {
        if (node == null) {
            return;
        }
        double nxt = Math.abs(node.val - target);
        if (nxt < diff || (nxt == diff && node.val < ans)) {
            diff = nxt;
            ans = node.val;
        }
        node = target < node.val ? node.left : node.right;
        dfs(node);
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
    int closestValue(TreeNode* root, double target) {
        int ans = root->val;
        double diff = INT_MAX;
        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if (!node) {
                return;
            }
            double nxt = abs(node->val - target);
            if (nxt < diff || (nxt == diff && node->val < ans)) {
                diff = nxt;
                ans = node->val;
            }
            node = target < node->val ? node->left : node->right;
            dfs(node);
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
func closestValue(root *TreeNode, target float64) int {
	ans := root.Val
	diff := math.MaxFloat64
	var dfs func(*TreeNode)
	dfs = func(node *TreeNode) {
		if node == nil {
			return
		}
		nxt := math.Abs(float64(node.Val) - target)
		if nxt < diff || (nxt == diff && node.Val < ans) {
			diff = nxt
			ans = node.Val
		}
		if target < float64(node.Val) {
			dfs(node.Left)
		} else {
			dfs(node.Right)
		}
	}
	dfs(root)
	return ans
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

function closestValue(root: TreeNode | null, target: number): number {
    let ans = 0;
    let diff = Number.POSITIVE_INFINITY;

    const dfs = (node: TreeNode | null): void => {
        if (!node) {
            return;
        }

        const nxt = Math.abs(target - node.val);
        if (nxt < diff || (nxt === diff && node.val < ans)) {
            diff = nxt;
            ans = node.val;
        }

        node = target < node.val ? node.left : node.right;
        dfs(node);
    };

    dfs(root);
    return ans;
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
 * @param {number} target
 * @return {number}
 */
var closestValue = function (root, target) {
    let ans = 0;
    let diff = Infinity;

    const dfs = node => {
        if (!node) {
            return;
        }

        const nxt = Math.abs(target - node.val);
        if (nxt < diff || (nxt === diff && node.val < ans)) {
            diff = nxt;
            ans = node.val;
        }

        node = target < node.val ? node.left : node.right;
        dfs(node);
    };

    dfs(root);
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：迭代

我们可以将递归函数改写为迭代的形式，使用一个循环来模拟递归的过程。我们从根节点开始，判断当前节点的值与目标值的差的绝对值是否小于当前的最小差，如果是，我们就更新答案。然后根据目标值与当前节点的值的大小关系，决定向左子树还是右子树移动。当我们遍历到空节点时，循环结束。

时间复杂度 $O(n)$，其中 $n$ 是二叉搜索树的节点数。空间复杂度 $O(1)$。

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
    def closestValue(self, root: Optional[TreeNode], target: float) -> int:
        ans, diff = root.val, inf
        while root:
            nxt = abs(root.val - target)
            if nxt < diff or (nxt == diff and root.val < ans):
                diff = nxt
                ans = root.val
            root = root.left if target < root.val else root.right
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
    public int closestValue(TreeNode root, double target) {
        int ans = root.val;
        double diff = Double.MAX_VALUE;
        while (root != null) {
            double nxt = Math.abs(root.val - target);
            if (nxt < diff || (nxt == diff && root.val < ans)) {
                diff = nxt;
                ans = root.val;
            }
            root = target < root.val ? root.left : root.right;
        }
        return ans;
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
    int closestValue(TreeNode* root, double target) {
        int ans = root->val;
        double diff = INT_MAX;
        while (root) {
            double nxt = abs(root->val - target);
            if (nxt < diff || (nxt == diff && root->val < ans)) {
                diff = nxt;
                ans = root->val;
            }
            root = target < root->val ? root->left : root->right;
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
func closestValue(root *TreeNode, target float64) int {
	ans := root.Val
	diff := math.MaxFloat64
	for root != nil {
		nxt := math.Abs(float64(root.Val) - target)
		if nxt < diff || (nxt == diff && root.Val < ans) {
			diff = nxt
			ans = root.Val
		}
		if float64(root.Val) > target {
			root = root.Left
		} else {
			root = root.Right
		}
	}
	return ans
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

function closestValue(root: TreeNode | null, target: number): number {
    let ans = 0;
    let diff = Number.POSITIVE_INFINITY;

    while (root) {
        const nxt = Math.abs(root.val - target);
        if (nxt < diff || (nxt === diff && root.val < ans)) {
            diff = nxt;
            ans = root.val;
        }
        root = target < root.val ? root.left : root.right;
    }
    return ans;
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
 * @param {number} target
 * @return {number}
 */
var closestValue = function (root, target) {
    let ans = root.val;
    let diff = Infinity;
    while (root) {
        const nxt = Math.abs(root.val - target);
        if (nxt < diff || (nxt === diff && root.val < ans)) {
            diff = nxt;
            ans = root.val;
        }
        root = target < root.val ? root.left : root.right;
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [271. 字符串的编码与解码 🔒](https://leetcode.cn/problems/encode-and-decode-strings){#271}

{{< tabs "271" >}}

{{% tab "python" %}}
```python
class Codec:
    def encode(self, strs: List[str]) -> str:
        """Encodes a list of strings to a single string."""
        ans = []
        for s in strs:
            ans.append('{:4}'.format(len(s)) + s)
        return ''.join(ans)

    def decode(self, s: str) -> List[str]:
        """Decodes a single string to a list of strings."""
        ans = []
        i, n = 0, len(s)
        while i < n:
            size = int(s[i : i + 4])
            i += 4
            ans.append(s[i : i + size])
            i += size
        return ans


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(strs))
```
{{% /tab %}}
{{% tab "java" %}}
```java
public class Codec {

    // Encodes a list of strings to a single string.
    public String encode(List<String> strs) {
        StringBuilder ans = new StringBuilder();
        for (String s : strs) {
            ans.append((char) s.length()).append(s);
        }
        return ans.toString();
    }

    // Decodes a single string to a list of strings.
    public List<String> decode(String s) {
        List<String> ans = new ArrayList<>();
        int i = 0, n = s.length();
        while (i < n) {
            int size = s.charAt(i++);
            ans.add(s.substring(i, i + size));
            i += size;
        }
        return ans;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(strs));
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ans;
        for (string s : strs) {
            int size = s.size();
            ans += string((const char*) &size, sizeof(size));
            ans += s;
        }
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0, n = s.size();
        int size = 0;
        while (i < n) {
            memcpy(&size, s.data() + i, sizeof(size));
            i += sizeof(size);
            ans.push_back(s.substr(i, size));
            i += size;
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Codec struct {
}

// Encodes a list of strings to a single string.
func (codec *Codec) Encode(strs []string) string {
	ans := &bytes.Buffer{}
	for _, s := range strs {
		t := fmt.Sprintf("%04d", len(s))
		ans.WriteString(t)
		ans.WriteString(s)
	}
	return ans.String()
}

// Decodes a single string to a list of strings.
func (codec *Codec) Decode(strs string) []string {
	ans := []string{}
	i, n := 0, len(strs)
	for i < n {
		t := strs[i : i+4]
		i += 4
		size, _ := strconv.Atoi(t)
		ans = append(ans, strs[i:i+size])
		i += size
	}
	return ans
}

// Your Codec object will be instantiated and called as such:
// var codec Codec
// codec.Decode(codec.Encode(strs));
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>请你设计一个算法，可以将一个&nbsp;<strong>字符串列表&nbsp;</strong>编码成为一个&nbsp;<strong>字符串</strong>。这个编码后的字符串是可以通过网络进行高效传送的，并且可以在接收端被解码回原来的字符串列表。</p>

<p>1 号机（发送方）有如下函数：</p>

<pre>
string encode(vector&lt;string&gt; strs) {
  // ... your code
  return encoded_string;
}</pre>

<p>2 号机（接收方）有如下函数：</p>

<pre>
vector&lt;string&gt; decode(string s) {
  //... your code
  return strs;
}
</pre>

<p>1 号机（发送方）执行：</p>

<pre>
string encoded_string = encode(strs);
</pre>

<p>2 号机（接收方）执行：</p>

<pre>
vector&lt;string&gt; strs2 = decode(encoded_string);
</pre>

<p>此时，2 号机（接收方）的 <code>strs2</code>&nbsp;需要和 1 号机（发送方）的 <code>strs</code> 相同。</p>

<p>请你来实现这个&nbsp;<code>encode</code> 和&nbsp;<code>decode</code> 方法。</p>

<p>不允许使用任何序列化方法解决这个问题（例如 <code>eval</code>）。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>dummy_input = ["Hello","World"]
<b>输出：</b>["Hello","World"]
<strong>解释：</strong>
1 号机：
Codec encoder = new Codec();
String msg = encoder.encode(strs);
Machine 1 ---msg---&gt; Machine 2

2 号机：
Codec decoder = new Codec();
String[] strs = decoder.decode(msg);
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>dummy_input = [""]
<b>输出：</b>[""]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= strs.length &lt;= 200</code></li>
	<li><code>0 &lt;= strs[i].length &lt;= 200</code></li>
	<li><code>strs[i]</code>&nbsp;包含 256 个有效 ASCII 字符中的任何可能字符。</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你能编写一个通用算法来处理任何可能的字符集吗？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：编码字符串长度

编码时，将字符串的长度转成固定 $4$ 位的字符串，加上字符串本身，依次拼接到结果字符串。

解码时，先取前四位字符串，得到长度，再通过长度截取后面的字符串。依次截取，最终得到字符串列表。

时间复杂度 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class Codec:
    def encode(self, strs: List[str]) -> str:
        """Encodes a list of strings to a single string."""
        ans = []
        for s in strs:
            ans.append('{:4}'.format(len(s)) + s)
        return ''.join(ans)

    def decode(self, s: str) -> List[str]:
        """Decodes a single string to a list of strings."""
        ans = []
        i, n = 0, len(s)
        while i < n:
            size = int(s[i : i + 4])
            i += 4
            ans.append(s[i : i + size])
            i += size
        return ans


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(strs))
```

#### Java

```java
public class Codec {

    // Encodes a list of strings to a single string.
    public String encode(List<String> strs) {
        StringBuilder ans = new StringBuilder();
        for (String s : strs) {
            ans.append((char) s.length()).append(s);
        }
        return ans.toString();
    }

    // Decodes a single string to a list of strings.
    public List<String> decode(String s) {
        List<String> ans = new ArrayList<>();
        int i = 0, n = s.length();
        while (i < n) {
            int size = s.charAt(i++);
            ans.add(s.substring(i, i + size));
            i += size;
        }
        return ans;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(strs));
```

#### C++

```cpp
class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ans;
        for (string s : strs) {
            int size = s.size();
            ans += string((const char*) &size, sizeof(size));
            ans += s;
        }
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0, n = s.size();
        int size = 0;
        while (i < n) {
            memcpy(&size, s.data() + i, sizeof(size));
            i += sizeof(size);
            ans.push_back(s.substr(i, size));
            i += size;
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
```

#### Go

```go
type Codec struct {
}

// Encodes a list of strings to a single string.
func (codec *Codec) Encode(strs []string) string {
	ans := &bytes.Buffer{}
	for _, s := range strs {
		t := fmt.Sprintf("%04d", len(s))
		ans.WriteString(t)
		ans.WriteString(s)
	}
	return ans.String()
}

// Decodes a single string to a list of strings.
func (codec *Codec) Decode(strs string) []string {
	ans := []string{}
	i, n := 0, len(strs)
	for i < n {
		t := strs[i : i+4]
		i += 4
		size, _ := strconv.Atoi(t)
		ans = append(ans, strs[i:i+size])
		i += size
	}
	return ans
}

// Your Codec object will be instantiated and called as such:
// var codec Codec
// codec.Decode(codec.Encode(strs));
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [272. 最接近的二叉搜索树值 II 🔒](https://leetcode.cn/problems/closest-binary-search-tree-value-ii){#272}

{{< tabs "272" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def closestKValues(self, root: TreeNode, target: float, k: int) -> List[int]:
        def dfs(root):
            if root is None:
                return
            dfs(root.left)
            if len(q) < k:
                q.append(root.val)
            else:
                if abs(root.val - target) >= abs(q[0] - target):
                    return
                q.popleft()
                q.append(root.val)
            dfs(root.right)

        q = deque()
        dfs(root)
        return list(q)
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

    private List<Integer> ans;
    private double target;
    private int k;

    public List<Integer> closestKValues(TreeNode root, double target, int k) {
        ans = new LinkedList<>();
        this.target = target;
        this.k = k;
        dfs(root);
        return ans;
    }

    private void dfs(TreeNode root) {
        if (root == null) {
            return;
        }
        dfs(root.left);
        if (ans.size() < k) {
            ans.add(root.val);
        } else {
            if (Math.abs(root.val - target) >= Math.abs(ans.get(0) - target)) {
                return;
            }
            ans.remove(0);
            ans.add(root.val);
        }
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
    queue<int> q;
    double target;
    int k;

    vector<int> closestKValues(TreeNode* root, double target, int k) {
        this->target = target;
        this->k = k;
        dfs(root);
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }

    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        if (q.size() < k)
            q.push(root->val);
        else {
            if (abs(root->val - target) >= abs(q.front() - target)) return;
            q.pop();
            q.push(root->val);
        }
        dfs(root->right);
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
func closestKValues(root *TreeNode, target float64, k int) []int {
	var ans []int
	var dfs func(root *TreeNode)
	dfs = func(root *TreeNode) {
		if root == nil {
			return
		}
		dfs(root.Left)
		if len(ans) < k {
			ans = append(ans, root.Val)
		} else {
			if math.Abs(float64(root.Val)-target) >= math.Abs(float64(ans[0])-target) {
				return
			}
			ans = ans[1:]
			ans = append(ans, root.Val)
		}
		dfs(root.Right)
	}
	dfs(root)
	return ans
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定二叉搜索树的根&nbsp;<code>root</code>&nbsp;、一个目标值&nbsp;<code>target</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;，返回BST中最接近目标的 <code>k</code> 个值。你可以按 <strong>任意顺序</strong> 返回答案。</p>

<p>题目&nbsp;<strong>保证</strong>&nbsp;该二叉搜索树中只会存在一种&nbsp;k 个值集合最接近&nbsp;<code>target</code></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0200-0299/0272.Closest%20Binary%20Search%20Tree%20Value%20II/images/closest1-1-tree.jpg" /></p>

<pre>
<strong>输入:</strong> root = [4,2,5,1,3]，目标值 = 3.714286，且 <em>k</em> = 2
<strong>输出:</strong> [4,3]</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> root = [1], target = 0.000000, k = 1
<strong>输出:</strong> [1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>二叉树的节点总数为&nbsp;<code>n</code></li>
	<li><code>1 &lt;= k &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= Node.val &lt;= 10<sup>9</sup></code></li>
	<li><code>-10<sup>9</sup>&nbsp;&lt;= target &lt;= 10<sup>9</sup></code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>假设该二叉搜索树是平衡的，请问您是否能在小于&nbsp;<code>O(n)</code>（&nbsp;<code>n = total nodes</code>&nbsp;）的时间复杂度内解决该问题呢？</p>

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
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def closestKValues(self, root: TreeNode, target: float, k: int) -> List[int]:
        def dfs(root):
            if root is None:
                return
            dfs(root.left)
            if len(q) < k:
                q.append(root.val)
            else:
                if abs(root.val - target) >= abs(q[0] - target):
                    return
                q.popleft()
                q.append(root.val)
            dfs(root.right)

        q = deque()
        dfs(root)
        return list(q)
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

    private List<Integer> ans;
    private double target;
    private int k;

    public List<Integer> closestKValues(TreeNode root, double target, int k) {
        ans = new LinkedList<>();
        this.target = target;
        this.k = k;
        dfs(root);
        return ans;
    }

    private void dfs(TreeNode root) {
        if (root == null) {
            return;
        }
        dfs(root.left);
        if (ans.size() < k) {
            ans.add(root.val);
        } else {
            if (Math.abs(root.val - target) >= Math.abs(ans.get(0) - target)) {
                return;
            }
            ans.remove(0);
            ans.add(root.val);
        }
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
    queue<int> q;
    double target;
    int k;

    vector<int> closestKValues(TreeNode* root, double target, int k) {
        this->target = target;
        this->k = k;
        dfs(root);
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }

    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        if (q.size() < k)
            q.push(root->val);
        else {
            if (abs(root->val - target) >= abs(q.front() - target)) return;
            q.pop();
            q.push(root->val);
        }
        dfs(root->right);
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
func closestKValues(root *TreeNode, target float64, k int) []int {
	var ans []int
	var dfs func(root *TreeNode)
	dfs = func(root *TreeNode) {
		if root == nil {
			return
		}
		dfs(root.Left)
		if len(ans) < k {
			ans = append(ans, root.Val)
		} else {
			if math.Abs(float64(root.Val)-target) >= math.Abs(float64(ans[0])-target) {
				return
			}
			ans = ans[1:]
			ans = append(ans, root.Val)
		}
		dfs(root.Right)
	}
	dfs(root)
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [273. 整数转换英文表示](https://leetcode.cn/problems/integer-to-english-words){#273}

{{< tabs "273" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberToWords(self, num: int) -> str:
        if num == 0:
            return 'Zero'

        lt20 = [
            '',
            'One',
            'Two',
            'Three',
            'Four',
            'Five',
            'Six',
            'Seven',
            'Eight',
            'Nine',
            'Ten',
            'Eleven',
            'Twelve',
            'Thirteen',
            'Fourteen',
            'Fifteen',
            'Sixteen',
            'Seventeen',
            'Eighteen',
            'Nineteen',
        ]
        tens = [
            '',
            'Ten',
            'Twenty',
            'Thirty',
            'Forty',
            'Fifty',
            'Sixty',
            'Seventy',
            'Eighty',
            'Ninety',
        ]
        thousands = ['Billion', 'Million', 'Thousand', '']

        def transfer(num):
            if num == 0:
                return ''
            if num < 20:
                return lt20[num] + ' '
            if num < 100:
                return tens[num // 10] + ' ' + transfer(num % 10)
            return lt20[num // 100] + ' Hundred ' + transfer(num % 100)

        res = []
        i, j = 1000000000, 0
        while i > 0:
            if num // i != 0:
                res.append(transfer(num // i))
                res.append(thousands[j])
                res.append(' ')
                num %= i
            j += 1
            i //= 1000
        return ''.join(res).strip()
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private String[] lt20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight",
        "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
        "Seventeen", "Eighteen", "Nineteen"};
    private String[] tens
        = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    private String[] thousands = {"Billion", "Million", "Thousand", ""};

    public String numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 1000000000, j = 0; i > 0; i /= 1000, ++j) {
            if (num / i == 0) {
                continue;
            }
            sb.append(transfer(num / i)).append(thousands[j]).append(' ');
            num %= i;
        }
        return sb.toString().trim();
    }

    private String transfer(int num) {
        if (num == 0) {
            return "";
        }
        if (num < 20) {
            return lt20[num] + " ";
        }
        if (num < 100) {
            return tens[num / 10] + " " + transfer(num % 10);
        }
        return lt20[num / 100] + " Hundred " + transfer(num % 100);
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
using System.Collections.Generic;
using System.Linq;

public class Solution {
    private string[] bases = { "Thousand", "Million", "Billion" };
    public string NumberToWords(int num) {
        if (num == 0)
        {
            return "Zero";
        }
        var baseIndex = -1;
        var parts = new List<string>();
        while (num > 0)
        {
            var part = NumberToWordsInternal(num % 1000);
            if (part.Length > 0 && baseIndex >= 0)
            {
                part = JoinParts(part, bases[baseIndex]);
            }
            parts.Add(part);
            baseIndex++;
            num /= 1000;
        }
        parts.Reverse();
        return JoinParts(parts);
    }

    private string JoinParts(IEnumerable<string> parts)
    {
        return string.Join(" ", parts.Where(p => p.Length > 0));
    }

    private string JoinParts(params string[] parts)
    {
        return JoinParts((IEnumerable<string>)parts);
    }

    private string NumberToWordsInternal(int num)
    {
        switch(num)
        {
            case 0: return "";
            case 1: return "One";
            case 2: return "Two";
            case 3: return "Three";
            case 4: return "Four";
            case 5: return "Five";
            case 6: return "Six";
            case 7: return "Seven";
            case 8: return "Eight";
            case 9: return "Nine";
            case 10: return "Ten";
            case 11: return "Eleven";
            case 12: return "Twelve";
            case 13: return "Thirteen";
            case 14: return "Fourteen";
            case 15: return "Fifteen";
            case 16: return "Sixteen";
            case 17: return "Seventeen";
            case 18: return "Eighteen";
            case 19: return "Nineteen";
        }

        if (num < 100)
        {
            string part1;
            switch (num/10)
            {
                case 2: part1 = "Twenty"; break;
                case 3: part1 = "Thirty"; break;
                case 4: part1 = "Forty"; break;
                case 5: part1 = "Fifty"; break;
                case 6: part1 = "Sixty"; break;
                case 7: part1 = "Seventy"; break;
                case 8: part1 = "Eighty"; break;
                case 9: default: part1 = "Ninety"; break;
            }
            var part2 = NumberToWordsInternal(num % 10);
            return JoinParts(part1, part2);
        }

        {
            var part1 = NumberToWordsInternal(num / 100);
            var part2 = NumberToWordsInternal(num % 100);
            return JoinParts(part1, "Hundred", part2);
        }
    }
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberToWords(num: number): string {
    if (num === 0) return 'Zero';

    // prettier-ignore
    const f = (x: number): string => {
    const dict1 = ['','One','Two','Three','Four','Five','Six','Seven','Eight','Nine','Ten','Eleven','Twelve','Thirteen','Fourteen','Fifteen','Sixteen','Seventeen','Eighteen','Nineteen',]
    const dict2 = ['','','Twenty','Thirty','Forty','Fifty','Sixty','Seventy','Eighty','Ninety',]
    let ans = ''

    if (x <= 19) ans = dict1[x] ?? ''
    else if (x < 100) ans = `${dict2[Math.floor(x / 10)]} ${f(x % 10)}`
    else if (x < 10 ** 3) ans = `${dict1[Math.floor(x / 100)]} Hundred ${f(x % 100)}`
    else if (x < 10 ** 6) ans = `${f(Math.floor(x / 10 ** 3))} Thousand ${f(x % 10 ** 3)}`
    else if (x < 10 ** 9) ans = `${f(Math.floor(x / 10 ** 6))} Million ${f(x % 10 ** 6)}`
    else ans = `${f(Math.floor(x / 10 ** 9))} Billion ${f(x % 10 ** 9)}`

    return ans.trim()
  }

    return f(num);
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function numberToWords(num) {
    if (num === 0) return 'Zero';

    // prettier-ignore
    const f = (x) => {
    const dict1 = ['','One','Two','Three','Four','Five','Six','Seven','Eight','Nine','Ten','Eleven','Twelve','Thirteen','Fourteen','Fifteen','Sixteen','Seventeen','Eighteen','Nineteen',]
    const dict2 = ['','','Twenty','Thirty','Forty','Fifty','Sixty','Seventy','Eighty','Ninety',]
    let ans = ''

    if (x <= 19) ans = dict1[x] ?? ''
    else if (x < 100) ans = `${dict2[Math.floor(x / 10)]} ${f(x % 10)}`
    else if (x < 10 ** 3) ans = `${dict1[Math.floor(x / 100)]} Hundred ${f(x % 100)}`
    else if (x < 10 ** 6) ans = `${f(Math.floor(x / 10 ** 3))} Thousand ${f(x % 10 ** 3)}`
    else if (x < 10 ** 9) ans = `${f(Math.floor(x / 10 ** 6))} Million ${f(x % 10 ** 6)}`
    else ans = `${f(Math.floor(x / 10 ** 9))} Billion ${f(x % 10 ** 9)}`

    return ans.trim()
  }

    return f(num);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>将非负整数 <code>num</code> 转换为其对应的英文表示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>num = 123
<strong>输出：</strong>"One Hundred Twenty Three"
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>num = 12345
<strong>输出：</strong>"Twelve Thousand Three Hundred Forty Five"
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>num = 1234567
<strong>输出：</strong>"One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= num &lt;= 2<sup>31</sup> - 1</code></li>
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
    def numberToWords(self, num: int) -> str:
        if num == 0:
            return 'Zero'

        lt20 = [
            '',
            'One',
            'Two',
            'Three',
            'Four',
            'Five',
            'Six',
            'Seven',
            'Eight',
            'Nine',
            'Ten',
            'Eleven',
            'Twelve',
            'Thirteen',
            'Fourteen',
            'Fifteen',
            'Sixteen',
            'Seventeen',
            'Eighteen',
            'Nineteen',
        ]
        tens = [
            '',
            'Ten',
            'Twenty',
            'Thirty',
            'Forty',
            'Fifty',
            'Sixty',
            'Seventy',
            'Eighty',
            'Ninety',
        ]
        thousands = ['Billion', 'Million', 'Thousand', '']

        def transfer(num):
            if num == 0:
                return ''
            if num < 20:
                return lt20[num] + ' '
            if num < 100:
                return tens[num // 10] + ' ' + transfer(num % 10)
            return lt20[num // 100] + ' Hundred ' + transfer(num % 100)

        res = []
        i, j = 1000000000, 0
        while i > 0:
            if num // i != 0:
                res.append(transfer(num // i))
                res.append(thousands[j])
                res.append(' ')
                num %= i
            j += 1
            i //= 1000
        return ''.join(res).strip()
```

#### Java

```java
class Solution {
    private static Map<Integer, String> map;

    static {
        map = new HashMap<>();
        map.put(1, "One");
        map.put(2, "Two");
        map.put(3, "Three");
        map.put(4, "Four");
        map.put(5, "Five");
        map.put(6, "Six");
        map.put(7, "Seven");
        map.put(8, "Eight");
        map.put(9, "Nine");
        map.put(10, "Ten");
        map.put(11, "Eleven");
        map.put(12, "Twelve");
        map.put(13, "Thirteen");
        map.put(14, "Fourteen");
        map.put(15, "Fifteen");
        map.put(16, "Sixteen");
        map.put(17, "Seventeen");
        map.put(18, "Eighteen");
        map.put(19, "Nineteen");
        map.put(20, "Twenty");
        map.put(30, "Thirty");
        map.put(40, "Forty");
        map.put(50, "Fifty");
        map.put(60, "Sixty");
        map.put(70, "Seventy");
        map.put(80, "Eighty");
        map.put(90, "Ninety");
        map.put(100, "Hundred");
        map.put(1000, "Thousand");
        map.put(1000000, "Million");
        map.put(1000000000, "Billion");
    }

    public String numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 1000000000; i >= 1000; i /= 1000) {
            if (num >= i) {
                sb.append(get3Digits(num / i)).append(' ').append(map.get(i));
                num %= i;
            }
        }
        if (num > 0) {
            sb.append(get3Digits(num));
        }
        return sb.substring(1);
    }

    private String get3Digits(int num) {
        StringBuilder sb = new StringBuilder();
        if (num >= 100) {
            sb.append(' ').append(map.get(num / 100)).append(' ').append(map.get(100));
            num %= 100;
        }
        if (num > 0) {
            if (num < 20 || num % 10 == 0) {
                sb.append(' ').append(map.get(num));
            } else {
                sb.append(' ').append(map.get(num / 10 * 10)).append(' ').append(map.get(num % 10));
            }
        }
        return sb.toString();
    }
}
```

#### C#

```cs
using System.Collections.Generic;
using System.Linq;

public class Solution {
    private string[] bases = { "Thousand", "Million", "Billion" };
    public string NumberToWords(int num) {
        if (num == 0)
        {
            return "Zero";
        }
        var baseIndex = -1;
        var parts = new List<string>();
        while (num > 0)
        {
            var part = NumberToWordsInternal(num % 1000);
            if (part.Length > 0 && baseIndex >= 0)
            {
                part = JoinParts(part, bases[baseIndex]);
            }
            parts.Add(part);
            baseIndex++;
            num /= 1000;
        }
        parts.Reverse();
        return JoinParts(parts);
    }

    private string JoinParts(IEnumerable<string> parts)
    {
        return string.Join(" ", parts.Where(p => p.Length > 0));
    }

    private string JoinParts(params string[] parts)
    {
        return JoinParts((IEnumerable<string>)parts);
    }

    private string NumberToWordsInternal(int num)
    {
        switch(num)
        {
            case 0: return "";
            case 1: return "One";
            case 2: return "Two";
            case 3: return "Three";
            case 4: return "Four";
            case 5: return "Five";
            case 6: return "Six";
            case 7: return "Seven";
            case 8: return "Eight";
            case 9: return "Nine";
            case 10: return "Ten";
            case 11: return "Eleven";
            case 12: return "Twelve";
            case 13: return "Thirteen";
            case 14: return "Fourteen";
            case 15: return "Fifteen";
            case 16: return "Sixteen";
            case 17: return "Seventeen";
            case 18: return "Eighteen";
            case 19: return "Nineteen";
        }

        if (num < 100)
        {
            string part1;
            switch (num/10)
            {
                case 2: part1 = "Twenty"; break;
                case 3: part1 = "Thirty"; break;
                case 4: part1 = "Forty"; break;
                case 5: part1 = "Fifty"; break;
                case 6: part1 = "Sixty"; break;
                case 7: part1 = "Seventy"; break;
                case 8: part1 = "Eighty"; break;
                case 9: default: part1 = "Ninety"; break;
            }
            var part2 = NumberToWordsInternal(num % 10);
            return JoinParts(part1, part2);
        }

        {
            var part1 = NumberToWordsInternal(num / 100);
            var part2 = NumberToWordsInternal(num % 100);
            return JoinParts(part1, "Hundred", part2);
        }
    }
}
```

#### TypeScript

```ts
function numberToWords(num: number): string {
    if (num === 0) return 'Zero';

    // prettier-ignore
    const f = (x: number): string => {
    const dict1 = ['','One','Two','Three','Four','Five','Six','Seven','Eight','Nine','Ten','Eleven','Twelve','Thirteen','Fourteen','Fifteen','Sixteen','Seventeen','Eighteen','Nineteen',]
    const dict2 = ['','','Twenty','Thirty','Forty','Fifty','Sixty','Seventy','Eighty','Ninety',]
    let ans = ''

    if (x <= 19) ans = dict1[x] ?? ''
    else if (x < 100) ans = `${dict2[Math.floor(x / 10)]} ${f(x % 10)}`
    else if (x < 10 ** 3) ans = `${dict1[Math.floor(x / 100)]} Hundred ${f(x % 100)}`
    else if (x < 10 ** 6) ans = `${f(Math.floor(x / 10 ** 3))} Thousand ${f(x % 10 ** 3)}`
    else if (x < 10 ** 9) ans = `${f(Math.floor(x / 10 ** 6))} Million ${f(x % 10 ** 6)}`
    else ans = `${f(Math.floor(x / 10 ** 9))} Billion ${f(x % 10 ** 9)}`

    return ans.trim()
  }

    return f(num);
}
```

#### JavaScript

```js
function numberToWords(num) {
    if (num === 0) return 'Zero';

    // prettier-ignore
    const f = (x) => {
    const dict1 = ['','One','Two','Three','Four','Five','Six','Seven','Eight','Nine','Ten','Eleven','Twelve','Thirteen','Fourteen','Fifteen','Sixteen','Seventeen','Eighteen','Nineteen',]
    const dict2 = ['','','Twenty','Thirty','Forty','Fifty','Sixty','Seventy','Eighty','Ninety',]
    let ans = ''

    if (x <= 19) ans = dict1[x] ?? ''
    else if (x < 100) ans = `${dict2[Math.floor(x / 10)]} ${f(x % 10)}`
    else if (x < 10 ** 3) ans = `${dict1[Math.floor(x / 100)]} Hundred ${f(x % 100)}`
    else if (x < 10 ** 6) ans = `${f(Math.floor(x / 10 ** 3))} Thousand ${f(x % 10 ** 3)}`
    else if (x < 10 ** 9) ans = `${f(Math.floor(x / 10 ** 6))} Million ${f(x % 10 ** 6)}`
    else ans = `${f(Math.floor(x / 10 ** 9))} Billion ${f(x % 10 ** 9)}`

    return ans.trim()
  }

    return f(num);
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
    private String[] lt20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight",
        "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
        "Seventeen", "Eighteen", "Nineteen"};
    private String[] tens
        = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    private String[] thousands = {"Billion", "Million", "Thousand", ""};

    public String numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 1000000000, j = 0; i > 0; i /= 1000, ++j) {
            if (num / i == 0) {
                continue;
            }
            sb.append(transfer(num / i)).append(thousands[j]).append(' ');
            num %= i;
        }
        return sb.toString().trim();
    }

    private String transfer(int num) {
        if (num == 0) {
            return "";
        }
        if (num < 20) {
            return lt20[num] + " ";
        }
        if (num < 100) {
            return tens[num / 10] + " " + transfer(num % 10);
        }
        return lt20[num / 100] + " Hundred " + transfer(num % 100);
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [274. H 指数](https://leetcode.cn/problems/h-index){#274}

{{< tabs "274" >}}

{{% tab "python" %}}
```python
class Solution:
    def hIndex(self, citations: List[int]) -> int:
        l, r = 0, len(citations)
        while l < r:
            mid = (l + r + 1) >> 1
            if sum(x >= mid for x in citations) >= mid:
                l = mid
            else:
                r = mid - 1
        return l
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int hIndex(int[] citations) {
        int l = 0, r = citations.length;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            int s = 0;
            for (int x : citations) {
                if (x >= mid) {
                    ++s;
                }
            }
            if (s >= mid) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l = 0, r = citations.size();
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            int s = 0;
            for (int x : citations) {
                if (x >= mid) {
                    ++s;
                }
            }
            if (s >= mid) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func hIndex(citations []int) int {
	l, r := 0, len(citations)
	for l < r {
		mid := (l + r + 1) >> 1
		s := 0
		for _, x := range citations {
			if x >= mid {
				s++
			}
		}
		if s >= mid {
			l = mid
		} else {
			r = mid - 1
		}
	}
	return l
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function hIndex(citations: number[]): number {
    let l = 0;
    let r = citations.length;
    while (l < r) {
        const mid = (l + r + 1) >> 1;
        let s = 0;
        for (const x of citations) {
            if (x >= mid) {
                ++s;
            }
        }
        if (s >= mid) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    #[allow(dead_code)]
    pub fn h_index(citations: Vec<i32>) -> i32 {
        let mut citations = citations;
        citations.sort_by(|&lhs, &rhs| rhs.cmp(&lhs));

        let n = citations.len();

        for i in (1..=n).rev() {
            if citations[i - 1] >= (i as i32) {
                return i as i32;
            }
        }

        0
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>citations</code> ，其中 <code>citations[i]</code> 表示研究者的第 <code>i</code> 篇论文被引用的次数。计算并返回该研究者的 <strong><code>h</code><em>&nbsp;</em>指数</strong>。</p>

<p>根据维基百科上&nbsp;<a href="https://baike.baidu.com/item/h-index/3991452?fr=aladdin" target="_blank">h 指数的定义</a>：<code>h</code> 代表“高引用次数” ，一名科研人员的 <code>h</code><strong> 指数 </strong>是指他（她）至少发表了 <code>h</code> 篇论文，并且&nbsp;<strong>至少&nbsp;</strong>有 <code>h</code> 篇论文被引用次数大于等于 <code>h</code> 。如果 <code>h</code><em> </em>有多种可能的值，<strong><code>h</code> 指数 </strong>是其中最大的那个。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong><code>citations = [3,0,6,1,5]</code>
<strong>输出：</strong>3 
<strong>解释：</strong>给定数组表示研究者总共有 <code>5</code> 篇论文，每篇论文相应的被引用了 <code>3, 0, 6, 1, 5</code> 次。
&nbsp;    由于研究者有 <code>3 </code>篇论文每篇 <strong>至少 </strong>被引用了 <code>3</code> 次，其余两篇论文每篇被引用 <strong>不多于</strong> <code>3</code> 次，所以她的 <em>h </em>指数是 <code>3</code>。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>citations = [1,3,1]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == citations.length</code></li>
	<li><code>1 &lt;= n &lt;= 5000</code></li>
	<li><code>0 &lt;= citations[i] &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序

我们可以先对数组 `citations` 按照元素值从大到小进行排序。然后我们从大到小枚举 $h$ 值，如果某个 $h$ 值满足 $citations[h-1] \geq h$，则说明有至少 $h$ 篇论文分别被引用了至少 $h$ 次，直接返回 $h$ 即可。如果没有找到这样的 $h$ 值，说明所有的论文都没有被引用，返回 $0$。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 是数组 `citations` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def hIndex(self, citations: List[int]) -> int:
        citations.sort(reverse=True)
        for h in range(len(citations), 0, -1):
            if citations[h - 1] >= h:
                return h
        return 0
```

#### Java

```java
class Solution {
    public int hIndex(int[] citations) {
        Arrays.sort(citations);
        int n = citations.length;
        for (int h = n; h > 0; --h) {
            if (citations[n - h] >= h) {
                return h;
            }
        }
        return 0;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(), citations.rend());
        for (int h = citations.size(); h; --h) {
            if (citations[h - 1] >= h) {
                return h;
            }
        }
        return 0;
    }
};
```

#### Go

```go
func hIndex(citations []int) int {
	sort.Ints(citations)
	n := len(citations)
	for h := n; h > 0; h-- {
		if citations[n-h] >= h {
			return h
		}
	}
	return 0
}
```

#### TypeScript

```ts
function hIndex(citations: number[]): number {
    citations.sort((a, b) => b - a);
    for (let h = citations.length; h; --h) {
        if (citations[h - 1] >= h) {
            return h;
        }
    }
    return 0;
}
```

#### Rust

```rust
impl Solution {
    #[allow(dead_code)]
    pub fn h_index(citations: Vec<i32>) -> i32 {
        let mut citations = citations;
        citations.sort_by(|&lhs, &rhs| rhs.cmp(&lhs));

        let n = citations.len();

        for i in (1..=n).rev() {
            if citations[i - 1] >= (i as i32) {
                return i as i32;
            }
        }

        0
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：计数 + 求和

我们可以使用一个长度为 $n+1$ 的数组 $cnt$，其中 $cnt[i]$ 表示引用次数为 $i$ 的论文的篇数。我们遍历数组 `citations`，将引用次数大于 $n$ 的论文都当作引用次数为 $n$ 的论文，然后将每篇论文的引用次数作为下标，将 $cnt$ 中对应的元素值加 $1$。这样我们就统计出了每个引用次数对应的论文篇数。

接下来，我们从大到小枚举 $h$ 值，将 $cnt$ 中下标为 $h$ 的元素值加到变量 $s$ 中，其中 $s$ 表示引用次数大于等于 $h$ 的论文篇数。如果 $s \geq h$，说明至少有 $h$ 篇论文分别被引用了至少 $h$ 次，直接返回 $h$ 即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 `citations` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def hIndex(self, citations: List[int]) -> int:
        n = len(citations)
        cnt = [0] * (n + 1)
        for x in citations:
            cnt[min(x, n)] += 1
        s = 0
        for h in range(n, -1, -1):
            s += cnt[h]
            if s >= h:
                return h
```

#### Java

```java
class Solution {
    public int hIndex(int[] citations) {
        int n = citations.length;
        int[] cnt = new int[n + 1];
        for (int x : citations) {
            ++cnt[Math.min(x, n)];
        }
        for (int h = n, s = 0;; --h) {
            s += cnt[h];
            if (s >= h) {
                return h;
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int cnt[n + 1];
        memset(cnt, 0, sizeof(cnt));
        for (int x : citations) {
            ++cnt[min(x, n)];
        }
        for (int h = n, s = 0;; --h) {
            s += cnt[h];
            if (s >= h) {
                return h;
            }
        }
    }
};
```

#### Go

```go
func hIndex(citations []int) int {
	n := len(citations)
	cnt := make([]int, n+1)
	for _, x := range citations {
		cnt[min(x, n)]++
	}
	for h, s := n, 0; ; h-- {
		s += cnt[h]
		if s >= h {
			return h
		}
	}
}
```

#### TypeScript

```ts
function hIndex(citations: number[]): number {
    const n: number = citations.length;
    const cnt: number[] = new Array(n + 1).fill(0);
    for (const x of citations) {
        ++cnt[Math.min(x, n)];
    }
    for (let h = n, s = 0; ; --h) {
        s += cnt[h];
        if (s >= h) {
            return h;
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三：二分查找

我们注意到，如果存在一个 $h$ 值满足至少有 $h$ 篇论文至少被引用 $h$ 次，那么对于任意一个 $h' \lt h$，都有至少 $h'$ 篇论文至少被引用 $h'$ 次。因此我们可以使用二分查找的方法，找到最大的 $h$ 值，使得至少有 $h$ 篇论文至少被引用 $h$ 次。

我们定义二分查找的左边界 $l=0$，右边界 $r=n$。每次我们取 $mid = \lfloor \frac{l + r + 1}{2} \rfloor$，其中 $\lfloor x \rfloor$ 表示对 $x$ 向下取整。然后我们统计数组 `citations` 中大于等于 $mid$ 的元素的个数，记为 $s$。如果 $s \geq mid$，说明至少有 $mid$ 篇论文至少被引用 $mid$ 次，此时我们将左边界 $l$ 变为 $mid$，否则我们将右边界 $r$ 变为 $mid-1$。当左边界 $l$ 等于右边界 $r$ 时，我们找到了最大的 $h$ 值，即为 $l$ 或 $r$。

时间复杂度 $O(n \times \log n)$，其中 $n$ 是数组 `citations` 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def hIndex(self, citations: List[int]) -> int:
        l, r = 0, len(citations)
        while l < r:
            mid = (l + r + 1) >> 1
            if sum(x >= mid for x in citations) >= mid:
                l = mid
            else:
                r = mid - 1
        return l
```

#### Java

```java
class Solution {
    public int hIndex(int[] citations) {
        int l = 0, r = citations.length;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            int s = 0;
            for (int x : citations) {
                if (x >= mid) {
                    ++s;
                }
            }
            if (s >= mid) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l = 0, r = citations.size();
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            int s = 0;
            for (int x : citations) {
                if (x >= mid) {
                    ++s;
                }
            }
            if (s >= mid) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};
```

#### Go

```go
func hIndex(citations []int) int {
	l, r := 0, len(citations)
	for l < r {
		mid := (l + r + 1) >> 1
		s := 0
		for _, x := range citations {
			if x >= mid {
				s++
			}
		}
		if s >= mid {
			l = mid
		} else {
			r = mid - 1
		}
	}
	return l
}
```

#### TypeScript

```ts
function hIndex(citations: number[]): number {
    let l = 0;
    let r = citations.length;
    while (l < r) {
        const mid = (l + r + 1) >> 1;
        let s = 0;
        for (const x of citations) {
            if (x >= mid) {
                ++s;
            }
        }
        if (s >= mid) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [275. H 指数 II](https://leetcode.cn/problems/h-index-ii){#275}

{{< tabs "275" >}}

{{% tab "python" %}}
```python
class Solution:
    def hIndex(self, citations: List[int]) -> int:
        n = len(citations)
        left, right = 0, n
        while left < right:
            mid = (left + right + 1) >> 1
            if citations[n - mid] >= mid:
                left = mid
            else:
                right = mid - 1
        return left
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int hIndex(int[] citations) {
        int n = citations.length;
        int left = 0, right = n;
        while (left < right) {
            int mid = (left + right) >>> 1;
            if (citations[mid] >= n - mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return n - left;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0, right = n;
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            if (citations[n - mid] >= mid)
                left = mid;
            else
                right = mid - 1;
        }
        return left;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func hIndex(citations []int) int {
	n := len(citations)
	left, right := 0, n
	for left < right {
		mid := (left + right + 1) >> 1
		if citations[n-mid] >= mid {
			left = mid
		} else {
			right = mid - 1
		}
	}
	return left
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function hIndex(citations: number[]): number {
    const n = citations.length;
    let left = 0,
        right = n;
    while (left < right) {
        const mid = (left + right + 1) >> 1;
        if (citations[n - mid] >= mid) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    return left;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn h_index(citations: Vec<i32>) -> i32 {
        let n = citations.len();
        let (mut left, mut right) = (0, n);
        while left < right {
            let mid = ((left + right + 1) >> 1) as usize;
            if citations[n - mid] >= (mid as i32) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        left as i32
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int HIndex(int[] citations) {
        int n = citations.Length;
        int left = 0, right = n;
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            if (citations[n - mid] >= mid) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>citations</code> ，其中 <code>citations[i]</code> 表示研究者的第 <code>i</code> 篇论文被引用的次数，<code>citations</code> 已经按照&nbsp;<strong>非降序排列&nbsp;</strong>。计算并返回该研究者的 h<strong><em>&nbsp;</em></strong>指数。</p>

<p><a href="https://baike.baidu.com/item/h-index/3991452?fr=aladdin" target="_blank">h 指数的定义</a>：h 代表“高引用次数”（high citations），一名科研人员的 <code>h</code> 指数是指他（她）的 （<code>n</code> 篇论文中）<strong>至少&nbsp;</strong>有 <code>h</code> 篇论文分别被引用了<strong>至少</strong> <code>h</code> 次。</p>

<p>请你设计并实现对数时间复杂度的算法解决此问题。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong><code>citations = [0,1,3,5,6]</code>
<strong>输出：</strong><code>3</code>
<strong>解释：</strong>给定数组表示研究者总共有 <code>5</code> 篇论文，每篇论文相应的被引用了 <code>0, 1, 3, 5, 6</code> 次。
&nbsp;    由于研究者有<code>3</code>篇论文每篇<strong> 至少 </strong>被引用了 <code>3</code> 次，其余两篇论文每篇被引用<strong> 不多于</strong> <code>3</code> 次，所以她的<em> h </em>指数是 <code>3</code> 。</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong><code>citations = [1,2,100]</code>
<strong>输出：</strong><code>2</code>
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == citations.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= citations[i] &lt;= 1000</code></li>
	<li><code>citations</code> 按 <strong>升序排列</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

我们注意到，如果有至少 $x$ 篇论文的引用次数大于等于 $x$，那么对于任意 $y \lt x$，其引用次数也一定大于等于 $y$。这存在着单调性。

因此，我们二分枚举 $h$，获取满足条件的最大 $h$。由于要满足 $h$ 篇论文至少被引用 $h$ 次，因此 $citations[n - mid] \ge mid$。

时间复杂度 $O(\log n)$，其中 $n$ 是数组 $citations$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def hIndex(self, citations: List[int]) -> int:
        n = len(citations)
        left, right = 0, n
        while left < right:
            mid = (left + right + 1) >> 1
            if citations[n - mid] >= mid:
                left = mid
            else:
                right = mid - 1
        return left
```

#### Java

```java
class Solution {
    public int hIndex(int[] citations) {
        int n = citations.length;
        int left = 0, right = n;
        while (left < right) {
            int mid = (left + right) >>> 1;
            if (citations[mid] >= n - mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return n - left;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0, right = n;
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            if (citations[n - mid] >= mid)
                left = mid;
            else
                right = mid - 1;
        }
        return left;
    }
};
```

#### Go

```go
func hIndex(citations []int) int {
	n := len(citations)
	left, right := 0, n
	for left < right {
		mid := (left + right + 1) >> 1
		if citations[n-mid] >= mid {
			left = mid
		} else {
			right = mid - 1
		}
	}
	return left
}
```

#### TypeScript

```ts
function hIndex(citations: number[]): number {
    const n = citations.length;
    let left = 0,
        right = n;
    while (left < right) {
        const mid = (left + right + 1) >> 1;
        if (citations[n - mid] >= mid) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    return left;
}
```

#### Rust

```rust
impl Solution {
    pub fn h_index(citations: Vec<i32>) -> i32 {
        let n = citations.len();
        let (mut left, mut right) = (0, n);
        while left < right {
            let mid = ((left + right + 1) >> 1) as usize;
            if citations[n - mid] >= (mid as i32) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        left as i32
    }
}
```

#### C#

```cs
public class Solution {
    public int HIndex(int[] citations) {
        int n = citations.Length;
        int left = 0, right = n;
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            if (citations[n - mid] >= mid) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [276. 栅栏涂色 🔒](https://leetcode.cn/problems/paint-fence){#276}

{{< tabs "276" >}}

{{% tab "python" %}}
```python
class Solution:
    def numWays(self, n: int, k: int) -> int:
        f, g = k, 0
        for _ in range(n - 1):
            ff = (f + g) * (k - 1)
            g = f
            f = ff
        return f + g
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numWays(int n, int k) {
        int f = k, g = 0;
        for (int i = 1; i < n; ++i) {
            int ff = (f + g) * (k - 1);
            g = f;
            f = ff;
        }
        return f + g;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int numWays(int n, int k) {
        int f = k, g = 0;
        for (int i = 1; i < n; ++i) {
            int ff = (f + g) * (k - 1);
            g = f;
            f = ff;
        }
        return f + g;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numWays(n int, k int) int {
	f, g := k, 0
	for i := 1; i < n; i++ {
		f, g = (f+g)*(k-1), f
	}
	return f + g
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numWays(n: number, k: number): number {
    let [f, g] = [k, 0];
    for (let i = 1; i < n; ++i) {
        const ff = (f + g) * (k - 1);
        g = f;
        f = ff;
    }
    return f + g;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有 <code>k</code> 种颜色的涂料和一个包含 <code>n</code> 个栅栏柱的栅栏，请你按下述规则为栅栏设计涂色方案：</p>

<ul>
	<li>每个栅栏柱可以用其中 <strong>一种</strong> 颜色进行上色。</li>
	<li>相邻的栅栏柱 <strong>最多连续两个 </strong>颜色相同。</li>
</ul>

<p>给你两个整数 <code>k</code> 和 <code>n</code> ，返回所有有效的涂色 <strong>方案数</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0200-0299/0276.Paint%20Fence/images/paintfenceex1.png" style="width: 507px; height: 313px;" />
<pre>
<strong>输入：</strong>n = 3, k = 2
<strong>输出：</strong>6
<strong>解释：</strong>所有的可能涂色方案如上图所示。注意，全涂红或者全涂绿的方案属于无效方案，因为相邻的栅栏柱 <strong>最多连续两个 </strong>颜色相同。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 1, k = 1
<strong>输出：</strong>1
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 7, k = 2
<strong>输出：</strong>42
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= n <= 50</code></li>
	<li><code>1 <= k <= 10<sup>5</sup></code></li>
	<li>题目数据保证：对于输入的 <code>n</code> 和 <code>k</code> ，其答案在范围 <code>[0, 2<sup>31</sup> - 1]</code> 内</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i]$ 表示表示 $[0..i]$ 的栅栏柱且最后两个栅栏柱颜色不同的涂色方法数，定义 $g[i]$ 表示表示 $[0..i]$ 的栅栏柱且最后两个栅栏柱颜色相同的涂色方法数。初始时 $f[0] = k$，而 $g[0] = 0$。

当 $i > 0$ 时，有如下状态转移方程：

$$
\begin{aligned}
f[i] & = (f[i - 1] + g[i - 1]) \times (k - 1) \\
g[i] & = f[i - 1]
\end{aligned}
$$

最终的答案即为 $f[n - 1] + g[n - 1]$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是栅栏的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numWays(self, n: int, k: int) -> int:
        f = [0] * n
        g = [0] * n
        f[0] = k
        for i in range(1, n):
            f[i] = (f[i - 1] + g[i - 1]) * (k - 1)
            g[i] = f[i - 1]
        return f[-1] + g[-1]
```

#### Java

```java
class Solution {
    public int numWays(int n, int k) {
        int[] f = new int[n];
        int[] g = new int[n];
        f[0] = k;
        for (int i = 1; i < n; ++i) {
            f[i] = (f[i - 1] + g[i - 1]) * (k - 1);
            g[i] = f[i - 1];
        }
        return f[n - 1] + g[n - 1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numWays(int n, int k) {
        vector<int> f(n);
        vector<int> g(n);
        f[0] = k;
        for (int i = 1; i < n; ++i) {
            f[i] = (f[i - 1] + g[i - 1]) * (k - 1);
            g[i] = f[i - 1];
        }
        return f[n - 1] + g[n - 1];
    }
};
```

#### Go

```go
func numWays(n int, k int) int {
	f := make([]int, n)
	g := make([]int, n)
	f[0] = k
	for i := 1; i < n; i++ {
		f[i] = (f[i-1] + g[i-1]) * (k - 1)
		g[i] = f[i-1]
	}
	return f[n-1] + g[n-1]
}
```

#### TypeScript

```ts
function numWays(n: number, k: number): number {
    const f: number[] = Array(n).fill(0);
    const g: number[] = Array(n).fill(0);
    f[0] = k;
    for (let i = 1; i < n; ++i) {
        f[i] = (f[i - 1] + g[i - 1]) * (k - 1);
        g[i] = f[i - 1];
    }
    return f[n - 1] + g[n - 1];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划（空间优化）

我们发现 $f[i]$ 和 $g[i]$ 只与 $f[i - 1]$ 和 $g[i - 1]$ 有关，因此我们可以使用两个变量 $f$ 和 $g$ 分别记录 $f[i - 1]$ 和 $g[i - 1]$ 的值，从而将空间复杂度优化到 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numWays(self, n: int, k: int) -> int:
        f, g = k, 0
        for _ in range(n - 1):
            ff = (f + g) * (k - 1)
            g = f
            f = ff
        return f + g
```

#### Java

```java
class Solution {
    public int numWays(int n, int k) {
        int f = k, g = 0;
        for (int i = 1; i < n; ++i) {
            int ff = (f + g) * (k - 1);
            g = f;
            f = ff;
        }
        return f + g;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numWays(int n, int k) {
        int f = k, g = 0;
        for (int i = 1; i < n; ++i) {
            int ff = (f + g) * (k - 1);
            g = f;
            f = ff;
        }
        return f + g;
    }
};
```

#### Go

```go
func numWays(n int, k int) int {
	f, g := k, 0
	for i := 1; i < n; i++ {
		f, g = (f+g)*(k-1), f
	}
	return f + g
}
```

#### TypeScript

```ts
function numWays(n: number, k: number): number {
    let [f, g] = [k, 0];
    for (let i = 1; i < n; ++i) {
        const ff = (f + g) * (k - 1);
        g = f;
        f = ff;
    }
    return f + g;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [277. 搜寻名人 🔒](https://leetcode.cn/problems/find-the-celebrity){#277}

{{< tabs "277" >}}

{{% tab "bash" %}}
```bash
ans = 0
for i in [1,n) {
	if (ans knows i) {
		ans = i
	}
}

ans = 0

ans not knows 1
ans not knows 2
ans knows 3
ans = 3

ans not knows 4
ans not knows 5
ans not knows 6
ans = 6
```
{{% /tab %}}
{{% tab "python" %}}
```python
# The knows API is already defined for you.
# return a bool, whether a knows b
# def knows(a: int, b: int) -> bool:


class Solution:
    def findCelebrity(self, n: int) -> int:
        ans = 0
        for i in range(1, n):
            if knows(ans, i):
                ans = i
        for i in range(n):
            if ans != i:
                if knows(ans, i) or not knows(i, ans):
                    return -1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
/* The knows API is defined in the parent class Relation.
      boolean knows(int a, int b); */

public class Solution extends Relation {
    public int findCelebrity(int n) {
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            if (knows(ans, i)) {
                ans = i;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (ans != i) {
                if (knows(ans, i) || !knows(i, ans)) {
                    return -1;
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
/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            if (knows(ans, i)) {
                ans = i;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (ans != i) {
                if (knows(ans, i) || !knows(i, ans)) {
                    return -1;
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
/**
 * The knows API is already defined for you.
 *     knows := func(a int, b int) bool
 */
func solution(knows func(a int, b int) bool) func(n int) int {
	return func(n int) int {
		ans := 0
		for i := 1; i < n; i++ {
			if knows(ans, i) {
				ans = i
			}
		}
		for i := 0; i < n; i++ {
			if ans != i {
				if knows(ans, i) || !knows(i, ans) {
					return -1
				}
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

<p>假设你是一个专业的狗仔，参加了一个&nbsp;<code>n</code>&nbsp;人派对，其中每个人被从&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n - 1</code>&nbsp;标号。在这个派对人群当中可能存在一位&nbsp;“名人”。所谓 “名人” 的定义是：其他所有&nbsp;<code>n - 1</code>&nbsp;个人都认识他/她，而他/她并不认识其他任何人。</p>

<p>现在你想要确认这个 “名人” 是谁，或者确定这里没有&nbsp;“名人”。而你唯一能做的就是问诸如 “A&nbsp;你好呀，请问你认不认识&nbsp;B呀？”&nbsp;的问题，以确定 A 是否认识 B。你需要在（渐近意义上）尽可能少的问题内来确定这位 “名人” 是谁（或者确定这里没有 “名人”）。</p>

<p>给定整数&nbsp;<code>n</code>&nbsp;和一个辅助函数&nbsp;<code>bool knows(a, b)</code>&nbsp;用来获取&nbsp;<code>a</code> 是否认识&nbsp;<code>b</code>。实现一个函数&nbsp;<code>int findCelebrity(n)</code>。派对最多只会有一个 “名人” 参加。</p>

<p>若&nbsp;“名人” 存在，请返回他/她的编号；若&nbsp;“名人”&nbsp;不存在，请返回&nbsp;<code>-1</code>。</p>

<p><strong>注意</strong>&nbsp;<code>n x n</code>&nbsp;的二维数组&nbsp;<code>graph</code>&nbsp;给定的输入并不是&nbsp;<strong>直接</strong>&nbsp;提供给你的，而是&nbsp;<strong>只能</strong>&nbsp;通过辅助函数 <code>knows</code>&nbsp;获取。<code>graph[i][j] == 1</code>&nbsp;表示&nbsp;<code>i</code> 认识 <code>j</code>，而&nbsp;<code>graph[i][j] == 0</code>&nbsp;表示&nbsp;<code>j</code>&nbsp;不认识&nbsp;<code>i</code>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0200-0299/0277.Find%20the%20Celebrity/images/g1.jpg" style="width: 224px; height: 145px;" />
<pre>
<strong>输入: </strong>graph = [[1,1,0],[0,1,0],[1,1,1]]
<strong>输出: </strong>1
<strong>解释: </strong>有编号分别为 0、1 和 2 的三个人。graph[i][j] = 1 代表编号为 i 的人认识编号为 j 的人，而 graph[i][j] = 0 则代表编号为 i 的人不认识编号为 j 的人。“名人” 是编号 1 的人，因为 0 和 2 均认识他/她，但 1 不认识任何人。
</pre>
<strong> </strong>

<p><strong><strong class="example">示例&nbsp;2:</strong></strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0200-0299/0277.Find%20the%20Celebrity/images/g2.jpg" style="width: 224px; height: 145px;" />
<pre>
<strong>输入: </strong>graph = [[1,0,1],[1,1,0],[0,1,1]]
<strong>输出: </strong>-1
<strong>解释: </strong>没有 “名人”
</pre>

<p><strong>&nbsp;</strong></p>
<strong> </strong>

<p><strong><strong>提示：</strong></strong></p>
<strong> </strong>

<ul>
	<li><code>n == graph.length == graph[i].length</code></li>
	<li><code>2 &lt;= n &lt;= 100</code></li>
	<li><code>graph[i][j]</code> 是 <code>0</code> 或 <code>1</code></li>
	<li><code>graph[i][i] == 1</code></li>
</ul>
<strong> </strong>

<p><strong>&nbsp;</strong></p>
<strong> </strong>

<p><strong><strong>进阶：</strong></strong>如果允许调用 API <code>knows</code> 的最大次数为 <code>3 * n</code> ，你可以设计一个不超过最大调用次数的解决方案吗？</p>
<strong> </strong>

<ol>
</ol>
<strong> </strong>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：O(n) 遍历

经过验证，若暴力遍历，调用 $O(n^2)$ 次 $knows$ 方法，会报 TLE 错误。因此，我们需要寻找更优的解法。

要找出 $n$ 个人中的名人，题目给我们的关键信息是：1. 名人不认识其他所有人；2. 其他所有人都认识名人。

那么，我们初始时假定名人 $ans=0$。然后在 $[1,n)$ 范围内遍历 $i$，若 $ans$ 认识 $i$，说明 $ans$ 不是我们要找的名人，此时我们可以直接将 $ans$ 更新为 $i$。

为什么呢？我们来举个实际的例子。

```bash
ans = 0
for i in [1,n) {
	if (ans knows i) {
		ans = i
	}
}

ans = 0

ans not knows 1
ans not knows 2
ans knows 3
ans = 3

ans not knows 4
ans not knows 5
ans not knows 6
ans = 6
```

这里 $ans$ 认识 $3$，说明 $ans$ 不是名人（即 $0$ 不是名人），那么名人会是 $1$ 或者 $2$ 吗？不会！因为若 $1$ 或者 $2$ 是名人，那么 $0$ 应该认识 $1$ 或者 $2$ 才对，与前面的例子冲突。因此，我们可以直接将 $ans$ 更新为 $i$。

我们找出 $ans$ 之后，接下来再遍历一遍，判断 $ans$ 是否满足名人的条件。若不满足，返回 $-1$。

否则遍历结束，返回 $ans$。

<!-- tabs:start -->

#### Python3

```python
# The knows API is already defined for you.
# return a bool, whether a knows b
# def knows(a: int, b: int) -> bool:


class Solution:
    def findCelebrity(self, n: int) -> int:
        ans = 0
        for i in range(1, n):
            if knows(ans, i):
                ans = i
        for i in range(n):
            if ans != i:
                if knows(ans, i) or not knows(i, ans):
                    return -1
        return ans
```

#### Java

```java
/* The knows API is defined in the parent class Relation.
      boolean knows(int a, int b); */

public class Solution extends Relation {
    public int findCelebrity(int n) {
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            if (knows(ans, i)) {
                ans = i;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (ans != i) {
                if (knows(ans, i) || !knows(i, ans)) {
                    return -1;
                }
            }
        }
        return ans;
    }
}
```

#### C++

```cpp
/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            if (knows(ans, i)) {
                ans = i;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (ans != i) {
                if (knows(ans, i) || !knows(i, ans)) {
                    return -1;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
/**
 * The knows API is already defined for you.
 *     knows := func(a int, b int) bool
 */
func solution(knows func(a int, b int) bool) func(n int) int {
	return func(n int) int {
		ans := 0
		for i := 1; i < n; i++ {
			if knows(ans, i) {
				ans = i
			}
		}
		for i := 0; i < n; i++ {
			if ans != i {
				if knows(ans, i) || !knows(i, ans) {
					return -1
				}
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

# [278. 第一个错误的版本](https://leetcode.cn/problems/first-bad-version){#278}

{{< tabs "278" >}}

{{% tab "python" %}}
```python
# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:


class Solution:
    def firstBadVersion(self, n: int) -> int:
        l, r = 1, n
        while l < r:
            mid = (l + r) >> 1
            if isBadVersion(mid):
                r = mid
            else:
                l = mid + 1
        return l
```
{{% /tab %}}
{{% tab "java" %}}
```java
/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int l = 1, r = n;
        while (l < r) {
            int mid = (l + r) >>> 1;
            if (isBadVersion(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (isBadVersion(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Forward declaration of isBadVersion API.
 * @param   version   your guess about first bad version
 * @return 	 	      true if current version is bad
 *			          false if current version is good
 * func isBadVersion(version int) bool;
 */

func firstBadVersion(n int) int {
	l, r := 1, n
	for l < r {
		mid := (l + r) >> 1
		if isBadVersion(mid) {
			r = mid
		} else {
			l = mid + 1
		}
	}
	return l
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * The knows API is defined in the parent class Relation.
 * isBadVersion(version: number): boolean {
 *     ...
 * };
 */

var solution = function (isBadVersion: any) {
    return function (n: number): number {
        let [l, r] = [1, n];
        while (l < r) {
            const mid = (l + r) >>> 1;
            if (isBadVersion(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };
};
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
// The API isBadVersion is defined for you.
// isBadVersion(version:i32)-> bool;
// to call it use self.isBadVersion(version)

impl Solution {
    pub fn first_bad_version(&self, n: i32) -> i32 {
		let (mut l, mut r) = (1, n);
        while l < r {
            let mid = l + (r - l) / 2;
            if self.isBadVersion(mid) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        l
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * Definition for isBadVersion()
 *
 * @param {integer} version number
 * @return {boolean} whether the version is bad
 * isBadVersion = function(version) {
 *     ...
 * };
 */

/**
 * @param {function} isBadVersion()
 * @return {function}
 */
var solution = function (isBadVersion) {
    /**
     * @param {integer} n Total versions
     * @return {integer} The first bad version
     */
    return function (n) {
        let [l, r] = [1, n];
        while (l < r) {
            const mid = (l + r) >>> 1;
            if (isBadVersion(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你是产品经理，目前正在带领一个团队开发新的产品。不幸的是，你的产品的最新版本没有通过质量检测。由于每个版本都是基于之前的版本开发的，所以错误的版本之后的所有版本都是错的。</p>

<p>假设你有 <code>n</code> 个版本 <code>[1, 2, ..., n]</code>，你想找出导致之后所有版本出错的第一个错误的版本。</p>

<p>你可以通过调用&nbsp;<code>bool isBadVersion(version)</code>&nbsp;接口来判断版本号 <code>version</code> 是否在单元测试中出错。实现一个函数来查找第一个错误的版本。你应该尽量减少对调用 API 的次数。</p>
&nbsp;

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 5, bad = 4
<strong>输出：</strong>4
<strong>解释：</strong>
<code>调用 isBadVersion(3) -&gt; false 
调用 isBadVersion(5)&nbsp;-&gt; true 
调用 isBadVersion(4)&nbsp;-&gt; true</code>
<code>所以，4 是第一个错误的版本。</code>
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 1, bad = 1
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= bad &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

我们定义二分查找的左边界 $l = 1$，右边界 $r = n$。

当 $l < r$ 时，我们计算中间位置 $\textit{mid} = \left\lfloor \frac{l + r}{2} \right\rfloor$，然后调用 `isBadVersion(mid)` 接口，如果返回 $\textit{true}$，则说明第一个错误的版本在 $[l, \textit{mid}]$ 之间，我们令 $r = \textit{mid}$；否则第一个错误的版本在 $[\textit{mid} + 1, r]$ 之间，我们令 $l = \textit{mid} + 1$。

最终返回 $l$ 即可。

时间复杂度 $O(\log n)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:


class Solution:
    def firstBadVersion(self, n: int) -> int:
        l, r = 1, n
        while l < r:
            mid = (l + r) >> 1
            if isBadVersion(mid):
                r = mid
            else:
                l = mid + 1
        return l
```

#### Java

```java
/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int l = 1, r = n;
        while (l < r) {
            int mid = (l + r) >>> 1;
            if (isBadVersion(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}
```

#### C++

```cpp
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (isBadVersion(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
```

#### Go

```go
/**
 * Forward declaration of isBadVersion API.
 * @param   version   your guess about first bad version
 * @return 	 	      true if current version is bad
 *			          false if current version is good
 * func isBadVersion(version int) bool;
 */

func firstBadVersion(n int) int {
	l, r := 1, n
	for l < r {
		mid := (l + r) >> 1
		if isBadVersion(mid) {
			r = mid
		} else {
			l = mid + 1
		}
	}
	return l
}
```

#### TypeScript

```ts
/**
 * The knows API is defined in the parent class Relation.
 * isBadVersion(version: number): boolean {
 *     ...
 * };
 */

var solution = function (isBadVersion: any) {
    return function (n: number): number {
        let [l, r] = [1, n];
        while (l < r) {
            const mid = (l + r) >>> 1;
            if (isBadVersion(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };
};
```

#### Rust

```rust
// The API isBadVersion is defined for you.
// isBadVersion(version:i32)-> bool;
// to call it use self.isBadVersion(version)

impl Solution {
    pub fn first_bad_version(&self, n: i32) -> i32 {
		let (mut l, mut r) = (1, n);
        while l < r {
            let mid = l + (r - l) / 2;
            if self.isBadVersion(mid) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        l
    }
}
```

#### JavaScript

```js
/**
 * Definition for isBadVersion()
 *
 * @param {integer} version number
 * @return {boolean} whether the version is bad
 * isBadVersion = function(version) {
 *     ...
 * };
 */

/**
 * @param {function} isBadVersion()
 * @return {function}
 */
var solution = function (isBadVersion) {
    /**
     * @param {integer} n Total versions
     * @return {integer} The first bad version
     */
    return function (n) {
        let [l, r] = [1, n];
        while (l < r) {
            const mid = (l + r) >>> 1;
            if (isBadVersion(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [279. 完全平方数](https://leetcode.cn/problems/perfect-squares){#279}

{{< tabs "279" >}}

{{% tab "python" %}}
```python
class Solution:
    def numSquares(self, n: int) -> int:
        m = int(sqrt(n))
        f = [0] + [inf] * n
        for i in range(1, m + 1):
            for j in range(i * i, n + 1):
                f[j] = min(f[j], f[j - i * i] + 1)
        return f[n]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numSquares(int n) {
        int m = (int) Math.sqrt(n);
        int[] f = new int[n + 1];
        Arrays.fill(f, 1 << 30);
        f[0] = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = i * i; j <= n; ++j) {
                f[j] = Math.min(f[j], f[j - i * i] + 1);
            }
        }
        return f[n];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int numSquares(int n) {
        int m = sqrt(n);
        int f[n + 1];
        memset(f, 0x3f, sizeof(f));
        f[0] = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = i * i; j <= n; ++j) {
                f[j] = min(f[j], f[j - i * i] + 1);
            }
        }
        return f[n];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numSquares(n int) int {
	m := int(math.Sqrt(float64(n)))
	f := make([]int, n+1)
	for i := range f {
		f[i] = 1 << 30
	}
	f[0] = 0
	for i := 1; i <= m; i++ {
		for j := i * i; j <= n; j++ {
			f[j] = min(f[j], f[j-i*i]+1)
		}
	}
	return f[n]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numSquares(n: number): number {
    const m = Math.floor(Math.sqrt(n));
    const f: number[] = Array(n + 1).fill(1 << 30);
    f[0] = 0;
    for (let i = 1; i <= m; ++i) {
        for (let j = i * i; j <= n; ++j) {
            f[j] = Math.min(f[j], f[j - i * i] + 1);
        }
    }
    return f[n];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn num_squares(n: i32) -> i32 {
        let (row, col) = ((n as f32).sqrt().floor() as usize, n as usize);
        let mut dp = vec![i32::MAX; col + 1];
        dp[0] = 0;
        for i in 1..=row {
            for j in i * i..=col {
                dp[j] = std::cmp::min(dp[j], dp[j - i * i] + 1);
            }
        }
        dp[col]
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数 <code>n</code> ，返回 <em>和为 <code>n</code> 的完全平方数的最少数量</em> 。</p>

<p><strong>完全平方数</strong> 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，<code>1</code>、<code>4</code>、<code>9</code> 和 <code>16</code> 都是完全平方数，而 <code>3</code> 和 <code>11</code> 不是。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1：</strong></p>

<pre>
<strong>输入：</strong>n = <code>12</code>
<strong>输出：</strong>3 
<strong>解释：</strong><code>12 = 4 + 4 + 4</code></pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = <code>13</code>
<strong>输出：</strong>2
<strong>解释：</strong><code>13 = 4 + 9</code></pre>

&nbsp;

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划(完全背包)

我们定义 $f[i][j]$ 表示使用数字 $1, 2, \cdots, i$ 的完全平方数组成和为 $j$ 的最少数量。初始时 $f[0][0] = 0$，其余位置的值均为正无穷。

我们可以枚举使用的最后一个数字的数量 $k$，那么：

$$
f[i][j] = \min(f[i - 1][j], f[i - 1][j - i^2] + 1, \cdots, f[i - 1][j - k \times i^2] + k)
$$

其中 $i^2$ 表示最后一个数字 $i$ 的完全平方数。

不妨令 $j = j - i^2$，那么有：

$$
f[i][j - i^2] = \min(f[i - 1][j - i^2], f[i - 1][j - 2 \times i^2] + 1, \cdots, f[i - 1][j - k \times i^2] + k - 1)
$$

将二式代入一式，我们可以得到以下状态转移方程：

$$
f[i][j] = \min(f[i - 1][j], f[i][j - i^2] + 1)
$$

最后答案即为 $f[m][n]$。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 为 $sqrt(n)$ 的整数部分。

注意到 $f[i][j]$ 只与 $f[i - 1][j]$ 和 $f[i][j - i^2]$ 有关，因此我们可以将二维数组优化为一维数组，空间复杂度降为 $O(n)$。

相似题目：

-   [322. 零钱兑换](https://github.com/doocs/leetcode/blob/main/solution/0300-0399/0322.Coin%20Change/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numSquares(self, n: int) -> int:
        m = int(sqrt(n))
        f = [[inf] * (n + 1) for _ in range(m + 1)]
        f[0][0] = 0
        for i in range(1, m + 1):
            for j in range(n + 1):
                f[i][j] = f[i - 1][j]
                if j >= i * i:
                    f[i][j] = min(f[i][j], f[i][j - i * i] + 1)
        return f[m][n]
```

#### Java

```java
class Solution {
    public int numSquares(int n) {
        int m = (int) Math.sqrt(n);
        int[][] f = new int[m + 1][n + 1];
        for (var g : f) {
            Arrays.fill(g, 1 << 30);
        }
        f[0][0] = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                f[i][j] = f[i - 1][j];
                if (j >= i * i) {
                    f[i][j] = Math.min(f[i][j], f[i][j - i * i] + 1);
                }
            }
        }
        return f[m][n];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numSquares(int n) {
        int m = sqrt(n);
        int f[m + 1][n + 1];
        memset(f, 0x3f, sizeof(f));
        f[0][0] = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                f[i][j] = f[i - 1][j];
                if (j >= i * i) {
                    f[i][j] = min(f[i][j], f[i][j - i * i] + 1);
                }
            }
        }
        return f[m][n];
    }
};
```

#### Go

```go
func numSquares(n int) int {
	m := int(math.Sqrt(float64(n)))
	f := make([][]int, m+1)
	const inf = 1 << 30
	for i := range f {
		f[i] = make([]int, n+1)
		for j := range f[i] {
			f[i][j] = inf
		}
	}
	f[0][0] = 0
	for i := 1; i <= m; i++ {
		for j := 0; j <= n; j++ {
			f[i][j] = f[i-1][j]
			if j >= i*i {
				f[i][j] = min(f[i][j], f[i][j-i*i]+1)
			}
		}
	}
	return f[m][n]
}
```

#### TypeScript

```ts
function numSquares(n: number): number {
    const m = Math.floor(Math.sqrt(n));
    const f: number[][] = Array(m + 1)
        .fill(0)
        .map(() => Array(n + 1).fill(1 << 30));
    f[0][0] = 0;
    for (let i = 1; i <= m; ++i) {
        for (let j = 0; j <= n; ++j) {
            f[i][j] = f[i - 1][j];
            if (j >= i * i) {
                f[i][j] = Math.min(f[i][j], f[i][j - i * i] + 1);
            }
        }
    }
    return f[m][n];
}
```

#### Rust

```rust
impl Solution {
    pub fn num_squares(n: i32) -> i32 {
        let (row, col) = ((n as f32).sqrt().floor() as usize, n as usize);
        let mut dp = vec![vec![i32::MAX; col + 1]; row + 1];
        dp[0][0] = 0;
        for i in 1..=row {
            for j in 0..=col {
                dp[i][j] = dp[i - 1][j];
                if j >= i * i {
                    dp[i][j] = std::cmp::min(dp[i][j], dp[i][j - i * i] + 1);
                }
            }
        }
        dp[row][col]
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numSquares(self, n: int) -> int:
        m = int(sqrt(n))
        f = [0] + [inf] * n
        for i in range(1, m + 1):
            for j in range(i * i, n + 1):
                f[j] = min(f[j], f[j - i * i] + 1)
        return f[n]
```

#### Java

```java
class Solution {
    public int numSquares(int n) {
        int m = (int) Math.sqrt(n);
        int[] f = new int[n + 1];
        Arrays.fill(f, 1 << 30);
        f[0] = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = i * i; j <= n; ++j) {
                f[j] = Math.min(f[j], f[j - i * i] + 1);
            }
        }
        return f[n];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numSquares(int n) {
        int m = sqrt(n);
        int f[n + 1];
        memset(f, 0x3f, sizeof(f));
        f[0] = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = i * i; j <= n; ++j) {
                f[j] = min(f[j], f[j - i * i] + 1);
            }
        }
        return f[n];
    }
};
```

#### Go

```go
func numSquares(n int) int {
	m := int(math.Sqrt(float64(n)))
	f := make([]int, n+1)
	for i := range f {
		f[i] = 1 << 30
	}
	f[0] = 0
	for i := 1; i <= m; i++ {
		for j := i * i; j <= n; j++ {
			f[j] = min(f[j], f[j-i*i]+1)
		}
	}
	return f[n]
}
```

#### TypeScript

```ts
function numSquares(n: number): number {
    const m = Math.floor(Math.sqrt(n));
    const f: number[] = Array(n + 1).fill(1 << 30);
    f[0] = 0;
    for (let i = 1; i <= m; ++i) {
        for (let j = i * i; j <= n; ++j) {
            f[j] = Math.min(f[j], f[j - i * i] + 1);
        }
    }
    return f[n];
}
```

#### Rust

```rust
impl Solution {
    pub fn num_squares(n: i32) -> i32 {
        let (row, col) = ((n as f32).sqrt().floor() as usize, n as usize);
        let mut dp = vec![i32::MAX; col + 1];
        dp[0] = 0;
        for i in 1..=row {
            for j in i * i..=col {
                dp[j] = std::cmp::min(dp[j], dp[j - i * i] + 1);
            }
        }
        dp[col]
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
