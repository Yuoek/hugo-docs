---
title: "2230_查找可享受优惠的用户 🔒"
date: 2025-10-08T18:39:07+08:00
weight: 4
tags: [二分查找, 二叉树, 前缀和, 双指针, 堆（优先队列）, 字符串, 排序, 数学, 数据库, 数组, 枚举, 树, 贪心]
---

{{< markmap >}}
### [2230_查找可享受优惠的用户 🔒](#2230)
#### [数据库](#2230)
### [2231_按奇偶性交换后的最大数字](#2231)
#### [排序](#2231)
#### [堆（优先队列）](#2231)
### [2232_向表达式添加括号后的最小结果](#2232)
#### [字符串](#2232)
#### [枚举](#2232)
### [2233_K 次增加后的最大乘积](#2233)
#### [贪心](#2233)
#### [数组](#2233)
#### [堆（优先队列）](#2233)
### [2234_花园的最大总美丽值](#2234)
#### [贪心](#2234)
#### [数组](#2234)
#### [双指针](#2234)
#### [二分查找](#2234)
#### [枚举](#2234)
#### [前缀和](#2234)
#### [排序](#2234)
### [2235_两整数相加](#2235)
#### [数学](#2235)
### [2236_判断根结点是否等于子结点之和](#2236)
#### [树](#2236)
#### [二叉树](#2236)
### [2237_计算街道上满足所需亮度的位置数量 🔒](#2237)
#### [数组](#2237)
#### [前缀和](#2237)
### [2238_司机成为乘客的次数 🔒](#2238)
#### [数据库](#2238)
### [2239_找到最接近 0 的数字](#2239)
#### [数组](#2239)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2230_查找可享受优惠的用户 🔒
___
#### 数据库
---
### 2231_按奇偶性交换后的最大数字
___
#### 排序
___
#### 堆（优先队列）
---
### 2232_向表达式添加括号后的最小结果
___
#### 字符串
___
#### 枚举
---
### 2233_K 次增加后的最大乘积
___
#### 贪心
___
#### 数组
___
#### 堆（优先队列）
---
### 2234_花园的最大总美丽值
___
#### 贪心
___
#### 数组
___
#### 双指针
___
#### 二分查找
___
#### 枚举
___
#### 前缀和
___
#### 排序
---
### 2235_两整数相加
___
#### 数学
---
### 2236_判断根结点是否等于子结点之和
___
#### 树
___
#### 二叉树
---
### 2237_计算街道上满足所需亮度的位置数量 🔒
___
#### 数组
___
#### 前缀和
---
### 2238_司机成为乘客的次数 🔒
___
#### 数据库
---
### 2239_找到最接近 0 的数字
___
#### 数组
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉树 | 前缀和 |
| 双指针 | 堆（优先队列） | 字符串 |
| 排序 | 数学 | 数据库 |
| 数组 | 枚举 | 树 |
| 贪心 |  |  |

# [2230. 查找可享受优惠的用户 🔒](https://leetcode.cn/problems/the-users-that-are-eligible-for-discount){#2230}

{{< tabs "2230" >}}

{{% tab "sql" %}}
```sql
CREATE PROCEDURE getUserIDs(startDate DATE, endDate DATE, minAmount INT)
BEGIN
    # Write your MySQL query statement below.
    SELECT DISTINCT user_id
    FROM Purchases
    WHERE amount >= minAmount AND time_stamp BETWEEN startDate AND endDate
    ORDER BY user_id;
END;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>Table: <code>Purchases</code></p>

<pre>
+-------------+----------+
| Column Name | Type     |
+-------------+----------+
| user_id     | int      |
| time_stamp  | datetime |
| amount      | int      |
+-------------+----------+
(user_id, time_stamp)是此表的主键（不同值的列的组合）。
每一行都包含有关购买时间和用户 ID user_id 以及购买的数量的信息。
</pre>

<p>如果用户在包含时间间隔 <code>[startDate，endDate]</code> 内购买了至少&nbsp;<code>minAmount</code>&nbsp;数量的商品，则有资格享受折扣。要将日期转换为时间，两个日期都应视为一天的 <strong>开始</strong>（例如，<code>endDate = 2022-03-05</code>&nbsp;应该被认为是 <code>2022-03-05 00:00:00</code>）。</p>

<p>编写一个解决方案来查询符合折扣条件的用户的 ID。</p>

<p>返回结果表，以&nbsp;<code>user_id</code>&nbsp;排序。</p>

<p>查询结果格式如下例所示。</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Purchases 表：
+---------+---------------------+--------+
| user_id | time_stamp          | amount |
+---------+---------------------+--------+
| 1       | 2022-04-20 09:03:00 | 4416   |
| 2       | 2022-03-19 19:24:02 | 678    |
| 3       | 2022-03-18 12:03:09 | 4523   |
| 3       | 2022-03-30 09:43:42 | 626    |
+---------+---------------------+--------+
startDate = 2022-03-08, endDate = 2022-03-20, minAmount = 1000
<strong>输出：</strong>
+---------+
| user_id |
+---------+
| 3       |
+---------+
<strong>解释：</strong>
在三个用户中，只有用户 3 有资格享受折扣。
- 用户 1 有一次至少购买了 minAmount 的数量，但不在时间间隔内。
- 用户 2 在时间间隔内有一次购买，但少于 minAmount 数量。
- 用户 3 是唯一满足这两个条件的用户。
</pre>

<strong>重要提示：</strong>这个问题基本上与 <a href="https://leetcode.cn/problems/the-number-of-users-that-are-eligible-for-discount/description/">有资格享受折扣的用户数量</a> 相同。

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
CREATE PROCEDURE getUserIDs(startDate DATE, endDate DATE, minAmount INT)
BEGIN
    # Write your MySQL query statement below.
    SELECT DISTINCT user_id
    FROM Purchases
    WHERE amount >= minAmount AND time_stamp BETWEEN startDate AND endDate
    ORDER BY user_id;
END;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2231. 按奇偶性交换后的最大数字](https://leetcode.cn/problems/largest-number-after-digit-swaps-by-parity){#2231}

{{< tabs "2231" >}}

{{% tab "python" %}}
```python
class Solution:
    def largestInteger(self, num: int) -> int:
        nums = [int(c) for c in str(num)]
        cnt = Counter(nums)
        idx = [8, 9]
        ans = 0
        for x in nums:
            while cnt[idx[x & 1]] == 0:
                idx[x & 1] -= 2
            ans = ans * 10 + idx[x & 1]
            cnt[idx[x & 1]] -= 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int largestInteger(int num) {
        char[] s = String.valueOf(num).toCharArray();
        int[] cnt = new int[10];
        for (char c : s) {
            ++cnt[c - '0'];
        }
        int[] idx = {8, 9};
        int ans = 0;
        for (char c : s) {
            int x = c - '0';
            while (cnt[idx[x & 1]] == 0) {
                idx[x & 1] -= 2;
            }
            ans = ans * 10 + idx[x & 1];
            cnt[idx[x & 1]]--;
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
    int largestInteger(int num) {
        string s = to_string(num);
        int cnt[10] = {0};
        for (char c : s) {
            cnt[c - '0']++;
        }
        int idx[2] = {8, 9};
        int ans = 0;
        for (char c : s) {
            int x = c - '0';
            while (cnt[idx[x & 1]] == 0) {
                idx[x & 1] -= 2;
            }
            ans = ans * 10 + idx[x & 1];
            cnt[idx[x & 1]]--;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func largestInteger(num int) int {
	s := []byte(fmt.Sprint(num))
	cnt := [10]int{}

	for _, c := range s {
		cnt[c-'0']++
	}

	idx := [2]int{8, 9}
	ans := 0

	for _, c := range s {
		x := int(c - '0')
		for cnt[idx[x&1]] == 0 {
			idx[x&1] -= 2
		}
		ans = ans*10 + idx[x&1]
		cnt[idx[x&1]]--
	}

	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function largestInteger(num: number): number {
    const s = num.toString().split('');
    const cnt = Array(10).fill(0);

    for (const c of s) {
        cnt[+c]++;
    }

    const idx = [8, 9];
    let ans = 0;

    for (const c of s) {
        const x = +c;
        while (cnt[idx[x % 2]] === 0) {
            idx[x % 2] -= 2;
        }
        ans = ans * 10 + idx[x % 2];
        cnt[idx[x % 2]]--;
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

<p>给你一个正整数 <code>num</code> 。你可以交换 <code>num</code> 中 <strong>奇偶性</strong> 相同的任意两位数字（即，都是奇数或者偶数）。</p>

<p>返回交换 <strong>任意</strong> 次之后 <code>num</code> 的 <strong>最大</strong> 可能值<em>。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>num = 1234
<strong>输出：</strong>3412
<strong>解释：</strong>交换数字 3 和数字 1 ，结果得到 3214 。
交换数字 2 和数字 4 ，结果得到 3412 。
注意，可能存在其他交换序列，但是可以证明 3412 是最大可能值。
注意，不能交换数字 4 和数字 1 ，因为它们奇偶性不同。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>num = 65875
<strong>输出：</strong>87655
<strong>解释：</strong>交换数字 8 和数字 6 ，结果得到 85675 。
交换数字 5 和数字 7 ，结果得到 87655 。
注意，可能存在其他交换序列，但是可以证明 87655 是最大可能值。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们可以用一个长度为 $10$ 的数组 $\textit{cnt}$ 统计整数 $\textit{num}$ 中所有数字出现的次数，用一个下标数组 $\textit{idx}$ 记录当前最大可用偶数和奇数，初始时 $\textit{idx}$ 为 $[8, 9]$。

接下来，我们依次遍历整数 $\textit{num}$ 的每个数字，如果数字为奇数，则取 $\textit{idx}$ 下标为 $1$ 对应的数字，否则取下标为 $0$ 对应的数字。如果该数字出现的次数为 $0$，则需要将数字减 $2$，继续判断，直到存在满足条件的数。然后，我们更新答案，以及数字出现的次数，继续遍历，直到遍历到整数 $\textit{num}$。

时间复杂度 $O(\log \textit{num})$，空间复杂度 $O(\log \textit{num})$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def largestInteger(self, num: int) -> int:
        nums = [int(c) for c in str(num)]
        cnt = Counter(nums)
        idx = [8, 9]
        ans = 0
        for x in nums:
            while cnt[idx[x & 1]] == 0:
                idx[x & 1] -= 2
            ans = ans * 10 + idx[x & 1]
            cnt[idx[x & 1]] -= 1
        return ans
```

#### Java

```java
class Solution {
    public int largestInteger(int num) {
        char[] s = String.valueOf(num).toCharArray();
        int[] cnt = new int[10];
        for (char c : s) {
            ++cnt[c - '0'];
        }
        int[] idx = {8, 9};
        int ans = 0;
        for (char c : s) {
            int x = c - '0';
            while (cnt[idx[x & 1]] == 0) {
                idx[x & 1] -= 2;
            }
            ans = ans * 10 + idx[x & 1];
            cnt[idx[x & 1]]--;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);
        int cnt[10] = {0};
        for (char c : s) {
            cnt[c - '0']++;
        }
        int idx[2] = {8, 9};
        int ans = 0;
        for (char c : s) {
            int x = c - '0';
            while (cnt[idx[x & 1]] == 0) {
                idx[x & 1] -= 2;
            }
            ans = ans * 10 + idx[x & 1];
            cnt[idx[x & 1]]--;
        }
        return ans;
    }
};
```

#### Go

```go
func largestInteger(num int) int {
	s := []byte(fmt.Sprint(num))
	cnt := [10]int{}

	for _, c := range s {
		cnt[c-'0']++
	}

	idx := [2]int{8, 9}
	ans := 0

	for _, c := range s {
		x := int(c - '0')
		for cnt[idx[x&1]] == 0 {
			idx[x&1] -= 2
		}
		ans = ans*10 + idx[x&1]
		cnt[idx[x&1]]--
	}

	return ans
}
```

#### TypeScript

```ts
function largestInteger(num: number): number {
    const s = num.toString().split('');
    const cnt = Array(10).fill(0);

    for (const c of s) {
        cnt[+c]++;
    }

    const idx = [8, 9];
    let ans = 0;

    for (const c of s) {
        const x = +c;
        while (cnt[idx[x % 2]] === 0) {
            idx[x % 2] -= 2;
        }
        ans = ans * 10 + idx[x % 2];
        cnt[idx[x % 2]]--;
    }

    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：分组 + 排序

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2232. 向表达式添加括号后的最小结果](https://leetcode.cn/problems/minimize-result-by-adding-parentheses-to-expression){#2232}

{{< tabs "2232" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimizeResult(self, expression: str) -> str:
        l, r = expression.split("+")
        m, n = len(l), len(r)
        mi = inf
        ans = None
        for i in range(m):
            for j in range(n):
                c = int(l[i:]) + int(r[: j + 1])
                a = 1 if i == 0 else int(l[:i])
                b = 1 if j == n - 1 else int(r[j + 1 :])
                if (t := a * b * c) < mi:
                    mi = t
                    ans = f"{l[:i]}({l[i:]}+{r[: j + 1]}){r[j + 1:]}"
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String minimizeResult(String expression) {
        int idx = expression.indexOf('+');
        String l = expression.substring(0, idx);
        String r = expression.substring(idx + 1);
        int m = l.length(), n = r.length();
        int mi = Integer.MAX_VALUE;
        String ans = "";
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int c = Integer.parseInt(l.substring(i)) + Integer.parseInt(r.substring(0, j + 1));
                int a = i == 0 ? 1 : Integer.parseInt(l.substring(0, i));
                int b = j == n - 1 ? 1 : Integer.parseInt(r.substring(j + 1));
                int t = a * b * c;
                if (t < mi) {
                    mi = t;
                    ans = String.format("%s(%s+%s)%s", l.substring(0, i), l.substring(i),
                        r.substring(0, j + 1), r.substring(j + 1));
                }
            }
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimizeResult(expression: string): string {
    const [n1, n2] = expression.split('+');
    let minSum = Number.MAX_SAFE_INTEGER;
    let ans = '';
    let arr1 = [],
        arr2 = n1.split(''),
        arr3 = n2.split(''),
        arr4 = [];
    while (arr2.length) {
        (arr3 = n2.split('')), (arr4 = []);
        while (arr3.length) {
            let cur = (getNum(arr2) + getNum(arr3)) * getNum(arr1) * getNum(arr4);
            if (cur < minSum) {
                minSum = cur;
                ans = `${arr1.join('')}(${arr2.join('')}+${arr3.join('')})${arr4.join('')}`;
            }
            arr4.unshift(arr3.pop());
        }
        arr1.push(arr2.shift());
    }
    return ans;
}

function getNum(arr: Array<string>): number {
    return arr.length ? Number(arr.join('')) : 1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始的字符串 <code>expression</code> ，格式为 <code>"&lt;num1&gt;+&lt;num2&gt;"</code> ，其中 <code>&lt;num1&gt;</code> 和 <code>&lt;num2&gt;</code> 表示正整数。</p>

<p>请你向 <code>expression</code> 中添加一对括号，使得在添加之后， <code>expression</code> 仍然是一个有效的数学表达式，并且计算后可以得到 <strong>最小</strong> 可能值。左括号 <strong>必须</strong> 添加在 <code>'+'</code> 的左侧，而右括号必须添加在 <code>'+'</code> 的右侧。</p>

<p>返回添加一对括号后形成的表达式&nbsp;<code>expression</code> ，且满足<em> </em><code>expression</code><em> </em>计算得到 <strong>最小</strong> 可能值<em>。</em>如果存在多个答案都能产生相同结果，返回任意一个答案。</p>

<p>生成的输入满足：<code>expression</code> 的原始值和添加满足要求的任一对括号之后 <code>expression</code> 的值，都符合 32-bit 带符号整数范围。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>expression = "247+38"
<strong>输出：</strong>"2(47+38)"
<strong>解释：</strong>表达式计算得到 2 * (47 + 38) = 2 * 85 = 170 。
注意 "2(4)7+38" 不是有效的结果，因为右括号必须添加在 <code>'+' 的右侧。</code>
可以证明 170 是最小可能值。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>expression = "12+34"
<strong>输出：</strong>"1(2+3)4"
<strong>解释：</strong>表达式计算得到 1 * (2 + 3) * 4 = 1 * 5 * 4 = 20 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>expression = "999+999"
<strong>输出：</strong>"(999+999)"
<strong>解释：</strong>表达式计算得到 999 + 999 = 1998 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= expression.length &lt;= 10</code></li>
	<li><code>expression</code> 仅由数字 <code>'1'</code> 到 <code>'9'</code> 和 <code>'+'</code> 组成</li>
	<li><code>expression</code> 由数字开始和结束</li>
	<li><code>expression</code> 恰好仅含有一个 <code>'+'</code>.</li>
	<li><code>expression</code> 的原始值和添加满足要求的任一对括号之后 <code>expression</code> 的值，都符合 32-bit 带符号整数范围</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举左右括号的插入位置

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimizeResult(self, expression: str) -> str:
        l, r = expression.split("+")
        m, n = len(l), len(r)
        mi = inf
        ans = None
        for i in range(m):
            for j in range(n):
                c = int(l[i:]) + int(r[: j + 1])
                a = 1 if i == 0 else int(l[:i])
                b = 1 if j == n - 1 else int(r[j + 1 :])
                if (t := a * b * c) < mi:
                    mi = t
                    ans = f"{l[:i]}({l[i:]}+{r[: j + 1]}){r[j + 1:]}"
        return ans
```

#### Java

```java
class Solution {
    public String minimizeResult(String expression) {
        int idx = expression.indexOf('+');
        String l = expression.substring(0, idx);
        String r = expression.substring(idx + 1);
        int m = l.length(), n = r.length();
        int mi = Integer.MAX_VALUE;
        String ans = "";
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int c = Integer.parseInt(l.substring(i)) + Integer.parseInt(r.substring(0, j + 1));
                int a = i == 0 ? 1 : Integer.parseInt(l.substring(0, i));
                int b = j == n - 1 ? 1 : Integer.parseInt(r.substring(j + 1));
                int t = a * b * c;
                if (t < mi) {
                    mi = t;
                    ans = String.format("%s(%s+%s)%s", l.substring(0, i), l.substring(i),
                        r.substring(0, j + 1), r.substring(j + 1));
                }
            }
        }
        return ans;
    }
}
```

#### TypeScript

```ts
function minimizeResult(expression: string): string {
    const [n1, n2] = expression.split('+');
    let minSum = Number.MAX_SAFE_INTEGER;
    let ans = '';
    let arr1 = [],
        arr2 = n1.split(''),
        arr3 = n2.split(''),
        arr4 = [];
    while (arr2.length) {
        (arr3 = n2.split('')), (arr4 = []);
        while (arr3.length) {
            let cur = (getNum(arr2) + getNum(arr3)) * getNum(arr1) * getNum(arr4);
            if (cur < minSum) {
                minSum = cur;
                ans = `${arr1.join('')}(${arr2.join('')}+${arr3.join('')})${arr4.join('')}`;
            }
            arr4.unshift(arr3.pop());
        }
        arr1.push(arr2.shift());
    }
    return ans;
}

function getNum(arr: Array<string>): number {
    return arr.length ? Number(arr.join('')) : 1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2233. K 次增加后的最大乘积](https://leetcode.cn/problems/maximum-product-after-k-increments){#2233}

{{< tabs "2233" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumProduct(self, nums: List[int], k: int) -> int:
        heapify(nums)
        for _ in range(k):
            heapreplace(nums, nums[0] + 1)
        mod = 10**9 + 7
        return reduce(lambda x, y: x * y % mod, nums)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumProduct(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int x : nums) {
            pq.offer(x);
        }
        while (k-- > 0) {
            pq.offer(pq.poll() + 1);
        }
        final int mod = (int) 1e9 + 7;
        long ans = 1;
        for (int x : pq) {
            ans = (ans * x) % mod;
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
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int x : nums) {
            pq.push(x);
        }
        while (k-- > 0) {
            int smallest = pq.top();
            pq.pop();
            pq.push(smallest + 1);
        }
        const int mod = 1e9 + 7;
        long long ans = 1;
        while (!pq.empty()) {
            ans = (ans * pq.top()) % mod;
            pq.pop();
        }
        return static_cast<int>(ans);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumProduct(nums []int, k int) int {
	h := hp{nums}
	for heap.Init(&h); k > 0; k-- {
		h.IntSlice[0]++
		heap.Fix(&h, 0)
	}
	ans := 1
	for _, x := range nums {
		ans = (ans * x) % (1e9 + 7)
	}
	return ans
}

type hp struct{ sort.IntSlice }

func (hp) Push(any)     {}
func (hp) Pop() (_ any) { return }
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumProduct(nums: number[], k: number): number {
    const pq = new MinPriorityQueue();
    nums.forEach(x => pq.enqueue(x));
    while (k--) {
        const x = pq.dequeue().element;
        pq.enqueue(x + 1);
    }
    let ans = 1;
    const mod = 10 ** 9 + 7;
    while (!pq.isEmpty()) {
        ans = (ans * pq.dequeue().element) % mod;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maximumProduct = function (nums, k) {
    const pq = new MinPriorityQueue();
    nums.forEach(x => pq.enqueue(x));
    while (k--) {
        const x = pq.dequeue().element;
        pq.enqueue(x + 1);
    }
    let ans = 1;
    const mod = 10 ** 9 + 7;
    while (!pq.isEmpty()) {
        ans = (ans * pq.dequeue().element) % mod;
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

<p>给你一个非负整数数组&nbsp;<code>nums</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;。每次操作，你可以选择&nbsp;<code>nums</code>&nbsp;中 <strong>任一</strong>&nbsp;元素并将它 <strong>增加</strong>&nbsp;<code>1</code>&nbsp;。</p>

<p>请你返回 <strong>至多</strong>&nbsp;<code>k</code>&nbsp;次操作后，能得到的<em>&nbsp;</em><code>nums</code>的&nbsp;<strong>最大乘积</strong>&nbsp;。由于答案可能很大，请你将答案对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;取余后返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [0,4], k = 5
<b>输出：</b>20
<b>解释：</b>将第一个数增加 5 次。
得到 nums = [5, 4] ，乘积为 5 * 4 = 20 。
可以证明 20 是能得到的最大乘积，所以我们返回 20 。
存在其他增加 nums 的方法，也能得到最大乘积。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [6,3,3,2], k = 2
<b>输出：</b>216
<b>解释：</b>将第二个数增加 1 次，将第四个数增加 1 次。
得到 nums = [6, 4, 3, 3] ，乘积为 6 * 4 * 3 * 3 = 216 。
可以证明 216 是能得到的最大乘积，所以我们返回 216 。
存在其他增加 nums 的方法，也能得到最大乘积。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length, k &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 优先队列（小根堆）

根据题目描述，要使得乘积最大，我们需要尽量增大较小的数，因此我们可以使用小根堆来维护数组 $\textit{nums}$。每次从小根堆中取出最小的数，将其增加 $1$，然后重新放回小根堆中。重复这个过程 $k$ 次后，我们将当前小根堆中的所有数相乘，即可得到答案。

时间复杂度 $O(k \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumProduct(self, nums: List[int], k: int) -> int:
        heapify(nums)
        for _ in range(k):
            heapreplace(nums, nums[0] + 1)
        mod = 10**9 + 7
        return reduce(lambda x, y: x * y % mod, nums)
```

#### Java

```java
class Solution {
    public int maximumProduct(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int x : nums) {
            pq.offer(x);
        }
        while (k-- > 0) {
            pq.offer(pq.poll() + 1);
        }
        final int mod = (int) 1e9 + 7;
        long ans = 1;
        for (int x : pq) {
            ans = (ans * x) % mod;
        }
        return (int) ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int x : nums) {
            pq.push(x);
        }
        while (k-- > 0) {
            int smallest = pq.top();
            pq.pop();
            pq.push(smallest + 1);
        }
        const int mod = 1e9 + 7;
        long long ans = 1;
        while (!pq.empty()) {
            ans = (ans * pq.top()) % mod;
            pq.pop();
        }
        return static_cast<int>(ans);
    }
};
```

#### Go

```go
func maximumProduct(nums []int, k int) int {
	h := hp{nums}
	for heap.Init(&h); k > 0; k-- {
		h.IntSlice[0]++
		heap.Fix(&h, 0)
	}
	ans := 1
	for _, x := range nums {
		ans = (ans * x) % (1e9 + 7)
	}
	return ans
}

type hp struct{ sort.IntSlice }

func (hp) Push(any)     {}
func (hp) Pop() (_ any) { return }
```

#### TypeScript

```ts
function maximumProduct(nums: number[], k: number): number {
    const pq = new MinPriorityQueue();
    nums.forEach(x => pq.enqueue(x));
    while (k--) {
        const x = pq.dequeue().element;
        pq.enqueue(x + 1);
    }
    let ans = 1;
    const mod = 10 ** 9 + 7;
    while (!pq.isEmpty()) {
        ans = (ans * pq.dequeue().element) % mod;
    }
    return ans;
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maximumProduct = function (nums, k) {
    const pq = new MinPriorityQueue();
    nums.forEach(x => pq.enqueue(x));
    while (k--) {
        const x = pq.dequeue().element;
        pq.enqueue(x + 1);
    }
    let ans = 1;
    const mod = 10 ** 9 + 7;
    while (!pq.isEmpty()) {
        ans = (ans * pq.dequeue().element) % mod;
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2234. 花园的最大总美丽值](https://leetcode.cn/problems/maximum-total-beauty-of-the-gardens){#2234}

{{< tabs "2234" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumBeauty(
        self, flowers: List[int], newFlowers: int, target: int, full: int, partial: int
    ) -> int:
        flowers.sort()
        n = len(flowers)
        s = list(accumulate(flowers, initial=0))
        ans, i = 0, n - bisect_left(flowers, target)
        for x in range(i, n + 1):
            newFlowers -= 0 if x == 0 else max(target - flowers[n - x], 0)
            if newFlowers < 0:
                break
            l, r = 0, n - x - 1
            while l < r:
                mid = (l + r + 1) >> 1
                if flowers[mid] * (mid + 1) - s[mid + 1] <= newFlowers:
                    l = mid
                else:
                    r = mid - 1
            y = 0
            if r != -1:
                cost = flowers[l] * (l + 1) - s[l + 1]
                y = min(flowers[l] + (newFlowers - cost) // (l + 1), target - 1)
            ans = max(ans, x * full + y * partial)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long maximumBeauty(int[] flowers, long newFlowers, int target, int full, int partial) {
        Arrays.sort(flowers);
        int n = flowers.length;
        long[] s = new long[n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + flowers[i];
        }
        long ans = 0;
        int x = 0;
        for (int v : flowers) {
            if (v >= target) {
                ++x;
            }
        }
        for (; x <= n; ++x) {
            newFlowers -= (x == 0 ? 0 : Math.max(target - flowers[n - x], 0));
            if (newFlowers < 0) {
                break;
            }
            int l = 0, r = n - x - 1;
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if ((long) flowers[mid] * (mid + 1) - s[mid + 1] <= newFlowers) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            long y = 0;
            if (r != -1) {
                long cost = (long) flowers[l] * (l + 1) - s[l + 1];
                y = Math.min(flowers[l] + (newFlowers - cost) / (l + 1), target - 1);
            }
            ans = Math.max(ans, (long) x * full + y * partial);
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
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        sort(flowers.begin(), flowers.end());
        int n = flowers.size();
        long long s[n + 1];
        s[0] = 0;
        for (int i = 1; i <= n; ++i) {
            s[i] = s[i - 1] + flowers[i - 1];
        }
        long long ans = 0;
        int i = flowers.end() - lower_bound(flowers.begin(), flowers.end(), target);
        for (int x = i; x <= n; ++x) {
            newFlowers -= (x == 0 ? 0 : max(target - flowers[n - x], 0));
            if (newFlowers < 0) {
                break;
            }
            int l = 0, r = n - x - 1;
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (1LL * flowers[mid] * (mid + 1) - s[mid + 1] <= newFlowers) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            int y = 0;
            if (r != -1) {
                long long cost = 1LL * flowers[l] * (l + 1) - s[l + 1];
                long long mx = flowers[l] + (newFlowers - cost) / (l + 1);
                long long threshold = target - 1;
                y = min(mx, threshold);
            }
            ans = max(ans, 1LL * x * full + 1LL * y * partial);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumBeauty(flowers []int, newFlowers int64, target int, full int, partial int) int64 {
	sort.Ints(flowers)
	n := len(flowers)
	s := make([]int, n+1)
	for i, x := range flowers {
		s[i+1] = s[i] + x
	}
	ans := 0
	i := n - sort.SearchInts(flowers, target)
	for x := i; x <= n; x++ {
		if x > 0 {
			newFlowers -= int64(max(target-flowers[n-x], 0))
		}
		if newFlowers < 0 {
			break
		}
		l, r := 0, n-x-1
		for l < r {
			mid := (l + r + 1) >> 1
			if int64(flowers[mid]*(mid+1)-s[mid+1]) <= newFlowers {
				l = mid
			} else {
				r = mid - 1
			}
		}
		y := 0
		if r != -1 {
			cost := flowers[l]*(l+1) - s[l+1]
			y = min(flowers[l]+int((newFlowers-int64(cost))/int64(l+1)), target-1)
		}
		ans = max(ans, x*full+y*partial)
	}
	return int64(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumBeauty(
    flowers: number[],
    newFlowers: number,
    target: number,
    full: number,
    partial: number,
): number {
    flowers.sort((a, b) => a - b);
    const n = flowers.length;
    const s: number[] = Array(n + 1).fill(0);
    for (let i = 1; i <= n; i++) {
        s[i] = s[i - 1] + flowers[i - 1];
    }
    let x = flowers.filter(f => f >= target).length;
    let ans = 0;
    for (; x <= n; ++x) {
        newFlowers -= x === 0 ? 0 : Math.max(target - flowers[n - x], 0);
        if (newFlowers < 0) {
            break;
        }
        let l = 0;
        let r = n - x - 1;
        while (l < r) {
            const mid = (l + r + 1) >> 1;
            if (flowers[mid] * (mid + 1) - s[mid + 1] <= newFlowers) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        let y = 0;
        if (r !== -1) {
            const cost = flowers[l] * (l + 1) - s[l + 1];
            y = Math.min(flowers[l] + Math.floor((newFlowers - cost) / (l + 1)), target - 1);
        }
        ans = Math.max(ans, x * full + y * partial);
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

<p>Alice 是&nbsp;<code>n</code>&nbsp;个花园的园丁，她想通过种花，最大化她所有花园的总美丽值。</p>

<p>给你一个下标从 <strong>0</strong>&nbsp;开始大小为 <code>n</code>&nbsp;的整数数组&nbsp;<code>flowers</code>&nbsp;，其中&nbsp;<code>flowers[i]</code>&nbsp;是第 <code>i</code>&nbsp;个花园里已经种的花的数目。已经种了的花 <strong>不能</strong>&nbsp;移走。同时给你&nbsp;<code>newFlowers</code>&nbsp;，表示 Alice 额外可以种花的&nbsp;<strong>最大数目</strong>&nbsp;。同时给你的还有整数&nbsp;<code>target</code>&nbsp;，<code>full</code>&nbsp;和&nbsp;<code>partial</code>&nbsp;。</p>

<p>如果一个花园有 <strong>至少</strong>&nbsp;<code>target</code>&nbsp;朵花，那么这个花园称为 <strong>完善的</strong>&nbsp;，花园的 <strong>总美丽值</strong>&nbsp;为以下分数之 <strong>和</strong> ：</p>

<ul>
	<li><b>完善</b> 花园数目乘以&nbsp;<code>full</code>.</li>
	<li>剩余 <strong>不完善</strong>&nbsp;花园里，花的 <strong>最少数目</strong>&nbsp;乘以&nbsp;<code>partial</code>&nbsp;。如果没有不完善花园，那么这一部分的值为&nbsp;<code>0</code>&nbsp;。</li>
</ul>

<p>请你返回 Alice 种最多 <code>newFlowers</code>&nbsp;朵花以后，能得到的<strong>&nbsp;最大</strong>&nbsp;总美丽值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>flowers = [1,3,1,1], newFlowers = 7, target = 6, full = 12, partial = 1
<b>输出：</b>14
<b>解释：</b>Alice 可以按以下方案种花
- 在第 0 个花园种 2 朵花
- 在第 1 个花园种 3 朵花
- 在第 2 个花园种 1 朵花
- 在第 3 个花园种 1 朵花
花园里花的数目为 [3,6,2,2] 。总共种了 2 + 3 + 1 + 1 = 7 朵花。
只有 1 个花园是完善的。
不完善花园里花的最少数目是 2 。
所以总美丽值为 1 * 12 + 2 * 1 = 12 + 2 = 14 。
没有其他方案可以让花园总美丽值超过 14 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>flowers = [2,4,5,3], newFlowers = 10, target = 5, full = 2, partial = 6
<b>输出：</b>30
<b>解释：</b>Alice 可以按以下方案种花
- 在第 0 个花园种 3 朵花
- 在第 1 个花园种 0 朵花
- 在第 2 个花园种 0 朵花
- 在第 3 个花园种 2 朵花
花园里花的数目为 [5,4,5,5] 。总共种了 3 + 0 + 0 + 2 = 5 朵花。
有 3 个花园是完善的。
不完善花园里花的最少数目为 4 。
所以总美丽值为 3 * 2 + 4 * 6 = 6 + 24 = 30 。
没有其他方案可以让花园总美丽值超过 30 。
注意，Alice可以让所有花园都变成完善的，但这样她的总美丽值反而更小。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= flowers.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= flowers[i], target &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= newFlowers &lt;= 10<sup>10</sup></code></li>
	<li><code>1 &lt;= full, partial &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举 + 二分查找

我们注意到，如果一个花园中种的花的数目已经大于等于 $\textit{target}$，那么这个花园就已经是完善的花园，不能再改变。而不完善的花园中，可以通过种更多的花来使得这个花园变成完善的花园。

我们不妨枚举有多少个花园最终成为完善的花园，假设初始时有 $x$ 个完善的花园，那么我们可以在 $[x, n]$ 范围内枚举。我们应该选择哪些不完善花园变成完善花园呢？实际上，我们应该选择那么花的数目较多的花园，这样才能使得最终剩下的可额外种植的花更多，将这些花用于提升不完善花园的最小值。因此，我们对数组 $\textit{flowers}$ 进行排序。

接下来，我们枚举完善花园的数目 $x$，那么当前要变成完善花园的是 $\textit{target}[n-x]$，需要种植的花的数量为 $\max(0, \textit{target} - \textit{flowers}[n - x])$。

我们更新剩余可种植的花 $\textit{newFlowers}$，如果小于 $0$，说明已经不能将更多的花园变成完善花园了，直接退出枚举。

否则，我们在 $[0,..n-x-1]$ 范围内，二分查找可以把不完善花园变成完善花园的最大下标。记下标为 $l$，那么所需要种植的花的数量为 $\textit{cost} = \textit{flowers}[l] \times (l + 1) - s[l + 1]$，其中 $s[i]$ 是 $\textit{flowers}$ 数组中前 $i$ 个数之和。如果此时还能提升最小值的大小，我们算出能提升的幅度 $\frac{\textit{newFlowers} - \textit{cost}}{l + 1}$，并且保证最终的最小值不超过 $\textit{target}-1$。即最小值 $y = \min(\textit{flowers}[l] + \frac{\textit{newFlowers} - \textit{cost}}{l + 1}, \textit{target} - 1)$。那么此时花园的美丽值为 $x \times \textit{full} + y \times \textit{partial}$。答案为所有美丽值的最大值。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $\textit{flowers}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumBeauty(
        self, flowers: List[int], newFlowers: int, target: int, full: int, partial: int
    ) -> int:
        flowers.sort()
        n = len(flowers)
        s = list(accumulate(flowers, initial=0))
        ans, i = 0, n - bisect_left(flowers, target)
        for x in range(i, n + 1):
            newFlowers -= 0 if x == 0 else max(target - flowers[n - x], 0)
            if newFlowers < 0:
                break
            l, r = 0, n - x - 1
            while l < r:
                mid = (l + r + 1) >> 1
                if flowers[mid] * (mid + 1) - s[mid + 1] <= newFlowers:
                    l = mid
                else:
                    r = mid - 1
            y = 0
            if r != -1:
                cost = flowers[l] * (l + 1) - s[l + 1]
                y = min(flowers[l] + (newFlowers - cost) // (l + 1), target - 1)
            ans = max(ans, x * full + y * partial)
        return ans
```

#### Java

```java
class Solution {
    public long maximumBeauty(int[] flowers, long newFlowers, int target, int full, int partial) {
        Arrays.sort(flowers);
        int n = flowers.length;
        long[] s = new long[n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + flowers[i];
        }
        long ans = 0;
        int x = 0;
        for (int v : flowers) {
            if (v >= target) {
                ++x;
            }
        }
        for (; x <= n; ++x) {
            newFlowers -= (x == 0 ? 0 : Math.max(target - flowers[n - x], 0));
            if (newFlowers < 0) {
                break;
            }
            int l = 0, r = n - x - 1;
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if ((long) flowers[mid] * (mid + 1) - s[mid + 1] <= newFlowers) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            long y = 0;
            if (r != -1) {
                long cost = (long) flowers[l] * (l + 1) - s[l + 1];
                y = Math.min(flowers[l] + (newFlowers - cost) / (l + 1), target - 1);
            }
            ans = Math.max(ans, (long) x * full + y * partial);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        sort(flowers.begin(), flowers.end());
        int n = flowers.size();
        long long s[n + 1];
        s[0] = 0;
        for (int i = 1; i <= n; ++i) {
            s[i] = s[i - 1] + flowers[i - 1];
        }
        long long ans = 0;
        int i = flowers.end() - lower_bound(flowers.begin(), flowers.end(), target);
        for (int x = i; x <= n; ++x) {
            newFlowers -= (x == 0 ? 0 : max(target - flowers[n - x], 0));
            if (newFlowers < 0) {
                break;
            }
            int l = 0, r = n - x - 1;
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (1LL * flowers[mid] * (mid + 1) - s[mid + 1] <= newFlowers) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            int y = 0;
            if (r != -1) {
                long long cost = 1LL * flowers[l] * (l + 1) - s[l + 1];
                long long mx = flowers[l] + (newFlowers - cost) / (l + 1);
                long long threshold = target - 1;
                y = min(mx, threshold);
            }
            ans = max(ans, 1LL * x * full + 1LL * y * partial);
        }
        return ans;
    }
};
```

#### Go

```go
func maximumBeauty(flowers []int, newFlowers int64, target int, full int, partial int) int64 {
	sort.Ints(flowers)
	n := len(flowers)
	s := make([]int, n+1)
	for i, x := range flowers {
		s[i+1] = s[i] + x
	}
	ans := 0
	i := n - sort.SearchInts(flowers, target)
	for x := i; x <= n; x++ {
		if x > 0 {
			newFlowers -= int64(max(target-flowers[n-x], 0))
		}
		if newFlowers < 0 {
			break
		}
		l, r := 0, n-x-1
		for l < r {
			mid := (l + r + 1) >> 1
			if int64(flowers[mid]*(mid+1)-s[mid+1]) <= newFlowers {
				l = mid
			} else {
				r = mid - 1
			}
		}
		y := 0
		if r != -1 {
			cost := flowers[l]*(l+1) - s[l+1]
			y = min(flowers[l]+int((newFlowers-int64(cost))/int64(l+1)), target-1)
		}
		ans = max(ans, x*full+y*partial)
	}
	return int64(ans)
}
```

#### TypeScript

```ts
function maximumBeauty(
    flowers: number[],
    newFlowers: number,
    target: number,
    full: number,
    partial: number,
): number {
    flowers.sort((a, b) => a - b);
    const n = flowers.length;
    const s: number[] = Array(n + 1).fill(0);
    for (let i = 1; i <= n; i++) {
        s[i] = s[i - 1] + flowers[i - 1];
    }
    let x = flowers.filter(f => f >= target).length;
    let ans = 0;
    for (; x <= n; ++x) {
        newFlowers -= x === 0 ? 0 : Math.max(target - flowers[n - x], 0);
        if (newFlowers < 0) {
            break;
        }
        let l = 0;
        let r = n - x - 1;
        while (l < r) {
            const mid = (l + r + 1) >> 1;
            if (flowers[mid] * (mid + 1) - s[mid + 1] <= newFlowers) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        let y = 0;
        if (r !== -1) {
            const cost = flowers[l] * (l + 1) - s[l + 1];
            y = Math.min(flowers[l] + Math.floor((newFlowers - cost) / (l + 1)), target - 1);
        }
        ans = Math.max(ans, x * full + y * partial);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2235. 两整数相加](https://leetcode.cn/problems/add-two-integers){#2235}

{{< tabs "2235" >}}

{{% tab "python" %}}
```python
class Solution:
    def sum(self, num1: int, num2: int) -> int:
        num1, num2 = num1 & 0xFFFFFFFF, num2 & 0xFFFFFFFF
        while num2:
            carry = ((num1 & num2) << 1) & 0xFFFFFFFF
            num1, num2 = num1 ^ num2, carry
        return num1 if num1 < 0x80000000 else ~(num1 ^ 0xFFFFFFFF)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int sum(int num1, int num2) {
        while (num2 != 0) {
            int carry = (num1 & num2) << 1;
            num1 ^= num2;
            num2 = carry;
        }
        return num1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int sum(int num1, int num2) {
        while (num2) {
            unsigned int carry = (unsigned int) (num1 & num2) << 1;
            num1 ^= num2;
            num2 = carry;
        }
        return num1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sum(num1 int, num2 int) int {
	for num2 != 0 {
		carry := (num1 & num2) << 1
		num1 ^= num2
		num2 = carry
	}
	return num1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function sum(num1: number, num2: number): number {
    while (num2) {
        const carry = (num1 & num2) << 1;
        num1 ^= num2;
        num2 = carry;
    }
    return num1;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn sum(num1: i32, num2: i32) -> i32 {
        let mut num1 = num1;
        let mut num2 = num2;
        while num2 != 0 {
            let carry = (num1 & num2) << 1;
            num1 ^= num2;
            num2 = carry;
        }
        num1
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int sum(int num1, int num2) {
    return num1 + num2;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

给你两个整数&nbsp;<code>num1</code> 和 <code>num2</code>，返回这两个整数的和。

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>num1 = 12, num2 = 5
<strong>输出：</strong>17
<strong>解释：</strong>num1 是 12，num2 是 5 ，它们的和是 12 + 5 = 17 ，因此返回 17 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>num1 = -10, num2 = 4
<strong>输出：</strong>-6
<strong>解释：</strong>num1 + num2 = -6 ，因此返回 -6 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>-100 &lt;= num1, num2 &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：使用加法运算符

我们可以直接使用加法运算符 `+` 来计算两个整数的和。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sum(self, num1: int, num2: int) -> int:
        return num1 + num2
```

#### Java

```java
class Solution {
    public int sum(int num1, int num2) {
        return num1 + num2;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int sum(int num1, int num2) {
        return num1 + num2;
    }
};
```

#### Go

```go
func sum(num1 int, num2 int) int {
	return num1 + num2
}
```

#### TypeScript

```ts
function sum(num1: number, num2: number): number {
    return num1 + num2;
}
```

#### Rust

```rust
impl Solution {
    pub fn sum(num1: i32, num2: i32) -> i32 {
        num1 + num2
    }
}
```

#### C

```c
int sum(int num1, int num2) {
    return num1 + num2;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：位运算（不使用加法运算符）

我们也可以在不使用加法运算符的前提下，使用位运算来计算两个整数的和。

假设 $num1_i$ 和 $num2_i$ 分别表示 $num1$ 和 $num2$ 的第 $i$ 个二进制位。一共有 $4$ 种情况：

| $num1_i$ | $num2_i$ | 不进位的和 | 进位 |
| -------- | -------- | ---------- | ---- |
| 0        | 0        | 0          | 0    |
| 0        | 1        | 1          | 0    |
| 1        | 0        | 1          | 0    |
| 1        | 1        | 0          | 1    |

观察可以发现，“不进位的和”与“异或运算”有相同规律，而进位则与“与”运算规律相同，并且需要左移一位。

因此：

-   对两数进行按位 `&` 与运算，然后左移一位，得到进位，记为 $carry$；
-   对两数进行按位 `^` 异或运算，得到不进位的和；
-   问题转换为求：“不进位的数 + 进位” 之和；
-   循环，直至第二个数为 $0$，返回第一个数即可（也可以用递归实现）。

时间复杂度 $O(\log M)$，其中 $M$ 为题目中数字的最大值。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sum(self, num1: int, num2: int) -> int:
        num1, num2 = num1 & 0xFFFFFFFF, num2 & 0xFFFFFFFF
        while num2:
            carry = ((num1 & num2) << 1) & 0xFFFFFFFF
            num1, num2 = num1 ^ num2, carry
        return num1 if num1 < 0x80000000 else ~(num1 ^ 0xFFFFFFFF)
```

#### Java

```java
class Solution {
    public int sum(int num1, int num2) {
        while (num2 != 0) {
            int carry = (num1 & num2) << 1;
            num1 ^= num2;
            num2 = carry;
        }
        return num1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int sum(int num1, int num2) {
        while (num2) {
            unsigned int carry = (unsigned int) (num1 & num2) << 1;
            num1 ^= num2;
            num2 = carry;
        }
        return num1;
    }
};
```

#### Go

```go
func sum(num1 int, num2 int) int {
	for num2 != 0 {
		carry := (num1 & num2) << 1
		num1 ^= num2
		num2 = carry
	}
	return num1
}
```

#### TypeScript

```ts
function sum(num1: number, num2: number): number {
    while (num2) {
        const carry = (num1 & num2) << 1;
        num1 ^= num2;
        num2 = carry;
    }
    return num1;
}
```

#### Rust

```rust
impl Solution {
    pub fn sum(num1: i32, num2: i32) -> i32 {
        let mut num1 = num1;
        let mut num2 = num2;
        while num2 != 0 {
            let carry = (num1 & num2) << 1;
            num1 ^= num2;
            num2 = carry;
        }
        num1
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2236. 判断根结点是否等于子结点之和](https://leetcode.cn/problems/root-equals-sum-of-children){#2236}

{{< tabs "2236" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def checkTree(self, root: Optional[TreeNode]) -> bool:
        return root.val == root.left.val + root.right.val
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
    public boolean checkTree(TreeNode root) {
        return root.val == root.left.val + root.right.val;
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
    bool checkTree(TreeNode* root) {
        return root->val == root->left->val + root->right->val;
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
func checkTree(root *TreeNode) bool {
	return root.Val == root.Left.Val+root.Right.Val
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

function checkTree(root: TreeNode | null): boolean {
    return root.val === root.left.val + root.right.val;
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
    pub fn check_tree(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        let node = root.as_ref().unwrap().borrow();
        let left = node.left.as_ref().unwrap().borrow().val;
        let right = node.right.as_ref().unwrap().borrow().val;
        node.val == left + right
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

bool checkTree(struct TreeNode* root) {
    return root->val == root->left->val + root->right->val;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 <strong>二叉树 </strong>的根结点&nbsp;<code>root</code>，该二叉树由恰好&nbsp;<code>3</code>&nbsp;个结点组成：根结点、左子结点和右子结点。</p>

<p>如果根结点值等于两个子结点值之和，返回&nbsp;<code>true</code>&nbsp;，否则返回<em>&nbsp;</em><code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2236.Root%20Equals%20Sum%20of%20Children/images/graph3drawio.png" style="width: 281px; height: 199px;" />
<pre>
<strong>输入：</strong>root = [10,4,6]
<strong>输出：</strong>true
<strong>解释：</strong>根结点、左子结点和右子结点的值分别是 10 、4 和 6 。
由于 10 等于 4 + 6 ，因此返回 true 。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2236.Root%20Equals%20Sum%20of%20Children/images/graph3drawio-1.png" style="width: 281px; height: 199px;" />
<pre>
<strong>输入：</strong>root = [5,3,1]
<strong>输出：</strong>false
<strong>解释：</strong>根结点、左子结点和右子结点的值分别是 5 、3 和 1 。
由于 5 不等于 3 + 1 ，因此返回 false 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树只包含根结点、左子结点和右子结点</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：直接判断

我们直接判断根节点的值是否等于左右子节点的值之和即可。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

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
    def checkTree(self, root: Optional[TreeNode]) -> bool:
        return root.val == root.left.val + root.right.val
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
    public boolean checkTree(TreeNode root) {
        return root.val == root.left.val + root.right.val;
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
    bool checkTree(TreeNode* root) {
        return root->val == root->left->val + root->right->val;
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
func checkTree(root *TreeNode) bool {
	return root.Val == root.Left.Val+root.Right.Val
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

function checkTree(root: TreeNode | null): boolean {
    return root.val === root.left.val + root.right.val;
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
    pub fn check_tree(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        let node = root.as_ref().unwrap().borrow();
        let left = node.left.as_ref().unwrap().borrow().val;
        let right = node.right.as_ref().unwrap().borrow().val;
        node.val == left + right
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

bool checkTree(struct TreeNode* root) {
    return root->val == root->left->val + root->right->val;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2237. 计算街道上满足所需亮度的位置数量 🔒](https://leetcode.cn/problems/count-positions-on-street-with-required-brightness){#2237}

{{< tabs "2237" >}}

{{% tab "python" %}}
```python
class Solution:
    def meetRequirement(
        self, n: int, lights: List[List[int]], requirement: List[int]
    ) -> int:
        d = [0] * (n + 1)
        for p, r in lights:
            i, j = max(0, p - r), min(n - 1, p + r)
            d[i] += 1
            d[j + 1] -= 1
        return sum(s >= r for s, r in zip(accumulate(d), requirement))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int meetRequirement(int n, int[][] lights, int[] requirement) {
        int[] d = new int[n + 1];
        for (int[] e : lights) {
            int i = Math.max(0, e[0] - e[1]);
            int j = Math.min(n - 1, e[0] + e[1]);
            ++d[i];
            --d[j + 1];
        }
        int s = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            s += d[i];
            if (s >= requirement[i]) {
                ++ans;
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
    int meetRequirement(int n, vector<vector<int>>& lights, vector<int>& requirement) {
        vector<int> d(n + 1);
        for (const auto& e : lights) {
            int i = max(0, e[0] - e[1]), j = min(n - 1, e[0] + e[1]);
            ++d[i];
            --d[j + 1];
        }
        int s = 0, ans = 0;
        for (int i = 0; i < n; ++i) {
            s += d[i];
            if (s >= requirement[i]) {
                ++ans;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func meetRequirement(n int, lights [][]int, requirement []int) (ans int) {
	d := make([]int, n+1)
	for _, e := range lights {
		i, j := max(0, e[0]-e[1]), min(n-1, e[0]+e[1])
		d[i]++
		d[j+1]--
	}
	s := 0
	for i, r := range requirement {
		s += d[i]
		if s >= r {
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function meetRequirement(n: number, lights: number[][], requirement: number[]): number {
    const d: number[] = Array(n + 1).fill(0);
    for (const [p, r] of lights) {
        const [i, j] = [Math.max(0, p - r), Math.min(n - 1, p + r)];
        ++d[i];
        --d[j + 1];
    }
    let [ans, s] = [0, 0];
    for (let i = 0; i < n; ++i) {
        s += d[i];
        if (s >= requirement[i]) {
            ++ans;
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

<p>给你一个整数 <code>n</code>。一条完全笔直的街道用一条从 <code>0</code> 到 <code>n - 1</code> 的数轴表示。给你一个二维整数数组 <code>lights</code>，表示街道上的路灯。每个 <code>lights[i] = [position<sub>i</sub>, range<sub>i</sub>]</code>&nbsp;表示在位置 <code>position<sub>i</sub></code> 有一盏路灯，从 <code>[max(0, position<sub>i</sub> - range<sub>i</sub>), min(n - 1, position<sub>i</sub> + range<sub>i</sub>)]</code>&nbsp;(<strong>包含边界</strong>) 开始照亮该区域。</p>

<p>位置 <code>p</code> 的&nbsp;<strong>亮度&nbsp;</strong>定义为点亮位置 <code>p</code> 的路灯的数量。给定一个大小为 <code>n</code> 的整数数组 <code>requirement</code>，数组的&nbsp;<strong>下标从 0 开始</strong>，其中 <code>requirement[i]</code> 是街道上第 <code>i</code> 个位置的最小&nbsp;<strong>亮度</strong>。</p>

<p>返回<em>街道上 <code>0</code> 到 <code>n - 1</code> 之间&nbsp;<strong>亮度至少满足</strong>&nbsp;</em><code>requirement[i]</code><em> 的位置 <code>i</code> 的数量。</em></p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2237.Count%20Positions%20on%20Street%20With%20Required%20Brightness/images/screenshot-2022-04-11-at-22-24-43-diagramdrawio-diagramsnet.png" style="height: 150px; width: 579px;" />
<pre>
<strong>输入:</strong> n = 5, lights = [[0,1],[2,1],[3,2]], requirement = [0,2,1,4,1]
<strong>输出:</strong> 4
<strong>解释:</strong>
- 第一盏路灯照亮区域范围为 [max(0,0 - 1)， min(n - 1,0 + 1)] =[0,1](含边界)。
- 第二盏路灯的点亮范围为 [max(0,2 - 1)， min(n - 1,2 + 1)] =[1,3](含边界)。
- 第三盏路灯照亮区域范围为 [max(0,3 - 2)， min(n - 1,3 + 2)] =[1,4](含边界)。

-   位置 0 被第一盏路灯覆盖。它被 1 个路灯覆盖，大于 requirement[0]。
-   位置 1 被第一、第二和第三个路灯覆盖。被 3 个路灯覆盖，大于 requirement[1]。
-   位置 2 由第二和第三路灯覆盖。被 2 个路灯覆盖，大于 requirement[2]。
-   位置 3 由第二和第三路灯覆盖。它被 2 个路灯覆盖，比 requirement[3] 少。
-   位置 4 被第三个路灯覆盖。它被 1 盏路灯覆盖，等于 requirement[4]。

位置 0、1、2、4 满足要求，因此返回4。

</pre>

<p><strong class="example">示例&nbsp;2:</strong></p>

<pre>
<strong>输入:</strong> n = 1, lights = [[0,1]], requirement = [2]
<strong>输出:</strong> 0
<strong>解释:</strong>
- 第一盏路灯照亮区域范围为 [max(0,0 - 1)， min(n - 1,0 + 1)] =[0,0](含边界)。
- 位置 0 被第一盏路灯覆盖。它被 1 个路灯覆盖，比 requirement[0] 少。
- 返回0，因为没有位置满足亮度要求。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= lights.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= position<sub>i</sub> &lt; n</code></li>
	<li><code>0 &lt;= range<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
	<li><code>requirement.length == n</code></li>
	<li><code>0 &lt;= requirement[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：差分数组

对一段连续的区间 $[i, j]$ 同时加上一个值 $v$，可以通过差分数组来实现。

我们定义一个长度为 $n + 1$ 的数组 $\textit{d}$，接下来对于每个路灯，我们计算出它的左边界 $i = \max(0, p - r)$ 和右边界 $j = \min(n - 1, p + r)$，然后将 $\textit{d}[i]$ 加上 $1$，将 $\textit{d}[j + 1]$ 减去 $1$。

然后，我们对 $\textit{d}$ 进行前缀和运算，对于每个位置 $i$，如果 $\textit{d}[i]$ 的前缀和大于等于 $\textit{requirement}[i]$，则说明该位置满足要求，将答案加一。

最后返回答案即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为路灯数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def meetRequirement(
        self, n: int, lights: List[List[int]], requirement: List[int]
    ) -> int:
        d = [0] * (n + 1)
        for p, r in lights:
            i, j = max(0, p - r), min(n - 1, p + r)
            d[i] += 1
            d[j + 1] -= 1
        return sum(s >= r for s, r in zip(accumulate(d), requirement))
```

#### Java

```java
class Solution {
    public int meetRequirement(int n, int[][] lights, int[] requirement) {
        int[] d = new int[n + 1];
        for (int[] e : lights) {
            int i = Math.max(0, e[0] - e[1]);
            int j = Math.min(n - 1, e[0] + e[1]);
            ++d[i];
            --d[j + 1];
        }
        int s = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            s += d[i];
            if (s >= requirement[i]) {
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
    int meetRequirement(int n, vector<vector<int>>& lights, vector<int>& requirement) {
        vector<int> d(n + 1);
        for (const auto& e : lights) {
            int i = max(0, e[0] - e[1]), j = min(n - 1, e[0] + e[1]);
            ++d[i];
            --d[j + 1];
        }
        int s = 0, ans = 0;
        for (int i = 0; i < n; ++i) {
            s += d[i];
            if (s >= requirement[i]) {
                ++ans;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func meetRequirement(n int, lights [][]int, requirement []int) (ans int) {
	d := make([]int, n+1)
	for _, e := range lights {
		i, j := max(0, e[0]-e[1]), min(n-1, e[0]+e[1])
		d[i]++
		d[j+1]--
	}
	s := 0
	for i, r := range requirement {
		s += d[i]
		if s >= r {
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function meetRequirement(n: number, lights: number[][], requirement: number[]): number {
    const d: number[] = Array(n + 1).fill(0);
    for (const [p, r] of lights) {
        const [i, j] = [Math.max(0, p - r), Math.min(n - 1, p + r)];
        ++d[i];
        --d[j + 1];
    }
    let [ans, s] = [0, 0];
    for (let i = 0; i < n; ++i) {
        s += d[i];
        if (s >= requirement[i]) {
            ++ans;
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

# [2238. 司机成为乘客的次数 🔒](https://leetcode.cn/problems/number-of-times-a-driver-was-a-passenger){#2238}

{{< tabs "2238" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH T AS (SELECT DISTINCT driver_id FROM Rides)
SELECT t.driver_id, COUNT(passenger_id) AS cnt
FROM
    T AS t
    LEFT JOIN Rides AS r ON t.driver_id = r.passenger_id
GROUP BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Rides</code></p>

<pre>
+--------------+------+
| Column Name  | Type |
+--------------+------+
| ride_id      | int  |
| driver_id    | int  |
| passenger_id | int  |
+--------------+------+
ride_id 是该表的主键（具有唯一值的列）。
该表的每一行都包含驾驶员的 ID 和在 ride_id 中乘车的乘客的 ID。
注意 driver_id != passenger_id。</pre>

<p>&nbsp;</p>

<p>编写解决方案，获取每个司机的 ID 和他们作为乘客的次数。</p>

<p data-group="1-1">以&nbsp;<strong>任意顺序&nbsp;</strong>返回结果表。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
Rides 表:
+---------+-----------+--------------+
| ride_id | driver_id | passenger_id |
+---------+-----------+--------------+
| 1       | 7         | 1            |
| 2       | 7         | 2            |
| 3       | 11        | 1            |
| 4       | 11        | 7            |
| 5       | 11        | 7            |
| 6       | 11        | 3            |
+---------+-----------+--------------+
<strong>输出:</strong> 
+-----------+-----+
| driver_id | cnt |
+-----------+-----+
| 7         | 2   |
| 11        | 0   |
+-----------+-----+
<strong>解释:</strong> 
在所有给定的行程中有两名司机: 7 和 11.
ID = 7 的司机曾两次成为乘客。
ID = 11 的司机从来不是乘客。</pre>

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
WITH T AS (SELECT DISTINCT driver_id FROM Rides)
SELECT t.driver_id, COUNT(passenger_id) AS cnt
FROM
    T AS t
    LEFT JOIN Rides AS r ON t.driver_id = r.passenger_id
GROUP BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2239. 找到最接近 0 的数字](https://leetcode.cn/problems/find-closest-number-to-zero){#2239}

{{< tabs "2239" >}}

{{% tab "python" %}}
```python
class Solution:
    def findClosestNumber(self, nums: List[int]) -> int:
        ans, d = 0, inf
        for x in nums:
            if (y := abs(x)) < d or (y == d and x > ans):
                ans, d = x, y
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findClosestNumber(int[] nums) {
        int ans = 0, d = 1 << 30;
        for (int x : nums) {
            int y = Math.abs(x);
            if (y < d || (y == d && x > ans)) {
                ans = x;
                d = y;
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
    int findClosestNumber(vector<int>& nums) {
        int ans = 0, d = 1 << 30;
        for (int x : nums) {
            int y = abs(x);
            if (y < d || (y == d && x > ans)) {
                ans = x;
                d = y;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findClosestNumber(nums []int) int {
	ans, d := 0, 1<<30
	for _, x := range nums {
		if y := abs(x); y < d || (y == d && x > ans) {
			ans, d = x, y
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
function findClosestNumber(nums: number[]): number {
    let [ans, d] = [0, 1 << 30];
    for (const x of nums) {
        const y = Math.abs(x);
        if (y < d || (y == d && x > ans)) {
            [ans, d] = [x, y];
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

<p>给你一个长度为 <code>n</code>&nbsp;的整数数组&nbsp;<code>nums</code>&nbsp;，请你返回 <code>nums</code>&nbsp;中最 <strong>接近</strong>&nbsp;<code>0</code>&nbsp;的数字。如果有多个答案，请你返回它们中的 <strong>最大值</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [-4,-2,1,4,8]
<b>输出：</b>1
<strong>解释：</strong>
-4 到 0 的距离为 |-4| = 4 。
-2 到 0 的距离为 |-2| = 2 。
1 到 0 的距离为 |1| = 1 。
4 到 0 的距离为 |4| = 4 。
8 到 0 的距离为 |8| = 8 。
所以，数组中距离 0 最近的数字为 1 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [2,-1,1]
<b>输出：</b>1
<b>解释：</b>1 和 -1 都是距离 0 最近的数字，所以返回较大值 1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：一次遍历

我们定义一个变量 $\textit{d}$ 来记录当前最小的距离，初始时 $\textit{d}=\infty$。然后我们遍历数组，对于每个元素 $x$，我们计算 $y=|x|$，如果 $y \lt d$ 或者 $y=d$ 且 $x \gt \textit{ans}$，我们就更新答案 $\textit{ans}=x$ 和 $\textit{d}=y$。

遍历结束后返回答案即可。

时间复杂度 $O(n)$，其中 $n$ 是数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findClosestNumber(self, nums: List[int]) -> int:
        ans, d = 0, inf
        for x in nums:
            if (y := abs(x)) < d or (y == d and x > ans):
                ans, d = x, y
        return ans
```

#### Java

```java
class Solution {
    public int findClosestNumber(int[] nums) {
        int ans = 0, d = 1 << 30;
        for (int x : nums) {
            int y = Math.abs(x);
            if (y < d || (y == d && x > ans)) {
                ans = x;
                d = y;
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
    int findClosestNumber(vector<int>& nums) {
        int ans = 0, d = 1 << 30;
        for (int x : nums) {
            int y = abs(x);
            if (y < d || (y == d && x > ans)) {
                ans = x;
                d = y;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findClosestNumber(nums []int) int {
	ans, d := 0, 1<<30
	for _, x := range nums {
		if y := abs(x); y < d || (y == d && x > ans) {
			ans, d = x, y
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
function findClosestNumber(nums: number[]): number {
    let [ans, d] = [0, 1 << 30];
    for (const x of nums) {
        const y = Math.abs(x);
        if (y < d || (y == d && x > ans)) {
            [ans, d] = [x, y];
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
