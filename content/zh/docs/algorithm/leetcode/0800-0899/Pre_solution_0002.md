---
title: "0810_黑板异或游戏"
date: 2025-10-08T18:36:34+08:00
weight: 2
tags: [二叉树, 位运算, 几何, 前缀和, 动态规划, 博弈, 哈希表, 回溯, 字符串, 广度优先搜索, 数学, 数组, 枚举, 树, 深度优先搜索, 脑筋急转弯, 计数, 链表]
---

{{< markmap >}}
### [0810_黑板异或游戏](#810)
#### [位运算](#810)
#### [脑筋急转弯](#810)
#### [数组](#810)
#### [数学](#810)
#### [博弈](#810)
### [0811_子域名访问计数](#811)
#### [数组](#811)
#### [哈希表](#811)
#### [字符串](#811)
#### [计数](#811)
### [0812_最大三角形面积](#812)
#### [几何](#812)
#### [数组](#812)
#### [数学](#812)
### [0813_最大平均值和的分组](#813)
#### [数组](#813)
#### [动态规划](#813)
#### [前缀和](#813)
### [0814_二叉树剪枝](#814)
#### [树](#814)
#### [深度优先搜索](#814)
#### [二叉树](#814)
### [0815_公交路线](#815)
#### [广度优先搜索](#815)
#### [数组](#815)
#### [哈希表](#815)
### [0816_模糊坐标](#816)
#### [字符串](#816)
#### [回溯](#816)
#### [枚举](#816)
### [0817_链表组件](#817)
#### [数组](#817)
#### [哈希表](#817)
#### [链表](#817)
### [0818_赛车](#818)
#### [动态规划](#818)
### [0819_最常见的单词](#819)
#### [数组](#819)
#### [哈希表](#819)
#### [字符串](#819)
#### [计数](#819)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0810_黑板异或游戏
___
#### 位运算
___
#### 脑筋急转弯
___
#### 数组
___
#### 数学
___
#### 博弈
---
### 0811_子域名访问计数
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 计数
---
### 0812_最大三角形面积
___
#### 几何
___
#### 数组
___
#### 数学
---
### 0813_最大平均值和的分组
___
#### 数组
___
#### 动态规划
___
#### 前缀和
---
### 0814_二叉树剪枝
___
#### 树
___
#### 深度优先搜索
___
#### 二叉树
---
### 0815_公交路线
___
#### 广度优先搜索
___
#### 数组
___
#### 哈希表
---
### 0816_模糊坐标
___
#### 字符串
___
#### 回溯
___
#### 枚举
---
### 0817_链表组件
___
#### 数组
___
#### 哈希表
___
#### 链表
---
### 0818_赛车
___
#### 动态规划
---
### 0819_最常见的单词
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 计数
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二叉树 | 位运算 | 几何 |
| 前缀和 | 动态规划 | 博弈 |
| 哈希表 | 回溯 | 字符串 |
| 广度优先搜索 | 数学 | 数组 |
| 枚举 | 树 | 深度优先搜索 |
| 脑筋急转弯 | 计数 | 链表 |

# [810. 黑板异或游戏](https://leetcode.cn/problems/chalkboard-xor-game){#810}

{{< tabs "810" >}}

{{% tab "python" %}}
```python
class Solution:
    def xorGame(self, nums: List[int]) -> bool:
        return len(nums) % 2 == 0 or reduce(xor, nums) == 0
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean xorGame(int[] nums) {
        return nums.length % 2 == 0 || Arrays.stream(nums).reduce(0, (a, b) -> a ^ b) == 0;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool xorGame(vector<int>& nums) {
        if (nums.size() % 2 == 0) return true;
        int x = 0;
        for (int& v : nums) x ^= v;
        return x == 0;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func xorGame(nums []int) bool {
	if len(nums)%2 == 0 {
		return true
	}
	x := 0
	for _, v := range nums {
		x ^= v
	}
	return x == 0
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>黑板上写着一个非负整数数组 <code>nums[i]</code> 。</p>

<p>Alice 和 Bob 轮流从黑板上擦掉一个数字，Alice 先手。如果擦除一个数字后，剩余的所有数字按位异或运算得出的结果等于 <code>0</code> 的话，当前玩家游戏失败。&nbsp;另外，如果只剩一个数字，按位异或运算得到它本身；如果无数字剩余，按位异或运算结果为&nbsp;<code>0</code>。</p>

<p>并且，轮到某个玩家时，如果当前黑板上所有数字按位异或运算结果等于 <code>0</code> ，这个玩家获胜。</p>

<p>假设两个玩家每步都使用最优解，当且仅当 Alice 获胜时返回 <code>true</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入:</strong> nums = [1,1,2]
<strong>输出:</strong> false
<strong>解释:</strong> 
Alice 有两个选择: 擦掉数字 1 或 2。
如果擦掉 1, 数组变成 [1, 2]。剩余数字按位异或得到 1 XOR 2 = 3。那么 Bob 可以擦掉任意数字，因为 Alice 会成为擦掉最后一个数字的人，她总是会输。
如果 Alice 擦掉 2，那么数组变成[1, 1]。剩余数字按位异或得到 1 XOR 1 = 0。Alice 仍然会输掉游戏。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> nums = [0,1]
<strong>输出:</strong> true
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> nums = [1,2,3]
<strong>输出:</strong> true
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums[i] &lt; 2<sup>16</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：位运算

根据游戏规则，轮到某个玩家时，如果当前黑板上所有数字按位异或运算结果为 $0$，这个玩家获胜。由于 Alice 先手，因此当 $\textit{nums}$ 中所有数字的异或结果为 $0$ 时，Alice 可以获胜。

当 $\textit{nums}$ 中所有数字的异或结果不为 $0$ 时，我们不妨考虑从数组 $\textit{nums}$ 的长度奇偶性来分析 Alice 的获胜情况。

当 $\textit{nums}$ 的长度为偶数时，如果 Alice 必败，那么只有一种情况，就是 Alice 无论擦掉哪个数字，剩余所有数字的异或结果都等于 $0$。我们来分析一下是否存在这种情况。

假设数组 $\textit{nums}$ 长度为 $n$，并且 $n$ 是偶数，记所有数字异或结尾为 $S$，则有：

$$
S = \textit{nums}[0] \oplus \textit{nums}[1] \oplus \cdots \oplus \textit{nums}[n-1] \neq 0
$$

我们记 $S_i$ 为数组 $\textit{nums}$ 擦掉第 $i$ 个数字后的异或结果，那么有：

$$
S_i \oplus \textit{nums}[i] = S
$$

等式两边同时异或 $\textit{nums}[i]$，得到：

$$
S_i = S \oplus \textit{nums}[i]
$$

如果无论 Alice 擦掉哪个数字，剩余所有数字的异或结果都等于 $0$，那么对所有 $i$，都有 $S_i = 0$，即：

$$
S_0 \oplus S_1 \oplus \cdots \oplus S_{n-1} = 0
$$

我们将 $S_i = S \oplus \textit{nums}[i]$ 代入上式，得到：

$$
S \oplus \textit{nums}[0] \oplus S \oplus \textit{nums}[1] \oplus \cdots \oplus S \oplus \textit{nums}[n-1] = 0
$$

上式共有 $n$（偶数）个 $S$，而 $\textit{nums}[0] \oplus \textit{nums}[1] \oplus \cdots \oplus \textit{nums}[n-1]$ 也等于 $S$，因此上式等价于 $0 \oplus S = 0$。这与 $S \neq 0$ 矛盾，因此不存在这种情况。因此当 $\textit{nums}$ 的长度为偶数时，Alice 必胜。

如果长度为奇数，那么 Alice 擦掉一个数字后，剩余数字个数为偶数，也就是将偶数长度的情况留给 Bob，那么 Bob 必胜，也即 Alice 必败。

综上，当 $\textit{nums}$ 的长度为偶数，或者 $\textit{nums}$ 中所有数字的异或结果为 $0$ 时，Alice 可以获胜。

时间复杂度 $O(n)$，其中 $n$ 为数组 $\textit{nums}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def xorGame(self, nums: List[int]) -> bool:
        return len(nums) % 2 == 0 or reduce(xor, nums) == 0
```

#### Java

```java
class Solution {
    public boolean xorGame(int[] nums) {
        return nums.length % 2 == 0 || Arrays.stream(nums).reduce(0, (a, b) -> a ^ b) == 0;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool xorGame(vector<int>& nums) {
        if (nums.size() % 2 == 0) return true;
        int x = 0;
        for (int& v : nums) x ^= v;
        return x == 0;
    }
};
```

#### Go

```go
func xorGame(nums []int) bool {
	if len(nums)%2 == 0 {
		return true
	}
	x := 0
	for _, v := range nums {
		x ^= v
	}
	return x == 0
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [811. 子域名访问计数](https://leetcode.cn/problems/subdomain-visit-count){#811}

{{< tabs "811" >}}

{{% tab "python" %}}
```python
class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        cnt = Counter()
        for s in cpdomains:
            v = int(s[: s.index(' ')])
            for i, c in enumerate(s):
                if c in ' .':
                    cnt[s[i + 1 :]] += v
        return [f'{v} {s}' for s, v in cnt.items()]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<String> subdomainVisits(String[] cpdomains) {
        Map<String, Integer> cnt = new HashMap<>();
        for (String s : cpdomains) {
            int i = s.indexOf(" ");
            int v = Integer.parseInt(s.substring(0, i));
            for (; i < s.length(); ++i) {
                if (s.charAt(i) == ' ' || s.charAt(i) == '.') {
                    String t = s.substring(i + 1);
                    cnt.put(t, cnt.getOrDefault(t, 0) + v);
                }
            }
        }
        List<String> ans = new ArrayList<>();
        for (var e : cnt.entrySet()) {
            ans.add(e.getValue() + " " + e.getKey());
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
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> cnt;
        for (auto& s : cpdomains) {
            int i = s.find(' ');
            int v = stoi(s.substr(0, i));
            for (; i < s.size(); ++i) {
                if (s[i] == ' ' || s[i] == '.') {
                    cnt[s.substr(i + 1)] += v;
                }
            }
        }
        vector<string> ans;
        for (auto& [s, v] : cnt) {
            ans.push_back(to_string(v) + " " + s);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func subdomainVisits(cpdomains []string) []string {
	cnt := map[string]int{}
	for _, s := range cpdomains {
		i := strings.IndexByte(s, ' ')
		v, _ := strconv.Atoi(s[:i])
		for ; i < len(s); i++ {
			if s[i] == ' ' || s[i] == '.' {
				cnt[s[i+1:]] += v
			}
		}
	}
	ans := make([]string, 0, len(cnt))
	for s, v := range cnt {
		ans = append(ans, strconv.Itoa(v)+" "+s)
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

<p>网站域名 <code>"discuss.leetcode.com"</code> 由多个子域名组成。顶级域名为 <code>"com"</code> ，二级域名为 <code>"leetcode.com"</code> ，最低一级为 <code>"discuss.leetcode.com"</code> 。当访问域名 <code>"discuss.leetcode.com"</code> 时，同时也会隐式访问其父域名 <code>"leetcode.com" </code>以及 <code>"com"</code> 。</p>

<p><strong>计数配对域名</strong> 是遵循 <code>"rep d1.d2.d3"</code> 或 <code>"rep d1.d2"</code> 格式的一个域名表示，其中 <code>rep</code> 表示访问域名的次数，<code>d1.d2.d3</code> 为域名本身。</p>

<ul>
	<li>例如，<code>"9001 discuss.leetcode.com"</code> 就是一个 <strong>计数配对域名</strong> ，表示 <code>discuss.leetcode.com</code> 被访问了 <code>9001</code> 次。</li>
</ul>

<p>给你一个<strong> 计数配对域名 </strong>组成的数组 <code>cpdomains</code> ，解析得到输入中每个子域名对应的&nbsp;<strong>计数配对域名</strong> ，并以数组形式返回。可以按 <strong>任意顺序</strong> 返回答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>cpdomains = ["9001 discuss.leetcode.com"]
<strong>输出：</strong>["9001 leetcode.com","9001 discuss.leetcode.com","9001 com"]
<strong>解释：</strong>例子中仅包含一个网站域名："discuss.leetcode.com"。
按照前文描述，子域名 "leetcode.com" 和 "com" 都会被访问，所以它们都被访问了 9001 次。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>cpdomains = ["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]
<strong>输出：</strong>["901 mail.com","50 yahoo.com","900 google.mail.com","5 wiki.org","5 org","1 intel.mail.com","951 com"]
<strong>解释：</strong>按照前文描述，会访问 "google.mail.com" 900 次，"yahoo.com" 50 次，"intel.mail.com" 1 次，"wiki.org" 5 次。
而对于父域名，会访问 "mail.com" 900 + 1 = 901 次，"com" 900 + 50 + 1 = 951 次，和 "org" 5 次。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= cpdomain.length &lt;= 100</code></li>
	<li><code>1 &lt;= cpdomain[i].length &lt;= 100</code></li>
	<li><code>cpdomain[i]</code> 会遵循 <code>"rep<sub>i</sub> d1<sub>i</sub>.d2<sub>i</sub>.d3<sub>i</sub>"</code> 或 <code>"rep<sub>i</sub> d1<sub>i</sub>.d2<sub>i</sub>"</code> 格式</li>
	<li><code>rep<sub>i</sub></code> 是范围 <code>[1, 10<sup>4</sup>]</code> 内的一个整数</li>
	<li><code>d1<sub>i</sub></code>、<code>d2<sub>i</sub></code> 和 <code>d3<sub>i</sub></code> 由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们用哈希表 `cnt` 存储每个域名（子域名）对应的访问次数。

然后遍历数组，对于每个域名，我们将其拆分为子域名，然后更新哈希表 `cnt` 中对应的访问次数。

最后，我们将哈希表中的键值对转换为数组，即可得到答案。

时间复杂度 $O(L)$，空间复杂度 $O(L)$。其中 $L$ 是数组 `cpdomains` 中所有域名的长度之和。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        cnt = Counter()
        for s in cpdomains:
            v = int(s[: s.index(' ')])
            for i, c in enumerate(s):
                if c in ' .':
                    cnt[s[i + 1 :]] += v
        return [f'{v} {s}' for s, v in cnt.items()]
```

#### Java

```java
class Solution {
    public List<String> subdomainVisits(String[] cpdomains) {
        Map<String, Integer> cnt = new HashMap<>();
        for (String s : cpdomains) {
            int i = s.indexOf(" ");
            int v = Integer.parseInt(s.substring(0, i));
            for (; i < s.length(); ++i) {
                if (s.charAt(i) == ' ' || s.charAt(i) == '.') {
                    String t = s.substring(i + 1);
                    cnt.put(t, cnt.getOrDefault(t, 0) + v);
                }
            }
        }
        List<String> ans = new ArrayList<>();
        for (var e : cnt.entrySet()) {
            ans.add(e.getValue() + " " + e.getKey());
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> cnt;
        for (auto& s : cpdomains) {
            int i = s.find(' ');
            int v = stoi(s.substr(0, i));
            for (; i < s.size(); ++i) {
                if (s[i] == ' ' || s[i] == '.') {
                    cnt[s.substr(i + 1)] += v;
                }
            }
        }
        vector<string> ans;
        for (auto& [s, v] : cnt) {
            ans.push_back(to_string(v) + " " + s);
        }
        return ans;
    }
};
```

#### Go

```go
func subdomainVisits(cpdomains []string) []string {
	cnt := map[string]int{}
	for _, s := range cpdomains {
		i := strings.IndexByte(s, ' ')
		v, _ := strconv.Atoi(s[:i])
		for ; i < len(s); i++ {
			if s[i] == ' ' || s[i] == '.' {
				cnt[s[i+1:]] += v
			}
		}
	}
	ans := make([]string, 0, len(cnt))
	for s, v := range cnt {
		ans = append(ans, strconv.Itoa(v)+" "+s)
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [812. 最大三角形面积](https://leetcode.cn/problems/largest-triangle-area){#812}

{{< tabs "812" >}}

{{% tab "python" %}}
```python
class Solution:
    def largestTriangleArea(self, points: List[List[int]]) -> float:
        ans = 0
        for x1, y1 in points:
            for x2, y2 in points:
                for x3, y3 in points:
                    u1, v1 = x2 - x1, y2 - y1
                    u2, v2 = x3 - x1, y3 - y1
                    t = abs(u1 * v2 - u2 * v1) / 2
                    ans = max(ans, t)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public double largestTriangleArea(int[][] points) {
        double ans = 0;
        for (int[] p1 : points) {
            int x1 = p1[0], y1 = p1[1];
            for (int[] p2 : points) {
                int x2 = p2[0], y2 = p2[1];
                for (int[] p3 : points) {
                    int x3 = p3[0], y3 = p3[1];
                    int u1 = x2 - x1, v1 = y2 - y1;
                    int u2 = x3 - x1, v2 = y3 - y1;
                    double t = Math.abs(u1 * v2 - u2 * v1) / 2.0;
                    ans = Math.max(ans, t);
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
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0;
        for (auto& p1 : points) {
            int x1 = p1[0], y1 = p1[1];
            for (auto& p2 : points) {
                int x2 = p2[0], y2 = p2[1];
                for (auto& p3 : points) {
                    int x3 = p3[0], y3 = p3[1];
                    int u1 = x2 - x1, v1 = y2 - y1;
                    int u2 = x3 - x1, v2 = y3 - y1;
                    double t = abs(u1 * v2 - u2 * v1) / 2.0;
                    ans = max(ans, t);
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
func largestTriangleArea(points [][]int) float64 {
	ans := 0.0
	for _, p1 := range points {
		x1, y1 := p1[0], p1[1]
		for _, p2 := range points {
			x2, y2 := p2[0], p2[1]
			for _, p3 := range points {
				x3, y3 := p3[0], p3[1]
				u1, v1 := x2-x1, y2-y1
				u2, v2 := x3-x1, y3-y1
				t := float64(abs(u1*v2-u2*v1)) / 2.0
				ans = math.Max(ans, t)
			}
		}
	}
	return ans
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个由 <strong>X-Y</strong> 平面上的点组成的数组 <code>points</code> ，其中 <code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> 。从其中取任意三个不同的点组成三角形，返回能组成的最大三角形的面积。与真实值误差在 <code>10<sup>-5</sup></code> 内的答案将会视为正确答案<strong>。</strong></p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0800-0899/0812.Largest%20Triangle%20Area/images/1027.png" style="height: 369px; width: 450px;" />
<pre>
<strong>输入：</strong>points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
<strong>输出：</strong>2.00000
<strong>解释：</strong>输入中的 5 个点如上图所示，红色的三角形面积最大。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>points = [[1,0],[0,0],[0,1]]
<strong>输出：</strong>0.50000
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= points.length &lt;= 50</code></li>
	<li><code>-50 &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= 50</code></li>
	<li>给出的所有点 <strong>互不相同</strong></li>
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
    def largestTriangleArea(self, points: List[List[int]]) -> float:
        ans = 0
        for x1, y1 in points:
            for x2, y2 in points:
                for x3, y3 in points:
                    u1, v1 = x2 - x1, y2 - y1
                    u2, v2 = x3 - x1, y3 - y1
                    t = abs(u1 * v2 - u2 * v1) / 2
                    ans = max(ans, t)
        return ans
```

#### Java

```java
class Solution {
    public double largestTriangleArea(int[][] points) {
        double ans = 0;
        for (int[] p1 : points) {
            int x1 = p1[0], y1 = p1[1];
            for (int[] p2 : points) {
                int x2 = p2[0], y2 = p2[1];
                for (int[] p3 : points) {
                    int x3 = p3[0], y3 = p3[1];
                    int u1 = x2 - x1, v1 = y2 - y1;
                    int u2 = x3 - x1, v2 = y3 - y1;
                    double t = Math.abs(u1 * v2 - u2 * v1) / 2.0;
                    ans = Math.max(ans, t);
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
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0;
        for (auto& p1 : points) {
            int x1 = p1[0], y1 = p1[1];
            for (auto& p2 : points) {
                int x2 = p2[0], y2 = p2[1];
                for (auto& p3 : points) {
                    int x3 = p3[0], y3 = p3[1];
                    int u1 = x2 - x1, v1 = y2 - y1;
                    int u2 = x3 - x1, v2 = y3 - y1;
                    double t = abs(u1 * v2 - u2 * v1) / 2.0;
                    ans = max(ans, t);
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func largestTriangleArea(points [][]int) float64 {
	ans := 0.0
	for _, p1 := range points {
		x1, y1 := p1[0], p1[1]
		for _, p2 := range points {
			x2, y2 := p2[0], p2[1]
			for _, p3 := range points {
				x3, y3 := p3[0], p3[1]
				u1, v1 := x2-x1, y2-y1
				u2, v2 := x3-x1, y3-y1
				t := float64(abs(u1*v2-u2*v1)) / 2.0
				ans = math.Max(ans, t)
			}
		}
	}
	return ans
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [813. 最大平均值和的分组](https://leetcode.cn/problems/largest-sum-of-averages){#813}

{{< tabs "813" >}}

{{% tab "python" %}}
```python
class Solution:
    def largestSumOfAverages(self, nums: List[int], k: int) -> float:
        n = len(nums)
        f = [[0] * (k + 1) for _ in range(n + 1)]
        s = list(accumulate(nums, initial=0))
        for i in range(1, n + 1):
            f[i][1] = s[i] / i
            for j in range(2, min(i + 1, k + 1)):
                for h in range(i):
                    f[i][j] = max(f[i][j], f[h][j - 1] + (s[i] - s[h]) / (i - h))
        return f[n][k]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public double largestSumOfAverages(int[] nums, int k) {
        int n = nums.length;
        double[][] f = new double[n + 1][k + 1];
        int[] s = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
        for (int i = 1; i <= n; ++i) {
            f[i][1] = s[i] * 1.0 / i;
            for (int j = 2; j <= Math.min(i, k); ++j) {
                for (int h = 0; h < i; ++h) {
                    f[i][j] = Math.max(f[i][j], f[h][j - 1] + (s[i] - s[h]) * 1.0 / (i - h));
                }
            }
        }
        return f[n][k];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        int s[n + 1];
        s[0] = 0;
        double f[n + 1][k + 1];
        memset(f, 0, sizeof(f));
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
        for (int i = 1; i <= n; ++i) {
            f[i][1] = s[i] * 1.0 / i;
            for (int j = 2; j <= min(i, k); ++j) {
                for (int h = 0; h < i; ++h) {
                    f[i][j] = max(f[i][j], f[h][j - 1] + (s[i] - s[h]) * 1.0 / (i - h));
                }
            }
        }
        return f[n][k];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func largestSumOfAverages(nums []int, k int) float64 {
	n := len(nums)
	s := make([]int, n+1)
	for i, x := range nums {
		s[i+1] = s[i] + x
	}
	f := make([][]float64, n+1)
	for i := range f {
		f[i] = make([]float64, k+1)
	}
	for i := 1; i <= n; i++ {
		f[i][1] = float64(s[i]) / float64(i)
		for j := 2; j <= min(i, k); j++ {
			for h := 0; h < i; h++ {
				f[i][j] = max(f[i][j], f[h][j-1]+float64(s[i]-s[h])/float64(i-h))
			}
		}
	}
	return f[n][k]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function largestSumOfAverages(nums: number[], k: number): number {
    const n = nums.length;
    const s: number[] = Array(n + 1).fill(0);
    for (let i = 0; i < n; i++) {
        s[i + 1] = s[i] + nums[i];
    }
    const f: number[][] = Array.from({ length: n + 1 }, () => Array(k + 1).fill(0));
    for (let i = 1; i <= n; ++i) {
        f[i][1] = s[i] / i;
        for (let j = 2; j <= Math.min(i, k); ++j) {
            for (let h = 0; h < i; ++h) {
                f[i][j] = Math.max(f[i][j], f[h][j - 1] + (s[i] - s[h]) / (i - h));
            }
        }
    }
    return f[n][k];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定数组&nbsp;<code>nums</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;。我们将给定的数组&nbsp;<code>nums</code>&nbsp;分成 <strong>最多</strong>&nbsp;<code>k</code>&nbsp;个非空子数组，且数组内部是连续的&nbsp;。&nbsp;<strong>分数</strong> 由每个子数组内的平均值的总和构成。</p>

<p>注意我们必须使用 <code>nums</code> 数组中的每一个数进行分组，并且分数不一定需要是整数。</p>

<p>返回我们所能得到的最大 <strong>分数</strong> 是多少。答案误差在&nbsp;<code>10<sup>-6</sup></code>&nbsp;内被视为是正确的。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> nums = [9,1,2,3,9], k = 3
<strong>输出:</strong> 20.00000
<strong>解释:</strong> 
nums 的最优分组是[9], [1, 2, 3], [9]. 得到的分数是 9 + (1 + 2 + 3) / 3 + 9 = 20. 
我们也可以把 nums 分成[9, 1], [2], [3, 9]. 
这样的分组得到的分数为 5 + 2 + 6 = 13, 但不是最大值.
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> nums = [1,2,3,4,5,6,7], k = 4
<strong>输出:</strong> 20.50000
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= k &lt;= nums.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和 + 记忆化搜索

我们可以先预处理得到前缀和数组 $s$，方便快速得到子数组的和。

接下来，我们设计一个函数 $\textit{dfs}(i, k)$，表示从数组下标 $i$ 开始，最多分成 $k$ 组的最大平均值和。答案为 $\textit{dfs}(0, k)$。

函数 $\textit{dfs}(i, k)$ 的执行逻辑如下：

当 $i = n$ 时，表示已经遍历到数组末尾，此时返回 $0$。

当 $k = 1$ 时，表示只剩下一组，此时返回从下标 $i$ 开始到数组末尾的平均值。

否则，我们在 $[i + 1, n)$ 的区间内枚举下一个分组的开始位置 $j$，计算从 $i$ 到 $j - 1$ 的平均值 $\frac{s[j] - s[i]}{j - i}$，加上 $\textit{dfs}(j, k - 1)$ 的结果，取所有结果的最大值。

时间复杂度 $O(n^2 \times k)$，空间复杂度 $O(n \times k)$。其中 $n$ 表示数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def largestSumOfAverages(self, nums: List[int], k: int) -> float:
        @cache
        def dfs(i: int, k: int) -> float:
            if i == n:
                return 0
            if k == 1:
                return (s[n] - s[i]) / (n - i)
            ans = 0
            for j in range(i + 1, n):
                ans = max(ans, (s[j] - s[i]) / (j - i) + dfs(j, k - 1))
            return ans

        n = len(nums)
        s = list(accumulate(nums, initial=0))
        return dfs(0, k)
```

#### Java

```java
class Solution {
    private Double[][] f;
    private int[] s;
    private int n;

    public double largestSumOfAverages(int[] nums, int k) {
        n = nums.length;
        s = new int[n + 1];
        f = new Double[n][k + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
        return dfs(0, k);
    }

    private double dfs(int i, int k) {
        if (i == n) {
            return 0;
        }
        if (k == 1) {
            return (s[n] - s[i]) * 1.0 / (n - i);
        }
        if (f[i][k] != null) {
            return f[i][k];
        }
        double ans = 0;
        for (int j = i + 1; j < n; ++j) {
            ans = Math.max(ans, (s[j] - s[i]) * 1.0 /(j - i) + dfs(j, k - 1));
        }
        return f[i][k] = ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        int s[n + 1];
        double f[n][k + 1];
        memset(f, 0, sizeof(f));
        s[0] = 0;
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
        auto dfs = [&](this auto&& dfs, int i, int k) -> double {
            if (i == n) {
                return 0;
            }
            if (k == 1) {
                return (s[n] - s[i]) * 1.0 / (n - i);
            }
            if (f[i][k] > 0) {
                return f[i][k];
            }
            double ans = 0;
            for (int j = i + 1; j < n; ++j) {
                ans = max(ans, (s[j] - s[i]) * 1.0 / (j - i) + dfs(j, k - 1));
            }
            return f[i][k] = ans;
        };
        return dfs(0, k);
    }
};
```

#### Go

```go
func largestSumOfAverages(nums []int, k int) float64 {
	n := len(nums)
	s := make([]int, n+1)
	for i, x := range nums {
		s[i+1] = s[i] + x
	}
	f := make([][]float64, n)
	for i := range f {
		f[i] = make([]float64, k+1)
	}
	var dfs func(int, int) float64
	dfs = func(i, k int) float64 {
		if i == n {
			return 0
		}
		if f[i][k] > 0 {
			return f[i][k]
		}
		if k == 1 {
			return float64(s[n]-s[i]) / float64(n-i)
		}
		ans := 0.0
		for j := i + 1; j < n; j++ {
			ans = math.Max(ans, float64(s[j]-s[i])/float64(j-i)+dfs(j, k-1))
		}
		f[i][k] = ans
		return ans
	}
	return dfs(0, k)
}
```

#### TypeScript

```ts
function largestSumOfAverages(nums: number[], k: number): number {
    const n = nums.length;
    const s: number[] = Array(n + 1).fill(0);
    for (let i = 0; i < n; i++) {
        s[i + 1] = s[i] + nums[i];
    }
    const f: number[][] = Array.from({ length: n }, () => Array(k + 1).fill(0));
    const dfs = (i: number, k: number): number => {
        if (i === n) {
            return 0;
        }
        if (f[i][k] > 0) {
            return f[i][k];
        }
        if (k === 1) {
            return (s[n] - s[i]) / (n - i);
        }
        for (let j = i + 1; j < n; j++) {
            f[i][k] = Math.max(f[i][k], dfs(j, k - 1) + (s[j] - s[i]) / (j - i));
        }
        return f[i][k];
    };
    return dfs(0, k);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划

我们可以将方法一的记忆化搜索转化为动态规划。

定义 $f[i][j]$ 表示数组 $\textit{nums}$ 的前 $i$ 个元素最多分成 $j$ 组的最大平均值和。答案为 $f[n][k]$。

对于 $f[i][j]$，我们可以枚举上一组的结束位置 $h$，计算 $f[h][j-1]$，加上 $\frac{s[i]-s[h]}{i-h}$ 的结果，取所有结果的最大值。

时间复杂度 $O(n^2 \times k)$，空间复杂度 $O(n \times k)$。其中 $n$ 表示数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def largestSumOfAverages(self, nums: List[int], k: int) -> float:
        n = len(nums)
        f = [[0] * (k + 1) for _ in range(n + 1)]
        s = list(accumulate(nums, initial=0))
        for i in range(1, n + 1):
            f[i][1] = s[i] / i
            for j in range(2, min(i + 1, k + 1)):
                for h in range(i):
                    f[i][j] = max(f[i][j], f[h][j - 1] + (s[i] - s[h]) / (i - h))
        return f[n][k]
```

#### Java

```java
class Solution {
    public double largestSumOfAverages(int[] nums, int k) {
        int n = nums.length;
        double[][] f = new double[n + 1][k + 1];
        int[] s = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
        for (int i = 1; i <= n; ++i) {
            f[i][1] = s[i] * 1.0 / i;
            for (int j = 2; j <= Math.min(i, k); ++j) {
                for (int h = 0; h < i; ++h) {
                    f[i][j] = Math.max(f[i][j], f[h][j - 1] + (s[i] - s[h]) * 1.0 / (i - h));
                }
            }
        }
        return f[n][k];
    }
}
```

#### C++

```cpp
class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        int s[n + 1];
        s[0] = 0;
        double f[n + 1][k + 1];
        memset(f, 0, sizeof(f));
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
        for (int i = 1; i <= n; ++i) {
            f[i][1] = s[i] * 1.0 / i;
            for (int j = 2; j <= min(i, k); ++j) {
                for (int h = 0; h < i; ++h) {
                    f[i][j] = max(f[i][j], f[h][j - 1] + (s[i] - s[h]) * 1.0 / (i - h));
                }
            }
        }
        return f[n][k];
    }
};
```

#### Go

```go
func largestSumOfAverages(nums []int, k int) float64 {
	n := len(nums)
	s := make([]int, n+1)
	for i, x := range nums {
		s[i+1] = s[i] + x
	}
	f := make([][]float64, n+1)
	for i := range f {
		f[i] = make([]float64, k+1)
	}
	for i := 1; i <= n; i++ {
		f[i][1] = float64(s[i]) / float64(i)
		for j := 2; j <= min(i, k); j++ {
			for h := 0; h < i; h++ {
				f[i][j] = max(f[i][j], f[h][j-1]+float64(s[i]-s[h])/float64(i-h))
			}
		}
	}
	return f[n][k]
}
```

#### TypeScript

```ts
function largestSumOfAverages(nums: number[], k: number): number {
    const n = nums.length;
    const s: number[] = Array(n + 1).fill(0);
    for (let i = 0; i < n; i++) {
        s[i + 1] = s[i] + nums[i];
    }
    const f: number[][] = Array.from({ length: n + 1 }, () => Array(k + 1).fill(0));
    for (let i = 1; i <= n; ++i) {
        f[i][1] = s[i] / i;
        for (let j = 2; j <= Math.min(i, k); ++j) {
            for (let h = 0; h < i; ++h) {
                f[i][j] = Math.max(f[i][j], f[h][j - 1] + (s[i] - s[h]) / (i - h));
            }
        }
    }
    return f[n][k];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [814. 二叉树剪枝](https://leetcode.cn/problems/binary-tree-pruning){#814}

{{< tabs "814" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pruneTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root is None:
            return root
        root.left = self.pruneTree(root.left)
        root.right = self.pruneTree(root.right)
        if root.val == 0 and root.left == root.right:
            return None
        return root
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
    public TreeNode pruneTree(TreeNode root) {
        if (root == null) {
            return null;
        }
        root.left = pruneTree(root.left);
        root.right = pruneTree(root.right);
        if (root.val == 0 && root.left == null && root.right == null) {
            return null;
        }
        return root;
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
    TreeNode* pruneTree(TreeNode* root) {
        if (!root) {
            return root;
        }
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if (root->val == 0 && root->left == root->right) {
            return nullptr;
        }
        return root;
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
func pruneTree(root *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}
	root.Left = pruneTree(root.Left)
	root.Right = pruneTree(root.Right)
	if root.Val == 0 && root.Left == nil && root.Right == nil {
		return nil
	}
	return root
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

function pruneTree(root: TreeNode | null): TreeNode | null {
    if (!root) {
        return root;
    }
    root.left = pruneTree(root.left);
    root.right = pruneTree(root.right);
    if (root.val === 0 && root.left === root.right) {
        return null;
    }
    return root;
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
    pub fn prune_tree(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        if root.is_none() {
            return None;
        }

        let root = root.unwrap();
        let left = Self::prune_tree(root.borrow_mut().left.take());
        let right = Self::prune_tree(root.borrow_mut().right.take());
        if root.borrow().val == 0 && left.is_none() && right.is_none() {
            return None;
        }

        root.borrow_mut().left = left;
        root.borrow_mut().right = right;
        Some(root)
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
 * @return {TreeNode}
 */
var pruneTree = function (root) {
    if (!root) {
        return root;
    }
    root.left = pruneTree(root.left);
    root.right = pruneTree(root.right);
    if (root.val === 0 && root.left === root.right) {
        return null;
    }
    return root;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你二叉树的根结点&nbsp;<code>root</code>&nbsp;，此外树的每个结点的值要么是 <code>0</code> ，要么是 <code>1</code> 。</p>

<p>返回移除了所有不包含 <code>1</code> 的子树的原二叉树。</p>

<p>节点 <code>node</code> 的子树为 <code>node</code> 本身加上所有 <code>node</code> 的后代。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0800-0899/0814.Binary%20Tree%20Pruning/images/1028_2.png" style="width: 500px; height: 140px;" />
<pre>
<strong>输入：</strong>root = [1,null,0,0,1]
<strong>输出：</strong>[1,null,0,null,1]
<strong>解释：</strong>
只有红色节点满足条件“所有不包含 1 的子树”。 右图为返回的答案。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0800-0899/0814.Binary%20Tree%20Pruning/images/1028_1.png" style="width: 500px; height: 115px;" />
<pre>
<strong>输入：</strong>root = [1,0,1,0,0,0,1]
<strong>输出：</strong>[1,null,1,null,1]
</pre>

<p><strong>示例 3：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0800-0899/0814.Binary%20Tree%20Pruning/images/1028.png" style="width: 500px; height: 134px;" />
<pre>
<strong>输入：</strong>root = [1,1,0,1,1,0,1,0]
<strong>输出：</strong>[1,1,0,1,1,null,1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点的数目在范围 <code>[1, 200]</code> 内</li>
	<li><code>Node.val</code> 为 <code>0</code> 或 <code>1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归

我们首先判断当前节点是否为空，如果为空则直接返回空节点。

否则，我们递归地对左右子树进行剪枝，并将剪枝后的左右子树重新赋值给当前节点的左右子节点。然后判断当前节点的值是否为 0 且左右子节点都为空，如果是则返回空节点，否则返回当前节点。

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
    def pruneTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root is None:
            return root
        root.left = self.pruneTree(root.left)
        root.right = self.pruneTree(root.right)
        if root.val == 0 and root.left == root.right:
            return None
        return root
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
    public TreeNode pruneTree(TreeNode root) {
        if (root == null) {
            return null;
        }
        root.left = pruneTree(root.left);
        root.right = pruneTree(root.right);
        if (root.val == 0 && root.left == null && root.right == null) {
            return null;
        }
        return root;
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
    TreeNode* pruneTree(TreeNode* root) {
        if (!root) {
            return root;
        }
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if (root->val == 0 && root->left == root->right) {
            return nullptr;
        }
        return root;
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
func pruneTree(root *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}
	root.Left = pruneTree(root.Left)
	root.Right = pruneTree(root.Right)
	if root.Val == 0 && root.Left == nil && root.Right == nil {
		return nil
	}
	return root
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

function pruneTree(root: TreeNode | null): TreeNode | null {
    if (!root) {
        return root;
    }
    root.left = pruneTree(root.left);
    root.right = pruneTree(root.right);
    if (root.val === 0 && root.left === root.right) {
        return null;
    }
    return root;
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
    pub fn prune_tree(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        if root.is_none() {
            return None;
        }

        let root = root.unwrap();
        let left = Self::prune_tree(root.borrow_mut().left.take());
        let right = Self::prune_tree(root.borrow_mut().right.take());
        if root.borrow().val == 0 && left.is_none() && right.is_none() {
            return None;
        }

        root.borrow_mut().left = left;
        root.borrow_mut().right = right;
        Some(root)
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
 * @return {TreeNode}
 */
var pruneTree = function (root) {
    if (!root) {
        return root;
    }
    root.left = pruneTree(root.left);
    root.right = pruneTree(root.right);
    if (root.val === 0 && root.left === root.right) {
        return null;
    }
    return root;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [815. 公交路线](https://leetcode.cn/problems/bus-routes){#815}

{{< tabs "815" >}}

{{% tab "python" %}}
```python
class Solution:
    def numBusesToDestination(
        self, routes: List[List[int]], source: int, target: int
    ) -> int:
        if source == target:
            return 0
        # 使用 defaultdict 构建站点到公交线路的映射
        g = defaultdict(list)
        for i, route in enumerate(routes):
            for stop in route:
                g[stop].append(i)

        # 如果 source 或 target 不在站点映射中，返回 -1
        if source not in g or target not in g:
            return -1

        # 初始化队列和访问集合
        q = [(source, 0)]
        vis_bus = set()
        vis_stop = {source}

        # 开始广度优先搜索
        for stop, bus_count in q:
            # 如果当前站点是目标站点，返回所需的公交次数
            if stop == target:
                return bus_count

            # 遍历经过当前站点的所有公交线路
            for bus in g[stop]:
                if bus not in vis_bus:
                    vis_bus.add(bus)

                    # 遍历该线路上的所有站点
                    for next_stop in routes[bus]:
                        if next_stop not in vis_stop:
                            vis_stop.add(next_stop)
                            q.append((next_stop, bus_count + 1))
        return -1 # 如果无法到达目标站点，返回 -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numBusesToDestination(int[][] routes, int source, int target) {
        if (source == target) {
            return 0;
        }

        // 使用 HashMap 构建站点到公交线路的映射
        Map<Integer, List<Integer>> g = new HashMap<>();
        for (int i = 0; i < routes.length; i++) {
            for (int stop : routes[i]) {
                g.computeIfAbsent(stop, k -> new ArrayList<>()).add(i);
            }
        }

        // 如果 source 或 target 不在站点映射中，返回 -1
        if (!g.containsKey(source) || !g.containsKey(target)) {
            return -1;
        }

        // 初始化队列和访问集合
        Deque<int[]> q = new ArrayDeque<>();
        Set<Integer> visBus = new HashSet<>();
        Set<Integer> visStop = new HashSet<>();
        q.offer(new int[] {source, 0});
        visStop.add(source);

        // 开始广度优先搜索
        while (!q.isEmpty()) {
            int[] current = q.poll();
            int stop = current[0], busCount = current[1];

            // 如果当前站点是目标站点，返回所需的公交次数
            if (stop == target) {
                return busCount;
            }

            // 遍历经过当前站点的所有公交线路
            for (int bus : g.get(stop)) {
                if (visBus.add(bus)) {
                    // 遍历该线路上的所有站点
                    for (int nextStop : routes[bus]) {
                        if (visStop.add(nextStop)) {
                            q.offer(new int[] {nextStop, busCount + 1});
                        }
                    }
                }
            }
        }

        return -1; // 如果无法到达目标站点，返回 -1
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) {
            return 0;
        }

        // 使用 unordered_map 构建站点到公交线路的映射
        unordered_map<int, vector<int>> g;
        for (int i = 0; i < routes.size(); i++) {
            for (int stop : routes[i]) {
                g[stop].push_back(i);
            }
        }

        // 如果 source 或 target 不在站点映射中，返回 -1
        if (!g.contains(source) || !g.contains(target)) {
            return -1;
        }

        // 初始化队列和访问集合
        queue<pair<int, int>> q;
        unordered_set<int> visBus;
        unordered_set<int> visStop;
        q.push({source, 0});
        visStop.insert(source);

        // 开始广度优先搜索
        while (!q.empty()) {
            auto [stop, busCount] = q.front();
            q.pop();

            // 如果当前站点是目标站点，返回所需的公交次数
            if (stop == target) {
                return busCount;
            }

            // 遍历经过当前站点的所有公交线路
            for (int bus : g[stop]) {
                if (!visBus.contains(bus)) {
                    visBus.insert(bus);
                    // 遍历该线路上的所有站点
                    for (int nextStop : routes[bus]) {
                        if (!visStop.contains(nextStop)) {
                            visStop.insert(nextStop);
                            q.push({nextStop, busCount + 1});
                        }
                    }
                }
            }
        }

        return -1; // 如果无法到达目标站点，返回 -1
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numBusesToDestination(routes [][]int, source int, target int) int {
	if source == target {
		return 0
	}

	// 使用 map 构建站点到公交线路的映射
	g := make(map[int][]int)
	for i, route := range routes {
		for _, stop := range route {
			g[stop] = append(g[stop], i)
		}
	}

	// 如果 source 或 target 不在站点映射中，返回 -1
	if g[source] == nil || g[target] == nil {
		return -1
	}

	// 初始化队列和访问集合
	q := list.New()
	q.PushBack([2]int{source, 0})
	visBus := make(map[int]bool)
	visStop := make(map[int]bool)
	visStop[source] = true

	// 开始广度优先搜索
	for q.Len() > 0 {
		front := q.Front()
		q.Remove(front)
		stop, busCount := front.Value.([2]int)[0], front.Value.([2]int)[1]

		// 如果当前站点是目标站点，返回所需的公交次数
		if stop == target {
			return busCount
		}

		// 遍历经过当前站点的所有公交线路
		for _, bus := range g[stop] {
			if !visBus[bus] {
				visBus[bus] = true
				// 遍历该线路上的所有站点
				for _, nextStop := range routes[bus] {
					if !visStop[nextStop] {
						visStop[nextStop] = true
						q.PushBack([2]int{nextStop, busCount + 1})
					}
				}
			}
		}
	}

	return -1 // 如果无法到达目标站点，返回
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numBusesToDestination(routes: number[][], source: number, target: number): number {
    if (source === target) {
        return 0;
    }

    // 使用 Map 构建站点到公交线路的映射
    const g: Map<number, number[]> = new Map();
    for (let i = 0; i < routes.length; i++) {
        for (const stop of routes[i]) {
            if (!g.has(stop)) {
                g.set(stop, []);
            }
            g.get(stop)!.push(i);
        }
    }

    // 如果 source 或 target 不在站点映射中，返回 -1
    if (!g.has(source) || !g.has(target)) {
        return -1;
    }

    // 初始化队列和访问集合
    const q: [number, number][] = [[source, 0]];
    const visBus: Set<number> = new Set();
    const visStop: Set<number> = new Set([source]);

    // 开始广度优先搜索
    for (const [stop, busCount] of q) {
        // 如果当前站点是目标站点，返回所需的公交次数
        if (stop === target) {
            return busCount;
        }

        // 遍历经过当前站点的所有公交线路
        for (const bus of g.get(stop)!) {
            if (!visBus.has(bus)) {
                visBus.add(bus);
                // 遍历该线路上的所有站点
                for (const nextStop of routes[bus]) {
                    if (!visStop.has(nextStop)) {
                        visStop.add(nextStop);
                        q.push([nextStop, busCount + 1]);
                    }
                }
            }
        }
    }

    return -1; // 如果无法到达目标站点，返回 -1
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int NumBusesToDestination(int[][] routes, int source, int target) {
        if (source == target) {
            return 0; // 如果起点和终点相同，直接返回 0
        }

        // 使用 Dictionary 构建站点到公交线路的映射
        var g = new Dictionary<int, List<int>>();
        for (int i = 0; i < routes.Length; i++) {
            foreach (int stop in routes[i]) {
                if (!g.ContainsKey(stop)) {
                    g[stop] = new List<int>();
                }
                g[stop].Add(i); // 将公交线路编号添加到该站点的列表中
            }
        }

        // 如果 source 或 target 不在站点映射中，返回 -1
        if (!g.ContainsKey(source) || !g.ContainsKey(target)) {
            return -1;
        }

        // 初始化队列和访问集合
        var q = new Queue<int[]>();
        var visBus = new HashSet<int>(); // 记录访问过的公交线路
        var visStop = new HashSet<int>(); // 记录访问过的站点
        q.Enqueue(new int[] { source, 0 }); // 将起点加入队列，公交次数初始化为 0
        visStop.Add(source); // 将起点标记为已访问

        // 开始广度优先搜索
        while (q.Count > 0) {
            var current = q.Dequeue(); // 从队列中取出当前站点
            int stop = current[0], busCount = current[1];

            // 如果当前站点是目标站点，返回所需的公交次数
            if (stop == target) {
                return busCount;
            }

            // 遍历经过当前站点的所有公交线路
            foreach (int bus in g[stop]) {
                if (visBus.Add(bus)) { // 如果公交线路没有被访问过
                    // 遍历该线路上的所有站点
                    foreach (int nextStop in routes[bus]) {
                        if (visStop.Add(nextStop)) { // 如果该站点没有被访问过
                            q.Enqueue(new int[] { nextStop, busCount + 1 }); // 将新站点加入队列，公交次数加 1
                        }
                    }
                }
            }
        }

        return -1; // 如果无法到达目标站点，返回 -1
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个数组 <code>routes</code> ，表示一系列公交线路，其中每个 <code>routes[i]</code> 表示一条公交线路，第 <code>i</code> 辆公交车将会在上面循环行驶。</p>

<ul>
	<li>例如，路线 <code>routes[0] = [1, 5, 7]</code> 表示第 <code>0</code> 辆公交车会一直按序列 <code>1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ...</code> 这样的车站路线行驶。</li>
</ul>

<p>现在从 <code>source</code> 车站出发（初始时不在公交车上），要前往 <code>target</code> 车站。 期间仅可乘坐公交车。</p>

<p>求出 <strong>最少乘坐的公交车数量</strong> 。如果不可能到达终点车站，返回 <code>-1</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>routes = [[1,2,7],[3,6,7]], source = 1, target = 6
<strong>输出：</strong>2
<strong>解释：</strong>最优策略是先乘坐第一辆公交车到达车站 7 , 然后换乘第二辆公交车到车站 6 。 
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12
<strong>输出：</strong>-1
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= routes.length <= 500</code>.</li>
	<li><code>1 <= routes[i].length <= 10<sup>5</sup></code></li>
	<li><code>routes[i]</code> 中的所有值 <strong>互不相同</strong></li>
	<li><code>sum(routes[i].length) <= 10<sup>5</sup></code></li>
	<li><code>0 <= routes[i][j] < 10<sup>6</sup></code></li>
	<li><code>0 <= source, target < 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS

我们首先判断 $\textit{source}$ 和 $\textit{target}$ 是否相同，如果相同则直接返回 $0$。

然后我们使用一个哈希表 $\textit{g}$ 来构建站点到公交线路的映射。对于每一条公交线路，我们遍历其经过的所有站点，将每个站点映射到该公交线路，即 $\textit{g}[\textit{stop}]$ 为经过站点 $\textit{stop}$ 的所有公交线路。

接着我们判断 $\textit{source}$ 和 $\textit{target}$ 是否在站点映射中，如果不在则返回 $-1$。

我们使用一个队列 $\textit{q}$ 来进行广度优先搜索，队列中的每个元素为一个二元组 $(\textit{stop}, \textit{busCount})$，表示当前站点 $\textit{stop}$ 和到达当前站点所需的公交次数 $\textit{busCount}$。

我们初始化一个集合 $\textit{visBus}$ 来记录已经访问过的公交线路，一个集合 $\textit{visStop}$ 来记录已经访问过的站点。然后我们将 $\textit{source}$ 加入到 $\textit{visStop}$ 中，并将 $(\textit{source}, 0)$ 加入到队列 $\textit{q}$ 中。

接下来我们开始广度优先搜索，当队列 $\textit{q}$ 不为空时，我们取出队列的第一个元素，即当前站点 $\textit{stop}$ 和到达当前站点所需的公交次数 $\textit{busCount}$。

如果当前站点 $\textit{stop}$ 是目标站点 $\textit{target}$，我们返回到达目标站点所需的公交次数 $\textit{busCount}$。

否则，我们遍历经过当前站点的所有公交线路，对于每一条公交线路，我们遍历该线路上的所有站点，如果某个站点 $\textit{nextStop}$ 没有被访问过，则将其加入到 $\textit{visStop}$ 中，并将 $(\textit{nextStop}, \textit{busCount} + 1)$ 加入到队列 $\textit{q}$ 中。

最后，如果无法到达目标站点，则返回 $-1$。

时间复杂度 $O(L)$，空间复杂度 $O(L)$，其中 $L$ 为所有公交线路上的站点总数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numBusesToDestination(
        self, routes: List[List[int]], source: int, target: int
    ) -> int:
        if source == target:
            return 0
        # 使用 defaultdict 构建站点到公交线路的映射
        g = defaultdict(list)
        for i, route in enumerate(routes):
            for stop in route:
                g[stop].append(i)

        # 如果 source 或 target 不在站点映射中，返回 -1
        if source not in g or target not in g:
            return -1

        # 初始化队列和访问集合
        q = [(source, 0)]
        vis_bus = set()
        vis_stop = {source}

        # 开始广度优先搜索
        for stop, bus_count in q:
            # 如果当前站点是目标站点，返回所需的公交次数
            if stop == target:
                return bus_count

            # 遍历经过当前站点的所有公交线路
            for bus in g[stop]:
                if bus not in vis_bus:
                    vis_bus.add(bus)

                    # 遍历该线路上的所有站点
                    for next_stop in routes[bus]:
                        if next_stop not in vis_stop:
                            vis_stop.add(next_stop)
                            q.append((next_stop, bus_count + 1))
        return -1 # 如果无法到达目标站点，返回 -1
```

#### Java

```java
class Solution {
    public int numBusesToDestination(int[][] routes, int source, int target) {
        if (source == target) {
            return 0;
        }

        // 使用 HashMap 构建站点到公交线路的映射
        Map<Integer, List<Integer>> g = new HashMap<>();
        for (int i = 0; i < routes.length; i++) {
            for (int stop : routes[i]) {
                g.computeIfAbsent(stop, k -> new ArrayList<>()).add(i);
            }
        }

        // 如果 source 或 target 不在站点映射中，返回 -1
        if (!g.containsKey(source) || !g.containsKey(target)) {
            return -1;
        }

        // 初始化队列和访问集合
        Deque<int[]> q = new ArrayDeque<>();
        Set<Integer> visBus = new HashSet<>();
        Set<Integer> visStop = new HashSet<>();
        q.offer(new int[] {source, 0});
        visStop.add(source);

        // 开始广度优先搜索
        while (!q.isEmpty()) {
            int[] current = q.poll();
            int stop = current[0], busCount = current[1];

            // 如果当前站点是目标站点，返回所需的公交次数
            if (stop == target) {
                return busCount;
            }

            // 遍历经过当前站点的所有公交线路
            for (int bus : g.get(stop)) {
                if (visBus.add(bus)) {
                    // 遍历该线路上的所有站点
                    for (int nextStop : routes[bus]) {
                        if (visStop.add(nextStop)) {
                            q.offer(new int[] {nextStop, busCount + 1});
                        }
                    }
                }
            }
        }

        return -1; // 如果无法到达目标站点，返回 -1
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) {
            return 0;
        }

        // 使用 unordered_map 构建站点到公交线路的映射
        unordered_map<int, vector<int>> g;
        for (int i = 0; i < routes.size(); i++) {
            for (int stop : routes[i]) {
                g[stop].push_back(i);
            }
        }

        // 如果 source 或 target 不在站点映射中，返回 -1
        if (!g.contains(source) || !g.contains(target)) {
            return -1;
        }

        // 初始化队列和访问集合
        queue<pair<int, int>> q;
        unordered_set<int> visBus;
        unordered_set<int> visStop;
        q.push({source, 0});
        visStop.insert(source);

        // 开始广度优先搜索
        while (!q.empty()) {
            auto [stop, busCount] = q.front();
            q.pop();

            // 如果当前站点是目标站点，返回所需的公交次数
            if (stop == target) {
                return busCount;
            }

            // 遍历经过当前站点的所有公交线路
            for (int bus : g[stop]) {
                if (!visBus.contains(bus)) {
                    visBus.insert(bus);
                    // 遍历该线路上的所有站点
                    for (int nextStop : routes[bus]) {
                        if (!visStop.contains(nextStop)) {
                            visStop.insert(nextStop);
                            q.push({nextStop, busCount + 1});
                        }
                    }
                }
            }
        }

        return -1; // 如果无法到达目标站点，返回 -1
    }
};
```

#### Go

```go
func numBusesToDestination(routes [][]int, source int, target int) int {
	if source == target {
		return 0
	}

	// 使用 map 构建站点到公交线路的映射
	g := make(map[int][]int)
	for i, route := range routes {
		for _, stop := range route {
			g[stop] = append(g[stop], i)
		}
	}

	// 如果 source 或 target 不在站点映射中，返回 -1
	if g[source] == nil || g[target] == nil {
		return -1
	}

	// 初始化队列和访问集合
	q := list.New()
	q.PushBack([2]int{source, 0})
	visBus := make(map[int]bool)
	visStop := make(map[int]bool)
	visStop[source] = true

	// 开始广度优先搜索
	for q.Len() > 0 {
		front := q.Front()
		q.Remove(front)
		stop, busCount := front.Value.([2]int)[0], front.Value.([2]int)[1]

		// 如果当前站点是目标站点，返回所需的公交次数
		if stop == target {
			return busCount
		}

		// 遍历经过当前站点的所有公交线路
		for _, bus := range g[stop] {
			if !visBus[bus] {
				visBus[bus] = true
				// 遍历该线路上的所有站点
				for _, nextStop := range routes[bus] {
					if !visStop[nextStop] {
						visStop[nextStop] = true
						q.PushBack([2]int{nextStop, busCount + 1})
					}
				}
			}
		}
	}

	return -1 // 如果无法到达目标站点，返回
}
```

#### TypeScript

```ts
function numBusesToDestination(routes: number[][], source: number, target: number): number {
    if (source === target) {
        return 0;
    }

    // 使用 Map 构建站点到公交线路的映射
    const g: Map<number, number[]> = new Map();
    for (let i = 0; i < routes.length; i++) {
        for (const stop of routes[i]) {
            if (!g.has(stop)) {
                g.set(stop, []);
            }
            g.get(stop)!.push(i);
        }
    }

    // 如果 source 或 target 不在站点映射中，返回 -1
    if (!g.has(source) || !g.has(target)) {
        return -1;
    }

    // 初始化队列和访问集合
    const q: [number, number][] = [[source, 0]];
    const visBus: Set<number> = new Set();
    const visStop: Set<number> = new Set([source]);

    // 开始广度优先搜索
    for (const [stop, busCount] of q) {
        // 如果当前站点是目标站点，返回所需的公交次数
        if (stop === target) {
            return busCount;
        }

        // 遍历经过当前站点的所有公交线路
        for (const bus of g.get(stop)!) {
            if (!visBus.has(bus)) {
                visBus.add(bus);
                // 遍历该线路上的所有站点
                for (const nextStop of routes[bus]) {
                    if (!visStop.has(nextStop)) {
                        visStop.add(nextStop);
                        q.push([nextStop, busCount + 1]);
                    }
                }
            }
        }
    }

    return -1; // 如果无法到达目标站点，返回 -1
}
```

#### C#

```cs
public class Solution {
    public int NumBusesToDestination(int[][] routes, int source, int target) {
        if (source == target) {
            return 0; // 如果起点和终点相同，直接返回 0
        }

        // 使用 Dictionary 构建站点到公交线路的映射
        var g = new Dictionary<int, List<int>>();
        for (int i = 0; i < routes.Length; i++) {
            foreach (int stop in routes[i]) {
                if (!g.ContainsKey(stop)) {
                    g[stop] = new List<int>();
                }
                g[stop].Add(i); // 将公交线路编号添加到该站点的列表中
            }
        }

        // 如果 source 或 target 不在站点映射中，返回 -1
        if (!g.ContainsKey(source) || !g.ContainsKey(target)) {
            return -1;
        }

        // 初始化队列和访问集合
        var q = new Queue<int[]>();
        var visBus = new HashSet<int>(); // 记录访问过的公交线路
        var visStop = new HashSet<int>(); // 记录访问过的站点
        q.Enqueue(new int[] { source, 0 }); // 将起点加入队列，公交次数初始化为 0
        visStop.Add(source); // 将起点标记为已访问

        // 开始广度优先搜索
        while (q.Count > 0) {
            var current = q.Dequeue(); // 从队列中取出当前站点
            int stop = current[0], busCount = current[1];

            // 如果当前站点是目标站点，返回所需的公交次数
            if (stop == target) {
                return busCount;
            }

            // 遍历经过当前站点的所有公交线路
            foreach (int bus in g[stop]) {
                if (visBus.Add(bus)) { // 如果公交线路没有被访问过
                    // 遍历该线路上的所有站点
                    foreach (int nextStop in routes[bus]) {
                        if (visStop.Add(nextStop)) { // 如果该站点没有被访问过
                            q.Enqueue(new int[] { nextStop, busCount + 1 }); // 将新站点加入队列，公交次数加 1
                        }
                    }
                }
            }
        }

        return -1; // 如果无法到达目标站点，返回 -1
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [816. 模糊坐标](https://leetcode.cn/problems/ambiguous-coordinates){#816}

{{< tabs "816" >}}

{{% tab "python" %}}
```python
class Solution:
    def ambiguousCoordinates(self, s: str) -> List[str]:
        def f(i, j):
            res = []
            for k in range(1, j - i + 1):
                l, r = s[i : i + k], s[i + k : j]
                ok = (l == '0' or not l.startswith('0')) and not r.endswith('0')
                if ok:
                    res.append(l + ('.' if k < j - i else '') + r)
            return res

        n = len(s)
        return [
            f'({x}, {y})' for i in range(2, n - 1) for x in f(1, i) for y in f(i, n - 1)
        ]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<String> ambiguousCoordinates(String s) {
        int n = s.length();
        List<String> ans = new ArrayList<>();
        for (int i = 2; i < n - 1; ++i) {
            for (String x : f(s, 1, i)) {
                for (String y : f(s, i, n - 1)) {
                    ans.add(String.format("(%s, %s)", x, y));
                }
            }
        }
        return ans;
    }

    private List<String> f(String s, int i, int j) {
        List<String> res = new ArrayList<>();
        for (int k = 1; k <= j - i; ++k) {
            String l = s.substring(i, i + k);
            String r = s.substring(i + k, j);
            boolean ok = ("0".equals(l) || !l.startsWith("0")) && !r.endsWith("0");
            if (ok) {
                res.add(l + (k < j - i ? "." : "") + r);
            }
        }
        return res;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        int n = s.size();
        vector<string> ans;
        auto f = [&](int i, int j) {
            vector<string> res;
            for (int k = 1; k <= j - i; ++k) {
                string l = s.substr(i, k);
                string r = s.substr(i + k, j - i - k);
                bool ok = (l == "0" || l[0] != '0') && r.back() != '0';
                if (ok) {
                    res.push_back(l + (k < j - i ? "." : "") + r);
                }
            }
            return res;
        };
        for (int i = 2; i < n - 1; ++i) {
            for (auto& x : f(1, i)) {
                for (auto& y : f(i, n - 1)) {
                    ans.emplace_back("(" + x + ", " + y + ")");
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
func ambiguousCoordinates(s string) []string {
	f := func(i, j int) []string {
		res := []string{}
		for k := 1; k <= j-i; k++ {
			l, r := s[i:i+k], s[i+k:j]
			ok := (l == "0" || l[0] != '0') && (r == "" || r[len(r)-1] != '0')
			if ok {
				t := ""
				if k < j-i {
					t = "."
				}
				res = append(res, l+t+r)
			}
		}
		return res
	}

	n := len(s)
	ans := []string{}
	for i := 2; i < n-1; i++ {
		for _, x := range f(1, i) {
			for _, y := range f(i, n-1) {
				ans = append(ans, "("+x+", "+y+")")
			}
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function ambiguousCoordinates(s: string): string[] {
    s = s.slice(1, s.length - 1);
    const n = s.length;
    const dfs = (s: string) => {
        const res: string[] = [];
        for (let i = 1; i < s.length; i++) {
            const t = `${s.slice(0, i)}.${s.slice(i)}`;
            if (`${Number(t)}` === t) {
                res.push(t);
            }
        }
        if (`${Number(s)}` === s) {
            res.push(s);
        }
        return res;
    };
    const ans: string[] = [];
    for (let i = 1; i < n; i++) {
        for (const left of dfs(s.slice(0, i))) {
            for (const right of dfs(s.slice(i))) {
                ans.push(`(${left}, ${right})`);
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

<p>我们有一些二维坐标，如&nbsp;<code>&quot;(1, 3)&quot;</code>&nbsp;或&nbsp;<code>&quot;(2, 0.5)&quot;</code>，然后我们移除所有逗号，小数点和空格，得到一个字符串<code>S</code>。返回所有可能的原始字符串到一个列表中。</p>

<p>原始的坐标表示法不会存在多余的零，所以不会出现类似于&quot;00&quot;, &quot;0.0&quot;, &quot;0.00&quot;, &quot;1.0&quot;, &quot;001&quot;, &quot;00.01&quot;或一些其他更小的数来表示坐标。此外，一个小数点前至少存在一个数，所以也不会出现&ldquo;.1&rdquo;形式的数字。</p>

<p>最后返回的列表可以是任意顺序的。而且注意返回的两个数字中间（逗号之后）都有一个空格。</p>

<p>&nbsp;</p>

<pre>
<strong>示例 1:</strong>
<strong>输入:</strong> &quot;(123)&quot;
<strong>输出:</strong> [&quot;(1, 23)&quot;, &quot;(12, 3)&quot;, &quot;(1.2, 3)&quot;, &quot;(1, 2.3)&quot;]
</pre>

<pre>
<strong>示例 2:</strong>
<strong>输入:</strong> &quot;(00011)&quot;
<strong>输出:</strong> &nbsp;[&quot;(0.001, 1)&quot;, &quot;(0, 0.011)&quot;]
<strong>解释:</strong> 
0.0, 00, 0001 或 00.01 是不被允许的。
</pre>

<pre>
<strong>示例 3:</strong>
<strong>输入:</strong> &quot;(0123)&quot;
<strong>输出:</strong> [&quot;(0, 123)&quot;, &quot;(0, 12.3)&quot;, &quot;(0, 1.23)&quot;, &quot;(0.1, 23)&quot;, &quot;(0.1, 2.3)&quot;, &quot;(0.12, 3)&quot;]
</pre>

<pre>
<strong>示例 4:</strong>
<strong>输入:</strong> &quot;(100)&quot;
<strong>输出:</strong> [(10, 0)]
<strong>解释:</strong> 
1.0 是不被允许的。
</pre>

<p>&nbsp;</p>

<p><strong>提示: </strong></p>

<ul>
	<li><code>4 &lt;= S.length &lt;= 12</code>.</li>
	<li><code>S[0]</code> = &quot;(&quot;, <code>S[S.length - 1]</code> = &quot;)&quot;, 且字符串&nbsp;<code>S</code>&nbsp;中的其他元素都是数字。</li>
</ul>

<p>&nbsp;</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：暴力模拟

枚举纵坐标的起始位置，然后分别获取横、纵坐标的所有可能的表示形式，最后将横、纵坐标的所有可能的表示形式组合起来。

我们将一个坐标值 $x$ 或 $y$ 按照小数点的位置分成左右两部分，那么两部分应该满足以下条件：

1. 左半部分不能以 0 开头，除非左半部分只有 0；
2. 右半部分不能以 0 结尾。

时间复杂度 $O(n^3)$，其中 $n$ 为字符串 $S$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def ambiguousCoordinates(self, s: str) -> List[str]:
        def f(i, j):
            res = []
            for k in range(1, j - i + 1):
                l, r = s[i : i + k], s[i + k : j]
                ok = (l == '0' or not l.startswith('0')) and not r.endswith('0')
                if ok:
                    res.append(l + ('.' if k < j - i else '') + r)
            return res

        n = len(s)
        return [
            f'({x}, {y})' for i in range(2, n - 1) for x in f(1, i) for y in f(i, n - 1)
        ]
```

#### Java

```java
class Solution {
    public List<String> ambiguousCoordinates(String s) {
        int n = s.length();
        List<String> ans = new ArrayList<>();
        for (int i = 2; i < n - 1; ++i) {
            for (String x : f(s, 1, i)) {
                for (String y : f(s, i, n - 1)) {
                    ans.add(String.format("(%s, %s)", x, y));
                }
            }
        }
        return ans;
    }

    private List<String> f(String s, int i, int j) {
        List<String> res = new ArrayList<>();
        for (int k = 1; k <= j - i; ++k) {
            String l = s.substring(i, i + k);
            String r = s.substring(i + k, j);
            boolean ok = ("0".equals(l) || !l.startsWith("0")) && !r.endsWith("0");
            if (ok) {
                res.add(l + (k < j - i ? "." : "") + r);
            }
        }
        return res;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        int n = s.size();
        vector<string> ans;
        auto f = [&](int i, int j) {
            vector<string> res;
            for (int k = 1; k <= j - i; ++k) {
                string l = s.substr(i, k);
                string r = s.substr(i + k, j - i - k);
                bool ok = (l == "0" || l[0] != '0') && r.back() != '0';
                if (ok) {
                    res.push_back(l + (k < j - i ? "." : "") + r);
                }
            }
            return res;
        };
        for (int i = 2; i < n - 1; ++i) {
            for (auto& x : f(1, i)) {
                for (auto& y : f(i, n - 1)) {
                    ans.emplace_back("(" + x + ", " + y + ")");
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func ambiguousCoordinates(s string) []string {
	f := func(i, j int) []string {
		res := []string{}
		for k := 1; k <= j-i; k++ {
			l, r := s[i:i+k], s[i+k:j]
			ok := (l == "0" || l[0] != '0') && (r == "" || r[len(r)-1] != '0')
			if ok {
				t := ""
				if k < j-i {
					t = "."
				}
				res = append(res, l+t+r)
			}
		}
		return res
	}

	n := len(s)
	ans := []string{}
	for i := 2; i < n-1; i++ {
		for _, x := range f(1, i) {
			for _, y := range f(i, n-1) {
				ans = append(ans, "("+x+", "+y+")")
			}
		}
	}
	return ans
}
```

#### TypeScript

```ts
function ambiguousCoordinates(s: string): string[] {
    s = s.slice(1, s.length - 1);
    const n = s.length;
    const dfs = (s: string) => {
        const res: string[] = [];
        for (let i = 1; i < s.length; i++) {
            const t = `${s.slice(0, i)}.${s.slice(i)}`;
            if (`${Number(t)}` === t) {
                res.push(t);
            }
        }
        if (`${Number(s)}` === s) {
            res.push(s);
        }
        return res;
    };
    const ans: string[] = [];
    for (let i = 1; i < n; i++) {
        for (const left of dfs(s.slice(0, i))) {
            for (const right of dfs(s.slice(i))) {
                ans.push(`(${left}, ${right})`);
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

# [817. 链表组件](https://leetcode.cn/problems/linked-list-components){#817}

{{< tabs "817" >}}

{{% tab "python" %}}
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def numComponents(self, head: Optional[ListNode], nums: List[int]) -> int:
        ans = 0
        s = set(nums)
        while head:
            while head and head.val not in s:
                head = head.next
            ans += head is not None
            while head and head.val in s:
                head = head.next
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int numComponents(ListNode head, int[] nums) {
        int ans = 0;
        Set<Integer> s = new HashSet<>();
        for (int v : nums) {
            s.add(v);
        }
        while (head != null) {
            while (head != null && !s.contains(head.val)) {
                head = head.next;
            }
            ans += head != null ? 1 : 0;
            while (head != null && s.contains(head.val)) {
                head = head.next;
            }
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;
        while (head) {
            while (head && !s.count(head->val)) head = head->next;
            ans += head != nullptr;
            while (head && s.count(head->val)) head = head->next;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func numComponents(head *ListNode, nums []int) int {
	s := map[int]bool{}
	for _, v := range nums {
		s[v] = true
	}
	ans := 0
	for head != nil {
		for head != nil && !s[head.Val] {
			head = head.Next
		}
		if head != nil {
			ans++
		}
		for head != nil && s[head.Val] {
			head = head.Next
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function numComponents(head: ListNode | null, nums: number[]): number {
    const set = new Set<number>(nums);
    let res = 0;
    let cur = head;
    let inSet = false;
    while (cur != null) {
        if (set.has(cur.val)) {
            if (!inSet) {
                inSet = true;
                res++;
            }
        } else {
            inSet = false;
        }
        cur = cur.next;
    }
    return res;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
use std::collections::HashSet;
impl Solution {
    pub fn num_components(head: Option<Box<ListNode>>, nums: Vec<i32>) -> i32 {
        let set = nums.into_iter().collect::<HashSet<i32>>();
        let mut res = 0;
        let mut in_set = false;
        let mut cur = &head;
        while let Some(node) = cur {
            if set.contains(&node.val) {
                if !in_set {
                    in_set = true;
                    res += 1;
                }
            } else {
                in_set = false;
            }
            cur = &node.next;
        }
        res
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number[]} nums
 * @return {number}
 */
var numComponents = function (head, nums) {
    const s = new Set(nums);
    let ans = 0;
    while (head) {
        while (head && !s.has(head.val)) {
            head = head.next;
        }
        ans += head != null;
        while (head && s.has(head.val)) {
            head = head.next;
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

<p>给定链表头结点&nbsp;<code>head</code>，该链表上的每个结点都有一个 <strong>唯一的整型值</strong> 。同时给定列表&nbsp;<code>nums</code>，该列表是上述链表中整型值的一个子集。</p>

<p>返回列表&nbsp;<code>nums</code>&nbsp;中组件的个数，这里对组件的定义为：链表中一段最长连续结点的值（该值必须在列表&nbsp;<code>nums</code>&nbsp;中）构成的集合。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0800-0899/0817.Linked%20List%20Components/images/lc-linkedlistcom1.jpg" /></p>

<pre>
<strong>输入:</strong> head = [0,1,2,3], nums = [0,1,3]
<strong>输出:</strong> 2
<strong>解释:</strong> 链表中,0 和 1 是相连接的，且 nums 中不包含 2，所以 [0, 1] 是 nums 的一个组件，同理 [3] 也是一个组件，故返回 2。</pre>

<p><strong>示例 2：</strong></p>

<p><strong>&nbsp;</strong><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0800-0899/0817.Linked%20List%20Components/images/lc-linkedlistcom2.jpg" /></p>

<pre>
<strong>输入:</strong> head = [0,1,2,3,4], nums = [0,3,1,4]
<strong>输出:</strong> 2
<strong>解释:</strong> 链表中，0 和 1 是相连接的，3 和 4 是相连接的，所以 [0, 1] 和 [3, 4] 是两个组件，故返回 2。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表中节点数为<code>n</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= Node.val &lt; n</code></li>
	<li><code>Node.val</code>&nbsp;中所有值 <strong>不同</strong></li>
	<li><code>1 &lt;= nums.length &lt;= n</code></li>
	<li><code>0 &lt;= nums[i] &lt; n</code></li>
	<li><code>nums</code> 中所有值 <strong>不同</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 链表一次遍历

题目中需要判断链表中节点的值是否在数组 `nums` 中，因此我们可以使用哈希表 $s$ 存储数组 `nums` 中的值。

然后遍历链表，找到第一个在哈希表 $s$ 中的节点，然后从该节点开始遍历，直到遇到不在哈希表 $s$ 中的节点，这样就找到了一个组件，然后继续遍历链表，直到遍历完整个链表。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为链表的节点个数。

<!-- tabs:start -->

#### Python3

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def numComponents(self, head: Optional[ListNode], nums: List[int]) -> int:
        ans = 0
        s = set(nums)
        while head:
            while head and head.val not in s:
                head = head.next
            ans += head is not None
            while head and head.val in s:
                head = head.next
        return ans
```

#### Java

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int numComponents(ListNode head, int[] nums) {
        int ans = 0;
        Set<Integer> s = new HashSet<>();
        for (int v : nums) {
            s.add(v);
        }
        while (head != null) {
            while (head != null && !s.contains(head.val)) {
                head = head.next;
            }
            ans += head != null ? 1 : 0;
            while (head != null && s.contains(head.val)) {
                head = head.next;
            }
        }
        return ans;
    }
}
```

#### C++

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;
        while (head) {
            while (head && !s.count(head->val)) head = head->next;
            ans += head != nullptr;
            while (head && s.count(head->val)) head = head->next;
        }
        return ans;
    }
};
```

#### Go

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func numComponents(head *ListNode, nums []int) int {
	s := map[int]bool{}
	for _, v := range nums {
		s[v] = true
	}
	ans := 0
	for head != nil {
		for head != nil && !s[head.Val] {
			head = head.Next
		}
		if head != nil {
			ans++
		}
		for head != nil && s[head.Val] {
			head = head.Next
		}
	}
	return ans
}
```

#### TypeScript

```ts
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function numComponents(head: ListNode | null, nums: number[]): number {
    const set = new Set<number>(nums);
    let res = 0;
    let cur = head;
    let inSet = false;
    while (cur != null) {
        if (set.has(cur.val)) {
            if (!inSet) {
                inSet = true;
                res++;
            }
        } else {
            inSet = false;
        }
        cur = cur.next;
    }
    return res;
}
```

#### Rust

```rust
// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
use std::collections::HashSet;
impl Solution {
    pub fn num_components(head: Option<Box<ListNode>>, nums: Vec<i32>) -> i32 {
        let set = nums.into_iter().collect::<HashSet<i32>>();
        let mut res = 0;
        let mut in_set = false;
        let mut cur = &head;
        while let Some(node) = cur {
            if set.contains(&node.val) {
                if !in_set {
                    in_set = true;
                    res += 1;
                }
            } else {
                in_set = false;
            }
            cur = &node.next;
        }
        res
    }
}
```

#### JavaScript

```js
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number[]} nums
 * @return {number}
 */
var numComponents = function (head, nums) {
    const s = new Set(nums);
    let ans = 0;
    while (head) {
        while (head && !s.has(head.val)) {
            head = head.next;
        }
        ans += head != null;
        while (head && s.has(head.val)) {
            head = head.next;
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

# [818. 赛车](https://leetcode.cn/problems/race-car){#818}

{{< tabs "818" >}}

{{% tab "python" %}}
```python
class Solution:
    def racecar(self, target: int) -> int:
        dp = [0] * (target + 1)
        for i in range(1, target + 1):
            k = i.bit_length()
            if i == 2**k - 1:
                dp[i] = k
                continue
            dp[i] = dp[2**k - 1 - i] + k + 1
            for j in range(k - 1):
                dp[i] = min(dp[i], dp[i - (2 ** (k - 1) - 2**j)] + k - 1 + j + 2)
        return dp[target]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int racecar(int target) {
        int[] dp = new int[target + 1];
        for (int i = 1; i <= target; ++i) {
            int k = 32 - Integer.numberOfLeadingZeros(i);
            if (i == (1 << k) - 1) {
                dp[i] = k;
                continue;
            }
            dp[i] = dp[(1 << k) - 1 - i] + k + 1;
            for (int j = 0; j < k; ++j) {
                dp[i] = Math.min(dp[i], dp[i - (1 << (k - 1)) + (1 << j)] + k - 1 + j + 2);
            }
        }
        return dp[target];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int racecar(int target) {
        vector<int> dp(target + 1);
        for (int i = 1; i <= target; ++i) {
            int k = 32 - __builtin_clz(i);
            if (i == (1 << k) - 1) {
                dp[i] = k;
                continue;
            }
            dp[i] = dp[(1 << k) - 1 - i] + k + 1;
            for (int j = 0; j < k; ++j) {
                dp[i] = min(dp[i], dp[i - (1 << (k - 1)) + (1 << j)] + k - 1 + j + 2);
            }
        }
        return dp[target];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func racecar(target int) int {
	dp := make([]int, target+1)
	for i := 1; i <= target; i++ {
		k := bits.Len(uint(i))
		if i == (1<<k)-1 {
			dp[i] = k
			continue
		}
		dp[i] = dp[(1<<k)-1-i] + k + 1
		for j := 0; j < k; j++ {
			dp[i] = min(dp[i], dp[i-(1<<(k-1))+(1<<j)]+k-1+j+2)
		}
	}
	return dp[target]
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

你的赛车可以从位置 <code>0</code> 开始，并且速度为 <code>+1</code> ，在一条无限长的数轴上行驶。赛车也可以向负方向行驶。赛车可以按照由加速指令 <code>'A'</code> 和倒车指令 <code>'R'</code> 组成的指令序列自动行驶。

<ul>
	<li>当收到指令 <code>'A'</code> 时，赛车这样行驶：
	<ul>
		<li><code>position += speed</code></li>
		<li><code>speed *= 2</code></li>
	</ul>
	</li>
	<li>当收到指令 <code>'R'</code> 时，赛车这样行驶：
	<ul>
		<li>如果速度为正数，那么<code>speed = -1</code></li>
		<li>否则 <code>speed = 1</code></li>
	</ul>
	当前所处位置不变。</li>
</ul>

<p>例如，在执行指令 <code>"AAR"</code> 后，赛车位置变化为 <code>0 --&gt; 1 --&gt; 3 --&gt; 3</code> ，速度变化为 <code>1 --&gt; 2 --&gt; 4 --&gt; -1</code> 。</p>

<p>给你一个目标位置 <code>target</code> ，返回能到达目标位置的最短指令序列的长度。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>target = 3
<strong>输出：</strong>2
<strong>解释：</strong>
最短指令序列是 "AA" 。
位置变化 0 --&gt; 1 --&gt; 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>target = 6
<strong>输出：</strong>5
<strong>解释：</strong>
最短指令序列是 "AAARA" 。
位置变化 0 --&gt; 1 --&gt; 3 --&gt; 7 --&gt; 7 --&gt; 6 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= target &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

设 $dp[i]$ 表示到达位置 $i$ 的最短指令序列的长度。答案为 $dp[target]$。

对于任意位置 $i$，都有 $2^{k-1} \leq i \lt 2^k$，并且我们可以有三种方式到达位置 $i$：

-   如果 $i$ 等于 $2^k-1$，那么我们可以直接执行 $k$ 个 `A` 指令到达位置 $i$，此时 $dp[i] = k$；
-   否则，我们可以先执行 $k$ 个 `A` 指令到达位置 $2^k-1$，然后执行 `R` 指令，剩余距离为 $2^k-1-i$，此时 $dp[i] = dp[2^k-1-i] + k + 1$；我们也可以先执行 $k-1$ 个 `A` 指令到达位置 $2^{k-1}-1$，然后执行 `R` 指令，接着执行 $j$（其中 $0 \le j \lt k$） 个 `A`，再执行 `R`，剩余距离为 $i - 2^{k-1} + 2^j$，此时 $dp[i] = dp[i - 2^{k-1} + 2^j] + k - 1 + j + 2$。求出 $dp[i]$ 的最小值即可。

时间复杂度 $O(n \log n)$，其中 $n$ 为 $target$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def racecar(self, target: int) -> int:
        dp = [0] * (target + 1)
        for i in range(1, target + 1):
            k = i.bit_length()
            if i == 2**k - 1:
                dp[i] = k
                continue
            dp[i] = dp[2**k - 1 - i] + k + 1
            for j in range(k - 1):
                dp[i] = min(dp[i], dp[i - (2 ** (k - 1) - 2**j)] + k - 1 + j + 2)
        return dp[target]
```

#### Java

```java
class Solution {
    public int racecar(int target) {
        int[] dp = new int[target + 1];
        for (int i = 1; i <= target; ++i) {
            int k = 32 - Integer.numberOfLeadingZeros(i);
            if (i == (1 << k) - 1) {
                dp[i] = k;
                continue;
            }
            dp[i] = dp[(1 << k) - 1 - i] + k + 1;
            for (int j = 0; j < k; ++j) {
                dp[i] = Math.min(dp[i], dp[i - (1 << (k - 1)) + (1 << j)] + k - 1 + j + 2);
            }
        }
        return dp[target];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int racecar(int target) {
        vector<int> dp(target + 1);
        for (int i = 1; i <= target; ++i) {
            int k = 32 - __builtin_clz(i);
            if (i == (1 << k) - 1) {
                dp[i] = k;
                continue;
            }
            dp[i] = dp[(1 << k) - 1 - i] + k + 1;
            for (int j = 0; j < k; ++j) {
                dp[i] = min(dp[i], dp[i - (1 << (k - 1)) + (1 << j)] + k - 1 + j + 2);
            }
        }
        return dp[target];
    }
};
```

#### Go

```go
func racecar(target int) int {
	dp := make([]int, target+1)
	for i := 1; i <= target; i++ {
		k := bits.Len(uint(i))
		if i == (1<<k)-1 {
			dp[i] = k
			continue
		}
		dp[i] = dp[(1<<k)-1-i] + k + 1
		for j := 0; j < k; j++ {
			dp[i] = min(dp[i], dp[i-(1<<(k-1))+(1<<j)]+k-1+j+2)
		}
	}
	return dp[target]
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [819. 最常见的单词](https://leetcode.cn/problems/most-common-word){#819}

{{< tabs "819" >}}

{{% tab "python" %}}
```python
class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        s = set(banned)
        p = Counter(re.findall('[a-z]+', paragraph.lower()))
        return next(word for word, _ in p.most_common() if word not in s)
```
{{% /tab %}}
{{% tab "java" %}}
```java
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class Solution {
    private static Pattern pattern = Pattern.compile("[a-z]+");

    public String mostCommonWord(String paragraph, String[] banned) {
        Set<String> bannedWords = new HashSet<>();
        for (String word : banned) {
            bannedWords.add(word);
        }
        Map<String, Integer> counter = new HashMap<>();
        Matcher matcher = pattern.matcher(paragraph.toLowerCase());
        while (matcher.find()) {
            String word = matcher.group();
            if (bannedWords.contains(word)) {
                continue;
            }
            counter.put(word, counter.getOrDefault(word, 0) + 1);
        }
        int max = Integer.MIN_VALUE;
        String ans = null;
        for (Map.Entry<String, Integer> entry : counter.entrySet()) {
            if (entry.getValue() > max) {
                max = entry.getValue();
                ans = entry.getKey();
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
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> s(banned.begin(), banned.end());
        unordered_map<string, int> counter;
        string ans;
        for (int i = 0, mx = 0, n = paragraph.size(); i < n;) {
            if (!isalpha(paragraph[i]) && (++i > 0)) continue;
            int j = i;
            string word;
            while (j < n && isalpha(paragraph[j])) {
                word.push_back(tolower(paragraph[j]));
                ++j;
            }
            i = j + 1;
            if (s.count(word)) continue;
            ++counter[word];
            if (counter[word] > mx) {
                ans = word;
                mx = counter[word];
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func mostCommonWord(paragraph string, banned []string) string {
	s := make(map[string]bool)
	for _, w := range banned {
		s[w] = true
	}
	counter := make(map[string]int)
	var ans string
	for i, mx, n := 0, 0, len(paragraph); i < n; {
		if !unicode.IsLetter(rune(paragraph[i])) {
			i++
			continue
		}
		j := i
		var word []byte
		for j < n && unicode.IsLetter(rune(paragraph[j])) {
			word = append(word, byte(unicode.ToLower(rune(paragraph[j]))))
			j++
		}
		i = j + 1
		t := string(word)
		if s[t] {
			continue
		}
		counter[t]++
		if counter[t] > mx {
			ans = t
			mx = counter[t]
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function mostCommonWord(paragraph: string, banned: string[]): string {
    const s = paragraph.toLocaleLowerCase();
    const map = new Map<string, number>();
    const set = new Set<string>(banned);
    for (const word of s.split(/[^A-z]/)) {
        if (word === '' || set.has(word)) {
            continue;
        }
        map.set(word, (map.get(word) ?? 0) + 1);
    }
    return [...map.entries()].reduce((r, v) => (v[1] > r[1] ? v : r), ['', 0])[0];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::{HashMap, HashSet};
impl Solution {
    pub fn most_common_word(mut paragraph: String, banned: Vec<String>) -> String {
        paragraph.make_ascii_lowercase();
        let banned: HashSet<&str> = banned.iter().map(String::as_str).collect();
        let mut map = HashMap::new();
        for word in paragraph.split(|c| !matches!(c, 'a'..='z')) {
            if word.is_empty() || banned.contains(word) {
                continue;
            }
            let val = map.get(&word).unwrap_or(&0) + 1;
            map.insert(word, val);
        }
        map.into_iter()
            .max_by_key(|&(_, v)| v)
            .unwrap()
            .0
            .to_string()
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>paragraph</code> 和一个表示禁用词的字符串数组 <code>banned</code> ，返回出现频率最高的非禁用词。题目数据 <strong>保证 </strong>至少存在一个非禁用词，且答案<strong> 唯一 </strong>。</p>

<p><code>paragraph</code> 中的单词 <strong>不区分大小写</strong> ，答案应以 <strong>小写 </strong>形式返回。</p>

<p><b>注意</b>&nbsp;单词不包含标点符号。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.", banned = ["hit"]
<strong>输出：</strong>"ball"
<strong>解释：</strong>
"hit" 出现了 3 次，但它是禁用词。
"ball" 出现了两次（没有其他单词出现这么多次），因此它是段落中出现频率最高的非禁用词。
请注意，段落中的单词不区分大小写，
标点符号会被忽略（即使它们紧挨着单词，如 "ball,"），
并且尽管 "hit" 出现的次数更多，但它不能作为答案，因为它是禁用词。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>paragraph = "a.", banned = []
<strong>输出：</strong>"a"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= paragraph.length &lt;= 1000</code></li>
	<li><code>paragraph</code> 由英文字母、空格 <code>' '</code>、和以下符号组成：<code>"!?',;."</code></li>
	<li><code>0 &lt;= banned.length &lt;= 100</code></li>
	<li><code>1 &lt;= banned[i].length &lt;= 10</code></li>
	<li><code>banned[i]</code> 仅由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：正则匹配/双指针 + 哈希表

正则匹配（或双指针）找出所有单词，用哈希表统计每个单词出现的频率，找到出现未在 banned 中出现且频率最大的单词。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        s = set(banned)
        p = Counter(re.findall('[a-z]+', paragraph.lower()))
        return next(word for word, _ in p.most_common() if word not in s)
```

#### Java

```java
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class Solution {
    private static Pattern pattern = Pattern.compile("[a-z]+");

    public String mostCommonWord(String paragraph, String[] banned) {
        Set<String> bannedWords = new HashSet<>();
        for (String word : banned) {
            bannedWords.add(word);
        }
        Map<String, Integer> counter = new HashMap<>();
        Matcher matcher = pattern.matcher(paragraph.toLowerCase());
        while (matcher.find()) {
            String word = matcher.group();
            if (bannedWords.contains(word)) {
                continue;
            }
            counter.put(word, counter.getOrDefault(word, 0) + 1);
        }
        int max = Integer.MIN_VALUE;
        String ans = null;
        for (Map.Entry<String, Integer> entry : counter.entrySet()) {
            if (entry.getValue() > max) {
                max = entry.getValue();
                ans = entry.getKey();
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
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> s(banned.begin(), banned.end());
        unordered_map<string, int> counter;
        string ans;
        for (int i = 0, mx = 0, n = paragraph.size(); i < n;) {
            if (!isalpha(paragraph[i]) && (++i > 0)) continue;
            int j = i;
            string word;
            while (j < n && isalpha(paragraph[j])) {
                word.push_back(tolower(paragraph[j]));
                ++j;
            }
            i = j + 1;
            if (s.count(word)) continue;
            ++counter[word];
            if (counter[word] > mx) {
                ans = word;
                mx = counter[word];
            }
        }
        return ans;
    }
};
```

#### Go

```go
func mostCommonWord(paragraph string, banned []string) string {
	s := make(map[string]bool)
	for _, w := range banned {
		s[w] = true
	}
	counter := make(map[string]int)
	var ans string
	for i, mx, n := 0, 0, len(paragraph); i < n; {
		if !unicode.IsLetter(rune(paragraph[i])) {
			i++
			continue
		}
		j := i
		var word []byte
		for j < n && unicode.IsLetter(rune(paragraph[j])) {
			word = append(word, byte(unicode.ToLower(rune(paragraph[j]))))
			j++
		}
		i = j + 1
		t := string(word)
		if s[t] {
			continue
		}
		counter[t]++
		if counter[t] > mx {
			ans = t
			mx = counter[t]
		}
	}
	return ans
}
```

#### TypeScript

```ts
function mostCommonWord(paragraph: string, banned: string[]): string {
    const s = paragraph.toLocaleLowerCase();
    const map = new Map<string, number>();
    const set = new Set<string>(banned);
    for (const word of s.split(/[^A-z]/)) {
        if (word === '' || set.has(word)) {
            continue;
        }
        map.set(word, (map.get(word) ?? 0) + 1);
    }
    return [...map.entries()].reduce((r, v) => (v[1] > r[1] ? v : r), ['', 0])[0];
}
```

#### Rust

```rust
use std::collections::{HashMap, HashSet};
impl Solution {
    pub fn most_common_word(mut paragraph: String, banned: Vec<String>) -> String {
        paragraph.make_ascii_lowercase();
        let banned: HashSet<&str> = banned.iter().map(String::as_str).collect();
        let mut map = HashMap::new();
        for word in paragraph.split(|c| !matches!(c, 'a'..='z')) {
            if word.is_empty() || banned.contains(word) {
                continue;
            }
            let val = map.get(&word).unwrap_or(&0) + 1;
            map.insert(word, val);
        }
        map.into_iter()
            .max_by_key(|&(_, v)| v)
            .unwrap()
            .0
            .to_string()
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
