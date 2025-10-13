---
title: "2690_无穷方法对象 🔒"
date: 2025-10-08T18:39:28+08:00
weight: 10
tags: [JavaScript, 双指针, 回溯, 图, 堆（优先队列）, 字符串, 数学, 最短路, 栈, 模拟, 贪心]
---

{{< markmap >}}
### [2690_无穷方法对象 🔒](#2690)
#### [JavaScript](#2690)
### [2691_不可变辅助工具 🔒](#2691)
#### [JavaScript](#2691)
### [2692_使对象不可变 🔒](#2692)
#### [JavaScript](#2692)
### [2693_使用自定义上下文调用函数](#2693)
#### [JavaScript](#2693)
### [2694_事件发射器](#2694)
#### [JavaScript](#2694)
### [2695_包装数组](#2695)
#### [JavaScript](#2695)
### [2696_删除子串后的字符串最小长度](#2696)
#### [栈](#2696)
#### [字符串](#2696)
#### [模拟](#2696)
### [2697_字典序最小回文串](#2697)
#### [贪心](#2697)
#### [双指针](#2697)
#### [字符串](#2697)
### [2698_求一个整数的惩罚数](#2698)
#### [数学](#2698)
#### [回溯](#2698)
### [2699_修改图中的边权](#2699)
#### [图](#2699)
#### [最短路](#2699)
#### [堆（优先队列）](#2699)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2690_无穷方法对象 🔒
___
#### JavaScript
---
### 2691_不可变辅助工具 🔒
___
#### JavaScript
---
### 2692_使对象不可变 🔒
___
#### JavaScript
---
### 2693_使用自定义上下文调用函数
___
#### JavaScript
---
### 2694_事件发射器
___
#### JavaScript
---
### 2695_包装数组
___
#### JavaScript
---
### 2696_删除子串后的字符串最小长度
___
#### 栈
___
#### 字符串
___
#### 模拟
---
### 2697_字典序最小回文串
___
#### 贪心
___
#### 双指针
___
#### 字符串
---
### 2698_求一个整数的惩罚数
___
#### 数学
___
#### 回溯
---
### 2699_修改图中的边权
___
#### 图
___
#### 最短路
___
#### 堆（优先队列）
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| JavaScript | 双指针 | 回溯 |
| 图 | 堆（优先队列） | 字符串 |
| 数学 | 最短路 | 栈 |
| 模拟 | 贪心 |  |

# [2690. 无穷方法对象 🔒](https://leetcode.cn/problems/infinite-method-object){#2690}

{{< tabs "2690" >}}

{{% tab "ts" %}}
```ts
function createInfiniteObject(): Record<string, () => string> {
    return new Proxy(
        {},
        {
            get: (_, prop) => () => prop.toString(),
        },
    );
}

/**
 * const obj = createInfiniteObject();
 * obj['abc123'](); // "abc123"
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>请你编写一个函数，返回一个 <strong>无穷方法对象</strong> 。</p>

<p><strong>无穷方法对象</strong> 被定义为一个对象，它允许您调用任何方法，并始终返回方法的名称。</p>

<p>例如，如果执行 <code>obj.abc123()</code> ，它将返回 <code>"abc123"</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>method = "abc123"
<b>输出：</b>"abc123"
<strong>解释：</strong>
const obj = createInfiniteObject();
obj['abc123'](); // "abc123"
返回的字符串应始终与方法名称匹配。</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>method = ".-qw73n|^2It"
<strong>输出：</strong>".-qw73n|^2It"
<b>解释：</b>返回的字符串应始终与方法名称匹配。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= method.length &lt;= 1000</code></li>
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
function createInfiniteObject(): Record<string, () => string> {
    return new Proxy(
        {},
        {
            get: (_, prop) => () => prop.toString(),
        },
    );
}

/**
 * const obj = createInfiniteObject();
 * obj['abc123'](); // "abc123"
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2691. 不可变辅助工具 🔒](https://leetcode.cn/problems/immutability-helper){#2691}

{{< tabs "2691" >}}

{{% tab "ts" %}}
```ts

```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>创建带有微小修改的不可变对象的克隆副本是一个繁琐的过程。请你编写一个名为 <code>ImmutableHelper</code> 的类，作为满足这一要求的工具。构造函数接受一个不可变对象 <code>obj</code> ，该对象将是一个 JSON 对象或数组。</p>

<p>该类有一个名为 <code>produce</code> 的方法，它接受一个名为 <code>mutator</code> 的函数。该函数返回一个新的对象，它与原始对象相似，但应用了这些变化。</p>

<p><code>mutator</code> 函数接受 <code>obj</code> 的 <strong>代理</strong> 版本。函数的使用者可以（看起来）对该对象进行修改，但原始对象 <code>obj</code> 实际上没有被改变。</p>

<p>例如，用户可以编写如下代码：</p>

<pre>
const originalObj = {"x": 5};
const helper = new ImmutableHelper(originalObj);
const newObj = helper.produce((proxy) =&gt; {
  proxy.x = proxy.x + 1;
});
console.log(originalObj); // {"x": 5}
console.log(newObj); // {"x": 6}</pre>

<p><code>mutator</code> 函数的属性：</p>

<ul>
	<li>它始终返回 <code>undefined</code> 。</li>
	<li>它永远不会访问不存在的键。</li>
	<li>它永远不会删除键（ <code>delete obj.key</code> ）。</li>
	<li>它永远不会在代理对象上调用方法（ <code>push</code> 、<code>shift</code> 等）。</li>
	<li>它永远不会将键设置为对象（ <code>proxy.x = {}</code> ）。</li>
</ul>

<p><strong>关于如何测试解决方案的说明：</strong>解决方案验证器仅分析返回结果与原始 <code>obj</code> 之间的差异。进行完全比较的计算开销太大。此外，对原始对象进行的任何变更都将导致答案错误。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>
obj = {"val": 10}, 
mutators = [
&nbsp; proxy =&gt; { proxy.val += 1; },
&nbsp; proxy =&gt; { proxy.val -= 1; }
]
<strong>输出：</strong>
[
  {"val": 11},
&nbsp; {"val": 9}
]
<strong>解释：</strong>
const helper = new ImmutableHelper({val: 10});
helper.produce(proxy =&gt; { proxy.val += 1; }); // { "val": 11 }
helper.produce(proxy =&gt; { proxy.val -= 1; }); // { "val": 9 }
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>
obj = {"arr": [1, 2, 3]} 
mutators = [
&nbsp;proxy =&gt; { 
&nbsp;  proxy.arr[0] = 5; 
&nbsp;  proxy.newVal = proxy.arr[0] + proxy.arr[1];
 }
]
<strong>输出：</strong>
[
  {"arr": [5, 2, 3], "newVal": 7 } 
]
<strong>解释：</strong>对原始数组进行了两次编辑。首先将数组的第一个元素设置为 5。然后添加了一个值为 7 的新键。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>
obj = {"obj": {"val": {"x": 10, "y": 20}}}
mutators = [
&nbsp; proxy =&gt; { 
&nbsp;   let data = proxy.obj.val; 
&nbsp;   let temp = data.x; 
&nbsp;   data.x = data.y; 
&nbsp;   data.y = temp; 
&nbsp; }
]
<strong>输出：</strong>
[
  {"obj": {"val": {"x": 20, "y": 10}}}
]
<strong>解释：</strong>交换了 "x" 和 "y" 的值。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= JSON.stringify(obj).length &lt;= 4 * 10<sup>5</sup></code></li>
	<li><code>produce() 的总调用次数 &lt; <font face="monospace">10<sup>5</sup></font></code></li>
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

```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2692. 使对象不可变 🔒](https://leetcode.cn/problems/make-object-immutable){#2692}

{{< tabs "2692" >}}

{{% tab "ts" %}}
```ts
type Obj = Array<any> | Record<any, any>;

function makeImmutable(obj: Obj): Obj {
    const arrayHandler: ProxyHandler<Array<any>> = {
        set: (_, prop) => {
            throw `Error Modifying Index: ${String(prop)}`;
        },
    };
    const objectHandler: ProxyHandler<Record<any, any>> = {
        set: (_, prop) => {
            throw `Error Modifying: ${String(prop)}`;
        },
    };
    const fnHandler: ProxyHandler<Function> = {
        apply: target => {
            throw `Error Calling Method: ${target.name}`;
        },
    };
    const fn = ['pop', 'push', 'shift', 'unshift', 'splice', 'sort', 'reverse'];
    const dfs = (obj: Obj) => {
        for (const key in obj) {
            if (typeof obj[key] === 'object' && obj[key] !== null) {
                obj[key] = dfs(obj[key]);
            }
        }
        if (Array.isArray(obj)) {
            fn.forEach(f => (obj[f] = new Proxy(obj[f], fnHandler)));
            return new Proxy(obj, arrayHandler);
        }
        return new Proxy(obj, objectHandler);
    };
    return dfs(obj);
}

/**
 * const obj = makeImmutable({x: 5});
 * obj.x = 6; // throws "Error Modifying x"
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>请你编写一个函数，该函数接收一个对象 <code>obj</code> ，并返回该对象的一个新的 <strong>不可变</strong> 版本。</p>

<p><strong>不可变</strong> 对象是指不能被修改的对象，如果试图修改它，则会抛出错误。</p>

<p>此新对象可能产生三种类型的错误消息。</p>

<ul>
	<li>如果试图修改对象的键，则会产生以下错误消息： <code>`Error Modifying: ${key}`</code> 。</li>
	<li>如果试图修改数组的索引，则会产生以下错误消息： <code>`Error Modifying Index: ${index}`</code> 。</li>
	<li>如果试图调用会改变数组的方法，则会产生以下错误消息： <code>`Error Calling Method: ${methodName}`</code> 。你可以假设只有以下方法能够改变数组： <code>['pop', 'push', 'shift', 'unshift', 'splice', 'sort', 'reverse']</code> 。</li>
</ul>

<p><code>obj</code> 是一个有效的 JSON 对象或数组，也就是说，它是 <code>JSON.parse()</code> 的输出结果。</p>

<p>请注意，应该抛出字符串字面量，而不是 <code>Error</code> 对象。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>
obj = {
&nbsp; "x": 5
}
fn = (obj) =&gt; { 
&nbsp; obj.x = 5;
&nbsp; return obj.x;
}
<b>输出：</b>{"value": null, "error": "Error Modifying:&nbsp;x"}
<b>解释：</b>试图修改对象的键会导致抛出错误。请注意，是否将值设置为与之前相同的值并不重要。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong> 
obj = [1, 2, 3]
fn = (arr) =&gt; { 
&nbsp; arr[1] = {}; 
&nbsp; return arr[2]; 
}
<b>输出：</b>{"value": null, "error": "Error Modifying&nbsp;Index: 1"}
<strong>解释：</strong>试图修改数组会导致抛出错误。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>
obj = {
&nbsp; "arr": [1, 2, 3]
}
fn = (obj) =&gt; { 
&nbsp; obj.arr.push(4);
&nbsp; return 42;
}
<b>输出：</b>{ "value": null, "error": "Error Calling Method: push"}
<strong>解释：</strong>调用可能导致修改的方法会导致抛出错误。
</pre>

<p><strong class="example">示例 4：</strong></p>

<pre>
<b>输入：</b>
obj = {
&nbsp; "x": 2,
&nbsp; "y": 2
}
fn = (obj) =&gt; { 
&nbsp; return Object.keys(obj);
}
<b>输出：</b>{"value": ["x", "y"], "error": null}
<strong>解释：</strong>没有尝试进行修改，因此函数正常返回。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= JSON.stringify(obj).length &lt;= 10<sup>5</sup></code></li>
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
type Obj = Array<any> | Record<any, any>;

function makeImmutable(obj: Obj): Obj {
    const arrayHandler: ProxyHandler<Array<any>> = {
        set: (_, prop) => {
            throw `Error Modifying Index: ${String(prop)}`;
        },
    };
    const objectHandler: ProxyHandler<Record<any, any>> = {
        set: (_, prop) => {
            throw `Error Modifying: ${String(prop)}`;
        },
    };
    const fnHandler: ProxyHandler<Function> = {
        apply: target => {
            throw `Error Calling Method: ${target.name}`;
        },
    };
    const fn = ['pop', 'push', 'shift', 'unshift', 'splice', 'sort', 'reverse'];
    const dfs = (obj: Obj) => {
        for (const key in obj) {
            if (typeof obj[key] === 'object' && obj[key] !== null) {
                obj[key] = dfs(obj[key]);
            }
        }
        if (Array.isArray(obj)) {
            fn.forEach(f => (obj[f] = new Proxy(obj[f], fnHandler)));
            return new Proxy(obj, arrayHandler);
        }
        return new Proxy(obj, objectHandler);
    };
    return dfs(obj);
}

/**
 * const obj = makeImmutable({x: 5});
 * obj.x = 6; // throws "Error Modifying x"
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2693. 使用自定义上下文调用函数](https://leetcode.cn/problems/call-function-with-custom-context){#2693}

{{< tabs "2693" >}}

{{% tab "ts" %}}
```ts
declare global {
    interface Function {
        callPolyfill(context: Record<any, any>, ...args: any[]): any;
    }
}

Function.prototype.callPolyfill = function (context, ...args): any {
    const fn = this.bind(context);
    return fn(...args);
};

/**
 * function increment() { this.count++; return this.count; }
 * increment.callPolyfill({count: 1}); // 2
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>增强所有函数，使其具有&nbsp;<code>callPolyfill</code>&nbsp;方法。该方法接受一个对象&nbsp;<code>obj</code>&nbsp;作为第一个参数，以及任意数量的附加参数。<code>obj</code>&nbsp;成为函数的&nbsp;<code>this</code>&nbsp;上下文。附加参数将传递给该函数（即&nbsp;<code>callPolyfill</code>&nbsp;方法所属的函数）。</p>

<p>例如，如果有以下函数：</p>

<pre>
function tax(price, taxRate) {
  const totalCost = price * (1 + taxRate);
&nbsp; console.log(`The cost of ${this.item} is ${totalCost}`);
}
</pre>

<p>调用&nbsp;<code>tax(10, 0.1)</code>&nbsp;将输出&nbsp;<code>"The cost of undefined is 11"</code>&nbsp;。这是因为&nbsp;<code>this</code>&nbsp;上下文未定义。</p>

<p>然而，调用&nbsp;<code>tax.callPolyfill({item: "salad"}, 10, 0.1)</code>&nbsp;将输出&nbsp;<code>"The cost of salad is 11"</code>&nbsp;。<code>this</code>&nbsp;上下文被正确设置，函数输出了适当的结果。</p>

<p>请在不使用内置的&nbsp;<code>Function.call</code>&nbsp;方法的情况下解决这个问题。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>
fn = function add(b) {
  return this.a + b;
}
args = [{"a": 5}, 7]
<b>输出：</b>12
<strong>解释：</strong>
fn.callPolyfill({"a": 5}, 7); // 12
<code>callPolyfill </code>将 "this" 上下文设置为 <code>{"a": 5} </code>，并将 7 作为参数传递。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>
fn = function tax(price, taxRate) { 
&nbsp;return `The cost of the ${this.item} is ${price * taxRate}`; 
}
args = [{"item": "burger"}, 10, 1,1]
<b>输出：</b>"The cost of the burger is 11"
<b>解释：</b><code>callPolyfill </code>将 "this" 上下文设置为 <code>{"item": "burger"} </code>，并将 10 和 1.1 作为附加参数传递。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul style="list-style-type:square;">
	<li><code><font face="monospace">typeof args[0] == 'object' and args[0] != null</font></code></li>
	<li><code>1 &lt;= args.length &lt;= 100</code></li>
	<li><code>2 &lt;= JSON.stringify(args[0]).length &lt;= 10<sup>5</sup></code></li>
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
    interface Function {
        callPolyfill(context: Record<any, any>, ...args: any[]): any;
    }
}

Function.prototype.callPolyfill = function (context, ...args): any {
    const fn = this.bind(context);
    return fn(...args);
};

/**
 * function increment() { this.count++; return this.count; }
 * increment.callPolyfill({count: 1}); // 2
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2694. 事件发射器](https://leetcode.cn/problems/event-emitter){#2694}

{{< tabs "2694" >}}

{{% tab "ts" %}}
```ts
type Callback = (...args: any[]) => any;
type Subscription = {
    unsubscribe: () => void;
};

class EventEmitter {
    private d: Map<string, Set<Callback>> = new Map();

    subscribe(eventName: string, callback: Callback): Subscription {
        this.d.set(eventName, (this.d.get(eventName) || new Set()).add(callback));
        return {
            unsubscribe: () => {
                this.d.get(eventName)?.delete(callback);
            },
        };
    }

    emit(eventName: string, args: any[] = []): any {
        const callbacks = this.d.get(eventName);
        if (!callbacks) {
            return [];
        }
        return [...callbacks].map(callback => callback(...args));
    }
}

/**
 * const emitter = new EventEmitter();
 *
 * // Subscribe to the onClick event with onClickCallback
 * function onClickCallback() { return 99 }
 * const sub = emitter.subscribe('onClick', onClickCallback);
 *
 * emitter.emit('onClick'); // [99]
 * sub.unsubscribe(); // undefined
 * emitter.emit('onClick'); // []
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>设计一个 <code>EventEmitter</code> 类。这个接口与 Node.js 或 DOM 的 Event Target 接口相似，但有一些差异。<code>EventEmitter</code> 应该允许订阅事件和触发事件。</p>

<p>你的 <code>EventEmitter</code> 类应该有以下两个方法：</p>

<ul>
	<li><strong>subscribe</strong> - 这个方法接收两个参数：一个作为字符串的事件名和一个回调函数。当事件被触发时，这个回调函数将被调用。 一个事件应该能够有多个监听器。当触发带有多个回调函数的事件时，应按照订阅的顺序依次调用每个回调函数。应返回一个结果数组。你可以假设传递给 <code>subscribe</code> 的回调函数都不是引用相同的。 <code>subscribe</code> 方法还应返回一个对象，其中包含一个 <code>unsubscribe</code> 方法，使用户可以取消订阅。当调用 <code>unsubscribe</code> 方法时，回调函数应该从订阅列表中删除，并返回 undefined。</li>
	<li><strong>emit</strong> - 这个方法接收两个参数：一个作为字符串的事件名和一个可选的参数数组，这些参数将传递给回调函数。如果没有订阅给定事件的回调函数，则返回一个空数组。否则，按照它们被订阅的顺序返回所有回调函数调用的结果数组。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：
</b>actions = ["EventEmitter", "emit", "subscribe", "subscribe", "emit"], 
values = [[], ["firstEvent", "function cb1() { return 5; }"],  ["firstEvent", "function cb1() { return 5; }"], ["firstEvent"]]
<b>输出：</b>[[],["emitted",[]],["subscribed"],["subscribed"],["emitted",[5,6]]]
<b>解释：</b>
const emitter = new EventEmitter();
emitter.emit("firstEvent"); // [], 还没有订阅任何回调函数
emitter.subscribe("firstEvent", function cb1() { return 5; });
emitter.subscribe("firstEvent", function cb2() { return 6; });
emitter.emit("firstEvent"); // [5, 6], 返回 cb1 和 cb2 的输出
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：
</b>actions = ["EventEmitter", "subscribe", "emit", "emit"], 
values = [[], ["firstEvent", "function cb1(...args) { return args.join(','); }"], ["firstEvent", [1,2,3]], ["firstEvent", [3,4,6]]]
<b>输出：</b>[[],["subscribed"],["emitted",["1,2,3"]],["emitted",["3,4,6"]]]
<strong>解释：</strong>注意 emit 方法应该能够接受一个可选的参数数组。

const emitter = new EventEmitter();
emitter.subscribe("firstEvent, function cb1(...args) { return args.join(','); });
emitter.emit("firstEvent", [1, 2, 3]); // ["1,2,3"]
emitter.emit("firstEvent", [3, 4, 6]); // ["3,4,6"]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：
</b>actions = ["EventEmitter", "subscribe", "emit", "unsubscribe", "emit"], 
values = [[], ["firstEvent", "(...args) =&gt; args.join(',')"], ["firstEvent", [1,2,3]], [0], ["firstEvent", [4,5,6]]]
<b>输出：</b>[[],["subscribed"],["emitted",["1,2,3"]],["unsubscribed",0],["emitted",[]]]
<b>解释：</b>
const emitter = new EventEmitter();
const sub = emitter.subscribe("firstEvent", (...args) =&gt; args.join(','));
emitter.emit("firstEvent", [1, 2, 3]); // ["1,2,3"]
sub.unsubscribe(); // undefined
emitter.emit("firstEvent", [4, 5, 6]); // [], 没有订阅者
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<b>输入：
</b>actions = ["EventEmitter", "subscribe", "subscribe", "unsubscribe", "emit"], 
values = [[], ["firstEvent", "x =&gt; x + 1"], ["firstEvent", "x =&gt; x + 2"], [0], ["firstEvent", [5]]]
<b>输出：</b>[[],["subscribed"],["subscribed"],["unsubscribed",0],["emitted",[7]]]
<b>解释：</b>
const emitter = new EventEmitter();
const sub1 = emitter.subscribe("firstEvent", x =&gt; x + 1);
const sub2 = emitter.subscribe("firstEvent", x =&gt; x + 2);
sub1.unsubscribe(); // undefined
emitter.emit("firstEvent", [5]); // [7]</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= actions.length &lt;= 10</code></li>
	<li><code>values.length === actions.length</code></li>
	<li>所有测试用例都是有效的。例如，你不需要处理取消一个不存在的订阅的情况。</li>
	<li>只有 4 种不同的操作：<code>EventEmitter</code>、<code>emit</code>、<code>subscribe</code> 和 <code>unsubscribe</code>&nbsp;。 <code>EventEmitter</code> 操作没有参数。</li>
	<li><code>emit</code> 操作接收 1 或 2 个参数。第一个参数是要触发的事件名，第二个参数传递给回调函数。</li>
	<li><code>subscribe</code> 操作接收 2 个参数，第一个是事件名，第二个是回调函数。</li>
	<li><code>unsubscribe</code> 操作接收一个参数，即之前进行订阅的顺序（从 0 开始）。</li>
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
type Callback = (...args: any[]) => any;
type Subscription = {
    unsubscribe: () => void;
};

class EventEmitter {
    private d: Map<string, Set<Callback>> = new Map();

    subscribe(eventName: string, callback: Callback): Subscription {
        this.d.set(eventName, (this.d.get(eventName) || new Set()).add(callback));
        return {
            unsubscribe: () => {
                this.d.get(eventName)?.delete(callback);
            },
        };
    }

    emit(eventName: string, args: any[] = []): any {
        const callbacks = this.d.get(eventName);
        if (!callbacks) {
            return [];
        }
        return [...callbacks].map(callback => callback(...args));
    }
}

/**
 * const emitter = new EventEmitter();
 *
 * // Subscribe to the onClick event with onClickCallback
 * function onClickCallback() { return 99 }
 * const sub = emitter.subscribe('onClick', onClickCallback);
 *
 * emitter.emit('onClick'); // [99]
 * sub.unsubscribe(); // undefined
 * emitter.emit('onClick'); // []
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2695. 包装数组](https://leetcode.cn/problems/array-wrapper){#2695}

{{< tabs "2695" >}}

{{% tab "ts" %}}
```ts
class ArrayWrapper {
    private nums: number[];
    private s: number;

    constructor(nums: number[]) {
        this.nums = nums;
        this.s = nums.reduce((a, b) => a + b, 0);
    }

    valueOf() {
        return this.s;
    }

    toString() {
        return `[${this.nums}]`;
    }
}

/**
 * const obj1 = new ArrayWrapper([1,2]);
 * const obj2 = new ArrayWrapper([3,4]);
 * obj1 + obj2; // 10
 * String(obj1); // "[1,2]"
 * String(obj2); // "[3,4]"
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>创建一个名为 <code>ArrayWrapper</code> 的类，它在其构造函数中接受一个整数数组作为参数。该类应具有以下两个特性：</p>

<ul>
	<li>当使用 <code>+</code> 运算符将两个该类的实例相加时，结果值为两个数组中所有元素的总和。</li>
	<li>当在实例上调用 <code>String()</code> 函数时，它将返回一个由逗号分隔的括在方括号中的字符串。例如，<code>[1,2,3]</code> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [[1,2],[3,4]], operation = "Add"
<b>输出：</b>10
<b>解释：</b>
const obj1 = new ArrayWrapper([1,2]);
const obj2 = new ArrayWrapper([3,4]);
obj1 + obj2; // 10
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [[23,98,42,70]], operation = "String"
<b>输出：</b>"[23,98,42,70]"
<strong>解释：</strong>
const obj = new ArrayWrapper([23,98,42,70]);
String(obj); // "[23,98,42,70]"
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [[],[]], operation = "Add"
<b>输出：</b>0
<strong>解释：</strong>
const obj1 = new ArrayWrapper([]);
const obj2 = new ArrayWrapper([]);
obj1 + obj2; // 0
</pre>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<ul>
	<li><code>0 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums[i]&nbsp;&lt;= 1000</code></li>
	<li><code>注意：nums 是传递给构造函数的数组。</code></li>
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
class ArrayWrapper {
    private nums: number[];
    private s: number;

    constructor(nums: number[]) {
        this.nums = nums;
        this.s = nums.reduce((a, b) => a + b, 0);
    }

    valueOf() {
        return this.s;
    }

    toString() {
        return `[${this.nums}]`;
    }
}

/**
 * const obj1 = new ArrayWrapper([1,2]);
 * const obj2 = new ArrayWrapper([3,4]);
 * obj1 + obj2; // 10
 * String(obj1); // "[1,2]"
 * String(obj2); // "[3,4]"
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2696. 删除子串后的字符串最小长度](https://leetcode.cn/problems/minimum-string-length-after-removing-substrings){#2696}

{{< tabs "2696" >}}

{{% tab "python" %}}
```python
class Solution:
    def minLength(self, s: str) -> int:
        stk = [""]
        for c in s:
            if (c == "B" and stk[-1] == "A") or (c == "D" and stk[-1] == "C"):
                stk.pop()
            else:
                stk.append(c)
        return len(stk) - 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minLength(String s) {
        Deque<Character> stk = new ArrayDeque<>();
        stk.push(' ');
        for (char c : s.toCharArray()) {
            if ((c == 'B' && stk.peek() == 'A') || (c == 'D' && stk.peek() == 'C')) {
                stk.pop();
            } else {
                stk.push(c);
            }
        }
        return stk.size() - 1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minLength(string s) {
        string stk = " ";
        for (char& c : s) {
            if ((c == 'B' && stk.back() == 'A') || (c == 'D' && stk.back() == 'C')) {
                stk.pop_back();
            } else {
                stk.push_back(c);
            }
        }
        return stk.size() - 1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minLength(s string) int {
	stk := []byte{' '}
	for _, c := range s {
		if (c == 'B' && stk[len(stk)-1] == 'A') || (c == 'D' && stk[len(stk)-1] == 'C') {
			stk = stk[:len(stk)-1]
		} else {
			stk = append(stk, byte(c))
		}
	}
	return len(stk) - 1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
const minLength = (s: string, n = s.length): number =>
    ((s = s.replace(/AB|CD/g, '')), s.length === n) ? n : minLength(s);
```
{{% /tab %}}
{{% tab "js" %}}
```js
const minLength = (s, n = s.length) =>
    ((s = s.replace(/AB|CD/g, '')), s.length === n) ? n : minLength(s);
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn min_length(s: String) -> i32 {
        let mut ans: Vec<u8> = Vec::new();

        for c in s.bytes() {
            if let Some(last) = ans.last() {
                if *last == b'A' && c == b'B' {
                    ans.pop();
                } else if *last == b'C' && c == b'D' {
                    ans.pop();
                } else {
                    ans.push(c);
                }
            } else {
                ans.push(c);
            }
        }

        ans.len() as i32
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个仅由 <strong>大写</strong> 英文字符组成的字符串 <code>s</code> 。</p>

<p>你可以对此字符串执行一些操作，在每一步操作中，你可以从 <code>s</code> 中删除 <strong>任一个</strong> <code>"AB"</code> 或 <code>"CD"</code> 子字符串。</p>

<p>通过执行操作，删除所有&nbsp;<code>"AB"</code> 和 <code>"CD"</code> 子串，返回可获得的最终字符串的 <strong>最小</strong> 可能长度。</p>

<p><strong>注意</strong>，删除子串后，重新连接出的字符串可能会产生新的&nbsp;<code>"AB"</code> 或 <code>"CD"</code> 子串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "ABFCACDB"
<strong>输出：</strong>2
<strong>解释：</strong>你可以执行下述操作：
- 从 "<em><strong>AB</strong></em>FCACDB" 中删除子串 "AB"，得到 s = "FCACDB" 。
- 从 "FCA<em><strong>CD</strong></em>B" 中删除子串 "CD"，得到 s = "FCAB" 。
- 从 "FC<strong><em>AB</em></strong>" 中删除子串 "AB"，得到 s = "FC" 。
最终字符串的长度为 2 。
可以证明 2 是可获得的最小长度。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "ACBBD"
<strong>输出：</strong>5
<strong>解释：</strong>无法执行操作，字符串长度不变。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> 仅由大写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：栈

我们遍历字符串 $s$，对于当前遍历到的字符 $c$，如果栈不为空且栈顶元素 $top$ 与 $c$ 可以组成 $AB$ 或 $CD$，则弹出栈顶元素，否则将 $c$ 入栈。

最后栈中剩余的元素个数就是最终字符串的长度。

> 在实现上，我们可以在栈中预先放入一个空字符，这样就不需要在遍历字符串时判断栈是否为空了，最后返回栈的大小减一即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minLength(self, s: str) -> int:
        stk = [""]
        for c in s:
            if (c == "B" and stk[-1] == "A") or (c == "D" and stk[-1] == "C"):
                stk.pop()
            else:
                stk.append(c)
        return len(stk) - 1
```

#### Java

```java
class Solution {
    public int minLength(String s) {
        Deque<Character> stk = new ArrayDeque<>();
        stk.push(' ');
        for (char c : s.toCharArray()) {
            if ((c == 'B' && stk.peek() == 'A') || (c == 'D' && stk.peek() == 'C')) {
                stk.pop();
            } else {
                stk.push(c);
            }
        }
        return stk.size() - 1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minLength(string s) {
        string stk = " ";
        for (char& c : s) {
            if ((c == 'B' && stk.back() == 'A') || (c == 'D' && stk.back() == 'C')) {
                stk.pop_back();
            } else {
                stk.push_back(c);
            }
        }
        return stk.size() - 1;
    }
};
```

#### Go

```go
func minLength(s string) int {
	stk := []byte{' '}
	for _, c := range s {
		if (c == 'B' && stk[len(stk)-1] == 'A') || (c == 'D' && stk[len(stk)-1] == 'C') {
			stk = stk[:len(stk)-1]
		} else {
			stk = append(stk, byte(c))
		}
	}
	return len(stk) - 1
}
```

#### TypeScript

```ts
function minLength(s: string): number {
    const stk: string[] = [];
    for (const c of s) {
        if ((stk.at(-1) === 'A' && c === 'B') || (stk.at(-1) === 'C' && c === 'D')) {
            stk.pop();
        } else {
            stk.push(c);
        }
    }
    return stk.length;
}
```

#### JavaScript

```js
function minLength(s) {
    const stk = [];
    for (const c of s) {
        if ((stk.at(-1) === 'A' && c === 'B') || (stk.at(-1) === 'C' && c === 'D')) {
            stk.pop();
        } else {
            stk.push(c);
        }
    }
    return stk.length;
}
```

#### Rust

```rust
impl Solution {
    pub fn min_length(s: String) -> i32 {
        let mut ans: Vec<u8> = Vec::new();

        for c in s.bytes() {
            if let Some(last) = ans.last() {
                if *last == b'A' && c == b'B' {
                    ans.pop();
                } else if *last == b'C' && c == b'D' {
                    ans.pop();
                } else {
                    ans.push(c);
                }
            } else {
                ans.push(c);
            }
        }

        ans.len() as i32
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：递归（一行代码）

<!-- tabs:start -->

#### TypeScript

```ts
const minLength = (s: string, n = s.length): number =>
    ((s = s.replace(/AB|CD/g, '')), s.length === n) ? n : minLength(s);
```

#### JavaScript

```js
const minLength = (s, n = s.length) =>
    ((s = s.replace(/AB|CD/g, '')), s.length === n) ? n : minLength(s);
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2697. 字典序最小回文串](https://leetcode.cn/problems/lexicographically-smallest-palindrome){#2697}

{{< tabs "2697" >}}

{{% tab "python" %}}
```python
class Solution:
    def makeSmallestPalindrome(self, s: str) -> str:
        cs = list(s)
        i, j = 0, len(s) - 1
        while i < j:
            cs[i] = cs[j] = min(cs[i], cs[j])
            i, j = i + 1, j - 1
        return "".join(cs)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String makeSmallestPalindrome(String s) {
        char[] cs = s.toCharArray();
        for (int i = 0, j = cs.length - 1; i < j; ++i, --j) {
            cs[i] = cs[j] = (char) Math.min(cs[i], cs[j]);
        }
        return new String(cs);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string makeSmallestPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
            s[i] = s[j] = min(s[i], s[j]);
        }
        return s;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func makeSmallestPalindrome(s string) string {
	cs := []byte(s)
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		cs[i] = min(cs[i], cs[j])
		cs[j] = cs[i]
	}
	return string(cs)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function makeSmallestPalindrome(s: string): string {
    const cs = s.split('');
    for (let i = 0, j = s.length - 1; i < j; ++i, --j) {
        cs[i] = cs[j] = s[i] < s[j] ? s[i] : s[j];
    }
    return cs.join('');
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn make_smallest_palindrome(s: String) -> String {
        let mut cs: Vec<char> = s.chars().collect();
        let n = cs.len();
        for i in 0..n / 2 {
            let j = n - 1 - i;
            cs[i] = std::cmp::min(cs[i], cs[j]);
            cs[j] = cs[i];
        }
        cs.into_iter().collect()
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个由 <strong>小写英文字母</strong> 组成的字符串 <code>s</code> ，你可以对其执行一些操作。在一步操作中，你可以用其他小写英文字母 <strong>替换</strong>&nbsp; <code>s</code> 中的一个字符。</p>

<p>请你执行 <strong>尽可能少的操作</strong> ，使 <code>s</code> 变成一个 <strong>回文串</strong> 。如果执行 <strong>最少</strong> 操作次数的方案不止一种，则只需选取 <strong>字典序最小</strong> 的方案。</p>

<p>对于两个长度相同的字符串 <code>a</code> 和 <code>b</code> ，在 <code>a</code> 和 <code>b</code> 出现不同的第一个位置，如果该位置上 <code>a</code> 中对应字母比 <code>b</code> 中对应字母在字母表中出现顺序更早，则认为 <code>a</code> 的字典序比 <code>b</code> 的字典序要小。</p>

<p>返回最终的回文字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "egcfe"
<strong>输出：</strong>"efcfe"
<strong>解释：</strong>将 "egcfe" 变成回文字符串的最小操作次数为 1 ，修改 1 次得到的字典序最小回文字符串是 "efcfe"，只需将 'g' 改为 'f' 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "abcd"
<strong>输出：</strong>"abba"
<strong>解释：</strong>将 "abcd" 变成回文字符串的最小操作次数为 2 ，修改 2 次得到的字典序最小回文字符串是 "abba" 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "seven"
<strong>输出：</strong>"neven"
<strong>解释：</strong>将 "seven" 变成回文字符串的最小操作次数为 1 ，修改 1 次得到的字典序最小回文字符串是 "neven" 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code> 仅由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 双指针

我们用两个指针 $i$ 和 $j$ 分别指向字符串的首尾，初始时 $i = 0$, $j = n - 1$。

接下来，我们每一次都贪心地将 $s[i]$ 和 $s[j]$ 修改为它们中的较小值，使得它们相等。然后将 $i$ 向后移动一位，将 $j$ 向前移动一位，继续进行这一过程，直到 $i \ge j$ 为止。此时，我们就得到了最小的回文串。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是字符串的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def makeSmallestPalindrome(self, s: str) -> str:
        cs = list(s)
        i, j = 0, len(s) - 1
        while i < j:
            cs[i] = cs[j] = min(cs[i], cs[j])
            i, j = i + 1, j - 1
        return "".join(cs)
```

#### Java

```java
class Solution {
    public String makeSmallestPalindrome(String s) {
        char[] cs = s.toCharArray();
        for (int i = 0, j = cs.length - 1; i < j; ++i, --j) {
            cs[i] = cs[j] = (char) Math.min(cs[i], cs[j]);
        }
        return new String(cs);
    }
}
```

#### C++

```cpp
class Solution {
public:
    string makeSmallestPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
            s[i] = s[j] = min(s[i], s[j]);
        }
        return s;
    }
};
```

#### Go

```go
func makeSmallestPalindrome(s string) string {
	cs := []byte(s)
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		cs[i] = min(cs[i], cs[j])
		cs[j] = cs[i]
	}
	return string(cs)
}
```

#### TypeScript

```ts
function makeSmallestPalindrome(s: string): string {
    const cs = s.split('');
    for (let i = 0, j = s.length - 1; i < j; ++i, --j) {
        cs[i] = cs[j] = s[i] < s[j] ? s[i] : s[j];
    }
    return cs.join('');
}
```

#### Rust

```rust
impl Solution {
    pub fn make_smallest_palindrome(s: String) -> String {
        let mut cs: Vec<char> = s.chars().collect();
        let n = cs.len();
        for i in 0..n / 2 {
            let j = n - 1 - i;
            cs[i] = std::cmp::min(cs[i], cs[j]);
            cs[j] = cs[i];
        }
        cs.into_iter().collect()
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2698. 求一个整数的惩罚数](https://leetcode.cn/problems/find-the-punishment-number-of-an-integer){#2698}

{{< tabs "2698" >}}

{{% tab "python" %}}
```python
class Solution:
    def punishmentNumber(self, n: int) -> int:
        def check(s: str, i: int, x: int) -> bool:
            m = len(s)
            if i >= m:
                return x == 0
            y = 0
            for j in range(i, m):
                y = y * 10 + int(s[j])
                if y > x:
                    break
                if check(s, j + 1, x - y):
                    return True
            return False

        ans = 0
        for i in range(1, n + 1):
            x = i * i
            if check(str(x), 0, i):
                ans += x
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            int x = i * i;
            if (check(x + "", 0, i)) {
                ans += x;
            }
        }
        return ans;
    }

    private boolean check(String s, int i, int x) {
        int m = s.length();
        if (i >= m) {
            return x == 0;
        }
        int y = 0;
        for (int j = i; j < m; ++j) {
            y = y * 10 + (s.charAt(j) - '0');
            if (y > x) {
                break;
            }
            if (check(s, j + 1, x - y)) {
                return true;
            }
        }
        return false;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            int x = i * i;
            string s = to_string(x);
            if (check(s, 0, i)) {
                ans += x;
            }
        }
        return ans;
    }

    bool check(const string& s, int i, int x) {
        int m = s.size();
        if (i >= m) {
            return x == 0;
        }
        int y = 0;
        for (int j = i; j < m; ++j) {
            y = y * 10 + s[j] - '0';
            if (y > x) {
                break;
            }
            if (check(s, j + 1, x - y)) {
                return true;
            }
        }
        return false;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func punishmentNumber(n int) (ans int) {
	var check func(string, int, int) bool
	check = func(s string, i, x int) bool {
		m := len(s)
		if i >= m {
			return x == 0
		}
		y := 0
		for j := i; j < m; j++ {
			y = y*10 + int(s[j]-'0')
			if y > x {
				break
			}
			if check(s, j+1, x-y) {
				return true
			}
		}
		return false
	}
	for i := 1; i <= n; i++ {
		x := i * i
		s := strconv.Itoa(x)
		if check(s, 0, i) {
			ans += x
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function punishmentNumber(n: number): number {
    const check = (s: string, i: number, x: number): boolean => {
        const m = s.length;
        if (i >= m) {
            return x === 0;
        }
        let y = 0;
        for (let j = i; j < m; ++j) {
            y = y * 10 + Number(s[j]);
            if (y > x) {
                break;
            }
            if (check(s, j + 1, x - y)) {
                return true;
            }
        }
        return false;
    };
    let ans = 0;
    for (let i = 1; i <= n; ++i) {
        const x = i * i;
        const s = x.toString();
        if (check(s, 0, i)) {
            ans += x;
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

<p>给你一个正整数&nbsp;<code>n</code>&nbsp;，请你返回&nbsp;<code>n</code>&nbsp;的&nbsp;<strong>惩罚数</strong>&nbsp;。</p>

<p><code>n</code>&nbsp;的 <strong>惩罚数</strong>&nbsp;定义为所有满足以下条件 <code>i</code>&nbsp;的数的平方和：</p>

<ul>
	<li><code>1 &lt;= i &lt;= n</code></li>
	<li><code>i * i</code> 的十进制表示的字符串可以分割成若干连续子字符串，且这些子字符串对应的整数值之和等于 <code>i</code> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>n = 10
<b>输出：</b>182
<b>解释：</b>总共有 3 个范围在 [1, 10] 的整数 i 满足要求：
- 1 ，因为 1 * 1 = 1
- 9 ，因为 9 * 9 = 81 ，且 81 可以分割成 8 + 1 。
- 10 ，因为 10 * 10 = 100 ，且 100 可以分割成 10 + 0 。
因此，10 的惩罚数为 1 + 81 + 100 = 182
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>n = 37
<b>输出：</b>1478
<b>解释：</b>总共有 4 个范围在 [1, 37] 的整数 i 满足要求：
- 1 ，因为 1 * 1 = 1
- 9 ，因为 9 * 9 = 81 ，且 81 可以分割成 8 + 1 。
- 10 ，因为 10 * 10 = 100 ，且 100 可以分割成 10 + 0 。
- 36 ，因为 36 * 36 = 1296 ，且 1296 可以分割成 1 + 29 + 6 。
因此，37 的惩罚数为 1 + 81 + 100 + 1296 = 1478
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举 + DFS

我们枚举 $i$，其中 $1 \leq i \leq n$，对于每个 $i$，我们将 $x = i^2$ 的十进制表示的字符串进行分割，然后判断是否满足题目要求。如果满足，我们就将 $x$ 累加到答案中。

枚举结束，返回答案即可。

时间复杂度 $O(n^{1 + 2 \log_{10}^2})$，空间复杂度 $O(\log n)$。其中 $n$ 为给定的正整数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def punishmentNumber(self, n: int) -> int:
        def check(s: str, i: int, x: int) -> bool:
            m = len(s)
            if i >= m:
                return x == 0
            y = 0
            for j in range(i, m):
                y = y * 10 + int(s[j])
                if y > x:
                    break
                if check(s, j + 1, x - y):
                    return True
            return False

        ans = 0
        for i in range(1, n + 1):
            x = i * i
            if check(str(x), 0, i):
                ans += x
        return ans
```

#### Java

```java
class Solution {
    public int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            int x = i * i;
            if (check(x + "", 0, i)) {
                ans += x;
            }
        }
        return ans;
    }

    private boolean check(String s, int i, int x) {
        int m = s.length();
        if (i >= m) {
            return x == 0;
        }
        int y = 0;
        for (int j = i; j < m; ++j) {
            y = y * 10 + (s.charAt(j) - '0');
            if (y > x) {
                break;
            }
            if (check(s, j + 1, x - y)) {
                return true;
            }
        }
        return false;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            int x = i * i;
            string s = to_string(x);
            if (check(s, 0, i)) {
                ans += x;
            }
        }
        return ans;
    }

    bool check(const string& s, int i, int x) {
        int m = s.size();
        if (i >= m) {
            return x == 0;
        }
        int y = 0;
        for (int j = i; j < m; ++j) {
            y = y * 10 + s[j] - '0';
            if (y > x) {
                break;
            }
            if (check(s, j + 1, x - y)) {
                return true;
            }
        }
        return false;
    }
};
```

#### Go

```go
func punishmentNumber(n int) (ans int) {
	var check func(string, int, int) bool
	check = func(s string, i, x int) bool {
		m := len(s)
		if i >= m {
			return x == 0
		}
		y := 0
		for j := i; j < m; j++ {
			y = y*10 + int(s[j]-'0')
			if y > x {
				break
			}
			if check(s, j+1, x-y) {
				return true
			}
		}
		return false
	}
	for i := 1; i <= n; i++ {
		x := i * i
		s := strconv.Itoa(x)
		if check(s, 0, i) {
			ans += x
		}
	}
	return
}
```

#### TypeScript

```ts
function punishmentNumber(n: number): number {
    const check = (s: string, i: number, x: number): boolean => {
        const m = s.length;
        if (i >= m) {
            return x === 0;
        }
        let y = 0;
        for (let j = i; j < m; ++j) {
            y = y * 10 + Number(s[j]);
            if (y > x) {
                break;
            }
            if (check(s, j + 1, x - y)) {
                return true;
            }
        }
        return false;
    };
    let ans = 0;
    for (let i = 1; i <= n; ++i) {
        const x = i * i;
        const s = x.toString();
        if (check(s, 0, i)) {
            ans += x;
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

# [2699. 修改图中的边权](https://leetcode.cn/problems/modify-graph-edge-weights){#2699}

{{< tabs "2699" >}}

{{% tab "python" %}}
```python
class Solution:
    def modifiedGraphEdges(
        self, n: int, edges: List[List[int]], source: int, destination: int, target: int
    ) -> List[List[int]]:
        def dijkstra(edges: List[List[int]]) -> int:
            g = [[inf] * n for _ in range(n)]
            for a, b, w in edges:
                if w == -1:
                    continue
                g[a][b] = g[b][a] = w
            dist = [inf] * n
            dist[source] = 0
            vis = [False] * n
            for _ in range(n):
                k = -1
                for j in range(n):
                    if not vis[j] and (k == -1 or dist[k] > dist[j]):
                        k = j
                vis[k] = True
                for j in range(n):
                    dist[j] = min(dist[j], dist[k] + g[k][j])
            return dist[destination]

        inf = 2 * 10**9
        d = dijkstra(edges)
        if d < target:
            return []
        ok = d == target
        for e in edges:
            if e[2] > 0:
                continue
            if ok:
                e[2] = inf
                continue
            e[2] = 1
            d = dijkstra(edges)
            if d <= target:
                ok = True
                e[2] += target - d
        return edges if ok else []
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private final int inf = 2000000000;

    public int[][] modifiedGraphEdges(
        int n, int[][] edges, int source, int destination, int target) {
        long d = dijkstra(edges, n, source, destination);
        if (d < target) {
            return new int[0][];
        }
        boolean ok = d == target;
        for (var e : edges) {
            if (e[2] > 0) {
                continue;
            }
            if (ok) {
                e[2] = inf;
                continue;
            }
            e[2] = 1;
            d = dijkstra(edges, n, source, destination);
            if (d <= target) {
                ok = true;
                e[2] += target - d;
            }
        }
        return ok ? edges : new int[0][];
    }

    private long dijkstra(int[][] edges, int n, int src, int dest) {
        int[][] g = new int[n][n];
        long[] dist = new long[n];
        Arrays.fill(dist, inf);
        dist[src] = 0;
        for (var f : g) {
            Arrays.fill(f, inf);
        }
        for (var e : edges) {
            int a = e[0], b = e[1], w = e[2];
            if (w == -1) {
                continue;
            }
            g[a][b] = w;
            g[b][a] = w;
        }
        boolean[] vis = new boolean[n];
        for (int i = 0; i < n; ++i) {
            int k = -1;
            for (int j = 0; j < n; ++j) {
                if (!vis[j] && (k == -1 || dist[k] > dist[j])) {
                    k = j;
                }
            }
            vis[k] = true;
            for (int j = 0; j < n; ++j) {
                dist[j] = Math.min(dist[j], dist[k] + g[k][j]);
            }
        }
        return dist[dest];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
using ll = long long;
const int inf = 2e9;

class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        ll d = dijkstra(edges, n, source, destination);
        if (d < target) {
            return {};
        }
        bool ok = d == target;
        for (auto& e : edges) {
            if (e[2] > 0) {
                continue;
            }
            if (ok) {
                e[2] = inf;
                continue;
            }
            e[2] = 1;
            d = dijkstra(edges, n, source, destination);
            if (d <= target) {
                ok = true;
                e[2] += target - d;
            }
        }
        return ok ? edges : vector<vector<int>>{};
    }

    ll dijkstra(vector<vector<int>>& edges, int n, int src, int dest) {
        ll g[n][n];
        ll dist[n];
        bool vis[n];
        for (int i = 0; i < n; ++i) {
            fill(g[i], g[i] + n, inf);
            dist[i] = inf;
            vis[i] = false;
        }
        dist[src] = 0;
        for (auto& e : edges) {
            int a = e[0], b = e[1], w = e[2];
            if (w == -1) {
                continue;
            }
            g[a][b] = w;
            g[b][a] = w;
        }
        for (int i = 0; i < n; ++i) {
            int k = -1;
            for (int j = 0; j < n; ++j) {
                if (!vis[j] && (k == -1 || dist[j] < dist[k])) {
                    k = j;
                }
            }
            vis[k] = true;
            for (int j = 0; j < n; ++j) {
                dist[j] = min(dist[j], dist[k] + g[k][j]);
            }
        }
        return dist[dest];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func modifiedGraphEdges(n int, edges [][]int, source int, destination int, target int) [][]int {
	const inf int = 2e9
	dijkstra := func(edges [][]int) int {
		g := make([][]int, n)
		dist := make([]int, n)
		vis := make([]bool, n)
		for i := range g {
			g[i] = make([]int, n)
			for j := range g[i] {
				g[i][j] = inf
			}
			dist[i] = inf
		}
		dist[source] = 0
		for _, e := range edges {
			a, b, w := e[0], e[1], e[2]
			if w == -1 {
				continue
			}
			g[a][b], g[b][a] = w, w
		}
		for i := 0; i < n; i++ {
			k := -1
			for j := 0; j < n; j++ {
				if !vis[j] && (k == -1 || dist[j] < dist[k]) {
					k = j
				}
			}
			vis[k] = true
			for j := 0; j < n; j++ {
				dist[j] = min(dist[j], dist[k]+g[k][j])
			}
		}
		return dist[destination]
	}
	d := dijkstra(edges)
	if d < target {
		return [][]int{}
	}
	ok := d == target
	for _, e := range edges {
		if e[2] > 0 {
			continue
		}
		if ok {
			e[2] = inf
			continue
		}
		e[2] = 1
		d := dijkstra(edges)
		if d <= target {
			ok = true
			e[2] += target - d
		}
	}
	if ok {
		return edges
	}
	return [][]int{}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function modifiedGraphEdges(
    n: number,
    edges: number[][],
    source: number,
    destination: number,
    target: number,
): number[][] {
    const inf = 2e9;
    const dijkstra = (edges: number[][]): number => {
        const g: number[][] = Array(n)
            .fill(0)
            .map(() => Array(n).fill(inf));
        const dist: number[] = Array(n).fill(inf);
        const vis: boolean[] = Array(n).fill(false);
        for (const [a, b, w] of edges) {
            if (w === -1) {
                continue;
            }
            g[a][b] = w;
            g[b][a] = w;
        }
        dist[source] = 0;
        for (let i = 0; i < n; ++i) {
            let k = -1;
            for (let j = 0; j < n; ++j) {
                if (!vis[j] && (k === -1 || dist[j] < dist[k])) {
                    k = j;
                }
            }
            vis[k] = true;
            for (let j = 0; j < n; ++j) {
                dist[j] = Math.min(dist[j], dist[k] + g[k][j]);
            }
        }
        return dist[destination];
    };
    let d = dijkstra(edges);
    if (d < target) {
        return [];
    }
    let ok = d === target;
    for (const e of edges) {
        if (e[2] > 0) {
            continue;
        }
        if (ok) {
            e[2] = inf;
            continue;
        }
        e[2] = 1;
        d = dijkstra(edges);
        if (d <= target) {
            ok = true;
            e[2] += target - d;
        }
    }
    return ok ? edges : [];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 <code>n</code>&nbsp;个节点的 <strong>无向带权连通</strong>&nbsp;图，节点编号为&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n - 1</code>&nbsp;，再给你一个整数数组&nbsp;<code>edges</code>&nbsp;，其中&nbsp;<code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>, w<sub>i</sub>]</code>&nbsp;表示节点&nbsp;<code>a<sub>i</sub></code> 和&nbsp;<code>b<sub>i</sub></code>&nbsp;之间有一条边权为&nbsp;<code>w<sub>i</sub></code>&nbsp;的边。</p>

<p>部分边的边权为&nbsp;<code>-1</code>（<code>w<sub>i</sub> = -1</code>），其他边的边权都为 <strong>正</strong>&nbsp;数（<code>w<sub>i</sub> &gt; 0</code>）。</p>

<p>你需要将所有边权为 <code>-1</code>&nbsp;的边都修改为范围&nbsp;<code>[1, 2 * 10<sup>9</sup>]</code>&nbsp;中的 <strong>正整数</strong>&nbsp;，使得从节点&nbsp;<code>source</code>&nbsp;到节点&nbsp;<code>destination</code>&nbsp;的 <strong>最短距离</strong>&nbsp;为整数&nbsp;<code>target</code>&nbsp;。如果有 <strong>多种</strong>&nbsp;修改方案可以使&nbsp;<code>source</code> 和&nbsp;<code>destination</code>&nbsp;之间的最短距离等于&nbsp;<code>target</code>&nbsp;，你可以返回任意一种方案。</p>

<p>如果存在使 <code>source</code>&nbsp;到 <code>destination</code>&nbsp;最短距离为 <code>target</code>&nbsp;的方案，请你按任意顺序返回包含所有边的数组（包括未修改边权的边）。如果不存在这样的方案，请你返回一个 <strong>空数组</strong>&nbsp;。</p>

<p><strong>注意：</strong>你不能修改一开始边权为正数的边。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2600-2699/2699.Modify%20Graph%20Edge%20Weights/images/graph.png" style="width: 300px; height: 300px;" /></strong></p>

<pre>
<b>输入：</b>n = 5, edges = [[4,1,-1],[2,0,-1],[0,3,-1],[4,3,-1]], source = 0, destination = 1, target = 5
<b>输出：</b>[[4,1,1],[2,0,1],[0,3,3],[4,3,1]]
<b>解释：</b>上图展示了一个满足题意的修改方案，从 0 到 1 的最短距离为 5 。
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2600-2699/2699.Modify%20Graph%20Edge%20Weights/images/graph-2.png" style="width: 300px; height: 300px;" /></strong></p>

<pre>
<b>输入：</b>n = 3, edges = [[0,1,-1],[0,2,5]], source = 0, destination = 2, target = 6
<b>输出：</b>[]
<b>解释：</b>上图是一开始的图。没有办法通过修改边权为 -1 的边，使得 0 到 2 的最短距离等于 6 ，所以返回一个空数组。
</pre>

<p><strong>示例 3：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2600-2699/2699.Modify%20Graph%20Edge%20Weights/images/graph-3.png" style="width: 300px; height: 300px;" /></strong></p>

<pre>
<b>输入：</b>n = 4, edges = [[1,0,4],[1,2,3],[2,3,5],[0,3,-1]], source = 0, destination = 2, target = 6
<b>输出：</b>[[1,0,4],[1,2,3],[2,3,5],[0,3,1]]
<b>解释：</b>上图展示了一个满足题意的修改方案，从 0 到 2 的最短距离为 6 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= edges.length &lt;= n * (n - 1) / 2</code></li>
	<li><code>edges[i].length == 3</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i&nbsp;</sub>&lt;&nbsp;n</code></li>
	<li><code>w<sub>i</sub>&nbsp;= -1</code> 或者 <code>1 &lt;= w<sub>i&nbsp;</sub>&lt;= 10<sup><span style="">7</span></sup></code></li>
	<li><code>a<sub>i&nbsp;</sub>!=&nbsp;b<sub>i</sub></code></li>
	<li><code>0 &lt;= source, destination &lt; n</code></li>
	<li><code>source != destination</code></li>
	<li><code>1 &lt;= target &lt;= 10<sup>9</sup></code></li>
	<li>输入的图是连通图，且没有自环和重边。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：最短路（Dijkstra 算法）

我们先不考虑边权为 $-1$ 的边，使用 Dijkstra 算法求出从 $source$ 到 $destination$ 的最短距离 $d$。

如果 $d \lt target$，说明存在一条完全由正权边组成的最短路径，此时无论我们如何修改边权为 $-1$ 的边，都无法使得 $source$ 到 $destination$ 的最短距离等于 $target$，因此不存在满足题意的修改方案，返回一个空数组即可。

如果 $d = target$，说明存在一条完全由正权边组成的、长度为 $target$ 的最短路径，此时我们可以将所有边权为 $-1$ 的边修改为最大值 $2 \times 10^9$ 即可。

如果 $d \gt target$，我们可以尝试往图中加入一条边权为 $-1$ 的边，将边权设置为 $1$，然后再次使用 Dijkstra 算法求出从 $source$ 到 $destination$ 的最短距离 $d$。

-   如果最短距离 $d \leq target$，说明加入这条边后，可以使得最短路变短，而且最短路也一定经过这条边，那么我们只需要将这条边的边权改为 $target-d+1$，就可以使得最短路等于 $target$。然后我们将其余的边权为 $-1$ 的边修改为最大值 $2 \times 10^9$ 即可。
-   如果最短距离 $d \gt target$，说明加入这条边后，最短路不会变短，那么我们贪心地将这条边的边权保持为 $-1$，然后继续尝试加入其余的边权为 $-1$ 的边。

时间复杂度 $O(n^3)$，空间复杂度 $O(n^2)$。其中 $n$ 是图中的点数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def modifiedGraphEdges(
        self, n: int, edges: List[List[int]], source: int, destination: int, target: int
    ) -> List[List[int]]:
        def dijkstra(edges: List[List[int]]) -> int:
            g = [[inf] * n for _ in range(n)]
            for a, b, w in edges:
                if w == -1:
                    continue
                g[a][b] = g[b][a] = w
            dist = [inf] * n
            dist[source] = 0
            vis = [False] * n
            for _ in range(n):
                k = -1
                for j in range(n):
                    if not vis[j] and (k == -1 or dist[k] > dist[j]):
                        k = j
                vis[k] = True
                for j in range(n):
                    dist[j] = min(dist[j], dist[k] + g[k][j])
            return dist[destination]

        inf = 2 * 10**9
        d = dijkstra(edges)
        if d < target:
            return []
        ok = d == target
        for e in edges:
            if e[2] > 0:
                continue
            if ok:
                e[2] = inf
                continue
            e[2] = 1
            d = dijkstra(edges)
            if d <= target:
                ok = True
                e[2] += target - d
        return edges if ok else []
```

#### Java

```java
class Solution {
    private final int inf = 2000000000;

    public int[][] modifiedGraphEdges(
        int n, int[][] edges, int source, int destination, int target) {
        long d = dijkstra(edges, n, source, destination);
        if (d < target) {
            return new int[0][];
        }
        boolean ok = d == target;
        for (var e : edges) {
            if (e[2] > 0) {
                continue;
            }
            if (ok) {
                e[2] = inf;
                continue;
            }
            e[2] = 1;
            d = dijkstra(edges, n, source, destination);
            if (d <= target) {
                ok = true;
                e[2] += target - d;
            }
        }
        return ok ? edges : new int[0][];
    }

    private long dijkstra(int[][] edges, int n, int src, int dest) {
        int[][] g = new int[n][n];
        long[] dist = new long[n];
        Arrays.fill(dist, inf);
        dist[src] = 0;
        for (var f : g) {
            Arrays.fill(f, inf);
        }
        for (var e : edges) {
            int a = e[0], b = e[1], w = e[2];
            if (w == -1) {
                continue;
            }
            g[a][b] = w;
            g[b][a] = w;
        }
        boolean[] vis = new boolean[n];
        for (int i = 0; i < n; ++i) {
            int k = -1;
            for (int j = 0; j < n; ++j) {
                if (!vis[j] && (k == -1 || dist[k] > dist[j])) {
                    k = j;
                }
            }
            vis[k] = true;
            for (int j = 0; j < n; ++j) {
                dist[j] = Math.min(dist[j], dist[k] + g[k][j]);
            }
        }
        return dist[dest];
    }
}
```

#### C++

```cpp
using ll = long long;
const int inf = 2e9;

class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        ll d = dijkstra(edges, n, source, destination);
        if (d < target) {
            return {};
        }
        bool ok = d == target;
        for (auto& e : edges) {
            if (e[2] > 0) {
                continue;
            }
            if (ok) {
                e[2] = inf;
                continue;
            }
            e[2] = 1;
            d = dijkstra(edges, n, source, destination);
            if (d <= target) {
                ok = true;
                e[2] += target - d;
            }
        }
        return ok ? edges : vector<vector<int>>{};
    }

    ll dijkstra(vector<vector<int>>& edges, int n, int src, int dest) {
        ll g[n][n];
        ll dist[n];
        bool vis[n];
        for (int i = 0; i < n; ++i) {
            fill(g[i], g[i] + n, inf);
            dist[i] = inf;
            vis[i] = false;
        }
        dist[src] = 0;
        for (auto& e : edges) {
            int a = e[0], b = e[1], w = e[2];
            if (w == -1) {
                continue;
            }
            g[a][b] = w;
            g[b][a] = w;
        }
        for (int i = 0; i < n; ++i) {
            int k = -1;
            for (int j = 0; j < n; ++j) {
                if (!vis[j] && (k == -1 || dist[j] < dist[k])) {
                    k = j;
                }
            }
            vis[k] = true;
            for (int j = 0; j < n; ++j) {
                dist[j] = min(dist[j], dist[k] + g[k][j]);
            }
        }
        return dist[dest];
    }
};
```

#### Go

```go
func modifiedGraphEdges(n int, edges [][]int, source int, destination int, target int) [][]int {
	const inf int = 2e9
	dijkstra := func(edges [][]int) int {
		g := make([][]int, n)
		dist := make([]int, n)
		vis := make([]bool, n)
		for i := range g {
			g[i] = make([]int, n)
			for j := range g[i] {
				g[i][j] = inf
			}
			dist[i] = inf
		}
		dist[source] = 0
		for _, e := range edges {
			a, b, w := e[0], e[1], e[2]
			if w == -1 {
				continue
			}
			g[a][b], g[b][a] = w, w
		}
		for i := 0; i < n; i++ {
			k := -1
			for j := 0; j < n; j++ {
				if !vis[j] && (k == -1 || dist[j] < dist[k]) {
					k = j
				}
			}
			vis[k] = true
			for j := 0; j < n; j++ {
				dist[j] = min(dist[j], dist[k]+g[k][j])
			}
		}
		return dist[destination]
	}
	d := dijkstra(edges)
	if d < target {
		return [][]int{}
	}
	ok := d == target
	for _, e := range edges {
		if e[2] > 0 {
			continue
		}
		if ok {
			e[2] = inf
			continue
		}
		e[2] = 1
		d := dijkstra(edges)
		if d <= target {
			ok = true
			e[2] += target - d
		}
	}
	if ok {
		return edges
	}
	return [][]int{}
}
```

#### TypeScript

```ts
function modifiedGraphEdges(
    n: number,
    edges: number[][],
    source: number,
    destination: number,
    target: number,
): number[][] {
    const inf = 2e9;
    const dijkstra = (edges: number[][]): number => {
        const g: number[][] = Array(n)
            .fill(0)
            .map(() => Array(n).fill(inf));
        const dist: number[] = Array(n).fill(inf);
        const vis: boolean[] = Array(n).fill(false);
        for (const [a, b, w] of edges) {
            if (w === -1) {
                continue;
            }
            g[a][b] = w;
            g[b][a] = w;
        }
        dist[source] = 0;
        for (let i = 0; i < n; ++i) {
            let k = -1;
            for (let j = 0; j < n; ++j) {
                if (!vis[j] && (k === -1 || dist[j] < dist[k])) {
                    k = j;
                }
            }
            vis[k] = true;
            for (let j = 0; j < n; ++j) {
                dist[j] = Math.min(dist[j], dist[k] + g[k][j]);
            }
        }
        return dist[destination];
    };
    let d = dijkstra(edges);
    if (d < target) {
        return [];
    }
    let ok = d === target;
    for (const e of edges) {
        if (e[2] > 0) {
            continue;
        }
        if (ok) {
            e[2] = inf;
            continue;
        }
        e[2] = 1;
        d = dijkstra(edges);
        if (d <= target) {
            ok = true;
            e[2] += target - d;
        }
    }
    return ok ? edges : [];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
