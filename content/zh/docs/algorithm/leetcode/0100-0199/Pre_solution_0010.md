---
title: "0190_颠倒二进制位"
date: 2025-10-08T18:45:43+08:00
weight: 10
tags: [Shell, 二叉树, 位运算, 分治, 动态规划, 广度优先搜索, 数据库, 数组, 树, 深度优先搜索]
---

{{< markmap >}}
### [0190_颠倒二进制位](#190)
#### [位运算](#190)
#### [分治](#190)
### [0191_位1的个数](#191)
#### [位运算](#191)
#### [分治](#191)
### [0192_统计词频](#192)
#### [Shell](#192)
### [0193_有效电话号码](#193)
#### [Shell](#193)
### [0194_转置文件](#194)
#### [Shell](#194)
### [0195_第十行](#195)
#### [Shell](#195)
### [0196_删除重复的电子邮箱](#196)
#### [数据库](#196)
### [0197_上升的温度](#197)
#### [数据库](#197)
### [0198_打家劫舍](#198)
#### [数组](#198)
#### [动态规划](#198)
### [0199_二叉树的右视图](#199)
#### [树](#199)
#### [深度优先搜索](#199)
#### [广度优先搜索](#199)
#### [二叉树](#199)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0190_颠倒二进制位
___
#### 位运算
___
#### 分治
---
### 0191_位1的个数
___
#### 位运算
___
#### 分治
---
### 0192_统计词频
___
#### Shell
---
### 0193_有效电话号码
___
#### Shell
---
### 0194_转置文件
___
#### Shell
---
### 0195_第十行
___
#### Shell
---
### 0196_删除重复的电子邮箱
___
#### 数据库
---
### 0197_上升的温度
___
#### 数据库
---
### 0198_打家劫舍
___
#### 数组
___
#### 动态规划
---
### 0199_二叉树的右视图
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
| Shell | 二叉树 | 位运算 |
| 分治 | 动态规划 | 广度优先搜索 |
| 数据库 | 数组 | 树 |
| 深度优先搜索 |  |  |

# [190. 颠倒二进制位](https://leetcode.cn/problems/reverse-bits){#190}

{{< tabs "190" >}}

{{% tab "python" %}}
```python
class Solution:
    def reverseBits(self, n: int) -> int:
        ans = 0
        for i in range(32):
            ans |= (n & 1) << (31 - i)
            n >>= 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
public class Solution {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        int ans = 0;
        for (int i = 0; i < 32 && n != 0; ++i) {
            ans |= (n & 1) << (31 - i);
            n >>>= 1;
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
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (int i = 0; i < 32 && n; ++i) {
            ans |= (n & 1) << (31 - i);
            n >>= 1;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func reverseBits(n uint32) (ans uint32) {
	for i := 0; i < 32; i++ {
		ans |= (n & 1) << (31 - i)
		n >>= 1
	}
	return
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn reverse_bits(mut n: u32) -> u32 {
        let mut ans = 0;
        for i in 0..32 {
            ans |= (n & 1) << (31 - i);
            n >>= 1;
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} n - a positive integer
 * @return {number} - a positive integer
 */
var reverseBits = function (n) {
    let ans = 0;
    for (let i = 0; i < 32 && n; ++i) {
        ans |= (n & 1) << (31 - i);
        n >>= 1;
    }
    return ans >>> 0;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>颠倒给定的 32 位无符号整数的二进制位。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>n = 43261596</span></p>

<p><span class="example-io"><b>输出：</b>964176192</span></p>

<p><strong>解释：</strong></p>

<table>
	<tbody>
		<tr>
			<th>整数</th>
			<th>二进制</th>
		</tr>
		<tr>
			<td>43261596</td>
			<td>00000010100101000001111010011100</td>
		</tr>
		<tr>
			<td>964176192</td>
			<td>00111001011110000010100101000000</td>
		</tr>
	</tbody>
</table>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>n = 2147483644</span></p>

<p><span class="example-io"><b>输出：</b>1073741822</span></p>

<p><strong>解释：</strong></p>

<table>
	<tbody>
		<tr>
			<th>整数</th>
			<th>二进制</th>
		</tr>
		<tr>
			<td>2147483644</td>
			<td>01111111111111111111111111111100</td>
		</tr>
		<tr>
			<td>1073741822</td>
			<td>00111111111111111111111111111110</td>
		</tr>
	</tbody>
</table>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= n &lt;= 2<sup>31</sup>&nbsp;- 2</code></li>
	<li><code>n</code>&nbsp;为偶数</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶</strong>: 如果多次调用这个函数，你将如何优化你的算法？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：位运算

我们可以从低位到高位，逐个取出 `n` 的每一位，然后将其放到 `ans` 的对应位置上。

比如，对于第 $i$ 位，我们可以通过 `(n & 1) << (31 - i)` 来取出 `n` 的第 $i$ 位，并将其放到 `ans` 的第 $31 - i$ 位上，然后将 `n` 右移一位。

时间复杂度 $(\log n)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def reverseBits(self, n: int) -> int:
        ans = 0
        for i in range(32):
            ans |= (n & 1) << (31 - i)
            n >>= 1
        return ans
```

#### Java

```java
public class Solution {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        int ans = 0;
        for (int i = 0; i < 32 && n != 0; ++i) {
            ans |= (n & 1) << (31 - i);
            n >>>= 1;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (int i = 0; i < 32 && n; ++i) {
            ans |= (n & 1) << (31 - i);
            n >>= 1;
        }
        return ans;
    }
};
```

#### Go

```go
func reverseBits(n uint32) (ans uint32) {
	for i := 0; i < 32; i++ {
		ans |= (n & 1) << (31 - i)
		n >>= 1
	}
	return
}
```

#### Rust

```rust
impl Solution {
    pub fn reverse_bits(mut n: u32) -> u32 {
        let mut ans = 0;
        for i in 0..32 {
            ans |= (n & 1) << (31 - i);
            n >>= 1;
        }
        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number} n - a positive integer
 * @return {number} - a positive integer
 */
var reverseBits = function (n) {
    let ans = 0;
    for (let i = 0; i < 32 && n; ++i) {
        ans |= (n & 1) << (31 - i);
        n >>= 1;
    }
    return ans >>> 0;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [191. 位1的个数](https://leetcode.cn/problems/number-of-1-bits){#191}

{{< tabs "191" >}}

{{% tab "txt" %}}
```txt
[0, 1, 0, 1] // 5
[0, 1, 0, 0] // 5 - 1 = 4
[0, 1, 0, 0] // 5 & 4 = 4

[0, 1, 0, 0] // 4
[0, 0, 1, 1] // 4 - 1 = 3
[0, 0, 0, 0] // 4 & 3 = 0
```
{{% /tab %}}
{{% tab "python" %}}
```python
class Solution:
    def hammingWeight(self, n: int) -> int:
        ans = 0
        while n:
            n -= n & -n
            ans += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int ans = 0;
        while (n != 0) {
            n -= (n & -n);
            ++ans;
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
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n) {
            n -= (n & -n);
            ++ans;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func hammingWeight(num uint32) int {
	ans := 0
	for num != 0 {
		num -= (num & -num)
		ans++
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function hammingWeight(n: number): number {
    let count = 0;
    while (n) {
        n -= n & -n;
        count++;
    }
    return count;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn hammingWeight(mut n: u32) -> i32 {
        let mut res = 0;
        while n != 0 {
            n &= n - 1;
            res += 1;
        }
        res
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} n
 * @return {number}
 */
var hammingWeight = function (n) {
    let count = 0;
    while (n) {
        n -= n & -n;
        count++;
    }
    return count;
};
```
{{% /tab %}}
{{% tab "c" %}}
```c
int hammingWeight(uint32_t n) {
    int ans = 0;
    while (n) {
        n &= n - 1;
        ans++;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "kotlin" %}}
```kotlin
class Solution {
    fun hammingWeight(n: Int): Int {
        var count = 0
        var num = n
        while (num != 0) {
            num -= num and (-num)
            count++
        }
        return count
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个正整数 <code>n</code>，编写一个函数，获取一个正整数的二进制形式并返回其二进制表达式中 <span data-keyword="set-bit">设置位</span> 的个数（也被称为<a href="https://baike.baidu.com/item/%E6%B1%89%E6%98%8E%E9%87%8D%E9%87%8F" target="_blank">汉明重量</a>）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 11
<strong>输出：</strong>3
<strong>解释：</strong>输入的二进制串 <code><strong>1011</strong>&nbsp;中，共有 3 个设置位。</code>
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 128
<strong>输出：</strong>1
<strong>解释：</strong>输入的二进制串 <strong>10000000</strong>&nbsp;中，共有 1 个设置位。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 2147483645
<strong>输出：</strong>30
<strong>解释：</strong>输入的二进制串 <strong>1111111111111111111111111111101</strong> 中，共有 30 个设置位。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<ul>
</ul>

<p>&nbsp;</p>

<p><strong>进阶</strong>：</p>

<ul>
	<li>如果多次调用这个函数，你将如何优化你的算法？</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：位运算

利用 `n & (n - 1)` 消除 `n` 中最后一位 1 这一特点，优化过程：

```txt
HAMMING-WEIGHT(n)
    r = 0
    while n != 0
        n &= n - 1
        r += 1
    r
```

以 5 为例，演示推演过程：

```txt
[0, 1, 0, 1] // 5
[0, 1, 0, 0] // 5 - 1 = 4
[0, 1, 0, 0] // 5 & 4 = 4

[0, 1, 0, 0] // 4
[0, 0, 1, 1] // 4 - 1 = 3
[0, 0, 0, 0] // 4 & 3 = 0
```

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def hammingWeight(self, n: int) -> int:
        ans = 0
        while n:
            n &= n - 1
            ans += 1
        return ans
```

#### Java

```java
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int ans = 0;
        while (n != 0) {
            n &= n - 1;
            ++ans;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n) {
            n &= n - 1;
            ++ans;
        }
        return ans;
    }
};
```

#### Go

```go
func hammingWeight(num uint32) int {
	ans := 0
	for num != 0 {
		num &= num - 1
		ans++
	}
	return ans
}
```

#### TypeScript

```ts
function hammingWeight(n: number): number {
    let ans: number = 0;
    while (n !== 0) {
        ans++;
        n &= n - 1;
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn hammingWeight(n: u32) -> i32 {
        n.count_ones() as i32
    }
}
```

#### JavaScript

```js
/**
 * @param {number} n - a positive integer
 * @return {number}
 */
var hammingWeight = function (n) {
    let ans = 0;
    while (n) {
        n &= n - 1;
        ++ans;
    }
    return ans;
};
```

#### C

```c
int hammingWeight(uint32_t n) {
    int ans = 0;
    while (n) {
        n &= n - 1;
        ans++;
    }
    return ans;
}
```

#### Kotlin

```kotlin
class Solution {
    fun hammingWeight(n: Int): Int {
        var count = 0
        var num = n
        while (num != 0) {
            num = num and (num - 1)
            count++
        }
        return count
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：lowbit

`x -= (x & -x)` 可以消除二进制形式的最后一位 1。

同 [剑指 Offer 15. 二进制中 1 的个数](https://github.com/doocs/leetcode/blob/main/lcof/面试题15.%20二进制中1的个数/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def hammingWeight(self, n: int) -> int:
        ans = 0
        while n:
            n -= n & -n
            ans += 1
        return ans
```

#### Java

```java
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int ans = 0;
        while (n != 0) {
            n -= (n & -n);
            ++ans;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n) {
            n -= (n & -n);
            ++ans;
        }
        return ans;
    }
};
```

#### Go

```go
func hammingWeight(num uint32) int {
	ans := 0
	for num != 0 {
		num -= (num & -num)
		ans++
	}
	return ans
}
```

#### TypeScript

```ts
function hammingWeight(n: number): number {
    let count = 0;
    while (n) {
        n -= n & -n;
        count++;
    }
    return count;
}
```

#### Rust

```rust
impl Solution {
    pub fn hammingWeight(mut n: u32) -> i32 {
        let mut res = 0;
        while n != 0 {
            n &= n - 1;
            res += 1;
        }
        res
    }
}
```

#### JavaScript

```js
/**
 * @param {number} n
 * @return {number}
 */
var hammingWeight = function (n) {
    let count = 0;
    while (n) {
        n -= n & -n;
        count++;
    }
    return count;
};
```

#### Kotlin

```kotlin
class Solution {
    fun hammingWeight(n: Int): Int {
        var count = 0
        var num = n
        while (num != 0) {
            num -= num and (-num)
            count++
        }
        return count
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [192. 统计词频](https://leetcode.cn/problems/word-frequency){#192}

{{< tabs "192" >}}

{{% tab "bash" %}}
```bash
# Read from the file words.txt and output the word frequency list to stdout.
cat words.txt | tr -s ' ' '\n' | sort | uniq -c | sort -nr | awk '{print $2, $1}'
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>写一个 bash 脚本以统计一个文本文件&nbsp;<code>words.txt</code>&nbsp;中每个单词出现的<span data-keyword="frequency-textfile">频率</span>。</p>

<p>为了简单起见，你可以假设：</p>

<ul>
	<li><code>words.txt</code>只包括小写字母和&nbsp;<code>' '</code>&nbsp;。</li>
	<li>每个单词只由小写字母组成。</li>
	<li>单词间由一个或多个空格字符分隔。</li>
</ul>

<p><strong>示例:</strong></p>

<p>假设 <code>words.txt</code> 内容如下：</p>

<pre>
the day is sunny the the
the sunny is is
</pre>

<p>你的脚本应当输出（以词频降序排列）：</p>

<pre>
the 4
is 3
sunny 2
day 1
</pre>

<p><strong>说明:</strong></p>

<ul>
	<li>不要担心词频相同的单词的排序问题，每个单词出现的频率都是唯一的。</li>
	<li>你可以使用一行&nbsp;<a href="http://tldp.org/HOWTO/Bash-Prog-Intro-HOWTO-4.html">Unix pipes</a>&nbsp;实现吗？</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：awk

<!-- tabs:start -->

#### Shell

```bash
# Read from the file words.txt and output the word frequency list to stdout.
cat words.txt | tr -s ' ' '\n' | sort | uniq -c | sort -nr | awk '{print $2, $1}'
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [193. 有效电话号码](https://leetcode.cn/problems/valid-phone-numbers){#193}

{{< tabs "193" >}}

{{% tab "bash" %}}
```bash
# Read from the file file.txt and output all valid phone numbers to stdout.
awk '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/' file.txt
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个包含电话号码列表（一行一个电话号码）的文本文件 <code>file.txt</code>，写一个单行 bash 脚本输出所有有效的电话号码。</p>

<p>你可以假设一个有效的电话号码必须满足以下两种格式： (xxx) xxx-xxxx 或 xxx-xxx-xxxx。（x 表示一个数字）</p>

<p>你也可以假设每行前后没有多余的空格字符。</p>

<p> </p>

<p><strong>示例：</strong></p>

<p>假设 <code>file.txt</code> 内容如下：</p>

<pre>
987-123-4567
123 456 7890
(123) 456-7890
</pre>

<p>你的脚本应当输出下列有效的电话号码：</p>

<pre>
987-123-4567
(123) 456-7890
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：awk

<!-- tabs:start -->

#### Shell

```bash
# Read from the file file.txt and output all valid phone numbers to stdout.
awk '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/' file.txt
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [194. 转置文件](https://leetcode.cn/problems/transpose-file){#194}

{{< tabs "194" >}}

{{% tab "bash" %}}
```bash
# Read from the file file.txt and print its transposed content to stdout.
awk '
{
  for (i=1; i<=NF; i++) {
    if(NR == 1) {
      res[i] = re$i
    } else {
      res[i] = res[i]" "$i
    }
  }
}END {
  for (i=1;i<=NF;i++) {
    print res[i]
  }
}
' file.txt
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个文件 <code>file.txt</code>，转置它的内容。</p>

<p>你可以假设每行列数相同，并且每个字段由 <code>' '</code> 分隔。</p>

<p> </p>

<p><strong>示例：</strong></p>

<p>假设 <code>file.txt</code> 文件内容如下：</p>

<pre>
name age
alice 21
ryan 30
</pre>

<p>应当输出：</p>

<pre>
name alice ryan
age 21 30
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：awk

<!-- tabs:start -->

#### Shell

```bash
# Read from the file file.txt and print its transposed content to stdout.
awk '
{
  for (i=1; i<=NF; i++) {
    if(NR == 1) {
      res[i] = re$i
    } else {
      res[i] = res[i]" "$i
    }
  }
}END {
  for (i=1;i<=NF;i++) {
    print res[i]
  }
}
' file.txt
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [195. 第十行](https://leetcode.cn/problems/tenth-line){#195}

{{< tabs "195" >}}

{{% tab "bash" %}}
```bash
# Read from the file file.txt and output the tenth line to stdout.
sed -n 10p file.txt
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个文本文件&nbsp;<code>file.txt</code>，请只打印这个文件中的第十行。</p>

<p><strong>示例:</strong></p>

<p>假设&nbsp;<code>file.txt</code> 有如下内容：</p>

<pre>Line 1
Line 2
Line 3
Line 4
Line 5
Line 6
Line 7
Line 8
Line 9
Line 10
</pre>

<p>你的脚本应当显示第十行：</p>

<pre>Line 10
</pre>

<p><strong>说明:</strong><br>
1. 如果文件少于十行，你应当输出什么？<br>
2. 至少有三种不同的解法，请尝试尽可能多的方法来解题。</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：sed

<!-- tabs:start -->

#### Shell

```bash
# Read from the file file.txt and output the tenth line to stdout.
sed -n 10p file.txt
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [196. 删除重复的电子邮箱](https://leetcode.cn/problems/delete-duplicate-emails){#196}

{{< tabs "196" >}}

{{% tab "python" %}}
```python
import pandas as pd


# Modify Person in place
def delete_duplicate_emails(person: pd.DataFrame) -> None:
    # Sort the rows based on id (Ascending order)
    person.sort_values(by="id", ascending=True, inplace=True)
    # Drop the duplicates based on email.
    person.drop_duplicates(subset="email", keep="first", inplace=True)
```
{{% /tab %}}
{{% tab "sql" %}}
```sql
DELETE p2
FROM
    person AS p1
    JOIN person AS p2 ON p1.email = p2.email
WHERE
    p1.id < p2.id;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表:&nbsp;<code>Person</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| email       | varchar |
+-------------+---------+
id 是该表的主键列(具有唯一值的列)。
该表的每一行包含一封电子邮件。电子邮件将不包含大写字母。
</pre>

<p>&nbsp;</p>

<p>编写解决方案<strong> 删除</strong> 所有重复的电子邮件，只保留一个具有最小 <code>id</code> 的唯一电子邮件。</p>

<p>（对于 SQL 用户，请注意你应该编写一个 <code>DELETE</code> 语句而不是 <code>SELECT</code> 语句。）</p>

<p>（对于 Pandas 用户，请注意你应该直接修改 <code>Person</code> 表。）</p>

<p>运行脚本后，显示的答案是 <code>Person</code> 表。驱动程序将首先编译并运行您的代码片段，然后再显示 <code>Person</code> 表。<code>Person</code> 表的最终顺序 <strong>无关紧要</strong> 。</p>

<p>返回结果格式如下示例所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
Person 表:
+----+------------------+
| id | email            |
+----+------------------+
| 1  | john@example.com |
| 2  | bob@example.com  |
| 3  | john@example.com |
+----+------------------+
<strong>输出:</strong> 
+----+------------------+
| id | email            |
+----+------------------+
| 1  | john@example.com |
| 2  | bob@example.com  |
+----+------------------+
<strong>解释:</strong> john@example.com重复两次。我们保留最小的Id = 1。</pre>

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
import pandas as pd


# Modify Person in place
def delete_duplicate_emails(person: pd.DataFrame) -> None:
    # Sort the rows based on id (Ascending order)
    person.sort_values(by="id", ascending=True, inplace=True)
    # Drop the duplicates based on email.
    person.drop_duplicates(subset="email", keep="first", inplace=True)
```

#### MySQL

```sql
# Write your MySQL query statement below
DELETE FROM Person
WHERE id NOT IN (SELECT MIN(id) FROM (SELECT * FROM Person) AS p GROUP BY email);
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
DELETE FROM Person
WHERE
    id NOT IN (
        SELECT id
        FROM
            (
                SELECT
                    id,
                    ROW_NUMBER() OVER (
                        PARTITION BY email
                        ORDER BY id
                    ) AS rk
                FROM Person
            ) AS p
        WHERE rk = 1
    );
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三

<!-- tabs:start -->

#### MySQL

```sql
DELETE p2
FROM
    person AS p1
    JOIN person AS p2 ON p1.email = p2.email
WHERE
    p1.id < p2.id;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [197. 上升的温度](https://leetcode.cn/problems/rising-temperature){#197}

{{< tabs "197" >}}

{{% tab "python" %}}
```python
import pandas as pd


def rising_temperature(weather: pd.DataFrame) -> pd.DataFrame:
    weather.sort_values(by="recordDate", inplace=True)
    return weather[
        (weather.temperature.diff() > 0) & (weather.recordDate.diff().dt.days == 1)
    ][["id"]]
```
{{% /tab %}}
{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT w1.id
FROM
    Weather AS w1
    JOIN Weather AS w2
        ON SUBDATE(w1.recordDate, 1) = w2.recordDate AND w1.temperature > w2.temperature;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<div class="original__bRMd">
<div>
<p>表：&nbsp;<code>Weather</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| recordDate    | date    |
| temperature   | int     |
+---------------+---------+
id 是该表具有唯一值的列。
没有具有相同 recordDate 的不同行。
该表包含特定日期的温度信息</pre>

<p>&nbsp;</p>

<p>编写解决方案，找出与之前（昨天的）日期相比温度更高的所有日期的 <code>id</code> 。</p>

<p>返回结果 <strong>无顺序要求</strong> 。</p>

<p>结果格式如下例子所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Weather 表：
+----+------------+-------------+
| id | recordDate | Temperature |
+----+------------+-------------+
| 1  | 2015-01-01 | 10          |
| 2  | 2015-01-02 | 25          |
| 3  | 2015-01-03 | 20          |
| 4  | 2015-01-04 | 30          |
+----+------------+-------------+
<strong>输出：</strong>
+----+
| id |
+----+
| 2  |
| 4  |
+----+
<strong>解释：</strong>
2015-01-02 的温度比前一天高（10 -&gt; 25）
2015-01-04 的温度比前一天高（20 -&gt; 30）</pre>
</div>
</div>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：自连接 + DATEDIFF/SUBDATE 函数

我们可以通过自连接的方式，将 `Weather` 表中的每一行与它的前一行进行比较，如果温度更高，并且日期相差一天，那么就是我们要找的结果。

<!-- tabs:start -->

#### Python3

```python
import pandas as pd


def rising_temperature(weather: pd.DataFrame) -> pd.DataFrame:
    weather.sort_values(by="recordDate", inplace=True)
    return weather[
        (weather.temperature.diff() > 0) & (weather.recordDate.diff().dt.days == 1)
    ][["id"]]
```

#### MySQL

```sql
# Write your MySQL query statement below
SELECT w1.id
FROM
    Weather AS w1
    JOIN Weather AS w2
        ON DATEDIFF(w1.recordDate, w2.recordDate) = 1 AND w1.temperature > w2.temperature;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT w1.id
FROM
    Weather AS w1
    JOIN Weather AS w2
        ON SUBDATE(w1.recordDate, 1) = w2.recordDate AND w1.temperature > w2.temperature;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [198. 打家劫舍](https://leetcode.cn/problems/house-robber){#198}

{{< tabs "198" >}}

{{% tab "python" %}}
```python
class Solution:
    def rob(self, nums: List[int]) -> int:
        f = g = 0
        for x in nums:
            f, g = max(f, g), f + x
        return max(f, g)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int rob(int[] nums) {
        int f = 0, g = 0;
        for (int x : nums) {
            int ff = Math.max(f, g);
            g = f + x;
            f = ff;
        }
        return Math.max(f, g);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int f = 0, g = 0;
        for (int& x : nums) {
            int ff = max(f, g);
            g = f + x;
            f = ff;
        }
        return max(f, g);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func rob(nums []int) int {
	f, g := 0, 0
	for _, x := range nums {
		f, g = max(f, g), f+x
	}
	return max(f, g)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function rob(nums: number[]): number {
    let [f, g] = [0, 0];
    for (const x of nums) {
        [f, g] = [Math.max(f, g), f + x];
    }
    return Math.max(f, g);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn rob(nums: Vec<i32>) -> i32 {
        let mut f = [0, 0];
        for x in nums {
            f = [f[0].max(f[1]), f[0] + x];
        }
        f[0].max(f[1])
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function rob(nums) {
    let [f, g] = [0, 0];
    for (const x of nums) {
        [f, g] = [Math.max(f, g), f + x];
    }
    return Math.max(f, g);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，<strong>如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警</strong>。</p>

<p>给定一个代表每个房屋存放金额的非负整数数组，计算你<strong> 不触动警报装置的情况下 </strong>，一夜之内能够偷窃到的最高金额。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>[1,2,3,1]
<strong>输出：</strong>4
<strong>解释：</strong>偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>[2,7,9,3,1]
<strong>输出：</strong>12
<strong>解释：</strong>偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
     偷窃到的最高金额 = 2 + 9 + 1 = 12 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 100</code></li>
	<li><code>0 <= nums[i] <= 400</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $\textit{dfs}(i)$，表示从第 $i$ 间房屋开始偷窃能够得到的最高金额。那么答案即为 $\textit{dfs}(0)$。

函数 $\textit{dfs}(i)$ 的执行过程如下：

-   如果 $i \ge \textit{len}(\textit{nums})$，表示所有房屋都被考虑过了，直接返回 $0$；
-   否则，考虑偷窃第 $i$ 间房屋，那么 $\textit{dfs}(i) = \textit{nums}[i] + \textit{dfs}(i+2)$；不偷窃第 $i$ 间房屋，那么 $\textit{dfs}(i) = \textit{dfs}(i+1)$。
-   返回 $\max(\textit{nums}[i] + \textit{dfs}(i+2), \textit{dfs}(i+1))$。

为了避免重复计算，我们使用记忆化搜索的方法，将 $\textit{dfs}(i)$ 的结果保存在一个数组或哈希表中，每次计算前先查询是否已经计算过，如果计算过直接返回结果。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def rob(self, nums: List[int]) -> int:
        @cache
        def dfs(i: int) -> int:
            if i >= len(nums):
                return 0
            return max(nums[i] + dfs(i + 2), dfs(i + 1))

        return dfs(0)
```

#### Java

```java
class Solution {
    private Integer[] f;
    private int[] nums;

    public int rob(int[] nums) {
        this.nums = nums;
        f = new Integer[nums.length];
        return dfs(0);
    }

    private int dfs(int i) {
        if (i >= nums.length) {
            return 0;
        }
        if (f[i] == null) {
            f[i] = Math.max(nums[i] + dfs(i + 2), dfs(i + 1));
        }
        return f[i];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int f[n];
        memset(f, -1, sizeof(f));
        auto dfs = [&](this auto&& dfs, int i) -> int {
            if (i >= n) {
                return 0;
            }
            if (f[i] < 0) {
                f[i] = max(nums[i] + dfs(i + 2), dfs(i + 1));
            }
            return f[i];
        };
        return dfs(0);
    }
};
```

#### Go

```go
func rob(nums []int) int {
	n := len(nums)
	f := make([]int, n)
	for i := range f {
		f[i] = -1
	}
	var dfs func(int) int
	dfs = func(i int) int {
		if i >= n {
			return 0
		}
		if f[i] < 0 {
			f[i] = max(nums[i]+dfs(i+2), dfs(i+1))
		}
		return f[i]
	}
	return dfs(0)
}
```

#### TypeScript

```ts
function rob(nums: number[]): number {
    const n = nums.length;
    const f: number[] = Array(n).fill(-1);
    const dfs = (i: number): number => {
        if (i >= n) {
            return 0;
        }
        if (f[i] < 0) {
            f[i] = Math.max(nums[i] + dfs(i + 2), dfs(i + 1));
        }
        return f[i];
    };
    return dfs(0);
}
```

#### Rust

```rust
impl Solution {
    pub fn rob(nums: Vec<i32>) -> i32 {
        fn dfs(i: usize, nums: &Vec<i32>, f: &mut Vec<i32>) -> i32 {
            if i >= nums.len() {
                return 0;
            }
            if f[i] < 0 {
                f[i] = (nums[i] + dfs(i + 2, nums, f)).max(dfs(i + 1, nums, f));
            }
            f[i]
        }

        let n = nums.len();
        let mut f = vec![-1; n];
        dfs(0, &nums, &mut f)
    }
}
```

#### JavaScript

```js
function rob(nums) {
    const n = nums.length;
    const f = Array(n).fill(-1);
    const dfs = i => {
        if (i >= n) {
            return 0;
        }
        if (f[i] < 0) {
            f[i] = Math.max(nums[i] + dfs(i + 2), dfs(i + 1));
        }
        return f[i];
    };
    return dfs(0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划

我们定义 $f[i]$ 表示前 $i$ 间房屋能偷窃到的最高总金额，初始时 $f[0]=0$, $f[1]=nums[0]$。

考虑 $i \gt 1$ 的情况，第 $i$ 间房屋有两个选项：

-   不偷窃第 $i$ 间房屋，偷窃总金额为 $f[i-1]$；
-   偷窃第 $i$ 间房屋，偷窃总金额为 $f[i-2]+nums[i-1]$；

因此，我们可以得到状态转移方程：

$$
f[i]=
\begin{cases}
0, & i=0 \\
nums[0], & i=1 \\
\max(f[i-1],f[i-2]+nums[i-1]), & i \gt 1
\end{cases}
$$

最终的答案即为 $f[n]$，其中 $n$ 是数组的长度。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        f = [0] * (n + 1)
        f[1] = nums[0]
        for i in range(2, n + 1):
            f[i] = max(f[i - 1], f[i - 2] + nums[i - 1])
        return f[n]
```

#### Java

```java
class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        int[] f = new int[n + 1];
        f[1] = nums[0];
        for (int i = 2; i <= n; ++i) {
            f[i] = Math.max(f[i - 1], f[i - 2] + nums[i - 1]);
        }
        return f[n];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int f[n + 1];
        memset(f, 0, sizeof(f));
        f[1] = nums[0];
        for (int i = 2; i <= n; ++i) {
            f[i] = max(f[i - 1], f[i - 2] + nums[i - 1]);
        }
        return f[n];
    }
};
```

#### Go

```go
func rob(nums []int) int {
	n := len(nums)
	f := make([]int, n+1)
	f[1] = nums[0]
	for i := 2; i <= n; i++ {
		f[i] = max(f[i-1], f[i-2]+nums[i-1])
	}
	return f[n]
}
```

#### TypeScript

```ts
function rob(nums: number[]): number {
    const n = nums.length;
    const f: number[] = Array(n + 1).fill(0);
    f[1] = nums[0];
    for (let i = 2; i <= n; ++i) {
        f[i] = Math.max(f[i - 1], f[i - 2] + nums[i - 1]);
    }
    return f[n];
}
```

#### Rust

```rust
impl Solution {
    pub fn rob(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut f = vec![0; n + 1];
        f[1] = nums[0];
        for i in 2..=n {
            f[i] = f[i - 1].max(f[i - 2] + nums[i - 1]);
        }
        f[n]
    }
}
```

#### JavaScript

```js
function rob(nums) {
    const n = nums.length;
    const f = Array(n + 1).fill(0);
    f[1] = nums[0];
    for (let i = 2; i <= n; ++i) {
        f[i] = Math.max(f[i - 1], f[i - 2] + nums[i - 1]);
    }
    return f[n];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三：动态规划（空间优化）

我们注意到，当 $i \gt 2$ 时，$f[i]$ 只和 $f[i-1]$ 与 $f[i-2]$ 有关，因此我们可以使用两个变量代替数组，将空间复杂度降到 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def rob(self, nums: List[int]) -> int:
        f = g = 0
        for x in nums:
            f, g = max(f, g), f + x
        return max(f, g)
```

#### Java

```java
class Solution {
    public int rob(int[] nums) {
        int f = 0, g = 0;
        for (int x : nums) {
            int ff = Math.max(f, g);
            g = f + x;
            f = ff;
        }
        return Math.max(f, g);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int f = 0, g = 0;
        for (int& x : nums) {
            int ff = max(f, g);
            g = f + x;
            f = ff;
        }
        return max(f, g);
    }
};
```

#### Go

```go
func rob(nums []int) int {
	f, g := 0, 0
	for _, x := range nums {
		f, g = max(f, g), f+x
	}
	return max(f, g)
}
```

#### TypeScript

```ts
function rob(nums: number[]): number {
    let [f, g] = [0, 0];
    for (const x of nums) {
        [f, g] = [Math.max(f, g), f + x];
    }
    return Math.max(f, g);
}
```

#### Rust

```rust
impl Solution {
    pub fn rob(nums: Vec<i32>) -> i32 {
        let mut f = [0, 0];
        for x in nums {
            f = [f[0].max(f[1]), f[0] + x];
        }
        f[0].max(f[1])
    }
}
```

#### JavaScript

```js
function rob(nums) {
    let [f, g] = [0, 0];
    for (const x of nums) {
        [f, g] = [Math.max(f, g), f + x];
    }
    return Math.max(f, g);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [199. 二叉树的右视图](https://leetcode.cn/problems/binary-tree-right-side-view){#199}

{{< tabs "199" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        def dfs(root: Optional[TreeNode], depth: int) -> None:
            if root is None:
                return
            if len(ans) == depth:
                ans.append(root.val)
            dfs(root.right, depth + 1)
            dfs(root.left, depth + 1)

        ans = []
        dfs(root, 0)
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

    public List<Integer> rightSideView(TreeNode root) {
        dfs(root, 0);
        return ans;
    }

    private void dfs(TreeNode root, int depth) {
        if (root == null) {
            return;
        }
        if (ans.size() == depth) {
            ans.add(root.val);
        }
        dfs(root.right, depth + 1);
        dfs(root.left, depth + 1);
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        auto dfs = [&](this auto&& dfs, TreeNode* root, int depth) -> void {
            if (!root) {
                return;
            }
            if (ans.size() == depth) {
                ans.push_back(root->val);
            }
            dfs(root->right, depth + 1);
            dfs(root->left, depth + 1);
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
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func rightSideView(root *TreeNode) (ans []int) {
	var dfs func(*TreeNode, int)
	dfs = func(root *TreeNode, depth int) {
		if root == nil {
			return
		}
		if len(ans) == depth {
			ans = append(ans, root.Val)
		}
		dfs(root.Right, depth+1)
		dfs(root.Left, depth+1)
	}
	dfs(root, 0)
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

function rightSideView(root: TreeNode | null): number[] {
    const ans = [];
    const dfs = (root: TreeNode | null, depth: number) => {
        if (!root) {
            return;
        }
        if (ans.length == depth) {
            ans.push(root.val);
        }
        dfs(root.right, depth + 1);
        dfs(root.left, depth + 1);
    };
    dfs(root, 0);
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
    pub fn right_side_view(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut ans = Vec::new();
        fn dfs(node: Option<Rc<RefCell<TreeNode>>>, depth: usize, ans: &mut Vec<i32>) {
            if let Some(node_ref) = node {
                let node = node_ref.borrow();
                if ans.len() == depth {
                    ans.push(node.val);
                }
                dfs(node.right.clone(), depth + 1, ans);
                dfs(node.left.clone(), depth + 1, ans);
            }
        }
        dfs(root, 0, &mut ans);
        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var rightSideView = function (root) {
    const ans = [];
    const dfs = (root, depth) => {
        if (!root) {
            return;
        }
        if (ans.length == depth) {
            ans.push(root.val);
        }
        dfs(root.right, depth + 1);
        dfs(root.left, depth + 1);
    };
    dfs(root, 0);
    return ans;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个二叉树的 <strong>根节点</strong> <code>root</code>，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>root = [1,2,3,null,5,null,4]</span></p>

<p><strong>输出：</strong><span class="example-io">[1,3,4]</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0100-0199/0199.Binary%20Tree%20Right%20Side%20View/images/tmpd5jn43fs-1.png" style="width: 400px; height: 207px;" /></p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>root = [1,2,3,4,null,null,null,5]</span></p>

<p><span class="example-io"><b>输出：</b>[1,3,4,5]</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0100-0199/0199.Binary%20Tree%20Right%20Side%20View/images/tmpkpe40xeh-1.png" style="width: 400px; height: 214px;" /></p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">root = [1,null,3]</span></p>

<p><strong>输出：</strong><span class="example-io">[1,3]</span></p>
</div>

<p><strong class="example">示例 4：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>root = []</span></p>

<p><strong>输出：</strong><span class="example-io">[]</span></p>

<p>&nbsp;</p>
</div>

<p><strong>提示:</strong></p>

<ul>
	<li>二叉树的节点个数的范围是 <code>[0,100]</code></li>
	<li><meta charset="UTF-8" /><code>-100&nbsp;&lt;= Node.val &lt;= 100</code>&nbsp;</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS

我们可以使用广度优先搜索，定义一个队列 $\textit{q}$，将根节点放入队列中。每次从队列中取出当前层的所有节点，对于当前节点，我们先判断右子树是否存在，若存在则将右子树放入队列中；再判断左子树是否存在，若存在则将左子树放入队列中。这样每次取出队列中的第一个节点即为该层的右视图节点。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为二叉树节点个数。

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
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        if root is None:
            return ans
        q = deque([root])
        while q:
            ans.append(q[0].val)
            for _ in range(len(q)):
                node = q.popleft()
                if node.right:
                    q.append(node.right)
                if node.left:
                    q.append(node.left)
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
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        if (root == null) {
            return ans;
        }
        Deque<TreeNode> q = new ArrayDeque<>();
        q.offer(root);
        while (!q.isEmpty()) {
            ans.add(q.peekFirst().val);
            for (int k = q.size(); k > 0; --k) {
                TreeNode node = q.poll();
                if (node.right != null) {
                    q.offer(node.right);
                }
                if (node.left != null) {
                    q.offer(node.left);
                }
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (!root) {
            return ans;
        }
        queue<TreeNode*> q{{root}};
        while (q.size()) {
            ans.push_back(q.front()->val);
            for (int k = q.size(); k; --k) {
                auto node = q.front();
                q.pop();
                if (node->right) {
                    q.push(node->right);
                }
                if (node->left) {
                    q.push(node->left);
                }
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
func rightSideView(root *TreeNode) (ans []int) {
	if root == nil {
		return
	}
	q := []*TreeNode{root}
	for len(q) > 0 {
		ans = append(ans, q[0].Val)
		for k := len(q); k > 0; k-- {
			node := q[0]
			q = q[1:]
			if node.Right != nil {
				q = append(q, node.Right)
			}
			if node.Left != nil {
				q = append(q, node.Left)
			}
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

function rightSideView(root: TreeNode | null): number[] {
    const ans: number[] = [];
    if (!root) {
        return ans;
    }
    const q: TreeNode[] = [root];
    while (q.length > 0) {
        ans.push(q[0].val);
        const nq: TreeNode[] = [];
        for (const { left, right } of q) {
            if (right) {
                nq.push(right);
            }
            if (left) {
                nq.push(left);
            }
        }
        q.length = 0;
        q.push(...nq);
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
use std::collections::VecDeque;
use std::rc::Rc;
impl Solution {
    pub fn right_side_view(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut ans = vec![];
        if root.is_none() {
            return ans;
        }
        let mut q = VecDeque::new();
        q.push_back(root);
        while !q.is_empty() {
            let k = q.len();
            ans.push(q[0].as_ref().unwrap().borrow().val);
            for _ in 0..k {
                if let Some(node) = q.pop_front().unwrap() {
                    let mut node = node.borrow_mut();
                    if node.right.is_some() {
                        q.push_back(node.right.take());
                    }
                    if node.left.is_some() {
                        q.push_back(node.left.take());
                    }
                }
            }
        }
        ans
    }
}
```

#### JavaScript

```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var rightSideView = function (root) {
    const ans = [];
    if (!root) {
        return ans;
    }
    const q = [root];
    while (q.length > 0) {
        ans.push(q[0].val);
        const nq = [];
        for (const { left, right } of q) {
            if (right) {
                nq.push(right);
            }
            if (left) {
                nq.push(left);
            }
        }
        q.length = 0;
        q.push(...nq);
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：DFS

使用 DFS 深度优先遍历二叉树，每次先遍历右子树，再遍历左子树，这样每层第一个遍历到的节点即为该层的右视图节点。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为二叉树节点个数。

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
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        def dfs(root: Optional[TreeNode], depth: int) -> None:
            if root is None:
                return
            if len(ans) == depth:
                ans.append(root.val)
            dfs(root.right, depth + 1)
            dfs(root.left, depth + 1)

        ans = []
        dfs(root, 0)
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

    public List<Integer> rightSideView(TreeNode root) {
        dfs(root, 0);
        return ans;
    }

    private void dfs(TreeNode root, int depth) {
        if (root == null) {
            return;
        }
        if (ans.size() == depth) {
            ans.add(root.val);
        }
        dfs(root.right, depth + 1);
        dfs(root.left, depth + 1);
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        auto dfs = [&](this auto&& dfs, TreeNode* root, int depth) -> void {
            if (!root) {
                return;
            }
            if (ans.size() == depth) {
                ans.push_back(root->val);
            }
            dfs(root->right, depth + 1);
            dfs(root->left, depth + 1);
        };
        dfs(root, 0);
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
func rightSideView(root *TreeNode) (ans []int) {
	var dfs func(*TreeNode, int)
	dfs = func(root *TreeNode, depth int) {
		if root == nil {
			return
		}
		if len(ans) == depth {
			ans = append(ans, root.Val)
		}
		dfs(root.Right, depth+1)
		dfs(root.Left, depth+1)
	}
	dfs(root, 0)
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

function rightSideView(root: TreeNode | null): number[] {
    const ans = [];
    const dfs = (root: TreeNode | null, depth: number) => {
        if (!root) {
            return;
        }
        if (ans.length == depth) {
            ans.push(root.val);
        }
        dfs(root.right, depth + 1);
        dfs(root.left, depth + 1);
    };
    dfs(root, 0);
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
    pub fn right_side_view(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut ans = Vec::new();
        fn dfs(node: Option<Rc<RefCell<TreeNode>>>, depth: usize, ans: &mut Vec<i32>) {
            if let Some(node_ref) = node {
                let node = node_ref.borrow();
                if ans.len() == depth {
                    ans.push(node.val);
                }
                dfs(node.right.clone(), depth + 1, ans);
                dfs(node.left.clone(), depth + 1, ans);
            }
        }
        dfs(root, 0, &mut ans);
        ans
    }
}
```

#### JavaScript

```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var rightSideView = function (root) {
    const ans = [];
    const dfs = (root, depth) => {
        if (!root) {
            return;
        }
        if (ans.length == depth) {
            ans.push(root.val);
        }
        dfs(root.right, depth + 1);
        dfs(root.left, depth + 1);
    };
    dfs(root, 0);
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
