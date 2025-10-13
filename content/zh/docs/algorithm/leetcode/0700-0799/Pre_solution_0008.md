---
title: "0770_基本计算器 IV"
date: 2025-10-08T18:36:29+08:00
weight: 8
tags: [二分查找, 二叉搜索树, 二叉树, 位运算, 动态规划, 双指针, 哈希表, 回溯, 堆（优先队列）, 字符串, 并查集, 广度优先搜索, 数学, 数组, 栈, 树, 深度优先搜索, 矩阵, 记忆化搜索, 递归]
---

{{< markmap >}}
### [0770_基本计算器 IV](#770)
#### [栈](#770)
#### [递归](#770)
#### [哈希表](#770)
#### [数学](#770)
#### [字符串](#770)
### [0771_宝石与石头](#771)
#### [哈希表](#771)
#### [字符串](#771)
### [0772_基本计算器 III 🔒](#772)
#### [栈](#772)
#### [递归](#772)
#### [数学](#772)
#### [字符串](#772)
### [0773_滑动谜题](#773)
#### [广度优先搜索](#773)
#### [记忆化搜索](#773)
#### [数组](#773)
#### [动态规划](#773)
#### [回溯](#773)
#### [矩阵](#773)
### [0774_最小化去加油站的最大距离 🔒](#774)
#### [数组](#774)
#### [二分查找](#774)
### [0775_全局倒置与局部倒置](#775)
#### [数组](#775)
#### [数学](#775)
### [0776_拆分二叉搜索树 🔒](#776)
#### [树](#776)
#### [二叉搜索树](#776)
#### [递归](#776)
#### [二叉树](#776)
### [0777_在 LR 字符串中交换相邻字符](#777)
#### [双指针](#777)
#### [字符串](#777)
### [0778_水位上升的泳池中游泳](#778)
#### [深度优先搜索](#778)
#### [广度优先搜索](#778)
#### [并查集](#778)
#### [数组](#778)
#### [二分查找](#778)
#### [矩阵](#778)
#### [堆（优先队列）](#778)
### [0779_第K个语法符号](#779)
#### [位运算](#779)
#### [递归](#779)
#### [数学](#779)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0770_基本计算器 IV
___
#### 栈
___
#### 递归
___
#### 哈希表
___
#### 数学
___
#### 字符串
---
### 0771_宝石与石头
___
#### 哈希表
___
#### 字符串
---
### 0772_基本计算器 III 🔒
___
#### 栈
___
#### 递归
___
#### 数学
___
#### 字符串
---
### 0773_滑动谜题
___
#### 广度优先搜索
___
#### 记忆化搜索
___
#### 数组
___
#### 动态规划
___
#### 回溯
___
#### 矩阵
---
### 0774_最小化去加油站的最大距离 🔒
___
#### 数组
___
#### 二分查找
---
### 0775_全局倒置与局部倒置
___
#### 数组
___
#### 数学
---
### 0776_拆分二叉搜索树 🔒
___
#### 树
___
#### 二叉搜索树
___
#### 递归
___
#### 二叉树
---
### 0777_在 LR 字符串中交换相邻字符
___
#### 双指针
___
#### 字符串
---
### 0778_水位上升的泳池中游泳
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 并查集
___
#### 数组
___
#### 二分查找
___
#### 矩阵
___
#### 堆（优先队列）
---
### 0779_第K个语法符号
___
#### 位运算
___
#### 递归
___
#### 数学
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉搜索树 | 二叉树 |
| 位运算 | 动态规划 | 双指针 |
| 哈希表 | 回溯 | 堆（优先队列） |
| 字符串 | 并查集 | 广度优先搜索 |
| 数学 | 数组 | 栈 |
| 树 | 深度优先搜索 | 矩阵 |
| 记忆化搜索 | 递归 |  |

# [770. 基本计算器 IV](https://leetcode.cn/problems/basic-calculator-iv){#770}

{{< tabs "770" >}}

{{% tab "python" %}}
```python

```
{{% /tab %}}
{{% tab "java" %}}
```java

```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp

```
{{% /tab %}}
{{% tab "go" %}}
```go

```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个表达式如&nbsp;<code>expression = "e + 8 - a + 5"</code>&nbsp;和一个求值映射，如&nbsp;<code>{"e": 1}</code>（给定的形式为&nbsp;<code>evalvars = ["e"]</code> 和&nbsp;<code>evalints = [1]</code>），返回表示简化表达式的标记列表，例如 <code>["-1*a","14"]</code></p>

<ul>
	<li>表达式交替使用块和符号，每个块和符号之间有一个空格。</li>
	<li>块要么是括号中的表达式，要么是变量，要么是非负整数。</li>
	<li>变量是一个由小写字母组成的字符串（不包括数字）。请注意，变量可以是多个字母，并注意变量从不具有像&nbsp;<code>"2x"</code>&nbsp;或&nbsp;<code>"-x"</code>&nbsp;这样的前导系数或一元运算符&nbsp;。</li>
</ul>

<p>表达式按通常顺序进行求值：先是括号，然后求乘法，再计算加法和减法。</p>

<ul>
	<li>例如，<code>expression = "1 + 2 * 3"</code>&nbsp;的答案是 <code>["7"]</code>。</li>
</ul>

<p>输出格式如下：</p>

<ul>
	<li>对于系数非零的每个自变量项，我们按字典排序的顺序将自变量写在一个项中。
	<ul>
		<li>例如，我们永远不会写像 <code>“b*a*c”</code> 这样的项，只写 <code>“a*b*c”</code>。</li>
	</ul>
	</li>
	<li>项的次数等于被乘的自变量的数目，并计算重复项。我们先写出答案的最大次数项，用字典顺序打破关系，此时忽略词的前导系数。
	<ul>
		<li>例如，<code>"a*a*b*c"</code> 的次数为 4。</li>
	</ul>
	</li>
	<li>项的前导系数直接放在左边，用星号将它与变量分隔开(如果存在的话)。前导系数 1 仍然要打印出来。</li>
	<li>格式良好的一个示例答案是&nbsp;<code>["-2*a*a*a", "3*a*a*b", "3*b*b", "4*a", "5*c", "-6"]</code>&nbsp;。</li>
	<li>系数为 <code>0</code> 的项（包括常数项）不包括在内。
	<ul>
		<li>例如，<code>“0”</code> 的表达式输出为&nbsp;<code>[]</code>&nbsp;。</li>
	</ul>
	</li>
</ul>

<p><strong>注意：</strong>你可以假设给定的表达式均有效。所有中间结果都在区间 <code>[-2<sup>31</sup>, 2<sup>31</sup> - 1]</code> 内。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>expression = "e + 8 - a + 5", evalvars = ["e"], evalints = [1]
<strong>输出：</strong>["-1*a","14"]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>expression = "e - 8 + temperature - pressure",
evalvars = ["e", "temperature"], evalints = [1, 12]
<strong>输出：</strong>["-1*pressure","5"]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>expression = "(e + 8) * (e - 8)", evalvars = [], evalints = []
<strong>输出：</strong>["1*e*e","-64"]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= expression.length &lt;= 250</code></li>
	<li><code>expression</code>&nbsp;由小写英文字母，数字&nbsp;<code>'+'</code>,&nbsp;<code>'-'</code>,&nbsp;<code>'*'</code>,&nbsp;<code>'('</code>,&nbsp;<code>')'</code>,&nbsp;<code>' '</code>&nbsp;组成</li>
	<li><code>expression</code>&nbsp;不包含任何前空格或后空格</li>
	<li><code>expression</code>&nbsp;中的所有符号都用一个空格隔开</li>
	<li><code>0 &lt;= evalvars.length &lt;= 100</code></li>
	<li><code>1 &lt;= evalvars[i].length &lt;= 20</code></li>
	<li><code>evalvars[i]</code>&nbsp;由小写英文字母组成</li>
	<li><code>evalints.length == evalvars.length</code></li>
	<li><code>-100 &lt;= evalints[i] &lt;= 100</code></li>
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

#### Python3

```python

```

#### Java

```java

```

#### C++

```cpp

```

#### Go

```go

```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [771. 宝石与石头](https://leetcode.cn/problems/jewels-and-stones){#771}

{{< tabs "771" >}}

{{% tab "python" %}}
```python
class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        s = set(jewels)
        return sum(c in s for c in stones)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numJewelsInStones(String jewels, String stones) {
        int[] s = new int[128];
        for (char c : jewels.toCharArray()) {
            s[c] = 1;
        }
        int ans = 0;
        for (char c : stones.toCharArray()) {
            ans += s[c];
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
    int numJewelsInStones(string jewels, string stones) {
        int s[128] = {0};
        for (char c : jewels) {
            s[c] = 1;
        }
        int ans = 0;
        for (char c : stones) {
            ans += s[c];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numJewelsInStones(jewels string, stones string) (ans int) {
	s := [128]int{}
	for _, c := range jewels {
		s[c] = 1
	}
	for _, c := range stones {
		ans += s[c]
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numJewelsInStones(jewels: string, stones: string): number {
    const s = new Set([...jewels]);
    let ans = 0;
    for (const c of stones) {
        s.has(c) && ans++;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashSet;
impl Solution {
    pub fn num_jewels_in_stones(jewels: String, stones: String) -> i32 {
        let mut s = jewels.as_bytes().iter().collect::<HashSet<&u8>>();
        let mut ans = 0;
        for c in stones.as_bytes() {
            if s.contains(c) {
                ans += 1;
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
 * @param {string} jewels
 * @param {string} stones
 * @return {number}
 */
var numJewelsInStones = function (jewels, stones) {
    const s = new Set(jewels.split(''));
    return stones.split('').reduce((prev, val) => prev + s.has(val), 0);
};
```
{{% /tab %}}
{{% tab "c" %}}
```c
int numJewelsInStones(char* jewels, char* stones) {
    int set[128] = {0};
    for (int i = 0; jewels[i]; i++) {
        set[jewels[i]] = 1;
    }
    int ans = 0;
    for (int i = 0; stones[i]; i++) {
        set[stones[i]] && ans++;
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

<p>&nbsp;给你一个字符串 <code>jewels</code>&nbsp;代表石头中宝石的类型，另有一个字符串 <code>stones</code> 代表你拥有的石头。&nbsp;<code>stones</code>&nbsp;中每个字符代表了一种你拥有的石头的类型，你想知道你拥有的石头中有多少是宝石。</p>

<p>字母区分大小写，因此 <code>"a"</code> 和 <code>"A"</code> 是不同类型的石头。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>jewels = "aA", stones = "aAAbbbb"
<strong>输出：</strong>3
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>jewels = "z", stones = "ZZ"
<strong>输出：</strong>0<strong>
</strong></pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;=&nbsp;jewels.length, stones.length &lt;= 50</code></li>
	<li><code>jewels</code> 和 <code>stones</code> 仅由英文字母组成</li>
	<li><code>jewels</code> 中的所有字符都是 <strong>唯一的</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表或数组

我们可以先用一个哈希表或数组 $s$ 记录所有宝石的类型。然后遍历所有石头，如果当前石头是宝石，就将答案加一。

时间复杂度 $O(m+n)$，空间复杂度 $O(|\Sigma|)$，其中 $m$ 和 $n$ 分别是字符串 $jewels$ 和 $stones$ 的长度，而 $\Sigma$ 是字符集，本题中字符集为所有大小写英文字母的集合。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        s = set(jewels)
        return sum(c in s for c in stones)
```

#### Java

```java
class Solution {
    public int numJewelsInStones(String jewels, String stones) {
        int[] s = new int[128];
        for (char c : jewels.toCharArray()) {
            s[c] = 1;
        }
        int ans = 0;
        for (char c : stones.toCharArray()) {
            ans += s[c];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int s[128] = {0};
        for (char c : jewels) {
            s[c] = 1;
        }
        int ans = 0;
        for (char c : stones) {
            ans += s[c];
        }
        return ans;
    }
};
```

#### Go

```go
func numJewelsInStones(jewels string, stones string) (ans int) {
	s := [128]int{}
	for _, c := range jewels {
		s[c] = 1
	}
	for _, c := range stones {
		ans += s[c]
	}
	return
}
```

#### TypeScript

```ts
function numJewelsInStones(jewels: string, stones: string): number {
    const s = new Set([...jewels]);
    let ans = 0;
    for (const c of stones) {
        s.has(c) && ans++;
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::HashSet;
impl Solution {
    pub fn num_jewels_in_stones(jewels: String, stones: String) -> i32 {
        let mut s = jewels.as_bytes().iter().collect::<HashSet<&u8>>();
        let mut ans = 0;
        for c in stones.as_bytes() {
            if s.contains(c) {
                ans += 1;
            }
        }
        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {string} jewels
 * @param {string} stones
 * @return {number}
 */
var numJewelsInStones = function (jewels, stones) {
    const s = new Set(jewels.split(''));
    return stones.split('').reduce((prev, val) => prev + s.has(val), 0);
};
```

#### C

```c
int numJewelsInStones(char* jewels, char* stones) {
    int set[128] = {0};
    for (int i = 0; jewels[i]; i++) {
        set[jewels[i]] = 1;
    }
    int ans = 0;
    for (int i = 0; stones[i]; i++) {
        set[stones[i]] && ans++;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [772. 基本计算器 III 🔒](https://leetcode.cn/problems/basic-calculator-iii){#772}

{{< tabs "772" >}}

{{% tab "python" %}}
```python
class Solution:
    def calculate(self, s: str) -> int:
        def dfs(q):
            num, sign, stk = 0, "+", []
            while q:
                c = q.popleft()
                if c.isdigit():
                    num = num * 10 + int(c)
                if c == "(":
                    num = dfs(q)
                if c in "+-*/)" or not q:
                    match sign:
                        case "+":
                            stk.append(num)
                        case "-":
                            stk.append(-num)
                        case "*":
                            stk.append(stk.pop() * num)
                        case "/":
                            stk.append(int(stk.pop() / num))
                    num, sign = 0, c
                if c == ")":
                    break
            return sum(stk)

        return dfs(deque(s))
```
{{% /tab %}}
{{% tab "java" %}}
```java

```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
// 逆波兰表示法求解
class Solution {
public:
    // 定义一个操作函数，根据操作符进行数学运算
    int operate(int b, char ch, int a) {
        // 注意ab顺序
        switch (ch) {
        case '+':
            return a + b; // 加法
        case '-':
            return a - b; // 减法
        case '*':
            return a * b; // 乘法
        case '/':
            return a / b; // 除法
        default:
            break;
        }
        return 0; // 默认返回0，处理无效操作符
    }

    // 计算字符串表达式的值
    int calculate(string s) {
        int preority[250]; // 操作符优先级数组
        preority['+'] = 1;
        preority['-'] = 1;
        preority['*'] = 2;
        preority['/'] = 2;
        preority['('] = 0;
        preority[')'] = 0;

        stack<char> op; // 操作符栈
        stack<int> num; // 操作数栈
        int stringsize = s.size(); // 字符串长度
        int i = 0;
        char ch;

        // 遍历字符串
        for (; i < stringsize; i++) {
            ch = s[i];
            if (ch == ' ') {
                continue; // 跳过空格
            }
            if (ch >= '0' && ch <= '9') {
                int realnum = ch - '0'; // 将字符转换为数字
                // 处理多位数字
                while (s[i + 1] >= '0' && s[i + 1] <= '9') {
                    i++;
                    realnum *= 10;
                    realnum += s[i] - '0';
                }
                num.push(realnum); // 将数字压入栈
            } else {
                // 处理操作符
                if (op.empty() || ch == '(' || preority[ch] > preority[op.top()]) {
                    // 特殊情况，处理首个字符为'-'或'+'的情况
                    if (num.empty() && (ch == '-' || ch == '+')) {
                        num.push(0);
                    }
                    op.push(ch); // 将操作符压入栈
                    // 处理括号内的表达式
                    if (ch == '(') {
                        int j = i;
                        while (j + 1 < stringsize) {
                            // 预处理括号内的首个操作符
                            if (s[j + 1] == '-' || s[j + 1] == '+') {
                                num.push(0);
                            }
                            if (s[j + 1] != ' ') {
                                break;
                            }
                            j++;
                        }
                    }
                } else if (ch == ')') {
                    // 处理右括号
                    char ch2 = ')';
                    ch2 = op.top();
                    op.pop();
                    while (ch2 != '(') {
                        int a = num.top();
                        num.pop();
                        int b = num.top();
                        num.pop();
                        num.push(operate(a, ch2, b)); // 计算并压入结果
                        ch2 = op.top();
                        op.pop();
                    }
                } else if (preority[ch] <= preority[op.top()]) {
                    // 处理优先级小于等于栈顶操作符的情况
                    char ch2;
                    ch2 = op.top();
                    while (!op.empty() && preority[ch] <= preority[op.top()] && ch2 != '(') {
                        op.pop();
                        int a = num.top();
                        num.pop();
                        int b = num.top();
                        num.pop();
                        num.push(operate(a, ch2, b)); // 计算并压入结果
                        if (!op.empty()) {
                            ch2 = op.top();
                        } else {
                            break;
                        }
                    }
                    op.push(ch); // 将当前操作符压入栈
                }
            }
        }

        // 处理剩余在栈中的表达式
        while (!op.empty()) {
            ch = op.top();
            op.pop();
            int a = num.top();
            num.pop();
            int b = num.top();
            num.pop();
            num.push(operate(a, ch, b)); // 计算并压入结果
        }

        return num.top(); // 返回最终结果
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go

```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>实现一个基本的计算器来计算简单的表达式字符串。</p>

<p>表达式字符串只包含非负整数，算符 <code>+</code>、<code>-</code>、<code>*</code>、<code>/</code> ，左括号 <code>(</code> 和右括号 <code>)</code> 。整数除法需要 <strong>向下截断</strong> 。</p>

<p>你可以假定给定的表达式总是有效的。所有的中间结果的范围均满足 <code>[-2<sup>31</sup>, 2<sup>31</sup> - 1]</code> 。</p>

<p><strong>注意：</strong>你不能使用任何将字符串作为表达式求值的内置函数，比如 <code>eval()</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "1+1"
<strong>输出：</strong>2
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "6-4/2"
<strong>输出：</strong>4
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "2*(5+5*2)/3+(6/2+8)"
<strong>输出：</strong>21
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> 由整数、<code>'+'</code>、<code>'-'</code>、<code>'*'</code>、<code>'/'</code>、<code>'('</code> 和 <code>')'</code> 组成</li>
	<li><code>s</code> 是一个 <strong>有效的</strong> 表达式</li>
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

#### Python3

```python
class Solution:
    def calculate(self, s: str) -> int:
        def dfs(q):
            num, sign, stk = 0, "+", []
            while q:
                c = q.popleft()
                if c.isdigit():
                    num = num * 10 + int(c)
                if c == "(":
                    num = dfs(q)
                if c in "+-*/)" or not q:
                    match sign:
                        case "+":
                            stk.append(num)
                        case "-":
                            stk.append(-num)
                        case "*":
                            stk.append(stk.pop() * num)
                        case "/":
                            stk.append(int(stk.pop() / num))
                    num, sign = 0, c
                if c == ")":
                    break
            return sum(stk)

        return dfs(deque(s))
```

#### Java

```java

```

#### C++

```cpp
// 逆波兰表示法求解
class Solution {
public:
    // 定义一个操作函数，根据操作符进行数学运算
    int operate(int b, char ch, int a) {
        // 注意ab顺序
        switch (ch) {
        case '+':
            return a + b; // 加法
        case '-':
            return a - b; // 减法
        case '*':
            return a * b; // 乘法
        case '/':
            return a / b; // 除法
        default:
            break;
        }
        return 0; // 默认返回0，处理无效操作符
    }

    // 计算字符串表达式的值
    int calculate(string s) {
        int preority[250]; // 操作符优先级数组
        preority['+'] = 1;
        preority['-'] = 1;
        preority['*'] = 2;
        preority['/'] = 2;
        preority['('] = 0;
        preority[')'] = 0;

        stack<char> op; // 操作符栈
        stack<int> num; // 操作数栈
        int stringsize = s.size(); // 字符串长度
        int i = 0;
        char ch;

        // 遍历字符串
        for (; i < stringsize; i++) {
            ch = s[i];
            if (ch == ' ') {
                continue; // 跳过空格
            }
            if (ch >= '0' && ch <= '9') {
                int realnum = ch - '0'; // 将字符转换为数字
                // 处理多位数字
                while (s[i + 1] >= '0' && s[i + 1] <= '9') {
                    i++;
                    realnum *= 10;
                    realnum += s[i] - '0';
                }
                num.push(realnum); // 将数字压入栈
            } else {
                // 处理操作符
                if (op.empty() || ch == '(' || preority[ch] > preority[op.top()]) {
                    // 特殊情况，处理首个字符为'-'或'+'的情况
                    if (num.empty() && (ch == '-' || ch == '+')) {
                        num.push(0);
                    }
                    op.push(ch); // 将操作符压入栈
                    // 处理括号内的表达式
                    if (ch == '(') {
                        int j = i;
                        while (j + 1 < stringsize) {
                            // 预处理括号内的首个操作符
                            if (s[j + 1] == '-' || s[j + 1] == '+') {
                                num.push(0);
                            }
                            if (s[j + 1] != ' ') {
                                break;
                            }
                            j++;
                        }
                    }
                } else if (ch == ')') {
                    // 处理右括号
                    char ch2 = ')';
                    ch2 = op.top();
                    op.pop();
                    while (ch2 != '(') {
                        int a = num.top();
                        num.pop();
                        int b = num.top();
                        num.pop();
                        num.push(operate(a, ch2, b)); // 计算并压入结果
                        ch2 = op.top();
                        op.pop();
                    }
                } else if (preority[ch] <= preority[op.top()]) {
                    // 处理优先级小于等于栈顶操作符的情况
                    char ch2;
                    ch2 = op.top();
                    while (!op.empty() && preority[ch] <= preority[op.top()] && ch2 != '(') {
                        op.pop();
                        int a = num.top();
                        num.pop();
                        int b = num.top();
                        num.pop();
                        num.push(operate(a, ch2, b)); // 计算并压入结果
                        if (!op.empty()) {
                            ch2 = op.top();
                        } else {
                            break;
                        }
                    }
                    op.push(ch); // 将当前操作符压入栈
                }
            }
        }

        // 处理剩余在栈中的表达式
        while (!op.empty()) {
            ch = op.top();
            op.pop();
            int a = num.top();
            num.pop();
            int b = num.top();
            num.pop();
            num.push(operate(a, ch, b)); // 计算并压入结果
        }

        return num.top(); // 返回最终结果
    }
};
```

#### Go

```go

```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [773. 滑动谜题](https://leetcode.cn/problems/sliding-puzzle){#773}

{{< tabs "773" >}}

{{% tab "python" %}}
```python
class Solution:
    def slidingPuzzle(self, board: List[List[int]]) -> int:
        m, n = 2, 3
        seq = []
        start, end = '', '123450'
        for i in range(m):
            for j in range(n):
                if board[i][j] != 0:
                    seq.append(board[i][j])
                start += str(board[i][j])

        def check(seq):
            n = len(seq)
            cnt = sum(seq[i] > seq[j] for i in range(n) for j in range(i, n))
            return cnt % 2 == 0

        def f(s):
            ans = 0
            for i in range(m * n):
                if s[i] != '0':
                    num = ord(s[i]) - ord('1')
                    ans += abs(i // n - num // n) + abs(i % n - num % n)
            return ans

        if not check(seq):
            return -1
        q = [(f(start), start)]
        dist = {start: 0}
        while q:
            _, state = heappop(q)
            if state == end:
                return dist[state]
            p1 = state.index('0')
            i, j = p1 // n, p1 % n
            s = list(state)
            for a, b in [[0, -1], [0, 1], [1, 0], [-1, 0]]:
                x, y = i + a, j + b
                if 0 <= x < m and 0 <= y < n:
                    p2 = x * n + y
                    s[p1], s[p2] = s[p2], s[p1]
                    next = ''.join(s)
                    s[p1], s[p2] = s[p2], s[p1]
                    if next not in dist or dist[next] > dist[state] + 1:
                        dist[next] = dist[state] + 1
                        heappush(q, (dist[next] + f(next), next))
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int m = 2;
    private int n = 3;

    public int slidingPuzzle(int[][] board) {
        String start = "";
        String end = "123450";
        String seq = "";
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                start += board[i][j];
                if (board[i][j] != 0) {
                    seq += board[i][j];
                }
            }
        }
        if (!check(seq)) {
            return -1;
        }
        PriorityQueue<Pair<Integer, String>> q
            = new PriorityQueue<>(Comparator.comparingInt(Pair::getKey));
        Map<String, Integer> dist = new HashMap<>();
        dist.put(start, 0);
        q.offer(new Pair<>(f(start), start));
        int[] dirs = {-1, 0, 1, 0, -1};
        while (!q.isEmpty()) {
            String state = q.poll().getValue();
            int step = dist.get(state);
            if (end.equals(state)) {
                return step;
            }
            int p1 = state.indexOf("0");
            int i = p1 / n, j = p1 % n;
            char[] s = state.toCharArray();
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    int p2 = x * n + y;
                    swap(s, p1, p2);
                    String next = String.valueOf(s);
                    if (!dist.containsKey(next) || dist.get(next) > step + 1) {
                        dist.put(next, step + 1);
                        q.offer(new Pair<>(step + 1 + f(next), next));
                    }
                    swap(s, p1, p2);
                }
            }
        }
        return -1;
    }

    private void swap(char[] arr, int i, int j) {
        char t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }

    private int f(String s) {
        int ans = 0;
        for (int i = 0; i < m * n; ++i) {
            if (s.charAt(i) != '0') {
                int num = s.charAt(i) - '1';
                ans += Math.abs(i / n - num / n) + Math.abs(i % n - num % n);
            }
        }
        return ans;
    }

    private boolean check(String s) {
        int n = s.length();
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (s.charAt(i) > s.charAt(j)) {
                    ++cnt;
                }
            }
        }
        return cnt % 2 == 0;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int m = 2;
    int n = 3;

    int slidingPuzzle(vector<vector<int>>& board) {
        string start, seq;
        string end = "123450";
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                start += char(board[i][j] + '0');
                if (board[i][j] != 0) seq += char(board[i][j] + '0');
            }
        }
        if (!check(seq)) return -1;
        typedef pair<int, string> PIS;
        priority_queue<PIS, vector<PIS>, greater<PIS>> q;
        unordered_map<string, int> dist;
        dist[start] = 0;
        q.push({f(start), start});
        vector<int> dirs = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            PIS t = q.top();
            q.pop();
            string state = t.second;
            int step = dist[state];
            if (state == end) return step;
            int p1 = state.find('0');
            int i = p1 / n, j = p1 % n;
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x < 0 || x >= m || y < 0 || y >= n) continue;
                int p2 = x * n + y;
                swap(state[p1], state[p2]);
                if (!dist.count(state) || dist[state] > step + 1) {
                    dist[state] = step + 1;
                    q.push({step + 1 + f(state), state});
                }
                swap(state[p1], state[p2]);
            }
        }
        return -1;
    }

    bool check(string s) {
        int n = s.size();
        int cnt = 0;
        for (int i = 0; i < n; ++i)
            for (int j = i; j < n; ++j)
                if (s[i] > s[j])
                    ++cnt;
        return cnt % 2 == 0;
    }

    int f(string s) {
        int ans = 0;
        for (int i = 0; i < m * n; ++i) {
            if (s[i] == '0') continue;
            int num = s[i] - '1';
            ans += abs(num / n - i / n) + abs(num % n - i % n);
        }
        return ans;
    }
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>在一个 <code>2 x 3</code> 的板上（<code>board</code>）有 5 块砖瓦，用数字 <code>1~5</code> 来表示, 以及一块空缺用&nbsp;<code>0</code>&nbsp;来表示。一次 <strong>移动</strong> 定义为选择&nbsp;<code>0</code>&nbsp;与一个相邻的数字（上下左右）进行交换.</p>

<p>最终当板&nbsp;<code>board</code>&nbsp;的结果是&nbsp;<code>[[1,2,3],[4,5,0]]</code>&nbsp;谜板被解开。</p>

<p>给出一个谜板的初始状态&nbsp;<code>board</code>&nbsp;，返回最少可以通过多少次移动解开谜板，如果不能解开谜板，则返回 <code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0773.Sliding%20Puzzle/images/slide1-grid.jpg" /></p>

<pre>
<strong>输入：</strong>board = [[1,2,3],[4,0,5]]
<strong>输出：</strong>1
<strong>解释：</strong>交换 0 和 5 ，1 步完成
</pre>

<p><strong>示例 2:</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0773.Sliding%20Puzzle/images/slide2-grid.jpg" /></p>

<pre>
<strong>输入：</strong>board = [[1,2,3],[5,4,0]]
<strong>输出：</strong>-1
<strong>解释：</strong>没有办法完成谜板
</pre>

<p><strong>示例 3:</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0773.Sliding%20Puzzle/images/slide3-grid.jpg" /></p>

<pre>
<strong>输入：</strong>board = [[4,1,2],[5,0,3]]
<strong>输出：</strong>5
<strong>解释：</strong>
最少完成谜板的最少移动次数是 5 ，
一种移动路径:
尚未移动: [[4,1,2],[5,0,3]]
移动 1 次: [[4,1,2],[0,5,3]]
移动 2 次: [[0,1,2],[4,5,3]]
移动 3 次: [[1,0,2],[4,5,3]]
移动 4 次: [[1,2,0],[4,5,3]]
移动 5 次: [[1,2,3],[4,5,0]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>board.length == 2</code></li>
	<li><code>board[i].length == 3</code></li>
	<li><code>0 &lt;= board[i][j] &lt;= 5</code></li>
	<li><code>board[i][j]</code>&nbsp;中每个值都 <strong>不同</strong></li>
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

#### Python3

```python
class Solution:
    def slidingPuzzle(self, board: List[List[int]]) -> int:
        t = [None] * 6

        def gets():
            for i in range(2):
                for j in range(3):
                    t[i * 3 + j] = str(board[i][j])
            return ''.join(t)

        def setb(s):
            for i in range(2):
                for j in range(3):
                    board[i][j] = int(s[i * 3 + j])

        def f():
            res = []
            i, j = next((i, j) for i in range(2) for j in range(3) if board[i][j] == 0)
            for a, b in [[0, -1], [0, 1], [1, 0], [-1, 0]]:
                x, y = i + a, j + b
                if 0 <= x < 2 and 0 <= y < 3:
                    board[i][j], board[x][y] = board[x][y], board[i][j]
                    res.append(gets())
                    board[i][j], board[x][y] = board[x][y], board[i][j]
            return res

        start = gets()
        end = "123450"
        if start == end:
            return 0
        vis = {start}
        q = deque([(start)])
        ans = 0
        while q:
            ans += 1
            for _ in range(len(q)):
                x = q.popleft()
                setb(x)
                for y in f():
                    if y == end:
                        return ans
                    if y not in vis:
                        vis.add(y)
                        q.append(y)
        return -1
```

#### Java

```java
class Solution {
    private String[] t = new String[6];
    private int[][] board;

    public int slidingPuzzle(int[][] board) {
        this.board = board;
        String start = gets();
        String end = "123450";
        if (end.equals(start)) {
            return 0;
        }
        Set<String> vis = new HashSet<>();
        Deque<String> q = new ArrayDeque<>();
        q.offer(start);
        vis.add(start);
        int ans = 0;
        while (!q.isEmpty()) {
            ++ans;
            for (int n = q.size(); n > 0; --n) {
                String x = q.poll();
                setb(x);
                for (String y : next()) {
                    if (y.equals(end)) {
                        return ans;
                    }
                    if (!vis.contains(y)) {
                        vis.add(y);
                        q.offer(y);
                    }
                }
            }
        }
        return -1;
    }

    private String gets() {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                t[i * 3 + j] = String.valueOf(board[i][j]);
            }
        }
        return String.join("", t);
    }

    private void setb(String s) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = s.charAt(i * 3 + j) - '0';
            }
        }
    }

    private int[] find0() {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == 0) {
                    return new int[] {i, j};
                }
            }
        }
        return new int[] {0, 0};
    }

    private List<String> next() {
        int[] p = find0();
        int i = p[0], j = p[1];
        int[] dirs = {-1, 0, 1, 0, -1};
        List<String> res = new ArrayList<>();
        for (int k = 0; k < 4; ++k) {
            int x = i + dirs[k];
            int y = j + dirs[k + 1];
            if (x >= 0 && x < 2 && y >= 0 && y < 3) {
                swap(i, j, x, y);
                res.add(gets());
                swap(i, j, x, y);
            }
        }
        return res;
    }

    private void swap(int i, int j, int x, int y) {
        int t = board[i][j];
        board[i][j] = board[x][y];
        board[x][y] = t;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = gets(board);
        string end = "123450";
        if (start == end) return 0;
        unordered_set<string> vis;
        vis.insert(start);
        queue<string> q{{start}};
        int ans = 0;
        while (!q.empty()) {
            ++ans;
            for (int n = q.size(); n > 0; --n) {
                string x = q.front();
                q.pop();
                setb(x, board);
                for (string y : next(board)) {
                    if (y == end) return ans;
                    if (!vis.count(y)) {
                        vis.insert(y);
                        q.push(y);
                    }
                }
            }
        }
        return -1;
    }

    string gets(vector<vector<int>>& board) {
        string s = "";
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 3; ++j)
                s.push_back('0' + board[i][j]);
        return s;
    }

    void setb(string s, vector<vector<int>>& board) {
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 3; ++j)
                board[i][j] = s[i * 3 + j] - '0';
    }

    vector<string> next(vector<vector<int>>& board) {
        vector<string> res;
        auto p = find0(board);
        int i = p.first, j = p.second;
        vector<int> dirs = {-1, 0, 1, 0, -1};
        for (int k = 0; k < 4; ++k) {
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x >= 0 && x < 2 && y >= 0 && y < 3) {
                swap(i, j, x, y, board);
                res.push_back(gets(board));
                swap(i, j, x, y, board);
            }
        }
        return res;
    }

    void swap(int i, int j, int x, int y, vector<vector<int>>& board) {
        int t = board[i][j];
        board[i][j] = board[x][y];
        board[x][y] = t;
    }

    pair<int, int> find0(vector<vector<int>>& board) {
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 3; ++j)
                if (board[i][j] == 0)
                    return {i, j};
        return {0, 0};
    }
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def slidingPuzzle(self, board: List[List[int]]) -> int:
        m, n = 2, 3
        seq = []
        start, end = '', '123450'
        for i in range(m):
            for j in range(n):
                if board[i][j] != 0:
                    seq.append(board[i][j])
                start += str(board[i][j])

        def check(seq):
            n = len(seq)
            cnt = sum(seq[i] > seq[j] for i in range(n) for j in range(i, n))
            return cnt % 2 == 0

        def f(s):
            ans = 0
            for i in range(m * n):
                if s[i] != '0':
                    num = ord(s[i]) - ord('1')
                    ans += abs(i // n - num // n) + abs(i % n - num % n)
            return ans

        if not check(seq):
            return -1
        q = [(f(start), start)]
        dist = {start: 0}
        while q:
            _, state = heappop(q)
            if state == end:
                return dist[state]
            p1 = state.index('0')
            i, j = p1 // n, p1 % n
            s = list(state)
            for a, b in [[0, -1], [0, 1], [1, 0], [-1, 0]]:
                x, y = i + a, j + b
                if 0 <= x < m and 0 <= y < n:
                    p2 = x * n + y
                    s[p1], s[p2] = s[p2], s[p1]
                    next = ''.join(s)
                    s[p1], s[p2] = s[p2], s[p1]
                    if next not in dist or dist[next] > dist[state] + 1:
                        dist[next] = dist[state] + 1
                        heappush(q, (dist[next] + f(next), next))
        return -1
```

#### Java

```java
class Solution {
    private int m = 2;
    private int n = 3;

    public int slidingPuzzle(int[][] board) {
        String start = "";
        String end = "123450";
        String seq = "";
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                start += board[i][j];
                if (board[i][j] != 0) {
                    seq += board[i][j];
                }
            }
        }
        if (!check(seq)) {
            return -1;
        }
        PriorityQueue<Pair<Integer, String>> q
            = new PriorityQueue<>(Comparator.comparingInt(Pair::getKey));
        Map<String, Integer> dist = new HashMap<>();
        dist.put(start, 0);
        q.offer(new Pair<>(f(start), start));
        int[] dirs = {-1, 0, 1, 0, -1};
        while (!q.isEmpty()) {
            String state = q.poll().getValue();
            int step = dist.get(state);
            if (end.equals(state)) {
                return step;
            }
            int p1 = state.indexOf("0");
            int i = p1 / n, j = p1 % n;
            char[] s = state.toCharArray();
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    int p2 = x * n + y;
                    swap(s, p1, p2);
                    String next = String.valueOf(s);
                    if (!dist.containsKey(next) || dist.get(next) > step + 1) {
                        dist.put(next, step + 1);
                        q.offer(new Pair<>(step + 1 + f(next), next));
                    }
                    swap(s, p1, p2);
                }
            }
        }
        return -1;
    }

    private void swap(char[] arr, int i, int j) {
        char t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }

    private int f(String s) {
        int ans = 0;
        for (int i = 0; i < m * n; ++i) {
            if (s.charAt(i) != '0') {
                int num = s.charAt(i) - '1';
                ans += Math.abs(i / n - num / n) + Math.abs(i % n - num % n);
            }
        }
        return ans;
    }

    private boolean check(String s) {
        int n = s.length();
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (s.charAt(i) > s.charAt(j)) {
                    ++cnt;
                }
            }
        }
        return cnt % 2 == 0;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int m = 2;
    int n = 3;

    int slidingPuzzle(vector<vector<int>>& board) {
        string start, seq;
        string end = "123450";
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                start += char(board[i][j] + '0');
                if (board[i][j] != 0) seq += char(board[i][j] + '0');
            }
        }
        if (!check(seq)) return -1;
        typedef pair<int, string> PIS;
        priority_queue<PIS, vector<PIS>, greater<PIS>> q;
        unordered_map<string, int> dist;
        dist[start] = 0;
        q.push({f(start), start});
        vector<int> dirs = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            PIS t = q.top();
            q.pop();
            string state = t.second;
            int step = dist[state];
            if (state == end) return step;
            int p1 = state.find('0');
            int i = p1 / n, j = p1 % n;
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x < 0 || x >= m || y < 0 || y >= n) continue;
                int p2 = x * n + y;
                swap(state[p1], state[p2]);
                if (!dist.count(state) || dist[state] > step + 1) {
                    dist[state] = step + 1;
                    q.push({step + 1 + f(state), state});
                }
                swap(state[p1], state[p2]);
            }
        }
        return -1;
    }

    bool check(string s) {
        int n = s.size();
        int cnt = 0;
        for (int i = 0; i < n; ++i)
            for (int j = i; j < n; ++j)
                if (s[i] > s[j])
                    ++cnt;
        return cnt % 2 == 0;
    }

    int f(string s) {
        int ans = 0;
        for (int i = 0; i < m * n; ++i) {
            if (s[i] == '0') continue;
            int num = s[i] - '1';
            ans += abs(num / n - i / n) + abs(num % n - i % n);
        }
        return ans;
    }
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [774. 最小化去加油站的最大距离 🔒](https://leetcode.cn/problems/minimize-max-distance-to-gas-station){#774}

{{< tabs "774" >}}

{{% tab "python" %}}
```python
class Solution:
    def minmaxGasDist(self, stations: List[int], k: int) -> float:
        def check(x):
            return sum(int((b - a) / x) for a, b in pairwise(stations)) <= k

        left, right = 0, 1e8
        while right - left > 1e-6:
            mid = (left + right) / 2
            if check(mid):
                right = mid
            else:
                left = mid
        return left
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public double minmaxGasDist(int[] stations, int k) {
        double left = 0, right = 1e8;
        while (right - left > 1e-6) {
            double mid = (left + right) / 2.0;
            if (check(mid, stations, k)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return left;
    }

    private boolean check(double x, int[] stations, int k) {
        int s = 0;
        for (int i = 0; i < stations.length - 1; ++i) {
            s += (int) ((stations[i + 1] - stations[i]) / x);
        }
        return s <= k;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int k) {
        double left = 0, right = 1e8;
        auto check = [&](double x) {
            int s = 0;
            for (int i = 0; i < stations.size() - 1; ++i) {
                s += (int) ((stations[i + 1] - stations[i]) / x);
            }
            return s <= k;
        };
        while (right - left > 1e-6) {
            double mid = (left + right) / 2.0;
            if (check(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return left;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minmaxGasDist(stations []int, k int) float64 {
	check := func(x float64) bool {
		s := 0
		for i, v := range stations[:len(stations)-1] {
			s += int(float64(stations[i+1]-v) / x)
		}
		return s <= k
	}
	var left, right float64 = 0, 1e8
	for right-left > 1e-6 {
		mid := (left + right) / 2.0
		if check(mid) {
			right = mid
		} else {
			left = mid
		}
	}
	return left
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>整数数组 <code>stations</code> 表示 <strong>水平数轴</strong> 上各个加油站的位置。给你一个整数 <code>k</code> 。</p>

<p>请你在数轴上增设 <code>k</code> 个加油站，新增加油站可以位于 <strong>水平数轴</strong> 上的任意位置，而不必放在整数位置上。</p>

<p>设 <code>penalty()</code> 是：增设 <code>k</code> 个新加油站后，<strong>相邻</strong> 两个加油站间的最大距离。</p>
请你返回 <code>penalty()</code><strong> </strong>可能的最小值。与实际答案误差在 <code>10<sup>-6</sup></code> 范围内的答案将被视作正确答案。

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>stations = [1,2,3,4,5,6,7,8,9,10], k = 9
<strong>输出：</strong>0.50000
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>stations = [23,24,36,39,46,56,57,65,84,98], k = 1
<strong>输出：</strong>14.00000
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>10 <= stations.length <= 2000</code></li>
	<li><code>0 <= stations[i] <= 10<sup>8</sup></code></li>
	<li><code>stations</code> 按 <strong>严格递增</strong> 顺序排列</li>
	<li><code>1 <= k <= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找（浮点数二分）

我们二分枚举相邻两个加油站间的距离，找到最小的距离，使得加油站的数量不超过 $k$。

时间复杂度 $O(n\log M)$。其中 $n$ 为加油站的数量；而 $M$ 为答案的范围，即 $10^8$ 除以答案的精度 $10^{-6}$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minmaxGasDist(self, stations: List[int], k: int) -> float:
        def check(x):
            return sum(int((b - a) / x) for a, b in pairwise(stations)) <= k

        left, right = 0, 1e8
        while right - left > 1e-6:
            mid = (left + right) / 2
            if check(mid):
                right = mid
            else:
                left = mid
        return left
```

#### Java

```java
class Solution {
    public double minmaxGasDist(int[] stations, int k) {
        double left = 0, right = 1e8;
        while (right - left > 1e-6) {
            double mid = (left + right) / 2.0;
            if (check(mid, stations, k)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return left;
    }

    private boolean check(double x, int[] stations, int k) {
        int s = 0;
        for (int i = 0; i < stations.length - 1; ++i) {
            s += (int) ((stations[i + 1] - stations[i]) / x);
        }
        return s <= k;
    }
}
```

#### C++

```cpp
class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int k) {
        double left = 0, right = 1e8;
        auto check = [&](double x) {
            int s = 0;
            for (int i = 0; i < stations.size() - 1; ++i) {
                s += (int) ((stations[i + 1] - stations[i]) / x);
            }
            return s <= k;
        };
        while (right - left > 1e-6) {
            double mid = (left + right) / 2.0;
            if (check(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return left;
    }
};
```

#### Go

```go
func minmaxGasDist(stations []int, k int) float64 {
	check := func(x float64) bool {
		s := 0
		for i, v := range stations[:len(stations)-1] {
			s += int(float64(stations[i+1]-v) / x)
		}
		return s <= k
	}
	var left, right float64 = 0, 1e8
	for right-left > 1e-6 {
		mid := (left + right) / 2.0
		if check(mid) {
			right = mid
		} else {
			left = mid
		}
	}
	return left
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [775. 全局倒置与局部倒置](https://leetcode.cn/problems/global-and-local-inversions){#775}

{{< tabs "775" >}}

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
    def isIdealPermutation(self, nums: List[int]) -> bool:
        n = len(nums)
        tree = BinaryIndexedTree(n)
        cnt = 0
        for i, v in enumerate(nums):
            cnt += i < n - 1 and v > nums[i + 1]
            cnt -= i - tree.query(v)
            if cnt < 0:
                return False
            tree.update(v + 1, 1)
        return True
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
    public boolean isIdealPermutation(int[] nums) {
        int n = nums.length;
        BinaryIndexedTree tree = new BinaryIndexedTree(n);
        int cnt = 0;
        for (int i = 0; i < n && cnt >= 0; ++i) {
            cnt += (i < n - 1 && nums[i] > nums[i + 1] ? 1 : 0);
            cnt -= (i - tree.query(nums[i]));
            tree.update(nums[i] + 1, 1);
        }
        return cnt == 0;
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
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        BinaryIndexedTree tree(n);
        long cnt = 0;
        for (int i = 0; i < n && ~cnt; ++i) {
            cnt += (i < n - 1 && nums[i] > nums[i + 1]);
            cnt -= (i - tree.query(nums[i]));
            tree.update(nums[i] + 1, 1);
        }
        return cnt == 0;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isIdealPermutation(nums []int) bool {
	n := len(nums)
	tree := newBinaryIndexedTree(n)
	cnt := 0
	for i, v := range nums {
		if i < n-1 && v > nums[i+1] {
			cnt++
		}
		cnt -= (i - tree.query(v))
		if cnt < 0 {
			break
		}
		tree.update(v+1, 1)
	}
	return cnt == 0
}

type BinaryIndexedTree struct {
	n int
	c []int
}

func newBinaryIndexedTree(n int) BinaryIndexedTree {
	c := make([]int, n+1)
	return BinaryIndexedTree{n, c}
}

func (this BinaryIndexedTree) update(x, delta int) {
	for x <= this.n {
		this.c[x] += delta
		x += x & -x
	}
}

func (this BinaryIndexedTree) query(x int) int {
	s := 0
	for x > 0 {
		s += this.c[x]
		x -= x & -x
	}
	return s
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个长度为 <code>n</code> 的整数数组 <code>nums</code> ，表示由范围 <code>[0, n - 1]</code> 内所有整数组成的一个排列。</p>

<p><strong>全局倒置</strong> 的数目等于满足下述条件不同下标对 <code>(i, j)</code> 的数目：</p>

<ul>
	<li><code>0 &lt;= i &lt; j &lt; n</code></li>
	<li><code>nums[i] &gt; nums[j]</code></li>
</ul>

<p><strong>局部倒置</strong> 的数目等于满足下述条件的下标 <code>i</code> 的数目：</p>

<ul>
	<li><code>0 &lt;= i &lt; n - 1</code></li>
	<li><code>nums[i] &gt; nums[i + 1]</code></li>
</ul>

<p>当数组 <code>nums</code> 中 <strong>全局倒置</strong> 的数量等于 <strong>局部倒置</strong> 的数量时，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,0,2]
<strong>输出：</strong>true
<strong>解释：</strong>有 1 个全局倒置，和 1 个局部倒置。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,0]
<strong>输出：</strong>false
<strong>解释：</strong>有 2 个全局倒置，和 1 个局部倒置。
</pre>

&nbsp;

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt; n</code></li>
	<li><code>nums</code> 中的所有整数 <strong>互不相同</strong></li>
	<li><code>nums</code> 是范围 <code>[0, n - 1]</code> 内所有数字组成的一个排列</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：维护前缀最大值

根据题意，我们可以发现，一个数组中的局部倒置一定是全局倒置，但是全局倒置不一定是局部倒置。也就是说，全局倒置的数量一定大于等于局部倒置的数量。

因此，我们枚举每个数 $nums[i]$，其中 $2 \leq i \leq n - 1$，维护前缀数组 $nums[0,..i-2]$ 中的最大值，记为 $mx$。如果存在 $mx$ 大于 $nums[i]$，则说明全局倒置的数量大于局部倒置的数量，返回 `false` 即可。

遍历结束后，返回 `true`。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为数组 `nums` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isIdealPermutation(self, nums: List[int]) -> bool:
        mx = 0
        for i in range(2, len(nums)):
            if (mx := max(mx, nums[i - 2])) > nums[i]:
                return False
        return True
```

#### Java

```java
class Solution {
    public boolean isIdealPermutation(int[] nums) {
        int mx = 0;
        for (int i = 2; i < nums.length; ++i) {
            mx = Math.max(mx, nums[i - 2]);
            if (mx > nums[i]) {
                return false;
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
    bool isIdealPermutation(vector<int>& nums) {
        int mx = 0;
        for (int i = 2; i < nums.size(); ++i) {
            mx = max(mx, nums[i - 2]);
            if (mx > nums[i]) return false;
        }
        return true;
    }
};
```

#### Go

```go
func isIdealPermutation(nums []int) bool {
	mx := 0
	for i := 2; i < len(nums); i++ {
		mx = max(mx, nums[i-2])
		if mx > nums[i] {
			return false
		}
	}
	return true
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：树状数组

这道题目实际上是一个“逆序对”问题。

局部倒置的数量等于相邻元素之间逆序对的个数，可以在遍历数组 `nums` 的过程中直接求出；而全局倒置的数量等于逆序对的个数，求解逆序对个数的一个常用做法是使用树状数组。

树状数组，也称作“二叉索引树”（Binary Indexed Tree）或 Fenwick 树。 它可以高效地实现如下两个操作：

1. 单点更新：即函数 `update(x, delta)`，把序列 $x$ 位置的数加上一个值 $delta$。时间复杂度 $O(\log n)$。
1. 前缀和查询：即函数 `query(x)`，查询序列 `[1,...x]` 区间的区间和，即位置 $x$ 的前缀和。时间复杂度 $O(\log n)$。

对于本题，我们定义一个变量 $cnt$ 记录局部倒置的数量与全局倒置的数量之差。如果遍历过程中，$cnt$ 的值小于 $0$，则说明全局倒置的数量大于局部倒置的数量，返回 `false` 即可。

时间复杂度 $O(n\times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 `nums` 的长度。

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
    def isIdealPermutation(self, nums: List[int]) -> bool:
        n = len(nums)
        tree = BinaryIndexedTree(n)
        cnt = 0
        for i, v in enumerate(nums):
            cnt += i < n - 1 and v > nums[i + 1]
            cnt -= i - tree.query(v)
            if cnt < 0:
                return False
            tree.update(v + 1, 1)
        return True
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
    public boolean isIdealPermutation(int[] nums) {
        int n = nums.length;
        BinaryIndexedTree tree = new BinaryIndexedTree(n);
        int cnt = 0;
        for (int i = 0; i < n && cnt >= 0; ++i) {
            cnt += (i < n - 1 && nums[i] > nums[i + 1] ? 1 : 0);
            cnt -= (i - tree.query(nums[i]));
            tree.update(nums[i] + 1, 1);
        }
        return cnt == 0;
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
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        BinaryIndexedTree tree(n);
        long cnt = 0;
        for (int i = 0; i < n && ~cnt; ++i) {
            cnt += (i < n - 1 && nums[i] > nums[i + 1]);
            cnt -= (i - tree.query(nums[i]));
            tree.update(nums[i] + 1, 1);
        }
        return cnt == 0;
    }
};
```

#### Go

```go
func isIdealPermutation(nums []int) bool {
	n := len(nums)
	tree := newBinaryIndexedTree(n)
	cnt := 0
	for i, v := range nums {
		if i < n-1 && v > nums[i+1] {
			cnt++
		}
		cnt -= (i - tree.query(v))
		if cnt < 0 {
			break
		}
		tree.update(v+1, 1)
	}
	return cnt == 0
}

type BinaryIndexedTree struct {
	n int
	c []int
}

func newBinaryIndexedTree(n int) BinaryIndexedTree {
	c := make([]int, n+1)
	return BinaryIndexedTree{n, c}
}

func (this BinaryIndexedTree) update(x, delta int) {
	for x <= this.n {
		this.c[x] += delta
		x += x & -x
	}
}

func (this BinaryIndexedTree) query(x int) int {
	s := 0
	for x > 0 {
		s += this.c[x]
		x -= x & -x
	}
	return s
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [776. 拆分二叉搜索树 🔒](https://leetcode.cn/problems/split-bst){#776}

{{< tabs "776" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def splitBST(
        self, root: Optional[TreeNode], target: int
    ) -> List[Optional[TreeNode]]:
        def dfs(root):
            if root is None:
                return [None, None]
            if root.val <= target:
                l, r = dfs(root.right)
                root.right = l
                return [root, r]
            else:
                l, r = dfs(root.left)
                root.left = r
                return [l, root]

        return dfs(root)
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
    private int t;

    public TreeNode[] splitBST(TreeNode root, int target) {
        t = target;
        return dfs(root);
    }

    private TreeNode[] dfs(TreeNode root) {
        if (root == null) {
            return new TreeNode[] {null, null};
        }
        if (root.val <= t) {
            TreeNode[] ans = dfs(root.right);
            root.right = ans[0];
            ans[0] = root;
            return ans;
        } else {
            TreeNode[] ans = dfs(root.left);
            root.left = ans[1];
            ans[1] = root;
            return ans;
        }
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
    int t;

    vector<TreeNode*> splitBST(TreeNode* root, int target) {
        t = target;
        return dfs(root);
    }

    vector<TreeNode*> dfs(TreeNode* root) {
        if (!root) return {nullptr, nullptr};
        if (root->val <= t) {
            auto ans = dfs(root->right);
            root->right = ans[0];
            ans[0] = root;
            return ans;
        } else {
            auto ans = dfs(root->left);
            root->left = ans[1];
            ans[1] = root;
            return ans;
        }
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
func splitBST(root *TreeNode, target int) []*TreeNode {
	if root == nil {
		return []*TreeNode{nil, nil}
	}
	if root.Val <= target {
		ans := splitBST(root.Right, target)
		root.Right = ans[0]
		ans[0] = root
		return ans
	} else {
		ans := splitBST(root.Left, target)
		root.Left = ans[1]
		ans[1] = root
		return ans
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
 * @param {number} target
 * @return {TreeNode[]}
 */
var splitBST = function (root, target) {
    let ans = [null, null];
    if (!root) {
        return ans;
    }
    if (root.val <= target) {
        ans = splitBST(root.right, target);
        root.right = ans[0];
        ans[0] = root;
    } else {
        ans = splitBST(root.left, target);
        root.left = ans[1];
        ans[1] = root;
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

<p>给你一棵二叉搜索树（BST）的根结点 <code>root</code>&nbsp;和一个整数 <code>target</code> 。请将该树按要求拆分为两个子树：其中第一个子树结点的值都必须小于等于给定的目标值；另一个子树结点的值都必须大于目标值；树中并非一定要存在值为&nbsp;<code>target</code>&nbsp;的结点。</p>

<p>除此之外，树中大部分结构都需要保留，也就是说原始树中父节点 <code>p</code> 的任意子节点 <code>c</code> ，假如拆分后它们仍在同一个子树中，那么结点 <code>p</code>&nbsp;应仍为 <code>c</code>&nbsp;的父结点。</p>

<p>按顺序返回 <em>两个子树的根结点的数组</em> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0776.Split%20BST/images/split-tree.jpg" style="height: 193px; width: 600px;" /></p>

<pre>
<strong>输入：</strong>root = [4,2,6,1,3,5,7], target = 2
<strong>输出：</strong>[[2,1],[4,3,6,null,null,5,7]]
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> root = [1], target = 1
<strong>输出:</strong> [[1],[]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>二叉搜索树节点个数在&nbsp;<code>[1, 50]</code>&nbsp;范围内</li>
	<li><code>0 &lt;= Node.val, target &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归

判断 `root` 节点的情况：

-   若 `root` 为空，直接返回 `[null, null]`；
-   若 `root.val <= target`，说明 `root` 及其左孩子所有节点的值均小于等于 `target`，那么我们递归 `root.right`，得到 `ans`。然后将 `root.right` 指向 `ans[0]`，最后返回 `[root, ans[1]]`；
-   若 `root.val > target`，说明 `root` 及其右孩子所有节点的值均大于 `target`，那么我们递归 `root.left`，得到 `ans`。然后将 `root.left` 指向 `ans[1]`，最后返回 `[ans[0], root]`。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是二叉搜索树的节点个数。

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
    def splitBST(
        self, root: Optional[TreeNode], target: int
    ) -> List[Optional[TreeNode]]:
        def dfs(root):
            if root is None:
                return [None, None]
            if root.val <= target:
                l, r = dfs(root.right)
                root.right = l
                return [root, r]
            else:
                l, r = dfs(root.left)
                root.left = r
                return [l, root]

        return dfs(root)
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
    private int t;

    public TreeNode[] splitBST(TreeNode root, int target) {
        t = target;
        return dfs(root);
    }

    private TreeNode[] dfs(TreeNode root) {
        if (root == null) {
            return new TreeNode[] {null, null};
        }
        if (root.val <= t) {
            TreeNode[] ans = dfs(root.right);
            root.right = ans[0];
            ans[0] = root;
            return ans;
        } else {
            TreeNode[] ans = dfs(root.left);
            root.left = ans[1];
            ans[1] = root;
            return ans;
        }
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
    int t;

    vector<TreeNode*> splitBST(TreeNode* root, int target) {
        t = target;
        return dfs(root);
    }

    vector<TreeNode*> dfs(TreeNode* root) {
        if (!root) return {nullptr, nullptr};
        if (root->val <= t) {
            auto ans = dfs(root->right);
            root->right = ans[0];
            ans[0] = root;
            return ans;
        } else {
            auto ans = dfs(root->left);
            root->left = ans[1];
            ans[1] = root;
            return ans;
        }
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
func splitBST(root *TreeNode, target int) []*TreeNode {
	if root == nil {
		return []*TreeNode{nil, nil}
	}
	if root.Val <= target {
		ans := splitBST(root.Right, target)
		root.Right = ans[0]
		ans[0] = root
		return ans
	} else {
		ans := splitBST(root.Left, target)
		root.Left = ans[1]
		ans[1] = root
		return ans
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
 * @param {number} target
 * @return {TreeNode[]}
 */
var splitBST = function (root, target) {
    let ans = [null, null];
    if (!root) {
        return ans;
    }
    if (root.val <= target) {
        ans = splitBST(root.right, target);
        root.right = ans[0];
        ans[0] = root;
    } else {
        ans = splitBST(root.left, target);
        root.left = ans[1];
        ans[1] = root;
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [777. 在 LR 字符串中交换相邻字符](https://leetcode.cn/problems/swap-adjacent-in-lr-string){#777}

{{< tabs "777" >}}

{{% tab "python" %}}
```python
class Solution:
    def canTransform(self, start: str, end: str) -> bool:
        n = len(start)
        i = j = 0
        while 1:
            while i < n and start[i] == 'X':
                i += 1
            while j < n and end[j] == 'X':
                j += 1
            if i >= n and j >= n:
                return True
            if i >= n or j >= n or start[i] != end[j]:
                return False
            if start[i] == 'L' and i < j:
                return False
            if start[i] == 'R' and i > j:
                return False
            i, j = i + 1, j + 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean canTransform(String start, String end) {
        int n = start.length();
        int i = 0, j = 0;
        while (true) {
            while (i < n && start.charAt(i) == 'X') {
                ++i;
            }
            while (j < n && end.charAt(j) == 'X') {
                ++j;
            }
            if (i == n && j == n) {
                return true;
            }
            if (i == n || j == n || start.charAt(i) != end.charAt(j)) {
                return false;
            }
            if (start.charAt(i) == 'L' && i < j || start.charAt(i) == 'R' && i > j) {
                return false;
            }
            ++i;
            ++j;
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool canTransform(string start, string end) {
        int n = start.size();
        int i = 0, j = 0;
        while (true) {
            while (i < n && start[i] == 'X') ++i;
            while (j < n && end[j] == 'X') ++j;
            if (i == n && j == n) return true;
            if (i == n || j == n || start[i] != end[j]) return false;
            if (start[i] == 'L' && i < j) return false;
            if (start[i] == 'R' && i > j) return false;
            ++i;
            ++j;
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func canTransform(start string, end string) bool {
	n := len(start)
	i, j := 0, 0
	for {
		for i < n && start[i] == 'X' {
			i++
		}
		for j < n && end[j] == 'X' {
			j++
		}
		if i == n && j == n {
			return true
		}
		if i == n || j == n || start[i] != end[j] {
			return false
		}
		if start[i] == 'L' && i < j {
			return false
		}
		if start[i] == 'R' && i > j {
			return false
		}
		i, j = i+1, j+1
	}
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>在一个由 <code>'L'</code> , <code>'R'</code> 和 <code>'X'</code> 三个字符组成的字符串（例如<code>"RXXLRXRXL"</code>）中进行移动操作。一次移动操作指用一个&nbsp;<code>"LX"</code>&nbsp;替换一个&nbsp;<code>"XL"</code>，或者用一个&nbsp;<code>"XR"</code>&nbsp;替换一个&nbsp;<code>"RX"</code>。现给定起始字符串&nbsp;<code>start</code>&nbsp;和结束字符串&nbsp;<code>result</code>，请编写代码，当且仅当存在一系列移动操作使得&nbsp;<code>start</code>&nbsp;可以转换成&nbsp;<code>result</code>&nbsp;时， 返回&nbsp;<code>True</code>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>start = "RXXLRXRXL", result = "XRLXXRRLX"
<strong>输出：</strong>true
<strong>解释：</strong>通过以下步骤我们可以将 start 转化为 result：
RXXLRXRXL -&gt;
XRXLRXRXL -&gt;
XRLXRXRXL -&gt;
XRLXXRRXL -&gt;
XRLXXRRLX
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>start = "X", result = "L"
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= start.length&nbsp;&lt;= 10<sup>4</sup></code></li>
	<li><code>start.length == result.length</code></li>
	<li><code>start</code> 和&nbsp;<code>result</code>&nbsp;都只包含&nbsp;<code>'L'</code>, <code>'R'</code>&nbsp;或&nbsp;<code>'X'</code>。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

替换操作实际上是将 `L` 往左移动（`L` 左边为 `X` 时才能移动），`R` 往右移动（`R` 右边是 `X` 时才能移动），但 `L` 无法穿过 `R`。所以，如果去掉 `start` 和 `end` 中的所有 `X`，剩下的字符应该是相同的，否则返回 `false`。

双指针遍历 `start` 和 `end`：

-   如果当前字符为 `L` 且 $i\lt j$，那么这个 `L` 无法向右移动，返回 `false`；
-   如果当前字符为 `R` 且 $i\gt j$，那么这个 `R` 无法向左移动，返回 `false`。

如果双指针均遍历到末尾，返回 `true`。

时间复杂度 $O(n)$，其中 $n$ 表示字符串 `start` 或 `end` 的长度。

相似题目：

-   [2337. 移动片段得到字符串](https://github.com/doocs/leetcode/blob/main/solution/2300-2399/2337.Move%20Pieces%20to%20Obtain%20a%20String/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canTransform(self, start: str, end: str) -> bool:
        n = len(start)
        i = j = 0
        while 1:
            while i < n and start[i] == 'X':
                i += 1
            while j < n and end[j] == 'X':
                j += 1
            if i >= n and j >= n:
                return True
            if i >= n or j >= n or start[i] != end[j]:
                return False
            if start[i] == 'L' and i < j:
                return False
            if start[i] == 'R' and i > j:
                return False
            i, j = i + 1, j + 1
```

#### Java

```java
class Solution {
    public boolean canTransform(String start, String end) {
        int n = start.length();
        int i = 0, j = 0;
        while (true) {
            while (i < n && start.charAt(i) == 'X') {
                ++i;
            }
            while (j < n && end.charAt(j) == 'X') {
                ++j;
            }
            if (i == n && j == n) {
                return true;
            }
            if (i == n || j == n || start.charAt(i) != end.charAt(j)) {
                return false;
            }
            if (start.charAt(i) == 'L' && i < j || start.charAt(i) == 'R' && i > j) {
                return false;
            }
            ++i;
            ++j;
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool canTransform(string start, string end) {
        int n = start.size();
        int i = 0, j = 0;
        while (true) {
            while (i < n && start[i] == 'X') ++i;
            while (j < n && end[j] == 'X') ++j;
            if (i == n && j == n) return true;
            if (i == n || j == n || start[i] != end[j]) return false;
            if (start[i] == 'L' && i < j) return false;
            if (start[i] == 'R' && i > j) return false;
            ++i;
            ++j;
        }
    }
};
```

#### Go

```go
func canTransform(start string, end string) bool {
	n := len(start)
	i, j := 0, 0
	for {
		for i < n && start[i] == 'X' {
			i++
		}
		for j < n && end[j] == 'X' {
			j++
		}
		if i == n && j == n {
			return true
		}
		if i == n || j == n || start[i] != end[j] {
			return false
		}
		if start[i] == 'L' && i < j {
			return false
		}
		if start[i] == 'R' && i > j {
			return false
		}
		i, j = i+1, j+1
	}
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [778. 水位上升的泳池中游泳](https://leetcode.cn/problems/swim-in-rising-water){#778}

{{< tabs "778" >}}

{{% tab "python" %}}
```python
class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        def find(x):
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        n = len(grid)
        p = list(range(n * n))
        hi = [0] * (n * n)
        for i, row in enumerate(grid):
            for j, h in enumerate(row):
                hi[h] = i * n + j
        for t in range(n * n):
            i, j = hi[t] // n, hi[t] % n
            for a, b in [(0, -1), (0, 1), (1, 0), (-1, 0)]:
                x, y = i + a, j + b
                if 0 <= x < n and 0 <= y < n and grid[x][y] <= t:
                    p[find(x * n + y)] = find(hi[t])
                if find(0) == find(n * n - 1):
                    return t
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] p;

    public int swimInWater(int[][] grid) {
        int n = grid.length;
        p = new int[n * n];
        for (int i = 0; i < p.length; ++i) {
            p[i] = i;
        }
        int[] hi = new int[n * n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                hi[grid[i][j]] = i * n + j;
            }
        }
        int[] dirs = {-1, 0, 1, 0, -1};
        for (int t = 0; t < n * n; ++t) {
            int i = hi[t] / n;
            int j = hi[t] % n;
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k];
                int y = j + dirs[k + 1];
                if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] <= t) {
                    p[find(x * n + y)] = find(i * n + j);
                }
                if (find(0) == find(n * n - 1)) {
                    return t;
                }
            }
        }
        return -1;
    }

    private int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> p;

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        p.resize(n * n);
        for (int i = 0; i < p.size(); ++i) p[i] = i;
        vector<int> hi(n * n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                hi[grid[i][j]] = i * n + j;
        vector<int> dirs = {-1, 0, 1, 0, -1};
        for (int t = 0; t < n * n; ++t) {
            int i = hi[t] / n, j = hi[t] % n;
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] <= t)
                    p[find(x * n + y)] = find(hi[t]);
                if (find(0) == find(n * n - 1)) return t;
            }
        }
        return -1;
    }

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func swimInWater(grid [][]int) int {
	n := len(grid)
	p := make([]int, n*n)
	for i := range p {
		p[i] = i
	}
	hi := make([]int, n*n)
	for i, row := range grid {
		for j, h := range row {
			hi[h] = i*n + j
		}
	}
	var find func(x int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	dirs := []int{-1, 0, 1, 0, -1}
	for t := 0; t < n*n; t++ {
		i, j := hi[t]/n, hi[t]%n
		for k := 0; k < 4; k++ {
			x, y := i+dirs[k], j+dirs[k+1]
			if x >= 0 && x < n && y >= 0 && y < n && grid[x][y] <= t {
				p[find(x*n+y)] = find(hi[t])
			}
			if find(0) == find(n*n-1) {
				return t
			}
		}
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function swimInWater(grid: number[][]): number {
    const m = grid.length,
        n = grid[0].length;
    let visited = Array.from({ length: m }, () => new Array(n).fill(false));
    let ans = 0;
    let stack = [[0, 0, grid[0][0]]];
    const dir = [
        [0, 1],
        [0, -1],
        [1, 0],
        [-1, 0],
    ];

    while (stack.length) {
        let [i, j] = stack.shift();
        ans = Math.max(grid[i][j], ans);
        if (i == m - 1 && j == n - 1) break;
        for (let [dx, dy] of dir) {
            let x = i + dx,
                y = j + dy;
            if (x < m && x > -1 && y < n && y > -1 && !visited[x][y]) {
                visited[x][y] = true;
                stack.push([x, y, grid[x][y]]);
            }
        }
        stack.sort((a, b) => a[2] - b[2]);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
const DIR: [(i32, i32); 4] = [(-1, 0), (1, 0), (0, -1), (0, 1)];

impl Solution {
    #[allow(dead_code)]
    pub fn swim_in_water(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let m = grid[0].len();
        let mut ret_time = 0;
        let mut disjoint_set: Vec<usize> = vec![0; n * m];

        // Initialize the disjoint set
        for i in 0..n * m {
            disjoint_set[i] = i;
        }

        loop {
            if Self::check_and_union(&grid, &mut disjoint_set, ret_time) {
                break;
            }
            // Otherwise, keep checking
            ret_time += 1;
        }

        ret_time
    }

    #[allow(dead_code)]
    fn check_and_union(grid: &Vec<Vec<i32>>, d_set: &mut Vec<usize>, cur_time: i32) -> bool {
        let n = grid.len();
        let m = grid[0].len();

        for i in 0..n {
            for j in 0..m {
                if grid[i][j] != cur_time {
                    continue;
                }
                // Otherwise, let's union the square with its neighbors
                for (dx, dy) in DIR {
                    let x = dx + (i as i32);
                    let y = dy + (j as i32);
                    if Self::check_bounds(x, y, n as i32, m as i32)
                        && grid[x as usize][y as usize] <= cur_time
                    {
                        Self::union(i * m + j, (x as usize) * m + (y as usize), d_set);
                    }
                }
            }
        }

        Self::find(0, d_set) == Self::find(n * m - 1, d_set)
    }

    #[allow(dead_code)]
    fn find(x: usize, d_set: &mut Vec<usize>) -> usize {
        if d_set[x] != x {
            d_set[x] = Self::find(d_set[x], d_set);
        }
        d_set[x]
    }

    #[allow(dead_code)]
    fn union(x: usize, y: usize, d_set: &mut Vec<usize>) {
        let p_x = Self::find(x, d_set);
        let p_y = Self::find(y, d_set);
        d_set[p_x] = p_y;
    }

    #[allow(dead_code)]
    fn check_bounds(i: i32, j: i32, n: i32, m: i32) -> bool {
        i >= 0 && i < n && j >= 0 && j < m
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>在一个 <code>n x n</code>&nbsp;的整数矩阵&nbsp;<code>grid</code> 中，每一个方格的值 <code>grid[i][j]</code> 表示位置 <code>(i, j)</code> 的平台高度。</p>

<p>当开始下雨时，在时间为&nbsp;<code>t</code>&nbsp;时，水池中的水位为&nbsp;<code>t</code>&nbsp;。你可以从一个平台游向四周相邻的任意一个平台，但是前提是此时水位必须同时淹没这两个平台。假定你可以瞬间移动无限距离，也就是默认在方格内部游动是不耗时的。当然，在你游泳的时候你必须待在坐标方格里面。</p>

<p>你从坐标方格的左上平台&nbsp;<code>(0，0)</code> 出发。返回 <em>你到达坐标方格的右下平台&nbsp;<code>(n-1, n-1)</code>&nbsp;所需的最少时间 。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0778.Swim%20in%20Rising%20Water/images/swim1-grid.jpg" /></p>

<pre>
<strong>输入:</strong> grid = [[0,2],[1,3]]
<strong>输出:</strong> 3
<strong>解释:</strong>
时间为0时，你位于坐标方格的位置为 <code>(0, 0)。</code>
此时你不能游向任意方向，因为四个相邻方向平台的高度都大于当前时间为 0 时的水位。
等时间到达 3 时，你才可以游向平台 (1, 1). 因为此时的水位是 3，坐标方格中的平台没有比水位 3 更高的，所以你可以游向坐标方格中的任意位置
</pre>

<p><strong>示例 2:</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0778.Swim%20in%20Rising%20Water/images/swim2-grid-1.jpg" /></p>

<pre>
<strong>输入:</strong> grid = [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
<strong>输出:</strong> 16
<strong>解释: </strong>最终的路线用加粗进行了标记。
我们必须等到时间为 16，此时才能保证平台 (0, 0) 和 (4, 4) 是连通的
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>n == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 50</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;&nbsp;n<sup>2</sup></code></li>
	<li><code>grid[i][j]</code>&nbsp;中每个值&nbsp;<strong>均无重复</strong></li>
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

#### Python3

```python
class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        def find(x):
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        n = len(grid)
        p = list(range(n * n))
        hi = [0] * (n * n)
        for i, row in enumerate(grid):
            for j, h in enumerate(row):
                hi[h] = i * n + j
        for t in range(n * n):
            i, j = hi[t] // n, hi[t] % n
            for a, b in [(0, -1), (0, 1), (1, 0), (-1, 0)]:
                x, y = i + a, j + b
                if 0 <= x < n and 0 <= y < n and grid[x][y] <= t:
                    p[find(x * n + y)] = find(hi[t])
                if find(0) == find(n * n - 1):
                    return t
        return -1
```

#### Java

```java
class Solution {
    private int[] p;

    public int swimInWater(int[][] grid) {
        int n = grid.length;
        p = new int[n * n];
        for (int i = 0; i < p.length; ++i) {
            p[i] = i;
        }
        int[] hi = new int[n * n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                hi[grid[i][j]] = i * n + j;
            }
        }
        int[] dirs = {-1, 0, 1, 0, -1};
        for (int t = 0; t < n * n; ++t) {
            int i = hi[t] / n;
            int j = hi[t] % n;
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k];
                int y = j + dirs[k + 1];
                if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] <= t) {
                    p[find(x * n + y)] = find(i * n + j);
                }
                if (find(0) == find(n * n - 1)) {
                    return t;
                }
            }
        }
        return -1;
    }

    private int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> p;

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        p.resize(n * n);
        for (int i = 0; i < p.size(); ++i) p[i] = i;
        vector<int> hi(n * n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                hi[grid[i][j]] = i * n + j;
        vector<int> dirs = {-1, 0, 1, 0, -1};
        for (int t = 0; t < n * n; ++t) {
            int i = hi[t] / n, j = hi[t] % n;
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] <= t)
                    p[find(x * n + y)] = find(hi[t]);
                if (find(0) == find(n * n - 1)) return t;
            }
        }
        return -1;
    }

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
};
```

#### Go

```go
func swimInWater(grid [][]int) int {
	n := len(grid)
	p := make([]int, n*n)
	for i := range p {
		p[i] = i
	}
	hi := make([]int, n*n)
	for i, row := range grid {
		for j, h := range row {
			hi[h] = i*n + j
		}
	}
	var find func(x int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	dirs := []int{-1, 0, 1, 0, -1}
	for t := 0; t < n*n; t++ {
		i, j := hi[t]/n, hi[t]%n
		for k := 0; k < 4; k++ {
			x, y := i+dirs[k], j+dirs[k+1]
			if x >= 0 && x < n && y >= 0 && y < n && grid[x][y] <= t {
				p[find(x*n+y)] = find(hi[t])
			}
			if find(0) == find(n*n-1) {
				return t
			}
		}
	}
	return -1
}
```

#### TypeScript

```ts
function swimInWater(grid: number[][]): number {
    const m = grid.length,
        n = grid[0].length;
    let visited = Array.from({ length: m }, () => new Array(n).fill(false));
    let ans = 0;
    let stack = [[0, 0, grid[0][0]]];
    const dir = [
        [0, 1],
        [0, -1],
        [1, 0],
        [-1, 0],
    ];

    while (stack.length) {
        let [i, j] = stack.shift();
        ans = Math.max(grid[i][j], ans);
        if (i == m - 1 && j == n - 1) break;
        for (let [dx, dy] of dir) {
            let x = i + dx,
                y = j + dy;
            if (x < m && x > -1 && y < n && y > -1 && !visited[x][y]) {
                visited[x][y] = true;
                stack.push([x, y, grid[x][y]]);
            }
        }
        stack.sort((a, b) => a[2] - b[2]);
    }
    return ans;
}
```

#### Rust

```rust
const DIR: [(i32, i32); 4] = [(-1, 0), (1, 0), (0, -1), (0, 1)];

impl Solution {
    #[allow(dead_code)]
    pub fn swim_in_water(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let m = grid[0].len();
        let mut ret_time = 0;
        let mut disjoint_set: Vec<usize> = vec![0; n * m];

        // Initialize the disjoint set
        for i in 0..n * m {
            disjoint_set[i] = i;
        }

        loop {
            if Self::check_and_union(&grid, &mut disjoint_set, ret_time) {
                break;
            }
            // Otherwise, keep checking
            ret_time += 1;
        }

        ret_time
    }

    #[allow(dead_code)]
    fn check_and_union(grid: &Vec<Vec<i32>>, d_set: &mut Vec<usize>, cur_time: i32) -> bool {
        let n = grid.len();
        let m = grid[0].len();

        for i in 0..n {
            for j in 0..m {
                if grid[i][j] != cur_time {
                    continue;
                }
                // Otherwise, let's union the square with its neighbors
                for (dx, dy) in DIR {
                    let x = dx + (i as i32);
                    let y = dy + (j as i32);
                    if Self::check_bounds(x, y, n as i32, m as i32)
                        && grid[x as usize][y as usize] <= cur_time
                    {
                        Self::union(i * m + j, (x as usize) * m + (y as usize), d_set);
                    }
                }
            }
        }

        Self::find(0, d_set) == Self::find(n * m - 1, d_set)
    }

    #[allow(dead_code)]
    fn find(x: usize, d_set: &mut Vec<usize>) -> usize {
        if d_set[x] != x {
            d_set[x] = Self::find(d_set[x], d_set);
        }
        d_set[x]
    }

    #[allow(dead_code)]
    fn union(x: usize, y: usize, d_set: &mut Vec<usize>) {
        let p_x = Self::find(x, d_set);
        let p_y = Self::find(y, d_set);
        d_set[p_x] = p_y;
    }

    #[allow(dead_code)]
    fn check_bounds(i: i32, j: i32, n: i32, m: i32) -> bool {
        i >= 0 && i < n && j >= 0 && j < m
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [779. 第K个语法符号](https://leetcode.cn/problems/k-th-symbol-in-grammar){#779}

{{< tabs "779" >}}

{{% tab "python" %}}
```python
class Solution:
    def kthGrammar(self, n: int, k: int) -> int:
        return (k - 1).bit_count() & 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int kthGrammar(int n, int k) {
        return Integer.bitCount(k - 1) & 1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int kthGrammar(int n, int k) {
        return __builtin_popcount(k - 1) & 1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func kthGrammar(n int, k int) int {
	return bits.OnesCount(uint(k-1)) & 1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function kthGrammar(n: number, k: number): number {
    return bitCount(k - 1) & 1;
}

function bitCount(i: number): number {
    i = i - ((i >>> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >>> 2) & 0x33333333);
    i = (i + (i >>> 4)) & 0x0f0f0f0f;
    i = i + (i >>> 8);
    i = i + (i >>> 16);
    return i & 0x3f;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>我们构建了一个包含 <code>n</code> 行(&nbsp;<strong>索引从 1&nbsp; 开始&nbsp;</strong>)的表。首先在第一行我们写上一个 <code>0</code>。接下来的每一行，将前一行中的<code>0</code>替换为<code>01</code>，<code>1</code>替换为<code>10</code>。</p>

<ul>
	<li>例如，对于 <code>n = 3</code> ，第 <code>1</code> 行是 <code>0</code> ，第 <code>2</code> 行是 <code>01</code> ，第3行是 <code>0110</code> 。</li>
</ul>

<p>给定行数&nbsp;<code>n</code>&nbsp;和序数 <code>k</code>，返回第 <code>n</code> 行中第 <code>k</code>&nbsp;个字符。（&nbsp;<code>k</code>&nbsp;<strong>从索引 1 开始</strong>）</p>

<p><br />
<strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> n = 1, k = 1
<strong>输出:</strong> 0
<strong>解释: </strong>第一行：<u>0</u>
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> n = 2, k = 1
<strong>输出:</strong> 0
<strong>解释:</strong> 
第一行: 0 
第二行: <u>0</u>1
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> n = 2, k = 2
<strong>输出:</strong> 1
<strong>解释:</strong>
第一行: 0
第二行: 0<u>1</u>
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 30</code></li>
	<li><code>1 &lt;= k &lt;= 2<sup>n - 1</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归

我们先来看一下前几行的规律：

```
n = 1: 0
n = 2: 0 1
n = 3: 0 1 1 0
n = 4: 0 1 1 0 1 0 0 1
n = 5: 0 1 1 0 1 0 0 1 1 0 0 1 0 1 1 0
...
```

可以发现，每一行的前半部分和上一行完全一致，后半部分是上一行的反转。注意，这里的“反转”指的是 $0$ 变 $1$, $1$ 变 $0$。

如果 $k$ 在前半部分，那么第 $k$ 个字符就是上一行的第 $k$ 个字符，直接递归 $kthGrammar(n - 1, k)$ 即可。

如果 $k$ 在后半部分，那么第 $k$ 个字符就是上一行的第 $k - 2^{n - 2}$ 个字符的反转，即 $kthGrammar(n - 1, k - 2^{n - 2}) \oplus 1 $。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def kthGrammar(self, n: int, k: int) -> int:
        if n == 1:
            return 0
        if k <= (1 << (n - 2)):
            return self.kthGrammar(n - 1, k)
        return self.kthGrammar(n - 1, k - (1 << (n - 2))) ^ 1
```

#### Java

```java
class Solution {
    public int kthGrammar(int n, int k) {
        if (n == 1) {
            return 0;
        }
        if (k <= (1 << (n - 2))) {
            return kthGrammar(n - 1, k);
        }
        return kthGrammar(n - 1, k - (1 << (n - 2))) ^ 1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1) return 0;
        if (k <= (1 << (n - 2))) return kthGrammar(n - 1, k);
        return kthGrammar(n - 1, k - (1 << (n - 2))) ^ 1;
    }
};
```

#### Go

```go
func kthGrammar(n int, k int) int {
	if n == 1 {
		return 0
	}
	if k <= (1 << (n - 2)) {
		return kthGrammar(n-1, k)
	}
	return kthGrammar(n-1, k-(1<<(n-2))) ^ 1
}
```

#### TypeScript

```ts
function kthGrammar(n: number, k: number): number {
    if (n == 1) {
        return 0;
    }
    if (k <= 1 << (n - 2)) {
        return kthGrammar(n - 1, k);
    }
    return kthGrammar(n - 1, k - (1 << (n - 2))) ^ 1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：位运算 + 脑筋急转弯

题目中索引从 $1$ 开始，我们将 $k$ 改成 $k-1$，将索引转换为从 $0$ 开始。在接下来的讨论中，索引均从 $0$ 开始。

仔细观察，一行中的第 $i$ 个字符，会在第 $2i$ 和第 $2i+1$ 个位置产生两个字符。

```
0 1 1 0 1 0 0 1 1 0 0 1 0 1 1 0
```

如果第 $i$ 个字符是 $0$，那么在位置 $2i$ 和 $2i+1$ 产生的字符分别是 $0$ 和 $1$；如果第 $i$ 个字符是 $1$，产生的字符是 $1$ 和 $0$。

```
0 1 1 0 1 0 0 1 1 0 0 1 0 1 1 0
      ^     * *
```

```
0 1 1 0 1 0 0 1 1 0 0 1 0 1 1 0
        ^       * *
```

可以发现，第 $2i$ （偶数位）个字符总是和第 $i$ 个字符相同，而第 $2i+1$ （奇数位）个字符是第 $i$ 个字符的反转。也就是说，奇数位上的字符总是发生了一次反转而来的。反转偶数次，字符不变；反转奇数次，相当于反转了一次。

因此，我们只需要看 $k$ 这个数字是否是奇数，若是，累计一次反转。然后将 $k$ 除以 $2$，继续判断，并累计反转次数，直至 $k$ 为 $0$。

最后判断反转的次数是否为奇数，是则答案为 $1$，否则为 $0$。

以上累计反转次数的过程，实际上等价于求 $k$ 的二进制表示中，有多少位是 $1$。

时间复杂度 $O(\log k)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def kthGrammar(self, n: int, k: int) -> int:
        return (k - 1).bit_count() & 1
```

#### Java

```java
class Solution {
    public int kthGrammar(int n, int k) {
        return Integer.bitCount(k - 1) & 1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int kthGrammar(int n, int k) {
        return __builtin_popcount(k - 1) & 1;
    }
};
```

#### Go

```go
func kthGrammar(n int, k int) int {
	return bits.OnesCount(uint(k-1)) & 1
}
```

#### TypeScript

```ts
function kthGrammar(n: number, k: number): number {
    return bitCount(k - 1) & 1;
}

function bitCount(i: number): number {
    i = i - ((i >>> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >>> 2) & 0x33333333);
    i = (i + (i >>> 4)) & 0x0f0f0f0f;
    i = i + (i >>> 8);
    i = i + (i >>> 16);
    return i & 0x3f;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
