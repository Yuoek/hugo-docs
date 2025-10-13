---
title: "0760_找出变位映射 🔒"
date: 2025-10-08T18:36:29+08:00
weight: 7
tags: [位运算, 动态规划, 单调栈, 双指针, 哈希表, 图, 堆（优先队列）, 字符串, 并查集, 广度优先搜索, 排序, 数学, 数组, 栈, 深度优先搜索, 矩阵, 计数, 贪心, 递归]
---

{{< markmap >}}
### [0760_找出变位映射 🔒](#760)
#### [数组](#760)
#### [哈希表](#760)
### [0761_特殊的二进制序列](#761)
#### [递归](#761)
#### [字符串](#761)
### [0762_二进制表示中质数个计算置位](#762)
#### [位运算](#762)
#### [数学](#762)
### [0763_划分字母区间](#763)
#### [贪心](#763)
#### [哈希表](#763)
#### [双指针](#763)
#### [字符串](#763)
### [0764_最大加号标志](#764)
#### [数组](#764)
#### [动态规划](#764)
### [0765_情侣牵手](#765)
#### [贪心](#765)
#### [深度优先搜索](#765)
#### [广度优先搜索](#765)
#### [并查集](#765)
#### [图](#765)
### [0766_托普利茨矩阵](#766)
#### [数组](#766)
#### [矩阵](#766)
### [0767_重构字符串](#767)
#### [贪心](#767)
#### [哈希表](#767)
#### [字符串](#767)
#### [计数](#767)
#### [排序](#767)
#### [堆（优先队列）](#767)
### [0768_最多能完成排序的块 II](#768)
#### [栈](#768)
#### [贪心](#768)
#### [数组](#768)
#### [排序](#768)
#### [单调栈](#768)
### [0769_最多能完成排序的块](#769)
#### [栈](#769)
#### [贪心](#769)
#### [数组](#769)
#### [排序](#769)
#### [单调栈](#769)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0760_找出变位映射 🔒
___
#### 数组
___
#### 哈希表
---
### 0761_特殊的二进制序列
___
#### 递归
___
#### 字符串
---
### 0762_二进制表示中质数个计算置位
___
#### 位运算
___
#### 数学
---
### 0763_划分字母区间
___
#### 贪心
___
#### 哈希表
___
#### 双指针
___
#### 字符串
---
### 0764_最大加号标志
___
#### 数组
___
#### 动态规划
---
### 0765_情侣牵手
___
#### 贪心
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 并查集
___
#### 图
---
### 0766_托普利茨矩阵
___
#### 数组
___
#### 矩阵
---
### 0767_重构字符串
___
#### 贪心
___
#### 哈希表
___
#### 字符串
___
#### 计数
___
#### 排序
___
#### 堆（优先队列）
---
### 0768_最多能完成排序的块 II
___
#### 栈
___
#### 贪心
___
#### 数组
___
#### 排序
___
#### 单调栈
---
### 0769_最多能完成排序的块
___
#### 栈
___
#### 贪心
___
#### 数组
___
#### 排序
___
#### 单调栈
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 位运算 | 动态规划 | 单调栈 |
| 双指针 | 哈希表 | 图 |
| 堆（优先队列） | 字符串 | 并查集 |
| 广度优先搜索 | 排序 | 数学 |
| 数组 | 栈 | 深度优先搜索 |
| 矩阵 | 计数 | 贪心 |
| 递归 |  |  |

# [760. 找出变位映射 🔒](https://leetcode.cn/problems/find-anagram-mappings){#760}

{{< tabs "760" >}}

{{% tab "python" %}}
```python
class Solution:
    def anagramMappings(self, nums1: List[int], nums2: List[int]) -> List[int]:
        mapper = defaultdict(set)
        for i, num in enumerate(nums2):
            mapper[num].add(i)
        return [mapper[num].pop() for num in nums1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] anagramMappings(int[] nums1, int[] nums2) {
        Map<Integer, Set<Integer>> map = new HashMap<>();
        for (int i = 0; i < nums2.length; ++i) {
            map.computeIfAbsent(nums2[i], k -> new HashSet<>()).add(i);
        }
        int[] res = new int[nums1.length];
        for (int i = 0; i < nums1.length; ++i) {
            int idx = map.get(nums1[i]).iterator().next();
            res[i] = idx;
            map.get(nums1[i]).remove(idx);
        }
        return res;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个整数数组 <code>nums1</code> 和 <code>nums2</code>，其中 <code>nums2</code> 是 <code>nums1</code> 的一个<strong> 变位词 </strong>。两个数组都可能包含重复元素。</p>

<p>返回一个下标映射数组 <code>mapping</code>，它将 <code>nums1</code> 映射到 <code>nums2</code>，其中 <code>mapping[i] = j</code> 表示 <code>nums1</code> 中的第 <code>i</code> 个元素出现在 <code>nums2</code> 的第 <code>j</code> 个下标上。如果有多个答案，返回 <strong>任意一个 </strong>。</p>

<p>数组 <code>a</code> 是数组 <code>b</code> 的一个 <strong>变位词 </strong>意味着 <code>b</code> 是通过将 <code>a</code> 中元素的顺序随机打乱生成的。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [12,28,46,32,50], nums2 = [50,12,32,46,28]
<strong>输出：</strong>[1,4,3,2,0]
<strong>解释：</strong>因为 nums1 中的第 0 个元素出现在 nums2[1] 上，所以 mapping[0] = 1，而 nums1 中的第 1 个元素出现在 nums2[4] 上，所以 mapping[1] = 4，以此类推。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [84,46], nums2 = [84,46]
<strong>输出：</strong>[0,1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length &lt;= 100</code></li>
	<li><code>nums2.length == nums1.length</code></li>
	<li><code>0 &lt;= nums1[i], nums2[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>nums2</code> 是 <code>nums1</code> 的一个变位词。</li>
</ul>
<!-- 保持注释以帮助理解题目要求 -->

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
    def anagramMappings(self, nums1: List[int], nums2: List[int]) -> List[int]:
        mapper = defaultdict(set)
        for i, num in enumerate(nums2):
            mapper[num].add(i)
        return [mapper[num].pop() for num in nums1]
```

#### Java

```java
class Solution {
    public int[] anagramMappings(int[] nums1, int[] nums2) {
        Map<Integer, Set<Integer>> map = new HashMap<>();
        for (int i = 0; i < nums2.length; ++i) {
            map.computeIfAbsent(nums2[i], k -> new HashSet<>()).add(i);
        }
        int[] res = new int[nums1.length];
        for (int i = 0; i < nums1.length; ++i) {
            int idx = map.get(nums1[i]).iterator().next();
            res[i] = idx;
            map.get(nums1[i]).remove(idx);
        }
        return res;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [761. 特殊的二进制序列](https://leetcode.cn/problems/special-binary-string){#761}

{{< tabs "761" >}}

{{% tab "python" %}}
```python
class Solution:
    def makeLargestSpecial(self, s: str) -> str:
        if s == '':
            return ''
        ans = []
        cnt = 0
        i = j = 0
        while i < len(s):
            cnt += 1 if s[i] == '1' else -1
            if cnt == 0:
                ans.append('1' + self.makeLargestSpecial(s[j + 1 : i]) + '0')
                j = i + 1
            i += 1
        ans.sort(reverse=True)
        return ''.join(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String makeLargestSpecial(String s) {
        if ("".equals(s)) {
            return "";
        }
        List<String> ans = new ArrayList<>();
        int cnt = 0;
        for (int i = 0, j = 0; i < s.length(); ++i) {
            cnt += s.charAt(i) == '1' ? 1 : -1;
            if (cnt == 0) {
                String t = "1" + makeLargestSpecial(s.substring(j + 1, i)) + "0";
                ans.add(t);
                j = i + 1;
            }
        }
        ans.sort(Comparator.reverseOrder());
        return String.join("", ans);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string makeLargestSpecial(string s) {
        if (s == "") return s;
        vector<string> ans;
        int cnt = 0;
        for (int i = 0, j = 0; i < s.size(); ++i) {
            cnt += s[i] == '1' ? 1 : -1;
            if (cnt == 0) {
                ans.push_back("1" + makeLargestSpecial(s.substr(j + 1, i - j - 1)) + "0");
                j = i + 1;
            }
        }
        sort(ans.begin(), ans.end(), greater<string>{});
        return accumulate(ans.begin(), ans.end(), ""s);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func makeLargestSpecial(s string) string {
	if s == "" {
		return ""
	}
	ans := sort.StringSlice{}
	cnt := 0
	for i, j := 0, 0; i < len(s); i++ {
		if s[i] == '1' {
			cnt++
		} else {
			cnt--
		}
		if cnt == 0 {
			ans = append(ans, "1"+makeLargestSpecial(s[j+1:i])+"0")
			j = i + 1
		}
	}
	sort.Sort(sort.Reverse(ans))
	return strings.Join(ans, "")
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>特殊的二进制序列是具有以下两个性质的二进制序列：</p>

<ul>
	<li>0 的数量与 1 的数量相等。</li>
	<li>二进制序列的每一个前缀码中 1 的数量要大于等于 0 的数量。</li>
</ul>

<p>给定一个特殊的二进制序列&nbsp;<code>S</code>，以字符串形式表示。定义一个<em>操作 </em>为首先选择&nbsp;<code>S</code>&nbsp;的两个连续且非空的特殊的子串，然后将它们交换。（两个子串为连续的当且仅当第一个子串的最后一个字符恰好为第二个子串的第一个字符的前一个字符。)</p>

<p>在任意次数的操作之后，交换后的字符串按照字典序排列的最大的结果是什么？</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> S = &quot;11011000&quot;
<strong>输出:</strong> &quot;11100100&quot;
<strong>解释:</strong>
将子串 &quot;10&quot; （在S[1]出现） 和 &quot;1100&quot; （在S[3]出现）进行交换。
这是在进行若干次操作后按字典序排列最大的结果。
</pre>

<p><strong>说明:</strong></p>

<ol>
	<li><code>S</code>&nbsp;的长度不超过&nbsp;<code>50</code>。</li>
	<li><code>S</code>&nbsp;保证为一个满足上述定义的<em>特殊 </em>的二进制序列。</li>
</ol>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归 + 排序

我们可以把特殊的二进制序列看作“有效的括号”，$1$ 代表左括号，$0$ 代表右括号。例如，"11011000" 可以看作："(()(()))"。

交换两个连续非空的特殊子串，相当于交换两个相邻的有效括号，我们可以使用递归来解决这个问题。

我们将字符串 $s$ 中的每个“有效的括号”都看作一部分，递归处理，最后进行排序，得到最终答案。

时间复杂度 $O(n^2)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def makeLargestSpecial(self, s: str) -> str:
        if s == '':
            return ''
        ans = []
        cnt = 0
        i = j = 0
        while i < len(s):
            cnt += 1 if s[i] == '1' else -1
            if cnt == 0:
                ans.append('1' + self.makeLargestSpecial(s[j + 1 : i]) + '0')
                j = i + 1
            i += 1
        ans.sort(reverse=True)
        return ''.join(ans)
```

#### Java

```java
class Solution {
    public String makeLargestSpecial(String s) {
        if ("".equals(s)) {
            return "";
        }
        List<String> ans = new ArrayList<>();
        int cnt = 0;
        for (int i = 0, j = 0; i < s.length(); ++i) {
            cnt += s.charAt(i) == '1' ? 1 : -1;
            if (cnt == 0) {
                String t = "1" + makeLargestSpecial(s.substring(j + 1, i)) + "0";
                ans.add(t);
                j = i + 1;
            }
        }
        ans.sort(Comparator.reverseOrder());
        return String.join("", ans);
    }
}
```

#### C++

```cpp
class Solution {
public:
    string makeLargestSpecial(string s) {
        if (s == "") return s;
        vector<string> ans;
        int cnt = 0;
        for (int i = 0, j = 0; i < s.size(); ++i) {
            cnt += s[i] == '1' ? 1 : -1;
            if (cnt == 0) {
                ans.push_back("1" + makeLargestSpecial(s.substr(j + 1, i - j - 1)) + "0");
                j = i + 1;
            }
        }
        sort(ans.begin(), ans.end(), greater<string>{});
        return accumulate(ans.begin(), ans.end(), ""s);
    }
};
```

#### Go

```go
func makeLargestSpecial(s string) string {
	if s == "" {
		return ""
	}
	ans := sort.StringSlice{}
	cnt := 0
	for i, j := 0, 0; i < len(s); i++ {
		if s[i] == '1' {
			cnt++
		} else {
			cnt--
		}
		if cnt == 0 {
			ans = append(ans, "1"+makeLargestSpecial(s[j+1:i])+"0")
			j = i + 1
		}
	}
	sort.Sort(sort.Reverse(ans))
	return strings.Join(ans, "")
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [762. 二进制表示中质数个计算置位](https://leetcode.cn/problems/prime-number-of-set-bits-in-binary-representation){#762}

{{< tabs "762" >}}

{{% tab "python" %}}
```python
class Solution:
    def countPrimeSetBits(self, left: int, right: int) -> int:
        primes = {2, 3, 5, 7, 11, 13, 17, 19}
        return sum(i.bit_count() in primes for i in range(left, right + 1))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private static Set<Integer> primes = Set.of(2, 3, 5, 7, 11, 13, 17, 19);

    public int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; ++i) {
            if (primes.contains(Integer.bitCount(i))) {
                ++ans;
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
    int countPrimeSetBits(int left, int right) {
        unordered_set<int> primes{2, 3, 5, 7, 11, 13, 17, 19};
        int ans = 0;
        for (int i = left; i <= right; ++i) ans += primes.count(__builtin_popcount(i));
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countPrimeSetBits(left int, right int) (ans int) {
	primes := map[int]int{}
	for _, v := range []int{2, 3, 5, 7, 11, 13, 17, 19} {
		primes[v] = 1
	}
	for i := left; i <= right; i++ {
		ans += primes[bits.OnesCount(uint(i))]
	}
	return
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个整数&nbsp;<code>left</code>&nbsp;和&nbsp;<code>right</code> ，在闭区间 <code>[left, right]</code>&nbsp;范围内，统计并返回 <strong>计算置位位数为质数</strong> 的整数个数。</p>

<p><strong>计算置位位数</strong> 就是二进制表示中 <code>1</code> 的个数。</p>

<ul>
	<li>例如， <code>21</code>&nbsp;的二进制表示&nbsp;<code>10101</code>&nbsp;有 <code>3</code> 个计算置位。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>left = 6, right = 10
<strong>输出：</strong>4
<strong>解释：</strong>
6 -&gt; 110 (2 个计算置位，2 是质数)
7 -&gt; 111 (3 个计算置位，3 是质数)
9 -&gt; 1001 (2 个计算置位，2 是质数)
10-&gt; 1010 (2 个计算置位，2 是质数)
共计 4 个计算置位为质数的数字。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>left = 10, right = 15
<strong>输出：</strong>5
<strong>解释：</strong>
10 -&gt; 1010 (2 个计算置位, 2 是质数)
11 -&gt; 1011 (3 个计算置位, 3 是质数)
12 -&gt; 1100 (2 个计算置位, 2 是质数)
13 -&gt; 1101 (3 个计算置位, 3 是质数)
14 -&gt; 1110 (3 个计算置位, 3 是质数)
15 -&gt; 1111 (4 个计算置位, 4 不是质数)
共计 5 个计算置位为质数的数字。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= left &lt;= right &lt;= 10<sup>6</sup></code></li>
	<li><code>0 &lt;= right - left &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学 + 位运算

题目中 $left$ 和 $right$ 的范围均在 $10^6$ 以内，而 $2^{20} = 1048576$，因此，二进制中 $1$ 的个数最多也就 $20$ 个，而 $20$ 以内的质数有 `[2, 3, 5, 7, 11, 13, 17, 19]`。

我们枚举 $[left,.. right]$ 范围内的每个数，统计其二进制中 $1$ 的个数，然后判断该个数是否为质数，如果是，答案加一。

时间复杂度 $O(n\times \log m)$。其中 $n = right - left + 1$，而 $m$ 为 $[left,.. right]$ 范围内的最大数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countPrimeSetBits(self, left: int, right: int) -> int:
        primes = {2, 3, 5, 7, 11, 13, 17, 19}
        return sum(i.bit_count() in primes for i in range(left, right + 1))
```

#### Java

```java
class Solution {
    private static Set<Integer> primes = Set.of(2, 3, 5, 7, 11, 13, 17, 19);

    public int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; ++i) {
            if (primes.contains(Integer.bitCount(i))) {
                ++ans;
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
    int countPrimeSetBits(int left, int right) {
        unordered_set<int> primes{2, 3, 5, 7, 11, 13, 17, 19};
        int ans = 0;
        for (int i = left; i <= right; ++i) ans += primes.count(__builtin_popcount(i));
        return ans;
    }
};
```

#### Go

```go
func countPrimeSetBits(left int, right int) (ans int) {
	primes := map[int]int{}
	for _, v := range []int{2, 3, 5, 7, 11, 13, 17, 19} {
		primes[v] = 1
	}
	for i := left; i <= right; i++ {
		ans += primes[bits.OnesCount(uint(i))]
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [763. 划分字母区间](https://leetcode.cn/problems/partition-labels){#763}

{{< tabs "763" >}}

{{% tab "python" %}}
```python
class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        last = {c: i for i, c in enumerate(s)}
        mx = j = 0
        ans = []
        for i, c in enumerate(s):
            mx = max(mx, last[c])
            if mx == i:
                ans.append(i - j + 1)
                j = i + 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> partitionLabels(String s) {
        int[] last = new int[26];
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            last[s.charAt(i) - 'a'] = i;
        }
        List<Integer> ans = new ArrayList<>();
        int mx = 0, j = 0;
        for (int i = 0; i < n; ++i) {
            mx = Math.max(mx, last[s.charAt(i) - 'a']);
            if (mx == i) {
                ans.add(i - j + 1);
                j = i + 1;
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
    vector<int> partitionLabels(string s) {
        int last[26] = {0};
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            last[s[i] - 'a'] = i;
        }
        vector<int> ans;
        int mx = 0, j = 0;
        for (int i = 0; i < n; ++i) {
            mx = max(mx, last[s[i] - 'a']);
            if (mx == i) {
                ans.push_back(i - j + 1);
                j = i + 1;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func partitionLabels(s string) (ans []int) {
	last := [26]int{}
	for i, c := range s {
		last[c-'a'] = i
	}
	var mx, j int
	for i, c := range s {
		mx = max(mx, last[c-'a'])
		if mx == i {
			ans = append(ans, i-j+1)
			j = i + 1
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function partitionLabels(s: string): number[] {
    const last: number[] = Array(26).fill(0);
    const idx = (c: string) => c.charCodeAt(0) - 'a'.charCodeAt(0);
    const n = s.length;
    for (let i = 0; i < n; ++i) {
        last[idx(s[i])] = i;
    }
    const ans: number[] = [];
    for (let i = 0, j = 0, mx = 0; i < n; ++i) {
        mx = Math.max(mx, last[idx(s[i])]);
        if (mx === i) {
            ans.push(i - j + 1);
            j = i + 1;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn partition_labels(s: String) -> Vec<i32> {
        let n = s.len();
        let bytes = s.as_bytes();
        let mut last = [0; 26];
        for i in 0..n {
            last[(bytes[i] - b'a') as usize] = i;
        }
        let mut ans = vec![];
        let mut j = 0;
        let mut mx = 0;
        for i in 0..n {
            mx = mx.max(last[(bytes[i] - b'a') as usize]);
            if mx == i {
                ans.push((i - j + 1) as i32);
                j = i + 1;
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
 * @param {string} s
 * @return {number[]}
 */
var partitionLabels = function (s) {
    const last = new Array(26).fill(0);
    const idx = c => c.charCodeAt() - 'a'.charCodeAt();
    const n = s.length;
    for (let i = 0; i < n; ++i) {
        last[idx(s[i])] = i;
    }
    const ans = [];
    for (let i = 0, j = 0, mx = 0; i < n; ++i) {
        mx = Math.max(mx, last[idx(s[i])]);
        if (mx === i) {
            ans.push(i - j + 1);
            j = i + 1;
        }
    }
    return ans;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public IList<int> PartitionLabels(string s) {
        int[] last = new int[26];
        int n = s.Length;
        for (int i = 0; i < n; i++) {
            last[s[i] - 'a'] = i;
        }
        IList<int> ans = new List<int>();
        for (int i = 0, j = 0, mx = 0; i < n; ++i) {
            mx = Math.Max(mx, last[s[i] - 'a']);
            if (mx == i) {
                ans.Add(i - j + 1);
                j = i + 1;
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

<p>给你一个字符串 <code>s</code> 。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。例如，字符串&nbsp;<code>"ababcc"</code> 能够被分为 <code>["abab", "cc"]</code>，但类似&nbsp;<code>["aba", "bcc"]</code> 或&nbsp;<code>["ab", "ab", "cc"]</code> 的划分是非法的。</p>

<p>注意，划分结果需要满足：将所有划分结果按顺序连接，得到的字符串仍然是 <code>s</code> 。</p>

<p>返回一个表示每个字符串片段的长度的列表。</p>

<p>&nbsp;</p>
<strong class="example">示例 1：</strong>

<pre>
<strong>输入：</strong>s = "ababcbacadefegdehijhklij"
<strong>输出：</strong>[9,7,8]
<strong>解释：</strong>
划分结果为 "ababcbaca"、"defegde"、"hijhklij" 。
每个字母最多出现在一个片段中。
像 "ababcbacadefegde", "hijhklij" 这样的划分是错误的，因为划分的片段数较少。 </pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "eccbbbbdec"
<strong>输出：</strong>[10]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 500</code></li>
	<li><code>s</code> 仅由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

我们先用数组或哈希表 $\textit{last}$ 记录字符串 $s$ 中每个字母最后一次出现的位置。

接下来我们使用贪心的方法，将字符串划分为尽可能多的片段。

从左到右遍历字符串 $s$，遍历的同时维护当前片段的开始下标 $j$ 和结束下标 $i$，初始均为 $0$。

对于每个访问到的字母 $c$，获取到最后一次出现的位置 $\textit{last}[c]$。由于当前片段的结束下标一定不会小于 $\textit{last}[c]$，因此令 $\textit{mx} = \max(\textit{mx}, \textit{last}[c])$。

当访问到下标 $\textit{mx}$ 时，意味着当前片段访问结束，当前片段的下标范围是 $[j,.. i]$，长度为 $i - j + 1$，我们将其添加到结果数组中。然后令 $j = i + 1$, 继续寻找下一个片段。

重复上述过程，直至字符串遍历结束，即可得到所有片段的长度。

时间复杂度 $O(n)$，空间复杂度 $O(|\Sigma|)$。其中 $n$ 为字符串 $s$ 的长度，而 $|\Sigma|$ 为字符集的大小。本题中 $|\Sigma| = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        last = {c: i for i, c in enumerate(s)}
        mx = j = 0
        ans = []
        for i, c in enumerate(s):
            mx = max(mx, last[c])
            if mx == i:
                ans.append(i - j + 1)
                j = i + 1
        return ans
```

#### Java

```java
class Solution {
    public List<Integer> partitionLabels(String s) {
        int[] last = new int[26];
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            last[s.charAt(i) - 'a'] = i;
        }
        List<Integer> ans = new ArrayList<>();
        int mx = 0, j = 0;
        for (int i = 0; i < n; ++i) {
            mx = Math.max(mx, last[s.charAt(i) - 'a']);
            if (mx == i) {
                ans.add(i - j + 1);
                j = i + 1;
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
    vector<int> partitionLabels(string s) {
        int last[26] = {0};
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            last[s[i] - 'a'] = i;
        }
        vector<int> ans;
        int mx = 0, j = 0;
        for (int i = 0; i < n; ++i) {
            mx = max(mx, last[s[i] - 'a']);
            if (mx == i) {
                ans.push_back(i - j + 1);
                j = i + 1;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func partitionLabels(s string) (ans []int) {
	last := [26]int{}
	for i, c := range s {
		last[c-'a'] = i
	}
	var mx, j int
	for i, c := range s {
		mx = max(mx, last[c-'a'])
		if mx == i {
			ans = append(ans, i-j+1)
			j = i + 1
		}
	}
	return
}
```

#### TypeScript

```ts
function partitionLabels(s: string): number[] {
    const last: number[] = Array(26).fill(0);
    const idx = (c: string) => c.charCodeAt(0) - 'a'.charCodeAt(0);
    const n = s.length;
    for (let i = 0; i < n; ++i) {
        last[idx(s[i])] = i;
    }
    const ans: number[] = [];
    for (let i = 0, j = 0, mx = 0; i < n; ++i) {
        mx = Math.max(mx, last[idx(s[i])]);
        if (mx === i) {
            ans.push(i - j + 1);
            j = i + 1;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn partition_labels(s: String) -> Vec<i32> {
        let n = s.len();
        let bytes = s.as_bytes();
        let mut last = [0; 26];
        for i in 0..n {
            last[(bytes[i] - b'a') as usize] = i;
        }
        let mut ans = vec![];
        let mut j = 0;
        let mut mx = 0;
        for i in 0..n {
            mx = mx.max(last[(bytes[i] - b'a') as usize]);
            if mx == i {
                ans.push((i - j + 1) as i32);
                j = i + 1;
            }
        }
        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {string} s
 * @return {number[]}
 */
var partitionLabels = function (s) {
    const last = new Array(26).fill(0);
    const idx = c => c.charCodeAt() - 'a'.charCodeAt();
    const n = s.length;
    for (let i = 0; i < n; ++i) {
        last[idx(s[i])] = i;
    }
    const ans = [];
    for (let i = 0, j = 0, mx = 0; i < n; ++i) {
        mx = Math.max(mx, last[idx(s[i])]);
        if (mx === i) {
            ans.push(i - j + 1);
            j = i + 1;
        }
    }
    return ans;
};
```

#### C#

```cs
public class Solution {
    public IList<int> PartitionLabels(string s) {
        int[] last = new int[26];
        int n = s.Length;
        for (int i = 0; i < n; i++) {
            last[s[i] - 'a'] = i;
        }
        IList<int> ans = new List<int>();
        for (int i = 0, j = 0, mx = 0; i < n; ++i) {
            mx = Math.Max(mx, last[s[i] - 'a']);
            if (mx == i) {
                ans.Add(i - j + 1);
                j = i + 1;
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

# [764. 最大加号标志](https://leetcode.cn/problems/largest-plus-sign){#764}

{{< tabs "764" >}}

{{% tab "python" %}}
```python
class Solution:
    def orderOfLargestPlusSign(self, n: int, mines: List[List[int]]) -> int:
        dp = [[n] * n for _ in range(n)]
        for x, y in mines:
            dp[x][y] = 0
        for i in range(n):
            left = right = up = down = 0
            for j, k in zip(range(n), reversed(range(n))):
                left = left + 1 if dp[i][j] else 0
                right = right + 1 if dp[i][k] else 0
                up = up + 1 if dp[j][i] else 0
                down = down + 1 if dp[k][i] else 0
                dp[i][j] = min(dp[i][j], left)
                dp[i][k] = min(dp[i][k], right)
                dp[j][i] = min(dp[j][i], up)
                dp[k][i] = min(dp[k][i], down)
        return max(max(v) for v in dp)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int orderOfLargestPlusSign(int n, int[][] mines) {
        int[][] dp = new int[n][n];
        for (var e : dp) {
            Arrays.fill(e, n);
        }
        for (var e : mines) {
            dp[e[0]][e[1]] = 0;
        }
        for (int i = 0; i < n; ++i) {
            int left = 0, right = 0, up = 0, down = 0;
            for (int j = 0, k = n - 1; j < n; ++j, --k) {
                left = dp[i][j] > 0 ? left + 1 : 0;
                right = dp[i][k] > 0 ? right + 1 : 0;
                up = dp[j][i] > 0 ? up + 1 : 0;
                down = dp[k][i] > 0 ? down + 1 : 0;
                dp[i][j] = Math.min(dp[i][j], left);
                dp[i][k] = Math.min(dp[i][k], right);
                dp[j][i] = Math.min(dp[j][i], up);
                dp[k][i] = Math.min(dp[k][i], down);
            }
        }
        return Arrays.stream(dp).flatMapToInt(Arrays::stream).max().getAsInt();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> dp(n, vector<int>(n, n));
        for (auto& e : mines) dp[e[0]][e[1]] = 0;
        for (int i = 0; i < n; ++i) {
            int left = 0, right = 0, up = 0, down = 0;
            for (int j = 0, k = n - 1; j < n; ++j, --k) {
                left = dp[i][j] ? left + 1 : 0;
                right = dp[i][k] ? right + 1 : 0;
                up = dp[j][i] ? up + 1 : 0;
                down = dp[k][i] ? down + 1 : 0;
                dp[i][j] = min(dp[i][j], left);
                dp[i][k] = min(dp[i][k], right);
                dp[j][i] = min(dp[j][i], up);
                dp[k][i] = min(dp[k][i], down);
            }
        }
        int ans = 0;
        for (auto& e : dp) ans = max(ans, *max_element(e.begin(), e.end()));
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func orderOfLargestPlusSign(n int, mines [][]int) (ans int) {
	dp := make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, n)
		for j := range dp[i] {
			dp[i][j] = n
		}
	}
	for _, e := range mines {
		dp[e[0]][e[1]] = 0
	}
	for i := 0; i < n; i++ {
		var left, right, up, down int
		for j, k := 0, n-1; j < n; j, k = j+1, k-1 {
			left, right, up, down = left+1, right+1, up+1, down+1
			if dp[i][j] == 0 {
				left = 0
			}
			if dp[i][k] == 0 {
				right = 0
			}
			if dp[j][i] == 0 {
				up = 0
			}
			if dp[k][i] == 0 {
				down = 0
			}
			dp[i][j] = min(dp[i][j], left)
			dp[i][k] = min(dp[i][k], right)
			dp[j][i] = min(dp[j][i], up)
			dp[k][i] = min(dp[k][i], down)
		}
	}
	for _, e := range dp {
		ans = max(ans, slices.Max(e))
	}
	return
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>在一个 <code>n x n</code> 的矩阵&nbsp;<code>grid</code>&nbsp;中，除了在数组&nbsp;<code>mines</code>&nbsp;中给出的元素为&nbsp;<code>0</code>，其他每个元素都为&nbsp;<code>1</code>。<code>mines[i] = [x<sub>i</sub>, y<sub>i</sub>]</code>表示&nbsp;<code>grid[x<sub>i</sub>][y<sub>i</sub>] == 0</code></p>

<p>返回 <em>&nbsp;</em><code>grid</code><em> 中包含&nbsp;<code>1</code>&nbsp;的最大的 <strong>轴对齐</strong> 加号标志的阶数</em> 。如果未找到加号标志，则返回 <code>0</code> 。</p>

<p>一个&nbsp;<code>k</code>&nbsp;阶由&nbsp;<em><code>1</code></em>&nbsp;组成的 <strong>“轴对称”加号标志</strong> 具有中心网格&nbsp;<code>grid[r][c] == 1</code>&nbsp;，以及4个从中心向上、向下、向左、向右延伸，长度为&nbsp;<code>k-1</code>，由&nbsp;<code>1</code>&nbsp;组成的臂。注意，只有加号标志的所有网格要求为 <code>1</code> ，别的网格可能为 <code>0</code> 也可能为 <code>1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0764.Largest%20Plus%20Sign/images/plus1-grid.jpg" /></p>

<pre>
<strong>输入:</strong> n = 5, mines = [[4, 2]]
<strong>输出:</strong> 2
<strong>解释: </strong>在上面的网格中，最大加号标志的阶只能是2。一个标志已在图中标出。
</pre>

<p><strong>示例 2：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0764.Largest%20Plus%20Sign/images/plus2-grid.jpg" /></p>

<pre>
<strong>输入:</strong> n = 1, mines = [[0, 0]]
<strong>输出:</strong> 0
<strong>解释: </strong>没有加号标志，返回 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 500</code></li>
	<li><code>1 &lt;= mines.length &lt;= 5000</code></li>
	<li><code>0 &lt;= x<sub>i</sub>, y<sub>i</sub>&nbsp;&lt; n</code></li>
	<li>每一对&nbsp;<code>(x<sub>i</sub>, y<sub>i</sub>)</code>&nbsp;都 <strong>不重复</strong>​​​​​​​</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $dp[i][j]$ 表示以 $(i, j)$ 为中心的最大加号标志的阶数，答案即为所有 $dp[i][j]$ 的最大值。

我们可以发现，对于每个 $(i, j)$，其最大加号标志的阶数不会超过其上下左右四个方向上连续的 $1$ 的个数的最小值。因此，我们可以预处理出每个位置上下左右四个方向上连续的 $1$ 的个数，然后遍历所有的 $(i, j)$，求出 $dp[i][j]$ 的最大值即可。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 为网格的边长。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def orderOfLargestPlusSign(self, n: int, mines: List[List[int]]) -> int:
        dp = [[n] * n for _ in range(n)]
        for x, y in mines:
            dp[x][y] = 0
        for i in range(n):
            left = right = up = down = 0
            for j, k in zip(range(n), reversed(range(n))):
                left = left + 1 if dp[i][j] else 0
                right = right + 1 if dp[i][k] else 0
                up = up + 1 if dp[j][i] else 0
                down = down + 1 if dp[k][i] else 0
                dp[i][j] = min(dp[i][j], left)
                dp[i][k] = min(dp[i][k], right)
                dp[j][i] = min(dp[j][i], up)
                dp[k][i] = min(dp[k][i], down)
        return max(max(v) for v in dp)
```

#### Java

```java
class Solution {
    public int orderOfLargestPlusSign(int n, int[][] mines) {
        int[][] dp = new int[n][n];
        for (var e : dp) {
            Arrays.fill(e, n);
        }
        for (var e : mines) {
            dp[e[0]][e[1]] = 0;
        }
        for (int i = 0; i < n; ++i) {
            int left = 0, right = 0, up = 0, down = 0;
            for (int j = 0, k = n - 1; j < n; ++j, --k) {
                left = dp[i][j] > 0 ? left + 1 : 0;
                right = dp[i][k] > 0 ? right + 1 : 0;
                up = dp[j][i] > 0 ? up + 1 : 0;
                down = dp[k][i] > 0 ? down + 1 : 0;
                dp[i][j] = Math.min(dp[i][j], left);
                dp[i][k] = Math.min(dp[i][k], right);
                dp[j][i] = Math.min(dp[j][i], up);
                dp[k][i] = Math.min(dp[k][i], down);
            }
        }
        return Arrays.stream(dp).flatMapToInt(Arrays::stream).max().getAsInt();
    }
}
```

#### C++

```cpp
class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> dp(n, vector<int>(n, n));
        for (auto& e : mines) dp[e[0]][e[1]] = 0;
        for (int i = 0; i < n; ++i) {
            int left = 0, right = 0, up = 0, down = 0;
            for (int j = 0, k = n - 1; j < n; ++j, --k) {
                left = dp[i][j] ? left + 1 : 0;
                right = dp[i][k] ? right + 1 : 0;
                up = dp[j][i] ? up + 1 : 0;
                down = dp[k][i] ? down + 1 : 0;
                dp[i][j] = min(dp[i][j], left);
                dp[i][k] = min(dp[i][k], right);
                dp[j][i] = min(dp[j][i], up);
                dp[k][i] = min(dp[k][i], down);
            }
        }
        int ans = 0;
        for (auto& e : dp) ans = max(ans, *max_element(e.begin(), e.end()));
        return ans;
    }
};
```

#### Go

```go
func orderOfLargestPlusSign(n int, mines [][]int) (ans int) {
	dp := make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, n)
		for j := range dp[i] {
			dp[i][j] = n
		}
	}
	for _, e := range mines {
		dp[e[0]][e[1]] = 0
	}
	for i := 0; i < n; i++ {
		var left, right, up, down int
		for j, k := 0, n-1; j < n; j, k = j+1, k-1 {
			left, right, up, down = left+1, right+1, up+1, down+1
			if dp[i][j] == 0 {
				left = 0
			}
			if dp[i][k] == 0 {
				right = 0
			}
			if dp[j][i] == 0 {
				up = 0
			}
			if dp[k][i] == 0 {
				down = 0
			}
			dp[i][j] = min(dp[i][j], left)
			dp[i][k] = min(dp[i][k], right)
			dp[j][i] = min(dp[j][i], up)
			dp[k][i] = min(dp[k][i], down)
		}
	}
	for _, e := range dp {
		ans = max(ans, slices.Max(e))
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [765. 情侣牵手](https://leetcode.cn/problems/couples-holding-hands){#765}

{{< tabs "765" >}}

{{% tab "python" %}}
```python
class Solution:
    def minSwapsCouples(self, row: List[int]) -> int:
        def find(x: int) -> int:
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        n = len(row) >> 1
        p = list(range(n))
        for i in range(0, len(row), 2):
            a, b = row[i] >> 1, row[i + 1] >> 1
            p[find(a)] = find(b)
        return n - sum(i == find(i) for i in range(n))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] p;

    public int minSwapsCouples(int[] row) {
        int n = row.length >> 1;
        p = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        for (int i = 0; i < n << 1; i += 2) {
            int a = row[i] >> 1, b = row[i + 1] >> 1;
            p[find(a)] = find(b);
        }
        int ans = n;
        for (int i = 0; i < n; ++i) {
            if (i == find(i)) {
                --ans;
            }
        }
        return ans;
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
    int minSwapsCouples(vector<int>& row) {
        int n = row.size() / 2;
        int p[n];
        iota(p, p + n, 0);
        function<int(int)> find = [&](int x) -> int {
            if (p[x] != x) {
                p[x] = find(p[x]);
            }
            return p[x];
        };
        for (int i = 0; i < n << 1; i += 2) {
            int a = row[i] >> 1, b = row[i + 1] >> 1;
            p[find(a)] = find(b);
        }
        int ans = n;
        for (int i = 0; i < n; ++i) {
            ans -= i == find(i);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minSwapsCouples(row []int) int {
	n := len(row) >> 1
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
	for i := 0; i < n<<1; i += 2 {
		a, b := row[i]>>1, row[i+1]>>1
		p[find(a)] = find(b)
	}
	ans := n
	for i := range p {
		if find(i) == i {
			ans--
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minSwapsCouples(row: number[]): number {
    const n = row.length >> 1;
    const p: number[] = Array(n)
        .fill(0)
        .map((_, i) => i);
    const find = (x: number): number => {
        if (p[x] !== x) {
            p[x] = find(p[x]);
        }
        return p[x];
    };
    for (let i = 0; i < n << 1; i += 2) {
        const a = row[i] >> 1;
        const b = row[i + 1] >> 1;
        p[find(a)] = find(b);
    }
    let ans = n;
    for (let i = 0; i < n; ++i) {
        if (i === find(i)) {
            --ans;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    private int[] p;

    public int MinSwapsCouples(int[] row) {
        int n = row.Length >> 1;
        p = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        for (int i = 0; i < n << 1; i += 2) {
            int a = row[i] >> 1;
            int b = row[i + 1] >> 1;
            p[find(a)] = find(b);
        }
        int ans = n;
        for (int i = 0; i < n; ++i) {
            if (p[i] == i) {
                --ans;
            }
        }
        return ans;
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

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><code>n</code> 对情侣坐在连续排列的 <code>2n</code>&nbsp;个座位上，想要牵到对方的手。</p>

<p>人和座位由一个整数数组 <code>row</code> 表示，其中 <code>row[i]</code> 是坐在第 <code>i </code>个座位上的人的 <strong>ID</strong>。情侣们按顺序编号，第一对是&nbsp;<code>(0, 1)</code>，第二对是&nbsp;<code>(2, 3)</code>，以此类推，最后一对是&nbsp;<code>(2n-2, 2n-1)</code>。</p>

<p>返回 <em>最少交换座位的次数，以便每对情侣可以并肩坐在一起</em>。 <i>每次</i>交换可选择任意两人，让他们站起来交换座位。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> row = [0,2,1,3]
<strong>输出:</strong> 1
<strong>解释:</strong> 只需要交换row[1]和row[2]的位置即可。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> row = [3,2,0,1]
<strong>输出:</strong> 0
<strong>解释:</strong> 无需交换座位，所有的情侣都已经可以手牵手了。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>2n == row.length</code></li>
	<li><code>2 &lt;= n &lt;= 30</code></li>
	<li><code>n</code>&nbsp;是偶数</li>
	<li><code>0 &lt;= row[i] &lt; 2n</code></li>
	<li><code>row</code>&nbsp;中所有元素均<strong>无重复</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：并查集

我们可以给每一对情侣编号，编号 $0$ 和 $1$ 的人对应情侣 $0$，编号 $2$ 和 $3$ 的人对应情侣 $1$...即编号为 $row[i]$ 对应的情侣编号为 $\lfloor \frac{row[i]}{2} \rfloor$。

如果有 $k$ 对情侣相互之间坐错了位置，也即是说，有 $k$ 对情侣处于一个置换环中，那么他们之间需要经过 $k-1$ 次交换才能都坐到正确的位置上。

为什么？不妨这样考虑，我们先调整一对情侣的位置，使其坐到正确的位置上，那么问题就从 $k$ 对情侣的问题，转换成了 $k-1$ 对情侣的问题。依此类推，最终 $k=1$ 时，交换次数为 $0$。所以，如果 $k$ 对情侣相互之间坐错了位置，那么需要 $k-1$ 次交换。

因此，我们只需要遍历一遍数组，利用并查集找出有多少个置换环，假设有 $x$ 个，每个环的大小（情侣的对数）为 $y_1, y_2, \cdots, y_x$，那么需要交换的次数为 $y_1-1 + y_2-1 + \cdots + y_x-1 = y_1 + y_2 + \cdots + y_x - x = n - x$。

时间复杂度 $O(n \times \alpha(n))$，空间复杂度 $O(n)$。其中 $\alpha(n)$ 为阿克曼函数的反函数，可以认为是一个很小的常数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minSwapsCouples(self, row: List[int]) -> int:
        def find(x: int) -> int:
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        n = len(row) >> 1
        p = list(range(n))
        for i in range(0, len(row), 2):
            a, b = row[i] >> 1, row[i + 1] >> 1
            p[find(a)] = find(b)
        return n - sum(i == find(i) for i in range(n))
```

#### Java

```java
class Solution {
    private int[] p;

    public int minSwapsCouples(int[] row) {
        int n = row.length >> 1;
        p = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        for (int i = 0; i < n << 1; i += 2) {
            int a = row[i] >> 1, b = row[i + 1] >> 1;
            p[find(a)] = find(b);
        }
        int ans = n;
        for (int i = 0; i < n; ++i) {
            if (i == find(i)) {
                --ans;
            }
        }
        return ans;
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
    int minSwapsCouples(vector<int>& row) {
        int n = row.size() / 2;
        int p[n];
        iota(p, p + n, 0);
        function<int(int)> find = [&](int x) -> int {
            if (p[x] != x) {
                p[x] = find(p[x]);
            }
            return p[x];
        };
        for (int i = 0; i < n << 1; i += 2) {
            int a = row[i] >> 1, b = row[i + 1] >> 1;
            p[find(a)] = find(b);
        }
        int ans = n;
        for (int i = 0; i < n; ++i) {
            ans -= i == find(i);
        }
        return ans;
    }
};
```

#### Go

```go
func minSwapsCouples(row []int) int {
	n := len(row) >> 1
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
	for i := 0; i < n<<1; i += 2 {
		a, b := row[i]>>1, row[i+1]>>1
		p[find(a)] = find(b)
	}
	ans := n
	for i := range p {
		if find(i) == i {
			ans--
		}
	}
	return ans
}
```

#### TypeScript

```ts
function minSwapsCouples(row: number[]): number {
    const n = row.length >> 1;
    const p: number[] = Array(n)
        .fill(0)
        .map((_, i) => i);
    const find = (x: number): number => {
        if (p[x] !== x) {
            p[x] = find(p[x]);
        }
        return p[x];
    };
    for (let i = 0; i < n << 1; i += 2) {
        const a = row[i] >> 1;
        const b = row[i + 1] >> 1;
        p[find(a)] = find(b);
    }
    let ans = n;
    for (let i = 0; i < n; ++i) {
        if (i === find(i)) {
            --ans;
        }
    }
    return ans;
}
```

#### C#

```cs
public class Solution {
    private int[] p;

    public int MinSwapsCouples(int[] row) {
        int n = row.Length >> 1;
        p = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        for (int i = 0; i < n << 1; i += 2) {
            int a = row[i] >> 1;
            int b = row[i + 1] >> 1;
            p[find(a)] = find(b);
        }
        int ans = n;
        for (int i = 0; i < n; ++i) {
            if (p[i] == i) {
                --ans;
            }
        }
        return ans;
    }

    private int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [766. 托普利茨矩阵](https://leetcode.cn/problems/toeplitz-matrix){#766}

{{< tabs "766" >}}

{{% tab "python" %}}
```python
class Solution:
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:
        m, n = len(matrix), len(matrix[0])
        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][j] != matrix[i - 1][j - 1]:
                    return False
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isToeplitzMatrix(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] != matrix[i - 1][j - 1]) {
                    return false;
                }
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
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] != matrix[i - 1][j - 1]) {
                    return false;
                }
            }
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isToeplitzMatrix(matrix [][]int) bool {
	m, n := len(matrix), len(matrix[0])
	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			if matrix[i][j] != matrix[i-1][j-1] {
				return false
			}
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isToeplitzMatrix(matrix: number[][]): boolean {
    const [m, n] = [matrix.length, matrix[0].length];
    for (let i = 1; i < m; ++i) {
        for (let j = 1; j < n; ++j) {
            if (matrix[i][j] !== matrix[i - 1][j - 1]) {
                return false;
            }
        }
    }
    return true;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn is_toeplitz_matrix(matrix: Vec<Vec<i32>>) -> bool {
        let (m, n) = (matrix.len(), matrix[0].len());
        for i in 1..m {
            for j in 1..n {
                if matrix[i][j] != matrix[i - 1][j - 1] {
                    return false;
                }
            }
        }
        true
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[][]} matrix
 * @return {boolean}
 */
var isToeplitzMatrix = function (matrix) {
    const [m, n] = [matrix.length, matrix[0].length];
    for (let i = 1; i < m; ++i) {
        for (let j = 1; j < n; ++j) {
            if (matrix[i][j] !== matrix[i - 1][j - 1]) {
                return false;
            }
        }
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

<p>给你一个 <code>m x n</code> 的矩阵 <code>matrix</code> 。如果这个矩阵是托普利茨矩阵，返回 <code>true</code> ；否则，返回<em> </em><code>false</code><em> 。</em></p>

<p>如果矩阵上每一条由左上到右下的对角线上的元素都相同，那么这个矩阵是<em> </em><strong>托普利茨矩阵</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0766.Toeplitz%20Matrix/images/ex1.jpg" style="width: 322px; height: 242px;" />
<pre>
<strong>输入：</strong>matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
<strong>输出：</strong>true
<strong>解释：</strong>
在上述矩阵中, 其对角线为: 
"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]"。 
各条对角线上的所有元素均相同, 因此答案是 True 。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0766.Toeplitz%20Matrix/images/ex2.jpg" style="width: 162px; height: 162px;" />
<pre>
<strong>输入：</strong>matrix = [[1,2],[2,2]]
<strong>输出：</strong>false
<strong>解释：</strong>
对角线 "[1, 2]" 上的元素不同。</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 <= m, n <= 20</code></li>
	<li><code>0 <= matrix[i][j] <= 99</code></li>
</ul>

<p> </p>

<p><strong>进阶：</strong></p>

<ul>
	<li>如果矩阵存储在磁盘上，并且内存有限，以至于一次最多只能将矩阵的一行加载到内存中，该怎么办？</li>
	<li>如果矩阵太大，以至于一次只能将不完整的一行加载到内存中，该怎么办？</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：一次遍历

根据题目描述，托普利茨矩阵的特点是：矩阵中每个元素都与其左上角的元素相等。因此，我们只需要遍历矩阵中的每个元素，检查它是否与左上角的元素相等即可。

时间复杂度 $O(m \times n)$，其中 $m$ 和 $n$ 分别是矩阵的行数和列数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:
        m, n = len(matrix), len(matrix[0])
        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][j] != matrix[i - 1][j - 1]:
                    return False
        return True
```

#### Java

```java
class Solution {
    public boolean isToeplitzMatrix(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] != matrix[i - 1][j - 1]) {
                    return false;
                }
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
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] != matrix[i - 1][j - 1]) {
                    return false;
                }
            }
        }
        return true;
    }
};
```

#### Go

```go
func isToeplitzMatrix(matrix [][]int) bool {
	m, n := len(matrix), len(matrix[0])
	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			if matrix[i][j] != matrix[i-1][j-1] {
				return false
			}
		}
	}
	return true
}
```

#### TypeScript

```ts
function isToeplitzMatrix(matrix: number[][]): boolean {
    const [m, n] = [matrix.length, matrix[0].length];
    for (let i = 1; i < m; ++i) {
        for (let j = 1; j < n; ++j) {
            if (matrix[i][j] !== matrix[i - 1][j - 1]) {
                return false;
            }
        }
    }
    return true;
}
```

#### Rust

```rust
impl Solution {
    pub fn is_toeplitz_matrix(matrix: Vec<Vec<i32>>) -> bool {
        let (m, n) = (matrix.len(), matrix[0].len());
        for i in 1..m {
            for j in 1..n {
                if matrix[i][j] != matrix[i - 1][j - 1] {
                    return false;
                }
            }
        }
        true
    }
}
```

#### JavaScript

```js
/**
 * @param {number[][]} matrix
 * @return {boolean}
 */
var isToeplitzMatrix = function (matrix) {
    const [m, n] = [matrix.length, matrix[0].length];
    for (let i = 1; i < m; ++i) {
        for (let j = 1; j < n; ++j) {
            if (matrix[i][j] !== matrix[i - 1][j - 1]) {
                return false;
            }
        }
    }
    return true;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [767. 重构字符串](https://leetcode.cn/problems/reorganize-string){#767}

{{< tabs "767" >}}

{{% tab "python" %}}
```python
class Solution:
    def reorganizeString(self, s: str) -> str:
        return self.rearrangeString(s, 2)

    def rearrangeString(self, s: str, k: int) -> str:
        h = [(-v, c) for c, v in Counter(s).items()]
        heapify(h)
        q = deque()
        ans = []
        while h:
            v, c = heappop(h)
            v *= -1
            ans.append(c)
            q.append((v - 1, c))
            if len(q) >= k:
                w, c = q.popleft()
                if w:
                    heappush(h, (-w, c))
        return "" if len(ans) != len(s) else "".join(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String reorganizeString(String s) {
        return rearrangeString(s, 2);
    }

    public String rearrangeString(String s, int k) {
        int n = s.length();
        int[] cnt = new int[26];
        for (char c : s.toCharArray()) {
            ++cnt[c - 'a'];
        }
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[0] - a[0]);
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] > 0) {
                pq.offer(new int[] {cnt[i], i});
            }
        }
        Deque<int[]> q = new ArrayDeque<>();
        StringBuilder ans = new StringBuilder();
        while (!pq.isEmpty()) {
            var p = pq.poll();
            int v = p[0], c = p[1];
            ans.append((char) ('a' + c));
            q.offer(new int[] {v - 1, c});
            if (q.size() >= k) {
                p = q.pollFirst();
                if (p[0] > 0) {
                    pq.offer(p);
                }
            }
        }
        return ans.length() == n ? ans.toString() : "";
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string reorganizeString(string s) {
        return rearrangeString(s, 2);
    }

    string rearrangeString(string s, int k) {
        unordered_map<char, int> cnt;
        for (char c : s) ++cnt[c];
        priority_queue<pair<int, char>> pq;
        for (auto& [c, v] : cnt) pq.push({v, c});
        queue<pair<int, char>> q;
        string ans;
        while (!pq.empty()) {
            auto [v, c] = pq.top();
            pq.pop();
            ans += c;
            q.push({v - 1, c});
            if (q.size() >= k) {
                auto p = q.front();
                q.pop();
                if (p.first) {
                    pq.push(p);
                }
            }
        }
        return ans.size() == s.size() ? ans : "";
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func reorganizeString(s string) string {
	return rearrangeString(s, 2)
}

func rearrangeString(s string, k int) string {
	cnt := map[byte]int{}
	for i := range s {
		cnt[s[i]]++
	}
	pq := hp{}
	for c, v := range cnt {
		heap.Push(&pq, pair{v, c})
	}
	ans := []byte{}
	q := []pair{}
	for len(pq) > 0 {
		p := heap.Pop(&pq).(pair)
		v, c := p.v, p.c
		ans = append(ans, c)
		q = append(q, pair{v - 1, c})
		if len(q) >= k {
			p = q[0]
			q = q[1:]
			if p.v > 0 {
				heap.Push(&pq, p)
			}
		}
	}
	if len(ans) == len(s) {
		return string(ans)
	}
	return ""
}

type pair struct {
	v int
	c byte
}

type hp []pair

func (h hp) Len() int { return len(h) }
func (h hp) Less(i, j int) bool {
	a, b := h[i], h[j]
	return a.v > b.v
}
func (h hp) Swap(i, j int) { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)   { *h = append(*h, v.(pair)) }
func (h *hp) Pop() any     { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::{BinaryHeap, HashMap, VecDeque};

impl Solution {
    #[allow(dead_code)]
    pub fn reorganize_string(s: String) -> String {
        let mut map = HashMap::new();
        let mut pq = BinaryHeap::new();
        let mut ret = String::new();
        let mut queue = VecDeque::new();
        let n = s.len();

        // Initialize the HashMap
        for c in s.chars() {
            map.entry(c)
                .and_modify(|e| {
                    *e += 1;
                })
                .or_insert(1);
        }

        // Initialize the binary heap
        for (k, v) in map.iter() {
            if 2 * *v - 1 > n {
                return "".to_string();
            } else {
                pq.push((*v, *k));
            }
        }

        while !pq.is_empty() {
            let (v, k) = pq.pop().unwrap();
            ret.push(k);
            queue.push_back((v - 1, k));
            if queue.len() == 2 {
                let (v, k) = queue.pop_front().unwrap();
                if v != 0 {
                    pq.push((v, k));
                }
            }
        }

        if ret.len() == n {
            ret
        } else {
            "".to_string()
        }
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个字符串&nbsp;<code>s</code>&nbsp;，检查是否能重新排布其中的字母，使得两相邻的字符不同。</p>

<p>返回<em> <code>s</code>&nbsp;的任意可能的重新排列。若不可行，返回空字符串&nbsp;<code>""</code></em>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre>
<strong>输入:</strong> s = "aab"
<strong>输出:</strong> "aba"
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> s = "aaab"
<strong>输出:</strong> ""
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 500</code></li>
	<li><code>s</code> 只包含小写字母</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

利用哈希表 cnt 统计字符串 s 中每个字符出现的次数。

若最大的出现次数 mx 大于 `(n + 1) / 2`，说明一定会存在两个相同字符相邻，直接返回 ''。

否则，按字符出现频率从大到小遍历，依次间隔 1 个位置填充字符。若位置大于等于 n，则重置为 1 继续填充。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def reorganizeString(self, s: str) -> str:
        n = len(s)
        cnt = Counter(s)
        mx = max(cnt.values())
        if mx > (n + 1) // 2:
            return ''
        i = 0
        ans = [None] * n
        for k, v in cnt.most_common():
            while v:
                ans[i] = k
                v -= 1
                i += 2
                if i >= n:
                    i = 1
        return ''.join(ans)
```

#### Java

```java
class Solution {
    public String reorganizeString(String s) {
        int[] cnt = new int[26];
        int mx = 0;
        for (char c : s.toCharArray()) {
            int t = c - 'a';
            ++cnt[t];
            mx = Math.max(mx, cnt[t]);
        }
        int n = s.length();
        if (mx > (n + 1) / 2) {
            return "";
        }
        int k = 0;
        for (int v : cnt) {
            if (v > 0) {
                ++k;
            }
        }
        int[][] m = new int[k][2];
        k = 0;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] > 0) {
                m[k++] = new int[] {cnt[i], i};
            }
        }
        Arrays.sort(m, (a, b) -> b[0] - a[0]);
        k = 0;
        StringBuilder ans = new StringBuilder(s);
        for (int[] e : m) {
            int v = e[0], i = e[1];
            while (v-- > 0) {
                ans.setCharAt(k, (char) ('a' + i));
                k += 2;
                if (k >= n) {
                    k = 1;
                }
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
    string reorganizeString(string s) {
        vector<int> cnt(26);
        for (char& c : s) ++cnt[c - 'a'];
        int mx = *max_element(cnt.begin(), cnt.end());
        int n = s.size();
        if (mx > (n + 1) / 2) return "";
        vector<vector<int>> m;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i]) m.push_back({cnt[i], i});
        }
        sort(m.begin(), m.end());
        reverse(m.begin(), m.end());
        string ans = s;
        int k = 0;
        for (auto& e : m) {
            int v = e[0], i = e[1];
            while (v--) {
                ans[k] = 'a' + i;
                k += 2;
                if (k >= n) k = 1;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func reorganizeString(s string) string {
	cnt := make([]int, 26)
	for _, c := range s {
		t := c - 'a'
		cnt[t]++
	}
	mx := slices.Max(cnt)
	n := len(s)
	if mx > (n+1)/2 {
		return ""
	}
	m := [][]int{}
	for i, v := range cnt {
		if v > 0 {
			m = append(m, []int{v, i})
		}
	}
	sort.Slice(m, func(i, j int) bool {
		return m[i][0] > m[j][0]
	})
	ans := make([]byte, n)
	k := 0
	for _, e := range m {
		v, i := e[0], e[1]
		for v > 0 {
			ans[k] = byte('a' + i)
			k += 2
			if k >= n {
				k = 1
			}
			v--
		}
	}
	return string(ans)
}
```

#### Rust

```rust
use std::collections::{BinaryHeap, HashMap, VecDeque};

impl Solution {
    #[allow(dead_code)]
    pub fn reorganize_string(s: String) -> String {
        let mut map = HashMap::new();
        let mut pq = BinaryHeap::new();
        let mut ret = String::new();
        let mut queue = VecDeque::new();
        let n = s.len();

        // Initialize the HashMap
        for c in s.chars() {
            map.entry(c)
                .and_modify(|e| {
                    *e += 1;
                })
                .or_insert(1);
        }

        // Initialize the binary heap
        for (k, v) in map.iter() {
            if 2 * *v - 1 > n {
                return "".to_string();
            } else {
                pq.push((*v, *k));
            }
        }

        while !pq.is_empty() {
            let (v, k) = pq.pop().unwrap();
            ret.push(k);
            queue.push_back((v - 1, k));
            if queue.len() == 2 {
                let (v, k) = queue.pop_front().unwrap();
                if v != 0 {
                    pq.push((v, k));
                }
            }
        }

        if ret.len() == n {
            ret
        } else {
            "".to_string()
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：贪心 + 哈希表 + 优先队列（大根堆）

先用哈希表 `cnt` 统计每个字母出现的次数，然后构建一个大根堆 `pq`，其中每个元素是一个 `(v, c)` 的元组，其中 `c` 是字母，`v` 是字母出现的次数。

重排字符串时，我们每次从堆顶弹出一个元素 `(v, c)`，将 `c` 添加到结果字符串中，并将 `(v-1, c)` 放入队列 `q` 中。当队列 `q` 的长度达到 $k$ （本题中 $k$ 为 2）及以上时，弹出队首元素，若此时 `v` 大于 0，则将队首元素放入堆中。循环，直至堆为空。

最后判断结果字符串的长度，若与 `s` 长度相等，则返回结果字符串，否则返回空串。

时间复杂度 $O(n\log n)$，其中 $n$ 是字符串 `s` 的长度。

相似题目：

-   [358. K 距离间隔重排字符串](https://github.com/doocs/leetcode/blob/main/solution/0300-0399/0358.Rearrange%20String%20k%20Distance%20Apart/README.md)
-   [1054. 距离相等的条形码](https://github.com/doocs/leetcode/blob/main/solution/1000-1099/1054.Distant%20Barcodes/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def reorganizeString(self, s: str) -> str:
        return self.rearrangeString(s, 2)

    def rearrangeString(self, s: str, k: int) -> str:
        h = [(-v, c) for c, v in Counter(s).items()]
        heapify(h)
        q = deque()
        ans = []
        while h:
            v, c = heappop(h)
            v *= -1
            ans.append(c)
            q.append((v - 1, c))
            if len(q) >= k:
                w, c = q.popleft()
                if w:
                    heappush(h, (-w, c))
        return "" if len(ans) != len(s) else "".join(ans)
```

#### Java

```java
class Solution {
    public String reorganizeString(String s) {
        return rearrangeString(s, 2);
    }

    public String rearrangeString(String s, int k) {
        int n = s.length();
        int[] cnt = new int[26];
        for (char c : s.toCharArray()) {
            ++cnt[c - 'a'];
        }
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[0] - a[0]);
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] > 0) {
                pq.offer(new int[] {cnt[i], i});
            }
        }
        Deque<int[]> q = new ArrayDeque<>();
        StringBuilder ans = new StringBuilder();
        while (!pq.isEmpty()) {
            var p = pq.poll();
            int v = p[0], c = p[1];
            ans.append((char) ('a' + c));
            q.offer(new int[] {v - 1, c});
            if (q.size() >= k) {
                p = q.pollFirst();
                if (p[0] > 0) {
                    pq.offer(p);
                }
            }
        }
        return ans.length() == n ? ans.toString() : "";
    }
}
```

#### C++

```cpp
class Solution {
public:
    string reorganizeString(string s) {
        return rearrangeString(s, 2);
    }

    string rearrangeString(string s, int k) {
        unordered_map<char, int> cnt;
        for (char c : s) ++cnt[c];
        priority_queue<pair<int, char>> pq;
        for (auto& [c, v] : cnt) pq.push({v, c});
        queue<pair<int, char>> q;
        string ans;
        while (!pq.empty()) {
            auto [v, c] = pq.top();
            pq.pop();
            ans += c;
            q.push({v - 1, c});
            if (q.size() >= k) {
                auto p = q.front();
                q.pop();
                if (p.first) {
                    pq.push(p);
                }
            }
        }
        return ans.size() == s.size() ? ans : "";
    }
};
```

#### Go

```go
func reorganizeString(s string) string {
	return rearrangeString(s, 2)
}

func rearrangeString(s string, k int) string {
	cnt := map[byte]int{}
	for i := range s {
		cnt[s[i]]++
	}
	pq := hp{}
	for c, v := range cnt {
		heap.Push(&pq, pair{v, c})
	}
	ans := []byte{}
	q := []pair{}
	for len(pq) > 0 {
		p := heap.Pop(&pq).(pair)
		v, c := p.v, p.c
		ans = append(ans, c)
		q = append(q, pair{v - 1, c})
		if len(q) >= k {
			p = q[0]
			q = q[1:]
			if p.v > 0 {
				heap.Push(&pq, p)
			}
		}
	}
	if len(ans) == len(s) {
		return string(ans)
	}
	return ""
}

type pair struct {
	v int
	c byte
}

type hp []pair

func (h hp) Len() int { return len(h) }
func (h hp) Less(i, j int) bool {
	a, b := h[i], h[j]
	return a.v > b.v
}
func (h hp) Swap(i, j int) { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)   { *h = append(*h, v.(pair)) }
func (h *hp) Pop() any     { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [768. 最多能完成排序的块 II](https://leetcode.cn/problems/max-chunks-to-make-sorted-ii){#768}

{{< tabs "768" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        stk = []
        for v in arr:
            if not stk or v >= stk[-1]:
                stk.append(v)
            else:
                mx = stk.pop()
                while stk and stk[-1] > v:
                    stk.pop()
                stk.append(mx)
        return len(stk)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxChunksToSorted(int[] arr) {
        Deque<Integer> stk = new ArrayDeque<>();
        for (int v : arr) {
            if (stk.isEmpty() || stk.peek() <= v) {
                stk.push(v);
            } else {
                int mx = stk.pop();
                while (!stk.isEmpty() && stk.peek() > v) {
                    stk.pop();
                }
                stk.push(mx);
            }
        }
        return stk.size();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> stk;
        for (int& v : arr) {
            if (stk.empty() || stk.top() <= v)
                stk.push(v);
            else {
                int mx = stk.top();
                stk.pop();
                while (!stk.empty() && stk.top() > v) stk.pop();
                stk.push(mx);
            }
        }
        return stk.size();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxChunksToSorted(arr []int) int {
	var stk []int
	for _, v := range arr {
		if len(stk) == 0 || stk[len(stk)-1] <= v {
			stk = append(stk, v)
		} else {
			mx := stk[len(stk)-1]
			stk = stk[:len(stk)-1]
			for len(stk) > 0 && stk[len(stk)-1] > v {
				stk = stk[:len(stk)-1]
			}
			stk = append(stk, mx)
		}
	}
	return len(stk)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxChunksToSorted(arr: number[]): number {
    const stk: number[] = [];
    for (let v of arr) {
        if (stk.length === 0 || v >= stk[stk.length - 1]) {
            stk.push(v);
        } else {
            let mx = stk.pop()!;
            while (stk.length > 0 && stk[stk.length - 1] > v) {
                stk.pop();
            }
            stk.push(mx);
        }
    }
    return stk.length;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn max_chunks_to_sorted(arr: Vec<i32>) -> i32 {
        let mut stk = Vec::new();
        for &v in arr.iter() {
            if stk.is_empty() || v >= *stk.last().unwrap() {
                stk.push(v);
            } else {
                let mut mx = stk.pop().unwrap();
                while let Some(&top) = stk.last() {
                    if top > v {
                        stk.pop();
                    } else {
                        break;
                    }
                }
                stk.push(mx);
            }
        }
        stk.len() as i32
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>arr</code> 。</p>

<p>将 <code>arr</code> 分割成若干 <strong>块</strong> ，并将这些块分别进行排序。之后再连接起来，使得连接的结果和按升序排序后的原数组相同。</p>

<p>返回能将数组分成的最多块数？</p>
&nbsp;

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr = [5,4,3,2,1]
<strong>输出：</strong>1
<strong>解释：</strong>
将数组分成2块或者更多块，都无法得到所需的结果。 
例如，分成 [5, 4], [3, 2, 1] 的结果是 [4, 5, 1, 2, 3]，这不是有序的数组。 
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr = [2,1,3,4,4]
<strong>输出：</strong>4
<strong>解释：</strong>
可以把它分成两块，例如 [2, 1], [3, 4, 4]。 
然而，分成 [2, 1], [3], [4], [4] 可以得到最多的块数。 
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 2000</code></li>
	<li><code>0 &lt;= arr[i] &lt;= 10<sup>8</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：单调栈

根据题目，我们可以发现，从左到右，每个分块都有一个最大值，并且这些分块的最大值呈单调递增（非严格递增）。我们可以用一个栈来存储这些分块的最大值。最后得到的栈的大小，也就是题目所求的最多能完成排序的块。

时间复杂度 $O(n)$，其中 $n$ 表示 $\textit{arr}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        stk = []
        for v in arr:
            if not stk or v >= stk[-1]:
                stk.append(v)
            else:
                mx = stk.pop()
                while stk and stk[-1] > v:
                    stk.pop()
                stk.append(mx)
        return len(stk)
```

#### Java

```java
class Solution {
    public int maxChunksToSorted(int[] arr) {
        Deque<Integer> stk = new ArrayDeque<>();
        for (int v : arr) {
            if (stk.isEmpty() || stk.peek() <= v) {
                stk.push(v);
            } else {
                int mx = stk.pop();
                while (!stk.isEmpty() && stk.peek() > v) {
                    stk.pop();
                }
                stk.push(mx);
            }
        }
        return stk.size();
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> stk;
        for (int& v : arr) {
            if (stk.empty() || stk.top() <= v)
                stk.push(v);
            else {
                int mx = stk.top();
                stk.pop();
                while (!stk.empty() && stk.top() > v) stk.pop();
                stk.push(mx);
            }
        }
        return stk.size();
    }
};
```

#### Go

```go
func maxChunksToSorted(arr []int) int {
	var stk []int
	for _, v := range arr {
		if len(stk) == 0 || stk[len(stk)-1] <= v {
			stk = append(stk, v)
		} else {
			mx := stk[len(stk)-1]
			stk = stk[:len(stk)-1]
			for len(stk) > 0 && stk[len(stk)-1] > v {
				stk = stk[:len(stk)-1]
			}
			stk = append(stk, mx)
		}
	}
	return len(stk)
}
```

#### TypeScript

```ts
function maxChunksToSorted(arr: number[]): number {
    const stk: number[] = [];
    for (let v of arr) {
        if (stk.length === 0 || v >= stk[stk.length - 1]) {
            stk.push(v);
        } else {
            let mx = stk.pop()!;
            while (stk.length > 0 && stk[stk.length - 1] > v) {
                stk.pop();
            }
            stk.push(mx);
        }
    }
    return stk.length;
}
```

#### Rust

```rust
impl Solution {
    pub fn max_chunks_to_sorted(arr: Vec<i32>) -> i32 {
        let mut stk = Vec::new();
        for &v in arr.iter() {
            if stk.is_empty() || v >= *stk.last().unwrap() {
                stk.push(v);
            } else {
                let mut mx = stk.pop().unwrap();
                while let Some(&top) = stk.last() {
                    if top > v {
                        stk.pop();
                    } else {
                        break;
                    }
                }
                stk.push(mx);
            }
        }
        stk.len() as i32
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [769. 最多能完成排序的块](https://leetcode.cn/problems/max-chunks-to-make-sorted){#769}

{{< tabs "769" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        stk = []
        for v in arr:
            if not stk or v >= stk[-1]:
                stk.append(v)
            else:
                mx = stk.pop()
                while stk and stk[-1] > v:
                    stk.pop()
                stk.append(mx)
        return len(stk)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxChunksToSorted(int[] arr) {
        Deque<Integer> stk = new ArrayDeque<>();
        for (int v : arr) {
            if (stk.isEmpty() || v >= stk.peek()) {
                stk.push(v);
            } else {
                int mx = stk.pop();
                while (!stk.isEmpty() && stk.peek() > v) {
                    stk.pop();
                }
                stk.push(mx);
            }
        }
        return stk.size();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> stk;
        for (int v : arr) {
            if (stk.empty() || v >= stk.top()) {
                stk.push(v);
            } else {
                int mx = stk.top();
                stk.pop();
                while (!stk.empty() && stk.top() > v) {
                    stk.pop();
                }
                stk.push(mx);
            }
        }
        return stk.size();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxChunksToSorted(arr []int) int {
	stk := []int{}
	for _, v := range arr {
		if len(stk) == 0 || v >= stk[len(stk)-1] {
			stk = append(stk, v)
		} else {
			mx := stk[len(stk)-1]
			stk = stk[:len(stk)-1]
			for len(stk) > 0 && stk[len(stk)-1] > v {
				stk = stk[:len(stk)-1]
			}
			stk = append(stk, mx)
		}
	}
	return len(stk)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxChunksToSorted(arr: number[]): number {
    const stk: number[] = [];

    for (const x of arr) {
        if (stk.at(-1)! > x) {
            const top = stk.pop()!;
            while (stk.length && stk.at(-1)! > x) stk.pop();
            stk.push(top);
        } else stk.push(x);
    }

    return stk.length;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn max_chunks_to_sorted(arr: Vec<i32>) -> i32 {
        let mut ans = 0;
        let mut mx = 0;
        for i in 0..arr.len() {
            mx = mx.max(arr[i]);
            if mx == (i as i32) {
                ans += 1;
            }
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxChunksToSorted(int* arr, int arrSize) {
    int ans = 0;
    int mx = -1;
    for (int i = 0; i < arrSize; i++) {
        mx = max(mx, arr[i]);
        if (mx == i) {
            ans++;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function maxChunksToSorted(arr) {
    const stk = [];

    for (const x of arr) {
        if (stk.at(-1) > x) {
            const top = stk.pop();
            while (stk.length && stk.at(-1) > x) stk.pop();
            stk.push(top);
        } else stk.push(x);
    }

    return stk.length;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个长度为 <code>n</code> 的整数数组 <code>arr</code> ，它表示在 <code>[0, n - 1]</code> 范围内的整数的排列。</p>

<p>我们将 <code>arr</code> 分割成若干 <strong>块</strong> (即分区)，并对每个块单独排序。将它们连接起来后，使得连接的结果和按升序排序后的原数组相同。</p>

<p>返回数组能分成的最多块数量。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> arr = [4,3,2,1,0]
<strong>输出:</strong> 1
<strong>解释:</strong>
将数组分成2块或者更多块，都无法得到所需的结果。
例如，分成 [4, 3], [2, 1, 0] 的结果是 [3, 4, 0, 1, 2]，这不是有序的数组。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> arr = [1,0,2,3,4]
<strong>输出:</strong> 4
<strong>解释:</strong>
我们可以把它分成两块，例如 [1, 0], [2, 3, 4]。
然而，分成 [1, 0], [2], [3], [4] 可以得到最多的块数。
对每个块单独排序后，结果为 [0, 1], [2], [3], [4]
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>n == arr.length</code></li>
	<li><code>1 &lt;= n &lt;= 10</code></li>
	<li><code>0 &lt;= arr[i] &lt; n</code></li>
	<li><code>arr</code>&nbsp;中每个元素都 <strong>不同</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 一次遍历

由于 $\textit{arr}$ 是 $[0,..,n-1]$ 的一个排列，若已遍历过的数中的最大值 $\textit{mx}$ 与当前遍历到的下标 $i$ 相等，说明可以进行一次分割，累加答案。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为数组 $\textit{arr}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        mx = ans = 0
        for i, v in enumerate(arr):
            mx = max(mx, v)
            if i == mx:
                ans += 1
        return ans
```

#### Java

```java
class Solution {
    public int maxChunksToSorted(int[] arr) {
        int ans = 0, mx = 0;
        for (int i = 0; i < arr.length; ++i) {
            mx = Math.max(mx, arr[i]);
            if (i == mx) {
                ++ans;
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
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0, mx = 0;
        for (int i = 0; i < arr.size(); ++i) {
            mx = max(mx, arr[i]);
            ans += i == mx;
        }
        return ans;
    }
};
```

#### Go

```go
func maxChunksToSorted(arr []int) int {
	ans, mx := 0, 0
	for i, v := range arr {
		mx = max(mx, v)
		if i == mx {
			ans++
		}
	}
	return ans
}
```

#### TypeScript

```ts
function maxChunksToSorted(arr: number[]): number {
    const n = arr.length;
    let ans = 0;
    let mx = 0;
    for (let i = 0; i < n; i++) {
        mx = Math.max(arr[i], mx);
        if (mx == i) {
            ans++;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn max_chunks_to_sorted(arr: Vec<i32>) -> i32 {
        let mut ans = 0;
        let mut mx = 0;
        for i in 0..arr.len() {
            mx = mx.max(arr[i]);
            if mx == (i as i32) {
                ans += 1;
            }
        }
        ans
    }
}
```

#### C

```c
#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxChunksToSorted(int* arr, int arrSize) {
    int ans = 0;
    int mx = -1;
    for (int i = 0; i < arrSize; i++) {
        mx = max(mx, arr[i]);
        if (mx == i) {
            ans++;
        }
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：单调栈

方法一的解法有一定的局限性，若数组中存在重复元素，就无法得到正确的答案。

根据题目，我们可以发现，从左到右，每个分块都有一个最大值，并且这些分块的最大值呈单调递增。我们可以用一个栈来存储这些分块的最大值。最后得到的栈的大小，也就是题目所求的最多能完成排序的块。

以上这种解法，不仅可以解决本题，也可以解决 [768. 最多能完成排序的块 II](https://github.com/doocs/leetcode/blob/main/solution/0700-0799/0768.Max%20Chunks%20To%20Make%20Sorted%20II/README.md) 这道困难题。大家可以自行尝试。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{arr}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        stk = []
        for v in arr:
            if not stk or v >= stk[-1]:
                stk.append(v)
            else:
                mx = stk.pop()
                while stk and stk[-1] > v:
                    stk.pop()
                stk.append(mx)
        return len(stk)
```

#### Java

```java
class Solution {
    public int maxChunksToSorted(int[] arr) {
        Deque<Integer> stk = new ArrayDeque<>();
        for (int v : arr) {
            if (stk.isEmpty() || v >= stk.peek()) {
                stk.push(v);
            } else {
                int mx = stk.pop();
                while (!stk.isEmpty() && stk.peek() > v) {
                    stk.pop();
                }
                stk.push(mx);
            }
        }
        return stk.size();
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> stk;
        for (int v : arr) {
            if (stk.empty() || v >= stk.top()) {
                stk.push(v);
            } else {
                int mx = stk.top();
                stk.pop();
                while (!stk.empty() && stk.top() > v) {
                    stk.pop();
                }
                stk.push(mx);
            }
        }
        return stk.size();
    }
};
```

#### Go

```go
func maxChunksToSorted(arr []int) int {
	stk := []int{}
	for _, v := range arr {
		if len(stk) == 0 || v >= stk[len(stk)-1] {
			stk = append(stk, v)
		} else {
			mx := stk[len(stk)-1]
			stk = stk[:len(stk)-1]
			for len(stk) > 0 && stk[len(stk)-1] > v {
				stk = stk[:len(stk)-1]
			}
			stk = append(stk, mx)
		}
	}
	return len(stk)
}
```

#### TypeScript

```ts
function maxChunksToSorted(arr: number[]): number {
    const stk: number[] = [];

    for (const x of arr) {
        if (stk.at(-1)! > x) {
            const top = stk.pop()!;
            while (stk.length && stk.at(-1)! > x) stk.pop();
            stk.push(top);
        } else stk.push(x);
    }

    return stk.length;
}
```

#### JavaScript

```js
function maxChunksToSorted(arr) {
    const stk = [];

    for (const x of arr) {
        if (stk.at(-1) > x) {
            const top = stk.pop();
            while (stk.length && stk.at(-1) > x) stk.pop();
            stk.push(top);
        } else stk.push(x);
    }

    return stk.length;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
