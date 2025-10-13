---
title: "0400_第 N 位数字"
date: 2025-10-08T18:36:10+08:00
weight: 1
tags: [二分查找, 二叉树, 位运算, 动态规划, 单调栈, 双指针, 哈希表, 回溯, 堆（优先队列）, 字符串, 广度优先搜索, 排序, 数学, 数组, 栈, 树, 树状数组, 深度优先搜索, 矩阵, 线段树, 贪心]
---

{{< markmap >}}
### [0400_第 N 位数字](#400)
#### [数学](#400)
#### [二分查找](#400)
### [0401_二进制手表](#401)
#### [位运算](#401)
#### [回溯](#401)
### [0402_移掉 K 位数字](#402)
#### [栈](#402)
#### [贪心](#402)
#### [字符串](#402)
#### [单调栈](#402)
### [0403_青蛙过河](#403)
#### [数组](#403)
#### [动态规划](#403)
### [0404_左叶子之和](#404)
#### [树](#404)
#### [深度优先搜索](#404)
#### [广度优先搜索](#404)
#### [二叉树](#404)
### [0405_数字转换为十六进制数](#405)
#### [位运算](#405)
#### [数学](#405)
#### [字符串](#405)
### [0406_根据身高重建队列](#406)
#### [树状数组](#406)
#### [线段树](#406)
#### [数组](#406)
#### [排序](#406)
### [0407_接雨水 II](#407)
#### [广度优先搜索](#407)
#### [数组](#407)
#### [矩阵](#407)
#### [堆（优先队列）](#407)
### [0408_有效单词缩写 🔒](#408)
#### [双指针](#408)
#### [字符串](#408)
### [0409_最长回文串](#409)
#### [贪心](#409)
#### [哈希表](#409)
#### [字符串](#409)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0400_第 N 位数字
___
#### 数学
___
#### 二分查找
---
### 0401_二进制手表
___
#### 位运算
___
#### 回溯
---
### 0402_移掉 K 位数字
___
#### 栈
___
#### 贪心
___
#### 字符串
___
#### 单调栈
---
### 0403_青蛙过河
___
#### 数组
___
#### 动态规划
---
### 0404_左叶子之和
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 二叉树
---
### 0405_数字转换为十六进制数
___
#### 位运算
___
#### 数学
___
#### 字符串
---
### 0406_根据身高重建队列
___
#### 树状数组
___
#### 线段树
___
#### 数组
___
#### 排序
---
### 0407_接雨水 II
___
#### 广度优先搜索
___
#### 数组
___
#### 矩阵
___
#### 堆（优先队列）
---
### 0408_有效单词缩写 🔒
___
#### 双指针
___
#### 字符串
---
### 0409_最长回文串
___
#### 贪心
___
#### 哈希表
___
#### 字符串
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉树 | 位运算 |
| 动态规划 | 单调栈 | 双指针 |
| 哈希表 | 回溯 | 堆（优先队列） |
| 字符串 | 广度优先搜索 | 排序 |
| 数学 | 数组 | 栈 |
| 树 | 树状数组 | 深度优先搜索 |
| 矩阵 | 线段树 | 贪心 |

# [400. 第 N 位数字](https://leetcode.cn/problems/nth-digit){#400}

{{< tabs "400" >}}

{{% tab "python" %}}
```python
class Solution:
    def findNthDigit(self, n: int) -> int:
        k, cnt = 1, 9
        while k * cnt < n:
            n -= k * cnt
            k += 1
            cnt *= 10
        num = 10 ** (k - 1) + (n - 1) // k
        idx = (n - 1) % k
        return int(str(num)[idx])
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findNthDigit(int n) {
        int k = 1, cnt = 9;
        while ((long) k * cnt < n) {
            n -= k * cnt;
            ++k;
            cnt *= 10;
        }
        int num = (int) Math.pow(10, k - 1) + (n - 1) / k;
        int idx = (n - 1) % k;
        return String.valueOf(num).charAt(idx) - '0';
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int findNthDigit(int n) {
        int k = 1, cnt = 9;
        while (1ll * k * cnt < n) {
            n -= k * cnt;
            ++k;
            cnt *= 10;
        }
        int num = pow(10, k - 1) + (n - 1) / k;
        int idx = (n - 1) % k;
        return to_string(num)[idx] - '0';
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findNthDigit(n int) int {
	k, cnt := 1, 9
	for k*cnt < n {
		n -= k * cnt
		k++
		cnt *= 10
	}
	num := int(math.Pow10(k-1)) + (n-1)/k
	idx := (n - 1) % k
	return int(strconv.Itoa(num)[idx] - '0')
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} n
 * @return {number}
 */
var findNthDigit = function (n) {
    let k = 1,
        cnt = 9;
    while (k * cnt < n) {
        n -= k * cnt;
        ++k;
        cnt *= 10;
    }
    const num = Math.pow(10, k - 1) + (n - 1) / k;
    const idx = (n - 1) % k;
    return num.toString()[idx];
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int FindNthDigit(int n) {
        int k = 1, cnt = 9;
        while ((long) k * cnt < n) {
            n -= k * cnt;
            ++k;
            cnt *= 10;
        }
        int num = (int) Math.Pow(10, k - 1) + (n - 1) / k;
        int idx = (n - 1) % k;
        return num.ToString()[idx] - '0';
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数 <code>n</code> ，请你在无限的整数序列&nbsp;<code>[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...]</code> 中找出并返回第&nbsp;<code>n</code><em> </em>位上的数字。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 3
<strong>输出：</strong>3
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 11
<strong>输出：</strong>0
<strong>解释：</strong>第 11 位数字在序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 里是 <strong>0 </strong>，它是 10 的一部分。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学

位数为 $k$ 的最小整数和最大整数分别为 $10^{k-1}$ 和 $10^k-1$，因此 $k$ 位数的总位数为 $k \times 9 \times 10^{k-1}$。

我们用 $k$ 表示当前数字的位数，用 $cnt$ 表示当前位数的数字的总数，初始时 $k=1$, $cnt=9$。

每次将 $n$ 减去 $cnt \times k$，当 $n$ 小于等于 $cnt \times k$ 时，说明 $n$ 对应的数字在当前位数的数字范围内，此时可以计算出对应的数字。

具体做法是，首先计算出 $n$ 对应的是当前位数的哪一个数字，然后计算出是该数字的第几位，从而得到该位上的数字。

时间复杂度 $O(\log_{10} n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findNthDigit(self, n: int) -> int:
        k, cnt = 1, 9
        while k * cnt < n:
            n -= k * cnt
            k += 1
            cnt *= 10
        num = 10 ** (k - 1) + (n - 1) // k
        idx = (n - 1) % k
        return int(str(num)[idx])
```

#### Java

```java
class Solution {
    public int findNthDigit(int n) {
        int k = 1, cnt = 9;
        while ((long) k * cnt < n) {
            n -= k * cnt;
            ++k;
            cnt *= 10;
        }
        int num = (int) Math.pow(10, k - 1) + (n - 1) / k;
        int idx = (n - 1) % k;
        return String.valueOf(num).charAt(idx) - '0';
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findNthDigit(int n) {
        int k = 1, cnt = 9;
        while (1ll * k * cnt < n) {
            n -= k * cnt;
            ++k;
            cnt *= 10;
        }
        int num = pow(10, k - 1) + (n - 1) / k;
        int idx = (n - 1) % k;
        return to_string(num)[idx] - '0';
    }
};
```

#### Go

```go
func findNthDigit(n int) int {
	k, cnt := 1, 9
	for k*cnt < n {
		n -= k * cnt
		k++
		cnt *= 10
	}
	num := int(math.Pow10(k-1)) + (n-1)/k
	idx := (n - 1) % k
	return int(strconv.Itoa(num)[idx] - '0')
}
```

#### JavaScript

```js
/**
 * @param {number} n
 * @return {number}
 */
var findNthDigit = function (n) {
    let k = 1,
        cnt = 9;
    while (k * cnt < n) {
        n -= k * cnt;
        ++k;
        cnt *= 10;
    }
    const num = Math.pow(10, k - 1) + (n - 1) / k;
    const idx = (n - 1) % k;
    return num.toString()[idx];
};
```

#### C#

```cs
public class Solution {
    public int FindNthDigit(int n) {
        int k = 1, cnt = 9;
        while ((long) k * cnt < n) {
            n -= k * cnt;
            ++k;
            cnt *= 10;
        }
        int num = (int) Math.Pow(10, k - 1) + (n - 1) / k;
        int idx = (n - 1) % k;
        return num.ToString()[idx] - '0';
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [401. 二进制手表](https://leetcode.cn/problems/binary-watch){#401}

{{< tabs "401" >}}

{{% tab "python" %}}
```python
class Solution:
    def readBinaryWatch(self, turnedOn: int) -> List[str]:
        ans = []
        for i in range(1 << 10):
            h, m = i >> 6, i & 0b111111
            if h < 12 and m < 60 and i.bit_count() == turnedOn:
                ans.append('{:d}:{:02d}'.format(h, m))
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<String> readBinaryWatch(int turnedOn) {
        List<String> ans = new ArrayList<>();
        for (int i = 0; i < 1 << 10; ++i) {
            int h = i >> 6, m = i & 0b111111;
            if (h < 12 && m < 60 && Integer.bitCount(i) == turnedOn) {
                ans.add(String.format("%d:%02d", h, m));
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
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for (int i = 0; i < 1 << 10; ++i) {
            int h = i >> 6, m = i & 0b111111;
            if (h < 12 && m < 60 && __builtin_popcount(i) == turnedOn) {
                ans.push_back(to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m));
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func readBinaryWatch(turnedOn int) []string {
	var ans []string
	for i := 0; i < 1<<10; i++ {
		h, m := i>>6, i&0b111111
		if h < 12 && m < 60 && bits.OnesCount(uint(i)) == turnedOn {
			ans = append(ans, fmt.Sprintf("%d:%02d", h, m))
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function readBinaryWatch(turnedOn: number): string[] {
    if (turnedOn === 0) {
        return ['0:00'];
    }
    const n = 10;
    const res = [];
    const bitArr = new Array(10).fill(false);
    const createTime = () => {
        return [
            bitArr.slice(0, 4).reduce((p, v) => (p << 1) | Number(v), 0),
            bitArr.slice(4).reduce((p, v) => (p << 1) | Number(v), 0),
        ];
    };
    const helper = (i: number, count: number) => {
        if (i + count > n || count === 0) {
            return;
        }
        bitArr[i] = true;
        if (count === 1) {
            const [h, m] = createTime();
            if (h < 12 && m < 60) {
                res.push(`${h}:${m < 10 ? '0' + m : m}`);
            }
        }
        helper(i + 1, count - 1);
        bitArr[i] = false;
        helper(i + 1, count);
    };
    helper(0, turnedOn);
    return res;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    fn create_time(bit_arr: &[bool; 10]) -> (i32, i32) {
        let mut h = 0;
        let mut m = 0;
        for i in 0..4 {
            h <<= 1;
            h |= if bit_arr[i] { 1 } else { 0 };
        }
        for i in 4..10 {
            m <<= 1;
            m |= if bit_arr[i] { 1 } else { 0 };
        }

        (h, m)
    }

    fn helper(res: &mut Vec<String>, bit_arr: &mut [bool; 10], i: usize, count: usize) {
        if i + count > 10 || count == 0 {
            return;
        }
        bit_arr[i] = true;
        if count == 1 {
            let (h, m) = Self::create_time(bit_arr);
            if h < 12 && m < 60 {
                if m < 10 {
                    res.push(format!("{}:0{}", h, m));
                } else {
                    res.push(format!("{}:{}", h, m));
                }
            }
        }
        Self::helper(res, bit_arr, i + 1, count - 1);
        bit_arr[i] = false;
        Self::helper(res, bit_arr, i + 1, count);
    }

    pub fn read_binary_watch(turned_on: i32) -> Vec<String> {
        if turned_on == 0 {
            return vec![String::from("0:00")];
        }
        let mut res = vec![];
        let mut bit_arr = [false; 10];
        Self::helper(&mut res, &mut bit_arr, 0, turned_on as usize);
        res
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>二进制手表顶部有 4 个 LED 代表<strong> 小时（0-11）</strong>，底部的 6 个 LED 代表<strong> 分钟（0-59）</strong>。每个 LED 代表一个 0 或 1，最低位在右侧。</p>

<ul>
	<li>例如，下面的二进制手表读取 <code>"4:51"</code> 。</li>
</ul>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0401.Binary%20Watch/images/binarywatch.jpg" style="height: 300px; width" /></p>

<p>给你一个整数 <code>turnedOn</code> ，表示当前亮着的 LED 的数量，返回二进制手表可以表示的所有可能时间。你可以 <strong>按任意顺序</strong> 返回答案。</p>

<p>小时不会以零开头：</p>

<ul>
	<li>例如，<code>"01:00"</code> 是无效的时间，正确的写法应该是 <code>"1:00"</code> 。</li>
</ul>

<p>分钟必须由两位数组成，可能会以零开头：</p>

<ul>
	<li>例如，<code>"10:2"</code> 是无效的时间，正确的写法应该是 <code>"10:02"</code> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>turnedOn = 1
<strong>输出：</strong>["0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>turnedOn = 9
<strong>输出：</strong>[]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= turnedOn &lt;= 10</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举组合

题目可转换为求 i(`i∈[0,12)`) 和 j(`j∈[0,60)`) 所有可能的组合。

合法组合需要满足的条件是：i 的二进制形式中 1 的个数加上 j 的二进制形式中 1 的个数，结果等于 turnedOn。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def readBinaryWatch(self, turnedOn: int) -> List[str]:
        return [
            '{:d}:{:02d}'.format(i, j)
            for i in range(12)
            for j in range(60)
            if (bin(i) + bin(j)).count('1') == turnedOn
        ]
```

#### Java

```java
class Solution {
    public List<String> readBinaryWatch(int turnedOn) {
        List<String> ans = new ArrayList<>();
        for (int i = 0; i < 12; ++i) {
            for (int j = 0; j < 60; ++j) {
                if (Integer.bitCount(i) + Integer.bitCount(j) == turnedOn) {
                    ans.add(String.format("%d:%02d", i, j));
                }
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
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for (int i = 0; i < 12; ++i) {
            for (int j = 0; j < 60; ++j) {
                if (__builtin_popcount(i) + __builtin_popcount(j) == turnedOn) {
                    ans.push_back(to_string(i) + ":" + (j < 10 ? "0" : "") + to_string(j));
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func readBinaryWatch(turnedOn int) []string {
	var ans []string
	for i := 0; i < 12; i++ {
		for j := 0; j < 60; j++ {
			if bits.OnesCount(uint(i))+bits.OnesCount(uint(j)) == turnedOn {
				ans = append(ans, fmt.Sprintf("%d:%02d", i, j))
			}
		}
	}
	return ans
}
```

#### TypeScript

```ts
function readBinaryWatch(turnedOn: number): string[] {
    if (turnedOn === 0) {
        return ['0:00'];
    }
    const n = 10;
    const res = [];
    const bitArr = new Array(10).fill(false);
    const createTime = () => {
        return [
            bitArr.slice(0, 4).reduce((p, v) => (p << 1) | Number(v), 0),
            bitArr.slice(4).reduce((p, v) => (p << 1) | Number(v), 0),
        ];
    };
    const helper = (i: number, count: number) => {
        if (i + count > n || count === 0) {
            return;
        }
        bitArr[i] = true;
        if (count === 1) {
            const [h, m] = createTime();
            if (h < 12 && m < 60) {
                res.push(`${h}:${m < 10 ? '0' + m : m}`);
            }
        }
        helper(i + 1, count - 1);
        bitArr[i] = false;
        helper(i + 1, count);
    };
    helper(0, turnedOn);
    return res;
}
```

#### Rust

```rust
impl Solution {
    fn create_time(bit_arr: &[bool; 10]) -> (i32, i32) {
        let mut h = 0;
        let mut m = 0;
        for i in 0..4 {
            h <<= 1;
            h |= if bit_arr[i] { 1 } else { 0 };
        }
        for i in 4..10 {
            m <<= 1;
            m |= if bit_arr[i] { 1 } else { 0 };
        }

        (h, m)
    }

    fn helper(res: &mut Vec<String>, bit_arr: &mut [bool; 10], i: usize, count: usize) {
        if i + count > 10 || count == 0 {
            return;
        }
        bit_arr[i] = true;
        if count == 1 {
            let (h, m) = Self::create_time(bit_arr);
            if h < 12 && m < 60 {
                if m < 10 {
                    res.push(format!("{}:0{}", h, m));
                } else {
                    res.push(format!("{}:{}", h, m));
                }
            }
        }
        Self::helper(res, bit_arr, i + 1, count - 1);
        bit_arr[i] = false;
        Self::helper(res, bit_arr, i + 1, count);
    }

    pub fn read_binary_watch(turned_on: i32) -> Vec<String> {
        if turned_on == 0 {
            return vec![String::from("0:00")];
        }
        let mut res = vec![];
        let mut bit_arr = [false; 10];
        Self::helper(&mut res, &mut bit_arr, 0, turned_on as usize);
        res
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：二进制枚举

利用 10 个二进制位表示手表，其中前 4 位代表小时，后 6 位代表分钟。枚举 `[0, 1 << 10)` 的所有数，找出合法的数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def readBinaryWatch(self, turnedOn: int) -> List[str]:
        ans = []
        for i in range(1 << 10):
            h, m = i >> 6, i & 0b111111
            if h < 12 and m < 60 and i.bit_count() == turnedOn:
                ans.append('{:d}:{:02d}'.format(h, m))
        return ans
```

#### Java

```java
class Solution {
    public List<String> readBinaryWatch(int turnedOn) {
        List<String> ans = new ArrayList<>();
        for (int i = 0; i < 1 << 10; ++i) {
            int h = i >> 6, m = i & 0b111111;
            if (h < 12 && m < 60 && Integer.bitCount(i) == turnedOn) {
                ans.add(String.format("%d:%02d", h, m));
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
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for (int i = 0; i < 1 << 10; ++i) {
            int h = i >> 6, m = i & 0b111111;
            if (h < 12 && m < 60 && __builtin_popcount(i) == turnedOn) {
                ans.push_back(to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m));
            }
        }
        return ans;
    }
};
```

#### Go

```go
func readBinaryWatch(turnedOn int) []string {
	var ans []string
	for i := 0; i < 1<<10; i++ {
		h, m := i>>6, i&0b111111
		if h < 12 && m < 60 && bits.OnesCount(uint(i)) == turnedOn {
			ans = append(ans, fmt.Sprintf("%d:%02d", h, m))
		}
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [402. 移掉 K 位数字](https://leetcode.cn/problems/remove-k-digits){#402}

{{< tabs "402" >}}

{{% tab "python" %}}
```python
class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        stk = []
        remain = len(num) - k
        for c in num:
            while k and stk and stk[-1] > c:
                stk.pop()
                k -= 1
            stk.append(c)
        return ''.join(stk[:remain]).lstrip('0') or '0'
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String removeKdigits(String num, int k) {
        StringBuilder stk = new StringBuilder();
        for (char c : num.toCharArray()) {
            while (k > 0 && stk.length() > 0 && stk.charAt(stk.length() - 1) > c) {
                stk.deleteCharAt(stk.length() - 1);
                --k;
            }
            stk.append(c);
        }
        for (; k > 0; --k) {
            stk.deleteCharAt(stk.length() - 1);
        }
        int i = 0;
        for (; i < stk.length() && stk.charAt(i) == '0'; ++i) {
        }
        String ans = stk.substring(i);
        return "".equals(ans) ? "0" : ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string removeKdigits(string num, int k) {
        string stk;
        for (char& c : num) {
            while (k && stk.size() && stk.back() > c) {
                stk.pop_back();
                --k;
            }
            stk += c;
        }
        while (k--) {
            stk.pop_back();
        }
        int i = 0;
        for (; i < stk.size() && stk[i] == '0'; ++i) {
        }
        string ans = stk.substr(i);
        return ans == "" ? "0" : ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func removeKdigits(num string, k int) string {
	stk, remain := make([]byte, 0), len(num)-k
	for i := 0; i < len(num); i++ {
		n := len(stk)
		for k > 0 && n > 0 && stk[n-1] > num[i] {
			stk = stk[:n-1]
			n, k = n-1, k-1
		}
		stk = append(stk, num[i])
	}

	for i := 0; i < len(stk) && i < remain; i++ {
		if stk[i] != '0' {
			return string(stk[i:remain])
		}
	}
	return "0"
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function removeKdigits(num: string, k: number): string {
    const stk: string[] = [];
    for (const c of num) {
        while (k && stk.length > 0 && stk[stk.length - 1] > c) {
            stk.pop();
            k--;
        }
        stk.push(c);
    }
    while (k--) {
        stk.pop();
    }
    return stk.join('').replace(/^0*/g, '') || '0';
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个以字符串表示的非负整数 <code>num</code> 和一个整数 <code>k</code> ，移除这个数中的 <code>k</code><em> </em>位数字，使得剩下的数字最小。请你以字符串形式返回这个最小的数字。</p>
 

<p><strong>示例 1 ：</strong></p>

<pre>
<strong>输入：</strong>num = "1432219", k = 3
<strong>输出：</strong>"1219"
<strong>解释：</strong>移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219 。
</pre>

<p><strong>示例 2 ：</strong></p>

<pre>
<strong>输入：</strong>num = "10200", k = 1
<strong>输出：</strong>"200"
<strong>解释：</strong>移掉首位的 1 剩下的数字为 200. 注意输出不能有任何前导零。
</pre>

<p><strong>示例 3 ：</strong></p>

<pre>
<strong>输入：</strong>num = "10", k = 2
<strong>输出：</strong>"0"
<strong>解释：</strong>从原数字移除所有的数字，剩余为空就是 0 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= k <= num.length <= 10<sup>5</sup></code></li>
	<li><code>num</code> 仅由若干位数字（0 - 9）组成</li>
	<li>除了 <strong>0</strong> 本身之外，<code>num</code> 不含任何前导零</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心算法

前置知识：两个相同位数的数字大小关系取决于第一个不同位的数的大小。

基本的思路如下：

-   从左到右遍历数组元素；
-   对于遍历到的当前元素，选择保留；
-   但可以选择性丢弃前面的相邻元素，丢弃与否取决于当前元素和前面相邻元素的大小；
-   根据前置知识可知当当前元素小于前面相邻元素时可以移除前面相邻的元素。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        stk = []
        remain = len(num) - k
        for c in num:
            while k and stk and stk[-1] > c:
                stk.pop()
                k -= 1
            stk.append(c)
        return ''.join(stk[:remain]).lstrip('0') or '0'
```

#### Java

```java
class Solution {
    public String removeKdigits(String num, int k) {
        StringBuilder stk = new StringBuilder();
        for (char c : num.toCharArray()) {
            while (k > 0 && stk.length() > 0 && stk.charAt(stk.length() - 1) > c) {
                stk.deleteCharAt(stk.length() - 1);
                --k;
            }
            stk.append(c);
        }
        for (; k > 0; --k) {
            stk.deleteCharAt(stk.length() - 1);
        }
        int i = 0;
        for (; i < stk.length() && stk.charAt(i) == '0'; ++i) {
        }
        String ans = stk.substring(i);
        return "".equals(ans) ? "0" : ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    string removeKdigits(string num, int k) {
        string stk;
        for (char& c : num) {
            while (k && stk.size() && stk.back() > c) {
                stk.pop_back();
                --k;
            }
            stk += c;
        }
        while (k--) {
            stk.pop_back();
        }
        int i = 0;
        for (; i < stk.size() && stk[i] == '0'; ++i) {
        }
        string ans = stk.substr(i);
        return ans == "" ? "0" : ans;
    }
};
```

#### Go

```go
func removeKdigits(num string, k int) string {
	stk, remain := make([]byte, 0), len(num)-k
	for i := 0; i < len(num); i++ {
		n := len(stk)
		for k > 0 && n > 0 && stk[n-1] > num[i] {
			stk = stk[:n-1]
			n, k = n-1, k-1
		}
		stk = append(stk, num[i])
	}

	for i := 0; i < len(stk) && i < remain; i++ {
		if stk[i] != '0' {
			return string(stk[i:remain])
		}
	}
	return "0"
}
```

#### TypeScript

```ts
function removeKdigits(num: string, k: number): string {
    const stk: string[] = [];
    for (const c of num) {
        while (k && stk.length > 0 && stk[stk.length - 1] > c) {
            stk.pop();
            k--;
        }
        stk.push(c);
    }
    while (k--) {
        stk.pop();
    }
    return stk.join('').replace(/^0*/g, '') || '0';
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [403. 青蛙过河](https://leetcode.cn/problems/frog-jump){#403}

{{< tabs "403" >}}

{{% tab "python" %}}
```python
class Solution:
    def canCross(self, stones: List[int]) -> bool:
        n = len(stones)
        f = [[False] * n for _ in range(n)]
        f[0][0] = True
        for i in range(1, n):
            for j in range(i - 1, -1, -1):
                k = stones[i] - stones[j]
                if k - 1 > j:
                    break
                f[i][k] = f[j][k - 1] or f[j][k] or f[j][k + 1]
                if i == n - 1 and f[i][k]:
                    return True
        return False
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean canCross(int[] stones) {
        int n = stones.length;
        boolean[][] f = new boolean[n][n];
        f[0][0] = true;
        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                int k = stones[i] - stones[j];
                if (k - 1 > j) {
                    break;
                }
                f[i][k] = f[j][k - 1] || f[j][k] || f[j][k + 1];
                if (i == n - 1 && f[i][k]) {
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
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        bool f[n][n];
        memset(f, false, sizeof(f));
        f[0][0] = true;
        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                int k = stones[i] - stones[j];
                if (k - 1 > j) {
                    break;
                }
                f[i][k] = f[j][k - 1] || f[j][k] || f[j][k + 1];
                if (i == n - 1 && f[i][k]) {
                    return true;
                }
            }
        }
        return false;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func canCross(stones []int) bool {
	n := len(stones)
	f := make([][]bool, n)
	for i := range f {
		f[i] = make([]bool, n)
	}
	f[0][0] = true
	for i := 1; i < n; i++ {
		for j := i - 1; j >= 0; j-- {
			k := stones[i] - stones[j]
			if k-1 > j {
				break
			}
			f[i][k] = f[j][k-1] || f[j][k] || f[j][k+1]
			if i == n-1 && f[i][k] {
				return true
			}
		}
	}
	return false
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function canCross(stones: number[]): boolean {
    const n = stones.length;
    const f: boolean[][] = new Array(n).fill(0).map(() => new Array(n).fill(false));
    f[0][0] = true;
    for (let i = 1; i < n; ++i) {
        for (let j = i - 1; j >= 0; --j) {
            const k = stones[i] - stones[j];
            if (k - 1 > j) {
                break;
            }
            f[i][k] = f[j][k - 1] || f[j][k] || f[j][k + 1];
            if (i == n - 1 && f[i][k]) {
                return true;
            }
        }
    }
    return false;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    #[allow(dead_code)]
    pub fn can_cross(stones: Vec<i32>) -> bool {
        let n = stones.len();
        let mut dp = vec![vec![false; n]; n];

        // Initialize the dp vector
        dp[0][0] = true;

        // Begin the actual dp process
        for i in 1..n {
            for j in (0..=i - 1).rev() {
                let k = (stones[i] - stones[j]) as usize;
                if k - 1 > j {
                    break;
                }
                dp[i][k] = dp[j][k - 1] || dp[j][k] || dp[j][k + 1];
                if i == n - 1 && dp[i][k] {
                    return true;
                }
            }
        }

        false
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>一只青蛙想要过河。 假定河流被等分为若干个单元格，并且在每一个单元格内都有可能放有一块石子（也有可能没有）。 青蛙可以跳上石子，但是不可以跳入水中。</p>

<p>给你石子的位置列表 <code>stones</code>（用单元格序号 <strong>升序</strong> 表示），&nbsp;请判定青蛙能否成功过河（即能否在最后一步跳至最后一块石子上）。开始时，&nbsp;青蛙默认已站在第一块石子上，并可以假定它第一步只能跳跃 <code>1</code> 个单位（即只能从单元格 1 跳至单元格 2 ）。</p>

<p>如果青蛙上一步跳跃了&nbsp;<code>k</code><em>&nbsp;</em>个单位，那么它接下来的跳跃距离只能选择为&nbsp;<code>k - 1</code>、<code>k</code><em>&nbsp;</em>或&nbsp;<code>k + 1</code> 个单位。&nbsp;另请注意，青蛙只能向前方（终点的方向）跳跃。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>stones = [0,1,3,5,6,8,12,17]
<strong>输出：</strong>true
<strong>解释：</strong>青蛙可以成功过河，按照如下方案跳跃：跳 1 个单位到第 2 块石子, 然后跳 2 个单位到第 3 块石子, 接着 跳 2 个单位到第 4 块石子, 然后跳 3 个单位到第 6 块石子, 跳 4 个单位到第 7 块石子, 最后，跳 5 个单位到第 8 个石子（即最后一块石子）。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>stones = [0,1,2,3,4,8,9,11]
<strong>输出：</strong>false
<strong>解释：</strong>这是因为第 5 和第 6 个石子之间的间距太大，没有可选的方案供青蛙跳跃过去。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= stones.length &lt;= 2000</code></li>
	<li><code>0 &lt;= stones[i] &lt;= 2<sup>31</sup> - 1</code></li>
	<li><code>stones[0] == 0</code></li>
	<li><code>stones</code>&nbsp;按严格升序排列</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 记忆化搜索

我们用哈希表 $pos$ 记录每个石子的下标，接下来设计一个函数 $dfs(i, k)$，表示青蛙从第 $i$ 个石子跳跃且上一次跳跃距离为 $k$，如果青蛙能够到达终点，那么函数返回 `true`，否则返回 `false`。

函数 $dfs(i, k)$ 的计算过程如下：

如果 $i$ 是最后一个石子的下标，那么青蛙已经到达终点，返回 `true`；

否则，我们需要枚举青蛙接下来的跳跃距离 $j$，其中 $j \in [k-1, k, k+1]$。如果 $j$ 是正数，并且哈希表 $pos$ 中存在位置 $stones[i] + j$，那么青蛙在第 $i$ 个石子上可以选择跳跃 $j$ 个单位，如果 $dfs(pos[stones[i] + j], j)$ 返回 `true`，那么青蛙可以从第 $i$ 个石子成功跳跃到终点，我们就可以返回 `true`。

枚举结束，说明青蛙在第 $i$ 个石子上无法选择合适的跳跃距离跳到终点，我们就返回 `false`。

为了防止函数 $dfs(i, k)$ 中出现重复计算，我们可以使用记忆化搜索，将 $dfs(i, k)$ 的结果记录在一个数组 $f$ 中，每当函数 $dfs(i, k)$ 返回结果，我们就将 $f[i][k]$ 进行赋值，并在下次遇到 $dfs(i, k)$ 时直接返回 $f[i][k]$。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 是石子的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canCross(self, stones: List[int]) -> bool:
        @cache
        def dfs(i, k):
            if i == n - 1:
                return True
            for j in range(k - 1, k + 2):
                if j > 0 and stones[i] + j in pos and dfs(pos[stones[i] + j], j):
                    return True
            return False

        n = len(stones)
        pos = {s: i for i, s in enumerate(stones)}
        return dfs(0, 0)
```

#### Java

```java
class Solution {
    private Boolean[][] f;
    private Map<Integer, Integer> pos = new HashMap<>();
    private int[] stones;
    private int n;

    public boolean canCross(int[] stones) {
        n = stones.length;
        f = new Boolean[n][n];
        this.stones = stones;
        for (int i = 0; i < n; ++i) {
            pos.put(stones[i], i);
        }
        return dfs(0, 0);
    }

    private boolean dfs(int i, int k) {
        if (i == n - 1) {
            return true;
        }
        if (f[i][k] != null) {
            return f[i][k];
        }
        for (int j = k - 1; j <= k + 1; ++j) {
            if (j > 0) {
                int h = stones[i] + j;
                if (pos.containsKey(h) && dfs(pos.get(h), j)) {
                    return f[i][k] = true;
                }
            }
        }
        return f[i][k] = false;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        int f[n][n];
        memset(f, -1, sizeof(f));
        unordered_map<int, int> pos;
        for (int i = 0; i < n; ++i) {
            pos[stones[i]] = i;
        }
        function<bool(int, int)> dfs = [&](int i, int k) -> bool {
            if (i == n - 1) {
                return true;
            }
            if (f[i][k] != -1) {
                return f[i][k];
            }
            for (int j = k - 1; j <= k + 1; ++j) {
                if (j > 0 && pos.count(stones[i] + j) && dfs(pos[stones[i] + j], j)) {
                    return f[i][k] = true;
                }
            }
            return f[i][k] = false;
        };
        return dfs(0, 0);
    }
};
```

#### Go

```go
func canCross(stones []int) bool {
	n := len(stones)
	f := make([][]int, n)
	pos := map[int]int{}
	for i := range f {
		pos[stones[i]] = i
		f[i] = make([]int, n)
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	var dfs func(int, int) bool
	dfs = func(i, k int) bool {
		if i == n-1 {
			return true
		}
		if f[i][k] != -1 {
			return f[i][k] == 1
		}
		for j := k - 1; j <= k+1; j++ {
			if j > 0 {
				if p, ok := pos[stones[i]+j]; ok {
					if dfs(p, j) {
						f[i][k] = 1
						return true
					}
				}
			}
		}
		f[i][k] = 0
		return false
	}
	return dfs(0, 0)
}
```

#### TypeScript

```ts
function canCross(stones: number[]): boolean {
    const n = stones.length;
    const pos: Map<number, number> = new Map();
    for (let i = 0; i < n; ++i) {
        pos.set(stones[i], i);
    }
    const f: number[][] = new Array(n).fill(0).map(() => new Array(n).fill(-1));
    const dfs = (i: number, k: number): boolean => {
        if (i === n - 1) {
            return true;
        }
        if (f[i][k] !== -1) {
            return f[i][k] === 1;
        }
        for (let j = k - 1; j <= k + 1; ++j) {
            if (j > 0 && pos.has(stones[i] + j)) {
                if (dfs(pos.get(stones[i] + j)!, j)) {
                    f[i][k] = 1;
                    return true;
                }
            }
        }
        f[i][k] = 0;
        return false;
    };
    return dfs(0, 0);
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    #[allow(dead_code)]
    pub fn can_cross(stones: Vec<i32>) -> bool {
        let n = stones.len();
        let mut record = vec![vec![-1; n]; n];
        let mut pos = HashMap::new();
        for (i, &s) in stones.iter().enumerate() {
            pos.insert(s, i);
        }

        Self::dfs(&mut record, 0, 0, n, &pos, &stones)
    }

    #[allow(dead_code)]
    fn dfs(
        record: &mut Vec<Vec<i32>>,
        i: usize,
        k: usize,
        n: usize,
        pos: &HashMap<i32, usize>,
        stones: &Vec<i32>,
    ) -> bool {
        if i == n - 1 {
            return true;
        }

        if record[i][k] != -1 {
            return record[i][k] == 1;
        }

        let k = k as i32;
        for j in k - 1..=k + 1 {
            if j > 0
                && pos.contains_key(&(stones[i] + j))
                && Self::dfs(record, pos[&(stones[i] + j)], j as usize, n, pos, stones)
            {
                record[i][k as usize] = 1;
                return true;
            }
        }

        record[i][k as usize] = 0;
        false
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划

我们定义 $f[i][k]$ 表示青蛙能否达到「现在所处的石子编号」为 $i$，「上一次跳跃距离」为 $k$ 的状态。初始时 $f[0][0] = true$，其余均为 `false`。

考虑 $f[i]$，我们可以枚举上一块石子的编号 $j$，那么上一次跳跃的距离 $k=stones[i]-stones[j]$。如果 $k-1 \gt j$，那么青蛙无法从第 $j$ 块石子跳跃到第 $i$ 块石子，我们可以直接跳过这种情况。否则，青蛙可以从第 $j$ 块石子跳跃到第 $i$ 块石子，那么 $f[i][k] = f[j][k-1] \lor f[j][k] \lor f[j][k+1]$。如果 $i=n-1$，且 $f[i][k]=true$，那么青蛙可以成功过河，我们就可以返回 `true`。

否则，我们最后返回 `false`。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 是石子的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canCross(self, stones: List[int]) -> bool:
        n = len(stones)
        f = [[False] * n for _ in range(n)]
        f[0][0] = True
        for i in range(1, n):
            for j in range(i - 1, -1, -1):
                k = stones[i] - stones[j]
                if k - 1 > j:
                    break
                f[i][k] = f[j][k - 1] or f[j][k] or f[j][k + 1]
                if i == n - 1 and f[i][k]:
                    return True
        return False
```

#### Java

```java
class Solution {
    public boolean canCross(int[] stones) {
        int n = stones.length;
        boolean[][] f = new boolean[n][n];
        f[0][0] = true;
        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                int k = stones[i] - stones[j];
                if (k - 1 > j) {
                    break;
                }
                f[i][k] = f[j][k - 1] || f[j][k] || f[j][k + 1];
                if (i == n - 1 && f[i][k]) {
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
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        bool f[n][n];
        memset(f, false, sizeof(f));
        f[0][0] = true;
        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                int k = stones[i] - stones[j];
                if (k - 1 > j) {
                    break;
                }
                f[i][k] = f[j][k - 1] || f[j][k] || f[j][k + 1];
                if (i == n - 1 && f[i][k]) {
                    return true;
                }
            }
        }
        return false;
    }
};
```

#### Go

```go
func canCross(stones []int) bool {
	n := len(stones)
	f := make([][]bool, n)
	for i := range f {
		f[i] = make([]bool, n)
	}
	f[0][0] = true
	for i := 1; i < n; i++ {
		for j := i - 1; j >= 0; j-- {
			k := stones[i] - stones[j]
			if k-1 > j {
				break
			}
			f[i][k] = f[j][k-1] || f[j][k] || f[j][k+1]
			if i == n-1 && f[i][k] {
				return true
			}
		}
	}
	return false
}
```

#### TypeScript

```ts
function canCross(stones: number[]): boolean {
    const n = stones.length;
    const f: boolean[][] = new Array(n).fill(0).map(() => new Array(n).fill(false));
    f[0][0] = true;
    for (let i = 1; i < n; ++i) {
        for (let j = i - 1; j >= 0; --j) {
            const k = stones[i] - stones[j];
            if (k - 1 > j) {
                break;
            }
            f[i][k] = f[j][k - 1] || f[j][k] || f[j][k + 1];
            if (i == n - 1 && f[i][k]) {
                return true;
            }
        }
    }
    return false;
}
```

#### Rust

```rust
impl Solution {
    #[allow(dead_code)]
    pub fn can_cross(stones: Vec<i32>) -> bool {
        let n = stones.len();
        let mut dp = vec![vec![false; n]; n];

        // Initialize the dp vector
        dp[0][0] = true;

        // Begin the actual dp process
        for i in 1..n {
            for j in (0..=i - 1).rev() {
                let k = (stones[i] - stones[j]) as usize;
                if k - 1 > j {
                    break;
                }
                dp[i][k] = dp[j][k - 1] || dp[j][k] || dp[j][k + 1];
                if i == n - 1 && dp[i][k] {
                    return true;
                }
            }
        }

        false
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [404. 左叶子之和](https://leetcode.cn/problems/sum-of-left-leaves){#404}

{{< tabs "404" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        ans = 0
        stk = [root]
        while stk:
            root = stk.pop()
            if root.left:
                if root.left.left == root.left.right:
                    ans += root.left.val
                else:
                    stk.append(root.left)
            if root.right:
                stk.append(root.right)
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
    public int sumOfLeftLeaves(TreeNode root) {
        if (root == null) {
            return 0;
        }
        Deque<TreeNode> stk = new ArrayDeque<>();
        stk.push(root);
        int ans = 0;
        while (!stk.isEmpty()) {
            root = stk.pop();
            if (root.left != null) {
                if (root.left.left == root.left.right) {
                    ans += root.left.val;
                } else {
                    stk.push(root.left);
                }
            }
            if (root.right != null) {
                stk.push(root.right);
            }
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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int ans = 0;
        stack<TreeNode*> stk{{root}};
        while (!stk.empty()) {
            root = stk.top(), stk.pop();
            if (root->left) {
                if (!root->left->left && !root->left->right) {
                    ans += root->left->val;
                } else {
                    stk.push(root->left);
                }
            }
            if (root->right) {
                stk.push(root->right);
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
func sumOfLeftLeaves(root *TreeNode) (ans int) {
	if root == nil {
		return 0
	}
	stk := []*TreeNode{root}
	for len(stk) > 0 {
		root = stk[len(stk)-1]
		stk = stk[:len(stk)-1]
		if root.Left != nil {
			if root.Left.Left == root.Left.Right {
				ans += root.Left.Val
			} else {
				stk = append(stk, root.Left)
			}
		}
		if root.Right != nil {
			stk = append(stk, root.Right)
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

function sumOfLeftLeaves(root: TreeNode | null): number {
    if (!root) {
        return 0;
    }
    let ans = 0;
    const stk: TreeNode[] = [root];
    while (stk.length) {
        const { left, right } = stk.pop()!;
        if (left) {
            if (left.left === left.right) {
                ans += left.val;
            } else {
                stk.push(left);
            }
        }
        if (right) {
            stk.push(right);
        }
    }
    return ans;
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
use std::rc::Rc;
impl Solution {
    fn dfs(root: &Option<Rc<RefCell<TreeNode>>>, is_left: bool) -> i32 {
        if root.is_none() {
            return 0;
        }
        let node = root.as_ref().unwrap().borrow();
        let left = &node.left;
        let right = &node.right;
        if left.is_none() && right.is_none() {
            if is_left {
                return node.val;
            }
            return 0;
        }
        Self::dfs(left, true) + Self::dfs(right, false)
    }

    pub fn sum_of_left_leaves(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        Self::dfs(&root, false)
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int sumOfLeftLeaves(struct TreeNode* root) {
    if (!root) {
        return 0;
    }
    int ans = sumOfLeftLeaves(root->right);
    if (root->left) {
        if (!root->left->left && !root->left->right) {
            ans += root->left->val;
        } else {
            ans += sumOfLeftLeaves(root->left);
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

<p>给定二叉树的根节点&nbsp;<code>root</code>&nbsp;，返回所有左叶子之和。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0404.Sum%20of%20Left%20Leaves/images/leftsum-tree.jpg" /></p>

<pre>
<strong>输入:</strong> root = [3,9,20,null,null,15,7] 
<strong>输出:</strong> 24 
<strong>解释:</strong> 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre>
<strong>输入:</strong> root = [1]
<strong>输出:</strong> 0
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li>节点数在&nbsp;<code>[1, 1000]</code>&nbsp;范围内</li>
	<li><code>-1000 &lt;= Node.val &lt;= 1000</code></li>
</ul>

<p>&nbsp;</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归

我们首先判断 `root` 是否为空，如果为空则返回 $0$。

否则，我们递归调用 `sumOfLeftLeaves` 函数计算 `root` 的右子树中所有左叶子之和，并将结果赋给答案变量 $ans$。然后我们判断 `root` 的左子节点是否存在，如果存在，我们判断其是否为叶子节点，如果是叶子节点，则将其值加到答案变量 $ans$ 中，否则我们递归调用 `sumOfLeftLeaves` 函数计算 `root` 的左子树中所有左叶子之和，并将结果加到答案变量 $ans$ 中。

最后返回答案即可。

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
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        ans = self.sumOfLeftLeaves(root.right)
        if root.left:
            if root.left.left == root.left.right:
                ans += root.left.val
            else:
                ans += self.sumOfLeftLeaves(root.left)
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
    public int sumOfLeftLeaves(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int ans = sumOfLeftLeaves(root.right);
        if (root.left != null) {
            if (root.left.left == root.left.right) {
                ans += root.left.val;
            } else {
                ans += sumOfLeftLeaves(root.left);
            }
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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int ans = sumOfLeftLeaves(root->right);
        if (root->left) {
            if (!root->left->left && !root->left->right) {
                ans += root->left->val;
            } else {
                ans += sumOfLeftLeaves(root->left);
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
func sumOfLeftLeaves(root *TreeNode) int {
	if root == nil {
		return 0
	}
	ans := sumOfLeftLeaves(root.Right)
	if root.Left != nil {
		if root.Left.Left == root.Left.Right {
			ans += root.Left.Val
		} else {
			ans += sumOfLeftLeaves(root.Left)
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

function sumOfLeftLeaves(root: TreeNode | null): number {
    if (!root) {
        return 0;
    }
    let ans = sumOfLeftLeaves(root.right);
    if (root.left) {
        if (root.left.left === root.left.right) {
            ans += root.left.val;
        } else {
            ans += sumOfLeftLeaves(root.left);
        }
    }
    return ans;
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
use std::rc::Rc;
impl Solution {
    fn dfs(root: &Option<Rc<RefCell<TreeNode>>>, is_left: bool) -> i32 {
        if root.is_none() {
            return 0;
        }
        let node = root.as_ref().unwrap().borrow();
        let left = &node.left;
        let right = &node.right;
        if left.is_none() && right.is_none() {
            if is_left {
                return node.val;
            }
            return 0;
        }
        Self::dfs(left, true) + Self::dfs(right, false)
    }

    pub fn sum_of_left_leaves(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        Self::dfs(&root, false)
    }
}
```

#### C

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int sumOfLeftLeaves(struct TreeNode* root) {
    if (!root) {
        return 0;
    }
    int ans = sumOfLeftLeaves(root->right);
    if (root->left) {
        if (!root->left->left && !root->left->right) {
            ans += root->left->val;
        } else {
            ans += sumOfLeftLeaves(root->left);
        }
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：栈

我们也可以将方法一的递归改为迭代，使用栈来模拟递归的过程。

与方法一类似，我们首先判断 `root` 是否为空，如果为空则返回 $0$。

否则，我们初始化答案变量 $ans$ 为 $0$，然后初始化栈 $stk$，将 `root` 加入栈中。

当栈不为空时，我们弹出栈顶元素 `root`，如果 `root` 的左子节点存在，我们判断其是否为叶子节点，如果是叶子节点，则将其值加到答案变量 $ans$ 中，否则我们将其左子节点加入栈中。然后我们判断 `root` 的右子节点是否存在，如果存在，我们将其加入栈中。

最后返回答案即可。

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
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        ans = 0
        stk = [root]
        while stk:
            root = stk.pop()
            if root.left:
                if root.left.left == root.left.right:
                    ans += root.left.val
                else:
                    stk.append(root.left)
            if root.right:
                stk.append(root.right)
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
    public int sumOfLeftLeaves(TreeNode root) {
        if (root == null) {
            return 0;
        }
        Deque<TreeNode> stk = new ArrayDeque<>();
        stk.push(root);
        int ans = 0;
        while (!stk.isEmpty()) {
            root = stk.pop();
            if (root.left != null) {
                if (root.left.left == root.left.right) {
                    ans += root.left.val;
                } else {
                    stk.push(root.left);
                }
            }
            if (root.right != null) {
                stk.push(root.right);
            }
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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int ans = 0;
        stack<TreeNode*> stk{{root}};
        while (!stk.empty()) {
            root = stk.top(), stk.pop();
            if (root->left) {
                if (!root->left->left && !root->left->right) {
                    ans += root->left->val;
                } else {
                    stk.push(root->left);
                }
            }
            if (root->right) {
                stk.push(root->right);
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
func sumOfLeftLeaves(root *TreeNode) (ans int) {
	if root == nil {
		return 0
	}
	stk := []*TreeNode{root}
	for len(stk) > 0 {
		root = stk[len(stk)-1]
		stk = stk[:len(stk)-1]
		if root.Left != nil {
			if root.Left.Left == root.Left.Right {
				ans += root.Left.Val
			} else {
				stk = append(stk, root.Left)
			}
		}
		if root.Right != nil {
			stk = append(stk, root.Right)
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

function sumOfLeftLeaves(root: TreeNode | null): number {
    if (!root) {
        return 0;
    }
    let ans = 0;
    const stk: TreeNode[] = [root];
    while (stk.length) {
        const { left, right } = stk.pop()!;
        if (left) {
            if (left.left === left.right) {
                ans += left.val;
            } else {
                stk.push(left);
            }
        }
        if (right) {
            stk.push(right);
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

# [405. 数字转换为十六进制数](https://leetcode.cn/problems/convert-a-number-to-hexadecimal){#405}

{{< tabs "405" >}}

{{% tab "python" %}}
```python
class Solution:
    def toHex(self, num: int) -> str:
        if num == 0:
            return '0'
        chars = '0123456789abcdef'
        s = []
        for i in range(7, -1, -1):
            x = (num >> (4 * i)) & 0xF
            if s or x != 0:
                s.append(chars[x])
        return ''.join(s)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String toHex(int num) {
        if (num == 0) {
            return "0";
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 7; i >= 0; --i) {
            int x = (num >> (4 * i)) & 0xf;
            if (sb.length() > 0 || x != 0) {
                char c = x < 10 ? (char) (x + '0') : (char) (x - 10 + 'a');
                sb.append(c);
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
    string toHex(int num) {
        if (num == 0) return "0";
        string s = "";
        for (int i = 7; i >= 0; --i) {
            int x = (num >> (4 * i)) & 0xf;
            if (s.size() > 0 || x != 0) {
                char c = x < 10 ? (char) (x + '0') : (char) (x - 10 + 'a');
                s += c;
            }
        }
        return s;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func toHex(num int) string {
	if num == 0 {
		return "0"
	}
	sb := &strings.Builder{}
	for i := 7; i >= 0; i-- {
		x := num >> (4 * i) & 0xf
		if x > 0 || sb.Len() > 0 {
			var c byte
			if x < 10 {
				c = '0' + byte(x)
			} else {
				c = 'a' + byte(x-10)
			}
			sb.WriteByte(c)
		}
	}
	return sb.String()
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个整数，编写一个算法将这个数转换为十六进制数。对于负整数，我们通常使用&nbsp;<a href="https://baike.baidu.com/item/%E8%A1%A5%E7%A0%81/6854613?fr=aladdin">补码运算</a>&nbsp;方法。</p>

<p>答案字符串中的所有字母都应该是小写字符，并且除了 0 本身之外，答案中不应该有任何前置零。</p>

<p><strong>注意: </strong>不允许使用任何由库提供的将数字直接转换或格式化为十六进制的方法来解决这个问题。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>num = 26
<b>输出：</b>"1a"
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>num = -1
<b>输出：</b>"ffffffff"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>-2<sup>31</sup> &lt;= num &lt;= 2<sup>31</sup> - 1</code></li>
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
    def toHex(self, num: int) -> str:
        if num == 0:
            return '0'
        chars = '0123456789abcdef'
        s = []
        for i in range(7, -1, -1):
            x = (num >> (4 * i)) & 0xF
            if s or x != 0:
                s.append(chars[x])
        return ''.join(s)
```

#### Java

```java
class Solution {
    public String toHex(int num) {
        if (num == 0) {
            return "0";
        }
        StringBuilder sb = new StringBuilder();
        while (num != 0) {
            int x = num & 15;
            if (x < 10) {
                sb.append(x);
            } else {
                sb.append((char) (x - 10 + 'a'));
            }
            num >>>= 4;
        }
        return sb.reverse().toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        string s = "";
        for (int i = 7; i >= 0; --i) {
            int x = (num >> (4 * i)) & 0xf;
            if (s.size() > 0 || x != 0) {
                char c = x < 10 ? (char) (x + '0') : (char) (x - 10 + 'a');
                s += c;
            }
        }
        return s;
    }
};
```

#### Go

```go
func toHex(num int) string {
	if num == 0 {
		return "0"
	}
	sb := &strings.Builder{}
	for i := 7; i >= 0; i-- {
		x := num >> (4 * i) & 0xf
		if x > 0 || sb.Len() > 0 {
			var c byte
			if x < 10 {
				c = '0' + byte(x)
			} else {
				c = 'a' + byte(x-10)
			}
			sb.WriteByte(c)
		}
	}
	return sb.String()
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
    public String toHex(int num) {
        if (num == 0) {
            return "0";
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 7; i >= 0; --i) {
            int x = (num >> (4 * i)) & 0xf;
            if (sb.length() > 0 || x != 0) {
                char c = x < 10 ? (char) (x + '0') : (char) (x - 10 + 'a');
                sb.append(c);
            }
        }
        return sb.toString();
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [406. 根据身高重建队列](https://leetcode.cn/problems/queue-reconstruction-by-height){#406}

{{< tabs "406" >}}

{{% tab "python" %}}
```python
class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        people.sort(key=lambda x: (-x[0], x[1]))
        ans = []
        for p in people:
            ans.insert(p[1], p)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[][] reconstructQueue(int[][] people) {
        Arrays.sort(people, (a, b) -> a[0] == b[0] ? a[1] - b[1] : b[0] - a[0]);
        List<int[]> ans = new ArrayList<>(people.length);
        for (int[] p : people) {
            ans.add(p[1], p);
        }
        return ans.toArray(new int[ans.size()][]);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        vector<vector<int>> ans;
        for (const vector<int>& p : people)
            ans.insert(ans.begin() + p[1], p);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func reconstructQueue(people [][]int) [][]int {
	sort.Slice(people, func(i, j int) bool {
		a, b := people[i], people[j]
		return a[0] > b[0] || a[0] == b[0] && a[1] < b[1]
	})
	var ans [][]int
	for _, p := range people {
		i := p[1]
		ans = append(ans[:i], append([][]int{p}, ans[i:]...)...)
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

<p>假设有打乱顺序的一群人站成一个队列，数组 <code>people</code> 表示队列中一些人的属性（不一定按顺序）。每个 <code>people[i] = [h<sub>i</sub>, k<sub>i</sub>]</code> 表示第 <code>i</code> 个人的身高为 <code>h<sub>i</sub></code> ，前面 <strong>正好</strong> 有 <code>k<sub>i</sub></code><sub> </sub>个身高大于或等于 <code>h<sub>i</sub></code> 的人。</p>

<p>请你重新构造并返回输入数组 <code>people</code> 所表示的队列。返回的队列应该格式化为数组 <code>queue</code> ，其中 <code>queue[j] = [h<sub>j</sub>, k<sub>j</sub>]</code> 是队列中第 <code>j</code> 个人的属性（<code>queue[0]</code> 是排在队列前面的人）。</p>

<p> </p>

<ul>
</ul>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
<strong>输出：</strong>[[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
<strong>解释：</strong>
编号为 0 的人身高为 5 ，没有身高更高或者相同的人排在他前面。
编号为 1 的人身高为 7 ，没有身高更高或者相同的人排在他前面。
编号为 2 的人身高为 5 ，有 2 个身高更高或者相同的人排在他前面，即编号为 0 和 1 的人。
编号为 3 的人身高为 6 ，有 1 个身高更高或者相同的人排在他前面，即编号为 1 的人。
编号为 4 的人身高为 4 ，有 4 个身高更高或者相同的人排在他前面，即编号为 0、1、2、3 的人。
编号为 5 的人身高为 7 ，有 1 个身高更高或者相同的人排在他前面，即编号为 1 的人。
因此 [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]] 是重新构造后的队列。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>people = [[6,0],[5,0],[4,0],[3,2],[2,2],[1,4]]
<strong>输出：</strong>[[4,0],[5,0],[2,2],[3,2],[1,4],[6,0]]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= people.length <= 2000</code></li>
	<li><code>0 <= h<sub>i</sub> <= 10<sup>6</sup></code></li>
	<li><code>0 <= k<sub>i</sub> < people.length</code></li>
	<li>题目数据确保队列可以被重建</li>
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
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        people.sort(key=lambda x: (-x[0], x[1]))
        ans = []
        for p in people:
            ans.insert(p[1], p)
        return ans
```

#### Java

```java
class Solution {
    public int[][] reconstructQueue(int[][] people) {
        Arrays.sort(people, (a, b) -> a[0] == b[0] ? a[1] - b[1] : b[0] - a[0]);
        List<int[]> ans = new ArrayList<>(people.length);
        for (int[] p : people) {
            ans.add(p[1], p);
        }
        return ans.toArray(new int[ans.size()][]);
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        vector<vector<int>> ans;
        for (const vector<int>& p : people)
            ans.insert(ans.begin() + p[1], p);
        return ans;
    }
};
```

#### Go

```go
func reconstructQueue(people [][]int) [][]int {
	sort.Slice(people, func(i, j int) bool {
		a, b := people[i], people[j]
		return a[0] > b[0] || a[0] == b[0] && a[1] < b[1]
	})
	var ans [][]int
	for _, p := range people {
		i := p[1]
		ans = append(ans[:i], append([][]int{p}, ans[i:]...)...)
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [407. 接雨水 II](https://leetcode.cn/problems/trapping-rain-water-ii){#407}

{{< tabs "407" >}}

{{% tab "python" %}}
```python
class Solution:
    def trapRainWater(self, heightMap: List[List[int]]) -> int:
        m, n = len(heightMap), len(heightMap[0])
        vis = [[False] * n for _ in range(m)]
        pq = []
        for i in range(m):
            for j in range(n):
                if i == 0 or i == m - 1 or j == 0 or j == n - 1:
                    heappush(pq, (heightMap[i][j], i, j))
                    vis[i][j] = True
        ans = 0
        dirs = (-1, 0, 1, 0, -1)
        while pq:
            h, i, j = heappop(pq)
            for a, b in pairwise(dirs):
                x, y = i + a, j + b
                if x >= 0 and x < m and y >= 0 and y < n and not vis[x][y]:
                    ans += max(0, h - heightMap[x][y])
                    vis[x][y] = True
                    heappush(pq, (max(h, heightMap[x][y]), x, y))
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int trapRainWater(int[][] heightMap) {
        int m = heightMap.length, n = heightMap[0].length;
        boolean[][] vis = new boolean[m][n];
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    pq.offer(new int[] {heightMap[i][j], i, j});
                    vis[i][j] = true;
                }
            }
        }
        int ans = 0;
        int[] dirs = {-1, 0, 1, 0, -1};
        while (!pq.isEmpty()) {
            var p = pq.poll();
            for (int k = 0; k < 4; ++k) {
                int x = p[1] + dirs[k], y = p[2] + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y]) {
                    ans += Math.max(0, p[0] - heightMap[x][y]);
                    vis[x][y] = true;
                    pq.offer(new int[] {Math.max(p[0], heightMap[x][y]), x, y});
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
    int trapRainWater(vector<vector<int>>& heightMap) {
        using tii = tuple<int, int, int>;
        priority_queue<tii, vector<tii>, greater<tii>> pq;
        int m = heightMap.size(), n = heightMap[0].size();
        bool vis[m][n];
        memset(vis, 0, sizeof vis);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    pq.emplace(heightMap[i][j], i, j);
                    vis[i][j] = true;
                }
            }
        }
        int ans = 0;
        int dirs[5] = {-1, 0, 1, 0, -1};
        while (!pq.empty()) {
            auto [h, i, j] = pq.top();
            pq.pop();
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y]) {
                    ans += max(0, h - heightMap[x][y]);
                    vis[x][y] = true;
                    pq.emplace(max(heightMap[x][y], h), x, y);
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
func trapRainWater(heightMap [][]int) (ans int) {
	m, n := len(heightMap), len(heightMap[0])
	pq := hp{}
	vis := make([][]bool, m)
	for i, row := range heightMap {
		vis[i] = make([]bool, n)
		for j, v := range row {
			if i == 0 || i == m-1 || j == 0 || j == n-1 {
				heap.Push(&pq, tuple{v, i, j})
				vis[i][j] = true
			}
		}
	}
	dirs := []int{-1, 0, 1, 0, -1}
	for len(pq) > 0 {
		p := heap.Pop(&pq).(tuple)
		for k := 0; k < 4; k++ {
			x, y := p.i+dirs[k], p.j+dirs[k+1]
			if x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] {
				ans += max(0, p.v-heightMap[x][y])
				vis[x][y] = true
				heap.Push(&pq, tuple{max(p.v, heightMap[x][y]), x, y})
			}
		}
	}
	return
}

type tuple struct{ v, i, j int }
type hp []tuple

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].v < h[j].v }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)        { *h = append(*h, v.(tuple)) }
func (h *hp) Pop() any          { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个&nbsp;<code>m x n</code>&nbsp;的矩阵，其中的值均为非负整数，代表二维高度图每个单元的高度，请计算图中形状最多能接多少体积的雨水。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0407.Trapping%20Rain%20Water%20II/images/trap1-3d.jpg" /></p>

<pre>
<strong>输入:</strong> heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
<strong>输出:</strong> 4
<strong>解释:</strong> 下雨后，雨水将会被上图蓝色的方块中。总的接雨水量为1+2+1=4。
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0407.Trapping%20Rain%20Water%20II/images/trap2-3d.jpg" /></p>

<pre>
<strong>输入:</strong> heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
<strong>输出:</strong> 10
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>m == heightMap.length</code></li>
	<li><code>n == heightMap[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>0 &lt;= heightMap[i][j] &lt;= 2 * 10<sup>4</sup></code></li>
</ul>

<p>&nbsp;</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：优先队列（小根堆）

接雨水问题的变种，由于矩阵的边界上的高度是确定的，因此可以将矩阵的边界上的高度加入优先队列，然后从优先队列中取出最小的高度，然后将其四周的高度与其比较，如果四周的高度小于当前高度，则可以接雨水，接雨水的体积为当前高度减去四周的高度，然后将较大的高度加入优先队列，重复上述过程，直到优先队列为空。

时间复杂度 $O(m \times n \times \log (m \times n))$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别为矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def trapRainWater(self, heightMap: List[List[int]]) -> int:
        m, n = len(heightMap), len(heightMap[0])
        vis = [[False] * n for _ in range(m)]
        pq = []
        for i in range(m):
            for j in range(n):
                if i == 0 or i == m - 1 or j == 0 or j == n - 1:
                    heappush(pq, (heightMap[i][j], i, j))
                    vis[i][j] = True
        ans = 0
        dirs = (-1, 0, 1, 0, -1)
        while pq:
            h, i, j = heappop(pq)
            for a, b in pairwise(dirs):
                x, y = i + a, j + b
                if x >= 0 and x < m and y >= 0 and y < n and not vis[x][y]:
                    ans += max(0, h - heightMap[x][y])
                    vis[x][y] = True
                    heappush(pq, (max(h, heightMap[x][y]), x, y))
        return ans
```

#### Java

```java
class Solution {
    public int trapRainWater(int[][] heightMap) {
        int m = heightMap.length, n = heightMap[0].length;
        boolean[][] vis = new boolean[m][n];
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    pq.offer(new int[] {heightMap[i][j], i, j});
                    vis[i][j] = true;
                }
            }
        }
        int ans = 0;
        int[] dirs = {-1, 0, 1, 0, -1};
        while (!pq.isEmpty()) {
            var p = pq.poll();
            for (int k = 0; k < 4; ++k) {
                int x = p[1] + dirs[k], y = p[2] + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y]) {
                    ans += Math.max(0, p[0] - heightMap[x][y]);
                    vis[x][y] = true;
                    pq.offer(new int[] {Math.max(p[0], heightMap[x][y]), x, y});
                }
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
    int trapRainWater(vector<vector<int>>& heightMap) {
        using tii = tuple<int, int, int>;
        priority_queue<tii, vector<tii>, greater<tii>> pq;
        int m = heightMap.size(), n = heightMap[0].size();
        bool vis[m][n];
        memset(vis, 0, sizeof vis);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    pq.emplace(heightMap[i][j], i, j);
                    vis[i][j] = true;
                }
            }
        }
        int ans = 0;
        int dirs[5] = {-1, 0, 1, 0, -1};
        while (!pq.empty()) {
            auto [h, i, j] = pq.top();
            pq.pop();
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y]) {
                    ans += max(0, h - heightMap[x][y]);
                    vis[x][y] = true;
                    pq.emplace(max(heightMap[x][y], h), x, y);
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func trapRainWater(heightMap [][]int) (ans int) {
	m, n := len(heightMap), len(heightMap[0])
	pq := hp{}
	vis := make([][]bool, m)
	for i, row := range heightMap {
		vis[i] = make([]bool, n)
		for j, v := range row {
			if i == 0 || i == m-1 || j == 0 || j == n-1 {
				heap.Push(&pq, tuple{v, i, j})
				vis[i][j] = true
			}
		}
	}
	dirs := []int{-1, 0, 1, 0, -1}
	for len(pq) > 0 {
		p := heap.Pop(&pq).(tuple)
		for k := 0; k < 4; k++ {
			x, y := p.i+dirs[k], p.j+dirs[k+1]
			if x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] {
				ans += max(0, p.v-heightMap[x][y])
				vis[x][y] = true
				heap.Push(&pq, tuple{max(p.v, heightMap[x][y]), x, y})
			}
		}
	}
	return
}

type tuple struct{ v, i, j int }
type hp []tuple

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].v < h[j].v }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)        { *h = append(*h, v.(tuple)) }
func (h *hp) Pop() any          { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [408. 有效单词缩写 🔒](https://leetcode.cn/problems/valid-word-abbreviation){#408}

{{< tabs "408" >}}

{{% tab "python" %}}
```python
class Solution:
    def validWordAbbreviation(self, word: str, abbr: str) -> bool:
        m, n = len(word), len(abbr)
        i = j = x = 0
        while i < m and j < n:
            if abbr[j].isdigit():
                if abbr[j] == "0" and x == 0:
                    return False
                x = x * 10 + int(abbr[j])
            else:
                i += x
                x = 0
                if i >= m or word[i] != abbr[j]:
                    return False
                i += 1
            j += 1
        return i + x == m and j == n
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean validWordAbbreviation(String word, String abbr) {
        int m = word.length(), n = abbr.length();
        int i = 0, j = 0, x = 0;
        for (; i < m && j < n; ++j) {
            char c = abbr.charAt(j);
            if (Character.isDigit(c)) {
                if (c == '0' && x == 0) {
                    return false;
                }
                x = x * 10 + (c - '0');
            } else {
                i += x;
                x = 0;
                if (i >= m || word.charAt(i) != c) {
                    return false;
                }
                ++i;
            }
        }
        return i + x == m && j == n;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int m = word.size(), n = abbr.size();
        int i = 0, j = 0, x = 0;
        for (; i < m && j < n; ++j) {
            if (isdigit(abbr[j])) {
                if (abbr[j] == '0' && x == 0) {
                    return false;
                }
                x = x * 10 + (abbr[j] - '0');
            } else {
                i += x;
                x = 0;
                if (i >= m || word[i] != abbr[j]) {
                    return false;
                }
                ++i;
            }
        }
        return i + x == m && j == n;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func validWordAbbreviation(word string, abbr string) bool {
	m, n := len(word), len(abbr)
	i, j, x := 0, 0, 0
	for ; i < m && j < n; j++ {
		if abbr[j] >= '0' && abbr[j] <= '9' {
			if x == 0 && abbr[j] == '0' {
				return false
			}
			x = x*10 + int(abbr[j]-'0')
		} else {
			i += x
			x = 0
			if i >= m || word[i] != abbr[j] {
				return false
			}
			i++
		}
	}
	return i+x == m && j == n
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function validWordAbbreviation(word: string, abbr: string): boolean {
    const [m, n] = [word.length, abbr.length];
    let [i, j, x] = [0, 0, 0];
    for (; i < m && j < n; ++j) {
        if (abbr[j] >= '0' && abbr[j] <= '9') {
            if (abbr[j] === '0' && x === 0) {
                return false;
            }
            x = x * 10 + Number(abbr[j]);
        } else {
            i += x;
            x = 0;
            if (i >= m || word[i++] !== abbr[j]) {
                return false;
            }
        }
    }
    return i + x === m && j === n;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>字符串可以用 <strong>缩写</strong> 进行表示，<strong>缩写</strong> 的方法是将任意数量的 <strong>不相邻</strong> 的子字符串替换为相应子串的长度。例如，字符串 <code>"substitution"</code> 可以缩写为（不止这几种方法）：</p>

<ul>
	<li><code>"s10n"</code> (<code>"s <em><strong>ubstitutio</strong></em> n"</code>)</li>
	<li><code>"sub4u4"</code> (<code>"sub <em><strong>stit</strong></em> u <em><strong>tion</strong></em>"</code>)</li>
	<li><code>"12"</code> (<code>"<em><strong>substitution</strong></em>"</code>)</li>
	<li><code>"su3i1u2on"</code> (<code>"su <em><strong>bst</strong></em> i <em><strong>t</strong></em> u <em><strong>ti</strong></em> on"</code>)</li>
	<li><code>"substitution"</code> (没有替换子字符串)</li>
</ul>

<p>下列是不合法的缩写：</p>

<ul>
	<li><code>"s55n"</code>&nbsp;(<code>"s&nbsp;<u>ubsti</u>&nbsp;<u>tutio</u>&nbsp;n"</code>，两处缩写相邻)</li>
	<li><code>"s010n"</code>&nbsp;(缩写存在前导零)</li>
	<li><code>"s0ubstitution"</code>&nbsp;(缩写是一个空字符串)</li>
</ul>

<p>给你一个字符串单词 <code>word</code> 和一个缩写&nbsp;<code>abbr</code>&nbsp;，判断这个缩写是否可以是给定单词的缩写。</p>

<p><strong>子字符串</strong>是字符串中连续的<strong>非空</strong>字符序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>word = "internationalization", abbr = "i12iz4n"
<strong>输出：</strong>true
<strong>解释：</strong>单词 "internationalization" 可以缩写为 "i12iz4n" ("i <em><strong>nternational</strong></em> iz <em><strong>atio</strong></em> n") 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>word = "apple", abbr = "a2e"
<strong>输出：</strong>false
<strong>解释：</strong>单词 "apple" 无法缩写为 "a2e" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 20</code></li>
	<li><code>word</code> 仅由小写英文字母组成</li>
	<li><code>1 &lt;= abbr.length &lt;= 10</code></li>
	<li><code>abbr</code> 由小写英文字母和数字组成</li>
	<li><code>abbr</code> 中的所有数字均符合 32-bit 整数范围</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以直接模拟字符匹配替换。

假设字符串 $word$ 和字符串 $abbr$ 的长度分别为 $m$ 和 $n$，我们使用两个指针 $i$ 和 $j$ 分别指向字符串 $word$ 和字符串 $abbr$ 的初始位置，用一个整型变量 $x$ 记录当前匹配到的 $abbr$ 的数字。

循环匹配字符串 $word$ 和字符串 $abbr$ 的每个字符：

如果指针 $j$ 指向的字符 $abbr[j]$ 是数字，如果 $abbr[j]$ 是 `'0'`，并且 $x$ 为 $0$，说明 $abbr$ 中的数字含有前导零，因此不是合法的缩写，返回 `false`；否则将 $x$ 更新为 $x \times 10 + abbr[j] - '0'$。

如果指针 $j$ 指向的字符 $abbr[j]$ 不是数字，那么我们此时将指针 $i$ 往前移动 $x$ 个位置，然后将 $x$ 重置为 $0$。如果此时 $i \geq m$ 或者 $word[i] \neq abbr[j]$，说明两个字符串无法匹配，返回 `false`；否则将指针 $i$ 往前移动 $1$ 个位置。

然后我们将指针 $j$ 往前移动 $1$ 个位置，重复上述过程，直到 $i$ 超出字符串 $word$ 的长度或者 $j$ 超出字符串 $abbr$ 的长度。

最后，如果 $i + x$ 等于 $m$ 且 $j$ 等于 $n$，说明字符串 $word$ 可以缩写成字符串 $abbr$，返回 `true`；否则返回 `false`。

时间复杂度 $O(m + n)$，其中 $m$ 和 $n$ 分别是字符串 $word$ 和字符串 $abbr$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def validWordAbbreviation(self, word: str, abbr: str) -> bool:
        m, n = len(word), len(abbr)
        i = j = x = 0
        while i < m and j < n:
            if abbr[j].isdigit():
                if abbr[j] == "0" and x == 0:
                    return False
                x = x * 10 + int(abbr[j])
            else:
                i += x
                x = 0
                if i >= m or word[i] != abbr[j]:
                    return False
                i += 1
            j += 1
        return i + x == m and j == n
```

#### Java

```java
class Solution {
    public boolean validWordAbbreviation(String word, String abbr) {
        int m = word.length(), n = abbr.length();
        int i = 0, j = 0, x = 0;
        for (; i < m && j < n; ++j) {
            char c = abbr.charAt(j);
            if (Character.isDigit(c)) {
                if (c == '0' && x == 0) {
                    return false;
                }
                x = x * 10 + (c - '0');
            } else {
                i += x;
                x = 0;
                if (i >= m || word.charAt(i) != c) {
                    return false;
                }
                ++i;
            }
        }
        return i + x == m && j == n;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int m = word.size(), n = abbr.size();
        int i = 0, j = 0, x = 0;
        for (; i < m && j < n; ++j) {
            if (isdigit(abbr[j])) {
                if (abbr[j] == '0' && x == 0) {
                    return false;
                }
                x = x * 10 + (abbr[j] - '0');
            } else {
                i += x;
                x = 0;
                if (i >= m || word[i] != abbr[j]) {
                    return false;
                }
                ++i;
            }
        }
        return i + x == m && j == n;
    }
};
```

#### Go

```go
func validWordAbbreviation(word string, abbr string) bool {
	m, n := len(word), len(abbr)
	i, j, x := 0, 0, 0
	for ; i < m && j < n; j++ {
		if abbr[j] >= '0' && abbr[j] <= '9' {
			if x == 0 && abbr[j] == '0' {
				return false
			}
			x = x*10 + int(abbr[j]-'0')
		} else {
			i += x
			x = 0
			if i >= m || word[i] != abbr[j] {
				return false
			}
			i++
		}
	}
	return i+x == m && j == n
}
```

#### TypeScript

```ts
function validWordAbbreviation(word: string, abbr: string): boolean {
    const [m, n] = [word.length, abbr.length];
    let [i, j, x] = [0, 0, 0];
    for (; i < m && j < n; ++j) {
        if (abbr[j] >= '0' && abbr[j] <= '9') {
            if (abbr[j] === '0' && x === 0) {
                return false;
            }
            x = x * 10 + Number(abbr[j]);
        } else {
            i += x;
            x = 0;
            if (i >= m || word[i++] !== abbr[j]) {
                return false;
            }
        }
    }
    return i + x === m && j === n;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [409. 最长回文串](https://leetcode.cn/problems/longest-palindrome){#409}

{{< tabs "409" >}}

{{% tab "python" %}}
```python
class Solution:
    def longestPalindrome(self, s: str) -> int:
        odd = defaultdict(int)
        cnt = 0
        for c in s:
            odd[c] ^= 1
            cnt += 1 if odd[c] else -1
        return len(s) - cnt + 1 if cnt else len(s)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int longestPalindrome(String s) {
        int[] odd = new int[128];
        int n = s.length();
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            odd[s.charAt(i)] ^= 1;
            cnt += odd[s.charAt(i)] == 1 ? 1 : -1;
        }
        return cnt > 0 ? n - cnt + 1 : n;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        int odd[128]{};
        int n = s.length();
        int cnt = 0;
        for (char& c : s) {
            odd[c] ^= 1;
            cnt += odd[c] ? 1 : -1;
        }
        return cnt ? n - cnt + 1 : n;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func longestPalindrome(s string) (ans int) {
	odd := [128]int{}
	cnt := 0
	for _, c := range s {
		odd[c] ^= 1
		cnt += odd[c]
		if odd[c] == 0 {
			cnt--
		}
	}
	if cnt > 0 {
		return len(s) - cnt + 1
	}
	return len(s)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function longestPalindrome(s: string): number {
    const odd: Record<string, number> = {};
    let cnt = 0;
    for (const c of s) {
        odd[c] ^= 1;
        cnt += odd[c] ? 1 : -1;
    }
    return cnt ? s.length - cnt + 1 : s.length;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    pub fn longest_palindrome(s: String) -> i32 {
        let mut cnt = HashMap::new();
        for ch in s.chars() {
            *cnt.entry(ch).or_insert(0) += 1;
        }

        let mut ans = 0;
        for &v in cnt.values() {
            ans += (v / 2) * 2;
        }

        if ans < (s.len() as i32) {
            ans += 1;
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

<p>给定一个包含大写字母和小写字母的字符串<meta charset="UTF-8" />&nbsp;<code>s</code>&nbsp;，返回&nbsp;<em>通过这些字母构造成的 <strong>最长的 <span data-keyword="palindrome-string">回文串</span></strong></em>&nbsp;的长度。</p>

<p>在构造过程中，请注意 <strong>区分大小写</strong> 。比如&nbsp;<code>"Aa"</code>&nbsp;不能当做一个回文字符串。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1: </strong></p>

<pre>
<strong>输入:</strong>s = "abccccdd"
<strong>输出:</strong>7
<strong>解释:</strong>
我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
</pre>

<p><strong class="example">示例 2:</strong></p>

<pre>
<strong>输入:</strong>s = "a"
<strong>输出:</strong>1
<strong>解释：</strong>可以构造的最长回文串是"a"，它的长度是 1。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 2000</code></li>
	<li><code>s</code>&nbsp;只由小写 <strong>和/或</strong> 大写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

一个合法的回文字符串，最多存在一个出现奇数次数的字符，其余字符出现次数均为偶数。

因此，我们可以先遍历字符串 $s$，统计每个字符出现的次数，记录在数组或哈希表 $cnt$ 中。

然后，我们遍历 $cnt$，对于每个次数 $v$，将 $v$ 除以 2 取整，再乘以 2，累加到答案 $ans$ 中。

最后，如果答案小于字符串 $s$ 的长度，则将答案加一，返回 $ans$。

时间复杂度 $O(n + |\Sigma|)$，空间复杂度 $O(|\Sigma|)$。其中，$n$ 为字符串 $s$ 的长度，而 $|\Sigma|$ 为字符集大小，在本题中 $|\Sigma| = 128$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestPalindrome(self, s: str) -> int:
        cnt = Counter(s)
        ans = sum(v // 2 * 2 for v in cnt.values())
        ans += int(ans < len(s))
        return ans
```

#### Java

```java
class Solution {
    public int longestPalindrome(String s) {
        int[] cnt = new int[128];
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            ++cnt[s.charAt(i)];
        }
        int ans = 0;
        for (int v : cnt) {
            ans += v / 2 * 2;
        }
        ans += ans < n ? 1 : 0;
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        int cnt[128]{};
        for (char c : s) {
            ++cnt[c];
        }
        int ans = 0;
        for (int v : cnt) {
            ans += v / 2 * 2;
        }
        ans += ans < s.size();
        return ans;
    }
};
```

#### Go

```go
func longestPalindrome(s string) (ans int) {
	cnt := [128]int{}
	for _, c := range s {
		cnt[c]++
	}
	for _, v := range cnt {
		ans += v / 2 * 2
	}
	if ans < len(s) {
		ans++
	}
	return
}
```

#### TypeScript

```ts
function longestPalindrome(s: string): number {
    const cnt: Record<string, number> = {};
    for (const c of s) {
        cnt[c] = (cnt[c] || 0) + 1;
    }
    let ans = Object.values(cnt).reduce((acc, v) => acc + Math.floor(v / 2) * 2, 0);
    ans += ans < s.length ? 1 : 0;
    return ans;
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn longest_palindrome(s: String) -> i32 {
        let mut cnt = HashMap::new();
        for ch in s.chars() {
            *cnt.entry(ch).or_insert(0) += 1;
        }

        let mut ans = 0;
        for &v in cnt.values() {
            ans += (v / 2) * 2;
        }

        if ans < (s.len() as i32) {
            ans += 1;
        }

        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：位运算 + 计数

我们可以使用一个数组或哈希表 $odd$ 记录字符串 $s$ 中每个字符是否出现奇数次，用一个整型变量 $cnt$ 记录出现奇数次的字符个数。

遍历字符串 $s$，对于每个字符 $c$，将 $odd[c]$ 取反，即 $0 \rightarrow 1$, $1 \rightarrow 0$。如果 $odd[c]$ 由 $0$ 变为 $1$，则 $cnt$ 加一；如果 $odd[c]$ 由 $1$ 变为 $0$，则 $cnt$ 减一。

最后，如果 $cnt$ 大于 $0$，答案为 $n - cnt + 1$，否则答案为 $n$。

时间复杂度 $O(n)$，空间复杂度 $O(|\Sigma|)$。其中，$n$ 为字符串 $s$ 的长度，而 $|\Sigma|$ 为字符集大小，在本题中 $|\Sigma| = 128$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestPalindrome(self, s: str) -> int:
        odd = defaultdict(int)
        cnt = 0
        for c in s:
            odd[c] ^= 1
            cnt += 1 if odd[c] else -1
        return len(s) - cnt + 1 if cnt else len(s)
```

#### Java

```java
class Solution {
    public int longestPalindrome(String s) {
        int[] odd = new int[128];
        int n = s.length();
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            odd[s.charAt(i)] ^= 1;
            cnt += odd[s.charAt(i)] == 1 ? 1 : -1;
        }
        return cnt > 0 ? n - cnt + 1 : n;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        int odd[128]{};
        int n = s.length();
        int cnt = 0;
        for (char& c : s) {
            odd[c] ^= 1;
            cnt += odd[c] ? 1 : -1;
        }
        return cnt ? n - cnt + 1 : n;
    }
};
```

#### Go

```go
func longestPalindrome(s string) (ans int) {
	odd := [128]int{}
	cnt := 0
	for _, c := range s {
		odd[c] ^= 1
		cnt += odd[c]
		if odd[c] == 0 {
			cnt--
		}
	}
	if cnt > 0 {
		return len(s) - cnt + 1
	}
	return len(s)
}
```

#### TypeScript

```ts
function longestPalindrome(s: string): number {
    const odd: Record<string, number> = {};
    let cnt = 0;
    for (const c of s) {
        odd[c] ^= 1;
        cnt += odd[c] ? 1 : -1;
    }
    return cnt ? s.length - cnt + 1 : s.length;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
