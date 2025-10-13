---
title: "2390_从字符串中移除星号"
date: 2025-10-08T18:39:12+08:00
weight: 10
tags: [二分查找, 位运算, 前缀和, 动态规划, 单调队列, 双指针, 哈希表, 回溯, 图, 堆（优先队列）, 字符串, 拓扑排序, 数学, 数据库, 数组, 枚举, 栈, 模拟, 滑动窗口, 矩阵, 脑筋急转弯, 队列]
---

{{< markmap >}}
### [2390_从字符串中移除星号](#2390)
#### [栈](#2390)
#### [字符串](#2390)
#### [模拟](#2390)
### [2391_收集垃圾的最少总时间](#2391)
#### [数组](#2391)
#### [字符串](#2391)
#### [前缀和](#2391)
### [2392_给定条件下构造矩阵](#2392)
#### [图](#2392)
#### [拓扑排序](#2392)
#### [数组](#2392)
#### [矩阵](#2392)
### [2393_严格递增的子数组个数 🔒](#2393)
#### [数组](#2393)
#### [数学](#2393)
#### [动态规划](#2393)
### [2394_开除员工 🔒](#2394)
#### [数据库](#2394)
### [2395_和相等的子数组](#2395)
#### [数组](#2395)
#### [哈希表](#2395)
### [2396_严格回文的数字](#2396)
#### [脑筋急转弯](#2396)
#### [数学](#2396)
#### [双指针](#2396)
### [2397_被列覆盖的最多行数](#2397)
#### [位运算](#2397)
#### [数组](#2397)
#### [回溯](#2397)
#### [枚举](#2397)
#### [矩阵](#2397)
### [2398_预算内的最多机器人数目](#2398)
#### [队列](#2398)
#### [数组](#2398)
#### [二分查找](#2398)
#### [前缀和](#2398)
#### [滑动窗口](#2398)
#### [单调队列](#2398)
#### [堆（优先队列）](#2398)
### [2399_检查相同字母间的距离](#2399)
#### [数组](#2399)
#### [哈希表](#2399)
#### [字符串](#2399)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2390_从字符串中移除星号
___
#### 栈
___
#### 字符串
___
#### 模拟
---
### 2391_收集垃圾的最少总时间
___
#### 数组
___
#### 字符串
___
#### 前缀和
---
### 2392_给定条件下构造矩阵
___
#### 图
___
#### 拓扑排序
___
#### 数组
___
#### 矩阵
---
### 2393_严格递增的子数组个数 🔒
___
#### 数组
___
#### 数学
___
#### 动态规划
---
### 2394_开除员工 🔒
___
#### 数据库
---
### 2395_和相等的子数组
___
#### 数组
___
#### 哈希表
---
### 2396_严格回文的数字
___
#### 脑筋急转弯
___
#### 数学
___
#### 双指针
---
### 2397_被列覆盖的最多行数
___
#### 位运算
___
#### 数组
___
#### 回溯
___
#### 枚举
___
#### 矩阵
---
### 2398_预算内的最多机器人数目
___
#### 队列
___
#### 数组
___
#### 二分查找
___
#### 前缀和
___
#### 滑动窗口
___
#### 单调队列
___
#### 堆（优先队列）
---
### 2399_检查相同字母间的距离
___
#### 数组
___
#### 哈希表
___
#### 字符串
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 前缀和 |
| 动态规划 | 单调队列 | 双指针 |
| 哈希表 | 回溯 | 图 |
| 堆（优先队列） | 字符串 | 拓扑排序 |
| 数学 | 数据库 | 数组 |
| 枚举 | 栈 | 模拟 |
| 滑动窗口 | 矩阵 | 脑筋急转弯 |
| 队列 |  |  |

# [2390. 从字符串中移除星号](https://leetcode.cn/problems/removing-stars-from-a-string){#2390}

{{< tabs "2390" >}}

{{% tab "python" %}}
```python
class Solution:
    def removeStars(self, s: str) -> str:
        ans = []
        for c in s:
            if c == '*':
                ans.pop()
            else:
                ans.append(c)
        return ''.join(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String removeStars(String s) {
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == '*') {
                ans.deleteCharAt(ans.length() - 1);
            } else {
                ans.append(s.charAt(i));
            }
        }
        return ans.toString();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string removeStars(string s) {
        string ans;
        for (char c : s) {
            if (c == '*') {
                ans.pop_back();
            } else {
                ans.push_back(c);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func removeStars(s string) string {
	ans := []rune{}
	for _, c := range s {
		if c == '*' {
			ans = ans[:len(ans)-1]
		} else {
			ans = append(ans, c)
		}
	}
	return string(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function removeStars(s: string): string {
    const ans: string[] = [];
    for (const c of s) {
        if (c === '*') {
            ans.pop();
        } else {
            ans.push(c);
        }
    }
    return ans.join('');
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn remove_stars(s: String) -> String {
        let mut ans = String::new();
        for &c in s.as_bytes().iter() {
            if c == b'*' {
                ans.pop();
            } else {
                ans.push(char::from(c));
            }
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param String $s
     * @return String
     */
    function removeStars($s) {
        $ans = [];
        $n = strlen($s);
        for ($i = 0; $i < $n; $i++) {
            $c = $s[$i];
            if ($c === '*') {
                array_pop($ans);
            } else {
                $ans[] = $c;
            }
        }
        return implode('', $ans);
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个包含若干星号 <code>*</code> 的字符串 <code>s</code> 。</p>

<p>在一步操作中，你可以：</p>

<ul>
	<li>选中 <code>s</code> 中的一个星号。</li>
	<li>移除星号 <strong>左侧</strong> 最近的那个 <strong>非星号</strong> 字符，并移除该星号自身。</li>
</ul>

<p>返回移除 <strong>所有</strong> 星号之后的字符串<strong>。</strong></p>

<p><strong>注意：</strong></p>

<ul>
	<li>生成的输入保证总是可以执行题面中描述的操作。</li>
	<li>可以证明结果字符串是唯一的。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "leet**cod*e"
<strong>输出：</strong>"lecoe"
<strong>解释：</strong>从左到右执行移除操作：
- 距离第 1 个星号最近的字符是 "lee<em><strong>t</strong></em>**cod*e" 中的 't' ，s 变为 "lee*cod*e" 。
- 距离第 2 个星号最近的字符是 "le<em><strong>e</strong></em>*cod*e" 中的 'e' ，s 变为 "lecod*e" 。
- 距离第 3 个星号最近的字符是 "leco<em><strong>d</strong></em>*e" 中的 'd' ，s 变为 "lecoe" 。
不存在其他星号，返回 "lecoe" 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "erase*****"
<strong>输出：</strong>""
<strong>解释：</strong>整个字符串都会被移除，所以返回空字符串。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> 由小写英文字母和星号 <code>*</code> 组成</li>
	<li><code>s</code> 可以执行上述操作</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：栈模拟

我们可以使用栈模拟操作过程。遍历字符串 $s$，如果当前字符不是星号，则将其入栈；如果当前字符是星号，则将栈顶元素出栈。

最后我们将栈中元素拼接成字符串返回即可。

时间复杂度 $O(n)$，其中 $n$ 是字符串 $s$ 的长度。忽略答案字符串的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def removeStars(self, s: str) -> str:
        ans = []
        for c in s:
            if c == '*':
                ans.pop()
            else:
                ans.append(c)
        return ''.join(ans)
```

#### Java

```java
class Solution {
    public String removeStars(String s) {
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == '*') {
                ans.deleteCharAt(ans.length() - 1);
            } else {
                ans.append(s.charAt(i));
            }
        }
        return ans.toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string removeStars(string s) {
        string ans;
        for (char c : s) {
            if (c == '*') {
                ans.pop_back();
            } else {
                ans.push_back(c);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func removeStars(s string) string {
	ans := []rune{}
	for _, c := range s {
		if c == '*' {
			ans = ans[:len(ans)-1]
		} else {
			ans = append(ans, c)
		}
	}
	return string(ans)
}
```

#### TypeScript

```ts
function removeStars(s: string): string {
    const ans: string[] = [];
    for (const c of s) {
        if (c === '*') {
            ans.pop();
        } else {
            ans.push(c);
        }
    }
    return ans.join('');
}
```

#### Rust

```rust
impl Solution {
    pub fn remove_stars(s: String) -> String {
        let mut ans = String::new();
        for &c in s.as_bytes().iter() {
            if c == b'*' {
                ans.pop();
            } else {
                ans.push(char::from(c));
            }
        }
        ans
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param String $s
     * @return String
     */
    function removeStars($s) {
        $ans = [];
        $n = strlen($s);
        for ($i = 0; $i < $n; $i++) {
            $c = $s[$i];
            if ($c === '*') {
                array_pop($ans);
            } else {
                $ans[] = $c;
            }
        }
        return implode('', $ans);
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2391. 收集垃圾的最少总时间](https://leetcode.cn/problems/minimum-amount-of-time-to-collect-garbage){#2391}

{{< tabs "2391" >}}

{{% tab "python" %}}
```python
class Solution:
    def garbageCollection(self, garbage: List[str], travel: List[int]) -> int:
        last = {}
        ans = 0
        for i, s in enumerate(garbage):
            ans += len(s)
            for c in s:
                last[c] = i
        ts = 0
        for i, t in enumerate(travel, 1):
            ts += t
            ans += sum(ts for j in last.values() if i == j)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int garbageCollection(String[] garbage, int[] travel) {
        Map<Character, Integer> last = new HashMap<>(3);
        int ans = 0;
        for (int i = 0; i < garbage.length; ++i) {
            String s = garbage[i];
            ans += s.length();
            for (char c : s.toCharArray()) {
                last.put(c, i);
            }
        }
        int ts = 0;
        for (int i = 1; i <= travel.length; ++i) {
            ts += travel[i - 1];
            for (int j : last.values()) {
                if (i == j) {
                    ans += ts;
                }
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
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        unordered_map<char, int> last;
        int ans = 0;
        for (int i = 0; i < garbage.size(); ++i) {
            auto& s = garbage[i];
            ans += s.size();
            for (char& c : s) {
                last[c] = i;
            }
        }
        int ts = 0;
        for (int i = 1; i <= travel.size(); ++i) {
            ts += travel[i - 1];
            for (auto& [_, j] : last) {
                if (i == j) {
                    ans += ts;
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
func garbageCollection(garbage []string, travel []int) (ans int) {
	last := map[byte]int{}
	for i, s := range garbage {
		ans += len(s)
		for j := range s {
			last[s[j]] = i
		}
	}
	ts := 0
	for i := 1; i <= len(travel); i++ {
		ts += travel[i-1]
		for _, j := range last {
			if i == j {
				ans += ts
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function garbageCollection(garbage: string[], travel: number[]): number {
    const last: Map<string, number> = new Map();
    let ans = 0;
    for (let i = 0; i < garbage.length; ++i) {
        const s = garbage[i];
        ans += s.length;
        for (const c of s) {
            last.set(c, i);
        }
    }
    let ts = 0;
    for (let i = 1; i <= travel.length; ++i) {
        ts += travel[i - 1];
        for (const [_, j] of last) {
            if (i === j) {
                ans += ts;
            }
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    pub fn garbage_collection(garbage: Vec<String>, travel: Vec<i32>) -> i32 {
        let mut last: HashMap<char, usize> = HashMap::new();
        let mut ans = 0;
        for (i, s) in garbage.iter().enumerate() {
            ans += s.len() as i32;
            for c in s.chars() {
                last.insert(c, i);
            }
        }
        let mut ts = 0;
        for (i, t) in travel.iter().enumerate() {
            ts += t;
            for &j in last.values() {
                if i + 1 == j {
                    ans += ts;
                }
            }
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int GarbageCollection(string[] garbage, int[] travel) {
        Dictionary<char, int> last = new Dictionary<char, int>();
        int ans = 0;
        for (int i = 0; i < garbage.Length; ++i) {
            ans += garbage[i].Length;
            foreach (char c in garbage[i]) {
                last[c] = i;
            }
        }
        int ts = 0;
        for (int i = 1; i <= travel.Length; ++i) {
            ts += travel[i - 1];
            foreach (int j in last.Values) {
                if (i == j) {
                    ans += ts;
                }
            }
        }
        return ans;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的字符串数组&nbsp;<code>garbage</code>&nbsp;，其中&nbsp;<code>garbage[i]</code>&nbsp;表示第 <code>i</code>&nbsp;个房子的垃圾集合。<code>garbage[i]</code>&nbsp;只包含字符&nbsp;<code>'M'</code>&nbsp;，<code>'P'</code> 和&nbsp;<code>'G'</code>&nbsp;，但可能包含多个相同字符，每个字符分别表示一单位的金属、纸和玻璃。垃圾车收拾 <strong>一</strong>&nbsp;单位的任何一种垃圾都需要花费&nbsp;<code>1</code>&nbsp;分钟。</p>

<p>同时给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>travel</code>&nbsp;，其中&nbsp;<code>travel[i]</code>&nbsp;是垃圾车从房子 <code>i</code>&nbsp;行驶到房子 <code>i + 1</code>&nbsp;需要的分钟数。</p>

<p>城市里总共有三辆垃圾车，分别收拾三种垃圾。每辆垃圾车都从房子 <code>0</code>&nbsp;出发，<strong>按顺序</strong>&nbsp;到达每一栋房子。但它们 <strong>不是必须</strong>&nbsp;到达所有的房子。</p>

<p>任何时刻只有 <strong>一辆</strong>&nbsp;垃圾车处在使用状态。当一辆垃圾车在行驶或者收拾垃圾的时候，另外两辆车 <strong>不能</strong>&nbsp;做任何事情。</p>

<p>请你返回收拾完所有垃圾需要花费的 <strong>最少</strong>&nbsp;总分钟数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>garbage = ["G","P","GP","GG"], travel = [2,4,3]
<b>输出：</b>21
<strong>解释：</strong>
收拾纸的垃圾车：
1. 从房子 0 行驶到房子 1
2. 收拾房子 1 的纸垃圾
3. 从房子 1 行驶到房子 2
4. 收拾房子 2 的纸垃圾
收拾纸的垃圾车总共花费 8 分钟收拾完所有的纸垃圾。
收拾玻璃的垃圾车：
1. 收拾房子 0 的玻璃垃圾
2. 从房子 0 行驶到房子 1
3. 从房子 1 行驶到房子 2
4. 收拾房子 2 的玻璃垃圾
5. 从房子 2 行驶到房子 3
6. 收拾房子 3 的玻璃垃圾
收拾玻璃的垃圾车总共花费 13 分钟收拾完所有的玻璃垃圾。
由于没有金属垃圾，收拾金属的垃圾车不需要花费任何时间。
所以总共花费 8 + 13 = 21 分钟收拾完所有垃圾。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>garbage = ["MMM","PGM","GP"], travel = [3,10]
<b>输出：</b>37
<strong>解释：</strong>
收拾金属的垃圾车花费 7 分钟收拾完所有的金属垃圾。
收拾纸的垃圾车花费 15 分钟收拾完所有的纸垃圾。
收拾玻璃的垃圾车花费 15 分钟收拾完所有的玻璃垃圾。
总共花费 7 + 15 + 15 = 37 分钟收拾完所有的垃圾。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= garbage.length &lt;= 10<sup>5</sup></code></li>
	<li><code>garbage[i]</code> 只包含字母&nbsp;<code>'M'</code>&nbsp;，<code>'P'</code>&nbsp;和&nbsp;<code>'G'</code>&nbsp;。</li>
	<li><code>1 &lt;= garbage[i].length &lt;= 10</code></li>
	<li><code>travel.length == garbage.length - 1</code></li>
	<li><code>1 &lt;= travel[i] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 前缀和

根据题目描述，每一辆垃圾车从房子 $0$ 出发，收集其中一种垃圾，按顺序前进，直到到达该种垃圾最后出现的房子下标为止。

因此，我们可以用一个哈希表 $\textit{last}$ 记录每种垃圾最后出现的房子下标。我们假设第 $i$ 种垃圾最后一次出现在第 $j$ 个房子，那么第 $i$ 辆车所需要的行驶时间为 $\textit{travel}[0] + \textit{travel}[1] + \cdots + \textit{travel}[j-1]$。注意，如果 $j = 0$，则不需要行驶时间。我们通过前缀和累计所有车辆的行驶时间，加上每种垃圾的总收集时间，即可得到答案。

时间复杂度 $O(n)$，空间复杂度 $O(k)$，其中 $n$ 和 $k$ 分别是垃圾的数量和种类。本题中 $k = 3$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def garbageCollection(self, garbage: List[str], travel: List[int]) -> int:
        last = {}
        ans = 0
        for i, s in enumerate(garbage):
            ans += len(s)
            for c in s:
                last[c] = i
        ts = 0
        for i, t in enumerate(travel, 1):
            ts += t
            ans += sum(ts for j in last.values() if i == j)
        return ans
```

#### Java

```java
class Solution {
    public int garbageCollection(String[] garbage, int[] travel) {
        Map<Character, Integer> last = new HashMap<>(3);
        int ans = 0;
        for (int i = 0; i < garbage.length; ++i) {
            String s = garbage[i];
            ans += s.length();
            for (char c : s.toCharArray()) {
                last.put(c, i);
            }
        }
        int ts = 0;
        for (int i = 1; i <= travel.length; ++i) {
            ts += travel[i - 1];
            for (int j : last.values()) {
                if (i == j) {
                    ans += ts;
                }
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
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        unordered_map<char, int> last;
        int ans = 0;
        for (int i = 0; i < garbage.size(); ++i) {
            auto& s = garbage[i];
            ans += s.size();
            for (char& c : s) {
                last[c] = i;
            }
        }
        int ts = 0;
        for (int i = 1; i <= travel.size(); ++i) {
            ts += travel[i - 1];
            for (auto& [_, j] : last) {
                if (i == j) {
                    ans += ts;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func garbageCollection(garbage []string, travel []int) (ans int) {
	last := map[byte]int{}
	for i, s := range garbage {
		ans += len(s)
		for j := range s {
			last[s[j]] = i
		}
	}
	ts := 0
	for i := 1; i <= len(travel); i++ {
		ts += travel[i-1]
		for _, j := range last {
			if i == j {
				ans += ts
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function garbageCollection(garbage: string[], travel: number[]): number {
    const last: Map<string, number> = new Map();
    let ans = 0;
    for (let i = 0; i < garbage.length; ++i) {
        const s = garbage[i];
        ans += s.length;
        for (const c of s) {
            last.set(c, i);
        }
    }
    let ts = 0;
    for (let i = 1; i <= travel.length; ++i) {
        ts += travel[i - 1];
        for (const [_, j] of last) {
            if (i === j) {
                ans += ts;
            }
        }
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn garbage_collection(garbage: Vec<String>, travel: Vec<i32>) -> i32 {
        let mut last: HashMap<char, usize> = HashMap::new();
        let mut ans = 0;
        for (i, s) in garbage.iter().enumerate() {
            ans += s.len() as i32;
            for c in s.chars() {
                last.insert(c, i);
            }
        }
        let mut ts = 0;
        for (i, t) in travel.iter().enumerate() {
            ts += t;
            for &j in last.values() {
                if i + 1 == j {
                    ans += ts;
                }
            }
        }
        ans
    }
}
```

#### C#

```cs
public class Solution {
    public int GarbageCollection(string[] garbage, int[] travel) {
        Dictionary<char, int> last = new Dictionary<char, int>();
        int ans = 0;
        for (int i = 0; i < garbage.Length; ++i) {
            ans += garbage[i].Length;
            foreach (char c in garbage[i]) {
                last[c] = i;
            }
        }
        int ts = 0;
        for (int i = 1; i <= travel.Length; ++i) {
            ts += travel[i - 1];
            foreach (int j in last.Values) {
                if (i == j) {
                    ans += ts;
                }
            }
        }
        return ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2392. 给定条件下构造矩阵](https://leetcode.cn/problems/build-a-matrix-with-conditions){#2392}

{{< tabs "2392" >}}

{{% tab "python" %}}
```python
class Solution:
    def buildMatrix(
        self, k: int, rowConditions: List[List[int]], colConditions: List[List[int]]
    ) -> List[List[int]]:
        def f(cond):
            g = defaultdict(list)
            indeg = [0] * (k + 1)
            for a, b in cond:
                g[a].append(b)
                indeg[b] += 1
            q = deque([i for i, v in enumerate(indeg[1:], 1) if v == 0])
            res = []
            while q:
                for _ in range(len(q)):
                    i = q.popleft()
                    res.append(i)
                    for j in g[i]:
                        indeg[j] -= 1
                        if indeg[j] == 0:
                            q.append(j)
            return None if len(res) != k else res

        row = f(rowConditions)
        col = f(colConditions)
        if row is None or col is None:
            return []
        ans = [[0] * k for _ in range(k)]
        m = [0] * (k + 1)
        for i, v in enumerate(col):
            m[v] = i
        for i, v in enumerate(row):
            ans[i][m[v]] = v
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int k;

    public int[][] buildMatrix(int k, int[][] rowConditions, int[][] colConditions) {
        this.k = k;
        List<Integer> row = f(rowConditions);
        List<Integer> col = f(colConditions);
        if (row == null || col == null) {
            return new int[0][0];
        }
        int[][] ans = new int[k][k];
        int[] m = new int[k + 1];
        for (int i = 0; i < k; ++i) {
            m[col.get(i)] = i;
        }
        for (int i = 0; i < k; ++i) {
            ans[i][m[row.get(i)]] = row.get(i);
        }
        return ans;
    }

    private List<Integer> f(int[][] cond) {
        List<Integer>[] g = new List[k + 1];
        Arrays.setAll(g, key -> new ArrayList<>());
        int[] indeg = new int[k + 1];
        for (var e : cond) {
            int a = e[0], b = e[1];
            g[a].add(b);
            ++indeg[b];
        }
        Deque<Integer> q = new ArrayDeque<>();
        for (int i = 1; i < indeg.length; ++i) {
            if (indeg[i] == 0) {
                q.offer(i);
            }
        }
        List<Integer> res = new ArrayList<>();
        while (!q.isEmpty()) {
            for (int n = q.size(); n > 0; --n) {
                int i = q.pollFirst();
                res.add(i);
                for (int j : g[i]) {
                    if (--indeg[j] == 0) {
                        q.offer(j);
                    }
                }
            }
        }
        return res.size() == k ? res : null;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int k;

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        this->k = k;
        auto row = f(rowConditions);
        auto col = f(colConditions);
        if (row.empty() || col.empty()) return {};
        vector<vector<int>> ans(k, vector<int>(k));
        vector<int> m(k + 1);
        for (int i = 0; i < k; ++i) {
            m[col[i]] = i;
        }
        for (int i = 0; i < k; ++i) {
            ans[i][m[row[i]]] = row[i];
        }
        return ans;
    }

    vector<int> f(vector<vector<int>>& cond) {
        vector<vector<int>> g(k + 1);
        vector<int> indeg(k + 1);
        for (auto& e : cond) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            ++indeg[b];
        }
        queue<int> q;
        for (int i = 1; i < k + 1; ++i) {
            if (!indeg[i]) {
                q.push(i);
            }
        }
        vector<int> res;
        while (!q.empty()) {
            for (int n = q.size(); n; --n) {
                int i = q.front();
                res.push_back(i);
                q.pop();
                for (int j : g[i]) {
                    if (--indeg[j] == 0) {
                        q.push(j);
                    }
                }
            }
        }
        return res.size() == k ? res : vector<int>();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func buildMatrix(k int, rowConditions [][]int, colConditions [][]int) [][]int {
	f := func(cond [][]int) []int {
		g := make([][]int, k+1)
		indeg := make([]int, k+1)
		for _, e := range cond {
			a, b := e[0], e[1]
			g[a] = append(g[a], b)
			indeg[b]++
		}
		q := []int{}
		for i, v := range indeg[1:] {
			if v == 0 {
				q = append(q, i+1)
			}
		}
		res := []int{}
		for len(q) > 0 {
			for n := len(q); n > 0; n-- {
				i := q[0]
				q = q[1:]
				res = append(res, i)
				for _, j := range g[i] {
					indeg[j]--
					if indeg[j] == 0 {
						q = append(q, j)
					}
				}
			}
		}
		if len(res) == k {
			return res
		}
		return []int{}
	}

	row := f(rowConditions)
	col := f(colConditions)
	if len(row) == 0 || len(col) == 0 {
		return [][]int{}
	}
	m := make([]int, k+1)
	for i, v := range col {
		m[v] = i
	}
	ans := make([][]int, k)
	for i := range ans {
		ans[i] = make([]int, k)
	}
	for i, v := range row {
		ans[i][m[v]] = v
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function buildMatrix(k: number, rowConditions: number[][], colConditions: number[][]): number[][] {
    function f(cond) {
        const g = Array.from({ length: k + 1 }, () => []);
        const indeg = new Array(k + 1).fill(0);
        for (const [a, b] of cond) {
            g[a].push(b);
            ++indeg[b];
        }
        const q = [];
        for (let i = 1; i < indeg.length; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        const res = [];
        while (q.length) {
            for (let n = q.length; n; --n) {
                const i = q.shift();
                res.push(i);
                for (const j of g[i]) {
                    if (--indeg[j] == 0) {
                        q.push(j);
                    }
                }
            }
        }
        return res.length == k ? res : [];
    }

    const row = f(rowConditions);
    const col = f(colConditions);
    if (!row.length || !col.length) return [];
    const ans = Array.from({ length: k }, () => new Array(k).fill(0));
    const m = new Array(k + 1).fill(0);
    for (let i = 0; i < k; ++i) {
        m[col[i]] = i;
    }
    for (let i = 0; i < k; ++i) {
        ans[i][m[row[i]]] = row[i];
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

<p>给你一个 <strong>正</strong>&nbsp;整数&nbsp;<code>k</code>&nbsp;，同时给你：</p>

<ul>
	<li>一个大小为 <code>n</code>&nbsp;的二维整数数组&nbsp;<code>rowConditions</code>&nbsp;，其中&nbsp;<code>rowConditions[i] = [above<sub>i</sub>, below<sub>i</sub>]</code>&nbsp;和</li>
	<li>一个大小为 <code>m</code>&nbsp;的二维整数数组&nbsp;<code>colConditions</code>&nbsp;，其中&nbsp;<code>colConditions[i] = [left<sub>i</sub>, right<sub>i</sub>]</code>&nbsp;。</li>
</ul>

<p>两个数组里的整数都是&nbsp;<code>1</code>&nbsp;到&nbsp;<code>k</code>&nbsp;之间的数字。</p>

<p>你需要构造一个&nbsp;<code>k x k</code>&nbsp;的矩阵，<code>1</code>&nbsp;到&nbsp;<code>k</code>&nbsp;每个数字需要&nbsp;<strong>恰好出现一次</strong>&nbsp;。剩余的数字都是<b>&nbsp;</b><code>0</code>&nbsp;。</p>

<p>矩阵还需要满足以下条件：</p>

<ul>
	<li>对于所有 <code>0</code>&nbsp;到&nbsp;<code>n - 1</code>&nbsp;之间的下标&nbsp;<code>i</code>&nbsp;，数字&nbsp;<code>above<sub>i</sub></code>&nbsp;所在的 <strong>行</strong>&nbsp;必须在数字&nbsp;<code>below<sub>i</sub></code>&nbsp;所在行的上面。</li>
	<li>对于所有 <code>0</code>&nbsp;到 <code>m - 1</code>&nbsp;之间的下标&nbsp;<code>i</code>&nbsp;，数字&nbsp;<code>left<sub>i</sub></code>&nbsp;所在的 <b>列</b>&nbsp;必须在数字&nbsp;<code>right<sub>i</sub></code>&nbsp;所在列的左边。</li>
</ul>

<p>返回满足上述要求的 <strong>任意</strong>&nbsp;矩阵。如果不存在答案，返回一个空的矩阵。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2300-2399/2392.Build%20a%20Matrix%20With%20Conditions/images/gridosdrawio.png" style="width: 211px; height: 211px;"></p>

<pre><b>输入：</b>k = 3, rowConditions = [[1,2],[3,2]], colConditions = [[2,1],[3,2]]
<b>输出：</b>[[3,0,0],[0,0,1],[0,2,0]]
<b>解释：</b>上图为一个符合所有条件的矩阵。
行要求如下：
- 数字 1 在第 <strong>1</strong> 行，数字 2 在第 <strong>2</strong>&nbsp;行，1 在 2 的上面。
- 数字 3 在第 <strong>0</strong>&nbsp;行，数字 2 在第 <strong>2</strong>&nbsp;行，3 在 2 的上面。
列要求如下：
- 数字 2 在第 <strong>1</strong>&nbsp;列，数字 1 在第 <strong>2</strong>&nbsp;列，2 在 1 的左边。
- 数字 3 在第 <strong>0</strong>&nbsp;列，数字 2 在第 <strong>1</strong>&nbsp;列，3 在 2 的左边。
注意，可能有多种正确的答案。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>k = 3, rowConditions = [[1,2],[2,3],[3,1],[2,3]], colConditions = [[2,1]]
<b>输出：</b>[]
<b>解释：</b>由前两个条件可以得到 3 在 1 的下面，但第三个条件是 3 在 1 的上面。
没有符合条件的矩阵存在，所以我们返回空矩阵。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= k &lt;= 400</code></li>
	<li><code>1 &lt;= rowConditions.length, colConditions.length &lt;= 10<sup>4</sup></code></li>
	<li><code>rowConditions[i].length == colConditions[i].length == 2</code></li>
	<li><code>1 &lt;= above<sub>i</sub>, below<sub>i</sub>, left<sub>i</sub>, right<sub>i</sub> &lt;= k</code></li>
	<li><code>above<sub>i</sub> != below<sub>i</sub></code></li>
	<li><code>left<sub>i</sub> != right<sub>i</sub></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：拓扑排序

利用拓扑排序，找到一个合法的 `row` 序列和 `col` 序列，然后根据这两个序列构造出矩阵。

时间复杂度 $O(m+n+k)$。其中 $m$ 和 $n$ 分别为 `rowConditions` 和 `colConditions` 的长度，而 $k$ 为题目中给定的正整数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def buildMatrix(
        self, k: int, rowConditions: List[List[int]], colConditions: List[List[int]]
    ) -> List[List[int]]:
        def f(cond):
            g = defaultdict(list)
            indeg = [0] * (k + 1)
            for a, b in cond:
                g[a].append(b)
                indeg[b] += 1
            q = deque([i for i, v in enumerate(indeg[1:], 1) if v == 0])
            res = []
            while q:
                for _ in range(len(q)):
                    i = q.popleft()
                    res.append(i)
                    for j in g[i]:
                        indeg[j] -= 1
                        if indeg[j] == 0:
                            q.append(j)
            return None if len(res) != k else res

        row = f(rowConditions)
        col = f(colConditions)
        if row is None or col is None:
            return []
        ans = [[0] * k for _ in range(k)]
        m = [0] * (k + 1)
        for i, v in enumerate(col):
            m[v] = i
        for i, v in enumerate(row):
            ans[i][m[v]] = v
        return ans
```

#### Java

```java
class Solution {
    private int k;

    public int[][] buildMatrix(int k, int[][] rowConditions, int[][] colConditions) {
        this.k = k;
        List<Integer> row = f(rowConditions);
        List<Integer> col = f(colConditions);
        if (row == null || col == null) {
            return new int[0][0];
        }
        int[][] ans = new int[k][k];
        int[] m = new int[k + 1];
        for (int i = 0; i < k; ++i) {
            m[col.get(i)] = i;
        }
        for (int i = 0; i < k; ++i) {
            ans[i][m[row.get(i)]] = row.get(i);
        }
        return ans;
    }

    private List<Integer> f(int[][] cond) {
        List<Integer>[] g = new List[k + 1];
        Arrays.setAll(g, key -> new ArrayList<>());
        int[] indeg = new int[k + 1];
        for (var e : cond) {
            int a = e[0], b = e[1];
            g[a].add(b);
            ++indeg[b];
        }
        Deque<Integer> q = new ArrayDeque<>();
        for (int i = 1; i < indeg.length; ++i) {
            if (indeg[i] == 0) {
                q.offer(i);
            }
        }
        List<Integer> res = new ArrayList<>();
        while (!q.isEmpty()) {
            for (int n = q.size(); n > 0; --n) {
                int i = q.pollFirst();
                res.add(i);
                for (int j : g[i]) {
                    if (--indeg[j] == 0) {
                        q.offer(j);
                    }
                }
            }
        }
        return res.size() == k ? res : null;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int k;

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        this->k = k;
        auto row = f(rowConditions);
        auto col = f(colConditions);
        if (row.empty() || col.empty()) return {};
        vector<vector<int>> ans(k, vector<int>(k));
        vector<int> m(k + 1);
        for (int i = 0; i < k; ++i) {
            m[col[i]] = i;
        }
        for (int i = 0; i < k; ++i) {
            ans[i][m[row[i]]] = row[i];
        }
        return ans;
    }

    vector<int> f(vector<vector<int>>& cond) {
        vector<vector<int>> g(k + 1);
        vector<int> indeg(k + 1);
        for (auto& e : cond) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            ++indeg[b];
        }
        queue<int> q;
        for (int i = 1; i < k + 1; ++i) {
            if (!indeg[i]) {
                q.push(i);
            }
        }
        vector<int> res;
        while (!q.empty()) {
            for (int n = q.size(); n; --n) {
                int i = q.front();
                res.push_back(i);
                q.pop();
                for (int j : g[i]) {
                    if (--indeg[j] == 0) {
                        q.push(j);
                    }
                }
            }
        }
        return res.size() == k ? res : vector<int>();
    }
};
```

#### Go

```go
func buildMatrix(k int, rowConditions [][]int, colConditions [][]int) [][]int {
	f := func(cond [][]int) []int {
		g := make([][]int, k+1)
		indeg := make([]int, k+1)
		for _, e := range cond {
			a, b := e[0], e[1]
			g[a] = append(g[a], b)
			indeg[b]++
		}
		q := []int{}
		for i, v := range indeg[1:] {
			if v == 0 {
				q = append(q, i+1)
			}
		}
		res := []int{}
		for len(q) > 0 {
			for n := len(q); n > 0; n-- {
				i := q[0]
				q = q[1:]
				res = append(res, i)
				for _, j := range g[i] {
					indeg[j]--
					if indeg[j] == 0 {
						q = append(q, j)
					}
				}
			}
		}
		if len(res) == k {
			return res
		}
		return []int{}
	}

	row := f(rowConditions)
	col := f(colConditions)
	if len(row) == 0 || len(col) == 0 {
		return [][]int{}
	}
	m := make([]int, k+1)
	for i, v := range col {
		m[v] = i
	}
	ans := make([][]int, k)
	for i := range ans {
		ans[i] = make([]int, k)
	}
	for i, v := range row {
		ans[i][m[v]] = v
	}
	return ans
}
```

#### TypeScript

```ts
function buildMatrix(k: number, rowConditions: number[][], colConditions: number[][]): number[][] {
    function f(cond) {
        const g = Array.from({ length: k + 1 }, () => []);
        const indeg = new Array(k + 1).fill(0);
        for (const [a, b] of cond) {
            g[a].push(b);
            ++indeg[b];
        }
        const q = [];
        for (let i = 1; i < indeg.length; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        const res = [];
        while (q.length) {
            for (let n = q.length; n; --n) {
                const i = q.shift();
                res.push(i);
                for (const j of g[i]) {
                    if (--indeg[j] == 0) {
                        q.push(j);
                    }
                }
            }
        }
        return res.length == k ? res : [];
    }

    const row = f(rowConditions);
    const col = f(colConditions);
    if (!row.length || !col.length) return [];
    const ans = Array.from({ length: k }, () => new Array(k).fill(0));
    const m = new Array(k + 1).fill(0);
    for (let i = 0; i < k; ++i) {
        m[col[i]] = i;
    }
    for (let i = 0; i < k; ++i) {
        ans[i][m[row[i]]] = row[i];
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2393. 严格递增的子数组个数 🔒](https://leetcode.cn/problems/count-strictly-increasing-subarrays){#2393}

{{< tabs "2393" >}}

{{% tab "python" %}}
```python
class Solution:
    def countSubarrays(self, nums: List[int]) -> int:
        ans = cnt = 1
        for x, y in pairwise(nums):
            if x < y:
                cnt += 1
            else:
                cnt = 1
            ans += cnt
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long countSubarrays(int[] nums) {
        long ans = 1, cnt = 1;
        for (int i = 1; i < nums.length; ++i) {
            if (nums[i - 1] < nums[i]) {
                ++cnt;
            } else {
                cnt = 1;
            }
            ans += cnt;
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
    long long countSubarrays(vector<int>& nums) {
        long long ans = 1, cnt = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] < nums[i]) {
                ++cnt;
            } else {
                cnt = 1;
            }
            ans += cnt;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countSubarrays(nums []int) int64 {
	ans, cnt := 1, 1
	for i, x := range nums[1:] {
		if nums[i] < x {
			cnt++
		} else {
			cnt = 1
		}
		ans += cnt
	}
	return int64(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countSubarrays(nums: number[]): number {
    let [ans, cnt] = [1, 1];
    for (let i = 1; i < nums.length; ++i) {
        if (nums[i - 1] < nums[i]) {
            ++cnt;
        } else {
            cnt = 1;
        }
        ans += cnt;
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

<p>给定一个由&nbsp;<strong>正整数&nbsp;</strong>组成的数组 <code>nums</code> 。</p>

<p>返回&nbsp;<em><strong>严格递增&nbsp;</strong>顺序的 </em><code>nums</code><em>&nbsp;<strong>子数组&nbsp;</strong>的数目。</em></p>

<p data-group="1-1"><strong>子数组&nbsp;</strong>是数组的一部分，且是&nbsp;<strong>连续 </strong>的。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>

<pre>
<strong>输入:</strong> nums = [1,3,5,4,4,6]
<strong>输出:</strong> 10
<strong>解释:</strong> 严格递增的子数组如下:
- 长度为 1 的子数组: [1], [3], [5], [4], [4], [6]。
- 长度为 2 的子数组: [1,3], [3,5], [4,6]。
- 长度为 3 的子数组: [1,3,5]。
子数组的总数是 6 + 3 + 1 = 10。
</pre>

<p><strong class="example">示例 2:</strong></p>

<pre>
<strong>输入:</strong> nums = [1,2,3,4,5]
<strong>输出:</strong> 15
<strong>解释:</strong> 每个子数组都严格递增。我们可以取 15 个子数组。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们可以枚举以每个元素结尾的严格递增子数组的个数，然后将它们累加起来即可。

我们用一个变量 $\textit{cnt}$ 来记录以当前元素结尾的严格递增子数组的个数，初始时 $\textit{cnt} = 1$。然后我们从第二个元素开始遍历数组，如果当前元素大于前一个元素，那么 $\textit{cnt}$ 就可以加 $1$，否则 $\textit{cnt}$ 重置为 $1$。此时，以当前元素结尾的严格递增子数组的个数就是 $\textit{cnt}$，我们将其累加到答案中即可。

遍历结束后，返回答案即可。

时间复杂度 $O(n)$，其中 $n$ 为数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countSubarrays(self, nums: List[int]) -> int:
        ans = cnt = 1
        for x, y in pairwise(nums):
            if x < y:
                cnt += 1
            else:
                cnt = 1
            ans += cnt
        return ans
```

#### Java

```java
class Solution {
    public long countSubarrays(int[] nums) {
        long ans = 1, cnt = 1;
        for (int i = 1; i < nums.length; ++i) {
            if (nums[i - 1] < nums[i]) {
                ++cnt;
            } else {
                cnt = 1;
            }
            ans += cnt;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long countSubarrays(vector<int>& nums) {
        long long ans = 1, cnt = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] < nums[i]) {
                ++cnt;
            } else {
                cnt = 1;
            }
            ans += cnt;
        }
        return ans;
    }
};
```

#### Go

```go
func countSubarrays(nums []int) int64 {
	ans, cnt := 1, 1
	for i, x := range nums[1:] {
		if nums[i] < x {
			cnt++
		} else {
			cnt = 1
		}
		ans += cnt
	}
	return int64(ans)
}
```

#### TypeScript

```ts
function countSubarrays(nums: number[]): number {
    let [ans, cnt] = [1, 1];
    for (let i = 1; i < nums.length; ++i) {
        if (nums[i - 1] < nums[i]) {
            ++cnt;
        } else {
            cnt = 1;
        }
        ans += cnt;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2394. 开除员工 🔒](https://leetcode.cn/problems/employees-with-deductions){#2394}

{{< tabs "2394" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            employee_id,
            SUM(ceiling(TIMESTAMPDIFF(second, in_time, out_time) / 60)) / 60 AS tot
        FROM Logs
        GROUP BY employee_id
    )
SELECT employee_id
FROM
    Employees
    LEFT JOIN T USING (employee_id)
WHERE IFNULL(tot, 0) < needed_hours;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Employees</code></p>

<pre>
+--------------+------+
| Column Name  | Type |
+--------------+------+
| employee_id  | int  |
| needed_hours | int  |
+--------------+------+
employee_id 是该表具有的唯一值的列。
每一行都包含员工的 id 和他们获得工资所需的最低工作时数。
</pre>

<p>&nbsp;</p>

<p>表: <code>Logs</code></p>

<pre>
+-------------+----------+
| Column Name | Type     |
+-------------+----------+
| employee_id | int      |
| in_time     | datetime |
| out_time    | datetime |
+-------------+----------+
(employee_id, in_time, out_time) 是该表的主键（具有唯一值的列的组合）。
该表的每一行都显示了员工的时间戳。in_time 是员工开始工作的时间，out_time 是员工结束工作的时间。
所有时间都在 2022 年 10 月。out_time 可以是 in_time 之后的一天，这意味着该员工在午夜之后工作。
</pre>

<p>&nbsp;</p>

<p>在公司里，每个员工每个月必须工作一定的小时数。员工在工作段中工作。员工工作的小时数可以通过员工在所有工作段中工作的分钟数的总和来计算。每个工作段的分钟数是向上取整的。</p>

<ul>
	<li>例如，如果员工在一个时间段中工作了 <code>51</code> 分 <code>2</code> 秒，我们就认为它是 <code>52</code> 分钟。</li>
</ul>

<p>编写解决方案来报告将被开除的员工的 id。换句话说，报告没有工作所需时间的员工的 id。</p>

<p data-group="1-1">以 <strong>任意顺序</strong> 返回结果表。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
Employees 表:
+-------------+--------------+
| employee_id | needed_hours |
+-------------+--------------+
| 1           | 20           |
| 2           | 12           |
| 3           | 2            |
+-------------+--------------+
Logs 表:
+-------------+---------------------+---------------------+
| employee_id | in_time             | out_time            |
+-------------+---------------------+---------------------+
| 1           | 2022-10-01 09:00:00 | 2022-10-01 17:00:00 |
| 1           | 2022-10-06 09:05:04 | 2022-10-06 17:09:03 |
| 1           | 2022-10-12 23:00:00 | 2022-10-13 03:00:01 |
| 2           | 2022-10-29 12:00:00 | 2022-10-29 23:58:58 |
+-------------+---------------------+---------------------+
<strong>输出:</strong> 
+-------------+
| employee_id |
+-------------+
| 2           |
| 3           |
+-------------+
<strong>解释:</strong> 
员工 1:
 - 参加了三个工作段:
    - 在 2022-10-01, 他工作了 8 个小时。
    - 在 2022-10-06, 他工作了 8 小时 4 分钟。
    - 在 2022-10-12, 他工作了 4 小时 1 分钟。请注意，他一直工作到午夜。
 - 员工 1 在各个时段总共工作了 20 小时5分钟，不被开除。
员工 2:
 - 参加了一个工作段:
    - 在 2022-10-29, 他工作了 11 小时 59 分钟。
 - 员工 2 没有工作足够的时长，将被开除。
员工 3:
 - 没有任何工作段。
 - 员工 3 没有工作足够的时长，将被开除。
</pre>

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
    T AS (
        SELECT
            employee_id,
            SUM(ceiling(TIMESTAMPDIFF(second, in_time, out_time) / 60)) / 60 AS tot
        FROM Logs
        GROUP BY employee_id
    )
SELECT employee_id
FROM
    Employees
    LEFT JOIN T USING (employee_id)
WHERE IFNULL(tot, 0) < needed_hours;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2395. 和相等的子数组](https://leetcode.cn/problems/find-subarrays-with-equal-sum){#2395}

{{< tabs "2395" >}}

{{% tab "python" %}}
```python
class Solution:
    def findSubarrays(self, nums: List[int]) -> bool:
        vis = set()
        for a, b in pairwise(nums):
            if (x := a + b) in vis:
                return True
            vis.add(x)
        return False
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean findSubarrays(int[] nums) {
        Set<Integer> vis = new HashSet<>();
        for (int i = 1; i < nums.length; ++i) {
            if (!vis.add(nums[i - 1] + nums[i])) {
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
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> vis;
        for (int i = 1; i < nums.size(); ++i) {
            int x = nums[i - 1] + nums[i];
            if (vis.count(x)) {
                return true;
            }
            vis.insert(x);
        }
        return false;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findSubarrays(nums []int) bool {
	vis := map[int]bool{}
	for i, b := range nums[1:] {
		x := nums[i] + b
		if vis[x] {
			return true
		}
		vis[x] = true
	}
	return false
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findSubarrays(nums: number[]): boolean {
    const vis: Set<number> = new Set<number>();
    for (let i = 1; i < nums.length; ++i) {
        const x = nums[i - 1] + nums[i];
        if (vis.has(x)) {
            return true;
        }
        vis.add(x);
    }
    return false;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashSet;
impl Solution {
    pub fn find_subarrays(nums: Vec<i32>) -> bool {
        let n = nums.len();
        let mut set = HashSet::new();
        for i in 1..n {
            if !set.insert(nums[i - 1] + nums[i]) {
                return true;
            }
        }
        false
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
bool findSubarrays(int* nums, int numsSize) {
    for (int i = 1; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i - 1] + nums[i] == nums[j - 1] + nums[j]) {
                return true;
            }
        }
    }
    return false;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;，判断是否存在&nbsp;<strong>两个</strong>&nbsp;长度为&nbsp;<code>2</code>&nbsp;的子数组且它们的&nbsp;<strong>和</strong>&nbsp;相等。注意，这两个子数组起始位置的下标必须&nbsp;<strong>不相同</strong>&nbsp;。</p>

<p>如果这样的子数组存在，请返回&nbsp;<code>true</code>，否则返回&nbsp;<code>false</code><em>&nbsp;</em>。</p>

<p><strong>子数组</strong> 是一个数组中一段连续非空的元素组成的序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [4,2,4]
<b>输出：</b>true
<b>解释：</b>元素为 [4,2] 和 [2,4] 的子数组有相同的和 6 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [1,2,3,4,5]
<b>输出：</b>false
<b>解释：</b>没有长度为 2 的两个子数组和相等。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>nums = [0,0,0]
<b>输出：</b>true
<b>解释：</b>子数组 [nums[0],nums[1]] 和 [nums[1],nums[2]] 的和相等，都为 0 。
注意即使子数组的元素相同，这两个子数组也视为不相同的子数组，因为它们在原数组中的起始位置不同。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 1000</code></li>
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

我们可以遍历数组 $nums$，用哈希表 $vis$ 记录数组中每两个相邻元素的和，如果当前两个元素的和已经在哈希表中出现过，则返回 `true`，否则将当前两个元素的和加入哈希表中。

遍历结束后，说明没有找到满足条件的两个子数组，返回 `false`。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findSubarrays(self, nums: List[int]) -> bool:
        vis = set()
        for a, b in pairwise(nums):
            if (x := a + b) in vis:
                return True
            vis.add(x)
        return False
```

#### Java

```java
class Solution {
    public boolean findSubarrays(int[] nums) {
        Set<Integer> vis = new HashSet<>();
        for (int i = 1; i < nums.length; ++i) {
            if (!vis.add(nums[i - 1] + nums[i])) {
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
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> vis;
        for (int i = 1; i < nums.size(); ++i) {
            int x = nums[i - 1] + nums[i];
            if (vis.count(x)) {
                return true;
            }
            vis.insert(x);
        }
        return false;
    }
};
```

#### Go

```go
func findSubarrays(nums []int) bool {
	vis := map[int]bool{}
	for i, b := range nums[1:] {
		x := nums[i] + b
		if vis[x] {
			return true
		}
		vis[x] = true
	}
	return false
}
```

#### TypeScript

```ts
function findSubarrays(nums: number[]): boolean {
    const vis: Set<number> = new Set<number>();
    for (let i = 1; i < nums.length; ++i) {
        const x = nums[i - 1] + nums[i];
        if (vis.has(x)) {
            return true;
        }
        vis.add(x);
    }
    return false;
}
```

#### Rust

```rust
use std::collections::HashSet;
impl Solution {
    pub fn find_subarrays(nums: Vec<i32>) -> bool {
        let n = nums.len();
        let mut set = HashSet::new();
        for i in 1..n {
            if !set.insert(nums[i - 1] + nums[i]) {
                return true;
            }
        }
        false
    }
}
```

#### C

```c
bool findSubarrays(int* nums, int numsSize) {
    for (int i = 1; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i - 1] + nums[i] == nums[j - 1] + nums[j]) {
                return true;
            }
        }
    }
    return false;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2396. 严格回文的数字](https://leetcode.cn/problems/strictly-palindromic-number){#2396}

{{< tabs "2396" >}}

{{% tab "python" %}}
```python
class Solution:
    def isStrictlyPalindromic(self, n: int) -> bool:
        return False
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isStrictlyPalindromic(int n) {
        return false;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        return false;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isStrictlyPalindromic(n int) bool {
	return false
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isStrictlyPalindromic(n: number): boolean {
    return false;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn is_strictly_palindromic(n: i32) -> bool {
        false
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
bool isStrictlyPalindromic(int n) {
    return 0;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>如果一个整数 <code>n</code>&nbsp;在 <code>b</code>&nbsp;进制下（<code>b</code>&nbsp;为 <code>2</code>&nbsp;到 <code>n - 2</code>&nbsp;之间的所有整数）对应的字符串&nbsp;<strong>全部</strong>&nbsp;都是 <strong>回文的</strong>&nbsp;，那么我们称这个数&nbsp;<code>n</code>&nbsp;是 <strong>严格回文</strong>&nbsp;的。</p>

<p>给你一个整数&nbsp;<code>n</code>&nbsp;，如果 <code>n</code>&nbsp;是 <strong>严格回文</strong>&nbsp;的，请返回&nbsp;<code>true</code> ，否则返回<em>&nbsp;</em><code>false</code>&nbsp;。</p>

<p>如果一个字符串从前往后读和从后往前读完全相同，那么这个字符串是 <strong>回文的</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>n = 9
<b>输出：</b>false
<b>解释：</b>在 2 进制下：9 = 1001 ，是回文的。
在 3 进制下：9 = 100 ，不是回文的。
所以，9 不是严格回文数字，我们返回 false 。
注意在 4, 5, 6 和 7 进制下，n = 9 都不是回文的。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>n = 4
<b>输出：</b>false
<b>解释：</b>我们只考虑 2 进制：4 = 100 ，不是回文的。
所以我们返回 false 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>4 &lt;= n &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：脑筋急转弯

当 $n = 4$ 时，二进制表示为 $100$，不是回文串；

当 $n \gt 4$ 时，此时 $n - 2$ 进制表示为 $12$，不是回文串。

因此，我们可以直接返回 `false`。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isStrictlyPalindromic(self, n: int) -> bool:
        return False
```

#### Java

```java
class Solution {
    public boolean isStrictlyPalindromic(int n) {
        return false;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        return false;
    }
};
```

#### Go

```go
func isStrictlyPalindromic(n int) bool {
	return false
}
```

#### TypeScript

```ts
function isStrictlyPalindromic(n: number): boolean {
    return false;
}
```

#### Rust

```rust
impl Solution {
    pub fn is_strictly_palindromic(n: i32) -> bool {
        false
    }
}
```

#### C

```c
bool isStrictlyPalindromic(int n) {
    return 0;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2397. 被列覆盖的最多行数](https://leetcode.cn/problems/maximum-rows-covered-by-columns){#2397}

{{< tabs "2397" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumRows(self, matrix: List[List[int]], numSelect: int) -> int:
        rows = []
        for row in matrix:
            mask = reduce(or_, (1 << j for j, x in enumerate(row) if x), 0)
            rows.append(mask)

        ans = 0
        for mask in range(1 << len(matrix[0])):
            if mask.bit_count() != numSelect:
                continue
            t = sum((x & mask) == x for x in rows)
            ans = max(ans, t)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumRows(int[][] matrix, int numSelect) {
        int m = matrix.length, n = matrix[0].length;
        int[] rows = new int[m];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 1) {
                    rows[i] |= 1 << j;
                }
            }
        }
        int ans = 0;
        for (int mask = 1; mask < 1 << n; ++mask) {
            if (Integer.bitCount(mask) != numSelect) {
                continue;
            }
            int t = 0;
            for (int x : rows) {
                if ((x & mask) == x) {
                    ++t;
                }
            }
            ans = Math.max(ans, t);
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
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        int m = matrix.size(), n = matrix[0].size();
        int rows[m];
        memset(rows, 0, sizeof(rows));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j]) {
                    rows[i] |= 1 << j;
                }
            }
        }
        int ans = 0;
        for (int mask = 1; mask < 1 << n; ++mask) {
            if (__builtin_popcount(mask) != numSelect) {
                continue;
            }
            int t = 0;
            for (int x : rows) {
                t += (x & mask) == x;
            }
            ans = max(ans, t);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumRows(matrix [][]int, numSelect int) (ans int) {
	m, n := len(matrix), len(matrix[0])
	rows := make([]int, m)
	for i, row := range matrix {
		for j, x := range row {
			if x == 1 {
				rows[i] |= 1 << j
			}
		}
	}
	for mask := 1; mask < 1<<n; mask++ {
		if bits.OnesCount(uint(mask)) != numSelect {
			continue
		}
		t := 0
		for _, x := range rows {
			if (x & mask) == x {
				t++
			}
		}
		if ans < t {
			ans = t
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumRows(matrix: number[][], numSelect: number): number {
    const [m, n] = [matrix.length, matrix[0].length];
    const rows: number[] = Array(m).fill(0);
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (matrix[i][j]) {
                rows[i] |= 1 << j;
            }
        }
    }
    let ans = 0;
    for (let mask = 1; mask < 1 << n; ++mask) {
        if (bitCount(mask) !== numSelect) {
            continue;
        }
        let t = 0;
        for (const x of rows) {
            if ((x & mask) === x) {
                ++t;
            }
        }
        ans = Math.max(ans, t);
    }
    return ans;
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

<p>给你一个下标从 <strong>0 </strong>开始、大小为 <code>m x n</code> 的二进制矩阵 <code>matrix</code> ；另给你一个整数 <code>numSelect</code>，表示你必须从 <code>matrix</code> 中选择的 <strong>不同</strong> 列的数量。</p>

<p>如果一行中所有的 <code>1</code> 都被你选中的列所覆盖，则认为这一行被 <strong>覆盖</strong> 了。</p>

<p><strong>形式上</strong>，假设 <code>s = {c<sub>1</sub>, c<sub>2</sub>, ...., c<sub>numSelect</sub>}</code> 是你选择的列的集合。对于矩阵中的某一行 <code>row</code> ，如果满足下述条件，则认为这一行被集合 <code>s</code> <strong>覆盖</strong>：</p>

<ul>
	<li>对于满足 <code>matrix[row][col] == 1</code> 的每个单元格 <code>matrix[row][col]</code>（<code>0 &lt;= col &lt;= n - 1</code>），<code>col</code> 均存在于 <code>s</code> 中，或者</li>
	<li><code>row</code> 中 <strong>不存在</strong> 值为 <code>1</code> 的单元格。</li>
</ul>

<p>你需要从矩阵中选出 <code>numSelect</code> 个列，使集合覆盖的行数最大化。</p>

<p>返回一个整数，表示可以由 <code>numSelect</code> 列构成的集合 <strong>覆盖</strong> 的 <strong>最大行数</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2300-2399/2397.Maximum%20Rows%20Covered%20by%20Columns/images/rowscovered.png" style="width: 250px; height: 417px;" /></strong></p>

<pre>
<b>输入：</b>matrix = [[0,0,0],[1,0,1],[0,1,1],[0,0,1]], numSelect = 2
<b>输出：</b>3
<strong>解释：</strong>
图示中显示了一种覆盖 3 行的可行办法。
选择 s = {0, 2} 。
- 第 0 行被覆盖，因为其中没有出现 1 。
- 第 1 行被覆盖，因为值为 1 的两列（即 0 和 2）均存在于 s 中。
- 第 2 行未被覆盖，因为 matrix[2][1] == 1 但是 1 未存在于 s 中。
- 第 3 行被覆盖，因为 matrix[2][2] == 1 且 2 存在于 s 中。
因此，可以覆盖 3 行。
另外 s = {1, 2} 也可以覆盖 3 行，但可以证明无法覆盖更多行。</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2300-2399/2397.Maximum%20Rows%20Covered%20by%20Columns/images/rowscovered2.png" style="width: 83px; height: 247px;" /></strong></p>

<pre>
<b>输入：</b>matrix = [[1],[0]], numSelect = 1
<b>输出：</b>2
<strong>解释：</strong>
选择唯一的一列，两行都被覆盖了，因为整个矩阵都被覆盖了。
所以我们返回 2 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 12</code></li>
	<li><code>matrix[i][j]</code> 要么是 <code>0</code> 要么是 <code>1</code></li>
	<li><code>1 &lt;= numSelect&nbsp;&lt;= n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二进制枚举

我们先将矩阵中的每一行转换成一个二进制数，记录在数组 $rows$ 中，其中 $rows[i]$ 表示第 $i$ 行对应的二进制数，而 $rows[i]$ 这个二进制数的第 $j$ 位表示第 $i$ 行第 $j$ 列的值。

接下来，我们枚举所有的 $2^n$ 种列选择方案，其中 $n$ 为矩阵的列数。对于每一种列选择方案，我们判断是否选中了 `numSelect` 列，如果不是，则跳过。否则，我们统计矩阵中有多少行中的所有 $1$ 都被选中的列覆盖，即统计有多少行的二进制数 $rows[i]$ 与列选择方案 $mask$ 按位与的结果等于 $rows[i]$，并更新最大的行数。

时间复杂度 $O(2^n \times m)$，空间复杂度 $O(m)$。其中 $m$ 和 $n$ 分别为矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumRows(self, matrix: List[List[int]], numSelect: int) -> int:
        rows = []
        for row in matrix:
            mask = reduce(or_, (1 << j for j, x in enumerate(row) if x), 0)
            rows.append(mask)

        ans = 0
        for mask in range(1 << len(matrix[0])):
            if mask.bit_count() != numSelect:
                continue
            t = sum((x & mask) == x for x in rows)
            ans = max(ans, t)
        return ans
```

#### Java

```java
class Solution {
    public int maximumRows(int[][] matrix, int numSelect) {
        int m = matrix.length, n = matrix[0].length;
        int[] rows = new int[m];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 1) {
                    rows[i] |= 1 << j;
                }
            }
        }
        int ans = 0;
        for (int mask = 1; mask < 1 << n; ++mask) {
            if (Integer.bitCount(mask) != numSelect) {
                continue;
            }
            int t = 0;
            for (int x : rows) {
                if ((x & mask) == x) {
                    ++t;
                }
            }
            ans = Math.max(ans, t);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        int m = matrix.size(), n = matrix[0].size();
        int rows[m];
        memset(rows, 0, sizeof(rows));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j]) {
                    rows[i] |= 1 << j;
                }
            }
        }
        int ans = 0;
        for (int mask = 1; mask < 1 << n; ++mask) {
            if (__builtin_popcount(mask) != numSelect) {
                continue;
            }
            int t = 0;
            for (int x : rows) {
                t += (x & mask) == x;
            }
            ans = max(ans, t);
        }
        return ans;
    }
};
```

#### Go

```go
func maximumRows(matrix [][]int, numSelect int) (ans int) {
	m, n := len(matrix), len(matrix[0])
	rows := make([]int, m)
	for i, row := range matrix {
		for j, x := range row {
			if x == 1 {
				rows[i] |= 1 << j
			}
		}
	}
	for mask := 1; mask < 1<<n; mask++ {
		if bits.OnesCount(uint(mask)) != numSelect {
			continue
		}
		t := 0
		for _, x := range rows {
			if (x & mask) == x {
				t++
			}
		}
		if ans < t {
			ans = t
		}
	}
	return
}
```

#### TypeScript

```ts
function maximumRows(matrix: number[][], numSelect: number): number {
    const [m, n] = [matrix.length, matrix[0].length];
    const rows: number[] = Array(m).fill(0);
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (matrix[i][j]) {
                rows[i] |= 1 << j;
            }
        }
    }
    let ans = 0;
    for (let mask = 1; mask < 1 << n; ++mask) {
        if (bitCount(mask) !== numSelect) {
            continue;
        }
        let t = 0;
        for (const x of rows) {
            if ((x & mask) === x) {
                ++t;
            }
        }
        ans = Math.max(ans, t);
    }
    return ans;
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

# [2398. 预算内的最多机器人数目](https://leetcode.cn/problems/maximum-number-of-robots-within-budget){#2398}

{{< tabs "2398" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumRobots(
        self, chargeTimes: List[int], runningCosts: List[int], budget: int
    ) -> int:
        q = deque()
        ans = s = l = 0
        for r, (t, c) in enumerate(zip(chargeTimes, runningCosts)):
            s += c
            while q and chargeTimes[q[-1]] <= t:
                q.pop()
            q.append(r)
            while q and (r - l + 1) * s + chargeTimes[q[0]] > budget:
                if q[0] == l:
                    q.popleft()
                s -= runningCosts[l]
                l += 1
            ans = max(ans, r - l + 1)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumRobots(int[] chargeTimes, int[] runningCosts, long budget) {
        Deque<Integer> q = new ArrayDeque<>();
        int n = chargeTimes.length;
        int ans = 0;
        long s = 0;
        for (int l = 0, r = 0; r < n; ++r) {
            s += runningCosts[r];
            while (!q.isEmpty() && chargeTimes[q.peekLast()] <= chargeTimes[r]) {
                q.pollLast();
            }
            q.offerLast(r);
            while (!q.isEmpty() && (r - l + 1) * s + chargeTimes[q.peekFirst()] > budget) {
                if (q.peekFirst() == l) {
                    q.pollFirst();
                }
                s -= runningCosts[l++];
            }
            ans = Math.max(ans, r - l + 1);
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
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        deque<int> q;
        long long s = 0;
        int ans = 0;
        int n = chargeTimes.size();
        for (int l = 0, r = 0; r < n; ++r) {
            s += runningCosts[r];
            while (q.size() && chargeTimes[q.back()] <= chargeTimes[r]) {
                q.pop_back();
            }
            q.push_back(r);
            while (q.size() && (r - l + 1) * s + chargeTimes[q.front()] > budget) {
                if (q.front() == l) {
                    q.pop_front();
                }
                s -= runningCosts[l++];
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumRobots(chargeTimes []int, runningCosts []int, budget int64) (ans int) {
	q := Deque{}
	s := int64(0)
	l := 0
	for r, t := range chargeTimes {
		s += int64(runningCosts[r])
		for !q.Empty() && chargeTimes[q.Back()] <= t {
			q.PopBack()
		}
		q.PushBack(r)
		for !q.Empty() && int64(r-l+1)*s+int64(chargeTimes[q.Front()]) > budget {
			if q.Front() == l {
				q.PopFront()
			}
			s -= int64(runningCosts[l])
			l++
		}
		ans = max(ans, r-l+1)
	}
	return
}

// template
type Deque struct{ l, r []int }

func (q Deque) Empty() bool {
	return len(q.l) == 0 && len(q.r) == 0
}

func (q Deque) Size() int {
	return len(q.l) + len(q.r)
}

func (q *Deque) PushFront(v int) {
	q.l = append(q.l, v)
}

func (q *Deque) PushBack(v int) {
	q.r = append(q.r, v)
}

func (q *Deque) PopFront() (v int) {
	if len(q.l) > 0 {
		q.l, v = q.l[:len(q.l)-1], q.l[len(q.l)-1]
	} else {
		v, q.r = q.r[0], q.r[1:]
	}
	return
}

func (q *Deque) PopBack() (v int) {
	if len(q.r) > 0 {
		q.r, v = q.r[:len(q.r)-1], q.r[len(q.r)-1]
	} else {
		v, q.l = q.l[0], q.l[1:]
	}
	return
}

func (q Deque) Front() int {
	if len(q.l) > 0 {
		return q.l[len(q.l)-1]
	}
	return q.r[0]
}

func (q Deque) Back() int {
	if len(q.r) > 0 {
		return q.r[len(q.r)-1]
	}
	return q.l[0]
}

func (q Deque) Get(i int) int {
	if i < len(q.l) {
		return q.l[len(q.l)-1-i]
	}
	return q.r[i-len(q.l)]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumRobots(chargeTimes: number[], runningCosts: number[], budget: number): number {
    const q = new Deque<number>();
    const n = chargeTimes.length;
    let [ans, s] = [0, 0];
    for (let l = 0, r = 0; r < n; ++r) {
        s += runningCosts[r];
        while (!q.isEmpty() && chargeTimes[q.backValue()!] <= chargeTimes[r]) {
            q.popBack();
        }
        q.pushBack(r);
        while (!q.isEmpty() && (r - l + 1) * s + chargeTimes[q.frontValue()!] > budget) {
            if (q.frontValue() === l) {
                q.popFront();
            }
            s -= runningCosts[l++];
        }
        ans = Math.max(ans, r - l + 1);
    }
    return ans;
}

class Node<T> {
    value: T;
    next: Node<T> | null;
    prev: Node<T> | null;

    constructor(value: T) {
        this.value = value;
        this.next = null;
        this.prev = null;
    }
}

class Deque<T> {
    private front: Node<T> | null;
    private back: Node<T> | null;
    private size: number;

    constructor() {
        this.front = null;
        this.back = null;
        this.size = 0;
    }

    pushFront(val: T): void {
        const newNode = new Node(val);
        if (this.isEmpty()) {
            this.front = newNode;
            this.back = newNode;
        } else {
            newNode.next = this.front;
            this.front!.prev = newNode;
            this.front = newNode;
        }
        this.size++;
    }

    pushBack(val: T): void {
        const newNode = new Node(val);
        if (this.isEmpty()) {
            this.front = newNode;
            this.back = newNode;
        } else {
            newNode.prev = this.back;
            this.back!.next = newNode;
            this.back = newNode;
        }
        this.size++;
    }

    popFront(): T | undefined {
        if (this.isEmpty()) {
            return undefined;
        }
        const value = this.front!.value;
        this.front = this.front!.next;
        if (this.front !== null) {
            this.front.prev = null;
        } else {
            this.back = null;
        }
        this.size--;
        return value;
    }

    popBack(): T | undefined {
        if (this.isEmpty()) {
            return undefined;
        }
        const value = this.back!.value;
        this.back = this.back!.prev;
        if (this.back !== null) {
            this.back.next = null;
        } else {
            this.front = null;
        }
        this.size--;
        return value;
    }

    frontValue(): T | undefined {
        return this.front?.value;
    }

    backValue(): T | undefined {
        return this.back?.value;
    }

    getSize(): number {
        return this.size;
    }

    isEmpty(): boolean {
        return this.size === 0;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你有&nbsp;<code>n</code>&nbsp;个机器人，给你两个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>chargeTimes</code> 和&nbsp;<code>runningCosts</code>&nbsp;，两者长度都为&nbsp;<code>n</code>&nbsp;。第&nbsp;<code>i</code>&nbsp;个机器人充电时间为&nbsp;<code>chargeTimes[i]</code>&nbsp;单位时间，花费&nbsp;<code>runningCosts[i]</code>&nbsp;单位时间运行。再给你一个整数&nbsp;<code>budget</code>&nbsp;。</p>

<p>运行&nbsp;<code>k</code>&nbsp;个机器人 <strong>总开销</strong>&nbsp;是&nbsp;<code>max(chargeTimes) + k * sum(runningCosts)</code>&nbsp;，其中&nbsp;<code>max(chargeTimes)</code>&nbsp;是这&nbsp;<code>k</code>&nbsp;个机器人中最大充电时间，<code>sum(runningCosts)</code>&nbsp;是这 <code>k</code>&nbsp;个机器人的运行时间之和。</p>

<p>请你返回在 <strong>不超过</strong>&nbsp;<code>budget</code>&nbsp;的前提下，你 <strong>最多</strong>&nbsp;可以运行的 <strong>连续</strong>&nbsp;的机器人数目为多少。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>chargeTimes = [3,6,1,3,4], runningCosts = [2,1,3,4,5], budget = 25
<b>输出：</b>3
<b>解释：</b>
可以在 budget 以内运行所有单个机器人或者连续运行 2 个机器人。
选择前 3 个机器人，可以得到答案最大值 3 。总开销是 max(3,6,1) + 3 * sum(2,1,3) = 6 + 3 * 6 = 24 ，小于 25 。
可以看出无法在 budget 以内连续运行超过 3 个机器人，所以我们返回 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>chargeTimes = [11,12,19], runningCosts = [10,8,7], budget = 19
<b>输出：</b>0
<b>解释：</b>即使运行任何一个单个机器人，还是会超出 budget，所以我们返回 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>chargeTimes.length == runningCosts.length == n</code></li>
	<li><code>1 &lt;= n &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= chargeTimes[i], runningCosts[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= budget &lt;= 10<sup>15</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针 + 单调队列

问题实际上是求滑动窗口内的最大值，可以用单调队列来求解。

我们只需要二分枚举窗口 $k$ 的大小，找到一个最大的 $k$，使得满足题目要求。

实现过程中，实际上不需要进行二分枚举，只需要将固定窗口改为双指针非固定窗口即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$，其中 $n$ 是题目中机器人的数目。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumRobots(
        self, chargeTimes: List[int], runningCosts: List[int], budget: int
    ) -> int:
        q = deque()
        ans = s = l = 0
        for r, (t, c) in enumerate(zip(chargeTimes, runningCosts)):
            s += c
            while q and chargeTimes[q[-1]] <= t:
                q.pop()
            q.append(r)
            while q and (r - l + 1) * s + chargeTimes[q[0]] > budget:
                if q[0] == l:
                    q.popleft()
                s -= runningCosts[l]
                l += 1
            ans = max(ans, r - l + 1)
        return ans
```

#### Java

```java
class Solution {
    public int maximumRobots(int[] chargeTimes, int[] runningCosts, long budget) {
        Deque<Integer> q = new ArrayDeque<>();
        int n = chargeTimes.length;
        int ans = 0;
        long s = 0;
        for (int l = 0, r = 0; r < n; ++r) {
            s += runningCosts[r];
            while (!q.isEmpty() && chargeTimes[q.peekLast()] <= chargeTimes[r]) {
                q.pollLast();
            }
            q.offerLast(r);
            while (!q.isEmpty() && (r - l + 1) * s + chargeTimes[q.peekFirst()] > budget) {
                if (q.peekFirst() == l) {
                    q.pollFirst();
                }
                s -= runningCosts[l++];
            }
            ans = Math.max(ans, r - l + 1);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        deque<int> q;
        long long s = 0;
        int ans = 0;
        int n = chargeTimes.size();
        for (int l = 0, r = 0; r < n; ++r) {
            s += runningCosts[r];
            while (q.size() && chargeTimes[q.back()] <= chargeTimes[r]) {
                q.pop_back();
            }
            q.push_back(r);
            while (q.size() && (r - l + 1) * s + chargeTimes[q.front()] > budget) {
                if (q.front() == l) {
                    q.pop_front();
                }
                s -= runningCosts[l++];
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
```

#### Go

```go
func maximumRobots(chargeTimes []int, runningCosts []int, budget int64) (ans int) {
	q := Deque{}
	s := int64(0)
	l := 0
	for r, t := range chargeTimes {
		s += int64(runningCosts[r])
		for !q.Empty() && chargeTimes[q.Back()] <= t {
			q.PopBack()
		}
		q.PushBack(r)
		for !q.Empty() && int64(r-l+1)*s+int64(chargeTimes[q.Front()]) > budget {
			if q.Front() == l {
				q.PopFront()
			}
			s -= int64(runningCosts[l])
			l++
		}
		ans = max(ans, r-l+1)
	}
	return
}

// template
type Deque struct{ l, r []int }

func (q Deque) Empty() bool {
	return len(q.l) == 0 && len(q.r) == 0
}

func (q Deque) Size() int {
	return len(q.l) + len(q.r)
}

func (q *Deque) PushFront(v int) {
	q.l = append(q.l, v)
}

func (q *Deque) PushBack(v int) {
	q.r = append(q.r, v)
}

func (q *Deque) PopFront() (v int) {
	if len(q.l) > 0 {
		q.l, v = q.l[:len(q.l)-1], q.l[len(q.l)-1]
	} else {
		v, q.r = q.r[0], q.r[1:]
	}
	return
}

func (q *Deque) PopBack() (v int) {
	if len(q.r) > 0 {
		q.r, v = q.r[:len(q.r)-1], q.r[len(q.r)-1]
	} else {
		v, q.l = q.l[0], q.l[1:]
	}
	return
}

func (q Deque) Front() int {
	if len(q.l) > 0 {
		return q.l[len(q.l)-1]
	}
	return q.r[0]
}

func (q Deque) Back() int {
	if len(q.r) > 0 {
		return q.r[len(q.r)-1]
	}
	return q.l[0]
}

func (q Deque) Get(i int) int {
	if i < len(q.l) {
		return q.l[len(q.l)-1-i]
	}
	return q.r[i-len(q.l)]
}
```

#### TypeScript

```ts
function maximumRobots(chargeTimes: number[], runningCosts: number[], budget: number): number {
    const q = new Deque<number>();
    const n = chargeTimes.length;
    let [ans, s] = [0, 0];
    for (let l = 0, r = 0; r < n; ++r) {
        s += runningCosts[r];
        while (!q.isEmpty() && chargeTimes[q.backValue()!] <= chargeTimes[r]) {
            q.popBack();
        }
        q.pushBack(r);
        while (!q.isEmpty() && (r - l + 1) * s + chargeTimes[q.frontValue()!] > budget) {
            if (q.frontValue() === l) {
                q.popFront();
            }
            s -= runningCosts[l++];
        }
        ans = Math.max(ans, r - l + 1);
    }
    return ans;
}

class Node<T> {
    value: T;
    next: Node<T> | null;
    prev: Node<T> | null;

    constructor(value: T) {
        this.value = value;
        this.next = null;
        this.prev = null;
    }
}

class Deque<T> {
    private front: Node<T> | null;
    private back: Node<T> | null;
    private size: number;

    constructor() {
        this.front = null;
        this.back = null;
        this.size = 0;
    }

    pushFront(val: T): void {
        const newNode = new Node(val);
        if (this.isEmpty()) {
            this.front = newNode;
            this.back = newNode;
        } else {
            newNode.next = this.front;
            this.front!.prev = newNode;
            this.front = newNode;
        }
        this.size++;
    }

    pushBack(val: T): void {
        const newNode = new Node(val);
        if (this.isEmpty()) {
            this.front = newNode;
            this.back = newNode;
        } else {
            newNode.prev = this.back;
            this.back!.next = newNode;
            this.back = newNode;
        }
        this.size++;
    }

    popFront(): T | undefined {
        if (this.isEmpty()) {
            return undefined;
        }
        const value = this.front!.value;
        this.front = this.front!.next;
        if (this.front !== null) {
            this.front.prev = null;
        } else {
            this.back = null;
        }
        this.size--;
        return value;
    }

    popBack(): T | undefined {
        if (this.isEmpty()) {
            return undefined;
        }
        const value = this.back!.value;
        this.back = this.back!.prev;
        if (this.back !== null) {
            this.back.next = null;
        } else {
            this.front = null;
        }
        this.size--;
        return value;
    }

    frontValue(): T | undefined {
        return this.front?.value;
    }

    backValue(): T | undefined {
        return this.back?.value;
    }

    getSize(): number {
        return this.size;
    }

    isEmpty(): boolean {
        return this.size === 0;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2399. 检查相同字母间的距离](https://leetcode.cn/problems/check-distances-between-same-letters){#2399}

{{< tabs "2399" >}}

{{% tab "python" %}}
```python
class Solution:
    def checkDistances(self, s: str, distance: List[int]) -> bool:
        d = defaultdict(int)
        for i, c in enumerate(map(ord, s), 1):
            j = c - ord("a")
            if d[j] and i - d[j] - 1 != distance[j]:
                return False
            d[j] = i
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean checkDistances(String s, int[] distance) {
        int[] d = new int[26];
        for (int i = 1; i <= s.length(); ++i) {
            int j = s.charAt(i - 1) - 'a';
            if (d[j] > 0 && i - d[j] - 1 != distance[j]) {
                return false;
            }
            d[j] = i;
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
    bool checkDistances(string s, vector<int>& distance) {
        int d[26]{};
        for (int i = 1; i <= s.size(); ++i) {
            int j = s[i - 1] - 'a';
            if (d[j] && i - d[j] - 1 != distance[j]) {
                return false;
            }
            d[j] = i;
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func checkDistances(s string, distance []int) bool {
	d := [26]int{}
	for i, c := range s {
		c -= 'a'
		if d[c] > 0 && i-d[c] != distance[c] {
			return false
		}
		d[c] = i + 1
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function checkDistances(s: string, distance: number[]): boolean {
    const d: number[] = Array(26).fill(0);
    const n = s.length;
    for (let i = 1; i <= n; ++i) {
        const j = s.charCodeAt(i - 1) - 97;
        if (d[j] && i - d[j] - 1 !== distance[j]) {
            return false;
        }
        d[j] = i;
    }
    return true;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn check_distances(s: String, distance: Vec<i32>) -> bool {
        let n = s.len();
        let s = s.as_bytes();
        let mut d = [0; 26];
        for i in 0..n {
            let j = (s[i] - b'a') as usize;
            let i = i as i32;
            if d[j] > 0 && i - d[j] != distance[j] {
                return false;
            }
            d[j] = i + 1;
        }
        true
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
bool checkDistances(char* s, int* distance, int distanceSize) {
    int n = strlen(s);
    int d[26] = {0};
    for (int i = 0; i < n; i++) {
        int j = s[i] - 'a';
        if (d[j] > 0 && i - d[j] != distance[j]) {
            return false;
        }
        d[j] = i + 1;
    }
    return true;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始的字符串 <code>s</code> ，该字符串仅由小写英文字母组成，<code>s</code> 中的每个字母都 <strong>恰好</strong> 出现 <strong>两次</strong> 。另给你一个下标从 <strong>0</strong> 开始、长度为 <code>26</code> 的的整数数组 <code>distance</code> 。</p>

<p>字母表中的每个字母按从 <code>0</code> 到 <code>25</code> 依次编号（即，<code>'a' -&gt; 0</code>, <code>'b' -&gt; 1</code>, <code>'c' -&gt; 2</code>, ... , <code>'z' -&gt; 25</code>）。</p>

<p>在一个 <strong>匀整</strong> 字符串中，第 <code>i</code> 个字母的两次出现之间的字母数量是 <code>distance[i]</code> 。如果第 <code>i</code> 个字母没有在 <code>s</code> 中出现，那么 <code>distance[i]</code> 可以 <strong>忽略</strong> 。</p>

<p>如果 <code>s</code> 是一个 <strong>匀整</strong> 字符串，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "abaccb", distance = [1,3,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
<strong>输出：</strong>true
<strong>解释：</strong>
- 'a' 在下标 0 和下标 2 处出现，所以满足 distance[0] = 1 。
- 'b' 在下标 1 和下标 5 处出现，所以满足 distance[1] = 3 。
- 'c' 在下标 3 和下标 4 处出现，所以满足 distance[2] = 0 。
注意 distance[3] = 5 ，但是由于 'd' 没有在 s 中出现，可以忽略。
因为 s 是一个匀整字符串，返回 true 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "aa", distance = [1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
<strong>输出：</strong>false
<strong>解释：</strong>
- 'a' 在下标 0 和 1 处出现，所以两次出现之间的字母数量为 0 。
但是 distance[0] = 1 ，s 不是一个匀整字符串。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 52</code></li>
	<li><code>s</code> 仅由小写英文字母组成</li>
	<li><code>s</code> 中的每个字母恰好出现两次</li>
	<li><code>distance.length == 26</code></li>
	<li><code>0 &lt;= distance[i] &lt;= 50</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数组或哈希表

我们可以用哈希表 $d$ 记录每个字母出现的下标，然后遍历哈希表，判断每个字母的下标之差是否等于 `distance` 中对应的值。如果出现不等的情况，直接返回 `false`。如果遍历结束后，没有出现不等的情况，返回 `true`。

时间复杂度 $O(n)$，其中 $n$ 为字符串 $s$ 的长度。空间复杂度 $O(|\Sigma|)$，其中 $\Sigma$ 为字符集，这里为小写字母集合。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def checkDistances(self, s: str, distance: List[int]) -> bool:
        d = defaultdict(int)
        for i, c in enumerate(map(ord, s), 1):
            j = c - ord("a")
            if d[j] and i - d[j] - 1 != distance[j]:
                return False
            d[j] = i
        return True
```

#### Java

```java
class Solution {
    public boolean checkDistances(String s, int[] distance) {
        int[] d = new int[26];
        for (int i = 1; i <= s.length(); ++i) {
            int j = s.charAt(i - 1) - 'a';
            if (d[j] > 0 && i - d[j] - 1 != distance[j]) {
                return false;
            }
            d[j] = i;
        }
        return true;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        int d[26]{};
        for (int i = 1; i <= s.size(); ++i) {
            int j = s[i - 1] - 'a';
            if (d[j] && i - d[j] - 1 != distance[j]) {
                return false;
            }
            d[j] = i;
        }
        return true;
    }
};
```

#### Go

```go
func checkDistances(s string, distance []int) bool {
	d := [26]int{}
	for i, c := range s {
		c -= 'a'
		if d[c] > 0 && i-d[c] != distance[c] {
			return false
		}
		d[c] = i + 1
	}
	return true
}
```

#### TypeScript

```ts
function checkDistances(s: string, distance: number[]): boolean {
    const d: number[] = Array(26).fill(0);
    const n = s.length;
    for (let i = 1; i <= n; ++i) {
        const j = s.charCodeAt(i - 1) - 97;
        if (d[j] && i - d[j] - 1 !== distance[j]) {
            return false;
        }
        d[j] = i;
    }
    return true;
}
```

#### Rust

```rust
impl Solution {
    pub fn check_distances(s: String, distance: Vec<i32>) -> bool {
        let n = s.len();
        let s = s.as_bytes();
        let mut d = [0; 26];
        for i in 0..n {
            let j = (s[i] - b'a') as usize;
            let i = i as i32;
            if d[j] > 0 && i - d[j] != distance[j] {
                return false;
            }
            d[j] = i + 1;
        }
        true
    }
}
```

#### C

```c
bool checkDistances(char* s, int* distance, int distanceSize) {
    int n = strlen(s);
    int d[26] = {0};
    for (int i = 0; i < n; i++) {
        int j = s[i] - 'a';
        if (d[j] > 0 && i - d[j] != distance[j]) {
            return false;
        }
        d[j] = i + 1;
    }
    return true;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
