---
title: "2270_分割数组的方案数"
date: 2025-10-08T18:39:07+08:00
weight: 8
tags: [二分查找, 位运算, 前缀和, 动态规划, 哈希表, 字符串, 广度优先搜索, 排序, 数组, 有序集合, 树, 深度优先搜索, 滑动窗口, 线段树, 计数, 设计, 贪心]
---

{{< markmap >}}
### [2270_分割数组的方案数](#2270)
#### [数组](#2270)
#### [前缀和](#2270)
### [2271_毯子覆盖的最多白色砖块数](#2271)
#### [贪心](#2271)
#### [数组](#2271)
#### [二分查找](#2271)
#### [前缀和](#2271)
#### [排序](#2271)
#### [滑动窗口](#2271)
### [2272_最大波动的子字符串](#2272)
#### [数组](#2272)
#### [动态规划](#2272)
### [2273_移除字母异位词后的结果数组](#2273)
#### [数组](#2273)
#### [哈希表](#2273)
#### [字符串](#2273)
#### [排序](#2273)
### [2274_不含特殊楼层的最大连续楼层数](#2274)
#### [数组](#2274)
#### [排序](#2274)
### [2275_按位与结果大于零的最长组合](#2275)
#### [位运算](#2275)
#### [数组](#2275)
#### [哈希表](#2275)
#### [计数](#2275)
### [2276_统计区间中的整数数目](#2276)
#### [设计](#2276)
#### [线段树](#2276)
#### [有序集合](#2276)
### [2277_树中最接近路径的节点 🔒](#2277)
#### [树](#2277)
#### [深度优先搜索](#2277)
#### [广度优先搜索](#2277)
#### [数组](#2277)
### [2278_字母在字符串中的百分比](#2278)
#### [字符串](#2278)
### [2279_装满石头的背包的最大数量](#2279)
#### [贪心](#2279)
#### [数组](#2279)
#### [排序](#2279)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2270_分割数组的方案数
___
#### 数组
___
#### 前缀和
---
### 2271_毯子覆盖的最多白色砖块数
___
#### 贪心
___
#### 数组
___
#### 二分查找
___
#### 前缀和
___
#### 排序
___
#### 滑动窗口
---
### 2272_最大波动的子字符串
___
#### 数组
___
#### 动态规划
---
### 2273_移除字母异位词后的结果数组
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 排序
---
### 2274_不含特殊楼层的最大连续楼层数
___
#### 数组
___
#### 排序
---
### 2275_按位与结果大于零的最长组合
___
#### 位运算
___
#### 数组
___
#### 哈希表
___
#### 计数
---
### 2276_统计区间中的整数数目
___
#### 设计
___
#### 线段树
___
#### 有序集合
---
### 2277_树中最接近路径的节点 🔒
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 数组
---
### 2278_字母在字符串中的百分比
___
#### 字符串
---
### 2279_装满石头的背包的最大数量
___
#### 贪心
___
#### 数组
___
#### 排序
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 前缀和 |
| 动态规划 | 哈希表 | 字符串 |
| 广度优先搜索 | 排序 | 数组 |
| 有序集合 | 树 | 深度优先搜索 |
| 滑动窗口 | 线段树 | 计数 |
| 设计 | 贪心 |  |

# [2270. 分割数组的方案数](https://leetcode.cn/problems/number-of-ways-to-split-array){#2270}

{{< tabs "2270" >}}

{{% tab "python" %}}
```python
class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        s = sum(nums)
        ans = t = 0
        for x in nums[:-1]:
            t += x
            ans += t >= s - t
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int waysToSplitArray(int[] nums) {
        long s = 0;
        for (int x : nums) {
            s += x;
        }
        long t = 0;
        int ans = 0;
        for (int i = 0; i + 1 < nums.length; ++i) {
            t += nums[i];
            ans += t >= s - t ? 1 : 0;
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
    int waysToSplitArray(vector<int>& nums) {
        long long s = accumulate(nums.begin(), nums.end(), 0LL);
        long long t = 0;
        int ans = 0;
        for (int i = 0; i + 1 < nums.size(); ++i) {
            t += nums[i];
            ans += t >= s - t;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func waysToSplitArray(nums []int) (ans int) {
	var s, t int
	for _, x := range nums {
		s += x
	}
	for _, x := range nums[:len(nums)-1] {
		t += x
		if t >= s-t {
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function waysToSplitArray(nums: number[]): number {
    const s = nums.reduce((acc, cur) => acc + cur, 0);
    let [ans, t] = [0, 0];
    for (const x of nums.slice(0, -1)) {
        t += x;
        if (t >= s - t) {
            ++ans;
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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始长度为 <code>n</code>&nbsp;的整数数组&nbsp;<code>nums</code>&nbsp;。<br />
<span style="">如果以下描述为真，那么</span><span style=""> </span><code>nums</code>&nbsp;在下标 <code>i</code>&nbsp;处有一个 <strong>合法的分割</strong>&nbsp;：</p>

<ul>
	<li>前&nbsp;<code>i + 1</code>&nbsp;个元素的和 <strong>大于等于</strong>&nbsp;剩下的&nbsp;<code>n - i - 1</code>&nbsp;个元素的和。</li>
	<li>下标 <code>i</code>&nbsp;的右边 <strong>至少有一个</strong>&nbsp;元素，也就是说下标&nbsp;<code>i</code>&nbsp;满足&nbsp;<code>0 &lt;= i &lt; n - 1</code>&nbsp;。</li>
</ul>

<p>请你返回&nbsp;<code>nums</code>&nbsp;中的&nbsp;<strong>合法分割</strong>&nbsp;方案数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [10,4,-8,7]
<b>输出：</b>2
<b>解释：</b>
总共有 3 种不同的方案可以将 nums 分割成两个非空的部分：
- 在下标 0 处分割 nums 。那么第一部分为 [10] ，和为 10 。第二部分为 [4,-8,7] ，和为 3 。因为 10 &gt;= 3 ，所以 i = 0 是一个合法的分割。
- 在下标 1 处分割 nums 。那么第一部分为 [10,4] ，和为 14 。第二部分为 [-8,7] ，和为 -1 。因为 14 &gt;= -1 ，所以 i = 1 是一个合法的分割。
- 在下标 2 处分割 nums 。那么第一部分为 [10,4,-8] ，和为 6 。第二部分为 [7] ，和为 7 。因为 6 &lt; 7 ，所以 i = 2 不是一个合法的分割。
所以 nums 中总共合法分割方案受为 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [2,3,1,0]
<b>输出：</b>2
<b>解释：</b>
总共有 2 种 nums 的合法分割：
- 在下标 1 处分割 nums 。那么第一部分为 [2,3] ，和为 5 。第二部分为 [1,0] ，和为 1 。因为 5 &gt;= 1 ，所以 i = 1 是一个合法的分割。
- 在下标 2 处分割 nums 。那么第一部分为 [2,3,1] ，和为 6 。第二部分为 [0] ，和为 0 。因为 6 &gt;= 0 ，所以 i = 2 是一个合法的分割。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和

我们首先计算数组 $\textit{nums}$ 的总和 $s$，然后遍历数组 $\textit{nums}$ 的前 $n-1$ 个元素，用变量 $t$ 记录前缀和，如果 $t \geq s - t$，则将答案加一。

遍历结束后，返回答案即可。

时间复杂度 $O(n)$，其中 $n$ 为数组 $\textit{nums}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        s = sum(nums)
        ans = t = 0
        for x in nums[:-1]:
            t += x
            ans += t >= s - t
        return ans
```

#### Java

```java
class Solution {
    public int waysToSplitArray(int[] nums) {
        long s = 0;
        for (int x : nums) {
            s += x;
        }
        long t = 0;
        int ans = 0;
        for (int i = 0; i + 1 < nums.length; ++i) {
            t += nums[i];
            ans += t >= s - t ? 1 : 0;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long s = accumulate(nums.begin(), nums.end(), 0LL);
        long long t = 0;
        int ans = 0;
        for (int i = 0; i + 1 < nums.size(); ++i) {
            t += nums[i];
            ans += t >= s - t;
        }
        return ans;
    }
};
```

#### Go

```go
func waysToSplitArray(nums []int) (ans int) {
	var s, t int
	for _, x := range nums {
		s += x
	}
	for _, x := range nums[:len(nums)-1] {
		t += x
		if t >= s-t {
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function waysToSplitArray(nums: number[]): number {
    const s = nums.reduce((acc, cur) => acc + cur, 0);
    let [ans, t] = [0, 0];
    for (const x of nums.slice(0, -1)) {
        t += x;
        if (t >= s - t) {
            ++ans;
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

# [2271. 毯子覆盖的最多白色砖块数](https://leetcode.cn/problems/maximum-white-tiles-covered-by-a-carpet){#2271}

{{< tabs "2271" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumWhiteTiles(self, tiles: List[List[int]], carpetLen: int) -> int:
        tiles.sort()
        n = len(tiles)
        s = ans = j = 0
        for i, (li, ri) in enumerate(tiles):
            while j < n and tiles[j][1] - li + 1 <= carpetLen:
                s += tiles[j][1] - tiles[j][0] + 1
                j += 1
            if j < n and li + carpetLen > tiles[j][0]:
                ans = max(ans, s + li + carpetLen - tiles[j][0])
            else:
                ans = max(ans, s)
            s -= ri - li + 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumWhiteTiles(int[][] tiles, int carpetLen) {
        Arrays.sort(tiles, (a, b) -> a[0] - b[0]);
        int n = tiles.length;
        int s = 0, ans = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            while (j < n && tiles[j][1] - tiles[i][0] + 1 <= carpetLen) {
                s += tiles[j][1] - tiles[j][0] + 1;
                ++j;
            }
            if (j < n && tiles[i][0] + carpetLen > tiles[j][0]) {
                ans = Math.max(ans, s + tiles[i][0] + carpetLen - tiles[j][0]);
            } else {
                ans = Math.max(ans, s);
            }
            s -= (tiles[i][1] - tiles[i][0] + 1);
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
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(), tiles.end());
        int s = 0, ans = 0, n = tiles.size();
        for (int i = 0, j = 0; i < n; ++i) {
            while (j < n && tiles[j][1] - tiles[i][0] + 1 <= carpetLen) {
                s += tiles[j][1] - tiles[j][0] + 1;
                ++j;
            }
            if (j < n && tiles[i][0] + carpetLen > tiles[j][0]) {
                ans = max(ans, s + tiles[i][0] + carpetLen - tiles[j][0]);
            } else {
                ans = max(ans, s);
            }
            s -= (tiles[i][1] - tiles[i][0] + 1);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumWhiteTiles(tiles [][]int, carpetLen int) int {
	sort.Slice(tiles, func(i, j int) bool { return tiles[i][0] < tiles[j][0] })
	n := len(tiles)
	s, ans := 0, 0
	for i, j := 0, 0; i < n; i++ {
		for j < n && tiles[j][1]-tiles[i][0]+1 <= carpetLen {
			s += tiles[j][1] - tiles[j][0] + 1
			j++
		}
		if j < n && tiles[i][0]+carpetLen > tiles[j][0] {
			ans = max(ans, s+tiles[i][0]+carpetLen-tiles[j][0])
		} else {
			ans = max(ans, s)
		}
		s -= (tiles[i][1] - tiles[i][0] + 1)
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

<p>给你一个二维整数数组&nbsp;<code>tiles</code>&nbsp;，其中&nbsp;<code>tiles[i] = [l<sub>i</sub>, r<sub>i</sub>]</code>&nbsp;，表示所有在&nbsp;<code>l<sub>i</sub> &lt;= j &lt;= r<sub>i</sub></code>&nbsp;之间的每个瓷砖位置 <code>j</code>&nbsp;都被涂成了白色。</p>

<p>同时给你一个整数&nbsp;<code>carpetLen</code>&nbsp;，表示可以放在&nbsp;<strong>任何位置</strong>&nbsp;的一块毯子的长度。</p>

<p>请你返回使用这块毯子，<strong>最多</strong>&nbsp;可以盖住多少块瓷砖。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2271.Maximum%20White%20Tiles%20Covered%20by%20a%20Carpet/images/example1drawio3.png" style="width: 644px; height: 158px;" /></p>

<pre>
<b>输入：</b>tiles = [[1,5],[10,11],[12,18],[20,25],[30,32]], carpetLen = 10
<b>输出：</b>9
<b>解释：</b>将毯子从瓷砖 10 开始放置。
总共覆盖 9 块瓷砖，所以返回 9 。
注意可能有其他方案也可以覆盖 9 块瓷砖。
可以看出，瓷砖无法覆盖超过 9 块瓷砖。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2271.Maximum%20White%20Tiles%20Covered%20by%20a%20Carpet/images/example2drawio.png" style="width: 231px; height: 168px;" /></p>

<pre>
<strong>输入：</strong>tiles = [[10,11],[1,1]], carpetLen = 2
<b>输出：</b>2
<b>解释：</b>将毯子从瓷砖 10 开始放置。
总共覆盖 2 块瓷砖，所以我们返回 2 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= tiles.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>tiles[i].length == 2</code></li>
	<li><code>1 &lt;= l<sub>i</sub> &lt;= r<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= carpetLen &lt;= 10<sup>9</sup></code></li>
	<li><code>tiles</code>&nbsp;互相 <strong>不会重叠</strong>&nbsp;。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 排序 + 滑动窗口

直觉上，毯子的左端点一定与某块瓷砖的左端点重合，这样才能使得毯子覆盖的瓷砖最多。

我们可以来简单证明一下。

如果毯子落在某块瓷砖的中间某个位置，将毯子右移一个，毯子覆盖的瓷砖数量可能减少，也可能不变，但不可能增加；将毯子左移一个，毯子覆盖的瓷砖数量可能不变，也可能增加，但不可能减少。

也就是说，将毯子左移至某块瓷砖的左端点，一定可以使得毯子覆盖的瓷砖数量最多。

因此，我们可以将所有瓷砖按照左端点从小到大排序，然后枚举每块瓷砖的左端点，计算出以该左端点为起点的毯子覆盖的瓷砖数量，取最大值即可。

为了计算以某块瓷砖的左端点为起点的毯子覆盖的瓷砖数量，我们可以使用滑动窗口的思想，维护一个右端点不断右移的窗口，窗口内的瓷砖数量即为毯子覆盖的瓷砖数量。

时间复杂度 $O(n\log n)$，其中 $n$ 为瓷砖的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumWhiteTiles(self, tiles: List[List[int]], carpetLen: int) -> int:
        tiles.sort()
        n = len(tiles)
        s = ans = j = 0
        for i, (li, ri) in enumerate(tiles):
            while j < n and tiles[j][1] - li + 1 <= carpetLen:
                s += tiles[j][1] - tiles[j][0] + 1
                j += 1
            if j < n and li + carpetLen > tiles[j][0]:
                ans = max(ans, s + li + carpetLen - tiles[j][0])
            else:
                ans = max(ans, s)
            s -= ri - li + 1
        return ans
```

#### Java

```java
class Solution {
    public int maximumWhiteTiles(int[][] tiles, int carpetLen) {
        Arrays.sort(tiles, (a, b) -> a[0] - b[0]);
        int n = tiles.length;
        int s = 0, ans = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            while (j < n && tiles[j][1] - tiles[i][0] + 1 <= carpetLen) {
                s += tiles[j][1] - tiles[j][0] + 1;
                ++j;
            }
            if (j < n && tiles[i][0] + carpetLen > tiles[j][0]) {
                ans = Math.max(ans, s + tiles[i][0] + carpetLen - tiles[j][0]);
            } else {
                ans = Math.max(ans, s);
            }
            s -= (tiles[i][1] - tiles[i][0] + 1);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(), tiles.end());
        int s = 0, ans = 0, n = tiles.size();
        for (int i = 0, j = 0; i < n; ++i) {
            while (j < n && tiles[j][1] - tiles[i][0] + 1 <= carpetLen) {
                s += tiles[j][1] - tiles[j][0] + 1;
                ++j;
            }
            if (j < n && tiles[i][0] + carpetLen > tiles[j][0]) {
                ans = max(ans, s + tiles[i][0] + carpetLen - tiles[j][0]);
            } else {
                ans = max(ans, s);
            }
            s -= (tiles[i][1] - tiles[i][0] + 1);
        }
        return ans;
    }
};
```

#### Go

```go
func maximumWhiteTiles(tiles [][]int, carpetLen int) int {
	sort.Slice(tiles, func(i, j int) bool { return tiles[i][0] < tiles[j][0] })
	n := len(tiles)
	s, ans := 0, 0
	for i, j := 0, 0; i < n; i++ {
		for j < n && tiles[j][1]-tiles[i][0]+1 <= carpetLen {
			s += tiles[j][1] - tiles[j][0] + 1
			j++
		}
		if j < n && tiles[i][0]+carpetLen > tiles[j][0] {
			ans = max(ans, s+tiles[i][0]+carpetLen-tiles[j][0])
		} else {
			ans = max(ans, s)
		}
		s -= (tiles[i][1] - tiles[i][0] + 1)
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2272. 最大波动的子字符串](https://leetcode.cn/problems/substring-with-largest-variance){#2272}

{{< tabs "2272" >}}

{{% tab "python" %}}
```python
class Solution:
    def largestVariance(self, s: str) -> int:
        ans = 0
        for a, b in permutations(ascii_lowercase, 2):
            if a == b:
                continue
            f = [0, -inf]
            for c in s:
                if c == a:
                    f[0], f[1] = f[0] + 1, f[1] + 1
                elif c == b:
                    f[1] = max(f[1] - 1, f[0] - 1)
                    f[0] = 0
                if ans < f[1]:
                    ans = f[1]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int largestVariance(String s) {
        int n = s.length();
        int ans = 0;
        for (char a = 'a'; a <= 'z'; ++a) {
            for (char b = 'a'; b <= 'z'; ++b) {
                if (a == b) {
                    continue;
                }
                int[] f = new int[] {0, -n};
                for (int i = 0; i < n; ++i) {
                    if (s.charAt(i) == a) {
                        f[0]++;
                        f[1]++;
                    } else if (s.charAt(i) == b) {
                        f[1] = Math.max(f[0] - 1, f[1] - 1);
                        f[0] = 0;
                    }
                    ans = Math.max(ans, f[1]);
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
    int largestVariance(string s) {
        int n = s.size();
        int ans = 0;
        for (char a = 'a'; a <= 'z'; ++a) {
            for (char b = 'a'; b <= 'z'; ++b) {
                if (a == b) {
                    continue;
                }
                int f[2] = {0, -n};
                for (char c : s) {
                    if (c == a) {
                        f[0]++;
                        f[1]++;
                    } else if (c == b) {
                        f[1] = max(f[1] - 1, f[0] - 1);
                        f[0] = 0;
                    }
                    ans = max(ans, f[1]);
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
func largestVariance(s string) int {
	ans, n := 0, len(s)
	for a := 'a'; a <= 'z'; a++ {
		for b := 'a'; b <= 'z'; b++ {
			if a == b {
				continue
			}
			f := [2]int{0, -n}
			for _, c := range s {
				if c == a {
					f[0]++
					f[1]++
				} else if c == b {
					f[1] = max(f[1]-1, f[0]-1)
					f[0] = 0
				}
				ans = max(ans, f[1])
			}
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function largestVariance(s: string): number {
    const n: number = s.length;
    let ans: number = 0;
    for (let a = 97; a <= 122; ++a) {
        for (let b = 97; b <= 122; ++b) {
            if (a === b) {
                continue;
            }
            const f: number[] = [0, -n];
            for (let i = 0; i < n; ++i) {
                if (s.charCodeAt(i) === a) {
                    f[0]++;
                    f[1]++;
                } else if (s.charCodeAt(i) === b) {
                    f[1] = Math.max(f[0] - 1, f[1] - 1);
                    f[0] = 0;
                }
                ans = Math.max(ans, f[1]);
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

<p>字符串的 <strong>波动</strong>&nbsp;定义为子字符串中出现次数 <strong>最多</strong>&nbsp;的字符次数与出现次数 <strong>最少</strong>&nbsp;的字符次数之差。</p>

<p>给你一个字符串&nbsp;<code>s</code>&nbsp;，它只包含小写英文字母。请你返回 <code>s</code>&nbsp;里所有 <strong>子字符串的</strong>&nbsp;<strong>最大波动</strong>&nbsp;值。</p>

<p><strong>子字符串</strong> 是一个字符串的一段连续字符序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>s = "aababbb"
<b>输出：</b>3
<strong>解释：</strong>
所有可能的波动值和它们对应的子字符串如以下所示：
- 波动值为 0 的子字符串："a" ，"aa" ，"ab" ，"abab" ，"aababb" ，"ba" ，"b" ，"bb" 和 "bbb" 。
- 波动值为 1 的子字符串："aab" ，"aba" ，"abb" ，"aabab" ，"ababb" ，"aababbb" 和 "bab" 。
- 波动值为 2 的子字符串："aaba" ，"ababbb" ，"abbb" 和 "babb" 。
- 波动值为 3 的子字符串 "babbb" 。
所以，最大可能波动值为 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>s = "abcde"
<b>输出：</b>0
<strong>解释：</strong>
s 中没有字母出现超过 1 次，所以 s 中每个子字符串的波动值都是 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code>&nbsp; 只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举 + 动态规划

由于字符集只包含小写字母，我们可以考虑枚举出现次数最多的字符 $a$ 以及出现次数最少的字符 $b$。对于一个子串来说，这两种字符出现的次数之差就是子串的波动值。

具体实现上，我们使用双重循环枚举 $a$ 和 $b$，用 $f[0]$ 记录以当前字符结尾的连续出现字符 $a$ 的个数，用 $f[1]$ 记录以当前字符结尾的，并且包含 $a$ 和 $b$ 的子串的波动值。迭代取 $f[1]$ 的最大值即可。

递推公式如下：

1. 如果当前字符为 $a$，则 $f[0]$ 和 $f[1]$ 都加 $1$；
1. 如果当前字符为 $b$，则 $f[1] = \max(f[1] - 1, f[0] - 1)$，而 $f[0] = 0$；
1. 否则，无需考虑。

注意，初始时将 $f[1]$ 赋值为一个负数最大值，可以保证更新答案时是合法的。

时间复杂度 $O(n \times |\Sigma|^2)$，其中 $n$ 是字符串长度，而 $|\Sigma|$ 是字符集大小。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def largestVariance(self, s: str) -> int:
        ans = 0
        for a, b in permutations(ascii_lowercase, 2):
            if a == b:
                continue
            f = [0, -inf]
            for c in s:
                if c == a:
                    f[0], f[1] = f[0] + 1, f[1] + 1
                elif c == b:
                    f[1] = max(f[1] - 1, f[0] - 1)
                    f[0] = 0
                if ans < f[1]:
                    ans = f[1]
        return ans
```

#### Java

```java
class Solution {
    public int largestVariance(String s) {
        int n = s.length();
        int ans = 0;
        for (char a = 'a'; a <= 'z'; ++a) {
            for (char b = 'a'; b <= 'z'; ++b) {
                if (a == b) {
                    continue;
                }
                int[] f = new int[] {0, -n};
                for (int i = 0; i < n; ++i) {
                    if (s.charAt(i) == a) {
                        f[0]++;
                        f[1]++;
                    } else if (s.charAt(i) == b) {
                        f[1] = Math.max(f[0] - 1, f[1] - 1);
                        f[0] = 0;
                    }
                    ans = Math.max(ans, f[1]);
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
    int largestVariance(string s) {
        int n = s.size();
        int ans = 0;
        for (char a = 'a'; a <= 'z'; ++a) {
            for (char b = 'a'; b <= 'z'; ++b) {
                if (a == b) {
                    continue;
                }
                int f[2] = {0, -n};
                for (char c : s) {
                    if (c == a) {
                        f[0]++;
                        f[1]++;
                    } else if (c == b) {
                        f[1] = max(f[1] - 1, f[0] - 1);
                        f[0] = 0;
                    }
                    ans = max(ans, f[1]);
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func largestVariance(s string) int {
	ans, n := 0, len(s)
	for a := 'a'; a <= 'z'; a++ {
		for b := 'a'; b <= 'z'; b++ {
			if a == b {
				continue
			}
			f := [2]int{0, -n}
			for _, c := range s {
				if c == a {
					f[0]++
					f[1]++
				} else if c == b {
					f[1] = max(f[1]-1, f[0]-1)
					f[0] = 0
				}
				ans = max(ans, f[1])
			}
		}
	}
	return ans
}
```

#### TypeScript

```ts
function largestVariance(s: string): number {
    const n: number = s.length;
    let ans: number = 0;
    for (let a = 97; a <= 122; ++a) {
        for (let b = 97; b <= 122; ++b) {
            if (a === b) {
                continue;
            }
            const f: number[] = [0, -n];
            for (let i = 0; i < n; ++i) {
                if (s.charCodeAt(i) === a) {
                    f[0]++;
                    f[1]++;
                } else if (s.charCodeAt(i) === b) {
                    f[1] = Math.max(f[0] - 1, f[1] - 1);
                    f[0] = 0;
                }
                ans = Math.max(ans, f[1]);
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

# [2273. 移除字母异位词后的结果数组](https://leetcode.cn/problems/find-resultant-array-after-removing-anagrams){#2273}

{{< tabs "2273" >}}

{{% tab "python" %}}
```python
class Solution:
    def removeAnagrams(self, words: List[str]) -> List[str]:
        def check(s: str, t: str) -> bool:
            if len(s) != len(t):
                return True
            cnt = Counter(s)
            for c in t:
                cnt[c] -= 1
                if cnt[c] < 0:
                    return True
            return False

        return [words[0]] + [t for s, t in pairwise(words) if check(s, t)]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<String> removeAnagrams(String[] words) {
        List<String> ans = new ArrayList<>();
        ans.add(words[0]);
        for (int i = 1; i < words.length; ++i) {
            if (check(words[i - 1], words[i])) {
                ans.add(words[i]);
            }
        }
        return ans;
    }

    private boolean check(String s, String t) {
        if (s.length() != t.length()) {
            return true;
        }
        int[] cnt = new int[26];
        for (int i = 0; i < s.length(); ++i) {
            ++cnt[s.charAt(i) - 'a'];
        }
        for (int i = 0; i < t.length(); ++i) {
            if (--cnt[t.charAt(i) - 'a'] < 0) {
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
    vector<string> removeAnagrams(vector<string>& words) {
        auto check = [](string& s, string& t) -> bool {
            if (s.size() != t.size()) {
                return true;
            }
            int cnt[26]{};
            for (char& c : s) {
                ++cnt[c - 'a'];
            }
            for (char& c : t) {
                if (--cnt[c - 'a'] < 0) {
                    return true;
                }
            }
            return false;
        };

        vector<string> ans = {words[0]};
        for (int i = 1; i < words.size(); ++i) {
            if (check(words[i - 1], words[i])) {
                ans.emplace_back(words[i]);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func removeAnagrams(words []string) []string {
	ans := []string{words[0]}
	check := func(s, t string) bool {
		if len(s) != len(t) {
			return true
		}
		cnt := [26]int{}
		for _, c := range s {
			cnt[c-'a']++
		}
		for _, c := range t {
			cnt[c-'a']--
			if cnt[c-'a'] < 0 {
				return true
			}
		}
		return false
	}
	for i, t := range words[1:] {
		if check(words[i], t) {
			ans = append(ans, t)
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function removeAnagrams(words: string[]): string[] {
    const ans: string[] = [words[0]];
    const check = (s: string, t: string): boolean => {
        if (s.length !== t.length) {
            return true;
        }
        const cnt: number[] = Array(26).fill(0);
        for (const c of s) {
            ++cnt[c.charCodeAt(0) - 97];
        }
        for (const c of t) {
            if (--cnt[c.charCodeAt(0) - 97] < 0) {
                return true;
            }
        }
        return false;
    };
    for (let i = 1; i < words.length; ++i) {
        if (check(words[i - 1], words[i])) {
            ans.push(words[i]);
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

<p>给你一个下标从 <strong>0</strong> 开始的字符串 <code>words</code> ，其中 <code>words[i]</code> 由小写英文字符组成。</p>

<p>在一步操作中，需要选出任一下标 <code>i</code> ，从 <code>words</code> 中 <strong>删除</strong> <code>words[i]</code> 。其中下标 <code>i</code> 需要同时满足下述两个条件：</p>

<ol>
	<li><code>0 &lt; i &lt; words.length</code></li>
	<li><code>words[i - 1]</code> 和 <code>words[i]</code> 是 <strong>字母异位词</strong> 。</li>
</ol>

<p>只要可以选出满足条件的下标，就一直执行这个操作。</p>

<p>在执行所有操作后，返回 <code>words</code> 。可以证明，按任意顺序为每步操作选择下标都会得到相同的结果。</p>

<p><strong>字母异位词</strong> 是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母通常恰好只用一次。例如，<code>"dacb"</code> 是 <code>"abdc"</code> 的一个字母异位词。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>words = ["abba","baba","bbaa","cd","cd"]
<strong>输出：</strong>["abba","cd"]
<strong>解释：</strong>
获取结果数组的方法之一是执行下述步骤：
- 由于 words[2] = "bbaa" 和 words[1] = "baba" 是字母异位词，选择下标 2 并删除 words[2] 。
  现在 words = ["abba","baba","cd","cd"] 。
- 由于 words[1] = "baba" 和 words[0] = "abba" 是字母异位词，选择下标 1 并删除 words[1] 。
  现在 words = ["abba","cd","cd"] 。
- 由于 words[2] = "cd" 和 words[1] = "cd" 是字母异位词，选择下标 2 并删除 words[2] 。
  现在 words = ["abba","cd"] 。
无法再执行任何操作，所以 ["abba","cd"] 是最终答案。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>words = ["a","b","c","d","e"]
<strong>输出：</strong>["a","b","c","d","e"]
<strong>解释：</strong>
words 中不存在互为字母异位词的两个相邻字符串，所以无需执行任何操作。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 10</code></li>
	<li><code>words[i]</code> 由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们首先将 $\textit{words}[0]$ 加入答案数组，然后从 $\textit{words}[1]$ 开始遍历，如果 $\textit{words}[i - 1]$ 和 $\textit{words}[i]$ 不是字母异位词，我们就将 $\textit{words}[i]$ 加入答案数组。

问题转换为判断两个字符串是否是字母异位词，我们定义一个辅助函数 $\textit{check}(s, t)$ 来实现这个功能。如果 $s$ 和 $t$ 不是字母异位词，我们就返回 $\text{true}$，否则返回 $\text{false}$。

在函数 $\textit{check}(s, t)$ 中，我们首先判断 $s$ 和 $t$ 的长度是否相等，如果不相等，我们就返回 $\text{true}$。否则，我们用一个长度为 $26$ 的数组 $\textit{cnt}$ 来统计 $s$ 中每个字符出现的次数，然后遍历 $t$ 中的每个字符，将 $\textit{cnt}[c]$ 减 $1$，如果 $\textit{cnt}[c]$ 小于 $0$，我们就返回 $\text{true}$。如果正常遍历完 $t$ 中的每个字符，说明 $s$ 和 $t$ 是字母异位词，我们返回 $\text{false}$。

时间复杂度 $O(L)$，空间复杂度 $O(|\Sigma|)$。其中 $L$ 是数组 $\textit{words}$ 的长度，而 $\Sigma$ 是字符集，这里是小写英文字母，所以 $|\Sigma| = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def removeAnagrams(self, words: List[str]) -> List[str]:
        def check(s: str, t: str) -> bool:
            if len(s) != len(t):
                return True
            cnt = Counter(s)
            for c in t:
                cnt[c] -= 1
                if cnt[c] < 0:
                    return True
            return False

        return [words[0]] + [t for s, t in pairwise(words) if check(s, t)]
```

#### Java

```java
class Solution {
    public List<String> removeAnagrams(String[] words) {
        List<String> ans = new ArrayList<>();
        ans.add(words[0]);
        for (int i = 1; i < words.length; ++i) {
            if (check(words[i - 1], words[i])) {
                ans.add(words[i]);
            }
        }
        return ans;
    }

    private boolean check(String s, String t) {
        if (s.length() != t.length()) {
            return true;
        }
        int[] cnt = new int[26];
        for (int i = 0; i < s.length(); ++i) {
            ++cnt[s.charAt(i) - 'a'];
        }
        for (int i = 0; i < t.length(); ++i) {
            if (--cnt[t.charAt(i) - 'a'] < 0) {
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
    vector<string> removeAnagrams(vector<string>& words) {
        auto check = [](string& s, string& t) -> bool {
            if (s.size() != t.size()) {
                return true;
            }
            int cnt[26]{};
            for (char& c : s) {
                ++cnt[c - 'a'];
            }
            for (char& c : t) {
                if (--cnt[c - 'a'] < 0) {
                    return true;
                }
            }
            return false;
        };

        vector<string> ans = {words[0]};
        for (int i = 1; i < words.size(); ++i) {
            if (check(words[i - 1], words[i])) {
                ans.emplace_back(words[i]);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func removeAnagrams(words []string) []string {
	ans := []string{words[0]}
	check := func(s, t string) bool {
		if len(s) != len(t) {
			return true
		}
		cnt := [26]int{}
		for _, c := range s {
			cnt[c-'a']++
		}
		for _, c := range t {
			cnt[c-'a']--
			if cnt[c-'a'] < 0 {
				return true
			}
		}
		return false
	}
	for i, t := range words[1:] {
		if check(words[i], t) {
			ans = append(ans, t)
		}
	}
	return ans
}
```

#### TypeScript

```ts
function removeAnagrams(words: string[]): string[] {
    const ans: string[] = [words[0]];
    const check = (s: string, t: string): boolean => {
        if (s.length !== t.length) {
            return true;
        }
        const cnt: number[] = Array(26).fill(0);
        for (const c of s) {
            ++cnt[c.charCodeAt(0) - 97];
        }
        for (const c of t) {
            if (--cnt[c.charCodeAt(0) - 97] < 0) {
                return true;
            }
        }
        return false;
    };
    for (let i = 1; i < words.length; ++i) {
        if (check(words[i - 1], words[i])) {
            ans.push(words[i]);
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

# [2274. 不含特殊楼层的最大连续楼层数](https://leetcode.cn/problems/maximum-consecutive-floors-without-special-floors){#2274}

{{< tabs "2274" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxConsecutive(self, bottom: int, top: int, special: List[int]) -> int:
        special.sort()
        ans = max(special[0] - bottom, top - special[-1])
        for x, y in pairwise(special):
            ans = max(ans, y - x - 1)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxConsecutive(int bottom, int top, int[] special) {
        Arrays.sort(special);
        int n = special.length;
        int ans = Math.max(special[0] - bottom, top - special[n - 1]);
        for (int i = 1; i < n; ++i) {
            ans = Math.max(ans, special[i] - special[i - 1] - 1);
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
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        ranges::sort(special);
        int ans = max(special[0] - bottom, top - special.back());
        for (int i = 1; i < special.size(); ++i) {
            ans = max(ans, special[i] - special[i - 1] - 1);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxConsecutive(bottom int, top int, special []int) int {
	sort.Ints(special)
	ans := max(special[0]-bottom, top-special[len(special)-1])
	for i, x := range special[1:] {
		ans = max(ans, x-special[i]-1)
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxConsecutive(bottom: number, top: number, special: number[]): number {
    special.sort((a, b) => a - b);
    const n = special.length;
    let ans = Math.max(special[0] - bottom, top - special[n - 1]);
    for (let i = 1; i < n; ++i) {
        ans = Math.max(ans, special[i] - special[i - 1] - 1);
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

<p>Alice 管理着一家公司，并租用大楼的部分楼层作为办公空间。Alice 决定将一些楼层作为 <strong>特殊楼层</strong> ，仅用于放松。</p>

<p>给你两个整数 <code>bottom</code> 和 <code>top</code> ，表示 Alice 租用了从 <code>bottom</code> 到 <code>top</code>（含 <code>bottom</code> 和 <code>top</code> 在内）的所有楼层。另给你一个整数数组 <code>special</code> ，其中 <code>special[i]</code> 表示&nbsp; Alice 指定用于放松的特殊楼层。</p>

<p>返回不含特殊楼层的 <strong>最大</strong> 连续楼层数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>bottom = 2, top = 9, special = [4,6]
<strong>输出：</strong>3
<strong>解释：</strong>下面列出的是不含特殊楼层的连续楼层范围：
- (2, 3) ，楼层数为 2 。
- (5, 5) ，楼层数为 1 。
- (7, 9) ，楼层数为 3 。
因此，返回最大连续楼层数 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>bottom = 6, top = 8, special = [7,6,8]
<strong>输出：</strong>0
<strong>解释：</strong>每层楼都被规划为特殊楼层，所以返回 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示</strong></p>

<ul>
	<li><code>1 &lt;= special.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= bottom &lt;= special[i] &lt;= top &lt;= 10<sup>9</sup></code></li>
	<li><code>special</code> 中的所有值 <strong>互不相同</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序

我们可以将特殊楼层按照升序排序，然后计算相邻两个特殊楼层之间的楼层数，最后再计算第一个特殊楼层和 $\textit{bottom}$ 之间的楼层数，以及最后一个特殊楼层和 $\textit{top}$ 之间的楼层数，取这些楼层数的最大值即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 是数组 $\textit{special}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxConsecutive(self, bottom: int, top: int, special: List[int]) -> int:
        special.sort()
        ans = max(special[0] - bottom, top - special[-1])
        for x, y in pairwise(special):
            ans = max(ans, y - x - 1)
        return ans
```

#### Java

```java
class Solution {
    public int maxConsecutive(int bottom, int top, int[] special) {
        Arrays.sort(special);
        int n = special.length;
        int ans = Math.max(special[0] - bottom, top - special[n - 1]);
        for (int i = 1; i < n; ++i) {
            ans = Math.max(ans, special[i] - special[i - 1] - 1);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        ranges::sort(special);
        int ans = max(special[0] - bottom, top - special.back());
        for (int i = 1; i < special.size(); ++i) {
            ans = max(ans, special[i] - special[i - 1] - 1);
        }
        return ans;
    }
};
```

#### Go

```go
func maxConsecutive(bottom int, top int, special []int) int {
	sort.Ints(special)
	ans := max(special[0]-bottom, top-special[len(special)-1])
	for i, x := range special[1:] {
		ans = max(ans, x-special[i]-1)
	}
	return ans
}
```

#### TypeScript

```ts
function maxConsecutive(bottom: number, top: number, special: number[]): number {
    special.sort((a, b) => a - b);
    const n = special.length;
    let ans = Math.max(special[0] - bottom, top - special[n - 1]);
    for (let i = 1; i < n; ++i) {
        ans = Math.max(ans, special[i] - special[i - 1] - 1);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2275. 按位与结果大于零的最长组合](https://leetcode.cn/problems/largest-combination-with-bitwise-and-greater-than-zero){#2275}

{{< tabs "2275" >}}

{{% tab "python" %}}
```python
class Solution:
    def largestCombination(self, candidates: List[int]) -> int:
        ans = 0
        for i in range(max(candidates).bit_length()):
            ans = max(ans, sum(x >> i & 1 for x in candidates))
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int largestCombination(int[] candidates) {
        int mx = Arrays.stream(candidates).max().getAsInt();
        int m = Integer.SIZE - Integer.numberOfLeadingZeros(mx);
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            int cnt = 0;
            for (int x : candidates) {
                cnt += x >> i & 1;
            }
            ans = Math.max(ans, cnt);
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
    int largestCombination(vector<int>& candidates) {
        int mx = *max_element(candidates.begin(), candidates.end());
        int m = 32 - __builtin_clz(mx);
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            int cnt = 0;
            for (int x : candidates) {
                cnt += x >> i & 1;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func largestCombination(candidates []int) (ans int) {
	mx := slices.Max(candidates)
	m := bits.Len(uint(mx))
	for i := 0; i < m; i++ {
		cnt := 0
		for _, x := range candidates {
			cnt += (x >> i) & 1
		}
		ans = max(ans, cnt)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function largestCombination(candidates: number[]): number {
    const mx = Math.max(...candidates);
    const m = mx.toString(2).length;
    let ans = 0;
    for (let i = 0; i < m; ++i) {
        let cnt = 0;
        for (const x of candidates) {
            cnt += (x >> i) & 1;
        }
        ans = Math.max(ans, cnt);
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

<p>对数组&nbsp;<code>nums</code> 执行 <strong>按位与</strong> 相当于对数组&nbsp;<code>nums</code> 中的所有整数执行 <strong>按位与</strong> 。</p>

<ul>
	<li>例如，对 <code>nums = [1, 5, 3]</code> 来说，按位与等于 <code>1 &amp; 5 &amp; 3 = 1</code> 。</li>
	<li>同样，对 <code>nums = [7]</code> 而言，按位与等于 <code>7</code> 。</li>
</ul>

<p>给你一个正整数数组 <code>candidates</code> 。计算 <code>candidates</code> 中的数字每种组合下 <strong>按位与</strong> 的结果。</p>

<p>返回按位与结果大于 <code>0</code> 的 <strong>最长</strong> 组合的长度<em>。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>candidates = [16,17,71,62,12,24,14]
<strong>输出：</strong>4
<strong>解释：</strong>组合 [16,17,62,24] 的按位与结果是 16 &amp; 17 &amp; 62 &amp; 24 = 16 &gt; 0 。
组合长度是 4 。
可以证明不存在按位与结果大于 0 且长度大于 4 的组合。
注意，符合长度最大的组合可能不止一种。
例如，组合 [62,12,24,14] 的按位与结果是 62 &amp; 12 &amp; 24 &amp; 14 = 8 &gt; 0 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>candidates = [8,8]
<strong>输出：</strong>2
<strong>解释：</strong>最长组合是 [8,8] ，按位与结果 8 &amp; 8 = 8 &gt; 0 。
组合长度是 2 ，所以返回 2 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= candidates.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= candidates[i] &lt;= 10<sup>7</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：位运算

题目需要找到按位与结果大于 $0$ 的数字组合的最大长度，那么说明一定存在某个二进制位，所有数字在这个二进制位上都是 $1$。因此，我们可以枚举每个二进制位，统计所有数字在这个二进制位上的 $1$ 的个数，最后取最大值即可。

时间复杂度 $O(n \times \log M)$，其中 $n$ 和 $M$ 分别是数组 $\textit{candidates}$ 的长度和数组中的最大值。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def largestCombination(self, candidates: List[int]) -> int:
        ans = 0
        for i in range(max(candidates).bit_length()):
            ans = max(ans, sum(x >> i & 1 for x in candidates))
        return ans
```

#### Java

```java
class Solution {
    public int largestCombination(int[] candidates) {
        int mx = Arrays.stream(candidates).max().getAsInt();
        int m = Integer.SIZE - Integer.numberOfLeadingZeros(mx);
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            int cnt = 0;
            for (int x : candidates) {
                cnt += x >> i & 1;
            }
            ans = Math.max(ans, cnt);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int mx = *max_element(candidates.begin(), candidates.end());
        int m = 32 - __builtin_clz(mx);
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            int cnt = 0;
            for (int x : candidates) {
                cnt += x >> i & 1;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
```

#### Go

```go
func largestCombination(candidates []int) (ans int) {
	mx := slices.Max(candidates)
	m := bits.Len(uint(mx))
	for i := 0; i < m; i++ {
		cnt := 0
		for _, x := range candidates {
			cnt += (x >> i) & 1
		}
		ans = max(ans, cnt)
	}
	return
}
```

#### TypeScript

```ts
function largestCombination(candidates: number[]): number {
    const mx = Math.max(...candidates);
    const m = mx.toString(2).length;
    let ans = 0;
    for (let i = 0; i < m; ++i) {
        let cnt = 0;
        for (const x of candidates) {
            cnt += (x >> i) & 1;
        }
        ans = Math.max(ans, cnt);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2276. 统计区间中的整数数目](https://leetcode.cn/problems/count-integers-in-intervals){#2276}

{{< tabs "2276" >}}

{{% tab "python" %}}
```python
class Node:
    __slots__ = ("left", "right", "l", "r", "mid", "v", "add")

    def __init__(self, l, r):
        self.left = None
        self.right = None
        self.l = l
        self.r = r
        self.mid = (l + r) // 2
        self.v = 0
        self.add = 0


class SegmentTree:
    def __init__(self):
        self.root = Node(1, int(1e9) + 1)

    def modify(self, l, r, v, node=None):
        if node is None:
            node = self.root
        if l > r:
            return
        if node.l >= l and node.r <= r:
            node.v = node.r - node.l + 1
            node.add = v
            return
        self.pushdown(node)
        if l <= node.mid:
            self.modify(l, r, v, node.left)
        if r > node.mid:
            self.modify(l, r, v, node.right)
        self.pushup(node)

    def query(self, l, r, node=None):
        if node is None:
            node = self.root
        if l > r:
            return 0
        if node.l >= l and node.r <= r:
            return node.v
        self.pushdown(node)
        v = 0
        if l <= node.mid:
            v += self.query(l, r, node.left)
        if r > node.mid:
            v += self.query(l, r, node.right)
        return v

    def pushup(self, node):
        node.v = node.left.v + node.right.v

    def pushdown(self, node):
        if node.left is None:
            node.left = Node(node.l, node.mid)
        if node.right is None:
            node.right = Node(node.mid + 1, node.r)
        if node.add != 0:
            left, right = node.left, node.right
            left.add = node.add
            right.add = node.add
            left.v = left.r - left.l + 1
            right.v = right.r - right.l + 1
            node.add = 0


class CountIntervals:
    def __init__(self):
        self.tree = SegmentTree()

    def add(self, left, right):
        self.tree.modify(left, right, 1)

    def count(self):
        return self.tree.query(1, int(1e9))


# Your CountIntervals object will be instantiated and called as such:
# obj = CountIntervals()
# obj.add(left, right)
# param_2 = obj.count()
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Node {
    Node left;
    Node right;
    int l;
    int r;
    int mid;
    int v;
    int add;

    public Node(int l, int r) {
        this.l = l;
        this.r = r;
        this.mid = (l + r) >> 1;
    }
}

class SegmentTree {
    private Node root = new Node(1, (int) 1e9 + 1);

    public SegmentTree() {
    }

    public void modify(int l, int r, int v) {
        modify(l, r, v, root);
    }

    public void modify(int l, int r, int v, Node node) {
        if (l > r) {
            return;
        }
        if (node.l >= l && node.r <= r) {
            node.v = node.r - node.l + 1;
            node.add = v;
            return;
        }
        pushdown(node);
        if (l <= node.mid) {
            modify(l, r, v, node.left);
        }
        if (r > node.mid) {
            modify(l, r, v, node.right);
        }
        pushup(node);
    }

    public int query(int l, int r) {
        return query(l, r, root);
    }

    public int query(int l, int r, Node node) {
        if (l > r) {
            return 0;
        }
        if (node.l >= l && node.r <= r) {
            return node.v;
        }
        pushdown(node);
        int v = 0;
        if (l <= node.mid) {
            v += query(l, r, node.left);
        }
        if (r > node.mid) {
            v += query(l, r, node.right);
        }
        return v;
    }

    public void pushup(Node node) {
        node.v = node.left.v + node.right.v;
    }

    public void pushdown(Node node) {
        if (node.left == null) {
            node.left = new Node(node.l, node.mid);
        }
        if (node.right == null) {
            node.right = new Node(node.mid + 1, node.r);
        }
        if (node.add != 0) {
            Node left = node.left, right = node.right;
            left.add = node.add;
            right.add = node.add;
            left.v = left.r - left.l + 1;
            right.v = right.r - right.l + 1;
            node.add = 0;
        }
    }
}

class CountIntervals {
    private SegmentTree tree = new SegmentTree();

    public CountIntervals() {
    }

    public void add(int left, int right) {
        tree.modify(left, right, 1);
    }

    public int count() {
        return tree.query(1, (int) 1e9);
    }
}

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals obj = new CountIntervals();
 * obj.add(left,right);
 * int param_2 = obj.count();
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Node {
public:
    Node(int l, int r)
        : l(l)
        , r(r)
        , mid((l + r) / 2)
        , v(0)
        , add(0)
        , left(nullptr)
        , right(nullptr) {}

    int l, r, mid, v, add;
    Node* left;
    Node* right;
};

class SegmentTree {
public:
    SegmentTree()
        : root(new Node(1, 1000000001)) {}

    void modify(int l, int r, int v, Node* node = nullptr) {
        if (node == nullptr) {
            node = root;
        }
        if (l > r) {
            return;
        }
        if (node->l >= l && node->r <= r) {
            node->v = node->r - node->l + 1;
            node->add = v;
            return;
        }
        pushdown(node);
        if (l <= node->mid) {
            modify(l, r, v, node->left);
        }
        if (r > node->mid) {
            modify(l, r, v, node->right);
        }
        pushup(node);
    }

    int query(int l, int r, Node* node = nullptr) {
        if (node == nullptr) {
            node = root;
        }
        if (l > r) {
            return 0;
        }
        if (node->l >= l && node->r <= r) {
            return node->v;
        }
        pushdown(node);
        int v = 0;
        if (l <= node->mid) {
            v += query(l, r, node->left);
        }
        if (r > node->mid) {
            v += query(l, r, node->right);
        }
        return v;
    }

private:
    Node* root;

    void pushup(Node* node) {
        node->v = node->left->v + node->right->v;
    }

    void pushdown(Node* node) {
        if (node->left == nullptr) {
            node->left = new Node(node->l, node->mid);
        }
        if (node->right == nullptr) {
            node->right = new Node(node->mid + 1, node->r);
        }
        if (node->add != 0) {
            Node* left = node->left;
            Node* right = node->right;
            left->add = node->add;
            right->add = node->add;
            left->v = left->r - left->l + 1;
            right->v = right->r - right->l + 1;
            node->add = 0;
        }
    }
};

class CountIntervals {
public:
    CountIntervals() {}

    void add(int left, int right) {
        tree.modify(left, right, 1);
    }

    int count() {
        return tree.query(1, 1000000000);
    }

private:
    SegmentTree tree;
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Node struct {
	left  *Node
	right *Node
	l     int
	r     int
	mid   int
	v     int
	add   int
}

type SegmentTree struct {
	root *Node
}

func newNode(l, r int) *Node {
	return &Node{
		left:  nil,
		right: nil,
		l:     l,
		r:     r,
		mid:   (l + r) / 2,
		v:     0,
		add:   0,
	}
}

func newSegmentTree() *SegmentTree {
	return &SegmentTree{
		root: newNode(1, 1000000001),
	}
}

func (st *SegmentTree) modify(l, r, v int, node *Node) {
	if node == nil {
		node = st.root
	}
	if l > r {
		return
	}
	if node.l >= l && node.r <= r {
		node.v = node.r - node.l + 1
		node.add = v
		return
	}
	st.pushdown(node)
	if l <= node.mid {
		st.modify(l, r, v, node.left)
	}
	if r > node.mid {
		st.modify(l, r, v, node.right)
	}
	st.pushup(node)
}

func (st *SegmentTree) query(l, r int, node *Node) int {
	if node == nil {
		node = st.root
	}
	if l > r {
		return 0
	}
	if node.l >= l && node.r <= r {
		return node.v
	}
	st.pushdown(node)
	v := 0
	if l <= node.mid {
		v += st.query(l, r, node.left)
	}
	if r > node.mid {
		v += st.query(l, r, node.right)
	}
	return v
}

func (st *SegmentTree) pushup(node *Node) {
	node.v = node.left.v + node.right.v
}

func (st *SegmentTree) pushdown(node *Node) {
	if node.left == nil {
		node.left = newNode(node.l, node.mid)
	}
	if node.right == nil {
		node.right = newNode(node.mid+1, node.r)
	}
	if node.add != 0 {
		left := node.left
		right := node.right
		left.add = node.add
		right.add = node.add
		left.v = left.r - left.l + 1
		right.v = right.r - right.l + 1
		node.add = 0
	}
}

type CountIntervals struct {
	tree *SegmentTree
}

func Constructor() CountIntervals {
	return CountIntervals{
		tree: newSegmentTree(),
	}
}

func (ci *CountIntervals) Add(left, right int) {
	ci.tree.modify(left, right, 1, nil)
}

func (ci *CountIntervals) Count() int {
	return ci.tree.query(1, 1000000000, nil)
}

/**
 * Your CountIntervals object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Add(left,right);
 * param_2 := obj.Count();
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class CountIntervals {
    left: null | CountIntervals;
    right: null | CountIntervals;
    start: number;
    end: number;
    sum: number;
    constructor(start: number = 0, end: number = 10 ** 9) {
        this.left = null;
        this.right = null;
        this.start = start;
        this.end = end;
        this.sum = 0;
    }

    add(left: number, right: number): void {
        if (this.sum == this.end - this.start + 1) return;
        if (left <= this.start && right >= this.end) {
            this.sum = this.end - this.start + 1;
            return;
        }
        let mid = (this.start + this.end) >> 1;
        if (!this.left) this.left = new CountIntervals(this.start, mid);
        if (!this.right) this.right = new CountIntervals(mid + 1, this.end);
        if (left <= mid) this.left.add(left, right);
        if (right > mid) this.right.add(left, right);
        this.sum = this.left.sum + this.right.sum;
    }

    count(): number {
        return this.sum;
    }
}

/**
 * Your CountIntervals object will be instantiated and called as such:
 * var obj = new CountIntervals()
 * obj.add(left,right)
 * var param_2 = obj.count()
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你区间的 <strong>空</strong> 集，请你设计并实现满足要求的数据结构：</p>

<ul>
	<li><strong>新增：</strong>添加一个区间到这个区间集合中。</li>
	<li><strong>统计：</strong>计算出现在 <strong>至少一个</strong> 区间中的整数个数。</li>
</ul>

<p>实现 <code>CountIntervals</code> 类：</p>

<ul>
	<li><code>CountIntervals()</code> 使用区间的空集初始化对象</li>
	<li><code>void add(int left, int right)</code> 添加区间 <code>[left, right]</code> 到区间集合之中。</li>
	<li><code>int count()</code> 返回出现在 <strong>至少一个</strong> 区间中的整数个数。</li>
</ul>

<p><strong>注意：</strong>区间 <code>[left, right]</code> 表示满足 <code>left &lt;= x &lt;= right</code> 的所有整数 <code>x</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入</strong>
["CountIntervals", "add", "add", "count", "add", "count"]
[[], [2, 3], [7, 10], [], [5, 8], []]
<strong>输出</strong>
[null, null, null, 6, null, 8]

<strong>解释</strong>
CountIntervals countIntervals = new CountIntervals(); // 用一个区间空集初始化对象
countIntervals.add(2, 3);  // 将 [2, 3] 添加到区间集合中
countIntervals.add(7, 10); // 将 [7, 10] 添加到区间集合中
countIntervals.count();    // 返回 6
                           // 整数 2 和 3 出现在区间 [2, 3] 中
                           // 整数 7、8、9、10 出现在区间 [7, 10] 中
countIntervals.add(5, 8);  // 将 [5, 8] 添加到区间集合中
countIntervals.count();    // 返回 8
                           // 整数 2 和 3 出现在区间 [2, 3] 中
                           // 整数 5 和 6 出现在区间 [5, 8] 中
                           // 整数 7 和 8 出现在区间 [5, 8] 和区间 [7, 10] 中
                           // 整数 9 和 10 出现在区间 [7, 10] 中</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= left &lt;= right &lt;= 10<sup>9</sup></code></li>
	<li>最多调用&nbsp; <code>add</code> 和 <code>count</code> 方法 <strong>总计</strong> <code>10<sup>5</sup></code> 次</li>
	<li>调用 <code>count</code> 方法至少一次</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：线段树（动态开点）

根据题目描述，我们需要维护一个区间集合，支持区间的添加和查询操作。对于区间的添加，我们可以使用线段树来维护区间集合。

线段树将整个区间分割为多个不连续的子区间，子区间的数量不超过 $\log(width)$。更新某个元素的值，只需要更新 $\log(width)$ 个区间，并且这些区间都包含在一个包含该元素的大区间内。区间修改时，需要使用**懒标记**保证效率。

-   线段树的每个节点代表一个区间；
-   线段树具有唯一的根节点，代表的区间是整个统计范围，如 $[1,N]$；
-   线段树的每个叶子节点代表一个长度为 $1$ 的元区间 $[x,x]$；
-   对于每个内部节点 $[l,r]$，它的左儿子是 $[l,mid]$，右儿子是 $[mid+1,r]$, 其中 $mid=⌊(l+r)/2⌋$ (即向下取整)。

由于题目数据范围较大，我们可以使用动态开点的线段树来实现。动态开点的线段树是指，我们只在需要的时候才开点，而不是一开始就开好所有的点，这样可以节省空间。

时间复杂度方面，每次操作的时间复杂度为 $O(\log n)$。空间复杂度为 $O(m \times \log n)$。其中 $m$ 为操作次数，而 $n$ 为数据范围。

<!-- tabs:start -->

#### Python3

```python
class Node:
    __slots__ = ("left", "right", "l", "r", "mid", "v", "add")

    def __init__(self, l, r):
        self.left = None
        self.right = None
        self.l = l
        self.r = r
        self.mid = (l + r) // 2
        self.v = 0
        self.add = 0


class SegmentTree:
    def __init__(self):
        self.root = Node(1, int(1e9) + 1)

    def modify(self, l, r, v, node=None):
        if node is None:
            node = self.root
        if l > r:
            return
        if node.l >= l and node.r <= r:
            node.v = node.r - node.l + 1
            node.add = v
            return
        self.pushdown(node)
        if l <= node.mid:
            self.modify(l, r, v, node.left)
        if r > node.mid:
            self.modify(l, r, v, node.right)
        self.pushup(node)

    def query(self, l, r, node=None):
        if node is None:
            node = self.root
        if l > r:
            return 0
        if node.l >= l and node.r <= r:
            return node.v
        self.pushdown(node)
        v = 0
        if l <= node.mid:
            v += self.query(l, r, node.left)
        if r > node.mid:
            v += self.query(l, r, node.right)
        return v

    def pushup(self, node):
        node.v = node.left.v + node.right.v

    def pushdown(self, node):
        if node.left is None:
            node.left = Node(node.l, node.mid)
        if node.right is None:
            node.right = Node(node.mid + 1, node.r)
        if node.add != 0:
            left, right = node.left, node.right
            left.add = node.add
            right.add = node.add
            left.v = left.r - left.l + 1
            right.v = right.r - right.l + 1
            node.add = 0


class CountIntervals:
    def __init__(self):
        self.tree = SegmentTree()

    def add(self, left, right):
        self.tree.modify(left, right, 1)

    def count(self):
        return self.tree.query(1, int(1e9))


# Your CountIntervals object will be instantiated and called as such:
# obj = CountIntervals()
# obj.add(left, right)
# param_2 = obj.count()
```

#### Java

```java
class Node {
    Node left;
    Node right;
    int l;
    int r;
    int mid;
    int v;
    int add;

    public Node(int l, int r) {
        this.l = l;
        this.r = r;
        this.mid = (l + r) >> 1;
    }
}

class SegmentTree {
    private Node root = new Node(1, (int) 1e9 + 1);

    public SegmentTree() {
    }

    public void modify(int l, int r, int v) {
        modify(l, r, v, root);
    }

    public void modify(int l, int r, int v, Node node) {
        if (l > r) {
            return;
        }
        if (node.l >= l && node.r <= r) {
            node.v = node.r - node.l + 1;
            node.add = v;
            return;
        }
        pushdown(node);
        if (l <= node.mid) {
            modify(l, r, v, node.left);
        }
        if (r > node.mid) {
            modify(l, r, v, node.right);
        }
        pushup(node);
    }

    public int query(int l, int r) {
        return query(l, r, root);
    }

    public int query(int l, int r, Node node) {
        if (l > r) {
            return 0;
        }
        if (node.l >= l && node.r <= r) {
            return node.v;
        }
        pushdown(node);
        int v = 0;
        if (l <= node.mid) {
            v += query(l, r, node.left);
        }
        if (r > node.mid) {
            v += query(l, r, node.right);
        }
        return v;
    }

    public void pushup(Node node) {
        node.v = node.left.v + node.right.v;
    }

    public void pushdown(Node node) {
        if (node.left == null) {
            node.left = new Node(node.l, node.mid);
        }
        if (node.right == null) {
            node.right = new Node(node.mid + 1, node.r);
        }
        if (node.add != 0) {
            Node left = node.left, right = node.right;
            left.add = node.add;
            right.add = node.add;
            left.v = left.r - left.l + 1;
            right.v = right.r - right.l + 1;
            node.add = 0;
        }
    }
}

class CountIntervals {
    private SegmentTree tree = new SegmentTree();

    public CountIntervals() {
    }

    public void add(int left, int right) {
        tree.modify(left, right, 1);
    }

    public int count() {
        return tree.query(1, (int) 1e9);
    }
}

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals obj = new CountIntervals();
 * obj.add(left,right);
 * int param_2 = obj.count();
 */
```

#### C++

```cpp
class Node {
public:
    Node(int l, int r)
        : l(l)
        , r(r)
        , mid((l + r) / 2)
        , v(0)
        , add(0)
        , left(nullptr)
        , right(nullptr) {}

    int l, r, mid, v, add;
    Node* left;
    Node* right;
};

class SegmentTree {
public:
    SegmentTree()
        : root(new Node(1, 1000000001)) {}

    void modify(int l, int r, int v, Node* node = nullptr) {
        if (node == nullptr) {
            node = root;
        }
        if (l > r) {
            return;
        }
        if (node->l >= l && node->r <= r) {
            node->v = node->r - node->l + 1;
            node->add = v;
            return;
        }
        pushdown(node);
        if (l <= node->mid) {
            modify(l, r, v, node->left);
        }
        if (r > node->mid) {
            modify(l, r, v, node->right);
        }
        pushup(node);
    }

    int query(int l, int r, Node* node = nullptr) {
        if (node == nullptr) {
            node = root;
        }
        if (l > r) {
            return 0;
        }
        if (node->l >= l && node->r <= r) {
            return node->v;
        }
        pushdown(node);
        int v = 0;
        if (l <= node->mid) {
            v += query(l, r, node->left);
        }
        if (r > node->mid) {
            v += query(l, r, node->right);
        }
        return v;
    }

private:
    Node* root;

    void pushup(Node* node) {
        node->v = node->left->v + node->right->v;
    }

    void pushdown(Node* node) {
        if (node->left == nullptr) {
            node->left = new Node(node->l, node->mid);
        }
        if (node->right == nullptr) {
            node->right = new Node(node->mid + 1, node->r);
        }
        if (node->add != 0) {
            Node* left = node->left;
            Node* right = node->right;
            left->add = node->add;
            right->add = node->add;
            left->v = left->r - left->l + 1;
            right->v = right->r - right->l + 1;
            node->add = 0;
        }
    }
};

class CountIntervals {
public:
    CountIntervals() {}

    void add(int left, int right) {
        tree.modify(left, right, 1);
    }

    int count() {
        return tree.query(1, 1000000000);
    }

private:
    SegmentTree tree;
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */
```

#### Go

```go
type Node struct {
	left  *Node
	right *Node
	l     int
	r     int
	mid   int
	v     int
	add   int
}

type SegmentTree struct {
	root *Node
}

func newNode(l, r int) *Node {
	return &Node{
		left:  nil,
		right: nil,
		l:     l,
		r:     r,
		mid:   (l + r) / 2,
		v:     0,
		add:   0,
	}
}

func newSegmentTree() *SegmentTree {
	return &SegmentTree{
		root: newNode(1, 1000000001),
	}
}

func (st *SegmentTree) modify(l, r, v int, node *Node) {
	if node == nil {
		node = st.root
	}
	if l > r {
		return
	}
	if node.l >= l && node.r <= r {
		node.v = node.r - node.l + 1
		node.add = v
		return
	}
	st.pushdown(node)
	if l <= node.mid {
		st.modify(l, r, v, node.left)
	}
	if r > node.mid {
		st.modify(l, r, v, node.right)
	}
	st.pushup(node)
}

func (st *SegmentTree) query(l, r int, node *Node) int {
	if node == nil {
		node = st.root
	}
	if l > r {
		return 0
	}
	if node.l >= l && node.r <= r {
		return node.v
	}
	st.pushdown(node)
	v := 0
	if l <= node.mid {
		v += st.query(l, r, node.left)
	}
	if r > node.mid {
		v += st.query(l, r, node.right)
	}
	return v
}

func (st *SegmentTree) pushup(node *Node) {
	node.v = node.left.v + node.right.v
}

func (st *SegmentTree) pushdown(node *Node) {
	if node.left == nil {
		node.left = newNode(node.l, node.mid)
	}
	if node.right == nil {
		node.right = newNode(node.mid+1, node.r)
	}
	if node.add != 0 {
		left := node.left
		right := node.right
		left.add = node.add
		right.add = node.add
		left.v = left.r - left.l + 1
		right.v = right.r - right.l + 1
		node.add = 0
	}
}

type CountIntervals struct {
	tree *SegmentTree
}

func Constructor() CountIntervals {
	return CountIntervals{
		tree: newSegmentTree(),
	}
}

func (ci *CountIntervals) Add(left, right int) {
	ci.tree.modify(left, right, 1, nil)
}

func (ci *CountIntervals) Count() int {
	return ci.tree.query(1, 1000000000, nil)
}

/**
 * Your CountIntervals object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Add(left,right);
 * param_2 := obj.Count();
 */
```

#### TypeScript

```ts
class CountIntervals {
    left: null | CountIntervals;
    right: null | CountIntervals;
    start: number;
    end: number;
    sum: number;
    constructor(start: number = 0, end: number = 10 ** 9) {
        this.left = null;
        this.right = null;
        this.start = start;
        this.end = end;
        this.sum = 0;
    }

    add(left: number, right: number): void {
        if (this.sum == this.end - this.start + 1) return;
        if (left <= this.start && right >= this.end) {
            this.sum = this.end - this.start + 1;
            return;
        }
        let mid = (this.start + this.end) >> 1;
        if (!this.left) this.left = new CountIntervals(this.start, mid);
        if (!this.right) this.right = new CountIntervals(mid + 1, this.end);
        if (left <= mid) this.left.add(left, right);
        if (right > mid) this.right.add(left, right);
        this.sum = this.left.sum + this.right.sum;
    }

    count(): number {
        return this.sum;
    }
}

/**
 * Your CountIntervals object will be instantiated and called as such:
 * var obj = new CountIntervals()
 * obj.add(left,right)
 * var param_2 = obj.count()
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2277. 树中最接近路径的节点 🔒](https://leetcode.cn/problems/closest-node-to-path-in-tree){#2277}

{{< tabs "2277" >}}

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

<p>给定一个正整数 <code>n</code>，表示树中的节点数，编号从 <code>0</code> 到 <code>n - 1</code> (<strong>含边界</strong>)。还给定一个长度为 <code>n - 1</code> 的二维整数数组 <code>edges</code>，其中&nbsp;<code>edges[i] = [node1<sub>i</sub>, node2<sub>i</sub>]</code> 表示有一条&nbsp;<strong>双向&nbsp;</strong>边连接树中的 <code>node1<sub>i</sub></code> 和 <code>node2<sub>i</sub></code>。</p>

<p>给定一个长度为 <code>m</code>&nbsp;，<strong>下标从 0 开始</strong>&nbsp;的整数数组 <code>query</code>，其中 <code>query[i] = [start<sub>i</sub>, end<sub>i</sub>, node<sub>i</sub>]</code>&nbsp;意味着对于第 <code>i</code> 个查询，您的任务是从 <code>start<sub>i</sub></code> 到 <code>end<sub>i</sub></code> 的路径上找到&nbsp;<strong>最接近</strong> <code>node<sub>i</sub></code><sub>&nbsp;</sub>的节点。</p>

<p>返回<em>长度为 <code>m</code> 的整数数组 </em><code>answer</code><em>，其中 </em><code>answer[i]</code>&nbsp;<em>是第 <code>i</code> 个查询的答案。</em></p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2277.Closest%20Node%20to%20Path%20in%20Tree/images/image-20220514132158-1.png" style="width: 300px; height: 211px;" />
<pre>
<strong>输入:</strong> n = 7, edges = [[0,1],[0,2],[0,3],[1,4],[2,5],[2,6]], query = [[5,3,4],[5,3,6]]
<strong>输出:</strong> [0,2]
<strong>解释:</strong>
节点 5 到节点 3 的路径由节点 5、2、0、3 组成。
节点 4 到节点 0 的距离为 2。
节点 0 是距离节点 4 最近的路径上的节点，因此第一个查询的答案是 0。
节点 6 到节点 2 的距离为 1。
节点 2 是距离节点 6 最近的路径上的节点，因此第二个查询的答案是 2。
</pre>

<p><strong class="example">示例 2:</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2277.Closest%20Node%20to%20Path%20in%20Tree/images/image-20220514132318-2.png" style="width: 300px; height: 89px;" />
<pre>
<strong>输入:</strong> n = 3, edges = [[0,1],[1,2]], query = [[0,1,2]]
<strong>输出:</strong> [1]
<strong>解释:</strong>
从节点 0 到节点 1 的路径由节点 0,1 组成。
节点 2 到节点 1 的距离为 1。
节点 1 是距离节点 2 最近的路径上的节点，因此第一个查询的答案是 1。
</pre>

<p><strong class="example">示例 3:</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2277.Closest%20Node%20to%20Path%20in%20Tree/images/image-20220514132333-3.png" style="width: 300px; height: 89px;" />
<pre>
<strong>输入:</strong> n = 3, edges = [[0,1],[1,2]], query = [[0,0,0]]
<strong>输出:</strong> [0]
<strong>解释:</strong>
节点 0 到节点 0 的路径由节点 0 组成。
因为 0 是路径上唯一的节点，所以第一个查询的答案是0。</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= node1<sub>i</sub>, node2<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>node1<sub>i</sub> != node2<sub>i</sub></code></li>
	<li><code>1 &lt;= query.length &lt;= 1000</code></li>
	<li><code>query[i].length == 3</code></li>
	<li><code>0 &lt;= start<sub>i</sub>, end<sub>i</sub>, node<sub>i</sub> &lt;= n - 1</code></li>
	<li>
	<p data-group="1-1">这个图是一个树。</p>
	</li>
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

# [2278. 字母在字符串中的百分比](https://leetcode.cn/problems/percentage-of-letter-in-string){#2278}

{{< tabs "2278" >}}

{{% tab "python" %}}
```python
class Solution:
    def percentageLetter(self, s: str, letter: str) -> int:
        return s.count(letter) * 100 // len(s)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int percentageLetter(String s, char letter) {
        int cnt = 0;
        for (char c : s.toCharArray()) {
            if (c == letter) {
                ++cnt;
            }
        }
        return cnt * 100 / s.length();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int percentageLetter(string s, char letter) {
        return 100 * ranges::count(s, letter) / s.size();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func percentageLetter(s string, letter byte) int {
	return strings.Count(s, string(letter)) * 100 / len(s)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function percentageLetter(s: string, letter: string): number {
    const count = s.split('').filter(c => c === letter).length;
    return Math.floor((100 * count) / s.length);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn percentage_letter(s: String, letter: char) -> i32 {
        let count = s.chars().filter(|&c| c == letter).count();
        (100 * count as i32 / s.len() as i32) as i32
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>s</code> 和一个字符 <code>letter</code> ，返回在 <code>s</code> 中等于&nbsp;<code>letter</code>&nbsp;字符所占的 <strong>百分比</strong> ，向下取整到最接近的百分比。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "foobar", letter = "o"
<strong>输出：</strong>33
<strong>解释：</strong>
等于字母 'o' 的字符在 s 中占到的百分比是 2 / 6 * 100% = 33% ，向下取整，所以返回 33 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "jjjj", letter = "k"
<strong>输出：</strong>0
<strong>解释：</strong>
等于字母 'k' 的字符在 s 中占到的百分比是 0% ，所以返回 0 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> 由小写英文字母组成</li>
	<li><code>letter</code> 是一个小写英文字母</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们可以遍历字符串 $\textit{s}$，统计其中等于 $\textit{letter}$ 的字符的个数，然后根据公式 $\textit{count} \times 100 \, / \, \textit{len}(\textit{s})$ 计算百分比。

时间复杂度 $O(n)$，其中 $n$ 为字符串 $\textit{s}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def percentageLetter(self, s: str, letter: str) -> int:
        return s.count(letter) * 100 // len(s)
```

#### Java

```java
class Solution {
    public int percentageLetter(String s, char letter) {
        int cnt = 0;
        for (char c : s.toCharArray()) {
            if (c == letter) {
                ++cnt;
            }
        }
        return cnt * 100 / s.length();
    }
}
```

#### C++

```cpp
class Solution {
public:
    int percentageLetter(string s, char letter) {
        return 100 * ranges::count(s, letter) / s.size();
    }
};
```

#### Go

```go
func percentageLetter(s string, letter byte) int {
	return strings.Count(s, string(letter)) * 100 / len(s)
}
```

#### TypeScript

```ts
function percentageLetter(s: string, letter: string): number {
    const count = s.split('').filter(c => c === letter).length;
    return Math.floor((100 * count) / s.length);
}
```

#### Rust

```rust
impl Solution {
    pub fn percentage_letter(s: String, letter: char) -> i32 {
        let count = s.chars().filter(|&c| c == letter).count();
        (100 * count as i32 / s.len() as i32) as i32
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2279. 装满石头的背包的最大数量](https://leetcode.cn/problems/maximum-bags-with-full-capacity-of-rocks){#2279}

{{< tabs "2279" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumBags(
        self, capacity: List[int], rocks: List[int], additionalRocks: int
    ) -> int:
        for i, x in enumerate(rocks):
            capacity[i] -= x
        capacity.sort()
        for i, x in enumerate(capacity):
            additionalRocks -= x
            if additionalRocks < 0:
                return i
        return len(capacity)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumBags(int[] capacity, int[] rocks, int additionalRocks) {
        int n = rocks.length;
        for (int i = 0; i < n; ++i) {
            capacity[i] -= rocks[i];
        }
        Arrays.sort(capacity);
        for (int i = 0; i < n; ++i) {
            additionalRocks -= capacity[i];
            if (additionalRocks < 0) {
                return i;
            }
        }
        return n;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = rocks.size();
        for (int i = 0; i < n; ++i) {
            capacity[i] -= rocks[i];
        }
        ranges::sort(capacity);
        for (int i = 0; i < n; ++i) {
            additionalRocks -= capacity[i];
            if (additionalRocks < 0) {
                return i;
            }
        }
        return n;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumBags(capacity []int, rocks []int, additionalRocks int) int {
	for i, x := range rocks {
		capacity[i] -= x
	}
	sort.Ints(capacity)
	for i, x := range capacity {
		additionalRocks -= x
		if additionalRocks < 0 {
			return i
		}
	}
	return len(capacity)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumBags(capacity: number[], rocks: number[], additionalRocks: number): number {
    const n = rocks.length;
    for (let i = 0; i < n; ++i) {
        capacity[i] -= rocks[i];
    }
    capacity.sort((a, b) => a - b);
    for (let i = 0; i < n; ++i) {
        additionalRocks -= capacity[i];
        if (additionalRocks < 0) {
            return i;
        }
    }
    return n;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn maximum_bags(mut capacity: Vec<i32>, rocks: Vec<i32>, mut additional_rocks: i32) -> i32 {
        for i in 0..rocks.len() {
            capacity[i] -= rocks[i];
        }
        capacity.sort();
        for i in 0..capacity.len() {
            additional_rocks -= capacity[i];
            if additional_rocks < 0 {
                return i as i32;
            }
        }
        capacity.len() as i32
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>现有编号从&nbsp;<code>0</code> 到 <code>n - 1</code> 的 <code>n</code> 个背包。给你两个下标从 <strong>0</strong> 开始的整数数组 <code>capacity</code> 和 <code>rocks</code> 。第 <code>i</code> 个背包最大可以装 <code>capacity[i]</code> 块石头，当前已经装了 <code>rocks[i]</code> 块石头。另给你一个整数 <code>additionalRocks</code> ，表示<span class="text-only" data-eleid="10" style="white-space: pre;">你可以放置的额外石头数量，石头可以往 </span><strong><span class="text-only" data-eleid="11" style="white-space: pre;">任意</span></strong><span class="text-only" data-eleid="12" style="white-space: pre;"> 背包中放置。</span></p>

<p>请你将额外的石头放入一些背包中，并返回放置后装满石头的背包的 <strong>最大 </strong>数量<em>。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>capacity = [2,3,4,5], rocks = [1,2,4,4], additionalRocks = 2
<strong>输出：</strong>3
<strong>解释：</strong>
1 块石头放入背包 0 ，1 块石头放入背包 1 。
每个背包中的石头总数是 [2,3,4,4] 。
背包 0 、背包 1 和 背包 2 都装满石头。
总计 3 个背包装满石头，所以返回 3 。
可以证明不存在超过 3 个背包装满石头的情况。
注意，可能存在其他放置石头的方案同样能够得到 3 这个结果。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>capacity = [10,2,2], rocks = [2,2,0], additionalRocks = 100
<strong>输出：</strong>3
<strong>解释：</strong>
8 块石头放入背包 0 ，2 块石头放入背包 2 。
每个背包中的石头总数是 [10,2,2] 。
背包 0 、背包 1 和背包 2 都装满石头。
总计 3 个背包装满石头，所以返回 3 。
可以证明不存在超过 3 个背包装满石头的情况。
注意，不必用完所有的额外石头。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == capacity.length == rocks.length</code></li>
	<li><code>1 &lt;= n &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= capacity[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= rocks[i] &lt;= capacity[i]</code></li>
	<li><code>1 &lt;= additionalRocks &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 贪心

我们首先将每个背包的剩余容量计算出来，然后对剩余容量进行排序，接着我们从小到大遍历剩余容量，将额外的石头放入背包中，直到额外的石头用完或者背包的剩余容量用完为止，返回此时的背包数量即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为背包的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumBags(
        self, capacity: List[int], rocks: List[int], additionalRocks: int
    ) -> int:
        for i, x in enumerate(rocks):
            capacity[i] -= x
        capacity.sort()
        for i, x in enumerate(capacity):
            additionalRocks -= x
            if additionalRocks < 0:
                return i
        return len(capacity)
```

#### Java

```java
class Solution {
    public int maximumBags(int[] capacity, int[] rocks, int additionalRocks) {
        int n = rocks.length;
        for (int i = 0; i < n; ++i) {
            capacity[i] -= rocks[i];
        }
        Arrays.sort(capacity);
        for (int i = 0; i < n; ++i) {
            additionalRocks -= capacity[i];
            if (additionalRocks < 0) {
                return i;
            }
        }
        return n;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = rocks.size();
        for (int i = 0; i < n; ++i) {
            capacity[i] -= rocks[i];
        }
        ranges::sort(capacity);
        for (int i = 0; i < n; ++i) {
            additionalRocks -= capacity[i];
            if (additionalRocks < 0) {
                return i;
            }
        }
        return n;
    }
};
```

#### Go

```go
func maximumBags(capacity []int, rocks []int, additionalRocks int) int {
	for i, x := range rocks {
		capacity[i] -= x
	}
	sort.Ints(capacity)
	for i, x := range capacity {
		additionalRocks -= x
		if additionalRocks < 0 {
			return i
		}
	}
	return len(capacity)
}
```

#### TypeScript

```ts
function maximumBags(capacity: number[], rocks: number[], additionalRocks: number): number {
    const n = rocks.length;
    for (let i = 0; i < n; ++i) {
        capacity[i] -= rocks[i];
    }
    capacity.sort((a, b) => a - b);
    for (let i = 0; i < n; ++i) {
        additionalRocks -= capacity[i];
        if (additionalRocks < 0) {
            return i;
        }
    }
    return n;
}
```

#### Rust

```rust
impl Solution {
    pub fn maximum_bags(mut capacity: Vec<i32>, rocks: Vec<i32>, mut additional_rocks: i32) -> i32 {
        for i in 0..rocks.len() {
            capacity[i] -= rocks[i];
        }
        capacity.sort();
        for i in 0..capacity.len() {
            additional_rocks -= capacity[i];
            if additional_rocks < 0 {
                return i as i32;
            }
        }
        capacity.len() as i32
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
