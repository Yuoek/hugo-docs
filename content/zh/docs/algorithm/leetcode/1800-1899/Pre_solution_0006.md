---
title: "1850_邻位交换的最小次数"
date: 2025-10-08T18:38:27+08:00
weight: 6
tags: [二分查找, 前缀和, 动态规划, 单调栈, 双指针, 哈希表, 图, 堆（优先队列）, 字典树, 字符串, 扫描线, 拓扑排序, 排序, 数据库, 数组, 栈, 深度优先搜索, 滑动窗口, 计数, 记忆化搜索, 贪心]
---

{{< markmap >}}
### [1850_邻位交换的最小次数](#1850)
#### [贪心](#1850)
#### [双指针](#1850)
#### [字符串](#1850)
### [1851_包含每个查询的最小区间](#1851)
#### [数组](#1851)
#### [二分查找](#1851)
#### [排序](#1851)
#### [扫描线](#1851)
#### [堆（优先队列）](#1851)
### [1852_每个子数组的数字种类数 🔒](#1852)
#### [数组](#1852)
#### [哈希表](#1852)
#### [滑动窗口](#1852)
### [1853_转换日期格式 🔒](#1853)
#### [数据库](#1853)
### [1854_人口最多的年份](#1854)
#### [数组](#1854)
#### [计数](#1854)
#### [前缀和](#1854)
### [1855_下标对中的最大距离](#1855)
#### [数组](#1855)
#### [双指针](#1855)
#### [二分查找](#1855)
### [1856_子数组最小乘积的最大值](#1856)
#### [栈](#1856)
#### [数组](#1856)
#### [前缀和](#1856)
#### [单调栈](#1856)
### [1857_有向图中最大颜色值](#1857)
#### [图](#1857)
#### [拓扑排序](#1857)
#### [记忆化搜索](#1857)
#### [哈希表](#1857)
#### [动态规划](#1857)
#### [计数](#1857)
### [1858_包含所有前缀的最长单词 🔒](#1858)
#### [深度优先搜索](#1858)
#### [字典树](#1858)
#### [数组](#1858)
#### [字符串](#1858)
### [1859_将句子排序](#1859)
#### [字符串](#1859)
#### [排序](#1859)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1850_邻位交换的最小次数
___
#### 贪心
___
#### 双指针
___
#### 字符串
---
### 1851_包含每个查询的最小区间
___
#### 数组
___
#### 二分查找
___
#### 排序
___
#### 扫描线
___
#### 堆（优先队列）
---
### 1852_每个子数组的数字种类数 🔒
___
#### 数组
___
#### 哈希表
___
#### 滑动窗口
---
### 1853_转换日期格式 🔒
___
#### 数据库
---
### 1854_人口最多的年份
___
#### 数组
___
#### 计数
___
#### 前缀和
---
### 1855_下标对中的最大距离
___
#### 数组
___
#### 双指针
___
#### 二分查找
---
### 1856_子数组最小乘积的最大值
___
#### 栈
___
#### 数组
___
#### 前缀和
___
#### 单调栈
---
### 1857_有向图中最大颜色值
___
#### 图
___
#### 拓扑排序
___
#### 记忆化搜索
___
#### 哈希表
___
#### 动态规划
___
#### 计数
---
### 1858_包含所有前缀的最长单词 🔒
___
#### 深度优先搜索
___
#### 字典树
___
#### 数组
___
#### 字符串
---
### 1859_将句子排序
___
#### 字符串
___
#### 排序
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 前缀和 | 动态规划 |
| 单调栈 | 双指针 | 哈希表 |
| 图 | 堆（优先队列） | 字典树 |
| 字符串 | 扫描线 | 拓扑排序 |
| 排序 | 数据库 | 数组 |
| 栈 | 深度优先搜索 | 滑动窗口 |
| 计数 | 记忆化搜索 | 贪心 |

# [1850. 邻位交换的最小次数](https://leetcode.cn/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number){#1850}

{{< tabs "1850" >}}

{{% tab "python" %}}
```python
class Solution:
    def getMinSwaps(self, num: str, k: int) -> int:
        def next_permutation(nums: List[str]) -> bool:
            n = len(nums)
            i = n - 2
            while i >= 0 and nums[i] >= nums[i + 1]:
                i -= 1
            if i < 0:
                return False
            j = n - 1
            while j >= 0 and nums[j] <= nums[i]:
                j -= 1
            nums[i], nums[j] = nums[j], nums[i]
            nums[i + 1 : n] = nums[i + 1 : n][::-1]
            return True

        s = list(num)
        for _ in range(k):
            next_permutation(s)
        d = [[] for _ in range(10)]
        idx = [0] * 10
        n = len(s)
        for i, c in enumerate(num):
            j = ord(c) - ord("0")
            d[j].append(i)
        arr = [0] * n
        for i, c in enumerate(s):
            j = ord(c) - ord("0")
            arr[i] = d[j][idx[j]]
            idx[j] += 1
        return sum(arr[j] > arr[i] for i in range(n) for j in range(i))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int getMinSwaps(String num, int k) {
        char[] s = num.toCharArray();
        for (int i = 0; i < k; ++i) {
            nextPermutation(s);
        }
        List<Integer>[] d = new List[10];
        Arrays.setAll(d, i -> new ArrayList<>());
        int n = s.length;
        for (int i = 0; i < n; ++i) {
            d[num.charAt(i) - '0'].add(i);
        }
        int[] idx = new int[10];
        int[] arr = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = d[s[i] - '0'].get(idx[s[i] - '0']++);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (arr[j] > arr[i]) {
                    ++ans;
                }
            }
        }
        return ans;
    }

    private boolean nextPermutation(char[] nums) {
        int n = nums.length;
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            --i;
        }
        if (i < 0) {
            return false;
        }
        int j = n - 1;
        while (j >= 0 && nums[i] >= nums[j]) {
            --j;
        }
        swap(nums, i++, j);
        for (j = n - 1; i < j; ++i, --j) {
            swap(nums, i, j);
        }
        return true;
    }

    private void swap(char[] nums, int i, int j) {
        char t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int getMinSwaps(string num, int k) {
        string s = num;
        for (int i = 0; i < k; ++i) {
            next_permutation(begin(s), end(num));
        }
        vector<int> d[10];
        int n = num.size();
        for (int i = 0; i < n; ++i) {
            d[num[i] - '0'].push_back(i);
        }
        int idx[10]{};
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = d[s[i] - '0'][idx[s[i] - '0']++];
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (arr[j] > arr[i]) {
                    ++ans;
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
func getMinSwaps(num string, k int) (ans int) {
	s := []byte(num)
	for ; k > 0; k-- {
		nextPermutation(s)
	}
	d := [10][]int{}
	for i, c := range num {
		j := int(c - '0')
		d[j] = append(d[j], i)
	}
	idx := [10]int{}
	n := len(s)
	arr := make([]int, n)
	for i, c := range s {
		j := int(c - '0')
		arr[i] = d[j][idx[j]]
		idx[j]++
	}
	for i := 0; i < n; i++ {
		for j := 0; j < i; j++ {
			if arr[j] > arr[i] {
				ans++
			}
		}
	}
	return
}

func nextPermutation(nums []byte) bool {
	n := len(nums)
	i := n - 2
	for i >= 0 && nums[i] >= nums[i+1] {
		i--
	}
	if i < 0 {
		return false
	}
	j := n - 1
	for j >= 0 && nums[j] <= nums[i] {
		j--
	}
	nums[i], nums[j] = nums[j], nums[i]
	for i, j = i+1, n-1; i < j; i, j = i+1, j-1 {
		nums[i], nums[j] = nums[j], nums[i]
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function getMinSwaps(num: string, k: number): number {
    const n = num.length;
    const s = num.split('');
    for (let i = 0; i < k; ++i) {
        nextPermutation(s);
    }
    const d: number[][] = Array.from({ length: 10 }, () => []);
    for (let i = 0; i < n; ++i) {
        d[+num[i]].push(i);
    }
    const idx: number[] = Array(10).fill(0);
    const arr: number[] = [];
    for (let i = 0; i < n; ++i) {
        arr.push(d[+s[i]][idx[+s[i]]++]);
    }
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < i; ++j) {
            if (arr[j] > arr[i]) {
                ans++;
            }
        }
    }
    return ans;
}

function nextPermutation(nums: string[]): boolean {
    const n = nums.length;
    let i = n - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }
    if (i < 0) {
        return false;
    }
    let j = n - 1;
    while (j >= 0 && nums[i] >= nums[j]) {
        j--;
    }
    [nums[i], nums[j]] = [nums[j], nums[i]];
    for (i = i + 1, j = n - 1; i < j; ++i, --j) {
        [nums[i], nums[j]] = [nums[j], nums[i]];
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

<p>给你一个表示大整数的字符串 <code>num</code> ，和一个整数 <code>k</code> 。</p>

<p>如果某个整数是 <code>num</code> 中各位数字的一个 <strong>排列</strong> 且它的 <strong>值大于</strong> <code>num</code> ，则称这个整数为 <strong>妙数</strong> 。可能存在很多妙数，但是只需要关注 <strong>值最小</strong> 的那些。</p>

<ul>
	<li>例如，<code>num = "5489355142"</code> ：

    <ul>
    	<li>第 1 个最小妙数是 <code>"5489355214"</code></li>
    	<li>第 2 个最小妙数是 <code>"5489355241"</code></li>
    	<li>第 3 个最小妙数是 <code>"5489355412"</code></li>
    	<li>第 4 个最小妙数是 <code>"5489355421"</code></li>
    </ul>
    </li>

</ul>

<p>返回要得到第 <code>k</code> 个 <strong>最小妙数</strong> 需要对 <code>num</code> 执行的 <strong>相邻位数字交换的最小次数</strong> 。</p>

<p>测试用例是按存在第 <code>k</code> 个最小妙数而生成的。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>num = "5489355142", k = 4
<strong>输出：</strong>2
<strong>解释：</strong>第 4 个最小妙数是 "5489355421" ，要想得到这个数字：
- 交换下标 7 和下标 8 对应的位："5489355<strong>14</strong>2" -&gt; "5489355<strong>41</strong>2"
- 交换下标 8 和下标 9 对应的位："54893554<strong>12</strong>" -&gt; "54893554<strong>21</strong>"
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>num = "11112", k = 4
<strong>输出：</strong>4
<strong>解释：</strong>第 4 个最小妙数是 "21111" ，要想得到这个数字：
- 交换下标 3 和下标 4 对应的位："111<strong>12</strong>" -&gt; "111<strong>21</strong>"
- 交换下标 2 和下标 3 对应的位："11<strong>12</strong>1" -&gt; "11<strong>21</strong>1"
- 交换下标 1 和下标 2 对应的位："1<strong>12</strong>11" -&gt; "1<strong>21</strong>11"
- 交换下标 0 和下标 1 对应的位："<strong>12</strong>111" -&gt; "<strong>21</strong>111"
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>num = "00123", k = 1
<strong>输出：</strong>1
<strong>解释：</strong>第 1 个最小妙数是 "00132" ，要想得到这个数字：
- 交换下标 3 和下标 4 对应的位："001<strong>23</strong>" -&gt; "001<strong>32</strong>"
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= num.length &lt;= 1000</code></li>
	<li><code>1 &lt;= k &lt;= 1000</code></li>
	<li><code>num</code> 仅由数字组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：求下一个排列 + 逆序对

我们可以调用 $k$ 次 `next_permutation` 函数，得到第 $k$ 个最小妙数 $s$。

接下来，我们只需要计算 $num$ 需要经过多少次交换才能变成 $s$ 即可。

我们先考虑一个简单的情况，即 $num$ 中的数字都不相同。在这种情况下，我们可以直接把 $num$ 中的数字字符映射为下标。例如 $num$ 等于 `"54893"`，而 $s$ 等于 `"98345"`。我们将 $num$ 中的每个数字映射为下标，即：

$$
\begin{aligned}
num[0] &= 5 &\rightarrow& \quad 0 \\
num[1] &= 4 &\rightarrow& \quad 1 \\
num[2] &= 8 &\rightarrow& \quad 2 \\
num[3] &= 9 &\rightarrow& \quad 3 \\
num[4] &= 3 &\rightarrow& \quad 4 \\
\end{aligned}
$$

那么 $s$ 中的每个数字映射为下标，就是 `"32410"`。这样，将 $num$ 变成 $s$ 所需要的交换次数，就等于 $s$ 映射后的下标数组的逆序对数。

如果 $num$ 中存在相同的数字，那么我们可以使用一个数组 $d$ 来记录每个数字出现的下标，其中 $d[i]$ 表示数字 $i$ 出现的下标列表。为了使得交换次数尽可能少，在将 $s$ 映射为下标数组时，我们只需要按顺序贪心地选择 $d$ 中对应数字的下标即可。

最后，我们可以直接使用双重循环来计算逆序对数，也可以使用树状数组来优化。

时间复杂度 $O(n \times (k + n))$，空间复杂度 $O(n)$。其中 $n$ 是 $num$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getMinSwaps(self, num: str, k: int) -> int:
        def next_permutation(nums: List[str]) -> bool:
            n = len(nums)
            i = n - 2
            while i >= 0 and nums[i] >= nums[i + 1]:
                i -= 1
            if i < 0:
                return False
            j = n - 1
            while j >= 0 and nums[j] <= nums[i]:
                j -= 1
            nums[i], nums[j] = nums[j], nums[i]
            nums[i + 1 : n] = nums[i + 1 : n][::-1]
            return True

        s = list(num)
        for _ in range(k):
            next_permutation(s)
        d = [[] for _ in range(10)]
        idx = [0] * 10
        n = len(s)
        for i, c in enumerate(num):
            j = ord(c) - ord("0")
            d[j].append(i)
        arr = [0] * n
        for i, c in enumerate(s):
            j = ord(c) - ord("0")
            arr[i] = d[j][idx[j]]
            idx[j] += 1
        return sum(arr[j] > arr[i] for i in range(n) for j in range(i))
```

#### Java

```java
class Solution {
    public int getMinSwaps(String num, int k) {
        char[] s = num.toCharArray();
        for (int i = 0; i < k; ++i) {
            nextPermutation(s);
        }
        List<Integer>[] d = new List[10];
        Arrays.setAll(d, i -> new ArrayList<>());
        int n = s.length;
        for (int i = 0; i < n; ++i) {
            d[num.charAt(i) - '0'].add(i);
        }
        int[] idx = new int[10];
        int[] arr = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = d[s[i] - '0'].get(idx[s[i] - '0']++);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (arr[j] > arr[i]) {
                    ++ans;
                }
            }
        }
        return ans;
    }

    private boolean nextPermutation(char[] nums) {
        int n = nums.length;
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            --i;
        }
        if (i < 0) {
            return false;
        }
        int j = n - 1;
        while (j >= 0 && nums[i] >= nums[j]) {
            --j;
        }
        swap(nums, i++, j);
        for (j = n - 1; i < j; ++i, --j) {
            swap(nums, i, j);
        }
        return true;
    }

    private void swap(char[] nums, int i, int j) {
        char t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int getMinSwaps(string num, int k) {
        string s = num;
        for (int i = 0; i < k; ++i) {
            next_permutation(begin(s), end(num));
        }
        vector<int> d[10];
        int n = num.size();
        for (int i = 0; i < n; ++i) {
            d[num[i] - '0'].push_back(i);
        }
        int idx[10]{};
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = d[s[i] - '0'][idx[s[i] - '0']++];
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (arr[j] > arr[i]) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func getMinSwaps(num string, k int) (ans int) {
	s := []byte(num)
	for ; k > 0; k-- {
		nextPermutation(s)
	}
	d := [10][]int{}
	for i, c := range num {
		j := int(c - '0')
		d[j] = append(d[j], i)
	}
	idx := [10]int{}
	n := len(s)
	arr := make([]int, n)
	for i, c := range s {
		j := int(c - '0')
		arr[i] = d[j][idx[j]]
		idx[j]++
	}
	for i := 0; i < n; i++ {
		for j := 0; j < i; j++ {
			if arr[j] > arr[i] {
				ans++
			}
		}
	}
	return
}

func nextPermutation(nums []byte) bool {
	n := len(nums)
	i := n - 2
	for i >= 0 && nums[i] >= nums[i+1] {
		i--
	}
	if i < 0 {
		return false
	}
	j := n - 1
	for j >= 0 && nums[j] <= nums[i] {
		j--
	}
	nums[i], nums[j] = nums[j], nums[i]
	for i, j = i+1, n-1; i < j; i, j = i+1, j-1 {
		nums[i], nums[j] = nums[j], nums[i]
	}
	return true
}
```

#### TypeScript

```ts
function getMinSwaps(num: string, k: number): number {
    const n = num.length;
    const s = num.split('');
    for (let i = 0; i < k; ++i) {
        nextPermutation(s);
    }
    const d: number[][] = Array.from({ length: 10 }, () => []);
    for (let i = 0; i < n; ++i) {
        d[+num[i]].push(i);
    }
    const idx: number[] = Array(10).fill(0);
    const arr: number[] = [];
    for (let i = 0; i < n; ++i) {
        arr.push(d[+s[i]][idx[+s[i]]++]);
    }
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < i; ++j) {
            if (arr[j] > arr[i]) {
                ans++;
            }
        }
    }
    return ans;
}

function nextPermutation(nums: string[]): boolean {
    const n = nums.length;
    let i = n - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }
    if (i < 0) {
        return false;
    }
    let j = n - 1;
    while (j >= 0 && nums[i] >= nums[j]) {
        j--;
    }
    [nums[i], nums[j]] = [nums[j], nums[i]];
    for (i = i + 1, j = n - 1; i < j; ++i, --j) {
        [nums[i], nums[j]] = [nums[j], nums[i]];
    }
    return true;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1851. 包含每个查询的最小区间](https://leetcode.cn/problems/minimum-interval-to-include-each-query){#1851}

{{< tabs "1851" >}}

{{% tab "python" %}}
```python
class Solution:
    def minInterval(self, intervals: List[List[int]], queries: List[int]) -> List[int]:
        n, m = len(intervals), len(queries)
        intervals.sort()
        queries = sorted((x, i) for i, x in enumerate(queries))
        ans = [-1] * m
        pq = []
        i = 0
        for x, j in queries:
            while i < n and intervals[i][0] <= x:
                a, b = intervals[i]
                heappush(pq, (b - a + 1, b))
                i += 1
            while pq and pq[0][1] < x:
                heappop(pq)
            if pq:
                ans[j] = pq[0][0]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] minInterval(int[][] intervals, int[] queries) {
        int n = intervals.length, m = queries.length;
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);
        int[][] qs = new int[m][0];
        for (int i = 0; i < m; ++i) {
            qs[i] = new int[] {queries[i], i};
        }
        Arrays.sort(qs, (a, b) -> a[0] - b[0]);
        int[] ans = new int[m];
        Arrays.fill(ans, -1);
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        int i = 0;
        for (int[] q : qs) {
            while (i < n && intervals[i][0] <= q[0]) {
                int a = intervals[i][0], b = intervals[i][1];
                pq.offer(new int[] {b - a + 1, b});
                ++i;
            }
            while (!pq.isEmpty() && pq.peek()[1] < q[0]) {
                pq.poll();
            }
            if (!pq.isEmpty()) {
                ans[q[1]] = pq.peek()[0];
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
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size(), m = queries.size();
        sort(intervals.begin(), intervals.end());
        using pii = pair<int, int>;
        vector<pii> qs;
        for (int i = 0; i < m; ++i) {
            qs.emplace_back(queries[i], i);
        }
        sort(qs.begin(), qs.end());
        vector<int> ans(m, -1);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        int i = 0;
        for (auto& [x, j] : qs) {
            while (i < n && intervals[i][0] <= x) {
                int a = intervals[i][0], b = intervals[i][1];
                pq.emplace(b - a + 1, b);
                ++i;
            }
            while (!pq.empty() && pq.top().second < x) {
                pq.pop();
            }
            if (!pq.empty()) {
                ans[j] = pq.top().first;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minInterval(intervals [][]int, queries []int) []int {
	n, m := len(intervals), len(queries)
	sort.Slice(intervals, func(i, j int) bool { return intervals[i][0] < intervals[j][0] })
	qs := make([][2]int, m)
	ans := make([]int, m)
	for i := range qs {
		qs[i] = [2]int{queries[i], i}
		ans[i] = -1
	}
	sort.Slice(qs, func(i, j int) bool { return qs[i][0] < qs[j][0] })
	pq := hp{}
	i := 0
	for _, q := range qs {
		x, j := q[0], q[1]
		for i < n && intervals[i][0] <= x {
			a, b := intervals[i][0], intervals[i][1]
			heap.Push(&pq, pair{b - a + 1, b})
			i++
		}
		for len(pq) > 0 && pq[0].r < x {
			heap.Pop(&pq)
		}
		if len(pq) > 0 {
			ans[j] = pq[0].v
		}
	}
	return ans
}

type pair struct{ v, r int }
type hp []pair

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].v < h[j].v }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)        { *h = append(*h, v.(pair)) }
func (h *hp) Pop() any          { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个二维整数数组 <code>intervals</code> ，其中 <code>intervals[i] = [left<sub>i</sub>, right<sub>i</sub>]</code> 表示第 <code>i</code> 个区间开始于 <code>left<sub>i</sub></code> 、结束于 <code>right<sub>i</sub></code>（包含两侧取值，<strong>闭区间</strong>）。区间的 <strong>长度</strong> 定义为区间中包含的整数数目，更正式地表达是 <code>right<sub>i</sub> - left<sub>i</sub> + 1</code> 。</p>

<p>再给你一个整数数组 <code>queries</code> 。第 <code>j</code> 个查询的答案是满足&nbsp;<code>left<sub>i</sub> &lt;= queries[j] &lt;= right<sub>i</sub></code> 的 <strong>长度最小区间 <code>i</code> 的长度</strong> 。如果不存在这样的区间，那么答案是 <code>-1</code> 。</p>

<p>以数组形式返回对应查询的所有答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>intervals = [[1,4],[2,4],[3,6],[4,4]], queries = [2,3,4,5]
<strong>输出：</strong>[3,3,1,4]
<strong>解释：</strong>查询处理如下：
- Query = 2 ：区间 [2,4] 是包含 2 的最小区间，答案为 4 - 2 + 1 = 3 。
- Query = 3 ：区间 [2,4] 是包含 3 的最小区间，答案为 4 - 2 + 1 = 3 。
- Query = 4 ：区间 [4,4] 是包含 4 的最小区间，答案为 4 - 4 + 1 = 1 。
- Query = 5 ：区间 [3,6] 是包含 5 的最小区间，答案为 6 - 3 + 1 = 4 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>intervals = [[2,3],[2,5],[1,8],[20,25]], queries = [2,19,5,22]
<strong>输出：</strong>[2,-1,4,6]
<strong>解释：</strong>查询处理如下：
- Query = 2 ：区间 [2,3] 是包含 2 的最小区间，答案为 3 - 2 + 1 = 2 。
- Query = 19：不存在包含 19 的区间，答案为 -1 。
- Query = 5 ：区间 [2,5] 是包含 5 的最小区间，答案为 5 - 2 + 1 = 4 。
- Query = 22：区间 [20,25] 是包含 22 的最小区间，答案为 25 - 20 + 1 = 6 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= intervals.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>intervals[i].length == 2</code></li>
	<li><code>1 &lt;= left<sub>i</sub> &lt;= right<sub>i</sub> &lt;= 10<sup>7</sup></code></li>
	<li><code>1 &lt;= queries[j] &lt;= 10<sup>7</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 离线查询 + 优先队列（小根堆）

我们注意到，题目中查询的顺序并不会影响答案，并且涉及到的区间也不会发生变化，因此，我们考虑将所有的查询按照从小到大的顺序进行排序，同时将所有的区间按照左端点从小到大的顺序进行排序。

我们使用一个优先队列（小根堆） $pq$ 来维护当前所有的区间，队列的每个元素是一个二元组 $(v, r)$，表示一个区间长度为 $v$，右端点为 $r$ 的区间。初始时，优先队列为空。另外，我们定义一个指针 $i$，指向当前遍历到的区间，初始时 $i=0$。

我们按照从小到大的顺序依次遍历每个查询 $(x, j)$，并进行如下操作：

-   如果指针 $i$ 尚未遍历完所有的区间，并且当前遍历到的区间 $[a, b]$ 的左端点小于等于 $x$，那么我们将该区间加入优先队列中，并将指针 $i$ 后移一位，循环此过程；
-   如果优先队列不为空，并且堆顶元素的右端点小于 $x$，那么我们将堆顶元素弹出，循环此过程；
-   此时，如果优先队列不为空，那么堆顶元素就是包含 $x$ 的最小区间。我们将其长度 $v$ 加入答案数组 $ans$ 中。

在上述过程结束后，我们返回答案数组 $ans$ 即可。

时间复杂度 $O(n \times \log n + m \times \log m)$，空间复杂度 $O(n + m)$。其中 $n$ 和 $m$ 分别是数组 $intervals$ 和 $queries$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minInterval(self, intervals: List[List[int]], queries: List[int]) -> List[int]:
        n, m = len(intervals), len(queries)
        intervals.sort()
        queries = sorted((x, i) for i, x in enumerate(queries))
        ans = [-1] * m
        pq = []
        i = 0
        for x, j in queries:
            while i < n and intervals[i][0] <= x:
                a, b = intervals[i]
                heappush(pq, (b - a + 1, b))
                i += 1
            while pq and pq[0][1] < x:
                heappop(pq)
            if pq:
                ans[j] = pq[0][0]
        return ans
```

#### Java

```java
class Solution {
    public int[] minInterval(int[][] intervals, int[] queries) {
        int n = intervals.length, m = queries.length;
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);
        int[][] qs = new int[m][0];
        for (int i = 0; i < m; ++i) {
            qs[i] = new int[] {queries[i], i};
        }
        Arrays.sort(qs, (a, b) -> a[0] - b[0]);
        int[] ans = new int[m];
        Arrays.fill(ans, -1);
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        int i = 0;
        for (int[] q : qs) {
            while (i < n && intervals[i][0] <= q[0]) {
                int a = intervals[i][0], b = intervals[i][1];
                pq.offer(new int[] {b - a + 1, b});
                ++i;
            }
            while (!pq.isEmpty() && pq.peek()[1] < q[0]) {
                pq.poll();
            }
            if (!pq.isEmpty()) {
                ans[q[1]] = pq.peek()[0];
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
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size(), m = queries.size();
        sort(intervals.begin(), intervals.end());
        using pii = pair<int, int>;
        vector<pii> qs;
        for (int i = 0; i < m; ++i) {
            qs.emplace_back(queries[i], i);
        }
        sort(qs.begin(), qs.end());
        vector<int> ans(m, -1);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        int i = 0;
        for (auto& [x, j] : qs) {
            while (i < n && intervals[i][0] <= x) {
                int a = intervals[i][0], b = intervals[i][1];
                pq.emplace(b - a + 1, b);
                ++i;
            }
            while (!pq.empty() && pq.top().second < x) {
                pq.pop();
            }
            if (!pq.empty()) {
                ans[j] = pq.top().first;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minInterval(intervals [][]int, queries []int) []int {
	n, m := len(intervals), len(queries)
	sort.Slice(intervals, func(i, j int) bool { return intervals[i][0] < intervals[j][0] })
	qs := make([][2]int, m)
	ans := make([]int, m)
	for i := range qs {
		qs[i] = [2]int{queries[i], i}
		ans[i] = -1
	}
	sort.Slice(qs, func(i, j int) bool { return qs[i][0] < qs[j][0] })
	pq := hp{}
	i := 0
	for _, q := range qs {
		x, j := q[0], q[1]
		for i < n && intervals[i][0] <= x {
			a, b := intervals[i][0], intervals[i][1]
			heap.Push(&pq, pair{b - a + 1, b})
			i++
		}
		for len(pq) > 0 && pq[0].r < x {
			heap.Pop(&pq)
		}
		if len(pq) > 0 {
			ans[j] = pq[0].v
		}
	}
	return ans
}

type pair struct{ v, r int }
type hp []pair

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].v < h[j].v }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)        { *h = append(*h, v.(pair)) }
func (h *hp) Pop() any          { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1852. 每个子数组的数字种类数 🔒](https://leetcode.cn/problems/distinct-numbers-in-each-subarray){#1852}

{{< tabs "1852" >}}

{{% tab "python" %}}
```python
class Solution:
    def distinctNumbers(self, nums: List[int], k: int) -> List[int]:
        cnt = Counter(nums[:k])
        ans = [len(cnt)]
        for i in range(k, len(nums)):
            cnt[nums[i]] += 1
            cnt[nums[i - k]] -= 1
            if cnt[nums[i - k]] == 0:
                cnt.pop(nums[i - k])
            ans.append(len(cnt))
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] distinctNumbers(int[] nums, int k) {
        int m = 0;
        for (int x : nums) {
            m = Math.max(m, x);
        }
        int[] cnt = new int[m + 1];
        int v = 0;
        for (int i = 0; i < k; ++i) {
            if (++cnt[nums[i]] == 1) {
                ++v;
            }
        }
        int n = nums.length;
        int[] ans = new int[n - k + 1];
        ans[0] = v;
        for (int i = k; i < n; ++i) {
            if (++cnt[nums[i]] == 1) {
                ++v;
            }
            if (--cnt[nums[i - k]] == 0) {
                --v;
            }
            ans[i - k + 1] = v;
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
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        int m = *max_element(begin(nums), end(nums));
        int cnt[m + 1];
        memset(cnt, 0, sizeof(cnt));
        int n = nums.size();
        int v = 0;
        vector<int> ans(n - k + 1);
        for (int i = 0; i < k; ++i) {
            if (++cnt[nums[i]] == 1) {
                ++v;
            }
        }
        ans[0] = v;
        for (int i = k; i < n; ++i) {
            if (++cnt[nums[i]] == 1) {
                ++v;
            }
            if (--cnt[nums[i - k]] == 0) {
                --v;
            }
            ans[i - k + 1] = v;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func distinctNumbers(nums []int, k int) (ans []int) {
	m := slices.Max(nums)
	cnt := make([]int, m+1)
	v := 0
	for _, x := range nums[:k] {
		cnt[x]++
		if cnt[x] == 1 {
			v++
		}
	}
	ans = append(ans, v)
	for i := k; i < len(nums); i++ {
		cnt[nums[i]]++
		if cnt[nums[i]] == 1 {
			v++
		}
		cnt[nums[i-k]]--
		if cnt[nums[i-k]] == 0 {
			v--
		}
		ans = append(ans, v)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function distinctNumbers(nums: number[], k: number): number[] {
    const m = Math.max(...nums);
    const cnt: number[] = Array(m + 1).fill(0);
    let v: number = 0;
    for (let i = 0; i < k; ++i) {
        if (++cnt[nums[i]] === 1) {
            v++;
        }
    }
    const ans: number[] = [v];
    for (let i = k; i < nums.length; ++i) {
        if (++cnt[nums[i]] === 1) {
            v++;
        }
        if (--cnt[nums[i - k]] === 0) {
            v--;
        }
        ans.push(v);
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

<p>给你一个长度为&nbsp;<code>n</code>&nbsp;的整数数组&nbsp;<code>nums</code>&nbsp;与一个整数 <code>k</code>。你的任务是找到&nbsp;<code>nums</code>&nbsp;<strong>所有</strong>&nbsp;长度为&nbsp;<code>k</code>&nbsp;的子数组中&nbsp;<strong>不同</strong>&nbsp;元素的数量。</p>

<p>返回一个数组 <code>ans</code>，其中&nbsp;<code>ans[i]</code>&nbsp;是对于每个索引&nbsp;<code>0 &lt;= i &lt; n - k</code>，<code>nums[i..(i + k - 1)]</code>&nbsp;中不同元素的数量。</p>

<p>&nbsp;</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> nums = [1,2,3,2,2,1,3], k = 3
<strong>输出:</strong> [3,2,2,2,3]
<b>解释</b>：每个子数组的数字种类计算方法如下：
- nums[0..2] = [1,2,3] 所以 ans[0] = 3
- nums[1..3] = [2,3,2] 所以 ans[1] = 2
- nums[2..4] = [3,2,2] 所以 ans[2] = 2
- nums[3..5] = [2,2,1] 所以 ans[3] = 2
- nums[4..6] = [2,1,3] 所以 ans[4] = 3
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre>
<strong>输入:</strong> nums = [1,1,1,1,2,3,4], k = 4
<strong>输出:</strong> [1,2,3,4]
<strong>解释: </strong>每个子数组的数字种类计算方法如下：
- nums[0..3] = [1,1,1,1] 所以 ans[0] = 1
- nums[1..4] = [1,1,1,2] 所以 ans[1] = 2
- nums[2..5] = [1,1,2,3] 所以 ans[2] = 3
- nums[3..6] = [1,2,3,4] 所以 ans[3] = 4
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：滑动窗口 + 哈希表

我们用一个哈希表 $cnt$ 记录每个长度为 $k$ 的子数组中数字的出现次数。

接下来，我们首先遍历数组前 $k$ 个元素，记录每个元素出现的次数，遍历后，我们将哈希表的大小作为答案数组的第一个元素。

然后，我们从下标 $k$ 继续遍历数组，每次遍历时，我们将当前元素的出现次数加一，并且将当前元素左边的元素的出现次数减一，如果减一后的出现次数为 $0$，则将其从哈希表中删除，然后将哈希表的大小作为答案数组的下一个元素，继续遍历。

遍历结束后，我们返回答案数组。

时间复杂度 $O(n)$，空间复杂度 $O(k)$。其中 $n$ 为数组 $nums$ 的长度，而 $k$ 为题目给定的参数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def distinctNumbers(self, nums: List[int], k: int) -> List[int]:
        cnt = Counter(nums[:k])
        ans = [len(cnt)]
        for i in range(k, len(nums)):
            cnt[nums[i]] += 1
            cnt[nums[i - k]] -= 1
            if cnt[nums[i - k]] == 0:
                cnt.pop(nums[i - k])
            ans.append(len(cnt))
        return ans
```

#### Java

```java
class Solution {
    public int[] distinctNumbers(int[] nums, int k) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int i = 0; i < k; ++i) {
            cnt.merge(nums[i], 1, Integer::sum);
        }
        int n = nums.length;
        int[] ans = new int[n - k + 1];
        ans[0] = cnt.size();
        for (int i = k; i < n; ++i) {
            cnt.merge(nums[i], 1, Integer::sum);
            if (cnt.merge(nums[i - k], -1, Integer::sum) == 0) {
                cnt.remove(nums[i - k]);
            }
            ans[i - k + 1] = cnt.size();
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for (int i = 0; i < k; ++i) {
            ++cnt[nums[i]];
        }
        int n = nums.size();
        vector<int> ans;
        ans.push_back(cnt.size());
        for (int i = k; i < n; ++i) {
            ++cnt[nums[i]];
            if (--cnt[nums[i - k]] == 0) {
                cnt.erase(nums[i - k]);
            }
            ans.push_back(cnt.size());
        }
        return ans;
    }
};
```

#### Go

```go
func distinctNumbers(nums []int, k int) []int {
	cnt := map[int]int{}
	for _, x := range nums[:k] {
		cnt[x]++
	}
	ans := []int{len(cnt)}
	for i := k; i < len(nums); i++ {
		cnt[nums[i]]++
		cnt[nums[i-k]]--
		if cnt[nums[i-k]] == 0 {
			delete(cnt, nums[i-k])
		}
		ans = append(ans, len(cnt))
	}
	return ans
}
```

#### TypeScript

```ts
function distinctNumbers(nums: number[], k: number): number[] {
    const cnt: Map<number, number> = new Map();
    for (let i = 0; i < k; ++i) {
        cnt.set(nums[i], (cnt.get(nums[i]) ?? 0) + 1);
    }
    const ans: number[] = [cnt.size];
    for (let i = k; i < nums.length; ++i) {
        cnt.set(nums[i], (cnt.get(nums[i]) ?? 0) + 1);
        cnt.set(nums[i - k], cnt.get(nums[i - k])! - 1);
        if (cnt.get(nums[i - k]) === 0) {
            cnt.delete(nums[i - k]);
        }
        ans.push(cnt.size);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：滑动窗口 + 数组

我们也可以用数组来代替哈希表，这样可以提升一定的性能。

时间复杂度 $O(n)$，空间复杂度 $O(M)$。其中 $n$ 为数组 $nums$ 的长度，而 $M$ 为数组 $nums$ 中的最大值，本题中 $M \leq 10^5$。

<!-- tabs:start -->

#### Java

```java
class Solution {
    public int[] distinctNumbers(int[] nums, int k) {
        int m = 0;
        for (int x : nums) {
            m = Math.max(m, x);
        }
        int[] cnt = new int[m + 1];
        int v = 0;
        for (int i = 0; i < k; ++i) {
            if (++cnt[nums[i]] == 1) {
                ++v;
            }
        }
        int n = nums.length;
        int[] ans = new int[n - k + 1];
        ans[0] = v;
        for (int i = k; i < n; ++i) {
            if (++cnt[nums[i]] == 1) {
                ++v;
            }
            if (--cnt[nums[i - k]] == 0) {
                --v;
            }
            ans[i - k + 1] = v;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        int m = *max_element(begin(nums), end(nums));
        int cnt[m + 1];
        memset(cnt, 0, sizeof(cnt));
        int n = nums.size();
        int v = 0;
        vector<int> ans(n - k + 1);
        for (int i = 0; i < k; ++i) {
            if (++cnt[nums[i]] == 1) {
                ++v;
            }
        }
        ans[0] = v;
        for (int i = k; i < n; ++i) {
            if (++cnt[nums[i]] == 1) {
                ++v;
            }
            if (--cnt[nums[i - k]] == 0) {
                --v;
            }
            ans[i - k + 1] = v;
        }
        return ans;
    }
};
```

#### Go

```go
func distinctNumbers(nums []int, k int) (ans []int) {
	m := slices.Max(nums)
	cnt := make([]int, m+1)
	v := 0
	for _, x := range nums[:k] {
		cnt[x]++
		if cnt[x] == 1 {
			v++
		}
	}
	ans = append(ans, v)
	for i := k; i < len(nums); i++ {
		cnt[nums[i]]++
		if cnt[nums[i]] == 1 {
			v++
		}
		cnt[nums[i-k]]--
		if cnt[nums[i-k]] == 0 {
			v--
		}
		ans = append(ans, v)
	}
	return
}
```

#### TypeScript

```ts
function distinctNumbers(nums: number[], k: number): number[] {
    const m = Math.max(...nums);
    const cnt: number[] = Array(m + 1).fill(0);
    let v: number = 0;
    for (let i = 0; i < k; ++i) {
        if (++cnt[nums[i]] === 1) {
            v++;
        }
    }
    const ans: number[] = [v];
    for (let i = k; i < nums.length; ++i) {
        if (++cnt[nums[i]] === 1) {
            v++;
        }
        if (--cnt[nums[i - k]] === 0) {
            v--;
        }
        ans.push(v);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1853. 转换日期格式 🔒](https://leetcode.cn/problems/convert-date-format){#1853}

{{< tabs "1853" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT DATE_FORMAT(day, '%W, %M %e, %Y') AS day FROM Days;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Days</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| day         | date |
+-------------+------+
day 是这个表的主键。
</pre>

<p>&nbsp;</p>

<p>给定一个<code>Days</code>表，请你编写SQL查询语句，将<code>Days</code>表中的每一个日期转化为<code>"day_name, month_name day, year"</code>格式的字符串。</p>

<p>返回的结果表 <strong>不计顺序</strong> 。</p>

<p>查询结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Days table:
+------------+
| day        |
+------------+
| 2022-04-12 |
| 2021-08-09 |
| 2020-06-26 |
+------------+
<strong>输出：</strong>
+-------------------------+
| day                     |
+-------------------------+
| Tuesday, April 12, 2022 |
| Monday, August 9, 2021  |
| Friday, June 26, 2020   |
+-------------------------+
<strong>解释：</strong>请注意，输出对大小写敏感。</pre>

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
SELECT DATE_FORMAT(day, '%W, %M %e, %Y') AS day FROM Days;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1854. 人口最多的年份](https://leetcode.cn/problems/maximum-population-year){#1854}

{{< tabs "1854" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumPopulation(self, logs: List[List[int]]) -> int:
        d = [0] * 101
        offset = 1950
        for a, b in logs:
            a, b = a - offset, b - offset
            d[a] += 1
            d[b] -= 1
        s = mx = j = 0
        for i, x in enumerate(d):
            s += x
            if mx < s:
                mx, j = s, i
        return j + offset
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumPopulation(int[][] logs) {
        int[] d = new int[101];
        final int offset = 1950;
        for (var log : logs) {
            int a = log[0] - offset;
            int b = log[1] - offset;
            ++d[a];
            --d[b];
        }
        int s = 0, mx = 0;
        int j = 0;
        for (int i = 0; i < d.length; ++i) {
            s += d[i];
            if (mx < s) {
                mx = s;
                j = i;
            }
        }
        return j + offset;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int d[101]{};
        const int offset = 1950;
        for (auto& log : logs) {
            int a = log[0] - offset;
            int b = log[1] - offset;
            ++d[a];
            --d[b];
        }
        int s = 0, mx = 0;
        int j = 0;
        for (int i = 0; i < 101; ++i) {
            s += d[i];
            if (mx < s) {
                mx = s;
                j = i;
            }
        }
        return j + offset;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumPopulation(logs [][]int) int {
	d := [101]int{}
	offset := 1950
	for _, log := range logs {
		a, b := log[0]-offset, log[1]-offset
		d[a]++
		d[b]--
	}
	var s, mx, j int
	for i, x := range d {
		s += x
		if mx < s {
			mx = s
			j = i
		}
	}
	return j + offset
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumPopulation(logs: number[][]): number {
    const d: number[] = new Array(101).fill(0);
    const offset = 1950;
    for (const [birth, death] of logs) {
        d[birth - offset]++;
        d[death - offset]--;
    }
    let j = 0;
    for (let i = 0, s = 0, mx = 0; i < d.length; ++i) {
        s += d[i];
        if (mx < s) {
            mx = s;
            j = i;
        }
    }
    return j + offset;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[][]} logs
 * @return {number}
 */
var maximumPopulation = function (logs) {
    const d = new Array(101).fill(0);
    const offset = 1950;
    for (let [a, b] of logs) {
        a -= offset;
        b -= offset;
        d[a]++;
        d[b]--;
    }
    let j = 0;
    for (let i = 0, s = 0, mx = 0; i < 101; ++i) {
        s += d[i];
        if (mx < s) {
            mx = s;
            j = i;
        }
    }
    return j + offset;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个二维整数数组 <code>logs</code> ，其中每个 <code>logs[i] = [birth<sub>i</sub>, death<sub>i</sub>]</code> 表示第 <code>i</code> 个人的出生和死亡年份。</p>

<p>年份 <code>x</code> 的 <strong>人口</strong> 定义为这一年期间活着的人的数目。第 <code>i</code> 个人被计入年份 <code>x</code> 的人口需要满足：<code>x</code> 在闭区间 <code>[birth<sub>i</sub>, death<sub>i</sub> - 1]</code> 内。注意，人不应当计入他们死亡当年的人口中。</p>

<p>返回 <strong>人口最多</strong> 且 <strong>最早</strong> 的年份。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>logs = [[1993,1999],[2000,2010]]
<strong>输出：</strong>1993
<strong>解释：</strong>人口最多为 1 ，而 1993 是人口为 1 的最早年份。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>logs = [[1950,1961],[1960,1971],[1970,1981]]
<strong>输出：</strong>1960
<strong>解释：</strong> 
人口最多为 2 ，分别出现在 1960 和 1970 。
其中最早年份是 1960 。</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= logs.length &lt;= 100</code></li>
	<li><code>1950 &lt;= birth<sub>i</sub> &lt; death<sub>i</sub> &lt;= 2050</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：差分数组

我们注意到，年份的范围是 $[1950,..2050]$，因此我们可以将这些年份映射到一个长度为 $101$ 的数组 $d$ 中，数组的下标表示年份减去 $1950$ 的值。

接下来遍历 $logs$，对于每个人，我们将 $d[birth_i - 1950]$ 加 $1$，将 $d[death_i - 1950]$ 减 $1$。最后遍历数组 $d$，求出前缀和的最大值，即为人口最多的年份，再加上 $1950$ 即为答案。

时间复杂度 $O(n)$，空间复杂度 $O(C)$。其中 $n$ 为数组 $logs$ 的长度；而 $C$ 为年份的范围大小，即 $2050 - 1950 + 1 = 101$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumPopulation(self, logs: List[List[int]]) -> int:
        d = [0] * 101
        offset = 1950
        for a, b in logs:
            a, b = a - offset, b - offset
            d[a] += 1
            d[b] -= 1
        s = mx = j = 0
        for i, x in enumerate(d):
            s += x
            if mx < s:
                mx, j = s, i
        return j + offset
```

#### Java

```java
class Solution {
    public int maximumPopulation(int[][] logs) {
        int[] d = new int[101];
        final int offset = 1950;
        for (var log : logs) {
            int a = log[0] - offset;
            int b = log[1] - offset;
            ++d[a];
            --d[b];
        }
        int s = 0, mx = 0;
        int j = 0;
        for (int i = 0; i < d.length; ++i) {
            s += d[i];
            if (mx < s) {
                mx = s;
                j = i;
            }
        }
        return j + offset;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int d[101]{};
        const int offset = 1950;
        for (auto& log : logs) {
            int a = log[0] - offset;
            int b = log[1] - offset;
            ++d[a];
            --d[b];
        }
        int s = 0, mx = 0;
        int j = 0;
        for (int i = 0; i < 101; ++i) {
            s += d[i];
            if (mx < s) {
                mx = s;
                j = i;
            }
        }
        return j + offset;
    }
};
```

#### Go

```go
func maximumPopulation(logs [][]int) int {
	d := [101]int{}
	offset := 1950
	for _, log := range logs {
		a, b := log[0]-offset, log[1]-offset
		d[a]++
		d[b]--
	}
	var s, mx, j int
	for i, x := range d {
		s += x
		if mx < s {
			mx = s
			j = i
		}
	}
	return j + offset
}
```

#### TypeScript

```ts
function maximumPopulation(logs: number[][]): number {
    const d: number[] = new Array(101).fill(0);
    const offset = 1950;
    for (const [birth, death] of logs) {
        d[birth - offset]++;
        d[death - offset]--;
    }
    let j = 0;
    for (let i = 0, s = 0, mx = 0; i < d.length; ++i) {
        s += d[i];
        if (mx < s) {
            mx = s;
            j = i;
        }
    }
    return j + offset;
}
```

#### JavaScript

```js
/**
 * @param {number[][]} logs
 * @return {number}
 */
var maximumPopulation = function (logs) {
    const d = new Array(101).fill(0);
    const offset = 1950;
    for (let [a, b] of logs) {
        a -= offset;
        b -= offset;
        d[a]++;
        d[b]--;
    }
    let j = 0;
    for (let i = 0, s = 0, mx = 0; i < 101; ++i) {
        s += d[i];
        if (mx < s) {
            mx = s;
            j = i;
        }
    }
    return j + offset;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1855. 下标对中的最大距离](https://leetcode.cn/problems/maximum-distance-between-a-pair-of-values){#1855}

{{< tabs "1855" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxDistance(self, nums1: List[int], nums2: List[int]) -> int:
        m, n = len(nums1), len(nums2)
        ans = i = j = 0
        while i < m:
            while j < n and nums1[i] <= nums2[j]:
                j += 1
            ans = max(ans, j - i - 1)
            i += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxDistance(int[] nums1, int[] nums2) {
        int m = nums1.length, n = nums2.length;
        int ans = 0;
        for (int i = 0, j = 0; i < m; ++i) {
            while (j < n && nums1[i] <= nums2[j]) {
                ++j;
            }
            ans = Math.max(ans, j - i - 1);
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
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int ans = 0;
        for (int i = 0, j = 0; i < m; ++i) {
            while (j < n && nums1[i] <= nums2[j]) {
                ++j;
            }
            ans = max(ans, j - i - 1);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxDistance(nums1 []int, nums2 []int) int {
	m, n := len(nums1), len(nums2)
	ans := 0
	for i, j := 0, 0; i < m; i++ {
		for j < n && nums1[i] <= nums2[j] {
			j++
		}
		if ans < j-i-1 {
			ans = j - i - 1
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxDistance(nums1: number[], nums2: number[]): number {
    let ans = 0;
    const m = nums1.length;
    const n = nums2.length;
    for (let i = 0, j = 0; i < m; ++i) {
        while (j < n && nums1[i] <= nums2[j]) {
            j++;
        }
        ans = Math.max(ans, j - i - 1);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn max_distance(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
        let m = nums1.len();
        let n = nums2.len();
        let mut res = 0;
        let mut j = 0;
        for i in 0..m {
            while j < n && nums1[i] <= nums2[j] {
                j += 1;
            }
            res = res.max((j - i - 1) as i32);
        }
        res
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var maxDistance = function (nums1, nums2) {
    let ans = 0;
    const m = nums1.length;
    const n = nums2.length;
    for (let i = 0, j = 0; i < m; ++i) {
        while (j < n && nums1[i] <= nums2[j]) {
            j++;
        }
        ans = Math.max(ans, j - i - 1);
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

<p>给你两个 <strong>非递增</strong> 的整数数组 <code>nums1</code>​​​​​​ 和 <code>nums2</code>​​​​​​ ，数组下标均 <strong>从 0 开始</strong> 计数。</p>

<p>下标对 <code>(i, j)</code> 中 <code>0 &lt;= i &lt; nums1.length</code> 且 <code>0 &lt;= j &lt; nums2.length</code> 。如果该下标对同时满足 <code>i &lt;= j</code> 且 <code>nums1[i] &lt;= nums2[j]</code> ，则称之为 <strong>有效</strong> 下标对，该下标对的 <strong>距离</strong> 为 <code>j - i</code>​​ 。​​</p>

<p>返回所有 <strong>有效</strong> 下标对<em> </em><code>(i, j)</code><em> </em>中的 <strong>最大距离</strong> 。如果不存在有效下标对，返回 <code>0</code> 。</p>

<p>一个数组 <code>arr</code> ，如果每个 <code>1 &lt;= i &lt; arr.length</code> 均有 <code>arr[i-1] &gt;= arr[i]</code> 成立，那么该数组是一个 <strong>非递增</strong> 数组。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [55,30,5,4,2], nums2 = [100,20,10,10,5]
<strong>输出：</strong>2
<strong>解释：</strong>有效下标对是 (0,0), (2,2), (2,3), (2,4), (3,3), (3,4) 和 (4,4) 。
最大距离是 2 ，对应下标对 (2,4) 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [2,2,2], nums2 = [10,10,1]
<strong>输出：</strong>1
<strong>解释：</strong>有效下标对是 (0,0), (0,1) 和 (1,1) 。
最大距离是 1 ，对应下标对 (0,1) 。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [30,29,19,5], nums2 = [25,25,25,25,25]
<strong>输出：</strong>2
<strong>解释：</strong>有效下标对是 (2,2), (2,3), (2,4), (3,3) 和 (3,4) 。
最大距离是 2 ，对应下标对 (2,4) 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums2.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums1[i], nums2[j] &lt;= 10<sup>5</sup></code></li>
	<li><code>nums1</code> 和 <code>nums2</code> 都是 <strong>非递增</strong> 数组</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

假设 $nums1$, $nums2$ 的长度分别为 $m$ 和 $n$。

遍历数组 $nums1$，对于每个数字 $nums1[i]$，二分查找 $nums2$ 在 $[i,n)$ 范围内的数字，找到**最后一个**大于等于 $nums1[i]$ 的位置 $j$，计算此位置与 $i$ 的距离，并更新最大距离值 $ans$。

时间复杂度 $O(m \times \log n)$，其中 $m$ 和 $n$ 分别为 $nums1$ 和 $nums2$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxDistance(self, nums1: List[int], nums2: List[int]) -> int:
        ans = 0
        nums2 = nums2[::-1]
        for i, v in enumerate(nums1):
            j = len(nums2) - bisect_left(nums2, v) - 1
            ans = max(ans, j - i)
        return ans
```

#### Java

```java
class Solution {
    public int maxDistance(int[] nums1, int[] nums2) {
        int ans = 0;
        int m = nums1.length, n = nums2.length;
        for (int i = 0; i < m; ++i) {
            int left = i, right = n - 1;
            while (left < right) {
                int mid = (left + right + 1) >> 1;
                if (nums2[mid] >= nums1[i]) {
                    left = mid;
                } else {
                    right = mid - 1;
                }
            }
            ans = Math.max(ans, left - i);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        reverse(nums2.begin(), nums2.end());
        for (int i = 0; i < nums1.size(); ++i) {
            int j = nums2.size() - (lower_bound(nums2.begin(), nums2.end(), nums1[i]) - nums2.begin()) - 1;
            ans = max(ans, j - i);
        }
        return ans;
    }
};
```

#### Go

```go
func maxDistance(nums1 []int, nums2 []int) int {
	ans, n := 0, len(nums2)
	for i, num := range nums1 {
		left, right := i, n-1
		for left < right {
			mid := (left + right + 1) >> 1
			if nums2[mid] >= num {
				left = mid
			} else {
				right = mid - 1
			}
		}
		if ans < left-i {
			ans = left - i
		}
	}
	return ans
}
```

#### TypeScript

```ts
function maxDistance(nums1: number[], nums2: number[]): number {
    let ans = 0;
    let m = nums1.length;
    let n = nums2.length;
    for (let i = 0; i < m; ++i) {
        let left = i;
        let right = n - 1;
        while (left < right) {
            const mid = (left + right + 1) >> 1;
            if (nums2[mid] >= nums1[i]) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        ans = Math.max(ans, left - i);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn max_distance(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
        let m = nums1.len();
        let n = nums2.len();
        let mut res = 0;
        for i in 0..m {
            let mut left = i;
            let mut right = n;
            while left < right {
                let mid = left + (right - left) / 2;
                if nums2[mid] >= nums1[i] {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            res = res.max((left - i - 1) as i32);
        }
        res
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var maxDistance = function (nums1, nums2) {
    let ans = 0;
    let m = nums1.length;
    let n = nums2.length;
    for (let i = 0; i < m; ++i) {
        let left = i;
        let right = n - 1;
        while (left < right) {
            const mid = (left + right + 1) >> 1;
            if (nums2[mid] >= nums1[i]) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        ans = Math.max(ans, left - i);
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：双指针

在方法一中，我们只利用到 $nums2$ 是非递增数组这一条件，实际上，$nums1$ 也是非递增数组，我们可以用双指针 $i$ 和 $j$ 来遍历 $nums1$ 和 $nums2$。

时间复杂度 $O(m+n)$，其中 $m$ 和 $n$ 分别为 $nums1$ 和 $nums2$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxDistance(self, nums1: List[int], nums2: List[int]) -> int:
        m, n = len(nums1), len(nums2)
        ans = i = j = 0
        while i < m:
            while j < n and nums1[i] <= nums2[j]:
                j += 1
            ans = max(ans, j - i - 1)
            i += 1
        return ans
```

#### Java

```java
class Solution {
    public int maxDistance(int[] nums1, int[] nums2) {
        int m = nums1.length, n = nums2.length;
        int ans = 0;
        for (int i = 0, j = 0; i < m; ++i) {
            while (j < n && nums1[i] <= nums2[j]) {
                ++j;
            }
            ans = Math.max(ans, j - i - 1);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int ans = 0;
        for (int i = 0, j = 0; i < m; ++i) {
            while (j < n && nums1[i] <= nums2[j]) {
                ++j;
            }
            ans = max(ans, j - i - 1);
        }
        return ans;
    }
};
```

#### Go

```go
func maxDistance(nums1 []int, nums2 []int) int {
	m, n := len(nums1), len(nums2)
	ans := 0
	for i, j := 0, 0; i < m; i++ {
		for j < n && nums1[i] <= nums2[j] {
			j++
		}
		if ans < j-i-1 {
			ans = j - i - 1
		}
	}
	return ans
}
```

#### TypeScript

```ts
function maxDistance(nums1: number[], nums2: number[]): number {
    let ans = 0;
    const m = nums1.length;
    const n = nums2.length;
    for (let i = 0, j = 0; i < m; ++i) {
        while (j < n && nums1[i] <= nums2[j]) {
            j++;
        }
        ans = Math.max(ans, j - i - 1);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn max_distance(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
        let m = nums1.len();
        let n = nums2.len();
        let mut res = 0;
        let mut j = 0;
        for i in 0..m {
            while j < n && nums1[i] <= nums2[j] {
                j += 1;
            }
            res = res.max((j - i - 1) as i32);
        }
        res
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var maxDistance = function (nums1, nums2) {
    let ans = 0;
    const m = nums1.length;
    const n = nums2.length;
    for (let i = 0, j = 0; i < m; ++i) {
        while (j < n && nums1[i] <= nums2[j]) {
            j++;
        }
        ans = Math.max(ans, j - i - 1);
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1856. 子数组最小乘积的最大值](https://leetcode.cn/problems/maximum-subarray-min-product){#1856}

{{< tabs "1856" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxSumMinProduct(self, nums: List[int]) -> int:
        n = len(nums)
        left = [-1] * n
        right = [n] * n
        stk = []
        for i, x in enumerate(nums):
            while stk and nums[stk[-1]] >= x:
                stk.pop()
            if stk:
                left[i] = stk[-1]
            stk.append(i)
        stk = []
        for i in range(n - 1, -1, -1):
            while stk and nums[stk[-1]] > nums[i]:
                stk.pop()
            if stk:
                right[i] = stk[-1]
            stk.append(i)
        s = list(accumulate(nums, initial=0))
        mod = 10**9 + 7
        return max((s[right[i]] - s[left[i] + 1]) * x for i, x in enumerate(nums)) % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxSumMinProduct(int[] nums) {
        int n = nums.length;
        int[] left = new int[n];
        int[] right = new int[n];
        Arrays.fill(left, -1);
        Arrays.fill(right, n);
        Deque<Integer> stk = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            while (!stk.isEmpty() && nums[stk.peek()] >= nums[i]) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                left[i] = stk.peek();
            }
            stk.push(i);
        }
        stk.clear();
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.isEmpty() && nums[stk.peek()] > nums[i]) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                right[i] = stk.peek();
            }
            stk.push(i);
        }
        long[] s = new long[n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
        long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = Math.max(ans, nums[i] * (s[right[i]] - s[left[i] + 1]));
        }
        final int mod = (int) 1e9 + 7;
        return (int) (ans % mod);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && nums[stk.top()] >= nums[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                left[i] = stk.top();
            }
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = n - 1; ~i; --i) {
            while (!stk.empty() && nums[stk.top()] > nums[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                right[i] = stk.top();
            }
            stk.push(i);
        }
        long long s[n + 1];
        s[0] = 0;
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, nums[i] * (s[right[i]] - s[left[i] + 1]));
        }
        const int mod = 1e9 + 7;
        return ans % mod;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxSumMinProduct(nums []int) int {
	n := len(nums)
	left := make([]int, n)
	right := make([]int, n)
	for i := range left {
		left[i] = -1
		right[i] = n
	}
	stk := []int{}
	for i, x := range nums {
		for len(stk) > 0 && nums[stk[len(stk)-1]] >= x {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			left[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	stk = []int{}
	for i := n - 1; i >= 0; i-- {
		for len(stk) > 0 && nums[stk[len(stk)-1]] > nums[i] {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			right[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	s := make([]int, n+1)
	for i, x := range nums {
		s[i+1] = s[i] + x
	}
	ans := 0
	for i, x := range nums {
		if t := x * (s[right[i]] - s[left[i]+1]); ans < t {
			ans = t
		}
	}
	const mod = 1e9 + 7
	return ans % mod
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxSumMinProduct(nums: number[]): number {
    const n = nums.length;
    const left: number[] = Array(n).fill(-1);
    const right: number[] = Array(n).fill(n);
    const stk: number[] = [];
    for (let i = 0; i < n; ++i) {
        while (stk.length && nums[stk.at(-1)!] >= nums[i]) {
            stk.pop();
        }
        if (stk.length) {
            left[i] = stk.at(-1)!;
        }
        stk.push(i);
    }
    stk.length = 0;
    for (let i = n - 1; i >= 0; --i) {
        while (stk.length && nums[stk.at(-1)!] > nums[i]) {
            stk.pop();
        }
        if (stk.length) {
            right[i] = stk.at(-1)!;
        }
        stk.push(i);
    }
    const s: number[] = Array(n + 1).fill(0);
    for (let i = 0; i < n; ++i) {
        s[i + 1] = s[i] + nums[i];
    }
    let ans: bigint = 0n;
    const mod = 10 ** 9 + 7;
    for (let i = 0; i < n; ++i) {
        const t = BigInt(nums[i]) * BigInt(s[right[i]] - s[left[i] + 1]);
        if (ans < t) {
            ans = t;
        }
    }
    return Number(ans % BigInt(mod));
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>一个数组的 <strong>最小乘积</strong> 定义为这个数组中 <strong>最小值</strong> <strong>乘以 </strong>数组的 <strong>和</strong> 。</p>

<ul>
	<li>比方说，数组 <code>[3,2,5]</code> （最小值是 <code>2</code>）的最小乘积为 <code>2 * (3+2+5) = 2 * 10 = 20</code> 。</li>
</ul>

<p>给你一个正整数数组 <code>nums</code> ，请你返回 <code>nums</code> 任意 <strong>非空子数组</strong> 的<strong>最小乘积</strong> 的 <strong>最大值</strong> 。由于答案可能很大，请你返回答案对  <code>10<sup>9</sup> + 7</code> <strong>取余 </strong>的结果。</p>

<p>请注意，最小乘积的最大值考虑的是取余操作 <strong>之前</strong> 的结果。题目保证最小乘积的最大值在 <strong>不取余</strong> 的情况下可以用 <strong>64 位有符号整数</strong> 保存。</p>

<p><strong>子数组</strong> 定义为一个数组的 <strong>连续</strong> 部分。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,<strong>2,3,2</strong>]
<b>输出：</b>14
<b>解释：</b>最小乘积的最大值由子数组 [2,3,2] （最小值是 2）得到。
2 * (2+3+2) = 2 * 7 = 14 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [2,<strong>3,3</strong>,1,2]
<b>输出：</b>18
<b>解释：</b>最小乘积的最大值由子数组 [3,3] （最小值是 3）得到。
3 * (3+3) = 3 * 6 = 18 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [3,1,<strong>5,6,4</strong>,2]
<b>输出：</b>60
<b>解释：</b>最小乘积的最大值由子数组 [5,6,4] （最小值是 4）得到。
4 * (5+6+4) = 4 * 15 = 60 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 10<sup>5</sup></code></li>
	<li><code>1 <= nums[i] <= 10<sup>7</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：单调栈 + 前缀和

我们可以枚举每个元素 $nums[i]$ 作为子数组的最小值，找出子数组的左右边界 $left[i]$ 和 $right[i]$。其中 $left[i]$ 表示 $i$ 左侧第一个严格小于 $nums[i]$ 的位置，而 $right[i]$ 表示 $i$ 右侧第一个小于等于 $nums[i]$ 的位置。

为了方便地算出子数组的和，我们可以预处理出前缀和数组 $s$，其中 $s[i]$ 表示 $nums$ 前 $i$ 个元素的和。

那么以 $nums[i]$ 作为子数组最小值的最小乘积为 $nums[i] \times s[right[i]] - s[left[i] + 1]$。我们可以枚举每个元素 $nums[i]$，求出以 $nums[i]$ 作为子数组最小值的最小乘积，然后取最大值即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxSumMinProduct(self, nums: List[int]) -> int:
        n = len(nums)
        left = [-1] * n
        right = [n] * n
        stk = []
        for i, x in enumerate(nums):
            while stk and nums[stk[-1]] >= x:
                stk.pop()
            if stk:
                left[i] = stk[-1]
            stk.append(i)
        stk = []
        for i in range(n - 1, -1, -1):
            while stk and nums[stk[-1]] > nums[i]:
                stk.pop()
            if stk:
                right[i] = stk[-1]
            stk.append(i)
        s = list(accumulate(nums, initial=0))
        mod = 10**9 + 7
        return max((s[right[i]] - s[left[i] + 1]) * x for i, x in enumerate(nums)) % mod
```

#### Java

```java
class Solution {
    public int maxSumMinProduct(int[] nums) {
        int n = nums.length;
        int[] left = new int[n];
        int[] right = new int[n];
        Arrays.fill(left, -1);
        Arrays.fill(right, n);
        Deque<Integer> stk = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            while (!stk.isEmpty() && nums[stk.peek()] >= nums[i]) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                left[i] = stk.peek();
            }
            stk.push(i);
        }
        stk.clear();
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.isEmpty() && nums[stk.peek()] > nums[i]) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                right[i] = stk.peek();
            }
            stk.push(i);
        }
        long[] s = new long[n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
        long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = Math.max(ans, nums[i] * (s[right[i]] - s[left[i] + 1]));
        }
        final int mod = (int) 1e9 + 7;
        return (int) (ans % mod);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && nums[stk.top()] >= nums[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                left[i] = stk.top();
            }
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = n - 1; ~i; --i) {
            while (!stk.empty() && nums[stk.top()] > nums[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                right[i] = stk.top();
            }
            stk.push(i);
        }
        long long s[n + 1];
        s[0] = 0;
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, nums[i] * (s[right[i]] - s[left[i] + 1]));
        }
        const int mod = 1e9 + 7;
        return ans % mod;
    }
};
```

#### Go

```go
func maxSumMinProduct(nums []int) int {
	n := len(nums)
	left := make([]int, n)
	right := make([]int, n)
	for i := range left {
		left[i] = -1
		right[i] = n
	}
	stk := []int{}
	for i, x := range nums {
		for len(stk) > 0 && nums[stk[len(stk)-1]] >= x {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			left[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	stk = []int{}
	for i := n - 1; i >= 0; i-- {
		for len(stk) > 0 && nums[stk[len(stk)-1]] > nums[i] {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			right[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	s := make([]int, n+1)
	for i, x := range nums {
		s[i+1] = s[i] + x
	}
	ans := 0
	for i, x := range nums {
		if t := x * (s[right[i]] - s[left[i]+1]); ans < t {
			ans = t
		}
	}
	const mod = 1e9 + 7
	return ans % mod
}
```

#### TypeScript

```ts
function maxSumMinProduct(nums: number[]): number {
    const n = nums.length;
    const left: number[] = Array(n).fill(-1);
    const right: number[] = Array(n).fill(n);
    const stk: number[] = [];
    for (let i = 0; i < n; ++i) {
        while (stk.length && nums[stk.at(-1)!] >= nums[i]) {
            stk.pop();
        }
        if (stk.length) {
            left[i] = stk.at(-1)!;
        }
        stk.push(i);
    }
    stk.length = 0;
    for (let i = n - 1; i >= 0; --i) {
        while (stk.length && nums[stk.at(-1)!] > nums[i]) {
            stk.pop();
        }
        if (stk.length) {
            right[i] = stk.at(-1)!;
        }
        stk.push(i);
    }
    const s: number[] = Array(n + 1).fill(0);
    for (let i = 0; i < n; ++i) {
        s[i + 1] = s[i] + nums[i];
    }
    let ans: bigint = 0n;
    const mod = 10 ** 9 + 7;
    for (let i = 0; i < n; ++i) {
        const t = BigInt(nums[i]) * BigInt(s[right[i]] - s[left[i] + 1]);
        if (ans < t) {
            ans = t;
        }
    }
    return Number(ans % BigInt(mod));
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1857. 有向图中最大颜色值](https://leetcode.cn/problems/largest-color-value-in-a-directed-graph){#1857}

{{< tabs "1857" >}}

{{% tab "python" %}}
```python
class Solution:
    def largestPathValue(self, colors: str, edges: List[List[int]]) -> int:
        n = len(colors)
        indeg = [0] * n
        g = defaultdict(list)
        for a, b in edges:
            g[a].append(b)
            indeg[b] += 1
        q = deque()
        dp = [[0] * 26 for _ in range(n)]
        for i, v in enumerate(indeg):
            if v == 0:
                q.append(i)
                c = ord(colors[i]) - ord('a')
                dp[i][c] += 1
        cnt = 0
        ans = 1
        while q:
            i = q.popleft()
            cnt += 1
            for j in g[i]:
                indeg[j] -= 1
                if indeg[j] == 0:
                    q.append(j)
                c = ord(colors[j]) - ord('a')
                for k in range(26):
                    dp[j][k] = max(dp[j][k], dp[i][k] + (c == k))
                    ans = max(ans, dp[j][k])
        return -1 if cnt < n else ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int largestPathValue(String colors, int[][] edges) {
        int n = colors.length();
        List<Integer>[] g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        int[] indeg = new int[n];
        for (int[] e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            ++indeg[b];
        }
        Deque<Integer> q = new ArrayDeque<>();
        int[][] dp = new int[n][26];
        for (int i = 0; i < n; ++i) {
            if (indeg[i] == 0) {
                q.offer(i);
                int c = colors.charAt(i) - 'a';
                ++dp[i][c];
            }
        }
        int cnt = 0;
        int ans = 1;
        while (!q.isEmpty()) {
            int i = q.pollFirst();
            ++cnt;
            for (int j : g[i]) {
                if (--indeg[j] == 0) {
                    q.offer(j);
                }
                int c = colors.charAt(j) - 'a';
                for (int k = 0; k < 26; ++k) {
                    dp[j][k] = Math.max(dp[j][k], dp[i][k] + (c == k ? 1 : 0));
                    ans = Math.max(ans, dp[j][k]);
                }
            }
        }
        return cnt == n ? ans : -1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> g(n);
        vector<int> indeg(n);
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            ++indeg[b];
        }
        queue<int> q;
        vector<vector<int>> dp(n, vector<int>(26));
        for (int i = 0; i < n; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
                int c = colors[i] - 'a';
                dp[i][c]++;
            }
        }
        int cnt = 0;
        int ans = 1;
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            ++cnt;
            for (int j : g[i]) {
                if (--indeg[j] == 0) q.push(j);
                int c = colors[j] - 'a';
                for (int k = 0; k < 26; ++k) {
                    dp[j][k] = max(dp[j][k], dp[i][k] + (c == k));
                    ans = max(ans, dp[j][k]);
                }
            }
        }
        return cnt == n ? ans : -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func largestPathValue(colors string, edges [][]int) int {
	n := len(colors)
	g := make([][]int, n)
	indeg := make([]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		indeg[b]++
	}
	q := []int{}
	dp := make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, 26)
	}
	for i, v := range indeg {
		if v == 0 {
			q = append(q, i)
			c := colors[i] - 'a'
			dp[i][c]++
		}
	}
	cnt := 0
	ans := 1
	for len(q) > 0 {
		i := q[0]
		q = q[1:]
		cnt++
		for _, j := range g[i] {
			indeg[j]--
			if indeg[j] == 0 {
				q = append(q, j)
			}
			c := int(colors[j] - 'a')
			for k := 0; k < 26; k++ {
				t := 0
				if c == k {
					t = 1
				}
				dp[j][k] = max(dp[j][k], dp[i][k]+t)
				ans = max(ans, dp[j][k])
			}
		}
	}
	if cnt == n {
		return ans
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function largestPathValue(colors: string, edges: number[][]): number {
    const n = colors.length;
    const indeg = Array(n).fill(0);
    const g: Map<number, number[]> = new Map();
    for (const [a, b] of edges) {
        if (!g.has(a)) g.set(a, []);
        g.get(a)!.push(b);
        indeg[b]++;
    }
    const q: number[] = [];
    const dp: number[][] = Array.from({ length: n }, () => Array(26).fill(0));
    for (let i = 0; i < n; i++) {
        if (indeg[i] === 0) {
            q.push(i);
            const c = colors.charCodeAt(i) - 97;
            dp[i][c]++;
        }
    }
    let cnt = 0;
    let ans = 1;
    while (q.length) {
        const i = q.pop()!;
        cnt++;
        if (g.has(i)) {
            for (const j of g.get(i)!) {
                indeg[j]--;
                if (indeg[j] === 0) q.push(j);
                const c = colors.charCodeAt(j) - 97;
                for (let k = 0; k < 26; k++) {
                    dp[j][k] = Math.max(dp[j][k], dp[i][k] + (c === k ? 1 : 0));
                    ans = Math.max(ans, dp[j][k]);
                }
            }
        }
    }
    return cnt < n ? -1 : ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个&nbsp;<strong>有向图</strong>&nbsp;，它含有&nbsp;<code>n</code>&nbsp;个节点和 <code>m</code>&nbsp;条边。节点编号从&nbsp;<code>0</code> 到&nbsp;<code>n - 1</code>&nbsp;。</p>

<p>给你一个字符串&nbsp;<code>colors</code> ，其中&nbsp;<code>colors[i]</code>&nbsp;是小写英文字母，表示图中第 <code>i</code>&nbsp;个节点的 <b>颜色</b>&nbsp;（下标从 <strong>0</strong>&nbsp;开始）。同时给你一个二维数组&nbsp;<code>edges</code>&nbsp;，其中&nbsp;<code>edges[j] = [a<sub>j</sub>, b<sub>j</sub>]</code>&nbsp;表示从节点&nbsp;<code>a<sub>j</sub></code>&nbsp;到节点&nbsp;<code>b<sub>j</sub></code><sub>&nbsp;</sub>有一条&nbsp;<strong>有向边</strong>&nbsp;。</p>

<p>图中一条有效 <strong>路径</strong>&nbsp;是一个点序列&nbsp;<code>x<sub>1</sub> -&gt; x<sub>2</sub> -&gt; x<sub>3</sub> -&gt; ... -&gt; x<sub>k</sub></code>&nbsp;，对于所有&nbsp;<code>1 &lt;= i &lt; k</code>&nbsp;，从&nbsp;<code>x<sub>i</sub></code> 到&nbsp;<code>x<sub>i+1</sub></code>&nbsp;在图中有一条有向边。路径的 <strong>颜色值</strong>&nbsp;是路径中 <strong>出现次数最多</strong> 颜色的节点数目。</p>

<p>请你返回给定图中有效路径里面的&nbsp;<strong>最大颜色值</strong><strong>&nbsp;。</strong>如果图中含有环，请返回 <code>-1</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1800-1899/1857.Largest%20Color%20Value%20in%20a%20Directed%20Graph/images/leet1.png" style="width: 400px; height: 182px;" /></p>

<pre>
<b>输入：</b>colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
<b>输出：</b>3
<b>解释：</b>路径 0 -&gt; 2 -&gt; 3 -&gt; 4 含有 3 个颜色为 "a" 的节点（上图中的红色节点）。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1800-1899/1857.Largest%20Color%20Value%20in%20a%20Directed%20Graph/images/leet2.png" style="width: 85px; height: 85px;" /></p>

<pre>
<b>输入：</b>colors = "a", edges = [[0,0]]
<b>输出：</b>-1
<b>解释：</b>从 0 到 0 有一个环。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == colors.length</code></li>
	<li><code>m == edges.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= m &lt;= 10<sup>5</sup></code></li>
	<li><code>colors</code>&nbsp;只含有小写英文字母。</li>
	<li><code>0 &lt;= a<sub>j</sub>, b<sub>j</sub>&nbsp;&lt; n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：拓扑排序 + 动态规划

求出每个点的入度，进行拓扑排序。

定义一个二维数组 $dp$，其中 $dp[i][j]$ 表示从起点到 $i$ 点，颜色为 $j$ 的节点数目。

从 $i$ 点出发，遍历所有出边 $i \to j$，更新 $dp[j][k] = \max(dp[j][k], dp[i][k] + (c == k))$，其中 $c$ 是 $j$ 点的颜色。

答案为数组 $dp$ 中的最大值。

如果图中有环，则无法遍历完所有点，返回 $-1$。

时间复杂度 $O((n + m) \times |\Sigma|)$，空间复杂度 $O(m + n \times |\Sigma)$。其中 $|\Sigma|$ 是字母表大小，这里为 $26$，而且 $n$ 和 $m$ 分别是节点数和边数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def largestPathValue(self, colors: str, edges: List[List[int]]) -> int:
        n = len(colors)
        indeg = [0] * n
        g = defaultdict(list)
        for a, b in edges:
            g[a].append(b)
            indeg[b] += 1
        q = deque()
        dp = [[0] * 26 for _ in range(n)]
        for i, v in enumerate(indeg):
            if v == 0:
                q.append(i)
                c = ord(colors[i]) - ord('a')
                dp[i][c] += 1
        cnt = 0
        ans = 1
        while q:
            i = q.popleft()
            cnt += 1
            for j in g[i]:
                indeg[j] -= 1
                if indeg[j] == 0:
                    q.append(j)
                c = ord(colors[j]) - ord('a')
                for k in range(26):
                    dp[j][k] = max(dp[j][k], dp[i][k] + (c == k))
                    ans = max(ans, dp[j][k])
        return -1 if cnt < n else ans
```

#### Java

```java
class Solution {
    public int largestPathValue(String colors, int[][] edges) {
        int n = colors.length();
        List<Integer>[] g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        int[] indeg = new int[n];
        for (int[] e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            ++indeg[b];
        }
        Deque<Integer> q = new ArrayDeque<>();
        int[][] dp = new int[n][26];
        for (int i = 0; i < n; ++i) {
            if (indeg[i] == 0) {
                q.offer(i);
                int c = colors.charAt(i) - 'a';
                ++dp[i][c];
            }
        }
        int cnt = 0;
        int ans = 1;
        while (!q.isEmpty()) {
            int i = q.pollFirst();
            ++cnt;
            for (int j : g[i]) {
                if (--indeg[j] == 0) {
                    q.offer(j);
                }
                int c = colors.charAt(j) - 'a';
                for (int k = 0; k < 26; ++k) {
                    dp[j][k] = Math.max(dp[j][k], dp[i][k] + (c == k ? 1 : 0));
                    ans = Math.max(ans, dp[j][k]);
                }
            }
        }
        return cnt == n ? ans : -1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> g(n);
        vector<int> indeg(n);
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            ++indeg[b];
        }
        queue<int> q;
        vector<vector<int>> dp(n, vector<int>(26));
        for (int i = 0; i < n; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
                int c = colors[i] - 'a';
                dp[i][c]++;
            }
        }
        int cnt = 0;
        int ans = 1;
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            ++cnt;
            for (int j : g[i]) {
                if (--indeg[j] == 0) q.push(j);
                int c = colors[j] - 'a';
                for (int k = 0; k < 26; ++k) {
                    dp[j][k] = max(dp[j][k], dp[i][k] + (c == k));
                    ans = max(ans, dp[j][k]);
                }
            }
        }
        return cnt == n ? ans : -1;
    }
};
```

#### Go

```go
func largestPathValue(colors string, edges [][]int) int {
	n := len(colors)
	g := make([][]int, n)
	indeg := make([]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		indeg[b]++
	}
	q := []int{}
	dp := make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, 26)
	}
	for i, v := range indeg {
		if v == 0 {
			q = append(q, i)
			c := colors[i] - 'a'
			dp[i][c]++
		}
	}
	cnt := 0
	ans := 1
	for len(q) > 0 {
		i := q[0]
		q = q[1:]
		cnt++
		for _, j := range g[i] {
			indeg[j]--
			if indeg[j] == 0 {
				q = append(q, j)
			}
			c := int(colors[j] - 'a')
			for k := 0; k < 26; k++ {
				t := 0
				if c == k {
					t = 1
				}
				dp[j][k] = max(dp[j][k], dp[i][k]+t)
				ans = max(ans, dp[j][k])
			}
		}
	}
	if cnt == n {
		return ans
	}
	return -1
}
```

#### TypeScript

```ts
function largestPathValue(colors: string, edges: number[][]): number {
    const n = colors.length;
    const indeg = Array(n).fill(0);
    const g: Map<number, number[]> = new Map();
    for (const [a, b] of edges) {
        if (!g.has(a)) g.set(a, []);
        g.get(a)!.push(b);
        indeg[b]++;
    }
    const q: number[] = [];
    const dp: number[][] = Array.from({ length: n }, () => Array(26).fill(0));
    for (let i = 0; i < n; i++) {
        if (indeg[i] === 0) {
            q.push(i);
            const c = colors.charCodeAt(i) - 97;
            dp[i][c]++;
        }
    }
    let cnt = 0;
    let ans = 1;
    while (q.length) {
        const i = q.pop()!;
        cnt++;
        if (g.has(i)) {
            for (const j of g.get(i)!) {
                indeg[j]--;
                if (indeg[j] === 0) q.push(j);
                const c = colors.charCodeAt(j) - 97;
                for (let k = 0; k < 26; k++) {
                    dp[j][k] = Math.max(dp[j][k], dp[i][k] + (c === k ? 1 : 0));
                    ans = Math.max(ans, dp[j][k]);
                }
            }
        }
    }
    return cnt < n ? -1 : ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1858. 包含所有前缀的最长单词 🔒](https://leetcode.cn/problems/longest-word-with-all-prefixes){#1858}

{{< tabs "1858" >}}

{{% tab "python" %}}
```python
class Trie:
    __slots__ = ["children", "is_end"]

    def __init__(self):
        self.children: List[Trie | None] = [None] * 26
        self.is_end: bool = False

    def insert(self, w: str) -> None:
        node = self
        for c in w:
            idx = ord(c) - ord("a")
            if not node.children[idx]:
                node.children[idx] = Trie()
            node = node.children[idx]
        node.is_end = True

    def search(self, w: str) -> bool:
        node = self
        for c in w:
            idx = ord(c) - ord("a")
            node = node.children[idx]
            if not node.is_end:
                return False
        return True


class Solution:
    def longestWord(self, words: List[str]) -> str:
        trie = Trie()
        for w in words:
            trie.insert(w)
        ans = ""
        for w in words:
            if (len(w) > len(ans) or len(w) == len(ans) and w < ans) and trie.search(w):
                ans = w
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Trie {
    private Trie[] children = new Trie[26];
    private boolean isEnd;

    public Trie() {
    }

    public void insert(String w) {
        Trie node = this;
        for (char c : w.toCharArray()) {
            int idx = c - 'a';
            if (node.children[idx] == null) {
                node.children[idx] = new Trie();
            }
            node = node.children[idx];
        }
        node.isEnd = true;
    }

    public boolean search(String w) {
        Trie node = this;
        for (char c : w.toCharArray()) {
            int idx = c - 'a';
            node = node.children[idx];
            if (!node.isEnd) {
                return false;
            }
        }
        return true;
    }
}

class Solution {
    public String longestWord(String[] words) {
        Trie trie = new Trie();
        for (String w : words) {
            trie.insert(w);
        }
        String ans = "";
        for (String w : words) {
            if ((w.length() > ans.length() || (w.length() == ans.length() && w.compareTo(ans) < 0))
                && trie.search(w)) {
                ans = w;
            }
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Trie {
private:
    Trie* children[26];
    bool isEnd = false;

public:
    Trie() {
        fill(begin(children), end(children), nullptr);
    }

    void insert(const string& w) {
        Trie* node = this;
        for (char c : w) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new Trie();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    bool search(const string& w) {
        Trie* node = this;
        for (char c : w) {
            int idx = c - 'a';
            node = node->children[idx];
            if (!node->isEnd) {
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie trie;
        for (const string& w : words) {
            trie.insert(w);
        }
        string ans = "";
        for (const string& w : words) {
            if ((w.size() > ans.size() || (w.size() == ans.size() && w < ans)) && trie.search(w)) {
                ans = w;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Trie struct {
	children [26]*Trie
	isEnd    bool
}

func newTrie() *Trie {
	return &Trie{}
}

func (t *Trie) insert(w string) {
	node := t
	for _, c := range w {
		idx := c - 'a'
		if node.children[idx] == nil {
			node.children[idx] = newTrie()
		}
		node = node.children[idx]
	}
	node.isEnd = true
}

func (t *Trie) search(w string) bool {
	node := t
	for _, c := range w {
		idx := c - 'a'
		node = node.children[idx]
		if !node.isEnd {
			return false
		}
	}
	return true
}

func longestWord(words []string) string {
	trie := newTrie()
	for _, w := range words {
		trie.insert(w)
	}
	ans := ""
	for _, w := range words {
		if (len(w) > len(ans) || (len(w) == len(ans) && w < ans)) && trie.search(w) {
			ans = w
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class Trie {
    private children: (Trie | null)[] = Array(26).fill(null);
    private isEnd: boolean = false;

    insert(w: string): void {
        let node: Trie = this;
        for (const c of w) {
            const idx: number = c.charCodeAt(0) - 'a'.charCodeAt(0);
            if (!node.children[idx]) {
                node.children[idx] = new Trie();
            }
            node = node.children[idx] as Trie;
        }
        node.isEnd = true;
    }

    search(w: string): boolean {
        let node: Trie = this;
        for (const c of w) {
            const idx: number = c.charCodeAt(0) - 'a'.charCodeAt(0);
            node = node.children[idx] as Trie;
            if (!node.isEnd) {
                return false;
            }
        }
        return true;
    }
}

function longestWord(words: string[]): string {
    const trie: Trie = new Trie();
    for (const w of words) {
        trie.insert(w);
    }
    let ans: string = '';
    for (const w of words) {
        if ((w.length > ans.length || (w.length === ans.length && w < ans)) && trie.search(w)) {
            ans = w;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
struct Trie {
    children: [Option<Box<Trie>>; 26],
    is_end: bool,
}

impl Trie {
    fn new() -> Self {
        Trie {
            children: Default::default(),
            is_end: false,
        }
    }

    fn insert(&mut self, w: &str) {
        let mut node = self;
        for c in w.chars() {
            let idx = (c as usize) - ('a' as usize);
            node = node.children[idx].get_or_insert_with(|| Box::new(Trie::new()));
        }
        node.is_end = true;
    }

    fn search(&self, w: &str) -> bool {
        let mut node = self;
        for c in w.chars() {
            let idx = (c as usize) - ('a' as usize);
            if let Some(next_node) = &node.children[idx] {
                node = next_node.as_ref();
                if !node.is_end {
                    return false;
                }
            }
        }
        true
    }
}

impl Solution {
    pub fn longest_word(words: Vec<String>) -> String {
        let mut trie = Trie::new();
        for w in &words {
            trie.insert(w);
        }
        let mut ans = String::new();
        for w in &words {
            if (w.len() > ans.len() || (w.len() == ans.len() && w < &ans)) && trie.search(w) {
                ans = w.clone();
            }
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Trie {
    private Trie[] children = new Trie[26];
    private bool isEnd;

    public Trie() { }

    public void Insert(string w) {
        Trie node = this;
        foreach (char c in w.ToCharArray()) {
            int idx = c - 'a';
            if (node.children[idx] == null) {
                node.children[idx] = new Trie();
            }
            node = node.children[idx];
        }
        node.isEnd = true;
    }

    public bool Search(string w) {
        Trie node = this;
        foreach (char c in w.ToCharArray()) {
            int idx = c - 'a';
            node = node.children[idx];
            if (!node.isEnd) {
                return false;
            }
        }
        return true;
    }
}

public class Solution {
    public string LongestWord(string[] words) {
        Trie trie = new Trie();
        foreach (string w in words) {
            trie.Insert(w);
        }

        string ans = "";
        foreach (string w in words) {
            if ((w.Length > ans.Length || (w.Length == ans.Length && string.Compare(w, ans) < 0)) && trie.Search(w)) {
                ans = w;
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

<p>给定一个字符串数组 <code>words</code>，找出 <code>words</code> 中<strong>所有的前缀</strong>都在 <code>words</code> 中的<strong>最长</strong>字符串。</p>

<ul>
	<li>例如，令 <code>words = ["a", "app", "ap"]</code>。字符串 <code>"app"</code> 含前缀 <code>"ap"</code> 和 <code>"a"</code> ，都在 <code>words</code> 中。</li>
</ul>

<p>返回符合上述要求的字符串。如果存在多个（符合条件的）相同长度的字符串，返回字典序中最小的字符串，如果这样的字符串不存在，返回<em> </em><code>""</code>。</p>

<p> </p>

<p><strong>示例 1:</strong></p>

<pre><b>输入：</b> words = ["k","ki","kir","kira", "kiran"]
<b>输出：</b> "kiran"
<b>解释：</b> "kiran" 含前缀 "kira"、 "kir"、 "ki"、 和 "k"，这些前缀都出现在 words 中。
</pre>

<p><strong>示例 2:</strong></p>

<pre><b>输入：</b> words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
<b>输出： </b>"apple"
<b>解释：</b> "apple" 和 "apply" 都在 words 中含有各自的所有前缀。
然而，"apple" 在字典序中更小，所以我们返回之。
</pre>

<p><strong>示例 3:</strong></p>

<pre><b>输入：</b> words = ["abc", "bc", "ab", "qwe"]
<b>输出：</b> ""
</pre>

<p> </p>

<p><b>提示：</b></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= words[i].length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= sum(words[i].length) &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀树

我们定义一棵前缀树，前缀树每个节点有两个属性，一个是长度为 $26$ 的子节点数组 `children`，另一个是是否为单词结尾的标记 `isEnd`。

我们遍历 `words`，对于每个单词 `w`，我们从根节点开始遍历，如果当前节点的子节点数组中没有 `w` 的第一个字符，我们就创建一个新的节点，然后继续遍历 `w` 的下一个字符，直到遍历完 `w`，我们将当前节点的 `isEnd` 标记为 `true`。

接下来我们遍历 `words`，对于每个单词 `w`，我们从根节点开始遍历，如果当前节点的子节点数组的 `isEnd` 字段为 `false`，说明 `w` 的某个前缀不在 `words` 中，我们返回 `false`。否则继续遍历 `w` 的下一个字符，直到遍历完 `w`，我们返回 `true`。

时间复杂度 $O(\sum_{w \in words} |w|)$，空间复杂度 $O(\sum_{w \in words} |w|)$。

<!-- tabs:start -->

#### Python3

```python
class Trie:
    __slots__ = ["children", "is_end"]

    def __init__(self):
        self.children: List[Trie | None] = [None] * 26
        self.is_end: bool = False

    def insert(self, w: str) -> None:
        node = self
        for c in w:
            idx = ord(c) - ord("a")
            if not node.children[idx]:
                node.children[idx] = Trie()
            node = node.children[idx]
        node.is_end = True

    def search(self, w: str) -> bool:
        node = self
        for c in w:
            idx = ord(c) - ord("a")
            node = node.children[idx]
            if not node.is_end:
                return False
        return True


class Solution:
    def longestWord(self, words: List[str]) -> str:
        trie = Trie()
        for w in words:
            trie.insert(w)
        ans = ""
        for w in words:
            if (len(w) > len(ans) or len(w) == len(ans) and w < ans) and trie.search(w):
                ans = w
        return ans
```

#### Java

```java
class Trie {
    private Trie[] children = new Trie[26];
    private boolean isEnd;

    public Trie() {
    }

    public void insert(String w) {
        Trie node = this;
        for (char c : w.toCharArray()) {
            int idx = c - 'a';
            if (node.children[idx] == null) {
                node.children[idx] = new Trie();
            }
            node = node.children[idx];
        }
        node.isEnd = true;
    }

    public boolean search(String w) {
        Trie node = this;
        for (char c : w.toCharArray()) {
            int idx = c - 'a';
            node = node.children[idx];
            if (!node.isEnd) {
                return false;
            }
        }
        return true;
    }
}

class Solution {
    public String longestWord(String[] words) {
        Trie trie = new Trie();
        for (String w : words) {
            trie.insert(w);
        }
        String ans = "";
        for (String w : words) {
            if ((w.length() > ans.length() || (w.length() == ans.length() && w.compareTo(ans) < 0))
                && trie.search(w)) {
                ans = w;
            }
        }
        return ans;
    }
}
```

#### C++

```cpp
class Trie {
private:
    Trie* children[26];
    bool isEnd = false;

public:
    Trie() {
        fill(begin(children), end(children), nullptr);
    }

    void insert(const string& w) {
        Trie* node = this;
        for (char c : w) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new Trie();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    bool search(const string& w) {
        Trie* node = this;
        for (char c : w) {
            int idx = c - 'a';
            node = node->children[idx];
            if (!node->isEnd) {
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie trie;
        for (const string& w : words) {
            trie.insert(w);
        }
        string ans = "";
        for (const string& w : words) {
            if ((w.size() > ans.size() || (w.size() == ans.size() && w < ans)) && trie.search(w)) {
                ans = w;
            }
        }
        return ans;
    }
};
```

#### Go

```go
type Trie struct {
	children [26]*Trie
	isEnd    bool
}

func newTrie() *Trie {
	return &Trie{}
}

func (t *Trie) insert(w string) {
	node := t
	for _, c := range w {
		idx := c - 'a'
		if node.children[idx] == nil {
			node.children[idx] = newTrie()
		}
		node = node.children[idx]
	}
	node.isEnd = true
}

func (t *Trie) search(w string) bool {
	node := t
	for _, c := range w {
		idx := c - 'a'
		node = node.children[idx]
		if !node.isEnd {
			return false
		}
	}
	return true
}

func longestWord(words []string) string {
	trie := newTrie()
	for _, w := range words {
		trie.insert(w)
	}
	ans := ""
	for _, w := range words {
		if (len(w) > len(ans) || (len(w) == len(ans) && w < ans)) && trie.search(w) {
			ans = w
		}
	}
	return ans
}
```

#### TypeScript

```ts
class Trie {
    private children: (Trie | null)[] = Array(26).fill(null);
    private isEnd: boolean = false;

    insert(w: string): void {
        let node: Trie = this;
        for (const c of w) {
            const idx: number = c.charCodeAt(0) - 'a'.charCodeAt(0);
            if (!node.children[idx]) {
                node.children[idx] = new Trie();
            }
            node = node.children[idx] as Trie;
        }
        node.isEnd = true;
    }

    search(w: string): boolean {
        let node: Trie = this;
        for (const c of w) {
            const idx: number = c.charCodeAt(0) - 'a'.charCodeAt(0);
            node = node.children[idx] as Trie;
            if (!node.isEnd) {
                return false;
            }
        }
        return true;
    }
}

function longestWord(words: string[]): string {
    const trie: Trie = new Trie();
    for (const w of words) {
        trie.insert(w);
    }
    let ans: string = '';
    for (const w of words) {
        if ((w.length > ans.length || (w.length === ans.length && w < ans)) && trie.search(w)) {
            ans = w;
        }
    }
    return ans;
}
```

#### Rust

```rust
struct Trie {
    children: [Option<Box<Trie>>; 26],
    is_end: bool,
}

impl Trie {
    fn new() -> Self {
        Trie {
            children: Default::default(),
            is_end: false,
        }
    }

    fn insert(&mut self, w: &str) {
        let mut node = self;
        for c in w.chars() {
            let idx = (c as usize) - ('a' as usize);
            node = node.children[idx].get_or_insert_with(|| Box::new(Trie::new()));
        }
        node.is_end = true;
    }

    fn search(&self, w: &str) -> bool {
        let mut node = self;
        for c in w.chars() {
            let idx = (c as usize) - ('a' as usize);
            if let Some(next_node) = &node.children[idx] {
                node = next_node.as_ref();
                if !node.is_end {
                    return false;
                }
            }
        }
        true
    }
}

impl Solution {
    pub fn longest_word(words: Vec<String>) -> String {
        let mut trie = Trie::new();
        for w in &words {
            trie.insert(w);
        }
        let mut ans = String::new();
        for w in &words {
            if (w.len() > ans.len() || (w.len() == ans.len() && w < &ans)) && trie.search(w) {
                ans = w.clone();
            }
        }
        ans
    }
}
```

#### C#

```cs
public class Trie {
    private Trie[] children = new Trie[26];
    private bool isEnd;

    public Trie() { }

    public void Insert(string w) {
        Trie node = this;
        foreach (char c in w.ToCharArray()) {
            int idx = c - 'a';
            if (node.children[idx] == null) {
                node.children[idx] = new Trie();
            }
            node = node.children[idx];
        }
        node.isEnd = true;
    }

    public bool Search(string w) {
        Trie node = this;
        foreach (char c in w.ToCharArray()) {
            int idx = c - 'a';
            node = node.children[idx];
            if (!node.isEnd) {
                return false;
            }
        }
        return true;
    }
}

public class Solution {
    public string LongestWord(string[] words) {
        Trie trie = new Trie();
        foreach (string w in words) {
            trie.Insert(w);
        }

        string ans = "";
        foreach (string w in words) {
            if ((w.Length > ans.Length || (w.Length == ans.Length && string.Compare(w, ans) < 0)) && trie.Search(w)) {
                ans = w;
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

# [1859. 将句子排序](https://leetcode.cn/problems/sorting-the-sentence){#1859}

{{< tabs "1859" >}}

{{% tab "python" %}}
```python
class Solution:
    def sortSentence(self, s: str) -> str:
        ws = [(w[:-1], int(w[-1])) for w in s.split()]
        ws.sort(key=lambda x: x[1])
        return ' '.join(w for w, _ in ws)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String sortSentence(String s) {
        String[] ws = s.split(" ");
        int n = ws.length;
        String[] ans = new String[n];
        for (int i = 0; i < n; ++i) {
            String w = ws[i];
            ans[w.charAt(w.length() - 1) - '1'] = w.substring(0, w.length() - 1);
        }
        return String.join(" ", ans);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string sortSentence(string s) {
        istringstream iss(s);
        string w;
        vector<string> ws;
        while (iss >> w) {
            ws.push_back(w);
        }
        vector<string> ss(ws.size());
        for (auto& w : ws) {
            ss[w.back() - '1'] = w.substr(0, w.size() - 1);
        }
        string ans;
        for (auto& w : ss) {
            ans += w + " ";
        }
        ans.pop_back();
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sortSentence(s string) string {
	ws := strings.Split(s, " ")
	ans := make([]string, len(ws))
	for _, w := range ws {
		ans[w[len(w)-1]-'1'] = w[:len(w)-1]
	}
	return strings.Join(ans, " ")
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function sortSentence(s: string): string {
    const ws = s.split(' ');
    const ans = Array(ws.length);
    for (const w of ws) {
        ans[w.charCodeAt(w.length - 1) - '1'.charCodeAt(0)] = w.slice(0, -1);
    }
    return ans.join(' ');
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} s
 * @return {string}
 */
var sortSentence = function (s) {
    const ws = s.split(' ');
    const ans = Array(ws.length);
    for (const w of ws) {
        ans[w.charCodeAt(w.length - 1) - '1'.charCodeAt(0)] = w.slice(0, -1);
    }
    return ans.join(' ');
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>一个 <strong>句子</strong> 指的是一个序列的单词用单个空格连接起来，且开头和结尾没有任何空格。每个单词都只包含小写或大写英文字母。</p>

<p>我们可以给一个句子添加 <strong>从 1 开始的单词位置索引 </strong>，并且将句子中所有单词 <strong>打乱顺序</strong> 。</p>

<ul>
	<li>比方说，句子 <code>"This is a sentence"</code> 可以被打乱顺序得到 <code>"sentence4 a3 is2 This1"</code> 或者 <code>"is2 sentence4 This1 a3"</code> 。</li>
</ul>

<p>给你一个 <strong>打乱顺序</strong> 的句子 <code>s</code> ，它包含的单词不超过 <code>9</code> 个，请你重新构造并得到原本顺序的句子。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>s = "is2 sentence4 This1 a3"
<b>输出：</b>"This is a sentence"
<b>解释：</b>将 s 中的单词按照初始位置排序，得到 "This1 is2 a3 sentence4" ，然后删除数字。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>s = "Myself2 Me1 I4 and3"
<b>输出：</b>"Me Myself and I"
<b>解释：</b>将 s 中的单词按照初始位置排序，得到 "Me1 Myself2 and3 I4" ，然后删除数字。</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 <= s.length <= 200</code></li>
	<li><code>s</code> 只包含小写和大写英文字母、空格以及从 <code>1</code> 到 <code>9</code> 的数字。</li>
	<li><code>s</code> 中单词数目为 <code>1</code> 到 <code>9</code> 个。</li>
	<li><code>s</code> 中的单词由单个空格分隔。</li>
	<li><code>s</code> 不包含任何前导或者后缀空格。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：字符串分割

我们先将字符串 $s$ 按照空格分割，得到字符串数组 $\textit{ws}$，然后遍历数组 $\textit{ws}$，将每个单词的最后一个字符减去字符 '1'，得到的结果作为单词的索引，将单词的前缀作为单词的内容，最后将单词按照索引顺序拼接起来即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sortSentence(self, s: str) -> str:
        ws = [(w[:-1], int(w[-1])) for w in s.split()]
        ws.sort(key=lambda x: x[1])
        return ' '.join(w for w, _ in ws)
```

#### Java

```java
class Solution {
    public String sortSentence(String s) {
        String[] ws = s.split(" ");
        int n = ws.length;
        String[] ans = new String[n];
        for (int i = 0; i < n; ++i) {
            String w = ws[i];
            ans[w.charAt(w.length() - 1) - '1'] = w.substring(0, w.length() - 1);
        }
        return String.join(" ", ans);
    }
}
```

#### C++

```cpp
class Solution {
public:
    string sortSentence(string s) {
        istringstream iss(s);
        string w;
        vector<string> ws;
        while (iss >> w) {
            ws.push_back(w);
        }
        vector<string> ss(ws.size());
        for (auto& w : ws) {
            ss[w.back() - '1'] = w.substr(0, w.size() - 1);
        }
        string ans;
        for (auto& w : ss) {
            ans += w + " ";
        }
        ans.pop_back();
        return ans;
    }
};
```

#### Go

```go
func sortSentence(s string) string {
	ws := strings.Split(s, " ")
	ans := make([]string, len(ws))
	for _, w := range ws {
		ans[w[len(w)-1]-'1'] = w[:len(w)-1]
	}
	return strings.Join(ans, " ")
}
```

#### TypeScript

```ts
function sortSentence(s: string): string {
    const ws = s.split(' ');
    const ans = Array(ws.length);
    for (const w of ws) {
        ans[w.charCodeAt(w.length - 1) - '1'.charCodeAt(0)] = w.slice(0, -1);
    }
    return ans.join(' ');
}
```

#### JavaScript

```js
/**
 * @param {string} s
 * @return {string}
 */
var sortSentence = function (s) {
    const ws = s.split(' ');
    const ans = Array(ws.length);
    for (const w of ws) {
        ans[w.charCodeAt(w.length - 1) - '1'.charCodeAt(0)] = w.slice(0, -1);
    }
    return ans.join(' ');
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
