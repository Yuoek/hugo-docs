---
title: "0120_三角形最小路径和"
date: 2025-10-08T18:45:43+08:00
weight: 3
tags: [二叉树, 动态规划, 双指针, 哈希表, 回溯, 字符串, 并查集, 广度优先搜索, 数组, 树, 深度优先搜索, 贪心]
---

{{< markmap >}}
### [0120_三角形最小路径和](#120)
#### [数组](#120)
#### [动态规划](#120)
### [0121_买卖股票的最佳时机](#121)
#### [数组](#121)
#### [动态规划](#121)
### [0122_买卖股票的最佳时机 II](#122)
#### [贪心](#122)
#### [数组](#122)
#### [动态规划](#122)
### [0123_买卖股票的最佳时机 III](#123)
#### [数组](#123)
#### [动态规划](#123)
### [0124_二叉树中的最大路径和](#124)
#### [树](#124)
#### [深度优先搜索](#124)
#### [动态规划](#124)
#### [二叉树](#124)
### [0125_验证回文串](#125)
#### [双指针](#125)
#### [字符串](#125)
### [0126_单词接龙 II](#126)
#### [广度优先搜索](#126)
#### [哈希表](#126)
#### [字符串](#126)
#### [回溯](#126)
### [0127_单词接龙](#127)
#### [广度优先搜索](#127)
#### [哈希表](#127)
#### [字符串](#127)
### [0128_最长连续序列](#128)
#### [并查集](#128)
#### [数组](#128)
#### [哈希表](#128)
### [0129_求根节点到叶节点数字之和](#129)
#### [树](#129)
#### [深度优先搜索](#129)
#### [二叉树](#129)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0120_三角形最小路径和
___
#### 数组
___
#### 动态规划
---
### 0121_买卖股票的最佳时机
___
#### 数组
___
#### 动态规划
---
### 0122_买卖股票的最佳时机 II
___
#### 贪心
___
#### 数组
___
#### 动态规划
---
### 0123_买卖股票的最佳时机 III
___
#### 数组
___
#### 动态规划
---
### 0124_二叉树中的最大路径和
___
#### 树
___
#### 深度优先搜索
___
#### 动态规划
___
#### 二叉树
---
### 0125_验证回文串
___
#### 双指针
___
#### 字符串
---
### 0126_单词接龙 II
___
#### 广度优先搜索
___
#### 哈希表
___
#### 字符串
___
#### 回溯
---
### 0127_单词接龙
___
#### 广度优先搜索
___
#### 哈希表
___
#### 字符串
---
### 0128_最长连续序列
___
#### 并查集
___
#### 数组
___
#### 哈希表
---
### 0129_求根节点到叶节点数字之和
___
#### 树
___
#### 深度优先搜索
___
#### 二叉树
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二叉树 | 动态规划 | 双指针 |
| 哈希表 | 回溯 | 字符串 |
| 并查集 | 广度优先搜索 | 数组 |
| 树 | 深度优先搜索 | 贪心 |

# [120. 三角形最小路径和](https://leetcode.cn/problems/triangle){#120}

{{< tabs "120" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        n = len(triangle)
        for i in range(n - 2, -1, -1):
            for j in range(i + 1):
                triangle[i][j] = (
                    min(triangle[i + 1][j], triangle[i + 1][j + 1]) + triangle[i][j]
                )
        return triangle[0][0]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        for (int i = triangle.size() - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                int x = triangle.get(i).get(j);
                int y = Math.min(triangle.get(i + 1).get(j), triangle.get(i + 1).get(j + 1));
                triangle.get(i).set(j, x + y);
            }
        }
        return triangle.get(0).get(0);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = triangle.size() - 2; ~i; --i) {
            for (int j = 0; j <= i; ++j) {
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        return triangle[0][0];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumTotal(triangle [][]int) int {
	for i := len(triangle) - 2; i >= 0; i-- {
		for j := 0; j <= i; j++ {
			triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1])
		}
	}
	return triangle[0][0]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumTotal(triangle: number[][]): number {
    for (let i = triangle.length - 2; ~i; --i) {
        for (let j = 0; j <= i; ++j) {
            triangle[i][j] += Math.min(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }
    return triangle[0][0];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn minimum_total(triangle: Vec<Vec<i32>>) -> i32 {
        let mut triangle = triangle;
        for i in (0..triangle.len() - 1).rev() {
            for j in 0..=i {
                triangle[i][j] += triangle[i + 1][j].min(triangle[i + 1][j + 1]);
            }
        }
        triangle[0][0]
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个三角形 <code>triangle</code> ，找出自顶向下的最小路径和。</p>

<p>每一步只能移动到下一行中相邻的结点上。<strong>相邻的结点 </strong>在这里指的是 <strong>下标</strong> 与 <strong>上一层结点下标</strong> 相同或者等于 <strong>上一层结点下标 + 1</strong> 的两个结点。也就是说，如果正位于当前行的下标 <code>i</code> ，那么下一步可以移动到下一行的下标 <code>i</code> 或 <code>i + 1</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
<strong>输出：</strong>11
<strong>解释：</strong>如下面简图所示：
   <strong>2</strong>
  <strong>3</strong> 4
 6 <strong>5</strong> 7
4 <strong>1</strong> 8 3
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>triangle = [[-10]]
<strong>输出：</strong>-10
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= triangle.length <= 200</code></li>
	<li><code>triangle[0].length == 1</code></li>
	<li><code>triangle[i].length == triangle[i - 1].length + 1</code></li>
	<li><code>-10<sup>4</sup> <= triangle[i][j] <= 10<sup>4</sup></code></li>
</ul>

<p> </p>

<p><strong>进阶：</strong></p>

<ul>
	<li>你可以只使用 <code>O(n)</code> 的额外空间（<code>n</code> 为三角形的总行数）来解决这个问题吗？</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示从三角形底部走到位置 $(i, j)$ 的最小路径和。这里的位置 $(i, j)$ 指的是三角形中第 $i$ 行第 $j$ 列（均从 $0$ 开始编号）的位置。那么我们有如下的状态转移方程：

$$
f[i][j] = \min(f[i + 1][j], f[i + 1][j + 1]) + triangle[i][j]
$$

答案即为 $f[0][0]$。

我们注意到，状态 $f[i][j]$ 仅与状态 $f[i + 1][j]$ 和状态 $f[i + 1][j + 1]$ 有关，因此我们可以使用一维数组代替二维数组，将空间复杂度从 $O(n^2)$ 降低至 $O(n)$。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 是三角形的行数。

更进一步，我们还可以直接复用 $triangle$ 作为 $f$ 数组，这样就无需再额外创建 $f$ 数组，空间复杂度降低至 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        n = len(triangle)
        f = [[0] * (n + 1) for _ in range(n + 1)]
        for i in range(n - 1, -1, -1):
            for j in range(i + 1):
                f[i][j] = min(f[i + 1][j], f[i + 1][j + 1]) + triangle[i][j]
        return f[0][0]
```

#### Java

```java
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int n = triangle.size();
        int[] f = new int[n + 1];
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                f[j] = Math.min(f[j], f[j + 1]) + triangle.get(i).get(j);
            }
        }
        return f[0];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int f[n + 1];
        memset(f, 0, sizeof(f));
        for (int i = n - 1; ~i; --i) {
            for (int j = 0; j <= i; ++j) {
                f[j] = min(f[j], f[j + 1]) + triangle[i][j];
            }
        }
        return f[0];
    }
};
```

#### Go

```go
func minimumTotal(triangle [][]int) int {
	n := len(triangle)
	f := make([]int, n+1)
	for i := n - 1; i >= 0; i-- {
		for j := 0; j <= i; j++ {
			f[j] = min(f[j], f[j+1]) + triangle[i][j]
		}
	}
	return f[0]
}
```

#### TypeScript

```ts
function minimumTotal(triangle: number[][]): number {
    const n = triangle.length;
    const f: number[] = Array(n + 1).fill(0);
    for (let i = n - 1; ~i; --i) {
        for (let j = 0; j <= i; ++j) {
            f[j] = Math.min(f[j], f[j + 1]) + triangle[i][j];
        }
    }
    return f[0];
}
```

#### Rust

```rust
impl Solution {
    pub fn minimum_total(triangle: Vec<Vec<i32>>) -> i32 {
        let n = triangle.len();
        let mut f = vec![0; n + 1];
        for i in (0..n).rev() {
            for j in 0..=i {
                f[j] = f[j].min(f[j + 1]) + triangle[i][j];
            }
        }
        f[0]
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
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        n = len(triangle)
        f = [0] * (n + 1)
        for i in range(n - 1, -1, -1):
            for j in range(i + 1):
                f[j] = min(f[j], f[j + 1]) + triangle[i][j]
        return f[0]
```

#### Java

```java
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        for (int i = triangle.size() - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                int x = triangle.get(i).get(j);
                int y = Math.min(triangle.get(i + 1).get(j), triangle.get(i + 1).get(j + 1));
                triangle.get(i).set(j, x + y);
            }
        }
        return triangle.get(0).get(0);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = triangle.size() - 2; ~i; --i) {
            for (int j = 0; j <= i; ++j) {
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        return triangle[0][0];
    }
};
```

#### Go

```go
func minimumTotal(triangle [][]int) int {
	for i := len(triangle) - 2; i >= 0; i-- {
		for j := 0; j <= i; j++ {
			triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1])
		}
	}
	return triangle[0][0]
}
```

#### TypeScript

```ts
function minimumTotal(triangle: number[][]): number {
    for (let i = triangle.length - 2; ~i; --i) {
        for (let j = 0; j <= i; ++j) {
            triangle[i][j] += Math.min(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }
    return triangle[0][0];
}
```

#### Rust

```rust
impl Solution {
    pub fn minimum_total(triangle: Vec<Vec<i32>>) -> i32 {
        let mut triangle = triangle;
        for i in (0..triangle.len() - 1).rev() {
            for j in 0..=i {
                triangle[i][j] += triangle[i + 1][j].min(triangle[i + 1][j + 1]);
            }
        }
        triangle[0][0]
    }
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
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        n = len(triangle)
        for i in range(n - 2, -1, -1):
            for j in range(i + 1):
                triangle[i][j] = (
                    min(triangle[i + 1][j], triangle[i + 1][j + 1]) + triangle[i][j]
                )
        return triangle[0][0]
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [121. 买卖股票的最佳时机](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock){#121}

{{< tabs "121" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        ans, mi = 0, inf
        for v in prices:
            ans = max(ans, v - mi)
            mi = min(mi, v)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxProfit(int[] prices) {
        int ans = 0, mi = prices[0];
        for (int v : prices) {
            ans = Math.max(ans, v - mi);
            mi = Math.min(mi, v);
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
    int maxProfit(vector<int>& prices) {
        int ans = 0, mi = prices[0];
        for (int& v : prices) {
            ans = max(ans, v - mi);
            mi = min(mi, v);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxProfit(prices []int) (ans int) {
	mi := prices[0]
	for _, v := range prices {
		ans = max(ans, v-mi)
		mi = min(mi, v)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxProfit(prices: number[]): number {
    let ans = 0;
    let mi = prices[0];
    for (const v of prices) {
        ans = Math.max(ans, v - mi);
        mi = Math.min(mi, v);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut ans = 0;
        let mut mi = prices[0];
        for &v in &prices {
            ans = ans.max(v - mi);
            mi = mi.min(v);
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function (prices) {
    let ans = 0;
    let mi = prices[0];
    for (const v of prices) {
        ans = Math.max(ans, v - mi);
        mi = Math.min(mi, v);
    }
    return ans;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int MaxProfit(int[] prices) {
        int ans = 0, mi = prices[0];
        foreach (int v in prices) {
            ans = Math.Max(ans, v - mi);
            mi = Math.Min(mi, v);
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
     * @param Integer[] $prices
     * @return Integer
     */
    function maxProfit($prices) {
        $ans = 0;
        $mi = $prices[0];
        foreach ($prices as $v) {
            $ans = max($ans, $v - $mi);
            $mi = min($mi, $v);
        }
        return $ans;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个数组 <code>prices</code> ，它的第 <code>i</code> 个元素 <code>prices[i]</code> 表示一支给定股票第 <code>i</code> 天的价格。</p>

<p>你只能选择 <strong>某一天</strong> 买入这只股票，并选择在 <strong>未来的某一个不同的日子</strong> 卖出该股票。设计一个算法来计算你所能获取的最大利润。</p>

<p>返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 <code>0</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>[7,1,5,3,6,4]
<strong>输出：</strong>5
<strong>解释：</strong>在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>prices = [7,6,4,3,1]
<strong>输出：</strong>0
<strong>解释：</strong>在这种情况下, 没有交易完成, 所以最大利润为 0。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= prices.length <= 10<sup>5</sup></code></li>
	<li><code>0 <= prices[i] <= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举 + 维护前缀最小值

我们可以枚举数组 $nums$ 每个元素作为卖出价格，那么我们需要在前面找到一个最小值作为买入价格，这样才能使得利润最大化。

因此，我们用一个变量 $mi$ 维护数组 $nums$ 的前缀最小值。接下来遍历数组 $nums$，对于每个元素 $v$，计算其与前面元素的最小值 $mi$ 的差值，更新答案为差值的最大值。然后更新 $mi = min(mi, v)$。继续遍历数组 $nums$，直到遍历结束。

最后返回答案即可。

时间复杂度 $O(n)$，其中 $n$ 是数组 $nums$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        ans, mi = 0, inf
        for v in prices:
            ans = max(ans, v - mi)
            mi = min(mi, v)
        return ans
```

#### Java

```java
class Solution {
    public int maxProfit(int[] prices) {
        int ans = 0, mi = prices[0];
        for (int v : prices) {
            ans = Math.max(ans, v - mi);
            mi = Math.min(mi, v);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, mi = prices[0];
        for (int& v : prices) {
            ans = max(ans, v - mi);
            mi = min(mi, v);
        }
        return ans;
    }
};
```

#### Go

```go
func maxProfit(prices []int) (ans int) {
	mi := prices[0]
	for _, v := range prices {
		ans = max(ans, v-mi)
		mi = min(mi, v)
	}
	return
}
```

#### TypeScript

```ts
function maxProfit(prices: number[]): number {
    let ans = 0;
    let mi = prices[0];
    for (const v of prices) {
        ans = Math.max(ans, v - mi);
        mi = Math.min(mi, v);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut ans = 0;
        let mut mi = prices[0];
        for &v in &prices {
            ans = ans.max(v - mi);
            mi = mi.min(v);
        }
        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function (prices) {
    let ans = 0;
    let mi = prices[0];
    for (const v of prices) {
        ans = Math.max(ans, v - mi);
        mi = Math.min(mi, v);
    }
    return ans;
};
```

#### C#

```cs
public class Solution {
    public int MaxProfit(int[] prices) {
        int ans = 0, mi = prices[0];
        foreach (int v in prices) {
            ans = Math.Max(ans, v - mi);
            mi = Math.Min(mi, v);
        }
        return ans;
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param Integer[] $prices
     * @return Integer
     */
    function maxProfit($prices) {
        $ans = 0;
        $mi = $prices[0];
        foreach ($prices as $v) {
            $ans = max($ans, $v - $mi);
            $mi = min($mi, $v);
        }
        return $ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [122. 买卖股票的最佳时机 II](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii){#122}

{{< tabs "122" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        f = [-prices[0], 0]
        for i in range(1, n):
            g = [0] * 2
            g[0] = max(f[0], f[1] - prices[i])
            g[1] = max(f[1], f[0] + prices[i])
            f = g
        return f[1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int[] f = new int[] {-prices[0], 0};
        for (int i = 1; i < n; ++i) {
            int[] g = new int[2];
            g[0] = Math.max(f[0], f[1] - prices[i]);
            g[1] = Math.max(f[1], f[0] + prices[i]);
            f = g;
        }
        return f[1];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int f[2] = {-prices[0], 0};
        for (int i = 1; i < n; ++i) {
            int g[2];
            g[0] = max(f[0], f[1] - prices[i]);
            g[1] = max(f[1], f[0] + prices[i]);
            f[0] = g[0], f[1] = g[1];
        }
        return f[1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxProfit(prices []int) int {
	n := len(prices)
	f := [2]int{-prices[0], 0}
	for i := 1; i < n; i++ {
		g := [2]int{}
		g[0] = max(f[0], f[1]-prices[i])
		g[1] = max(f[1], f[0]+prices[i])
		f = g
	}
	return f[1]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxProfit(prices: number[]): number {
    let ans = 0;
    for (let i = 1; i < prices.length; i++) {
        ans += Math.max(0, prices[i] - prices[i - 1]);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut res = 0;
        for i in 1..prices.len() {
            res += (0).max(prices[i] - prices[i - 1]);
        }
        res
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function (prices) {
    let ans = 0;
    for (let i = 1; i < prices.length; i++) {
        ans += Math.max(0, prices[i] - prices[i - 1]);
    }
    return ans;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int MaxProfit(int[] prices) {
        int f1 = -prices[0], f2 = 0;
        for (int i = 1; i < prices.Length; ++i)
        {
            f1 = Math.Max(f1, f2 - prices[i]);
            f2 = Math.Max(f2, f1 + prices[i]);
        }
        return f2;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>prices</code> ，其中&nbsp;<code>prices[i]</code> 表示某支股票第 <code>i</code> 天的价格。</p>

<p>在每一天，你可以决定是否购买和/或出售股票。你在任何时候&nbsp;<strong>最多</strong>&nbsp;只能持有 <strong>一股</strong> 股票。你也可以先购买，然后在 <strong>同一天</strong> 出售。</p>

<p>返回 <em>你能获得的 <strong>最大</strong> 利润</em>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>prices = [7,1,5,3,6,4]
<strong>输出：</strong>7
<strong>解释：</strong>在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4。
随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6 - 3 = 3。
最大总利润为 4 + 3 = 7 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>prices = [1,2,3,4,5]
<strong>输出：</strong>4
<strong>解释：</strong>在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4。
最大总利润为 4 。</pre>

<p><strong>示例&nbsp;3：</strong></p>

<pre>
<strong>输入：</strong>prices = [7,6,4,3,1]
<strong>输出：</strong>0
<strong>解释：</strong>在这种情况下, 交易无法获得正利润，所以不参与交易可以获得最大利润，最大利润为 0。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= prices.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= prices[i] &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

从第二天开始，如果当天股价大于前一天股价，则在前一天买入，当天卖出，即可获得利润。如果当天股价小于前一天股价，则不买入，不卖出。也即是说，所有上涨交易日都做买卖，所有下跌交易日都不做买卖，最终获得的利润是最大的。

时间复杂度 $O(n)$，其中 $n$ 为数组 `prices` 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        return sum(max(0, b - a) for a, b in pairwise(prices))
```

#### Java

```java
class Solution {
    public int maxProfit(int[] prices) {
        int ans = 0;
        for (int i = 1; i < prices.length; ++i) {
            ans += Math.max(0, prices[i] - prices[i - 1]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for (int i = 1; i < prices.size(); ++i) ans += max(0, prices[i] - prices[i - 1]);
        return ans;
    }
};
```

#### Go

```go
func maxProfit(prices []int) (ans int) {
	for i, v := range prices[1:] {
		t := v - prices[i]
		if t > 0 {
			ans += t
		}
	}
	return
}
```

#### TypeScript

```ts
function maxProfit(prices: number[]): number {
    let ans = 0;
    for (let i = 1; i < prices.length; i++) {
        ans += Math.max(0, prices[i] - prices[i - 1]);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut res = 0;
        for i in 1..prices.len() {
            res += (0).max(prices[i] - prices[i - 1]);
        }
        res
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function (prices) {
    let ans = 0;
    for (let i = 1; i < prices.length; i++) {
        ans += Math.max(0, prices[i] - prices[i - 1]);
    }
    return ans;
};
```

#### C#

```cs
public class Solution {
    public int MaxProfit(int[] prices) {
        int ans = 0;
        for (int i = 1; i < prices.Length; ++i) {
            ans += Math.Max(0, prices[i] - prices[i - 1]);
        }
        return ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划

我们设 $f[i][j]$ 表示第 $i$ 天交易完后的最大利润，其中 $j$ 表示当前是否持有股票，持有股票时 $j=0$，不持有股票时 $j=1$。初始状态为 $f[0][0]=-prices[0]$，其余状态均为 $0$。

如果当前持有股票，那么可能是前一天就持有股票，今天什么都不做，即 $f[i][0]=f[i-1][0]$；也可能是前一天不持有股票，今天买入股票，即 $f[i][0]=f[i-1][1]-prices[i]$。

如果当前不持有股票，那么可能是前一天就不持有股票，今天什么都不做，即 $f[i][1]=f[i-1][1]$；也可能是前一天持有股票，今天卖出股票，即 $f[i][1]=f[i-1][0]+prices[i]$。

因此，我们可以写出状态转移方程：

$$
\begin{cases}
f[i][0]=\max(f[i-1][0],f[i-1][1]-prices[i])\\
f[i][1]=\max(f[i-1][1],f[i-1][0]+prices[i])
\end{cases}
$$

最终的答案即为 $f[n-1][1]$，其中 $n$ 为数组 `prices` 的长度。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 `prices` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        f = [[0] * 2 for _ in range(n)]
        f[0][0] = -prices[0]
        for i in range(1, n):
            f[i][0] = max(f[i - 1][0], f[i - 1][1] - prices[i])
            f[i][1] = max(f[i - 1][1], f[i - 1][0] + prices[i])
        return f[n - 1][1]
```

#### Java

```java
class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int[][] f = new int[n][2];
        f[0][0] = -prices[0];
        for (int i = 1; i < n; ++i) {
            f[i][0] = Math.max(f[i - 1][0], f[i - 1][1] - prices[i]);
            f[i][1] = Math.max(f[i - 1][1], f[i - 1][0] + prices[i]);
        }
        return f[n - 1][1];
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
        f[0][0] = -prices[0];
        f[0][1] = 0;
        for (int i = 1; i < n; ++i) {
            f[i][0] = max(f[i - 1][0], f[i - 1][1] - prices[i]);
            f[i][1] = max(f[i - 1][1], f[i - 1][0] + prices[i]);
        }
        return f[n - 1][1];
    }
};
```

#### Go

```go
func maxProfit(prices []int) int {
	n := len(prices)
	f := make([][2]int, n)
	f[0][0] = -prices[0]
	for i := 1; i < n; i++ {
		f[i][0] = max(f[i-1][0], f[i-1][1]-prices[i])
		f[i][1] = max(f[i-1][1], f[i-1][0]+prices[i])
	}
	return f[n-1][1]
}
```

#### C#

```cs
public class Solution {
    public int MaxProfit(int[] prices) {
        int f1 = -prices[0], f2 = 0;
        for (int i = 1; i < prices.Length; ++i)
        {
            f1 = Math.Max(f1, f2 - prices[i]);
            f2 = Math.Max(f2, f1 + prices[i]);
        }
        return f2;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三：动态规划（空间优化）

我们可以发现，在方法二中，第 $i$ 天的状态，只与第 $i-1$ 天的状态有关，因此我们可以只用两个变量来维护第 $i-1$ 天的状态，从而将空间复杂度优化到 $O(1)$。

时间复杂度 $O(n)$，其中 $n$ 为数组 `prices` 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        f = [-prices[0], 0]
        for i in range(1, n):
            g = [0] * 2
            g[0] = max(f[0], f[1] - prices[i])
            g[1] = max(f[1], f[0] + prices[i])
            f = g
        return f[1]
```

#### Java

```java
class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int[] f = new int[] {-prices[0], 0};
        for (int i = 1; i < n; ++i) {
            int[] g = new int[2];
            g[0] = Math.max(f[0], f[1] - prices[i]);
            g[1] = Math.max(f[1], f[0] + prices[i]);
            f = g;
        }
        return f[1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int f[2] = {-prices[0], 0};
        for (int i = 1; i < n; ++i) {
            int g[2];
            g[0] = max(f[0], f[1] - prices[i]);
            g[1] = max(f[1], f[0] + prices[i]);
            f[0] = g[0], f[1] = g[1];
        }
        return f[1];
    }
};
```

#### Go

```go
func maxProfit(prices []int) int {
	n := len(prices)
	f := [2]int{-prices[0], 0}
	for i := 1; i < n; i++ {
		g := [2]int{}
		g[0] = max(f[0], f[1]-prices[i])
		g[1] = max(f[1], f[0]+prices[i])
		f = g
	}
	return f[1]
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [123. 买卖股票的最佳时机 III](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii){#123}

{{< tabs "123" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # 第一次买入，第一次卖出，第二次买入，第二次卖出
        f1, f2, f3, f4 = -prices[0], 0, -prices[0], 0
        for price in prices[1:]:
            f1 = max(f1, -price)
            f2 = max(f2, f1 + price)
            f3 = max(f3, f2 - price)
            f4 = max(f4, f3 + price)
        return f4
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxProfit(int[] prices) {
        // 第一次买入，第一次卖出，第二次买入，第二次卖出
        int f1 = -prices[0], f2 = 0, f3 = -prices[0], f4 = 0;
        for (int i = 1; i < prices.length; ++i) {
            f1 = Math.max(f1, -prices[i]);
            f2 = Math.max(f2, f1 + prices[i]);
            f3 = Math.max(f3, f2 - prices[i]);
            f4 = Math.max(f4, f3 + prices[i]);
        }
        return f4;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int f1 = -prices[0], f2 = 0, f3 = -prices[0], f4 = 0;
        for (int i = 1; i < prices.size(); ++i) {
            f1 = max(f1, -prices[i]);
            f2 = max(f2, f1 + prices[i]);
            f3 = max(f3, f2 - prices[i]);
            f4 = max(f4, f3 + prices[i]);
        }
        return f4;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxProfit(prices []int) int {
	f1, f2, f3, f4 := -prices[0], 0, -prices[0], 0
	for i := 1; i < len(prices); i++ {
		f1 = max(f1, -prices[i])
		f2 = max(f2, f1+prices[i])
		f3 = max(f3, f2-prices[i])
		f4 = max(f4, f3+prices[i])
	}
	return f4
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxProfit(prices: number[]): number {
    let [f1, f2, f3, f4] = [-prices[0], 0, -prices[0], 0];
    for (let i = 1; i < prices.length; ++i) {
        f1 = Math.max(f1, -prices[i]);
        f2 = Math.max(f2, f1 + prices[i]);
        f3 = Math.max(f3, f2 - prices[i]);
        f4 = Math.max(f4, f3 + prices[i]);
    }
    return f4;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    #[allow(dead_code)]
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut f1 = -prices[0];
        let mut f2 = 0;
        let mut f3 = -prices[0];
        let mut f4 = 0;
        let n = prices.len();

        for i in 1..n {
            f1 = std::cmp::max(f1, -prices[i]);
            f2 = std::cmp::max(f2, f1 + prices[i]);
            f3 = std::cmp::max(f3, f2 - prices[i]);
            f4 = std::cmp::max(f4, f3 + prices[i]);
        }

        f4
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int MaxProfit(int[] prices) {
        int f1 = -prices[0], f2 = 0, f3 = -prices[0], f4 = 0;
        for (int i = 1; i < prices.Length; ++i) {
            f1 = Math.Max(f1, -prices[i]);
            f2 = Math.Max(f2, f1 + prices[i]);
            f3 = Math.Max(f3, f2 - prices[i]);
            f4 = Math.Max(f4, f3 + prices[i]);
        }
        return f4;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个数组，它的第<em> </em><code>i</code> 个元素是一支给定的股票在第 <code>i</code><em> </em>天的价格。</p>

<p>设计一个算法来计算你所能获取的最大利润。你最多可以完成 <strong>两笔 </strong>交易。</p>

<p><strong>注意：</strong>你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。</p>

<p> </p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入：</strong>prices = [3,3,5,0,0,3,1,4]
<strong>输出：</strong>6
<strong>解释：</strong>在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
     随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>prices = [1,2,3,4,5]
<strong>输出：</strong>4
<strong>解释：</strong>在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。   
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。   
     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>prices = [7,6,4,3,1] 
<strong>输出：</strong>0 
<strong>解释：</strong>在这个情况下, 没有交易完成, 所以最大利润为 0。</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>prices = [1]
<strong>输出：</strong>0
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= prices.length <= 10<sup>5</sup></code></li>
	<li><code>0 <= prices[i] <= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义以下几个变量，其中：

-   `f1` 表示第一次买入股票后的最大利润；
-   `f2` 表示第一次卖出股票后的最大利润；
-   `f3` 表示第二次买入股票后的最大利润；
-   `f4` 表示第二次卖出股票后的最大利润。

遍历过程中，直接使用 `f1`, `f2`, `f3`, `f4` 计算，考虑的是在同一天买入和卖出时，收益是 $0$，不会对答案产生影响。

最后返回 `f4` 即可。

时间复杂度 $O(n)$，其中 $n$ 为数组 `prices` 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # 第一次买入，第一次卖出，第二次买入，第二次卖出
        f1, f2, f3, f4 = -prices[0], 0, -prices[0], 0
        for price in prices[1:]:
            f1 = max(f1, -price)
            f2 = max(f2, f1 + price)
            f3 = max(f3, f2 - price)
            f4 = max(f4, f3 + price)
        return f4
```

#### Java

```java
class Solution {
    public int maxProfit(int[] prices) {
        // 第一次买入，第一次卖出，第二次买入，第二次卖出
        int f1 = -prices[0], f2 = 0, f3 = -prices[0], f4 = 0;
        for (int i = 1; i < prices.length; ++i) {
            f1 = Math.max(f1, -prices[i]);
            f2 = Math.max(f2, f1 + prices[i]);
            f3 = Math.max(f3, f2 - prices[i]);
            f4 = Math.max(f4, f3 + prices[i]);
        }
        return f4;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int f1 = -prices[0], f2 = 0, f3 = -prices[0], f4 = 0;
        for (int i = 1; i < prices.size(); ++i) {
            f1 = max(f1, -prices[i]);
            f2 = max(f2, f1 + prices[i]);
            f3 = max(f3, f2 - prices[i]);
            f4 = max(f4, f3 + prices[i]);
        }
        return f4;
    }
};
```

#### Go

```go
func maxProfit(prices []int) int {
	f1, f2, f3, f4 := -prices[0], 0, -prices[0], 0
	for i := 1; i < len(prices); i++ {
		f1 = max(f1, -prices[i])
		f2 = max(f2, f1+prices[i])
		f3 = max(f3, f2-prices[i])
		f4 = max(f4, f3+prices[i])
	}
	return f4
}
```

#### TypeScript

```ts
function maxProfit(prices: number[]): number {
    let [f1, f2, f3, f4] = [-prices[0], 0, -prices[0], 0];
    for (let i = 1; i < prices.length; ++i) {
        f1 = Math.max(f1, -prices[i]);
        f2 = Math.max(f2, f1 + prices[i]);
        f3 = Math.max(f3, f2 - prices[i]);
        f4 = Math.max(f4, f3 + prices[i]);
    }
    return f4;
}
```

#### Rust

```rust
impl Solution {
    #[allow(dead_code)]
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut f1 = -prices[0];
        let mut f2 = 0;
        let mut f3 = -prices[0];
        let mut f4 = 0;
        let n = prices.len();

        for i in 1..n {
            f1 = std::cmp::max(f1, -prices[i]);
            f2 = std::cmp::max(f2, f1 + prices[i]);
            f3 = std::cmp::max(f3, f2 - prices[i]);
            f4 = std::cmp::max(f4, f3 + prices[i]);
        }

        f4
    }
}
```

#### C#

```cs
public class Solution {
    public int MaxProfit(int[] prices) {
        int f1 = -prices[0], f2 = 0, f3 = -prices[0], f4 = 0;
        for (int i = 1; i < prices.Length; ++i) {
            f1 = Math.Max(f1, -prices[i]);
            f2 = Math.Max(f2, f1 + prices[i]);
            f3 = Math.Max(f3, f2 - prices[i]);
            f4 = Math.Max(f4, f3 + prices[i]);
        }
        return f4;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [124. 二叉树中的最大路径和](https://leetcode.cn/problems/binary-tree-maximum-path-sum){#124}

{{< tabs "124" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        def dfs(root: Optional[TreeNode]) -> int:
            if root is None:
                return 0
            left = max(0, dfs(root.left))
            right = max(0, dfs(root.right))
            nonlocal ans
            ans = max(ans, root.val + left + right)
            return root.val + max(left, right)

        ans = -inf
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
    private int ans = -1001;

    public int maxPathSum(TreeNode root) {
        dfs(root);
        return ans;
    }

    private int dfs(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int left = Math.max(0, dfs(root.left));
        int right = Math.max(0, dfs(root.right));
        ans = Math.max(ans, root.val + left + right);
        return root.val + Math.max(left, right);
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
    int maxPathSum(TreeNode* root) {
        int ans = -1001;
        function<int(TreeNode*)> dfs = [&](TreeNode* root) {
            if (!root) {
                return 0;
            }
            int left = max(0, dfs(root->left));
            int right = max(0, dfs(root->right));
            ans = max(ans, left + right + root->val);
            return root->val + max(left, right);
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
func maxPathSum(root *TreeNode) int {
	ans := -1001
	var dfs func(*TreeNode) int
	dfs = func(root *TreeNode) int {
		if root == nil {
			return 0
		}
		left := max(0, dfs(root.Left))
		right := max(0, dfs(root.Right))
		ans = max(ans, left+right+root.Val)
		return max(left, right) + root.Val
	}
	dfs(root)
	return ans
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

function maxPathSum(root: TreeNode | null): number {
    let ans = -1001;
    const dfs = (root: TreeNode | null): number => {
        if (!root) {
            return 0;
        }
        const left = Math.max(0, dfs(root.left));
        const right = Math.max(0, dfs(root.right));
        ans = Math.max(ans, left + right + root.val);
        return Math.max(left, right) + root.val;
    };
    dfs(root);
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
    fn dfs(root: &Option<Rc<RefCell<TreeNode>>>, res: &mut i32) -> i32 {
        if root.is_none() {
            return 0;
        }
        let node = root.as_ref().unwrap().borrow();
        let left = (0).max(Self::dfs(&node.left, res));
        let right = (0).max(Self::dfs(&node.right, res));
        *res = (node.val + left + right).max(*res);
        node.val + left.max(right)
    }

    pub fn max_path_sum(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut res = -1000;
        Self::dfs(&root, &mut res);
        res
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
 * @return {number}
 */
var maxPathSum = function (root) {
    let ans = -1001;
    const dfs = root => {
        if (!root) {
            return 0;
        }
        const left = Math.max(0, dfs(root.left));
        const right = Math.max(0, dfs(root.right));
        ans = Math.max(ans, left + right + root.val);
        return Math.max(left, right) + root.val;
    };
    dfs(root);
    return ans;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    private int ans = -1001;

    public int MaxPathSum(TreeNode root) {
        dfs(root);
        return ans;
    }

    private int dfs(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int left = Math.Max(0, dfs(root.left));
        int right = Math.Max(0, dfs(root.right));
        ans = Math.Max(ans, left + right + root.val);
        return root.val + Math.Max(left, right);
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>二叉树中的<strong> 路径</strong> 被定义为一条节点序列，序列中每对相邻节点之间都存在一条边。同一个节点在一条路径序列中 <strong>至多出现一次</strong> 。该路径<strong> 至少包含一个 </strong>节点，且不一定经过根节点。</p>

<p><strong>路径和</strong> 是路径中各节点值的总和。</p>

<p>给你一个二叉树的根节点 <code>root</code> ，返回其 <strong>最大路径和</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0100-0199/0124.Binary%20Tree%20Maximum%20Path%20Sum/images/exx1.jpg" style="width: 322px; height: 182px;" />
<pre>
<strong>输入：</strong>root = [1,2,3]
<strong>输出：</strong>6
<strong>解释：</strong>最优路径是 2 -&gt; 1 -&gt; 3 ，路径和为 2 + 1 + 3 = 6</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0100-0199/0124.Binary%20Tree%20Maximum%20Path%20Sum/images/exx2.jpg" />
<pre>
<strong>输入：</strong>root = [-10,9,20,null,null,15,7]
<strong>输出：</strong>42
<strong>解释：</strong>最优路径是 15 -&gt; 20 -&gt; 7 ，路径和为 15 + 20 + 7 = 42
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数目范围是 <code>[1, 3 * 10<sup>4</sup>]</code></li>
	<li><code>-1000 &lt;= Node.val &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归

我们思考二叉树递归问题的经典套路：

1. 终止条件（何时终止递归）
2. 递归处理左右子树
3. 合并左右子树的计算结果

对于本题，我们设计一个函数 $dfs(root)$，它返回以 $root$ 为根节点的二叉树的最大路径和。

函数 $dfs(root)$ 的执行逻辑如下：

如果 $root$ 不存在，那么 $dfs(root)$ 返回 $0$；

否则，我们递归计算 $root$ 的左子树和右子树的最大路径和，分别记为 $left$ 和 $right$。如果 $left$ 小于 $0$，那么我们将其置为 $0$，同理，如果 $right$ 小于 $0$，那么我们将其置为 $0$。

然后，我们用 $root.val + left + right$ 更新答案。最后，函数返回 $root.val + \max(left, right)$。

在主函数中，我们调用 $dfs(root)$，即可得到每个节点的最大路径和，其中的最大值即为答案。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是二叉树的节点数。

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
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        def dfs(root: Optional[TreeNode]) -> int:
            if root is None:
                return 0
            left = max(0, dfs(root.left))
            right = max(0, dfs(root.right))
            nonlocal ans
            ans = max(ans, root.val + left + right)
            return root.val + max(left, right)

        ans = -inf
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
    private int ans = -1001;

    public int maxPathSum(TreeNode root) {
        dfs(root);
        return ans;
    }

    private int dfs(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int left = Math.max(0, dfs(root.left));
        int right = Math.max(0, dfs(root.right));
        ans = Math.max(ans, root.val + left + right);
        return root.val + Math.max(left, right);
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
    int maxPathSum(TreeNode* root) {
        int ans = -1001;
        function<int(TreeNode*)> dfs = [&](TreeNode* root) {
            if (!root) {
                return 0;
            }
            int left = max(0, dfs(root->left));
            int right = max(0, dfs(root->right));
            ans = max(ans, left + right + root->val);
            return root->val + max(left, right);
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
func maxPathSum(root *TreeNode) int {
	ans := -1001
	var dfs func(*TreeNode) int
	dfs = func(root *TreeNode) int {
		if root == nil {
			return 0
		}
		left := max(0, dfs(root.Left))
		right := max(0, dfs(root.Right))
		ans = max(ans, left+right+root.Val)
		return max(left, right) + root.Val
	}
	dfs(root)
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

function maxPathSum(root: TreeNode | null): number {
    let ans = -1001;
    const dfs = (root: TreeNode | null): number => {
        if (!root) {
            return 0;
        }
        const left = Math.max(0, dfs(root.left));
        const right = Math.max(0, dfs(root.right));
        ans = Math.max(ans, left + right + root.val);
        return Math.max(left, right) + root.val;
    };
    dfs(root);
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
    fn dfs(root: &Option<Rc<RefCell<TreeNode>>>, res: &mut i32) -> i32 {
        if root.is_none() {
            return 0;
        }
        let node = root.as_ref().unwrap().borrow();
        let left = (0).max(Self::dfs(&node.left, res));
        let right = (0).max(Self::dfs(&node.right, res));
        *res = (node.val + left + right).max(*res);
        node.val + left.max(right)
    }

    pub fn max_path_sum(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut res = -1000;
        Self::dfs(&root, &mut res);
        res
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
 * @return {number}
 */
var maxPathSum = function (root) {
    let ans = -1001;
    const dfs = root => {
        if (!root) {
            return 0;
        }
        const left = Math.max(0, dfs(root.left));
        const right = Math.max(0, dfs(root.right));
        ans = Math.max(ans, left + right + root.val);
        return Math.max(left, right) + root.val;
    };
    dfs(root);
    return ans;
};
```

#### C#

```cs
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    private int ans = -1001;

    public int MaxPathSum(TreeNode root) {
        dfs(root);
        return ans;
    }

    private int dfs(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int left = Math.Max(0, dfs(root.left));
        int right = Math.Max(0, dfs(root.right));
        ans = Math.Max(ans, left + right + root.val);
        return root.val + Math.Max(left, right);
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [125. 验证回文串](https://leetcode.cn/problems/valid-palindrome){#125}

{{< tabs "125" >}}

{{% tab "python" %}}
```python
class Solution:
    def isPalindrome(self, s: str) -> bool:
        i, j = 0, len(s) - 1
        while i < j:
            if not s[i].isalnum():
                i += 1
            elif not s[j].isalnum():
                j -= 1
            elif s[i].lower() != s[j].lower():
                return False
            else:
                i, j = i + 1, j - 1
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isPalindrome(String s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (!Character.isLetterOrDigit(s.charAt(i))) {
                ++i;
            } else if (!Character.isLetterOrDigit(s.charAt(j))) {
                --j;
            } else if (Character.toLowerCase(s.charAt(i)) != Character.toLowerCase(s.charAt(j))) {
                return false;
            } else {
                ++i;
                --j;
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
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (!isalnum(s[i])) {
                ++i;
            } else if (!isalnum(s[j])) {
                --j;
            } else if (tolower(s[i]) != tolower(s[j])) {
                return false;
            } else {
                ++i;
                --j;
            }
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isPalindrome(s string) bool {
	i, j := 0, len(s)-1
	for i < j {
		if !isalnum(s[i]) {
			i++
		} else if !isalnum(s[j]) {
			j--
		} else if tolower(s[i]) != tolower(s[j]) {
			return false
		} else {
			i, j = i+1, j-1
		}
	}
	return true
}

func isalnum(ch byte) bool {
	return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')
}

func tolower(ch byte) byte {
	if ch >= 'A' && ch <= 'Z' {
		return ch + 32
	}
	return ch
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isPalindrome(s: string): boolean {
    let i = 0;
    let j = s.length - 1;
    while (i < j) {
        if (!/[a-zA-Z0-9]/.test(s[i])) {
            ++i;
        } else if (!/[a-zA-Z0-9]/.test(s[j])) {
            --j;
        } else if (s[i].toLowerCase() !== s[j].toLowerCase()) {
            return false;
        } else {
            ++i;
            --j;
        }
    }
    return true;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn is_palindrome(s: String) -> bool {
        let s = s.to_lowercase();
        let s = s.as_bytes();
        let n = s.len();
        let (mut l, mut r) = (0, n - 1);
        while l < r {
            while l < r && !s[l].is_ascii_alphanumeric() {
                l += 1;
            }
            while l < r && !s[r].is_ascii_alphanumeric() {
                r -= 1;
            }
            if s[l] != s[r] {
                return false;
            }
            l += 1;
            if r != 0 {
                r -= 1;
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
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function (s) {
    let i = 0;
    let j = s.length - 1;
    while (i < j) {
        if (!/[a-zA-Z0-9]/.test(s[i])) {
            ++i;
        } else if (!/[a-zA-Z0-9]/.test(s[j])) {
            --j;
        } else if (s[i].toLowerCase() !== s[j].toLowerCase()) {
            return false;
        } else {
            ++i;
            --j;
        }
    }
    return true;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public bool IsPalindrome(string s) {
        int i = 0, j = s.Length - 1;
        while (i < j) {
            if (!char.IsLetterOrDigit(s[i])) {
                ++i;
            } else if (!char.IsLetterOrDigit(s[j])) {
                --j;
            } else if (char.ToLower(s[i++]) != char.ToLower(s[j--])) {
                return false;
            }
        }
        return true;
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param String $s
     * @return Boolean
     */
    function isPalindrome($s) {
        $regex = '/[a-z0-9]/';
        $s = strtolower($s);
        preg_match_all($regex, $s, $matches);
        if ($matches[0] == null) {
            return true;
        }
        $len = floor(count($matches[0]) / 2);
        for ($i = 0; $i < $len; $i++) {
            if ($matches[0][$i] != $matches[0][count($matches[0]) - 1 - $i]) {
                return false;
            }
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

<p>如果在将所有大写字符转换为小写字符、并移除所有非字母数字字符之后，短语正着读和反着读都一样。则可以认为该短语是一个 <strong>回文串</strong> 。</p>

<p>字母和数字都属于字母数字字符。</p>

<p>给你一个字符串 <code>s</code>，如果它是 <strong>回文串</strong> ，返回 <code>true</code><em> </em>；否则，返回<em> </em><code>false</code><em> </em>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入:</strong> s = "A man, a plan, a canal: Panama"
<strong>输出：</strong>true
<strong>解释：</strong>"amanaplanacanalpanama" 是回文串。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "race a car"
<strong>输出：</strong>false
<strong>解释：</strong>"raceacar" 不是回文串。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = " "
<strong>输出：</strong>true
<strong>解释：</strong>在移除非字母数字字符之后，s 是一个空字符串 "" 。
由于空字符串正着反着读都一样，所以是回文串。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>s</code> 仅由可打印的 ASCII 字符组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

我们用双指针 $i$ 和 $j$ 分别指向字符串 $s$ 的两端，接下来循环以下过程，直至 $i \geq j$：

1. 如果 $s[i]$ 不是字母或数字，指针 $i$ 右移一位，继续下一次循环；
1. 如果 $s[j]$ 不是字母或数字，指针 $j$ 左移一位，继续下一次循环；
1. 如果 $s[i]$ 和 $s[j]$ 的小写形式不相等，返回 `false`；
1. 否则，指针 $i$ 右移一位，指针 $j$ 左移一位，继续下一次循环。

循环结束，返回 `true`。

时间复杂度 $O(n)$，其中 $n$ 是字符串 $s$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isPalindrome(self, s: str) -> bool:
        i, j = 0, len(s) - 1
        while i < j:
            if not s[i].isalnum():
                i += 1
            elif not s[j].isalnum():
                j -= 1
            elif s[i].lower() != s[j].lower():
                return False
            else:
                i, j = i + 1, j - 1
        return True
```

#### Java

```java
class Solution {
    public boolean isPalindrome(String s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (!Character.isLetterOrDigit(s.charAt(i))) {
                ++i;
            } else if (!Character.isLetterOrDigit(s.charAt(j))) {
                --j;
            } else if (Character.toLowerCase(s.charAt(i)) != Character.toLowerCase(s.charAt(j))) {
                return false;
            } else {
                ++i;
                --j;
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
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (!isalnum(s[i])) {
                ++i;
            } else if (!isalnum(s[j])) {
                --j;
            } else if (tolower(s[i]) != tolower(s[j])) {
                return false;
            } else {
                ++i;
                --j;
            }
        }
        return true;
    }
};
```

#### Go

```go
func isPalindrome(s string) bool {
	i, j := 0, len(s)-1
	for i < j {
		if !isalnum(s[i]) {
			i++
		} else if !isalnum(s[j]) {
			j--
		} else if tolower(s[i]) != tolower(s[j]) {
			return false
		} else {
			i, j = i+1, j-1
		}
	}
	return true
}

func isalnum(ch byte) bool {
	return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')
}

func tolower(ch byte) byte {
	if ch >= 'A' && ch <= 'Z' {
		return ch + 32
	}
	return ch
}
```

#### TypeScript

```ts
function isPalindrome(s: string): boolean {
    let i = 0;
    let j = s.length - 1;
    while (i < j) {
        if (!/[a-zA-Z0-9]/.test(s[i])) {
            ++i;
        } else if (!/[a-zA-Z0-9]/.test(s[j])) {
            --j;
        } else if (s[i].toLowerCase() !== s[j].toLowerCase()) {
            return false;
        } else {
            ++i;
            --j;
        }
    }
    return true;
}
```

#### Rust

```rust
impl Solution {
    pub fn is_palindrome(s: String) -> bool {
        let s = s.to_lowercase();
        let s = s.as_bytes();
        let n = s.len();
        let (mut l, mut r) = (0, n - 1);
        while l < r {
            while l < r && !s[l].is_ascii_alphanumeric() {
                l += 1;
            }
            while l < r && !s[r].is_ascii_alphanumeric() {
                r -= 1;
            }
            if s[l] != s[r] {
                return false;
            }
            l += 1;
            if r != 0 {
                r -= 1;
            }
        }
        true
    }
}
```

#### JavaScript

```js
/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function (s) {
    let i = 0;
    let j = s.length - 1;
    while (i < j) {
        if (!/[a-zA-Z0-9]/.test(s[i])) {
            ++i;
        } else if (!/[a-zA-Z0-9]/.test(s[j])) {
            --j;
        } else if (s[i].toLowerCase() !== s[j].toLowerCase()) {
            return false;
        } else {
            ++i;
            --j;
        }
    }
    return true;
};
```

#### C#

```cs
public class Solution {
    public bool IsPalindrome(string s) {
        int i = 0, j = s.Length - 1;
        while (i < j) {
            if (!char.IsLetterOrDigit(s[i])) {
                ++i;
            } else if (!char.IsLetterOrDigit(s[j])) {
                --j;
            } else if (char.ToLower(s[i++]) != char.ToLower(s[j--])) {
                return false;
            }
        }
        return true;
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param String $s
     * @return Boolean
     */
    function isPalindrome($s) {
        $regex = '/[a-z0-9]/';
        $s = strtolower($s);
        preg_match_all($regex, $s, $matches);
        if ($matches[0] == null) {
            return true;
        }
        $len = floor(count($matches[0]) / 2);
        for ($i = 0; $i < $len; $i++) {
            if ($matches[0][$i] != $matches[0][count($matches[0]) - 1 - $i]) {
                return false;
            }
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

# [126. 单词接龙 II](https://leetcode.cn/problems/word-ladder-ii){#126}

{{< tabs "126" >}}

{{% tab "python" %}}
```python
class Solution:
    def findLadders(
        self, beginWord: str, endWord: str, wordList: List[str]
    ) -> List[List[str]]:
        def dfs(path, cur):
            if cur == beginWord:
                ans.append(path[::-1])
                return
            for precursor in prev[cur]:
                path.append(precursor)
                dfs(path, precursor)
                path.pop()

        ans = []
        words = set(wordList)
        if endWord not in words:
            return ans
        words.discard(beginWord)
        dist = {beginWord: 0}
        prev = defaultdict(set)
        q = deque([beginWord])
        found = False
        step = 0
        while q and not found:
            step += 1
            for i in range(len(q), 0, -1):
                p = q.popleft()
                s = list(p)
                for i in range(len(s)):
                    ch = s[i]
                    for j in range(26):
                        s[i] = chr(ord('a') + j)
                        t = ''.join(s)
                        if dist.get(t, 0) == step:
                            prev[t].add(p)
                        if t not in words:
                            continue
                        prev[t].add(p)
                        words.discard(t)
                        q.append(t)
                        dist[t] = step
                        if endWord == t:
                            found = True
                    s[i] = ch
        if found:
            path = [endWord]
            dfs(path, endWord)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private List<List<String>> ans;
    private Map<String, Set<String>> prev;

    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        ans = new ArrayList<>();
        Set<String> words = new HashSet<>(wordList);
        if (!words.contains(endWord)) {
            return ans;
        }
        words.remove(beginWord);
        Map<String, Integer> dist = new HashMap<>();
        dist.put(beginWord, 0);
        prev = new HashMap<>();
        Queue<String> q = new ArrayDeque<>();
        q.offer(beginWord);
        boolean found = false;
        int step = 0;
        while (!q.isEmpty() && !found) {
            ++step;
            for (int i = q.size(); i > 0; --i) {
                String p = q.poll();
                char[] chars = p.toCharArray();
                for (int j = 0; j < chars.length; ++j) {
                    char ch = chars[j];
                    for (char k = 'a'; k <= 'z'; ++k) {
                        chars[j] = k;
                        String t = new String(chars);
                        if (dist.getOrDefault(t, 0) == step) {
                            prev.get(t).add(p);
                        }
                        if (!words.contains(t)) {
                            continue;
                        }
                        prev.computeIfAbsent(t, key -> new HashSet<>()).add(p);
                        words.remove(t);
                        q.offer(t);
                        dist.put(t, step);
                        if (endWord.equals(t)) {
                            found = true;
                        }
                    }
                    chars[j] = ch;
                }
            }
        }
        if (found) {
            Deque<String> path = new ArrayDeque<>();
            path.add(endWord);
            dfs(path, beginWord, endWord);
        }
        return ans;
    }

    private void dfs(Deque<String> path, String beginWord, String cur) {
        if (cur.equals(beginWord)) {
            ans.add(new ArrayList<>(path));
            return;
        }
        for (String precursor : prev.get(cur)) {
            path.addFirst(precursor);
            dfs(path, beginWord, precursor);
            path.removeFirst();
        }
    }
}
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findLadders(beginWord string, endWord string, wordList []string) [][]string {
	var ans [][]string
	words := make(map[string]bool)
	for _, word := range wordList {
		words[word] = true
	}
	if !words[endWord] {
		return ans
	}
	words[beginWord] = false
	dist := map[string]int{beginWord: 0}
	prev := map[string]map[string]bool{}
	q := []string{beginWord}
	found := false
	step := 0
	for len(q) > 0 && !found {
		step++
		for i := len(q); i > 0; i-- {
			p := q[0]
			q = q[1:]
			chars := []byte(p)
			for j := 0; j < len(chars); j++ {
				ch := chars[j]
				for k := 'a'; k <= 'z'; k++ {
					chars[j] = byte(k)
					t := string(chars)
					if v, ok := dist[t]; ok {
						if v == step {
							prev[t][p] = true
						}
					}
					if !words[t] {
						continue
					}
					if len(prev[t]) == 0 {
						prev[t] = make(map[string]bool)
					}
					prev[t][p] = true
					words[t] = false
					q = append(q, t)
					dist[t] = step
					if endWord == t {
						found = true
					}
				}
				chars[j] = ch
			}
		}
	}
	var dfs func(path []string, begin, cur string)
	dfs = func(path []string, begin, cur string) {
		if cur == beginWord {
			cp := make([]string, len(path))
			copy(cp, path)
			ans = append(ans, cp)
			return
		}
		for k := range prev[cur] {
			path = append([]string{k}, path...)
			dfs(path, beginWord, k)
			path = path[1:]
		}
	}
	if found {
		path := []string{endWord}
		dfs(path, beginWord, endWord)
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

<p>按字典&nbsp;<code>wordList</code> 完成从单词 <code>beginWord</code> 到单词 <code>endWord</code> 转化，一个表示此过程的 <strong>转换序列</strong> 是形式上像 <code>beginWord -&gt; s<sub>1</sub> -&gt; s<sub>2</sub> -&gt; ... -&gt; s<sub>k</sub></code> 这样的单词序列，并满足：</p>

<div class="original__bRMd">
<div>
<ul>
	<li>每对相邻的单词之间仅有单个字母不同。</li>
	<li>转换过程中的每个单词 <code>s<sub>i</sub></code>（<code>1 &lt;= i &lt;= k</code>）必须是字典&nbsp;<code>wordList</code> 中的单词。注意，<code>beginWord</code> 不必是字典 <code>wordList</code> 中的单词。</li>
	<li><code>s<sub>k</sub> == endWord</code></li>
</ul>

<p>给你两个单词 <code>beginWord</code> 和 <code>endWord</code> ，以及一个字典 <code>wordList</code> 。请你找出并返回所有从 <code>beginWord</code> 到 <code>endWord</code> 的 <strong>最短转换序列</strong> ，如果不存在这样的转换序列，返回一个空列表。每个序列都应该以单词列表<em> </em><code>[beginWord, s<sub>1</sub>, s<sub>2</sub>, ..., s<sub>k</sub>]</code> 的形式返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
<strong>输出：</strong>[["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
<strong>解释：</strong>存在 2 种最短的转换序列：
"hit" -&gt; "hot" -&gt; "dot" -&gt; "dog" -&gt; "cog"
"hit" -&gt; "hot" -&gt; "lot" -&gt; "log" -&gt; "cog"
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
<strong>输出：</strong>[]
<strong>解释：</strong>endWord "cog" 不在字典 wordList 中，所以不存在符合要求的转换序列。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= beginWord.length &lt;= 5</code></li>
	<li><code>endWord.length == beginWord.length</code></li>
	<li><code>1 &lt;= wordList.length &lt;= 500</code></li>
	<li><code>wordList[i].length == beginWord.length</code></li>
	<li><code>beginWord</code>、<code>endWord</code> 和 <code>wordList[i]</code> 由小写英文字母组成</li>
	<li><code>beginWord != endWord</code></li>
	<li><code>wordList</code> 中的所有单词 <strong>互不相同</strong></li>
</ul>
</div>
</div>

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
    def findLadders(
        self, beginWord: str, endWord: str, wordList: List[str]
    ) -> List[List[str]]:
        def dfs(path, cur):
            if cur == beginWord:
                ans.append(path[::-1])
                return
            for precursor in prev[cur]:
                path.append(precursor)
                dfs(path, precursor)
                path.pop()

        ans = []
        words = set(wordList)
        if endWord not in words:
            return ans
        words.discard(beginWord)
        dist = {beginWord: 0}
        prev = defaultdict(set)
        q = deque([beginWord])
        found = False
        step = 0
        while q and not found:
            step += 1
            for i in range(len(q), 0, -1):
                p = q.popleft()
                s = list(p)
                for i in range(len(s)):
                    ch = s[i]
                    for j in range(26):
                        s[i] = chr(ord('a') + j)
                        t = ''.join(s)
                        if dist.get(t, 0) == step:
                            prev[t].add(p)
                        if t not in words:
                            continue
                        prev[t].add(p)
                        words.discard(t)
                        q.append(t)
                        dist[t] = step
                        if endWord == t:
                            found = True
                    s[i] = ch
        if found:
            path = [endWord]
            dfs(path, endWord)
        return ans
```

#### Java

```java
class Solution {
    private List<List<String>> ans;
    private Map<String, Set<String>> prev;

    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        ans = new ArrayList<>();
        Set<String> words = new HashSet<>(wordList);
        if (!words.contains(endWord)) {
            return ans;
        }
        words.remove(beginWord);
        Map<String, Integer> dist = new HashMap<>();
        dist.put(beginWord, 0);
        prev = new HashMap<>();
        Queue<String> q = new ArrayDeque<>();
        q.offer(beginWord);
        boolean found = false;
        int step = 0;
        while (!q.isEmpty() && !found) {
            ++step;
            for (int i = q.size(); i > 0; --i) {
                String p = q.poll();
                char[] chars = p.toCharArray();
                for (int j = 0; j < chars.length; ++j) {
                    char ch = chars[j];
                    for (char k = 'a'; k <= 'z'; ++k) {
                        chars[j] = k;
                        String t = new String(chars);
                        if (dist.getOrDefault(t, 0) == step) {
                            prev.get(t).add(p);
                        }
                        if (!words.contains(t)) {
                            continue;
                        }
                        prev.computeIfAbsent(t, key -> new HashSet<>()).add(p);
                        words.remove(t);
                        q.offer(t);
                        dist.put(t, step);
                        if (endWord.equals(t)) {
                            found = true;
                        }
                    }
                    chars[j] = ch;
                }
            }
        }
        if (found) {
            Deque<String> path = new ArrayDeque<>();
            path.add(endWord);
            dfs(path, beginWord, endWord);
        }
        return ans;
    }

    private void dfs(Deque<String> path, String beginWord, String cur) {
        if (cur.equals(beginWord)) {
            ans.add(new ArrayList<>(path));
            return;
        }
        for (String precursor : prev.get(cur)) {
            path.addFirst(precursor);
            dfs(path, beginWord, precursor);
            path.removeFirst();
        }
    }
}
```

#### Go

```go
func findLadders(beginWord string, endWord string, wordList []string) [][]string {
	var ans [][]string
	words := make(map[string]bool)
	for _, word := range wordList {
		words[word] = true
	}
	if !words[endWord] {
		return ans
	}
	words[beginWord] = false
	dist := map[string]int{beginWord: 0}
	prev := map[string]map[string]bool{}
	q := []string{beginWord}
	found := false
	step := 0
	for len(q) > 0 && !found {
		step++
		for i := len(q); i > 0; i-- {
			p := q[0]
			q = q[1:]
			chars := []byte(p)
			for j := 0; j < len(chars); j++ {
				ch := chars[j]
				for k := 'a'; k <= 'z'; k++ {
					chars[j] = byte(k)
					t := string(chars)
					if v, ok := dist[t]; ok {
						if v == step {
							prev[t][p] = true
						}
					}
					if !words[t] {
						continue
					}
					if len(prev[t]) == 0 {
						prev[t] = make(map[string]bool)
					}
					prev[t][p] = true
					words[t] = false
					q = append(q, t)
					dist[t] = step
					if endWord == t {
						found = true
					}
				}
				chars[j] = ch
			}
		}
	}
	var dfs func(path []string, begin, cur string)
	dfs = func(path []string, begin, cur string) {
		if cur == beginWord {
			cp := make([]string, len(path))
			copy(cp, path)
			ans = append(ans, cp)
			return
		}
		for k := range prev[cur] {
			path = append([]string{k}, path...)
			dfs(path, beginWord, k)
			path = path[1:]
		}
	}
	if found {
		path := []string{endWord}
		dfs(path, beginWord, endWord)
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [127. 单词接龙](https://leetcode.cn/problems/word-ladder){#127}

{{< tabs "127" >}}

{{% tab "python" %}}
```python
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        def extend(m1, m2, q):
            for _ in range(len(q)):
                s = q.popleft()
                step = m1[s]
                s = list(s)
                for i in range(len(s)):
                    ch = s[i]
                    for j in range(26):
                        s[i] = chr(ord('a') + j)
                        t = ''.join(s)
                        if t in m1 or t not in words:
                            continue
                        if t in m2:
                            return step + 1 + m2[t]
                        m1[t] = step + 1
                        q.append(t)
                    s[i] = ch
            return -1

        words = set(wordList)
        if endWord not in words:
            return 0
        q1, q2 = deque([beginWord]), deque([endWord])
        m1, m2 = {beginWord: 0}, {endWord: 0}
        while q1 and q2:
            t = extend(m1, m2, q1) if len(q1) <= len(q2) else extend(m2, m1, q2)
            if t != -1:
                return t + 1
        return 0
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private Set<String> words;

    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        words = new HashSet<>(wordList);
        if (!words.contains(endWord)) {
            return 0;
        }
        Queue<String> q1 = new ArrayDeque<>();
        Queue<String> q2 = new ArrayDeque<>();
        Map<String, Integer> m1 = new HashMap<>();
        Map<String, Integer> m2 = new HashMap<>();
        q1.offer(beginWord);
        q2.offer(endWord);
        m1.put(beginWord, 0);
        m2.put(endWord, 0);
        while (!q1.isEmpty() && !q2.isEmpty()) {
            int t = q1.size() <= q2.size() ? extend(m1, m2, q1) : extend(m2, m1, q2);
            if (t != -1) {
                return t + 1;
            }
        }
        return 0;
    }

    private int extend(Map<String, Integer> m1, Map<String, Integer> m2, Queue<String> q) {
        for (int i = q.size(); i > 0; --i) {
            String s = q.poll();
            int step = m1.get(s);
            char[] chars = s.toCharArray();
            for (int j = 0; j < chars.length; ++j) {
                char ch = chars[j];
                for (char k = 'a'; k <= 'z'; ++k) {
                    chars[j] = k;
                    String t = new String(chars);
                    if (!words.contains(t) || m1.containsKey(t)) {
                        continue;
                    }
                    if (m2.containsKey(t)) {
                        return step + 1 + m2.get(t);
                    }
                    q.offer(t);
                    m1.put(t, step + 1);
                }
                chars[j] = ch;
            }
        }
        return -1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (!words.count(endWord)) return 0;
        queue<string> q1{{beginWord}};
        queue<string> q2{{endWord}};
        unordered_map<string, int> m1;
        unordered_map<string, int> m2;
        m1[beginWord] = 0;
        m2[endWord] = 0;
        while (!q1.empty() && !q2.empty()) {
            int t = q1.size() <= q2.size() ? extend(m1, m2, q1, words) : extend(m2, m1, q2, words);
            if (t != -1) return t + 1;
        }
        return 0;
    }

    int extend(unordered_map<string, int>& m1, unordered_map<string, int>& m2, queue<string>& q, unordered_set<string>& words) {
        for (int i = q.size(); i > 0; --i) {
            string s = q.front();
            int step = m1[s];
            q.pop();
            for (int j = 0; j < s.size(); ++j) {
                char ch = s[j];
                for (char k = 'a'; k <= 'z'; ++k) {
                    s[j] = k;
                    if (!words.count(s) || m1.count(s)) continue;
                    if (m2.count(s)) return step + 1 + m2[s];
                    m1[s] = step + 1;
                    q.push(s);
                }
                s[j] = ch;
            }
        }
        return -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func ladderLength(beginWord string, endWord string, wordList []string) int {
	words := make(map[string]bool)
	for _, word := range wordList {
		words[word] = true
	}
	if !words[endWord] {
		return 0
	}

	q1, q2 := []string{beginWord}, []string{endWord}
	m1, m2 := map[string]int{beginWord: 0}, map[string]int{endWord: 0}
	extend := func() int {
		for i := len(q1); i > 0; i-- {
			s := q1[0]
			step, _ := m1[s]
			q1 = q1[1:]
			chars := []byte(s)
			for j := 0; j < len(chars); j++ {
				ch := chars[j]
				for k := 'a'; k <= 'z'; k++ {
					chars[j] = byte(k)
					t := string(chars)
					if !words[t] {
						continue
					}
					if _, ok := m1[t]; ok {
						continue
					}
					if v, ok := m2[t]; ok {
						return step + 1 + v
					}
					q1 = append(q1, t)
					m1[t] = step + 1
				}
				chars[j] = ch
			}
		}
		return -1
	}
	for len(q1) > 0 && len(q2) > 0 {
		if len(q1) > len(q2) {
			m1, m2 = m2, m1
			q1, q2 = q2, q1
		}
		t := extend()
		if t != -1 {
			return t + 1
		}
	}
	return 0
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
using System.Collections;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int LadderLength(string beginWord, string endWord, IList<string> wordList) {
        var words = Enumerable.Repeat(beginWord, 1).Concat(wordList).Select((word, i) => new { Word = word, Index = i }).ToList();
        var endWordIndex = words.Find(w => w.Word == endWord)?.Index;
        if (endWordIndex == null) {
            return 0;
        }

        var paths = new List<int>[words.Count];
        for (var i = 0; i < paths.Length; ++i)
        {
            paths[i] = new List<int>();
        }
        for (var i = 0; i < beginWord.Length; ++i)
        {
            var hashMap = new Hashtable();
            foreach (var item in words)
            {
                var newWord = string.Format("{0}_{1}", item.Word.Substring(0, i), item.Word.Substring(i + 1));
                List<int> similars;
                if (!hashMap.ContainsKey(newWord))
                {
                    similars = new List<int>();
                    hashMap.Add(newWord, similars);
                }
                else
                {
                    similars = (List<int>)hashMap[newWord];
                }
                foreach (var similar in similars)
                {
                    paths[similar].Add(item.Index);
                    paths[item.Index].Add(similar);
                }
                similars.Add(item.Index);
            }
        }

        var left = words.Count - 1;
        var lastRound = new List<int> { 0 };
        var visited = new bool[words.Count];
        visited[0] = true;
        for (var result = 2; left > 0; ++result)
        {
            var thisRound = new List<int>();
            foreach (var index in lastRound)
            {
                foreach (var next in paths[index])
                {
                    if (!visited[next])
                    {
                        visited[next] = true;
                        if (next == endWordIndex) return result;
                        thisRound.Add(next);
                    }
                }
            }
            if (thisRound.Count == 0) break;
            lastRound = thisRound;
        }

        return 0;
    }
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function ladderLength(beginWord: string, endWord: string, wordList: string[]): number {
    if (!wordList.includes(endWord)) return 0;

    const replace = (s: string, i: number, ch: string) => s.slice(0, i) + ch + s.slice(i + 1);
    const { length } = beginWord;
    const words: Record<string, string[]> = {};
    const g: Record<string, string[]> = {};

    for (const w of [beginWord, ...wordList]) {
        const derivatives: string[] = [];

        for (let i = 0; i < length; i++) {
            const nextW = replace(w, i, '*');
            derivatives.push(nextW);

            g[nextW] ??= [];
            g[nextW].push(w);
        }

        words[w] = derivatives;
    }

    let ans = 0;
    let q = words[beginWord];
    const vis = new Set<string>([beginWord]);

    while (q.length) {
        const nextQ: string[] = [];
        ans++;

        for (const variant of q) {
            for (const w of g[variant]) {
                if (w === endWord) return ans + 1;

                if (vis.has(w)) continue;
                vis.add(w);

                nextQ.push(...words[w]);
            }
        }

        q = nextQ;
    }

    return 0;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>字典&nbsp;<code>wordList</code> 中从单词 <code>beginWord</code><em>&nbsp;</em>到&nbsp;<code>endWord</code> 的 <strong>转换序列 </strong>是一个按下述规格形成的序列<meta charset="UTF-8" />&nbsp;<code>beginWord -&gt; s<sub>1</sub>&nbsp;-&gt; s<sub>2</sub>&nbsp;-&gt; ... -&gt; s<sub>k</sub></code>：</p>

<ul>
	<li>每一对相邻的单词只差一个字母。</li>
	<li><meta charset="UTF-8" />&nbsp;对于&nbsp;<code>1 &lt;= i &lt;= k</code>&nbsp;时，每个<meta charset="UTF-8" />&nbsp;<code>s<sub>i</sub></code>&nbsp;都在<meta charset="UTF-8" />&nbsp;<code>wordList</code>&nbsp;中。注意， <code>beginWord</code><em>&nbsp;</em>不需要在<meta charset="UTF-8" />&nbsp;<code>wordList</code>&nbsp;中。<meta charset="UTF-8" /></li>
	<li><code>s<sub>k</sub>&nbsp;== endWord</code></li>
</ul>

<p>给你两个单词<em> </em><code>beginWord</code><em>&nbsp;</em>和 <code>endWord</code> 和一个字典 <code>wordList</code> ，返回 <em>从&nbsp;<code>beginWord</code> 到&nbsp;<code>endWord</code> 的 <strong>最短转换序列</strong> 中的 <strong>单词数目</strong></em> 。如果不存在这样的转换序列，返回 <code>0</code> 。</p>
&nbsp;

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
<strong>输出：</strong>5
<strong>解释：</strong>一个最短转换序列是 "hit" -&gt; "hot" -&gt; "dot" -&gt; "dog" -&gt; "cog", 返回它的长度 5。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
<strong>输出：</strong>0
<strong>解释：</strong>endWord "cog" 不在字典中，所以无法进行转换。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= beginWord.length &lt;= 10</code></li>
	<li><code>endWord.length == beginWord.length</code></li>
	<li><code>1 &lt;= wordList.length &lt;= 5000</code></li>
	<li><code>wordList[i].length == beginWord.length</code></li>
	<li><code>beginWord</code>、<code>endWord</code> 和 <code>wordList[i]</code> 由小写英文字母组成</li>
	<li><code>beginWord != endWord</code></li>
	<li><code>wordList</code> 中的所有字符串 <strong>互不相同</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS

BFS 最小步数模型。本题可以用朴素 BFS，也可以用双向 BFS 优化搜索空间，从而提升效率。

双向 BFS 是 BFS 常见的一个优化方法，主要实现思路如下：

1. 创建两个队列 q1, q2 分别用于“起点 -> 终点”、“终点 -> 起点”两个方向的搜索；
2. 创建两个哈希表 m1, m2 分别记录访问过的节点以及对应的扩展次数（步数）；
3. 每次搜索时，优先选择元素数量较少的队列进行搜索扩展，如果在扩展过程中，搜索到另一个方向已经访问过的节点，说明找到了最短路径；
4. 只要其中一个队列为空，说明当前方向的搜索已经进行不下去了，说明起点到终点不连通，无需继续搜索。

```python
while q1 and q2:
    if len(q1) <= len(q2):
        # 优先选择较少元素的队列进行扩展
        extend(m1, m2, q1)
    else:
        extend(m2, m1, q2)


def extend(m1, m2, q):
    # 新一轮扩展
    for _ in range(len(q)):
        p = q.popleft()
        step = m1[p]
        for t in next(p):
            if t in m1:
                # 此前已经访问过
                continue
            if t in m2:
                # 另一个方向已经搜索过，说明找到了一条最短的连通路径
                return step + 1 + m2[t]
            q.append(t)
            m1[t] = step + 1
```

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        words = set(wordList)
        q = deque([beginWord])
        ans = 1
        while q:
            ans += 1
            for _ in range(len(q)):
                s = q.popleft()
                s = list(s)
                for i in range(len(s)):
                    ch = s[i]
                    for j in range(26):
                        s[i] = chr(ord('a') + j)
                        t = ''.join(s)
                        if t not in words:
                            continue
                        if t == endWord:
                            return ans
                        q.append(t)
                        words.remove(t)
                    s[i] = ch
        return 0
```

#### Java

```java
class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Set<String> words = new HashSet<>(wordList);
        Queue<String> q = new ArrayDeque<>();
        q.offer(beginWord);
        int ans = 1;
        while (!q.isEmpty()) {
            ++ans;
            for (int i = q.size(); i > 0; --i) {
                String s = q.poll();
                char[] chars = s.toCharArray();
                for (int j = 0; j < chars.length; ++j) {
                    char ch = chars[j];
                    for (char k = 'a'; k <= 'z'; ++k) {
                        chars[j] = k;
                        String t = new String(chars);
                        if (!words.contains(t)) {
                            continue;
                        }
                        if (endWord.equals(t)) {
                            return ans;
                        }
                        q.offer(t);
                        words.remove(t);
                    }
                    chars[j] = ch;
                }
            }
        }
        return 0;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        queue<string> q{{beginWord}};
        int ans = 1;
        while (!q.empty()) {
            ++ans;
            for (int i = q.size(); i > 0; --i) {
                string s = q.front();
                q.pop();
                for (int j = 0; j < s.size(); ++j) {
                    char ch = s[j];
                    for (char k = 'a'; k <= 'z'; ++k) {
                        s[j] = k;
                        if (!words.count(s)) continue;
                        if (s == endWord) return ans;
                        q.push(s);
                        words.erase(s);
                    }
                    s[j] = ch;
                }
            }
        }
        return 0;
    }
};
```

#### Go

```go
func ladderLength(beginWord string, endWord string, wordList []string) int {
	words := make(map[string]bool)
	for _, word := range wordList {
		words[word] = true
	}
	q := []string{beginWord}
	ans := 1
	for len(q) > 0 {
		ans++
		for i := len(q); i > 0; i-- {
			s := q[0]
			q = q[1:]
			chars := []byte(s)
			for j := 0; j < len(chars); j++ {
				ch := chars[j]
				for k := 'a'; k <= 'z'; k++ {
					chars[j] = byte(k)
					t := string(chars)
					if !words[t] {
						continue
					}
					if t == endWord {
						return ans
					}
					q = append(q, t)
					words[t] = false
				}
				chars[j] = ch
			}
		}
	}
	return 0
}
```

#### C#

```cs
using System.Collections;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int LadderLength(string beginWord, string endWord, IList<string> wordList) {
        var words = Enumerable.Repeat(beginWord, 1).Concat(wordList).Select((word, i) => new { Word = word, Index = i }).ToList();
        var endWordIndex = words.Find(w => w.Word == endWord)?.Index;
        if (endWordIndex == null) {
            return 0;
        }

        var paths = new List<int>[words.Count];
        for (var i = 0; i < paths.Length; ++i)
        {
            paths[i] = new List<int>();
        }
        for (var i = 0; i < beginWord.Length; ++i)
        {
            var hashMap = new Hashtable();
            foreach (var item in words)
            {
                var newWord = string.Format("{0}_{1}", item.Word.Substring(0, i), item.Word.Substring(i + 1));
                List<int> similars;
                if (!hashMap.ContainsKey(newWord))
                {
                    similars = new List<int>();
                    hashMap.Add(newWord, similars);
                }
                else
                {
                    similars = (List<int>)hashMap[newWord];
                }
                foreach (var similar in similars)
                {
                    paths[similar].Add(item.Index);
                    paths[item.Index].Add(similar);
                }
                similars.Add(item.Index);
            }
        }

        var left = words.Count - 1;
        var lastRound = new List<int> { 0 };
        var visited = new bool[words.Count];
        visited[0] = true;
        for (var result = 2; left > 0; ++result)
        {
            var thisRound = new List<int>();
            foreach (var index in lastRound)
            {
                foreach (var next in paths[index])
                {
                    if (!visited[next])
                    {
                        visited[next] = true;
                        if (next == endWordIndex) return result;
                        thisRound.Add(next);
                    }
                }
            }
            if (thisRound.Count == 0) break;
            lastRound = thisRound;
        }

        return 0;
    }
}
```

#### TypeScript

```ts
function ladderLength(beginWord: string, endWord: string, wordList: string[]): number {
    if (!wordList.includes(endWord)) return 0;

    const replace = (s: string, i: number, ch: string) => s.slice(0, i) + ch + s.slice(i + 1);
    const { length } = beginWord;
    const words: Record<string, string[]> = {};
    const g: Record<string, string[]> = {};

    for (const w of [beginWord, ...wordList]) {
        const derivatives: string[] = [];

        for (let i = 0; i < length; i++) {
            const nextW = replace(w, i, '*');
            derivatives.push(nextW);

            g[nextW] ??= [];
            g[nextW].push(w);
        }

        words[w] = derivatives;
    }

    let ans = 0;
    let q = words[beginWord];
    const vis = new Set<string>([beginWord]);

    while (q.length) {
        const nextQ: string[] = [];
        ans++;

        for (const variant of q) {
            for (const w of g[variant]) {
                if (w === endWord) return ans + 1;

                if (vis.has(w)) continue;
                vis.add(w);

                nextQ.push(...words[w]);
            }
        }

        q = nextQ;
    }

    return 0;
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
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        def extend(m1, m2, q):
            for _ in range(len(q)):
                s = q.popleft()
                step = m1[s]
                s = list(s)
                for i in range(len(s)):
                    ch = s[i]
                    for j in range(26):
                        s[i] = chr(ord('a') + j)
                        t = ''.join(s)
                        if t in m1 or t not in words:
                            continue
                        if t in m2:
                            return step + 1 + m2[t]
                        m1[t] = step + 1
                        q.append(t)
                    s[i] = ch
            return -1

        words = set(wordList)
        if endWord not in words:
            return 0
        q1, q2 = deque([beginWord]), deque([endWord])
        m1, m2 = {beginWord: 0}, {endWord: 0}
        while q1 and q2:
            t = extend(m1, m2, q1) if len(q1) <= len(q2) else extend(m2, m1, q2)
            if t != -1:
                return t + 1
        return 0
```

#### Java

```java
class Solution {
    private Set<String> words;

    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        words = new HashSet<>(wordList);
        if (!words.contains(endWord)) {
            return 0;
        }
        Queue<String> q1 = new ArrayDeque<>();
        Queue<String> q2 = new ArrayDeque<>();
        Map<String, Integer> m1 = new HashMap<>();
        Map<String, Integer> m2 = new HashMap<>();
        q1.offer(beginWord);
        q2.offer(endWord);
        m1.put(beginWord, 0);
        m2.put(endWord, 0);
        while (!q1.isEmpty() && !q2.isEmpty()) {
            int t = q1.size() <= q2.size() ? extend(m1, m2, q1) : extend(m2, m1, q2);
            if (t != -1) {
                return t + 1;
            }
        }
        return 0;
    }

    private int extend(Map<String, Integer> m1, Map<String, Integer> m2, Queue<String> q) {
        for (int i = q.size(); i > 0; --i) {
            String s = q.poll();
            int step = m1.get(s);
            char[] chars = s.toCharArray();
            for (int j = 0; j < chars.length; ++j) {
                char ch = chars[j];
                for (char k = 'a'; k <= 'z'; ++k) {
                    chars[j] = k;
                    String t = new String(chars);
                    if (!words.contains(t) || m1.containsKey(t)) {
                        continue;
                    }
                    if (m2.containsKey(t)) {
                        return step + 1 + m2.get(t);
                    }
                    q.offer(t);
                    m1.put(t, step + 1);
                }
                chars[j] = ch;
            }
        }
        return -1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (!words.count(endWord)) return 0;
        queue<string> q1{{beginWord}};
        queue<string> q2{{endWord}};
        unordered_map<string, int> m1;
        unordered_map<string, int> m2;
        m1[beginWord] = 0;
        m2[endWord] = 0;
        while (!q1.empty() && !q2.empty()) {
            int t = q1.size() <= q2.size() ? extend(m1, m2, q1, words) : extend(m2, m1, q2, words);
            if (t != -1) return t + 1;
        }
        return 0;
    }

    int extend(unordered_map<string, int>& m1, unordered_map<string, int>& m2, queue<string>& q, unordered_set<string>& words) {
        for (int i = q.size(); i > 0; --i) {
            string s = q.front();
            int step = m1[s];
            q.pop();
            for (int j = 0; j < s.size(); ++j) {
                char ch = s[j];
                for (char k = 'a'; k <= 'z'; ++k) {
                    s[j] = k;
                    if (!words.count(s) || m1.count(s)) continue;
                    if (m2.count(s)) return step + 1 + m2[s];
                    m1[s] = step + 1;
                    q.push(s);
                }
                s[j] = ch;
            }
        }
        return -1;
    }
};
```

#### Go

```go
func ladderLength(beginWord string, endWord string, wordList []string) int {
	words := make(map[string]bool)
	for _, word := range wordList {
		words[word] = true
	}
	if !words[endWord] {
		return 0
	}

	q1, q2 := []string{beginWord}, []string{endWord}
	m1, m2 := map[string]int{beginWord: 0}, map[string]int{endWord: 0}
	extend := func() int {
		for i := len(q1); i > 0; i-- {
			s := q1[0]
			step, _ := m1[s]
			q1 = q1[1:]
			chars := []byte(s)
			for j := 0; j < len(chars); j++ {
				ch := chars[j]
				for k := 'a'; k <= 'z'; k++ {
					chars[j] = byte(k)
					t := string(chars)
					if !words[t] {
						continue
					}
					if _, ok := m1[t]; ok {
						continue
					}
					if v, ok := m2[t]; ok {
						return step + 1 + v
					}
					q1 = append(q1, t)
					m1[t] = step + 1
				}
				chars[j] = ch
			}
		}
		return -1
	}
	for len(q1) > 0 && len(q2) > 0 {
		if len(q1) > len(q2) {
			m1, m2 = m2, m1
			q1, q2 = q2, q1
		}
		t := extend()
		if t != -1 {
			return t + 1
		}
	}
	return 0
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [128. 最长连续序列](https://leetcode.cn/problems/longest-consecutive-sequence){#128}

{{< tabs "128" >}}

{{% tab "python" %}}
```python
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        s = set(nums)
        ans = 0
        for x in s:
            if x - 1 not in s:
                y = x + 1
                while y in s:
                    y += 1
                ans = max(ans, y - x)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> s = new HashSet<>();
        for (int x : nums) {
            s.add(x);
        }
        int ans = 0;
        for (int x : s) {
            if (!s.contains(x - 1)) {
                int y = x + 1;
                while (s.contains(y)) {
                    ++y;
                }
                ans = Math.max(ans, y - x);
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
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;
        for (int x : s) {
            if (!s.contains(x - 1)) {
                int y = x + 1;
                while (s.contains(y)) {
                    y++;
                }
                ans = max(ans, y - x);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func longestConsecutive(nums []int) (ans int) {
	s := map[int]bool{}
	for _, x := range nums {
		s[x] = true
	}
	for x, _ := range s {
		if !s[x-1] {
			y := x + 1
			for s[y] {
				y++
			}
			ans = max(ans, y-x)
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function longestConsecutive(nums: number[]): number {
    const s = new Set<number>(nums);
    let ans = 0;
    for (const x of s) {
        if (!s.has(x - 1)) {
            let y = x + 1;
            while (s.has(y)) {
                y++;
            }
            ans = Math.max(ans, y - x);
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashSet;

impl Solution {
    pub fn longest_consecutive(nums: Vec<i32>) -> i32 {
        let s: HashSet<i32> = nums.iter().cloned().collect();
        let mut ans = 0;
        for &x in &s {
            if !s.contains(&(x - 1)) {
                let mut y = x + 1;
                while s.contains(&y) {
                    y += 1;
                }
                ans = ans.max(y - x);
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
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function (nums) {
    const s = new Set(nums);
    let ans = 0;
    for (const x of nums) {
        if (!s.has(x - 1)) {
            let y = x + 1;
            while (s.has(y)) {
                y++;
            }
            ans = Math.max(ans, y - x);
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

<p>给定一个未排序的整数数组 <code>nums</code> ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。</p>

<p>请你设计并实现时间复杂度为&nbsp;<code>O(n)</code><em> </em>的算法解决此问题。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [100,4,200,1,3,2]
<strong>输出：</strong>4
<strong>解释：</strong>最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,3,7,2,5,8,4,6,0,1]
<strong>输出：</strong>9
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,0,1,2]
<b>输出：</b>3
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们可以用一个哈希表 $\textit{s}$ 存储数组中所有的元素，用一个变量 $\textit{ans}$ 记录最长连续序列的长度，用一个哈希表 $\textit{d}$ 记录每个元素 $x$ 所在的连续序列的长度。

接下来，我们遍历数组中每个元素 $x$，用一个临时变量 $y$ 记录当前连续序列的最大值，初始时 $y = x$。然后，我们不断尝试匹配 $y+1, y+2, y+3, \dots$，直到匹配不到为止，过程中将匹配到的元素从哈希表 $\textit{s}$ 中移除。那么，当前元素 $x$ 所在的连续序列的长度即为 $d[x] = d[y] + y - x$，然后更新答案 $\textit{ans} = \max(\textit{ans}, d[x])$。

遍历结束后，返回答案 $\textit{ans}$ 即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        s = set(nums)
        ans = 0
        d = defaultdict(int)
        for x in nums:
            y = x
            while y in s:
                s.remove(y)
                y += 1
            d[x] = d[y] + y - x
            ans = max(ans, d[x])
        return ans
```

#### Java

```java
class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> s = new HashSet<>();
        for (int x : nums) {
            s.add(x);
        }
        int ans = 0;
        Map<Integer, Integer> d = new HashMap<>();
        for (int x : nums) {
            int y = x;
            while (s.contains(y)) {
                s.remove(y++);
            }
            d.put(x, d.getOrDefault(y, 0) + y - x);
            ans = Math.max(ans, d.get(x));
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;
        unordered_map<int, int> d;
        for (int x : nums) {
            int y = x;
            while (s.contains(y)) {
                s.erase(y++);
            }
            d[x] = (d.contains(y) ? d[y] : 0) + y - x;
            ans = max(ans, d[x]);
        }
        return ans;
    }
};
```

#### Go

```go
func longestConsecutive(nums []int) (ans int) {
	s := map[int]bool{}
	for _, x := range nums {
		s[x] = true
	}
	d := map[int]int{}
	for _, x := range nums {
		y := x
		for s[y] {
			delete(s, y)
			y++
		}
		d[x] = d[y] + y - x
		ans = max(ans, d[x])
	}
	return
}
```

#### TypeScript

```ts
function longestConsecutive(nums: number[]): number {
    const s = new Set(nums);
    let ans = 0;
    const d = new Map<number, number>();
    for (const x of nums) {
        let y = x;
        while (s.has(y)) {
            s.delete(y++);
        }
        d.set(x, (d.get(y) || 0) + (y - x));
        ans = Math.max(ans, d.get(x)!);
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::{HashMap, HashSet};

impl Solution {
    pub fn longest_consecutive(nums: Vec<i32>) -> i32 {
        let mut s: HashSet<i32> = nums.iter().cloned().collect();
        let mut ans = 0;
        let mut d: HashMap<i32, i32> = HashMap::new();
        for &x in &nums {
            let mut y = x;
            while s.contains(&y) {
                s.remove(&y);
                y += 1;
            }
            let length = d.get(&(y)).unwrap_or(&0) + y - x;
            d.insert(x, length);
            ans = ans.max(length);
        }
        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function (nums) {
    const s = new Set(nums);
    let ans = 0;
    const d = new Map();
    for (const x of nums) {
        let y = x;
        while (s.has(y)) {
            s.delete(y++);
        }
        d.set(x, (d.get(y) || 0) + (y - x));
        ans = Math.max(ans, d.get(x));
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：哈希表（优化）

与方法一类似，我们用一个哈希表 $\textit{s}$ 存储数组中所有的元素，用一个变量 $\textit{ans}$ 记录最长连续序列的长度。但是，我们不再使用哈希表 $\textit{d}$ 记录每个元素 $x$ 所在的连续序列的长度，在遍历的过程中，跳过那些 $x-1$ 也在哈希表 $\textit{s}$ 中的元素，如果 $x-1$ 在哈希表 $\textit{s}$ 中，那么 $x$ 一定不是连续序列的起点，因此我们可以直接跳过 $x$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        s = set(nums)
        ans = 0
        for x in s:
            if x - 1 not in s:
                y = x + 1
                while y in s:
                    y += 1
                ans = max(ans, y - x)
        return ans
```

#### Java

```java
class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> s = new HashSet<>();
        for (int x : nums) {
            s.add(x);
        }
        int ans = 0;
        for (int x : s) {
            if (!s.contains(x - 1)) {
                int y = x + 1;
                while (s.contains(y)) {
                    ++y;
                }
                ans = Math.max(ans, y - x);
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
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;
        for (int x : s) {
            if (!s.contains(x - 1)) {
                int y = x + 1;
                while (s.contains(y)) {
                    y++;
                }
                ans = max(ans, y - x);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func longestConsecutive(nums []int) (ans int) {
	s := map[int]bool{}
	for _, x := range nums {
		s[x] = true
	}
	for x, _ := range s {
		if !s[x-1] {
			y := x + 1
			for s[y] {
				y++
			}
			ans = max(ans, y-x)
		}
	}
	return
}
```

#### TypeScript

```ts
function longestConsecutive(nums: number[]): number {
    const s = new Set<number>(nums);
    let ans = 0;
    for (const x of s) {
        if (!s.has(x - 1)) {
            let y = x + 1;
            while (s.has(y)) {
                y++;
            }
            ans = Math.max(ans, y - x);
        }
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::HashSet;

impl Solution {
    pub fn longest_consecutive(nums: Vec<i32>) -> i32 {
        let s: HashSet<i32> = nums.iter().cloned().collect();
        let mut ans = 0;
        for &x in &s {
            if !s.contains(&(x - 1)) {
                let mut y = x + 1;
                while s.contains(&y) {
                    y += 1;
                }
                ans = ans.max(y - x);
            }
        }
        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function (nums) {
    const s = new Set(nums);
    let ans = 0;
    for (const x of nums) {
        if (!s.has(x - 1)) {
            let y = x + 1;
            while (s.has(y)) {
                y++;
            }
            ans = Math.max(ans, y - x);
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

# [129. 求根节点到叶节点数字之和](https://leetcode.cn/problems/sum-root-to-leaf-numbers){#129}

{{< tabs "129" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        def dfs(root, s):
            if root is None:
                return 0
            s = s * 10 + root.val
            if root.left is None and root.right is None:
                return s
            return dfs(root.left, s) + dfs(root.right, s)

        return dfs(root, 0)
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
    public int sumNumbers(TreeNode root) {
        return dfs(root, 0);
    }

    private int dfs(TreeNode root, int s) {
        if (root == null) {
            return 0;
        }
        s = s * 10 + root.val;
        if (root.left == null && root.right == null) {
            return s;
        }
        return dfs(root.left, s) + dfs(root.right, s);
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
    int sumNumbers(TreeNode* root) {
        function<int(TreeNode*, int)> dfs = [&](TreeNode* root, int s) -> int {
            if (!root) return 0;
            s = s * 10 + root->val;
            if (!root->left && !root->right) return s;
            return dfs(root->left, s) + dfs(root->right, s);
        };
        return dfs(root, 0);
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
func sumNumbers(root *TreeNode) int {
	var dfs func(*TreeNode, int) int
	dfs = func(root *TreeNode, s int) int {
		if root == nil {
			return 0
		}
		s = s*10 + root.Val
		if root.Left == nil && root.Right == nil {
			return s
		}
		return dfs(root.Left, s) + dfs(root.Right, s)
	}
	return dfs(root, 0)
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

function sumNumbers(root: TreeNode | null): number {
    function dfs(root: TreeNode | null, s: number): number {
        if (!root) return 0;
        s = s * 10 + root.val;
        if (!root.left && !root.right) return s;
        return dfs(root.left, s) + dfs(root.right, s);
    }
    return dfs(root, 0);
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
    fn dfs(node: &Option<Rc<RefCell<TreeNode>>>, mut num: i32) -> i32 {
        if node.is_none() {
            return 0;
        }
        let node = node.as_ref().unwrap().borrow();
        num = num * 10 + node.val;
        if node.left.is_none() && node.right.is_none() {
            return num;
        }
        Self::dfs(&node.left, num) + Self::dfs(&node.right, num)
    }

    pub fn sum_numbers(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        Self::dfs(&root, 0)
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
 * @return {number}
 */
var sumNumbers = function (root) {
    function dfs(root, s) {
        if (!root) return 0;
        s = s * 10 + root.val;
        if (!root.left && !root.right) return s;
        return dfs(root.left, s) + dfs(root.right, s);
    }
    return dfs(root, 0);
};
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

int dfs(struct TreeNode* root, int num) {
    if (!root) {
        return 0;
    }
    num = num * 10 + root->val;
    if (!root->left && !root->right) {
        return num;
    }
    return dfs(root->left, num) + dfs(root->right, num);
}

int sumNumbers(struct TreeNode* root) {
    return dfs(root, 0);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

给你一个二叉树的根节点 <code>root</code> ，树中每个节点都存放有一个 <code>0</code> 到 <code>9</code> 之间的数字。

<div class="original__bRMd">
<div>
<p>每条从根节点到叶节点的路径都代表一个数字：</p>

<ul>
	<li>例如，从根节点到叶节点的路径 <code>1 -> 2 -> 3</code> 表示数字 <code>123</code> 。</li>
</ul>

<p>计算从根节点到叶节点生成的 <strong>所有数字之和</strong> 。</p>

<p><strong>叶节点</strong> 是指没有子节点的节点。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0100-0199/0129.Sum%20Root%20to%20Leaf%20Numbers/images/num1tree.jpg" style="width: 212px; height: 182px;" />
<pre>
<strong>输入：</strong>root = [1,2,3]
<strong>输出：</strong>25
<strong>解释：</strong>
从根到叶子节点路径 <code>1->2</code> 代表数字 <code>12</code>
从根到叶子节点路径 <code>1->3</code> 代表数字 <code>13</code>
因此，数字总和 = 12 + 13 = <code>25</code></pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0100-0199/0129.Sum%20Root%20to%20Leaf%20Numbers/images/num2tree.jpg" style="width: 292px; height: 302px;" />
<pre>
<strong>输入：</strong>root = [4,9,0,5,1]
<strong>输出：</strong>1026
<strong>解释：</strong>
从根到叶子节点路径 <code>4->9->5</code> 代表数字 495
从根到叶子节点路径 <code>4->9->1</code> 代表数字 491
从根到叶子节点路径 <code>4->0</code> 代表数字 40
因此，数字总和 = 495 + 491 + 40 = <code>1026</code>
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点的数目在范围 <code>[1, 1000]</code> 内</li>
	<li><code>0 <= Node.val <= 9</code></li>
	<li>树的深度不超过 <code>10</code></li>
</ul>
</div>
</div>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们可以设计一个函数 $dfs(root, s)$，表示从当前节点 $root$ 出发，且当前路径数字为 $s$，返回从当前节点到叶子节点的所有路径数字之和。那么答案就是 $dfs(root, 0)$。

函数 $dfs(root, s)$ 的计算如下：

-   如果当前节点 $root$ 为空，则返回 $0$。
-   否则，将当前节点的值加到 $s$ 中，即 $s = s \times 10 + root.val$。
-   如果当前节点是叶子节点，则返回 $s$。
-   否则，返回 $dfs(root.left, s) + dfs(root.right, s)$。

时间复杂度 $O(n)$，空间复杂度 $O(\log n)$。其中 $n$ 是二叉树的节点数。

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
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        def dfs(root, s):
            if root is None:
                return 0
            s = s * 10 + root.val
            if root.left is None and root.right is None:
                return s
            return dfs(root.left, s) + dfs(root.right, s)

        return dfs(root, 0)
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
    public int sumNumbers(TreeNode root) {
        return dfs(root, 0);
    }

    private int dfs(TreeNode root, int s) {
        if (root == null) {
            return 0;
        }
        s = s * 10 + root.val;
        if (root.left == null && root.right == null) {
            return s;
        }
        return dfs(root.left, s) + dfs(root.right, s);
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
    int sumNumbers(TreeNode* root) {
        function<int(TreeNode*, int)> dfs = [&](TreeNode* root, int s) -> int {
            if (!root) return 0;
            s = s * 10 + root->val;
            if (!root->left && !root->right) return s;
            return dfs(root->left, s) + dfs(root->right, s);
        };
        return dfs(root, 0);
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
func sumNumbers(root *TreeNode) int {
	var dfs func(*TreeNode, int) int
	dfs = func(root *TreeNode, s int) int {
		if root == nil {
			return 0
		}
		s = s*10 + root.Val
		if root.Left == nil && root.Right == nil {
			return s
		}
		return dfs(root.Left, s) + dfs(root.Right, s)
	}
	return dfs(root, 0)
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

function sumNumbers(root: TreeNode | null): number {
    function dfs(root: TreeNode | null, s: number): number {
        if (!root) return 0;
        s = s * 10 + root.val;
        if (!root.left && !root.right) return s;
        return dfs(root.left, s) + dfs(root.right, s);
    }
    return dfs(root, 0);
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
    fn dfs(node: &Option<Rc<RefCell<TreeNode>>>, mut num: i32) -> i32 {
        if node.is_none() {
            return 0;
        }
        let node = node.as_ref().unwrap().borrow();
        num = num * 10 + node.val;
        if node.left.is_none() && node.right.is_none() {
            return num;
        }
        Self::dfs(&node.left, num) + Self::dfs(&node.right, num)
    }

    pub fn sum_numbers(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        Self::dfs(&root, 0)
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
 * @return {number}
 */
var sumNumbers = function (root) {
    function dfs(root, s) {
        if (!root) return 0;
        s = s * 10 + root.val;
        if (!root.left && !root.right) return s;
        return dfs(root.left, s) + dfs(root.right, s);
    }
    return dfs(root, 0);
};
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

int dfs(struct TreeNode* root, int num) {
    if (!root) {
        return 0;
    }
    num = num * 10 + root->val;
    if (!root->left && !root->right) {
        return num;
    }
    return dfs(root->left, num) + dfs(root->right, num);
}

int sumNumbers(struct TreeNode* root) {
    return dfs(root, 0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
