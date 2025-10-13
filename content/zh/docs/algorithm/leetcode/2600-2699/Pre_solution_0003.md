---
title: "2620_计数器"
date: 2025-10-08T18:39:28+08:00
weight: 3
tags: [JavaScript]
---

{{< markmap >}}
### [2620_计数器](#2620)
#### [JavaScript](#2620)
### [2621_睡眠函数](#2621)
#### [JavaScript](#2621)
### [2622_有时间限制的缓存](#2622)
#### [JavaScript](#2622)
### [2623_记忆函数](#2623)
#### [JavaScript](#2623)
### [2624_蜗牛排序](#2624)
#### [JavaScript](#2624)
### [2625_扁平化嵌套数组](#2625)
#### [JavaScript](#2625)
### [2626_数组归约运算](#2626)
#### [JavaScript](#2626)
### [2627_函数防抖](#2627)
#### [JavaScript](#2627)
### [2628_完全相等的 JSON 字符串 🔒](#2628)
#### [JavaScript](#2628)
### [2629_复合函数](#2629)
#### [JavaScript](#2629)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2620_计数器
___
#### JavaScript
---
### 2621_睡眠函数
___
#### JavaScript
---
### 2622_有时间限制的缓存
___
#### JavaScript
---
### 2623_记忆函数
___
#### JavaScript
---
### 2624_蜗牛排序
___
#### JavaScript
---
### 2625_扁平化嵌套数组
___
#### JavaScript
---
### 2626_数组归约运算
___
#### JavaScript
---
### 2627_函数防抖
___
#### JavaScript
---
### 2628_完全相等的 JSON 字符串 🔒
___
#### JavaScript
---
### 2629_复合函数
___
#### JavaScript
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| JavaScript |  |  |

# [2620. 计数器](https://leetcode.cn/problems/counter){#2620}

{{< tabs "2620" >}}

{{% tab "ts" %}}
```ts
function createCounter(n: number): () => number {
    let i = n;
    return function () {
        return i++;
    };
}

/**
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个整型参数 <code>n</code>，请你编写并返回一个 <code>counter</code><strong>&nbsp;</strong>函数。这个&nbsp;<code>counter</code><strong>&nbsp;</strong>函数最初返回 <code>n</code>，每次调用它时会返回前一个值加 1 的值 ( <code>n</code> ,&nbsp; <code>n + 1</code> ,&nbsp; <code>n + 2</code> ，等等)。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
n = 10 
["call","call","call"]
<strong>输出：</strong>[10,11,12]
<strong>解释：</strong>
counter() = 10 // 第一次调用 counter()，返回 n。
counter() = 11 // 返回上次调用的值加 1。
counter() = 12 // 返回上次调用的值加 1。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>
n = -2
["call","call","call","call","call"]
<strong>输出：</strong>[-2,-1,0,1,2]
<strong>解释：</strong>counter() 最初返回 -2。然后在每个后续调用后增加 1。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>-1000<sup>&nbsp;</sup>&lt;= n &lt;= 1000</code></li>
	<li><code>0 &lt;= calls.length &lt;= 1000</code></li>
	<li><code>calls[i] === "call"</code></li>
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
function createCounter(n: number): () => number {
    let i = n;
    return function () {
        return i++;
    };
}

/**
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2621. 睡眠函数](https://leetcode.cn/problems/sleep){#2621}

{{< tabs "2621" >}}

{{% tab "ts" %}}
```ts
async function sleep(millis: number): Promise<void> {
    return new Promise(r => setTimeout(r, millis));
}

/**
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} millis
 * @return {Promise}
 */
async function sleep(millis) {
    return new Promise(r => setTimeout(r, millis));
}

/**
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>请你编写一个异步函数，它接收一个正整数参数 <code>millis</code>&nbsp;，并休眠 <code>millis</code> 毫秒。要求此函数可以解析任何值。</p>

<p><strong>请注意</strong>，实际睡眠持续时间与&nbsp;<code>millis</code> 之间的微小偏差是可以接受的。</p>

<p>&nbsp;</p>

<p><b>示例 1：</b></p>

<pre>
<b>输入：</b>millis = 100
<b>输出：</b>100
<b>解释：</b>
在 100ms 后此异步函数执行完时返回一个 Promise 对象
let t = Date.now();
sleep(100).then(() =&gt; {
  console.log(Date.now() - t); // 100
});
</pre>

<p><b>示例 2：</b></p>

<pre>
<b>输入：</b>millis = 200
<b>输出：</b>200
<b>解释：</b>在 200ms 后函数执行完时返回一个 Promise 对象
</pre>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<ul>
	<li><code>1 &lt;= millis &lt;= 1000</code></li>
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
async function sleep(millis: number): Promise<void> {
    return new Promise(r => setTimeout(r, millis));
}

/**
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */
```

#### JavaScript

```js
/**
 * @param {number} millis
 * @return {Promise}
 */
async function sleep(millis) {
    return new Promise(r => setTimeout(r, millis));
}

/**
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2622. 有时间限制的缓存](https://leetcode.cn/problems/cache-with-time-limit){#2622}

{{< tabs "2622" >}}

{{% tab "ts" %}}
```ts
class TimeLimitedCache {
    #cache: Map<number, [value: number, expire: number]> = new Map();

    set(key: number, value: number, duration: number): boolean {
        const isExist = this.#cache.has(key);

        if (!this.#isExpired(key)) {
            this.#cache.set(key, [value, Date.now() + duration]);
        }

        return isExist;
    }

    get(key: number): number {
        if (this.#isExpired(key)) return -1;
        const res = this.#cache.get(key)?.[0] ?? -1;
        return res;
    }

    count(): number {
        const xs = Array.from(this.#cache).filter(([key]) => !this.#isExpired(key));
        return xs.length;
    }

    #isExpired = (key: number) =>
        this.#cache.has(key) &&
        (this.#cache.get(key)?.[1] ?? Number.NEGATIVE_INFINITY) < Date.now();
}

/**
 * Your TimeLimitedCache object will be instantiated and called as such:
 * var obj = new TimeLimitedCache()
 * obj.set(1, 42, 1000); // false
 * obj.get(1) // 42
 * obj.count() // 1
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>编写一个类，它允许获取和设置键-值对，并且每个键都有一个&nbsp;<strong>过期时间</strong>&nbsp;。</p>

<p>该类有三个公共方法：</p>

<p><code>set(key, value, duration)</code>&nbsp;：接收参数为整型键 <code>key</code> 、整型值 <code>value</code> 和以毫秒为单位的持续时间 <code>duration</code> 。一旦 <code>duration</code>&nbsp;到期后，这个键就无法访问。如果相同的未过期键已经存在，该方法将返回&nbsp;<code>true</code>&nbsp;，否则返回&nbsp;<code>false</code>&nbsp;。如果该键已经存在，则它的值和持续时间都应该被覆盖。</p>

<p><code>get(key)</code>&nbsp;：如果存在一个未过期的键，它应该返回这个键相关的值。否则返回&nbsp;<code>-1</code>&nbsp;。</p>

<p><code>count()</code>&nbsp;：返回未过期键的总数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong> 
actions = ["TimeLimitedCache", "set", "get", "count", "get"]
values = [[], [1, 42, 100], [1], [], [1]]
timeDeays = [0, 0, 50, 50, 150]
<strong>输出：</strong> [null, false, 42, 1, -1]
<strong>解释：</strong>
在 t=0 时，缓存被构造。
在 t=0 时，添加一个键值对 (1: 42) ，过期时间为 100ms 。因为该值不存在，因此返回false。
在 t=50 时，请求 key=1 并返回值 42。
在 t=50 时，调用 count() ，缓存中有一个未过期的键。
在 t=100 时，key=1 到期。
在 t=150 时，调用 get(1) ，返回 -1，因为缓存是空的。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>
actions = ["TimeLimitedCache", "set", "set", "get", "get", "get", "count"]
values = [[], [1, 42, 50], [1, 50, 100], [1], [1], [1], []]
timeDelays = [0, 0, 40, 50, 120, 200, 250]
<strong>输出：</strong> [null, false, true, 50, 50, -1]
<strong>解释：</strong>
在 t=0 时，缓存被构造。
在 t=0 时，添加一个键值对 (1: 42) ，过期时间为 50ms。因为该值不存在，因此返回false。
当 t=40 时，添加一个键值对 (1: 50) ，过期时间为 100ms。因为一个未过期的键已经存在，返回 true 并覆盖这个键的旧值。
在 t=50 时，调用 get(1) ，返回 50。
在 t=120 时，调用 get(1) ，返回 50。
在 t=140 时，key=1 过期。
在 t=200 时，调用 get(1) ，但缓存为空，因此返回 -1。
在 t=250 时，count() 返回0 ，因为缓存是空的，没有未过期的键。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= key, value &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= duration &lt;= 1000</code></li>
	<li><code>1 &lt;= actions.length &lt;= 100</code></li>
	<li><code>actions.length === values.length</code></li>
	<li><code>actions.length === timeDelays.length</code></li>
	<li><code>0 &lt;= timeDelays[i] &lt;= 1450</code></li>
	<li><code>actions[i]</code> 是 "TimeLimitedCache"、"set"、"get" 和 "count" 中的一个。</li>
	<li>第一个操作始终是 "TimeLimitedCache" 而且一定会以 0 毫秒的延迟立即执行</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们用哈希表 $cache$ 记录键值对，其中键为整型键 $key$，值为一个数组，数组的第一个元素为整型值 $value$，第二个元素为元素的过期时间 $expire$。

我们实现一个 `removeExpire` 方法，用于删除过期的键值对。在 `set`、`get` 和 `count` 方法中，我们先调用 `removeExpire` 方法，然后再进行相应的操作。

时间复杂度为 $O(1)$，空间复杂度为 $O(n)$。其中 $n$ 为哈希表 $cache$ 的大小。

<!-- tabs:start -->

#### TypeScript

```ts
class TimeLimitedCache {
    #cache: Map<number, [value: number, expire: number]> = new Map();

    set(key: number, value: number, duration: number): boolean {
        const isExist = this.#cache.has(key);

        if (!this.#isExpired(key)) {
            this.#cache.set(key, [value, Date.now() + duration]);
        }

        return isExist;
    }

    get(key: number): number {
        if (this.#isExpired(key)) return -1;
        const res = this.#cache.get(key)?.[0] ?? -1;
        return res;
    }

    count(): number {
        const xs = Array.from(this.#cache).filter(([key]) => !this.#isExpired(key));
        return xs.length;
    }

    #isExpired = (key: number) =>
        this.#cache.has(key) &&
        (this.#cache.get(key)?.[1] ?? Number.NEGATIVE_INFINITY) < Date.now();
}

/**
 * Your TimeLimitedCache object will be instantiated and called as such:
 * var obj = new TimeLimitedCache()
 * obj.set(1, 42, 1000); // false
 * obj.get(1) // 42
 * obj.count() // 1
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2623. 记忆函数](https://leetcode.cn/problems/memoize){#2623}

{{< tabs "2623" >}}

{{% tab "ts" %}}
```ts
type Fn = (...params: any) => any;

function memoize(fn: Fn): Fn {
    const cache: Record<any, any> = {};

    return function (...args) {
        if (args in cache) {
            return cache[args];
        }
        const result = fn(...args);
        cache[args] = result;
        return result;
    };
}

/**
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>请你编写一个函数 <code>fn</code>，它接收另一个函数作为输入，并返回该函数的 <strong>记忆化</strong> 后的结果。</p>

<p><strong>记忆函数</strong> 是一个对于相同的输入永远不会被调用两次的函数。相反，它将返回一个缓存值。</p>

<p>你可以假设有 <strong>3</strong> 个可能的输入函数：<code>sum</code> 、<code>fib</code> 和 <code>factorial</code> 。</p>

<ul>
	<li>&nbsp;<code>sum</code> 接收两个整型参数 <code>a</code> 和 <code>b</code> ，并返回 <code>a + b</code> 。假设如果参数 <code>(b, a)</code> 已经缓存了值，其中 <code>a != b</code>，它不能用于参数 <code>(a, b)</code>。例如，如果参数是 <code>(3, 2)</code> 和 <code>(2, 3)</code>，则应进行两个单独的调用。</li>
	<li>&nbsp;<code>fib</code> 接收一个整型参数&nbsp;<code>n</code> ，如果 <code>n &lt;= 1</code> 则返回 <code>1</code>，否则返回 <code>fib (n - 1) + fib (n - 2)</code>。</li>
	<li>&nbsp;<code>factorial</code> 接收一个整型参数 <code>n</code> ，如果 <code>n &lt;= 1</code> 则返回&nbsp;&nbsp;<code>1</code>&nbsp;，否则返回 <code>factorial(n - 1) * n</code> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
fnName = "sum"
actions = ["call","call","getCallCount","call","getCallCount"]
values = [[2,2],[2,2],[],[1,2],[]]
<strong>输出：</strong>[4,4,1,3,2]
<strong>解释：</strong>
const sum = (a, b) =&gt; a + b;
const memoizedSum = memoize(sum);
memoizedSum (2, 2);// "call" - 返回 4。sum() 被调用，因为之前没有使用参数 (2, 2) 调用过。
memoizedSum (2, 2);// "call" - 返回 4。没有调用 sum()，因为前面有相同的输入。
// "getCallCount" - 总调用数： 1
memoizedSum(1, 2);// "call" - 返回 3。sum() 被调用，因为之前没有使用参数 (1, 2) 调用过。
// "getCallCount" - 总调用数： 2
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：
</strong>fnName = "factorial"
actions = ["call","call","call","getCallCount","call","getCallCount"]
values = [[2],[3],[2],[],[3],[]]
<strong>输出：</strong>[2,6,2,2,6,2]
<strong>解释：</strong>
const factorial = (n) =&gt; (n &lt;= 1) ? 1 : (n * factorial(n - 1));
const memoFactorial = memoize(factorial);
memoFactorial(2); // "call" - 返回 2。
memoFactorial(3); // "call" - 返回 6。
memoFactorial(2); // "call" - 返回 2。 没有调用 factorial()，因为前面有相同的输入。
// "getCallCount" -  总调用数：2
memoFactorial(3); // "call" - 返回 6。 没有调用 factorial()，因为前面有相同的输入。
// "getCallCount" -  总调用数：2
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：
</strong>fnName = "fib"
actions = ["call","getCallCount"]
values = [[5],[]]
<strong>输出：</strong>[8,1]
<strong>解释：
</strong>fib(5) = 8 // "call"
// "getCallCount" -&nbsp;总调用数：1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= a, b &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= n &lt;= 10</code></li>
	<li><code>1 &lt;= actions.length &lt;= 10<sup>5</sup></code></li>
	<li><code>actions.length === values.length</code></li>
	<li><code>actions[i]</code> 为&nbsp;"call" 和 "getCallCount" 中的一个</li>
	<li><code>fnName</code> 为 "sum", "factorial" 和 "fib" 中的一个</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们可以使用哈希表来存储函数的参数和返回值，当再次调用函数时，如果参数已经存在于哈希表中，则直接返回哈希表中的值，否则调用函数并将返回值存入哈希表中。

时间复杂度 $O(1)$，空间复杂度 $O(n)$。其中 $n$ 为函数的参数个数。

<!-- tabs:start -->

#### TypeScript

```ts
type Fn = (...params: any) => any;

function memoize(fn: Fn): Fn {
    const cache: Record<any, any> = {};

    return function (...args) {
        if (args in cache) {
            return cache[args];
        }
        const result = fn(...args);
        cache[args] = result;
        return result;
    };
}

/**
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2624. 蜗牛排序](https://leetcode.cn/problems/snail-traversal){#2624}

{{< tabs "2624" >}}

{{% tab "ts" %}}
```ts
declare global {
    interface Array<T> {
        snail(rowsCount: number, colsCount: number): number[][];
    }
}

Array.prototype.snail = function (rowsCount: number, colsCount: number): number[][] {
    if (rowsCount * colsCount !== this.length) {
        return [];
    }
    const ans: number[][] = Array.from({ length: rowsCount }, () => Array(colsCount));
    for (let h = 0, i = 0, j = 0, k = 1; h < this.length; ++h) {
        ans[i][j] = this[h];
        i += k;
        if (i === rowsCount || i === -1) {
            i -= k;
            k = -k;
            ++j;
        }
    }
    return ans;
};

/**
 * const arr = [1,2,3,4];
 * arr.snail(1,4); // [[1,2,3,4]]
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>请你编写一段代码为所有数组实现&nbsp;&nbsp;<code>snail(rowsCount，colsCount)</code> 方法，该方法将 1D 数组转换为以蜗牛排序的模式的 2D 数组。无效的输入值应该输出一个空数组。当 <code>rowsCount * colsCount&nbsp;!==</code><code>nums.length</code>&nbsp;时。这个输入被认为是无效的。</p>

<p>蜗牛排序从左上角的单元格开始，从当前数组的第一个值开始。然后，它从上到下遍历第一列，接着移动到右边的下一列，并从下到上遍历它。将这种模式持续下去，每列交替变换遍历方向，直到覆盖整个数组。例如，当给定输入数组&nbsp;&nbsp;<code>[19, 10, 3, 7, 9, 8, 5, 2, 1, 17, 16, 14, 12, 18, 6, 13, 11, 20, 4, 15]</code> ，当 <code>rowsCount = 5</code>&nbsp;且&nbsp;<code>colsCount = 4</code> 时，需要输出矩阵如下图所示。注意，矩阵沿箭头方向对应于原数组中数字的顺序</p>

<p>&nbsp;</p>

<p><img alt="Traversal Diagram" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2600-2699/2624.Snail%20Traversal/images/screen-shot-2023-04-10-at-100006-pm.png" style="width: 275px; height: 343px;" /></p>

<p>&nbsp;</p>

<p><b>示例 1：</b></p>

<pre>
<b>输入：</b>
nums = [19, 10, 3, 7, 9, 8, 5, 2, 1, 17, 16, 14, 12, 18, 6, 13, 11, 20, 4, 15]
rowsCount = 5
colsCount = 4
<b>输出：</b>
[
 [19,17,16,15],
&nbsp;[10,1,14,4],
&nbsp;[3,2,12,20],
&nbsp;[7,5,18,11],
&nbsp;[9,8,6,13]
]
</pre>

<p><b>示例 2：</b></p>

<pre>
<b>输入：</b>
nums = [1,2,3,4]
rowsCount = 1
colsCount = 4
<b>输出：</b>[[1, 2, 3, 4]]
</pre>

<p><b>示例 3：</b></p>

<pre>
<b>输入：</b>
nums = [1,3]
rowsCount = 2
colsCount = 2
<b>输出：</b>[]
<strong>Explanation:</strong> 2 * 2 = 4, 且原数组 [1,3] 的长度为 2; 所以，输入是无效的。
</pre>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<ul>
	<li><code>0 &lt;= nums.length &lt;= 250</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 1000</code></li>
	<li><code>1 &lt;= rowsCount &lt;= 250</code></li>
	<li><code>1 &lt;= colsCount &lt;= 250</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们首先判断数组的长度是否等于行数与列数的乘积，如果不等，说明输入是无效的，返回空数组。

接下来，我们可以模拟蜗牛排序的过程，从左上角开始，遍历数组，按照蜗牛排序的顺序，将遍历到的元素依次放入结果数组中。

时间复杂度 $(n)$，其中 $n$ 为数组的长度。忽略答案数组的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### TypeScript

```ts
declare global {
    interface Array<T> {
        snail(rowsCount: number, colsCount: number): number[][];
    }
}

Array.prototype.snail = function (rowsCount: number, colsCount: number): number[][] {
    if (rowsCount * colsCount !== this.length) {
        return [];
    }
    const ans: number[][] = Array.from({ length: rowsCount }, () => Array(colsCount));
    for (let h = 0, i = 0, j = 0, k = 1; h < this.length; ++h) {
        ans[i][j] = this[h];
        i += k;
        if (i === rowsCount || i === -1) {
            i -= k;
            k = -k;
            ++j;
        }
    }
    return ans;
};

/**
 * const arr = [1,2,3,4];
 * arr.snail(1,4); // [[1,2,3,4]]
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2625. 扁平化嵌套数组](https://leetcode.cn/problems/flatten-deeply-nested-array){#2625}

{{< tabs "2625" >}}

{{% tab "ts" %}}
```ts
type MultiDimensionalArray = (number | MultiDimensionalArray)[];

var flat = function (arr: MultiDimensionalArray, n: number): MultiDimensionalArray {
    if (!n) {
        return arr;
    }
    const ans: MultiDimensionalArray = [];
    for (const x of arr) {
        if (Array.isArray(x) && n) {
            ans.push(...flat(x, n - 1));
        } else {
            ans.push(x);
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

<p>请你编写一个函数，它接收一个&nbsp;<strong>多维数组&nbsp;</strong><code>arr</code> 和它的深度 <code>n</code> ，并返回该数组的&nbsp;<strong>扁平化&nbsp;</strong>后的结果。</p>

<p><strong>多维数组&nbsp;</strong>是一种包含整数或其他&nbsp;<strong>多维数组&nbsp;</strong>的递归数据结构。</p>

<p>数组 <strong>扁平化</strong> 是对数组的一种操作，定义是将原数组部分或全部子数组删除，并替换为该子数组中的实际元素。只有当嵌套的数组深度小于 <code>n</code> 时，才应该执行扁平化操作。第一层数组中元素的深度被认为是 0。</p>

<p>请在没有使用内置方法&nbsp;<code>Array.flat</code> 的前提下解决这个问题。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入</strong>
arr = [1, 2, 3, [4, 5, 6], [7, 8, [9, 10, 11], 12], [13, 14, 15]]
n = 0
<strong>输出</strong>
[1, 2, 3, [4, 5, 6], [7, 8, [9, 10, 11], 12], [13, 14, 15]]

<strong>解释</strong>
传递深度 n=0 的多维数组将始终得到原始数组。这是因为子数组(0)的最小可能的深度不小于 n = 0。因此，任何子数组都不应该被平面化。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入</strong>
arr = [1, 2, 3, [4, 5, 6], [7, 8, [9, 10, 11], 12], [13, 14, 15]]
n = 1
<strong>输出</strong>
[1, 2, 3, 4, 5, 6, 7, 8, [9, 10, 11], 12, 13, 14, 15]

<strong>解释</strong>
以 4 、7 和 13 开头的子数组都被扁平化了，这是因为它们的深度为 0， 而 0 小于 1。然而 [9,10,11] 其深度为 1，所以未被扁平化。</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入</strong>
arr = [[1, 2, 3], [4, 5, 6], [7, 8, [9, 10, 11], 12], [13, 14, 15]]
n = 2
<strong>输出</strong>
[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]

<strong>解释</strong>
所有子数组的最大深度都为 1。因此，它们都被扁平化了。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= arr 的元素个数&nbsp;&lt;=&nbsp;10<sup>5</sup></code></li>
	<li><code>0 &lt;= arr 的子数组个数&nbsp;&lt;=&nbsp;10<sup>5</sup></code></li>
	<li><code>maxDepth &lt;= 1000</code></li>
	<li><code>-1000 &lt;= each number &lt;= 1000</code></li>
	<li><code><font face="monospace">0 &lt;= n &lt;= 1000</font></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归

我们可以使用递归的方法，将多维数组扁平化。

在函数中，我们首先判断 $n$ 是否小于等于 $0$，如果是，直接返回原数组。否则，我们遍历数组的每个元素 $x$，如果 $x$ 是数组，我们递归调用函数，参数为 $(x, n - 1)$，将返回值添加到结果数组中；否则，将 $x$ 添加到结果数组中。最后返回结果数组。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组的元素个数。

<!-- tabs:start -->

#### TypeScript

```ts
type MultiDimensionalArray = (number | MultiDimensionalArray)[];

var flat = function (arr: MultiDimensionalArray, n: number): MultiDimensionalArray {
    if (!n) {
        return arr;
    }
    const ans: MultiDimensionalArray = [];
    for (const x of arr) {
        if (Array.isArray(x) && n) {
            ans.push(...flat(x, n - 1));
        } else {
            ans.push(x);
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

# [2626. 数组归约运算](https://leetcode.cn/problems/array-reduce-transformation){#2626}

{{< tabs "2626" >}}

{{% tab "ts" %}}
```ts
type Fn = (accum: number, curr: number) => number;

function reduce(nums: number[], fn: Fn, init: number): number {
    let acc: number = init;
    for (const x of nums) {
        acc = fn(acc, x);
    }
    return acc;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个整数数组 <code>nums</code>、一个 reducer 函数 <code>fn</code> 和一个初始值 <code>init</code>，返回通过依次对数组的每个元素执行 <code>fn</code> 函数得到的最终结果。</p>

<p>通过以下操作实现这个结果：<code>val = fn(init, nums[0])，val = fn(val, nums[1])，val = fn(val, nums[2])，...</code> 直到处理数组中的每个元素。然后返回 <code>val</code> 的最终值。</p>

<p>如果数组的长度为 0，则函数应返回 <code>init</code>。</p>

<p>请你在不使用内置数组方法的&nbsp;<code>Array.reduce</code>&nbsp;前提下解决这个问题。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>
nums = [1,2,3,4]
fn = function sum(accum, curr) { return accum + curr; }
init = 0
<strong>输出：</strong>10
<strong>解释：</strong>
初始值为 init=0 。
(0) + nums[0] = 1
(1) + nums[1] = 3
(3) + nums[2] = 6
(6) + nums[3] = 10
Val 最终值为 10。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong> 
nums = [1,2,3,4]
fn = function sum(accum, curr) { return accum + curr * curr; }
init = 100
<strong>输出：</strong>130
<strong>解释：</strong>
初始值为 init=100 。
(100) + nums[0]^2 = 101
(101) + nums[1]^2 = 105
(105) + nums[2]^2 = 114
(114) + nums[3]^2 = 130
Val 最终值为 130。
</pre>

<p><strong class="example">示例3:</strong></p>

<pre>
<strong>输入：</strong> 
nums = []
fn = function sum(accum, curr) { return 0; }
init = 25
<strong>输出：</strong>25
<b>解释：</b>这是一个空数组，所以返回 init 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 1000</code></li>
	<li><code>0 &lt;= init &lt;= 1000</code></li>
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
type Fn = (accum: number, curr: number) => number;

function reduce(nums: number[], fn: Fn, init: number): number {
    let acc: number = init;
    for (const x of nums) {
        acc = fn(acc, x);
    }
    return acc;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2627. 函数防抖](https://leetcode.cn/problems/debounce){#2627}

{{< tabs "2627" >}}

{{% tab "ts" %}}
```ts
type F = (...p: any[]) => any;

function debounce(fn: F, t: number): F {
    let timeout: ReturnType<typeof setTimeout> | undefined;

    return function (...args) {
        if (timeout !== undefined) {
            clearTimeout(timeout);
        }
        timeout = setTimeout(() => {
            fn.apply(this, args);
        }, t);
    };
}

/**
 * const log = debounce(console.log, 100);
 * log('Hello'); // cancelled
 * log('Hello'); // cancelled
 * log('Hello'); // Logged at t=100ms
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>请你编写一个函数，接收参数为另一个函数和一个以毫秒为单位的时间 <code>t</code> ，并返回该函数的&nbsp;<b>函数防抖&nbsp;</b>后的结果。</p>

<p><b>函数防抖 </b>方法是一个函数，它的执行被延迟了 <code>t</code> 毫秒，如果在这个时间窗口内再次调用它，它的执行将被取消。你编写的防抖函数也应该接收传递的参数。</p>

<p>例如，假设 <code>t = 50ms</code> ，函数分别在 <code>30ms</code> 、 <code>60ms</code> 和 <code>100ms</code> 时调用。前两个函数调用将被取消，第三个函数调用将在 <code>150ms</code> 执行。如果改为 <code>t = 35ms</code> ，则第一个调用将被取消，第二个调用将在 <code>95ms</code> 执行，第三个调用将在 <code>135ms</code> 执行。</p>

<p><img alt="Debounce Schematic" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2600-2699/2627.Debounce/images/screen-shot-2023-04-08-at-11048-pm.png" style="width: 800px; height: 242px;" /></p>

<p>上图展示了了防抖函数是如何转换事件的。其中，每个矩形表示 100ms，反弹时间为 400ms。每种颜色代表一组不同的输入。</p>

<p>请在不使用 lodash 的 <code>_.debounce()</code> 函数的前提下解决该问题。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>
t = 50
calls = [
&nbsp; {"t": 50, inputs: [1]},
&nbsp; {"t": 75, inputs: [2]}
]
<b>输出：</b>[{"t": 125, inputs: [2]}]
<strong>解释：</strong>
let start = Date.now();
function log(...inputs) { 
&nbsp; console.log([Date.now() - start, inputs ])
}
const dlog = debounce(log, 50);
setTimeout(() =&gt; dlog(1), 50);
setTimeout(() =&gt; dlog(2), 75);

第一次调用被第二次调用取消，因为第二次调用发生在 100ms 之前
第二次调用延迟 50ms，在 125ms 执行。输入为 (2)。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>
t = 20
calls = [
&nbsp; {"t": 50, inputs: [1]},
&nbsp; {"t": 100, inputs: [2]}
]
<b>输出：</b>[{"t": 70, inputs: [1]}, {"t": 120, inputs: [2]}]
<strong>解释：</strong>
第一次调用延迟到 70ms。输入为 (1)。
第二次调用延迟到 120ms。输入为 (2)。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>
t = 150
calls = [
&nbsp; {"t": 50, inputs: [1, 2]},
&nbsp; {"t": 300, inputs: [3, 4]},
&nbsp; {"t": 300, inputs: [5, 6]}
]
<b>输出：</b>[{"t": 200, inputs: [1,2]}, {"t": 450, inputs: [5, 6]}]
<strong>解释：</strong>
第一次调用延迟了 150ms，运行时间为 200ms。输入为 (1, 2)。
第二次调用被第三次调用取消
第三次调用延迟了 150ms，运行时间为 450ms。输入为 (5, 6)。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= t &lt;= 1000</code></li>
	<li><code>1 &lt;= calls.length &lt;= 10</code></li>
	<li><code>0 &lt;= calls[i].t &lt;= 1000</code></li>
	<li><code>0 &lt;= calls[i].inputs.length &lt;= 10</code></li>
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
type F = (...p: any[]) => any;

function debounce(fn: F, t: number): F {
    let timeout: ReturnType<typeof setTimeout> | undefined;

    return function (...args) {
        if (timeout !== undefined) {
            clearTimeout(timeout);
        }
        timeout = setTimeout(() => {
            fn.apply(this, args);
        }, t);
    };
}

/**
 * const log = debounce(console.log, 100);
 * log('Hello'); // cancelled
 * log('Hello'); // cancelled
 * log('Hello'); // Logged at t=100ms
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2628. 完全相等的 JSON 字符串 🔒](https://leetcode.cn/problems/json-deep-equal){#2628}

{{< tabs "2628" >}}

{{% tab "ts" %}}
```ts
function areDeeplyEqual(o1: any, o2: any): boolean {
    if (o1 === null || typeof o1 !== 'object') {
        return o1 === o2;
    }
    if (typeof o1 !== typeof o2) {
        return false;
    }
    if (Array.isArray(o1) !== Array.isArray(o2)) {
        return false;
    }
    if (Array.isArray(o1)) {
        if (o1.length !== o2.length) {
            return false;
        }
        for (let i = 0; i < o1.length; i++) {
            if (!areDeeplyEqual(o1[i], o2[i])) {
                return false;
            }
        }
        return true;
    } else {
        const keys1 = Object.keys(o1);
        const keys2 = Object.keys(o2);
        if (keys1.length !== keys2.length) {
            return false;
        }
        for (const key of keys1) {
            if (!areDeeplyEqual(o1[key], o2[key])) {
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

<p>给定两个对象 <code>o1</code> 和 <code>o2</code> ，请你检查它们是否 <strong>完全相等</strong> 。</p>

<p>对于两个 <strong>完全相等</strong> 的对象，必须满足以下条件：</p>

<ul>
	<li>如果两个值都是原始类型，它们通过了&nbsp;<code>===</code> 等式检查，则认为这两个值是 <strong>完全相等</strong> 的。</li>
	<li>如果两个值都是数组，在它们具有相同元素且顺序相同，并且每个元素在这些条件下也 <strong>完全相等&nbsp;</strong>时，认为这两个值是&nbsp;<strong>完全相等</strong>&nbsp;的。</li>
	<li>如果两个值都是对象，在它们具有相同键，并且每个键关联的值在这些条件下也 <strong>完全相等</strong> 时，认为这两个值是 <strong>完全相等</strong> 的。</li>
</ul>

<p>你可以假设这两个对象都是 <code>JSON.parse</code> 的输出。换句话说，它们是有效的 <code>JSON</code> 。</p>

<p>请你在不使用 lodash 的 <code>_.isEqual()</code> 函数的前提下解决这个问题。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>o1 = {"x":1,"y":2}, o2 = {"x":1,"y":2}
<b>输出：</b>true
<b>输入：</b>键和值完全匹配。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>o1 = {"y":2,"x":1}, o2 = {"x":1,"y":2}
<b>输出：</b>true
<b>解释：</b>尽管键的顺序不同，但它们仍然完全匹配。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>o1 = {"x":null,"L":[1,2,3]}, o2 = {"x":null,"L":["1","2","3"]}
<b>输出：</b>false
<b>解释：</b>数字数组不同于字符串数组。
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<b>输入：</b>o1 = true, o2 = false
<b>输出：</b>false
<b>解释：</b>true !== false</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= JSON.stringify(o1).length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= JSON.stringify(o2).length &lt;= 10<sup>5</sup></code></li>
	<li><code>maxNestingDepth &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归

我们先判断 `o1` 是否为空，或者 `o1` 是否非对象类型。如果是，则直接返回 `o1` 和 `o2` 是否相等。

否则，我们判断 `o1` 和 `o2` 的类型是否相同。如果不同，则返回 `false`。

接下来，我们判断 `o1` 和 `o2` 是否都是数组。如果不是，则返回 `false`。

如果是数组，则判断两个数组的长度是否相同。如果不同，则返回 `false`。否则，我们遍历两个数组对应位置的元素，递归调用 `areDeeplyEqual` 函数，判断两个元素是否相等。如果有一个元素不相等，则返回 `false`。否则，返回 `true`。

如果 `o1` 和 `o2` 都不是数组，则判断两个对象的键的个数是否相同。如果不同，则返回 `false`。否则，我们遍历 `o1` 的所有键，递归调用 `areDeeplyEqual` 函数，判断两个键对应的值是否相等。如果有一个键对应的值不相等，则返回 `false`。否则，返回 `true`。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为 `o1` 和 `o2` 的长度。

<!-- tabs:start -->

#### TypeScript

```ts
function areDeeplyEqual(o1: any, o2: any): boolean {
    if (o1 === null || typeof o1 !== 'object') {
        return o1 === o2;
    }
    if (typeof o1 !== typeof o2) {
        return false;
    }
    if (Array.isArray(o1) !== Array.isArray(o2)) {
        return false;
    }
    if (Array.isArray(o1)) {
        if (o1.length !== o2.length) {
            return false;
        }
        for (let i = 0; i < o1.length; i++) {
            if (!areDeeplyEqual(o1[i], o2[i])) {
                return false;
            }
        }
        return true;
    } else {
        const keys1 = Object.keys(o1);
        const keys2 = Object.keys(o2);
        if (keys1.length !== keys2.length) {
            return false;
        }
        for (const key of keys1) {
            if (!areDeeplyEqual(o1[key], o2[key])) {
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

# [2629. 复合函数](https://leetcode.cn/problems/function-composition){#2629}

{{< tabs "2629" >}}

{{% tab "ts" %}}
```ts
type F = (x: number) => number;

function compose(functions: F[]): F {
    return function (x) {
        return functions.reduceRight((acc, fn) => fn(acc), x);
    };
}

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>请你编写一个函数，它接收一个函数数组 <code>[f<sub>1</sub>, f<sub>2</sub>, f<sub>3</sub>，…， f<sub>n</sub>]</code> ，并返回一个新的函数 <code>fn</code>&nbsp;，它是函数数组的 <strong>复合函数</strong> 。</p>

<p><code>[f(x)， g(x)， h(x)]</code> 的 <strong>复合函数</strong> 为 <code>fn(x) = f(g(h(x)))</code>&nbsp;。</p>

<p>一个空函数列表的 <strong>复合函数</strong> 是 <strong>恒等函数</strong> <code>f(x) = x</code> 。</p>

<p>你可以假设数组中的每个函数接受一个整型参数作为输入，并返回一个整型作为输出。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>functions = [x =&gt; x + 1, x =&gt; x * x, x =&gt; 2 * x], x = 4
<b>输出：</b>65
<strong>解释：</strong>
从右向左计算......
Starting with x = 4.
2 * (4) = 8
(8) * (8) = 64
(64) + 1 = 65
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>functions = [x =&gt; 10 * x, x =&gt; 10 * x, x =&gt; 10 * x], x = 1
<b>输出：</b>1000
<strong>解释：</strong>
从右向左计算......
10 * (1) = 10
10 * (10) = 100
10 * (100) = 1000
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>functions = [], x = 42
<b>输出：</b>42
<strong>解释：</strong>
空函数列表的复合函数就是恒等函数</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code><font face="monospace">-1000 &lt;= x &lt;= 1000</font></code></li>
	<li><code><font face="monospace">0 &lt;= functions.length &lt;= 1000</font></code></li>
	<li><font face="monospace">所有函数都接受并返回一个整型</font></li>
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
type F = (x: number) => number;

function compose(functions: F[]): F {
    return function (x) {
        return functions.reduceRight((acc, fn) => fn(acc), x);
    };
}

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
