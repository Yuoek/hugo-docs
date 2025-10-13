---
title: "0420_强密码检验器"
date: 2025-10-08T18:36:10+08:00
weight: 3
tags: [二叉搜索树, 二叉树, 位运算, 分治, 双向链表, 哈希表, 回溯, 堆（优先队列）, 字典树, 字符串, 广度优先搜索, 数学, 数组, 栈, 树, 深度优先搜索, 滑动窗口, 矩阵, 贪心, 链表]
---

{{< markmap >}}
### [0420_强密码检验器](#420)
#### [贪心](#420)
#### [字符串](#420)
#### [堆（优先队列）](#420)
### [0421_数组中两个数的最大异或值](#421)
#### [位运算](#421)
#### [字典树](#421)
#### [数组](#421)
#### [哈希表](#421)
### [0422_有效的单词方块 🔒](#422)
#### [数组](#422)
#### [矩阵](#422)
### [0423_从英文中重建数字](#423)
#### [哈希表](#423)
#### [数学](#423)
#### [字符串](#423)
### [0424_替换后的最长重复字符](#424)
#### [哈希表](#424)
#### [字符串](#424)
#### [滑动窗口](#424)
### [0425_单词方块 🔒](#425)
#### [字典树](#425)
#### [数组](#425)
#### [字符串](#425)
#### [回溯](#425)
### [0426_将二叉搜索树转化为排序的双向链表 🔒](#426)
#### [栈](#426)
#### [树](#426)
#### [深度优先搜索](#426)
#### [二叉搜索树](#426)
#### [链表](#426)
#### [二叉树](#426)
#### [双向链表](#426)
### [0427_建立四叉树](#427)
#### [树](#427)
#### [数组](#427)
#### [分治](#427)
#### [矩阵](#427)
### [0428_序列化和反序列化 N 叉树 🔒](#428)
#### [树](#428)
#### [深度优先搜索](#428)
#### [广度优先搜索](#428)
#### [字符串](#428)
### [0429_N 叉树的层序遍历](#429)
#### [树](#429)
#### [广度优先搜索](#429)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0420_强密码检验器
___
#### 贪心
___
#### 字符串
___
#### 堆（优先队列）
---
### 0421_数组中两个数的最大异或值
___
#### 位运算
___
#### 字典树
___
#### 数组
___
#### 哈希表
---
### 0422_有效的单词方块 🔒
___
#### 数组
___
#### 矩阵
---
### 0423_从英文中重建数字
___
#### 哈希表
___
#### 数学
___
#### 字符串
---
### 0424_替换后的最长重复字符
___
#### 哈希表
___
#### 字符串
___
#### 滑动窗口
---
### 0425_单词方块 🔒
___
#### 字典树
___
#### 数组
___
#### 字符串
___
#### 回溯
---
### 0426_将二叉搜索树转化为排序的双向链表 🔒
___
#### 栈
___
#### 树
___
#### 深度优先搜索
___
#### 二叉搜索树
___
#### 链表
___
#### 二叉树
___
#### 双向链表
---
### 0427_建立四叉树
___
#### 树
___
#### 数组
___
#### 分治
___
#### 矩阵
---
### 0428_序列化和反序列化 N 叉树 🔒
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 字符串
---
### 0429_N 叉树的层序遍历
___
#### 树
___
#### 广度优先搜索
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二叉搜索树 | 二叉树 | 位运算 |
| 分治 | 双向链表 | 哈希表 |
| 回溯 | 堆（优先队列） | 字典树 |
| 字符串 | 广度优先搜索 | 数学 |
| 数组 | 栈 | 树 |
| 深度优先搜索 | 滑动窗口 | 矩阵 |
| 贪心 | 链表 |  |

# [420. 强密码检验器](https://leetcode.cn/problems/strong-password-checker){#420}

{{< tabs "420" >}}

{{% tab "python" %}}
```python
class Solution:
    def strongPasswordChecker(self, password: str) -> int:
        def countTypes(s):
            a = b = c = 0
            for ch in s:
                if ch.islower():
                    a = 1
                elif ch.isupper():
                    b = 1
                elif ch.isdigit():
                    c = 1
            return a + b + c

        types = countTypes(password)
        n = len(password)
        if n < 6:
            return max(6 - n, 3 - types)
        if n <= 20:
            replace = cnt = 0
            prev = '~'
            for curr in password:
                if curr == prev:
                    cnt += 1
                else:
                    replace += cnt // 3
                    cnt = 1
                    prev = curr
            replace += cnt // 3
            return max(replace, 3 - types)
        replace = cnt = 0
        remove, remove2 = n - 20, 0
        prev = '~'
        for curr in password:
            if curr == prev:
                cnt += 1
            else:
                if remove > 0 and cnt >= 3:
                    if cnt % 3 == 0:
                        remove -= 1
                        replace -= 1
                    elif cnt % 3 == 1:
                        remove2 += 1
                replace += cnt // 3
                cnt = 1
                prev = curr
        if remove > 0 and cnt >= 3:
            if cnt % 3 == 0:
                remove -= 1
                replace -= 1
            elif cnt % 3 == 1:
                remove2 += 1
        replace += cnt // 3
        use2 = min(replace, remove2, remove // 2)
        replace -= use2
        remove -= use2 * 2

        use3 = min(replace, remove // 3)
        replace -= use3
        remove -= use3 * 3
        return n - 20 + max(replace, 3 - types)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int strongPasswordChecker(String password) {
        int types = countTypes(password);
        int n = password.length();
        if (n < 6) {
            return Math.max(6 - n, 3 - types);
        }
        char[] chars = password.toCharArray();
        if (n <= 20) {
            int replace = 0;
            int cnt = 0;
            char prev = '~';
            for (char curr : chars) {
                if (curr == prev) {
                    ++cnt;
                } else {
                    replace += cnt / 3;
                    cnt = 1;
                    prev = curr;
                }
            }
            replace += cnt / 3;
            return Math.max(replace, 3 - types);
        }
        int replace = 0, remove = n - 20;
        int remove2 = 0;
        int cnt = 0;
        char prev = '~';
        for (char curr : chars) {
            if (curr == prev) {
                ++cnt;
            } else {
                if (remove > 0 && cnt >= 3) {
                    if (cnt % 3 == 0) {
                        --remove;
                        --replace;
                    } else if (cnt % 3 == 1) {
                        ++remove2;
                    }
                }
                replace += cnt / 3;
                cnt = 1;
                prev = curr;
            }
        }
        if (remove > 0 && cnt >= 3) {
            if (cnt % 3 == 0) {
                --remove;
                --replace;
            } else if (cnt % 3 == 1) {
                ++remove2;
            }
        }
        replace += cnt / 3;

        int use2 = Math.min(Math.min(replace, remove2), remove / 2);
        replace -= use2;
        remove -= use2 * 2;

        int use3 = Math.min(replace, remove / 3);
        replace -= use3;
        remove -= use3 * 3;
        return (n - 20) + Math.max(replace, 3 - types);
    }

    private int countTypes(String s) {
        int a = 0, b = 0, c = 0;
        for (char ch : s.toCharArray()) {
            if (Character.isLowerCase(ch)) {
                a = 1;
            } else if (Character.isUpperCase(ch)) {
                b = 1;
            } else if (Character.isDigit(ch)) {
                c = 1;
            }
        }
        return a + b + c;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int strongPasswordChecker(string password) {
        int types = countTypes(password);
        int n = password.size();
        if (n < 6) return max(6 - n, 3 - types);
        if (n <= 20) {
            int replace = 0, cnt = 0;
            char prev = '~';
            for (char& curr : password) {
                if (curr == prev)
                    ++cnt;
                else {
                    replace += cnt / 3;
                    cnt = 1;
                    prev = curr;
                }
            }
            replace += cnt / 3;
            return max(replace, 3 - types);
        }
        int replace = 0, remove = n - 20;
        int remove2 = 0;
        int cnt = 0;
        char prev = '~';
        for (char& curr : password) {
            if (curr == prev)
                ++cnt;
            else {
                if (remove > 0 && cnt >= 3) {
                    if (cnt % 3 == 0) {
                        --remove;
                        --replace;
                    } else if (cnt % 3 == 1)
                        ++remove2;
                }
                replace += cnt / 3;
                cnt = 1;
                prev = curr;
            }
        }
        if (remove > 0 && cnt >= 3) {
            if (cnt % 3 == 0) {
                --remove;
                --replace;
            } else if (cnt % 3 == 1)
                ++remove2;
        }
        replace += cnt / 3;

        int use2 = min(min(replace, remove2), remove / 2);
        replace -= use2;
        remove -= use2 * 2;

        int use3 = min(replace, remove / 3);
        replace -= use3;
        remove -= use3 * 3;
        return (n - 20) + max(replace, 3 - types);
    }

    int countTypes(string& s) {
        int a = 0, b = 0, c = 0;
        for (char& ch : s) {
            if (islower(ch))
                a = 1;
            else if (isupper(ch))
                b = 1;
            else if (isdigit(ch))
                c = 1;
        }
        return a + b + c;
    }
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>满足以下条件的密码被认为是强密码：</p>

<ul>
	<li>由至少 <code>6</code> 个，至多 <code>20</code> 个字符组成。</li>
	<li>包含至少 <strong>一个小写 </strong>字母，至少&nbsp;<strong>一个大写</strong> 字母，和至少&nbsp;<strong>一个数字</strong> 。</li>
	<li>不包含连续三个重复字符 (比如 <code>"B<em><strong>aaa</strong></em>bb0"</code> 是弱密码, 但是&nbsp;<code>"B<em><strong>aa</strong></em>b<em><strong>a</strong></em>0"</code> 是强密码)。</li>
</ul>

<p>给你一个字符串 <code>password</code> ，返回&nbsp;<em>将 <code>password</code> 修改到满足强密码条件需要的最少修改步数。如果 <code>password</code> 已经是强密码，则返回 <code>0</code> 。</em></p>

<p>在一步修改操作中，你可以：</p>

<ul>
	<li>插入一个字符到 <code>password</code> ，</li>
	<li>从 <code>password</code> 中删除一个字符，或</li>
	<li>用另一个字符来替换 <code>password</code> 中的某个字符。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>password = "a"
<strong>输出：</strong>5
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>password = "aA1"
<strong>输出：</strong>3
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>password = "1337C0d3"
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= password.length &lt;= 50</code></li>
	<li><code>password</code> 由字母、数字、点 <code>'.'</code> 或者感叹号 <code>'!'</code> 组成</li>
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
    def strongPasswordChecker(self, password: str) -> int:
        def countTypes(s):
            a = b = c = 0
            for ch in s:
                if ch.islower():
                    a = 1
                elif ch.isupper():
                    b = 1
                elif ch.isdigit():
                    c = 1
            return a + b + c

        types = countTypes(password)
        n = len(password)
        if n < 6:
            return max(6 - n, 3 - types)
        if n <= 20:
            replace = cnt = 0
            prev = '~'
            for curr in password:
                if curr == prev:
                    cnt += 1
                else:
                    replace += cnt // 3
                    cnt = 1
                    prev = curr
            replace += cnt // 3
            return max(replace, 3 - types)
        replace = cnt = 0
        remove, remove2 = n - 20, 0
        prev = '~'
        for curr in password:
            if curr == prev:
                cnt += 1
            else:
                if remove > 0 and cnt >= 3:
                    if cnt % 3 == 0:
                        remove -= 1
                        replace -= 1
                    elif cnt % 3 == 1:
                        remove2 += 1
                replace += cnt // 3
                cnt = 1
                prev = curr
        if remove > 0 and cnt >= 3:
            if cnt % 3 == 0:
                remove -= 1
                replace -= 1
            elif cnt % 3 == 1:
                remove2 += 1
        replace += cnt // 3
        use2 = min(replace, remove2, remove // 2)
        replace -= use2
        remove -= use2 * 2

        use3 = min(replace, remove // 3)
        replace -= use3
        remove -= use3 * 3
        return n - 20 + max(replace, 3 - types)
```

#### Java

```java
class Solution {
    public int strongPasswordChecker(String password) {
        int types = countTypes(password);
        int n = password.length();
        if (n < 6) {
            return Math.max(6 - n, 3 - types);
        }
        char[] chars = password.toCharArray();
        if (n <= 20) {
            int replace = 0;
            int cnt = 0;
            char prev = '~';
            for (char curr : chars) {
                if (curr == prev) {
                    ++cnt;
                } else {
                    replace += cnt / 3;
                    cnt = 1;
                    prev = curr;
                }
            }
            replace += cnt / 3;
            return Math.max(replace, 3 - types);
        }
        int replace = 0, remove = n - 20;
        int remove2 = 0;
        int cnt = 0;
        char prev = '~';
        for (char curr : chars) {
            if (curr == prev) {
                ++cnt;
            } else {
                if (remove > 0 && cnt >= 3) {
                    if (cnt % 3 == 0) {
                        --remove;
                        --replace;
                    } else if (cnt % 3 == 1) {
                        ++remove2;
                    }
                }
                replace += cnt / 3;
                cnt = 1;
                prev = curr;
            }
        }
        if (remove > 0 && cnt >= 3) {
            if (cnt % 3 == 0) {
                --remove;
                --replace;
            } else if (cnt % 3 == 1) {
                ++remove2;
            }
        }
        replace += cnt / 3;

        int use2 = Math.min(Math.min(replace, remove2), remove / 2);
        replace -= use2;
        remove -= use2 * 2;

        int use3 = Math.min(replace, remove / 3);
        replace -= use3;
        remove -= use3 * 3;
        return (n - 20) + Math.max(replace, 3 - types);
    }

    private int countTypes(String s) {
        int a = 0, b = 0, c = 0;
        for (char ch : s.toCharArray()) {
            if (Character.isLowerCase(ch)) {
                a = 1;
            } else if (Character.isUpperCase(ch)) {
                b = 1;
            } else if (Character.isDigit(ch)) {
                c = 1;
            }
        }
        return a + b + c;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int strongPasswordChecker(string password) {
        int types = countTypes(password);
        int n = password.size();
        if (n < 6) return max(6 - n, 3 - types);
        if (n <= 20) {
            int replace = 0, cnt = 0;
            char prev = '~';
            for (char& curr : password) {
                if (curr == prev)
                    ++cnt;
                else {
                    replace += cnt / 3;
                    cnt = 1;
                    prev = curr;
                }
            }
            replace += cnt / 3;
            return max(replace, 3 - types);
        }
        int replace = 0, remove = n - 20;
        int remove2 = 0;
        int cnt = 0;
        char prev = '~';
        for (char& curr : password) {
            if (curr == prev)
                ++cnt;
            else {
                if (remove > 0 && cnt >= 3) {
                    if (cnt % 3 == 0) {
                        --remove;
                        --replace;
                    } else if (cnt % 3 == 1)
                        ++remove2;
                }
                replace += cnt / 3;
                cnt = 1;
                prev = curr;
            }
        }
        if (remove > 0 && cnt >= 3) {
            if (cnt % 3 == 0) {
                --remove;
                --replace;
            } else if (cnt % 3 == 1)
                ++remove2;
        }
        replace += cnt / 3;

        int use2 = min(min(replace, remove2), remove / 2);
        replace -= use2;
        remove -= use2 * 2;

        int use3 = min(replace, remove / 3);
        replace -= use3;
        remove -= use3 * 3;
        return (n - 20) + max(replace, 3 - types);
    }

    int countTypes(string& s) {
        int a = 0, b = 0, c = 0;
        for (char& ch : s) {
            if (islower(ch))
                a = 1;
            else if (isupper(ch))
                b = 1;
            else if (isdigit(ch))
                c = 1;
        }
        return a + b + c;
    }
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [421. 数组中两个数的最大异或值](https://leetcode.cn/problems/maximum-xor-of-two-numbers-in-an-array){#421}

{{< tabs "421" >}}

{{% tab "python" %}}
```python
class Trie:
    __slots__ = ("children",)

    def __init__(self):
        self.children: List[Trie | None] = [None, None]

    def insert(self, x: int):
        node = self
        for i in range(30, -1, -1):
            v = x >> i & 1
            if node.children[v] is None:
                node.children[v] = Trie()
            node = node.children[v]

    def search(self, x: int) -> int:
        node = self
        ans = 0
        for i in range(30, -1, -1):
            v = x >> i & 1
            if node.children[v ^ 1]:
                ans |= 1 << i
                node = node.children[v ^ 1]
            else:
                node = node.children[v]
        return ans


class Solution:
    def findMaximumXOR(self, nums: List[int]) -> int:
        trie = Trie()
        for x in nums:
            trie.insert(x)
        return max(trie.search(x) for x in nums)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Trie {
    private Trie[] children = new Trie[2];

    public Trie() {
    }

    public void insert(int x) {
        Trie node = this;
        for (int i = 30; i >= 0; --i) {
            int v = x >> i & 1;
            if (node.children[v] == null) {
                node.children[v] = new Trie();
            }
            node = node.children[v];
        }
    }

    public int search(int x) {
        Trie node = this;
        int ans = 0;
        for (int i = 30; i >= 0; --i) {
            int v = x >> i & 1;
            if (node.children[v ^ 1] != null) {
                ans |= 1 << i;
                node = node.children[v ^ 1];
            } else {
                node = node.children[v];
            }
        }
        return ans;
    }
}

class Solution {
    public int findMaximumXOR(int[] nums) {
        Trie trie = new Trie();
        int ans = 0;
        for (int x : nums) {
            trie.insert(x);
            ans = Math.max(ans, trie.search(x));
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Trie {
public:
    Trie* children[2];

    Trie()
        : children{nullptr, nullptr} {}

    void insert(int x) {
        Trie* node = this;
        for (int i = 30; ~i; --i) {
            int v = x >> i & 1;
            if (!node->children[v]) {
                node->children[v] = new Trie();
            }
            node = node->children[v];
        }
    }

    int search(int x) {
        Trie* node = this;
        int ans = 0;
        for (int i = 30; ~i; --i) {
            int v = x >> i & 1;
            if (node->children[v ^ 1]) {
                ans |= 1 << i;
                node = node->children[v ^ 1];
            } else {
                node = node->children[v];
            }
        }
        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* trie = new Trie();
        int ans = 0;
        for (int x : nums) {
            trie->insert(x);
            ans = max(ans, trie->search(x));
        }
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

func (t *Trie) insert(x int) {
	node := t
	for i := 30; i >= 0; i-- {
		v := x >> i & 1
		if node.children[v] == nil {
			node.children[v] = newTrie()
		}
		node = node.children[v]
	}
}

func (t *Trie) search(x int) int {
	node := t
	ans := 0
	for i := 30; i >= 0; i-- {
		v := x >> i & 1
		if node.children[v^1] != nil {
			ans |= 1 << i
			node = node.children[v^1]
		} else {
			node = node.children[v]
		}
	}
	return ans
}

func findMaximumXOR(nums []int) (ans int) {
	trie := newTrie()
	for _, x := range nums {
		trie.insert(x)
		ans = max(ans, trie.search(x))
	}
	return ans
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
struct Trie {
    children: [Option<Box<Trie>>; 2],
}

impl Trie {
    fn new() -> Trie {
        Trie {
            children: [None, None],
        }
    }

    fn insert(&mut self, x: i32) {
        let mut node = self;
        for i in (0..=30).rev() {
            let v = ((x >> i) & 1) as usize;
            if node.children[v].is_none() {
                node.children[v] = Some(Box::new(Trie::new()));
            }
            node = node.children[v].as_mut().unwrap();
        }
    }

    fn search(&self, x: i32) -> i32 {
        let mut node = self;
        let mut ans = 0;
        for i in (0..=30).rev() {
            let v = ((x >> i) & 1) as usize;
            if let Some(child) = &node.children[v ^ 1] {
                ans |= 1 << i;
                node = child.as_ref();
            } else {
                node = node.children[v].as_ref().unwrap();
            }
        }
        ans
    }
}

impl Solution {
    pub fn find_maximum_xor(nums: Vec<i32>) -> i32 {
        let mut trie = Trie::new();
        let mut ans = 0;
        for &x in nums.iter() {
            trie.insert(x);
            ans = ans.max(trie.search(x));
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

<p>给你一个整数数组 <code>nums</code> ，返回<em> </em><code>nums[i] XOR nums[j]</code> 的最大运算结果，其中 <code>0 ≤ i ≤ j &lt; n</code> 。</p>

<p>&nbsp;</p>

<div class="original__bRMd">
<div>
<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,10,5,25,2,8]
<strong>输出：</strong>28
<strong>解释：</strong>最大运算结果是 5 XOR 25 = 28.</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [14,70,53,83,49,91,36,80,92,51,66,70]
<strong>输出：</strong>127
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
</ul>
</div>
</div>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀树

题目是求两个元素的异或最大值，可以从最高位开始考虑。

我们把数组中的每个元素 $x$ 看作一个 $32$ 位的 $01$ 串，按二进制从高位到低位的顺序，插入前缀树（最低位为叶子节点）。

搜索 $x$ 时，尽量走相反的 $01$ 字符指针的策略，因为异或运算的法则是相同得 $0$，不同得 $1$，所以我们尽可能往与 $x$ 当前位相反的字符方向走，才能得到能和 $x$ 产生最大异或值的结果。

时间复杂度 $O(n \times \log M)$，空间复杂度 $O(n \times \log M)$，其中 $n$ 是数组 $nums$ 的长度，而 $M$ 是数组中元素的最大值。

<!-- tabs:start -->

#### Python3

```python
class Trie:
    __slots__ = ("children",)

    def __init__(self):
        self.children: List[Trie | None] = [None, None]

    def insert(self, x: int):
        node = self
        for i in range(30, -1, -1):
            v = x >> i & 1
            if node.children[v] is None:
                node.children[v] = Trie()
            node = node.children[v]

    def search(self, x: int) -> int:
        node = self
        ans = 0
        for i in range(30, -1, -1):
            v = x >> i & 1
            if node.children[v ^ 1]:
                ans |= 1 << i
                node = node.children[v ^ 1]
            else:
                node = node.children[v]
        return ans


class Solution:
    def findMaximumXOR(self, nums: List[int]) -> int:
        trie = Trie()
        for x in nums:
            trie.insert(x)
        return max(trie.search(x) for x in nums)
```

#### Java

```java
class Trie {
    private Trie[] children = new Trie[2];

    public Trie() {
    }

    public void insert(int x) {
        Trie node = this;
        for (int i = 30; i >= 0; --i) {
            int v = x >> i & 1;
            if (node.children[v] == null) {
                node.children[v] = new Trie();
            }
            node = node.children[v];
        }
    }

    public int search(int x) {
        Trie node = this;
        int ans = 0;
        for (int i = 30; i >= 0; --i) {
            int v = x >> i & 1;
            if (node.children[v ^ 1] != null) {
                ans |= 1 << i;
                node = node.children[v ^ 1];
            } else {
                node = node.children[v];
            }
        }
        return ans;
    }
}

class Solution {
    public int findMaximumXOR(int[] nums) {
        Trie trie = new Trie();
        int ans = 0;
        for (int x : nums) {
            trie.insert(x);
            ans = Math.max(ans, trie.search(x));
        }
        return ans;
    }
}
```

#### C++

```cpp
class Trie {
public:
    Trie* children[2];

    Trie()
        : children{nullptr, nullptr} {}

    void insert(int x) {
        Trie* node = this;
        for (int i = 30; ~i; --i) {
            int v = x >> i & 1;
            if (!node->children[v]) {
                node->children[v] = new Trie();
            }
            node = node->children[v];
        }
    }

    int search(int x) {
        Trie* node = this;
        int ans = 0;
        for (int i = 30; ~i; --i) {
            int v = x >> i & 1;
            if (node->children[v ^ 1]) {
                ans |= 1 << i;
                node = node->children[v ^ 1];
            } else {
                node = node->children[v];
            }
        }
        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* trie = new Trie();
        int ans = 0;
        for (int x : nums) {
            trie->insert(x);
            ans = max(ans, trie->search(x));
        }
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

func (t *Trie) insert(x int) {
	node := t
	for i := 30; i >= 0; i-- {
		v := x >> i & 1
		if node.children[v] == nil {
			node.children[v] = newTrie()
		}
		node = node.children[v]
	}
}

func (t *Trie) search(x int) int {
	node := t
	ans := 0
	for i := 30; i >= 0; i-- {
		v := x >> i & 1
		if node.children[v^1] != nil {
			ans |= 1 << i
			node = node.children[v^1]
		} else {
			node = node.children[v]
		}
	}
	return ans
}

func findMaximumXOR(nums []int) (ans int) {
	trie := newTrie()
	for _, x := range nums {
		trie.insert(x)
		ans = max(ans, trie.search(x))
	}
	return ans
}
```

#### Rust

```rust
struct Trie {
    children: [Option<Box<Trie>>; 2],
}

impl Trie {
    fn new() -> Trie {
        Trie {
            children: [None, None],
        }
    }

    fn insert(&mut self, x: i32) {
        let mut node = self;
        for i in (0..=30).rev() {
            let v = ((x >> i) & 1) as usize;
            if node.children[v].is_none() {
                node.children[v] = Some(Box::new(Trie::new()));
            }
            node = node.children[v].as_mut().unwrap();
        }
    }

    fn search(&self, x: i32) -> i32 {
        let mut node = self;
        let mut ans = 0;
        for i in (0..=30).rev() {
            let v = ((x >> i) & 1) as usize;
            if let Some(child) = &node.children[v ^ 1] {
                ans |= 1 << i;
                node = child.as_ref();
            } else {
                node = node.children[v].as_ref().unwrap();
            }
        }
        ans
    }
}

impl Solution {
    pub fn find_maximum_xor(nums: Vec<i32>) -> i32 {
        let mut trie = Trie::new();
        let mut ans = 0;
        for &x in nums.iter() {
            trie.insert(x);
            ans = ans.max(trie.search(x));
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

# [422. 有效的单词方块 🔒](https://leetcode.cn/problems/valid-word-square){#422}

{{< tabs "422" >}}

{{% tab "python" %}}
```python
class Solution:
    def validWordSquare(self, words: List[str]) -> bool:
        m = len(words)
        for i, w in enumerate(words):
            for j, c in enumerate(w):
                if j >= m or i >= len(words[j]) or c != words[j][i]:
                    return False
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean validWordSquare(List<String> words) {
        int m = words.size();
        for (int i = 0; i < m; ++i) {
            int n = words.get(i).length();
            for (int j = 0; j < n; ++j) {
                if (j >= m || i >= words.get(j).length()) {
                    return false;
                }
                if (words.get(i).charAt(j) != words.get(j).charAt(i)) {
                    return false;
                }
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
    bool validWordSquare(vector<string>& words) {
        int m = words.size();
        for (int i = 0; i < m; ++i) {
            int n = words[i].size();
            for (int j = 0; j < n; ++j) {
                if (j >= m || i >= words[j].size() || words[i][j] != words[j][i]) {
                    return false;
                }
            }
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func validWordSquare(words []string) bool {
	m := len(words)
	for i, w := range words {
		for j := range w {
			if j >= m || i >= len(words[j]) || w[j] != words[j][i] {
				return false
			}
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function validWordSquare(words: string[]): boolean {
    const m = words.length;
    for (let i = 0; i < m; ++i) {
        const n = words[i].length;
        for (let j = 0; j < n; ++j) {
            if (j >= m || i >= words[j].length || words[i][j] !== words[j][i]) {
                return false;
            }
        }
    }
    return true;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串数组 <code>words</code>，如果它能形成一个有效的<strong> 单词方块 </strong>，则返回 <code>true</code> <em>。</em></p>

<p>有效的单词方块是指此由字符串数组组成的文字方块的&nbsp;第 <code>k</code> 行 和&nbsp;第 <code>k</code> 列所显示的字符串完全相同，其中 <code>0 &lt;= k &lt; max(numRows, numColumns)</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0422.Valid%20Word%20Square/images/validsq1-grid.jpg" style="width: 333px; height: 333px;" />
<pre>
<strong>输入:</strong> words = ["abcd","bnrt","crmy","dtye"]
<strong>输出:</strong> true
<strong>解释:</strong>
第 1 行和第 1 列都读作 "abcd"。
第 2 行和第 2 列都读作 "bnrt"。
第 3 行和第 3 列都读作 "crmy"。
第 4 行和第 4 列都读作 "dtye"。
因此，它构成了一个有效的单词方块。
</pre>

<p><strong class="example">示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0422.Valid%20Word%20Square/images/validsq2-grid.jpg" style="width: 333px; height: 333px;" />
<pre>
<strong>输入:</strong> words = ["abcd","bnrt","crm","dt"]
<strong>输出:</strong> true
<strong>解释:</strong>
第 1 行和第 1 列都读作 "abcd"。
第 2 行和第 2 列都读作 "bnrt"。
第 3 行和第 3 列都读作 "crm"。
第 4 行和第 4 列都读作 "dt"。
因此，它构成了一个有效的单词方块。
</pre>

<p><strong class="example">示例 3：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0422.Valid%20Word%20Square/images/validsq3-grid.jpg" style="width: 333px; height: 333px;" />
<pre>
<strong>输入:</strong> words = ["ball","area","read","lady"]
<strong>输出:</strong> false
<strong>解释:</strong>
第 3 行读作 "read" 而第 3 列读作 "lead"。
因此，它不构成一个有效的单词方块。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 500</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 500</code></li>
	<li><code>words[i]</code> 仅由小写英文字母组成。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：遍历检查

我们观察发现，只要不满足 $words[i][j] = words[j][i]$，就可以直接返回 `false`。

因此，我们只需要遍历每一行，然后检查每一行是否满足 $words[i][j] = words[j][i]$ 即可。注意，如果下标越界，也直接返回 `false`。

时间复杂度 $O(n^2)$，其中 $n$ 是 $words$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def validWordSquare(self, words: List[str]) -> bool:
        m = len(words)
        for i, w in enumerate(words):
            for j, c in enumerate(w):
                if j >= m or i >= len(words[j]) or c != words[j][i]:
                    return False
        return True
```

#### Java

```java
class Solution {
    public boolean validWordSquare(List<String> words) {
        int m = words.size();
        for (int i = 0; i < m; ++i) {
            int n = words.get(i).length();
            for (int j = 0; j < n; ++j) {
                if (j >= m || i >= words.get(j).length()) {
                    return false;
                }
                if (words.get(i).charAt(j) != words.get(j).charAt(i)) {
                    return false;
                }
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
    bool validWordSquare(vector<string>& words) {
        int m = words.size();
        for (int i = 0; i < m; ++i) {
            int n = words[i].size();
            for (int j = 0; j < n; ++j) {
                if (j >= m || i >= words[j].size() || words[i][j] != words[j][i]) {
                    return false;
                }
            }
        }
        return true;
    }
};
```

#### Go

```go
func validWordSquare(words []string) bool {
	m := len(words)
	for i, w := range words {
		for j := range w {
			if j >= m || i >= len(words[j]) || w[j] != words[j][i] {
				return false
			}
		}
	}
	return true
}
```

#### TypeScript

```ts
function validWordSquare(words: string[]): boolean {
    const m = words.length;
    for (let i = 0; i < m; ++i) {
        const n = words[i].length;
        for (let j = 0; j < n; ++j) {
            if (j >= m || i >= words[j].length || words[i][j] !== words[j][i]) {
                return false;
            }
        }
    }
    return true;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [423. 从英文中重建数字](https://leetcode.cn/problems/reconstruct-original-digits-from-english){#423}

{{< tabs "423" >}}

{{% tab "python" %}}
```python
class Solution:
    def originalDigits(self, s: str) -> str:
        counter = Counter(s)
        cnt = [0] * 10

        cnt[0] = counter['z']
        cnt[2] = counter['w']
        cnt[4] = counter['u']
        cnt[6] = counter['x']
        cnt[8] = counter['g']

        cnt[3] = counter['h'] - cnt[8]
        cnt[5] = counter['f'] - cnt[4]
        cnt[7] = counter['s'] - cnt[6]

        cnt[1] = counter['o'] - cnt[0] - cnt[2] - cnt[4]
        cnt[9] = counter['i'] - cnt[5] - cnt[6] - cnt[8]

        return ''.join(cnt[i] * str(i) for i in range(10))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String originalDigits(String s) {
        int[] counter = new int[26];
        for (char c : s.toCharArray()) {
            ++counter[c - 'a'];
        }
        int[] cnt = new int[10];
        cnt[0] = counter['z' - 'a'];
        cnt[2] = counter['w' - 'a'];
        cnt[4] = counter['u' - 'a'];
        cnt[6] = counter['x' - 'a'];
        cnt[8] = counter['g' - 'a'];

        cnt[3] = counter['h' - 'a'] - cnt[8];
        cnt[5] = counter['f' - 'a'] - cnt[4];
        cnt[7] = counter['s' - 'a'] - cnt[6];

        cnt[1] = counter['o' - 'a'] - cnt[0] - cnt[2] - cnt[4];
        cnt[9] = counter['i' - 'a'] - cnt[5] - cnt[6] - cnt[8];

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < cnt[i]; ++j) {
                sb.append(i);
            }
        }
        return sb.toString();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string originalDigits(string s) {
        vector<int> counter(26);
        for (char c : s) ++counter[c - 'a'];
        vector<int> cnt(10);
        cnt[0] = counter['z' - 'a'];
        cnt[2] = counter['w' - 'a'];
        cnt[4] = counter['u' - 'a'];
        cnt[6] = counter['x' - 'a'];
        cnt[8] = counter['g' - 'a'];

        cnt[3] = counter['h' - 'a'] - cnt[8];
        cnt[5] = counter['f' - 'a'] - cnt[4];
        cnt[7] = counter['s' - 'a'] - cnt[6];

        cnt[1] = counter['o' - 'a'] - cnt[0] - cnt[2] - cnt[4];
        cnt[9] = counter['i' - 'a'] - cnt[5] - cnt[6] - cnt[8];

        string ans;
        for (int i = 0; i < 10; ++i)
            for (int j = 0; j < cnt[i]; ++j)
                ans += char(i + '0');
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func originalDigits(s string) string {
	counter := make([]int, 26)
	for _, c := range s {
		counter[c-'a']++
	}
	cnt := make([]int, 10)
	cnt[0] = counter['z'-'a']
	cnt[2] = counter['w'-'a']
	cnt[4] = counter['u'-'a']
	cnt[6] = counter['x'-'a']
	cnt[8] = counter['g'-'a']

	cnt[3] = counter['h'-'a'] - cnt[8]
	cnt[5] = counter['f'-'a'] - cnt[4]
	cnt[7] = counter['s'-'a'] - cnt[6]

	cnt[1] = counter['o'-'a'] - cnt[0] - cnt[2] - cnt[4]
	cnt[9] = counter['i'-'a'] - cnt[5] - cnt[6] - cnt[8]

	ans := []byte{}
	for i, c := range cnt {
		ans = append(ans, bytes.Repeat([]byte{byte('0' + i)}, c)...)
	}
	return string(ans)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>s</code> ，其中包含字母顺序打乱的用英文单词表示的若干数字（<code>0-9</code>）。按 <strong>升序</strong> 返回原始的数字。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "owoztneoer"
<strong>输出：</strong>"012"
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "fviefuro"
<strong>输出：</strong>"45"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code> 为 <code>["e","g","f","i","h","o","n","s","r","u","t","w","v","x","z"]</code> 这些字符之一</li>
	<li><code>s</code> 保证是一个符合题目要求的字符串</li>
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
    def originalDigits(self, s: str) -> str:
        counter = Counter(s)
        cnt = [0] * 10

        cnt[0] = counter['z']
        cnt[2] = counter['w']
        cnt[4] = counter['u']
        cnt[6] = counter['x']
        cnt[8] = counter['g']

        cnt[3] = counter['h'] - cnt[8]
        cnt[5] = counter['f'] - cnt[4]
        cnt[7] = counter['s'] - cnt[6]

        cnt[1] = counter['o'] - cnt[0] - cnt[2] - cnt[4]
        cnt[9] = counter['i'] - cnt[5] - cnt[6] - cnt[8]

        return ''.join(cnt[i] * str(i) for i in range(10))
```

#### Java

```java
class Solution {
    public String originalDigits(String s) {
        int[] counter = new int[26];
        for (char c : s.toCharArray()) {
            ++counter[c - 'a'];
        }
        int[] cnt = new int[10];
        cnt[0] = counter['z' - 'a'];
        cnt[2] = counter['w' - 'a'];
        cnt[4] = counter['u' - 'a'];
        cnt[6] = counter['x' - 'a'];
        cnt[8] = counter['g' - 'a'];

        cnt[3] = counter['h' - 'a'] - cnt[8];
        cnt[5] = counter['f' - 'a'] - cnt[4];
        cnt[7] = counter['s' - 'a'] - cnt[6];

        cnt[1] = counter['o' - 'a'] - cnt[0] - cnt[2] - cnt[4];
        cnt[9] = counter['i' - 'a'] - cnt[5] - cnt[6] - cnt[8];

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < cnt[i]; ++j) {
                sb.append(i);
            }
        }
        return sb.toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string originalDigits(string s) {
        vector<int> counter(26);
        for (char c : s) ++counter[c - 'a'];
        vector<int> cnt(10);
        cnt[0] = counter['z' - 'a'];
        cnt[2] = counter['w' - 'a'];
        cnt[4] = counter['u' - 'a'];
        cnt[6] = counter['x' - 'a'];
        cnt[8] = counter['g' - 'a'];

        cnt[3] = counter['h' - 'a'] - cnt[8];
        cnt[5] = counter['f' - 'a'] - cnt[4];
        cnt[7] = counter['s' - 'a'] - cnt[6];

        cnt[1] = counter['o' - 'a'] - cnt[0] - cnt[2] - cnt[4];
        cnt[9] = counter['i' - 'a'] - cnt[5] - cnt[6] - cnt[8];

        string ans;
        for (int i = 0; i < 10; ++i)
            for (int j = 0; j < cnt[i]; ++j)
                ans += char(i + '0');
        return ans;
    }
};
```

#### Go

```go
func originalDigits(s string) string {
	counter := make([]int, 26)
	for _, c := range s {
		counter[c-'a']++
	}
	cnt := make([]int, 10)
	cnt[0] = counter['z'-'a']
	cnt[2] = counter['w'-'a']
	cnt[4] = counter['u'-'a']
	cnt[6] = counter['x'-'a']
	cnt[8] = counter['g'-'a']

	cnt[3] = counter['h'-'a'] - cnt[8]
	cnt[5] = counter['f'-'a'] - cnt[4]
	cnt[7] = counter['s'-'a'] - cnt[6]

	cnt[1] = counter['o'-'a'] - cnt[0] - cnt[2] - cnt[4]
	cnt[9] = counter['i'-'a'] - cnt[5] - cnt[6] - cnt[8]

	ans := []byte{}
	for i, c := range cnt {
		ans = append(ans, bytes.Repeat([]byte{byte('0' + i)}, c)...)
	}
	return string(ans)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [424. 替换后的最长重复字符](https://leetcode.cn/problems/longest-repeating-character-replacement){#424}

{{< tabs "424" >}}

{{% tab "python" %}}
```python
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        cnt = Counter()
        l = mx = 0
        for r, c in enumerate(s):
            cnt[c] += 1
            mx = max(mx, cnt[c])
            if r - l + 1 - mx > k:
                cnt[s[l]] -= 1
                l += 1
        return len(s) - l
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int characterReplacement(String s, int k) {
        int[] cnt = new int[26];
        int l = 0, mx = 0;
        int n = s.length();
        for (int r = 0; r < n; ++r) {
            mx = Math.max(mx, ++cnt[s.charAt(r) - 'A']);
            if (r - l + 1 - mx > k) {
                --cnt[s.charAt(l++) - 'A'];
            }
        }
        return n - l;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int characterReplacement(string s, int k) {
        int cnt[26]{};
        int l = 0, mx = 0;
        int n = s.length();
        for (int r = 0; r < n; ++r) {
            mx = max(mx, ++cnt[s[r] - 'A']);
            if (r - l + 1 - mx > k) {
                --cnt[s[l++] - 'A'];
            }
        }
        return n - l;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func characterReplacement(s string, k int) int {
	cnt := [26]int{}
	l, mx := 0, 0
	for r, c := range s {
		cnt[c-'A']++
		mx = max(mx, cnt[c-'A'])
		if r-l+1-mx > k {
			cnt[s[l]-'A']--
			l++
		}
	}
	return len(s) - l
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function characterReplacement(s: string, k: number): number {
    const idx = (c: string) => c.charCodeAt(0) - 65;
    const cnt: number[] = Array(26).fill(0);
    const n = s.length;
    let [l, mx] = [0, 0];
    for (let r = 0; r < n; ++r) {
        mx = Math.max(mx, ++cnt[idx(s[r])]);
        if (r - l + 1 - mx > k) {
            --cnt[idx(s[l++])];
        }
    }
    return n - l;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>s</code> 和一个整数 <code>k</code> 。你可以选择字符串中的任一字符，并将其更改为任何其他大写英文字符。该操作最多可执行 <code>k</code> 次。</p>

<p>在执行上述操作后，返回 <em>包含相同字母的最长子字符串的长度。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "ABAB", k = 2
<strong>输出：</strong>4
<strong>解释：</strong>用两个'A'替换为两个'B',反之亦然。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "AABABBA", k = 1
<strong>输出：</strong>4
<strong>解释：</strong>
将中间的一个'A'替换为'B',字符串变为 "AABBBBA"。
子串 "BBBB" 有最长重复字母, 答案为 4。
可能存在其他的方法来得到同样的结果。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> 仅由大写英文字母组成</li>
	<li><code>0 &lt;= k &lt;= s.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

我们使用一个哈希表 `cnt` 统计字符串中每个字符出现的次数，使用双指针 `l` 和 `r` 维护一个滑动窗口，使得窗口的大小减去出现次数最多的字符的次数，结果不超过 $k$。

我们遍历字符串，每次更新窗口的右边界 `r`，并更新窗口内的字符出现次数，同时更新出现过的字符的最大出现次数 `mx`。当窗口的大小减去 `mx` 大于 $k$ 时，我们需要缩小窗口的左边界 `l`，同时更新窗口内的字符出现次数，直到窗口的大小减去 `mx` 不大于 $k$。

最后，答案为 $n - l$，其中 $n$ 为字符串的长度。

时间复杂度 $O(n)$，空间复杂度 $O(|\Sigma|)$。其中 $n$ 为字符串的长度，而 $|\Sigma|$ 为字符集的大小，本题中字符集为大写英文字母，所以 $|\Sigma| = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        cnt = Counter()
        l = mx = 0
        for r, c in enumerate(s):
            cnt[c] += 1
            mx = max(mx, cnt[c])
            if r - l + 1 - mx > k:
                cnt[s[l]] -= 1
                l += 1
        return len(s) - l
```

#### Java

```java
class Solution {
    public int characterReplacement(String s, int k) {
        int[] cnt = new int[26];
        int l = 0, mx = 0;
        int n = s.length();
        for (int r = 0; r < n; ++r) {
            mx = Math.max(mx, ++cnt[s.charAt(r) - 'A']);
            if (r - l + 1 - mx > k) {
                --cnt[s.charAt(l++) - 'A'];
            }
        }
        return n - l;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int characterReplacement(string s, int k) {
        int cnt[26]{};
        int l = 0, mx = 0;
        int n = s.length();
        for (int r = 0; r < n; ++r) {
            mx = max(mx, ++cnt[s[r] - 'A']);
            if (r - l + 1 - mx > k) {
                --cnt[s[l++] - 'A'];
            }
        }
        return n - l;
    }
};
```

#### Go

```go
func characterReplacement(s string, k int) int {
	cnt := [26]int{}
	l, mx := 0, 0
	for r, c := range s {
		cnt[c-'A']++
		mx = max(mx, cnt[c-'A'])
		if r-l+1-mx > k {
			cnt[s[l]-'A']--
			l++
		}
	}
	return len(s) - l
}
```

#### TypeScript

```ts
function characterReplacement(s: string, k: number): number {
    const idx = (c: string) => c.charCodeAt(0) - 65;
    const cnt: number[] = Array(26).fill(0);
    const n = s.length;
    let [l, mx] = [0, 0];
    for (let r = 0; r < n; ++r) {
        mx = Math.max(mx, ++cnt[idx(s[r])]);
        if (r - l + 1 - mx > k) {
            --cnt[idx(s[l++])];
        }
    }
    return n - l;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [425. 单词方块 🔒](https://leetcode.cn/problems/word-squares){#425}

{{< tabs "425" >}}

{{% tab "python" %}}
```python
class Trie:
    def __init__(self):
        self.children = [None] * 26
        self.v = []

    def insert(self, w, i):
        node = self
        for c in w:
            idx = ord(c) - ord('a')
            if node.children[idx] is None:
                node.children[idx] = Trie()
            node = node.children[idx]
            node.v.append(i)

    def search(self, w):
        node = self
        for c in w:
            idx = ord(c) - ord('a')
            if node.children[idx] is None:
                return []
            node = node.children[idx]
        return node.v


class Solution:
    def wordSquares(self, words: List[str]) -> List[List[str]]:
        def dfs(t):
            if len(t) == len(words[0]):
                ans.append(t[:])
                return
            idx = len(t)
            pref = [v[idx] for v in t]
            indexes = trie.search(''.join(pref))
            for i in indexes:
                t.append(words[i])
                dfs(t)
                t.pop()

        trie = Trie()
        ans = []
        for i, w in enumerate(words):
            trie.insert(w, i)
        for w in words:
            dfs([w])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Trie {
    Trie[] children = new Trie[26];
    List<Integer> v = new ArrayList<>();

    void insert(String word, int i) {
        Trie node = this;
        for (char c : word.toCharArray()) {
            c -= 'a';
            if (node.children[c] == null) {
                node.children[c] = new Trie();
            }
            node = node.children[c];
            node.v.add(i);
        }
    }

    List<Integer> search(String pref) {
        Trie node = this;
        for (char c : pref.toCharArray()) {
            c -= 'a';
            if (node.children[c] == null) {
                return Collections.emptyList();
            }
            node = node.children[c];
        }
        return node.v;
    }
}

class Solution {
    private Trie trie = new Trie();
    private String[] words;
    private List<List<String>> ans = new ArrayList<>();

    public List<List<String>> wordSquares(String[] words) {
        this.words = words;
        for (int i = 0; i < words.length; ++i) {
            trie.insert(words[i], i);
        }

        List<String> t = new ArrayList<>();
        for (String w : words) {
            t.add(w);
            dfs(t);
            t.remove(t.size() - 1);
        }
        return ans;
    }

    private void dfs(List<String> t) {
        if (t.size() == words[0].length()) {
            ans.add(new ArrayList<>(t));
            return;
        }
        int idx = t.size();
        StringBuilder pref = new StringBuilder();
        for (String x : t) {
            pref.append(x.charAt(idx));
        }
        List<Integer> indexes = trie.search(pref.toString());
        for (int i : indexes) {
            t.add(words[i]);
            dfs(t);
            t.remove(t.size() - 1);
        }
    }
}
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Trie struct {
	children [26]*Trie
	v        []int
}

func newTrie() *Trie {
	return &Trie{}
}
func (this *Trie) insert(word string, i int) {
	node := this
	for _, c := range word {
		c -= 'a'
		if node.children[c] == nil {
			node.children[c] = newTrie()
		}
		node = node.children[c]
		node.v = append(node.v, i)
	}
}
func (this *Trie) search(word string) []int {
	node := this
	for _, c := range word {
		c -= 'a'
		if node.children[c] == nil {
			return []int{}
		}
		node = node.children[c]
	}
	return node.v
}

func wordSquares(words []string) [][]string {
	trie := newTrie()
	for i, w := range words {
		trie.insert(w, i)
	}
	ans := [][]string{}
	var dfs func([]string)
	dfs = func(t []string) {
		if len(t) == len(words[0]) {
			cp := make([]string, len(t))
			copy(cp, t)
			ans = append(ans, cp)
			return
		}
		idx := len(t)
		pref := []byte{}
		for _, v := range t {
			pref = append(pref, v[idx])
		}
		indexes := trie.search(string(pref))
		for _, i := range indexes {
			t = append(t, words[i])
			dfs(t)
			t = t[:len(t)-1]
		}
	}
	for _, w := range words {
		dfs([]string{w})
	}
	return ans
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个单词集合&nbsp;<code>words</code> <strong>（没有重复）</strong>，找出并返回其中所有的 <a href="https://en.wikipedia.org/wiki/Word_square">单词方块</a><strong>&nbsp;</strong>。&nbsp;<code>words</code>&nbsp;中的同一个单词可以被 <strong>多次</strong> 使用。你可以按 <strong>任意顺序</strong> 返回答案。</p>

<p>一个单词序列形成了一个有效的 <strong>单词方块</strong> 的意思是指从第 <code>k</code> 行和第 <code>k</code> 列 &nbsp;<code>0 &lt;= k &lt; max(numRows, numColumns)</code> 来看都是相同的字符串。</p>

<ul>
	<li>例如，单词序列&nbsp;<code>["ball","area","lead","lady"]</code>&nbsp;形成了一个单词方块，因为每个单词从水平方向看和从竖直方向看都是相同的。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>words = ["area","lead","wall","lady","ball"]
<strong>输出:</strong> [["ball","area","lead","lady"],
["wall","area","lead","lady"]]
<strong>解释：</strong>
输出包含两个单词方块，输出的顺序不重要，只需要保证每个单词方块内的单词顺序正确即可。 
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>words = ["abat","baba","atan","atal"]
<strong>输出：</strong>[["baba","abat","baba","atal"],
["baba","abat","baba","atan"]]
<strong>解释：</strong>
输出包含两个单词方块，输出的顺序不重要，只需要保证每个单词方块内的单词顺序正确即可。 
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 1000</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 4</code></li>
	<li><code>words[i]</code>&nbsp;长度相同</li>
	<li><code>words[i]</code>&nbsp;只由小写英文字母组成</li>
	<li><code>words[i]</code>&nbsp;都 <strong>各不相同</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀树 + DFS

根据已添加单词确定下一个单词的前缀，继续进行搜索。

比如已经添加了两个单词 $ball$ 和 $area$，要添加下一个单词，我们首先要获取下一个单词的前缀，第一个字母是第一个单词的第三个位置 $l$，第二个字母是第二个单词的第三个位置 $e$，这样就构成了前缀 $le$。然后找出所有前缀为 $le$ 的单词，作为下一个单词。

<!-- tabs:start -->

#### Python3

```python
class Trie:
    def __init__(self):
        self.children = [None] * 26
        self.v = []

    def insert(self, w, i):
        node = self
        for c in w:
            idx = ord(c) - ord('a')
            if node.children[idx] is None:
                node.children[idx] = Trie()
            node = node.children[idx]
            node.v.append(i)

    def search(self, w):
        node = self
        for c in w:
            idx = ord(c) - ord('a')
            if node.children[idx] is None:
                return []
            node = node.children[idx]
        return node.v


class Solution:
    def wordSquares(self, words: List[str]) -> List[List[str]]:
        def dfs(t):
            if len(t) == len(words[0]):
                ans.append(t[:])
                return
            idx = len(t)
            pref = [v[idx] for v in t]
            indexes = trie.search(''.join(pref))
            for i in indexes:
                t.append(words[i])
                dfs(t)
                t.pop()

        trie = Trie()
        ans = []
        for i, w in enumerate(words):
            trie.insert(w, i)
        for w in words:
            dfs([w])
        return ans
```

#### Java

```java
class Trie {
    Trie[] children = new Trie[26];
    List<Integer> v = new ArrayList<>();

    void insert(String word, int i) {
        Trie node = this;
        for (char c : word.toCharArray()) {
            c -= 'a';
            if (node.children[c] == null) {
                node.children[c] = new Trie();
            }
            node = node.children[c];
            node.v.add(i);
        }
    }

    List<Integer> search(String pref) {
        Trie node = this;
        for (char c : pref.toCharArray()) {
            c -= 'a';
            if (node.children[c] == null) {
                return Collections.emptyList();
            }
            node = node.children[c];
        }
        return node.v;
    }
}

class Solution {
    private Trie trie = new Trie();
    private String[] words;
    private List<List<String>> ans = new ArrayList<>();

    public List<List<String>> wordSquares(String[] words) {
        this.words = words;
        for (int i = 0; i < words.length; ++i) {
            trie.insert(words[i], i);
        }

        List<String> t = new ArrayList<>();
        for (String w : words) {
            t.add(w);
            dfs(t);
            t.remove(t.size() - 1);
        }
        return ans;
    }

    private void dfs(List<String> t) {
        if (t.size() == words[0].length()) {
            ans.add(new ArrayList<>(t));
            return;
        }
        int idx = t.size();
        StringBuilder pref = new StringBuilder();
        for (String x : t) {
            pref.append(x.charAt(idx));
        }
        List<Integer> indexes = trie.search(pref.toString());
        for (int i : indexes) {
            t.add(words[i]);
            dfs(t);
            t.remove(t.size() - 1);
        }
    }
}
```

#### Go

```go
type Trie struct {
	children [26]*Trie
	v        []int
}

func newTrie() *Trie {
	return &Trie{}
}
func (this *Trie) insert(word string, i int) {
	node := this
	for _, c := range word {
		c -= 'a'
		if node.children[c] == nil {
			node.children[c] = newTrie()
		}
		node = node.children[c]
		node.v = append(node.v, i)
	}
}
func (this *Trie) search(word string) []int {
	node := this
	for _, c := range word {
		c -= 'a'
		if node.children[c] == nil {
			return []int{}
		}
		node = node.children[c]
	}
	return node.v
}

func wordSquares(words []string) [][]string {
	trie := newTrie()
	for i, w := range words {
		trie.insert(w, i)
	}
	ans := [][]string{}
	var dfs func([]string)
	dfs = func(t []string) {
		if len(t) == len(words[0]) {
			cp := make([]string, len(t))
			copy(cp, t)
			ans = append(ans, cp)
			return
		}
		idx := len(t)
		pref := []byte{}
		for _, v := range t {
			pref = append(pref, v[idx])
		}
		indexes := trie.search(string(pref))
		for _, i := range indexes {
			t = append(t, words[i])
			dfs(t)
			t = t[:len(t)-1]
		}
	}
	for _, w := range words {
		dfs([]string{w})
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [426. 将二叉搜索树转化为排序的双向链表 🔒](https://leetcode.cn/problems/convert-binary-search-tree-to-sorted-doubly-linked-list){#426}

{{< tabs "426" >}}

{{% tab "python" %}}
```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
"""


class Solution:
    def treeToDoublyList(self, root: 'Optional[Node]') -> 'Optional[Node]':
        def dfs(root):
            if root is None:
                return
            nonlocal prev, head
            dfs(root.left)
            if prev:
                prev.right = root
                root.left = prev
            else:
                head = root
            prev = root
            dfs(root.right)

        if root is None:
            return None
        head = prev = None
        dfs(root)
        prev.right = head
        head.left = prev
        return head
```
{{% /tab %}}
{{% tab "java" %}}
```java
/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val,Node _left,Node _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
    private Node prev;
    private Node head;

    public Node treeToDoublyList(Node root) {
        if (root == null) {
            return null;
        }
        prev = null;
        head = null;
        dfs(root);
        prev.right = head;
        head.left = prev;
        return head;
    }

    private void dfs(Node root) {
        if (root == null) {
            return;
        }
        dfs(root.left);
        if (prev != null) {
            prev.right = root;
            root.left = prev;
        } else {
            head = root;
        }
        prev = root;
        dfs(root.right);
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
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* prev;
    Node* head;

    Node* treeToDoublyList(Node* root) {
        if (!root) return nullptr;
        prev = nullptr;
        head = nullptr;
        dfs(root);
        prev->right = head;
        head->left = prev;
        return head;
    }

    void dfs(Node* root) {
        if (!root) return;
        dfs(root->left);
        if (prev) {
            prev->right = root;
            root->left = prev;
        } else
            head = root;
        prev = root;
        dfs(root->right);
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
 *     Left *Node
 *     Right *Node
 * }
 */

func treeToDoublyList(root *Node) *Node {
	if root == nil {
		return root
	}
	var prev, head *Node

	var dfs func(root *Node)
	dfs = func(root *Node) {
		if root == nil {
			return
		}
		dfs(root.Left)
		if prev != nil {
			prev.Right = root
			root.Left = prev
		} else {
			head = root
		}
		prev = root
		dfs(root.Right)
	}
	dfs(root)
	prev.Right = head
	head.Left = prev
	return head
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * // Definition for a Node.
 * function Node(val, left, right) {
 *      this.val = val;
 *      this.left = left;
 *      this.right = right;
 *  };
 */

/**
 * @param {Node} root
 * @return {Node}
 */
var treeToDoublyList = function (root) {
    if (!root) return root;
    let prev = null;
    let head = null;

    function dfs(root) {
        if (!root) return;
        dfs(root.left);
        if (prev) {
            prev.right = root;
            root.left = prev;
        } else {
            head = root;
        }
        prev = root;
        dfs(root.right);
    }
    dfs(root);
    prev.right = head;
    head.left = prev;
    return head;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>将一个 <strong>二叉搜索树</strong> 就地转化为一个 <strong>已排序的双向循环链表</strong> 。</p>

<p>对于双向循环列表，你可以将左右孩子指针作为双向循环链表的前驱和后继指针，第一个节点的前驱是最后一个节点，最后一个节点的后继是第一个节点。</p>

<p>特别地，我们希望可以 <strong>原地</strong> 完成转换操作。当转化完成以后，树中节点的左指针需要指向前驱，树中节点的右指针需要指向后继。还需要返回链表中最小元素的指针。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>root = [4,2,5,1,3] 

<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0426.Convert%20Binary%20Search%20Tree%20to%20Sorted%20Doubly%20Linked%20List/images/bstdllreturndll.png" style="width: 400px;" />
<strong>输出：</strong>[1,2,3,4,5]

<strong>解释：</strong>下图显示了转化后的二叉搜索树，实线表示后继关系，虚线表示前驱关系。
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0426.Convert%20Binary%20Search%20Tree%20to%20Sorted%20Doubly%20Linked%20List/images/bstdllreturnbst.png" style="width: 400px;" />
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>root = [2,1,3]
<strong>输出：</strong>[1,2,3]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点的数量在范围&nbsp;<code>[0, 2000]</code>&nbsp;中</li>
	<li><code>-1000 &lt;= Node.val &lt;= 1000</code></li>
	<li>树中的所有值都是 <strong>独一无二</strong> 的</li>
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
"""
# Definition for a Node.
class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
"""


class Solution:
    def treeToDoublyList(self, root: 'Optional[Node]') -> 'Optional[Node]':
        def dfs(root):
            if root is None:
                return
            nonlocal prev, head
            dfs(root.left)
            if prev:
                prev.right = root
                root.left = prev
            else:
                head = root
            prev = root
            dfs(root.right)

        if root is None:
            return None
        head = prev = None
        dfs(root)
        prev.right = head
        head.left = prev
        return head
```

#### Java

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val,Node _left,Node _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
    private Node prev;
    private Node head;

    public Node treeToDoublyList(Node root) {
        if (root == null) {
            return null;
        }
        prev = null;
        head = null;
        dfs(root);
        prev.right = head;
        head.left = prev;
        return head;
    }

    private void dfs(Node root) {
        if (root == null) {
            return;
        }
        dfs(root.left);
        if (prev != null) {
            prev.right = root;
            root.left = prev;
        } else {
            head = root;
        }
        prev = root;
        dfs(root.right);
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
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* prev;
    Node* head;

    Node* treeToDoublyList(Node* root) {
        if (!root) return nullptr;
        prev = nullptr;
        head = nullptr;
        dfs(root);
        prev->right = head;
        head->left = prev;
        return head;
    }

    void dfs(Node* root) {
        if (!root) return;
        dfs(root->left);
        if (prev) {
            prev->right = root;
            root->left = prev;
        } else
            head = root;
        prev = root;
        dfs(root->right);
    }
};
```

#### Go

```go
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Left *Node
 *     Right *Node
 * }
 */

func treeToDoublyList(root *Node) *Node {
	if root == nil {
		return root
	}
	var prev, head *Node

	var dfs func(root *Node)
	dfs = func(root *Node) {
		if root == nil {
			return
		}
		dfs(root.Left)
		if prev != nil {
			prev.Right = root
			root.Left = prev
		} else {
			head = root
		}
		prev = root
		dfs(root.Right)
	}
	dfs(root)
	prev.Right = head
	head.Left = prev
	return head
}
```

#### JavaScript

```js
/**
 * // Definition for a Node.
 * function Node(val, left, right) {
 *      this.val = val;
 *      this.left = left;
 *      this.right = right;
 *  };
 */

/**
 * @param {Node} root
 * @return {Node}
 */
var treeToDoublyList = function (root) {
    if (!root) return root;
    let prev = null;
    let head = null;

    function dfs(root) {
        if (!root) return;
        dfs(root.left);
        if (prev) {
            prev.right = root;
            root.left = prev;
        } else {
            head = root;
        }
        prev = root;
        dfs(root.right);
    }
    dfs(root);
    prev.right = head;
    head.left = prev;
    return head;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [427. 建立四叉树](https://leetcode.cn/problems/construct-quad-tree){#427}

{{< tabs "427" >}}

{{% tab "python" %}}
```python
"""
# Definition for a QuadTree node.
class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight
"""


class Solution:
    def construct(self, grid: List[List[int]]) -> 'Node':
        def dfs(a, b, c, d):
            zero = one = 0
            for i in range(a, c + 1):
                for j in range(b, d + 1):
                    if grid[i][j] == 0:
                        zero = 1
                    else:
                        one = 1
            isLeaf = zero + one == 1
            val = isLeaf and one
            if isLeaf:
                return Node(grid[a][b], True)
            topLeft = dfs(a, b, (a + c) // 2, (b + d) // 2)
            topRight = dfs(a, (b + d) // 2 + 1, (a + c) // 2, d)
            bottomLeft = dfs((a + c) // 2 + 1, b, c, (b + d) // 2)
            bottomRight = dfs((a + c) // 2 + 1, (b + d) // 2 + 1, c, d)
            return Node(val, isLeaf, topLeft, topRight, bottomLeft, bottomRight)

        return dfs(0, 0, len(grid) - 1, len(grid[0]) - 1)
```
{{% /tab %}}
{{% tab "java" %}}
```java
/*
// Definition for a QuadTree node.
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;


    public Node() {
        this.val = false;
        this.isLeaf = false;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }

    public Node(boolean val, boolean isLeaf) {
        this.val = val;
        this.isLeaf = isLeaf;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }

    public Node(boolean val, boolean isLeaf, Node topLeft, Node topRight, Node bottomLeft, Node
bottomRight) { this.val = val; this.isLeaf = isLeaf; this.topLeft = topLeft; this.topRight =
topRight; this.bottomLeft = bottomLeft; this.bottomRight = bottomRight;
    }
};
*/

class Solution {
    public Node construct(int[][] grid) {
        return dfs(0, 0, grid.length - 1, grid[0].length - 1, grid);
    }

    private Node dfs(int a, int b, int c, int d, int[][] grid) {
        int zero = 0, one = 0;
        for (int i = a; i <= c; ++i) {
            for (int j = b; j <= d; ++j) {
                if (grid[i][j] == 0) {
                    zero = 1;
                } else {
                    one = 1;
                }
            }
        }
        boolean isLeaf = zero + one == 1;
        boolean val = isLeaf && one == 1;
        Node node = new Node(val, isLeaf);
        if (isLeaf) {
            return node;
        }
        node.topLeft = dfs(a, b, (a + c) / 2, (b + d) / 2, grid);
        node.topRight = dfs(a, (b + d) / 2 + 1, (a + c) / 2, d, grid);
        node.bottomLeft = dfs((a + c) / 2 + 1, b, c, (b + d) / 2, grid);
        node.bottomRight = dfs((a + c) / 2 + 1, (b + d) / 2 + 1, c, d, grid);
        return node;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return dfs(0, 0, grid.size() - 1, grid[0].size() - 1, grid);
    }

    Node* dfs(int a, int b, int c, int d, vector<vector<int>>& grid) {
        int zero = 0, one = 0;
        for (int i = a; i <= c; ++i) {
            for (int j = b; j <= d; ++j) {
                if (grid[i][j])
                    one = 1;
                else
                    zero = 1;
            }
        }
        bool isLeaf = zero + one == 1;
        bool val = isLeaf && one;
        Node* node = new Node(val, isLeaf);
        if (isLeaf) return node;
        node->topLeft = dfs(a, b, (a + c) / 2, (b + d) / 2, grid);
        node->topRight = dfs(a, (b + d) / 2 + 1, (a + c) / 2, d, grid);
        node->bottomLeft = dfs((a + c) / 2 + 1, b, c, (b + d) / 2, grid);
        node->bottomRight = dfs((a + c) / 2 + 1, (b + d) / 2 + 1, c, d, grid);
        return node;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for a QuadTree node.
 * type Node struct {
 *     Val bool
 *     IsLeaf bool
 *     TopLeft *Node
 *     TopRight *Node
 *     BottomLeft *Node
 *     BottomRight *Node
 * }
 */

func construct(grid [][]int) *Node {
	var dfs func(a, b, c, d int) *Node
	dfs = func(a, b, c, d int) *Node {
		zero, one := 0, 0
		for i := a; i <= c; i++ {
			for j := b; j <= d; j++ {
				if grid[i][j] == 0 {
					zero = 1
				} else {
					one = 1
				}
			}
		}
		isLeaf := zero+one == 1
		val := isLeaf && one == 1
		node := &Node{Val: val, IsLeaf: isLeaf}
		if isLeaf {
			return node
		}
		node.TopLeft = dfs(a, b, (a+c)/2, (b+d)/2)
		node.TopRight = dfs(a, (b+d)/2+1, (a+c)/2, d)
		node.BottomLeft = dfs((a+c)/2+1, b, c, (b+d)/2)
		node.BottomRight = dfs((a+c)/2+1, (b+d)/2+1, c, d)
		return node
	}
	return dfs(0, 0, len(grid)-1, len(grid[0])-1)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 <code>n * n</code> 矩阵 <code>grid</code> ，矩阵由若干 <code>0</code> 和 <code>1</code> 组成。请你用四叉树表示该矩阵 <code>grid</code> 。</p>

<p>你需要返回能表示矩阵 <code>grid</code> 的 四叉树 的根结点。</p>

<p>四叉树数据结构中，每个内部节点只有四个子节点。此外，每个节点都有两个属性：</p>

<ul>
	<li><code>val</code>：储存叶子结点所代表的区域的值。1 对应 <strong>True</strong>，0 对应 <strong>False</strong>。注意，当 <code>isLeaf</code> 为 <strong>False </strong>时，你可以把 <strong>True</strong> 或者 <strong>False</strong> 赋值给节点，两种值都会被判题机制 <strong>接受</strong> 。</li>
	<li><code>isLeaf</code>: 当这个节点是一个叶子结点时为 <strong>True</strong>，如果它有 4 个子节点则为 <strong>False</strong> 。</li>
</ul>

<pre>
class Node {
    public boolean val;
&nbsp; &nbsp; public boolean isLeaf;
&nbsp; &nbsp; public Node topLeft;
&nbsp; &nbsp; public Node topRight;
&nbsp; &nbsp; public Node bottomLeft;
&nbsp; &nbsp; public Node bottomRight;
}</pre>

<p>我们可以按以下步骤为二维区域构建四叉树：</p>

<ol>
	<li>如果当前网格的值相同（即，全为 <code>0</code> 或者全为 <code>1</code>），将 <code>isLeaf</code> 设为 True ，将 <code>val</code> 设为网格相应的值，并将四个子节点都设为 Null 然后停止。</li>
	<li>如果当前网格的值不同，将 <code>isLeaf</code> 设为 False， 将 <code>val</code> 设为任意值，然后如下图所示，将当前网格划分为四个子网格。</li>
	<li>使用适当的子网格递归每个子节点。</li>
</ol>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0427.Construct%20Quad%20Tree/images/new_top.png" style="height: 181px; width: 777px;" /></p>

<p>如果你想了解更多关于四叉树的内容，可以参考 <a href="https://baike.baidu.com/item/%E5%9B%9B%E5%8F%89%E6%A0%91">百科</a> 。</p>

<p><strong>四叉树格式：</strong></p>

<p>你不需要阅读本节来解决这个问题。只有当你想了解输出格式时才会这样做。输出为使用层序遍历后四叉树的序列化形式，其中 <code>null</code> 表示路径终止符，其下面不存在节点。</p>

<p>它与二叉树的序列化非常相似。唯一的区别是节点以列表形式表示 <code>[isLeaf, val]</code> 。</p>

<p>如果 <code>isLeaf</code> 或者 <code>val</code> 的值为 True ，则表示它在列表&nbsp;<code>[isLeaf, val]</code> 中的值为 <strong>1</strong> ；如果 <code>isLeaf</code> 或者 <code>val</code> 的值为 False ，则表示值为 <strong>0 </strong>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0427.Construct%20Quad%20Tree/images/grid1.png" style="height: 99px; width: 777px;" /></p>

<pre>
<strong>输入：</strong>grid = [[0,1],[1,0]]
<strong>输出：</strong>[[0,1],[1,0],[1,1],[1,1],[1,0]]
<strong>解释：</strong>此示例的解释如下：
请注意，在下面四叉树的图示中，0 表示 false，1 表示 True 。
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0427.Construct%20Quad%20Tree/images/e1tree.png" style="height: 186px; width: 777px;" />
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0427.Construct%20Quad%20Tree/images/e2mat.png" style="height: 343px; width: 777px;" /></p>

<pre>
<strong>输入：</strong>grid = [[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0]]
<strong>输出：</strong>[[0,1],[1,1],[0,1],[1,1],[1,0],null,null,null,null,[1,0],[1,0],[1,1],[1,1]]
<strong>解释：</strong>网格中的所有值都不相同。我们将网格划分为四个子网格。
topLeft，bottomLeft 和 bottomRight 均具有相同的值。
topRight 具有不同的值，因此我们将其再分为 4 个子网格，这样每个子网格都具有相同的值。
解释如下图所示：
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0427.Construct%20Quad%20Tree/images/e2tree.png" style="height: 328px; width: 777px;" />
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>n == grid.length == grid[i].length</code></li>
	<li><code>n == 2<sup>x</sup></code> 其中 <code>0 &lt;= x &lt;= 6</code></li>
</ol>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

DFS 递归遍历 grid，先判断 grid 是否为叶子节点，是则返回叶子节点相关信息；否则递归 grid 4 个子节点。

<!-- tabs:start -->

#### Python3

```python
"""
# Definition for a QuadTree node.
class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight
"""


class Solution:
    def construct(self, grid: List[List[int]]) -> 'Node':
        def dfs(a, b, c, d):
            zero = one = 0
            for i in range(a, c + 1):
                for j in range(b, d + 1):
                    if grid[i][j] == 0:
                        zero = 1
                    else:
                        one = 1
            isLeaf = zero + one == 1
            val = isLeaf and one
            if isLeaf:
                return Node(grid[a][b], True)
            topLeft = dfs(a, b, (a + c) // 2, (b + d) // 2)
            topRight = dfs(a, (b + d) // 2 + 1, (a + c) // 2, d)
            bottomLeft = dfs((a + c) // 2 + 1, b, c, (b + d) // 2)
            bottomRight = dfs((a + c) // 2 + 1, (b + d) // 2 + 1, c, d)
            return Node(val, isLeaf, topLeft, topRight, bottomLeft, bottomRight)

        return dfs(0, 0, len(grid) - 1, len(grid[0]) - 1)
```

#### Java

```java
/*
// Definition for a QuadTree node.
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;


    public Node() {
        this.val = false;
        this.isLeaf = false;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }

    public Node(boolean val, boolean isLeaf) {
        this.val = val;
        this.isLeaf = isLeaf;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }

    public Node(boolean val, boolean isLeaf, Node topLeft, Node topRight, Node bottomLeft, Node
bottomRight) { this.val = val; this.isLeaf = isLeaf; this.topLeft = topLeft; this.topRight =
topRight; this.bottomLeft = bottomLeft; this.bottomRight = bottomRight;
    }
};
*/

class Solution {
    public Node construct(int[][] grid) {
        return dfs(0, 0, grid.length - 1, grid[0].length - 1, grid);
    }

    private Node dfs(int a, int b, int c, int d, int[][] grid) {
        int zero = 0, one = 0;
        for (int i = a; i <= c; ++i) {
            for (int j = b; j <= d; ++j) {
                if (grid[i][j] == 0) {
                    zero = 1;
                } else {
                    one = 1;
                }
            }
        }
        boolean isLeaf = zero + one == 1;
        boolean val = isLeaf && one == 1;
        Node node = new Node(val, isLeaf);
        if (isLeaf) {
            return node;
        }
        node.topLeft = dfs(a, b, (a + c) / 2, (b + d) / 2, grid);
        node.topRight = dfs(a, (b + d) / 2 + 1, (a + c) / 2, d, grid);
        node.bottomLeft = dfs((a + c) / 2 + 1, b, c, (b + d) / 2, grid);
        node.bottomRight = dfs((a + c) / 2 + 1, (b + d) / 2 + 1, c, d, grid);
        return node;
    }
}
```

#### C++

```cpp
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return dfs(0, 0, grid.size() - 1, grid[0].size() - 1, grid);
    }

    Node* dfs(int a, int b, int c, int d, vector<vector<int>>& grid) {
        int zero = 0, one = 0;
        for (int i = a; i <= c; ++i) {
            for (int j = b; j <= d; ++j) {
                if (grid[i][j])
                    one = 1;
                else
                    zero = 1;
            }
        }
        bool isLeaf = zero + one == 1;
        bool val = isLeaf && one;
        Node* node = new Node(val, isLeaf);
        if (isLeaf) return node;
        node->topLeft = dfs(a, b, (a + c) / 2, (b + d) / 2, grid);
        node->topRight = dfs(a, (b + d) / 2 + 1, (a + c) / 2, d, grid);
        node->bottomLeft = dfs((a + c) / 2 + 1, b, c, (b + d) / 2, grid);
        node->bottomRight = dfs((a + c) / 2 + 1, (b + d) / 2 + 1, c, d, grid);
        return node;
    }
};
```

#### Go

```go
/**
 * Definition for a QuadTree node.
 * type Node struct {
 *     Val bool
 *     IsLeaf bool
 *     TopLeft *Node
 *     TopRight *Node
 *     BottomLeft *Node
 *     BottomRight *Node
 * }
 */

func construct(grid [][]int) *Node {
	var dfs func(a, b, c, d int) *Node
	dfs = func(a, b, c, d int) *Node {
		zero, one := 0, 0
		for i := a; i <= c; i++ {
			for j := b; j <= d; j++ {
				if grid[i][j] == 0 {
					zero = 1
				} else {
					one = 1
				}
			}
		}
		isLeaf := zero+one == 1
		val := isLeaf && one == 1
		node := &Node{Val: val, IsLeaf: isLeaf}
		if isLeaf {
			return node
		}
		node.TopLeft = dfs(a, b, (a+c)/2, (b+d)/2)
		node.TopRight = dfs(a, (b+d)/2+1, (a+c)/2, d)
		node.BottomLeft = dfs((a+c)/2+1, b, c, (b+d)/2)
		node.BottomRight = dfs((a+c)/2+1, (b+d)/2+1, c, d)
		return node
	}
	return dfs(0, 0, len(grid)-1, len(grid[0])-1)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [428. 序列化和反序列化 N 叉树 🔒](https://leetcode.cn/problems/serialize-and-deserialize-n-ary-tree){#428}

{{< tabs "428" >}}

{{% tab "python" %}}
```python

```
{{% /tab %}}
{{% tab "java" %}}
```java

```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp

```
{{% /tab %}}
{{% tab "go" %}}
```go

```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>序列化是指将一个数据结构转化为位序列的过程，因此可以将其存储在文件中或内存缓冲区中，以便稍后在相同或不同的计算机环境中恢复结构。</p>

<p>设计一个序列化和反序列化 N 叉树的算法。一个 N 叉树是指每个节点都有不超过 N 个孩子节点的有根树。序列化 / 反序列化算法的算法实现没有限制。你只需要保证 N 叉树可以被序列化为一个字符串并且该字符串可以被反序列化成原树结构即可。</p>

<p>例如，你需要序列化下面的 <code>3-叉</code> 树。</p>

<p>&nbsp;</p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0428.Serialize%20and%20Deserialize%20N-ary%20Tree/images/1727093143-BPVnoI-image.png" style="height: 321px; width: 500px;" /></p>

<p>&nbsp;</p>

<p>为&nbsp;<code>[1 [3[5 6] 2 4]]</code>。你不需要以这种形式完成，你可以自己创造和实现不同的方法。</p>

<p>或者，您可以遵循 LeetCode 的层序遍历序列化格式，其中每组孩子节点由空值分隔。</p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0428.Serialize%20and%20Deserialize%20N-ary%20Tree/images/1727093169-WGFOps-image.png" style="height: 454px; width: 500px;" /></p>

<p>例如，上面的树可以序列化为 <code>[1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]</code></p>

<p>你不一定要遵循以上建议的格式，有很多不同的格式，所以请发挥创造力，想出不同的方法来完成本题。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>

<pre>
<strong>输入:</strong> root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
<strong>输出:</strong> [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
</pre>

<p><strong class="example">示例 2:</strong></p>

<pre>
<strong>输入:</strong> root = [1,null,3,2,4,null,5,6]
<strong>输出:</strong> [1,null,3,2,4,null,5,6]
</pre>

<p><strong class="example">示例 3:</strong></p>

<pre>
<strong>输入:</strong> root = []
<strong>输出:</strong> []
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数目的范围是 <code>[0,&nbsp;10<sup>4</sup>]</code>.</li>
	<li><code>0 &lt;= Node.val &lt;= 10<sup>4</sup></code></li>
	<li>N 叉树的高度小于等于 <code>1000</code></li>
	<li>不要使用类成员 / 全局变量 / 静态变量来存储状态。你的序列化和反序列化算法应是无状态的。</li>
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

```

#### Java

```java

```

#### C++

```cpp

```

#### Go

```go

```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [429. N 叉树的层序遍历](https://leetcode.cn/problems/n-ary-tree-level-order-traversal){#429}

{{< tabs "429" >}}

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

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个 N 叉树，返回其节点值的<em>层序遍历</em>。（即从左到右，逐层遍历）。</p>

<p>树的序列化输入是用层序遍历，每组子节点都由 null 值分隔（参见示例）。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0429.N-ary%20Tree%20Level%20Order%20Traversal/images/narytreeexample.png" style="width: 100%; max-width: 300px;" /></p>

<pre>
<strong>输入：</strong>root = [1,null,3,2,4,null,5,6]
<strong>输出：</strong>[[1],[3,2,4],[5,6]]
</pre>

<p><strong class="example">示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0429.N-ary%20Tree%20Level%20Order%20Traversal/images/sample_4_964.png" style="width: 296px; height: 241px;" /></p>

<pre>
<strong>输入：</strong>root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
<strong>输出：</strong>[[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树的高度不会超过&nbsp;<code>1000</code></li>
	<li>树的节点总数在 <code>[0,&nbsp;10<sup>4</sup>]</code> 之间</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS

我们首先判断根节点是否为空，若为空则直接返回空列表。

否则，我们创建一个队列 $q$，初始时将根节点加入队列。

当队列不为空时，我们循环以下操作：

1. 创建一个空列表 $t$，用于存放当前层的节点值。
2. 对于队列中的每个节点，将其值加入 $t$ 中，并将其子节点加入队列。
3. 将 $t$ 加入结果列表 $ans$。

最后返回结果列表 $ans$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为 N 叉树的节点数。

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
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        ans = []
        if root is None:
            return ans
        q = deque([root])
        while q:
            t = []
            for _ in range(len(q)):
                root = q.popleft()
                t.append(root.val)
                q.extend(root.children)
            ans.append(t)
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
    public List<List<Integer>> levelOrder(Node root) {
        List<List<Integer>> ans = new ArrayList<>();
        if (root == null) {
            return ans;
        }
        Deque<Node> q = new ArrayDeque<>();
        q.offer(root);
        while (!q.isEmpty()) {
            List<Integer> t = new ArrayList<>();
            for (int n = q.size(); n > 0; --n) {
                root = q.poll();
                t.add(root.val);
                q.addAll(root.children);
            }
            ans.add(t);
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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }
        queue<Node*> q{{root}};
        while (!q.empty()) {
            vector<int> t;
            for (int n = q.size(); n; --n) {
                root = q.front();
                q.pop();
                t.push_back(root->val);
                for (auto& child : root->children) {
                    q.push(child);
                }
            }
            ans.push_back(t);
        }
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

func levelOrder(root *Node) (ans [][]int) {
	if root == nil {
		return
	}
	q := []*Node{root}
	for len(q) > 0 {
		var t []int
		for n := len(q); n > 0; n-- {
			root = q[0]
			q = q[1:]
			t = append(t, root.Val)
			for _, child := range root.Children {
				q = append(q, child)
			}
		}
		ans = append(ans, t)
	}
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

function levelOrder(root: Node | null): number[][] {
    const ans: number[][] = [];
    if (!root) {
        return ans;
    }
    const q: Node[] = [root];
    while (q.length) {
        const qq: Node[] = [];
        const t: number[] = [];
        for (const { val, children } of q) {
            qq.push(...children);
            t.push(val);
        }
        ans.push(t);
        q.splice(0, q.length, ...qq);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：DFS

我们可以使用深度优先搜索的方法，遍历整棵树。

我们定义一个辅助函数 $dfs(root, i)$，其中 $root$ 表示当前节点，而 $i$ 表示当前层数。

在 $dfs$ 函数中，我们首先判断 $root$ 是否为空，若为空则直接返回。

否则，我们判断 $ans$ 的长度是否小于等于 $i$，若是则说明当前层还没有加入到 $ans$ 中，我们需要先加入一个空列表。然后将 $root$ 的值加入 $ans[i]$ 中。

接着，我们遍历 $root$ 的所有子节点，对于每个子节点，我们调用 $dfs(child, i + 1)$。

在主函数中，我们调用 $dfs(root, 0)$，并返回 $ans$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为 N 叉树的节点数。

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

#### Go

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

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
