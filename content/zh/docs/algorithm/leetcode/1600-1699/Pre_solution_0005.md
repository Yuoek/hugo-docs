---
title: "1640_能否连接形成数组"
date: 2025-10-08T18:38:12+08:00
weight: 5
tags: [二分查找, 二叉树, 分治, 动态规划, 哈希表, 堆（优先队列）, 字符串, 归并排序, 排序, 数学, 数据库, 数组, 有序集合, 树, 树状数组, 模拟, 深度优先搜索, 线段树, 组合数学, 贪心]
---

{{< markmap >}}
### [1640_能否连接形成数组](#1640)
#### [数组](#1640)
#### [哈希表](#1640)
### [1641_统计字典序元音字符串的数目](#1641)
#### [数学](#1641)
#### [动态规划](#1641)
#### [组合数学](#1641)
### [1642_可以到达的最远建筑](#1642)
#### [贪心](#1642)
#### [数组](#1642)
#### [堆（优先队列）](#1642)
### [1643_第 K 条最小指令](#1643)
#### [数组](#1643)
#### [数学](#1643)
#### [动态规划](#1643)
#### [组合数学](#1643)
### [1644_二叉树的最近公共祖先 II 🔒](#1644)
#### [树](#1644)
#### [深度优先搜索](#1644)
#### [二叉树](#1644)
### [1645_Hopper 公司查询 II 🔒](#1645)
#### [数据库](#1645)
### [1646_获取生成数组中的最大值](#1646)
#### [数组](#1646)
#### [模拟](#1646)
### [1647_字符频次唯一的最小删除次数](#1647)
#### [贪心](#1647)
#### [哈希表](#1647)
#### [字符串](#1647)
#### [排序](#1647)
### [1648_销售价值减少的颜色球](#1648)
#### [贪心](#1648)
#### [数组](#1648)
#### [数学](#1648)
#### [二分查找](#1648)
#### [排序](#1648)
#### [堆（优先队列）](#1648)
### [1649_通过指令创建有序数组](#1649)
#### [树状数组](#1649)
#### [线段树](#1649)
#### [数组](#1649)
#### [二分查找](#1649)
#### [分治](#1649)
#### [有序集合](#1649)
#### [归并排序](#1649)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1640_能否连接形成数组
___
#### 数组
___
#### 哈希表
---
### 1641_统计字典序元音字符串的数目
___
#### 数学
___
#### 动态规划
___
#### 组合数学
---
### 1642_可以到达的最远建筑
___
#### 贪心
___
#### 数组
___
#### 堆（优先队列）
---
### 1643_第 K 条最小指令
___
#### 数组
___
#### 数学
___
#### 动态规划
___
#### 组合数学
---
### 1644_二叉树的最近公共祖先 II 🔒
___
#### 树
___
#### 深度优先搜索
___
#### 二叉树
---
### 1645_Hopper 公司查询 II 🔒
___
#### 数据库
---
### 1646_获取生成数组中的最大值
___
#### 数组
___
#### 模拟
---
### 1647_字符频次唯一的最小删除次数
___
#### 贪心
___
#### 哈希表
___
#### 字符串
___
#### 排序
---
### 1648_销售价值减少的颜色球
___
#### 贪心
___
#### 数组
___
#### 数学
___
#### 二分查找
___
#### 排序
___
#### 堆（优先队列）
---
### 1649_通过指令创建有序数组
___
#### 树状数组
___
#### 线段树
___
#### 数组
___
#### 二分查找
___
#### 分治
___
#### 有序集合
___
#### 归并排序
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉树 | 分治 |
| 动态规划 | 哈希表 | 堆（优先队列） |
| 字符串 | 归并排序 | 排序 |
| 数学 | 数据库 | 数组 |
| 有序集合 | 树 | 树状数组 |
| 模拟 | 深度优先搜索 | 线段树 |
| 组合数学 | 贪心 |  |

# [1640. 能否连接形成数组](https://leetcode.cn/problems/check-array-formation-through-concatenation){#1640}

{{< tabs "1640" >}}

{{% tab "python" %}}
```python
class Solution:
    def canFormArray(self, arr: List[int], pieces: List[List[int]]) -> bool:
        d = {p[0]: p for p in pieces}
        i, n = 0, len(arr)
        while i < n:
            if arr[i] not in d:
                return False
            p = d[arr[i]]
            if arr[i : i + len(p)] != p:
                return False
            i += len(p)
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean canFormArray(int[] arr, int[][] pieces) {
        Map<Integer, int[]> d = new HashMap<>();
        for (var p : pieces) {
            d.put(p[0], p);
        }
        for (int i = 0; i < arr.length;) {
            if (!d.containsKey(arr[i])) {
                return false;
            }
            for (int v : d.get(arr[i])) {
                if (arr[i++] != v) {
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
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, vector<int>> d;
        for (auto& p : pieces) {
            d[p[0]] = p;
        }
        for (int i = 0; i < arr.size();) {
            if (!d.count(arr[i])) {
                return false;
            }
            for (int& v : d[arr[i]]) {
                if (arr[i++] != v) {
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
func canFormArray(arr []int, pieces [][]int) bool {
	d := map[int][]int{}
	for _, p := range pieces {
		d[p[0]] = p
	}
	for i := 0; i < len(arr); {
		p, ok := d[arr[i]]
		if !ok {
			return false
		}
		for _, v := range p {
			if arr[i] != v {
				return false
			}
			i++
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function canFormArray(arr: number[], pieces: number[][]): boolean {
    const n = arr.length;
    let i = 0;
    while (i < n) {
        const target = arr[i];
        const items = pieces.find(v => v[0] === target);
        if (items == null) {
            return false;
        }
        for (const item of items) {
            if (item !== arr[i]) {
                return false;
            }
            i++;
        }
    }
    return true;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;
impl Solution {
    pub fn can_form_array(arr: Vec<i32>, pieces: Vec<Vec<i32>>) -> bool {
        let n = arr.len();
        let mut map = HashMap::new();
        for (i, v) in pieces.iter().enumerate() {
            map.insert(v[0], i);
        }
        let mut i = 0;
        while i < n {
            match map.get(&arr[i]) {
                None => {
                    return false;
                }
                Some(&j) => {
                    for &item in pieces[j].iter() {
                        if item != arr[i] {
                            return false;
                        }
                        i += 1;
                    }
                }
            }
        }
        true
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} arr
 * @param {number[][]} pieces
 * @return {boolean}
 */
var canFormArray = function (arr, pieces) {
    const d = new Map();
    for (const p of pieces) {
        d.set(p[0], p);
    }
    for (let i = 0; i < arr.length; ) {
        if (!d.has(arr[i])) {
            return false;
        }
        const p = d.get(arr[i]);
        for (const v of p) {
            if (arr[i++] != v) {
                return false;
            }
        }
    }
    return true;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>arr</code> ，数组中的每个整数 <strong>互不相同</strong> 。另有一个由整数数组构成的数组 <code>pieces</code>，其中的整数也 <strong>互不相同</strong> 。请你以 <strong>任意顺序</strong> 连接 <code>pieces</code> 中的数组以形成 <code>arr</code> 。但是，<strong>不允许</strong> 对每个数组 <code>pieces[i]</code> 中的整数重新排序。</p>

<p>如果可以连接<em> </em><code>pieces</code> 中的数组形成 <code>arr</code> ，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr = [15,88], pieces = [[88],[15]]
<strong>输出：</strong>true
<strong>解释：</strong>依次连接 <code>[15]</code> 和 <code>[88]</code>
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr = [49,18,16], pieces = [[16,18,49]]
<strong>输出：</strong>false
<strong>解释：</strong>即便数字相符，也不能重新排列 pieces[0]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>arr = [91,4,64,78], pieces = [[78],[4,64],[91]]
<strong>输出：</strong>true
<strong>解释：</strong>依次连接 <code>[91]</code>、<code>[4,64]</code> 和 <code>[78]</code></pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= pieces.length &lt;= arr.length &lt;= 100</code></li>
	<li><code>sum(pieces[i].length) == arr.length</code></li>
	<li><code>1 &lt;= pieces[i].length &lt;= arr.length</code></li>
	<li><code>1 &lt;= arr[i], pieces[i][j] &lt;= 100</code></li>
	<li><code>arr</code> 中的整数 <strong>互不相同</strong></li>
	<li><code>pieces</code> 中的整数 <strong>互不相同</strong>（也就是说，如果将 <code>pieces</code> 扁平化成一维数组，数组中的所有整数互不相同）</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：暴力枚举

遍历 `arr`，在 `pieces` 中找到首元素等于当前 `arr[i]` 的数组项，如果找不到，直接返回 `false`。

如果找到了，我们记数组项为 `pieces[k]`，然后继续往后遍历 `arr[i]` 和 `pieces[k]`，直至 `pieces[k]` 遍历完或者元素不等。

遍历结束，返回 `true`。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canFormArray(self, arr: List[int], pieces: List[List[int]]) -> bool:
        i = 0
        while i < len(arr):
            k = 0
            while k < len(pieces) and pieces[k][0] != arr[i]:
                k += 1
            if k == len(pieces):
                return False
            j = 0
            while j < len(pieces[k]) and arr[i] == pieces[k][j]:
                i, j = i + 1, j + 1
        return True
```

#### Java

```java
class Solution {
    public boolean canFormArray(int[] arr, int[][] pieces) {
        for (int i = 0; i < arr.length;) {
            int k = 0;
            while (k < pieces.length && pieces[k][0] != arr[i]) {
                ++k;
            }
            if (k == pieces.length) {
                return false;
            }
            int j = 0;
            while (j < pieces[k].length && arr[i] == pieces[k][j]) {
                ++i;
                ++j;
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
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        for (int i = 0; i < arr.size();) {
            int k = 0;
            while (k < pieces.size() && pieces[k][0] != arr[i]) {
                ++k;
            }
            if (k == pieces.size()) {
                return false;
            }
            int j = 0;
            while (j < pieces[k].size() && arr[i] == pieces[k][j]) {
                ++i;
                ++j;
            }
        }
        return true;
    }
};
```

#### Go

```go
func canFormArray(arr []int, pieces [][]int) bool {
	for i := 0; i < len(arr); {
		k := 0
		for k < len(pieces) && pieces[k][0] != arr[i] {
			k++
		}
		if k == len(pieces) {
			return false
		}
		j := 0
		for j < len(pieces[k]) && arr[i] == pieces[k][j] {
			i, j = i+1, j+1
		}
	}
	return true
}
```

#### TypeScript

```ts
function canFormArray(arr: number[], pieces: number[][]): boolean {
    const n = arr.length;
    let i = 0;
    while (i < n) {
        const target = arr[i];
        const items = pieces.find(v => v[0] === target);
        if (items == null) {
            return false;
        }
        for (const item of items) {
            if (item !== arr[i]) {
                return false;
            }
            i++;
        }
    }
    return true;
}
```

#### Rust

```rust
use std::collections::HashMap;
impl Solution {
    pub fn can_form_array(arr: Vec<i32>, pieces: Vec<Vec<i32>>) -> bool {
        let n = arr.len();
        let mut map = HashMap::new();
        for (i, v) in pieces.iter().enumerate() {
            map.insert(v[0], i);
        }
        let mut i = 0;
        while i < n {
            match map.get(&arr[i]) {
                None => {
                    return false;
                }
                Some(&j) => {
                    for &item in pieces[j].iter() {
                        if item != arr[i] {
                            return false;
                        }
                        i += 1;
                    }
                }
            }
        }
        true
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} arr
 * @param {number[][]} pieces
 * @return {boolean}
 */
var canFormArray = function (arr, pieces) {
    const d = new Map();
    for (const p of pieces) {
        d.set(p[0], p);
    }
    for (let i = 0; i < arr.length; ) {
        if (!d.has(arr[i])) {
            return false;
        }
        const p = d.get(arr[i]);
        for (const v of p) {
            if (arr[i++] != v) {
                return false;
            }
        }
    }
    return true;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：哈希表

创建一个哈希表，键为 `pieces` 中每个数组项的首元素，值为数组项。

遍历 `arr`，如果当前元素在哈希表中不存在，直接返回 `false`；否则，取出哈希表中对应的数组项，判断其与 `arr` 中的元素是否相等，如果不相等，直接返回 `false`。

否则，遍历结束，返回 `true`。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为 `arr` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canFormArray(self, arr: List[int], pieces: List[List[int]]) -> bool:
        d = {p[0]: p for p in pieces}
        i, n = 0, len(arr)
        while i < n:
            if arr[i] not in d:
                return False
            p = d[arr[i]]
            if arr[i : i + len(p)] != p:
                return False
            i += len(p)
        return True
```

#### Java

```java
class Solution {
    public boolean canFormArray(int[] arr, int[][] pieces) {
        Map<Integer, int[]> d = new HashMap<>();
        for (var p : pieces) {
            d.put(p[0], p);
        }
        for (int i = 0; i < arr.length;) {
            if (!d.containsKey(arr[i])) {
                return false;
            }
            for (int v : d.get(arr[i])) {
                if (arr[i++] != v) {
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
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, vector<int>> d;
        for (auto& p : pieces) {
            d[p[0]] = p;
        }
        for (int i = 0; i < arr.size();) {
            if (!d.count(arr[i])) {
                return false;
            }
            for (int& v : d[arr[i]]) {
                if (arr[i++] != v) {
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
func canFormArray(arr []int, pieces [][]int) bool {
	d := map[int][]int{}
	for _, p := range pieces {
		d[p[0]] = p
	}
	for i := 0; i < len(arr); {
		p, ok := d[arr[i]]
		if !ok {
			return false
		}
		for _, v := range p {
			if arr[i] != v {
				return false
			}
			i++
		}
	}
	return true
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1641. 统计字典序元音字符串的数目](https://leetcode.cn/problems/count-sorted-vowel-strings){#1641}

{{< tabs "1641" >}}

{{% tab "python" %}}
```python
class Solution:
    def countVowelStrings(self, n: int) -> int:
        f = [1] * 5
        for _ in range(n - 1):
            s = 0
            for j in range(5):
                s += f[j]
                f[j] = s
        return sum(f)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countVowelStrings(int n) {
        int[] f = {1, 1, 1, 1, 1};
        for (int i = 0; i < n - 1; ++i) {
            int s = 0;
            for (int j = 0; j < 5; ++j) {
                s += f[j];
                f[j] = s;
            }
        }
        return Arrays.stream(f).sum();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int countVowelStrings(int n) {
        int f[5] = {1, 1, 1, 1, 1};
        for (int i = 0; i < n - 1; ++i) {
            int s = 0;
            for (int j = 0; j < 5; ++j) {
                s += f[j];
                f[j] = s;
            }
        }
        return accumulate(f, f + 5, 0);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countVowelStrings(n int) (ans int) {
	f := [5]int{1, 1, 1, 1, 1}
	for i := 0; i < n-1; i++ {
		s := 0
		for j := 0; j < 5; j++ {
			s += f[j]
			f[j] = s
		}
	}
	for _, v := range f {
		ans += v
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

<p>给你一个整数 <code>n</code>，请返回长度为 <code>n</code> 、仅由元音 (<code>a</code>, <code>e</code>, <code>i</code>, <code>o</code>, <code>u</code>) 组成且按 <strong>字典序排列</strong> 的字符串数量。</p>

<p>字符串 <code>s</code> 按 <strong>字典序排列</strong> 需要满足：对于所有有效的 <code>i</code>，<code>s[i]</code> 在字母表中的位置总是与 <code>s[i+1]</code> 相同或在 <code>s[i+1]</code> 之前。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 1
<strong>输出：</strong>5
<strong>解释：</strong>仅由元音组成的 5 个字典序字符串为 <code>["a","e","i","o","u"]</code>
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 2
<strong>输出：</strong>15
<strong>解释：</strong>仅由元音组成的 15 个字典序字符串为
["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"]
注意，"ea" 不是符合题意的字符串，因为 'e' 在字母表中的位置比 'a' 靠后
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 33
<strong>输出：</strong>66045
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= n <= 50</code> </li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $dfs(i, j)$，表示当前已经选了 $i$ 个元音字母，且最后一个元音字母是 $j$ 的方案数。那么答案就是 $dfs(0, 0)$。

函数 $dfs(i, j)$ 的计算过程如下：

-   如果 $i \ge n$，说明已经选了 $n$ 个元音字母，返回 $1$。
-   否则，枚举 $j$ 后面的元音字母，即 $k \in [j, 4]$，并将 $dfs(i + 1, k)$ 的结果累加，即 $dfs(i, j) = \sum_{k = j}^4 dfs(i + 1, k)$。

过程中，我们可以使用记忆化搜索，将已经计算过的 $dfs(i, j)$ 的结果保存起来，避免重复计算。

时间复杂度 $O(n \times C^2)$，空间复杂度 $O(n \times C)$。其中 $n$ 为题目给定的整数，而 $C$ 是元音字母的数量，本题中 $C = 5$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countVowelStrings(self, n: int) -> int:
        @cache
        def dfs(i, j):
            return 1 if i >= n else sum(dfs(i + 1, k) for k in range(j, 5))

        return dfs(0, 0)
```

#### Java

```java
class Solution {
    private Integer[][] f;
    private int n;

    public int countVowelStrings(int n) {
        this.n = n;
        f = new Integer[n][5];
        return dfs(0, 0);
    }

    private int dfs(int i, int j) {
        if (i >= n) {
            return 1;
        }
        if (f[i][j] != null) {
            return f[i][j];
        }
        int ans = 0;
        for (int k = j; k < 5; ++k) {
            ans += dfs(i + 1, k);
        }
        return f[i][j] = ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countVowelStrings(int n) {
        int f[n][5];
        memset(f, 0, sizeof f);
        function<int(int, int)> dfs = [&](int i, int j) {
            if (i >= n) {
                return 1;
            }
            if (f[i][j]) {
                return f[i][j];
            }
            int ans = 0;
            for (int k = j; k < 5; ++k) {
                ans += dfs(i + 1, k);
            }
            return f[i][j] = ans;
        };
        return dfs(0, 0);
    }
};
```

#### Go

```go
func countVowelStrings(n int) int {
	f := make([][5]int, n)
	var dfs func(i, j int) int
	dfs = func(i, j int) int {
		if i >= n {
			return 1
		}
		if f[i][j] != 0 {
			return f[i][j]
		}
		ans := 0
		for k := j; k < 5; k++ {
			ans += dfs(i+1, k)
		}
		f[i][j] = ans
		return ans
	}
	return dfs(0, 0)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划 + 前缀和

定义 $f[i][j]$ 表示当前已经选了 $i$ 个元音字母，且最后一个元音字母是 $j$ 的方案数。初始时 $f[1][j]=1$。答案是 $\sum_{j = 0}^4 f[n][j]$。

我们可以发现 $f[i][j]$ 只与 $f[i - 1][j]$ 有关，因此可以将二维数组压缩为一维数组，从而优化空间复杂度。

时间复杂度 $O(n \times C)$，空间复杂度 $O(C)$。其中 $n$ 为题目给定的整数，而 $C$ 是元音字母的数量，本题中 $C = 5$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countVowelStrings(self, n: int) -> int:
        f = [1] * 5
        for _ in range(n - 1):
            s = 0
            for j in range(5):
                s += f[j]
                f[j] = s
        return sum(f)
```

#### Java

```java
class Solution {
    public int countVowelStrings(int n) {
        int[] f = {1, 1, 1, 1, 1};
        for (int i = 0; i < n - 1; ++i) {
            int s = 0;
            for (int j = 0; j < 5; ++j) {
                s += f[j];
                f[j] = s;
            }
        }
        return Arrays.stream(f).sum();
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countVowelStrings(int n) {
        int f[5] = {1, 1, 1, 1, 1};
        for (int i = 0; i < n - 1; ++i) {
            int s = 0;
            for (int j = 0; j < 5; ++j) {
                s += f[j];
                f[j] = s;
            }
        }
        return accumulate(f, f + 5, 0);
    }
};
```

#### Go

```go
func countVowelStrings(n int) (ans int) {
	f := [5]int{1, 1, 1, 1, 1}
	for i := 0; i < n-1; i++ {
		s := 0
		for j := 0; j < 5; j++ {
			s += f[j]
			f[j] = s
		}
	}
	for _, v := range f {
		ans += v
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1642. 可以到达的最远建筑](https://leetcode.cn/problems/furthest-building-you-can-reach){#1642}

{{< tabs "1642" >}}

{{% tab "python" %}}
```python
class Solution:
    def furthestBuilding(self, heights: List[int], bricks: int, ladders: int) -> int:
        h = []
        for i, a in enumerate(heights[:-1]):
            b = heights[i + 1]
            d = b - a
            if d > 0:
                heappush(h, d)
                if len(h) > ladders:
                    bricks -= heappop(h)
                    if bricks < 0:
                        return i
        return len(heights) - 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int furthestBuilding(int[] heights, int bricks, int ladders) {
        PriorityQueue<Integer> q = new PriorityQueue<>();
        int n = heights.length;
        for (int i = 0; i < n - 1; ++i) {
            int a = heights[i], b = heights[i + 1];
            int d = b - a;
            if (d > 0) {
                q.offer(d);
                if (q.size() > ladders) {
                    bricks -= q.poll();
                    if (bricks < 0) {
                        return i;
                    }
                }
            }
        }
        return n - 1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> q;
        int n = heights.size();
        for (int i = 0; i < n - 1; ++i) {
            int a = heights[i], b = heights[i + 1];
            int d = b - a;
            if (d > 0) {
                q.push(d);
                if (q.size() > ladders) {
                    bricks -= q.top();
                    q.pop();
                    if (bricks < 0) {
                        return i;
                    }
                }
            }
        }
        return n - 1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func furthestBuilding(heights []int, bricks int, ladders int) int {
	q := hp{}
	n := len(heights)
	for i, a := range heights[:n-1] {
		b := heights[i+1]
		d := b - a
		if d > 0 {
			heap.Push(&q, d)
			if q.Len() > ladders {
				bricks -= heap.Pop(&q).(int)
				if bricks < 0 {
					return i
				}
			}
		}
	}
	return n - 1
}

type hp struct{ sort.IntSlice }

func (h *hp) Push(v any) { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() any {
	a := h.IntSlice
	v := a[len(a)-1]
	h.IntSlice = a[:len(a)-1]
	return v
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>heights</code> ，表示建筑物的高度。另有一些砖块 <code>bricks</code> 和梯子 <code>ladders</code> 。</p>

<p>你从建筑物 <code>0</code> 开始旅程，不断向后面的建筑物移动，期间可能会用到砖块或梯子。</p>

<p>当从建筑物 <code>i</code> 移动到建筑物 <code>i+1</code>（下标<strong> 从 0 开始 </strong>）时：</p>

<ul>
	<li>如果当前建筑物的高度 <strong>大于或等于</strong> 下一建筑物的高度，则不需要梯子或砖块</li>
	<li>如果当前建筑的高度 <strong>小于</strong> 下一个建筑的高度，您可以使用 <strong>一架梯子</strong> 或 <strong><code>(h[i+1] - h[i])</code> 个砖块</strong></li>
</ul>
如果以最佳方式使用给定的梯子和砖块，返回你可以到达的最远建筑物的下标（下标<strong> 从 0 开始 </strong>）。

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1642.Furthest%20Building%20You%20Can%20Reach/images/q4.gif" style="width: 562px; height: 561px;" />
<pre>
<strong>输入：</strong>heights = [4,2,7,6,9,14,12], bricks = 5, ladders = 1
<strong>输出：</strong>4
<strong>解释：</strong>从建筑物 0 出发，你可以按此方案完成旅程：
- 不使用砖块或梯子到达建筑物 1 ，因为 4 >= 2
- 使用 5 个砖块到达建筑物 2 。你必须使用砖块或梯子，因为 2 < 7
- 不使用砖块或梯子到达建筑物 3 ，因为 7 >= 6
- 使用唯一的梯子到达建筑物 4 。你必须使用砖块或梯子，因为 6 < 9
无法越过建筑物 4 ，因为没有更多砖块或梯子。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>heights = [4,12,2,7,3,18,20,3,19], bricks = 10, ladders = 2
<strong>输出：</strong>7
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>heights = [14,3,19,3], bricks = 17, ladders = 0
<strong>输出：</strong>3
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= heights.length <= 10<sup>5</sup></code></li>
	<li><code>1 <= heights[i] <= 10<sup>6</sup></code></li>
	<li><code>0 <= bricks <= 10<sup>9</sup></code></li>
	<li><code>0 <= ladders <= heights.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 优先队列（小根堆）

梯子最好用在高度差较大的地方，因此我们可以将所有的高度差存入优先队列中，每次取出最小的高度差，如果梯子不够用，则用砖块填补，如果砖块不够用，则返回当前位置。

时间复杂度 $O(n\log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 `heights` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def furthestBuilding(self, heights: List[int], bricks: int, ladders: int) -> int:
        h = []
        for i, a in enumerate(heights[:-1]):
            b = heights[i + 1]
            d = b - a
            if d > 0:
                heappush(h, d)
                if len(h) > ladders:
                    bricks -= heappop(h)
                    if bricks < 0:
                        return i
        return len(heights) - 1
```

#### Java

```java
class Solution {
    public int furthestBuilding(int[] heights, int bricks, int ladders) {
        PriorityQueue<Integer> q = new PriorityQueue<>();
        int n = heights.length;
        for (int i = 0; i < n - 1; ++i) {
            int a = heights[i], b = heights[i + 1];
            int d = b - a;
            if (d > 0) {
                q.offer(d);
                if (q.size() > ladders) {
                    bricks -= q.poll();
                    if (bricks < 0) {
                        return i;
                    }
                }
            }
        }
        return n - 1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> q;
        int n = heights.size();
        for (int i = 0; i < n - 1; ++i) {
            int a = heights[i], b = heights[i + 1];
            int d = b - a;
            if (d > 0) {
                q.push(d);
                if (q.size() > ladders) {
                    bricks -= q.top();
                    q.pop();
                    if (bricks < 0) {
                        return i;
                    }
                }
            }
        }
        return n - 1;
    }
};
```

#### Go

```go
func furthestBuilding(heights []int, bricks int, ladders int) int {
	q := hp{}
	n := len(heights)
	for i, a := range heights[:n-1] {
		b := heights[i+1]
		d := b - a
		if d > 0 {
			heap.Push(&q, d)
			if q.Len() > ladders {
				bricks -= heap.Pop(&q).(int)
				if bricks < 0 {
					return i
				}
			}
		}
	}
	return n - 1
}

type hp struct{ sort.IntSlice }

func (h *hp) Push(v any) { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() any {
	a := h.IntSlice
	v := a[len(a)-1]
	h.IntSlice = a[:len(a)-1]
	return v
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1643. 第 K 条最小指令](https://leetcode.cn/problems/kth-smallest-instructions){#1643}

{{< tabs "1643" >}}

{{% tab "python" %}}
```python
class Solution:
    def kthSmallestPath(self, destination: List[int], k: int) -> str:
        v, h = destination
        ans = []
        for _ in range(h + v):
            if h == 0:
                ans.append("V")
            else:
                x = comb(h + v - 1, h - 1)
                if k > x:
                    ans.append("V")
                    v -= 1
                    k -= x
                else:
                    ans.append("H")
                    h -= 1
        return "".join(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String kthSmallestPath(int[] destination, int k) {
        int v = destination[0], h = destination[1];
        int n = v + h;
        int[][] c = new int[n + 1][h + 1];
        c[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            c[i][0] = 1;
            for (int j = 1; j <= h; ++j) {
                c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
            }
        }
        StringBuilder ans = new StringBuilder();
        for (int i = n; i > 0; --i) {
            if (h == 0) {
                ans.append('V');
            } else {
                int x = c[v + h - 1][h - 1];
                if (k > x) {
                    ans.append('V');
                    k -= x;
                    --v;
                } else {
                    ans.append('H');
                    --h;
                }
            }
        }
        return ans.toString();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        int v = destination[0], h = destination[1];
        int n = v + h;
        int c[n + 1][h + 1];
        memset(c, 0, sizeof(c));
        c[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            c[i][0] = 1;
            for (int j = 1; j <= h; ++j) {
                c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
            }
        }
        string ans;
        for (int i = 0; i < n; ++i) {
            if (h == 0) {
                ans.push_back('V');
            } else {
                int x = c[v + h - 1][h - 1];
                if (k > x) {
                    ans.push_back('V');
                    --v;
                    k -= x;
                } else {
                    ans.push_back('H');
                    --h;
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
func kthSmallestPath(destination []int, k int) string {
	v, h := destination[0], destination[1]
	n := v + h
	c := make([][]int, n+1)
	for i := range c {
		c[i] = make([]int, h+1)
		c[i][0] = 1
	}
	for i := 1; i <= n; i++ {
		for j := 1; j <= h; j++ {
			c[i][j] = c[i-1][j] + c[i-1][j-1]
		}
	}
	ans := []byte{}
	for i := 0; i < n; i++ {
		if h == 0 {
			ans = append(ans, 'V')
		} else {
			x := c[v+h-1][h-1]
			if k > x {
				ans = append(ans, 'V')
				k -= x
				v--
			} else {
				ans = append(ans, 'H')
				h--
			}
		}
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

<p>Bob 站在单元格 <code>(0, 0)</code> ，想要前往目的地 <code>destination</code> ：<code>(row, column)</code> 。他只能向 <strong>右</strong> 或向 <strong>下</strong> 走。你可以为 Bob 提供导航 <strong>指令</strong> 来帮助他到达目的地 <code>destination</code> 。</p>

<p><strong>指令</strong> 用字符串表示，其中每个字符：</p>

<ul>
	<li><code>'H'</code> ，意味着水平向右移动</li>
	<li><code>'V'</code> ，意味着竖直向下移动</li>
</ul>

<p>能够为 Bob 导航到目的地 <code>destination</code> 的指令可以有多种，例如，如果目的地 <code>destination</code> 是 <code>(2, 3)</code>，<code>"HHHVV"</code> 和 <code>"HVHVH"</code> 都是有效<strong> 指令</strong> 。</p>

<ul>
</ul>

<p>然而，Bob 很挑剔。因为他的幸运数字是 <code>k</code>，他想要遵循 <strong>按字典序排列后的第 <code>k</code> 条最小指令 </strong>的导航前往目的地 <code>destination</code> 。<code>k</code>  的编号 <strong>从 1 开始</strong> 。</p>

<p>给你一个整数数组 <code>destination</code> 和一个整数 <code>k</code> ，请你返回可以为<em> </em>Bob<em> </em>提供前往目的地 <code>destination</code> 导航的<strong> 按字典序排列后的第 <code>k</code> 条最小指令 </strong>。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1643.Kth%20Smallest%20Instructions/images/ex1.png" style="width: 300px;" /></p>

<pre>
<strong>输入：</strong>destination = [2,3], k = 1
<strong>输出：</strong>"HHHVV"
<strong>解释：</strong>能前往 (2, 3) 的所有导航指令 <strong>按字典序排列后</strong> 如下所示：
["HHHVV", "HHVHV", "HHVVH", "HVHHV", "HVHVH", "HVVHH", "VHHHV", "VHHVH", "VHVHH", "VVHHH"].
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1643.Kth%20Smallest%20Instructions/images/ex2.png" style="width: 300px; height: 229px;" /></strong></p>

<pre>
<strong>输入：</strong>destination = [2,3], k = 2
<strong>输出：</strong>"HHVHV"
</pre>

<p><strong>示例 3：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1643.Kth%20Smallest%20Instructions/images/ex3.png" style="width: 300px; height: 229px;" /></strong></p>

<pre>
<strong>输入：</strong>destination = [2,3], k = 3
<strong>输出：</strong>"HHVVH"
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>destination.length == 2</code></li>
	<li><code>1 <= row, column <= 15</code></li>
	<li><code>1 <= k <= nCr(row + column, row)</code>，其中 <code>nCr(a, b)</code> 表示组合数，即从 <code>a</code> 个物品中选 <code>b</code> 个物品的不同方案数。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：组合计数

根据题目描述我们可以知道，最终的路径是由 $destination[0]$ 个 `'V'` 和 $destination[1]$ 个 `'H'` 组成的，且按字典序排列后的第 $k$ 条最小指令。

我们首先考虑字典序的最高位，即最左边的字符。如果高位字符是 `'V'`，那么所有以 `'H'` 开头的路径的字典序都比它小，而以 `'H'` 开头的路径总数为 $x = C_{v+h-1}^{h-1}$。

如果 $k \lt x$，那么高位字符一定是 `'V'`，我们将 $k$ 减去 $x$，并将 $v$ 减 $1$，然后继续考虑下一位字符；否则，高位字符一定是 `'H'`，我们将 $h$ 减 $1$，然后继续考虑下一位字符。

注意，如果 $h = 0$，那么高位字符一定是 `'V'`，因为剩下的字符都是 `'V'`。

问题可以转换为求解 $C_{n}^{k}$，我们可以通过公式 $C_{n}^{k} = C_{n-1}^{k-1} + C_{n-1}^{k}$ 递推求解。

时间复杂度 $O((h + v) \times h)$，空间复杂度 $O((h + v) \times h)$。其中 $h$ 和 $v$ 分别为 $destination[1]$ 和 $destination[0]$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def kthSmallestPath(self, destination: List[int], k: int) -> str:
        v, h = destination
        ans = []
        for _ in range(h + v):
            if h == 0:
                ans.append("V")
            else:
                x = comb(h + v - 1, h - 1)
                if k > x:
                    ans.append("V")
                    v -= 1
                    k -= x
                else:
                    ans.append("H")
                    h -= 1
        return "".join(ans)
```

#### Java

```java
class Solution {
    public String kthSmallestPath(int[] destination, int k) {
        int v = destination[0], h = destination[1];
        int n = v + h;
        int[][] c = new int[n + 1][h + 1];
        c[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            c[i][0] = 1;
            for (int j = 1; j <= h; ++j) {
                c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
            }
        }
        StringBuilder ans = new StringBuilder();
        for (int i = n; i > 0; --i) {
            if (h == 0) {
                ans.append('V');
            } else {
                int x = c[v + h - 1][h - 1];
                if (k > x) {
                    ans.append('V');
                    k -= x;
                    --v;
                } else {
                    ans.append('H');
                    --h;
                }
            }
        }
        return ans.toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        int v = destination[0], h = destination[1];
        int n = v + h;
        int c[n + 1][h + 1];
        memset(c, 0, sizeof(c));
        c[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            c[i][0] = 1;
            for (int j = 1; j <= h; ++j) {
                c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
            }
        }
        string ans;
        for (int i = 0; i < n; ++i) {
            if (h == 0) {
                ans.push_back('V');
            } else {
                int x = c[v + h - 1][h - 1];
                if (k > x) {
                    ans.push_back('V');
                    --v;
                    k -= x;
                } else {
                    ans.push_back('H');
                    --h;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func kthSmallestPath(destination []int, k int) string {
	v, h := destination[0], destination[1]
	n := v + h
	c := make([][]int, n+1)
	for i := range c {
		c[i] = make([]int, h+1)
		c[i][0] = 1
	}
	for i := 1; i <= n; i++ {
		for j := 1; j <= h; j++ {
			c[i][j] = c[i-1][j] + c[i-1][j-1]
		}
	}
	ans := []byte{}
	for i := 0; i < n; i++ {
		if h == 0 {
			ans = append(ans, 'V')
		} else {
			x := c[v+h-1][h-1]
			if k > x {
				ans = append(ans, 'V')
				k -= x
				v--
			} else {
				ans = append(ans, 'H')
				h--
			}
		}
	}
	return string(ans)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1644. 二叉树的最近公共祖先 II 🔒](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree-ii){#1644}

{{< tabs "1644" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def lowestCommonAncestor(
        self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode'
    ) -> 'TreeNode':
        def dfs(root, p, q):
            if root is None:
                return False
            l = dfs(root.left, p, q)
            r = dfs(root.right, p, q)
            nonlocal ans
            if l and r:
                ans = root
            if (l or r) and (root.val == p.val or root.val == q.val):
                ans = root
            return l or r or root.val == p.val or root.val == q.val

        ans = None
        dfs(root, p, q)
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
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    private TreeNode ans;

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        dfs(root, p, q);
        return ans;
    }

    private boolean dfs(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null) {
            return false;
        }
        boolean l = dfs(root.left, p, q);
        boolean r = dfs(root.right, p, q);
        if (l && r) {
            ans = root;
        }
        if ((l || r) && (root.val == p.val || root.val == q.val)) {
            ans = root;
        }
        return l || r || root.val == p.val || root.val == q.val;
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }

private:
    TreeNode* ans = nullptr;

    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return false;
        }
        bool l = dfs(root->left, p, q);
        bool r = dfs(root->right, p, q);
        if (l && r) {
            ans = root;
        }
        if ((l || r) && (root->val == p->val || root->val == q->val)) {
            ans = root;
        }
        return l || r || root->val == p->val || root->val == q->val;
    }
};
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {TreeNode}
 */
var lowestCommonAncestor = function (root, p, q) {
    const dfs = root => {
        if (!root) {
            return false;
        }
        const l = dfs(root.left);
        const r = dfs(root.right);
        if (l && r) {
            ans = root;
        }
        if ((l || r) && (root.val === p.val || root.val === q.val)) {
            ans = root;
        }
        return l || r || root.val === p.val || root.val === q.val;
    };
    let ans = null;
    dfs(root);
    return ans;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一棵二叉树的根节点 <code>root</code>，返回给定节点 <code>p</code> 和 <code>q</code> 的最近公共祖先（LCA）节点。如果 <code>p</code> 或 <code>q</code> 之一<strong> 不存在</strong> 于该二叉树中，返回 <code>null</code>。树中的每个节点值都是互不相同的。</p>

<p>根据<a href="https://en.wikipedia.org/wiki/Lowest_common_ancestor" target="_blank">维基百科中对最近公共祖先节点的定义</a>：“两个节点 <code>p</code> 和 <code>q</code> 在二叉树 <code>T</code> 中的最近公共祖先节点是<strong> 后代节点 </strong>中既包括 <code>p</code>&nbsp;又包括&nbsp;<code>q</code>&nbsp;的最深节点（我们允许<strong> 一个节点为自身的一个后代节点 </strong>）”。一个节点 <code>x</code>&nbsp;的<strong> 后代节点 </strong>是节点&nbsp;<code>x</code> 到某一叶节点间的路径中的节点 <code>y</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1644.Lowest%20Common%20Ancestor%20of%20a%20Binary%20Tree%20II/images/binarytree.png" />
<pre>
<b>输入：</b> root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
<b>输出：</b> 3
<b>解释：</b> 节点 5 和 1 的共同祖先节点是 3。</pre>

<p><strong>示例 2:</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1644.Lowest%20Common%20Ancestor%20of%20a%20Binary%20Tree%20II/images/binarytree.png" /></p>

<pre>
<b>输入：</b> root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
<b>输出：</b> 5
<b>解释：</b> 节点 5 和 4 的共同祖先节点是 5。根据共同祖先节点的定义，一个节点可以是自身的后代节点。</pre>

<p><strong>示例 3:</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1644.Lowest%20Common%20Ancestor%20of%20a%20Binary%20Tree%20II/images/binarytree.png" /></p>

<pre>
<strong>输入：</strong> root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 10
<b>输出：</b> null
<b>解释：</b> 节点 10 不存在于树中，所以返回 null。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li>树中节点个数的范围是&nbsp;<code>[1, 10<sup>4</sup>]</code></li>
	<li><code>-10<sup>9</sup> &lt;= Node.val &lt;= 10<sup>9</sup></code></li>
	<li>所有节点的值&nbsp;<code>Node.val</code> <strong>互不相同</strong></li>
	<li><code>p != q</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong> 在不检查节点是否存在的情况下，你可以遍历树找出最近公共祖先节点吗？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归（后序遍历）

我们设计一个函数 $dfs(root, p, q)$，该函数返回以 $root$ 为根节点的二叉树中是否包含节点 $p$ 或节点 $q$，如果包含，则返回 `true`，否则返回 `false`。

函数 $dfs(root, p, q)$ 的递归过程如下：

如果当前节点 $root$ 为空，则返回 `false`。

否则，我们递归地遍历左子树和右子树，得到 $l$ 和 $r$，分别表示左子树和右子树中是否包含节点 $p$ 或节点 $q$。

如果 $l$ 和 $r$ 都为 `true`，说明当前节点 $root$ 就是我们要找的最近公共祖先节点，将其赋值给变量 $ans$。

如果 $l$ 或 $r$ 为 `true`，并且当前节点 $root$ 的值等于节点 $p$ 或节点 $q$ 的值，说明当前节点 $root$ 就是我们要找的最近公共祖先节点，将其赋值给变量 $ans$。

最后，我们判断 $l$ 或 $r$ 是否为 `true`，或者当前节点 $root$ 的值是否等于节点 $p$ 或节点 $q$ 的值，如果是，则返回 `true`，否则返回 `false`。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是二叉树的节点个数。

<!-- tabs:start -->

#### Python3

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def lowestCommonAncestor(
        self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode'
    ) -> 'TreeNode':
        def dfs(root, p, q):
            if root is None:
                return False
            l = dfs(root.left, p, q)
            r = dfs(root.right, p, q)
            nonlocal ans
            if l and r:
                ans = root
            if (l or r) and (root.val == p.val or root.val == q.val):
                ans = root
            return l or r or root.val == p.val or root.val == q.val

        ans = None
        dfs(root, p, q)
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
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    private TreeNode ans;

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        dfs(root, p, q);
        return ans;
    }

    private boolean dfs(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null) {
            return false;
        }
        boolean l = dfs(root.left, p, q);
        boolean r = dfs(root.right, p, q);
        if (l && r) {
            ans = root;
        }
        if ((l || r) && (root.val == p.val || root.val == q.val)) {
            ans = root;
        }
        return l || r || root.val == p.val || root.val == q.val;
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }

private:
    TreeNode* ans = nullptr;

    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return false;
        }
        bool l = dfs(root->left, p, q);
        bool r = dfs(root->right, p, q);
        if (l && r) {
            ans = root;
        }
        if ((l || r) && (root->val == p->val || root->val == q->val)) {
            ans = root;
        }
        return l || r || root->val == p->val || root->val == q->val;
    }
};
```

#### JavaScript

```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {TreeNode}
 */
var lowestCommonAncestor = function (root, p, q) {
    const dfs = root => {
        if (!root) {
            return false;
        }
        const l = dfs(root.left);
        const r = dfs(root.right);
        if (l && r) {
            ans = root;
        }
        if ((l || r) && (root.val === p.val || root.val === q.val)) {
            ans = root;
        }
        return l || r || root.val === p.val || root.val === q.val;
    };
    let ans = null;
    dfs(root);
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1645. Hopper 公司查询 II 🔒](https://leetcode.cn/problems/hopper-company-queries-ii){#1645}

{{< tabs "1645" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH RECURSIVE
    Month AS (
        SELECT 1 AS month
        UNION
        SELECT month + 1
        FROM Month
        WHERE month < 12
    ),
    S AS (
        SELECT month, driver_id, join_date
        FROM
            Month AS m
            LEFT JOIN Drivers AS d
                ON YEAR(d.join_date) < 2020
                OR (YEAR(d.join_date) = 2020 AND MONTH(d.join_date) <= month)
    ),
    T AS (
        SELECT driver_id, requested_at
        FROM
            Rides
            JOIN AcceptedRides USING (ride_id)
        WHERE YEAR(requested_at) = 2020
    )
SELECT
    month,
    IFNULL(
        ROUND(COUNT(DISTINCT t.driver_id) * 100 / COUNT(DISTINCT s.driver_id), 2),
        0
    ) AS working_percentage
FROM
    S AS s
    LEFT JOIN T AS t
        ON s.driver_id = t.driver_id
        AND s.join_date <= t.requested_at
        AND s.month = MONTH(t.requested_at)
GROUP BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Drivers</code></p>

<pre>
+-------------+---------+
| Column Name | Type &nbsp; &nbsp;|
+-------------+---------+
| driver_id &nbsp; | int &nbsp; &nbsp; |
| join_date &nbsp; | date &nbsp; &nbsp;|
+-------------+---------+
driver_id 是该表具有唯一值的列。
该表的每一行均包含驾驶员的ID以及他们加入 Hopper 公司的日期。
</pre>

<p>&nbsp;</p>

<p>表: <code>Rides</code></p>

<pre>
+--------------+---------+
| Column Name &nbsp;| Type &nbsp; &nbsp;|
+--------------+---------+
| ride_id &nbsp; &nbsp; &nbsp;| int &nbsp; &nbsp; |
| user_id &nbsp; &nbsp; &nbsp;| int &nbsp; &nbsp; |
| requested_at | date &nbsp; &nbsp;|
+--------------+---------+
ride_id 是该表具有唯一值的列。
该表的每一行均包含行程 ID(ride_id)，用户 ID(user_id) 以及该行程的日期 (requested_at)。
该表中可能有一些不被接受的乘车请求。</pre>

<p>&nbsp;</p>

<p>表: <code>AcceptedRides</code></p>

<pre>
+---------------+---------+
| Column Name &nbsp; | Type &nbsp; &nbsp;|
+---------------+---------+
| ride_id &nbsp; &nbsp; &nbsp; | int &nbsp; &nbsp; |
| driver_id &nbsp; &nbsp; | int &nbsp; &nbsp; |
| ride_distance | int &nbsp; &nbsp; |
| ride_duration | int &nbsp; &nbsp; |
+---------------+---------+
ride_id 是该表具有唯一值的列。
该表的每一行都包含已接受的行程信息。
表中的行程信息都在 "Rides" 表中存在。
</pre>

<p>&nbsp;</p>

<p>编写解决方案以报告 <strong>2020</strong> 年每个月的工作驱动因素&nbsp;<strong>百分比</strong>（<code>working_percentage</code>），其中：</p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1645.Hopper%20Company%20Queries%20II/images/codecogseqn.png" style="width: 800px; height: 36px;" />
<p>&nbsp;</p>

<p><strong>注意：</strong>如果一个月内可用驾驶员的数量为零，我们认为&nbsp;<code>working_percentage</code>&nbsp;为&nbsp;<code>0</code><strong>。</strong></p>

<p>返回按&nbsp;<code>month</code>&nbsp;<strong>升序&nbsp;</strong>排列的结果表，其中&nbsp;<code>month</code>&nbsp;是月份的编号（一月是&nbsp;<code>1</code>，二月是&nbsp;<code>2</code>，等等）。将&nbsp;<code>working_percentage</code>&nbsp;四舍五入至&nbsp;<strong>小数点后两位</strong>。</p>

<p>结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入：</strong>
表 Drivers:
+-----------+------------+
| driver_id | join_date &nbsp;|
+-----------+------------+
| 10 &nbsp; &nbsp; &nbsp; &nbsp;| 2019-12-10 |
| 8 &nbsp; &nbsp; &nbsp; &nbsp; | 2020-1-13 &nbsp;|
| 5 &nbsp; &nbsp; &nbsp; &nbsp; | 2020-2-16 &nbsp;|
| 7 &nbsp; &nbsp; &nbsp; &nbsp; | 2020-3-8 &nbsp; |
| 4 &nbsp; &nbsp; &nbsp; &nbsp; | 2020-5-17 &nbsp;|
| 1 &nbsp; &nbsp; &nbsp; &nbsp; | 2020-10-24 |
| 6 &nbsp; &nbsp; &nbsp; &nbsp; | 2021-1-5 &nbsp; |
+-----------+------------+

表 Rides:
+---------+---------+--------------+
| ride_id | user_id | requested_at |
+---------+---------+--------------+
| 6 &nbsp; &nbsp; &nbsp; | 75 &nbsp; &nbsp; &nbsp;| 2019-12-9 &nbsp; &nbsp;|
| 1 &nbsp; &nbsp; &nbsp; | 54 &nbsp; &nbsp; &nbsp;| 2020-2-9 &nbsp; &nbsp; |
| 10 &nbsp; &nbsp; &nbsp;| 63 &nbsp; &nbsp; &nbsp;| 2020-3-4 &nbsp; &nbsp; |
| 19 &nbsp; &nbsp; &nbsp;| 39 &nbsp; &nbsp; &nbsp;| 2020-4-6 &nbsp; &nbsp; |
| 3 &nbsp; &nbsp; &nbsp; | 41 &nbsp; &nbsp; &nbsp;| 2020-6-3 &nbsp; &nbsp; |
| 13 &nbsp; &nbsp; &nbsp;| 52 &nbsp; &nbsp; &nbsp;| 2020-6-22 &nbsp; &nbsp;|
| 7 &nbsp; &nbsp; &nbsp; | 69 &nbsp; &nbsp; &nbsp;| 2020-7-16 &nbsp; &nbsp;|
| 17 &nbsp; &nbsp; &nbsp;| 70 &nbsp; &nbsp; &nbsp;| 2020-8-25 &nbsp; &nbsp;|
| 20 &nbsp; &nbsp; &nbsp;| 81 &nbsp; &nbsp; &nbsp;| 2020-11-2 &nbsp; &nbsp;|
| 5 &nbsp; &nbsp; &nbsp; | 57 &nbsp; &nbsp; &nbsp;| 2020-11-9 &nbsp; &nbsp;|
| 2 &nbsp; &nbsp; &nbsp; | 42 &nbsp; &nbsp; &nbsp;| 2020-12-9 &nbsp; &nbsp;|
| 11 &nbsp; &nbsp; &nbsp;| 68 &nbsp; &nbsp; &nbsp;| 2021-1-11 &nbsp; &nbsp;|
| 15 &nbsp; &nbsp; &nbsp;| 32 &nbsp; &nbsp; &nbsp;| 2021-1-17 &nbsp; &nbsp;|
| 12 &nbsp; &nbsp; &nbsp;| 11 &nbsp; &nbsp; &nbsp;| 2021-1-19 &nbsp; &nbsp;|
| 14 &nbsp; &nbsp; &nbsp;| 18 &nbsp; &nbsp; &nbsp;| 2021-1-27 &nbsp; &nbsp;|
+---------+---------+--------------+

表 AcceptedRides:
+---------+-----------+---------------+---------------+
| ride_id | driver_id | ride_distance | ride_duration |
+---------+-----------+---------------+---------------+
| 10 &nbsp; &nbsp; &nbsp;| 10 &nbsp; &nbsp; &nbsp; &nbsp;| 63 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;| 38 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|
| 13 &nbsp; &nbsp; &nbsp;| 10 &nbsp; &nbsp; &nbsp; &nbsp;| 73 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;| 96 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|
| 7 &nbsp; &nbsp; &nbsp; | 8 &nbsp; &nbsp; &nbsp; &nbsp; | 100 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; | 28 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|
| 17 &nbsp; &nbsp; &nbsp;| 7 &nbsp; &nbsp; &nbsp; &nbsp; | 119 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; | 68 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|
| 20 &nbsp; &nbsp; &nbsp;| 1 &nbsp; &nbsp; &nbsp; &nbsp; | 121 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; | 92 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|
| 5 &nbsp; &nbsp; &nbsp; | 7 &nbsp; &nbsp; &nbsp; &nbsp; | 42 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;| 101 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; |
| 2 &nbsp; &nbsp; &nbsp; | 4 &nbsp; &nbsp; &nbsp; &nbsp; | 6 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; | 38 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|
| 11 &nbsp; &nbsp; &nbsp;| 8 &nbsp; &nbsp; &nbsp; &nbsp; | 37 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;| 43 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|
| 15 &nbsp; &nbsp; &nbsp;| 8 &nbsp; &nbsp; &nbsp; &nbsp; | 108 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; | 82 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|
| 12 &nbsp; &nbsp; &nbsp;| 8 &nbsp; &nbsp; &nbsp; &nbsp; | 38 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;| 34 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|
| 14 &nbsp; &nbsp; &nbsp;| 1 &nbsp; &nbsp; &nbsp; &nbsp; | 90 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;| 74 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|
+---------+-----------+---------------+---------------+
<strong>输出：</strong>
+-------+--------------------+
| month | working_percentage |
+-------+--------------------+
| 1 &nbsp; &nbsp; | 0.00 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; |
| 2 &nbsp; &nbsp; | 0.00 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; |
| 3 &nbsp; &nbsp; | 25.00 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|
| 4 &nbsp; &nbsp; | 0.00 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; |
| 5 &nbsp; &nbsp; | 0.00 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; |
| 6 &nbsp; &nbsp; | 20.00 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|
| 7 &nbsp; &nbsp; | 20.00 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|
| 8 &nbsp; &nbsp; | 20.00 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|
| 9 &nbsp; &nbsp; | 0.00 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; |
| 10 &nbsp; &nbsp;| 0.00 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; |
| 11 &nbsp; &nbsp;| 33.33 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|
| 12 &nbsp; &nbsp;| 16.67 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|
+-------+--------------------+
<strong>解释：</strong>
截至 1 月底 --&gt; 2 个活跃的驾驶员 (10, 8)，无被接受的行程。百分比是0%。
截至 2 月底 --&gt; 3 个活跃的驾驶员 (10, 8, 5)，无被接受的行程。百分比是0%。
截至 3 月底 --&gt; 4 个活跃的驾驶员 (10, 8, 5, 7)，1 个被驾驶员 (10) 接受的行程。百分比是 (1 / 4) * 100 = 25%。
截至 4 月底 --&gt; 4 个活跃的驾驶员 (10, 8, 5, 7)，无被接受的行程。百分比是 0%。
截至 5 月底 --&gt; 5 个活跃的驾驶员 (10, 8, 5, 7, 4)，无被接受的行程。百分比是 0%。
截至 6 月底 --&gt; 5 个活跃的驾驶员 (10, 8, 5, 7, 4)，1 个被驾驶员 (10) 接受的行程。 百分比是 (1 / 5) * 100 = 20%。
截至 7 月底 --&gt; 5 个活跃的驾驶员 (10, 8, 5, 7, 4)，1 个被驾驶员 (8) 接受的行程。百分比是 (1 / 5) * 100 = 20%。
截至 8 月底 --&gt; 5 个活跃的驾驶员 (10, 8, 5, 7, 4)，1 个被驾驶员 (7) 接受的行程。百分比是 (1 / 5) * 100 = 20%。
截至 9 月底 --&gt; 5 个活跃的驾驶员 (10, 8, 5, 7, 4)，无被接受的行程。百分比是 0%。
截至 10 月底 --&gt; 6 个活跃的驾驶员 (10, 8, 5, 7, 4, 1) 无被接受的行程。百分比是 0%。
截至 11 月底 --&gt; 6 个活跃的驾驶员 (10, 8, 5, 7, 4, 1)，2 个被不同驾驶员 (1, 7) 接受的行程。百分比是 (2 / 6) * 100 = 33.33%。
截至 12 月底 --&gt; 6 个活跃的驾驶员 (10, 8, 5, 7, 4, 1)，1 个被驾驶员 (4) 接受的行程。百分比是 (1 / 6) * 100 = 16.67%。
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归 + 左连接 + 分组

我们可以使用递归的方法生成 $1 \sim 12$ 月的数据，记录在 `Month` 表中。

接下来，我们用 `Month` 表与 `Drivers` 表进行左连接，连接的条件是 `year(d.join_date) < 2020 or (year(d.join_date) = 2020 and month(d.join_date) <= month)`，这样就可以得到每个月的活跃司机数。

然后，我们再用 `Rides` 表与 `AcceptedRides` 表进行内连接，连接的条件是 `ride_id` 相等，并且我们只查出 `year(requested_at) = 2020` 的数据，这样就可以得到 $2020$ 年被接受的所有行程。

最后，我们将上面两个表进行左连接，连接的条件是 `month` 相等、`driver_id` 相等，并且 `join_date` 小于等于 `requested_at`，这样就可以得到每个月被接受的行程数，按月份进行分组，就可以得到每个月的活跃司机数和被接受的行程数，从而计算出每个月的接单率。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH RECURSIVE
    Month AS (
        SELECT 1 AS month
        UNION
        SELECT month + 1
        FROM Month
        WHERE month < 12
    ),
    S AS (
        SELECT month, driver_id, join_date
        FROM
            Month AS m
            LEFT JOIN Drivers AS d
                ON YEAR(d.join_date) < 2020
                OR (YEAR(d.join_date) = 2020 AND MONTH(d.join_date) <= month)
    ),
    T AS (
        SELECT driver_id, requested_at
        FROM
            Rides
            JOIN AcceptedRides USING (ride_id)
        WHERE YEAR(requested_at) = 2020
    )
SELECT
    month,
    IFNULL(
        ROUND(COUNT(DISTINCT t.driver_id) * 100 / COUNT(DISTINCT s.driver_id), 2),
        0
    ) AS working_percentage
FROM
    S AS s
    LEFT JOIN T AS t
        ON s.driver_id = t.driver_id
        AND s.join_date <= t.requested_at
        AND s.month = MONTH(t.requested_at)
GROUP BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1646. 获取生成数组中的最大值](https://leetcode.cn/problems/get-maximum-in-generated-array){#1646}

{{< tabs "1646" >}}

{{% tab "python" %}}
```python
class Solution:
    def getMaximumGenerated(self, n: int) -> int:
        if n < 2:
            return n
        nums = [0] * (n + 1)
        nums[1] = 1
        for i in range(2, n + 1):
            nums[i] = nums[i >> 1] if i % 2 == 0 else nums[i >> 1] + nums[(i >> 1) + 1]
        return max(nums)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int getMaximumGenerated(int n) {
        if (n < 2) {
            return n;
        }
        int[] nums = new int[n + 1];
        nums[1] = 1;
        for (int i = 2; i <= n; ++i) {
            nums[i] = i % 2 == 0 ? nums[i >> 1] : nums[i >> 1] + nums[(i >> 1) + 1];
        }
        return Arrays.stream(nums).max().getAsInt();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n < 2) {
            return n;
        }
        int nums[n + 1];
        nums[0] = 0;
        nums[1] = 1;
        for (int i = 2; i <= n; ++i) {
            nums[i] = i % 2 == 0 ? nums[i >> 1] : nums[i >> 1] + nums[(i >> 1) + 1];
        }
        return *max_element(nums, nums + n + 1);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getMaximumGenerated(n int) int {
	if n < 2 {
		return n
	}
	nums := make([]int, n+1)
	nums[1] = 1
	for i := 2; i <= n; i++ {
		if i%2 == 0 {
			nums[i] = nums[i/2]
		} else {
			nums[i] = nums[i/2] + nums[i/2+1]
		}
	}
	return slices.Max(nums)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function getMaximumGenerated(n: number): number {
    if (n === 0) {
        return 0;
    }
    const nums: number[] = new Array(n + 1).fill(0);
    nums[1] = 1;
    for (let i = 2; i < n + 1; ++i) {
        nums[i] = i % 2 === 0 ? nums[i >> 1] : nums[i >> 1] + nums[(i >> 1) + 1];
    }
    return Math.max(...nums);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数 <code>n</code> 。按下述规则生成一个长度为 <code>n + 1</code> 的数组 <code>nums</code> ：</p>

<ul>
	<li><code>nums[0] = 0</code></li>
	<li><code>nums[1] = 1</code></li>
	<li>当 <code>2 <= 2 * i <= n</code> 时，<code>nums[2 * i] = nums[i]</code></li>
	<li>当 <code>2 <= 2 * i + 1 <= n</code> 时，<code>nums[2 * i + 1] = nums[i] + nums[i + 1]</code></li>
</ul>

<p>返回生成数组 <code>nums</code> 中的 <strong>最大</strong> 值。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 7
<strong>输出：</strong>3
<strong>解释：</strong>根据规则：
  nums[0] = 0
  nums[1] = 1
  nums[(1 * 2) = 2] = nums[1] = 1
  nums[(1 * 2) + 1 = 3] = nums[1] + nums[2] = 1 + 1 = 2
  nums[(2 * 2) = 4] = nums[2] = 1
  nums[(2 * 2) + 1 = 5] = nums[2] + nums[3] = 1 + 2 = 3
  nums[(3 * 2) = 6] = nums[3] = 2
  nums[(3 * 2) + 1 = 7] = nums[3] + nums[4] = 2 + 1 = 3
因此，nums = [0,1,1,2,1,3,2,3]，最大值 3
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 2
<strong>输出：</strong>1
<strong>解释：</strong>根据规则，nums[0]、nums[1] 和 nums[2] 之中的最大值是 1
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 3
<strong>输出：</strong>2
<strong>解释：</strong>根据规则，nums[0]、nums[1]、nums[2] 和 nums[3] 之中的最大值是 2
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 <= n <= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们先判断 $n$ 的值，如果 $n < 2$，则直接返回 $n$。

否则，我们创建一个长度为 $n + 1$ 的数组 $nums$，并初始化 $nums[0] = 0$ 以及 $nums[1] = 1$。

然后从下标 $2$ 开始遍历，如果当前下标 $i$ 为偶数，则 $nums[i] = nums[i / 2]$，否则 $nums[i] = nums[i / 2] + nums[i / 2 + 1]$。

最后返回数组 $nums$ 中的最大值即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为给定的整数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getMaximumGenerated(self, n: int) -> int:
        if n < 2:
            return n
        nums = [0] * (n + 1)
        nums[1] = 1
        for i in range(2, n + 1):
            nums[i] = nums[i >> 1] if i % 2 == 0 else nums[i >> 1] + nums[(i >> 1) + 1]
        return max(nums)
```

#### Java

```java
class Solution {
    public int getMaximumGenerated(int n) {
        if (n < 2) {
            return n;
        }
        int[] nums = new int[n + 1];
        nums[1] = 1;
        for (int i = 2; i <= n; ++i) {
            nums[i] = i % 2 == 0 ? nums[i >> 1] : nums[i >> 1] + nums[(i >> 1) + 1];
        }
        return Arrays.stream(nums).max().getAsInt();
    }
}
```

#### C++

```cpp
class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n < 2) {
            return n;
        }
        int nums[n + 1];
        nums[0] = 0;
        nums[1] = 1;
        for (int i = 2; i <= n; ++i) {
            nums[i] = i % 2 == 0 ? nums[i >> 1] : nums[i >> 1] + nums[(i >> 1) + 1];
        }
        return *max_element(nums, nums + n + 1);
    }
};
```

#### Go

```go
func getMaximumGenerated(n int) int {
	if n < 2 {
		return n
	}
	nums := make([]int, n+1)
	nums[1] = 1
	for i := 2; i <= n; i++ {
		if i%2 == 0 {
			nums[i] = nums[i/2]
		} else {
			nums[i] = nums[i/2] + nums[i/2+1]
		}
	}
	return slices.Max(nums)
}
```

#### TypeScript

```ts
function getMaximumGenerated(n: number): number {
    if (n === 0) {
        return 0;
    }
    const nums: number[] = new Array(n + 1).fill(0);
    nums[1] = 1;
    for (let i = 2; i < n + 1; ++i) {
        nums[i] = i % 2 === 0 ? nums[i >> 1] : nums[i >> 1] + nums[(i >> 1) + 1];
    }
    return Math.max(...nums);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1647. 字符频次唯一的最小删除次数](https://leetcode.cn/problems/minimum-deletions-to-make-character-frequencies-unique){#1647}

{{< tabs "1647" >}}

{{% tab "python" %}}
```python
class Solution:
    def minDeletions(self, s: str) -> int:
        cnt = Counter(s)
        vals = sorted(cnt.values(), reverse=True)
        ans = 0
        for i in range(1, len(vals)):
            while vals[i] >= vals[i - 1] and vals[i] > 0:
                vals[i] -= 1
                ans += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minDeletions(String s) {
        int[] cnt = new int[26];
        for (int i = 0; i < s.length(); ++i) {
            ++cnt[s.charAt(i) - 'a'];
        }
        Arrays.sort(cnt);
        int ans = 0, pre = 1 << 30;
        for (int i = 25; i >= 0; --i) {
            int v = cnt[i];
            if (pre == 0) {
                ans += v;
            } else if (v >= pre) {
                ans += v - pre + 1;
                --pre;
            } else {
                pre = v;
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
    int minDeletions(string s) {
        vector<int> cnt(26);
        for (char& c : s) ++cnt[c - 'a'];
        sort(cnt.rbegin(), cnt.rend());
        int ans = 0, pre = 1 << 30;
        for (int& v : cnt) {
            if (pre == 0) {
                ans += v;
            } else if (v >= pre) {
                ans += v - pre + 1;
                --pre;
            } else {
                pre = v;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minDeletions(s string) (ans int) {
	cnt := make([]int, 26)
	for _, c := range s {
		cnt[c-'a']++
	}
	sort.Sort(sort.Reverse(sort.IntSlice(cnt)))
	pre := 1 << 30
	for _, v := range cnt {
		if pre == 0 {
			ans += v
		} else if v >= pre {
			ans += v - pre + 1
			pre--
		} else {
			pre = v
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minDeletions(s: string): number {
    let map = {};
    for (let c of s) {
        map[c] = (map[c] || 0) + 1;
    }
    let ans = 0;
    let vals: number[] = Object.values(map);
    vals.sort((a, b) => a - b);
    for (let i = 1; i < vals.length; ++i) {
        while (vals[i] > 0 && i != vals.indexOf(vals[i])) {
            --vals[i];
            ++ans;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    #[allow(dead_code)]
    pub fn min_deletions(s: String) -> i32 {
        let mut cnt = vec![0; 26];
        let mut ans = 0;

        for c in s.chars() {
            cnt[((c as u8) - ('a' as u8)) as usize] += 1;
        }

        cnt.sort_by(|&lhs, &rhs| rhs.cmp(&lhs));

        for i in 1..26 {
            while cnt[i] >= cnt[i - 1] && cnt[i] > 0 {
                cnt[i] -= 1;
                ans += 1;
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

<p>如果字符串 <code>s</code> 中 <strong>不存在</strong> 两个不同字符 <strong>频次</strong> 相同的情况，就称 <code>s</code> 是 <strong>优质字符串</strong> 。</p>

<p>给你一个字符串 <code>s</code>，返回使 <code>s</code> 成为 <strong>优质字符串</strong> 需要删除的 <strong>最小</strong> 字符数。</p>

<p>字符串中字符的 <strong>频次</strong> 是该字符在字符串中的出现次数。例如，在字符串 <code>"aab"</code> 中，<code>'a'</code> 的频次是 <code>2</code>，而 <code>'b'</code> 的频次是 <code>1</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "aab"
<strong>输出：</strong>0
<strong>解释：</strong><code>s</code> 已经是优质字符串。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "aaabbbcc"
<strong>输出：</strong>2
<strong>解释：</strong>可以删除两个 'b' , 得到优质字符串 "aaabcc" 。
另一种方式是删除一个 'b' 和一个 'c' ，得到优质字符串 "aaabbc" 。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "ceabaacb"
<strong>输出：</strong>2
<strong>解释：</strong>可以删除两个 'c' 得到优质字符串 "eabaab" 。
注意，只需要关注结果字符串中仍然存在的字符。（即，频次为 0 的字符会忽略不计。）
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= s.length <= 10<sup>5</sup></code></li>
	<li><code>s</code> 仅含小写英文字母</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数组 + 排序

我们先用一个长度为 $26$ 的数组 $\textit{cnt}$ 统计字符串 $s$ 中每个字母出现的次数。

然后我们对数组 $\textit{cnt}$ 进行倒序排序。定义一个变量 $\textit{pre}$ 记录当前字母的出现次数。

接下来，遍历数组 $\textit{cnt}$ 每个元素 $v$，如果当前 $\textit{pre}$ 等于 $0$，我们直接将答案加上 $v$；否则，如果 $v \geq \textit{pre}$，我们将答案加上 $v-\textit{pre}+1$，并且将 $\textit{pre}$ 减去 $1$，否则，我们直接将 $\textit{pre}$ 更新为 $v$。然后继续遍历下个元素。

遍历结束，返回答案即可。

时间复杂度 $O(n + |\Sigma| \times \log |\Sigma|)$，空间复杂度 $O(|\Sigma|)$。其中 $n$ 是字符串 $s$ 的长度，而 $|\Sigma|$ 为字母集的大小。本题中 $|\Sigma|=26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minDeletions(self, s: str) -> int:
        cnt = Counter(s)
        ans, pre = 0, inf
        for v in sorted(cnt.values(), reverse=True):
            if pre == 0:
                ans += v
            elif v >= pre:
                ans += v - pre + 1
                pre -= 1
            else:
                pre = v
        return ans
```

#### Java

```java
class Solution {
    public int minDeletions(String s) {
        int[] cnt = new int[26];
        for (int i = 0; i < s.length(); ++i) {
            ++cnt[s.charAt(i) - 'a'];
        }
        Arrays.sort(cnt);
        int ans = 0;
        for (int i = 24; i >= 0; --i) {
            while (cnt[i] >= cnt[i + 1] && cnt[i] > 0) {
                --cnt[i];
                ++ans;
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
    int minDeletions(string s) {
        vector<int> cnt(26);
        for (char& c : s) ++cnt[c - 'a'];
        sort(cnt.rbegin(), cnt.rend());
        int ans = 0;
        for (int i = 1; i < 26; ++i) {
            while (cnt[i] >= cnt[i - 1] && cnt[i] > 0) {
                --cnt[i];
                ++ans;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minDeletions(s string) (ans int) {
	cnt := make([]int, 26)
	for _, c := range s {
		cnt[c-'a']++
	}
	sort.Sort(sort.Reverse(sort.IntSlice(cnt)))
	for i := 1; i < 26; i++ {
		for cnt[i] >= cnt[i-1] && cnt[i] > 0 {
			cnt[i]--
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function minDeletions(s: string): number {
    let map = {};
    for (let c of s) {
        map[c] = (map[c] || 0) + 1;
    }
    let ans = 0;
    let vals: number[] = Object.values(map);
    vals.sort((a, b) => a - b);
    for (let i = 1; i < vals.length; ++i) {
        while (vals[i] > 0 && i != vals.indexOf(vals[i])) {
            --vals[i];
            ++ans;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    #[allow(dead_code)]
    pub fn min_deletions(s: String) -> i32 {
        let mut cnt = vec![0; 26];
        let mut ans = 0;

        for c in s.chars() {
            cnt[((c as u8) - ('a' as u8)) as usize] += 1;
        }

        cnt.sort_by(|&lhs, &rhs| rhs.cmp(&lhs));

        for i in 1..26 {
            while cnt[i] >= cnt[i - 1] && cnt[i] > 0 {
                cnt[i] -= 1;
                ans += 1;
            }
        }

        ans
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
    def minDeletions(self, s: str) -> int:
        cnt = Counter(s)
        vals = sorted(cnt.values(), reverse=True)
        ans = 0
        for i in range(1, len(vals)):
            while vals[i] >= vals[i - 1] and vals[i] > 0:
                vals[i] -= 1
                ans += 1
        return ans
```

#### Java

```java
class Solution {
    public int minDeletions(String s) {
        int[] cnt = new int[26];
        for (int i = 0; i < s.length(); ++i) {
            ++cnt[s.charAt(i) - 'a'];
        }
        Arrays.sort(cnt);
        int ans = 0, pre = 1 << 30;
        for (int i = 25; i >= 0; --i) {
            int v = cnt[i];
            if (pre == 0) {
                ans += v;
            } else if (v >= pre) {
                ans += v - pre + 1;
                --pre;
            } else {
                pre = v;
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
    int minDeletions(string s) {
        vector<int> cnt(26);
        for (char& c : s) ++cnt[c - 'a'];
        sort(cnt.rbegin(), cnt.rend());
        int ans = 0, pre = 1 << 30;
        for (int& v : cnt) {
            if (pre == 0) {
                ans += v;
            } else if (v >= pre) {
                ans += v - pre + 1;
                --pre;
            } else {
                pre = v;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minDeletions(s string) (ans int) {
	cnt := make([]int, 26)
	for _, c := range s {
		cnt[c-'a']++
	}
	sort.Sort(sort.Reverse(sort.IntSlice(cnt)))
	pre := 1 << 30
	for _, v := range cnt {
		if pre == 0 {
			ans += v
		} else if v >= pre {
			ans += v - pre + 1
			pre--
		} else {
			pre = v
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

# [1648. 销售价值减少的颜色球](https://leetcode.cn/problems/sell-diminishing-valued-colored-balls){#1648}

{{< tabs "1648" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxProfit(self, inventory: List[int], orders: int) -> int:
        inventory.sort(reverse=True)
        mod = 10**9 + 7
        ans = i = 0
        n = len(inventory)
        while orders > 0:
            while i < n and inventory[i] >= inventory[0]:
                i += 1
            nxt = 0
            if i < n:
                nxt = inventory[i]
            cnt = i
            x = inventory[0] - nxt
            tot = cnt * x
            if tot > orders:
                decr = orders // cnt
                a1, an = inventory[0] - decr + 1, inventory[0]
                ans += (a1 + an) * decr // 2 * cnt
                ans += (inventory[0] - decr) * (orders % cnt)
            else:
                a1, an = nxt + 1, inventory[0]
                ans += (a1 + an) * x // 2 * cnt
                inventory[0] = nxt
            orders -= tot
            ans %= mod
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private static final int MOD = (int) 1e9 + 7;

    public int maxProfit(int[] inventory, int orders) {
        Arrays.sort(inventory);
        int n = inventory.length;
        for (int i = 0, j = n - 1; i < j; ++i, --j) {
            int t = inventory[i];
            inventory[i] = inventory[j];
            inventory[j] = t;
        }
        long ans = 0;
        int i = 0;
        while (orders > 0) {
            while (i < n && inventory[i] >= inventory[0]) {
                ++i;
            }
            int nxt = i < n ? inventory[i] : 0;
            int cnt = i;
            long x = inventory[0] - nxt;
            long tot = cnt * x;
            if (tot > orders) {
                int decr = orders / cnt;
                long a1 = inventory[0] - decr + 1, an = inventory[0];
                ans += (a1 + an) * decr / 2 * cnt;
                ans += (a1 - 1) * (orders % cnt);
            } else {
                long a1 = nxt + 1, an = inventory[0];
                ans += (a1 + an) * x / 2 * cnt;
                inventory[0] = nxt;
            }
            orders -= tot;
            ans %= MOD;
        }
        return (int) ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        long ans = 0, mod = 1e9 + 7;
        int i = 0, n = inventory.size();
        sort(inventory.rbegin(), inventory.rend());
        while (orders > 0) {
            while (i < n && inventory[i] >= inventory[0]) {
                ++i;
            }
            int nxt = i < n ? inventory[i] : 0;
            int cnt = i;
            long x = inventory[0] - nxt;
            long tot = cnt * x;
            if (tot > orders) {
                int decr = orders / cnt;
                long a1 = inventory[0] - decr + 1, an = inventory[0];
                ans += (a1 + an) * decr / 2 * cnt;
                ans += (a1 - 1) * (orders % cnt);
            } else {
                long a1 = nxt + 1, an = inventory[0];
                ans += (a1 + an) * x / 2 * cnt;
                inventory[0] = nxt;
            }
            orders -= tot;
            ans %= mod;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxProfit(inventory []int, orders int) int {
	var mod int = 1e9 + 7
	i, n, ans := 0, len(inventory), 0
	sort.Ints(inventory)
	for i, j := 0, n-1; i < j; i, j = i+1, j-1 {
		inventory[i], inventory[j] = inventory[j], inventory[i]
	}
	for orders > 0 {
		for i < n && inventory[i] >= inventory[0] {
			i++
		}
		nxt := 0
		if i < n {
			nxt = inventory[i]
		}
		cnt := i
		x := inventory[0] - nxt
		tot := cnt * x
		if tot > orders {
			decr := orders / cnt
			a1, an := inventory[0]-decr+1, inventory[0]
			ans += (a1 + an) * decr / 2 * cnt
			ans += (a1 - 1) * (orders % cnt)
		} else {
			a1, an := nxt+1, inventory[0]
			ans += (a1 + an) * x / 2 * cnt
			inventory[0] = nxt
		}
		orders -= tot
		ans %= mod
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

<p>你有一些球的库存 <code>inventory</code> ，里面包含着不同颜色的球。一个顾客想要 <strong>任意颜色</strong> 总数为 <code>orders</code> 的球。</p>

<p>这位顾客有一种特殊的方式衡量球的价值：每个球的价值是目前剩下的 <strong>同色球</strong> 的数目。比方说还剩下 <code>6</code> 个黄球，那么顾客买第一个黄球的时候该黄球的价值为 <code>6</code> 。这笔交易以后，只剩下 <code>5</code> 个黄球了，所以下一个黄球的价值为 <code>5</code> （也就是球的价值随着顾客购买同色球是递减的）</p>

<p>给你整数数组 <code>inventory</code> ，其中 <code>inventory[i]</code> 表示第 <code>i</code> 种颜色球一开始的数目。同时给你整数 <code>orders</code> ，表示顾客总共想买的球数目。你可以按照 <strong>任意顺序</strong> 卖球。</p>

<p>请你返回卖了 <code>orders</code> 个球以后 <strong>最大</strong> 总价值之和。由于答案可能会很大，请你返回答案对 <code>10<sup>9</sup> + 7</code> <strong>取余数</strong> 的结果。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1648.Sell%20Diminishing-Valued%20Colored%20Balls/images/jj.gif" style="width: 480px; height: 270px;" />
<pre>
<b>输入：</b>inventory = [2,5], orders = 4
<b>输出：</b>14
<b>解释：</b>卖 1 个第一种颜色的球（价值为 2 )，卖 3 个第二种颜色的球（价值为 5 + 4 + 3）。
最大总和为 2 + 5 + 4 + 3 = 14 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>inventory = [3,5], orders = 6
<b>输出：</b>19
<strong>解释：</strong>卖 2 个第一种颜色的球（价值为 3 + 2），卖 4 个第二种颜色的球（价值为 5 + 4 + 3 + 2）。
最大总和为 3 + 2 + 5 + 4 + 3 + 2 = 19 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>inventory = [2,8,4,10,6], orders = 20
<b>输出：</b>110
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<b>输入：</b>inventory = [1000000000], orders = 1000000000
<b>输出：</b>21
<strong>解释：</strong>卖 1000000000 次第一种颜色的球，总价值为 500000000500000000 。 500000000500000000 对 10<sup>9 </sup>+ 7 取余为 21 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= inventory.length <= 10<sup>5</sup></code></li>
	<li><code>1 <= inventory[i] <= 10<sup>9</sup></code></li>
	<li><code>1 <= orders <= min(sum(inventory[i]), 10<sup>9</sup>)</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 优化模拟

要使得总价值最大，我们可以贪心地每次卖出数量最多的一种颜色的球。由于 `orders` 值域较大，如果直接简单地模拟，会超时。因此，我们需要优化模拟的过程。

实际上，我们不需要一次次进行模拟，我们可以跟踪数量最多的同色球的种类数 `cnt`，每一次可以卖出一批球，从而达到加速模拟的目的。

时间复杂度 $O(n\log n)$，空间复杂度 $O(1)$。其中 $n$ 为数组 `inventory` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxProfit(self, inventory: List[int], orders: int) -> int:
        inventory.sort(reverse=True)
        mod = 10**9 + 7
        ans = i = 0
        n = len(inventory)
        while orders > 0:
            while i < n and inventory[i] >= inventory[0]:
                i += 1
            nxt = 0
            if i < n:
                nxt = inventory[i]
            cnt = i
            x = inventory[0] - nxt
            tot = cnt * x
            if tot > orders:
                decr = orders // cnt
                a1, an = inventory[0] - decr + 1, inventory[0]
                ans += (a1 + an) * decr // 2 * cnt
                ans += (inventory[0] - decr) * (orders % cnt)
            else:
                a1, an = nxt + 1, inventory[0]
                ans += (a1 + an) * x // 2 * cnt
                inventory[0] = nxt
            orders -= tot
            ans %= mod
        return ans
```

#### Java

```java
class Solution {
    private static final int MOD = (int) 1e9 + 7;

    public int maxProfit(int[] inventory, int orders) {
        Arrays.sort(inventory);
        int n = inventory.length;
        for (int i = 0, j = n - 1; i < j; ++i, --j) {
            int t = inventory[i];
            inventory[i] = inventory[j];
            inventory[j] = t;
        }
        long ans = 0;
        int i = 0;
        while (orders > 0) {
            while (i < n && inventory[i] >= inventory[0]) {
                ++i;
            }
            int nxt = i < n ? inventory[i] : 0;
            int cnt = i;
            long x = inventory[0] - nxt;
            long tot = cnt * x;
            if (tot > orders) {
                int decr = orders / cnt;
                long a1 = inventory[0] - decr + 1, an = inventory[0];
                ans += (a1 + an) * decr / 2 * cnt;
                ans += (a1 - 1) * (orders % cnt);
            } else {
                long a1 = nxt + 1, an = inventory[0];
                ans += (a1 + an) * x / 2 * cnt;
                inventory[0] = nxt;
            }
            orders -= tot;
            ans %= MOD;
        }
        return (int) ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        long ans = 0, mod = 1e9 + 7;
        int i = 0, n = inventory.size();
        sort(inventory.rbegin(), inventory.rend());
        while (orders > 0) {
            while (i < n && inventory[i] >= inventory[0]) {
                ++i;
            }
            int nxt = i < n ? inventory[i] : 0;
            int cnt = i;
            long x = inventory[0] - nxt;
            long tot = cnt * x;
            if (tot > orders) {
                int decr = orders / cnt;
                long a1 = inventory[0] - decr + 1, an = inventory[0];
                ans += (a1 + an) * decr / 2 * cnt;
                ans += (a1 - 1) * (orders % cnt);
            } else {
                long a1 = nxt + 1, an = inventory[0];
                ans += (a1 + an) * x / 2 * cnt;
                inventory[0] = nxt;
            }
            orders -= tot;
            ans %= mod;
        }
        return ans;
    }
};
```

#### Go

```go
func maxProfit(inventory []int, orders int) int {
	var mod int = 1e9 + 7
	i, n, ans := 0, len(inventory), 0
	sort.Ints(inventory)
	for i, j := 0, n-1; i < j; i, j = i+1, j-1 {
		inventory[i], inventory[j] = inventory[j], inventory[i]
	}
	for orders > 0 {
		for i < n && inventory[i] >= inventory[0] {
			i++
		}
		nxt := 0
		if i < n {
			nxt = inventory[i]
		}
		cnt := i
		x := inventory[0] - nxt
		tot := cnt * x
		if tot > orders {
			decr := orders / cnt
			a1, an := inventory[0]-decr+1, inventory[0]
			ans += (a1 + an) * decr / 2 * cnt
			ans += (a1 - 1) * (orders % cnt)
		} else {
			a1, an := nxt+1, inventory[0]
			ans += (a1 + an) * x / 2 * cnt
			inventory[0] = nxt
		}
		orders -= tot
		ans %= mod
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1649. 通过指令创建有序数组](https://leetcode.cn/problems/create-sorted-array-through-instructions){#1649}

{{< tabs "1649" >}}

{{% tab "python" %}}
```python
class Node:
    def __init__(self):
        self.l = 0
        self.r = 0
        self.v = 0


class SegmentTree:
    def __init__(self, n):
        self.tr = [Node() for _ in range(4 * n)]
        self.build(1, 1, n)

    def build(self, u, l, r):
        self.tr[u].l = l
        self.tr[u].r = r
        if l == r:
            return
        mid = (l + r) >> 1
        self.build(u << 1, l, mid)
        self.build(u << 1 | 1, mid + 1, r)

    def modify(self, u, x, v):
        if self.tr[u].l == x and self.tr[u].r == x:
            self.tr[u].v += v
            return
        mid = (self.tr[u].l + self.tr[u].r) >> 1
        if x <= mid:
            self.modify(u << 1, x, v)
        else:
            self.modify(u << 1 | 1, x, v)
        self.pushup(u)

    def pushup(self, u):
        self.tr[u].v = self.tr[u << 1].v + self.tr[u << 1 | 1].v

    def query(self, u, l, r):
        if self.tr[u].l >= l and self.tr[u].r <= r:
            return self.tr[u].v
        mid = (self.tr[u].l + self.tr[u].r) >> 1
        v = 0
        if l <= mid:
            v = self.query(u << 1, l, r)
        if r > mid:
            v += self.query(u << 1 | 1, l, r)
        return v


class Solution:
    def createSortedArray(self, instructions: List[int]) -> int:
        n = max(instructions)
        tree = SegmentTree(n)
        ans = 0
        for num in instructions:
            a = tree.query(1, 1, num - 1)
            b = tree.query(1, 1, n) - tree.query(1, 1, num)
            ans += min(a, b)
            tree.modify(1, num, 1)
        return ans % int((1e9 + 7))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int createSortedArray(int[] instructions) {
        int n = 100010;
        int mod = (int) 1e9 + 7;
        SegmentTree tree = new SegmentTree(n);
        int ans = 0;
        for (int num : instructions) {
            int a = tree.query(1, 1, num - 1);
            int b = tree.query(1, 1, n) - tree.query(1, 1, num);
            ans += Math.min(a, b);
            ans %= mod;
            tree.modify(1, num, 1);
        }
        return ans;
    }
}

class Node {
    int l;
    int r;
    int v;
}

class SegmentTree {
    private Node[] tr;

    public SegmentTree(int n) {
        tr = new Node[4 * n];
        for (int i = 0; i < tr.length; ++i) {
            tr[i] = new Node();
        }
        build(1, 1, n);
    }

    public void build(int u, int l, int r) {
        tr[u].l = l;
        tr[u].r = r;
        if (l == r) {
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
    }

    public void modify(int u, int x, int v) {
        if (tr[u].l == x && tr[u].r == x) {
            tr[u].v += v;
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

    SegmentTree(int n) {
        tr.resize(4 * n);
        for (int i = 0; i < tr.size(); ++i) tr[i] = new Node();
        build(1, 1, n);
    }

    void build(int u, int l, int r) {
        tr[u]->l = l;
        tr[u]->r = r;
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
    }

    void modify(int u, int x, int v) {
        if (tr[u]->l == x && tr[u]->r == x) {
            tr[u]->v += v;
            return;
        }
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        if (x <= mid)
            modify(u << 1, x, v);
        else
            modify(u << 1 | 1, x, v);
        pushup(u);
    }

    void pushup(int u) {
        tr[u]->v = tr[u << 1]->v + tr[u << 1 | 1]->v;
    }

    int query(int u, int l, int r) {
        if (tr[u]->l >= l && tr[u]->r <= r) return tr[u]->v;
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        int v = 0;
        if (l <= mid) v = query(u << 1, l, r);
        if (r > mid) v += query(u << 1 | 1, l, r);
        return v;
    }
};

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        int n = *max_element(instructions.begin(), instructions.end());
        int mod = 1e9 + 7;
        SegmentTree* tree = new SegmentTree(n);
        int ans = 0;
        for (int num : instructions) {
            int a = tree->query(1, 1, num - 1);
            int b = tree->query(1, 1, n) - tree->query(1, 1, num);
            ans += min(a, b);
            ans %= mod;
            tree->modify(1, num, 1);
        }
        return ans;
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
	c := make([]int, n+1)
	return &BinaryIndexedTree{n, c}
}

func (this *BinaryIndexedTree) update(x, delta int) {
	for x <= this.n {
		this.c[x] += delta
		x += x & -x
	}
}

func (this *BinaryIndexedTree) query(x int) int {
	s := 0
	for x > 0 {
		s += this.c[x]
		x -= x & -x
	}
	return s
}

func createSortedArray(instructions []int) (ans int) {
	m := slices.Max(instructions)
	tree := newBinaryIndexedTree(m)
	const mod = 1e9 + 7
	for i, x := range instructions {
		cost := min(tree.query(x-1), i-tree.query(x))
		ans = (ans + cost) % mod
		tree.update(x, 1)
	}
	return
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

    public update(x: number, v: number): void {
        while (x <= this.n) {
            this.c[x] += v;
            x += x & -x;
        }
    }

    public query(x: number): number {
        let s = 0;
        while (x > 0) {
            s += this.c[x];
            x -= x & -x;
        }
        return s;
    }
}

function createSortedArray(instructions: number[]): number {
    const m = Math.max(...instructions);
    const tree = new BinaryIndexedTree(m);
    let ans = 0;
    const mod = 10 ** 9 + 7;
    for (let i = 0; i < instructions.length; ++i) {
        const x = instructions[i];
        const cost = Math.min(tree.query(x - 1), i - tree.query(x));
        ans = (ans + cost) % mod;
        tree.update(x, 1);
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

<p>给你一个整数数组 <code>instructions</code> ，你需要根据 <code>instructions</code> 中的元素创建一个有序数组。一开始你有一个空的数组 <code>nums</code> ，你需要 <strong>从左到右</strong> 遍历 <code>instructions</code> 中的元素，将它们依次插入 <code>nums</code> 数组中。每一次插入操作的 <strong>代价</strong> 是以下两者的 <strong>较小值</strong> ：</p>

<ul>
	<li><code>nums</code> 中 <strong>严格小于 </strong> <code>instructions[i]</code> 的数字数目。</li>
	<li><code>nums</code> 中 <strong>严格大于 </strong> <code>instructions[i]</code> 的数字数目。</li>
</ul>

<p>比方说，如果要将 <code>3</code> 插入到 <code>nums = [1,2,3,5]</code> ，那么插入操作的 <strong>代价</strong> 为 <code>min(2, 1)</code> (元素 <code>1</code> 和  <code>2</code> 小于 <code>3</code> ，元素 <code>5</code> 大于 <code>3</code> ），插入后 <code>nums</code> 变成 <code>[1,2,3,3,5]</code> 。</p>

<p>请你返回将 <code>instructions</code> 中所有元素依次插入 <code>nums</code> 后的 <strong>总最小代价 </strong>。由于答案会很大，请将它对 <code>10<sup>9</sup> + 7</code> <b>取余</b> 后返回。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>instructions = [1,5,6,2]
<b>输出：</b>1
<b>解释：</b>一开始 nums = [] 。
插入 1 ，代价为 min(0, 0) = 0 ，现在 nums = [1] 。
插入 5 ，代价为 min(1, 0) = 0 ，现在 nums = [1,5] 。
插入 6 ，代价为 min(2, 0) = 0 ，现在 nums = [1,5,6] 。
插入 2 ，代价为 min(1, 2) = 1 ，现在 nums = [1,2,5,6] 。
总代价为 0 + 0 + 0 + 1 = 1 。</pre>

<p><strong>示例 2:</strong></p>

<pre><b>输入：</b>instructions = [1,2,3,6,5,4]
<b>输出：</b>3
<b>解释：</b>一开始 nums = [] 。
插入 1 ，代价为 min(0, 0) = 0 ，现在 nums = [1] 。
插入 2 ，代价为 min(1, 0) = 0 ，现在 nums = [1,2] 。
插入 3 ，代价为 min(2, 0) = 0 ，现在 nums = [1,2,3] 。
插入 6 ，代价为 min(3, 0) = 0 ，现在 nums = [1,2,3,6] 。
插入 5 ，代价为 min(3, 1) = 1 ，现在 nums = [1,2,3,5,6] 。
插入 4 ，代价为 min(3, 2) = 2 ，现在 nums = [1,2,3,4,5,6] 。
总代价为 0 + 0 + 0 + 0 + 1 + 2 = 3 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>instructions = [1,3,3,3,2,4,2,1,2]
<b>输出：</b>4
<b>解释：</b>一开始 nums = [] 。
插入 1 ，代价为 min(0, 0) = 0 ，现在 nums = [1] 。
插入 3 ，代价为 min(1, 0) = 0 ，现在 nums = [1,3] 。
插入 3 ，代价为 min(1, 0) = 0 ，现在 nums = [1,3,3] 。
插入 3 ，代价为 min(1, 0) = 0 ，现在 nums = [1,3,3,3] 。
插入 2 ，代价为 min(1, 3) = 1 ，现在 nums = [1,2,3,3,3] 。
插入 4 ，代价为 min(5, 0) = 0 ，现在 nums = [1,2,3,3,3,4] 。
​​​​​插入 2 ，代价为 min(1, 4) = 1 ，现在 nums = [1,2,2,3,3,3,4] 。
插入 1 ，代价为 min(0, 6) = 0 ，现在 nums = [1,1,2,2,3,3,3,4] 。
插入 2 ，代价为 min(2, 4) = 2 ，现在 nums = [1,1,2,2,2,3,3,3,4] 。
总代价为 0 + 0 + 0 + 0 + 1 + 0 + 1 + 0 + 2 = 4 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= instructions.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= instructions[i] &lt;= 10<sup>5</sup></code></li>
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

树状数组最基本的功能就是求比某点 x 小的点的个数（这里的比较是抽象的概念，可以是数的大小、坐标的大小、质量的大小等等）。

比如给定数组 `a[5] = {2, 5, 3, 4, 1}`，求 `b[i] = 位置 i 左边小于等于 a[i] 的数的个数`。对于此例，`b[5] = {0, 1, 1, 2, 0}`。

解决方案是直接遍历数组，每个位置先求出 `query(a[i])`，然后再修改树状数组 `update(a[i], 1)` 即可。当数的范围比较大时，需要进行离散化，即先进行去重并排序，然后对每个数字进行编号。

<!-- tabs:start -->

#### Python3

```python
class BinaryIndexedTree:
    def __init__(self, n):
        self.n = n
        self.c = [0] * (n + 1)

    def update(self, x: int, v: int):
        while x <= self.n:
            self.c[x] += v
            x += x & -x

    def query(self, x: int) -> int:
        s = 0
        while x:
            s += self.c[x]
            x -= x & -x
        return s


class Solution:
    def createSortedArray(self, instructions: List[int]) -> int:
        m = max(instructions)
        tree = BinaryIndexedTree(m)
        ans = 0
        mod = 10**9 + 7
        for i, x in enumerate(instructions):
            cost = min(tree.query(x - 1), i - tree.query(x))
            ans += cost
            tree.update(x, 1)
        return ans % mod
```

#### Java

```java
class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        this.c = new int[n + 1];
    }

    public void update(int x, int v) {
        while (x <= n) {
            c[x] += v;
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

class Solution {
    public int createSortedArray(int[] instructions) {
        int m = 0;
        for (int x : instructions) {
            m = Math.max(m, x);
        }
        BinaryIndexedTree tree = new BinaryIndexedTree(m);
        int ans = 0;
        final int mod = (int) 1e9 + 7;
        for (int i = 0; i < instructions.length; ++i) {
            int x = instructions[i];
            int cost = Math.min(tree.query(x - 1), i - tree.query(x));
            ans = (ans + cost) % mod;
            tree.update(x, 1);
        }
        return ans;
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

    void update(int x, int delta) {
        while (x <= n) {
            c[x] += delta;
            x += x & -x;
        }
    }

    int query(int x) {
        int s = 0;
        while (x) {
            s += c[x];
            x -= x & -x;
        }
        return s;
    }

private:
    int n;
    vector<int> c;
};

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        int m = *max_element(instructions.begin(), instructions.end());
        BinaryIndexedTree tree(m);
        const int mod = 1e9 + 7;
        int ans = 0;
        for (int i = 0; i < instructions.size(); ++i) {
            int x = instructions[i];
            int cost = min(tree.query(x - 1), i - tree.query(x));
            ans = (ans + cost) % mod;
            tree.update(x, 1);
        }
        return ans;
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
	c := make([]int, n+1)
	return &BinaryIndexedTree{n, c}
}

func (this *BinaryIndexedTree) update(x, delta int) {
	for x <= this.n {
		this.c[x] += delta
		x += x & -x
	}
}

func (this *BinaryIndexedTree) query(x int) int {
	s := 0
	for x > 0 {
		s += this.c[x]
		x -= x & -x
	}
	return s
}

func createSortedArray(instructions []int) (ans int) {
	m := slices.Max(instructions)
	tree := newBinaryIndexedTree(m)
	const mod = 1e9 + 7
	for i, x := range instructions {
		cost := min(tree.query(x-1), i-tree.query(x))
		ans = (ans + cost) % mod
		tree.update(x, 1)
	}
	return
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

    public update(x: number, v: number): void {
        while (x <= this.n) {
            this.c[x] += v;
            x += x & -x;
        }
    }

    public query(x: number): number {
        let s = 0;
        while (x > 0) {
            s += this.c[x];
            x -= x & -x;
        }
        return s;
    }
}

function createSortedArray(instructions: number[]): number {
    const m = Math.max(...instructions);
    const tree = new BinaryIndexedTree(m);
    let ans = 0;
    const mod = 10 ** 9 + 7;
    for (let i = 0; i < instructions.length; ++i) {
        const x = instructions[i];
        const cost = Math.min(tree.query(x - 1), i - tree.query(x));
        ans = (ans + cost) % mod;
        tree.update(x, 1);
    }
    return ans;
}
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

> 本题线段树 Python3 代码 TLE，Java、C++ 代码 AC。

<!-- tabs:start -->

#### Python3

```python
class Node:
    def __init__(self):
        self.l = 0
        self.r = 0
        self.v = 0


class SegmentTree:
    def __init__(self, n):
        self.tr = [Node() for _ in range(4 * n)]
        self.build(1, 1, n)

    def build(self, u, l, r):
        self.tr[u].l = l
        self.tr[u].r = r
        if l == r:
            return
        mid = (l + r) >> 1
        self.build(u << 1, l, mid)
        self.build(u << 1 | 1, mid + 1, r)

    def modify(self, u, x, v):
        if self.tr[u].l == x and self.tr[u].r == x:
            self.tr[u].v += v
            return
        mid = (self.tr[u].l + self.tr[u].r) >> 1
        if x <= mid:
            self.modify(u << 1, x, v)
        else:
            self.modify(u << 1 | 1, x, v)
        self.pushup(u)

    def pushup(self, u):
        self.tr[u].v = self.tr[u << 1].v + self.tr[u << 1 | 1].v

    def query(self, u, l, r):
        if self.tr[u].l >= l and self.tr[u].r <= r:
            return self.tr[u].v
        mid = (self.tr[u].l + self.tr[u].r) >> 1
        v = 0
        if l <= mid:
            v = self.query(u << 1, l, r)
        if r > mid:
            v += self.query(u << 1 | 1, l, r)
        return v


class Solution:
    def createSortedArray(self, instructions: List[int]) -> int:
        n = max(instructions)
        tree = SegmentTree(n)
        ans = 0
        for num in instructions:
            a = tree.query(1, 1, num - 1)
            b = tree.query(1, 1, n) - tree.query(1, 1, num)
            ans += min(a, b)
            tree.modify(1, num, 1)
        return ans % int((1e9 + 7))
```

#### Java

```java
class Solution {
    public int createSortedArray(int[] instructions) {
        int n = 100010;
        int mod = (int) 1e9 + 7;
        SegmentTree tree = new SegmentTree(n);
        int ans = 0;
        for (int num : instructions) {
            int a = tree.query(1, 1, num - 1);
            int b = tree.query(1, 1, n) - tree.query(1, 1, num);
            ans += Math.min(a, b);
            ans %= mod;
            tree.modify(1, num, 1);
        }
        return ans;
    }
}

class Node {
    int l;
    int r;
    int v;
}

class SegmentTree {
    private Node[] tr;

    public SegmentTree(int n) {
        tr = new Node[4 * n];
        for (int i = 0; i < tr.length; ++i) {
            tr[i] = new Node();
        }
        build(1, 1, n);
    }

    public void build(int u, int l, int r) {
        tr[u].l = l;
        tr[u].r = r;
        if (l == r) {
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
    }

    public void modify(int u, int x, int v) {
        if (tr[u].l == x && tr[u].r == x) {
            tr[u].v += v;
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

    SegmentTree(int n) {
        tr.resize(4 * n);
        for (int i = 0; i < tr.size(); ++i) tr[i] = new Node();
        build(1, 1, n);
    }

    void build(int u, int l, int r) {
        tr[u]->l = l;
        tr[u]->r = r;
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
    }

    void modify(int u, int x, int v) {
        if (tr[u]->l == x && tr[u]->r == x) {
            tr[u]->v += v;
            return;
        }
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        if (x <= mid)
            modify(u << 1, x, v);
        else
            modify(u << 1 | 1, x, v);
        pushup(u);
    }

    void pushup(int u) {
        tr[u]->v = tr[u << 1]->v + tr[u << 1 | 1]->v;
    }

    int query(int u, int l, int r) {
        if (tr[u]->l >= l && tr[u]->r <= r) return tr[u]->v;
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        int v = 0;
        if (l <= mid) v = query(u << 1, l, r);
        if (r > mid) v += query(u << 1 | 1, l, r);
        return v;
    }
};

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        int n = *max_element(instructions.begin(), instructions.end());
        int mod = 1e9 + 7;
        SegmentTree* tree = new SegmentTree(n);
        int ans = 0;
        for (int num : instructions) {
            int a = tree->query(1, 1, num - 1);
            int b = tree->query(1, 1, n) - tree->query(1, 1, num);
            ans += min(a, b);
            ans %= mod;
            tree->modify(1, num, 1);
        }
        return ans;
    }
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
