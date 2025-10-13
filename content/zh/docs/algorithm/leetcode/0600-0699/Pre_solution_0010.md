---
title: "0690_员工的重要性"
date: 2025-10-08T18:36:23+08:00
weight: 10
tags: [位运算, 动态规划, 双指针, 哈希函数, 哈希表, 回溯, 堆（优先队列）, 字典树, 字符串, 并查集, 广度优先搜索, 排序, 数组, 有序集合, 树, 桶排序, 深度优先搜索, 状态压缩, 矩阵, 线段树, 计数, 记忆化搜索]
---

{{< markmap >}}
### [0690_员工的重要性](#690)
#### [树](#690)
#### [深度优先搜索](#690)
#### [广度优先搜索](#690)
#### [数组](#690)
#### [哈希表](#690)
### [0691_贴纸拼词](#691)
#### [位运算](#691)
#### [记忆化搜索](#691)
#### [数组](#691)
#### [哈希表](#691)
#### [字符串](#691)
#### [动态规划](#691)
#### [回溯](#691)
#### [状态压缩](#691)
### [0692_前K个高频单词](#692)
#### [字典树](#692)
#### [数组](#692)
#### [哈希表](#692)
#### [字符串](#692)
#### [桶排序](#692)
#### [计数](#692)
#### [排序](#692)
#### [堆（优先队列）](#692)
### [0693_交替位二进制数](#693)
#### [位运算](#693)
### [0694_不同岛屿的数量 🔒](#694)
#### [深度优先搜索](#694)
#### [广度优先搜索](#694)
#### [并查集](#694)
#### [哈希表](#694)
#### [哈希函数](#694)
### [0695_岛屿的最大面积](#695)
#### [深度优先搜索](#695)
#### [广度优先搜索](#695)
#### [并查集](#695)
#### [数组](#695)
#### [矩阵](#695)
### [0696_计数二进制子串](#696)
#### [双指针](#696)
#### [字符串](#696)
### [0697_数组的度](#697)
#### [数组](#697)
#### [哈希表](#697)
### [0698_划分为k个相等的子集](#698)
#### [位运算](#698)
#### [记忆化搜索](#698)
#### [数组](#698)
#### [动态规划](#698)
#### [回溯](#698)
#### [状态压缩](#698)
### [0699_掉落的方块](#699)
#### [线段树](#699)
#### [数组](#699)
#### [有序集合](#699)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0690_员工的重要性
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
### 0691_贴纸拼词
___
#### 位运算
___
#### 记忆化搜索
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 动态规划
___
#### 回溯
___
#### 状态压缩
---
### 0692_前K个高频单词
___
#### 字典树
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 桶排序
___
#### 计数
___
#### 排序
___
#### 堆（优先队列）
---
### 0693_交替位二进制数
___
#### 位运算
---
### 0694_不同岛屿的数量 🔒
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 并查集
___
#### 哈希表
___
#### 哈希函数
---
### 0695_岛屿的最大面积
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 并查集
___
#### 数组
___
#### 矩阵
---
### 0696_计数二进制子串
___
#### 双指针
___
#### 字符串
---
### 0697_数组的度
___
#### 数组
___
#### 哈希表
---
### 0698_划分为k个相等的子集
___
#### 位运算
___
#### 记忆化搜索
___
#### 数组
___
#### 动态规划
___
#### 回溯
___
#### 状态压缩
---
### 0699_掉落的方块
___
#### 线段树
___
#### 数组
___
#### 有序集合
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 位运算 | 动态规划 | 双指针 |
| 哈希函数 | 哈希表 | 回溯 |
| 堆（优先队列） | 字典树 | 字符串 |
| 并查集 | 广度优先搜索 | 排序 |
| 数组 | 有序集合 | 树 |
| 桶排序 | 深度优先搜索 | 状态压缩 |
| 矩阵 | 线段树 | 计数 |
| 记忆化搜索 |  |  |

# [690. 员工的重要性](https://leetcode.cn/problems/employee-importance){#690}

{{< tabs "690" >}}

{{% tab "python" %}}
```python
"""
# Definition for Employee.
class Employee:
    def __init__(self, id: int, importance: int, subordinates: List[int]):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates
"""


class Solution:
    def getImportance(self, employees: List["Employee"], id: int) -> int:
        def dfs(i: int) -> int:
            return d[i].importance + sum(dfs(j) for j in d[i].subordinates)

        d = {e.id: e for e in employees}
        return dfs(id)
```
{{% /tab %}}
{{% tab "java" %}}
```java
/*
// Definition for Employee.
class Employee {
    public int id;
    public int importance;
    public List<Integer> subordinates;
};
*/

class Solution {
    private final Map<Integer, Employee> d = new HashMap<>();

    public int getImportance(List<Employee> employees, int id) {
        for (var e : employees) {
            d.put(e.id, e);
        }
        return dfs(id);
    }

    private int dfs(int i) {
        Employee e = d.get(i);
        int s = e.importance;
        for (int j : e.subordinates) {
            s += dfs(j);
        }
        return s;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> d;
        for (auto& e : employees) {
            d[e->id] = e;
        }
        function<int(int)> dfs = [&](int i) -> int {
            int s = d[i]->importance;
            for (int j : d[i]->subordinates) {
                s += dfs(j);
            }
            return s;
        };
        return dfs(id);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for Employee.
 * type Employee struct {
 *     Id int
 *     Importance int
 *     Subordinates []int
 * }
 */

func getImportance(employees []*Employee, id int) int {
	d := map[int]*Employee{}
	for _, e := range employees {
		d[e.Id] = e
	}
	var dfs func(int) int
	dfs = func(i int) int {
		s := d[i].Importance
		for _, j := range d[i].Subordinates {
			s += dfs(j)
		}
		return s
	}
	return dfs(id)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for Employee.
 * class Employee {
 *     id: number
 *     importance: number
 *     subordinates: number[]
 *     constructor(id: number, importance: number, subordinates: number[]) {
 *         this.id = (id === undefined) ? 0 : id;
 *         this.importance = (importance === undefined) ? 0 : importance;
 *         this.subordinates = (subordinates === undefined) ? [] : subordinates;
 *     }
 * }
 */

function getImportance(employees: Employee[], id: number): number {
    const d = new Map<number, Employee>();
    for (const e of employees) {
        d.set(e.id, e);
    }
    const dfs = (i: number): number => {
        let s = d.get(i)!.importance;
        for (const j of d.get(i)!.subordinates) {
            s += dfs(j);
        }
        return s;
    };
    return dfs(id);
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * Definition for Employee.
 * function Employee(id, importance, subordinates) {
 *     this.id = id;
 *     this.importance = importance;
 *     this.subordinates = subordinates;
 * }
 */

/**
 * @param {Employee[]} employees
 * @param {number} id
 * @return {number}
 */
var GetImportance = function (employees, id) {
    const d = new Map();
    for (const e of employees) {
        d.set(e.id, e);
    }
    const dfs = i => {
        let s = d.get(i).importance;
        for (const j of d.get(i).subordinates) {
            s += dfs(j);
        }
        return s;
    };
    return dfs(id);
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你有一个保存员工信息的数据结构，它包含了员工唯一的 id ，重要度和直系下属的 id 。</p>

<p>给定一个员工数组&nbsp;<code>employees</code>，其中：</p>

<ul>
	<li><code>employees[i].id</code> 是第&nbsp;<code>i</code>&nbsp;个员工的 ID。</li>
	<li><code>employees[i].importance</code>&nbsp;是第&nbsp;<code>i</code>&nbsp;个员工的重要度。</li>
	<li><code>employees[i].subordinates</code> 是第 <code>i</code> 名员工的直接下属的 ID 列表。</li>
</ul>

<p>给定一个整数&nbsp;<code>id</code>&nbsp;表示一个员工的 ID，返回这个员工和他所有下属的重要度的 <strong>总和</strong>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0600-0699/0690.Employee%20Importance/images/1716170448-dKZffb-image.png" style="width: 400px; height: 258px;" /></strong></p>

<pre>
<strong>输入：</strong>employees = [[1,5,[2,3]],[2,3,[]],[3,3,[]]], id = 1
<strong>输出：</strong>11
<strong>解释：</strong>
员工 1 自身的重要度是 5 ，他有两个直系下属 2 和 3 ，而且 2 和 3 的重要度均为 3 。因此员工 1 的总重要度是 5 + 3 + 3 = 11 。
</pre>

<p>&nbsp;</p>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0600-0699/0690.Employee%20Importance/images/1716170929-dkWpra-image.png" style="width: 362px; height: 361px;" /></strong></p>

<pre>
<strong>输入：</strong>employees = [[1,2,[5]],[5,-3,[]]], id = 5
<strong>输出：</strong>-3
<strong>解释：</strong>员工 5 的重要度为 -3 并且没有直接下属。
因此，员工 5 的总重要度为 -3。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= employees.length &lt;= 2000</code></li>
	<li><code>1 &lt;= employees[i].id &lt;= 2000</code></li>
	<li>所有的&nbsp;<code>employees[i].id</code>&nbsp;<strong>互不相同</strong>。</li>
	<li><code>-100 &lt;= employees[i].importance &lt;= 100</code></li>
	<li>一名员工最多有一名直接领导，并可能有多名下属。</li>
	<li><code>employees[i].subordinates</code>&nbsp;中的 ID 都有效。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + DFS

我们用一个哈希表 $d$ 存储所有员工的信息，其中键是员工的 ID，值是员工对象。然后我们从给定的员工 ID 开始深度优先搜索，每次遍历到一个员工时，将该员工的重要度加到答案中，并递归遍历该员工的所有下属，将下属的重要度也加到答案中。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是员工的数量。

<!-- tabs:start -->

#### Python3

```python
"""
# Definition for Employee.
class Employee:
    def __init__(self, id: int, importance: int, subordinates: List[int]):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates
"""


class Solution:
    def getImportance(self, employees: List["Employee"], id: int) -> int:
        def dfs(i: int) -> int:
            return d[i].importance + sum(dfs(j) for j in d[i].subordinates)

        d = {e.id: e for e in employees}
        return dfs(id)
```

#### Java

```java
/*
// Definition for Employee.
class Employee {
    public int id;
    public int importance;
    public List<Integer> subordinates;
};
*/

class Solution {
    private final Map<Integer, Employee> d = new HashMap<>();

    public int getImportance(List<Employee> employees, int id) {
        for (var e : employees) {
            d.put(e.id, e);
        }
        return dfs(id);
    }

    private int dfs(int i) {
        Employee e = d.get(i);
        int s = e.importance;
        for (int j : e.subordinates) {
            s += dfs(j);
        }
        return s;
    }
}
```

#### C++

```cpp
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> d;
        for (auto& e : employees) {
            d[e->id] = e;
        }
        function<int(int)> dfs = [&](int i) -> int {
            int s = d[i]->importance;
            for (int j : d[i]->subordinates) {
                s += dfs(j);
            }
            return s;
        };
        return dfs(id);
    }
};
```

#### Go

```go
/**
 * Definition for Employee.
 * type Employee struct {
 *     Id int
 *     Importance int
 *     Subordinates []int
 * }
 */

func getImportance(employees []*Employee, id int) int {
	d := map[int]*Employee{}
	for _, e := range employees {
		d[e.Id] = e
	}
	var dfs func(int) int
	dfs = func(i int) int {
		s := d[i].Importance
		for _, j := range d[i].Subordinates {
			s += dfs(j)
		}
		return s
	}
	return dfs(id)
}
```

#### TypeScript

```ts
/**
 * Definition for Employee.
 * class Employee {
 *     id: number
 *     importance: number
 *     subordinates: number[]
 *     constructor(id: number, importance: number, subordinates: number[]) {
 *         this.id = (id === undefined) ? 0 : id;
 *         this.importance = (importance === undefined) ? 0 : importance;
 *         this.subordinates = (subordinates === undefined) ? [] : subordinates;
 *     }
 * }
 */

function getImportance(employees: Employee[], id: number): number {
    const d = new Map<number, Employee>();
    for (const e of employees) {
        d.set(e.id, e);
    }
    const dfs = (i: number): number => {
        let s = d.get(i)!.importance;
        for (const j of d.get(i)!.subordinates) {
            s += dfs(j);
        }
        return s;
    };
    return dfs(id);
}
```

#### JavaScript

```js
/**
 * Definition for Employee.
 * function Employee(id, importance, subordinates) {
 *     this.id = id;
 *     this.importance = importance;
 *     this.subordinates = subordinates;
 * }
 */

/**
 * @param {Employee[]} employees
 * @param {number} id
 * @return {number}
 */
var GetImportance = function (employees, id) {
    const d = new Map();
    for (const e of employees) {
        d.set(e.id, e);
    }
    const dfs = i => {
        let s = d.get(i).importance;
        for (const j of d.get(i).subordinates) {
            s += dfs(j);
        }
        return s;
    };
    return dfs(id);
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [691. 贴纸拼词](https://leetcode.cn/problems/stickers-to-spell-word){#691}

{{< tabs "691" >}}

{{% tab "python" %}}
```python
class Solution:
    def minStickers(self, stickers: List[str], target: str) -> int:
        n = len(target)
        q = deque([0])
        vis = [False] * (1 << n)
        vis[0] = True
        ans = 0
        while q:
            for _ in range(len(q)):
                cur = q.popleft()
                if cur == (1 << n) - 1:
                    return ans
                for s in stickers:
                    cnt = Counter(s)
                    nxt = cur
                    for i, c in enumerate(target):
                        if (cur >> i & 1) == 0 and cnt[c] > 0:
                            cnt[c] -= 1
                            nxt |= 1 << i
                    if not vis[nxt]:
                        vis[nxt] = True
                        q.append(nxt)
            ans += 1
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minStickers(String[] stickers, String target) {
        int n = target.length();
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(0);
        boolean[] vis = new boolean[1 << n];
        vis[0] = true;
        for (int ans = 0; !q.isEmpty(); ++ans) {
            for (int m = q.size(); m > 0; --m) {
                int cur = q.poll();
                if (cur == (1 << n) - 1) {
                    return ans;
                }
                for (String s : stickers) {
                    int[] cnt = new int[26];
                    int nxt = cur;
                    for (char c : s.toCharArray()) {
                        ++cnt[c - 'a'];
                    }
                    for (int i = 0; i < n; ++i) {
                        int j = target.charAt(i) - 'a';
                        if ((cur >> i & 1) == 0 && cnt[j] > 0) {
                            --cnt[j];
                            nxt |= 1 << i;
                        }
                    }
                    if (!vis[nxt]) {
                        vis[nxt] = true;
                        q.offer(nxt);
                    }
                }
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
    int minStickers(vector<string>& stickers, string target) {
        int n = target.size();
        queue<int> q{{0}};
        vector<bool> vis(1 << n);
        vis[0] = true;
        for (int ans = 0; q.size(); ++ans) {
            for (int m = q.size(); m; --m) {
                int cur = q.front();
                q.pop();
                if (cur == (1 << n) - 1) {
                    return ans;
                }
                for (auto& s : stickers) {
                    int cnt[26]{};
                    int nxt = cur;
                    for (char& c : s) {
                        ++cnt[c - 'a'];
                    }
                    for (int i = 0; i < n; ++i) {
                        int j = target[i] - 'a';
                        if ((cur >> i & 1) == 0 && cnt[j] > 0) {
                            nxt |= 1 << i;
                            --cnt[j];
                        }
                    }
                    if (!vis[nxt]) {
                        vis[nxt] = true;
                        q.push(nxt);
                    }
                }
            }
        }
        return -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minStickers(stickers []string, target string) (ans int) {
	n := len(target)
	q := []int{0}
	vis := make([]bool, 1<<n)
	vis[0] = true
	for ; len(q) > 0; ans++ {
		for m := len(q); m > 0; m-- {
			cur := q[0]
			q = q[1:]
			if cur == 1<<n-1 {
				return
			}
			for _, s := range stickers {
				cnt := [26]int{}
				for _, c := range s {
					cnt[c-'a']++
				}
				nxt := cur
				for i, c := range target {
					if cur>>i&1 == 0 && cnt[c-'a'] > 0 {
						nxt |= 1 << i
						cnt[c-'a']--
					}
				}
				if !vis[nxt] {
					vis[nxt] = true
					q = append(q, nxt)
				}
			}
		}
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minStickers(stickers: string[], target: string): number {
    const n = target.length;
    const q: number[] = [0];
    const vis: boolean[] = Array(1 << n).fill(false);
    vis[0] = true;
    for (let ans = 0; q.length; ++ans) {
        const qq: number[] = [];
        for (const cur of q) {
            if (cur === (1 << n) - 1) {
                return ans;
            }
            for (const s of stickers) {
                const cnt: number[] = Array(26).fill(0);
                for (const c of s) {
                    cnt[c.charCodeAt(0) - 97]++;
                }
                let nxt = cur;
                for (let i = 0; i < n; ++i) {
                    const j = target.charCodeAt(i) - 97;
                    if (((cur >> i) & 1) === 0 && cnt[j]) {
                        nxt |= 1 << i;
                        cnt[j]--;
                    }
                }
                if (!vis[nxt]) {
                    vis[nxt] = true;
                    qq.push(nxt);
                }
            }
        }
        q.splice(0, q.length, ...qq);
    }
    return -1;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::{HashSet, VecDeque};

impl Solution {
    pub fn min_stickers(stickers: Vec<String>, target: String) -> i32 {
        let mut q = VecDeque::new();
        q.push_back(0);
        let mut ans = 0;
        let n = target.len();
        let mut vis = HashSet::new();
        vis.insert(0);
        while !q.is_empty() {
            for _ in 0..q.len() {
                let state = q.pop_front().unwrap();
                if state == (1 << n) - 1 {
                    return ans;
                }
                for s in &stickers {
                    let mut nxt = state;
                    let mut cnt = [0; 26];
                    for &c in s.as_bytes() {
                        cnt[(c - b'a') as usize] += 1;
                    }
                    for (i, &c) in target.as_bytes().iter().enumerate() {
                        let idx = (c - b'a') as usize;
                        if (nxt & (1 << i)) == 0 && cnt[idx] > 0 {
                            nxt |= 1 << i;
                            cnt[idx] -= 1;
                        }
                    }
                    if !vis.contains(&nxt) {
                        q.push_back(nxt);
                        vis.insert(nxt);
                    }
                }
            }
            ans += 1;
        }
        -1
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>我们有 <code>n</code> 种不同的贴纸。每个贴纸上都有一个小写的英文单词。</p>

<p>您想要拼写出给定的字符串 <code>target</code>&nbsp;，方法是从收集的贴纸中切割单个字母并重新排列它们。如果你愿意，你可以多次使用每个贴纸，每个贴纸的数量是无限的。</p>

<p>返回你需要拼出 <code>target</code>&nbsp;的最小贴纸数量。如果任务不可能，则返回 <code>-1</code> 。</p>

<p><strong>注意：</strong>在所有的测试用例中，所有的单词都是从 <code>1000</code> 个最常见的美国英语单词中随机选择的，并且 <code>target</code>&nbsp;被选择为两个随机单词的连接。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong> stickers = ["with","example","science"], target = "thehat"
<b>输出：</b>3
<strong>解释：
</strong>我们可以使用 2 个 "with" 贴纸，和 1 个 "example" 贴纸。
把贴纸上的字母剪下来并重新排列后，就可以形成目标 “thehat“ 了。
此外，这是形成目标字符串所需的最小贴纸数量。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<b>输入：</b>stickers = ["notice","possible"], target = "basicbasic"
<b>输出：</b>-1
<strong>解释：</strong>我们不能通过剪切给定贴纸的字母来形成目标“basicbasic”。</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>n == stickers.length</code></li>
	<li><code>1 &lt;= n &lt;= 50</code></li>
	<li><code>1 &lt;= stickers[i].length &lt;= 10</code></li>
	<li><code>1 &lt;= target.length &lt;= 15</code></li>
	<li><code>stickers[i]</code>&nbsp;和&nbsp;<code>target</code>&nbsp;由小写英文单词组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS + 状态压缩

我们注意到，字符串 $\textit{target}$ 的长度不超过 $15$，我们可以使用一个长度为 $15$ 的二进制数来表示 $\textit{target}$ 的每个字符是否被拼出，如果第 $i$ 位为 $1$，表示 $\textit{target}$ 的第 $i$ 个字符已经被拼出，否则表示未被拼出。

我们定义一个初始状态 $0$，表示所有字符都未被拼出，然后我们使用广度优先搜索的方法，从初始状态开始，每次搜索时，我们枚举所有的贴纸，对于每一张贴纸，我们尝试拼出 $\textit{target}$ 的每一个字符，如果拼出了某个字符，我们就将对应的二进制数的第 $i$ 位设置为 $1$，表示该字符已经被拼出，然后我们继续搜索，直到我们拼出了 $\textit{target}$ 的所有字符。

时间复杂度 $O(2^n \times m \times (l + n))$，空间复杂度 $O(2^n)$。其中 $n$ 是字符串 $\textit{target}$ 的长度，而 $m$ 和 $l$ 分别是贴纸的数量和贴纸的平均长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minStickers(self, stickers: List[str], target: str) -> int:
        n = len(target)
        q = deque([0])
        vis = [False] * (1 << n)
        vis[0] = True
        ans = 0
        while q:
            for _ in range(len(q)):
                cur = q.popleft()
                if cur == (1 << n) - 1:
                    return ans
                for s in stickers:
                    cnt = Counter(s)
                    nxt = cur
                    for i, c in enumerate(target):
                        if (cur >> i & 1) == 0 and cnt[c] > 0:
                            cnt[c] -= 1
                            nxt |= 1 << i
                    if not vis[nxt]:
                        vis[nxt] = True
                        q.append(nxt)
            ans += 1
        return -1
```

#### Java

```java
class Solution {
    public int minStickers(String[] stickers, String target) {
        int n = target.length();
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(0);
        boolean[] vis = new boolean[1 << n];
        vis[0] = true;
        for (int ans = 0; !q.isEmpty(); ++ans) {
            for (int m = q.size(); m > 0; --m) {
                int cur = q.poll();
                if (cur == (1 << n) - 1) {
                    return ans;
                }
                for (String s : stickers) {
                    int[] cnt = new int[26];
                    int nxt = cur;
                    for (char c : s.toCharArray()) {
                        ++cnt[c - 'a'];
                    }
                    for (int i = 0; i < n; ++i) {
                        int j = target.charAt(i) - 'a';
                        if ((cur >> i & 1) == 0 && cnt[j] > 0) {
                            --cnt[j];
                            nxt |= 1 << i;
                        }
                    }
                    if (!vis[nxt]) {
                        vis[nxt] = true;
                        q.offer(nxt);
                    }
                }
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
    int minStickers(vector<string>& stickers, string target) {
        int n = target.size();
        queue<int> q{{0}};
        vector<bool> vis(1 << n);
        vis[0] = true;
        for (int ans = 0; q.size(); ++ans) {
            for (int m = q.size(); m; --m) {
                int cur = q.front();
                q.pop();
                if (cur == (1 << n) - 1) {
                    return ans;
                }
                for (auto& s : stickers) {
                    int cnt[26]{};
                    int nxt = cur;
                    for (char& c : s) {
                        ++cnt[c - 'a'];
                    }
                    for (int i = 0; i < n; ++i) {
                        int j = target[i] - 'a';
                        if ((cur >> i & 1) == 0 && cnt[j] > 0) {
                            nxt |= 1 << i;
                            --cnt[j];
                        }
                    }
                    if (!vis[nxt]) {
                        vis[nxt] = true;
                        q.push(nxt);
                    }
                }
            }
        }
        return -1;
    }
};
```

#### Go

```go
func minStickers(stickers []string, target string) (ans int) {
	n := len(target)
	q := []int{0}
	vis := make([]bool, 1<<n)
	vis[0] = true
	for ; len(q) > 0; ans++ {
		for m := len(q); m > 0; m-- {
			cur := q[0]
			q = q[1:]
			if cur == 1<<n-1 {
				return
			}
			for _, s := range stickers {
				cnt := [26]int{}
				for _, c := range s {
					cnt[c-'a']++
				}
				nxt := cur
				for i, c := range target {
					if cur>>i&1 == 0 && cnt[c-'a'] > 0 {
						nxt |= 1 << i
						cnt[c-'a']--
					}
				}
				if !vis[nxt] {
					vis[nxt] = true
					q = append(q, nxt)
				}
			}
		}
	}
	return -1
}
```

#### TypeScript

```ts
function minStickers(stickers: string[], target: string): number {
    const n = target.length;
    const q: number[] = [0];
    const vis: boolean[] = Array(1 << n).fill(false);
    vis[0] = true;
    for (let ans = 0; q.length; ++ans) {
        const qq: number[] = [];
        for (const cur of q) {
            if (cur === (1 << n) - 1) {
                return ans;
            }
            for (const s of stickers) {
                const cnt: number[] = Array(26).fill(0);
                for (const c of s) {
                    cnt[c.charCodeAt(0) - 97]++;
                }
                let nxt = cur;
                for (let i = 0; i < n; ++i) {
                    const j = target.charCodeAt(i) - 97;
                    if (((cur >> i) & 1) === 0 && cnt[j]) {
                        nxt |= 1 << i;
                        cnt[j]--;
                    }
                }
                if (!vis[nxt]) {
                    vis[nxt] = true;
                    qq.push(nxt);
                }
            }
        }
        q.splice(0, q.length, ...qq);
    }
    return -1;
}
```

#### Rust

```rust
use std::collections::{HashSet, VecDeque};

impl Solution {
    pub fn min_stickers(stickers: Vec<String>, target: String) -> i32 {
        let mut q = VecDeque::new();
        q.push_back(0);
        let mut ans = 0;
        let n = target.len();
        let mut vis = HashSet::new();
        vis.insert(0);
        while !q.is_empty() {
            for _ in 0..q.len() {
                let state = q.pop_front().unwrap();
                if state == (1 << n) - 1 {
                    return ans;
                }
                for s in &stickers {
                    let mut nxt = state;
                    let mut cnt = [0; 26];
                    for &c in s.as_bytes() {
                        cnt[(c - b'a') as usize] += 1;
                    }
                    for (i, &c) in target.as_bytes().iter().enumerate() {
                        let idx = (c - b'a') as usize;
                        if (nxt & (1 << i)) == 0 && cnt[idx] > 0 {
                            nxt |= 1 << i;
                            cnt[idx] -= 1;
                        }
                    }
                    if !vis.contains(&nxt) {
                        q.push_back(nxt);
                        vis.insert(nxt);
                    }
                }
            }
            ans += 1;
        }
        -1
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [692. 前K个高频单词](https://leetcode.cn/problems/top-k-frequent-words){#692}

{{< tabs "692" >}}

{{% tab "python" %}}
```python
class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        cnt = Counter(words)
        return sorted(cnt, key=lambda x: (-cnt[x], x))[:k]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        Map<String, Integer> cnt = new HashMap<>();
        for (String w : words) {
            cnt.merge(w, 1, Integer::sum);
        }
        Arrays.sort(words, (a, b) -> {
            int c1 = cnt.get(a), c2 = cnt.get(b);
            return c1 == c2 ? a.compareTo(b) : c2 - c1;
        });
        List<String> ans = new ArrayList<>();
        for (int i = 0; i < words.length && ans.size() < k; ++i) {
            if (i == 0 || !words[i].equals(words[i - 1])) {
                ans.add(words[i]);
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
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> cnt;
        for (const auto& w : words) {
            ++cnt[w];
        }
        vector<string> ans;
        for (const auto& [w, _] : cnt) {
            ans.push_back(w);
        }
        ranges::sort(ans, [&](const string& a, const string& b) {
            return cnt[a] > cnt[b] || (cnt[a] == cnt[b] && a < b);
        });
        ans.resize(k);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func topKFrequent(words []string, k int) (ans []string) {
	cnt := map[string]int{}
	for _, w := range words {
		cnt[w]++
	}
	for w := range cnt {
		ans = append(ans, w)
	}
	sort.Slice(ans, func(i, j int) bool { a, b := ans[i], ans[j]; return cnt[a] > cnt[b] || cnt[a] == cnt[b] && a < b })
	return ans[:k]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function topKFrequent(words: string[], k: number): string[] {
    const cnt: Map<string, number> = new Map();
    for (const w of words) {
        cnt.set(w, (cnt.get(w) || 0) + 1);
    }
    const ans: string[] = Array.from(cnt.keys());
    ans.sort((a, b) => {
        return cnt.get(a) === cnt.get(b) ? a.localeCompare(b) : cnt.get(b)! - cnt.get(a)!;
    });
    return ans.slice(0, k);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个单词列表&nbsp;<code>words</code>&nbsp;和一个整数 <code>k</code> ，返回前&nbsp;<code>k</code><em>&nbsp;</em>个出现次数最多的单词。</p>

<p>返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率， <strong>按字典顺序</strong> 排序。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入:</strong> words = ["i", "love", "leetcode", "i", "love", "coding"], k = 2
<strong>输出:</strong> ["i", "love"]
<strong>解析:</strong> "i" 和 "love" 为出现次数最多的两个单词，均为2次。
    注意，按字母顺序 "i" 在 "love" 之前。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入:</strong> ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
<strong>输出:</strong> ["the", "is", "sunny", "day"]
<strong>解析:</strong> "the", "is", "sunny" 和 "day" 是出现次数最多的四个单词，
    出现次数依次为 4, 3, 2 和 1 次。
</pre>

<p>&nbsp;</p>

<p><strong>注意：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 500</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 10</code></li>
	<li><code>words[i]</code>&nbsp;由小写英文字母组成。</li>
	<li><code>k</code> 的取值范围是&nbsp;<code>[1, <strong>不同</strong> words[i] 的数量]</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>尝试以&nbsp;<code>O(n log k)</code> 时间复杂度和&nbsp;<code>O(n)</code> 空间复杂度解决。</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 排序

我们可以用一个哈希表 $\textit{cnt}$ 记录每一个单词出现的次数，然后对哈希表中的键值对按照值进行排序，如果值相同，按照键进行排序。

最后取出前 $k$ 个键即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为单词的个数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        cnt = Counter(words)
        return sorted(cnt, key=lambda x: (-cnt[x], x))[:k]
```

#### Java

```java
class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        Map<String, Integer> cnt = new HashMap<>();
        for (String w : words) {
            cnt.merge(w, 1, Integer::sum);
        }
        Arrays.sort(words, (a, b) -> {
            int c1 = cnt.get(a), c2 = cnt.get(b);
            return c1 == c2 ? a.compareTo(b) : c2 - c1;
        });
        List<String> ans = new ArrayList<>();
        for (int i = 0; i < words.length && ans.size() < k; ++i) {
            if (i == 0 || !words[i].equals(words[i - 1])) {
                ans.add(words[i]);
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
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> cnt;
        for (const auto& w : words) {
            ++cnt[w];
        }
        vector<string> ans;
        for (const auto& [w, _] : cnt) {
            ans.push_back(w);
        }
        ranges::sort(ans, [&](const string& a, const string& b) {
            return cnt[a] > cnt[b] || (cnt[a] == cnt[b] && a < b);
        });
        ans.resize(k);
        return ans;
    }
};
```

#### Go

```go
func topKFrequent(words []string, k int) (ans []string) {
	cnt := map[string]int{}
	for _, w := range words {
		cnt[w]++
	}
	for w := range cnt {
		ans = append(ans, w)
	}
	sort.Slice(ans, func(i, j int) bool { a, b := ans[i], ans[j]; return cnt[a] > cnt[b] || cnt[a] == cnt[b] && a < b })
	return ans[:k]
}
```

#### TypeScript

```ts
function topKFrequent(words: string[], k: number): string[] {
    const cnt: Map<string, number> = new Map();
    for (const w of words) {
        cnt.set(w, (cnt.get(w) || 0) + 1);
    }
    const ans: string[] = Array.from(cnt.keys());
    ans.sort((a, b) => {
        return cnt.get(a) === cnt.get(b) ? a.localeCompare(b) : cnt.get(b)! - cnt.get(a)!;
    });
    return ans.slice(0, k);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [693. 交替位二进制数](https://leetcode.cn/problems/binary-number-with-alternating-bits){#693}

{{< tabs "693" >}}

{{% tab "python" %}}
```python
class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        n ^= n >> 1
        return (n & (n + 1)) == 0
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean hasAlternatingBits(int n) {
        n ^= (n >> 1);
        return (n & (n + 1)) == 0;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool hasAlternatingBits(int n) {
        n ^= (n >> 1);
        return (n & ((long) n + 1)) == 0;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func hasAlternatingBits(n int) bool {
	n ^= (n >> 1)
	return (n & (n + 1)) == 0
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn has_alternating_bits(n: i32) -> bool {
        let t = n ^ (n >> 1);
        (t & (t + 1)) == 0
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个正整数，检查它的二进制表示是否总是 0、1 交替出现：换句话说，就是二进制表示中相邻两位的数字永不相同。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 5
<strong>输出：</strong>true
<strong>解释：</strong>5 的二进制表示是：101
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 7
<strong>输出：</strong>false
<strong>解释：</strong>7 的二进制表示是：111.</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 11
<strong>输出：</strong>false
<strong>解释：</strong>11 的二进制表示是：1011.</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

n 循环右移直至为 0，依次检测 n 的二进制位是否交替出现。若循环过程中发现 0、1 没有交替出现，直接返回 false。否则循环结束返回 true。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        prev = -1
        while n:
            curr = n & 1
            if prev == curr:
                return False
            prev = curr
            n >>= 1
        return True
```

#### Java

```java
class Solution {
    public boolean hasAlternatingBits(int n) {
        int prev = -1;
        while (n != 0) {
            int curr = n & 1;
            if (prev == curr) {
                return false;
            }
            prev = curr;
            n >>= 1;
        }
        return true;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = -1;
        while (n) {
            int curr = n & 1;
            if (prev == curr) return false;
            prev = curr;
            n >>= 1;
        }
        return true;
    }
};
```

#### Go

```go
func hasAlternatingBits(n int) bool {
	prev := -1
	for n != 0 {
		curr := n & 1
		if prev == curr {
			return false
		}
		prev = curr
		n >>= 1
	}
	return true
}
```

#### Rust

```rust
impl Solution {
    pub fn has_alternating_bits(mut n: i32) -> bool {
        let u = n & 3;
        if u != 1 && u != 2 {
            return false;
        }
        while n != 0 {
            if (n & 3) != u {
                return false;
            }
            n >>= 2;
        }
        true
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：位运算

假设 01 交替出现，那么我们可以通过错位异或将尾部全部转为 1，加 1 可以得到 2 的幂次的一个数 n（n 中只有一个位是 1），接着利用 `n & (n + 1)` 可以消除最后一位的 1。

此时判断是否为 0，若是，说明假设成立，是 01 交替串。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        n ^= n >> 1
        return (n & (n + 1)) == 0
```

#### Java

```java
class Solution {
    public boolean hasAlternatingBits(int n) {
        n ^= (n >> 1);
        return (n & (n + 1)) == 0;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool hasAlternatingBits(int n) {
        n ^= (n >> 1);
        return (n & ((long) n + 1)) == 0;
    }
};
```

#### Go

```go
func hasAlternatingBits(n int) bool {
	n ^= (n >> 1)
	return (n & (n + 1)) == 0
}
```

#### Rust

```rust
impl Solution {
    pub fn has_alternating_bits(n: i32) -> bool {
        let t = n ^ (n >> 1);
        (t & (t + 1)) == 0
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [694. 不同岛屿的数量 🔒](https://leetcode.cn/problems/number-of-distinct-islands){#694}

{{< tabs "694" >}}

{{% tab "python" %}}
```python
class Solution:
    def numDistinctIslands(self, grid: List[List[int]]) -> int:
        def dfs(i: int, j: int, k: int):
            grid[i][j] = 0
            path.append(str(k))
            dirs = (-1, 0, 1, 0, -1)
            for h in range(1, 5):
                x, y = i + dirs[h - 1], j + dirs[h]
                if 0 <= x < m and 0 <= y < n and grid[x][y]:
                    dfs(x, y, h)
            path.append(str(-k))

        paths = set()
        path = []
        m, n = len(grid), len(grid[0])
        for i, row in enumerate(grid):
            for j, x in enumerate(row):
                if x:
                    dfs(i, j, 0)
                    paths.add("".join(path))
                    path.clear()
        return len(paths)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int m;
    private int n;
    private int[][] grid;
    private StringBuilder path = new StringBuilder();

    public int numDistinctIslands(int[][] grid) {
        m = grid.length;
        n = grid[0].length;
        this.grid = grid;
        Set<String> paths = new HashSet<>();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    dfs(i, j, 0);
                    paths.add(path.toString());
                    path.setLength(0);
                }
            }
        }
        return paths.size();
    }

    private void dfs(int i, int j, int k) {
        grid[i][j] = 0;
        path.append(k);
        int[] dirs = {-1, 0, 1, 0, -1};
        for (int h = 1; h < 5; ++h) {
            int x = i + dirs[h - 1];
            int y = j + dirs[h];
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                dfs(x, y, h);
            }
        }
        path.append(k);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        unordered_set<string> paths;
        string path;
        int m = grid.size(), n = grid[0].size();
        int dirs[5] = {-1, 0, 1, 0, -1};

        function<void(int, int, int)> dfs = [&](int i, int j, int k) {
            grid[i][j] = 0;
            path += to_string(k);
            for (int h = 1; h < 5; ++h) {
                int x = i + dirs[h - 1], y = j + dirs[h];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y]) {
                    dfs(x, y, h);
                }
            }
            path += to_string(k);
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    dfs(i, j, 0);
                    paths.insert(path);
                    path.clear();
                }
            }
        }
        return paths.size();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numDistinctIslands(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	paths := map[string]bool{}
	path := []byte{}
	dirs := [5]int{-1, 0, 1, 0, -1}
	var dfs func(i, j, k int)
	dfs = func(i, j, k int) {
		grid[i][j] = 0
		path = append(path, byte(k))
		for h := 1; h < 5; h++ {
			x, y := i+dirs[h-1], j+dirs[h]
			if x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1 {
				dfs(x, y, h)
			}
		}
		path = append(path, byte(k))
	}
	for i, row := range grid {
		for j, x := range row {
			if x == 1 {
				dfs(i, j, 0)
				paths[string(path)] = true
				path = path[:0]
			}
		}
	}
	return len(paths)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numDistinctIslands(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;
    const paths: Set<string> = new Set();
    const path: number[] = [];
    const dirs: number[] = [-1, 0, 1, 0, -1];
    const dfs = (i: number, j: number, k: number) => {
        grid[i][j] = 0;
        path.push(k);
        for (let h = 1; h < 5; ++h) {
            const [x, y] = [i + dirs[h - 1], j + dirs[h]];
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y]) {
                dfs(x, y, h);
            }
        }
        path.push(k);
    };
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (grid[i][j]) {
                dfs(i, j, 0);
                paths.add(path.join(','));
                path.length = 0;
            }
        }
    }
    return paths.size;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个非空 01 二维数组表示的网格，一个岛屿由四连通（上、下、左、右四个方向）的 <code>1</code> 组成，你可以认为网格的四周被海水包围。</p>

<p>请你计算这个网格中共有多少个形状不同的岛屿。两个岛屿被认为是相同的，当且仅当一个岛屿可以通过平移变换（不可以旋转、翻转）和另一个岛屿重合。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0600-0699/0694.Number%20of%20Distinct%20Islands/images/distinctisland1-1-grid.jpg" /></p>

<pre>
<strong>输入:</strong> grid = [[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]
<b>输出：</b>1
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入:</strong> grid = [[1,1,0,1,1],[1,0,0,0,0],[0,0,0,0,1],[1,1,0,1,1]]
<b>输出</b><strong>:</strong> 3</pre>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0600-0699/0694.Number%20of%20Distinct%20Islands/images/distinctisland1-2-grid.jpg" /></p>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 50</code></li>
	<li><code>grid[i][j]</code>&nbsp;仅包含&nbsp;<code>0</code>&nbsp;或&nbsp;<code>1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + DFS

我们遍历网格中的每个位置 $(i, j)$，如果该位置为 $1$，则以其为起始节点开始进行深度优先搜索，过程中将 $1$ 修改为 $0$，并且将搜索的方向记录下来，等搜索结束后将方向序列加入哈希表中，最后返回哈希表中不同方向序列的数量即可。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别为网格的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numDistinctIslands(self, grid: List[List[int]]) -> int:
        def dfs(i: int, j: int, k: int):
            grid[i][j] = 0
            path.append(str(k))
            dirs = (-1, 0, 1, 0, -1)
            for h in range(1, 5):
                x, y = i + dirs[h - 1], j + dirs[h]
                if 0 <= x < m and 0 <= y < n and grid[x][y]:
                    dfs(x, y, h)
            path.append(str(-k))

        paths = set()
        path = []
        m, n = len(grid), len(grid[0])
        for i, row in enumerate(grid):
            for j, x in enumerate(row):
                if x:
                    dfs(i, j, 0)
                    paths.add("".join(path))
                    path.clear()
        return len(paths)
```

#### Java

```java
class Solution {
    private int m;
    private int n;
    private int[][] grid;
    private StringBuilder path = new StringBuilder();

    public int numDistinctIslands(int[][] grid) {
        m = grid.length;
        n = grid[0].length;
        this.grid = grid;
        Set<String> paths = new HashSet<>();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    dfs(i, j, 0);
                    paths.add(path.toString());
                    path.setLength(0);
                }
            }
        }
        return paths.size();
    }

    private void dfs(int i, int j, int k) {
        grid[i][j] = 0;
        path.append(k);
        int[] dirs = {-1, 0, 1, 0, -1};
        for (int h = 1; h < 5; ++h) {
            int x = i + dirs[h - 1];
            int y = j + dirs[h];
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                dfs(x, y, h);
            }
        }
        path.append(k);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        unordered_set<string> paths;
        string path;
        int m = grid.size(), n = grid[0].size();
        int dirs[5] = {-1, 0, 1, 0, -1};

        function<void(int, int, int)> dfs = [&](int i, int j, int k) {
            grid[i][j] = 0;
            path += to_string(k);
            for (int h = 1; h < 5; ++h) {
                int x = i + dirs[h - 1], y = j + dirs[h];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y]) {
                    dfs(x, y, h);
                }
            }
            path += to_string(k);
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    dfs(i, j, 0);
                    paths.insert(path);
                    path.clear();
                }
            }
        }
        return paths.size();
    }
};
```

#### Go

```go
func numDistinctIslands(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	paths := map[string]bool{}
	path := []byte{}
	dirs := [5]int{-1, 0, 1, 0, -1}
	var dfs func(i, j, k int)
	dfs = func(i, j, k int) {
		grid[i][j] = 0
		path = append(path, byte(k))
		for h := 1; h < 5; h++ {
			x, y := i+dirs[h-1], j+dirs[h]
			if x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1 {
				dfs(x, y, h)
			}
		}
		path = append(path, byte(k))
	}
	for i, row := range grid {
		for j, x := range row {
			if x == 1 {
				dfs(i, j, 0)
				paths[string(path)] = true
				path = path[:0]
			}
		}
	}
	return len(paths)
}
```

#### TypeScript

```ts
function numDistinctIslands(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;
    const paths: Set<string> = new Set();
    const path: number[] = [];
    const dirs: number[] = [-1, 0, 1, 0, -1];
    const dfs = (i: number, j: number, k: number) => {
        grid[i][j] = 0;
        path.push(k);
        for (let h = 1; h < 5; ++h) {
            const [x, y] = [i + dirs[h - 1], j + dirs[h]];
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y]) {
                dfs(x, y, h);
            }
        }
        path.push(k);
    };
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (grid[i][j]) {
                dfs(i, j, 0);
                paths.add(path.join(','));
                path.length = 0;
            }
        }
    }
    return paths.size;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [695. 岛屿的最大面积](https://leetcode.cn/problems/max-area-of-island){#695}

{{< tabs "695" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        def dfs(i: int, j: int) -> int:
            if grid[i][j] == 0:
                return 0
            ans = 1
            grid[i][j] = 0
            dirs = (-1, 0, 1, 0, -1)
            for a, b in pairwise(dirs):
                x, y = i + a, j + b
                if 0 <= x < m and 0 <= y < n:
                    ans += dfs(x, y)
            return ans

        m, n = len(grid), len(grid[0])
        return max(dfs(i, j) for i in range(m) for j in range(n))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int m;
    private int n;
    private int[][] grid;

    public int maxAreaOfIsland(int[][] grid) {
        m = grid.length;
        n = grid[0].length;
        this.grid = grid;
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = Math.max(ans, dfs(i, j));
            }
        }
        return ans;
    }

    private int dfs(int i, int j) {
        if (grid[i][j] == 0) {
            return 0;
        }
        int ans = 1;
        grid[i][j] = 0;
        int[] dirs = {-1, 0, 1, 0, -1};
        for (int k = 0; k < 4; ++k) {
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x >= 0 && x < m && y >= 0 && y < n) {
                ans += dfs(x, y);
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
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dirs[5] = {-1, 0, 1, 0, -1};
        int ans = 0;
        function<int(int, int)> dfs = [&](int i, int j) {
            if (grid[i][j] == 0) {
                return 0;
            }
            int ans = 1;
            grid[i][j] = 0;
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    ans += dfs(x, y);
                }
            }
            return ans;
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = max(ans, dfs(i, j));
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxAreaOfIsland(grid [][]int) (ans int) {
	m, n := len(grid), len(grid[0])
	dirs := [5]int{-1, 0, 1, 0, -1}
	var dfs func(i, j int) int
	dfs = func(i, j int) int {
		if grid[i][j] == 0 {
			return 0
		}
		ans := 1
		grid[i][j] = 0
		for k := 0; k < 4; k++ {
			x, y := i+dirs[k], j+dirs[k+1]
			if x >= 0 && x < m && y >= 0 && y < n {
				ans += dfs(x, y)
			}
		}
		return ans
	}
	for i := range grid {
		for j := range grid[i] {
			ans = max(ans, dfs(i, j))
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxAreaOfIsland(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;
    const dirs = [-1, 0, 1, 0, -1];
    const dfs = (i: number, j: number): number => {
        if (grid[i][j] === 0) {
            return 0;
        }
        let ans = 1;
        grid[i][j] = 0;
        for (let k = 0; k < 4; ++k) {
            const [x, y] = [i + dirs[k], j + dirs[k + 1]];
            if (x >= 0 && x < m && y >= 0 && y < n) {
                ans += dfs(x, y);
            }
        }
        return ans;
    };
    let ans = 0;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            ans = Math.max(ans, dfs(i, j));
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    fn dfs(grid: &mut Vec<Vec<i32>>, i: usize, j: usize) -> i32 {
        if i == grid.len() || j == grid[0].len() || grid[i][j] == 0 {
            return 0;
        }
        grid[i][j] = 0;
        let mut res = 1 + Self::dfs(grid, i + 1, j) + Self::dfs(grid, i, j + 1);
        if i != 0 {
            res += Self::dfs(grid, i - 1, j);
        }
        if j != 0 {
            res += Self::dfs(grid, i, j - 1);
        }
        res
    }

    pub fn max_area_of_island(mut grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        let mut res = 0;
        for i in 0..m {
            for j in 0..n {
                res = res.max(Self::dfs(&mut grid, i, j));
            }
        }
        res
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个大小为 <code>m x n</code> 的二进制矩阵 <code>grid</code> 。</p>

<p><strong>岛屿</strong>&nbsp;是由一些相邻的&nbsp;<code>1</code>&nbsp;(代表土地) 构成的组合，这里的「相邻」要求两个 <code>1</code> 必须在 <strong>水平或者竖直的四个方向上 </strong>相邻。你可以假设&nbsp;<code>grid</code> 的四个边缘都被 <code>0</code>（代表水）包围着。</p>

<p>岛屿的面积是岛上值为 <code>1</code> 的单元格的数目。</p>

<p>计算并返回 <code>grid</code> 中最大的岛屿面积。如果没有岛屿，则返回面积为 <code>0</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0600-0699/0695.Max%20Area%20of%20Island/images/maxarea1-grid.jpg" style="width: 500px; height: 310px;" />
<pre>
<strong>输入：</strong>grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
<strong>输出：</strong>6
<strong>解释：</strong>答案不应该是 <code>11</code> ，因为岛屿只能包含水平或垂直这四个方向上的 <code>1</code> 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>grid = [[0,0,0,0,0,0,0,0]]
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 50</code></li>
	<li><code>grid[i][j]</code> 为 <code>0</code> 或 <code>1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们可以遍历每一个格子 $(i, j)$，从每个格子开始进行深度优先搜索，如果搜索到的格子是陆地，就将当前格子标记为已访问，并且继续搜索上、下、左、右四个方向的格子。搜索结束后，计算标记的陆地的数量，即为岛屿的面积。我们找出最大的岛屿面积即为答案。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是二维数组的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        def dfs(i: int, j: int) -> int:
            if grid[i][j] == 0:
                return 0
            ans = 1
            grid[i][j] = 0
            dirs = (-1, 0, 1, 0, -1)
            for a, b in pairwise(dirs):
                x, y = i + a, j + b
                if 0 <= x < m and 0 <= y < n:
                    ans += dfs(x, y)
            return ans

        m, n = len(grid), len(grid[0])
        return max(dfs(i, j) for i in range(m) for j in range(n))
```

#### Java

```java
class Solution {
    private int m;
    private int n;
    private int[][] grid;

    public int maxAreaOfIsland(int[][] grid) {
        m = grid.length;
        n = grid[0].length;
        this.grid = grid;
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = Math.max(ans, dfs(i, j));
            }
        }
        return ans;
    }

    private int dfs(int i, int j) {
        if (grid[i][j] == 0) {
            return 0;
        }
        int ans = 1;
        grid[i][j] = 0;
        int[] dirs = {-1, 0, 1, 0, -1};
        for (int k = 0; k < 4; ++k) {
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x >= 0 && x < m && y >= 0 && y < n) {
                ans += dfs(x, y);
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
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dirs[5] = {-1, 0, 1, 0, -1};
        int ans = 0;
        function<int(int, int)> dfs = [&](int i, int j) {
            if (grid[i][j] == 0) {
                return 0;
            }
            int ans = 1;
            grid[i][j] = 0;
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    ans += dfs(x, y);
                }
            }
            return ans;
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = max(ans, dfs(i, j));
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maxAreaOfIsland(grid [][]int) (ans int) {
	m, n := len(grid), len(grid[0])
	dirs := [5]int{-1, 0, 1, 0, -1}
	var dfs func(i, j int) int
	dfs = func(i, j int) int {
		if grid[i][j] == 0 {
			return 0
		}
		ans := 1
		grid[i][j] = 0
		for k := 0; k < 4; k++ {
			x, y := i+dirs[k], j+dirs[k+1]
			if x >= 0 && x < m && y >= 0 && y < n {
				ans += dfs(x, y)
			}
		}
		return ans
	}
	for i := range grid {
		for j := range grid[i] {
			ans = max(ans, dfs(i, j))
		}
	}
	return
}
```

#### TypeScript

```ts
function maxAreaOfIsland(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;
    const dirs = [-1, 0, 1, 0, -1];
    const dfs = (i: number, j: number): number => {
        if (grid[i][j] === 0) {
            return 0;
        }
        let ans = 1;
        grid[i][j] = 0;
        for (let k = 0; k < 4; ++k) {
            const [x, y] = [i + dirs[k], j + dirs[k + 1]];
            if (x >= 0 && x < m && y >= 0 && y < n) {
                ans += dfs(x, y);
            }
        }
        return ans;
    };
    let ans = 0;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            ans = Math.max(ans, dfs(i, j));
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    fn dfs(grid: &mut Vec<Vec<i32>>, i: usize, j: usize) -> i32 {
        if i == grid.len() || j == grid[0].len() || grid[i][j] == 0 {
            return 0;
        }
        grid[i][j] = 0;
        let mut res = 1 + Self::dfs(grid, i + 1, j) + Self::dfs(grid, i, j + 1);
        if i != 0 {
            res += Self::dfs(grid, i - 1, j);
        }
        if j != 0 {
            res += Self::dfs(grid, i, j - 1);
        }
        res
    }

    pub fn max_area_of_island(mut grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        let mut res = 0;
        for i in 0..m {
            for j in 0..n {
                res = res.max(Self::dfs(&mut grid, i, j));
            }
        }
        res
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [696. 计数二进制子串](https://leetcode.cn/problems/count-binary-substrings){#696}

{{< tabs "696" >}}

{{% tab "python" %}}
```python
class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        i, n = 0, len(s)
        t = []
        while i < n:
            cnt = 1
            while i + 1 < n and s[i + 1] == s[i]:
                cnt += 1
                i += 1
            t.append(cnt)
            i += 1
        ans = 0
        for i in range(1, len(t)):
            ans += min(t[i - 1], t[i])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countBinarySubstrings(String s) {
        int i = 0, n = s.length();
        List<Integer> t = new ArrayList<>();
        while (i < n) {
            int cnt = 1;
            while (i + 1 < n && s.charAt(i + 1) == s.charAt(i)) {
                ++i;
                ++cnt;
            }
            t.add(cnt);
            ++i;
        }
        int ans = 0;
        for (i = 1; i < t.size(); ++i) {
            ans += Math.min(t.get(i - 1), t.get(i));
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
    int countBinarySubstrings(string s) {
        int i = 0, n = s.size();
        vector<int> t;
        while (i < n) {
            int cnt = 1;
            while (i + 1 < n && s[i + 1] == s[i]) {
                ++cnt;
                ++i;
            }
            t.push_back(cnt);
            ++i;
        }
        int ans = 0;
        for (i = 1; i < t.size(); ++i) ans += min(t[i - 1], t[i]);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countBinarySubstrings(s string) int {
	i, n := 0, len(s)
	var t []int
	for i < n {
		cnt := 1
		for i+1 < n && s[i+1] == s[i] {
			i++
			cnt++
		}
		t = append(t, cnt)
		i++
	}
	ans := 0
	for i := 1; i < len(t); i++ {
		ans += min(t[i-1], t[i])
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

<p>给定一个字符串&nbsp;<code>s</code>，统计并返回具有相同数量 <code>0</code> 和 <code>1</code> 的非空（连续）子字符串的数量，并且这些子字符串中的所有 <code>0</code> 和所有 <code>1</code> 都是成组连续的。</p>

<p>重复出现（不同位置）的子串也要统计它们出现的次数。</p>
&nbsp;

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "00110011"
<strong>输出：</strong>6
<strong>解释：</strong>6 个子串满足具有相同数量的连续 1 和 0 ："0011"、"01"、"1100"、"10"、"0011" 和 "01" 。
注意，一些重复出现的子串（不同位置）要统计它们出现的次数。
另外，"00110011" 不是有效的子串，因为所有的 0（还有 1 ）没有组合在一起。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "10101"
<strong>输出：</strong>4
<strong>解释：</strong>有 4 个子串："10"、"01"、"10"、"01" ，具有相同数量的连续 1 和 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code> 为 <code>'0'</code> 或 <code>'1'</code></li>
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
    def countBinarySubstrings(self, s: str) -> int:
        i, n = 0, len(s)
        t = []
        while i < n:
            cnt = 1
            while i + 1 < n and s[i + 1] == s[i]:
                cnt += 1
                i += 1
            t.append(cnt)
            i += 1
        ans = 0
        for i in range(1, len(t)):
            ans += min(t[i - 1], t[i])
        return ans
```

#### Java

```java
class Solution {
    public int countBinarySubstrings(String s) {
        int i = 0, n = s.length();
        List<Integer> t = new ArrayList<>();
        while (i < n) {
            int cnt = 1;
            while (i + 1 < n && s.charAt(i + 1) == s.charAt(i)) {
                ++i;
                ++cnt;
            }
            t.add(cnt);
            ++i;
        }
        int ans = 0;
        for (i = 1; i < t.size(); ++i) {
            ans += Math.min(t.get(i - 1), t.get(i));
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countBinarySubstrings(string s) {
        int i = 0, n = s.size();
        vector<int> t;
        while (i < n) {
            int cnt = 1;
            while (i + 1 < n && s[i + 1] == s[i]) {
                ++cnt;
                ++i;
            }
            t.push_back(cnt);
            ++i;
        }
        int ans = 0;
        for (i = 1; i < t.size(); ++i) ans += min(t[i - 1], t[i]);
        return ans;
    }
};
```

#### Go

```go
func countBinarySubstrings(s string) int {
	i, n := 0, len(s)
	var t []int
	for i < n {
		cnt := 1
		for i+1 < n && s[i+1] == s[i] {
			i++
			cnt++
		}
		t = append(t, cnt)
		i++
	}
	ans := 0
	for i := 1; i < len(t); i++ {
		ans += min(t[i-1], t[i])
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [697. 数组的度](https://leetcode.cn/problems/degree-of-an-array){#697}

{{< tabs "697" >}}

{{% tab "python" %}}
```python
class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        cnt = Counter(nums)
        degree = cnt.most_common()[0][1]
        left, right = {}, {}
        for i, v in enumerate(nums):
            if v not in left:
                left[v] = i
            right[v] = i
        ans = inf
        for v in nums:
            if cnt[v] == degree:
                t = right[v] - left[v] + 1
                if ans > t:
                    ans = t
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findShortestSubArray(int[] nums) {
        Map<Integer, Integer> cnt = new HashMap<>();
        Map<Integer, Integer> left = new HashMap<>();
        Map<Integer, Integer> right = new HashMap<>();
        int degree = 0;
        for (int i = 0; i < nums.length; ++i) {
            int v = nums[i];
            cnt.put(v, cnt.getOrDefault(v, 0) + 1);
            degree = Math.max(degree, cnt.get(v));
            if (!left.containsKey(v)) {
                left.put(v, i);
            }
            right.put(v, i);
        }
        int ans = 1000000;
        for (int v : nums) {
            if (cnt.get(v) == degree) {
                int t = right.get(v) - left.get(v) + 1;
                if (ans > t) {
                    ans = t;
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
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> cnt;
        unordered_map<int, int> left;
        unordered_map<int, int> right;
        int degree = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int v = nums[i];
            degree = max(degree, ++cnt[v]);
            if (!left.count(v)) {
                left[v] = i;
            }
            right[v] = i;
        }
        int ans = 1e6;
        for (int v : nums) {
            if (cnt[v] == degree) {
                int t = right[v] - left[v] + 1;
                if (ans > t) {
                    ans = t;
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
func findShortestSubArray(nums []int) (ans int) {
	ans = 50000
	numsMap := make(map[int]int, len(nums))
	for _, num := range nums {
		numsMap[num]++
	}
	var maxDegree int
	for _, num := range numsMap {
		maxDegree = max(num, maxDegree)
	}
	degreeNums := getMaxDegreeElem(maxDegree, numsMap)
	for _, num := range degreeNums {
		f := findSubArray(num, nums)
		ans = min(ans, f)
	}
	return
}

func findSubArray(target int, nums []int) int {
	start := getStartIdx(target, nums)
	end := getEndIdx(target, nums)
	return (end - start) + 1
}

func getStartIdx(target int, nums []int) (start int) {
	for idx, num := range nums {
		if num == target {
			start = idx
			break
		}
	}
	return start
}

func getEndIdx(target int, nums []int) (end int) {
	for i := len(nums) - 1; i > 0; i-- {
		if nums[i] == target {
			end = i
			break
		}
	}
	return
}

func getMaxDegreeElem(maxDegree int, numsMap map[int]int) []int {
	var ans []int
	for key, value := range numsMap {
		if value == maxDegree {
			ans = append(ans, key)
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

<p>给定一个非空且只包含非负数的整数数组&nbsp;<code>nums</code>，数组的 <strong>度</strong> 的定义是指数组里任一元素出现频数的最大值。</p>

<p>你的任务是在 <code>nums</code> 中找到与&nbsp;<code>nums</code>&nbsp;拥有相同大小的度的最短连续子数组，返回其长度。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,2,3,1]
<strong>输出：</strong>2
<strong>解释：</strong>
输入数组的度是 2 ，因为元素 1 和 2 的出现频数最大，均为 2 。
连续子数组里面拥有相同度的有如下所示：
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
最短连续子数组 [2, 2] 的长度为 2 ，所以返回 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,2,3,1,4,2]
<strong>输出：</strong>6
<strong>解释：</strong>
数组的度是 3 ，因为元素 2 重复出现 3 次。
所以 [2,2,3,1,4,2] 是最短子数组，因此返回 6 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>nums.length</code>&nbsp;在 <code>1</code> 到 <code>50,000</code> 范围内。</li>
	<li><code>nums[i]</code>&nbsp;是一个在 <code>0</code> 到 <code>49,999</code> 范围内的整数。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

遍历数组，用哈希表记录数组每个元素出现的次数，以及首次、末次出现的位置。然后遍历哈希表，获取元素出现次数最多（可能有多个）且首末位置差最小的数。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        cnt = Counter(nums)
        degree = cnt.most_common()[0][1]
        left, right = {}, {}
        for i, v in enumerate(nums):
            if v not in left:
                left[v] = i
            right[v] = i
        ans = inf
        for v in nums:
            if cnt[v] == degree:
                t = right[v] - left[v] + 1
                if ans > t:
                    ans = t
        return ans
```

#### Java

```java
class Solution {
    public int findShortestSubArray(int[] nums) {
        Map<Integer, Integer> cnt = new HashMap<>();
        Map<Integer, Integer> left = new HashMap<>();
        Map<Integer, Integer> right = new HashMap<>();
        int degree = 0;
        for (int i = 0; i < nums.length; ++i) {
            int v = nums[i];
            cnt.put(v, cnt.getOrDefault(v, 0) + 1);
            degree = Math.max(degree, cnt.get(v));
            if (!left.containsKey(v)) {
                left.put(v, i);
            }
            right.put(v, i);
        }
        int ans = 1000000;
        for (int v : nums) {
            if (cnt.get(v) == degree) {
                int t = right.get(v) - left.get(v) + 1;
                if (ans > t) {
                    ans = t;
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
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> cnt;
        unordered_map<int, int> left;
        unordered_map<int, int> right;
        int degree = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int v = nums[i];
            degree = max(degree, ++cnt[v]);
            if (!left.count(v)) {
                left[v] = i;
            }
            right[v] = i;
        }
        int ans = 1e6;
        for (int v : nums) {
            if (cnt[v] == degree) {
                int t = right[v] - left[v] + 1;
                if (ans > t) {
                    ans = t;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findShortestSubArray(nums []int) int {
	cnt := map[int]int{}
	left := map[int]int{}
	right := map[int]int{}
	var degree int
	for i, v := range nums {
		cnt[v]++
		if degree < cnt[v] {
			degree = cnt[v]
		}
		if _, ok := left[v]; !ok {
			left[v] = i
		}
		right[v] = i
	}
	ans := 100000
	for v, c := range cnt {
		if c == degree {
			t := right[v] - left[v] + 1
			if ans > t {
				ans = t
			}
		}
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Go

```go
func findShortestSubArray(nums []int) (ans int) {
	ans = 50000
	numsMap := make(map[int]int, len(nums))
	for _, num := range nums {
		numsMap[num]++
	}
	var maxDegree int
	for _, num := range numsMap {
		maxDegree = max(num, maxDegree)
	}
	degreeNums := getMaxDegreeElem(maxDegree, numsMap)
	for _, num := range degreeNums {
		f := findSubArray(num, nums)
		ans = min(ans, f)
	}
	return
}

func findSubArray(target int, nums []int) int {
	start := getStartIdx(target, nums)
	end := getEndIdx(target, nums)
	return (end - start) + 1
}

func getStartIdx(target int, nums []int) (start int) {
	for idx, num := range nums {
		if num == target {
			start = idx
			break
		}
	}
	return start
}

func getEndIdx(target int, nums []int) (end int) {
	for i := len(nums) - 1; i > 0; i-- {
		if nums[i] == target {
			end = i
			break
		}
	}
	return
}

func getMaxDegreeElem(maxDegree int, numsMap map[int]int) []int {
	var ans []int
	for key, value := range numsMap {
		if value == maxDegree {
			ans = append(ans, key)
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

# [698. 划分为k个相等的子集](https://leetcode.cn/problems/partition-to-k-equal-sum-subsets){#698}

{{< tabs "698" >}}

{{% tab "python" %}}
```python
class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        s = sum(nums)
        if s % k:
            return False
        s //= k
        nums.sort()
        n = len(nums)
        f = [False] * (1 << n)
        cur = [0] * (1 << n)
        f[0] = True
        for i in range(1 << n):
            if not f[i]:
                continue
            for j in range(n):
                if cur[i] + nums[j] > s:
                    break
                if (i >> j & 1) == 0:
                    if not f[i | 1 << j]:
                        cur[i | 1 << j] = (cur[i] + nums[j]) % s
                        f[i | 1 << j] = True
        return f[-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean canPartitionKSubsets(int[] nums, int k) {
        int s = 0;
        for (int x : nums) {
            s += x;
        }
        if (s % k != 0) {
            return false;
        }
        s /= k;
        Arrays.sort(nums);
        int n = nums.length;
        boolean[] f = new boolean[1 << n];
        f[0] = true;
        int[] cur = new int[1 << n];
        for (int i = 0; i < 1 << n; ++i) {
            if (!f[i]) {
                continue;
            }
            for (int j = 0; j < n; ++j) {
                if (cur[i] + nums[j] > s) {
                    break;
                }
                if ((i >> j & 1) == 0) {
                    cur[i | 1 << j] = (cur[i] + nums[j]) % s;
                    f[i | 1 << j] = true;
                }
            }
        }
        return f[(1 << n) - 1];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int s = accumulate(nums.begin(), nums.end(), 0);
        if (s % k) {
            return false;
        }
        s /= k;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        bool f[1 << n];
        int cur[1 << n];
        memset(f, false, sizeof(f));
        memset(cur, 0, sizeof(cur));
        f[0] = 1;
        for (int i = 0; i < 1 << n; ++i) {
            if (!f[i]) {
                continue;
            }
            for (int j = 0; j < n; ++j) {
                if (cur[i] + nums[j] > s) {
                    break;
                }
                if ((i >> j & 1) == 0) {
                    f[i | 1 << j] = true;
                    cur[i | 1 << j] = (cur[i] + nums[j]) % s;
                }
            }
        }
        return f[(1 << n) - 1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func canPartitionKSubsets(nums []int, k int) bool {
	s := 0
	for _, x := range nums {
		s += x
	}
	if s%k != 0 {
		return false
	}
	s /= k
	sort.Ints(nums)
	n := len(nums)
	f := make([]bool, 1<<n)
	cur := make([]int, 1<<n)
	f[0] = true
	for i := 0; i < 1<<n; i++ {
		if !f[i] {
			continue
		}
		for j := 0; j < n; j++ {
			if cur[i]+nums[j] > s {
				break
			}
			if i>>j&1 == 0 {
				f[i|1<<j] = true
				cur[i|1<<j] = (cur[i] + nums[j]) % s
			}
		}
	}
	return f[(1<<n)-1]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function canPartitionKSubsets(nums: number[], k: number): boolean {
    let s = nums.reduce((a, b) => a + b);
    if (s % k !== 0) {
        return false;
    }
    s /= k;
    nums.sort((a, b) => a - b);
    const n = nums.length;
    const f: boolean[] = Array(1 << n).fill(false);
    f[0] = true;
    const cur: number[] = Array(n).fill(0);
    for (let i = 0; i < 1 << n; ++i) {
        if (!f[i]) {
            continue;
        }
        for (let j = 0; j < n; ++j) {
            if (cur[i] + nums[j] > s) {
                break;
            }
            if (((i >> j) & 1) === 0) {
                f[i | (1 << j)] = true;
                cur[i | (1 << j)] = (cur[i] + nums[j]) % s;
            }
        }
    }
    return f[(1 << n) - 1];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个整数数组&nbsp;&nbsp;<code>nums</code> 和一个正整数 <code>k</code>，找出是否有可能把这个数组分成 <code>k</code> 个非空子集，其总和都相等。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong> nums = [4, 3, 2, 3, 5, 2, 1], k = 4
<strong>输出：</strong> True
<strong>说明：</strong> 有可能将其分成 4 个子集（5），（1,4），（2,3），（2,3）等于总和。</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> nums = [1,2,3,4], k = 3
<strong>输出:</strong> false</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= len(nums) &lt;= 16</code></li>
	<li><code>0 &lt; nums[i] &lt; 10000</code></li>
	<li>每个元素的频率在 <code>[1,4]</code> 范围内</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS + 剪枝

根据题意，我们需要将数组 $\textit{nums}$ 划分为 $k$ 个子集，且每个子集的和相等。因此，先累加 $\textit{nums}$ 中所有元素的和，如果不能被 $k$ 整除，说明无法划分为 $k$ 个子集，提前返回 $\textit{false}$。

如果能被 $k$ 整除，不妨将每个子集期望的和记为 $s$，然后创建一个长度为 $k$ 的数组 $\textit{cur}$，表示当前每个子集的和。

对数组 $\textit{nums}$ 进行降序排序（减少搜索次数），然后从第一个元素开始，依次尝试将其加入到 $\textit{cur}$ 的每个子集中。这里如果将 $\textit{nums}[i]$ 加入某个子集 $\textit{cur}[j]$ 后，子集的和超过 $s$，说明无法放入，可以直接跳过；另外，如果 $\textit{cur}[j]$ 与 $\textit{cur}[j - 1]$ 相等，意味着我们在 $\textit{cur}[j - 1]$ 的时候已经完成了搜索，也可以跳过当前的搜索。

如果能将所有元素都加入到 $\textit{cur}$ 中，说明可以划分为 $k$ 个子集，返回 $\textit{true}$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        def dfs(i):
            if i == len(nums):
                return True
            for j in range(k):
                if j and cur[j] == cur[j - 1]:
                    continue
                cur[j] += nums[i]
                if cur[j] <= s and dfs(i + 1):
                    return True
                cur[j] -= nums[i]
            return False

        s, mod = divmod(sum(nums), k)
        if mod:
            return False
        cur = [0] * k
        nums.sort(reverse=True)
        return dfs(0)
```

#### Java

```java
class Solution {
    private int[] nums;
    private int[] cur;
    private int s;

    public boolean canPartitionKSubsets(int[] nums, int k) {
        for (int v : nums) {
            s += v;
        }
        if (s % k != 0) {
            return false;
        }
        s /= k;
        cur = new int[k];
        Arrays.sort(nums);
        this.nums = nums;
        return dfs(nums.length - 1);
    }

    private boolean dfs(int i) {
        if (i < 0) {
            return true;
        }
        for (int j = 0; j < cur.length; ++j) {
            if (j > 0 && cur[j] == cur[j - 1]) {
                continue;
            }
            cur[j] += nums[i];
            if (cur[j] <= s && dfs(i - 1)) {
                return true;
            }
            cur[j] -= nums[i];
        }
        return false;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int s = accumulate(nums.begin(), nums.end(), 0);
        if (s % k) {
            return false;
        }
        s /= k;
        int n = nums.size();
        vector<int> cur(k);
        function<bool(int)> dfs = [&](int i) {
            if (i == n) {
                return true;
            }
            for (int j = 0; j < k; ++j) {
                if (j && cur[j] == cur[j - 1]) {
                    continue;
                }
                cur[j] += nums[i];
                if (cur[j] <= s && dfs(i + 1)) {
                    return true;
                }
                cur[j] -= nums[i];
            }
            return false;
        };
        sort(nums.begin(), nums.end(), greater<int>());
        return dfs(0);
    }
};
```

#### Go

```go
func canPartitionKSubsets(nums []int, k int) bool {
	s := 0
	for _, v := range nums {
		s += v
	}
	if s%k != 0 {
		return false
	}
	s /= k
	cur := make([]int, k)
	n := len(nums)

	var dfs func(int) bool
	dfs = func(i int) bool {
		if i == n {
			return true
		}
		for j := 0; j < k; j++ {
			if j > 0 && cur[j] == cur[j-1] {
				continue
			}
			cur[j] += nums[i]
			if cur[j] <= s && dfs(i+1) {
				return true
			}
			cur[j] -= nums[i]
		}
		return false
	}

	sort.Sort(sort.Reverse(sort.IntSlice(nums)))
	return dfs(0)
}
```

#### TypeScript

```ts
function canPartitionKSubsets(nums: number[], k: number): boolean {
    const dfs = (i: number): boolean => {
        if (i === nums.length) {
            return true;
        }
        for (let j = 0; j < k; j++) {
            if (j > 0 && cur[j] === cur[j - 1]) {
                continue;
            }
            cur[j] += nums[i];
            if (cur[j] <= s && dfs(i + 1)) {
                return true;
            }
            cur[j] -= nums[i];
        }
        return false;
    };

    let s = nums.reduce((a, b) => a + b, 0);
    const mod = s % k;
    if (mod !== 0) {
        return false;
    }
    s = Math.floor(s / k);
    const cur = Array(k).fill(0);
    nums.sort((a, b) => b - a);
    return dfs(0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：状态压缩 + 记忆化搜索

与方法一相同，我们依然先判断数组 $\textit{nums}$ 是否有可能被划分为 $k$ 个子集。如果不能被 $k$ 整除，直接返回 $\textit{false}$。

我们记 $s$ 为每个子集期望的和，当前元素被划分的情况为 $\textit{state}$。对于第 $i$ 个数，若 $\textit{state}$ 的第 $i$ 位为 $0$，说明第 $i$ 个元素未被划分。

我们的目标是从全部元素中凑出 $k$ 个和为 $s$ 的子集。记当前子集的和为 $t$。在未划分第 $i$ 个元素时：

-   若 $t + \textit{nums}[i] \gt s$，说明第 $i$ 个元素不能被添加到当前子集中，由于我们对 $\textit{nums}$ 数组进行升序排列，因此数组 $\textit{nums}$ 从位置 $i$ 开始的所有元素都不能被添加到当前子集，直接返回 $\textit{false}$。
-   否则，将第 $i$ 个元素添加到当前子集中，状态变为 $\textit{state} | 2^i$，然后继续对未划分的元素进行搜索。需要注意的是，若 $t + \textit{nums}[i] = s$，说明恰好可以得到一个和为 $s$ 的子集，下一步将 $t$ 归零（可以通过 $(t + \textit{nums}[i]) \bmod s$ 实现），并继续划分下一个子集。

为了避免重复搜索，我们使用一个长度为 $2^n$ 的数组 $\textit{f}$ 记录每个状态下的搜索结果。数组 $\textit{f}$ 有三个可能的值：

-   `0`：表示当前状态还未搜索过；
-   `-1`：表示当前状态下无法划分为 $k$ 个子集；
-   `1`：表示当前状态下可以划分为 $k$ 个子集。

时间复杂度 $O(n \times 2^n)$，空间复杂度 $O(2^n)$。其中 $n$ 表示数组 $\textit{nums}$ 的长度。对于每个状态，我们需要遍历数组 $\textit{nums}$，时间复杂度为 $O(n)$；状态总数为 $2^n$，因此总的时间复杂度为 $O(n\times 2^n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        @cache
        def dfs(state, t):
            if state == mask:
                return True
            for i, v in enumerate(nums):
                if (state >> i) & 1:
                    continue
                if t + v > s:
                    break
                if dfs(state | 1 << i, (t + v) % s):
                    return True
            return False

        s, mod = divmod(sum(nums), k)
        if mod:
            return False
        nums.sort()
        mask = (1 << len(nums)) - 1
        return dfs(0, 0)
```

#### Java

```java
class Solution {
    private int[] f;
    private int[] nums;
    private int n;
    private int s;

    public boolean canPartitionKSubsets(int[] nums, int k) {
        for (int v : nums) {
            s += v;
        }
        if (s % k != 0) {
            return false;
        }
        s /= k;
        Arrays.sort(nums);
        this.nums = nums;
        n = nums.length;
        f = new int[1 << n];
        return dfs(0, 0);
    }

    private boolean dfs(int state, int t) {
        if (state == (1 << n) - 1) {
            return true;
        }
        if (f[state] != 0) {
            return f[state] == 1;
        }
        for (int i = 0; i < n; ++i) {
            if (((state >> i) & 1) == 1) {
                continue;
            }
            if (t + nums[i] > s) {
                break;
            }
            if (dfs(state | 1 << i, (t + nums[i]) % s)) {
                f[state] = 1;
                return true;
            }
        }
        f[state] = -1;
        return false;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int s = accumulate(nums.begin(), nums.end(), 0);
        if (s % k) {
            return false;
        }
        s /= k;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int mask = (1 << n) - 1;
        vector<int> f(1 << n);
        function<bool(int, int)> dfs = [&](int state, int t) {
            if (state == mask) {
                return true;
            }
            if (f[state]) {
                return f[state] == 1;
            }
            for (int i = 0; i < n; ++i) {
                if (state >> i & 1) {
                    continue;
                }
                if (t + nums[i] > s) {
                    break;
                }
                if (dfs(state | 1 << i, (t + nums[i]) % s)) {
                    f[state] = 1;
                    return true;
                }
            }
            f[state] = -1;
            return false;
        };
        return dfs(0, 0);
    }
};
```

#### Go

```go
func canPartitionKSubsets(nums []int, k int) bool {
	s := 0
	for _, v := range nums {
		s += v
	}
	if s%k != 0 {
		return false
	}
	s /= k
	n := len(nums)
	f := make([]int, 1<<n)
	mask := (1 << n) - 1

	var dfs func(int, int) bool
	dfs = func(state, t int) bool {
		if state == mask {
			return true
		}
		if f[state] != 0 {
			return f[state] == 1
		}
		for i, v := range nums {
			if (state >> i & 1) == 1 {
				continue
			}
			if t+v > s {
				break
			}
			if dfs(state|1<<i, (t+v)%s) {
				f[state] = 1
				return true
			}
		}
		f[state] = -1
		return false
	}

	sort.Ints(nums)
	return dfs(0, 0)
}
```

#### TypeScript

```ts
function canPartitionKSubsets(nums: number[], k: number): boolean {
    let s = nums.reduce((a, b) => a + b, 0);
    if (s % k !== 0) {
        return false;
    }
    s = Math.floor(s / k);
    nums.sort((a, b) => a - b);
    const n = nums.length;
    const mask = (1 << n) - 1;
    const f = Array(1 << n).fill(0);

    const dfs = (state: number, t: number): boolean => {
        if (state === mask) {
            return true;
        }
        if (f[state] !== 0) {
            return f[state] === 1;
        }
        for (let i = 0; i < n; ++i) {
            if ((state >> i) & 1) {
                continue;
            }
            if (t + nums[i] > s) {
                break;
            }
            if (dfs(state | (1 << i), (t + nums[i]) % s)) {
                f[state] = 1;
                return true;
            }
        }
        f[state] = -1;
        return false;
    };

    return dfs(0, 0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三：动态规划

我们可以使用动态规划的方法求解本题。

我们定义 $f[i]$ 表示当前选取的数字的状态为 $i$ 时，是否存在 $k$ 个子集满足题目要求。初始时 $f[0]= true$，答案为 $f[2^n-1]$。其中 $n$ 表示数组 $nums$ 的长度。另外，我们定义 $cur[i]$ 表示当前选取的数字的状态为 $i$ 时，最后一个子集的和。

我们在 $[0, 2^n]$ 的范围内枚举状态 $i$，对于每个状态 $i$，如果 $f[i]$ 为 $\textit{false}$，我们直接跳过即可。否则，我们枚举 $\textit{nums}$ 数组中的任意一个数 $\textit{nums}[j]$，如果 $\textit{cur}[i] + \textit{nums}[j] > s$，我们直接跳出枚举循环，因为后面的数更大，无法放入当前子集；否则，如果 $i$ 的二进制表示的第 $j$ 位为 $0$，说明当前 $\textit{nums}[j]$ 还没有被选取，我们可以将其放入当前子集中，此时状态变为 $i | 2^j$，并更新 $\textit{cur}[i | 2^j] = (\textit{cur}[i] + \textit{nums}[j]) \bmod s$，并且 $f[i | 2^j] = \textit{true}$。

最后，我们返回 $f[2^n - 1]$ 即可。

时间复杂度 $O(n \times 2^n)$，空间复杂度 $O(2^n)$。其中 $n$ 表示数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        s = sum(nums)
        if s % k:
            return False
        s //= k
        nums.sort()
        n = len(nums)
        f = [False] * (1 << n)
        cur = [0] * (1 << n)
        f[0] = True
        for i in range(1 << n):
            if not f[i]:
                continue
            for j in range(n):
                if cur[i] + nums[j] > s:
                    break
                if (i >> j & 1) == 0:
                    if not f[i | 1 << j]:
                        cur[i | 1 << j] = (cur[i] + nums[j]) % s
                        f[i | 1 << j] = True
        return f[-1]
```

#### Java

```java
class Solution {
    public boolean canPartitionKSubsets(int[] nums, int k) {
        int s = 0;
        for (int x : nums) {
            s += x;
        }
        if (s % k != 0) {
            return false;
        }
        s /= k;
        Arrays.sort(nums);
        int n = nums.length;
        boolean[] f = new boolean[1 << n];
        f[0] = true;
        int[] cur = new int[1 << n];
        for (int i = 0; i < 1 << n; ++i) {
            if (!f[i]) {
                continue;
            }
            for (int j = 0; j < n; ++j) {
                if (cur[i] + nums[j] > s) {
                    break;
                }
                if ((i >> j & 1) == 0) {
                    cur[i | 1 << j] = (cur[i] + nums[j]) % s;
                    f[i | 1 << j] = true;
                }
            }
        }
        return f[(1 << n) - 1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int s = accumulate(nums.begin(), nums.end(), 0);
        if (s % k) {
            return false;
        }
        s /= k;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        bool f[1 << n];
        int cur[1 << n];
        memset(f, false, sizeof(f));
        memset(cur, 0, sizeof(cur));
        f[0] = 1;
        for (int i = 0; i < 1 << n; ++i) {
            if (!f[i]) {
                continue;
            }
            for (int j = 0; j < n; ++j) {
                if (cur[i] + nums[j] > s) {
                    break;
                }
                if ((i >> j & 1) == 0) {
                    f[i | 1 << j] = true;
                    cur[i | 1 << j] = (cur[i] + nums[j]) % s;
                }
            }
        }
        return f[(1 << n) - 1];
    }
};
```

#### Go

```go
func canPartitionKSubsets(nums []int, k int) bool {
	s := 0
	for _, x := range nums {
		s += x
	}
	if s%k != 0 {
		return false
	}
	s /= k
	sort.Ints(nums)
	n := len(nums)
	f := make([]bool, 1<<n)
	cur := make([]int, 1<<n)
	f[0] = true
	for i := 0; i < 1<<n; i++ {
		if !f[i] {
			continue
		}
		for j := 0; j < n; j++ {
			if cur[i]+nums[j] > s {
				break
			}
			if i>>j&1 == 0 {
				f[i|1<<j] = true
				cur[i|1<<j] = (cur[i] + nums[j]) % s
			}
		}
	}
	return f[(1<<n)-1]
}
```

#### TypeScript

```ts
function canPartitionKSubsets(nums: number[], k: number): boolean {
    let s = nums.reduce((a, b) => a + b);
    if (s % k !== 0) {
        return false;
    }
    s /= k;
    nums.sort((a, b) => a - b);
    const n = nums.length;
    const f: boolean[] = Array(1 << n).fill(false);
    f[0] = true;
    const cur: number[] = Array(n).fill(0);
    for (let i = 0; i < 1 << n; ++i) {
        if (!f[i]) {
            continue;
        }
        for (let j = 0; j < n; ++j) {
            if (cur[i] + nums[j] > s) {
                break;
            }
            if (((i >> j) & 1) === 0) {
                f[i | (1 << j)] = true;
                cur[i | (1 << j)] = (cur[i] + nums[j]) % s;
            }
        }
    }
    return f[(1 << n) - 1];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [699. 掉落的方块](https://leetcode.cn/problems/falling-squares){#699}

{{< tabs "699" >}}

{{% tab "python" %}}
```python
class Node:
    def __init__(self, l, r):
        self.left = None
        self.right = None
        self.l = l
        self.r = r
        self.mid = (l + r) >> 1
        self.v = 0
        self.add = 0


class SegmentTree:
    def __init__(self):
        self.root = Node(1, int(1e9))

    def modify(self, l, r, v, node=None):
        if l > r:
            return
        if node is None:
            node = self.root
        if node.l >= l and node.r <= r:
            node.v = v
            node.add = v
            return
        self.pushdown(node)
        if l <= node.mid:
            self.modify(l, r, v, node.left)
        if r > node.mid:
            self.modify(l, r, v, node.right)
        self.pushup(node)

    def query(self, l, r, node=None):
        if l > r:
            return 0
        if node is None:
            node = self.root
        if node.l >= l and node.r <= r:
            return node.v
        self.pushdown(node)
        v = 0
        if l <= node.mid:
            v = max(v, self.query(l, r, node.left))
        if r > node.mid:
            v = max(v, self.query(l, r, node.right))
        return v

    def pushup(self, node):
        node.v = max(node.left.v, node.right.v)

    def pushdown(self, node):
        if node.left is None:
            node.left = Node(node.l, node.mid)
        if node.right is None:
            node.right = Node(node.mid + 1, node.r)
        if node.add:
            node.left.v = node.add
            node.right.v = node.add
            node.left.add = node.add
            node.right.add = node.add
            node.add = 0


class Solution:
    def fallingSquares(self, positions: List[List[int]]) -> List[int]:
        ans = []
        mx = 0
        tree = SegmentTree()
        for l, w in positions:
            r = l + w - 1
            h = tree.query(l, r) + w
            mx = max(mx, h)
            ans.append(mx)
            tree.modify(l, r, h)
        return ans
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
    private Node root = new Node(1, (int) 1e9);

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
            node.v = v;
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
            v = Math.max(v, query(l, r, node.left));
        }
        if (r > node.mid) {
            v = Math.max(v, query(l, r, node.right));
        }
        return v;
    }

    public void pushup(Node node) {
        node.v = Math.max(node.left.v, node.right.v);
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
            left.v = node.add;
            right.v = node.add;
            node.add = 0;
        }
    }
}

class Solution {
    public List<Integer> fallingSquares(int[][] positions) {
        List<Integer> ans = new ArrayList<>();
        SegmentTree tree = new SegmentTree();
        int mx = 0;
        for (int[] p : positions) {
            int l = p[0], w = p[1], r = l + w - 1;
            int h = tree.query(l, r) + w;
            mx = Math.max(mx, h);
            ans.add(mx);
            tree.modify(l, r, h);
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Node {
public:
    Node* left;
    Node* right;
    int l;
    int r;
    int mid;
    int v;
    int add;

    Node(int l, int r) {
        this->l = l;
        this->r = r;
        this->mid = (l + r) >> 1;
        this->left = this->right = nullptr;
        v = add = 0;
    }
};

class SegmentTree {
private:
    Node* root;

public:
    SegmentTree() {
        root = new Node(1, 1e9);
    }

    void modify(int l, int r, int v) {
        modify(l, r, v, root);
    }

    void modify(int l, int r, int v, Node* node) {
        if (l > r) return;
        if (node->l >= l && node->r <= r) {
            node->v = v;
            node->add = v;
            return;
        }
        pushdown(node);
        if (l <= node->mid) modify(l, r, v, node->left);
        if (r > node->mid) modify(l, r, v, node->right);
        pushup(node);
    }

    int query(int l, int r) {
        return query(l, r, root);
    }

    int query(int l, int r, Node* node) {
        if (l > r) return 0;
        if (node->l >= l && node->r <= r) return node->v;
        pushdown(node);
        int v = 0;
        if (l <= node->mid) v = max(v, query(l, r, node->left));
        if (r > node->mid) v = max(v, query(l, r, node->right));
        return v;
    }

    void pushup(Node* node) {
        node->v = max(node->left->v, node->right->v);
    }

    void pushdown(Node* node) {
        if (!node->left) node->left = new Node(node->l, node->mid);
        if (!node->right) node->right = new Node(node->mid + 1, node->r);
        if (node->add) {
            Node* left = node->left;
            Node* right = node->right;
            left->v = node->add;
            right->v = node->add;
            left->add = node->add;
            right->add = node->add;
            node->add = 0;
        }
    }
};

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<int> ans;
        SegmentTree* tree = new SegmentTree();
        int mx = 0;
        for (auto& p : positions) {
            int l = p[0], w = p[1], r = l + w - 1;
            int h = tree->query(l, r) + w;
            mx = max(mx, h);
            ans.push_back(mx);
            tree->modify(l, r, h);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type node struct {
	left      *node
	right     *node
	l, mid, r int
	v, add    int
}

func newNode(l, r int) *node {
	return &node{
		l:   l,
		r:   r,
		mid: (l + r) >> 1,
	}
}

type segmentTree struct {
	root *node
}

func newSegmentTree() *segmentTree {
	return &segmentTree{
		root: newNode(1, 1e9),
	}
}

func (t *segmentTree) modify(l, r, v int, n *node) {
	if l > r {
		return
	}
	if n.l >= l && n.r <= r {
		n.v = v
		n.add = v
		return
	}
	t.pushdown(n)
	if l <= n.mid {
		t.modify(l, r, v, n.left)
	}
	if r > n.mid {
		t.modify(l, r, v, n.right)
	}
	t.pushup(n)
}

func (t *segmentTree) query(l, r int, n *node) int {
	if l > r {
		return 0
	}
	if n.l >= l && n.r <= r {
		return n.v
	}
	t.pushdown(n)
	v := 0
	if l <= n.mid {
		v = max(v, t.query(l, r, n.left))
	}
	if r > n.mid {
		v = max(v, t.query(l, r, n.right))
	}
	return v
}

func (t *segmentTree) pushup(n *node) {
	n.v = max(n.left.v, n.right.v)
}

func (t *segmentTree) pushdown(n *node) {
	if n.left == nil {
		n.left = newNode(n.l, n.mid)
	}
	if n.right == nil {
		n.right = newNode(n.mid+1, n.r)
	}
	if n.add != 0 {
		n.left.add = n.add
		n.right.add = n.add
		n.left.v = n.add
		n.right.v = n.add
		n.add = 0
	}
}

func fallingSquares(positions [][]int) []int {
	ans := make([]int, len(positions))
	t := newSegmentTree()
	mx := 0
	for i, p := range positions {
		l, w, r := p[0], p[1], p[0]+p[1]-1
		h := t.query(l, r, t.root) + w
		mx = max(mx, h)
		ans[i] = mx
		t.modify(l, r, h, t.root)
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class Node {
    left: Node | null = null;
    right: Node | null = null;
    l: number;
    r: number;
    mid: number;
    v: number = 0;
    add: number = 0;

    constructor(l: number, r: number) {
        this.l = l;
        this.r = r;
        this.mid = (l + r) >> 1;
    }
}

class SegmentTree {
    private root: Node = new Node(1, 1e9);

    public modify(l: number, r: number, v: number): void {
        this.modifyNode(l, r, v, this.root);
    }

    private modifyNode(l: number, r: number, v: number, node: Node): void {
        if (l > r) {
            return;
        }
        if (node.l >= l && node.r <= r) {
            node.v = v;
            node.add = v;
            return;
        }
        this.pushdown(node);
        if (l <= node.mid) {
            this.modifyNode(l, r, v, node.left!);
        }
        if (r > node.mid) {
            this.modifyNode(l, r, v, node.right!);
        }
        this.pushup(node);
    }

    public query(l: number, r: number): number {
        return this.queryNode(l, r, this.root);
    }

    private queryNode(l: number, r: number, node: Node): number {
        if (l > r) {
            return 0;
        }
        if (node.l >= l && node.r <= r) {
            return node.v;
        }
        this.pushdown(node);
        let v = 0;
        if (l <= node.mid) {
            v = Math.max(v, this.queryNode(l, r, node.left!));
        }
        if (r > node.mid) {
            v = Math.max(v, this.queryNode(l, r, node.right!));
        }
        return v;
    }

    private pushup(node: Node): void {
        node.v = Math.max(node.left!.v, node.right!.v);
    }

    private pushdown(node: Node): void {
        if (node.left == null) {
            node.left = new Node(node.l, node.mid);
        }
        if (node.right == null) {
            node.right = new Node(node.mid + 1, node.r);
        }
        if (node.add != 0) {
            let left = node.left,
                right = node.right;
            left!.add = node.add;
            right!.add = node.add;
            left!.v = node.add;
            right!.v = node.add;
            node.add = 0;
        }
    }
}

function fallingSquares(positions: number[][]): number[] {
    const ans: number[] = [];
    const tree = new SegmentTree();
    let mx = 0;
    for (const [l, w] of positions) {
        const r = l + w - 1;
        const h = tree.query(l, r) + w;
        mx = Math.max(mx, h);
        ans.push(mx);
        tree.modify(l, r, h);
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

<p>在二维平面上的 x 轴上，放置着一些方块。</p>

<p>给你一个二维整数数组 <code>positions</code> ，其中 <code>positions[i] = [left<sub>i</sub>, sideLength<sub>i</sub>]</code> 表示：第 <code>i</code> 个方块边长为 <code>sideLength<sub>i</sub></code> ，其左侧边与 x 轴上坐标点&nbsp;<code>left<sub>i</sub></code> 对齐。</p>

<p>每个方块都从一个比目前所有的落地方块更高的高度掉落而下。方块沿 y 轴负方向下落，直到着陆到 <strong>另一个正方形的顶边</strong> 或者是 <strong>x 轴上</strong> 。一个方块仅仅是擦过另一个方块的左侧边或右侧边不算着陆。一旦着陆，它就会固定在原地，无法移动。</p>

<p>在每个方块掉落后，你必须记录目前所有已经落稳的 <strong>方块堆叠的最高高度</strong> 。</p>

<p>返回一个整数数组 <code>ans</code> ，其中 <code>ans[i]</code> 表示在第 <code>i</code> 块方块掉落后堆叠的最高高度。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0600-0699/0699.Falling%20Squares/images/fallingsq1-plane.jpg" style="width: 500px; height: 505px;" />
<pre>
<strong>输入：</strong>positions = [[1,2],[2,3],[6,1]]
<strong>输出：</strong>[2,5,5]
<strong>解释：</strong>
第 1 个方块掉落后，最高的堆叠由方块 1 组成，堆叠的最高高度为 2 。
第 2 个方块掉落后，最高的堆叠由方块 1 和 2 组成，堆叠的最高高度为 5 。
第 3 个方块掉落后，最高的堆叠仍然由方块 1 和 2 组成，堆叠的最高高度为 5 。
因此，返回 [2, 5, 5] 作为答案。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>positions = [[100,100],[200,100]]
<strong>输出：</strong>[100,100]
<strong>解释：</strong>
第 1 个方块掉落后，最高的堆叠由方块 1 组成，堆叠的最高高度为 100 。
第 2 个方块掉落后，最高的堆叠可以由方块 1 组成也可以由方块 2 组成，堆叠的最高高度为 100 。
因此，返回 [100, 100] 作为答案。
注意，方块 2 擦过方块 1 的右侧边，但不会算作在方块 1 上着陆。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= positions.length &lt;= 1000</code></li>
	<li><code>1 &lt;= left<sub>i</sub> &lt;= 10<sup>8</sup></code></li>
	<li><code>1 &lt;= sideLength<sub>i</sub> &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：线段树

根据题目描述，我们需要维护一个区间集合，支持区间的修改和查询操作。这种情况下，我们可以使用线段树来解决。

线段树将整个区间分割为多个不连续的子区间，子区间的数量不超过 $\log(width)$，其中 $width$ 是区间的长度。更新某个元素的值，只需要更新 $\log(width)$ 个区间，并且这些区间都包含在一个包含该元素的大区间内。区间修改时，需要使用**懒标记**保证效率。

-   线段树的每个节点代表一个区间；
-   线段树具有唯一的根节点，代表的区间是整个统计范围，如 $[1, n]$；
-   线段树的每个叶子节点代表一个长度为 1 的元区间 $[x, x]$；
-   对于每个内部节点 $[l, r]$，它的左儿子是 $[l, mid]$，右儿子是 $[mid + 1, r]$, 其中 $\textit{mid} = \frac{l + r}{2}$；

对于本题，线段树节点维护的信息有：

1. 区间中方块的最大高度 $v$
1. 懒标记 $add$

另外，由于数轴范围很大，达到 $10^8$，因此我们采用动态开点。

时间复杂度方面，每次查询和修改的时间复杂度为 $O(\log n)$，总时间复杂度为 $O(n \log n)$。空间复杂度为 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class Node:
    def __init__(self, l, r):
        self.left = None
        self.right = None
        self.l = l
        self.r = r
        self.mid = (l + r) >> 1
        self.v = 0
        self.add = 0


class SegmentTree:
    def __init__(self):
        self.root = Node(1, int(1e9))

    def modify(self, l, r, v, node=None):
        if l > r:
            return
        if node is None:
            node = self.root
        if node.l >= l and node.r <= r:
            node.v = v
            node.add = v
            return
        self.pushdown(node)
        if l <= node.mid:
            self.modify(l, r, v, node.left)
        if r > node.mid:
            self.modify(l, r, v, node.right)
        self.pushup(node)

    def query(self, l, r, node=None):
        if l > r:
            return 0
        if node is None:
            node = self.root
        if node.l >= l and node.r <= r:
            return node.v
        self.pushdown(node)
        v = 0
        if l <= node.mid:
            v = max(v, self.query(l, r, node.left))
        if r > node.mid:
            v = max(v, self.query(l, r, node.right))
        return v

    def pushup(self, node):
        node.v = max(node.left.v, node.right.v)

    def pushdown(self, node):
        if node.left is None:
            node.left = Node(node.l, node.mid)
        if node.right is None:
            node.right = Node(node.mid + 1, node.r)
        if node.add:
            node.left.v = node.add
            node.right.v = node.add
            node.left.add = node.add
            node.right.add = node.add
            node.add = 0


class Solution:
    def fallingSquares(self, positions: List[List[int]]) -> List[int]:
        ans = []
        mx = 0
        tree = SegmentTree()
        for l, w in positions:
            r = l + w - 1
            h = tree.query(l, r) + w
            mx = max(mx, h)
            ans.append(mx)
            tree.modify(l, r, h)
        return ans
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
    private Node root = new Node(1, (int) 1e9);

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
            node.v = v;
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
            v = Math.max(v, query(l, r, node.left));
        }
        if (r > node.mid) {
            v = Math.max(v, query(l, r, node.right));
        }
        return v;
    }

    public void pushup(Node node) {
        node.v = Math.max(node.left.v, node.right.v);
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
            left.v = node.add;
            right.v = node.add;
            node.add = 0;
        }
    }
}

class Solution {
    public List<Integer> fallingSquares(int[][] positions) {
        List<Integer> ans = new ArrayList<>();
        SegmentTree tree = new SegmentTree();
        int mx = 0;
        for (int[] p : positions) {
            int l = p[0], w = p[1], r = l + w - 1;
            int h = tree.query(l, r) + w;
            mx = Math.max(mx, h);
            ans.add(mx);
            tree.modify(l, r, h);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Node {
public:
    Node* left;
    Node* right;
    int l;
    int r;
    int mid;
    int v;
    int add;

    Node(int l, int r) {
        this->l = l;
        this->r = r;
        this->mid = (l + r) >> 1;
        this->left = this->right = nullptr;
        v = add = 0;
    }
};

class SegmentTree {
private:
    Node* root;

public:
    SegmentTree() {
        root = new Node(1, 1e9);
    }

    void modify(int l, int r, int v) {
        modify(l, r, v, root);
    }

    void modify(int l, int r, int v, Node* node) {
        if (l > r) return;
        if (node->l >= l && node->r <= r) {
            node->v = v;
            node->add = v;
            return;
        }
        pushdown(node);
        if (l <= node->mid) modify(l, r, v, node->left);
        if (r > node->mid) modify(l, r, v, node->right);
        pushup(node);
    }

    int query(int l, int r) {
        return query(l, r, root);
    }

    int query(int l, int r, Node* node) {
        if (l > r) return 0;
        if (node->l >= l && node->r <= r) return node->v;
        pushdown(node);
        int v = 0;
        if (l <= node->mid) v = max(v, query(l, r, node->left));
        if (r > node->mid) v = max(v, query(l, r, node->right));
        return v;
    }

    void pushup(Node* node) {
        node->v = max(node->left->v, node->right->v);
    }

    void pushdown(Node* node) {
        if (!node->left) node->left = new Node(node->l, node->mid);
        if (!node->right) node->right = new Node(node->mid + 1, node->r);
        if (node->add) {
            Node* left = node->left;
            Node* right = node->right;
            left->v = node->add;
            right->v = node->add;
            left->add = node->add;
            right->add = node->add;
            node->add = 0;
        }
    }
};

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<int> ans;
        SegmentTree* tree = new SegmentTree();
        int mx = 0;
        for (auto& p : positions) {
            int l = p[0], w = p[1], r = l + w - 1;
            int h = tree->query(l, r) + w;
            mx = max(mx, h);
            ans.push_back(mx);
            tree->modify(l, r, h);
        }
        return ans;
    }
};
```

#### Go

```go
type node struct {
	left      *node
	right     *node
	l, mid, r int
	v, add    int
}

func newNode(l, r int) *node {
	return &node{
		l:   l,
		r:   r,
		mid: (l + r) >> 1,
	}
}

type segmentTree struct {
	root *node
}

func newSegmentTree() *segmentTree {
	return &segmentTree{
		root: newNode(1, 1e9),
	}
}

func (t *segmentTree) modify(l, r, v int, n *node) {
	if l > r {
		return
	}
	if n.l >= l && n.r <= r {
		n.v = v
		n.add = v
		return
	}
	t.pushdown(n)
	if l <= n.mid {
		t.modify(l, r, v, n.left)
	}
	if r > n.mid {
		t.modify(l, r, v, n.right)
	}
	t.pushup(n)
}

func (t *segmentTree) query(l, r int, n *node) int {
	if l > r {
		return 0
	}
	if n.l >= l && n.r <= r {
		return n.v
	}
	t.pushdown(n)
	v := 0
	if l <= n.mid {
		v = max(v, t.query(l, r, n.left))
	}
	if r > n.mid {
		v = max(v, t.query(l, r, n.right))
	}
	return v
}

func (t *segmentTree) pushup(n *node) {
	n.v = max(n.left.v, n.right.v)
}

func (t *segmentTree) pushdown(n *node) {
	if n.left == nil {
		n.left = newNode(n.l, n.mid)
	}
	if n.right == nil {
		n.right = newNode(n.mid+1, n.r)
	}
	if n.add != 0 {
		n.left.add = n.add
		n.right.add = n.add
		n.left.v = n.add
		n.right.v = n.add
		n.add = 0
	}
}

func fallingSquares(positions [][]int) []int {
	ans := make([]int, len(positions))
	t := newSegmentTree()
	mx := 0
	for i, p := range positions {
		l, w, r := p[0], p[1], p[0]+p[1]-1
		h := t.query(l, r, t.root) + w
		mx = max(mx, h)
		ans[i] = mx
		t.modify(l, r, h, t.root)
	}
	return ans
}
```

#### TypeScript

```ts
class Node {
    left: Node | null = null;
    right: Node | null = null;
    l: number;
    r: number;
    mid: number;
    v: number = 0;
    add: number = 0;

    constructor(l: number, r: number) {
        this.l = l;
        this.r = r;
        this.mid = (l + r) >> 1;
    }
}

class SegmentTree {
    private root: Node = new Node(1, 1e9);

    public modify(l: number, r: number, v: number): void {
        this.modifyNode(l, r, v, this.root);
    }

    private modifyNode(l: number, r: number, v: number, node: Node): void {
        if (l > r) {
            return;
        }
        if (node.l >= l && node.r <= r) {
            node.v = v;
            node.add = v;
            return;
        }
        this.pushdown(node);
        if (l <= node.mid) {
            this.modifyNode(l, r, v, node.left!);
        }
        if (r > node.mid) {
            this.modifyNode(l, r, v, node.right!);
        }
        this.pushup(node);
    }

    public query(l: number, r: number): number {
        return this.queryNode(l, r, this.root);
    }

    private queryNode(l: number, r: number, node: Node): number {
        if (l > r) {
            return 0;
        }
        if (node.l >= l && node.r <= r) {
            return node.v;
        }
        this.pushdown(node);
        let v = 0;
        if (l <= node.mid) {
            v = Math.max(v, this.queryNode(l, r, node.left!));
        }
        if (r > node.mid) {
            v = Math.max(v, this.queryNode(l, r, node.right!));
        }
        return v;
    }

    private pushup(node: Node): void {
        node.v = Math.max(node.left!.v, node.right!.v);
    }

    private pushdown(node: Node): void {
        if (node.left == null) {
            node.left = new Node(node.l, node.mid);
        }
        if (node.right == null) {
            node.right = new Node(node.mid + 1, node.r);
        }
        if (node.add != 0) {
            let left = node.left,
                right = node.right;
            left!.add = node.add;
            right!.add = node.add;
            left!.v = node.add;
            right!.v = node.add;
            node.add = 0;
        }
    }
}

function fallingSquares(positions: number[][]): number[] {
    const ans: number[] = [];
    const tree = new SegmentTree();
    let mx = 0;
    for (const [l, w] of positions) {
        const r = l + w - 1;
        const h = tree.query(l, r) + w;
        mx = Math.max(mx, h);
        ans.push(mx);
        tree.modify(l, r, h);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
