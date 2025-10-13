---
title: "2980_检查按位或是否存在尾随零"
date: 2025-10-08T18:39:48+08:00
weight: 9
tags: [二分查找, 位运算, 前缀和, 哈希表, 字符串, 数据库, 数组, 滑动窗口, 计数]
---

{{< markmap >}}
### [2980_检查按位或是否存在尾随零](#2980)
#### [位运算](#2980)
#### [数组](#2980)
### [2981_找出出现至少三次的最长特殊子字符串 I](#2981)
#### [哈希表](#2981)
#### [字符串](#2981)
#### [二分查找](#2981)
#### [计数](#2981)
#### [滑动窗口](#2981)
### [2982_找出出现至少三次的最长特殊子字符串 II](#2982)
#### [哈希表](#2982)
#### [字符串](#2982)
#### [二分查找](#2982)
#### [计数](#2982)
#### [滑动窗口](#2982)
### [2983_回文串重新排列查询](#2983)
#### [哈希表](#2983)
#### [字符串](#2983)
#### [前缀和](#2983)
### [2984_找到每座城市的高峰通话时间 🔒](#2984)
#### [数据库](#2984)
### [2985_计算订单平均商品数量 🔒](#2985)
#### [数据库](#2985)
### [2986_找到第三笔交易 🔒](#2986)
#### [数据库](#2986)
### [2987_寻找房价最贵的城市 🔒](#2987)
#### [数据库](#2987)
### [2988_最大部门的经理 🔒](#2988)
#### [数据库](#2988)
### [2989_班级表现 🔒](#2989)
#### [数据库](#2989)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2980_检查按位或是否存在尾随零
___
#### 位运算
___
#### 数组
---
### 2981_找出出现至少三次的最长特殊子字符串 I
___
#### 哈希表
___
#### 字符串
___
#### 二分查找
___
#### 计数
___
#### 滑动窗口
---
### 2982_找出出现至少三次的最长特殊子字符串 II
___
#### 哈希表
___
#### 字符串
___
#### 二分查找
___
#### 计数
___
#### 滑动窗口
---
### 2983_回文串重新排列查询
___
#### 哈希表
___
#### 字符串
___
#### 前缀和
---
### 2984_找到每座城市的高峰通话时间 🔒
___
#### 数据库
---
### 2985_计算订单平均商品数量 🔒
___
#### 数据库
---
### 2986_找到第三笔交易 🔒
___
#### 数据库
---
### 2987_寻找房价最贵的城市 🔒
___
#### 数据库
---
### 2988_最大部门的经理 🔒
___
#### 数据库
---
### 2989_班级表现 🔒
___
#### 数据库
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 前缀和 |
| 哈希表 | 字符串 | 数据库 |
| 数组 | 滑动窗口 | 计数 |

# [2980. 检查按位或是否存在尾随零](https://leetcode.cn/problems/check-if-bitwise-or-has-trailing-zeros){#2980}

{{< tabs "2980" >}}

{{% tab "python" %}}
```python
class Solution:
    def hasTrailingZeros(self, nums: List[int]) -> bool:
        return sum(x & 1 ^ 1 for x in nums) >= 2
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean hasTrailingZeros(int[] nums) {
        int cnt = 0;
        for (int x : nums) {
            cnt += (x & 1 ^ 1);
        }
        return cnt >= 2;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int cnt = 0;
        for (int x : nums) {
            cnt += (x & 1 ^ 1);
        }
        return cnt >= 2;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func hasTrailingZeros(nums []int) bool {
	cnt := 0
	for _, x := range nums {
		cnt += (x&1 ^ 1)
	}
	return cnt >= 2
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function hasTrailingZeros(nums: number[]): boolean {
    let cnt = 0;
    for (const x of nums) {
        cnt += (x & 1) ^ 1;
    }
    return cnt >= 2;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个<strong> 正整数 </strong>数组 <code>nums</code> 。</p>

<p>你需要检查是否可以从数组中选出 <strong>两个或更多 </strong>元素，满足这些元素的按位或运算（ <code>OR</code>）结果的二进制表示中 <strong>至少</strong><strong> </strong>存在一个尾随零。</p>

<p>例如，数字 <code>5</code> 的二进制表示是 <code>"101"</code>，不存在尾随零，而数字 <code>4</code> 的二进制表示是 <code>"100"</code>，存在两个尾随零。</p>

<p>如果可以选择两个或更多元素，其按位或运算结果存在尾随零，返回 <code>true</code>；否则，返回<em> </em><code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,4,5]
<strong>输出：</strong>true
<strong>解释：</strong>如果选择元素 2 和 4，按位或运算结果是 6，二进制表示为 "110" ，存在一个尾随零。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,4,8,16]
<strong>输出：</strong>true
<strong>解释：</strong>如果选择元素 2 和 4，按位或运算结果是 6，二进制表示为 "110"，存在一个尾随零。
其他按位或运算结果存在尾随零的可能选择方案包括：(2, 8), (2, 16), (4, 8), (4, 16), (8, 16), (2, 4, 8), (2, 4, 16), (2, 8, 16), (4, 8, 16), 以及 (2, 4, 8, 16) 。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,3,5,7,9]
<strong>输出：</strong>false
<strong>解释：</strong>不存在按位或运算结果存在尾随零的选择方案。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：统计偶数个数

根据题意，我们可以知道，如果数组中存在两个或两个以上的元素，其按位或运算结果存在尾随零，那么数组中必然存在至少两个偶数。因此，我们可以统计数组中偶数的个数，如果偶数的个数大于等于 $2$，那么就返回 `true`，否则返回 `false`。

时间复杂度 $O(n)$，其中 $n$ 是数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def hasTrailingZeros(self, nums: List[int]) -> bool:
        return sum(x & 1 ^ 1 for x in nums) >= 2
```

#### Java

```java
class Solution {
    public boolean hasTrailingZeros(int[] nums) {
        int cnt = 0;
        for (int x : nums) {
            cnt += (x & 1 ^ 1);
        }
        return cnt >= 2;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int cnt = 0;
        for (int x : nums) {
            cnt += (x & 1 ^ 1);
        }
        return cnt >= 2;
    }
};
```

#### Go

```go
func hasTrailingZeros(nums []int) bool {
	cnt := 0
	for _, x := range nums {
		cnt += (x&1 ^ 1)
	}
	return cnt >= 2
}
```

#### TypeScript

```ts
function hasTrailingZeros(nums: number[]): boolean {
    let cnt = 0;
    for (const x of nums) {
        cnt += (x & 1) ^ 1;
    }
    return cnt >= 2;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2981. 找出出现至少三次的最长特殊子字符串 I](https://leetcode.cn/problems/find-longest-special-substring-that-occurs-thrice-i){#2981}

{{< tabs "2981" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumLength(self, s: str) -> int:
        def check(x: int) -> bool:
            cnt = defaultdict(int)
            i = 0
            while i < n:
                j = i + 1
                while j < n and s[j] == s[i]:
                    j += 1
                cnt[s[i]] += max(0, j - i - x + 1)
                i = j
            return max(cnt.values()) >= 3

        n = len(s)
        l, r = 0, n
        while l < r:
            mid = (l + r + 1) >> 1
            if check(mid):
                l = mid
            else:
                r = mid - 1
        return -1 if l == 0 else l
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private String s;
    private int n;

    public int maximumLength(String s) {
        this.s = s;
        n = s.length();
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l == 0 ? -1 : l;
    }

    private boolean check(int x) {
        int[] cnt = new int[26];
        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && s.charAt(j) == s.charAt(i)) {
                j++;
            }
            int k = s.charAt(i) - 'a';
            cnt[k] += Math.max(0, j - i - x + 1);
            if (cnt[k] >= 3) {
                return true;
            }
            i = j;
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
    int maximumLength(string s) {
        int n = s.size();
        int l = 0, r = n;
        auto check = [&](int x) {
            int cnt[26]{};
            for (int i = 0; i < n;) {
                int j = i + 1;
                while (j < n && s[j] == s[i]) {
                    ++j;
                }
                int k = s[i] - 'a';
                cnt[k] += max(0, j - i - x + 1);
                if (cnt[k] >= 3) {
                    return true;
                }
                i = j;
            }
            return false;
        };
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l == 0 ? -1 : l;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumLength(s string) int {
	n := len(s)
	l, r := 0, n
	check := func(x int) bool {
		cnt := [26]int{}
		for i := 0; i < n; {
			j := i + 1
			for j < n && s[j] == s[i] {
				j++
			}
			k := s[i] - 'a'
			cnt[k] += max(0, j-i-x+1)
			if cnt[k] >= 3 {
				return true
			}
			i = j
		}
		return false
	}
	for l < r {
		mid := (l + r + 1) >> 1
		if check(mid) {
			l = mid
		} else {
			r = mid - 1
		}
	}
	if l == 0 {
		return -1
	}
	return l
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumLength(s: string): number {
    const cnt = new Map<string, number>();
    const n = s.length;
    let [c, ch] = [0, ''];

    for (let i = 0; i < n + 1; i++) {
        if (ch === s[i]) {
            c++;
        } else {
            let j = 1;
            while (c) {
                const char = ch.repeat(j++);
                cnt.set(char, (cnt.get(char) ?? 0) + c);
                c--;
            }

            ch = s[i];
            c = 1;
        }
    }

    let res = -1;
    for (const [x, c] of cnt) {
        if (c >= 3) {
            res = Math.max(res, x.length);
        }
    }

    return res;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function maximumLength(s) {
    const cnt = new Map();
    const n = s.length;
    let [c, ch] = [0, ''];

    for (let i = 0; i < n + 1; i++) {
        if (ch === s[i]) {
            c++;
        } else {
            let j = 1;
            while (c) {
                const char = ch.repeat(j++);
                cnt.set(char, (cnt.get(char) ?? 0) + c);
                c--;
            }

            ch = s[i];
            c = 1;
        }
    }

    let res = -1;
    for (const [x, c] of cnt) {
        if (c >= 3) {
            res = Math.max(res, x.length);
        }
    }

    return res;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个仅由小写英文字母组成的字符串 <code>s</code> 。</p>

<p>如果一个字符串仅由单一字符组成，那么它被称为 <strong>特殊 </strong>字符串。例如，字符串 <code>"abc"</code> 不是特殊字符串，而字符串 <code>"ddd"</code>、<code>"zz"</code> 和 <code>"f"</code> 是特殊字符串。</p>

<p>返回在 <code>s</code> 中出现 <strong>至少三次 </strong>的<strong> 最长特殊子字符串 </strong>的长度，如果不存在出现至少三次的特殊子字符串，则返回 <code>-1</code> 。</p>

<p><strong>子字符串 </strong>是字符串中的一个连续<strong> 非空 </strong>字符序列。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "aaaa"
<strong>输出：</strong>2
<strong>解释：</strong>出现三次的最长特殊子字符串是 "aa" ：子字符串 "<em><strong>aa</strong></em>aa"、"a<em><strong>aa</strong></em>a" 和 "aa<em><strong>aa</strong></em>"。
可以证明最大长度是 2 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "abcdef"
<strong>输出：</strong>-1
<strong>解释：</strong>不存在出现至少三次的特殊子字符串。因此返回 -1 。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "abcaba"
<strong>输出：</strong>1
<strong>解释：</strong>出现三次的最长特殊子字符串是 "a" ：子字符串 "<em><strong>a</strong></em>bcaba"、"abc<em><strong>a</strong></em>ba" 和 "abcab<em><strong>a</strong></em>"。
可以证明最大长度是 1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= s.length &lt;= 50</code></li>
	<li><code>s</code> 仅由小写英文字母组成。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找 + 滑动窗口计数

我们注意到，如果一个长度为 $x$ 且出现至少三次的特殊子字符串存在，那么长度为 $x-1$ 的特殊子字符串也一定存在，这存在着单调性，因此我们可以使用二分查找的方法来找到最长的特殊子字符串。

我们定义二分查找的左边界 $l = 0$，右边界 $r = n$，其中 $n$ 是字符串的长度。每次二分查找的过程中，我们取 $mid = \lfloor \frac{l + r + 1}{2} \rfloor$，如果长度为 $mid$ 的特殊子字符串存在，那么我们就将左边界更新为 $mid$，否则我们就将右边界更新为 $mid - 1$。在二分查找的过程中，我们使用滑动窗口来计算特殊子字符串的个数。

具体地，我们设计一个函数 $check(x)$，表示长度为 $x$ 且出现至少三次的特殊子字符串是否存在。

在函数 $check(x)$ 中，我们定义一个哈希表或长度为 $26$ 的数组 $cnt$，其中 $cnt[i]$ 表示长度为 $x$，且由第 $i$ 个小写字母组成的特殊子字符串的个数。我们遍历字符串 $s$，如果当前遍历到的字符为 $s[i]$，那么我们将指针 $j$ 向右移动，直到 $s[j] \neq s[i]$，此时 $s[i \cdots j-1]$ 就是一个长度为 $x$ 的特殊子字符串，我们将 $cnt[s[i]]$ 增加 $\max(0, j - i - x + 1)$，然后将指针 $i$ 更新为 $j$。

在遍历结束之后，我们遍历数组 $cnt$，如果存在 $cnt[i] \geq 3$，那么就说明长度为 $x$ 且出现至少三次的特殊子字符串存在，我们返回 $true$，否则返回 $false$。

时间复杂度 $O((n + |\Sigma|) \times \log n)$，空间复杂度 $O(|\Sigma|)$，其中 $n$ 是字符串 $s$ 的长度，而 $|\Sigma|$ 表示字符集的大小，本题中字符集为小写英文字母，因此 $|\Sigma| = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumLength(self, s: str) -> int:
        def check(x: int) -> bool:
            cnt = defaultdict(int)
            i = 0
            while i < n:
                j = i + 1
                while j < n and s[j] == s[i]:
                    j += 1
                cnt[s[i]] += max(0, j - i - x + 1)
                i = j
            return max(cnt.values()) >= 3

        n = len(s)
        l, r = 0, n
        while l < r:
            mid = (l + r + 1) >> 1
            if check(mid):
                l = mid
            else:
                r = mid - 1
        return -1 if l == 0 else l
```

#### Java

```java
class Solution {
    private String s;
    private int n;

    public int maximumLength(String s) {
        this.s = s;
        n = s.length();
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l == 0 ? -1 : l;
    }

    private boolean check(int x) {
        int[] cnt = new int[26];
        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && s.charAt(j) == s.charAt(i)) {
                j++;
            }
            int k = s.charAt(i) - 'a';
            cnt[k] += Math.max(0, j - i - x + 1);
            if (cnt[k] >= 3) {
                return true;
            }
            i = j;
        }
        return false;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        int l = 0, r = n;
        auto check = [&](int x) {
            int cnt[26]{};
            for (int i = 0; i < n;) {
                int j = i + 1;
                while (j < n && s[j] == s[i]) {
                    ++j;
                }
                int k = s[i] - 'a';
                cnt[k] += max(0, j - i - x + 1);
                if (cnt[k] >= 3) {
                    return true;
                }
                i = j;
            }
            return false;
        };
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l == 0 ? -1 : l;
    }
};
```

#### Go

```go
func maximumLength(s string) int {
	n := len(s)
	l, r := 0, n
	check := func(x int) bool {
		cnt := [26]int{}
		for i := 0; i < n; {
			j := i + 1
			for j < n && s[j] == s[i] {
				j++
			}
			k := s[i] - 'a'
			cnt[k] += max(0, j-i-x+1)
			if cnt[k] >= 3 {
				return true
			}
			i = j
		}
		return false
	}
	for l < r {
		mid := (l + r + 1) >> 1
		if check(mid) {
			l = mid
		} else {
			r = mid - 1
		}
	}
	if l == 0 {
		return -1
	}
	return l
}
```

#### TypeScript

```ts
function maximumLength(s: string): number {
    const n = s.length;
    let [l, r] = [0, n];
    const check = (x: number): boolean => {
        const cnt: number[] = Array(26).fill(0);
        for (let i = 0; i < n; ) {
            let j = i + 1;
            while (j < n && s[j] === s[i]) {
                j++;
            }
            const k = s[i].charCodeAt(0) - 'a'.charCodeAt(0);
            cnt[k] += Math.max(0, j - i - x + 1);
            if (cnt[k] >= 3) {
                return true;
            }
            i = j;
        }
        return false;
    };
    while (l < r) {
        const mid = (l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l === 0 ? -1 : l;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：计数

时间复杂度 $O(n)$。

<!-- tabs:start -->

#### TypeScript

```ts
function maximumLength(s: string): number {
    const cnt = new Map<string, number>();
    const n = s.length;
    let [c, ch] = [0, ''];

    for (let i = 0; i < n + 1; i++) {
        if (ch === s[i]) {
            c++;
        } else {
            let j = 1;
            while (c) {
                const char = ch.repeat(j++);
                cnt.set(char, (cnt.get(char) ?? 0) + c);
                c--;
            }

            ch = s[i];
            c = 1;
        }
    }

    let res = -1;
    for (const [x, c] of cnt) {
        if (c >= 3) {
            res = Math.max(res, x.length);
        }
    }

    return res;
}
```

### JavaScript

```js
function maximumLength(s) {
    const cnt = new Map();
    const n = s.length;
    let [c, ch] = [0, ''];

    for (let i = 0; i < n + 1; i++) {
        if (ch === s[i]) {
            c++;
        } else {
            let j = 1;
            while (c) {
                const char = ch.repeat(j++);
                cnt.set(char, (cnt.get(char) ?? 0) + c);
                c--;
            }

            ch = s[i];
            c = 1;
        }
    }

    let res = -1;
    for (const [x, c] of cnt) {
        if (c >= 3) {
            res = Math.max(res, x.length);
        }
    }

    return res;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2982. 找出出现至少三次的最长特殊子字符串 II](https://leetcode.cn/problems/find-longest-special-substring-that-occurs-thrice-ii){#2982}

{{< tabs "2982" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumLength(self, s: str) -> int:
        def check(x: int) -> bool:
            cnt = defaultdict(int)
            i = 0
            while i < n:
                j = i + 1
                while j < n and s[j] == s[i]:
                    j += 1
                cnt[s[i]] += max(0, j - i - x + 1)
                i = j
            return max(cnt.values()) >= 3

        n = len(s)
        l, r = 0, n
        while l < r:
            mid = (l + r + 1) >> 1
            if check(mid):
                l = mid
            else:
                r = mid - 1
        return -1 if l == 0 else l
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private String s;
    private int n;

    public int maximumLength(String s) {
        this.s = s;
        n = s.length();
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l == 0 ? -1 : l;
    }

    private boolean check(int x) {
        int[] cnt = new int[26];
        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && s.charAt(j) == s.charAt(i)) {
                j++;
            }
            int k = s.charAt(i) - 'a';
            cnt[k] += Math.max(0, j - i - x + 1);
            if (cnt[k] >= 3) {
                return true;
            }
            i = j;
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
    int maximumLength(string s) {
        int n = s.size();
        int l = 0, r = n;
        auto check = [&](int x) {
            int cnt[26]{};
            for (int i = 0; i < n;) {
                int j = i + 1;
                while (j < n && s[j] == s[i]) {
                    ++j;
                }
                int k = s[i] - 'a';
                cnt[k] += max(0, j - i - x + 1);
                if (cnt[k] >= 3) {
                    return true;
                }
                i = j;
            }
            return false;
        };
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l == 0 ? -1 : l;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumLength(s string) int {
	n := len(s)
	l, r := 0, n
	check := func(x int) bool {
		cnt := [26]int{}
		for i := 0; i < n; {
			j := i + 1
			for j < n && s[j] == s[i] {
				j++
			}
			k := s[i] - 'a'
			cnt[k] += max(0, j-i-x+1)
			if cnt[k] >= 3 {
				return true
			}
			i = j
		}
		return false
	}
	for l < r {
		mid := (l + r + 1) >> 1
		if check(mid) {
			l = mid
		} else {
			r = mid - 1
		}
	}
	if l == 0 {
		return -1
	}
	return l
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumLength(s: string): number {
    const n = s.length;
    let [l, r] = [0, n];
    const check = (x: number): boolean => {
        const cnt: number[] = Array(26).fill(0);
        for (let i = 0; i < n; ) {
            let j = i + 1;
            while (j < n && s[j] === s[i]) {
                j++;
            }
            const k = s[i].charCodeAt(0) - 'a'.charCodeAt(0);
            cnt[k] += Math.max(0, j - i - x + 1);
            if (cnt[k] >= 3) {
                return true;
            }
            i = j;
        }
        return false;
    };
    while (l < r) {
        const mid = (l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l === 0 ? -1 : l;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个仅由小写英文字母组成的字符串 <code>s</code> 。</p>

<p>如果一个字符串仅由单一字符组成，那么它被称为 <strong>特殊 </strong>字符串。例如，字符串 <code>"abc"</code> 不是特殊字符串，而字符串 <code>"ddd"</code>、<code>"zz"</code> 和 <code>"f"</code> 是特殊字符串。</p>

<p>返回在 <code>s</code> 中出现 <strong>至少三次 </strong>的<strong> 最长特殊子字符串 </strong>的长度，如果不存在出现至少三次的特殊子字符串，则返回 <code>-1</code> 。</p>

<p><strong>子字符串 </strong>是字符串中的一个连续<strong> 非空 </strong>字符序列。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "aaaa"
<strong>输出：</strong>2
<strong>解释：</strong>出现三次的最长特殊子字符串是 "aa" ：子字符串 "<em><strong>aa</strong></em>aa"、"a<em><strong>aa</strong></em>a" 和 "aa<em><strong>aa</strong></em>"。
可以证明最大长度是 2 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "abcdef"
<strong>输出：</strong>-1
<strong>解释：</strong>不存在出现至少三次的特殊子字符串。因此返回 -1 。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "abcaba"
<strong>输出：</strong>1
<strong>解释：</strong>出现三次的最长特殊子字符串是 "a" ：子字符串 "<em><strong>a</strong></em>bcaba"、"abc<em><strong>a</strong></em>ba" 和 "abcab<em><strong>a</strong></em>"。
可以证明最大长度是 1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= s.length &lt;= 5 * 10<sup>5</sup></code></li>
	<li><code>s</code> 仅由小写英文字母组成。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找 + 滑动窗口计数

我们注意到，如果一个长度为 $x$ 且出现至少三次的特殊子字符串存在，那么长度为 $x-1$ 的特殊子字符串也一定存在，这存在着单调性，因此我们可以使用二分查找的方法来找到最长的特殊子字符串。

我们定义二分查找的左边界 $l = 0$，右边界 $r = n$，其中 $n$ 是字符串的长度。每次二分查找的过程中，我们取 $mid = \lfloor \frac{l + r + 1}{2} \rfloor$，如果长度为 $mid$ 的特殊子字符串存在，那么我们就将左边界更新为 $mid$，否则我们就将右边界更新为 $mid - 1$。在二分查找的过程中，我们使用滑动窗口来计算特殊子字符串的个数。

具体地，我们设计一个函数 $check(x)$，表示长度为 $x$ 且出现至少三次的特殊子字符串是否存在。

在函数 $check(x)$ 中，我们定义一个哈希表或长度为 $26$ 的数组 $cnt$，其中 $cnt[i]$ 表示长度为 $x$，且由第 $i$ 个小写字母组成的特殊子字符串的个数。我们遍历字符串 $s$，如果当前遍历到的字符为 $s[i]$，那么我们将指针 $j$ 向右移动，直到 $s[j] \neq s[i]$，此时 $s[i \cdots j-1]$ 就是一个长度为 $x$ 的特殊子字符串，我们将 $cnt[s[i]]$ 增加 $\max(0, j - i - x + 1)$，然后将指针 $i$ 更新为 $j$。

在遍历结束之后，我们遍历数组 $cnt$，如果存在 $cnt[i] \geq 3$，那么就说明长度为 $x$ 且出现至少三次的特殊子字符串存在，我们返回 $true$，否则返回 $false$。

时间复杂度 $O((n + |\Sigma|) \times \log n)$，空间复杂度 $O(|\Sigma|)$，其中 $n$ 是字符串 $s$ 的长度，而 $|\Sigma|$ 表示字符集的大小，本题中字符集为小写英文字母，因此 $|\Sigma| = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumLength(self, s: str) -> int:
        def check(x: int) -> bool:
            cnt = defaultdict(int)
            i = 0
            while i < n:
                j = i + 1
                while j < n and s[j] == s[i]:
                    j += 1
                cnt[s[i]] += max(0, j - i - x + 1)
                i = j
            return max(cnt.values()) >= 3

        n = len(s)
        l, r = 0, n
        while l < r:
            mid = (l + r + 1) >> 1
            if check(mid):
                l = mid
            else:
                r = mid - 1
        return -1 if l == 0 else l
```

#### Java

```java
class Solution {
    private String s;
    private int n;

    public int maximumLength(String s) {
        this.s = s;
        n = s.length();
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l == 0 ? -1 : l;
    }

    private boolean check(int x) {
        int[] cnt = new int[26];
        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && s.charAt(j) == s.charAt(i)) {
                j++;
            }
            int k = s.charAt(i) - 'a';
            cnt[k] += Math.max(0, j - i - x + 1);
            if (cnt[k] >= 3) {
                return true;
            }
            i = j;
        }
        return false;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        int l = 0, r = n;
        auto check = [&](int x) {
            int cnt[26]{};
            for (int i = 0; i < n;) {
                int j = i + 1;
                while (j < n && s[j] == s[i]) {
                    ++j;
                }
                int k = s[i] - 'a';
                cnt[k] += max(0, j - i - x + 1);
                if (cnt[k] >= 3) {
                    return true;
                }
                i = j;
            }
            return false;
        };
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l == 0 ? -1 : l;
    }
};
```

#### Go

```go
func maximumLength(s string) int {
	n := len(s)
	l, r := 0, n
	check := func(x int) bool {
		cnt := [26]int{}
		for i := 0; i < n; {
			j := i + 1
			for j < n && s[j] == s[i] {
				j++
			}
			k := s[i] - 'a'
			cnt[k] += max(0, j-i-x+1)
			if cnt[k] >= 3 {
				return true
			}
			i = j
		}
		return false
	}
	for l < r {
		mid := (l + r + 1) >> 1
		if check(mid) {
			l = mid
		} else {
			r = mid - 1
		}
	}
	if l == 0 {
		return -1
	}
	return l
}
```

#### TypeScript

```ts
function maximumLength(s: string): number {
    const n = s.length;
    let [l, r] = [0, n];
    const check = (x: number): boolean => {
        const cnt: number[] = Array(26).fill(0);
        for (let i = 0; i < n; ) {
            let j = i + 1;
            while (j < n && s[j] === s[i]) {
                j++;
            }
            const k = s[i].charCodeAt(0) - 'a'.charCodeAt(0);
            cnt[k] += Math.max(0, j - i - x + 1);
            if (cnt[k] >= 3) {
                return true;
            }
            i = j;
        }
        return false;
    };
    while (l < r) {
        const mid = (l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l === 0 ? -1 : l;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2983. 回文串重新排列查询](https://leetcode.cn/problems/palindrome-rearrangement-queries){#2983}

{{< tabs "2983" >}}

{{% tab "python" %}}
```python
class Solution:
    def canMakePalindromeQueries(self, s: str, queries: List[List[int]]) -> List[bool]:
        def count(pre: List[List[int]], i: int, j: int) -> List[int]:
            return [x - y for x, y in zip(pre[j + 1], pre[i])]

        def sub(cnt1: List[int], cnt2: List[int]) -> List[int]:
            res = []
            for x, y in zip(cnt1, cnt2):
                if x - y < 0:
                    return []
                res.append(x - y)
            return res

        def check(
            pre1: List[List[int]], pre2: List[List[int]], a: int, b: int, c: int, d: int
        ) -> bool:
            if diff[a] > 0 or diff[m] - diff[max(b, d) + 1] > 0:
                return False
            if d <= b:
                return count(pre1, a, b) == count(pre2, a, b)
            if b < c:
                return (
                    diff[c] - diff[b + 1] == 0
                    and count(pre1, a, b) == count(pre2, a, b)
                    and count(pre1, c, d) == count(pre2, c, d)
                )
            cnt1 = sub(count(pre1, a, b), count(pre2, a, c - 1))
            cnt2 = sub(count(pre2, c, d), count(pre1, b + 1, d))
            return bool(cnt1) and bool(cnt2) and cnt1 == cnt2

        n = len(s)
        m = n // 2
        t = s[m:][::-1]
        s = s[:m]
        pre1 = [[0] * 26 for _ in range(m + 1)]
        pre2 = [[0] * 26 for _ in range(m + 1)]
        diff = [0] * (m + 1)
        for i, (c1, c2) in enumerate(zip(s, t), 1):
            pre1[i] = pre1[i - 1][:]
            pre2[i] = pre2[i - 1][:]
            pre1[i][ord(c1) - ord("a")] += 1
            pre2[i][ord(c2) - ord("a")] += 1
            diff[i] = diff[i - 1] + int(c1 != c2)
        ans = []
        for a, b, c, d in queries:
            c, d = n - 1 - d, n - 1 - c
            ok = (
                check(pre1, pre2, a, b, c, d)
                if a <= c
                else check(pre2, pre1, c, d, a, b)
            )
            ans.append(ok)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean[] canMakePalindromeQueries(String s, int[][] queries) {
        int n = s.length();
        int m = n / 2;
        String t = new StringBuilder(s.substring(m)).reverse().toString();
        s = s.substring(0, m);
        int[][] pre1 = new int[m + 1][0];
        int[][] pre2 = new int[m + 1][0];
        int[] diff = new int[m + 1];
        pre1[0] = new int[26];
        pre2[0] = new int[26];
        for (int i = 1; i <= m; ++i) {
            pre1[i] = pre1[i - 1].clone();
            pre2[i] = pre2[i - 1].clone();
            ++pre1[i][s.charAt(i - 1) - 'a'];
            ++pre2[i][t.charAt(i - 1) - 'a'];
            diff[i] = diff[i - 1] + (s.charAt(i - 1) == t.charAt(i - 1) ? 0 : 1);
        }
        boolean[] ans = new boolean[queries.length];
        for (int i = 0; i < queries.length; ++i) {
            int[] q = queries[i];
            int a = q[0], b = q[1];
            int c = n - 1 - q[3], d = n - 1 - q[2];
            ans[i] = a <= c ? check(pre1, pre2, diff, a, b, c, d)
                            : check(pre2, pre1, diff, c, d, a, b);
        }
        return ans;
    }

    private boolean check(int[][] pre1, int[][] pre2, int[] diff, int a, int b, int c, int d) {
        if (diff[a] > 0 || diff[diff.length - 1] - diff[Math.max(b, d) + 1] > 0) {
            return false;
        }
        if (d <= b) {
            return Arrays.equals(count(pre1, a, b), count(pre2, a, b));
        }
        if (b < c) {
            return diff[c] - diff[b + 1] == 0 && Arrays.equals(count(pre1, a, b), count(pre2, a, b))
                && Arrays.equals(count(pre1, c, d), count(pre2, c, d));
        }
        int[] cnt1 = sub(count(pre1, a, b), count(pre2, a, c - 1));
        int[] cnt2 = sub(count(pre2, c, d), count(pre1, b + 1, d));
        return cnt1 != null && cnt2 != null && Arrays.equals(cnt1, cnt2);
    }

    private int[] count(int[][] pre, int i, int j) {
        int[] cnt = new int[26];
        for (int k = 0; k < 26; ++k) {
            cnt[k] = pre[j + 1][k] - pre[i][k];
        }
        return cnt;
    }

    private int[] sub(int[] cnt1, int[] cnt2) {
        int[] cnt = new int[26];
        for (int i = 0; i < 26; ++i) {
            cnt[i] = cnt1[i] - cnt2[i];
            if (cnt[i] < 0) {
                return null;
            }
        }
        return cnt;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<bool> canMakePalindromeQueries(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int m = n / 2;
        string t = string(s.begin() + m, s.end());
        reverse(t.begin(), t.end());
        s = string(s.begin(), s.begin() + m);

        vector<vector<int>> pre1(m + 1, vector<int>(26));
        vector<vector<int>> pre2(m + 1, vector<int>(26));
        vector<int> diff(m + 1, 0);
        for (int i = 1; i <= m; ++i) {
            pre1[i] = pre1[i - 1];
            pre2[i] = pre2[i - 1];
            ++pre1[i][s[i - 1] - 'a'];
            ++pre2[i][t[i - 1] - 'a'];
            diff[i] = diff[i - 1] + (s[i - 1] == t[i - 1] ? 0 : 1);
        }

        vector<bool> ans(queries.size(), false);
        for (int i = 0; i < queries.size(); ++i) {
            vector<int> q = queries[i];
            int a = q[0], b = q[1];
            int c = n - 1 - q[3], d = n - 1 - q[2];
            ans[i] = (a <= c) ? check(pre1, pre2, diff, a, b, c, d) : check(pre2, pre1, diff, c, d, a, b);
        }
        return ans;
    }

private:
    bool check(const vector<vector<int>>& pre1, const vector<vector<int>>& pre2, const vector<int>& diff, int a, int b, int c, int d) {
        if (diff[a] > 0 || diff[diff.size() - 1] - diff[max(b, d) + 1] > 0) {
            return false;
        }

        if (d <= b) {
            return count(pre1, a, b) == count(pre2, a, b);
        }

        if (b < c) {
            return diff[c] - diff[b + 1] == 0 && count(pre1, a, b) == count(pre2, a, b) && count(pre1, c, d) == count(pre2, c, d);
        }

        vector<int> cnt1 = sub(count(pre1, a, b), count(pre2, a, c - 1));
        vector<int> cnt2 = sub(count(pre2, c, d), count(pre1, b + 1, d));

        return cnt1 != vector<int>() && cnt2 != vector<int>() && cnt1 == cnt2;
    }

    vector<int> count(const vector<vector<int>>& pre, int i, int j) {
        vector<int> cnt(26);
        for (int k = 0; k < 26; ++k) {
            cnt[k] = pre[j + 1][k] - pre[i][k];
        }
        return cnt;
    }

    vector<int> sub(const vector<int>& cnt1, const vector<int>& cnt2) {
        vector<int> cnt(26);
        for (int i = 0; i < 26; ++i) {
            cnt[i] = cnt1[i] - cnt2[i];
            if (cnt[i] < 0) {
                return vector<int>();
            }
        }
        return cnt;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func canMakePalindromeQueries(s string, queries [][]int) (ans []bool) {
	n := len(s)
	m := n / 2
	t := reverse(s[m:])
	s = s[:m]

	pre1 := make([][]int, m+1)
	pre2 := make([][]int, m+1)
	diff := make([]int, m+1)
	pre1[0] = make([]int, 26)
	pre2[0] = make([]int, 26)

	for i := 1; i <= m; i++ {
		pre1[i] = slices.Clone(pre1[i-1])
		pre2[i] = slices.Clone(pre2[i-1])
		pre1[i][int(s[i-1]-'a')]++
		pre2[i][int(t[i-1]-'a')]++
		diff[i] = diff[i-1]
		if s[i-1] != t[i-1] {
			diff[i]++
		}
	}
	for _, q := range queries {
		a, b := q[0], q[1]
		c, d := n-1-q[3], n-1-q[2]
		if a <= c {
			ans = append(ans, check(pre1, pre2, diff, a, b, c, d))
		} else {
			ans = append(ans, check(pre2, pre1, diff, c, d, a, b))
		}
	}
	return
}

func check(pre1, pre2 [][]int, diff []int, a, b, c, d int) bool {
	if diff[a] > 0 || diff[len(diff)-1]-diff[max(b, d)+1] > 0 {
		return false
	}

	if d <= b {
		return slices.Equal(count(pre1, a, b), count(pre2, a, b))
	}

	if b < c {
		return diff[c]-diff[b+1] == 0 && slices.Equal(count(pre1, a, b), count(pre2, a, b)) && slices.Equal(count(pre1, c, d), count(pre2, c, d))
	}

	cnt1 := sub(count(pre1, a, b), count(pre2, a, c-1))
	cnt2 := sub(count(pre2, c, d), count(pre1, b+1, d))

	return !slices.Equal(cnt1, []int{}) && !slices.Equal(cnt2, []int{}) && slices.Equal(cnt1, cnt2)
}

func count(pre [][]int, i, j int) []int {
	cnt := make([]int, 26)
	for k := 0; k < 26; k++ {
		cnt[k] = pre[j+1][k] - pre[i][k]
	}
	return cnt
}

func sub(cnt1, cnt2 []int) []int {
	cnt := make([]int, 26)
	for i := 0; i < 26; i++ {
		cnt[i] = cnt1[i] - cnt2[i]
		if cnt[i] < 0 {
			return []int{}
		}
	}
	return cnt
}

func reverse(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function canMakePalindromeQueries(s: string, queries: number[][]): boolean[] {
    const n: number = s.length;
    const m: number = n >> 1;
    const t: string = s.slice(m).split('').reverse().join('');
    s = s.slice(0, m);

    const pre1: number[][] = Array.from({ length: m + 1 }, () => Array(26).fill(0));
    const pre2: number[][] = Array.from({ length: m + 1 }, () => Array(26).fill(0));
    const diff: number[] = Array(m + 1).fill(0);
    for (let i = 1; i <= m; ++i) {
        pre1[i] = [...pre1[i - 1]];
        pre2[i] = [...pre2[i - 1]];
        ++pre1[i][s.charCodeAt(i - 1) - 'a'.charCodeAt(0)];
        ++pre2[i][t.charCodeAt(i - 1) - 'a'.charCodeAt(0)];
        diff[i] = diff[i - 1] + (s[i - 1] === t[i - 1] ? 0 : 1);
    }

    const ans: boolean[] = Array(queries.length).fill(false);
    for (let i = 0; i < queries.length; ++i) {
        const q: number[] = queries[i];
        const [a, b] = [q[0], q[1]];
        const [c, d] = [n - 1 - q[3], n - 1 - q[2]];
        ans[i] = a <= c ? check(pre1, pre2, diff, a, b, c, d) : check(pre2, pre1, diff, c, d, a, b);
    }
    return ans;
}

function check(
    pre1: number[][],
    pre2: number[][],
    diff: number[],
    a: number,
    b: number,
    c: number,
    d: number,
): boolean {
    if (diff[a] > 0 || diff[diff.length - 1] - diff[Math.max(b, d) + 1] > 0) {
        return false;
    }

    if (d <= b) {
        return arraysEqual(count(pre1, a, b), count(pre2, a, b));
    }

    if (b < c) {
        return (
            diff[c] - diff[b + 1] === 0 &&
            arraysEqual(count(pre1, a, b), count(pre2, a, b)) &&
            arraysEqual(count(pre1, c, d), count(pre2, c, d))
        );
    }

    const cnt1: number[] | null = sub(count(pre1, a, b), count(pre2, a, c - 1));
    const cnt2: number[] | null = sub(count(pre2, c, d), count(pre1, b + 1, d));

    return cnt1 !== null && cnt2 !== null && arraysEqual(cnt1, cnt2);
}

function count(pre: number[][], i: number, j: number): number[] {
    const cnt: number[] = new Array(26).fill(0);
    for (let k = 0; k < 26; ++k) {
        cnt[k] = pre[j + 1][k] - pre[i][k];
    }
    return cnt;
}

function sub(cnt1: number[], cnt2: number[]): number[] | null {
    const cnt: number[] = new Array(26).fill(0);
    for (let i = 0; i < 26; ++i) {
        cnt[i] = cnt1[i] - cnt2[i];
        if (cnt[i] < 0) {
            return null;
        }
    }
    return cnt;
}

function arraysEqual(arr1: number[], arr2: number[]): boolean {
    return JSON.stringify(arr1) === JSON.stringify(arr2);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个长度为 <strong>偶数</strong>&nbsp;<code>n</code>&nbsp;，下标从 <strong>0</strong>&nbsp;开始的字符串&nbsp;<code>s</code>&nbsp;。</p>

<p>同时给你一个下标从 <strong>0</strong>&nbsp;开始的二维整数数组&nbsp;<code>queries</code>&nbsp;，其中&nbsp;<code>queries[i] = [a<sub>i</sub>, b<sub>i</sub>, c<sub>i</sub>, d<sub>i</sub>]</code>&nbsp;。</p>

<p>对于每个查询&nbsp;<code>i</code>&nbsp;，你需要执行以下操作：</p>

<ul>
	<li>将下标在范围&nbsp;<code>0 &lt;= a<sub>i</sub> &lt;= b<sub>i</sub> &lt; n / 2</code>&nbsp;内的&nbsp;<strong>子字符串</strong>&nbsp;<code>s[a<sub>i</sub>:b<sub>i</sub>]</code>&nbsp;中的字符重新排列。</li>
	<li>将下标在范围 <code>n / 2 &lt;= c<sub>i</sub> &lt;= d<sub>i</sub> &lt; n</code>&nbsp;内的 <strong>子字符串</strong>&nbsp;<code>s[c<sub>i</sub>:d<sub>i</sub>]</code>&nbsp;中的字符重新排列。</li>
</ul>

<p>对于每个查询，你的任务是判断执行操作后能否让 <code>s</code>&nbsp;变成一个 <strong>回文串</strong> 。</p>

<p>每个查询与其他查询都是 <strong>独立的</strong>&nbsp;。</p>

<p>请你返回一个下标从 <strong>0</strong>&nbsp;开始的数组<em>&nbsp;</em><code>answer</code>&nbsp;，如果第&nbsp;<code>i</code>&nbsp;个查询执行操作后，可以将&nbsp;<code>s</code>&nbsp;变为一个回文串，那么<em>&nbsp;</em><code>answer[i] =&nbsp;true</code>，否则为<em>&nbsp;</em><code>false</code>&nbsp;。</p>

<ul>
	<li><strong>子字符串</strong>&nbsp;指的是一个字符串中一段连续的字符序列。</li>
	<li><code>s[x:y]</code>&nbsp;表示 <code>s</code>&nbsp;中从下标 <code>x</code>&nbsp;到 <code>y</code>&nbsp;且两个端点 <strong>都包含</strong>&nbsp;的子字符串。</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>s = "abcabc", queries = [[1,1,3,5],[0,2,5,5]]
<b>输出：</b>[true,true]
<b>解释：</b>这个例子中，有 2 个查询：
第一个查询：
- a<sub>0</sub> = 1, b<sub>0</sub> = 1, c<sub>0</sub> = 3, d<sub>0</sub> = 5
- 你可以重新排列 s[1:1] =&gt; a<em><strong>b</strong></em>cabc 和 s[3:5] =&gt; abc<em><strong>abc</strong></em>&nbsp;。
- 为了让 s 变为回文串，s[3:5] 可以重新排列得到 =&gt; abc<strong><em>cba </em></strong>。
- 现在 s 是一个回文串。所以 answer[0] = true 。
第二个查询：
- a<sub>1</sub> = 0, b<sub>1</sub> = 2, c<sub>1</sub> = 5, d<sub>1</sub> = 5.
- 你可以重新排列 s[0:2] =&gt; <em><strong>abc</strong></em>abc 和 s[5:5] =&gt; abcab<strong><em>c</em></strong>&nbsp;。
- 为了让 s 变为回文串，s[0:2] 可以重新排列得到 =&gt; <em><strong>cba</strong></em>abc 。
- 现在 s 是一个回文串，所以 answer[1] = true 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>s = "abbcdecbba", queries = [[0,2,7,9]]
<b>输出：</b>[false]
<b>解释：</b>这个示例中，只有一个查询。
a<sub>0</sub> = 0, b<sub>0</sub> = 2, c<sub>0</sub> = 7, d<sub>0</sub> = 9.
你可以重新排列 s[0:2] =&gt; <em><strong>abb</strong></em>cdecbba 和 s[7:9] =&gt; abbcdec<em><strong>bba</strong></em>&nbsp;。
无法通过重新排列这些子字符串使 s 变为一个回文串，因为 s[3:6] 不是一个回文串。
所以 answer[0] = false 。</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>s = "acbcab", queries = [[1,2,4,5]]
<b>输出：</b>[true]
<strong>解释：</strong>这个示例中，只有一个查询。
a<sub>0</sub> = 1, b<sub>0</sub> = 2, c<sub>0</sub> = 4, d<sub>0</sub> = 5.
你可以重新排列 s[1:2] =&gt; a<em><strong>cb</strong></em>cab 和 s[4:5] =&gt; acbc<strong><em>ab</em></strong>&nbsp;。
为了让 s 变为回文串，s[1:2] 可以重新排列得到 =&gt; a<em><strong>bc</strong></em>cab<code>&nbsp;</code>。
然后 s[4:5] 重新排列得到 abcc<em><strong>ba</strong></em>&nbsp;。
现在 s 是一个回文串，所以 answer[0] = true 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n == s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>queries[i].length == 4</code></li>
	<li><code>a<sub>i</sub> == queries[i][0], b<sub>i</sub> == queries[i][1]</code></li>
	<li><code>c<sub>i</sub> == queries[i][2], d<sub>i</sub> == queries[i][3]</code></li>
	<li><code>0 &lt;= a<sub>i</sub> &lt;= b<sub>i</sub> &lt; n / 2</code></li>
	<li><code>n / 2 &lt;= c<sub>i</sub> &lt;= d<sub>i</sub> &lt; n </code></li>
	<li><code>n</code>&nbsp;是一个偶数。</li>
	<li><code>s</code> 只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和 + 分类讨论

我们记字符串 $s$ 的长度为 $n$，那么一半的长度为 $m = \frac{n}{2}$。接下来，我们把字符串 $s$ 分成长度相等的两段，其中第二段反转后得到字符串 $t$，第一段记为 $s$。那么对于每个查询 $[a_i, b_i, c_i, d_i]$，其中 $c_i$ 和 $d_i$ 需要变换为 $n - 1 - d_i$ 和 $n - 1 - c_i$。问题转化为：对于每个查询 $[a_i, b_i, c_i, d_i]$，判断 $s[a_i, b_i]$ 和 $t[c_i, d_i]$ 是否可以通过重新排列，使得字符串 $s$ 和 $t$ 相等。

我们预处理以下信息：

1. 字符串 $s$ 的前缀和数组 $pre_1$，其中 $pre_1[i][j]$ 表示字符串 $s$ 前 $i$ 个字符中字符 $j$ 的数量；
2. 字符串 $t$ 的前缀和数组 $pre_2$，其中 $pre_2[i][j]$ 表示字符串 $t$ 前 $i$ 个字符中字符 $j$ 的数量；
3. 字符串 $s$ 和 $t$ 的差异数组 $diff$，其中 $diff[i]$ 表示字符串 $s$ 和 $t$ 的前 $i$ 个字符中不同的字符数量。

对于每个查询 $[a_i, b_i, c_i, d_i]$，我们不妨假设 $a_i \le c_i$，那么我们需要讨论以下几种情况：

1. 字符串 $s$ 和 $t$ 的前缀子串 $s[..a_i-1]$ 和 $t[..a_i-1]$ 必须相等，并且后缀子串 $s[\max(b_i, d_i)+1..]$ 和 $t[\max(b_i, d_i)..]$ 也必须相等，否则无法通过重新排列使得字符串 $s$ 和 $t$ 相等；
1. 如果 $d_i \le b_i$，说明区间 $[a_i, b_i]$ 包含区间 $[c_i, d_i]$，那么如果 $s[a_i, b_i]$ 和 $t[a_i, b_i]$ 这两个子串包含的字符数量相同，那么就可以通过重新排列使得字符串 $s$ 和 $t$ 相等，否则无法通过重新排列使得字符串 $s$ 和 $t$ 相等；
1. 如果 $b_i < c_i$，说明区间 $[a_i, b_i]$ 和区间 $[c_i, d_i]$ 不相交，那么 $s[b_i+1, c_i-1]$ 和 $t[b_i+1, c_i-1]$ 这两个子串必须相等，并且 $s[a_i, b_i]$ 和 $t[a_i, b_i]$ 这两个子串必须相等，同时 $s[c_i, d_i]$ 和 $t[c_i, d_i]$ 这两个子串必须相等，否则无法通过重新排列使得字符串 $s$ 和 $t$ 相等。
1. 如果 $c_i \le b_i < d_i$，说明区间 $[a_i, b_i]$ 和区间 $[c_i, d_i]$ 相交，那么 $s[a_i, b_i]$ 包含的字符，减去 $t[a_i, c_i-1]$ 包含的字符，必须等于 $t[c_i, d_i]$ 包含的字符，减去 $s[b_i+1, d_i]$ 包含的字符，否则无法通过重新排列使得字符串 $s$ 和 $t$ 相等。

基于上述分析，我们遍历每个查询 $[a_i, b_i, c_i, d_i]$，判断是否满足上述条件即可。

时间复杂度 $O((n + q) \times |\Sigma|)$，空间复杂度 $O(n \times |\Sigma|)$。其中 $n$ 和 $q$ 分别是字符串 $s$ 的长度和查询数组 $queries$ 的长度；而 $|\Sigma|$ 是字符集的大小，本题中字符集为小写英文字母，因此 $|\Sigma| = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canMakePalindromeQueries(self, s: str, queries: List[List[int]]) -> List[bool]:
        def count(pre: List[List[int]], i: int, j: int) -> List[int]:
            return [x - y for x, y in zip(pre[j + 1], pre[i])]

        def sub(cnt1: List[int], cnt2: List[int]) -> List[int]:
            res = []
            for x, y in zip(cnt1, cnt2):
                if x - y < 0:
                    return []
                res.append(x - y)
            return res

        def check(
            pre1: List[List[int]], pre2: List[List[int]], a: int, b: int, c: int, d: int
        ) -> bool:
            if diff[a] > 0 or diff[m] - diff[max(b, d) + 1] > 0:
                return False
            if d <= b:
                return count(pre1, a, b) == count(pre2, a, b)
            if b < c:
                return (
                    diff[c] - diff[b + 1] == 0
                    and count(pre1, a, b) == count(pre2, a, b)
                    and count(pre1, c, d) == count(pre2, c, d)
                )
            cnt1 = sub(count(pre1, a, b), count(pre2, a, c - 1))
            cnt2 = sub(count(pre2, c, d), count(pre1, b + 1, d))
            return bool(cnt1) and bool(cnt2) and cnt1 == cnt2

        n = len(s)
        m = n // 2
        t = s[m:][::-1]
        s = s[:m]
        pre1 = [[0] * 26 for _ in range(m + 1)]
        pre2 = [[0] * 26 for _ in range(m + 1)]
        diff = [0] * (m + 1)
        for i, (c1, c2) in enumerate(zip(s, t), 1):
            pre1[i] = pre1[i - 1][:]
            pre2[i] = pre2[i - 1][:]
            pre1[i][ord(c1) - ord("a")] += 1
            pre2[i][ord(c2) - ord("a")] += 1
            diff[i] = diff[i - 1] + int(c1 != c2)
        ans = []
        for a, b, c, d in queries:
            c, d = n - 1 - d, n - 1 - c
            ok = (
                check(pre1, pre2, a, b, c, d)
                if a <= c
                else check(pre2, pre1, c, d, a, b)
            )
            ans.append(ok)
        return ans
```

#### Java

```java
class Solution {
    public boolean[] canMakePalindromeQueries(String s, int[][] queries) {
        int n = s.length();
        int m = n / 2;
        String t = new StringBuilder(s.substring(m)).reverse().toString();
        s = s.substring(0, m);
        int[][] pre1 = new int[m + 1][0];
        int[][] pre2 = new int[m + 1][0];
        int[] diff = new int[m + 1];
        pre1[0] = new int[26];
        pre2[0] = new int[26];
        for (int i = 1; i <= m; ++i) {
            pre1[i] = pre1[i - 1].clone();
            pre2[i] = pre2[i - 1].clone();
            ++pre1[i][s.charAt(i - 1) - 'a'];
            ++pre2[i][t.charAt(i - 1) - 'a'];
            diff[i] = diff[i - 1] + (s.charAt(i - 1) == t.charAt(i - 1) ? 0 : 1);
        }
        boolean[] ans = new boolean[queries.length];
        for (int i = 0; i < queries.length; ++i) {
            int[] q = queries[i];
            int a = q[0], b = q[1];
            int c = n - 1 - q[3], d = n - 1 - q[2];
            ans[i] = a <= c ? check(pre1, pre2, diff, a, b, c, d)
                            : check(pre2, pre1, diff, c, d, a, b);
        }
        return ans;
    }

    private boolean check(int[][] pre1, int[][] pre2, int[] diff, int a, int b, int c, int d) {
        if (diff[a] > 0 || diff[diff.length - 1] - diff[Math.max(b, d) + 1] > 0) {
            return false;
        }
        if (d <= b) {
            return Arrays.equals(count(pre1, a, b), count(pre2, a, b));
        }
        if (b < c) {
            return diff[c] - diff[b + 1] == 0 && Arrays.equals(count(pre1, a, b), count(pre2, a, b))
                && Arrays.equals(count(pre1, c, d), count(pre2, c, d));
        }
        int[] cnt1 = sub(count(pre1, a, b), count(pre2, a, c - 1));
        int[] cnt2 = sub(count(pre2, c, d), count(pre1, b + 1, d));
        return cnt1 != null && cnt2 != null && Arrays.equals(cnt1, cnt2);
    }

    private int[] count(int[][] pre, int i, int j) {
        int[] cnt = new int[26];
        for (int k = 0; k < 26; ++k) {
            cnt[k] = pre[j + 1][k] - pre[i][k];
        }
        return cnt;
    }

    private int[] sub(int[] cnt1, int[] cnt2) {
        int[] cnt = new int[26];
        for (int i = 0; i < 26; ++i) {
            cnt[i] = cnt1[i] - cnt2[i];
            if (cnt[i] < 0) {
                return null;
            }
        }
        return cnt;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<bool> canMakePalindromeQueries(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int m = n / 2;
        string t = string(s.begin() + m, s.end());
        reverse(t.begin(), t.end());
        s = string(s.begin(), s.begin() + m);

        vector<vector<int>> pre1(m + 1, vector<int>(26));
        vector<vector<int>> pre2(m + 1, vector<int>(26));
        vector<int> diff(m + 1, 0);
        for (int i = 1; i <= m; ++i) {
            pre1[i] = pre1[i - 1];
            pre2[i] = pre2[i - 1];
            ++pre1[i][s[i - 1] - 'a'];
            ++pre2[i][t[i - 1] - 'a'];
            diff[i] = diff[i - 1] + (s[i - 1] == t[i - 1] ? 0 : 1);
        }

        vector<bool> ans(queries.size(), false);
        for (int i = 0; i < queries.size(); ++i) {
            vector<int> q = queries[i];
            int a = q[0], b = q[1];
            int c = n - 1 - q[3], d = n - 1 - q[2];
            ans[i] = (a <= c) ? check(pre1, pre2, diff, a, b, c, d) : check(pre2, pre1, diff, c, d, a, b);
        }
        return ans;
    }

private:
    bool check(const vector<vector<int>>& pre1, const vector<vector<int>>& pre2, const vector<int>& diff, int a, int b, int c, int d) {
        if (diff[a] > 0 || diff[diff.size() - 1] - diff[max(b, d) + 1] > 0) {
            return false;
        }

        if (d <= b) {
            return count(pre1, a, b) == count(pre2, a, b);
        }

        if (b < c) {
            return diff[c] - diff[b + 1] == 0 && count(pre1, a, b) == count(pre2, a, b) && count(pre1, c, d) == count(pre2, c, d);
        }

        vector<int> cnt1 = sub(count(pre1, a, b), count(pre2, a, c - 1));
        vector<int> cnt2 = sub(count(pre2, c, d), count(pre1, b + 1, d));

        return cnt1 != vector<int>() && cnt2 != vector<int>() && cnt1 == cnt2;
    }

    vector<int> count(const vector<vector<int>>& pre, int i, int j) {
        vector<int> cnt(26);
        for (int k = 0; k < 26; ++k) {
            cnt[k] = pre[j + 1][k] - pre[i][k];
        }
        return cnt;
    }

    vector<int> sub(const vector<int>& cnt1, const vector<int>& cnt2) {
        vector<int> cnt(26);
        for (int i = 0; i < 26; ++i) {
            cnt[i] = cnt1[i] - cnt2[i];
            if (cnt[i] < 0) {
                return vector<int>();
            }
        }
        return cnt;
    }
};
```

#### Go

```go
func canMakePalindromeQueries(s string, queries [][]int) (ans []bool) {
	n := len(s)
	m := n / 2
	t := reverse(s[m:])
	s = s[:m]

	pre1 := make([][]int, m+1)
	pre2 := make([][]int, m+1)
	diff := make([]int, m+1)
	pre1[0] = make([]int, 26)
	pre2[0] = make([]int, 26)

	for i := 1; i <= m; i++ {
		pre1[i] = slices.Clone(pre1[i-1])
		pre2[i] = slices.Clone(pre2[i-1])
		pre1[i][int(s[i-1]-'a')]++
		pre2[i][int(t[i-1]-'a')]++
		diff[i] = diff[i-1]
		if s[i-1] != t[i-1] {
			diff[i]++
		}
	}
	for _, q := range queries {
		a, b := q[0], q[1]
		c, d := n-1-q[3], n-1-q[2]
		if a <= c {
			ans = append(ans, check(pre1, pre2, diff, a, b, c, d))
		} else {
			ans = append(ans, check(pre2, pre1, diff, c, d, a, b))
		}
	}
	return
}

func check(pre1, pre2 [][]int, diff []int, a, b, c, d int) bool {
	if diff[a] > 0 || diff[len(diff)-1]-diff[max(b, d)+1] > 0 {
		return false
	}

	if d <= b {
		return slices.Equal(count(pre1, a, b), count(pre2, a, b))
	}

	if b < c {
		return diff[c]-diff[b+1] == 0 && slices.Equal(count(pre1, a, b), count(pre2, a, b)) && slices.Equal(count(pre1, c, d), count(pre2, c, d))
	}

	cnt1 := sub(count(pre1, a, b), count(pre2, a, c-1))
	cnt2 := sub(count(pre2, c, d), count(pre1, b+1, d))

	return !slices.Equal(cnt1, []int{}) && !slices.Equal(cnt2, []int{}) && slices.Equal(cnt1, cnt2)
}

func count(pre [][]int, i, j int) []int {
	cnt := make([]int, 26)
	for k := 0; k < 26; k++ {
		cnt[k] = pre[j+1][k] - pre[i][k]
	}
	return cnt
}

func sub(cnt1, cnt2 []int) []int {
	cnt := make([]int, 26)
	for i := 0; i < 26; i++ {
		cnt[i] = cnt1[i] - cnt2[i]
		if cnt[i] < 0 {
			return []int{}
		}
	}
	return cnt
}

func reverse(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}
```

#### TypeScript

```ts
function canMakePalindromeQueries(s: string, queries: number[][]): boolean[] {
    const n: number = s.length;
    const m: number = n >> 1;
    const t: string = s.slice(m).split('').reverse().join('');
    s = s.slice(0, m);

    const pre1: number[][] = Array.from({ length: m + 1 }, () => Array(26).fill(0));
    const pre2: number[][] = Array.from({ length: m + 1 }, () => Array(26).fill(0));
    const diff: number[] = Array(m + 1).fill(0);
    for (let i = 1; i <= m; ++i) {
        pre1[i] = [...pre1[i - 1]];
        pre2[i] = [...pre2[i - 1]];
        ++pre1[i][s.charCodeAt(i - 1) - 'a'.charCodeAt(0)];
        ++pre2[i][t.charCodeAt(i - 1) - 'a'.charCodeAt(0)];
        diff[i] = diff[i - 1] + (s[i - 1] === t[i - 1] ? 0 : 1);
    }

    const ans: boolean[] = Array(queries.length).fill(false);
    for (let i = 0; i < queries.length; ++i) {
        const q: number[] = queries[i];
        const [a, b] = [q[0], q[1]];
        const [c, d] = [n - 1 - q[3], n - 1 - q[2]];
        ans[i] = a <= c ? check(pre1, pre2, diff, a, b, c, d) : check(pre2, pre1, diff, c, d, a, b);
    }
    return ans;
}

function check(
    pre1: number[][],
    pre2: number[][],
    diff: number[],
    a: number,
    b: number,
    c: number,
    d: number,
): boolean {
    if (diff[a] > 0 || diff[diff.length - 1] - diff[Math.max(b, d) + 1] > 0) {
        return false;
    }

    if (d <= b) {
        return arraysEqual(count(pre1, a, b), count(pre2, a, b));
    }

    if (b < c) {
        return (
            diff[c] - diff[b + 1] === 0 &&
            arraysEqual(count(pre1, a, b), count(pre2, a, b)) &&
            arraysEqual(count(pre1, c, d), count(pre2, c, d))
        );
    }

    const cnt1: number[] | null = sub(count(pre1, a, b), count(pre2, a, c - 1));
    const cnt2: number[] | null = sub(count(pre2, c, d), count(pre1, b + 1, d));

    return cnt1 !== null && cnt2 !== null && arraysEqual(cnt1, cnt2);
}

function count(pre: number[][], i: number, j: number): number[] {
    const cnt: number[] = new Array(26).fill(0);
    for (let k = 0; k < 26; ++k) {
        cnt[k] = pre[j + 1][k] - pre[i][k];
    }
    return cnt;
}

function sub(cnt1: number[], cnt2: number[]): number[] | null {
    const cnt: number[] = new Array(26).fill(0);
    for (let i = 0; i < 26; ++i) {
        cnt[i] = cnt1[i] - cnt2[i];
        if (cnt[i] < 0) {
            return null;
        }
    }
    return cnt;
}

function arraysEqual(arr1: number[], arr2: number[]): boolean {
    return JSON.stringify(arr1) === JSON.stringify(arr2);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2984. 找到每座城市的高峰通话时间 🔒](https://leetcode.cn/problems/find-peak-calling-hours-for-each-city){#2984}

{{< tabs "2984" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            *,
            RANK() OVER (
                PARTITION BY city
                ORDER BY cnt DESC
            ) AS rk
        FROM
            (
                SELECT
                    city,
                    HOUR(call_time) AS h,
                    COUNT(1) AS cnt
                FROM Calls
                GROUP BY 1, 2
            ) AS t
    )
SELECT city, h AS peak_calling_hour, cnt AS number_of_calls
FROM T
WHERE rk = 1
ORDER BY 2 DESC, 1 DESC;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：&nbsp;<code>Calls</code></p>

<pre>
+--------------+----------+
| Column Name  | Type     |
+--------------+----------+
| caller_id    | int      |
| recipient_id | int      |
| call_time    | datetime |
| city         | varchar  |
+--------------+----------+
(caller_id, recipient_id, call_time) 是该表的主键(具有唯一值的列)。
每一行包含 caller id, recipient id, call time,和 city。
</pre>

<p>编写一个查询，找到每个 <code>city</code>&nbsp;的 <strong>高峰</strong> 通话 <b>时间</b>。如果 <strong>多个时间</strong>&nbsp;有 <strong>相同</strong> 数量的通话，则所有这些时间都将被视为该特定城市的 <strong>高峰时间</strong>。</p>

<p>按照 <strong>高峰时间</strong>&nbsp;和<em> </em><code>city</code><em> </em>按 <strong>降序</strong> 排序返回结果表。</p>

<p>结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><b>示例 1:</b></p>

<pre>
<b>输入：</b>
Calls table:
+-----------+--------------+---------------------+----------+
| caller_id | recipient_id | call_time           | city     |
+-----------+--------------+---------------------+----------+
| 8         | 4            | 2021-08-24 22:46:07 | Houston  |
| 4         | 8            | 2021-08-24 22:57:13 | Houston  |  
| 5         | 1            | 2021-08-11 21:28:44 | Houston  |  
| 8         | 3            | 2021-08-17 22:04:15 | Houston  |
| 11        | 3            | 2021-08-17 13:07:00 | New York |
| 8         | 11           | 2021-08-17 14:22:22 | New York |
+-----------+--------------+---------------------+----------+
<b>输出：</b>
+----------+-------------------+-----------------+
| city     | peak_calling_hour | number_of_calls |
+----------+-------------------+-----------------+
| Houston  | 22                | 3               |
| New York | 14                | 1               |
| New York | 13                | 1               |
+----------+-------------------+-----------------+
<b>解释：</b>
对于 Houston：
  - 高峰时间是 22:00，总共记录了 3 次通话。 
对于 New York：
  - 3:00 和 14:00 都有相同数量的通话，因此这两个时间都被视为高峰时间。
输出表按照高峰时间和城市按降序排序。</pre>

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
    T AS (
        SELECT
            *,
            RANK() OVER (
                PARTITION BY city
                ORDER BY cnt DESC
            ) AS rk
        FROM
            (
                SELECT
                    city,
                    HOUR(call_time) AS h,
                    COUNT(1) AS cnt
                FROM Calls
                GROUP BY 1, 2
            ) AS t
    )
SELECT city, h AS peak_calling_hour, cnt AS number_of_calls
FROM T
WHERE rk = 1
ORDER BY 2 DESC, 1 DESC;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2985. 计算订单平均商品数量 🔒](https://leetcode.cn/problems/calculate-compressed-mean){#2985}

{{< tabs "2985" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    ROUND(
        SUM(item_count * order_occurrences) / SUM(order_occurrences),
        2
    ) AS average_items_per_order
FROM Orders;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：&nbsp;<code>Orders</code></p>

<pre>
+-------------------+------+
| Column Name       | Type |
+-------------------+------+
| order_id          | int  |
| item_count        | int  |
| order_occurrences | int  |
+-------------------+------+
order_id 是这张表具有唯一值的列。
这张表包括 order_id, item_count,和 order_occurrences。
</pre>

<p>编写一个计算每个订单的 <strong>平均</strong> 商品数量的解决方案，保留 <code>2</code> <strong>位小数。</strong></p>

<p>以<em>&nbsp;<strong>任意</strong>&nbsp;顺序返回结果表。</em></p>

<p>结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><b>示例 1:</b></p>

<pre>
<b>输入：</b>
Orders table:
+----------+------------+-------------------+
| order_id | item_count | order_occurrences | 
+----------+------------+-------------------+
| 10       | 1          | 500               | 
| 11       | 2          | 1000              |     
| 12       | 3          | 800               |  
| 13       | 4          | 1000              | 
+----------+------------+-------------------+
<b>输出</b>
+-------------------------+
| average_items_per_order | 
+-------------------------+
| 2.70                    |
+-------------------------+
<b>解释</b>
计算如下：
 - 总商品数：(1 * 500) + (2 * 1000) + (3 * 800) + (4 * 1000) = 8900 
 - 总订单数：500 + 1000 + 800 + 1000 = 3300 
 - 因此，每个订单的平均商品数量为 8900 / 3300 = 2.70
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：求和

我们使用 `SUM` 函数求出总的商品数量和总的订单数，然后相除，得到平均值，最后使用 `ROUND` 函数保留两位小数即可。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    ROUND(
        SUM(item_count * order_occurrences) / SUM(order_occurrences),
        2
    ) AS average_items_per_order
FROM Orders;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2986. 找到第三笔交易 🔒](https://leetcode.cn/problems/find-third-transaction){#2986}

{{< tabs "2986" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            *,
            RANK() OVER (
                PARTITION BY user_id
                ORDER BY transaction_date
            ) AS rk,
            spend > (
                LAG(spend) OVER (
                    PARTITION BY user_id
                    ORDER BY transaction_date
                )
            )
            AND spend > (
                LAG(spend, 2) OVER (
                    PARTITION BY user_id
                    ORDER BY transaction_date
                )
            ) AS st
        FROM Transactions
    )
SELECT user_id, spend AS third_transaction_spend, transaction_date AS third_transaction_date
FROM T
WHERE rk = 3 AND st = 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：&nbsp;<code>Transactions</code></p>

<pre>
+------------------+----------+
| Column Name      | Type     |
+------------------+----------+
| user_id          | int      |
| spend            | decimal  |
| transaction_date | datetime |
+------------------+----------+
(user_id, transaction_date) 是这张表具有唯一值的列。
该表包含 user_id, spend,和 transaction_date。
</pre>

<p>编写一个查询，找到符合要求的用户的 <strong>第三笔交易</strong> （如果他们有至少三笔交易），并且满足&nbsp;<strong>前两笔交易</strong> 的花费&nbsp;<strong>低于&nbsp;第三笔交易</strong>的花费。</p>

<p>返回&nbsp;<em>按 <strong>升序</strong>&nbsp;<code>user_id</code>&nbsp;排序的结果表。</em></p>

<p>结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><b>示例 1:</b></p>

<pre>
<b>输入：</b>
Transactions table:
+---------+--------+---------------------+
| user_id | spend  | transaction_date    | 
+---------+--------+---------------------+
| 1       | 65.56  | 2023-11-18 13:49:42 | 
| 1       | 96.0   | 2023-11-30 02:47:26 |     
| 1       | 7.44   | 2023-11-02 12:15:23 | 
| 1       | 49.78  | 2023-11-12 00:13:46 | 
| 2       | 40.89  | 2023-11-21 04:39:15 |  
| 2       | 100.44 | 2023-11-20 07:39:34 | 
| 3       | 37.33  | 2023-11-03 06:22:02 | 
| 3       | 13.89  | 2023-11-11 16:00:14 | 
| 3       | 7.0    | 2023-11-29 22:32:36 | 
+---------+--------+---------------------+
<b>输出</b>
+---------+-------------------------+------------------------+
| user_id | third_transaction_spend | third_transaction_date | 
+---------+-------------------------+------------------------+
| 1       | 65.56                   | 2023-11-18 13:49:42    |  
+---------+-------------------------+------------------------+
<b>解释</b>
- 对于 user_id 1，他们的第三笔交易发生在 2023-11-18 13:49:42，金额为 $65.56，超过了前两笔交易的支出，分别是 2023-11-02 12:15:23 的 $7.44 和 2023-11-12 00:13:46 的 $49.78。因此，此第三笔交易将包含在输出表中。
- user_id 2 只有总共 2 笔交易，因此没有第三笔交易。
- 对于 user_id 3，第三笔交易的金额 $7.0 少于前两笔交易，因此不会包含在内。
输出表按升序按 user_id 排序。

</pre>

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
    T AS (
        SELECT
            *,
            RANK() OVER (
                PARTITION BY user_id
                ORDER BY transaction_date
            ) AS rk,
            spend > (
                LAG(spend) OVER (
                    PARTITION BY user_id
                    ORDER BY transaction_date
                )
            )
            AND spend > (
                LAG(spend, 2) OVER (
                    PARTITION BY user_id
                    ORDER BY transaction_date
                )
            ) AS st
        FROM Transactions
    )
SELECT user_id, spend AS third_transaction_spend, transaction_date AS third_transaction_date
FROM T
WHERE rk = 3 AND st = 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2987. 寻找房价最贵的城市 🔒](https://leetcode.cn/problems/find-expensive-cities){#2987}

{{< tabs "2987" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT city
FROM Listings
GROUP BY city
HAVING AVG(price) > (SELECT AVG(price) FROM Listings)
ORDER BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：&nbsp;<code>Listings</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| listing_id  | int     |
| city        | varchar |
| price       | int     |
+-------------+---------+
listing_id 是这张表具有唯一值的列。
这张表包括 listing_id, city,和 price。
</pre>

<p>编写一个解决方案，查找 <strong>房价平均值</strong> 超过 <strong>全国</strong> 平均房价的 <strong>城市</strong>。</p>

<p>返回 <em>按&nbsp;</em><code>city</code><em> </em><em><strong>升序</strong> 排序的结果表。</em></p>

<p>结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><b>示例 1:</b></p>

<pre>
<b>输入：</b>
Listings table:
+------------+--------------+---------+
| listing_id | city         | price   | 
+------------+--------------+---------+
| 113        | LosAngeles   | 7560386 | 
| 136        | SanFrancisco | 2380268 |     
| 92         | Chicago      | 9833209 | 
| 60         | Chicago      | 5147582 | 
| 8          | Chicago      | 5274441 |  
| 79         | SanFrancisco | 8372065 | 
| 37         | Chicago      | 7939595 | 
| 53         | LosAngeles   | 4965123 | 
| 178        | SanFrancisco | 999207  | 
| 51         | NewYork      | 5951718 | 
| 121        | NewYork      | 2893760 | 
+------------+--------------+---------+
<b>输出</b>
+------------+
| city       | 
+------------+
| Chicago    | 
| LosAngeles |  
+------------+
<b>解释</b>
全国平均房价为 $6,122,059.45。在列出的城市中：
- Chicago 的平均价格为 $7,048,706.75
- Los Angeles 的平均价格为 $6,277,754.5
- San Francisco 的平均价格为 $3,900,513.33
- New York 的平均价格为 $4,422,739
只有 Chicago 和 Los Angeles 的平均房价超过了全国平均水平。因此，这两个城市包含在输出表中。输出表按城市名称升序排序。
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分组聚合 + 子查询

我们将 `Listings` 表按照 `city` 分组，然后计算每个城市的平均房价，最后筛选出平均房价大于全国平均房价的城市即可。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT city
FROM Listings
GROUP BY city
HAVING AVG(price) > (SELECT AVG(price) FROM Listings)
ORDER BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2988. 最大部门的经理 🔒](https://leetcode.cn/problems/manager-of-the-largest-department){#2988}

{{< tabs "2988" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT dep_id, COUNT(1) AS cnt
        FROM Employees
        GROUP BY 1
    )
SELECT emp_name AS manager_name, t.dep_id
FROM
    T AS t
    JOIN Employees AS e ON t.dep_id = e.dep_id AND e.position = 'Manager'
WHERE cnt = (SELECT MAX(cnt) FROM T)
ORDER BY 2;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：&nbsp;<code>Employees</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| emp_id      | int     |
| emp_name    | varchar |
| dep_id      | int     |
| position    | varchar |
+-------------+---------+
emp_id 是这张表具有唯一值的列。
这张表包括 emp_id, emp_name, dep_id,和 position。
</pre>

<p>查询 <strong>最大部门</strong> 的&nbsp;<strong>经理</strong>&nbsp;的&nbsp;<strong>名字</strong>。当拥有相同数量的员工时，可能会有多个最大部门。</p>

<p>返回&nbsp;<em>按照</em> <code>dep_id</code> <em><strong>升序</strong> 排列的结果表格。</em></p>

<p>结果表格的格式如下例所示。</p>

<p>&nbsp;</p>

<p><b>示例 1:</b></p>

<pre>
<b>输入：</b>
Employees table:
+--------+----------+--------+---------------+
| emp_id | emp_name | dep_id | position      | 
+--------+----------+--------+---------------+
| 156    | Michael  | 107    | Manager       |
| 112    | Lucas    | 107    | Consultant    |    
| 8      | Isabella | 101    | Manager       | 
| 160    | Joseph   | 100    | Manager       | 
| 80     | Aiden    | 100    | Engineer      | 
| 190    | Skylar   | 100    | Freelancer    | 
| 196    | Stella   | 101    | Coordinator   |
| 167    | Audrey   | 100    | Consultant    |
| 97     | Nathan   | 101    | Supervisor    |
| 128    | Ian      | 101    | Administrator |
| 81     | Ethan    | 107    | Administrator |
+--------+----------+--------+---------------+
<b>输出</b>
+--------------+--------+
| manager_name | dep_id | 
+--------------+--------+
| Joseph       | 100    | 
| Isabella     | 101    | 
+--------------+--------+
<b>解释</b>
- 部门 ID 为 100 和 101 的每个部门都有 4 名员工，而部门 107 有 3 名员工。由于部门 100 和 101 都拥有相同数量的员工，它们各自的经理将被包括在内。
输出表格按 dep_id 升序排列。

</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分组 + 等值连接 + 子查询

我们可以先统计每个部门的员工数量，记为表 `T`，然后我们将 `T` 与 `Employees` 表进行连接，连接条件为 `T.dep_id = Employees.dep_id`，并且 `Employees.position = 'Manager'`，这样就可以得到每个部门的经理，最后我们再筛选出员工数量最多的部门即可。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT dep_id, COUNT(1) AS cnt
        FROM Employees
        GROUP BY 1
    )
SELECT emp_name AS manager_name, t.dep_id
FROM
    T AS t
    JOIN Employees AS e ON t.dep_id = e.dep_id AND e.position = 'Manager'
WHERE cnt = (SELECT MAX(cnt) FROM T)
ORDER BY 2;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2989. 班级表现 🔒](https://leetcode.cn/problems/class-performance){#2989}

{{< tabs "2989" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    MAX(assignment1 + assignment2 + assignment3) - MIN(
        assignment1 + assignment2 + assignment3
    ) AS difference_in_score
FROM Scores;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：&nbsp;<code>Scores</code></p>

<pre>
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| student_id   | int     |
| student_name | varchar |
| assignment1  | int     |
| assignment2  | int     |
| assignment3  | int     |
+--------------+---------+
student_id 是这张表具有唯一值的列。
该表包含 student_id, student_name, assignment1, assignment2,和 assignment3。
</pre>

<p>编写一个查询，计算学生获得的&nbsp;<strong>最高总分&nbsp;</strong>和&nbsp;<strong>最低总分&nbsp;</strong>之间的&nbsp;<strong>差</strong>（<code>3</code> 次作业的总和）。</p>

<p>以 <em><strong>任意</strong> 顺序返回结果表。</em></p>

<p>结果表的格式如下示例所示。</p>

<p>&nbsp;</p>

<p><b>示例 1:</b></p>

<pre>
<b>输入：</b>
Scores 表：
+------------+--------------+-------------+-------------+-------------+
| student_id | student_name | assignment1 | assignment2 | assignment3 |
+------------+--------------+-------------+-------------+-------------+
| 309        | Owen         | 88          | 47          | 87          |
| 321        | Claire       | 98          | 95          | 37          |     
| 338        | Julian       | 100         | 64          | 43          |  
| 423        | Peyton       | 60          | 44          | 47          |  
| 896        | David        | 32          | 37          | 50          | 
| 235        | Camila       | 31          | 53          | 69          | 
+------------+--------------+-------------+-------------+-------------+
<b>输出</b>
+---------------------+
| difference_in_score | 
+---------------------+
| 111                 | 
+---------------------+
<b>解释</b>
- student_id 309 的总分为 88 + 47 + 87 = 222。
- student_id 321 的总分为 98 + 95 + 37 = 230。
- student_id 338 的总分为 100 + 64 + 43 = 207。
- student_id 423 的总分为 60 + 44 + 47 = 151。
- student_id 896 的总分为 32 + 37 + 50 = 119。
- student_id 235 的总分为 31 + 53 + 69 = 153。
student_id 321 拥有最高分为 230，而 student_id 896 拥有最低分为 119。因此，它们之间的差异为 111。
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：最大值最小值

我们可以使用 `MAX` 和 `MIN` 函数来分别获取 `assignment1`、`assignment2`、`assignment3` 的和的最大值和最小值，然后相减即可。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    MAX(assignment1 + assignment2 + assignment3) - MIN(
        assignment1 + assignment2 + assignment3
    ) AS difference_in_score
FROM Scores;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
