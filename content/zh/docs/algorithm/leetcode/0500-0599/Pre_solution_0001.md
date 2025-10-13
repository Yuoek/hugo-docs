---
title: "0500_键盘行"
date: 2025-10-08T18:36:17+08:00
weight: 1
tags: [二叉搜索树, 二叉树, 动态规划, 单调栈, 哈希表, 图, 堆（优先队列）, 字符串, 广度优先搜索, 排序, 数学, 数组, 最短路, 栈, 树, 深度优先搜索, 矩阵, 记忆化搜索, 贪心, 递归]
---

{{< markmap >}}
### [0500_键盘行](#500)
#### [数组](#500)
#### [哈希表](#500)
#### [字符串](#500)
### [0501_二叉搜索树中的众数](#501)
#### [树](#501)
#### [深度优先搜索](#501)
#### [二叉搜索树](#501)
#### [二叉树](#501)
### [0502_IPO](#502)
#### [贪心](#502)
#### [数组](#502)
#### [排序](#502)
#### [堆（优先队列）](#502)
### [0503_下一个更大元素 II](#503)
#### [栈](#503)
#### [数组](#503)
#### [单调栈](#503)
### [0504_七进制数](#504)
#### [数学](#504)
#### [字符串](#504)
### [0505_迷宫 II 🔒](#505)
#### [深度优先搜索](#505)
#### [广度优先搜索](#505)
#### [图](#505)
#### [数组](#505)
#### [矩阵](#505)
#### [最短路](#505)
#### [堆（优先队列）](#505)
### [0506_相对名次](#506)
#### [数组](#506)
#### [排序](#506)
#### [堆（优先队列）](#506)
### [0507_完美数](#507)
#### [数学](#507)
### [0508_出现次数最多的子树元素和](#508)
#### [树](#508)
#### [深度优先搜索](#508)
#### [哈希表](#508)
#### [二叉树](#508)
### [0509_斐波那契数](#509)
#### [递归](#509)
#### [记忆化搜索](#509)
#### [数学](#509)
#### [动态规划](#509)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0500_键盘行
___
#### 数组
___
#### 哈希表
___
#### 字符串
---
### 0501_二叉搜索树中的众数
___
#### 树
___
#### 深度优先搜索
___
#### 二叉搜索树
___
#### 二叉树
---
### 0502_IPO
___
#### 贪心
___
#### 数组
___
#### 排序
___
#### 堆（优先队列）
---
### 0503_下一个更大元素 II
___
#### 栈
___
#### 数组
___
#### 单调栈
---
### 0504_七进制数
___
#### 数学
___
#### 字符串
---
### 0505_迷宫 II 🔒
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 图
___
#### 数组
___
#### 矩阵
___
#### 最短路
___
#### 堆（优先队列）
---
### 0506_相对名次
___
#### 数组
___
#### 排序
___
#### 堆（优先队列）
---
### 0507_完美数
___
#### 数学
---
### 0508_出现次数最多的子树元素和
___
#### 树
___
#### 深度优先搜索
___
#### 哈希表
___
#### 二叉树
---
### 0509_斐波那契数
___
#### 递归
___
#### 记忆化搜索
___
#### 数学
___
#### 动态规划
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二叉搜索树 | 二叉树 | 动态规划 |
| 单调栈 | 哈希表 | 图 |
| 堆（优先队列） | 字符串 | 广度优先搜索 |
| 排序 | 数学 | 数组 |
| 最短路 | 栈 | 树 |
| 深度优先搜索 | 矩阵 | 记忆化搜索 |
| 贪心 | 递归 |  |

# [500. 键盘行](https://leetcode.cn/problems/keyboard-row){#500}

{{< tabs "500" >}}

{{% tab "python" %}}
```python
class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        ans = []
        s = "12210111011122000010020202"
        for w in words:
            x = s[ord(w[0].lower()) - ord('a')]
            if all(s[ord(c.lower()) - ord('a')] == x for c in w):
                ans.append(w)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String[] findWords(String[] words) {
        String s = "12210111011122000010020202";
        List<String> ans = new ArrayList<>();
        for (var w : words) {
            String t = w.toLowerCase();
            char x = s.charAt(t.charAt(0) - 'a');
            boolean ok = true;
            for (char c : t.toCharArray()) {
                if (s.charAt(c - 'a') != x) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans.add(w);
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
    vector<string> findWords(vector<string>& words) {
        string s = "12210111011122000010020202";
        vector<string> ans;
        for (auto& w : words) {
            char x = s[tolower(w[0]) - 'a'];
            bool ok = true;
            for (char& c : w) {
                if (s[tolower(c) - 'a'] != x) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans.emplace_back(w);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findWords(words []string) (ans []string) {
	s := "12210111011122000010020202"
	for _, w := range words {
		x := s[unicode.ToLower(rune(w[0]))-'a']
		ok := true
		for _, c := range w[1:] {
			if s[unicode.ToLower(c)-'a'] != x {
				ok = false
				break
			}
		}
		if ok {
			ans = append(ans, w)
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findWords(words: string[]): string[] {
    const s = '12210111011122000010020202';
    const ans: string[] = [];
    for (const w of words) {
        const t = w.toLowerCase();
        const x = s[t.charCodeAt(0) - 'a'.charCodeAt(0)];
        let ok = true;
        for (const c of t) {
            if (s[c.charCodeAt(0) - 'a'.charCodeAt(0)] !== x) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans.push(w);
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public string[] FindWords(string[] words) {
        string s = "12210111011122000010020202";
        IList<string> ans = new List<string>();
        foreach (string w in words) {
            char x = s[char.ToLower(w[0]) - 'a'];
            bool ok = true;
            for (int i = 1; i < w.Length; ++i) {
                if (s[char.ToLower(w[i]) - 'a'] != x) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans.Add(w);
            }
        }
        return ans.ToArray();
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串数组 <code>words</code> ，只返回可以使用在 <strong>美式键盘</strong> 同一行的字母打印出来的单词。键盘如下图所示。</p>

<p><strong>请注意</strong>，字符串&nbsp;<strong>不区分大小写</strong>，相同字母的大小写形式都被视为在同一行<strong>。</strong></p>

<p><strong>美式键盘</strong> 中：</p>

<ul>
	<li>第一行由字符 <code>"qwertyuiop"</code> 组成。</li>
	<li>第二行由字符 <code>"asdfghjkl"</code> 组成。</li>
	<li>第三行由字符 <code>"zxcvbnm"</code> 组成。</li>
</ul>

<p><img alt="American keyboard" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0500.Keyboard%20Row/images/keyboard.png" style="width: 100%; max-width: 600px" /></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">words = ["Hello","Alaska","Dad","Peace"]</span></p>

<p><b>输出：</b><span class="example-io">["Alaska","Dad"]</span></p>

<p><strong>解释：</strong></p>

<p>由于不区分大小写，<code>"a"</code> 和&nbsp;<code>"A"</code> 都在美式键盘的第二行。</p>
</div>

<p><strong>示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>words = ["omk"]</span></p>

<p><span class="example-io"><b>输出：</b>[]</span></p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b></span><span class="example-io">words = ["adsdf","sfd"]</span></p>

<p><span class="example-io"><b>输出：</b></span><span class="example-io">["adsdf","sfd"]</span></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 20</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 100</code></li>
	<li><code>words[i]</code> 由英文字母（小写和大写字母）组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：字符映射

我们将每个键盘行的字符映射到对应的行数，然后遍历字符串数组，判断每个字符串是否都在同一行即可。

时间复杂度 $O(L)$，空间复杂度 $O(C)$。其中 $L$ 为所有字符串的长度之和；而 $C$ 为字符集的大小，本题中 $C = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        s1 = set('qwertyuiop')
        s2 = set('asdfghjkl')
        s3 = set('zxcvbnm')
        ans = []
        for w in words:
            s = set(w.lower())
            if s <= s1 or s <= s2 or s <= s3:
                ans.append(w)
        return ans
```

#### Java

```java
class Solution {
    public String[] findWords(String[] words) {
        String s = "12210111011122000010020202";
        List<String> ans = new ArrayList<>();
        for (var w : words) {
            String t = w.toLowerCase();
            char x = s.charAt(t.charAt(0) - 'a');
            boolean ok = true;
            for (char c : t.toCharArray()) {
                if (s.charAt(c - 'a') != x) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans.add(w);
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
    vector<string> findWords(vector<string>& words) {
        string s = "12210111011122000010020202";
        vector<string> ans;
        for (auto& w : words) {
            char x = s[tolower(w[0]) - 'a'];
            bool ok = true;
            for (char& c : w) {
                if (s[tolower(c) - 'a'] != x) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans.emplace_back(w);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findWords(words []string) (ans []string) {
	s := "12210111011122000010020202"
	for _, w := range words {
		x := s[unicode.ToLower(rune(w[0]))-'a']
		ok := true
		for _, c := range w[1:] {
			if s[unicode.ToLower(c)-'a'] != x {
				ok = false
				break
			}
		}
		if ok {
			ans = append(ans, w)
		}
	}
	return
}
```

#### TypeScript

```ts
function findWords(words: string[]): string[] {
    const s = '12210111011122000010020202';
    const ans: string[] = [];
    for (const w of words) {
        const t = w.toLowerCase();
        const x = s[t.charCodeAt(0) - 'a'.charCodeAt(0)];
        let ok = true;
        for (const c of t) {
            if (s[c.charCodeAt(0) - 'a'.charCodeAt(0)] !== x) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans.push(w);
        }
    }
    return ans;
}
```

#### C#

```cs
public class Solution {
    public string[] FindWords(string[] words) {
        string s = "12210111011122000010020202";
        IList<string> ans = new List<string>();
        foreach (string w in words) {
            char x = s[char.ToLower(w[0]) - 'a'];
            bool ok = true;
            for (int i = 1; i < w.Length; ++i) {
                if (s[char.ToLower(w[i]) - 'a'] != x) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans.Add(w);
            }
        }
        return ans.ToArray();
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
    def findWords(self, words: List[str]) -> List[str]:
        ans = []
        s = "12210111011122000010020202"
        for w in words:
            x = s[ord(w[0].lower()) - ord('a')]
            if all(s[ord(c.lower()) - ord('a')] == x for c in w):
                ans.append(w)
        return ans
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [501. 二叉搜索树中的众数](https://leetcode.cn/problems/find-mode-in-binary-search-tree){#501}

{{< tabs "501" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findMode(self, root: TreeNode) -> List[int]:
        def dfs(root):
            if root is None:
                return
            nonlocal mx, prev, ans, cnt
            dfs(root.left)
            cnt = cnt + 1 if prev == root.val else 1
            if cnt > mx:
                ans = [root.val]
                mx = cnt
            elif cnt == mx:
                ans.append(root.val)
            prev = root.val
            dfs(root.right)

        prev = None
        mx = cnt = 0
        ans = []
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
    private int mx;
    private int cnt;
    private TreeNode prev;
    private List<Integer> res;

    public int[] findMode(TreeNode root) {
        res = new ArrayList<>();
        dfs(root);
        int[] ans = new int[res.size()];
        for (int i = 0; i < res.size(); ++i) {
            ans[i] = res.get(i);
        }
        return ans;
    }

    private void dfs(TreeNode root) {
        if (root == null) {
            return;
        }
        dfs(root.left);
        cnt = prev != null && prev.val == root.val ? cnt + 1 : 1;
        if (cnt > mx) {
            res = new ArrayList<>(Arrays.asList(root.val));
            mx = cnt;
        } else if (cnt == mx) {
            res.add(root.val);
        }
        prev = root;
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
    TreeNode* prev;
    int mx, cnt;
    vector<int> ans;

    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return ans;
    }

    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        cnt = prev != nullptr && prev->val == root->val ? cnt + 1 : 1;
        if (cnt > mx) {
            ans.clear();
            ans.push_back(root->val);
            mx = cnt;
        } else if (cnt == mx)
            ans.push_back(root->val);
        prev = root;
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
func findMode(root *TreeNode) []int {
	mx, cnt := 0, 0
	var prev *TreeNode
	var ans []int
	var dfs func(root *TreeNode)
	dfs = func(root *TreeNode) {
		if root == nil {
			return
		}
		dfs(root.Left)
		if prev != nil && prev.Val == root.Val {
			cnt++
		} else {
			cnt = 1
		}
		if cnt > mx {
			ans = []int{root.Val}
			mx = cnt
		} else if cnt == mx {
			ans = append(ans, root.Val)
		}
		prev = root
		dfs(root.Right)
	}
	dfs(root)
	return ans
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    private int mx;
    private int cnt;
    private TreeNode prev;
    private List<int> res;

    public int[] FindMode(TreeNode root) {
        res = new List<int>();
        Dfs(root);
        int[] ans = new int[res.Count];
        for (int i = 0; i < res.Count; ++i) {
            ans[i] = res[i];
        }
        return ans;
    }

    private void Dfs(TreeNode root) {
        if (root == null) {
            return;
        }
        Dfs(root.left);
        cnt = prev != null && prev.val == root.val ? cnt + 1 : 1;
        if (cnt > mx) {
            res = new List<int>(new int[] { root.val });
            mx = cnt;
        } else if (cnt == mx) {
            res.Add(root.val);
        }
        prev = root;
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

<p>给你一个含重复值的二叉搜索树（BST）的根节点 <code>root</code> ，找出并返回 BST 中的所有 <a href="https://baike.baidu.com/item/%E4%BC%97%E6%95%B0/44796" target="_blank">众数</a>（即，出现频率最高的元素）。</p>

<p>如果树中有不止一个众数，可以按 <strong>任意顺序</strong> 返回。</p>

<p>假定 BST 满足如下定义：</p>

<ul>
	<li>结点左子树中所含节点的值 <strong>小于等于</strong> 当前节点的值</li>
	<li>结点右子树中所含节点的值 <strong>大于等于</strong> 当前节点的值</li>
	<li>左子树和右子树都是二叉搜索树</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0501.Find%20Mode%20in%20Binary%20Search%20Tree/images/mode-tree.jpg" style="width: 142px; height: 222px;" />
<pre>
<strong>输入：</strong>root = [1,null,2,2]
<strong>输出：</strong>[2]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>root = [0]
<strong>输出：</strong>[0]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点的数目在范围 <code>[1, 10<sup>4</sup>]</code> 内</li>
	<li><code>-10<sup>5</sup> &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）</p>

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
    def findMode(self, root: TreeNode) -> List[int]:
        def dfs(root):
            if root is None:
                return
            nonlocal mx, prev, ans, cnt
            dfs(root.left)
            cnt = cnt + 1 if prev == root.val else 1
            if cnt > mx:
                ans = [root.val]
                mx = cnt
            elif cnt == mx:
                ans.append(root.val)
            prev = root.val
            dfs(root.right)

        prev = None
        mx = cnt = 0
        ans = []
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
    private int mx;
    private int cnt;
    private TreeNode prev;
    private List<Integer> res;

    public int[] findMode(TreeNode root) {
        res = new ArrayList<>();
        dfs(root);
        int[] ans = new int[res.size()];
        for (int i = 0; i < res.size(); ++i) {
            ans[i] = res.get(i);
        }
        return ans;
    }

    private void dfs(TreeNode root) {
        if (root == null) {
            return;
        }
        dfs(root.left);
        cnt = prev != null && prev.val == root.val ? cnt + 1 : 1;
        if (cnt > mx) {
            res = new ArrayList<>(Arrays.asList(root.val));
            mx = cnt;
        } else if (cnt == mx) {
            res.add(root.val);
        }
        prev = root;
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
    TreeNode* prev;
    int mx, cnt;
    vector<int> ans;

    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return ans;
    }

    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        cnt = prev != nullptr && prev->val == root->val ? cnt + 1 : 1;
        if (cnt > mx) {
            ans.clear();
            ans.push_back(root->val);
            mx = cnt;
        } else if (cnt == mx)
            ans.push_back(root->val);
        prev = root;
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
func findMode(root *TreeNode) []int {
	mx, cnt := 0, 0
	var prev *TreeNode
	var ans []int
	var dfs func(root *TreeNode)
	dfs = func(root *TreeNode) {
		if root == nil {
			return
		}
		dfs(root.Left)
		if prev != nil && prev.Val == root.Val {
			cnt++
		} else {
			cnt = 1
		}
		if cnt > mx {
			ans = []int{root.Val}
			mx = cnt
		} else if cnt == mx {
			ans = append(ans, root.Val)
		}
		prev = root
		dfs(root.Right)
	}
	dfs(root)
	return ans
}
```

#### C#

```cs
public class Solution {
    private int mx;
    private int cnt;
    private TreeNode prev;
    private List<int> res;

    public int[] FindMode(TreeNode root) {
        res = new List<int>();
        Dfs(root);
        int[] ans = new int[res.Count];
        for (int i = 0; i < res.Count; ++i) {
            ans[i] = res[i];
        }
        return ans;
    }

    private void Dfs(TreeNode root) {
        if (root == null) {
            return;
        }
        Dfs(root.left);
        cnt = prev != null && prev.val == root.val ? cnt + 1 : 1;
        if (cnt > mx) {
            res = new List<int>(new int[] { root.val });
            mx = cnt;
        } else if (cnt == mx) {
            res.Add(root.val);
        }
        prev = root;
        Dfs(root.right);
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [502. IPO](https://leetcode.cn/problems/ipo){#502}

{{< tabs "502" >}}

{{% tab "python" %}}
```python
class Solution:
    def findMaximizedCapital(
        self, k: int, w: int, profits: List[int], capital: List[int]
    ) -> int:
        h1 = [(c, p) for c, p in zip(capital, profits)]
        heapify(h1)
        h2 = []
        while k:
            while h1 and h1[0][0] <= w:
                heappush(h2, -heappop(h1)[1])
            if not h2:
                break
            w -= heappop(h2)
            k -= 1
        return w
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findMaximizedCapital(int k, int w, int[] profits, int[] capital) {
        int n = capital.length;
        PriorityQueue<int[]> q1 = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        for (int i = 0; i < n; ++i) {
            q1.offer(new int[] {capital[i], profits[i]});
        }
        PriorityQueue<Integer> q2 = new PriorityQueue<>((a, b) -> b - a);
        while (k-- > 0) {
            while (!q1.isEmpty() && q1.peek()[0] <= w) {
                q2.offer(q1.poll()[1]);
            }
            if (q2.isEmpty()) {
                break;
            }
            w += q2.poll();
        }
        return w;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
using pii = pair<int, int>;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pii, vector<pii>, greater<pii>> q1;
        int n = profits.size();
        for (int i = 0; i < n; ++i) {
            q1.push({capital[i], profits[i]});
        }
        priority_queue<int> q2;
        while (k--) {
            while (!q1.empty() && q1.top().first <= w) {
                q2.push(q1.top().second);
                q1.pop();
            }
            if (q2.empty()) {
                break;
            }
            w += q2.top();
            q2.pop();
        }
        return w;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findMaximizedCapital(k int, w int, profits []int, capital []int) int {
	q1 := hp2{}
	for i, c := range capital {
		heap.Push(&q1, pair{c, profits[i]})
	}
	q2 := hp{}
	for k > 0 {
		for len(q1) > 0 && q1[0].c <= w {
			heap.Push(&q2, heap.Pop(&q1).(pair).p)
		}
		if q2.Len() == 0 {
			break
		}
		w += heap.Pop(&q2).(int)
		k--
	}
	return w
}

type hp struct{ sort.IntSlice }

func (h hp) Less(i, j int) bool { return h.IntSlice[i] > h.IntSlice[j] }
func (h *hp) Push(v any)        { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() any {
	a := h.IntSlice
	v := a[len(a)-1]
	h.IntSlice = a[:len(a)-1]
	return v
}

type pair struct{ c, p int }
type hp2 []pair

func (h hp2) Len() int           { return len(h) }
func (h hp2) Less(i, j int) bool { return h[i].c < h[j].c }
func (h hp2) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp2) Push(v any)        { *h = append(*h, v.(pair)) }
func (h *hp2) Pop() any          { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>假设 力扣（LeetCode）即将开始 <strong>IPO</strong> 。为了以更高的价格将股票卖给风险投资公司，力扣 希望在 IPO 之前开展一些项目以增加其资本。 由于资源有限，它只能在 IPO 之前完成最多 <code>k</code> 个不同的项目。帮助 力扣 设计完成最多 <code>k</code> 个不同项目后得到最大总资本的方式。</p>

<p>给你 <code>n</code> 个项目。对于每个项目 <code>i</code><strong> </strong>，它都有一个纯利润 <code>profits[i]</code> ，和启动该项目需要的最小资本 <code>capital[i]</code> 。</p>

<p>最初，你的资本为 <code>w</code> 。当你完成一个项目时，你将获得纯利润，且利润将被添加到你的总资本中。</p>

<p>总而言之，从给定项目中选择 <strong>最多</strong> <code>k</code> 个不同项目的列表，以 <strong>最大化最终资本</strong> ，并输出最终可获得的最多资本。</p>

<p>答案保证在 32 位有符号整数范围内。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>k = 2, w = 0, profits = [1,2,3], capital = [0,1,1]
<strong>输出：</strong>4
<strong>解释：
</strong>由于你的初始资本为 0，你仅可以从 0 号项目开始。
在完成后，你将获得 1 的利润，你的总资本将变为 1。
此时你可以选择开始 1 号或 2 号项目。
由于你最多可以选择两个项目，所以你需要完成 2 号项目以获得最大的资本。
因此，输出最后最大化的资本，为 0 + 1 + 3 = 4。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>k = 3, w = 0, profits = [1,2,3], capital = [0,1,2]
<strong>输出：</strong>6
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= w &lt;= 10<sup>9</sup></code></li>
	<li><code>n == profits.length</code></li>
	<li><code>n == capital.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= profits[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= capital[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 优先队列（双堆）

将每个项目放入优先队列 $q_1$ 中，按照启动资本从小到大排序。如果堆顶元素启动资本不超过当前已有的资金，则循环弹出，放入另一个优先队列 $q_2$ 中，按照纯利润从大到小排序。取出当前利润最大的项目，将其纯利润加入到当前资金中，重复上述操作 $k$ 次。

时间复杂度 $O(n\log n)$，空间复杂度 $O(n)$。其中 $n$ 为项目数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findMaximizedCapital(
        self, k: int, w: int, profits: List[int], capital: List[int]
    ) -> int:
        h1 = [(c, p) for c, p in zip(capital, profits)]
        heapify(h1)
        h2 = []
        while k:
            while h1 and h1[0][0] <= w:
                heappush(h2, -heappop(h1)[1])
            if not h2:
                break
            w -= heappop(h2)
            k -= 1
        return w
```

#### Java

```java
class Solution {
    public int findMaximizedCapital(int k, int w, int[] profits, int[] capital) {
        int n = capital.length;
        PriorityQueue<int[]> q1 = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        for (int i = 0; i < n; ++i) {
            q1.offer(new int[] {capital[i], profits[i]});
        }
        PriorityQueue<Integer> q2 = new PriorityQueue<>((a, b) -> b - a);
        while (k-- > 0) {
            while (!q1.isEmpty() && q1.peek()[0] <= w) {
                q2.offer(q1.poll()[1]);
            }
            if (q2.isEmpty()) {
                break;
            }
            w += q2.poll();
        }
        return w;
    }
}
```

#### C++

```cpp
using pii = pair<int, int>;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pii, vector<pii>, greater<pii>> q1;
        int n = profits.size();
        for (int i = 0; i < n; ++i) {
            q1.push({capital[i], profits[i]});
        }
        priority_queue<int> q2;
        while (k--) {
            while (!q1.empty() && q1.top().first <= w) {
                q2.push(q1.top().second);
                q1.pop();
            }
            if (q2.empty()) {
                break;
            }
            w += q2.top();
            q2.pop();
        }
        return w;
    }
};
```

#### Go

```go
func findMaximizedCapital(k int, w int, profits []int, capital []int) int {
	q1 := hp2{}
	for i, c := range capital {
		heap.Push(&q1, pair{c, profits[i]})
	}
	q2 := hp{}
	for k > 0 {
		for len(q1) > 0 && q1[0].c <= w {
			heap.Push(&q2, heap.Pop(&q1).(pair).p)
		}
		if q2.Len() == 0 {
			break
		}
		w += heap.Pop(&q2).(int)
		k--
	}
	return w
}

type hp struct{ sort.IntSlice }

func (h hp) Less(i, j int) bool { return h.IntSlice[i] > h.IntSlice[j] }
func (h *hp) Push(v any)        { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() any {
	a := h.IntSlice
	v := a[len(a)-1]
	h.IntSlice = a[:len(a)-1]
	return v
}

type pair struct{ c, p int }
type hp2 []pair

func (h hp2) Len() int           { return len(h) }
func (h hp2) Less(i, j int) bool { return h[i].c < h[j].c }
func (h hp2) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp2) Push(v any)        { *h = append(*h, v.(pair)) }
func (h *hp2) Pop() any          { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [503. 下一个更大元素 II](https://leetcode.cn/problems/next-greater-element-ii){#503}

{{< tabs "503" >}}

{{% tab "python" %}}
```python
class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [-1] * n
        stk = []
        for i in range(n * 2 - 1, -1, -1):
            i %= n
            while stk and stk[-1] <= nums[i]:
                stk.pop()
            if stk:
                ans[i] = stk[-1]
            stk.append(nums[i])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        Arrays.fill(ans, -1);
        Deque<Integer> stk = new ArrayDeque<>();
        for (int i = n * 2 - 1; i >= 0; --i) {
            int j = i % n;
            while (!stk.isEmpty() && stk.peek() <= nums[j]) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                ans[j] = stk.peek();
            }
            stk.push(nums[j]);
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
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> stk;
        for (int i = n * 2 - 1; ~i; --i) {
            int j = i % n;
            while (stk.size() && stk.top() <= nums[j]) {
                stk.pop();
            }
            if (stk.size()) {
                ans[j] = stk.top();
            }
            stk.push(nums[j]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func nextGreaterElements(nums []int) []int {
	n := len(nums)
	ans := make([]int, n)
	for i := range ans {
		ans[i] = -1
	}
	stk := []int{}
	for i := n*2 - 1; i >= 0; i-- {
		j := i % n
		for len(stk) > 0 && stk[len(stk)-1] <= nums[j] {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			ans[j] = stk[len(stk)-1]
		}
		stk = append(stk, nums[j])
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function nextGreaterElements(nums: number[]): number[] {
    const n = nums.length;
    const stk: number[] = [];
    const ans: number[] = Array(n).fill(-1);
    for (let i = n * 2 - 1; ~i; --i) {
        const j = i % n;
        while (stk.length && stk.at(-1)! <= nums[j]) {
            stk.pop();
        }
        if (stk.length) {
            ans[j] = stk.at(-1)!;
        }
        stk.push(nums[j]);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var nextGreaterElements = function (nums) {
    const n = nums.length;
    const stk = [];
    const ans = Array(n).fill(-1);
    for (let i = n * 2 - 1; ~i; --i) {
        const j = i % n;
        while (stk.length && stk.at(-1) <= nums[j]) {
            stk.pop();
        }
        if (stk.length) {
            ans[j] = stk.at(-1);
        }
        stk.push(nums[j]);
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

<p>给定一个循环数组&nbsp;<code>nums</code>&nbsp;（&nbsp;<code>nums[nums.length - 1]</code>&nbsp;的下一个元素是&nbsp;<code>nums[0]</code>&nbsp;），返回&nbsp;<em><code>nums</code>&nbsp;中每个元素的 <strong>下一个更大元素</strong></em> 。</p>

<p>数字 <code>x</code>&nbsp;的 <strong>下一个更大的元素</strong> 是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 <code>-1</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> nums = [1,2,1]
<strong>输出:</strong> [2,-1,2]
<strong>解释:</strong> 第一个 1 的下一个更大的数是 2；
数字 2 找不到下一个更大的数； 
第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> nums = [1,2,3,4,3]
<strong>输出:</strong> [2,3,4,-1,4]
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>9</sup>&nbsp;&lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：单调栈

题目需要我们找到每个元素的下一个更大元素，那么我们可以从后往前遍历数组，这样可以将问题为求上一个更大元素。另外，由于数组是循环的，我们可以将数组遍历两次。

具体地，我们从下标 $n \times 2 - 1$ 开始向前遍历数组，其中 $n$ 是数组的长度。然后，我们记 $j = i \bmod n$，其中 $\bmod$ 表示取模运算。如果栈不为空且栈顶元素小于等于 $nums[j]$，那么我们就不断地弹出栈顶元素，直到栈为空或者栈顶元素大于 $nums[j]$。此时，栈顶元素就是 $nums[j]$ 的上一个更大元素，我们将其赋给 $ans[j]$。最后，我们将 $nums[j]$ 入栈。继续遍历下一个元素。

遍历结束后，我们就可以得到数组 $ans$，它是数组 $nums$ 中每个元素的下一个更大元素。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [-1] * n
        stk = []
        for i in range(n * 2 - 1, -1, -1):
            i %= n
            while stk and stk[-1] <= nums[i]:
                stk.pop()
            if stk:
                ans[i] = stk[-1]
            stk.append(nums[i])
        return ans
```

#### Java

```java
class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        Arrays.fill(ans, -1);
        Deque<Integer> stk = new ArrayDeque<>();
        for (int i = n * 2 - 1; i >= 0; --i) {
            int j = i % n;
            while (!stk.isEmpty() && stk.peek() <= nums[j]) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                ans[j] = stk.peek();
            }
            stk.push(nums[j]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> stk;
        for (int i = n * 2 - 1; ~i; --i) {
            int j = i % n;
            while (stk.size() && stk.top() <= nums[j]) {
                stk.pop();
            }
            if (stk.size()) {
                ans[j] = stk.top();
            }
            stk.push(nums[j]);
        }
        return ans;
    }
};
```

#### Go

```go
func nextGreaterElements(nums []int) []int {
	n := len(nums)
	ans := make([]int, n)
	for i := range ans {
		ans[i] = -1
	}
	stk := []int{}
	for i := n*2 - 1; i >= 0; i-- {
		j := i % n
		for len(stk) > 0 && stk[len(stk)-1] <= nums[j] {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			ans[j] = stk[len(stk)-1]
		}
		stk = append(stk, nums[j])
	}
	return ans
}
```

#### TypeScript

```ts
function nextGreaterElements(nums: number[]): number[] {
    const n = nums.length;
    const stk: number[] = [];
    const ans: number[] = Array(n).fill(-1);
    for (let i = n * 2 - 1; ~i; --i) {
        const j = i % n;
        while (stk.length && stk.at(-1)! <= nums[j]) {
            stk.pop();
        }
        if (stk.length) {
            ans[j] = stk.at(-1)!;
        }
        stk.push(nums[j]);
    }
    return ans;
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var nextGreaterElements = function (nums) {
    const n = nums.length;
    const stk = [];
    const ans = Array(n).fill(-1);
    for (let i = n * 2 - 1; ~i; --i) {
        const j = i % n;
        while (stk.length && stk.at(-1) <= nums[j]) {
            stk.pop();
        }
        if (stk.length) {
            ans[j] = stk.at(-1);
        }
        stk.push(nums[j]);
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [504. 七进制数](https://leetcode.cn/problems/base-7){#504}

{{< tabs "504" >}}

{{% tab "python" %}}
```python
class Solution:
    def convertToBase7(self, num: int) -> str:
        if num == 0:
            return '0'
        if num < 0:
            return '-' + self.convertToBase7(-num)
        ans = []
        while num:
            ans.append(str(num % 7))
            num //= 7
        return ''.join(ans[::-1])
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String convertToBase7(int num) {
        if (num == 0) {
            return "0";
        }
        if (num < 0) {
            return "-" + convertToBase7(-num);
        }
        StringBuilder sb = new StringBuilder();
        while (num != 0) {
            sb.append(num % 7);
            num /= 7;
        }
        return sb.reverse().toString();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        if (num < 0) return "-" + convertToBase7(-num);
        string ans = "";
        while (num) {
            ans = to_string(num % 7) + ans;
            num /= 7;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func convertToBase7(num int) string {
	if num == 0 {
		return "0"
	}
	if num < 0 {
		return "-" + convertToBase7(-num)
	}
	ans := []byte{}
	for num != 0 {
		ans = append([]byte{'0' + byte(num%7)}, ans...)
		num /= 7
	}
	return string(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function convertToBase7(num: number): string {
    if (num == 0) {
        return '0';
    }
    let res = '';
    const isMinus = num < 0;
    if (isMinus) {
        num = -num;
    }
    while (num != 0) {
        const r = num % 7;
        res = r + res;
        num = (num - r) / 7;
    }
    return isMinus ? '-' + res : res;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn convert_to_base7(mut num: i32) -> String {
        if num == 0 {
            return String::from("0");
        }
        let mut res = String::new();
        let is_minus = num < 0;
        if is_minus {
            num = -num;
        }
        while num != 0 {
            res.push_str((num % 7).to_string().as_str());
            num /= 7;
        }
        if is_minus {
            res.push('-');
        }
        res.chars().rev().collect()
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个整数 <code>num</code>，将其转化为 <strong>7 进制</strong>，并以字符串形式输出。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> num = 100
<strong>输出:</strong> "202"
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> num = -7
<strong>输出:</strong> "-10"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>-10<sup>7</sup>&nbsp;&lt;= num &lt;= 10<sup>7</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们不妨假设 `num` 大于等于 $0$，那么，如果 `num` 等于 $0$，只需要返回 $0$ 即可。否则，我们将 $num$ 模 $7$ 的结果保存起来，最后逆序拼接成字符串即可。

时间复杂度 $O(\log n)$，忽略答案的空间消耗，空间复杂度 $O(1)$。其中 $n$ 是 `num` 的绝对值大小。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def convertToBase7(self, num: int) -> str:
        if num == 0:
            return '0'
        if num < 0:
            return '-' + self.convertToBase7(-num)
        ans = []
        while num:
            ans.append(str(num % 7))
            num //= 7
        return ''.join(ans[::-1])
```

#### Java

```java
class Solution {
    public String convertToBase7(int num) {
        if (num == 0) {
            return "0";
        }
        if (num < 0) {
            return "-" + convertToBase7(-num);
        }
        StringBuilder sb = new StringBuilder();
        while (num != 0) {
            sb.append(num % 7);
            num /= 7;
        }
        return sb.reverse().toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        if (num < 0) return "-" + convertToBase7(-num);
        string ans = "";
        while (num) {
            ans = to_string(num % 7) + ans;
            num /= 7;
        }
        return ans;
    }
};
```

#### Go

```go
func convertToBase7(num int) string {
	if num == 0 {
		return "0"
	}
	if num < 0 {
		return "-" + convertToBase7(-num)
	}
	ans := []byte{}
	for num != 0 {
		ans = append([]byte{'0' + byte(num%7)}, ans...)
		num /= 7
	}
	return string(ans)
}
```

#### TypeScript

```ts
function convertToBase7(num: number): string {
    if (num == 0) {
        return '0';
    }
    let res = '';
    const isMinus = num < 0;
    if (isMinus) {
        num = -num;
    }
    while (num != 0) {
        const r = num % 7;
        res = r + res;
        num = (num - r) / 7;
    }
    return isMinus ? '-' + res : res;
}
```

#### Rust

```rust
impl Solution {
    pub fn convert_to_base7(mut num: i32) -> String {
        if num == 0 {
            return String::from("0");
        }
        let mut res = String::new();
        let is_minus = num < 0;
        if is_minus {
            num = -num;
        }
        while num != 0 {
            res.push_str((num % 7).to_string().as_str());
            num /= 7;
        }
        if is_minus {
            res.push('-');
        }
        res.chars().rev().collect()
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [505. 迷宫 II 🔒](https://leetcode.cn/problems/the-maze-ii){#505}

{{< tabs "505" >}}

{{% tab "python" %}}
```python
class Solution:
    def shortestDistance(
        self, maze: List[List[int]], start: List[int], destination: List[int]
    ) -> int:
        m, n = len(maze), len(maze[0])
        dirs = (-1, 0, 1, 0, -1)
        si, sj = start
        di, dj = destination
        q = deque([(si, sj)])
        dist = [[inf] * n for _ in range(m)]
        dist[si][sj] = 0
        while q:
            i, j = q.popleft()
            for a, b in pairwise(dirs):
                x, y, k = i, j, dist[i][j]
                while 0 <= x + a < m and 0 <= y + b < n and maze[x + a][y + b] == 0:
                    x, y, k = x + a, y + b, k + 1
                if k < dist[x][y]:
                    dist[x][y] = k
                    q.append((x, y))
        return -1 if dist[di][dj] == inf else dist[di][dj]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int shortestDistance(int[][] maze, int[] start, int[] destination) {
        int m = maze.length, n = maze[0].length;
        final int inf = 1 << 30;
        int[][] dist = new int[m][n];
        for (var row : dist) {
            Arrays.fill(row, inf);
        }
        int si = start[0], sj = start[1];
        int di = destination[0], dj = destination[1];
        dist[si][sj] = 0;
        Deque<int[]> q = new ArrayDeque<>();
        q.offer(new int[] {si, sj});
        int[] dirs = {-1, 0, 1, 0, -1};
        while (!q.isEmpty()) {
            var p = q.poll();
            int i = p[0], j = p[1];
            for (int d = 0; d < 4; ++d) {
                int x = i, y = j, k = dist[i][j];
                int a = dirs[d], b = dirs[d + 1];
                while (
                    x + a >= 0 && x + a < m && y + b >= 0 && y + b < n && maze[x + a][y + b] == 0) {
                    x += a;
                    y += b;
                    ++k;
                }
                if (k < dist[x][y]) {
                    dist[x][y] = k;
                    q.offer(new int[] {x, y});
                }
            }
        }
        return dist[di][dj] == inf ? -1 : dist[di][dj];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();
        int dist[m][n];
        memset(dist, 0x3f, sizeof(dist));
        int si = start[0], sj = start[1];
        int di = destination[0], dj = destination[1];
        dist[si][sj] = 0;
        queue<pair<int, int>> q;
        q.emplace(si, sj);
        int dirs[5] = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (int d = 0; d < 4; ++d) {
                int x = i, y = j, k = dist[i][j];
                int a = dirs[d], b = dirs[d + 1];
                while (x + a >= 0 && x + a < m && y + b >= 0 && y + b < n && maze[x + a][y + b] == 0) {
                    x += a;
                    y += b;
                    ++k;
                }
                if (k < dist[x][y]) {
                    dist[x][y] = k;
                    q.emplace(x, y);
                }
            }
        }
        return dist[di][dj] == 0x3f3f3f3f ? -1 : dist[di][dj];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func shortestDistance(maze [][]int, start []int, destination []int) int {
	m, n := len(maze), len(maze[0])
	dist := make([][]int, m)
	const inf = 1 << 30
	for i := range dist {
		dist[i] = make([]int, n)
		for j := range dist[i] {
			dist[i][j] = inf
		}
	}
	dist[start[0]][start[1]] = 0
	q := [][]int{start}
	dirs := [5]int{-1, 0, 1, 0, -1}
	for len(q) > 0 {
		p := q[0]
		q = q[1:]
		i, j := p[0], p[1]
		for d := 0; d < 4; d++ {
			x, y, k := i, j, dist[i][j]
			a, b := dirs[d], dirs[d+1]
			for x+a >= 0 && x+a < m && y+b >= 0 && y+b < n && maze[x+a][y+b] == 0 {
				x, y, k = x+a, y+b, k+1
			}
			if k < dist[x][y] {
				dist[x][y] = k
				q = append(q, []int{x, y})
			}
		}
	}
	di, dj := destination[0], destination[1]
	if dist[di][dj] == inf {
		return -1
	}
	return dist[di][dj]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function shortestDistance(maze: number[][], start: number[], destination: number[]): number {
    const m = maze.length;
    const n = maze[0].length;
    const dist: number[][] = Array.from({ length: m }, () =>
        Array.from({ length: n }, () => Infinity),
    );
    const [si, sj] = start;
    const [di, dj] = destination;
    dist[si][sj] = 0;
    const q: number[][] = [[si, sj]];
    const dirs = [-1, 0, 1, 0, -1];
    while (q.length) {
        const [i, j] = q.shift()!;
        for (let d = 0; d < 4; ++d) {
            let [x, y, k] = [i, j, dist[i][j]];
            const [a, b] = [dirs[d], dirs[d + 1]];
            while (x + a >= 0 && x + a < m && y + b >= 0 && y + b < n && maze[x + a][y + b] === 0) {
                x += a;
                y += b;
                ++k;
            }
            if (k < dist[x][y]) {
                dist[x][y] = k;
                q.push([x, y]);
            }
        }
    }
    return dist[di][dj] === Infinity ? -1 : dist[di][dj];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><strong>迷宫</strong>中有一个球，它有空地 (表示为 <code>0</code>) 和墙 (表示为 <code>1</code>)。球可以<strong>向上</strong>、<strong>向下</strong>、<strong>向左</strong>或<strong>向右</strong>滚过空地，但直到撞上墙之前它都不会停止滚动。当球停止时，它才可以选择下一个滚动方向。</p>

<p>给定 <code>m × n</code> 的<strong>迷宫</strong>(<code>maze</code>)，球的<strong>起始位置&nbsp;</strong>(<code>start = [start<sub>row</sub>, start<sub>col</sub>]</code>) 和<strong>目的地&nbsp;</strong>(<code>destination = [destination<sub>row</sub>, destination<sub>col</sub>]</code>)，返回球在<strong>目的地&nbsp;</strong>(<code>destination</code>) 停止的最短<strong>距离</strong>。如果球不能在<strong>目的地&nbsp;</strong>(<code>destination</code>) 停止，返回 <code>-1</code>。</p>

<p><strong>距离</strong>是指球从起始位置 ( 不包括 ) 到终点 ( 包括 ) 所经过的<strong>空地</strong>数。</p>

<p>你可以假设<strong>迷宫的边界都是墙&nbsp;</strong>( 见例子 )。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0505.The%20Maze%20II/images/maze1-1-grid.jpg" /></p>

<pre>
<strong>输入:</strong> maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [4,4]
<strong>输出:</strong> 12
<strong>解析:</strong> 一条最短路径 : left -&gt; down -&gt; left -&gt; down -&gt; right -&gt; down -&gt; right。
             总距离为 1 + 1 + 3 + 1 + 2 + 2 + 2 = 12。

</pre>

<p><strong>示例&nbsp;2:</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0505.The%20Maze%20II/images/maze1-2-grid.jpg" /></p>

<pre>
<strong>输入:</strong> maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [3,2]
<strong>输出:</strong> -1
<strong>解析:</strong> 球不可能在目的地停下来。注意，你可以经过目的地，但不能在那里停下来。
</pre>

<p><strong>示例&nbsp;3:</strong></p>

<pre>
<strong>输入:</strong> maze = [[0,0,0,0,0],[1,1,0,0,1],[0,0,0,0,0],[0,1,0,0,1],[0,1,0,0,0]], start = [4,3], destination = [0,1]
<strong>输出:</strong> -1
</pre>

<p>&nbsp;</p>

<p><strong>注意:</strong></p>

<ul>
	<li><code>m == maze.length</code></li>
	<li><code>n == maze[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
	<li><code>maze[i][j]</code>&nbsp;是&nbsp;<code>0</code>&nbsp;或&nbsp;<code>1</code>.</li>
	<li><code>start.length == 2</code></li>
	<li><code>destination.length == 2</code></li>
	<li><code>0 &lt;= start<sub>row</sub>, destination<sub>row</sub>&nbsp;&lt; m</code></li>
	<li><code>0 &lt;= start<sub>col</sub>, destination<sub>col</sub>&nbsp;&lt; n</code></li>
	<li>球和目的地都存在于一个空地中，它们最初不会处于相同的位置。</li>
	<li>
	<p data-group="1-1">迷宫<strong>至少包含两个空地</strong>。</p>
	</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS

我们定义一个二维数组 $dist$，其中 $dist[i][j]$ 表示从起始位置到达 $(i,j)$ 的最短路径长度。初始时，$dist$ 中的所有元素都被初始化为一个很大的数，除了起始位置，因为起始位置到自身的距离是 $0$。

然后，我们定义一个队列 $q$，将起始位置加入队列。随后不断进行以下操作：弹出队列中的首元素，将其四个方向上可以到达的位置加入队列中，并且在 $dist$ 中记录这些位置的距离，直到队列为空。

最后，如果终点位置的距离仍然是一个很大的数，说明从起始位置无法到达终点位置，返回 $-1$，否则返回终点位置的距离。

时间复杂度 $O(m \times n \times \max(m, n))$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是迷宫的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def shortestDistance(
        self, maze: List[List[int]], start: List[int], destination: List[int]
    ) -> int:
        m, n = len(maze), len(maze[0])
        dirs = (-1, 0, 1, 0, -1)
        si, sj = start
        di, dj = destination
        q = deque([(si, sj)])
        dist = [[inf] * n for _ in range(m)]
        dist[si][sj] = 0
        while q:
            i, j = q.popleft()
            for a, b in pairwise(dirs):
                x, y, k = i, j, dist[i][j]
                while 0 <= x + a < m and 0 <= y + b < n and maze[x + a][y + b] == 0:
                    x, y, k = x + a, y + b, k + 1
                if k < dist[x][y]:
                    dist[x][y] = k
                    q.append((x, y))
        return -1 if dist[di][dj] == inf else dist[di][dj]
```

#### Java

```java
class Solution {
    public int shortestDistance(int[][] maze, int[] start, int[] destination) {
        int m = maze.length, n = maze[0].length;
        final int inf = 1 << 30;
        int[][] dist = new int[m][n];
        for (var row : dist) {
            Arrays.fill(row, inf);
        }
        int si = start[0], sj = start[1];
        int di = destination[0], dj = destination[1];
        dist[si][sj] = 0;
        Deque<int[]> q = new ArrayDeque<>();
        q.offer(new int[] {si, sj});
        int[] dirs = {-1, 0, 1, 0, -1};
        while (!q.isEmpty()) {
            var p = q.poll();
            int i = p[0], j = p[1];
            for (int d = 0; d < 4; ++d) {
                int x = i, y = j, k = dist[i][j];
                int a = dirs[d], b = dirs[d + 1];
                while (
                    x + a >= 0 && x + a < m && y + b >= 0 && y + b < n && maze[x + a][y + b] == 0) {
                    x += a;
                    y += b;
                    ++k;
                }
                if (k < dist[x][y]) {
                    dist[x][y] = k;
                    q.offer(new int[] {x, y});
                }
            }
        }
        return dist[di][dj] == inf ? -1 : dist[di][dj];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();
        int dist[m][n];
        memset(dist, 0x3f, sizeof(dist));
        int si = start[0], sj = start[1];
        int di = destination[0], dj = destination[1];
        dist[si][sj] = 0;
        queue<pair<int, int>> q;
        q.emplace(si, sj);
        int dirs[5] = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (int d = 0; d < 4; ++d) {
                int x = i, y = j, k = dist[i][j];
                int a = dirs[d], b = dirs[d + 1];
                while (x + a >= 0 && x + a < m && y + b >= 0 && y + b < n && maze[x + a][y + b] == 0) {
                    x += a;
                    y += b;
                    ++k;
                }
                if (k < dist[x][y]) {
                    dist[x][y] = k;
                    q.emplace(x, y);
                }
            }
        }
        return dist[di][dj] == 0x3f3f3f3f ? -1 : dist[di][dj];
    }
};
```

#### Go

```go
func shortestDistance(maze [][]int, start []int, destination []int) int {
	m, n := len(maze), len(maze[0])
	dist := make([][]int, m)
	const inf = 1 << 30
	for i := range dist {
		dist[i] = make([]int, n)
		for j := range dist[i] {
			dist[i][j] = inf
		}
	}
	dist[start[0]][start[1]] = 0
	q := [][]int{start}
	dirs := [5]int{-1, 0, 1, 0, -1}
	for len(q) > 0 {
		p := q[0]
		q = q[1:]
		i, j := p[0], p[1]
		for d := 0; d < 4; d++ {
			x, y, k := i, j, dist[i][j]
			a, b := dirs[d], dirs[d+1]
			for x+a >= 0 && x+a < m && y+b >= 0 && y+b < n && maze[x+a][y+b] == 0 {
				x, y, k = x+a, y+b, k+1
			}
			if k < dist[x][y] {
				dist[x][y] = k
				q = append(q, []int{x, y})
			}
		}
	}
	di, dj := destination[0], destination[1]
	if dist[di][dj] == inf {
		return -1
	}
	return dist[di][dj]
}
```

#### TypeScript

```ts
function shortestDistance(maze: number[][], start: number[], destination: number[]): number {
    const m = maze.length;
    const n = maze[0].length;
    const dist: number[][] = Array.from({ length: m }, () =>
        Array.from({ length: n }, () => Infinity),
    );
    const [si, sj] = start;
    const [di, dj] = destination;
    dist[si][sj] = 0;
    const q: number[][] = [[si, sj]];
    const dirs = [-1, 0, 1, 0, -1];
    while (q.length) {
        const [i, j] = q.shift()!;
        for (let d = 0; d < 4; ++d) {
            let [x, y, k] = [i, j, dist[i][j]];
            const [a, b] = [dirs[d], dirs[d + 1]];
            while (x + a >= 0 && x + a < m && y + b >= 0 && y + b < n && maze[x + a][y + b] === 0) {
                x += a;
                y += b;
                ++k;
            }
            if (k < dist[x][y]) {
                dist[x][y] = k;
                q.push([x, y]);
            }
        }
    }
    return dist[di][dj] === Infinity ? -1 : dist[di][dj];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [506. 相对名次](https://leetcode.cn/problems/relative-ranks){#506}

{{< tabs "506" >}}

{{% tab "python" %}}
```python
class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        n = len(score)
        idx = list(range(n))
        idx.sort(key=lambda x: -score[x])
        top3 = ["Gold Medal", "Silver Medal", "Bronze Medal"]
        ans = [None] * n
        for i, j in enumerate(idx):
            ans[j] = top3[i] if i < 3 else str(i + 1)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String[] findRelativeRanks(int[] score) {
        int n = score.length;
        Integer[] idx = new Integer[n];
        Arrays.setAll(idx, i -> i);
        Arrays.sort(idx, (i1, i2) -> score[i2] - score[i1]);
        String[] ans = new String[n];
        String[] top3 = new String[] {"Gold Medal", "Silver Medal", "Bronze Medal"};
        for (int i = 0; i < n; ++i) {
            ans[idx[i]] = i < 3 ? top3[i] : String.valueOf(i + 1);
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
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&score](int a, int b) {
            return score[a] > score[b];
        });
        vector<string> ans(n);
        vector<string> top3 = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        for (int i = 0; i < n; ++i) {
            ans[idx[i]] = i < 3 ? top3[i] : to_string(i + 1);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findRelativeRanks(score []int) []string {
	n := len(score)
	idx := make([][]int, n)
	for i := 0; i < n; i++ {
		idx[i] = []int{score[i], i}
	}
	sort.Slice(idx, func(i1, i2 int) bool {
		return idx[i1][0] > idx[i2][0]
	})
	ans := make([]string, n)
	top3 := []string{"Gold Medal", "Silver Medal", "Bronze Medal"}
	for i := 0; i < n; i++ {
		if i < 3 {
			ans[idx[i][1]] = top3[i]
		} else {
			ans[idx[i][1]] = strconv.Itoa(i + 1)
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findRelativeRanks(score: number[]): string[] {
    const n = score.length;
    const idx = Array.from({ length: n }, (_, i) => i);
    idx.sort((a, b) => score[b] - score[a]);
    const top3 = ['Gold Medal', 'Silver Medal', 'Bronze Medal'];
    const ans: string[] = Array(n);
    for (let i = 0; i < n; i++) {
        if (i < 3) {
            ans[idx[i]] = top3[i];
        } else {
            ans[idx[i]] = (i + 1).toString();
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

<p>给你一个长度为 <code>n</code> 的整数数组 <code>score</code> ，其中 <code>score[i]</code> 是第 <code>i</code> 位运动员在比赛中的得分。所有得分都 <strong>互不相同</strong> 。</p>

<p>运动员将根据得分 <strong>决定名次</strong> ，其中名次第 <code>1</code> 的运动员得分最高，名次第 <code>2</code> 的运动员得分第 <code>2</code> 高，依此类推。运动员的名次决定了他们的获奖情况：</p>

<ul>
	<li>名次第 <code>1</code> 的运动员获金牌 <code>"Gold Medal"</code> 。</li>
	<li>名次第 <code>2</code> 的运动员获银牌 <code>"Silver Medal"</code> 。</li>
	<li>名次第 <code>3</code> 的运动员获铜牌 <code>"Bronze Medal"</code> 。</li>
	<li>从名次第 <code>4</code> 到第 <code>n</code> 的运动员，只能获得他们的名次编号（即，名次第 <code>x</code> 的运动员获得编号 <code>"x"</code>）。</li>
</ul>

<p>使用长度为 <code>n</code> 的数组 <code>answer</code> 返回获奖，其中 <code>answer[i]</code> 是第 <code>i</code> 位运动员的获奖情况。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>score = [5,4,3,2,1]
<strong>输出：</strong>["Gold Medal","Silver Medal","Bronze Medal","4","5"]
<strong>解释：</strong>名次为 [1<sup>st</sup>, 2<sup>nd</sup>, 3<sup>rd</sup>, 4<sup>th</sup>, 5<sup>th</sup>] 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>score = [10,3,8,9,4]
<strong>输出：</strong>["Gold Medal","5","Bronze Medal","Silver Medal","4"]
<strong>解释：</strong>名次为 [1<sup>st</sup>, 5<sup>th</sup>, 3<sup>rd</sup>, 2<sup>nd</sup>, 4<sup>th</sup>] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == score.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= score[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>score</code> 中的所有值 <strong>互不相同</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序

我们使用一个数组 $\textit{idx}$ 存储 $0$ 到 $n-1$ 的下标，然后对 $\textit{idx}$ 进行排序，排序规则为：按照 $\textit{score}$ 的值从大到小排序。

然后我们定义一个数组 $\textit{top3} = [\text{Gold Medal}, \text{Silver Medal}, \text{Bronze Medal}]$，遍历 $\textit{idx}$，对于每个下标 $j$，如果 $j$ 小于 $3$，则 $\textit{ans}[j]$ 为 $\textit{top3}[j]$，否则为 $j+1$。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{score}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        n = len(score)
        idx = list(range(n))
        idx.sort(key=lambda x: -score[x])
        top3 = ["Gold Medal", "Silver Medal", "Bronze Medal"]
        ans = [None] * n
        for i, j in enumerate(idx):
            ans[j] = top3[i] if i < 3 else str(i + 1)
        return ans
```

#### Java

```java
class Solution {
    public String[] findRelativeRanks(int[] score) {
        int n = score.length;
        Integer[] idx = new Integer[n];
        Arrays.setAll(idx, i -> i);
        Arrays.sort(idx, (i1, i2) -> score[i2] - score[i1]);
        String[] ans = new String[n];
        String[] top3 = new String[] {"Gold Medal", "Silver Medal", "Bronze Medal"};
        for (int i = 0; i < n; ++i) {
            ans[idx[i]] = i < 3 ? top3[i] : String.valueOf(i + 1);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&score](int a, int b) {
            return score[a] > score[b];
        });
        vector<string> ans(n);
        vector<string> top3 = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        for (int i = 0; i < n; ++i) {
            ans[idx[i]] = i < 3 ? top3[i] : to_string(i + 1);
        }
        return ans;
    }
};
```

#### Go

```go
func findRelativeRanks(score []int) []string {
	n := len(score)
	idx := make([][]int, n)
	for i := 0; i < n; i++ {
		idx[i] = []int{score[i], i}
	}
	sort.Slice(idx, func(i1, i2 int) bool {
		return idx[i1][0] > idx[i2][0]
	})
	ans := make([]string, n)
	top3 := []string{"Gold Medal", "Silver Medal", "Bronze Medal"}
	for i := 0; i < n; i++ {
		if i < 3 {
			ans[idx[i][1]] = top3[i]
		} else {
			ans[idx[i][1]] = strconv.Itoa(i + 1)
		}
	}
	return ans
}
```

#### TypeScript

```ts
function findRelativeRanks(score: number[]): string[] {
    const n = score.length;
    const idx = Array.from({ length: n }, (_, i) => i);
    idx.sort((a, b) => score[b] - score[a]);
    const top3 = ['Gold Medal', 'Silver Medal', 'Bronze Medal'];
    const ans: string[] = Array(n);
    for (let i = 0; i < n; i++) {
        if (i < 3) {
            ans[idx[i]] = top3[i];
        } else {
            ans[idx[i]] = (i + 1).toString();
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

# [507. 完美数](https://leetcode.cn/problems/perfect-number){#507}

{{< tabs "507" >}}

{{% tab "python" %}}
```python
class Solution:
    def checkPerfectNumber(self, num: int) -> bool:
        if num == 1:
            return False
        s, i = 1, 2
        while i <= num // i:
            if num % i == 0:
                s += i
                if i != num // i:
                    s += num // i
            i += 1
        return s == num
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean checkPerfectNumber(int num) {
        if (num == 1) {
            return false;
        }
        int s = 1;
        for (int i = 2; i <= num / i; ++i) {
            if (num % i == 0) {
                s += i;
                if (i != num / i) {
                    s += num / i;
                }
            }
        }
        return s == num;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1) {
            return false;
        }
        int s = 1;
        for (int i = 2; i <= num / i; ++i) {
            if (num % i == 0) {
                s += i;
                if (i != num / i) {
                    s += num / i;
                }
            }
        }
        return s == num;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func checkPerfectNumber(num int) bool {
	if num == 1 {
		return false
	}
	s := 1
	for i := 2; i <= num/i; i++ {
		if num%i == 0 {
			s += i
			if j := num / i; i != j {
				s += j
			}
		}
	}
	return s == num
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function checkPerfectNumber(num: number): boolean {
    if (num <= 1) {
        return false;
    }
    let s = 1;
    for (let i = 2; i <= num / i; ++i) {
        if (num % i === 0) {
            s += i;
            if (i * i !== num) {
                s += num / i;
            }
        }
    }
    return s === num;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>对于一个&nbsp;<strong>正整数</strong>，如果它和除了它自身以外的所有 <strong>正因子</strong> 之和相等，我们称它为 <strong>「完美数」</strong>。</p>

<p>给定一个&nbsp;<strong>整数&nbsp;</strong><code>n</code>，&nbsp;如果是完美数，返回 <code>true</code>；否则返回 <code>false</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>num = 28
<strong>输出：</strong>true
<strong>解释：</strong>28 = 1 + 2 + 4 + 7 + 14
1, 2, 4, 7, 和 14 是 28 的所有正因子。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>num = 7
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num &lt;= 10<sup>8</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们首先判断 $\textit{num}$ 是否为 1，如果为 1，则 $\textit{num}$ 不是完美数，返回 $\text{false}$。

然后，我们从 2 开始枚举 $\textit{num}$ 的所有正因子，如果 $\textit{num}$ 能被 $\textit{num}$ 的某个正因子 $i$ 整除，那么我们将 $i$ 加入到答案 $\textit{s}$ 中。如果 $\textit{num}$ 除以 $i$ 得到的商不等于 $i$，我们也将 $\textit{num}$ 除以 $i$ 得到的商加入到答案 $\textit{s}$ 中。

最后，我们判断 $\textit{s}$ 是否等于 $\textit{num}$ 即可。

时间复杂度 $O(\sqrt{n})$，其中 $n$ 为 $\textit{num}$ 的大小。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def checkPerfectNumber(self, num: int) -> bool:
        if num == 1:
            return False
        s, i = 1, 2
        while i <= num // i:
            if num % i == 0:
                s += i
                if i != num // i:
                    s += num // i
            i += 1
        return s == num
```

#### Java

```java
class Solution {
    public boolean checkPerfectNumber(int num) {
        if (num == 1) {
            return false;
        }
        int s = 1;
        for (int i = 2; i <= num / i; ++i) {
            if (num % i == 0) {
                s += i;
                if (i != num / i) {
                    s += num / i;
                }
            }
        }
        return s == num;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1) {
            return false;
        }
        int s = 1;
        for (int i = 2; i <= num / i; ++i) {
            if (num % i == 0) {
                s += i;
                if (i != num / i) {
                    s += num / i;
                }
            }
        }
        return s == num;
    }
};
```

#### Go

```go
func checkPerfectNumber(num int) bool {
	if num == 1 {
		return false
	}
	s := 1
	for i := 2; i <= num/i; i++ {
		if num%i == 0 {
			s += i
			if j := num / i; i != j {
				s += j
			}
		}
	}
	return s == num
}
```

#### TypeScript

```ts
function checkPerfectNumber(num: number): boolean {
    if (num <= 1) {
        return false;
    }
    let s = 1;
    for (let i = 2; i <= num / i; ++i) {
        if (num % i === 0) {
            s += i;
            if (i * i !== num) {
                s += num / i;
            }
        }
    }
    return s === num;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [508. 出现次数最多的子树元素和](https://leetcode.cn/problems/most-frequent-subtree-sum){#508}

{{< tabs "508" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findFrequentTreeSum(self, root: Optional[TreeNode]) -> List[int]:
        def dfs(root: Optional[TreeNode]) -> int:
            if root is None:
                return 0
            l, r = dfs(root.left), dfs(root.right)
            s = l + r + root.val
            cnt[s] += 1
            return s

        cnt = Counter()
        dfs(root)
        mx = max(cnt.values())
        return [k for k, v in cnt.items() if v == mx]
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
    private Map<Integer, Integer> cnt = new HashMap<>();
    private int mx;

    public int[] findFrequentTreeSum(TreeNode root) {
        dfs(root);
        List<Integer> ans = new ArrayList<>();
        for (var e : cnt.entrySet()) {
            if (e.getValue() == mx) {
                ans.add(e.getKey());
            }
        }
        return ans.stream().mapToInt(i -> i).toArray();
    }

    private int dfs(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int s = root.val + dfs(root.left) + dfs(root.right);
        mx = Math.max(mx, cnt.merge(s, 1, Integer::sum));
        return s;
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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> cnt;
        int mx = 0;
        function<int(TreeNode*)> dfs = [&](TreeNode* root) -> int {
            if (!root) {
                return 0;
            }
            int s = root->val + dfs(root->left) + dfs(root->right);
            mx = max(mx, ++cnt[s]);
            return s;
        };
        dfs(root);
        vector<int> ans;
        for (const auto& [k, v] : cnt) {
            if (v == mx) {
                ans.push_back(k);
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
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func findFrequentTreeSum(root *TreeNode) (ans []int) {
	cnt := map[int]int{}
	var mx int
	var dfs func(*TreeNode) int
	dfs = func(root *TreeNode) int {
		if root == nil {
			return 0
		}
		s := root.Val + dfs(root.Left) + dfs(root.Right)
		cnt[s]++
		mx = max(mx, cnt[s])
		return s
	}
	dfs(root)
	for k, v := range cnt {
		if v == mx {
			ans = append(ans, k)
		}
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

function findFrequentTreeSum(root: TreeNode | null): number[] {
    const cnt = new Map<number, number>();
    let mx = 0;
    const dfs = (root: TreeNode | null): number => {
        if (!root) {
            return 0;
        }
        const { val, left, right } = root;
        const s = val + dfs(left) + dfs(right);
        cnt.set(s, (cnt.get(s) ?? 0) + 1);
        mx = Math.max(mx, cnt.get(s)!);
        return s;
    };
    dfs(root);
    return Array.from(cnt.entries())
        .filter(([_, c]) => c === mx)
        .map(([s, _]) => s);
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
use std::collections::HashMap;
use std::rc::Rc;

impl Solution {
    pub fn find_frequent_tree_sum(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        fn dfs(root: Option<Rc<RefCell<TreeNode>>>, cnt: &mut HashMap<i32, i32>) -> i32 {
            if let Some(node) = root {
                let l = dfs(node.borrow().left.clone(), cnt);
                let r = dfs(node.borrow().right.clone(), cnt);
                let s = l + r + node.borrow().val;
                *cnt.entry(s).or_insert(0) += 1;
                s
            } else {
                0
            }
        }

        let mut cnt = HashMap::new();
        dfs(root, &mut cnt);

        let mx = cnt.values().cloned().max().unwrap_or(0);
        cnt.into_iter()
            .filter(|&(_, v)| v == mx)
            .map(|(k, _)| k)
            .collect()
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个二叉树的根结点&nbsp;<code>root</code>&nbsp;，请返回出现次数最多的子树元素和。如果有多个元素出现的次数相同，返回所有出现次数最多的子树元素和（不限顺序）。</p>

<p>一个结点的&nbsp;<strong>「子树元素和」</strong>&nbsp;定义为以该结点为根的二叉树上所有结点的元素之和（包括结点本身）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0508.Most%20Frequent%20Subtree%20Sum/images/freq1-tree.jpg" /></p>

<pre>
<strong>输入:</strong> root = [5,2,-3]
<strong>输出:</strong> [2,-3,4]
</pre>

<p><strong>示例&nbsp;2：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0508.Most%20Frequent%20Subtree%20Sum/images/freq2-tree.jpg" /></p>

<pre>
<strong>输入:</strong> root = [5,2,-5]
<b>输出:</b> [2]
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li>节点数在&nbsp;<code>[1, 10<sup>4</sup>]</code>&nbsp;范围内</li>
	<li><code>-10<sup>5</sup>&nbsp;&lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + DFS

我们可以使用一个哈希表 $\textit{cnt}$ 记录每个子树元素和出现的次数，然后使用深度优先搜索遍历整棵树，统计每个子树的元素和，并更新 $\textit{cnt}$。

最后，我们遍历 $\textit{cnt}$，找到所有出现次数最多的子树元素和。

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
    def findFrequentTreeSum(self, root: Optional[TreeNode]) -> List[int]:
        def dfs(root: Optional[TreeNode]) -> int:
            if root is None:
                return 0
            l, r = dfs(root.left), dfs(root.right)
            s = l + r + root.val
            cnt[s] += 1
            return s

        cnt = Counter()
        dfs(root)
        mx = max(cnt.values())
        return [k for k, v in cnt.items() if v == mx]
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
    private Map<Integer, Integer> cnt = new HashMap<>();
    private int mx;

    public int[] findFrequentTreeSum(TreeNode root) {
        dfs(root);
        List<Integer> ans = new ArrayList<>();
        for (var e : cnt.entrySet()) {
            if (e.getValue() == mx) {
                ans.add(e.getKey());
            }
        }
        return ans.stream().mapToInt(i -> i).toArray();
    }

    private int dfs(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int s = root.val + dfs(root.left) + dfs(root.right);
        mx = Math.max(mx, cnt.merge(s, 1, Integer::sum));
        return s;
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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> cnt;
        int mx = 0;
        function<int(TreeNode*)> dfs = [&](TreeNode* root) -> int {
            if (!root) {
                return 0;
            }
            int s = root->val + dfs(root->left) + dfs(root->right);
            mx = max(mx, ++cnt[s]);
            return s;
        };
        dfs(root);
        vector<int> ans;
        for (const auto& [k, v] : cnt) {
            if (v == mx) {
                ans.push_back(k);
            }
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
func findFrequentTreeSum(root *TreeNode) (ans []int) {
	cnt := map[int]int{}
	var mx int
	var dfs func(*TreeNode) int
	dfs = func(root *TreeNode) int {
		if root == nil {
			return 0
		}
		s := root.Val + dfs(root.Left) + dfs(root.Right)
		cnt[s]++
		mx = max(mx, cnt[s])
		return s
	}
	dfs(root)
	for k, v := range cnt {
		if v == mx {
			ans = append(ans, k)
		}
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

function findFrequentTreeSum(root: TreeNode | null): number[] {
    const cnt = new Map<number, number>();
    let mx = 0;
    const dfs = (root: TreeNode | null): number => {
        if (!root) {
            return 0;
        }
        const { val, left, right } = root;
        const s = val + dfs(left) + dfs(right);
        cnt.set(s, (cnt.get(s) ?? 0) + 1);
        mx = Math.max(mx, cnt.get(s)!);
        return s;
    };
    dfs(root);
    return Array.from(cnt.entries())
        .filter(([_, c]) => c === mx)
        .map(([s, _]) => s);
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
use std::collections::HashMap;
use std::rc::Rc;

impl Solution {
    pub fn find_frequent_tree_sum(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        fn dfs(root: Option<Rc<RefCell<TreeNode>>>, cnt: &mut HashMap<i32, i32>) -> i32 {
            if let Some(node) = root {
                let l = dfs(node.borrow().left.clone(), cnt);
                let r = dfs(node.borrow().right.clone(), cnt);
                let s = l + r + node.borrow().val;
                *cnt.entry(s).or_insert(0) += 1;
                s
            } else {
                0
            }
        }

        let mut cnt = HashMap::new();
        dfs(root, &mut cnt);

        let mx = cnt.values().cloned().max().unwrap_or(0);
        cnt.into_iter()
            .filter(|&(_, v)| v == mx)
            .map(|(k, _)| k)
            .collect()
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [509. 斐波那契数](https://leetcode.cn/problems/fibonacci-number){#509}

{{< tabs "509" >}}

{{% tab "python" %}}
```python
import numpy as np


class Solution:
    def fib(self, n: int) -> int:
        factor = np.asmatrix([(1, 1), (1, 0)], np.dtype("O"))
        res = np.asmatrix([(1, 0)], np.dtype("O"))
        while n:
            if n & 1:
                res = res * factor
            factor = factor * factor
            n >>= 1
        return res[0, 1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int fib(int n) {
        int[][] a = {{1, 1}, {1, 0}};
        return pow(a, n)[0][1];
    }

    private int[][] mul(int[][] a, int[][] b) {
        int m = a.length, n = b[0].length;
        int[][] c = new int[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < b.length; ++k) {
                    c[i][j] = c[i][j] + a[i][k] * b[k][j];
                }
            }
        }
        return c;
    }

    private int[][] pow(int[][] a, int n) {
        int[][] res = {{1, 0}};
        while (n > 0) {
            if ((n & 1) == 1) {
                res = mul(res, a);
            }
            a = mul(a, a);
            n >>= 1;
        }
        return res;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int fib(int n) {
        vector<vector<int>> a = {{1, 1}, {1, 0}};
        return qpow(a, n)[0][1];
    }

    vector<vector<int>> mul(vector<vector<int>>& a, vector<vector<int>>& b) {
        int m = a.size(), n = b[0].size();
        vector<vector<int>> c(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < b.size(); ++k) {
                    c[i][j] = c[i][j] + a[i][k] * b[k][j];
                }
            }
        }
        return c;
    }

    vector<vector<int>> qpow(vector<vector<int>>& a, int n) {
        vector<vector<int>> res = {{1, 0}};
        while (n) {
            if (n & 1) {
                res = mul(res, a);
            }
            a = mul(a, a);
            n >>= 1;
        }
        return res;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func fib(n int) int {
	a := [][]int{{1, 1}, {1, 0}}
	return pow(a, n)[0][1]
}

func mul(a, b [][]int) [][]int {
	m, n := len(a), len(b[0])
	c := make([][]int, m)
	for i := range c {
		c[i] = make([]int, n)
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			for k := 0; k < len(b); k++ {
				c[i][j] = c[i][j] + a[i][k]*b[k][j]
			}
		}
	}
	return c
}

func pow(a [][]int, n int) [][]int {
	res := [][]int{{1, 0}}
	for n > 0 {
		if n&1 == 1 {
			res = mul(res, a)
		}
		a = mul(a, a)
		n >>= 1
	}
	return res
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function fib(n: number): number {
    const a: number[][] = [
        [1, 1],
        [1, 0],
    ];
    return pow(a, n)[0][1];
}

function mul(a: number[][], b: number[][]): number[][] {
    const [m, n] = [a.length, b[0].length];
    const c = Array.from({ length: m }, () => Array.from({ length: n }, () => 0));
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            for (let k = 0; k < b.length; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

function pow(a: number[][], n: number): number[][] {
    let res = [[1, 0]];
    while (n) {
        if (n & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        n >>= 1;
    }
    return res;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn fib(n: i32) -> i32 {
        let a = vec![vec![1, 1], vec![1, 0]];
        pow(a, n as usize)[0][1]
    }
}

fn mul(a: Vec<Vec<i32>>, b: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let m = a.len();
    let n = b[0].len();
    let mut c = vec![vec![0; n]; m];

    for i in 0..m {
        for j in 0..n {
            for k in 0..b.len() {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    c
}

fn pow(mut a: Vec<Vec<i32>>, mut n: usize) -> Vec<Vec<i32>> {
    let mut res = vec![vec![1, 0], vec![0, 1]];

    while n > 0 {
        if n & 1 == 1 {
            res = mul(res, a.clone());
        }
        a = mul(a.clone(), a);
        n >>= 1;
    }
    res
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} n
 * @return {number}
 */
var fib = function (n) {
    const a = [
        [1, 1],
        [1, 0],
    ];
    return pow(a, n)[0][1];
};

function mul(a, b) {
    const m = a.length,
        n = b[0].length;
    const c = Array.from({ length: m }, () => Array(n).fill(0));
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            for (let k = 0; k < b.length; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

function pow(a, n) {
    let res = [
        [1, 0],
        [0, 1],
    ];
    while (n > 0) {
        if (n & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        n >>= 1;
    }
    return res;
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer $n
     * @return Integer
     */
    function fib($n) {
        $a = 0;
        $b = 1;
        for ($i = 0; $i < $n; $i++) {
            $temp = $a;
            $a = $b;
            $b = $temp + $b;
        }
        return $a;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><strong>斐波那契数</strong>&nbsp;（通常用&nbsp;<code>F(n)</code> 表示）形成的序列称为 <strong>斐波那契数列</strong> 。该数列由&nbsp;<code>0</code> 和 <code>1</code> 开始，后面的每一项数字都是前面两项数字的和。也就是：</p>

<pre>
F(0) = 0，F(1)&nbsp;= 1
F(n) = F(n - 1) + F(n - 2)，其中 n &gt; 1
</pre>

<p>给定&nbsp;<code>n</code> ，请计算 <code>F(n)</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 2
<strong>输出：</strong>1
<strong>解释：</strong>F(2) = F(1) + F(0) = 1 + 0 = 1
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 3
<strong>输出：</strong>2
<strong>解释：</strong>F(3) = F(2) + F(1) = 1 + 1 = 2
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 4
<strong>输出：</strong>3
<strong>解释：</strong>F(4) = F(3) + F(2) = 2 + 1 = 3
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= n &lt;= 30</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递推

我们定义两个变量 $a$ 和 $b$，初始时 $a = 0$, $b = 1$。

接下来，我们进行 $n$ 次循环，每次循环中，我们将 $a$ 和 $b$ 的值分别更新为 $b$ 和 $a + b$。

最后，返回 $a$ 即可。

时间复杂度 $O(n)$，其中 $n$ 为题目给定的整数 $n$。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def fib(self, n: int) -> int:
        a, b = 0, 1
        for _ in range(n):
            a, b = b, a + b
        return a
```

#### Java

```java
class Solution {
    public int fib(int n) {
        int a = 0, b = 1;
        while (n-- > 0) {
            int c = a + b;
            a = b;
            b = c;
        }
        return a;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int fib(int n) {
        int a = 0, b = 1;
        while (n--) {
            int c = a + b;
            a = b;
            b = c;
        }
        return a;
    }
};
```

#### Go

```go
func fib(n int) int {
	a, b := 0, 1
	for i := 0; i < n; i++ {
		a, b = b, a+b
	}
	return a
}
```

#### TypeScript

```ts
function fib(n: number): number {
    let [a, b] = [0, 1];
    while (n--) {
        [a, b] = [b, a + b];
    }
    return a;
}
```

#### Rust

```rust
impl Solution {
    pub fn fib(n: i32) -> i32 {
        let mut a = 0;
        let mut b = 1;
        for _ in 0..n {
            let t = b;
            b = a + b;
            a = t;
        }
        a
    }
}
```

#### JavaScript

```js
/**
 * @param {number} n
 * @return {number}
 */
var fib = function (n) {
    let [a, b] = [0, 1];
    while (n--) {
        [a, b] = [b, a + b];
    }
    return a;
};
```

#### PHP

```php
class Solution {
    /**
     * @param Integer $n
     * @return Integer
     */
    function fib($n) {
        $a = 0;
        $b = 1;
        for ($i = 0; $i < $n; $i++) {
            $temp = $a;
            $a = $b;
            $b = $temp + $b;
        }
        return $a;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：矩阵快速幂加速递推

我们设 $\textit{Fib}(n)$ 表示一个 $1 \times 2$ 的矩阵 $\begin{bmatrix} F_n & F_{n - 1} \end{bmatrix}$，其中 $F_n$ 和 $F_{n - 1}$ 分别是第 $n$ 个和第 $n - 1$ 个斐波那契数。

我们希望根据 $\textit{Fib}(n - 1) = \begin{bmatrix} F_{n - 1} & F_{n - 2} \end{bmatrix}$ 推出 $\textit{Fib}(n)$。也即是说，我们需要一个矩阵 $\textit{base}$，使得 $\textit{Fib}(n - 1) \times \textit{base} = \textit{Fib}(n)$，即：

$$
\begin{bmatrix}
F_{n - 1} & F_{n - 2}
\end{bmatrix} \times \textit{base} = \begin{bmatrix} F_n & F_{n - 1} \end{bmatrix}
$$

由于 $F_n = F_{n - 1} + F_{n - 2}$，所以矩阵 $\textit{base}$ 的第一列为：

$$
\begin{bmatrix}
1 \\
1
\end{bmatrix}
$$

第二列为：

$$
\begin{bmatrix}
1 \\
0
\end{bmatrix}
$$

因此有：

$$
\begin{bmatrix} F_{n - 1} & F_{n - 2} \end{bmatrix} \times \begin{bmatrix}1 & 1 \\ 1 & 0\end{bmatrix} = \begin{bmatrix} F_n & F_{n - 1} \end{bmatrix}
$$

我们定义初始矩阵 $res = \begin{bmatrix} 1 & 0 \end{bmatrix}$，那么 $F_n$ 等于 $res$ 乘以 $\textit{base}^{n}$ 的结果矩阵中第一行的第二个元素。使用矩阵快速幂求解即可。

时间复杂度 $O(\log n)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
import numpy as np


class Solution:
    def fib(self, n: int) -> int:
        factor = np.asmatrix([(1, 1), (1, 0)], np.dtype("O"))
        res = np.asmatrix([(1, 0)], np.dtype("O"))
        while n:
            if n & 1:
                res = res * factor
            factor = factor * factor
            n >>= 1
        return res[0, 1]
```

#### Java

```java
class Solution {
    public int fib(int n) {
        int[][] a = {{1, 1}, {1, 0}};
        return pow(a, n)[0][1];
    }

    private int[][] mul(int[][] a, int[][] b) {
        int m = a.length, n = b[0].length;
        int[][] c = new int[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < b.length; ++k) {
                    c[i][j] = c[i][j] + a[i][k] * b[k][j];
                }
            }
        }
        return c;
    }

    private int[][] pow(int[][] a, int n) {
        int[][] res = {{1, 0}};
        while (n > 0) {
            if ((n & 1) == 1) {
                res = mul(res, a);
            }
            a = mul(a, a);
            n >>= 1;
        }
        return res;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int fib(int n) {
        vector<vector<int>> a = {{1, 1}, {1, 0}};
        return qpow(a, n)[0][1];
    }

    vector<vector<int>> mul(vector<vector<int>>& a, vector<vector<int>>& b) {
        int m = a.size(), n = b[0].size();
        vector<vector<int>> c(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < b.size(); ++k) {
                    c[i][j] = c[i][j] + a[i][k] * b[k][j];
                }
            }
        }
        return c;
    }

    vector<vector<int>> qpow(vector<vector<int>>& a, int n) {
        vector<vector<int>> res = {{1, 0}};
        while (n) {
            if (n & 1) {
                res = mul(res, a);
            }
            a = mul(a, a);
            n >>= 1;
        }
        return res;
    }
};
```

#### Go

```go
func fib(n int) int {
	a := [][]int{{1, 1}, {1, 0}}
	return pow(a, n)[0][1]
}

func mul(a, b [][]int) [][]int {
	m, n := len(a), len(b[0])
	c := make([][]int, m)
	for i := range c {
		c[i] = make([]int, n)
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			for k := 0; k < len(b); k++ {
				c[i][j] = c[i][j] + a[i][k]*b[k][j]
			}
		}
	}
	return c
}

func pow(a [][]int, n int) [][]int {
	res := [][]int{{1, 0}}
	for n > 0 {
		if n&1 == 1 {
			res = mul(res, a)
		}
		a = mul(a, a)
		n >>= 1
	}
	return res
}
```

#### TypeScript

```ts
function fib(n: number): number {
    const a: number[][] = [
        [1, 1],
        [1, 0],
    ];
    return pow(a, n)[0][1];
}

function mul(a: number[][], b: number[][]): number[][] {
    const [m, n] = [a.length, b[0].length];
    const c = Array.from({ length: m }, () => Array.from({ length: n }, () => 0));
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            for (let k = 0; k < b.length; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

function pow(a: number[][], n: number): number[][] {
    let res = [[1, 0]];
    while (n) {
        if (n & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        n >>= 1;
    }
    return res;
}
```

#### Rust

```rust
impl Solution {
    pub fn fib(n: i32) -> i32 {
        let a = vec![vec![1, 1], vec![1, 0]];
        pow(a, n as usize)[0][1]
    }
}

fn mul(a: Vec<Vec<i32>>, b: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let m = a.len();
    let n = b[0].len();
    let mut c = vec![vec![0; n]; m];

    for i in 0..m {
        for j in 0..n {
            for k in 0..b.len() {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    c
}

fn pow(mut a: Vec<Vec<i32>>, mut n: usize) -> Vec<Vec<i32>> {
    let mut res = vec![vec![1, 0], vec![0, 1]];

    while n > 0 {
        if n & 1 == 1 {
            res = mul(res, a.clone());
        }
        a = mul(a.clone(), a);
        n >>= 1;
    }
    res
}
```

#### JavaScript

```js
/**
 * @param {number} n
 * @return {number}
 */
var fib = function (n) {
    const a = [
        [1, 1],
        [1, 0],
    ];
    return pow(a, n)[0][1];
};

function mul(a, b) {
    const m = a.length,
        n = b[0].length;
    const c = Array.from({ length: m }, () => Array(n).fill(0));
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            for (let k = 0; k < b.length; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

function pow(a, n) {
    let res = [
        [1, 0],
        [0, 1],
    ];
    while (n > 0) {
        if (n & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        n >>= 1;
    }
    return res;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
