---
title: "0590_N 叉树的后序遍历"
date: 2025-10-08T18:36:17+08:00
weight: 10
tags: [几何, 哈希表, 字符串, 排序, 数学, 数据库, 数组, 栈, 树, 模拟, 深度优先搜索, 滑动窗口, 计数]
---

{{< markmap >}}
### [0590_N 叉树的后序遍历](#590)
#### [栈](#590)
#### [树](#590)
#### [深度优先搜索](#590)
### [0591_标签验证器](#591)
#### [栈](#591)
#### [字符串](#591)
### [0592_分数加减运算](#592)
#### [数学](#592)
#### [字符串](#592)
#### [模拟](#592)
### [0593_有效的正方形](#593)
#### [几何](#593)
#### [数学](#593)
### [0594_最长和谐子序列](#594)
#### [数组](#594)
#### [哈希表](#594)
#### [计数](#594)
#### [排序](#594)
#### [滑动窗口](#594)
### [0595_大的国家](#595)
#### [数据库](#595)
### [0596_超过 5 名学生的课](#596)
#### [数据库](#596)
### [0597_好友申请 I：总体通过率 🔒](#597)
#### [数据库](#597)
### [0598_区间加法 II](#598)
#### [数组](#598)
#### [数学](#598)
### [0599_两个列表的最小索引总和](#599)
#### [数组](#599)
#### [哈希表](#599)
#### [字符串](#599)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0590_N 叉树的后序遍历
___
#### 栈
___
#### 树
___
#### 深度优先搜索
---
### 0591_标签验证器
___
#### 栈
___
#### 字符串
---
### 0592_分数加减运算
___
#### 数学
___
#### 字符串
___
#### 模拟
---
### 0593_有效的正方形
___
#### 几何
___
#### 数学
---
### 0594_最长和谐子序列
___
#### 数组
___
#### 哈希表
___
#### 计数
___
#### 排序
___
#### 滑动窗口
---
### 0595_大的国家
___
#### 数据库
---
### 0596_超过 5 名学生的课
___
#### 数据库
---
### 0597_好友申请 I：总体通过率 🔒
___
#### 数据库
---
### 0598_区间加法 II
___
#### 数组
___
#### 数学
---
### 0599_两个列表的最小索引总和
___
#### 数组
___
#### 哈希表
___
#### 字符串
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 几何 | 哈希表 | 字符串 |
| 排序 | 数学 | 数据库 |
| 数组 | 栈 | 树 |
| 模拟 | 深度优先搜索 | 滑动窗口 |
| 计数 |  |  |

# [590. N 叉树的后序遍历](https://leetcode.cn/problems/n-ary-tree-postorder-traversal){#590}

{{< tabs "590" >}}

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
    def postorder(self, root: 'Node') -> List[int]:
        ans = []
        if root is None:
            return ans
        stk = [root]
        while stk:
            node = stk.pop()
            ans.append(node.val)
            for child in node.children:
                stk.append(child)
        return ans[::-1]
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
    public List<Integer> postorder(Node root) {
        LinkedList<Integer> ans = new LinkedList<>();
        if (root == null) {
            return ans;
        }
        Deque<Node> stk = new ArrayDeque<>();
        stk.offer(root);
        while (!stk.isEmpty()) {
            root = stk.pollLast();
            ans.addFirst(root.val);
            for (Node child : root.children) {
                stk.offer(child);
            }
        }
        return ans;
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
    vector<int> postorder(Node* root) {
        vector<int> ans;
        if (!root) {
            return ans;
        }
        stack<Node*> stk{{root}};
        while (!stk.empty()) {
            root = stk.top();
            ans.push_back(root->val);
            stk.pop();
            for (Node* child : root->children) {
                stk.push(child);
            }
        }
        reverse(ans.begin(), ans.end());
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

func postorder(root *Node) []int {
	var ans []int
	if root == nil {
		return ans
	}
	stk := []*Node{root}
	for len(stk) > 0 {
		root = stk[len(stk)-1]
		stk = stk[:len(stk)-1]
		ans = append([]int{root.Val}, ans...)
		for _, child := range root.Children {
			stk = append(stk, child)
		}
	}
	return ans
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

function postorder(root: Node | null): number[] {
    const ans: number[] = [];
    if (!root) {
        return ans;
    }
    const stk: Node[] = [root];
    while (stk.length) {
        const { val, children } = stk.pop()!;
        ans.push(val);
        stk.push(...children);
    }
    return ans.reverse();
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个 n&nbsp;叉树的根节点<meta charset="UTF-8" />&nbsp;<code>root</code>&nbsp;，返回 <em>其节点值的<strong> 后序遍历</strong></em> 。</p>

<p>n 叉树 在输入中按层序遍历进行序列化表示，每组子节点由空值 <code>null</code> 分隔（请参见示例）。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0590.N-ary%20Tree%20Postorder%20Traversal/images/narytreeexample.png" style="height: 193px; width: 300px;" /></p>

<pre>
<strong>输入：</strong>root = [1,null,3,2,4,null,5,6]
<strong>输出：</strong>[5,6,3,2,4,1]
</pre>

<p><strong class="example">示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0590.N-ary%20Tree%20Postorder%20Traversal/images/sample_4_964.png" style="height: 269px; width: 296px;" /></p>

<pre>
<strong>输入：</strong>root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
<strong>输出：</strong>[2,6,14,11,7,3,12,8,4,13,9,10,5,1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>节点总数在范围 <code>[0, 10<sup>4</sup>]</code> 内</li>
	<li><code>0 &lt;= Node.val &lt;= 10<sup>4</sup></code></li>
	<li>n 叉树的高度小于或等于 <code>1000</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>递归法很简单，你可以使用迭代法完成此题吗?</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归

我们可以递归地遍历整棵树。对于每个节点，先对该节点的每个子节点递归地调用函数，然后将节点的值加入答案。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为节点数。

<!-- tabs:start -->

#### Python3

```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""


class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        def dfs(root):
            if root is None:
                return
            for child in root.children:
                dfs(child)
            ans.append(root.val)

        ans = []
        dfs(root)
        return ans
```

#### Java

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
    private List<Integer> ans = new ArrayList<>();

    public List<Integer> postorder(Node root) {
        dfs(root);
        return ans;
    }

    private void dfs(Node root) {
        if (root == null) {
            return;
        }
        for (Node child : root.children) {
            dfs(child);
        }
        ans.add(root.val);
    }
}
```

#### C++

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
    vector<int> postorder(Node* root) {
        vector<int> ans;
        function<void(Node*)> dfs = [&](Node* root) {
            if (!root) {
                return;
            }
            for (auto& child : root->children) {
                dfs(child);
            }
            ans.push_back(root->val);
        };
        dfs(root);
        return ans;
    }
};
```

#### Go

```go
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

func postorder(root *Node) (ans []int) {
	var dfs func(*Node)
	dfs = func(root *Node) {
		if root == nil {
			return
		}
		for _, child := range root.Children {
			dfs(child)
		}
		ans = append(ans, root.Val)
	}
	dfs(root)
	return
}
```

#### TypeScript

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

function postorder(root: Node | null): number[] {
    const ans: number[] = [];
    const dfs = (root: Node | null) => {
        if (!root) {
            return;
        }
        for (const child of root.children) {
            dfs(child);
        }
        ans.push(root.val);
    };
    dfs(root);
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：迭代（栈实现）

我们也可以用迭代的方法来解决这个问题。

我们使用一个栈来帮助我们得到后序遍历，我们首先把根节点入栈，因为后序遍历是左子树、右子树、根节点，栈的特点是先进后出，所以我们先把节点的值加入答案，然后对该节点的每个子节点按照从左到右的顺序依次入栈，这样可以得到根节点、右子树、左子树的遍历结果。最后把答案反转即可得到后序遍历的结果。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为节点数。

<!-- tabs:start -->

#### Python3

```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""


class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        ans = []
        if root is None:
            return ans
        stk = [root]
        while stk:
            node = stk.pop()
            ans.append(node.val)
            for child in node.children:
                stk.append(child)
        return ans[::-1]
```

#### Java

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
    public List<Integer> postorder(Node root) {
        LinkedList<Integer> ans = new LinkedList<>();
        if (root == null) {
            return ans;
        }
        Deque<Node> stk = new ArrayDeque<>();
        stk.offer(root);
        while (!stk.isEmpty()) {
            root = stk.pollLast();
            ans.addFirst(root.val);
            for (Node child : root.children) {
                stk.offer(child);
            }
        }
        return ans;
    }
}
```

#### C++

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
    vector<int> postorder(Node* root) {
        vector<int> ans;
        if (!root) {
            return ans;
        }
        stack<Node*> stk{{root}};
        while (!stk.empty()) {
            root = stk.top();
            ans.push_back(root->val);
            stk.pop();
            for (Node* child : root->children) {
                stk.push(child);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

#### Go

```go
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

func postorder(root *Node) []int {
	var ans []int
	if root == nil {
		return ans
	}
	stk := []*Node{root}
	for len(stk) > 0 {
		root = stk[len(stk)-1]
		stk = stk[:len(stk)-1]
		ans = append([]int{root.Val}, ans...)
		for _, child := range root.Children {
			stk = append(stk, child)
		}
	}
	return ans
}
```

#### TypeScript

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

function postorder(root: Node | null): number[] {
    const ans: number[] = [];
    if (!root) {
        return ans;
    }
    const stk: Node[] = [root];
    while (stk.length) {
        const { val, children } = stk.pop()!;
        ans.push(val);
        stk.push(...children);
    }
    return ans.reverse();
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [591. 标签验证器](https://leetcode.cn/problems/tag-validator){#591}

{{< tabs "591" >}}

{{% tab "python" %}}
```python
class Solution:
    def isValid(self, code: str) -> bool:
        def check(tag):
            return 1 <= len(tag) <= 9 and all(c.isupper() for c in tag)

        stk = []
        i, n = 0, len(code)
        while i < n:
            if i and not stk:
                return False
            if code[i : i + 9] == '<![CDATA[':
                i = code.find(']]>', i + 9)
                if i < 0:
                    return False
                i += 2
            elif code[i : i + 2] == '</':
                j = i + 2
                i = code.find('>', j)
                if i < 0:
                    return False
                t = code[j:i]
                if not check(t) or not stk or stk.pop() != t:
                    return False
            elif code[i] == '<':
                j = i + 1
                i = code.find('>', j)
                if i < 0:
                    return False
                t = code[j:i]
                if not check(t):
                    return False
                stk.append(t)
            i += 1
        return not stk
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isValid(String code) {
        Deque<String> stk = new ArrayDeque<>();
        for (int i = 0; i < code.length(); ++i) {
            if (i > 0 && stk.isEmpty()) {
                return false;
            }
            if (code.startsWith("<![CDATA[", i)) {
                i = code.indexOf("]]>", i + 9);
                if (i < 0) {
                    return false;
                }
                i += 2;
            } else if (code.startsWith("</", i)) {
                int j = i + 2;
                i = code.indexOf(">", j);
                if (i < 0) {
                    return false;
                }
                String t = code.substring(j, i);
                if (!check(t) || stk.isEmpty() || !stk.pop().equals(t)) {
                    return false;
                }
            } else if (code.startsWith("<", i)) {
                int j = i + 1;
                i = code.indexOf(">", j);
                if (i < 0) {
                    return false;
                }
                String t = code.substring(j, i);
                if (!check(t)) {
                    return false;
                }
                stk.push(t);
            }
        }
        return stk.isEmpty();
    }

    private boolean check(String tag) {
        int n = tag.length();
        if (n < 1 || n > 9) {
            return false;
        }
        for (char c : tag.toCharArray()) {
            if (!Character.isUpperCase(c)) {
                return false;
            }
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
    bool isValid(string code) {
        stack<string> stk;
        for (int i = 0; i < code.size(); ++i) {
            if (i && stk.empty()) return false;
            if (code.substr(i, 9) == "<![CDATA[") {
                i = code.find("]]>", i + 9);
                if (i < 0) return false;
                i += 2;
            } else if (code.substr(i, 2) == "</") {
                int j = i + 2;
                i = code.find('>', j);
                if (i < 0) return false;
                string t = code.substr(j, i - j);
                if (!check(t) || stk.empty() || stk.top() != t) return false;
                stk.pop();
            } else if (code.substr(i, 1) == "<") {
                int j = i + 1;
                i = code.find('>', j);
                if (i < 0) return false;
                string t = code.substr(j, i - j);
                if (!check(t)) return false;
                stk.push(t);
            }
        }
        return stk.empty();
    }

    bool check(string tag) {
        int n = tag.size();
        if (n < 1 || n > 9) return false;
        for (char& c : tag)
            if (!isupper(c))
                return false;
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isValid(code string) bool {
	var stk []string
	for i := 0; i < len(code); i++ {
		if i > 0 && len(stk) == 0 {
			return false
		}
		if strings.HasPrefix(code[i:], "<![CDATA[") {
			n := strings.Index(code[i+9:], "]]>")
			if n == -1 {
				return false
			}
			i += n + 11
		} else if strings.HasPrefix(code[i:], "</") {
			if len(stk) == 0 {
				return false
			}
			j := i + 2
			n := strings.IndexByte(code[j:], '>')
			if n == -1 {
				return false
			}
			t := code[j : j+n]
			last := stk[len(stk)-1]
			stk = stk[:len(stk)-1]
			if !check(t) || last != t {
				return false
			}
			i += n + 2
		} else if strings.HasPrefix(code[i:], "<") {
			j := i + 1
			n := strings.IndexByte(code[j:], '>')
			if n == -1 {
				return false
			}
			t := code[j : j+n]
			if !check(t) {
				return false
			}
			stk = append(stk, t)
			i += n + 1
		}
	}
	return len(stk) == 0
}

func check(tag string) bool {
	n := len(tag)
	if n < 1 || n > 9 {
		return false
	}
	for _, c := range tag {
		if c < 'A' || c > 'Z' {
			return false
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn is_valid(code: String) -> bool {
        fn check(tag: &str) -> bool {
            let n = tag.len();
            n >= 1 && n <= 9 && tag.as_bytes().iter().all(|b| b.is_ascii_uppercase())
        }

        let mut stk = Vec::new();
        let mut i = 0;
        while i < code.len() {
            if i > 0 && stk.is_empty() {
                return false;
            }
            if code[i..].starts_with("<![CDATA[") {
                match code[i + 9..].find("]]>") {
                    Some(n) => {
                        i += n + 11;
                    }
                    None => {
                        return false;
                    }
                };
            } else if code[i..].starts_with("</") {
                let j = i + 2;
                match code[j..].find('>') {
                    Some(n) => {
                        let t = &code[j..j + n];
                        if !check(t) || stk.is_empty() || stk.pop().unwrap() != t {
                            return false;
                        }
                        i += n + 2;
                    }
                    None => {
                        return false;
                    }
                };
            } else if code[i..].starts_with("<") {
                let j = i + 1;
                match code[j..].find('>') {
                    Some(n) => {
                        let t = &code[j..j + n];
                        if !check(t) {
                            return false;
                        }
                        stk.push(t);
                    }
                    None => {
                        return false;
                    }
                };
            }
            i += 1;
        }
        stk.is_empty()
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个表示代码片段的字符串，你需要实现一个验证器来解析这段代码，并返回它是否合法。合法的代码片段需要遵守以下的所有规则：</p>

<ol>
	<li>代码必须被<strong>合法的闭合标签</strong>包围。否则，代码是无效的。</li>
	<li><strong>闭合标签</strong>（不一定合法）要严格符合格式：<code>&lt;TAG_NAME&gt;TAG_CONTENT&lt;/TAG_NAME&gt;</code>。其中，<code>&lt;TAG_NAME&gt;</code>是起始标签，<code>&lt;/TAG_NAME&gt;</code>是结束标签。起始和结束标签中的 TAG_NAME 应当相同。当且仅当&nbsp;TAG_NAME 和 TAG_CONTENT 都是合法的，闭合标签才是<strong>合法的</strong>。</li>
	<li><strong>合法的</strong>&nbsp;<code>TAG_NAME</code>&nbsp;仅含有<strong>大写字母</strong>，长度在范围 [1,9] 之间。否则，该&nbsp;<code>TAG_NAME</code>&nbsp;是<strong>不合法的</strong>。</li>
	<li><strong>合法的</strong>&nbsp;<code>TAG_CONTENT</code>&nbsp;可以包含其他<strong>合法的闭合标签</strong>，<strong>cdata</strong>&nbsp;（请参考规则7）和任意字符（注意参考规则1）<strong>除了</strong>不匹配的<code>&lt;</code>、不匹配的起始和结束标签、不匹配的或带有不合法 TAG_NAME 的闭合标签。否则，<code>TAG_CONTENT</code>&nbsp;是<strong>不合法的</strong>。</li>
	<li>一个起始标签，如果没有具有相同&nbsp;TAG_NAME 的结束标签与之匹配，是不合法的。反之亦然。不过，你也需要考虑标签嵌套的问题。</li>
	<li>一个<code>&lt;</code>，如果你找不到一个后续的<code>&gt;</code>与之匹配，是不合法的。并且当你找到一个<code>&lt;</code>或<code>&lt;/</code>时，所有直到下一个<code>&gt;</code>的前的字符，都应当被解析为&nbsp;TAG_NAME（不一定合法）。</li>
	<li>cdata 有如下格式：<code>&lt;![CDATA[CDATA_CONTENT]]&gt;</code>。<code>CDATA_CONTENT</code>&nbsp;的范围被定义成&nbsp;<code>&lt;![CDATA[</code>&nbsp;和<strong>后续的第一个</strong>&nbsp;<code>]]&gt;</code>之间的字符。</li>
	<li><code>CDATA_CONTENT</code>&nbsp;可以包含<strong>任意字符</strong>。cdata 的功能是阻止验证器解析<code>CDATA_CONTENT</code>，所以即使其中有一些字符可以被解析为标签（无论合法还是不合法），也应该将它们视为<strong>常规字符</strong>。</li>
</ol>

<p><strong>合法代码的例子:</strong></p>

<pre>
<strong>输入:</strong> &quot;&lt;DIV&gt;This is the first line &lt;![CDATA[&lt;div&gt;]]&gt;&lt;/DIV&gt;&quot;

<strong>输出:</strong> True

<strong>解释:</strong> 

代码被包含在了闭合的标签内： &lt;DIV&gt; 和 &lt;/DIV&gt; 。

TAG_NAME 是合法的，TAG_CONTENT 包含了一些字符和 cdata 。 

即使 CDATA_CONTENT 含有不匹配的起始标签和不合法的 TAG_NAME，它应该被视为普通的文本，而不是标签。

所以 TAG_CONTENT 是合法的，因此代码是合法的。最终返回True。


<strong>输入:</strong> &quot;&lt;DIV&gt;&gt;&gt;  ![cdata[]] &lt;![CDATA[&lt;div&gt;]&gt;]]&gt;]]&gt;&gt;]&lt;/DIV&gt;&quot;

<strong>输出:</strong> True

<strong>解释:</strong>

我们首先将代码分割为： start_tag|tag_content|end_tag 。

start_tag -&gt; <strong>&quot;&lt;DIV&gt;&quot;</strong>

end_tag -&gt; <strong>&quot;&lt;/DIV&gt;&quot;</strong>

tag_content 也可被分割为： text1|cdata|text2 。

text1 -&gt; <strong>&quot;&gt;&gt;  ![cdata[]] &quot;</strong>

cdata -&gt; <strong>&quot;&lt;![CDATA[&lt;div&gt;]&gt;]]&gt;&quot;</strong> ，其中 CDATA_CONTENT 为 <strong>&quot;&lt;div&gt;]&gt;&quot;</strong>

text2 -&gt; <strong>&quot;]]&gt;&gt;]&quot;</strong>


start_tag <strong>不</strong>是 <strong>&quot;&lt;DIV&gt;&gt;&gt;&quot;</strong> 的原因参照规则 6 。
cdata <strong>不</strong>是 <strong>&quot;&lt;![CDATA[&lt;div&gt;]&gt;]]&gt;]]&gt;&quot;</strong> 的原因参照规则 7 。
</pre>

<p><strong>不合法代码的例子:</strong></p>

<pre>
<strong>输入:</strong> &quot;&lt;A&gt;  &lt;B&gt; &lt;/A&gt;   &lt;/B&gt;&quot;
<strong>输出:</strong> False
<strong>解释:</strong> 不合法。如果 &quot;&lt;A&gt;&quot; 是闭合的，那么 &quot;&lt;B&gt;&quot; 一定是不匹配的，反之亦然。

<strong>输入:</strong> &quot;&lt;DIV&gt;  div tag is not closed  &lt;DIV&gt;&quot;
<strong>输出:</strong> False

<strong>输入:</strong> &quot;&lt;DIV&gt;  unmatched &lt;  &lt;/DIV&gt;&quot;
<strong>输出:</strong> False

<strong>输入:</strong> &quot;&lt;DIV&gt; closed tags with invalid tag name  &lt;b&gt;123&lt;/b&gt; &lt;/DIV&gt;&quot;
<strong>输出:</strong> False

<strong>输入:</strong> &quot;&lt;DIV&gt; unmatched tags with invalid tag name  &lt;/1234567890&gt; and &lt;CDATA[[]]&gt;  &lt;/DIV&gt;&quot;
<strong>输出:</strong> False

<strong>输入:</strong> &quot;&lt;DIV&gt;  unmatched start tag &lt;B&gt;  and unmatched end tag &lt;/C&gt;  &lt;/DIV&gt;&quot;
<strong>输出:</strong> False
</pre>

<p><strong>注意:</strong></p>

<ol>
	<li>为简明起见，你可以假设输入的代码（包括提到的<strong>任意字符</strong>）只包含<code>数字</code>, <font color="#c7254e" face="Menlo, Monaco, Consolas, Courier New, monospace"><span style="background-color:#f9f2f4; font-size:12.6px">字母</span></font>, <code>&#39;&lt;&#39;</code>,<code>&#39;&gt;&#39;</code>,<code>&#39;/&#39;</code>,<code>&#39;!&#39;</code>,<code>&#39;[&#39;</code>,<code>&#39;]&#39;</code>和<code>&#39; &#39;</code>。</li>
</ol>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：栈模拟

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isValid(self, code: str) -> bool:
        def check(tag):
            return 1 <= len(tag) <= 9 and all(c.isupper() for c in tag)

        stk = []
        i, n = 0, len(code)
        while i < n:
            if i and not stk:
                return False
            if code[i : i + 9] == '<![CDATA[':
                i = code.find(']]>', i + 9)
                if i < 0:
                    return False
                i += 2
            elif code[i : i + 2] == '</':
                j = i + 2
                i = code.find('>', j)
                if i < 0:
                    return False
                t = code[j:i]
                if not check(t) or not stk or stk.pop() != t:
                    return False
            elif code[i] == '<':
                j = i + 1
                i = code.find('>', j)
                if i < 0:
                    return False
                t = code[j:i]
                if not check(t):
                    return False
                stk.append(t)
            i += 1
        return not stk
```

#### Java

```java
class Solution {
    public boolean isValid(String code) {
        Deque<String> stk = new ArrayDeque<>();
        for (int i = 0; i < code.length(); ++i) {
            if (i > 0 && stk.isEmpty()) {
                return false;
            }
            if (code.startsWith("<![CDATA[", i)) {
                i = code.indexOf("]]>", i + 9);
                if (i < 0) {
                    return false;
                }
                i += 2;
            } else if (code.startsWith("</", i)) {
                int j = i + 2;
                i = code.indexOf(">", j);
                if (i < 0) {
                    return false;
                }
                String t = code.substring(j, i);
                if (!check(t) || stk.isEmpty() || !stk.pop().equals(t)) {
                    return false;
                }
            } else if (code.startsWith("<", i)) {
                int j = i + 1;
                i = code.indexOf(">", j);
                if (i < 0) {
                    return false;
                }
                String t = code.substring(j, i);
                if (!check(t)) {
                    return false;
                }
                stk.push(t);
            }
        }
        return stk.isEmpty();
    }

    private boolean check(String tag) {
        int n = tag.length();
        if (n < 1 || n > 9) {
            return false;
        }
        for (char c : tag.toCharArray()) {
            if (!Character.isUpperCase(c)) {
                return false;
            }
        }
        return true;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool isValid(string code) {
        stack<string> stk;
        for (int i = 0; i < code.size(); ++i) {
            if (i && stk.empty()) return false;
            if (code.substr(i, 9) == "<![CDATA[") {
                i = code.find("]]>", i + 9);
                if (i < 0) return false;
                i += 2;
            } else if (code.substr(i, 2) == "</") {
                int j = i + 2;
                i = code.find('>', j);
                if (i < 0) return false;
                string t = code.substr(j, i - j);
                if (!check(t) || stk.empty() || stk.top() != t) return false;
                stk.pop();
            } else if (code.substr(i, 1) == "<") {
                int j = i + 1;
                i = code.find('>', j);
                if (i < 0) return false;
                string t = code.substr(j, i - j);
                if (!check(t)) return false;
                stk.push(t);
            }
        }
        return stk.empty();
    }

    bool check(string tag) {
        int n = tag.size();
        if (n < 1 || n > 9) return false;
        for (char& c : tag)
            if (!isupper(c))
                return false;
        return true;
    }
};
```

#### Go

```go
func isValid(code string) bool {
	var stk []string
	for i := 0; i < len(code); i++ {
		if i > 0 && len(stk) == 0 {
			return false
		}
		if strings.HasPrefix(code[i:], "<![CDATA[") {
			n := strings.Index(code[i+9:], "]]>")
			if n == -1 {
				return false
			}
			i += n + 11
		} else if strings.HasPrefix(code[i:], "</") {
			if len(stk) == 0 {
				return false
			}
			j := i + 2
			n := strings.IndexByte(code[j:], '>')
			if n == -1 {
				return false
			}
			t := code[j : j+n]
			last := stk[len(stk)-1]
			stk = stk[:len(stk)-1]
			if !check(t) || last != t {
				return false
			}
			i += n + 2
		} else if strings.HasPrefix(code[i:], "<") {
			j := i + 1
			n := strings.IndexByte(code[j:], '>')
			if n == -1 {
				return false
			}
			t := code[j : j+n]
			if !check(t) {
				return false
			}
			stk = append(stk, t)
			i += n + 1
		}
	}
	return len(stk) == 0
}

func check(tag string) bool {
	n := len(tag)
	if n < 1 || n > 9 {
		return false
	}
	for _, c := range tag {
		if c < 'A' || c > 'Z' {
			return false
		}
	}
	return true
}
```

#### Rust

```rust
impl Solution {
    pub fn is_valid(code: String) -> bool {
        fn check(tag: &str) -> bool {
            let n = tag.len();
            n >= 1 && n <= 9 && tag.as_bytes().iter().all(|b| b.is_ascii_uppercase())
        }

        let mut stk = Vec::new();
        let mut i = 0;
        while i < code.len() {
            if i > 0 && stk.is_empty() {
                return false;
            }
            if code[i..].starts_with("<![CDATA[") {
                match code[i + 9..].find("]]>") {
                    Some(n) => {
                        i += n + 11;
                    }
                    None => {
                        return false;
                    }
                };
            } else if code[i..].starts_with("</") {
                let j = i + 2;
                match code[j..].find('>') {
                    Some(n) => {
                        let t = &code[j..j + n];
                        if !check(t) || stk.is_empty() || stk.pop().unwrap() != t {
                            return false;
                        }
                        i += n + 2;
                    }
                    None => {
                        return false;
                    }
                };
            } else if code[i..].starts_with("<") {
                let j = i + 1;
                match code[j..].find('>') {
                    Some(n) => {
                        let t = &code[j..j + n];
                        if !check(t) {
                            return false;
                        }
                        stk.push(t);
                    }
                    None => {
                        return false;
                    }
                };
            }
            i += 1;
        }
        stk.is_empty()
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [592. 分数加减运算](https://leetcode.cn/problems/fraction-addition-and-subtraction){#592}

{{< tabs "592" >}}

{{% tab "python" %}}
```python
class Solution:
    def fractionAddition(self, expression: str) -> str:
        x, y = 0, 6 * 7 * 8 * 9 * 10
        if expression[0].isdigit():
            expression = '+' + expression
        i, n = 0, len(expression)
        while i < n:
            sign = -1 if expression[i] == '-' else 1
            i += 1
            j = i
            while j < n and expression[j] not in '+-':
                j += 1
            s = expression[i:j]
            a, b = s.split('/')
            x += sign * int(a) * y // int(b)
            i = j
        z = gcd(x, y)
        x //= z
        y //= z
        return f'{x}/{y}'
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String fractionAddition(String expression) {
        int x = 0, y = 6 * 7 * 8 * 9 * 10;
        if (Character.isDigit(expression.charAt(0))) {
            expression = "+" + expression;
        }
        int i = 0, n = expression.length();
        while (i < n) {
            int sign = expression.charAt(i) == '-' ? -1 : 1;
            ++i;
            int j = i;
            while (j < n && expression.charAt(j) != '+' && expression.charAt(j) != '-') {
                ++j;
            }
            String s = expression.substring(i, j);
            String[] t = s.split("/");
            int a = Integer.parseInt(t[0]), b = Integer.parseInt(t[1]);
            x += sign * a * y / b;
            i = j;
        }
        int z = gcd(Math.abs(x), y);
        x /= z;
        y /= z;
        return x + "/" + y;
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
```
{{% /tab %}}
{{% tab "go" %}}
```go
func fractionAddition(expression string) string {
	x, y := 0, 6*7*8*9*10
	if unicode.IsDigit(rune(expression[0])) {
		expression = "+" + expression
	}
	i, n := 0, len(expression)
	for i < n {
		sign := 1
		if expression[i] == '-' {
			sign = -1
		}
		i++
		j := i
		for j < n && expression[j] != '+' && expression[j] != '-' {
			j++
		}
		s := expression[i:j]
		t := strings.Split(s, "/")
		a, _ := strconv.Atoi(t[0])
		b, _ := strconv.Atoi(t[1])
		x += sign * a * y / b
		i = j
	}
	z := gcd(abs(x), y)
	x /= z
	y /= z
	return fmt.Sprintf("%d/%d", x, y)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} expression
 * @return {string}
 */
var fractionAddition = function (expression) {
    let x = 0,
        y = 1;

    if (!expression.startsWith('-') && !expression.startsWith('+')) {
        expression = '+' + expression;
    }

    let i = 0;
    const n = expression.length;

    while (i < n) {
        const sign = expression[i] === '-' ? -1 : 1;
        i++;

        let j = i;
        while (j < n && expression[j] !== '+' && expression[j] !== '-') {
            j++;
        }

        const [a, b] = expression.slice(i, j).split('/').map(Number);
        x = x * b + sign * a * y;
        y *= b;
        i = j;
    }

    const gcd = (a, b) => {
        while (b !== 0) {
            [a, b] = [b, a % b];
        }
        return Math.abs(a);
    };

    const z = gcd(x, y);
    x = Math.floor(x / z);
    y = Math.floor(y / z);

    return `${x}/${y}`;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个表示分数加减运算的字符串&nbsp;<code>expression</code>&nbsp;，你需要返回一个字符串形式的计算结果。&nbsp;</p>

<p>这个结果应该是不可约分的分数，即&nbsp;<a href="https://baike.baidu.com/item/%E6%9C%80%E7%AE%80%E5%88%86%E6%95%B0" target="_blank">最简分数</a>。&nbsp;如果最终结果是一个整数，例如&nbsp;<code>2</code>，你需要将它转换成分数形式，其分母为&nbsp;<code>1</code>。所以在上述例子中, <code>2</code>&nbsp;应该被转换为&nbsp;<code>2/1</code>。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre>
<strong>输入:</strong>&nbsp;<code>expression</code>&nbsp;= "-1/2+1/2"
<strong>输出:</strong> "0/1"
</pre>

<p><strong>&nbsp;示例 2:</strong></p>

<pre>
<strong>输入:</strong>&nbsp;<code>expression</code>&nbsp;= "-1/2+1/2+1/3"
<strong>输出:</strong> "1/3"
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong>&nbsp;<code>expression</code>&nbsp;= "1/3-1/2"
<strong>输出:</strong> "-1/6"
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li>输入和输出字符串只包含&nbsp;<code>'0'</code> 到&nbsp;<code>'9'</code>&nbsp;的数字，以及&nbsp;<code>'/'</code>, <code>'+'</code> 和&nbsp;<code>'-'</code>。&nbsp;</li>
	<li>输入和输出分数格式均为&nbsp;<code>±分子/分母</code>。如果输入的第一个分数或者输出的分数是正数，则&nbsp;<code>'+'</code>&nbsp;会被省略掉。</li>
	<li>输入只包含合法的&nbsp;<strong>最简分数</strong>，每个分数的<strong>分子</strong>与<strong>分母</strong>的范围是&nbsp;<code>[1,10]</code>。&nbsp;如果分母是 1，意味着这个分数实际上是一个整数。</li>
	<li>输入的分数个数范围是 [1,10]。</li>
	<li><strong>最终结果&nbsp;</strong>的分子与分母保证是 32 位整数范围内的有效整数。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def fractionAddition(self, expression: str) -> str:
        x, y = 0, 6 * 7 * 8 * 9 * 10
        if expression[0].isdigit():
            expression = '+' + expression
        i, n = 0, len(expression)
        while i < n:
            sign = -1 if expression[i] == '-' else 1
            i += 1
            j = i
            while j < n and expression[j] not in '+-':
                j += 1
            s = expression[i:j]
            a, b = s.split('/')
            x += sign * int(a) * y // int(b)
            i = j
        z = gcd(x, y)
        x //= z
        y //= z
        return f'{x}/{y}'
```

#### Java

```java
class Solution {
    public String fractionAddition(String expression) {
        int x = 0, y = 6 * 7 * 8 * 9 * 10;
        if (Character.isDigit(expression.charAt(0))) {
            expression = "+" + expression;
        }
        int i = 0, n = expression.length();
        while (i < n) {
            int sign = expression.charAt(i) == '-' ? -1 : 1;
            ++i;
            int j = i;
            while (j < n && expression.charAt(j) != '+' && expression.charAt(j) != '-') {
                ++j;
            }
            String s = expression.substring(i, j);
            String[] t = s.split("/");
            int a = Integer.parseInt(t[0]), b = Integer.parseInt(t[1]);
            x += sign * a * y / b;
            i = j;
        }
        int z = gcd(Math.abs(x), y);
        x /= z;
        y /= z;
        return x + "/" + y;
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
```

#### Go

```go
func fractionAddition(expression string) string {
	x, y := 0, 6*7*8*9*10
	if unicode.IsDigit(rune(expression[0])) {
		expression = "+" + expression
	}
	i, n := 0, len(expression)
	for i < n {
		sign := 1
		if expression[i] == '-' {
			sign = -1
		}
		i++
		j := i
		for j < n && expression[j] != '+' && expression[j] != '-' {
			j++
		}
		s := expression[i:j]
		t := strings.Split(s, "/")
		a, _ := strconv.Atoi(t[0])
		b, _ := strconv.Atoi(t[1])
		x += sign * a * y / b
		i = j
	}
	z := gcd(abs(x), y)
	x /= z
	y /= z
	return fmt.Sprintf("%d/%d", x, y)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
```

#### JavaScript

```js
/**
 * @param {string} expression
 * @return {string}
 */
var fractionAddition = function (expression) {
    let x = 0,
        y = 1;

    if (!expression.startsWith('-') && !expression.startsWith('+')) {
        expression = '+' + expression;
    }

    let i = 0;
    const n = expression.length;

    while (i < n) {
        const sign = expression[i] === '-' ? -1 : 1;
        i++;

        let j = i;
        while (j < n && expression[j] !== '+' && expression[j] !== '-') {
            j++;
        }

        const [a, b] = expression.slice(i, j).split('/').map(Number);
        x = x * b + sign * a * y;
        y *= b;
        i = j;
    }

    const gcd = (a, b) => {
        while (b !== 0) {
            [a, b] = [b, a % b];
        }
        return Math.abs(a);
    };

    const z = gcd(x, y);
    x = Math.floor(x / z);
    y = Math.floor(y / z);

    return `${x}/${y}`;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [593. 有效的正方形](https://leetcode.cn/problems/valid-square){#593}

{{< tabs "593" >}}

{{% tab "python" %}}
```python
class Solution:
    def validSquare(
        self, p1: List[int], p2: List[int], p3: List[int], p4: List[int]
    ) -> bool:
        def check(a, b, c):
            (x1, y1), (x2, y2), (x3, y3) = a, b, c
            d1 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)
            d2 = (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3)
            d3 = (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3)
            return any(
                [
                    d1 == d2 and d1 + d2 == d3 and d1,
                    d2 == d3 and d2 + d3 == d1 and d2,
                    d1 == d3 and d1 + d3 == d2 and d1,
                ]
            )

        return (
            check(p1, p2, p3)
            and check(p2, p3, p4)
            and check(p1, p3, p4)
            and check(p1, p2, p4)
        )
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean validSquare(int[] p1, int[] p2, int[] p3, int[] p4) {
        return check(p1, p2, p3) && check(p1, p3, p4) && check(p1, p2, p4) && check(p2, p3, p4);
    }

    private boolean check(int[] a, int[] b, int[] c) {
        int x1 = a[0], y1 = a[1];
        int x2 = b[0], y2 = b[1];
        int x3 = c[0], y3 = c[1];
        int d1 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        int d2 = (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3);
        int d3 = (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3);
        if (d1 == d2 && d1 + d2 == d3 && d1 > 0) {
            return true;
        }
        if (d1 == d3 && d1 + d3 == d2 && d1 > 0) {
            return true;
        }
        if (d2 == d3 && d2 + d3 == d1 && d2 > 0) {
            return true;
        }
        return false;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        return check(p1, p2, p3) && check(p1, p3, p4) && check(p1, p2, p4) && check(p2, p3, p4);
    }

    bool check(vector<int>& a, vector<int>& b, vector<int>& c) {
        int x1 = a[0], y1 = a[1];
        int x2 = b[0], y2 = b[1];
        int x3 = c[0], y3 = c[1];
        int d1 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        int d2 = (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3);
        int d3 = (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3);
        if (d1 == d2 && d1 + d2 == d3 && d1 > 0) return true;
        if (d1 == d3 && d1 + d3 == d2 && d1 > 0) return true;
        if (d2 == d3 && d2 + d3 == d1 && d2 > 0) return true;
        return false;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func validSquare(p1 []int, p2 []int, p3 []int, p4 []int) bool {
	check := func(a, b, c []int) bool {
		x1, y1 := a[0], a[1]
		x2, y2 := b[0], b[1]
		x3, y3 := c[0], c[1]
		d1 := (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)
		d2 := (x1-x3)*(x1-x3) + (y1-y3)*(y1-y3)
		d3 := (x2-x3)*(x2-x3) + (y2-y3)*(y2-y3)
		if d1 == d2 && d1+d2 == d3 && d1 > 0 {
			return true
		}
		if d1 == d3 && d1+d3 == d2 && d1 > 0 {
			return true
		}
		if d2 == d3 && d2+d3 == d1 && d2 > 0 {
			return true
		}
		return false
	}
	return check(p1, p2, p3) && check(p1, p3, p4) && check(p1, p2, p4) && check(p2, p3, p4)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定2D空间中四个点的坐标&nbsp;<code>p1</code>,&nbsp;<code>p2</code>,&nbsp;<code>p3</code>&nbsp;和&nbsp;<code>p4</code>，如果这四个点构成一个正方形，则返回 <code>true</code> 。</p>

<p>点的坐标&nbsp;<code>p<sub>i</sub></code> 表示为 <code>[xi, yi]</code> 。 <code>输入没有任何顺序</code> 。</p>

<p>一个 <strong>有效的正方形</strong> 有四条等边和四个等角(90度角)。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
<strong>输出:</strong> true
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入：</strong>p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,12]
<b>输出：</b>false
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<b>输入：</b>p1 = [1,0], p2 = [-1,0], p3 = [0,1], p4 = [0,-1]
<b>输出：</b>true
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>p1.length == p2.length == p3.length == p4.length == 2</code></li>
	<li><code>-10<sup>4</sup>&nbsp;&lt;= x<sub>i</sub>, y<sub>i</sub>&nbsp;&lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学

若任选三个点，都能构成等腰直角三角形，说明是有效的正方形。

时间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def validSquare(
        self, p1: List[int], p2: List[int], p3: List[int], p4: List[int]
    ) -> bool:
        def check(a, b, c):
            (x1, y1), (x2, y2), (x3, y3) = a, b, c
            d1 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)
            d2 = (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3)
            d3 = (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3)
            return any(
                [
                    d1 == d2 and d1 + d2 == d3 and d1,
                    d2 == d3 and d2 + d3 == d1 and d2,
                    d1 == d3 and d1 + d3 == d2 and d1,
                ]
            )

        return (
            check(p1, p2, p3)
            and check(p2, p3, p4)
            and check(p1, p3, p4)
            and check(p1, p2, p4)
        )
```

#### Java

```java
class Solution {
    public boolean validSquare(int[] p1, int[] p2, int[] p3, int[] p4) {
        return check(p1, p2, p3) && check(p1, p3, p4) && check(p1, p2, p4) && check(p2, p3, p4);
    }

    private boolean check(int[] a, int[] b, int[] c) {
        int x1 = a[0], y1 = a[1];
        int x2 = b[0], y2 = b[1];
        int x3 = c[0], y3 = c[1];
        int d1 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        int d2 = (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3);
        int d3 = (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3);
        if (d1 == d2 && d1 + d2 == d3 && d1 > 0) {
            return true;
        }
        if (d1 == d3 && d1 + d3 == d2 && d1 > 0) {
            return true;
        }
        if (d2 == d3 && d2 + d3 == d1 && d2 > 0) {
            return true;
        }
        return false;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        return check(p1, p2, p3) && check(p1, p3, p4) && check(p1, p2, p4) && check(p2, p3, p4);
    }

    bool check(vector<int>& a, vector<int>& b, vector<int>& c) {
        int x1 = a[0], y1 = a[1];
        int x2 = b[0], y2 = b[1];
        int x3 = c[0], y3 = c[1];
        int d1 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        int d2 = (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3);
        int d3 = (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3);
        if (d1 == d2 && d1 + d2 == d3 && d1 > 0) return true;
        if (d1 == d3 && d1 + d3 == d2 && d1 > 0) return true;
        if (d2 == d3 && d2 + d3 == d1 && d2 > 0) return true;
        return false;
    }
};
```

#### Go

```go
func validSquare(p1 []int, p2 []int, p3 []int, p4 []int) bool {
	check := func(a, b, c []int) bool {
		x1, y1 := a[0], a[1]
		x2, y2 := b[0], b[1]
		x3, y3 := c[0], c[1]
		d1 := (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)
		d2 := (x1-x3)*(x1-x3) + (y1-y3)*(y1-y3)
		d3 := (x2-x3)*(x2-x3) + (y2-y3)*(y2-y3)
		if d1 == d2 && d1+d2 == d3 && d1 > 0 {
			return true
		}
		if d1 == d3 && d1+d3 == d2 && d1 > 0 {
			return true
		}
		if d2 == d3 && d2+d3 == d1 && d2 > 0 {
			return true
		}
		return false
	}
	return check(p1, p2, p3) && check(p1, p3, p4) && check(p1, p2, p4) && check(p2, p3, p4)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [594. 最长和谐子序列](https://leetcode.cn/problems/longest-harmonious-subsequence){#594}

{{< tabs "594" >}}

{{% tab "python" %}}
```python
class Solution:
    def findLHS(self, nums: List[int]) -> int:
        cnt = Counter(nums)
        return max((c + cnt[x + 1] for x, c in cnt.items() if cnt[x + 1]), default=0)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findLHS(int[] nums) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int x : nums) {
            cnt.merge(x, 1, Integer::sum);
        }
        int ans = 0;
        for (var e : cnt.entrySet()) {
            int x = e.getKey(), c = e.getValue();
            if (cnt.containsKey(x + 1)) {
                ans = Math.max(ans, c + cnt.get(x + 1));
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
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int x : nums) {
            ++cnt[x];
        }
        int ans = 0;
        for (auto& [x, c] : cnt) {
            if (cnt.contains(x + 1)) {
                ans = max(ans, c + cnt[x + 1]);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findLHS(nums []int) (ans int) {
	cnt := map[int]int{}
	for _, x := range nums {
		cnt[x]++
	}
	for x, c := range cnt {
		if c1, ok := cnt[x+1]; ok {
			ans = max(ans, c+c1)
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findLHS(nums: number[]): number {
    const cnt: Record<number, number> = {};
    for (const x of nums) {
        cnt[x] = (cnt[x] || 0) + 1;
    }
    let ans = 0;
    for (const [x, c] of Object.entries(cnt)) {
        const y = +x + 1;
        if (cnt[y]) {
            ans = Math.max(ans, c + cnt[y]);
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    pub fn find_lhs(nums: Vec<i32>) -> i32 {
        let mut cnt = HashMap::new();
        for &x in &nums {
            *cnt.entry(x).or_insert(0) += 1;
        }
        let mut ans = 0;
        for (&x, &c) in &cnt {
            if let Some(&y) = cnt.get(&(x + 1)) {
                ans = ans.max(c + y);
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

<p>和谐数组是指一个数组里元素的最大值和最小值之间的差别 <strong>正好是 <code>1</code></strong> 。</p>

<p>给你一个整数数组 <code>nums</code> ，请你在所有可能的 <span data-keyword="subsequence-array">子序列</span> 中找到最长的和谐子序列的长度。</p>

<p>数组的 <strong>子序列</strong> 是一个由数组派生出来的序列，它可以通过删除一些元素或不删除元素、且不改变其余元素的顺序而得到。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [1,3,2,2,5,2,3,7]</span></p>

<p><span class="example-io"><b>输出：</b>5</span></p>

<p><strong>解释：</strong></p>

<p>最长和谐子序列是&nbsp;<code>[3,2,2,2,3]</code>。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,2,3,4]</span></p>

<p><span class="example-io"><b>输出：</b>2</span></p>

<p><strong>解释：</strong></p>

<p>最长和谐子序列是&nbsp;<code>[1,2]</code>，<code>[2,3]</code>&nbsp;和&nbsp;<code>[3,4]</code>，长度都为 2。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [1,1,1,1]</span></p>

<p><span class="example-io"><b>输出：</b>0</span></p>

<p><strong>解释：</strong></p>

<p>不存在和谐子序列。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们可以用一个哈希表 $\textit{cnt}$ 记录数组 $\textit{nums}$ 中每个元素出现的次数，然后遍历哈希表中的每个键值对 $(x, c)$，如果哈希表中存在键 $x + 1$，那么 $\textit{nums}$ 中元素 $x$ 和 $x + 1$ 出现的次数之和 $c + \textit{cnt}[x + 1]$ 就是一个和谐子序列，我们只需要在所有和谐子序列中找到最大的长度即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findLHS(self, nums: List[int]) -> int:
        cnt = Counter(nums)
        return max((c + cnt[x + 1] for x, c in cnt.items() if cnt[x + 1]), default=0)
```

#### Java

```java
class Solution {
    public int findLHS(int[] nums) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int x : nums) {
            cnt.merge(x, 1, Integer::sum);
        }
        int ans = 0;
        for (var e : cnt.entrySet()) {
            int x = e.getKey(), c = e.getValue();
            if (cnt.containsKey(x + 1)) {
                ans = Math.max(ans, c + cnt.get(x + 1));
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
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int x : nums) {
            ++cnt[x];
        }
        int ans = 0;
        for (auto& [x, c] : cnt) {
            if (cnt.contains(x + 1)) {
                ans = max(ans, c + cnt[x + 1]);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findLHS(nums []int) (ans int) {
	cnt := map[int]int{}
	for _, x := range nums {
		cnt[x]++
	}
	for x, c := range cnt {
		if c1, ok := cnt[x+1]; ok {
			ans = max(ans, c+c1)
		}
	}
	return
}
```

#### TypeScript

```ts
function findLHS(nums: number[]): number {
    const cnt: Record<number, number> = {};
    for (const x of nums) {
        cnt[x] = (cnt[x] || 0) + 1;
    }
    let ans = 0;
    for (const [x, c] of Object.entries(cnt)) {
        const y = +x + 1;
        if (cnt[y]) {
            ans = Math.max(ans, c + cnt[y]);
        }
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn find_lhs(nums: Vec<i32>) -> i32 {
        let mut cnt = HashMap::new();
        for &x in &nums {
            *cnt.entry(x).or_insert(0) += 1;
        }
        let mut ans = 0;
        for (&x, &c) in &cnt {
            if let Some(&y) = cnt.get(&(x + 1)) {
                ans = ans.max(c + y);
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

# [595. 大的国家](https://leetcode.cn/problems/big-countries){#595}

{{< tabs "595" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT name, population, area
FROM World
WHERE area >= 3000000
UNION
SELECT name, population, area
FROM World
WHERE population >= 25000000;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><code>World</code> 表：</p>

<div class="top-view__1vxA">
<div class="original__bRMd">
<div>
<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| name        | varchar |
| continent   | varchar |
| area        | int     |
| population  | int     |
| gdp         | bigint  |
+-------------+---------+
<code>name</code> 是该表的主键（具有唯一值的列）。
这张表的每一行提供：国家名称、所属大陆、面积、人口和 GDP 值。
</pre>

<p>&nbsp;</p>

<p>如果一个国家满足下述两个条件之一，则认为该国是 <strong>大国</strong> ：</p>

<ul>
	<li>面积至少为 300 万平方公里（即，<code>3000000 km<sup>2</sup></code>），或者</li>
	<li>人口至少为 2500 万（即 <code>25000000</code>）</li>
</ul>

<p>编写解决方案找出&nbsp;<strong>大国</strong> 的国家名称、人口和面积。</p>

<p>按 <strong>任意顺序</strong> 返回结果表。</p>

<p>返回结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例：</strong></p>

<pre>
<strong>输入：</strong>
World 表：
+-------------+-----------+---------+------------+--------------+
| name        | continent | area    | population | gdp          |
+-------------+-----------+---------+------------+--------------+
| Afghanistan | Asia      | 652230  | 25500100   | 20343000000  |
| Albania     | Europe    | 28748   | 2831741    | 12960000000  |
| Algeria     | Africa    | 2381741 | 37100000   | 188681000000 |
| Andorra     | Europe    | 468     | 78115      | 3712000000   |
| Angola      | Africa    | 1246700 | 20609294   | 100990000000 |
+-------------+-----------+---------+------------+--------------+
<strong>输出：</strong>
+-------------+------------+---------+
| name        | population | area    |
+-------------+------------+---------+
| Afghanistan | 25500100   | 652230  |
| Algeria     | 37100000   | 2381741 |
+-------------+------------+---------+
</pre>
</div>
</div>
</div>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：使用 WHERE + OR

我们可以使用 `WHERE` + `OR` 查询出所有符合条件的国家。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT name, population, area
FROM World
WHERE area >= 3000000 OR population >= 25000000;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：使用 UNION

我们可以查询出所有面积大于等于 300 万平方公里的国家，然后再查询出所有人口大于等于 2500 万的国家，最后使用 `UNION` 将两个结果集合并起来。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT name, population, area
FROM World
WHERE area >= 3000000
UNION
SELECT name, population, area
FROM World
WHERE population >= 25000000;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [596. 超过 5 名学生的课](https://leetcode.cn/problems/classes-with-at-least-5-students){#596}

{{< tabs "596" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT class
FROM Courses
GROUP BY 1
HAVING COUNT(1) >= 5;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表:&nbsp;<code>Courses</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| student     | varchar |
| class       | varchar |
+-------------+---------+
(student, class)是该表的主键（不同值的列的组合）。
该表的每一行表示学生的名字和他们注册的班级。
</pre>

<p>&nbsp;</p>

<p>查询&nbsp;<strong>至少有 5 个学生</strong> 的所有班级。</p>

<p>以 <strong>任意顺序 </strong>返回结果表。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
Courses table:
+---------+----------+
| student | class    |
+---------+----------+
| A       | Math     |
| B       | English  |
| C       | Math     |
| D       | Biology  |
| E       | Math     |
| F       | Computer |
| G       | Math     |
| H       | Math     |
| I       | Math     |
+---------+----------+
<strong>输出:</strong> 
+---------+ 
| class &nbsp; | 
+---------+ 
| Math &nbsp; &nbsp;| 
+---------+
<strong>解释: </strong>
-数学课有 6 个学生，所以我们包括它。
-英语课有 1 名学生，所以我们不包括它。
-生物课有 1 名学生，所以我们不包括它。
-计算机课有 1 个学生，所以我们不包括它。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分组统计

我们可以使用 `GROUP BY` 语句，按照班级分组，然后使用 `HAVING` 语句，筛选出学生数量大于等于 $5$ 的班级。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT class
FROM Courses
GROUP BY 1
HAVING COUNT(1) >= 5;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [597. 好友申请 I：总体通过率 🔒](https://leetcode.cn/problems/friend-requests-i-overall-acceptance-rate){#597}

{{< tabs "597" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    ROUND(
        IFNULL(
            (
                SELECT COUNT(DISTINCT requester_id, accepter_id)
                FROM RequestAccepted
            ) / (SELECT COUNT(DISTINCT sender_id, send_to_id) FROM FriendRequest),
            0
        ),
        2
    ) AS accept_rate;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>FriendRequest</code></p>

<pre>
+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| sender_id      | int     |
| send_to_id     | int     |
| request_date   | date    |
+----------------+---------+
该表可能包含重复项（换句话说，在SQL中，该表没有主键）。
该表包含发送请求的用户的 ID ，接受请求的用户的 ID 以及请求的日期。
</pre>

<p>&nbsp;</p>

<p>表：<code>RequestAccepted</code></p>

<pre>
+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| requester_id   | int     |
| accepter_id    | int     |
| accept_date    | date    |
+----------------+---------+
该表可能包含重复项（换句话说，在SQL中，该表没有主键）。
该表包含发送请求的用户的 ID ，接受请求的用户的 ID 以及请求通过的日期。</pre>

<p>&nbsp;</p>

<p>求出好友申请的通过率，用 2 位小数表示。通过率由接受好友申请的数目除以申请总数。</p>

<p><strong>提示：</strong></p>

<ul>
	<li>通过的好友申请不一定都在表&nbsp;<code>friend_request</code>&nbsp;中。你只需要统计总的被通过的申请数（不管它们在不在表&nbsp;<code>FriendRequest</code>&nbsp;中），并将它除以申请总数，得到通过率</li>
	<li>一个好友申请发送者有可能会给接受者发几条好友申请，也有可能一个好友申请会被通过好几次。这种情况下，重复的好友申请只统计一次。</li>
	<li>如果一个好友申请都没有，你应该返回&nbsp;<code>accept_rate</code>&nbsp;为 0.00 。</li>
</ul>

<p>返回结果应该如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
FriendRequest 表：
+-----------+------------+--------------+
| sender_id | send_to_id | request_date |
+-----------+------------+--------------+
| 1         | 2          | 2016/06/01   |
| 1         | 3          | 2016/06/01   |
| 1         | 4          | 2016/06/01   |
| 2         | 3          | 2016/06/02   |
| 3         | 4          | 2016/06/09   |
+-----------+------------+--------------+
RequestAccepted 表：
+--------------+-------------+-------------+
| requester_id | accepter_id | accept_date |
+--------------+-------------+-------------+
| 1            | 2           | 2016/06/03  |
| 1            | 3           | 2016/06/08  |
| 2            | 3           | 2016/06/08  |
| 3            | 4           | 2016/06/09  |
| 3            | 4           | 2016/06/10  |
+--------------+-------------+-------------+
<strong>输出：</strong>
+-------------+
| accept_rate |
+-------------+
| 0.8         |
+-------------+
<strong>解释：</strong>
总共有 5 个请求，有 4 个不同的通过请求，所以通过率是 0.80</pre>

<p>&nbsp;</p>

<p><strong>进阶:</strong></p>

<ul>
	<li>你能写一个查询语句得到每个月的通过率吗？</li>
	<li>你能求出每一天的累计通过率吗？</li>
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

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    ROUND(
        IFNULL(
            (
                SELECT COUNT(DISTINCT requester_id, accepter_id)
                FROM RequestAccepted
            ) / (SELECT COUNT(DISTINCT sender_id, send_to_id) FROM FriendRequest),
            0
        ),
        2
    ) AS accept_rate;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [598. 区间加法 II](https://leetcode.cn/problems/range-addition-ii){#598}

{{< tabs "598" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxCount(self, m: int, n: int, ops: List[List[int]]) -> int:
        for a, b in ops:
            m = min(m, a)
            n = min(n, b)
        return m * n
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxCount(int m, int n, int[][] ops) {
        for (int[] op : ops) {
            m = Math.min(m, op[0]);
            n = Math.min(n, op[1]);
        }
        return m * n;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for (auto op : ops) {
            m = min(m, op[0]);
            n = min(n, op[1]);
        }
        return m * n;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxCount(m int, n int, ops [][]int) int {
	for _, op := range ops {
		m = min(m, op[0])
		n = min(n, op[1])
	}
	return m * n
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxCount(m: number, n: number, ops: number[][]): number {
    for (const [a, b] of ops) {
        m = Math.min(m, a);
        n = Math.min(n, b);
    }
    return m * n;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn max_count(mut m: i32, mut n: i32, ops: Vec<Vec<i32>>) -> i32 {
        for op in ops {
            m = m.min(op[0]);
            n = n.min(op[1]);
        }
        m * n
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} m
 * @param {number} n
 * @param {number[][]} ops
 * @return {number}
 */
var maxCount = function (m, n, ops) {
    for (const [a, b] of ops) {
        m = Math.min(m, a);
        n = Math.min(n, b);
    }
    return m * n;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 <code>m x&nbsp;n</code> 的矩阵&nbsp;<code>M</code><strong> </strong>和一个操作数组 <code>op</code> 。矩阵初始化时所有的单元格都为 <code>0</code> 。<code>ops[i] = [ai, bi]</code> 意味着当所有的 <code>0 &lt;= x &lt; ai</code> 和 <code>0 &lt;= y &lt; bi</code> 时， <code>M[x][y]</code> 应该加 1。</p>

<p>在&nbsp;<em>执行完所有操作后</em>&nbsp;，计算并返回&nbsp;<em>矩阵中最大整数的个数</em>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0598.Range%20Addition%20II/images/ex1.jpg" style="height: 176px; width: 750px;" /></p>

<pre>
<strong>输入:</strong> m = 3, n = 3，ops = [[2,2],[3,3]]
<strong>输出:</strong> 4
<strong>解释:</strong> M 中最大的整数是 2, 而且 M 中有4个值为2的元素。因此返回 4。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> m = 3, n = 3, ops = [[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3]]
<strong>输出:</strong> 4
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> m = 3, n = 3, ops = []
<strong>输出:</strong> 9
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<p><meta charset="UTF-8" /></p>

<ul>
	<li><code>1 &lt;= m, n &lt;= 4 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= ops.length &lt;= 10<sup>4</sup></code></li>
	<li><code>ops[i].length == 2</code></li>
	<li><code>1 &lt;= a<sub>i</sub>&nbsp;&lt;= m</code></li>
	<li><code>1 &lt;= b<sub>i</sub>&nbsp;&lt;= n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：脑筋急转弯

我们注意到，所有操作子矩阵的交集就是最终的最大整数所在的子矩阵，并且每个操作子矩阵都是从左上角 $(0, 0)$ 开始的，因此，我们遍历所有操作子矩阵，求出行数和列数的最小值，最后返回这两个值的乘积即可。

注意，如果操作数组为空，那么矩阵中的最大整数个数就是 $m \times n$。

时间复杂度 $O(k)$，其中 $k$ 是操作数组 $\textit{ops}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxCount(self, m: int, n: int, ops: List[List[int]]) -> int:
        for a, b in ops:
            m = min(m, a)
            n = min(n, b)
        return m * n
```

#### Java

```java
class Solution {
    public int maxCount(int m, int n, int[][] ops) {
        for (int[] op : ops) {
            m = Math.min(m, op[0]);
            n = Math.min(n, op[1]);
        }
        return m * n;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for (auto op : ops) {
            m = min(m, op[0]);
            n = min(n, op[1]);
        }
        return m * n;
    }
};
```

#### Go

```go
func maxCount(m int, n int, ops [][]int) int {
	for _, op := range ops {
		m = min(m, op[0])
		n = min(n, op[1])
	}
	return m * n
}
```

#### TypeScript

```ts
function maxCount(m: number, n: number, ops: number[][]): number {
    for (const [a, b] of ops) {
        m = Math.min(m, a);
        n = Math.min(n, b);
    }
    return m * n;
}
```

#### Rust

```rust
impl Solution {
    pub fn max_count(mut m: i32, mut n: i32, ops: Vec<Vec<i32>>) -> i32 {
        for op in ops {
            m = m.min(op[0]);
            n = n.min(op[1]);
        }
        m * n
    }
}
```

#### JavaScript

```js
/**
 * @param {number} m
 * @param {number} n
 * @param {number[][]} ops
 * @return {number}
 */
var maxCount = function (m, n, ops) {
    for (const [a, b] of ops) {
        m = Math.min(m, a);
        n = Math.min(n, b);
    }
    return m * n;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [599. 两个列表的最小索引总和](https://leetcode.cn/problems/minimum-index-sum-of-two-lists){#599}

{{< tabs "599" >}}

{{% tab "python" %}}
```python
class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        d = {s: i for i, s in enumerate(list2)}
        ans = []
        mi = inf
        for i, s in enumerate(list1):
            if s in d:
                j = d[s]
                if i + j < mi:
                    mi = i + j
                    ans = [s]
                elif i + j == mi:
                    ans.append(s)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String[] findRestaurant(String[] list1, String[] list2) {
        Map<String, Integer> d = new HashMap<>();
        for (int i = 0; i < list2.length; ++i) {
            d.put(list2[i], i);
        }
        List<String> ans = new ArrayList<>();
        int mi = 1 << 30;
        for (int i = 0; i < list1.length; ++i) {
            if (d.containsKey(list1[i])) {
                int j = d.get(list1[i]);
                if (i + j < mi) {
                    mi = i + j;
                    ans.clear();
                    ans.add(list1[i]);
                } else if (i + j == mi) {
                    ans.add(list1[i]);
                }
            }
        }
        return ans.toArray(new String[0]);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> d;
        for (int i = 0; i < list2.size(); ++i) {
            d[list2[i]] = i;
        }
        vector<string> ans;
        int mi = INT_MAX;
        for (int i = 0; i < list1.size(); ++i) {
            if (d.contains(list1[i])) {
                int j = d[list1[i]];
                if (i + j < mi) {
                    mi = i + j;
                    ans.clear();
                    ans.push_back(list1[i]);
                } else if (i + j == mi) {
                    ans.push_back(list1[i]);
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
func findRestaurant(list1 []string, list2 []string) []string {
	d := map[string]int{}
	for i, s := range list2 {
		d[s] = i
	}
	ans := []string{}
	mi := 1 << 30
	for i, s := range list1 {
		if j, ok := d[s]; ok {
			if i+j < mi {
				mi = i + j
				ans = []string{s}
			} else if i+j == mi {
				ans = append(ans, s)
			}
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findRestaurant(list1: string[], list2: string[]): string[] {
    const d = new Map<string, number>(list2.map((s, i) => [s, i]));
    let mi = Infinity;
    const ans: string[] = [];
    list1.forEach((s, i) => {
        if (d.has(s)) {
            const j = d.get(s)!;
            if (i + j < mi) {
                mi = i + j;
                ans.length = 0;
                ans.push(s);
            } else if (i + j === mi) {
                ans.push(s);
            }
        }
    });
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    pub fn find_restaurant(list1: Vec<String>, list2: Vec<String>) -> Vec<String> {
        let mut d = HashMap::new();
        for (i, s) in list2.iter().enumerate() {
            d.insert(s, i);
        }

        let mut ans = Vec::new();
        let mut mi = std::i32::MAX;

        for (i, s) in list1.iter().enumerate() {
            if let Some(&j) = d.get(s) {
                if (i as i32 + j as i32) < mi {
                    mi = i as i32 + j as i32;
                    ans = vec![s.clone()];
                } else if (i as i32 + j as i32) == mi {
                    ans.push(s.clone());
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

<p>给定两个字符串数组&nbsp;<code>list1</code> 和 <code>list2</code>，找到 <strong>索引和最小的公共字符串</strong>。</p>

<p><strong>公共字符串</strong>&nbsp;是同时出现在&nbsp;<code>list1</code> 和 <code>list2</code>&nbsp;中的字符串。</p>

<p>具有 <strong>最小索引和的公共字符串</strong> 是指，如果它在 <code>list1[i]</code> 和 <code>list2[j]</code> 中出现，那么 <code>i + j</code> 应该是所有其他 <strong>公共字符串</strong> 中的最小值。</p>

<p>返回所有 <strong>具有最小索引和的公共字符串</strong>。以 <strong>任何顺序</strong> 返回答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入: </strong>list1 = ["Shogun", "Tapioca Express", "Burger King", "KFC"]，list2 = ["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
<strong>输出:</strong> ["Shogun"]
<strong>解释:</strong> 唯一的公共字符串是 “Shogun”。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong>list1 = ["Shogun", "Tapioca Express", "Burger King", "KFC"]，list2 = ["KFC", "Shogun", "Burger King"]
<strong>输出:</strong> ["Shogun"]
<strong>解释:</strong> 具有最小索引和的公共字符串是 “Shogun”，它有最小的索引和 = (0 + 1) = 1。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>list1 = ["happy","sad","good"], list2 = ["sad","happy","good"]
<b>输出：</b>["sad","happy"]
<b>解释：</b>有三个公共字符串：
"happy" 索引和 = (0 + 1) = 1.
"sad" 索引和 = (1 + 0) = 1.
"good" 索引和 = (2 + 2) = 4.
最小索引和的字符串是 "sad" 和 "happy"。</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= list1.length, list2.length &lt;= 1000</code></li>
	<li><code>1 &lt;= list1[i].length, list2[i].length &lt;= 30</code>&nbsp;</li>
	<li><code>list1[i]</code> 和 <code>list2[i]</code> 由空格<meta charset="UTF-8" />&nbsp;<code>' '</code>&nbsp;和英文字母组成。</li>
	<li><code>list1</code> 的所有字符串都是 <strong>唯一</strong> 的。</li>
	<li><code>list2</code> 中的所有字符串都是 <strong>唯一</strong> 的。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们用一个哈希表 $\textit{d}$ 记录 $\textit{list2}$ 中的字符串和它们的下标，用一个变量 $\textit{mi}$ 记录最小的下标和。

然后遍历 $\textit{list1}$，对于每个字符串 $\textit{s}$，如果 $\textit{s}$ 在 $\textit{list2}$ 中出现，那么我们计算 $\textit{s}$ 在 $\textit{list1}$ 中的下标 $\textit{i}$ 和在 $\textit{list2}$ 中的下标 $\textit{j}$，如果 $\textit{i} + \textit{j} < \textit{mi}$，我们就更新答案数组 $\textit{ans}$ 为 $\textit{s}$，并且更新 $\textit{mi}$ 为 $\textit{i} + \textit{j}$；如果 $\textit{i} + \textit{j} = \textit{mi}$，我们就将 $\textit{s}$ 加入答案数组 $\textit{ans}$。

遍历结束后，返回答案数组 $\textit{ans}$ 即可。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        d = {s: i for i, s in enumerate(list2)}
        ans = []
        mi = inf
        for i, s in enumerate(list1):
            if s in d:
                j = d[s]
                if i + j < mi:
                    mi = i + j
                    ans = [s]
                elif i + j == mi:
                    ans.append(s)
        return ans
```

#### Java

```java
class Solution {
    public String[] findRestaurant(String[] list1, String[] list2) {
        Map<String, Integer> d = new HashMap<>();
        for (int i = 0; i < list2.length; ++i) {
            d.put(list2[i], i);
        }
        List<String> ans = new ArrayList<>();
        int mi = 1 << 30;
        for (int i = 0; i < list1.length; ++i) {
            if (d.containsKey(list1[i])) {
                int j = d.get(list1[i]);
                if (i + j < mi) {
                    mi = i + j;
                    ans.clear();
                    ans.add(list1[i]);
                } else if (i + j == mi) {
                    ans.add(list1[i]);
                }
            }
        }
        return ans.toArray(new String[0]);
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> d;
        for (int i = 0; i < list2.size(); ++i) {
            d[list2[i]] = i;
        }
        vector<string> ans;
        int mi = INT_MAX;
        for (int i = 0; i < list1.size(); ++i) {
            if (d.contains(list1[i])) {
                int j = d[list1[i]];
                if (i + j < mi) {
                    mi = i + j;
                    ans.clear();
                    ans.push_back(list1[i]);
                } else if (i + j == mi) {
                    ans.push_back(list1[i]);
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findRestaurant(list1 []string, list2 []string) []string {
	d := map[string]int{}
	for i, s := range list2 {
		d[s] = i
	}
	ans := []string{}
	mi := 1 << 30
	for i, s := range list1 {
		if j, ok := d[s]; ok {
			if i+j < mi {
				mi = i + j
				ans = []string{s}
			} else if i+j == mi {
				ans = append(ans, s)
			}
		}
	}
	return ans
}
```

#### TypeScript

```ts
function findRestaurant(list1: string[], list2: string[]): string[] {
    const d = new Map<string, number>(list2.map((s, i) => [s, i]));
    let mi = Infinity;
    const ans: string[] = [];
    list1.forEach((s, i) => {
        if (d.has(s)) {
            const j = d.get(s)!;
            if (i + j < mi) {
                mi = i + j;
                ans.length = 0;
                ans.push(s);
            } else if (i + j === mi) {
                ans.push(s);
            }
        }
    });
    return ans;
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn find_restaurant(list1: Vec<String>, list2: Vec<String>) -> Vec<String> {
        let mut d = HashMap::new();
        for (i, s) in list2.iter().enumerate() {
            d.insert(s, i);
        }

        let mut ans = Vec::new();
        let mut mi = std::i32::MAX;

        for (i, s) in list1.iter().enumerate() {
            if let Some(&j) = d.get(s) {
                if (i as i32 + j as i32) < mi {
                    mi = i as i32 + j as i32;
                    ans = vec![s.clone()];
                } else if (i as i32 + j as i32) == mi {
                    ans.push(s.clone());
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
