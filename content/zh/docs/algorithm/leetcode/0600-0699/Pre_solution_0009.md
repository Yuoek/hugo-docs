---
title: "0680_验证回文串 II"
date: 2025-10-08T18:36:23+08:00
weight: 9
tags: [二叉树, 前缀和, 动态规划, 单调队列, 双指针, 哈希表, 回溯, 图, 堆（优先队列）, 字符串, 字符串匹配, 并查集, 广度优先搜索, 数组, 有序集合, 枚举, 栈, 树, 树状数组, 模拟, 深度优先搜索, 滑动窗口, 线段树, 贪心, 队列]
---

{{< markmap >}}
### [0680_验证回文串 II](#680)
#### [贪心](#680)
#### [双指针](#680)
#### [字符串](#680)
### [0681_最近时刻 🔒](#681)
#### [哈希表](#681)
#### [字符串](#681)
#### [回溯](#681)
#### [枚举](#681)
### [0682_棒球比赛](#682)
#### [栈](#682)
#### [数组](#682)
#### [模拟](#682)
### [0683_K 个关闭的灯泡 🔒](#683)
#### [树状数组](#683)
#### [线段树](#683)
#### [队列](#683)
#### [数组](#683)
#### [有序集合](#683)
#### [滑动窗口](#683)
#### [单调队列](#683)
#### [堆（优先队列）](#683)
### [0684_冗余连接](#684)
#### [深度优先搜索](#684)
#### [广度优先搜索](#684)
#### [并查集](#684)
#### [图](#684)
### [0685_冗余连接 II](#685)
#### [深度优先搜索](#685)
#### [广度优先搜索](#685)
#### [并查集](#685)
#### [图](#685)
### [0686_重复叠加字符串匹配](#686)
#### [字符串](#686)
#### [字符串匹配](#686)
### [0687_最长同值路径](#687)
#### [树](#687)
#### [深度优先搜索](#687)
#### [二叉树](#687)
### [0688_骑士在棋盘上的概率](#688)
#### [动态规划](#688)
### [0689_三个无重叠子数组的最大和](#689)
#### [数组](#689)
#### [动态规划](#689)
#### [前缀和](#689)
#### [滑动窗口](#689)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0680_验证回文串 II
___
#### 贪心
___
#### 双指针
___
#### 字符串
---
### 0681_最近时刻 🔒
___
#### 哈希表
___
#### 字符串
___
#### 回溯
___
#### 枚举
---
### 0682_棒球比赛
___
#### 栈
___
#### 数组
___
#### 模拟
---
### 0683_K 个关闭的灯泡 🔒
___
#### 树状数组
___
#### 线段树
___
#### 队列
___
#### 数组
___
#### 有序集合
___
#### 滑动窗口
___
#### 单调队列
___
#### 堆（优先队列）
---
### 0684_冗余连接
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 并查集
___
#### 图
---
### 0685_冗余连接 II
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 并查集
___
#### 图
---
### 0686_重复叠加字符串匹配
___
#### 字符串
___
#### 字符串匹配
---
### 0687_最长同值路径
___
#### 树
___
#### 深度优先搜索
___
#### 二叉树
---
### 0688_骑士在棋盘上的概率
___
#### 动态规划
---
### 0689_三个无重叠子数组的最大和
___
#### 数组
___
#### 动态规划
___
#### 前缀和
___
#### 滑动窗口
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二叉树 | 前缀和 | 动态规划 |
| 单调队列 | 双指针 | 哈希表 |
| 回溯 | 图 | 堆（优先队列） |
| 字符串 | 字符串匹配 | 并查集 |
| 广度优先搜索 | 数组 | 有序集合 |
| 枚举 | 栈 | 树 |
| 树状数组 | 模拟 | 深度优先搜索 |
| 滑动窗口 | 线段树 | 贪心 |
| 队列 |  |  |

# [680. 验证回文串 II](https://leetcode.cn/problems/valid-palindrome-ii){#680}

{{< tabs "680" >}}

{{% tab "python" %}}
```python
class Solution:
    def validPalindrome(self, s: str) -> bool:
        def check(i, j):
            while i < j:
                if s[i] != s[j]:
                    return False
                i, j = i + 1, j - 1
            return True

        i, j = 0, len(s) - 1
        while i < j:
            if s[i] != s[j]:
                return check(i, j - 1) or check(i + 1, j)
            i, j = i + 1, j - 1
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private char[] s;

    public boolean validPalindrome(String S) {
        this.s = S.toCharArray();
        for (int i = 0, j = s.length - 1; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                return check(i + 1, j) || check(i, j - 1);
            }
        }
        return true;
    }

    private boolean check(int i, int j) {
        for (; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                return false;
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
    bool validPalindrome(string s) {
        auto check = [&](int i, int j) {
            for (; i < j; ++i, --j) {
                if (s[i] != s[j]) {
                    return false;
                }
            }
            return true;
        };
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                return check(i + 1, j) || check(i, j - 1);
            }
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func validPalindrome(s string) bool {
	check := func(i, j int) bool {
		for ; i < j; i, j = i+1, j-1 {
			if s[i] != s[j] {
				return false
			}
		}
		return true
	}
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		if s[i] != s[j] {
			return check(i+1, j) || check(i, j-1)
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function validPalindrome(s: string): boolean {
    const check = (i: number, j: number): boolean => {
        for (; i < j; ++i, --j) {
            if (s[i] !== s[j]) {
                return false;
            }
        }
        return true;
    };
    for (let i = 0, j = s.length - 1; i < j; ++i, --j) {
        if (s[i] !== s[j]) {
            return check(i + 1, j) || check(i, j - 1);
        }
    }
    return true;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} s
 * @return {boolean}
 */
var validPalindrome = function (s) {
    const check = function (i, j) {
        for (; i < j; ++i, --j) {
            if (s[i] !== s[j]) {
                return false;
            }
        }
        return true;
    };
    for (let i = 0, j = s.length - 1; i < j; ++i, --j) {
        if (s[i] !== s[j]) {
            return check(i + 1, j) || check(i, j - 1);
        }
    }
    return true;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public bool ValidPalindrome(string s) {
        int i = 0, j = s.Length - 1;
        while (i < j && s[i] == s[j]) {
            i++;
            j--;
        }
        if (i >= j) {
            return true;
        }
        return check(s, i + 1, j) || check(s, i, j - 1);
    }

    private bool check(string s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
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

<p>给你一个字符串&nbsp;<code>s</code>，<strong>最多</strong> 可以从中删除一个字符。</p>

<p>请你判断 <code>s</code> 是否能成为回文字符串：如果能，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "aba"
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "abca"
<strong>输出：</strong>true
<strong>解释：</strong>你可以删除字符 'c' 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "abc"
<strong>输出：</strong>false</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> 由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

我们用两个指针分别指向字符串的左右两端，每次判断两个指针指向的字符是否相同，如果不相同，则判断删除左指针对应的字符后字符串是否是回文字符串，或者判断删除右指针对应的字符后字符串是否是回文字符串。如果两个指针指向的字符相同，则将左右指针都往中间移动一位，直到两个指针相遇为止。

如果遍历结束，都没有遇到指针指向的字符不相同的情况，那么字符串本身就是一个回文字符串，返回 `true` 即可。

时间复杂度 $O(n)$，其中 $n$ 是字符串 $s$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def validPalindrome(self, s: str) -> bool:
        def check(i, j):
            while i < j:
                if s[i] != s[j]:
                    return False
                i, j = i + 1, j - 1
            return True

        i, j = 0, len(s) - 1
        while i < j:
            if s[i] != s[j]:
                return check(i, j - 1) or check(i + 1, j)
            i, j = i + 1, j - 1
        return True
```

#### Java

```java
class Solution {
    private char[] s;

    public boolean validPalindrome(String S) {
        this.s = S.toCharArray();
        for (int i = 0, j = s.length - 1; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                return check(i + 1, j) || check(i, j - 1);
            }
        }
        return true;
    }

    private boolean check(int i, int j) {
        for (; i < j; ++i, --j) {
            if (s[i] != s[j]) {
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
    bool validPalindrome(string s) {
        auto check = [&](int i, int j) {
            for (; i < j; ++i, --j) {
                if (s[i] != s[j]) {
                    return false;
                }
            }
            return true;
        };
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                return check(i + 1, j) || check(i, j - 1);
            }
        }
        return true;
    }
};
```

#### Go

```go
func validPalindrome(s string) bool {
	check := func(i, j int) bool {
		for ; i < j; i, j = i+1, j-1 {
			if s[i] != s[j] {
				return false
			}
		}
		return true
	}
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		if s[i] != s[j] {
			return check(i+1, j) || check(i, j-1)
		}
	}
	return true
}
```

#### TypeScript

```ts
function validPalindrome(s: string): boolean {
    const check = (i: number, j: number): boolean => {
        for (; i < j; ++i, --j) {
            if (s[i] !== s[j]) {
                return false;
            }
        }
        return true;
    };
    for (let i = 0, j = s.length - 1; i < j; ++i, --j) {
        if (s[i] !== s[j]) {
            return check(i + 1, j) || check(i, j - 1);
        }
    }
    return true;
}
```

#### JavaScript

```js
/**
 * @param {string} s
 * @return {boolean}
 */
var validPalindrome = function (s) {
    const check = function (i, j) {
        for (; i < j; ++i, --j) {
            if (s[i] !== s[j]) {
                return false;
            }
        }
        return true;
    };
    for (let i = 0, j = s.length - 1; i < j; ++i, --j) {
        if (s[i] !== s[j]) {
            return check(i + 1, j) || check(i, j - 1);
        }
    }
    return true;
};
```

#### C#

```cs
public class Solution {
    public bool ValidPalindrome(string s) {
        int i = 0, j = s.Length - 1;
        while (i < j && s[i] == s[j]) {
            i++;
            j--;
        }
        if (i >= j) {
            return true;
        }
        return check(s, i + 1, j) || check(s, i, j - 1);
    }

    private bool check(string s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
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

# [681. 最近时刻 🔒](https://leetcode.cn/problems/next-closest-time){#681}

{{< tabs "681" >}}

{{% tab "python" %}}
```python
class Solution:
    def nextClosestTime(self, time: str) -> str:
        def check(t):
            h, m = int(t[:2]), int(t[2:])
            return 0 <= h < 24 and 0 <= m < 60

        def dfs(curr):
            if len(curr) == 4:
                if not check(curr):
                    return
                nonlocal ans, d
                p = int(curr[:2]) * 60 + int(curr[2:])
                if t < p < t + d:
                    d = p - t
                    ans = curr[:2] + ':' + curr[2:]
                return
            for c in s:
                dfs(curr + c)

        s = {c for c in time if c != ':'}
        t = int(time[:2]) * 60 + int(time[3:])
        d = inf
        ans = None
        dfs('')
        if ans is None:
            mi = min(int(c) for c in s)
            ans = f'{mi}{mi}:{mi}{mi}'
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int t;
    private int d;
    private String ans;
    private Set<Character> s;

    public String nextClosestTime(String time) {
        t = Integer.parseInt(time.substring(0, 2)) * 60 + Integer.parseInt(time.substring(3));
        d = Integer.MAX_VALUE;
        s = new HashSet<>();
        char mi = 'z';
        for (char c : time.toCharArray()) {
            if (c != ':') {
                s.add(c);
                if (c < mi) {
                    mi = c;
                }
            }
        }
        ans = null;
        dfs("");
        if (ans == null) {
            ans = "" + mi + mi + ":" + mi + mi;
        }
        return ans;
    }

    private void dfs(String curr) {
        if (curr.length() == 4) {
            if (!check(curr)) {
                return;
            }
            int p
                = Integer.parseInt(curr.substring(0, 2)) * 60 + Integer.parseInt(curr.substring(2));
            if (p > t && p - t < d) {
                d = p - t;
                ans = curr.substring(0, 2) + ":" + curr.substring(2);
            }
            return;
        }
        for (char c : s) {
            dfs(curr + c);
        }
    }

    private boolean check(String t) {
        int h = Integer.parseInt(t.substring(0, 2));
        int m = Integer.parseInt(t.substring(2));
        return 0 <= h && h < 24 && 0 <= m && m < 60;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个形如<meta charset="UTF-8" />&nbsp;<code>"HH:MM"</code> 表示的时刻<meta charset="UTF-8" />&nbsp;<code>time</code>&nbsp;，利用当前出现过的数字构造下一个距离当前时间最近的时刻。每个出现数字都可以被无限次使用。</p>

<p>你可以认为给定的字符串一定是合法的。例如，<meta charset="UTF-8" />&nbsp;<code>"01:34"</code> 和 <meta charset="UTF-8" />&nbsp;<code>"12:09"</code> 是合法的，<code>“1:34”</code> 和 <code>“12:9”</code> 是不合法的。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> "19:34"
<strong>输出:</strong> "19:39"
<strong>解释:</strong> 利用数字 <strong>1, 9, 3, 4</strong> 构造出来的最近时刻是 <strong>19:39</strong>，是 5 分钟之后。
结果不是 <strong>19:33</strong> 因为这个时刻是 23 小时 59 分钟之后。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> "23:59"
<strong>输出:</strong> "22:22"
<strong>解释:</strong> 利用数字 <strong>2, 3, 5, 9</strong> 构造出来的最近时刻是 <strong>22:22</strong>。 
答案一定是第二天的某一时刻，所以选择可构造的最小时刻。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<p><meta charset="UTF-8" /></p>

<ul>
	<li><code>time.length == 5</code></li>
	<li><code>time</code>&nbsp;为有效时间，格式为&nbsp;<code>"HH:MM"</code>.</li>
	<li><code>0 &lt;= HH &lt; 24</code></li>
	<li><code>0 &lt;= MM &lt; 60</code></li>
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
    def nextClosestTime(self, time: str) -> str:
        def check(t):
            h, m = int(t[:2]), int(t[2:])
            return 0 <= h < 24 and 0 <= m < 60

        def dfs(curr):
            if len(curr) == 4:
                if not check(curr):
                    return
                nonlocal ans, d
                p = int(curr[:2]) * 60 + int(curr[2:])
                if t < p < t + d:
                    d = p - t
                    ans = curr[:2] + ':' + curr[2:]
                return
            for c in s:
                dfs(curr + c)

        s = {c for c in time if c != ':'}
        t = int(time[:2]) * 60 + int(time[3:])
        d = inf
        ans = None
        dfs('')
        if ans is None:
            mi = min(int(c) for c in s)
            ans = f'{mi}{mi}:{mi}{mi}'
        return ans
```

#### Java

```java
class Solution {
    private int t;
    private int d;
    private String ans;
    private Set<Character> s;

    public String nextClosestTime(String time) {
        t = Integer.parseInt(time.substring(0, 2)) * 60 + Integer.parseInt(time.substring(3));
        d = Integer.MAX_VALUE;
        s = new HashSet<>();
        char mi = 'z';
        for (char c : time.toCharArray()) {
            if (c != ':') {
                s.add(c);
                if (c < mi) {
                    mi = c;
                }
            }
        }
        ans = null;
        dfs("");
        if (ans == null) {
            ans = "" + mi + mi + ":" + mi + mi;
        }
        return ans;
    }

    private void dfs(String curr) {
        if (curr.length() == 4) {
            if (!check(curr)) {
                return;
            }
            int p
                = Integer.parseInt(curr.substring(0, 2)) * 60 + Integer.parseInt(curr.substring(2));
            if (p > t && p - t < d) {
                d = p - t;
                ans = curr.substring(0, 2) + ":" + curr.substring(2);
            }
            return;
        }
        for (char c : s) {
            dfs(curr + c);
        }
    }

    private boolean check(String t) {
        int h = Integer.parseInt(t.substring(0, 2));
        int m = Integer.parseInt(t.substring(2));
        return 0 <= h && h < 24 && 0 <= m && m < 60;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [682. 棒球比赛](https://leetcode.cn/problems/baseball-game){#682}

{{< tabs "682" >}}

{{% tab "python" %}}
```python
class Solution:
    def calPoints(self, operations: List[str]) -> int:
        stk = []
        for op in operations:
            if op == "+":
                stk.append(stk[-1] + stk[-2])
            elif op == "D":
                stk.append(stk[-1] << 1)
            elif op == "C":
                stk.pop()
            else:
                stk.append(int(op))
        return sum(stk)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int calPoints(String[] operations) {
        Deque<Integer> stk = new ArrayDeque<>();
        for (String op : operations) {
            if ("+".equals(op)) {
                int a = stk.pop();
                int b = stk.peek();
                stk.push(a);
                stk.push(a + b);
            } else if ("D".equals(op)) {
                stk.push(stk.peek() << 1);
            } else if ("C".equals(op)) {
                stk.pop();
            } else {
                stk.push(Integer.valueOf(op));
            }
        }
        return stk.stream().mapToInt(Integer::intValue).sum();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> stk;
        for (auto& op : operations) {
            int n = stk.size();
            if (op == "+") {
                stk.push_back(stk[n - 1] + stk[n - 2]);
            } else if (op == "D") {
                stk.push_back(stk[n - 1] << 1);
            } else if (op == "C") {
                stk.pop_back();
            } else {
                stk.push_back(stoi(op));
            }
        }
        return accumulate(stk.begin(), stk.end(), 0);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func calPoints(operations []string) (ans int) {
	var stk []int
	for _, op := range operations {
		n := len(stk)
		switch op {
		case "+":
			stk = append(stk, stk[n-1]+stk[n-2])
		case "D":
			stk = append(stk, stk[n-1]*2)
		case "C":
			stk = stk[:n-1]
		default:
			num, _ := strconv.Atoi(op)
			stk = append(stk, num)
		}
	}
	for _, x := range stk {
		ans += x
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function calPoints(operations: string[]): number {
    const stk: number[] = [];
    for (const op of operations) {
        if (op === '+') {
            stk.push(stk.at(-1)! + stk.at(-2)!);
        } else if (op === 'D') {
            stk.push(stk.at(-1)! << 1);
        } else if (op === 'C') {
            stk.pop();
        } else {
            stk.push(+op);
        }
    }
    return stk.reduce((a, b) => a + b, 0);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn cal_points(operations: Vec<String>) -> i32 {
        let mut stk = vec![];
        for op in operations {
            match op.as_str() {
                "+" => {
                    let n = stk.len();
                    stk.push(stk[n - 1] + stk[n - 2]);
                }
                "D" => {
                    stk.push(stk.last().unwrap() * 2);
                }
                "C" => {
                    stk.pop();
                }
                n => {
                    stk.push(n.parse::<i32>().unwrap());
                }
            }
        }
        stk.into_iter().sum()
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你现在是一场采用特殊赛制棒球比赛的记录员。这场比赛由若干回合组成，过去几回合的得分可能会影响以后几回合的得分。</p>

<p>比赛开始时，记录是空白的。你会得到一个记录操作的字符串列表 <code>ops</code>，其中 <code>ops[i]</code> 是你需要记录的第 <code>i</code> 项操作，<code>ops</code> 遵循下述规则：</p>

<ol>
	<li>整数 <code>x</code> - 表示本回合新获得分数 <code>x</code></li>
	<li><code>"+"</code> - 表示本回合新获得的得分是前两次得分的总和。题目数据保证记录此操作时前面总是存在两个有效的分数。</li>
	<li><code>"D"</code> - 表示本回合新获得的得分是前一次得分的两倍。题目数据保证记录此操作时前面总是存在一个有效的分数。</li>
	<li><code>"C"</code> - 表示前一次得分无效，将其从记录中移除。题目数据保证记录此操作时前面总是存在一个有效的分数。</li>
</ol>

<p>请你返回记录中所有得分的总和。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>ops = ["5","2","C","D","+"]
<strong>输出：</strong>30
<strong>解释：</strong>
"5" - 记录加 5 ，记录现在是 [5]
"2" - 记录加 2 ，记录现在是 [5, 2]
"C" - 使前一次得分的记录无效并将其移除，记录现在是 [5].
"D" - 记录加 2 * 5 = 10 ，记录现在是 [5, 10].
"+" - 记录加 5 + 10 = 15 ，记录现在是 [5, 10, 15].
所有得分的总和 5 + 10 + 15 = 30
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>ops = ["5","-2","4","C","D","9","+","+"]
<strong>输出：</strong>27
<strong>解释：</strong>
"5" - 记录加 5 ，记录现在是 [5]
"-2" - 记录加 -2 ，记录现在是 [5, -2]
"4" - 记录加 4 ，记录现在是 [5, -2, 4]
"C" - 使前一次得分的记录无效并将其移除，记录现在是 [5, -2]
"D" - 记录加 2 * -2 = -4 ，记录现在是 [5, -2, -4]
"9" - 记录加 9 ，记录现在是 [5, -2, -4, 9]
"+" - 记录加 -4 + 9 = 5 ，记录现在是 [5, -2, -4, 9, 5]
"+" - 记录加 9 + 5 = 14 ，记录现在是 [5, -2, -4, 9, 5, 14]
所有得分的总和 5 + -2 + -4 + 9 + 5 + 14 = 27
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>ops = ["1"]
<strong>输出：</strong>1
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= ops.length <= 1000</code></li>
	<li><code>ops[i]</code> 为 <code>"C"</code>、<code>"D"</code>、<code>"+"</code>，或者一个表示整数的字符串。整数范围是 <code>[-3 * 10<sup>4</sup>, 3 * 10<sup>4</sup>]</code></li>
	<li>对于 <code>"+"</code> 操作，题目数据保证记录此操作时前面总是存在两个有效的分数</li>
	<li>对于 <code>"C"</code> 和 <code>"D"</code> 操作，题目数据保证记录此操作时前面总是存在一个有效的分数</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：栈 + 模拟

我们可以使用栈来模拟这个过程。

遍历 $\textit{operations}$，对于每个操作：

-   如果是 `+`，则将栈顶两个元素相加，然后将结果入栈；
-   如果是 `D`，则将栈顶元素的值乘以 2，然后将结果入栈；
-   如果是 `C`，则将栈顶元素出栈；
-   如果是数字，将数字入栈。

最后，将栈中的所有元素求和即为答案。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为 $\textit{operations}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def calPoints(self, operations: List[str]) -> int:
        stk = []
        for op in operations:
            if op == "+":
                stk.append(stk[-1] + stk[-2])
            elif op == "D":
                stk.append(stk[-1] << 1)
            elif op == "C":
                stk.pop()
            else:
                stk.append(int(op))
        return sum(stk)
```

#### Java

```java
class Solution {
    public int calPoints(String[] operations) {
        Deque<Integer> stk = new ArrayDeque<>();
        for (String op : operations) {
            if ("+".equals(op)) {
                int a = stk.pop();
                int b = stk.peek();
                stk.push(a);
                stk.push(a + b);
            } else if ("D".equals(op)) {
                stk.push(stk.peek() << 1);
            } else if ("C".equals(op)) {
                stk.pop();
            } else {
                stk.push(Integer.valueOf(op));
            }
        }
        return stk.stream().mapToInt(Integer::intValue).sum();
    }
}
```

#### C++

```cpp
class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> stk;
        for (auto& op : operations) {
            int n = stk.size();
            if (op == "+") {
                stk.push_back(stk[n - 1] + stk[n - 2]);
            } else if (op == "D") {
                stk.push_back(stk[n - 1] << 1);
            } else if (op == "C") {
                stk.pop_back();
            } else {
                stk.push_back(stoi(op));
            }
        }
        return accumulate(stk.begin(), stk.end(), 0);
    }
};
```

#### Go

```go
func calPoints(operations []string) (ans int) {
	var stk []int
	for _, op := range operations {
		n := len(stk)
		switch op {
		case "+":
			stk = append(stk, stk[n-1]+stk[n-2])
		case "D":
			stk = append(stk, stk[n-1]*2)
		case "C":
			stk = stk[:n-1]
		default:
			num, _ := strconv.Atoi(op)
			stk = append(stk, num)
		}
	}
	for _, x := range stk {
		ans += x
	}
	return
}
```

#### TypeScript

```ts
function calPoints(operations: string[]): number {
    const stk: number[] = [];
    for (const op of operations) {
        if (op === '+') {
            stk.push(stk.at(-1)! + stk.at(-2)!);
        } else if (op === 'D') {
            stk.push(stk.at(-1)! << 1);
        } else if (op === 'C') {
            stk.pop();
        } else {
            stk.push(+op);
        }
    }
    return stk.reduce((a, b) => a + b, 0);
}
```

#### Rust

```rust
impl Solution {
    pub fn cal_points(operations: Vec<String>) -> i32 {
        let mut stk = vec![];
        for op in operations {
            match op.as_str() {
                "+" => {
                    let n = stk.len();
                    stk.push(stk[n - 1] + stk[n - 2]);
                }
                "D" => {
                    stk.push(stk.last().unwrap() * 2);
                }
                "C" => {
                    stk.pop();
                }
                n => {
                    stk.push(n.parse::<i32>().unwrap());
                }
            }
        }
        stk.into_iter().sum()
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [683. K 个关闭的灯泡 🔒](https://leetcode.cn/problems/k-empty-slots){#683}

{{< tabs "683" >}}

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
    def kEmptySlots(self, bulbs: List[int], k: int) -> int:
        n = len(bulbs)
        tree = BinaryIndexedTree(n)
        vis = [False] * (n + 1)
        for i, x in enumerate(bulbs, 1):
            tree.update(x, 1)
            vis[x] = True
            y = x - k - 1
            if y > 0 and vis[y] and tree.query(x - 1) - tree.query(y) == 0:
                return i
            y = x + k + 1
            if y <= n and vis[y] and tree.query(y - 1) - tree.query(x) == 0:
                return i
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int kEmptySlots(int[] bulbs, int k) {
        int n = bulbs.length;
        BinaryIndexedTree tree = new BinaryIndexedTree(n);
        boolean[] vis = new boolean[n + 1];
        for (int i = 1; i <= n; ++i) {
            int x = bulbs[i - 1];
            tree.update(x, 1);
            vis[x] = true;
            int y = x - k - 1;
            if (y > 0 && vis[y] && tree.query(x - 1) - tree.query(y) == 0) {
                return i;
            }
            y = x + k + 1;
            if (y <= n && vis[y] && tree.query(y - 1) - tree.query(x) == 0) {
                return i;
            }
        }
        return -1;
    }
}

class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        this.c = new int[n + 1];
    }

    public void update(int x, int delta) {
        for (; x <= n; x += x & -x) {
            c[x] += delta;
        }
    }

    public int query(int x) {
        int s = 0;
        for (; x > 0; x -= x & -x) {
            s += c[x];
        }
        return s;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class BinaryIndexedTree {
public:
    int n;
    vector<int> c;

    BinaryIndexedTree(int _n)
        : n(_n)
        , c(_n + 1) {}

    void update(int x, int delta) {
        for (; x <= n; x += x & -x) {
            c[x] += delta;
        }
    }

    int query(int x) {
        int s = 0;
        for (; x; x -= x & -x) {
            s += c[x];
        }
        return s;
    }
};

class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        int n = bulbs.size();
        BinaryIndexedTree* tree = new BinaryIndexedTree(n);
        bool vis[n + 1];
        memset(vis, false, sizeof(vis));
        for (int i = 1; i <= n; ++i) {
            int x = bulbs[i - 1];
            tree->update(x, 1);
            vis[x] = true;
            int y = x - k - 1;
            if (y > 0 && vis[y] && tree->query(x - 1) - tree->query(y) == 0) {
                return i;
            }
            y = x + k + 1;
            if (y <= n && vis[y] && tree->query(y - 1) - tree->query(x) == 0) {
                return i;
            }
        }
        return -1;
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
	for ; x <= this.n; x += x & -x {
		this.c[x] += delta
	}
}

func (this *BinaryIndexedTree) query(x int) (s int) {
	for ; x > 0; x -= x & -x {
		s += this.c[x]
	}
	return
}

func kEmptySlots(bulbs []int, k int) int {
	n := len(bulbs)
	tree := newBinaryIndexedTree(n)
	vis := make([]bool, n+1)
	for i, x := range bulbs {
		tree.update(x, 1)
		vis[x] = true
		i++
		y := x - k - 1
		if y > 0 && vis[y] && tree.query(x-1)-tree.query(y) == 0 {
			return i
		}
		y = x + k + 1
		if y <= n && vis[y] && tree.query(y-1)-tree.query(x) == 0 {
			return i
		}
	}
	return -1
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

    public update(x: number, delta: number) {
        for (; x <= this.n; x += x & -x) {
            this.c[x] += delta;
        }
    }

    public query(x: number): number {
        let s = 0;
        for (; x > 0; x -= x & -x) {
            s += this.c[x];
        }
        return s;
    }
}

function kEmptySlots(bulbs: number[], k: number): number {
    const n = bulbs.length;
    const tree = new BinaryIndexedTree(n);
    const vis: boolean[] = Array(n + 1).fill(false);
    for (let i = 1; i <= n; ++i) {
        const x = bulbs[i - 1];
        tree.update(x, 1);
        vis[x] = true;
        let y = x - k - 1;
        if (y > 0 && vis[y] && tree.query(x - 1) - tree.query(y) === 0) {
            return i;
        }
        y = x + k + 1;
        if (y <= n && vis[y] && tree.query(y - 1) - tree.query(x) === 0) {
            return i;
        }
    }
    return -1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><code>n</code>&nbsp;个灯泡排成一行，编号从 <code>1</code> 到<meta charset="UTF-8" />&nbsp;<code>n</code>&nbsp;。最初，所有灯泡都关闭。每天&nbsp;<strong>只打开一个</strong>&nbsp;灯泡，直到<meta charset="UTF-8" />&nbsp;<code>n</code>&nbsp;天后所有灯泡都打开。</p>

<p>给你一个长度为<meta charset="UTF-8" />&nbsp;<code>n</code>&nbsp;的灯泡数组 <code>blubs</code> ，其中 <code>bulbs[i] = x</code> 意味着在第 <code>(i+1)</code> 天，我们会把在位置 <code>x</code> 的灯泡打开，其中 <code>i</code> <strong>从 0 开始</strong>，<code>x</code> <strong>从 1 开始</strong>。</p>

<p>给你一个整数<meta charset="UTF-8" />&nbsp;<code>k</code>&nbsp;，请返回<em>恰好有两个打开的灯泡，且它们中间 <strong>正好</strong> 有<meta charset="UTF-8" />&nbsp;<code>k</code>&nbsp;个&nbsp;<strong>全部关闭的</strong> 灯泡的 <strong>最小的天数</strong> </em>。<em>如果不存在这种情况，返回 <code>-1</code> 。</em></p>

<p>&nbsp;</p>

<p><b>示例 1：</b></p>

<pre>
<b>输入：</b>
bulbs = [1,3,2]，k = 1
<b>输出：</b>2
<b>解释：</b>
第一天 bulbs[0] = 1，打开第一个灯泡 [1,0,0]
第二天 bulbs[1] = 3，打开第三个灯泡 [1,0,1]
第三天 bulbs[2] = 2，打开第二个灯泡 [1,1,1]
返回2，因为在第二天，两个打开的灯泡之间恰好有一个关闭的灯泡。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>bulbs = [1,2,3]，k = 1
<strong>输出：</strong>-1
</pre>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<ul>
	<li><code>n == bulbs.length</code></li>
	<li><code>1 &lt;= n &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= bulbs[i] &lt;= n</code></li>
	<li><code>bulbs</code> 是一个由从 <code>1</code> 到 <code>n</code> 的数字构成的排列</li>
	<li><code>0 &lt;= k &lt;= 2 * 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：树状数组

我们可以使用树状数组来维护区间和，每一次打开灯泡，我们就在树状数组中更新对应位置的值，然后查询当前位置左边 $k$ 个灯泡是否都是关闭的，并且第 $k+1$ 个灯泡是否已经打开；或者查询当前位置右边 $k$ 个灯泡是否都是关闭的，并且第 $k+1$ 个灯泡是否已经打开。如果满足这两个条件之一，那么就说明当前位置是一个符合要求的位置，我们就可以返回当前的天数。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是灯泡的数量。

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
    def kEmptySlots(self, bulbs: List[int], k: int) -> int:
        n = len(bulbs)
        tree = BinaryIndexedTree(n)
        vis = [False] * (n + 1)
        for i, x in enumerate(bulbs, 1):
            tree.update(x, 1)
            vis[x] = True
            y = x - k - 1
            if y > 0 and vis[y] and tree.query(x - 1) - tree.query(y) == 0:
                return i
            y = x + k + 1
            if y <= n and vis[y] and tree.query(y - 1) - tree.query(x) == 0:
                return i
        return -1
```

#### Java

```java
class Solution {
    public int kEmptySlots(int[] bulbs, int k) {
        int n = bulbs.length;
        BinaryIndexedTree tree = new BinaryIndexedTree(n);
        boolean[] vis = new boolean[n + 1];
        for (int i = 1; i <= n; ++i) {
            int x = bulbs[i - 1];
            tree.update(x, 1);
            vis[x] = true;
            int y = x - k - 1;
            if (y > 0 && vis[y] && tree.query(x - 1) - tree.query(y) == 0) {
                return i;
            }
            y = x + k + 1;
            if (y <= n && vis[y] && tree.query(y - 1) - tree.query(x) == 0) {
                return i;
            }
        }
        return -1;
    }
}

class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        this.c = new int[n + 1];
    }

    public void update(int x, int delta) {
        for (; x <= n; x += x & -x) {
            c[x] += delta;
        }
    }

    public int query(int x) {
        int s = 0;
        for (; x > 0; x -= x & -x) {
            s += c[x];
        }
        return s;
    }
}
```

#### C++

```cpp
class BinaryIndexedTree {
public:
    int n;
    vector<int> c;

    BinaryIndexedTree(int _n)
        : n(_n)
        , c(_n + 1) {}

    void update(int x, int delta) {
        for (; x <= n; x += x & -x) {
            c[x] += delta;
        }
    }

    int query(int x) {
        int s = 0;
        for (; x; x -= x & -x) {
            s += c[x];
        }
        return s;
    }
};

class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        int n = bulbs.size();
        BinaryIndexedTree* tree = new BinaryIndexedTree(n);
        bool vis[n + 1];
        memset(vis, false, sizeof(vis));
        for (int i = 1; i <= n; ++i) {
            int x = bulbs[i - 1];
            tree->update(x, 1);
            vis[x] = true;
            int y = x - k - 1;
            if (y > 0 && vis[y] && tree->query(x - 1) - tree->query(y) == 0) {
                return i;
            }
            y = x + k + 1;
            if (y <= n && vis[y] && tree->query(y - 1) - tree->query(x) == 0) {
                return i;
            }
        }
        return -1;
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
	for ; x <= this.n; x += x & -x {
		this.c[x] += delta
	}
}

func (this *BinaryIndexedTree) query(x int) (s int) {
	for ; x > 0; x -= x & -x {
		s += this.c[x]
	}
	return
}

func kEmptySlots(bulbs []int, k int) int {
	n := len(bulbs)
	tree := newBinaryIndexedTree(n)
	vis := make([]bool, n+1)
	for i, x := range bulbs {
		tree.update(x, 1)
		vis[x] = true
		i++
		y := x - k - 1
		if y > 0 && vis[y] && tree.query(x-1)-tree.query(y) == 0 {
			return i
		}
		y = x + k + 1
		if y <= n && vis[y] && tree.query(y-1)-tree.query(x) == 0 {
			return i
		}
	}
	return -1
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

    public update(x: number, delta: number) {
        for (; x <= this.n; x += x & -x) {
            this.c[x] += delta;
        }
    }

    public query(x: number): number {
        let s = 0;
        for (; x > 0; x -= x & -x) {
            s += this.c[x];
        }
        return s;
    }
}

function kEmptySlots(bulbs: number[], k: number): number {
    const n = bulbs.length;
    const tree = new BinaryIndexedTree(n);
    const vis: boolean[] = Array(n + 1).fill(false);
    for (let i = 1; i <= n; ++i) {
        const x = bulbs[i - 1];
        tree.update(x, 1);
        vis[x] = true;
        let y = x - k - 1;
        if (y > 0 && vis[y] && tree.query(x - 1) - tree.query(y) === 0) {
            return i;
        }
        y = x + k + 1;
        if (y <= n && vis[y] && tree.query(y - 1) - tree.query(x) === 0) {
            return i;
        }
    }
    return -1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [684. 冗余连接](https://leetcode.cn/problems/redundant-connection){#684}

{{< tabs "684" >}}

{{% tab "python" %}}
```python
class UnionFind:
    __slots__ = "p", "size"

    def __init__(self, n: int):
        self.p: List[int] = list(range(n))
        self.size: List[int] = [1] * n

    def find(self, x: int) -> int:
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, a: int, b: int) -> bool:
        pa, pb = self.find(a), self.find(b)
        if pa == pb:
            return False
        if self.size[pa] > self.size[pb]:
            self.p[pb] = pa
            self.size[pa] += self.size[pb]
        else:
            self.p[pa] = pb
            self.size[pb] += self.size[pa]
        return True


class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        uf = UnionFind(len(edges))
        for a, b in edges:
            if not uf.union(a - 1, b - 1):
                return [a, b]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class UnionFind {
    private final int[] p;
    private final int[] size;

    public UnionFind(int n) {
        p = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            size[i] = 1;
        }
    }

    public int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    public boolean union(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }
}

class Solution {
    public int[] findRedundantConnection(int[][] edges) {
        UnionFind uf = new UnionFind(edges.length);
        for (int i = 0;; ++i) {
            if (!uf.union(edges[i][0] - 1, edges[i][1] - 1)) {
                return edges[i];
            }
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class UnionFind {
public:
    UnionFind(int n) {
        p = vector<int>(n);
        size = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    bool unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

private:
    vector<int> p, size;
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind uf(edges.size());
        for (int i = 0;; ++i) {
            if (!uf.unite(edges[i][0] - 1, edges[i][1] - 1)) {
                return edges[i];
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type unionFind struct {
	p, size []int
}

func newUnionFind(n int) *unionFind {
	p := make([]int, n)
	size := make([]int, n)
	for i := range p {
		p[i] = i
		size[i] = 1
	}
	return &unionFind{p, size}
}

func (uf *unionFind) find(x int) int {
	if uf.p[x] != x {
		uf.p[x] = uf.find(uf.p[x])
	}
	return uf.p[x]
}

func (uf *unionFind) union(a, b int) bool {
	pa, pb := uf.find(a), uf.find(b)
	if pa == pb {
		return false
	}
	if uf.size[pa] > uf.size[pb] {
		uf.p[pb] = pa
		uf.size[pa] += uf.size[pb]
	} else {
		uf.p[pa] = pb
		uf.size[pb] += uf.size[pa]
	}
	return true
}

func findRedundantConnection(edges [][]int) []int {
	uf := newUnionFind(len(edges))
	for i := 0; ; i++ {
		if !uf.union(edges[i][0]-1, edges[i][1]-1) {
			return edges[i]
		}
	}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class UnionFind {
    p: number[];
    size: number[];
    constructor(n: number) {
        this.p = Array.from({ length: n }, (_, i) => i);
        this.size = Array(n).fill(1);
    }

    find(x: number): number {
        if (this.p[x] !== x) {
            this.p[x] = this.find(this.p[x]);
        }
        return this.p[x];
    }

    union(a: number, b: number): boolean {
        const [pa, pb] = [this.find(a), this.find(b)];
        if (pa === pb) {
            return false;
        }
        if (this.size[pa] > this.size[pb]) {
            this.p[pb] = pa;
            this.size[pa] += this.size[pb];
        } else {
            this.p[pa] = pb;
            this.size[pb] += this.size[pa];
        }
        return true;
    }
}

function findRedundantConnection(edges: number[][]): number[] {
    const uf = new UnionFind(edges.length);
    for (let i = 0; ; ++i) {
        if (!uf.union(edges[i][0] - 1, edges[i][1] - 1)) {
            return edges[i];
        }
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
class UnionFind {
    constructor(n) {
        this.p = Array.from({ length: n }, (_, i) => i);
        this.size = Array(n).fill(1);
    }

    find(x) {
        if (this.p[x] !== x) {
            this.p[x] = this.find(this.p[x]);
        }
        return this.p[x];
    }

    union(a, b) {
        const pa = this.find(a);
        const pb = this.find(b);
        if (pa === pb) {
            return false;
        }
        if (this.size[pa] > this.size[pb]) {
            this.p[pb] = pa;
            this.size[pa] += this.size[pb];
        } else {
            this.p[pa] = pb;
            this.size[pb] += this.size[pa];
        }
        return true;
    }
}

/**
 * @param {number[][]} edges
 * @return {number[]}
 */
var findRedundantConnection = function (edges) {
    const uf = new UnionFind(edges.length);
    for (let i = 0; i < edges.length; i++) {
        if (!uf.union(edges[i][0] - 1, edges[i][1] - 1)) {
            return edges[i];
        }
    }
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>树可以看成是一个连通且 <strong>无环&nbsp;</strong>的&nbsp;<strong>无向&nbsp;</strong>图。</p>

<p>给定一个图，该图从一棵&nbsp;<code>n</code> 个节点 (节点值&nbsp;<code>1～n</code>) 的树中添加一条边后获得。添加的边的两个不同顶点编号在 <code>1</code> 到 <code>n</code>&nbsp;中间，且这条附加的边不属于树中已存在的边。图的信息记录于长度为 <code>n</code> 的二维数组 <code>edges</code>&nbsp;，<code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code>&nbsp;表示图中在 <code>ai</code> 和 <code>bi</code> 之间存在一条边。</p>

<p>请找出一条可以删去的边，删除后可使得剩余部分是一个有着 <code>n</code> 个节点的树。如果有多个答案，则返回数组&nbsp;<code>edges</code>&nbsp;中最后出现的那个。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0600-0699/0684.Redundant%20Connection/images/1626676174-hOEVUL-image.png" style="width: 152px; " /></p>

<pre>
<strong>输入:</strong> edges = [[1,2], [1,3], [2,3]]
<strong>输出:</strong> [2,3]
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0600-0699/0684.Redundant%20Connection/images/1626676179-kGxcmu-image.png" style="width: 250px; " /></p>

<pre>
<strong>输入:</strong> edges = [[1,2], [2,3], [3,4], [1,4], [1,5]]
<strong>输出:</strong> [1,4]
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>n == edges.length</code></li>
	<li><code>3 &lt;= n &lt;= 1000</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>1 &lt;= ai&nbsp;&lt; bi&nbsp;&lt;= edges.length</code></li>
	<li><code>ai != bi</code></li>
	<li><code>edges</code> 中无重复元素</li>
	<li>给定的图是连通的&nbsp;</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：并查集

根据题意，我们需要找到一条可以删去的边，删除后剩余部分是一个有着 $n$ 个节点的树。我们可以遍历每一条边，判断这条边是否在同一个连通分量中。如果在同一个连通分量中，则说明这条边是多余的，可以删除，直接返回这条边即可。否则，我们将这条边所连接的两个节点合并到同一个连通分量中。

时间复杂度 $O(n \log n)$，空间复杂度 $O(n)$。其中 $n$ 为边的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        def find(x: int) -> int:
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        p = list(range(len(edges)))
        for a, b in edges:
            pa, pb = find(a - 1), find(b - 1)
            if pa == pb:
                return [a, b]
            p[pa] = pb
```

#### Java

```java
class Solution {
    private int[] p;

    public int[] findRedundantConnection(int[][] edges) {
        int n = edges.length;
        p = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        for (int i = 0;; ++i) {
            int pa = find(edges[i][0] - 1);
            int pb = find(edges[i][1] - 1);
            if (pa == pb) {
                return edges[i];
            }
            p[pa] = pb;
        }
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        function<int(int)> find = [&](int x) {
            return x == p[x] ? x : p[x] = find(p[x]);
        };
        for (int i = 0;; ++i) {
            int pa = find(edges[i][0] - 1);
            int pb = find(edges[i][1] - 1);
            if (pa == pb) {
                return edges[i];
            }
            p[pa] = pb;
        }
    }
};
```

#### Go

```go
func findRedundantConnection(edges [][]int) []int {
	n := len(edges)
	p := make([]int, n)
	for i := range p {
		p[i] = i
	}
	var find func(int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	for i := 0; ; i++ {
		pa, pb := find(edges[i][0]-1), find(edges[i][1]-1)
		if pa == pb {
			return edges[i]
		}
		p[pa] = pb
	}
}
```

#### TypeScript

```ts
function findRedundantConnection(edges: number[][]): number[] {
    const n = edges.length;
    const p: number[] = Array.from({ length: n }, (_, i) => i);
    const find = (x: number): number => {
        if (p[x] !== x) {
            p[x] = find(p[x]);
        }
        return p[x];
    };
    for (let i = 0; ; ++i) {
        const pa = find(edges[i][0] - 1);
        const pb = find(edges[i][1] - 1);
        if (pa === pb) {
            return edges[i];
        }
        p[pa] = pb;
    }
}
```

#### JavaScript

```js
/**
 * @param {number[][]} edges
 * @return {number[]}
 */
var findRedundantConnection = function (edges) {
    const n = edges.length;
    const p = Array.from({ length: n }, (_, i) => i);
    const find = x => {
        if (p[x] !== x) {
            p[x] = find(p[x]);
        }
        return p[x];
    };
    for (let i = 0; ; ++i) {
        const pa = find(edges[i][0] - 1);
        const pb = find(edges[i][1] - 1);
        if (pa === pb) {
            return edges[i];
        }
        p[pa] = pb;
    }
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：并查集（模板做法）

这里给出一个并查集的模板做法，供大家参考。

时间复杂度 $O(n \alpha(n))$，空间复杂度 $O(n)$。其中 $n$ 为边的数量，而 $\alpha(n)$ 是阿克曼函数的反函数，可以认为是一个很小的常数。

<!-- tabs:start -->

#### Python3

```python
class UnionFind:
    __slots__ = "p", "size"

    def __init__(self, n: int):
        self.p: List[int] = list(range(n))
        self.size: List[int] = [1] * n

    def find(self, x: int) -> int:
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, a: int, b: int) -> bool:
        pa, pb = self.find(a), self.find(b)
        if pa == pb:
            return False
        if self.size[pa] > self.size[pb]:
            self.p[pb] = pa
            self.size[pa] += self.size[pb]
        else:
            self.p[pa] = pb
            self.size[pb] += self.size[pa]
        return True


class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        uf = UnionFind(len(edges))
        for a, b in edges:
            if not uf.union(a - 1, b - 1):
                return [a, b]
```

#### Java

```java
class UnionFind {
    private final int[] p;
    private final int[] size;

    public UnionFind(int n) {
        p = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            size[i] = 1;
        }
    }

    public int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    public boolean union(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }
}

class Solution {
    public int[] findRedundantConnection(int[][] edges) {
        UnionFind uf = new UnionFind(edges.length);
        for (int i = 0;; ++i) {
            if (!uf.union(edges[i][0] - 1, edges[i][1] - 1)) {
                return edges[i];
            }
        }
    }
}
```

#### C++

```cpp
class UnionFind {
public:
    UnionFind(int n) {
        p = vector<int>(n);
        size = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    bool unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

private:
    vector<int> p, size;
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind uf(edges.size());
        for (int i = 0;; ++i) {
            if (!uf.unite(edges[i][0] - 1, edges[i][1] - 1)) {
                return edges[i];
            }
        }
    }
};
```

#### Go

```go
type unionFind struct {
	p, size []int
}

func newUnionFind(n int) *unionFind {
	p := make([]int, n)
	size := make([]int, n)
	for i := range p {
		p[i] = i
		size[i] = 1
	}
	return &unionFind{p, size}
}

func (uf *unionFind) find(x int) int {
	if uf.p[x] != x {
		uf.p[x] = uf.find(uf.p[x])
	}
	return uf.p[x]
}

func (uf *unionFind) union(a, b int) bool {
	pa, pb := uf.find(a), uf.find(b)
	if pa == pb {
		return false
	}
	if uf.size[pa] > uf.size[pb] {
		uf.p[pb] = pa
		uf.size[pa] += uf.size[pb]
	} else {
		uf.p[pa] = pb
		uf.size[pb] += uf.size[pa]
	}
	return true
}

func findRedundantConnection(edges [][]int) []int {
	uf := newUnionFind(len(edges))
	for i := 0; ; i++ {
		if !uf.union(edges[i][0]-1, edges[i][1]-1) {
			return edges[i]
		}
	}
}
```

#### TypeScript

```ts
class UnionFind {
    p: number[];
    size: number[];
    constructor(n: number) {
        this.p = Array.from({ length: n }, (_, i) => i);
        this.size = Array(n).fill(1);
    }

    find(x: number): number {
        if (this.p[x] !== x) {
            this.p[x] = this.find(this.p[x]);
        }
        return this.p[x];
    }

    union(a: number, b: number): boolean {
        const [pa, pb] = [this.find(a), this.find(b)];
        if (pa === pb) {
            return false;
        }
        if (this.size[pa] > this.size[pb]) {
            this.p[pb] = pa;
            this.size[pa] += this.size[pb];
        } else {
            this.p[pa] = pb;
            this.size[pb] += this.size[pa];
        }
        return true;
    }
}

function findRedundantConnection(edges: number[][]): number[] {
    const uf = new UnionFind(edges.length);
    for (let i = 0; ; ++i) {
        if (!uf.union(edges[i][0] - 1, edges[i][1] - 1)) {
            return edges[i];
        }
    }
}
```

#### JavaScript

```js
class UnionFind {
    constructor(n) {
        this.p = Array.from({ length: n }, (_, i) => i);
        this.size = Array(n).fill(1);
    }

    find(x) {
        if (this.p[x] !== x) {
            this.p[x] = this.find(this.p[x]);
        }
        return this.p[x];
    }

    union(a, b) {
        const pa = this.find(a);
        const pb = this.find(b);
        if (pa === pb) {
            return false;
        }
        if (this.size[pa] > this.size[pb]) {
            this.p[pb] = pa;
            this.size[pa] += this.size[pb];
        } else {
            this.p[pa] = pb;
            this.size[pb] += this.size[pa];
        }
        return true;
    }
}

/**
 * @param {number[][]} edges
 * @return {number[]}
 */
var findRedundantConnection = function (edges) {
    const uf = new UnionFind(edges.length);
    for (let i = 0; i < edges.length; i++) {
        if (!uf.union(edges[i][0] - 1, edges[i][1] - 1)) {
            return edges[i];
        }
    }
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [685. 冗余连接 II](https://leetcode.cn/problems/redundant-connection-ii){#685}

{{< tabs "685" >}}

{{% tab "plaintext" %}}
```plaintext
1
        /^
       v  \
       2-->3
```
{{% /tab %}}
{{% tab "python" %}}
```python
class UnionFind:
    __slots__ = "p", "size"

    def __init__(self, n: int):
        self.p: List[int] = list(range(n))
        self.size: List[int] = [1] * n

    def find(self, x: int) -> int:
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, a: int, b: int) -> bool:
        pa, pb = self.find(a), self.find(b)
        if pa == pb:
            return False
        if self.size[pa] > self.size[pb]:
            self.p[pb] = pa
            self.size[pa] += self.size[pb]
        else:
            self.p[pa] = pb
            self.size[pb] += self.size[pa]
        return True


class Solution:
    def findRedundantDirectedConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)
        ind = [0] * n
        for _, v in edges:
            ind[v - 1] += 1
        dup = [i for i, (_, v) in enumerate(edges) if ind[v - 1] == 2]
        uf = UnionFind(n)
        if dup:
            for i, (u, v) in enumerate(edges):
                if i == dup[1]:
                    continue
                if not uf.union(u - 1, v - 1):
                    return edges[dup[0]]
            return edges[dup[1]]
        for i, (u, v) in enumerate(edges):
            if not uf.union(u - 1, v - 1):
                return edges[i]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class UnionFind {
    private final int[] p;
    private final int[] size;

    public UnionFind(int n) {
        p = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            size[i] = 1;
        }
    }

    public int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    public boolean union(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }
}

class Solution {
    public int[] findRedundantDirectedConnection(int[][] edges) {
        int n = edges.length;
        int[] ind = new int[n];
        for (var e : edges) {
            ++ind[e[1] - 1];
        }
        List<Integer> dup = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            if (ind[edges[i][1] - 1] == 2) {
                dup.add(i);
            }
        }
        UnionFind uf = new UnionFind(n);
        if (!dup.isEmpty()) {
            for (int i = 0; i < n; ++i) {
                if (i == dup.get(1)) {
                    continue;
                }
                if (!uf.union(edges[i][0] - 1, edges[i][1] - 1)) {
                    return edges[dup.get(0)];
                }
            }
            return edges[dup.get(1)];
        }
        for (int i = 0;; ++i) {
            if (!uf.union(edges[i][0] - 1, edges[i][1] - 1)) {
                return edges[i];
            }
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class UnionFind {
public:
    UnionFind(int n) {
        p = vector<int>(n);
        size = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    bool unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

private:
    vector<int> p, size;
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> ind(n);
        for (const auto& e : edges) {
            ++ind[e[1] - 1];
        }
        vector<int> dup;
        for (int i = 0; i < n; ++i) {
            if (ind[edges[i][1] - 1] == 2) {
                dup.push_back(i);
            }
        }
        UnionFind uf(n);
        if (!dup.empty()) {
            for (int i = 0; i < n; ++i) {
                if (i == dup[1]) {
                    continue;
                }
                if (!uf.unite(edges[i][0] - 1, edges[i][1] - 1)) {
                    return edges[dup[0]];
                }
            }
            return edges[dup[1]];
        }
        for (int i = 0;; ++i) {
            if (!uf.unite(edges[i][0] - 1, edges[i][1] - 1)) {
                return edges[i];
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type unionFind struct {
	p, size []int
}

func newUnionFind(n int) *unionFind {
	p := make([]int, n)
	size := make([]int, n)
	for i := range p {
		p[i] = i
		size[i] = 1
	}
	return &unionFind{p, size}
}

func (uf *unionFind) find(x int) int {
	if uf.p[x] != x {
		uf.p[x] = uf.find(uf.p[x])
	}
	return uf.p[x]
}

func (uf *unionFind) union(a, b int) bool {
	pa, pb := uf.find(a), uf.find(b)
	if pa == pb {
		return false
	}
	if uf.size[pa] > uf.size[pb] {
		uf.p[pb] = pa
		uf.size[pa] += uf.size[pb]
	} else {
		uf.p[pa] = pb
		uf.size[pb] += uf.size[pa]
	}
	return true
}

func findRedundantDirectedConnection(edges [][]int) []int {
	n := len(edges)
	ind := make([]int, n)
	for _, e := range edges {
		ind[e[1]-1]++
	}
	dup := []int{}
	for i, e := range edges {
		if ind[e[1]-1] == 2 {
			dup = append(dup, i)
		}
	}
	uf := newUnionFind(n)
	if len(dup) > 0 {
		for i, e := range edges {
			if i == dup[1] {
				continue
			}
			if !uf.union(e[0]-1, e[1]-1) {
				return edges[dup[0]]
			}
		}
		return edges[dup[1]]
	}
	for _, e := range edges {
		if !uf.union(e[0]-1, e[1]-1) {
			return e
		}
	}
	return nil
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class UnionFind {
    p: number[];
    size: number[];
    constructor(n: number) {
        this.p = Array.from({ length: n }, (_, i) => i);
        this.size = Array(n).fill(1);
    }

    find(x: number): number {
        if (this.p[x] !== x) {
            this.p[x] = this.find(this.p[x]);
        }
        return this.p[x];
    }

    union(a: number, b: number): boolean {
        const [pa, pb] = [this.find(a), this.find(b)];
        if (pa === pb) {
            return false;
        }
        if (this.size[pa] > this.size[pb]) {
            this.p[pb] = pa;
            this.size[pa] += this.size[pb];
        } else {
            this.p[pa] = pb;
            this.size[pb] += this.size[pa];
        }
        return true;
    }
}

function findRedundantDirectedConnection(edges: number[][]): number[] {
    const n = edges.length;
    const ind: number[] = Array(n).fill(0);
    for (const [_, v] of edges) {
        ++ind[v - 1];
    }
    const dup: number[] = [];
    for (let i = 0; i < n; ++i) {
        if (ind[edges[i][1] - 1] === 2) {
            dup.push(i);
        }
    }
    const uf = new UnionFind(n);
    if (dup.length) {
        for (let i = 0; i < n; ++i) {
            if (i === dup[1]) {
                continue;
            }
            if (!uf.union(edges[i][0] - 1, edges[i][1] - 1)) {
                return edges[dup[0]];
            }
        }
        return edges[dup[1]];
    }
    for (let i = 0; ; ++i) {
        if (!uf.union(edges[i][0] - 1, edges[i][1] - 1)) {
            return edges[i];
        }
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
class UnionFind {
    constructor(n) {
        this.p = Array.from({ length: n }, (_, i) => i);
        this.size = Array(n).fill(1);
    }

    find(x) {
        if (this.p[x] !== x) {
            this.p[x] = this.find(this.p[x]);
        }
        return this.p[x];
    }

    union(a, b) {
        const pa = this.find(a);
        const pb = this.find(b);
        if (pa === pb) {
            return false;
        }
        if (this.size[pa] > this.size[pb]) {
            this.p[pb] = pa;
            this.size[pa] += this.size[pb];
        } else {
            this.p[pa] = pb;
            this.size[pb] += this.size[pa];
        }
        return true;
    }
}

/**
 * @param {number[][]} edges
 * @return {number[]}
 */
var findRedundantDirectedConnection = function (edges) {
    const n = edges.length;
    const ind = Array(n).fill(0);
    for (const [_, v] of edges) {
        ++ind[v - 1];
    }
    const dup = [];
    for (let i = 0; i < n; ++i) {
        if (ind[edges[i][1] - 1] === 2) {
            dup.push(i);
        }
    }
    const uf = new UnionFind(n);
    if (dup.length) {
        for (let i = 0; i < n; ++i) {
            if (i === dup[1]) {
                continue;
            }
            if (!uf.union(edges[i][0] - 1, edges[i][1] - 1)) {
                return edges[dup[0]];
            }
        }
        return edges[dup[1]];
    }
    for (let i = 0; ; ++i) {
        if (!uf.union(edges[i][0] - 1, edges[i][1] - 1)) {
            return edges[i];
        }
    }
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>在本问题中，有根树指满足以下条件的 <strong>有向</strong> 图。该树只有一个根节点，所有其他节点都是该根节点的后继。该树除了根节点之外的每一个节点都有且只有一个父节点，而根节点没有父节点。</p>

<p>输入一个有向图，该图由一个有着 <code>n</code> 个节点（节点值不重复，从 <code>1</code> 到 <code>n</code>）的树及一条附加的有向边构成。附加的边包含在 <code>1</code> 到 <code>n</code> 中的两个不同顶点间，这条附加的边不属于树中已存在的边。</p>

<p>结果图是一个以边组成的二维数组&nbsp;<code>edges</code> 。 每个元素是一对 <code>[u<sub>i</sub>, v<sub>i</sub>]</code>，用以表示 <strong>有向 </strong>图中连接顶点 <code>u<sub>i</sub></code> 和顶点 <code>v<sub>i</sub></code> 的边，其中 <code>u<sub>i</sub></code> 是 <code>v<sub>i</sub></code> 的一个父节点。</p>

<p>返回一条能删除的边，使得剩下的图是有 <code>n</code> 个节点的有根树。若有多个答案，返回最后出现在给定二维数组的答案。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0600-0699/0685.Redundant%20Connection%20II/images/graph1.jpg" style="width: 222px; height: 222px;" />
<pre>
<strong>输入：</strong>edges = [[1,2],[1,3],[2,3]]
<strong>输出：</strong>[2,3]
</pre>

<p><strong class="example">示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0600-0699/0685.Redundant%20Connection%20II/images/graph2.jpg" style="width: 222px; height: 382px;" />
<pre>
<strong>输入：</strong>edges = [[1,2],[2,3],[3,4],[4,1],[1,5]]
<strong>输出：</strong>[4,1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == edges.length</code></li>
	<li><code>3 &lt;= n &lt;= 1000</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>1 &lt;= u<sub>i</sub>, v<sub>i</sub> &lt;= n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：并查集

根据题目描述，对于一棵有根树，根节点的入度为 $0$，其余节点的入度为 $1$。在向树中添加一条边之后，可能会出现以下三种情况：

1. 添加的边指向了非根节点，该节点的入度变为 $2$，此时图中不存在有向环；

    ```plaintext
       1
      / \
     v   v
     2-->3
    ```

1. 添加的边指向了非根节点，该节点的入度变为 $2$，此时图中存在有向环；

    ```plaintext
       1
       |
       v
       2 <--> 3
    ```

1. 添加的边指向了根节点，根节点的入度变为 $1$，此时图中存在有向环，但不存在入度为 $2$ 的节点。

    ```plaintext
        1
        /^
       v  \
       2-->3
    ```

因此，我们首先计算每个节点的入度，如果存在入度为 $2$ 的节点，我们定位到该节点对应的两条边，分别记为 $\textit{dup}[0]$ 和 $\textit{dup}[1]$。如果在删除 $\textit{dup}[1]$ 之后，剩余的边无法形成树，则说明 $\textit{dup}[0]$ 是需要删除的边；否则 $\textit{dup}[1]$ 是需要删除的边。

如果不存在入度为 $2$ 的节点，我们遍历数组 $\textit{edges}$，对于每条边 $(u, v)$，我们使用并查集维护节点之间的连通性。如果 $u$ 和 $v$ 已经连通，说明图中存在有向环，此时当前边即为需要删除的边。

时间复杂度 $O(n \log n)$，空间复杂度 $O(n)$。其中 $n$ 为边的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findRedundantDirectedConnection(self, edges: List[List[int]]) -> List[int]:
        def find(x: int) -> int:
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        n = len(edges)
        ind = [0] * n
        for _, v in edges:
            ind[v - 1] += 1
        dup = [i for i, (_, v) in enumerate(edges) if ind[v - 1] == 2]
        p = list(range(n))
        if dup:
            for i, (u, v) in enumerate(edges):
                if i == dup[1]:
                    continue
                pu, pv = find(u - 1), find(v - 1)
                if pu == pv:
                    return edges[dup[0]]
                p[pu] = pv
            return edges[dup[1]]
        for i, (u, v) in enumerate(edges):
            pu, pv = find(u - 1), find(v - 1)
            if pu == pv:
                return edges[i]
            p[pu] = pv
```

#### Java

```java
class Solution {
    private int[] p;

    public int[] findRedundantDirectedConnection(int[][] edges) {
        int n = edges.length;
        int[] ind = new int[n];
        for (var e : edges) {
            ++ind[e[1] - 1];
        }
        List<Integer> dup = new ArrayList<>();
        p = new int[n];
        for (int i = 0; i < n; ++i) {
            if (ind[edges[i][1] - 1] == 2) {
                dup.add(i);
            }
            p[i] = i;
        }
        if (!dup.isEmpty()) {
            for (int i = 0; i < n; ++i) {
                if (i == dup.get(1)) {
                    continue;
                }
                int pu = find(edges[i][0] - 1);
                int pv = find(edges[i][1] - 1);
                if (pu == pv) {
                    return edges[dup.get(0)];
                }
                p[pu] = pv;
            }
            return edges[dup.get(1)];
        }
        for (int i = 0;; ++i) {
            int pu = find(edges[i][0] - 1);
            int pv = find(edges[i][1] - 1);
            if (pu == pv) {
                return edges[i];
            }
            p[pu] = pv;
        }
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
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> ind(n);
        for (const auto& e : edges) {
            ++ind[e[1] - 1];
        }
        vector<int> dup;
        for (int i = 0; i < n; ++i) {
            if (ind[edges[i][1] - 1] == 2) {
                dup.push_back(i);
            }
        }
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        function<int(int)> find = [&](int x) {
            return x == p[x] ? x : p[x] = find(p[x]);
        };
        if (!dup.empty()) {
            for (int i = 0; i < n; ++i) {
                if (i == dup[1]) {
                    continue;
                }
                int pu = find(edges[i][0] - 1);
                int pv = find(edges[i][1] - 1);
                if (pu == pv) {
                    return edges[dup[0]];
                }
                p[pu] = pv;
            }
            return edges[dup[1]];
        }
        for (int i = 0;; ++i) {
            int pu = find(edges[i][0] - 1);
            int pv = find(edges[i][1] - 1);
            if (pu == pv) {
                return edges[i];
            }
            p[pu] = pv;
        }
    }
};
```

#### Go

```go
func findRedundantDirectedConnection(edges [][]int) []int {
	n := len(edges)
	ind := make([]int, n)
	for _, e := range edges {
		ind[e[1]-1]++
	}
	dup := []int{}
	for i, e := range edges {
		if ind[e[1]-1] == 2 {
			dup = append(dup, i)
		}
	}
	p := make([]int, n)
	for i := range p {
		p[i] = i
	}
	var find func(int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	if len(dup) > 0 {
		for i, e := range edges {
			if i == dup[1] {
				continue
			}
			pu, pv := find(e[0]-1), find(e[1]-1)
			if pu == pv {
				return edges[dup[0]]
			}
			p[pu] = pv
		}
		return edges[dup[1]]
	}
	for _, e := range edges {
		pu, pv := find(e[0]-1), find(e[1]-1)
		if pu == pv {
			return e
		}
		p[pu] = pv
	}
	return nil
}
```

#### TypeScript

```ts
function findRedundantDirectedConnection(edges: number[][]): number[] {
    const n = edges.length;
    const ind: number[] = Array(n).fill(0);
    for (const [_, v] of edges) {
        ++ind[v - 1];
    }
    const dup: number[] = [];
    for (let i = 0; i < n; ++i) {
        if (ind[edges[i][1] - 1] === 2) {
            dup.push(i);
        }
    }
    const p: number[] = Array.from({ length: n }, (_, i) => i);
    const find = (x: number): number => {
        if (p[x] !== x) {
            p[x] = find(p[x]);
        }
        return p[x];
    };
    if (dup.length) {
        for (let i = 0; i < n; ++i) {
            if (i === dup[1]) {
                continue;
            }
            const [pu, pv] = [find(edges[i][0] - 1), find(edges[i][1] - 1)];
            if (pu === pv) {
                return edges[dup[0]];
            }
            p[pu] = pv;
        }
        return edges[dup[1]];
    }
    for (let i = 0; ; ++i) {
        const [pu, pv] = [find(edges[i][0] - 1), find(edges[i][1] - 1)];
        if (pu === pv) {
            return edges[i];
        }
        p[pu] = pv;
    }
}
```

#### JavaScript

```js
/**
 * @param {number[][]} edges
 * @return {number[]}
 */
var findRedundantDirectedConnection = function (edges) {
    const n = edges.length;
    const ind = Array(n).fill(0);
    for (const [_, v] of edges) {
        ++ind[v - 1];
    }
    const dup = [];
    for (let i = 0; i < n; ++i) {
        if (ind[edges[i][1] - 1] === 2) {
            dup.push(i);
        }
    }
    const p = Array.from({ length: n }, (_, i) => i);
    const find = x => {
        if (p[x] !== x) {
            p[x] = find(p[x]);
        }
        return p[x];
    };
    if (dup.length) {
        for (let i = 0; i < n; ++i) {
            if (i === dup[1]) {
                continue;
            }
            const [pu, pv] = [find(edges[i][0] - 1), find(edges[i][1] - 1)];
            if (pu === pv) {
                return edges[dup[0]];
            }
            p[pu] = pv;
        }
        return edges[dup[1]];
    }
    for (let i = 0; ; ++i) {
        const [pu, pv] = [find(edges[i][0] - 1), find(edges[i][1] - 1)];
        if (pu === pv) {
            return edges[i];
        }
        p[pu] = pv;
    }
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：并查集（模板做法）

这里给出一个并查集的模板做法，供大家参考。

时间复杂度 $O(n \alpha(n))$，空间复杂度 $O(n)$。其中 $n$ 为边的数量，而 $\alpha(n)$ 是阿克曼函数的反函数，可以认为是一个很小的常数。

<!-- tabs:start -->

#### Python3

```python
class UnionFind:
    __slots__ = "p", "size"

    def __init__(self, n: int):
        self.p: List[int] = list(range(n))
        self.size: List[int] = [1] * n

    def find(self, x: int) -> int:
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, a: int, b: int) -> bool:
        pa, pb = self.find(a), self.find(b)
        if pa == pb:
            return False
        if self.size[pa] > self.size[pb]:
            self.p[pb] = pa
            self.size[pa] += self.size[pb]
        else:
            self.p[pa] = pb
            self.size[pb] += self.size[pa]
        return True


class Solution:
    def findRedundantDirectedConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)
        ind = [0] * n
        for _, v in edges:
            ind[v - 1] += 1
        dup = [i for i, (_, v) in enumerate(edges) if ind[v - 1] == 2]
        uf = UnionFind(n)
        if dup:
            for i, (u, v) in enumerate(edges):
                if i == dup[1]:
                    continue
                if not uf.union(u - 1, v - 1):
                    return edges[dup[0]]
            return edges[dup[1]]
        for i, (u, v) in enumerate(edges):
            if not uf.union(u - 1, v - 1):
                return edges[i]
```

#### Java

```java
class UnionFind {
    private final int[] p;
    private final int[] size;

    public UnionFind(int n) {
        p = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            size[i] = 1;
        }
    }

    public int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    public boolean union(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }
}

class Solution {
    public int[] findRedundantDirectedConnection(int[][] edges) {
        int n = edges.length;
        int[] ind = new int[n];
        for (var e : edges) {
            ++ind[e[1] - 1];
        }
        List<Integer> dup = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            if (ind[edges[i][1] - 1] == 2) {
                dup.add(i);
            }
        }
        UnionFind uf = new UnionFind(n);
        if (!dup.isEmpty()) {
            for (int i = 0; i < n; ++i) {
                if (i == dup.get(1)) {
                    continue;
                }
                if (!uf.union(edges[i][0] - 1, edges[i][1] - 1)) {
                    return edges[dup.get(0)];
                }
            }
            return edges[dup.get(1)];
        }
        for (int i = 0;; ++i) {
            if (!uf.union(edges[i][0] - 1, edges[i][1] - 1)) {
                return edges[i];
            }
        }
    }
}
```

#### C++

```cpp
class UnionFind {
public:
    UnionFind(int n) {
        p = vector<int>(n);
        size = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    bool unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

private:
    vector<int> p, size;
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> ind(n);
        for (const auto& e : edges) {
            ++ind[e[1] - 1];
        }
        vector<int> dup;
        for (int i = 0; i < n; ++i) {
            if (ind[edges[i][1] - 1] == 2) {
                dup.push_back(i);
            }
        }
        UnionFind uf(n);
        if (!dup.empty()) {
            for (int i = 0; i < n; ++i) {
                if (i == dup[1]) {
                    continue;
                }
                if (!uf.unite(edges[i][0] - 1, edges[i][1] - 1)) {
                    return edges[dup[0]];
                }
            }
            return edges[dup[1]];
        }
        for (int i = 0;; ++i) {
            if (!uf.unite(edges[i][0] - 1, edges[i][1] - 1)) {
                return edges[i];
            }
        }
    }
};
```

#### Go

```go
type unionFind struct {
	p, size []int
}

func newUnionFind(n int) *unionFind {
	p := make([]int, n)
	size := make([]int, n)
	for i := range p {
		p[i] = i
		size[i] = 1
	}
	return &unionFind{p, size}
}

func (uf *unionFind) find(x int) int {
	if uf.p[x] != x {
		uf.p[x] = uf.find(uf.p[x])
	}
	return uf.p[x]
}

func (uf *unionFind) union(a, b int) bool {
	pa, pb := uf.find(a), uf.find(b)
	if pa == pb {
		return false
	}
	if uf.size[pa] > uf.size[pb] {
		uf.p[pb] = pa
		uf.size[pa] += uf.size[pb]
	} else {
		uf.p[pa] = pb
		uf.size[pb] += uf.size[pa]
	}
	return true
}

func findRedundantDirectedConnection(edges [][]int) []int {
	n := len(edges)
	ind := make([]int, n)
	for _, e := range edges {
		ind[e[1]-1]++
	}
	dup := []int{}
	for i, e := range edges {
		if ind[e[1]-1] == 2 {
			dup = append(dup, i)
		}
	}
	uf := newUnionFind(n)
	if len(dup) > 0 {
		for i, e := range edges {
			if i == dup[1] {
				continue
			}
			if !uf.union(e[0]-1, e[1]-1) {
				return edges[dup[0]]
			}
		}
		return edges[dup[1]]
	}
	for _, e := range edges {
		if !uf.union(e[0]-1, e[1]-1) {
			return e
		}
	}
	return nil
}
```

#### TypeScript

```ts
class UnionFind {
    p: number[];
    size: number[];
    constructor(n: number) {
        this.p = Array.from({ length: n }, (_, i) => i);
        this.size = Array(n).fill(1);
    }

    find(x: number): number {
        if (this.p[x] !== x) {
            this.p[x] = this.find(this.p[x]);
        }
        return this.p[x];
    }

    union(a: number, b: number): boolean {
        const [pa, pb] = [this.find(a), this.find(b)];
        if (pa === pb) {
            return false;
        }
        if (this.size[pa] > this.size[pb]) {
            this.p[pb] = pa;
            this.size[pa] += this.size[pb];
        } else {
            this.p[pa] = pb;
            this.size[pb] += this.size[pa];
        }
        return true;
    }
}

function findRedundantDirectedConnection(edges: number[][]): number[] {
    const n = edges.length;
    const ind: number[] = Array(n).fill(0);
    for (const [_, v] of edges) {
        ++ind[v - 1];
    }
    const dup: number[] = [];
    for (let i = 0; i < n; ++i) {
        if (ind[edges[i][1] - 1] === 2) {
            dup.push(i);
        }
    }
    const uf = new UnionFind(n);
    if (dup.length) {
        for (let i = 0; i < n; ++i) {
            if (i === dup[1]) {
                continue;
            }
            if (!uf.union(edges[i][0] - 1, edges[i][1] - 1)) {
                return edges[dup[0]];
            }
        }
        return edges[dup[1]];
    }
    for (let i = 0; ; ++i) {
        if (!uf.union(edges[i][0] - 1, edges[i][1] - 1)) {
            return edges[i];
        }
    }
}
```

#### JavaScript

```js
class UnionFind {
    constructor(n) {
        this.p = Array.from({ length: n }, (_, i) => i);
        this.size = Array(n).fill(1);
    }

    find(x) {
        if (this.p[x] !== x) {
            this.p[x] = this.find(this.p[x]);
        }
        return this.p[x];
    }

    union(a, b) {
        const pa = this.find(a);
        const pb = this.find(b);
        if (pa === pb) {
            return false;
        }
        if (this.size[pa] > this.size[pb]) {
            this.p[pb] = pa;
            this.size[pa] += this.size[pb];
        } else {
            this.p[pa] = pb;
            this.size[pb] += this.size[pa];
        }
        return true;
    }
}

/**
 * @param {number[][]} edges
 * @return {number[]}
 */
var findRedundantDirectedConnection = function (edges) {
    const n = edges.length;
    const ind = Array(n).fill(0);
    for (const [_, v] of edges) {
        ++ind[v - 1];
    }
    const dup = [];
    for (let i = 0; i < n; ++i) {
        if (ind[edges[i][1] - 1] === 2) {
            dup.push(i);
        }
    }
    const uf = new UnionFind(n);
    if (dup.length) {
        for (let i = 0; i < n; ++i) {
            if (i === dup[1]) {
                continue;
            }
            if (!uf.union(edges[i][0] - 1, edges[i][1] - 1)) {
                return edges[dup[0]];
            }
        }
        return edges[dup[1]];
    }
    for (let i = 0; ; ++i) {
        if (!uf.union(edges[i][0] - 1, edges[i][1] - 1)) {
            return edges[i];
        }
    }
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [686. 重复叠加字符串匹配](https://leetcode.cn/problems/repeated-string-match){#686}

{{< tabs "686" >}}

{{% tab "python" %}}
```python
class Solution:
    def repeatedStringMatch(self, a: str, b: str) -> int:
        m, n = len(a), len(b)
        ans = ceil(n / m)
        t = [a] * ans
        for _ in range(3):
            if b in ''.join(t):
                return ans
            ans += 1
            t.append(a)
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int repeatedStringMatch(String a, String b) {
        int m = a.length(), n = b.length();
        int ans = (n + m - 1) / m;
        StringBuilder t = new StringBuilder(a.repeat(ans));
        for (int i = 0; i < 3; ++i) {
            if (t.toString().contains(b)) {
                return ans;
            }
            ++ans;
            t.append(a);
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
    int repeatedStringMatch(string a, string b) {
        int m = a.size(), n = b.size();
        int ans = (n + m - 1) / m;
        string t = "";
        for (int i = 0; i < ans; ++i) t += a;
        for (int i = 0; i < 3; ++i) {
            if (t.find(b) != -1) return ans;
            ++ans;
            t += a;
        }
        return -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func repeatedStringMatch(a string, b string) int {
	m, n := len(a), len(b)
	ans := (n + m - 1) / m
	t := strings.Repeat(a, ans)
	for i := 0; i < 3; i++ {
		if strings.Contains(t, b) {
			return ans
		}
		ans++
		t += a
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function repeatedStringMatch(a: string, b: string): number {
    const m: number = a.length,
        n: number = b.length;
    let ans: number = Math.ceil(n / m);
    let t: string = a.repeat(ans);

    for (let i = 0; i < 3; i++) {
        if (t.includes(b)) {
            return ans;
        }
        ans++;
        t += a;
    }

    return -1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定两个字符串&nbsp;<code>a</code> 和 <code>b</code>，寻找重复叠加字符串 <code>a</code> 的最小次数，使得字符串 <code>b</code> 成为叠加后的字符串 <code>a</code> 的子串，如果不存在则返回 <code>-1</code>。</p>

<p><strong>注意：</strong>字符串 <code>&quot;abc&quot;</code>&nbsp;重复叠加 0 次是 <code>&quot;&quot;</code>，重复叠加 1 次是&nbsp;<code>&quot;abc&quot;</code>，重复叠加 2 次是&nbsp;<code>&quot;abcabc&quot;</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>a = &quot;abcd&quot;, b = &quot;cdabcdab&quot;
<strong>输出：</strong>3
<strong>解释：</strong>a 重复叠加三遍后为 &quot;ab<strong>cdabcdab</strong>cd&quot;, 此时 b 是其子串。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>a = &quot;a&quot;, b = &quot;aa&quot;
<strong>输出：</strong>2
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>a = &quot;a&quot;, b = &quot;a&quot;
<strong>输出：</strong>1
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>a = &quot;abc&quot;, b = &quot;wxyz&quot;
<strong>输出：</strong>-1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= a.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= b.length &lt;= 10<sup>4</sup></code></li>
	<li><code>a</code> 和 <code>b</code> 由小写英文字母组成</li>
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
    def repeatedStringMatch(self, a: str, b: str) -> int:
        m, n = len(a), len(b)
        ans = ceil(n / m)
        t = [a] * ans
        for _ in range(3):
            if b in ''.join(t):
                return ans
            ans += 1
            t.append(a)
        return -1
```

#### Java

```java
class Solution {
    public int repeatedStringMatch(String a, String b) {
        int m = a.length(), n = b.length();
        int ans = (n + m - 1) / m;
        StringBuilder t = new StringBuilder(a.repeat(ans));
        for (int i = 0; i < 3; ++i) {
            if (t.toString().contains(b)) {
                return ans;
            }
            ++ans;
            t.append(a);
        }
        return -1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int m = a.size(), n = b.size();
        int ans = (n + m - 1) / m;
        string t = "";
        for (int i = 0; i < ans; ++i) t += a;
        for (int i = 0; i < 3; ++i) {
            if (t.find(b) != -1) return ans;
            ++ans;
            t += a;
        }
        return -1;
    }
};
```

#### Go

```go
func repeatedStringMatch(a string, b string) int {
	m, n := len(a), len(b)
	ans := (n + m - 1) / m
	t := strings.Repeat(a, ans)
	for i := 0; i < 3; i++ {
		if strings.Contains(t, b) {
			return ans
		}
		ans++
		t += a
	}
	return -1
}
```

#### TypeScript

```ts
function repeatedStringMatch(a: string, b: string): number {
    const m: number = a.length,
        n: number = b.length;
    let ans: number = Math.ceil(n / m);
    let t: string = a.repeat(ans);

    for (let i = 0; i < 3; i++) {
        if (t.includes(b)) {
            return ans;
        }
        ans++;
        t += a;
    }

    return -1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [687. 最长同值路径](https://leetcode.cn/problems/longest-univalue-path){#687}

{{< tabs "687" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestUnivaluePath(self, root: Optional[TreeNode]) -> int:
        def dfs(root: Optional[TreeNode]) -> int:
            if root is None:
                return 0
            l, r = dfs(root.left), dfs(root.right)
            l = l + 1 if root.left and root.left.val == root.val else 0
            r = r + 1 if root.right and root.right.val == root.val else 0
            nonlocal ans
            ans = max(ans, l + r)
            return max(l, r)

        ans = 0
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
    private int ans;

    public int longestUnivaluePath(TreeNode root) {
        dfs(root);
        return ans;
    }

    private int dfs(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int l = dfs(root.left);
        int r = dfs(root.right);
        l = root.left != null && root.left.val == root.val ? l + 1 : 0;
        r = root.right != null && root.right.val == root.val ? r + 1 : 0;
        ans = Math.max(ans, l + r);
        return Math.max(l, r);
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
    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        auto dfs = [&](this auto&& dfs, TreeNode* root) -> int {
            if (!root) {
                return 0;
            }
            int l = dfs(root->left);
            int r = dfs(root->right);
            l = root->left && root->left->val == root->val ? l + 1 : 0;
            r = root->right && root->right->val == root->val ? r + 1 : 0;
            ans = max(ans, l + r);
            return max(l, r);
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
func longestUnivaluePath(root *TreeNode) (ans int) {
	var dfs func(*TreeNode) int
	dfs = func(root *TreeNode) int {
		if root == nil {
			return 0
		}
		l, r := dfs(root.Left), dfs(root.Right)
		if root.Left != nil && root.Left.Val == root.Val {
			l++
		} else {
			l = 0
		}
		if root.Right != nil && root.Right.Val == root.Val {
			r++
		} else {
			r = 0
		}
		ans = max(ans, l+r)
		return max(l, r)
	}
	dfs(root)
	return
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

function longestUnivaluePath(root: TreeNode | null): number {
    let ans: number = 0;
    const dfs = (root: TreeNode | null): number => {
        if (!root) {
            return 0;
        }
        let [l, r] = [dfs(root.left), dfs(root.right)];
        l = root.left && root.left.val === root.val ? l + 1 : 0;
        r = root.right && root.right.val === root.val ? r + 1 : 0;
        ans = Math.max(ans, l + r);
        return Math.max(l, r);
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
    fn dfs(root: &Option<Rc<RefCell<TreeNode>>>, target: i32, ans: &mut i32) -> i32 {
        if root.is_none() {
            return 0;
        }

        let root = root.as_ref().unwrap().borrow();
        let left = Self::dfs(&root.left, root.val, ans);
        let right = Self::dfs(&root.right, root.val, ans);

        *ans = (*ans).max(left + right);

        if root.val == target {
            return left.max(right) + 1;
        }

        0
    }

    pub fn longest_univalue_path(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        if root.is_none() {
            return 0;
        }

        let mut ans = 0;
        Self::dfs(&root, root.as_ref().unwrap().borrow().val, &mut ans);
        ans
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
var longestUnivaluePath = function (root) {
    let ans = 0;
    const dfs = root => {
        if (!root) {
            return 0;
        }
        let [l, r] = [dfs(root.left), dfs(root.right)];
        l = root.left && root.left.val === root.val ? l + 1 : 0;
        r = root.right && root.right.val === root.val ? r + 1 : 0;
        ans = Math.max(ans, l + r);
        return Math.max(l, r);
    };
    dfs(root);
    return ans;
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
#define max(a, b) (((a) > (b)) ? (a) : (b))

int dfs(struct TreeNode* root, int* ans) {
    if (!root) {
        return 0;
    }
    int l = dfs(root->left, ans);
    int r = dfs(root->right, ans);
    l = root->left && root->left->val == root->val ? l + 1 : 0;
    r = root->right && root->right->val == root->val ? r + 1 : 0;
    *ans = max(*ans, l + r);
    return max(l, r);
}

int longestUnivaluePath(struct TreeNode* root) {
    int ans = 0;
    dfs(root, &ans);
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个二叉树的<meta charset="UTF-8" />&nbsp;<code>root</code>&nbsp;，返回&nbsp;<em>最长的路径的长度</em> ，这个路径中的&nbsp;<em>每个节点具有相同值</em>&nbsp;。 这条路径可以经过也可以不经过根节点。</p>

<p><strong>两个节点之间的路径长度</strong>&nbsp;由它们之间的边数表示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0600-0699/0687.Longest%20Univalue%20Path/images/ex1.jpg" /></p>

<pre>
<strong>输入：</strong>root = [5,4,5,1,1,5]
<strong>输出：</strong>2
</pre>

<p><strong>示例 2:</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0600-0699/0687.Longest%20Univalue%20Path/images/ex2.jpg" /></p>

<pre>
<strong>输入：</strong>root = [1,4,5,4,4,5]
<strong>输出：</strong>2
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li>树的节点数的范围是<meta charset="UTF-8" />&nbsp;<code>[0, 10<sup>4</sup>]</code>&nbsp;</li>
	<li><code>-1000 &lt;= Node.val &lt;= 1000</code></li>
	<li>树的深度将不超过 <code>1000</code>&nbsp;</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们设计一个函数 $\textit{dfs}(root)$，表示以 $\textit{root}$ 节点作为路径的其中一个端点，向下延伸的最长同值路径长度。

在 $\textit{dfs}(root)$ 中，我们首先递归调用 $\textit{dfs}(root.\textit{left})$ 和 $\textit{dfs}(root.\textit{right})$，得到两个返回值 $\textit{l}$ 和 $\textit{r}$。这两个返回值分别代表了以 $\textit{root}$ 节点的左孩子和右孩子为路径的其中一个端点，向下延伸的最长同值路径长度。

如果 $\textit{root}$ 存在左孩子且 $\textit{root}.\textit{val} = \textit{root}.\textit{left}.\textit{val}$，那么在 $\textit{root}$ 的左孩子为路径的其中一个端点，向下延伸的最长同值路径长度应为 $\textit{l} + 1$；否则，这个长度为 $0$。如果 $\textit{root}$ 存在右孩子且 $\textit{root}.\textit{val} = \textit{root}.\textit{right}.\textit{val}$，那么在 $\textit{root}$ 的右孩子为路径的其中一个端点，向下延伸的最长同值路径长度应为 $\textit{r} + 1$；否则，这个长度为 $0$。

在递归调用完左右孩子之后，我们更新答案为 $\max(\textit{ans}, \textit{l} + \textit{r})$，即以 $\textit{root}$ 为端点的路径经过 $\textit{root}$ 的最长同值路径长度。

最后，$\textit{dfs}(root)$ 函数返回以 $\textit{root}$ 为端点的向下延伸的最长同值路径长度，即 $\max(\textit{l}, \textit{r})$。

在主函数中，我们调用 $\textit{dfs}(root)$，即可得到答案。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为二叉树的节点个数。

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
    def longestUnivaluePath(self, root: Optional[TreeNode]) -> int:
        def dfs(root: Optional[TreeNode]) -> int:
            if root is None:
                return 0
            l, r = dfs(root.left), dfs(root.right)
            l = l + 1 if root.left and root.left.val == root.val else 0
            r = r + 1 if root.right and root.right.val == root.val else 0
            nonlocal ans
            ans = max(ans, l + r)
            return max(l, r)

        ans = 0
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
    private int ans;

    public int longestUnivaluePath(TreeNode root) {
        dfs(root);
        return ans;
    }

    private int dfs(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int l = dfs(root.left);
        int r = dfs(root.right);
        l = root.left != null && root.left.val == root.val ? l + 1 : 0;
        r = root.right != null && root.right.val == root.val ? r + 1 : 0;
        ans = Math.max(ans, l + r);
        return Math.max(l, r);
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
    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        auto dfs = [&](this auto&& dfs, TreeNode* root) -> int {
            if (!root) {
                return 0;
            }
            int l = dfs(root->left);
            int r = dfs(root->right);
            l = root->left && root->left->val == root->val ? l + 1 : 0;
            r = root->right && root->right->val == root->val ? r + 1 : 0;
            ans = max(ans, l + r);
            return max(l, r);
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
func longestUnivaluePath(root *TreeNode) (ans int) {
	var dfs func(*TreeNode) int
	dfs = func(root *TreeNode) int {
		if root == nil {
			return 0
		}
		l, r := dfs(root.Left), dfs(root.Right)
		if root.Left != nil && root.Left.Val == root.Val {
			l++
		} else {
			l = 0
		}
		if root.Right != nil && root.Right.Val == root.Val {
			r++
		} else {
			r = 0
		}
		ans = max(ans, l+r)
		return max(l, r)
	}
	dfs(root)
	return
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

function longestUnivaluePath(root: TreeNode | null): number {
    let ans: number = 0;
    const dfs = (root: TreeNode | null): number => {
        if (!root) {
            return 0;
        }
        let [l, r] = [dfs(root.left), dfs(root.right)];
        l = root.left && root.left.val === root.val ? l + 1 : 0;
        r = root.right && root.right.val === root.val ? r + 1 : 0;
        ans = Math.max(ans, l + r);
        return Math.max(l, r);
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
    fn dfs(root: &Option<Rc<RefCell<TreeNode>>>, target: i32, ans: &mut i32) -> i32 {
        if root.is_none() {
            return 0;
        }

        let root = root.as_ref().unwrap().borrow();
        let left = Self::dfs(&root.left, root.val, ans);
        let right = Self::dfs(&root.right, root.val, ans);

        *ans = (*ans).max(left + right);

        if root.val == target {
            return left.max(right) + 1;
        }

        0
    }

    pub fn longest_univalue_path(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        if root.is_none() {
            return 0;
        }

        let mut ans = 0;
        Self::dfs(&root, root.as_ref().unwrap().borrow().val, &mut ans);
        ans
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
var longestUnivaluePath = function (root) {
    let ans = 0;
    const dfs = root => {
        if (!root) {
            return 0;
        }
        let [l, r] = [dfs(root.left), dfs(root.right)];
        l = root.left && root.left.val === root.val ? l + 1 : 0;
        r = root.right && root.right.val === root.val ? r + 1 : 0;
        ans = Math.max(ans, l + r);
        return Math.max(l, r);
    };
    dfs(root);
    return ans;
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
#define max(a, b) (((a) > (b)) ? (a) : (b))

int dfs(struct TreeNode* root, int* ans) {
    if (!root) {
        return 0;
    }
    int l = dfs(root->left, ans);
    int r = dfs(root->right, ans);
    l = root->left && root->left->val == root->val ? l + 1 : 0;
    r = root->right && root->right->val == root->val ? r + 1 : 0;
    *ans = max(*ans, l + r);
    return max(l, r);
}

int longestUnivaluePath(struct TreeNode* root) {
    int ans = 0;
    dfs(root, &ans);
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [688. 骑士在棋盘上的概率](https://leetcode.cn/problems/knight-probability-in-chessboard){#688}

{{< tabs "688" >}}

{{% tab "python" %}}
```python
class Solution:
    def knightProbability(self, n: int, k: int, row: int, column: int) -> float:
        f = [[[0] * n for _ in range(n)] for _ in range(k + 1)]
        for i in range(n):
            for j in range(n):
                f[0][i][j] = 1
        for h in range(1, k + 1):
            for i in range(n):
                for j in range(n):
                    for a, b in pairwise((-2, -1, 2, 1, -2, 1, 2, -1, -2)):
                        x, y = i + a, j + b
                        if 0 <= x < n and 0 <= y < n:
                            f[h][i][j] += f[h - 1][x][y] / 8
        return f[k][row][column]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public double knightProbability(int n, int k, int row, int column) {
        double[][][] f = new double[k + 1][n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                f[0][i][j] = 1;
            }
        }
        int[] dirs = {-2, -1, 2, 1, -2, 1, 2, -1, -2};
        for (int h = 1; h <= k; ++h) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    for (int p = 0; p < 8; ++p) {
                        int x = i + dirs[p], y = j + dirs[p + 1];
                        if (x >= 0 && x < n && y >= 0 && y < n) {
                            f[h][i][j] += f[h - 1][x][y] / 8;
                        }
                    }
                }
            }
        }
        return f[k][row][column];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        double f[k + 1][n][n];
        memset(f, 0, sizeof(f));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                f[0][i][j] = 1;
            }
        }
        int dirs[9] = {-2, -1, 2, 1, -2, 1, 2, -1, -2};
        for (int h = 1; h <= k; ++h) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    for (int p = 0; p < 8; ++p) {
                        int x = i + dirs[p], y = j + dirs[p + 1];
                        if (x >= 0 && x < n && y >= 0 && y < n) {
                            f[h][i][j] += f[h - 1][x][y] / 8;
                        }
                    }
                }
            }
        }
        return f[k][row][column];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func knightProbability(n int, k int, row int, column int) float64 {
	f := make([][][]float64, k+1)
	for h := range f {
		f[h] = make([][]float64, n)
		for i := range f[h] {
			f[h][i] = make([]float64, n)
			for j := range f[h][i] {
				f[0][i][j] = 1
			}
		}
	}
	dirs := [9]int{-2, -1, 2, 1, -2, 1, 2, -1, -2}
	for h := 1; h <= k; h++ {
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				for p := 0; p < 8; p++ {
					x, y := i+dirs[p], j+dirs[p+1]
					if x >= 0 && x < n && y >= 0 && y < n {
						f[h][i][j] += f[h-1][x][y] / 8
					}
				}
			}
		}
	}
	return f[k][row][column]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function knightProbability(n: number, k: number, row: number, column: number): number {
    const f = Array.from({ length: k + 1 }, () =>
        Array.from({ length: n }, () => Array(n).fill(0)),
    );
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < n; ++j) {
            f[0][i][j] = 1;
        }
    }
    const dirs = [-2, -1, 2, 1, -2, 1, 2, -1, -2];
    for (let h = 1; h <= k; ++h) {
        for (let i = 0; i < n; ++i) {
            for (let j = 0; j < n; ++j) {
                for (let p = 0; p < 8; ++p) {
                    const x = i + dirs[p];
                    const y = j + dirs[p + 1];
                    if (x >= 0 && x < n && y >= 0 && y < n) {
                        f[h][i][j] += f[h - 1][x][y] / 8;
                    }
                }
            }
        }
    }
    return f[k][row][column];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn knight_probability(n: i32, k: i32, row: i32, column: i32) -> f64 {
        let n = n as usize;
        let k = k as usize;

        let mut f = vec![vec![vec![0.0; n]; n]; k + 1];

        for i in 0..n {
            for j in 0..n {
                f[0][i][j] = 1.0;
            }
        }

        let dirs = [-2, -1, 2, 1, -2, 1, 2, -1, -2];

        for h in 1..=k {
            for i in 0..n {
                for j in 0..n {
                    for p in 0..8 {
                        let x = i as isize + dirs[p];
                        let y = j as isize + dirs[p + 1];

                        if x >= 0 && x < n as isize && y >= 0 && y < n as isize {
                            let x = x as usize;
                            let y = y as usize;
                            f[h][i][j] += f[h - 1][x][y] / 8.0;
                        }
                    }
                }
            }
        }

        f[k][row as usize][column as usize]
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>在一个&nbsp;<code>n x n</code>&nbsp;的国际象棋棋盘上，一个骑士从单元格 <code>(row, column)</code>&nbsp;开始，并尝试进行 <code>k</code> 次移动。行和列是 <strong>从 0 开始</strong> 的，所以左上单元格是 <code>(0,0)</code> ，右下单元格是 <code>(n - 1, n - 1)</code> 。</p>

<p>象棋骑士有8种可能的走法，如下图所示。每次移动在基本方向上是两个单元格，然后在正交方向上是一个单元格。</p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0600-0699/0688.Knight%20Probability%20in%20Chessboard/images/knight.png" style="height: 300px; width: 300px;" /></p>

<p>每次骑士要移动时，它都会随机从8种可能的移动中选择一种(即使棋子会离开棋盘)，然后移动到那里。</p>

<p>骑士继续移动，直到它走了 <code>k</code> 步或离开了棋盘。</p>

<p>返回 <em>骑士在棋盘停止移动后仍留在棋盘上的概率</em> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入:</strong> n = 3, k = 2, row = 0, column = 0
<strong>输出:</strong> 0.0625
<strong>解释:</strong> 有两步(到(1,2)，(2,1))可以让骑士留在棋盘上。
在每一个位置上，也有两种移动可以让骑士留在棋盘上。
骑士留在棋盘上的总概率是0.0625。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入:</strong> n = 1, k = 0, row = 0, column = 0
<strong>输出:</strong> 1.00000
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 25</code></li>
	<li><code>0 &lt;= k &lt;= 100</code></li>
	<li><code>0 &lt;= row, column &lt;= n - 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[h][i][j]$ 表示骑士从 $(i, j)$ 位置出发，走了 $h$ 步以后还留在棋盘上的概率。那么最终答案就是 $f[k][\textit{row}][\textit{column}]$。

当 $h=0$ 时，骑士一定在棋盘上，概率为 $1$，即 $f[0][i][j]=1$。

当 $h \gt 0$ 时，骑士在 $(i, j)$ 位置上的概率可以由其上一步的 $8$ 个位置上的概率转移得到，即：

$$
f[h][i][j] = \sum_{x, y} f[h - 1][x][y] \times \frac{1}{8}
$$

其中 $(x, y)$ 是从 $(i, j)$ 位置可以走到的 $8$ 个位置中的一个。

最终答案即为 $f[k][\textit{row}][\textit{column}]$。

时间复杂度 $O(k \times n^2)$，空间复杂度 $O(k \times n^2)$。其中 $k$ 和 $n$ 分别是给定的步数和棋盘大小。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def knightProbability(self, n: int, k: int, row: int, column: int) -> float:
        f = [[[0] * n for _ in range(n)] for _ in range(k + 1)]
        for i in range(n):
            for j in range(n):
                f[0][i][j] = 1
        for h in range(1, k + 1):
            for i in range(n):
                for j in range(n):
                    for a, b in pairwise((-2, -1, 2, 1, -2, 1, 2, -1, -2)):
                        x, y = i + a, j + b
                        if 0 <= x < n and 0 <= y < n:
                            f[h][i][j] += f[h - 1][x][y] / 8
        return f[k][row][column]
```

#### Java

```java
class Solution {
    public double knightProbability(int n, int k, int row, int column) {
        double[][][] f = new double[k + 1][n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                f[0][i][j] = 1;
            }
        }
        int[] dirs = {-2, -1, 2, 1, -2, 1, 2, -1, -2};
        for (int h = 1; h <= k; ++h) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    for (int p = 0; p < 8; ++p) {
                        int x = i + dirs[p], y = j + dirs[p + 1];
                        if (x >= 0 && x < n && y >= 0 && y < n) {
                            f[h][i][j] += f[h - 1][x][y] / 8;
                        }
                    }
                }
            }
        }
        return f[k][row][column];
    }
}
```

#### C++

```cpp
class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        double f[k + 1][n][n];
        memset(f, 0, sizeof(f));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                f[0][i][j] = 1;
            }
        }
        int dirs[9] = {-2, -1, 2, 1, -2, 1, 2, -1, -2};
        for (int h = 1; h <= k; ++h) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    for (int p = 0; p < 8; ++p) {
                        int x = i + dirs[p], y = j + dirs[p + 1];
                        if (x >= 0 && x < n && y >= 0 && y < n) {
                            f[h][i][j] += f[h - 1][x][y] / 8;
                        }
                    }
                }
            }
        }
        return f[k][row][column];
    }
};
```

#### Go

```go
func knightProbability(n int, k int, row int, column int) float64 {
	f := make([][][]float64, k+1)
	for h := range f {
		f[h] = make([][]float64, n)
		for i := range f[h] {
			f[h][i] = make([]float64, n)
			for j := range f[h][i] {
				f[0][i][j] = 1
			}
		}
	}
	dirs := [9]int{-2, -1, 2, 1, -2, 1, 2, -1, -2}
	for h := 1; h <= k; h++ {
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				for p := 0; p < 8; p++ {
					x, y := i+dirs[p], j+dirs[p+1]
					if x >= 0 && x < n && y >= 0 && y < n {
						f[h][i][j] += f[h-1][x][y] / 8
					}
				}
			}
		}
	}
	return f[k][row][column]
}
```

#### TypeScript

```ts
function knightProbability(n: number, k: number, row: number, column: number): number {
    const f = Array.from({ length: k + 1 }, () =>
        Array.from({ length: n }, () => Array(n).fill(0)),
    );
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < n; ++j) {
            f[0][i][j] = 1;
        }
    }
    const dirs = [-2, -1, 2, 1, -2, 1, 2, -1, -2];
    for (let h = 1; h <= k; ++h) {
        for (let i = 0; i < n; ++i) {
            for (let j = 0; j < n; ++j) {
                for (let p = 0; p < 8; ++p) {
                    const x = i + dirs[p];
                    const y = j + dirs[p + 1];
                    if (x >= 0 && x < n && y >= 0 && y < n) {
                        f[h][i][j] += f[h - 1][x][y] / 8;
                    }
                }
            }
        }
    }
    return f[k][row][column];
}
```

#### Rust

```rust
impl Solution {
    pub fn knight_probability(n: i32, k: i32, row: i32, column: i32) -> f64 {
        let n = n as usize;
        let k = k as usize;

        let mut f = vec![vec![vec![0.0; n]; n]; k + 1];

        for i in 0..n {
            for j in 0..n {
                f[0][i][j] = 1.0;
            }
        }

        let dirs = [-2, -1, 2, 1, -2, 1, 2, -1, -2];

        for h in 1..=k {
            for i in 0..n {
                for j in 0..n {
                    for p in 0..8 {
                        let x = i as isize + dirs[p];
                        let y = j as isize + dirs[p + 1];

                        if x >= 0 && x < n as isize && y >= 0 && y < n as isize {
                            let x = x as usize;
                            let y = y as usize;
                            f[h][i][j] += f[h - 1][x][y] / 8.0;
                        }
                    }
                }
            }
        }

        f[k][row as usize][column as usize]
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [689. 三个无重叠子数组的最大和](https://leetcode.cn/problems/maximum-sum-of-3-non-overlapping-subarrays){#689}

{{< tabs "689" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxSumOfThreeSubarrays(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        s = list(accumulate(nums, initial=0))
        pre = [[] for _ in range(n)]
        suf = [[] for _ in range(n)]
        t = idx = 0
        for i in range(n - k + 1):
            if (cur := s[i + k] - s[i]) > t:
                pre[i + k - 1] = [cur, i]
                t, idx = pre[i + k - 1]
            else:
                pre[i + k - 1] = [t, idx]
        t = idx = 0
        for i in range(n - k, -1, -1):
            if (cur := s[i + k] - s[i]) >= t:
                suf[i] = [cur, i]
                t, idx = suf[i]
            else:
                suf[i] = [t, idx]
        t = 0
        ans = []
        for i in range(k, n - 2 * k + 1):
            if (cur := s[i + k] - s[i] + pre[i - 1][0] + suf[i + k][0]) > t:
                ans = [pre[i - 1][1], i, suf[i + k][1]]
                t = cur
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] maxSumOfThreeSubarrays(int[] nums, int k) {
        int n = nums.length;
        int[] s = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
        int[][] pre = new int[n][0];
        int[][] suf = new int[n][0];
        for (int i = 0, t = 0, idx = 0; i < n - k + 1; ++i) {
            int cur = s[i + k] - s[i];
            if (cur > t) {
                pre[i + k - 1] = new int[] {cur, i};
                t = cur;
                idx = i;
            } else {
                pre[i + k - 1] = new int[] {t, idx};
            }
        }
        for (int i = n - k, t = 0, idx = 0; i >= 0; --i) {
            int cur = s[i + k] - s[i];
            if (cur >= t) {
                suf[i] = new int[] {cur, i};
                t = cur;
                idx = i;
            } else {
                suf[i] = new int[] {t, idx};
            }
        }
        int[] ans = new int[0];
        for (int i = k, t = 0; i < n - 2 * k + 1; ++i) {
            int cur = s[i + k] - s[i] + pre[i - 1][0] + suf[i + k][0];
            if (cur > t) {
                ans = new int[] {pre[i - 1][1], i, suf[i + k][1]};
                t = cur;
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
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> s(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }

        vector<vector<int>> pre(n, vector<int>(2, 0));
        vector<vector<int>> suf(n, vector<int>(2, 0));

        for (int i = 0, t = 0, idx = 0; i < n - k + 1; ++i) {
            int cur = s[i + k] - s[i];
            if (cur > t) {
                pre[i + k - 1] = {cur, i};
                t = cur;
                idx = i;
            } else {
                pre[i + k - 1] = {t, idx};
            }
        }

        for (int i = n - k, t = 0, idx = 0; i >= 0; --i) {
            int cur = s[i + k] - s[i];
            if (cur >= t) {
                suf[i] = {cur, i};
                t = cur;
                idx = i;
            } else {
                suf[i] = {t, idx};
            }
        }

        vector<int> ans;
        for (int i = k, t = 0; i < n - 2 * k + 1; ++i) {
            int cur = s[i + k] - s[i] + pre[i - 1][0] + suf[i + k][0];
            if (cur > t) {
                ans = {pre[i - 1][1], i, suf[i + k][1]};
                t = cur;
            }
        }

        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxSumOfThreeSubarrays(nums []int, k int) (ans []int) {
	n := len(nums)
	s := make([]int, n+1)
	for i := 0; i < n; i++ {
		s[i+1] = s[i] + nums[i]
	}

	pre := make([][]int, n)
	suf := make([][]int, n)

	for i, t, idx := 0, 0, 0; i < n-k+1; i++ {
		cur := s[i+k] - s[i]
		if cur > t {
			pre[i+k-1] = []int{cur, i}
			t, idx = cur, i
		} else {
			pre[i+k-1] = []int{t, idx}
		}
	}

	for i, t, idx := n-k, 0, 0; i >= 0; i-- {
		cur := s[i+k] - s[i]
		if cur >= t {
			suf[i] = []int{cur, i}
			t, idx = cur, i
		} else {
			suf[i] = []int{t, idx}
		}
	}

	for i, t := k, 0; i < n-2*k+1; i++ {
		cur := s[i+k] - s[i] + pre[i-1][0] + suf[i+k][0]
		if cur > t {
			ans = []int{pre[i-1][1], i, suf[i+k][1]}
			t = cur
		}
	}

	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxSumOfThreeSubarrays(nums: number[], k: number): number[] {
    const n: number = nums.length;
    const s: number[] = Array(n + 1).fill(0);

    for (let i = 0; i < n; ++i) {
        s[i + 1] = s[i] + nums[i];
    }

    const pre: number[][] = Array(n)
        .fill([])
        .map(() => new Array(2).fill(0));
    const suf: number[][] = Array(n)
        .fill([])
        .map(() => new Array(2).fill(0));

    for (let i = 0, t = 0, idx = 0; i < n - k + 1; ++i) {
        const cur: number = s[i + k] - s[i];
        if (cur > t) {
            pre[i + k - 1] = [cur, i];
            t = cur;
            idx = i;
        } else {
            pre[i + k - 1] = [t, idx];
        }
    }

    for (let i = n - k, t = 0, idx = 0; i >= 0; --i) {
        const cur: number = s[i + k] - s[i];
        if (cur >= t) {
            suf[i] = [cur, i];
            t = cur;
            idx = i;
        } else {
            suf[i] = [t, idx];
        }
    }

    let ans: number[] = [];
    for (let i = k, t = 0; i < n - 2 * k + 1; ++i) {
        const cur: number = s[i + k] - s[i] + pre[i - 1][0] + suf[i + k][0];
        if (cur > t) {
            ans = [pre[i - 1][1], i, suf[i + k][1]];
            t = cur;
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

<p>给你一个整数数组 <code>nums</code> 和一个整数 <code>k</code> ，找出三个长度为 <code>k</code> 、互不重叠、且全部数字和最大的子数组，并返回这三个子数组。</p>

<p>以下标的数组形式返回结果，数组中的每一项分别指示每个子数组的起始位置（下标从 <strong>0</strong> 开始）。如果有多个结果，返回字典序最小的一个。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,1,2,6,7,5,1], k = 2
<strong>输出：</strong>[0,3,5]
<strong>解释：</strong>子数组 [1, 2], [2, 6], [7, 5] 对应的起始下标为 [0, 3, 5]。
也可以取 [2, 1], 但是结果 [1, 3, 5] 在字典序上更大。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,1,2,1,2,1,2,1], k = 2
<strong>输出：</strong>[0,2,4]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;&nbsp;2<sup>16</sup></code></li>
	<li><code>1 &lt;= k &lt;= floor(nums.length / 3)</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：滑动窗口

滑动窗口，枚举第三个子数组的位置，同时维护前两个无重叠子数组的最大和及其位置。

时间复杂度 $O(n)$，其中 $n$ 是数组 $nums$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxSumOfThreeSubarrays(self, nums: List[int], k: int) -> List[int]:
        s = s1 = s2 = s3 = 0
        mx1 = mx12 = 0
        idx1, idx12 = 0, ()
        ans = []
        for i in range(k * 2, len(nums)):
            s1 += nums[i - k * 2]
            s2 += nums[i - k]
            s3 += nums[i]
            if i >= k * 3 - 1:
                if s1 > mx1:
                    mx1 = s1
                    idx1 = i - k * 3 + 1
                if mx1 + s2 > mx12:
                    mx12 = mx1 + s2
                    idx12 = (idx1, i - k * 2 + 1)
                if mx12 + s3 > s:
                    s = mx12 + s3
                    ans = [*idx12, i - k + 1]
                s1 -= nums[i - k * 3 + 1]
                s2 -= nums[i - k * 2 + 1]
                s3 -= nums[i - k + 1]
        return ans
```

#### Java

```java
class Solution {
    public int[] maxSumOfThreeSubarrays(int[] nums, int k) {
        int[] ans = new int[3];
        int s = 0, s1 = 0, s2 = 0, s3 = 0;
        int mx1 = 0, mx12 = 0;
        int idx1 = 0, idx121 = 0, idx122 = 0;
        for (int i = k * 2; i < nums.length; ++i) {
            s1 += nums[i - k * 2];
            s2 += nums[i - k];
            s3 += nums[i];
            if (i >= k * 3 - 1) {
                if (s1 > mx1) {
                    mx1 = s1;
                    idx1 = i - k * 3 + 1;
                }
                if (mx1 + s2 > mx12) {
                    mx12 = mx1 + s2;
                    idx121 = idx1;
                    idx122 = i - k * 2 + 1;
                }
                if (mx12 + s3 > s) {
                    s = mx12 + s3;
                    ans = new int[] {idx121, idx122, i - k + 1};
                }
                s1 -= nums[i - k * 3 + 1];
                s2 -= nums[i - k * 2 + 1];
                s3 -= nums[i - k + 1];
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
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> ans(3);
        int s = 0, s1 = 0, s2 = 0, s3 = 0;
        int mx1 = 0, mx12 = 0;
        int idx1 = 0, idx121 = 0, idx122 = 0;
        for (int i = k * 2; i < nums.size(); ++i) {
            s1 += nums[i - k * 2];
            s2 += nums[i - k];
            s3 += nums[i];
            if (i >= k * 3 - 1) {
                if (s1 > mx1) {
                    mx1 = s1;
                    idx1 = i - k * 3 + 1;
                }
                if (mx1 + s2 > mx12) {
                    mx12 = mx1 + s2;
                    idx121 = idx1;
                    idx122 = i - k * 2 + 1;
                }
                if (mx12 + s3 > s) {
                    s = mx12 + s3;
                    ans = {idx121, idx122, i - k + 1};
                }
                s1 -= nums[i - k * 3 + 1];
                s2 -= nums[i - k * 2 + 1];
                s3 -= nums[i - k + 1];
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maxSumOfThreeSubarrays(nums []int, k int) []int {
	ans := make([]int, 3)
	s, s1, s2, s3 := 0, 0, 0, 0
	mx1, mx12 := 0, 0
	idx1, idx121, idx122 := 0, 0, 0
	for i := k * 2; i < len(nums); i++ {
		s1 += nums[i-k*2]
		s2 += nums[i-k]
		s3 += nums[i]
		if i >= k*3-1 {
			if s1 > mx1 {
				mx1 = s1
				idx1 = i - k*3 + 1
			}
			if mx1+s2 > mx12 {
				mx12 = mx1 + s2
				idx121 = idx1
				idx122 = i - k*2 + 1
			}
			if mx12+s3 > s {
				s = mx12 + s3
				ans = []int{idx121, idx122, i - k + 1}
			}
			s1 -= nums[i-k*3+1]
			s2 -= nums[i-k*2+1]
			s3 -= nums[i-k+1]
		}
	}
	return ans
}
```

#### TypeScript

```ts
function maxSumOfThreeSubarrays(nums: number[], k: number): number[] {
    const n: number = nums.length;
    const s: number[] = Array(n + 1).fill(0);

    for (let i = 0; i < n; ++i) {
        s[i + 1] = s[i] + nums[i];
    }

    const pre: number[][] = Array(n)
        .fill([])
        .map(() => new Array(2).fill(0));
    const suf: number[][] = Array(n)
        .fill([])
        .map(() => new Array(2).fill(0));

    for (let i = 0, t = 0, idx = 0; i < n - k + 1; ++i) {
        const cur: number = s[i + k] - s[i];
        if (cur > t) {
            pre[i + k - 1] = [cur, i];
            t = cur;
            idx = i;
        } else {
            pre[i + k - 1] = [t, idx];
        }
    }

    for (let i = n - k, t = 0, idx = 0; i >= 0; --i) {
        const cur: number = s[i + k] - s[i];
        if (cur >= t) {
            suf[i] = [cur, i];
            t = cur;
            idx = i;
        } else {
            suf[i] = [t, idx];
        }
    }

    let ans: number[] = [];
    for (let i = k, t = 0; i < n - 2 * k + 1; ++i) {
        const cur: number = s[i + k] - s[i] + pre[i - 1][0] + suf[i + k][0];
        if (cur > t) {
            ans = [pre[i - 1][1], i, suf[i + k][1]];
            t = cur;
        }
    }

    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：预处理前后缀 + 枚举中间子数组

我们可以预处理得到数组 $nums$ 的前缀和数组 $s$，其中 $s[i] = \sum_{j=0}^{i-1} nums[j]$，那么对于任意的 $i$，$j$，$s[j] - s[i]$ 就是子数组 $[i, j)$ 的和。

接下来，我们使用动态规划的方法，维护两个长度为 $n$ 的数组 $pre$ 和 $suf$，其中 $pre[i]$ 表示 $[0, i]$ 范围内长度为 $k$ 的子数组的最大和及其起始位置，$suf[i]$ 表示 $[i, n)$ 范围内长度为 $k$ 的子数组的最大和及其起始位置。

然后，我们枚举中间子数组的起始位置 $i$，那么三个子数组的和就是 $pre[i-1][0] + suf[i+k][0] + (s[i+k] - s[i])$，其中 $pre[i-1][0]$ 表示 $[0, i-1]$ 范围内长度为 $k$ 的子数组的最大和，$suf[i+k][0]$ 表示 $[i+k, n)$ 范围内长度为 $k$ 的子数组的最大和，$(s[i+k] - s[i])$ 表示 $[i, i+k)$ 范围内长度为 $k$ 的子数组的和。我们找出和的最大值对应的三个子数组的起始位置即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxSumOfThreeSubarrays(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        s = list(accumulate(nums, initial=0))
        pre = [[] for _ in range(n)]
        suf = [[] for _ in range(n)]
        t = idx = 0
        for i in range(n - k + 1):
            if (cur := s[i + k] - s[i]) > t:
                pre[i + k - 1] = [cur, i]
                t, idx = pre[i + k - 1]
            else:
                pre[i + k - 1] = [t, idx]
        t = idx = 0
        for i in range(n - k, -1, -1):
            if (cur := s[i + k] - s[i]) >= t:
                suf[i] = [cur, i]
                t, idx = suf[i]
            else:
                suf[i] = [t, idx]
        t = 0
        ans = []
        for i in range(k, n - 2 * k + 1):
            if (cur := s[i + k] - s[i] + pre[i - 1][0] + suf[i + k][0]) > t:
                ans = [pre[i - 1][1], i, suf[i + k][1]]
                t = cur
        return ans
```

#### Java

```java
class Solution {
    public int[] maxSumOfThreeSubarrays(int[] nums, int k) {
        int n = nums.length;
        int[] s = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
        int[][] pre = new int[n][0];
        int[][] suf = new int[n][0];
        for (int i = 0, t = 0, idx = 0; i < n - k + 1; ++i) {
            int cur = s[i + k] - s[i];
            if (cur > t) {
                pre[i + k - 1] = new int[] {cur, i};
                t = cur;
                idx = i;
            } else {
                pre[i + k - 1] = new int[] {t, idx};
            }
        }
        for (int i = n - k, t = 0, idx = 0; i >= 0; --i) {
            int cur = s[i + k] - s[i];
            if (cur >= t) {
                suf[i] = new int[] {cur, i};
                t = cur;
                idx = i;
            } else {
                suf[i] = new int[] {t, idx};
            }
        }
        int[] ans = new int[0];
        for (int i = k, t = 0; i < n - 2 * k + 1; ++i) {
            int cur = s[i + k] - s[i] + pre[i - 1][0] + suf[i + k][0];
            if (cur > t) {
                ans = new int[] {pre[i - 1][1], i, suf[i + k][1]};
                t = cur;
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
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> s(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }

        vector<vector<int>> pre(n, vector<int>(2, 0));
        vector<vector<int>> suf(n, vector<int>(2, 0));

        for (int i = 0, t = 0, idx = 0; i < n - k + 1; ++i) {
            int cur = s[i + k] - s[i];
            if (cur > t) {
                pre[i + k - 1] = {cur, i};
                t = cur;
                idx = i;
            } else {
                pre[i + k - 1] = {t, idx};
            }
        }

        for (int i = n - k, t = 0, idx = 0; i >= 0; --i) {
            int cur = s[i + k] - s[i];
            if (cur >= t) {
                suf[i] = {cur, i};
                t = cur;
                idx = i;
            } else {
                suf[i] = {t, idx};
            }
        }

        vector<int> ans;
        for (int i = k, t = 0; i < n - 2 * k + 1; ++i) {
            int cur = s[i + k] - s[i] + pre[i - 1][0] + suf[i + k][0];
            if (cur > t) {
                ans = {pre[i - 1][1], i, suf[i + k][1]};
                t = cur;
            }
        }

        return ans;
    }
};
```

#### Go

```go
func maxSumOfThreeSubarrays(nums []int, k int) (ans []int) {
	n := len(nums)
	s := make([]int, n+1)
	for i := 0; i < n; i++ {
		s[i+1] = s[i] + nums[i]
	}

	pre := make([][]int, n)
	suf := make([][]int, n)

	for i, t, idx := 0, 0, 0; i < n-k+1; i++ {
		cur := s[i+k] - s[i]
		if cur > t {
			pre[i+k-1] = []int{cur, i}
			t, idx = cur, i
		} else {
			pre[i+k-1] = []int{t, idx}
		}
	}

	for i, t, idx := n-k, 0, 0; i >= 0; i-- {
		cur := s[i+k] - s[i]
		if cur >= t {
			suf[i] = []int{cur, i}
			t, idx = cur, i
		} else {
			suf[i] = []int{t, idx}
		}
	}

	for i, t := k, 0; i < n-2*k+1; i++ {
		cur := s[i+k] - s[i] + pre[i-1][0] + suf[i+k][0]
		if cur > t {
			ans = []int{pre[i-1][1], i, suf[i+k][1]}
			t = cur
		}
	}

	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
