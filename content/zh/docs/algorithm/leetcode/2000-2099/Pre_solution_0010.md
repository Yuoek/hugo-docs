---
title: "2090_半径为 k 的子数组平均值"
date: 2025-10-08T18:38:57+08:00
weight: 10
tags: [二叉树, 双指针, 哈希表, 图, 堆（优先队列）, 字符串, 并查集, 广度优先搜索, 排序, 数组, 最短路, 枚举, 树, 欧拉回路, 深度优先搜索, 滑动窗口, 贪心, 链表]
---

{{< markmap >}}
### [2090_半径为 k 的子数组平均值](#2090)
#### [数组](#2090)
#### [滑动窗口](#2090)
### [2091_从数组中移除最大值和最小值](#2091)
#### [贪心](#2091)
#### [数组](#2091)
### [2092_找出知晓秘密的所有专家](#2092)
#### [深度优先搜索](#2092)
#### [广度优先搜索](#2092)
#### [并查集](#2092)
#### [图](#2092)
#### [排序](#2092)
### [2093_前往目标城市的最小费用 🔒](#2093)
#### [图](#2093)
#### [最短路](#2093)
#### [堆（优先队列）](#2093)
### [2094_找出 3 位偶数](#2094)
#### [数组](#2094)
#### [哈希表](#2094)
#### [枚举](#2094)
#### [排序](#2094)
### [2095_删除链表的中间节点](#2095)
#### [链表](#2095)
#### [双指针](#2095)
### [2096_从二叉树一个节点到另一个节点每一步的方向](#2096)
#### [树](#2096)
#### [深度优先搜索](#2096)
#### [字符串](#2096)
#### [二叉树](#2096)
### [2097_合法重新排列数对](#2097)
#### [深度优先搜索](#2097)
#### [图](#2097)
#### [欧拉回路](#2097)
### [2098_长度为 K 的最大偶数和子序列 🔒](#2098)
#### [贪心](#2098)
#### [数组](#2098)
#### [排序](#2098)
### [2099_找到和最大的长度为 K 的子序列](#2099)
#### [数组](#2099)
#### [哈希表](#2099)
#### [排序](#2099)
#### [堆（优先队列）](#2099)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2090_半径为 k 的子数组平均值
___
#### 数组
___
#### 滑动窗口
---
### 2091_从数组中移除最大值和最小值
___
#### 贪心
___
#### 数组
---
### 2092_找出知晓秘密的所有专家
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 并查集
___
#### 图
___
#### 排序
---
### 2093_前往目标城市的最小费用 🔒
___
#### 图
___
#### 最短路
___
#### 堆（优先队列）
---
### 2094_找出 3 位偶数
___
#### 数组
___
#### 哈希表
___
#### 枚举
___
#### 排序
---
### 2095_删除链表的中间节点
___
#### 链表
___
#### 双指针
---
### 2096_从二叉树一个节点到另一个节点每一步的方向
___
#### 树
___
#### 深度优先搜索
___
#### 字符串
___
#### 二叉树
---
### 2097_合法重新排列数对
___
#### 深度优先搜索
___
#### 图
___
#### 欧拉回路
---
### 2098_长度为 K 的最大偶数和子序列 🔒
___
#### 贪心
___
#### 数组
___
#### 排序
---
### 2099_找到和最大的长度为 K 的子序列
___
#### 数组
___
#### 哈希表
___
#### 排序
___
#### 堆（优先队列）
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二叉树 | 双指针 | 哈希表 |
| 图 | 堆（优先队列） | 字符串 |
| 并查集 | 广度优先搜索 | 排序 |
| 数组 | 最短路 | 枚举 |
| 树 | 欧拉回路 | 深度优先搜索 |
| 滑动窗口 | 贪心 | 链表 |

# [2090. 半径为 k 的子数组平均值](https://leetcode.cn/problems/k-radius-subarray-averages){#2090}

{{< tabs "2090" >}}

{{% tab "python" %}}
```python
class Solution:
    def getAverages(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        ans = [-1] * n
        s = 0
        for i, x in enumerate(nums):
            s += x
            if i >= k * 2:
                ans[i - k] = s // (k * 2 + 1)
                s -= nums[i - k * 2]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] getAverages(int[] nums, int k) {
        int n = nums.length;
        int[] ans = new int[n];
        Arrays.fill(ans, -1);
        long s = 0;
        for (int i = 0; i < n; ++i) {
            s += nums[i];
            if (i >= k * 2) {
                ans[i - k] = (int) (s / (k * 2 + 1));
                s -= nums[i - k * 2];
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
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, -1);
        long long s = 0;
        for (int i = 0; i < n; ++i) {
            s += nums[i];
            if (i >= k * 2) {
                ans[i - k] = s / (k * 2 + 1);
                s -= nums[i - k * 2];
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getAverages(nums []int, k int) []int {
	ans := make([]int, len(nums))
	for i := range ans {
		ans[i] = -1
	}
	s := 0
	for i, x := range nums {
		s += x
		if i >= k*2 {
			ans[i-k] = s / (k*2 + 1)
			s -= nums[i-k*2]
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function getAverages(nums: number[], k: number): number[] {
    const n = nums.length;
    const ans: number[] = Array(n).fill(-1);
    let s = 0;
    for (let i = 0; i < n; ++i) {
        s += nums[i];
        if (i >= k * 2) {
            ans[i - k] = Math.floor(s / (k * 2 + 1));
            s -= nums[i - k * 2];
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

<p>给你一个下标从 <strong>0</strong> 开始的数组 <code>nums</code> ，数组中有 <code>n</code> 个整数，另给你一个整数 <code>k</code> 。</p>

<p><strong>半径为 k 的子数组平均值</strong> 是指：<code>nums</code> 中一个以下标 <code>i</code> 为 <strong>中心</strong> 且 <strong>半径</strong> 为 <code>k</code> 的子数组中所有元素的平均值，即下标在&nbsp;<code>i - k</code> 和 <code>i + k</code> 范围（<strong>含</strong> <code>i - k</code> 和 <code>i + k</code>）内所有元素的平均值。如果在下标 <code>i</code> 前或后不足 <code>k</code> 个元素，那么<strong> 半径为 k 的子数组平均值 </strong>是 <code>-1</code> 。</p>

<p>构建并返回一个长度为 <code>n</code> 的数组<em> </em><code>avgs</code><em> </em>，其中<em> </em><code>avgs[i]</code><em> </em>是以下标 <code>i</code> 为中心的子数组的<strong> 半径为 k 的子数组平均值 </strong>。</p>

<p><code>x</code> 个元素的 <strong>平均值</strong> 是 <code>x</code> 个元素相加之和除以 <code>x</code> ，此时使用截断式 <strong>整数除法</strong> ，即需要去掉结果的小数部分。</p>

<ul>
	<li>例如，四个元素 <code>2</code>、<code>3</code>、<code>1</code> 和 <code>5</code> 的平均值是 <code>(2 + 3 + 1 + 5) / 4 = 11 / 4 = 2.75</code>，截断后得到 <code>2</code> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2090.K%20Radius%20Subarray%20Averages/images/eg1.png" style="width: 343px; height: 119px;" /></p>

<pre>
<strong>输入：</strong>nums = [7,4,3,9,1,8,5,2,6], k = 3
<strong>输出：</strong>[-1,-1,-1,5,4,4,-1,-1,-1]
<strong>解释：</strong>
- avg[0]、avg[1] 和 avg[2] 是 -1 ，因为在这几个下标前的元素数量都不足 k 个。
- 中心为下标 3 且半径为 3 的子数组的元素总和是：7 + 4 + 3 + 9 + 1 + 8 + 5 = 37 。
  使用截断式 <strong>整数除法</strong>，avg[3] = 37 / 7 = 5 。
- 中心为下标 4 的子数组，avg[4] = (4 + 3 + 9 + 1 + 8 + 5 + 2) / 7 = 4 。
- 中心为下标 5 的子数组，avg[5] = (3 + 9 + 1 + 8 + 5 + 2 + 6) / 7 = 4 。
- avg[6]、avg[7] 和 avg[8] 是 -1 ，因为在这几个下标后的元素数量都不足 k 个。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [100000], k = 0
<strong>输出：</strong>[100000]
<strong>解释：</strong>
- 中心为下标 0 且半径 0 的子数组的元素总和是：100000 。
  avg[0] = 100000 / 1 = 100000 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [8], k = 100000
<strong>输出：</strong>[-1]
<strong>解释：</strong>
- avg[0] 是 -1 ，因为在下标 0 前后的元素数量均不足 k 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i], k &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：滑动窗口

半径为 $k$ 的子数组的长度为 $k \times 2 + 1$，因此我们可以维护一个大小为 $k \times 2 + 1$ 的窗口，记窗口中的所有元素和为 $s$。

我们创建一个长度为 $n$ 的答案数组 $\textit{ans}$，初始时每个元素都为 $-1$。

接下来，我们遍历数组 $\textit{nums}$，将 $\textit{nums}[i]$ 的值加到窗口的和 $s$ 中，如果此时 $i \geq k \times 2$，说明此时窗口大小为 $k \times 2 + 1$，那么 $\textit{ans}[i-k] = \frac{s}{k \times 2 + 1}$，然后我们将 $\textit{nums}[i - k \times 2]$ 的值从窗口和 $s$ 中移出。继续遍历下个元素。

最后返回答案数组即可。

时间复杂度 $O(n)$，其中 $n$ 为数组 $\textit{nums}$ 的长度。忽略答案数组的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getAverages(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        ans = [-1] * n
        s = 0
        for i, x in enumerate(nums):
            s += x
            if i >= k * 2:
                ans[i - k] = s // (k * 2 + 1)
                s -= nums[i - k * 2]
        return ans
```

#### Java

```java
class Solution {
    public int[] getAverages(int[] nums, int k) {
        int n = nums.length;
        int[] ans = new int[n];
        Arrays.fill(ans, -1);
        long s = 0;
        for (int i = 0; i < n; ++i) {
            s += nums[i];
            if (i >= k * 2) {
                ans[i - k] = (int) (s / (k * 2 + 1));
                s -= nums[i - k * 2];
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
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, -1);
        long long s = 0;
        for (int i = 0; i < n; ++i) {
            s += nums[i];
            if (i >= k * 2) {
                ans[i - k] = s / (k * 2 + 1);
                s -= nums[i - k * 2];
            }
        }
        return ans;
    }
};
```

#### Go

```go
func getAverages(nums []int, k int) []int {
	ans := make([]int, len(nums))
	for i := range ans {
		ans[i] = -1
	}
	s := 0
	for i, x := range nums {
		s += x
		if i >= k*2 {
			ans[i-k] = s / (k*2 + 1)
			s -= nums[i-k*2]
		}
	}
	return ans
}
```

#### TypeScript

```ts
function getAverages(nums: number[], k: number): number[] {
    const n = nums.length;
    const ans: number[] = Array(n).fill(-1);
    let s = 0;
    for (let i = 0; i < n; ++i) {
        s += nums[i];
        if (i >= k * 2) {
            ans[i - k] = Math.floor(s / (k * 2 + 1));
            s -= nums[i - k * 2];
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

# [2091. 从数组中移除最大值和最小值](https://leetcode.cn/problems/removing-minimum-and-maximum-from-array){#2091}

{{< tabs "2091" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumDeletions(self, nums: List[int]) -> int:
        mi = mx = 0
        for i, num in enumerate(nums):
            if num < nums[mi]:
                mi = i
            if num > nums[mx]:
                mx = i
        if mi > mx:
            mi, mx = mx, mi
        return min(mx + 1, len(nums) - mi, mi + 1 + len(nums) - mx)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumDeletions(int[] nums) {
        int mi = 0, mx = 0, n = nums.length;
        for (int i = 0; i < n; ++i) {
            if (nums[i] < nums[mi]) {
                mi = i;
            }
            if (nums[i] > nums[mx]) {
                mx = i;
            }
        }
        if (mi > mx) {
            int t = mx;
            mx = mi;
            mi = t;
        }
        return Math.min(Math.min(mx + 1, n - mi), mi + 1 + n - mx);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mi = 0, mx = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] < nums[mi]) mi = i;
            if (nums[i] > nums[mx]) mx = i;
        }
        if (mi > mx) {
            int t = mi;
            mi = mx;
            mx = t;
        }
        return min(min(mx + 1, n - mi), mi + 1 + n - mx);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumDeletions(nums []int) int {
	mi, mx, n := 0, 0, len(nums)
	for i, num := range nums {
		if num < nums[mi] {
			mi = i
		}
		if num > nums[mx] {
			mx = i
		}
	}
	if mi > mx {
		mi, mx = mx, mi
	}
	return min(min(mx+1, n-mi), mi+1+n-mx)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumDeletions(nums: number[]): number {
    const n = nums.length;
    if (n == 1) return 1;
    let i = nums.indexOf(Math.min(...nums));
    let j = nums.indexOf(Math.max(...nums));
    let left = Math.min(i, j);
    let right = Math.max(i, j);
    // 左右 left + 1 + n - right
    // 两个都是左边 left + 1 + right - left = right + 1
    // 都是右边 n - right + right - left = n - left
    return Math.min(left + 1 + n - right, right + 1, n - left);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始的数组 <code>nums</code> ，数组由若干 <strong>互不相同</strong> 的整数组成。</p>

<p><code>nums</code> 中有一个值最小的元素和一个值最大的元素。分别称为 <strong>最小值</strong> 和 <strong>最大值</strong> 。你的目标是从数组中移除这两个元素。</p>

<p>一次 <strong>删除</strong> 操作定义为从数组的 <strong>前面</strong> 移除一个元素或从数组的 <strong>后面</strong> 移除一个元素。</p>

<p>返回将数组中最小值和最大值 <strong>都</strong> 移除需要的最小删除次数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,<em><strong>10</strong></em>,7,5,4,<em><strong>1</strong></em>,8,6]
<strong>输出：</strong>5
<strong>解释：</strong>
数组中的最小元素是 nums[5] ，值为 1 。
数组中的最大元素是 nums[1] ，值为 10 。
将最大值和最小值都移除需要从数组前面移除 2 个元素，从数组后面移除 3 个元素。
结果是 2 + 3 = 5 ，这是所有可能情况中的最小删除次数。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,<em><strong>-4</strong></em>,<em><strong>19</strong></em>,1,8,-2,-3,5]
<strong>输出：</strong>3
<strong>解释：</strong>
数组中的最小元素是 nums[1] ，值为 -4 。
数组中的最大元素是 nums[2] ，值为 19 。
将最大值和最小值都移除需要从数组前面移除 3 个元素。
结果是 3 ，这是所有可能情况中的最小删除次数。 
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [<em><strong>101</strong></em>]
<strong>输出：</strong>1
<strong>解释：</strong>
数组中只有这一个元素，那么它既是数组中的最小值又是数组中的最大值。
移除它只需要 1 次删除操作。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>nums</code> 中的整数 <strong>互不相同</strong></li>
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
    def minimumDeletions(self, nums: List[int]) -> int:
        mi = mx = 0
        for i, num in enumerate(nums):
            if num < nums[mi]:
                mi = i
            if num > nums[mx]:
                mx = i
        if mi > mx:
            mi, mx = mx, mi
        return min(mx + 1, len(nums) - mi, mi + 1 + len(nums) - mx)
```

#### Java

```java
class Solution {
    public int minimumDeletions(int[] nums) {
        int mi = 0, mx = 0, n = nums.length;
        for (int i = 0; i < n; ++i) {
            if (nums[i] < nums[mi]) {
                mi = i;
            }
            if (nums[i] > nums[mx]) {
                mx = i;
            }
        }
        if (mi > mx) {
            int t = mx;
            mx = mi;
            mi = t;
        }
        return Math.min(Math.min(mx + 1, n - mi), mi + 1 + n - mx);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mi = 0, mx = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] < nums[mi]) mi = i;
            if (nums[i] > nums[mx]) mx = i;
        }
        if (mi > mx) {
            int t = mi;
            mi = mx;
            mx = t;
        }
        return min(min(mx + 1, n - mi), mi + 1 + n - mx);
    }
};
```

#### Go

```go
func minimumDeletions(nums []int) int {
	mi, mx, n := 0, 0, len(nums)
	for i, num := range nums {
		if num < nums[mi] {
			mi = i
		}
		if num > nums[mx] {
			mx = i
		}
	}
	if mi > mx {
		mi, mx = mx, mi
	}
	return min(min(mx+1, n-mi), mi+1+n-mx)
}
```

#### TypeScript

```ts
function minimumDeletions(nums: number[]): number {
    const n = nums.length;
    if (n == 1) return 1;
    let i = nums.indexOf(Math.min(...nums));
    let j = nums.indexOf(Math.max(...nums));
    let left = Math.min(i, j);
    let right = Math.max(i, j);
    // 左右 left + 1 + n - right
    // 两个都是左边 left + 1 + right - left = right + 1
    // 都是右边 n - right + right - left = n - left
    return Math.min(left + 1 + n - right, right + 1, n - left);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2092. 找出知晓秘密的所有专家](https://leetcode.cn/problems/find-all-people-with-secret){#2092}

{{< tabs "2092" >}}

{{% tab "python" %}}
```python
class Solution:
    def findAllPeople(
        self, n: int, meetings: List[List[int]], firstPerson: int
    ) -> List[int]:
        vis = [False] * n
        vis[0] = vis[firstPerson] = True
        meetings.sort(key=lambda x: x[2])
        i, m = 0, len(meetings)
        while i < m:
            j = i
            while j + 1 < m and meetings[j + 1][2] == meetings[i][2]:
                j += 1
            s = set()
            g = defaultdict(list)
            for x, y, _ in meetings[i : j + 1]:
                g[x].append(y)
                g[y].append(x)
                s.update([x, y])
            q = deque([u for u in s if vis[u]])
            while q:
                u = q.popleft()
                for v in g[u]:
                    if not vis[v]:
                        vis[v] = True
                        q.append(v)
            i = j + 1
        return [i for i, v in enumerate(vis) if v]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> findAllPeople(int n, int[][] meetings, int firstPerson) {
        boolean[] vis = new boolean[n];
        vis[0] = true;
        vis[firstPerson] = true;
        int m = meetings.length;
        Arrays.sort(meetings, Comparator.comparingInt(a -> a[2]));
        for (int i = 0; i < m;) {
            int j = i;
            for (; j + 1 < m && meetings[j + 1][2] == meetings[i][2]; ++j)
                ;
            Map<Integer, List<Integer>> g = new HashMap<>();
            Set<Integer> s = new HashSet<>();
            for (int k = i; k <= j; ++k) {
                int x = meetings[k][0], y = meetings[k][1];
                g.computeIfAbsent(x, key -> new ArrayList<>()).add(y);
                g.computeIfAbsent(y, key -> new ArrayList<>()).add(x);
                s.add(x);
                s.add(y);
            }
            Deque<Integer> q = new ArrayDeque<>();
            for (int u : s) {
                if (vis[u]) {
                    q.offer(u);
                }
            }
            while (!q.isEmpty()) {
                int u = q.poll();
                for (int v : g.getOrDefault(u, Collections.emptyList())) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.offer(v);
                    }
                }
            }
            i = j + 1;
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            if (vis[i]) {
                ans.add(i);
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
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<bool> vis(n);
        vis[0] = vis[firstPerson] = true;
        sort(meetings.begin(), meetings.end(), [&](const auto& x, const auto& y) {
            return x[2] < y[2];
        });
        for (int i = 0, m = meetings.size(); i < m;) {
            int j = i;
            for (; j + 1 < m && meetings[j + 1][2] == meetings[i][2]; ++j)
                ;
            unordered_map<int, vector<int>> g;
            unordered_set<int> s;
            for (int k = i; k <= j; ++k) {
                int x = meetings[k][0], y = meetings[k][1];
                g[x].push_back(y);
                g[y].push_back(x);
                s.insert(x);
                s.insert(y);
            }
            queue<int> q;
            for (int u : s)
                if (vis[u])
                    q.push(u);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : g[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
            i = j + 1;
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i)
            if (vis[i])
                ans.push_back(i);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findAllPeople(n int, meetings [][]int, firstPerson int) []int {
	vis := make([]bool, n)
	vis[0], vis[firstPerson] = true, true
	sort.Slice(meetings, func(i, j int) bool {
		return meetings[i][2] < meetings[j][2]
	})
	for i, j, m := 0, 0, len(meetings); i < m; i = j + 1 {
		j = i
		for j+1 < m && meetings[j+1][2] == meetings[i][2] {
			j++
		}
		g := map[int][]int{}
		s := map[int]bool{}
		for _, e := range meetings[i : j+1] {
			x, y := e[0], e[1]
			g[x] = append(g[x], y)
			g[y] = append(g[y], x)
			s[x], s[y] = true, true
		}
		q := []int{}
		for u := range s {
			if vis[u] {
				q = append(q, u)
			}
		}
		for len(q) > 0 {
			u := q[0]
			q = q[1:]
			for _, v := range g[u] {
				if !vis[v] {
					vis[v] = true
					q = append(q, v)
				}
			}
		}
	}
	var ans []int
	for i, v := range vis {
		if v {
			ans = append(ans, i)
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findAllPeople(n: number, meetings: number[][], firstPerson: number): number[] {
    let parent: Array<number> = Array.from({ length: n + 1 }, (v, i) => i);
    parent[firstPerson] = 0;

    function findParent(index: number): number {
        if (parent[index] != index) parent[index] = findParent(parent[index]);
        return parent[index];
    }

    let map = new Map<number, Array<Array<number>>>();
    for (let meeting of meetings) {
        const time = meeting[2];
        let members: Array<Array<number>> = map.get(time) || new Array();
        members.push(meeting);
        map.set(time, members);
    }
    const times = [...map.keys()].sort((a, b) => a - b);
    for (let time of times) {
        // round 1
        for (let meeting of map.get(time)) {
            let [a, b] = meeting;
            if (!parent[findParent(a)] || !parent[findParent(b)]) {
                parent[findParent(a)] = 0;
                parent[findParent(b)] = 0;
            }
            parent[findParent(a)] = parent[findParent(b)];
        }
        // round 2
        for (let meeting of map.get(time)) {
            let [a, b] = meeting;
            if (!parent[findParent(a)] || !parent[findParent(b)]) {
                parent[findParent(a)] = 0;
                parent[findParent(b)] = 0;
            } else {
                parent[a] = a;
                parent[b] = b;
            }
        }
    }

    let ans = new Array<number>();
    for (let i = 0; i <= n; i++) {
        if (!parent[findParent(i)]) {
            ans.push(i);
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

<p>给你一个整数 <code>n</code> ，表示有 <code>n</code> 个专家从 <code>0</code> 到 <code>n - 1</code> 编号。另外给你一个下标从 0 开始的二维整数数组 <code>meetings</code> ，其中 <code>meetings[i] = [x<sub>i</sub>, y<sub>i</sub>, time<sub>i</sub>]</code> 表示专家 <code>x<sub>i</sub></code> 和专家 <code>y<sub>i</sub></code> 在时间 <code>time<sub>i</sub></code> 要开一场会。一个专家可以同时参加 <strong>多场会议</strong> 。最后，给你一个整数 <code>firstPerson</code> 。</p>

<p>专家 <code>0</code> 有一个 <strong>秘密</strong> ，最初，他在时间&nbsp;<code>0</code> 将这个秘密分享给了专家 <code>firstPerson</code> 。接着，这个秘密会在每次有知晓这个秘密的专家参加会议时进行传播。更正式的表达是，每次会议，如果专家 <code>x<sub>i</sub></code> 在时间 <code>time<sub>i</sub></code> 时知晓这个秘密，那么他将会与专家 <code>y<sub>i</sub></code> 分享这个秘密，反之亦然。</p>

<p>秘密共享是 <strong>瞬时发生</strong> 的。也就是说，在同一时间，一个专家不光可以接收到秘密，还能在其他会议上与其他专家分享。</p>

<p>在所有会议都结束之后，返回所有知晓这个秘密的专家列表。你可以按 <strong>任何顺序</strong> 返回答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 6, meetings = [[1,2,5],[2,3,8],[1,5,10]], firstPerson = 1
<strong>输出：</strong>[0,1,2,3,5]
<strong>解释：
</strong>时间 0 ，专家 0 将秘密与专家 1 共享。
时间 5 ，专家 1 将秘密与专家 2 共享。
时间 8 ，专家 2 将秘密与专家 3 共享。
时间 10 ，专家 1 将秘密与专家 5 共享。
因此，在所有会议结束后，专家 0、1、2、3 和 5 都将知晓这个秘密。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 4, meetings = [[3,1,3],[1,2,2],[0,3,3]], firstPerson = 3
<strong>输出：</strong>[0,1,3]
<strong>解释：</strong>
时间 0 ，专家 0 将秘密与专家 3 共享。
时间 2 ，专家 1 与专家 2 都不知晓这个秘密。
时间 3 ，专家 3 将秘密与专家 0 和专家 1 共享。
因此，在所有会议结束后，专家 0、1 和 3 都将知晓这个秘密。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 5, meetings = [[3,4,2],[1,2,1],[2,3,1]], firstPerson = 1
<strong>输出：</strong>[0,1,2,3,4]
<strong>解释：</strong>
时间 0 ，专家 0 将秘密与专家 1 共享。
时间 1 ，专家 1 将秘密与专家 2 共享，专家 2 将秘密与专家 3 共享。
注意，专家 2 可以在收到秘密的同一时间分享此秘密。
时间 2 ，专家 3 将秘密与专家 4 共享。
因此，在所有会议结束后，专家 0、1、2、3 和 4 都将知晓这个秘密。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= meetings.length &lt;= 10<sup>5</sup></code></li>
	<li><code>meetings[i].length == 3</code></li>
	<li><code>0 &lt;= x<sub>i</sub>, y<sub>i </sub>&lt;= n - 1</code></li>
	<li><code>x<sub>i</sub> != y<sub>i</sub></code></li>
	<li><code>1 &lt;= time<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= firstPerson &lt;= n - 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findAllPeople(
        self, n: int, meetings: List[List[int]], firstPerson: int
    ) -> List[int]:
        vis = [False] * n
        vis[0] = vis[firstPerson] = True
        meetings.sort(key=lambda x: x[2])
        i, m = 0, len(meetings)
        while i < m:
            j = i
            while j + 1 < m and meetings[j + 1][2] == meetings[i][2]:
                j += 1
            s = set()
            g = defaultdict(list)
            for x, y, _ in meetings[i : j + 1]:
                g[x].append(y)
                g[y].append(x)
                s.update([x, y])
            q = deque([u for u in s if vis[u]])
            while q:
                u = q.popleft()
                for v in g[u]:
                    if not vis[v]:
                        vis[v] = True
                        q.append(v)
            i = j + 1
        return [i for i, v in enumerate(vis) if v]
```

#### Java

```java
class Solution {
    public List<Integer> findAllPeople(int n, int[][] meetings, int firstPerson) {
        boolean[] vis = new boolean[n];
        vis[0] = true;
        vis[firstPerson] = true;
        int m = meetings.length;
        Arrays.sort(meetings, Comparator.comparingInt(a -> a[2]));
        for (int i = 0; i < m;) {
            int j = i;
            for (; j + 1 < m && meetings[j + 1][2] == meetings[i][2]; ++j)
                ;
            Map<Integer, List<Integer>> g = new HashMap<>();
            Set<Integer> s = new HashSet<>();
            for (int k = i; k <= j; ++k) {
                int x = meetings[k][0], y = meetings[k][1];
                g.computeIfAbsent(x, key -> new ArrayList<>()).add(y);
                g.computeIfAbsent(y, key -> new ArrayList<>()).add(x);
                s.add(x);
                s.add(y);
            }
            Deque<Integer> q = new ArrayDeque<>();
            for (int u : s) {
                if (vis[u]) {
                    q.offer(u);
                }
            }
            while (!q.isEmpty()) {
                int u = q.poll();
                for (int v : g.getOrDefault(u, Collections.emptyList())) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.offer(v);
                    }
                }
            }
            i = j + 1;
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            if (vis[i]) {
                ans.add(i);
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
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<bool> vis(n);
        vis[0] = vis[firstPerson] = true;
        sort(meetings.begin(), meetings.end(), [&](const auto& x, const auto& y) {
            return x[2] < y[2];
        });
        for (int i = 0, m = meetings.size(); i < m;) {
            int j = i;
            for (; j + 1 < m && meetings[j + 1][2] == meetings[i][2]; ++j)
                ;
            unordered_map<int, vector<int>> g;
            unordered_set<int> s;
            for (int k = i; k <= j; ++k) {
                int x = meetings[k][0], y = meetings[k][1];
                g[x].push_back(y);
                g[y].push_back(x);
                s.insert(x);
                s.insert(y);
            }
            queue<int> q;
            for (int u : s)
                if (vis[u])
                    q.push(u);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : g[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
            i = j + 1;
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i)
            if (vis[i])
                ans.push_back(i);
        return ans;
    }
};
```

#### Go

```go
func findAllPeople(n int, meetings [][]int, firstPerson int) []int {
	vis := make([]bool, n)
	vis[0], vis[firstPerson] = true, true
	sort.Slice(meetings, func(i, j int) bool {
		return meetings[i][2] < meetings[j][2]
	})
	for i, j, m := 0, 0, len(meetings); i < m; i = j + 1 {
		j = i
		for j+1 < m && meetings[j+1][2] == meetings[i][2] {
			j++
		}
		g := map[int][]int{}
		s := map[int]bool{}
		for _, e := range meetings[i : j+1] {
			x, y := e[0], e[1]
			g[x] = append(g[x], y)
			g[y] = append(g[y], x)
			s[x], s[y] = true, true
		}
		q := []int{}
		for u := range s {
			if vis[u] {
				q = append(q, u)
			}
		}
		for len(q) > 0 {
			u := q[0]
			q = q[1:]
			for _, v := range g[u] {
				if !vis[v] {
					vis[v] = true
					q = append(q, v)
				}
			}
		}
	}
	var ans []int
	for i, v := range vis {
		if v {
			ans = append(ans, i)
		}
	}
	return ans
}
```

#### TypeScript

```ts
function findAllPeople(n: number, meetings: number[][], firstPerson: number): number[] {
    let parent: Array<number> = Array.from({ length: n + 1 }, (v, i) => i);
    parent[firstPerson] = 0;

    function findParent(index: number): number {
        if (parent[index] != index) parent[index] = findParent(parent[index]);
        return parent[index];
    }

    let map = new Map<number, Array<Array<number>>>();
    for (let meeting of meetings) {
        const time = meeting[2];
        let members: Array<Array<number>> = map.get(time) || new Array();
        members.push(meeting);
        map.set(time, members);
    }
    const times = [...map.keys()].sort((a, b) => a - b);
    for (let time of times) {
        // round 1
        for (let meeting of map.get(time)) {
            let [a, b] = meeting;
            if (!parent[findParent(a)] || !parent[findParent(b)]) {
                parent[findParent(a)] = 0;
                parent[findParent(b)] = 0;
            }
            parent[findParent(a)] = parent[findParent(b)];
        }
        // round 2
        for (let meeting of map.get(time)) {
            let [a, b] = meeting;
            if (!parent[findParent(a)] || !parent[findParent(b)]) {
                parent[findParent(a)] = 0;
                parent[findParent(b)] = 0;
            } else {
                parent[a] = a;
                parent[b] = b;
            }
        }
    }

    let ans = new Array<number>();
    for (let i = 0; i <= n; i++) {
        if (!parent[findParent(i)]) {
            ans.push(i);
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

# [2093. 前往目标城市的最小费用 🔒](https://leetcode.cn/problems/minimum-cost-to-reach-city-with-discounts){#2093}

{{< tabs "2093" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumCost(self, n: int, highways: List[List[int]], discounts: int) -> int:
        g = defaultdict(list)
        for a, b, c in highways:
            g[a].append((b, c))
            g[b].append((a, c))
        q = [(0, 0, 0)]
        dist = [[inf] * (discounts + 1) for _ in range(n)]
        while q:
            cost, i, k = heappop(q)
            if k > discounts:
                continue
            if i == n - 1:
                return cost
            if dist[i][k] > cost:
                dist[i][k] = cost
                for j, v in g[i]:
                    heappush(q, (cost + v, j, k))
                    heappush(q, (cost + v // 2, j, k + 1))
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumCost(int n, int[][] highways, int discounts) {
        List<int[]>[] g = new List[n];
        for (int i = 0; i < n; ++i) {
            g[i] = new ArrayList<>();
        }
        for (var e : highways) {
            int a = e[0], b = e[1], c = e[2];
            g[a].add(new int[] {b, c});
            g[b].add(new int[] {a, c});
        }
        PriorityQueue<int[]> q = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        q.offer(new int[] {0, 0, 0});
        int[][] dist = new int[n][discounts + 1];
        for (var e : dist) {
            Arrays.fill(e, Integer.MAX_VALUE);
        }
        while (!q.isEmpty()) {
            var p = q.poll();
            int cost = p[0], i = p[1], k = p[2];
            if (k > discounts || dist[i][k] <= cost) {
                continue;
            }
            if (i == n - 1) {
                return cost;
            }
            dist[i][k] = cost;
            for (int[] nxt : g[i]) {
                int j = nxt[0], v = nxt[1];
                q.offer(new int[] {cost + v, j, k});
                q.offer(new int[] {cost + v / 2, j, k + 1});
            }
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
    int minimumCost(int n, vector<vector<int>>& highways, int discounts) {
        vector<vector<pair<int, int>>> g(n);
        for (auto& e : highways) {
            int a = e[0], b = e[1], c = e[2];
            g[a].push_back({b, c});
            g[b].push_back({a, c});
        }
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
        q.push({0, 0, 0});
        vector<vector<int>> dist(n, vector<int>(discounts + 1, INT_MAX));
        while (!q.empty()) {
            auto [cost, i, k] = q.top();
            q.pop();
            if (k > discounts || dist[i][k] <= cost) continue;
            if (i == n - 1) return cost;
            dist[i][k] = cost;
            for (auto [j, v] : g[i]) {
                q.push({cost + v, j, k});
                q.push({cost + v / 2, j, k + 1});
            }
        }
        return -1;
    }
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>一组公路连接&nbsp;<code>n</code>&nbsp;个城市，城市编号为从&nbsp;<code>0</code> 到&nbsp;<code>n - 1</code>&nbsp;。 输入包含一个二维数组&nbsp;<code>highways</code>&nbsp;，其中 <code>highways[i] = [city1<sub>i</sub>, city2<sub>i</sub>, toll<sub>i</sub>]</code> 表示有一条连接城市&nbsp;<code>city1<sub>i</sub></code> 和&nbsp;<code>city2<sub>i</sub></code>&nbsp;的双向公路，允许汽车缴纳值为&nbsp;<code>toll<sub>i</sub></code>&nbsp;的费用从&nbsp;&nbsp;<code>city1<sub>i</sub></code>&nbsp;前往&nbsp;<code>city2<sub>i</sub></code>&nbsp;<strong>或</strong> 从&nbsp;&nbsp;<code>city2<sub>i</sub></code>&nbsp;前往&nbsp;<code>city1<sub>i</sub></code>&nbsp;。</p>

<p>另给你一个整数&nbsp;<code>discounts</code> 表示你最多可以使用折扣的次数。你可以使用一次折扣使通过第&nbsp;<code>i<sup>th</sup></code>&nbsp;条公路的费用降低至&nbsp;<code>toll<sub>i</sub> / 2</code>（<b>向下取整</b>）。&nbsp;最多只可使用&nbsp;<code>discounts</code> 次折扣，&nbsp;且<strong> 每条公路最多只可使用一次折扣</strong> 。</p>

<p>返回从城市<code>0</code><em>&nbsp;</em>前往城市<em>&nbsp;</em><code>n - 1</code>&nbsp;的<em><strong> </strong></em><strong>最小费用</strong><em><strong> 。</strong></em>如果不存在从城市<code>0</code><em>&nbsp;</em>前往城市<em>&nbsp;</em><code>n - 1</code>&nbsp;的路径，返回&nbsp;<code>-1</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong><br />
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2093.Minimum%20Cost%20to%20Reach%20City%20With%20Discounts/images/image-20211129222429-1.png" style="height: 250px; width: 404px;" /></p>

<pre>
<strong>输入：</strong>n = 5, highways = [[0,1,4],[2,1,3],[1,4,11],[3,2,3],[3,4,2]], discounts = 1
<strong>输出：</strong>9
<strong>解释：</strong>
从 0 前往 1 ，需要费用为 4 。
从 1 前往 4 并使用一次折扣，需要费用为 11 / 2 = 5 。
从 0 前往 4 最小费用为 4 + 5 = 9 。
</pre>

<p><strong>示例 2：</strong><br />
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2093.Minimum%20Cost%20to%20Reach%20City%20With%20Discounts/images/image-20211129222650-4.png" style="width: 284px; height: 250px;" /></p>

<pre>
<strong>输入：</strong>n = 4, highways = [[1,3,17],[1,2,7],[3,2,5],[0,1,6],[3,0,20]], discounts = 20
<strong>输出：</strong>8
<strong>解释：</strong>
从 0 前往 1 并使用一次折扣，需要费用为 6 / 2 = 3 。
从 1 前往 2 并使用一次折扣，需要费用为 7 / 2 = 3 。
从 2 前往 3 并使用一次折扣，需要费用为 5 / 2 = 2 。
从 0 前往 3 最小费用为 3 + 3 + 2 = 8 。
</pre>

<p><strong>示例 3：</strong><br />
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2093.Minimum%20Cost%20to%20Reach%20City%20With%20Discounts/images/image-20211129222531-3.png" style="width: 275px; height: 250px;" /></p>

<pre>
<strong>输入：</strong>n = 4, highways = [[0,1,3],[2,3,2]], discounts = 0
<strong>输出：</strong>-1
<strong>解释：</strong>
不存在从 0 前往 3 的路径，所以返回 -1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 1000</code></li>
	<li><code>1 &lt;= highways.length &lt;= 1000</code></li>
	<li><code>highways[i].length == 3</code></li>
	<li><code>0 &lt;= city1<sub>i</sub>, city2<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>city1<sub>i</sub> != city2<sub>i</sub></code></li>
	<li><code>0 &lt;= toll<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= discounts &lt;= 500</code></li>
	<li>任意两个城市之间最多只有一条公路相连</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS

本题属于带限制的单源最短路问题。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumCost(self, n: int, highways: List[List[int]], discounts: int) -> int:
        g = defaultdict(list)
        for a, b, c in highways:
            g[a].append((b, c))
            g[b].append((a, c))
        q = [(0, 0, 0)]
        dist = [[inf] * (discounts + 1) for _ in range(n)]
        while q:
            cost, i, k = heappop(q)
            if k > discounts:
                continue
            if i == n - 1:
                return cost
            if dist[i][k] > cost:
                dist[i][k] = cost
                for j, v in g[i]:
                    heappush(q, (cost + v, j, k))
                    heappush(q, (cost + v // 2, j, k + 1))
        return -1
```

#### Java

```java
class Solution {
    public int minimumCost(int n, int[][] highways, int discounts) {
        List<int[]>[] g = new List[n];
        for (int i = 0; i < n; ++i) {
            g[i] = new ArrayList<>();
        }
        for (var e : highways) {
            int a = e[0], b = e[1], c = e[2];
            g[a].add(new int[] {b, c});
            g[b].add(new int[] {a, c});
        }
        PriorityQueue<int[]> q = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        q.offer(new int[] {0, 0, 0});
        int[][] dist = new int[n][discounts + 1];
        for (var e : dist) {
            Arrays.fill(e, Integer.MAX_VALUE);
        }
        while (!q.isEmpty()) {
            var p = q.poll();
            int cost = p[0], i = p[1], k = p[2];
            if (k > discounts || dist[i][k] <= cost) {
                continue;
            }
            if (i == n - 1) {
                return cost;
            }
            dist[i][k] = cost;
            for (int[] nxt : g[i]) {
                int j = nxt[0], v = nxt[1];
                q.offer(new int[] {cost + v, j, k});
                q.offer(new int[] {cost + v / 2, j, k + 1});
            }
        }
        return -1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& highways, int discounts) {
        vector<vector<pair<int, int>>> g(n);
        for (auto& e : highways) {
            int a = e[0], b = e[1], c = e[2];
            g[a].push_back({b, c});
            g[b].push_back({a, c});
        }
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
        q.push({0, 0, 0});
        vector<vector<int>> dist(n, vector<int>(discounts + 1, INT_MAX));
        while (!q.empty()) {
            auto [cost, i, k] = q.top();
            q.pop();
            if (k > discounts || dist[i][k] <= cost) continue;
            if (i == n - 1) return cost;
            dist[i][k] = cost;
            for (auto [j, v] : g[i]) {
                q.push({cost + v, j, k});
                q.push({cost + v / 2, j, k + 1});
            }
        }
        return -1;
    }
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2094. 找出 3 位偶数](https://leetcode.cn/problems/finding-3-digit-even-numbers){#2094}

{{< tabs "2094" >}}

{{% tab "python" %}}
```python
class Solution:
    def findEvenNumbers(self, digits: List[int]) -> List[int]:
        cnt = Counter(digits)
        ans = []
        for x in range(100, 1000, 2):
            cnt1 = Counter()
            y = x
            while y:
                y, v = divmod(y, 10)
                cnt1[v] += 1
            if all(cnt[i] >= cnt1[i] for i in range(10)):
                ans.append(x)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] findEvenNumbers(int[] digits) {
        int[] cnt = new int[10];
        for (int x : digits) {
            ++cnt[x];
        }
        List<Integer> ans = new ArrayList<>();
        for (int x = 100; x < 1000; x += 2) {
            int[] cnt1 = new int[10];
            for (int y = x; y > 0; y /= 10) {
                ++cnt1[y % 10];
            }
            boolean ok = true;
            for (int i = 0; i < 10 && ok; ++i) {
                ok = cnt[i] >= cnt1[i];
            }
            if (ok) {
                ans.add(x);
            }
        }
        return ans.stream().mapToInt(i -> i).toArray();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int cnt[10]{};
        for (int x : digits) {
            ++cnt[x];
        }
        vector<int> ans;
        for (int x = 100; x < 1000; x += 2) {
            int cnt1[10]{};
            for (int y = x; y; y /= 10) {
                ++cnt1[y % 10];
            }
            bool ok = true;
            for (int i = 0; i < 10 && ok; ++i) {
                ok = cnt[i] >= cnt1[i];
            }
            if (ok) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findEvenNumbers(digits []int) (ans []int) {
	cnt := [10]int{}
	for _, x := range digits {
		cnt[x]++
	}
	for x := 100; x < 1000; x += 2 {
		cnt1 := [10]int{}
		for y := x; y > 0; y /= 10 {
			cnt1[y%10]++
		}
		ok := true
		for i := 0; i < 10 && ok; i++ {
			ok = cnt[i] >= cnt1[i]
		}
		if ok {
			ans = append(ans, x)
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findEvenNumbers(digits: number[]): number[] {
    const cnt: number[] = Array(10).fill(0);
    for (const x of digits) {
        ++cnt[x];
    }
    const ans: number[] = [];
    for (let x = 100; x < 1000; x += 2) {
        const cnt1: number[] = Array(10).fill(0);
        for (let y = x; y; y = Math.floor(y / 10)) {
            ++cnt1[y % 10];
        }
        let ok = true;
        for (let i = 0; i < 10 && ok; ++i) {
            ok = cnt[i] >= cnt1[i];
        }
        if (ok) {
            ans.push(x);
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} digits
 * @return {number[]}
 */
var findEvenNumbers = function (digits) {
    const cnt = Array(10).fill(0);
    for (const x of digits) {
        ++cnt[x];
    }
    const ans = [];
    for (let x = 100; x < 1000; x += 2) {
        const cnt1 = Array(10).fill(0);
        for (let y = x; y; y = Math.floor(y / 10)) {
            ++cnt1[y % 10];
        }
        let ok = true;
        for (let i = 0; i < 10 && ok; ++i) {
            ok = cnt[i] >= cnt1[i];
        }
        if (ok) {
            ans.push(x);
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

<p>给你一个整数数组 <code>digits</code> ，其中每个元素是一个数字（<code>0 - 9</code>）。数组中可能存在重复元素。</p>

<p>你需要找出 <strong>所有</strong> 满足下述条件且 <strong>互不相同</strong> 的整数：</p>

<ul>
	<li>该整数由 <code>digits</code> 中的三个元素按 <strong>任意</strong> 顺序 <strong>依次连接</strong> 组成。</li>
	<li>该整数不含 <strong>前导零</strong></li>
	<li>该整数是一个 <strong>偶数</strong></li>
</ul>

<p>例如，给定的 <code>digits</code> 是 <code>[1, 2, 3]</code> ，整数 <code>132</code> 和 <code>312</code> 满足上面列出的全部条件。</p>

<p>将找出的所有互不相同的整数按 <strong>递增顺序</strong> 排列，并以数组形式返回<em>。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>digits = [2,1,3,0]
<strong>输出：</strong>[102,120,130,132,210,230,302,310,312,320]
<strong>解释：</strong>
所有满足题目条件的整数都在输出数组中列出。 
注意，答案数组中不含有 <strong>奇数</strong> 或带 <strong>前导零</strong> 的整数。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>digits = [2,2,8,8,2]
<strong>输出：</strong>[222,228,282,288,822,828,882]
<strong>解释：</strong>
同样的数字（0 - 9）在构造整数时可以重复多次，重复次数最多与其在 <code>digits</code> 中出现的次数一样。 
在这个例子中，数字 8 在构造 288、828 和 882 时都重复了两次。 
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>digits = [3,7,5]
<strong>输出：</strong>[]
<strong>解释：</strong>
使用给定的 digits 无法构造偶数。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;=&nbsp;digits.length &lt;= 100</code></li>
	<li><code>0 &lt;= digits[i] &lt;= 9</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数 + 枚举

我们先统计 $\textit{digits}$ 中每个数字出现的次数，记录在数组或哈希表 $\textit{cnt}$ 中。

然后，我们在 $[100, 1000)$ 的范围内枚举所有的偶数，判断这个偶数的每一位数字是否都不超过 $\textit{cnt}$ 中对应的数字的次数。如果是，则将这个偶数加入答案数组中。

最后，返回答案数组。

时间复杂度 $O(k \times 10^k)$，其中 $k$ 是目标偶数的位数，本题中 $k = 3$。忽略答案的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findEvenNumbers(self, digits: List[int]) -> List[int]:
        cnt = Counter(digits)
        ans = []
        for x in range(100, 1000, 2):
            cnt1 = Counter()
            y = x
            while y:
                y, v = divmod(y, 10)
                cnt1[v] += 1
            if all(cnt[i] >= cnt1[i] for i in range(10)):
                ans.append(x)
        return ans
```

#### Java

```java
class Solution {
    public int[] findEvenNumbers(int[] digits) {
        int[] cnt = new int[10];
        for (int x : digits) {
            ++cnt[x];
        }
        List<Integer> ans = new ArrayList<>();
        for (int x = 100; x < 1000; x += 2) {
            int[] cnt1 = new int[10];
            for (int y = x; y > 0; y /= 10) {
                ++cnt1[y % 10];
            }
            boolean ok = true;
            for (int i = 0; i < 10 && ok; ++i) {
                ok = cnt[i] >= cnt1[i];
            }
            if (ok) {
                ans.add(x);
            }
        }
        return ans.stream().mapToInt(i -> i).toArray();
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int cnt[10]{};
        for (int x : digits) {
            ++cnt[x];
        }
        vector<int> ans;
        for (int x = 100; x < 1000; x += 2) {
            int cnt1[10]{};
            for (int y = x; y; y /= 10) {
                ++cnt1[y % 10];
            }
            bool ok = true;
            for (int i = 0; i < 10 && ok; ++i) {
                ok = cnt[i] >= cnt1[i];
            }
            if (ok) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findEvenNumbers(digits []int) (ans []int) {
	cnt := [10]int{}
	for _, x := range digits {
		cnt[x]++
	}
	for x := 100; x < 1000; x += 2 {
		cnt1 := [10]int{}
		for y := x; y > 0; y /= 10 {
			cnt1[y%10]++
		}
		ok := true
		for i := 0; i < 10 && ok; i++ {
			ok = cnt[i] >= cnt1[i]
		}
		if ok {
			ans = append(ans, x)
		}
	}
	return
}
```

#### TypeScript

```ts
function findEvenNumbers(digits: number[]): number[] {
    const cnt: number[] = Array(10).fill(0);
    for (const x of digits) {
        ++cnt[x];
    }
    const ans: number[] = [];
    for (let x = 100; x < 1000; x += 2) {
        const cnt1: number[] = Array(10).fill(0);
        for (let y = x; y; y = Math.floor(y / 10)) {
            ++cnt1[y % 10];
        }
        let ok = true;
        for (let i = 0; i < 10 && ok; ++i) {
            ok = cnt[i] >= cnt1[i];
        }
        if (ok) {
            ans.push(x);
        }
    }
    return ans;
}
```

#### JavaScript

```js
/**
 * @param {number[]} digits
 * @return {number[]}
 */
var findEvenNumbers = function (digits) {
    const cnt = Array(10).fill(0);
    for (const x of digits) {
        ++cnt[x];
    }
    const ans = [];
    for (let x = 100; x < 1000; x += 2) {
        const cnt1 = Array(10).fill(0);
        for (let y = x; y; y = Math.floor(y / 10)) {
            ++cnt1[y % 10];
        }
        let ok = true;
        for (let i = 0; i < 10 && ok; ++i) {
            ok = cnt[i] >= cnt1[i];
        }
        if (ok) {
            ans.push(x);
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

# [2095. 删除链表的中间节点](https://leetcode.cn/problems/delete-the-middle-node-of-a-linked-list){#2095}

{{< tabs "2095" >}}

{{% tab "python" %}}
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(next=head)
        slow, fast = dummy, head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        slow.next = slow.next.next
        return dummy.next
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
    public ListNode deleteMiddle(ListNode head) {
        ListNode dummy = new ListNode(0, head);
        ListNode slow = dummy, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        slow.next = slow.next.next;
        return dummy.next;
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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* slow = dummy;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
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
func deleteMiddle(head *ListNode) *ListNode {
	dummy := &ListNode{Val: 0, Next: head}
	slow, fast := dummy, dummy.Next
	for fast != nil && fast.Next != nil {
		slow, fast = slow.Next, fast.Next.Next
	}
	slow.Next = slow.Next.Next
	return dummy.Next
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

function deleteMiddle(head: ListNode | null): ListNode | null {
    const dummy = new ListNode(0, head);
    let [slow, fast] = [dummy, head];
    while (fast && fast.next) {
        slow = slow.next;
        fast = fast.next.next;
    }
    slow.next = slow.next.next;
    return dummy.next;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个链表的头节点 <code>head</code> 。<strong>删除</strong> 链表的 <strong>中间节点</strong> ，并返回修改后的链表的头节点 <code>head</code> 。</p>

<p>长度为 <code>n</code> 链表的中间节点是从头数起第 <code>⌊n / 2⌋</code> 个节点（下标从 <strong>0</strong> 开始），其中 <code>⌊x⌋</code> 表示小于或等于 <code>x</code> 的最大整数。</p>

<ul>
	<li>对于 <code>n</code> = <code>1</code>、<code>2</code>、<code>3</code>、<code>4</code> 和 <code>5</code> 的情况，中间节点的下标分别是 <code>0</code>、<code>1</code>、<code>1</code>、<code>2</code> 和 <code>2</code> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2095.Delete%20the%20Middle%20Node%20of%20a%20Linked%20List/images/eg1drawio.png" style="width: 500px; height: 77px;" /></p>

<pre>
<strong>输入：</strong>head = [1,3,4,7,1,2,6]
<strong>输出：</strong>[1,3,4,1,2,6]
<strong>解释：</strong>
上图表示给出的链表。节点的下标分别标注在每个节点的下方。
由于 n = 7 ，值为 7 的节点 3 是中间节点，用红色标注。
返回结果为移除节点后的新链表。 
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2095.Delete%20the%20Middle%20Node%20of%20a%20Linked%20List/images/eg2drawio.png" style="width: 250px; height: 43px;" /></p>

<pre>
<strong>输入：</strong>head = [1,2,3,4]
<strong>输出：</strong>[1,2,4]
<strong>解释：</strong>
上图表示给出的链表。
对于 n = 4 ，值为 3 的节点 2 是中间节点，用红色标注。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2095.Delete%20the%20Middle%20Node%20of%20a%20Linked%20List/images/eg3drawio.png" style="width: 150px; height: 58px;" /></p>

<pre>
<strong>输入：</strong>head = [2,1]
<strong>输出：</strong>[2]
<strong>解释：</strong>
上图表示给出的链表。
对于 n = 2 ，值为 1 的节点 1 是中间节点，用红色标注。
值为 2 的节点 0 是移除节点 1 后剩下的唯一一个节点。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表中节点的数目在范围 <code>[1, 10<sup>5</sup>]</code> 内</li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：快慢指针

快慢指针法是一种用于解决链表中的问题的常用技巧。我们可以维护两个指针，一个慢指针 $\textit{slow}$ 和一个快指针 $\textit{fast}$。初始时 $\textit{slow}$ 指向一个虚拟节点，该虚拟节点的 $\textit{next}$ 指针指向链表的头节点 $\textit{head}$，而 $\textit{fast}$ 指向链表的头节点 $\textit{head}$。

然后，我们每次将慢指针向后移动一个位置，将快指针向后移动两个位置，直到快指针到达链表的末尾。此时，慢指针指向的节点的下一个节点就是链表的中间节点。我们将慢指针指向的节点的 $\textit{next}$ 指针指向下下个节点，即可删除中间节点。

时间复杂度 $O(n)$，其中 $n$ 是链表的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(next=head)
        slow, fast = dummy, head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        slow.next = slow.next.next
        return dummy.next
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
    public ListNode deleteMiddle(ListNode head) {
        ListNode dummy = new ListNode(0, head);
        ListNode slow = dummy, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        slow.next = slow.next.next;
        return dummy.next;
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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* slow = dummy;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
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
func deleteMiddle(head *ListNode) *ListNode {
	dummy := &ListNode{Val: 0, Next: head}
	slow, fast := dummy, dummy.Next
	for fast != nil && fast.Next != nil {
		slow, fast = slow.Next, fast.Next.Next
	}
	slow.Next = slow.Next.Next
	return dummy.Next
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

function deleteMiddle(head: ListNode | null): ListNode | null {
    const dummy = new ListNode(0, head);
    let [slow, fast] = [dummy, head];
    while (fast && fast.next) {
        slow = slow.next;
        fast = fast.next.next;
    }
    slow.next = slow.next.next;
    return dummy.next;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2096. 从二叉树一个节点到另一个节点每一步的方向](https://leetcode.cn/problems/step-by-step-directions-from-a-binary-tree-node-to-another){#2096}

{{< tabs "2096" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def getDirections(
        self, root: Optional[TreeNode], startValue: int, destValue: int
    ) -> str:
        def dfs(node: Optional[TreeNode], x: int, path: List[str]):
            if node is None:
                return False
            if node.val == x:
                return True
            path.append("L")
            if dfs(node.left, x, path):
                return True
            path[-1] = "R"
            if dfs(node.right, x, path):
                return True
            path.pop()
            return False

        path_to_start = []
        path_to_dest = []

        dfs(root, startValue, path_to_start)
        dfs(root, destValue, path_to_dest)
        i = 0
        while (
            i < len(path_to_start)
            and i < len(path_to_dest)
            and path_to_start[i] == path_to_dest[i]
        ):
            i += 1
        return "U" * (len(path_to_start) - i) + "".join(path_to_dest[i:])
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String getDirections(TreeNode root, int startValue, int destValue) {
        StringBuilder pathToStart = new StringBuilder();
        StringBuilder pathToDest = new StringBuilder();
        dfs(root, startValue, pathToStart);
        dfs(root, destValue, pathToDest);
        int i = 0;
        while (i < pathToStart.length() && i < pathToDest.length()
            && pathToStart.charAt(i) == pathToDest.charAt(i)) {
            ++i;
        }
        return "U".repeat(pathToStart.length() - i) + pathToDest.substring(i);
    }

    private boolean dfs(TreeNode node, int x, StringBuilder path) {
        if (node == null) {
            return false;
        }
        if (node.val == x) {
            return true;
        }
        path.append('L');
        if (dfs(node.left, x, path)) {
            return true;
        }
        path.setCharAt(path.length() - 1, 'R');
        if (dfs(node.right, x, path)) {
            return true;
        }
        path.deleteCharAt(path.length() - 1);
        return false;
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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string pathToStart, pathToDest;
        dfs(root, startValue, pathToStart);
        dfs(root, destValue, pathToDest);
        int i = 0;
        while (i < pathToStart.size() && i < pathToDest.size() && pathToStart[i] == pathToDest[i]) {
            i++;
        }
        return string(pathToStart.size() - i, 'U') + pathToDest.substr(i);
    }

private:
    bool dfs(TreeNode* node, int x, string& path) {
        if (node == nullptr) {
            return false;
        }
        if (node->val == x) {
            return true;
        }
        path.push_back('L');
        if (dfs(node->left, x, path)) {
            return true;
        }
        path.back() = 'R';
        if (dfs(node->right, x, path)) {
            return true;
        }
        path.pop_back();
        return false;
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
func getDirections(root *TreeNode, startValue int, destValue int) string {
	var dfs func(node *TreeNode, x int, path *[]byte) bool
	dfs = func(node *TreeNode, x int, path *[]byte) bool {
		if node == nil {
			return false
		}
		if node.Val == x {
			return true
		}
		*path = append(*path, 'L')
		if dfs(node.Left, x, path) {
			return true
		}
		(*path)[len(*path)-1] = 'R'
		if dfs(node.Right, x, path) {
			return true
		}
		*path = (*path)[:len(*path)-1]
		return false
	}

	pathToStart := []byte{}
	pathToDest := []byte{}
	dfs(root, startValue, &pathToStart)
	dfs(root, destValue, &pathToDest)
	i := 0
	for i < len(pathToStart) && i < len(pathToDest) && pathToStart[i] == pathToDest[i] {
		i++
	}
	return string(bytes.Repeat([]byte{'U'}, len(pathToStart)-i)) + string(pathToDest[i:])
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

function getDirections(root: TreeNode | null, startValue: number, destValue: number): string {
    const dfs = (node: TreeNode | null, x: number, path: string[]): boolean => {
        if (node === null) {
            return false;
        }
        if (node.val === x) {
            return true;
        }
        path.push('L');
        if (dfs(node.left, x, path)) {
            return true;
        }
        path[path.length - 1] = 'R';
        if (dfs(node.right, x, path)) {
            return true;
        }
        path.pop();
        return false;
    };
    const pathToStart: string[] = [];
    const pathToDest: string[] = [];
    dfs(root, startValue, pathToStart);
    dfs(root, destValue, pathToDest);
    let i = 0;
    while (pathToStart[i] === pathToDest[i]) {
        ++i;
    }
    return 'U'.repeat(pathToStart.length - i) + pathToDest.slice(i).join('');
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
 * @param {number} startValue
 * @param {number} destValue
 * @return {string}
 */
var getDirections = function (root, startValue, destValue) {
    const dfs = (node, x, path) => {
        if (node === null) {
            return false;
        }
        if (node.val === x) {
            return true;
        }
        path.push('L');
        if (dfs(node.left, x, path)) {
            return true;
        }
        path[path.length - 1] = 'R';
        if (dfs(node.right, x, path)) {
            return true;
        }
        path.pop();
        return false;
    };
    const pathToStart = [];
    const pathToDest = [];
    dfs(root, startValue, pathToStart);
    dfs(root, destValue, pathToDest);
    let i = 0;
    while (pathToStart[i] === pathToDest[i]) {
        ++i;
    }
    return 'U'.repeat(pathToStart.length - i) + pathToDest.slice(i).join('');
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一棵 <strong>二叉树</strong>&nbsp;的根节点&nbsp;<code>root</code>&nbsp;，这棵二叉树总共有&nbsp;<code>n</code>&nbsp;个节点。每个节点的值为&nbsp;<code>1</code>&nbsp;到&nbsp;<code>n</code>&nbsp;中的一个整数，且互不相同。给你一个整数&nbsp;<code>startValue</code>&nbsp;，表示起点节点 <code>s</code>&nbsp;的值，和另一个不同的整数&nbsp;<code>destValue</code>&nbsp;，表示终点节点&nbsp;<code>t</code>&nbsp;的值。</p>

<p>请找到从节点&nbsp;<code>s</code>&nbsp;到节点 <code>t</code>&nbsp;的 <strong>最短路径</strong>&nbsp;，并以字符串的形式返回每一步的方向。每一步用 <strong>大写</strong>&nbsp;字母&nbsp;<code>'L'</code>&nbsp;，<code>'R'</code>&nbsp;和&nbsp;<code>'U'</code>&nbsp;分别表示一种方向：</p>

<ul>
	<li><code>'L'</code>&nbsp;表示从一个节点前往它的 <strong>左孩子</strong>&nbsp;节点。</li>
	<li><code>'R'</code>&nbsp;表示从一个节点前往它的 <strong>右孩子</strong>&nbsp;节点。</li>
	<li><code>'U'</code>&nbsp;表示从一个节点前往它的 <strong>父</strong>&nbsp;节点。</li>
</ul>

<p>请你返回从 <code>s</code>&nbsp;到 <code>t</code>&nbsp;<strong>最短路径</strong>&nbsp;每一步的方向。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2096.Step-By-Step%20Directions%20From%20a%20Binary%20Tree%20Node%20to%20Another/images/eg1.png" style="width: 214px; height: 163px;"></p>

<pre><b>输入：</b>root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
<b>输出：</b>"UURL"
<b>解释：</b>最短路径为：3 → 1 → 5 → 2 → 6 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2096.Step-By-Step%20Directions%20From%20a%20Binary%20Tree%20Node%20to%20Another/images/eg2.png" style="width: 74px; height: 102px;"></p>

<pre><b>输入：</b>root = [2,1], startValue = 2, destValue = 1
<b>输出：</b>"L"
<b>解释：</b>最短路径为：2 → 1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数目为&nbsp;<code>n</code>&nbsp;。</li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= Node.val &lt;= n</code></li>
	<li>树中所有节点的值 <strong>互不相同</strong>&nbsp;。</li>
	<li><code>1 &lt;= startValue, destValue &lt;= n</code></li>
	<li><code>startValue != destValue</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：最近公共祖先 + DFS

我们可以先找到节点 $\textit{startValue}$ 和 $\textit{destValue}$ 的最近公共祖先，记为 $\textit{node}$，然后分别从 $\textit{node}$ 出发，找到 $\textit{startValue}$ 和 $\textit{destValue}$ 的路径。那么从 $\textit{startValue}$ 到 $\textit{node}$ 的路径就是 $\textit{U}$ 的个数，从 $\textit{node}$ 到 $\textit{destValue}$ 的路径就是 $\textit{path}$ 的路径，最后将这两个路径拼接起来即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为二叉树的节点数。

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
    def getDirections(
        self, root: Optional[TreeNode], startValue: int, destValue: int
    ) -> str:
        def lca(node: Optional[TreeNode], p: int, q: int):
            if node is None or node.val in (p, q):
                return node
            left = lca(node.left, p, q)
            right = lca(node.right, p, q)
            if left and right:
                return node
            return left or right

        def dfs(node: Optional[TreeNode], x: int, path: List[str]):
            if node is None:
                return False
            if node.val == x:
                return True
            path.append("L")
            if dfs(node.left, x, path):
                return True
            path[-1] = "R"
            if dfs(node.right, x, path):
                return True
            path.pop()
            return False

        node = lca(root, startValue, destValue)

        path_to_start = []
        path_to_dest = []

        dfs(node, startValue, path_to_start)
        dfs(node, destValue, path_to_dest)

        return "U" * len(path_to_start) + "".join(path_to_dest)
```

#### Java

```java
class Solution {
    public String getDirections(TreeNode root, int startValue, int destValue) {
        TreeNode node = lca(root, startValue, destValue);
        StringBuilder pathToStart = new StringBuilder();
        StringBuilder pathToDest = new StringBuilder();
        dfs(node, startValue, pathToStart);
        dfs(node, destValue, pathToDest);
        return "U".repeat(pathToStart.length()) + pathToDest.toString();
    }

    private TreeNode lca(TreeNode node, int p, int q) {
        if (node == null || node.val == p || node.val == q) {
            return node;
        }
        TreeNode left = lca(node.left, p, q);
        TreeNode right = lca(node.right, p, q);
        if (left != null && right != null) {
            return node;
        }
        return left != null ? left : right;
    }

    private boolean dfs(TreeNode node, int x, StringBuilder path) {
        if (node == null) {
            return false;
        }
        if (node.val == x) {
            return true;
        }
        path.append('L');
        if (dfs(node.left, x, path)) {
            return true;
        }
        path.setCharAt(path.length() - 1, 'R');
        if (dfs(node.right, x, path)) {
            return true;
        }
        path.deleteCharAt(path.length() - 1);
        return false;
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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* node = lca(root, startValue, destValue);
        string pathToStart, pathToDest;
        dfs(node, startValue, pathToStart);
        dfs(node, destValue, pathToDest);
        return string(pathToStart.size(), 'U') + pathToDest;
    }

private:
    TreeNode* lca(TreeNode* node, int p, int q) {
        if (node == nullptr || node->val == p || node->val == q) {
            return node;
        }
        TreeNode* left = lca(node->left, p, q);
        TreeNode* right = lca(node->right, p, q);
        if (left != nullptr && right != nullptr) {
            return node;
        }
        return left != nullptr ? left : right;
    }

    bool dfs(TreeNode* node, int x, string& path) {
        if (node == nullptr) {
            return false;
        }
        if (node->val == x) {
            return true;
        }
        path.push_back('L');
        if (dfs(node->left, x, path)) {
            return true;
        }
        path.back() = 'R';
        if (dfs(node->right, x, path)) {
            return true;
        }
        path.pop_back();
        return false;
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
func getDirections(root *TreeNode, startValue int, destValue int) string {
	var lca func(node *TreeNode, p, q int) *TreeNode
	lca = func(node *TreeNode, p, q int) *TreeNode {
		if node == nil || node.Val == p || node.Val == q {
			return node
		}
		left := lca(node.Left, p, q)
		right := lca(node.Right, p, q)
		if left != nil && right != nil {
			return node
		}
		if left != nil {
			return left
		}
		return right
	}
	var dfs func(node *TreeNode, x int, path *[]byte) bool
	dfs = func(node *TreeNode, x int, path *[]byte) bool {
		if node == nil {
			return false
		}
		if node.Val == x {
			return true
		}
		*path = append(*path, 'L')
		if dfs(node.Left, x, path) {
			return true
		}
		(*path)[len(*path)-1] = 'R'
		if dfs(node.Right, x, path) {
			return true
		}
		*path = (*path)[:len(*path)-1]
		return false
	}

	node := lca(root, startValue, destValue)
	pathToStart := []byte{}
	pathToDest := []byte{}
	dfs(node, startValue, &pathToStart)
	dfs(node, destValue, &pathToDest)
	return string(bytes.Repeat([]byte{'U'}, len(pathToStart))) + string(pathToDest)
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

function getDirections(root: TreeNode | null, startValue: number, destValue: number): string {
    const lca = (node: TreeNode | null, p: number, q: number): TreeNode | null => {
        if (node === null || [p, q].includes(node.val)) {
            return node;
        }
        const left = lca(node.left, p, q);
        const right = lca(node.right, p, q);

        return left && right ? node : left ?? right;
    };

    const dfs = (node: TreeNode | null, x: number, path: string[]): boolean => {
        if (node === null) {
            return false;
        }
        if (node.val === x) {
            return true;
        }
        path.push('L');
        if (dfs(node.left, x, path)) {
            return true;
        }
        path[path.length - 1] = 'R';
        if (dfs(node.right, x, path)) {
            return true;
        }
        path.pop();
        return false;
    };

    const node = lca(root, startValue, destValue);
    const pathToStart: string[] = [];
    const pathToDest: string[] = [];
    dfs(node, startValue, pathToStart);
    dfs(node, destValue, pathToDest);
    return 'U'.repeat(pathToStart.length) + pathToDest.join('');
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
 * @param {number} startValue
 * @param {number} destValue
 * @return {string}
 */
var getDirections = function (root, startValue, destValue) {
    const lca = (node, p, q) => {
        if (node === null || [p, q].includes(node.val)) {
            return node;
        }
        const left = lca(node.left, p, q);
        const right = lca(node.right, p, q);

        return left && right ? node : left ?? right;
    };

    const dfs = (node, x, path) => {
        if (node === null) {
            return false;
        }
        if (node.val === x) {
            return true;
        }
        path.push('L');
        if (dfs(node.left, x, path)) {
            return true;
        }
        path[path.length - 1] = 'R';
        if (dfs(node.right, x, path)) {
            return true;
        }
        path.pop();
        return false;
    };

    const node = lca(root, startValue, destValue);
    const pathToStart = [];
    const pathToDest = [];
    dfs(node, startValue, pathToStart);
    dfs(node, destValue, pathToDest);
    return 'U'.repeat(pathToStart.length) + pathToDest.join('');
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：最近公共祖先 + DFS（优化）

我们可以从 $\textit{root}$ 出发，找到 $\textit{startValue}$ 和 $\textit{destValue}$ 的路径，记为 $\textit{pathToStart}$ 和 $\textit{pathToDest}$，然后去除 $\textit{pathToStart}$ 和 $\textit{pathToDest}$ 的最长公共前缀，此时 $\textit{pathToStart}$ 的路径长度就是答案中 $\textit{U}$ 的个数，而 $\textit{pathToDest}$ 的路径就是答案中的路径，我们只需要将这两个路径拼接起来即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为二叉树的节点数。

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
    def getDirections(
        self, root: Optional[TreeNode], startValue: int, destValue: int
    ) -> str:
        def dfs(node: Optional[TreeNode], x: int, path: List[str]):
            if node is None:
                return False
            if node.val == x:
                return True
            path.append("L")
            if dfs(node.left, x, path):
                return True
            path[-1] = "R"
            if dfs(node.right, x, path):
                return True
            path.pop()
            return False

        path_to_start = []
        path_to_dest = []

        dfs(root, startValue, path_to_start)
        dfs(root, destValue, path_to_dest)
        i = 0
        while (
            i < len(path_to_start)
            and i < len(path_to_dest)
            and path_to_start[i] == path_to_dest[i]
        ):
            i += 1
        return "U" * (len(path_to_start) - i) + "".join(path_to_dest[i:])
```

#### Java

```java
class Solution {
    public String getDirections(TreeNode root, int startValue, int destValue) {
        StringBuilder pathToStart = new StringBuilder();
        StringBuilder pathToDest = new StringBuilder();
        dfs(root, startValue, pathToStart);
        dfs(root, destValue, pathToDest);
        int i = 0;
        while (i < pathToStart.length() && i < pathToDest.length()
            && pathToStart.charAt(i) == pathToDest.charAt(i)) {
            ++i;
        }
        return "U".repeat(pathToStart.length() - i) + pathToDest.substring(i);
    }

    private boolean dfs(TreeNode node, int x, StringBuilder path) {
        if (node == null) {
            return false;
        }
        if (node.val == x) {
            return true;
        }
        path.append('L');
        if (dfs(node.left, x, path)) {
            return true;
        }
        path.setCharAt(path.length() - 1, 'R');
        if (dfs(node.right, x, path)) {
            return true;
        }
        path.deleteCharAt(path.length() - 1);
        return false;
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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string pathToStart, pathToDest;
        dfs(root, startValue, pathToStart);
        dfs(root, destValue, pathToDest);
        int i = 0;
        while (i < pathToStart.size() && i < pathToDest.size() && pathToStart[i] == pathToDest[i]) {
            i++;
        }
        return string(pathToStart.size() - i, 'U') + pathToDest.substr(i);
    }

private:
    bool dfs(TreeNode* node, int x, string& path) {
        if (node == nullptr) {
            return false;
        }
        if (node->val == x) {
            return true;
        }
        path.push_back('L');
        if (dfs(node->left, x, path)) {
            return true;
        }
        path.back() = 'R';
        if (dfs(node->right, x, path)) {
            return true;
        }
        path.pop_back();
        return false;
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
func getDirections(root *TreeNode, startValue int, destValue int) string {
	var dfs func(node *TreeNode, x int, path *[]byte) bool
	dfs = func(node *TreeNode, x int, path *[]byte) bool {
		if node == nil {
			return false
		}
		if node.Val == x {
			return true
		}
		*path = append(*path, 'L')
		if dfs(node.Left, x, path) {
			return true
		}
		(*path)[len(*path)-1] = 'R'
		if dfs(node.Right, x, path) {
			return true
		}
		*path = (*path)[:len(*path)-1]
		return false
	}

	pathToStart := []byte{}
	pathToDest := []byte{}
	dfs(root, startValue, &pathToStart)
	dfs(root, destValue, &pathToDest)
	i := 0
	for i < len(pathToStart) && i < len(pathToDest) && pathToStart[i] == pathToDest[i] {
		i++
	}
	return string(bytes.Repeat([]byte{'U'}, len(pathToStart)-i)) + string(pathToDest[i:])
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

function getDirections(root: TreeNode | null, startValue: number, destValue: number): string {
    const dfs = (node: TreeNode | null, x: number, path: string[]): boolean => {
        if (node === null) {
            return false;
        }
        if (node.val === x) {
            return true;
        }
        path.push('L');
        if (dfs(node.left, x, path)) {
            return true;
        }
        path[path.length - 1] = 'R';
        if (dfs(node.right, x, path)) {
            return true;
        }
        path.pop();
        return false;
    };
    const pathToStart: string[] = [];
    const pathToDest: string[] = [];
    dfs(root, startValue, pathToStart);
    dfs(root, destValue, pathToDest);
    let i = 0;
    while (pathToStart[i] === pathToDest[i]) {
        ++i;
    }
    return 'U'.repeat(pathToStart.length - i) + pathToDest.slice(i).join('');
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
 * @param {number} startValue
 * @param {number} destValue
 * @return {string}
 */
var getDirections = function (root, startValue, destValue) {
    const dfs = (node, x, path) => {
        if (node === null) {
            return false;
        }
        if (node.val === x) {
            return true;
        }
        path.push('L');
        if (dfs(node.left, x, path)) {
            return true;
        }
        path[path.length - 1] = 'R';
        if (dfs(node.right, x, path)) {
            return true;
        }
        path.pop();
        return false;
    };
    const pathToStart = [];
    const pathToDest = [];
    dfs(root, startValue, pathToStart);
    dfs(root, destValue, pathToDest);
    let i = 0;
    while (pathToStart[i] === pathToDest[i]) {
        ++i;
    }
    return 'U'.repeat(pathToStart.length - i) + pathToDest.slice(i).join('');
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2097. 合法重新排列数对](https://leetcode.cn/problems/valid-arrangement-of-pairs){#2097}

{{< tabs "2097" >}}

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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的二维整数数组&nbsp;<code>pairs</code>&nbsp;，其中&nbsp;<code>pairs[i] = [start<sub>i</sub>, end<sub>i</sub>]</code>&nbsp;。如果 <code>pairs</code>&nbsp;的一个重新排列，满足对每一个下标 <code>i</code> （&nbsp;<code>1 &lt;= i &lt; pairs.length</code>&nbsp;）都有&nbsp;<code>end<sub>i-1</sub> == start<sub>i</sub></code><sub> </sub>，那么我们就认为这个重新排列是&nbsp;<code>pairs</code> 的一个 <strong>合法重新排列</strong> 。</p>

<p>请你返回 <strong>任意一个</strong>&nbsp;<code>pairs</code> 的合法重新排列。</p>

<p><b>注意：</b>数据保证至少存在一个 <code>pairs</code>&nbsp;的合法重新排列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>pairs = [[5,1],[4,5],[11,9],[9,4]]
<b>输出：</b>[[11,9],[9,4],[4,5],[5,1]]
<strong>解释：
</strong>输出的是一个合法重新排列，因为每一个 end<sub>i-1</sub> 都等于 start<sub>i</sub>&nbsp;。
end<sub>0</sub> = 9 == 9 = start<sub>1</sub> 
end<sub>1</sub> = 4 == 4 = start<sub>2</sub>
end<sub>2</sub> = 5 == 5 = start<sub>3</sub>
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>pairs = [[1,3],[3,2],[2,1]]
<b>输出：</b>[[1,3],[3,2],[2,1]]
<strong>解释：</strong>
输出的是一个合法重新排列，因为每一个 end<sub>i-1</sub> 都等于 start<sub>i</sub>&nbsp;。
end<sub>0</sub> = 3 == 3 = start<sub>1</sub>
end<sub>1</sub> = 2 == 2 = start<sub>2</sub>
重新排列后的数组 [[2,1],[1,3],[3,2]] 和 [[3,2],[2,1],[1,3]] 都是合法的。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>pairs = [[1,2],[1,3],[2,1]]
<b>输出：</b>[[1,2],[2,1],[1,3]]
<strong>解释：</strong>
输出的是一个合法重新排列，因为每一个 end<sub>i-1</sub> 都等于 start<sub>i</sub>&nbsp;。
end<sub>0</sub> = 2 == 2 = start<sub>1</sub>
end<sub>1</sub> = 1 == 1 = start<sub>2</sub>
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= pairs.length &lt;= 10<sup>5</sup></code></li>
	<li><code>pairs[i].length == 2</code></li>
	<li><code>0 &lt;= start<sub>i</sub>, end<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
	<li><code>start<sub>i</sub> != end<sub>i</sub></code></li>
	<li><code>pairs</code>&nbsp;中不存在一模一样的数对。</li>
	<li>至少 <strong>存在</strong> 一个合法的&nbsp;<code>pairs</code>&nbsp;重新排列。</li>
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

# [2098. 长度为 K 的最大偶数和子序列 🔒](https://leetcode.cn/problems/subsequence-of-size-k-with-the-largest-even-sum){#2098}

{{< tabs "2098" >}}

{{% tab "python" %}}
```python
class Solution:
    def largestEvenSum(self, nums: List[int], k: int) -> int:
        nums.sort()
        ans = sum(nums[-k:])
        if ans % 2 == 0:
            return ans
        n = len(nums)
        mx1 = mx2 = -inf
        for x in nums[: n - k]:
            if x & 1:
                mx1 = x
            else:
                mx2 = x
        mi1 = mi2 = inf
        for x in nums[-k:][::-1]:
            if x & 1:
                mi2 = x
            else:
                mi1 = x
        ans = max(ans - mi1 + mx1, ans - mi2 + mx2, -1)
        return -1 if ans < 0 else ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long largestEvenSum(int[] nums, int k) {
        Arrays.sort(nums);
        long ans = 0;
        int n = nums.length;
        for (int i = 0; i < k; ++i) {
            ans += nums[n - i - 1];
        }
        if (ans % 2 == 0) {
            return ans;
        }
        final int inf = 1 << 29;
        int mx1 = -inf, mx2 = -inf;
        for (int i = 0; i < n - k; ++i) {
            if (nums[i] % 2 == 1) {
                mx1 = nums[i];
            } else {
                mx2 = nums[i];
            }
        }
        int mi1 = inf, mi2 = inf;
        for (int i = n - 1; i >= n - k; --i) {
            if (nums[i] % 2 == 1) {
                mi2 = nums[i];
            } else {
                mi1 = nums[i];
            }
        }
        ans = Math.max(ans - mi1 + mx1, ans - mi2 + mx2);
        return ans < 0 ? -1 : ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long largestEvenSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        int n = nums.size();
        for (int i = 0; i < k; ++i) {
            ans += nums[n - i - 1];
        }
        if (ans % 2 == 0) {
            return ans;
        }
        const int inf = 1 << 29;
        int mx1 = -inf, mx2 = -inf;
        for (int i = 0; i < n - k; ++i) {
            if (nums[i] % 2) {
                mx1 = nums[i];
            } else {
                mx2 = nums[i];
            }
        }
        int mi1 = inf, mi2 = inf;
        for (int i = n - 1; i >= n - k; --i) {
            if (nums[i] % 2) {
                mi2 = nums[i];
            } else {
                mi1 = nums[i];
            }
        }
        ans = max(ans - mi1 + mx1, ans - mi2 + mx2);
        return ans < 0 ? -1 : ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func largestEvenSum(nums []int, k int) int64 {
	sort.Ints(nums)
	ans := 0
	n := len(nums)
	for i := 0; i < k; i++ {
		ans += nums[n-1-i]
	}
	if ans%2 == 0 {
		return int64(ans)
	}
	const inf = 1 << 29
	mx1, mx2 := -inf, -inf
	for _, x := range nums[:n-k] {
		if x%2 == 1 {
			mx1 = x
		} else {
			mx2 = x
		}
	}
	mi1, mi2 := inf, inf
	for i := n - 1; i >= n-k; i-- {
		if nums[i]%2 == 1 {
			mi2 = nums[i]
		} else {
			mi1 = nums[i]
		}
	}
	ans = max(-1, max(ans-mi1+mx1, ans-mi2+mx2))
	if ans%2 < 0 {
		return -1
	}
	return int64(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function largestEvenSum(nums: number[], k: number): number {
    nums.sort((a, b) => a - b);
    let ans = 0;
    const n = nums.length;
    for (let i = 0; i < k; ++i) {
        ans += nums[n - i - 1];
    }
    if (ans % 2 === 0) {
        return ans;
    }
    const inf = 1 << 29;
    let mx1 = -inf,
        mx2 = -inf;
    for (let i = 0; i < n - k; ++i) {
        if (nums[i] % 2 === 1) {
            mx1 = nums[i];
        } else {
            mx2 = nums[i];
        }
    }
    let mi1 = inf,
        mi2 = inf;
    for (let i = n - 1; i >= n - k; --i) {
        if (nums[i] % 2 === 1) {
            mi2 = nums[i];
        } else {
            mi1 = nums[i];
        }
    }
    ans = Math.max(ans - mi1 + mx1, ans - mi2 + mx2);
    return ans < 0 ? -1 : ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code> 和一个整数 <code>k</code> 。找出&nbsp;<code>nums</code> 长度为 <code>k</code> 的所有子序列中的 <strong>最大偶数和</strong> 。<br />
返回<strong>此总和</strong>，如果此总和不存在，则返回 <code>-1</code>。<br />
<strong>子序列</strong> 是一个数组，可以通过删除一些元素或不删除任何元素而从另一个数组派生，而不改变其余元素的顺序。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入:</strong> nums = [4,1,5,3,1], k = 3
<strong>输出:</strong> 12
<strong>解释:</strong>
具有最大可能偶数和的子序列是[4,5,3]。它的和为 4 + 5 + 3 = 12
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> nums = [4,6,2], k = 3
<strong>输出:</strong> 12
<strong>解释:</strong>
具有最大可能偶数和的子序列是[4,6,2]。它的和为 4 + 6 + 2 = 12
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> nums = [1,3,5], k = 1
<strong>输出:</strong> -1
<strong>解释:</strong>
长度为 1 的 NUM 的子序列没有偶数和。
</pre>

<p>&nbsp;</p>

<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= nums.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 排序

我们注意到，题目选取的是子序列，因此我们可以考虑先对数组进行排序。

接下来，我们先贪心地选取最大的 $k$ 个数，如果这些数的和为偶数，则直接返回这个和 $ans$。

否则，我们有两种贪心策略：

1. 在最大的 $k$ 个数中，找到一个最小的偶数 $mi1$，然后在剩下的 $n - k$ 个数中，找到一个最大的奇数 $mx1$，将 $mi1$ 替换为 $mx1$，如果存在这样的替换，那么替换后的和 $ans - mi1 + mx1$ 一定是偶数；
1. 在最大的 $k$ 个数中，找到一个最小的奇数 $mi2$，然后在剩下的 $n - k$ 个数中，找到一个最大的偶数 $mx2$，将 $mi2$ 替换为 $mx2$，如果存在这样的替换，那么替换后的和 $ans - mi2 + mx2$ 一定是偶数。

我们取最大的偶数和作为答案。如果不存在偶数和，则返回 $-1$。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为数组长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def largestEvenSum(self, nums: List[int], k: int) -> int:
        nums.sort()
        ans = sum(nums[-k:])
        if ans % 2 == 0:
            return ans
        n = len(nums)
        mx1 = mx2 = -inf
        for x in nums[: n - k]:
            if x & 1:
                mx1 = x
            else:
                mx2 = x
        mi1 = mi2 = inf
        for x in nums[-k:][::-1]:
            if x & 1:
                mi2 = x
            else:
                mi1 = x
        ans = max(ans - mi1 + mx1, ans - mi2 + mx2, -1)
        return -1 if ans < 0 else ans
```

#### Java

```java
class Solution {
    public long largestEvenSum(int[] nums, int k) {
        Arrays.sort(nums);
        long ans = 0;
        int n = nums.length;
        for (int i = 0; i < k; ++i) {
            ans += nums[n - i - 1];
        }
        if (ans % 2 == 0) {
            return ans;
        }
        final int inf = 1 << 29;
        int mx1 = -inf, mx2 = -inf;
        for (int i = 0; i < n - k; ++i) {
            if (nums[i] % 2 == 1) {
                mx1 = nums[i];
            } else {
                mx2 = nums[i];
            }
        }
        int mi1 = inf, mi2 = inf;
        for (int i = n - 1; i >= n - k; --i) {
            if (nums[i] % 2 == 1) {
                mi2 = nums[i];
            } else {
                mi1 = nums[i];
            }
        }
        ans = Math.max(ans - mi1 + mx1, ans - mi2 + mx2);
        return ans < 0 ? -1 : ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long largestEvenSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        int n = nums.size();
        for (int i = 0; i < k; ++i) {
            ans += nums[n - i - 1];
        }
        if (ans % 2 == 0) {
            return ans;
        }
        const int inf = 1 << 29;
        int mx1 = -inf, mx2 = -inf;
        for (int i = 0; i < n - k; ++i) {
            if (nums[i] % 2) {
                mx1 = nums[i];
            } else {
                mx2 = nums[i];
            }
        }
        int mi1 = inf, mi2 = inf;
        for (int i = n - 1; i >= n - k; --i) {
            if (nums[i] % 2) {
                mi2 = nums[i];
            } else {
                mi1 = nums[i];
            }
        }
        ans = max(ans - mi1 + mx1, ans - mi2 + mx2);
        return ans < 0 ? -1 : ans;
    }
};
```

#### Go

```go
func largestEvenSum(nums []int, k int) int64 {
	sort.Ints(nums)
	ans := 0
	n := len(nums)
	for i := 0; i < k; i++ {
		ans += nums[n-1-i]
	}
	if ans%2 == 0 {
		return int64(ans)
	}
	const inf = 1 << 29
	mx1, mx2 := -inf, -inf
	for _, x := range nums[:n-k] {
		if x%2 == 1 {
			mx1 = x
		} else {
			mx2 = x
		}
	}
	mi1, mi2 := inf, inf
	for i := n - 1; i >= n-k; i-- {
		if nums[i]%2 == 1 {
			mi2 = nums[i]
		} else {
			mi1 = nums[i]
		}
	}
	ans = max(-1, max(ans-mi1+mx1, ans-mi2+mx2))
	if ans%2 < 0 {
		return -1
	}
	return int64(ans)
}
```

#### TypeScript

```ts
function largestEvenSum(nums: number[], k: number): number {
    nums.sort((a, b) => a - b);
    let ans = 0;
    const n = nums.length;
    for (let i = 0; i < k; ++i) {
        ans += nums[n - i - 1];
    }
    if (ans % 2 === 0) {
        return ans;
    }
    const inf = 1 << 29;
    let mx1 = -inf,
        mx2 = -inf;
    for (let i = 0; i < n - k; ++i) {
        if (nums[i] % 2 === 1) {
            mx1 = nums[i];
        } else {
            mx2 = nums[i];
        }
    }
    let mi1 = inf,
        mi2 = inf;
    for (let i = n - 1; i >= n - k; --i) {
        if (nums[i] % 2 === 1) {
            mi2 = nums[i];
        } else {
            mi1 = nums[i];
        }
    }
    ans = Math.max(ans - mi1 + mx1, ans - mi2 + mx2);
    return ans < 0 ? -1 : ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2099. 找到和最大的长度为 K 的子序列](https://leetcode.cn/problems/find-subsequence-of-length-k-with-the-largest-sum){#2099}

{{< tabs "2099" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxSubsequence(self, nums: List[int], k: int) -> List[int]:
        idx = sorted(range(len(nums)), key=lambda i: nums[i])[-k:]
        return [nums[i] for i in sorted(idx)]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] maxSubsequence(int[] nums, int k) {
        int n = nums.length;
        Integer[] idx = new Integer[n];
        Arrays.setAll(idx, i -> i);
        Arrays.sort(idx, (i, j) -> nums[i] - nums[j]);
        Arrays.sort(idx, n - k, n);
        int[] ans = new int[k];
        for (int i = n - k; i < n; ++i) {
            ans[i - (n - k)] = nums[idx[i]];
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
#include <ranges>

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> idx(n);
        ranges::iota(idx, 0);
        ranges::sort(idx, [&](int i, int j) { return nums[i] < nums[j]; });
        ranges::sort(idx | views::drop(n - k));
        vector<int> ans(k);
        for (int i = n - k; i < n; ++i) {
            ans[i - (n - k)] = nums[idx[i]];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxSubsequence(nums []int, k int) []int {
	idx := slices.Clone(make([]int, len(nums)))
	for i := range idx {
		idx[i] = i
	}
	slices.SortFunc(idx, func(i, j int) int { return nums[i] - nums[j] })
	slices.Sort(idx[len(idx)-k:])
	ans := make([]int, k)
	for i := range ans {
		ans[i] = nums[idx[len(idx)-k+i]]
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxSubsequence(nums: number[], k: number): number[] {
    const n = nums.length;
    const idx: number[] = Array.from({ length: n }, (_, i) => i);
    idx.sort((i, j) => nums[i] - nums[j]);
    return idx
        .slice(n - k)
        .sort((i, j) => i - j)
        .map(i => nums[i]);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn max_subsequence(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let n = nums.len();
        let k = k as usize;
        let mut idx: Vec<usize> = (0..n).collect();

        idx.sort_by_key(|&i| nums[i]);
        idx[n - k..].sort();

        let mut ans = Vec::with_capacity(k);
        for i in n - k..n {
            ans.push(nums[idx[i]]);
        }

        ans
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;。你需要找到&nbsp;<code>nums</code>&nbsp;中长度为 <code>k</code>&nbsp;的 <strong>子序列</strong>&nbsp;，且这个子序列的&nbsp;<strong>和最大&nbsp;</strong>。</p>

<p>请你返回 <strong>任意</strong> 一个长度为&nbsp;<code>k</code>&nbsp;的整数子序列。</p>

<p><strong>子序列</strong>&nbsp;定义为从一个数组里删除一些元素后，不改变剩下元素的顺序得到的数组。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [2,1,3,3], k = 2
<b>输出：</b>[3,3]
<strong>解释：</strong>
子序列有最大和：3 + 3 = 6 。</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [-1,-2,3,4], k = 3
<b>输出：</b>[-1,3,4]
<b>解释：</b>
子序列有最大和：-1 + 3 + 4 = 6 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>nums = [3,4,3,3], k = 2
<b>输出：</b>[3,4]
<strong>解释：</strong>
子序列有最大和：3 + 4 = 7 。
另一个可行的子序列为 [4, 3] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>-10<sup>5</sup>&nbsp;&lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= nums.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序

我们先创建一个索引数组 $\textit{idx}$，数组中的每个元素是数组 $\textit{nums}$ 的下标。然后我们根据数组 $\textit{nums}$ 的值对索引数组 $\textit{idx}$ 进行排序，排序的规则是 $\textit{nums}[i] < \textit{nums}[j]$，其中 $i$ 和 $j$ 是索引数组 $\textit{idx}$ 中的两个下标。

排序完成后，我们取索引数组 $\textit{idx}$ 的最后 $k$ 个元素，这 $k$ 个元素对应的就是数组 $\textit{nums}$ 中最大的 $k$ 个元素。然后我们对这 $k$ 个下标进行排序，得到的就是最大的 $k$ 个元素在数组 $\textit{nums}$ 中的顺序。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxSubsequence(self, nums: List[int], k: int) -> List[int]:
        idx = sorted(range(len(nums)), key=lambda i: nums[i])[-k:]
        return [nums[i] for i in sorted(idx)]
```

#### Java

```java
class Solution {
    public int[] maxSubsequence(int[] nums, int k) {
        int n = nums.length;
        Integer[] idx = new Integer[n];
        Arrays.setAll(idx, i -> i);
        Arrays.sort(idx, (i, j) -> nums[i] - nums[j]);
        Arrays.sort(idx, n - k, n);
        int[] ans = new int[k];
        for (int i = n - k; i < n; ++i) {
            ans[i - (n - k)] = nums[idx[i]];
        }
        return ans;
    }
}
```

#### C++

```cpp
#include <ranges>

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> idx(n);
        ranges::iota(idx, 0);
        ranges::sort(idx, [&](int i, int j) { return nums[i] < nums[j]; });
        ranges::sort(idx | views::drop(n - k));
        vector<int> ans(k);
        for (int i = n - k; i < n; ++i) {
            ans[i - (n - k)] = nums[idx[i]];
        }
        return ans;
    }
};
```

#### Go

```go
func maxSubsequence(nums []int, k int) []int {
	idx := slices.Clone(make([]int, len(nums)))
	for i := range idx {
		idx[i] = i
	}
	slices.SortFunc(idx, func(i, j int) int { return nums[i] - nums[j] })
	slices.Sort(idx[len(idx)-k:])
	ans := make([]int, k)
	for i := range ans {
		ans[i] = nums[idx[len(idx)-k+i]]
	}
	return ans
}
```

#### TypeScript

```ts
function maxSubsequence(nums: number[], k: number): number[] {
    const n = nums.length;
    const idx: number[] = Array.from({ length: n }, (_, i) => i);
    idx.sort((i, j) => nums[i] - nums[j]);
    return idx
        .slice(n - k)
        .sort((i, j) => i - j)
        .map(i => nums[i]);
}
```

#### Rust

```rust
impl Solution {
    pub fn max_subsequence(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let n = nums.len();
        let k = k as usize;
        let mut idx: Vec<usize> = (0..n).collect();

        idx.sort_by_key(|&i| nums[i]);
        idx[n - k..].sort();

        let mut ans = Vec::with_capacity(k);
        for i in n - k..n {
            ans.push(nums[idx[i]]);
        }

        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
