---
title: "2704_ToBeOrNotToBe"
date: 2025-10-06T00:42:37+08:00
weight: 2704
tags: [JavaScript]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [2704. 相等还是不相等](https://leetcode.cn/problems/to-be-or-not-to-be)

[English Version](../en/2704-04/2704_ToBeOrNotToBe)

## 题目描述

<!-- description:start -->

<p>请你编写一个名为 <code>expect</code> 的函数，用于帮助开发人员测试他们的代码。它应该接受任何值 <code>val</code> 并返回一个包含以下两个函数的对象。</p>

<ul>
	<li><code>toBe(val)</code> 接受另一个值并在两个值相等（ <code>===</code> ）时返回 <code>true</code> 。如果它们不相等，则应抛出错误 <code>"Not Equal"</code> 。</li>
	<li><code>notToBe(val)</code> 接受另一个值并在两个值不相等（ <code>!==</code> ）时返回 <code>true</code> 。如果它们相等，则应抛出错误 <code>"Equal"</code> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>func = () =&gt; expect(5).toBe(5)
<b>输出：</b>{"value": true}
<b>解释：</b>5 === 5 因此该表达式返回 true。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>func = () =&gt; expect(5).toBe(null)
<b>输出：</b>{"error": "Not Equal"}
<b>解释：</b>5 !== null 因此抛出错误 "Not Equal".
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>func = () =&gt; expect(5).notToBe(null)
<b>输出：</b>{"value": true}
<b>解释：</b>5 !== null 因此该表达式返回 true.
</pre>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### TypeScript



#### JavaScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "ts" %}}
```ts
type ToBeOrNotToBe = {
    toBe: (val: any) => boolean;
    notToBe: (val: any) => boolean;
};

function expect(val: any): ToBeOrNotToBe {
    return {
        toBe: (toBeVal: any) => {
            if (val !== toBeVal) {
                throw new Error('Not Equal');
            }
            return true;
        },
        notToBe: (notToBeVal: any) => {
            if (val === notToBeVal) {
                throw new Error('Equal');
            }
            return true;
        },
    };
}

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} val
 * @return {Object}
 */
var expect = function (val) {
    return {
        toBe: function (expected) {
            if (val !== expected) {
                throw new Error('Not Equal');
            }
            return true;
        },
        notToBe: function (expected) {
            if (val === expected) {
                throw new Error('Equal');
            }
            return true;
        },
    };
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */
```
{{% /tab %}}
{{< /tabs>}}

