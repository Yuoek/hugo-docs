---
title: "0429_N-aryTreeLevelOrderTraversal"
date: 2025-10-06T00:42:37+08:00
weight: 0429
tags: [Tree, Breadth-First Search]
---


{{< katex />}}

{{< badge title="Difficulty" value="Medium" >}}

<!-- problem:start -->

# [429. N-ary Tree Level Order Traversal](https://leetcode.com/problems/n-ary-tree-level-order-traversal)

[中文文档](/solution/0400-0499/0429.N-ary%20Tree%20Level%20Order%20Traversal/README.md)

## Description

<!-- description:start -->

<p>Given an n-ary tree, return the <em>level order</em> traversal of its nodes&#39; values.</p>

<p><em>Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0429.N-ary%20Tree%20Level%20Order%20Traversal/images/narytreeexample.png" style="width: 100%; max-width: 300px;" /></p>

<pre>
<strong>Input:</strong> root = [1,null,3,2,4,null,5,6]
<strong>Output:</strong> [[1],[3,2,4],[5,6]]
</pre>

<p><strong class="example">Example 2:</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0429.N-ary%20Tree%20Level%20Order%20Traversal/images/sample_4_964.png" style="width: 296px; height: 241px;" /></p>

<pre>
<strong>Input:</strong> root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
<strong>Output:</strong> [[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The height of the n-ary tree is less than or equal to <code>1000</code></li>
	<li>The total number of nodes is between <code>[0, 10<sup>4</sup>]</code></li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: BFS

First, we check if the root node is null. If it is, we return an empty list directly.

Otherwise, we create a queue $q$ and initially add the root node to the queue.

When the queue is not empty, we loop through the following operations:

1. Create an empty list $t$ to store the values of the current level nodes.
2. For each node in the queue, add its value to $t$ and add its child nodes to the queue.
3. Add $t$ to the result list $ans$.

Finally, return the result list $ans$.

The time complexity is $O(n)$, and the space complexity is $O(n)$. Here, $n$ is the number of nodes in the N-ary tree.

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### Solution 2: DFS

We can use the Depth-First Search method to traverse the entire tree.

We define a helper function $dfs(root, i)$, where $root$ represents the current node, and $i$ represents the current level.

In the $dfs$ function, we first check if $root$ is null. If it is, we return directly.

Otherwise, we check if the length of $ans$ is less than or equal to $i$. If it is, it means that the current level has not been added to $ans$ yet, so we need to add an empty list first. Then we add the value of $root$ to $ans[i]$.

Next, we traverse all child nodes of $root$. For each child node, we call $dfs(child, i + 1)$.

In the main function, we call $dfs(root, 0)$ and return $ans$.

The time complexity is $O(n)$, and the space complexity is $O(n)$. Here, $n$ is the number of nodes in the N-ary tree.

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""


class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        def dfs(root, i):
            if root is None:
                return
            if len(ans) <= i:
                ans.append([])
            ans[i].append(root.val)
            for child in root.children:
                dfs(child, i + 1)

        ans = []
        dfs(root, 0)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    private List<List<Integer>> ans = new ArrayList<>();

    public List<List<Integer>> levelOrder(Node root) {
        dfs(root, 0);
        return ans;
    }

    private void dfs(Node root, int i) {
        if (root == null) {
            return;
        }
        if (ans.size() <= i) {
            ans.add(new ArrayList<>());
        }
        ans.get(i++).add(root.val);
        for (Node child : root.children) {
            dfs(child, i);
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        function<void(Node*, int i)> dfs = [&](Node* root, int i) {
            if (!root) {
                return;
            }
            if (ans.size() <= i) {
                ans.push_back({});
            }
            ans[i++].push_back(root->val);
            for (auto& child : root->children) {
                dfs(child, i);
            }
        };
        dfs(root, 0);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

func levelOrder(root *Node) (ans [][]int) {
	var dfs func(root *Node, i int)
	dfs = func(root *Node, i int) {
		if root == nil {
			return
		}
		if len(ans) <= i {
			ans = append(ans, []int{})
		}
		ans[i] = append(ans[i], root.Val)
		for _, child := range root.Children {
			dfs(child, i+1)
		}
	}
	dfs(root, 0)
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for node.
 * class Node {
 *     val: number
 *     children: Node[]
 *     constructor(val?: number) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.children = []
 *     }
 * }
 */

function levelOrder(root: Node | null): number[][] {
    const ans: number[][] = [];
    const dfs = (root: Node | null, i: number) => {
        if (root === null) {
            return;
        }
        if (ans.length <= i) {
            ans.push([]);
        }
        const { val, children } = root;
        ans[i++].push(val);
        children.forEach(node => dfs(node, i));
    };
    dfs(root, 0);
    return ans;
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""


class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        def dfs(root, i):
            if root is None:
                return
            if len(ans) <= i:
                ans.append([])
            ans[i].append(root.val)
            for child in root.children:
                dfs(child, i + 1)

        ans = []
        dfs(root, 0)
        return ans
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    private List<List<Integer>> ans = new ArrayList<>();

    public List<List<Integer>> levelOrder(Node root) {
        dfs(root, 0);
        return ans;
    }

    private void dfs(Node root, int i) {
        if (root == null) {
            return;
        }
        if (ans.size() <= i) {
            ans.add(new ArrayList<>());
        }
        ans.get(i++).add(root.val);
        for (Node child : root.children) {
            dfs(child, i);
        }
    }
}
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "cpp 可视化" %}}
{{< pythontutor width="100%" height="800" language="cpp" >}}
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        function<void(Node*, int i)> dfs = [&](Node* root, int i) {
            if (!root) {
                return;
            }
            if (ans.size() <= i) {
                ans.push_back({});
            }
            ans[i++].push_back(root->val);
            for (auto& child : root->children) {
                dfs(child, i);
            }
        };
        dfs(root, 0);
        return ans;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}