---
title: "2578_SplitWithMinimumSum"
date: 2025-10-06T00:42:37+08:00
weight: 2578
tags: [贪心, 数学, 排序]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [2578. 最小和分割](https://leetcode.cn/problems/split-with-minimum-sum)

[English Version](../en/2578-78/2578_SplitWithMinimumSum)

## 题目描述

<!-- description:start -->

<p>给你一个正整数&nbsp;<code>num</code>&nbsp;，请你将它分割成两个非负整数&nbsp;<code>num1</code> 和&nbsp;<code>num2</code>&nbsp;，满足：</p>

<ul>
	<li><code>num1</code> 和&nbsp;<code>num2</code>&nbsp;直接连起来，得到&nbsp;<code>num</code>&nbsp;各数位的一个排列。

    <ul>
    	<li>换句话说，<code>num1</code> 和&nbsp;<code>num2</code>&nbsp;中所有数字出现的次数之和等于&nbsp;<code>num</code>&nbsp;中所有数字出现的次数。</li>
    </ul>
    </li>
    <li><code>num1</code> 和&nbsp;<code>num2</code>&nbsp;可以包含前导 0 。</li>

</ul>

<p>请你返回&nbsp;<code>num1</code> 和 <code>num2</code>&nbsp;可以得到的和的 <strong>最小</strong> 值。</p>

<p><strong>注意：</strong></p>

<ul>
	<li><code>num</code>&nbsp;保证没有前导 0 。</li>
	<li><code>num1</code> 和&nbsp;<code>num2</code>&nbsp;中数位顺序可以与&nbsp;<code>num</code>&nbsp;中数位顺序不同。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>num = 4325
<b>输出：</b>59
<b>解释：</b>我们可以将 4325 分割成 <code>num1 </code>= 24 和 <code>num2 </code>= 35 ，和为 59 ，59 是最小和。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>num = 687
<b>输出：</b>75
<b>解释：</b>我们可以将 687 分割成 <code>num1</code> = 68 和 <code>num2 </code>= 7 ，和为最优值 75 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>10 &lt;= num &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：计数 + 贪心

我们先用哈希表或数组 $cnt$ 统计 $num$ 中各个数字出现的次数，用变量 $n$ 记录 $num$ 的位数。

接下来，枚举 $nums$ 所有位数 $i$，将 $cnt$ 中的数字按照从小到大的顺序交替地分配给 $num1$ 和 $num2$，记录在一个长度为 $2$ 的数组 $ans$ 中。最后，返回 $ans$ 中的两个数之和即可。

时间复杂度 $O(n)$，空间复杂度 $O(C)$。其中 $n$ 为 $num$ 的位数；而 $C$ 为 $num$ 中不同数字的个数，本题中 $C \leq 10$。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### Rust



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：排序 + 贪心

我们可以将 $num$ 转换成字符串或者字符数组，然后对其进行排序，接下来将排序后的数组中的数字按照从小到大的顺序交替地分配给 $num1$ 和 $num2$，最后返回 $num1$ 和 $num2$ 的和即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为 $num$ 的位数。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### Rust



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def splitNum(self, num: int) -> int:
        s = sorted(str(num))
        return int(''.join(s[::2])) + int(''.join(s[1::2]))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int splitNum(int num) {
        char[] s = (num + "").toCharArray();
        Arrays.sort(s);
        int[] ans = new int[2];
        for (int i = 0; i < s.length; ++i) {
            ans[i & 1] = ans[i & 1] * 10 + s[i] - '0';
        }
        return ans[0] + ans[1];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int splitNum(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        int ans[2]{};
        for (int i = 0; i < s.size(); ++i) {
            ans[i & 1] = ans[i & 1] * 10 + s[i] - '0';
        }
        return ans[0] + ans[1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func splitNum(num int) int {
	s := []byte(strconv.Itoa(num))
	sort.Slice(s, func(i, j int) bool { return s[i] < s[j] })
	ans := [2]int{}
	for i, c := range s {
		ans[i&1] = ans[i&1]*10 + int(c-'0')
	}
	return ans[0] + ans[1]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function splitNum(num: number): number {
    const s: string[] = String(num).split('');
    s.sort();
    const ans: number[] = Array(2).fill(0);
    for (let i = 0; i < s.length; ++i) {
        ans[i & 1] = ans[i & 1] * 10 + Number(s[i]);
    }
    return ans[0] + ans[1];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn split_num(num: i32) -> i32 {
        let mut s = num.to_string().into_bytes();
        s.sort_unstable();

        let mut ans = vec![0; 2];
        for (i, c) in s.iter().enumerate() {
            ans[i & 1] = ans[i & 1] * 10 + ((c - b'0') as i32);
        }

        ans[0] + ans[1]
    }
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def splitNum(self, num: int) -> int:
        s = sorted(str(num))
        return int(''.join(s[::2])) + int(''.join(s[1::2]))
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int splitNum(int num) {
        char[] s = (num + "").toCharArray();
        Arrays.sort(s);
        int[] ans = new int[2];
        for (int i = 0; i < s.length; ++i) {
            ans[i & 1] = ans[i & 1] * 10 + s[i] - '0';
        }
        return ans[0] + ans[1];
    }
}
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "cpp 可视化" %}}
{{< pythontutor width="100%" height="800" language="cpp" >}}
class Solution {
public:
    int splitNum(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        int ans[2]{};
        for (int i = 0; i < s.size(); ++i) {
            ans[i & 1] = ans[i & 1] * 10 + s[i] - '0';
        }
        return ans[0] + ans[1];
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}