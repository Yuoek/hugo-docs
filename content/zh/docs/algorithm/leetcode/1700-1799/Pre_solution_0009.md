---
title: "1780_判断一个数字是否可以表示成三的幂的和"
date: 2025-10-08T18:38:17+08:00
weight: 9
tags: [二分查找, 位运算, 前缀和, 动态规划, 双指针, 哈希表, 图, 堆（优先队列）, 字符串, 拓扑排序, 排序, 数学, 数据库, 数组, 最短路, 计数, 贪心]
---

{{< markmap >}}
### [1780_判断一个数字是否可以表示成三的幂的和](#1780)
#### [数学](#1780)
### [1781_所有子字符串美丽值之和](#1781)
#### [哈希表](#1781)
#### [字符串](#1781)
#### [计数](#1781)
### [1782_统计点对的数目](#1782)
#### [图](#1782)
#### [数组](#1782)
#### [哈希表](#1782)
#### [双指针](#1782)
#### [二分查找](#1782)
#### [计数](#1782)
#### [排序](#1782)
### [1783_大满贯数量 🔒](#1783)
#### [数据库](#1783)
### [1784_检查二进制字符串字段](#1784)
#### [字符串](#1784)
### [1785_构成特定和需要添加的最少元素](#1785)
#### [贪心](#1785)
#### [数组](#1785)
### [1786_从第一个节点出发到最后一个节点的受限路径数](#1786)
#### [图](#1786)
#### [拓扑排序](#1786)
#### [动态规划](#1786)
#### [最短路](#1786)
#### [堆（优先队列）](#1786)
### [1787_使所有区间的异或结果为零](#1787)
#### [位运算](#1787)
#### [数组](#1787)
#### [动态规划](#1787)
### [1788_最大化花园的美观度 🔒](#1788)
#### [贪心](#1788)
#### [数组](#1788)
#### [哈希表](#1788)
#### [前缀和](#1788)
### [1789_员工的直属部门](#1789)
#### [数据库](#1789)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1780_判断一个数字是否可以表示成三的幂的和
___
#### 数学
---
### 1781_所有子字符串美丽值之和
___
#### 哈希表
___
#### 字符串
___
#### 计数
---
### 1782_统计点对的数目
___
#### 图
___
#### 数组
___
#### 哈希表
___
#### 双指针
___
#### 二分查找
___
#### 计数
___
#### 排序
---
### 1783_大满贯数量 🔒
___
#### 数据库
---
### 1784_检查二进制字符串字段
___
#### 字符串
---
### 1785_构成特定和需要添加的最少元素
___
#### 贪心
___
#### 数组
---
### 1786_从第一个节点出发到最后一个节点的受限路径数
___
#### 图
___
#### 拓扑排序
___
#### 动态规划
___
#### 最短路
___
#### 堆（优先队列）
---
### 1787_使所有区间的异或结果为零
___
#### 位运算
___
#### 数组
___
#### 动态规划
---
### 1788_最大化花园的美观度 🔒
___
#### 贪心
___
#### 数组
___
#### 哈希表
___
#### 前缀和
---
### 1789_员工的直属部门
___
#### 数据库
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 前缀和 |
| 动态规划 | 双指针 | 哈希表 |
| 图 | 堆（优先队列） | 字符串 |
| 拓扑排序 | 排序 | 数学 |
| 数据库 | 数组 | 最短路 |
| 计数 | 贪心 |  |

# [1780. 判断一个数字是否可以表示成三的幂的和](https://leetcode.cn/problems/check-if-number-is-a-sum-of-powers-of-three){#1780}

{{< tabs "1780" >}}

{{% tab "python" %}}
```python
class Solution:
    def checkPowersOfThree(self, n: int) -> bool:
        while n:
            if n % 3 > 1:
                return False
            n //= 3
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean checkPowersOfThree(int n) {
        while (n > 0) {
            if (n % 3 > 1) {
                return false;
            }
            n /= 3;
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
    bool checkPowersOfThree(int n) {
        while (n) {
            if (n % 3 > 1) return false;
            n /= 3;
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func checkPowersOfThree(n int) bool {
	for n > 0 {
		if n%3 > 1 {
			return false
		}
		n /= 3
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function checkPowersOfThree(n: number): boolean {
    while (n) {
        if (n % 3 > 1) return false;
        n = Math.floor(n / 3);
    }
    return true;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn check_powers_of_three(n: i32) -> bool {
        let mut n = n;
        while n > 0 {
            if n % 3 > 1 {
                return false;
            }
            n /= 3;
        }
        true
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public bool CheckPowersOfThree(int n) {
        while (n > 0) {
            if (n % 3 > 1) {
                return false;
            }
            n /= 3;
        }
        return true;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数 <code>n</code> ，如果你可以将 <code>n</code> 表示成若干个不同的三的幂之和，请你返回 <code>true</code> ，否则请返回 <code>false</code> 。</p>

<p>对于一个整数 <code>y</code> ，如果存在整数 <code>x</code> 满足 <code>y == 3<sup>x</sup></code> ，我们称这个整数 <code>y</code> 是三的幂。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>n = 12
<b>输出：</b>true
<b>解释：</b>12 = 3<sup>1</sup> + 3<sup>2</sup>
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>n = 91
<b>输出：</b>true
<b>解释：</b>91 = 3<sup>0</sup> + 3<sup>2</sup> + 3<sup>4</sup>
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>n = 21
<b>输出：</b>false
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>7</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学分析

我们发现，如果一个数 $n$ 可以表示成若干个“不同的”三的幂之和，那么 $n$ 的三进制表示中，每一位上的数字只能是 $0$ 或者 $1$。

因此，我们将 $n$ 转换成三进制，然后判断每一位上的数字是否是 $0$ 或者 $1$。如果不是，那么 $n$ 就不可以表示成若干个三的幂之和，直接返回 $\textit{false}$；否则 $n$ 可以表示成若干个三的幂之和，返回 $\textit{true}$。

时间复杂度 $O(\log_3 n)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def checkPowersOfThree(self, n: int) -> bool:
        while n:
            if n % 3 > 1:
                return False
            n //= 3
        return True
```

#### Java

```java
class Solution {
    public boolean checkPowersOfThree(int n) {
        while (n > 0) {
            if (n % 3 > 1) {
                return false;
            }
            n /= 3;
        }
        return true;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n) {
            if (n % 3 > 1) return false;
            n /= 3;
        }
        return true;
    }
};
```

#### Go

```go
func checkPowersOfThree(n int) bool {
	for n > 0 {
		if n%3 > 1 {
			return false
		}
		n /= 3
	}
	return true
}
```

#### TypeScript

```ts
function checkPowersOfThree(n: number): boolean {
    while (n) {
        if (n % 3 > 1) return false;
        n = Math.floor(n / 3);
    }
    return true;
}
```

#### Rust

```rust
impl Solution {
    pub fn check_powers_of_three(n: i32) -> bool {
        let mut n = n;
        while n > 0 {
            if n % 3 > 1 {
                return false;
            }
            n /= 3;
        }
        true
    }
}
```

#### C#

```cs
public class Solution {
    public bool CheckPowersOfThree(int n) {
        while (n > 0) {
            if (n % 3 > 1) {
                return false;
            }
            n /= 3;
        }
        return true;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1781. 所有子字符串美丽值之和](https://leetcode.cn/problems/sum-of-beauty-of-all-substrings){#1781}

{{< tabs "1781" >}}

{{% tab "python" %}}
```python
class Solution:
    def beautySum(self, s: str) -> int:
        ans, n = 0, len(s)
        for i in range(n):
            cnt = Counter()
            freq = Counter()
            mi = mx = 1
            for j in range(i, n):
                freq[cnt[s[j]]] -= 1
                cnt[s[j]] += 1
                freq[cnt[s[j]]] += 1

                if cnt[s[j]] == 1:
                    mi = 1
                if freq[mi] == 0:
                    mi += 1
                if cnt[s[j]] > mx:
                    mx = cnt[s[j]]

                ans += mx - mi
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int beautySum(String s) {
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int[] cnt = new int[26];
            Map<Integer, Integer> freq = new HashMap<>();
            int mi = 1, mx = 1;
            for (int j = i; j < n; ++j) {
                int k = s.charAt(j) - 'a';
                freq.merge(cnt[k], -1, Integer::sum);
                ++cnt[k];
                freq.merge(cnt[k], 1, Integer::sum);

                if (cnt[k] == 1) {
                    mi = 1;
                }
                if (freq.getOrDefault(mi, 0) == 0) {
                    ++mi;
                }
                if (cnt[k] > mx) {
                    mx = cnt[k];
                }
                ans += mx - mi;
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
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int cnt[26]{};
            unordered_map<int, int> freq;
            int mi = 1, mx = 1;
            for (int j = i; j < n; ++j) {
                int k = s[j] - 'a';
                --freq[cnt[k]];
                ++cnt[k];
                ++freq[cnt[k]];

                if (cnt[k] == 1) {
                    mi = 1;
                }
                if (freq[mi] == 0) {
                    ++mi;
                }
                if (cnt[k] > mx) {
                    mx = cnt[k];
                }
                ans += mx - mi;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func beautySum(s string) (ans int) {
	n := len(s)
	for i := 0; i < n; i++ {
		cnt := [26]int{}
		freq := map[int]int{}
		mi, mx := 1, 1
		for j := i; j < n; j++ {
			k := int(s[j] - 'a')
			freq[cnt[k]]--
			cnt[k]++
			freq[cnt[k]]++

			if cnt[k] == 1 {
				mi = 1
			}
			if freq[mi] == 0 {
				mi++
			}
			if cnt[k] > mx {
				mx = cnt[k]
			}
			ans += mx - mi
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function beautySum(s: string): number {
    let ans = 0;
    for (let i = 0; i < s.length; ++i) {
        const cnt = new Map();
        for (let j = i; j < s.length; ++j) {
            cnt.set(s[j], (cnt.get(s[j]) || 0) + 1);
            const t = Array.from(cnt.values());
            ans += Math.max(...t) - Math.min(...t);
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn beauty_sum(s: String) -> i32 {
        let mut ans = 0;
        let n = s.len();
        let s: Vec<char> = s.chars().collect();

        for i in 0..n {
            let mut cnt = vec![0; 26];
            for j in i..n {
                cnt[s[j] as usize - 'a' as usize] += 1;
                let mut mi = 1000;
                let mut mx = 0;
                for &v in &cnt {
                    if v > 0 {
                        mi = mi.min(v);
                        mx = mx.max(v);
                    }
                }
                ans += mx - mi;
            }
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} s
 * @return {number}
 */
var beautySum = function (s) {
    const n = s.length;
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        const cnt = Array(26).fill(0);
        const freq = new Map();
        let [mi, mx] = [1, 1];
        for (let j = i; j < n; ++j) {
            const k = s[j].charCodeAt() - 97;
            freq.set(cnt[k], (freq.get(cnt[k]) || 0) - 1);
            ++cnt[k];
            freq.set(cnt[k], (freq.get(cnt[k]) || 0) + 1);
            if (cnt[k] === 1) {
                mi = 1;
            }
            if (freq.get(mi) === 0) {
                ++mi;
            }
            if (cnt[k] > mx) {
                mx = cnt[k];
            }
            ans += mx - mi;
        }
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

<p>一个字符串的 <strong>美丽值</strong> 定义为：出现频率最高字符与出现频率最低字符的出现次数之差。</p>

<ul>
	<li>比方说，<code>"abaacc"</code> 的美丽值为 <code>3 - 1 = 2</code> 。</li>
</ul>

<p>给你一个字符串 <code>s</code> ，请你返回它所有子字符串的 <strong>美丽值</strong> 之和。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>s = "aabcb"
<b>输出：</b>5
<strong>解释：</strong>美丽值不为零的字符串包括 ["aab","aabc","aabcb","abcb","bcb"] ，每一个字符串的美丽值都为 1 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>s = "aabcbaa"
<b>输出：</b>17
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= s.length <=<sup> </sup>500</code></li>
	<li><code>s</code> 只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举 + 计数

枚举每个子串的起点位置 $i$，找到以该起点位置的字符为左端点的所有子串，然后计算每个子串的美丽值，累加到答案中。

时间复杂度 $O(n^2 \times C)$，空间复杂度 $O(C)$。其中 $n$ 为字符串的长度，而 $C$ 为字符集的大小。本题中 $C = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def beautySum(self, s: str) -> int:
        ans, n = 0, len(s)
        for i in range(n):
            cnt = Counter()
            for j in range(i, n):
                cnt[s[j]] += 1
                ans += max(cnt.values()) - min(cnt.values())
        return ans
```

#### Java

```java
class Solution {
    public int beautySum(String s) {
        int ans = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            int[] cnt = new int[26];
            for (int j = i; j < n; ++j) {
                ++cnt[s.charAt(j) - 'a'];
                int mi = 1000, mx = 0;
                for (int v : cnt) {
                    if (v > 0) {
                        mi = Math.min(mi, v);
                        mx = Math.max(mx, v);
                    }
                }
                ans += mx - mi;
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
    int beautySum(string s) {
        int ans = 0;
        int n = s.size();
        int cnt[26];
        for (int i = 0; i < n; ++i) {
            memset(cnt, 0, sizeof cnt);
            for (int j = i; j < n; ++j) {
                ++cnt[s[j] - 'a'];
                int mi = 1000, mx = 0;
                for (int& v : cnt) {
                    if (v > 0) {
                        mi = min(mi, v);
                        mx = max(mx, v);
                    }
                }
                ans += mx - mi;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func beautySum(s string) (ans int) {
	for i := range s {
		cnt := [26]int{}
		for j := i; j < len(s); j++ {
			cnt[s[j]-'a']++
			mi, mx := 1000, 0
			for _, v := range cnt {
				if v > 0 {
					if mi > v {
						mi = v
					}
					if mx < v {
						mx = v
					}
				}
			}
			ans += mx - mi
		}
	}
	return
}
```

#### TypeScript

```ts
function beautySum(s: string): number {
    let ans = 0;
    for (let i = 0; i < s.length; ++i) {
        const cnt = new Map();
        for (let j = i; j < s.length; ++j) {
            cnt.set(s[j], (cnt.get(s[j]) || 0) + 1);
            const t = Array.from(cnt.values());
            ans += Math.max(...t) - Math.min(...t);
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn beauty_sum(s: String) -> i32 {
        let mut ans = 0;
        let n = s.len();
        let s: Vec<char> = s.chars().collect();

        for i in 0..n {
            let mut cnt = vec![0; 26];
            for j in i..n {
                cnt[s[j] as usize - 'a' as usize] += 1;
                let mut mi = 1000;
                let mut mx = 0;
                for &v in &cnt {
                    if v > 0 {
                        mi = mi.min(v);
                        mx = mx.max(v);
                    }
                }
                ans += mx - mi;
            }
        }
        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {string} s
 * @return {number}
 */
var beautySum = function (s) {
    let ans = 0;
    for (let i = 0; i < s.length; ++i) {
        const cnt = new Map();
        for (let j = i; j < s.length; ++j) {
            cnt.set(s[j], (cnt.get(s[j]) || 0) + 1);
            const t = Array.from(cnt.values());
            ans += Math.max(...t) - Math.min(...t);
        }
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def beautySum(self, s: str) -> int:
        ans, n = 0, len(s)
        for i in range(n):
            cnt = Counter()
            freq = Counter()
            mi = mx = 1
            for j in range(i, n):
                freq[cnt[s[j]]] -= 1
                cnt[s[j]] += 1
                freq[cnt[s[j]]] += 1

                if cnt[s[j]] == 1:
                    mi = 1
                if freq[mi] == 0:
                    mi += 1
                if cnt[s[j]] > mx:
                    mx = cnt[s[j]]

                ans += mx - mi
        return ans
```

#### Java

```java
class Solution {
    public int beautySum(String s) {
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int[] cnt = new int[26];
            Map<Integer, Integer> freq = new HashMap<>();
            int mi = 1, mx = 1;
            for (int j = i; j < n; ++j) {
                int k = s.charAt(j) - 'a';
                freq.merge(cnt[k], -1, Integer::sum);
                ++cnt[k];
                freq.merge(cnt[k], 1, Integer::sum);

                if (cnt[k] == 1) {
                    mi = 1;
                }
                if (freq.getOrDefault(mi, 0) == 0) {
                    ++mi;
                }
                if (cnt[k] > mx) {
                    mx = cnt[k];
                }
                ans += mx - mi;
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
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int cnt[26]{};
            unordered_map<int, int> freq;
            int mi = 1, mx = 1;
            for (int j = i; j < n; ++j) {
                int k = s[j] - 'a';
                --freq[cnt[k]];
                ++cnt[k];
                ++freq[cnt[k]];

                if (cnt[k] == 1) {
                    mi = 1;
                }
                if (freq[mi] == 0) {
                    ++mi;
                }
                if (cnt[k] > mx) {
                    mx = cnt[k];
                }
                ans += mx - mi;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func beautySum(s string) (ans int) {
	n := len(s)
	for i := 0; i < n; i++ {
		cnt := [26]int{}
		freq := map[int]int{}
		mi, mx := 1, 1
		for j := i; j < n; j++ {
			k := int(s[j] - 'a')
			freq[cnt[k]]--
			cnt[k]++
			freq[cnt[k]]++

			if cnt[k] == 1 {
				mi = 1
			}
			if freq[mi] == 0 {
				mi++
			}
			if cnt[k] > mx {
				mx = cnt[k]
			}
			ans += mx - mi
		}
	}
	return
}
```

#### JavaScript

```js
/**
 * @param {string} s
 * @return {number}
 */
var beautySum = function (s) {
    const n = s.length;
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        const cnt = Array(26).fill(0);
        const freq = new Map();
        let [mi, mx] = [1, 1];
        for (let j = i; j < n; ++j) {
            const k = s[j].charCodeAt() - 97;
            freq.set(cnt[k], (freq.get(cnt[k]) || 0) - 1);
            ++cnt[k];
            freq.set(cnt[k], (freq.get(cnt[k]) || 0) + 1);
            if (cnt[k] === 1) {
                mi = 1;
            }
            if (freq.get(mi) === 0) {
                ++mi;
            }
            if (cnt[k] > mx) {
                mx = cnt[k];
            }
            ans += mx - mi;
        }
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1782. 统计点对的数目](https://leetcode.cn/problems/count-pairs-of-nodes){#1782}

{{< tabs "1782" >}}

{{% tab "python" %}}
```python
class Solution:
    def countPairs(
        self, n: int, edges: List[List[int]], queries: List[int]
    ) -> List[int]:
        cnt = [0] * n
        g = defaultdict(int)
        for a, b in edges:
            a, b = a - 1, b - 1
            a, b = min(a, b), max(a, b)
            cnt[a] += 1
            cnt[b] += 1
            g[(a, b)] += 1

        s = sorted(cnt)
        ans = [0] * len(queries)
        for i, t in enumerate(queries):
            for j, x in enumerate(s):
                k = bisect_right(s, t - x, lo=j + 1)
                ans[i] += n - k
            for (a, b), v in g.items():
                if cnt[a] + cnt[b] > t and cnt[a] + cnt[b] - v <= t:
                    ans[i] -= 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] countPairs(int n, int[][] edges, int[] queries) {
        int[] cnt = new int[n];
        Map<Integer, Integer> g = new HashMap<>();
        for (var e : edges) {
            int a = e[0] - 1, b = e[1] - 1;
            ++cnt[a];
            ++cnt[b];
            int k = Math.min(a, b) * n + Math.max(a, b);
            g.merge(k, 1, Integer::sum);
        }
        int[] s = cnt.clone();
        Arrays.sort(s);
        int[] ans = new int[queries.length];
        for (int i = 0; i < queries.length; ++i) {
            int t = queries[i];
            for (int j = 0; j < n; ++j) {
                int x = s[j];
                int k = search(s, t - x, j + 1);
                ans[i] += n - k;
            }
            for (var e : g.entrySet()) {
                int a = e.getKey() / n, b = e.getKey() % n;
                int v = e.getValue();
                if (cnt[a] + cnt[b] > t && cnt[a] + cnt[b] - v <= t) {
                    --ans[i];
                }
            }
        }
        return ans;
    }

    private int search(int[] arr, int x, int i) {
        int left = i, right = arr.length;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (arr[mid] > x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> cnt(n);
        unordered_map<int, int> g;
        for (auto& e : edges) {
            int a = e[0] - 1, b = e[1] - 1;
            ++cnt[a];
            ++cnt[b];
            int k = min(a, b) * n + max(a, b);
            ++g[k];
        }
        vector<int> s = cnt;
        sort(s.begin(), s.end());
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            int t = queries[i];
            for (int j = 0; j < n; ++j) {
                int x = s[j];
                int k = upper_bound(s.begin() + j + 1, s.end(), t - x) - s.begin();
                ans[i] += n - k;
            }
            for (auto& [k, v] : g) {
                int a = k / n, b = k % n;
                if (cnt[a] + cnt[b] > t && cnt[a] + cnt[b] - v <= t) {
                    --ans[i];
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
func countPairs(n int, edges [][]int, queries []int) []int {
	cnt := make([]int, n)
	g := map[int]int{}
	for _, e := range edges {
		a, b := e[0]-1, e[1]-1
		cnt[a]++
		cnt[b]++
		if a > b {
			a, b = b, a
		}
		g[a*n+b]++
	}
	s := make([]int, n)
	copy(s, cnt)
	sort.Ints(s)
	ans := make([]int, len(queries))
	for i, t := range queries {
		for j, x := range s {
			k := sort.Search(n, func(h int) bool { return s[h] > t-x && h > j })
			ans[i] += n - k
		}
		for k, v := range g {
			a, b := k/n, k%n
			if cnt[a]+cnt[b] > t && cnt[a]+cnt[b]-v <= t {
				ans[i]--
			}
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countPairs(n: number, edges: number[][], queries: number[]): number[] {
    const cnt: number[] = new Array(n).fill(0);
    const g: Map<number, number> = new Map();
    for (const [a, b] of edges) {
        ++cnt[a - 1];
        ++cnt[b - 1];
        const k = Math.min(a - 1, b - 1) * n + Math.max(a - 1, b - 1);
        g.set(k, (g.get(k) || 0) + 1);
    }
    const s = cnt.slice().sort((a, b) => a - b);
    const search = (nums: number[], x: number, l: number): number => {
        let r = nums.length;
        while (l < r) {
            const mid = (l + r) >> 1;
            if (nums[mid] > x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };
    const ans: number[] = [];
    for (const t of queries) {
        let res = 0;
        for (let j = 0; j < s.length; ++j) {
            const k = search(s, t - s[j], j + 1);
            res += n - k;
        }
        for (const [k, v] of g) {
            const a = Math.floor(k / n);
            const b = k % n;
            if (cnt[a] + cnt[b] > t && cnt[a] + cnt[b] - v <= t) {
                --res;
            }
        }
        ans.push(res);
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

<p>给你一个无向图，无向图由整数&nbsp;<code>n</code>&nbsp;&nbsp;，表示图中节点的数目，和&nbsp;<code>edges</code>&nbsp;组成，其中&nbsp;<code>edges[i] = [u<sub>i</sub>, v<sub>i</sub>]</code>&nbsp;表示&nbsp;<code>u<sub>i</sub></code> 和&nbsp;<code>v<sub>i</sub></code><sub>&nbsp;</sub>之间有一条无向边。同时给你一个代表查询的整数数组&nbsp;<code>queries</code>&nbsp;。</p>

<p>第 <code>j</code> 个查询的答案是满足如下条件的点对 <code>(a, b)</code> 的数目：</p>

<ul>
	<li><code>a &lt; b</code></li>
	<li><code>cnt</code>&nbsp;是与 <code>a</code>&nbsp;<strong>或者&nbsp;</strong><code>b</code>&nbsp;相连的边的数目，且 <code>cnt</code>&nbsp;<strong>严格大于&nbsp;</strong><code>queries[j]</code>&nbsp;。</li>
</ul>

<p>请你返回一个数组&nbsp;<code>answers</code>&nbsp;，其中&nbsp;<code>answers.length == queries.length</code> 且&nbsp;<code>answers[j]</code>&nbsp;是第 <code>j</code>&nbsp;个查询的答案。</p>

<p>请注意，图中可能会有 <strong>多重边</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1700-1799/1782.Count%20Pairs%20Of%20Nodes/images/1692844033-Kvxjvr-image.png" style="width: 600px; height: 338px;" /></p>

<pre>
<b>输入：</b>n = 4, edges = [[1,2],[2,4],[1,3],[2,3],[2,1]], queries = [2,3]
<b>输出：</b>[6,5]
<b>解释：</b>每个点对中，与至少一个点相连的边的数目如上图所示。
answers[0] = 6。所有的点对(a, b)中边数和都大于2，故有6个；
answers[1] = 5。所有的点对(a, b)中除了(3,4)边数等于3，其它点对边数和都大于3，故有5个。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>n = 5, edges = [[1,5],[1,5],[3,4],[2,5],[1,3],[5,1],[2,3],[2,5]], queries = [1,2,3,4,5]
<b>输出：</b>[10,10,9,8,6]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= edges.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= u<sub>i</sub>, v<sub>i</sub> &lt;= n</code></li>
	<li><code>u<sub>i </sub>!= v<sub>i</sub></code></li>
	<li><code>1 &lt;= queries.length &lt;= 20</code></li>
	<li><code>0 &lt;= queries[j] &lt; edges.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 排序 + 二分查找

根据题目，我们可以知道，与点对 $(a, b)$ 相连的边数等于“与 $a$ 相连的边数”加上“与 $b$ 相连的边数”，再减去同时与 $a$ 和 $b$ 相连的边数。

因此，我们可以先用数组 $cnt$ 统计与每个点相连的边数，用哈希表 $g$ 统计每个点对的数量。

然后，对于每个查询 $q$，我们可以枚举 $a$，对于每个 $a$，我们可以通过二分查找找到第一个满足 $cnt[a] + cnt[b] > q$ 的 $b$，先将数量累加到当前查询的答案中，然后减去一部分重复的边。

时间复杂度 $O(q \times (n \times \log n + m))$，空间复杂度 $O(n + m)$。其中 $n$ 和 $m$ 分别是点数和边数，而 $q$ 是查询数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countPairs(
        self, n: int, edges: List[List[int]], queries: List[int]
    ) -> List[int]:
        cnt = [0] * n
        g = defaultdict(int)
        for a, b in edges:
            a, b = a - 1, b - 1
            a, b = min(a, b), max(a, b)
            cnt[a] += 1
            cnt[b] += 1
            g[(a, b)] += 1

        s = sorted(cnt)
        ans = [0] * len(queries)
        for i, t in enumerate(queries):
            for j, x in enumerate(s):
                k = bisect_right(s, t - x, lo=j + 1)
                ans[i] += n - k
            for (a, b), v in g.items():
                if cnt[a] + cnt[b] > t and cnt[a] + cnt[b] - v <= t:
                    ans[i] -= 1
        return ans
```

#### Java

```java
class Solution {
    public int[] countPairs(int n, int[][] edges, int[] queries) {
        int[] cnt = new int[n];
        Map<Integer, Integer> g = new HashMap<>();
        for (var e : edges) {
            int a = e[0] - 1, b = e[1] - 1;
            ++cnt[a];
            ++cnt[b];
            int k = Math.min(a, b) * n + Math.max(a, b);
            g.merge(k, 1, Integer::sum);
        }
        int[] s = cnt.clone();
        Arrays.sort(s);
        int[] ans = new int[queries.length];
        for (int i = 0; i < queries.length; ++i) {
            int t = queries[i];
            for (int j = 0; j < n; ++j) {
                int x = s[j];
                int k = search(s, t - x, j + 1);
                ans[i] += n - k;
            }
            for (var e : g.entrySet()) {
                int a = e.getKey() / n, b = e.getKey() % n;
                int v = e.getValue();
                if (cnt[a] + cnt[b] > t && cnt[a] + cnt[b] - v <= t) {
                    --ans[i];
                }
            }
        }
        return ans;
    }

    private int search(int[] arr, int x, int i) {
        int left = i, right = arr.length;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (arr[mid] > x) {
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
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> cnt(n);
        unordered_map<int, int> g;
        for (auto& e : edges) {
            int a = e[0] - 1, b = e[1] - 1;
            ++cnt[a];
            ++cnt[b];
            int k = min(a, b) * n + max(a, b);
            ++g[k];
        }
        vector<int> s = cnt;
        sort(s.begin(), s.end());
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            int t = queries[i];
            for (int j = 0; j < n; ++j) {
                int x = s[j];
                int k = upper_bound(s.begin() + j + 1, s.end(), t - x) - s.begin();
                ans[i] += n - k;
            }
            for (auto& [k, v] : g) {
                int a = k / n, b = k % n;
                if (cnt[a] + cnt[b] > t && cnt[a] + cnt[b] - v <= t) {
                    --ans[i];
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func countPairs(n int, edges [][]int, queries []int) []int {
	cnt := make([]int, n)
	g := map[int]int{}
	for _, e := range edges {
		a, b := e[0]-1, e[1]-1
		cnt[a]++
		cnt[b]++
		if a > b {
			a, b = b, a
		}
		g[a*n+b]++
	}
	s := make([]int, n)
	copy(s, cnt)
	sort.Ints(s)
	ans := make([]int, len(queries))
	for i, t := range queries {
		for j, x := range s {
			k := sort.Search(n, func(h int) bool { return s[h] > t-x && h > j })
			ans[i] += n - k
		}
		for k, v := range g {
			a, b := k/n, k%n
			if cnt[a]+cnt[b] > t && cnt[a]+cnt[b]-v <= t {
				ans[i]--
			}
		}
	}
	return ans
}
```

#### TypeScript

```ts
function countPairs(n: number, edges: number[][], queries: number[]): number[] {
    const cnt: number[] = new Array(n).fill(0);
    const g: Map<number, number> = new Map();
    for (const [a, b] of edges) {
        ++cnt[a - 1];
        ++cnt[b - 1];
        const k = Math.min(a - 1, b - 1) * n + Math.max(a - 1, b - 1);
        g.set(k, (g.get(k) || 0) + 1);
    }
    const s = cnt.slice().sort((a, b) => a - b);
    const search = (nums: number[], x: number, l: number): number => {
        let r = nums.length;
        while (l < r) {
            const mid = (l + r) >> 1;
            if (nums[mid] > x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };
    const ans: number[] = [];
    for (const t of queries) {
        let res = 0;
        for (let j = 0; j < s.length; ++j) {
            const k = search(s, t - s[j], j + 1);
            res += n - k;
        }
        for (const [k, v] of g) {
            const a = Math.floor(k / n);
            const b = k % n;
            if (cnt[a] + cnt[b] > t && cnt[a] + cnt[b] - v <= t) {
                --res;
            }
        }
        ans.push(res);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1783. 大满贯数量 🔒](https://leetcode.cn/problems/grand-slam-titles){#1783}

{{< tabs "1783" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    player_id,
    player_name,
    SUM(
        (
            CASE
                WHEN Wimbledon = player_id THEN 1
                ELSE 0
            END
        ) + (
            CASE
                WHEN Fr_open = player_id THEN 1
                ELSE 0
            END
        ) + (
            CASE
                WHEN US_open = player_id THEN 1
                ELSE 0
            END
        ) + (
            CASE
                WHEN Au_open = player_id THEN 1
                ELSE 0
            END
        )
    ) AS grand_slams_count
FROM
    Championships
    CROSS JOIN Players
GROUP BY player_id
HAVING grand_slams_count > 0;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Players</code></p>

<pre>
+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| player_id      | int     |
| player_name    | varchar |
+----------------+---------+
player_id 是这个表的主键（具有唯一值的列）
这个表的每一行给出一个网球运动员的 ID 和 姓名
</pre>

<p>&nbsp;</p>

<p>表：<code>Championships</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| year          | int     |
| Wimbledon     | int     |
| Fr_open       | int     |
| US_open       | int     |
| Au_open       | int     |
+---------------+---------+
year 是这个表的主键（具有唯一值的列）
该表的每一行都包含在每场大满贯网球比赛中赢得比赛的球员的 ID
</pre>

<p>&nbsp;</p>

<p>编写解决方案，找出每一个球员赢得大满贯比赛的次数。结果不包含没有赢得比赛的球员的ID 。</p>

<p>结果集 <strong>无顺序要求</strong> 。</p>

<p>结果的格式，如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入：</strong>
Players 表：
+-----------+-------------+
| player_id | player_name |
+-----------+-------------+
| 1         | Nadal       |
| 2         | Federer     |
| 3         | Novak       |
+-----------+-------------+
Championships 表：
+------+-----------+---------+---------+---------+
| year | Wimbledon | Fr_open | US_open | Au_open |
+------+-----------+---------+---------+---------+
| 2018 | 1         | 1       | 1       | 1       |
| 2019 | 1         | 1       | 2       | 2       |
| 2020 | 2         | 1       | 2       | 2       |
+------+-----------+---------+---------+---------+
<strong>输出：</strong>
+-----------+-------------+-------------------+
| player_id | player_name | grand_slams_count |
+-----------+-------------+-------------------+
| 2         | Federer     | 5                 |
| 1         | Nadal       | 7                 |
+-----------+-------------+-------------------+
<strong>解释：</strong>
Player 1 (Nadal) 获得了 7 次大满贯：其中温网 2 次(2018, 2019), 法国公开赛 3 次 (2018, 2019, 2020), 美国公开赛 1 次 (2018)以及澳网公开赛 1 次 (2018) 。
Player 2 (Federer) 获得了 5 次大满贯：其中温网 1 次 (2020), 美国公开赛 2 次 (2019, 2020) 以及澳网公开赛 2 次 (2019, 2020) 。
Player 3 (Novak)  没有赢得，因此不包含在结果集中。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：合并 + 等值连接 + 分组

我们可以使用 `UNION ALL`，将所有赢得大满贯比赛的球员 ID 合并到一张表 `T` 中，然后使用等值连接 `JOIN`，将 `T` 表与 `Players` 表按照 `player_id` 进行连接，最后使用 `GROUP BY` 和 `COUNT` 统计每个球员赢得大满贯比赛的次数。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT Wimbledon AS player_id
        FROM Championships
        UNION ALL
        SELECT Fr_open AS player_id
        FROM Championships
        UNION ALL
        SELECT US_open AS player_id
        FROM Championships
        UNION ALL
        SELECT Au_open AS player_id
        FROM Championships
    )
SELECT player_id, player_name, COUNT(1) AS grand_slams_count
FROM
    T
    JOIN Players USING (player_id)
GROUP BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    player_id,
    player_name,
    SUM(
        (
            CASE
                WHEN Wimbledon = player_id THEN 1
                ELSE 0
            END
        ) + (
            CASE
                WHEN Fr_open = player_id THEN 1
                ELSE 0
            END
        ) + (
            CASE
                WHEN US_open = player_id THEN 1
                ELSE 0
            END
        ) + (
            CASE
                WHEN Au_open = player_id THEN 1
                ELSE 0
            END
        )
    ) AS grand_slams_count
FROM
    Championships
    CROSS JOIN Players
GROUP BY player_id
HAVING grand_slams_count > 0;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1784. 检查二进制字符串字段](https://leetcode.cn/problems/check-if-binary-string-has-at-most-one-segment-of-ones){#1784}

{{< tabs "1784" >}}

{{% tab "python" %}}
```python
class Solution:
    def checkOnesSegment(self, s: str) -> bool:
        return '01' not in s
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean checkOnesSegment(String s) {
        return !s.contains("01");
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool checkOnesSegment(string s) {
        return s.find("01") == -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func checkOnesSegment(s string) bool {
	return !strings.Contains(s, "01")
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function checkOnesSegment(s: string): boolean {
    return !s.includes('01');
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn check_ones_segment(s: String) -> bool {
        !s.contains("01")
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个二进制字符串 <code>s</code> ，该字符串 <strong>不含前导零</strong> 。</p>

<p>如果 <code>s</code> 包含 <strong>零个或一个由连续的 <code>'1'</code> 组成的字段</strong> ，返回 <code>true</code>​​​ 。否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "1001"
<strong>输出：</strong>false
<strong>解释：</strong>由连续若干个&nbsp;<code>'1'</code> 组成的字段数量为 2，返回 false
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "110"
<strong>输出：</strong>true</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s[i]</code>​​​​ 为 <code>'0'</code> 或 <code>'1'</code></li>
	<li><code>s[0]</code> 为 <code>'1'</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：0 后面不能有 1

注意到字符串 $s$ 不含前导零，说明 $s$ 以 '1' 开头。

若字符串 $s$ 存在 "01" 串，那么 $s$ 就是形如 "1...01..." 的字符串，此时 $s$ 出现了至少两个连续的 '1' 片段，不满足题意，返回 `false`。

若字符串 $s$ 不存在 "01" 串，那么 $s$ 只能是形如 "1..1000..." 的字符串，此时 $s$ 只有一个连续的 '1' 片段，满足题意，返回 `true`。

因此，只需要判断字符串 $s$ 是否存在 "01" 串即可。

时间复杂度 $O(n)$。其中 $n$ 为字符串 $s$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def checkOnesSegment(self, s: str) -> bool:
        return '01' not in s
```

#### Java

```java
class Solution {
    public boolean checkOnesSegment(String s) {
        return !s.contains("01");
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool checkOnesSegment(string s) {
        return s.find("01") == -1;
    }
};
```

#### Go

```go
func checkOnesSegment(s string) bool {
	return !strings.Contains(s, "01")
}
```

#### TypeScript

```ts
function checkOnesSegment(s: string): boolean {
    let pre = s[0];
    for (const c of s) {
        if (pre !== c && c === '1') {
            return false;
        }
        pre = c;
    }
    return true;
}
```

#### Rust

```rust
impl Solution {
    pub fn check_ones_segment(s: String) -> bool {
        !s.contains("01")
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### TypeScript

```ts
function checkOnesSegment(s: string): boolean {
    return !s.includes('01');
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1785. 构成特定和需要添加的最少元素](https://leetcode.cn/problems/minimum-elements-to-add-to-form-a-given-sum){#1785}

{{< tabs "1785" >}}

{{% tab "python" %}}
```python
class Solution:
    def minElements(self, nums: List[int], limit: int, goal: int) -> int:
        d = abs(sum(nums) - goal)
        return (d + limit - 1) // limit
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minElements(int[] nums, int limit, int goal) {
        // long s = Arrays.stream(nums).asLongStream().sum();
        long s = 0;
        for (int v : nums) {
            s += v;
        }
        long d = Math.abs(s - goal);
        return (int) ((d + limit - 1) / limit);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long s = accumulate(nums.begin(), nums.end(), 0ll);
        long long d = abs(s - goal);
        return (d + limit - 1) / limit;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minElements(nums []int, limit int, goal int) int {
	s := 0
	for _, v := range nums {
		s += v
	}
	d := abs(s - goal)
	return (d + limit - 1) / limit
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
function minElements(nums: number[], limit: number, goal: number): number {
    const sum = nums.reduce((r, v) => r + v, 0);
    const diff = Math.abs(goal - sum);
    return Math.floor((diff + limit - 1) / limit);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn min_elements(nums: Vec<i32>, limit: i32, goal: i32) -> i32 {
        let limit = limit as i64;
        let goal = goal as i64;
        let mut sum = 0;
        for &num in nums.iter() {
            sum += num as i64;
        }
        let diff = (goal - sum).abs();
        ((diff + limit - 1) / limit) as i32
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int minElements(int* nums, int numsSize, int limit, int goal) {
    long long sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    long long diff = labs(goal - sum);
    return (diff + limit - 1) / limit;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code> ，和两个整数 <code>limit</code> 与 <code>goal</code> 。数组 <code>nums</code> 有一条重要属性：<code>abs(nums[i]) <= limit</code> 。</p>

<p>返回使数组元素总和等于 <code>goal</code> 所需要向数组中添加的 <strong>最少元素数量</strong> ，添加元素 <strong>不应改变</strong> 数组中 <code>abs(nums[i]) <= limit</code> 这一属性。</p>

<p>注意，如果 <code>x >= 0</code> ，那么 <code>abs(x)</code> 等于 <code>x</code> ；否则，等于 <code>-x</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,-1,1], limit = 3, goal = -4
<strong>输出：</strong>2
<strong>解释：</strong>可以将 -2 和 -3 添加到数组中，数组的元素总和变为 1 - 1 + 1 - 2 - 3 = -4 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,-10,9,1], limit = 100, goal = 0
<strong>输出：</strong>1
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 10<sup>5</sup></code></li>
	<li><code>1 <= limit <= 10<sup>6</sup></code></li>
	<li><code>-limit <= nums[i] <= limit</code></li>
	<li><code>-10<sup>9</sup> <= goal <= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

我们先计算数组元素总和 $s$，然后计算 $s$ 与 $goal$ 的差值 $d$。

那么需要添加的元素数量为 $d$ 的绝对值除以 $limit$ 向上取整，即 $\lceil \frac{|d|}{limit} \rceil$。

注意，本题中数组元素的数据范围为 $[-10^6, 10^6]$，元素个数最大为 $10^5$，总和 $s$ 以及差值 $d$ 可能会超过 $32$ 位整数的表示范围，因此需要使用 $64$ 位整数。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minElements(self, nums: List[int], limit: int, goal: int) -> int:
        d = abs(sum(nums) - goal)
        return (d + limit - 1) // limit
```

#### Java

```java
class Solution {
    public int minElements(int[] nums, int limit, int goal) {
        // long s = Arrays.stream(nums).asLongStream().sum();
        long s = 0;
        for (int v : nums) {
            s += v;
        }
        long d = Math.abs(s - goal);
        return (int) ((d + limit - 1) / limit);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long s = accumulate(nums.begin(), nums.end(), 0ll);
        long long d = abs(s - goal);
        return (d + limit - 1) / limit;
    }
};
```

#### Go

```go
func minElements(nums []int, limit int, goal int) int {
	s := 0
	for _, v := range nums {
		s += v
	}
	d := abs(s - goal)
	return (d + limit - 1) / limit
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
function minElements(nums: number[], limit: number, goal: number): number {
    const sum = nums.reduce((r, v) => r + v, 0);
    const diff = Math.abs(goal - sum);
    return Math.floor((diff + limit - 1) / limit);
}
```

#### Rust

```rust
impl Solution {
    pub fn min_elements(nums: Vec<i32>, limit: i32, goal: i32) -> i32 {
        let limit = limit as i64;
        let goal = goal as i64;
        let mut sum = 0;
        for &num in nums.iter() {
            sum += num as i64;
        }
        let diff = (goal - sum).abs();
        ((diff + limit - 1) / limit) as i32
    }
}
```

#### C

```c
int minElements(int* nums, int numsSize, int limit, int goal) {
    long long sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    long long diff = labs(goal - sum);
    return (diff + limit - 1) / limit;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1786. 从第一个节点出发到最后一个节点的受限路径数](https://leetcode.cn/problems/number-of-restricted-paths-from-first-to-last-node){#1786}

{{< tabs "1786" >}}

{{% tab "python" %}}
```python
class Solution:
    def countRestrictedPaths(self, n: int, edges: List[List[int]]) -> int:
        g = defaultdict(list)
        for u, v, w in edges:
            g[u].append((v, w))
            g[v].append((u, w))
        dist = [inf] * (n + 1)
        dist[n] = 0
        q = [(0, n)]
        mod = 10**9 + 7
        while q:
            _, u = heappop(q)
            for v, w in g[u]:
                if dist[v] > dist[u] + w:
                    dist[v] = dist[u] + w
                    heappush(q, (dist[v], v))
        arr = list(range(1, n + 1))
        arr.sort(key=lambda i: dist[i])
        f = [0] * (n + 1)
        f[n] = 1
        for i in arr:
            for j, _ in g[i]:
                if dist[i] > dist[j]:
                    f[i] = (f[i] + f[j]) % mod
        return f[1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private static final int INF = Integer.MAX_VALUE;
    private static final int MOD = (int) 1e9 + 7;

    public int countRestrictedPaths(int n, int[][] edges) {
        List<int[]>[] g = new List[n + 1];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (int[] e : edges) {
            int u = e[0], v = e[1], w = e[2];
            g[u].add(new int[] {v, w});
            g[v].add(new int[] {u, w});
        }
        PriorityQueue<int[]> q = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        q.offer(new int[] {0, n});
        int[] dist = new int[n + 1];
        Arrays.fill(dist, INF);
        dist[n] = 0;
        while (!q.isEmpty()) {
            int[] p = q.poll();
            int u = p[1];
            for (int[] ne : g[u]) {
                int v = ne[0], w = ne[1];
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    q.offer(new int[] {dist[v], v});
                }
            }
        }
        int[] f = new int[n + 1];
        f[n] = 1;
        Integer[] arr = new Integer[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = i + 1;
        }
        Arrays.sort(arr, (i, j) -> dist[i] - dist[j]);
        for (int i : arr) {
            for (int[] ne : g[i]) {
                int j = ne[0];
                if (dist[i] > dist[j]) {
                    f[i] = (f[i] + f[j]) % MOD;
                }
            }
        }
        return f[1];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
using pii = pair<int, int>;

class Solution {
public:
    const int inf = INT_MAX;
    const int mod = 1e9 + 7;
    vector<vector<pii>> g;
    vector<int> dist;
    vector<int> f;
    int n;

    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        this->n = n;
        g.resize(n + 1);
        dist.assign(n + 1, inf);
        f.assign(n + 1, -1);
        dist[n] = 0;
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }
        priority_queue<pii, vector<pii>, greater<pii>> q;
        q.emplace(0, n);
        while (!q.empty()) {
            auto [_, u] = q.top();
            q.pop();
            for (auto [v, w] : g[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    q.emplace(dist[v], v);
                }
            }
        }
        return dfs(1);
    }

    int dfs(int i) {
        if (f[i] != -1) return f[i];
        if (i == n) return 1;
        int ans = 0;
        for (auto [j, _] : g[i]) {
            if (dist[i] > dist[j]) {
                ans = (ans + dfs(j)) % mod;
            }
        }
        f[i] = ans;
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
const inf = math.MaxInt32
const mod = 1e9 + 7

type pair struct {
	first  int
	second int
}

var _ heap.Interface = (*pairs)(nil)

type pairs []pair

func (a pairs) Len() int { return len(a) }
func (a pairs) Less(i int, j int) bool {
	return a[i].first < a[j].first || a[i].first == a[j].first && a[i].second < a[j].second
}
func (a pairs) Swap(i int, j int) { a[i], a[j] = a[j], a[i] }
func (a *pairs) Push(x any)       { *a = append(*a, x.(pair)) }
func (a *pairs) Pop() any         { l := len(*a); t := (*a)[l-1]; *a = (*a)[:l-1]; return t }

func countRestrictedPaths(n int, edges [][]int) int {
	g := make([]pairs, n+1)
	for _, e := range edges {
		u, v, w := e[0], e[1], e[2]
		g[u] = append(g[u], pair{v, w})
		g[v] = append(g[v], pair{u, w})
	}
	dist := make([]int, n+1)
	f := make([]int, n+1)
	for i := range dist {
		dist[i] = inf
		f[i] = -1
	}
	dist[n] = 0
	h := make(pairs, 0)
	heap.Push(&h, pair{0, n})
	for len(h) > 0 {
		u := heap.Pop(&h).(pair).second
		for _, ne := range g[u] {
			v, w := ne.first, ne.second
			if dist[v] > dist[u]+w {
				dist[v] = dist[u] + w
				heap.Push(&h, pair{dist[v], v})
			}
		}
	}
	var dfs func(int) int
	dfs = func(i int) int {
		if f[i] != -1 {
			return f[i]
		}
		if i == n {
			return 1
		}
		ans := 0
		for _, ne := range g[i] {
			j := ne.first
			if dist[i] > dist[j] {
				ans = (ans + dfs(j)) % mod
			}
		}
		f[i] = ans
		return ans
	}
	return dfs(1)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>现有一个加权无向连通图。给你一个正整数 <code>n</code> ，表示图中有 <code>n</code> 个节点，并按从 <code>1</code> 到 <code>n</code> 给节点编号；另给你一个数组 <code>edges</code> ，其中每个 <code>edges[i] = [u<sub>i</sub>, v<sub>i</sub>, weight<sub>i</sub>]</code> 表示存在一条位于节点 <code>u<sub>i</sub></code> 和 <code>v<sub>i</sub></code> 之间的边，这条边的权重为 <code>weight<sub>i</sub></code> 。</p>

<p>从节点 <code>start</code> 出发到节点 <code>end</code> 的路径是一个形如 <code>[z<sub>0</sub>, z<sub>1</sub>,<sub> </sub>z<sub>2</sub>, ..., z<sub>k</sub>]</code> 的节点序列，满足 <code>z<sub>0 </sub>= start</code> 、<code>z<sub>k</sub> = end</code> 且在所有符合 <code>0 <= i <= k-1</code> 的节点 <code>z<sub>i</sub></code> 和 <code>z<sub>i+1</sub></code> 之间存在一条边。</p>

<p>路径的距离定义为这条路径上所有边的权重总和。用 <code>distanceToLastNode(x)</code> 表示节点 <code>n</code> 和 <code>x</code> 之间路径的最短距离。<strong>受限路径</strong> 为满足 <code>distanceToLastNode(z<sub>i</sub>) > distanceToLastNode(z<sub>i+1</sub>)</code> 的一条路径，其中 <code>0 <= i <= k-1</code> 。</p>

<p>返回从节点 <code>1</code> 出发到节点 <code>n</code> 的 <strong>受限路径数</strong> 。由于数字可能很大，请返回对 <code>10<sup>9</sup> + 7</code> <strong>取余</strong> 的结果。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1700-1799/1786.Number%20of%20Restricted%20Paths%20From%20First%20to%20Last%20Node/images/restricted_paths_ex1.png" style="width: 351px; height: 341px;" />
<pre>
<strong>输入：</strong>n = 5, edges = [[1,2,3],[1,3,3],[2,3,1],[1,4,2],[5,2,2],[3,5,1],[5,4,10]]
<strong>输出：</strong>3
<strong>解释：</strong>每个圆包含黑色的节点编号和蓝色的 distanceToLastNode 值。三条受限路径分别是：
1) 1 --> 2 --> 5
2) 1 --> 2 --> 3 --> 5
3) 1 --> 3 --> 5
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1700-1799/1786.Number%20of%20Restricted%20Paths%20From%20First%20to%20Last%20Node/images/restricted_paths_ex22.png" style="width: 356px; height: 401px;" />
<pre>
<strong>输入：</strong>n = 7, edges = [[1,3,1],[4,1,2],[7,3,4],[2,5,3],[5,6,1],[6,7,2],[7,5,3],[2,6,4]]
<strong>输出：</strong>1
<strong>解释：</strong>每个圆包含黑色的节点编号和蓝色的 distanceToLastNode 值。唯一一条受限路径是：1 --> 3 --> 7 。</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= n <= 2 * 10<sup>4</sup></code></li>
	<li><code>n - 1 <= edges.length <= 4 * 10<sup>4</sup></code></li>
	<li><code>edges[i].length == 3</code></li>
	<li><code>1 <= u<sub>i</sub>, v<sub>i</sub> <= n</code></li>
	<li><code>u<sub>i </sub>!= v<sub>i</sub></code></li>
	<li><code>1 <= weight<sub>i</sub> <= 10<sup>5</sup></code></li>
	<li>任意两个节点之间至多存在一条边</li>
	<li>任意两个节点之间至少存在一条路径</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：堆优化 Dijkstra + 记忆化搜索

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countRestrictedPaths(self, n: int, edges: List[List[int]]) -> int:
        @cache
        def dfs(i):
            if i == n:
                return 1
            ans = 0
            for j, _ in g[i]:
                if dist[i] > dist[j]:
                    ans = (ans + dfs(j)) % mod
            return ans

        g = defaultdict(list)
        for u, v, w in edges:
            g[u].append((v, w))
            g[v].append((u, w))
        q = [(0, n)]
        dist = [inf] * (n + 1)
        dist[n] = 0
        mod = 10**9 + 7
        while q:
            _, u = heappop(q)
            for v, w in g[u]:
                if dist[v] > dist[u] + w:
                    dist[v] = dist[u] + w
                    heappush(q, (dist[v], v))
        return dfs(1)
```

#### Java

```java
class Solution {
    private static final int INF = Integer.MAX_VALUE;
    private static final int MOD = (int) 1e9 + 7;
    private List<int[]>[] g;
    private int[] dist;
    private int[] f;
    private int n;

    public int countRestrictedPaths(int n, int[][] edges) {
        this.n = n;
        g = new List[n + 1];
        for (int i = 0; i < g.length; ++i) {
            g[i] = new ArrayList<>();
        }
        for (int[] e : edges) {
            int u = e[0], v = e[1], w = e[2];
            g[u].add(new int[] {v, w});
            g[v].add(new int[] {u, w});
        }
        PriorityQueue<int[]> q = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        q.offer(new int[] {0, n});
        dist = new int[n + 1];
        f = new int[n + 1];
        Arrays.fill(dist, INF);
        Arrays.fill(f, -1);
        dist[n] = 0;
        while (!q.isEmpty()) {
            int[] p = q.poll();
            int u = p[1];
            for (int[] ne : g[u]) {
                int v = ne[0], w = ne[1];
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    q.offer(new int[] {dist[v], v});
                }
            }
        }
        return dfs(1);
    }

    private int dfs(int i) {
        if (f[i] != -1) {
            return f[i];
        }
        if (i == n) {
            return 1;
        }
        int ans = 0;
        for (int[] ne : g[i]) {
            int j = ne[0];
            if (dist[i] > dist[j]) {
                ans = (ans + dfs(j)) % MOD;
            }
        }
        f[i] = ans;
        return ans;
    }
}
```

#### C++

```cpp
using pii = pair<int, int>;

class Solution {
public:
    const int inf = INT_MAX;
    const int mod = 1e9 + 7;
    vector<vector<pii>> g;
    vector<int> dist;
    vector<int> f;
    int n;

    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        this->n = n;
        g.resize(n + 1);
        dist.assign(n + 1, inf);
        f.assign(n + 1, -1);
        dist[n] = 0;
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }
        priority_queue<pii, vector<pii>, greater<pii>> q;
        q.emplace(0, n);
        while (!q.empty()) {
            auto [_, u] = q.top();
            q.pop();
            for (auto [v, w] : g[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    q.emplace(dist[v], v);
                }
            }
        }
        return dfs(1);
    }

    int dfs(int i) {
        if (f[i] != -1) return f[i];
        if (i == n) return 1;
        int ans = 0;
        for (auto [j, _] : g[i]) {
            if (dist[i] > dist[j]) {
                ans = (ans + dfs(j)) % mod;
            }
        }
        f[i] = ans;
        return ans;
    }
};
```

#### Go

```go
const inf = math.MaxInt32
const mod = 1e9 + 7

type pair struct {
	first  int
	second int
}

var _ heap.Interface = (*pairs)(nil)

type pairs []pair

func (a pairs) Len() int { return len(a) }
func (a pairs) Less(i int, j int) bool {
	return a[i].first < a[j].first || a[i].first == a[j].first && a[i].second < a[j].second
}
func (a pairs) Swap(i int, j int) { a[i], a[j] = a[j], a[i] }
func (a *pairs) Push(x any)       { *a = append(*a, x.(pair)) }
func (a *pairs) Pop() any         { l := len(*a); t := (*a)[l-1]; *a = (*a)[:l-1]; return t }

func countRestrictedPaths(n int, edges [][]int) int {
	g := make([]pairs, n+1)
	for _, e := range edges {
		u, v, w := e[0], e[1], e[2]
		g[u] = append(g[u], pair{v, w})
		g[v] = append(g[v], pair{u, w})
	}
	dist := make([]int, n+1)
	f := make([]int, n+1)
	for i := range dist {
		dist[i] = inf
		f[i] = -1
	}
	dist[n] = 0
	h := make(pairs, 0)
	heap.Push(&h, pair{0, n})
	for len(h) > 0 {
		u := heap.Pop(&h).(pair).second
		for _, ne := range g[u] {
			v, w := ne.first, ne.second
			if dist[v] > dist[u]+w {
				dist[v] = dist[u] + w
				heap.Push(&h, pair{dist[v], v})
			}
		}
	}
	var dfs func(int) int
	dfs = func(i int) int {
		if f[i] != -1 {
			return f[i]
		}
		if i == n {
			return 1
		}
		ans := 0
		for _, ne := range g[i] {
			j := ne.first
			if dist[i] > dist[j] {
				ans = (ans + dfs(j)) % mod
			}
		}
		f[i] = ans
		return ans
	}
	return dfs(1)
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
    def countRestrictedPaths(self, n: int, edges: List[List[int]]) -> int:
        g = defaultdict(list)
        for u, v, w in edges:
            g[u].append((v, w))
            g[v].append((u, w))
        dist = [inf] * (n + 1)
        dist[n] = 0
        q = [(0, n)]
        mod = 10**9 + 7
        while q:
            _, u = heappop(q)
            for v, w in g[u]:
                if dist[v] > dist[u] + w:
                    dist[v] = dist[u] + w
                    heappush(q, (dist[v], v))
        arr = list(range(1, n + 1))
        arr.sort(key=lambda i: dist[i])
        f = [0] * (n + 1)
        f[n] = 1
        for i in arr:
            for j, _ in g[i]:
                if dist[i] > dist[j]:
                    f[i] = (f[i] + f[j]) % mod
        return f[1]
```

#### Java

```java
class Solution {
    private static final int INF = Integer.MAX_VALUE;
    private static final int MOD = (int) 1e9 + 7;

    public int countRestrictedPaths(int n, int[][] edges) {
        List<int[]>[] g = new List[n + 1];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (int[] e : edges) {
            int u = e[0], v = e[1], w = e[2];
            g[u].add(new int[] {v, w});
            g[v].add(new int[] {u, w});
        }
        PriorityQueue<int[]> q = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        q.offer(new int[] {0, n});
        int[] dist = new int[n + 1];
        Arrays.fill(dist, INF);
        dist[n] = 0;
        while (!q.isEmpty()) {
            int[] p = q.poll();
            int u = p[1];
            for (int[] ne : g[u]) {
                int v = ne[0], w = ne[1];
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    q.offer(new int[] {dist[v], v});
                }
            }
        }
        int[] f = new int[n + 1];
        f[n] = 1;
        Integer[] arr = new Integer[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = i + 1;
        }
        Arrays.sort(arr, (i, j) -> dist[i] - dist[j]);
        for (int i : arr) {
            for (int[] ne : g[i]) {
                int j = ne[0];
                if (dist[i] > dist[j]) {
                    f[i] = (f[i] + f[j]) % MOD;
                }
            }
        }
        return f[1];
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1787. 使所有区间的异或结果为零](https://leetcode.cn/problems/make-the-xor-of-all-segments-equal-to-zero){#1787}

{{< tabs "1787" >}}

{{% tab "python" %}}
```python
class Solution:
    def minChanges(self, nums: List[int], k: int) -> int:
        n = 1 << 10
        cnt = [Counter() for _ in range(k)]
        size = [0] * k
        for i, v in enumerate(nums):
            cnt[i % k][v] += 1
            size[i % k] += 1
        f = [inf] * n
        f[0] = 0
        for i in range(k):
            g = [min(f) + size[i]] * n
            for j in range(n):
                for v, c in cnt[i].items():
                    g[j] = min(g[j], f[j ^ v] + size[i] - c)
            f = g
        return f[0]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minChanges(int[] nums, int k) {
        int n = 1 << 10;
        Map<Integer, Integer>[] cnt = new Map[k];
        Arrays.setAll(cnt, i -> new HashMap<>());
        int[] size = new int[k];
        for (int i = 0; i < nums.length; ++i) {
            int j = i % k;
            cnt[j].merge(nums[i], 1, Integer::sum);
            size[j]++;
        }
        int[] f = new int[n];
        final int inf = 1 << 30;
        Arrays.fill(f, inf);
        f[0] = 0;
        for (int i = 0; i < k; ++i) {
            int[] g = new int[n];
            Arrays.fill(g, min(f) + size[i]);
            for (int j = 0; j < n; ++j) {
                for (var e : cnt[i].entrySet()) {
                    int v = e.getKey(), c = e.getValue();
                    g[j] = Math.min(g[j], f[j ^ v] + size[i] - c);
                }
            }
            f = g;
        }
        return f[0];
    }

    private int min(int[] arr) {
        int mi = arr[0];
        for (int v : arr) {
            mi = Math.min(mi, v);
        }
        return mi;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = 1 << 10;
        unordered_map<int, int> cnt[k];
        vector<int> size(k);
        for (int i = 0; i < nums.size(); ++i) {
            cnt[i % k][nums[i]]++;
            size[i % k]++;
        }
        vector<int> f(n, 1 << 30);
        f[0] = 0;
        for (int i = 0; i < k; ++i) {
            int mi = *min_element(f.begin(), f.end());
            vector<int> g(n, mi + size[i]);
            for (int j = 0; j < n; ++j) {
                for (auto& [v, c] : cnt[i]) {
                    g[j] = min(g[j], f[j ^ v] + size[i] - c);
                }
            }
            f = move(g);
        }
        return f[0];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minChanges(nums []int, k int) int {
	n := 1 << 10
	cnt := make([]map[int]int, k)
	for i := range cnt {
		cnt[i] = map[int]int{}
	}
	size := make([]int, k)
	for i, v := range nums {
		cnt[i%k][v]++
		size[i%k]++
	}
	f := make([]int, n)
	for i := 1; i < n; i++ {
		f[i] = 0x3f3f3f3f
	}
	for i, sz := range size {
		g := make([]int, n)
		x := slices.Min(f) + sz
		for i := range g {
			g[i] = x
		}
		for j := 0; j < n; j++ {
			for v, c := range cnt[i] {
				g[j] = min(g[j], f[j^v]+sz-c)
			}
		}
		f = g
	}
	return f[0]
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code>​​​ 和一个整数 <code>k</code>​​​​​ 。区间 <code>[left, right]</code>（<code>left <= right</code>）的 <strong>异或结果</strong> 是对下标位于 <code>left</code> 和 <code>right</code>（包括 <code>left</code> 和 <code>right</code> ）之间所有元素进行 <code>XOR</code> 运算的结果：<code>nums[left] XOR nums[left+1] XOR ... XOR nums[right]</code> 。</p>

<p>返回数组中 <strong>要更改的最小元素数</strong> ，以使所有长度为 <code>k</code> 的区间异或结果等于零。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,0,3,0], k = 1
<strong>输出：</strong>3
<strong>解释：</strong>将数组 [<strong>1</strong>,<strong>2</strong>,0,<strong>3</strong>,0] 修改为 [<strong>0</strong>,<strong>0</strong>,0,<strong>0</strong>,0]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,4,5,2,1,7,3,4,7], k = 3
<strong>输出：</strong>3
<strong>解释：</strong>将数组 [3,4,<strong>5</strong>,<strong>2</strong>,<strong>1</strong>,7,3,4,7] 修改为 [3,4,<strong>7</strong>,<strong>3</strong>,<strong>4</strong>,7,3,4,7]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,4,1,2,5,1,2,6], k = 3
<strong>输出：</strong>3
<strong>解释：</strong>将数组[1,2,<strong>4,</strong>1,2,<strong>5</strong>,1,2,<strong>6</strong>] 修改为 [1,2,<strong>3</strong>,1,2,<strong>3</strong>,1,2,<strong>3</strong>]</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= k <= nums.length <= 2000</code></li>
	<li><code>​​​​​​0 <= nums[i] < 2<sup>10</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

注意到数组 `nums` 在修改之后，任意长度为 $k$ 的区间异或结果都等于 $0$，那么对于任意的 $i$，都有：

$$
nums[i] \oplus nums[i+1] \oplus ... \oplus nums[i+k-1] = 0
$$

以及

$$
nums[i+1] \oplus nums[i+2] \oplus ... \oplus nums[i+k] = 0
$$

结合上面两个等式以及异或运算的性质，可以得到 $nums[i] \oplus nums[i+k] = 0$，即 $nums[i]=nums[i+k]$，我们发现，修改后的数组 `nums` 中的元素是以周期为 $k$ 的循环，对模 $k$ 同余的一组数必然只能取固定值，同时需要满足前 $k$ 个数异或结果为 $0$。

我们先对每一组 $i$ 进行计数，每一组的元素个数为 $size[i]$，每一组值为 $v$ 的元素个数为 $cnt[i][v]$。

接下来，我们可以用动态规划来求解。设 $f[i][j]$ 表示前 $i+1$ 组异或和为 $j$ 的最小修改次数。由于每一组的值只与前一组的值有关，因此我们可以用滚动数组优化空间复杂度。

重新定义 $f[j]$ 表示处理到当前组，且异或和为 $j$ 的最小修改次数。

状态转移时，有两种选择：一是将当前组的数全部都修改为同一个值，那么我们可以选择上一个代价最小的那个，加上这一组的元素个数 $size[i]$，此时的代价为 $\min{f[0..n]} + size[i]$；二是将当前组的数全部修改为当前组的某个值 $j$，枚举 $j$ 以及当前组的元素 $v$，那么前面的代价为 $f[j \oplus v]$，此时的代价为 $f[j \oplus v] + size[i] - cnt[i][v]$。取最小值即可。

最终答案为 $f[0]$。

时间复杂度 $O(2^{C}\times k + n)$。其中 $n$ 是数组 `nums` 的长度，而 $C$ 为 `nums` 中元素二进制表示的最大位数，本题中 $C=10$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minChanges(self, nums: List[int], k: int) -> int:
        n = 1 << 10
        cnt = [Counter() for _ in range(k)]
        size = [0] * k
        for i, v in enumerate(nums):
            cnt[i % k][v] += 1
            size[i % k] += 1
        f = [inf] * n
        f[0] = 0
        for i in range(k):
            g = [min(f) + size[i]] * n
            for j in range(n):
                for v, c in cnt[i].items():
                    g[j] = min(g[j], f[j ^ v] + size[i] - c)
            f = g
        return f[0]
```

#### Java

```java
class Solution {
    public int minChanges(int[] nums, int k) {
        int n = 1 << 10;
        Map<Integer, Integer>[] cnt = new Map[k];
        Arrays.setAll(cnt, i -> new HashMap<>());
        int[] size = new int[k];
        for (int i = 0; i < nums.length; ++i) {
            int j = i % k;
            cnt[j].merge(nums[i], 1, Integer::sum);
            size[j]++;
        }
        int[] f = new int[n];
        final int inf = 1 << 30;
        Arrays.fill(f, inf);
        f[0] = 0;
        for (int i = 0; i < k; ++i) {
            int[] g = new int[n];
            Arrays.fill(g, min(f) + size[i]);
            for (int j = 0; j < n; ++j) {
                for (var e : cnt[i].entrySet()) {
                    int v = e.getKey(), c = e.getValue();
                    g[j] = Math.min(g[j], f[j ^ v] + size[i] - c);
                }
            }
            f = g;
        }
        return f[0];
    }

    private int min(int[] arr) {
        int mi = arr[0];
        for (int v : arr) {
            mi = Math.min(mi, v);
        }
        return mi;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = 1 << 10;
        unordered_map<int, int> cnt[k];
        vector<int> size(k);
        for (int i = 0; i < nums.size(); ++i) {
            cnt[i % k][nums[i]]++;
            size[i % k]++;
        }
        vector<int> f(n, 1 << 30);
        f[0] = 0;
        for (int i = 0; i < k; ++i) {
            int mi = *min_element(f.begin(), f.end());
            vector<int> g(n, mi + size[i]);
            for (int j = 0; j < n; ++j) {
                for (auto& [v, c] : cnt[i]) {
                    g[j] = min(g[j], f[j ^ v] + size[i] - c);
                }
            }
            f = move(g);
        }
        return f[0];
    }
};
```

#### Go

```go
func minChanges(nums []int, k int) int {
	n := 1 << 10
	cnt := make([]map[int]int, k)
	for i := range cnt {
		cnt[i] = map[int]int{}
	}
	size := make([]int, k)
	for i, v := range nums {
		cnt[i%k][v]++
		size[i%k]++
	}
	f := make([]int, n)
	for i := 1; i < n; i++ {
		f[i] = 0x3f3f3f3f
	}
	for i, sz := range size {
		g := make([]int, n)
		x := slices.Min(f) + sz
		for i := range g {
			g[i] = x
		}
		for j := 0; j < n; j++ {
			for v, c := range cnt[i] {
				g[j] = min(g[j], f[j^v]+sz-c)
			}
		}
		f = g
	}
	return f[0]
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1788. 最大化花园的美观度 🔒](https://leetcode.cn/problems/maximize-the-beauty-of-the-garden){#1788}

{{< tabs "1788" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumBeauty(self, flowers: List[int]) -> int:
        s = [0] * (len(flowers) + 1)
        d = {}
        ans = -inf
        for i, v in enumerate(flowers):
            if v in d:
                ans = max(ans, s[i] - s[d[v] + 1] + v * 2)
            else:
                d[v] = i
            s[i + 1] = s[i] + max(v, 0)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumBeauty(int[] flowers) {
        int n = flowers.length;
        int[] s = new int[n + 1];
        Map<Integer, Integer> d = new HashMap<>();
        int ans = Integer.MIN_VALUE;
        for (int i = 0; i < n; ++i) {
            int v = flowers[i];
            if (d.containsKey(v)) {
                ans = Math.max(ans, s[i] - s[d.get(v) + 1] + v * 2);
            } else {
                d.put(v, i);
            }
            s[i + 1] = s[i] + Math.max(v, 0);
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
    int maximumBeauty(vector<int>& flowers) {
        int n = flowers.size();
        vector<int> s(n + 1);
        unordered_map<int, int> d;
        int ans = INT_MIN;
        for (int i = 0; i < n; ++i) {
            int v = flowers[i];
            if (d.count(v)) {
                ans = max(ans, s[i] - s[d[v] + 1] + v * 2);
            } else {
                d[v] = i;
            }
            s[i + 1] = s[i] + max(v, 0);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumBeauty(flowers []int) int {
	n := len(flowers)
	s := make([]int, n+1)
	d := map[int]int{}
	ans := math.MinInt32
	for i, v := range flowers {
		if j, ok := d[v]; ok {
			ans = max(ans, s[i]-s[j+1]+v*2)
		} else {
			d[v] = i
		}
		s[i+1] = s[i] + max(v, 0)
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumBeauty(flowers: number[]): number {
    const n = flowers.length;
    const s: number[] = Array(n + 1).fill(0);
    const d: Map<number, number> = new Map();
    let ans = -Infinity;
    for (let i = 0; i < n; ++i) {
        const v = flowers[i];
        if (d.has(v)) {
            ans = Math.max(ans, s[i] - s[d.get(v)! + 1] + v * 2);
        } else {
            d.set(v, i);
        }
        s[i + 1] = s[i] + Math.max(v, 0);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    pub fn maximum_beauty(flowers: Vec<i32>) -> i32 {
        let mut s = vec![0; flowers.len() + 1];
        let mut d = HashMap::new();
        let mut ans = i32::MIN;

        for (i, &v) in flowers.iter().enumerate() {
            if let Some(&j) = d.get(&v) {
                ans = ans.max(s[i] - s[j + 1] + v * 2);
            } else {
                d.insert(v, i);
            }
            s[i + 1] = s[i] + v.max(0);
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

<p>有一个花园，有&nbsp;<code>n</code>&nbsp;朵花，这些花都有一个用整数表示的美观度。这些花被种在一条线上。给定一个长度为 <code>n</code> 的整数类型数组&nbsp;<code>flowers</code>&nbsp;，每一个&nbsp;<code>flowers[i]</code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;朵花的美观度。</p>

<p>一个花园满足下列条件时，该花园是<strong>有效</strong>的。</p>

<ul>
	<li>花园中至少包含两朵花。</li>
	<li>第一朵花和最后一朵花的美观度相同。</li>
</ul>

<p>作为一个被钦定的园丁，你可以从花园中<strong>去除</strong>任意朵花（也可以不去除任意一朵）。你想要通过一种方法移除某些花朵，使得剩下的花园变得<strong>有效</strong>。花园的美观度是其中所有剩余的花朵美观度之和。</p>

<p>返回你去除了任意朵花（也可以不去除任意一朵）之后形成的<strong>有效</strong>花园中最大可能的美观度。</p>

<p>&nbsp;</p>

<p><b class="example">示例 1：</b></p>

<pre>
<strong>输入:</strong> flowers = [1,2,3,1,2]
<strong>输出:</strong> 8
<strong>解释:</strong> 你可以修整为有效花园 [2,3,1,2] 来达到总美观度 2 + 3 + 1 + 2 = 8。</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入:</strong> flowers = [100,1,1,-3,1]
<strong>输出:</strong> 3
<strong>解释:</strong> 你可以修整为有效花园 [1,1,1] 来达到总美观度 1 + 1 + 1 = 3。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入:</strong> flowers = [-1,-2,0,-1]
<strong>输出:</strong> -2
<strong>解释:</strong> 你可以修整为有效花园 [-1,-1] 来达到总美观度 -1 + -1 = -2。
</pre>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<ul>
	<li><code>2 &lt;= flowers.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= flowers[i] &lt;= 10<sup>4</sup></code></li>
	<li>去除一些花朵（可能没有）后，是有可能形成一个有效花园的。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 前缀和

我们用哈希表 $d$ 记录每个美观度第一次出现的位置，用前缀和数组 $s$ 记录当前位置之前的美观度之和。如果一个美观度 $v$ 在位置 $i$ 和 $j$ 出现过（其中 $i \lt j$），那么我们可以得到一个有效的花园 $[i+1,j]$，其美观度为 $s[i] - s[j + 1] + v \times 2$，我们用这个值更新答案。否则，我们将当前美观度所在的位置 $i$ 记录到哈希表 $d$ 中。接下来，我们更新前缀和，如果美观度 $v$ 为负数，我们将其视为 $0$。

遍历完所有的美观度之后，我们就可以得到答案。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为花朵的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumBeauty(self, flowers: List[int]) -> int:
        s = [0] * (len(flowers) + 1)
        d = {}
        ans = -inf
        for i, v in enumerate(flowers):
            if v in d:
                ans = max(ans, s[i] - s[d[v] + 1] + v * 2)
            else:
                d[v] = i
            s[i + 1] = s[i] + max(v, 0)
        return ans
```

#### Java

```java
class Solution {
    public int maximumBeauty(int[] flowers) {
        int n = flowers.length;
        int[] s = new int[n + 1];
        Map<Integer, Integer> d = new HashMap<>();
        int ans = Integer.MIN_VALUE;
        for (int i = 0; i < n; ++i) {
            int v = flowers[i];
            if (d.containsKey(v)) {
                ans = Math.max(ans, s[i] - s[d.get(v) + 1] + v * 2);
            } else {
                d.put(v, i);
            }
            s[i + 1] = s[i] + Math.max(v, 0);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumBeauty(vector<int>& flowers) {
        int n = flowers.size();
        vector<int> s(n + 1);
        unordered_map<int, int> d;
        int ans = INT_MIN;
        for (int i = 0; i < n; ++i) {
            int v = flowers[i];
            if (d.count(v)) {
                ans = max(ans, s[i] - s[d[v] + 1] + v * 2);
            } else {
                d[v] = i;
            }
            s[i + 1] = s[i] + max(v, 0);
        }
        return ans;
    }
};
```

#### Go

```go
func maximumBeauty(flowers []int) int {
	n := len(flowers)
	s := make([]int, n+1)
	d := map[int]int{}
	ans := math.MinInt32
	for i, v := range flowers {
		if j, ok := d[v]; ok {
			ans = max(ans, s[i]-s[j+1]+v*2)
		} else {
			d[v] = i
		}
		s[i+1] = s[i] + max(v, 0)
	}
	return ans
}
```

#### TypeScript

```ts
function maximumBeauty(flowers: number[]): number {
    const n = flowers.length;
    const s: number[] = Array(n + 1).fill(0);
    const d: Map<number, number> = new Map();
    let ans = -Infinity;
    for (let i = 0; i < n; ++i) {
        const v = flowers[i];
        if (d.has(v)) {
            ans = Math.max(ans, s[i] - s[d.get(v)! + 1] + v * 2);
        } else {
            d.set(v, i);
        }
        s[i + 1] = s[i] + Math.max(v, 0);
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn maximum_beauty(flowers: Vec<i32>) -> i32 {
        let mut s = vec![0; flowers.len() + 1];
        let mut d = HashMap::new();
        let mut ans = i32::MIN;

        for (i, &v) in flowers.iter().enumerate() {
            if let Some(&j) = d.get(&v) {
                ans = ans.max(s[i] - s[j + 1] + v * 2);
            } else {
                d.insert(v, i);
            }
            s[i + 1] = s[i] + v.max(0);
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

# [1789. 员工的直属部门](https://leetcode.cn/problems/primary-department-for-each-employee){#1789}

{{< tabs "1789" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT employee_id, department_id
FROM Employee
WHERE primary_flag = 'Y'
UNION
SELECT employee_id, department_id
FROM Employee
GROUP BY 1
HAVING COUNT(1) = 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Employee</code></p>

<pre>
+---------------+---------+
| Column Name   |  Type   |
+---------------+---------+
| employee_id   | int     |
| department_id | int     |
| primary_flag  | varchar |
+---------------+---------+
这张表的主键为 employee_id, department_id (具有唯一值的列的组合)
employee_id 是员工的ID
department_id 是部门的ID，表示员工与该部门有关系
primary_flag 是一个枚举类型，值分别为('Y', 'N'). 如果值为'Y',表示该部门是员工的直属部门。 如果值是'N',则否
</pre>

<p>&nbsp;</p>

<p>一个员工可以属于多个部门。当一个员工加入<strong>超过一个部门</strong>的时候，他需要决定哪个部门是他的直属部门。请注意，当员工只加入一个部门的时候，那这个部门将默认为他的直属部门，虽然表记录的值为<code>'N'</code>.</p>

<p>请编写解决方案，查出员工所属的直属部门。</p>

<p>返回结果 <strong>没有顺序要求</strong> 。</p>

<p>返回结果格式如下例子所示：</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Employee table:
+-------------+---------------+--------------+
| employee_id | department_id | primary_flag |
+-------------+---------------+--------------+
| 1           | 1             | N            |
| 2           | 1             | Y            |
| 2           | 2             | N            |
| 3           | 3             | N            |
| 4           | 2             | N            |
| 4           | 3             | Y            |
| 4           | 4             | N            |
+-------------+---------------+--------------+
<strong>输出：</strong>
+-------------+---------------+
| employee_id | department_id |
+-------------+---------------+
| 1           | 1             |
| 2           | 1             |
| 3           | 3             |
| 4           | 3             |
+-------------+---------------+
<strong>解释：</strong>
- 员工 1 的直属部门是 1
- 员工 2 的直属部门是 1
- 员工 3 的直属部门是 3
- 员工 4 的直属部门是 3</pre>

<p>&nbsp;</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：合并

我们可以查出所有已经有直属部门的员工，然后再查出所有只属于一个部门的员工，最后我们可以使用 `UNION` 合并两个结果集。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT employee_id, department_id
FROM Employee
WHERE primary_flag = 'Y'
UNION
SELECT employee_id, department_id
FROM Employee
GROUP BY 1
HAVING COUNT(1) = 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
