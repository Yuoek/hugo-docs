---
title: "3270_求出数字答案"
date: 2025-10-08T18:40:15+08:00
weight: 8
tags: [位运算, 前缀和, 动态规划, 哈希表, 堆（优先队列）, 字符串, 排序, 数学, 数据库, 数组, 枚举, 模拟, 状态压缩, 矩阵, 组合数学, 计数, 贪心]
---

{{< markmap >}}
### [3270_求出数字答案](#3270)
#### [数学](#3270)
### [3271_哈希分割字符串](#3271)
#### [字符串](#3271)
#### [模拟](#3271)
### [3272_统计好整数的数目](#3272)
#### [哈希表](#3272)
#### [数学](#3272)
#### [组合数学](#3272)
#### [枚举](#3272)
### [3273_对 Bob 造成的最少伤害](#3273)
#### [贪心](#3273)
#### [数组](#3273)
#### [排序](#3273)
### [3274_检查棋盘方格颜色是否相同](#3274)
#### [数学](#3274)
#### [字符串](#3274)
### [3275_第 K 近障碍物查询](#3275)
#### [数组](#3275)
#### [堆（优先队列）](#3275)
### [3276_选择矩阵中单元格的最大得分](#3276)
#### [位运算](#3276)
#### [数组](#3276)
#### [动态规划](#3276)
#### [状态压缩](#3276)
#### [矩阵](#3276)
### [3277_查询子数组最大异或值](#3277)
#### [数组](#3277)
#### [动态规划](#3277)
### [3278_寻找数据科学家职位的候选人 II 🔒](#3278)
#### [数据库](#3278)
### [3279_活塞占据的最大总区域 🔒](#3279)
#### [数组](#3279)
#### [哈希表](#3279)
#### [字符串](#3279)
#### [计数](#3279)
#### [前缀和](#3279)
#### [模拟](#3279)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 3270_求出数字答案
___
#### 数学
---
### 3271_哈希分割字符串
___
#### 字符串
___
#### 模拟
---
### 3272_统计好整数的数目
___
#### 哈希表
___
#### 数学
___
#### 组合数学
___
#### 枚举
---
### 3273_对 Bob 造成的最少伤害
___
#### 贪心
___
#### 数组
___
#### 排序
---
### 3274_检查棋盘方格颜色是否相同
___
#### 数学
___
#### 字符串
---
### 3275_第 K 近障碍物查询
___
#### 数组
___
#### 堆（优先队列）
---
### 3276_选择矩阵中单元格的最大得分
___
#### 位运算
___
#### 数组
___
#### 动态规划
___
#### 状态压缩
___
#### 矩阵
---
### 3277_查询子数组最大异或值
___
#### 数组
___
#### 动态规划
---
### 3278_寻找数据科学家职位的候选人 II 🔒
___
#### 数据库
---
### 3279_活塞占据的最大总区域 🔒
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 计数
___
#### 前缀和
___
#### 模拟
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 位运算 | 前缀和 | 动态规划 |
| 哈希表 | 堆（优先队列） | 字符串 |
| 排序 | 数学 | 数据库 |
| 数组 | 枚举 | 模拟 |
| 状态压缩 | 矩阵 | 组合数学 |
| 计数 | 贪心 |  |

# [3270. 求出数字答案](https://leetcode.cn/problems/find-the-key-of-the-numbers){#3270}

{{< tabs "3270" >}}

{{% tab "python" %}}
```python
class Solution:
    def generateKey(self, num1: int, num2: int, num3: int) -> int:
        ans, k = 0, 1
        for _ in range(4):
            x = min(num1 // k % 10, num2 // k % 10, num3 // k % 10)
            ans += x * k
            k *= 10
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int generateKey(int num1, int num2, int num3) {
        int ans = 0, k = 1;
        for (int i = 0; i < 4; ++i) {
            int x = Math.min(Math.min(num1 / k % 10, num2 / k % 10), num3 / k % 10);
            ans += x * k;
            k *= 10;
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
    int generateKey(int num1, int num2, int num3) {
        int ans = 0, k = 1;
        for (int i = 0; i < 4; ++i) {
            int x = min({num1 / k % 10, num2 / k % 10, num3 / k % 10});
            ans += x * k;
            k *= 10;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func generateKey(num1 int, num2 int, num3 int) (ans int) {
	k := 1
	for i := 0; i < 4; i++ {
		x := min(min(num1/k%10, num2/k%10), num3/k%10)
		ans += x * k
		k *= 10
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function generateKey(num1: number, num2: number, num3: number): number {
    let [ans, k] = [0, 1];
    for (let i = 0; i < 4; ++i) {
        const x = Math.min(((num1 / k) | 0) % 10, ((num2 / k) | 0) % 10, ((num3 / k) | 0) % 10);
        ans += x * k;
        k *= 10;
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

<p>给你三个 <strong>正</strong>&nbsp;整数&nbsp;<code>num1</code>&nbsp;，<code>num2</code>&nbsp;和&nbsp;<code>num3</code>&nbsp;。</p>

<p>数字 <code>num1</code>&nbsp;，<code>num2</code>&nbsp;和 <code>num3</code>&nbsp;的数字答案 <code>key</code>&nbsp;是一个四位数，定义如下：</p>

<ul>
	<li>一开始，如果有数字 <strong>少于</strong>&nbsp;四位数，给它补 <strong>前导 0 </strong>。</li>
	<li>答案 <code>key</code>&nbsp;的第&nbsp;<code>i</code>&nbsp;个数位（<code>1 &lt;= i &lt;= 4</code>）为&nbsp;<code>num1</code>&nbsp;，<code>num2</code>&nbsp;和&nbsp;<code>num3</code>&nbsp;第&nbsp;<code>i</code>&nbsp;个数位中的&nbsp;<strong>最小</strong>&nbsp;值。</li>
</ul>

<p>请你返回三个数字 <strong>没有</strong>&nbsp;前导 0 的数字答案。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>num1 = 1, num2 = 10, num3 = 1000</span></p>

<p><span class="example-io"><b>输出：</b>0</span></p>

<p><b>解释：</b></p>

<p>补前导 0 后，<code>num1</code>&nbsp;变为&nbsp;<code>"0001"</code>&nbsp;，<code>num2</code> 变为&nbsp;<code>"0010"</code>&nbsp;，<code>num3</code>&nbsp;保持不变，为&nbsp;<code>"1000"</code>&nbsp;。</p>

<ul>
	<li>数字答案 <code>key</code>&nbsp;的第&nbsp;<code>1</code>&nbsp;个数位为&nbsp;<code>min(0, 0, 1)</code>&nbsp;。</li>
	<li>数字答案 <code>key</code>&nbsp;的第&nbsp;<code>2</code>&nbsp;个数位为&nbsp;<code>min(0, 0, 0)</code>&nbsp;。</li>
	<li>数字答案 <code>key</code>&nbsp;的第 <code>3</code> 个数位为&nbsp;<code>min(0, 1, 0)</code>&nbsp;。</li>
	<li>数字答案 <code>key</code>&nbsp;的第 <code>4</code> 个数位为&nbsp;<code>min(1, 0, 0)</code>&nbsp;。</li>
</ul>

<p>所以数字答案为&nbsp;<code>"0000"</code>&nbsp;，也就是 0 。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">num1 = 987, num2 = 879, num3 = 798</span></p>

<p><span class="example-io"><b>输出：</b>777</span></p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>num1 = 1, num2 = 2, num3 = 3</span></p>

<p><span class="example-io"><b>输出：</b>1</span></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num1, num2, num3 &lt;= 9999</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以直接模拟这个过程，定义一个变量 $\textit{ans}$ 用于存储答案，定义一个变量 $\textit{k}$ 用于表示当前位数，其中 $\textit{k} = 1$ 表示个位数，而 $\textit{k} = 10$ 表示十位数，以此类推。

我们从个位数开始，对于每一位，我们分别计算 $\textit{num1}$, $\textit{num2}$ 和 $\textit{num3}$ 的当前位数，取三者的最小值，然后将这个最小值乘以 $\textit{k}$ 加到答案上。然后将 $\textit{k}$ 乘以 10，继续计算下一位。

最后返回答案即可。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def generateKey(self, num1: int, num2: int, num3: int) -> int:
        ans, k = 0, 1
        for _ in range(4):
            x = min(num1 // k % 10, num2 // k % 10, num3 // k % 10)
            ans += x * k
            k *= 10
        return ans
```

#### Java

```java
class Solution {
    public int generateKey(int num1, int num2, int num3) {
        int ans = 0, k = 1;
        for (int i = 0; i < 4; ++i) {
            int x = Math.min(Math.min(num1 / k % 10, num2 / k % 10), num3 / k % 10);
            ans += x * k;
            k *= 10;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        int ans = 0, k = 1;
        for (int i = 0; i < 4; ++i) {
            int x = min({num1 / k % 10, num2 / k % 10, num3 / k % 10});
            ans += x * k;
            k *= 10;
        }
        return ans;
    }
};
```

#### Go

```go
func generateKey(num1 int, num2 int, num3 int) (ans int) {
	k := 1
	for i := 0; i < 4; i++ {
		x := min(min(num1/k%10, num2/k%10), num3/k%10)
		ans += x * k
		k *= 10
	}
	return
}
```

#### TypeScript

```ts
function generateKey(num1: number, num2: number, num3: number): number {
    let [ans, k] = [0, 1];
    for (let i = 0; i < 4; ++i) {
        const x = Math.min(((num1 / k) | 0) % 10, ((num2 / k) | 0) % 10, ((num3 / k) | 0) % 10);
        ans += x * k;
        k *= 10;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3271. 哈希分割字符串](https://leetcode.cn/problems/hash-divided-string){#3271}

{{< tabs "3271" >}}

{{% tab "python" %}}
```python
class Solution:
    def stringHash(self, s: str, k: int) -> str:
        ans = []
        for i in range(0, len(s), k):
            t = 0
            for j in range(i, i + k):
                t += ord(s[j]) - ord("a")
            hashedChar = t % 26
            ans.append(chr(ord("a") + hashedChar))
        return "".join(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String stringHash(String s, int k) {
        StringBuilder ans = new StringBuilder();
        int n = s.length();
        for (int i = 0; i < n; i += k) {
            int t = 0;
            for (int j = i; j < i + k; ++j) {
                t += s.charAt(j) - 'a';
            }
            int hashedChar = t % 26;
            ans.append((char) ('a' + hashedChar));
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
    string stringHash(string s, int k) {
        string ans;
        int n = s.length();
        for (int i = 0; i < n; i += k) {
            int t = 0;
            for (int j = i; j < i + k; ++j) {
                t += s[j] - 'a';
            }
            int hashedChar = t % 26;
            ans += ('a' + hashedChar);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func stringHash(s string, k int) string {
	n := len(s)
	ans := make([]byte, 0, n/k)

	for i := 0; i < n; i += k {
		t := 0
		for j := i; j < i+k; j++ {
			t += int(s[j] - 'a')
		}
		hashedChar := t % 26
		ans = append(ans, 'a'+byte(hashedChar))
	}

	return string(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function stringHash(s: string, k: number): string {
    const ans: string[] = [];
    const n: number = s.length;

    for (let i = 0; i < n; i += k) {
        let t: number = 0;
        for (let j = i; j < i + k; j++) {
            t += s.charCodeAt(j) - 97;
        }
        const hashedChar: number = t % 26;
        ans.push(String.fromCharCode(97 + hashedChar));
    }

    return ans.join('');
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个长度为 <code>n</code>&nbsp;的字符串 <code>s</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;，<code>n</code>&nbsp;是 <code>k</code>&nbsp;的 <strong>倍数</strong>&nbsp;。你的任务是将字符串 <code>s</code>&nbsp;哈希为一个长度为 <code>n / k</code>&nbsp;的新字符串&nbsp;<code>result</code>&nbsp;。</p>

<p>首先，将&nbsp;<code>s</code>&nbsp;分割成&nbsp;<code>n / k</code>&nbsp;个&nbsp;<strong><span data-keyword="substring-nonempty">子字符串</span></strong>&nbsp;，每个子字符串的长度都为&nbsp;<code>k</code>&nbsp;。然后，将&nbsp;<code>result</code>&nbsp;初始化为一个 <strong>空</strong>&nbsp;字符串。</p>

<p>我们依次从前往后处理每一个 <strong>子字符串</strong>&nbsp;：</p>

<ul>
	<li>一个字符的 <strong>哈希值</strong>&nbsp;是它在 <strong>字母表</strong>&nbsp;中的下标（也就是&nbsp;<code>'a' →<!-- notionvc: d3f8e4c2-23cd-41ad-a14b-101dfe4c5aba --> 0</code>&nbsp;，<code>'b' →<!-- notionvc: d3f8e4c2-23cd-41ad-a14b-101dfe4c5aba --> 1</code>&nbsp;，... ，<code>'z' →<!-- notionvc: d3f8e4c2-23cd-41ad-a14b-101dfe4c5aba --> 25</code>）。</li>
	<li>将子字符串中字母的 <strong>哈希值</strong>&nbsp;求和。</li>
	<li>将和对 26 取余，将结果记为&nbsp;<code>hashedChar</code>&nbsp;。</li>
	<li>找到小写字母表中 <code>hashedChar</code>&nbsp;对应的字符。</li>
	<li>将该字符添加到&nbsp;<code>result</code>&nbsp;的末尾。</li>
</ul>

<p>返回&nbsp;<code>result</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>s = "abcd", k = 2</span></p>

<p><span class="example-io"><b>输出：</b>"bf"</span></p>

<p><b>解释：</b></p>

<p>第一个字符串为&nbsp;<code>"ab"</code>&nbsp;，<code>0 + 1 = 1</code>&nbsp;，<code>1 % 26 = 1</code>&nbsp;，<code>result[0] = 'b'</code>&nbsp;。</p>

<p>第二个字符串为： <code>"cd"</code>&nbsp;，<code>2 + 3 = 5</code>&nbsp;，<code>5 % 26 = 5</code>&nbsp;，<code>result[1] = 'f'</code>&nbsp;。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>s = "mxz", k = 3</span></p>

<p><span class="example-io"><b>输出：</b>"i"</span></p>

<p><b>解释：</b></p>

<p>唯一的子字符串为&nbsp;<code>"mxz"</code>&nbsp;，<code>12 + 23 + 25 = 60</code>&nbsp;，<code>60 % 26 = 8</code>&nbsp;，<code>result[0] = 'i'</code>&nbsp;。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= 100</code></li>
	<li><code>k &lt;= s.length &lt;= 1000</code></li>
	<li><code>s.length</code>&nbsp;能被 <code>k</code>&nbsp;整除。</li>
	<li><code>s</code> 只含有小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以按照题目描述的步骤模拟即可。

遍历字符串 $s$，每次取 $k$ 个字符，计算它们的哈希值之和，记为 $t$，然后对 $t$ 取模 $26$，找到对应的字符，将其添加到结果字符串的末尾。

最后返回结果字符串即可。

时间复杂度 $O(n)$，其中 $n$ 为字符串 $s$ 的长度。忽略答案字符串的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def stringHash(self, s: str, k: int) -> str:
        ans = []
        for i in range(0, len(s), k):
            t = 0
            for j in range(i, i + k):
                t += ord(s[j]) - ord("a")
            hashedChar = t % 26
            ans.append(chr(ord("a") + hashedChar))
        return "".join(ans)
```

#### Java

```java
class Solution {
    public String stringHash(String s, int k) {
        StringBuilder ans = new StringBuilder();
        int n = s.length();
        for (int i = 0; i < n; i += k) {
            int t = 0;
            for (int j = i; j < i + k; ++j) {
                t += s.charAt(j) - 'a';
            }
            int hashedChar = t % 26;
            ans.append((char) ('a' + hashedChar));
        }
        return ans.toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string stringHash(string s, int k) {
        string ans;
        int n = s.length();
        for (int i = 0; i < n; i += k) {
            int t = 0;
            for (int j = i; j < i + k; ++j) {
                t += s[j] - 'a';
            }
            int hashedChar = t % 26;
            ans += ('a' + hashedChar);
        }
        return ans;
    }
};
```

#### Go

```go
func stringHash(s string, k int) string {
	n := len(s)
	ans := make([]byte, 0, n/k)

	for i := 0; i < n; i += k {
		t := 0
		for j := i; j < i+k; j++ {
			t += int(s[j] - 'a')
		}
		hashedChar := t % 26
		ans = append(ans, 'a'+byte(hashedChar))
	}

	return string(ans)
}
```

#### TypeScript

```ts
function stringHash(s: string, k: number): string {
    const ans: string[] = [];
    const n: number = s.length;

    for (let i = 0; i < n; i += k) {
        let t: number = 0;
        for (let j = i; j < i + k; j++) {
            t += s.charCodeAt(j) - 97;
        }
        const hashedChar: number = t % 26;
        ans.push(String.fromCharCode(97 + hashedChar));
    }

    return ans.join('');
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3272. 统计好整数的数目](https://leetcode.cn/problems/find-the-count-of-good-integers){#3272}

{{< tabs "3272" >}}

{{% tab "python" %}}
```python
class Solution:
    def countGoodIntegers(self, n: int, k: int) -> int:
        fac = [factorial(i) for i in range(n + 1)]
        ans = 0
        vis = set()
        base = 10 ** ((n - 1) // 2)
        for i in range(base, base * 10):
            s = str(i)
            s += s[::-1][n % 2 :]
            if int(s) % k:
                continue
            t = "".join(sorted(s))
            if t in vis:
                continue
            vis.add(t)
            cnt = Counter(t)
            res = (n - cnt["0"]) * fac[n - 1]
            for x in cnt.values():
                res //= fac[x]
            ans += res
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long countGoodIntegers(int n, int k) {
        long[] fac = new long[n + 1];
        fac[0] = 1;
        for (int i = 1; i <= n; i++) {
            fac[i] = fac[i - 1] * i;
        }

        long ans = 0;
        Set<String> vis = new HashSet<>();
        int base = (int) Math.pow(10, (n - 1) / 2);

        for (int i = base; i < base * 10; i++) {
            String s = String.valueOf(i);
            StringBuilder sb = new StringBuilder(s).reverse();
            s += sb.substring(n % 2);
            if (Long.parseLong(s) % k != 0) {
                continue;
            }

            char[] arr = s.toCharArray();
            Arrays.sort(arr);
            String t = new String(arr);
            if (vis.contains(t)) {
                continue;
            }
            vis.add(t);
            int[] cnt = new int[10];
            for (char c : arr) {
                cnt[c - '0']++;
            }

            long res = (n - cnt[0]) * fac[n - 1];
            for (int x : cnt) {
                res /= fac[x];
            }
            ans += res;
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
    long long countGoodIntegers(int n, int k) {
        vector<long long> fac(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            fac[i] = fac[i - 1] * i;
        }

        long long ans = 0;
        unordered_set<string> vis;
        int base = pow(10, (n - 1) / 2);

        for (int i = base; i < base * 10; ++i) {
            string s = to_string(i);
            string rev = s;
            reverse(rev.begin(), rev.end());
            s += rev.substr(n % 2);
            if (stoll(s) % k) {
                continue;
            }
            string t = s;
            sort(t.begin(), t.end());
            if (vis.count(t)) {
                continue;
            }
            vis.insert(t);
            vector<int> cnt(10);
            for (char c : t) {
                cnt[c - '0']++;
            }
            long long res = (n - cnt[0]) * fac[n - 1];
            for (int x : cnt) {
                res /= fac[x];
            }
            ans += res;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func factorial(n int) []int64 {
	fac := make([]int64, n+1)
	fac[0] = 1
	for i := 1; i <= n; i++ {
		fac[i] = fac[i-1] * int64(i)
	}
	return fac
}

func countGoodIntegers(n int, k int) (ans int64) {
	fac := factorial(n)
	vis := make(map[string]bool)
	base := int(math.Pow(10, float64((n-1)/2)))

	for i := base; i < base*10; i++ {
		s := strconv.Itoa(i)
		rev := reverseString(s)
		s += rev[n%2:]
		num, _ := strconv.ParseInt(s, 10, 64)
		if num%int64(k) != 0 {
			continue
		}
		bs := []byte(s)
		slices.Sort(bs)
		t := string(bs)

		if vis[t] {
			continue
		}
		vis[t] = true
		cnt := make([]int, 10)
		for _, c := range t {
			cnt[c-'0']++
		}
		res := (int64(n) - int64(cnt[0])) * fac[n-1]
		for _, x := range cnt {
			res /= fac[x]
		}
		ans += res
	}

	return
}

func reverseString(s string) string {
	t := []byte(s)
	for i, j := 0, len(t)-1; i < j; i, j = i+1, j-1 {
		t[i], t[j] = t[j], t[i]
	}
	return string(t)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countGoodIntegers(n: number, k: number): number {
    const fac = factorial(n);
    let ans = 0;
    const vis = new Set<string>();
    const base = Math.pow(10, Math.floor((n - 1) / 2));

    for (let i = base; i < base * 10; i++) {
        let s = `${i}`;
        const rev = reverseString(s);
        if (n % 2 === 1) {
            s += rev.substring(1);
        } else {
            s += rev;
        }

        if (+s % k !== 0) {
            continue;
        }

        const bs = Array.from(s).sort();
        const t = bs.join('');

        if (vis.has(t)) {
            continue;
        }

        vis.add(t);

        const cnt = Array(10).fill(0);
        for (const c of t) {
            cnt[+c]++;
        }

        let res = (n - cnt[0]) * fac[n - 1];
        for (const x of cnt) {
            res /= fac[x];
        }
        ans += res;
    }

    return ans;
}

function factorial(n: number): number[] {
    const fac = Array(n + 1).fill(1);
    for (let i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * i;
    }
    return fac;
}

function reverseString(s: string): string {
    return s.split('').reverse().join('');
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn count_good_integers(n: i32, k: i32) -> i64 {
        use std::collections::HashSet;
        let n = n as usize;
        let k = k as i64;
        let mut fac = vec![1_i64; n + 1];
        for i in 1..=n {
            fac[i] = fac[i - 1] * i as i64;
        }

        let mut ans = 0;
        let mut vis = HashSet::new();
        let base = 10_i64.pow(((n - 1) / 2) as u32);

        for i in base..base * 10 {
            let s = i.to_string();
            let rev: String = s.chars().rev().collect();
            let full_s = if n % 2 == 0 {
                format!("{}{}", s, rev)
            } else {
                format!("{}{}", s, &rev[1..])
            };

            let num: i64 = full_s.parse().unwrap();
            if num % k != 0 {
                continue;
            }

            let mut arr: Vec<char> = full_s.chars().collect();
            arr.sort_unstable();
            let t: String = arr.iter().collect();
            if vis.contains(&t) {
                continue;
            }
            vis.insert(t);

            let mut cnt = vec![0; 10];
            for c in arr {
                cnt[c as usize - '0' as usize] += 1;
            }

            let mut res = (n - cnt[0]) as i64 * fac[n - 1];
            for &x in &cnt {
                if x > 0 {
                    res /= fac[x];
                }
            }
            ans += res;
        }

        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var countGoodIntegers = function (n, k) {
    const fac = factorial(n);
    let ans = 0;
    const vis = new Set();
    const base = Math.pow(10, Math.floor((n - 1) / 2));

    for (let i = base; i < base * 10; i++) {
        let s = String(i);
        const rev = reverseString(s);
        if (n % 2 === 1) {
            s += rev.substring(1);
        } else {
            s += rev;
        }

        if (parseInt(s, 10) % k !== 0) {
            continue;
        }

        const bs = Array.from(s).sort();
        const t = bs.join('');

        if (vis.has(t)) {
            continue;
        }

        vis.add(t);

        const cnt = Array(10).fill(0);
        for (const c of t) {
            cnt[parseInt(c, 10)]++;
        }

        let res = (n - cnt[0]) * fac[n - 1];
        for (const x of cnt) {
            res /= fac[x];
        }
        ans += res;
    }

    return ans;
};

function factorial(n) {
    const fac = Array(n + 1).fill(1);
    for (let i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * i;
    }
    return fac;
}

function reverseString(s) {
    return s.split('').reverse().join('');
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个 <strong>正</strong>&nbsp;整数&nbsp;<code>n</code> 和&nbsp;<code>k</code>&nbsp;。</p>

<p>如果一个整数&nbsp;<code>x</code>&nbsp;满足以下条件，那么它被称为 <strong>k</strong><strong>&nbsp;回文</strong>&nbsp;整数&nbsp;。</p>

<ul>
	<li><code>x</code>&nbsp;是一个&nbsp;<span data-keyword="palindrome-integer">回文整数 。</span></li>
	<li><code>x</code>&nbsp;能被 <code>k</code>&nbsp;整除。</li>
</ul>

<p>如果一个整数的数位重新排列后能得到一个 <strong>k 回文整数</strong>&nbsp;，那么我们称这个整数为&nbsp;<strong>好 </strong>整数。比方说，<code>k = 2</code>&nbsp;，那么&nbsp;2020 可以重新排列得到 2002 ，2002 是一个 k 回文串，所以 2020 是一个好整数。而 1010 无法重新排列数位得到一个 k 回文整数。</p>

<p>请你返回 <code>n</code>&nbsp;个数位的整数中，有多少个 <strong>好</strong>&nbsp;整数。</p>

<p><b>注意</b>&nbsp;，任何整数在重新排列数位之前或者之后 <strong>都不能</strong> 有前导 0 。比方说 1010 不能重排列得到&nbsp;101 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>n = 3, k = 5</span></p>

<p><span class="example-io"><b>输出：</b>27</span></p>

<p><b>解释：</b></p>

<p>部分好整数如下：</p>

<ul>
	<li>551 ，因为它可以重排列得到 515 。</li>
	<li>525 ，因为它已经是一个 k 回文整数。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>n = 1, k = 4</span></p>

<p><span class="example-io"><b>输出：</b>2</span></p>

<p><strong>解释：</strong></p>

<p>两个好整数分别是 4 和 8 。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>n = 5, k = 6</span></p>

<p><span class="example-io"><b>输出：</b>2468</span></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10</code></li>
	<li><code>1 &lt;= k &lt;= 9</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举 + 组合数学

我们可以考虑枚举所有长度为 $n$ 的回文数，判断它们是否是 $k$ 回文数。由于回文数的性质，我们只需要枚举前半部分的数字，然后将其反转拼接到后面即可。

前半部分的数字长度为 $\lfloor \frac{n - 1}{2} \rfloor$，那么前半部分的数字范围是 $[10^{\lfloor \frac{n - 1}{2} \rfloor}, 10^{\lfloor \frac{n - 1}{2} \rfloor + 1})$。我们可以将前半部分的数字拼接到后面，形成一个长度为 $n$ 的回文数。注意到，如果 $n$ 是奇数，则需要将中间的数字做特殊处理。

然后，我们判断该回文数是否是 $k$ 回文数，如果是，则统计该回文数的所有排列组合。为了避免重复，我们可以使用一个集合 $\textit{vis}$ 来存储已经出现过的回文数的每个最小排列。如果该回文数的最小排列已经出现过，则跳过该回文数。否则，我们统计该回文数有多少个不重复的排列组合，添加到答案中。

我们可以使用一个数组 $\textit{cnt}$ 来统计每个数字出现的次数，然后使用组合数学的公式计算排列组合的数量。具体来说，假设数字 $0$ 出现了 $x_0$ 次，数字 $1$ 出现了 $x_1$ 次，...，数字 $9$ 出现了 $x_9$ 次，那么该回文数的排列组合数量为：

$$
\frac{(n - x_0) \cdot (n - 1)!}{x_0! \cdot x_1! \cdots x_9!}
$$

其中 $(n - x_0)$ 表示最高位可以选择除 $0$ 以外的所有数字，而 $(n - 1)!$ 表示除最高位以外的所有数字的排列组合数量，然后我们除以每个数字出现的次数的阶乘，避免重复。

最后，我们将所有的排列组合数量相加，得到最终的答案。

时间复杂度 $({10}^m \times n \times \log n)$，空间复杂度 $O({10}^m \times n)$，其中 $m = \lfloor \frac{n - 1}{2} \rfloor$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countGoodIntegers(self, n: int, k: int) -> int:
        fac = [factorial(i) for i in range(n + 1)]
        ans = 0
        vis = set()
        base = 10 ** ((n - 1) // 2)
        for i in range(base, base * 10):
            s = str(i)
            s += s[::-1][n % 2 :]
            if int(s) % k:
                continue
            t = "".join(sorted(s))
            if t in vis:
                continue
            vis.add(t)
            cnt = Counter(t)
            res = (n - cnt["0"]) * fac[n - 1]
            for x in cnt.values():
                res //= fac[x]
            ans += res
        return ans
```

#### Java

```java
class Solution {
    public long countGoodIntegers(int n, int k) {
        long[] fac = new long[n + 1];
        fac[0] = 1;
        for (int i = 1; i <= n; i++) {
            fac[i] = fac[i - 1] * i;
        }

        long ans = 0;
        Set<String> vis = new HashSet<>();
        int base = (int) Math.pow(10, (n - 1) / 2);

        for (int i = base; i < base * 10; i++) {
            String s = String.valueOf(i);
            StringBuilder sb = new StringBuilder(s).reverse();
            s += sb.substring(n % 2);
            if (Long.parseLong(s) % k != 0) {
                continue;
            }

            char[] arr = s.toCharArray();
            Arrays.sort(arr);
            String t = new String(arr);
            if (vis.contains(t)) {
                continue;
            }
            vis.add(t);
            int[] cnt = new int[10];
            for (char c : arr) {
                cnt[c - '0']++;
            }

            long res = (n - cnt[0]) * fac[n - 1];
            for (int x : cnt) {
                res /= fac[x];
            }
            ans += res;
        }

        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        vector<long long> fac(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            fac[i] = fac[i - 1] * i;
        }

        long long ans = 0;
        unordered_set<string> vis;
        int base = pow(10, (n - 1) / 2);

        for (int i = base; i < base * 10; ++i) {
            string s = to_string(i);
            string rev = s;
            reverse(rev.begin(), rev.end());
            s += rev.substr(n % 2);
            if (stoll(s) % k) {
                continue;
            }
            string t = s;
            sort(t.begin(), t.end());
            if (vis.count(t)) {
                continue;
            }
            vis.insert(t);
            vector<int> cnt(10);
            for (char c : t) {
                cnt[c - '0']++;
            }
            long long res = (n - cnt[0]) * fac[n - 1];
            for (int x : cnt) {
                res /= fac[x];
            }
            ans += res;
        }
        return ans;
    }
};
```

#### Go

```go
func factorial(n int) []int64 {
	fac := make([]int64, n+1)
	fac[0] = 1
	for i := 1; i <= n; i++ {
		fac[i] = fac[i-1] * int64(i)
	}
	return fac
}

func countGoodIntegers(n int, k int) (ans int64) {
	fac := factorial(n)
	vis := make(map[string]bool)
	base := int(math.Pow(10, float64((n-1)/2)))

	for i := base; i < base*10; i++ {
		s := strconv.Itoa(i)
		rev := reverseString(s)
		s += rev[n%2:]
		num, _ := strconv.ParseInt(s, 10, 64)
		if num%int64(k) != 0 {
			continue
		}
		bs := []byte(s)
		slices.Sort(bs)
		t := string(bs)

		if vis[t] {
			continue
		}
		vis[t] = true
		cnt := make([]int, 10)
		for _, c := range t {
			cnt[c-'0']++
		}
		res := (int64(n) - int64(cnt[0])) * fac[n-1]
		for _, x := range cnt {
			res /= fac[x]
		}
		ans += res
	}

	return
}

func reverseString(s string) string {
	t := []byte(s)
	for i, j := 0, len(t)-1; i < j; i, j = i+1, j-1 {
		t[i], t[j] = t[j], t[i]
	}
	return string(t)
}
```

#### TypeScript

```ts
function countGoodIntegers(n: number, k: number): number {
    const fac = factorial(n);
    let ans = 0;
    const vis = new Set<string>();
    const base = Math.pow(10, Math.floor((n - 1) / 2));

    for (let i = base; i < base * 10; i++) {
        let s = `${i}`;
        const rev = reverseString(s);
        if (n % 2 === 1) {
            s += rev.substring(1);
        } else {
            s += rev;
        }

        if (+s % k !== 0) {
            continue;
        }

        const bs = Array.from(s).sort();
        const t = bs.join('');

        if (vis.has(t)) {
            continue;
        }

        vis.add(t);

        const cnt = Array(10).fill(0);
        for (const c of t) {
            cnt[+c]++;
        }

        let res = (n - cnt[0]) * fac[n - 1];
        for (const x of cnt) {
            res /= fac[x];
        }
        ans += res;
    }

    return ans;
}

function factorial(n: number): number[] {
    const fac = Array(n + 1).fill(1);
    for (let i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * i;
    }
    return fac;
}

function reverseString(s: string): string {
    return s.split('').reverse().join('');
}
```

#### Rust

```rust
impl Solution {
    pub fn count_good_integers(n: i32, k: i32) -> i64 {
        use std::collections::HashSet;
        let n = n as usize;
        let k = k as i64;
        let mut fac = vec![1_i64; n + 1];
        for i in 1..=n {
            fac[i] = fac[i - 1] * i as i64;
        }

        let mut ans = 0;
        let mut vis = HashSet::new();
        let base = 10_i64.pow(((n - 1) / 2) as u32);

        for i in base..base * 10 {
            let s = i.to_string();
            let rev: String = s.chars().rev().collect();
            let full_s = if n % 2 == 0 {
                format!("{}{}", s, rev)
            } else {
                format!("{}{}", s, &rev[1..])
            };

            let num: i64 = full_s.parse().unwrap();
            if num % k != 0 {
                continue;
            }

            let mut arr: Vec<char> = full_s.chars().collect();
            arr.sort_unstable();
            let t: String = arr.iter().collect();
            if vis.contains(&t) {
                continue;
            }
            vis.insert(t);

            let mut cnt = vec![0; 10];
            for c in arr {
                cnt[c as usize - '0' as usize] += 1;
            }

            let mut res = (n - cnt[0]) as i64 * fac[n - 1];
            for &x in &cnt {
                if x > 0 {
                    res /= fac[x];
                }
            }
            ans += res;
        }

        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var countGoodIntegers = function (n, k) {
    const fac = factorial(n);
    let ans = 0;
    const vis = new Set();
    const base = Math.pow(10, Math.floor((n - 1) / 2));

    for (let i = base; i < base * 10; i++) {
        let s = String(i);
        const rev = reverseString(s);
        if (n % 2 === 1) {
            s += rev.substring(1);
        } else {
            s += rev;
        }

        if (parseInt(s, 10) % k !== 0) {
            continue;
        }

        const bs = Array.from(s).sort();
        const t = bs.join('');

        if (vis.has(t)) {
            continue;
        }

        vis.add(t);

        const cnt = Array(10).fill(0);
        for (const c of t) {
            cnt[parseInt(c, 10)]++;
        }

        let res = (n - cnt[0]) * fac[n - 1];
        for (const x of cnt) {
            res /= fac[x];
        }
        ans += res;
    }

    return ans;
};

function factorial(n) {
    const fac = Array(n + 1).fill(1);
    for (let i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * i;
    }
    return fac;
}

function reverseString(s) {
    return s.split('').reverse().join('');
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3273. 对 Bob 造成的最少伤害](https://leetcode.cn/problems/minimum-amount-of-damage-dealt-to-bob){#3273}

{{< tabs "3273" >}}

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

<p>给你一个整数&nbsp;<code>power</code>&nbsp;和两个整数数组&nbsp;<code>damage</code> 和&nbsp;<code>health</code>&nbsp;，两个数组的长度都为&nbsp;<code>n</code>&nbsp;。</p>

<p>Bob 有&nbsp;<code>n</code>&nbsp;个敌人，如果第&nbsp;<code>i</code>&nbsp;个敌人还活着（也就是健康值&nbsp;<code>health[i] &gt; 0</code>&nbsp;的时候），每秒钟会对 Bob 造成&nbsp;<code>damage[i]</code>&nbsp;<strong>点</strong>&nbsp;伤害。</p>

<p>每一秒中，在敌人对 Bob 造成伤害 <strong>之后</strong>&nbsp;，Bob 会选择 <strong>一个</strong>&nbsp;还活着的敌人进行攻击，该敌人的健康值减少 <code>power</code>&nbsp;。</p>

<p>请你返回 Bob 将 <strong>所有</strong>&nbsp;<code>n</code>&nbsp;个敌人都消灭之前，<strong>最少</strong>&nbsp;会受到多少伤害。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>power = 4, damage = [1,2,3,4], health = [4,5,6,8]</span></p>

<p><span class="example-io"><b>输出：</b>39</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>最开始 2 秒内都攻击敌人 3 ，然后敌人 3 会被消灭，这段时间内对 Bob 的总伤害是&nbsp;<code>10 + 10 = 20</code>&nbsp;点。</li>
	<li>接下来 2 秒内都攻击敌人 2 ，然后敌人 2 会被消灭，这段时间内对 Bob 的总伤害是&nbsp;<code>6 + 6 = 12</code>&nbsp;点。</li>
	<li>接下来 1 秒内都攻击敌人 0 ，然后敌人 0 会被消灭，这段时间内对 Bob 的总伤害是&nbsp;<code>3</code>&nbsp;点。</li>
	<li>接下来 2 秒内都攻击敌人 1 ，然后敌人 1 会被消灭，这段时间内对 Bob 的总伤害是&nbsp;<code>2 + 2 = 4</code>&nbsp;点。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>power = 1, damage = [1,1,1,1], health = [1,2,3,4]</span></p>

<p><span class="example-io"><b>输出：</b>20</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>最开始 1 秒内都攻击敌人 0 ，然后敌人 0 会被消灭，这段时间对 Bob 的总伤害是&nbsp;<code>4</code>&nbsp;点。</li>
	<li>接下来 2 秒内都攻击敌人 1 ，然后敌人 1 会被消灭，这段时间对 Bob 的总伤害是&nbsp;<code>3 + 3 = 6</code>&nbsp;点。</li>
	<li>接下来 3 秒内都攻击敌人 2 ，然后敌人 2 会被消灭，这段时间对 Bob 的总伤害是&nbsp;<code>2 + 2 + 2 = 6</code>&nbsp;点。</li>
	<li>接下来 4 秒内都攻击敌人 3 ，然后敌人 3 会被消灭，这段时间对 Bob 的总伤害是&nbsp;<code>1 + 1 + 1 + 1 = 4</code>&nbsp;点。</li>
</ul>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>power = 8, damage = [40], health = [59]</span></p>

<p><span class="example-io"><b>输出：</b>320</span></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= power &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= n == damage.length == health.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= damage[i], health[i] &lt;= 10<sup>4</sup></code></li>
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

# [3274. 检查棋盘方格颜色是否相同](https://leetcode.cn/problems/check-if-two-chessboard-squares-have-the-same-color){#3274}

{{< tabs "3274" >}}

{{% tab "python" %}}
```python
class Solution:
    def checkTwoChessboards(self, coordinate1: str, coordinate2: str) -> bool:
        x = ord(coordinate1[0]) - ord(coordinate2[0])
        y = int(coordinate1[1]) - int(coordinate2[1])
        return (x + y) % 2 == 0
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean checkTwoChessboards(String coordinate1, String coordinate2) {
        int x = coordinate1.charAt(0) - coordinate2.charAt(0);
        int y = coordinate1.charAt(1) - coordinate2.charAt(1);
        return (x + y) % 2 == 0;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int x = coordinate1[0] - coordinate2[0];
        int y = coordinate1[1] - coordinate2[1];
        return (x + y) % 2 == 0;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func checkTwoChessboards(coordinate1 string, coordinate2 string) bool {
	x := coordinate1[0] - coordinate2[0]
	y := coordinate1[1] - coordinate2[1]
	return (x+y)%2 == 0
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function checkTwoChessboards(coordinate1: string, coordinate2: string): boolean {
    const x = coordinate1.charCodeAt(0) - coordinate2.charCodeAt(0);
    const y = coordinate1.charCodeAt(1) - coordinate2.charCodeAt(1);
    return (x + y) % 2 === 0;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个字符串 <code>coordinate1</code> 和 <code>coordinate2</code>，代表 <code>8 x 8</code> 国际象棋棋盘上的两个方格的坐标。</p>

<p>以下是棋盘的参考图。</p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3274.Check%20if%20Two%20Chessboard%20Squares%20Have%20the%20Same%20Color/images/screenshot-2021-02-20-at-22159-pm.png" style="width: 400px; height: 396px;" /></p>

<p>如果这两个方格颜色相同，返回 <code>true</code>，否则返回 <code>false</code>。</p>

<p>坐标总是表示有效的棋盘方格。坐标的格式总是先字母（表示列），再数字（表示行）。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">coordinate1 = "a1", coordinate2 = "c3"</span></p>

<p><strong>输出：</strong> <span class="example-io">true</span></p>

<p><strong>解释：</strong></p>

<p>两个方格均为黑色。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">coordinate1 = "a1", coordinate2 = "h3"</span></p>

<p><strong>输出：</strong> <span class="example-io">false</span></p>

<p><strong>解释：</strong></p>

<p>方格 <code>"a1"</code> 是黑色，而 <code>"h3"</code> 是白色。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>coordinate1.length == coordinate2.length == 2</code></li>
	<li><code>'a' &lt;= coordinate1[0], coordinate2[0] &lt;= 'h'</code></li>
	<li><code>'1' &lt;= coordinate1[1], coordinate2[1] &lt;= '8'</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学

我们计算两个坐标的横纵坐标的差值，如果两个坐标的横纵坐标的差值之和为偶数，那么这两个坐标的方格颜色相同，否则不同。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def checkTwoChessboards(self, coordinate1: str, coordinate2: str) -> bool:
        x = ord(coordinate1[0]) - ord(coordinate2[0])
        y = int(coordinate1[1]) - int(coordinate2[1])
        return (x + y) % 2 == 0
```

#### Java

```java
class Solution {
    public boolean checkTwoChessboards(String coordinate1, String coordinate2) {
        int x = coordinate1.charAt(0) - coordinate2.charAt(0);
        int y = coordinate1.charAt(1) - coordinate2.charAt(1);
        return (x + y) % 2 == 0;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int x = coordinate1[0] - coordinate2[0];
        int y = coordinate1[1] - coordinate2[1];
        return (x + y) % 2 == 0;
    }
};
```

#### Go

```go
func checkTwoChessboards(coordinate1 string, coordinate2 string) bool {
	x := coordinate1[0] - coordinate2[0]
	y := coordinate1[1] - coordinate2[1]
	return (x+y)%2 == 0
}
```

#### TypeScript

```ts
function checkTwoChessboards(coordinate1: string, coordinate2: string): boolean {
    const x = coordinate1.charCodeAt(0) - coordinate2.charCodeAt(0);
    const y = coordinate1.charCodeAt(1) - coordinate2.charCodeAt(1);
    return (x + y) % 2 === 0;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3275. 第 K 近障碍物查询](https://leetcode.cn/problems/k-th-nearest-obstacle-queries){#3275}

{{< tabs "3275" >}}

{{% tab "python" %}}
```python
class Solution:
    def resultsArray(self, queries: List[List[int]], k: int) -> List[int]:
        ans = []
        pq = []
        for i, (x, y) in enumerate(queries):
            heappush(pq, -(abs(x) + abs(y)))
            if i >= k:
                heappop(pq)
            ans.append(-pq[0] if i >= k - 1 else -1)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] resultsArray(int[][] queries, int k) {
        int n = queries.length;
        int[] ans = new int[n];
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for (int i = 0; i < n; ++i) {
            int x = Math.abs(queries[i][0]) + Math.abs(queries[i][1]);
            pq.offer(x);
            if (i >= k) {
                pq.poll();
            }
            ans[i] = i >= k - 1 ? pq.peek() : -1;
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
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        vector<int> ans;
        priority_queue<int> pq;
        for (const auto& q : queries) {
            int x = abs(q[0]) + abs(q[1]);
            pq.push(x);
            if (pq.size() > k) {
                pq.pop();
            }
            ans.push_back(pq.size() == k ? pq.top() : -1);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func resultsArray(queries [][]int, k int) (ans []int) {
	pq := &hp{}
	for _, q := range queries {
		x := abs(q[0]) + abs(q[1])
		pq.push(x)
		if pq.Len() > k {
			pq.pop()
		}
		if pq.Len() == k {
			ans = append(ans, pq.IntSlice[0])
		} else {
			ans = append(ans, -1)
		}
	}
	return
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

type hp struct{ sort.IntSlice }

func (h hp) Less(i, j int) bool { return h.IntSlice[i] > h.IntSlice[j] }
func (h *hp) Push(v any)        { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() any {
	a := h.IntSlice
	v := a[len(a)-1]
	h.IntSlice = a[:len(a)-1]
	return v
}
func (h *hp) push(v int) { heap.Push(h, v) }
func (h *hp) pop() int   { return heap.Pop(h).(int) }
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function resultsArray(queries: number[][], k: number): number[] {
    const pq = new MaxPriorityQueue();
    const ans: number[] = [];
    for (const [x, y] of queries) {
        pq.enqueue(Math.abs(x) + Math.abs(y));
        if (pq.size() > k) {
            pq.dequeue();
        }
        ans.push(pq.size() === k ? pq.front().element : -1);
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

<p>有一个无限大的二维平面。</p>

<p>给你一个正整数&nbsp;<code>k</code>&nbsp;，同时给你一个二维数组&nbsp;<code>queries</code>&nbsp;，包含一系列查询：</p>

<ul>
	<li><code>queries[i] = [x, y]</code>&nbsp;：在平面上坐标&nbsp;<code>(x, y)</code>&nbsp;处建一个障碍物，数据保证之前的查询 <strong>不会</strong> 在这个坐标处建立任何障碍物。</li>
</ul>

<p>每次查询后，你需要找到离原点第 <code>k</code>&nbsp;<strong>近</strong>&nbsp;障碍物到原点的 <strong>距离</strong>&nbsp;。</p>

<p>请你返回一个整数数组&nbsp;<code>results</code>&nbsp;，其中&nbsp;<code>results[i]</code>&nbsp;表示建立第 <code>i</code>&nbsp;个障碍物以后，离原地第 <code>k</code>&nbsp;近障碍物距离原点的距离。如果少于 <code>k</code>&nbsp;个障碍物，<code>results[i] == -1</code>&nbsp;。</p>

<p><strong>注意</strong>，一开始&nbsp;<strong>没有</strong>&nbsp;任何障碍物。</p>

<p>坐标在&nbsp;<code>(x, y)</code>&nbsp;处的点距离原点的距离定义为&nbsp;<code>|x| + |y|</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>queries = [[1,2],[3,4],[2,3],[-3,0]], k = 2</span></p>

<p><span class="example-io"><b>输出：</b>[-1,7,5,3]</span></p>

<p><strong>解释：</strong></p>

<p>最初，不存在障碍物。</p>

<ul>
	<li><code>queries[0]</code>&nbsp;之后，少于 2 个障碍物。</li>
	<li><code>queries[1]</code>&nbsp;之后，&nbsp;两个障碍物距离原点的距离分别为 3 和 7 。</li>
	<li><code>queries[2]</code>&nbsp;之后，障碍物距离原点的距离分别为 3 ，5 和 7 。</li>
	<li><code>queries[3]</code>&nbsp;之后，障碍物距离原点的距离分别为 3，3，5 和 7 。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>queries = [[5,5],[4,4],[3,3]], k = 1</span></p>

<p><span class="example-io"><b>输出：</b>[10,8,6]</span></p>

<p><b>解释：</b></p>

<ul>
	<li><code>queries[0]</code>&nbsp;之后，只有一个障碍物，距离原点距离为 10 。</li>
	<li><code>queries[1]</code>&nbsp;之后，障碍物距离原点距离分别为 8 和 10 。</li>
	<li><code>queries[2]</code>&nbsp;之后，障碍物距离原点的距离分别为 6， 8 和10 。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= queries.length &lt;= 2 * 10<sup>5</sup></code></li>
	<li>所有&nbsp;<code>queries[i]</code>&nbsp;互不相同。</li>
	<li><code>-10<sup>9</sup> &lt;= queries[i][0], queries[i][1] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：优先队列（大根堆）

我们可以使用一个优先队列（大根堆）来维护离原点最近的 $k$ 个障碍物。

遍历 $\textit{queries}$，每次计算 $x$ 和 $y$ 的绝对值之和，然后将其加入优先队列。如果优先队列的大小超过 $k$，则弹出堆顶元素。如果当前优先队列的大小等于 $k$，则将堆顶元素加入答案数组，否则将 $-1$ 加入答案数组。

遍历结束后，返回答案数组即可。

时间复杂度 $O(n \times \log k)$，空间复杂度 $O(k)$。其中 $n$ 为数组 $\textit{queries}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def resultsArray(self, queries: List[List[int]], k: int) -> List[int]:
        ans = []
        pq = []
        for i, (x, y) in enumerate(queries):
            heappush(pq, -(abs(x) + abs(y)))
            if i >= k:
                heappop(pq)
            ans.append(-pq[0] if i >= k - 1 else -1)
        return ans
```

#### Java

```java
class Solution {
    public int[] resultsArray(int[][] queries, int k) {
        int n = queries.length;
        int[] ans = new int[n];
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for (int i = 0; i < n; ++i) {
            int x = Math.abs(queries[i][0]) + Math.abs(queries[i][1]);
            pq.offer(x);
            if (i >= k) {
                pq.poll();
            }
            ans[i] = i >= k - 1 ? pq.peek() : -1;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        vector<int> ans;
        priority_queue<int> pq;
        for (const auto& q : queries) {
            int x = abs(q[0]) + abs(q[1]);
            pq.push(x);
            if (pq.size() > k) {
                pq.pop();
            }
            ans.push_back(pq.size() == k ? pq.top() : -1);
        }
        return ans;
    }
};
```

#### Go

```go
func resultsArray(queries [][]int, k int) (ans []int) {
	pq := &hp{}
	for _, q := range queries {
		x := abs(q[0]) + abs(q[1])
		pq.push(x)
		if pq.Len() > k {
			pq.pop()
		}
		if pq.Len() == k {
			ans = append(ans, pq.IntSlice[0])
		} else {
			ans = append(ans, -1)
		}
	}
	return
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

type hp struct{ sort.IntSlice }

func (h hp) Less(i, j int) bool { return h.IntSlice[i] > h.IntSlice[j] }
func (h *hp) Push(v any)        { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() any {
	a := h.IntSlice
	v := a[len(a)-1]
	h.IntSlice = a[:len(a)-1]
	return v
}
func (h *hp) push(v int) { heap.Push(h, v) }
func (h *hp) pop() int   { return heap.Pop(h).(int) }
```

#### TypeScript

```ts
function resultsArray(queries: number[][], k: number): number[] {
    const pq = new MaxPriorityQueue();
    const ans: number[] = [];
    for (const [x, y] of queries) {
        pq.enqueue(Math.abs(x) + Math.abs(y));
        if (pq.size() > k) {
            pq.dequeue();
        }
        ans.push(pq.size() === k ? pq.front().element : -1);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3276. 选择矩阵中单元格的最大得分](https://leetcode.cn/problems/select-cells-in-grid-with-maximum-score){#3276}

{{< tabs "3276" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxScore(self, grid: List[List[int]]) -> int:
        g = defaultdict(set)
        mx = 0
        for i, row in enumerate(grid):
            for x in row:
                g[x].add(i)
                mx = max(mx, x)
        m = len(grid)
        f = [[0] * (1 << m) for _ in range(mx + 1)]
        for i in range(1, mx + 1):
            for j in range(1 << m):
                f[i][j] = f[i - 1][j]
                for k in g[i]:
                    if j >> k & 1:
                        f[i][j] = max(f[i][j], f[i - 1][j ^ 1 << k] + i)
        return f[-1][-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxScore(List<List<Integer>> grid) {
        int m = grid.size();
        int mx = 0;
        boolean[][] g = new boolean[101][m + 1];
        for (int i = 0; i < m; ++i) {
            for (int x : grid.get(i)) {
                g[x][i] = true;
                mx = Math.max(mx, x);
            }
        }
        int[][] f = new int[mx + 1][1 << m];
        for (int i = 1; i <= mx; ++i) {
            for (int j = 0; j < 1 << m; ++j) {
                f[i][j] = f[i - 1][j];
                for (int k = 0; k < m; ++k) {
                    if (g[i][k] && (j >> k & 1) == 1) {
                        f[i][j] = Math.max(f[i][j], f[i - 1][j ^ 1 << k] + i);
                    }
                }
            }
        }
        return f[mx][(1 << m) - 1];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int mx = 0;
        bool g[101][11]{};
        for (int i = 0; i < m; ++i) {
            for (int x : grid[i]) {
                g[x][i] = true;
                mx = max(mx, x);
            }
        }
        int f[mx + 1][1 << m];
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= mx; ++i) {
            for (int j = 0; j < 1 << m; ++j) {
                f[i][j] = f[i - 1][j];
                for (int k = 0; k < m; ++k) {
                    if (g[i][k] && (j >> k & 1) == 1) {
                        f[i][j] = max(f[i][j], f[i - 1][j ^ 1 << k] + i);
                    }
                }
            }
        }
        return f[mx][(1 << m) - 1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxScore(grid [][]int) int {
	m := len(grid)
	mx := 0
	g := [101][11]bool{}
	for i, row := range grid {
		for _, x := range row {
			g[x][i] = true
			mx = max(mx, x)
		}
	}
	f := make([][]int, mx+1)
	for i := range f {
		f[i] = make([]int, 1<<m)
	}
	for i := 1; i <= mx; i++ {
		for j := 0; j < 1<<m; j++ {
			f[i][j] = f[i-1][j]
			for k := 0; k < m; k++ {
				if g[i][k] && (j>>k&1) == 1 {
					f[i][j] = max(f[i][j], f[i-1][j^1<<k]+i)
				}
			}
		}
	}
	return f[mx][1<<m-1]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxScore(grid: number[][]): number {
    const m = grid.length;
    let mx = 0;
    const g: boolean[][] = Array.from({ length: 101 }, () => Array(m + 1).fill(false));
    for (let i = 0; i < m; ++i) {
        for (const x of grid[i]) {
            g[x][i] = true;
            mx = Math.max(mx, x);
        }
    }
    const f: number[][] = Array.from({ length: mx + 1 }, () => Array(1 << m).fill(0));
    for (let i = 1; i <= mx; ++i) {
        for (let j = 0; j < 1 << m; ++j) {
            f[i][j] = f[i - 1][j];
            for (let k = 0; k < m; ++k) {
                if (g[i][k] && ((j >> k) & 1) === 1) {
                    f[i][j] = Math.max(f[i][j], f[i - 1][j ^ (1 << k)] + i);
                }
            }
        }
    }
    return f[mx][(1 << m) - 1];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个由正整数构成的二维矩阵 <code>grid</code>。</p>

<p>你需要从矩阵中选择<strong> 一个或多个 </strong>单元格，选中的单元格应满足以下条件：</p>

<ul>
	<li>所选单元格中的任意两个单元格都不会处于矩阵的 <strong>同一行</strong>。</li>
	<li>所选单元格的值 <strong>互不相同</strong>。</li>
</ul>

<p>你的得分为所选单元格值的<strong>总和</strong>。</p>

<p>返回你能获得的<strong> 最大 </strong>得分。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">grid = [[1,2,3],[4,3,2],[1,1,1]]</span></p>

<p><strong>输出：</strong> <span class="example-io">8</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3276.Select%20Cells%20in%20Grid%20With%20Maximum%20Score/images/grid1drawio.png" /></p>

<p>选择上图中用彩色标记的单元格，对应的值分别为 1、3 和 4 。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">grid = [[8,7,6],[8,3,2]]</span></p>

<p><strong>输出：</strong> <span class="example-io">15</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3276.Select%20Cells%20in%20Grid%20With%20Maximum%20Score/images/grid8_8drawio.png" style="width: 170px; height: 114px;" /></p>

<p>选择上图中用彩色标记的单元格，对应的值分别为 7 和 8 。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= grid.length, grid[i].length &lt;= 10</code></li>
	<li><code>1 &lt;= grid[i][j] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：状态压缩动态规划

我们定义 $f[i][j]$ 表示在 $[1,..i]$ 的数中进行选择，且选择的数对应的行的状态为 $j$ 时的最大得分。初始时 $f[i][j] = 0$，答案为 $f[\textit{mx}][2^m - 1]$。其中 $\textit{mx}$ 表示矩阵中的最大值，而 $m$ 表示矩阵的行数。

我们首先对矩阵进行预处理，使用一个哈希表 $g$ 记录每个数对应的行的集合。然后我们可以使用状态压缩动态规划的方法求解答案。

对于状态 $f[i][j]$，我们可以不选择 $i$ 这个数，此时 $f[i][j] = f[i-1][j]$；也可以选择 $i$ 这个数，此时我们需要枚举 $i$ 对应的行的集合 $g[i]$ 中的每一个行 $k$，如果 $j$ 的第 $k$ 位为 $1$，则说明我们可以选择 $i$ 这个数，此时 $f[i][j] = \max(f[i][j], f[i-1][j \oplus 2^k] + i)$。

最后我们返回 $f[\textit{mx}][2^m - 1]$ 即可。

时间复杂度 $O(m \times 2^m \times \textit{mx})$，空间复杂度 $O(\textit{mx} \times 2^m)$。其中 $m$ 为矩阵的行数，而 $\textit{mx}$ 为矩阵中的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxScore(self, grid: List[List[int]]) -> int:
        g = defaultdict(set)
        mx = 0
        for i, row in enumerate(grid):
            for x in row:
                g[x].add(i)
                mx = max(mx, x)
        m = len(grid)
        f = [[0] * (1 << m) for _ in range(mx + 1)]
        for i in range(1, mx + 1):
            for j in range(1 << m):
                f[i][j] = f[i - 1][j]
                for k in g[i]:
                    if j >> k & 1:
                        f[i][j] = max(f[i][j], f[i - 1][j ^ 1 << k] + i)
        return f[-1][-1]
```

#### Java

```java
class Solution {
    public int maxScore(List<List<Integer>> grid) {
        int m = grid.size();
        int mx = 0;
        boolean[][] g = new boolean[101][m + 1];
        for (int i = 0; i < m; ++i) {
            for (int x : grid.get(i)) {
                g[x][i] = true;
                mx = Math.max(mx, x);
            }
        }
        int[][] f = new int[mx + 1][1 << m];
        for (int i = 1; i <= mx; ++i) {
            for (int j = 0; j < 1 << m; ++j) {
                f[i][j] = f[i - 1][j];
                for (int k = 0; k < m; ++k) {
                    if (g[i][k] && (j >> k & 1) == 1) {
                        f[i][j] = Math.max(f[i][j], f[i - 1][j ^ 1 << k] + i);
                    }
                }
            }
        }
        return f[mx][(1 << m) - 1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int mx = 0;
        bool g[101][11]{};
        for (int i = 0; i < m; ++i) {
            for (int x : grid[i]) {
                g[x][i] = true;
                mx = max(mx, x);
            }
        }
        int f[mx + 1][1 << m];
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= mx; ++i) {
            for (int j = 0; j < 1 << m; ++j) {
                f[i][j] = f[i - 1][j];
                for (int k = 0; k < m; ++k) {
                    if (g[i][k] && (j >> k & 1) == 1) {
                        f[i][j] = max(f[i][j], f[i - 1][j ^ 1 << k] + i);
                    }
                }
            }
        }
        return f[mx][(1 << m) - 1];
    }
};
```

#### Go

```go
func maxScore(grid [][]int) int {
	m := len(grid)
	mx := 0
	g := [101][11]bool{}
	for i, row := range grid {
		for _, x := range row {
			g[x][i] = true
			mx = max(mx, x)
		}
	}
	f := make([][]int, mx+1)
	for i := range f {
		f[i] = make([]int, 1<<m)
	}
	for i := 1; i <= mx; i++ {
		for j := 0; j < 1<<m; j++ {
			f[i][j] = f[i-1][j]
			for k := 0; k < m; k++ {
				if g[i][k] && (j>>k&1) == 1 {
					f[i][j] = max(f[i][j], f[i-1][j^1<<k]+i)
				}
			}
		}
	}
	return f[mx][1<<m-1]
}
```

#### TypeScript

```ts
function maxScore(grid: number[][]): number {
    const m = grid.length;
    let mx = 0;
    const g: boolean[][] = Array.from({ length: 101 }, () => Array(m + 1).fill(false));
    for (let i = 0; i < m; ++i) {
        for (const x of grid[i]) {
            g[x][i] = true;
            mx = Math.max(mx, x);
        }
    }
    const f: number[][] = Array.from({ length: mx + 1 }, () => Array(1 << m).fill(0));
    for (let i = 1; i <= mx; ++i) {
        for (let j = 0; j < 1 << m; ++j) {
            f[i][j] = f[i - 1][j];
            for (let k = 0; k < m; ++k) {
                if (g[i][k] && ((j >> k) & 1) === 1) {
                    f[i][j] = Math.max(f[i][j], f[i - 1][j ^ (1 << k)] + i);
                }
            }
        }
    }
    return f[mx][(1 << m) - 1];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3277. 查询子数组最大异或值](https://leetcode.cn/problems/maximum-xor-score-subarray-queries){#3277}

{{< tabs "3277" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumSubarrayXor(
        self, nums: List[int], queries: List[List[int]]
    ) -> List[int]:
        n = len(nums)
        f = [[0] * n for _ in range(n)]
        g = [[0] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            f[i][i] = g[i][i] = nums[i]
            for j in range(i + 1, n):
                f[i][j] = f[i][j - 1] ^ f[i + 1][j]
                g[i][j] = max(f[i][j], g[i][j - 1], g[i + 1][j])
        return [g[l][r] for l, r in queries]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] maximumSubarrayXor(int[] nums, int[][] queries) {
        int n = nums.length;
        int[][] f = new int[n][n];
        int[][] g = new int[n][n];
        for (int i = n - 1; i >= 0; --i) {
            f[i][i] = nums[i];
            g[i][i] = nums[i];
            for (int j = i + 1; j < n; ++j) {
                f[i][j] = f[i][j - 1] ^ f[i + 1][j];
                g[i][j] = Math.max(f[i][j], Math.max(g[i][j - 1], g[i + 1][j]));
            }
        }
        int m = queries.length;
        int[] ans = new int[m];
        for (int i = 0; i < m; ++i) {
            int l = queries[i][0], r = queries[i][1];
            ans[i] = g[l][r];
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
    vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<vector<int>> f(n, vector<int>(n));
        vector<vector<int>> g(n, vector<int>(n));
        for (int i = n - 1; i >= 0; --i) {
            f[i][i] = nums[i];
            g[i][i] = nums[i];
            for (int j = i + 1; j < n; ++j) {
                f[i][j] = f[i][j - 1] ^ f[i + 1][j];
                g[i][j] = max({f[i][j], g[i][j - 1], g[i + 1][j]});
            }
        }
        vector<int> ans;
        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            ans.push_back(g[l][r]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumSubarrayXor(nums []int, queries [][]int) (ans []int) {
	n := len(nums)
	f := make([][]int, n)
	g := make([][]int, n)
	for i := 0; i < n; i++ {
		f[i] = make([]int, n)
		g[i] = make([]int, n)
	}
	for i := n - 1; i >= 0; i-- {
		f[i][i] = nums[i]
		g[i][i] = nums[i]
		for j := i + 1; j < n; j++ {
			f[i][j] = f[i][j-1] ^ f[i+1][j]
			g[i][j] = max(f[i][j], max(g[i][j-1], g[i+1][j]))
		}
	}
	for _, q := range queries {
		l, r := q[0], q[1]
		ans = append(ans, g[l][r])
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumSubarrayXor(nums: number[], queries: number[][]): number[] {
    const n = nums.length;
    const f: number[][] = Array.from({ length: n }, () => Array(n).fill(0));
    const g: number[][] = Array.from({ length: n }, () => Array(n).fill(0));
    for (let i = n - 1; i >= 0; i--) {
        f[i][i] = nums[i];
        g[i][i] = nums[i];
        for (let j = i + 1; j < n; j++) {
            f[i][j] = f[i][j - 1] ^ f[i + 1][j];
            g[i][j] = Math.max(f[i][j], Math.max(g[i][j - 1], g[i + 1][j]));
        }
    }
    return queries.map(([l, r]) => g[l][r]);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个由 <code>n</code> 个整数组成的数组 <code>nums</code>，以及一个大小为 <code>q</code> 的二维整数数组 <code>queries</code>，其中 <code>queries[i] = [l<sub>i</sub>, r<sub>i</sub>]</code>。</p>

<p>对于每一个查询，你需要找出 <code>nums[l<sub>i</sub>..r<sub>i</sub>]</code> 中任意 <span data-keyword="subarray">子数组</span> 的 <strong>最大异或值</strong>。</p>

<p><strong>数组的异或值 </strong>需要对数组 <code>a</code> 反复执行以下操作，直到只剩一个元素，剩下的那个元素就是 <strong>异或值</strong>：</p>

<ul>
	<li><span class="text-only" data-eleid="9" style="white-space: pre;">对于除最后一个下标以外的所有下标</span> <code>i</code>，同时将 <code>a[i]</code> 替换为 <code>a[i] XOR a[i + 1]</code> 。</li>
	<li>移除数组的最后一个元素。</li>
</ul>

<p>返回一个大小为 <code>q</code> 的数组 <code>answer</code>，其中 <code>answer[i]</code> 表示查询 <code>i</code> 的答案。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [2,8,4,32,16,1], queries = [[0,2],[1,4],[0,5]]</span></p>

<p><strong>输出：</strong> <span class="example-io">[12,60,60]</span></p>

<p><strong>解释：</strong></p>

<p>在第一个查询中，<code>nums[0..2]</code> 的子数组分别是 <code>[2]</code>, <code>[8]</code>, <code>[4]</code>, <code>[2, 8]</code>, <code>[8, 4]</code>, 和 <code>[2, 8, 4]</code>，它们的异或值分别为 2, 8, 4, 10, 12, 和 6。查询的答案是 12，所有异或值中的最大值。</p>

<p>在第二个查询中，<code>nums[1..4]</code> 的子数组中最大的异或值是子数组 <code>nums[1..4]</code> 的异或值，为 60。</p>

<p>在第三个查询中，<code>nums[0..5]</code> 的子数组中最大的异或值是子数组 <code>nums[1..4]</code> 的异或值，为 60。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [0,7,3,2,8,5,1], queries = [[0,3],[1,5],[2,4],[2,6],[5,6]]</span></p>

<p><strong>输出：</strong> <span class="example-io">[7,14,11,14,5]</span></p>

<p><strong>解释：</strong></p>

<table height="70" width="472">
	<thead>
		<tr>
			<th>下标</th>
			<th>nums[l<sub>i</sub>..r<sub>i</sub>]</th>
			<th>最大异或值子数组</th>
			<th>子数组最大异或值</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>0</td>
			<td>[0, 7, 3, 2]</td>
			<td>[7]</td>
			<td>7</td>
		</tr>
		<tr>
			<td>1</td>
			<td>[7, 3, 2, 8, 5]</td>
			<td>[7, 3, 2, 8]</td>
			<td>14</td>
		</tr>
		<tr>
			<td>2</td>
			<td>[3, 2, 8]</td>
			<td>[3, 2, 8]</td>
			<td>11</td>
		</tr>
		<tr>
			<td>3</td>
			<td>[3, 2, 8, 5, 1]</td>
			<td>[2, 8, 5, 1]</td>
			<td>14</td>
		</tr>
		<tr>
			<td>4</td>
			<td>[5, 1]</td>
			<td>[5]</td>
			<td>5</td>
		</tr>
	</tbody>
</table>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == nums.length &lt;= 2000</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
	<li><code>1 &lt;= q == queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>queries[i].length == 2</code></li>
	<li><code>queries[i] = [l<sub>i</sub>, r<sub>i</sub>]</code></li>
	<li><code>0 &lt;= l<sub>i</sub> &lt;= r<sub>i</sub> &lt;= n - 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示 $\textit{nums}[i..j]$ 的异或值，那么根据题目描述，我们可以得到状态转移方程：

$$
f[i][j] = f[i][j-1] \oplus f[i+1][j]
$$

其中 $\oplus$ 表示异或运算。

我们再定义 $g[i][j]$ 表示 $f[i][j]$ 的最大值，那么状态转移方程为：

$$
g[i][j] = \max(f[i][j], g[i][j-1], g[i+1][j])
$$

最后，我们遍历查询数组，对于每个查询 $[l, r]$，将 $g[l][r]$ 加入答案数组即可。

时间复杂度 $O(n^2 + m)$，空间复杂度 $O(n^2)$。其中 $n$ 和 $m$ 分别为数组 $\textit{nums}$ 和 $\textit{queries}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumSubarrayXor(
        self, nums: List[int], queries: List[List[int]]
    ) -> List[int]:
        n = len(nums)
        f = [[0] * n for _ in range(n)]
        g = [[0] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            f[i][i] = g[i][i] = nums[i]
            for j in range(i + 1, n):
                f[i][j] = f[i][j - 1] ^ f[i + 1][j]
                g[i][j] = max(f[i][j], g[i][j - 1], g[i + 1][j])
        return [g[l][r] for l, r in queries]
```

#### Java

```java
class Solution {
    public int[] maximumSubarrayXor(int[] nums, int[][] queries) {
        int n = nums.length;
        int[][] f = new int[n][n];
        int[][] g = new int[n][n];
        for (int i = n - 1; i >= 0; --i) {
            f[i][i] = nums[i];
            g[i][i] = nums[i];
            for (int j = i + 1; j < n; ++j) {
                f[i][j] = f[i][j - 1] ^ f[i + 1][j];
                g[i][j] = Math.max(f[i][j], Math.max(g[i][j - 1], g[i + 1][j]));
            }
        }
        int m = queries.length;
        int[] ans = new int[m];
        for (int i = 0; i < m; ++i) {
            int l = queries[i][0], r = queries[i][1];
            ans[i] = g[l][r];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<vector<int>> f(n, vector<int>(n));
        vector<vector<int>> g(n, vector<int>(n));
        for (int i = n - 1; i >= 0; --i) {
            f[i][i] = nums[i];
            g[i][i] = nums[i];
            for (int j = i + 1; j < n; ++j) {
                f[i][j] = f[i][j - 1] ^ f[i + 1][j];
                g[i][j] = max({f[i][j], g[i][j - 1], g[i + 1][j]});
            }
        }
        vector<int> ans;
        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            ans.push_back(g[l][r]);
        }
        return ans;
    }
};
```

#### Go

```go
func maximumSubarrayXor(nums []int, queries [][]int) (ans []int) {
	n := len(nums)
	f := make([][]int, n)
	g := make([][]int, n)
	for i := 0; i < n; i++ {
		f[i] = make([]int, n)
		g[i] = make([]int, n)
	}
	for i := n - 1; i >= 0; i-- {
		f[i][i] = nums[i]
		g[i][i] = nums[i]
		for j := i + 1; j < n; j++ {
			f[i][j] = f[i][j-1] ^ f[i+1][j]
			g[i][j] = max(f[i][j], max(g[i][j-1], g[i+1][j]))
		}
	}
	for _, q := range queries {
		l, r := q[0], q[1]
		ans = append(ans, g[l][r])
	}
	return
}
```

#### TypeScript

```ts
function maximumSubarrayXor(nums: number[], queries: number[][]): number[] {
    const n = nums.length;
    const f: number[][] = Array.from({ length: n }, () => Array(n).fill(0));
    const g: number[][] = Array.from({ length: n }, () => Array(n).fill(0));
    for (let i = n - 1; i >= 0; i--) {
        f[i][i] = nums[i];
        g[i][i] = nums[i];
        for (let j = i + 1; j < n; j++) {
            f[i][j] = f[i][j - 1] ^ f[i + 1][j];
            g[i][j] = Math.max(f[i][j], Math.max(g[i][j - 1], g[i + 1][j]));
        }
    }
    return queries.map(([l, r]) => g[l][r]);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3278. 寻找数据科学家职位的候选人 II 🔒](https://leetcode.cn/problems/find-candidates-for-data-scientist-position-ii){#3278}

{{< tabs "3278" >}}

{{% tab "sql" %}}
```sql
WITH
    S AS (
        SELECT
            candidate_id,
            project_id,
            COUNT(*) matched_skills,
            SUM(
                CASE
                    WHEN proficiency > importance THEN 10
                    WHEN proficiency < importance THEN -5
                    ELSE 0
                END
            ) + 100 AS score
        FROM
            Candidates
            JOIN Projects USING (skill)
        GROUP BY 1, 2
    ),
    T AS (
        SELECT project_id, COUNT(1) required_skills
        FROM Projects
        GROUP BY 1
    ),
    P AS (
        SELECT
            project_id,
            candidate_id,
            score,
            RANK() OVER (
                PARTITION BY project_id
                ORDER BY score DESC, candidate_id
            ) rk
        FROM
            S
            JOIN T USING (project_id)
        WHERE matched_skills = required_skills
    )
SELECT project_id, candidate_id, score
FROM P
WHERE rk = 1
ORDER BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<font face="monospace"><code>Candidates</code></font></p>

<pre>
+--------------+---------+ 
| Column Name  | Type    | 
+--------------+---------+ 
| candidate_id | int     | 
| skill        | varchar |
| proficiency  | int     |
+--------------+---------+
是这张表的主键（有不同值的列）。 
每一行包括 candidate_id 和技能，以及熟练程度（1-5）。
</pre>

<p>表：<font face="monospace"><code>Projects</code></font></p>

<pre>
+--------------+---------+ 
| Column Name  | Type    | 
+--------------+---------+ 
| project_id   | int     | 
| skill        | varchar |
| importance   | int     |
+--------------+---------+
(project_id, skill) 是这张表的主键。
每一行包括 project_id，所需技能，以及项目的重要性（1-5）。
</pre>

<p>Leetcode 正在为多个数据科学项目招聘人员。编写一个解决方案来根据以下条件为 <strong>每一个项目</strong> 找到 <strong>最佳候选人</strong>：</p>

<ol>
	<li>候选人必须拥有项目所需的 <strong>所有</strong>&nbsp;技能。</li>
	<li>为每个候选人-项目对计算如下的 <strong>分数</strong>：
	<ul>
		<li>从&nbsp;<code>100</code>&nbsp;分<strong>&nbsp;开始。</strong></li>
		<li>对于每一个技能，当 <b>熟练程度 &gt; 重要性 加</b>&nbsp;<code>10</code>&nbsp;分。</li>
		<li>对于每一个技能，当&nbsp;<strong>熟练程度 &lt; 重要性 减</strong>&nbsp;<code>5</code>&nbsp;分。</li>
		<li>如果候选人的技能熟练程度 <strong>等于</strong> 项目的技能重要性，则分数保持不变</li>
	</ul>
	</li>
</ol>

<p>仅包括每个项目的最佳候选人（最高分）。如果 <strong>相同</strong>，选择有 <strong>更小</strong>&nbsp;<code>candidate_id</code>&nbsp;的候选人。如果一个项目 <strong>没有适合的候选人</strong>，<strong>不要返回 </strong>那个项目。</p>

<p>返回结果表以&nbsp;<code>project_id</code>&nbsp;升序排序。</p>

<p>输出格式如下所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例：</strong></p>

<div class="example-block">
<p><strong>输入：</strong></p>

<p><code>Candidates</code> 表：</p>

<pre class="example-io">
+--------------+-----------+-------------+
| candidate_id | skill     | proficiency |
+--------------+-----------+-------------+
| 101          | Python    | 5           |
| 101          | Tableau   | 3           |
| 101          | PostgreSQL| 4           |
| 101          | TensorFlow| 2           |
| 102          | Python    | 4           |
| 102          | Tableau   | 5           |
| 102          | PostgreSQL| 4           |
| 102          | R         | 4           |
| 103          | Python    | 3           |
| 103          | Tableau   | 5           |
| 103          | PostgreSQL| 5           |
| 103          | Spark     | 4           |
+--------------+-----------+-------------+
</pre>

<p><code>Projects</code> 表：</p>

<pre class="example-io">
+-------------+-----------+------------+
| project_id  | skill     | importance |
+-------------+-----------+------------+
| 501         | Python    | 4          |
| 501         | Tableau   | 3          |
| 501         | PostgreSQL| 5          |
| 502         | Python    | 3          |
| 502         | Tableau   | 4          |
| 502         | R         | 2          |
+-------------+-----------+------------+
</pre>

<p><strong>输出：</strong></p>

<pre class="example-io">
+-------------+--------------+-------+
| project_id  | candidate_id | score |
+-------------+--------------+-------+
| 501         | 101          | 105   |
| 502         | 102          | 130   |
+-------------+--------------+-------+
</pre>

<p><strong>解释：</strong></p>

<ul>
	<li>对于项目 501, 候选人 101 有最高的 105 分。所有其他的候选人有相同的分数，但候选人 101 有比他们更小的 candidate_id。</li>
	<li>对于项目 502，候选人&nbsp;102 有最高的 130&nbsp;分。</li>
</ul>

<p>输出表以 project_id 升序排序。</p>
</div>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：等值连接 + 分组统计 + 窗口函数

我们可以将表 `Candidates` 和表 `Projects` 通过 `skill` 列进行等值连接，统计每个候选人在每个项目中匹配的技能数量、总分数，记录在表 `S` 中。

然后我们再次统计每个项目所需的技能数量，记录在表 `T` 中。

接着我们将表 `S` 和表 `T` 通过 `project_id` 列进行等值连接，筛选出匹配的技能数量等于所需技能数量的候选人，记录在表 `P` 中，并计算每个项目的候选人排名，字段为 `rk`。

最后我们筛选出每个项目的排名为 1 的候选人，即为最佳候选人。

<!-- tabs:start -->

#### MySQL

```sql
WITH
    S AS (
        SELECT
            candidate_id,
            project_id,
            COUNT(*) matched_skills,
            SUM(
                CASE
                    WHEN proficiency > importance THEN 10
                    WHEN proficiency < importance THEN -5
                    ELSE 0
                END
            ) + 100 AS score
        FROM
            Candidates
            JOIN Projects USING (skill)
        GROUP BY 1, 2
    ),
    T AS (
        SELECT project_id, COUNT(1) required_skills
        FROM Projects
        GROUP BY 1
    ),
    P AS (
        SELECT
            project_id,
            candidate_id,
            score,
            RANK() OVER (
                PARTITION BY project_id
                ORDER BY score DESC, candidate_id
            ) rk
        FROM
            S
            JOIN T USING (project_id)
        WHERE matched_skills = required_skills
    )
SELECT project_id, candidate_id, score
FROM P
WHERE rk = 1
ORDER BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3279. 活塞占据的最大总区域 🔒](https://leetcode.cn/problems/maximum-total-area-occupied-by-pistons){#3279}

{{< tabs "3279" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxArea(self, height: int, positions: List[int], directions: str) -> int:
        delta = defaultdict(int)
        diff = res = 0
        for pos, dir in zip(positions, directions):
            res += pos
            if dir == "U":
                diff += 1
                delta[height - pos] -= 2
                delta[height * 2 - pos] += 2
            else:
                diff -= 1
                delta[pos] += 2
                delta[height + pos] -= 2
        ans = res
        pre = 0
        for cur, d in sorted(delta.items()):
            res += (cur - pre) * diff
            pre = cur
            diff += d
            ans = max(ans, res)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long maxArea(int height, int[] positions, String directions) {
        Map<Integer, Integer> delta = new TreeMap<>();
        int diff = 0;
        long res = 0;
        for (int i = 0; i < positions.length; ++i) {
            int pos = positions[i];
            char dir = directions.charAt(i);
            res += pos;
            if (dir == 'U') {
                ++diff;
                delta.merge(height - pos, -2, Integer::sum);
                delta.merge(height * 2 - pos, 2, Integer::sum);
            } else {
                --diff;
                delta.merge(pos, 2, Integer::sum);
                delta.merge(height + pos, -2, Integer::sum);
            }
        }
        long ans = res;
        int pre = 0;
        for (var e : delta.entrySet()) {
            int cur = e.getKey();
            int d = e.getValue();
            res += (long) (cur - pre) * diff;
            pre = cur;
            diff += d;
            ans = Math.max(ans, res);
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
    long long maxArea(int height, vector<int>& positions, string directions) {
        map<int, int> delta;
        int diff = 0;
        long long res = 0;

        for (int i = 0; i < positions.size(); ++i) {
            int pos = positions[i];
            char dir = directions[i];
            res += pos;

            if (dir == 'U') {
                ++diff;
                delta[height - pos] -= 2;
                delta[height * 2 - pos] += 2;
            } else {
                --diff;
                delta[pos] += 2;
                delta[height + pos] -= 2;
            }
        }

        long long ans = res;
        int pre = 0;

        for (const auto& [cur, d] : delta) {
            res += static_cast<long long>(cur - pre) * diff;
            pre = cur;
            diff += d;
            ans = max(ans, res);
        }

        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxArea(height int, positions []int, directions string) int64 {
	delta := make(map[int]int)
	diff := 0
	var res int64 = 0
	for i, pos := range positions {
		dir := directions[i]
		res += int64(pos)

		if dir == 'U' {
			diff++
			delta[height-pos] -= 2
			delta[height*2-pos] += 2
		} else {
			diff--
			delta[pos] += 2
			delta[height+pos] -= 2
		}
	}
	ans := res
	pre := 0
	keys := make([]int, 0, len(delta))
	for key := range delta {
		keys = append(keys, key)
	}
	sort.Ints(keys)
	for _, cur := range keys {
		d := delta[cur]
		res += int64(cur-pre) * int64(diff)
		pre = cur
		diff += d
		ans = max(ans, res)
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

<p>一台旧车的引擎中有一些活塞，我们想要计算活塞 <strong>下方</strong> 的 <strong>最大</strong> 区域。</p>

<p>给定：</p>

<ul>
	<li>一个整数&nbsp;<code>height</code>，表示活塞 <strong>最大</strong> 可到达的高度。</li>
	<li>一个整数数组&nbsp;<code>positions</code>，其中&nbsp;<code>positions[i]</code>&nbsp;是活塞&nbsp;<code>i</code>&nbsp;的当前位置，等于其 <strong>下方</strong>&nbsp;的当前区域。</li>
	<li>一个字符串&nbsp;<code>directions</code>，其中&nbsp;<code>directions[i]</code>&nbsp;是活塞&nbsp;<code>i</code>&nbsp;的当前移动方向，<code>'U'</code> 表示向上，<code>'D'</code> 表示向下。</li>
</ul>

<p>每一秒：</p>

<ul>
	<li>每个活塞向它的当前方向移动 1 单位。即如果方向向上，<code>positions[i]</code> 增加 1。</li>
	<li>如果一个活塞到达了其中一个终点，即&nbsp;<code>positions[i] == 0</code> 或&nbsp;<code>positions[i] == height</code>，它的方向将会改变。</li>
</ul>

<p>返回所有活塞下方的最大可能区域。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">height = 5, positions = [2,5], directions = "UD"</span></p>

<p><span class="example-io"><b>输出：</b>7</span></p>

<p><strong>解释：</strong></p>

<p>当前活塞的位置下方区域最大。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">height = 6, positions = [0,0,6,3], directions = "UUDU"</span></p>

<p><span class="example-io"><b>输出：</b>15</span></p>

<p><strong>解释：</strong></p>

<p>三秒后，活塞将会位于&nbsp;<code>[3, 3, 3, 6]</code>，此时下方区域最大。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= height &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= positions.length == directions.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= positions[i] &lt;= height</code></li>
	<li><code>directions[i]</code>&nbsp;为&nbsp;<code>'U'</code>&nbsp;或&nbsp;<code>'D'</code>。</li>
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
    def maxArea(self, height: int, positions: List[int], directions: str) -> int:
        delta = defaultdict(int)
        diff = res = 0
        for pos, dir in zip(positions, directions):
            res += pos
            if dir == "U":
                diff += 1
                delta[height - pos] -= 2
                delta[height * 2 - pos] += 2
            else:
                diff -= 1
                delta[pos] += 2
                delta[height + pos] -= 2
        ans = res
        pre = 0
        for cur, d in sorted(delta.items()):
            res += (cur - pre) * diff
            pre = cur
            diff += d
            ans = max(ans, res)
        return ans
```

#### Java

```java
class Solution {
    public long maxArea(int height, int[] positions, String directions) {
        Map<Integer, Integer> delta = new TreeMap<>();
        int diff = 0;
        long res = 0;
        for (int i = 0; i < positions.length; ++i) {
            int pos = positions[i];
            char dir = directions.charAt(i);
            res += pos;
            if (dir == 'U') {
                ++diff;
                delta.merge(height - pos, -2, Integer::sum);
                delta.merge(height * 2 - pos, 2, Integer::sum);
            } else {
                --diff;
                delta.merge(pos, 2, Integer::sum);
                delta.merge(height + pos, -2, Integer::sum);
            }
        }
        long ans = res;
        int pre = 0;
        for (var e : delta.entrySet()) {
            int cur = e.getKey();
            int d = e.getValue();
            res += (long) (cur - pre) * diff;
            pre = cur;
            diff += d;
            ans = Math.max(ans, res);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long maxArea(int height, vector<int>& positions, string directions) {
        map<int, int> delta;
        int diff = 0;
        long long res = 0;

        for (int i = 0; i < positions.size(); ++i) {
            int pos = positions[i];
            char dir = directions[i];
            res += pos;

            if (dir == 'U') {
                ++diff;
                delta[height - pos] -= 2;
                delta[height * 2 - pos] += 2;
            } else {
                --diff;
                delta[pos] += 2;
                delta[height + pos] -= 2;
            }
        }

        long long ans = res;
        int pre = 0;

        for (const auto& [cur, d] : delta) {
            res += static_cast<long long>(cur - pre) * diff;
            pre = cur;
            diff += d;
            ans = max(ans, res);
        }

        return ans;
    }
};
```

#### Go

```go
func maxArea(height int, positions []int, directions string) int64 {
	delta := make(map[int]int)
	diff := 0
	var res int64 = 0
	for i, pos := range positions {
		dir := directions[i]
		res += int64(pos)

		if dir == 'U' {
			diff++
			delta[height-pos] -= 2
			delta[height*2-pos] += 2
		} else {
			diff--
			delta[pos] += 2
			delta[height+pos] -= 2
		}
	}
	ans := res
	pre := 0
	keys := make([]int, 0, len(delta))
	for key := range delta {
		keys = append(keys, key)
	}
	sort.Ints(keys)
	for _, cur := range keys {
		d := delta[cur]
		res += int64(cur-pre) * int64(diff)
		pre = cur
		diff += d
		ans = max(ans, res)
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
