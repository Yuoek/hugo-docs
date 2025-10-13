---
title: "3150_无效的推文 II 🔒"
date: 2025-10-08T18:40:09+08:00
weight: 6
tags: [二分查找, 二叉树, 位运算, 前缀和, 动态规划, 哈希表, 广度优先搜索, 数学, 数据库, 数组, 树, 深度优先搜索, 组合数学, 计数, 记忆化搜索]
---

{{< markmap >}}
### [3150_无效的推文 II 🔒](#3150)
#### [数据库](#3150)
### [3151_特殊数组 I](#3151)
#### [数组](#3151)
### [3152_特殊数组 II](#3152)
#### [数组](#3152)
#### [二分查找](#3152)
#### [前缀和](#3152)
### [3153_所有数对中数位差之和](#3153)
#### [数组](#3153)
#### [哈希表](#3153)
#### [数学](#3153)
#### [计数](#3153)
### [3154_到达第 K 级台阶的方案数](#3154)
#### [位运算](#3154)
#### [记忆化搜索](#3154)
#### [数学](#3154)
#### [动态规划](#3154)
#### [组合数学](#3154)
### [3155_可升级服务器的最大数量 🔒](#3155)
#### [数组](#3155)
#### [数学](#3155)
#### [二分查找](#3155)
### [3156_员工任务持续时间和并发任务 🔒](#3156)
#### [数据库](#3156)
### [3157_找到具有最小和的树的层数 🔒](#3157)
#### [树](#3157)
#### [深度优先搜索](#3157)
#### [广度优先搜索](#3157)
#### [二叉树](#3157)
### [3158_求出出现两次数字的 XOR 值](#3158)
#### [位运算](#3158)
#### [数组](#3158)
#### [哈希表](#3158)
### [3159_查询数组中元素的出现位置](#3159)
#### [数组](#3159)
#### [哈希表](#3159)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 3150_无效的推文 II 🔒
___
#### 数据库
---
### 3151_特殊数组 I
___
#### 数组
---
### 3152_特殊数组 II
___
#### 数组
___
#### 二分查找
___
#### 前缀和
---
### 3153_所有数对中数位差之和
___
#### 数组
___
#### 哈希表
___
#### 数学
___
#### 计数
---
### 3154_到达第 K 级台阶的方案数
___
#### 位运算
___
#### 记忆化搜索
___
#### 数学
___
#### 动态规划
___
#### 组合数学
---
### 3155_可升级服务器的最大数量 🔒
___
#### 数组
___
#### 数学
___
#### 二分查找
---
### 3156_员工任务持续时间和并发任务 🔒
___
#### 数据库
---
### 3157_找到具有最小和的树的层数 🔒
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 二叉树
---
### 3158_求出出现两次数字的 XOR 值
___
#### 位运算
___
#### 数组
___
#### 哈希表
---
### 3159_查询数组中元素的出现位置
___
#### 数组
___
#### 哈希表
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉树 | 位运算 |
| 前缀和 | 动态规划 | 哈希表 |
| 广度优先搜索 | 数学 | 数据库 |
| 数组 | 树 | 深度优先搜索 |
| 组合数学 | 计数 | 记忆化搜索 |

# [3150. 无效的推文 II 🔒](https://leetcode.cn/problems/invalid-tweets-ii){#3150}

{{< tabs "3150" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT tweet_id
FROM Tweets
WHERE
    LENGTH(content) > 140
    OR (LENGTH(content) - LENGTH(REPLACE(content, '@', ''))) > 3
    OR (LENGTH(content) - LENGTH(REPLACE(content, '#', ''))) > 3
ORDER BY 1;
```
{{% /tab %}}
{{% tab "python" %}}
```python
import pandas as pd


def find_invalid_tweets(tweets: pd.DataFrame) -> pd.DataFrame:
    invalid_tweets = tweets[
        (tweets["content"].str.len() > 140)
        | (tweets["content"].str.count("@") > 3)
        | (tweets["content"].str.count("#") > 3)
    ].sort_values(by="tweet_id")
    return invalid_tweets[["tweet_id"]]
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Tweets</code></p>

<pre>
+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| tweet_id       | int     |
| content        | varchar |
+----------------+---------+
tweet_id 是这个表的主键（有不同值的列）。
这个表包含某社交媒体 App 中所有的推文。</pre>

<p>编写一个解决方案来找到 <strong>无效的推文</strong>。如果一条推文满足下面 <strong>任一</strong>&nbsp;条件会被认为无效：</p>

<ul>
	<li>长度超过&nbsp;<code>140</code>&nbsp;个字符。</li>
	<li>有超过&nbsp;<code>3</code>&nbsp;次提及。</li>
	<li>有超过&nbsp;<code><font face="monospace">3</font></code>&nbsp;个标签。</li>
</ul>

<p>以&nbsp;<code>tweet_id</code> <em><strong>升序</strong>&nbsp;</em>返回结果表。</p>

<p>查询结果格式如下所示：</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<div class="example-block">
<p><b>输入：</b></p>

<p>Tweets 表：</p>

<pre class="example-io">
  +----------+-----------------------------------------------------------------------------------+
  | tweet_id | content                                                                           |
  +----------+-----------------------------------------------------------------------------------+
  | 1        | Traveling, exploring, and living my best life @JaneSmith @SaraJohnson @LisaTaylor |
  |          | @MikeBrown #Foodie #Fitness #Learning                                             | 
  | 2        | Just had the best dinner with friends! #Foodie #Friends #Fun                      |
  | 4        | Working hard on my new project #Work #Goals #Productivity #Fun                    |
  +----------+-----------------------------------------------------------------------------------+
  </pre>

<p><strong>输出：</strong></p>

<pre class="example-io">
  +----------+
  | tweet_id |
  +----------+
  | 1        |
  | 4        |
  +----------+
  </pre>

<p><strong>解释：</strong></p>

<ul>
	<li>tweet_id&nbsp;1 包含 4&nbsp;次提及。</li>
	<li>tweet_id 4 包含 4 个标签。</li>
</ul>
输出表以 tweet_id 升序排序。</div>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：LENGTH() 函数 + REPLACE() 函数

我们可以使用 `LENGTH()` 函数计算字符串的长度，计算排除掉 `@` 或 `#` 之后的长度，然后使用 `OR` 运算符连接这三个条件，筛选出对应的 tweet_id，并按照 tweet_id 升序排序。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT tweet_id
FROM Tweets
WHERE
    LENGTH(content) > 140
    OR (LENGTH(content) - LENGTH(REPLACE(content, '@', ''))) > 3
    OR (LENGTH(content) - LENGTH(REPLACE(content, '#', ''))) > 3
ORDER BY 1;
```

#### Python3

```python
import pandas as pd


def find_invalid_tweets(tweets: pd.DataFrame) -> pd.DataFrame:
    invalid_tweets = tweets[
        (tweets["content"].str.len() > 140)
        | (tweets["content"].str.count("@") > 3)
        | (tweets["content"].str.count("#") > 3)
    ].sort_values(by="tweet_id")
    return invalid_tweets[["tweet_id"]]
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3151. 特殊数组 I](https://leetcode.cn/problems/special-array-i){#3151}

{{< tabs "3151" >}}

{{% tab "python" %}}
```python
class Solution:
    def isArraySpecial(self, nums: List[int]) -> bool:
        return all(a % 2 != b % 2 for a, b in pairwise(nums))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isArraySpecial(int[] nums) {
        for (int i = 1; i < nums.length; ++i) {
            if (nums[i] % 2 == nums[i - 1] % 2) {
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
    bool isArraySpecial(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] % 2 == nums[i - 1] % 2) {
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
func isArraySpecial(nums []int) bool {
	for i, x := range nums[1:] {
		if x%2 == nums[i]%2 {
			return false
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isArraySpecial(nums: number[]): boolean {
    for (let i = 1; i < nums.length; ++i) {
        if (nums[i] % 2 === nums[i - 1] % 2) {
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

<p>如果数组的每一对相邻元素都是两个奇偶性不同的数字，则该数组被认为是一个 <strong>特殊数组</strong>。换句话说，每一对中的元素 <strong>必须</strong> 有一个是偶数，另一个是奇数。</p>

<p>你有一个整数数组 <code>nums</code>。如果 <code>nums</code> 是一个 <strong>特殊数组</strong> ，返回 <code>true</code>，否则返回 <code>false</code>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [1]</span></p>

<p><strong>输出：</strong><span class="example-io">true</span></p>

<p><strong>解释：</strong></p>

<p>只有一个元素，所以答案为 <code>true</code>。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [2,1,4]</span></p>

<p><strong>输出：</strong><span class="example-io">true</span></p>

<p><strong>解释：</strong></p>

<p>只有两对相邻元素： <code>(2,1)</code> 和 <code>(1,4)</code>，它们都包含了奇偶性不同的数字，因此答案为 <code>true</code>。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [4,3,1,6]</span></p>

<p><strong>输出：</strong><span class="example-io">false</span></p>

<p><strong>解释：</strong></p>

<p><code>nums[1]</code> 和 <code>nums[2]</code> 都是奇数。因此答案为 <code>false</code>。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：一次遍历

我们从左到右遍历数组，对于每一对相邻元素，如果它们的奇偶性相同，那么数组就不是特殊数组，返回 `false`；否则，数组是特殊数组，返回 `true`。

时间复杂度 $O(n)$，其中 $n$ 是数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isArraySpecial(self, nums: List[int]) -> bool:
        return all(a % 2 != b % 2 for a, b in pairwise(nums))
```

#### Java

```java
class Solution {
    public boolean isArraySpecial(int[] nums) {
        for (int i = 1; i < nums.length; ++i) {
            if (nums[i] % 2 == nums[i - 1] % 2) {
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
    bool isArraySpecial(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] % 2 == nums[i - 1] % 2) {
                return false;
            }
        }
        return true;
    }
};
```

#### Go

```go
func isArraySpecial(nums []int) bool {
	for i, x := range nums[1:] {
		if x%2 == nums[i]%2 {
			return false
		}
	}
	return true
}
```

#### TypeScript

```ts
function isArraySpecial(nums: number[]): boolean {
    for (let i = 1; i < nums.length; ++i) {
        if (nums[i] % 2 === nums[i - 1] % 2) {
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

# [3152. 特殊数组 II](https://leetcode.cn/problems/special-array-ii){#3152}

{{< tabs "3152" >}}

{{% tab "python" %}}
```python
class Solution:
    def isArraySpecial(self, nums: List[int], queries: List[List[int]]) -> List[bool]:
        n = len(nums)
        d = list(range(n))
        for i in range(1, n):
            if nums[i] % 2 != nums[i - 1] % 2:
                d[i] = d[i - 1]
        return [d[t] <= f for f, t in queries]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean[] isArraySpecial(int[] nums, int[][] queries) {
        int n = nums.length;
        int[] d = new int[n];
        for (int i = 1; i < n; ++i) {
            if (nums[i] % 2 != nums[i - 1] % 2) {
                d[i] = d[i - 1];
            } else {
                d[i] = i;
            }
        }
        int m = queries.length;
        boolean[] ans = new boolean[m];
        for (int i = 0; i < m; ++i) {
            ans[i] = d[queries[i][1]] <= queries[i][0];
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
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> d(n);
        iota(d.begin(), d.end(), 0);
        for (int i = 1; i < n; ++i) {
            if (nums[i] % 2 != nums[i - 1] % 2) {
                d[i] = d[i - 1];
            }
        }
        vector<bool> ans;
        for (auto& q : queries) {
            ans.push_back(d[q[1]] <= q[0]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isArraySpecial(nums []int, queries [][]int) (ans []bool) {
	n := len(nums)
	d := make([]int, n)
	for i := range d {
		d[i] = i
	}
	for i := 1; i < len(nums); i++ {
		if nums[i]%2 != nums[i-1]%2 {
			d[i] = d[i-1]
		}
	}
	for _, q := range queries {
		ans = append(ans, d[q[1]] <= q[0])
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isArraySpecial(nums: number[], queries: number[][]): boolean[] {
    const n = nums.length;
    const d: number[] = Array.from({ length: n }, (_, i) => i);
    for (let i = 1; i < n; ++i) {
        if (nums[i] % 2 !== nums[i - 1] % 2) {
            d[i] = d[i - 1];
        }
    }
    return queries.map(([from, to]) => d[to] <= from);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>如果数组的每一对相邻元素都是两个奇偶性不同的数字，则该数组被认为是一个 <strong>特殊数组</strong> 。</p>

<p>你有一个整数数组 <code>nums</code> 和一个二维整数矩阵 <code>queries</code>，对于 <code>queries[i] = [from<sub>i</sub>, to<sub>i</sub>]</code>，请你帮助你检查 <span data-keyword="subarray">子数组</span> <code>nums[from<sub>i</sub>..to<sub>i</sub>]</code> 是不是一个 <strong>特殊数组 </strong>。</p>

<p>返回布尔数组 <code>answer</code>，如果 <code>nums[from<sub>i</sub>..to<sub>i</sub>]</code> 是特殊数组，则 <code>answer[i]</code> 为 <code>true</code> ，否则，<code>answer[i]</code> 为 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [3,4,1,2,6], queries = [[0,4]]</span></p>

<p><strong>输出：</strong><span class="example-io">[false]</span></p>

<p><strong>解释：</strong></p>

<p>子数组是 <code>[3,4,1,2,6]</code>。2 和 6 都是偶数。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [4,3,1,6], queries = [[0,2],[2,3]]</span></p>

<p><strong>输出：</strong><span class="example-io">[false,true]</span></p>

<p><strong>解释：</strong></p>

<ol>
	<li>子数组是 <code>[4,3,1]</code>。3 和 1 都是奇数。因此这个查询的答案是 <code>false</code>。</li>
	<li>子数组是 <code>[1,6]</code>。只有一对：<code>(1,6)</code>，且包含了奇偶性不同的数字。因此这个查询的答案是 <code>true</code>。</li>
</ol>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>queries[i].length == 2</code></li>
	<li><code>0 &lt;= queries[i][0] &lt;= queries[i][1] &lt;= nums.length - 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记录每个位置的最左特殊数组位置

我们可以定义一个数组 $d$ 来记录每个位置的最左特殊数组位置，初始时 $d[i] = i$。然后我们从左到右遍历数组 $nums$，如果 $nums[i]$ 和 $nums[i - 1]$ 的奇偶性不同，那么 $d[i] = d[i - 1]$。

最后我们遍历每个查询，判断 $d[to] <= from$ 是否成立即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isArraySpecial(self, nums: List[int], queries: List[List[int]]) -> List[bool]:
        n = len(nums)
        d = list(range(n))
        for i in range(1, n):
            if nums[i] % 2 != nums[i - 1] % 2:
                d[i] = d[i - 1]
        return [d[t] <= f for f, t in queries]
```

#### Java

```java
class Solution {
    public boolean[] isArraySpecial(int[] nums, int[][] queries) {
        int n = nums.length;
        int[] d = new int[n];
        for (int i = 1; i < n; ++i) {
            if (nums[i] % 2 != nums[i - 1] % 2) {
                d[i] = d[i - 1];
            } else {
                d[i] = i;
            }
        }
        int m = queries.length;
        boolean[] ans = new boolean[m];
        for (int i = 0; i < m; ++i) {
            ans[i] = d[queries[i][1]] <= queries[i][0];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> d(n);
        iota(d.begin(), d.end(), 0);
        for (int i = 1; i < n; ++i) {
            if (nums[i] % 2 != nums[i - 1] % 2) {
                d[i] = d[i - 1];
            }
        }
        vector<bool> ans;
        for (auto& q : queries) {
            ans.push_back(d[q[1]] <= q[0]);
        }
        return ans;
    }
};
```

#### Go

```go
func isArraySpecial(nums []int, queries [][]int) (ans []bool) {
	n := len(nums)
	d := make([]int, n)
	for i := range d {
		d[i] = i
	}
	for i := 1; i < len(nums); i++ {
		if nums[i]%2 != nums[i-1]%2 {
			d[i] = d[i-1]
		}
	}
	for _, q := range queries {
		ans = append(ans, d[q[1]] <= q[0])
	}
	return
}
```

#### TypeScript

```ts
function isArraySpecial(nums: number[], queries: number[][]): boolean[] {
    const n = nums.length;
    const d: number[] = Array.from({ length: n }, (_, i) => i);
    for (let i = 1; i < n; ++i) {
        if (nums[i] % 2 !== nums[i - 1] % 2) {
            d[i] = d[i - 1];
        }
    }
    return queries.map(([from, to]) => d[to] <= from);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3153. 所有数对中数位差之和](https://leetcode.cn/problems/sum-of-digit-differences-of-all-pairs){#3153}

{{< tabs "3153" >}}

{{% tab "python" %}}
```python
class Solution:
    def sumDigitDifferences(self, nums: List[int]) -> int:
        n = len(nums)
        m = int(log10(nums[0])) + 1
        ans = 0
        for _ in range(m):
            cnt = Counter()
            for i, x in enumerate(nums):
                nums[i], y = divmod(x, 10)
                cnt[y] += 1
            ans += sum(v * (n - v) for v in cnt.values()) // 2
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long sumDigitDifferences(int[] nums) {
        int n = nums.length;
        int m = (int) Math.floor(Math.log10(nums[0])) + 1;
        int[] cnt = new int[10];
        long ans = 0;
        for (int k = 0; k < m; ++k) {
            Arrays.fill(cnt, 0);
            for (int i = 0; i < n; ++i) {
                ++cnt[nums[i] % 10];
                nums[i] /= 10;
            }
            for (int i = 0; i < 10; ++i) {
                ans += 1L * cnt[i] * (n - cnt[i]);
            }
        }
        return ans / 2;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int n = nums.size();
        int m = floor(log10(nums[0])) + 1;
        int cnt[10];
        long long ans = 0;
        for (int k = 0; k < m; ++k) {
            memset(cnt, 0, sizeof(cnt));
            for (int i = 0; i < n; ++i) {
                ++cnt[nums[i] % 10];
                nums[i] /= 10;
            }
            for (int i = 0; i < 10; ++i) {
                ans += 1LL * cnt[i] * (n - cnt[i]);
            }
        }
        return ans / 2;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sumDigitDifferences(nums []int) (ans int64) {
	n := len(nums)
	m := int(math.Floor(math.Log10(float64(nums[0])))) + 1
	for k := 0; k < m; k++ {
		cnt := [10]int{}
		for i, x := range nums {
			cnt[x%10]++
			nums[i] /= 10
		}
		for _, v := range cnt {
			ans += int64(v) * int64(n-v)
		}
	}
	ans /= 2
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function sumDigitDifferences(nums: number[]): number {
    const n = nums.length;
    const m = Math.floor(Math.log10(nums[0])) + 1;
    let ans: bigint = BigInt(0);
    for (let k = 0; k < m; ++k) {
        const cnt: number[] = Array(10).fill(0);
        for (let i = 0; i < n; ++i) {
            ++cnt[nums[i] % 10];
            nums[i] = Math.floor(nums[i] / 10);
        }
        for (let i = 0; i < 10; ++i) {
            ans += BigInt(cnt[i]) * BigInt(n - cnt[i]);
        }
    }
    ans /= BigInt(2);
    return Number(ans);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你有一个数组&nbsp;<code>nums</code>&nbsp;，它只包含 <strong>正</strong>&nbsp;整数，所有正整数的数位长度都 <strong>相同</strong>&nbsp;。</p>

<p>两个整数的 <strong>数位差</strong>&nbsp;指的是两个整数 <b>相同</b>&nbsp;位置上不同数字的数目。</p>

<p>请你返回 <code>nums</code>&nbsp;中 <strong>所有</strong>&nbsp;整数对里，<strong>数位差之和。</strong></p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [13,23,12]</span></p>

<p><b>输出：</b>4</p>

<p><strong>解释：</strong><br />
计算过程如下：<br />
-&nbsp;<strong>1</strong>3 和&nbsp;<strong>2</strong>3 的数位差为&nbsp;1 。<br />
- 1<strong>3</strong> 和 1<strong>2</strong>&nbsp;的数位差为&nbsp;1 。<br />
-&nbsp;<strong>23</strong> 和&nbsp;<strong>12</strong>&nbsp;的数位差为&nbsp;2 。<br />
所以所有整数数对的数位差之和为&nbsp;<code>1 + 1 + 2 = 4</code>&nbsp;。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [10,10,10,10]</span></p>

<p><span class="example-io"><b>输出：</b>0</span></p>

<p><strong>解释：</strong><br />
数组中所有整数都相同，所以所有整数数对的数位不同之和为 0 。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt; 10<sup>9</sup></code></li>
	<li><code>nums</code>&nbsp;中的整数都有相同的数位长度。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们先获取数组中数字的位数 $m$，然后对于每一位，我们统计数组 $\textit{nums}$ 中每个数字在该位上的出现次数，记为 $\textit{cnt}$。那么在该位上，所有数对的数位不同之和为：

$$
\sum_{v \in \textit{cnt}} v \times (n - v)
$$

其中 $n$ 是数组的长度。我们将所有位的数位不同之和相加，再除以 $2$ 即可得到答案。

时间复杂度 $O(n \times m)$，空间复杂度 $O(C)$，其中 $n$ 和 $m$ 分别是数组的长度和数字的位数；而 $C$ 是常数，本题中 $C = 10$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sumDigitDifferences(self, nums: List[int]) -> int:
        n = len(nums)
        m = int(log10(nums[0])) + 1
        ans = 0
        for _ in range(m):
            cnt = Counter()
            for i, x in enumerate(nums):
                nums[i], y = divmod(x, 10)
                cnt[y] += 1
            ans += sum(v * (n - v) for v in cnt.values()) // 2
        return ans
```

#### Java

```java
class Solution {
    public long sumDigitDifferences(int[] nums) {
        int n = nums.length;
        int m = (int) Math.floor(Math.log10(nums[0])) + 1;
        int[] cnt = new int[10];
        long ans = 0;
        for (int k = 0; k < m; ++k) {
            Arrays.fill(cnt, 0);
            for (int i = 0; i < n; ++i) {
                ++cnt[nums[i] % 10];
                nums[i] /= 10;
            }
            for (int i = 0; i < 10; ++i) {
                ans += 1L * cnt[i] * (n - cnt[i]);
            }
        }
        return ans / 2;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int n = nums.size();
        int m = floor(log10(nums[0])) + 1;
        int cnt[10];
        long long ans = 0;
        for (int k = 0; k < m; ++k) {
            memset(cnt, 0, sizeof(cnt));
            for (int i = 0; i < n; ++i) {
                ++cnt[nums[i] % 10];
                nums[i] /= 10;
            }
            for (int i = 0; i < 10; ++i) {
                ans += 1LL * cnt[i] * (n - cnt[i]);
            }
        }
        return ans / 2;
    }
};
```

#### Go

```go
func sumDigitDifferences(nums []int) (ans int64) {
	n := len(nums)
	m := int(math.Floor(math.Log10(float64(nums[0])))) + 1
	for k := 0; k < m; k++ {
		cnt := [10]int{}
		for i, x := range nums {
			cnt[x%10]++
			nums[i] /= 10
		}
		for _, v := range cnt {
			ans += int64(v) * int64(n-v)
		}
	}
	ans /= 2
	return
}
```

#### TypeScript

```ts
function sumDigitDifferences(nums: number[]): number {
    const n = nums.length;
    const m = Math.floor(Math.log10(nums[0])) + 1;
    let ans: bigint = BigInt(0);
    for (let k = 0; k < m; ++k) {
        const cnt: number[] = Array(10).fill(0);
        for (let i = 0; i < n; ++i) {
            ++cnt[nums[i] % 10];
            nums[i] = Math.floor(nums[i] / 10);
        }
        for (let i = 0; i < 10; ++i) {
            ans += BigInt(cnt[i]) * BigInt(n - cnt[i]);
        }
    }
    ans /= BigInt(2);
    return Number(ans);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3154. 到达第 K 级台阶的方案数](https://leetcode.cn/problems/find-number-of-ways-to-reach-the-k-th-stair){#3154}

{{< tabs "3154" >}}

{{% tab "python" %}}
```python
class Solution:
    def waysToReachStair(self, k: int) -> int:
        @cache
        def dfs(i: int, j: int, jump: int) -> int:
            if i > k + 1:
                return 0
            ans = int(i == k)
            if i > 0 and j == 0:
                ans += dfs(i - 1, 1, jump)
            ans += dfs(i + (1 << jump), 0, jump + 1)
            return ans

        return dfs(1, 0, 0)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private Map<Long, Integer> f = new HashMap<>();
    private int k;

    public int waysToReachStair(int k) {
        this.k = k;
        return dfs(1, 0, 0);
    }

    private int dfs(int i, int j, int jump) {
        if (i > k + 1) {
            return 0;
        }
        long key = ((long) i << 32) | jump << 1 | j;
        if (f.containsKey(key)) {
            return f.get(key);
        }
        int ans = i == k ? 1 : 0;
        if (i > 0 && j == 0) {
            ans += dfs(i - 1, 1, jump);
        }
        ans += dfs(i + (1 << jump), 0, jump + 1);
        f.put(key, ans);
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int waysToReachStair(int k) {
        unordered_map<long long, int> f;
        auto dfs = [&](this auto&& dfs, int i, int j, int jump) -> int {
            if (i > k + 1) {
                return 0;
            }
            long long key = ((long long) i << 32) | jump << 1 | j;
            if (f.contains(key)) {
                return f[key];
            }
            int ans = i == k ? 1 : 0;
            if (i > 0 && j == 0) {
                ans += dfs(i - 1, 1, jump);
            }
            ans += dfs(i + (1 << jump), 0, jump + 1);
            f[key] = ans;
            return ans;
        };
        return dfs(1, 0, 0);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func waysToReachStair(k int) int {
	f := map[int]int{}
	var dfs func(i, j, jump int) int
	dfs = func(i, j, jump int) int {
		if i > k+1 {
			return 0
		}
		key := (i << 32) | jump<<1 | j
		if v, has := f[key]; has {
			return v
		}
		ans := 0
		if i == k {
			ans++
		}
		if i > 0 && j == 0 {
			ans += dfs(i-1, 1, jump)
		}
		ans += dfs(i+(1<<jump), 0, jump+1)
		f[key] = ans
		return ans
	}
	return dfs(1, 0, 0)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function waysToReachStair(k: number): number {
    const f: Map<bigint, number> = new Map();

    const dfs = (i: number, j: number, jump: number): number => {
        if (i > k + 1) {
            return 0;
        }

        const key: bigint = (BigInt(i) << BigInt(32)) | BigInt(jump << 1) | BigInt(j);
        if (f.has(key)) {
            return f.get(key)!;
        }

        let ans: number = 0;
        if (i === k) {
            ans++;
        }

        if (i > 0 && j === 0) {
            ans += dfs(i - 1, 1, jump);
        }

        ans += dfs(i + (1 << jump), 0, jump + 1);
        f.set(key, ans);
        return ans;
    };

    return dfs(1, 0, 0);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你有一个 <strong>非负</strong>&nbsp;整数&nbsp;<code>k</code>&nbsp;。有一个无限长度的台阶，<strong>最低</strong>&nbsp;一层编号为 0 。</p>

<p>Alice&nbsp;有一个整数&nbsp;<code>jump</code>&nbsp;，一开始值为 0 。Alice 从台阶 1 开始，可以使用 <strong>任意</strong>&nbsp;次操作，目标是到达第&nbsp;<code>k</code> 级台阶。假设 Alice 位于台阶 <code>i</code> ，一次 <strong>操作</strong> 中，Alice 可以：</p>

<ul>
	<li>向下走一级到&nbsp;<code>i - 1</code>&nbsp;，但该操作&nbsp;<strong>不能</strong>&nbsp;连续使用，如果在台阶第 0 级也不能使用。</li>
	<li>向上走到台阶&nbsp;<code>i + 2<sup>jump</sup></code>&nbsp;处，然后&nbsp;<code>jump</code>&nbsp;变为&nbsp;<code>jump + 1</code>&nbsp;。</li>
</ul>

<p>请你返回 Alice 到达台阶 <code>k</code>&nbsp;处的总方案数。</p>

<p><b>注意</b>，Alice 可能到达台阶 <code>k</code>&nbsp;处后，通过一些操作重新回到台阶 <code>k</code>&nbsp;处，这视为不同的方案。</p>

<p>&nbsp;</p>

<p><b>示例 1：</b></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>k = 0</span></p>

<p><span class="example-io"><b>输出：</b>2</span></p>

<p><strong>解释：</strong></p>

<p>2 种到达台阶 0 的方案为：</p>

<ul>
	<li>Alice&nbsp;从台阶&nbsp;1 开始。
	<ul>
		<li>执行第一种操作，从台阶 1 向下走到台阶 0 。</li>
	</ul>
	</li>
	<li>Alice&nbsp;从台阶 1 开始。
	<ul>
		<li>执行第一种操作，从台阶 1 向下走到台阶 0 。</li>
		<li>执行第二种操作，向上走 2<sup>0</sup>&nbsp;级台阶到台阶 1 。</li>
		<li>执行第一种操作，从台阶 1 向下走到台阶 0 。</li>
	</ul>
	</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>k = 1</span></p>

<p><span class="example-io"><b>输出：</b>4</span></p>

<p><strong>解释：</strong></p>

<p>4 种到达台阶 1 的方案为：</p>

<ul>
	<li>Alice&nbsp;从台阶 1 开始，已经到达台阶 1 。</li>
	<li>Alice&nbsp;从台阶 1 开始。
	<ul>
		<li>执行第一种操作，从台阶 1 向下走到台阶 0 。</li>
		<li>执行第二种操作，向上走 2<sup>0</sup>&nbsp;级台阶到台阶 1 。</li>
	</ul>
	</li>
	<li>Alice&nbsp;从台阶 1 开始。
	<ul>
		<li>执行第二种操作，向上走 2<sup>0</sup>&nbsp;级台阶到台阶 2 。</li>
		<li>执行第一种操作，向下走 1 级台阶到台阶 1 。</li>
	</ul>
	</li>
	<li>Alice&nbsp;从台阶 1 开始。
	<ul>
		<li>执行第一种操作，从台阶 1 向下走到台阶 0 。</li>
		<li>执行第二种操作，向上走&nbsp;2<sup>0</sup>&nbsp;级台阶到台阶 1 。</li>
		<li>执行第一种操作，向下走 1 级台阶到台阶 0 。</li>
		<li>执行第二种操作，向上走 2<sup>1</sup>&nbsp;级台阶到台阶 2 。</li>
		<li>执行第一种操作，向下走&nbsp;1 级台阶到台阶 1 。</li>
	</ul>
	</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= k &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $\textit{dfs}(i, j, \textit{jump})$，表示当前位于第 $i$ 级台阶，且进行了 $j$ 次操作 $1$ 和 $\textit{jump}$ 次操作 $2$，到达第 $k$ 级台阶的方案数。那么答案就是 $\textit{dfs}(1, 0, 0)$。

函数 $\textit{dfs}(i, j, \textit{jump})$ 的计算过程如下：

-   如果 $i > k + 1$，由于无法连续两次向下走，所以无法再到达第 $k$ 级台阶，返回 $0$；
-   如果 $i = k$，表示已经到达第 $k$ 级台阶，答案初始化为 $1$，然后继续计算；
-   如果 $i > 0$ 且 $j = 0$，表示可以向下走，递归计算 $\textit{dfs}(i - 1, 1, \textit{jump})$；
-   递归计算 $\textit{dfs}(i + 2^{\textit{jump}}, 0, \textit{jump} + 1)$，累加到答案中。

为了避免重复计算，我们使用记忆化搜索，将已经计算过的状态保存起来。

时间复杂度 $(\log ^2 k)$，空间复杂度 $(\log ^2 k)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def waysToReachStair(self, k: int) -> int:
        @cache
        def dfs(i: int, j: int, jump: int) -> int:
            if i > k + 1:
                return 0
            ans = int(i == k)
            if i > 0 and j == 0:
                ans += dfs(i - 1, 1, jump)
            ans += dfs(i + (1 << jump), 0, jump + 1)
            return ans

        return dfs(1, 0, 0)
```

#### Java

```java
class Solution {
    private Map<Long, Integer> f = new HashMap<>();
    private int k;

    public int waysToReachStair(int k) {
        this.k = k;
        return dfs(1, 0, 0);
    }

    private int dfs(int i, int j, int jump) {
        if (i > k + 1) {
            return 0;
        }
        long key = ((long) i << 32) | jump << 1 | j;
        if (f.containsKey(key)) {
            return f.get(key);
        }
        int ans = i == k ? 1 : 0;
        if (i > 0 && j == 0) {
            ans += dfs(i - 1, 1, jump);
        }
        ans += dfs(i + (1 << jump), 0, jump + 1);
        f.put(key, ans);
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int waysToReachStair(int k) {
        unordered_map<long long, int> f;
        auto dfs = [&](this auto&& dfs, int i, int j, int jump) -> int {
            if (i > k + 1) {
                return 0;
            }
            long long key = ((long long) i << 32) | jump << 1 | j;
            if (f.contains(key)) {
                return f[key];
            }
            int ans = i == k ? 1 : 0;
            if (i > 0 && j == 0) {
                ans += dfs(i - 1, 1, jump);
            }
            ans += dfs(i + (1 << jump), 0, jump + 1);
            f[key] = ans;
            return ans;
        };
        return dfs(1, 0, 0);
    }
};
```

#### Go

```go
func waysToReachStair(k int) int {
	f := map[int]int{}
	var dfs func(i, j, jump int) int
	dfs = func(i, j, jump int) int {
		if i > k+1 {
			return 0
		}
		key := (i << 32) | jump<<1 | j
		if v, has := f[key]; has {
			return v
		}
		ans := 0
		if i == k {
			ans++
		}
		if i > 0 && j == 0 {
			ans += dfs(i-1, 1, jump)
		}
		ans += dfs(i+(1<<jump), 0, jump+1)
		f[key] = ans
		return ans
	}
	return dfs(1, 0, 0)
}
```

#### TypeScript

```ts
function waysToReachStair(k: number): number {
    const f: Map<bigint, number> = new Map();

    const dfs = (i: number, j: number, jump: number): number => {
        if (i > k + 1) {
            return 0;
        }

        const key: bigint = (BigInt(i) << BigInt(32)) | BigInt(jump << 1) | BigInt(j);
        if (f.has(key)) {
            return f.get(key)!;
        }

        let ans: number = 0;
        if (i === k) {
            ans++;
        }

        if (i > 0 && j === 0) {
            ans += dfs(i - 1, 1, jump);
        }

        ans += dfs(i + (1 << jump), 0, jump + 1);
        f.set(key, ans);
        return ans;
    };

    return dfs(1, 0, 0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3155. 可升级服务器的最大数量 🔒](https://leetcode.cn/problems/maximum-number-of-upgradable-servers){#3155}

{{< tabs "3155" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxUpgrades(
        self, count: List[int], upgrade: List[int], sell: List[int], money: List[int]
    ) -> List[int]:
        ans = []
        for cnt, cost, income, cash in zip(count, upgrade, sell, money):
            ans.append(min(cnt, (cnt * income + cash) // (cost + income)))
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] maxUpgrades(int[] count, int[] upgrade, int[] sell, int[] money) {
        int n = count.length;
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            ans[i] = Math.min(
                count[i], (int) ((1L * count[i] * sell[i] + money[i]) / (upgrade[i] + sell[i])));
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
    vector<int> maxUpgrades(vector<int>& count, vector<int>& upgrade, vector<int>& sell, vector<int>& money) {
        int n = count.size();
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            ans.push_back(min(count[i], (int) ((1LL * count[i] * sell[i] + money[i]) / (upgrade[i] + sell[i]))));
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxUpgrades(count []int, upgrade []int, sell []int, money []int) (ans []int) {
	for i, cnt := range count {
		ans = append(ans, min(cnt, (cnt*sell[i]+money[i])/(upgrade[i]+sell[i])))
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxUpgrades(
    count: number[],
    upgrade: number[],
    sell: number[],
    money: number[],
): number[] {
    const n = count.length;
    const ans: number[] = [];
    for (let i = 0; i < n; ++i) {
        const x = ((count[i] * sell[i] + money[i]) / (upgrade[i] + sell[i])) | 0;
        ans.push(Math.min(x, count[i]));
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

<p>你有&nbsp;<code>n</code>&nbsp;个数据中心并且需要升级他们的服务器。</p>

<p>给定四个长度为&nbsp;<code>n</code>&nbsp;的数组&nbsp;<code>count</code>，<code>upgrade</code>，<code>sell</code>&nbsp;和&nbsp;<code>money</code>，分别针对每个数据中心表示：</p>

<ul>
	<li>服务器的数量</li>
	<li>升级单个服务器的成本</li>
	<li>出售服务器获得的钱</li>
	<li>你最初拥有的钱</li>
</ul>

<p>返回一个数组&nbsp;<code>answer</code>，其中对于每个数据中心，<code>answer</code>&nbsp;中相应的元素代表可以升级的 <strong>最大</strong> 服务器数量。</p>

<p>请注意，一个数据中心的资金 <strong>不能</strong> 用于另一个数据中心。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">count = [4,3], upgrade = [3,5], sell = [4,2], money = [8,9]</span></p>

<p><strong>输出：</strong><span class="example-io">[3,2]</span></p>

<p><strong>解释：</strong></p>

<p>对于第一个数据中心，如果我们出售一台服务器，我们将会有&nbsp;<code>8 + 4 = 12</code>&nbsp;单位的钱并且我们能够升级其余的 3 台服务器。</p>

<p>对于第二个数据中心，如果我们出售一台服务器，我们将会有 <code>9 + 2 = 11</code> 单位的钱并且我们能够升级其余的 2&nbsp;台服务器。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">count = [1], upgrade = [2], sell = [1], money = [1]</span></p>

<p><strong>输出：</strong><span class="example-io">[0]</span></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= count.length == upgrade.length == sell.length == money.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= count[i], upgrade[i], sell[i], money[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学

对于每个数据中心，我们假设可以升级 $\textit{x}$ 台服务器，那么 $\textit{x} \times \textit{upgrade[i]} \leq \textit{count[i]} \times \textit{sell[i]} + \textit{money[i]}$。即 $\textit{x} \leq \frac{\textit{count[i]} \times \textit{sell[i]} + \textit{money[i]}}{\textit{upgrade[i]} + \textit{sell[i]}}$。又因为 $\textit{x} \leq \textit{count[i]}$，所以我们取两者的最小值即可。

时间复杂度 $O(n)$，其中 $n$ 为数组的长度。忽略答案数组的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxUpgrades(
        self, count: List[int], upgrade: List[int], sell: List[int], money: List[int]
    ) -> List[int]:
        ans = []
        for cnt, cost, income, cash in zip(count, upgrade, sell, money):
            ans.append(min(cnt, (cnt * income + cash) // (cost + income)))
        return ans
```

#### Java

```java
class Solution {
    public int[] maxUpgrades(int[] count, int[] upgrade, int[] sell, int[] money) {
        int n = count.length;
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            ans[i] = Math.min(
                count[i], (int) ((1L * count[i] * sell[i] + money[i]) / (upgrade[i] + sell[i])));
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> maxUpgrades(vector<int>& count, vector<int>& upgrade, vector<int>& sell, vector<int>& money) {
        int n = count.size();
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            ans.push_back(min(count[i], (int) ((1LL * count[i] * sell[i] + money[i]) / (upgrade[i] + sell[i]))));
        }
        return ans;
    }
};
```

#### Go

```go
func maxUpgrades(count []int, upgrade []int, sell []int, money []int) (ans []int) {
	for i, cnt := range count {
		ans = append(ans, min(cnt, (cnt*sell[i]+money[i])/(upgrade[i]+sell[i])))
	}
	return
}
```

#### TypeScript

```ts
function maxUpgrades(
    count: number[],
    upgrade: number[],
    sell: number[],
    money: number[],
): number[] {
    const n = count.length;
    const ans: number[] = [];
    for (let i = 0; i < n; ++i) {
        const x = ((count[i] * sell[i] + money[i]) / (upgrade[i] + sell[i])) | 0;
        ans.push(Math.min(x, count[i]));
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3156. 员工任务持续时间和并发任务 🔒](https://leetcode.cn/problems/employee-task-duration-and-concurrent-tasks){#3156}

{{< tabs "3156" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT DISTINCT employee_id, start_time AS st
        FROM Tasks
        UNION DISTINCT
        SELECT DISTINCT employee_id, end_time AS st
        FROM Tasks
    ),
    P AS (
        SELECT
            *,
            LEAD(st) OVER (
                PARTITION BY employee_id
                ORDER BY st
            ) AS ed
        FROM T
    ),
    S AS (
        SELECT
            P.*,
            COUNT(1) AS concurrent_count
        FROM
            P
            INNER JOIN Tasks USING (employee_id)
        WHERE P.st >= Tasks.start_time AND P.ed <= Tasks.end_time
        GROUP BY 1, 2, 3
    )
SELECT
    employee_id,
    FLOOR(SUM(TIME_TO_SEC(TIMEDIFF(ed, st)) / 3600)) AS total_task_hours,
    MAX(concurrent_count) AS max_concurrent_tasks
FROM S
GROUP BY 1
ORDER BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Tasks</code></p>

<pre>
+---------------+----------+
| Column Name   | Type     |
+---------------+----------+
| task_id       | int      |
| employee_id   | int      |
| start_time    | datetime |
| end_time      | datetime |
+---------------+----------+
(task_id, employee_id) 是这张表的主键。
这张表的每一行包含任务标识，员工标识和每个任务的开始和结束时间。
</pre>

<p>编写一个解决方案来查找 <strong>每个</strong> 员工的任务 <strong>总持续时间</strong> 以及员工在任何时间点处理的 <strong>最大并发任务数</strong>。总时长应该 <strong>向下取整</strong>&nbsp;到最近的 <strong>整小时</strong>。</p>

<p>返回结果表以&nbsp;<code>employee_id</code><strong> <em>升序</em></strong><em>&nbsp;排序。</em></p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例：</strong></p>

<div class="example-block">
<p><strong>输入：</strong></p>

<p>Tasks 表：</p>

<pre class="example-io">
+---------+-------------+---------------------+---------------------+
| task_id | employee_id | start_time          | end_time            |
+---------+-------------+---------------------+---------------------+
| 1       | 1001        | 2023-05-01 08:00:00 | 2023-05-01 09:00:00 |
| 2       | 1001        | 2023-05-01 08:30:00 | 2023-05-01 10:30:00 |
| 3       | 1001        | 2023-05-01 11:00:00 | 2023-05-01 12:00:00 |
| 7       | 1001        | 2023-05-01 13:00:00 | 2023-05-01 15:30:00 |
| 4       | 1002        | 2023-05-01 09:00:00 | 2023-05-01 10:00:00 |
| 5       | 1002        | 2023-05-01 09:30:00 | 2023-05-01 11:30:00 |
| 6       | 1003        | 2023-05-01 14:00:00 | 2023-05-01 16:00:00 |
+---------+-------------+---------------------+---------------------+
</pre>

<p><strong>输出：</strong></p>

<pre class="example-io">
+-------------+------------------+----------------------+
| employee_id | total_task_hours | max_concurrent_tasks |
+-------------+------------------+----------------------+
| 1001        | 6                | 2                    |
| 1002        | 2                | 2                    |
| 1003        | 2                | 1                    |
+-------------+------------------+----------------------+
</pre>

<p><strong>解释：</strong></p>

<ul>
	<li>对于员工 ID 1001：
	<ul>
		<li>任务 1 和任务 2 从 08:30 到&nbsp;09:00 重叠（30 分钟）。</li>
		<li>任务 7 持续时间为 150 分钟（2 小时 30 分钟）。</li>
		<li>总工作小时：60（任务 1）+ 120（任务 2）+ 60（任务&nbsp;3）+ 150（任务 7）- 30（重叠）= 360 分钟 = 6 小时。</li>
		<li>最大并发任务：2 （重叠期间）。</li>
	</ul>
	</li>
	<li>对于员工 ID 1002：
	<ul>
		<li>任务 4 和任务 5 从 09:30 到&nbsp;10:00 重叠（30 分钟）。</li>
		<li>总工作时间：60 （任务&nbsp;4）+ 120（任务 5）- 30（重叠）= 150 分钟 = 2 小时 30 分钟。</li>
		<li>总工作小时：（舍入后）：2 小时。</li>
		<li>最大并发任务：2 （重叠期间）。</li>
	</ul>
	</li>
	<li>对于员工 ID 1003：
	<ul>
		<li>没有重叠的工作。</li>
		<li>总工作时间：120 分钟 = 2 小时。</li>
		<li>最大并发任务：1。</li>
	</ul>
	</li>
</ul>

<p><b>注意：</b>输出表以 employee_id 升序排序。</p>
</div>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：合并 + 连接

我们首先将 `employee_id` 的 `start_time` 和 `end_time` 合并到一个新的表 `T` 中，然后使用 `LEAD` 函数计算出每个员工的下一个任务的开始时间，接着我们将 `T` 表和 `Tasks` 表连接起来，计算出每个员工的并发任务数，最后按照 `employee_id` 分组，计算出每个员工的总任务时间和最大并发任务数。

相似题目：

-   [3268. Find Overlapping Shifts II 🔒](https://github.com/doocs/leetcode/blob/main/solution/3200-3299/3268.Find%20Overlapping%20Shifts%20II/README.md)

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT DISTINCT employee_id, start_time AS st
        FROM Tasks
        UNION DISTINCT
        SELECT DISTINCT employee_id, end_time AS st
        FROM Tasks
    ),
    P AS (
        SELECT
            *,
            LEAD(st) OVER (
                PARTITION BY employee_id
                ORDER BY st
            ) AS ed
        FROM T
    ),
    S AS (
        SELECT
            P.*,
            COUNT(1) AS concurrent_count
        FROM
            P
            INNER JOIN Tasks USING (employee_id)
        WHERE P.st >= Tasks.start_time AND P.ed <= Tasks.end_time
        GROUP BY 1, 2, 3
    )
SELECT
    employee_id,
    FLOOR(SUM(TIME_TO_SEC(TIMEDIFF(ed, st)) / 3600)) AS total_task_hours,
    MAX(concurrent_count) AS max_concurrent_tasks
FROM S
GROUP BY 1
ORDER BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3157. 找到具有最小和的树的层数 🔒](https://leetcode.cn/problems/find-the-level-of-tree-with-minimum-sum){#3157}

{{< tabs "3157" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minimumLevel(self, root: Optional[TreeNode]) -> int:
        q = deque([root])
        ans = 0
        level, s = 1, inf
        while q:
            t = 0
            for _ in range(len(q)):
                node = q.popleft()
                t += node.val
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            if s > t:
                s = t
                ans = level
            level += 1
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
    public int minimumLevel(TreeNode root) {
        Deque<TreeNode> q = new ArrayDeque<>();
        q.offer(root);
        int ans = 0;
        long s = Long.MAX_VALUE;
        for (int level = 1; !q.isEmpty(); ++level) {
            long t = 0;
            for (int m = q.size(); m > 0; --m) {
                TreeNode node = q.poll();
                t += node.val;
                if (node.left != null) {
                    q.offer(node.left);
                }
                if (node.right != null) {
                    q.offer(node.right);
                }
            }
            if (s > t) {
                s = t;
                ans = level;
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
    int minimumLevel(TreeNode* root) {
        queue<TreeNode*> q{{root}};
        int ans = 0;
        long long s = 1LL << 60;
        for (int level = 1; q.size(); ++level) {
            long long t = 0;
            for (int m = q.size(); m; --m) {
                TreeNode* node = q.front();
                q.pop();
                t += node->val;
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            if (s > t) {
                s = t;
                ans = level;
            }
        }
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
func minimumLevel(root *TreeNode) (ans int) {
	q := []*TreeNode{root}
	s := math.MaxInt64
	for level := 1; len(q) > 0; level++ {
		t := 0
		for m := len(q); m > 0; m-- {
			node := q[0]
			q = q[1:]
			t += node.Val
			if node.Left != nil {
				q = append(q, node.Left)
			}
			if node.Right != nil {
				q = append(q, node.Right)
			}
		}
		if s > t {
			s = t
			ans = level
		}
	}
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

function minimumLevel(root: TreeNode | null): number {
    const q: TreeNode[] = [root];
    let s = Infinity;
    let ans = 0;
    for (let level = 1; q.length; ++level) {
        const qq: TreeNode[] = [];
        let t = 0;
        for (const { val, left, right } of q) {
            t += val;
            left && qq.push(left);
            right && qq.push(right);
        }
        if (s > t) {
            s = t;
            ans = level;
        }
        q.splice(0, q.length, ...qq);
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

<p>给定一棵二叉树的根&nbsp;<code>root</code>，其中每个节点有一个值，返回树中 <strong>层和最小</strong> 的层数（如果相等，返回&nbsp;<strong>最低</strong>&nbsp;的层数）。</p>

<p><strong>注意</strong>&nbsp;树的根节点在第一层，其它任何节点的层数是它到根节点的距离+1。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">root = [50,6,2,30,80,7]</span></p>

<p><strong>输出：</strong><span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3100-3199/3157.Find%20the%20Level%20of%20Tree%20with%20Minimum%20Sum/images/image_2024-05-17_16-15-46.png" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 265px; height: 129px;" /></p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">root = [36,17,10,null,null,24]</span></p>

<p><strong>输出：</strong><span class="example-io">3</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3100-3199/3157.Find%20the%20Level%20of%20Tree%20with%20Minimum%20Sum/images/image_2024-05-17_16-14-18.png" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 170px; height: 135px;" /></p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">root = [5,null,5,null,5]</span></p>

<p><strong>输出：</strong><span class="example-io">1</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3100-3199/3157.Find%20the%20Level%20of%20Tree%20with%20Minimum%20Sum/images/image_2024-05-19_19-07-20.png" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 170px; height: 135px;" /></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数量的范围是&nbsp;<code>[1, 10<sup>5</sup>]</code>。</li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS

我们可以使用 BFS，逐层遍历二叉树，记录每一层的节点值之和，找到具有最小节点值之和的层，返回该层的层数。

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
    def minimumLevel(self, root: Optional[TreeNode]) -> int:
        q = deque([root])
        ans = 0
        level, s = 1, inf
        while q:
            t = 0
            for _ in range(len(q)):
                node = q.popleft()
                t += node.val
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            if s > t:
                s = t
                ans = level
            level += 1
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
    public int minimumLevel(TreeNode root) {
        Deque<TreeNode> q = new ArrayDeque<>();
        q.offer(root);
        int ans = 0;
        long s = Long.MAX_VALUE;
        for (int level = 1; !q.isEmpty(); ++level) {
            long t = 0;
            for (int m = q.size(); m > 0; --m) {
                TreeNode node = q.poll();
                t += node.val;
                if (node.left != null) {
                    q.offer(node.left);
                }
                if (node.right != null) {
                    q.offer(node.right);
                }
            }
            if (s > t) {
                s = t;
                ans = level;
            }
        }
        return ans;
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
    int minimumLevel(TreeNode* root) {
        queue<TreeNode*> q{{root}};
        int ans = 0;
        long long s = 1LL << 60;
        for (int level = 1; q.size(); ++level) {
            long long t = 0;
            for (int m = q.size(); m; --m) {
                TreeNode* node = q.front();
                q.pop();
                t += node->val;
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            if (s > t) {
                s = t;
                ans = level;
            }
        }
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
func minimumLevel(root *TreeNode) (ans int) {
	q := []*TreeNode{root}
	s := math.MaxInt64
	for level := 1; len(q) > 0; level++ {
		t := 0
		for m := len(q); m > 0; m-- {
			node := q[0]
			q = q[1:]
			t += node.Val
			if node.Left != nil {
				q = append(q, node.Left)
			}
			if node.Right != nil {
				q = append(q, node.Right)
			}
		}
		if s > t {
			s = t
			ans = level
		}
	}
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

function minimumLevel(root: TreeNode | null): number {
    const q: TreeNode[] = [root];
    let s = Infinity;
    let ans = 0;
    for (let level = 1; q.length; ++level) {
        const qq: TreeNode[] = [];
        let t = 0;
        for (const { val, left, right } of q) {
            t += val;
            left && qq.push(left);
            right && qq.push(right);
        }
        if (s > t) {
            s = t;
            ans = level;
        }
        q.splice(0, q.length, ...qq);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3158. 求出出现两次数字的 XOR 值](https://leetcode.cn/problems/find-the-xor-of-numbers-which-appear-twice){#3158}

{{< tabs "3158" >}}

{{% tab "python" %}}
```python
class Solution:
    def duplicateNumbersXOR(self, nums: List[int]) -> int:
        ans = mask = 0
        for x in nums:
            if mask >> x & 1:
                ans ^= x
            else:
                mask |= 1 << x
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int duplicateNumbersXOR(int[] nums) {
        int ans = 0;
        long mask = 0;
        for (int x : nums) {
            if ((mask >> x & 1) == 1) {
                ans ^= x;
            } else {
                mask |= 1L << x;
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
    int duplicateNumbersXOR(vector<int>& nums) {
        int ans = 0;
        long long mask = 0;
        for (int x : nums) {
            if (mask >> x & 1) {
                ans ^= x;
            } else {
                mask |= 1LL << x;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func duplicateNumbersXOR(nums []int) (ans int) {
	mask := 0
	for _, x := range nums {
		if mask>>x&1 == 1 {
			ans ^= x
		} else {
			mask |= 1 << x
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function duplicateNumbersXOR(nums: number[]): number {
    let ans = 0;
    let mask = 0n;
    for (const x of nums) {
        if ((mask >> BigInt(x)) & 1n) {
            ans ^= x;
        } else {
            mask |= 1n << BigInt(x);
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

<p>给你一个数组&nbsp;<code>nums</code>&nbsp;，数组中的数字 <strong>要么</strong> 出现一次，<strong>要么</strong>&nbsp;出现两次。</p>

<p>请你返回数组中所有出现两次数字的按位<em>&nbsp;</em><code>XOR</code>&nbsp;值，如果没有数字出现过两次，返回 0 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,2,1,3]</span></p>

<p><span class="example-io"><b>输出：</b>1</span></p>

<p><strong>解释：</strong></p>

<p><code>nums</code>&nbsp;中唯一出现过两次的数字是 1 。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,2,3]</span></p>

<p><span class="example-io"><b>输出：</b>0</span></p>

<p><strong>解释：</strong></p>

<p><code>nums</code>&nbsp;中没有数字出现两次。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,2,2,1]</span></p>

<p><span class="example-io"><b>输出：</b>3</span></p>

<p><strong>解释：</strong></p>

<p>数字 1 和&nbsp;2 出现过两次。<code>1 XOR 2 == 3</code>&nbsp;。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 50</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 50</code></li>
	<li><code>nums</code>&nbsp;中每个数字要么出现过一次，要么出现过两次。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们定义一个数组或哈希表 $\textit{cnt}$ 记录每个数字出现的次数。

接下来，遍历数组 $\textit{nums}$，当某个数字出现两次时，我们将其与答案进行异或运算。

最后返回答案即可。

时间复杂度 $O(n)$，空间复杂度 $O(M)$。其中 $n$ 是数组 $\textit{nums}$ 的长度，而 $M$ 是数组 $\textit{nums}$ 中的最大值或数组 $\textit{nums}$ 不同数字的个数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def duplicateNumbersXOR(self, nums: List[int]) -> int:
        cnt = Counter(nums)
        return reduce(xor, [x for x, v in cnt.items() if v == 2], 0)
```

#### Java

```java
class Solution {
    public int duplicateNumbersXOR(int[] nums) {
        int[] cnt = new int[51];
        int ans = 0;
        for (int x : nums) {
            if (++cnt[x] == 2) {
                ans ^= x;
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
    int duplicateNumbersXOR(vector<int>& nums) {
        int cnt[51]{};
        int ans = 0;
        for (int x : nums) {
            if (++cnt[x] == 2) {
                ans ^= x;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func duplicateNumbersXOR(nums []int) (ans int) {
	cnt := [51]int{}
	for _, x := range nums {
		cnt[x]++
		if cnt[x] == 2 {
			ans ^= x
		}
	}
	return
}
```

#### TypeScript

```ts
function duplicateNumbersXOR(nums: number[]): number {
    const cnt: number[] = Array(51).fill(0);
    let ans: number = 0;
    for (const x of nums) {
        if (++cnt[x] === 2) {
            ans ^= x;
        }
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：位运算

由于题目中给出的数字范围是 $1 \leq \textit{nums}[i] \leq 50$，我们可以使用一个 $64$ 位的整数来存储每个数字的出现次数。

我们定义一个整数 $\textit{mask}$ 来记录每个数字是否出现过。

接下来，遍历数组 $\textit{nums}$，当某个数字出现两次时，即 $\textit{mask}$ 的二进制表示中第 $x$ 位为 $1$ 时，我们将其与答案进行异或运算。否则，我们将 $\textit{mask}$ 的第 $x$ 位设置为 $1$。

最后返回答案即可。

时间复杂度 $O(n)$，其中 $n$ 是数组 $\textit{nums}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def duplicateNumbersXOR(self, nums: List[int]) -> int:
        ans = mask = 0
        for x in nums:
            if mask >> x & 1:
                ans ^= x
            else:
                mask |= 1 << x
        return ans
```

#### Java

```java
class Solution {
    public int duplicateNumbersXOR(int[] nums) {
        int ans = 0;
        long mask = 0;
        for (int x : nums) {
            if ((mask >> x & 1) == 1) {
                ans ^= x;
            } else {
                mask |= 1L << x;
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
    int duplicateNumbersXOR(vector<int>& nums) {
        int ans = 0;
        long long mask = 0;
        for (int x : nums) {
            if (mask >> x & 1) {
                ans ^= x;
            } else {
                mask |= 1LL << x;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func duplicateNumbersXOR(nums []int) (ans int) {
	mask := 0
	for _, x := range nums {
		if mask>>x&1 == 1 {
			ans ^= x
		} else {
			mask |= 1 << x
		}
	}
	return
}
```

#### TypeScript

```ts
function duplicateNumbersXOR(nums: number[]): number {
    let ans = 0;
    let mask = 0n;
    for (const x of nums) {
        if ((mask >> BigInt(x)) & 1n) {
            ans ^= x;
        } else {
            mask |= 1n << BigInt(x);
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

# [3159. 查询数组中元素的出现位置](https://leetcode.cn/problems/find-occurrences-of-an-element-in-an-array){#3159}

{{< tabs "3159" >}}

{{% tab "python" %}}
```python
class Solution:
    def occurrencesOfElement(
        self, nums: List[int], queries: List[int], x: int
    ) -> List[int]:
        ids = [i for i, v in enumerate(nums) if v == x]
        return [ids[i - 1] if i - 1 < len(ids) else -1 for i in queries]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] occurrencesOfElement(int[] nums, int[] queries, int x) {
        List<Integer> ids = new ArrayList<>();
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] == x) {
                ids.add(i);
            }
        }
        int m = queries.length;
        int[] ans = new int[m];
        for (int i = 0; i < m; ++i) {
            int j = queries[i] - 1;
            ans[i] = j < ids.size() ? ids.get(j) : -1;
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
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> ids;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == x) {
                ids.push_back(i);
            }
        }
        vector<int> ans;
        for (int& i : queries) {
            ans.push_back(i - 1 < ids.size() ? ids[i - 1] : -1);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func occurrencesOfElement(nums []int, queries []int, x int) (ans []int) {
	ids := []int{}
	for i, v := range nums {
		if v == x {
			ids = append(ids, i)
		}
	}
	for _, i := range queries {
		if i-1 < len(ids) {
			ans = append(ans, ids[i-1])
		} else {
			ans = append(ans, -1)
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function occurrencesOfElement(nums: number[], queries: number[], x: number): number[] {
    const ids: number[] = nums.map((v, i) => (v === x ? i : -1)).filter(v => v !== -1);
    return queries.map(i => ids[i - 1] ?? -1);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;，一个整数数组&nbsp;<code>queries</code>&nbsp;和一个整数&nbsp;<code>x</code>&nbsp;。</p>

<p>对于每个查询&nbsp;<code>queries[i]</code>&nbsp;，你需要找到&nbsp;<code>nums</code>&nbsp;中第&nbsp;<code>queries[i]</code>&nbsp;个&nbsp;<code>x</code>&nbsp;的位置，并返回它的下标。如果数组中&nbsp;<code>x</code>&nbsp;的出现次数少于&nbsp;<code>queries[i]</code>&nbsp;，该查询的答案为 -1 。</p>

<p>请你返回一个整数数组&nbsp;<code>answer</code>&nbsp;，包含所有查询的答案。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,3,1,7], queries = [1,3,2,4], x = 1</span></p>

<p><span class="example-io"><b>输出：</b>[0,-1,2,-1]</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>第 1 个查询，第一个 1 出现在下标 0 处。</li>
	<li>第 2 个查询，<code>nums</code>&nbsp;中只有两个 1 ，所以答案为 -1 。</li>
	<li>第 3 个查询，第二个 1 出现在下标 2 处。</li>
	<li>第 4 个查询，<code>nums</code>&nbsp;中只有两个 1 ，所以答案为 -1 。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,2,3], queries = [10], x = 5</span></p>

<p><span class="example-io"><b>输出：</b>[-1]</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>第 1 个查询，<code>nums</code>&nbsp;中没有 5 ，所以答案为 -1 。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length, queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= queries[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i], x &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

根据题目描述，我们可以先遍历一遍数组 $\textit{nums}$，找出所有值为 $x$ 的元素的下标，记录在数组 $\textit{ids}$ 中。

接着遍历数组 $\textit{queries}$，对于每个查询 $i$，如果 $i - 1$ 小于 $\textit{ids}$ 的长度，那么答案就是 $\textit{ids}[i - 1]$，否则答案就是 $-1$。

时间复杂度 $O(n + m)$，空间复杂度 $O(n + m)$。其中 $n$ 和 $m$ 分别是数组 $\textit{nums}$ 和数组 $\textit{queries}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def occurrencesOfElement(
        self, nums: List[int], queries: List[int], x: int
    ) -> List[int]:
        ids = [i for i, v in enumerate(nums) if v == x]
        return [ids[i - 1] if i - 1 < len(ids) else -1 for i in queries]
```

#### Java

```java
class Solution {
    public int[] occurrencesOfElement(int[] nums, int[] queries, int x) {
        List<Integer> ids = new ArrayList<>();
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] == x) {
                ids.add(i);
            }
        }
        int m = queries.length;
        int[] ans = new int[m];
        for (int i = 0; i < m; ++i) {
            int j = queries[i] - 1;
            ans[i] = j < ids.size() ? ids.get(j) : -1;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> ids;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == x) {
                ids.push_back(i);
            }
        }
        vector<int> ans;
        for (int& i : queries) {
            ans.push_back(i - 1 < ids.size() ? ids[i - 1] : -1);
        }
        return ans;
    }
};
```

#### Go

```go
func occurrencesOfElement(nums []int, queries []int, x int) (ans []int) {
	ids := []int{}
	for i, v := range nums {
		if v == x {
			ids = append(ids, i)
		}
	}
	for _, i := range queries {
		if i-1 < len(ids) {
			ans = append(ans, ids[i-1])
		} else {
			ans = append(ans, -1)
		}
	}
	return
}
```

#### TypeScript

```ts
function occurrencesOfElement(nums: number[], queries: number[], x: number): number[] {
    const ids: number[] = nums.map((v, i) => (v === x ? i : -1)).filter(v => v !== -1);
    return queries.map(i => ids[i - 1] ?? -1);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
