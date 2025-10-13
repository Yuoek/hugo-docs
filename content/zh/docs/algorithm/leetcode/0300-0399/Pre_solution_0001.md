---
title: "0300_最长递增子序列"
date: 2025-10-08T18:35:54+08:00
weight: 1
tags: [二分查找, 分治, 前缀和, 动态规划, 哈希表, 回溯, 字符串, 并查集, 广度优先搜索, 数组, 树状数组, 深度优先搜索, 矩阵, 线段树, 设计]
---

{{< markmap >}}
### [0300_最长递增子序列](#300)
#### [数组](#300)
#### [二分查找](#300)
#### [动态规划](#300)
### [0301_删除无效的括号](#301)
#### [广度优先搜索](#301)
#### [字符串](#301)
#### [回溯](#301)
### [0302_包含全部黑色像素的最小矩形 🔒](#302)
#### [深度优先搜索](#302)
#### [广度优先搜索](#302)
#### [数组](#302)
#### [二分查找](#302)
#### [矩阵](#302)
### [0303_区域和检索 - 数组不可变](#303)
#### [设计](#303)
#### [数组](#303)
#### [前缀和](#303)
### [0304_二维区域和检索 - 矩阵不可变](#304)
#### [设计](#304)
#### [数组](#304)
#### [矩阵](#304)
#### [前缀和](#304)
### [0305_岛屿数量 II 🔒](#305)
#### [并查集](#305)
#### [数组](#305)
#### [哈希表](#305)
### [0306_累加数](#306)
#### [字符串](#306)
#### [回溯](#306)
### [0307_区域和检索 - 数组可修改](#307)
#### [设计](#307)
#### [树状数组](#307)
#### [线段树](#307)
#### [数组](#307)
#### [分治](#307)
### [0308_二维区域和检索 - 矩阵可修改 🔒](#308)
#### [设计](#308)
#### [树状数组](#308)
#### [线段树](#308)
#### [数组](#308)
#### [矩阵](#308)
### [0309_买卖股票的最佳时机含冷冻期](#309)
#### [数组](#309)
#### [动态规划](#309)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0300_最长递增子序列
___
#### 数组
___
#### 二分查找
___
#### 动态规划
---
### 0301_删除无效的括号
___
#### 广度优先搜索
___
#### 字符串
___
#### 回溯
---
### 0302_包含全部黑色像素的最小矩形 🔒
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 数组
___
#### 二分查找
___
#### 矩阵
---
### 0303_区域和检索 - 数组不可变
___
#### 设计
___
#### 数组
___
#### 前缀和
---
### 0304_二维区域和检索 - 矩阵不可变
___
#### 设计
___
#### 数组
___
#### 矩阵
___
#### 前缀和
---
### 0305_岛屿数量 II 🔒
___
#### 并查集
___
#### 数组
___
#### 哈希表
---
### 0306_累加数
___
#### 字符串
___
#### 回溯
---
### 0307_区域和检索 - 数组可修改
___
#### 设计
___
#### 树状数组
___
#### 线段树
___
#### 数组
___
#### 分治
---
### 0308_二维区域和检索 - 矩阵可修改 🔒
___
#### 设计
___
#### 树状数组
___
#### 线段树
___
#### 数组
___
#### 矩阵
---
### 0309_买卖股票的最佳时机含冷冻期
___
#### 数组
___
#### 动态规划
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 分治 | 前缀和 |
| 动态规划 | 哈希表 | 回溯 |
| 字符串 | 并查集 | 广度优先搜索 |
| 数组 | 树状数组 | 深度优先搜索 |
| 矩阵 | 线段树 | 设计 |

# [300. 最长递增子序列](https://leetcode.cn/problems/longest-increasing-subsequence){#300}

{{< tabs "300" >}}

{{% tab "python" %}}
```python
class BinaryIndexedTree:
    def __init__(self, n: int):
        self.n = n
        self.c = [0] * (n + 1)

    def update(self, x: int, v: int):
        while x <= self.n:
            self.c[x] = max(self.c[x], v)
            x += x & -x

    def query(self, x: int) -> int:
        mx = 0
        while x:
            mx = max(mx, self.c[x])
            x -= x & -x
        return mx


class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        s = sorted(set(nums))
        m = len(s)
        tree = BinaryIndexedTree(m)
        for x in nums:
            x = bisect_left(s, x) + 1
            t = tree.query(x - 1) + 1
            tree.update(x, t)
        return tree.query(m)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int lengthOfLIS(int[] nums) {
        int[] s = nums.clone();
        Arrays.sort(s);
        int m = 0;
        int n = s.length;
        for (int i = 0; i < n; ++i) {
            if (i == 0 || s[i] != s[i - 1]) {
                s[m++] = s[i];
            }
        }
        BinaryIndexedTree tree = new BinaryIndexedTree(m);
        for (int x : nums) {
            x = search(s, x, m);
            int t = tree.query(x - 1) + 1;
            tree.update(x, t);
        }
        return tree.query(m);
    }

    private int search(int[] nums, int x, int r) {
        int l = 0;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l + 1;
    }
}

class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        c = new int[n + 1];
    }

    public void update(int x, int v) {
        while (x <= n) {
            c[x] = Math.max(c[x], v);
            x += x & -x;
        }
    }

    public int query(int x) {
        int mx = 0;
        while (x > 0) {
            mx = Math.max(mx, c[x]);
            x -= x & -x;
        }
        return mx;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class BinaryIndexedTree {
public:
    BinaryIndexedTree(int _n)
        : n(_n)
        , c(_n + 1) {}

    void update(int x, int v) {
        while (x <= n) {
            c[x] = max(c[x], v);
            x += x & -x;
        }
    }

    int query(int x) {
        int mx = 0;
        while (x) {
            mx = max(mx, c[x]);
            x -= x & -x;
        }
        return mx;
    }

private:
    int n;
    vector<int> c;
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> s = nums;
        sort(s.begin(), s.end());
        s.erase(unique(s.begin(), s.end()), s.end());
        BinaryIndexedTree tree(s.size());
        for (int x : nums) {
            x = lower_bound(s.begin(), s.end(), x) - s.begin() + 1;
            int t = tree.query(x - 1) + 1;
            tree.update(x, t);
        }
        return tree.query(s.size());
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type BinaryIndexedTree struct {
	n int
	c []int
}

func newBinaryIndexedTree(n int) *BinaryIndexedTree {
	return &BinaryIndexedTree{n, make([]int, n+1)}
}

func (bit *BinaryIndexedTree) update(x, v int) {
	for x <= bit.n {
		bit.c[x] = max(bit.c[x], v)
		x += x & -x
	}
}

func (bit *BinaryIndexedTree) query(x int) int {
	mx := 0
	for x > 0 {
		mx = max(mx, bit.c[x])
		x -= x & -x
	}
	return mx
}

func lengthOfLIS(nums []int) int {
	n := len(nums)
	s := make([]int, n)
	copy(s, nums)
	sort.Ints(s)
	m := 0
	for i, x := range s {
		if i == 0 || x != s[i-1] {
			s[m] = x
			m++
		}
	}
	tree := newBinaryIndexedTree(m)
	for _, x := range nums {
		x = sort.SearchInts(s[:m], x) + 1
		t := tree.query(x-1) + 1
		tree.update(x, t)
	}
	return tree.query(m)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class BinaryIndexedTree {
    private n: number;
    private c: number[];

    constructor(n: number) {
        this.n = n;
        this.c = new Array(n + 1).fill(0);
    }

    update(x: number, v: number) {
        while (x <= this.n) {
            this.c[x] = Math.max(this.c[x], v);
            x += x & -x;
        }
    }

    query(x: number): number {
        let mx = 0;
        while (x) {
            mx = Math.max(mx, this.c[x]);
            x -= x & -x;
        }
        return mx;
    }
}

function lengthOfLIS(nums: number[]): number {
    const s = [...new Set(nums)].sort((a, b) => a - b);
    const m = s.length;
    const tree = new BinaryIndexedTree(m);
    for (let x of nums) {
        x = search(s, x);
        const t = tree.query(x - 1) + 1;
        tree.update(x, t);
    }
    return tree.query(m);
}

function search(nums: number[], x: number): number {
    let l = 0,
        r = nums.length - 1;
    while (l < r) {
        const mid = (l + r) >> 1;
        if (nums[mid] >= x) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l + 1;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn length_of_lis(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut f = vec![1; n];
        for i in 1..n {
            for j in 0..i {
                if nums[j] < nums[i] {
                    f[i] = f[i].max(f[j] + 1);
                }
            }
        }
        *f.iter().max().unwrap()
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code> ，找到其中最长严格递增子序列的长度。</p>

<p><strong>子序列&nbsp;</strong>是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，<code>[3,6,2,7]</code> 是数组 <code>[0,3,1,6,2,2,7]</code> 的<span data-keyword="subsequence-array">子序列</span>。</p>
&nbsp;

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [10,9,2,5,3,7,101,18]
<strong>输出：</strong>4
<strong>解释：</strong>最长递增子序列是 [2,3,7,101]，因此长度为 4 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,1,0,3,2,3]
<strong>输出：</strong>4
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [7,7,7,7,7,7,7]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2500</code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>

<p>&nbsp;</p>

<p><b>进阶：</b></p>

<ul>
	<li>你能将算法的时间复杂度降低到&nbsp;<code>O(n log(n))</code> 吗?</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i]$ 表示以 $nums[i]$ 结尾的最长递增子序列的长度，初始时 $f[i] = 1$，答案为 $f[i]$ 的最大值。

对于 $f[i]$，我们需要枚举 $0 \le j \lt i$，如果 $nums[j] \lt nums[i]$，则 $f[i] = \max(f[i], f[j] + 1)$。

最后的答案即为 $f[i]$ 的最大值。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 为数组长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        f = [1] * n
        for i in range(1, n):
            for j in range(i):
                if nums[j] < nums[i]:
                    f[i] = max(f[i], f[j] + 1)
        return max(f)
```

#### Java

```java
class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int[] f = new int[n];
        Arrays.fill(f, 1);
        int ans = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    f[i] = Math.max(f[i], f[j] + 1);
                }
            }
            ans = Math.max(ans, f[i]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    f[i] = max(f[i], f[j] + 1);
                }
            }
        }
        return *max_element(f.begin(), f.end());
    }
};
```

#### Go

```go
func lengthOfLIS(nums []int) int {
	n := len(nums)
	f := make([]int, n)
	for i := range f {
		f[i] = 1
	}
	ans := 1
	for i := 1; i < n; i++ {
		for j := 0; j < i; j++ {
			if nums[j] < nums[i] {
				f[i] = max(f[i], f[j]+1)
				ans = max(ans, f[i])
			}
		}
	}
	return ans
}
```

#### TypeScript

```ts
function lengthOfLIS(nums: number[]): number {
    const n = nums.length;
    const f: number[] = new Array(n).fill(1);
    for (let i = 1; i < n; ++i) {
        for (let j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) {
                f[i] = Math.max(f[i], f[j] + 1);
            }
        }
    }
    return Math.max(...f);
}
```

#### Rust

```rust
impl Solution {
    pub fn length_of_lis(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut f = vec![1; n];
        for i in 1..n {
            for j in 0..i {
                if nums[j] < nums[i] {
                    f[i] = f[i].max(f[j] + 1);
                }
            }
        }
        *f.iter().max().unwrap()
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：离散化 + 树状数组

我们将数组中的元素离散化，然后使用树状数组维护不大于某个元素的最长递增子序列的长度。

遍历数组中的每个元素 $x$，将其离散化，然后在树状数组中查找不大于 $x-1$ 的最长递增子序列的长度 $t$，则 $x$ 的最长递增子序列的长度为 $t+1$，更新答案，并且更新树状数组中 $x$ 的最长递增子序列的长度。

遍历完数组中的所有元素，即可得到答案。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组长度。

<!-- tabs:start -->

#### Python3

```python
class BinaryIndexedTree:
    def __init__(self, n: int):
        self.n = n
        self.c = [0] * (n + 1)

    def update(self, x: int, v: int):
        while x <= self.n:
            self.c[x] = max(self.c[x], v)
            x += x & -x

    def query(self, x: int) -> int:
        mx = 0
        while x:
            mx = max(mx, self.c[x])
            x -= x & -x
        return mx


class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        s = sorted(set(nums))
        m = len(s)
        tree = BinaryIndexedTree(m)
        for x in nums:
            x = bisect_left(s, x) + 1
            t = tree.query(x - 1) + 1
            tree.update(x, t)
        return tree.query(m)
```

#### Java

```java
class Solution {
    public int lengthOfLIS(int[] nums) {
        int[] s = nums.clone();
        Arrays.sort(s);
        int m = 0;
        int n = s.length;
        for (int i = 0; i < n; ++i) {
            if (i == 0 || s[i] != s[i - 1]) {
                s[m++] = s[i];
            }
        }
        BinaryIndexedTree tree = new BinaryIndexedTree(m);
        for (int x : nums) {
            x = search(s, x, m);
            int t = tree.query(x - 1) + 1;
            tree.update(x, t);
        }
        return tree.query(m);
    }

    private int search(int[] nums, int x, int r) {
        int l = 0;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l + 1;
    }
}

class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        c = new int[n + 1];
    }

    public void update(int x, int v) {
        while (x <= n) {
            c[x] = Math.max(c[x], v);
            x += x & -x;
        }
    }

    public int query(int x) {
        int mx = 0;
        while (x > 0) {
            mx = Math.max(mx, c[x]);
            x -= x & -x;
        }
        return mx;
    }
}
```

#### C++

```cpp
class BinaryIndexedTree {
public:
    BinaryIndexedTree(int _n)
        : n(_n)
        , c(_n + 1) {}

    void update(int x, int v) {
        while (x <= n) {
            c[x] = max(c[x], v);
            x += x & -x;
        }
    }

    int query(int x) {
        int mx = 0;
        while (x) {
            mx = max(mx, c[x]);
            x -= x & -x;
        }
        return mx;
    }

private:
    int n;
    vector<int> c;
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> s = nums;
        sort(s.begin(), s.end());
        s.erase(unique(s.begin(), s.end()), s.end());
        BinaryIndexedTree tree(s.size());
        for (int x : nums) {
            x = lower_bound(s.begin(), s.end(), x) - s.begin() + 1;
            int t = tree.query(x - 1) + 1;
            tree.update(x, t);
        }
        return tree.query(s.size());
    }
};
```

#### Go

```go
type BinaryIndexedTree struct {
	n int
	c []int
}

func newBinaryIndexedTree(n int) *BinaryIndexedTree {
	return &BinaryIndexedTree{n, make([]int, n+1)}
}

func (bit *BinaryIndexedTree) update(x, v int) {
	for x <= bit.n {
		bit.c[x] = max(bit.c[x], v)
		x += x & -x
	}
}

func (bit *BinaryIndexedTree) query(x int) int {
	mx := 0
	for x > 0 {
		mx = max(mx, bit.c[x])
		x -= x & -x
	}
	return mx
}

func lengthOfLIS(nums []int) int {
	n := len(nums)
	s := make([]int, n)
	copy(s, nums)
	sort.Ints(s)
	m := 0
	for i, x := range s {
		if i == 0 || x != s[i-1] {
			s[m] = x
			m++
		}
	}
	tree := newBinaryIndexedTree(m)
	for _, x := range nums {
		x = sort.SearchInts(s[:m], x) + 1
		t := tree.query(x-1) + 1
		tree.update(x, t)
	}
	return tree.query(m)
}
```

#### TypeScript

```ts
class BinaryIndexedTree {
    private n: number;
    private c: number[];

    constructor(n: number) {
        this.n = n;
        this.c = new Array(n + 1).fill(0);
    }

    update(x: number, v: number) {
        while (x <= this.n) {
            this.c[x] = Math.max(this.c[x], v);
            x += x & -x;
        }
    }

    query(x: number): number {
        let mx = 0;
        while (x) {
            mx = Math.max(mx, this.c[x]);
            x -= x & -x;
        }
        return mx;
    }
}

function lengthOfLIS(nums: number[]): number {
    const s = [...new Set(nums)].sort((a, b) => a - b);
    const m = s.length;
    const tree = new BinaryIndexedTree(m);
    for (let x of nums) {
        x = search(s, x);
        const t = tree.query(x - 1) + 1;
        tree.update(x, t);
    }
    return tree.query(m);
}

function search(nums: number[], x: number): number {
    let l = 0,
        r = nums.length - 1;
    while (l < r) {
        const mid = (l + r) >> 1;
        if (nums[mid] >= x) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l + 1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [301. 删除无效的括号](https://leetcode.cn/problems/remove-invalid-parentheses){#301}

{{< tabs "301" >}}

{{% tab "python" %}}
```python
class Solution:
    def removeInvalidParentheses(self, s: str) -> List[str]:
        def dfs(i, l, r, lcnt, rcnt, t):
            if i == n:
                if l == 0 and r == 0:
                    ans.add(t)
                return
            if n - i < l + r or lcnt < rcnt:
                return
            if s[i] == '(' and l:
                dfs(i + 1, l - 1, r, lcnt, rcnt, t)
            elif s[i] == ')' and r:
                dfs(i + 1, l, r - 1, lcnt, rcnt, t)
            dfs(i + 1, l, r, lcnt + (s[i] == '('), rcnt + (s[i] == ')'), t + s[i])

        l = r = 0
        for c in s:
            if c == '(':
                l += 1
            elif c == ')':
                if l:
                    l -= 1
                else:
                    r += 1
        ans = set()
        n = len(s)
        dfs(0, l, r, 0, 0, '')
        return list(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private String s;
    private int n;
    private Set<String> ans = new HashSet<>();

    public List<String> removeInvalidParentheses(String s) {
        this.s = s;
        this.n = s.length();
        int l = 0, r = 0;
        for (char c : s.toCharArray()) {
            if (c == '(') {
                ++l;
            } else if (c == ')') {
                if (l > 0) {
                    --l;
                } else {
                    ++r;
                }
            }
        }
        dfs(0, l, r, 0, 0, "");
        return new ArrayList<>(ans);
    }

    private void dfs(int i, int l, int r, int lcnt, int rcnt, String t) {
        if (i == n) {
            if (l == 0 && r == 0) {
                ans.add(t);
            }
            return;
        }
        if (n - i < l + r || lcnt < rcnt) {
            return;
        }
        char c = s.charAt(i);
        if (c == '(' && l > 0) {
            dfs(i + 1, l - 1, r, lcnt, rcnt, t);
        }
        if (c == ')' && r > 0) {
            dfs(i + 1, l, r - 1, lcnt, rcnt, t);
        }
        int x = c == '(' ? 1 : 0;
        int y = c == ')' ? 1 : 0;
        dfs(i + 1, l, r, lcnt + x, rcnt + y, t + c);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> ans;
        int l = 0, r = 0, n = s.size();
        for (char& c : s) {
            if (c == '(') {
                ++l;
            } else if (c == ')') {
                if (l) {
                    --l;
                } else {
                    ++r;
                }
            }
        }
        function<void(int, int, int, int, int, string)> dfs;
        dfs = [&](int i, int l, int r, int lcnt, int rcnt, string t) {
            if (i == n) {
                if (l == 0 && r == 0) {
                    ans.insert(t);
                }
                return;
            }
            if (n - i < l + r || lcnt < rcnt) {
                return;
            }
            if (s[i] == '(' && l) {
                dfs(i + 1, l - 1, r, lcnt, rcnt, t);
            }
            if (s[i] == ')' && r) {
                dfs(i + 1, l, r - 1, lcnt, rcnt, t);
            }
            int x = s[i] == '(' ? 1 : 0;
            int y = s[i] == ')' ? 1 : 0;
            dfs(i + 1, l, r, lcnt + x, rcnt + y, t + s[i]);
        };

        dfs(0, l, r, 0, 0, "");
        return vector<string>(ans.begin(), ans.end());
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func removeInvalidParentheses(s string) []string {
	vis := map[string]bool{}
	l, r, n := 0, 0, len(s)
	for _, c := range s {
		if c == '(' {
			l++
		} else if c == ')' {
			if l > 0 {
				l--
			} else {
				r++
			}
		}
	}
	var dfs func(i, l, r, lcnt, rcnt int, t string)
	dfs = func(i, l, r, lcnt, rcnt int, t string) {
		if i == n {
			if l == 0 && r == 0 {
				vis[t] = true
			}
			return
		}
		if n-i < l+r || lcnt < rcnt {
			return
		}
		if s[i] == '(' && l > 0 {
			dfs(i+1, l-1, r, lcnt, rcnt, t)
		}
		if s[i] == ')' && r > 0 {
			dfs(i+1, l, r-1, lcnt, rcnt, t)
		}
		x, y := 0, 0
		if s[i] == '(' {
			x = 1
		} else if s[i] == ')' {
			y = 1
		}
		dfs(i+1, l, r, lcnt+x, rcnt+y, t+string(s[i]))
	}
	dfs(0, l, r, 0, 0, "")
	ans := make([]string, 0, len(vis))
	for v := range vis {
		ans = append(ans, v)
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

<p>给你一个由若干括号和字母组成的字符串 <code>s</code> ，删除最小数量的无效括号，使得输入的字符串有效。</p>

<p>返回所有可能的结果。答案可以按 <strong>任意顺序</strong> 返回。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "()())()"
<strong>输出：</strong>["(())()","()()()"]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "(a)())()"
<strong>输出：</strong>["(a())()","(a)()()"]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = ")("
<strong>输出：</strong>[""]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= s.length <= 25</code></li>
	<li><code>s</code> 由小写英文字母以及括号 <code>'('</code> 和 <code>')'</code> 组成</li>
	<li><code>s</code> 中至多含 <code>20</code> 个括号</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS + 剪枝

我们首先处理得到字符串 $s$ 待删除的左、右括号的最小数量，分别记为 $l$ 和 $r$。

然后我们设计一个递归函数 `dfs(i, l, r, lcnt, rcnt, t)`，其中：

-   `i` 表示当前处理到字符串 $s$ 的第 $i$ 个字符；
-   `l` 和 `r` 分别表示剩余待删除的左、右括号的数量；
-   `t` 表示当前得到的字符串；
-   `lcnt` 和 `rcnt` 分别表示当前得到的字符串中左、右括号的数量。

递归函数的逻辑如下：

-   如果 `i` 等于字符串 $s$ 的长度，且 `l` 和 `r` 都等于 $0$，则将 `t` 加入答案数组中；
-   如果剩余的待处理字符数 $n-i$ 小于剩余待删除的左右括号数量 $l+r$，或者当前得到的字符串中的左括号数量小于右括号数量，直接返回；
-   如果当前字符是左括号，我们可以选择删除或者保留，如果删除，需要满足 $l \gt 0$，然后递归调用 `dfs(i+1, l-1, r, lcnt, rcnt, t)`；
-   如果当前字符是右括号，我们可以选择删除或者保留，如果删除，需要满足 $r \gt 0$，然后递归调用 `dfs(i+1, l, r-1, lcnt, rcnt, t)`；
-   如果选择保留当前字符，我们需要判断当前字符是左括号、右括号还是字母。如果是左括号，我们需要更新 `lcnt`，如果是右括号，我们需要更新 `rcnt`，然后递归调用 `dfs(i+1, l, r, lcnt, rcnt, t+s[i])`。

我们调用 `dfs(0, l, r, 0, 0, "")`，搜索所有可能的字符串。

最后返回去重后的答案数组即可。

时间复杂度 $O(n\times 2^n)$，空间复杂度 $O(n)$。长度为 $n$ 的字符串有 $2^n$ 种可能的删除方式，每种删除方式需要 $O(n)$ 的时间复制字符串。因此总时间复杂度为 $O(n\times 2^n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def removeInvalidParentheses(self, s: str) -> List[str]:
        def dfs(i, l, r, lcnt, rcnt, t):
            if i == n:
                if l == 0 and r == 0:
                    ans.add(t)
                return
            if n - i < l + r or lcnt < rcnt:
                return
            if s[i] == '(' and l:
                dfs(i + 1, l - 1, r, lcnt, rcnt, t)
            elif s[i] == ')' and r:
                dfs(i + 1, l, r - 1, lcnt, rcnt, t)
            dfs(i + 1, l, r, lcnt + (s[i] == '('), rcnt + (s[i] == ')'), t + s[i])

        l = r = 0
        for c in s:
            if c == '(':
                l += 1
            elif c == ')':
                if l:
                    l -= 1
                else:
                    r += 1
        ans = set()
        n = len(s)
        dfs(0, l, r, 0, 0, '')
        return list(ans)
```

#### Java

```java
class Solution {
    private String s;
    private int n;
    private Set<String> ans = new HashSet<>();

    public List<String> removeInvalidParentheses(String s) {
        this.s = s;
        this.n = s.length();
        int l = 0, r = 0;
        for (char c : s.toCharArray()) {
            if (c == '(') {
                ++l;
            } else if (c == ')') {
                if (l > 0) {
                    --l;
                } else {
                    ++r;
                }
            }
        }
        dfs(0, l, r, 0, 0, "");
        return new ArrayList<>(ans);
    }

    private void dfs(int i, int l, int r, int lcnt, int rcnt, String t) {
        if (i == n) {
            if (l == 0 && r == 0) {
                ans.add(t);
            }
            return;
        }
        if (n - i < l + r || lcnt < rcnt) {
            return;
        }
        char c = s.charAt(i);
        if (c == '(' && l > 0) {
            dfs(i + 1, l - 1, r, lcnt, rcnt, t);
        }
        if (c == ')' && r > 0) {
            dfs(i + 1, l, r - 1, lcnt, rcnt, t);
        }
        int x = c == '(' ? 1 : 0;
        int y = c == ')' ? 1 : 0;
        dfs(i + 1, l, r, lcnt + x, rcnt + y, t + c);
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> ans;
        int l = 0, r = 0, n = s.size();
        for (char& c : s) {
            if (c == '(') {
                ++l;
            } else if (c == ')') {
                if (l) {
                    --l;
                } else {
                    ++r;
                }
            }
        }
        function<void(int, int, int, int, int, string)> dfs;
        dfs = [&](int i, int l, int r, int lcnt, int rcnt, string t) {
            if (i == n) {
                if (l == 0 && r == 0) {
                    ans.insert(t);
                }
                return;
            }
            if (n - i < l + r || lcnt < rcnt) {
                return;
            }
            if (s[i] == '(' && l) {
                dfs(i + 1, l - 1, r, lcnt, rcnt, t);
            }
            if (s[i] == ')' && r) {
                dfs(i + 1, l, r - 1, lcnt, rcnt, t);
            }
            int x = s[i] == '(' ? 1 : 0;
            int y = s[i] == ')' ? 1 : 0;
            dfs(i + 1, l, r, lcnt + x, rcnt + y, t + s[i]);
        };

        dfs(0, l, r, 0, 0, "");
        return vector<string>(ans.begin(), ans.end());
    }
};
```

#### Go

```go
func removeInvalidParentheses(s string) []string {
	vis := map[string]bool{}
	l, r, n := 0, 0, len(s)
	for _, c := range s {
		if c == '(' {
			l++
		} else if c == ')' {
			if l > 0 {
				l--
			} else {
				r++
			}
		}
	}
	var dfs func(i, l, r, lcnt, rcnt int, t string)
	dfs = func(i, l, r, lcnt, rcnt int, t string) {
		if i == n {
			if l == 0 && r == 0 {
				vis[t] = true
			}
			return
		}
		if n-i < l+r || lcnt < rcnt {
			return
		}
		if s[i] == '(' && l > 0 {
			dfs(i+1, l-1, r, lcnt, rcnt, t)
		}
		if s[i] == ')' && r > 0 {
			dfs(i+1, l, r-1, lcnt, rcnt, t)
		}
		x, y := 0, 0
		if s[i] == '(' {
			x = 1
		} else if s[i] == ')' {
			y = 1
		}
		dfs(i+1, l, r, lcnt+x, rcnt+y, t+string(s[i]))
	}
	dfs(0, l, r, 0, 0, "")
	ans := make([]string, 0, len(vis))
	for v := range vis {
		ans = append(ans, v)
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [302. 包含全部黑色像素的最小矩形 🔒](https://leetcode.cn/problems/smallest-rectangle-enclosing-black-pixels){#302}

{{< tabs "302" >}}

{{% tab "python" %}}
```python
class Solution:
    def minArea(self, image: List[List[str]], x: int, y: int) -> int:
        m, n = len(image), len(image[0])
        left, right = 0, x
        while left < right:
            mid = (left + right) >> 1
            c = 0
            while c < n and image[mid][c] == '0':
                c += 1
            if c < n:
                right = mid
            else:
                left = mid + 1
        u = left
        left, right = x, m - 1
        while left < right:
            mid = (left + right + 1) >> 1
            c = 0
            while c < n and image[mid][c] == '0':
                c += 1
            if c < n:
                left = mid
            else:
                right = mid - 1
        d = left
        left, right = 0, y
        while left < right:
            mid = (left + right) >> 1
            r = 0
            while r < m and image[r][mid] == '0':
                r += 1
            if r < m:
                right = mid
            else:
                left = mid + 1
        l = left
        left, right = y, n - 1
        while left < right:
            mid = (left + right + 1) >> 1
            r = 0
            while r < m and image[r][mid] == '0':
                r += 1
            if r < m:
                left = mid
            else:
                right = mid - 1
        r = left
        return (d - u + 1) * (r - l + 1)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {

    public int minArea(char[][] image, int x, int y) {
        int m = image.length, n = image[0].length;
        int left = 0, right = x;
        while (left < right) {
            int mid = (left + right) >> 1;
            int c = 0;
            while (c < n && image[mid][c] == '0') {
                ++c;
            }
            if (c < n) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        int u = left;
        left = x;
        right = m - 1;
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            int c = 0;
            while (c < n && image[mid][c] == '0') {
                ++c;
            }
            if (c < n) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        int d = left;
        left = 0;
        right = y;
        while (left < right) {
            int mid = (left + right) >> 1;
            int r = 0;
            while (r < m && image[r][mid] == '0') {
                ++r;
            }
            if (r < m) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        int l = left;
        left = y;
        right = n - 1;
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            int r = 0;
            while (r < m && image[r][mid] == '0') {
                ++r;
            }
            if (r < m) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        int r = left;
        return (d - u + 1) * (r - l + 1);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int m = image.size(), n = image[0].size();
        int left = 0, right = x;
        while (left < right) {
            int mid = (left + right) >> 1;
            int c = 0;
            while (c < n && image[mid][c] == '0') ++c;
            if (c < n)
                right = mid;
            else
                left = mid + 1;
        }
        int u = left;
        left = x;
        right = m - 1;
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            int c = 0;
            while (c < n && image[mid][c] == '0') ++c;
            if (c < n)
                left = mid;
            else
                right = mid - 1;
        }
        int d = left;
        left = 0;
        right = y;
        while (left < right) {
            int mid = (left + right) >> 1;
            int r = 0;
            while (r < m && image[r][mid] == '0') ++r;
            if (r < m)
                right = mid;
            else
                left = mid + 1;
        }
        int l = left;
        left = y;
        right = n - 1;
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            int r = 0;
            while (r < m && image[r][mid] == '0') ++r;
            if (r < m)
                left = mid;
            else
                right = mid - 1;
        }
        int r = left;
        return (d - u + 1) * (r - l + 1);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minArea(image [][]byte, x int, y int) int {
	m, n := len(image), len(image[0])
	left, right := 0, x
	for left < right {
		mid := (left + right) >> 1
		c := 0
		for c < n && image[mid][c] == '0' {
			c++
		}
		if c < n {
			right = mid
		} else {
			left = mid + 1
		}
	}
	u := left
	left, right = x, m-1
	for left < right {
		mid := (left + right + 1) >> 1
		c := 0
		for c < n && image[mid][c] == '0' {
			c++
		}
		if c < n {
			left = mid
		} else {
			right = mid - 1
		}
	}
	d := left
	left, right = 0, y
	for left < right {
		mid := (left + right) >> 1
		r := 0
		for r < m && image[r][mid] == '0' {
			r++
		}
		if r < m {
			right = mid
		} else {
			left = mid + 1
		}
	}
	l := left
	left, right = y, n-1
	for left < right {
		mid := (left + right + 1) >> 1
		r := 0
		for r < m && image[r][mid] == '0' {
			r++
		}
		if r < m {
			left = mid
		} else {
			right = mid - 1
		}
	}
	r := left
	return (d - u + 1) * (r - l + 1)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>图片在计算机处理中往往是使用二维矩阵来表示的。</p>

<p>给你一个大小为 <code>m x n</code> 的二进制矩阵&nbsp;<code>image</code> 表示一张黑白图片，<code>0</code>&nbsp;代表白色像素，<code>1</code>&nbsp;代表黑色像素。</p>

<p>黑色像素相互连接，也就是说，图片中只会有一片连在一块儿的黑色像素。像素点是水平或竖直方向连接的。</p>

<p>给你两个整数 <code>x</code> 和 <code>y</code> 表示某一个黑色像素的位置，请你找出包含全部黑色像素的最小矩形（与坐标轴对齐），并返回该矩形的面积。</p>

<p>你必须设计并实现一个时间复杂度低于&nbsp;<code>O(mn)</code> 的算法来解决此问题。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0300-0399/0302.Smallest%20Rectangle%20Enclosing%20Black%20Pixels/images/pixel-grid.jpg" style="width: 333px; height: 253px;" />
<pre>
<strong>输入：</strong>image = [["0","0","1","0"],["0","1","1","0"],["0","1","0","0"]], x = 0, y = 2
<strong>输出：</strong>6
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>image = [["1"]], x = 0, y = 0
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == image.length</code></li>
	<li><code>n == image[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
	<li><code>image[i][j]</code> 为 <code>'0'</code> 或 <code>'1'</code></li>
	<li><code>1 &lt;= x &lt; m</code></li>
	<li><code>1 &lt;= y &lt; n</code></li>
	<li><code>image[x][y] == '1'</code></li>
	<li><code>image</code> 中的黑色像素仅形成一个 <strong>组件</strong></li>
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
    def minArea(self, image: List[List[str]], x: int, y: int) -> int:
        m, n = len(image), len(image[0])
        left, right = 0, x
        while left < right:
            mid = (left + right) >> 1
            c = 0
            while c < n and image[mid][c] == '0':
                c += 1
            if c < n:
                right = mid
            else:
                left = mid + 1
        u = left
        left, right = x, m - 1
        while left < right:
            mid = (left + right + 1) >> 1
            c = 0
            while c < n and image[mid][c] == '0':
                c += 1
            if c < n:
                left = mid
            else:
                right = mid - 1
        d = left
        left, right = 0, y
        while left < right:
            mid = (left + right) >> 1
            r = 0
            while r < m and image[r][mid] == '0':
                r += 1
            if r < m:
                right = mid
            else:
                left = mid + 1
        l = left
        left, right = y, n - 1
        while left < right:
            mid = (left + right + 1) >> 1
            r = 0
            while r < m and image[r][mid] == '0':
                r += 1
            if r < m:
                left = mid
            else:
                right = mid - 1
        r = left
        return (d - u + 1) * (r - l + 1)
```

#### Java

```java
class Solution {

    public int minArea(char[][] image, int x, int y) {
        int m = image.length, n = image[0].length;
        int left = 0, right = x;
        while (left < right) {
            int mid = (left + right) >> 1;
            int c = 0;
            while (c < n && image[mid][c] == '0') {
                ++c;
            }
            if (c < n) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        int u = left;
        left = x;
        right = m - 1;
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            int c = 0;
            while (c < n && image[mid][c] == '0') {
                ++c;
            }
            if (c < n) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        int d = left;
        left = 0;
        right = y;
        while (left < right) {
            int mid = (left + right) >> 1;
            int r = 0;
            while (r < m && image[r][mid] == '0') {
                ++r;
            }
            if (r < m) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        int l = left;
        left = y;
        right = n - 1;
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            int r = 0;
            while (r < m && image[r][mid] == '0') {
                ++r;
            }
            if (r < m) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        int r = left;
        return (d - u + 1) * (r - l + 1);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int m = image.size(), n = image[0].size();
        int left = 0, right = x;
        while (left < right) {
            int mid = (left + right) >> 1;
            int c = 0;
            while (c < n && image[mid][c] == '0') ++c;
            if (c < n)
                right = mid;
            else
                left = mid + 1;
        }
        int u = left;
        left = x;
        right = m - 1;
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            int c = 0;
            while (c < n && image[mid][c] == '0') ++c;
            if (c < n)
                left = mid;
            else
                right = mid - 1;
        }
        int d = left;
        left = 0;
        right = y;
        while (left < right) {
            int mid = (left + right) >> 1;
            int r = 0;
            while (r < m && image[r][mid] == '0') ++r;
            if (r < m)
                right = mid;
            else
                left = mid + 1;
        }
        int l = left;
        left = y;
        right = n - 1;
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            int r = 0;
            while (r < m && image[r][mid] == '0') ++r;
            if (r < m)
                left = mid;
            else
                right = mid - 1;
        }
        int r = left;
        return (d - u + 1) * (r - l + 1);
    }
};
```

#### Go

```go
func minArea(image [][]byte, x int, y int) int {
	m, n := len(image), len(image[0])
	left, right := 0, x
	for left < right {
		mid := (left + right) >> 1
		c := 0
		for c < n && image[mid][c] == '0' {
			c++
		}
		if c < n {
			right = mid
		} else {
			left = mid + 1
		}
	}
	u := left
	left, right = x, m-1
	for left < right {
		mid := (left + right + 1) >> 1
		c := 0
		for c < n && image[mid][c] == '0' {
			c++
		}
		if c < n {
			left = mid
		} else {
			right = mid - 1
		}
	}
	d := left
	left, right = 0, y
	for left < right {
		mid := (left + right) >> 1
		r := 0
		for r < m && image[r][mid] == '0' {
			r++
		}
		if r < m {
			right = mid
		} else {
			left = mid + 1
		}
	}
	l := left
	left, right = y, n-1
	for left < right {
		mid := (left + right + 1) >> 1
		r := 0
		for r < m && image[r][mid] == '0' {
			r++
		}
		if r < m {
			left = mid
		} else {
			right = mid - 1
		}
	}
	r := left
	return (d - u + 1) * (r - l + 1)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [303. 区域和检索 - 数组不可变](https://leetcode.cn/problems/range-sum-query-immutable){#303}

{{< tabs "303" >}}

{{% tab "python" %}}
```python
class NumArray:
    def __init__(self, nums: List[int]):
        self.s = list(accumulate(nums, initial=0))

    def sumRange(self, left: int, right: int) -> int:
        return self.s[right + 1] - self.s[left]


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class NumArray {
    private int[] s;

    public NumArray(int[] nums) {
        int n = nums.length;
        s = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
    }

    public int sumRange(int left, int right) {
        return s[right + 1] - s[left];
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(left,right);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class NumArray {
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        s.resize(n + 1);
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        return s[right + 1] - s[left];
    }

private:
    vector<int> s;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type NumArray struct {
	s []int
}

func Constructor(nums []int) NumArray {
	n := len(nums)
	s := make([]int, n+1)
	for i, v := range nums {
		s[i+1] = s[i] + v
	}
	return NumArray{s}
}

func (this *NumArray) SumRange(left int, right int) int {
	return this.s[right+1] - this.s[left]
}

/**
 * Your NumArray object will be instantiated and called as such:
 * obj := Constructor(nums);
 * param_1 := obj.SumRange(left,right);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class NumArray {
    private s: number[];

    constructor(nums: number[]) {
        const n = nums.length;
        this.s = Array(n + 1).fill(0);
        for (let i = 0; i < n; ++i) {
            this.s[i + 1] = this.s[i] + nums[i];
        }
    }

    sumRange(left: number, right: number): number {
        return this.s[right + 1] - this.s[left];
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * var obj = new NumArray(nums)
 * var param_1 = obj.sumRange(left,right)
 */
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
struct NumArray {
    s: Vec<i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl NumArray {
    fn new(mut nums: Vec<i32>) -> Self {
        let n = nums.len();
        let mut s = vec![0; n + 1];
        for i in 0..n {
            s[i + 1] = s[i] + nums[i];
        }
        Self { s }
    }

    fn sum_range(&self, left: i32, right: i32) -> i32 {
        self.s[(right + 1) as usize] - self.s[left as usize]
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 */
var NumArray = function (nums) {
    const n = nums.length;
    this.s = Array(n + 1).fill(0);
    for (let i = 0; i < n; ++i) {
        this.s[i + 1] = this.s[i] + nums[i];
    }
};

/**
 * @param {number} left
 * @param {number} right
 * @return {number}
 */
NumArray.prototype.sumRange = function (left, right) {
    return this.s[right + 1] - this.s[left];
};

/**
 * Your NumArray object will be instantiated and called as such:
 * var obj = new NumArray(nums)
 * var param_1 = obj.sumRange(left,right)
 */
```
{{% /tab %}}
{{% tab "php" %}}
```php
class NumArray {
    /**
     * @param Integer[] $nums
     */
    function __construct($nums) {
        $this->s = [0];
        foreach ($nums as $x) {
            $this->s[] = $this->s[count($this->s) - 1] + $x;
        }
    }

    /**
     * @param Integer $left
     * @param Integer $right
     * @return Integer
     */
    function sumRange($left, $right) {
        return $this->s[$right + 1] - $this->s[$left];
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * $obj = NumArray($nums);
 * $ret_1 = $obj->sumRange($left, $right);
 */
```
{{% /tab %}}
{{% tab "c" %}}
```c
typedef struct {
    int* s;
} NumArray;

NumArray* numArrayCreate(int* nums, int n) {
    int* s = malloc(sizeof(int) * (n + 1));
    s[0] = 0;
    for (int i = 0; i < n; i++) {
        s[i + 1] = s[i] + nums[i];
    }
    NumArray* obj = malloc(sizeof(NumArray));
    obj->s = s;
    return obj;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    return obj->s[right + 1] - obj->s[left];
}

void numArrayFree(NumArray* obj) {
    free(obj->s);
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);

 * numArrayFree(obj);
*/
```
{{% /tab %}}
{{% tab "kotlin" %}}
```kotlin
class NumArray(nums: IntArray) {
    private val prefix_sums: IntArray

    init {
        val nums_size = nums.size
        this.prefix_sums = IntArray(nums_size + 1)
        for (i in 0..<nums_size) {
            this.prefix_sums[i + 1] = this.prefix_sums[i] + nums[i]
        }
    }

    fun sumRange(left: Int, right: Int): Int = this.prefix_sums[right + 1] - this.prefix_sums[left]
}

/**
 * Your NumArray object will be instantiated and called as such: var obj = NumArray(nums) var
 * param_1 = obj.sumRange(left,right)
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个整数数组 &nbsp;<code>nums</code>，处理以下类型的多个查询:</p>

<ol>
	<li>计算索引&nbsp;<code>left</code>&nbsp;和&nbsp;<code>right</code>&nbsp;（包含 <code>left</code> 和 <code>right</code>）之间的 <code>nums</code> 元素的 <strong>和</strong> ，其中&nbsp;<code>left &lt;= right</code></li>
</ol>

<p>实现 <code>NumArray</code> 类：</p>

<ul>
	<li><code>NumArray(int[] nums)</code> 使用数组 <code>nums</code> 初始化对象</li>
	<li><code>int sumRange(int i, int j)</code> 返回数组 <code>nums</code>&nbsp;中索引&nbsp;<code>left</code>&nbsp;和&nbsp;<code>right</code>&nbsp;之间的元素的 <strong>总和</strong> ，包含&nbsp;<code>left</code>&nbsp;和&nbsp;<code>right</code>&nbsp;两点（也就是&nbsp;<code>nums[left] + nums[left + 1] + ... + nums[right]</code>&nbsp;)</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
<strong>输出：
</strong>[null, 1, -1, -3]

<strong>解释：</strong>
NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
numArray.sumRange(0, 2); // return 1 ((-2) + 0 + 3)
numArray.sumRange(2, 5); // return -1 (3 + (-5) + 2 + (-1)) 
numArray.sumRange(0, 5); // return -3 ((-2) + 0 + 3 + (-5) + 2 + (-1))
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>5</sup>&nbsp;&lt;= nums[i] &lt;=&nbsp;10<sup>5</sup></code></li>
	<li><code>0 &lt;= i &lt;= j &lt; nums.length</code></li>
	<li>最多调用 <code>10<sup>4</sup></code> 次 <code>sumRange</code><strong> </strong>方法</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和

我们创建一个长度为 $n + 1$ 的前缀和数组 $s$，其中 $s[i]$ 表示前 $i$ 个元素的前缀和，即 $s[i] = \sum_{j=0}^{i-1} nums[j]$，那么索引 $[left, right]$ 之间的元素的和就可以表示为 $s[right + 1] - s[left]$。

初始化前缀和数组 $s$ 的时间复杂度为 $O(n)$，查询的时间复杂度为 $O(1)$。空间复杂度 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class NumArray:
    def __init__(self, nums: List[int]):
        self.s = list(accumulate(nums, initial=0))

    def sumRange(self, left: int, right: int) -> int:
        return self.s[right + 1] - self.s[left]


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)
```

#### Java

```java
class NumArray {
    private int[] s;

    public NumArray(int[] nums) {
        int n = nums.length;
        s = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
    }

    public int sumRange(int left, int right) {
        return s[right + 1] - s[left];
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(left,right);
 */
```

#### C++

```cpp
class NumArray {
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        s.resize(n + 1);
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        return s[right + 1] - s[left];
    }

private:
    vector<int> s;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
```

#### Go

```go
type NumArray struct {
	s []int
}

func Constructor(nums []int) NumArray {
	n := len(nums)
	s := make([]int, n+1)
	for i, v := range nums {
		s[i+1] = s[i] + v
	}
	return NumArray{s}
}

func (this *NumArray) SumRange(left int, right int) int {
	return this.s[right+1] - this.s[left]
}

/**
 * Your NumArray object will be instantiated and called as such:
 * obj := Constructor(nums);
 * param_1 := obj.SumRange(left,right);
 */
```

#### TypeScript

```ts
class NumArray {
    private s: number[];

    constructor(nums: number[]) {
        const n = nums.length;
        this.s = Array(n + 1).fill(0);
        for (let i = 0; i < n; ++i) {
            this.s[i + 1] = this.s[i] + nums[i];
        }
    }

    sumRange(left: number, right: number): number {
        return this.s[right + 1] - this.s[left];
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * var obj = new NumArray(nums)
 * var param_1 = obj.sumRange(left,right)
 */
```

#### Rust

```rust
struct NumArray {
    s: Vec<i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl NumArray {
    fn new(mut nums: Vec<i32>) -> Self {
        let n = nums.len();
        let mut s = vec![0; n + 1];
        for i in 0..n {
            s[i + 1] = s[i] + nums[i];
        }
        Self { s }
    }

    fn sum_range(&self, left: i32, right: i32) -> i32 {
        self.s[(right + 1) as usize] - self.s[left as usize]
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 */
var NumArray = function (nums) {
    const n = nums.length;
    this.s = Array(n + 1).fill(0);
    for (let i = 0; i < n; ++i) {
        this.s[i + 1] = this.s[i] + nums[i];
    }
};

/**
 * @param {number} left
 * @param {number} right
 * @return {number}
 */
NumArray.prototype.sumRange = function (left, right) {
    return this.s[right + 1] - this.s[left];
};

/**
 * Your NumArray object will be instantiated and called as such:
 * var obj = new NumArray(nums)
 * var param_1 = obj.sumRange(left,right)
 */
```

#### PHP

```php
class NumArray {
    /**
     * @param Integer[] $nums
     */
    function __construct($nums) {
        $this->s = [0];
        foreach ($nums as $x) {
            $this->s[] = $this->s[count($this->s) - 1] + $x;
        }
    }

    /**
     * @param Integer $left
     * @param Integer $right
     * @return Integer
     */
    function sumRange($left, $right) {
        return $this->s[$right + 1] - $this->s[$left];
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * $obj = NumArray($nums);
 * $ret_1 = $obj->sumRange($left, $right);
 */
```

#### C

```c
typedef struct {
    int* s;
} NumArray;

NumArray* numArrayCreate(int* nums, int n) {
    int* s = malloc(sizeof(int) * (n + 1));
    s[0] = 0;
    for (int i = 0; i < n; i++) {
        s[i + 1] = s[i] + nums[i];
    }
    NumArray* obj = malloc(sizeof(NumArray));
    obj->s = s;
    return obj;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    return obj->s[right + 1] - obj->s[left];
}

void numArrayFree(NumArray* obj) {
    free(obj->s);
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);

 * numArrayFree(obj);
*/
```

#### Kotlin

```kotlin
class NumArray(nums: IntArray) {
    private val prefix_sums: IntArray

    init {
        val nums_size = nums.size
        this.prefix_sums = IntArray(nums_size + 1)
        for (i in 0..<nums_size) {
            this.prefix_sums[i + 1] = this.prefix_sums[i] + nums[i]
        }
    }

    fun sumRange(left: Int, right: Int): Int = this.prefix_sums[right + 1] - this.prefix_sums[left]
}

/**
 * Your NumArray object will be instantiated and called as such: var obj = NumArray(nums) var
 * param_1 = obj.sumRange(left,right)
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [304. 二维区域和检索 - 矩阵不可变](https://leetcode.cn/problems/range-sum-query-2d-immutable){#304}

{{< tabs "304" >}}

{{% tab "python" %}}
```python
class NumMatrix:
    def __init__(self, matrix: List[List[int]]):
        m, n = len(matrix), len(matrix[0])
        self.s = [[0] * (n + 1) for _ in range(m + 1)]
        for i, row in enumerate(matrix):
            for j, v in enumerate(row):
                self.s[i + 1][j + 1] = (
                    self.s[i][j + 1] + self.s[i + 1][j] - self.s[i][j] + v
                )

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        return (
            self.s[row2 + 1][col2 + 1]
            - self.s[row2 + 1][col1]
            - self.s[row1][col2 + 1]
            + self.s[row1][col1]
        )


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class NumMatrix {
    private int[][] s;

    public NumMatrix(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        s = new int[m + 1][n + 1];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                s[i + 1][j + 1] = s[i + 1][j] + s[i][j + 1] - s[i][j] + matrix[i][j];
            }
        }
    }

    public int sumRegion(int row1, int col1, int row2, int col2) {
        return s[row2 + 1][col2 + 1] - s[row2 + 1][col1] - s[row1][col2 + 1] + s[row1][col1];
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class NumMatrix {
public:
    vector<vector<int>> s;

    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        s.resize(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                s[i + 1][j + 1] = s[i + 1][j] + s[i][j + 1] - s[i][j] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return s[row2 + 1][col2 + 1] - s[row2 + 1][col1] - s[row1][col2 + 1] + s[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type NumMatrix struct {
	s [][]int
}

func Constructor(matrix [][]int) NumMatrix {
	m, n := len(matrix), len(matrix[0])
	s := make([][]int, m+1)
	for i := range s {
		s[i] = make([]int, n+1)
	}
	for i, row := range matrix {
		for j, v := range row {
			s[i+1][j+1] = s[i+1][j] + s[i][j+1] - s[i][j] + v
		}
	}
	return NumMatrix{s}
}

func (this *NumMatrix) SumRegion(row1 int, col1 int, row2 int, col2 int) int {
	return this.s[row2+1][col2+1] - this.s[row2+1][col1] - this.s[row1][col2+1] + this.s[row1][col1]
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * obj := Constructor(matrix);
 * param_1 := obj.SumRegion(row1,col1,row2,col2);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class NumMatrix {
    private s: number[][];

    constructor(matrix: number[][]) {
        const m = matrix.length;
        const n = matrix[0].length;
        this.s = new Array(m + 1).fill(0).map(() => new Array(n + 1).fill(0));
        for (let i = 0; i < m; ++i) {
            for (let j = 0; j < n; ++j) {
                this.s[i + 1][j + 1] =
                    this.s[i + 1][j] + this.s[i][j + 1] - this.s[i][j] + matrix[i][j];
            }
        }
    }

    sumRegion(row1: number, col1: number, row2: number, col2: number): number {
        return (
            this.s[row2 + 1][col2 + 1] -
            this.s[row2 + 1][col1] -
            this.s[row1][col2 + 1] +
            this.s[row1][col1]
        );
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * var obj = new NumMatrix(matrix)
 * var param_1 = obj.sumRegion(row1,col1,row2,col2)
 */
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
/**
 * Your NumMatrix object will be instantiated and called as such:
 * let obj = NumMatrix::new(matrix);
 * let ret_1: i32 = obj.sum_region(row1, col1, row2, col2);
 */

struct NumMatrix {
    // Of size (N + 1) * (M + 1)
    prefix_vec: Vec<Vec<i32>>,
    n: usize,
    m: usize,
    is_initialized: bool,
    ref_vec: Vec<Vec<i32>>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl NumMatrix {
    fn new(matrix: Vec<Vec<i32>>) -> Self {
        NumMatrix {
            prefix_vec: vec![vec![0; matrix[0].len() + 1]; matrix.len() + 1],
            n: matrix.len(),
            m: matrix[0].len(),
            is_initialized: false,
            ref_vec: matrix,
        }
    }

    fn sum_region(&mut self, row1: i32, col1: i32, row2: i32, col2: i32) -> i32 {
        if !self.is_initialized {
            self.initialize_prefix_vec();
        }
        // Since i32 will let `rustc` complain, just make it happy
        let row1: usize = row1 as usize;
        let col1: usize = col1 as usize;
        let row2: usize = row2 as usize;
        let col2: usize = col2 as usize;
        // Return the value in O(1)
        self.prefix_vec[row2 + 1][col2 + 1]
            - self.prefix_vec[row2 + 1][col1]
            - self.prefix_vec[row1][col2 + 1]
            + self.prefix_vec[row1][col1]
    }

    fn initialize_prefix_vec(&mut self) {
        // Initialize the prefix sum vector
        for i in 0..self.n {
            for j in 0..self.m {
                self.prefix_vec[i + 1][j + 1] =
                    self.prefix_vec[i][j + 1] + self.prefix_vec[i + 1][j] - self.prefix_vec[i][j]
                        + self.ref_vec[i][j];
            }
        }
        self.is_initialized = true;
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[][]} matrix
 */
var NumMatrix = function (matrix) {
    const m = matrix.length;
    const n = matrix[0].length;
    this.s = new Array(m + 1).fill(0).map(() => new Array(n + 1).fill(0));
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            this.s[i + 1][j + 1] =
                this.s[i + 1][j] + this.s[i][j + 1] - this.s[i][j] + matrix[i][j];
        }
    }
};

/**
 * @param {number} row1
 * @param {number} col1
 * @param {number} row2
 * @param {number} col2
 * @return {number}
 */
NumMatrix.prototype.sumRegion = function (row1, col1, row2, col2) {
    return (
        this.s[row2 + 1][col2 + 1] -
        this.s[row2 + 1][col1] -
        this.s[row1][col2 + 1] +
        this.s[row1][col1]
    );
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * var obj = new NumMatrix(matrix)
 * var param_1 = obj.sumRegion(row1,col1,row2,col2)
 */
```
{{% /tab %}}
{{% tab "kotlin" %}}
```kotlin
class NumMatrix(matrix: Array<IntArray>) {
    private val n: Int
    private val m: Int
    private val matrix: Array<IntArray>
    private val prefix_sums_matrix: Array<IntArray>
    private var initialized: Boolean

    init {
        this.n = matrix.size
        this.m = matrix[0].size
        this.matrix = matrix
        this.prefix_sums_matrix = Array(n + 1) { IntArray(m + 1) }
        this.initialized = false
    }

    fun sumRegion(row1: Int, col1: Int, row2: Int, col2: Int): Int {
        this.init()
        return this.prefix_sums_matrix[row2 + 1][col2 + 1] -
            this.prefix_sums_matrix[row2 + 1][col1] -
            this.prefix_sums_matrix[row1][col2 + 1] +
            this.prefix_sums_matrix[row1][col1]
    }

    private fun init(): Boolean {
        if (!this.initialized) {
            for (i in 0..<this.n) {
                for (j in 0..<this.m) {
                    this.prefix_sums_matrix[i + 1][j + 1] =
                        this.prefix_sums_matrix[i + 1][j] +
                        this.prefix_sums_matrix[i][j + 1] -
                        this.prefix_sums_matrix[i][j] +
                        this.matrix[i][j]
                }
            }
            this.initialized = true
            return true
        }
        return false
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such: var obj = NumMatrix(matrix) var
 * param_1 = obj.sumRegion(row1,col1,row2,col2)
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><big><small>给定一个二维矩阵 <code>matrix</code>，</small></big>以下类型的多个请求：</p>

<ul>
	<li><big><small>计算其子矩形范围内元素的总和，该子矩阵的 <strong>左上角</strong> 为 <code>(row1,&nbsp;col1)</code> ，<strong>右下角</strong> 为 <code>(row2,&nbsp;col2)</code> 。</small></big></li>
</ul>

<p>实现 <code>NumMatrix</code> 类：</p>

<ul>
	<li><code>NumMatrix(int[][] matrix)</code>&nbsp;给定整数矩阵 <code>matrix</code> 进行初始化</li>
	<li><code>int sumRegion(int row1, int col1, int row2, int col2)</code>&nbsp;返回<big><small> <strong>左上角</strong></small></big><big><small> <code>(row1,&nbsp;col1)</code>&nbsp;、<strong>右下角</strong>&nbsp;<code>(row2,&nbsp;col2)</code></small></big> 所描述的子矩阵的元素 <strong>总和</strong> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0300-0399/0304.Range%20Sum%20Query%202D%20-%20Immutable/images/1626332422-wUpUHT-image.png" style="width: 200px;" /></p>

<pre>
<strong>输入:</strong> 
["NumMatrix","sumRegion","sumRegion","sumRegion"]
[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]]
<strong>输出:</strong> 
[null, 8, 11, 12]

<strong>解释:</strong>
NumMatrix numMatrix = new NumMatrix([[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]);
numMatrix.sumRegion(2, 1, 4, 3); // return 8 (红色矩形框的元素总和)
numMatrix.sumRegion(1, 1, 2, 2); // return 11 (绿色矩形框的元素总和)
numMatrix.sumRegion(1, 2, 2, 4); // return 12 (蓝色矩形框的元素总和)
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 &lt;= m,&nbsp;n &lt;=&nbsp;200</code><meta charset="UTF-8" /></li>
	<li><code>-10<sup>5</sup>&nbsp;&lt;= matrix[i][j] &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= row1 &lt;= row2 &lt; m</code></li>
	<li><code>0 &lt;= col1 &lt;= col2 &lt; n</code></li>
	<li><meta charset="UTF-8" />最多调用 <code>10<sup>4</sup></code> 次&nbsp;<code>sumRegion</code> 方法</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二维前缀和

我们用 $s[i + 1][j + 1]$ 表示第 $i$ 行第 $j$ 列左上部分所有元素之和，下标 $i$ 和 $j$ 均从 $0$ 开始。可以得到以下前缀和公式：

$$
s[i + 1][j + 1] = s[i + 1][j] + s[i][j + 1] - s[i][j] + nums[i][j]
$$

那么分别以 $(x_1, y_1)$ 和 $(x_2, y_2)$ 为左上角和右下角的矩形的元素之和为：

$$
s[x_2 + 1][y_2 + 1] - s[x_2 + 1][y_1] - s[x_1][y_2 + 1] + s[x_1][y_1]
$$

我们在初始化方法中预处理出前缀和数组 $s$，在查询方法中直接返回上述公式的结果即可。

初始化的时间复杂度为 $O(m \times n)$，查询的时间复杂度为 $O(1)$。空间复杂度为 $O(m \times n)$。

<!-- tabs:start -->

#### Python3

```python
class NumMatrix:
    def __init__(self, matrix: List[List[int]]):
        m, n = len(matrix), len(matrix[0])
        self.s = [[0] * (n + 1) for _ in range(m + 1)]
        for i, row in enumerate(matrix):
            for j, v in enumerate(row):
                self.s[i + 1][j + 1] = (
                    self.s[i][j + 1] + self.s[i + 1][j] - self.s[i][j] + v
                )

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        return (
            self.s[row2 + 1][col2 + 1]
            - self.s[row2 + 1][col1]
            - self.s[row1][col2 + 1]
            + self.s[row1][col1]
        )


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)
```

#### Java

```java
class NumMatrix {
    private int[][] s;

    public NumMatrix(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        s = new int[m + 1][n + 1];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                s[i + 1][j + 1] = s[i + 1][j] + s[i][j + 1] - s[i][j] + matrix[i][j];
            }
        }
    }

    public int sumRegion(int row1, int col1, int row2, int col2) {
        return s[row2 + 1][col2 + 1] - s[row2 + 1][col1] - s[row1][col2 + 1] + s[row1][col1];
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
```

#### C++

```cpp
class NumMatrix {
public:
    vector<vector<int>> s;

    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        s.resize(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                s[i + 1][j + 1] = s[i + 1][j] + s[i][j + 1] - s[i][j] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return s[row2 + 1][col2 + 1] - s[row2 + 1][col1] - s[row1][col2 + 1] + s[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
```

#### Go

```go
type NumMatrix struct {
	s [][]int
}

func Constructor(matrix [][]int) NumMatrix {
	m, n := len(matrix), len(matrix[0])
	s := make([][]int, m+1)
	for i := range s {
		s[i] = make([]int, n+1)
	}
	for i, row := range matrix {
		for j, v := range row {
			s[i+1][j+1] = s[i+1][j] + s[i][j+1] - s[i][j] + v
		}
	}
	return NumMatrix{s}
}

func (this *NumMatrix) SumRegion(row1 int, col1 int, row2 int, col2 int) int {
	return this.s[row2+1][col2+1] - this.s[row2+1][col1] - this.s[row1][col2+1] + this.s[row1][col1]
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * obj := Constructor(matrix);
 * param_1 := obj.SumRegion(row1,col1,row2,col2);
 */
```

#### TypeScript

```ts
class NumMatrix {
    private s: number[][];

    constructor(matrix: number[][]) {
        const m = matrix.length;
        const n = matrix[0].length;
        this.s = new Array(m + 1).fill(0).map(() => new Array(n + 1).fill(0));
        for (let i = 0; i < m; ++i) {
            for (let j = 0; j < n; ++j) {
                this.s[i + 1][j + 1] =
                    this.s[i + 1][j] + this.s[i][j + 1] - this.s[i][j] + matrix[i][j];
            }
        }
    }

    sumRegion(row1: number, col1: number, row2: number, col2: number): number {
        return (
            this.s[row2 + 1][col2 + 1] -
            this.s[row2 + 1][col1] -
            this.s[row1][col2 + 1] +
            this.s[row1][col1]
        );
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * var obj = new NumMatrix(matrix)
 * var param_1 = obj.sumRegion(row1,col1,row2,col2)
 */
```

#### Rust

```rust
/**
 * Your NumMatrix object will be instantiated and called as such:
 * let obj = NumMatrix::new(matrix);
 * let ret_1: i32 = obj.sum_region(row1, col1, row2, col2);
 */

struct NumMatrix {
    // Of size (N + 1) * (M + 1)
    prefix_vec: Vec<Vec<i32>>,
    n: usize,
    m: usize,
    is_initialized: bool,
    ref_vec: Vec<Vec<i32>>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl NumMatrix {
    fn new(matrix: Vec<Vec<i32>>) -> Self {
        NumMatrix {
            prefix_vec: vec![vec![0; matrix[0].len() + 1]; matrix.len() + 1],
            n: matrix.len(),
            m: matrix[0].len(),
            is_initialized: false,
            ref_vec: matrix,
        }
    }

    fn sum_region(&mut self, row1: i32, col1: i32, row2: i32, col2: i32) -> i32 {
        if !self.is_initialized {
            self.initialize_prefix_vec();
        }
        // Since i32 will let `rustc` complain, just make it happy
        let row1: usize = row1 as usize;
        let col1: usize = col1 as usize;
        let row2: usize = row2 as usize;
        let col2: usize = col2 as usize;
        // Return the value in O(1)
        self.prefix_vec[row2 + 1][col2 + 1]
            - self.prefix_vec[row2 + 1][col1]
            - self.prefix_vec[row1][col2 + 1]
            + self.prefix_vec[row1][col1]
    }

    fn initialize_prefix_vec(&mut self) {
        // Initialize the prefix sum vector
        for i in 0..self.n {
            for j in 0..self.m {
                self.prefix_vec[i + 1][j + 1] =
                    self.prefix_vec[i][j + 1] + self.prefix_vec[i + 1][j] - self.prefix_vec[i][j]
                        + self.ref_vec[i][j];
            }
        }
        self.is_initialized = true;
    }
}
```

#### JavaScript

```js
/**
 * @param {number[][]} matrix
 */
var NumMatrix = function (matrix) {
    const m = matrix.length;
    const n = matrix[0].length;
    this.s = new Array(m + 1).fill(0).map(() => new Array(n + 1).fill(0));
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            this.s[i + 1][j + 1] =
                this.s[i + 1][j] + this.s[i][j + 1] - this.s[i][j] + matrix[i][j];
        }
    }
};

/**
 * @param {number} row1
 * @param {number} col1
 * @param {number} row2
 * @param {number} col2
 * @return {number}
 */
NumMatrix.prototype.sumRegion = function (row1, col1, row2, col2) {
    return (
        this.s[row2 + 1][col2 + 1] -
        this.s[row2 + 1][col1] -
        this.s[row1][col2 + 1] +
        this.s[row1][col1]
    );
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * var obj = new NumMatrix(matrix)
 * var param_1 = obj.sumRegion(row1,col1,row2,col2)
 */
```

#### Kotlin

```kotlin
class NumMatrix(matrix: Array<IntArray>) {
    private val n: Int
    private val m: Int
    private val matrix: Array<IntArray>
    private val prefix_sums_matrix: Array<IntArray>
    private var initialized: Boolean

    init {
        this.n = matrix.size
        this.m = matrix[0].size
        this.matrix = matrix
        this.prefix_sums_matrix = Array(n + 1) { IntArray(m + 1) }
        this.initialized = false
    }

    fun sumRegion(row1: Int, col1: Int, row2: Int, col2: Int): Int {
        this.init()
        return this.prefix_sums_matrix[row2 + 1][col2 + 1] -
            this.prefix_sums_matrix[row2 + 1][col1] -
            this.prefix_sums_matrix[row1][col2 + 1] +
            this.prefix_sums_matrix[row1][col1]
    }

    private fun init(): Boolean {
        if (!this.initialized) {
            for (i in 0..<this.n) {
                for (j in 0..<this.m) {
                    this.prefix_sums_matrix[i + 1][j + 1] =
                        this.prefix_sums_matrix[i + 1][j] +
                        this.prefix_sums_matrix[i][j + 1] -
                        this.prefix_sums_matrix[i][j] +
                        this.matrix[i][j]
                }
            }
            this.initialized = true
            return true
        }
        return false
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such: var obj = NumMatrix(matrix) var
 * param_1 = obj.sumRegion(row1,col1,row2,col2)
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [305. 岛屿数量 II 🔒](https://leetcode.cn/problems/number-of-islands-ii){#305}

{{< tabs "305" >}}

{{% tab "python" %}}
```python
class UnionFind:
    def __init__(self, n: int):
        self.p = list(range(n))
        self.size = [1] * n

    def find(self, x: int):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, a: int, b: int) -> bool:
        pa, pb = self.find(a - 1), self.find(b - 1)
        if pa == pb:
            return False
        if self.size[pa] > self.size[pb]:
            self.p[pb] = pa
            self.size[pa] += self.size[pb]
        else:
            self.p[pa] = pb
            self.size[pb] += self.size[pa]
        return True


class Solution:
    def numIslands2(self, m: int, n: int, positions: List[List[int]]) -> List[int]:
        uf = UnionFind(m * n)
        grid = [[0] * n for _ in range(m)]
        ans = []
        dirs = (-1, 0, 1, 0, -1)
        cnt = 0
        for i, j in positions:
            if grid[i][j]:
                ans.append(cnt)
                continue
            grid[i][j] = 1
            cnt += 1
            for a, b in pairwise(dirs):
                x, y = i + a, j + b
                if (
                    0 <= x < m
                    and 0 <= y < n
                    and grid[x][y]
                    and uf.union(i * n + j, x * n + y)
                ):
                    cnt -= 1
            ans.append(cnt)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class UnionFind {
    private final int[] p;
    private final int[] size;

    public UnionFind(int n) {
        p = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            size[i] = 1;
        }
    }

    public int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    public boolean union(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }
}

class Solution {
    public List<Integer> numIslands2(int m, int n, int[][] positions) {
        int[][] grid = new int[m][n];
        UnionFind uf = new UnionFind(m * n);
        int[] dirs = {-1, 0, 1, 0, -1};
        int cnt = 0;
        List<Integer> ans = new ArrayList<>();
        for (var p : positions) {
            int i = p[0], j = p[1];
            if (grid[i][j] == 1) {
                ans.add(cnt);
                continue;
            }
            grid[i][j] = 1;
            ++cnt;
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1
                    && uf.union(i * n + j, x * n + y)) {
                    --cnt;
                }
            }
            ans.add(cnt);
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class UnionFind {
public:
    UnionFind(int n) {
        p = vector<int>(n);
        size = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    bool unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

private:
    vector<int> p, size;
};

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        int grid[m][n];
        memset(grid, 0, sizeof(grid));
        UnionFind uf(m * n);
        int dirs[5] = {-1, 0, 1, 0, -1};
        int cnt = 0;
        vector<int> ans;
        for (auto& p : positions) {
            int i = p[0], j = p[1];
            if (grid[i][j]) {
                ans.push_back(cnt);
                continue;
            }
            grid[i][j] = 1;
            ++cnt;
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] && uf.unite(i * n + j, x * n + y)) {
                    --cnt;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type unionFind struct {
	p, size []int
}

func newUnionFind(n int) *unionFind {
	p := make([]int, n)
	size := make([]int, n)
	for i := range p {
		p[i] = i
		size[i] = 1
	}
	return &unionFind{p, size}
}

func (uf *unionFind) find(x int) int {
	if uf.p[x] != x {
		uf.p[x] = uf.find(uf.p[x])
	}
	return uf.p[x]
}

func (uf *unionFind) union(a, b int) bool {
	pa, pb := uf.find(a), uf.find(b)
	if pa == pb {
		return false
	}
	if uf.size[pa] > uf.size[pb] {
		uf.p[pb] = pa
		uf.size[pa] += uf.size[pb]
	} else {
		uf.p[pa] = pb
		uf.size[pb] += uf.size[pa]
	}
	return true
}

func numIslands2(m int, n int, positions [][]int) (ans []int) {
	uf := newUnionFind(m * n)
	grid := make([][]int, m)
	for i := range grid {
		grid[i] = make([]int, n)
	}
	dirs := [5]int{-1, 0, 1, 0, -1}
	cnt := 0
	for _, p := range positions {
		i, j := p[0], p[1]
		if grid[i][j] == 1 {
			ans = append(ans, cnt)
			continue
		}
		grid[i][j] = 1
		cnt++
		for k := 0; k < 4; k++ {
			x, y := i+dirs[k], j+dirs[k+1]
			if x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1 && uf.union(i*n+j, x*n+y) {
				cnt--
			}
		}
		ans = append(ans, cnt)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class UnionFind {
    p: number[];
    size: number[];
    constructor(n: number) {
        this.p = Array(n)
            .fill(0)
            .map((_, i) => i);
        this.size = Array(n).fill(1);
    }

    find(x: number): number {
        if (this.p[x] !== x) {
            this.p[x] = this.find(this.p[x]);
        }
        return this.p[x];
    }

    union(a: number, b: number): boolean {
        const [pa, pb] = [this.find(a), this.find(b)];
        if (pa === pb) {
            return false;
        }
        if (this.size[pa] > this.size[pb]) {
            this.p[pb] = pa;
            this.size[pa] += this.size[pb];
        } else {
            this.p[pa] = pb;
            this.size[pb] += this.size[pa];
        }
        return true;
    }
}

function numIslands2(m: number, n: number, positions: number[][]): number[] {
    const grid: number[][] = Array.from({ length: m }, () => Array(n).fill(0));
    const uf = new UnionFind(m * n);
    const ans: number[] = [];
    const dirs: number[] = [-1, 0, 1, 0, -1];
    let cnt = 0;
    for (const [i, j] of positions) {
        if (grid[i][j]) {
            ans.push(cnt);
            continue;
        }
        grid[i][j] = 1;
        ++cnt;
        for (let k = 0; k < 4; ++k) {
            const [x, y] = [i + dirs[k], j + dirs[k + 1]];
            if (x < 0 || x >= m || y < 0 || y >= n || !grid[x][y]) {
                continue;
            }
            if (uf.union(i * n + j, x * n + y)) {
                --cnt;
            }
        }
        ans.push(cnt);
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

<p>给你一个大小为 <code>m x n</code> 的二维二进制网格 <code>grid</code> 。网格表示一个地图，其中，<code>0</code> 表示水，<code>1</code> 表示陆地。最初，<code>grid</code> 中的所有单元格都是水单元格（即，所有单元格都是 <code>0</code>）。</p>

<p>可以通过执行 <code>addLand</code> 操作，将某个位置的水转换成陆地。给你一个数组 <code>positions</code> ，其中 <code>positions[i] = [r<sub>i</sub>, c<sub>i</sub>]</code> 是要执行第 <code>i</code> 次操作的位置 <code>(r<sub>i</sub>, c<sub>i</sub>)</code> 。</p>

<p>返回一个整数数组 <code>answer</code> ，其中 <code>answer[i]</code> 是将单元格 <code>(r<sub>i</sub>, c<sub>i</sub>)</code> 转换为陆地后，地图中岛屿的数量。</p>

<p><strong>岛屿</strong> 的定义是被「水」包围的「陆地」，通过水平方向或者垂直方向上相邻的陆地连接而成。你可以假设地图网格的四边均被无边无际的「水」所包围。</p>
&nbsp;

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0300-0399/0305.Number%20of%20Islands%20II/images/tmp-grid.jpg" style="width: 500px; height: 294px;" />
<pre>
<strong>输入：</strong>m = 3, n = 3, positions = [[0,0],[0,1],[1,2],[2,1]]
<strong>输出：</strong>[1,1,2,3]
<strong>解释：</strong>
起初，二维网格&nbsp;<code>grid</code>&nbsp;被全部注入「水」。（0 代表「水」，1 代表「陆地」）
- 操作&nbsp;#1：<code>addLand(0, 0)</code> 将&nbsp;<code>grid[0][0]</code> 的水变为陆地。此时存在 1 个岛屿。
- 操作&nbsp;#2：<code>addLand(0, 1)</code> 将&nbsp;<code>grid[0][1]</code> 的水变为陆地。此时存在 1 个岛屿。
- 操作&nbsp;#3：<code>addLand(1, 2)</code> 将&nbsp;<code>grid[1][2]</code> 的水变为陆地。此时存在 2 个岛屿。
- 操作&nbsp;#4：<code>addLand(2, 1)</code> 将&nbsp;<code>grid[2][1]</code> 的水变为陆地。此时存在 3 个岛屿。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>m = 1, n = 1, positions = [[0,0]]
<strong>输出：</strong>[1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= m, n, positions.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>4</sup></code></li>
	<li><code>positions[i].length == 2</code></li>
	<li><code>0 &lt;= r<sub>i</sub> &lt; m</code></li>
	<li><code>0 &lt;= c<sub>i</sub> &lt; n</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你可以设计一个时间复杂度 <code>O(k log(mn))</code> 的算法解决此问题吗？（其中 <code>k == positions.length</code>）</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：并查集

我们用一个二维数组 $grid$ 来表示一个地图，其中 $0$ 和 $1$ 分别表示水和陆地。初始时 $grid$ 中的所有单元格都是水单元格（即所有单元格都是 $0$），用一个变量 $cnt$ 来记录岛屿的数量。而岛屿之间的连通关系可以用一个并查集 $uf$ 来维护。

接下来，我们遍历数组 $positions$ 中的每个位置 $(i, j)$，如果 $grid[i][j]$ 为 $1$，说明该位置已经是陆地，我们直接将 $cnt$ 添加到答案中；否则，我们将 $grid[i][j]$ 的值改为 $1$，并且将 $cnt$ 的值增加 $1$。然后，我们遍历该位置的上下左右四个方向，如果某个方向的位置为 $1$，并且该位置与 $(i, j)$ 不属于同一个连通分量，那么我们就将该位置与 $(i, j)$ 进行合并，同时将 $cnt$ 的值减少 $1$。遍历完该位置的上下左右四个方向之后，我们将 $cnt$ 添加到答案中。

时间复杂度 $O(k \times \alpha(m \times n))$ 或 $O(k \times \log(m \times n))$，其中 $k$ 是 $positions$ 的长度，而 $\alpha$ 是阿克曼函数的反函数，本题中 $\alpha(m \times n)$ 可以认为是一个很小的常数。

<!-- tabs:start -->

#### Python3

```python
class UnionFind:
    def __init__(self, n: int):
        self.p = list(range(n))
        self.size = [1] * n

    def find(self, x: int):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, a: int, b: int) -> bool:
        pa, pb = self.find(a - 1), self.find(b - 1)
        if pa == pb:
            return False
        if self.size[pa] > self.size[pb]:
            self.p[pb] = pa
            self.size[pa] += self.size[pb]
        else:
            self.p[pa] = pb
            self.size[pb] += self.size[pa]
        return True


class Solution:
    def numIslands2(self, m: int, n: int, positions: List[List[int]]) -> List[int]:
        uf = UnionFind(m * n)
        grid = [[0] * n for _ in range(m)]
        ans = []
        dirs = (-1, 0, 1, 0, -1)
        cnt = 0
        for i, j in positions:
            if grid[i][j]:
                ans.append(cnt)
                continue
            grid[i][j] = 1
            cnt += 1
            for a, b in pairwise(dirs):
                x, y = i + a, j + b
                if (
                    0 <= x < m
                    and 0 <= y < n
                    and grid[x][y]
                    and uf.union(i * n + j, x * n + y)
                ):
                    cnt -= 1
            ans.append(cnt)
        return ans
```

#### Java

```java
class UnionFind {
    private final int[] p;
    private final int[] size;

    public UnionFind(int n) {
        p = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            size[i] = 1;
        }
    }

    public int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    public boolean union(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }
}

class Solution {
    public List<Integer> numIslands2(int m, int n, int[][] positions) {
        int[][] grid = new int[m][n];
        UnionFind uf = new UnionFind(m * n);
        int[] dirs = {-1, 0, 1, 0, -1};
        int cnt = 0;
        List<Integer> ans = new ArrayList<>();
        for (var p : positions) {
            int i = p[0], j = p[1];
            if (grid[i][j] == 1) {
                ans.add(cnt);
                continue;
            }
            grid[i][j] = 1;
            ++cnt;
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1
                    && uf.union(i * n + j, x * n + y)) {
                    --cnt;
                }
            }
            ans.add(cnt);
        }
        return ans;
    }
}
```

#### C++

```cpp
class UnionFind {
public:
    UnionFind(int n) {
        p = vector<int>(n);
        size = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    bool unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

private:
    vector<int> p, size;
};

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        int grid[m][n];
        memset(grid, 0, sizeof(grid));
        UnionFind uf(m * n);
        int dirs[5] = {-1, 0, 1, 0, -1};
        int cnt = 0;
        vector<int> ans;
        for (auto& p : positions) {
            int i = p[0], j = p[1];
            if (grid[i][j]) {
                ans.push_back(cnt);
                continue;
            }
            grid[i][j] = 1;
            ++cnt;
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] && uf.unite(i * n + j, x * n + y)) {
                    --cnt;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
```

#### Go

```go
type unionFind struct {
	p, size []int
}

func newUnionFind(n int) *unionFind {
	p := make([]int, n)
	size := make([]int, n)
	for i := range p {
		p[i] = i
		size[i] = 1
	}
	return &unionFind{p, size}
}

func (uf *unionFind) find(x int) int {
	if uf.p[x] != x {
		uf.p[x] = uf.find(uf.p[x])
	}
	return uf.p[x]
}

func (uf *unionFind) union(a, b int) bool {
	pa, pb := uf.find(a), uf.find(b)
	if pa == pb {
		return false
	}
	if uf.size[pa] > uf.size[pb] {
		uf.p[pb] = pa
		uf.size[pa] += uf.size[pb]
	} else {
		uf.p[pa] = pb
		uf.size[pb] += uf.size[pa]
	}
	return true
}

func numIslands2(m int, n int, positions [][]int) (ans []int) {
	uf := newUnionFind(m * n)
	grid := make([][]int, m)
	for i := range grid {
		grid[i] = make([]int, n)
	}
	dirs := [5]int{-1, 0, 1, 0, -1}
	cnt := 0
	for _, p := range positions {
		i, j := p[0], p[1]
		if grid[i][j] == 1 {
			ans = append(ans, cnt)
			continue
		}
		grid[i][j] = 1
		cnt++
		for k := 0; k < 4; k++ {
			x, y := i+dirs[k], j+dirs[k+1]
			if x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1 && uf.union(i*n+j, x*n+y) {
				cnt--
			}
		}
		ans = append(ans, cnt)
	}
	return
}
```

#### TypeScript

```ts
class UnionFind {
    p: number[];
    size: number[];
    constructor(n: number) {
        this.p = Array(n)
            .fill(0)
            .map((_, i) => i);
        this.size = Array(n).fill(1);
    }

    find(x: number): number {
        if (this.p[x] !== x) {
            this.p[x] = this.find(this.p[x]);
        }
        return this.p[x];
    }

    union(a: number, b: number): boolean {
        const [pa, pb] = [this.find(a), this.find(b)];
        if (pa === pb) {
            return false;
        }
        if (this.size[pa] > this.size[pb]) {
            this.p[pb] = pa;
            this.size[pa] += this.size[pb];
        } else {
            this.p[pa] = pb;
            this.size[pb] += this.size[pa];
        }
        return true;
    }
}

function numIslands2(m: number, n: number, positions: number[][]): number[] {
    const grid: number[][] = Array.from({ length: m }, () => Array(n).fill(0));
    const uf = new UnionFind(m * n);
    const ans: number[] = [];
    const dirs: number[] = [-1, 0, 1, 0, -1];
    let cnt = 0;
    for (const [i, j] of positions) {
        if (grid[i][j]) {
            ans.push(cnt);
            continue;
        }
        grid[i][j] = 1;
        ++cnt;
        for (let k = 0; k < 4; ++k) {
            const [x, y] = [i + dirs[k], j + dirs[k + 1]];
            if (x < 0 || x >= m || y < 0 || y >= n || !grid[x][y]) {
                continue;
            }
            if (uf.union(i * n + j, x * n + y)) {
                --cnt;
            }
        }
        ans.push(cnt);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [306. 累加数](https://leetcode.cn/problems/additive-number){#306}

{{< tabs "306" >}}

{{% tab "python" %}}
```python
class Solution:
    def isAdditiveNumber(self, num: str) -> bool:
        def dfs(a, b, num):
            if not num:
                return True
            if a + b > 0 and num[0] == '0':
                return False
            for i in range(1, len(num) + 1):
                if a + b == int(num[:i]):
                    if dfs(b, a + b, num[i:]):
                        return True
            return False

        n = len(num)
        for i in range(1, n - 1):
            for j in range(i + 1, n):
                if i > 1 and num[0] == '0':
                    break
                if j - i > 1 and num[i] == '0':
                    continue
                if dfs(int(num[:i]), int(num[i:j]), num[j:]):
                    return True
        return False
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isAdditiveNumber(String num) {
        int n = num.length();
        for (int i = 1; i < Math.min(n - 1, 19); ++i) {
            for (int j = i + 1; j < Math.min(n, i + 19); ++j) {
                if (i > 1 && num.charAt(0) == '0') {
                    break;
                }
                if (j - i > 1 && num.charAt(i) == '0') {
                    continue;
                }
                long a = Long.parseLong(num.substring(0, i));
                long b = Long.parseLong(num.substring(i, j));
                if (dfs(a, b, num.substring(j))) {
                    return true;
                }
            }
        }
        return false;
    }

    private boolean dfs(long a, long b, String num) {
        if ("".equals(num)) {
            return true;
        }
        if (a + b > 0 && num.charAt(0) == '0') {
            return false;
        }
        for (int i = 1; i < Math.min(num.length() + 1, 19); ++i) {
            if (a + b == Long.parseLong(num.substring(0, i))) {
                if (dfs(b, a + b, num.substring(i))) {
                    return true;
                }
            }
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
    bool isAdditiveNumber(string num) {
        int n = num.size();
        for (int i = 1; i < min(n - 1, 19); ++i) {
            for (int j = i + 1; j < min(n, i + 19); ++j) {
                if (i > 1 && num[0] == '0') break;
                if (j - i > 1 && num[i] == '0') continue;
                auto a = stoll(num.substr(0, i));
                auto b = stoll(num.substr(i, j - i));
                if (dfs(a, b, num.substr(j, n - j))) return true;
            }
        }
        return false;
    }

    bool dfs(long long a, long long b, string num) {
        if (num == "") return true;
        if (a + b > 0 && num[0] == '0') return false;
        for (int i = 1; i < min((int) num.size() + 1, 19); ++i)
            if (a + b == stoll(num.substr(0, i)))
                if (dfs(b, a + b, num.substr(i, num.size() - i)))
                    return true;
        return false;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isAdditiveNumber(num string) bool {
	n := len(num)
	var dfs func(a, b int64, num string) bool
	dfs = func(a, b int64, num string) bool {
		if num == "" {
			return true
		}
		if a+b > 0 && num[0] == '0' {
			return false
		}
		for i := 1; i < min(len(num)+1, 19); i++ {
			c, _ := strconv.ParseInt(num[:i], 10, 64)
			if a+b == c {
				if dfs(b, c, num[i:]) {
					return true
				}
			}
		}
		return false
	}
	for i := 1; i < min(n-1, 19); i++ {
		for j := i + 1; j < min(n, i+19); j++ {
			if i > 1 && num[0] == '0' {
				break
			}
			if j-i > 1 && num[i] == '0' {
				continue
			}
			a, _ := strconv.ParseInt(num[:i], 10, 64)
			b, _ := strconv.ParseInt(num[i:j], 10, 64)
			if dfs(a, b, num[j:]) {
				return true
			}
		}
	}
	return false
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><strong>累加数</strong> 是一个字符串，组成它的数字可以形成累加序列。</p>

<p>一个有效的 <strong>累加序列</strong> 必须<strong> 至少 </strong>包含 3 个数。除了最开始的两个数以外，序列中的每个后续数字必须是它之前两个数字之和。</p>

<p>给你一个只包含数字&nbsp;<code>'0'-'9'</code>&nbsp;的字符串，编写一个算法来判断给定输入是否是 <strong>累加数</strong> 。如果是，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p><strong>说明：</strong>累加序列里的数，除数字 0 之外，<strong>不会</strong> 以 0 开头，所以不会出现&nbsp;<code>1, 2, 03</code> 或者&nbsp;<code>1, 02, 3</code>&nbsp;的情况。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong><code>"112358"</code>
<strong>输出：</strong>true 
<strong>解释：</strong>累加序列为: <code>1, 1, 2, 3, 5, 8 </code>。1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
</pre>

<p><strong>示例&nbsp;2：</strong></p>

<pre>
<strong>输入<code>：</code></strong><code>"199100199"</code>
<strong>输出：</strong>true 
<strong>解释：</strong>累加序列为: <code>1, 99, 100, 199。</code>1 + 99 = 100, 99 + 100 = 199</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num.length &lt;= 35</code></li>
	<li><code>num</code> 仅由数字（<code>0</code> - <code>9</code>）组成</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你计划如何处理由过大的整数输入导致的溢出?</p>

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
    def isAdditiveNumber(self, num: str) -> bool:
        def dfs(a, b, num):
            if not num:
                return True
            if a + b > 0 and num[0] == '0':
                return False
            for i in range(1, len(num) + 1):
                if a + b == int(num[:i]):
                    if dfs(b, a + b, num[i:]):
                        return True
            return False

        n = len(num)
        for i in range(1, n - 1):
            for j in range(i + 1, n):
                if i > 1 and num[0] == '0':
                    break
                if j - i > 1 and num[i] == '0':
                    continue
                if dfs(int(num[:i]), int(num[i:j]), num[j:]):
                    return True
        return False
```

#### Java

```java
class Solution {
    public boolean isAdditiveNumber(String num) {
        int n = num.length();
        for (int i = 1; i < Math.min(n - 1, 19); ++i) {
            for (int j = i + 1; j < Math.min(n, i + 19); ++j) {
                if (i > 1 && num.charAt(0) == '0') {
                    break;
                }
                if (j - i > 1 && num.charAt(i) == '0') {
                    continue;
                }
                long a = Long.parseLong(num.substring(0, i));
                long b = Long.parseLong(num.substring(i, j));
                if (dfs(a, b, num.substring(j))) {
                    return true;
                }
            }
        }
        return false;
    }

    private boolean dfs(long a, long b, String num) {
        if ("".equals(num)) {
            return true;
        }
        if (a + b > 0 && num.charAt(0) == '0') {
            return false;
        }
        for (int i = 1; i < Math.min(num.length() + 1, 19); ++i) {
            if (a + b == Long.parseLong(num.substring(0, i))) {
                if (dfs(b, a + b, num.substring(i))) {
                    return true;
                }
            }
        }
        return false;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        for (int i = 1; i < min(n - 1, 19); ++i) {
            for (int j = i + 1; j < min(n, i + 19); ++j) {
                if (i > 1 && num[0] == '0') break;
                if (j - i > 1 && num[i] == '0') continue;
                auto a = stoll(num.substr(0, i));
                auto b = stoll(num.substr(i, j - i));
                if (dfs(a, b, num.substr(j, n - j))) return true;
            }
        }
        return false;
    }

    bool dfs(long long a, long long b, string num) {
        if (num == "") return true;
        if (a + b > 0 && num[0] == '0') return false;
        for (int i = 1; i < min((int) num.size() + 1, 19); ++i)
            if (a + b == stoll(num.substr(0, i)))
                if (dfs(b, a + b, num.substr(i, num.size() - i)))
                    return true;
        return false;
    }
};
```

#### Go

```go
func isAdditiveNumber(num string) bool {
	n := len(num)
	var dfs func(a, b int64, num string) bool
	dfs = func(a, b int64, num string) bool {
		if num == "" {
			return true
		}
		if a+b > 0 && num[0] == '0' {
			return false
		}
		for i := 1; i < min(len(num)+1, 19); i++ {
			c, _ := strconv.ParseInt(num[:i], 10, 64)
			if a+b == c {
				if dfs(b, c, num[i:]) {
					return true
				}
			}
		}
		return false
	}
	for i := 1; i < min(n-1, 19); i++ {
		for j := i + 1; j < min(n, i+19); j++ {
			if i > 1 && num[0] == '0' {
				break
			}
			if j-i > 1 && num[i] == '0' {
				continue
			}
			a, _ := strconv.ParseInt(num[:i], 10, 64)
			b, _ := strconv.ParseInt(num[i:j], 10, 64)
			if dfs(a, b, num[j:]) {
				return true
			}
		}
	}
	return false
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [307. 区域和检索 - 数组可修改](https://leetcode.cn/problems/range-sum-query-mutable){#307}

{{< tabs "307" >}}

{{% tab "python" %}}
```python
class Node:
    __slots__ = ["l", "r", "v"]

    def __init__(self):
        self.l = self.r = self.v = 0


class SegmentTree:
    __slots__ = ["nums", "tr"]

    def __init__(self, nums):
        self.nums = nums
        n = len(nums)
        self.tr = [Node() for _ in range(n << 2)]
        self.build(1, 1, n)

    def build(self, u, l, r):
        self.tr[u].l, self.tr[u].r = l, r
        if l == r:
            self.tr[u].v = self.nums[l - 1]
            return
        mid = (l + r) >> 1
        self.build(u << 1, l, mid)
        self.build(u << 1 | 1, mid + 1, r)
        self.pushup(u)

    def modify(self, u, x, v):
        if self.tr[u].l == x and self.tr[u].r == x:
            self.tr[u].v = v
            return
        mid = (self.tr[u].l + self.tr[u].r) >> 1
        if x <= mid:
            self.modify(u << 1, x, v)
        else:
            self.modify(u << 1 | 1, x, v)
        self.pushup(u)

    def query(self, u, l, r):
        if self.tr[u].l >= l and self.tr[u].r <= r:
            return self.tr[u].v
        mid = (self.tr[u].l + self.tr[u].r) >> 1
        result = 0
        if l <= mid:
            result += self.query(u << 1, l, r)
        if r > mid:
            result += self.query(u << 1 | 1, l, r)
        return result

    def pushup(self, u):
        self.tr[u].v = self.tr[u << 1].v + self.tr[u << 1 | 1].v


class NumArray:
    __slots__ = ["tree"]

    def __init__(self, nums: List[int]):
        self.tree = SegmentTree(nums)

    def update(self, index: int, val: int) -> None:
        self.tree.modify(1, index + 1, val)

    def sumRange(self, left: int, right: int) -> int:
        return self.tree.query(1, left + 1, right + 1)


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(index,val)
# param_2 = obj.sumRange(left,right)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Node {
    int l;
    int r;
    int v;
}

class SegmentTree {
    private Node[] tr;
    private int[] nums;

    public SegmentTree(int[] nums) {
        this.nums = nums;
        int n = nums.length;
        tr = new Node[n << 2];
        for (int i = 0; i < tr.length; ++i) {
            tr[i] = new Node();
        }
        build(1, 1, n);
    }

    public void build(int u, int l, int r) {
        tr[u].l = l;
        tr[u].r = r;
        if (l == r) {
            tr[u].v = nums[l - 1];
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }

    public void modify(int u, int x, int v) {
        if (tr[u].l == x && tr[u].r == x) {
            tr[u].v = v;
            return;
        }
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (x <= mid) {
            modify(u << 1, x, v);
        } else {
            modify(u << 1 | 1, x, v);
        }
        pushup(u);
    }

    public int query(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) {
            return tr[u].v;
        }
        int mid = (tr[u].l + tr[u].r) >> 1;
        int v = 0;
        if (l <= mid) {
            v += query(u << 1, l, r);
        }
        if (r > mid) {
            v += query(u << 1 | 1, l, r);
        }
        return v;
    }

    public void pushup(int u) {
        tr[u].v = tr[u << 1].v + tr[u << 1 | 1].v;
    }
}

class NumArray {
    private SegmentTree tree;

    public NumArray(int[] nums) {
        tree = new SegmentTree(nums);
    }

    public void update(int index, int val) {
        tree.modify(1, index + 1, val);
    }

    public int sumRange(int left, int right) {
        return tree.query(1, left + 1, right + 1);
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(index,val);
 * int param_2 = obj.sumRange(left,right);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Node {
public:
    int l;
    int r;
    int v;
};

class SegmentTree {
public:
    vector<Node*> tr;
    vector<int> nums;

    SegmentTree(vector<int>& nums) {
        this->nums = nums;
        int n = nums.size();
        tr.resize(n << 2);
        for (int i = 0; i < tr.size(); ++i) tr[i] = new Node();
        build(1, 1, n);
    }

    void build(int u, int l, int r) {
        tr[u]->l = l;
        tr[u]->r = r;
        if (l == r) {
            tr[u]->v = nums[l - 1];
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }

    void modify(int u, int x, int v) {
        if (tr[u]->l == x && tr[u]->r == x) {
            tr[u]->v = v;
            return;
        }
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        if (x <= mid)
            modify(u << 1, x, v);
        else
            modify(u << 1 | 1, x, v);
        pushup(u);
    }

    int query(int u, int l, int r) {
        if (tr[u]->l >= l && tr[u]->r <= r) return tr[u]->v;
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        int v = 0;
        if (l <= mid) v += query(u << 1, l, r);
        if (r > mid) v += query(u << 1 | 1, l, r);
        return v;
    }

    void pushup(int u) {
        tr[u]->v = tr[u << 1]->v + tr[u << 1 | 1]->v;
    }
};

class NumArray {
public:
    SegmentTree* tree;

    NumArray(vector<int>& nums) {
        tree = new SegmentTree(nums);
    }

    void update(int index, int val) {
        return tree->modify(1, index + 1, val);
    }

    int sumRange(int left, int right) {
        return tree->query(1, left + 1, right + 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Node struct {
	l, r, v int
}

type SegmentTree struct {
	tr   []Node
	nums []int
}

func newSegmentTree(nums []int) *SegmentTree {
	n := len(nums)
	tr := make([]Node, n<<2)
	for i := range tr {
		tr[i] = Node{}
	}
	tree := &SegmentTree{
		tr:   tr,
		nums: nums,
	}
	tree.build(1, 1, n)
	return tree
}

func (tree *SegmentTree) build(u, l, r int) {
	tree.tr[u].l, tree.tr[u].r = l, r
	if l == r {
		tree.tr[u].v = tree.nums[l-1]
		return
	}
	mid := (l + r) >> 1
	tree.build(u<<1, l, mid)
	tree.build(u<<1|1, mid+1, r)
	tree.pushup(u)
}

func (tree *SegmentTree) modify(u, x, v int) {
	if tree.tr[u].l == x && tree.tr[u].r == x {
		tree.tr[u].v = v
		return
	}
	mid := (tree.tr[u].l + tree.tr[u].r) >> 1
	if x <= mid {
		tree.modify(u<<1, x, v)
	} else {
		tree.modify(u<<1|1, x, v)
	}
	tree.pushup(u)
}

func (tree *SegmentTree) query(u, l, r int) (v int) {
	if tree.tr[u].l >= l && tree.tr[u].r <= r {
		return tree.tr[u].v
	}
	mid := (tree.tr[u].l + tree.tr[u].r) >> 1
	if l <= mid {
		v += tree.query(u<<1, l, r)
	}
	if r > mid {
		v += tree.query(u<<1|1, l, r)
	}
	return v
}

func (tree *SegmentTree) pushup(u int) {
	tree.tr[u].v = tree.tr[u<<1].v + tree.tr[u<<1|1].v
}

type NumArray struct {
	tree *SegmentTree
}

func Constructor(nums []int) NumArray {
	return NumArray{
		tree: newSegmentTree(nums),
	}
}

func (this *NumArray) Update(index int, val int) {
	this.tree.modify(1, index+1, val)
}

func (this *NumArray) SumRange(left int, right int) int {
	return this.tree.query(1, left+1, right+1)
}

/**
 * Your NumArray object will be instantiated and called as such:
 * obj := Constructor(nums);
 * obj.Update(index,val);
 * param_2 := obj.SumRange(left,right);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class Node {
    l: number;
    r: number;
    v: number;
}

class SegmentTree {
    private tr: Node[];
    private nums: number[];

    constructor(nums: number[]) {
        this.nums = nums;
        const n = nums.length;
        this.tr = new Array<Node>(n << 2);
        for (let i = 0; i < this.tr.length; ++i) {
            this.tr[i] = { l: 0, r: 0, v: 0 };
        }
        this.build(1, 1, n);
    }

    build(u: number, l: number, r: number): void {
        this.tr[u].l = l;
        this.tr[u].r = r;
        if (l == r) {
            this.tr[u].v = this.nums[l - 1];
            return;
        }
        const mid = (l + r) >> 1;
        this.build(u << 1, l, mid);
        this.build((u << 1) | 1, mid + 1, r);
        this.pushup(u);
    }

    modify(u: number, x: number, v: number): void {
        if (this.tr[u].l == x && this.tr[u].r == x) {
            this.tr[u].v = v;
            return;
        }
        const mid = (this.tr[u].l + this.tr[u].r) >> 1;
        if (x <= mid) {
            this.modify(u << 1, x, v);
        } else {
            this.modify((u << 1) | 1, x, v);
        }
        this.pushup(u);
    }

    query(u: number, l: number, r: number): number {
        if (this.tr[u].l >= l && this.tr[u].r <= r) {
            return this.tr[u].v;
        }
        const mid = (this.tr[u].l + this.tr[u].r) >> 1;
        let v = 0;
        if (l <= mid) {
            v += this.query(u << 1, l, r);
        }
        if (r > mid) {
            v += this.query((u << 1) | 1, l, r);
        }
        return v;
    }

    pushup(u: number): void {
        this.tr[u].v = this.tr[u << 1].v + this.tr[(u << 1) | 1].v;
    }
}

class NumArray {
    private tree: SegmentTree;

    constructor(nums: number[]) {
        this.tree = new SegmentTree(nums);
    }

    update(index: number, val: number): void {
        this.tree.modify(1, index + 1, val);
    }

    sumRange(left: number, right: number): number {
        return this.tree.query(1, left + 1, right + 1);
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * var obj = new NumArray(nums)
 * obj.update(index,val)
 * var param_2 = obj.sumRange(left,right)
 */
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Node {
    public int l;
    public int r;
    public int v;
}

public class SegmentTree {
    private Node[] tr;
    private int[] nums;

    public SegmentTree(int[] nums) {
        this.nums = nums;
        int n = nums.Length;
        tr = new Node[n << 2];
        for (int i = 0; i < tr.Length; ++i) {
            tr[i] = new Node();
        }
        Build(1, 1, n);
    }

    public void Build(int u, int l, int r) {
        tr[u].l = l;
        tr[u].r = r;
        if (l == r) {
            tr[u].v = nums[l - 1];
            return;
        }
        int mid = (l + r) >> 1;
        Build(u << 1, l, mid);
        Build(u << 1 | 1, mid + 1, r);
        Pushup(u);
    }

    public void Modify(int u, int x, int v) {
        if (tr[u].l == x && tr[u].r == x) {
            tr[u].v = v;
            return;
        }
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (x <= mid) {
            Modify(u << 1, x, v);
        } else {
            Modify(u << 1 | 1, x, v);
        }
        Pushup(u);
    }

    public int Query(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) {
            return tr[u].v;
        }
        int mid = (tr[u].l + tr[u].r) >> 1;
        int v = 0;
        if (l <= mid) {
            v += Query(u << 1, l, r);
        }
        if (r > mid) {
            v += Query(u << 1 | 1, l, r);
        }
        return v;
    }

    public void Pushup(int u) {
        tr[u].v = tr[u << 1].v + tr[u << 1 | 1].v;
    }
}

public class NumArray {
    private SegmentTree tree;

    public NumArray(int[] nums) {
        tree = new SegmentTree(nums);
    }

    public void Update(int index, int val) {
        tree.Modify(1, index + 1, val);
    }

    public int SumRange(int left, int right) {
        return tree.Query(1, left + 1, right + 1);
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.Update(index,val);
 * int param_2 = obj.SumRange(left,right);
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个数组 <code>nums</code> ，请你完成两类查询。</p>

<ol>
	<li>其中一类查询要求 <strong>更新</strong> 数组&nbsp;<code>nums</code>&nbsp;下标对应的值</li>
	<li>另一类查询要求返回数组&nbsp;<code>nums</code>&nbsp;中索引&nbsp;<code>left</code>&nbsp;和索引&nbsp;<code>right</code>&nbsp;之间（&nbsp;<strong>包含&nbsp;</strong>）的nums元素的 <strong>和</strong>&nbsp;，其中&nbsp;<code>left &lt;= right</code></li>
</ol>

<p>实现 <code>NumArray</code> 类：</p>

<ul>
	<li><code>NumArray(int[] nums)</code> 用整数数组 <code>nums</code> 初始化对象</li>
	<li><code>void update(int index, int val)</code> 将 <code>nums[index]</code> 的值 <strong>更新</strong> 为 <code>val</code></li>
	<li><code>int sumRange(int left, int right)</code> 返回数组&nbsp;<code>nums</code>&nbsp;中索引&nbsp;<code>left</code>&nbsp;和索引&nbsp;<code>right</code>&nbsp;之间（&nbsp;<strong>包含&nbsp;</strong>）的nums元素的 <strong>和</strong>&nbsp;（即，<code>nums[left] + nums[left + 1], ..., nums[right]</code>）</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入</strong>：
["NumArray", "sumRange", "update", "sumRange"]
[[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
<strong>输出</strong>：
[null, 9, null, 8]

<strong>解释</strong>：
NumArray numArray = new NumArray([1, 3, 5]);
numArray.sumRange(0, 2); // 返回 1 + 3 + 5 = 9
numArray.update(1, 2);   // nums = [1,2,5]
numArray.sumRange(0, 2); // 返回 1 + 2 + 5 = 8
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 3 *&nbsp;10<sup>4</sup></code></li>
	<li><code>-100 &lt;= nums[i] &lt;= 100</code></li>
	<li><code>0 &lt;= index &lt; nums.length</code></li>
	<li><code>-100 &lt;= val &lt;= 100</code></li>
	<li><code>0 &lt;= left &lt;= right &lt; nums.length</code></li>
	<li>调用 <code>update</code> 和 <code>sumRange</code> 方法次数不大于&nbsp;<code>3 * 10<sup>4</sup></code>&nbsp;</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：树状数组

树状数组，也称作“二叉索引树”（Binary Indexed Tree）或 Fenwick 树。 它可以高效地实现如下两个操作：

1. **单点更新** $update(x, delta)$： 把序列 $x$ 位置的数加上一个值 $delta$；
1. **前缀和查询** $query(x)$：查询序列 $[1,...x]$ 区间的区间和，即位置 $x$ 的前缀和。

这两个操作的时间复杂度均为 $O(\log n)$。

树状数组最基本的功能就是求比某点 $x$ 小的点的个数（这里的比较是抽象的概念，可以是数的大小、坐标的大小、质量的大小等等）。

对于本题，我们在构造函数中，先创建一个树状数组，然后遍历数组中每个元素的下标 $i$（从 $1$ 开始）和对应的值 $v$，调用 $update(i, v)$，即可完成树状数组的初始化。时间复杂度为 $O(n \log n)$。

对于 $sumRange(left, right)$，我们可以通过 $query(right + 1) - query(left)$ 得到区间和。时间复杂度为 $O(\log n)$。

对于 $update(index, val)$，我们可以先通过 $sumRange(index, index)$ 得到原来的值 $prev$，然后调用 $update(index, val - prev)$，即可完成更新。时间复杂度为 $O(\log n)$。

空间复杂度为 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class BinaryIndexedTree:
    __slots__ = ["n", "c"]

    def __init__(self, n):
        self.n = n
        self.c = [0] * (n + 1)

    def update(self, x: int, delta: int):
        while x <= self.n:
            self.c[x] += delta
            x += x & -x

    def query(self, x: int) -> int:
        s = 0
        while x > 0:
            s += self.c[x]
            x -= x & -x
        return s


class NumArray:
    __slots__ = ["tree"]

    def __init__(self, nums: List[int]):
        self.tree = BinaryIndexedTree(len(nums))
        for i, v in enumerate(nums, 1):
            self.tree.update(i, v)

    def update(self, index: int, val: int) -> None:
        prev = self.sumRange(index, index)
        self.tree.update(index + 1, val - prev)

    def sumRange(self, left: int, right: int) -> int:
        return self.tree.query(right + 1) - self.tree.query(left)


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(index,val)
# param_2 = obj.sumRange(left,right)
```

#### Java

```java
class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        c = new int[n + 1];
    }

    public void update(int x, int delta) {
        while (x <= n) {
            c[x] += delta;
            x += x & -x;
        }
    }

    public int query(int x) {
        int s = 0;
        while (x > 0) {
            s += c[x];
            x -= x & -x;
        }
        return s;
    }
}

class NumArray {
    private BinaryIndexedTree tree;

    public NumArray(int[] nums) {
        int n = nums.length;
        tree = new BinaryIndexedTree(n);
        for (int i = 0; i < n; ++i) {
            tree.update(i + 1, nums[i]);
        }
    }

    public void update(int index, int val) {
        int prev = sumRange(index, index);
        tree.update(index + 1, val - prev);
    }

    public int sumRange(int left, int right) {
        return tree.query(right + 1) - tree.query(left);
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(index,val);
 * int param_2 = obj.sumRange(left,right);
 */
```

#### C++

```cpp
class BinaryIndexedTree {
public:
    int n;
    vector<int> c;

    BinaryIndexedTree(int _n)
        : n(_n)
        , c(_n + 1) {}

    void update(int x, int delta) {
        while (x <= n) {
            c[x] += delta;
            x += x & -x;
        }
    }

    int query(int x) {
        int s = 0;
        while (x > 0) {
            s += c[x];
            x -= x & -x;
        }
        return s;
    }
};

class NumArray {
public:
    BinaryIndexedTree* tree;

    NumArray(vector<int>& nums) {
        int n = nums.size();
        tree = new BinaryIndexedTree(n);
        for (int i = 0; i < n; ++i) tree->update(i + 1, nums[i]);
    }

    void update(int index, int val) {
        int prev = sumRange(index, index);
        tree->update(index + 1, val - prev);
    }

    int sumRange(int left, int right) {
        return tree->query(right + 1) - tree->query(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
```

#### Go

```go
type BinaryIndexedTree struct {
	n int
	c []int
}

func newBinaryIndexedTree(n int) *BinaryIndexedTree {
	c := make([]int, n+1)
	return &BinaryIndexedTree{n, c}
}

func (t *BinaryIndexedTree) update(x, delta int) {
	for ; x <= t.n; x += x & -x {
		t.c[x] += delta
	}
}

func (t *BinaryIndexedTree) query(x int) (s int) {
	for ; x > 0; x -= x & -x {
		s += t.c[x]
	}
	return s
}

type NumArray struct {
	tree *BinaryIndexedTree
}

func Constructor(nums []int) NumArray {
	tree := newBinaryIndexedTree(len(nums))
	for i, v := range nums {
		tree.update(i+1, v)
	}
	return NumArray{tree}
}

func (t *NumArray) Update(index int, val int) {
	prev := t.SumRange(index, index)
	t.tree.update(index+1, val-prev)
}

func (t *NumArray) SumRange(left int, right int) int {
	return t.tree.query(right+1) - t.tree.query(left)
}

/**
 * Your NumArray object will be instantiated and called as such:
 * obj := Constructor(nums);
 * obj.Update(index,val);
 * param_2 := obj.SumRange(left,right);
 */
```

#### TypeScript

```ts
class BinaryIndexedTree {
    private n: number;
    private c: number[];

    constructor(n: number) {
        this.n = n;
        this.c = Array(n + 1).fill(0);
    }

    update(x: number, delta: number): void {
        while (x <= this.n) {
            this.c[x] += delta;
            x += x & -x;
        }
    }

    query(x: number): number {
        let s = 0;
        while (x > 0) {
            s += this.c[x];
            x -= x & -x;
        }
        return s;
    }
}

class NumArray {
    private tree: BinaryIndexedTree;

    constructor(nums: number[]) {
        const n = nums.length;
        this.tree = new BinaryIndexedTree(n);
        for (let i = 0; i < n; ++i) {
            this.tree.update(i + 1, nums[i]);
        }
    }

    update(index: number, val: number): void {
        const prev = this.sumRange(index, index);
        this.tree.update(index + 1, val - prev);
    }

    sumRange(left: number, right: number): number {
        return this.tree.query(right + 1) - this.tree.query(left);
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * var obj = new NumArray(nums)
 * obj.update(index,val)
 * var param_2 = obj.sumRange(left,right)
 */
```

#### C#

```cs
class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        c = new int[n + 1];
    }

    public void Update(int x, int delta) {
        while (x <= n) {
            c[x] += delta;
            x += x & -x;
        }
    }

    public int Query(int x) {
        int s = 0;
        while (x > 0) {
            s += c[x];
            x -= x & -x;
        }
        return s;
    }
}

public class NumArray {
    private BinaryIndexedTree tree;

    public NumArray(int[] nums) {
        int n = nums.Length;
        tree = new BinaryIndexedTree(n);
        for (int i = 0; i < n; ++i) {
            tree.Update(i + 1, nums[i]);
        }
    }

    public void Update(int index, int val) {
        int prev = SumRange(index, index);
        tree.Update(index + 1, val - prev);
    }

    public int SumRange(int left, int right) {
        return tree.Query(right + 1) - tree.Query(left);
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.Update(index,val);
 * int param_2 = obj.SumRange(left,right);
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：线段树

线段树将整个区间分割为多个不连续的子区间，子区间的数量不超过 $\log(width)$。更新某个元素的值，只需要更新 $\log(width)$ 个区间，并且这些区间都包含在一个包含该元素的大区间内。

-   线段树的每个节点代表一个区间；
-   线段树具有唯一的根节点，代表的区间是整个统计范围，如 $[1, N]$；
-   线段树的每个叶子节点代表一个长度为 $1$ 的元区间 $[x, x]$；
-   对于每个内部节点 $[l, r]$，它的左儿子是 $[l, mid]$，右儿子是 $[mid + 1, r]$, 其中 $mid = \lfloor \frac{l + r}{2} \rfloor$（即向下取整）。

对于本题，构造函数的时间复杂度为 $O(n \log n)$，其他操作的时间复杂度为 $O(\log n)$。空间复杂度为 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class Node:
    __slots__ = ["l", "r", "v"]

    def __init__(self):
        self.l = self.r = self.v = 0


class SegmentTree:
    __slots__ = ["nums", "tr"]

    def __init__(self, nums):
        self.nums = nums
        n = len(nums)
        self.tr = [Node() for _ in range(n << 2)]
        self.build(1, 1, n)

    def build(self, u, l, r):
        self.tr[u].l, self.tr[u].r = l, r
        if l == r:
            self.tr[u].v = self.nums[l - 1]
            return
        mid = (l + r) >> 1
        self.build(u << 1, l, mid)
        self.build(u << 1 | 1, mid + 1, r)
        self.pushup(u)

    def modify(self, u, x, v):
        if self.tr[u].l == x and self.tr[u].r == x:
            self.tr[u].v = v
            return
        mid = (self.tr[u].l + self.tr[u].r) >> 1
        if x <= mid:
            self.modify(u << 1, x, v)
        else:
            self.modify(u << 1 | 1, x, v)
        self.pushup(u)

    def query(self, u, l, r):
        if self.tr[u].l >= l and self.tr[u].r <= r:
            return self.tr[u].v
        mid = (self.tr[u].l + self.tr[u].r) >> 1
        result = 0
        if l <= mid:
            result += self.query(u << 1, l, r)
        if r > mid:
            result += self.query(u << 1 | 1, l, r)
        return result

    def pushup(self, u):
        self.tr[u].v = self.tr[u << 1].v + self.tr[u << 1 | 1].v


class NumArray:
    __slots__ = ["tree"]

    def __init__(self, nums: List[int]):
        self.tree = SegmentTree(nums)

    def update(self, index: int, val: int) -> None:
        self.tree.modify(1, index + 1, val)

    def sumRange(self, left: int, right: int) -> int:
        return self.tree.query(1, left + 1, right + 1)


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(index,val)
# param_2 = obj.sumRange(left,right)
```

#### Java

```java
class Node {
    int l;
    int r;
    int v;
}

class SegmentTree {
    private Node[] tr;
    private int[] nums;

    public SegmentTree(int[] nums) {
        this.nums = nums;
        int n = nums.length;
        tr = new Node[n << 2];
        for (int i = 0; i < tr.length; ++i) {
            tr[i] = new Node();
        }
        build(1, 1, n);
    }

    public void build(int u, int l, int r) {
        tr[u].l = l;
        tr[u].r = r;
        if (l == r) {
            tr[u].v = nums[l - 1];
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }

    public void modify(int u, int x, int v) {
        if (tr[u].l == x && tr[u].r == x) {
            tr[u].v = v;
            return;
        }
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (x <= mid) {
            modify(u << 1, x, v);
        } else {
            modify(u << 1 | 1, x, v);
        }
        pushup(u);
    }

    public int query(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) {
            return tr[u].v;
        }
        int mid = (tr[u].l + tr[u].r) >> 1;
        int v = 0;
        if (l <= mid) {
            v += query(u << 1, l, r);
        }
        if (r > mid) {
            v += query(u << 1 | 1, l, r);
        }
        return v;
    }

    public void pushup(int u) {
        tr[u].v = tr[u << 1].v + tr[u << 1 | 1].v;
    }
}

class NumArray {
    private SegmentTree tree;

    public NumArray(int[] nums) {
        tree = new SegmentTree(nums);
    }

    public void update(int index, int val) {
        tree.modify(1, index + 1, val);
    }

    public int sumRange(int left, int right) {
        return tree.query(1, left + 1, right + 1);
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(index,val);
 * int param_2 = obj.sumRange(left,right);
 */
```

#### C++

```cpp
class Node {
public:
    int l;
    int r;
    int v;
};

class SegmentTree {
public:
    vector<Node*> tr;
    vector<int> nums;

    SegmentTree(vector<int>& nums) {
        this->nums = nums;
        int n = nums.size();
        tr.resize(n << 2);
        for (int i = 0; i < tr.size(); ++i) tr[i] = new Node();
        build(1, 1, n);
    }

    void build(int u, int l, int r) {
        tr[u]->l = l;
        tr[u]->r = r;
        if (l == r) {
            tr[u]->v = nums[l - 1];
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }

    void modify(int u, int x, int v) {
        if (tr[u]->l == x && tr[u]->r == x) {
            tr[u]->v = v;
            return;
        }
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        if (x <= mid)
            modify(u << 1, x, v);
        else
            modify(u << 1 | 1, x, v);
        pushup(u);
    }

    int query(int u, int l, int r) {
        if (tr[u]->l >= l && tr[u]->r <= r) return tr[u]->v;
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        int v = 0;
        if (l <= mid) v += query(u << 1, l, r);
        if (r > mid) v += query(u << 1 | 1, l, r);
        return v;
    }

    void pushup(int u) {
        tr[u]->v = tr[u << 1]->v + tr[u << 1 | 1]->v;
    }
};

class NumArray {
public:
    SegmentTree* tree;

    NumArray(vector<int>& nums) {
        tree = new SegmentTree(nums);
    }

    void update(int index, int val) {
        return tree->modify(1, index + 1, val);
    }

    int sumRange(int left, int right) {
        return tree->query(1, left + 1, right + 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
```

#### Go

```go
type Node struct {
	l, r, v int
}

type SegmentTree struct {
	tr   []Node
	nums []int
}

func newSegmentTree(nums []int) *SegmentTree {
	n := len(nums)
	tr := make([]Node, n<<2)
	for i := range tr {
		tr[i] = Node{}
	}
	tree := &SegmentTree{
		tr:   tr,
		nums: nums,
	}
	tree.build(1, 1, n)
	return tree
}

func (tree *SegmentTree) build(u, l, r int) {
	tree.tr[u].l, tree.tr[u].r = l, r
	if l == r {
		tree.tr[u].v = tree.nums[l-1]
		return
	}
	mid := (l + r) >> 1
	tree.build(u<<1, l, mid)
	tree.build(u<<1|1, mid+1, r)
	tree.pushup(u)
}

func (tree *SegmentTree) modify(u, x, v int) {
	if tree.tr[u].l == x && tree.tr[u].r == x {
		tree.tr[u].v = v
		return
	}
	mid := (tree.tr[u].l + tree.tr[u].r) >> 1
	if x <= mid {
		tree.modify(u<<1, x, v)
	} else {
		tree.modify(u<<1|1, x, v)
	}
	tree.pushup(u)
}

func (tree *SegmentTree) query(u, l, r int) (v int) {
	if tree.tr[u].l >= l && tree.tr[u].r <= r {
		return tree.tr[u].v
	}
	mid := (tree.tr[u].l + tree.tr[u].r) >> 1
	if l <= mid {
		v += tree.query(u<<1, l, r)
	}
	if r > mid {
		v += tree.query(u<<1|1, l, r)
	}
	return v
}

func (tree *SegmentTree) pushup(u int) {
	tree.tr[u].v = tree.tr[u<<1].v + tree.tr[u<<1|1].v
}

type NumArray struct {
	tree *SegmentTree
}

func Constructor(nums []int) NumArray {
	return NumArray{
		tree: newSegmentTree(nums),
	}
}

func (this *NumArray) Update(index int, val int) {
	this.tree.modify(1, index+1, val)
}

func (this *NumArray) SumRange(left int, right int) int {
	return this.tree.query(1, left+1, right+1)
}

/**
 * Your NumArray object will be instantiated and called as such:
 * obj := Constructor(nums);
 * obj.Update(index,val);
 * param_2 := obj.SumRange(left,right);
 */
```

#### TypeScript

```ts
class Node {
    l: number;
    r: number;
    v: number;
}

class SegmentTree {
    private tr: Node[];
    private nums: number[];

    constructor(nums: number[]) {
        this.nums = nums;
        const n = nums.length;
        this.tr = new Array<Node>(n << 2);
        for (let i = 0; i < this.tr.length; ++i) {
            this.tr[i] = { l: 0, r: 0, v: 0 };
        }
        this.build(1, 1, n);
    }

    build(u: number, l: number, r: number): void {
        this.tr[u].l = l;
        this.tr[u].r = r;
        if (l == r) {
            this.tr[u].v = this.nums[l - 1];
            return;
        }
        const mid = (l + r) >> 1;
        this.build(u << 1, l, mid);
        this.build((u << 1) | 1, mid + 1, r);
        this.pushup(u);
    }

    modify(u: number, x: number, v: number): void {
        if (this.tr[u].l == x && this.tr[u].r == x) {
            this.tr[u].v = v;
            return;
        }
        const mid = (this.tr[u].l + this.tr[u].r) >> 1;
        if (x <= mid) {
            this.modify(u << 1, x, v);
        } else {
            this.modify((u << 1) | 1, x, v);
        }
        this.pushup(u);
    }

    query(u: number, l: number, r: number): number {
        if (this.tr[u].l >= l && this.tr[u].r <= r) {
            return this.tr[u].v;
        }
        const mid = (this.tr[u].l + this.tr[u].r) >> 1;
        let v = 0;
        if (l <= mid) {
            v += this.query(u << 1, l, r);
        }
        if (r > mid) {
            v += this.query((u << 1) | 1, l, r);
        }
        return v;
    }

    pushup(u: number): void {
        this.tr[u].v = this.tr[u << 1].v + this.tr[(u << 1) | 1].v;
    }
}

class NumArray {
    private tree: SegmentTree;

    constructor(nums: number[]) {
        this.tree = new SegmentTree(nums);
    }

    update(index: number, val: number): void {
        this.tree.modify(1, index + 1, val);
    }

    sumRange(left: number, right: number): number {
        return this.tree.query(1, left + 1, right + 1);
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * var obj = new NumArray(nums)
 * obj.update(index,val)
 * var param_2 = obj.sumRange(left,right)
 */
```

#### C#

```cs
public class Node {
    public int l;
    public int r;
    public int v;
}

public class SegmentTree {
    private Node[] tr;
    private int[] nums;

    public SegmentTree(int[] nums) {
        this.nums = nums;
        int n = nums.Length;
        tr = new Node[n << 2];
        for (int i = 0; i < tr.Length; ++i) {
            tr[i] = new Node();
        }
        Build(1, 1, n);
    }

    public void Build(int u, int l, int r) {
        tr[u].l = l;
        tr[u].r = r;
        if (l == r) {
            tr[u].v = nums[l - 1];
            return;
        }
        int mid = (l + r) >> 1;
        Build(u << 1, l, mid);
        Build(u << 1 | 1, mid + 1, r);
        Pushup(u);
    }

    public void Modify(int u, int x, int v) {
        if (tr[u].l == x && tr[u].r == x) {
            tr[u].v = v;
            return;
        }
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (x <= mid) {
            Modify(u << 1, x, v);
        } else {
            Modify(u << 1 | 1, x, v);
        }
        Pushup(u);
    }

    public int Query(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) {
            return tr[u].v;
        }
        int mid = (tr[u].l + tr[u].r) >> 1;
        int v = 0;
        if (l <= mid) {
            v += Query(u << 1, l, r);
        }
        if (r > mid) {
            v += Query(u << 1 | 1, l, r);
        }
        return v;
    }

    public void Pushup(int u) {
        tr[u].v = tr[u << 1].v + tr[u << 1 | 1].v;
    }
}

public class NumArray {
    private SegmentTree tree;

    public NumArray(int[] nums) {
        tree = new SegmentTree(nums);
    }

    public void Update(int index, int val) {
        tree.Modify(1, index + 1, val);
    }

    public int SumRange(int left, int right) {
        return tree.Query(1, left + 1, right + 1);
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.Update(index,val);
 * int param_2 = obj.SumRange(left,right);
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [308. 二维区域和检索 - 矩阵可修改 🔒](https://leetcode.cn/problems/range-sum-query-2d-mutable){#308}

{{< tabs "308" >}}

{{% tab "python" %}}
```python
class Node:
    def __init__(self):
        self.l = 0
        self.r = 0
        self.v = 0


class SegmentTree:
    def __init__(self, nums):
        n = len(nums)
        self.nums = nums
        self.tr = [Node() for _ in range(4 * n)]
        self.build(1, 1, n)

    def build(self, u, l, r):
        self.tr[u].l = l
        self.tr[u].r = r
        if l == r:
            self.tr[u].v = self.nums[l - 1]
            return
        mid = (l + r) >> 1
        self.build(u << 1, l, mid)
        self.build(u << 1 | 1, mid + 1, r)
        self.pushup(u)

    def modify(self, u, x, v):
        if self.tr[u].l == x and self.tr[u].r == x:
            self.tr[u].v = v
            return
        mid = (self.tr[u].l + self.tr[u].r) >> 1
        if x <= mid:
            self.modify(u << 1, x, v)
        else:
            self.modify(u << 1 | 1, x, v)
        self.pushup(u)

    def query(self, u, l, r):
        if self.tr[u].l >= l and self.tr[u].r <= r:
            return self.tr[u].v
        mid = (self.tr[u].l + self.tr[u].r) >> 1
        v = 0
        if l <= mid:
            v += self.query(u << 1, l, r)
        if r > mid:
            v += self.query(u << 1 | 1, l, r)
        return v

    def pushup(self, u):
        self.tr[u].v = self.tr[u << 1].v + self.tr[u << 1 | 1].v


class NumMatrix:
    def __init__(self, matrix: List[List[int]]):
        self.trees = [SegmentTree(row) for row in matrix]

    def update(self, row: int, col: int, val: int) -> None:
        tree = self.trees[row]
        tree.modify(1, col + 1, val)

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        return sum(
            self.trees[row].query(1, col1 + 1, col2 + 1)
            for row in range(row1, row2 + 1)
        )


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# obj.update(row,col,val)
# param_2 = obj.sumRegion(row1,col1,row2,col2)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Node {
    int l;
    int r;
    int v;
}

class SegmentTree {
    private Node[] tr;
    private int[] nums;

    public SegmentTree(int[] nums) {
        int n = nums.length;
        tr = new Node[n << 2];
        this.nums = nums;
        for (int i = 0; i < tr.length; ++i) {
            tr[i] = new Node();
        }
        build(1, 1, n);
    }

    public void build(int u, int l, int r) {
        tr[u].l = l;
        tr[u].r = r;
        if (l == r) {
            tr[u].v = nums[l - 1];
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }

    public void modify(int u, int x, int v) {
        if (tr[u].l == x && tr[u].r == x) {
            tr[u].v = v;
            return;
        }
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (x <= mid) {
            modify(u << 1, x, v);
        } else {
            modify(u << 1 | 1, x, v);
        }
        pushup(u);
    }

    public void pushup(int u) {
        tr[u].v = tr[u << 1].v + tr[u << 1 | 1].v;
    }

    public int query(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) {
            return tr[u].v;
        }
        int mid = (tr[u].l + tr[u].r) >> 1;
        int v = 0;
        if (l <= mid) {
            v += query(u << 1, l, r);
        }
        if (r > mid) {
            v += query(u << 1 | 1, l, r);
        }
        return v;
    }
}

class NumMatrix {
    private SegmentTree[] trees;

    public NumMatrix(int[][] matrix) {
        int m = matrix.length;
        trees = new SegmentTree[m];
        for (int i = 0; i < m; ++i) {
            trees[i] = new SegmentTree(matrix[i]);
        }
    }

    public void update(int row, int col, int val) {
        SegmentTree tree = trees[row];
        tree.modify(1, col + 1, val);
    }

    public int sumRegion(int row1, int col1, int row2, int col2) {
        int s = 0;
        for (int row = row1; row <= row2; ++row) {
            SegmentTree tree = trees[row];
            s += tree.query(1, col1 + 1, col2 + 1);
        }
        return s;
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Node {
public:
    int l;
    int r;
    int v;
};

class SegmentTree {
public:
    vector<Node*> tr;
    vector<int> nums;

    SegmentTree(vector<int>& nums) {
        int n = nums.size();
        tr.resize(n << 2);
        this->nums = nums;
        for (int i = 0; i < tr.size(); ++i) tr[i] = new Node();
        build(1, 1, n);
    }

    void build(int u, int l, int r) {
        tr[u]->l = l;
        tr[u]->r = r;
        if (l == r) {
            tr[u]->v = nums[l - 1];
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }

    void modify(int u, int x, int v) {
        if (tr[u]->l == x && tr[u]->r == x) {
            tr[u]->v = v;
            return;
        }
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        if (x <= mid)
            modify(u << 1, x, v);
        else
            modify(u << 1 | 1, x, v);
        pushup(u);
    }

    int query(int u, int l, int r) {
        if (tr[u]->l >= l && tr[u]->r <= r) return tr[u]->v;
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        int v = 0;
        if (l <= mid) v += query(u << 1, l, r);
        if (r > mid) v += query(u << 1 | 1, l, r);
        return v;
    }

    void pushup(int u) {
        tr[u]->v = tr[u << 1]->v + tr[u << 1 | 1]->v;
    }
};

class NumMatrix {
public:
    vector<SegmentTree*> trees;

    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        trees.resize(m);
        for (int i = 0; i < m; ++i) trees[i] = new SegmentTree(matrix[i]);
    }

    void update(int row, int col, int val) {
        SegmentTree* tree = trees[row];
        tree->modify(1, col + 1, val);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int s = 0;
        for (int row = row1; row <= row2; ++row) s += trees[row]->query(1, col1 + 1, col2 + 1);
        return s;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type BinaryIndexedTree struct {
	n int
	c []int
}

func newBinaryIndexedTree(n int) *BinaryIndexedTree {
	c := make([]int, n+1)
	return &BinaryIndexedTree{n, c}
}

func (this *BinaryIndexedTree) lowbit(x int) int {
	return x & -x
}

func (this *BinaryIndexedTree) update(x, delta int) {
	for x <= this.n {
		this.c[x] += delta
		x += this.lowbit(x)
	}
}

func (this *BinaryIndexedTree) query(x int) int {
	s := 0
	for x > 0 {
		s += this.c[x]
		x -= this.lowbit(x)
	}
	return s
}

type NumMatrix struct {
	trees []*BinaryIndexedTree
}

func Constructor(matrix [][]int) NumMatrix {
	n := len(matrix[0])
	var trees []*BinaryIndexedTree
	for _, row := range matrix {
		tree := newBinaryIndexedTree(n)
		for j, v := range row {
			tree.update(j+1, v)
		}
		trees = append(trees, tree)
	}
	return NumMatrix{trees}
}

func (this *NumMatrix) Update(row int, col int, val int) {
	tree := this.trees[row]
	prev := tree.query(col+1) - tree.query(col)
	tree.update(col+1, val-prev)
}

func (this *NumMatrix) SumRegion(row1 int, col1 int, row2 int, col2 int) int {
	s := 0
	for i := row1; i <= row2; i++ {
		tree := this.trees[i]
		s += tree.query(col2+1) - tree.query(col1)
	}
	return s
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * obj := Constructor(matrix);
 * obj.Update(row,col,val);
 * param_2 := obj.SumRegion(row1,col1,row2,col2);
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个二维矩阵 <code>matrix</code> ，处理以下类型的多个查询:</p>

<ol>
	<li><strong>更新</strong> <code>matrix</code> 中单元格的值。</li>
	<li>计算由&nbsp;<strong>左上角</strong> <code>(row1, col1)</code> 和&nbsp;<strong>右下角</strong> <code>(row2, col2)</code> 定义的 <code>matrix</code>&nbsp;内矩阵元素的&nbsp;<strong>和</strong>。</li>
</ol>

<p>实现 <code>NumMatrix</code> 类：</p>

<ul>
	<li><code>NumMatrix(int[][] matrix)</code> 用整数矩阵&nbsp;<code>matrix</code> 初始化对象。</li>
	<li><code>void update(int row, int col, int val)</code> <strong>更新</strong> <code>matrix[row][col]</code> 的值到 <code>val</code> 。</li>
	<li><code>int sumRegion(int row1, int col1, int row2, int col2)</code> 返回矩阵&nbsp;<code>matrix</code> 中指定矩形区域元素的 <strong>和</strong> ，该区域由 <strong>左上角</strong> <code>(row1, col1)</code> 和 <strong>右下角</strong> <code>(row2, col2)</code> 界定。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0300-0399/0308.Range%20Sum%20Query%202D%20-%20Mutable/images/summut-grid.jpg" style="height: 222px; width: 500px;" />
<pre>
<strong>输入</strong>
["NumMatrix", "sumRegion", "update", "sumRegion"]
[[[[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]], [2, 1, 4, 3], [3, 2, 2], [2, 1, 4, 3]]
<strong>输出</strong>
[null, 8, null, 10]

<strong>解释</strong>
NumMatrix numMatrix = new NumMatrix([[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]);
numMatrix.sumRegion(2, 1, 4, 3); // 返回 8 (即, 左侧红色矩形的和)
numMatrix.update(3, 2, 2); // 矩阵从左图变为右图
numMatrix.sumRegion(2, 1, 4, 3); // 返回 10 (即，右侧红色矩形的和)

</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>-10<font size="1">00</font>&nbsp;&lt;= matrix[i][j] &lt;= 10<font size="1">00</font></code></li>
	<li><code>0 &lt;= row &lt; m</code></li>
	<li><code>0 &lt;= col &lt; n</code></li>
	<li><code>-10<font size="1">00</font>&nbsp;&lt;= val &lt;= 10<font size="1">00</font></code></li>
	<li><code>0 &lt;= row1 &lt;= row2 &lt; m</code></li>
	<li><code>0 &lt;= col1 &lt;= col2 &lt; n</code></li>
	<li>最多调用<code>5000</code>&nbsp;次&nbsp;<code>sumRegion</code> 和 <code>update</code> 方法</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：树状数组

树状数组，也称作“二叉索引树”（Binary Indexed Tree）或 Fenwick 树。 它可以高效地实现如下两个操作：

1. **单点更新** `update(x, delta)`： 把序列 x 位置的数加上一个值 delta；
1. **前缀和查询** `query(x)`：查询序列 `[1,...x]` 区间的区间和，即位置 x 的前缀和。

这两个操作的时间复杂度均为 $O(\log n)$。

对于本题，可以构建二维树状数组。

<!-- tabs:start -->

#### Python3

```python
class BinaryIndexedTree:
    def __init__(self, n):
        self.n = n
        self.c = [0] * (n + 1)

    @staticmethod
    def lowbit(x):
        return x & -x

    def update(self, x, delta):
        while x <= self.n:
            self.c[x] += delta
            x += BinaryIndexedTree.lowbit(x)

    def query(self, x):
        s = 0
        while x > 0:
            s += self.c[x]
            x -= BinaryIndexedTree.lowbit(x)
        return s


class NumMatrix:
    def __init__(self, matrix: List[List[int]]):
        self.trees = []
        n = len(matrix[0])
        for row in matrix:
            tree = BinaryIndexedTree(n)
            for j, v in enumerate(row):
                tree.update(j + 1, v)
            self.trees.append(tree)

    def update(self, row: int, col: int, val: int) -> None:
        tree = self.trees[row]
        prev = tree.query(col + 1) - tree.query(col)
        tree.update(col + 1, val - prev)

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        return sum(
            tree.query(col2 + 1) - tree.query(col1)
            for tree in self.trees[row1 : row2 + 1]
        )


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# obj.update(row,col,val)
# param_2 = obj.sumRegion(row1,col1,row2,col2)
```

#### Java

```java
class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        c = new int[n + 1];
    }

    public void update(int x, int delta) {
        while (x <= n) {
            c[x] += delta;
            x += lowbit(x);
        }
    }

    public int query(int x) {
        int s = 0;
        while (x > 0) {
            s += c[x];
            x -= lowbit(x);
        }
        return s;
    }

    public static int lowbit(int x) {
        return x & -x;
    }
}

class NumMatrix {
    private BinaryIndexedTree[] trees;

    public NumMatrix(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        trees = new BinaryIndexedTree[m];
        for (int i = 0; i < m; ++i) {
            BinaryIndexedTree tree = new BinaryIndexedTree(n);
            for (int j = 0; j < n; ++j) {
                tree.update(j + 1, matrix[i][j]);
            }
            trees[i] = tree;
        }
    }

    public void update(int row, int col, int val) {
        BinaryIndexedTree tree = trees[row];
        int prev = tree.query(col + 1) - tree.query(col);
        tree.update(col + 1, val - prev);
    }

    public int sumRegion(int row1, int col1, int row2, int col2) {
        int s = 0;
        for (int i = row1; i <= row2; ++i) {
            BinaryIndexedTree tree = trees[i];
            s += tree.query(col2 + 1) - tree.query(col1);
        }
        return s;
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */
```

#### C++

```cpp
class BinaryIndexedTree {
public:
    int n;
    vector<int> c;

    BinaryIndexedTree(int _n)
        : n(_n)
        , c(_n + 1) {}

    void update(int x, int delta) {
        while (x <= n) {
            c[x] += delta;
            x += lowbit(x);
        }
    }

    int query(int x) {
        int s = 0;
        while (x > 0) {
            s += c[x];
            x -= lowbit(x);
        }
        return s;
    }

    int lowbit(int x) {
        return x & -x;
    }
};

class NumMatrix {
public:
    vector<BinaryIndexedTree*> trees;

    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        trees.resize(m);
        for (int i = 0; i < m; ++i) {
            BinaryIndexedTree* tree = new BinaryIndexedTree(n);
            for (int j = 0; j < n; ++j) tree->update(j + 1, matrix[i][j]);
            trees[i] = tree;
        }
    }

    void update(int row, int col, int val) {
        BinaryIndexedTree* tree = trees[row];
        int prev = tree->query(col + 1) - tree->query(col);
        tree->update(col + 1, val - prev);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int s = 0;
        for (int i = row1; i <= row2; ++i) {
            BinaryIndexedTree* tree = trees[i];
            s += tree->query(col2 + 1) - tree->query(col1);
        }
        return s;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */
```

#### Go

```go
type BinaryIndexedTree struct {
	n int
	c []int
}

func newBinaryIndexedTree(n int) *BinaryIndexedTree {
	c := make([]int, n+1)
	return &BinaryIndexedTree{n, c}
}

func (this *BinaryIndexedTree) lowbit(x int) int {
	return x & -x
}

func (this *BinaryIndexedTree) update(x, delta int) {
	for x <= this.n {
		this.c[x] += delta
		x += this.lowbit(x)
	}
}

func (this *BinaryIndexedTree) query(x int) int {
	s := 0
	for x > 0 {
		s += this.c[x]
		x -= this.lowbit(x)
	}
	return s
}

type NumMatrix struct {
	trees []*BinaryIndexedTree
}

func Constructor(matrix [][]int) NumMatrix {
	n := len(matrix[0])
	var trees []*BinaryIndexedTree
	for _, row := range matrix {
		tree := newBinaryIndexedTree(n)
		for j, v := range row {
			tree.update(j+1, v)
		}
		trees = append(trees, tree)
	}
	return NumMatrix{trees}
}

func (this *NumMatrix) Update(row int, col int, val int) {
	tree := this.trees[row]
	prev := tree.query(col+1) - tree.query(col)
	tree.update(col+1, val-prev)
}

func (this *NumMatrix) SumRegion(row1 int, col1 int, row2 int, col2 int) int {
	s := 0
	for i := row1; i <= row2; i++ {
		tree := this.trees[i]
		s += tree.query(col2+1) - tree.query(col1)
	}
	return s
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * obj := Constructor(matrix);
 * obj.Update(row,col,val);
 * param_2 := obj.SumRegion(row1,col1,row2,col2);
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：线段树

线段树将整个区间分割为多个不连续的子区间，子区间的数量不超过 `log(width)`。更新某个元素的值，只需要更新 `log(width)` 个区间，并且这些区间都包含在一个包含该元素的大区间内。

-   线段树的每个节点代表一个区间；
-   线段树具有唯一的根节点，代表的区间是整个统计范围，如 `[1, N]`；
-   线段树的每个叶子节点代表一个长度为 1 的元区间 `[x, x]`；
-   对于每个内部节点 `[l, r]`，它的左儿子是 `[l, mid]`，右儿子是 `[mid + 1, r]`, 其中 `mid = ⌊(l + r) / 2⌋` (即向下取整)。

<!-- tabs:start -->

#### Python3

```python
class Node:
    def __init__(self):
        self.l = 0
        self.r = 0
        self.v = 0


class SegmentTree:
    def __init__(self, nums):
        n = len(nums)
        self.nums = nums
        self.tr = [Node() for _ in range(4 * n)]
        self.build(1, 1, n)

    def build(self, u, l, r):
        self.tr[u].l = l
        self.tr[u].r = r
        if l == r:
            self.tr[u].v = self.nums[l - 1]
            return
        mid = (l + r) >> 1
        self.build(u << 1, l, mid)
        self.build(u << 1 | 1, mid + 1, r)
        self.pushup(u)

    def modify(self, u, x, v):
        if self.tr[u].l == x and self.tr[u].r == x:
            self.tr[u].v = v
            return
        mid = (self.tr[u].l + self.tr[u].r) >> 1
        if x <= mid:
            self.modify(u << 1, x, v)
        else:
            self.modify(u << 1 | 1, x, v)
        self.pushup(u)

    def query(self, u, l, r):
        if self.tr[u].l >= l and self.tr[u].r <= r:
            return self.tr[u].v
        mid = (self.tr[u].l + self.tr[u].r) >> 1
        v = 0
        if l <= mid:
            v += self.query(u << 1, l, r)
        if r > mid:
            v += self.query(u << 1 | 1, l, r)
        return v

    def pushup(self, u):
        self.tr[u].v = self.tr[u << 1].v + self.tr[u << 1 | 1].v


class NumMatrix:
    def __init__(self, matrix: List[List[int]]):
        self.trees = [SegmentTree(row) for row in matrix]

    def update(self, row: int, col: int, val: int) -> None:
        tree = self.trees[row]
        tree.modify(1, col + 1, val)

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        return sum(
            self.trees[row].query(1, col1 + 1, col2 + 1)
            for row in range(row1, row2 + 1)
        )


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# obj.update(row,col,val)
# param_2 = obj.sumRegion(row1,col1,row2,col2)
```

#### Java

```java
class Node {
    int l;
    int r;
    int v;
}

class SegmentTree {
    private Node[] tr;
    private int[] nums;

    public SegmentTree(int[] nums) {
        int n = nums.length;
        tr = new Node[n << 2];
        this.nums = nums;
        for (int i = 0; i < tr.length; ++i) {
            tr[i] = new Node();
        }
        build(1, 1, n);
    }

    public void build(int u, int l, int r) {
        tr[u].l = l;
        tr[u].r = r;
        if (l == r) {
            tr[u].v = nums[l - 1];
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }

    public void modify(int u, int x, int v) {
        if (tr[u].l == x && tr[u].r == x) {
            tr[u].v = v;
            return;
        }
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (x <= mid) {
            modify(u << 1, x, v);
        } else {
            modify(u << 1 | 1, x, v);
        }
        pushup(u);
    }

    public void pushup(int u) {
        tr[u].v = tr[u << 1].v + tr[u << 1 | 1].v;
    }

    public int query(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) {
            return tr[u].v;
        }
        int mid = (tr[u].l + tr[u].r) >> 1;
        int v = 0;
        if (l <= mid) {
            v += query(u << 1, l, r);
        }
        if (r > mid) {
            v += query(u << 1 | 1, l, r);
        }
        return v;
    }
}

class NumMatrix {
    private SegmentTree[] trees;

    public NumMatrix(int[][] matrix) {
        int m = matrix.length;
        trees = new SegmentTree[m];
        for (int i = 0; i < m; ++i) {
            trees[i] = new SegmentTree(matrix[i]);
        }
    }

    public void update(int row, int col, int val) {
        SegmentTree tree = trees[row];
        tree.modify(1, col + 1, val);
    }

    public int sumRegion(int row1, int col1, int row2, int col2) {
        int s = 0;
        for (int row = row1; row <= row2; ++row) {
            SegmentTree tree = trees[row];
            s += tree.query(1, col1 + 1, col2 + 1);
        }
        return s;
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */
```

#### C++

```cpp
class Node {
public:
    int l;
    int r;
    int v;
};

class SegmentTree {
public:
    vector<Node*> tr;
    vector<int> nums;

    SegmentTree(vector<int>& nums) {
        int n = nums.size();
        tr.resize(n << 2);
        this->nums = nums;
        for (int i = 0; i < tr.size(); ++i) tr[i] = new Node();
        build(1, 1, n);
    }

    void build(int u, int l, int r) {
        tr[u]->l = l;
        tr[u]->r = r;
        if (l == r) {
            tr[u]->v = nums[l - 1];
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }

    void modify(int u, int x, int v) {
        if (tr[u]->l == x && tr[u]->r == x) {
            tr[u]->v = v;
            return;
        }
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        if (x <= mid)
            modify(u << 1, x, v);
        else
            modify(u << 1 | 1, x, v);
        pushup(u);
    }

    int query(int u, int l, int r) {
        if (tr[u]->l >= l && tr[u]->r <= r) return tr[u]->v;
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        int v = 0;
        if (l <= mid) v += query(u << 1, l, r);
        if (r > mid) v += query(u << 1 | 1, l, r);
        return v;
    }

    void pushup(int u) {
        tr[u]->v = tr[u << 1]->v + tr[u << 1 | 1]->v;
    }
};

class NumMatrix {
public:
    vector<SegmentTree*> trees;

    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        trees.resize(m);
        for (int i = 0; i < m; ++i) trees[i] = new SegmentTree(matrix[i]);
    }

    void update(int row, int col, int val) {
        SegmentTree* tree = trees[row];
        tree->modify(1, col + 1, val);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int s = 0;
        for (int row = row1; row <= row2; ++row) s += trees[row]->query(1, col1 + 1, col2 + 1);
        return s;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [309. 买卖股票的最佳时机含冷冻期](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown){#309}

{{< tabs "309" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        f, f0, f1 = 0, 0, -prices[0]
        for x in prices[1:]:
            f, f0, f1 = f0, max(f0, f1 + x), max(f1, f - x)
        return f0
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxProfit(int[] prices) {
        int f = 0, f0 = 0, f1 = -prices[0];
        for (int i = 1; i < prices.length; ++i) {
            int g0 = Math.max(f0, f1 + prices[i]);
            f1 = Math.max(f1, f - prices[i]);
            f = f0;
            f0 = g0;
        }
        return f0;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int f = 0, f0 = 0, f1 = -prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            int g0 = max(f0, f1 + prices[i]);
            f1 = max(f1, f - prices[i]);
            f = f0;
            f0 = g0;
        }
        return f0;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxProfit(prices []int) int {
	f, f0, f1 := 0, 0, -prices[0]
	for _, x := range prices[1:] {
		f, f0, f1 = f0, max(f0, f1+x), max(f1, f-x)
	}
	return f0
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxProfit(prices: number[]): number {
    let [f, f0, f1] = [0, 0, -prices[0]];
    for (const x of prices.slice(1)) {
        [f, f0, f1] = [f0, Math.max(f0, f1 + x), Math.max(f1, f - x)];
    }
    return f0;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个整数数组<meta charset="UTF-8" /><code>prices</code>，其中第&nbsp;<em>&nbsp;</em><code>prices[i]</code>&nbsp;表示第&nbsp;<code><em>i</em></code>&nbsp;天的股票价格 。​</p>

<p>设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:</p>

<ul>
	<li>卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。</li>
</ul>

<p><strong>注意：</strong>你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> prices = [1,2,3,0,2]
<strong>输出: </strong>3 
<strong>解释:</strong> 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> prices = [1]
<strong>输出:</strong> 0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= prices.length &lt;= 5000</code></li>
	<li><code>0 &lt;= prices[i] &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $dfs(i, j)$，表示从第 $i$ 天开始，状态为 $j$ 时，能够获得的最大利润。其中 $j$ 的取值为 $0, 1$，分别表示当前不持有股票和持有股票。答案即为 $dfs(0, 0)$。

函数 $dfs(i, j)$ 的执行逻辑如下：

如果 $i \geq n$，表示已经没有股票可以交易了，此时返回 $0$；

否则，我们可以选择不交易，此时 $dfs(i, j) = dfs(i + 1, j)$。我们也可以进行股票交易，如果此时 $j \gt 0$，说明当前持有股票，可以卖出，此时 $dfs(i, j) = prices[i] + dfs(i + 2, 0)$；如果此时 $j = 0$，说明当前不持有股票，可以买入，此时 $dfs(i, j) = -prices[i] + dfs(i + 1, 1)$。取最大值作为函数 $dfs(i, j)$ 的返回值。

答案为 $dfs(0, 0)$。

为了避免重复计算，我们使用记忆化搜索的方法，用一个数组 $f$ 记录 $dfs(i, j)$ 的返回值，如果 $f[i][j]$ 不为 $-1$，说明已经计算过，直接返回 $f[i][j]$ 即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $prices$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        @cache
        def dfs(i: int, j: int) -> int:
            if i >= len(prices):
                return 0
            ans = dfs(i + 1, j)
            if j:
                ans = max(ans, prices[i] + dfs(i + 2, 0))
            else:
                ans = max(ans, -prices[i] + dfs(i + 1, 1))
            return ans

        return dfs(0, 0)
```

#### Java

```java
class Solution {
    private int[] prices;
    private Integer[][] f;

    public int maxProfit(int[] prices) {
        this.prices = prices;
        f = new Integer[prices.length][2];
        return dfs(0, 0);
    }

    private int dfs(int i, int j) {
        if (i >= prices.length) {
            return 0;
        }
        if (f[i][j] != null) {
            return f[i][j];
        }
        int ans = dfs(i + 1, j);
        if (j > 0) {
            ans = Math.max(ans, prices[i] + dfs(i + 2, 0));
        } else {
            ans = Math.max(ans, -prices[i] + dfs(i + 1, 1));
        }
        return f[i][j] = ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int f[n][2];
        memset(f, -1, sizeof(f));
        function<int(int, int)> dfs = [&](int i, int j) {
            if (i >= n) {
                return 0;
            }
            if (f[i][j] != -1) {
                return f[i][j];
            }
            int ans = dfs(i + 1, j);
            if (j) {
                ans = max(ans, prices[i] + dfs(i + 2, 0));
            } else {
                ans = max(ans, -prices[i] + dfs(i + 1, 1));
            }
            return f[i][j] = ans;
        };
        return dfs(0, 0);
    }
};
```

#### Go

```go
func maxProfit(prices []int) int {
	n := len(prices)
	f := make([][2]int, n)
	for i := range f {
		f[i] = [2]int{-1, -1}
	}
	var dfs func(i, j int) int
	dfs = func(i, j int) int {
		if i >= n {
			return 0
		}
		if f[i][j] != -1 {
			return f[i][j]
		}
		ans := dfs(i+1, j)
		if j > 0 {
			ans = max(ans, prices[i]+dfs(i+2, 0))
		} else {
			ans = max(ans, -prices[i]+dfs(i+1, 1))
		}
		f[i][j] = ans
		return ans
	}
	return dfs(0, 0)
}
```

#### TypeScript

```ts
function maxProfit(prices: number[]): number {
    const n = prices.length;
    const f: number[][] = Array.from({ length: n }, () => Array.from({ length: 2 }, () => -1));
    const dfs = (i: number, j: number): number => {
        if (i >= n) {
            return 0;
        }
        if (f[i][j] !== -1) {
            return f[i][j];
        }
        let ans = dfs(i + 1, j);
        if (j) {
            ans = Math.max(ans, prices[i] + dfs(i + 2, 0));
        } else {
            ans = Math.max(ans, -prices[i] + dfs(i + 1, 1));
        }
        return (f[i][j] = ans);
    };
    return dfs(0, 0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划

我们也可以用动态规划的方法求解。

我们定义 $f[i][j]$ 表示到第 $i$ 天，且状态为 $j$ 时，能够获得的最大利润。其中 $j$ 的取值为 $0, 1$，分别表示当前不持有股票和持有股票。初始时 $f[0][0] = 0$, $f[0][1] = -prices[0]$。

当 $i \geq 1$ 时，如果当前不持有股票，那么 $f[i][0]$ 可以由 $f[i - 1][0]$ 和 $f[i - 1][1] + prices[i]$ 转移得到，即 $f[i][0] = \max(f[i - 1][0], f[i - 1][1] + prices[i])$；如果当前持有股票，那么 $f[i][1]$ 可以由 $f[i - 1][1]$ 和 $f[i - 2][0] - prices[i]$ 转移得到，即 $f[i][1] = \max(f[i - 1][1], f[i - 2][0] - prices[i])$。最终答案为 $f[n - 1][0]$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $prices$ 的长度。

我们注意到，状态 $f[i][]$ 的转移只与 $f[i - 1][]$ 和 $f[i - 2][0]$ 有关，因此我们可以用三个变量 $f$, $f_0$, $f_1$ 代替数组 $f$，将空间复杂度优化到 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        f = [[0] * 2 for _ in range(n)]
        f[0][1] = -prices[0]
        for i in range(1, n):
            f[i][0] = max(f[i - 1][0], f[i - 1][1] + prices[i])
            f[i][1] = max(f[i - 1][1], f[i - 2][0] - prices[i])
        return f[n - 1][0]
```

#### Java

```java
class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int[][] f = new int[n][2];
        f[0][1] = -prices[0];
        for (int i = 1; i < n; i++) {
            f[i][0] = Math.max(f[i - 1][0], f[i - 1][1] + prices[i]);
            f[i][1] = Math.max(f[i - 1][1], (i > 1 ? f[i - 2][0] : 0) - prices[i]);
        }
        return f[n - 1][0];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int f[n][2];
        memset(f, 0, sizeof(f));
        f[0][1] = -prices[0];
        for (int i = 1; i < n; ++i) {
            f[i][0] = max(f[i - 1][0], f[i - 1][1] + prices[i]);
            f[i][1] = max(f[i - 1][1], (i > 1 ? f[i - 2][0] : 0) - prices[i]);
        }
        return f[n - 1][0];
    }
};
```

#### Go

```go
func maxProfit(prices []int) int {
	n := len(prices)
	f := make([][2]int, n)
	f[0][1] = -prices[0]
	for i := 1; i < n; i++ {
		f[i][0] = max(f[i-1][0], f[i-1][1]+prices[i])
		if i > 1 {
			f[i][1] = max(f[i-1][1], f[i-2][0]-prices[i])
		} else {
			f[i][1] = max(f[i-1][1], -prices[i])
		}
	}
	return f[n-1][0]
}
```

#### TypeScript

```ts
function maxProfit(prices: number[]): number {
    const n = prices.length;
    const f: number[][] = Array.from({ length: n }, () => Array.from({ length: 2 }, () => 0));
    f[0][1] = -prices[0];
    for (let i = 1; i < n; ++i) {
        f[i][0] = Math.max(f[i - 1][0], f[i - 1][1] + prices[i]);
        f[i][1] = Math.max(f[i - 1][1], (i > 1 ? f[i - 2][0] : 0) - prices[i]);
    }
    return f[n - 1][0];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        f, f0, f1 = 0, 0, -prices[0]
        for x in prices[1:]:
            f, f0, f1 = f0, max(f0, f1 + x), max(f1, f - x)
        return f0
```

#### Java

```java
class Solution {
    public int maxProfit(int[] prices) {
        int f = 0, f0 = 0, f1 = -prices[0];
        for (int i = 1; i < prices.length; ++i) {
            int g0 = Math.max(f0, f1 + prices[i]);
            f1 = Math.max(f1, f - prices[i]);
            f = f0;
            f0 = g0;
        }
        return f0;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int f = 0, f0 = 0, f1 = -prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            int g0 = max(f0, f1 + prices[i]);
            f1 = max(f1, f - prices[i]);
            f = f0;
            f0 = g0;
        }
        return f0;
    }
};
```

#### Go

```go
func maxProfit(prices []int) int {
	f, f0, f1 := 0, 0, -prices[0]
	for _, x := range prices[1:] {
		f, f0, f1 = f0, max(f0, f1+x), max(f1, f-x)
	}
	return f0
}
```

#### TypeScript

```ts
function maxProfit(prices: number[]): number {
    let [f, f0, f1] = [0, 0, -prices[0]];
    for (const x of prices.slice(1)) {
        [f, f0, f1] = [f0, Math.max(f0, f1 + x), Math.max(f1, f - x)];
    }
    return f0;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
