---
title: "2630_记忆函数 II"
date: 2025-10-08T18:39:28+08:00
weight: 4
tags: [JavaScript, 动态规划, 排序, 数学, 数组, 矩阵, 组合数学]
---

{{< markmap >}}
### [2630_记忆函数 II](#2630)
#### [JavaScript](#2630)
### [2631_分组](#2631)
#### [JavaScript](#2631)
### [2632_柯里化 🔒](#2632)
#### [JavaScript](#2632)
### [2633_将对象转换为 JSON 字符串 🔒](#2633)
#### [JavaScript](#2633)
### [2634_过滤数组中的元素](#2634)
#### [JavaScript](#2634)
### [2635_转换数组中的每个元素](#2635)
#### [JavaScript](#2635)
### [2636_Promise 对象池 🔒](#2636)
#### [JavaScript](#2636)
### [2637_有时间限制的 Promise 对象](#2637)
#### [JavaScript](#2637)
### [2638_统计 K-Free 子集的总数 🔒](#2638)
#### [数组](#2638)
#### [数学](#2638)
#### [动态规划](#2638)
#### [组合数学](#2638)
#### [排序](#2638)
### [2639_查询网格图中每一列的宽度](#2639)
#### [数组](#2639)
#### [矩阵](#2639)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2630_记忆函数 II
___
#### JavaScript
---
### 2631_分组
___
#### JavaScript
---
### 2632_柯里化 🔒
___
#### JavaScript
---
### 2633_将对象转换为 JSON 字符串 🔒
___
#### JavaScript
---
### 2634_过滤数组中的元素
___
#### JavaScript
---
### 2635_转换数组中的每个元素
___
#### JavaScript
---
### 2636_Promise 对象池 🔒
___
#### JavaScript
---
### 2637_有时间限制的 Promise 对象
___
#### JavaScript
---
### 2638_统计 K-Free 子集的总数 🔒
___
#### 数组
___
#### 数学
___
#### 动态规划
___
#### 组合数学
___
#### 排序
---
### 2639_查询网格图中每一列的宽度
___
#### 数组
___
#### 矩阵
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| JavaScript | 动态规划 | 排序 |
| 数学 | 数组 | 矩阵 |
| 组合数学 |  |  |

# [2630. 记忆函数 II](https://leetcode.cn/problems/memoize-ii){#2630}

{{< tabs "2630" >}}

{{% tab "ts" %}}
```ts
type Fn = (...params: any) => any;

function memoize(fn: Fn): Fn {
    const idxMap: Map<string, number> = new Map();
    const cache: Map<string, any> = new Map();

    const getIdx = (obj: any): number => {
        if (!idxMap.has(obj)) {
            idxMap.set(obj, idxMap.size);
        }
        return idxMap.get(obj)!;
    };

    return function (...params: any) {
        const key = params.map(getIdx).join(',');
        if (!cache.has(key)) {
            cache.set(key, fn(...params));
        }
        return cache.get(key)!;
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

<p>现给定一个函数 <code>fn</code> ，返回该函数的一个 <strong>记忆化</strong> 版本。</p>

<p>一个 <strong>记忆化</strong> 的函数是一个函数，它不会被相同的输入调用两次。而是会返回一个缓存的值。</p>

<p>函数 <code>fn</code> 可以是任何函数，对它所接受的值类型没有任何限制。如果两个输入值在 JavaScript 中使用 <code>===</code>&nbsp;运算符比较时相等，则它们被视为相同。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong> 
getInputs = () =&gt; [[2,2],[2,2],[1,2]]
fn = function (a, b) { return a + b; }
<b>输出：</b>[{"val":4,"calls":1},{"val":4,"calls":1},{"val":3,"calls":2}]
<strong>解释：</strong>
const inputs = getInputs();
const memoized = memoize(fn);
for (const arr of inputs) {
  memoized(...arr);
}

对于参数为 (2, 2) 的输入: 2 + 2 = 4，需要调用 fn() 。
对于参数为 (2, 2) 的输入: 2 + 2 = 4，这些输入之前已经出现过，因此不需要再次调用 fn()。
对于参数为 (1, 2) 的输入: 1 + 2 = 3，需要再次调用 fn()，总共调用了 2 次。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>
getInputs = () =&gt; [[{},{}],[{},{}],[{},{}]] 
fn = function (a, b) { return a + b; }
<b>输出：</b>[{"val":{},"calls":1},{"val":{},"calls":2},{"val":{},"calls":3}]
<strong>解释：</strong>
将两个空对象合并总是会得到一个空对象。尽管看起来应该缓存命中并只调用一次 <code>fn()</code>，但是这些空对象彼此之间都不是 <code>===</code> 相等的。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong> 
getInputs = () =&gt; { const o = {}; return [[o,o],[o,o],[o,o]]; }
fn = function (a, b) { return ({...a, ...b}); }
<b>输出：</b>[{"val":{},"calls":1},{"val":{},"calls":1},{"val":{},"calls":1}]
<strong>解释：</strong>
将两个空对象合并总是会得到一个空对象。因为传入的每个对象都是相同的，所以第二个和第三个函数调用都会命中缓存。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= inputs.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= inputs.flat().length &lt;= 10<sup>5</sup></code></li>
	<li><code>inputs[i][j] != NaN</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双哈希表

我们用两个哈希表，其中：

-   `idxMap` 用于记录每个参数对应的索引，索引从 $0$ 开始逐渐递增；
-   `cache` 用于记录每个函数参数调用的结果。

对于每个函数参数，我们将其转换为索引序列，然后将其转换为字符串作为 `cache` 的键，将函数调用的结果作为 `cache` 的值。每一次函数调用，我们都先判断 `cache` 中是否存在该键，如果存在，则直接返回对应的值，否则调用函数并将结果存入 `cache` 中。

时间复杂度 $O(1)$，空间复杂度 $O(n)$。其中 $n$ 为函数参数的个数。

<!-- tabs:start -->

#### TypeScript

```ts
type Fn = (...params: any) => any;

function memoize(fn: Fn): Fn {
    const idxMap: Map<string, number> = new Map();
    const cache: Map<string, any> = new Map();

    const getIdx = (obj: any): number => {
        if (!idxMap.has(obj)) {
            idxMap.set(obj, idxMap.size);
        }
        return idxMap.get(obj)!;
    };

    return function (...params: any) {
        const key = params.map(getIdx).join(',');
        if (!cache.has(key)) {
            cache.set(key, fn(...params));
        }
        return cache.get(key)!;
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

# [2631. 分组](https://leetcode.cn/problems/group-by){#2631}

{{< tabs "2631" >}}

{{% tab "ts" %}}
```ts
declare global {
    interface Array<T> {
        groupBy(fn: (item: T) => string): Record<string, T[]>;
    }
}

Array.prototype.groupBy = function (fn) {
    return this.reduce((acc, item) => {
        const key = fn(item);
        if (acc[key]) {
            acc[key].push(item);
        } else {
            acc[key] = [item];
        }
        return acc;
    }, {});
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>请你编写一段可应用于所有数组的代码，使任何数组调用 <code>array. groupBy(fn)</code> 方法时，它返回对该数组 <strong>分组后</strong> 的结果。</p>

<p>数组 <strong>分组</strong> 是一个对象，其中的每个键都是 <code>fn(arr[i])</code> 的输出的一个数组，该数组中含有原数组中具有该键的所有项。</p>

<p>提供的回调函数 <code>fn</code> 将接受数组中的项并返回一个字符串类型的键。</p>

<p>每个值列表的顺序应该与元素在数组中出现的顺序相同。任何顺序的键都是可以接受的。</p>

<p>请在不使用 lodash 的&nbsp;<code>_.groupBy</code> 函数的前提下解决这个问题。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>
array = [
&nbsp; {"id":"1"},
&nbsp; {"id":"1"},
&nbsp; {"id":"2"}
], 
fn = function (item) { 
&nbsp; return item.id; 
}
<b>输出：</b>
{ 
&nbsp; "1": [{"id": "1"}, {"id": "1"}], &nbsp; 
&nbsp; "2": [{"id": "2"}] 
}
<strong>解释：</strong>
输出来自函数 array.groupBy(fn)。
分组选择方法是从数组中的每个项中获取 "id" 。
有两个 "id" 为 1 的对象。所以将这两个对象都放在第一个数组中。
有一个 "id" 为 2 的对象。所以该对象被放到第二个数组中。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>
array = [
&nbsp; [1, 2, 3],
&nbsp; [1, 3, 5],
&nbsp; [1, 5, 9]
]
fn = function (list) { 
&nbsp; return String(list[0]); 
}
<b>输出：</b>
{ 
&nbsp; "1": [[1, 2, 3], [1, 3, 5], [1, 5, 9]] 
}
<strong>解释：</strong>
数组可以是任何类型的。在本例中，分组选择方法是将键定义为数组中的第一个元素。
所有数组的第一个元素都是1，所以它们被组合在一起。
{
  "1": [[1, 2, 3], [1, 3, 5], [1, 5, 9]]
}
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输出：</b>
array = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
fn = function (n) { 
&nbsp; return String(n &gt; 5);
}
<strong>输入：</strong>
{
&nbsp; "true": [6, 7, 8, 9, 10],
&nbsp; "false": [1, 2, 3, 4, 5]
}
<strong>解释：</strong>
分组选择方法是根据每个数字是否大于 5 来分割数组。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= array.length &lt;= 10<sup>5</sup></code></li>
	<li><code>fn 返回一个字符串</code></li>
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
declare global {
    interface Array<T> {
        groupBy(fn: (item: T) => string): Record<string, T[]>;
    }
}

Array.prototype.groupBy = function (fn) {
    return this.reduce((acc, item) => {
        const key = fn(item);
        if (acc[key]) {
            acc[key].push(item);
        } else {
            acc[key] = [item];
        }
        return acc;
    }, {});
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2632. 柯里化 🔒](https://leetcode.cn/problems/curry){#2632}

{{< tabs "2632" >}}

{{% tab "ts" %}}
```ts
function curry(fn: Function): Function {
    return function curried(...args) {
        if (args.length >= fn.length) {
            return fn(...args);
        }
        return (...nextArgs) => curried(...args, ...nextArgs);
    };
}

/**
 * function sum(a, b) { return a + b; }
 * const csum = curry(sum);
 * csum(1)(2) // 3
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>请你编写一个函数，它接收一个其他的函数，并返回该函数的&nbsp;<strong>柯里化&nbsp;</strong>后的形式。</p>

<p><strong>柯里化&nbsp;</strong>函数的定义是接受与原函数相同数量或更少数量的参数，并返回另一个 <strong>柯里化</strong> 后的函数或与原函数相同的值。</p>

<p>实际上，当你调用原函数，如 <code>sum(1,2,3)</code>&nbsp;时，它将调用 <strong>柯里化</strong> 函数的某个形式，如 <code>csum(1)(2)(3)</code>， <code>csum(1)(2,3)</code>， <code>csum(1,2)(3)</code>，或 <code>csum(1,2,3)</code> 。所有调用 <strong>柯里化</strong> 函数的方法都应该返回与原始函数相同的值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>
fn = function sum(a, b, c) { return a + b + c; }
inputs = [[1],[2],[3]]
<b>输出：</b>6
<strong>解释：</strong>
执行的代码是：
const curriedSum = curry(fn);
curriedSum(1)(2)(3) === 6;
curriedSum(1)(2)(3) 应该返回像原函数 sum(1, 2, 3) 一样的值。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>
fn = function sum(a, b, c) { return a + b + c; }
inputs = [[1,2],[3]]]
<b>输出：</b>6
<strong>解释：</strong>
curriedSum(1, 2)(3) 应该返回像原函数 sum(1, 2, 3) 一样的值。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>
fn = function sum(a, b, c) { return a + b + c; }
inputs = [[],[],[1,2,3]]
<b>输出：</b>6
<strong>解释：</strong>
你应该能够以任何方式传递参数，包括一次性传递所有参数或完全不传递参数。
curriedSum()()(1, 2, 3) 应该返回像原函数 sum(1, 2, 3) 一样的值。
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>
fn = function life() { return 42; }
inputs = [[]]
<b>输出：</b>42
<strong>解释：</strong>
柯里化一个没有接收参数，没做有效操作的函数。
curriedLife() === 42
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= inputs.length &lt;= 1000</code></li>
	<li><code>0 &lt;= inputs[i][j] &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= fn.length &lt;= 1000</code></li>
	<li><code>inputs.flat().length == fn.length</code></li>
	<li><code>函数参数需要被显式定义</code></li>
	<li>如果&nbsp;<code>fn.length &gt; 0</code>&nbsp;则最后一个数组&nbsp;<code>inputs</code>&nbsp;不为空</li>
	<li>如果&nbsp;<code>fn.length === 0</code>&nbsp;则&nbsp;<code>inputs.length === 1</code>&nbsp;</li>
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
function curry(fn: Function): Function {
    return function curried(...args) {
        if (args.length >= fn.length) {
            return fn(...args);
        }
        return (...nextArgs) => curried(...args, ...nextArgs);
    };
}

/**
 * function sum(a, b) { return a + b; }
 * const csum = curry(sum);
 * csum(1)(2) // 3
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2633. 将对象转换为 JSON 字符串 🔒](https://leetcode.cn/problems/convert-object-to-json-string){#2633}

{{< tabs "2633" >}}

{{% tab "ts" %}}
```ts
function jsonStringify(object: any): string {
    if (object === null) {
        return 'null';
    }
    if (typeof object === 'string') {
        return `"${object}"`;
    }
    if (typeof object === 'number' || typeof object === 'boolean') {
        return object.toString();
    }
    if (Array.isArray(object)) {
        return `[${object.map(jsonStringify).join(',')}]`;
    }
    if (typeof object === 'object') {
        return `{${Object.entries(object)
            .map(([key, value]) => `${jsonStringify(key)}:${jsonStringify(value)}`)
            .join(',')}}`;
    }
    return '';
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>现给定一个值，返回该值的有效 JSON 字符串。你可以假设这个值只包括字符串、整数、数组、对象、布尔值和 null。返回的字符串不能包含额外的空格。键的返回顺序应该与 <code>Object.keys()</code> 的顺序相同。</p>

<p>请你在不使用内置方法 <code>JSON.stringify</code> 的前提下解决这个问题。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>object = {"y":1,"x":2}
<strong>输出：</strong>{"y":1,"x":2}
<strong>解释：</strong>
返回该对象的 JSON 表示形式。
注意，键的返回顺序应该与 Object.keys() 的顺序相同。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>object = {"a":"str","b":-12,"c":true,"d":null}
<strong>输出：</strong>{"a":"str","b":-12,"c":true,"d":null}
<strong>解释：</strong>
JSON 的基本类型是字符串、数字型、布尔值和 null。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>object = {"key":{"a":1,"b":[{},null,"Hello"]}}
<strong>输出：</strong>{"key":{"a":1,"b":[{},null,"Hello"]}}
<strong>解释：</strong>
对象和数组可以包括其他对象和数组。
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>object = true
<strong>输出：</strong>true
<strong>解释：</strong>
基本类型是有效的输入</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>value</code>&nbsp;是一个有效的 JSON 值</li>
	<li><code>1 &lt;= JSON.stringify(object).length &lt;= 10<sup>5</sup></code></li>
	<li><code>maxNestingLevel &lt;= 1000</code></li>
	<li>所有字符串只包含字母数字字符</li>
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
function jsonStringify(object: any): string {
    if (object === null) {
        return 'null';
    }
    if (typeof object === 'string') {
        return `"${object}"`;
    }
    if (typeof object === 'number' || typeof object === 'boolean') {
        return object.toString();
    }
    if (Array.isArray(object)) {
        return `[${object.map(jsonStringify).join(',')}]`;
    }
    if (typeof object === 'object') {
        return `{${Object.entries(object)
            .map(([key, value]) => `${jsonStringify(key)}:${jsonStringify(value)}`)
            .join(',')}}`;
    }
    return '';
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2634. 过滤数组中的元素](https://leetcode.cn/problems/filter-elements-from-array){#2634}

{{< tabs "2634" >}}

{{% tab "ts" %}}
```ts
function filter(arr: number[], fn: (n: number, i: number) => any): number[] {
    const ans: number[] = [];
    for (let i = 0; i < arr.length; ++i) {
        if (fn(arr[i], i)) {
            ans.push(arr[i]);
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

<p>给定一个整数数组&nbsp;<code>arr</code> 和一个过滤函数 <code>fn</code>，并返回一个过滤后的数组 <code>filteredArr</code> 。</p>

<p><code>fn</code> 函数接受一个或两个参数：</p>

<ul>
	<li><code>arr[i]</code> - <code>arr</code> 中的数字</li>
	<li><code>i</code> - <code>arr[i]</code> 的索引</li>
</ul>

<p><code>filteredArr</code> 应该只包含使表达式 <code>fn(arr[i], i)</code> 的值为 <strong>真值</strong> 的 <code>arr</code> 中的元素。<strong>真值</strong> 是指 <code>Boolean(value)</code>&nbsp;返回参数为&nbsp;<code>true</code> 的值。</p>

<p>请在不使用内置的 <code>Array.filter</code> 方法的情况下解决该问题。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr = [0,10,20,30], fn = function greaterThan10(n) { return n &gt; 10; }
<b>输出：</b> [20,30]
<b>解释：</b>
const newArray = filter(arr, fn); // [20, 30]
过滤函数过滤掉不大于 10 的值</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>arr = [1,2,3], fn = function firstIndex(n, i) { return i === 0; }
<b>输出：</b>[1]
<strong>解释：</strong>
过滤函数 fn 也可以接受每个元素的索引
在这种情况下，过滤函数删除索引不为 0 的元素
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>arr = [-2,-1,0,1,2], fn = function plusOne(n) { return n + 1 }
<b>输出：</b>[-2,0,1,2]
<strong>解释：</strong>
像 0 这样的假值应被过滤掉
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= arr.length &lt;= 1000</code></li>
	<li><code><font face="monospace">-10<sup>9</sup>&nbsp;&lt;= arr[i] &lt;= 10<sup>9</sup></font></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：遍历

我们遍历数组 $arr$，对于每个元素 $arr[i]$，如果 $fn(arr[i], i)$ 为真，则将其加入答案数组中。最后返回答案数组即可。

时间复杂度 $O(n)$，其中 $n$ 为数组 $arr$ 的长度。忽略答案的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### TypeScript

```ts
function filter(arr: number[], fn: (n: number, i: number) => any): number[] {
    const ans: number[] = [];
    for (let i = 0; i < arr.length; ++i) {
        if (fn(arr[i], i)) {
            ans.push(arr[i]);
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

# [2635. 转换数组中的每个元素](https://leetcode.cn/problems/apply-transform-over-each-element-in-array){#2635}

{{< tabs "2635" >}}

{{% tab "ts" %}}
```ts
function map(arr: number[], fn: (n: number, i: number) => number): number[] {
    for (let i = 0; i < arr.length; ++i) {
        arr[i] = fn(arr[i], i);
    }
    return arr;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>编写一个函数，这个函数接收一个整数数组&nbsp;<code>arr</code> 和一个映射函数&nbsp; <code>fn</code>&nbsp;，通过该映射函数返回一个新的数组。</p>

<p>返回数组的创建语句应为 <code>returnedArray[i] = fn(arr[i], i)</code>&nbsp;。</p>

<p>请你在不使用内置方法&nbsp;<code>Array.map</code>&nbsp;的前提下解决这个问题。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>

<pre>
<strong>输入：</strong>arr = [1,2,3], fn = function plusone(n) { return n + 1; }
<strong>输出：</strong>[2,3,4]
<strong>解释： </strong>
const newArray = map(arr, plusone); // [2,3,4]
此映射函数返回值是将数组中每个元素的值加 1。
</pre>

<p><strong class="example">示例</strong><strong class="example"> 2:</strong></p>

<pre>
<strong>输入：</strong>arr = [1,2,3], fn = function plusI(n, i) { return n + i; }
<strong>输出：</strong>[1,3,5]
<strong>解释：</strong>此映射函数返回值根据输入数组索引增加每个值。
</pre>

<p><strong class="example">示例&nbsp;3:</strong></p>

<pre>
<strong>输入：</strong>arr = [10,20,30], fn = function constant() { return 42; }
<strong>输出：</strong>[42,42,42]
<strong>解释：</strong>此映射函数返回值恒为 42。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= arr.length &lt;= 1000</code></li>
	<li><code><font face="monospace">-10<sup>9</sup>&nbsp;&lt;= arr[i] &lt;= 10<sup>9</sup></font></code></li>
	<li><font face="monospace"><code>fn</code> 返回一个整数。</font></li>
</ul>
<span style="display:block"><span style="height:0px"><span style="position:absolute">​​​​​​</span></span></span>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：遍历

我们遍历数组 $arr$，对于每个元素 $arr[i]$，将其替换为 $fn(arr[i], i)$。最后返回数组 $arr$ 即可。

时间复杂度 $O(n)$，其中 $n$ 为数组 $arr$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### TypeScript

```ts
function map(arr: number[], fn: (n: number, i: number) => number): number[] {
    for (let i = 0; i < arr.length; ++i) {
        arr[i] = fn(arr[i], i);
    }
    return arr;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2636. Promise 对象池 🔒](https://leetcode.cn/problems/promise-pool){#2636}

{{< tabs "2636" >}}

{{% tab "ts" %}}
```ts
type F = () => Promise<any>;

function promisePool(functions: F[], n: number): Promise<any> {
    const wrappers = functions.map(fn => async () => {
        await fn();
        const nxt = waiting.shift();
        nxt && (await nxt());
    });

    const running = wrappers.slice(0, n);
    const waiting = wrappers.slice(n);
    return Promise.all(running.map(fn => fn()));
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>请你编写一个异步函数 <code>promisePool</code> ，它接收一个异步函数数组 <code>functions</code> 和 <strong>池限制</strong> <code>n</code>。它应该返回一个 promise 对象，当所有输入函数都执行完毕后，promise 对象就执行完毕。</p>

<p><strong>池限制</strong> 定义是一次可以挂起的最多 promise 对象的数量。<code>promisePool</code> 应该开始执行尽可能多的函数，并在旧的 promise 执行完毕后继续执行新函数。<code>promisePool</code> 应该先执行 <code>functions[i]</code>，再执行 <code>functions[i + 1]</code>，然后执行&nbsp;<code>functions[i + 2]</code>，等等。当最后一个 promise 执行完毕时，<code>promisePool</code> 也应该执行完毕。</p>

<p>例如，如果 <code>n = 1</code> , <code>promisePool</code>&nbsp;在序列中每次执行一个函数。然而，如果 <code>n = 2</code> ，它首先执行两个函数。当两个函数中的任何一个执行完毕后，再执行第三个函数(如果它是可用的)，依此类推，直到没有函数要执行为止。</p>

<p>你可以假设所有的 <code>functions</code> 都不会被拒绝。对于 <code>promisePool</code> 来说，返回一个可以解析任何值的 promise 都是可以接受的。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>
functions = [
&nbsp; () =&gt; new Promise(res =&gt; setTimeout(res, 300)),
&nbsp; () =&gt; new Promise(res =&gt; setTimeout(res, 400)),
&nbsp; () =&gt; new Promise(res =&gt; setTimeout(res, 200))
]
n = 2
<b>输出：</b>[[300,400,500],500]
<strong>解释</strong>
传递了三个函数。它们的睡眠时间分别为 300ms、 400ms 和 200ms。
在 t=0 时，执行前两个函数。池大小限制达到 2。
当 t=300 时，第一个函数执行完毕后，执行第3个函数。池大小为 2。
在 t=400 时，第二个函数执行完毕后。没有什么可执行的了。池大小为 1。
在 t=500 时，第三个函数执行完毕后。池大小为 0，因此返回的 promise 也执行完成。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：
</strong>functions = [
&nbsp; () =&gt; new Promise(res =&gt; setTimeout(res, 300)),
&nbsp; () =&gt; new Promise(res =&gt; setTimeout(res, 400)),
&nbsp; () =&gt; new Promise(res =&gt; setTimeout(res, 200))
]
n = 5
<b>输出：</b>[[300,400,200],400]
<strong>解释：</strong>
在 t=0 时，所有3个函数都被执行。池的限制大小 5 永远不会满足。
在 t=200 时，第三个函数执行完毕后。池大小为 2。
在 t=300 时，第一个函数执行完毕后。池大小为 1。
在 t=400 时，第二个函数执行完毕后。池大小为 0，因此返回的 promise 也执行完成。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>
functions = [
&nbsp; () =&gt; new Promise(res =&gt; setTimeout(res, 300)),
&nbsp; () =&gt; new Promise(res =&gt; setTimeout(res, 400)),
&nbsp; () =&gt; new Promise(res =&gt; setTimeout(res, 200))
]
n = 1
<b>输出：</b>[[300,700,900],900]
<strong>解释：</strong>
在 t=0 时，执行第一个函数。池大小为1。
当 t=300 时，第一个函数执行完毕后，执行第二个函数。池大小为 1。
当 t=700 时，第二个函数执行完毕后，执行第三个函数。池大小为 1。
在 t=900 时，第三个函数执行完毕后。池大小为 0，因此返回的 Promise 也执行完成。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= functions.length &lt;= 10</code></li>
	<li><code><font face="monospace">1 &lt;= n &lt;= 10</font></code></li>
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
type F = () => Promise<any>;

function promisePool(functions: F[], n: number): Promise<any> {
    const wrappers = functions.map(fn => async () => {
        await fn();
        const nxt = waiting.shift();
        nxt && (await nxt());
    });

    const running = wrappers.slice(0, n);
    const waiting = wrappers.slice(n);
    return Promise.all(running.map(fn => fn()));
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2637. 有时间限制的 Promise 对象](https://leetcode.cn/problems/promise-time-limit){#2637}

{{< tabs "2637" >}}

{{% tab "ts" %}}
```ts
type Fn = (...params: any[]) => Promise<any>;

function timeLimit(fn: Fn, t: number): Fn {
    return async function (...args) {
        return Promise.race([
            fn(...args),
            new Promise((_, reject) => setTimeout(() => reject('Time Limit Exceeded'), t)),
        ]);
    };
}

/**
 * const limited = timeLimit((t) => new Promise(res => setTimeout(res, t)), 100);
 * limited(150).catch(console.log) // "Time Limit Exceeded" at t=100ms
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>请你编写一个函数，它接受一个异步函数 <code>fn</code>&nbsp;和一个以毫秒为单位的时间 <code>t</code>。它应根据限时函数返回一个有 <strong>限时</strong> 效果的函数。函数 <code>fn</code> 接受提供给 <strong>限时</strong> 函数的参数。</p>

<p><strong>限时</strong> 函数应遵循以下规则：</p>

<ul>
	<li>如果 <code>fn</code> 在 <code>t</code> 毫秒的时间限制内完成，<strong>限时</strong> 函数应返回结果。</li>
	<li>如果 <code>fn</code> 的执行超过时间限制，<strong>限时&nbsp;</strong>函数应拒绝并返回字符串 <code>"Time Limit Exceeded"</code> 。</li>
</ul>

<p>&nbsp;</p>

<p><b>示例 1：</b></p>

<pre>
<strong>输入：</strong>
fn = async (n) =&gt; { 
&nbsp; await new Promise(res =&gt; setTimeout(res, 100)); 
&nbsp; return n * n; 
}
inputs = [5]
t = 50
<strong>输出：</strong>{"rejected":"Time Limit Exceeded","time":50}
<strong>解释：</strong>
const limited = timeLimit(fn, t)
const start = performance.now()
let result;
try {
&nbsp; &nbsp;const res = await limited(...inputs)
&nbsp; &nbsp;result = {"resolved": res, "time": Math.floor(performance.now() - start)};
} catch (err) {
&nbsp;  result = {"rejected": err, "time": Math.floor(performance.now() - start)};
}
console.log(result) // 输出结果
<b>
</b>提供的函数设置在 100ms 后执行完成，但是设置的超时时间为 50ms，所以在 t=50ms 时拒绝因为达到了超时时间。
</pre>

<p><b>示例 2：</b></p>

<pre>
<strong>输入：</strong>
fn = async (n) =&gt; { 
&nbsp; await new Promise(res =&gt; setTimeout(res, 100)); 
&nbsp; return n * n; 
}
inputs = [5]
t = 150
<strong>输出：</strong>{"resolved":25,"time":100}
<strong>解释：</strong>
在 t=100ms 时执行 5*5=25 ，没有达到超时时间。
</pre>

<p><b>示例 3：</b></p>

<pre>
<strong>输入：</strong>
fn = async (a, b) =&gt; { 
&nbsp; await new Promise(res =&gt; setTimeout(res, 120)); 
&nbsp; return a + b; 
}
inputs = [5,10]
t = 150
<strong>输出：</strong>{"resolved":15,"time":120}
<strong>解释：</strong><b>
</b>在 t=120ms 时执行 5+10=15，没有达到超时时间。
</pre>

<p><b>示例 4：</b></p>

<pre>
<strong>输入：</strong>
fn = async () =&gt; { 
&nbsp; throw "Error";
}
inputs = []
t = 1000
<strong>输出：</strong>{"rejected":"Error","time":0}
<strong>解释：</strong>
此函数始终丢出 Error</pre>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<ul>
	<li><code>0 &lt;= inputs.length &lt;= 10</code></li>
	<li><code>0 &lt;= t &lt;= 1000</code></li>
	<li><code>fn</code> 返回一个 Promise 对象</li>
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
type Fn = (...params: any[]) => Promise<any>;

function timeLimit(fn: Fn, t: number): Fn {
    return async function (...args) {
        return Promise.race([
            fn(...args),
            new Promise((_, reject) => setTimeout(() => reject('Time Limit Exceeded'), t)),
        ]);
    };
}

/**
 * const limited = timeLimit((t) => new Promise(res => setTimeout(res, t)), 100);
 * limited(150).catch(console.log) // "Time Limit Exceeded" at t=100ms
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2638. 统计 K-Free 子集的总数 🔒](https://leetcode.cn/problems/count-the-number-of-k-free-subsets){#2638}

{{< tabs "2638" >}}

{{% tab "python" %}}
```python
class Solution:
    def countTheNumOfKFreeSubsets(self, nums: List[int], k: int) -> int:
        nums.sort()
        g = defaultdict(list)
        for x in nums:
            g[x % k].append(x)
        ans = 1
        for arr in g.values():
            m = len(arr)
            f = [0] * (m + 1)
            f[0] = 1
            f[1] = 2
            for i in range(2, m + 1):
                if arr[i - 1] - arr[i - 2] == k:
                    f[i] = f[i - 1] + f[i - 2]
                else:
                    f[i] = f[i - 1] * 2
            ans *= f[m]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long countTheNumOfKFreeSubsets(int[] nums, int k) {
        Arrays.sort(nums);
        Map<Integer, List<Integer>> g = new HashMap<>();
        for (int i = 0; i < nums.length; ++i) {
            g.computeIfAbsent(nums[i] % k, x -> new ArrayList<>()).add(nums[i]);
        }
        long ans = 1;
        for (var arr : g.values()) {
            int m = arr.size();
            long[] f = new long[m + 1];
            f[0] = 1;
            f[1] = 2;
            for (int i = 2; i <= m; ++i) {
                if (arr.get(i - 1) - arr.get(i - 2) == k) {
                    f[i] = f[i - 1] + f[i - 2];
                } else {
                    f[i] = f[i - 1] * 2;
                }
            }
            ans *= f[m];
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
    long long countTheNumOfKFreeSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        unordered_map<int, vector<int>> g;
        for (int i = 0; i < nums.size(); ++i) {
            g[nums[i] % k].push_back(nums[i]);
        }
        long long ans = 1;
        for (auto& [_, arr] : g) {
            int m = arr.size();
            long long f[m + 1];
            f[0] = 1;
            f[1] = 2;
            for (int i = 2; i <= m; ++i) {
                if (arr[i - 1] - arr[i - 2] == k) {
                    f[i] = f[i - 1] + f[i - 2];
                } else {
                    f[i] = f[i - 1] * 2;
                }
            }
            ans *= f[m];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countTheNumOfKFreeSubsets(nums []int, k int) int64 {
	sort.Ints(nums)
	g := map[int][]int{}
	for _, x := range nums {
		g[x%k] = append(g[x%k], x)
	}
	ans := int64(1)
	for _, arr := range g {
		m := len(arr)
		f := make([]int64, m+1)
		f[0] = 1
		f[1] = 2
		for i := 2; i <= m; i++ {
			if arr[i-1]-arr[i-2] == k {
				f[i] = f[i-1] + f[i-2]
			} else {
				f[i] = f[i-1] * 2
			}
		}
		ans *= f[m]
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countTheNumOfKFreeSubsets(nums: number[], k: number): number {
    nums.sort((a, b) => a - b);
    const g: Map<number, number[]> = new Map();
    for (const x of nums) {
        const y = x % k;
        if (!g.has(y)) {
            g.set(y, []);
        }
        g.get(y)!.push(x);
    }
    let ans: number = 1;
    for (const [_, arr] of g) {
        const m = arr.length;
        const f: number[] = new Array(m + 1).fill(1);
        f[1] = 2;
        for (let i = 2; i <= m; ++i) {
            if (arr[i - 1] - arr[i - 2] === k) {
                f[i] = f[i - 1] + f[i - 2];
            } else {
                f[i] = f[i - 1] * 2;
            }
        }
        ans *= f[m];
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

<p>给定一个包含 <strong>无重复</strong> 元素的整数数组 <code>nums</code> 和一个整数 <code>k</code> 。</p>

<p>如果一个子集中 <strong>不</strong> 存在两个差的绝对值等于 <code>k</code> 的元素，则称其为 <strong>k-Free</strong> 子集。注意，空集是一个 <strong>k-Free</strong> 子集。</p>

<p>返回 <code>nums</code> 中 <strong>k-Free</strong> 子集的数量。</p>

<p>一个数组的 <strong>子集</strong> 是该数组中的元素的选择（可能为零个）。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1 ：</strong></p>

<pre>
<b>输入：</b>nums = [5,4,6], k = 1
<b>输出：</b>5
<b>解释：</b>有 5 个合法子集：{}, {5}, {4}, {6} 和 {4, 6} 。
</pre>

<p><strong class="example">示例 2 ：</strong></p>

<pre>
<b>输入：</b>nums = [2,3,5,8], k = 5
<b>输出：</b>12
<b>解释：</b>有12个合法子集：{}, {2}, {3}, {5}, {8}, {2, 3}, {2, 3, 5}, {2, 5}, {2, 5, 8}, {2, 8}, {3, 5} 和 {5, 8} 。
</pre>

<p><strong class="example">示例 3 ：</strong></p>

<pre>
<b>输入：</b>nums = [10,5,9,11], k = 20
<b>输出：</b>16
<b>解释：</b>所有的子集都是有效的。由于子集的总数为 2^4 = 16，因此答案为 16 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 50</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 1000</code></li>
	<li><code>1 &lt;= k &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分组 + 动态规划

我们先将数组 $nums$ 按照升序排序，然后将数组中的元素按照模 $k$ 分组，即 $nums[i] \bmod k$ 相同的元素放在同一组中。那么对于任意两个不同组的元素，它们的差值的绝对值一定不等于 $k$。因此，我们可以求出每一组的子集个数，然后将每一组的子集个数相乘即可得到答案。

对于每一组 $arr$，我们可以使用动态规划求出子集个数。设 $f[i]$ 表示前 $i$ 个元素的子集个数，初始时 $f[0] = 1$，而 $f[1]=2$。当 $i \geq 2$ 时，如果 $arr[i-1]-arr[i-2]=k$，如果我们选择 $arr[i-1]$，那么 $f[i]=f[i-2]$；如果我们不选择 $arr[i-1]$，那么 $f[i]=f[i-1]$。因此，当 $arr[i-1]-arr[i-2]=k$ 时，有 $f[i]=f[i-1]+f[i-2]$；否则 $f[i] = f[i - 1] \times 2$。这一组的子集个数即为 $f[m]$，其中 $m$ 为数组 $arr$ 的长度。

最后，我们将每一组的子集个数相乘即可得到答案。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countTheNumOfKFreeSubsets(self, nums: List[int], k: int) -> int:
        nums.sort()
        g = defaultdict(list)
        for x in nums:
            g[x % k].append(x)
        ans = 1
        for arr in g.values():
            m = len(arr)
            f = [0] * (m + 1)
            f[0] = 1
            f[1] = 2
            for i in range(2, m + 1):
                if arr[i - 1] - arr[i - 2] == k:
                    f[i] = f[i - 1] + f[i - 2]
                else:
                    f[i] = f[i - 1] * 2
            ans *= f[m]
        return ans
```

#### Java

```java
class Solution {
    public long countTheNumOfKFreeSubsets(int[] nums, int k) {
        Arrays.sort(nums);
        Map<Integer, List<Integer>> g = new HashMap<>();
        for (int i = 0; i < nums.length; ++i) {
            g.computeIfAbsent(nums[i] % k, x -> new ArrayList<>()).add(nums[i]);
        }
        long ans = 1;
        for (var arr : g.values()) {
            int m = arr.size();
            long[] f = new long[m + 1];
            f[0] = 1;
            f[1] = 2;
            for (int i = 2; i <= m; ++i) {
                if (arr.get(i - 1) - arr.get(i - 2) == k) {
                    f[i] = f[i - 1] + f[i - 2];
                } else {
                    f[i] = f[i - 1] * 2;
                }
            }
            ans *= f[m];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long countTheNumOfKFreeSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        unordered_map<int, vector<int>> g;
        for (int i = 0; i < nums.size(); ++i) {
            g[nums[i] % k].push_back(nums[i]);
        }
        long long ans = 1;
        for (auto& [_, arr] : g) {
            int m = arr.size();
            long long f[m + 1];
            f[0] = 1;
            f[1] = 2;
            for (int i = 2; i <= m; ++i) {
                if (arr[i - 1] - arr[i - 2] == k) {
                    f[i] = f[i - 1] + f[i - 2];
                } else {
                    f[i] = f[i - 1] * 2;
                }
            }
            ans *= f[m];
        }
        return ans;
    }
};
```

#### Go

```go
func countTheNumOfKFreeSubsets(nums []int, k int) int64 {
	sort.Ints(nums)
	g := map[int][]int{}
	for _, x := range nums {
		g[x%k] = append(g[x%k], x)
	}
	ans := int64(1)
	for _, arr := range g {
		m := len(arr)
		f := make([]int64, m+1)
		f[0] = 1
		f[1] = 2
		for i := 2; i <= m; i++ {
			if arr[i-1]-arr[i-2] == k {
				f[i] = f[i-1] + f[i-2]
			} else {
				f[i] = f[i-1] * 2
			}
		}
		ans *= f[m]
	}
	return ans
}
```

#### TypeScript

```ts
function countTheNumOfKFreeSubsets(nums: number[], k: number): number {
    nums.sort((a, b) => a - b);
    const g: Map<number, number[]> = new Map();
    for (const x of nums) {
        const y = x % k;
        if (!g.has(y)) {
            g.set(y, []);
        }
        g.get(y)!.push(x);
    }
    let ans: number = 1;
    for (const [_, arr] of g) {
        const m = arr.length;
        const f: number[] = new Array(m + 1).fill(1);
        f[1] = 2;
        for (let i = 2; i <= m; ++i) {
            if (arr[i - 1] - arr[i - 2] === k) {
                f[i] = f[i - 1] + f[i - 2];
            } else {
                f[i] = f[i - 1] * 2;
            }
        }
        ans *= f[m];
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2639. 查询网格图中每一列的宽度](https://leetcode.cn/problems/find-the-width-of-columns-of-a-grid){#2639}

{{< tabs "2639" >}}

{{% tab "python" %}}
```python
class Solution:
    def findColumnWidth(self, grid: List[List[int]]) -> List[int]:
        return [max(len(str(x)) for x in col) for col in zip(*grid)]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] findColumnWidth(int[][] grid) {
        int n = grid[0].length;
        int[] ans = new int[n];
        for (var row : grid) {
            for (int j = 0; j < n; ++j) {
                int w = String.valueOf(row[j]).length();
                ans[j] = Math.max(ans[j], w);
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
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<int> ans(n);
        for (auto& row : grid) {
            for (int j = 0; j < n; ++j) {
                int w = to_string(row[j]).size();
                ans[j] = max(ans[j], w);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findColumnWidth(grid [][]int) []int {
	ans := make([]int, len(grid[0]))
	for _, row := range grid {
		for j, x := range row {
			w := len(strconv.Itoa(x))
			ans[j] = max(ans[j], w)
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findColumnWidth(grid: number[][]): number[] {
    const n = grid[0].length;
    const ans: number[] = new Array(n).fill(0);
    for (const row of grid) {
        for (let j = 0; j < n; ++j) {
            const w: number = String(row[j]).length;
            ans[j] = Math.max(ans[j], w);
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn find_column_width(grid: Vec<Vec<i32>>) -> Vec<i32> {
        let mut ans = vec![0; grid[0].len()];

        for row in grid.iter() {
            for (j, num) in row.iter().enumerate() {
                let width = num.to_string().len() as i32;
                ans[j] = std::cmp::max(ans[j], width);
            }
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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的&nbsp;<code>m x n</code>&nbsp;整数矩阵&nbsp;<code>grid</code>&nbsp;。矩阵中某一列的宽度是这一列数字的最大 <strong>字符串长度</strong>&nbsp;。</p>

<ul>
	<li>比方说，如果&nbsp;<code>grid = [[-10], [3], [12]]</code>&nbsp;，那么唯一一列的宽度是&nbsp;<code>3</code>&nbsp;，因为&nbsp;<code>-10</code>&nbsp;的字符串长度为&nbsp;<code>3</code>&nbsp;。</li>
</ul>

<p>请你返回一个大小为 <code>n</code>&nbsp;的整数数组&nbsp;<code>ans</code>&nbsp;，其中&nbsp;<code>ans[i]</code>&nbsp;是第&nbsp;<code>i</code>&nbsp;列的宽度。</p>

<p>一个有 <code>len</code>&nbsp;个数位的整数 <code>x</code>&nbsp;，如果是非负数，那么&nbsp;<strong>字符串</strong><strong>长度</strong>&nbsp;为&nbsp;<code>len</code>&nbsp;，否则为&nbsp;<code>len + 1</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>grid = [[1],[22],[333]]
<b>输出：</b>[3]
<b>解释：</b>第 0 列中，333 字符串长度为 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>grid = [[-15,1,3],[15,7,12],[5,6,-2]]
<b>输出：</b>[3,1,2]
<b>解释：</b>
第 0 列中，只有 -15 字符串长度为 3 。
第 1 列中，所有整数的字符串长度都是 1 。
第 2 列中，12 和 -2 的字符串长度都为 2 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 100 </code></li>
	<li><code>-10<sup>9</sup> &lt;= grid[r][c] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们记矩阵的列数为 $n$，创建一个长度为 $n$ 的数组 $ans$，其中 $ans[i]$ 表示第 $i$ 列的宽度。初始时 $ans[i] = 0$。

遍历矩阵中的每一行，对于每一行中的每个元素，计算其字符串长度 $w$，并更新 $ans[j]$ 的值为 $\max(ans[j], w)$。

遍历完所有行后，数组 $ans$ 中的每个元素即为对应列的宽度。

时间复杂度 $O(m \times n)$，空间复杂度 $O(\log M)$。其中 $m$ 和 $n$ 分别为矩阵的行数和列数，而 $M$ 为矩阵中的最大元素绝对值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findColumnWidth(self, grid: List[List[int]]) -> List[int]:
        return [max(len(str(x)) for x in col) for col in zip(*grid)]
```

#### Java

```java
class Solution {
    public int[] findColumnWidth(int[][] grid) {
        int n = grid[0].length;
        int[] ans = new int[n];
        for (var row : grid) {
            for (int j = 0; j < n; ++j) {
                int w = String.valueOf(row[j]).length();
                ans[j] = Math.max(ans[j], w);
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
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<int> ans(n);
        for (auto& row : grid) {
            for (int j = 0; j < n; ++j) {
                int w = to_string(row[j]).size();
                ans[j] = max(ans[j], w);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findColumnWidth(grid [][]int) []int {
	ans := make([]int, len(grid[0]))
	for _, row := range grid {
		for j, x := range row {
			w := len(strconv.Itoa(x))
			ans[j] = max(ans[j], w)
		}
	}
	return ans
}
```

#### TypeScript

```ts
function findColumnWidth(grid: number[][]): number[] {
    const n = grid[0].length;
    const ans: number[] = new Array(n).fill(0);
    for (const row of grid) {
        for (let j = 0; j < n; ++j) {
            const w: number = String(row[j]).length;
            ans[j] = Math.max(ans[j], w);
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn find_column_width(grid: Vec<Vec<i32>>) -> Vec<i32> {
        let mut ans = vec![0; grid[0].len()];

        for row in grid.iter() {
            for (j, num) in row.iter().enumerate() {
                let width = num.to_string().len() as i32;
                ans[j] = std::cmp::max(ans[j], width);
            }
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
