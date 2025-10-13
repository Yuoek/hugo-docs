---
title: "0580_统计各专业学生人数 🔒"
date: 2025-10-08T18:36:17+08:00
weight: 9
tags: [几何, 动态规划, 单调栈, 双指针, 哈希表, 字典树, 字符串, 广度优先搜索, 排序, 数学, 数据库, 数组, 栈, 树, 深度优先搜索, 设计, 贪心]
---

{{< markmap >}}
### [0580_统计各专业学生人数 🔒](#580)
#### [数据库](#580)
### [0581_最短无序连续子数组](#581)
#### [栈](#581)
#### [贪心](#581)
#### [数组](#581)
#### [双指针](#581)
#### [排序](#581)
#### [单调栈](#581)
### [0582_杀掉进程 🔒](#582)
#### [树](#582)
#### [深度优先搜索](#582)
#### [广度优先搜索](#582)
#### [数组](#582)
#### [哈希表](#582)
### [0583_两个字符串的删除操作](#583)
#### [字符串](#583)
#### [动态规划](#583)
### [0584_寻找用户推荐人](#584)
#### [数据库](#584)
### [0585_2016年的投资](#585)
#### [数据库](#585)
### [0586_订单最多的客户](#586)
#### [数据库](#586)
### [0587_安装栅栏](#587)
#### [几何](#587)
#### [数组](#587)
#### [数学](#587)
### [0588_设计内存文件系统 🔒](#588)
#### [设计](#588)
#### [字典树](#588)
#### [哈希表](#588)
#### [字符串](#588)
#### [排序](#588)
### [0589_N 叉树的前序遍历](#589)
#### [栈](#589)
#### [树](#589)
#### [深度优先搜索](#589)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0580_统计各专业学生人数 🔒
___
#### 数据库
---
### 0581_最短无序连续子数组
___
#### 栈
___
#### 贪心
___
#### 数组
___
#### 双指针
___
#### 排序
___
#### 单调栈
---
### 0582_杀掉进程 🔒
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 数组
___
#### 哈希表
---
### 0583_两个字符串的删除操作
___
#### 字符串
___
#### 动态规划
---
### 0584_寻找用户推荐人
___
#### 数据库
---
### 0585_2016年的投资
___
#### 数据库
---
### 0586_订单最多的客户
___
#### 数据库
---
### 0587_安装栅栏
___
#### 几何
___
#### 数组
___
#### 数学
---
### 0588_设计内存文件系统 🔒
___
#### 设计
___
#### 字典树
___
#### 哈希表
___
#### 字符串
___
#### 排序
---
### 0589_N 叉树的前序遍历
___
#### 栈
___
#### 树
___
#### 深度优先搜索
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 几何 | 动态规划 | 单调栈 |
| 双指针 | 哈希表 | 字典树 |
| 字符串 | 广度优先搜索 | 排序 |
| 数学 | 数据库 | 数组 |
| 栈 | 树 | 深度优先搜索 |
| 设计 | 贪心 |  |

# [580. 统计各专业学生人数 🔒](https://leetcode.cn/problems/count-student-number-in-departments){#580}

{{< tabs "580" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT dept_name, COUNT(student_id) AS student_number
FROM
    Department
    LEFT JOIN Student USING (dept_id)
GROUP BY dept_id
ORDER BY 2 DESC, 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表:&nbsp;<code>Student</code></p>

<pre>
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| student_id   | int     |
| student_name | varchar |
| gender       | varchar |
| dept_id      | int     |
+--------------+---------+
student_id 是该表的主键（具有唯一值的列）。
dept_id是Department表中dept_id的外键。
该表的每一行都表示学生的姓名、性别和所属系的id。
</pre>

<p>&nbsp;</p>

<p>表:&nbsp;<code>Department</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| dept_id     | int     |
| dept_name   | varchar |
+-------------+---------+
dept_id是该表的主键（具有唯一值的列）。
该表的每一行包含一个部门的id和名称。</pre>

<p>&nbsp;</p>

<p>编写解决方案，为&nbsp;<code>Department</code>&nbsp;表中的所有部门(甚至是没有当前学生的部门)报告各自的部门名称和每个部门的学生人数。</p>

<p>按 <code>student_number</code> <strong>降序&nbsp;</strong>返回结果表。如果是平局，则按 <code>dept_name</code> 的&nbsp; <strong>字母顺序&nbsp;</strong>排序。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
Student 表:
+------------+--------------+--------+---------+
| student_id | student_name | gender | dept_id |
+------------+--------------+--------+---------+
| 1          | Jack         | M      | 1       |
| 2          | Jane         | F      | 1       |
| 3          | Mark         | M      | 2       |
+------------+--------------+--------+---------+
Department 表:
+---------+-------------+
| dept_id | dept_name   |
+---------+-------------+
| 1       | Engineering |
| 2       | Science     |
| 3       | Law         |
+---------+-------------+
<strong>输出:</strong> 
+-------------+----------------+
| dept_name   | student_number |
+-------------+----------------+
| Engineering | 2              |
| Science     | 1              |
| Law         | 0              |
+-------------+----------------+</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：左连接 + 分组统计

我们可以使用左连接，将 `Department` 表与 `Student` 表按照 `dept_id` 进行连接，然后按照 `dept_id` 分组统计学生人数，最后按照 `student_number` 降序、`dept_name` 升序排序即可。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT dept_name, COUNT(student_id) AS student_number
FROM
    Department
    LEFT JOIN Student USING (dept_id)
GROUP BY dept_id
ORDER BY 2 DESC, 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [581. 最短无序连续子数组](https://leetcode.cn/problems/shortest-unsorted-continuous-subarray){#581}

{{< tabs "581" >}}

{{% tab "python" %}}
```python
class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        mi, mx = inf, -inf
        l = r = -1
        n = len(nums)
        for i, x in enumerate(nums):
            if mx > x:
                r = i
            else:
                mx = x
            if mi < nums[n - i - 1]:
                l = n - i - 1
            else:
                mi = nums[n - i - 1]
        return 0 if r == -1 else r - l + 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findUnsortedSubarray(int[] nums) {
        final int inf = 1 << 30;
        int n = nums.length;
        int l = -1, r = -1;
        int mi = inf, mx = -inf;
        for (int i = 0; i < n; ++i) {
            if (mx > nums[i]) {
                r = i;
            } else {
                mx = nums[i];
            }
            if (mi < nums[n - i - 1]) {
                l = n - i - 1;
            } else {
                mi = nums[n - i - 1];
            }
        }
        return r == -1 ? 0 : r - l + 1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        const int inf = 1e9;
        int n = nums.size();
        int l = -1, r = -1;
        int mi = inf, mx = -inf;
        for (int i = 0; i < n; ++i) {
            if (mx > nums[i]) {
                r = i;
            } else {
                mx = nums[i];
            }
            if (mi < nums[n - i - 1]) {
                l = n - i - 1;
            } else {
                mi = nums[n - i - 1];
            }
        }
        return r == -1 ? 0 : r - l + 1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findUnsortedSubarray(nums []int) int {
	const inf = 1 << 30
	n := len(nums)
	l, r := -1, -1
	mi, mx := inf, -inf
	for i, x := range nums {
		if mx > x {
			r = i
		} else {
			mx = x
		}
		if mi < nums[n-i-1] {
			l = n - i - 1
		} else {
			mi = nums[n-i-1]
		}
	}
	if r == -1 {
		return 0
	}
	return r - l + 1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findUnsortedSubarray(nums: number[]): number {
    let [l, r] = [-1, -1];
    let [mi, mx] = [Infinity, -Infinity];
    const n = nums.length;
    for (let i = 0; i < n; ++i) {
        if (mx > nums[i]) {
            r = i;
        } else {
            mx = nums[i];
        }
        if (mi < nums[n - i - 1]) {
            l = n - i - 1;
        } else {
            mi = nums[n - i - 1];
        }
    }
    return r === -1 ? 0 : r - l + 1;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn find_unsorted_subarray(nums: Vec<i32>) -> i32 {
        let inf = 1 << 30;
        let n = nums.len();
        let mut l = -1;
        let mut r = -1;
        let mut mi = inf;
        let mut mx = -inf;

        for i in 0..n {
            if mx > nums[i] {
                r = i as i32;
            } else {
                mx = nums[i];
            }

            if mi < nums[n - i - 1] {
                l = (n - i - 1) as i32;
            } else {
                mi = nums[n - i - 1];
            }
        }

        if r == -1 {
            0
        } else {
            r - l + 1
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

<p>给你一个整数数组 <code>nums</code> ，你需要找出一个 <strong>连续子数组</strong> ，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。</p>

<p>请你找出符合题意的 <strong>最短</strong> 子数组，并输出它的长度。</p>

<p> </p>

<div class="original__bRMd">
<div>
<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,6,4,8,10,9,15]
<strong>输出：</strong>5
<strong>解释：</strong>你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,4]
<strong>输出：</strong>0
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1]
<strong>输出：</strong>0
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 10<sup>4</sup></code></li>
	<li><code>-10<sup>5</sup> <= nums[i] <= 10<sup>5</sup></code></li>
</ul>

<p> </p>

<p><strong>进阶：</strong>你可以设计一个时间复杂度为 <code>O(n)</code> 的解决方案吗？</p>
</div>
</div>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序

我们可以先对数组进行排序，然后比较排序后的数组和原数组，找到最左边和最右边不相等的位置，它们之间的长度就是我们要找的最短无序连续子数组的长度。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        arr = sorted(nums)
        l, r = 0, len(nums) - 1
        while l <= r and nums[l] == arr[l]:
            l += 1
        while l <= r and nums[r] == arr[r]:
            r -= 1
        return r - l + 1
```

#### Java

```java
class Solution {
    public int findUnsortedSubarray(int[] nums) {
        int[] arr = nums.clone();
        Arrays.sort(arr);
        int l = 0, r = arr.length - 1;
        while (l <= r && nums[l] == arr[l]) {
            l++;
        }
        while (l <= r && nums[r] == arr[r]) {
            r--;
        }
        return r - l + 1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        int l = 0, r = arr.size() - 1;
        while (l <= r && arr[l] == nums[l]) {
            l++;
        }
        while (l <= r && arr[r] == nums[r]) {
            r--;
        }
        return r - l + 1;
    }
};
```

#### Go

```go
func findUnsortedSubarray(nums []int) int {
	arr := make([]int, len(nums))
	copy(arr, nums)
	sort.Ints(arr)
	l, r := 0, len(arr)-1
	for l <= r && nums[l] == arr[l] {
		l++
	}
	for l <= r && nums[r] == arr[r] {
		r--
	}
	return r - l + 1
}
```

#### TypeScript

```ts
function findUnsortedSubarray(nums: number[]): number {
    const arr = [...nums];
    arr.sort((a, b) => a - b);
    let [l, r] = [0, arr.length - 1];
    while (l <= r && arr[l] === nums[l]) {
        ++l;
    }
    while (l <= r && arr[r] === nums[r]) {
        --r;
    }
    return r - l + 1;
}
```

#### Rust

```rust
impl Solution {
    pub fn find_unsorted_subarray(nums: Vec<i32>) -> i32 {
        let mut arr = nums.clone();
        arr.sort();
        let mut l = 0usize;
        while l < nums.len() && nums[l] == arr[l] {
            l += 1;
        }
        if l == nums.len() {
            return 0;
        }
        let mut r = nums.len() - 1;
        while r > l && nums[r] == arr[r] {
            r -= 1;
        }
        (r - l + 1) as i32
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：维护左侧最大值和右侧最小值

我们可以从左到右遍历数组，维护一个最大值 $mx$，如果当前值小于 $mx$，说明当前值不在正确的位置上，我们更新右边界 $r$ 为当前位置。同理，我们可以从右到左遍历数组，维护一个最小值 $mi$，如果当前值大于 $mi$，说明当前值不在正确的位置上，我们更新左边界 $l$ 为当前位置。在初始化时，我们将 $l$ 和 $r$ 都初始化为 $-1$，如果 $l$ 和 $r$ 都没有被更新，说明数组已经有序，返回 $0$，否则返回 $r - l + 1$。

时间复杂度 $O(n)$，其中 $n$ 是数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        mi, mx = inf, -inf
        l = r = -1
        n = len(nums)
        for i, x in enumerate(nums):
            if mx > x:
                r = i
            else:
                mx = x
            if mi < nums[n - i - 1]:
                l = n - i - 1
            else:
                mi = nums[n - i - 1]
        return 0 if r == -1 else r - l + 1
```

#### Java

```java
class Solution {
    public int findUnsortedSubarray(int[] nums) {
        final int inf = 1 << 30;
        int n = nums.length;
        int l = -1, r = -1;
        int mi = inf, mx = -inf;
        for (int i = 0; i < n; ++i) {
            if (mx > nums[i]) {
                r = i;
            } else {
                mx = nums[i];
            }
            if (mi < nums[n - i - 1]) {
                l = n - i - 1;
            } else {
                mi = nums[n - i - 1];
            }
        }
        return r == -1 ? 0 : r - l + 1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        const int inf = 1e9;
        int n = nums.size();
        int l = -1, r = -1;
        int mi = inf, mx = -inf;
        for (int i = 0; i < n; ++i) {
            if (mx > nums[i]) {
                r = i;
            } else {
                mx = nums[i];
            }
            if (mi < nums[n - i - 1]) {
                l = n - i - 1;
            } else {
                mi = nums[n - i - 1];
            }
        }
        return r == -1 ? 0 : r - l + 1;
    }
};
```

#### Go

```go
func findUnsortedSubarray(nums []int) int {
	const inf = 1 << 30
	n := len(nums)
	l, r := -1, -1
	mi, mx := inf, -inf
	for i, x := range nums {
		if mx > x {
			r = i
		} else {
			mx = x
		}
		if mi < nums[n-i-1] {
			l = n - i - 1
		} else {
			mi = nums[n-i-1]
		}
	}
	if r == -1 {
		return 0
	}
	return r - l + 1
}
```

#### TypeScript

```ts
function findUnsortedSubarray(nums: number[]): number {
    let [l, r] = [-1, -1];
    let [mi, mx] = [Infinity, -Infinity];
    const n = nums.length;
    for (let i = 0; i < n; ++i) {
        if (mx > nums[i]) {
            r = i;
        } else {
            mx = nums[i];
        }
        if (mi < nums[n - i - 1]) {
            l = n - i - 1;
        } else {
            mi = nums[n - i - 1];
        }
    }
    return r === -1 ? 0 : r - l + 1;
}
```

#### Rust

```rust
impl Solution {
    pub fn find_unsorted_subarray(nums: Vec<i32>) -> i32 {
        let inf = 1 << 30;
        let n = nums.len();
        let mut l = -1;
        let mut r = -1;
        let mut mi = inf;
        let mut mx = -inf;

        for i in 0..n {
            if mx > nums[i] {
                r = i as i32;
            } else {
                mx = nums[i];
            }

            if mi < nums[n - i - 1] {
                l = (n - i - 1) as i32;
            } else {
                mi = nums[n - i - 1];
            }
        }

        if r == -1 {
            0
        } else {
            r - l + 1
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [582. 杀掉进程 🔒](https://leetcode.cn/problems/kill-process){#582}

{{< tabs "582" >}}

{{% tab "python" %}}
```python
class Solution:
    def killProcess(self, pid: List[int], ppid: List[int], kill: int) -> List[int]:
        def dfs(i: int):
            ans.append(i)
            for j in g[i]:
                dfs(j)

        g = defaultdict(list)
        for i, p in zip(pid, ppid):
            g[p].append(i)
        ans = []
        dfs(kill)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private Map<Integer, List<Integer>> g = new HashMap<>();
    private List<Integer> ans = new ArrayList<>();

    public List<Integer> killProcess(List<Integer> pid, List<Integer> ppid, int kill) {
        int n = pid.size();
        for (int i = 0; i < n; ++i) {
            g.computeIfAbsent(ppid.get(i), k -> new ArrayList<>()).add(pid.get(i));
        }
        dfs(kill);
        return ans;
    }

    private void dfs(int i) {
        ans.add(i);
        for (int j : g.getOrDefault(i, Collections.emptyList())) {
            dfs(j);
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> g;
        int n = pid.size();
        for (int i = 0; i < n; ++i) {
            g[ppid[i]].push_back(pid[i]);
        }
        vector<int> ans;
        function<void(int)> dfs = [&](int i) {
            ans.push_back(i);
            for (int j : g[i]) {
                dfs(j);
            }
        };
        dfs(kill);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func killProcess(pid []int, ppid []int, kill int) (ans []int) {
	g := map[int][]int{}
	for i, p := range ppid {
		g[p] = append(g[p], pid[i])
	}
	var dfs func(int)
	dfs = func(i int) {
		ans = append(ans, i)
		for _, j := range g[i] {
			dfs(j)
		}
	}
	dfs(kill)
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function killProcess(pid: number[], ppid: number[], kill: number): number[] {
    const g: Map<number, number[]> = new Map();
    for (let i = 0; i < pid.length; ++i) {
        if (!g.has(ppid[i])) {
            g.set(ppid[i], []);
        }
        g.get(ppid[i])?.push(pid[i]);
    }
    const ans: number[] = [];
    const dfs = (i: number) => {
        ans.push(i);
        for (const j of g.get(i) ?? []) {
            dfs(j);
        }
    };
    dfs(kill);
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    pub fn kill_process(pid: Vec<i32>, ppid: Vec<i32>, kill: i32) -> Vec<i32> {
        let mut g: HashMap<i32, Vec<i32>> = HashMap::new();
        let mut ans: Vec<i32> = Vec::new();

        let n = pid.len();
        for i in 0..n {
            g.entry(ppid[i]).or_insert(Vec::new()).push(pid[i]);
        }

        Self::dfs(&mut ans, &g, kill);
        ans
    }

    fn dfs(ans: &mut Vec<i32>, g: &HashMap<i32, Vec<i32>>, i: i32) {
        ans.push(i);
        if let Some(children) = g.get(&i) {
            for &j in children {
                Self::dfs(ans, g, j);
            }
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

<p>系统中存在 <code>n</code>&nbsp;个进程，形成一个有根树结构。给你两个整数数组&nbsp;<code>pid</code> 和 <code>ppid</code> ，其中 <code>pid[i]</code> 是第 <code>i</code> 个进程的 ID ，<code>ppid[i]</code> 是第 <code>i</code> 个进程的父进程 ID 。</p>

<p>每一个进程只有 <strong>一个父进程</strong> ，但是可能会有 <strong>一个或者多个子进程</strong> 。只有一个进程的 <code>ppid[i] = 0</code> ，意味着这个进程 <strong>没有父进程</strong> 。</p>

<p>当一个进程 <strong>被杀掉</strong> 的时候，它所有的子进程和后代进程都要被杀掉。</p>

<p>给你一个整数 <code>kill</code> 表示要杀掉​​进程的 ID ，返回被杀掉的进程的 ID 列表。可以按 <strong>任意顺序</strong> 返回答案。</p>
&nbsp;

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0582.Kill%20Process/images/ptree.jpg" style="width: 207px; height: 302px;" />
<pre>
<strong>输入：</strong>pid = [1,3,10,5], ppid = [3,0,5,3], kill = 5
<strong>输出：</strong>[5,10]
<strong>解释：</strong>涂为红色的进程是应该被杀掉的进程。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>pid = [1], ppid = [0], kill = 1
<strong>输出：</strong>[1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == pid.length</code></li>
	<li><code>n == ppid.length</code></li>
	<li><code>1 &lt;= n &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= pid[i] &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= ppid[i] &lt;= 5 * 10<sup>4</sup></code></li>
	<li>仅有一个进程没有父进程</li>
	<li><code>pid</code> 中的所有值 <strong>互不相同</strong></li>
	<li>题目数据保证 <code>kill</code> 在 <code>pid</code> 中</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们先根据 $pid$ 和 $ppid$ 构建出图 $g$，其中 $g[i]$ 表示进程 $i$ 的所有子进程。然后从进程 $kill$ 开始，进行深度优先搜索，即可得到所有被杀掉的进程。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是进程的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def killProcess(self, pid: List[int], ppid: List[int], kill: int) -> List[int]:
        def dfs(i: int):
            ans.append(i)
            for j in g[i]:
                dfs(j)

        g = defaultdict(list)
        for i, p in zip(pid, ppid):
            g[p].append(i)
        ans = []
        dfs(kill)
        return ans
```

#### Java

```java
class Solution {
    private Map<Integer, List<Integer>> g = new HashMap<>();
    private List<Integer> ans = new ArrayList<>();

    public List<Integer> killProcess(List<Integer> pid, List<Integer> ppid, int kill) {
        int n = pid.size();
        for (int i = 0; i < n; ++i) {
            g.computeIfAbsent(ppid.get(i), k -> new ArrayList<>()).add(pid.get(i));
        }
        dfs(kill);
        return ans;
    }

    private void dfs(int i) {
        ans.add(i);
        for (int j : g.getOrDefault(i, Collections.emptyList())) {
            dfs(j);
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> g;
        int n = pid.size();
        for (int i = 0; i < n; ++i) {
            g[ppid[i]].push_back(pid[i]);
        }
        vector<int> ans;
        function<void(int)> dfs = [&](int i) {
            ans.push_back(i);
            for (int j : g[i]) {
                dfs(j);
            }
        };
        dfs(kill);
        return ans;
    }
};
```

#### Go

```go
func killProcess(pid []int, ppid []int, kill int) (ans []int) {
	g := map[int][]int{}
	for i, p := range ppid {
		g[p] = append(g[p], pid[i])
	}
	var dfs func(int)
	dfs = func(i int) {
		ans = append(ans, i)
		for _, j := range g[i] {
			dfs(j)
		}
	}
	dfs(kill)
	return
}
```

#### TypeScript

```ts
function killProcess(pid: number[], ppid: number[], kill: number): number[] {
    const g: Map<number, number[]> = new Map();
    for (let i = 0; i < pid.length; ++i) {
        if (!g.has(ppid[i])) {
            g.set(ppid[i], []);
        }
        g.get(ppid[i])?.push(pid[i]);
    }
    const ans: number[] = [];
    const dfs = (i: number) => {
        ans.push(i);
        for (const j of g.get(i) ?? []) {
            dfs(j);
        }
    };
    dfs(kill);
    return ans;
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn kill_process(pid: Vec<i32>, ppid: Vec<i32>, kill: i32) -> Vec<i32> {
        let mut g: HashMap<i32, Vec<i32>> = HashMap::new();
        let mut ans: Vec<i32> = Vec::new();

        let n = pid.len();
        for i in 0..n {
            g.entry(ppid[i]).or_insert(Vec::new()).push(pid[i]);
        }

        Self::dfs(&mut ans, &g, kill);
        ans
    }

    fn dfs(ans: &mut Vec<i32>, g: &HashMap<i32, Vec<i32>>, i: i32) {
        ans.push(i);
        if let Some(children) = g.get(&i) {
            for &j in children {
                Self::dfs(ans, g, j);
            }
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [583. 两个字符串的删除操作](https://leetcode.cn/problems/delete-operation-for-two-strings){#583}

{{< tabs "583" >}}

{{% tab "python" %}}
```python
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        m, n = len(word1), len(word2)
        f = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(1, m + 1):
            f[i][0] = i
        for j in range(1, n + 1):
            f[0][j] = j
        for i, a in enumerate(word1, 1):
            for j, b in enumerate(word2, 1):
                if a == b:
                    f[i][j] = f[i - 1][j - 1]
                else:
                    f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1
        return f[m][n]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minDistance(String word1, String word2) {
        int m = word1.length(), n = word2.length();
        int[][] f = new int[m + 1][n + 1];
        for (int i = 0; i <= m; ++i) {
            f[i][0] = i;
        }
        for (int j = 0; j <= n; ++j) {
            f[0][j] = j;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                char a = word1.charAt(i - 1);
                char b = word2.charAt(j - 1);
                if (a == b) {
                    f[i][j] = f[i - 1][j - 1];
                } else {
                    f[i][j] = Math.min(f[i - 1][j], f[i][j - 1]) + 1;
                }
            }
        }
        return f[m][n];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        for (int i = 0; i <= m; ++i) {
            f[i][0] = i;
        }
        for (int j = 0; j <= n; ++j) {
            f[0][j] = j;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                char a = word1[i - 1];
                char b = word2[j - 1];
                if (a == b) {
                    f[i][j] = f[i - 1][j - 1];
                } else {
                    f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
                }
            }
        }
        return f[m][n];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minDistance(word1 string, word2 string) int {
	m, n := len(word1), len(word2)
	f := make([][]int, m+1)
	for i := range f {
		f[i] = make([]int, n+1)
        f[i][0] = i
	}
	for j := 1; j <= n; j++ {
		f[0][j] = j
	}
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			a, b := word1[i-1], word2[j-1]
			if a == b {
				f[i][j] = f[i-1][j-1]
			} else {
				f[i][j] = 1 + min(f[i-1][j], f[i][j-1])
			}
		}
	}
	return f[m][n]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minDistance(word1: string, word2: string): number {
    const m = word1.length;
    const n = word2.length;
    const f: number[][] = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
    for (let i = 1; i <= m; ++i) {
        f[i][0] = i;
    }
    for (let j = 1; j <= n; ++j) {
        f[0][j] = j;
    }
    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            if (word1[i - 1] === word2[j - 1]) {
                f[i][j] = f[i - 1][j - 1];
            } else {
                f[i][j] = Math.min(f[i - 1][j], f[i][j - 1]) + 1;
            }
        }
    }
    return f[m][n];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn min_distance(word1: String, word2: String) -> i32 {
        let m = word1.len();
        let n = word2.len();
        let s: Vec<char> = word1.chars().collect();
        let t: Vec<char> = word2.chars().collect();
        let mut f = vec![vec![0; n + 1]; m + 1];

        for i in 0..=m {
            f[i][0] = i as i32;
        }
        for j in 0..=n {
            f[0][j] = j as i32;
        }

        for i in 1..=m {
            for j in 1..=n {
                let a = s[i - 1];
                let b = t[j - 1];
                if a == b {
                    f[i][j] = f[i - 1][j - 1];
                } else {
                    f[i][j] = std::cmp::min(f[i - 1][j], f[i][j - 1]) + 1;
                }
            }
        }
        f[m][n]
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定两个单词&nbsp;<code>word1</code>&nbsp;和<meta charset="UTF-8" />&nbsp;<code>word2</code>&nbsp;，返回使得<meta charset="UTF-8" />&nbsp;<code>word1</code>&nbsp;和&nbsp;<meta charset="UTF-8" />&nbsp;<code>word2</code><em>&nbsp;</em><strong>相同</strong>所需的<strong>最小步数</strong>。</p>

<p><strong>每步&nbsp;</strong>可以删除任意一个字符串中的一个字符。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入:</strong> word1 = "sea", word2 = "eat"
<strong>输出:</strong> 2
<strong>解释:</strong> 第一步将 "sea" 变为 "ea" ，第二步将 "eat "变为 "ea"
</pre>

<p><strong>示例 &nbsp;2:</strong></p>

<pre>
<b>输入：</b>word1 = "leetcode", word2 = "etco"
<b>输出：</b>4
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>
<meta charset="UTF-8" />

<ul>
	<li><code>1 &lt;= word1.length, word2.length &lt;= 500</code></li>
	<li><code>word1</code>&nbsp;和&nbsp;<code>word2</code>&nbsp;只包含小写英文字母</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示使得字符串 $\textit{word1}$ 的前 $i$ 个字符和字符串 $\textit{word2}$ 的前 $j$ 个字符相同的最小删除步数。那么答案为 $f[m][n]$，其中 $m$ 和 $n$ 分别是字符串 $\textit{word1}$ 和 $\textit{word2}$ 的长度。

初始时，如果 $j = 0$，那么 $f[i][0] = i$；如果 $i = 0$，那么 $f[0][j] = j$。

当 $i, j > 0$ 时，如果 $\textit{word1}[i - 1] = \textit{word2}[j - 1]$，那么 $f[i][j] = f[i - 1][j - 1]$；否则 $f[i][j] = \min(f[i - 1][j], f[i][j - 1]) + 1$。

最终返回 $f[m][n]$ 即可。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是字符串 $\textit{word1}$ 和 $\textit{word2}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        m, n = len(word1), len(word2)
        f = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(1, m + 1):
            f[i][0] = i
        for j in range(1, n + 1):
            f[0][j] = j
        for i, a in enumerate(word1, 1):
            for j, b in enumerate(word2, 1):
                if a == b:
                    f[i][j] = f[i - 1][j - 1]
                else:
                    f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1
        return f[m][n]
```

#### Java

```java
class Solution {
    public int minDistance(String word1, String word2) {
        int m = word1.length(), n = word2.length();
        int[][] f = new int[m + 1][n + 1];
        for (int i = 0; i <= m; ++i) {
            f[i][0] = i;
        }
        for (int j = 0; j <= n; ++j) {
            f[0][j] = j;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                char a = word1.charAt(i - 1);
                char b = word2.charAt(j - 1);
                if (a == b) {
                    f[i][j] = f[i - 1][j - 1];
                } else {
                    f[i][j] = Math.min(f[i - 1][j], f[i][j - 1]) + 1;
                }
            }
        }
        return f[m][n];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        for (int i = 0; i <= m; ++i) {
            f[i][0] = i;
        }
        for (int j = 0; j <= n; ++j) {
            f[0][j] = j;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                char a = word1[i - 1];
                char b = word2[j - 1];
                if (a == b) {
                    f[i][j] = f[i - 1][j - 1];
                } else {
                    f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
                }
            }
        }
        return f[m][n];
    }
};
```

#### Go

```go
func minDistance(word1 string, word2 string) int {
	m, n := len(word1), len(word2)
	f := make([][]int, m+1)
	for i := range f {
		f[i] = make([]int, n+1)
        f[i][0] = i
	}
	for j := 1; j <= n; j++ {
		f[0][j] = j
	}
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			a, b := word1[i-1], word2[j-1]
			if a == b {
				f[i][j] = f[i-1][j-1]
			} else {
				f[i][j] = 1 + min(f[i-1][j], f[i][j-1])
			}
		}
	}
	return f[m][n]
}
```

#### TypeScript

```ts
function minDistance(word1: string, word2: string): number {
    const m = word1.length;
    const n = word2.length;
    const f: number[][] = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
    for (let i = 1; i <= m; ++i) {
        f[i][0] = i;
    }
    for (let j = 1; j <= n; ++j) {
        f[0][j] = j;
    }
    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            if (word1[i - 1] === word2[j - 1]) {
                f[i][j] = f[i - 1][j - 1];
            } else {
                f[i][j] = Math.min(f[i - 1][j], f[i][j - 1]) + 1;
            }
        }
    }
    return f[m][n];
}
```

#### Rust

```rust
impl Solution {
    pub fn min_distance(word1: String, word2: String) -> i32 {
        let m = word1.len();
        let n = word2.len();
        let s: Vec<char> = word1.chars().collect();
        let t: Vec<char> = word2.chars().collect();
        let mut f = vec![vec![0; n + 1]; m + 1];

        for i in 0..=m {
            f[i][0] = i as i32;
        }
        for j in 0..=n {
            f[0][j] = j as i32;
        }

        for i in 1..=m {
            for j in 1..=n {
                let a = s[i - 1];
                let b = t[j - 1];
                if a == b {
                    f[i][j] = f[i - 1][j - 1];
                } else {
                    f[i][j] = std::cmp::min(f[i - 1][j], f[i][j - 1]) + 1;
                }
            }
        }
        f[m][n]
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [584. 寻找用户推荐人](https://leetcode.cn/problems/find-customer-referee){#584}

{{< tabs "584" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT name
FROM Customer
WHERE IFNULL(referee_id, 0) != 2;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表:&nbsp;<code>Customer</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
| referee_id  | int     |
+-------------+---------+
在 SQL 中，id 是该表的主键列。
该表的每一行表示一个客户的 id、姓名以及推荐他们的客户的 id。</pre>

<p>找出以下客户的姓名：</p>

<ol>
	<li><strong>被任何</strong>&nbsp;<code>id != 2</code>&nbsp;的用户推荐。</li>
	<li><strong>没有被</strong>&nbsp;任何用户推荐。</li>
</ol>

<p>以 <strong>任意顺序</strong> 返回结果表。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b> 
Customer 表:
+----+------+------------+
| id | name | referee_id |
+----+------+------------+
| 1  | Will | null       |
| 2  | Jane | null       |
| 3  | Alex | 2          |
| 4  | Bill | null       |
| 5  | Zack | 1          |
| 6  | Mark | 2          |
+----+------+------------+
<b>输出：</b>
+------+
| name |
+------+
| Will |
| Jane |
| Bill |
| Zack |
+------+</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：条件过滤

我们可以直接筛选出 `referee_id` 不为 `2` 的客户姓名。注意，`referee_id` 为 `NULL` 的客户也应该被筛选出来。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT name
FROM Customer
WHERE IFNULL(referee_id, 0) != 2;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [585. 2016年的投资](https://leetcode.cn/problems/investments-in-2016){#585}

{{< tabs "585" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            tiv_2016,
            COUNT(1) OVER (PARTITION BY tiv_2015) AS cnt1,
            COUNT(1) OVER (PARTITION BY lat, lon) AS cnt2
        FROM Insurance
    )
SELECT ROUND(SUM(tiv_2016), 2) AS tiv_2016
FROM T
WHERE cnt1 > 1 AND cnt2 = 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><code>Insurance</code> 表：</p>

<div class="original__bRMd">
<div>
<pre>
+-------------+-------+
| Column Name | Type  |
+-------------+-------+
| pid         | int   |
| tiv_2015    | float |
| tiv_2016    | float |
| lat         | float |
| lon         | float |
+-------------+-------+
pid 是这张表的主键(具有唯一值的列)。
表中的每一行都包含一条保险信息，其中：
pid 是投保人的投保编号。
tiv_2015 是该投保人在 2015 年的总投保金额，tiv_2016 是该投保人在 2016 年的总投保金额。
lat 是投保人所在城市的纬度。题目数据确保 lat 不为空。
lon 是投保人所在城市的经度。题目数据确保 lon 不为空。</pre>

<p>&nbsp;</p>

<p>编写解决方案报告 2016 年 (<code>tiv_2016</code>) 所有满足下述条件的投保人的投保金额之和：</p>

<ul>
	<li>他在 2015 年的投保额&nbsp;(<code>tiv_2015</code>) 至少跟一个其他投保人在 2015 年的投保额相同。</li>
	<li>他所在的城市必须与其他投保人都不同（也就是说&nbsp;(<code>lat, lon</code>) 不能跟其他任何一个投保人完全相同）。</li>
</ul>

<p><code>tiv_2016</code> 四舍五入的 <strong>两位小数</strong> 。</p>

<p>查询结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Insurance 表：
+-----+----------+----------+-----+-----+
| pid | tiv_2015 | tiv_2016 | lat | lon |
+-----+----------+----------+-----+-----+
| 1   | 10       | 5        | 10  | 10  |
| 2   | 20       | 20       | 20  | 20  |
| 3   | 10       | 30       | 20  | 20  |
| 4   | 10       | 40       | 40  | 40  |
+-----+----------+----------+-----+-----+
<strong>输出：</strong>
+----------+
| tiv_2016 |
+----------+
| 45.00    |
+----------+
<strong>解释：
</strong>表中的第一条记录和最后一条记录都满足两个条件。
tiv_2015 值为 10 与第三条和第四条记录相同，且其位置是唯一的。

第二条记录不符合任何一个条件。其 tiv_2015 与其他投保人不同，并且位置与第三条记录相同，这也导致了第三条记录不符合题目要求。
因此，结果是第一条记录和最后一条记录的 tiv_2016 之和，即 45 。</pre>
</div>
</div>

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
            tiv_2016,
            COUNT(1) OVER (PARTITION BY tiv_2015) AS cnt1,
            COUNT(1) OVER (PARTITION BY lat, lon) AS cnt2
        FROM Insurance
    )
SELECT ROUND(SUM(tiv_2016), 2) AS tiv_2016
FROM T
WHERE cnt1 > 1 AND cnt2 = 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [586. 订单最多的客户](https://leetcode.cn/problems/customer-placing-the-largest-number-of-orders){#586}

{{< tabs "586" >}}

{{% tab "sql" %}}
```sql
/* Write your T-SQL query statement below */
SELECT TOP 1
    customer_number
FROM
    orders
GROUP BY customer_number
ORDER BY COUNT(customer_number) DESC;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表:&nbsp;<code>Orders</code></p>

<pre>
+-----------------+----------+
| Column Name     | Type     |
+-----------------+----------+
| order_number    | int      |
| customer_number | int      |
+-----------------+----------+
在 SQL 中，Order_number是该表的主键。
此表包含关于订单ID和客户ID的信息。
</pre>

<p>&nbsp;</p>

<p>查找下了 <strong>最多订单</strong>&nbsp;的客户的 <code>customer_number</code> 。</p>

<p>测试用例生成后， <strong>恰好有一个客户</strong> 比任何其他客户下了更多的订单。</p>

<p>查询结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
Orders 表:
+--------------+-----------------+
| order_number | customer_number |
+--------------+-----------------+
| 1            | 1               |
| 2            | 2               |
| 3            | 3               |
| 4            | 3               |
+--------------+-----------------+
<strong>输出:</strong> 
+-----------------+
| customer_number |
+-----------------+
| 3               |
+-----------------+
<strong>解释:</strong> 
customer_number 为 '3' 的顾客有两个订单，比顾客 '1' 或者 '2' 都要多，因为他们只有一个订单。
所以结果是该顾客的 customer_number ，也就是 3 。
</pre>

<p>&nbsp;</p>

<p><strong>进阶：</strong> 如果有多位顾客订单数并列最多，你能找到他们所有的 <code>customer_number</code> 吗？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分组 + 排序

我们可以使用 `GROUP BY` 将数据按照 `customer_number` 进行分组，然后按照 `count(1)` 进行降序排序，最后取第一条记录的 `customer_number` 即可。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    customer_number
FROM orders
GROUP BY customer_number
ORDER BY COUNT(1) DESC
LIMIT 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### MySQL

```sql
/* Write your T-SQL query statement below */
SELECT TOP 1
    customer_number
FROM
    orders
GROUP BY customer_number
ORDER BY COUNT(customer_number) DESC;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [587. 安装栅栏](https://leetcode.cn/problems/erect-the-fence){#587}

{{< tabs "587" >}}

{{% tab "python" %}}
```python
class Solution:
    def outerTrees(self, trees: List[List[int]]) -> List[List[int]]:
        def cross(i, j, k):
            a, b, c = trees[i], trees[j], trees[k]
            return (b[0] - a[0]) * (c[1] - b[1]) - (b[1] - a[1]) * (c[0] - b[0])

        n = len(trees)
        if n < 4:
            return trees
        trees.sort()
        vis = [False] * n
        stk = [0]
        for i in range(1, n):
            while len(stk) > 1 and cross(stk[-2], stk[-1], i) < 0:
                vis[stk.pop()] = False
            vis[i] = True
            stk.append(i)
        m = len(stk)
        for i in range(n - 2, -1, -1):
            if vis[i]:
                continue
            while len(stk) > m and cross(stk[-2], stk[-1], i) < 0:
                stk.pop()
            stk.append(i)
        stk.pop()
        return [trees[i] for i in stk]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[][] outerTrees(int[][] trees) {
        int n = trees.length;
        if (n < 4) {
            return trees;
        }
        Arrays.sort(trees, (a, b) -> { return a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]; });
        boolean[] vis = new boolean[n];
        int[] stk = new int[n + 10];
        int cnt = 1;
        for (int i = 1; i < n; ++i) {
            while (cnt > 1 && cross(trees[stk[cnt - 1]], trees[stk[cnt - 2]], trees[i]) < 0) {
                vis[stk[--cnt]] = false;
            }
            vis[i] = true;
            stk[cnt++] = i;
        }
        int m = cnt;
        for (int i = n - 1; i >= 0; --i) {
            if (vis[i]) {
                continue;
            }
            while (cnt > m && cross(trees[stk[cnt - 1]], trees[stk[cnt - 2]], trees[i]) < 0) {
                --cnt;
            }
            stk[cnt++] = i;
        }
        int[][] ans = new int[cnt - 1][2];
        for (int i = 0; i < ans.length; ++i) {
            ans[i] = trees[stk[i]];
        }
        return ans;
    }

    private int cross(int[] a, int[] b, int[] c) {
        return (b[0] - a[0]) * (c[1] - b[1]) - (b[1] - a[1]) * (c[0] - b[0]);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();
        if (n < 4) return trees;
        sort(trees.begin(), trees.end());
        vector<int> vis(n);
        vector<int> stk(n + 10);
        int cnt = 1;
        for (int i = 1; i < n; ++i) {
            while (cnt > 1 && cross(trees[stk[cnt - 1]], trees[stk[cnt - 2]], trees[i]) < 0) vis[stk[--cnt]] = false;
            vis[i] = true;
            stk[cnt++] = i;
        }
        int m = cnt;
        for (int i = n - 1; i >= 0; --i) {
            if (vis[i]) continue;
            while (cnt > m && cross(trees[stk[cnt - 1]], trees[stk[cnt - 2]], trees[i]) < 0) --cnt;
            stk[cnt++] = i;
        }
        vector<vector<int>> ans;
        for (int i = 0; i < cnt - 1; ++i) ans.push_back(trees[stk[i]]);
        return ans;
    }

    int cross(vector<int>& a, vector<int>& b, vector<int>& c) {
        return (b[0] - a[0]) * (c[1] - b[1]) - (b[1] - a[1]) * (c[0] - b[0]);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func outerTrees(trees [][]int) [][]int {
	n := len(trees)
	if n < 4 {
		return trees
	}
	sort.Slice(trees, func(i, j int) bool {
		if trees[i][0] == trees[j][0] {
			return trees[i][1] < trees[j][1]
		}
		return trees[i][0] < trees[j][0]
	})
	cross := func(i, j, k int) int {
		a, b, c := trees[i], trees[j], trees[k]
		return (b[0]-a[0])*(c[1]-b[1]) - (b[1]-a[1])*(c[0]-b[0])
	}
	vis := make([]bool, n)
	stk := []int{0}
	for i := 1; i < n; i++ {
		for len(stk) > 1 && cross(stk[len(stk)-1], stk[len(stk)-2], i) < 0 {
			vis[stk[len(stk)-1]] = false
			stk = stk[:len(stk)-1]
		}
		vis[i] = true
		stk = append(stk, i)
	}
	m := len(stk)
	for i := n - 1; i >= 0; i-- {
		if vis[i] {
			continue
		}
		for len(stk) > m && cross(stk[len(stk)-1], stk[len(stk)-2], i) < 0 {
			stk = stk[:len(stk)-1]
		}
		stk = append(stk, i)
	}
	var ans [][]int
	for i := 0; i < len(stk)-1; i++ {
		ans = append(ans, trees[stk[i]])
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

<p>给定一个数组 <code>trees</code>，其中 <code>trees[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> 表示树在花园中的位置。</p>

<p>你被要求用最短长度的绳子把整个花园围起来，因为绳子很贵。只有把&nbsp;<strong>所有的树都围起来</strong>，花园才围得很好。</p>

<p>返回<em>恰好位于围栏周边的树木的坐标</em>。</p>

<p><strong>示例 1:</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0587.Erect%20the%20Fence/images/erect2-plane.jpg" style="width: 400px;" /></p>

<pre>
<strong>输入:</strong> points = [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
<strong>输出:</strong> [[1,1],[2,0],[3,3],[2,4],[4,2]]</pre>

<p><strong>示例 2:</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0587.Erect%20the%20Fence/images/erect1-plane.jpg" style="height: 393px; width: 400px;" /></p>

<pre>
<strong>输入:</strong> points = [[1,2],[2,2],[4,2]]
<strong>输出:</strong> [[4,2],[2,2],[1,2]]</pre>

<p>&nbsp;</p>

<p><strong>注意:</strong></p>

<ul>
	<li><code>1 &lt;= points.length &lt;= 3000</code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>0 &lt;= x<sub>i</sub>, y<sub>i</sub>&nbsp;&lt;= 100</code></li>
	<li>
	<p data-group="1-1">所有给定的点都是&nbsp;<strong>唯一&nbsp;</strong>的。</p>
	</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：Andrew 算法

原理：

利用夹角，让整个图形保持左转。先将最左边的前两个点加入栈中，每次加入新点时判断是否左拐（叉积大于 0），如果是就将新点直接加入；如果不是，就弹出栈顶，直到左拐，将新点加入栈中。

流程：

1. 将所有点 `(x, y)` 进行排序，以 x 为第一关键字，y 为第二关键字升序排序；
1. 先从左至右维护凸包的下半部分，然后再从右至左维护上半部分；
1. 将第一个点放入栈中，这个点一定时凸包的最左边的点了，是不会清理掉的，然后再将第二个点放入栈中。当栈中元素大于等于 2 的时候，就要判断栈顶元素是否还要保留：
    - 如果新点在栈顶元素和次栈顶元素所组成的直线的逆时针方向上，那么直接将新点加入栈中；
    - 否则，将栈顶元素不断弹出，直至新点的位置出现在栈顶元素与次栈顶元素所在直线的逆时针方向。

这个过程，是从左往右走的，并且得到的凸包是凸壳的下半部分。求上半部分的时候，从右往左遍历。

时间复杂度 O(nlogn)。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def outerTrees(self, trees: List[List[int]]) -> List[List[int]]:
        def cross(i, j, k):
            a, b, c = trees[i], trees[j], trees[k]
            return (b[0] - a[0]) * (c[1] - b[1]) - (b[1] - a[1]) * (c[0] - b[0])

        n = len(trees)
        if n < 4:
            return trees
        trees.sort()
        vis = [False] * n
        stk = [0]
        for i in range(1, n):
            while len(stk) > 1 and cross(stk[-2], stk[-1], i) < 0:
                vis[stk.pop()] = False
            vis[i] = True
            stk.append(i)
        m = len(stk)
        for i in range(n - 2, -1, -1):
            if vis[i]:
                continue
            while len(stk) > m and cross(stk[-2], stk[-1], i) < 0:
                stk.pop()
            stk.append(i)
        stk.pop()
        return [trees[i] for i in stk]
```

#### Java

```java
class Solution {
    public int[][] outerTrees(int[][] trees) {
        int n = trees.length;
        if (n < 4) {
            return trees;
        }
        Arrays.sort(trees, (a, b) -> { return a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]; });
        boolean[] vis = new boolean[n];
        int[] stk = new int[n + 10];
        int cnt = 1;
        for (int i = 1; i < n; ++i) {
            while (cnt > 1 && cross(trees[stk[cnt - 1]], trees[stk[cnt - 2]], trees[i]) < 0) {
                vis[stk[--cnt]] = false;
            }
            vis[i] = true;
            stk[cnt++] = i;
        }
        int m = cnt;
        for (int i = n - 1; i >= 0; --i) {
            if (vis[i]) {
                continue;
            }
            while (cnt > m && cross(trees[stk[cnt - 1]], trees[stk[cnt - 2]], trees[i]) < 0) {
                --cnt;
            }
            stk[cnt++] = i;
        }
        int[][] ans = new int[cnt - 1][2];
        for (int i = 0; i < ans.length; ++i) {
            ans[i] = trees[stk[i]];
        }
        return ans;
    }

    private int cross(int[] a, int[] b, int[] c) {
        return (b[0] - a[0]) * (c[1] - b[1]) - (b[1] - a[1]) * (c[0] - b[0]);
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();
        if (n < 4) return trees;
        sort(trees.begin(), trees.end());
        vector<int> vis(n);
        vector<int> stk(n + 10);
        int cnt = 1;
        for (int i = 1; i < n; ++i) {
            while (cnt > 1 && cross(trees[stk[cnt - 1]], trees[stk[cnt - 2]], trees[i]) < 0) vis[stk[--cnt]] = false;
            vis[i] = true;
            stk[cnt++] = i;
        }
        int m = cnt;
        for (int i = n - 1; i >= 0; --i) {
            if (vis[i]) continue;
            while (cnt > m && cross(trees[stk[cnt - 1]], trees[stk[cnt - 2]], trees[i]) < 0) --cnt;
            stk[cnt++] = i;
        }
        vector<vector<int>> ans;
        for (int i = 0; i < cnt - 1; ++i) ans.push_back(trees[stk[i]]);
        return ans;
    }

    int cross(vector<int>& a, vector<int>& b, vector<int>& c) {
        return (b[0] - a[0]) * (c[1] - b[1]) - (b[1] - a[1]) * (c[0] - b[0]);
    }
};
```

#### Go

```go
func outerTrees(trees [][]int) [][]int {
	n := len(trees)
	if n < 4 {
		return trees
	}
	sort.Slice(trees, func(i, j int) bool {
		if trees[i][0] == trees[j][0] {
			return trees[i][1] < trees[j][1]
		}
		return trees[i][0] < trees[j][0]
	})
	cross := func(i, j, k int) int {
		a, b, c := trees[i], trees[j], trees[k]
		return (b[0]-a[0])*(c[1]-b[1]) - (b[1]-a[1])*(c[0]-b[0])
	}
	vis := make([]bool, n)
	stk := []int{0}
	for i := 1; i < n; i++ {
		for len(stk) > 1 && cross(stk[len(stk)-1], stk[len(stk)-2], i) < 0 {
			vis[stk[len(stk)-1]] = false
			stk = stk[:len(stk)-1]
		}
		vis[i] = true
		stk = append(stk, i)
	}
	m := len(stk)
	for i := n - 1; i >= 0; i-- {
		if vis[i] {
			continue
		}
		for len(stk) > m && cross(stk[len(stk)-1], stk[len(stk)-2], i) < 0 {
			stk = stk[:len(stk)-1]
		}
		stk = append(stk, i)
	}
	var ans [][]int
	for i := 0; i < len(stk)-1; i++ {
		ans = append(ans, trees[stk[i]])
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [588. 设计内存文件系统 🔒](https://leetcode.cn/problems/design-in-memory-file-system){#588}

{{< tabs "588" >}}

{{% tab "python" %}}
```python
class Trie:
    def __init__(self):
        self.name = None
        self.isFile = False
        self.content = []
        self.children = {}

    def insert(self, path, isFile):
        node = self
        ps = path.split('/')
        for p in ps[1:]:
            if p not in node.children:
                node.children[p] = Trie()
            node = node.children[p]
        node.isFile = isFile
        if isFile:
            node.name = ps[-1]
        return node

    def search(self, path):
        node = self
        if path == '/':
            return node
        ps = path.split('/')
        for p in ps[1:]:
            if p not in node.children:
                return None
            node = node.children[p]
        return node


class FileSystem:
    def __init__(self):
        self.root = Trie()

    def ls(self, path: str) -> List[str]:
        node = self.root.search(path)
        if node is None:
            return []
        if node.isFile:
            return [node.name]
        return sorted(node.children.keys())

    def mkdir(self, path: str) -> None:
        self.root.insert(path, False)

    def addContentToFile(self, filePath: str, content: str) -> None:
        node = self.root.insert(filePath, True)
        node.content.append(content)

    def readContentFromFile(self, filePath: str) -> str:
        node = self.root.search(filePath)
        return ''.join(node.content)


# Your FileSystem object will be instantiated and called as such:
# obj = FileSystem()
# param_1 = obj.ls(path)
# obj.mkdir(path)
# obj.addContentToFile(filePath,content)
# param_4 = obj.readContentFromFile(filePath)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Trie {
    String name;
    boolean isFile;
    StringBuilder content = new StringBuilder();
    Map<String, Trie> children = new HashMap<>();

    Trie insert(String path, boolean isFile) {
        Trie node = this;
        String[] ps = path.split("/");
        for (int i = 1; i < ps.length; ++i) {
            String p = ps[i];
            if (!node.children.containsKey(p)) {
                node.children.put(p, new Trie());
            }
            node = node.children.get(p);
        }
        node.isFile = isFile;
        if (isFile) {
            node.name = ps[ps.length - 1];
        }
        return node;
    }

    Trie search(String path) {
        Trie node = this;
        String[] ps = path.split("/");
        for (int i = 1; i < ps.length; ++i) {
            String p = ps[i];
            if (!node.children.containsKey(p)) {
                return null;
            }
            node = node.children.get(p);
        }
        return node;
    }
}

class FileSystem {
    private Trie root = new Trie();

    public FileSystem() {
    }

    public List<String> ls(String path) {
        List<String> ans = new ArrayList<>();
        Trie node = root.search(path);
        if (node == null) {
            return ans;
        }
        if (node.isFile) {
            ans.add(node.name);
            return ans;
        }
        for (String v : node.children.keySet()) {
            ans.add(v);
        }
        Collections.sort(ans);
        return ans;
    }

    public void mkdir(String path) {
        root.insert(path, false);
    }

    public void addContentToFile(String filePath, String content) {
        Trie node = root.insert(filePath, true);
        node.content.append(content);
    }

    public String readContentFromFile(String filePath) {
        Trie node = root.search(filePath);
        return node.content.toString();
    }
}

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem obj = new FileSystem();
 * List<String> param_1 = obj.ls(path);
 * obj.mkdir(path);
 * obj.addContentToFile(filePath,content);
 * String param_4 = obj.readContentFromFile(filePath);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Trie struct {
	name     string
	isFile   bool
	content  strings.Builder
	children map[string]*Trie
}

func newTrie() *Trie {
	m := map[string]*Trie{}
	return &Trie{children: m}
}

func (this *Trie) insert(path string, isFile bool) *Trie {
	node := this
	ps := strings.Split(path, "/")
	for _, p := range ps[1:] {
		if _, ok := node.children[p]; !ok {
			node.children[p] = newTrie()
		}
		node, _ = node.children[p]
	}
	node.isFile = isFile
	if isFile {
		node.name = ps[len(ps)-1]
	}
	return node
}

func (this *Trie) search(path string) *Trie {
	if path == "/" {
		return this
	}
	node := this
	ps := strings.Split(path, "/")
	for _, p := range ps[1:] {
		if _, ok := node.children[p]; !ok {
			return nil
		}
		node, _ = node.children[p]
	}
	return node
}

type FileSystem struct {
	root *Trie
}

func Constructor() FileSystem {
	root := newTrie()
	return FileSystem{root}
}

func (this *FileSystem) Ls(path string) []string {
	var ans []string
	node := this.root.search(path)
	if node == nil {
		return ans
	}
	if node.isFile {
		ans = append(ans, node.name)
		return ans
	}
	for v := range node.children {
		ans = append(ans, v)
	}
	sort.Strings(ans)
	return ans
}

func (this *FileSystem) Mkdir(path string) {
	this.root.insert(path, false)
}

func (this *FileSystem) AddContentToFile(filePath string, content string) {
	node := this.root.insert(filePath, true)
	node.content.WriteString(content)
}

func (this *FileSystem) ReadContentFromFile(filePath string) string {
	node := this.root.search(filePath)
	return node.content.String()
}

/**
 * Your FileSystem object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Ls(path);
 * obj.Mkdir(path);
 * obj.AddContentToFile(filePath,content);
 * param_4 := obj.ReadContentFromFile(filePath);
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>设计一个内存文件系统，模拟以下功能：</p>

<p>实现文件系统类:</p>

<ul>
	<li><code>FileSystem()</code>&nbsp;初始化系统对象</li>
	<li><code>List&lt;String&gt; ls(String path)</code>
	<ul>
		<li>如果 <code>path</code> 是一个文件路径，则返回一个仅包含该文件名称的列表。</li>
		<li>如果 <code>path</code> 是一个目录路径，则返回该目录中文件和 <strong>目录名</strong> 的列表。</li>
	</ul>
	</li>
</ul>

<p>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; 答案应该 按<strong>字典顺序</strong> 排列。</p>

<ul>
	<li><code>void mkdir(String path)</code>&nbsp;根据给定的路径创建一个新目录。给定的目录路径不存在。如果路径中的中间目录不存在，您也应该创建它们。</li>
	<li><code>void addContentToFile(String filePath, String content)</code>
	<ul>
		<li>如果 <code>filePath</code> 不存在，则创建包含给定内容&nbsp;<code>content</code>的文件。</li>
		<li>如果 <code>filePath</code> 已经存在，将给定的内容&nbsp;<code>content</code>附加到原始内容。</li>
	</ul>
	</li>
	<li><code>String readContentFromFile(String filePath)</code>&nbsp;返回 <code>filePath</code>下的文件内容。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0588.Design%20In-Memory%20File%20System/images/filesystem.png" style="height: 315px; width: 650px;" /></p>

<pre>
<strong>输入:</strong> 
["FileSystem","ls","mkdir","addContentToFile","ls","readContentFromFile"]
[[],["/"],["/a/b/c"],["/a/b/c/d","hello"],["/"],["/a/b/c/d"]]
<strong>输出:</strong>
[null,[],null,null,["a"],"hello"]

<strong>解释:</strong>
FileSystem fileSystem = new FileSystem();
fileSystem.ls("/");                         // 返回 []
fileSystem.mkdir("/a/b/c");
fileSystem.addContentToFile("/a/b/c/d", "hello");
fileSystem.ls("/");                         // 返回 ["a"]
fileSystem.readContentFromFile("/a/b/c/d"); // 返回 "hello"</pre>

<p>&nbsp;</p>

<p><strong>注意:</strong></p>

<ul>
	<li><code>1 &lt;= path.length,&nbsp;filePath.length &lt;= 100</code></li>
	<li><code>path</code>&nbsp;和&nbsp;<code>filePath</code>&nbsp;都是绝对路径，除非是根目录&nbsp;<code>‘/’</code>&nbsp;自身，其他路径都是以&nbsp;<code>‘/’</code>&nbsp;开头且 <strong>不</strong> 以&nbsp;<code>‘/’</code>&nbsp;结束。</li>
	<li>你可以假定所有操作的参数都是有效的，即用户不会获取不存在文件的内容，或者获取不存在文件夹和文件的列表。</li>
	<li>你可以假定所有文件夹名字和文件名字都只包含小写字母，且同一文件夹下不会有相同名字的文件夹或文件。</li>
	<li>你可以假定&nbsp;<code>addContentToFile</code> 中的文件的父目录都存在。</li>
	<li><code>1 &lt;= content.length &lt;= 50</code></li>
	<li><code>ls</code>,&nbsp;<code>mkdir</code>,&nbsp;<code>addContentToFile</code>, and&nbsp;<code>readContentFromFile</code>&nbsp;最多被调用&nbsp;<code>300</code>&nbsp;次</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀树

哈希表实现前缀树。

<!-- tabs:start -->

#### Python3

```python
class Trie:
    def __init__(self):
        self.name = None
        self.isFile = False
        self.content = []
        self.children = {}

    def insert(self, path, isFile):
        node = self
        ps = path.split('/')
        for p in ps[1:]:
            if p not in node.children:
                node.children[p] = Trie()
            node = node.children[p]
        node.isFile = isFile
        if isFile:
            node.name = ps[-1]
        return node

    def search(self, path):
        node = self
        if path == '/':
            return node
        ps = path.split('/')
        for p in ps[1:]:
            if p not in node.children:
                return None
            node = node.children[p]
        return node


class FileSystem:
    def __init__(self):
        self.root = Trie()

    def ls(self, path: str) -> List[str]:
        node = self.root.search(path)
        if node is None:
            return []
        if node.isFile:
            return [node.name]
        return sorted(node.children.keys())

    def mkdir(self, path: str) -> None:
        self.root.insert(path, False)

    def addContentToFile(self, filePath: str, content: str) -> None:
        node = self.root.insert(filePath, True)
        node.content.append(content)

    def readContentFromFile(self, filePath: str) -> str:
        node = self.root.search(filePath)
        return ''.join(node.content)


# Your FileSystem object will be instantiated and called as such:
# obj = FileSystem()
# param_1 = obj.ls(path)
# obj.mkdir(path)
# obj.addContentToFile(filePath,content)
# param_4 = obj.readContentFromFile(filePath)
```

#### Java

```java
class Trie {
    String name;
    boolean isFile;
    StringBuilder content = new StringBuilder();
    Map<String, Trie> children = new HashMap<>();

    Trie insert(String path, boolean isFile) {
        Trie node = this;
        String[] ps = path.split("/");
        for (int i = 1; i < ps.length; ++i) {
            String p = ps[i];
            if (!node.children.containsKey(p)) {
                node.children.put(p, new Trie());
            }
            node = node.children.get(p);
        }
        node.isFile = isFile;
        if (isFile) {
            node.name = ps[ps.length - 1];
        }
        return node;
    }

    Trie search(String path) {
        Trie node = this;
        String[] ps = path.split("/");
        for (int i = 1; i < ps.length; ++i) {
            String p = ps[i];
            if (!node.children.containsKey(p)) {
                return null;
            }
            node = node.children.get(p);
        }
        return node;
    }
}

class FileSystem {
    private Trie root = new Trie();

    public FileSystem() {
    }

    public List<String> ls(String path) {
        List<String> ans = new ArrayList<>();
        Trie node = root.search(path);
        if (node == null) {
            return ans;
        }
        if (node.isFile) {
            ans.add(node.name);
            return ans;
        }
        for (String v : node.children.keySet()) {
            ans.add(v);
        }
        Collections.sort(ans);
        return ans;
    }

    public void mkdir(String path) {
        root.insert(path, false);
    }

    public void addContentToFile(String filePath, String content) {
        Trie node = root.insert(filePath, true);
        node.content.append(content);
    }

    public String readContentFromFile(String filePath) {
        Trie node = root.search(filePath);
        return node.content.toString();
    }
}

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem obj = new FileSystem();
 * List<String> param_1 = obj.ls(path);
 * obj.mkdir(path);
 * obj.addContentToFile(filePath,content);
 * String param_4 = obj.readContentFromFile(filePath);
 */
```

#### Go

```go
type Trie struct {
	name     string
	isFile   bool
	content  strings.Builder
	children map[string]*Trie
}

func newTrie() *Trie {
	m := map[string]*Trie{}
	return &Trie{children: m}
}

func (this *Trie) insert(path string, isFile bool) *Trie {
	node := this
	ps := strings.Split(path, "/")
	for _, p := range ps[1:] {
		if _, ok := node.children[p]; !ok {
			node.children[p] = newTrie()
		}
		node, _ = node.children[p]
	}
	node.isFile = isFile
	if isFile {
		node.name = ps[len(ps)-1]
	}
	return node
}

func (this *Trie) search(path string) *Trie {
	if path == "/" {
		return this
	}
	node := this
	ps := strings.Split(path, "/")
	for _, p := range ps[1:] {
		if _, ok := node.children[p]; !ok {
			return nil
		}
		node, _ = node.children[p]
	}
	return node
}

type FileSystem struct {
	root *Trie
}

func Constructor() FileSystem {
	root := newTrie()
	return FileSystem{root}
}

func (this *FileSystem) Ls(path string) []string {
	var ans []string
	node := this.root.search(path)
	if node == nil {
		return ans
	}
	if node.isFile {
		ans = append(ans, node.name)
		return ans
	}
	for v := range node.children {
		ans = append(ans, v)
	}
	sort.Strings(ans)
	return ans
}

func (this *FileSystem) Mkdir(path string) {
	this.root.insert(path, false)
}

func (this *FileSystem) AddContentToFile(filePath string, content string) {
	node := this.root.insert(filePath, true)
	node.content.WriteString(content)
}

func (this *FileSystem) ReadContentFromFile(filePath string) string {
	node := this.root.search(filePath)
	return node.content.String()
}

/**
 * Your FileSystem object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Ls(path);
 * obj.Mkdir(path);
 * obj.AddContentToFile(filePath,content);
 * param_4 := obj.ReadContentFromFile(filePath);
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [589. N 叉树的前序遍历](https://leetcode.cn/problems/n-ary-tree-preorder-traversal){#589}

{{< tabs "589" >}}

{{% tab "python" %}}
```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""


class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        ans = []
        if root is None:
            return ans
        stk = [root]
        while stk:
            node = stk.pop()
            ans.append(node.val)
            for child in node.children[::-1]:
                stk.append(child)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public List<Integer> preorder(Node root) {
        if (root == null) {
            return Collections.emptyList();
        }
        List<Integer> ans = new ArrayList<>();
        Deque<Node> stk = new ArrayDeque<>();
        stk.push(root);
        while (!stk.isEmpty()) {
            Node node = stk.pop();
            ans.add(node.val);
            List<Node> children = node.children;
            for (int i = children.size() - 1; i >= 0; --i) {
                stk.push(children.get(i));
            }
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        if (!root) return {};
        vector<int> ans;
        stack<Node*> stk;
        stk.push(root);
        while (!stk.empty()) {
            Node* node = stk.top();
            ans.push_back(node->val);
            stk.pop();
            auto children = node->children;
            for (int i = children.size() - 1; i >= 0; --i) stk.push(children[i]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

func preorder(root *Node) (ans []int) {
	if root == nil {
		return
	}
	stk := []*Node{root}
	for len(stk) > 0 {
		node := stk[len(stk)-1]
		ans = append(ans, node.Val)
		stk = stk[:len(stk)-1]
		children := node.Children
		for i := len(children) - 1; i >= 0; i-- {
			stk = append(stk, children[i])
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for node.
 * class Node {
 *     val: number
 *     children: Node[]
 *     constructor(val?: number) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.children = []
 *     }
 * }
 */

function preorder(root: Node | null): number[] {
    const ans: number[] = [];
    if (!root) {
        return ans;
    }
    const stk: Node[] = [root];
    while (stk.length) {
        const { val, children } = stk.pop()!;
        ans.push(val);
        for (let i = children.length - 1; i >= 0; i--) {
            stk.push(children[i]);
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void dfs(struct Node* root, int* ans, int* i) {
    if (!root) {
        return;
    }
    ans[(*i)++] = root->val;
    for (int j = 0; j < root->numChildren; j++) {
        dfs(root->children[j], ans, i);
    }
}

int* preorder(struct Node* root, int* returnSize) {
    int* ans = malloc(sizeof(int) * 10000);
    *returnSize = 0;
    dfs(root, ans, returnSize);
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个 n&nbsp;叉树的根节点 <meta charset="UTF-8" />&nbsp;<code>root</code>&nbsp;，返回 <em>其节点值的<strong> 前序遍历</strong></em> 。</p>

<p>n 叉树 在输入中按层序遍历进行序列化表示，每组子节点由空值 <code>null</code> 分隔（请参见示例）。</p>

<p><br />
<strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0589.N-ary%20Tree%20Preorder%20Traversal/images/narytreeexample.png" style="height: 193px; width: 300px;" /></p>

<pre>
<strong>输入：</strong>root = [1,null,3,2,4,null,5,6]
<strong>输出：</strong>[1,3,5,6,2,4]
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0589.N-ary%20Tree%20Preorder%20Traversal/images/sample_4_964.png" style="height: 272px; width: 300px;" /></p>

<pre>
<strong>输入：</strong>root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
<strong>输出：</strong>[1,2,3,6,7,11,14,4,8,12,5,9,13,10]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>节点总数在范围<meta charset="UTF-8" />&nbsp;<code>[0, 10<sup>4</sup>]</code>内</li>
	<li><code>0 &lt;= Node.val &lt;= 10<sup>4</sup></code></li>
	<li>n 叉树的高度小于或等于 <code>1000</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>递归法很简单，你可以使用迭代法完成此题吗?</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归

我们可以递归地遍历整棵树。对于每个节点，先将节点的值加入答案，然后对该节点的每个子节点递归地调用函数。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为节点数。

<!-- tabs:start -->

#### Python3

```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""


class Solution:
    def preorder(self, root: "Node") -> List[int]:
        def dfs(root):
            if root is None:
                return
            ans.append(root.val)
            for child in root.children:
                dfs(child)

        ans = []
        dfs(root)
        return ans
```

#### Java

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    private List<Integer> ans = new ArrayList<>();

    public List<Integer> preorder(Node root) {
        dfs(root);
        return ans;
    }

    private void dfs(Node root) {
        if (root == null) {
            return;
        }
        ans.add(root.val);
        for (Node child : root.children) {
            dfs(child);
        }
    }
}
```

#### C++

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        function<void(Node*)> dfs = [&](Node* root) {
            if (!root) {
                return;
            }
            ans.push_back(root->val);
            for (auto& child : root->children) {
                dfs(child);
            }
        };
        dfs(root);
        return ans;
    }
};
```

#### Go

```go
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

func preorder(root *Node) (ans []int) {
	var dfs func(*Node)
	dfs = func(root *Node) {
		if root == nil {
			return
		}
		ans = append(ans, root.Val)
		for _, child := range root.Children {
			dfs(child)
		}
	}
	dfs(root)
	return
}
```

#### TypeScript

```ts
/**
 * Definition for node.
 * class Node {
 *     val: number
 *     children: Node[]
 *     constructor(val?: number) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.children = []
 *     }
 * }
 */

function preorder(root: Node | null): number[] {
    const ans: number[] = [];
    const dfs = (root: Node | null) => {
        if (!root) {
            return;
        }
        ans.push(root.val);
        for (const child of root.children) {
            dfs(child);
        }
    };
    dfs(root);
    return ans;
}
```

#### C

```c
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void dfs(struct Node* root, int* ans, int* i) {
    if (!root) {
        return;
    }
    ans[(*i)++] = root->val;
    for (int j = 0; j < root->numChildren; j++) {
        dfs(root->children[j], ans, i);
    }
}

int* preorder(struct Node* root, int* returnSize) {
    int* ans = malloc(sizeof(int) * 10000);
    *returnSize = 0;
    dfs(root, ans, returnSize);
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：迭代（栈实现）

我们也可以用迭代的方法来解决这个问题。

我们使用一个栈来帮助我们得到前序遍历，我们首先把根节点入栈，因为前序遍历是根节点、左子树、右子树，栈的特点是先进后出，所以我们先把节点的值加入答案，然后对该节点的每个子节点按照从右到左的顺序依次入栈。循环直到栈为空。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为节点数。

<!-- tabs:start -->

#### Python3

```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""


class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        ans = []
        if root is None:
            return ans
        stk = [root]
        while stk:
            node = stk.pop()
            ans.append(node.val)
            for child in node.children[::-1]:
                stk.append(child)
        return ans
```

#### Java

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public List<Integer> preorder(Node root) {
        if (root == null) {
            return Collections.emptyList();
        }
        List<Integer> ans = new ArrayList<>();
        Deque<Node> stk = new ArrayDeque<>();
        stk.push(root);
        while (!stk.isEmpty()) {
            Node node = stk.pop();
            ans.add(node.val);
            List<Node> children = node.children;
            for (int i = children.size() - 1; i >= 0; --i) {
                stk.push(children.get(i));
            }
        }
        return ans;
    }
}
```

#### C++

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        if (!root) return {};
        vector<int> ans;
        stack<Node*> stk;
        stk.push(root);
        while (!stk.empty()) {
            Node* node = stk.top();
            ans.push_back(node->val);
            stk.pop();
            auto children = node->children;
            for (int i = children.size() - 1; i >= 0; --i) stk.push(children[i]);
        }
        return ans;
    }
};
```

#### Go

```go
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

func preorder(root *Node) (ans []int) {
	if root == nil {
		return
	}
	stk := []*Node{root}
	for len(stk) > 0 {
		node := stk[len(stk)-1]
		ans = append(ans, node.Val)
		stk = stk[:len(stk)-1]
		children := node.Children
		for i := len(children) - 1; i >= 0; i-- {
			stk = append(stk, children[i])
		}
	}
	return
}
```

#### TypeScript

```ts
/**
 * Definition for node.
 * class Node {
 *     val: number
 *     children: Node[]
 *     constructor(val?: number) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.children = []
 *     }
 * }
 */

function preorder(root: Node | null): number[] {
    const ans: number[] = [];
    if (!root) {
        return ans;
    }
    const stk: Node[] = [root];
    while (stk.length) {
        const { val, children } = stk.pop()!;
        ans.push(val);
        for (let i = children.length - 1; i >= 0; i--) {
            stk.push(children[i]);
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
