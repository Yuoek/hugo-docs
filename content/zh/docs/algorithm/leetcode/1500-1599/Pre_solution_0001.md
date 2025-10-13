---
title: "1500_设计文件分享系统 🔒"
date: 2025-10-08T18:37:33+08:00
weight: 1
tags: [二分查找, 位运算, 前缀和, 动态规划, 单调栈, 双指针, 哈希表, 堆（优先队列）, 字符串, 排序, 数据库, 数据流, 数组, 栈, 树, 树状数组, 模拟, 深度优先搜索, 矩阵, 线段树, 脑筋急转弯, 设计, 贪心]
---

{{< markmap >}}
### [1500_设计文件分享系统 🔒](#1500)
#### [设计](#1500)
#### [哈希表](#1500)
#### [数据流](#1500)
#### [排序](#1500)
#### [堆（优先队列）](#1500)
### [1501_可以放心投资的国家 🔒](#1501)
#### [数据库](#1501)
### [1502_判断能否形成等差数列](#1502)
#### [数组](#1502)
#### [排序](#1502)
### [1503_所有蚂蚁掉下来前的最后一刻](#1503)
#### [脑筋急转弯](#1503)
#### [数组](#1503)
#### [模拟](#1503)
### [1504_统计全 1 子矩形](#1504)
#### [栈](#1504)
#### [数组](#1504)
#### [动态规划](#1504)
#### [矩阵](#1504)
#### [单调栈](#1504)
### [1505_最多 K 次交换相邻数位后得到的最小整数](#1505)
#### [贪心](#1505)
#### [树状数组](#1505)
#### [线段树](#1505)
#### [字符串](#1505)
### [1506_找到 N 叉树的根节点 🔒](#1506)
#### [位运算](#1506)
#### [树](#1506)
#### [深度优先搜索](#1506)
#### [哈希表](#1506)
### [1507_转变日期格式](#1507)
#### [字符串](#1507)
### [1508_子数组和排序后的区间和](#1508)
#### [数组](#1508)
#### [双指针](#1508)
#### [二分查找](#1508)
#### [前缀和](#1508)
#### [排序](#1508)
### [1509_三次操作后最大值与最小值的最小差](#1509)
#### [贪心](#1509)
#### [数组](#1509)
#### [排序](#1509)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1500_设计文件分享系统 🔒
___
#### 设计
___
#### 哈希表
___
#### 数据流
___
#### 排序
___
#### 堆（优先队列）
---
### 1501_可以放心投资的国家 🔒
___
#### 数据库
---
### 1502_判断能否形成等差数列
___
#### 数组
___
#### 排序
---
### 1503_所有蚂蚁掉下来前的最后一刻
___
#### 脑筋急转弯
___
#### 数组
___
#### 模拟
---
### 1504_统计全 1 子矩形
___
#### 栈
___
#### 数组
___
#### 动态规划
___
#### 矩阵
___
#### 单调栈
---
### 1505_最多 K 次交换相邻数位后得到的最小整数
___
#### 贪心
___
#### 树状数组
___
#### 线段树
___
#### 字符串
---
### 1506_找到 N 叉树的根节点 🔒
___
#### 位运算
___
#### 树
___
#### 深度优先搜索
___
#### 哈希表
---
### 1507_转变日期格式
___
#### 字符串
---
### 1508_子数组和排序后的区间和
___
#### 数组
___
#### 双指针
___
#### 二分查找
___
#### 前缀和
___
#### 排序
---
### 1509_三次操作后最大值与最小值的最小差
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
| 动态规划 | 单调栈 | 双指针 |
| 哈希表 | 堆（优先队列） | 字符串 |
| 排序 | 数据库 | 数据流 |
| 数组 | 栈 | 树 |
| 树状数组 | 模拟 | 深度优先搜索 |
| 矩阵 | 线段树 | 脑筋急转弯 |
| 设计 | 贪心 |  |

# [1500. 设计文件分享系统 🔒](https://leetcode.cn/problems/design-a-file-sharing-system){#1500}

{{< tabs "1500" >}}

{{% tab "python" %}}
```python
class FileSharing:
    def __init__(self, m: int):
        self.cur = 0
        self.chunks = m
        self.reused = []
        self.user_chunks = defaultdict(set)

    def join(self, ownedChunks: List[int]) -> int:
        if self.reused:
            userID = heappop(self.reused)
        else:
            self.cur += 1
            userID = self.cur
        self.user_chunks[userID] = set(ownedChunks)
        return userID

    def leave(self, userID: int) -> None:
        heappush(self.reused, userID)
        self.user_chunks.pop(userID)

    def request(self, userID: int, chunkID: int) -> List[int]:
        if chunkID < 1 or chunkID > self.chunks:
            return []
        res = []
        for k, v in self.user_chunks.items():
            if chunkID in v:
                res.append(k)
        if res:
            self.user_chunks[userID].add(chunkID)
        return sorted(res)


# Your FileSharing object will be instantiated and called as such:
# obj = FileSharing(m)
# param_1 = obj.join(ownedChunks)
# obj.leave(userID)
# param_3 = obj.request(userID,chunkID)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class FileSharing {
    private int chunks;
    private int cur;
    private TreeSet<Integer> reused;
    private TreeMap<Integer, Set<Integer>> userChunks;

    public FileSharing(int m) {
        cur = 0;
        chunks = m;
        reused = new TreeSet<>();
        userChunks = new TreeMap<>();
    }

    public int join(List<Integer> ownedChunks) {
        int userID;
        if (reused.isEmpty()) {
            ++cur;
            userID = cur;
        } else {
            userID = reused.pollFirst();
        }
        userChunks.put(userID, new HashSet<>(ownedChunks));
        return userID;
    }

    public void leave(int userID) {
        reused.add(userID);
        userChunks.remove(userID);
    }

    public List<Integer> request(int userID, int chunkID) {
        if (chunkID < 1 || chunkID > chunks) {
            return Collections.emptyList();
        }
        List<Integer> res = new ArrayList<>();
        for (Map.Entry<Integer, Set<Integer>> entry : userChunks.entrySet()) {
            if (entry.getValue().contains(chunkID)) {
                res.add(entry.getKey());
            }
        }
        if (!res.isEmpty()) {
            userChunks.computeIfAbsent(userID, k -> new HashSet<>()).add(chunkID);
        }
        return res;
    }
}

/**
 * Your FileSharing object will be instantiated and called as such:
 * FileSharing obj = new FileSharing(m);
 * int param_1 = obj.join(ownedChunks);
 * obj.leave(userID);
 * List<Integer> param_3 = obj.request(userID,chunkID);
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>我们需要使用一套文件分享系统来分享一个非常大的文件，该文件由&nbsp;<code>m</code> 个从&nbsp;<code>1</code>&nbsp;到&nbsp;<code>m</code>&nbsp;编号的 <strong>文件块</strong> 组成。</p>

<p>当用户加入系统时，系统应为其注册&nbsp;<strong>一个独有&nbsp;</strong>的 ID。这个独有的 ID 应当被相应的用户使用&nbsp;<strong>一次</strong>，但是当用户离开系统时，其&nbsp;ID 应可以被（后续新注册的用户）<strong>再次使用</strong>。</p>

<p>用户可以请求文件中的某个指定的文件块，系统应当返回拥有这个文件块的所有用户的 ID。如果用户收到&nbsp;ID 的非空列表，就表示成功接收到请求的文件块。</p>

<p><br />
实现&nbsp;<code>FileSharing</code> 类：</p>

<ul>
	<li><code>FileSharing(int m)</code>&nbsp;初始化该对象，文件有&nbsp;<code>m</code> 个文件块。</li>
	<li><code>int join(int[] ownedChunks)</code>：一个新用户加入系统，并拥有文件的一些文件块。系统应当为该用户注册一个 ID，该 ID 应是未被其他用户占用的<strong>最小正整数</strong>。返回注册的 ID。</li>
	<li><code>void leave(int userID)</code>：ID 为&nbsp;<code>userID</code>&nbsp;的用户将离开系统，你不能再从该用户提取文件块了。</li>
	<li><code>int[] request(int userID, int chunkID)</code>：ID 为&nbsp;<code>userID</code>&nbsp;的用户请求编号为&nbsp;<code>chunkID</code>&nbsp;的文件块。返回拥有这个文件块的所有用户的 ID 所构成的列表或数组，按升序排列。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例:</strong></p>

<pre>
<strong>输入:</strong>
["FileSharing","join","join","join","request","request","leave","request","leave","join"]
[[4],[[1,2]],[[2,3]],[[4]],[1,3],[2,2],[1],[2,1],[2],[[]]]
<strong>输出:</strong>
[null,1,2,3,[2],[1,2],null,[],null,1]
<strong>解释:</strong>
FileSharing fileSharing = new FileSharing(4); // 我们用该系统分享由 4 个文件块组成的文件。

fileSharing.join([1, 2]);    // 一个拥有文件块 [1,2] 的用户加入系统，为其注册 id = 1 并返回 1。

fileSharing.join([2, 3]);    // 一个拥有文件块 [2,3] 的用户加入系统，为其注册 id = 2 并返回 2。

fileSharing.join([4]);       // 一个拥有文件块 [4] 的用户加入系统，为其注册 id = 3 并返回 3。

fileSharing.request(1, 3);   // id = 1 的用户请求第 3 个文件块，只有 id = 2 的用户拥有文件块，返回 [2] 。注意，现在用户 1 现拥有文件块 [1,2,3]。

fileSharing.request(2, 2);   // id = 2 的用户请求第 2 个文件块，id 为 [1,2] 的用户拥有该文件块，所以我们返回 [1,2] 。

fileSharing.leave(1);        // id = 1 的用户离开系统，其所拥有的所有文件块不再对其他用户可用。

fileSharing.request(2, 1);   // id = 2 的用户请求第 1 个文件块，系统中没有用户拥有该文件块，所以我们返回空列表 [] 。

fileSharing.leave(2);        // id = 2 的用户离开系统。

fileSharing.join([]);        // 一个不拥有任何文件块的用户加入系统，为其注册 id = 1 并返回 1 。注意，id 1 和 2 空闲，可以重新使用。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= m &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;=&nbsp;ownedChunks.length &lt;= min(100, m)</code></li>
	<li><code>1 &lt;= ownedChunks[i] &lt;= m</code></li>
	<li><code>ownedChunks</code> 的值是互不相同的。</li>
	<li><code>1 &lt;=&nbsp;chunkID &lt;= m</code></li>
	<li>当你<strong>正确地注册</strong>用户 ID 时，题目保证&nbsp;<code>userID</code>&nbsp;是系统中的一个已注册用户。</li>
	<li><code>join</code>、&nbsp;<code>leave</code>&nbsp;和&nbsp;<code>request</code>&nbsp;最多被调用&nbsp;<code>10<sup>4</sup></code>&nbsp;次。</li>
	<li>每次对&nbsp;<code>leave</code>&nbsp;的调用都有对应的对&nbsp;<code>join</code>&nbsp;的调用。</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong></p>

<ul>
	<li>当系统以用户的 IP 地址而不是独有 ID 来识别用户，且用户断开连接后以相同 IP 重新连接系统时，会发生什么？</li>
	<li>当用户频繁加入并退出系统，且该用户不请求任何文件块时，你的解决方案仍然保持高效吗？</li>
	<li>当所有用户同时加入系统，请求所有文件并离开时，你的解决方案仍然保持高效吗？</li>
	<li>如果系统用于分享&nbsp;<code>n</code>&nbsp;个文件，其中第 &nbsp;<code>i</code>&nbsp;个文件由&nbsp;<code>m[i]</code>&nbsp;组成，你需要如何修改？</li>
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
class FileSharing:
    def __init__(self, m: int):
        self.cur = 0
        self.chunks = m
        self.reused = []
        self.user_chunks = defaultdict(set)

    def join(self, ownedChunks: List[int]) -> int:
        if self.reused:
            userID = heappop(self.reused)
        else:
            self.cur += 1
            userID = self.cur
        self.user_chunks[userID] = set(ownedChunks)
        return userID

    def leave(self, userID: int) -> None:
        heappush(self.reused, userID)
        self.user_chunks.pop(userID)

    def request(self, userID: int, chunkID: int) -> List[int]:
        if chunkID < 1 or chunkID > self.chunks:
            return []
        res = []
        for k, v in self.user_chunks.items():
            if chunkID in v:
                res.append(k)
        if res:
            self.user_chunks[userID].add(chunkID)
        return sorted(res)


# Your FileSharing object will be instantiated and called as such:
# obj = FileSharing(m)
# param_1 = obj.join(ownedChunks)
# obj.leave(userID)
# param_3 = obj.request(userID,chunkID)
```

#### Java

```java
class FileSharing {
    private int chunks;
    private int cur;
    private TreeSet<Integer> reused;
    private TreeMap<Integer, Set<Integer>> userChunks;

    public FileSharing(int m) {
        cur = 0;
        chunks = m;
        reused = new TreeSet<>();
        userChunks = new TreeMap<>();
    }

    public int join(List<Integer> ownedChunks) {
        int userID;
        if (reused.isEmpty()) {
            ++cur;
            userID = cur;
        } else {
            userID = reused.pollFirst();
        }
        userChunks.put(userID, new HashSet<>(ownedChunks));
        return userID;
    }

    public void leave(int userID) {
        reused.add(userID);
        userChunks.remove(userID);
    }

    public List<Integer> request(int userID, int chunkID) {
        if (chunkID < 1 || chunkID > chunks) {
            return Collections.emptyList();
        }
        List<Integer> res = new ArrayList<>();
        for (Map.Entry<Integer, Set<Integer>> entry : userChunks.entrySet()) {
            if (entry.getValue().contains(chunkID)) {
                res.add(entry.getKey());
            }
        }
        if (!res.isEmpty()) {
            userChunks.computeIfAbsent(userID, k -> new HashSet<>()).add(chunkID);
        }
        return res;
    }
}

/**
 * Your FileSharing object will be instantiated and called as such:
 * FileSharing obj = new FileSharing(m);
 * int param_1 = obj.join(ownedChunks);
 * obj.leave(userID);
 * List<Integer> param_3 = obj.request(userID,chunkID);
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1501. 可以放心投资的国家 🔒](https://leetcode.cn/problems/countries-you-can-safely-invest-in){#1501}

{{< tabs "1501" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT c.name AS country, AVG(duration) AS duration
        FROM
            Person
            JOIN Calls ON id IN(caller_id, callee_id)
            JOIN Country AS c ON LEFT(phone_number, 3) = country_code
        GROUP BY 1
    )
SELECT country
FROM T
WHERE duration > (SELECT AVG(duration) FROM Calls);
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表&nbsp;<code>Person</code>:</p>

<pre>
+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| id             | int     |
| name           | varchar |
| phone_number   | varchar |
+----------------+---------+
id 是该表具有唯一值的列.
该表每一行包含一个人的名字和电话号码.
电话号码的格式是:'xxx-yyyyyyy', 其中 xxx 是国家码(3 个字符), yyyyyyy 是电话号码(7 个字符), x 和 y 都表示数字. 同时, 国家码和电话号码都可以包含前导 0.
</pre>

<p>&nbsp;</p>

<p>表&nbsp;<code>Country</code>:</p>

<pre>
+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| name           | varchar |
| country_code   | varchar |
+----------------+---------+
country_code 是该表具有唯一值的列.
该表每一行包含国家名和国家码. country_code 的格式是'xxx', x 是数字.
</pre>

<p>&nbsp;</p>

<p>表&nbsp;<code>Calls</code>:</p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| caller_id   | int  |
| callee_id   | int  |
| duration    | int  |
+-------------+------+
该表无主键, 可能包含重复行.
每一行包含呼叫方 id, 被呼叫方 id 和以分钟为单位的通话时长. caller_id != callee_id
</pre>

<p>&nbsp;</p>

<p>一家电信公司想要投资新的国家。该公司想要投资的国家是:&nbsp; 该国的平均通话时长要严格地大于全球平均通话时长。</p>

<p>写一个解决方案,&nbsp;&nbsp;找到所有该公司可以投资的国家。</p>

<p>返回的结果表 <strong>无顺序要求</strong>。</p>

<p>结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<span style="white-space: pre-wrap;"><strong>输入：</strong>
Person 表：</span>
+----+----------+--------------+
| id | name     | phone_number |
+----+----------+--------------+
| 3  | Jonathan | 051-1234567  |
| 12 | Elvis    | 051-7654321  |
| 1  | Moncef   | 212-1234567  |
| 2  | Maroua   | 212-6523651  |
| 7  | Meir     | 972-1234567  |
| 9  | Rachel   | 972-0011100  |
+----+----------+--------------+
Country 表:
+----------+--------------+
| name     | country_code |
+----------+--------------+
| Peru     | 051          |
| Israel   | 972          |
| Morocco  | 212          |
| Germany  | 049          |
| Ethiopia | 251          |
+----------+--------------+
Calls 表:
+-----------+-----------+----------+
| caller_id | callee_id | duration |
+-----------+-----------+----------+
| 1         | 9         | 33       |
| 2         | 9         | 4        |
| 1         | 2         | 59       |
| 3         | 12        | 102      |
| 3         | 12        | 330      |
| 12        | 3         | 5        |
| 7         | 9         | 13       |
| 7         | 1         | 3        |
| 9         | 7         | 1        |
| 1         | 7         | 7        |
+-----------+-----------+----------+
<b>输出：</b>
+----------+
| country  |
+----------+
| Peru     |
+----------+
<b>解释：</b>
国家 Peru 的平均通话时长是 (102 + 102 + 330 + 330 + 5 + 5) / 6 = 145.666667
国家 Israel 的平均通话时长是 (33 + 4 + 13 + 13 + 3 + 1 + 1 + 7) / 8 = 9.37500
国家 Morocco 的平均通话时长是 (33 + 4 + 59 + 59 + 3 + 7) / 6 = 27.5000 
全球平均通话时长 = (2 * (33 + 4 + 59 + 102 + 330 + 5 + 13 + 3 + 1 + 7)) / 20 = 55.70000
所以, Peru 是唯一的平均通话时长大于全球平均通话时长的国家, 也是唯一的推荐投资的国家.
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：等值连接 + 分组 + 子查询

我们可以使用等值连接，将 `Person` 表和 `Calls` 表连接起来，连接的条件是 `Person.id = Calls.caller_id` 或者 `Person.id = Calls.callee_id`，然后再将连接后的表和 `Country` 表连接起来，连接的条件是 `left(phone_number, 3) = country_code`，最后按照国家分组，计算每个国家的平均通话时长，然后再使用子查询，找出平均通话时长大于全球平均通话时长的国家。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT country
FROM
    (
        SELECT c.name AS country, AVG(duration) AS duration
        FROM
            Person
            JOIN Calls ON id IN(caller_id, callee_id)
            JOIN Country AS c ON LEFT(phone_number, 3) = country_code
        GROUP BY 1
    ) AS t
WHERE duration > (SELECT AVG(duration) FROM Calls);
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT c.name AS country, AVG(duration) AS duration
        FROM
            Person
            JOIN Calls ON id IN(caller_id, callee_id)
            JOIN Country AS c ON LEFT(phone_number, 3) = country_code
        GROUP BY 1
    )
SELECT country
FROM T
WHERE duration > (SELECT AVG(duration) FROM Calls);
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1502. 判断能否形成等差数列](https://leetcode.cn/problems/can-make-arithmetic-progression-from-sequence){#1502}

{{< tabs "1502" >}}

{{% tab "python" %}}
```python
class Solution:
    def canMakeArithmeticProgression(self, arr: List[int]) -> bool:
        a = min(arr)
        b = max(arr)
        n = len(arr)
        if (b - a) % (n - 1):
            return False
        d = (b - a) // (n - 1)
        s = set(arr)
        return all(a + d * i in s for i in range(n))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean canMakeArithmeticProgression(int[] arr) {
        int n = arr.length;
        int a = arr[0], b = arr[0];
        Set<Integer> s = new HashSet<>();
        for (int x : arr) {
            a = Math.min(a, x);
            b = Math.max(b, x);
            s.add(x);
        }
        if ((b - a) % (n - 1) != 0) {
            return false;
        }
        int d = (b - a) / (n - 1);
        for (int i = 0; i < n; ++i) {
            if (!s.contains(a + d * i)) {
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
    bool canMakeArithmeticProgression(vector<int>& arr) {
        auto [a, b] = minmax_element(arr.begin(), arr.end());
        int n = arr.size();
        if ((*b - *a) % (n - 1) != 0) {
            return false;
        }
        int d = (*b - *a) / (n - 1);
        unordered_set<int> s(arr.begin(), arr.end());
        for (int i = 0; i < n; ++i) {
            if (!s.count(*a + d * i)) {
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
func canMakeArithmeticProgression(arr []int) bool {
	a, b := slices.Min(arr), slices.Max(arr)
	n := len(arr)
	if (b-a)%(n-1) != 0 {
		return false
	}
	d := (b - a) / (n - 1)
	s := map[int]bool{}
	for _, x := range arr {
		s[x] = true
	}
	for i := 0; i < n; i++ {
		if !s[a+i*d] {
			return false
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function canMakeArithmeticProgression(arr: number[]): boolean {
    const n = arr.length;
    const a = Math.min(...arr);
    const b = Math.max(...arr);

    if ((b - a) % (n - 1) !== 0) {
        return false;
    }

    const d = (b - a) / (n - 1);
    const s = new Set(arr);

    for (let i = 0; i < n; ++i) {
        if (!s.has(a + d * i)) {
            return false;
        }
    }
    return true;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn can_make_arithmetic_progression(arr: Vec<i32>) -> bool {
        let n = arr.len();
        let a = *arr.iter().min().unwrap();
        let b = *arr.iter().max().unwrap();

        if (b - a) % (n as i32 - 1) != 0 {
            return false;
        }

        let d = (b - a) / (n as i32 - 1);
        let s: std::collections::HashSet<_> = arr.into_iter().collect();

        for i in 0..n {
            if !s.contains(&(a + d * i as i32)) {
                return false;
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
 * @param {number[]} arr
 * @return {boolean}
 */
var canMakeArithmeticProgression = function (arr) {
    const n = arr.length;
    const a = Math.min(...arr);
    const b = Math.max(...arr);

    if ((b - a) % (n - 1) !== 0) {
        return false;
    }

    const d = (b - a) / (n - 1);
    const s = new Set(arr);

    for (let i = 0; i < n; ++i) {
        if (!s.has(a + d * i)) {
            return false;
        }
    }
    return true;
};
```
{{% /tab %}}
{{% tab "c" %}}
```c
int cmp(const void* a, const void* b) {
    return *(int*) a - *(int*) b;
}

bool canMakeArithmeticProgression(int* arr, int arrSize) {
    qsort(arr, arrSize, sizeof(int), cmp);
    int d = arr[1] - arr[0];
    for (int i = 2; i < arrSize; i++) {
        if (arr[i] - arr[i - 1] != d) {
            return 0;
        }
    }
    return 1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个数字数组 <code>arr</code> 。</p>

<p>如果一个数列中，任意相邻两项的差总等于同一个常数，那么这个数列就称为 <strong>等差数列</strong> 。</p>

<p>如果可以重新排列数组形成等差数列，请返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [3,5,1]
<strong>输出：</strong>true
<strong>解释：</strong>对数组重新排序得到 [1,3,5] 或者 [5,3,1] ，任意相邻两项的差分别为 2 或 -2 ，可以形成等差数列。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = [1,2,4]
<strong>输出：</strong>false
<strong>解释：</strong>无法通过重新排序得到等差数列。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= arr.length &lt;= 1000</code></li>
	<li><code>-10^6 &lt;= arr[i] &lt;= 10^6</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 遍历

我们可以先将数组 $\textit{arr}$ 排序，然后计算前两项的差值 $d$，接着遍历数组，判断相邻两项的差是否等于 $d$。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为数组 $\textit{arr}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canMakeArithmeticProgression(self, arr: List[int]) -> bool:
        arr.sort()
        d = arr[1] - arr[0]
        return all(b - a == d for a, b in pairwise(arr))
```

#### Java

```java
class Solution {
    public boolean canMakeArithmeticProgression(int[] arr) {
        Arrays.sort(arr);
        int d = arr[1] - arr[0];
        for (int i = 2; i < arr.length; ++i) {
            if (arr[i] - arr[i - 1] != d) {
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
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int d = arr[1] - arr[0];
        for (int i = 2; i < arr.size(); i++) {
            if (arr[i] - arr[i - 1] != d) {
                return false;
            }
        }
        return true;
    }
};
```

#### Go

```go
func canMakeArithmeticProgression(arr []int) bool {
	sort.Ints(arr)
	d := arr[1] - arr[0]
	for i := 2; i < len(arr); i++ {
		if arr[i]-arr[i-1] != d {
			return false
		}
	}
	return true
}
```

#### TypeScript

```ts
function canMakeArithmeticProgression(arr: number[]): boolean {
    arr.sort((a, b) => a - b);
    const n = arr.length;
    const d = arr[1] - arr[0];
    for (let i = 2; i < n; i++) {
        if (arr[i] - arr[i - 1] !== d) {
            return false;
        }
    }
    return true;
}
```

#### Rust

```rust
impl Solution {
    pub fn can_make_arithmetic_progression(mut arr: Vec<i32>) -> bool {
        arr.sort();
        let n = arr.len();
        let d = arr[1] - arr[0];
        for i in 2..n {
            if arr[i] - arr[i - 1] != d {
                return false;
            }
        }
        true
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} arr
 * @return {boolean}
 */
var canMakeArithmeticProgression = function (arr) {
    arr.sort((a, b) => a - b);
    const n = arr.length;
    const d = arr[1] - arr[0];
    for (let i = 2; i < n; i++) {
        if (arr[i] - arr[i - 1] !== d) {
            return false;
        }
    }
    return true;
};
```

#### C

```c
int cmp(const void* a, const void* b) {
    return *(int*) a - *(int*) b;
}

bool canMakeArithmeticProgression(int* arr, int arrSize) {
    qsort(arr, arrSize, sizeof(int), cmp);
    int d = arr[1] - arr[0];
    for (int i = 2; i < arrSize; i++) {
        if (arr[i] - arr[i - 1] != d) {
            return 0;
        }
    }
    return 1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：哈希表 + 数学

我们先找出数组 $\textit{arr}$ 中的最小值 $a$ 和最大值 $b$，如果数组 $\textit{arr}$ 可以重排成等差数列，那么公差 $d = \frac{b - a}{n - 1}$ 必须为整数。

我们可以用哈希表来记录数组 $\textit{arr}$ 中的所有元素，然后遍历 $i \in [0, n)$，判断 $a + d \times i$ 是否在哈希表中，如果不在，说明数组 $\textit{arr}$ 不能重排成等差数列，返回 `false`。否则遍历完数组后，返回 `true`。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{arr}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canMakeArithmeticProgression(self, arr: List[int]) -> bool:
        a = min(arr)
        b = max(arr)
        n = len(arr)
        if (b - a) % (n - 1):
            return False
        d = (b - a) // (n - 1)
        s = set(arr)
        return all(a + d * i in s for i in range(n))
```

#### Java

```java
class Solution {
    public boolean canMakeArithmeticProgression(int[] arr) {
        int n = arr.length;
        int a = arr[0], b = arr[0];
        Set<Integer> s = new HashSet<>();
        for (int x : arr) {
            a = Math.min(a, x);
            b = Math.max(b, x);
            s.add(x);
        }
        if ((b - a) % (n - 1) != 0) {
            return false;
        }
        int d = (b - a) / (n - 1);
        for (int i = 0; i < n; ++i) {
            if (!s.contains(a + d * i)) {
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
    bool canMakeArithmeticProgression(vector<int>& arr) {
        auto [a, b] = minmax_element(arr.begin(), arr.end());
        int n = arr.size();
        if ((*b - *a) % (n - 1) != 0) {
            return false;
        }
        int d = (*b - *a) / (n - 1);
        unordered_set<int> s(arr.begin(), arr.end());
        for (int i = 0; i < n; ++i) {
            if (!s.count(*a + d * i)) {
                return false;
            }
        }
        return true;
    }
};
```

#### Go

```go
func canMakeArithmeticProgression(arr []int) bool {
	a, b := slices.Min(arr), slices.Max(arr)
	n := len(arr)
	if (b-a)%(n-1) != 0 {
		return false
	}
	d := (b - a) / (n - 1)
	s := map[int]bool{}
	for _, x := range arr {
		s[x] = true
	}
	for i := 0; i < n; i++ {
		if !s[a+i*d] {
			return false
		}
	}
	return true
}
```

#### TypeScript

```ts
function canMakeArithmeticProgression(arr: number[]): boolean {
    const n = arr.length;
    const a = Math.min(...arr);
    const b = Math.max(...arr);

    if ((b - a) % (n - 1) !== 0) {
        return false;
    }

    const d = (b - a) / (n - 1);
    const s = new Set(arr);

    for (let i = 0; i < n; ++i) {
        if (!s.has(a + d * i)) {
            return false;
        }
    }
    return true;
}
```

#### Rust

```rust
impl Solution {
    pub fn can_make_arithmetic_progression(arr: Vec<i32>) -> bool {
        let n = arr.len();
        let a = *arr.iter().min().unwrap();
        let b = *arr.iter().max().unwrap();

        if (b - a) % (n as i32 - 1) != 0 {
            return false;
        }

        let d = (b - a) / (n as i32 - 1);
        let s: std::collections::HashSet<_> = arr.into_iter().collect();

        for i in 0..n {
            if !s.contains(&(a + d * i as i32)) {
                return false;
            }
        }
        true
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} arr
 * @return {boolean}
 */
var canMakeArithmeticProgression = function (arr) {
    const n = arr.length;
    const a = Math.min(...arr);
    const b = Math.max(...arr);

    if ((b - a) % (n - 1) !== 0) {
        return false;
    }

    const d = (b - a) / (n - 1);
    const s = new Set(arr);

    for (let i = 0; i < n; ++i) {
        if (!s.has(a + d * i)) {
            return false;
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

# [1503. 所有蚂蚁掉下来前的最后一刻](https://leetcode.cn/problems/last-moment-before-all-ants-fall-out-of-a-plank){#1503}

{{< tabs "1503" >}}

{{% tab "python" %}}
```python
class Solution:
    def getLastMoment(self, n: int, left: List[int], right: List[int]) -> int:
        ans = 0
        for x in left:
            ans = max(ans, x)
        for x in right:
            ans = max(ans, n - x)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int getLastMoment(int n, int[] left, int[] right) {
        int ans = 0;
        for (int x : left) {
            ans = Math.max(ans, x);
        }
        for (int x : right) {
            ans = Math.max(ans, n - x);
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
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;
        for (int& x : left) {
            ans = max(ans, x);
        }
        for (int& x : right) {
            ans = max(ans, n - x);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getLastMoment(n int, left []int, right []int) (ans int) {
	for _, x := range left {
		ans = max(ans, x)
	}
	for _, x := range right {
		ans = max(ans, n-x)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function getLastMoment(n: number, left: number[], right: number[]): number {
    let ans = 0;
    for (const x of left) {
        ans = Math.max(ans, x);
    }
    for (const x of right) {
        ans = Math.max(ans, n - x);
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

<p>有一块木板，长度为 <code>n</code> 个 <strong>单位</strong> 。一些蚂蚁在木板上移动，每只蚂蚁都以 <strong>每秒一个单位</strong> 的速度移动。其中，一部分蚂蚁向 <strong>左</strong> 移动，其他蚂蚁向 <strong>右</strong> 移动。</p>

<p>当两只向 <strong>不同</strong> 方向移动的蚂蚁在某个点相遇时，它们会同时改变移动方向并继续移动。假设更改方向不会花费任何额外时间。</p>

<p>而当蚂蚁在某一时刻 <code>t</code> 到达木板的一端时，它立即从木板上掉下来。</p>

<p>给你一个整数 <code>n</code> 和两个整数数组 <code>left</code> 以及 <code>right</code> 。两个数组分别标识向左或者向右移动的蚂蚁在 <code>t = 0</code> 时的位置。请你返回最后一只蚂蚁从木板上掉下来的时刻。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p>&nbsp;</p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1503.Last%20Moment%20Before%20All%20Ants%20Fall%20Out%20of%20a%20Plank/images/ants.jpg" style="height: 610px; width: 450px;" /></p>

<pre>
<strong>输入：</strong>n = 4, left = [4,3], right = [0,1]
<strong>输出：</strong>4
<strong>解释：</strong>如上图所示：
-下标 0 处的蚂蚁命名为 A 并向右移动。
-下标 1 处的蚂蚁命名为 B 并向右移动。
-下标 3 处的蚂蚁命名为 C 并向左移动。
-下标 4 处的蚂蚁命名为 D 并向左移动。
请注意，蚂蚁在木板上的最后时刻是 t = 4 秒，之后蚂蚁立即从木板上掉下来。（也就是说在 t = 4.0000000001 时，木板上没有蚂蚁）。</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1503.Last%20Moment%20Before%20All%20Ants%20Fall%20Out%20of%20a%20Plank/images/ants2.jpg" style="height: 101px; width: 639px;" /></p>

<pre>
<strong>输入：</strong>n = 7, left = [], right = [0,1,2,3,4,5,6,7]
<strong>输出：</strong>7
<strong>解释：</strong>所有蚂蚁都向右移动，下标为 0 的蚂蚁需要 7 秒才能从木板上掉落。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1503.Last%20Moment%20Before%20All%20Ants%20Fall%20Out%20of%20a%20Plank/images/ants3.jpg" style="height: 100px; width: 639px;" /></p>

<pre>
<strong>输入：</strong>n = 7, left = [0,1,2,3,4,5,6,7], right = []
<strong>输出：</strong>7
<strong>解释：</strong>所有蚂蚁都向左移动，下标为 7 的蚂蚁需要 7 秒才能从木板上掉落。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10^4</code></li>
	<li><code>0 &lt;= left.length &lt;= n + 1</code></li>
	<li><code>0 &lt;= left[i] &lt;= n</code></li>
	<li><code>0 &lt;= right.length &lt;= n + 1</code></li>
	<li><code>0 &lt;= right[i] &lt;= n</code></li>
	<li><code>1 &lt;= left.length + right.length &lt;= n + 1</code></li>
	<li><code>left</code> 和 <code>right</code> 中的所有值都是唯一的，并且每个值 <strong>只能出现在二者之一</strong> 中。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：脑筋急转弯

题目关键点在于两只蚂蚁相遇，然后分别调转方向的情况，实际上相当于两只蚂蚁继续往原来的方向移动。因此，我们只需要求出所有蚂蚁中最远的那只蚂蚁的移动距离即可。

注意 $\textit{left}$ 和 $\textit{right}$ 数组的长度可能为 $0$。

时间复杂度 $O(n)$，其中 $n$ 为木板的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getLastMoment(self, n: int, left: List[int], right: List[int]) -> int:
        ans = 0
        for x in left:
            ans = max(ans, x)
        for x in right:
            ans = max(ans, n - x)
        return ans
```

#### Java

```java
class Solution {
    public int getLastMoment(int n, int[] left, int[] right) {
        int ans = 0;
        for (int x : left) {
            ans = Math.max(ans, x);
        }
        for (int x : right) {
            ans = Math.max(ans, n - x);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;
        for (int& x : left) {
            ans = max(ans, x);
        }
        for (int& x : right) {
            ans = max(ans, n - x);
        }
        return ans;
    }
};
```

#### Go

```go
func getLastMoment(n int, left []int, right []int) (ans int) {
	for _, x := range left {
		ans = max(ans, x)
	}
	for _, x := range right {
		ans = max(ans, n-x)
	}
	return
}
```

#### TypeScript

```ts
function getLastMoment(n: number, left: number[], right: number[]): number {
    let ans = 0;
    for (const x of left) {
        ans = Math.max(ans, x);
    }
    for (const x of right) {
        ans = Math.max(ans, n - x);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1504. 统计全 1 子矩形](https://leetcode.cn/problems/count-submatrices-with-all-ones){#1504}

{{< tabs "1504" >}}

{{% tab "python" %}}
```python
class Solution:
    def numSubmat(self, mat: List[List[int]]) -> int:
        m, n = len(mat), len(mat[0])
        g = [[0] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if mat[i][j]:
                    g[i][j] = 1 if j == 0 else 1 + g[i][j - 1]
        ans = 0
        for i in range(m):
            for j in range(n):
                col = inf
                for k in range(i, -1, -1):
                    col = min(col, g[k][j])
                    ans += col
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numSubmat(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        int[][] g = new int[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1) {
                    g[i][j] = j == 0 ? 1 : 1 + g[i][j - 1];
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int col = 1 << 30;
                for (int k = i; k >= 0 && col > 0; --k) {
                    col = Math.min(col, g[k][j]);
                    ans += col;
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
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> g(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1) {
                    g[i][j] = j == 0 ? 1 : 1 + g[i][j - 1];
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int col = 1 << 30;
                for (int k = i; k >= 0 && col > 0; --k) {
                    col = min(col, g[k][j]);
                    ans += col;
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
func numSubmat(mat [][]int) (ans int) {
	m, n := len(mat), len(mat[0])
	g := make([][]int, m)
	for i := range g {
		g[i] = make([]int, n)
		for j := range g[i] {
			if mat[i][j] == 1 {
				if j == 0 {
					g[i][j] = 1
				} else {
					g[i][j] = 1 + g[i][j-1]
				}
			}
		}
	}
	for i := range g {
		for j := range g[i] {
			col := 1 << 30
			for k := i; k >= 0 && col > 0; k-- {
				col = min(col, g[k][j])
				ans += col
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numSubmat(mat: number[][]): number {
    const m = mat.length;
    const n = mat[0].length;
    const g: number[][] = Array.from({ length: m }, () => Array(n).fill(0));

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (mat[i][j]) {
                g[i][j] = j === 0 ? 1 : 1 + g[i][j - 1];
            }
        }
    }

    let ans = 0;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            let col = Infinity;
            for (let k = i; k >= 0; k--) {
                col = Math.min(col, g[k][j]);
                ans += col;
            }
        }
    }

    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn num_submat(mat: Vec<Vec<i32>>) -> i32 {
        let m = mat.len();
        let n = mat[0].len();
        let mut g = vec![vec![0; n]; m];

        for i in 0..m {
            for j in 0..n {
                if mat[i][j] == 1 {
                    if j == 0 {
                        g[i][j] = 1;
                    } else {
                        g[i][j] = 1 + g[i][j - 1];
                    }
                }
            }
        }

        let mut ans = 0;
        for i in 0..m {
            for j in 0..n {
                let mut col = i32::MAX;
                let mut k = i as i32;
                while k >= 0 && col > 0 {
                    col = col.min(g[k as usize][j]);
                    ans += col;
                    k -= 1;
                }
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
 * @param {number[][]} mat
 * @return {number}
 */
var numSubmat = function (mat) {
    const m = mat.length;
    const n = mat[0].length;
    const g = Array.from({ length: m }, () => Array(n).fill(0));

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (mat[i][j]) {
                g[i][j] = j === 0 ? 1 : 1 + g[i][j - 1];
            }
        }
    }

    let ans = 0;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            let col = Infinity;
            for (let k = i; k >= 0; k--) {
                col = Math.min(col, g[k][j]);
                ans += col;
            }
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

<p>给你一个&nbsp;<code>m x n</code>&nbsp;的二进制矩阵&nbsp;<code>mat</code>&nbsp;，请你返回有多少个&nbsp;<strong>子矩形</strong>&nbsp;的元素全部都是 1 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1504.Count%20Submatrices%20With%20All%20Ones/images/ones1-grid.jpg" /></p>

<pre>
<strong>输入：</strong>mat = [[1,0,1],[1,1,0],[1,1,0]]
<strong>输出：</strong>13
<strong>解释：
</strong>有 <strong>6</strong>&nbsp;个 1x1 的矩形。
有 <strong>2</strong> 个 1x2 的矩形。
有 <strong>3</strong> 个 2x1 的矩形。
有 <strong>1</strong> 个 2x2 的矩形。
有 <strong>1</strong> 个 3x1 的矩形。
矩形数目总共 = 6 + 2 + 3 + 1 + 1 = <strong>13</strong>&nbsp;。
</pre>

<p><strong>示例 2：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1504.Count%20Submatrices%20With%20All%20Ones/images/ones2-grid.jpg" /></p>

<pre>
<strong>输入：</strong>mat = [[0,1,1,0],[0,1,1,1],[1,1,1,0]]
<strong>输出：</strong>24
<strong>解释：</strong>
有 <strong>8</strong> 个 1x1 的子矩形。
有 <strong>5</strong> 个 1x2 的子矩形。
有 <strong>2</strong> 个 1x3 的子矩形。
有 <strong>4</strong> 个 2x1 的子矩形。
有 <strong>2</strong> 个 2x2 的子矩形。
有 <strong>2</strong> 个 3x1 的子矩形。
有 <strong>1</strong> 个 3x2 的子矩形。
矩形数目总共 = 8 + 5 + 2 + 4 + 2 + 2 + 1 = <strong>24</strong><strong> 。</strong>

</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= m, n &lt;= 150</code></li>
	<li><code>mat[i][j]</code>&nbsp;仅包含&nbsp;<code>0</code>&nbsp;或&nbsp;<code>1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举 + 前缀和

我们可以枚举矩阵的右下角 $(i, j)$，然后向上枚举矩阵的第一行 $k$，那么每一行以 $(i, j)$ 为右下角的矩阵的宽度就是 $\min_{k \leq i} \textit{g}[k][j]$，其中 $\textit{g}[k][j]$ 表示第 $k$ 行以 $(k, j)$ 为右下角的矩阵的宽度。

因此，我们可以预处理得到二维数组 $g[i][j]$，其中 $g[i][j]$ 表示第 $i$ 行中，从第 $j$ 列向左连续的 $1$ 的个数。

时间复杂度 $O(m^2 \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numSubmat(self, mat: List[List[int]]) -> int:
        m, n = len(mat), len(mat[0])
        g = [[0] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if mat[i][j]:
                    g[i][j] = 1 if j == 0 else 1 + g[i][j - 1]
        ans = 0
        for i in range(m):
            for j in range(n):
                col = inf
                for k in range(i, -1, -1):
                    col = min(col, g[k][j])
                    ans += col
        return ans
```

#### Java

```java
class Solution {
    public int numSubmat(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        int[][] g = new int[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1) {
                    g[i][j] = j == 0 ? 1 : 1 + g[i][j - 1];
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int col = 1 << 30;
                for (int k = i; k >= 0 && col > 0; --k) {
                    col = Math.min(col, g[k][j]);
                    ans += col;
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
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> g(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1) {
                    g[i][j] = j == 0 ? 1 : 1 + g[i][j - 1];
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int col = 1 << 30;
                for (int k = i; k >= 0 && col > 0; --k) {
                    col = min(col, g[k][j]);
                    ans += col;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func numSubmat(mat [][]int) (ans int) {
	m, n := len(mat), len(mat[0])
	g := make([][]int, m)
	for i := range g {
		g[i] = make([]int, n)
		for j := range g[i] {
			if mat[i][j] == 1 {
				if j == 0 {
					g[i][j] = 1
				} else {
					g[i][j] = 1 + g[i][j-1]
				}
			}
		}
	}
	for i := range g {
		for j := range g[i] {
			col := 1 << 30
			for k := i; k >= 0 && col > 0; k-- {
				col = min(col, g[k][j])
				ans += col
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function numSubmat(mat: number[][]): number {
    const m = mat.length;
    const n = mat[0].length;
    const g: number[][] = Array.from({ length: m }, () => Array(n).fill(0));

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (mat[i][j]) {
                g[i][j] = j === 0 ? 1 : 1 + g[i][j - 1];
            }
        }
    }

    let ans = 0;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            let col = Infinity;
            for (let k = i; k >= 0; k--) {
                col = Math.min(col, g[k][j]);
                ans += col;
            }
        }
    }

    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn num_submat(mat: Vec<Vec<i32>>) -> i32 {
        let m = mat.len();
        let n = mat[0].len();
        let mut g = vec![vec![0; n]; m];

        for i in 0..m {
            for j in 0..n {
                if mat[i][j] == 1 {
                    if j == 0 {
                        g[i][j] = 1;
                    } else {
                        g[i][j] = 1 + g[i][j - 1];
                    }
                }
            }
        }

        let mut ans = 0;
        for i in 0..m {
            for j in 0..n {
                let mut col = i32::MAX;
                let mut k = i as i32;
                while k >= 0 && col > 0 {
                    col = col.min(g[k as usize][j]);
                    ans += col;
                    k -= 1;
                }
            }
        }
        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number[][]} mat
 * @return {number}
 */
var numSubmat = function (mat) {
    const m = mat.length;
    const n = mat[0].length;
    const g = Array.from({ length: m }, () => Array(n).fill(0));

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (mat[i][j]) {
                g[i][j] = j === 0 ? 1 : 1 + g[i][j - 1];
            }
        }
    }

    let ans = 0;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            let col = Infinity;
            for (let k = i; k >= 0; k--) {
                col = Math.min(col, g[k][j]);
                ans += col;
            }
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

# [1505. 最多 K 次交换相邻数位后得到的最小整数](https://leetcode.cn/problems/minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits){#1505}

{{< tabs "1505" >}}

{{% tab "python" %}}
```python
class BinaryIndexedTree:
    def __init__(self, n):
        self.n = n
        self.c = [0] * (n + 1)

    @staticmethod
    def lowbit(x):
        return x & -x

    def update(self, x, delta):
        while x <= self.n:
            self.c[x] += delta
            x += BinaryIndexedTree.lowbit(x)

    def query(self, x):
        s = 0
        while x:
            s += self.c[x]
            x -= BinaryIndexedTree.lowbit(x)
        return s


class Solution:
    def minInteger(self, num: str, k: int) -> str:
        pos = defaultdict(deque)
        for i, v in enumerate(num, 1):
            pos[int(v)].append(i)
        ans = []
        n = len(num)
        tree = BinaryIndexedTree(n)
        for i in range(1, n + 1):
            for v in range(10):
                q = pos[v]
                if q:
                    j = q[0]
                    dist = tree.query(n) - tree.query(j) + j - i
                    if dist <= k:
                        k -= dist
                        q.popleft()
                        ans.append(str(v))
                        tree.update(j, 1)
                        break
        return ''.join(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String minInteger(String num, int k) {
        Queue<Integer>[] pos = new Queue[10];
        for (int i = 0; i < 10; ++i) {
            pos[i] = new ArrayDeque<>();
        }
        int n = num.length();
        for (int i = 0; i < n; ++i) {
            pos[num.charAt(i) - '0'].offer(i + 1);
        }
        StringBuilder ans = new StringBuilder();
        BinaryIndexedTree tree = new BinaryIndexedTree(n);
        for (int i = 1; i <= n; ++i) {
            for (int v = 0; v < 10; ++v) {
                if (!pos[v].isEmpty()) {
                    Queue<Integer> q = pos[v];
                    int j = q.peek();
                    int dist = tree.query(n) - tree.query(j) + j - i;
                    if (dist <= k) {
                        k -= dist;
                        q.poll();
                        ans.append(v);
                        tree.update(j, 1);
                        break;
                    }
                }
            }
        }
        return ans.toString();
    }
}

class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        c = new int[n + 1];
    }

    public void update(int x, int delta) {
        while (x <= n) {
            c[x] += delta;
            x += lowbit(x);
        }
    }

    public int query(int x) {
        int s = 0;
        while (x > 0) {
            s += c[x];
            x -= lowbit(x);
        }
        return s;
    }

    public static int lowbit(int x) {
        return x & -x;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class BinaryIndexedTree {
public:
    int n;
    vector<int> c;

    BinaryIndexedTree(int _n)
        : n(_n)
        , c(_n + 1) {}

    void update(int x, int delta) {
        while (x <= n) {
            c[x] += delta;
            x += lowbit(x);
        }
    }

    int query(int x) {
        int s = 0;
        while (x > 0) {
            s += c[x];
            x -= lowbit(x);
        }
        return s;
    }

    int lowbit(int x) {
        return x & -x;
    }
};

class Solution {
public:
    string minInteger(string num, int k) {
        vector<queue<int>> pos(10);
        int n = num.size();
        for (int i = 0; i < n; ++i) pos[num[i] - '0'].push(i + 1);
        BinaryIndexedTree* tree = new BinaryIndexedTree(n);
        string ans = "";
        for (int i = 1; i <= n; ++i) {
            for (int v = 0; v < 10; ++v) {
                auto& q = pos[v];
                if (!q.empty()) {
                    int j = q.front();
                    int dist = tree->query(n) - tree->query(j) + j - i;
                    if (dist <= k) {
                        k -= dist;
                        q.pop();
                        ans += (v + '0');
                        tree->update(j, 1);
                        break;
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
type BinaryIndexedTree struct {
	n int
	c []int
}

func newBinaryIndexedTree(n int) *BinaryIndexedTree {
	c := make([]int, n+1)
	return &BinaryIndexedTree{n, c}
}

func (this *BinaryIndexedTree) lowbit(x int) int {
	return x & -x
}

func (this *BinaryIndexedTree) update(x, delta int) {
	for x <= this.n {
		this.c[x] += delta
		x += this.lowbit(x)
	}
}

func (this *BinaryIndexedTree) query(x int) int {
	s := 0
	for x > 0 {
		s += this.c[x]
		x -= this.lowbit(x)
	}
	return s
}

func minInteger(num string, k int) string {
	pos := make([][]int, 10)
	for i, c := range num {
		pos[c-'0'] = append(pos[c-'0'], i+1)
	}
	n := len(num)
	tree := newBinaryIndexedTree(n)
	var ans strings.Builder
	for i := 1; i <= n; i++ {
		for v := 0; v < 10; v++ {
			if len(pos[v]) > 0 {
				j := pos[v][0]
				dist := tree.query(n) - tree.query(j) + j - i
				if dist <= k {
					k -= dist
					pos[v] = pos[v][1:]
					ans.WriteByte(byte(v + '0'))
					tree.update(j, 1)
					break
				}
			}
		}
	}
	return ans.String()
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串&nbsp;<code>num</code> 和一个整数&nbsp;<code>k</code> 。其中，<code>num</code> 表示一个很大的整数，字符串中的每个字符依次对应整数上的各个 <strong>数位</strong> 。</p>

<p>你可以交换这个整数相邻数位的数字 <strong>最多</strong>&nbsp;<code>k</code>&nbsp;次。</p>

<p>请你返回你能得到的最小整数，并以字符串形式返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1505.Minimum%20Possible%20Integer%20After%20at%20Most%20K%20Adjacent%20Swaps%20On%20Digits/images/q4_1.jpg" style="height:40px; width:500px" /></p>

<pre>
<strong>输入：</strong>num = &quot;4321&quot;, k = 4
<strong>输出：</strong>&quot;1342&quot;
<strong>解释：</strong>4321 通过 4 次交换相邻数位得到最小整数的步骤如上图所示。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>num = &quot;100&quot;, k = 1
<strong>输出：</strong>&quot;010&quot;
<strong>解释：</strong>输出可以包含前导 0 ，但输入保证不会有前导 0 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>num = &quot;36789&quot;, k = 1000
<strong>输出：</strong>&quot;36789&quot;
<strong>解释：</strong>不需要做任何交换。
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>num = &quot;22&quot;, k = 22
<strong>输出：</strong>&quot;22&quot;
</pre>

<p><strong>示例 5：</strong></p>

<pre>
<strong>输入：</strong>num = &quot;9438957234785635408&quot;, k = 23
<strong>输出：</strong>&quot;0345989723478563548&quot;
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num.length &lt;= 30000</code></li>
	<li><code>num</code>&nbsp;只包含&nbsp;<strong>数字</strong>&nbsp;且不含有<strong>&nbsp;前导 0&nbsp;</strong>。</li>
	<li><code>1 &lt;= k &lt;= 10^9</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心算法 + 树状数组

树状数组，也称作“二叉索引树”（Binary Indexed Tree）或 Fenwick 树。 它可以高效地实现如下两个操作：

1. **单点更新** `update(x, delta)`： 把序列 x 位置的数加上一个值 delta；
1. **前缀和查询** `query(x)`：查询序列 `[1,...x]` 区间的区间和，即位置 x 的前缀和。

这两个操作的时间复杂度均为 $O(\log n)$。

对于本题，要想得到在 k 次交换内字典序最小整数，我们可以「贪心」地从 num 的最高位开始考虑，即希望 num 的最高位尽可能小。我们可以依次枚举 `0~9`，对于当前枚举到的数位 x，判断是否可以将某个位置上的 x 通过最多 k 次交换移动到最高位。由于每一次交换只能交换相邻位置的两个数字，因此将一个距离最高位为 s 的数位移动到最高位，需要 s 次交换操作。例如当 `num = 97620` 时，0 与最高位的距离为 4，我们可以通过 4 次交换操作把 0 移动到最高位。

这样的交换操作相当于把 0 移动到最高位，同时将 0 之前的所有数位向后移动了一位。

我们接下来考虑次高位。与最高位类似，我们选择最小的数位 x，使得它与次高位的距离不超过 k'，其中 k' 是 k 扣除最高位交换后的剩余次数。

考虑上面 `num = 97620` 的例子，此时我们应当选择 x=2 交换至次高位。然而我们发现，经过第一次的交换操作，2 所在的位置发生了变化！在 num 中，2 与次高位的距离为 2，而将 0 交换至最高位后，2 与次高位的距离增加了 1，变为 3。这是因为 0 从 2 的后面「转移」到了 2 的前面，使得 2 向后移动了一位。因此，x 实际所在的位置，等于 x 初始时在 num 中的位置，加上 x 后面发生交换的数位个数。这里的「x 后面发生交换的数位个数」，就可以使用**树状数组**进行维护。

解题思路如下：

1. 用 `pos[x]` 按照高位到低位的顺序，存放所有 x 在 num 中出现的位置；
1. 从高到低遍历每一个位置。对于位置 i，我们从小到大枚举交换的数位 x。`pos[x]` 中的首个元素即为与当前位置距离最近的 x 的位置：
    - 记 j 为 `pos[x]` 中的首元素，那么 `num[j]`（也即是 x）当前实际所在的位置，等于 j 加上 j 后面发现交换的数位个数。我们使用树状数组查询区间 `[j + 1, n]`，那么 num[j] 与位置 i 的实际距离 dist 为：`tree.query(n) - tree.query(j) + j - i`。
    - 如果 dist 小于等于 k，那么我们可以将 x 交换至位置 i。我们使用树状数组更新单点 j，将对应的值增加 1，表示该位置的数位发生了变换。随后更新 k 值，以及将 j 从 `pos[x]` 中移除。
1. 遍历结束后，我们就得到了答案。

<!-- tabs:start -->

#### Python3

```python
class BinaryIndexedTree:
    def __init__(self, n):
        self.n = n
        self.c = [0] * (n + 1)

    @staticmethod
    def lowbit(x):
        return x & -x

    def update(self, x, delta):
        while x <= self.n:
            self.c[x] += delta
            x += BinaryIndexedTree.lowbit(x)

    def query(self, x):
        s = 0
        while x:
            s += self.c[x]
            x -= BinaryIndexedTree.lowbit(x)
        return s


class Solution:
    def minInteger(self, num: str, k: int) -> str:
        pos = defaultdict(deque)
        for i, v in enumerate(num, 1):
            pos[int(v)].append(i)
        ans = []
        n = len(num)
        tree = BinaryIndexedTree(n)
        for i in range(1, n + 1):
            for v in range(10):
                q = pos[v]
                if q:
                    j = q[0]
                    dist = tree.query(n) - tree.query(j) + j - i
                    if dist <= k:
                        k -= dist
                        q.popleft()
                        ans.append(str(v))
                        tree.update(j, 1)
                        break
        return ''.join(ans)
```

#### Java

```java
class Solution {
    public String minInteger(String num, int k) {
        Queue<Integer>[] pos = new Queue[10];
        for (int i = 0; i < 10; ++i) {
            pos[i] = new ArrayDeque<>();
        }
        int n = num.length();
        for (int i = 0; i < n; ++i) {
            pos[num.charAt(i) - '0'].offer(i + 1);
        }
        StringBuilder ans = new StringBuilder();
        BinaryIndexedTree tree = new BinaryIndexedTree(n);
        for (int i = 1; i <= n; ++i) {
            for (int v = 0; v < 10; ++v) {
                if (!pos[v].isEmpty()) {
                    Queue<Integer> q = pos[v];
                    int j = q.peek();
                    int dist = tree.query(n) - tree.query(j) + j - i;
                    if (dist <= k) {
                        k -= dist;
                        q.poll();
                        ans.append(v);
                        tree.update(j, 1);
                        break;
                    }
                }
            }
        }
        return ans.toString();
    }
}

class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        c = new int[n + 1];
    }

    public void update(int x, int delta) {
        while (x <= n) {
            c[x] += delta;
            x += lowbit(x);
        }
    }

    public int query(int x) {
        int s = 0;
        while (x > 0) {
            s += c[x];
            x -= lowbit(x);
        }
        return s;
    }

    public static int lowbit(int x) {
        return x & -x;
    }
}
```

#### C++

```cpp
class BinaryIndexedTree {
public:
    int n;
    vector<int> c;

    BinaryIndexedTree(int _n)
        : n(_n)
        , c(_n + 1) {}

    void update(int x, int delta) {
        while (x <= n) {
            c[x] += delta;
            x += lowbit(x);
        }
    }

    int query(int x) {
        int s = 0;
        while (x > 0) {
            s += c[x];
            x -= lowbit(x);
        }
        return s;
    }

    int lowbit(int x) {
        return x & -x;
    }
};

class Solution {
public:
    string minInteger(string num, int k) {
        vector<queue<int>> pos(10);
        int n = num.size();
        for (int i = 0; i < n; ++i) pos[num[i] - '0'].push(i + 1);
        BinaryIndexedTree* tree = new BinaryIndexedTree(n);
        string ans = "";
        for (int i = 1; i <= n; ++i) {
            for (int v = 0; v < 10; ++v) {
                auto& q = pos[v];
                if (!q.empty()) {
                    int j = q.front();
                    int dist = tree->query(n) - tree->query(j) + j - i;
                    if (dist <= k) {
                        k -= dist;
                        q.pop();
                        ans += (v + '0');
                        tree->update(j, 1);
                        break;
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
type BinaryIndexedTree struct {
	n int
	c []int
}

func newBinaryIndexedTree(n int) *BinaryIndexedTree {
	c := make([]int, n+1)
	return &BinaryIndexedTree{n, c}
}

func (this *BinaryIndexedTree) lowbit(x int) int {
	return x & -x
}

func (this *BinaryIndexedTree) update(x, delta int) {
	for x <= this.n {
		this.c[x] += delta
		x += this.lowbit(x)
	}
}

func (this *BinaryIndexedTree) query(x int) int {
	s := 0
	for x > 0 {
		s += this.c[x]
		x -= this.lowbit(x)
	}
	return s
}

func minInteger(num string, k int) string {
	pos := make([][]int, 10)
	for i, c := range num {
		pos[c-'0'] = append(pos[c-'0'], i+1)
	}
	n := len(num)
	tree := newBinaryIndexedTree(n)
	var ans strings.Builder
	for i := 1; i <= n; i++ {
		for v := 0; v < 10; v++ {
			if len(pos[v]) > 0 {
				j := pos[v][0]
				dist := tree.query(n) - tree.query(j) + j - i
				if dist <= k {
					k -= dist
					pos[v] = pos[v][1:]
					ans.WriteByte(byte(v + '0'))
					tree.update(j, 1)
					break
				}
			}
		}
	}
	return ans.String()
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1506. 找到 N 叉树的根节点 🔒](https://leetcode.cn/problems/find-root-of-n-ary-tree){#1506}

{{< tabs "1506" >}}

{{% tab "python" %}}
```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []
"""


class Solution:
    def findRoot(self, tree: List['Node']) -> 'Node':
        x = 0
        for node in tree:
            x ^= node.val
            for child in node.children:
                x ^= child.val
        return next(node for node in tree if node.val == x)
```
{{% /tab %}}
{{% tab "java" %}}
```java
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;


    public Node() {
        children = new ArrayList<Node>();
    }

    public Node(int _val) {
        val = _val;
        children = new ArrayList<Node>();
    }

    public Node(int _val,ArrayList<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public Node findRoot(List<Node> tree) {
        int x = 0;
        for (Node node : tree) {
            x ^= node.val;
            for (Node child : node.children) {
                x ^= child.val;
            }
        }
        for (int i = 0;; ++i) {
            if (tree.get(i).val == x) {
                return tree.get(i);
            }
        }
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
    Node* findRoot(vector<Node*> tree) {
        int x = 0;
        for (Node* node : tree) {
            x ^= node->val;
            for (Node* child : node->children) {
                x ^= child->val;
            }
        }
        for (int i = 0;; ++i) {
            if (tree[i]->val == x) {
                return tree[i];
            }
        }
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

func findRoot(tree []*Node) *Node {
	x := 0
	for _, node := range tree {
		x ^= node.Val
		for _, child := range node.Children {
			x ^= child.Val
		}
	}
	for i := 0; ; i++ {
		if tree[i].Val == x {
			return tree[i]
		}
	}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for Node.
 * class Node {
 *     val: number
 *     children: Node[]
 *     constructor(val?: number, children?: Node[]) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.children = (children===undefined ? [] : children)
 *     }
 * }
 */

function findRoot(tree: Node[]): Node | null {
    let x = 0;
    for (const node of tree) {
        x ^= node.val;
        for (const child of node.children) {
            x ^= child.val;
        }
    }
    return tree.find(node => node.val === x) || null;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一棵&nbsp;<a href="https://leetcode.cn/explore/learn/card/n-ary-tree/" target="_blank">N 叉树</a>&nbsp;的所有节点在一个数组&nbsp;&nbsp;<code>Node[] tree</code>&nbsp;中，树中每个节点都有 <strong>唯一的值</strong> 。</p>

<p>找到并返回 N 叉树的 <strong>根节点 </strong>。</p>

<p>&nbsp;</p>

<p><strong>自定义测试：</strong></p>

<p><em>N 叉树的输入序列为其层序遍历序列，每组子节点用 null 分隔（见示例）。</em></p>

<p><em><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1506.Find%20Root%20of%20N-Ary%20Tree/images/sample_4_964.png" style="width:300px" /></em></p>

<p>上图中的 N 叉树的序列化描述为 <code>[1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]</code> 。</p>

<p><strong>测试将以下列方式进行：</strong></p>

<ul>
	<li>输入数据的形式为树的序列化描述。</li>
	<li>驱动程序代码将根据序列化的输入数据构造树，并以任意顺序将每个 <code>Node</code> 对象放入一个数组中。</li>
	<li>驱动程序代码将把数组传递给 <code>findRoot</code> ，你所编写的函数应该在数组中查找并返回根 <code>Node</code> 对象。</li>
	<li>驱动程序代码将接受返回的 <code>Node</code> 对象并对其进行序列化。如果序列化的结果和输入数据 <strong>相同</strong> ，则测试 <strong>通过</strong> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1506.Find%20Root%20of%20N-Ary%20Tree/images/narytreeexample.png" style="width:250px" /></p>

<pre>
<strong>输入：</strong>tree = [1,null,3,2,4,null,5,6]
<strong>输出：</strong>[1,null,3,2,4,null,5,6]
<strong>解释：</strong>来自输入数据的树如上所示。
驱动程序代码创建树，并以任意顺序向 findRoot 提供 Node 对象。
例如，传递的数组可以是 [Node(5),Node(4),Node(3),Node(6),Node(2),Node(1)] 或 [Node(2),Node(6),Node(1),Node(3),Node(5),Node(4)] 。
findRoot 函数应该返回根 Node(1) ，驱动程序代码将序列化它并与输入数据进行比较。
输入数据和序列化的 Node(1) 相同，因此测试通过。</pre>

<p><strong class="example">示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1506.Find%20Root%20of%20N-Ary%20Tree/images/sample_4_964.png" style="height:241px; width:296px" /></p>

<pre>
<strong>输入：</strong>tree = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
<strong>输出：</strong>[1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>节点的总个数在&nbsp;<code>[1,&nbsp;5*10^4]</code>&nbsp;之间。</li>
	<li>每个节点都有唯一的值。</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong></p>

<ul>
	<li>你可以使用 O(1) 额外内存空间且 O(n) 时间复杂度的算法来找到该树的根节点吗？</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：位运算

对于一棵 N 叉树的节点，如果该节点是根节点，那么该节点只会出现一次在数组 `tree` 中；而如果该节点不是根节点，那么该节点会出现两次，一次在数组 `tree` 中，一次在该节点的父节点的 `children` 数组中。

因此，我们可以遍历数组 `tree`，计算每个节点的值以及其所有子节点的值的异或和，记录在变量 $x$ 中。遍历结束后，我们得到的 $x$ 就是根节点的值。

接下来，我们再遍历数组 `tree`，找到值为 $x$ 的节点，即为根节点，返回即可。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为数组 `tree` 的长度。

<!-- tabs:start -->

#### Python3

```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []
"""


class Solution:
    def findRoot(self, tree: List['Node']) -> 'Node':
        x = 0
        for node in tree:
            x ^= node.val
            for child in node.children:
                x ^= child.val
        return next(node for node in tree if node.val == x)
```

#### Java

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;


    public Node() {
        children = new ArrayList<Node>();
    }

    public Node(int _val) {
        val = _val;
        children = new ArrayList<Node>();
    }

    public Node(int _val,ArrayList<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public Node findRoot(List<Node> tree) {
        int x = 0;
        for (Node node : tree) {
            x ^= node.val;
            for (Node child : node.children) {
                x ^= child.val;
            }
        }
        for (int i = 0;; ++i) {
            if (tree.get(i).val == x) {
                return tree.get(i);
            }
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
    Node* findRoot(vector<Node*> tree) {
        int x = 0;
        for (Node* node : tree) {
            x ^= node->val;
            for (Node* child : node->children) {
                x ^= child->val;
            }
        }
        for (int i = 0;; ++i) {
            if (tree[i]->val == x) {
                return tree[i];
            }
        }
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

func findRoot(tree []*Node) *Node {
	x := 0
	for _, node := range tree {
		x ^= node.Val
		for _, child := range node.Children {
			x ^= child.Val
		}
	}
	for i := 0; ; i++ {
		if tree[i].Val == x {
			return tree[i]
		}
	}
}
```

#### TypeScript

```ts
/**
 * Definition for Node.
 * class Node {
 *     val: number
 *     children: Node[]
 *     constructor(val?: number, children?: Node[]) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.children = (children===undefined ? [] : children)
 *     }
 * }
 */

function findRoot(tree: Node[]): Node | null {
    let x = 0;
    for (const node of tree) {
        x ^= node.val;
        for (const child of node.children) {
            x ^= child.val;
        }
    }
    return tree.find(node => node.val === x) || null;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1507. 转变日期格式](https://leetcode.cn/problems/reformat-date){#1507}

{{< tabs "1507" >}}

{{% tab "python" %}}
```python
class Solution:
    def reformatDate(self, date: str) -> str:
        s = date.split()
        s.reverse()
        months = " JanFebMarAprMayJunJulAugSepOctNovDec"
        s[1] = str(months.index(s[1]) // 3 + 1).zfill(2)
        s[2] = s[2][:-2].zfill(2)
        return "-".join(s)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String reformatDate(String date) {
        var s = date.split(" ");
        String months = " JanFebMarAprMayJunJulAugSepOctNovDec";
        int day = Integer.parseInt(s[0].substring(0, s[0].length() - 2));
        int month = months.indexOf(s[1]) / 3 + 1;
        return String.format("%s-%02d-%02d", s[2], month, day);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string reformatDate(string date) {
        string months = " JanFebMarAprMayJunJulAugSepOctNovDec";
        stringstream ss(date);
        string year, month, t;
        int day;
        ss >> day >> t >> month >> year;
        month = to_string(months.find(month) / 3 + 1);
        return year + "-" + (month.size() == 1 ? "0" + month : month) + "-" + (day > 9 ? "" : "0") + to_string(day);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func reformatDate(date string) string {
	s := strings.Split(date, " ")
	day, _ := strconv.Atoi(s[0][:len(s[0])-2])
	months := " JanFebMarAprMayJunJulAugSepOctNovDec"
	month := strings.Index(months, s[1])/3 + 1
	year, _ := strconv.Atoi(s[2])
	return fmt.Sprintf("%d-%02d-%02d", year, month, day)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function reformatDate(date: string): string {
    const s = date.split(' ');
    const months = ' JanFebMarAprMayJunJulAugSepOctNovDec';
    const day = parseInt(s[0].substring(0, s[0].length - 2));
    const month = Math.floor(months.indexOf(s[1]) / 3) + 1;
    return `${s[2]}-${month.toString().padStart(2, '0')}-${day.toString().padStart(2, '0')}`;
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param String $date
     * @return String
     */
    function reformatDate($date) {
        $arr = explode(' ', $date);
        $months = [
            'Jan' => '01',
            'Feb' => '02',
            'Mar' => '03',
            'Apr' => '04',
            'May' => '05',
            'Jun' => '06',
            'Jul' => '07',
            'Aug' => '08',
            'Sep' => '09',
            'Oct' => '10',
            'Nov' => '11',
            'Dec' => '12',
        ];
        $year = $arr[2];
        $month = $months[$arr[1]];
        $day = intval($arr[0]);
        if ($day > 0 && $day < 10) {
            $day = '0' . $day;
        }
        return $year . '-' . $month . '-' . $day;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串&nbsp;<code>date</code>&nbsp;，它的格式为&nbsp;<code>Day Month Year</code>&nbsp;，其中：</p>

<ul>
	<li><code>Day</code>&nbsp;是集合&nbsp;<code>{&quot;1st&quot;, &quot;2nd&quot;, &quot;3rd&quot;, &quot;4th&quot;, ..., &quot;30th&quot;, &quot;31st&quot;}</code>&nbsp;中的一个元素。</li>
	<li><code>Month</code>&nbsp;是集合&nbsp;<code>{&quot;Jan&quot;, &quot;Feb&quot;, &quot;Mar&quot;, &quot;Apr&quot;, &quot;May&quot;, &quot;Jun&quot;, &quot;Jul&quot;, &quot;Aug&quot;, &quot;Sep&quot;, &quot;Oct&quot;, &quot;Nov&quot;, &quot;Dec&quot;}</code>&nbsp;中的一个元素。</li>
	<li><code>Year</code>&nbsp;的范围在 ​<code>[1900, 2100]</code>&nbsp;之间。</li>
</ul>

<p>请你将字符串转变为&nbsp;<code>YYYY-MM-DD</code>&nbsp;的格式，其中：</p>

<ul>
	<li><code>YYYY</code>&nbsp;表示 4 位的年份。</li>
	<li><code>MM</code>&nbsp;表示 2 位的月份。</li>
	<li><code>DD</code>&nbsp;表示 2 位的天数。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>date = &quot;20th Oct 2052&quot;
<strong>输出：</strong>&quot;2052-10-20&quot;
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>date = &quot;6th Jun 1933&quot;
<strong>输出：</strong>&quot;1933-06-06&quot;
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>date = &quot;26th May 1960&quot;
<strong>输出：</strong>&quot;1960-05-26&quot;
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>给定日期保证是合法的，所以不需要处理异常输入。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

将字符串按空格分割为三个部分，分别为 `day`、`month` 和 `year`，然后拼接为 `YYYY-MM-DD` 的格式。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def reformatDate(self, date: str) -> str:
        s = date.split()
        s.reverse()
        months = " JanFebMarAprMayJunJulAugSepOctNovDec"
        s[1] = str(months.index(s[1]) // 3 + 1).zfill(2)
        s[2] = s[2][:-2].zfill(2)
        return "-".join(s)
```

#### Java

```java
class Solution {
    public String reformatDate(String date) {
        var s = date.split(" ");
        String months = " JanFebMarAprMayJunJulAugSepOctNovDec";
        int day = Integer.parseInt(s[0].substring(0, s[0].length() - 2));
        int month = months.indexOf(s[1]) / 3 + 1;
        return String.format("%s-%02d-%02d", s[2], month, day);
    }
}
```

#### C++

```cpp
class Solution {
public:
    string reformatDate(string date) {
        string months = " JanFebMarAprMayJunJulAugSepOctNovDec";
        stringstream ss(date);
        string year, month, t;
        int day;
        ss >> day >> t >> month >> year;
        month = to_string(months.find(month) / 3 + 1);
        return year + "-" + (month.size() == 1 ? "0" + month : month) + "-" + (day > 9 ? "" : "0") + to_string(day);
    }
};
```

#### Go

```go
func reformatDate(date string) string {
	s := strings.Split(date, " ")
	day, _ := strconv.Atoi(s[0][:len(s[0])-2])
	months := " JanFebMarAprMayJunJulAugSepOctNovDec"
	month := strings.Index(months, s[1])/3 + 1
	year, _ := strconv.Atoi(s[2])
	return fmt.Sprintf("%d-%02d-%02d", year, month, day)
}
```

#### TypeScript

```ts
function reformatDate(date: string): string {
    const s = date.split(' ');
    const months = ' JanFebMarAprMayJunJulAugSepOctNovDec';
    const day = parseInt(s[0].substring(0, s[0].length - 2));
    const month = Math.floor(months.indexOf(s[1]) / 3) + 1;
    return `${s[2]}-${month.toString().padStart(2, '0')}-${day.toString().padStart(2, '0')}`;
}
```

#### PHP

```php
class Solution {
    /**
     * @param String $date
     * @return String
     */
    function reformatDate($date) {
        $arr = explode(' ', $date);
        $months = [
            'Jan' => '01',
            'Feb' => '02',
            'Mar' => '03',
            'Apr' => '04',
            'May' => '05',
            'Jun' => '06',
            'Jul' => '07',
            'Aug' => '08',
            'Sep' => '09',
            'Oct' => '10',
            'Nov' => '11',
            'Dec' => '12',
        ];
        $year = $arr[2];
        $month = $months[$arr[1]];
        $day = intval($arr[0]);
        if ($day > 0 && $day < 10) {
            $day = '0' . $day;
        }
        return $year . '-' . $month . '-' . $day;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1508. 子数组和排序后的区间和](https://leetcode.cn/problems/range-sum-of-sorted-subarray-sums){#1508}

{{< tabs "1508" >}}

{{% tab "python" %}}
```python
class Solution:
    def rangeSum(self, nums: List[int], n: int, left: int, right: int) -> int:
        arr = []
        for i in range(n):
            s = 0
            for j in range(i, n):
                s += nums[j]
                arr.append(s)
        arr.sort()
        mod = 10**9 + 7
        return sum(arr[left - 1 : right]) % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int rangeSum(int[] nums, int n, int left, int right) {
        int[] arr = new int[n * (n + 1) / 2];
        for (int i = 0, k = 0; i < n; ++i) {
            int s = 0;
            for (int j = i; j < n; ++j) {
                s += nums[j];
                arr[k++] = s;
            }
        }
        Arrays.sort(arr);
        int ans = 0;
        final int mod = (int) 1e9 + 7;
        for (int i = left - 1; i < right; ++i) {
            ans = (ans + arr[i]) % mod;
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
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int arr[n * (n + 1) / 2];
        for (int i = 0, k = 0; i < n; ++i) {
            int s = 0;
            for (int j = i; j < n; ++j) {
                s += nums[j];
                arr[k++] = s;
            }
        }
        sort(arr, arr + n * (n + 1) / 2);
        int ans = 0;
        const int mod = 1e9 + 7;
        for (int i = left - 1; i < right; ++i) {
            ans = (ans + arr[i]) % mod;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func rangeSum(nums []int, n int, left int, right int) (ans int) {
	var arr []int
	for i := 0; i < n; i++ {
		s := 0
		for j := i; j < n; j++ {
			s += nums[j]
			arr = append(arr, s)
		}
	}
	sort.Ints(arr)
	const mod int = 1e9 + 7
	for _, x := range arr[left-1 : right] {
		ans = (ans + x) % mod
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function rangeSum(nums: number[], n: number, left: number, right: number): number {
    let arr = Array((n * (n + 1)) / 2).fill(0);
    const mod = 10 ** 9 + 7;

    for (let i = 0, s = 0, k = 0; i < n; i++, s = 0) {
        for (let j = i; j < n; j++, k++) {
            s += nums[j];
            arr[k] = s;
        }
    }

    arr = arr.sort((a, b) => a - b).slice(left - 1, right);
    return arr.reduce((acc, cur) => (acc + cur) % mod, 0);
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function rangeSum(nums, n, left, right) {
    let arr = Array((n * (n + 1)) / 2).fill(0);
    const mod = 10 ** 9 + 7;

    for (let i = 0, s = 0, k = 0; i < n; i++, s = 0) {
        for (let j = i; j < n; j++, k++) {
            s += nums[j];
            arr[k] = s;
        }
    }

    arr = arr.sort((a, b) => a - b).slice(left - 1, right);
    return arr.reduce((acc, cur) => acc + cur, 0) % mod;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个数组&nbsp;<code>nums</code>&nbsp;，它包含&nbsp;<code>n</code>&nbsp;个正整数。你需要计算所有非空连续子数组的和，并将它们按升序排序，得到一个新的包含&nbsp;<code>n * (n + 1) / 2</code>&nbsp;个数字的数组。</p>

<p>请你返回在新数组中下标为<em>&nbsp;</em><code>left</code>&nbsp;到&nbsp;<code>right</code> <strong>（下标从 1 开始）</strong>的所有数字和（包括左右端点）。由于答案可能很大，请你将它对 10^9 + 7 取模后返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,4], n = 4, left = 1, right = 5
<strong>输出：</strong>13 
<strong>解释：</strong>所有的子数组和为 1, 3, 6, 10, 2, 5, 9, 3, 7, 4 。将它们升序排序后，我们得到新的数组 [1, 2, 3, 3, 4, 5, 6, 7, 9, 10] 。下标从 le = 1 到 ri = 5 的和为 1 + 2 + 3 + 3 + 4 = 13 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,4], n = 4, left = 3, right = 4
<strong>输出：</strong>6
<strong>解释：</strong>给定数组与示例 1 一样，所以新数组为 [1, 2, 3, 3, 4, 5, 6, 7, 9, 10] 。下标从 le = 3 到 ri = 4 的和为 3 + 3 = 6 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,4], n = 4, left = 1, right = 10
<strong>输出：</strong>50
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10^3</code></li>
	<li><code>nums.length == n</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
	<li><code>1 &lt;= left &lt;= right&nbsp;&lt;= n * (n + 1) / 2</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以按照题目的要求，生成数组 $\textit{arr}$，然后对数组进行排序，最后求出 $[\textit{left}-1, \textit{right}-1]$ 范围的所有元素的和，得到结果。

时间复杂度 $O(n^2 \times \log n)$，空间复杂度 $O(n^2)$。其中 $n$ 为题目给定的数组长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def rangeSum(self, nums: List[int], n: int, left: int, right: int) -> int:
        arr = []
        for i in range(n):
            s = 0
            for j in range(i, n):
                s += nums[j]
                arr.append(s)
        arr.sort()
        mod = 10**9 + 7
        return sum(arr[left - 1 : right]) % mod
```

#### Java

```java
class Solution {
    public int rangeSum(int[] nums, int n, int left, int right) {
        int[] arr = new int[n * (n + 1) / 2];
        for (int i = 0, k = 0; i < n; ++i) {
            int s = 0;
            for (int j = i; j < n; ++j) {
                s += nums[j];
                arr[k++] = s;
            }
        }
        Arrays.sort(arr);
        int ans = 0;
        final int mod = (int) 1e9 + 7;
        for (int i = left - 1; i < right; ++i) {
            ans = (ans + arr[i]) % mod;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int arr[n * (n + 1) / 2];
        for (int i = 0, k = 0; i < n; ++i) {
            int s = 0;
            for (int j = i; j < n; ++j) {
                s += nums[j];
                arr[k++] = s;
            }
        }
        sort(arr, arr + n * (n + 1) / 2);
        int ans = 0;
        const int mod = 1e9 + 7;
        for (int i = left - 1; i < right; ++i) {
            ans = (ans + arr[i]) % mod;
        }
        return ans;
    }
};
```

#### Go

```go
func rangeSum(nums []int, n int, left int, right int) (ans int) {
	var arr []int
	for i := 0; i < n; i++ {
		s := 0
		for j := i; j < n; j++ {
			s += nums[j]
			arr = append(arr, s)
		}
	}
	sort.Ints(arr)
	const mod int = 1e9 + 7
	for _, x := range arr[left-1 : right] {
		ans = (ans + x) % mod
	}
	return
}
```

#### TypeScript

```ts
function rangeSum(nums: number[], n: number, left: number, right: number): number {
    let arr = Array((n * (n + 1)) / 2).fill(0);
    const mod = 10 ** 9 + 7;

    for (let i = 0, s = 0, k = 0; i < n; i++, s = 0) {
        for (let j = i; j < n; j++, k++) {
            s += nums[j];
            arr[k] = s;
        }
    }

    arr = arr.sort((a, b) => a - b).slice(left - 1, right);
    return arr.reduce((acc, cur) => (acc + cur) % mod, 0);
}
```

#### JavaScript

```js
function rangeSum(nums, n, left, right) {
    let arr = Array((n * (n + 1)) / 2).fill(0);
    const mod = 10 ** 9 + 7;

    for (let i = 0, s = 0, k = 0; i < n; i++, s = 0) {
        for (let j = i; j < n; j++, k++) {
            s += nums[j];
            arr[k] = s;
        }
    }

    arr = arr.sort((a, b) => a - b).slice(left - 1, right);
    return arr.reduce((acc, cur) => acc + cur, 0) % mod;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1509. 三次操作后最大值与最小值的最小差](https://leetcode.cn/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves){#1509}

{{< tabs "1509" >}}

{{% tab "python" %}}
```python
class Solution:
    def minDifference(self, nums: List[int]) -> int:
        n = len(nums)
        if n < 5:
            return 0
        nums.sort()
        ans = inf
        for l in range(4):
            r = 3 - l
            ans = min(ans, nums[n - 1 - r] - nums[l])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minDifference(int[] nums) {
        int n = nums.length;
        if (n < 5) {
            return 0;
        }
        Arrays.sort(nums);
        long ans = 1L << 60;
        for (int l = 0; l <= 3; ++l) {
            int r = 3 - l;
            ans = Math.min(ans, (long) nums[n - 1 - r] - nums[l]);
        }
        return (int) ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n < 5) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        long long ans = 1L << 60;
        for (int l = 0; l <= 3; ++l) {
            int r = 3 - l;
            ans = min(ans, 1LL * nums[n - 1 - r] - nums[l]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minDifference(nums []int) int {
	n := len(nums)
	if n < 5 {
		return 0
	}
	sort.Ints(nums)
	ans := 1 << 60
	for l := 0; l <= 3; l++ {
		r := 3 - l
		ans = min(ans, nums[n-1-r]-nums[l])
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minDifference(nums: number[]): number {
    if (nums.length < 5) {
        return 0;
    }
    nums.sort((a, b) => a - b);
    let ans = Number.POSITIVE_INFINITY;
    for (let i = 0; i < 4; i++) {
        ans = Math.min(ans, nums.at(i - 4)! - nums[i]);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var minDifference = function (nums) {
    if (nums.length < 5) {
        return 0;
    }
    nums.sort((a, b) => a - b);
    let ans = Number.POSITIVE_INFINITY;
    for (let i = 0; i < 4; i++) {
        ans = Math.min(ans, nums.at(i - 4) - nums[i]);
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

<p>给你一个数组&nbsp;<code>nums</code>&nbsp;。</p>

<p>每次操作你可以选择&nbsp;<code>nums</code>&nbsp;中的任意一个元素并将它改成 <strong>任意值</strong> 。</p>

<p>在&nbsp;<strong>执行最多三次移动后&nbsp;</strong>，返回&nbsp;<code>nums</code>&nbsp;中最大值与最小值的最小差值。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [5,3,2,4]
<strong>输出：</strong>0
<strong>解释：</strong>我们最多可以走 3 步。
第一步，将 2 变为 3 。 nums 变成 [5,3,3,4] 。
第二步，将 4 改为 3 。 nums 变成 [5,3,3,3] 。
第三步，将 5 改为 3 。 nums 变成 [3,3,3,3] 。
执行 3 次移动后，最小值和最大值之间的差值为 3 - 3 = 0 。</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,5,0,10,14]
<strong>输出：</strong>1
<strong>解释：</strong>我们最多可以走 3 步。
第一步，将 5 改为 0 。 nums变成 [1,0,0,10,14] 。
第二步，将 10 改为 0 。 nums变成 [1,0,0,0,14] 。
第三步，将 14 改为 1 。 nums变成 [1,0,0,0,1] 。
执行 3 步后，最小值和最大值之间的差值为 1 - 0 = 1 。
可以看出，没有办法可以在 3 步内使差值变为0。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,100,20]
<strong>输出：</strong>0
<strong>解释：</strong>我们最多可以走 3 步。
第一步，将 100 改为 7 。 nums 变成 [3,7,20] 。
第二步，将 20 改为 7 。 nums 变成 [3,7,7] 。
第三步，将 3 改为 7 。 nums 变成 [7,7,7] 。
执行 3 步后，最小值和最大值之间的差值是 7 - 7 = 0。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 贪心

我们可以先判断数组长度是否小于 $5$，如果小于 $5$，那么直接返回 $0$。

否则，我们将数组排序，然后贪心地选择数组左边最小的 $l=[0,..3]$ 个数和右边最小的 $r = 3 - l$ 个数，取其中最小的差值 $nums[n - 1 - r] - nums[l]$ 即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为数组 `nums` 的长度。

相似题目：

-   [2567. 修改两个元素的最小分数](https://github.com/doocs/leetcode/blob/main/solution/2500-2599/2567.Minimum%20Score%20by%20Changing%20Two%20Elements/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minDifference(self, nums: List[int]) -> int:
        n = len(nums)
        if n < 5:
            return 0
        nums.sort()
        ans = inf
        for l in range(4):
            r = 3 - l
            ans = min(ans, nums[n - 1 - r] - nums[l])
        return ans
```

#### Java

```java
class Solution {
    public int minDifference(int[] nums) {
        int n = nums.length;
        if (n < 5) {
            return 0;
        }
        Arrays.sort(nums);
        long ans = 1L << 60;
        for (int l = 0; l <= 3; ++l) {
            int r = 3 - l;
            ans = Math.min(ans, (long) nums[n - 1 - r] - nums[l]);
        }
        return (int) ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n < 5) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        long long ans = 1L << 60;
        for (int l = 0; l <= 3; ++l) {
            int r = 3 - l;
            ans = min(ans, 1LL * nums[n - 1 - r] - nums[l]);
        }
        return ans;
    }
};
```

#### Go

```go
func minDifference(nums []int) int {
	n := len(nums)
	if n < 5 {
		return 0
	}
	sort.Ints(nums)
	ans := 1 << 60
	for l := 0; l <= 3; l++ {
		r := 3 - l
		ans = min(ans, nums[n-1-r]-nums[l])
	}
	return ans
}
```

#### TypeScript

```ts
function minDifference(nums: number[]): number {
    if (nums.length < 5) {
        return 0;
    }
    nums.sort((a, b) => a - b);
    let ans = Number.POSITIVE_INFINITY;
    for (let i = 0; i < 4; i++) {
        ans = Math.min(ans, nums.at(i - 4)! - nums[i]);
    }
    return ans;
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var minDifference = function (nums) {
    if (nums.length < 5) {
        return 0;
    }
    nums.sort((a, b) => a - b);
    let ans = Number.POSITIVE_INFINITY;
    for (let i = 0; i < 4; i++) {
        ans = Math.min(ans, nums.at(i - 4) - nums[i]);
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
