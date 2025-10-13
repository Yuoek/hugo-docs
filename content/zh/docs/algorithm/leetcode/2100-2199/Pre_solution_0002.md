---
title: "2110_股票平滑下跌阶段的数目"
date: 2025-10-08T18:39:03+08:00
weight: 2
tags: [二分查找, 动态规划, 哈希表, 图, 字符串, 拓扑排序, 数学, 数据库, 数组, 栈, 贪心]
---

{{< markmap >}}
### [2110_股票平滑下跌阶段的数目](#2110)
#### [数组](#2110)
#### [数学](#2110)
#### [动态规划](#2110)
### [2111_使数组 K 递增的最少操作次数](#2111)
#### [数组](#2111)
#### [二分查找](#2111)
### [2112_最繁忙的机场 🔒](#2112)
#### [数据库](#2112)
### [2113_查询删除和添加元素后的数组 🔒](#2113)
#### [数组](#2113)
### [2114_句子中的最多单词数](#2114)
#### [数组](#2114)
#### [字符串](#2114)
### [2115_从给定原材料中找到所有可以做出的菜](#2115)
#### [图](#2115)
#### [拓扑排序](#2115)
#### [数组](#2115)
#### [哈希表](#2115)
#### [字符串](#2115)
### [2116_判断一个括号字符串是否有效](#2116)
#### [栈](#2116)
#### [贪心](#2116)
#### [字符串](#2116)
### [2117_一个区间内所有数乘积的缩写](#2117)
#### [数学](#2117)
### [2118_建立方程 🔒](#2118)
#### [数据库](#2118)
### [2119_反转两次的数字](#2119)
#### [数学](#2119)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2110_股票平滑下跌阶段的数目
___
#### 数组
___
#### 数学
___
#### 动态规划
---
### 2111_使数组 K 递增的最少操作次数
___
#### 数组
___
#### 二分查找
---
### 2112_最繁忙的机场 🔒
___
#### 数据库
---
### 2113_查询删除和添加元素后的数组 🔒
___
#### 数组
---
### 2114_句子中的最多单词数
___
#### 数组
___
#### 字符串
---
### 2115_从给定原材料中找到所有可以做出的菜
___
#### 图
___
#### 拓扑排序
___
#### 数组
___
#### 哈希表
___
#### 字符串
---
### 2116_判断一个括号字符串是否有效
___
#### 栈
___
#### 贪心
___
#### 字符串
---
### 2117_一个区间内所有数乘积的缩写
___
#### 数学
---
### 2118_建立方程 🔒
___
#### 数据库
---
### 2119_反转两次的数字
___
#### 数学
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 动态规划 | 哈希表 |
| 图 | 字符串 | 拓扑排序 |
| 数学 | 数据库 | 数组 |
| 栈 | 贪心 |  |

# [2110. 股票平滑下跌阶段的数目](https://leetcode.cn/problems/number-of-smooth-descent-periods-of-a-stock){#2110}

{{< tabs "2110" >}}

{{% tab "python" %}}
```python
class Solution:
    def getDescentPeriods(self, prices: List[int]) -> int:
        ans = 0
        i, n = 0, len(prices)
        while i < n:
            j = i + 1
            while j < n and prices[j - 1] - prices[j] == 1:
                j += 1
            cnt = j - i
            ans += (1 + cnt) * cnt // 2
            i = j
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long getDescentPeriods(int[] prices) {
        long ans = 0;
        int n = prices.length;
        for (int i = 0, j = 0; i < n; i = j) {
            j = i + 1;
            while (j < n && prices[j - 1] - prices[j] == 1) {
                ++j;
            }
            int cnt = j - i;
            ans += (1L + cnt) * cnt / 2;
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
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        int n = prices.size();
        for (int i = 0, j = 0; i < n; i = j) {
            j = i + 1;
            while (j < n && prices[j - 1] - prices[j] == 1) {
                ++j;
            }
            int cnt = j - i;
            ans += (1LL + cnt) * cnt / 2;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getDescentPeriods(prices []int) (ans int64) {
	n := len(prices)
	for i, j := 0, 0; i < n; i = j {
		j = i + 1
		for j < n && prices[j-1]-prices[j] == 1 {
			j++
		}
		cnt := j - i
		ans += int64((1 + cnt) * cnt / 2)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function getDescentPeriods(prices: number[]): number {
    let ans = 0;
    const n = prices.length;
    for (let i = 0, j = 0; i < n; i = j) {
        j = i + 1;
        while (j < n && prices[j - 1] - prices[j] === 1) {
            ++j;
        }
        const cnt = j - i;
        ans += Math.floor(((1 + cnt) * cnt) / 2);
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

<p>给你一个整数数组&nbsp;<code>prices</code>&nbsp;，表示一支股票的历史每日股价，其中&nbsp;<code>prices[i]</code>&nbsp;是这支股票第&nbsp;<code>i</code>&nbsp;天的价格。</p>

<p>一个 <strong>平滑下降的阶段</strong>&nbsp;定义为：对于&nbsp;<strong>连续一天或者多天</strong>&nbsp;，每日股价都比 <strong>前一日股价恰好少 </strong><code>1</code>&nbsp;，这个阶段第一天的股价没有限制。</p>

<p>请你返回 <strong>平滑下降阶段</strong>&nbsp;的数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>prices = [3,2,1,4]
<b>输出：</b>7
<b>解释：</b>总共有 7 个平滑下降阶段：
[3], [2], [1], [4], [3,2], [2,1] 和 [3,2,1]
注意，仅一天按照定义也是平滑下降阶段。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>prices = [8,6,7,7]
<b>输出：</b>4
<b>解释：</b>总共有 4 个连续平滑下降阶段：[8], [6], [7] 和 [7]
由于 8 - 6 ≠ 1 ，所以 [8,6] 不是平滑下降阶段。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>prices = [1]
<b>输出：</b>1
<b>解释：</b>总共有 1 个平滑下降阶段：[1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= prices.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= prices[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

我们定义一个答案变量 `ans`，初始值为 $0$。

接下来，我们使用双指针 $i$ 和 $j$，分别指向当前平滑下降阶段的第一天和最后一天的下一天。初始时 $i = 0$, $j = 0$。

从左到右遍历数组 `prices`，对于每个位置 $i$，我们将 $j$ 向右移动，直到 $j$ 到达数组末尾或者 $prices[j - 1] - prices[j] \neq 1$ 为止。此时，$cnt = j - i$ 即为当前平滑下降阶段的长度，我们累加 $\frac{(1 + cnt) \times cnt}{2}$ 到答案变量 `ans` 中。接下来将 $i$ 更新为 $j$，继续遍历。

遍历结束后，返回答案变量 `ans` 即可。

时间复杂度 $O(n)$，其中 $n$ 为数组 `prices` 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getDescentPeriods(self, prices: List[int]) -> int:
        ans = 0
        i, n = 0, len(prices)
        while i < n:
            j = i + 1
            while j < n and prices[j - 1] - prices[j] == 1:
                j += 1
            cnt = j - i
            ans += (1 + cnt) * cnt // 2
            i = j
        return ans
```

#### Java

```java
class Solution {
    public long getDescentPeriods(int[] prices) {
        long ans = 0;
        int n = prices.length;
        for (int i = 0, j = 0; i < n; i = j) {
            j = i + 1;
            while (j < n && prices[j - 1] - prices[j] == 1) {
                ++j;
            }
            int cnt = j - i;
            ans += (1L + cnt) * cnt / 2;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        int n = prices.size();
        for (int i = 0, j = 0; i < n; i = j) {
            j = i + 1;
            while (j < n && prices[j - 1] - prices[j] == 1) {
                ++j;
            }
            int cnt = j - i;
            ans += (1LL + cnt) * cnt / 2;
        }
        return ans;
    }
};
```

#### Go

```go
func getDescentPeriods(prices []int) (ans int64) {
	n := len(prices)
	for i, j := 0, 0; i < n; i = j {
		j = i + 1
		for j < n && prices[j-1]-prices[j] == 1 {
			j++
		}
		cnt := j - i
		ans += int64((1 + cnt) * cnt / 2)
	}
	return
}
```

#### TypeScript

```ts
function getDescentPeriods(prices: number[]): number {
    let ans = 0;
    const n = prices.length;
    for (let i = 0, j = 0; i < n; i = j) {
        j = i + 1;
        while (j < n && prices[j - 1] - prices[j] === 1) {
            ++j;
        }
        const cnt = j - i;
        ans += Math.floor(((1 + cnt) * cnt) / 2);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2111. 使数组 K 递增的最少操作次数](https://leetcode.cn/problems/minimum-operations-to-make-the-array-k-increasing){#2111}

{{< tabs "2111" >}}

{{% tab "python" %}}
```python
class Solution:
    def kIncreasing(self, arr: List[int], k: int) -> int:
        def lis(arr):
            t = []
            for x in arr:
                idx = bisect_right(t, x)
                if idx == len(t):
                    t.append(x)
                else:
                    t[idx] = x
            return len(arr) - len(t)

        return sum(lis(arr[i::k]) for i in range(k))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int kIncreasing(int[] arr, int k) {
        int n = arr.length;
        int ans = 0;
        for (int i = 0; i < k; ++i) {
            List<Integer> t = new ArrayList<>();
            for (int j = i; j < n; j += k) {
                t.add(arr[j]);
            }
            ans += lis(t);
        }
        return ans;
    }

    private int lis(List<Integer> arr) {
        List<Integer> t = new ArrayList<>();
        for (int x : arr) {
            int idx = searchRight(t, x);
            if (idx == t.size()) {
                t.add(x);
            } else {
                t.set(idx, x);
            }
        }
        return arr.size() - t.size();
    }

    private int searchRight(List<Integer> arr, int x) {
        int left = 0, right = arr.size();
        while (left < right) {
            int mid = (left + right) >> 1;
            if (arr.get(mid) > x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int ans = 0, n = arr.size();
        for (int i = 0; i < k; ++i) {
            vector<int> t;
            for (int j = i; j < n; j += k) t.push_back(arr[j]);
            ans += lis(t);
        }
        return ans;
    }

    int lis(vector<int>& arr) {
        vector<int> t;
        for (int x : arr) {
            auto it = upper_bound(t.begin(), t.end(), x);
            if (it == t.end())
                t.push_back(x);
            else
                *it = x;
        }
        return arr.size() - t.size();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func kIncreasing(arr []int, k int) int {
	searchRight := func(arr []int, x int) int {
		left, right := 0, len(arr)
		for left < right {
			mid := (left + right) >> 1
			if arr[mid] > x {
				right = mid
			} else {
				left = mid + 1
			}
		}
		return left
	}

	lis := func(arr []int) int {
		var t []int
		for _, x := range arr {
			idx := searchRight(t, x)
			if idx == len(t) {
				t = append(t, x)
			} else {
				t[idx] = x
			}
		}
		return len(arr) - len(t)
	}

	n := len(arr)
	ans := 0
	for i := 0; i < k; i++ {
		var t []int
		for j := i; j < n; j += k {
			t = append(t, arr[j])
		}
		ans += lis(t)
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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始包含 <code>n</code>&nbsp;个正整数的数组&nbsp;<code>arr</code>&nbsp;，和一个正整数&nbsp;<code>k</code>&nbsp;。</p>

<p>如果对于每个满足&nbsp;<code>k &lt;= i &lt;= n-1</code>&nbsp;的下标&nbsp;<code>i</code>&nbsp;，都有&nbsp;<code>arr[i-k] &lt;= arr[i]</code>&nbsp;，那么我们称&nbsp;<code>arr</code>&nbsp;是 <strong>K</strong>&nbsp;<strong>递增</strong> 的。</p>

<ul>
	<li>比方说，<code>arr = [4, 1, 5, 2, 6, 2]</code>&nbsp;对于&nbsp;<code>k = 2</code>&nbsp;是 K 递增的，因为：

    <ul>
    	<li><code>arr[0] &lt;= arr[2] (4 &lt;= 5)</code></li>
    	<li><code>arr[1] &lt;= arr[3] (1 &lt;= 2)</code></li>
    	<li><code>arr[2] &lt;= arr[4] (5 &lt;= 6)</code></li>
    	<li><code>arr[3] &lt;= arr[5] (2 &lt;= 2)</code></li>
    </ul>
    </li>
    <li>但是，相同的数组&nbsp;<code>arr</code>&nbsp;对于&nbsp;<code>k = 1</code>&nbsp;不是 K 递增的（因为&nbsp;<code>arr[0] &gt; arr[1]</code>），对于&nbsp;<code>k = 3</code>&nbsp;也不是 K 递增的（因为&nbsp;<code>arr[0] &gt; arr[3]</code>&nbsp;）。</li>

</ul>

<p>每一次 <strong>操作</strong>&nbsp;中，你可以选择一个下标&nbsp;<code>i</code> 并将&nbsp;<code>arr[i]</code> <strong>改成任意&nbsp;</strong>正整数。</p>

<p>请你返回对于给定的 <code>k</code>&nbsp;，使数组变成 K 递增的 <strong>最少操作次数</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>arr = [5,4,3,2,1], k = 1
<b>输出：</b>4
<strong>解释：
</strong>对于 k = 1 ，数组最终必须变成非递减的。
可行的 K 递增结果数组为 [5,<em><strong>6</strong></em>,<em><strong>7</strong></em>,<em><strong>8</strong></em>,<em><strong>9</strong></em>]，[<em><strong>1</strong></em>,<em><strong>1</strong></em>,<em><strong>1</strong></em>,<em><strong>1</strong></em>,1]，[<em><strong>2</strong></em>,<em><strong>2</strong></em>,3,<em><strong>4</strong></em>,<em><strong>4</strong></em>] 。它们都需要 4 次操作。
次优解是将数组变成比方说 [<em><strong>6</strong></em>,<em><strong>7</strong></em>,<em><strong>8</strong></em>,<em><strong>9</strong></em>,<em><strong>10</strong></em>] ，因为需要 5 次操作。
显然我们无法使用少于 4 次操作将数组变成 K 递增的。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>arr = [4,1,5,2,6,2], k = 2
<b>输出：</b>0
<strong>解释：</strong>
这是题目描述中的例子。
对于每个满足 2 &lt;= i &lt;= 5 的下标 i ，有 arr[i-2] &lt;=<b> </b>arr[i] 。
由于给定数组已经是 K 递增的，我们不需要进行任何操作。</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>arr = [4,1,5,2,6,2], k = 3
<b>输出：</b>2
<strong>解释：</strong>
下标 3 和 5 是仅有的 3 &lt;= i &lt;= 5 且不满足 arr[i-3] &lt;= arr[i] 的下标。
将数组变成 K 递增的方法之一是将 arr[3] 变为 4 ，且将 arr[5] 变成 5 。
数组变为 [4,1,5,<em><strong>4</strong></em>,6,<em><strong>5</strong></em>] 。
可能有其他方法将数组变为 K 递增的，但没有任何一种方法需要的操作次数小于 2 次。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= arr[i], k &lt;= arr.length</code></li>
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
    def kIncreasing(self, arr: List[int], k: int) -> int:
        def lis(arr):
            t = []
            for x in arr:
                idx = bisect_right(t, x)
                if idx == len(t):
                    t.append(x)
                else:
                    t[idx] = x
            return len(arr) - len(t)

        return sum(lis(arr[i::k]) for i in range(k))
```

#### Java

```java
class Solution {
    public int kIncreasing(int[] arr, int k) {
        int n = arr.length;
        int ans = 0;
        for (int i = 0; i < k; ++i) {
            List<Integer> t = new ArrayList<>();
            for (int j = i; j < n; j += k) {
                t.add(arr[j]);
            }
            ans += lis(t);
        }
        return ans;
    }

    private int lis(List<Integer> arr) {
        List<Integer> t = new ArrayList<>();
        for (int x : arr) {
            int idx = searchRight(t, x);
            if (idx == t.size()) {
                t.add(x);
            } else {
                t.set(idx, x);
            }
        }
        return arr.size() - t.size();
    }

    private int searchRight(List<Integer> arr, int x) {
        int left = 0, right = arr.size();
        while (left < right) {
            int mid = (left + right) >> 1;
            if (arr.get(mid) > x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int ans = 0, n = arr.size();
        for (int i = 0; i < k; ++i) {
            vector<int> t;
            for (int j = i; j < n; j += k) t.push_back(arr[j]);
            ans += lis(t);
        }
        return ans;
    }

    int lis(vector<int>& arr) {
        vector<int> t;
        for (int x : arr) {
            auto it = upper_bound(t.begin(), t.end(), x);
            if (it == t.end())
                t.push_back(x);
            else
                *it = x;
        }
        return arr.size() - t.size();
    }
};
```

#### Go

```go
func kIncreasing(arr []int, k int) int {
	searchRight := func(arr []int, x int) int {
		left, right := 0, len(arr)
		for left < right {
			mid := (left + right) >> 1
			if arr[mid] > x {
				right = mid
			} else {
				left = mid + 1
			}
		}
		return left
	}

	lis := func(arr []int) int {
		var t []int
		for _, x := range arr {
			idx := searchRight(t, x)
			if idx == len(t) {
				t = append(t, x)
			} else {
				t[idx] = x
			}
		}
		return len(arr) - len(t)
	}

	n := len(arr)
	ans := 0
	for i := 0; i < k; i++ {
		var t []int
		for j := i; j < n; j += k {
			t = append(t, arr[j])
		}
		ans += lis(t)
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2112. 最繁忙的机场 🔒](https://leetcode.cn/problems/the-airport-with-the-most-traffic){#2112}

{{< tabs "2112" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT * FROM Flights
        UNION
        SELECT arrival_airport, departure_airport, flights_count FROM Flights
    ),
    P AS (
        SELECT departure_airport, SUM(flights_count) AS cnt
        FROM T
        GROUP BY 1
    )
SELECT departure_airport AS airport_id
FROM P
WHERE cnt = (SELECT MAX(cnt) FROM P);
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Flights</code></p>

<pre>
+-------------------+------+
| Column Name       | Type |
+-------------------+------+
| departure_airport | int  |
| arrival_airport   | int  |
| flights_count     | int  |
+-------------------+------+
(departure_airport, arrival_airport) 是该表的主键列。
该表的每一行都表示从 departure_airport 出发并到达 arrival_airport 的 flights_count 航班。
</pre>

<p>&nbsp;</p>

<p>编写一个 SQL 来查询&nbsp;<strong>流量最大&nbsp;</strong>的机场的 ID。客流量最大的机场是指从该机场起飞或抵达该机场的航班总数最多的机场。如果有多个机场流量最大，请全部查询出来。</p>

<p data-group="1-1">以&nbsp;<strong>任意顺序&nbsp;</strong>返回结果表。</p>

<p>查询结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
Flights 表:
+-------------------+-----------------+---------------+
| departure_airport | arrival_airport | flights_count |
+-------------------+-----------------+---------------+
| 1                 | 2               | 4             |
| 2                 | 1               | 5             |
| 2                 | 4               | 5             |
+-------------------+-----------------+---------------+
<strong>输出:</strong> 
+------------+
| airport_id |
+------------+
| 2          |
+------------+
<strong>解释:</strong> 
1 号机场有 9 个航班 (4 个出发, 5 个到达).
2 号机场有 14 个航班 (10 个出发, 4 个到达).
4 号机场有 5 个航班 (5 个到达).
客流量最大的机场是 2 号机场。
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre>
<strong>输入:</strong> 
Flights 表:
+-------------------+-----------------+---------------+
| departure_airport | arrival_airport | flights_count |
+-------------------+-----------------+---------------+
| 1                 | 2               | 4             |
| 2                 | 1               | 5             |
| 3                 | 4               | 5             |
| 4                 | 3               | 4             |
| 5                 | 6               | 7             |
+-------------------+-----------------+---------------+
<strong>输出:</strong> 
+------------+
| airport_id |
+------------+
| 1          |
| 2          |
| 3          |
| 4          |
+------------+
<strong>解释:</strong> 
1 号机场有 9 个航班 (4 个出发, 5 个到达).
2 号机场有 9 个航班 (5 个出发, 4 个到达).
3 号机场有 9 个航班 (5 个出发, 4 个到达).
4 号机场有 9 个航班 (5 个出发, 4 个到达).
5 号机场有 7 个航班 (7 个出发).
6 号机场有 7 个航班 (7 个到达).
流量最大的机场是机场 1、2、3 和 4。</pre>

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
        SELECT * FROM Flights
        UNION
        SELECT arrival_airport, departure_airport, flights_count FROM Flights
    ),
    P AS (
        SELECT departure_airport, SUM(flights_count) AS cnt
        FROM T
        GROUP BY 1
    )
SELECT departure_airport AS airport_id
FROM P
WHERE cnt = (SELECT MAX(cnt) FROM P);
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2113. 查询删除和添加元素后的数组 🔒](https://leetcode.cn/problems/elements-in-array-after-removing-and-replacing-elements){#2113}

{{< tabs "2113" >}}

{{% tab "python" %}}
```python
class Solution:
    def elementInNums(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        n, m = len(nums), len(queries)
        ans = [-1] * m
        for j, (t, i) in enumerate(queries):
            t %= 2 * n
            if t < n and i < n - t:
                ans[j] = nums[i + t]
            elif t > n and i < t - n:
                ans[j] = nums[i]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] elementInNums(int[] nums, int[][] queries) {
        int n = nums.length, m = queries.length;
        int[] ans = new int[m];
        for (int j = 0; j < m; ++j) {
            ans[j] = -1;
            int t = queries[j][0], i = queries[j][1];
            t %= (2 * n);
            if (t < n && i < n - t) {
                ans[j] = nums[i + t];
            } else if (t > n && i < t - n) {
                ans[j] = nums[i];
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
    vector<int> elementInNums(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        vector<int> ans(m, -1);
        for (int j = 0; j < m; ++j) {
            int t = queries[j][0], i = queries[j][1];
            t %= (n * 2);
            if (t < n && i < n - t) {
                ans[j] = nums[i + t];
            } else if (t > n && i < t - n) {
                ans[j] = nums[i];
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func elementInNums(nums []int, queries [][]int) []int {
	n, m := len(nums), len(queries)
	ans := make([]int, m)
	for j, q := range queries {
		t, i := q[0], q[1]
		t %= (n * 2)
		ans[j] = -1
		if t < n && i < n-t {
			ans[j] = nums[i+t]
		} else if t > n && i < t-n {
			ans[j] = nums[i]
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function elementInNums(nums: number[], queries: number[][]): number[] {
    const n = nums.length;
    const m = queries.length;
    const ans: number[] = Array(m).fill(-1);
    for (let j = 0; j < m; ++j) {
        let [t, i] = queries[j];
        t %= 2 * n;
        if (t < n && i < n - t) {
            ans[j] = nums[i + t];
        } else if (t >= n && i < t - n) {
            ans[j] = nums[i];
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

<p>给你一个&nbsp;<strong>下标从 0 开始</strong>&nbsp;的数组&nbsp;<code>nums</code>。一开始，在第 <code>0</code> 分钟，数组没有变化。此后每过一分钟，数组的 <strong>最左边</strong> 的元素将被移除，直到数组为空。然后，每过一分钟，数组的 <strong>尾部</strong> 将添加一个元素，添加的顺序和删除的顺序相同，直到数组被复原。此后上述操作无限循环进行。</p>

<ul>
	<li>举个例子，如果 <code>nums = [0, 1, 2]</code>，那么数组将按如下流程变化：<code>[0,1,2] → [1,2] → [2] → [] → [0] → [0,1] → [0,1,2] → [1,2] → [2] → [] → [0] → [0,1] → [0,1,2] → ...</code></li>
</ul>

<p>然后给你一个长度为 <code>n</code> 的二维数组 <code>queries</code>，其中 <code>queries[j] = [time<sub>j</sub>, index<sub>j</sub>]</code>，表示第 <code>j</code> 个查询。第 <code>j</code> 个查询的答案定义如下：</p>

<ul>
	<li>如果在时刻&nbsp;<code>time<sub>j</sub></code>，<code>index<sub>j</sub> &lt; nums.length</code>，那么答案是此时的 <code>nums[index<sub>j</sub>]</code>；</li>
	<li>如果在时刻&nbsp;<code>time<sub>j</sub></code>，<code>index<sub>j</sub> &gt;= nums.length</code>，那么答案是 <code>-1</code>。</li>
</ul>

<p>请返回一个长度为 <code>n</code> 的整数数组 <code>ans</code>，其中 <code>ans[j]</code> 为第 <code>j</code> 个查询的答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> nums = [0,1,2], queries = [[0,2],[2,0],[3,2],[5,0]]
<strong>输出:</strong> [2,2,-1,0]
<strong>解释:</strong>
第 0 分钟: [0,1,2] - 数组和 nums 相同。
第 1 分钟: [1,2]   - 最左侧元素 0 被移除。
第 2 分钟: [2]     - 最左侧元素 1 被移除。
第 3 分钟: []      - 最左侧元素 0 被移除。
第 4 分钟: [0]     - 0 被添加到数组尾部。
第 5 分钟: [0,1]   - 1 被添加到数组尾部。

在第 0 分钟, nums[2] 是 2。
在第 2 分钟, nums[0] 是 2。
在第 3 分钟, nums[2] 不存在。
在第 5 分钟, nums[0] 是 0。
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> nums = [2], queries = [[0,0],[1,0],[2,0],[3,0]]
<strong>输出:</strong> [2,-1,2,-1]
第 0 分钟: [2] - 数组和 nums 相同。
第 1 分钟: []  - 最左侧元素 2 被移除。
第 2 分钟: [2] - 2 被添加到数组尾部。
第 3 分钟: []  - 最左侧元素 2 被移除。

在第 0 分钟, nums[0] 是 2。
在第 1 分钟, nums[0] 不存在。
在第 2 分钟, nums[0] 是 2。
在第 3 分钟, nums[0] 不存在。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 100</code></li>
	<li><code>n == queries.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>queries[j].length == 2</code></li>
	<li><code>0 &lt;= time<sub>j</sub> &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= index<sub>j</sub> &lt; nums.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：直接计算

我们先初始化一个数组 $ans$，长度为 $m$，用于存储答案，初始化所有元素为 $-1$。

接下来遍历数组 $queries$，对于每个查询，我们先获取当前查询的时间 $t$ 和索引 $i$，先将 $t$ 对 $2n$ 取模，然后判断 $t$ 和 $n$ 的关系：

-   如果 $t \lt n$，那么 $t$ 时刻的数组元素个数为 $n - t$，并且数组元素是原数组元素整体向左移动 $t$ 个位置后的结果，因此如果 $i \lt n - t$，答案为 $nums[i + t]$；
-   如果 $t \gt n$，那么 $t$ 时刻的数组元素个数为 $t - n$，并且数组元素是原数组元素的前 $t - n$ 个元素，因此如果 $i \lt t - n$，答案为 $nums[i]$。

最后返回数组 $ans$ 即可。

时间复杂度 $O(m)$，其中 $m$ 为数组 $queries$ 的长度。忽略答案数组的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def elementInNums(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        n, m = len(nums), len(queries)
        ans = [-1] * m
        for j, (t, i) in enumerate(queries):
            t %= 2 * n
            if t < n and i < n - t:
                ans[j] = nums[i + t]
            elif t > n and i < t - n:
                ans[j] = nums[i]
        return ans
```

#### Java

```java
class Solution {
    public int[] elementInNums(int[] nums, int[][] queries) {
        int n = nums.length, m = queries.length;
        int[] ans = new int[m];
        for (int j = 0; j < m; ++j) {
            ans[j] = -1;
            int t = queries[j][0], i = queries[j][1];
            t %= (2 * n);
            if (t < n && i < n - t) {
                ans[j] = nums[i + t];
            } else if (t > n && i < t - n) {
                ans[j] = nums[i];
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
    vector<int> elementInNums(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        vector<int> ans(m, -1);
        for (int j = 0; j < m; ++j) {
            int t = queries[j][0], i = queries[j][1];
            t %= (n * 2);
            if (t < n && i < n - t) {
                ans[j] = nums[i + t];
            } else if (t > n && i < t - n) {
                ans[j] = nums[i];
            }
        }
        return ans;
    }
};
```

#### Go

```go
func elementInNums(nums []int, queries [][]int) []int {
	n, m := len(nums), len(queries)
	ans := make([]int, m)
	for j, q := range queries {
		t, i := q[0], q[1]
		t %= (n * 2)
		ans[j] = -1
		if t < n && i < n-t {
			ans[j] = nums[i+t]
		} else if t > n && i < t-n {
			ans[j] = nums[i]
		}
	}
	return ans
}
```

#### TypeScript

```ts
function elementInNums(nums: number[], queries: number[][]): number[] {
    const n = nums.length;
    const m = queries.length;
    const ans: number[] = Array(m).fill(-1);
    for (let j = 0; j < m; ++j) {
        let [t, i] = queries[j];
        t %= 2 * n;
        if (t < n && i < n - t) {
            ans[j] = nums[i + t];
        } else if (t >= n && i < t - n) {
            ans[j] = nums[i];
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

# [2114. 句子中的最多单词数](https://leetcode.cn/problems/maximum-number-of-words-found-in-sentences){#2114}

{{< tabs "2114" >}}

{{% tab "python" %}}
```python
class Solution:
    def mostWordsFound(self, sentences: List[str]) -> int:
        return 1 + max(s.count(' ') for s in sentences)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int mostWordsFound(String[] sentences) {
        int ans = 0;
        for (var s : sentences) {
            int cnt = 1;
            for (int i = 0; i < s.length(); ++i) {
                if (s.charAt(i) == ' ') {
                    ++cnt;
                }
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
    int mostWordsFound(vector<string>& sentences) {
        int ans = 0;
        for (auto& s : sentences) {
            int cnt = 1 + count(s.begin(), s.end(), ' ');
            ans = max(ans, cnt);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func mostWordsFound(sentences []string) (ans int) {
	for _, s := range sentences {
		cnt := 1 + strings.Count(s, " ")
		if ans < cnt {
			ans = cnt
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function mostWordsFound(sentences: string[]): number {
    return sentences.reduce(
        (r, s) =>
            Math.max(
                r,
                [...s].reduce((r, c) => r + (c === ' ' ? 1 : 0), 1),
            ),
        0,
    );
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn most_words_found(sentences: Vec<String>) -> i32 {
        let mut ans = 0;
        for s in sentences.iter() {
            let mut count = 1;
            for c in s.as_bytes() {
                if *c == b' ' {
                    count += 1;
                }
            }
            ans = ans.max(count);
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
#define max(a, b) (((a) > (b)) ? (a) : (b))

int mostWordsFound(char** sentences, int sentencesSize) {
    int ans = 0;
    for (int i = 0; i < sentencesSize; i++) {
        char* s = sentences[i];
        int count = 1;
        for (int j = 0; s[j]; j++) {
            if (s[j] == ' ') {
                count++;
            }
        }
        ans = max(ans, count);
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

<p>一个 <strong>句子</strong>&nbsp;由一些 <strong>单词</strong>&nbsp;以及它们之间的单个空格组成，句子的开头和结尾不会有多余空格。</p>

<p>给你一个字符串数组&nbsp;<code>sentences</code>&nbsp;，其中&nbsp;<code>sentences[i]</code>&nbsp;表示单个 <strong>句子</strong>&nbsp;。</p>

<p>请你返回单个句子里 <strong>单词的最多数目</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>sentences = ["alice and bob love leetcode", "i think so too", <em><strong>"this is great thanks very much"</strong></em>]
<b>输出：</b>6
<b>解释：</b>
- 第一个句子 "alice and bob love leetcode" 总共有 5 个单词。
- 第二个句子 "i think so too" 总共有 4 个单词。
- 第三个句子 "this is great thanks very much" 总共有 6 个单词。
所以，单个句子中有最多单词数的是第三个句子，总共有 6 个单词。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>sentences = ["please wait", <em><strong>"continue to fight"</strong></em>, <em><strong>"continue to win"</strong></em>]
<b>输出：</b>3
<b>解释：</b>可能有多个句子有相同单词数。
这个例子中，第二个句子和第三个句子（加粗斜体）有相同数目的单词数。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= sentences.length &lt;= 100</code></li>
	<li><code>1 &lt;= sentences[i].length &lt;= 100</code></li>
	<li><code>sentences[i]</code>&nbsp;只包含小写英文字母和&nbsp;<code>' '</code>&nbsp;。</li>
	<li><code>sentences[i]</code>&nbsp;的开头和结尾都没有空格。</li>
	<li><code>sentences[i]</code>&nbsp;中所有单词由单个空格隔开。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：空格计数

我们遍历数组 `sentences`，对于每个句子，我们计算其中的空格数，那么单词数就是空格数加 $1$。最后返回最大的单词数即可。

时间复杂度 $O(L)$，其中 $L$ 是数组 `sentences` 中所有字符串的长度之和。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def mostWordsFound(self, sentences: List[str]) -> int:
        return 1 + max(s.count(' ') for s in sentences)
```

#### Java

```java
class Solution {
    public int mostWordsFound(String[] sentences) {
        int ans = 0;
        for (var s : sentences) {
            int cnt = 1;
            for (int i = 0; i < s.length(); ++i) {
                if (s.charAt(i) == ' ') {
                    ++cnt;
                }
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
    int mostWordsFound(vector<string>& sentences) {
        int ans = 0;
        for (auto& s : sentences) {
            int cnt = 1 + count(s.begin(), s.end(), ' ');
            ans = max(ans, cnt);
        }
        return ans;
    }
};
```

#### Go

```go
func mostWordsFound(sentences []string) (ans int) {
	for _, s := range sentences {
		cnt := 1 + strings.Count(s, " ")
		if ans < cnt {
			ans = cnt
		}
	}
	return
}
```

#### TypeScript

```ts
function mostWordsFound(sentences: string[]): number {
    return sentences.reduce(
        (r, s) =>
            Math.max(
                r,
                [...s].reduce((r, c) => r + (c === ' ' ? 1 : 0), 1),
            ),
        0,
    );
}
```

#### Rust

```rust
impl Solution {
    pub fn most_words_found(sentences: Vec<String>) -> i32 {
        let mut ans = 0;
        for s in sentences.iter() {
            let mut count = 1;
            for c in s.as_bytes() {
                if *c == b' ' {
                    count += 1;
                }
            }
            ans = ans.max(count);
        }
        ans
    }
}
```

#### C

```c
#define max(a, b) (((a) > (b)) ? (a) : (b))

int mostWordsFound(char** sentences, int sentencesSize) {
    int ans = 0;
    for (int i = 0; i < sentencesSize; i++) {
        char* s = sentences[i];
        int count = 1;
        for (int j = 0; s[j]; j++) {
            if (s[j] == ' ') {
                count++;
            }
        }
        ans = max(ans, count);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2115. 从给定原材料中找到所有可以做出的菜](https://leetcode.cn/problems/find-all-possible-recipes-from-given-supplies){#2115}

{{< tabs "2115" >}}

{{% tab "python" %}}
```python
class Solution:
    def findAllRecipes(
        self, recipes: List[str], ingredients: List[List[str]], supplies: List[str]
    ) -> List[str]:
        g = defaultdict(list)
        indeg = defaultdict(int)
        for a, b in zip(recipes, ingredients):
            for v in b:
                g[v].append(a)
            indeg[a] += len(b)
        q = supplies
        ans = []
        for i in q:
            for j in g[i]:
                indeg[j] -= 1
                if indeg[j] == 0:
                    ans.append(j)
                    q.append(j)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<String> findAllRecipes(
        String[] recipes, List<List<String>> ingredients, String[] supplies) {
        Map<String, List<String>> g = new HashMap<>();
        Map<String, Integer> indeg = new HashMap<>();
        for (int i = 0; i < recipes.length; ++i) {
            for (String v : ingredients.get(i)) {
                g.computeIfAbsent(v, k -> new ArrayList<>()).add(recipes[i]);
            }
            indeg.put(recipes[i], ingredients.get(i).size());
        }
        Deque<String> q = new ArrayDeque<>();
        for (String s : supplies) {
            q.offer(s);
        }
        List<String> ans = new ArrayList<>();
        while (!q.isEmpty()) {
            for (int n = q.size(); n > 0; --n) {
                String i = q.pollFirst();
                for (String j : g.getOrDefault(i, Collections.emptyList())) {
                    indeg.put(j, indeg.get(j) - 1);
                    if (indeg.get(j) == 0) {
                        ans.add(j);
                        q.offer(j);
                    }
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
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> g;
        unordered_map<string, int> indeg;
        for (int i = 0; i < recipes.size(); ++i) {
            for (auto& v : ingredients[i]) {
                g[v].push_back(recipes[i]);
            }
            indeg[recipes[i]] = ingredients[i].size();
        }
        queue<string> q;
        for (auto& s : supplies) {
            q.push(s);
        }
        vector<string> ans;
        while (!q.empty()) {
            for (int n = q.size(); n; --n) {
                auto i = q.front();
                q.pop();
                for (auto j : g[i]) {
                    if (--indeg[j] == 0) {
                        ans.push_back(j);
                        q.push(j);
                    }
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
func findAllRecipes(recipes []string, ingredients [][]string, supplies []string) []string {
	g := map[string][]string{}
	indeg := map[string]int{}
	for i, a := range recipes {
		for _, b := range ingredients[i] {
			g[b] = append(g[b], a)
		}
		indeg[a] = len(ingredients[i])
	}
	q := []string{}
	for _, s := range supplies {
		q = append(q, s)
	}
	ans := []string{}
	for len(q) > 0 {
		for n := len(q); n > 0; n-- {
			i := q[0]
			q = q[1:]
			for _, j := range g[i] {
				indeg[j]--
				if indeg[j] == 0 {
					ans = append(ans, j)
					q = append(q, j)
				}
			}
		}
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

<p>你有 <code>n</code>&nbsp;道不同菜的信息。给你一个字符串数组&nbsp;<code>recipes</code>&nbsp;和一个二维字符串数组&nbsp;<code>ingredients</code>&nbsp;。第&nbsp;<code>i</code>&nbsp;道菜的名字为&nbsp;<code>recipes[i]</code>&nbsp;，如果你有它&nbsp;<strong>所有</strong>&nbsp;的原材料&nbsp;<code>ingredients[i]</code>&nbsp;，那么你可以&nbsp;<strong>做出</strong>&nbsp;这道菜。一份食谱也可以是 <strong>其它</strong>&nbsp;食谱的原料，也就是说&nbsp;<code>ingredients[i]</code>&nbsp;可能包含&nbsp;<code>recipes</code>&nbsp;中另一个字符串。</p>

<p>同时给你一个字符串数组&nbsp;<code>supplies</code>&nbsp;，它包含你初始时拥有的所有原材料，每一种原材料你都有无限多。</p>

<p>请你返回你可以做出的所有菜。你可以以 <strong>任意顺序</strong>&nbsp;返回它们。</p>

<p>注意两道菜在它们的原材料中可能互相包含。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>recipes = ["bread"], ingredients = [["yeast","flour"]], supplies = ["yeast","flour","corn"]
<b>输出：</b>["bread"]
<strong>解释：</strong>
我们可以做出 "bread" ，因为我们有原材料 "yeast" 和 "flour" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>recipes = ["bread","sandwich"], ingredients = [["yeast","flour"],["bread","meat"]], supplies = ["yeast","flour","meat"]
<b>输出：</b>["bread","sandwich"]
<strong>解释：</strong>
我们可以做出 "bread" ，因为我们有原材料 "yeast" 和 "flour" 。
我们可以做出 "sandwich" ，因为我们有原材料 "meat" 且可以做出原材料 "bread" 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>recipes = ["bread","sandwich","burger"], ingredients = [["yeast","flour"],["bread","meat"],["sandwich","meat","bread"]], supplies = ["yeast","flour","meat"]
<b>输出：</b>["bread","sandwich","burger"]
<strong>解释：</strong>
我们可以做出 "bread" ，因为我们有原材料 "yeast" 和 "flour" 。
我们可以做出 "sandwich" ，因为我们有原材料 "meat" 且可以做出原材料 "bread" 。
我们可以做出 "burger" ，因为我们有原材料 "meat" 且可以做出原材料 "bread" 和 "sandwich" 。
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<b>输入：</b>recipes = ["bread"], ingredients = [["yeast","flour"]], supplies = ["yeast"]
<b>输出：</b>[]
<strong>解释：</strong>
我们没法做出任何菜，因为我们只有原材料 "yeast" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == recipes.length == ingredients.length</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= ingredients[i].length, supplies.length &lt;= 100</code></li>
	<li><code>1 &lt;= recipes[i].length, ingredients[i][j].length, supplies[k].length &lt;= 10</code></li>
	<li><code>recipes[i], ingredients[i][j]</code>&nbsp;和&nbsp;<code>supplies[k]</code>&nbsp;只包含小写英文字母。</li>
	<li>所有&nbsp;<code>recipes</code> 和&nbsp;<code>supplies</code>&nbsp;中的值互不相同。</li>
	<li><code>ingredients[i]</code>&nbsp;中的字符串互不相同。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：拓扑排序

首先，我们可以将每道菜看成一个节点，每个节点的入度表示其所需的原材料数量。我们可以通过拓扑排序的方式，找到所有可以做出的菜。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findAllRecipes(
        self, recipes: List[str], ingredients: List[List[str]], supplies: List[str]
    ) -> List[str]:
        g = defaultdict(list)
        indeg = defaultdict(int)
        for a, b in zip(recipes, ingredients):
            for v in b:
                g[v].append(a)
            indeg[a] += len(b)
        q = supplies
        ans = []
        for i in q:
            for j in g[i]:
                indeg[j] -= 1
                if indeg[j] == 0:
                    ans.append(j)
                    q.append(j)
        return ans
```

#### Java

```java
class Solution {
    public List<String> findAllRecipes(
        String[] recipes, List<List<String>> ingredients, String[] supplies) {
        Map<String, List<String>> g = new HashMap<>();
        Map<String, Integer> indeg = new HashMap<>();
        for (int i = 0; i < recipes.length; ++i) {
            for (String v : ingredients.get(i)) {
                g.computeIfAbsent(v, k -> new ArrayList<>()).add(recipes[i]);
            }
            indeg.put(recipes[i], ingredients.get(i).size());
        }
        Deque<String> q = new ArrayDeque<>();
        for (String s : supplies) {
            q.offer(s);
        }
        List<String> ans = new ArrayList<>();
        while (!q.isEmpty()) {
            for (int n = q.size(); n > 0; --n) {
                String i = q.pollFirst();
                for (String j : g.getOrDefault(i, Collections.emptyList())) {
                    indeg.put(j, indeg.get(j) - 1);
                    if (indeg.get(j) == 0) {
                        ans.add(j);
                        q.offer(j);
                    }
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
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> g;
        unordered_map<string, int> indeg;
        for (int i = 0; i < recipes.size(); ++i) {
            for (auto& v : ingredients[i]) {
                g[v].push_back(recipes[i]);
            }
            indeg[recipes[i]] = ingredients[i].size();
        }
        queue<string> q;
        for (auto& s : supplies) {
            q.push(s);
        }
        vector<string> ans;
        while (!q.empty()) {
            for (int n = q.size(); n; --n) {
                auto i = q.front();
                q.pop();
                for (auto j : g[i]) {
                    if (--indeg[j] == 0) {
                        ans.push_back(j);
                        q.push(j);
                    }
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findAllRecipes(recipes []string, ingredients [][]string, supplies []string) []string {
	g := map[string][]string{}
	indeg := map[string]int{}
	for i, a := range recipes {
		for _, b := range ingredients[i] {
			g[b] = append(g[b], a)
		}
		indeg[a] = len(ingredients[i])
	}
	q := []string{}
	for _, s := range supplies {
		q = append(q, s)
	}
	ans := []string{}
	for len(q) > 0 {
		for n := len(q); n > 0; n-- {
			i := q[0]
			q = q[1:]
			for _, j := range g[i] {
				indeg[j]--
				if indeg[j] == 0 {
					ans = append(ans, j)
					q = append(q, j)
				}
			}
		}
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2116. 判断一个括号字符串是否有效](https://leetcode.cn/problems/check-if-a-parentheses-string-can-be-valid){#2116}

{{< tabs "2116" >}}

{{% tab "python" %}}
```python
class Solution:
    def canBeValid(self, s: str, locked: str) -> bool:
        n = len(s)
        if n & 1:
            return False
        x = 0
        for i in range(n):
            if s[i] == '(' or locked[i] == '0':
                x += 1
            elif x:
                x -= 1
            else:
                return False
        x = 0
        for i in range(n - 1, -1, -1):
            if s[i] == ')' or locked[i] == '0':
                x += 1
            elif x:
                x -= 1
            else:
                return False
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean canBeValid(String s, String locked) {
        int n = s.length();
        if (n % 2 == 1) {
            return false;
        }
        int x = 0;
        for (int i = 0; i < n; ++i) {
            if (s.charAt(i) == '(' || locked.charAt(i) == '0') {
                ++x;
            } else if (x > 0) {
                --x;
            } else {
                return false;
            }
        }
        x = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s.charAt(i) == ')' || locked.charAt(i) == '0') {
                ++x;
            } else if (x > 0) {
                --x;
            } else {
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
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n & 1) {
            return false;
        }
        int x = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(' || locked[i] == '0') {
                ++x;
            } else if (x) {
                --x;
            } else {
                return false;
            }
        }
        x = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == ')' || locked[i] == '0') {
                ++x;
            } else if (x) {
                --x;
            } else {
                return false;
            }
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func canBeValid(s string, locked string) bool {
	n := len(s)
	if n%2 == 1 {
		return false
	}
	x := 0
	for i := range s {
		if s[i] == '(' || locked[i] == '0' {
			x++
		} else if x > 0 {
			x--
		} else {
			return false
		}
	}
	x = 0
	for i := n - 1; i >= 0; i-- {
		if s[i] == ')' || locked[i] == '0' {
			x++
		} else if x > 0 {
			x--
		} else {
			return false
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function canBeValid(s: string, locked: string): boolean {
    const n = s.length;
    if (n & 1) {
        return false;
    }
    let x = 0;
    for (let i = 0; i < n; ++i) {
        if (s[i] === '(' || locked[i] === '0') {
            ++x;
        } else if (x > 0) {
            --x;
        } else {
            return false;
        }
    }
    x = 0;
    for (let i = n - 1; i >= 0; --i) {
        if (s[i] === ')' || locked[i] === '0') {
            ++x;
        } else if (x > 0) {
            --x;
        } else {
            return false;
        }
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

<p>一个括号字符串是只由&nbsp;<code>'('</code> 和&nbsp;<code>')'</code>&nbsp;组成的&nbsp;<strong>非空</strong>&nbsp;字符串。如果一个字符串满足下面 <b>任意</b>&nbsp;一个条件，那么它就是有效的：</p>

<ul>
	<li>字符串为&nbsp;<code>()</code>.</li>
	<li>它可以表示为 <code>AB</code><span style="">（</span><code>A</code>&nbsp;与&nbsp;<code>B</code>&nbsp;连接），其中<code>A</code> 和&nbsp;<code>B</code>&nbsp;都是有效括号字符串。</li>
	<li>它可以表示为&nbsp;<code>(A)</code>&nbsp;，其中&nbsp;<code>A</code>&nbsp;是一个有效括号字符串。</li>
</ul>

<p>给你一个括号字符串&nbsp;<code>s</code>&nbsp;和一个字符串&nbsp;<code>locked</code>&nbsp;，两者长度都为&nbsp;<code>n</code>&nbsp;。<code>locked</code>&nbsp;是一个二进制字符串，只包含&nbsp;<code>'0'</code>&nbsp;和&nbsp;<code>'1'</code>&nbsp;。对于&nbsp;<code>locked</code>&nbsp;中&nbsp;<strong>每一个</strong>&nbsp;下标&nbsp;<code>i</code> ：</p>

<ul>
	<li>如果&nbsp;<code>locked[i]</code>&nbsp;是&nbsp;<code>'1'</code>&nbsp;，你 <strong>不能</strong>&nbsp;改变&nbsp;<code>s[i]</code>&nbsp;。</li>
	<li>如果&nbsp;<code>locked[i]</code>&nbsp;是&nbsp;<code>'0'</code>&nbsp;，你&nbsp;<strong>可以</strong>&nbsp;将&nbsp;<code>s[i]</code>&nbsp;变为&nbsp;<code>'('</code>&nbsp;或者&nbsp;<code>')'</code>&nbsp;。</li>
</ul>

<p>如果你可以将 <code>s</code>&nbsp;变为有效括号字符串，请你返回&nbsp;<code>true</code>&nbsp;，否则返回&nbsp;<code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2116.Check%20if%20a%20Parentheses%20String%20Can%20Be%20Valid/images/eg1.png" style="width: 311px; height: 101px;" /></p>

<pre>
<b>输入：</b>s = "))()))", locked = "010100"
<b>输出：</b>true
<b>解释：</b>locked[1] == '1' 和 locked[3] == '1' ，所以我们无法改变 s[1] 或者 s[3] 。
我们可以将 s[0] 和 s[4] 变为 '(' ，不改变 s[2] 和 s[5] ，使 s 变为有效字符串。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>s = "()()", locked = "0000"
<b>输出：</b>true
<b>解释：</b>我们不需要做任何改变，因为 s 已经是有效字符串了。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>s = ")", locked = "0"
<b>输出：</b>false
<b>解释：</b>locked 允许改变 s[0] 。
但无论将 s[0] 变为 '(' 或者 ')' 都无法使 s 变为有效字符串。
</pre>

<p><strong class="example">示例 4：</strong></p>

<pre>
<b>输入：</b>s = "(((())(((())", locked = "111111010111"
<b>输出：</b>true
<b>解释：</b>locked 允许我们改变 s[6] 和 s[8]。
我们将 s[6] 和 s[8] 改为 ')' 使 s 变为有效字符串。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == s.length == locked.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code>&nbsp;要么是&nbsp;<code>'('</code>&nbsp;要么是&nbsp;<code>')'</code>&nbsp;。</li>
	<li><code>locked[i]</code> 要么是&nbsp;<code>'0'</code>&nbsp;要么是&nbsp;<code>'1'</code> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 两次遍历

我们观察发现，奇数长度的字符串一定不是有效的括号字符串，因为无论怎么匹配，都会剩下一个括号。因此，如果字符串 $s$ 的长度是奇数，提前返回 $\textit{false}$。

接下来，我们进行两次遍历。

第一次从左到右，判断所有的 `'('` 括号是否可以被 `')'` 或者可变括号匹配，如果不可以，直接返回 $\textit{false}$。

第二次从右到左，判断所有的 `')'` 括号是否可以被 `'('` 或者可变括号匹配，如果不可以，直接返回 $\textit{false}$。

遍历结束，说明所有的括号都可以被匹配，字符串 $s$ 是有效的括号字符串，返回 $\textit{true}$。

时间复杂度 $O(n)$，其中 $n$ 为字符串 $s$ 的长度。空间复杂度 $O(1)$。

相似题目：

-   [678. 有效的括号字符串](https://github.com/doocs/leetcode/blob/main/solution/0600-0699/0678.Valid%20Parenthesis%20String/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canBeValid(self, s: str, locked: str) -> bool:
        n = len(s)
        if n & 1:
            return False
        x = 0
        for i in range(n):
            if s[i] == '(' or locked[i] == '0':
                x += 1
            elif x:
                x -= 1
            else:
                return False
        x = 0
        for i in range(n - 1, -1, -1):
            if s[i] == ')' or locked[i] == '0':
                x += 1
            elif x:
                x -= 1
            else:
                return False
        return True
```

#### Java

```java
class Solution {
    public boolean canBeValid(String s, String locked) {
        int n = s.length();
        if (n % 2 == 1) {
            return false;
        }
        int x = 0;
        for (int i = 0; i < n; ++i) {
            if (s.charAt(i) == '(' || locked.charAt(i) == '0') {
                ++x;
            } else if (x > 0) {
                --x;
            } else {
                return false;
            }
        }
        x = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s.charAt(i) == ')' || locked.charAt(i) == '0') {
                ++x;
            } else if (x > 0) {
                --x;
            } else {
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
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n & 1) {
            return false;
        }
        int x = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(' || locked[i] == '0') {
                ++x;
            } else if (x) {
                --x;
            } else {
                return false;
            }
        }
        x = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == ')' || locked[i] == '0') {
                ++x;
            } else if (x) {
                --x;
            } else {
                return false;
            }
        }
        return true;
    }
};
```

#### Go

```go
func canBeValid(s string, locked string) bool {
	n := len(s)
	if n%2 == 1 {
		return false
	}
	x := 0
	for i := range s {
		if s[i] == '(' || locked[i] == '0' {
			x++
		} else if x > 0 {
			x--
		} else {
			return false
		}
	}
	x = 0
	for i := n - 1; i >= 0; i-- {
		if s[i] == ')' || locked[i] == '0' {
			x++
		} else if x > 0 {
			x--
		} else {
			return false
		}
	}
	return true
}
```

#### TypeScript

```ts
function canBeValid(s: string, locked: string): boolean {
    const n = s.length;
    if (n & 1) {
        return false;
    }
    let x = 0;
    for (let i = 0; i < n; ++i) {
        if (s[i] === '(' || locked[i] === '0') {
            ++x;
        } else if (x > 0) {
            --x;
        } else {
            return false;
        }
    }
    x = 0;
    for (let i = n - 1; i >= 0; --i) {
        if (s[i] === ')' || locked[i] === '0') {
            ++x;
        } else if (x > 0) {
            --x;
        } else {
            return false;
        }
    }
    return true;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2117. 一个区间内所有数乘积的缩写](https://leetcode.cn/problems/abbreviating-the-product-of-a-range){#2117}

{{< tabs "2117" >}}

{{% tab "python" %}}
```python
class Solution:
    def abbreviateProduct(self, left: int, right: int) -> str:
        cnt2 = cnt5 = 0
        for x in range(left, right + 1):
            while x % 2 == 0:
                cnt2 += 1
                x //= 2
            while x % 5 == 0:
                cnt5 += 1
                x //= 5
        c = cnt2 = cnt5 = min(cnt2, cnt5)
        pre = suf = 1
        gt = False
        for x in range(left, right + 1):
            suf *= x
            while cnt2 and suf % 2 == 0:
                suf //= 2
                cnt2 -= 1
            while cnt5 and suf % 5 == 0:
                suf //= 5
                cnt5 -= 1
            if suf >= 1e10:
                gt = True
                suf %= int(1e10)
            pre *= x
            while pre > 1e5:
                pre /= 10
        if gt:
            return str(int(pre)) + "..." + str(suf % int(1e5)).zfill(5) + "e" + str(c)
        return str(suf) + "e" + str(c)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {

    public String abbreviateProduct(int left, int right) {
        int cnt2 = 0, cnt5 = 0;
        for (int i = left; i <= right; ++i) {
            int x = i;
            for (; x % 2 == 0; x /= 2) {
                ++cnt2;
            }
            for (; x % 5 == 0; x /= 5) {
                ++cnt5;
            }
        }
        int c = Math.min(cnt2, cnt5);
        cnt2 = cnt5 = c;
        long suf = 1;
        double pre = 1;
        boolean gt = false;
        for (int i = left; i <= right; ++i) {
            for (suf *= i; cnt2 > 0 && suf % 2 == 0; suf /= 2) {
                --cnt2;
            }
            for (; cnt5 > 0 && suf % 5 == 0; suf /= 5) {
                --cnt5;
            }
            if (suf >= (long) 1e10) {
                gt = true;
                suf %= (long) 1e10;
            }
            for (pre *= i; pre > 1e5; pre /= 10) {
            }
        }
        if (gt) {
            return (int) pre + "..." + String.format("%05d", suf % (int) 1e5) + "e" + c;
        }
        return suf + "e" + c;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string abbreviateProduct(int left, int right) {
        int cnt2 = 0, cnt5 = 0;
        for (int i = left; i <= right; ++i) {
            int x = i;
            for (; x % 2 == 0; x /= 2) {
                ++cnt2;
            }
            for (; x % 5 == 0; x /= 5) {
                ++cnt5;
            }
        }
        int c = min(cnt2, cnt5);
        cnt2 = cnt5 = c;
        long long suf = 1;
        long double pre = 1;
        bool gt = false;
        for (int i = left; i <= right; ++i) {
            for (suf *= i; cnt2 && suf % 2 == 0; suf /= 2) {
                --cnt2;
            }
            for (; cnt5 && suf % 5 == 0; suf /= 5) {
                --cnt5;
            }
            if (suf >= 1e10) {
                gt = true;
                suf %= (long long) 1e10;
            }
            for (pre *= i; pre > 1e5; pre /= 10) {
            }
        }
        if (gt) {
            char buf[10];
            snprintf(buf, sizeof(buf), "%0*lld", 5, suf % (int) 1e5);
            return to_string((int) pre) + "..." + string(buf) + "e" + to_string(c);
        }
        return to_string(suf) + "e" + to_string(c);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func abbreviateProduct(left int, right int) string {
	cnt2, cnt5 := 0, 0
	for i := left; i <= right; i++ {
		x := i
		for x%2 == 0 {
			cnt2++
			x /= 2
		}
		for x%5 == 0 {
			cnt5++
			x /= 5
		}
	}
	c := int(math.Min(float64(cnt2), float64(cnt5)))
	cnt2 = c
	cnt5 = c
	suf := int64(1)
	pre := float64(1)
	gt := false
	for i := left; i <= right; i++ {
		for suf *= int64(i); cnt2 > 0 && suf%2 == 0; {
			cnt2--
			suf /= int64(2)
		}
		for cnt5 > 0 && suf%5 == 0 {
			cnt5--
			suf /= int64(5)
		}
		if float64(suf) >= 1e10 {
			gt = true
			suf %= int64(1e10)
		}
		for pre *= float64(i); pre > 1e5; {
			pre /= 10
		}
	}
	if gt {
		return fmt.Sprintf("%05d...%05de%d", int(pre), int(suf)%int(1e5), c)
	}
	return fmt.Sprintf("%de%d", suf, c)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个正整数&nbsp;<code>left</code>&nbsp;和&nbsp;<code>right</code>&nbsp;，满足&nbsp;<code>left &lt;= right</code>&nbsp;。请你计算&nbsp;<strong>闭区间</strong>&nbsp;<code>[left, right]</code>&nbsp;中所有整数的&nbsp;<strong>乘积</strong>&nbsp;。</p>

<p>由于乘积可能非常大，你需要将它按照以下步骤 <strong>缩写</strong>&nbsp;：</p>

<ol>
	<li>统计乘积中&nbsp;<strong>后缀</strong> 0 的数目，并 <strong>移除</strong> 这些 0 ，将这个数目记为&nbsp;<code>C</code>&nbsp;。

    <ul>
    	<li>比方说，<code>1000</code>&nbsp;中有 <code>3</code> 个后缀 0&nbsp;，<code>546</code>&nbsp;中没有后缀 0 。</li>
    </ul>
    </li>
    <li>将乘积中剩余数字的位数记为&nbsp;<code>d</code>&nbsp;。如果&nbsp;<code>d &gt; 10</code>&nbsp;，那么将乘积表示为&nbsp;<code>&lt;pre&gt;...&lt;suf&gt;</code>&nbsp;的形式，其中&nbsp;<code>&lt;pre&gt;</code>&nbsp;表示乘积最 <strong>开始</strong>&nbsp;的 <code>5</code>&nbsp;个数位，<code>&lt;suf&gt;</code>&nbsp;表示删除后缀 0 <strong>之后</strong>&nbsp;结尾的 <code>5</code>&nbsp;个数位。如果&nbsp;<code>d &lt;= 10</code>&nbsp;，我们不对它做修改。
    <ul>
    	<li>比方说，我们将&nbsp;<code>1234567654321</code>&nbsp;表示为&nbsp;<code>12345...54321</code>&nbsp;，但是&nbsp;<code>1234567</code>&nbsp;仍然表示为&nbsp;<code>1234567</code>&nbsp;。</li>
    </ul>
    </li>
    <li>最后，将乘积表示为 <strong>字符串</strong>&nbsp;<code>"&lt;pre&gt;...&lt;suf&gt;eC"</code>&nbsp;。
    <ul>
    	<li>比方说，<code>12345678987600000</code>&nbsp;被表示为&nbsp;<code>"12345...89876e5"</code>&nbsp;。</li>
    </ul>
    </li>

</ol>

<p>请你返回一个字符串，表示 <strong>闭区间</strong>&nbsp;<code>[left, right]</code>&nbsp;中所有整数&nbsp;<strong>乘积</strong>&nbsp;的&nbsp;<strong>缩写</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>left = 1, right = 4
<b>输出：</b>"24e0"
<strong>解释：</strong>
乘积为 1 × 2 × 3 × 4 = 24 。
由于没有后缀 0 ，所以 24 保持不变，缩写的结尾为 "e0" 。
因为乘积的结果是 2 位数，小于 10 ，所欲我们不进一步将它缩写。
所以，最终将乘积表示为 "24e0" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>left = 2, right = 11
<strong>输出：</strong>"399168e2"
<strong>解释：</strong>乘积为 39916800 。
有 2 个后缀 0 ，删除后得到 399168 。缩写的结尾为 "e2" 。 
删除后缀 0 后是 6 位数，不需要进一步缩写。 
所以，最终将乘积表示为 "399168e2" 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>left = 371, right = 375
<strong>输出：</strong>"7219856259e3"
<strong>解释：</strong>乘积为 7219856259000 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= left &lt;= right &lt;= 10<sup>4</sup></code></li>
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
    def abbreviateProduct(self, left: int, right: int) -> str:
        cnt2 = cnt5 = 0
        for x in range(left, right + 1):
            while x % 2 == 0:
                cnt2 += 1
                x //= 2
            while x % 5 == 0:
                cnt5 += 1
                x //= 5
        c = cnt2 = cnt5 = min(cnt2, cnt5)
        pre = suf = 1
        gt = False
        for x in range(left, right + 1):
            suf *= x
            while cnt2 and suf % 2 == 0:
                suf //= 2
                cnt2 -= 1
            while cnt5 and suf % 5 == 0:
                suf //= 5
                cnt5 -= 1
            if suf >= 1e10:
                gt = True
                suf %= int(1e10)
            pre *= x
            while pre > 1e5:
                pre /= 10
        if gt:
            return str(int(pre)) + "..." + str(suf % int(1e5)).zfill(5) + "e" + str(c)
        return str(suf) + "e" + str(c)
```

#### Java

```java
class Solution {

    public String abbreviateProduct(int left, int right) {
        int cnt2 = 0, cnt5 = 0;
        for (int i = left; i <= right; ++i) {
            int x = i;
            for (; x % 2 == 0; x /= 2) {
                ++cnt2;
            }
            for (; x % 5 == 0; x /= 5) {
                ++cnt5;
            }
        }
        int c = Math.min(cnt2, cnt5);
        cnt2 = cnt5 = c;
        long suf = 1;
        double pre = 1;
        boolean gt = false;
        for (int i = left; i <= right; ++i) {
            for (suf *= i; cnt2 > 0 && suf % 2 == 0; suf /= 2) {
                --cnt2;
            }
            for (; cnt5 > 0 && suf % 5 == 0; suf /= 5) {
                --cnt5;
            }
            if (suf >= (long) 1e10) {
                gt = true;
                suf %= (long) 1e10;
            }
            for (pre *= i; pre > 1e5; pre /= 10) {
            }
        }
        if (gt) {
            return (int) pre + "..." + String.format("%05d", suf % (int) 1e5) + "e" + c;
        }
        return suf + "e" + c;
    }
}
```

#### C++

```cpp
class Solution {
public:
    string abbreviateProduct(int left, int right) {
        int cnt2 = 0, cnt5 = 0;
        for (int i = left; i <= right; ++i) {
            int x = i;
            for (; x % 2 == 0; x /= 2) {
                ++cnt2;
            }
            for (; x % 5 == 0; x /= 5) {
                ++cnt5;
            }
        }
        int c = min(cnt2, cnt5);
        cnt2 = cnt5 = c;
        long long suf = 1;
        long double pre = 1;
        bool gt = false;
        for (int i = left; i <= right; ++i) {
            for (suf *= i; cnt2 && suf % 2 == 0; suf /= 2) {
                --cnt2;
            }
            for (; cnt5 && suf % 5 == 0; suf /= 5) {
                --cnt5;
            }
            if (suf >= 1e10) {
                gt = true;
                suf %= (long long) 1e10;
            }
            for (pre *= i; pre > 1e5; pre /= 10) {
            }
        }
        if (gt) {
            char buf[10];
            snprintf(buf, sizeof(buf), "%0*lld", 5, suf % (int) 1e5);
            return to_string((int) pre) + "..." + string(buf) + "e" + to_string(c);
        }
        return to_string(suf) + "e" + to_string(c);
    }
};
```

#### Go

```go
func abbreviateProduct(left int, right int) string {
	cnt2, cnt5 := 0, 0
	for i := left; i <= right; i++ {
		x := i
		for x%2 == 0 {
			cnt2++
			x /= 2
		}
		for x%5 == 0 {
			cnt5++
			x /= 5
		}
	}
	c := int(math.Min(float64(cnt2), float64(cnt5)))
	cnt2 = c
	cnt5 = c
	suf := int64(1)
	pre := float64(1)
	gt := false
	for i := left; i <= right; i++ {
		for suf *= int64(i); cnt2 > 0 && suf%2 == 0; {
			cnt2--
			suf /= int64(2)
		}
		for cnt5 > 0 && suf%5 == 0 {
			cnt5--
			suf /= int64(5)
		}
		if float64(suf) >= 1e10 {
			gt = true
			suf %= int64(1e10)
		}
		for pre *= float64(i); pre > 1e5; {
			pre /= 10
		}
	}
	if gt {
		return fmt.Sprintf("%05d...%05de%d", int(pre), int(suf)%int(1e5), c)
	}
	return fmt.Sprintf("%de%d", suf, c)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2118. 建立方程 🔒](https://leetcode.cn/problems/build-the-equation){#2118}

{{< tabs "2118" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            power,
            CASE power
                WHEN 0 THEN IF(factor > 0, CONCAT('+', factor), factor)
                WHEN 1 THEN CONCAT(
                    IF(factor > 0, CONCAT('+', factor), factor),
                    'X'
                )
                ELSE CONCAT(
                    IF(factor > 0, CONCAT('+', factor), factor),
                    'X^',
                    power
                )
            END AS it
        FROM Terms
    )
SELECT
    CONCAT(GROUP_CONCAT(it ORDER BY power DESC SEPARATOR ""), '=0') AS equation
FROM T;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Terms</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| power       | int  |
| factor      | int  |
+-------------+------+
power 是该表具有唯一值的列。
该表的每一行包含关于方程的一项的信息。
power 是范围为 [0, 100] 的整数。
factor 是范围为 [-100,100] 的整数，且不能为零。
</pre>

<p>&nbsp;</p>

<p>你有一个非常强大的程序，可以解决世界上任何单变量的方程。传递给程序的方程必须格式化如下:</p>

<ul>
	<li>左边 (LHS) 应该包含所有的术语。</li>
	<li>右边 (RHS) 应该是零。</li>
	<li>LHS 的每一项应遵循 <code>"&lt;sign&gt;&lt;fact&gt;X^&lt;pow&gt;"</code>&nbsp;的格式，其中:
	<ul>
		<li><code>&lt;sign&gt;</code> 是 <code>"+"</code> 或者&nbsp;<code>"-"</code>。</li>
		<li><code>&lt;fact&gt;</code>&nbsp;是&nbsp;<code>factor</code>&nbsp;的 <strong>绝对值</strong>。</li>
		<li><code>&lt;pow&gt;</code> 是 <code>power</code>&nbsp;的值。</li>
	</ul>
	</li>
	<li>如果幂是 <code>1</code>, 不要加上&nbsp;<code>"^&lt;pow&gt;"</code>.
	<ul>
		<li>例如, 如果&nbsp;<code>power = 1</code> 并且&nbsp;<code>factor = 3</code>, 将有 <code>"+3X"</code>。</li>
	</ul>
	</li>
	<li>如果幂是 <code>0</code>,&nbsp;不要加上&nbsp;<code>"X"</code> 和&nbsp;<code>"^&lt;pow&gt;"</code>.
	<ul>
		<li>例如, 如果&nbsp;<code>power = 0</code> 并且&nbsp;<code>factor = -3</code>, 将有 <code>"-3"</code>。</li>
	</ul>
	</li>
	<li>LHS 中的幂应该按 <strong>降序排序</strong>。</li>
</ul>

<p data-group="1-1">编写一个解决方案来构建方程。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
Terms 表:
+-------+--------+
| power | factor |
+-------+--------+
| 2     | 1      |
| 1     | -4     |
| 0     | 2      |
+-------+--------+
<strong>输出:</strong> 
+--------------+
| equation     |
+--------------+
| +1X^2-4X+2=0 |
+--------------+
</pre>

<p><strong>示例&nbsp;2：</strong></p>

<pre>
<strong>输入:</strong> 
Terms 表:
+-------+--------+
| power | factor |
+-------+--------+
| 4     | -4     |
| 2     | 1      |
| 1     | -1     |
+-------+--------+
<strong>输出:</strong> 
+-----------------+
| equation        |
+-----------------+
| -4X^4+1X^2-1X=0 |
+-----------------+
</pre>

<p>&nbsp;</p>

<p><strong>扩展:</strong> 如果幂函数不是主键，但每个幂函数在答案中都是唯一的，那么解决方案中需要改变什么?</p>

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
            power,
            CASE power
                WHEN 0 THEN IF(factor > 0, CONCAT('+', factor), factor)
                WHEN 1 THEN CONCAT(
                    IF(factor > 0, CONCAT('+', factor), factor),
                    'X'
                )
                ELSE CONCAT(
                    IF(factor > 0, CONCAT('+', factor), factor),
                    'X^',
                    power
                )
            END AS it
        FROM Terms
    )
SELECT
    CONCAT(GROUP_CONCAT(it ORDER BY power DESC SEPARATOR ""), '=0') AS equation
FROM T;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2119. 反转两次的数字](https://leetcode.cn/problems/a-number-after-a-double-reversal){#2119}

{{< tabs "2119" >}}

{{% tab "python" %}}
```python
class Solution:
    def isSameAfterReversals(self, num: int) -> bool:
        return num == 0 or num % 10 != 0
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isSameAfterReversals(int num) {
        return num == 0 || num % 10 != 0;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool isSameAfterReversals(int num) {
        return num == 0 || num % 10 != 0;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isSameAfterReversals(num int) bool {
	return num == 0 || num%10 != 0
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isSameAfterReversals(num: number): boolean {
    return num === 0 || num % 10 !== 0;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn is_same_after_reversals(num: i32) -> bool {
        num == 0 || num % 10 != 0
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} num
 * @return {boolean}
 */
var isSameAfterReversals = function (num) {
    return num === 0 || num % 10 !== 0;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><strong>反转</strong> 一个整数意味着倒置它的所有位。</p>

<ul>
	<li>例如，反转 <code>2021</code> 得到 <code>1202</code> 。反转 <code>12300</code> 得到 <code>321</code> ，<strong>不保留前导零</strong> 。</li>
</ul>

<p>给你一个整数 <code>num</code> ，<strong>反转</strong> <code>num</code> 得到 <code>reversed1</code> ，<strong>接着反转</strong> <code>reversed1</code> 得到 <code>reversed2</code> 。如果 <code>reversed2</code> 等于 <code>num</code> ，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>num = 526
<strong>输出：</strong>true
<strong>解释：</strong>反转 num 得到 625 ，接着反转 625 得到 526 ，等于 num 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>num = 1800
<strong>输出：</strong>false
<strong>解释：</strong>反转 num 得到 81 ，接着反转 81 得到 18 ，不等于 num 。 </pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>num = 0
<strong>输出：</strong>true
<strong>解释：</strong>反转 num 得到 0 ，接着反转 0 得到 0 ，等于 num 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= num &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学

如果数字是 $0$，或者数字的个位不是 $0$，那么反转两次后的数字一定和原数字相等。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isSameAfterReversals(self, num: int) -> bool:
        return num == 0 or num % 10 != 0
```

#### Java

```java
class Solution {
    public boolean isSameAfterReversals(int num) {
        return num == 0 || num % 10 != 0;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool isSameAfterReversals(int num) {
        return num == 0 || num % 10 != 0;
    }
};
```

#### Go

```go
func isSameAfterReversals(num int) bool {
	return num == 0 || num%10 != 0
}
```

#### TypeScript

```ts
function isSameAfterReversals(num: number): boolean {
    return num === 0 || num % 10 !== 0;
}
```

#### Rust

```rust
impl Solution {
    pub fn is_same_after_reversals(num: i32) -> bool {
        num == 0 || num % 10 != 0
    }
}
```

#### JavaScript

```js
/**
 * @param {number} num
 * @return {boolean}
 */
var isSameAfterReversals = function (num) {
    return num === 0 || num % 10 !== 0;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
