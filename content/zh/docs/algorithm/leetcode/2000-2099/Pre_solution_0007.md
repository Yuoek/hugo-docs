---
title: "2060_同源字符串检测"
date: 2025-10-08T18:38:57+08:00
weight: 7
tags: [二分查找, 动态规划, 哈希表, 回溯, 图, 字符串, 数学, 数据库, 数组, 模拟, 滑动窗口, 矩阵, 组合数学, 计数, 设计, 贪心]
---

{{< markmap >}}
### [2060_同源字符串检测](#2060)
#### [字符串](#2060)
#### [动态规划](#2060)
### [2061_扫地机器人清扫过的空间个数 🔒](#2061)
#### [数组](#2061)
#### [矩阵](#2061)
#### [模拟](#2061)
### [2062_统计字符串中的元音子字符串](#2062)
#### [哈希表](#2062)
#### [字符串](#2062)
### [2063_所有子字符串中的元音](#2063)
#### [数学](#2063)
#### [字符串](#2063)
#### [动态规划](#2063)
#### [组合数学](#2063)
### [2064_分配给商店的最多商品的最小值](#2064)
#### [贪心](#2064)
#### [数组](#2064)
#### [二分查找](#2064)
### [2065_最大化一张图中的路径价值](#2065)
#### [图](#2065)
#### [数组](#2065)
#### [回溯](#2065)
### [2066_账户余额 🔒](#2066)
#### [数据库](#2066)
### [2067_等计数子串的数量 🔒](#2067)
#### [哈希表](#2067)
#### [字符串](#2067)
#### [计数](#2067)
#### [滑动窗口](#2067)
### [2068_检查两个字符串是否几乎相等](#2068)
#### [哈希表](#2068)
#### [字符串](#2068)
#### [计数](#2068)
### [2069_模拟行走机器人 II](#2069)
#### [设计](#2069)
#### [模拟](#2069)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2060_同源字符串检测
___
#### 字符串
___
#### 动态规划
---
### 2061_扫地机器人清扫过的空间个数 🔒
___
#### 数组
___
#### 矩阵
___
#### 模拟
---
### 2062_统计字符串中的元音子字符串
___
#### 哈希表
___
#### 字符串
---
### 2063_所有子字符串中的元音
___
#### 数学
___
#### 字符串
___
#### 动态规划
___
#### 组合数学
---
### 2064_分配给商店的最多商品的最小值
___
#### 贪心
___
#### 数组
___
#### 二分查找
---
### 2065_最大化一张图中的路径价值
___
#### 图
___
#### 数组
___
#### 回溯
---
### 2066_账户余额 🔒
___
#### 数据库
---
### 2067_等计数子串的数量 🔒
___
#### 哈希表
___
#### 字符串
___
#### 计数
___
#### 滑动窗口
---
### 2068_检查两个字符串是否几乎相等
___
#### 哈希表
___
#### 字符串
___
#### 计数
---
### 2069_模拟行走机器人 II
___
#### 设计
___
#### 模拟
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 动态规划 | 哈希表 |
| 回溯 | 图 | 字符串 |
| 数学 | 数据库 | 数组 |
| 模拟 | 滑动窗口 | 矩阵 |
| 组合数学 | 计数 | 设计 |
| 贪心 |  |  |

# [2060. 同源字符串检测](https://leetcode.cn/problems/check-if-an-original-string-exists-given-two-encoded-strings){#2060}

{{< tabs "2060" >}}

{{% tab "ts" %}}
```ts
function possiblyEquals(s1: string, s2: string): boolean {
    const n = s1.length,
        m = s2.length;
    let dp: Array<Array<Set<number>>> = Array.from({ length: n + 1 }, v =>
        Array.from({ length: m + 1 }, w => new Set()),
    );
    dp[0][0].add(0);

    for (let i = 0; i <= n; i++) {
        for (let j = 0; j <= m; j++) {
            for (let delta of dp[i][j]) {
                // s1为数字
                let num = 0;
                if (delta <= 0) {
                    for (let p = i; i < Math.min(i + 3, n); p++) {
                        if (isDigit(s1[p])) {
                            num = num * 10 + Number(s1[p]);
                            dp[p + 1][j].add(delta + num);
                        } else {
                            break;
                        }
                    }
                }

                // s2为数字
                num = 0;
                if (delta >= 0) {
                    for (let q = j; q < Math.min(j + 3, m); q++) {
                        if (isDigit(s2[q])) {
                            num = num * 10 + Number(s2[q]);
                            dp[i][q + 1].add(delta - num);
                        } else {
                            break;
                        }
                    }
                }

                // 数字匹配s1为字母
                if (i < n && delta < 0 && !isDigit(s1[i])) {
                    dp[i + 1][j].add(delta + 1);
                }

                // 数字匹配s2为字母
                if (j < m && delta > 0 && !isDigit(s2[j])) {
                    dp[i][j + 1].add(delta - 1);
                }

                // 两个字母匹配
                if (i < n && j < m && delta == 0 && s1[i] == s2[j]) {
                    dp[i + 1][j + 1].add(0);
                }
            }
        }
    }
    return dp[n][m].has(0);
}

function isDigit(char: string): boolean {
    return /^\d{1}$/g.test(char);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>原字符串由小写字母组成，可以按下述步骤编码：</p>

<ul>
	<li>任意将其 <strong>分割</strong> 为由若干 <strong>非空</strong> 子字符串组成的一个 <strong>序列</strong> 。</li>
	<li>任意选择序列中的一些元素（也可能不选择），然后将这些元素替换为元素各自的长度（作为一个数字型的字符串）。</li>
	<li>重新 <strong>顺次连接</strong> 序列，得到编码后的字符串。</li>
</ul>

<p>例如，编码 <code>"abcdefghijklmnop"</code> 的一种方法可以描述为：</p>

<ul>
	<li>将原字符串分割得到一个序列：<code>["ab", "cdefghijklmn", "o", "p"]</code> 。</li>
	<li>选出其中第二个和第三个元素并分别替换为它们自身的长度。序列变为 <code>["ab", "12", "1", "p"]</code> 。</li>
	<li>重新顺次连接序列中的元素，得到编码后的字符串：<code>"ab121p"</code> 。</li>
</ul>

<p>给你两个编码后的字符串 <code>s1</code> 和 <code>s2</code> ，由小写英文字母和数字 <code>1-9</code> 组成。如果存在能够同时编码得到 <code>s1</code> 和 <code>s2</code> 原字符串，返回 <code>true</code> ；否则，返回 <code>false</code>。</p>

<p><strong>注意：</strong>生成的测试用例满足 <code>s1</code> 和 <code>s2</code> 中连续数字数不超过 <code>3</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s1 = "internationalization", s2 = "i18n"
<strong>输出：</strong>true
<strong>解释：</strong>"internationalization" 可以作为原字符串
- "internationalization" 
  -&gt; 分割：      ["internationalization"]
  -&gt; 不替换任何元素
  -&gt; 连接：      "internationalization"，得到 s1
- "internationalization"
  -&gt; 分割：      ["i", "nternationalizatio", "n"]
  -&gt; 替换：      ["i", "18",                 "n"]
  -&gt; 连接：      "i18n"，得到 s2
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s1 = "l123e", s2 = "44"
<strong>输出：</strong>true
<strong>解释：</strong>"leetcode" 可以作为原字符串
- "leetcode" 
  -&gt; 分割：       ["l", "e", "et", "cod", "e"]
  -&gt; 替换：       ["l", "1", "2",  "3",   "e"]
  -&gt; 连接：       "l123e"，得到 s1
- "leetcode" 
  -&gt; 分割：       ["leet", "code"]
  -&gt; 替换：       ["4",    "4"]
  -&gt; 连接：       "44"，得到 s2
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s1 = "a5b", s2 = "c5b"
<strong>输出：</strong>false
<strong>解释：</strong>不存在这样的原字符串
- 编码为 s1 的字符串必须以字母 'a' 开头
- 编码为 s2 的字符串必须以字母 'c' 开头
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>s1 = "112s", s2 = "g841"
<strong>输出：</strong>true
<strong>解释：</strong>"gaaaaaaaaaaaas" 可以作为原字符串
- "gaaaaaaaaaaaas"
  -&gt; 分割：       ["g", "aaaaaaaaaaaa", "s"]
  -&gt; 替换：       ["1", "12",           "s"]
  -&gt; 连接：       "112s"，得到 s1
- "gaaaaaaaaaaaas"
  -&gt; 分割：       ["g", "aaaaaaaa", "aaaa", "s"]
  -&gt; 替换：       ["g", "8",        "4",    "1"]
  -&gt; 连接         "g841"，得到 s2
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>s1 = "ab", s2 = "a2"
<strong>输出：</strong>false
<strong>解释：</strong>不存在这样的原字符串
- 编码为 s1 的字符串由两个字母组成
- 编码为 s2 的字符串由三个字母组成
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s1.length, s2.length &lt;= 40</code></li>
	<li><code>s1</code> 和 <code>s2</code> 仅由数字 <code>1-9</code> 和小写英文字母组成</li>
	<li><code>s1</code> 和 <code>s2</code> 中连续数字数不超过 <code>3</code></li>
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

#### TypeScript

```ts
function possiblyEquals(s1: string, s2: string): boolean {
    const n = s1.length,
        m = s2.length;
    let dp: Array<Array<Set<number>>> = Array.from({ length: n + 1 }, v =>
        Array.from({ length: m + 1 }, w => new Set()),
    );
    dp[0][0].add(0);

    for (let i = 0; i <= n; i++) {
        for (let j = 0; j <= m; j++) {
            for (let delta of dp[i][j]) {
                // s1为数字
                let num = 0;
                if (delta <= 0) {
                    for (let p = i; i < Math.min(i + 3, n); p++) {
                        if (isDigit(s1[p])) {
                            num = num * 10 + Number(s1[p]);
                            dp[p + 1][j].add(delta + num);
                        } else {
                            break;
                        }
                    }
                }

                // s2为数字
                num = 0;
                if (delta >= 0) {
                    for (let q = j; q < Math.min(j + 3, m); q++) {
                        if (isDigit(s2[q])) {
                            num = num * 10 + Number(s2[q]);
                            dp[i][q + 1].add(delta - num);
                        } else {
                            break;
                        }
                    }
                }

                // 数字匹配s1为字母
                if (i < n && delta < 0 && !isDigit(s1[i])) {
                    dp[i + 1][j].add(delta + 1);
                }

                // 数字匹配s2为字母
                if (j < m && delta > 0 && !isDigit(s2[j])) {
                    dp[i][j + 1].add(delta - 1);
                }

                // 两个字母匹配
                if (i < n && j < m && delta == 0 && s1[i] == s2[j]) {
                    dp[i + 1][j + 1].add(0);
                }
            }
        }
    }
    return dp[n][m].has(0);
}

function isDigit(char: string): boolean {
    return /^\d{1}$/g.test(char);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2061. 扫地机器人清扫过的空间个数 🔒](https://leetcode.cn/problems/number-of-spaces-cleaning-robot-cleaned){#2061}

{{< tabs "2061" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfCleanRooms(self, room: List[List[int]]) -> int:
        dirs = (0, 1, 0, -1, 0)
        i = j = k = 0
        ans = 0
        vis = set()
        while (i, j, k) not in vis:
            vis.add((i, j, k))
            ans += room[i][j] == 0
            room[i][j] = -1
            x, y = i + dirs[k], j + dirs[k + 1]
            if 0 <= x < len(room) and 0 <= y < len(room[0]) and room[x][y] != 1:
                i, j = x, y
            else:
                k = (k + 1) % 4
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numberOfCleanRooms(int[][] room) {
        int[] dirs = {0, 1, 0, -1, 0};
        int i = 0, j = 0, k = 0;
        int m = room.length, n = room[0].length;
        boolean[][][] vis = new boolean[m][n][4];
        int ans = 0;
        while (!vis[i][j][k]) {
            vis[i][j][k] = true;
            ans += room[i][j] == 0 ? 1 : 0;
            room[i][j] = -1;
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && room[x][y] != 1) {
                i = x;
                j = y;
            } else {
                k = (k + 1) % 4;
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
    int numberOfCleanRooms(vector<vector<int>>& room) {
        int dirs[5] = {0, 1, 0, -1, 0};
        int i = 0, j = 0, k = 0;
        int m = room.size(), n = room[0].size();
        bool vis[m][n][4];
        memset(vis, false, sizeof(vis));
        int ans = 0;
        while (!vis[i][j][k]) {
            vis[i][j][k] = true;
            ans += room[i][j] == 0 ? 1 : 0;
            room[i][j] = -1;
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && room[x][y] != 1) {
                i = x;
                j = y;
            } else {
                k = (k + 1) % 4;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfCleanRooms(room [][]int) (ans int) {
	m, n := len(room), len(room[0])
	vis := make([][][4]bool, m)
	for i := range vis {
		vis[i] = make([][4]bool, n)
	}
	dirs := [5]int{0, 1, 0, -1, 0}
	var i, j, k int
	for !vis[i][j][k] {
		vis[i][j][k] = true
		if room[i][j] == 0 {
			ans++
			room[i][j] = -1
		}
		x, y := i+dirs[k], j+dirs[k+1]
		if x >= 0 && x < m && y >= 0 && y < n && room[x][y] != 1 {
			i, j = x, y
		} else {
			k = (k + 1) % 4
		}
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

<p>一个房间用一个<strong>从 0 开始索引</strong>的二维二进制矩阵 <code>room</code> 表示，其中 <code>0</code> 表示<strong>空闲</strong>空间， <code>1</code> 表示放有<strong>物体</strong>的空间。在每个测试用例中，房间左上角永远是空闲的。</p>

<p>一个扫地机器人面向右侧，从左上角开始清扫。机器人将一直前进，直到抵达房间边界或触碰到物体时，机器人将会<strong>顺时针</strong>旋转 90 度并重复以上步骤。初始位置和所有机器人走过的空间都会被它<strong>清扫干净</strong>。</p>

<p>若机器人持续运转下去，返回被<strong>清扫干净</strong>的空间数量。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong><br />
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2061.Number%20of%20Spaces%20Cleaning%20Robot%20Cleaned/images/image-20211101204703-1.png" style="width: 250px; height: 242px;" /></p>

<pre>
<strong>输入:</strong> room = [[0,0,0],[1,1,0],[0,0,0]]
<strong>输出:</strong> 7
<strong>解释:</strong>
机器人清理了位于 (0, 0)、 (0, 1) 和 (0, 2) 的空间。
机器人位于房间边界，所以它顺时针旋转 90 度，现在面向下。
机器人清理了位于 (1, 2) 和 (2, 2) 的空间。
机器人位于房间边界，所以它顺时针旋转 90 度，现在面向左。
机器人清理了位于 (2, 1) 和 (2, 0) 的空间。
机器人已清理了所有 7 处空闲空间，所以返回 7。
</pre>

<p><strong>示例 2：</strong><br />
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2061.Number%20of%20Spaces%20Cleaning%20Robot%20Cleaned/images/image-20211101204736-2.png" style="width: 250px; height: 245px;" /></p>

<pre>
<strong>输入:</strong> room = [[0,1,0],[1,0,0],[0,0,0]]
<strong>输出t:</strong> 1
<strong>解释:</strong>
机器人清理了位于 (0, 0) 的空间。
机器人触碰到了物体，所以它顺时针旋转 90 度，现在面向下。
机器人触碰到了物体，所以它顺时针旋转 90 度，现在面向左。
机器人位于房间边界，所以它顺时针旋转 90 度，现在面向上。
机器人位于房间边界，所以它顺时针旋转 90 度，现在面向右。
机器人回到了起始位置。
机器人清理了 1 处空间，所以返回 1。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == room.length</code></li>
	<li><code>n == room[r].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 300</code></li>
	<li><code>room[r][c]</code> 只会是 <code>0</code> 或 <code>1</code> 。</li>
	<li><code>room[0][0] == 0</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS 模拟

我们从起点 $(0, 0)$ 开始模拟机器人的清扫过程，每次清扫当前位置，然后向前走一步，如果碰到墙壁或者已经清扫过的位置，就顺时针旋转 90 度，然后继续清扫。

过程中，我们用一个三元组 $(i, j, k)$ 表示机器人当前的位置 $(i, j)$ 和朝向 $k$，其中 $k$ 的取值范围为 $0, 1, 2, 3$，分别表示朝右、朝下、朝左、朝上。我们用一个集合 `vis` 记录所有访问过的状态三元组。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别为房间的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfCleanRooms(self, room: List[List[int]]) -> int:
        def dfs(i, j, k):
            if (i, j, k) in vis:
                return
            nonlocal ans
            ans += room[i][j] == 0
            room[i][j] = -1
            vis.add((i, j, k))
            x, y = i + dirs[k], j + dirs[k + 1]
            if 0 <= x < len(room) and 0 <= y < len(room[0]) and room[x][y] != 1:
                dfs(x, y, k)
            else:
                dfs(i, j, (k + 1) % 4)

        vis = set()
        dirs = (0, 1, 0, -1, 0)
        ans = 0
        dfs(0, 0, 0)
        return ans
```

#### Java

```java
class Solution {
    private boolean[][][] vis;
    private int[][] room;
    private int ans;

    public int numberOfCleanRooms(int[][] room) {
        vis = new boolean[room.length][room[0].length][4];
        this.room = room;
        dfs(0, 0, 0);
        return ans;
    }

    private void dfs(int i, int j, int k) {
        if (vis[i][j][k]) {
            return;
        }
        int[] dirs = {0, 1, 0, -1, 0};
        ans += room[i][j] == 0 ? 1 : 0;
        room[i][j] = -1;
        vis[i][j][k] = true;
        int x = i + dirs[k], y = j + dirs[k + 1];
        if (x >= 0 && x < room.length && y >= 0 && y < room[0].length && room[x][y] != 1) {
            dfs(x, y, k);
        } else {
            dfs(i, j, (k + 1) % 4);
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numberOfCleanRooms(vector<vector<int>>& room) {
        int m = room.size(), n = room[0].size();
        bool vis[m][n][4];
        memset(vis, false, sizeof(vis));
        int dirs[5] = {0, 1, 0, -1, 0};
        int ans = 0;
        function<void(int, int, int)> dfs = [&](int i, int j, int k) {
            if (vis[i][j][k]) {
                return;
            }
            ans += room[i][j] == 0;
            room[i][j] = -1;
            vis[i][j][k] = true;
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && room[x][y] != 1) {
                dfs(x, y, k);
            } else {
                dfs(i, j, (k + 1) % 4);
            }
        };
        dfs(0, 0, 0);
        return ans;
    }
};
```

#### Go

```go
func numberOfCleanRooms(room [][]int) (ans int) {
	m, n := len(room), len(room[0])
	vis := make([][][4]bool, m)
	for i := range vis {
		vis[i] = make([][4]bool, n)
	}
	dirs := [5]int{0, 1, 0, -1, 0}
	var dfs func(i, j, k int)
	dfs = func(i, j, k int) {
		if vis[i][j][k] {
			return
		}
		if room[i][j] == 0 {
			ans++
			room[i][j] = -1
		}
		vis[i][j][k] = true
		x, y := i+dirs[k], j+dirs[k+1]
		if x >= 0 && x < m && y >= 0 && y < n && room[x][y] != 1 {
			dfs(x, y, k)
		} else {
			dfs(i, j, (k+1)%4)
		}
	}
	dfs(0, 0, 0)
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfCleanRooms(self, room: List[List[int]]) -> int:
        dirs = (0, 1, 0, -1, 0)
        i = j = k = 0
        ans = 0
        vis = set()
        while (i, j, k) not in vis:
            vis.add((i, j, k))
            ans += room[i][j] == 0
            room[i][j] = -1
            x, y = i + dirs[k], j + dirs[k + 1]
            if 0 <= x < len(room) and 0 <= y < len(room[0]) and room[x][y] != 1:
                i, j = x, y
            else:
                k = (k + 1) % 4
        return ans
```

#### Java

```java
class Solution {
    public int numberOfCleanRooms(int[][] room) {
        int[] dirs = {0, 1, 0, -1, 0};
        int i = 0, j = 0, k = 0;
        int m = room.length, n = room[0].length;
        boolean[][][] vis = new boolean[m][n][4];
        int ans = 0;
        while (!vis[i][j][k]) {
            vis[i][j][k] = true;
            ans += room[i][j] == 0 ? 1 : 0;
            room[i][j] = -1;
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && room[x][y] != 1) {
                i = x;
                j = y;
            } else {
                k = (k + 1) % 4;
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
    int numberOfCleanRooms(vector<vector<int>>& room) {
        int dirs[5] = {0, 1, 0, -1, 0};
        int i = 0, j = 0, k = 0;
        int m = room.size(), n = room[0].size();
        bool vis[m][n][4];
        memset(vis, false, sizeof(vis));
        int ans = 0;
        while (!vis[i][j][k]) {
            vis[i][j][k] = true;
            ans += room[i][j] == 0 ? 1 : 0;
            room[i][j] = -1;
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && room[x][y] != 1) {
                i = x;
                j = y;
            } else {
                k = (k + 1) % 4;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func numberOfCleanRooms(room [][]int) (ans int) {
	m, n := len(room), len(room[0])
	vis := make([][][4]bool, m)
	for i := range vis {
		vis[i] = make([][4]bool, n)
	}
	dirs := [5]int{0, 1, 0, -1, 0}
	var i, j, k int
	for !vis[i][j][k] {
		vis[i][j][k] = true
		if room[i][j] == 0 {
			ans++
			room[i][j] = -1
		}
		x, y := i+dirs[k], j+dirs[k+1]
		if x >= 0 && x < m && y >= 0 && y < n && room[x][y] != 1 {
			i, j = x, y
		} else {
			k = (k + 1) % 4
		}
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2062. 统计字符串中的元音子字符串](https://leetcode.cn/problems/count-vowel-substrings-of-a-string){#2062}

{{< tabs "2062" >}}

{{% tab "python" %}}
```python
class Solution:
    def countVowelSubstrings(self, word: str) -> int:
        s = set("aeiou")
        ans, n = 0, len(word)
        for i in range(n):
            t = set()
            for c in word[i:]:
                if c not in s:
                    break
                t.add(c)
                ans += len(t) == 5
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countVowelSubstrings(String word) {
        int n = word.length();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            Set<Character> t = new HashSet<>();
            for (int j = i; j < n; ++j) {
                char c = word.charAt(j);
                if (!isVowel(c)) {
                    break;
                }
                t.add(c);
                if (t.size() == 5) {
                    ++ans;
                }
            }
        }
        return ans;
    }

    private boolean isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int countVowelSubstrings(string word) {
        int ans = 0;
        int n = word.size();
        for (int i = 0; i < n; ++i) {
            unordered_set<char> t;
            for (int j = i; j < n; ++j) {
                char c = word[j];
                if (!isVowel(c)) break;
                t.insert(c);
                ans += t.size() == 5;
            }
        }
        return ans;
    }

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countVowelSubstrings(word string) int {
	ans, n := 0, len(word)
	for i := range word {
		t := map[byte]bool{}
		for j := i; j < n; j++ {
			c := word[j]
			if !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
				break
			}
			t[c] = true
			if len(t) == 5 {
				ans++
			}
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countVowelSubstrings(word: string): number {
    let ans = 0;
    const n = word.length;
    for (let i = 0; i < n; ++i) {
        const t = new Set<string>();
        for (let j = i; j < n; ++j) {
            const c = word[j];
            if (!(c === 'a' || c === 'e' || c === 'i' || c === 'o' || c === 'u')) {
                break;
            }
            t.add(c);
            if (t.size === 5) {
                ans++;
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

<p><strong>子字符串</strong> 是字符串中的一个连续（非空）的字符序列。</p>

<p><strong>元音子字符串</strong> 是 <strong>仅</strong> 由元音（<code>'a'</code>、<code>'e'</code>、<code>'i'</code>、<code>'o'</code> 和 <code>'u'</code>）组成的一个子字符串，且必须包含 <strong>全部五种</strong> 元音。</p>

<p>给你一个字符串 <code>word</code> ，统计并返回 <code>word</code> 中 <strong>元音子字符串的数目</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>word = "aeiouu"
<strong>输出：</strong>2
<strong>解释：</strong>下面列出 word 中的元音子字符串（斜体加粗部分）：
- "<em><strong>aeiou</strong></em>u"
- "<strong><em>aeiouu</em></strong>"
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>word = "unicornarihan"
<strong>输出：</strong>0
<strong>解释：</strong>word 中不含 5 种元音，所以也不会存在元音子字符串。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>word = "cuaieuouac"
<strong>输出：</strong>7
<strong>解释：</strong>下面列出 word 中的元音子字符串（斜体加粗部分）：
- "c<em><strong>uaieuo</strong></em>uac"
- "c<em><strong>uaieuou</strong></em>ac"
- "c<em><strong>uaieuoua</strong></em>c"
- "cu<em><strong>aieuo</strong></em>uac"
- "cu<em><strong>aieuou</strong></em>ac"
- "cu<em><strong>aieuoua</strong></em>c"
- "cua<em><strong>ieuoua</strong></em>c"</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>word = "bbaeixoubb"
<strong>输出：</strong>0
<strong>解释：</strong>所有包含全部五种元音的子字符串都含有辅音，所以不存在元音子字符串。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 100</code></li>
	<li><code>word</code> 仅由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：暴力枚举 + 哈希表

我们可以枚举子字符串的左端点 $i$，对于当前左端点，维护一个哈希表，记录当前子字符串中出现的元音字母，然后枚举右端点 $j$，如果当前右端点对应的字母不是元音字母，则跳出循环，否则将当前右端点对应的字母加入哈希表，如果哈希表中的元素个数为 $5$，则说明当前子字符串是一个元音子字符串，将结果加 $1$。

时间复杂度 $O(n^2)$，空间复杂度 $O(C)$。其中 $n$ 为字符串 $word$ 的长度；而 $C$ 为字符集大小，本题中 $C=5$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countVowelSubstrings(self, word: str) -> int:
        s = set("aeiou")
        ans, n = 0, len(word)
        for i in range(n):
            t = set()
            for c in word[i:]:
                if c not in s:
                    break
                t.add(c)
                ans += len(t) == 5
        return ans
```

#### Java

```java
class Solution {
    public int countVowelSubstrings(String word) {
        int n = word.length();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            Set<Character> t = new HashSet<>();
            for (int j = i; j < n; ++j) {
                char c = word.charAt(j);
                if (!isVowel(c)) {
                    break;
                }
                t.add(c);
                if (t.size() == 5) {
                    ++ans;
                }
            }
        }
        return ans;
    }

    private boolean isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countVowelSubstrings(string word) {
        int ans = 0;
        int n = word.size();
        for (int i = 0; i < n; ++i) {
            unordered_set<char> t;
            for (int j = i; j < n; ++j) {
                char c = word[j];
                if (!isVowel(c)) break;
                t.insert(c);
                ans += t.size() == 5;
            }
        }
        return ans;
    }

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};
```

#### Go

```go
func countVowelSubstrings(word string) int {
	ans, n := 0, len(word)
	for i := range word {
		t := map[byte]bool{}
		for j := i; j < n; j++ {
			c := word[j]
			if !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
				break
			}
			t[c] = true
			if len(t) == 5 {
				ans++
			}
		}
	}
	return ans
}
```

#### TypeScript

```ts
function countVowelSubstrings(word: string): number {
    let ans = 0;
    const n = word.length;
    for (let i = 0; i < n; ++i) {
        const t = new Set<string>();
        for (let j = i; j < n; ++j) {
            const c = word[j];
            if (!(c === 'a' || c === 'e' || c === 'i' || c === 'o' || c === 'u')) {
                break;
            }
            t.add(c);
            if (t.size === 5) {
                ans++;
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

# [2063. 所有子字符串中的元音](https://leetcode.cn/problems/vowels-of-all-substrings){#2063}

{{< tabs "2063" >}}

{{% tab "python" %}}
```python
class Solution:
    def countVowels(self, word: str) -> int:
        n = len(word)
        return sum((i + 1) * (n - i) for i, c in enumerate(word) if c in 'aeiou')
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long countVowels(String word) {
        long ans = 0;
        for (int i = 0, n = word.length(); i < n; ++i) {
            char c = word.charAt(i);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                ans += (i + 1L) * (n - i);
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
    long long countVowels(string word) {
        long long ans = 0;
        for (int i = 0, n = word.size(); i < n; ++i) {
            char c = word[i];
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                ans += (i + 1LL) * (n - i);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countVowels(word string) (ans int64) {
	for i, c := range word {
		if c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' {
			ans += int64((i + 1) * (len(word) - i))
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countVowels(word: string): number {
    const n = word.length;
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        if (['a', 'e', 'i', 'o', 'u'].includes(word[i])) {
            ans += (i + 1) * (n - i);
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn count_vowels(word: String) -> i64 {
        let n = word.len() as i64;
        word.chars()
            .enumerate()
            .filter(|(_, c)| "aeiou".contains(*c))
            .map(|(i, _)| (i as i64 + 1) * (n - i as i64))
            .sum()
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} word
 * @return {number}
 */
var countVowels = function (word) {
    const n = word.length;
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        if (['a', 'e', 'i', 'o', 'u'].includes(word[i])) {
            ans += (i + 1) * (n - i);
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

<p>给你一个字符串 <code>word</code> ，返回 <code>word</code> 的所有子字符串中 <strong>元音的总数</strong> ，元音是指 <code>'a'</code>、<code>'e'</code><em>、</em><code>'i'</code><em>、</em><code>'o'</code><em> </em>和 <code>'u'</code><em> 。</em></p>

<p><strong>子字符串</strong> 是字符串中一个连续（非空）的字符序列。</p>

<p><strong>注意：</strong>由于对 <code>word</code> 长度的限制比较宽松，答案可能超过有符号 32 位整数的范围。计算时需当心。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>word = "aba"
<strong>输出：</strong>6
<strong>解释：</strong>
所有子字符串是："a"、"ab"、"aba"、"b"、"ba" 和 "a" 。
- "b" 中有 0 个元音
- "a"、"ab"、"ba" 和 "a" 每个都有 1 个元音
- "aba" 中有 2 个元音
因此，元音总数 = 0 + 1 + 1 + 1 + 1 + 2 = 6 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>word = "abc"
<strong>输出：</strong>3
<strong>解释：</strong>
所有子字符串是："a"、"ab"、"abc"、"b"、"bc" 和 "c" 。
- "a"、"ab" 和 "abc" 每个都有 1 个元音
- "b"、"bc" 和 "c" 每个都有 0 个元音
因此，元音总数 = 1 + 1 + 1 + 0 + 0 + 0 = 3 。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>word = "ltcd"
<strong>输出：</strong>0
<strong>解释：</strong>"ltcd" 的子字符串均不含元音。</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>word = "noosabasboosa"
<strong>输出：</strong>237
<strong>解释：</strong>所有子字符串中共有 237 个元音。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 10<sup>5</sup></code></li>
	<li><code>word</code> 由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举贡献

我们可以枚举字符串的每个字符 $\textit{word}[i]$，如果 $\textit{word}[i]$ 是元音字母，那么 $\textit{word}[i]$ 一共在 $(i + 1) \times (n - i)$ 个子字符串中出现，将这些子字符串的个数累加即可。

时间复杂度 $O(n)$，其中 $n$ 为字符串 $\textit{word}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countVowels(self, word: str) -> int:
        n = len(word)
        return sum((i + 1) * (n - i) for i, c in enumerate(word) if c in 'aeiou')
```

#### Java

```java
class Solution {
    public long countVowels(String word) {
        long ans = 0;
        for (int i = 0, n = word.length(); i < n; ++i) {
            char c = word.charAt(i);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                ans += (i + 1L) * (n - i);
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
    long long countVowels(string word) {
        long long ans = 0;
        for (int i = 0, n = word.size(); i < n; ++i) {
            char c = word[i];
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                ans += (i + 1LL) * (n - i);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func countVowels(word string) (ans int64) {
	for i, c := range word {
		if c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' {
			ans += int64((i + 1) * (len(word) - i))
		}
	}
	return
}
```

#### TypeScript

```ts
function countVowels(word: string): number {
    const n = word.length;
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        if (['a', 'e', 'i', 'o', 'u'].includes(word[i])) {
            ans += (i + 1) * (n - i);
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn count_vowels(word: String) -> i64 {
        let n = word.len() as i64;
        word.chars()
            .enumerate()
            .filter(|(_, c)| "aeiou".contains(*c))
            .map(|(i, _)| (i as i64 + 1) * (n - i as i64))
            .sum()
    }
}
```

#### JavaScript

```js
/**
 * @param {string} word
 * @return {number}
 */
var countVowels = function (word) {
    const n = word.length;
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        if (['a', 'e', 'i', 'o', 'u'].includes(word[i])) {
            ans += (i + 1) * (n - i);
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

# [2064. 分配给商店的最多商品的最小值](https://leetcode.cn/problems/minimized-maximum-of-products-distributed-to-any-store){#2064}

{{< tabs "2064" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimizedMaximum(self, n: int, quantities: List[int]) -> int:
        def check(x):
            return sum((v + x - 1) // x for v in quantities) <= n

        return 1 + bisect_left(range(1, 10**6), True, key=check)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimizedMaximum(int n, int[] quantities) {
        int left = 1, right = (int) 1e5;
        while (left < right) {
            int mid = (left + right) >> 1;
            int cnt = 0;
            for (int v : quantities) {
                cnt += (v + mid - 1) / mid;
            }
            if (cnt <= n) {
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
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1, right = 1e5;
        while (left < right) {
            int mid = (left + right) >> 1;
            int cnt = 0;
            for (int& v : quantities) {
                cnt += (v + mid - 1) / mid;
            }
            if (cnt <= n) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimizedMaximum(n int, quantities []int) int {
	return 1 + sort.Search(1e5, func(x int) bool {
		x++
		cnt := 0
		for _, v := range quantities {
			cnt += (v + x - 1) / x
		}
		return cnt <= n
	})
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimizedMaximum(n: number, quantities: number[]): number {
    let left = 1;
    let right = 1e5;
    while (left < right) {
        const mid = (left + right) >> 1;
        let cnt = 0;
        for (const v of quantities) {
            cnt += Math.ceil(v / mid);
        }
        if (cnt <= n) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数&nbsp;<code>n</code>&nbsp;，表示有&nbsp;<code>n</code>&nbsp;间零售商店。总共有&nbsp;<code>m</code>&nbsp;种产品，每种产品的数目用一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>quantities</code>&nbsp;表示，其中&nbsp;<code>quantities[i]</code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;种商品的数目。</p>

<p>你需要将 <strong>所有商品</strong>&nbsp;分配到零售商店，并遵守这些规则：</p>

<ul>
	<li>一间商店 <strong>至多</strong>&nbsp;只能有 <strong>一种商品</strong> ，但一间商店拥有的商品数目可以为&nbsp;<strong>任意</strong>&nbsp;件。</li>
	<li>分配后，每间商店都会被分配一定数目的商品（可能为 <code>0</code>&nbsp;件）。用&nbsp;<code>x</code>&nbsp;表示所有商店中分配商品数目的最大值，你希望 <code>x</code>&nbsp;越小越好。也就是说，你想 <strong>最小化</strong>&nbsp;分配给任意商店商品数目的 <strong>最大值</strong>&nbsp;。</li>
</ul>

<p>请你返回最小的可能的&nbsp;<code>x</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>n = 6, quantities = [11,6]
<b>输出：</b>3
<strong>解释： </strong>一种最优方案为：
- 11 件种类为 0 的商品被分配到前 4 间商店，分配数目分别为：2，3，3，3 。
- 6 件种类为 1 的商品被分配到另外 2 间商店，分配数目分别为：3，3 。
分配给所有商店的最大商品数目为 max(2, 3, 3, 3, 3, 3) = 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>n = 7, quantities = [15,10,10]
<b>输出：</b>5
<b>解释：</b>一种最优方案为：
- 15 件种类为 0 的商品被分配到前 3 间商店，分配数目为：5，5，5 。
- 10 件种类为 1 的商品被分配到接下来 2 间商店，数目为：5，5 。
- 10 件种类为 2 的商品被分配到最后 2 间商店，数目为：5，5 。
分配给所有商店的最大商品数目为 max(5, 5, 5, 5, 5, 5, 5) = 5 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>n = 1, quantities = [100000]
<b>输出：</b>100000
<b>解释：</b>唯一一种最优方案为：
- 所有 100000 件商品 0 都分配到唯一的商店中。
分配给所有商店的最大商品数目为 max(100000) = 100000 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == quantities.length</code></li>
	<li><code>1 &lt;= m &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= quantities[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

我们注意到，如果分配给任意商店商品数目的最大值为 $x$，且满足题目要求，那么 $x+1$ 也一定满足题目要求，这存在着单调性。因此我们可以通过二分查找，找到一个最小的 $x$，使得 $x$ 满足题目要求。

我们定义二分查找的左边界 $left=1$，右边界 $right=10^5$。对于二分查找的每一步，我们取中间值 $mid$，判断是否存在一个分配方案，使得分配给任意商店商品数目的最大值为 $mid$，如果存在，那么我们将右边界 $right$ 移动到 $mid$，否则将左边界 $left$ 移动到 $mid+1$。

二分查找结束后，答案即为 $left$。

时间复杂度 $O(m \times \log M)$，空间复杂度 $O(1)$。其中 $m$ 为商品种类数，而 $M$ 为商品数目的最大值，本题中 $M \leq 10^5$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimizedMaximum(self, n: int, quantities: List[int]) -> int:
        def check(x):
            return sum((v + x - 1) // x for v in quantities) <= n

        return 1 + bisect_left(range(1, 10**6), True, key=check)
```

#### Java

```java
class Solution {
    public int minimizedMaximum(int n, int[] quantities) {
        int left = 1, right = (int) 1e5;
        while (left < right) {
            int mid = (left + right) >> 1;
            int cnt = 0;
            for (int v : quantities) {
                cnt += (v + mid - 1) / mid;
            }
            if (cnt <= n) {
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
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1, right = 1e5;
        while (left < right) {
            int mid = (left + right) >> 1;
            int cnt = 0;
            for (int& v : quantities) {
                cnt += (v + mid - 1) / mid;
            }
            if (cnt <= n) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
```

#### Go

```go
func minimizedMaximum(n int, quantities []int) int {
	return 1 + sort.Search(1e5, func(x int) bool {
		x++
		cnt := 0
		for _, v := range quantities {
			cnt += (v + x - 1) / x
		}
		return cnt <= n
	})
}
```

#### TypeScript

```ts
function minimizedMaximum(n: number, quantities: number[]): number {
    let left = 1;
    let right = 1e5;
    while (left < right) {
        const mid = (left + right) >> 1;
        let cnt = 0;
        for (const v of quantities) {
            cnt += Math.ceil(v / mid);
        }
        if (cnt <= n) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2065. 最大化一张图中的路径价值](https://leetcode.cn/problems/maximum-path-quality-of-a-graph){#2065}

{{< tabs "2065" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximalPathQuality(
        self, values: List[int], edges: List[List[int]], maxTime: int
    ) -> int:
        def dfs(u: int, cost: int, value: int):
            if u == 0:
                nonlocal ans
                ans = max(ans, value)
            for v, t in g[u]:
                if cost + t <= maxTime:
                    if vis[v]:
                        dfs(v, cost + t, value)
                    else:
                        vis[v] = True
                        dfs(v, cost + t, value + values[v])
                        vis[v] = False

        n = len(values)
        g = [[] for _ in range(n)]
        for u, v, t in edges:
            g[u].append((v, t))
            g[v].append((u, t))
        vis = [False] * n
        vis[0] = True
        ans = 0
        dfs(0, 0, values[0])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private List<int[]>[] g;
    private boolean[] vis;
    private int[] values;
    private int maxTime;
    private int ans;

    public int maximalPathQuality(int[] values, int[][] edges, int maxTime) {
        int n = values.length;
        g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : edges) {
            int u = e[0], v = e[1], t = e[2];
            g[u].add(new int[] {v, t});
            g[v].add(new int[] {u, t});
        }
        vis = new boolean[n];
        vis[0] = true;
        this.values = values;
        this.maxTime = maxTime;
        dfs(0, 0, values[0]);
        return ans;
    }

    private void dfs(int u, int cost, int value) {
        if (u == 0) {
            ans = Math.max(ans, value);
        }
        for (var e : g[u]) {
            int v = e[0], t = e[1];
            if (cost + t <= maxTime) {
                if (vis[v]) {
                    dfs(v, cost + t, value);
                } else {
                    vis[v] = true;
                    dfs(v, cost + t, value + values[v]);
                    vis[v] = false;
                }
            }
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        vector<pair<int, int>> g[n];
        for (auto& e : edges) {
            int u = e[0], v = e[1], t = e[2];
            g[u].emplace_back(v, t);
            g[v].emplace_back(u, t);
        }
        bool vis[n];
        memset(vis, false, sizeof(vis));
        vis[0] = true;
        int ans = 0;
        auto dfs = [&](this auto&& dfs, int u, int cost, int value) -> void {
            if (u == 0) {
                ans = max(ans, value);
            }
            for (auto& [v, t] : g[u]) {
                if (cost + t <= maxTime) {
                    if (vis[v]) {
                        dfs(v, cost + t, value);
                    } else {
                        vis[v] = true;
                        dfs(v, cost + t, value + values[v]);
                        vis[v] = false;
                    }
                }
            }
        };
        dfs(0, 0, values[0]);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximalPathQuality(values []int, edges [][]int, maxTime int) (ans int) {
	n := len(values)
	g := make([][][2]int, n)
	for _, e := range edges {
		u, v, t := e[0], e[1], e[2]
		g[u] = append(g[u], [2]int{v, t})
		g[v] = append(g[v], [2]int{u, t})
	}
	vis := make([]bool, n)
	vis[0] = true
	var dfs func(u, cost, value int)
	dfs = func(u, cost, value int) {
		if u == 0 {
			ans = max(ans, value)
		}
		for _, e := range g[u] {
			v, t := e[0], e[1]
			if cost+t <= maxTime {
				if vis[v] {
					dfs(v, cost+t, value)
				} else {
					vis[v] = true
					dfs(v, cost+t, value+values[v])
					vis[v] = false
				}
			}
		}
	}
	dfs(0, 0, values[0])
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximalPathQuality(values: number[], edges: number[][], maxTime: number): number {
    const n = values.length;
    const g: [number, number][][] = Array.from({ length: n }, () => []);
    for (const [u, v, t] of edges) {
        g[u].push([v, t]);
        g[v].push([u, t]);
    }
    const vis: boolean[] = Array(n).fill(false);
    vis[0] = true;
    let ans = 0;
    const dfs = (u: number, cost: number, value: number) => {
        if (u === 0) {
            ans = Math.max(ans, value);
        }
        for (const [v, t] of g[u]) {
            if (cost + t <= maxTime) {
                if (vis[v]) {
                    dfs(v, cost + t, value);
                } else {
                    vis[v] = true;
                    dfs(v, cost + t, value + values[v]);
                    vis[v] = false;
                }
            }
        }
    };
    dfs(0, 0, values[0]);
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一张 <strong>无向</strong>&nbsp;图，图中有 <code>n</code>&nbsp;个节点，节点编号从 <code>0</code>&nbsp;到 <code>n - 1</code>&nbsp;（<strong>都包括</strong>）。同时给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>values</code>&nbsp;，其中&nbsp;<code>values[i]</code>&nbsp;是第 <code>i</code>&nbsp;个节点的 <strong>价值</strong>&nbsp;。同时给你一个下标从 <strong>0</strong>&nbsp;开始的二维整数数组&nbsp;<code>edges</code>&nbsp;，其中&nbsp;<code>edges[j] = [u<sub>j</sub>, v<sub>j</sub>, time<sub>j</sub>]</code>&nbsp;表示节点&nbsp;<code>u<sub>j</sub></code> 和&nbsp;<code>v<sub>j</sub></code>&nbsp;之间有一条需要&nbsp;<code>time<sub>j</sub></code>&nbsp;秒才能通过的无向边。最后，给你一个整数&nbsp;<code>maxTime</code>&nbsp;。</p>

<p><strong>合法路径</strong>&nbsp;指的是图中任意一条从节点&nbsp;<code>0</code>&nbsp;开始，最终回到节点 <code>0</code>&nbsp;，且花费的总时间 <strong>不超过</strong>&nbsp;<code>maxTime</code> 秒的一条路径。你可以访问一个节点任意次。一条合法路径的 <b>价值</b>&nbsp;定义为路径中 <strong>不同节点</strong>&nbsp;的价值 <strong>之和</strong>&nbsp;（每个节点的价值 <strong>至多</strong>&nbsp;算入价值总和中一次）。</p>

<p>请你返回一条合法路径的 <strong>最大</strong>&nbsp;价值。</p>

<p><strong>注意：</strong>每个节点 <strong>至多</strong>&nbsp;有 <strong>四条</strong>&nbsp;边与之相连。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2065.Maximum%20Path%20Quality%20of%20a%20Graph/images/ex1drawio.png" style="width: 269px; height: 170px;" /></p>

<pre>
<b>输入：</b>values = [0,32,10,43], edges = [[0,1,10],[1,2,15],[0,3,10]], maxTime = 49
<b>输出：</b>75
<strong>解释：</strong>
一条可能的路径为：0 -&gt; 1 -&gt; 0 -&gt; 3 -&gt; 0 。总花费时间为 10 + 10 + 10 + 10 = 40 &lt;= 49 。
访问过的节点为 0 ，1 和 3 ，最大路径价值为 0 + 32 + 43 = 75 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2065.Maximum%20Path%20Quality%20of%20a%20Graph/images/ex2drawio.png" style="width: 269px; height: 170px;" /></p>

<pre>
<b>输入：</b>values = [5,10,15,20], edges = [[0,1,10],[1,2,10],[0,3,10]], maxTime = 30
<b>输出：</b>25
<strong>解释：</strong>
一条可能的路径为：0 -&gt; 3 -&gt; 0 。总花费时间为 10 + 10 = 20 &lt;= 30 。
访问过的节点为 0 和 3 ，最大路径价值为 5 + 20 = 25 。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2065.Maximum%20Path%20Quality%20of%20a%20Graph/images/ex31drawio.png" style="width: 236px; height: 170px;" /></p>

<pre>
<b>输入：</b>values = [1,2,3,4], edges = [[0,1,10],[1,2,11],[2,3,12],[1,3,13]], maxTime = 50
<b>输出：</b>7
<strong>解释：</strong>
一条可能的路径为：0 -&gt; 1 -&gt; 3 -&gt; 1 -&gt; 0 。总花费时间为 10 + 13 + 13 + 10 = 46 &lt;= 50 。
访问过的节点为 0 ，1 和 3 ，最大路径价值为 1 + 2 + 4 = 7 。</pre>

<p><strong>示例 4：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2065.Maximum%20Path%20Quality%20of%20a%20Graph/images/ex4drawio.png" style="width: 270px; height: 71px;" /></strong></p>

<pre>
<b>输入：</b>values = [0,1,2], edges = [[1,2,10]], maxTime = 10
<b>输出：</b>0
<b>解释：</b>
唯一一条路径为 0 。总花费时间为 0 。
唯一访问过的节点为 0 ，最大路径价值为 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == values.length</code></li>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
	<li><code>0 &lt;= values[i] &lt;= 10<sup>8</sup></code></li>
	<li><code>0 &lt;= edges.length &lt;= 2000</code></li>
	<li><code>edges[j].length == 3 </code></li>
	<li><code>0 &lt;= u<sub>j </sub>&lt; v<sub>j</sub> &lt;= n - 1</code></li>
	<li><code>10 &lt;= time<sub>j</sub>, maxTime &lt;= 100</code></li>
	<li><code>[u<sub>j</sub>, v<sub>j</sub>]</code>&nbsp;所有节点对 <strong>互不相同</strong>&nbsp;。</li>
	<li>每个节点 <strong>至多有四条&nbsp;</strong>边。</li>
	<li>图可能不连通。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们观察题目的数据范围，可以发现从 $0$ 开始的每条合法路径的边数不超过 $\frac{\textit{maxTime}}{\min(time_j)} = \frac{100}{10} = 10$ 条，并且每个节点至多有四条边，所以我们可以直接使用朴素的 DFS 暴力搜索所有合法路径。

我们先将图的边存储在邻接表表 $g$ 中，然后我们设计一个函数 $\textit{dfs}(u, \textit{cost}, \textit{value})$，其中 $u$ 表示当前节点编号，而 $\textit{cost}$ 和 $\textit{value}$ 分别表示当前路径的花费时间和价值。另外，使用一个长度为 $n$ 的数组 $\textit{vis}$ 记录每个节点是否被访问过。初始时，我们将节点 $0$ 标记为已访问。

函数 $\textit{dfs}(u, \textit{cost}, \textit{value})$ 的逻辑如下：

-   如果当前节点编号 $u$ 等于 $0$，表示我们已经回到了起点，那么我们更新答案为 $\max(\textit{ans}, \textit{value})$；
-   遍历当前节点 $u$ 的所有邻居节点 $v$，如果当前路径的花费时间加上边 $(u, v)$ 的时间 $t$ 不超过 $\textit{maxTime}$，那么我们可以选择继续访问节点 $v$；
    -   如果节点 $v$ 已经被访问过，那么我们直接递归调用 $\textit{dfs}(v, \textit{cost} + t, \textit{value})$；
    -   如果节点 $v$ 没有被访问过，我们标记节点 $v$ 为已访问，然后递归调用 $\textit{dfs}(v, \textit{cost} + t, \textit{value} + \textit{values}[v])$，最后恢复节点 $v$ 的访问状态。

在主函数中，我们调用 $\textit{dfs}(0, 0, \textit{values}[0])$，并返回答案 $\textit{ans}$ 即可。

时间复杂度 $O(n + m + 4^{\frac{\textit{maxTime}}{\min(time_j)}})$，空间复杂度 $O(n + m + \frac{\textit{maxTime}}{\min(time_j)})$。其中 $n$ 和 $m$ 分别表示节点数和边数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximalPathQuality(
        self, values: List[int], edges: List[List[int]], maxTime: int
    ) -> int:
        def dfs(u: int, cost: int, value: int):
            if u == 0:
                nonlocal ans
                ans = max(ans, value)
            for v, t in g[u]:
                if cost + t <= maxTime:
                    if vis[v]:
                        dfs(v, cost + t, value)
                    else:
                        vis[v] = True
                        dfs(v, cost + t, value + values[v])
                        vis[v] = False

        n = len(values)
        g = [[] for _ in range(n)]
        for u, v, t in edges:
            g[u].append((v, t))
            g[v].append((u, t))
        vis = [False] * n
        vis[0] = True
        ans = 0
        dfs(0, 0, values[0])
        return ans
```

#### Java

```java
class Solution {
    private List<int[]>[] g;
    private boolean[] vis;
    private int[] values;
    private int maxTime;
    private int ans;

    public int maximalPathQuality(int[] values, int[][] edges, int maxTime) {
        int n = values.length;
        g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : edges) {
            int u = e[0], v = e[1], t = e[2];
            g[u].add(new int[] {v, t});
            g[v].add(new int[] {u, t});
        }
        vis = new boolean[n];
        vis[0] = true;
        this.values = values;
        this.maxTime = maxTime;
        dfs(0, 0, values[0]);
        return ans;
    }

    private void dfs(int u, int cost, int value) {
        if (u == 0) {
            ans = Math.max(ans, value);
        }
        for (var e : g[u]) {
            int v = e[0], t = e[1];
            if (cost + t <= maxTime) {
                if (vis[v]) {
                    dfs(v, cost + t, value);
                } else {
                    vis[v] = true;
                    dfs(v, cost + t, value + values[v]);
                    vis[v] = false;
                }
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        vector<pair<int, int>> g[n];
        for (auto& e : edges) {
            int u = e[0], v = e[1], t = e[2];
            g[u].emplace_back(v, t);
            g[v].emplace_back(u, t);
        }
        bool vis[n];
        memset(vis, false, sizeof(vis));
        vis[0] = true;
        int ans = 0;
        auto dfs = [&](this auto&& dfs, int u, int cost, int value) -> void {
            if (u == 0) {
                ans = max(ans, value);
            }
            for (auto& [v, t] : g[u]) {
                if (cost + t <= maxTime) {
                    if (vis[v]) {
                        dfs(v, cost + t, value);
                    } else {
                        vis[v] = true;
                        dfs(v, cost + t, value + values[v]);
                        vis[v] = false;
                    }
                }
            }
        };
        dfs(0, 0, values[0]);
        return ans;
    }
};
```

#### Go

```go
func maximalPathQuality(values []int, edges [][]int, maxTime int) (ans int) {
	n := len(values)
	g := make([][][2]int, n)
	for _, e := range edges {
		u, v, t := e[0], e[1], e[2]
		g[u] = append(g[u], [2]int{v, t})
		g[v] = append(g[v], [2]int{u, t})
	}
	vis := make([]bool, n)
	vis[0] = true
	var dfs func(u, cost, value int)
	dfs = func(u, cost, value int) {
		if u == 0 {
			ans = max(ans, value)
		}
		for _, e := range g[u] {
			v, t := e[0], e[1]
			if cost+t <= maxTime {
				if vis[v] {
					dfs(v, cost+t, value)
				} else {
					vis[v] = true
					dfs(v, cost+t, value+values[v])
					vis[v] = false
				}
			}
		}
	}
	dfs(0, 0, values[0])
	return
}
```

#### TypeScript

```ts
function maximalPathQuality(values: number[], edges: number[][], maxTime: number): number {
    const n = values.length;
    const g: [number, number][][] = Array.from({ length: n }, () => []);
    for (const [u, v, t] of edges) {
        g[u].push([v, t]);
        g[v].push([u, t]);
    }
    const vis: boolean[] = Array(n).fill(false);
    vis[0] = true;
    let ans = 0;
    const dfs = (u: number, cost: number, value: number) => {
        if (u === 0) {
            ans = Math.max(ans, value);
        }
        for (const [v, t] of g[u]) {
            if (cost + t <= maxTime) {
                if (vis[v]) {
                    dfs(v, cost + t, value);
                } else {
                    vis[v] = true;
                    dfs(v, cost + t, value + values[v]);
                    vis[v] = false;
                }
            }
        }
    };
    dfs(0, 0, values[0]);
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2066. 账户余额 🔒](https://leetcode.cn/problems/account-balance){#2066}

{{< tabs "2066" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    account_id,
    day,
    SUM(IF(type = 'Deposit', amount, -amount)) OVER (
        PARTITION BY account_id
        ORDER BY day
    ) AS balance
FROM Transactions
ORDER BY 1, 2;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表名: <code>Transactions</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| account_id  | int  |
| day         | date |
| type        | ENUM |
| amount      | int  |
+-------------+------+
(account_id, day) 是该Transactions表的主键.
表中的每行数据表示一次交易的信息, 包括此次交易的账号(account_id), 交易类型(type), 交易发生时间(day), 交易发生金额(amount).
其中交易类型(type)字段包括了两种行为：存入 ('Deposit'), 取出('Withdraw').
</pre>

<p>&nbsp;</p>

<p>请写出能够返回用户每次交易完成后的账户余额. 我们约定所有用户在进行交易前的账户余额都为0，&nbsp;并且保证所有交易行为后的余额不为负数。</p>

<p>返回的结果请依次按照 账户（<code>account_id</code>),&nbsp;日期(&nbsp;<code>day</code>&nbsp;) 进行<strong>升序排序</strong>&nbsp;.</p>

<p>查询结果的格式请参照以下测试样例.</p>

<p>&nbsp;</p>

<p><strong>测试样例1:</strong></p>

<pre>
<strong>输入:</strong> 
Transactions 表:
+------------+------------+----------+--------+
| account_id | day        | type     | amount |
+------------+------------+----------+--------+
| 1          | 2021-11-07 | Deposit  | 2000   |
| 1          | 2021-11-09 | Withdraw | 1000   |
| 1          | 2021-11-11 | Deposit  | 3000   |
| 2          | 2021-12-07 | Deposit  | 7000   |
| 2          | 2021-12-12 | Withdraw | 7000   |
+------------+------------+----------+--------+
<strong>输出:</strong> 
+------------+------------+---------+
| account_id | day        | balance |
+------------+------------+---------+
| 1          | 2021-11-07 | 2000    |
| 1          | 2021-11-09 | 1000    |
| 1          | 2021-11-11 | 4000    |
| 2          | 2021-12-07 | 7000    |
| 2          | 2021-12-12 | 0       |
+------------+------------+---------+

<strong>解释:</strong> 
账户1:
- 初始金额为 0.
- 2021-11-07 --&gt; 存入2000. 余额变为 0 + 2000 = 2000.
- 2021-11-09 --&gt; 取出1000. 余额变为 2000 - 1000 = 1000.
- 2021-11-11 --&gt; 存入3000. 余额变为 1000 + 3000 = 4000.
账户2:
- 初始金额为 0.
- 2021-12-07 --&gt; 存入7000. 余额变为 0 + 7000 = 7000.
- 2021-12-12 --&gt; 取出 7000. 余额变为 7000 - 7000 = 0.
</pre>

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
SELECT
    account_id,
    day,
    SUM(IF(type = 'Deposit', amount, -amount)) OVER (
        PARTITION BY account_id
        ORDER BY day
    ) AS balance
FROM Transactions
ORDER BY 1, 2;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2067. 等计数子串的数量 🔒](https://leetcode.cn/problems/number-of-equal-count-substrings){#2067}

{{< tabs "2067" >}}

{{% tab "python" %}}
```python
class Solution:
    def equalCountSubstrings(self, s: str, count: int) -> int:
        ans = 0
        for i in range(1, 27):
            k = i * count
            if k > len(s):
                break
            cnt = Counter()
            t = 0
            for j, c in enumerate(s):
                cnt[c] += 1
                t += cnt[c] == count
                t -= cnt[c] == count + 1
                if j >= k:
                    cnt[s[j - k]] -= 1
                    t += cnt[s[j - k]] == count
                    t -= cnt[s[j - k]] == count - 1
                ans += i == t
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int equalCountSubstrings(String s, int count) {
        int ans = 0;
        int[] cnt = new int[26];
        int n = s.length();
        for (int i = 1; i < 27 && i * count <= n; ++i) {
            int k = i * count;
            Arrays.fill(cnt, 0);
            int t = 0;
            for (int j = 0; j < n; ++j) {
                int a = s.charAt(j) - 'a';
                ++cnt[a];
                t += cnt[a] == count ? 1 : 0;
                t -= cnt[a] == count + 1 ? 1 : 0;
                if (j - k >= 0) {
                    int b = s.charAt(j - k) - 'a';
                    --cnt[b];
                    t += cnt[b] == count ? 1 : 0;
                    t -= cnt[b] == count - 1 ? 1 : 0;
                }
                ans += i == t ? 1 : 0;
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
    int equalCountSubstrings(string s, int count) {
        int ans = 0;
        int n = s.size();
        int cnt[26];
        for (int i = 1; i < 27 && i * count <= n; ++i) {
            int k = i * count;
            memset(cnt, 0, sizeof(cnt));
            int t = 0;
            for (int j = 0; j < n; ++j) {
                int a = s[j] - 'a';
                t += ++cnt[a] == count;
                t -= cnt[a] == count + 1;
                if (j >= k) {
                    int b = s[j - k] - 'a';
                    t += --cnt[b] == count;
                    t -= cnt[b] == count - 1;
                }
                ans += i == t;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func equalCountSubstrings(s string, count int) (ans int) {
	n := len(s)
	for i := 1; i < 27 && i*count <= n; i++ {
		k := i * count
		cnt := [26]int{}
		t := 0
		for j, c := range s {
			a := c - 'a'
			cnt[a]++
			if cnt[a] == count {
				t++
			} else if cnt[a] == count+1 {
				t--
			}
			if j >= k {
				b := s[j-k] - 'a'
				cnt[b]--
				if cnt[b] == count {
					t++
				} else if cnt[b] == count-1 {
					t--
				}
			}
			if i == t {
				ans++
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function equalCountSubstrings(s: string, count: number): number {
    const n = s.length;
    let ans = 0;
    for (let i = 1; i < 27 && i * count <= n; ++i) {
        const k = i * count;
        const cnt: number[] = Array(26).fill(0);
        let t = 0;
        for (let j = 0; j < n; ++j) {
            const a = s.charCodeAt(j) - 97;
            t += ++cnt[a] === count ? 1 : 0;
            t -= cnt[a] === count + 1 ? 1 : 0;
            if (j >= k) {
                const b = s.charCodeAt(j - k) - 97;
                t += --cnt[b] === count ? 1 : 0;
                t -= cnt[b] === count - 1 ? 1 : 0;
            }
            ans += i === t ? 1 : 0;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} s
 * @param {number} count
 * @return {number}
 */
var equalCountSubstrings = function (s, count) {
    const n = s.length;
    let ans = 0;
    for (let i = 1; i < 27 && i * count <= n; ++i) {
        const k = i * count;
        const cnt = Array(26).fill(0);
        let t = 0;
        for (let j = 0; j < n; ++j) {
            const a = s.charCodeAt(j) - 97;
            t += ++cnt[a] === count ? 1 : 0;
            t -= cnt[a] === count + 1 ? 1 : 0;
            if (j >= k) {
                const b = s.charCodeAt(j - k) - 97;
                t += --cnt[b] === count ? 1 : 0;
                t -= cnt[b] === count - 1 ? 1 : 0;
            }
            ans += i === t ? 1 : 0;
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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的字符串 <code>s</code>，只包含小写英文字母和一个整数 <code>count</code>。如果&nbsp;<code>s</code>&nbsp;的&nbsp;<strong>子串 </strong>中的每种字母在子串中恰好出现 <code>count</code> 次，这个子串就被称为&nbsp;<strong>等计数子串</strong>。</p>

<p>返回<em> <code>s</code> 中&nbsp;<strong>等计数子串&nbsp;</strong>的个数。</em></p>

<p><strong>子串&nbsp;</strong>是字符串中连续的非空字符序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> s = "aaabcbbcc", count = 3
<strong>输出:</strong> 3
<strong>解释:</strong>
从下标 0 开始到下标 2 结束的子串是 "aaa"。
字母 “a” 在子串中恰好出现了 3 次。
从下标 3 开始到下标 8 结束的子串是 "bcbbcc"。
字母 “b” 和 “c” 在子串中恰好出现了 3 次。
从下标 0 开始到下标 8 结束的子串是 "aaabcbbcc"。
字母 “a”、“b” 和 “c” 在子串中恰好出现了 3 次。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> s = "abcd", count = 2
<strong>输出:</strong> 0
<strong>解释:</strong>
每种字母在 s 中出现的次数小于 count。
因此，s 中没有子串是等计数子串，返回 0。
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> s = "a", count = 5
<strong>输出:</strong> 0
<strong>解释:</strong>
每种字母在 s 中出现的次数小于 count。
因此，s 中没有子串是等计数子串，返回 0。</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= count &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>s</code> 只由小写英文字母组成。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举 + 滑动窗口

我们可以在 $[1..26]$ 范围内枚举子串的字母种类数 $i$，那么子串长度就是 $i \times count$。

接下来，我们将当前子串长度作为窗口的大小，统计窗口大小中有多少种字母的个数为 $count$，记录在 $t$ 中。如果此时 $i = t$，说明当前窗口中的字母个数都为 $count$，那么就可以将答案加一。

时间复杂度 $O(n \times C)$，空间复杂度 $O(C)$。其中 $n$ 为字符串 $s$ 的长度，而 $C$ 为字母的种类数，本题中 $C = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def equalCountSubstrings(self, s: str, count: int) -> int:
        ans = 0
        for i in range(1, 27):
            k = i * count
            if k > len(s):
                break
            cnt = Counter()
            t = 0
            for j, c in enumerate(s):
                cnt[c] += 1
                t += cnt[c] == count
                t -= cnt[c] == count + 1
                if j >= k:
                    cnt[s[j - k]] -= 1
                    t += cnt[s[j - k]] == count
                    t -= cnt[s[j - k]] == count - 1
                ans += i == t
        return ans
```

#### Java

```java
class Solution {
    public int equalCountSubstrings(String s, int count) {
        int ans = 0;
        int[] cnt = new int[26];
        int n = s.length();
        for (int i = 1; i < 27 && i * count <= n; ++i) {
            int k = i * count;
            Arrays.fill(cnt, 0);
            int t = 0;
            for (int j = 0; j < n; ++j) {
                int a = s.charAt(j) - 'a';
                ++cnt[a];
                t += cnt[a] == count ? 1 : 0;
                t -= cnt[a] == count + 1 ? 1 : 0;
                if (j - k >= 0) {
                    int b = s.charAt(j - k) - 'a';
                    --cnt[b];
                    t += cnt[b] == count ? 1 : 0;
                    t -= cnt[b] == count - 1 ? 1 : 0;
                }
                ans += i == t ? 1 : 0;
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
    int equalCountSubstrings(string s, int count) {
        int ans = 0;
        int n = s.size();
        int cnt[26];
        for (int i = 1; i < 27 && i * count <= n; ++i) {
            int k = i * count;
            memset(cnt, 0, sizeof(cnt));
            int t = 0;
            for (int j = 0; j < n; ++j) {
                int a = s[j] - 'a';
                t += ++cnt[a] == count;
                t -= cnt[a] == count + 1;
                if (j >= k) {
                    int b = s[j - k] - 'a';
                    t += --cnt[b] == count;
                    t -= cnt[b] == count - 1;
                }
                ans += i == t;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func equalCountSubstrings(s string, count int) (ans int) {
	n := len(s)
	for i := 1; i < 27 && i*count <= n; i++ {
		k := i * count
		cnt := [26]int{}
		t := 0
		for j, c := range s {
			a := c - 'a'
			cnt[a]++
			if cnt[a] == count {
				t++
			} else if cnt[a] == count+1 {
				t--
			}
			if j >= k {
				b := s[j-k] - 'a'
				cnt[b]--
				if cnt[b] == count {
					t++
				} else if cnt[b] == count-1 {
					t--
				}
			}
			if i == t {
				ans++
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function equalCountSubstrings(s: string, count: number): number {
    const n = s.length;
    let ans = 0;
    for (let i = 1; i < 27 && i * count <= n; ++i) {
        const k = i * count;
        const cnt: number[] = Array(26).fill(0);
        let t = 0;
        for (let j = 0; j < n; ++j) {
            const a = s.charCodeAt(j) - 97;
            t += ++cnt[a] === count ? 1 : 0;
            t -= cnt[a] === count + 1 ? 1 : 0;
            if (j >= k) {
                const b = s.charCodeAt(j - k) - 97;
                t += --cnt[b] === count ? 1 : 0;
                t -= cnt[b] === count - 1 ? 1 : 0;
            }
            ans += i === t ? 1 : 0;
        }
    }
    return ans;
}
```

#### JavaScript

```js
/**
 * @param {string} s
 * @param {number} count
 * @return {number}
 */
var equalCountSubstrings = function (s, count) {
    const n = s.length;
    let ans = 0;
    for (let i = 1; i < 27 && i * count <= n; ++i) {
        const k = i * count;
        const cnt = Array(26).fill(0);
        let t = 0;
        for (let j = 0; j < n; ++j) {
            const a = s.charCodeAt(j) - 97;
            t += ++cnt[a] === count ? 1 : 0;
            t -= cnt[a] === count + 1 ? 1 : 0;
            if (j >= k) {
                const b = s.charCodeAt(j - k) - 97;
                t += --cnt[b] === count ? 1 : 0;
                t -= cnt[b] === count - 1 ? 1 : 0;
            }
            ans += i === t ? 1 : 0;
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

# [2068. 检查两个字符串是否几乎相等](https://leetcode.cn/problems/check-whether-two-strings-are-almost-equivalent){#2068}

{{< tabs "2068" >}}

{{% tab "python" %}}
```python
class Solution:
    def checkAlmostEquivalent(self, word1: str, word2: str) -> bool:
        cnt = Counter(word1)
        for c in word2:
            cnt[c] -= 1
        return all(abs(x) <= 3 for x in cnt.values())
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean checkAlmostEquivalent(String word1, String word2) {
        int[] cnt = new int[26];
        for (int i = 0; i < word1.length(); ++i) {
            ++cnt[word1.charAt(i) - 'a'];
        }
        for (int i = 0; i < word2.length(); ++i) {
            --cnt[word2.charAt(i) - 'a'];
        }
        for (int x : cnt) {
            if (Math.abs(x) > 3) {
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
    bool checkAlmostEquivalent(string word1, string word2) {
        int cnt[26]{};
        for (char& c : word1) {
            ++cnt[c - 'a'];
        }
        for (char& c : word2) {
            --cnt[c - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (abs(cnt[i]) > 3) {
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
func checkAlmostEquivalent(word1 string, word2 string) bool {
	cnt := [26]int{}
	for _, c := range word1 {
		cnt[c-'a']++
	}
	for _, c := range word2 {
		cnt[c-'a']--
	}
	for _, x := range cnt {
		if x > 3 || x < -3 {
			return false
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function checkAlmostEquivalent(word1: string, word2: string): boolean {
    const cnt: number[] = new Array(26).fill(0);
    for (const c of word1) {
        ++cnt[c.charCodeAt(0) - 97];
    }
    for (const c of word2) {
        --cnt[c.charCodeAt(0) - 97];
    }
    return cnt.every(x => Math.abs(x) <= 3);
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} word1
 * @param {string} word2
 * @return {boolean}
 */
var checkAlmostEquivalent = function (word1, word2) {
    const m = new Map();
    for (let i = 0; i < word1.length; i++) {
        m.set(word1[i], (m.get(word1[i]) || 0) + 1);
        m.set(word2[i], (m.get(word2[i]) || 0) - 1);
    }
    for (const v of m.values()) {
        if (Math.abs(v) > 3) {
            return false;
        }
    }
    return true;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public bool CheckAlmostEquivalent(string word1, string word2) {
        int[] cnt = new int[26];
        foreach (var c in word1) {
            cnt[c - 'a']++;
        }
        foreach (var c in word2) {
            cnt[c - 'a']--;
        }
        return cnt.All(x => Math.Abs(x) <= 3);
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param String $word1
     * @param String $word2
     * @return Boolean
     */
    function checkAlmostEquivalent($word1, $word2) {
        for ($i = 0; $i < strlen($word1); $i++) {
            $hashtable[$word1[$i]] += 1;
            $hashtable[$word2[$i]] -= 1;
        }
        $keys = array_keys($hashtable);
        for ($j = 0; $j < count($keys); $j++) {
            if (abs($hashtable[$keys[$j]]) > 3) {
                return false;
            }
        }
        return true;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>如果两个字符串 <code>word1</code>&nbsp;和 <code>word2</code>&nbsp;中从 <code>'a'</code>&nbsp;到 <code>'z'</code>&nbsp;每一个字母出现频率之差都 <strong>不超过</strong>&nbsp;<code>3</code>&nbsp;，那么我们称这两个字符串&nbsp;<code>word1</code> 和&nbsp;<code>word2</code> <strong>几乎相等</strong>&nbsp;。</p>

<p>给你两个长度都为&nbsp;<code>n</code>&nbsp;的字符串&nbsp;<code>word1</code> 和&nbsp;<code>word2</code>&nbsp;，如果&nbsp;<code>word1</code>&nbsp;和&nbsp;<code>word2</code>&nbsp;<strong>几乎相等</strong>&nbsp;，请你返回&nbsp;<code>true</code>&nbsp;，否则返回&nbsp;<code>false</code>&nbsp;。</p>

<p>一个字母 <code>x</code>&nbsp;的出现 <strong>频率</strong>&nbsp;指的是它在字符串中出现的次数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>word1 = "aaaa", word2 = "bccb"
<b>输出：</b>false
<b>解释：</b>字符串 "aaaa" 中有 4 个 'a' ，但是 "bccb" 中有 0 个 'a' 。
两者之差为 4 ，大于上限 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>word1 = "abcdeef", word2 = "abaaacc"
<b>输出：</b>true
<b>解释：</b>word1 和 word2 中每个字母出现频率之差至多为 3 ：
- 'a' 在 word1 中出现了 1 次，在 word2 中出现了 4 次，差为 3 。
- 'b' 在 word1 中出现了 1 次，在 word2 中出现了 1 次，差为 0 。
- 'c' 在 word1 中出现了 1 次，在 word2 中出现了 2 次，差为 1 。
- 'd' 在 word1 中出现了 1 次，在 word2 中出现了 0 次，差为 1 。
- 'e' 在 word1 中出现了 2 次，在 word2 中出现了 0 次，差为 2 。
- 'f' 在 word1 中出现了 1 次，在 word2 中出现了 0 次，差为 1 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>word1 = "cccddabba", word2 = "babababab"
<b>输出：</b>true
<b>解释：</b>word1 和 word2 中每个字母出现频率之差至多为 3 ：
- 'a' 在 word1 中出现了 2 次，在 word2 中出现了 4 次，差为 2 。
- 'b' 在 word1 中出现了 2 次，在 word2 中出现了 5 次，差为 3 。
- 'c' 在 word1 中出现了 3 次，在 word2 中出现了 0 次，差为 3 。
- 'd' 在 word1 中出现了 2 次，在 word2 中出现了 0 次，差为 2 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == word1.length == word2.length</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>word1</code> 和&nbsp;<code>word2</code>&nbsp;都只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们可以创建一个长度为 $26$ 的数组 $cnt$，记录两个字符串中每个字母出现的次数之差。最后遍历 $cnt$，如果有任意一个字母出现的次数之差大于 $3$，则返回 `false`，否则返回 `true`。

时间复杂度 $O(n)$，空间复杂度 $O(C)$。其中 $n$ 是字符串的长度；而 $C$ 是字符集的大小，本题中 $C = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def checkAlmostEquivalent(self, word1: str, word2: str) -> bool:
        cnt = Counter(word1)
        for c in word2:
            cnt[c] -= 1
        return all(abs(x) <= 3 for x in cnt.values())
```

#### Java

```java
class Solution {
    public boolean checkAlmostEquivalent(String word1, String word2) {
        int[] cnt = new int[26];
        for (int i = 0; i < word1.length(); ++i) {
            ++cnt[word1.charAt(i) - 'a'];
        }
        for (int i = 0; i < word2.length(); ++i) {
            --cnt[word2.charAt(i) - 'a'];
        }
        for (int x : cnt) {
            if (Math.abs(x) > 3) {
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
    bool checkAlmostEquivalent(string word1, string word2) {
        int cnt[26]{};
        for (char& c : word1) {
            ++cnt[c - 'a'];
        }
        for (char& c : word2) {
            --cnt[c - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (abs(cnt[i]) > 3) {
                return false;
            }
        }
        return true;
    }
};
```

#### Go

```go
func checkAlmostEquivalent(word1 string, word2 string) bool {
	cnt := [26]int{}
	for _, c := range word1 {
		cnt[c-'a']++
	}
	for _, c := range word2 {
		cnt[c-'a']--
	}
	for _, x := range cnt {
		if x > 3 || x < -3 {
			return false
		}
	}
	return true
}
```

#### TypeScript

```ts
function checkAlmostEquivalent(word1: string, word2: string): boolean {
    const cnt: number[] = new Array(26).fill(0);
    for (const c of word1) {
        ++cnt[c.charCodeAt(0) - 97];
    }
    for (const c of word2) {
        --cnt[c.charCodeAt(0) - 97];
    }
    return cnt.every(x => Math.abs(x) <= 3);
}
```

#### JavaScript

```js
/**
 * @param {string} word1
 * @param {string} word2
 * @return {boolean}
 */
var checkAlmostEquivalent = function (word1, word2) {
    const m = new Map();
    for (let i = 0; i < word1.length; i++) {
        m.set(word1[i], (m.get(word1[i]) || 0) + 1);
        m.set(word2[i], (m.get(word2[i]) || 0) - 1);
    }
    for (const v of m.values()) {
        if (Math.abs(v) > 3) {
            return false;
        }
    }
    return true;
};
```

#### C#

```cs
public class Solution {
    public bool CheckAlmostEquivalent(string word1, string word2) {
        int[] cnt = new int[26];
        foreach (var c in word1) {
            cnt[c - 'a']++;
        }
        foreach (var c in word2) {
            cnt[c - 'a']--;
        }
        return cnt.All(x => Math.Abs(x) <= 3);
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param String $word1
     * @param String $word2
     * @return Boolean
     */
    function checkAlmostEquivalent($word1, $word2) {
        for ($i = 0; $i < strlen($word1); $i++) {
            $hashtable[$word1[$i]] += 1;
            $hashtable[$word2[$i]] -= 1;
        }
        $keys = array_keys($hashtable);
        for ($j = 0; $j < count($keys); $j++) {
            if (abs($hashtable[$keys[$j]]) > 3) {
                return false;
            }
        }
        return true;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2069. 模拟行走机器人 II](https://leetcode.cn/problems/walking-robot-simulation-ii){#2069}

{{< tabs "2069" >}}

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

<p>给你一个在 XY 平面上的&nbsp;<code>width x height</code>&nbsp;的网格图，<strong>左下角</strong>&nbsp;的格子为&nbsp;<code>(0, 0)</code>&nbsp;，<strong>右上角</strong>&nbsp;的格子为&nbsp;<code>(width - 1, height - 1)</code>&nbsp;。网格图中相邻格子为四个基本方向之一（<code>"North"</code>，<code>"East"</code>，<code>"South"</code>&nbsp;和&nbsp;<code>"West"</code>）。一个机器人 <strong>初始</strong>&nbsp;在格子&nbsp;<code>(0, 0)</code>&nbsp;，方向为&nbsp;<code>"East"</code>&nbsp;。</p>

<p>机器人可以根据指令移动指定的 <strong>步数</strong>&nbsp;。每一步，它可以执行以下操作。</p>

<ol>
	<li>沿着当前方向尝试 <strong>往前一步</strong>&nbsp;。</li>
	<li>如果机器人下一步将到达的格子 <strong>超出了边界</strong>&nbsp;，机器人会 <strong>逆时针</strong>&nbsp;转 90 度，然后再尝试往前一步。</li>
</ol>

<p>如果机器人完成了指令要求的移动步数，它将停止移动并等待下一个指令。</p>

<p>请你实现&nbsp;<code>Robot</code>&nbsp;类：</p>

<ul>
	<li><code>Robot(int width, int height)</code>&nbsp;初始化一个&nbsp;<code>width x height</code>&nbsp;的网格图，机器人初始在&nbsp;<code>(0, 0)</code>&nbsp;，方向朝&nbsp;<code>"East"</code>&nbsp;。</li>
	<li><code>void step(int num)</code>&nbsp;给机器人下达前进&nbsp;<code>num</code>&nbsp;步的指令。</li>
	<li><code>int[] getPos()</code>&nbsp;返回机器人当前所处的格子位置，用一个长度为 2 的数组&nbsp;<code>[x, y]</code>&nbsp;表示。</li>
	<li><code>String getDir()</code>&nbsp;返回当前机器人的朝向，为&nbsp;<code>"North"</code>&nbsp;，<code>"East"</code>&nbsp;，<code>"South"</code>&nbsp;或者&nbsp;<code>"West"</code>&nbsp;。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="example-1" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2069.Walking%20Robot%20Simulation%20II/images/example-1.png" style="width: 498px; height: 268px;" /></p>

<pre>
<strong>输入：</strong>
["Robot", "step", "step", "getPos", "getDir", "step", "step", "step", "getPos", "getDir"]
[[6, 3], [2], [2], [], [], [2], [1], [4], [], []]
<strong>输出：</strong>
[null, null, null, [4, 0], "East", null, null, null, [1, 2], "West"]

<strong>解释：</strong>
Robot robot = new Robot(6, 3); // 初始化网格图，机器人在 (0, 0) ，朝东。
robot.step(2);  // 机器人朝东移动 2 步，到达 (2, 0) ，并朝东。
robot.step(2);  // 机器人朝东移动 2 步，到达 (4, 0) ，并朝东。
robot.getPos(); // 返回 [4, 0]
robot.getDir(); // 返回 "East"
robot.step(2);  // 朝东移动 1 步到达 (5, 0) ，并朝东。
                // 下一步继续往东移动将出界，所以逆时针转变方向朝北。
                // 然后，往北移动 1 步到达 (5, 1) ，并朝北。
robot.step(1);  // 朝北移动 1 步到达 (5, 2) ，并朝 <strong>北</strong> （不是朝西）。
robot.step(4);  // 下一步继续往北移动将出界，所以逆时针转变方向朝西。
                // 然后，移动 4 步到 (1, 2) ，并朝西。
robot.getPos(); // 返回 [1, 2]
robot.getDir(); // 返回 "West"

</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= width, height &lt;= 100</code></li>
	<li><code>1 &lt;= num &lt;= 10<sup>5</sup></code></li>
	<li><code>step</code> ，<code>getPos</code>&nbsp;和&nbsp;<code>getDir</code>&nbsp;<strong>总共&nbsp;</strong>调用次数不超过&nbsp;<code>10<sup>4</sup></code>&nbsp;次。</li>
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
