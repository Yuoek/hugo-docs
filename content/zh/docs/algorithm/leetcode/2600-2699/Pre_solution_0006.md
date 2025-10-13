---
title: "2650_设计可取消函数"
date: 2025-10-08T18:39:28+08:00
weight: 6
tags: [JavaScript, 二分查找, 位运算, 哈希表, 并查集, 广度优先搜索, 排序, 数学, 数组, 数论, 有序集合, 树状数组, 深度优先搜索, 滑动窗口, 矩阵, 线段树, 贪心]
---

{{< markmap >}}
### [2650_设计可取消函数](#2650)
#### [JavaScript](#2650)
### [2651_计算列车到站时间](#2651)
#### [数学](#2651)
### [2652_倍数求和](#2652)
#### [数学](#2652)
### [2653_滑动子数组的美丽值](#2653)
#### [数组](#2653)
#### [哈希表](#2653)
#### [滑动窗口](#2653)
### [2654_使数组所有元素变成 1 的最少操作次数](#2654)
#### [数组](#2654)
#### [数学](#2654)
#### [数论](#2654)
### [2655_寻找最大长度的未覆盖区间 🔒](#2655)
#### [数组](#2655)
#### [排序](#2655)
### [2656_K 个元素的最大和](#2656)
#### [贪心](#2656)
#### [数组](#2656)
### [2657_找到两个数组的前缀公共数组](#2657)
#### [位运算](#2657)
#### [数组](#2657)
#### [哈希表](#2657)
### [2658_网格图中鱼的最大数目](#2658)
#### [深度优先搜索](#2658)
#### [广度优先搜索](#2658)
#### [并查集](#2658)
#### [数组](#2658)
#### [矩阵](#2658)
### [2659_将数组清空](#2659)
#### [贪心](#2659)
#### [树状数组](#2659)
#### [线段树](#2659)
#### [数组](#2659)
#### [二分查找](#2659)
#### [有序集合](#2659)
#### [排序](#2659)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2650_设计可取消函数
___
#### JavaScript
---
### 2651_计算列车到站时间
___
#### 数学
---
### 2652_倍数求和
___
#### 数学
---
### 2653_滑动子数组的美丽值
___
#### 数组
___
#### 哈希表
___
#### 滑动窗口
---
### 2654_使数组所有元素变成 1 的最少操作次数
___
#### 数组
___
#### 数学
___
#### 数论
---
### 2655_寻找最大长度的未覆盖区间 🔒
___
#### 数组
___
#### 排序
---
### 2656_K 个元素的最大和
___
#### 贪心
___
#### 数组
---
### 2657_找到两个数组的前缀公共数组
___
#### 位运算
___
#### 数组
___
#### 哈希表
---
### 2658_网格图中鱼的最大数目
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 并查集
___
#### 数组
___
#### 矩阵
---
### 2659_将数组清空
___
#### 贪心
___
#### 树状数组
___
#### 线段树
___
#### 数组
___
#### 二分查找
___
#### 有序集合
___
#### 排序
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| JavaScript | 二分查找 | 位运算 |
| 哈希表 | 并查集 | 广度优先搜索 |
| 排序 | 数学 | 数组 |
| 数论 | 有序集合 | 树状数组 |
| 深度优先搜索 | 滑动窗口 | 矩阵 |
| 线段树 | 贪心 |  |

# [2650. 设计可取消函数](https://leetcode.cn/problems/design-cancellable-function){#2650}

{{< tabs "2650" >}}

{{% tab "ts" %}}
```ts
function cancellable<T>(generator: Generator<Promise<any>, T, unknown>): [() => void, Promise<T>] {
    let cancel: () => void = () => {};
    const cancelPromise = new Promise((resolve, reject) => {
        cancel = () => reject('Cancelled');
    });
    cancelPromise.catch(() => {});

    const promise = (async () => {
        let next = generator.next();
        while (!next.done) {
            try {
                next = generator.next(await Promise.race([next.value, cancelPromise]));
            } catch (e) {
                next = generator.throw(e);
            }
        }
        return next.value;
    })();

    return [cancel, promise];
}

/**
 * function* tasks() {
 *   const val = yield new Promise(resolve => resolve(2 + 2));
 *   yield new Promise(resolve => setTimeout(resolve, 100));
 *   return val + 1;
 * }
 * const [cancel, promise] = cancellable(tasks());
 * setTimeout(cancel, 50);
 * promise.catch(console.log); // logs "Cancelled" at t=50ms
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有时候你会有一个长时间运行的任务，并且你可能希望在它完成之前取消它。为了实现这个目标，请你编写一个名为 <code>cancellable</code> 的函数，它接收一个生成器对象，并返回一个包含两个值的数组：一个 <strong>取消函数</strong> 和一个 <strong>promise</strong> 对象。</p>

<p>你可以假设生成器函数只会生成 promise 对象。你的函数负责将 promise 对象解析的值传回生成器。如果 promise 被拒绝，你的函数应将该错误抛回给生成器。</p>

<p>如果在生成器完成之前调用了取消回调函数，则你的函数应该将错误抛回给生成器。该错误应该是字符串 <code>"Cancelled"</code>（而不是一个 <code>Error</code> 对象）。如果错误被捕获，则返回的 promise 应该解析为下一个生成或返回的值。否则，promise 应该被拒绝并抛出该错误。不应执行任何其他代码。</p>

<p>当生成器完成时，您的函数返回的 promise 应该解析为生成器返回的值。但是，如果生成器抛出错误，则返回的 promise 应该拒绝并抛出该错误。</p>

<p>下面的示例展示了你的代码会如何被使用：</p>

<pre>
function* tasks() {
  const val = yield new Promise(resolve =&gt; resolve(2 + 2));
  yield new Promise(resolve =&gt; setTimeout(resolve, 100));
  return val + 1; // calculation shouldn't be done.
}
const [cancel, promise] = cancellable(tasks());
setTimeout(cancel, 50);
promise.catch(console.log); // logs "Cancelled" at t=50ms
</pre>

<p>相反，如果 <code>cancel()</code> 没有被调用或者在 <code>t=100ms</code> 之后才被调用，那么 promise 应被解析为 <code>5</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
generatorFunction = function*() { 
&nbsp; return 42; 
}
cancelledAt = 100
<strong>输出：</strong>{"resolved": 42}
<strong>解释：</strong>
const generator = generatorFunction();
const [cancel, promise] = cancellable(generator);
setTimeout(cancel, 100);
promise.then(console.log); // 在 t=0ms 解析为 42

该生成器立即生成 42 并完成。因此，返回的 promise 立即解析为 42。请注意，取消已经完成的生成器没有任何作用。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>
generatorFunction = function*() { 
&nbsp; const msg = yield new Promise(res =&gt; res("Hello")); 
&nbsp; throw `Error: ${msg}`; 
}
cancelledAt = null
<strong>输出：</strong>{"rejected": "Error: Hello"}
<strong>解释：</strong>
一个 Promise 被生成。该函数通过等待 promise 解析并将解析后的值传回生成器来处理它。然后抛出一个错误，这会导致 promise 被同样抛出的错误拒绝。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>
generatorFunction = function*() { 
&nbsp; yield new Promise(res =&gt; setTimeout(res, 200)); 
&nbsp; return "Success"; 
}
cancelledAt = 100
<strong>输出：</strong>{"rejected": "Cancelled"}
<strong>解释：</strong>
当函数等待被生成的 promise 解析时，cancel() 被调用。这会导致一个错误消息被发送回生成器。由于这个错误没有被捕获，返回的 promise 会因为这个错误而被拒绝。
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>
generatorFunction = function*() { 
&nbsp; let result = 0; 
&nbsp; yield new Promise(res =&gt; setTimeout(res, 100));
&nbsp; result += yield new Promise(res =&gt; res(1)); 
&nbsp; yield new Promise(res =&gt; setTimeout(res, 100)); 
&nbsp; result += yield new Promise(res =&gt; res(1)); 
&nbsp; return result;
}
cancelledAt = null
<strong>输出：</strong>{"resolved": 2}
<strong>解释：</strong>
生成器生成了 4 个 promise 。其中两个 promise 的值被添加到结果中。200ms 后，生成器以值 2 完成，该值被返回的 promise 解析。
</pre>

<p><strong>示例 5：</strong></p>

<pre>
<strong>输入：</strong>
generatorFunction = function*() { 
&nbsp; let result = 0; 
&nbsp; try { 
&nbsp;   yield new Promise(res =&gt; setTimeout(res, 100)); 
&nbsp;   result += yield new Promise(res =&gt; res(1)); 
&nbsp;   yield new Promise(res =&gt; setTimeout(res, 100)); 
&nbsp;   result += yield new Promise(res =&gt; res(1)); 
&nbsp; } catch(e) { 
&nbsp;   return result; 
&nbsp; } 
&nbsp; return result; 
}
cancelledAt = 150
<strong>输出：</strong>{"resolved": 1}
<strong>解释：</strong>
前两个生成的 promise 解析并导致结果递增。然而，在 t=150ms 时，生成器被取消了。发送给生成器的错误被捕获，结果被返回并最终由返回的 promise 解析。
</pre>

<p><strong>示例 6：</strong></p>

<pre>
<strong>输入：</strong>
generatorFunction = function*() { 
&nbsp; try { 
&nbsp;   yield new Promise((resolve, reject) =&gt; reject("Promise Rejected")); 
&nbsp; } catch(e) { 
&nbsp;   let a = yield new Promise(resolve =&gt; resolve(2));
    let b = yield new Promise(resolve =&gt; resolve(2)); 
&nbsp;   return a + b; 
&nbsp; }; 
}
cancelledAt = null
<strong>输出：</strong>{"resolved": 4}
<strong>解释：</strong>
第一个生成的 promise 立即被拒绝。该错误被捕获。因为生成器没有被取消，执行继续像往常一样。最终解析为 2 + 2 = 4。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>cancelledAt == null or 0 &lt;= cancelledAt &lt;= 1000</code></li>
	<li><code>generatorFunction</code> 返回一个生成器对象</li>
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

#### TypeScript

```ts
function cancellable<T>(generator: Generator<Promise<any>, T, unknown>): [() => void, Promise<T>] {
    let cancel: () => void = () => {};
    const cancelPromise = new Promise((resolve, reject) => {
        cancel = () => reject('Cancelled');
    });
    cancelPromise.catch(() => {});

    const promise = (async () => {
        let next = generator.next();
        while (!next.done) {
            try {
                next = generator.next(await Promise.race([next.value, cancelPromise]));
            } catch (e) {
                next = generator.throw(e);
            }
        }
        return next.value;
    })();

    return [cancel, promise];
}

/**
 * function* tasks() {
 *   const val = yield new Promise(resolve => resolve(2 + 2));
 *   yield new Promise(resolve => setTimeout(resolve, 100));
 *   return val + 1;
 * }
 * const [cancel, promise] = cancellable(tasks());
 * setTimeout(cancel, 50);
 * promise.catch(console.log); // logs "Cancelled" at t=50ms
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2651. 计算列车到站时间](https://leetcode.cn/problems/calculate-delayed-arrival-time){#2651}

{{< tabs "2651" >}}

{{% tab "python" %}}
```python
class Solution:
    def findDelayedArrivalTime(self, arrivalTime: int, delayedTime: int) -> int:
        return (arrivalTime + delayedTime) % 24
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        return (arrivalTime + delayedTime) % 24;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        return (arrivalTime + delayedTime) % 24;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findDelayedArrivalTime(arrivalTime int, delayedTime int) int {
	return (arrivalTime + delayedTime) % 24
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findDelayedArrivalTime(arrivalTime: number, delayedTime: number): number {
    return (arrivalTime + delayedTime) % 24;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn find_delayed_arrival_time(arrival_time: i32, delayed_time: i32) -> i32 {
        (arrival_time + delayed_time) % 24
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个正整数 <code>arrivalTime</code> 表示列车正点到站的时间（单位：小时），另给你一个正整数 <code>delayedTime</code> 表示列车延误的小时数。</p>

<p>返回列车实际到站的时间。</p>

<p>注意，该问题中的时间采用 24 小时制。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arrivalTime = 15, delayedTime = 5 
<strong>输出：</strong>20 
<strong>解释：</strong>列车正点到站时间是 15:00 ，延误 5 小时，所以列车实际到站的时间是 15 + 5 = 20（20:00）。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arrivalTime = 13, delayedTime = 11
<strong>输出：</strong>0
<strong>解释：</strong>列车正点到站时间是 13:00 ，延误 11 小时，所以列车实际到站的时间是 13 + 11 = 24（在 24 小时制中表示为 00:00 ，所以返回 0）。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arrivaltime &lt;&nbsp;24</code></li>
	<li><code>1 &lt;= delayedTime &lt;= 24</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学

我们直接计算列车实际到站的时间，即为 $arrivalTime + delayedTime$，但是由于时间采用 24 小时制，所以我们需要对结果取模，即 $(arrivalTime + delayedTime) \bmod 24$。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findDelayedArrivalTime(self, arrivalTime: int, delayedTime: int) -> int:
        return (arrivalTime + delayedTime) % 24
```

#### Java

```java
class Solution {
    public int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        return (arrivalTime + delayedTime) % 24;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        return (arrivalTime + delayedTime) % 24;
    }
};
```

#### Go

```go
func findDelayedArrivalTime(arrivalTime int, delayedTime int) int {
	return (arrivalTime + delayedTime) % 24
}
```

#### TypeScript

```ts
function findDelayedArrivalTime(arrivalTime: number, delayedTime: number): number {
    return (arrivalTime + delayedTime) % 24;
}
```

#### Rust

```rust
impl Solution {
    pub fn find_delayed_arrival_time(arrival_time: i32, delayed_time: i32) -> i32 {
        (arrival_time + delayed_time) % 24
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2652. 倍数求和](https://leetcode.cn/problems/sum-multiples){#2652}

{{< tabs "2652" >}}

{{% tab "python" %}}
```python
class Solution:
    def sumOfMultiples(self, n: int) -> int:
        def f(x: int) -> int:
            m = n // x
            return (x + m * x) * m // 2

        return f(3) + f(5) + f(7) - f(3 * 5) - f(3 * 7) - f(5 * 7) + f(3 * 5 * 7)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int n;

    public int sumOfMultiples(int n) {
        this.n = n;
        return f(3) + f(5) + f(7) - f(3 * 5) - f(3 * 7) - f(5 * 7) + f(3 * 5 * 7);
    }

    private int f(int x) {
        int m = n / x;
        return (x + m * x) * m / 2;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int sumOfMultiples(int n) {
        auto f = [&](int x) {
            int m = n / x;
            return (x + m * x) * m / 2;
        };
        return f(3) + f(5) + f(7) - f(3 * 5) - f(3 * 7) - f(5 * 7) + f(3 * 5 * 7);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sumOfMultiples(n int) int {
	f := func(x int) int {
		m := n / x
		return (x + m*x) * m / 2
	}
	return f(3) + f(5) + f(7) - f(3*5) - f(3*7) - f(5*7) + f(3*5*7)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function sumOfMultiples(n: number): number {
    const f = (x: number): number => {
        const m = Math.floor(n / x);
        return ((x + m * x) * m) >> 1;
    };
    return f(3) + f(5) + f(7) - f(3 * 5) - f(3 * 7) - f(5 * 7) + f(3 * 5 * 7);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn sum_of_multiples(n: i32) -> i32 {
        fn f(x: i32, n: i32) -> i32 {
            let m = n / x;
            ((x + m * x) * m) / 2
        }

        f(3, n) + f(5, n) + f(7, n) - f(3 * 5, n) - f(3 * 7, n) - f(5 * 7, n) + f(3 * 5 * 7, n)
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个正整数 <code>n</code> ，请你计算在 <code>[1，n]</code> 范围内能被 <code>3</code>、<code>5</code>、<code>7</code> 整除的所有整数之和。</p>

<p>返回一个整数，用于表示给定范围内所有满足约束条件的数字之和。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 7
<strong>输出：</strong>21
<strong>解释：</strong>在 <code>[1, 7]</code> 范围内能被 <code>3</code>、<code>5</code>、<code>7</code> 整除的所有整数分别是 <code>3</code>、<code>5</code>、<code>6</code>、<code>7</code> 。数字之和为 <code>21</code>。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 10
<strong>输出：</strong>40
<strong>解释：</strong>在 <code>[1, 10]</code> 范围内能被 <code>3</code>、<code>5</code>、<code>7</code> 整除的所有整数分别是 <code>3</code>、<code>5</code>、<code>6</code>、<code>7</code>、<code>9</code>、<code>10</code> 。数字之和为 <code>40</code>。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 9
<strong>输出：</strong>30
<strong>解释：</strong>在 <code>[1, 9]</code> 范围内能被 <code>3</code>、<code>5</code>、<code>7</code> 整除的所有整数分别是 <code>3</code>、<code>5</code>、<code>6</code>、<code>7</code>、<code>9</code> 。数字之和为 <code>30</code>。
</pre>

<p><strong>提示：</strong></p>

<ul>
	<li>1 &lt;= n &lt;= 10<sup>3</sup></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们直接枚举 $[1,..n]$ 中的每一个数 $x$，如果 $x$ 能被 $3$, $5$, $7$ 整除，那么就将 $x$ 累加到答案中。

枚举结束后，返回答案即可。

时间复杂度 $O(n)$，其中 $n$ 为题目给定的整数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sumOfMultiples(self, n: int) -> int:
        return sum(x for x in range(1, n + 1) if x % 3 == 0 or x % 5 == 0 or x % 7 == 0)
```

#### Java

```java
class Solution {
    public int sumOfMultiples(int n) {
        int ans = 0;
        for (int x = 1; x <= n; ++x) {
            if (x % 3 == 0 || x % 5 == 0 || x % 7 == 0) {
                ans += x;
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
    int sumOfMultiples(int n) {
        int ans = 0;
        for (int x = 1; x <= n; ++x) {
            if (x % 3 == 0 || x % 5 == 0 || x % 7 == 0) {
                ans += x;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func sumOfMultiples(n int) (ans int) {
	for x := 1; x <= n; x++ {
		if x%3 == 0 || x%5 == 0 || x%7 == 0 {
			ans += x
		}
	}
	return
}
```

#### TypeScript

```ts
function sumOfMultiples(n: number): number {
    let ans = 0;
    for (let x = 1; x <= n; ++x) {
        if (x % 3 === 0 || x % 5 === 0 || x % 7 === 0) {
            ans += x;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn sum_of_multiples(n: i32) -> i32 {
        let mut ans = 0;

        for x in 1..=n {
            if x % 3 == 0 || x % 5 == 0 || x % 7 == 0 {
                ans += x;
            }
        }

        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：数学（容斥原理）

我们定义函数 $f(x)$ 表示 $[1,..n]$ 中能被 $x$ 整除的数之和，那么一共有 $m = \left\lfloor \frac{n}{x} \right\rfloor$ 个数能被 $x$ 整除，这些数字分别为 $x$, $2x$, $3x$, $\cdots$, $mx$，构成一个等差数列，首项为 $x$，末项为 $mx$，项数为 $m$，因此 $f(x) = \frac{(x + mx) \times m}{2}$。

根据容斥原理，我们可以得到答案为：

$$
f(3) + f(5) + f(7) - f(3 \times 5) - f(3 \times 7) - f(5 \times 7) + f(3 \times 5 \times 7)
$$

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sumOfMultiples(self, n: int) -> int:
        def f(x: int) -> int:
            m = n // x
            return (x + m * x) * m // 2

        return f(3) + f(5) + f(7) - f(3 * 5) - f(3 * 7) - f(5 * 7) + f(3 * 5 * 7)
```

#### Java

```java
class Solution {
    private int n;

    public int sumOfMultiples(int n) {
        this.n = n;
        return f(3) + f(5) + f(7) - f(3 * 5) - f(3 * 7) - f(5 * 7) + f(3 * 5 * 7);
    }

    private int f(int x) {
        int m = n / x;
        return (x + m * x) * m / 2;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int sumOfMultiples(int n) {
        auto f = [&](int x) {
            int m = n / x;
            return (x + m * x) * m / 2;
        };
        return f(3) + f(5) + f(7) - f(3 * 5) - f(3 * 7) - f(5 * 7) + f(3 * 5 * 7);
    }
};
```

#### Go

```go
func sumOfMultiples(n int) int {
	f := func(x int) int {
		m := n / x
		return (x + m*x) * m / 2
	}
	return f(3) + f(5) + f(7) - f(3*5) - f(3*7) - f(5*7) + f(3*5*7)
}
```

#### TypeScript

```ts
function sumOfMultiples(n: number): number {
    const f = (x: number): number => {
        const m = Math.floor(n / x);
        return ((x + m * x) * m) >> 1;
    };
    return f(3) + f(5) + f(7) - f(3 * 5) - f(3 * 7) - f(5 * 7) + f(3 * 5 * 7);
}
```

#### Rust

```rust
impl Solution {
    pub fn sum_of_multiples(n: i32) -> i32 {
        (1..=n)
            .filter(|&x| (x % 3 == 0 || x % 5 == 0 || x % 7 == 0))
            .sum()
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三

<!-- tabs:start -->

#### Rust

```rust
impl Solution {
    pub fn sum_of_multiples(n: i32) -> i32 {
        fn f(x: i32, n: i32) -> i32 {
            let m = n / x;
            ((x + m * x) * m) / 2
        }

        f(3, n) + f(5, n) + f(7, n) - f(3 * 5, n) - f(3 * 7, n) - f(5 * 7, n) + f(3 * 5 * 7, n)
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2653. 滑动子数组的美丽值](https://leetcode.cn/problems/sliding-subarray-beauty){#2653}

{{< tabs "2653" >}}

{{% tab "python" %}}
```python
class MedianFinder:
    def __init__(self, x: int):
        self.x = x
        self.small = []
        self.large = []
        self.delayed = defaultdict(int)
        self.small_size = 0
        self.large_size = 0

    def add_num(self, num: int):
        if self.small_size < self.x or num <= -self.small[0]:
            heappush(self.small, -num)
            self.small_size += 1
        else:
            heappush(self.large, num)
            self.large_size += 1
        self.rebalance()

    def find(self) -> float:
        return -self.small[0] if self.small_size == self.x else 0

    def remove_num(self, num: int):
        self.delayed[num] += 1
        if num <= -self.small[0]:
            self.small_size -= 1
            if num == -self.small[0]:
                self.prune(self.small)
        else:
            self.large_size -= 1
            if num == self.large[0]:
                self.prune(self.large)
        self.rebalance()

    def prune(self, pq: List[int]):
        sign = -1 if pq is self.small else 1
        while pq and sign * pq[0] in self.delayed:
            self.delayed[sign * pq[0]] -= 1
            if self.delayed[sign * pq[0]] == 0:
                self.delayed.pop(sign * pq[0])
            heappop(pq)

    def rebalance(self):
        if self.small_size > self.x:
            heappush(self.large, -heappop(self.small))
            self.small_size -= 1
            self.large_size += 1
            self.prune(self.small)
        elif self.small_size < self.x and self.large_size > 0:
            heappush(self.small, -heappop(self.large))
            self.large_size -= 1
            self.small_size += 1
            self.prune(self.large)


class Solution:
    def getSubarrayBeauty(self, nums: List[int], k: int, x: int) -> List[int]:
        finder = MedianFinder(x)
        for i in range(k):
            if nums[i] < 0:
                finder.add_num(nums[i])
        ans = [finder.find()]
        for i in range(k, len(nums)):
            if nums[i] < 0:
                finder.add_num(nums[i])
            if nums[i - k] < 0:
                finder.remove_num(nums[i - k])
            ans.append(finder.find())
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class MedianFinder {
    private PriorityQueue<Integer> small = new PriorityQueue<>(Comparator.reverseOrder());
    private PriorityQueue<Integer> large = new PriorityQueue<>();
    private Map<Integer, Integer> delayed = new HashMap<>();
    private int smallSize;
    private int largeSize;
    private int x;

    public MedianFinder(int x) {
        this.x = x;
    }

    public void addNum(int num) {
        if (smallSize < x || num <= small.peek()) {
            small.offer(num);
            ++smallSize;
        } else {
            large.offer(num);
            ++largeSize;
        }
        rebalance();
    }

    public int find() {
        return smallSize == x ? small.peek() : 0;
    }

    public void removeNum(int num) {
        delayed.merge(num, 1, Integer::sum);
        if (num <= small.peek()) {
            --smallSize;
            if (num == small.peek()) {
                prune(small);
            }
        } else {
            --largeSize;
            if (num == large.peek()) {
                prune(large);
            }
        }
        rebalance();
    }

    private void prune(PriorityQueue<Integer> pq) {
        while (!pq.isEmpty() && delayed.containsKey(pq.peek())) {
            if (delayed.merge(pq.peek(), -1, Integer::sum) == 0) {
                delayed.remove(pq.peek());
            }
            pq.poll();
        }
    }

    private void rebalance() {
        if (smallSize > x) {
            large.offer(small.poll());
            --smallSize;
            ++largeSize;
            prune(small);
        } else if (smallSize < x && largeSize > 0) {
            small.offer(large.poll());
            --largeSize;
            ++smallSize;
            prune(large);
        }
    }
}

class Solution {
    public int[] getSubarrayBeauty(int[] nums, int k, int x) {
        MedianFinder finder = new MedianFinder(x);
        for (int i = 0; i < k; ++i) {
            if (nums[i] < 0) {
                finder.addNum(nums[i]);
            }
        }
        int n = nums.length;
        int[] ans = new int[n - k + 1];
        ans[0] = finder.find();
        for (int i = k; i < n; ++i) {
            if (nums[i] < 0) {
                finder.addNum(nums[i]);
            }
            if (nums[i - k] < 0) {
                finder.removeNum(nums[i - k]);
            }
            ans[i - k + 1] = finder.find();
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class MedianFinder {
public:
    MedianFinder(int x) {
        this->x = x;
    }

    void addNum(int num) {
        if (smallSize < x || num <= small.top()) {
            small.push(num);
            ++smallSize;
        } else {
            large.push(num);
            ++largeSize;
        }
        reblance();
    }

    void removeNum(int num) {
        ++delayed[num];
        if (num <= small.top()) {
            --smallSize;
            if (num == small.top()) {
                prune(small);
            }
        } else {
            --largeSize;
            if (num == large.top()) {
                prune(large);
            }
        }
        reblance();
    }

    int find() {
        return smallSize == x ? small.top() : 0;
    }

private:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;
    unordered_map<int, int> delayed;
    int smallSize = 0;
    int largeSize = 0;
    int x;

    template <typename T>
    void prune(T& pq) {
        while (!pq.empty() && delayed[pq.top()]) {
            if (--delayed[pq.top()] == 0) {
                delayed.erase(pq.top());
            }
            pq.pop();
        }
    }

    void reblance() {
        if (smallSize > x) {
            large.push(small.top());
            small.pop();
            --smallSize;
            ++largeSize;
            prune(small);
        } else if (smallSize < x && largeSize > 0) {
            small.push(large.top());
            large.pop();
            ++smallSize;
            --largeSize;
            prune(large);
        }
    }
};

class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        MedianFinder finder(x);
        for (int i = 0; i < k; ++i) {
            if (nums[i] < 0) {
                finder.addNum(nums[i]);
            }
        }
        int n = nums.size();
        vector<int> ans;
        ans.push_back(finder.find());
        for (int i = k; i < n; ++i) {
            if (nums[i] < 0) {
                finder.addNum(nums[i]);
            }
            if (nums[i - k] < 0) {
                finder.removeNum(nums[i - k]);
            }
            ans.push_back(finder.find());
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type MedianFinder struct {
	small                hp
	large                hp
	delayed              map[int]int
	smallSize, largeSize int
	x                    int
}

func Constructor(x int) MedianFinder {
	return MedianFinder{hp{}, hp{}, map[int]int{}, 0, 0, x}
}

func (this *MedianFinder) AddNum(num int) {
	if this.smallSize < this.x || num <= -this.small.IntSlice[0] {
		heap.Push(&this.small, -num)
		this.smallSize++
	} else {
		heap.Push(&this.large, num)
		this.largeSize++
	}
	this.rebalance()
}

func (this *MedianFinder) Find() int {
	if this.smallSize == this.x {
		return -this.small.IntSlice[0]
	}
	return 0
}

func (this *MedianFinder) RemoveNum(num int) {
	this.delayed[num]++
	if num <= -this.small.IntSlice[0] {
		this.smallSize--
		if num == -this.small.IntSlice[0] {
			this.prune(&this.small)
		}
	} else {
		this.largeSize--
		if num == this.large.IntSlice[0] {
			this.prune(&this.large)
		}
	}
	this.rebalance()
}

func (this *MedianFinder) prune(pq *hp) {
	sign := 1
	if pq == &this.small {
		sign = -1
	}
	for pq.Len() > 0 && this.delayed[sign*pq.IntSlice[0]] > 0 {
		this.delayed[sign*pq.IntSlice[0]]--
		if this.delayed[sign*pq.IntSlice[0]] == 0 {
			delete(this.delayed, sign*pq.IntSlice[0])
		}
		heap.Pop(pq)
	}
}

func (this *MedianFinder) rebalance() {
	if this.smallSize > this.x {
		heap.Push(&this.large, -heap.Pop(&this.small).(int))
		this.smallSize--
		this.largeSize++
		this.prune(&this.small)
	} else if this.smallSize < this.x && this.largeSize > 0 {
		heap.Push(&this.small, -heap.Pop(&this.large).(int))
		this.smallSize++
		this.largeSize--
		this.prune(&this.large)
	}
}

type hp struct{ sort.IntSlice }

func (h hp) Less(i, j int) bool { return h.IntSlice[i] < h.IntSlice[j] }
func (h *hp) Push(v any)        { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() any {
	a := h.IntSlice
	v := a[len(a)-1]
	h.IntSlice = a[:len(a)-1]
	return v
}

func getSubarrayBeauty(nums []int, k int, x int) []int {
	finder := Constructor(x)
	for _, num := range nums[:k] {
		if num < 0 {
			finder.AddNum(num)
		}
	}
	ans := []int{finder.Find()}
	for i := k; i < len(nums); i++ {
		if nums[i] < 0 {
			finder.AddNum(nums[i])
		}
		if nums[i-k] < 0 {
			finder.RemoveNum(nums[i-k])
		}
		ans = append(ans, finder.Find())
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function getSubarrayBeauty(nums: number[], k: number, x: number): number[] {
    const n = nums.length;
    const cnt: number[] = new Array(101).fill(0);
    for (let i = 0; i < k; ++i) {
        ++cnt[nums[i] + 50];
    }
    const ans: number[] = new Array(n - k + 1);
    const f = (x: number): number => {
        let s = 0;
        for (let i = 0; i < 50; ++i) {
            s += cnt[i];
            if (s >= x) {
                return i - 50;
            }
        }
        return 0;
    };
    ans[0] = f(x);
    for (let i = k, j = 1; i < n; ++i, ++j) {
        cnt[nums[i] + 50]++;
        cnt[nums[i - k] + 50]--;
        ans[j] = f(x);
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

<p>给你一个长度为 <code>n</code>&nbsp;的整数数组&nbsp;<code>nums</code>&nbsp;，请你求出每个长度为&nbsp;<code>k</code>&nbsp;的子数组的 <b>美丽值</b>&nbsp;。</p>

<p>一个子数组的 <strong>美丽值</strong>&nbsp;定义为：如果子数组中第 <code>x</code>&nbsp;<strong>小整数</strong>&nbsp;是 <strong>负数</strong>&nbsp;，那么美丽值为第 <code>x</code>&nbsp;小的数，否则美丽值为 <code>0</code>&nbsp;。</p>

<p>请你返回一个包含<em>&nbsp;</em><code>n - k + 1</code>&nbsp;个整数的数组，<strong>依次</strong>&nbsp;表示数组中从第一个下标开始，每个长度为&nbsp;<code>k</code>&nbsp;的子数组的<strong>&nbsp;美丽值</strong>&nbsp;。</p>

<ul>
	<li>
	<p>子数组指的是数组中一段连续 <strong>非空</strong>&nbsp;的元素序列。</p>
	</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [1,-1,-3,-2,3], k = 3, x = 2
<b>输出：</b>[-1,-2,-2]
<b>解释：</b>总共有 3 个 k = 3 的子数组。
第一个子数组是 <code>[1, -1, -3]</code> ，第二小的数是负数 -1 。
第二个子数组是 <code>[-1, -3, -2]</code> ，第二小的数是负数 -2 。
第三个子数组是 <code>[-3, -2, 3]&nbsp;，第二小的数是负数 -2 。</code></pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [-1,-2,-3,-4,-5], k = 2, x = 2
<b>输出：</b>[-1,-2,-3,-4]
<b>解释：</b>总共有 4 个 k = 2 的子数组。
<code>[-1, -2] 中第二小的数是负数 -1 。</code>
<code>[-2, -3] 中第二小的数是负数 -2 。</code>
<code>[-3, -4] 中第二小的数是负数 -3 。</code>
<code>[-4, -5] 中第二小的数是负数 -4 。</code></pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>nums = [-3,1,2,-3,0,-3], k = 2, x = 1
<b>输出：</b>[-3,0,-3,-3,-3]
<b>解释：</b>总共有 5 个 k = 2 的子数组。
<code>[-3, 1] 中最小的数是负数 -3 。</code>
<code>[1, 2] 中最小的数不是负数，所以美丽值为 0 。</code>
<code>[2, -3] 中最小的数是负数 -3 。</code>
<code>[-3, 0] 中最小的数是负数 -3 。</code>
<code>[0, -3] 中最小的数是负数 -3 。</code></pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length&nbsp;</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= n</code></li>
	<li><code>1 &lt;= x &lt;= k&nbsp;</code></li>
	<li><code>-50&nbsp;&lt;= nums[i] &lt;= 50&nbsp;</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：滑动窗口

我们注意到，数组 $nums$ 中元素的范围为 $[-50,50]$，因此，我们可以用一个数组长度为 $101$ 的数组 $cnt$ 统计 $[-50,50]$ 中每个数出现的次数。由于负数的存在，我们可以将每个数加上 $50$，使得每个数都变成非负数，这样就可以用数组 $cnt$ 统计每个数出现的次数了。

接下来，我们遍历数组 $nums$，维护一个长度为 $k$ 的滑动窗口，窗口中所有元素出现的次记数录在数组 $cnt$ 中，然后我们遍历数组 $cnt$，找到第 $x$ 小的负数，即为当前滑动窗口的美丽值。如果不存在第 $x$ 小的负数，那么美丽值为 $0$。

时间复杂度 $O(n \times 50)$，空间复杂度 $O(100)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getSubarrayBeauty(self, nums: List[int], k: int, x: int) -> List[int]:
        def f(x: int) -> int:
            s = 0
            for i in range(50):
                s += cnt[i]
                if s >= x:
                    return i - 50
            return 0

        cnt = [0] * 101
        for v in nums[:k]:
            cnt[v + 50] += 1
        ans = [f(x)]
        for i in range(k, len(nums)):
            cnt[nums[i] + 50] += 1
            cnt[nums[i - k] + 50] -= 1
            ans.append(f(x))
        return ans
```

#### Python3

```python
class Solution:
    def getSubarrayBeauty(self, nums: List[int], k: int, x: int) -> List[int]:
        sl = SortedList(nums[:k])
        ans = [sl[x - 1] if sl[x - 1] < 0 else 0]
        for i in range(k, len(nums)):
            sl.remove(nums[i - k])
            sl.add(nums[i])
            ans.append(sl[x - 1] if sl[x - 1] < 0 else 0)
        return ans
```

#### Java

```java
class Solution {
    public int[] getSubarrayBeauty(int[] nums, int k, int x) {
        int n = nums.length;
        int[] cnt = new int[101];
        for (int i = 0; i < k; ++i) {
            ++cnt[nums[i] + 50];
        }
        int[] ans = new int[n - k + 1];
        ans[0] = f(cnt, x);
        for (int i = k, j = 1; i < n; ++i) {
            ++cnt[nums[i] + 50];
            --cnt[nums[i - k] + 50];
            ans[j++] = f(cnt, x);
        }
        return ans;
    }

    private int f(int[] cnt, int x) {
        int s = 0;
        for (int i = 0; i < 50; ++i) {
            s += cnt[i];
            if (s >= x) {
                return i - 50;
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
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        int cnt[101]{};
        for (int i = 0; i < k; ++i) {
            ++cnt[nums[i] + 50];
        }
        vector<int> ans(n - k + 1);
        auto f = [&](int x) {
            int s = 0;
            for (int i = 0; i < 50; ++i) {
                s += cnt[i];
                if (s >= x) {
                    return i - 50;
                }
            }
            return 0;
        };
        ans[0] = f(x);
        for (int i = k, j = 1; i < n; ++i) {
            ++cnt[nums[i] + 50];
            --cnt[nums[i - k] + 50];
            ans[j++] = f(x);
        }
        return ans;
    }
};
```

#### Go

```go
func getSubarrayBeauty(nums []int, k int, x int) []int {
	n := len(nums)
	cnt := [101]int{}
	for _, x := range nums[:k] {
		cnt[x+50]++
	}
	ans := make([]int, n-k+1)
	f := func(x int) int {
		s := 0
		for i := 0; i < 50; i++ {
			s += cnt[i]
			if s >= x {
				return i - 50
			}
		}
		return 0
	}
	ans[0] = f(x)
	for i, j := k, 1; i < n; i, j = i+1, j+1 {
		cnt[nums[i]+50]++
		cnt[nums[i-k]+50]--
		ans[j] = f(x)
	}
	return ans
}
```

#### TypeScript

```ts
function getSubarrayBeauty(nums: number[], k: number, x: number): number[] {
    const n = nums.length;
    const cnt: number[] = new Array(101).fill(0);
    for (let i = 0; i < k; ++i) {
        ++cnt[nums[i] + 50];
    }
    const ans: number[] = new Array(n - k + 1);
    const f = (x: number): number => {
        let s = 0;
        for (let i = 0; i < 50; ++i) {
            s += cnt[i];
            if (s >= x) {
                return i - 50;
            }
        }
        return 0;
    };
    ans[0] = f(x);
    for (let i = k, j = 1; i < n; ++i, ++j) {
        cnt[nums[i] + 50]++;
        cnt[nums[i - k] + 50]--;
        ans[j] = f(x);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：双优先队列（大小根堆） + 延迟删除

我们可以使用两个优先队列（大小根堆）维护当前窗口中的元素，其中一个优先队列存储当前窗口中较小的 $x$ 个元素，另一个优先队列存储当前窗口中较大的 $k - x$ 个元素。我们还需要一个延迟删除字典 `delayed`，用于记录当前窗口中的元素是否需要删除。

我们设计一个类 `MedianFinder`，用于维护当前窗口中的元素。该类包含以下方法：

-   `add_num(num)`：将 `num` 加入当前窗口中。
-   `find()`：返回当前窗口的美丽值。
-   `remove_num(num)`：将 `num` 从当前窗口中移除。
-   `prune(pq)`：如果堆顶元素在延迟删除字典 `delayed` 中，则将其从堆顶弹出，并从该元素的延迟删除次数中减一。如果该元素的延迟删除次数为零，则将其从延迟删除字典中删除。
-   `rebalance()`：平衡两个优先队列的大小。

在 `add_num(num)` 方法中，我们先考虑将 `num` 加入较小的队列中，如果数量大于 $x$ 或者 `num` 小于等于较小的队列的堆顶元素，则将 `num` 加入较小的队列中；否则，将 `num` 加入较大的队列中。然后我们调用 `rebalance()` 方法，使得较小的队列中的元素数量不超过 $x$。

在 `remove_num(num)` 方法中，我们将 `num` 的延迟删除次数加一。然后我们将 `num` 与较小的队列的堆顶元素进行比较，如果 `num` 小于等于较小的队列的堆顶元素，则更新较小的队列的大小，并且调用 `prune()` 方法，使得较小的队列的堆顶元素不在延迟删除字典中。否则，我们更新较大的队列的大小，并且调用 `prune()` 方法，使得较大的队列的堆顶元素不在延迟删除字典中。

在 `find()` 方法中，如果较小的队列的大小等于 $x$，则返回较小的队列的堆顶元素，否则返回 $0$。

在 `prune(pq)` 方法中，如果堆顶元素在延迟删除字典中，则将其从堆顶弹出，并从该元素的延迟删除次数中减一。如果该元素的延迟删除次数为零，则将其从延迟删除字典中删除。

在 `rebalance()` 方法中，如果较小的队列的大小大于 $x$，则将较小的队列的堆顶元素加入较大的队列中，并调用 `prune()` 方法，使得较小的队列的堆顶元素不在延迟删除字典中。如果较小的队列的大小小于 $x$ 且较大的队列的大小大于 $0$，则将较大的队列的堆顶元素加入较小的队列中，并调用 `prune()` 方法，使得较大的队列的堆顶元素不在延迟删除字典中。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 `nums` 的长度。

相似题目：

-   [480. 滑动窗口中位数](https://github.com/doocs/leetcode/blob/main/solution/0400-0499/0480.Sliding%20Window%20Median/README.md)

<!-- tabs:start -->

#### Python3

```python
class MedianFinder:
    def __init__(self, x: int):
        self.x = x
        self.small = []
        self.large = []
        self.delayed = defaultdict(int)
        self.small_size = 0
        self.large_size = 0

    def add_num(self, num: int):
        if self.small_size < self.x or num <= -self.small[0]:
            heappush(self.small, -num)
            self.small_size += 1
        else:
            heappush(self.large, num)
            self.large_size += 1
        self.rebalance()

    def find(self) -> float:
        return -self.small[0] if self.small_size == self.x else 0

    def remove_num(self, num: int):
        self.delayed[num] += 1
        if num <= -self.small[0]:
            self.small_size -= 1
            if num == -self.small[0]:
                self.prune(self.small)
        else:
            self.large_size -= 1
            if num == self.large[0]:
                self.prune(self.large)
        self.rebalance()

    def prune(self, pq: List[int]):
        sign = -1 if pq is self.small else 1
        while pq and sign * pq[0] in self.delayed:
            self.delayed[sign * pq[0]] -= 1
            if self.delayed[sign * pq[0]] == 0:
                self.delayed.pop(sign * pq[0])
            heappop(pq)

    def rebalance(self):
        if self.small_size > self.x:
            heappush(self.large, -heappop(self.small))
            self.small_size -= 1
            self.large_size += 1
            self.prune(self.small)
        elif self.small_size < self.x and self.large_size > 0:
            heappush(self.small, -heappop(self.large))
            self.large_size -= 1
            self.small_size += 1
            self.prune(self.large)


class Solution:
    def getSubarrayBeauty(self, nums: List[int], k: int, x: int) -> List[int]:
        finder = MedianFinder(x)
        for i in range(k):
            if nums[i] < 0:
                finder.add_num(nums[i])
        ans = [finder.find()]
        for i in range(k, len(nums)):
            if nums[i] < 0:
                finder.add_num(nums[i])
            if nums[i - k] < 0:
                finder.remove_num(nums[i - k])
            ans.append(finder.find())
        return ans
```

#### Java

```java
class MedianFinder {
    private PriorityQueue<Integer> small = new PriorityQueue<>(Comparator.reverseOrder());
    private PriorityQueue<Integer> large = new PriorityQueue<>();
    private Map<Integer, Integer> delayed = new HashMap<>();
    private int smallSize;
    private int largeSize;
    private int x;

    public MedianFinder(int x) {
        this.x = x;
    }

    public void addNum(int num) {
        if (smallSize < x || num <= small.peek()) {
            small.offer(num);
            ++smallSize;
        } else {
            large.offer(num);
            ++largeSize;
        }
        rebalance();
    }

    public int find() {
        return smallSize == x ? small.peek() : 0;
    }

    public void removeNum(int num) {
        delayed.merge(num, 1, Integer::sum);
        if (num <= small.peek()) {
            --smallSize;
            if (num == small.peek()) {
                prune(small);
            }
        } else {
            --largeSize;
            if (num == large.peek()) {
                prune(large);
            }
        }
        rebalance();
    }

    private void prune(PriorityQueue<Integer> pq) {
        while (!pq.isEmpty() && delayed.containsKey(pq.peek())) {
            if (delayed.merge(pq.peek(), -1, Integer::sum) == 0) {
                delayed.remove(pq.peek());
            }
            pq.poll();
        }
    }

    private void rebalance() {
        if (smallSize > x) {
            large.offer(small.poll());
            --smallSize;
            ++largeSize;
            prune(small);
        } else if (smallSize < x && largeSize > 0) {
            small.offer(large.poll());
            --largeSize;
            ++smallSize;
            prune(large);
        }
    }
}

class Solution {
    public int[] getSubarrayBeauty(int[] nums, int k, int x) {
        MedianFinder finder = new MedianFinder(x);
        for (int i = 0; i < k; ++i) {
            if (nums[i] < 0) {
                finder.addNum(nums[i]);
            }
        }
        int n = nums.length;
        int[] ans = new int[n - k + 1];
        ans[0] = finder.find();
        for (int i = k; i < n; ++i) {
            if (nums[i] < 0) {
                finder.addNum(nums[i]);
            }
            if (nums[i - k] < 0) {
                finder.removeNum(nums[i - k]);
            }
            ans[i - k + 1] = finder.find();
        }
        return ans;
    }
}
```

#### C++

```cpp
class MedianFinder {
public:
    MedianFinder(int x) {
        this->x = x;
    }

    void addNum(int num) {
        if (smallSize < x || num <= small.top()) {
            small.push(num);
            ++smallSize;
        } else {
            large.push(num);
            ++largeSize;
        }
        reblance();
    }

    void removeNum(int num) {
        ++delayed[num];
        if (num <= small.top()) {
            --smallSize;
            if (num == small.top()) {
                prune(small);
            }
        } else {
            --largeSize;
            if (num == large.top()) {
                prune(large);
            }
        }
        reblance();
    }

    int find() {
        return smallSize == x ? small.top() : 0;
    }

private:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;
    unordered_map<int, int> delayed;
    int smallSize = 0;
    int largeSize = 0;
    int x;

    template <typename T>
    void prune(T& pq) {
        while (!pq.empty() && delayed[pq.top()]) {
            if (--delayed[pq.top()] == 0) {
                delayed.erase(pq.top());
            }
            pq.pop();
        }
    }

    void reblance() {
        if (smallSize > x) {
            large.push(small.top());
            small.pop();
            --smallSize;
            ++largeSize;
            prune(small);
        } else if (smallSize < x && largeSize > 0) {
            small.push(large.top());
            large.pop();
            ++smallSize;
            --largeSize;
            prune(large);
        }
    }
};

class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        MedianFinder finder(x);
        for (int i = 0; i < k; ++i) {
            if (nums[i] < 0) {
                finder.addNum(nums[i]);
            }
        }
        int n = nums.size();
        vector<int> ans;
        ans.push_back(finder.find());
        for (int i = k; i < n; ++i) {
            if (nums[i] < 0) {
                finder.addNum(nums[i]);
            }
            if (nums[i - k] < 0) {
                finder.removeNum(nums[i - k]);
            }
            ans.push_back(finder.find());
        }
        return ans;
    }
};
```

#### Go

```go
type MedianFinder struct {
	small                hp
	large                hp
	delayed              map[int]int
	smallSize, largeSize int
	x                    int
}

func Constructor(x int) MedianFinder {
	return MedianFinder{hp{}, hp{}, map[int]int{}, 0, 0, x}
}

func (this *MedianFinder) AddNum(num int) {
	if this.smallSize < this.x || num <= -this.small.IntSlice[0] {
		heap.Push(&this.small, -num)
		this.smallSize++
	} else {
		heap.Push(&this.large, num)
		this.largeSize++
	}
	this.rebalance()
}

func (this *MedianFinder) Find() int {
	if this.smallSize == this.x {
		return -this.small.IntSlice[0]
	}
	return 0
}

func (this *MedianFinder) RemoveNum(num int) {
	this.delayed[num]++
	if num <= -this.small.IntSlice[0] {
		this.smallSize--
		if num == -this.small.IntSlice[0] {
			this.prune(&this.small)
		}
	} else {
		this.largeSize--
		if num == this.large.IntSlice[0] {
			this.prune(&this.large)
		}
	}
	this.rebalance()
}

func (this *MedianFinder) prune(pq *hp) {
	sign := 1
	if pq == &this.small {
		sign = -1
	}
	for pq.Len() > 0 && this.delayed[sign*pq.IntSlice[0]] > 0 {
		this.delayed[sign*pq.IntSlice[0]]--
		if this.delayed[sign*pq.IntSlice[0]] == 0 {
			delete(this.delayed, sign*pq.IntSlice[0])
		}
		heap.Pop(pq)
	}
}

func (this *MedianFinder) rebalance() {
	if this.smallSize > this.x {
		heap.Push(&this.large, -heap.Pop(&this.small).(int))
		this.smallSize--
		this.largeSize++
		this.prune(&this.small)
	} else if this.smallSize < this.x && this.largeSize > 0 {
		heap.Push(&this.small, -heap.Pop(&this.large).(int))
		this.smallSize++
		this.largeSize--
		this.prune(&this.large)
	}
}

type hp struct{ sort.IntSlice }

func (h hp) Less(i, j int) bool { return h.IntSlice[i] < h.IntSlice[j] }
func (h *hp) Push(v any)        { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() any {
	a := h.IntSlice
	v := a[len(a)-1]
	h.IntSlice = a[:len(a)-1]
	return v
}

func getSubarrayBeauty(nums []int, k int, x int) []int {
	finder := Constructor(x)
	for _, num := range nums[:k] {
		if num < 0 {
			finder.AddNum(num)
		}
	}
	ans := []int{finder.Find()}
	for i := k; i < len(nums); i++ {
		if nums[i] < 0 {
			finder.AddNum(nums[i])
		}
		if nums[i-k] < 0 {
			finder.RemoveNum(nums[i-k])
		}
		ans = append(ans, finder.Find())
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2654. 使数组所有元素变成 1 的最少操作次数](https://leetcode.cn/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1){#2654}

{{< tabs "2654" >}}

{{% tab "python" %}}
```python
class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        cnt = nums.count(1)
        if cnt:
            return n - cnt
        mi = n + 1
        for i in range(n):
            g = 0
            for j in range(i, n):
                g = gcd(g, nums[j])
                if g == 1:
                    mi = min(mi, j - i + 1)
        return -1 if mi > n else n - 1 + mi - 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minOperations(int[] nums) {
        int n = nums.length;
        int cnt = 0;
        for (int x : nums) {
            if (x == 1) {
                ++cnt;
            }
        }
        if (cnt > 0) {
            return n - cnt;
        }
        int mi = n + 1;
        for (int i = 0; i < n; ++i) {
            int g = 0;
            for (int j = i; j < n; ++j) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    mi = Math.min(mi, j - i + 1);
                }
            }
        }
        return mi > n ? -1 : n - 1 + mi - 1;
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for (int x : nums) {
            if (x == 1) {
                ++cnt;
            }
        }
        if (cnt) {
            return n - cnt;
        }
        int mi = n + 1;
        for (int i = 0; i < n; ++i) {
            int g = 0;
            for (int j = i; j < n; ++j) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    mi = min(mi, j - i + 1);
                }
            }
        }
        return mi > n ? -1 : n - 1 + mi - 1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minOperations(nums []int) int {
	n := len(nums)
	cnt := 0
	for _, x := range nums {
		if x == 1 {
			cnt++
		}
	}
	if cnt > 0 {
		return n - cnt
	}
	mi := n + 1
	for i := 0; i < n; i++ {
		g := 0
		for j := i; j < n; j++ {
			g = gcd(g, nums[j])
			if g == 1 {
				mi = min(mi, j-i+1)
			}
		}
	}
	if mi > n {
		return -1
	}
	return n - 1 + mi - 1
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minOperations(nums: number[]): number {
    const n = nums.length;
    let cnt = 0;
    for (const x of nums) {
        if (x === 1) {
            ++cnt;
        }
    }
    if (cnt > 0) {
        return n - cnt;
    }
    let mi = n + 1;
    for (let i = 0; i < n; ++i) {
        let g = 0;
        for (let j = i; j < n; ++j) {
            g = gcd(g, nums[j]);
            if (g === 1) {
                mi = Math.min(mi, j - i + 1);
            }
        }
    }
    return mi > n ? -1 : n - 1 + mi - 1;
}

function gcd(a: number, b: number): number {
    return b === 0 ? a : gcd(b, a % b);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的 <strong>正</strong>&nbsp;整数数组&nbsp;<code>nums</code>&nbsp;。你可以对数组执行以下操作 <strong>任意</strong>&nbsp;次：</p>

<ul>
	<li>选择一个满足&nbsp;<code>0 &lt;= i &lt; n - 1</code>&nbsp;的下标 <code>i</code>&nbsp;，将&nbsp;<code>nums[i]</code> 或者&nbsp;<code>nums[i+1]</code>&nbsp;两者之一替换成它们的最大公约数。</li>
</ul>

<p>请你返回使数组 <code>nums</code>&nbsp;中所有元素都等于 <code>1</code>&nbsp;的 <strong>最少</strong>&nbsp;操作次数。如果无法让数组全部变成 <code>1</code>&nbsp;，请你返回 <code>-1</code>&nbsp;。</p>

<p>两个正整数的最大公约数指的是能整除这两个数的最大正整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [2,6,3,4]
<b>输出：</b>4
<b>解释：</b>我们可以执行以下操作：
- 选择下标 i = 2 ，将 nums[2] 替换为 gcd(3,4) = 1 ，得到 nums = [2,6,1,4] 。
- 选择下标 i = 1 ，将 nums[1] 替换为 gcd(6,1) = 1 ，得到 nums = [2,1,1,4] 。
- 选择下标 i = 0 ，将 nums[0] 替换为 gcd(2,1) = 1 ，得到 nums = [1,1,1,4] 。
- 选择下标 i = 2 ，将 nums[3] 替换为 gcd(1,4) = 1 ，得到 nums = [1,1,1,1] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [2,10,6,14]
<b>输出：</b>-1
<b>解释：</b>无法将所有元素都变成 1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 50</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学

我们先统计数组 $nums$ 中 $1$ 的个数 $cnt$，如果 $cnt \gt 0$，那么只需要 $n - cnt$ 次操作，就可以将整个数组变成 $1$。

否则，我们需要首先将数组中的一个元素变成 $1$，然后剩余的最小操作次数就是 $n - 1$。

考虑如何将数组中的一个元素变成 $1$，并且使得操作次数尽可能小。实际上，我们只需要找到一个最小的连续子数组区间 $nums[i,..j]$，使得子数组中所有元素的最大公约数为 $1$，子数组区间长度为 $mi = \min(mi, j - i + 1)$。最后我们总的操作次数就是 $n - 1 + mi - 1$。

时间复杂度 $O(n \times (n + \log M))$，空间复杂度 $(\log M)$。其中 $n$ 和 $M$ 分别是数组 $nums$ 的长度以及数组 $nums$ 中的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        cnt = nums.count(1)
        if cnt:
            return n - cnt
        mi = n + 1
        for i in range(n):
            g = 0
            for j in range(i, n):
                g = gcd(g, nums[j])
                if g == 1:
                    mi = min(mi, j - i + 1)
        return -1 if mi > n else n - 1 + mi - 1
```

#### Java

```java
class Solution {
    public int minOperations(int[] nums) {
        int n = nums.length;
        int cnt = 0;
        for (int x : nums) {
            if (x == 1) {
                ++cnt;
            }
        }
        if (cnt > 0) {
            return n - cnt;
        }
        int mi = n + 1;
        for (int i = 0; i < n; ++i) {
            int g = 0;
            for (int j = i; j < n; ++j) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    mi = Math.min(mi, j - i + 1);
                }
            }
        }
        return mi > n ? -1 : n - 1 + mi - 1;
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for (int x : nums) {
            if (x == 1) {
                ++cnt;
            }
        }
        if (cnt) {
            return n - cnt;
        }
        int mi = n + 1;
        for (int i = 0; i < n; ++i) {
            int g = 0;
            for (int j = i; j < n; ++j) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    mi = min(mi, j - i + 1);
                }
            }
        }
        return mi > n ? -1 : n - 1 + mi - 1;
    }
};
```

#### Go

```go
func minOperations(nums []int) int {
	n := len(nums)
	cnt := 0
	for _, x := range nums {
		if x == 1 {
			cnt++
		}
	}
	if cnt > 0 {
		return n - cnt
	}
	mi := n + 1
	for i := 0; i < n; i++ {
		g := 0
		for j := i; j < n; j++ {
			g = gcd(g, nums[j])
			if g == 1 {
				mi = min(mi, j-i+1)
			}
		}
	}
	if mi > n {
		return -1
	}
	return n - 1 + mi - 1
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
```

#### TypeScript

```ts
function minOperations(nums: number[]): number {
    const n = nums.length;
    let cnt = 0;
    for (const x of nums) {
        if (x === 1) {
            ++cnt;
        }
    }
    if (cnt > 0) {
        return n - cnt;
    }
    let mi = n + 1;
    for (let i = 0; i < n; ++i) {
        let g = 0;
        for (let j = i; j < n; ++j) {
            g = gcd(g, nums[j]);
            if (g === 1) {
                mi = Math.min(mi, j - i + 1);
            }
        }
    }
    return mi > n ? -1 : n - 1 + mi - 1;
}

function gcd(a: number, b: number): number {
    return b === 0 ? a : gcd(b, a % b);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2655. 寻找最大长度的未覆盖区间 🔒](https://leetcode.cn/problems/find-maximal-uncovered-ranges){#2655}

{{< tabs "2655" >}}

{{% tab "python" %}}
```python
class Solution:
    def findMaximalUncoveredRanges(
        self, n: int, ranges: List[List[int]]
    ) -> List[List[int]]:
        ranges.sort()
        last = -1
        ans = []
        for l, r in ranges:
            if last + 1 < l:
                ans.append([last + 1, l - 1])
            last = max(last, r)
        if last + 1 < n:
            ans.append([last + 1, n - 1])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[][] findMaximalUncoveredRanges(int n, int[][] ranges) {
        Arrays.sort(ranges, (a, b) -> a[0] - b[0]);
        int last = -1;
        List<int[]> ans = new ArrayList<>();
        for (int[] range : ranges) {
            int l = range[0], r = range[1];
            if (last + 1 < l) {
                ans.add(new int[] {last + 1, l - 1});
            }
            last = Math.max(last, r);
        }
        if (last + 1 < n) {
            ans.add(new int[] {last + 1, n - 1});
        }
        return ans.toArray(new int[0][]);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<vector<int>> findMaximalUncoveredRanges(int n, vector<vector<int>>& ranges) {
        sort(ranges.begin(), ranges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        int last = -1;
        vector<vector<int>> ans;
        for (auto& range : ranges) {
            int l = range[0], r = range[1];
            if (last + 1 < l) {
                ans.push_back({last + 1, l - 1});
            }
            last = max(last, r);
        }
        if (last + 1 < n) {
            ans.push_back({last + 1, n - 1});
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findMaximalUncoveredRanges(n int, ranges [][]int) (ans [][]int) {
	sort.Slice(ranges, func(i, j int) bool { return ranges[i][0] < ranges[j][0] })
	last := -1
	for _, r := range ranges {
		if last+1 < r[0] {
			ans = append(ans, []int{last + 1, r[0] - 1})
		}
		last = max(last, r[1])
	}
	if last+1 < n {
		ans = append(ans, []int{last + 1, n - 1})
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

<p>现给你一个长度为 n 的 <strong>索引从 0 开始的</strong>&nbsp;数组 <code>nums</code> 和一个 <strong>索引从 0 开始的</strong> 2 维数组 <code>ranges</code> ，<strong>ranges</strong> 是 <strong>nums</strong> 的子区间列表（子区间可能 <strong>重叠</strong> ）。</p>

<p>每行 <code>ranges[i]</code> 恰好有两个元素：</p>

<ul>
	<li><code>ranges[i][0]</code> 表示第i个区间的起始位置（包含）</li>
	<li><code>ranges[i][1]</code> 表示第i个区间的结束位置（包含）</li>
</ul>

<p>这些区间覆盖了 <code>nums</code> 的一些元素，并留下了一些 <strong>未覆盖</strong> 的元素。你的任务是找到所有 <strong>最大长度</strong> 的未覆盖区间。</p>

<p>返回按起始点 <strong>升序排序</strong> 的未覆盖区间的二维数组 <code>answer</code> 。</p>

<p>所有 <strong>最大长度</strong> 的 <strong>未覆盖</strong> 区间指满足两个条件：</p>

<ul>
	<li>每个未覆盖的元素应该属于 <strong>恰好</strong> 一个子区间。</li>
	<li><strong>不存在</strong>两个区间 (l1,r1) 和 (l2,r2) 使得 r1+1=l2 。</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例 1 ：</strong></p>

<pre>
<b>输入：</b>n = 10, ranges = [[3,5],[7,8]]
<b>输出：</b>[[0,2],[6,6],[9,9]]
<b>解释：</b>区间 (3,5) 和 (7,8) 都被覆盖，因此如果我们将 nums 简化为一个二进制数组，其中 0 表示未覆盖的元素，1 表示覆盖的元素，则数组变为[0,0,0,1,1,1,0,1,1,0]，在其中我们可以观察到区间 (0,2)，(6,6)和(9,9)未被覆盖。
</pre>

<p><strong class="example">示例 2&nbsp;：</strong></p>

<pre>
<b>输入：</b>n = 3, ranges = [[0,2]]
<b>输出：</b>[]
<strong>解释：</strong>在这个例子中，整个 nums 数组都被覆盖，没有未覆盖的元素，所以输出是一个空数组。
</pre>

<p><strong class="example">示例 3 ：</strong></p>

<pre>
<b>输入：</b>n = 7, ranges = [[2,4],[0,3]]
<b>输出：</b>[[5,6]]
<b>解释：</b>区间 (0,3) 和 (2,4) 都被覆盖，因此如果我们将 nums 简化为一个二进制数组，其中 0 表示未覆盖的元素，1 表示覆盖的元素，则数组变为[1,1,1,1,1,0,0]，在其中我们可以观察到区间 (5,6) 未被覆盖。</pre>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<ul>
	<li><code>1 &lt;= n &lt;=&nbsp;10<sup>9</sup></code></li>
	<li><code>0 &lt;= ranges.length &lt;= 10<sup>6</sup></code></li>
	<li><code>ranges[i].length = 2</code></li>
	<li><code>0 &lt;= ranges[i][j] &lt;= n - 1</code></li>
	<li><code>ranges[i][0] &lt;=&nbsp;ranges[i][1]</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序

我们将所有的区间按照左端点从小到大排序，然后从左到右遍历所有的区间，维护一个变量 $last$ 表示当前已经被覆盖的最右端点，初始时 $last=-1$。如果当前区间的左端点大于 $last+1$，那么说明 $[last+1, l-1]$ 是一个未被覆盖的区间，我们将其加入答案数组中。然后我们更新 $last$ 为当前区间的右端点，继续遍历下一个区间。当遍历完所有的区间后，如果 $last+1 \lt n$，那么说明 $[last+1, n-1]$ 是一个未被覆盖的区间，我们将其加入答案数组中。

最后我们将答案数组返回即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 是数组 $ranges$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findMaximalUncoveredRanges(
        self, n: int, ranges: List[List[int]]
    ) -> List[List[int]]:
        ranges.sort()
        last = -1
        ans = []
        for l, r in ranges:
            if last + 1 < l:
                ans.append([last + 1, l - 1])
            last = max(last, r)
        if last + 1 < n:
            ans.append([last + 1, n - 1])
        return ans
```

#### Java

```java
class Solution {
    public int[][] findMaximalUncoveredRanges(int n, int[][] ranges) {
        Arrays.sort(ranges, (a, b) -> a[0] - b[0]);
        int last = -1;
        List<int[]> ans = new ArrayList<>();
        for (int[] range : ranges) {
            int l = range[0], r = range[1];
            if (last + 1 < l) {
                ans.add(new int[] {last + 1, l - 1});
            }
            last = Math.max(last, r);
        }
        if (last + 1 < n) {
            ans.add(new int[] {last + 1, n - 1});
        }
        return ans.toArray(new int[0][]);
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> findMaximalUncoveredRanges(int n, vector<vector<int>>& ranges) {
        sort(ranges.begin(), ranges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        int last = -1;
        vector<vector<int>> ans;
        for (auto& range : ranges) {
            int l = range[0], r = range[1];
            if (last + 1 < l) {
                ans.push_back({last + 1, l - 1});
            }
            last = max(last, r);
        }
        if (last + 1 < n) {
            ans.push_back({last + 1, n - 1});
        }
        return ans;
    }
};
```

#### Go

```go
func findMaximalUncoveredRanges(n int, ranges [][]int) (ans [][]int) {
	sort.Slice(ranges, func(i, j int) bool { return ranges[i][0] < ranges[j][0] })
	last := -1
	for _, r := range ranges {
		if last+1 < r[0] {
			ans = append(ans, []int{last + 1, r[0] - 1})
		}
		last = max(last, r[1])
	}
	if last+1 < n {
		ans = append(ans, []int{last + 1, n - 1})
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2656. K 个元素的最大和](https://leetcode.cn/problems/maximum-sum-with-exactly-k-elements){#2656}

{{< tabs "2656" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximizeSum(self, nums: List[int], k: int) -> int:
        x = max(nums)
        return k * x + k * (k - 1) // 2
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximizeSum(int[] nums, int k) {
        int x = 0;
        for (int v : nums) {
            x = Math.max(x, v);
        }
        return k * x + k * (k - 1) / 2;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int x = *max_element(nums.begin(), nums.end());
        return k * x + k * (k - 1) / 2;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximizeSum(nums []int, k int) int {
	x := slices.Max(nums)
	return k*x + k*(k-1)/2
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximizeSum(nums: number[], k: number): number {
    const x = Math.max(...nums);
    return k * x + (k * (k - 1)) / 2;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn maximize_sum(nums: Vec<i32>, k: i32) -> i32 {
        let mx = *nums.iter().max().unwrap_or(&0);

        ((0 + k - 1) * k) / 2 + k * mx
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code> 和一个整数&nbsp;<code>k</code>&nbsp;。你需要执行以下操作<strong>&nbsp;恰好</strong> <code>k</code>&nbsp;次，最大化你的得分：</p>

<ol>
	<li>从 <code>nums</code>&nbsp;中选择一个元素&nbsp;<code>m</code>&nbsp;。</li>
	<li>将选中的元素&nbsp;<code>m</code>&nbsp;从数组中删除。</li>
	<li>将新元素&nbsp;<code>m + 1</code>&nbsp;添加到数组中。</li>
	<li>你的得分增加&nbsp;<code>m</code>&nbsp;。</li>
</ol>

<p>请你返回执行以上操作恰好 <code>k</code>&nbsp;次后的最大得分。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,2,3,4,5], k = 3
<b>输出：</b>18
<b>解释：</b>我们需要从 nums 中恰好选择 3 个元素并最大化得分。
第一次选择 5 。和为 5 ，nums = [1,2,3,4,6] 。
第二次选择 6 。和为 6 ，nums = [1,2,3,4,7] 。
第三次选择 7 。和为 5 + 6 + 7 = 18 ，nums = [1,2,3,4,8] 。
所以我们返回 18 。
18 是可以得到的最大答案。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [5,5,5], k = 2
<b>输出：</b>11
<b>解释：</b>我们需要从 nums 中恰好选择 2 个元素并最大化得分。
第一次选择 5 。和为 5 ，nums = [5,5,6] 。
第二次选择 6 。和为 6 ，nums = [5,5,7] 。
所以我们返回 11 。
11 是可以得到的最大答案。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
	<li><code>1 &lt;= k &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 数学

我们注意到，要使得最终的得分最大，我们应该尽可能地使得每次选择的元素最大。因此，我们第一次选择数组中的最大元素 $x$，第二次选择 $x+1$，第三次选择 $x+2$，以此类推，直到第 $k$ 次选择 $x+k-1$。这样的选择方式可以保证每次选择的元素都是当前数组中的最大值，因此最终的得分也是最大的。答案即为 $k$ 个 $x$ 的和加上 $0+1+2+\cdots+(k-1)$，即 $k \times x + (k - 1) \times k / 2$。

时间复杂度 $O(n)$，其中 $n$ 是数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximizeSum(self, nums: List[int], k: int) -> int:
        x = max(nums)
        return k * x + k * (k - 1) // 2
```

#### Java

```java
class Solution {
    public int maximizeSum(int[] nums, int k) {
        int x = 0;
        for (int v : nums) {
            x = Math.max(x, v);
        }
        return k * x + k * (k - 1) / 2;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int x = *max_element(nums.begin(), nums.end());
        return k * x + k * (k - 1) / 2;
    }
};
```

#### Go

```go
func maximizeSum(nums []int, k int) int {
	x := slices.Max(nums)
	return k*x + k*(k-1)/2
}
```

#### TypeScript

```ts
function maximizeSum(nums: number[], k: number): number {
    const x = Math.max(...nums);
    return k * x + (k * (k - 1)) / 2;
}
```

#### Rust

```rust
impl Solution {
    pub fn maximize_sum(nums: Vec<i32>, k: i32) -> i32 {
        let mut mx = 0;

        for &n in &nums {
            if n > mx {
                mx = n;
            }
        }

        ((0 + k - 1) * k) / 2 + k * mx
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Rust

```rust
impl Solution {
    pub fn maximize_sum(nums: Vec<i32>, k: i32) -> i32 {
        let mx = *nums.iter().max().unwrap_or(&0);

        ((0 + k - 1) * k) / 2 + k * mx
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2657. 找到两个数组的前缀公共数组](https://leetcode.cn/problems/find-the-prefix-common-array-of-two-arrays){#2657}

{{< tabs "2657" >}}

{{% tab "python" %}}
```python
class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        ans = []
        x = y = 0
        for a, b in zip(A, B):
            x |= 1 << a
            y |= 1 << b
            ans.append((x & y).bit_count())
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        int n = A.length;
        int[] ans = new int[n];
        long x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            x |= 1L << A[i];
            y |= 1L << B[i];
            ans[i] = Long.bitCount(x & y);
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
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n);
        long long x = 0, y = 0;
        for (int i = 0; i < n; ++i) {
            x |= (1LL << A[i]);
            y |= (1LL << B[i]);
            ans[i] = __builtin_popcountll(x & y);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findThePrefixCommonArray(A []int, B []int) []int {
	n := len(A)
	ans := make([]int, n)
	var x, y int
	for i := 0; i < n; i++ {
		x |= 1 << A[i]
		y |= 1 << B[i]
		ans[i] = bits.OnesCount(uint(x & y))
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findThePrefixCommonArray(A: number[], B: number[]): number[] {
    const n = A.length;
    const ans: number[] = [];
    let [x, y] = [0n, 0n];
    for (let i = 0; i < n; i++) {
        x |= 1n << BigInt(A[i]);
        y |= 1n << BigInt(B[i]);
        ans.push(bitCount64(x & y));
    }
    return ans;
}

function bitCount64(i: bigint): number {
    i = i - ((i >> 1n) & 0x5555555555555555n);
    i = (i & 0x3333333333333333n) + ((i >> 2n) & 0x3333333333333333n);
    i = (i + (i >> 4n)) & 0x0f0f0f0f0f0f0f0fn;
    i = i + (i >> 8n);
    i = i + (i >> 16n);
    i = i + (i >> 32n);
    return Number(i & 0x7fn);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个下标从 <strong>0</strong>&nbsp;开始长度为 <code>n</code>&nbsp;的整数排列&nbsp;<code>A</code> 和&nbsp;<code>B</code>&nbsp;。</p>

<p><code>A</code>&nbsp;和&nbsp;<code>B</code>&nbsp;的 <strong>前缀公共数组</strong>&nbsp;定义为数组&nbsp;<code>C</code>&nbsp;，其中&nbsp;<code>C[i]</code>&nbsp;是数组&nbsp;<code>A</code> 和&nbsp;<code>B</code>&nbsp;到下标为&nbsp;<code>i</code>&nbsp;之前公共元素的数目。</p>

<p>请你返回 <code>A</code>&nbsp;和 <code>B</code>&nbsp;的 <strong>前缀公共数组</strong>&nbsp;。</p>

<p>如果一个长度为 <code>n</code>&nbsp;的数组包含 <code>1</code>&nbsp;到 <code>n</code>&nbsp;的元素恰好一次，我们称这个数组是一个长度为 <code>n</code>&nbsp;的 <strong>排列</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>A = [1,3,2,4], B = [3,1,2,4]
<b>输出：</b>[0,2,3,4]
<b>解释：</b>i = 0：没有公共元素，所以 C[0] = 0 。
i = 1：1 和 3 是两个数组的前缀公共元素，所以 C[1] = 2 。
i = 2：1，2 和 3 是两个数组的前缀公共元素，所以 C[2] = 3 。
i = 3：1，2，3 和 4 是两个数组的前缀公共元素，所以 C[3] = 4 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>A = [2,3,1], B = [3,1,2]
<b>输出：</b>[0,1,3]
<b>解释：</b>i = 0：没有公共元素，所以 C[0] = 0 。
i = 1：只有 3 是公共元素，所以 C[1] = 1 。
i = 2：1，2 和 3 是两个数组的前缀公共元素，所以 C[2] = 3 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= A.length == B.length == n &lt;= 50</code></li>
	<li><code>1 &lt;= A[i], B[i] &lt;= n</code></li>
	<li>题目保证&nbsp;<code>A</code>&nbsp;和&nbsp;<code>B</code>&nbsp;两个数组都是&nbsp;<code>n</code>&nbsp;个元素的排列。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们可以使用两个数组 $cnt1$ 和 $cnt2$ 分别记录数组 $A$ 和 $B$ 中每个元素出现的次数，用数组 $ans$ 记录答案。

遍历数组 $A$ 和 $B$，将 $A[i]$ 在 $cnt1$ 中出现次数加一，将 $B[i]$ 在 $cnt2$ 中出现次数加一。然后枚举 $j \in [1,n]$，计算 $cnt1$ 和 $cnt2$ 中每个元素 $j$ 出现次数的最小值，累加到 $ans[i]$ 中。

遍历结束后，返回答案数组 $ans$ 即可。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $A$ 和 $B$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        ans = []
        cnt1 = Counter()
        cnt2 = Counter()
        for a, b in zip(A, B):
            cnt1[a] += 1
            cnt2[b] += 1
            t = sum(min(v, cnt2[x]) for x, v in cnt1.items())
            ans.append(t)
        return ans
```

#### Java

```java
class Solution {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        int n = A.length;
        int[] ans = new int[n];
        int[] cnt1 = new int[n + 1];
        int[] cnt2 = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            ++cnt1[A[i]];
            ++cnt2[B[i]];
            for (int j = 1; j <= n; ++j) {
                ans[i] += Math.min(cnt1[j], cnt2[j]);
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
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n);
        vector<int> cnt1(n + 1), cnt2(n + 1);
        for (int i = 0; i < n; ++i) {
            ++cnt1[A[i]];
            ++cnt2[B[i]];
            for (int j = 1; j <= n; ++j) {
                ans[i] += min(cnt1[j], cnt2[j]);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findThePrefixCommonArray(A []int, B []int) []int {
	n := len(A)
	cnt1 := make([]int, n+1)
	cnt2 := make([]int, n+1)
	ans := make([]int, n)
	for i, a := range A {
		b := B[i]
		cnt1[a]++
		cnt2[b]++
		for j := 1; j <= n; j++ {
			ans[i] += min(cnt1[j], cnt2[j])
		}
	}
	return ans
}
```

#### TypeScript

```ts
function findThePrefixCommonArray(A: number[], B: number[]): number[] {
    const n = A.length;
    const cnt1: number[] = Array(n + 1).fill(0);
    const cnt2: number[] = Array(n + 1).fill(0);
    const ans: number[] = Array(n).fill(0);
    for (let i = 0; i < n; ++i) {
        ++cnt1[A[i]];
        ++cnt2[B[i]];
        for (let j = 1; j <= n; ++j) {
            ans[i] += Math.min(cnt1[j], cnt2[j]);
        }
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：位运算（异或运算）

我们可以使用一个长度为 $n+1$ 的数组 $vis$ 记录数组 $A$ 和 $B$ 中每个元素的出现情况，数组 $vis$ 的初始值为 $1$。另外，我们用一个变量 $s$ 记录当前公共元素的个数。

接下来，我们遍历数组 $A$ 和 $B$，更新 $vis[A[i]] = vis[A[i]] \oplus 1$，并且更新 $vis[B[i]] = vis[B[i]] \oplus 1$，其中 $\oplus$ 表示异或运算。

如果遍历到当前位置，元素 $A[i]$ 出现过两次（即在数组 $A$ 和 $B$ 中都出现过），那么 $vis[A[i]]$ 的值将为会 $1$，我们将 $s$ 加一。同理，如果元素 $B[i]$ 出现过两次，那么 $vis[B[i]]$ 的值将为会 $1$，我们将 $s$ 加一。然后将 $s$ 的值加入到答案数组 $ans$ 中。

遍历结束后，返回答案数组 $ans$ 即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $A$ 和 $B$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        ans = []
        vis = [1] * (len(A) + 1)
        s = 0
        for a, b in zip(A, B):
            vis[a] ^= 1
            s += vis[a]
            vis[b] ^= 1
            s += vis[b]
            ans.append(s)
        return ans
```

#### Java

```java
class Solution {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        int n = A.length;
        int[] ans = new int[n];
        int[] vis = new int[n + 1];
        Arrays.fill(vis, 1);
        int s = 0;
        for (int i = 0; i < n; ++i) {
            vis[A[i]] ^= 1;
            s += vis[A[i]];
            vis[B[i]] ^= 1;
            s += vis[B[i]];
            ans[i] = s;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans;
        vector<int> vis(n + 1, 1);
        int s = 0;
        for (int i = 0; i < n; ++i) {
            vis[A[i]] ^= 1;
            s += vis[A[i]];
            vis[B[i]] ^= 1;
            s += vis[B[i]];
            ans.push_back(s);
        }
        return ans;
    }
};
```

#### Go

```go
func findThePrefixCommonArray(A []int, B []int) (ans []int) {
	vis := make([]int, len(A)+1)
	for i := range vis {
		vis[i] = 1
	}
	s := 0
	for i, a := range A {
		b := B[i]
		vis[a] ^= 1
		s += vis[a]
		vis[b] ^= 1
		s += vis[b]
		ans = append(ans, s)
	}
	return
}
```

#### TypeScript

```ts
function findThePrefixCommonArray(A: number[], B: number[]): number[] {
    const n = A.length;
    const vis: number[] = Array(n + 1).fill(1);
    const ans: number[] = [];
    let s = 0;
    for (let i = 0; i < n; ++i) {
        const [a, b] = [A[i], B[i]];
        vis[a] ^= 1;
        s += vis[a];
        vis[b] ^= 1;
        s += vis[b];
        ans.push(s);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三：位运算（空间优化）

由于题目中给定的数组 $A$ 和 $B$ 的元素范围是 $[1,n]$，且不超过 $50$，我们可以使用一个整数 $x$ 和一个整数 $y$ 来分别表示数组 $A$ 和 $B$ 中每个元素的出现情况。具体地，我们用整数 $x$ 的第 $i$ 位表示元素 $i$ 是否在数组 $A$ 中出现过，用整数 $y$ 的第 $i$ 位表示元素 $i$ 是否在数组 $B$ 中出现过。

时间复杂度 $O(n)$，其中 $n$ 是数组 $A$ 和 $B$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        ans = []
        x = y = 0
        for a, b in zip(A, B):
            x |= 1 << a
            y |= 1 << b
            ans.append((x & y).bit_count())
        return ans
```

#### Java

```java
class Solution {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        int n = A.length;
        int[] ans = new int[n];
        long x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            x |= 1L << A[i];
            y |= 1L << B[i];
            ans[i] = Long.bitCount(x & y);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n);
        long long x = 0, y = 0;
        for (int i = 0; i < n; ++i) {
            x |= (1LL << A[i]);
            y |= (1LL << B[i]);
            ans[i] = __builtin_popcountll(x & y);
        }
        return ans;
    }
};
```

#### Go

```go
func findThePrefixCommonArray(A []int, B []int) []int {
	n := len(A)
	ans := make([]int, n)
	var x, y int
	for i := 0; i < n; i++ {
		x |= 1 << A[i]
		y |= 1 << B[i]
		ans[i] = bits.OnesCount(uint(x & y))
	}
	return ans
}
```

#### TypeScript

```ts
function findThePrefixCommonArray(A: number[], B: number[]): number[] {
    const n = A.length;
    const ans: number[] = [];
    let [x, y] = [0n, 0n];
    for (let i = 0; i < n; i++) {
        x |= 1n << BigInt(A[i]);
        y |= 1n << BigInt(B[i]);
        ans.push(bitCount64(x & y));
    }
    return ans;
}

function bitCount64(i: bigint): number {
    i = i - ((i >> 1n) & 0x5555555555555555n);
    i = (i & 0x3333333333333333n) + ((i >> 2n) & 0x3333333333333333n);
    i = (i + (i >> 4n)) & 0x0f0f0f0f0f0f0f0fn;
    i = i + (i >> 8n);
    i = i + (i >> 16n);
    i = i + (i >> 32n);
    return Number(i & 0x7fn);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2658. 网格图中鱼的最大数目](https://leetcode.cn/problems/maximum-number-of-fish-in-a-grid){#2658}

{{< tabs "2658" >}}

{{% tab "python" %}}
```python
class Solution:
    def findMaxFish(self, grid: List[List[int]]) -> int:
        def dfs(i: int, j: int) -> int:
            cnt = grid[i][j]
            grid[i][j] = 0
            for a, b in pairwise((-1, 0, 1, 0, -1)):
                x, y = i + a, j + b
                if 0 <= x < m and 0 <= y < n and grid[x][y]:
                    cnt += dfs(x, y)
            return cnt

        m, n = len(grid), len(grid[0])
        ans = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j]:
                    ans = max(ans, dfs(i, j))
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[][] grid;
    private int m;
    private int n;

    public int findMaxFish(int[][] grid) {
        m = grid.length;
        n = grid[0].length;
        this.grid = grid;
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    ans = Math.max(ans, dfs(i, j));
                }
            }
        }
        return ans;
    }

    private int dfs(int i, int j) {
        int cnt = grid[i][j];
        grid[i][j] = 0;
        int[] dirs = {-1, 0, 1, 0, -1};
        for (int k = 0; k < 4; ++k) {
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] > 0) {
                cnt += dfs(x, y);
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
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            int cnt = grid[i][j];
            grid[i][j] = 0;
            int dirs[5] = {-1, 0, 1, 0, -1};
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y]) {
                    cnt += dfs(x, y);
                }
            }
            return cnt;
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    ans = max(ans, dfs(i, j));
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
func findMaxFish(grid [][]int) (ans int) {
	m, n := len(grid), len(grid[0])
	dirs := [5]int{-1, 0, 1, 0, -1}
	var dfs func(i, j int) int
	dfs = func(i, j int) int {
		cnt := grid[i][j]
		grid[i][j] = 0
		for k := 0; k < 4; k++ {
			x, y := i+dirs[k], j+dirs[k+1]
			if x >= 0 && x < m && y >= 0 && y < n && grid[x][y] > 0 {
				cnt += dfs(x, y)
			}
		}
		return cnt
	}
	for i := range grid {
		for j := range grid[i] {
			if grid[i][j] > 0 {
				ans = max(ans, dfs(i, j))
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findMaxFish(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;

    const dirs = [-1, 0, 1, 0, -1];
    const dfs = (i: number, j: number): number => {
        let cnt = grid[i][j];
        grid[i][j] = 0;
        for (let k = 0; k < 4; ++k) {
            const x = i + dirs[k];
            const y = j + dirs[k + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] > 0) {
                cnt += dfs(x, y);
            }
        }
        return cnt;
    };

    let ans = 0;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (grid[i][j] > 0) {
                ans = Math.max(ans, dfs(i, j));
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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始大小为 <code>m x n</code>&nbsp;的二维整数数组&nbsp;<code>grid</code>&nbsp;，其中下标在&nbsp;<code>(r, c)</code>&nbsp;处的整数表示：</p>

<ul>
	<li>如果&nbsp;<code>grid[r][c] = 0</code>&nbsp;，那么它是一块 <strong>陆地</strong>&nbsp;。</li>
	<li>如果&nbsp;<code>grid[r][c] &gt; 0</code>&nbsp;，那么它是一块&nbsp;<strong>水域</strong>&nbsp;，且包含&nbsp;<code>grid[r][c]</code>&nbsp;条鱼。</li>
</ul>

<p>一位渔夫可以从任意 <strong>水域</strong>&nbsp;格子&nbsp;<code>(r, c)</code>&nbsp;出发，然后执行以下操作任意次：</p>

<ul>
	<li>捕捞格子&nbsp;<code>(r, c)</code>&nbsp;处所有的鱼，或者</li>
	<li>移动到相邻的 <strong>水域</strong>&nbsp;格子。</li>
</ul>

<p>请你返回渔夫最优策略下，&nbsp;<strong>最多</strong>&nbsp;可以捕捞多少条鱼。如果没有水域格子，请你返回 <code>0</code>&nbsp;。</p>

<p>格子&nbsp;<code>(r, c)</code>&nbsp;<strong>相邻</strong>&nbsp;的格子为&nbsp;<code>(r, c + 1)</code>&nbsp;，<code>(r, c - 1)</code>&nbsp;，<code>(r + 1, c)</code> 和&nbsp;<code>(r - 1, c)</code>&nbsp;，前提是相邻格子在网格图内。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2600-2699/2658.Maximum%20Number%20of%20Fish%20in%20a%20Grid/images/example.png" style="width: 241px; height: 161px;"></p>

<pre><b>输入：</b>grid = [[0,2,1,0],[4,0,0,3],[1,0,0,4],[0,3,2,0]]
<b>输出：</b>7
<b>解释：</b>渔夫可以从格子 <code>(1,3)</code> 出发，捕捞 3 条鱼，然后移动到格子 <code>(2,3)</code>&nbsp;，捕捞 4 条鱼。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2600-2699/2658.Maximum%20Number%20of%20Fish%20in%20a%20Grid/images/example2.png"></p>

<pre><b>输入：</b>grid = [[1,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,1]]
<b>输出：</b>1
<b>解释：</b>渔夫可以从格子 (0,0) 或者 (3,3) ，捕捞 1 条鱼。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 10</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 10</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

根据题目描述，我们只需要找出每块连通的水域中鱼的数目，然后取最大值即可。因此，我们可以使用深度优先搜索的方法来解决本题。

我们定义一个函数 $dfs(i, j)$，表示从网格图中的第 $i$ 行第 $j$ 列的格子出发，可以捕捞到的最大鱼数。函数 $dfs(i, j)$ 的执行逻辑如下：

我们用一个变量 $cnt$ 来记录当前格子中的鱼的数目，然后将当前格子中的鱼的数目置为 $0$，表示已经捕捞过了。然后我们遍历当前格子的上下左右四个方向，如果某个方向的格子 $(x, y)$ 在网格图内且是水域格子，那么我们就递归调用 $dfs(x, y)$ 函数，将返回值加到 $cnt$ 中。最后返回 $cnt$ 即可。

在主函数中，我们遍历所有的格子 $(i, j)$，如果当前格子是水域格子，那么我们就调用 $dfs(i, j)$ 函数，取返回值的最大值作为答案返回即可。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是网格图的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findMaxFish(self, grid: List[List[int]]) -> int:
        def dfs(i: int, j: int) -> int:
            cnt = grid[i][j]
            grid[i][j] = 0
            for a, b in pairwise((-1, 0, 1, 0, -1)):
                x, y = i + a, j + b
                if 0 <= x < m and 0 <= y < n and grid[x][y]:
                    cnt += dfs(x, y)
            return cnt

        m, n = len(grid), len(grid[0])
        ans = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j]:
                    ans = max(ans, dfs(i, j))
        return ans
```

#### Java

```java
class Solution {
    private int[][] grid;
    private int m;
    private int n;

    public int findMaxFish(int[][] grid) {
        m = grid.length;
        n = grid[0].length;
        this.grid = grid;
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    ans = Math.max(ans, dfs(i, j));
                }
            }
        }
        return ans;
    }

    private int dfs(int i, int j) {
        int cnt = grid[i][j];
        grid[i][j] = 0;
        int[] dirs = {-1, 0, 1, 0, -1};
        for (int k = 0; k < 4; ++k) {
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] > 0) {
                cnt += dfs(x, y);
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
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            int cnt = grid[i][j];
            grid[i][j] = 0;
            int dirs[5] = {-1, 0, 1, 0, -1};
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y]) {
                    cnt += dfs(x, y);
                }
            }
            return cnt;
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    ans = max(ans, dfs(i, j));
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findMaxFish(grid [][]int) (ans int) {
	m, n := len(grid), len(grid[0])
	dirs := [5]int{-1, 0, 1, 0, -1}
	var dfs func(i, j int) int
	dfs = func(i, j int) int {
		cnt := grid[i][j]
		grid[i][j] = 0
		for k := 0; k < 4; k++ {
			x, y := i+dirs[k], j+dirs[k+1]
			if x >= 0 && x < m && y >= 0 && y < n && grid[x][y] > 0 {
				cnt += dfs(x, y)
			}
		}
		return cnt
	}
	for i := range grid {
		for j := range grid[i] {
			if grid[i][j] > 0 {
				ans = max(ans, dfs(i, j))
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function findMaxFish(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;

    const dirs = [-1, 0, 1, 0, -1];
    const dfs = (i: number, j: number): number => {
        let cnt = grid[i][j];
        grid[i][j] = 0;
        for (let k = 0; k < 4; ++k) {
            const x = i + dirs[k];
            const y = j + dirs[k + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] > 0) {
                cnt += dfs(x, y);
            }
        }
        return cnt;
    };

    let ans = 0;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (grid[i][j] > 0) {
                ans = Math.max(ans, dfs(i, j));
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

# [2659. 将数组清空](https://leetcode.cn/problems/make-array-empty){#2659}

{{< tabs "2659" >}}

{{% tab "python" %}}
```python
class BinaryIndexedTree:
    def __init__(self, n):
        self.n = n
        self.c = [0] * (n + 1)

    def update(self, x, delta):
        while x <= self.n:
            self.c[x] += delta
            x += x & -x

    def query(self, x):
        s = 0
        while x:
            s += self.c[x]
            x -= x & -x
        return s


class Solution:
    def countOperationsToEmptyArray(self, nums: List[int]) -> int:
        pos = {x: i for i, x in enumerate(nums)}
        nums.sort()
        ans = pos[nums[0]] + 1
        n = len(nums)
        tree = BinaryIndexedTree(n)
        for k, (a, b) in enumerate(pairwise(nums)):
            i, j = pos[a], pos[b]
            d = j - i - tree.query(j + 1) + tree.query(i + 1)
            ans += d + (n - k) * int(i > j)
            tree.update(i + 1, 1)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        c = new int[n + 1];
    }

    public void update(int x, int delta) {
        while (x <= n) {
            c[x] += delta;
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
    public long countOperationsToEmptyArray(int[] nums) {
        int n = nums.length;
        Map<Integer, Integer> pos = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            pos.put(nums[i], i);
        }
        Arrays.sort(nums);
        long ans = pos.get(nums[0]) + 1;
        BinaryIndexedTree tree = new BinaryIndexedTree(n);
        for (int k = 0; k < n - 1; ++k) {
            int i = pos.get(nums[k]), j = pos.get(nums[k + 1]);
            long d = j - i - (tree.query(j + 1) - tree.query(i + 1));
            ans += d + (n - k) * (i > j ? 1 : 0);
            tree.update(i + 1, 1);
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
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
    long long countOperationsToEmptyArray(vector<int>& nums) {
        unordered_map<int, int> pos;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            pos[nums[i]] = i;
        }
        sort(nums.begin(), nums.end());
        BinaryIndexedTree tree(n);
        long long ans = pos[nums[0]] + 1;
        for (int k = 0; k < n - 1; ++k) {
            int i = pos[nums[k]], j = pos[nums[k + 1]];
            long long d = j - i - (tree.query(j + 1) - tree.query(i + 1));
            ans += d + (n - k) * int(i > j);
            tree.update(i + 1, 1);
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

func countOperationsToEmptyArray(nums []int) int64 {
	n := len(nums)
	pos := map[int]int{}
	for i, x := range nums {
		pos[x] = i
	}
	sort.Ints(nums)
	tree := newBinaryIndexedTree(n)
	ans := pos[nums[0]] + 1
	for k := 0; k < n-1; k++ {
		i, j := pos[nums[k]], pos[nums[k+1]]
		d := j - i - (tree.query(j+1) - tree.query(i+1))
		if i > j {
			d += n - k
		}
		ans += d
		tree.update(i+1, 1)
	}
	return int64(ans)
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
        this.c = Array(n + 1).fill(0);
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

function countOperationsToEmptyArray(nums: number[]): number {
    const pos: Map<number, number> = new Map();
    const n = nums.length;
    for (let i = 0; i < n; ++i) {
        pos.set(nums[i], i);
    }
    nums.sort((a, b) => a - b);
    const tree = new BinaryIndexedTree(n);
    let ans = pos.get(nums[0])! + 1;
    for (let k = 0; k < n - 1; ++k) {
        const i = pos.get(nums[k])!;
        const j = pos.get(nums[k + 1])!;
        let d = j - i - (tree.query(j + 1) - tree.query(i + 1));
        if (i > j) {
            d += n - k;
        }
        ans += d;
        tree.update(i + 1, 1);
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

<p>给你一个包含若干 <strong>互不相同</strong>&nbsp;整数的数组&nbsp;<code>nums</code>&nbsp;，你需要执行以下操作 <strong>直到</strong><strong>数组为空</strong>&nbsp;：</p>

<ul>
	<li>如果数组中第一个元素是当前数组中的 <strong>最小值</strong>&nbsp;，则删除它。</li>
	<li>否则，将第一个元素移动到数组的 <strong>末尾</strong>&nbsp;。</li>
</ul>

<p>请你返回需要多少个操作使<em>&nbsp;</em><code>nums</code><em>&nbsp;</em>为空。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [3,4,-1]
<b>输出：</b>5
</pre>

<table style="border: 2px solid black; border-collapse: collapse;">
	<thead>
		<tr>
			<th style="border: 2px solid black; padding: 5px;">Operation</th>
			<th style="border: 2px solid black; padding: 5px;">Array</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td style="border: 2px solid black; padding: 5px;">1</td>
			<td style="border: 2px solid black; padding: 5px;">[4, -1, 3]</td>
		</tr>
		<tr>
			<td style="border: 2px solid black; padding: 5px;">2</td>
			<td style="border: 2px solid black; padding: 5px;">[-1, 3, 4]</td>
		</tr>
		<tr>
			<td style="border: 2px solid black; padding: 5px;">3</td>
			<td style="border: 2px solid black; padding: 5px;">[3, 4]</td>
		</tr>
		<tr>
			<td style="border: 2px solid black; padding: 5px;">4</td>
			<td style="border: 2px solid black; padding: 5px;">[4]</td>
		</tr>
		<tr>
			<td style="border: 2px solid black; padding: 5px;">5</td>
			<td style="border: 2px solid black; padding: 5px;">[]</td>
		</tr>
	</tbody>
</table>

<p>&nbsp;</p>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [1,2,4,3]
<b>输出：</b>5
</pre>

<table style="border: 2px solid black; border-collapse: collapse;">
	<thead>
		<tr>
			<th style="border: 2px solid black; padding: 5px;">Operation</th>
			<th style="border: 2px solid black; padding: 5px;">Array</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td style="border: 2px solid black; padding: 5px;">1</td>
			<td style="border: 2px solid black; padding: 5px;">[2, 4, 3]</td>
		</tr>
		<tr>
			<td style="border: 2px solid black; padding: 5px;">2</td>
			<td style="border: 2px solid black; padding: 5px;">[4, 3]</td>
		</tr>
		<tr>
			<td style="border: 2px solid black; padding: 5px;">3</td>
			<td style="border: 2px solid black; padding: 5px;">[3, 4]</td>
		</tr>
		<tr>
			<td style="border: 2px solid black; padding: 5px;">4</td>
			<td style="border: 2px solid black; padding: 5px;">[4]</td>
		</tr>
		<tr>
			<td style="border: 2px solid black; padding: 5px;">5</td>
			<td style="border: 2px solid black; padding: 5px;">[]</td>
		</tr>
	</tbody>
</table>

<p>&nbsp;</p>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [1,2,3]
<b>输出：</b>3
</pre>

<table style="border: 2px solid black; border-collapse: collapse;">
	<thead>
		<tr>
			<th style="border: 2px solid black; padding: 5px;">Operation</th>
			<th style="border: 2px solid black; padding: 5px;">Array</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td style="border: 2px solid black; padding: 5px;">1</td>
			<td style="border: 2px solid black; padding: 5px;">[2, 3]</td>
		</tr>
		<tr>
			<td style="border: 2px solid black; padding: 5px;">2</td>
			<td style="border: 2px solid black; padding: 5px;">[3]</td>
		</tr>
		<tr>
			<td style="border: 2px solid black; padding: 5px;">3</td>
			<td style="border: 2px solid black; padding: 5px;">[]</td>
		</tr>
	</tbody>
</table>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>9&nbsp;</sup>&lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>nums</code>&nbsp;中的元素 <strong>互不相同</strong>&nbsp;。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 排序 + 树状数组

我们先用哈希表 $pos$ 记录数组 $nums$ 中每个元素的位置，接下来对数组 $nums$ 进行排序，那么数组最小值的下标为 $pos[nums[0]]$，移动到数组的第一个位置并且删除，需要 $pos[nums[0]] + 1$ 次操作，因此初始答案为 $ans = pos[nums[0]] + 1$。

接下来，我们遍历排序后的数组 $nums$，相邻两个元素 $a$ 和 $b$ 的下标分别为 $i=pos[a]$, $j=pos[b]$。那么将第二个元素 $b$ 移动到数组第一个位置并且删除所需要的操作数，等于两个下标的间隔，减去两个下标之间此前删除的下标个数，累加操作数到答案中。我们可以用树状数组或者有序列表维护已删除的下标，这样就可以在 $O(\log n)$ 的时间内求出两个下标之间已删除的下标个数。注意，如果 $i \gt j$，那么需要额外增加 $n - k$ 次操作，其中 $k$ 是当前遍历到的位置。

遍历结束后，返回操作数 $ans$ 即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countOperationsToEmptyArray(self, nums: List[int]) -> int:
        pos = {x: i for i, x in enumerate(nums)}
        nums.sort()
        sl = SortedList()
        ans = pos[nums[0]] + 1
        n = len(nums)
        for k, (a, b) in enumerate(pairwise(nums)):
            i, j = pos[a], pos[b]
            d = j - i - sl.bisect(j) + sl.bisect(i)
            ans += d + (n - k) * int(i > j)
            sl.add(i)
        return ans
```

#### Java

```java
class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        c = new int[n + 1];
    }

    public void update(int x, int delta) {
        while (x <= n) {
            c[x] += delta;
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
    public long countOperationsToEmptyArray(int[] nums) {
        int n = nums.length;
        Map<Integer, Integer> pos = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            pos.put(nums[i], i);
        }
        Arrays.sort(nums);
        long ans = pos.get(nums[0]) + 1;
        BinaryIndexedTree tree = new BinaryIndexedTree(n);
        for (int k = 0; k < n - 1; ++k) {
            int i = pos.get(nums[k]), j = pos.get(nums[k + 1]);
            long d = j - i - (tree.query(j + 1) - tree.query(i + 1));
            ans += d + (n - k) * (i > j ? 1 : 0);
            tree.update(i + 1, 1);
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
    long long countOperationsToEmptyArray(vector<int>& nums) {
        unordered_map<int, int> pos;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            pos[nums[i]] = i;
        }
        sort(nums.begin(), nums.end());
        BinaryIndexedTree tree(n);
        long long ans = pos[nums[0]] + 1;
        for (int k = 0; k < n - 1; ++k) {
            int i = pos[nums[k]], j = pos[nums[k + 1]];
            long long d = j - i - (tree.query(j + 1) - tree.query(i + 1));
            ans += d + (n - k) * int(i > j);
            tree.update(i + 1, 1);
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

func countOperationsToEmptyArray(nums []int) int64 {
	n := len(nums)
	pos := map[int]int{}
	for i, x := range nums {
		pos[x] = i
	}
	sort.Ints(nums)
	tree := newBinaryIndexedTree(n)
	ans := pos[nums[0]] + 1
	for k := 0; k < n-1; k++ {
		i, j := pos[nums[k]], pos[nums[k+1]]
		d := j - i - (tree.query(j+1) - tree.query(i+1))
		if i > j {
			d += n - k
		}
		ans += d
		tree.update(i+1, 1)
	}
	return int64(ans)
}
```

#### TypeScript

```ts
class BinaryIndexedTree {
    private n: number;
    private c: number[];

    constructor(n: number) {
        this.n = n;
        this.c = Array(n + 1).fill(0);
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

function countOperationsToEmptyArray(nums: number[]): number {
    const pos: Map<number, number> = new Map();
    const n = nums.length;
    for (let i = 0; i < n; ++i) {
        pos.set(nums[i], i);
    }
    nums.sort((a, b) => a - b);
    const tree = new BinaryIndexedTree(n);
    let ans = pos.get(nums[0])! + 1;
    for (let k = 0; k < n - 1; ++k) {
        const i = pos.get(nums[k])!;
        const j = pos.get(nums[k + 1])!;
        let d = j - i - (tree.query(j + 1) - tree.query(i + 1));
        if (i > j) {
            d += n - k;
        }
        ans += d;
        tree.update(i + 1, 1);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Python3

```python
class BinaryIndexedTree:
    def __init__(self, n):
        self.n = n
        self.c = [0] * (n + 1)

    def update(self, x, delta):
        while x <= self.n:
            self.c[x] += delta
            x += x & -x

    def query(self, x):
        s = 0
        while x:
            s += self.c[x]
            x -= x & -x
        return s


class Solution:
    def countOperationsToEmptyArray(self, nums: List[int]) -> int:
        pos = {x: i for i, x in enumerate(nums)}
        nums.sort()
        ans = pos[nums[0]] + 1
        n = len(nums)
        tree = BinaryIndexedTree(n)
        for k, (a, b) in enumerate(pairwise(nums)):
            i, j = pos[a], pos[b]
            d = j - i - tree.query(j + 1) + tree.query(i + 1)
            ans += d + (n - k) * int(i > j)
            tree.update(i + 1, 1)
        return ans
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
