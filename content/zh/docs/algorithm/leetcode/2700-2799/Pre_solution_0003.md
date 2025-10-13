---
title: "2720_受欢迎度百分比 🔒"
date: 2025-10-08T18:39:33+08:00
weight: 3
tags: [JavaScript, 交互, 哈希表, 数学, 数据库, 数组]
---

{{< markmap >}}
### [2720_受欢迎度百分比 🔒](#2720)
#### [数据库](#2720)
### [2721_并行执行异步函数](#2721)
#### [JavaScript](#2721)
### [2722_根据 ID 合并两个数组](#2722)
#### [JavaScript](#2722)
### [2723_两个 Promise 对象相加](#2723)
#### [JavaScript](#2723)
### [2724_排序方式](#2724)
#### [JavaScript](#2724)
### [2725_间隔取消](#2725)
#### [JavaScript](#2725)
### [2726_使用方法链的计算器](#2726)
#### [JavaScript](#2726)
### [2727_判断对象是否为空](#2727)
#### [JavaScript](#2727)
### [2728_计算一个环形街道上的房屋数量 🔒](#2728)
#### [数组](#2728)
#### [交互](#2728)
### [2729_判断一个数是否迷人](#2729)
#### [哈希表](#2729)
#### [数学](#2729)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2720_受欢迎度百分比 🔒
___
#### 数据库
---
### 2721_并行执行异步函数
___
#### JavaScript
---
### 2722_根据 ID 合并两个数组
___
#### JavaScript
---
### 2723_两个 Promise 对象相加
___
#### JavaScript
---
### 2724_排序方式
___
#### JavaScript
---
### 2725_间隔取消
___
#### JavaScript
---
### 2726_使用方法链的计算器
___
#### JavaScript
---
### 2727_判断对象是否为空
___
#### JavaScript
---
### 2728_计算一个环形街道上的房屋数量 🔒
___
#### 数组
___
#### 交互
---
### 2729_判断一个数是否迷人
___
#### 哈希表
___
#### 数学
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| JavaScript | 交互 | 哈希表 |
| 数学 | 数据库 | 数组 |

# [2720. 受欢迎度百分比 🔒](https://leetcode.cn/problems/popularity-percentage){#2720}

{{< tabs "2720" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    F AS (
        SELECT * FROM Friends
        UNION
        SELECT user2, user1 FROM Friends
    ),
    T AS (SELECT COUNT(DISTINCT user1) AS cnt FROM F)
SELECT DISTINCT
    user1,
    ROUND(
        (COUNT(1) OVER (PARTITION BY user1)) * 100 / (SELECT cnt FROM T),
        2
    ) AS percentage_popularity
FROM F
ORDER BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Friends</code></p>

<pre>
+-------------+------+
| 列名        | 类型  |
+-------------+------+
| user1       | int  |
| user2       | int  |
+-------------+------+
(user1, user2) 是该表的主键(具有唯一值的列)。 
每一行包含关于朋友关系的信息，其中 user1 和 user2 是朋友。 
</pre>

<p>编写一条 SQL 查询，找出 Meta/Facebook 平台上每个用户的受欢迎度的百分比。受欢迎度百分比定义为用户拥有的朋友总数除以平台上的总用户数，然后乘以 100，并&nbsp;<strong>四舍五入保留 2 位小数&nbsp;</strong>。</p>

<p>返回按照 <code>user1</code> <strong>升序</strong> 排序的结果表。</p>

<p>查询结果格式如下示例所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>&nbsp;
Friends 表:
+-------+-------+
| user1 | user2 | 
+-------+-------+
| 2 &nbsp; &nbsp; | 1 &nbsp; &nbsp; | 
| 1 &nbsp; &nbsp; | 3 &nbsp; &nbsp; | 
| 4 &nbsp; &nbsp; | 1 &nbsp; &nbsp; | 
| 1 &nbsp; &nbsp; | 5 &nbsp; &nbsp; | 
| 1 &nbsp; &nbsp; | 6 &nbsp; &nbsp; |
| 2 &nbsp; &nbsp; | 6 &nbsp; &nbsp; | 
| 7 &nbsp; &nbsp; | 2 &nbsp; &nbsp; | 
| 8 &nbsp; &nbsp; | 3&nbsp; &nbsp; &nbsp;| 
| 3 &nbsp; &nbsp; | 9 &nbsp; &nbsp; |  
+-------+-------+
<b>输出：</b>
+-------+-----------------------+
| user1 | percentage_popularity |
+-------+-----------------------+
| 1     | 55.56 &nbsp;  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|
| 2     | 33.33 &nbsp;  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|
| 3     | 33.33   &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; |
| 4     | 11.11 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; |
| 5     | 11.11 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; |
| 6     | 22.22 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; |
| 7     | 11.11 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; |
| 8     | 11.11 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; |
| 9     | 11.11 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; |
+-------+-----------------------+
<b>解释：</b>
平台上总共有 9 个用户。
- 用户 "1" 与 2、3、4、5 和 6 是朋友。因此，用户 1 的受欢迎度百分比计算为（5/9）* 100 = 55.56。
- 用户 "2" 与 1、6 和 7 是朋友。因此，用户 2 的受欢迎度百分比计算为（3/9）* 100 = 33.33。
- 用户 "3" 与 1、8 和 9 是朋友。因此，用户 3 的受欢迎度百分比计算为（3/9）* 100 = 33.33。
- 用户 "4" 与 1 是朋友。因此，用户 4 的受欢迎度百分比计算为（1/9）* 100 = 11.11。
- 用户 "5" 与 1 是朋友。因此，用户 5 的受欢迎度百分比计算为（1/9）* 100 = 11.11。
- 用户 "6" 与 1 和 2 是朋友。因此，用户 6 的受欢迎度百分比计算为（2/9）* 100 = 22.22。
- 用户 "7" 与 2 是朋友。因此，用户 7 的受欢迎度百分比计算为（1/9）* 100 = 11.11。
- 用户 "8" 与 3 是朋友。因此，用户 8 的受欢迎度百分比计算为（1/9）* 100 = 11.11。
- 用户 "9" 与 3 是朋友。因此，用户 9 的受欢迎度百分比计算为（1/9）* 100 = 11.11。 
user1 按升序排序。</pre>

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
WITH
    F AS (
        SELECT * FROM Friends
        UNION
        SELECT user2, user1 FROM Friends
    ),
    T AS (SELECT COUNT(DISTINCT user1) AS cnt FROM F)
SELECT DISTINCT
    user1,
    ROUND(
        (COUNT(1) OVER (PARTITION BY user1)) * 100 / (SELECT cnt FROM T),
        2
    ) AS percentage_popularity
FROM F
ORDER BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2721. 并行执行异步函数](https://leetcode.cn/problems/execute-asynchronous-functions-in-parallel){#2721}

{{< tabs "2721" >}}

{{% tab "ts" %}}
```ts
async function promiseAll<T>(functions: (() => Promise<T>)[]): Promise<T[]> {
    return new Promise<T[]>((resolve, reject) => {
        let cnt = 0;
        const ans = new Array(functions.length);
        for (let i = 0; i < functions.length; ++i) {
            const f = functions[i];
            f()
                .then(res => {
                    ans[i] = res;
                    cnt++;
                    if (cnt === functions.length) {
                        resolve(ans);
                    }
                })
                .catch(err => {
                    reject(err);
                });
        }
    });
}

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个异步函数数组 <code>functions</code>，返回一个新的 promise 对象&nbsp;<code>promise</code>。数组中的每个函数都不接受参数并返回一个 promise。所有的 promise 都应该并行执行。</p>

<p><code>promise</code> resolve 条件：</p>

<ul>
	<li>当所有从 <code>functions</code> 返回的 promise 都成功的并行解析时。<code>promise</code> 的解析值应该是一个按照它们在 <code>functions</code> 中的顺序排列的 promise 的解析值数组。<code>promise</code> 应该在数组中的所有异步函数并行执行完成时解析。</li>
</ul>

<p><code>promise</code>&nbsp;reject 条件：</p>

<ul>
	<li>当任何从 <code>functions</code> 返回的 promise 被拒绝时。<code>promise</code> 也会被拒绝，并返回第一个拒绝的原因。</li>
</ul>

<p>请在不使用内置的 <code>Promise.all</code> 函数的情况下解决。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>functions = [
&nbsp; () =&gt; new Promise(resolve =&gt; setTimeout(() =&gt; resolve(5), 200))
]
<b>输出：</b>{"t": 200, "resolved": [5]}
<b>解释：</b>
promiseAll(functions).then(console.log); // [5]

单个函数在 200 毫秒后以值 5 成功解析。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>functions = [
    () =&gt; new Promise(resolve =&gt; setTimeout(() =&gt; resolve(1), 200)), 
    () =&gt; new Promise((resolve, reject) =&gt; setTimeout(() =&gt; reject("Error"), 100))
]
<b>输出：</b>{"t": 100, "rejected": "Error"}
<b>解释：</b>由于其中一个 promise 被拒绝，返回的 promise 也在同一时间被拒绝并返回相同的错误。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>functions = [
    () =&gt; new Promise(resolve =&gt; setTimeout(() =&gt; resolve(4), 50)), 
    () =&gt; new Promise(resolve =&gt; setTimeout(() =&gt; resolve(10), 150)), 
    () =&gt; new Promise(resolve =&gt; setTimeout(() =&gt; resolve(16), 100))
]
<b>输出：</b>{"t": 150, "resolved": [4, 10, 16]}
<b>解释：</b>所有的 promise 都成功执行。当最后一个 promise 被解析时，返回的 promise 也被解析了。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>函数 <code>functions</code> 是一个返回 promise 的函数数组</li>
	<li><code>1 &lt;= functions.length &lt;= 10</code></li>
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
async function promiseAll<T>(functions: (() => Promise<T>)[]): Promise<T[]> {
    return new Promise<T[]>((resolve, reject) => {
        let cnt = 0;
        const ans = new Array(functions.length);
        for (let i = 0; i < functions.length; ++i) {
            const f = functions[i];
            f()
                .then(res => {
                    ans[i] = res;
                    cnt++;
                    if (cnt === functions.length) {
                        resolve(ans);
                    }
                })
                .catch(err => {
                    reject(err);
                });
        }
    });
}

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2722. 根据 ID 合并两个数组](https://leetcode.cn/problems/join-two-arrays-by-id){#2722}

{{< tabs "2722" >}}

{{% tab "ts" %}}
```ts
function join(arr1: ArrayType[], arr2: ArrayType[]): ArrayType[] {
    const r = (acc: Obj, x: ArrayType): Obj => ((acc[x.id] = x), acc);
    const d = arr1.reduce(r, {});

    arr2.forEach(x => {
        if (d[x.id]) {
            Object.assign(d[x.id], x);
        } else {
            d[x.id] = x;
        }
    });
    return Object.values(d);
}

type JSONValue = null | boolean | number | string | JSONValue[] | { [key: string]: JSONValue };
type ArrayType = { id: number } & Record<string, JSONValue>;

type Obj = Record<number, ArrayType>;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>现给定两个数组 <code>arr1</code> 和 <code>arr2</code> ，返回一个新的数组 <code>joinedArray</code> 。两个输入数组中的每个对象都包含一个 <code>id</code> 字段。</p>

<p><code>joinedArray</code> 是一个通过 <code>id</code> 将 <code>arr1</code> 和 <code>arr2</code> 连接而成的数组。<code>joinedArray</code> 的长度应为唯一值 <code>id</code> 的长度。返回的数组应按 <code>id</code> <strong>升序</strong> 排序。</p>

<p>如果一个 <code>id</code> 存在于一个数组中但不存在于另一个数组中，则该对象应包含在结果数组中且不进行修改。</p>

<p>如果两个对象共享一个 <code>id</code> ，则它们的属性应进行合并：</p>

<ul>
	<li>如果一个键只存在于一个对象中，则该键值对应该包含在对象中。</li>
	<li>如果一个键在两个对象中都包含，则 <code>arr2</code> 中的值应覆盖 <code>arr1</code> 中的值。</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>
arr1 = [
&nbsp;   {"id": 1, "x": 1},
&nbsp;   {"id": 2, "x": 9}
], 
arr2 = [
    {"id": 3, "x": 5}
]
<b>输出：</b>
[
&nbsp;   {"id": 1, "x": 1},
&nbsp;   {"id": 2, "x": 9},
    {"id": 3, "x": 5}
]
<b>解释：</b>没有共同的 id，因此将 arr1 与 arr2 简单地连接起来。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>
arr1 = [
    {"id": 1, "x": 2, "y": 3},
    {"id": 2, "x": 3, "y": 6}
], 
arr2 = [
    {"id": 2, "x": 10, "y": 20},
    {"id": 3, "x": 0, "y": 0}
]
<b>输出：</b>
[
    {"id": 1, "x": 2, "y": 3},
    {"id": 2, "x": 10, "y": 20},
&nbsp;   {"id": 3, "x": 0, "y": 0}
]
<b>解释：</b>id 为 1 和 id 为 3 的对象在结果数组中保持不变。id 为 2 的两个对象合并在一起。arr2 中的键覆盖 arr1 中的值。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>
arr1 = [
    {"id": 1, "b": {"b": 94},"v": [4, 3], "y": 48}
]
arr2 = [
    {"id": 1, "b": {"c": 84}, "v": [1, 3]}
]
<strong>输出：</strong> [
    {"id": 1, "b": {"c": 84}, "v": [1, 3], "y": 48}
]
<b>解释：</b>具有 id 为 1 的对象合并在一起。对于键 "b" 和 "v" ，使用 arr2 中的值。由于键 "y" 只存在于 arr1 中，因此取 arr1 的值。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>arr1 和 arr2 都是有效的 JSON 数组</code></li>
	<li><code>在 arr1 和 arr2 中都有唯一的键值 id</code></li>
	<li><code>2 &lt;= JSON.stringify(arr1).length &lt;= 10<sup>6</sup></code></li>
	<li><code>2 &lt;= JSON.stringify(arr2).length &lt;= 10<sup>6</sup></code></li>
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
function join(arr1: ArrayType[], arr2: ArrayType[]): ArrayType[] {
    const r = (acc: Obj, x: ArrayType): Obj => ((acc[x.id] = x), acc);
    const d = arr1.reduce(r, {});

    arr2.forEach(x => {
        if (d[x.id]) {
            Object.assign(d[x.id], x);
        } else {
            d[x.id] = x;
        }
    });
    return Object.values(d);
}

type JSONValue = null | boolean | number | string | JSONValue[] | { [key: string]: JSONValue };
type ArrayType = { id: number } & Record<string, JSONValue>;

type Obj = Record<number, ArrayType>;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2723. 两个 Promise 对象相加](https://leetcode.cn/problems/add-two-promises){#2723}

{{< tabs "2723" >}}

{{% tab "ts" %}}
```ts
async function addTwoPromises(
    promise1: Promise<number>,
    promise2: Promise<number>,
): Promise<number> {
    return (await promise1) + (await promise2);
}

/**
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */
```
{{% /tab %}}
{{% tab "js" %}}
```js
var addTwoPromises = async function (promise1, promise2) {
    return (await promise1) + (await promise2);
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

给定两个 promise 对象&nbsp;<code>promise1</code> 和 <code>promise2</code>，返回一个新的 promise。<code>promise1</code> 和 <code>promise2</code> 都会被解析为一个数字。返回的 Promise 应该解析为这两个数字的和。

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>
promise1 = new Promise(resolve =&gt; setTimeout(() =&gt; resolve(2), 20)), 
promise2 = new Promise(resolve =&gt; setTimeout(() =&gt; resolve(5), 60))
<b>输出：</b>7
<b>解释：</b>两个输入的 Promise 分别解析为值 2 和 5。返回的 Promise 应该解析为 2 + 5 = 7。返回的 Promise 解析的时间不作为判断条件。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>
promise1 = new Promise(resolve =&gt; setTimeout(() =&gt; resolve(10), 50)), 
promise2 = new Promise(resolve =&gt; setTimeout(() =&gt; resolve(-12), 30))
<b>输出：</b>-2
<b>解释：</b>两个输入的 Promise 分别解析为值 10 和 -12。返回的 Promise 应该解析为 10 + -12 = -2。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>promise1 和 promise2</code> 都是被解析为一个数字的 promise 对象</li>
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
async function addTwoPromises(
    promise1: Promise<number>,
    promise2: Promise<number>,
): Promise<number> {
    return (await promise1) + (await promise2);
}

/**
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */
```

#### JavaScript

```js
var addTwoPromises = async function (promise1, promise2) {
    return (await promise1) + (await promise2);
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2724. 排序方式](https://leetcode.cn/problems/sort-by){#2724}

{{< tabs "2724" >}}

{{% tab "ts" %}}
```ts
function sortBy(arr: any[], fn: Function): any[] {
    return arr.sort((a, b) => fn(a) - fn(b));
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个数组 <code>arr</code> 和一个函数 <code>fn</code>，返回一个排序后的数组 <code>sortedArr</code>。你可以假设 <code>fn</code> 只返回数字，并且这些数字决定了 <code>sortedArr</code> 的排序顺序。<code>sortedArr</code> 必须按照 <code>fn</code> 的输出值&nbsp;<strong>升序</strong> 排序。</p>

<p>你可以假设对于给定的数组，<code>fn</code> 不会返回重复的数字。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>arr = [5, 4, 1, 2, 3], fn = (x) =&gt; x
<b>输出：</b>[1, 2, 3, 4, 5]
<b>解释：</b>fn 只是返回传入的数字，因此数组按升序排序。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>arr = [{"x": 1}, {"x": 0}, {"x": -1}], fn = (d) =&gt; d.x
<b>输出：</b>[{"x": -1}, {"x": 0}, {"x": 1}]
<b>解释：</b>fn 返回 "x" 键的值，因此数组根据该值排序。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>arr = [[3, 4], [5, 2], [10, 1]], fn = (x) =&gt; x[1]
<b>输出：</b>[[10, 1], [5, 2], [3, 4]]
<b>解释：</b>数组按照索引为 1 处的数字升序排序。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>arr</code> 是一个有效的 JSON 数组</li>
	<li><code>fn</code> 是一个函数，返回一个数字</li>
	<li><code>1 &lt;=&nbsp;arr.length &lt;= 5 * 10<sup>5</sup></code></li>
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
function sortBy(arr: any[], fn: Function): any[] {
    return arr.sort((a, b) => fn(a) - fn(b));
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2725. 间隔取消](https://leetcode.cn/problems/interval-cancellation){#2725}

{{< tabs "2725" >}}

{{% tab "ts" %}}
```ts
function cancellable(fn: Function, args: any[], t: number): Function {
    fn(...args);
    const time = setInterval(() => fn(...args), t);
    return () => clearInterval(time);
}

/**
 *  const result = []
 *
 *  const fn = (x) => x * 2
 *  const args = [4], t = 20, cancelT = 110
 *
 *  const log = (...argsArr) => {
 *      result.push(fn(...argsArr))
 *  }
 *
 *  const cancel = cancellable(fn, args, t);
 *
 *  setTimeout(() => {
 *     cancel()
 *     console.log(result) // [
 *                         //      {"time":0,"returned":8},
 *                         //      {"time":20,"returned":8},
 *                         //      {"time":40,"returned":8},
 *                         //      {"time":60,"returned":8},
 *                         //      {"time":80,"returned":8},
 *                         //      {"time":100,"returned":8}
 *                         //  ]
 *  }, cancelT)
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>现给定一个函数 <code>fn</code>，一个参数数组 <code>args</code> 和一个时间间隔 <code>t</code>，返回一个取消函数 <code>cancelFn</code>。</p>

<p>在经过 <code>cancelTimeMs</code> 毫秒的延迟后，将调用返回的取消函数 <code>cancelFn</code>。</p>

<pre>
setTimeout(cancelFn, cancelTimeMs)
</pre>

<p>函数 <code>fn</code> 应立即使用参数 <code>args</code> 调用，然后每隔 <code>t</code> 毫秒调用一次，直到在 <code>cancelTimeMs</code> 毫秒时调用 <code>cancelFn</code>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>fn = (x) =&gt; x * 2, args = [4], t = 35, cancelT = 190
<b>输出：</b>
[
   {"time": 0, "returned": 8},
   {"time": 35, "returned": 8},
   {"time": 70, "returned": 8},
   {"time": 105, "returned": 8},
   {"time": 140, "returned": 8},
   {"time": 175, "returned": 8}
]
<strong>解释：</strong> 
const cancelTimeMs = 190;
const cancelFn = cancellable((x) =&gt; x * 2, [4], 35);
setTimeout(cancelFn, cancelTimeMs);

每隔 35ms，调用 fn(4)。直到 t=190ms，然后取消。
第一次调用 fn 是在 0ms。fn(4) 返回 8。
第二次调用 fn 是在 35ms。fn(4) 返回 8。
第三次调用 fn 是在 70ms。fn(4) 返回 8。
第四次调用 fn 是在&nbsp;105ms。fn(4) 返回 8。
第五次调用 fn 是在 140ms。fn(4) 返回 8。
第六次调用 fn 是在 175ms。fn(4) 返回 8。
在 t=190ms 时取消
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>fn = (x1, x2) =&gt; (x1 * x2), args = [2, 5], t = 30, cancelT = 165
<strong>输出：</strong> 
[
   {"time": 0, "returned": 10},
   {"time": 30, "returned": 10},
   {"time": 60, "returned": 10},
   {"time": 90, "returned": 10},
   {"time": 120, "returned": 10},
   {"time": 150, "returned": 10}
]
<strong>解释：</strong>
const cancelTimeMs = 165; 
const cancelFn = cancellable((x1, x2) =&gt; (x1 * x2), [2, 5], 30) 
setTimeout(cancelFn, cancelTimeMs)

每隔 30ms，调用 fn(2, 5)。直到 t=165ms，然后取消。
第一次调用 fn 是在 0ms
第二次调用 fn 是在 30ms
第三次调用 fn 是在 60ms
第四次调用 fn 是在&nbsp;90ms
第五次调用 fn 是在 120ms
第六次调用 fn 是在 150ms
在 165ms 取消
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>fn = (x1, x2, x3) =&gt; (x1 + x2 + x3), args = [5, 1, 3], t = 50, cancelT = 180
<b>输出：</b>
[
   {"time": 0, "returned": 9},
   {"time": 50, "returned": 9},
   {"time": 100, "returned": 9},
   {"time": 150, "returned": 9}
]
<b>解释：</b>
const cancelTimeMs = 180;
const cancelFn = cancellable((x1, x2, x3) =&gt; (x1 + x2 + x3), [5, 1, 3], 50)
setTimeout(cancelFn, cancelTimeMs)

每隔 50ms，调用 fn(5, 1, 3)。直到 t=180ms，然后取消。
第一次调用 fn 是在 0ms
第二次调用 fn 是在 50ms
第三次调用 fn 是在 100ms
第四次调用 fn 是在&nbsp;150ms
在 180ms 取消
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>fn</code> 是一个函数</li>
	<li><code>args</code> 是一个有效的 JSON 数组</li>
	<li><code>1 &lt;= args.length &lt;= 10</code></li>
	<li><code><font face="monospace">30 &lt;= t &lt;= 100</font></code></li>
	<li><code><font face="monospace">10 &lt;= cancelT &lt;= 500</font></code></li>
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
function cancellable(fn: Function, args: any[], t: number): Function {
    fn(...args);
    const time = setInterval(() => fn(...args), t);
    return () => clearInterval(time);
}

/**
 *  const result = []
 *
 *  const fn = (x) => x * 2
 *  const args = [4], t = 20, cancelT = 110
 *
 *  const log = (...argsArr) => {
 *      result.push(fn(...argsArr))
 *  }
 *
 *  const cancel = cancellable(fn, args, t);
 *
 *  setTimeout(() => {
 *     cancel()
 *     console.log(result) // [
 *                         //      {"time":0,"returned":8},
 *                         //      {"time":20,"returned":8},
 *                         //      {"time":40,"returned":8},
 *                         //      {"time":60,"returned":8},
 *                         //      {"time":80,"returned":8},
 *                         //      {"time":100,"returned":8}
 *                         //  ]
 *  }, cancelT)
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2726. 使用方法链的计算器](https://leetcode.cn/problems/calculator-with-method-chaining){#2726}

{{< tabs "2726" >}}

{{% tab "ts" %}}
```ts
class Calculator {
    private x: number;

    constructor(value: number) {
        this.x = value;
    }

    add(value: number): Calculator {
        this.x += value;
        return this;
    }

    subtract(value: number): Calculator {
        this.x -= value;
        return this;
    }

    multiply(value: number): Calculator {
        this.x *= value;
        return this;
    }

    divide(value: number): Calculator {
        if (value === 0) {
            throw new Error('Division by zero is not allowed');
        }
        this.x /= value;
        return this;
    }

    power(value: number): Calculator {
        this.x **= value;
        return this;
    }

    getResult(): number {
        return this.x;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>设计一个类 <code>Calculator</code> 。该类应提供加法、减法、乘法、除法和乘方等数学运算功能。同时，它还应支持连续操作的方法链式调用。<code>Calculator</code> 类的构造函数应接受一个数字作为 <code>result</code> 的初始值。</p>

<p>你的 <code>Calculator</code> 类应包含以下方法：</p>

<ul>
	<li><code>add</code> - 将给定的数字 <code>value</code> 与 <code>result</code> 相加，并返回更新后的 <code>Calculator</code> 对象。</li>
	<li><code>subtract</code> - 从 <code>result</code> 中减去给定的数字 <code>value</code>&nbsp;，并返回更新后的 <code>Calculator</code> 对象。</li>
	<li><code>multiply</code> - 将 <code>result</code> 乘以给定的数字 <code>value</code> ，并返回更新后的&nbsp;<code>Calculator</code> 对象。</li>
	<li><code>divide</code> - 将 <code>result</code> 除以给定的数字 <code>value</code> ，并返回更新后的&nbsp;<code>Calculator</code> 对象。如果传入的值为 <code>0</code> ，则抛出错误 <code>"Division by zero is not allowed"</code> 。</li>
	<li><code>power</code> - 计算 <code>result</code> 的幂，指数为给定的数字 <code>value</code> ，并返回更新后的&nbsp;<code>Calculator</code> 对象。（<code>result = result ^ value</code> ）</li>
	<li><code>getResult</code> - 返回 <code>result</code> 的值。</li>
</ul>

<p>结果与实际结果相差在 <code>10<sup>-5</sup></code><sup>&nbsp;</sup>范围内的解被认为是正确的。</p>

<p>&nbsp;</p>

<p><b>示例 1：</b></p>

<pre>
<b>输入：</b>actions = ["Calculator", "add", "subtract", "getResult"], 
values = [10, 5, 7]
<b>输出：</b>8
<b>解释：</b>
new Calculator(10).add(5).subtract(7).getResult() // 10 + 5 - 7 = 8
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>actions = ["Calculator", "multiply", "power", "getResult"], 
values = [2, 5, 2]
<b>输出：</b>100
<b>解释：</b>
new Calculator(2).multiply(5).power(2).getResult() // (2 * 5) ^ 2 = 100
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>actions = ["Calculator", "divide", "getResult"], 
values = [20, 0]
<b>输出：</b>"Division by zero is not allowed"
<b>解释：</b>
new Calculator(20).divide(0).getResult() // 20 / 0 

由于不能除以零，因此应抛出错误。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>actions</code>&nbsp;是一个有效的 JSON 字符串数组</li>
	<li><code>values</code>&nbsp;是一个有效的 JSON 字符串数组</li>
	<li><code>2 &lt;= actions.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= values.length &lt;= 2 * 10<sup>4</sup>&nbsp;- 1</code></li>
	<li><code>actions[i]</code>&nbsp;是 "Calculator", "add", "subtract", "multiply", "divide", "power", 和 "getResult" 其中的元素</li>
	<li>第一个操作总是 "Calculator"</li>
	<li>最后一个操作总是&nbsp;"getResult"</li>
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
class Calculator {
    private x: number;

    constructor(value: number) {
        this.x = value;
    }

    add(value: number): Calculator {
        this.x += value;
        return this;
    }

    subtract(value: number): Calculator {
        this.x -= value;
        return this;
    }

    multiply(value: number): Calculator {
        this.x *= value;
        return this;
    }

    divide(value: number): Calculator {
        if (value === 0) {
            throw new Error('Division by zero is not allowed');
        }
        this.x /= value;
        return this;
    }

    power(value: number): Calculator {
        this.x **= value;
        return this;
    }

    getResult(): number {
        return this.x;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2727. 判断对象是否为空](https://leetcode.cn/problems/is-object-empty){#2727}

{{< tabs "2727" >}}

{{% tab "ts" %}}
```ts
function isEmpty(obj: Record<string, any> | any[]): boolean {
    return Object.keys(obj).length === 0;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {Object | Array} obj
 * @return {boolean}
 */
var isEmpty = function (obj) {
    for (const x in obj) {
        return false;
    }
    return true;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个对象或数组，判断它是否为空。</p>

<ul>
	<li>一个空对象不包含任何键值对。</li>
	<li>一个空数组不包含任何元素。</li>
</ul>

<p>你可以假设对象或数组是通过 <code>JSON.parse</code> 解析得到的。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>obj = {"x": 5, "y": 42}
<b>输出：</b>false
<b>解释：</b>这个对象有两个键值对，所以它不为空。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>obj = {}
<b>输出：</b>true
<b>解释：</b>这个对象没有任何键值对，所以它为空。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>obj = [null, false, 0]
<b>输出：</b>false
<b>解释：</b>这个数组有 3 个元素，所以它不为空。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>obj</code> 是一个有效的 JSON 对象或数组</li>
	<li><code>2 &lt;= JSON.stringify(obj).length &lt;= 10<sup>5</sup></code></li>
</ul>

<p>&nbsp;</p>
<strong>你可以在 O(1) 时间复杂度内解决这个问题吗？</strong>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：遍历

我们可以遍历对象或数组，如果遍历到了第一个元素，就返回 `false`，否则返回 `true`。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### TypeScript

```ts
function isEmpty(obj: Record<string, any> | any[]): boolean {
    for (const x in obj) {
        return false;
    }
    return true;
}
```

#### JavaScript

```js
/**
 * @param {Object | Array} obj
 * @return {boolean}
 */
var isEmpty = function (obj) {
    for (const x in obj) {
        return false;
    }
    return true;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### TypeScript

```ts
function isEmpty(obj: Record<string, any> | any[]): boolean {
    return Object.keys(obj).length === 0;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2728. 计算一个环形街道上的房屋数量 🔒](https://leetcode.cn/problems/count-houses-in-a-circular-street){#2728}

{{< tabs "2728" >}}

{{% tab "python" %}}
```python
# Definition for a street.
# class Street:
#     def openDoor(self):
#         pass
#     def closeDoor(self):
#         pass
#     def isDoorOpen(self):
#         pass
#     def moveRight(self):
#         pass
#     def moveLeft(self):
#         pass
class Solution:
    def houseCount(self, street: Optional["Street"], k: int) -> int:
        for _ in range(k):
            street.openDoor()
            street.moveLeft()
        ans = 0
        while street.isDoorOpen():
            street.closeDoor()
            street.moveLeft()
            ans += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Definition for a street.
 * class Street {
 *     public Street(int[] doors);
 *     public void openDoor();
 *     public void closeDoor();
 *     public boolean isDoorOpen();
 *     public void moveRight();
 *     public void moveLeft();
 * }
 */
class Solution {
    public int houseCount(Street street, int k) {
        while (k-- > 0) {
            street.openDoor();
            street.moveLeft();
        }
        int ans = 0;
        while (street.isDoorOpen()) {
            ++ans;
            street.closeDoor();
            street.moveLeft();
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Definition for a street.
 * class Street {
 * public:
 *     Street(vector<int> doors);
 *     void openDoor();
 *     void closeDoor();
 *     bool isDoorOpen();
 *     void moveRight();
 *     void moveLeft();
 * };
 */
class Solution {
public:
    int houseCount(Street* street, int k) {
        while (k--) {
            street->openDoor();
            street->moveLeft();
        }
        int ans = 0;
        while (street->isDoorOpen()) {
            ans++;
            street->closeDoor();
            street->moveLeft();
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for a street.
 * type Street interface {
 *     OpenDoor()
 *     CloseDoor()
 *     IsDoorOpen() bool
 *     MoveRight()
 *     MoveLeft()
 * }
 */
func houseCount(street Street, k int) (ans int) {
	for ; k > 0; k-- {
		street.OpenDoor()
		street.MoveLeft()
	}
	for ; street.IsDoorOpen(); street.MoveLeft() {
		ans++
		street.CloseDoor()
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for a street.
 * class Street {
 *     constructor(doors: number[]);
 *     public openDoor(): void;
 *     public closeDoor(): void;
 *     public isDoorOpen(): boolean;
 *     public moveRight(): void;
 *     public moveLeft(): void;
 * }
 */
function houseCount(street: Street | null, k: number): number {
    while (k-- > 0) {
        street.openDoor();
        street.moveLeft();
    }
    let ans = 0;
    while (street.isDoorOpen()) {
        ++ans;
        street.closeDoor();
        street.moveLeft();
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

<p>给定一个代表环形街道的类 <code>Street</code> 和一个正整数 <code>k</code>，表示街道上房屋的最大数量（也就是说房屋数量不超过 <code>k</code>&nbsp;）。每个房屋的门初始时可以是开着的也可以是关着的。</p>

<p>刚开始，你站在一座房子的门前。你的任务是计算街道上的房屋数量。</p>

<p><code>Street</code> 类包含以下函数：</p>

<ul>
	<li><code>void openDoor()</code> ：打开当前房屋的门。</li>
	<li><code>void closeDoor()</code> ：关闭当前房屋的门。</li>
	<li><code>boolean isDoorOpen()</code> ：如果当前房屋的门是开着的返回 <code>true</code> ，否则返回 <code>false</code> 。</li>
	<li><code>void moveRight()</code> ：向右移动到下一座房屋。</li>
	<li><code>void moveLeft()</code> ：向左移动到上一座房屋。</li>
</ul>

<p>返回 <code>ans</code>，它表示街道上的房屋数量。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>street = [0,0,0,0], k = 10
<b>输出：</b>4
<b>解释：</b>街道上有 4 座房屋，它们的门都是关着的。
房屋数量小于 k，即 10。</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>street = [1,0,1,1,0], k = 5
<b>输出：</b>5
<b>解释：</b>街道上有 5 座房屋，向右移动时第 1、3 和 4 座房屋的门是开着的，其余的门都是关着的。房屋数量等于 k，即 5。
</pre>

<p>&nbsp;</p>

<p><strong>解释：</strong></p>

<ul>
	<li><code>n&nbsp; 是房屋数量</code></li>
	<li><code>1 &lt;= n &lt;= k &lt;= 10<sup>3</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：遍历

我们先循环 $k$ 次，每次打开当前房子的门，然后向左移动一格，循环结束后，所有房子的门都是打开的。

然后，我们再循环左移，如果当前房子的门是打开的，就关闭它，房子数加一，继续左移，直到当前房子的门是关闭的，循环结束，返回房子数。

时间复杂度 $O(k)$，其中 $k$ 为题目给定的整数。空间复杂度 $O(1)$。

相似题目：

-   [2753. 计算一个环形街道上的房屋数量 🔒 II](https://github.com/doocs/leetcode/blob/main/solution/2700-2799/2753.Count%20Houses%20in%20a%20Circular%20Street%20II/README.md)

<!-- tabs:start -->

#### Python3

```python
# Definition for a street.
# class Street:
#     def openDoor(self):
#         pass
#     def closeDoor(self):
#         pass
#     def isDoorOpen(self):
#         pass
#     def moveRight(self):
#         pass
#     def moveLeft(self):
#         pass
class Solution:
    def houseCount(self, street: Optional["Street"], k: int) -> int:
        for _ in range(k):
            street.openDoor()
            street.moveLeft()
        ans = 0
        while street.isDoorOpen():
            street.closeDoor()
            street.moveLeft()
            ans += 1
        return ans
```

#### Java

```java
/**
 * Definition for a street.
 * class Street {
 *     public Street(int[] doors);
 *     public void openDoor();
 *     public void closeDoor();
 *     public boolean isDoorOpen();
 *     public void moveRight();
 *     public void moveLeft();
 * }
 */
class Solution {
    public int houseCount(Street street, int k) {
        while (k-- > 0) {
            street.openDoor();
            street.moveLeft();
        }
        int ans = 0;
        while (street.isDoorOpen()) {
            ++ans;
            street.closeDoor();
            street.moveLeft();
        }
        return ans;
    }
}
```

#### C++

```cpp
/**
 * Definition for a street.
 * class Street {
 * public:
 *     Street(vector<int> doors);
 *     void openDoor();
 *     void closeDoor();
 *     bool isDoorOpen();
 *     void moveRight();
 *     void moveLeft();
 * };
 */
class Solution {
public:
    int houseCount(Street* street, int k) {
        while (k--) {
            street->openDoor();
            street->moveLeft();
        }
        int ans = 0;
        while (street->isDoorOpen()) {
            ans++;
            street->closeDoor();
            street->moveLeft();
        }
        return ans;
    }
};
```

#### Go

```go
/**
 * Definition for a street.
 * type Street interface {
 *     OpenDoor()
 *     CloseDoor()
 *     IsDoorOpen() bool
 *     MoveRight()
 *     MoveLeft()
 * }
 */
func houseCount(street Street, k int) (ans int) {
	for ; k > 0; k-- {
		street.OpenDoor()
		street.MoveLeft()
	}
	for ; street.IsDoorOpen(); street.MoveLeft() {
		ans++
		street.CloseDoor()
	}
	return
}
```

#### TypeScript

```ts
/**
 * Definition for a street.
 * class Street {
 *     constructor(doors: number[]);
 *     public openDoor(): void;
 *     public closeDoor(): void;
 *     public isDoorOpen(): boolean;
 *     public moveRight(): void;
 *     public moveLeft(): void;
 * }
 */
function houseCount(street: Street | null, k: number): number {
    while (k-- > 0) {
        street.openDoor();
        street.moveLeft();
    }
    let ans = 0;
    while (street.isDoorOpen()) {
        ++ans;
        street.closeDoor();
        street.moveLeft();
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2729. 判断一个数是否迷人](https://leetcode.cn/problems/check-if-the-number-is-fascinating){#2729}

{{< tabs "2729" >}}

{{% tab "python" %}}
```python
class Solution:
    def isFascinating(self, n: int) -> bool:
        s = str(n) + str(2 * n) + str(3 * n)
        return "".join(sorted(s)) == "123456789"
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isFascinating(int n) {
        String s = "" + n + (2 * n) + (3 * n);
        int[] cnt = new int[10];
        for (char c : s.toCharArray()) {
            if (++cnt[c - '0'] > 1) {
                return false;
            }
        }
        return cnt[0] == 0 && s.length() == 9;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool isFascinating(int n) {
        string s = to_string(n) + to_string(n * 2) + to_string(n * 3);
        sort(s.begin(), s.end());
        return s == "123456789";
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isFascinating(n int) bool {
	s := strconv.Itoa(n) + strconv.Itoa(n*2) + strconv.Itoa(n*3)
	cnt := [10]int{}
	for _, c := range s {
		cnt[c-'0']++
		if cnt[c-'0'] > 1 {
			return false
		}
	}
	return cnt[0] == 0 && len(s) == 9
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isFascinating(n: number): boolean {
    const s = `${n}${n * 2}${n * 3}`;
    return s.split('').sort().join('') === '123456789';
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    pub fn is_fascinating(mut n: i32) -> bool {
        let mut i = n * 2;
        let mut j = n * 3;

        let mut hash = HashMap::new();

        while n != 0 {
            let cnt = hash.entry(n % 10).or_insert(0);
            *cnt += 1;
            n /= 10;
        }

        while i != 0 {
            let cnt = hash.entry(i % 10).or_insert(0);
            *cnt += 1;
            i /= 10;
        }

        while j != 0 {
            let cnt = hash.entry(j % 10).or_insert(0);
            *cnt += 1;
            j /= 10;
        }

        for k in 1..=9 {
            if !hash.contains_key(&k) || hash[&k] > 1 {
                return false;
            }
        }

        !hash.contains_key(&0)
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个三位数整数 <code>n</code>&nbsp;。</p>

<p>如果经过以下修改得到的数字 <strong>恰好</strong>&nbsp;包含数字 <code>1</code>&nbsp;到 <code>9</code>&nbsp;各一次且不包含任何 <code>0</code>&nbsp;，那么我们称数字 <code>n</code>&nbsp;是 <strong>迷人的</strong>&nbsp;：</p>

<ul>
	<li>将&nbsp;<code>n</code>&nbsp;与数字&nbsp;<code>2 * n</code> 和&nbsp;<code>3 * n</code>&nbsp;<strong>连接</strong>&nbsp;。</li>
</ul>

<p>如果 <code>n</code>&nbsp;是迷人的，返回&nbsp;<code>true</code>，否则返回&nbsp;<code>false</code>&nbsp;。</p>

<p><strong>连接</strong>&nbsp;两个数字表示把它们首尾相接连在一起。比方说&nbsp;<code>121</code> 和&nbsp;<code>371</code>&nbsp;连接得到&nbsp;<code>121371</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>n = 192
<b>输出：</b>true
<b>解释：</b>我们将数字 n = 192 ，2 * n = 384 和 3 * n = 576 连接，得到 192384576 。这个数字包含 1 到 9 恰好各一次。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>n = 100
<b>输出：</b>false
<b>解释：</b>我们将数字 n = 100 ，2 * n = 200 和 3 * n = 300 连接，得到 100200300 。这个数字不符合上述条件。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>100 &lt;= n &lt;= 999</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们根据题目描述，将数字 $n$ 与 $2 \times n$ 和 $3 \times n$ 连接，得到字符串 $s$，然后判断 $s$ 是否包含数字 $1$ 到 $9$ 各一次且不包含任何 $0$ 即可。

时间复杂度 $O(\log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为题目给定的整数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isFascinating(self, n: int) -> bool:
        s = str(n) + str(2 * n) + str(3 * n)
        return "".join(sorted(s)) == "123456789"
```

#### Java

```java
class Solution {
    public boolean isFascinating(int n) {
        String s = "" + n + (2 * n) + (3 * n);
        int[] cnt = new int[10];
        for (char c : s.toCharArray()) {
            if (++cnt[c - '0'] > 1) {
                return false;
            }
        }
        return cnt[0] == 0 && s.length() == 9;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool isFascinating(int n) {
        string s = to_string(n) + to_string(n * 2) + to_string(n * 3);
        sort(s.begin(), s.end());
        return s == "123456789";
    }
};
```

#### Go

```go
func isFascinating(n int) bool {
	s := strconv.Itoa(n) + strconv.Itoa(n*2) + strconv.Itoa(n*3)
	cnt := [10]int{}
	for _, c := range s {
		cnt[c-'0']++
		if cnt[c-'0'] > 1 {
			return false
		}
	}
	return cnt[0] == 0 && len(s) == 9
}
```

#### TypeScript

```ts
function isFascinating(n: number): boolean {
    const s = `${n}${n * 2}${n * 3}`;
    return s.split('').sort().join('') === '123456789';
}
```

#### Rust

```rust
impl Solution {
    pub fn is_fascinating(n: i32) -> bool {
        let s = format!("{}{}{}", n, n * 2, n * 3);

        let mut cnt = vec![0; 10];
        for c in s.chars() {
            let t = (c as usize) - ('0' as usize);
            cnt[t] += 1;
            if cnt[t] > 1 {
                return false;
            }
        }

        cnt[0] == 0 && s.len() == 9
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
use std::collections::HashMap;

impl Solution {
    pub fn is_fascinating(mut n: i32) -> bool {
        let mut i = n * 2;
        let mut j = n * 3;

        let mut hash = HashMap::new();

        while n != 0 {
            let cnt = hash.entry(n % 10).or_insert(0);
            *cnt += 1;
            n /= 10;
        }

        while i != 0 {
            let cnt = hash.entry(i % 10).or_insert(0);
            *cnt += 1;
            i /= 10;
        }

        while j != 0 {
            let cnt = hash.entry(j % 10).or_insert(0);
            *cnt += 1;
            j /= 10;
        }

        for k in 1..=9 {
            if !hash.contains_key(&k) || hash[&k] > 1 {
                return false;
            }
        }

        !hash.contains_key(&0)
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
