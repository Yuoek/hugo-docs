---
title: "0011_盛最多水的容器"
date: 2025-10-08T18:34:13+08:00
weight: 2
tags: [双指针, 哈希表, 回溯, 字典树, 字符串, 排序, 数学, 数组, 栈, 贪心, 链表]
---

{{< markmap >}}
### [0011_盛最多水的容器](#11)
#### [贪心](#11)
#### [数组](#11)
#### [双指针](#11)
### [0012_整数转罗马数字](#12)
#### [哈希表](#12)
#### [数学](#12)
#### [字符串](#12)
### [0013_罗马数字转整数](#13)
#### [哈希表](#13)
#### [数学](#13)
#### [字符串](#13)
### [0014_最长公共前缀](#14)
#### [字典树](#14)
#### [数组](#14)
#### [字符串](#14)
### [0015_三数之和](#15)
#### [数组](#15)
#### [双指针](#15)
#### [排序](#15)
### [0016_最接近的三数之和](#16)
#### [数组](#16)
#### [双指针](#16)
#### [排序](#16)
### [0017_电话号码的字母组合](#17)
#### [哈希表](#17)
#### [字符串](#17)
#### [回溯](#17)
### [0018_四数之和](#18)
#### [数组](#18)
#### [双指针](#18)
#### [排序](#18)
### [0019_删除链表的倒数第 N 个结点](#19)
#### [链表](#19)
#### [双指针](#19)
### [0020_有效的括号](#20)
#### [栈](#20)
#### [字符串](#20)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0011_盛最多水的容器
___
#### 贪心
___
#### 数组
___
#### 双指针
---
### 0012_整数转罗马数字
___
#### 哈希表
___
#### 数学
___
#### 字符串
---
### 0013_罗马数字转整数
___
#### 哈希表
___
#### 数学
___
#### 字符串
---
### 0014_最长公共前缀
___
#### 字典树
___
#### 数组
___
#### 字符串
---
### 0015_三数之和
___
#### 数组
___
#### 双指针
___
#### 排序
---
### 0016_最接近的三数之和
___
#### 数组
___
#### 双指针
___
#### 排序
---
### 0017_电话号码的字母组合
___
#### 哈希表
___
#### 字符串
___
#### 回溯
---
### 0018_四数之和
___
#### 数组
___
#### 双指针
___
#### 排序
---
### 0019_删除链表的倒数第 N 个结点
___
#### 链表
___
#### 双指针
---
### 0020_有效的括号
___
#### 栈
___
#### 字符串
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 双指针 | 哈希表 | 回溯 |
| 字典树 | 字符串 | 排序 |
| 数学 | 数组 | 栈 |
| 贪心 | 链表 |  |

# [11. 盛最多水的容器](https://leetcode.cn/problems/container-with-most-water){#11}

{{< tabs "11" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxArea(self, height: List[int]) -> int:
        l, r = 0, len(height) - 1
        ans = 0
        while l < r:
            t = min(height[l], height[r]) * (r - l)
            ans = max(ans, t)
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxArea(int[] height) {
        int l = 0, r = height.length - 1;
        int ans = 0;
        while (l < r) {
            int t = Math.min(height[l], height[r]) * (r - l);
            ans = Math.max(ans, t);
            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
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
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int ans = 0;
        while (l < r) {
            int t = min(height[l], height[r]) * (r - l);
            ans = max(ans, t);
            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxArea(height []int) (ans int) {
	l, r := 0, len(height)-1
	for l < r {
		t := min(height[l], height[r]) * (r - l)
		ans = max(ans, t)
		if height[l] < height[r] {
			l++
		} else {
			r--
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxArea(height: number[]): number {
    let [l, r] = [0, height.length - 1];
    let ans = 0;
    while (l < r) {
        const t = Math.min(height[l], height[r]) * (r - l);
        ans = Math.max(ans, t);
        if (height[l] < height[r]) {
            ++l;
        } else {
            --r;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let mut l = 0;
        let mut r = height.len() - 1;
        let mut ans = 0;
        while l < r {
            ans = ans.max(height[l].min(height[r]) * ((r - l) as i32));
            if height[l] < height[r] {
                l += 1;
            } else {
                r -= 1;
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
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function (height) {
    let [l, r] = [0, height.length - 1];
    let ans = 0;
    while (l < r) {
        const t = Math.min(height[l], height[r]) * (r - l);
        ans = Math.max(ans, t);
        if (height[l] < height[r]) {
            ++l;
        } else {
            --r;
        }
    }
    return ans;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int MaxArea(int[] height) {
        int l = 0, r = height.Length - 1;
        int ans = 0;
        while (l < r) {
            int t = Math.Min(height[l], height[r]) * (r - l);
            ans = Math.Max(ans, t);
            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer[] $height
     * @return Integer
     */
    function maxArea($height) {
        $l = 0;
        $r = count($height) - 1;
        $ans = 0;
        while ($l < $r) {
            $t = min($height[$l], $height[$r]) * ($r - $l);
            $ans = max($ans, $t);
            if ($height[$l] < $height[$r]) {
                ++$l;
            } else {
                --$r;
            }
        }
        return $ans;
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int maxArea(int* height, int heightSize) {
    int l = 0, r = heightSize - 1;
    int ans = 0;
    while (l < r) {
        int t = min(height[l], height[r]) * (r - l);
        ans = max(ans, t);
        if (height[l] < height[r]) {
            ++l;
        } else {
            --r;
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

<p>给定一个长度为 <code>n</code> 的整数数组&nbsp;<code>height</code>&nbsp;。有&nbsp;<code>n</code>&nbsp;条垂线，第 <code>i</code> 条线的两个端点是&nbsp;<code>(i, 0)</code>&nbsp;和&nbsp;<code>(i, height[i])</code>&nbsp;。</p>

<p>找出其中的两条线，使得它们与&nbsp;<code>x</code>&nbsp;轴共同构成的容器可以容纳最多的水。</p>

<p>返回容器可以储存的最大水量。</p>

<p><strong>说明：</strong>你不能倾斜容器。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0000-0099/0011.Container%20With%20Most%20Water/images/question_11.jpg" /></p>

<pre>
<strong>输入：</strong>[1,8,6,2,5,4,8,3,7]
<strong>输出：</strong>49 
<strong>解释：</strong>图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为&nbsp;49。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>height = [1,1]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == height.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= height[i] &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

我们使用两个指针 $l$ 和 $r$ 分别指向数组的左右两端，即 $l = 0$，而 $r = n - 1$，其中 $n$ 是数组的长度。

接下来，我们使用变量 $\textit{ans}$ 记录容器的最大容量，初始化为 $0$。

然后，我们开始进行循环，每次循环中，我们计算当前容器的容量，即 $\textit{min}(height[l], height[r]) \times (r - l)$，并将其与 $\textit{ans}$ 进行比较，将较大值赋给 $\textit{ans}$。然后，我们判断 $height[l]$ 和 $height[r]$ 的大小，如果 $\textit{height}[l] < \textit{height}[r]$，移动 $r$ 指针不会使得结果变得更好，因为容器的高度由较短的那根垂直线决定，所以我们移动 $l$ 指针。反之，我们移动 $r$ 指针。

遍历结束后，返回 $\textit{ans}$ 即可。

时间复杂度 $O(n)$，其中 $n$ 是数组 $\textit{height}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxArea(self, height: List[int]) -> int:
        l, r = 0, len(height) - 1
        ans = 0
        while l < r:
            t = min(height[l], height[r]) * (r - l)
            ans = max(ans, t)
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
        return ans
```

#### Java

```java
class Solution {
    public int maxArea(int[] height) {
        int l = 0, r = height.length - 1;
        int ans = 0;
        while (l < r) {
            int t = Math.min(height[l], height[r]) * (r - l);
            ans = Math.max(ans, t);
            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
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
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int ans = 0;
        while (l < r) {
            int t = min(height[l], height[r]) * (r - l);
            ans = max(ans, t);
            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maxArea(height []int) (ans int) {
	l, r := 0, len(height)-1
	for l < r {
		t := min(height[l], height[r]) * (r - l)
		ans = max(ans, t)
		if height[l] < height[r] {
			l++
		} else {
			r--
		}
	}
	return
}
```

#### TypeScript

```ts
function maxArea(height: number[]): number {
    let [l, r] = [0, height.length - 1];
    let ans = 0;
    while (l < r) {
        const t = Math.min(height[l], height[r]) * (r - l);
        ans = Math.max(ans, t);
        if (height[l] < height[r]) {
            ++l;
        } else {
            --r;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let mut l = 0;
        let mut r = height.len() - 1;
        let mut ans = 0;
        while l < r {
            ans = ans.max(height[l].min(height[r]) * ((r - l) as i32));
            if height[l] < height[r] {
                l += 1;
            } else {
                r -= 1;
            }
        }
        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function (height) {
    let [l, r] = [0, height.length - 1];
    let ans = 0;
    while (l < r) {
        const t = Math.min(height[l], height[r]) * (r - l);
        ans = Math.max(ans, t);
        if (height[l] < height[r]) {
            ++l;
        } else {
            --r;
        }
    }
    return ans;
};
```

#### C#

```cs
public class Solution {
    public int MaxArea(int[] height) {
        int l = 0, r = height.Length - 1;
        int ans = 0;
        while (l < r) {
            int t = Math.Min(height[l], height[r]) * (r - l);
            ans = Math.Max(ans, t);
            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
        }
        return ans;
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param Integer[] $height
     * @return Integer
     */
    function maxArea($height) {
        $l = 0;
        $r = count($height) - 1;
        $ans = 0;
        while ($l < $r) {
            $t = min($height[$l], $height[$r]) * ($r - $l);
            $ans = max($ans, $t);
            if ($height[$l] < $height[$r]) {
                ++$l;
            } else {
                --$r;
            }
        }
        return $ans;
    }
}
```

#### C

```c
int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int maxArea(int* height, int heightSize) {
    int l = 0, r = heightSize - 1;
    int ans = 0;
    while (l < r) {
        int t = min(height[l], height[r]) * (r - l);
        ans = max(ans, t);
        if (height[l] < height[r]) {
            ++l;
        } else {
            --r;
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

# [12. 整数转罗马数字](https://leetcode.cn/problems/integer-to-roman){#12}

{{< tabs "12" >}}

{{% tab "python" %}}
```python
class Solution:
    def intToRoman(self, num: int) -> str:
        cs = ('M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I')
        vs = (1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1)
        ans = []
        for c, v in zip(cs, vs):
            while num >= v:
                num -= v
                ans.append(c)
        return ''.join(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String intToRoman(int num) {
        List<String> cs
            = List.of("M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I");
        List<Integer> vs = List.of(1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1);
        StringBuilder ans = new StringBuilder();
        for (int i = 0, n = cs.size(); i < n; ++i) {
            while (num >= vs.get(i)) {
                num -= vs.get(i);
                ans.append(cs.get(i));
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
    string intToRoman(int num) {
        vector<string> cs = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> vs = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string ans;
        for (int i = 0; i < cs.size(); ++i) {
            while (num >= vs[i]) {
                num -= vs[i];
                ans += cs[i];
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func intToRoman(num int) string {
	cs := []string{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"}
	vs := []int{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}
	ans := &strings.Builder{}
	for i, v := range vs {
		for num >= v {
			num -= v
			ans.WriteString(cs[i])
		}
	}
	return ans.String()
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function intToRoman(num: number): string {
    const cs: string[] = ['M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I'];
    const vs: number[] = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1];
    const ans: string[] = [];
    for (let i = 0; i < vs.length; ++i) {
        while (num >= vs[i]) {
            num -= vs[i];
            ans.push(cs[i]);
        }
    }
    return ans.join('');
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn int_to_roman(num: i32) -> String {
        let cs = [
            "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I",
        ];
        let vs = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1];
        let mut num = num;
        let mut ans = String::new();

        for (i, &v) in vs.iter().enumerate() {
            while num >= v {
                num -= v;
                ans.push_str(cs[i]);
            }
        }

        ans
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public string IntToRoman(int num) {
        List<string> cs = new List<string>{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        List<int> vs = new List<int>{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < cs.Count; i++) {
            while (num >= vs[i]) {
                ans.Append(cs[i]);
                num -= vs[i];
            }
        }
        return ans.ToString();
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer $num
     * @return String
     */
    function intToRoman($num) {
        $cs = ['M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I'];
        $vs = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1];
        $ans = '';

        foreach ($vs as $i => $v) {
            while ($num >= $v) {
                $num -= $v;
                $ans .= $cs[$i];
            }
        }

        return $ans;
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
static const char* cs[] = {
    "M", "CM", "D", "CD", "C", "XC",
    "L", "XL", "X", "IX", "V", "IV", "I"};

static const int vs[] = {
    1000, 900, 500, 400, 100, 90,
    50, 40, 10, 9, 5, 4, 1};

char* intToRoman(int num) {
    static char ans[20];
    ans[0] = '\0';
    for (int i = 0; i < 13; ++i) {
        while (num >= vs[i]) {
            num -= vs[i];
            strcat(ans, cs[i]);
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

<p>七个不同的符号代表罗马数字，其值如下：</p>

<table>
	<thead>
		<tr>
			<th>符号</th>
			<th>值</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>I</td>
			<td>1</td>
		</tr>
		<tr>
			<td>V</td>
			<td>5</td>
		</tr>
		<tr>
			<td>X</td>
			<td>10</td>
		</tr>
		<tr>
			<td>L</td>
			<td>50</td>
		</tr>
		<tr>
			<td>C</td>
			<td>100</td>
		</tr>
		<tr>
			<td>D</td>
			<td>500</td>
		</tr>
		<tr>
			<td>M</td>
			<td>1000</td>
		</tr>
	</tbody>
</table>

<p>罗马数字是通过添加从最高到最低的小数位值的转换而形成的。将小数位值转换为罗马数字有以下规则：</p>

<ul>
	<li>如果该值不是以 4 或 9 开头，请选择可以从输入中减去的最大值的符号，将该符号附加到结果，减去其值，然后将其余部分转换为罗马数字。</li>
	<li>如果该值以 4 或 9 开头，使用 <strong>减法形式</strong>，表示从以下符号中减去一个符号，例如&nbsp;4 是 5 (<code>V</code>) 减 1 (<code>I</code>): <code>IV</code>&nbsp;，9 是 10 (<code>X</code>) 减&nbsp;1 (<code>I</code>)：<code>IX</code>。仅使用以下减法形式：4 (<code>IV</code>)，9 (<code>IX</code>)，40 (<code>XL</code>)，90 (<code>XC</code>)，400 (<code>CD</code>) 和&nbsp;900 (<code>CM</code>)。</li>
	<li>只有 10 的次方（<code>I</code>, <code>X</code>, <code>C</code>, <code>M</code>）最多可以连续附加 3 次以代表 10 的倍数。你不能多次附加&nbsp;5&nbsp;(<code>V</code>)，50 (<code>L</code>) 或 500 (<code>D</code>)。如果需要将符号附加4次，请使用 <strong>减法形式</strong>。</li>
</ul>

<p>给定一个整数，将其转换为罗马数字。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">num = 3749</span></p>

<p><strong>输出：</strong>&nbsp;<span class="example-io">"MMMDCCXLIX"</span></p>

<p><strong>解释：</strong></p>

<pre>
3000 = MMM 由于 1000 (M) + 1000 (M) + 1000 (M)
 700 = DCC 由于 500 (D) + 100 (C) + 100 (C)
  40 = XL 由于 50 (L) 减 10 (X)
   9 = IX 由于 10 (X) 减 1 (I)
注意：49 不是 50 (L) 减 1 (I) 因为转换是基于小数位
</pre>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">num = 58</span></p>

<p><strong>输出：</strong><span class="example-io">"LVIII"</span></p>

<p><strong>解释：</strong></p>

<pre>
50 = L
 8 = VIII
</pre>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">num = 1994</span></p>

<p><strong>输出：</strong><span class="example-io">"MCMXCIV"</span></p>

<p><strong>解释：</strong></p>

<pre>
1000 = M
 900 = CM
  90 = XC
   4 = IV
</pre>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num &lt;= 3999</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

我们可以先将所有可能的符号 $cs$ 和对应的数值 $vs$ 列出来，然后从大到小枚举每个数值 $vs[i]$，每次尽可能多地使用该数值对应的符号 $cs[i]$，直到数字 $num$ 变为 $0$。

时间复杂度为 $O(m)$，空间复杂度为 $O(m)$。其中 $m$ 为符号的个数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def intToRoman(self, num: int) -> str:
        cs = ('M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I')
        vs = (1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1)
        ans = []
        for c, v in zip(cs, vs):
            while num >= v:
                num -= v
                ans.append(c)
        return ''.join(ans)
```

#### Java

```java
class Solution {
    public String intToRoman(int num) {
        List<String> cs
            = List.of("M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I");
        List<Integer> vs = List.of(1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1);
        StringBuilder ans = new StringBuilder();
        for (int i = 0, n = cs.size(); i < n; ++i) {
            while (num >= vs.get(i)) {
                num -= vs.get(i);
                ans.append(cs.get(i));
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
    string intToRoman(int num) {
        vector<string> cs = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> vs = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string ans;
        for (int i = 0; i < cs.size(); ++i) {
            while (num >= vs[i]) {
                num -= vs[i];
                ans += cs[i];
            }
        }
        return ans;
    }
};
```

#### Go

```go
func intToRoman(num int) string {
	cs := []string{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"}
	vs := []int{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}
	ans := &strings.Builder{}
	for i, v := range vs {
		for num >= v {
			num -= v
			ans.WriteString(cs[i])
		}
	}
	return ans.String()
}
```

#### TypeScript

```ts
function intToRoman(num: number): string {
    const cs: string[] = ['M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I'];
    const vs: number[] = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1];
    const ans: string[] = [];
    for (let i = 0; i < vs.length; ++i) {
        while (num >= vs[i]) {
            num -= vs[i];
            ans.push(cs[i]);
        }
    }
    return ans.join('');
}
```

#### Rust

```rust
impl Solution {
    pub fn int_to_roman(num: i32) -> String {
        let cs = [
            "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I",
        ];
        let vs = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1];
        let mut num = num;
        let mut ans = String::new();

        for (i, &v) in vs.iter().enumerate() {
            while num >= v {
                num -= v;
                ans.push_str(cs[i]);
            }
        }

        ans
    }
}
```

#### C#

```cs
public class Solution {
    public string IntToRoman(int num) {
        List<string> cs = new List<string>{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        List<int> vs = new List<int>{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < cs.Count; i++) {
            while (num >= vs[i]) {
                ans.Append(cs[i]);
                num -= vs[i];
            }
        }
        return ans.ToString();
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param Integer $num
     * @return String
     */
    function intToRoman($num) {
        $cs = ['M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I'];
        $vs = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1];
        $ans = '';

        foreach ($vs as $i => $v) {
            while ($num >= $v) {
                $num -= $v;
                $ans .= $cs[$i];
            }
        }

        return $ans;
    }
}
```

#### C

```c
static const char* cs[] = {
    "M", "CM", "D", "CD", "C", "XC",
    "L", "XL", "X", "IX", "V", "IV", "I"};

static const int vs[] = {
    1000, 900, 500, 400, 100, 90,
    50, 40, 10, 9, 5, 4, 1};

char* intToRoman(int num) {
    static char ans[20];
    ans[0] = '\0';
    for (int i = 0; i < 13; ++i) {
        while (num >= vs[i]) {
            num -= vs[i];
            strcat(ans, cs[i]);
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

# [13. 罗马数字转整数](https://leetcode.cn/problems/roman-to-integer){#13}

{{< tabs "13" >}}

{{% tab "python" %}}
```python
class Solution:
    def romanToInt(self, s: str) -> int:
        d = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        return sum((-1 if d[a] < d[b] else 1) * d[a] for a, b in pairwise(s)) + d[s[-1]]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int romanToInt(String s) {
        String cs = "IVXLCDM";
        int[] vs = {1, 5, 10, 50, 100, 500, 1000};
        Map<Character, Integer> d = new HashMap<>();
        for (int i = 0; i < vs.length; ++i) {
            d.put(cs.charAt(i), vs[i]);
        }
        int n = s.length();
        int ans = d.get(s.charAt(n - 1));
        for (int i = 0; i < n - 1; ++i) {
            int sign = d.get(s.charAt(i)) < d.get(s.charAt(i + 1)) ? -1 : 1;
            ans += sign * d.get(s.charAt(i));
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
    int romanToInt(string s) {
        unordered_map<char, int> nums{
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
        int ans = nums[s.back()];
        for (int i = 0; i < s.size() - 1; ++i) {
            int sign = nums[s[i]] < nums[s[i + 1]] ? -1 : 1;
            ans += sign * nums[s[i]];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func romanToInt(s string) (ans int) {
	d := map[byte]int{'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
	for i := 0; i < len(s)-1; i++ {
		if d[s[i]] < d[s[i+1]] {
			ans -= d[s[i]]
		} else {
			ans += d[s[i]]
		}
	}
	ans += d[s[len(s)-1]]
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function romanToInt(s: string): number {
    const d: Map<string, number> = new Map([
        ['I', 1],
        ['V', 5],
        ['X', 10],
        ['L', 50],
        ['C', 100],
        ['D', 500],
        ['M', 1000],
    ]);
    let ans: number = d.get(s[s.length - 1])!;
    for (let i = 0; i < s.length - 1; ++i) {
        const sign = d.get(s[i])! < d.get(s[i + 1])! ? -1 : 1;
        ans += sign * d.get(s[i])!;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn roman_to_int(s: String) -> i32 {
        let d = vec![
            ('I', 1),
            ('V', 5),
            ('X', 10),
            ('L', 50),
            ('C', 100),
            ('D', 500),
            ('M', 1000),
        ]
        .into_iter()
        .collect::<std::collections::HashMap<_, _>>();

        let s: Vec<char> = s.chars().collect();
        let mut ans = 0;
        let len = s.len();

        for i in 0..len - 1 {
            if d[&s[i]] < d[&s[i + 1]] {
                ans -= d[&s[i]];
            } else {
                ans += d[&s[i]];
            }
        }

        ans += d[&s[len - 1]];
        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
const romanToInt = function (s) {
    const d = {
        I: 1,
        V: 5,
        X: 10,
        L: 50,
        C: 100,
        D: 500,
        M: 1000,
    };
    let ans = d[s[s.length - 1]];
    for (let i = 0; i < s.length - 1; ++i) {
        const sign = d[s[i]] < d[s[i + 1]] ? -1 : 1;
        ans += sign * d[s[i]];
    }
    return ans;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int RomanToInt(string s) {
        Dictionary<char, int> d = new Dictionary<char, int>();
        d.Add('I', 1);
        d.Add('V', 5);
        d.Add('X', 10);
        d.Add('L', 50);
        d.Add('C', 100);
        d.Add('D', 500);
        d.Add('M', 1000);
        int ans = d[s[s.Length - 1]];
        for (int i = 0; i < s.Length - 1; ++i) {
            int sign = d[s[i]] < d[s[i + 1]] ? -1 : 1;
            ans += sign * d[s[i]];
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param String $s
     * @return Integer
     */
    function romanToInt($s) {
        $d = [
            'I' => 1,
            'V' => 5,
            'X' => 10,
            'L' => 50,
            'C' => 100,
            'D' => 500,
            'M' => 1000,
        ];
        $ans = 0;
        $len = strlen($s);

        for ($i = 0; $i < $len - 1; $i++) {
            if ($d[$s[$i]] < $d[$s[$i + 1]]) {
                $ans -= $d[$s[$i]];
            } else {
                $ans += $d[$s[$i]];
            }
        }

        $ans += $d[$s[$len - 1]];
        return $ans;
    }
}
```
{{% /tab %}}
{{% tab "rb" %}}
```rb
# @param {String} s
# @return {Integer}
def roman_to_int(s)
  d = {
      'I' => 1, 'V' => 5, 'X' => 10,
      'L' => 50, 'C' => 100,
      'D' => 500, 'M' => 1000
  }
  ans = 0
  len = s.length

  (0...len-1).each do |i|
      if d[s[i]] < d[s[i + 1]]
          ans -= d[s[i]]
      else
          ans += d[s[i]]
      end
  end

  ans += d[s[len - 1]]
  ans
end
```
{{% /tab %}}
{{% tab "c" %}}
```c
int nums(char c) {
    switch (c) {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default: return 0;
    }
}

int romanToInt(char* s) {
    int ans = nums(s[strlen(s) - 1]);
    for (int i = 0; i < (int) strlen(s) - 1; ++i) {
        int sign = nums(s[i]) < nums(s[i + 1]) ? -1 : 1;
        ans += sign * nums(s[i]);
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

<p>罗马数字包含以下七种字符:&nbsp;<code>I</code>，&nbsp;<code>V</code>，&nbsp;<code>X</code>，&nbsp;<code>L</code>，<code>C</code>，<code>D</code>&nbsp;和&nbsp;<code>M</code>。</p>

<pre>
<strong>字符</strong>          <strong>数值</strong>
I             1
V             5
X             10
L             50
C             100
D             500
M             1000</pre>

<p>例如， 罗马数字 <code>2</code> 写做&nbsp;<code>II</code>&nbsp;，即为两个并列的 1 。<code>12</code> 写做&nbsp;<code>XII</code>&nbsp;，即为&nbsp;<code>X</code>&nbsp;+&nbsp;<code>II</code>&nbsp;。 <code>27</code> 写做&nbsp;&nbsp;<code>XXVII</code>, 即为&nbsp;<code>XX</code>&nbsp;+&nbsp;<code>V</code>&nbsp;+&nbsp;<code>II</code>&nbsp;。</p>

<p>通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做&nbsp;<code>IIII</code>，而是&nbsp;<code>IV</code>。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为&nbsp;<code>IX</code>。这个特殊的规则只适用于以下六种情况：</p>

<ul>
	<li><code>I</code>&nbsp;可以放在&nbsp;<code>V</code>&nbsp;(5) 和&nbsp;<code>X</code>&nbsp;(10) 的左边，来表示 4 和 9。</li>
	<li><code>X</code>&nbsp;可以放在&nbsp;<code>L</code>&nbsp;(50) 和&nbsp;<code>C</code>&nbsp;(100) 的左边，来表示 40 和&nbsp;90。&nbsp;</li>
	<li><code>C</code>&nbsp;可以放在&nbsp;<code>D</code>&nbsp;(500) 和&nbsp;<code>M</code>&nbsp;(1000) 的左边，来表示&nbsp;400 和&nbsp;900。</li>
</ul>

<p>给定一个罗马数字，将其转换成整数。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre>
<strong>输入:</strong>&nbsp;s = "III"
<strong>输出:</strong> 3</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre>
<strong>输入:</strong>&nbsp;s = "IV"
<strong>输出:</strong> 4</pre>

<p><strong>示例&nbsp;3:</strong></p>

<pre>
<strong>输入:</strong>&nbsp;s = "IX"
<strong>输出:</strong> 9</pre>

<p><strong>示例&nbsp;4:</strong></p>

<pre>
<strong>输入:</strong>&nbsp;s = "LVIII"
<strong>输出:</strong> 58
<strong>解释:</strong> L = 50, V= 5, III = 3.
</pre>

<p><strong>示例&nbsp;5:</strong></p>

<pre>
<strong>输入:</strong>&nbsp;s = "MCMXCIV"
<strong>输出:</strong> 1994
<strong>解释:</strong> M = 1000, CM = 900, XC = 90, IV = 4.</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 15</code></li>
	<li><code>s</code> 仅含字符 <code>('I', 'V', 'X', 'L', 'C', 'D', 'M')</code></li>
	<li>题目数据保证 <code>s</code> 是一个有效的罗马数字，且表示整数在范围 <code>[1, 3999]</code> 内</li>
	<li>题目所给测试用例皆符合罗马数字书写规则，不会出现跨位等情况。</li>
	<li>IL 和 IM 这样的例子并不符合题目要求，49 应该写作 XLIX，999 应该写作 CMXCIX 。</li>
	<li>关于罗马数字的详尽书写规则，可以参考 <a href="https://baike.baidu.com/item/%E7%BD%97%E9%A9%AC%E6%95%B0%E5%AD%97/772296">罗马数字 - 百度百科</a>。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 模拟

我们先用哈希表 $d$ 记录每个字符对应的数值，然后从左到右遍历字符串 $s$，如果当前字符对应的数值小于右边字符对应的数值，则减去当前字符对应的数值，否则加上当前字符对应的数值。

时间复杂度 $(n)$，空间复杂度 $O(m)$。其中 $n$ 和 $m$ 分别为字符串 $s$ 的长度和字符集的大小。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def romanToInt(self, s: str) -> int:
        d = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        return sum((-1 if d[a] < d[b] else 1) * d[a] for a, b in pairwise(s)) + d[s[-1]]
```

#### Java

```java
class Solution {
    public int romanToInt(String s) {
        String cs = "IVXLCDM";
        int[] vs = {1, 5, 10, 50, 100, 500, 1000};
        Map<Character, Integer> d = new HashMap<>();
        for (int i = 0; i < vs.length; ++i) {
            d.put(cs.charAt(i), vs[i]);
        }
        int n = s.length();
        int ans = d.get(s.charAt(n - 1));
        for (int i = 0; i < n - 1; ++i) {
            int sign = d.get(s.charAt(i)) < d.get(s.charAt(i + 1)) ? -1 : 1;
            ans += sign * d.get(s.charAt(i));
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> nums{
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
        int ans = nums[s.back()];
        for (int i = 0; i < s.size() - 1; ++i) {
            int sign = nums[s[i]] < nums[s[i + 1]] ? -1 : 1;
            ans += sign * nums[s[i]];
        }
        return ans;
    }
};
```

#### Go

```go
func romanToInt(s string) (ans int) {
	d := map[byte]int{'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
	for i := 0; i < len(s)-1; i++ {
		if d[s[i]] < d[s[i+1]] {
			ans -= d[s[i]]
		} else {
			ans += d[s[i]]
		}
	}
	ans += d[s[len(s)-1]]
	return
}
```

#### TypeScript

```ts
function romanToInt(s: string): number {
    const d: Map<string, number> = new Map([
        ['I', 1],
        ['V', 5],
        ['X', 10],
        ['L', 50],
        ['C', 100],
        ['D', 500],
        ['M', 1000],
    ]);
    let ans: number = d.get(s[s.length - 1])!;
    for (let i = 0; i < s.length - 1; ++i) {
        const sign = d.get(s[i])! < d.get(s[i + 1])! ? -1 : 1;
        ans += sign * d.get(s[i])!;
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn roman_to_int(s: String) -> i32 {
        let d = vec![
            ('I', 1),
            ('V', 5),
            ('X', 10),
            ('L', 50),
            ('C', 100),
            ('D', 500),
            ('M', 1000),
        ]
        .into_iter()
        .collect::<std::collections::HashMap<_, _>>();

        let s: Vec<char> = s.chars().collect();
        let mut ans = 0;
        let len = s.len();

        for i in 0..len - 1 {
            if d[&s[i]] < d[&s[i + 1]] {
                ans -= d[&s[i]];
            } else {
                ans += d[&s[i]];
            }
        }

        ans += d[&s[len - 1]];
        ans
    }
}
```

#### JavaScript

```js
const romanToInt = function (s) {
    const d = {
        I: 1,
        V: 5,
        X: 10,
        L: 50,
        C: 100,
        D: 500,
        M: 1000,
    };
    let ans = d[s[s.length - 1]];
    for (let i = 0; i < s.length - 1; ++i) {
        const sign = d[s[i]] < d[s[i + 1]] ? -1 : 1;
        ans += sign * d[s[i]];
    }
    return ans;
};
```

#### C#

```cs
public class Solution {
    public int RomanToInt(string s) {
        Dictionary<char, int> d = new Dictionary<char, int>();
        d.Add('I', 1);
        d.Add('V', 5);
        d.Add('X', 10);
        d.Add('L', 50);
        d.Add('C', 100);
        d.Add('D', 500);
        d.Add('M', 1000);
        int ans = d[s[s.Length - 1]];
        for (int i = 0; i < s.Length - 1; ++i) {
            int sign = d[s[i]] < d[s[i + 1]] ? -1 : 1;
            ans += sign * d[s[i]];
        }
        return ans;
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param String $s
     * @return Integer
     */
    function romanToInt($s) {
        $d = [
            'I' => 1,
            'V' => 5,
            'X' => 10,
            'L' => 50,
            'C' => 100,
            'D' => 500,
            'M' => 1000,
        ];
        $ans = 0;
        $len = strlen($s);

        for ($i = 0; $i < $len - 1; $i++) {
            if ($d[$s[$i]] < $d[$s[$i + 1]]) {
                $ans -= $d[$s[$i]];
            } else {
                $ans += $d[$s[$i]];
            }
        }

        $ans += $d[$s[$len - 1]];
        return $ans;
    }
}
```

#### Ruby

```rb
# @param {String} s
# @return {Integer}
def roman_to_int(s)
  d = {
      'I' => 1, 'V' => 5, 'X' => 10,
      'L' => 50, 'C' => 100,
      'D' => 500, 'M' => 1000
  }
  ans = 0
  len = s.length

  (0...len-1).each do |i|
      if d[s[i]] < d[s[i + 1]]
          ans -= d[s[i]]
      else
          ans += d[s[i]]
      end
  end

  ans += d[s[len - 1]]
  ans
end
```

#### C

```c
int nums(char c) {
    switch (c) {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default: return 0;
    }
}

int romanToInt(char* s) {
    int ans = nums(s[strlen(s) - 1]);
    for (int i = 0; i < (int) strlen(s) - 1; ++i) {
        int sign = nums(s[i]) < nums(s[i + 1]) ? -1 : 1;
        ans += sign * nums(s[i]);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [14. 最长公共前缀](https://leetcode.cn/problems/longest-common-prefix){#14}

{{< tabs "14" >}}

{{% tab "python" %}}
```python
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        for i in range(len(strs[0])):
            for s in strs[1:]:
                if len(s) <= i or s[i] != strs[0][i]:
                    return s[:i]
        return strs[0]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        int n = strs.length;
        for (int i = 0; i < strs[0].length(); ++i) {
            for (int j = 1; j < n; ++j) {
                if (strs[j].length() <= i || strs[j].charAt(i) != strs[0].charAt(i)) {
                    return strs[0].substring(0, i);
                }
            }
        }
        return strs[0];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        for (int i = 0; i < strs[0].size(); ++i) {
            for (int j = 1; j < n; ++j) {
                if (strs[j].size() <= i || strs[j][i] != strs[0][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func longestCommonPrefix(strs []string) string {
	n := len(strs)
	for i := range strs[0] {
		for j := 1; j < n; j++ {
			if len(strs[j]) <= i || strs[j][i] != strs[0][i] {
				return strs[0][:i]
			}
		}
	}
	return strs[0]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function longestCommonPrefix(strs: string[]): string {
    const len = strs.reduce((r, s) => Math.min(r, s.length), Infinity);
    for (let i = len; i > 0; i--) {
        const target = strs[0].slice(0, i);
        if (strs.every(s => s.slice(0, i) === target)) {
            return target;
        }
    }
    return '';
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn longest_common_prefix(strs: Vec<String>) -> String {
        let mut len = strs.iter().map(|s| s.len()).min().unwrap();
        for i in (1..=len).rev() {
            let mut is_equal = true;
            let target = strs[0][0..i].to_string();
            if strs.iter().all(|s| target == s[0..i]) {
                return target;
            }
        }
        String::new()
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function (strs) {
    for (let j = 0; j < strs[0].length; j++) {
        for (let i = 0; i < strs.length; i++) {
            if (strs[0][j] !== strs[i][j]) {
                return strs[0].substring(0, j);
            }
        }
    }
    return strs[0];
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public string LongestCommonPrefix(string[] strs) {
        int n = strs.Length;
        for (int i = 0; i < strs[0].Length; ++i) {
            for (int j = 1; j < n; ++j) {
                if (i >= strs[j].Length || strs[j][i] != strs[0][i]) {
                    return strs[0].Substring(0, i);
                }
            }
        }
        return strs[0];
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param String[] $strs
     * @return String
     */
    function longestCommonPrefix($strs) {
        $rs = '';
        for ($i = 0; $i < strlen($strs[0]); $i++) {
            for ($j = 1; $j < count($strs); $j++) {
                if ($strs[0][$i] != $strs[$j][$i]) {
                    return $rs;
                }
            }
            $rs = $rs . $strs[0][$i];
        }
        return $rs;
    }
}
```
{{% /tab %}}
{{% tab "rb" %}}
```rb
# @param {String[]} strs
# @return {String}
def longest_common_prefix(strs)
  return '' if strs.nil? || strs.length.zero?

  return strs[0] if strs.length == 1

  idx = 0
  while idx < strs[0].length
    cur_char = strs[0][idx]

    str_idx = 1
    while str_idx < strs.length
      return idx > 0 ? strs[0][0..idx-1] : '' if strs[str_idx].length <= idx

      return '' if strs[str_idx][idx] != cur_char && idx.zero?
      return strs[0][0..idx - 1] if strs[str_idx][idx] != cur_char
      str_idx += 1
    end

    idx += 1
  end

  idx > 0 ? strs[0][0..idx] : ''
end
```
{{% /tab %}}
{{% tab "c" %}}
```c
char* longestCommonPrefix(char** strs, int strsSize) {
    for (int i = 0; strs[0][i]; i++) {
        for (int j = 1; j < strsSize; j++) {
            if (strs[j][i] != strs[0][i]) {
                strs[0][i] = '\0';
                return strs[0];
            }
        }
    }
    return strs[0];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>编写一个函数来查找字符串数组中的最长公共前缀。</p>

<p>如果不存在公共前缀，返回空字符串&nbsp;<code>""</code>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>strs = ["flower","flow","flight"]
<strong>输出：</strong>"fl"
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>strs = ["dog","racecar","car"]
<strong>输出：</strong>""
<strong>解释：</strong>输入不存在公共前缀。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= strs.length &lt;= 200</code></li>
	<li><code>0 &lt;= strs[i].length &lt;= 200</code></li>
	<li><code>strs[i]</code>&nbsp;如果非空，则仅由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：字符比较

我们以第一个字符串 $strs[0]$ 为基准，依次比较后面的字符串的第 $i$ 个字符是否与 $strs[0]$ 的第 $i$ 个字符相同，如果相同则继续比较下一个字符，否则返回 $strs[0]$ 的前 $i$ 个字符。

遍历结束，说明所有字符串的前 $i$ 个字符都相同，返回 $strs[0]$ 即可。

时间复杂度 $(n \times m)$，其中 $n$ 和 $m$ 分别为字符串数组的长度以及字符串的最小长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        for i in range(len(strs[0])):
            for s in strs[1:]:
                if len(s) <= i or s[i] != strs[0][i]:
                    return s[:i]
        return strs[0]
```

#### Java

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        int n = strs.length;
        for (int i = 0; i < strs[0].length(); ++i) {
            for (int j = 1; j < n; ++j) {
                if (strs[j].length() <= i || strs[j].charAt(i) != strs[0].charAt(i)) {
                    return strs[0].substring(0, i);
                }
            }
        }
        return strs[0];
    }
}
```

#### C++

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        for (int i = 0; i < strs[0].size(); ++i) {
            for (int j = 1; j < n; ++j) {
                if (strs[j].size() <= i || strs[j][i] != strs[0][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};
```

#### Go

```go
func longestCommonPrefix(strs []string) string {
	n := len(strs)
	for i := range strs[0] {
		for j := 1; j < n; j++ {
			if len(strs[j]) <= i || strs[j][i] != strs[0][i] {
				return strs[0][:i]
			}
		}
	}
	return strs[0]
}
```

#### TypeScript

```ts
function longestCommonPrefix(strs: string[]): string {
    const len = strs.reduce((r, s) => Math.min(r, s.length), Infinity);
    for (let i = len; i > 0; i--) {
        const target = strs[0].slice(0, i);
        if (strs.every(s => s.slice(0, i) === target)) {
            return target;
        }
    }
    return '';
}
```

#### Rust

```rust
impl Solution {
    pub fn longest_common_prefix(strs: Vec<String>) -> String {
        let mut len = strs.iter().map(|s| s.len()).min().unwrap();
        for i in (1..=len).rev() {
            let mut is_equal = true;
            let target = strs[0][0..i].to_string();
            if strs.iter().all(|s| target == s[0..i]) {
                return target;
            }
        }
        String::new()
    }
}
```

#### JavaScript

```js
/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function (strs) {
    for (let j = 0; j < strs[0].length; j++) {
        for (let i = 0; i < strs.length; i++) {
            if (strs[0][j] !== strs[i][j]) {
                return strs[0].substring(0, j);
            }
        }
    }
    return strs[0];
};
```

#### C#

```cs
public class Solution {
    public string LongestCommonPrefix(string[] strs) {
        int n = strs.Length;
        for (int i = 0; i < strs[0].Length; ++i) {
            for (int j = 1; j < n; ++j) {
                if (i >= strs[j].Length || strs[j][i] != strs[0][i]) {
                    return strs[0].Substring(0, i);
                }
            }
        }
        return strs[0];
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param String[] $strs
     * @return String
     */
    function longestCommonPrefix($strs) {
        $rs = '';
        for ($i = 0; $i < strlen($strs[0]); $i++) {
            for ($j = 1; $j < count($strs); $j++) {
                if ($strs[0][$i] != $strs[$j][$i]) {
                    return $rs;
                }
            }
            $rs = $rs . $strs[0][$i];
        }
        return $rs;
    }
}
```

#### Ruby

```rb
# @param {String[]} strs
# @return {String}
def longest_common_prefix(strs)
  return '' if strs.nil? || strs.length.zero?

  return strs[0] if strs.length == 1

  idx = 0
  while idx < strs[0].length
    cur_char = strs[0][idx]

    str_idx = 1
    while str_idx < strs.length
      return idx > 0 ? strs[0][0..idx-1] : '' if strs[str_idx].length <= idx

      return '' if strs[str_idx][idx] != cur_char && idx.zero?
      return strs[0][0..idx - 1] if strs[str_idx][idx] != cur_char
      str_idx += 1
    end

    idx += 1
  end

  idx > 0 ? strs[0][0..idx] : ''
end
```

#### C

```c
char* longestCommonPrefix(char** strs, int strsSize) {
    for (int i = 0; strs[0][i]; i++) {
        for (int j = 1; j < strsSize; j++) {
            if (strs[j][i] != strs[0][i]) {
                strs[0][i] = '\0';
                return strs[0];
            }
        }
    }
    return strs[0];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [15. 三数之和](https://leetcode.cn/problems/3sum){#15}

{{< tabs "15" >}}

{{% tab "python" %}}
```python
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        n = len(nums)
        ans = []
        for i in range(n - 2):
            if nums[i] > 0:
                break
            if i and nums[i] == nums[i - 1]:
                continue
            j, k = i + 1, n - 1
            while j < k:
                x = nums[i] + nums[j] + nums[k]
                if x < 0:
                    j += 1
                elif x > 0:
                    k -= 1
                else:
                    ans.append([nums[i], nums[j], nums[k]])
                    j, k = j + 1, k - 1
                    while j < k and nums[j] == nums[j - 1]:
                        j += 1
                    while j < k and nums[k] == nums[k + 1]:
                        k -= 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<>();
        int n = nums.length;
        for (int i = 0; i < n - 2 && nums[i] <= 0; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1, k = n - 1;
            while (j < k) {
                int x = nums[i] + nums[j] + nums[k];
                if (x < 0) {
                    ++j;
                } else if (x > 0) {
                    --k;
                } else {
                    ans.add(List.of(nums[i], nums[j++], nums[k--]));
                    while (j < k && nums[j] == nums[j - 1]) {
                        ++j;
                    }
                    while (j < k && nums[k] == nums[k + 1]) {
                        --k;
                    }
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
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n - 2 && nums[i] <= 0; ++i) {
            if (i && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1, k = n - 1;
            while (j < k) {
                int x = nums[i] + nums[j] + nums[k];
                if (x < 0) {
                    ++j;
                } else if (x > 0) {
                    --k;
                } else {
                    ans.push_back({nums[i], nums[j++], nums[k--]});
                    while (j < k && nums[j] == nums[j - 1]) {
                        ++j;
                    }
                    while (j < k && nums[k] == nums[k + 1]) {
                        --k;
                    }
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
func threeSum(nums []int) (ans [][]int) {
	sort.Ints(nums)
	n := len(nums)
	for i := 0; i < n-2 && nums[i] <= 0; i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		j, k := i+1, n-1
		for j < k {
			x := nums[i] + nums[j] + nums[k]
			if x < 0 {
				j++
			} else if x > 0 {
				k--
			} else {
				ans = append(ans, []int{nums[i], nums[j], nums[k]})
				j, k = j+1, k-1
				for j < k && nums[j] == nums[j-1] {
					j++
				}
				for j < k && nums[k] == nums[k+1] {
					k--
				}
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function threeSum(nums: number[]): number[][] {
    nums.sort((a, b) => a - b);
    const ans: number[][] = [];
    const n = nums.length;
    for (let i = 0; i < n - 2 && nums[i] <= 0; i++) {
        if (i > 0 && nums[i] === nums[i - 1]) {
            continue;
        }
        let j = i + 1;
        let k = n - 1;
        while (j < k) {
            const x = nums[i] + nums[j] + nums[k];
            if (x < 0) {
                ++j;
            } else if (x > 0) {
                --k;
            } else {
                ans.push([nums[i], nums[j++], nums[k--]]);
                while (j < k && nums[j] === nums[j - 1]) {
                    ++j;
                }
                while (j < k && nums[k] === nums[k + 1]) {
                    --k;
                }
            }
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::cmp::Ordering;

impl Solution {
    pub fn three_sum(mut nums: Vec<i32>) -> Vec<Vec<i32>> {
        nums.sort();
        let n = nums.len();
        let mut res = vec![];
        let mut i = 0;
        while i < n - 2 && nums[i] <= 0 {
            let mut l = i + 1;
            let mut r = n - 1;
            while l < r {
                match (nums[i] + nums[l] + nums[r]).cmp(&0) {
                    Ordering::Less => {
                        l += 1;
                    }
                    Ordering::Greater => {
                        r -= 1;
                    }
                    Ordering::Equal => {
                        res.push(vec![nums[i], nums[l], nums[r]]);
                        l += 1;
                        r -= 1;
                        while l < n && nums[l] == nums[l - 1] {
                            l += 1;
                        }
                        while r > 0 && nums[r] == nums[r + 1] {
                            r -= 1;
                        }
                    }
                }
            }
            i += 1;
            while i < n - 2 && nums[i] == nums[i - 1] {
                i += 1;
            }
        }
        res
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function (nums) {
    const n = nums.length;
    nums.sort((a, b) => a - b);
    const ans = [];
    for (let i = 0; i < n - 2 && nums[i] <= 0; ++i) {
        if (i > 0 && nums[i] === nums[i - 1]) {
            continue;
        }
        let j = i + 1;
        let k = n - 1;
        while (j < k) {
            const x = nums[i] + nums[j] + nums[k];
            if (x < 0) {
                ++j;
            } else if (x > 0) {
                --k;
            } else {
                ans.push([nums[i], nums[j++], nums[k--]]);
                while (j < k && nums[j] === nums[j - 1]) {
                    ++j;
                }
                while (j < k && nums[k] === nums[k + 1]) {
                    --k;
                }
            }
        }
    }
    return ans;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public IList<IList<int>> ThreeSum(int[] nums) {
        Array.Sort(nums);
        int n = nums.Length;
        IList<IList<int>> ans = new List<IList<int>>();
        for (int i = 0; i < n - 2 && nums[i] <= 0; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1, k = n - 1;
            while (j < k) {
                int x = nums[i] + nums[j] + nums[k];
                if (x < 0) {
                    ++j;
                } else if (x > 0) {
                    --k;
                } else {
                    ans.Add(new List<int> { nums[i], nums[j--], nums[k--] });
                    while (j < k && nums[j] == nums[j + 1]) {
                        ++j;
                    }
                    while (j < k && nums[k] == nums[k + 1]) {
                        --k;
                    }
                }
            }
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "rb" %}}
```rb
# @param {Integer[]} nums
# @return {Integer[][]}
def three_sum(nums)
  res = []
  nums.sort!

  for i in 0..(nums.length - 3)
    next if i > 0 && nums[i - 1] == nums[i]
    j = i + 1
    k = nums.length - 1
    while j < k do
      sum = nums[i] + nums[j] + nums[k]
      if sum < 0
        j += 1
      elsif sum > 0
        k -= 1
      else
        res += [[nums[i], nums[j], nums[k]]]
        j += 1
        k -= 1
        j += 1 while nums[j] == nums[j - 1]
        k -= 1 while nums[k] == nums[k + 1]
      end
    end
  end

  res
end
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer[] $nums
     * @return Integer[][]
     */
    function threeSum($nums) {
        sort($nums);
        $ans = [];
        $n = count($nums);
        for ($i = 0; $i < $n - 2 && $nums[$i] <= 0; ++$i) {
            if ($i > 0 && $nums[$i] == $nums[$i - 1]) {
                continue;
            }
            $j = $i + 1;
            $k = $n - 1;
            while ($j < $k) {
                $x = $nums[$i] + $nums[$j] + $nums[$k];
                if ($x < 0) {
                    ++$j;
                } elseif ($x > 0) {
                    --$k;
                } else {
                    $ans[] = [$nums[$i], $nums[$j++], $nums[$k--]];
                    while ($j < $k && $nums[$j] == $nums[$j - 1]) {
                        ++$j;
                    }
                    while ($j < $k && $nums[$k] == $nums[$k + 1]) {
                        --$k;
                    }
                }
            }
        }
        return $ans;
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int cmp(const void* a, const void* b) {
    return *(int*) a - *(int*) b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    int cap = 1000;
    int** ans = (int**) malloc(sizeof(int*) * cap);
    *returnColumnSizes = (int*) malloc(sizeof(int) * cap);

    qsort(nums, numsSize, sizeof(int), cmp);

    for (int i = 0; i < numsSize - 2 && nums[i] <= 0; ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int j = i + 1, k = numsSize - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum < 0) {
                ++j;
            } else if (sum > 0) {
                --k;
            } else {
                if (*returnSize >= cap) {
                    cap *= 2;
                    ans = (int**) realloc(ans, sizeof(int*) * cap);
                    *returnColumnSizes = (int*) realloc(*returnColumnSizes, sizeof(int) * cap);
                }
                ans[*returnSize] = (int*) malloc(sizeof(int) * 3);
                ans[*returnSize][0] = nums[i];
                ans[*returnSize][1] = nums[j];
                ans[*returnSize][2] = nums[k];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                ++j;
                --k;
                while (j < k && nums[j] == nums[j - 1]) ++j;
                while (j < k && nums[k] == nums[k + 1]) --k;
            }
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

<p>给你一个整数数组 <code>nums</code> ，判断是否存在三元组 <code>[nums[i], nums[j], nums[k]]</code> 满足 <code>i != j</code>、<code>i != k</code> 且 <code>j != k</code> ，同时还满足 <code>nums[i] + nums[j] + nums[k] == 0</code> 。请你返回所有和为 <code>0</code> 且不重复的三元组。</p>

<p><strong>注意：</strong>答案中不可以包含重复的三元组。</p>

<p>&nbsp;</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [-1,0,1,2,-1,-4]
<strong>输出：</strong>[[-1,-1,2],[-1,0,1]]
<strong>解释：</strong>
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
注意，输出的顺序和三元组的顺序并不重要。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,1,1]
<strong>输出：</strong>[]
<strong>解释：</strong>唯一可能的三元组和不为 0 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,0,0]
<strong>输出：</strong>[[0,0,0]]
<strong>解释：</strong>唯一可能的三元组和为 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 3000</code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 双指针

我们注意到，题目不要求我们按照顺序返回三元组，因此我们不妨先对数组进行排序，这样就可以方便地跳过重复的元素。

接下来，我们枚举三元组的第一个元素 $nums[i]$，其中 $0 \leq i \lt n - 2$。对于每个 $i$，我们可以通过维护两个指针 $j = i + 1$ 和 $k = n - 1$，从而找到满足 $nums[i] + nums[j] + nums[k] = 0$ 的 $j$ 和 $k$。在枚举的过程中，我们需要跳过重复的元素，以避免出现重复的三元组。

具体判断逻辑如下：

如果 $i \gt 0$ 并且 $nums[i] = nums[i - 1]$，则说明当前枚举的元素与上一个元素相同，我们可以直接跳过，因为不会产生新的结果。

如果 $nums[i] \gt 0$，则说明当前枚举的元素大于 $0$，则三数之和必然无法等于 $0$，结束枚举。

否则，我们令左指针 $j = i + 1$，右指针 $k = n - 1$，当 $j \lt k$ 时，执行循环，计算三数之和 $x = nums[i] + nums[j] + nums[k]$，并与 $0$ 比较：

-   如果 $x \lt 0$，则说明 $nums[j]$ 太小，我们需要将 $j$ 右移一位。
-   如果 $x \gt 0$，则说明 $nums[k]$ 太大，我们需要将 $k$ 左移一位。
-   否则，说明我们找到了一个合法的三元组，将其加入答案，并将 $j$ 右移一位，将 $k$ 左移一位，同时跳过所有重复的元素，继续寻找下一个合法的三元组。

枚举结束后，我们即可得到三元组的答案。

时间复杂度 $O(n^2)$，空间复杂度 $O(\log n)$。其中 $n$ 为数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        n = len(nums)
        ans = []
        for i in range(n - 2):
            if nums[i] > 0:
                break
            if i and nums[i] == nums[i - 1]:
                continue
            j, k = i + 1, n - 1
            while j < k:
                x = nums[i] + nums[j] + nums[k]
                if x < 0:
                    j += 1
                elif x > 0:
                    k -= 1
                else:
                    ans.append([nums[i], nums[j], nums[k]])
                    j, k = j + 1, k - 1
                    while j < k and nums[j] == nums[j - 1]:
                        j += 1
                    while j < k and nums[k] == nums[k + 1]:
                        k -= 1
        return ans
```

#### Java

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<>();
        int n = nums.length;
        for (int i = 0; i < n - 2 && nums[i] <= 0; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1, k = n - 1;
            while (j < k) {
                int x = nums[i] + nums[j] + nums[k];
                if (x < 0) {
                    ++j;
                } else if (x > 0) {
                    --k;
                } else {
                    ans.add(List.of(nums[i], nums[j++], nums[k--]));
                    while (j < k && nums[j] == nums[j - 1]) {
                        ++j;
                    }
                    while (j < k && nums[k] == nums[k + 1]) {
                        --k;
                    }
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
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n - 2 && nums[i] <= 0; ++i) {
            if (i && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1, k = n - 1;
            while (j < k) {
                int x = nums[i] + nums[j] + nums[k];
                if (x < 0) {
                    ++j;
                } else if (x > 0) {
                    --k;
                } else {
                    ans.push_back({nums[i], nums[j++], nums[k--]});
                    while (j < k && nums[j] == nums[j - 1]) {
                        ++j;
                    }
                    while (j < k && nums[k] == nums[k + 1]) {
                        --k;
                    }
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func threeSum(nums []int) (ans [][]int) {
	sort.Ints(nums)
	n := len(nums)
	for i := 0; i < n-2 && nums[i] <= 0; i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		j, k := i+1, n-1
		for j < k {
			x := nums[i] + nums[j] + nums[k]
			if x < 0 {
				j++
			} else if x > 0 {
				k--
			} else {
				ans = append(ans, []int{nums[i], nums[j], nums[k]})
				j, k = j+1, k-1
				for j < k && nums[j] == nums[j-1] {
					j++
				}
				for j < k && nums[k] == nums[k+1] {
					k--
				}
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function threeSum(nums: number[]): number[][] {
    nums.sort((a, b) => a - b);
    const ans: number[][] = [];
    const n = nums.length;
    for (let i = 0; i < n - 2 && nums[i] <= 0; i++) {
        if (i > 0 && nums[i] === nums[i - 1]) {
            continue;
        }
        let j = i + 1;
        let k = n - 1;
        while (j < k) {
            const x = nums[i] + nums[j] + nums[k];
            if (x < 0) {
                ++j;
            } else if (x > 0) {
                --k;
            } else {
                ans.push([nums[i], nums[j++], nums[k--]]);
                while (j < k && nums[j] === nums[j - 1]) {
                    ++j;
                }
                while (j < k && nums[k] === nums[k + 1]) {
                    --k;
                }
            }
        }
    }
    return ans;
}
```

#### Rust

```rust
use std::cmp::Ordering;

impl Solution {
    pub fn three_sum(mut nums: Vec<i32>) -> Vec<Vec<i32>> {
        nums.sort();
        let n = nums.len();
        let mut res = vec![];
        let mut i = 0;
        while i < n - 2 && nums[i] <= 0 {
            let mut l = i + 1;
            let mut r = n - 1;
            while l < r {
                match (nums[i] + nums[l] + nums[r]).cmp(&0) {
                    Ordering::Less => {
                        l += 1;
                    }
                    Ordering::Greater => {
                        r -= 1;
                    }
                    Ordering::Equal => {
                        res.push(vec![nums[i], nums[l], nums[r]]);
                        l += 1;
                        r -= 1;
                        while l < n && nums[l] == nums[l - 1] {
                            l += 1;
                        }
                        while r > 0 && nums[r] == nums[r + 1] {
                            r -= 1;
                        }
                    }
                }
            }
            i += 1;
            while i < n - 2 && nums[i] == nums[i - 1] {
                i += 1;
            }
        }
        res
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function (nums) {
    const n = nums.length;
    nums.sort((a, b) => a - b);
    const ans = [];
    for (let i = 0; i < n - 2 && nums[i] <= 0; ++i) {
        if (i > 0 && nums[i] === nums[i - 1]) {
            continue;
        }
        let j = i + 1;
        let k = n - 1;
        while (j < k) {
            const x = nums[i] + nums[j] + nums[k];
            if (x < 0) {
                ++j;
            } else if (x > 0) {
                --k;
            } else {
                ans.push([nums[i], nums[j++], nums[k--]]);
                while (j < k && nums[j] === nums[j - 1]) {
                    ++j;
                }
                while (j < k && nums[k] === nums[k + 1]) {
                    --k;
                }
            }
        }
    }
    return ans;
};
```

#### C#

```cs
public class Solution {
    public IList<IList<int>> ThreeSum(int[] nums) {
        Array.Sort(nums);
        int n = nums.Length;
        IList<IList<int>> ans = new List<IList<int>>();
        for (int i = 0; i < n - 2 && nums[i] <= 0; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1, k = n - 1;
            while (j < k) {
                int x = nums[i] + nums[j] + nums[k];
                if (x < 0) {
                    ++j;
                } else if (x > 0) {
                    --k;
                } else {
                    ans.Add(new List<int> { nums[i], nums[j--], nums[k--] });
                    while (j < k && nums[j] == nums[j + 1]) {
                        ++j;
                    }
                    while (j < k && nums[k] == nums[k + 1]) {
                        --k;
                    }
                }
            }
        }
        return ans;
    }
}
```

#### Ruby

```rb
# @param {Integer[]} nums
# @return {Integer[][]}
def three_sum(nums)
  res = []
  nums.sort!

  for i in 0..(nums.length - 3)
    next if i > 0 && nums[i - 1] == nums[i]
    j = i + 1
    k = nums.length - 1
    while j < k do
      sum = nums[i] + nums[j] + nums[k]
      if sum < 0
        j += 1
      elsif sum > 0
        k -= 1
      else
        res += [[nums[i], nums[j], nums[k]]]
        j += 1
        k -= 1
        j += 1 while nums[j] == nums[j - 1]
        k -= 1 while nums[k] == nums[k + 1]
      end
    end
  end

  res
end
```

#### PHP

```php
class Solution {
    /**
     * @param Integer[] $nums
     * @return Integer[][]
     */
    function threeSum($nums) {
        sort($nums);
        $ans = [];
        $n = count($nums);
        for ($i = 0; $i < $n - 2 && $nums[$i] <= 0; ++$i) {
            if ($i > 0 && $nums[$i] == $nums[$i - 1]) {
                continue;
            }
            $j = $i + 1;
            $k = $n - 1;
            while ($j < $k) {
                $x = $nums[$i] + $nums[$j] + $nums[$k];
                if ($x < 0) {
                    ++$j;
                } elseif ($x > 0) {
                    --$k;
                } else {
                    $ans[] = [$nums[$i], $nums[$j++], $nums[$k--]];
                    while ($j < $k && $nums[$j] == $nums[$j - 1]) {
                        ++$j;
                    }
                    while ($j < $k && $nums[$k] == $nums[$k + 1]) {
                        --$k;
                    }
                }
            }
        }
        return $ans;
    }
}
```

#### C

```c
int cmp(const void* a, const void* b) {
    return *(int*) a - *(int*) b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    int cap = 1000;
    int** ans = (int**) malloc(sizeof(int*) * cap);
    *returnColumnSizes = (int*) malloc(sizeof(int) * cap);

    qsort(nums, numsSize, sizeof(int), cmp);

    for (int i = 0; i < numsSize - 2 && nums[i] <= 0; ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int j = i + 1, k = numsSize - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum < 0) {
                ++j;
            } else if (sum > 0) {
                --k;
            } else {
                if (*returnSize >= cap) {
                    cap *= 2;
                    ans = (int**) realloc(ans, sizeof(int*) * cap);
                    *returnColumnSizes = (int*) realloc(*returnColumnSizes, sizeof(int) * cap);
                }
                ans[*returnSize] = (int*) malloc(sizeof(int) * 3);
                ans[*returnSize][0] = nums[i];
                ans[*returnSize][1] = nums[j];
                ans[*returnSize][2] = nums[k];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                ++j;
                --k;
                while (j < k && nums[j] == nums[j - 1]) ++j;
                while (j < k && nums[k] == nums[k + 1]) --k;
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

# [16. 最接近的三数之和](https://leetcode.cn/problems/3sum-closest){#16}

{{< tabs "16" >}}

{{% tab "python" %}}
```python
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        n = len(nums)
        ans = inf
        for i, v in enumerate(nums):
            j, k = i + 1, n - 1
            while j < k:
                t = v + nums[j] + nums[k]
                if t == target:
                    return t
                if abs(t - target) < abs(ans - target):
                    ans = t
                if t > target:
                    k -= 1
                else:
                    j += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int ans = 1 << 30;
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                int t = nums[i] + nums[j] + nums[k];
                if (t == target) {
                    return t;
                }
                if (Math.abs(t - target) < Math.abs(ans - target)) {
                    ans = t;
                }
                if (t > target) {
                    --k;
                } else {
                    ++j;
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
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 1 << 30;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                int t = nums[i] + nums[j] + nums[k];
                if (t == target) return t;
                if (abs(t - target) < abs(ans - target)) ans = t;
                if (t > target)
                    --k;
                else
                    ++j;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func threeSumClosest(nums []int, target int) int {
	sort.Ints(nums)
	ans := 1 << 30
	n := len(nums)
	for i, v := range nums {
		j, k := i+1, n-1
		for j < k {
			t := v + nums[j] + nums[k]
			if t == target {
				return t
			}
			if abs(t-target) < abs(ans-target) {
				ans = t
			}
			if t > target {
				k--
			} else {
				j++
			}
		}
	}
	return ans
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
function threeSumClosest(nums: number[], target: number): number {
    nums.sort((a, b) => a - b);
    let ans: number = 1 << 30;
    const n = nums.length;
    for (let i = 0; i < n; ++i) {
        let j = i + 1;
        let k = n - 1;
        while (j < k) {
            const t: number = nums[i] + nums[j] + nums[k];
            if (t === target) {
                return t;
            }
            if (Math.abs(t - target) < Math.abs(ans - target)) {
                ans = t;
            }
            if (t > target) {
                --k;
            } else {
                ++j;
            }
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var threeSumClosest = function (nums, target) {
    nums.sort((a, b) => a - b);
    let ans = 1 << 30;
    const n = nums.length;
    for (let i = 0; i < n; ++i) {
        let j = i + 1;
        let k = n - 1;
        while (j < k) {
            const t = nums[i] + nums[j] + nums[k];
            if (t === target) {
                return t;
            }
            if (Math.abs(t - target) < Math.abs(ans - target)) {
                ans = t;
            }
            if (t > target) {
                --k;
            } else {
                ++j;
            }
        }
    }
    return ans;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int ThreeSumClosest(int[] nums, int target) {
        Array.Sort(nums);
        int ans = 1 << 30;
        int n = nums.Length;
        for (int i = 0; i < n; ++i) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                int t = nums[i] + nums[j] + nums[k];
                if (t == target) {
                    return t;
                }
                if (Math.Abs(t - target) < Math.Abs(ans - target)) {
                    ans = t;
                }
                if (t > target) {
                    --k;
                } else {
                    ++j;
                }
            }
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param int[] $nums
     * @param int $target
     * @return int
     */

    function threeSumClosest($nums, $target) {
        $n = count($nums);
        $closestSum = $nums[0] + $nums[1] + $nums[2];
        $minDiff = abs($closestSum - $target);

        sort($nums);

        for ($i = 0; $i < $n - 2; $i++) {
            $left = $i + 1;
            $right = $n - 1;

            while ($left < $right) {
                $sum = $nums[$i] + $nums[$left] + $nums[$right];
                $diff = abs($sum - $target);

                if ($diff < $minDiff) {
                    $minDiff = $diff;
                    $closestSum = $sum;
                } elseif ($sum < $target) {
                    $left++;
                } elseif ($sum > $target) {
                    $right--;
                } else {
                    return $sum;
                }
            }
        }

        return $closestSum;
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int cmp(const void* a, const void* b) {
    return (*(int*) a - *(int*) b);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int ans = 1 << 30;
    for (int i = 0; i < numsSize; ++i) {
        int j = i + 1, k = numsSize - 1;
        while (j < k) {
            int t = nums[i] + nums[j] + nums[k];
            if (t == target) {
                return t;
            }
            if (abs(t - target) < abs(ans - target)) {
                ans = t;
            }
            if (t > target) {
                --k;
            } else {
                ++j;
            }
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

<p>给你一个长度为 <code>n</code> 的整数数组&nbsp;<code>nums</code><em>&nbsp;</em>和 一个目标值&nbsp;<code>target</code>。请你从 <code>nums</code><em> </em>中选出三个整数，使它们的和与&nbsp;<code>target</code>&nbsp;最接近。</p>

<p>返回这三个数的和。</p>

<p>假定每组输入只存在恰好一个解。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [-1,2,1,-4], target = 1
<strong>输出：</strong>2
<strong>解释：</strong>与 target 最接近的和是 2 (-1 + 2 + 1 = 2)。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,0,0], target = 1
<strong>输出：</strong>0
<strong>解释：</strong>与 target 最接近的和是 0（0 + 0 + 0 = 0）。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>-1000 &lt;= nums[i] &lt;= 1000</code></li>
	<li><code>-10<sup>4</sup> &lt;= target &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 双指针

我们将数组排序，然后遍历数组，对于每个元素 $nums[i]$，我们使用指针 $j$ 和 $k$ 分别指向 $i+1$ 和 $n-1$，计算三数之和，如果三数之和等于 $target$，则直接返回 $target$，否则根据与 $target$ 的差值更新答案。如果三数之和大于 $target$，则将 $k$ 向左移动一位，否则将 $j$ 向右移动一位。

时间复杂度 $O(n^2)$，空间复杂度 $O(\log n)$。其中 $n$ 为数组长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        n = len(nums)
        ans = inf
        for i, v in enumerate(nums):
            j, k = i + 1, n - 1
            while j < k:
                t = v + nums[j] + nums[k]
                if t == target:
                    return t
                if abs(t - target) < abs(ans - target):
                    ans = t
                if t > target:
                    k -= 1
                else:
                    j += 1
        return ans
```

#### Java

```java
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int ans = 1 << 30;
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                int t = nums[i] + nums[j] + nums[k];
                if (t == target) {
                    return t;
                }
                if (Math.abs(t - target) < Math.abs(ans - target)) {
                    ans = t;
                }
                if (t > target) {
                    --k;
                } else {
                    ++j;
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
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 1 << 30;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                int t = nums[i] + nums[j] + nums[k];
                if (t == target) return t;
                if (abs(t - target) < abs(ans - target)) ans = t;
                if (t > target)
                    --k;
                else
                    ++j;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func threeSumClosest(nums []int, target int) int {
	sort.Ints(nums)
	ans := 1 << 30
	n := len(nums)
	for i, v := range nums {
		j, k := i+1, n-1
		for j < k {
			t := v + nums[j] + nums[k]
			if t == target {
				return t
			}
			if abs(t-target) < abs(ans-target) {
				ans = t
			}
			if t > target {
				k--
			} else {
				j++
			}
		}
	}
	return ans
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
function threeSumClosest(nums: number[], target: number): number {
    nums.sort((a, b) => a - b);
    let ans: number = 1 << 30;
    const n = nums.length;
    for (let i = 0; i < n; ++i) {
        let j = i + 1;
        let k = n - 1;
        while (j < k) {
            const t: number = nums[i] + nums[j] + nums[k];
            if (t === target) {
                return t;
            }
            if (Math.abs(t - target) < Math.abs(ans - target)) {
                ans = t;
            }
            if (t > target) {
                --k;
            } else {
                ++j;
            }
        }
    }
    return ans;
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var threeSumClosest = function (nums, target) {
    nums.sort((a, b) => a - b);
    let ans = 1 << 30;
    const n = nums.length;
    for (let i = 0; i < n; ++i) {
        let j = i + 1;
        let k = n - 1;
        while (j < k) {
            const t = nums[i] + nums[j] + nums[k];
            if (t === target) {
                return t;
            }
            if (Math.abs(t - target) < Math.abs(ans - target)) {
                ans = t;
            }
            if (t > target) {
                --k;
            } else {
                ++j;
            }
        }
    }
    return ans;
};
```

#### C#

```cs
public class Solution {
    public int ThreeSumClosest(int[] nums, int target) {
        Array.Sort(nums);
        int ans = 1 << 30;
        int n = nums.Length;
        for (int i = 0; i < n; ++i) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                int t = nums[i] + nums[j] + nums[k];
                if (t == target) {
                    return t;
                }
                if (Math.Abs(t - target) < Math.Abs(ans - target)) {
                    ans = t;
                }
                if (t > target) {
                    --k;
                } else {
                    ++j;
                }
            }
        }
        return ans;
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param int[] $nums
     * @param int $target
     * @return int
     */

    function threeSumClosest($nums, $target) {
        $n = count($nums);
        $closestSum = $nums[0] + $nums[1] + $nums[2];
        $minDiff = abs($closestSum - $target);

        sort($nums);

        for ($i = 0; $i < $n - 2; $i++) {
            $left = $i + 1;
            $right = $n - 1;

            while ($left < $right) {
                $sum = $nums[$i] + $nums[$left] + $nums[$right];
                $diff = abs($sum - $target);

                if ($diff < $minDiff) {
                    $minDiff = $diff;
                    $closestSum = $sum;
                } elseif ($sum < $target) {
                    $left++;
                } elseif ($sum > $target) {
                    $right--;
                } else {
                    return $sum;
                }
            }
        }

        return $closestSum;
    }
}
```

#### C

```c
int cmp(const void* a, const void* b) {
    return (*(int*) a - *(int*) b);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int ans = 1 << 30;
    for (int i = 0; i < numsSize; ++i) {
        int j = i + 1, k = numsSize - 1;
        while (j < k) {
            int t = nums[i] + nums[j] + nums[k];
            if (t == target) {
                return t;
            }
            if (abs(t - target) < abs(ans - target)) {
                ans = t;
            }
            if (t > target) {
                --k;
            } else {
                ++j;
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

# [17. 电话号码的字母组合](https://leetcode.cn/problems/letter-combinations-of-a-phone-number){#17}

{{< tabs "17" >}}

{{% tab "python" %}}
```python
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        def dfs(i: int):
            if i >= len(digits):
                ans.append("".join(t))
                return
            for c in d[int(digits[i]) - 2]:
                t.append(c)
                dfs(i + 1)
                t.pop()

        if not digits:
            return []
        d = ["abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        ans = []
        t = []
        dfs(0)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private final String[] d = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    private String digits;
    private List<String> ans = new ArrayList<>();
    private StringBuilder t = new StringBuilder();

    public List<String> letterCombinations(String digits) {
        if (digits.length() == 0) {
            return ans;
        }
        this.digits = digits;
        dfs(0);
        return ans;
    }

    private void dfs(int i) {
        if (i >= digits.length()) {
            ans.add(t.toString());
            return;
        }
        String s = d[digits.charAt(i) - '2'];
        for (char c : s.toCharArray()) {
            t.append(c);
            dfs(i + 1);
            t.deleteCharAt(t.length() - 1);
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        vector<string> d = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string t;
        function<void(int)> dfs = [&](int i) {
            if (i >= digits.size()) {
                ans.push_back(t);
                return;
            }
            for (auto& c : d[digits[i] - '2']) {
                t.push_back(c);
                dfs(i + 1);
                t.pop_back();
            }
        };
        dfs(0);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func letterCombinations(digits string) (ans []string) {
	d := []string{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}
	t := []rune{}
	var dfs func(int)
	dfs = func(i int) {
		if i >= len(digits) {
			ans = append(ans, string(t))
			return
		}
		for _, c := range d[digits[i]-'2'] {
			t = append(t, c)
			dfs(i + 1)
			t = t[:len(t)-1]
		}
	}
	if len(digits) == 0 {
		return
	}
	dfs(0)
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function letterCombinations(digits: string): string[] {
    if (digits.length === 0) {
        return [];
    }
    const ans: string[] = [];
    const t: string[] = [];
    const d = ['abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz'];
    const dfs = (i: number) => {
        if (i >= digits.length) {
            ans.push(t.join(''));
            return;
        }
        const s = d[+digits[i] - 2];
        for (const c of s) {
            t.push(c);
            dfs(i + 1);
            t.pop();
        }
    };
    dfs(0);
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn letter_combinations(digits: String) -> Vec<String> {
        let d = ["abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"];
        let mut ans = Vec::new();
        let mut t = String::new();
        if digits.is_empty() {
            return ans;
        }
        Solution::dfs(&digits, &d, &mut t, &mut ans, 0);
        ans
    }

    fn dfs(digits: &String, d: &[&str; 8], t: &mut String, ans: &mut Vec<String>, i: usize) {
        if i >= digits.len() {
            ans.push(t.clone());
            return;
        }
        let s = d[((digits.chars().nth(i).unwrap() as u8) - b'2') as usize];
        for c in s.chars() {
            t.push(c);
            Solution::dfs(digits, d, t, ans, i + 1);
            t.pop();
        }
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function (digits) {
    if (digits.length === 0) {
        return [];
    }
    const ans = [];
    const t = [];
    const d = ['abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz'];
    const dfs = i => {
        if (i >= digits.length) {
            ans.push(t.join(''));
            return;
        }
        const s = d[+digits[i] - 2];
        for (const c of s) {
            t.push(c);
            dfs(i + 1);
            t.pop();
        }
    };
    dfs(0);
    return ans;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    private readonly string[] d = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    private string digits;
    private List<string> ans = new List<string>();
    private System.Text.StringBuilder t = new System.Text.StringBuilder();

    public IList<string> LetterCombinations(string digits) {
        if (digits.Length == 0) {
            return ans;
        }
        this.digits = digits;
        Dfs(0);
        return ans;
    }

    private void Dfs(int i) {
        if (i >= digits.Length) {
            ans.Add(t.ToString());
            return;
        }
        string s = d[digits[i] - '2'];
        foreach (char c in s) {
            t.Append(c);
            Dfs(i + 1);
            t.Remove(t.Length - 1, 1);
        }
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param string $digits
     * @return string[]
     */

    function letterCombinations($digits) {
        $digitMap = [
            '2' => ['a', 'b', 'c'],
            '3' => ['d', 'e', 'f'],
            '4' => ['g', 'h', 'i'],
            '5' => ['j', 'k', 'l'],
            '6' => ['m', 'n', 'o'],
            '7' => ['p', 'q', 'r', 's'],
            '8' => ['t', 'u', 'v'],
            '9' => ['w', 'x', 'y', 'z'],
        ];

        $combinations = [];

        backtrack($digits, '', 0, $digitMap, $combinations);

        return $combinations;
    }

    function backtrack($digits, $current, $index, $digitMap, &$combinations) {
        if ($index === strlen($digits)) {
            if ($current !== '') {
                $combinations[] = $current;
            }
            return;
        }

        $digit = $digits[$index];
        $letters = $digitMap[$digit];

        foreach ($letters as $letter) {
            backtrack($digits, $current . $letter, $index + 1, $digitMap, $combinations);
        }
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
char* d[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

char** letterCombinations(char* digits, int* returnSize) {
    if (!*digits) {
        *returnSize = 0;
        return NULL;
    }

    int size = 1;
    char** ans = (char**) malloc(sizeof(char*));
    ans[0] = strdup("");

    for (int x = 0; digits[x]; ++x) {
        char* s = d[digits[x] - '2'];
        int len = strlen(s);
        char** t = (char**) malloc(sizeof(char*) * size * len);
        int tSize = 0;

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < len; ++j) {
                int oldLen = strlen(ans[i]);
                char* tmp = (char*) malloc(oldLen + 2);
                strcpy(tmp, ans[i]);
                tmp[oldLen] = s[j];
                tmp[oldLen + 1] = '\0';
                t[tSize++] = tmp;
            }
            free(ans[i]);
        }
        free(ans);
        ans = t;
        size = tSize;
    }

    *returnSize = size;
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个仅包含数字&nbsp;<code>2-9</code>&nbsp;的字符串，返回所有它能表示的字母组合。答案可以按 <strong>任意顺序</strong> 返回。</p>

<p>给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。</p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0000-0099/0017.Letter%20Combinations%20of%20a%20Phone%20Number/images/1752723054-mfIHZs-image.png" style="width: 200px;" /></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>digits = "23"
<strong>输出：</strong>["ad","ae","af","bd","be","bf","cd","ce","cf"]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>digits = ""
<strong>输出：</strong>[]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>digits = "2"
<strong>输出：</strong>["a","b","c"]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= digits.length &lt;= 4</code></li>
	<li><code>digits[i]</code> 是范围 <code>['2', '9']</code> 的一个数字。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：遍历

我们先用一个数组或者哈希表存储每个数字对应的字母，然后遍历每个数字，将其对应的字母与之前的结果进行组合，得到新的结果。

时间复杂度 $O(4^n)$。空间复杂度 $O(4^n)$。其中 $n$ 是输入数字的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        d = ["abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        ans = [""]
        for i in digits:
            s = d[int(i) - 2]
            ans = [a + b for a in ans for b in s]
        return ans
```

#### Java

```java
class Solution {
    public List<String> letterCombinations(String digits) {
        List<String> ans = new ArrayList<>();
        if (digits.length() == 0) {
            return ans;
        }
        ans.add("");
        String[] d = new String[] {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for (char i : digits.toCharArray()) {
            String s = d[i - '2'];
            List<String> t = new ArrayList<>();
            for (String a : ans) {
                for (String b : s.split("")) {
                    t.add(a + b);
                }
            }
            ans = t;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        vector<string> d = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans = {""};
        for (auto& i : digits) {
            string s = d[i - '2'];
            vector<string> t;
            for (auto& a : ans) {
                for (auto& b : s) {
                    t.push_back(a + b);
                }
            }
            ans = move(t);
        }
        return ans;
    }
};
```

#### Go

```go
func letterCombinations(digits string) []string {
	ans := []string{}
	if len(digits) == 0 {
		return ans
	}
	ans = append(ans, "")
	d := []string{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}
	for _, i := range digits {
		s := d[i-'2']
		t := []string{}
		for _, a := range ans {
			for _, b := range s {
				t = append(t, a+string(b))
			}
		}
		ans = t
	}
	return ans
}
```

#### TypeScript

```ts
function letterCombinations(digits: string): string[] {
    if (digits.length === 0) {
        return [];
    }
    const ans: string[] = [''];
    const d = ['abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz'];
    for (const i of digits) {
        const s = d[+i - 2];
        const t: string[] = [];
        for (const a of ans) {
            for (const b of s) {
                t.push(a + b);
            }
        }
        ans.splice(0, ans.length, ...t);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn letter_combinations(digits: String) -> Vec<String> {
        let mut ans: Vec<String> = Vec::new();
        if digits.is_empty() {
            return ans;
        }
        ans.push("".to_string());
        let d = ["abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"];
        for i in digits.chars() {
            let s = &d[((i as u8) - b'2') as usize];
            let mut t: Vec<String> = Vec::new();
            for a in &ans {
                for b in s.chars() {
                    t.push(format!("{}{}", a, b));
                }
            }
            ans = t;
        }
        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function (digits) {
    if (digits.length === 0) {
        return [];
    }
    const ans = [''];
    const d = ['abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz'];
    for (const i of digits) {
        const s = d[+i - 2];
        const t = [];
        for (const a of ans) {
            for (const b of s) {
                t.push(a + b);
            }
        }
        ans.splice(0, ans.length, ...t);
    }
    return ans;
};
```

#### C#

```cs
public class Solution {
    public IList<string> LetterCombinations(string digits) {
        var ans = new List<string>();
        if (digits.Length == 0) {
            return ans;
        }
        ans.Add("");
        string[] d = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        foreach (char i in digits) {
            string s = d[i - '2'];
            var t = new List<string>();
            foreach (string a in ans) {
                foreach (char b in s) {
                    t.Add(a + b);
                }
            }
            ans = t;
        }
        return ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：DFS

我们可以使用深度优先搜索的方法，枚举所有可能的字母组合。假设当前已经产生了一部分字母组合，但是还有一些数字没有被穷举到，此时我们取出下一个数字所对应的字母，然后依次枚举这个数字所对应的每一个字母，将它们添加到前面已经产生的字母组合后面，形成所有可能的组合。

时间复杂度 $O(4^n)$。空间复杂度 $O(n)$。其中 $n$ 是输入数字的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        def dfs(i: int):
            if i >= len(digits):
                ans.append("".join(t))
                return
            for c in d[int(digits[i]) - 2]:
                t.append(c)
                dfs(i + 1)
                t.pop()

        if not digits:
            return []
        d = ["abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        ans = []
        t = []
        dfs(0)
        return ans
```

#### Java

```java
class Solution {
    private final String[] d = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    private String digits;
    private List<String> ans = new ArrayList<>();
    private StringBuilder t = new StringBuilder();

    public List<String> letterCombinations(String digits) {
        if (digits.length() == 0) {
            return ans;
        }
        this.digits = digits;
        dfs(0);
        return ans;
    }

    private void dfs(int i) {
        if (i >= digits.length()) {
            ans.add(t.toString());
            return;
        }
        String s = d[digits.charAt(i) - '2'];
        for (char c : s.toCharArray()) {
            t.append(c);
            dfs(i + 1);
            t.deleteCharAt(t.length() - 1);
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        vector<string> d = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string t;
        function<void(int)> dfs = [&](int i) {
            if (i >= digits.size()) {
                ans.push_back(t);
                return;
            }
            for (auto& c : d[digits[i] - '2']) {
                t.push_back(c);
                dfs(i + 1);
                t.pop_back();
            }
        };
        dfs(0);
        return ans;
    }
};
```

#### Go

```go
func letterCombinations(digits string) (ans []string) {
	d := []string{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}
	t := []rune{}
	var dfs func(int)
	dfs = func(i int) {
		if i >= len(digits) {
			ans = append(ans, string(t))
			return
		}
		for _, c := range d[digits[i]-'2'] {
			t = append(t, c)
			dfs(i + 1)
			t = t[:len(t)-1]
		}
	}
	if len(digits) == 0 {
		return
	}
	dfs(0)
	return
}
```

#### TypeScript

```ts
function letterCombinations(digits: string): string[] {
    if (digits.length === 0) {
        return [];
    }
    const ans: string[] = [];
    const t: string[] = [];
    const d = ['abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz'];
    const dfs = (i: number) => {
        if (i >= digits.length) {
            ans.push(t.join(''));
            return;
        }
        const s = d[+digits[i] - 2];
        for (const c of s) {
            t.push(c);
            dfs(i + 1);
            t.pop();
        }
    };
    dfs(0);
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn letter_combinations(digits: String) -> Vec<String> {
        let d = ["abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"];
        let mut ans = Vec::new();
        let mut t = String::new();
        if digits.is_empty() {
            return ans;
        }
        Solution::dfs(&digits, &d, &mut t, &mut ans, 0);
        ans
    }

    fn dfs(digits: &String, d: &[&str; 8], t: &mut String, ans: &mut Vec<String>, i: usize) {
        if i >= digits.len() {
            ans.push(t.clone());
            return;
        }
        let s = d[((digits.chars().nth(i).unwrap() as u8) - b'2') as usize];
        for c in s.chars() {
            t.push(c);
            Solution::dfs(digits, d, t, ans, i + 1);
            t.pop();
        }
    }
}
```

#### JavaScript

```js
/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function (digits) {
    if (digits.length === 0) {
        return [];
    }
    const ans = [];
    const t = [];
    const d = ['abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz'];
    const dfs = i => {
        if (i >= digits.length) {
            ans.push(t.join(''));
            return;
        }
        const s = d[+digits[i] - 2];
        for (const c of s) {
            t.push(c);
            dfs(i + 1);
            t.pop();
        }
    };
    dfs(0);
    return ans;
};
```

#### C#

```cs
public class Solution {
    private readonly string[] d = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    private string digits;
    private List<string> ans = new List<string>();
    private System.Text.StringBuilder t = new System.Text.StringBuilder();

    public IList<string> LetterCombinations(string digits) {
        if (digits.Length == 0) {
            return ans;
        }
        this.digits = digits;
        Dfs(0);
        return ans;
    }

    private void Dfs(int i) {
        if (i >= digits.Length) {
            ans.Add(t.ToString());
            return;
        }
        string s = d[digits[i] - '2'];
        foreach (char c in s) {
            t.Append(c);
            Dfs(i + 1);
            t.Remove(t.Length - 1, 1);
        }
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param string $digits
     * @return string[]
     */

    function letterCombinations($digits) {
        $digitMap = [
            '2' => ['a', 'b', 'c'],
            '3' => ['d', 'e', 'f'],
            '4' => ['g', 'h', 'i'],
            '5' => ['j', 'k', 'l'],
            '6' => ['m', 'n', 'o'],
            '7' => ['p', 'q', 'r', 's'],
            '8' => ['t', 'u', 'v'],
            '9' => ['w', 'x', 'y', 'z'],
        ];

        $combinations = [];

        backtrack($digits, '', 0, $digitMap, $combinations);

        return $combinations;
    }

    function backtrack($digits, $current, $index, $digitMap, &$combinations) {
        if ($index === strlen($digits)) {
            if ($current !== '') {
                $combinations[] = $current;
            }
            return;
        }

        $digit = $digits[$index];
        $letters = $digitMap[$digit];

        foreach ($letters as $letter) {
            backtrack($digits, $current . $letter, $index + 1, $digitMap, $combinations);
        }
    }
}
```

#### C

```c
char* d[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

char** letterCombinations(char* digits, int* returnSize) {
    if (!*digits) {
        *returnSize = 0;
        return NULL;
    }

    int size = 1;
    char** ans = (char**) malloc(sizeof(char*));
    ans[0] = strdup("");

    for (int x = 0; digits[x]; ++x) {
        char* s = d[digits[x] - '2'];
        int len = strlen(s);
        char** t = (char**) malloc(sizeof(char*) * size * len);
        int tSize = 0;

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < len; ++j) {
                int oldLen = strlen(ans[i]);
                char* tmp = (char*) malloc(oldLen + 2);
                strcpy(tmp, ans[i]);
                tmp[oldLen] = s[j];
                tmp[oldLen + 1] = '\0';
                t[tSize++] = tmp;
            }
            free(ans[i]);
        }
        free(ans);
        ans = t;
        size = tSize;
    }

    *returnSize = size;
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [18. 四数之和](https://leetcode.cn/problems/4sum){#18}

{{< tabs "18" >}}

{{% tab "python" %}}
```python
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        n = len(nums)
        ans = []
        if n < 4:
            return ans
        nums.sort()
        for i in range(n - 3):
            if i and nums[i] == nums[i - 1]:
                continue
            for j in range(i + 1, n - 2):
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue
                k, l = j + 1, n - 1
                while k < l:
                    x = nums[i] + nums[j] + nums[k] + nums[l]
                    if x < target:
                        k += 1
                    elif x > target:
                        l -= 1
                    else:
                        ans.append([nums[i], nums[j], nums[k], nums[l]])
                        k, l = k + 1, l - 1
                        while k < l and nums[k] == nums[k - 1]:
                            k += 1
                        while k < l and nums[l] == nums[l + 1]:
                            l -= 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        int n = nums.length;
        List<List<Integer>> ans = new ArrayList<>();
        if (n < 4) {
            return ans;
        }
        Arrays.sort(nums);
        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int k = j + 1, l = n - 1;
                while (k < l) {
                    long x = (long) nums[i] + nums[j] + nums[k] + nums[l];
                    if (x < target) {
                        ++k;
                    } else if (x > target) {
                        --l;
                    } else {
                        ans.add(List.of(nums[i], nums[j], nums[k++], nums[l--]));
                        while (k < l && nums[k] == nums[k - 1]) {
                            ++k;
                        }
                        while (k < l && nums[l] == nums[l + 1]) {
                            --l;
                        }
                    }
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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        if (n < 4) {
            return ans;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; ++i) {
            if (i && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int k = j + 1, l = n - 1;
                while (k < l) {
                    long long x = (long long) nums[i] + nums[j] + nums[k] + nums[l];
                    if (x < target) {
                        ++k;
                    } else if (x > target) {
                        --l;
                    } else {
                        ans.push_back({nums[i], nums[j], nums[k++], nums[l--]});
                        while (k < l && nums[k] == nums[k - 1]) {
                            ++k;
                        }
                        while (k < l && nums[l] == nums[l + 1]) {
                            --l;
                        }
                    }
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
func fourSum(nums []int, target int) (ans [][]int) {
	n := len(nums)
	if n < 4 {
		return
	}
	sort.Ints(nums)
	for i := 0; i < n-3; i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		for j := i + 1; j < n-2; j++ {
			if j > i+1 && nums[j] == nums[j-1] {
				continue
			}
			k, l := j+1, n-1
			for k < l {
				x := nums[i] + nums[j] + nums[k] + nums[l]
				if x < target {
					k++
				} else if x > target {
					l--
				} else {
					ans = append(ans, []int{nums[i], nums[j], nums[k], nums[l]})
					k++
					l--
					for k < l && nums[k] == nums[k-1] {
						k++
					}
					for k < l && nums[l] == nums[l+1] {
						l--
					}
				}
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function fourSum(nums: number[], target: number): number[][] {
    const n = nums.length;
    const ans: number[][] = [];
    if (n < 4) {
        return ans;
    }
    nums.sort((a, b) => a - b);
    for (let i = 0; i < n - 3; ++i) {
        if (i > 0 && nums[i] === nums[i - 1]) {
            continue;
        }
        for (let j = i + 1; j < n - 2; ++j) {
            if (j > i + 1 && nums[j] === nums[j - 1]) {
                continue;
            }
            let [k, l] = [j + 1, n - 1];
            while (k < l) {
                const x = nums[i] + nums[j] + nums[k] + nums[l];
                if (x < target) {
                    ++k;
                } else if (x > target) {
                    --l;
                } else {
                    ans.push([nums[i], nums[j], nums[k++], nums[l--]]);
                    while (k < l && nums[k] === nums[k - 1]) {
                        ++k;
                    }
                    while (k < l && nums[l] === nums[l + 1]) {
                        --l;
                    }
                }
            }
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[][]}
 */
var fourSum = function (nums, target) {
    const n = nums.length;
    const ans = [];
    if (n < 4) {
        return ans;
    }
    nums.sort((a, b) => a - b);
    for (let i = 0; i < n - 3; ++i) {
        if (i > 0 && nums[i] === nums[i - 1]) {
            continue;
        }
        for (let j = i + 1; j < n - 2; ++j) {
            if (j > i + 1 && nums[j] === nums[j - 1]) {
                continue;
            }
            let [k, l] = [j + 1, n - 1];
            while (k < l) {
                const x = nums[i] + nums[j] + nums[k] + nums[l];
                if (x < target) {
                    ++k;
                } else if (x > target) {
                    --l;
                } else {
                    ans.push([nums[i], nums[j], nums[k++], nums[l--]]);
                    while (k < l && nums[k] === nums[k - 1]) {
                        ++k;
                    }
                    while (k < l && nums[l] === nums[l + 1]) {
                        --l;
                    }
                }
            }
        }
    }
    return ans;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public IList<IList<int>> FourSum(int[] nums, int target) {
        int n = nums.Length;
        var ans = new List<IList<int>>();
        if (n < 4) {
            return ans;
        }
        Array.Sort(nums);
        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int k = j + 1, l = n - 1;
                while (k < l) {
                    long x = (long) nums[i] + nums[j] + nums[k] + nums[l];
                    if (x < target) {
                        ++k;
                    } else if (x > target) {
                        --l;
                    } else {
                        ans.Add(new List<int> {nums[i], nums[j], nums[k++], nums[l--]});
                        while (k < l && nums[k] == nums[k - 1]) {
                            ++k;
                        }
                        while (k < l && nums[l] == nums[l + 1]) {
                            --l;
                        }
                    }
                }
            }
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param int[] $nums
     * @param int $target
     * @return int[][]
     */

    function fourSum($nums, $target) {
        $result = [];
        $n = count($nums);

        sort($nums);

        for ($i = 0; $i < $n - 3; $i++) {
            if ($i > 0 && $nums[$i] === $nums[$i - 1]) {
                continue;
            }

            for ($j = $i + 1; $j < $n - 2; $j++) {
                if ($j > $i + 1 && $nums[$j] === $nums[$j - 1]) {
                    continue;
                }

                $left = $j + 1;
                $right = $n - 1;

                while ($left < $right) {
                    $sum = $nums[$i] + $nums[$j] + $nums[$left] + $nums[$right];

                    if ($sum === $target) {
                        $result[] = [$nums[$i], $nums[$j], $nums[$left], $nums[$right]];

                        while ($left < $right && $nums[$left] === $nums[$left + 1]) {
                            $left++;
                        }

                        while ($left < $right && $nums[$right] === $nums[$right - 1]) {
                            $right--;
                        }

                        $left++;
                        $right--;
                    } elseif ($sum < $target) {
                        $left++;
                    } else {
                        $right--;
                    }
                }
            }
        }
        return $result;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个由 <code>n</code> 个整数组成的数组&nbsp;<code>nums</code> ，和一个目标值 <code>target</code> 。请你找出并返回满足下述全部条件且<strong>不重复</strong>的四元组&nbsp;<code>[nums[a], nums[b], nums[c], nums[d]]</code>&nbsp;（若两个四元组元素一一对应，则认为两个四元组重复）：</p>

<ul>
	<li><code>0 &lt;= a, b, c, d&nbsp;&lt; n</code></li>
	<li><code>a</code>、<code>b</code>、<code>c</code> 和 <code>d</code> <strong>互不相同</strong></li>
	<li><code>nums[a] + nums[b] + nums[c] + nums[d] == target</code></li>
</ul>

<p>你可以按 <strong>任意顺序</strong> 返回答案 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,0,-1,0,-2,2], target = 0
<strong>输出：</strong>[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,2,2,2,2], target = 8
<strong>输出：</strong>[[2,2,2,2]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 200</code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= target &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 双指针

我们注意到，题目中要求找到不重复的四元组，那么我们可以先对数组进行排序，这样就可以方便地跳过重复的元素。

接下来，我们枚举四元组的前两个元素 $nums[i]$ 和 $nums[j]$，其中 $i \lt j$，在枚举的过程中，我们跳过重复的 $nums[i]$ 和 $nums[j]$。然后，我们用两个指针 $k$ 和 $l$ 分别指向 $nums[i]$ 和 $nums[j]$ 后面的两端，令 $x = nums[i] + nums[j] + nums[k] + nums[l]$，我们将 $x$ 与 $target$ 比较，进行如下操作：

-   如果 $x \lt target$，则更新 $k = k + 1$ 以得到更大的 $x$；
-   如果 $x \gt target$，则更新 $l = l - 1$ 以得到更小的 $x$；
-   否则，说明找到了一个四元组 $(nums[i], nums[j], nums[k], nums[l])$，将其加入答案，然后我们更新指针 $k$ 和 $l$，并跳过所有重复的元素，防止答案中包含重复的四元组，继续寻找下一个四元组。

时间复杂度为 $O(n^3)$，空间复杂度为 $O(\log n)$，其中 $n$ 是数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        n = len(nums)
        ans = []
        if n < 4:
            return ans
        nums.sort()
        for i in range(n - 3):
            if i and nums[i] == nums[i - 1]:
                continue
            for j in range(i + 1, n - 2):
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue
                k, l = j + 1, n - 1
                while k < l:
                    x = nums[i] + nums[j] + nums[k] + nums[l]
                    if x < target:
                        k += 1
                    elif x > target:
                        l -= 1
                    else:
                        ans.append([nums[i], nums[j], nums[k], nums[l]])
                        k, l = k + 1, l - 1
                        while k < l and nums[k] == nums[k - 1]:
                            k += 1
                        while k < l and nums[l] == nums[l + 1]:
                            l -= 1
        return ans
```

#### Java

```java
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        int n = nums.length;
        List<List<Integer>> ans = new ArrayList<>();
        if (n < 4) {
            return ans;
        }
        Arrays.sort(nums);
        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int k = j + 1, l = n - 1;
                while (k < l) {
                    long x = (long) nums[i] + nums[j] + nums[k] + nums[l];
                    if (x < target) {
                        ++k;
                    } else if (x > target) {
                        --l;
                    } else {
                        ans.add(List.of(nums[i], nums[j], nums[k++], nums[l--]));
                        while (k < l && nums[k] == nums[k - 1]) {
                            ++k;
                        }
                        while (k < l && nums[l] == nums[l + 1]) {
                            --l;
                        }
                    }
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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        if (n < 4) {
            return ans;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; ++i) {
            if (i && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int k = j + 1, l = n - 1;
                while (k < l) {
                    long long x = (long long) nums[i] + nums[j] + nums[k] + nums[l];
                    if (x < target) {
                        ++k;
                    } else if (x > target) {
                        --l;
                    } else {
                        ans.push_back({nums[i], nums[j], nums[k++], nums[l--]});
                        while (k < l && nums[k] == nums[k - 1]) {
                            ++k;
                        }
                        while (k < l && nums[l] == nums[l + 1]) {
                            --l;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func fourSum(nums []int, target int) (ans [][]int) {
	n := len(nums)
	if n < 4 {
		return
	}
	sort.Ints(nums)
	for i := 0; i < n-3; i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		for j := i + 1; j < n-2; j++ {
			if j > i+1 && nums[j] == nums[j-1] {
				continue
			}
			k, l := j+1, n-1
			for k < l {
				x := nums[i] + nums[j] + nums[k] + nums[l]
				if x < target {
					k++
				} else if x > target {
					l--
				} else {
					ans = append(ans, []int{nums[i], nums[j], nums[k], nums[l]})
					k++
					l--
					for k < l && nums[k] == nums[k-1] {
						k++
					}
					for k < l && nums[l] == nums[l+1] {
						l--
					}
				}
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function fourSum(nums: number[], target: number): number[][] {
    const n = nums.length;
    const ans: number[][] = [];
    if (n < 4) {
        return ans;
    }
    nums.sort((a, b) => a - b);
    for (let i = 0; i < n - 3; ++i) {
        if (i > 0 && nums[i] === nums[i - 1]) {
            continue;
        }
        for (let j = i + 1; j < n - 2; ++j) {
            if (j > i + 1 && nums[j] === nums[j - 1]) {
                continue;
            }
            let [k, l] = [j + 1, n - 1];
            while (k < l) {
                const x = nums[i] + nums[j] + nums[k] + nums[l];
                if (x < target) {
                    ++k;
                } else if (x > target) {
                    --l;
                } else {
                    ans.push([nums[i], nums[j], nums[k++], nums[l--]]);
                    while (k < l && nums[k] === nums[k - 1]) {
                        ++k;
                    }
                    while (k < l && nums[l] === nums[l + 1]) {
                        --l;
                    }
                }
            }
        }
    }
    return ans;
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[][]}
 */
var fourSum = function (nums, target) {
    const n = nums.length;
    const ans = [];
    if (n < 4) {
        return ans;
    }
    nums.sort((a, b) => a - b);
    for (let i = 0; i < n - 3; ++i) {
        if (i > 0 && nums[i] === nums[i - 1]) {
            continue;
        }
        for (let j = i + 1; j < n - 2; ++j) {
            if (j > i + 1 && nums[j] === nums[j - 1]) {
                continue;
            }
            let [k, l] = [j + 1, n - 1];
            while (k < l) {
                const x = nums[i] + nums[j] + nums[k] + nums[l];
                if (x < target) {
                    ++k;
                } else if (x > target) {
                    --l;
                } else {
                    ans.push([nums[i], nums[j], nums[k++], nums[l--]]);
                    while (k < l && nums[k] === nums[k - 1]) {
                        ++k;
                    }
                    while (k < l && nums[l] === nums[l + 1]) {
                        --l;
                    }
                }
            }
        }
    }
    return ans;
};
```

#### C#

```cs
public class Solution {
    public IList<IList<int>> FourSum(int[] nums, int target) {
        int n = nums.Length;
        var ans = new List<IList<int>>();
        if (n < 4) {
            return ans;
        }
        Array.Sort(nums);
        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int k = j + 1, l = n - 1;
                while (k < l) {
                    long x = (long) nums[i] + nums[j] + nums[k] + nums[l];
                    if (x < target) {
                        ++k;
                    } else if (x > target) {
                        --l;
                    } else {
                        ans.Add(new List<int> {nums[i], nums[j], nums[k++], nums[l--]});
                        while (k < l && nums[k] == nums[k - 1]) {
                            ++k;
                        }
                        while (k < l && nums[l] == nums[l + 1]) {
                            --l;
                        }
                    }
                }
            }
        }
        return ans;
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param int[] $nums
     * @param int $target
     * @return int[][]
     */

    function fourSum($nums, $target) {
        $result = [];
        $n = count($nums);

        sort($nums);

        for ($i = 0; $i < $n - 3; $i++) {
            if ($i > 0 && $nums[$i] === $nums[$i - 1]) {
                continue;
            }

            for ($j = $i + 1; $j < $n - 2; $j++) {
                if ($j > $i + 1 && $nums[$j] === $nums[$j - 1]) {
                    continue;
                }

                $left = $j + 1;
                $right = $n - 1;

                while ($left < $right) {
                    $sum = $nums[$i] + $nums[$j] + $nums[$left] + $nums[$right];

                    if ($sum === $target) {
                        $result[] = [$nums[$i], $nums[$j], $nums[$left], $nums[$right]];

                        while ($left < $right && $nums[$left] === $nums[$left + 1]) {
                            $left++;
                        }

                        while ($left < $right && $nums[$right] === $nums[$right - 1]) {
                            $right--;
                        }

                        $left++;
                        $right--;
                    } elseif ($sum < $target) {
                        $left++;
                    } else {
                        $right--;
                    }
                }
            }
        }
        return $result;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [19. 删除链表的倒数第 N 个结点](https://leetcode.cn/problems/remove-nth-node-from-end-of-list){#19}

{{< tabs "19" >}}

{{% tab "python" %}}
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode(next=head)
        fast = slow = dummy
        for _ in range(n):
            fast = fast.next
        while fast.next:
            slow, fast = slow.next, fast.next
        slow.next = slow.next.next
        return dummy.next
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy = new ListNode(0, head);
        ListNode fast = dummy, slow = dummy;
        while (n-- > 0) {
            fast = fast.next;
        }
        while (fast.next != null) {
            slow = slow.next;
            fast = fast.next;
        }
        slow.next = slow.next.next;
        return dummy.next;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        while (n--) {
            fast = fast->next;
        }
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {
	dummy := &ListNode{0, head}
	fast, slow := dummy, dummy
	for ; n > 0; n-- {
		fast = fast.Next
	}
	for fast.Next != nil {
		slow, fast = slow.Next, fast.Next
	}
	slow.Next = slow.Next.Next
	return dummy.Next
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function removeNthFromEnd(head: ListNode | null, n: number): ListNode | null {
    const dummy = new ListNode(0, head);
    let fast = dummy;
    let slow = dummy;
    while (n--) {
        fast = fast.next;
    }
    while (fast.next) {
        slow = slow.next;
        fast = fast.next;
    }
    slow.next = slow.next.next;
    return dummy.next;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn remove_nth_from_end(head: Option<Box<ListNode>>, n: i32) -> Option<Box<ListNode>> {
        let mut dummy = Some(Box::new(ListNode { val: 0, next: head }));
        let mut slow = &mut dummy;
        let mut fast = &slow.clone();
        for _ in 0..=n {
            fast = &fast.as_ref().unwrap().next;
        }
        while fast.is_some() {
            fast = &fast.as_ref().unwrap().next;
            slow = &mut slow.as_mut().unwrap().next;
        }
        slow.as_mut().unwrap().next = slow.as_mut().unwrap().next.as_mut().unwrap().next.take();
        dummy.unwrap().next
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function (head, n) {
    const dummy = new ListNode(0, head);
    let fast = dummy,
        slow = dummy;
    while (n--) {
        fast = fast.next;
    }
    while (fast.next) {
        slow = slow.next;
        fast = fast.next;
    }
    slow.next = slow.next.next;
    return dummy.next;
};
```
{{% /tab %}}
{{% tab "swift" %}}
```swift
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public var val: Int
 *     public var next: ListNode?
 *     public init() { self.val = 0; self.next = nil; }
 *     public init(_ val: Int) { self.val = val; self.next = nil; }
 *     public init(_ val: Int, _ next: ListNode?) { self.val = val; self.next = next; }
 * }
 */
class Solution {
    func removeNthFromEnd(_ head: ListNode?, _ n: Int) -> ListNode? {
        let dummy = ListNode(0)
        dummy.next = head
        var fast: ListNode? = dummy
        var slow: ListNode? = dummy
        for _ in 0..<n {
            fast = fast?.next
        }
        while fast?.next != nil {
            fast = fast?.next
            slow = slow?.next
        }
        slow?.next = slow?.next?.next
        return dummy.next
    }
}
```
{{% /tab %}}
{{% tab "rb" %}}
```rb
# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val = 0, _next = nil)
#         @val = val
#         @next = _next
#     end
# end
# @param {ListNode} head
# @param {Integer} n
# @return {ListNode}
def remove_nth_from_end(head, n)
    dummy = ListNode.new(0, head)
    fast = slow = dummy
    while n > 0
        fast = fast.next
        n -= 1
    end
    while fast.next
        slow = slow.next
        fast = fast.next
    end
    slow.next = slow.next.next
    return dummy.next
end
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode RemoveNthFromEnd(ListNode head, int n) {
        ListNode dummy = new ListNode(0, head);
        ListNode fast = dummy, slow = dummy;
        while (n-- > 0) {
            fast = fast.next;
        }
        while (fast.next != null) {
            slow = slow.next;
            fast = fast.next;
        }
        slow.next = slow.next.next;
        return dummy.next;
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
/**
 * Definition for a singly-linked list.
 * class ListNode {
 *     public $val = 0;
 *     public $next = null;
 *     function __construct($val = 0, $next = null) {
 *         $this->val = $val;
 *         $this->next = $next;
 *     }
 * }
 */
class Solution {
    /**
     * @param ListNode $head
     * @param Integer $n
     * @return ListNode
     */
    function removeNthFromEnd($head, $n) {
        $dummy = new ListNode(0, $head);
        $fast = $slow = $dummy;
        for ($i = 0; $i < $n; $i++) {
            $fast = $fast->next;
        }
        while ($fast->next !== null) {
            $fast = $fast->next;
            $slow = $slow->next;
        }
        $slow->next = $slow->next->next;
        return $dummy->next;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个链表，删除链表的倒数第&nbsp;<code>n</code><em>&nbsp;</em>个结点，并且返回链表的头结点。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0000-0099/0019.Remove%20Nth%20Node%20From%20End%20of%20List/images/remove_ex1.jpg" style="width: 542px; height: 222px;" />
<pre>
<strong>输入：</strong>head = [1,2,3,4,5], n = 2
<strong>输出：</strong>[1,2,3,5]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>head = [1], n = 1
<strong>输出：</strong>[]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>head = [1,2], n = 1
<strong>输出：</strong>[1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表中结点的数目为 <code>sz</code></li>
	<li><code>1 &lt;= sz &lt;= 30</code></li>
	<li><code>0 &lt;= Node.val &lt;= 100</code></li>
	<li><code>1 &lt;= n &lt;= sz</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你能尝试使用一趟扫描实现吗？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：快慢指针

我们定义两个指针 `fast` 和 `slow`，初始时都指向链表的虚拟头结点 `dummy`。

接着 `fast` 指针先向前移动 $n$ 步，然后 `fast` 和 `slow` 指针同时向前移动，直到 `fast` 指针到达链表的末尾。此时 `slow.next` 指针指向的结点就是倒数第 `n` 个结点的前驱结点，将其删除即可。

时间复杂度 $O(n)$，其中 $n$ 为链表的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode(next=head)
        fast = slow = dummy
        for _ in range(n):
            fast = fast.next
        while fast.next:
            slow, fast = slow.next, fast.next
        slow.next = slow.next.next
        return dummy.next
```

#### Java

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy = new ListNode(0, head);
        ListNode fast = dummy, slow = dummy;
        while (n-- > 0) {
            fast = fast.next;
        }
        while (fast.next != null) {
            slow = slow.next;
            fast = fast.next;
        }
        slow.next = slow.next.next;
        return dummy.next;
    }
}
```

#### C++

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        while (n--) {
            fast = fast->next;
        }
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};
```

#### Go

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {
	dummy := &ListNode{0, head}
	fast, slow := dummy, dummy
	for ; n > 0; n-- {
		fast = fast.Next
	}
	for fast.Next != nil {
		slow, fast = slow.Next, fast.Next
	}
	slow.Next = slow.Next.Next
	return dummy.Next
}
```

#### TypeScript

```ts
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function removeNthFromEnd(head: ListNode | null, n: number): ListNode | null {
    const dummy = new ListNode(0, head);
    let fast = dummy;
    let slow = dummy;
    while (n--) {
        fast = fast.next;
    }
    while (fast.next) {
        slow = slow.next;
        fast = fast.next;
    }
    slow.next = slow.next.next;
    return dummy.next;
}
```

#### Rust

```rust
// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn remove_nth_from_end(head: Option<Box<ListNode>>, n: i32) -> Option<Box<ListNode>> {
        let mut dummy = Some(Box::new(ListNode { val: 0, next: head }));
        let mut slow = &mut dummy;
        let mut fast = &slow.clone();
        for _ in 0..=n {
            fast = &fast.as_ref().unwrap().next;
        }
        while fast.is_some() {
            fast = &fast.as_ref().unwrap().next;
            slow = &mut slow.as_mut().unwrap().next;
        }
        slow.as_mut().unwrap().next = slow.as_mut().unwrap().next.as_mut().unwrap().next.take();
        dummy.unwrap().next
    }
}
```

#### JavaScript

```js
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function (head, n) {
    const dummy = new ListNode(0, head);
    let fast = dummy,
        slow = dummy;
    while (n--) {
        fast = fast.next;
    }
    while (fast.next) {
        slow = slow.next;
        fast = fast.next;
    }
    slow.next = slow.next.next;
    return dummy.next;
};
```

#### Swift

```swift
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public var val: Int
 *     public var next: ListNode?
 *     public init() { self.val = 0; self.next = nil; }
 *     public init(_ val: Int) { self.val = val; self.next = nil; }
 *     public init(_ val: Int, _ next: ListNode?) { self.val = val; self.next = next; }
 * }
 */
class Solution {
    func removeNthFromEnd(_ head: ListNode?, _ n: Int) -> ListNode? {
        let dummy = ListNode(0)
        dummy.next = head
        var fast: ListNode? = dummy
        var slow: ListNode? = dummy
        for _ in 0..<n {
            fast = fast?.next
        }
        while fast?.next != nil {
            fast = fast?.next
            slow = slow?.next
        }
        slow?.next = slow?.next?.next
        return dummy.next
    }
}
```

#### Ruby

```rb
# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val = 0, _next = nil)
#         @val = val
#         @next = _next
#     end
# end
# @param {ListNode} head
# @param {Integer} n
# @return {ListNode}
def remove_nth_from_end(head, n)
    dummy = ListNode.new(0, head)
    fast = slow = dummy
    while n > 0
        fast = fast.next
        n -= 1
    end
    while fast.next
        slow = slow.next
        fast = fast.next
    end
    slow.next = slow.next.next
    return dummy.next
end
```

#### C#

```cs
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode RemoveNthFromEnd(ListNode head, int n) {
        ListNode dummy = new ListNode(0, head);
        ListNode fast = dummy, slow = dummy;
        while (n-- > 0) {
            fast = fast.next;
        }
        while (fast.next != null) {
            slow = slow.next;
            fast = fast.next;
        }
        slow.next = slow.next.next;
        return dummy.next;
    }
}
```

#### PHP

```php
/**
 * Definition for a singly-linked list.
 * class ListNode {
 *     public $val = 0;
 *     public $next = null;
 *     function __construct($val = 0, $next = null) {
 *         $this->val = $val;
 *         $this->next = $next;
 *     }
 * }
 */
class Solution {
    /**
     * @param ListNode $head
     * @param Integer $n
     * @return ListNode
     */
    function removeNthFromEnd($head, $n) {
        $dummy = new ListNode(0, $head);
        $fast = $slow = $dummy;
        for ($i = 0; $i < $n; $i++) {
            $fast = $fast->next;
        }
        while ($fast->next !== null) {
            $fast = $fast->next;
            $slow = $slow->next;
        }
        $slow->next = $slow->next->next;
        return $dummy->next;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [20. 有效的括号](https://leetcode.cn/problems/valid-parentheses){#20}

{{< tabs "20" >}}

{{% tab "python" %}}
```python
class Solution:
    def isValid(self, s: str) -> bool:
        stk = []
        d = {'()', '[]', '{}'}
        for c in s:
            if c in '({[':
                stk.append(c)
            elif not stk or stk.pop() + c not in d:
                return False
        return not stk
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isValid(String s) {
        Deque<Character> stk = new ArrayDeque<>();
        for (char c : s.toCharArray()) {
            if (c == '(' || c == '{' || c == '[') {
                stk.push(c);
            } else if (stk.isEmpty() || !match(stk.pop(), c)) {
                return false;
            }
        }
        return stk.isEmpty();
    }

    private boolean match(char l, char r) {
        return (l == '(' && r == ')') || (l == '{' && r == '}') || (l == '[' && r == ']');
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool isValid(string s) {
        string stk;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[')
                stk.push_back(c);
            else if (stk.empty() || !match(stk.back(), c))
                return false;
            else
                stk.pop_back();
        }
        return stk.empty();
    }

    bool match(char l, char r) {
        return (l == '(' && r == ')') || (l == '[' && r == ']') || (l == '{' && r == '}');
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isValid(s string) bool {
	stk := []rune{}
	for _, c := range s {
		if c == '(' || c == '{' || c == '[' {
			stk = append(stk, c)
		} else if len(stk) == 0 || !match(stk[len(stk)-1], c) {
			return false
		} else {
			stk = stk[:len(stk)-1]
		}
	}
	return len(stk) == 0
}

func match(l, r rune) bool {
	return (l == '(' && r == ')') || (l == '[' && r == ']') || (l == '{' && r == '}')
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
const map = new Map([
    ['(', ')'],
    ['[', ']'],
    ['{', '}'],
]);

function isValid(s: string): boolean {
    const stack = [];
    for (const c of s) {
        if (map.has(c)) {
            stack.push(map.get(c));
        } else if (stack.pop() !== c) {
            return false;
        }
    }
    return stack.length === 0;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    pub fn is_valid(s: String) -> bool {
        let mut map = HashMap::new();
        map.insert('(', ')');
        map.insert('[', ']');
        map.insert('{', '}');
        let mut stack = vec![];
        for c in s.chars() {
            if map.contains_key(&c) {
                stack.push(map[&c]);
            } else if stack.pop().unwrap_or(' ') != c {
                return false;
            }
        }
        stack.len() == 0
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function (s) {
    let stk = [];
    for (const c of s) {
        if (c == '(' || c == '{' || c == '[') {
            stk.push(c);
        } else if (stk.length == 0 || !match(stk[stk.length - 1], c)) {
            return false;
        } else {
            stk.pop();
        }
    }
    return stk.length == 0;
};

function match(l, r) {
    return (l == '(' && r == ')') || (l == '[' && r == ']') || (l == '{' && r == '}');
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public bool IsValid(string s) {
        Stack<char> stk = new Stack<char>();
        foreach (var c in s.ToCharArray()) {
            if (c == '(') {
                stk.Push(')');
            } else if (c == '[') {
                stk.Push(']');
            } else if (c == '{') {
                stk.Push('}');
            } else if (stk.Count == 0 || stk.Pop() != c) {
                return false;
            }
        }
        return stk.Count == 0;
    }
}
```
{{% /tab %}}
{{% tab "rb" %}}
```rb
# @param {String} s
# @return {Boolean}
def is_valid(s)
  stack = ''
  s.split('').each do |c|
    if ['{', '[', '('].include?(c)
      stack += c
    else
      if c == '}' && stack[stack.length - 1] == '{'

        stack = stack.length > 1 ? stack[0..stack.length - 2] : ""
      elsif c == ']' && stack[stack.length - 1] == '['
        stack = stack.length > 1 ? stack[0..stack.length - 2] : ""
      elsif c == ')' && stack[stack.length - 1] == '('
        stack = stack.length > 1 ? stack[0..stack.length - 2] : ""
      else
        return false
      end
    end
  end
  stack == ''
end
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param string $s
     * @return boolean
     */

    function isValid($s) {
        $stack = [];
        $brackets = [
            ')' => '(',
            '}' => '{',
            ']' => '[',
        ];

        for ($i = 0; $i < strlen($s); $i++) {
            $char = $s[$i];
            if (array_key_exists($char, $brackets)) {
                if (empty($stack) || $stack[count($stack) - 1] !== $brackets[$char]) {
                    return false;
                }
                array_pop($stack);
            } else {
                array_push($stack, $char);
            }
        }
        return empty($stack);
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个只包括 <code>'('</code>，<code>')'</code>，<code>'{'</code>，<code>'}'</code>，<code>'['</code>，<code>']'</code>&nbsp;的字符串 <code>s</code> ，判断字符串是否有效。</p>

<p>有效字符串需满足：</p>

<ol>
	<li>左括号必须用相同类型的右括号闭合。</li>
	<li>左括号必须以正确的顺序闭合。</li>
	<li>每个右括号都有一个对应的相同类型的左括号。</li>
</ol>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>s = "()"</span></p>

<p><span class="example-io"><b>输出：</b>true</span></p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>s = "()[]{}"</span></p>

<p><span class="example-io"><b>输出：</b>true</span></p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>s = "(]"</span></p>

<p><span class="example-io"><b>输出：</b>false</span></p>
</div>

<p><strong class="example">示例 4：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>s = "([])"</span></p>

<p><span class="example-io"><b>输出：</b>true</span></p>
</div>

<p><strong class="example">示例 5：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>s = "([)]"</span></p>

<p><span class="example-io"><b>输出：</b>false</span></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> 仅由括号 <code>'()[]{}'</code> 组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：栈

遍历括号字符串 $s$，遇到左括号时，压入当前的左括号；遇到右括号时，弹出栈顶元素（若栈为空，直接返回 `false`），判断是否匹配，若不匹配，直接返回 `false`。

也可以选择遇到左括号时，将右括号压入栈中；遇到右括号时，弹出栈顶元素（若栈为空，直接返回 `false`），判断是否是相等。若不匹配，直接返回 `false`。

> 两者的区别仅限于括号转换时机，一个是在入栈时，一个是在出栈时。

遍历结束，若栈为空，说明括号字符串有效，返回 `true`；否则，返回 `false`。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为括号字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isValid(self, s: str) -> bool:
        stk = []
        d = {'()', '[]', '{}'}
        for c in s:
            if c in '({[':
                stk.append(c)
            elif not stk or stk.pop() + c not in d:
                return False
        return not stk
```

#### Java

```java
class Solution {
    public boolean isValid(String s) {
        Deque<Character> stk = new ArrayDeque<>();
        for (char c : s.toCharArray()) {
            if (c == '(' || c == '{' || c == '[') {
                stk.push(c);
            } else if (stk.isEmpty() || !match(stk.pop(), c)) {
                return false;
            }
        }
        return stk.isEmpty();
    }

    private boolean match(char l, char r) {
        return (l == '(' && r == ')') || (l == '{' && r == '}') || (l == '[' && r == ']');
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool isValid(string s) {
        string stk;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[')
                stk.push_back(c);
            else if (stk.empty() || !match(stk.back(), c))
                return false;
            else
                stk.pop_back();
        }
        return stk.empty();
    }

    bool match(char l, char r) {
        return (l == '(' && r == ')') || (l == '[' && r == ']') || (l == '{' && r == '}');
    }
};
```

#### Go

```go
func isValid(s string) bool {
	stk := []rune{}
	for _, c := range s {
		if c == '(' || c == '{' || c == '[' {
			stk = append(stk, c)
		} else if len(stk) == 0 || !match(stk[len(stk)-1], c) {
			return false
		} else {
			stk = stk[:len(stk)-1]
		}
	}
	return len(stk) == 0
}

func match(l, r rune) bool {
	return (l == '(' && r == ')') || (l == '[' && r == ']') || (l == '{' && r == '}')
}
```

#### TypeScript

```ts
const map = new Map([
    ['(', ')'],
    ['[', ']'],
    ['{', '}'],
]);

function isValid(s: string): boolean {
    const stack = [];
    for (const c of s) {
        if (map.has(c)) {
            stack.push(map.get(c));
        } else if (stack.pop() !== c) {
            return false;
        }
    }
    return stack.length === 0;
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn is_valid(s: String) -> bool {
        let mut map = HashMap::new();
        map.insert('(', ')');
        map.insert('[', ']');
        map.insert('{', '}');
        let mut stack = vec![];
        for c in s.chars() {
            if map.contains_key(&c) {
                stack.push(map[&c]);
            } else if stack.pop().unwrap_or(' ') != c {
                return false;
            }
        }
        stack.len() == 0
    }
}
```

#### JavaScript

```js
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function (s) {
    let stk = [];
    for (const c of s) {
        if (c == '(' || c == '{' || c == '[') {
            stk.push(c);
        } else if (stk.length == 0 || !match(stk[stk.length - 1], c)) {
            return false;
        } else {
            stk.pop();
        }
    }
    return stk.length == 0;
};

function match(l, r) {
    return (l == '(' && r == ')') || (l == '[' && r == ']') || (l == '{' && r == '}');
}
```

#### C#

```cs
public class Solution {
    public bool IsValid(string s) {
        Stack<char> stk = new Stack<char>();
        foreach (var c in s.ToCharArray()) {
            if (c == '(') {
                stk.Push(')');
            } else if (c == '[') {
                stk.Push(']');
            } else if (c == '{') {
                stk.Push('}');
            } else if (stk.Count == 0 || stk.Pop() != c) {
                return false;
            }
        }
        return stk.Count == 0;
    }
}
```

#### Ruby

```rb
# @param {String} s
# @return {Boolean}
def is_valid(s)
  stack = ''
  s.split('').each do |c|
    if ['{', '[', '('].include?(c)
      stack += c
    else
      if c == '}' && stack[stack.length - 1] == '{'

        stack = stack.length > 1 ? stack[0..stack.length - 2] : ""
      elsif c == ']' && stack[stack.length - 1] == '['
        stack = stack.length > 1 ? stack[0..stack.length - 2] : ""
      elsif c == ')' && stack[stack.length - 1] == '('
        stack = stack.length > 1 ? stack[0..stack.length - 2] : ""
      else
        return false
      end
    end
  end
  stack == ''
end
```

#### PHP

```php
class Solution {
    /**
     * @param string $s
     * @return boolean
     */

    function isValid($s) {
        $stack = [];
        $brackets = [
            ')' => '(',
            '}' => '{',
            ']' => '[',
        ];

        for ($i = 0; $i < strlen($s); $i++) {
            $char = $s[$i];
            if (array_key_exists($char, $brackets)) {
                if (empty($stack) || $stack[count($stack) - 1] !== $brackets[$char]) {
                    return false;
                }
                array_pop($stack);
            } else {
                array_push($stack, $char);
            }
        }
        return empty($stack);
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
