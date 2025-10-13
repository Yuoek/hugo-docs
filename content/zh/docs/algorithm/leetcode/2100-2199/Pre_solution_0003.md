---
title: "2120_执行所有后缀指令"
date: 2025-10-08T18:39:03+08:00
weight: 3
tags: [位运算, 前缀和, 双指针, 哈希表, 图, 字符串, 拓扑排序, 排序, 数学, 数组, 枚举, 模拟, 深度优先搜索, 矩阵, 贪心]
---

{{< markmap >}}
### [2120_执行所有后缀指令](#2120)
#### [字符串](#2120)
#### [模拟](#2120)
### [2121_相同元素的间隔之和](#2121)
#### [数组](#2121)
#### [哈希表](#2121)
#### [前缀和](#2121)
### [2122_还原原数组](#2122)
#### [数组](#2122)
#### [哈希表](#2122)
#### [双指针](#2122)
#### [枚举](#2122)
#### [排序](#2122)
### [2123_使矩阵中的 1 互不相邻的最小操作数 🔒](#2123)
#### [图](#2123)
#### [数组](#2123)
#### [矩阵](#2123)
### [2124_检查是否所有 A 都在 B 之前](#2124)
#### [字符串](#2124)
### [2125_银行中的激光束数量](#2125)
#### [数组](#2125)
#### [数学](#2125)
#### [字符串](#2125)
#### [矩阵](#2125)
### [2126_摧毁小行星](#2126)
#### [贪心](#2126)
#### [数组](#2126)
#### [排序](#2126)
### [2127_参加会议的最多员工数](#2127)
#### [深度优先搜索](#2127)
#### [图](#2127)
#### [拓扑排序](#2127)
### [2128_通过翻转行或列来去除所有的 1 🔒](#2128)
#### [位运算](#2128)
#### [数组](#2128)
#### [数学](#2128)
#### [矩阵](#2128)
### [2129_将标题首字母大写](#2129)
#### [字符串](#2129)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2120_执行所有后缀指令
___
#### 字符串
___
#### 模拟
---
### 2121_相同元素的间隔之和
___
#### 数组
___
#### 哈希表
___
#### 前缀和
---
### 2122_还原原数组
___
#### 数组
___
#### 哈希表
___
#### 双指针
___
#### 枚举
___
#### 排序
---
### 2123_使矩阵中的 1 互不相邻的最小操作数 🔒
___
#### 图
___
#### 数组
___
#### 矩阵
---
### 2124_检查是否所有 A 都在 B 之前
___
#### 字符串
---
### 2125_银行中的激光束数量
___
#### 数组
___
#### 数学
___
#### 字符串
___
#### 矩阵
---
### 2126_摧毁小行星
___
#### 贪心
___
#### 数组
___
#### 排序
---
### 2127_参加会议的最多员工数
___
#### 深度优先搜索
___
#### 图
___
#### 拓扑排序
---
### 2128_通过翻转行或列来去除所有的 1 🔒
___
#### 位运算
___
#### 数组
___
#### 数学
___
#### 矩阵
---
### 2129_将标题首字母大写
___
#### 字符串
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 位运算 | 前缀和 | 双指针 |
| 哈希表 | 图 | 字符串 |
| 拓扑排序 | 排序 | 数学 |
| 数组 | 枚举 | 模拟 |
| 深度优先搜索 | 矩阵 | 贪心 |

# [2120. 执行所有后缀指令](https://leetcode.cn/problems/execution-of-all-suffix-instructions-staying-in-a-grid){#2120}

{{< tabs "2120" >}}

{{% tab "python" %}}
```python
class Solution:
    def executeInstructions(self, n: int, startPos: List[int], s: str) -> List[int]:
        ans = []
        m = len(s)
        mp = {"L": [0, -1], "R": [0, 1], "U": [-1, 0], "D": [1, 0]}
        for i in range(m):
            x, y = startPos
            t = 0
            for j in range(i, m):
                a, b = mp[s[j]]
                if 0 <= x + a < n and 0 <= y + b < n:
                    x, y, t = x + a, y + b, t + 1
                else:
                    break
            ans.append(t)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] executeInstructions(int n, int[] startPos, String s) {
        int m = s.length();
        int[] ans = new int[m];
        Map<Character, int[]> mp = new HashMap<>(4);
        mp.put('L', new int[] {0, -1});
        mp.put('R', new int[] {0, 1});
        mp.put('U', new int[] {-1, 0});
        mp.put('D', new int[] {1, 0});
        for (int i = 0; i < m; ++i) {
            int x = startPos[0], y = startPos[1];
            int t = 0;
            for (int j = i; j < m; ++j) {
                char c = s.charAt(j);
                int a = mp.get(c)[0], b = mp.get(c)[1];
                if (0 <= x + a && x + a < n && 0 <= y + b && y + b < n) {
                    x += a;
                    y += b;
                    ++t;
                } else {
                    break;
                }
            }
            ans[i] = t;
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
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int m = s.size();
        vector<int> ans(m);
        unordered_map<char, vector<int>> mp;
        mp['L'] = {0, -1};
        mp['R'] = {0, 1};
        mp['U'] = {-1, 0};
        mp['D'] = {1, 0};
        for (int i = 0; i < m; ++i) {
            int x = startPos[0], y = startPos[1];
            int t = 0;
            for (int j = i; j < m; ++j) {
                int a = mp[s[j]][0], b = mp[s[j]][1];
                if (0 <= x + a && x + a < n && 0 <= y + b && y + b < n) {
                    x += a;
                    y += b;
                    ++t;
                } else
                    break;
            }
            ans[i] = t;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func executeInstructions(n int, startPos []int, s string) []int {
	m := len(s)
	mp := make(map[byte][]int)
	mp['L'] = []int{0, -1}
	mp['R'] = []int{0, 1}
	mp['U'] = []int{-1, 0}
	mp['D'] = []int{1, 0}
	ans := make([]int, m)
	for i := 0; i < m; i++ {
		x, y := startPos[0], startPos[1]
		t := 0
		for j := i; j < m; j++ {
			a, b := mp[s[j]][0], mp[s[j]][1]
			if 0 <= x+a && x+a < n && 0 <= y+b && y+b < n {
				x += a
				y += b
				t++
			} else {
				break
			}
		}
		ans[i] = t
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function executeInstructions(n: number, startPos: number[], s: string): number[] {
    const m = s.length;
    const ans = new Array(m);
    for (let i = 0; i < m; i++) {
        let [y, x] = startPos;
        let j: number;
        for (j = i; j < m; j++) {
            const c = s[j];
            if (c === 'U') {
                y--;
            } else if (c === 'D') {
                y++;
            } else if (c === 'L') {
                x--;
            } else {
                x++;
            }
            if (y === -1 || y === n || x === -1 || x === n) {
                break;
            }
        }
        ans[i] = j - i;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn execute_instructions(n: i32, start_pos: Vec<i32>, s: String) -> Vec<i32> {
        let s = s.as_bytes();
        let m = s.len();
        let mut ans = vec![0; m];
        for i in 0..m {
            let mut y = start_pos[0];
            let mut x = start_pos[1];
            let mut j = i;
            while j < m {
                match s[j] {
                    b'U' => {
                        y -= 1;
                    }
                    b'D' => {
                        y += 1;
                    }
                    b'L' => {
                        x -= 1;
                    }
                    _ => {
                        x += 1;
                    }
                }
                if y == -1 || y == n || x == -1 || x == n {
                    break;
                }
                j += 1;
            }
            ans[i] = (j - i) as i32;
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* executeInstructions(int n, int* startPos, int startPosSize, char* s, int* returnSize) {
    int m = strlen(s);
    int* ans = malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) {
        int y = startPos[0];
        int x = startPos[1];
        int j = i;
        for (j = i; j < m; j++) {
            if (s[j] == 'U') {
                y--;
            } else if (s[j] == 'D') {
                y++;
            } else if (s[j] == 'L') {
                x--;
            } else {
                x++;
            }
            if (y == -1 || y == n || x == -1 || x == n) {
                break;
            }
        }
        ans[i] = j - i;
    }
    *returnSize = m;
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>现有一个 <code>n x n</code> 大小的网格，左上角单元格坐标 <code>(0, 0)</code> ，右下角单元格坐标 <code>(n - 1, n - 1)</code> 。给你整数 <code>n</code> 和一个整数数组 <code>startPos</code> ，其中 <code>startPos = [start<sub>row</sub>, start<sub>col</sub>]</code> 表示机器人最开始在坐标为 <code>(start<sub>row</sub>, start<sub>col</sub>)</code> 的单元格上。</p>

<p>另给你一个长度为 <code>m</code> 、下标从 <strong>0</strong> 开始的字符串 <code>s</code> ，其中 <code>s[i]</code> 是对机器人的第 <code>i</code> 条指令：<code>'L'</code>（向左移动），<code>'R'</code>（向右移动），<code>'U'</code>（向上移动）和 <code>'D'</code>（向下移动）。</p>

<p>机器人可以从 <code>s</code> 中的任一第 <code>i</code> 条指令开始执行。它将会逐条执行指令直到 <code>s</code> 的末尾，但在满足下述条件之一时，机器人将会停止：</p>

<ul>
	<li>下一条指令将会导致机器人移动到网格外。</li>
	<li>没有指令可以执行。</li>
</ul>

<p>返回一个长度为 <code>m</code> 的数组 <code>answer</code> ，其中 <code>answer[i]</code> 是机器人从第 <code>i</code>&nbsp;条指令 <strong>开始</strong>&nbsp;，可以执行的 <strong>指令数目</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2120.Execution%20of%20All%20Suffix%20Instructions%20Staying%20in%20a%20Grid/images/1.png" style="width: 145px; height: 142px;" /></p>

<pre>
<strong>输入：</strong>n = 3, startPos = [0,1], s = "RRDDLU"
<strong>输出：</strong>[1,5,4,3,1,0]
<strong>解释：</strong>机器人从 startPos 出发，并从第 i 条指令开始执行：
- 0: "<em><strong>R</strong></em>RDDLU" 在移动到网格外之前，只能执行一条 "R" 指令。
- 1:  "<em><strong>RDDLU</strong></em>" 可以执行全部五条指令，机器人仍在网格内，最终到达 (0, 0) 。
- 2:   "<em><strong>DDLU</strong></em>" 可以执行全部四条指令，机器人仍在网格内，最终到达 (0, 0) 。
- 3:    "<em><strong>DLU</strong></em>" 可以执行全部三条指令，机器人仍在网格内，最终到达 (0, 0) 。
- 4:     "<em><strong>L</strong></em>U" 在移动到网格外之前，只能执行一条 "L" 指令。
- 5:      "U" 如果向上移动，将会移动到网格外。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2120.Execution%20of%20All%20Suffix%20Instructions%20Staying%20in%20a%20Grid/images/2.png" style="width: 106px; height: 103px;" /></p>

<pre>
<strong>输入：</strong>n = 2, startPos = [1,1], s = "LURD"
<strong>输出：</strong>[4,1,0,0]
<strong>解释：</strong>
- 0: "<em><strong>LURD</strong></em>"
- 1:  "<em><strong>U</strong></em>RD"
- 2:   "RD"
- 3:    "D"
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2120.Execution%20of%20All%20Suffix%20Instructions%20Staying%20in%20a%20Grid/images/3.png" style="width: 67px; height: 64px;" /></p>

<pre>
<strong>输入：</strong>n = 1, startPos = [0,0], s = "LRUD"
<strong>输出：</strong>[0,0,0,0]
<strong>解释：</strong>无论机器人从哪条指令开始执行，都会移动到网格外。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == s.length</code></li>
	<li><code>1 &lt;= n, m &lt;= 500</code></li>
	<li><code>startPos.length == 2</code></li>
	<li><code>0 &lt;= start<sub>row</sub>, start<sub>col</sub> &lt; n</code></li>
	<li><code>s</code> 由 <code>'L'</code>、<code>'R'</code>、<code>'U'</code> 和 <code>'D'</code> 组成</li>
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
    def executeInstructions(self, n: int, startPos: List[int], s: str) -> List[int]:
        ans = []
        m = len(s)
        mp = {"L": [0, -1], "R": [0, 1], "U": [-1, 0], "D": [1, 0]}
        for i in range(m):
            x, y = startPos
            t = 0
            for j in range(i, m):
                a, b = mp[s[j]]
                if 0 <= x + a < n and 0 <= y + b < n:
                    x, y, t = x + a, y + b, t + 1
                else:
                    break
            ans.append(t)
        return ans
```

#### Java

```java
class Solution {
    public int[] executeInstructions(int n, int[] startPos, String s) {
        int m = s.length();
        int[] ans = new int[m];
        Map<Character, int[]> mp = new HashMap<>(4);
        mp.put('L', new int[] {0, -1});
        mp.put('R', new int[] {0, 1});
        mp.put('U', new int[] {-1, 0});
        mp.put('D', new int[] {1, 0});
        for (int i = 0; i < m; ++i) {
            int x = startPos[0], y = startPos[1];
            int t = 0;
            for (int j = i; j < m; ++j) {
                char c = s.charAt(j);
                int a = mp.get(c)[0], b = mp.get(c)[1];
                if (0 <= x + a && x + a < n && 0 <= y + b && y + b < n) {
                    x += a;
                    y += b;
                    ++t;
                } else {
                    break;
                }
            }
            ans[i] = t;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int m = s.size();
        vector<int> ans(m);
        unordered_map<char, vector<int>> mp;
        mp['L'] = {0, -1};
        mp['R'] = {0, 1};
        mp['U'] = {-1, 0};
        mp['D'] = {1, 0};
        for (int i = 0; i < m; ++i) {
            int x = startPos[0], y = startPos[1];
            int t = 0;
            for (int j = i; j < m; ++j) {
                int a = mp[s[j]][0], b = mp[s[j]][1];
                if (0 <= x + a && x + a < n && 0 <= y + b && y + b < n) {
                    x += a;
                    y += b;
                    ++t;
                } else
                    break;
            }
            ans[i] = t;
        }
        return ans;
    }
};
```

#### Go

```go
func executeInstructions(n int, startPos []int, s string) []int {
	m := len(s)
	mp := make(map[byte][]int)
	mp['L'] = []int{0, -1}
	mp['R'] = []int{0, 1}
	mp['U'] = []int{-1, 0}
	mp['D'] = []int{1, 0}
	ans := make([]int, m)
	for i := 0; i < m; i++ {
		x, y := startPos[0], startPos[1]
		t := 0
		for j := i; j < m; j++ {
			a, b := mp[s[j]][0], mp[s[j]][1]
			if 0 <= x+a && x+a < n && 0 <= y+b && y+b < n {
				x += a
				y += b
				t++
			} else {
				break
			}
		}
		ans[i] = t
	}
	return ans
}
```

#### TypeScript

```ts
function executeInstructions(n: number, startPos: number[], s: string): number[] {
    const m = s.length;
    const ans = new Array(m);
    for (let i = 0; i < m; i++) {
        let [y, x] = startPos;
        let j: number;
        for (j = i; j < m; j++) {
            const c = s[j];
            if (c === 'U') {
                y--;
            } else if (c === 'D') {
                y++;
            } else if (c === 'L') {
                x--;
            } else {
                x++;
            }
            if (y === -1 || y === n || x === -1 || x === n) {
                break;
            }
        }
        ans[i] = j - i;
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn execute_instructions(n: i32, start_pos: Vec<i32>, s: String) -> Vec<i32> {
        let s = s.as_bytes();
        let m = s.len();
        let mut ans = vec![0; m];
        for i in 0..m {
            let mut y = start_pos[0];
            let mut x = start_pos[1];
            let mut j = i;
            while j < m {
                match s[j] {
                    b'U' => {
                        y -= 1;
                    }
                    b'D' => {
                        y += 1;
                    }
                    b'L' => {
                        x -= 1;
                    }
                    _ => {
                        x += 1;
                    }
                }
                if y == -1 || y == n || x == -1 || x == n {
                    break;
                }
                j += 1;
            }
            ans[i] = (j - i) as i32;
        }
        ans
    }
}
```

#### C

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* executeInstructions(int n, int* startPos, int startPosSize, char* s, int* returnSize) {
    int m = strlen(s);
    int* ans = malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) {
        int y = startPos[0];
        int x = startPos[1];
        int j = i;
        for (j = i; j < m; j++) {
            if (s[j] == 'U') {
                y--;
            } else if (s[j] == 'D') {
                y++;
            } else if (s[j] == 'L') {
                x--;
            } else {
                x++;
            }
            if (y == -1 || y == n || x == -1 || x == n) {
                break;
            }
        }
        ans[i] = j - i;
    }
    *returnSize = m;
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2121. 相同元素的间隔之和](https://leetcode.cn/problems/intervals-between-identical-elements){#2121}

{{< tabs "2121" >}}

{{% tab "python" %}}
```python
class Solution:
    def getDistances(self, arr: List[int]) -> List[int]:
        d = defaultdict(list)
        n = len(arr)
        for i, v in enumerate(arr):
            d[v].append(i)
        ans = [0] * n
        for v in d.values():
            m = len(v)
            val = sum(v) - v[0] * m
            for i, p in enumerate(v):
                delta = v[i] - v[i - 1] if i >= 1 else 0
                val += i * delta - (m - i) * delta
                ans[p] = val
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long[] getDistances(int[] arr) {
        Map<Integer, List<Integer>> d = new HashMap<>();
        int n = arr.length;
        for (int i = 0; i < n; ++i) {
            d.computeIfAbsent(arr[i], k -> new ArrayList<>()).add(i);
        }
        long[] ans = new long[n];
        for (List<Integer> v : d.values()) {
            int m = v.size();
            long val = 0;
            for (int e : v) {
                val += e;
            }
            val -= (m * v.get(0));
            for (int i = 0; i < v.size(); ++i) {
                int delta = i >= 1 ? v.get(i) - v.get(i - 1) : 0;
                val += i * delta - (m - i) * delta;
                ans[v.get(i)] = val;
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
    vector<long long> getDistances(vector<int>& arr) {
        unordered_map<int, vector<int>> d;
        int n = arr.size();
        for (int i = 0; i < n; ++i) d[arr[i]].push_back(i);
        vector<long long> ans(n);
        for (auto& item : d) {
            auto& v = item.second;
            int m = v.size();
            long long val = 0;
            for (int e : v) val += e;
            val -= m * v[0];
            for (int i = 0; i < v.size(); ++i) {
                int delta = i >= 1 ? v[i] - v[i - 1] : 0;
                val += i * delta - (m - i) * delta;
                ans[v[i]] = val;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getDistances(arr []int) []int64 {
	d := make(map[int][]int)
	n := len(arr)
	for i, v := range arr {
		d[v] = append(d[v], i)
	}
	ans := make([]int64, n)
	for _, v := range d {
		m := len(v)
		val := 0
		for _, e := range v {
			val += e
		}
		val -= m * v[0]
		for i, p := range v {
			delta := 0
			if i >= 1 {
				delta = v[i] - v[i-1]
			}
			val += i*delta - (m-i)*delta
			ans[p] = int64(val)
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

<p>给你一个下标从 <strong>0</strong> 开始、由 <code>n</code> 个整数组成的数组 <code>arr</code> 。</p>

<p><code>arr</code> 中两个元素的 <strong>间隔</strong> 定义为它们下标之间的 <strong>绝对差</strong> 。更正式地，<code>arr[i]</code> 和 <code>arr[j]</code> 之间的间隔是 <code>|i - j|</code> 。</p>

<p>返回一个长度为 <code>n</code> 的数组&nbsp;<code>intervals</code> ，其中 <code>intervals[i]</code> 是<em> </em><code>arr[i]</code><em> </em>和<em> </em><code>arr</code><em> </em>中每个相同元素（与 <code>arr[i]</code> 的值相同）的 <strong>间隔之和</strong> <em>。</em></p>

<p><strong>注意：</strong><code>|x|</code> 是 <code>x</code> 的绝对值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [2,1,3,1,2,3,3]
<strong>输出：</strong>[4,2,7,2,4,4,5]
<strong>解释：</strong>
- 下标 0 ：另一个 2 在下标 4 ，|0 - 4| = 4
- 下标 1 ：另一个 1 在下标 3 ，|1 - 3| = 2
- 下标 2 ：另两个 3 在下标 5 和 6 ，|2 - 5| + |2 - 6| = 7
- 下标 3 ：另一个 1 在下标 1 ，|3 - 1| = 2
- 下标 4 ：另一个 2 在下标 0 ，|4 - 0| = 4
- 下标 5 ：另两个 3 在下标 2 和 6 ，|5 - 2| + |5 - 6| = 4
- 下标 6 ：另两个 3 在下标 2 和 5 ，|6 - 2| + |6 - 5| = 5
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = [10,5,10,10]
<strong>输出：</strong>[5,0,3,4]
<strong>解释：</strong>
- 下标 0 ：另两个 10 在下标 2 和 3 ，|0 - 2| + |0 - 3| = 5
- 下标 1 ：只有这一个 5 在数组中，所以到相同元素的间隔之和是 0
- 下标 2 ：另两个 10 在下标 0 和 3 ，|2 - 0| + |2 - 3| = 3
- 下标 3 ：另两个 10 在下标 0 和 2 ，|3 - 0| + |3 - 2| = 4
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == arr.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= arr[i] &lt;= 10<sup>5</sup></code></li>
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
    def getDistances(self, arr: List[int]) -> List[int]:
        d = defaultdict(list)
        n = len(arr)
        for i, v in enumerate(arr):
            d[v].append(i)
        ans = [0] * n
        for v in d.values():
            m = len(v)
            val = sum(v) - v[0] * m
            for i, p in enumerate(v):
                delta = v[i] - v[i - 1] if i >= 1 else 0
                val += i * delta - (m - i) * delta
                ans[p] = val
        return ans
```

#### Java

```java
class Solution {
    public long[] getDistances(int[] arr) {
        Map<Integer, List<Integer>> d = new HashMap<>();
        int n = arr.length;
        for (int i = 0; i < n; ++i) {
            d.computeIfAbsent(arr[i], k -> new ArrayList<>()).add(i);
        }
        long[] ans = new long[n];
        for (List<Integer> v : d.values()) {
            int m = v.size();
            long val = 0;
            for (int e : v) {
                val += e;
            }
            val -= (m * v.get(0));
            for (int i = 0; i < v.size(); ++i) {
                int delta = i >= 1 ? v.get(i) - v.get(i - 1) : 0;
                val += i * delta - (m - i) * delta;
                ans[v.get(i)] = val;
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
    vector<long long> getDistances(vector<int>& arr) {
        unordered_map<int, vector<int>> d;
        int n = arr.size();
        for (int i = 0; i < n; ++i) d[arr[i]].push_back(i);
        vector<long long> ans(n);
        for (auto& item : d) {
            auto& v = item.second;
            int m = v.size();
            long long val = 0;
            for (int e : v) val += e;
            val -= m * v[0];
            for (int i = 0; i < v.size(); ++i) {
                int delta = i >= 1 ? v[i] - v[i - 1] : 0;
                val += i * delta - (m - i) * delta;
                ans[v[i]] = val;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func getDistances(arr []int) []int64 {
	d := make(map[int][]int)
	n := len(arr)
	for i, v := range arr {
		d[v] = append(d[v], i)
	}
	ans := make([]int64, n)
	for _, v := range d {
		m := len(v)
		val := 0
		for _, e := range v {
			val += e
		}
		val -= m * v[0]
		for i, p := range v {
			delta := 0
			if i >= 1 {
				delta = v[i] - v[i-1]
			}
			val += i*delta - (m-i)*delta
			ans[p] = int64(val)
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

# [2122. 还原原数组](https://leetcode.cn/problems/recover-the-original-array){#2122}

{{< tabs "2122" >}}

{{% tab "python" %}}
```python
class Solution:
    def recoverArray(self, nums: List[int]) -> List[int]:
        nums.sort()
        n = len(nums)
        for i in range(1, n):
            d = nums[i] - nums[0]
            if d == 0 or d % 2 == 1:
                continue
            vis = [False] * n
            vis[i] = True
            ans = [(nums[0] + nums[i]) >> 1]
            l, r = 1, i + 1
            while r < n:
                while l < n and vis[l]:
                    l += 1
                while r < n and nums[r] - nums[l] < d:
                    r += 1
                if r == n or nums[r] - nums[l] > d:
                    break
                vis[r] = True
                ans.append((nums[l] + nums[r]) >> 1)
                l, r = l + 1, r + 1
            if len(ans) == (n >> 1):
                return ans
        return []
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] recoverArray(int[] nums) {
        Arrays.sort(nums);
        for (int i = 1, n = nums.length; i < n; ++i) {
            int d = nums[i] - nums[0];
            if (d == 0 || d % 2 == 1) {
                continue;
            }
            boolean[] vis = new boolean[n];
            vis[i] = true;
            List<Integer> t = new ArrayList<>();
            t.add((nums[0] + nums[i]) >> 1);
            for (int l = 1, r = i + 1; r < n; ++l, ++r) {
                while (l < n && vis[l]) {
                    ++l;
                }
                while (r < n && nums[r] - nums[l] < d) {
                    ++r;
                }
                if (r == n || nums[r] - nums[l] > d) {
                    break;
                }
                vis[r] = true;
                t.add((nums[l] + nums[r]) >> 1);
            }
            if (t.size() == (n >> 1)) {
                int[] ans = new int[t.size()];
                int idx = 0;
                for (int e : t) {
                    ans[idx++] = e;
                }
                return ans;
            }
        }
        return null;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1, n = nums.size(); i < n; ++i) {
            int d = nums[i] - nums[0];
            if (d == 0 || d % 2 == 1) continue;
            vector<bool> vis(n);
            vis[i] = true;
            vector<int> ans;
            ans.push_back((nums[0] + nums[i]) >> 1);
            for (int l = 1, r = i + 1; r < n; ++l, ++r) {
                while (l < n && vis[l]) ++l;
                while (r < n && nums[r] - nums[l] < d) ++r;
                if (r == n || nums[r] - nums[l] > d) break;
                vis[r] = true;
                ans.push_back((nums[l] + nums[r]) >> 1);
            }
            if (ans.size() == (n >> 1)) return ans;
        }
        return {};
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func recoverArray(nums []int) []int {
	sort.Ints(nums)
	for i, n := 1, len(nums); i < n; i++ {
		d := nums[i] - nums[0]
		if d == 0 || d%2 == 1 {
			continue
		}
		vis := make([]bool, n)
		vis[i] = true
		ans := []int{(nums[0] + nums[i]) >> 1}
		for l, r := 1, i+1; r < n; l, r = l+1, r+1 {
			for l < n && vis[l] {
				l++
			}
			for r < n && nums[r]-nums[l] < d {
				r++
			}
			if r == n || nums[r]-nums[l] > d {
				break
			}
			vis[r] = true
			ans = append(ans, (nums[l]+nums[r])>>1)
		}
		if len(ans) == (n >> 1) {
			return ans
		}
	}
	return []int{}
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>Alice 有一个下标从 <strong>0</strong> 开始的数组 <code>arr</code> ，由 <code>n</code> 个正整数组成。她会选择一个任意的 <strong>正整数 </strong><code>k</code> 并按下述方式创建两个下标从 <strong>0</strong> 开始的新整数数组 <code>lower</code> 和 <code>higher</code> ：</p>

<ol>
	<li>对每个满足 <code>0 &lt;= i &lt; n</code> 的下标 <code>i</code> ，<code>lower[i] = arr[i] - k</code></li>
	<li>对每个满足 <code>0 &lt;= i &lt; n</code> 的下标 <code>i</code> ，<code>higher[i] = arr[i] + k</code></li>
</ol>

<p>不幸地是，Alice 丢失了全部三个数组。但是，她记住了在数组 <code>lower</code> 和 <code>higher</code> 中出现的整数，但不知道每个整数属于哪个数组。请你帮助 Alice 还原原数组。</p>

<p>给你一个由 2n 个整数组成的整数数组 <code>nums</code> ，其中 <strong>恰好</strong> <code>n</code> 个整数出现在 <code>lower</code> ，剩下的出现在 <code>higher</code> ，还原并返回 <strong>原数组</strong> <code>arr</code> 。如果出现答案不唯一的情况，返回 <strong>任一</strong> 有效数组。</p>

<p><strong>注意：</strong>生成的测试用例保证存在 <strong>至少一个</strong> 有效数组 <code>arr</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [2,10,6,4,8,12]
<strong>输出：</strong>[3,7,11]
<strong>解释：</strong>
如果 arr = [3,7,11] 且 k = 1 ，那么 lower = [2,6,10] 且 higher = [4,8,12] 。
组合 lower 和 higher 得到 [2,6,10,4,8,12] ，这是 nums 的一个排列。
另一个有效的数组是 arr = [5,7,9] 且 k = 3 。在这种情况下，lower = [2,4,6] 且 higher = [8,10,12] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [1,1,3,3]
<strong>输出：</strong>[2,2]
<strong>解释：</strong>
如果 arr = [2,2] 且 k = 1 ，那么 lower = [1,1] 且 higher = [3,3] 。
组合 lower 和 higher 得到 [1,1,3,3] ，这是 nums 的一个排列。
注意，数组不能是 [1,3] ，因为在这种情况下，获得 [1,1,3,3] 唯一可行的方案是 k = 0 。
这种方案是无效的，k 必须是一个正整数。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [5,435]
<strong>输出：</strong>[220]
<strong>解释：</strong>
唯一可行的组合是 arr = [220] 且 k = 215 。在这种情况下，lower = [5] 且 higher = [435] 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 * n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li>生成的测试用例保证存在 <strong>至少一个</strong> 有效数组 <code>arr</code></li>
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
    def recoverArray(self, nums: List[int]) -> List[int]:
        nums.sort()
        n = len(nums)
        for i in range(1, n):
            d = nums[i] - nums[0]
            if d == 0 or d % 2 == 1:
                continue
            vis = [False] * n
            vis[i] = True
            ans = [(nums[0] + nums[i]) >> 1]
            l, r = 1, i + 1
            while r < n:
                while l < n and vis[l]:
                    l += 1
                while r < n and nums[r] - nums[l] < d:
                    r += 1
                if r == n or nums[r] - nums[l] > d:
                    break
                vis[r] = True
                ans.append((nums[l] + nums[r]) >> 1)
                l, r = l + 1, r + 1
            if len(ans) == (n >> 1):
                return ans
        return []
```

#### Java

```java
class Solution {
    public int[] recoverArray(int[] nums) {
        Arrays.sort(nums);
        for (int i = 1, n = nums.length; i < n; ++i) {
            int d = nums[i] - nums[0];
            if (d == 0 || d % 2 == 1) {
                continue;
            }
            boolean[] vis = new boolean[n];
            vis[i] = true;
            List<Integer> t = new ArrayList<>();
            t.add((nums[0] + nums[i]) >> 1);
            for (int l = 1, r = i + 1; r < n; ++l, ++r) {
                while (l < n && vis[l]) {
                    ++l;
                }
                while (r < n && nums[r] - nums[l] < d) {
                    ++r;
                }
                if (r == n || nums[r] - nums[l] > d) {
                    break;
                }
                vis[r] = true;
                t.add((nums[l] + nums[r]) >> 1);
            }
            if (t.size() == (n >> 1)) {
                int[] ans = new int[t.size()];
                int idx = 0;
                for (int e : t) {
                    ans[idx++] = e;
                }
                return ans;
            }
        }
        return null;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1, n = nums.size(); i < n; ++i) {
            int d = nums[i] - nums[0];
            if (d == 0 || d % 2 == 1) continue;
            vector<bool> vis(n);
            vis[i] = true;
            vector<int> ans;
            ans.push_back((nums[0] + nums[i]) >> 1);
            for (int l = 1, r = i + 1; r < n; ++l, ++r) {
                while (l < n && vis[l]) ++l;
                while (r < n && nums[r] - nums[l] < d) ++r;
                if (r == n || nums[r] - nums[l] > d) break;
                vis[r] = true;
                ans.push_back((nums[l] + nums[r]) >> 1);
            }
            if (ans.size() == (n >> 1)) return ans;
        }
        return {};
    }
};
```

#### Go

```go
func recoverArray(nums []int) []int {
	sort.Ints(nums)
	for i, n := 1, len(nums); i < n; i++ {
		d := nums[i] - nums[0]
		if d == 0 || d%2 == 1 {
			continue
		}
		vis := make([]bool, n)
		vis[i] = true
		ans := []int{(nums[0] + nums[i]) >> 1}
		for l, r := 1, i+1; r < n; l, r = l+1, r+1 {
			for l < n && vis[l] {
				l++
			}
			for r < n && nums[r]-nums[l] < d {
				r++
			}
			if r == n || nums[r]-nums[l] > d {
				break
			}
			vis[r] = true
			ans = append(ans, (nums[l]+nums[r])>>1)
		}
		if len(ans) == (n >> 1) {
			return ans
		}
	}
	return []int{}
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2123. 使矩阵中的 1 互不相邻的最小操作数 🔒](https://leetcode.cn/problems/minimum-operations-to-remove-adjacent-ones-in-matrix){#2123}

{{< tabs "2123" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumOperations(self, grid: List[List[int]]) -> int:
        def find(i: int) -> int:
            for j in g[i]:
                if j not in vis:
                    vis.add(j)
                    if match[j] == -1 or find(match[j]):
                        match[j] = i
                        return 1
            return 0

        g = defaultdict(list)
        m, n = len(grid), len(grid[0])
        for i, row in enumerate(grid):
            for j, v in enumerate(row):
                if (i + j) % 2 and v:
                    x = i * n + j
                    if i < m - 1 and grid[i + 1][j]:
                        g[x].append(x + n)
                    if i and grid[i - 1][j]:
                        g[x].append(x - n)
                    if j < n - 1 and grid[i][j + 1]:
                        g[x].append(x + 1)
                    if j and grid[i][j - 1]:
                        g[x].append(x - 1)

        match = [-1] * (m * n)
        ans = 0
        for i in g.keys():
            vis = set()
            ans += find(i)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private Map<Integer, List<Integer>> g = new HashMap<>();
    private Set<Integer> vis = new HashSet<>();
    private int[] match;

    public int minimumOperations(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i + j) % 2 == 1 && grid[i][j] == 1) {
                    int x = i * n + j;
                    if (i < m - 1 && grid[i + 1][j] == 1) {
                        g.computeIfAbsent(x, z -> new ArrayList<>()).add(x + n);
                    }
                    if (i > 0 && grid[i - 1][j] == 1) {
                        g.computeIfAbsent(x, z -> new ArrayList<>()).add(x - n);
                    }
                    if (j < n - 1 && grid[i][j + 1] == 1) {
                        g.computeIfAbsent(x, z -> new ArrayList<>()).add(x + 1);
                    }
                    if (j > 0 && grid[i][j - 1] == 1) {
                        g.computeIfAbsent(x, z -> new ArrayList<>()).add(x - 1);
                    }
                }
            }
        }
        match = new int[m * n];
        Arrays.fill(match, -1);
        int ans = 0;
        for (int i : g.keySet()) {
            ans += find(i);
            vis.clear();
        }
        return ans;
    }

    private int find(int i) {
        for (int j : g.get(i)) {
            if (vis.add(j)) {
                if (match[j] == -1 || find(match[j]) == 1) {
                    match[j] = i;
                    return 1;
                }
            }
        }
        return 0;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> match(m * n, -1);
        unordered_set<int> vis;
        unordered_map<int, vector<int>> g;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i + j) % 2 && grid[i][j]) {
                    int x = i * n + j;
                    if (i < m - 1 && grid[i + 1][j]) {
                        g[x].push_back(x + n);
                    }
                    if (i && grid[i - 1][j]) {
                        g[x].push_back(x - n);
                    }
                    if (j < n - 1 && grid[i][j + 1]) {
                        g[x].push_back(x + 1);
                    }
                    if (j && grid[i][j - 1]) {
                        g[x].push_back(x - 1);
                    }
                }
            }
        }
        int ans = 0;
        function<int(int)> find = [&](int i) -> int {
            for (int& j : g[i]) {
                if (!vis.count(j)) {
                    vis.insert(j);
                    if (match[j] == -1 || find(match[j])) {
                        match[j] = i;
                        return 1;
                    }
                }
            }
            return 0;
        };
        for (auto& [i, _] : g) {
            ans += find(i);
            vis.clear();
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumOperations(grid [][]int) (ans int) {
	m, n := len(grid), len(grid[0])
	vis := map[int]bool{}
	match := make([]int, m*n)
	for i := range match {
		match[i] = -1
	}
	g := map[int][]int{}
	for i, row := range grid {
		for j, v := range row {
			if (i+j)&1 == 1 && v == 1 {
				x := i*n + j
				if i < m-1 && grid[i+1][j] == 1 {
					g[x] = append(g[x], x+n)
				}
				if i > 0 && grid[i-1][j] == 1 {
					g[x] = append(g[x], x-n)
				}
				if j < n-1 && grid[i][j+1] == 1 {
					g[x] = append(g[x], x+1)
				}
				if j > 0 && grid[i][j-1] == 1 {
					g[x] = append(g[x], x-1)
				}
			}
		}
	}
	var find func(int) int
	find = func(i int) int {
		for _, j := range g[i] {
			if !vis[j] {
				vis[j] = true
				if match[j] == -1 || find(match[j]) == 1 {
					match[j] = i
					return 1
				}
			}
		}
		return 0
	}
	for i := range g {
		ans += find(i)
		vis = map[int]bool{}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumOperations(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;
    const match: number[] = Array(m * n).fill(-1);
    const vis: Set<number> = new Set();
    const g: Map<number, number[]> = new Map();
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if ((i + j) % 2 && grid[i][j]) {
                const x = i * n + j;
                g.set(x, []);
                if (i < m - 1 && grid[i + 1][j]) {
                    g.get(x)!.push(x + n);
                }
                if (i && grid[i - 1][j]) {
                    g.get(x)!.push(x - n);
                }
                if (j < n - 1 && grid[i][j + 1]) {
                    g.get(x)!.push(x + 1);
                }
                if (j && grid[i][j - 1]) {
                    g.get(x)!.push(x - 1);
                }
            }
        }
    }
    const find = (i: number): number => {
        for (const j of g.get(i)!) {
            if (!vis.has(j)) {
                vis.add(j);
                if (match[j] === -1 || find(match[j])) {
                    match[j] = i;
                    return 1;
                }
            }
        }
        return 0;
    };
    let ans = 0;
    for (const i of g.keys()) {
        ans += find(i);
        vis.clear();
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

<p>给你一个 <strong>下标从 0 开始&nbsp;</strong>的矩阵 <code>grid</code>。每次操作，你可以把 <code>grid</code>&nbsp;中的 一个&nbsp;<code>1</code> 变成&nbsp;<code>0</code> 。</p>

<p>如果一个矩阵中，没有 <code>1</code> 与其它的 <code>1</code> <strong>四连通</strong>（也就是说所有 <code>1</code> 在上下左右四个方向上不能与其他 <code>1</code> 相邻），那么该矩阵就是 <strong>完全独立</strong> 的。</p>

<p>请返回让&nbsp;<code>grid</code> 成为 <strong>完全独立</strong> 的矩阵的 <em>最小操作数</em>。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2123.Minimum%20Operations%20to%20Remove%20Adjacent%20Ones%20in%20Matrix/images/image-20211223181501-1.png" style="width: 644px; height: 250px;">
<pre><strong>输入:</strong> grid = [[1,1,0],[0,1,1],[1,1,1]]
<strong>输出:</strong> 3
<strong>解释:</strong> 可以进行三次操作（把 grid[0][1], grid[1][2] 和 grid[2][1] 变成 0）。
操作后的矩阵中的所有的 1 与其它 1 均不相邻，因此矩阵是完全独立的。
</pre>

<p><strong>示例 2:</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2123.Minimum%20Operations%20to%20Remove%20Adjacent%20Ones%20in%20Matrix/images/image-20211223181518-2.png" style="height: 250px; width: 255px;">
<pre><strong>输入:</strong> grid = [[0,0,0],[0,0,0],[0,0,0]]
<strong>输出:</strong> 0
<strong>解释:</strong> 矩阵中没有 1，此时矩阵也是完全独立的，因此无需操作，返回 0。
</pre>

<p><strong>示例 3:</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2123.Minimum%20Operations%20to%20Remove%20Adjacent%20Ones%20in%20Matrix/images/image-20211223181817-3.png" style="width: 165px; height: 167px;">
<pre><strong>输入:</strong> grid = [[0,1],[1,0]]
<strong>输出:</strong> 0
<strong>解释:</strong> 矩阵中的所有的 1 与其它 1 均不相邻，已经是完全独立的，因此无需操作，返回 0。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 300</code></li>
	<li><code>grid[i][j]</code> 是&nbsp;<code>0</code>&nbsp;或者&nbsp;<code>1</code>.</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：匈牙利算法

我们注意到，如果矩阵中的两个 $1$ 相邻，那么它们一定属于不同的组。因此，我们可以把矩阵中所有的 $1$ 视为点，相邻的两个 $1$ 之间连一条边，构建二分图。

那么，问题可以转化为求二分图最小点覆盖，也即选出最少数目的点来覆盖所有的边。由于二分图的最小点覆盖数等于最大匹配数，因此我们可以使用匈牙利算法求出二分图的最大匹配数。

匈牙利算法的核心思想是，不断地从未匹配的点出发，寻找增广路径，直到没有增广路径为止，就得到了最大匹配。

时间复杂度 $O(m \times n)$，其中 $n$ 和 $m$ 分别是矩阵中 $1$ 的数目以及边的数目。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumOperations(self, grid: List[List[int]]) -> int:
        def find(i: int) -> int:
            for j in g[i]:
                if j not in vis:
                    vis.add(j)
                    if match[j] == -1 or find(match[j]):
                        match[j] = i
                        return 1
            return 0

        g = defaultdict(list)
        m, n = len(grid), len(grid[0])
        for i, row in enumerate(grid):
            for j, v in enumerate(row):
                if (i + j) % 2 and v:
                    x = i * n + j
                    if i < m - 1 and grid[i + 1][j]:
                        g[x].append(x + n)
                    if i and grid[i - 1][j]:
                        g[x].append(x - n)
                    if j < n - 1 and grid[i][j + 1]:
                        g[x].append(x + 1)
                    if j and grid[i][j - 1]:
                        g[x].append(x - 1)

        match = [-1] * (m * n)
        ans = 0
        for i in g.keys():
            vis = set()
            ans += find(i)
        return ans
```

#### Java

```java
class Solution {
    private Map<Integer, List<Integer>> g = new HashMap<>();
    private Set<Integer> vis = new HashSet<>();
    private int[] match;

    public int minimumOperations(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i + j) % 2 == 1 && grid[i][j] == 1) {
                    int x = i * n + j;
                    if (i < m - 1 && grid[i + 1][j] == 1) {
                        g.computeIfAbsent(x, z -> new ArrayList<>()).add(x + n);
                    }
                    if (i > 0 && grid[i - 1][j] == 1) {
                        g.computeIfAbsent(x, z -> new ArrayList<>()).add(x - n);
                    }
                    if (j < n - 1 && grid[i][j + 1] == 1) {
                        g.computeIfAbsent(x, z -> new ArrayList<>()).add(x + 1);
                    }
                    if (j > 0 && grid[i][j - 1] == 1) {
                        g.computeIfAbsent(x, z -> new ArrayList<>()).add(x - 1);
                    }
                }
            }
        }
        match = new int[m * n];
        Arrays.fill(match, -1);
        int ans = 0;
        for (int i : g.keySet()) {
            ans += find(i);
            vis.clear();
        }
        return ans;
    }

    private int find(int i) {
        for (int j : g.get(i)) {
            if (vis.add(j)) {
                if (match[j] == -1 || find(match[j]) == 1) {
                    match[j] = i;
                    return 1;
                }
            }
        }
        return 0;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> match(m * n, -1);
        unordered_set<int> vis;
        unordered_map<int, vector<int>> g;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i + j) % 2 && grid[i][j]) {
                    int x = i * n + j;
                    if (i < m - 1 && grid[i + 1][j]) {
                        g[x].push_back(x + n);
                    }
                    if (i && grid[i - 1][j]) {
                        g[x].push_back(x - n);
                    }
                    if (j < n - 1 && grid[i][j + 1]) {
                        g[x].push_back(x + 1);
                    }
                    if (j && grid[i][j - 1]) {
                        g[x].push_back(x - 1);
                    }
                }
            }
        }
        int ans = 0;
        function<int(int)> find = [&](int i) -> int {
            for (int& j : g[i]) {
                if (!vis.count(j)) {
                    vis.insert(j);
                    if (match[j] == -1 || find(match[j])) {
                        match[j] = i;
                        return 1;
                    }
                }
            }
            return 0;
        };
        for (auto& [i, _] : g) {
            ans += find(i);
            vis.clear();
        }
        return ans;
    }
};
```

#### Go

```go
func minimumOperations(grid [][]int) (ans int) {
	m, n := len(grid), len(grid[0])
	vis := map[int]bool{}
	match := make([]int, m*n)
	for i := range match {
		match[i] = -1
	}
	g := map[int][]int{}
	for i, row := range grid {
		for j, v := range row {
			if (i+j)&1 == 1 && v == 1 {
				x := i*n + j
				if i < m-1 && grid[i+1][j] == 1 {
					g[x] = append(g[x], x+n)
				}
				if i > 0 && grid[i-1][j] == 1 {
					g[x] = append(g[x], x-n)
				}
				if j < n-1 && grid[i][j+1] == 1 {
					g[x] = append(g[x], x+1)
				}
				if j > 0 && grid[i][j-1] == 1 {
					g[x] = append(g[x], x-1)
				}
			}
		}
	}
	var find func(int) int
	find = func(i int) int {
		for _, j := range g[i] {
			if !vis[j] {
				vis[j] = true
				if match[j] == -1 || find(match[j]) == 1 {
					match[j] = i
					return 1
				}
			}
		}
		return 0
	}
	for i := range g {
		ans += find(i)
		vis = map[int]bool{}
	}
	return
}
```

#### TypeScript

```ts
function minimumOperations(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;
    const match: number[] = Array(m * n).fill(-1);
    const vis: Set<number> = new Set();
    const g: Map<number, number[]> = new Map();
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if ((i + j) % 2 && grid[i][j]) {
                const x = i * n + j;
                g.set(x, []);
                if (i < m - 1 && grid[i + 1][j]) {
                    g.get(x)!.push(x + n);
                }
                if (i && grid[i - 1][j]) {
                    g.get(x)!.push(x - n);
                }
                if (j < n - 1 && grid[i][j + 1]) {
                    g.get(x)!.push(x + 1);
                }
                if (j && grid[i][j - 1]) {
                    g.get(x)!.push(x - 1);
                }
            }
        }
    }
    const find = (i: number): number => {
        for (const j of g.get(i)!) {
            if (!vis.has(j)) {
                vis.add(j);
                if (match[j] === -1 || find(match[j])) {
                    match[j] = i;
                    return 1;
                }
            }
        }
        return 0;
    };
    let ans = 0;
    for (const i of g.keys()) {
        ans += find(i);
        vis.clear();
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2124. 检查是否所有 A 都在 B 之前](https://leetcode.cn/problems/check-if-all-as-appears-before-all-bs){#2124}

{{< tabs "2124" >}}

{{% tab "python" %}}
```python
class Solution:
    def checkString(self, s: str) -> bool:
        return "ba" not in s
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean checkString(String s) {
        return !s.contains("ba");
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool checkString(string s) {
        return !s.contains("ba");
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func checkString(s string) bool {
	return !strings.Contains(s, "ba")
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function checkString(s: string): boolean {
    return !s.includes('ba');
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn check_string(s: String) -> bool {
        !s.contains("ba")
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 <strong>仅</strong> 由字符 <code>'a'</code> 和 <code>'b'</code> 组成的字符串&nbsp; <code>s</code> 。如果字符串中 <strong>每个</strong> <em> </em><code>'a'</code> 都出现在 <strong>每个</strong><em> </em><code>'b'</code><em> </em>之前，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "aaabbb"
<strong>输出：</strong>true
<strong>解释：</strong>
'a' 位于下标 0、1 和 2 ；而 'b' 位于下标 3、4 和 5 。
因此，每个 'a' 都出现在每个 'b' 之前，所以返回 true 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "abab"
<strong>输出：</strong>false
<strong>解释：</strong>
存在一个 'a' 位于下标 2 ，而一个 'b' 位于下标 1 。
因此，不能满足每个 'a' 都出现在每个 'b' 之前，所以返回 false 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = "bbb"
<strong>输出：</strong>true
<strong>解释：</strong>
不存在 'a' ，因此可以视作每个 'a' 都出现在每个 'b' 之前，所以返回 true 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s[i]</code> 为 <code>'a'</code> 或 <code>'b'</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：脑筋急转弯

根据题意，字符串 $s$ 仅由字符 `a`, `b` 组成。

要使得所有 `a` 都在 `b` 之前出现，需要满足 `b` 之后不会出现 `a`，也就是说，字符串 "ba" 不是字符串 $s$ 的子串，条件才能成立。

时间复杂度 $O(n)$，其中 $n$ 是字符串 $s$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def checkString(self, s: str) -> bool:
        return "ba" not in s
```

#### Java

```java
class Solution {
    public boolean checkString(String s) {
        return !s.contains("ba");
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool checkString(string s) {
        return !s.contains("ba");
    }
};
```

#### Go

```go
func checkString(s string) bool {
	return !strings.Contains(s, "ba")
}
```

#### TypeScript

```ts
function checkString(s: string): boolean {
    return !s.includes('ba');
}
```

#### Rust

```rust
impl Solution {
    pub fn check_string(s: String) -> bool {
        !s.contains("ba")
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2125. 银行中的激光束数量](https://leetcode.cn/problems/number-of-laser-beams-in-a-bank){#2125}

{{< tabs "2125" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        ans = pre = 0
        for row in bank:
            if (cur := row.count("1")) > 0:
                ans += pre * cur
                pre = cur
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numberOfBeams(String[] bank) {
        int ans = 0, pre = 0;
        for (String row : bank) {
            int cur = 0;
            for (int i = 0; i < row.length(); ++i) {
                cur += row.charAt(i) - '0';
            }
            if (cur > 0) {
                ans += pre * cur;
                pre = cur;
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
    int numberOfBeams(vector<string>& bank) {
        int ans = 0, pre = 0;
        for (auto& row : bank) {
            int cur = count(row.begin(), row.end(), '1');
            if (cur) {
                ans += pre * cur;
                pre = cur;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfBeams(bank []string) (ans int) {
	pre := 0
	for _, row := range bank {
		if cur := strings.Count(row, "1"); cur > 0 {
			ans += pre * cur
			pre = cur
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberOfBeams(bank: string[]): number {
    let [ans, pre] = [0, 0];
    for (const row of bank) {
        const cur = row.split('1').length - 1;
        if (cur) {
            ans += pre * cur;
            pre = cur;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn number_of_beams(bank: Vec<String>) -> i32 {
        let mut ans = 0;
        let mut pre = 0;
        for row in bank {
            let cur = row.chars().filter(|&c| c == '1').count() as i32;
            if cur > 0 {
                ans += pre * cur;
                pre = cur;
            }
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int numberOfBeams(char** bank, int bankSize) {
    int ans = 0, pre = 0;
    for (int i = 0; i < bankSize; ++i) {
        int cur = 0;
        for (int j = 0; bank[i][j] != '\0'; ++j) {
            if (bank[i][j] == '1') {
                cur++;
            }
        }
        if (cur) {
            ans += pre * cur;
            pre = cur;
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

<p>银行内部的防盗安全装置已经激活。给你一个下标从 <strong>0</strong> 开始的二进制字符串数组 <code>bank</code> ，表示银行的平面图，这是一个大小为 <code>m x n</code> 的二维矩阵。 <code>bank[i]</code> 表示第 <code>i</code> 行的设备分布，由若干 <code>'0'</code> 和若干 <code>'1'</code> 组成。<code>'0'</code> 表示单元格是空的，而 <code>'1'</code> 表示单元格有一个安全设备。</p>

<p>对任意两个安全设备而言，<strong>如果</strong><strong>同时</strong> 满足下面两个条件，则二者之间存在 <strong>一个</strong> 激光束：</p>

<ul>
	<li>两个设备位于两个 <strong>不同行</strong> ：<code>r<sub>1</sub></code> 和 <code>r<sub>2</sub></code> ，其中 <code>r<sub>1</sub> &lt; r<sub>2</sub></code> 。</li>
	<li>满足&nbsp;<code>r<sub>1</sub> &lt; i &lt; r<sub>2</sub></code>&nbsp;的 <strong>所有&nbsp;</strong>行&nbsp;<code>i</code>&nbsp;，都&nbsp;<strong>没有安全设备</strong> 。</li>
</ul>

<p>激光束是独立的，也就是说，一个激光束既不会干扰另一个激光束，也不会与另一个激光束合并成一束。</p>

<p>返回银行中激光束的总数量。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2125.Number%20of%20Laser%20Beams%20in%20a%20Bank/images/laser1.jpg" style="width: 400px; height: 368px;" /></p>

<pre>
<strong>输入：</strong>bank = ["011001","000000","010100","001000"]
<strong>输出：</strong>8
<strong>解释：</strong>在下面每组设备对之间，存在一条激光束。总共是 8 条激光束：
 * bank[0][1] -- bank[2][1]
 * bank[0][1] -- bank[2][3]
 * bank[0][2] -- bank[2][1]
 * bank[0][2] -- bank[2][3]
 * bank[0][5] -- bank[2][1]
 * bank[0][5] -- bank[2][3]
 * bank[2][1] -- bank[3][2]
 * bank[2][3] -- bank[3][2]
注意，第 0 行和第 3 行上的设备之间不存在激光束。
这是因为第 2 行存在安全设备，这不满足第 2 个条件。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2125.Number%20of%20Laser%20Beams%20in%20a%20Bank/images/laser2.jpg" style="width: 244px; height: 325px;" /></p>

<pre>
<strong>输入：</strong>bank = ["000","111","000"]
<strong>输出：</strong>0
<strong>解释：</strong>不存在两个位于不同行的设备
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == bank.length</code></li>
	<li><code>n == bank[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 500</code></li>
	<li><code>bank[i][j]</code> 为 <code>'0'</code> 或 <code>'1'</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：逐行统计

我们可以逐行统计每行的安全设备数量，如果当前行没有安全设备，直接跳过，否则我们将当前行的安全设备数量乘以前一行的安全设备数量，累加到答案中。然后更新前一行的安全设备数量为当前行的安全设备数量。

时间复杂度 $O(m \times n)$，其中 $m$ 和 $n$ 分别为行数和列数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        ans = pre = 0
        for row in bank:
            if (cur := row.count("1")) > 0:
                ans += pre * cur
                pre = cur
        return ans
```

#### Java

```java
class Solution {
    public int numberOfBeams(String[] bank) {
        int ans = 0, pre = 0;
        for (String row : bank) {
            int cur = 0;
            for (int i = 0; i < row.length(); ++i) {
                cur += row.charAt(i) - '0';
            }
            if (cur > 0) {
                ans += pre * cur;
                pre = cur;
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
    int numberOfBeams(vector<string>& bank) {
        int ans = 0, pre = 0;
        for (auto& row : bank) {
            int cur = count(row.begin(), row.end(), '1');
            if (cur) {
                ans += pre * cur;
                pre = cur;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func numberOfBeams(bank []string) (ans int) {
	pre := 0
	for _, row := range bank {
		if cur := strings.Count(row, "1"); cur > 0 {
			ans += pre * cur
			pre = cur
		}
	}
	return
}
```

#### TypeScript

```ts
function numberOfBeams(bank: string[]): number {
    let [ans, pre] = [0, 0];
    for (const row of bank) {
        const cur = row.split('1').length - 1;
        if (cur) {
            ans += pre * cur;
            pre = cur;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn number_of_beams(bank: Vec<String>) -> i32 {
        let mut ans = 0;
        let mut pre = 0;
        for row in bank {
            let cur = row.chars().filter(|&c| c == '1').count() as i32;
            if cur > 0 {
                ans += pre * cur;
                pre = cur;
            }
        }
        ans
    }
}
```

#### C

```c
int numberOfBeams(char** bank, int bankSize) {
    int ans = 0, pre = 0;
    for (int i = 0; i < bankSize; ++i) {
        int cur = 0;
        for (int j = 0; bank[i][j] != '\0'; ++j) {
            if (bank[i][j] == '1') {
                cur++;
            }
        }
        if (cur) {
            ans += pre * cur;
            pre = cur;
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

# [2126. 摧毁小行星](https://leetcode.cn/problems/destroying-asteroids){#2126}

{{< tabs "2126" >}}

{{% tab "python" %}}
```python
class Solution:
    def asteroidsDestroyed(self, mass: int, asteroids: List[int]) -> bool:
        asteroids.sort()
        for x in asteroids:
            if mass < x:
                return False
            mass += x
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean asteroidsDestroyed(int mass, int[] asteroids) {
        Arrays.sort(asteroids);
        long m = mass;
        for (int x : asteroids) {
            if (m < x) {
                return false;
            }
            m += x;
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
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        ranges::sort(asteroids);
        long long m = mass;
        for (int x : asteroids) {
            if (m < x) {
                return false;
            }
            m += x;
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func asteroidsDestroyed(mass int, asteroids []int) bool {
	sort.Ints(asteroids)
	for _, x := range asteroids {
		if mass < x {
			return false
		}
		mass += x
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function asteroidsDestroyed(mass: number, asteroids: number[]): boolean {
    asteroids.sort((a, b) => a - b);
    for (const x of asteroids) {
        if (mass < x) {
            return false;
        }
        mass += x;
    }
    return true;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn asteroids_destroyed(mass: i32, mut asteroids: Vec<i32>) -> bool {
        let mut mass = mass as i64;
        asteroids.sort_unstable();
        for &x in &asteroids {
            if mass < x as i64 {
                return false;
            }
            mass += x as i64;
        }
        true
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} mass
 * @param {number[]} asteroids
 * @return {boolean}
 */
var asteroidsDestroyed = function (mass, asteroids) {
    asteroids.sort((a, b) => a - b);
    for (const x of asteroids) {
        if (mass < x) {
            return false;
        }
        mass += x;
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

<p>给你一个整数&nbsp;<code>mass</code>&nbsp;，它表示一颗行星的初始质量。再给你一个整数数组&nbsp;<code>asteroids</code>&nbsp;，其中&nbsp;<code>asteroids[i]</code>&nbsp;是第&nbsp;<code>i</code>&nbsp;颗小行星的质量。</p>

<p>你可以按 <strong>任意顺序</strong>&nbsp;重新安排小行星的顺序，然后让行星跟它们发生碰撞。如果行星碰撞时的质量 <strong>大于等于</strong>&nbsp;小行星的质量，那么小行星被 <strong>摧毁</strong>&nbsp;，并且行星会 <strong>获得</strong>&nbsp;这颗小行星的质量。否则，行星将被摧毁。</p>

<p>如果所有小行星 <strong>都</strong>&nbsp;能被摧毁，请返回 <code>true</code>&nbsp;，否则返回 <code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>mass = 10, asteroids = [3,9,19,5,21]
<b>输出：</b>true
<b>解释：</b>一种安排小行星的方式为 [9,19,5,3,21] ：
- 行星与质量为 9 的小行星碰撞。新的行星质量为：10 + 9 = 19
- 行星与质量为 19 的小行星碰撞。新的行星质量为：19 + 19 = 38
- 行星与质量为 5 的小行星碰撞。新的行星质量为：38 + 5 = 43
- 行星与质量为 3 的小行星碰撞。新的行星质量为：43 + 3 = 46
- 行星与质量为 21 的小行星碰撞。新的行星质量为：46 + 21 = 67
所有小行星都被摧毁。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>mass = 5, asteroids = [4,9,23,4]
<b>输出：</b>false
<b>解释：</b>
行星无论如何没法获得足够质量去摧毁质量为 23 的小行星。
行星把别的小行星摧毁后，质量为 5 + 4 + 9 + 4 = 22 。
它比 23 小，所以无法摧毁最后一颗小行星。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= mass &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= asteroids.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= asteroids[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 贪心

根据题目描述，我们可以将小行星按质量从小到大排序，然后依次遍历小行星，如果行星的质量小于小行星的质量，那么行星将被摧毁，返回 `false`，否则行星将获得这颗小行星的质量。

如果所有小行星都能被摧毁，返回 `true`。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 是小行星的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def asteroidsDestroyed(self, mass: int, asteroids: List[int]) -> bool:
        asteroids.sort()
        for x in asteroids:
            if mass < x:
                return False
            mass += x
        return True
```

#### Java

```java
class Solution {
    public boolean asteroidsDestroyed(int mass, int[] asteroids) {
        Arrays.sort(asteroids);
        long m = mass;
        for (int x : asteroids) {
            if (m < x) {
                return false;
            }
            m += x;
        }
        return true;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        ranges::sort(asteroids);
        long long m = mass;
        for (int x : asteroids) {
            if (m < x) {
                return false;
            }
            m += x;
        }
        return true;
    }
};
```

#### Go

```go
func asteroidsDestroyed(mass int, asteroids []int) bool {
	sort.Ints(asteroids)
	for _, x := range asteroids {
		if mass < x {
			return false
		}
		mass += x
	}
	return true
}
```

#### TypeScript

```ts
function asteroidsDestroyed(mass: number, asteroids: number[]): boolean {
    asteroids.sort((a, b) => a - b);
    for (const x of asteroids) {
        if (mass < x) {
            return false;
        }
        mass += x;
    }
    return true;
}
```

#### Rust

```rust
impl Solution {
    pub fn asteroids_destroyed(mass: i32, mut asteroids: Vec<i32>) -> bool {
        let mut mass = mass as i64;
        asteroids.sort_unstable();
        for &x in &asteroids {
            if mass < x as i64 {
                return false;
            }
            mass += x as i64;
        }
        true
    }
}
```

#### JavaScript

```js
/**
 * @param {number} mass
 * @param {number[]} asteroids
 * @return {boolean}
 */
var asteroidsDestroyed = function (mass, asteroids) {
    asteroids.sort((a, b) => a - b);
    for (const x of asteroids) {
        if (mass < x) {
            return false;
        }
        mass += x;
    }
    return true;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2127. 参加会议的最多员工数](https://leetcode.cn/problems/maximum-employees-to-be-invited-to-a-meeting){#2127}

{{< tabs "2127" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumInvitations(self, favorite: List[int]) -> int:
        def max_cycle(fa: List[int]) -> int:
            n = len(fa)
            vis = [False] * n
            ans = 0
            for i in range(n):
                if vis[i]:
                    continue
                cycle = []
                j = i
                while not vis[j]:
                    cycle.append(j)
                    vis[j] = True
                    j = fa[j]
                for k, v in enumerate(cycle):
                    if v == j:
                        ans = max(ans, len(cycle) - k)
                        break
            return ans

        def topological_sort(fa: List[int]) -> int:
            n = len(fa)
            indeg = [0] * n
            dist = [1] * n
            for v in fa:
                indeg[v] += 1
            q = deque(i for i, v in enumerate(indeg) if v == 0)
            while q:
                i = q.popleft()
                dist[fa[i]] = max(dist[fa[i]], dist[i] + 1)
                indeg[fa[i]] -= 1
                if indeg[fa[i]] == 0:
                    q.append(fa[i])
            return sum(dist[i] for i, v in enumerate(fa) if i == fa[fa[i]])

        return max(max_cycle(favorite), topological_sort(favorite))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumInvitations(int[] favorite) {
        return Math.max(maxCycle(favorite), topologicalSort(favorite));
    }

    private int maxCycle(int[] fa) {
        int n = fa.length;
        boolean[] vis = new boolean[n];
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (vis[i]) {
                continue;
            }
            List<Integer> cycle = new ArrayList<>();
            int j = i;
            while (!vis[j]) {
                cycle.add(j);
                vis[j] = true;
                j = fa[j];
            }
            for (int k = 0; k < cycle.size(); ++k) {
                if (cycle.get(k) == j) {
                    ans = Math.max(ans, cycle.size() - k);
                }
            }
        }
        return ans;
    }

    private int topologicalSort(int[] fa) {
        int n = fa.length;
        int[] indeg = new int[n];
        int[] dist = new int[n];
        Arrays.fill(dist, 1);
        for (int v : fa) {
            indeg[v]++;
        }
        Deque<Integer> q = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            if (indeg[i] == 0) {
                q.offer(i);
            }
        }
        int ans = 0;
        while (!q.isEmpty()) {
            int i = q.pollFirst();
            dist[fa[i]] = Math.max(dist[fa[i]], dist[i] + 1);
            if (--indeg[fa[i]] == 0) {
                q.offer(fa[i]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (i == fa[fa[i]]) {
                ans += dist[i];
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
    int maximumInvitations(vector<int>& favorite) {
        return max(maxCycle(favorite), topologicalSort(favorite));
    }

    int maxCycle(vector<int>& fa) {
        int n = fa.size();
        vector<bool> vis(n);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (vis[i]) continue;
            vector<int> cycle;
            int j = i;
            while (!vis[j]) {
                cycle.push_back(j);
                vis[j] = true;
                j = fa[j];
            }
            for (int k = 0; k < cycle.size(); ++k) {
                if (cycle[k] == j) {
                    ans = max(ans, (int) cycle.size() - k);
                    break;
                }
            }
        }
        return ans;
    }

    int topologicalSort(vector<int>& fa) {
        int n = fa.size();
        vector<int> indeg(n);
        vector<int> dist(n, 1);
        for (int v : fa) ++indeg[v];
        queue<int> q;
        for (int i = 0; i < n; ++i)
            if (indeg[i] == 0) q.push(i);
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            dist[fa[i]] = max(dist[fa[i]], dist[i] + 1);
            if (--indeg[fa[i]] == 0) q.push(fa[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
            if (i == fa[fa[i]]) ans += dist[i];
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumInvitations(favorite []int) int {
	a, b := maxCycle(favorite), topologicalSort(favorite)
	return max(a, b)
}

func maxCycle(fa []int) int {
	n := len(fa)
	vis := make([]bool, n)
	ans := 0
	for i := range fa {
		if vis[i] {
			continue
		}
		j := i
		cycle := []int{}
		for !vis[j] {
			cycle = append(cycle, j)
			vis[j] = true
			j = fa[j]
		}
		for k, v := range cycle {
			if v == j {
				ans = max(ans, len(cycle)-k)
				break
			}
		}
	}
	return ans
}

func topologicalSort(fa []int) int {
	n := len(fa)
	indeg := make([]int, n)
	dist := make([]int, n)
	for i := range fa {
		dist[i] = 1
	}
	for _, v := range fa {
		indeg[v]++
	}
	q := []int{}
	for i, v := range indeg {
		if v == 0 {
			q = append(q, i)
		}
	}
	for len(q) > 0 {
		i := q[0]
		q = q[1:]
		dist[fa[i]] = max(dist[fa[i]], dist[i]+1)
		indeg[fa[i]]--
		if indeg[fa[i]] == 0 {
			q = append(q, fa[i])
		}
	}
	ans := 0
	for i := range fa {
		if i == fa[fa[i]] {
			ans += dist[i]
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumInvitations(favorite: number[]): number {
    return Math.max(maxCycle(favorite), topologicalSort(favorite));
}

function maxCycle(fa: number[]): number {
    const n = fa.length;
    const vis: boolean[] = Array(n).fill(false);
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        if (vis[i]) {
            continue;
        }
        const cycle: number[] = [];
        let j = i;
        for (; !vis[j]; j = fa[j]) {
            cycle.push(j);
            vis[j] = true;
        }
        for (let k = 0; k < cycle.length; ++k) {
            if (cycle[k] === j) {
                ans = Math.max(ans, cycle.length - k);
            }
        }
    }
    return ans;
}

function topologicalSort(fa: number[]): number {
    const n = fa.length;
    const indeg: number[] = Array(n).fill(0);
    const dist: number[] = Array(n).fill(1);
    for (const v of fa) {
        ++indeg[v];
    }
    const q: number[] = [];
    for (let i = 0; i < n; ++i) {
        if (indeg[i] === 0) {
            q.push(i);
        }
    }
    let ans = 0;
    while (q.length) {
        const i = q.pop()!;
        dist[fa[i]] = Math.max(dist[fa[i]], dist[i] + 1);
        if (--indeg[fa[i]] === 0) {
            q.push(fa[i]);
        }
    }
    for (let i = 0; i < n; ++i) {
        if (i === fa[fa[i]]) {
            ans += dist[i];
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

<p>一个公司准备组织一场会议，邀请名单上有&nbsp;<code>n</code>&nbsp;位员工。公司准备了一张 <strong>圆形</strong>&nbsp;的桌子，可以坐下 <strong>任意数目</strong>&nbsp;的员工。</p>

<p>员工编号为 <code>0</code>&nbsp;到 <code>n - 1</code>&nbsp;。每位员工都有一位 <strong>喜欢</strong>&nbsp;的员工，每位员工&nbsp;<strong>当且仅当</strong>&nbsp;他被安排在喜欢员工的旁边，他才会参加会议。每位员工喜欢的员工 <strong>不会</strong>&nbsp;是他自己。</p>

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>favorite</code>&nbsp;，其中&nbsp;<code>favorite[i]</code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;位员工喜欢的员工。请你返回参加会议的&nbsp;<strong>最多员工数目</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2127.Maximum%20Employees%20to%20Be%20Invited%20to%20a%20Meeting/images/ex1.png" style="width: 236px; height: 195px;" /></p>

<pre>
<b>输入：</b>favorite = [2,2,1,2]
<b>输出：</b>3
<strong>解释：</strong>
上图展示了公司邀请员工 0，1 和 2 参加会议以及他们在圆桌上的座位。
没办法邀请所有员工参与会议，因为员工 2 没办法同时坐在 0，1 和 3 员工的旁边。
注意，公司也可以邀请员工 1，2 和 3 参加会议。
所以最多参加会议的员工数目为 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>favorite = [1,2,0]
<b>输出：</b>3
<b>解释：</b>
每个员工都至少是另一个员工喜欢的员工。所以公司邀请他们所有人参加会议的前提是所有人都参加了会议。
座位安排同图 1 所示：
- 员工 0 坐在员工 2 和 1 之间。
- 员工 1 坐在员工 0 和 2 之间。
- 员工 2 坐在员工 1 和 0 之间。
参与会议的最多员工数目为 3 。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2127.Maximum%20Employees%20to%20Be%20Invited%20to%20a%20Meeting/images/ex2.png" style="width: 219px; height: 220px;" /></p>

<pre>
<b>输入：</b>favorite = [3,0,1,4,1]
<b>输出：</b>4
<b>解释：</b>
上图展示了公司可以邀请员工 0，1，3 和 4 参加会议以及他们在圆桌上的座位。
员工 2 无法参加，因为他喜欢的员工 1 旁边的座位已经被占领了。
所以公司只能不邀请员工 2 。
参加会议的最多员工数目为 4 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == favorite.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= favorite[i] &lt;=&nbsp;n - 1</code></li>
	<li><code>favorite[i] != i</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：图的最大环 + 最长链

我们观察发现，题目中员工的喜好关系可以看作一个有向图，这个有向图可以分成多个“基环内向树”的结构。在每个结构中，包含一个环，而环上的每个节点都连接着一棵树。

什么是“基环内向树”？首先，基环树是一个具有 $n$ 个节点 $n$ 条边的有向图，而内向树是指这个有向图中，每个节点都有且仅有一条出边。本题中，每个员工都有且仅有一个喜欢的员工，因此，构成的有向图可以由多个“基环内向树”构成。

<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2127.Maximum%20Employees%20to%20Be%20Invited%20to%20a%20Meeting/images/05Dxh9.png"></p>

对于本题，我们可以求出图的最大环的长度，这里我们只需要求出最大的一个环的长度，这是因为，如果有多个环，那么不同环之间是不连通的，不符合题意。

另外，对于环的大小等于 $2$ 的长度，即存在两个员工互相喜欢，那么我们可以把这两个员工安排在一起，如果这两个员工各自被别的员工喜欢，那么我们只需要把喜欢他们的员工安排在他们的旁边即可。如果有多个这样的情况，我们可以把他们都安排上。

因此，问题实际上等价于求出图的最大环的长度，以及所有长度为 $2$ 的环加上其最长链。求这两者的最大值即可。求最长链到长度为 $2$ 的环，我们可以使用拓扑排序。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 `favorite` 的长度。

相似题目：

-   [2360. 图中的最长环](https://github.com/doocs/leetcode/blob/main/solution/2300-2399/2360.Longest%20Cycle%20in%20a%20Graph/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumInvitations(self, favorite: List[int]) -> int:
        def max_cycle(fa: List[int]) -> int:
            n = len(fa)
            vis = [False] * n
            ans = 0
            for i in range(n):
                if vis[i]:
                    continue
                cycle = []
                j = i
                while not vis[j]:
                    cycle.append(j)
                    vis[j] = True
                    j = fa[j]
                for k, v in enumerate(cycle):
                    if v == j:
                        ans = max(ans, len(cycle) - k)
                        break
            return ans

        def topological_sort(fa: List[int]) -> int:
            n = len(fa)
            indeg = [0] * n
            dist = [1] * n
            for v in fa:
                indeg[v] += 1
            q = deque(i for i, v in enumerate(indeg) if v == 0)
            while q:
                i = q.popleft()
                dist[fa[i]] = max(dist[fa[i]], dist[i] + 1)
                indeg[fa[i]] -= 1
                if indeg[fa[i]] == 0:
                    q.append(fa[i])
            return sum(dist[i] for i, v in enumerate(fa) if i == fa[fa[i]])

        return max(max_cycle(favorite), topological_sort(favorite))
```

#### Java

```java
class Solution {
    public int maximumInvitations(int[] favorite) {
        return Math.max(maxCycle(favorite), topologicalSort(favorite));
    }

    private int maxCycle(int[] fa) {
        int n = fa.length;
        boolean[] vis = new boolean[n];
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (vis[i]) {
                continue;
            }
            List<Integer> cycle = new ArrayList<>();
            int j = i;
            while (!vis[j]) {
                cycle.add(j);
                vis[j] = true;
                j = fa[j];
            }
            for (int k = 0; k < cycle.size(); ++k) {
                if (cycle.get(k) == j) {
                    ans = Math.max(ans, cycle.size() - k);
                }
            }
        }
        return ans;
    }

    private int topologicalSort(int[] fa) {
        int n = fa.length;
        int[] indeg = new int[n];
        int[] dist = new int[n];
        Arrays.fill(dist, 1);
        for (int v : fa) {
            indeg[v]++;
        }
        Deque<Integer> q = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            if (indeg[i] == 0) {
                q.offer(i);
            }
        }
        int ans = 0;
        while (!q.isEmpty()) {
            int i = q.pollFirst();
            dist[fa[i]] = Math.max(dist[fa[i]], dist[i] + 1);
            if (--indeg[fa[i]] == 0) {
                q.offer(fa[i]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (i == fa[fa[i]]) {
                ans += dist[i];
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
    int maximumInvitations(vector<int>& favorite) {
        return max(maxCycle(favorite), topologicalSort(favorite));
    }

    int maxCycle(vector<int>& fa) {
        int n = fa.size();
        vector<bool> vis(n);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (vis[i]) continue;
            vector<int> cycle;
            int j = i;
            while (!vis[j]) {
                cycle.push_back(j);
                vis[j] = true;
                j = fa[j];
            }
            for (int k = 0; k < cycle.size(); ++k) {
                if (cycle[k] == j) {
                    ans = max(ans, (int) cycle.size() - k);
                    break;
                }
            }
        }
        return ans;
    }

    int topologicalSort(vector<int>& fa) {
        int n = fa.size();
        vector<int> indeg(n);
        vector<int> dist(n, 1);
        for (int v : fa) ++indeg[v];
        queue<int> q;
        for (int i = 0; i < n; ++i)
            if (indeg[i] == 0) q.push(i);
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            dist[fa[i]] = max(dist[fa[i]], dist[i] + 1);
            if (--indeg[fa[i]] == 0) q.push(fa[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
            if (i == fa[fa[i]]) ans += dist[i];
        return ans;
    }
};
```

#### Go

```go
func maximumInvitations(favorite []int) int {
	a, b := maxCycle(favorite), topologicalSort(favorite)
	return max(a, b)
}

func maxCycle(fa []int) int {
	n := len(fa)
	vis := make([]bool, n)
	ans := 0
	for i := range fa {
		if vis[i] {
			continue
		}
		j := i
		cycle := []int{}
		for !vis[j] {
			cycle = append(cycle, j)
			vis[j] = true
			j = fa[j]
		}
		for k, v := range cycle {
			if v == j {
				ans = max(ans, len(cycle)-k)
				break
			}
		}
	}
	return ans
}

func topologicalSort(fa []int) int {
	n := len(fa)
	indeg := make([]int, n)
	dist := make([]int, n)
	for i := range fa {
		dist[i] = 1
	}
	for _, v := range fa {
		indeg[v]++
	}
	q := []int{}
	for i, v := range indeg {
		if v == 0 {
			q = append(q, i)
		}
	}
	for len(q) > 0 {
		i := q[0]
		q = q[1:]
		dist[fa[i]] = max(dist[fa[i]], dist[i]+1)
		indeg[fa[i]]--
		if indeg[fa[i]] == 0 {
			q = append(q, fa[i])
		}
	}
	ans := 0
	for i := range fa {
		if i == fa[fa[i]] {
			ans += dist[i]
		}
	}
	return ans
}
```

#### TypeScript

```ts
function maximumInvitations(favorite: number[]): number {
    return Math.max(maxCycle(favorite), topologicalSort(favorite));
}

function maxCycle(fa: number[]): number {
    const n = fa.length;
    const vis: boolean[] = Array(n).fill(false);
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        if (vis[i]) {
            continue;
        }
        const cycle: number[] = [];
        let j = i;
        for (; !vis[j]; j = fa[j]) {
            cycle.push(j);
            vis[j] = true;
        }
        for (let k = 0; k < cycle.length; ++k) {
            if (cycle[k] === j) {
                ans = Math.max(ans, cycle.length - k);
            }
        }
    }
    return ans;
}

function topologicalSort(fa: number[]): number {
    const n = fa.length;
    const indeg: number[] = Array(n).fill(0);
    const dist: number[] = Array(n).fill(1);
    for (const v of fa) {
        ++indeg[v];
    }
    const q: number[] = [];
    for (let i = 0; i < n; ++i) {
        if (indeg[i] === 0) {
            q.push(i);
        }
    }
    let ans = 0;
    while (q.length) {
        const i = q.pop()!;
        dist[fa[i]] = Math.max(dist[fa[i]], dist[i] + 1);
        if (--indeg[fa[i]] === 0) {
            q.push(fa[i]);
        }
    }
    for (let i = 0; i < n; ++i) {
        if (i === fa[fa[i]]) {
            ans += dist[i];
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

# [2128. 通过翻转行或列来去除所有的 1 🔒](https://leetcode.cn/problems/remove-all-ones-with-row-and-column-flips){#2128}

{{< tabs "2128" >}}

{{% tab "python" %}}
```python
class Solution:
    def removeOnes(self, grid: List[List[int]]) -> bool:
        s = set()
        for row in grid:
            t = tuple(row) if row[0] == grid[0][0] else tuple(x ^ 1 for x in row)
            s.add(t)
        return len(s) == 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean removeOnes(int[][] grid) {
        Set<String> s = new HashSet<>();
        int n = grid[0].length;
        for (var row : grid) {
            var cs = new char[n];
            for (int i = 0; i < n; ++i) {
                cs[i] = (char) (row[0] ^ row[i]);
            }
            s.add(String.valueOf(cs));
        }
        return s.size() == 1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        unordered_set<string> s;
        for (auto& row : grid) {
            string t;
            for (int x : row) {
                t.push_back('0' + (row[0] == 0 ? x : x ^ 1));
            }
            s.insert(t);
        }
        return s.size() == 1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func removeOnes(grid [][]int) bool {
	s := map[string]bool{}
	for _, row := range grid {
		t := []byte{}
		for _, x := range row {
			if row[0] == 1 {
				x ^= 1
			}
			t = append(t, byte(x)+'0')
		}
		s[string(t)] = true
	}
	return len(s) == 1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function removeOnes(grid: number[][]): boolean {
    const s = new Set<string>();
    for (const row of grid) {
        if (row[0] === 1) {
            for (let i = 0; i < row.length; i++) {
                row[i] ^= 1;
            }
        }
        const t = row.join('');
        s.add(t);
    }
    return s.size === 1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个大小为&nbsp;<code>m x n</code> 的二进制矩阵&nbsp;<code>grid</code>。</p>

<p>每次操作，你可以选择 <strong>任意</strong> 一行 或者 一列，然后将其中的所有值翻转（<code>0</code> 变成 <code>1</code>， <code>1</code>变成 <code>0</code>）。</p>

<p>如果经过 <strong>任意次</strong> 操作，你能将矩阵中所有的 <code>1</code> 去除，那么返回 <code>true</code>；否则返回 <code>false</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2128.Remove%20All%20Ones%20With%20Row%20and%20Column%20Flips/images/image-20220103191300-1.png" style="width: 756px; height: 225px;">
<pre><strong>输入:</strong> grid = [[0,1,0],[1,0,1],[0,1,0]]
<strong>输出:</strong> true
<strong>解释:</strong> 一种去除所有 1 的可行方法是:
- 翻转矩阵的中间的行
- 翻转矩阵的中间的列
</pre>

<p><strong>示例 2:</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2128.Remove%20All%20Ones%20With%20Row%20and%20Column%20Flips/images/image-20220103181204-7.png" style="width: 237px; height: 225px;">
<pre><strong>输入:</strong> grid = [[1,1,0],[0,0,0],[0,0,0]]
<strong>输出:</strong> false
<strong>解释:</strong> 不可能去除矩阵中所有的 1。
</pre>

<p><strong>示例 3:</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2128.Remove%20All%20Ones%20With%20Row%20and%20Column%20Flips/images/image-20220103181224-8.png" style="width: 114px; height: 100px;">
<pre><strong>输入:</strong> grid = [[0]]
<strong>输出:</strong> true
<strong>解释:</strong> 矩阵中不存在 1，已经符合要求。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 300</code></li>
	<li><code>grid[i][j]</code> 是&nbsp;<code>0</code>&nbsp;或者&nbsp;<code>1</code>.</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们观察发现，如果矩阵中的两行满足以下条件之一，则它们可以通过翻转某些列的方式得到相等的行：

1. 两行的对应位置元素相等，即如果其中一行元素为 $1,0,0,1$，则另一行元素也为 $1,0,0,1$；
1. 两行的对应位置元素相反，即如果其中一行元素为 $1,0,0,1$，则另一行元素为 $0,1,1,0$。

我们称满足以上条件之一的两行元素为“等价行”，那么题目所求的答案即为矩阵中最多包含等价行的行数。

因此，我们可以遍历矩阵的每一行，将每一行转换成第一个元素为 $0$ 的“等价行”。具体做法如下：

-   如果当前行的第一个元素为 $0$，那么当前行的元素保持不变；
-   如果当前行的第一个元素为 $1$，那么我们将当前行的每个元素进行翻转，即 $0$ 变成 $1$, $1$ 变成 $0$。也就是说，我们将以 $1$ 开头的行翻转成以 $0$ 开头的“等价行”。

这样一来，我们只需要用一个哈希表来统计转换后的每一行，如果最后哈希表只有一个元素，那么说明我们可以通过翻转行或列，将矩阵中所有的 $1$ 去除。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m)$。其中 $m$ 和 $n$ 分别是矩阵的行数和列数。

相似题目：

-   [1072. 按列翻转得到最大值等行数](https://github.com/doocs/leetcode/blob/main/solution/1000-1099/1072.Flip%20Columns%20For%20Maximum%20Number%20of%20Equal%20Rows/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def removeOnes(self, grid: List[List[int]]) -> bool:
        s = set()
        for row in grid:
            t = tuple(row) if row[0] == grid[0][0] else tuple(x ^ 1 for x in row)
            s.add(t)
        return len(s) == 1
```

#### Java

```java
class Solution {
    public boolean removeOnes(int[][] grid) {
        Set<String> s = new HashSet<>();
        int n = grid[0].length;
        for (var row : grid) {
            var cs = new char[n];
            for (int i = 0; i < n; ++i) {
                cs[i] = (char) (row[0] ^ row[i]);
            }
            s.add(String.valueOf(cs));
        }
        return s.size() == 1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        unordered_set<string> s;
        for (auto& row : grid) {
            string t;
            for (int x : row) {
                t.push_back('0' + (row[0] == 0 ? x : x ^ 1));
            }
            s.insert(t);
        }
        return s.size() == 1;
    }
};
```

#### Go

```go
func removeOnes(grid [][]int) bool {
	s := map[string]bool{}
	for _, row := range grid {
		t := []byte{}
		for _, x := range row {
			if row[0] == 1 {
				x ^= 1
			}
			t = append(t, byte(x)+'0')
		}
		s[string(t)] = true
	}
	return len(s) == 1
}
```

#### TypeScript

```ts
function removeOnes(grid: number[][]): boolean {
    const s = new Set<string>();
    for (const row of grid) {
        if (row[0] === 1) {
            for (let i = 0; i < row.length; i++) {
                row[i] ^= 1;
            }
        }
        const t = row.join('');
        s.add(t);
    }
    return s.size === 1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2129. 将标题首字母大写](https://leetcode.cn/problems/capitalize-the-title){#2129}

{{< tabs "2129" >}}

{{% tab "python" %}}
```python
class Solution:
    def capitalizeTitle(self, title: str) -> str:
        words = [w.lower() if len(w) < 3 else w.capitalize() for w in title.split()]
        return " ".join(words)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String capitalizeTitle(String title) {
        List<String> ans = new ArrayList<>();
        for (String s : title.split(" ")) {
            if (s.length() < 3) {
                ans.add(s.toLowerCase());
            } else {
                ans.add(s.substring(0, 1).toUpperCase() + s.substring(1).toLowerCase());
            }
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
    string capitalizeTitle(string title) {
        transform(title.begin(), title.end(), title.begin(), ::tolower);
        istringstream ss(title);
        string ans;
        while (ss >> title) {
            if (title.size() > 2) {
                title[0] = toupper(title[0]);
            }
            ans += title;
            ans += " ";
        }
        ans.pop_back();
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func capitalizeTitle(title string) string {
	title = strings.ToLower(title)
	words := strings.Split(title, " ")
	for i, s := range words {
		if len(s) > 2 {
			words[i] = strings.Title(s)
		}
	}
	return strings.Join(words, " ")
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function capitalizeTitle(title: string): string {
    return title
        .split(' ')
        .map(s =>
            s.length < 3
                ? s.toLowerCase()
                : s.substring(0, 1).toUpperCase() + s.substring(1).toLowerCase(),
        )
        .join(' ');
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public string CapitalizeTitle(string title) {
        List<string> ans = new List<string>();
        foreach (string s in title.Split(' ')) {
            if (s.Length < 3) {
                ans.Add(s.ToLower());
            } else {
                ans.Add(char.ToUpper(s[0]) + s.Substring(1).ToLower());
            }
        }
        return string.Join(" ", ans);
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串&nbsp;<code>title</code>&nbsp;，它由单个空格连接一个或多个单词组成，每个单词都只包含英文字母。请你按以下规则将每个单词的首字母 <strong>大写</strong>&nbsp;：</p>

<ul>
	<li>如果单词的长度为&nbsp;<code>1</code>&nbsp;或者&nbsp;<code>2</code>&nbsp;，所有字母变成小写。</li>
	<li>否则，将单词首字母大写，剩余字母变成小写。</li>
</ul>

<p>请你返回 <strong>大写后</strong>&nbsp;的<em>&nbsp;</em><code>title</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><b>示例 1：</b></p>

<pre><b>输入：</b>title = "capiTalIze tHe titLe"
<b>输出：</b>"Capitalize The Title"
<strong>解释：</strong>
由于所有单词的长度都至少为 3 ，将每个单词首字母大写，剩余字母变为小写。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>title = "First leTTeR of EACH Word"
<b>输出：</b>"First Letter of Each Word"
<strong>解释：</strong>
单词 "of" 长度为 2 ，所以它保持完全小写。
其他单词长度都至少为 3 ，所以其他单词首字母大写，剩余字母小写。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>title = "i lOve leetcode"
<b>输出：</b>"i Love Leetcode"
<strong>解释：</strong>
单词 "i" 长度为 1 ，所以它保留小写。
其他单词长度都至少为 3 ，所以其他单词首字母大写，剩余字母小写。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= title.length &lt;= 100</code></li>
	<li><code>title</code>&nbsp;由单个空格隔开的单词组成，且不含有任何前导或后缀空格。</li>
	<li>每个单词由大写和小写英文字母组成，且都是 <strong>非空</strong>&nbsp;的。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

直接模拟，按空格切分字符串，得到每个单词，再按题目转大小写。最后用空格连接每个单词。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是字符串 `title` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def capitalizeTitle(self, title: str) -> str:
        words = [w.lower() if len(w) < 3 else w.capitalize() for w in title.split()]
        return " ".join(words)
```

#### Java

```java
class Solution {
    public String capitalizeTitle(String title) {
        List<String> ans = new ArrayList<>();
        for (String s : title.split(" ")) {
            if (s.length() < 3) {
                ans.add(s.toLowerCase());
            } else {
                ans.add(s.substring(0, 1).toUpperCase() + s.substring(1).toLowerCase());
            }
        }
        return String.join(" ", ans);
    }
}
```

#### C++

```cpp
class Solution {
public:
    string capitalizeTitle(string title) {
        transform(title.begin(), title.end(), title.begin(), ::tolower);
        istringstream ss(title);
        string ans;
        while (ss >> title) {
            if (title.size() > 2) {
                title[0] = toupper(title[0]);
            }
            ans += title;
            ans += " ";
        }
        ans.pop_back();
        return ans;
    }
};
```

#### Go

```go
func capitalizeTitle(title string) string {
	title = strings.ToLower(title)
	words := strings.Split(title, " ")
	for i, s := range words {
		if len(s) > 2 {
			words[i] = strings.Title(s)
		}
	}
	return strings.Join(words, " ")
}
```

#### TypeScript

```ts
function capitalizeTitle(title: string): string {
    return title
        .split(' ')
        .map(s =>
            s.length < 3
                ? s.toLowerCase()
                : s.substring(0, 1).toUpperCase() + s.substring(1).toLowerCase(),
        )
        .join(' ');
}
```

#### C#

```cs
public class Solution {
    public string CapitalizeTitle(string title) {
        List<string> ans = new List<string>();
        foreach (string s in title.Split(' ')) {
            if (s.Length < 3) {
                ans.Add(s.ToLower());
            } else {
                ans.Add(char.ToUpper(s[0]) + s.Substring(1).ToLower());
            }
        }
        return string.Join(" ", ans);
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
