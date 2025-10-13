---
title: "1460_通过翻转子数组使两个数组相等"
date: 2025-10-08T18:37:18+08:00
weight: 7
tags: [二叉树, 位运算, 动态规划, 哈希函数, 哈希表, 回溯, 图, 堆（优先队列）, 字符串, 广度优先搜索, 拓扑排序, 排序, 数学, 数据库, 数组, 树, 概率与统计, 深度优先搜索, 滚动哈希, 矩阵, 组合数学, 贪心]
---

{{< markmap >}}
### [1460_通过翻转子数组使两个数组相等](#1460)
#### [数组](#1460)
#### [哈希表](#1460)
#### [排序](#1460)
### [1461_检查一个字符串是否包含所有长度为 K 的二进制子串](#1461)
#### [位运算](#1461)
#### [哈希表](#1461)
#### [字符串](#1461)
#### [哈希函数](#1461)
#### [滚动哈希](#1461)
### [1462_课程表 IV](#1462)
#### [深度优先搜索](#1462)
#### [广度优先搜索](#1462)
#### [图](#1462)
#### [拓扑排序](#1462)
### [1463_摘樱桃 II](#1463)
#### [数组](#1463)
#### [动态规划](#1463)
#### [矩阵](#1463)
### [1464_数组中两元素的最大乘积](#1464)
#### [数组](#1464)
#### [排序](#1464)
#### [堆（优先队列）](#1464)
### [1465_切割后面积最大的蛋糕](#1465)
#### [贪心](#1465)
#### [数组](#1465)
#### [排序](#1465)
### [1466_重新规划路线](#1466)
#### [深度优先搜索](#1466)
#### [广度优先搜索](#1466)
#### [图](#1466)
### [1467_两个盒子中球的颜色数相同的概率](#1467)
#### [数组](#1467)
#### [数学](#1467)
#### [动态规划](#1467)
#### [回溯](#1467)
#### [组合数学](#1467)
#### [概率与统计](#1467)
### [1468_计算税后工资 🔒](#1468)
#### [数据库](#1468)
### [1469_寻找所有的独生节点 🔒](#1469)
#### [树](#1469)
#### [深度优先搜索](#1469)
#### [广度优先搜索](#1469)
#### [二叉树](#1469)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1460_通过翻转子数组使两个数组相等
___
#### 数组
___
#### 哈希表
___
#### 排序
---
### 1461_检查一个字符串是否包含所有长度为 K 的二进制子串
___
#### 位运算
___
#### 哈希表
___
#### 字符串
___
#### 哈希函数
___
#### 滚动哈希
---
### 1462_课程表 IV
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 图
___
#### 拓扑排序
---
### 1463_摘樱桃 II
___
#### 数组
___
#### 动态规划
___
#### 矩阵
---
### 1464_数组中两元素的最大乘积
___
#### 数组
___
#### 排序
___
#### 堆（优先队列）
---
### 1465_切割后面积最大的蛋糕
___
#### 贪心
___
#### 数组
___
#### 排序
---
### 1466_重新规划路线
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 图
---
### 1467_两个盒子中球的颜色数相同的概率
___
#### 数组
___
#### 数学
___
#### 动态规划
___
#### 回溯
___
#### 组合数学
___
#### 概率与统计
---
### 1468_计算税后工资 🔒
___
#### 数据库
---
### 1469_寻找所有的独生节点 🔒
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 二叉树
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二叉树 | 位运算 | 动态规划 |
| 哈希函数 | 哈希表 | 回溯 |
| 图 | 堆（优先队列） | 字符串 |
| 广度优先搜索 | 拓扑排序 | 排序 |
| 数学 | 数据库 | 数组 |
| 树 | 概率与统计 | 深度优先搜索 |
| 滚动哈希 | 矩阵 | 组合数学 |
| 贪心 |  |  |

# [1460. 通过翻转子数组使两个数组相等](https://leetcode.cn/problems/make-two-arrays-equal-by-reversing-subarrays){#1460}

{{< tabs "1460" >}}

{{% tab "python" %}}
```python
class Solution:
    def canBeEqual(self, target: List[int], arr: List[int]) -> bool:
        return Counter(target) == Counter(arr)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean canBeEqual(int[] target, int[] arr) {
        int[] cnt1 = new int[1001];
        int[] cnt2 = new int[1001];
        for (int v : target) {
            ++cnt1[v];
        }
        for (int v : arr) {
            ++cnt2[v];
        }
        return Arrays.equals(cnt1, cnt2);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> cnt1(1001);
        vector<int> cnt2(1001);
        for (int& v : target) {
            ++cnt1[v];
        }
        for (int& v : arr) {
            ++cnt2[v];
        }
        return cnt1 == cnt2;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func canBeEqual(target []int, arr []int) bool {
	cnt1 := make([]int, 1001)
	cnt2 := make([]int, 1001)
	for _, v := range target {
		cnt1[v]++
	}
	for _, v := range arr {
		cnt2[v]++
	}
	return reflect.DeepEqual(cnt1, cnt2)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function canBeEqual(target: number[], arr: number[]): boolean {
    const n = target.length;
    const cnt = Array(1001).fill(0);
    for (let i = 0; i < n; i++) {
        cnt[target[i]]++;
        cnt[arr[i]]--;
    }
    return cnt.every(v => !v);
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function canBeEqual(target, arr) {
    const n = target.length;
    const cnt = Array(1001).fill(0);
    for (let i = 0; i < n; i++) {
        cnt[target[i]]++;
        cnt[arr[i]]--;
    }
    return cnt.every(v => !v);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn can_be_equal(mut target: Vec<i32>, mut arr: Vec<i32>) -> bool {
        let n = target.len();
        let mut cnt = [0; 1001];
        for i in 0..n {
            cnt[target[i] as usize] += 1;
            cnt[arr[i] as usize] -= 1;
        }
        cnt.iter().all(|v| *v == 0)
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer[] $target
     * @param Integer[] $arr
     * @return Boolean
     */
    function canBeEqual($target, $arr) {
        sort($target);
        sort($arr);
        return $target === $arr;
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int compare(const void* a, const void* b) {
    return (*(int*) a - *(int*) b);
}

bool canBeEqual(int* target, int targetSize, int* arr, int arrSize) {
    qsort(target, targetSize, sizeof(int), compare);
    qsort(arr, arrSize, sizeof(int), compare);
    for (int i = 0; i < targetSize; ++i) {
        if (target[i] != arr[i]) {
            return false;
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

<p>给你两个长度相同的整数数组&nbsp;<code>target</code>&nbsp;和&nbsp;<code>arr</code>&nbsp;。每一步中，你可以选择&nbsp;<code>arr</code>&nbsp;的任意 <strong>非空子数组</strong>&nbsp;并将它翻转。你可以执行此过程任意次。</p>

<p><em>如果你能让 <code>arr</code>&nbsp;变得与 <code>target</code>&nbsp;相同，返回 True；否则，返回 False 。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>target = [1,2,3,4], arr = [2,4,1,3]
<strong>输出：</strong>true
<strong>解释：</strong>你可以按照如下步骤使 arr 变成 target：
1- 翻转子数组 [2,4,1] ，arr 变成 [1,4,2,3]
2- 翻转子数组 [4,2] ，arr 变成 [1,2,4,3]
3- 翻转子数组 [4,3] ，arr 变成 [1,2,3,4]
上述方法并不是唯一的，还存在多种将 arr 变成 target 的方法。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>target = [7], arr = [7]
<strong>输出：</strong>true
<strong>解释：</strong>arr 不需要做任何翻转已经与 target 相等。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>target = [3,7,9], arr = [3,7,11]
<strong>输出：</strong>false
<strong>解释：</strong>arr 没有数字 9 ，所以无论如何也无法变成 target 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>target.length == arr.length</code></li>
	<li><code>1 &lt;= target.length &lt;= 1000</code></li>
	<li><code>1 &lt;= target[i] &lt;= 1000</code></li>
	<li><code>1 &lt;= arr[i] &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序

如果两个数组排序后相等，那么它们可以通过翻转子数组变成相等的数组。

因此，我们只需要对两个数组进行排序，然后判断排序后的数组是否相等即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 是数组 $arr$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canBeEqual(self, target: List[int], arr: List[int]) -> bool:
        return sorted(target) == sorted(arr)
```

#### Java

```java
class Solution {
    public boolean canBeEqual(int[] target, int[] arr) {
        Arrays.sort(target);
        Arrays.sort(arr);
        return Arrays.equals(target, arr);
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        return target == arr;
    }
};
```

#### Go

```go
func canBeEqual(target []int, arr []int) bool {
	sort.Ints(target)
	sort.Ints(arr)
	return reflect.DeepEqual(target, arr)
}
```

#### TypeScript

```ts
function canBeEqual(target: number[], arr: number[]): boolean {
    target.sort();
    arr.sort();
    return target.every((x, i) => x === arr[i]);
}
```

#### JavaScript

```js
function canBeEqual(target, arr) {
    target.sort();
    arr.sort();
    return target.every((x, i) => x === arr[i]);
}
```

#### Rust

```rust
impl Solution {
    pub fn can_be_equal(mut target: Vec<i32>, mut arr: Vec<i32>) -> bool {
        target.sort();
        arr.sort();
        target == arr
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param Integer[] $target
     * @param Integer[] $arr
     * @return Boolean
     */
    function canBeEqual($target, $arr) {
        sort($target);
        sort($arr);
        return $target === $arr;
    }
}
```

#### C

```c
int compare(const void* a, const void* b) {
    return (*(int*) a - *(int*) b);
}

bool canBeEqual(int* target, int targetSize, int* arr, int arrSize) {
    qsort(target, targetSize, sizeof(int), compare);
    qsort(arr, arrSize, sizeof(int), compare);
    for (int i = 0; i < targetSize; ++i) {
        if (target[i] != arr[i]) {
            return false;
        }
    }
    return true;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：计数

我们注意到，题目中给出的数组元素的范围是 $1 \sim 1000$，因此我们可以使用两个长度为 $1001$ 的数组 `cnt1` 和 `cnt2` 分别记录数组 `target` 和 `arr` 中每个元素出现的次数。最后判断两个数组是否相等即可。

我们也可以只用一个数组 `cnt`，遍历数组 `target` 和 `arr`，对于 `target[i]`，我们将 `cnt[target[i]]` 加一，对于 `arr[i]`，我们将 `cnt[arr[i]]` 减一。最后判断数组 `cnt` 中的所有元素是否都为 $0$。

时间复杂度 $O(n + M)$，空间复杂度 $O(M)$。其中 $n$ 是数组 $arr$ 的长度，而 $M$ 是数组元素的范围，本题中 $M = 1001$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canBeEqual(self, target: List[int], arr: List[int]) -> bool:
        return Counter(target) == Counter(arr)
```

#### Java

```java
class Solution {
    public boolean canBeEqual(int[] target, int[] arr) {
        int[] cnt1 = new int[1001];
        int[] cnt2 = new int[1001];
        for (int v : target) {
            ++cnt1[v];
        }
        for (int v : arr) {
            ++cnt2[v];
        }
        return Arrays.equals(cnt1, cnt2);
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> cnt1(1001);
        vector<int> cnt2(1001);
        for (int& v : target) {
            ++cnt1[v];
        }
        for (int& v : arr) {
            ++cnt2[v];
        }
        return cnt1 == cnt2;
    }
};
```

#### Go

```go
func canBeEqual(target []int, arr []int) bool {
	cnt1 := make([]int, 1001)
	cnt2 := make([]int, 1001)
	for _, v := range target {
		cnt1[v]++
	}
	for _, v := range arr {
		cnt2[v]++
	}
	return reflect.DeepEqual(cnt1, cnt2)
}
```

#### TypeScript

```ts
function canBeEqual(target: number[], arr: number[]): boolean {
    const n = target.length;
    const cnt = Array(1001).fill(0);
    for (let i = 0; i < n; i++) {
        cnt[target[i]]++;
        cnt[arr[i]]--;
    }
    return cnt.every(v => !v);
}
```

#### JavaScript

```js
function canBeEqual(target, arr) {
    const n = target.length;
    const cnt = Array(1001).fill(0);
    for (let i = 0; i < n; i++) {
        cnt[target[i]]++;
        cnt[arr[i]]--;
    }
    return cnt.every(v => !v);
}
```

#### Rust

```rust
impl Solution {
    pub fn can_be_equal(mut target: Vec<i32>, mut arr: Vec<i32>) -> bool {
        let n = target.len();
        let mut cnt = [0; 1001];
        for i in 0..n {
            cnt[target[i] as usize] += 1;
            cnt[arr[i] as usize] -= 1;
        }
        cnt.iter().all(|v| *v == 0)
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1461. 检查一个字符串是否包含所有长度为 K 的二进制子串](https://leetcode.cn/problems/check-if-a-string-contains-all-binary-codes-of-size-k){#1461}

{{< tabs "1461" >}}

{{% tab "python" %}}
```python
class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        n = len(s)
        m = 1 << k
        if n - k + 1 < m:
            return False
        ss = set()
        x = int(s[:k], 2)
        ss.add(x)
        for i in range(k, n):
            a = int(s[i - k]) << (k - 1)
            b = int(s[i])
            x = (x - a) << 1 | b
            ss.add(x)
        return len(ss) == m
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean hasAllCodes(String s, int k) {
        int n = s.length();
        int m = 1 << k;
        if (n - k + 1 < m) {
            return false;
        }
        boolean[] ss = new boolean[m];
        int x = Integer.parseInt(s.substring(0, k), 2);
        ss[x] = true;
        for (int i = k; i < n; ++i) {
            int a = (s.charAt(i - k) - '0') << (k - 1);
            int b = s.charAt(i) - '0';
            x = (x - a) << 1 | b;
            ss[x] = true;
        }
        for (boolean v : ss) {
            if (!v) {
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
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        int m = 1 << k;
        if (n - k + 1 < m) {
            return false;
        }
        bool ss[m];
        memset(ss, false, sizeof(ss));
        int x = stoi(s.substr(0, k), nullptr, 2);
        ss[x] = true;
        for (int i = k; i < n; ++i) {
            int a = (s[i - k] - '0') << (k - 1);
            int b = s[i] - '0';
            x = (x - a) << 1 | b;
            ss[x] = true;
        }
        return all_of(ss, ss + m, [](bool v) { return v; });
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func hasAllCodes(s string, k int) bool {
	n, m := len(s), 1<<k
	if n-k+1 < m {
		return false
	}
	ss := make([]bool, m)
	x, _ := strconv.ParseInt(s[:k], 2, 64)
	ss[x] = true
	for i := k; i < n; i++ {
		a := int64(s[i-k]-'0') << (k - 1)
		b := int64(s[i] - '0')
		x = (x-a)<<1 | b
		ss[x] = true
	}
	for _, v := range ss {
		if !v {
			return false
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function hasAllCodes(s: string, k: number): boolean {
    const n = s.length;
    const m = 1 << k;
    if (n - k + 1 < m) {
        return false;
    }
    let x = +`0b${s.slice(0, k)}`;
    const ss = new Set<number>();
    ss.add(x);
    for (let i = k; i < n; ++i) {
        const a = +s[i - k] << (k - 1);
        const b = +s[i];
        x = ((x - a) << 1) | b;
        ss.add(x);
    }
    return ss.size === m;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个二进制字符串&nbsp;<code>s</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;。如果所有长度为 <code>k</code>&nbsp;的二进制字符串都是 <code>s</code>&nbsp;的子串，请返回 <code>true</code> ，否则请返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "00110110", k = 2
<strong>输出：</strong>true
<strong>解释：</strong>长度为 2 的二进制串包括 "00"，"01"，"10" 和 "11"。它们分别是 s 中下标为 0，1，3，2 开始的长度为 2 的子串。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "0110", k = 1
<strong>输出：</strong>true
<strong>解释：</strong>长度为 1 的二进制串包括 "0" 和 "1"，显然它们都是 s 的子串。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "0110", k = 2
<strong>输出：</strong>false
<strong>解释：</strong>长度为 2 的二进制串 "00" 没有出现在 s 中。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 5 * 10<sup>5</sup></code></li>
	<li><code>s[i]</code> 不是<code>'0'</code> 就是 <code>'1'</code></li>
	<li><code>1 &lt;= k &lt;= 20</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

首先，对于一个长度为 $n$ 的字符串 $s$，长度为 $k$ 的子串的个数为 $n - k + 1$，如果 $n - k + 1 < 2^k$，则一定存在长度为 $k$ 的二进制串不是 $s$ 的子串，返回 `false`。

接下来，我们遍历字符串 $s$，将所有长度为 $k$ 的子串存入集合 $ss$，最后判断集合 $ss$ 的大小是否等于 $2^k$。

时间复杂度 $O(n \times k)$，空间复杂度 $O(n)$。其中 $n$ 是字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        n = len(s)
        m = 1 << k
        if n - k + 1 < m:
            return False
        ss = {s[i : i + k] for i in range(n - k + 1)}
        return len(ss) == m
```

#### Java

```java
class Solution {
    public boolean hasAllCodes(String s, int k) {
        int n = s.length();
        int m = 1 << k;
        if (n - k + 1 < m) {
            return false;
        }
        Set<String> ss = new HashSet<>();
        for (int i = 0; i < n - k + 1; ++i) {
            ss.add(s.substring(i, i + k));
        }
        return ss.size() == m;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        int m = 1 << k;
        if (n - k + 1 < m) {
            return false;
        }
        unordered_set<string> ss;
        for (int i = 0; i + k <= n; ++i) {
            ss.insert(move(s.substr(i, k)));
        }
        return ss.size() == m;
    }
};
```

#### Go

```go
func hasAllCodes(s string, k int) bool {
	n, m := len(s), 1<<k
	if n-k+1 < m {
		return false
	}
	ss := map[string]bool{}
	for i := 0; i+k <= n; i++ {
		ss[s[i:i+k]] = true
	}
	return len(ss) == m
}
```

#### TypeScript

```ts
function hasAllCodes(s: string, k: number): boolean {
    const n = s.length;
    const m = 1 << k;
    if (n - k + 1 < m) {
        return false;
    }
    const ss = new Set<string>();
    for (let i = 0; i + k <= n; ++i) {
        ss.add(s.slice(i, i + k));
    }
    return ss.size === m;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：滑动窗口

方法一中，我们存储了所有长度为 $k$ 的不同子串，子串的处理需要 $O(k)$ 的时间，我们可以改用滑动窗口，每次添加最新字符时，删除窗口最左边的字符。此过程中用一个整型数字 $x$ 来存放子串。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        n = len(s)
        m = 1 << k
        if n - k + 1 < m:
            return False
        ss = set()
        x = int(s[:k], 2)
        ss.add(x)
        for i in range(k, n):
            a = int(s[i - k]) << (k - 1)
            b = int(s[i])
            x = (x - a) << 1 | b
            ss.add(x)
        return len(ss) == m
```

#### Java

```java
class Solution {
    public boolean hasAllCodes(String s, int k) {
        int n = s.length();
        int m = 1 << k;
        if (n - k + 1 < m) {
            return false;
        }
        boolean[] ss = new boolean[m];
        int x = Integer.parseInt(s.substring(0, k), 2);
        ss[x] = true;
        for (int i = k; i < n; ++i) {
            int a = (s.charAt(i - k) - '0') << (k - 1);
            int b = s.charAt(i) - '0';
            x = (x - a) << 1 | b;
            ss[x] = true;
        }
        for (boolean v : ss) {
            if (!v) {
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
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        int m = 1 << k;
        if (n - k + 1 < m) {
            return false;
        }
        bool ss[m];
        memset(ss, false, sizeof(ss));
        int x = stoi(s.substr(0, k), nullptr, 2);
        ss[x] = true;
        for (int i = k; i < n; ++i) {
            int a = (s[i - k] - '0') << (k - 1);
            int b = s[i] - '0';
            x = (x - a) << 1 | b;
            ss[x] = true;
        }
        return all_of(ss, ss + m, [](bool v) { return v; });
    }
};
```

#### Go

```go
func hasAllCodes(s string, k int) bool {
	n, m := len(s), 1<<k
	if n-k+1 < m {
		return false
	}
	ss := make([]bool, m)
	x, _ := strconv.ParseInt(s[:k], 2, 64)
	ss[x] = true
	for i := k; i < n; i++ {
		a := int64(s[i-k]-'0') << (k - 1)
		b := int64(s[i] - '0')
		x = (x-a)<<1 | b
		ss[x] = true
	}
	for _, v := range ss {
		if !v {
			return false
		}
	}
	return true
}
```

#### TypeScript

```ts
function hasAllCodes(s: string, k: number): boolean {
    const n = s.length;
    const m = 1 << k;
    if (n - k + 1 < m) {
        return false;
    }
    let x = +`0b${s.slice(0, k)}`;
    const ss = new Set<number>();
    ss.add(x);
    for (let i = k; i < n; ++i) {
        const a = +s[i - k] << (k - 1);
        const b = +s[i];
        x = ((x - a) << 1) | b;
        ss.add(x);
    }
    return ss.size === m;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1462. 课程表 IV](https://leetcode.cn/problems/course-schedule-iv){#1462}

{{< tabs "1462" >}}

{{% tab "python" %}}
```python
class Solution:
    def checkIfPrerequisite(
        self, n: int, prerequisites: List[List[int]], queries: List[List[int]]
    ) -> List[bool]:
        f = [[False] * n for _ in range(n)]
        g = [[] for _ in range(n)]
        indeg = [0] * n
        for a, b in prerequisites:
            g[a].append(b)
            indeg[b] += 1
        q = deque(i for i, x in enumerate(indeg) if x == 0)
        while q:
            i = q.popleft()
            for j in g[i]:
                f[i][j] = True
                for h in range(n):
                    f[h][j] = f[h][j] or f[h][i]
                indeg[j] -= 1
                if indeg[j] == 0:
                    q.append(j)
        return [f[a][b] for a, b in queries]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Boolean> checkIfPrerequisite(int n, int[][] prerequisites, int[][] queries) {
        boolean[][] f = new boolean[n][n];
        List<Integer>[] g = new List[n];
        int[] indeg = new int[n];
        Arrays.setAll(g, i -> new ArrayList<>());
        for (var p : prerequisites) {
            g[p[0]].add(p[1]);
            ++indeg[p[1]];
        }
        Deque<Integer> q = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            if (indeg[i] == 0) {
                q.offer(i);
            }
        }
        while (!q.isEmpty()) {
            int i = q.poll();
            for (int j : g[i]) {
                f[i][j] = true;
                for (int h = 0; h < n; ++h) {
                    f[h][j] |= f[h][i];
                }
                if (--indeg[j] == 0) {
                    q.offer(j);
                }
            }
        }
        List<Boolean> ans = new ArrayList<>();
        for (var qry : queries) {
            ans.add(f[qry[0]][qry[1]]);
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
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        bool f[n][n];
        memset(f, false, sizeof(f));
        vector<int> g[n];
        vector<int> indeg(n);
        for (auto& p : prerequisites) {
            g[p[0]].push_back(p[1]);
            ++indeg[p[1]];
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            for (int j : g[i]) {
                f[i][j] = true;
                for (int h = 0; h < n; ++h) {
                    f[h][j] |= f[h][i];
                }
                if (--indeg[j] == 0) {
                    q.push(j);
                }
            }
        }
        vector<bool> ans;
        for (auto& qry : queries) {
            ans.push_back(f[qry[0]][qry[1]]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func checkIfPrerequisite(n int, prerequisites [][]int, queries [][]int) (ans []bool) {
	f := make([][]bool, n)
	for i := range f {
		f[i] = make([]bool, n)
	}
	g := make([][]int, n)
	indeg := make([]int, n)
	for _, p := range prerequisites {
		a, b := p[0], p[1]
		g[a] = append(g[a], b)
		indeg[b]++
	}
	q := []int{}
	for i, x := range indeg {
		if x == 0 {
			q = append(q, i)
		}
	}
	for len(q) > 0 {
		i := q[0]
		q = q[1:]
		for _, j := range g[i] {
			f[i][j] = true
			for h := 0; h < n; h++ {
				f[h][j] = f[h][j] || f[h][i]
			}
			indeg[j]--
			if indeg[j] == 0 {
				q = append(q, j)
			}
		}
	}
	for _, q := range queries {
		ans = append(ans, f[q[0]][q[1]])
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function checkIfPrerequisite(n: number, prerequisites: number[][], queries: number[][]): boolean[] {
    const f = Array.from({ length: n }, () => Array(n).fill(false));
    const g: number[][] = Array.from({ length: n }, () => []);
    const indeg: number[] = Array(n).fill(0);
    for (const [a, b] of prerequisites) {
        g[a].push(b);
        ++indeg[b];
    }
    const q: number[] = [];
    for (let i = 0; i < n; ++i) {
        if (indeg[i] === 0) {
            q.push(i);
        }
    }
    while (q.length) {
        const i = q.shift()!;
        for (const j of g[i]) {
            f[i][j] = true;
            for (let h = 0; h < n; ++h) {
                f[h][j] ||= f[h][i];
            }
            if (--indeg[j] === 0) {
                q.push(j);
            }
        }
    }
    return queries.map(([a, b]) => f[a][b]);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你总共需要上<meta charset="UTF-8" />&nbsp;<code>numCourses</code>&nbsp;门课，课程编号依次为 <code>0</code>&nbsp;到&nbsp;<code>numCourses-1</code>&nbsp;。你会得到一个数组&nbsp;<code>prerequisite</code> ，其中<meta charset="UTF-8" />&nbsp;<code>prerequisites[i] = [a<sub>i</sub>, b<sub>i</sub>]</code>&nbsp;表示如果你想选<meta charset="UTF-8" />&nbsp;<code>b<sub>i</sub></code> 课程，你<strong> 必须</strong> 先选<meta charset="UTF-8" />&nbsp;<code>a<sub>i</sub></code>&nbsp;课程。</p>

<ul>
	<li>有的课会有直接的先修课程，比如如果想上课程 <code>1</code>&nbsp;，你必须先上课程 <code>0</code>&nbsp;，那么会以 <code>[0,1]</code>&nbsp;数对的形式给出先修课程数对。</li>
</ul>

<p>先决条件也可以是 <strong>间接</strong> 的。如果课程 <code>a</code> 是课程 <code>b</code> 的先决条件，课程 <code>b</code> 是课程 <code>c</code> 的先决条件，那么课程 <code>a</code> 就是课程 <code>c</code> 的先决条件。</p>

<p>你也得到一个数组<meta charset="UTF-8" />&nbsp;<code>queries</code>&nbsp;，其中<meta charset="UTF-8" />&nbsp;<code>queries[j] = [u<sub>j</sub>, v<sub>j</sub>]</code>。对于第 <code>j</code> 个查询，您应该回答课程<meta charset="UTF-8" />&nbsp;<code>u<sub>j</sub></code>&nbsp;是否是课程<meta charset="UTF-8" />&nbsp;<code>v<sub>j</sub></code>&nbsp;的先决条件。</p>

<p>返回一个布尔数组 <code>answer</code> ，其中 <code>answer[j]</code> 是第 <code>j</code> 个查询的答案。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1462.Course%20Schedule%20IV/images/courses4-1-graph.jpg" /></p>

<pre>
<strong>输入：</strong>numCourses = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
<strong>输出：</strong>[false,true]
<strong>解释：</strong>[1, 0] 数对表示在你上课程 0 之前必须先上课程 1。
课程 0 不是课程 1 的先修课程，但课程 1 是课程 0 的先修课程。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>numCourses = 2, prerequisites = [], queries = [[1,0],[0,1]]
<strong>输出：</strong>[false,false]
<strong>解释：</strong>没有先修课程对，所以每门课程之间是独立的。
</pre>

<p><strong class="example">示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1462.Course%20Schedule%20IV/images/courses4-3-graph.jpg" /></p>

<pre>
<strong>输入：</strong>numCourses = 3, prerequisites = [[1,2],[1,0],[2,0]], queries = [[1,0],[1,2]]
<strong>输出：</strong>[true,true]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<p><meta charset="UTF-8" /></p>

<ul>
	<li><code>2 &lt;= numCourses &lt;= 100</code></li>
	<li><code>0 &lt;= prerequisites.length &lt;= (numCourses * (numCourses - 1) / 2)</code></li>
	<li><code>prerequisites[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub>&nbsp;&lt;= numCourses - 1</code></li>
	<li><code>a<sub>i</sub>&nbsp;!= b<sub>i</sub></code></li>
	<li>每一对<meta charset="UTF-8" />&nbsp;<code>[a<sub>i</sub>, b<sub>i</sub>]</code>&nbsp;都 <strong>不同</strong></li>
	<li>先修课程图中没有环。</li>
	<li><code>1 &lt;= queries.length &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= u<sub>i</sub>, v<sub>i</sub>&nbsp;&lt;= numCourses - 1</code></li>
	<li><code>u<sub>i</sub>&nbsp;!= v<sub>i</sub></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：Floyd 算法

我们创建一个二维数组 $f$，其中 $f[i][j]$ 表示节点 $i$ 到节点 $j$ 是否可达。

接下来，我们遍历先修课程数组 $prerequisites$，对于其中的每一项 $[a, b]$，我们将 $f[a][b]$ 设为 $true$。

然后，我们使用 Floyd 算法计算出所有节点对之间的可达性。

具体地，我们使用三重循环，首先枚举中间点 $k$，接下来枚举起点 $i$，最后枚举终点 $j$。对于每一次循环，如果节点 $i$ 到节点 $k$ 可达，且节点 $k$ 到节点 $j$ 可达，那么节点 $i$ 到节点 $j$ 也是可达的，我们将 $f[i][j]$ 设为 $true$。

在计算完所有节点对之间的可达性之后，对于每一个查询 $[a, b]$，我们直接返回 $f[a][b]$ 即可。

时间复杂度 $O(n^3)$，空间复杂度 $O(n^2)$。其中 $n$ 为节点数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def checkIfPrerequisite(
        self, n: int, prerequisites: List[List[int]], queries: List[List[int]]
    ) -> List[bool]:
        f = [[False] * n for _ in range(n)]
        for a, b in prerequisites:
            f[a][b] = True
        for k in range(n):
            for i in range(n):
                for j in range(n):
                    if f[i][k] and f[k][j]:
                        f[i][j] = True
        return [f[a][b] for a, b in queries]
```

#### Java

```java
class Solution {
    public List<Boolean> checkIfPrerequisite(int n, int[][] prerequisites, int[][] queries) {
        boolean[][] f = new boolean[n][n];
        for (var p : prerequisites) {
            f[p[0]][p[1]] = true;
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    f[i][j] |= f[i][k] && f[k][j];
                }
            }
        }
        List<Boolean> ans = new ArrayList<>();
        for (var q : queries) {
            ans.add(f[q[0]][q[1]]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        bool f[n][n];
        memset(f, false, sizeof(f));
        for (auto& p : prerequisites) {
            f[p[0]][p[1]] = true;
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    f[i][j] |= (f[i][k] && f[k][j]);
                }
            }
        }
        vector<bool> ans;
        for (auto& q : queries) {
            ans.push_back(f[q[0]][q[1]]);
        }
        return ans;
    }
};
```

#### Go

```go
func checkIfPrerequisite(n int, prerequisites [][]int, queries [][]int) (ans []bool) {
	f := make([][]bool, n)
	for i := range f {
		f[i] = make([]bool, n)
	}
	for _, p := range prerequisites {
		f[p[0]][p[1]] = true
	}
	for k := 0; k < n; k++ {
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				f[i][j] = f[i][j] || (f[i][k] && f[k][j])
			}
		}
	}
	for _, q := range queries {
		ans = append(ans, f[q[0]][q[1]])
	}
	return
}
```

#### TypeScript

```ts
function checkIfPrerequisite(n: number, prerequisites: number[][], queries: number[][]): boolean[] {
    const f = Array.from({ length: n }, () => Array(n).fill(false));
    prerequisites.forEach(([a, b]) => (f[a][b] = true));
    for (let k = 0; k < n; ++k) {
        for (let i = 0; i < n; ++i) {
            for (let j = 0; j < n; ++j) {
                f[i][j] ||= f[i][k] && f[k][j];
            }
        }
    }
    return queries.map(([a, b]) => f[a][b]);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：拓扑排序

与方法一类似，我们创建一个二维数组 $f$，其中 $f[i][j]$ 表示节点 $i$ 到节点 $j$ 是否可达。另外，我们创建一个邻接表 $g$，其中 $g[i]$ 表示节点 $i$ 的所有后继节点；创建一个数组 $indeg$，其中 $indeg[i]$ 表示节点 $i$ 的入度。

接下来，我们遍历先修课程数组 $prerequisites$，对于其中的每一项 $[a, b]$，我们更新邻接表 $g$ 和入度数组 $indeg$。

然后，我们使用拓扑排序计算出所有节点对之间的可达性。

定义一个队列 $q$，初始时将所有入度为 $0$ 的节点加入队列中。随后不断进行以下操作：取出队首节点 $i$，然后遍历 $g[i]$ 中的所有节点 $j$，将 $f[i][j]$ 设为 $true$。接下来，我们枚举节点 $h$，如果 $f[h][i]$ 为 $true$，那么我们也将 $f[h][j]$ 设为 $true$。在这之后，我们将 $j$ 的入度减少 $1$。如果此时 $j$ 的入度为 $0$，那么我们就将 $j$ 加入队列中。

在计算完所有节点对之间的可达性之后，对于每一个查询 $[a, b]$，我们直接返回 $f[a][b]$ 即可。

时间复杂度 $O(n^3)$，空间复杂度 $O(n^2)$。其中 $n$ 为节点数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def checkIfPrerequisite(
        self, n: int, prerequisites: List[List[int]], queries: List[List[int]]
    ) -> List[bool]:
        f = [[False] * n for _ in range(n)]
        g = [[] for _ in range(n)]
        indeg = [0] * n
        for a, b in prerequisites:
            g[a].append(b)
            indeg[b] += 1
        q = deque(i for i, x in enumerate(indeg) if x == 0)
        while q:
            i = q.popleft()
            for j in g[i]:
                f[i][j] = True
                for h in range(n):
                    f[h][j] = f[h][j] or f[h][i]
                indeg[j] -= 1
                if indeg[j] == 0:
                    q.append(j)
        return [f[a][b] for a, b in queries]
```

#### Java

```java
class Solution {
    public List<Boolean> checkIfPrerequisite(int n, int[][] prerequisites, int[][] queries) {
        boolean[][] f = new boolean[n][n];
        List<Integer>[] g = new List[n];
        int[] indeg = new int[n];
        Arrays.setAll(g, i -> new ArrayList<>());
        for (var p : prerequisites) {
            g[p[0]].add(p[1]);
            ++indeg[p[1]];
        }
        Deque<Integer> q = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            if (indeg[i] == 0) {
                q.offer(i);
            }
        }
        while (!q.isEmpty()) {
            int i = q.poll();
            for (int j : g[i]) {
                f[i][j] = true;
                for (int h = 0; h < n; ++h) {
                    f[h][j] |= f[h][i];
                }
                if (--indeg[j] == 0) {
                    q.offer(j);
                }
            }
        }
        List<Boolean> ans = new ArrayList<>();
        for (var qry : queries) {
            ans.add(f[qry[0]][qry[1]]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        bool f[n][n];
        memset(f, false, sizeof(f));
        vector<int> g[n];
        vector<int> indeg(n);
        for (auto& p : prerequisites) {
            g[p[0]].push_back(p[1]);
            ++indeg[p[1]];
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            for (int j : g[i]) {
                f[i][j] = true;
                for (int h = 0; h < n; ++h) {
                    f[h][j] |= f[h][i];
                }
                if (--indeg[j] == 0) {
                    q.push(j);
                }
            }
        }
        vector<bool> ans;
        for (auto& qry : queries) {
            ans.push_back(f[qry[0]][qry[1]]);
        }
        return ans;
    }
};
```

#### Go

```go
func checkIfPrerequisite(n int, prerequisites [][]int, queries [][]int) (ans []bool) {
	f := make([][]bool, n)
	for i := range f {
		f[i] = make([]bool, n)
	}
	g := make([][]int, n)
	indeg := make([]int, n)
	for _, p := range prerequisites {
		a, b := p[0], p[1]
		g[a] = append(g[a], b)
		indeg[b]++
	}
	q := []int{}
	for i, x := range indeg {
		if x == 0 {
			q = append(q, i)
		}
	}
	for len(q) > 0 {
		i := q[0]
		q = q[1:]
		for _, j := range g[i] {
			f[i][j] = true
			for h := 0; h < n; h++ {
				f[h][j] = f[h][j] || f[h][i]
			}
			indeg[j]--
			if indeg[j] == 0 {
				q = append(q, j)
			}
		}
	}
	for _, q := range queries {
		ans = append(ans, f[q[0]][q[1]])
	}
	return
}
```

#### TypeScript

```ts
function checkIfPrerequisite(n: number, prerequisites: number[][], queries: number[][]): boolean[] {
    const f = Array.from({ length: n }, () => Array(n).fill(false));
    const g: number[][] = Array.from({ length: n }, () => []);
    const indeg: number[] = Array(n).fill(0);
    for (const [a, b] of prerequisites) {
        g[a].push(b);
        ++indeg[b];
    }
    const q: number[] = [];
    for (let i = 0; i < n; ++i) {
        if (indeg[i] === 0) {
            q.push(i);
        }
    }
    while (q.length) {
        const i = q.shift()!;
        for (const j of g[i]) {
            f[i][j] = true;
            for (let h = 0; h < n; ++h) {
                f[h][j] ||= f[h][i];
            }
            if (--indeg[j] === 0) {
                q.push(j);
            }
        }
    }
    return queries.map(([a, b]) => f[a][b]);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1463. 摘樱桃 II](https://leetcode.cn/problems/cherry-pickup-ii){#1463}

{{< tabs "1463" >}}

{{% tab "python" %}}
```python
class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        f = [[-1] * n for _ in range(n)]
        g = [[-1] * n for _ in range(n)]
        f[0][n - 1] = grid[0][0] + grid[0][n - 1]
        for i in range(1, m):
            for j1 in range(n):
                for j2 in range(n):
                    x = grid[i][j1] + (0 if j1 == j2 else grid[i][j2])
                    for y1 in range(j1 - 1, j1 + 2):
                        for y2 in range(j2 - 1, j2 + 2):
                            if 0 <= y1 < n and 0 <= y2 < n and f[y1][y2] != -1:
                                g[j1][j2] = max(g[j1][j2], f[y1][y2] + x)
            f, g = g, f
        return max(f[j1][j2] for j1, j2 in product(range(n), range(n)))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int cherryPickup(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] f = new int[n][n];
        int[][] g = new int[n][n];
        for (int i = 0; i < n; ++i) {
            Arrays.fill(f[i], -1);
            Arrays.fill(g[i], -1);
        }
        f[0][n - 1] = grid[0][0] + grid[0][n - 1];
        for (int i = 1; i < m; ++i) {
            for (int j1 = 0; j1 < n; ++j1) {
                for (int j2 = 0; j2 < n; ++j2) {
                    int x = grid[i][j1] + (j1 == j2 ? 0 : grid[i][j2]);
                    for (int y1 = j1 - 1; y1 <= j1 + 1; ++y1) {
                        for (int y2 = j2 - 1; y2 <= j2 + 1; ++y2) {
                            if (y1 >= 0 && y1 < n && y2 >= 0 && y2 < n && f[y1][y2] != -1) {
                                g[j1][j2] = Math.max(g[j1][j2], f[y1][y2] + x);
                            }
                        }
                    }
                }
            }
            int[][] t = f;
            f = g;
            g = t;
        }
        int ans = 0;
        for (int j1 = 0; j1 < n; ++j1) {
            for (int j2 = 0; j2 < n; ++j2) {
                ans = Math.max(ans, f[j1][j2]);
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
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> f(n, vector<int>(n, -1));
        vector<vector<int>> g(n, vector<int>(n, -1));
        f[0][n - 1] = grid[0][0] + grid[0][n - 1];
        for (int i = 1; i < m; ++i) {
            for (int j1 = 0; j1 < n; ++j1) {
                for (int j2 = 0; j2 < n; ++j2) {
                    int x = grid[i][j1] + (j1 == j2 ? 0 : grid[i][j2]);
                    for (int y1 = j1 - 1; y1 <= j1 + 1; ++y1) {
                        for (int y2 = j2 - 1; y2 <= j2 + 1; ++y2) {
                            if (y1 >= 0 && y1 < n && y2 >= 0 && y2 < n && f[y1][y2] != -1) {
                                g[j1][j2] = max(g[j1][j2], f[y1][y2] + x);
                            }
                        }
                    }
                }
            }
            swap(f, g);
        }
        int ans = 0;
        for (int j1 = 0; j1 < n; ++j1) {
            for (int j2 = 0; j2 < n; ++j2) {
                ans = max(ans, f[j1][j2]);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func cherryPickup(grid [][]int) (ans int) {
	m, n := len(grid), len(grid[0])
	f := make([][]int, n)
	g := make([][]int, n)
	for i := range f {
		f[i] = make([]int, n)
		g[i] = make([]int, n)
		for j := range f[i] {
			f[i][j] = -1
			g[i][j] = -1
		}
	}
	f[0][n-1] = grid[0][0] + grid[0][n-1]
	for i := 1; i < m; i++ {
		for j1 := 0; j1 < n; j1++ {
			for j2 := 0; j2 < n; j2++ {
				x := grid[i][j1]
				if j1 != j2 {
					x += grid[i][j2]
				}
				for y1 := j1 - 1; y1 <= j1+1; y1++ {
					for y2 := j2 - 1; y2 <= j2+1; y2++ {
						if y1 >= 0 && y1 < n && y2 >= 0 && y2 < n && f[y1][y2] != -1 {
							g[j1][j2] = max(g[j1][j2], f[y1][y2]+x)
						}
					}
				}
			}
		}
		f, g = g, f
	}
	for j1 := 0; j1 < n; j1++ {
		ans = max(ans, slices.Max(f[j1]))
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function cherryPickup(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;
    let f: number[][] = Array.from({ length: n }, () => Array.from({ length: n }, () => -1));
    let g: number[][] = Array.from({ length: n }, () => Array.from({ length: n }, () => -1));
    f[0][n - 1] = grid[0][0] + grid[0][n - 1];
    for (let i = 1; i < m; ++i) {
        for (let j1 = 0; j1 < n; ++j1) {
            for (let j2 = 0; j2 < n; ++j2) {
                const x = grid[i][j1] + (j1 === j2 ? 0 : grid[i][j2]);
                for (let y1 = j1 - 1; y1 <= j1 + 1; ++y1) {
                    for (let y2 = j2 - 1; y2 <= j2 + 1; ++y2) {
                        if (y1 >= 0 && y1 < n && y2 >= 0 && y2 < n && f[y1][y2] !== -1) {
                            g[j1][j2] = Math.max(g[j1][j2], f[y1][y2] + x);
                        }
                    }
                }
            }
        }
        [f, g] = [g, f];
    }
    return Math.max(...f.flat());
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个&nbsp;<code>rows x cols</code> 的矩阵&nbsp;<code>grid</code>&nbsp;来表示一块樱桃地。 <code>grid</code>&nbsp;中每个格子的数字表示你能获得的樱桃数目。</p>

<p>你有两个机器人帮你收集樱桃，机器人 1 从左上角格子 <code>(0,0)</code> 出发，机器人 2 从右上角格子 <code>(0, cols-1)</code> 出发。</p>

<p>请你按照如下规则，返回两个机器人能收集的最多樱桃数目：</p>

<ul>
	<li>从格子&nbsp;<code>(i,j)</code> 出发，机器人可以移动到格子&nbsp;<code>(i+1, j-1)</code>，<code>(i+1, j)</code> 或者&nbsp;<code>(i+1, j+1)</code>&nbsp;。</li>
	<li>当一个机器人经过某个格子时，它会把该格子内所有的樱桃都摘走，然后这个位置会变成空格子，即没有樱桃的格子。</li>
	<li>当两个机器人同时到达同一个格子时，它们中只有一个可以摘到樱桃。</li>
	<li>两个机器人在任意时刻都不能移动到 <code>grid</code>&nbsp;外面。</li>
	<li>两个机器人最后都要到达&nbsp;<code>grid</code>&nbsp;最底下一行。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1463.Cherry%20Pickup%20II/images/sample_1_1802.png" style="height: 182px; width: 139px;"></strong></p>

<pre><strong>输入：</strong>grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
<strong>输出：</strong>24
<strong>解释：</strong>机器人 1 和机器人 2 的路径在上图中分别用绿色和蓝色表示。
机器人 1 摘的樱桃数目为 (3 + 2 + 5 + 2) = 12 。
机器人 2 摘的樱桃数目为 (1 + 5 + 5 + 1) = 12 。
樱桃总数为： 12 + 12 = 24 。
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1463.Cherry%20Pickup%20II/images/sample_2_1802.png" style="height: 257px; width: 284px;"></strong></p>

<pre><strong>输入：</strong>grid = [[1,0,0,0,0,0,1],[2,0,0,0,0,3,0],[2,0,9,0,0,0,0],[0,3,0,5,4,0,0],[1,0,2,3,0,0,6]]
<strong>输出：</strong>28
<strong>解释：</strong>机器人 1 和机器人 2 的路径在上图中分别用绿色和蓝色表示。
机器人 1 摘的樱桃数目为 (1 + 9 + 5 + 2) = 17 。
机器人 2 摘的樱桃数目为 (1 + 3 + 4 + 3) = 11 。
樱桃总数为： 17 + 11 = 28 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>grid = [[1,0,0,3],[0,0,0,3],[0,0,3,3],[9,0,3,3]]
<strong>输出：</strong>22
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>grid = [[1,1],[1,1]]
<strong>输出：</strong>4
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>rows == grid.length</code></li>
	<li><code>cols == grid[i].length</code></li>
	<li><code>2 &lt;= rows, cols &lt;= 70</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 100&nbsp;</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j_1][j_2]$ 表示两个机器人分别在第 $i$ 行的位置 $j_1$ 和 $j_2$ 时能够摘到的最多樱桃数目。初始时 $f[0][0][n-1] = grid[0][0] + grid[0][n-1]$，其余值均为 $-1$。答案为 $\max_{0 \leq j_1, j_2 < n} f[m-1][j_1][j_2]$。

考虑 $f[i][j_1][j_2]$，如果 $j_1 \neq j_2$，那么机器人在第 $i$ 行能摘到的樱桃数目为 $grid[i][j_1] + grid[i][j_2]$；如果 $j_1 = j_2$，那么机器人在第 $i$ 行能摘到的樱桃数目为 $grid[i][j_1]$。我们可以枚举两个机器人的上一个状态 $f[i-1][y1][y2]$，其中 $y_1, y_2$ 分别是两个机器人在第 $i-1$ 行的位置，那么有 $y_1 \in \{j_1-1, j_1, j_1+1\}$ 且 $y_2 \in \{j_2-1, j_2, j_2+1\}$。状态转移方程如下：

$$
f[i][j_1][j_2] = \max_{y_1 \in \{j_1-1, j_1, j_1+1\}, y_2 \in \{j_2-1, j_2, j_2+1\}} f[i-1][y_1][y_2] + \begin{cases} grid[i][j_1] + grid[i][j_2], & j_1 \neq j_2 \\ grid[i][j_1], & j_1 = j_2 \end{cases}
$$

其中 $f[i-1][y_1][y_2]$ 为 $-1$ 时需要忽略。

最终的答案即为 $\max_{0 \leq j_1, j_2 < n} f[m-1][j_1][j_2]$。

时间复杂度 $O(m \times n^2)$，空间复杂度 $O(m \times n^2)$。其中 $m$ 和 $n$ 分别是网格的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        f = [[[-1] * n for _ in range(n)] for _ in range(m)]
        f[0][0][n - 1] = grid[0][0] + grid[0][n - 1]
        for i in range(1, m):
            for j1 in range(n):
                for j2 in range(n):
                    x = grid[i][j1] + (0 if j1 == j2 else grid[i][j2])
                    for y1 in range(j1 - 1, j1 + 2):
                        for y2 in range(j2 - 1, j2 + 2):
                            if 0 <= y1 < n and 0 <= y2 < n and f[i - 1][y1][y2] != -1:
                                f[i][j1][j2] = max(f[i][j1][j2], f[i - 1][y1][y2] + x)
        return max(f[-1][j1][j2] for j1, j2 in product(range(n), range(n)))
```

#### Java

```java
class Solution {
    public int cherryPickup(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][][] f = new int[m][n][n];
        for (var g : f) {
            for (var h : g) {
                Arrays.fill(h, -1);
            }
        }
        f[0][0][n - 1] = grid[0][0] + grid[0][n - 1];
        for (int i = 1; i < m; ++i) {
            for (int j1 = 0; j1 < n; ++j1) {
                for (int j2 = 0; j2 < n; ++j2) {
                    int x = grid[i][j1] + (j1 == j2 ? 0 : grid[i][j2]);
                    for (int y1 = j1 - 1; y1 <= j1 + 1; ++y1) {
                        for (int y2 = j2 - 1; y2 <= j2 + 1; ++y2) {
                            if (y1 >= 0 && y1 < n && y2 >= 0 && y2 < n && f[i - 1][y1][y2] != -1) {
                                f[i][j1][j2] = Math.max(f[i][j1][j2], f[i - 1][y1][y2] + x);
                            }
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int j1 = 0; j1 < n; ++j1) {
            for (int j2 = 0; j2 < n; ++j2) {
                ans = Math.max(ans, f[m - 1][j1][j2]);
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
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int f[m][n][n];
        memset(f, -1, sizeof(f));
        f[0][0][n - 1] = grid[0][0] + grid[0][n - 1];
        for (int i = 1; i < m; ++i) {
            for (int j1 = 0; j1 < n; ++j1) {
                for (int j2 = 0; j2 < n; ++j2) {
                    int x = grid[i][j1] + (j1 == j2 ? 0 : grid[i][j2]);
                    for (int y1 = j1 - 1; y1 <= j1 + 1; ++y1) {
                        for (int y2 = j2 - 1; y2 <= j2 + 1; ++y2) {
                            if (y1 >= 0 && y1 < n && y2 >= 0 && y2 < n && f[i - 1][y1][y2] != -1) {
                                f[i][j1][j2] = max(f[i][j1][j2], f[i - 1][y1][y2] + x);
                            }
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int j1 = 0; j1 < n; ++j1) {
            for (int j2 = 0; j2 < n; ++j2) {
                ans = max(ans, f[m - 1][j1][j2]);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func cherryPickup(grid [][]int) (ans int) {
	m, n := len(grid), len(grid[0])
	f := make([][][]int, m)
	for i := range f {
		f[i] = make([][]int, n)
		for j := range f[i] {
			f[i][j] = make([]int, n)
			for k := range f[i][j] {
				f[i][j][k] = -1
			}
		}
	}
	f[0][0][n-1] = grid[0][0] + grid[0][n-1]
	for i := 1; i < m; i++ {
		for j1 := 0; j1 < n; j1++ {
			for j2 := 0; j2 < n; j2++ {
				x := grid[i][j1]
				if j1 != j2 {
					x += grid[i][j2]
				}
				for y1 := j1 - 1; y1 <= j1+1; y1++ {
					for y2 := j2 - 1; y2 <= j2+1; y2++ {
						if y1 >= 0 && y1 < n && y2 >= 0 && y2 < n && f[i-1][y1][y2] != -1 {
							f[i][j1][j2] = max(f[i][j1][j2], f[i-1][y1][y2]+x)
						}
					}
				}
			}
		}
	}
	for j1 := 0; j1 < n; j1++ {
		ans = max(ans, slices.Max(f[m-1][j1]))
	}
	return
}
```

#### TypeScript

```ts
function cherryPickup(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;
    const f = Array.from({ length: m }, () =>
        Array.from({ length: n }, () => Array.from({ length: n }, () => -1)),
    );
    f[0][0][n - 1] = grid[0][0] + grid[0][n - 1];
    for (let i = 1; i < m; ++i) {
        for (let j1 = 0; j1 < n; ++j1) {
            for (let j2 = 0; j2 < n; ++j2) {
                const x = grid[i][j1] + (j1 === j2 ? 0 : grid[i][j2]);
                for (let y1 = j1 - 1; y1 <= j1 + 1; ++y1) {
                    for (let y2 = j2 - 1; y2 <= j2 + 1; ++y2) {
                        if (y1 >= 0 && y1 < n && y2 >= 0 && y2 < n && f[i - 1][y1][y2] !== -1) {
                            f[i][j1][j2] = Math.max(f[i][j1][j2], f[i - 1][y1][y2] + x);
                        }
                    }
                }
            }
        }
    }
    return Math.max(...f[m - 1].flat());
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划（空间优化）

注意到 $f[i][j_1][j_2]$ 的计算只和 $f[i-1][y_1][y_2]$ 有关，因此我们可以使用滚动数组优化空间复杂度，空间复杂度优化后的时间复杂度为 $O(n^2)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        f = [[-1] * n for _ in range(n)]
        g = [[-1] * n for _ in range(n)]
        f[0][n - 1] = grid[0][0] + grid[0][n - 1]
        for i in range(1, m):
            for j1 in range(n):
                for j2 in range(n):
                    x = grid[i][j1] + (0 if j1 == j2 else grid[i][j2])
                    for y1 in range(j1 - 1, j1 + 2):
                        for y2 in range(j2 - 1, j2 + 2):
                            if 0 <= y1 < n and 0 <= y2 < n and f[y1][y2] != -1:
                                g[j1][j2] = max(g[j1][j2], f[y1][y2] + x)
            f, g = g, f
        return max(f[j1][j2] for j1, j2 in product(range(n), range(n)))
```

#### Java

```java
class Solution {
    public int cherryPickup(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] f = new int[n][n];
        int[][] g = new int[n][n];
        for (int i = 0; i < n; ++i) {
            Arrays.fill(f[i], -1);
            Arrays.fill(g[i], -1);
        }
        f[0][n - 1] = grid[0][0] + grid[0][n - 1];
        for (int i = 1; i < m; ++i) {
            for (int j1 = 0; j1 < n; ++j1) {
                for (int j2 = 0; j2 < n; ++j2) {
                    int x = grid[i][j1] + (j1 == j2 ? 0 : grid[i][j2]);
                    for (int y1 = j1 - 1; y1 <= j1 + 1; ++y1) {
                        for (int y2 = j2 - 1; y2 <= j2 + 1; ++y2) {
                            if (y1 >= 0 && y1 < n && y2 >= 0 && y2 < n && f[y1][y2] != -1) {
                                g[j1][j2] = Math.max(g[j1][j2], f[y1][y2] + x);
                            }
                        }
                    }
                }
            }
            int[][] t = f;
            f = g;
            g = t;
        }
        int ans = 0;
        for (int j1 = 0; j1 < n; ++j1) {
            for (int j2 = 0; j2 < n; ++j2) {
                ans = Math.max(ans, f[j1][j2]);
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
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> f(n, vector<int>(n, -1));
        vector<vector<int>> g(n, vector<int>(n, -1));
        f[0][n - 1] = grid[0][0] + grid[0][n - 1];
        for (int i = 1; i < m; ++i) {
            for (int j1 = 0; j1 < n; ++j1) {
                for (int j2 = 0; j2 < n; ++j2) {
                    int x = grid[i][j1] + (j1 == j2 ? 0 : grid[i][j2]);
                    for (int y1 = j1 - 1; y1 <= j1 + 1; ++y1) {
                        for (int y2 = j2 - 1; y2 <= j2 + 1; ++y2) {
                            if (y1 >= 0 && y1 < n && y2 >= 0 && y2 < n && f[y1][y2] != -1) {
                                g[j1][j2] = max(g[j1][j2], f[y1][y2] + x);
                            }
                        }
                    }
                }
            }
            swap(f, g);
        }
        int ans = 0;
        for (int j1 = 0; j1 < n; ++j1) {
            for (int j2 = 0; j2 < n; ++j2) {
                ans = max(ans, f[j1][j2]);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func cherryPickup(grid [][]int) (ans int) {
	m, n := len(grid), len(grid[0])
	f := make([][]int, n)
	g := make([][]int, n)
	for i := range f {
		f[i] = make([]int, n)
		g[i] = make([]int, n)
		for j := range f[i] {
			f[i][j] = -1
			g[i][j] = -1
		}
	}
	f[0][n-1] = grid[0][0] + grid[0][n-1]
	for i := 1; i < m; i++ {
		for j1 := 0; j1 < n; j1++ {
			for j2 := 0; j2 < n; j2++ {
				x := grid[i][j1]
				if j1 != j2 {
					x += grid[i][j2]
				}
				for y1 := j1 - 1; y1 <= j1+1; y1++ {
					for y2 := j2 - 1; y2 <= j2+1; y2++ {
						if y1 >= 0 && y1 < n && y2 >= 0 && y2 < n && f[y1][y2] != -1 {
							g[j1][j2] = max(g[j1][j2], f[y1][y2]+x)
						}
					}
				}
			}
		}
		f, g = g, f
	}
	for j1 := 0; j1 < n; j1++ {
		ans = max(ans, slices.Max(f[j1]))
	}
	return
}
```

#### TypeScript

```ts
function cherryPickup(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;
    let f: number[][] = Array.from({ length: n }, () => Array.from({ length: n }, () => -1));
    let g: number[][] = Array.from({ length: n }, () => Array.from({ length: n }, () => -1));
    f[0][n - 1] = grid[0][0] + grid[0][n - 1];
    for (let i = 1; i < m; ++i) {
        for (let j1 = 0; j1 < n; ++j1) {
            for (let j2 = 0; j2 < n; ++j2) {
                const x = grid[i][j1] + (j1 === j2 ? 0 : grid[i][j2]);
                for (let y1 = j1 - 1; y1 <= j1 + 1; ++y1) {
                    for (let y2 = j2 - 1; y2 <= j2 + 1; ++y2) {
                        if (y1 >= 0 && y1 < n && y2 >= 0 && y2 < n && f[y1][y2] !== -1) {
                            g[j1][j2] = Math.max(g[j1][j2], f[y1][y2] + x);
                        }
                    }
                }
            }
        }
        [f, g] = [g, f];
    }
    return Math.max(...f.flat());
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1464. 数组中两元素的最大乘积](https://leetcode.cn/problems/maximum-product-of-two-elements-in-an-array){#1464}

{{< tabs "1464" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        a = b = 0
        for v in nums:
            if v > a:
                a, b = v, a
            elif v > b:
                b = v
        return (a - 1) * (b - 1)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxProduct(int[] nums) {
        int a = 0, b = 0;
        for (int v : nums) {
            if (v > a) {
                b = a;
                a = v;
            } else if (v > b) {
                b = v;
            }
        }
        return (a - 1) * (b - 1);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int a = 0, b = 0;
        for (int v : nums) {
            if (v > a) {
                b = a;
                a = v;
            } else if (v > b) {
                b = v;
            }
        }
        return (a - 1) * (b - 1);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxProduct(nums []int) int {
	a, b := 0, 0
	for _, v := range nums {
		if v > a {
			b, a = a, v
		} else if v > b {
			b = v
		}
	}
	return (a - 1) * (b - 1)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxProduct(nums: number[]): number {
    let max = 0;
    let submax = 0;
    for (const num of nums) {
        if (num > max) {
            submax = max;
            max = num;
        } else if (num > submax) {
            submax = num;
        }
    }
    return (max - 1) * (submax - 1);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn max_product(nums: Vec<i32>) -> i32 {
        let mut max = 0;
        let mut submax = 0;
        for &num in nums.iter() {
            if num > max {
                submax = max;
                max = num;
            } else if num > submax {
                submax = num;
            }
        }
        (max - 1) * (submax - 1)
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function maxProduct($nums) {
        $max = 0;
        $submax = 0;
        for ($i = 0; $i < count($nums); $i++) {
            if ($nums[$i] > $max) {
                $submax = $max;
                $max = $nums[$i];
            } elseif ($nums[$i] > $submax) {
                $submax = $nums[$i];
            }
        }
        return ($max - 1) * ($submax - 1);
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int maxProduct(int* nums, int numsSize) {
    int max = 0;
    int submax = 0;
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        if (num > max) {
            submax = max;
            max = num;
        } else if (num > submax) {
            submax = num;
        }
    }
    return (max - 1) * (submax - 1);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code>，请你选择数组的两个不同下标 <code>i</code> 和 <code>j</code><em>，</em>使 <code>(nums[i]-1)*(nums[j]-1)</code> 取得最大值。</p>

<p>请你计算并返回该式的最大值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [3,4,5,2]
<strong>输出：</strong>12 
<strong>解释：</strong>如果选择下标 i=1 和 j=2（下标从 0 开始），则可以获得最大值，(nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12 。 
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [1,5,4,5]
<strong>输出：</strong>16
<strong>解释：</strong>选择下标 i=1 和 j=3（下标从 0 开始），则可以获得最大值 (5-1)*(5-1) = 16 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [3,7]
<strong>输出：</strong>12
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 500</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10^3</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：暴力枚举

双重循环，枚举所有的下标对，求出 $(nums[i]-1) \times (nums[j]-1)$ 的最大值。其中 $i \neq j$。

时间复杂度 $O(n^2)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        ans = 0
        for i, a in enumerate(nums):
            for b in nums[i + 1 :]:
                ans = max(ans, (a - 1) * (b - 1))
        return ans
```

#### Java

```java
class Solution {
    public int maxProduct(int[] nums) {
        int ans = 0;
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ans = Math.max(ans, (nums[i] - 1) * (nums[j] - 1));
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
    int maxProduct(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ans = max(ans, (nums[i] - 1) * (nums[j] - 1));
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maxProduct(nums []int) int {
	ans := 0
	for i, a := range nums {
		for _, b := range nums[i+1:] {
			t := (a - 1) * (b - 1)
			if ans < t {
				ans = t
			}
		}
	}
	return ans
}
```

#### TypeScript

```ts
function maxProduct(nums: number[]): number {
    const n = nums.length;
    for (let i = 0; i < 2; i++) {
        let maxIdx = i;
        for (let j = i + 1; j < n; j++) {
            if (nums[j] > nums[maxIdx]) {
                maxIdx = j;
            }
        }
        [nums[i], nums[maxIdx]] = [nums[maxIdx], nums[i]];
    }
    return (nums[0] - 1) * (nums[1] - 1);
}
```

#### Rust

```rust
impl Solution {
    pub fn max_product(nums: Vec<i32>) -> i32 {
        let mut max = 0;
        let mut submax = 0;
        for &num in nums.iter() {
            if num > max {
                submax = max;
                max = num;
            } else if num > submax {
                submax = num;
            }
        }
        (max - 1) * (submax - 1)
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function maxProduct($nums) {
        $max = 0;
        $submax = 0;
        for ($i = 0; $i < count($nums); $i++) {
            if ($nums[$i] > $max) {
                $submax = $max;
                $max = $nums[$i];
            } elseif ($nums[$i] > $submax) {
                $submax = $nums[$i];
            }
        }
        return ($max - 1) * ($submax - 1);
    }
}
```

#### C

```c
int maxProduct(int* nums, int numsSize) {
    int max = 0;
    int submax = 0;
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        if (num > max) {
            submax = max;
            max = num;
        } else if (num > submax) {
            submax = num;
        }
    }
    return (max - 1) * (submax - 1);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：排序

对 $nums$ 进行排序，取最后两个元素，计算乘积 $(nums[n-1]-1) \times (nums[n-2]-1)$ 即可。

时间复杂度 $O(nlogn)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        nums.sort()
        return (nums[-1] - 1) * (nums[-2] - 1)
```

#### Java

```java
class Solution {
    public int maxProduct(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        return (nums[n - 1] - 1) * (nums[n - 2] - 1);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        return (nums[0] - 1) * (nums[1] - 1);
    }
};
```

#### Go

```go
func maxProduct(nums []int) int {
	sort.Ints(nums)
	n := len(nums)
	return (nums[n-1] - 1) * (nums[n-2] - 1)
}
```

#### TypeScript

```ts
function maxProduct(nums: number[]): number {
    let max = 0;
    let submax = 0;
    for (const num of nums) {
        if (num > max) {
            submax = max;
            max = num;
        } else if (num > submax) {
            submax = num;
        }
    }
    return (max - 1) * (submax - 1);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三：一次遍历

遍历 $nums$，维护最大值 $a$ 和次大值 $b$。遍历结束，返回 $(a-1) \times (b-1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        a = b = 0
        for v in nums:
            if v > a:
                a, b = v, a
            elif v > b:
                b = v
        return (a - 1) * (b - 1)
```

#### Java

```java
class Solution {
    public int maxProduct(int[] nums) {
        int a = 0, b = 0;
        for (int v : nums) {
            if (v > a) {
                b = a;
                a = v;
            } else if (v > b) {
                b = v;
            }
        }
        return (a - 1) * (b - 1);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int a = 0, b = 0;
        for (int v : nums) {
            if (v > a) {
                b = a;
                a = v;
            } else if (v > b) {
                b = v;
            }
        }
        return (a - 1) * (b - 1);
    }
};
```

#### Go

```go
func maxProduct(nums []int) int {
	a, b := 0, 0
	for _, v := range nums {
		if v > a {
			b, a = a, v
		} else if v > b {
			b = v
		}
	}
	return (a - 1) * (b - 1)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1465. 切割后面积最大的蛋糕](https://leetcode.cn/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts){#1465}

{{< tabs "1465" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxArea(
        self, h: int, w: int, horizontalCuts: List[int], verticalCuts: List[int]
    ) -> int:
        horizontalCuts.extend([0, h])
        verticalCuts.extend([0, w])
        horizontalCuts.sort()
        verticalCuts.sort()
        x = max(b - a for a, b in pairwise(horizontalCuts))
        y = max(b - a for a, b in pairwise(verticalCuts))
        return (x * y) % (10**9 + 7)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxArea(int h, int w, int[] horizontalCuts, int[] verticalCuts) {
        final int mod = (int) 1e9 + 7;
        Arrays.sort(horizontalCuts);
        Arrays.sort(verticalCuts);
        int m = horizontalCuts.length;
        int n = verticalCuts.length;
        long x = Math.max(horizontalCuts[0], h - horizontalCuts[m - 1]);
        long y = Math.max(verticalCuts[0], w - verticalCuts[n - 1]);
        for (int i = 1; i < m; ++i) {
            x = Math.max(x, horizontalCuts[i] - horizontalCuts[i - 1]);
        }
        for (int i = 1; i < n; ++i) {
            y = Math.max(y, verticalCuts[i] - verticalCuts[i - 1]);
        }
        return (int) ((x * y) % mod);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int x = 0, y = 0;
        for (int i = 1; i < horizontalCuts.size(); ++i) {
            x = max(x, horizontalCuts[i] - horizontalCuts[i - 1]);
        }
        for (int i = 1; i < verticalCuts.size(); ++i) {
            y = max(y, verticalCuts[i] - verticalCuts[i - 1]);
        }
        const int mod = 1e9 + 7;
        return (1ll * x * y) % mod;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxArea(h int, w int, horizontalCuts []int, verticalCuts []int) int {
	horizontalCuts = append(horizontalCuts, []int{0, h}...)
	verticalCuts = append(verticalCuts, []int{0, w}...)
	sort.Ints(horizontalCuts)
	sort.Ints(verticalCuts)
	x, y := 0, 0
	const mod int = 1e9 + 7
	for i := 1; i < len(horizontalCuts); i++ {
		x = max(x, horizontalCuts[i]-horizontalCuts[i-1])
	}
	for i := 1; i < len(verticalCuts); i++ {
		y = max(y, verticalCuts[i]-verticalCuts[i-1])
	}
	return (x * y) % mod
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxArea(h: number, w: number, horizontalCuts: number[], verticalCuts: number[]): number {
    const mod = 1e9 + 7;
    horizontalCuts.push(0, h);
    verticalCuts.push(0, w);
    horizontalCuts.sort((a, b) => a - b);
    verticalCuts.sort((a, b) => a - b);
    let [x, y] = [0, 0];
    for (let i = 1; i < horizontalCuts.length; i++) {
        x = Math.max(x, horizontalCuts[i] - horizontalCuts[i - 1]);
    }
    for (let i = 1; i < verticalCuts.length; i++) {
        y = Math.max(y, verticalCuts[i] - verticalCuts[i - 1]);
    }
    return Number((BigInt(x) * BigInt(y)) % BigInt(mod));
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn max_area(
        h: i32,
        w: i32,
        mut horizontal_cuts: Vec<i32>,
        mut vertical_cuts: Vec<i32>,
    ) -> i32 {
        const MOD: i64 = 1_000_000_007;

        horizontal_cuts.sort();
        vertical_cuts.sort();

        let m = horizontal_cuts.len();
        let n = vertical_cuts.len();

        let mut x = i64::max(
            horizontal_cuts[0] as i64,
            (h as i64) - (horizontal_cuts[m - 1] as i64),
        );
        let mut y = i64::max(
            vertical_cuts[0] as i64,
            (w as i64) - (vertical_cuts[n - 1] as i64),
        );

        for i in 1..m {
            x = i64::max(
                x,
                (horizontal_cuts[i] as i64) - (horizontal_cuts[i - 1] as i64),
            );
        }

        for i in 1..n {
            y = i64::max(y, (vertical_cuts[i] as i64) - (vertical_cuts[i - 1] as i64));
        }

        ((x * y) % MOD) as i32
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>矩形蛋糕的高度为 <code>h</code> 且宽度为 <code>w</code>，给你两个整数数组 <code>horizontalCuts</code> 和 <code>verticalCuts</code>，其中：</p>

<ul>
	<li>&nbsp;<code>horizontalCuts[i]</code> 是从矩形蛋糕顶部到第&nbsp; <code>i</code> 个水平切口的距离</li>
	<li><code>verticalCuts[j]</code> 是从矩形蛋糕的左侧到第 <code>j</code> 个竖直切口的距离</li>
</ul>

<p>请你按数组 <em><code>horizontalCuts</code> </em>和<em> <code>verticalCuts</code> </em>中提供的水平和竖直位置切割后，请你找出 <strong>面积最大</strong> 的那份蛋糕，并返回其 <strong>面积</strong> 。由于答案可能是一个很大的数字，因此需要将结果&nbsp;<strong>对</strong>&nbsp;<code>10<sup>9</sup>&nbsp;+ 7</code>&nbsp;<strong>取余</strong> 后返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1465.Maximum%20Area%20of%20a%20Piece%20of%20Cake%20After%20Horizontal%20and%20Vertical%20Cuts/images/leetcode_max_area_2.png" /></p>

<pre>
<strong>输入：</strong>h = 5, w = 4, horizontalCuts = [1,2,4], verticalCuts = [1,3]
<strong>输出：</strong>4 
<strong>解释：</strong>上图所示的矩阵蛋糕中，红色线表示水平和竖直方向上的切口。切割蛋糕后，绿色的那份蛋糕面积最大。
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1465.Maximum%20Area%20of%20a%20Piece%20of%20Cake%20After%20Horizontal%20and%20Vertical%20Cuts/images/leetcode_max_area_3.png" /></strong></p>

<pre>
<strong>输入：</strong>h = 5, w = 4, horizontalCuts = [3,1], verticalCuts = [1]
<strong>输出：</strong>6
<strong>解释：</strong>上图所示的矩阵蛋糕中，红色线表示水平和竖直方向上的切口。切割蛋糕后，绿色和黄色的两份蛋糕面积最大。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>h = 5, w = 4, horizontalCuts = [3], verticalCuts = [3]
<strong>输出：</strong>9
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= h, w &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= horizontalCuts.length &lt;= min(h - 1, 10<sup>5</sup>)</code></li>
	<li><code>1 &lt;= verticalCuts.length &lt;= min(w - 1, 10<sup>5</sup>)</code></li>
	<li><code>1 &lt;= horizontalCuts[i] &lt; h</code></li>
	<li><code>1 &lt;= verticalCuts[i] &lt; w</code></li>
	<li>题目数据保证 <code>horizontalCuts</code> 中的所有元素各不相同</li>
	<li>题目数据保证 <code>verticalCuts</code>&nbsp;中的所有元素各不相同</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序

我们先分别对 `horizontalCuts` 和 `verticalCuts` 排序，然后分别遍历两个数组，计算相邻两个元素的最大差值，分别记为 $x$ 和 $y$，最后返回 $x \times y$ 即可。

注意要考虑边界情况，即 `horizontalCuts` 和 `verticalCuts` 的首尾元素。

时间复杂度 $O(m\log m + n\log n)$，空间复杂度 $(\log m + \log n)$。其中 $m$ 和 $n$ 分别为 `horizontalCuts` 和 `verticalCuts` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxArea(
        self, h: int, w: int, horizontalCuts: List[int], verticalCuts: List[int]
    ) -> int:
        horizontalCuts.extend([0, h])
        verticalCuts.extend([0, w])
        horizontalCuts.sort()
        verticalCuts.sort()
        x = max(b - a for a, b in pairwise(horizontalCuts))
        y = max(b - a for a, b in pairwise(verticalCuts))
        return (x * y) % (10**9 + 7)
```

#### Java

```java
class Solution {
    public int maxArea(int h, int w, int[] horizontalCuts, int[] verticalCuts) {
        final int mod = (int) 1e9 + 7;
        Arrays.sort(horizontalCuts);
        Arrays.sort(verticalCuts);
        int m = horizontalCuts.length;
        int n = verticalCuts.length;
        long x = Math.max(horizontalCuts[0], h - horizontalCuts[m - 1]);
        long y = Math.max(verticalCuts[0], w - verticalCuts[n - 1]);
        for (int i = 1; i < m; ++i) {
            x = Math.max(x, horizontalCuts[i] - horizontalCuts[i - 1]);
        }
        for (int i = 1; i < n; ++i) {
            y = Math.max(y, verticalCuts[i] - verticalCuts[i - 1]);
        }
        return (int) ((x * y) % mod);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int x = 0, y = 0;
        for (int i = 1; i < horizontalCuts.size(); ++i) {
            x = max(x, horizontalCuts[i] - horizontalCuts[i - 1]);
        }
        for (int i = 1; i < verticalCuts.size(); ++i) {
            y = max(y, verticalCuts[i] - verticalCuts[i - 1]);
        }
        const int mod = 1e9 + 7;
        return (1ll * x * y) % mod;
    }
};
```

#### Go

```go
func maxArea(h int, w int, horizontalCuts []int, verticalCuts []int) int {
	horizontalCuts = append(horizontalCuts, []int{0, h}...)
	verticalCuts = append(verticalCuts, []int{0, w}...)
	sort.Ints(horizontalCuts)
	sort.Ints(verticalCuts)
	x, y := 0, 0
	const mod int = 1e9 + 7
	for i := 1; i < len(horizontalCuts); i++ {
		x = max(x, horizontalCuts[i]-horizontalCuts[i-1])
	}
	for i := 1; i < len(verticalCuts); i++ {
		y = max(y, verticalCuts[i]-verticalCuts[i-1])
	}
	return (x * y) % mod
}
```

#### TypeScript

```ts
function maxArea(h: number, w: number, horizontalCuts: number[], verticalCuts: number[]): number {
    const mod = 1e9 + 7;
    horizontalCuts.push(0, h);
    verticalCuts.push(0, w);
    horizontalCuts.sort((a, b) => a - b);
    verticalCuts.sort((a, b) => a - b);
    let [x, y] = [0, 0];
    for (let i = 1; i < horizontalCuts.length; i++) {
        x = Math.max(x, horizontalCuts[i] - horizontalCuts[i - 1]);
    }
    for (let i = 1; i < verticalCuts.length; i++) {
        y = Math.max(y, verticalCuts[i] - verticalCuts[i - 1]);
    }
    return Number((BigInt(x) * BigInt(y)) % BigInt(mod));
}
```

#### Rust

```rust
impl Solution {
    pub fn max_area(
        h: i32,
        w: i32,
        mut horizontal_cuts: Vec<i32>,
        mut vertical_cuts: Vec<i32>,
    ) -> i32 {
        const MOD: i64 = 1_000_000_007;

        horizontal_cuts.sort();
        vertical_cuts.sort();

        let m = horizontal_cuts.len();
        let n = vertical_cuts.len();

        let mut x = i64::max(
            horizontal_cuts[0] as i64,
            (h as i64) - (horizontal_cuts[m - 1] as i64),
        );
        let mut y = i64::max(
            vertical_cuts[0] as i64,
            (w as i64) - (vertical_cuts[n - 1] as i64),
        );

        for i in 1..m {
            x = i64::max(
                x,
                (horizontal_cuts[i] as i64) - (horizontal_cuts[i - 1] as i64),
            );
        }

        for i in 1..n {
            y = i64::max(y, (vertical_cuts[i] as i64) - (vertical_cuts[i - 1] as i64));
        }

        ((x * y) % MOD) as i32
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1466. 重新规划路线](https://leetcode.cn/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero){#1466}

{{< tabs "1466" >}}

{{% tab "python" %}}
```python
class Solution:
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        g = [[] for _ in range(n)]
        for a, b in connections:
            g[a].append((b, 1))
            g[b].append((a, 0))
        q = deque([0])
        vis = {0}
        ans = 0
        while q:
            a = q.popleft()
            for b, c in g[a]:
                if b not in vis:
                    vis.add(b)
                    q.append(b)
                    ans += c
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minReorder(int n, int[][] connections) {
        List<int[]>[] g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : connections) {
            int a = e[0], b = e[1];
            g[a].add(new int[] {b, 1});
            g[b].add(new int[] {a, 0});
        }
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(0);
        boolean[] vis = new boolean[n];
        vis[0] = true;
        int ans = 0;
        while (!q.isEmpty()) {
            int a = q.poll();
            for (var e : g[a]) {
                int b = e[0], c = e[1];
                if (!vis[b]) {
                    vis[b] = true;
                    q.offer(b);
                    ans += c;
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
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<pair<int, int>> g[n];
        for (auto& e : connections) {
            int a = e[0], b = e[1];
            g[a].emplace_back(b, 1);
            g[b].emplace_back(a, 0);
        }
        queue<int> q{{0}};
        vector<bool> vis(n);
        vis[0] = true;
        int ans = 0;
        while (q.size()) {
            int a = q.front();
            q.pop();
            for (auto& [b, c] : g[a]) {
                if (!vis[b]) {
                    vis[b] = true;
                    q.push(b);
                    ans += c;
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
func minReorder(n int, connections [][]int) (ans int) {
	g := make([][][2]int, n)
	for _, e := range connections {
		a, b := e[0], e[1]
		g[a] = append(g[a], [2]int{b, 1})
		g[b] = append(g[b], [2]int{a, 0})
	}
	q := []int{0}
	vis := make([]bool, n)
	vis[0] = true
	for len(q) > 0 {
		a := q[0]
		q = q[1:]
		for _, e := range g[a] {
			b, c := e[0], e[1]
			if !vis[b] {
				vis[b] = true
				q = append(q, b)
				ans += c
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minReorder(n: number, connections: number[][]): number {
    const g: [number, number][][] = Array.from({ length: n }, () => []);
    for (const [a, b] of connections) {
        g[a].push([b, 1]);
        g[b].push([a, 0]);
    }

    const q: number[] = [0];
    const vis = new Set<number>();
    vis.add(0);

    let ans = 0;
    while (q.length) {
        const a = q.pop()!;
        for (const [b, c] of g[a]) {
            if (!vis.has(b)) {
                vis.add(b);
                q.push(b);
                ans += c;
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
    pub fn min_reorder(n: i32, connections: Vec<Vec<i32>>) -> i32 {
        let mut g: Vec<Vec<(i32, i32)>> = vec![vec![]; n as usize];
        for e in connections.iter() {
            let a = e[0] as usize;
            let b = e[1] as usize;
            g[a].push((b as i32, 1));
            g[b].push((a as i32, 0));
        }
        fn dfs(a: usize, fa: i32, g: &Vec<Vec<(i32, i32)>>) -> i32 {
            let mut ans = 0;
            for &(b, c) in g[a].iter() {
                if b != fa {
                    ans += c + dfs(b as usize, a as i32, g);
                }
            }
            ans
        }
        dfs(0, -1, &g)
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><code>n</code> 座城市，从 <code>0</code> 到 <code>n-1</code> 编号，其间共有 <code>n-1</code> 条路线。因此，要想在两座不同城市之间旅行只有唯一一条路线可供选择（路线网形成一颗树）。去年，交通运输部决定重新规划路线，以改变交通拥堵的状况。</p>

<p>路线用 <code>connections</code> 表示，其中 <code>connections[i] = [a, b]</code> 表示从城市 <code>a</code> 到 <code>b</code> 的一条有向路线。</p>

<p>今年，城市 0 将会举办一场大型比赛，很多游客都想前往城市 0 。</p>

<p>请你帮助重新规划路线方向，使每个城市都可以访问城市 0 。返回需要变更方向的最小路线数。</p>

<p>题目数据 <strong>保证</strong> 每个城市在重新规划路线方向后都能到达城市 0 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1466.Reorder%20Routes%20to%20Make%20All%20Paths%20Lead%20to%20the%20City%20Zero/images/sample_1_1819.png" style="height: 150px; width: 240px;"></strong></p>

<pre><strong>输入：</strong>n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
<strong>输出：</strong>3
<strong>解释：</strong>更改以红色显示的路线的方向，使每个城市都可以到达城市 0 。</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1466.Reorder%20Routes%20to%20Make%20All%20Paths%20Lead%20to%20the%20City%20Zero/images/sample_2_1819.png" style="height: 60px; width: 380px;"></strong></p>

<pre><strong>输入：</strong>n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
<strong>输出：</strong>2
<strong>解释：</strong>更改以红色显示的路线的方向，使每个城市都可以到达城市 0 。</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>n = 3, connections = [[1,0],[2,0]]
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 5 * 10^4</code></li>
	<li><code>connections.length == n-1</code></li>
	<li><code>connections[i].length == 2</code></li>
	<li><code>0 &lt;= connections[i][0], connections[i][1] &lt;= n-1</code></li>
	<li><code>connections[i][0] != connections[i][1]</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

题目给定的路线图中有 $n$ 个节点和 $n-1$ 条边，如果我们忽略边的方向，那么这 $n$ 个节点构成了一棵树。而题目需要我们改变某些边的方向，使得每个节点都能到达节点 $0$。

我们不妨考虑从节点 $0$ 出发，到达其他所有节点。方向与题目描述相反，意味着我们在构建图的时候，对于有向边 $[a, b]$，我们应该视为有向边 $[b, a]$。也即是说，如果要从 $a$ 到 $b$，我们需要变更一次方向；如果要从 $b$ 到 $a$，则不需要变更方向。

接下来，我们只需要从节点 $0$ 出发，搜索其他所有节点，过程中，如果遇到需要变更方向的边，则累加一次变更方向的次数。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是题目中节点的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        def dfs(a: int, fa: int) -> int:
            return sum(c + dfs(b, a) for b, c in g[a] if b != fa)

        g = [[] for _ in range(n)]
        for a, b in connections:
            g[a].append((b, 1))
            g[b].append((a, 0))
        return dfs(0, -1)
```

#### Java

```java
class Solution {
    private List<int[]>[] g;

    public int minReorder(int n, int[][] connections) {
        g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : connections) {
            int a = e[0], b = e[1];
            g[a].add(new int[] {b, 1});
            g[b].add(new int[] {a, 0});
        }
        return dfs(0, -1);
    }

    private int dfs(int a, int fa) {
        int ans = 0;
        for (var e : g[a]) {
            int b = e[0], c = e[1];
            if (b != fa) {
                ans += c + dfs(b, a);
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
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<pair<int, int>> g[n];
        for (auto& e : connections) {
            int a = e[0], b = e[1];
            g[a].emplace_back(b, 1);
            g[b].emplace_back(a, 0);
        }
        function<int(int, int)> dfs = [&](int a, int fa) {
            int ans = 0;
            for (auto& [b, c] : g[a]) {
                if (b != fa) {
                    ans += c + dfs(b, a);
                }
            }
            return ans;
        };
        return dfs(0, -1);
    }
};
```

#### Go

```go
func minReorder(n int, connections [][]int) int {
	g := make([][][2]int, n)
	for _, e := range connections {
		a, b := e[0], e[1]
		g[a] = append(g[a], [2]int{b, 1})
		g[b] = append(g[b], [2]int{a, 0})
	}
	var dfs func(int, int) int
	dfs = func(a, fa int) (ans int) {
		for _, e := range g[a] {
			if b, c := e[0], e[1]; b != fa {
				ans += c + dfs(b, a)
			}
		}
		return
	}
	return dfs(0, -1)
}
```

#### TypeScript

```ts
function minReorder(n: number, connections: number[][]): number {
    const g: [number, number][][] = Array.from({ length: n }, () => []);
    for (const [a, b] of connections) {
        g[a].push([b, 1]);
        g[b].push([a, 0]);
    }
    const dfs = (a: number, fa: number): number => {
        let ans = 0;
        for (const [b, c] of g[a]) {
            if (b !== fa) {
                ans += c + dfs(b, a);
            }
        }
        return ans;
    };
    return dfs(0, -1);
}
```

#### Rust

```rust
impl Solution {
    pub fn min_reorder(n: i32, connections: Vec<Vec<i32>>) -> i32 {
        let mut g: Vec<Vec<(i32, i32)>> = vec![vec![]; n as usize];
        for e in connections.iter() {
            let a = e[0] as usize;
            let b = e[1] as usize;
            g[a].push((b as i32, 1));
            g[b].push((a as i32, 0));
        }
        fn dfs(a: usize, fa: i32, g: &Vec<Vec<(i32, i32)>>) -> i32 {
            let mut ans = 0;
            for &(b, c) in g[a].iter() {
                if b != fa {
                    ans += c + dfs(b as usize, a as i32, g);
                }
            }
            ans
        }
        dfs(0, -1, &g)
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：BFS

我们可以使用广度优先搜索的方法，从节点 $0$ 出发，搜索其他所有节点，过程中，如果遇到需要变更方向的边，则累加一次变更方向的次数。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是题目中节点的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        g = [[] for _ in range(n)]
        for a, b in connections:
            g[a].append((b, 1))
            g[b].append((a, 0))
        q = deque([0])
        vis = {0}
        ans = 0
        while q:
            a = q.popleft()
            for b, c in g[a]:
                if b not in vis:
                    vis.add(b)
                    q.append(b)
                    ans += c
        return ans
```

```java
class Solution {
    public int minReorder(int n, int[][] connections) {
        List<int[]>[] g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : connections) {
            int a = e[0], b = e[1];
            g[a].add(new int[] {b, 1});
            g[b].add(new int[] {a, 0});
        }
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(0);
        boolean[] vis = new boolean[n];
        vis[0] = true;
        int ans = 0;
        while (!q.isEmpty()) {
            int a = q.poll();
            for (var e : g[a]) {
                int b = e[0], c = e[1];
                if (!vis[b]) {
                    vis[b] = true;
                    q.offer(b);
                    ans += c;
                }
            }
        }
        return ans;
    }
}
```

```cpp
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<pair<int, int>> g[n];
        for (auto& e : connections) {
            int a = e[0], b = e[1];
            g[a].emplace_back(b, 1);
            g[b].emplace_back(a, 0);
        }
        queue<int> q{{0}};
        vector<bool> vis(n);
        vis[0] = true;
        int ans = 0;
        while (q.size()) {
            int a = q.front();
            q.pop();
            for (auto& [b, c] : g[a]) {
                if (!vis[b]) {
                    vis[b] = true;
                    q.push(b);
                    ans += c;
                }
            }
        }
        return ans;
    }
};
```

```go
func minReorder(n int, connections [][]int) (ans int) {
	g := make([][][2]int, n)
	for _, e := range connections {
		a, b := e[0], e[1]
		g[a] = append(g[a], [2]int{b, 1})
		g[b] = append(g[b], [2]int{a, 0})
	}
	q := []int{0}
	vis := make([]bool, n)
	vis[0] = true
	for len(q) > 0 {
		a := q[0]
		q = q[1:]
		for _, e := range g[a] {
			b, c := e[0], e[1]
			if !vis[b] {
				vis[b] = true
				q = append(q, b)
				ans += c
			}
		}
	}
	return
}
```

```ts
function minReorder(n: number, connections: number[][]): number {
    const g: [number, number][][] = Array.from({ length: n }, () => []);
    for (const [a, b] of connections) {
        g[a].push([b, 1]);
        g[b].push([a, 0]);
    }

    const q: number[] = [0];
    const vis = new Set<number>();
    vis.add(0);

    let ans = 0;
    while (q.length) {
        const a = q.pop()!;
        for (const [b, c] of g[a]) {
            if (!vis.has(b)) {
                vis.add(b);
                q.push(b);
                ans += c;
            }
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

# [1467. 两个盒子中球的颜色数相同的概率](https://leetcode.cn/problems/probability-of-a-two-boxes-having-the-same-number-of-distinct-balls){#1467}

{{< tabs "1467" >}}

{{% tab "python" %}}
```python
class Solution:
    def getProbability(self, balls: List[int]) -> float:
        @cache
        def dfs(i: int, j: int, diff: int) -> float:
            if i >= k:
                return 1 if j == 0 and diff == 0 else 0
            if j < 0:
                return 0
            ans = 0
            for x in range(balls[i] + 1):
                y = 1 if x == balls[i] else (-1 if x == 0 else 0)
                ans += dfs(i + 1, j - x, diff + y) * comb(balls[i], x)
            return ans

        n = sum(balls) >> 1
        k = len(balls)
        return dfs(0, n, 0) / comb(n << 1, n)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int n;
    private long[][] c;
    private int[] balls;
    private Map<List<Integer>, Long> f = new HashMap<>();

    public double getProbability(int[] balls) {
        int mx = 0;
        for (int x : balls) {
            n += x;
            mx = Math.max(mx, x);
        }
        n >>= 1;
        this.balls = balls;
        int m = Math.max(mx, n << 1);
        c = new long[m + 1][m + 1];
        for (int i = 0; i <= m; ++i) {
            c[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            }
        }
        return dfs(0, n, 0) * 1.0 / c[n << 1][n];
    }

    private long dfs(int i, int j, int diff) {
        if (i >= balls.length) {
            return j == 0 && diff == 0 ? 1 : 0;
        }
        if (j < 0) {
            return 0;
        }
        List<Integer> key = List.of(i, j, diff);
        if (f.containsKey(key)) {
            return f.get(key);
        }
        long ans = 0;
        for (int x = 0; x <= balls[i]; ++x) {
            int y = x == balls[i] ? 1 : (x == 0 ? -1 : 0);
            ans += dfs(i + 1, j - x, diff + y) * c[balls[i]][x];
        }
        f.put(key, ans);
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    double getProbability(vector<int>& balls) {
        int n = accumulate(balls.begin(), balls.end(), 0) / 2;
        int mx = *max_element(balls.begin(), balls.end());
        int m = max(mx, n << 1);
        long long c[m + 1][m + 1];
        memset(c, 0, sizeof(c));
        for (int i = 0; i <= m; ++i) {
            c[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            }
        }
        int k = balls.size();
        long long f[k][n + 1][k << 1 | 1];
        memset(f, -1, sizeof(f));
        function<long long(int, int, int)> dfs = [&](int i, int j, int diff) -> long long {
            if (i >= k) {
                return j == 0 && diff == k ? 1 : 0;
            }
            if (j < 0) {
                return 0;
            }
            if (f[i][j][diff] != -1) {
                return f[i][j][diff];
            }
            long long ans = 0;
            for (int x = 0; x <= balls[i]; ++x) {
                int y = x == balls[i] ? 1 : (x == 0 ? -1 : 0);
                ans += dfs(i + 1, j - x, diff + y) * c[balls[i]][x];
            }
            return f[i][j][diff] = ans;
        };
        return dfs(0, n, k) * 1.0 / c[n << 1][n];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getProbability(balls []int) float64 {
	n, mx := 0, 0
	for _, x := range balls {
		n += x
		mx = max(mx, x)
	}
	n >>= 1
	m := max(mx, n<<1)
	c := make([][]int, m+1)
	for i := range c {
		c[i] = make([]int, m+1)
	}
	for i := 0; i <= m; i++ {
		c[i][0] = 1
		for j := 1; j <= i; j++ {
			c[i][j] = c[i-1][j-1] + c[i-1][j]
		}
	}
	k := len(balls)
	f := make([][][]int, k)
	for i := range f {
		f[i] = make([][]int, n+1)
		for j := range f[i] {
			f[i][j] = make([]int, k<<1|1)
			for h := range f[i][j] {
				f[i][j][h] = -1
			}
		}
	}
	var dfs func(int, int, int) int
	dfs = func(i, j, diff int) int {
		if i >= k {
			if j == 0 && diff == k {
				return 1
			}
			return 0
		}
		if j < 0 {
			return 0
		}
		if f[i][j][diff] != -1 {
			return f[i][j][diff]
		}
		ans := 0
		for x := 0; x <= balls[i]; x++ {
			y := 1
			if x != balls[i] {
				if x == 0 {
					y = -1
				} else {
					y = 0
				}
			}
			ans += dfs(i+1, j-x, diff+y) * c[balls[i]][x]
		}
		f[i][j][diff] = ans
		return ans
	}
	return float64(dfs(0, n, k)) / float64(c[n<<1][n])
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function getProbability(balls: number[]): number {
    const n = balls.reduce((a, b) => a + b, 0) >> 1;
    const mx = Math.max(...balls);
    const m = Math.max(mx, n << 1);
    const c: number[][] = Array(m + 1)
        .fill(0)
        .map(() => Array(m + 1).fill(0));
    for (let i = 0; i <= m; ++i) {
        c[i][0] = 1;
        for (let j = 1; j <= i; ++j) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
    const k = balls.length;
    const f: number[][][] = Array(k)
        .fill(0)
        .map(() =>
            Array(n + 1)
                .fill(0)
                .map(() => Array((k << 1) | 1).fill(-1)),
        );
    const dfs = (i: number, j: number, diff: number): number => {
        if (i >= k) {
            return j === 0 && diff === k ? 1 : 0;
        }
        if (j < 0) {
            return 0;
        }
        if (f[i][j][diff] !== -1) {
            return f[i][j][diff];
        }
        let ans = 0;
        for (let x = 0; x <= balls[i]; ++x) {
            const y = x === balls[i] ? 1 : x === 0 ? -1 : 0;
            ans += dfs(i + 1, j - x, diff + y) * c[balls[i]][x];
        }
        return (f[i][j][diff] = ans);
    };
    return dfs(0, n, k) / c[n << 1][n];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>桌面上有 <code>2n</code> 个颜色不完全相同的球，球的颜色共有 <code>k</code> 种。给你一个大小为 <code>k</code> 的整数数组 <code>balls</code> ，其中 <code>balls[i]</code> 是颜色为&nbsp;<code>i</code> 的球的数量。</p>

<p>所有的球都已经 <strong>随机打乱顺序</strong> ，前 <code>n</code> 个球放入第一个盒子，后 <code>n</code> 个球放入另一个盒子（请认真阅读示例 2 的解释部分）。</p>

<p><strong>注意：</strong>这两个盒子是不同的。例如，两个球颜色分别为 <code>a</code> 和 <code>b</code>，盒子分别为 <code>[]</code> 和 <code>()</code>，那么 <code>[a] (b)</code> 和 <code>[b] (a)</code> 这两种分配方式是不同的（请认真阅读示例的解释部分）。</p>

<p>请返回「两个盒子中球的颜色数相同」的情况的概率。答案与真实值误差在 <code>10<sup>-5</sup></code> 以内，则被视为正确答案</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>balls = [1,1]
<strong>输出：</strong>1.00000
<strong>解释：</strong>球平均分配的方式只有两种：
- 颜色为 1 的球放入第一个盒子，颜色为 2 的球放入第二个盒子
- 颜色为 2 的球放入第一个盒子，颜色为 1 的球放入第二个盒子
这两种分配，两个盒子中球的颜色数都相同。所以概率为 2/2 = 1 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>balls = [2,1,1]
<strong>输出：</strong>0.66667
<strong>解释：</strong>球的列表为 [1, 1, 2, 3]
随机打乱，得到 12 种等概率的不同打乱方案，每种方案概率为 1/12 ：
[1,1 / 2,3], [1,1 / 3,2], [1,2 / 1,3], [1,2 / 3,1], [1,3 / 1,2], [1,3 / 2,1], [2,1 / 1,3], [2,1 / 3,1], [2,3 / 1,1], [3,1 / 1,2], [3,1 / 2,1], [3,2 / 1,1]
然后，我们将前两个球放入第一个盒子，后两个球放入第二个盒子。
这 12 种可能的随机打乱方式中的 8 种满足「两个盒子中球的颜色数相同」。
概率 = 8/12 = 0.66667
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>balls = [1,2,1,2]
<strong>输出：</strong>0.60000
<strong>解释：</strong>球的列表为 [1, 2, 2, 3, 4, 4]。要想显示所有 180 种随机打乱方案是很难的，但只检查「两个盒子中球的颜色数相同」的 108 种情况是比较容易的。
概率 = 108 / 180 = 0.6 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= balls.length &lt;= 8</code></li>
	<li><code>1 &lt;= balls[i] &lt;= 6</code></li>
	<li><code>sum(balls)</code> 是偶数</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索 + 组合数学

我们知道 $2n$ 个球，平均分到两个盒子中，总共有 $C_{2n}^n$ 种分法。接下来，我们可以求出每种分法中，两个盒子中球的颜色数相同的情况数。最后，将两者相除即可。

我们可以预处理出组合数 $C_{n}^m$，然后使用记忆化搜索求解。

设计一个函数 $dfs(i, j, diff)$，表示当前从第 $i$ 种球开始，第一个盒子剩余可放置 $j$ 个球，两个盒子中球的颜色数的差为 $diff$ 的方案数。

函数 $dfs(i, j, diff)$ 的执行逻辑如下：

-   如果 $i \geq k$，表示所有球都已经放完，如果 $j = 0$ 且 $diff = 0$，表示两个盒子中球的颜色数相同，返回 $1$，否则返回 $0$；
-   如果 $j < 0$，表示第一个盒子中球的数量超过了 $n$，返回 $0$；
-   如果 $f[i][j][diff]$ 不为 $-1$，表示已经计算过，直接返回 $f[i][j][diff]$；
-   否则，枚举第 $i$ 种球放入第一个盒子中的数量 $x$，则第 $i$ 种球放入第二个盒子中的数量为 $balls[i] - x$，两个盒子中球的颜色数的变化量为 $y$。如果所有球都放入第一个盒子中，那么 $y = 1$；如果所有球都放入第二个盒子中，那么 $y = -1$；否则 $y = 0$。然后，递归计算 $dfs(i + 1, j - x, diff + y)$，并将结果与 $C_{balls[i]}^x$ 相乘，累加到答案中。最后，将答案存入 $f[i][j][diff]$ 中，并返回答案。

时间复杂度 $O(n^2 \times k^2)$，空间复杂度 $O(n \times k^2)$。其中 $n$ 和 $k$ 分别是球的总数和颜色的种数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getProbability(self, balls: List[int]) -> float:
        @cache
        def dfs(i: int, j: int, diff: int) -> float:
            if i >= k:
                return 1 if j == 0 and diff == 0 else 0
            if j < 0:
                return 0
            ans = 0
            for x in range(balls[i] + 1):
                y = 1 if x == balls[i] else (-1 if x == 0 else 0)
                ans += dfs(i + 1, j - x, diff + y) * comb(balls[i], x)
            return ans

        n = sum(balls) >> 1
        k = len(balls)
        return dfs(0, n, 0) / comb(n << 1, n)
```

#### Java

```java
class Solution {
    private int n;
    private long[][] c;
    private int[] balls;
    private Map<List<Integer>, Long> f = new HashMap<>();

    public double getProbability(int[] balls) {
        int mx = 0;
        for (int x : balls) {
            n += x;
            mx = Math.max(mx, x);
        }
        n >>= 1;
        this.balls = balls;
        int m = Math.max(mx, n << 1);
        c = new long[m + 1][m + 1];
        for (int i = 0; i <= m; ++i) {
            c[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            }
        }
        return dfs(0, n, 0) * 1.0 / c[n << 1][n];
    }

    private long dfs(int i, int j, int diff) {
        if (i >= balls.length) {
            return j == 0 && diff == 0 ? 1 : 0;
        }
        if (j < 0) {
            return 0;
        }
        List<Integer> key = List.of(i, j, diff);
        if (f.containsKey(key)) {
            return f.get(key);
        }
        long ans = 0;
        for (int x = 0; x <= balls[i]; ++x) {
            int y = x == balls[i] ? 1 : (x == 0 ? -1 : 0);
            ans += dfs(i + 1, j - x, diff + y) * c[balls[i]][x];
        }
        f.put(key, ans);
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    double getProbability(vector<int>& balls) {
        int n = accumulate(balls.begin(), balls.end(), 0) / 2;
        int mx = *max_element(balls.begin(), balls.end());
        int m = max(mx, n << 1);
        long long c[m + 1][m + 1];
        memset(c, 0, sizeof(c));
        for (int i = 0; i <= m; ++i) {
            c[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            }
        }
        int k = balls.size();
        long long f[k][n + 1][k << 1 | 1];
        memset(f, -1, sizeof(f));
        function<long long(int, int, int)> dfs = [&](int i, int j, int diff) -> long long {
            if (i >= k) {
                return j == 0 && diff == k ? 1 : 0;
            }
            if (j < 0) {
                return 0;
            }
            if (f[i][j][diff] != -1) {
                return f[i][j][diff];
            }
            long long ans = 0;
            for (int x = 0; x <= balls[i]; ++x) {
                int y = x == balls[i] ? 1 : (x == 0 ? -1 : 0);
                ans += dfs(i + 1, j - x, diff + y) * c[balls[i]][x];
            }
            return f[i][j][diff] = ans;
        };
        return dfs(0, n, k) * 1.0 / c[n << 1][n];
    }
};
```

#### Go

```go
func getProbability(balls []int) float64 {
	n, mx := 0, 0
	for _, x := range balls {
		n += x
		mx = max(mx, x)
	}
	n >>= 1
	m := max(mx, n<<1)
	c := make([][]int, m+1)
	for i := range c {
		c[i] = make([]int, m+1)
	}
	for i := 0; i <= m; i++ {
		c[i][0] = 1
		for j := 1; j <= i; j++ {
			c[i][j] = c[i-1][j-1] + c[i-1][j]
		}
	}
	k := len(balls)
	f := make([][][]int, k)
	for i := range f {
		f[i] = make([][]int, n+1)
		for j := range f[i] {
			f[i][j] = make([]int, k<<1|1)
			for h := range f[i][j] {
				f[i][j][h] = -1
			}
		}
	}
	var dfs func(int, int, int) int
	dfs = func(i, j, diff int) int {
		if i >= k {
			if j == 0 && diff == k {
				return 1
			}
			return 0
		}
		if j < 0 {
			return 0
		}
		if f[i][j][diff] != -1 {
			return f[i][j][diff]
		}
		ans := 0
		for x := 0; x <= balls[i]; x++ {
			y := 1
			if x != balls[i] {
				if x == 0 {
					y = -1
				} else {
					y = 0
				}
			}
			ans += dfs(i+1, j-x, diff+y) * c[balls[i]][x]
		}
		f[i][j][diff] = ans
		return ans
	}
	return float64(dfs(0, n, k)) / float64(c[n<<1][n])
}
```

#### TypeScript

```ts
function getProbability(balls: number[]): number {
    const n = balls.reduce((a, b) => a + b, 0) >> 1;
    const mx = Math.max(...balls);
    const m = Math.max(mx, n << 1);
    const c: number[][] = Array(m + 1)
        .fill(0)
        .map(() => Array(m + 1).fill(0));
    for (let i = 0; i <= m; ++i) {
        c[i][0] = 1;
        for (let j = 1; j <= i; ++j) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
    const k = balls.length;
    const f: number[][][] = Array(k)
        .fill(0)
        .map(() =>
            Array(n + 1)
                .fill(0)
                .map(() => Array((k << 1) | 1).fill(-1)),
        );
    const dfs = (i: number, j: number, diff: number): number => {
        if (i >= k) {
            return j === 0 && diff === k ? 1 : 0;
        }
        if (j < 0) {
            return 0;
        }
        if (f[i][j][diff] !== -1) {
            return f[i][j][diff];
        }
        let ans = 0;
        for (let x = 0; x <= balls[i]; ++x) {
            const y = x === balls[i] ? 1 : x === 0 ? -1 : 0;
            ans += dfs(i + 1, j - x, diff + y) * c[balls[i]][x];
        }
        return (f[i][j][diff] = ans);
    };
    return dfs(0, n, k) / c[n << 1][n];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1468. 计算税后工资 🔒](https://leetcode.cn/problems/calculate-salaries){#1468}

{{< tabs "1468" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    s.company_id,
    employee_id,
    employee_name,
    ROUND(
        CASE
            WHEN top < 1000 THEN salary
            WHEN top >= 1000
            AND top <= 10000 THEN salary * 0.76
            ELSE salary * 0.51
        END
    ) AS salary
FROM
    Salaries AS s
    JOIN (
        SELECT company_id, MAX(salary) AS top
        FROM Salaries
        GROUP BY company_id
    ) AS t
        ON s.company_id = t.company_id;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><code>Salaries</code> 表：</p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| company_id    | int     |
| employee_id   | int     |
| employee_name | varchar |
| salary        | int     |
+---------------+---------+
在 SQL 中，(company_id, employee_id) 是这个表的主键
这个表包括员工的company id, id, name 和 salary 
</pre>

<p>&nbsp;</p>

<p>查找出每个员工的税后工资</p>

<p>每个公司的税率计算依照以下规则</p>

<ul>
	<li>如果这个公司员工最高工资不到 <code>$1000</code> ，税率为 <code>0%</code></li>
	<li>如果这个公司员工最高工资在 <code>[1000, 10000]</code> 之间，税率为 <code>24%</code></li>
	<li>如果这个公司员工最高工资大于 <code>$10000</code> ，税率为 <code>49%</code></li>
</ul>

<p>按 <strong>任意顺序</strong> 返回结果。</p>

<p>返回结果的格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Salaries 表：
+------------+-------------+---------------+--------+
| company_id | employee_id | employee_name | salary |
+------------+-------------+---------------+--------+
| 1          | 1           | Tony          | 2000   |
| 1          | 2           | Pronub        | 21300  |
| 1          | 3           | Tyrrox        | 10800  |
| 2          | 1           | Pam           | 300    |
| 2          | 7           | Bassem        | 450    |
| 2          | 9           | Hermione      | 700    |
| 3          | 7           | Bocaben       | 100    |
| 3          | 2           | Ognjen        | 2200   |
| 3          | 13          | Nyancat       | 3300   |
| 3          | 15          | Morninngcat   | 7777   |
+------------+-------------+---------------+--------+
<strong>输出：</strong>
+------------+-------------+---------------+--------+
| company_id | employee_id | employee_name | salary |
+------------+-------------+---------------+--------+
| 1          | 1           | Tony          | 1020   |
| 1          | 2           | Pronub        | 10863  |
| 1          | 3           | Tyrrox        | 5508   |
| 2          | 1           | Pam           | 300    |
| 2          | 7           | Bassem        | 450    |
| 2          | 9           | Hermione      | 700    |
| 3          | 7           | Bocaben       | 76     |
| 3          | 2           | Ognjen        | 1672   |
| 3          | 13          | Nyancat       | 2508   |
| 3          | 15          | Morninngcat   | 5911   |
+------------+-------------+---------------+--------+
<strong>解释：</strong>
对于公司 1，最高薪资为 21300。公司 1 的员工税率为 49%。
对于公司 2，最高薪资为 700。公司 2 的员工税率为 0%。
对于公司 3，最高薪资为 7777。公司 3 的员工税率为 24%。
薪资扣除税后的金额计算公式为：薪资 - (税率百分比 / 100) * 薪资
例如，Morninngcat（员工号 3，薪资为 7777）扣除税后的薪资为：7777 - 7777 * (24 / 100) = 7777 - 1866.48 = 5910.52，四舍五入为 5911。</pre>

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
    s.company_id,
    employee_id,
    employee_name,
    ROUND(
        CASE
            WHEN top < 1000 THEN salary
            WHEN top >= 1000
            AND top <= 10000 THEN salary * 0.76
            ELSE salary * 0.51
        END
    ) AS salary
FROM
    Salaries AS s
    JOIN (
        SELECT company_id, MAX(salary) AS top
        FROM Salaries
        GROUP BY company_id
    ) AS t
        ON s.company_id = t.company_id;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1469. 寻找所有的独生节点 🔒](https://leetcode.cn/problems/find-all-the-lonely-nodes){#1469}

{{< tabs "1469" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getLonelyNodes(self, root: Optional[TreeNode]) -> List[int]:
        def dfs(root: Optional[TreeNode]):
            if root is None or root.left == root.right:
                return
            if root.left is None:
                ans.append(root.right.val)
            if root.right is None:
                ans.append(root.left.val)
            dfs(root.left)
            dfs(root.right)

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
    private List<Integer> ans = new ArrayList<>();

    public List<Integer> getLonelyNodes(TreeNode root) {
        dfs(root);
        return ans;
    }

    private void dfs(TreeNode root) {
        if (root == null || (root.left == root.right)) {
            return;
        }
        if (root.left == null) {
            ans.add(root.right.val);
        }
        if (root.right == null) {
            ans.add(root.left.val);
        }
        dfs(root.left);
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
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> ans;
        auto dfs = [&](this auto&& dfs, TreeNode* root) {
            if (!root || (root->left == root->right)) {
                return;
            }
            if (!root->left) {
                ans.push_back(root->right->val);
            }
            if (!root->right) {
                ans.push_back(root->left->val);
            }
            dfs(root->left);
            dfs(root->right);
        };
        dfs(root);
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
 func getLonelyNodes(root *TreeNode) (ans []int) {
	var dfs func(*TreeNode)
	dfs = func(root *TreeNode) {
		if root == nil || (root.Left == root.Right) {
			return
		}
		if root.Left == nil {
			ans = append(ans, root.Right.Val)
		}
		if root.Right == nil {
			ans = append(ans, root.Left.Val)
		}
		dfs(root.Left)
		dfs(root.Right)
	}
	dfs(root)
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

function getLonelyNodes(root: TreeNode | null): number[] {
    const ans: number[] = [];
    const dfs = (root: TreeNode | null) => {
        if (!root || root.left === root.right) {
            return;
        }
        if (!root.left) {
            ans.push(root.right.val);
        }
        if (!root.right) {
            ans.push(root.left.val);
        }
        dfs(root.left);
        dfs(root.right);
    };
    dfs(root);
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>二叉树中，如果一个节点是其父节点的唯一子节点，则称这样的节点为 “<strong>独生节点</strong>” 。二叉树的根节点不会是独生节点，因为它没有父节点。</p>

<p>给定一棵二叉树的根节点&nbsp;<code>root</code> ，返回树中<strong> 所有的独生节点的值所构成的数组</strong> 。数组的顺序<strong> 不限 </strong>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1469.Find%20All%20The%20Lonely%20Nodes/images/e1.png" style="height:202px; width:203px" /></p>

<pre>
<strong>输入：</strong>root = [1,2,3,null,4]
<strong>输出：</strong>[4]
<strong>解释：</strong>浅蓝色的节点是唯一的独生节点。
节点 1 是根节点，不是独生的。
节点 2 和 3 有共同的父节点，所以它们都不是独生的。
</pre>

<p><strong class="example">示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1469.Find%20All%20The%20Lonely%20Nodes/images/e2.png" style="height:282px; width:442px" /></p>

<pre>
<strong>输入：</strong>root = [7,1,4,6,null,5,3,null,null,null,null,null,2]
<strong>输出：</strong>[6,2]
<strong>输出：</strong>浅蓝色的节点是独生节点。
请谨记，顺序是不限的。 [2,6] 也是一种可接受的答案。
</pre>

<p><strong class="example">示例 3：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1469.Find%20All%20The%20Lonely%20Nodes/images/tree.png" style="height:202px; width:363px" /> </strong></p>

<pre>
<strong>输入：</strong>root = [11,99,88,77,null,null,66,55,null,null,44,33,null,null,22]
<strong>输出：</strong>[77,55,33,66,44,22]
<strong>解释：</strong>节点 99 和 88 有共同的父节点，节点 11 是根节点。
其他所有节点都是独生节点。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>tree</code>&nbsp;中节点个数的取值范围是&nbsp;<code>[1, 1000]</code>。</li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们可以使用深度优先搜索遍历整棵树，设计一个函数 $\textit{dfs}$，它的作用是遍历树中的每个节点，如果当前节点是独生节点，那么将其值加入答案数组中。函数 $\textit{dfs}$ 的执行过程如下：

1. 如果当前节点为空，或者当前节点是叶子节点，即当前节点的左右子节点都为空，那么直接返回。
2. 如果当前节点的左子节点为空，那么将当前节点的右子节点是独生节点，将其值加入答案数组中。
3. 如果当前节点的右子节点为空，那么将当前节点的左子节点是独生节点，将其值加入答案数组中。
4. 递归遍历当前节点的左子节点和右子节点。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是二叉树中节点的个数。

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
    def getLonelyNodes(self, root: Optional[TreeNode]) -> List[int]:
        def dfs(root: Optional[TreeNode]):
            if root is None or root.left == root.right:
                return
            if root.left is None:
                ans.append(root.right.val)
            if root.right is None:
                ans.append(root.left.val)
            dfs(root.left)
            dfs(root.right)

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
    private List<Integer> ans = new ArrayList<>();

    public List<Integer> getLonelyNodes(TreeNode root) {
        dfs(root);
        return ans;
    }

    private void dfs(TreeNode root) {
        if (root == null || (root.left == root.right)) {
            return;
        }
        if (root.left == null) {
            ans.add(root.right.val);
        }
        if (root.right == null) {
            ans.add(root.left.val);
        }
        dfs(root.left);
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
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> ans;
        auto dfs = [&](this auto&& dfs, TreeNode* root) {
            if (!root || (root->left == root->right)) {
                return;
            }
            if (!root->left) {
                ans.push_back(root->right->val);
            }
            if (!root->right) {
                ans.push_back(root->left->val);
            }
            dfs(root->left);
            dfs(root->right);
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
 func getLonelyNodes(root *TreeNode) (ans []int) {
	var dfs func(*TreeNode)
	dfs = func(root *TreeNode) {
		if root == nil || (root.Left == root.Right) {
			return
		}
		if root.Left == nil {
			ans = append(ans, root.Right.Val)
		}
		if root.Right == nil {
			ans = append(ans, root.Left.Val)
		}
		dfs(root.Left)
		dfs(root.Right)
	}
	dfs(root)
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

function getLonelyNodes(root: TreeNode | null): number[] {
    const ans: number[] = [];
    const dfs = (root: TreeNode | null) => {
        if (!root || root.left === root.right) {
            return;
        }
        if (!root.left) {
            ans.push(root.right.val);
        }
        if (!root.right) {
            ans.push(root.left.val);
        }
        dfs(root.left);
        dfs(root.right);
    };
    dfs(root);
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
