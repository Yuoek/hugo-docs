---
title: "1450_在既定时间做作业的学生人数"
date: 2025-10-08T18:37:18+08:00
weight: 6
tags: [二叉树, 位运算, 几何, 动态规划, 双指针, 哈希表, 字符串, 字符串匹配, 广度优先搜索, 排序, 数学, 数据库, 数组, 树, 深度优先搜索, 滑动窗口]
---

{{< markmap >}}
### [1450_在既定时间做作业的学生人数](#1450)
#### [数组](#1450)
### [1451_重新排列句子中的单词](#1451)
#### [字符串](#1451)
#### [排序](#1451)
### [1452_收藏清单](#1452)
#### [数组](#1452)
#### [哈希表](#1452)
#### [字符串](#1452)
### [1453_圆形靶内的最大飞镖数量](#1453)
#### [几何](#1453)
#### [数组](#1453)
#### [数学](#1453)
### [1454_活跃用户 🔒](#1454)
#### [数据库](#1454)
### [1455_检查单词是否为句中其他单词的前缀](#1455)
#### [双指针](#1455)
#### [字符串](#1455)
#### [字符串匹配](#1455)
### [1456_定长子串中元音的最大数目](#1456)
#### [字符串](#1456)
#### [滑动窗口](#1456)
### [1457_二叉树中的伪回文路径](#1457)
#### [位运算](#1457)
#### [树](#1457)
#### [深度优先搜索](#1457)
#### [广度优先搜索](#1457)
#### [二叉树](#1457)
### [1458_两个子序列的最大点积](#1458)
#### [数组](#1458)
#### [动态规划](#1458)
### [1459_矩形面积 🔒](#1459)
#### [数据库](#1459)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1450_在既定时间做作业的学生人数
___
#### 数组
---
### 1451_重新排列句子中的单词
___
#### 字符串
___
#### 排序
---
### 1452_收藏清单
___
#### 数组
___
#### 哈希表
___
#### 字符串
---
### 1453_圆形靶内的最大飞镖数量
___
#### 几何
___
#### 数组
___
#### 数学
---
### 1454_活跃用户 🔒
___
#### 数据库
---
### 1455_检查单词是否为句中其他单词的前缀
___
#### 双指针
___
#### 字符串
___
#### 字符串匹配
---
### 1456_定长子串中元音的最大数目
___
#### 字符串
___
#### 滑动窗口
---
### 1457_二叉树中的伪回文路径
___
#### 位运算
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 二叉树
---
### 1458_两个子序列的最大点积
___
#### 数组
___
#### 动态规划
---
### 1459_矩形面积 🔒
___
#### 数据库
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二叉树 | 位运算 | 几何 |
| 动态规划 | 双指针 | 哈希表 |
| 字符串 | 字符串匹配 | 广度优先搜索 |
| 排序 | 数学 | 数据库 |
| 数组 | 树 | 深度优先搜索 |
| 滑动窗口 |  |  |

# [1450. 在既定时间做作业的学生人数](https://leetcode.cn/problems/number-of-students-doing-homework-at-a-given-time){#1450}

{{< tabs "1450" >}}

{{% tab "python" %}}
```python
class Solution:
    def busyStudent(
        self, startTime: List[int], endTime: List[int], queryTime: int
    ) -> int:
        return sum(x <= queryTime <= y for x, y in zip(startTime, endTime))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int busyStudent(int[] startTime, int[] endTime, int queryTime) {
        int ans = 0;
        for (int i = 0; i < startTime.length; ++i) {
            if (startTime[i] <= queryTime && queryTime <= endTime[i]) {
                ++ans;
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
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int ans = 0;
        for (int i = 0; i < startTime.size(); ++i) {
            ans += startTime[i] <= queryTime && queryTime <= endTime[i];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func busyStudent(startTime []int, endTime []int, queryTime int) (ans int) {
	for i, x := range startTime {
		if x <= queryTime && queryTime <= endTime[i] {
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function busyStudent(startTime: number[], endTime: number[], queryTime: number): number {
    const n = startTime.length;
    let ans = 0;
    for (let i = 0; i < n; i++) {
        if (startTime[i] <= queryTime && queryTime <= endTime[i]) {
            ans++;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn busy_student(start_time: Vec<i32>, end_time: Vec<i32>, query_time: i32) -> i32 {
        let mut ans = 0;
        for i in 0..start_time.len() {
            if start_time[i] <= query_time && end_time[i] >= query_time {
                ans += 1;
            }
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int busyStudent(int* startTime, int startTimeSize, int* endTime, int endTimeSize, int queryTime) {
    int ans = 0;
    for (int i = 0; i < startTimeSize; i++) {
        if (startTime[i] <= queryTime && endTime[i] >= queryTime) {
            ans++;
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

<p>给你两个整数数组 <code>startTime</code>（开始时间）和 <code>endTime</code>（结束时间），并指定一个整数 <code>queryTime</code> 作为查询时间。</p>

<p>已知，第 <code>i</code> 名学生在 <code>startTime[i]</code> 时开始写作业并于 <code>endTime[i]</code> 时完成作业。</p>

<p>请返回在查询时间 <code>queryTime</code> 时正在做作业的学生人数。形式上，返回能够使 <code>queryTime</code> 处于区间 <code>[startTime[i], endTime[i]]</code>（含）的学生人数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>startTime = [1,2,3], endTime = [3,2,7], queryTime = 4
<strong>输出：</strong>1
<strong>解释：</strong>一共有 3 名学生。
第一名学生在时间 1 开始写作业，并于时间 3 完成作业，在时间 4 没有处于做作业的状态。
第二名学生在时间 2 开始写作业，并于时间 2 完成作业，在时间 4 没有处于做作业的状态。
第三名学生在时间 3 开始写作业，预计于时间 7 完成作业，这是是唯一一名在时间 4 时正在做作业的学生。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>startTime = [4], endTime = [4], queryTime = 4
<strong>输出：</strong>1
<strong>解释：</strong>在查询时间只有一名学生在做作业。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>startTime = [4], endTime = [4], queryTime = 5
<strong>输出：</strong>0
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>startTime = [1,1,1,1], endTime = [1,3,2,4], queryTime = 7
<strong>输出：</strong>0
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>startTime = [9,8,7,6,5,4,3,2,1], endTime = [10,10,10,10,10,10,10,10,10], queryTime = 5
<strong>输出：</strong>5
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>startTime.length == endTime.length</code></li>
	<li><code>1 &lt;= startTime.length &lt;= 100</code></li>
	<li><code>1 &lt;= startTime[i] &lt;= endTime[i] &lt;= 1000</code></li>
	<li><code>1 &lt;=&nbsp;queryTime &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：直接遍历

我们可以直接遍历两个数组，对于每个学生，判断 $\textit{queryTime}$ 是否在他们的作业时间区间内，若是，答案加一。

遍历结束后，返回答案即可。

时间复杂度 $O(n)$，其中 $n$ 为学生数量。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def busyStudent(
        self, startTime: List[int], endTime: List[int], queryTime: int
    ) -> int:
        return sum(x <= queryTime <= y for x, y in zip(startTime, endTime))
```

#### Java

```java
class Solution {
    public int busyStudent(int[] startTime, int[] endTime, int queryTime) {
        int ans = 0;
        for (int i = 0; i < startTime.length; ++i) {
            if (startTime[i] <= queryTime && queryTime <= endTime[i]) {
                ++ans;
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
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int ans = 0;
        for (int i = 0; i < startTime.size(); ++i) {
            ans += startTime[i] <= queryTime && queryTime <= endTime[i];
        }
        return ans;
    }
};
```

#### Go

```go
func busyStudent(startTime []int, endTime []int, queryTime int) (ans int) {
	for i, x := range startTime {
		if x <= queryTime && queryTime <= endTime[i] {
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function busyStudent(startTime: number[], endTime: number[], queryTime: number): number {
    const n = startTime.length;
    let ans = 0;
    for (let i = 0; i < n; i++) {
        if (startTime[i] <= queryTime && queryTime <= endTime[i]) {
            ans++;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn busy_student(start_time: Vec<i32>, end_time: Vec<i32>, query_time: i32) -> i32 {
        let mut ans = 0;
        for i in 0..start_time.len() {
            if start_time[i] <= query_time && end_time[i] >= query_time {
                ans += 1;
            }
        }
        ans
    }
}
```

#### C

```c
int busyStudent(int* startTime, int startTimeSize, int* endTime, int endTimeSize, int queryTime) {
    int ans = 0;
    for (int i = 0; i < startTimeSize; i++) {
        if (startTime[i] <= queryTime && endTime[i] >= queryTime) {
            ans++;
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

# [1451. 重新排列句子中的单词](https://leetcode.cn/problems/rearrange-words-in-a-sentence){#1451}

{{< tabs "1451" >}}

{{% tab "python" %}}
```python
class Solution:
    def arrangeWords(self, text: str) -> str:
        words = text.split()
        words[0] = words[0].lower()
        words.sort(key=len)
        words[0] = words[0].title()
        return " ".join(words)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String arrangeWords(String text) {
        String[] words = text.split(" ");
        words[0] = words[0].toLowerCase();
        Arrays.sort(words, Comparator.comparingInt(String::length));
        words[0] = words[0].substring(0, 1).toUpperCase() + words[0].substring(1);
        return String.join(" ", words);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string arrangeWords(string text) {
        vector<string> words;
        stringstream ss(text);
        string t;
        while (ss >> t) {
            words.push_back(t);
        }
        words[0][0] = tolower(words[0][0]);
        stable_sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });
        string ans = "";
        for (auto& s : words) {
            ans += s + " ";
        }
        ans.pop_back();
        ans[0] = toupper(ans[0]);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func arrangeWords(text string) string {
	words := strings.Split(text, " ")
	words[0] = strings.ToLower(words[0])
	sort.SliceStable(words, func(i, j int) bool { return len(words[i]) < len(words[j]) })
	words[0] = strings.Title(words[0])
	return strings.Join(words, " ")
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function arrangeWords(text: string): string {
    let words: string[] = text.split(' ');
    words[0] = words[0].toLowerCase();
    words.sort((a, b) => a.length - b.length);
    words[0] = words[0].charAt(0).toUpperCase() + words[0].slice(1);
    return words.join(' ');
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} text
 * @return {string}
 */
var arrangeWords = function (text) {
    let arr = text.split(' ');
    arr[0] = arr[0].toLocaleLowerCase();
    arr.sort((a, b) => a.length - b.length);
    arr[0] = arr[0][0].toLocaleUpperCase() + arr[0].substr(1);
    return arr.join(' ');
};
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param String $text
     * @return String
     */
    function arrangeWords($text) {
        $text = lcfirst($text);
        $arr = explode(' ', $text);
        for ($i = 0; $i < count($arr); $i++) {
            $hashtable[$i] = strlen($arr[$i]);
        }
        asort($hashtable);
        $key = array_keys($hashtable);
        $rs = [];
        for ($j = 0; $j < count($key); $j++) {
            array_push($rs, $arr[$key[$j]]);
        }
        return ucfirst(implode(' ', $rs));
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>「句子」是一个用空格分隔单词的字符串。给你一个满足下述格式的句子 <code>text</code> :</p>

<ul>
	<li>句子的首字母大写</li>
	<li><code>text</code> 中的每个单词都用单个空格分隔。</li>
</ul>

<p>请你重新排列 <code>text</code> 中的单词，使所有单词按其长度的升序排列。如果两个单词的长度相同，则保留其在原句子中的相对顺序。</p>

<p>请同样按上述格式返回新的句子。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>text = &quot;Leetcode is cool&quot;
<strong>输出：</strong>&quot;Is cool leetcode&quot;
<strong>解释：</strong>句子中共有 3 个单词，长度为 8 的 &quot;Leetcode&quot; ，长度为 2 的 &quot;is&quot; 以及长度为 4 的 &quot;cool&quot; 。
输出需要按单词的长度升序排列，新句子中的第一个单词首字母需要大写。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>text = &quot;Keep calm and code on&quot;
<strong>输出：</strong>&quot;On and keep calm code&quot;
<strong>解释：</strong>输出的排序情况如下：
&quot;On&quot; 2 个字母。
&quot;and&quot; 3 个字母。
&quot;keep&quot; 4 个字母，因为存在长度相同的其他单词，所以它们之间需要保留在原句子中的相对顺序。
&quot;calm&quot; 4 个字母。
&quot;code&quot; 4 个字母。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>text = &quot;To be or not to be&quot;
<strong>输出：</strong>&quot;To be or to be not&quot;
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>text</code> 以大写字母开头，然后包含若干小写字母以及单词间的单个空格。</li>
	<li><code>1 &lt;= text.length &lt;= 10^5</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序

将 `text` 按空格切分为字符串数组 `words`，并将 `words[0]` 转为小写。然后对 `words` 进行排序（这里需要确保长度相同的情况下，相对顺序保持不变，因此是一种稳定排序）。

排完序后，对 `words[0]` 首字母转为大写。最后将 `words` 所有字符串用空格拼接成一个字符串。

时间复杂度 $O(n\log n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def arrangeWords(self, text: str) -> str:
        words = text.split()
        words[0] = words[0].lower()
        words.sort(key=len)
        words[0] = words[0].title()
        return " ".join(words)
```

#### Java

```java
class Solution {
    public String arrangeWords(String text) {
        String[] words = text.split(" ");
        words[0] = words[0].toLowerCase();
        Arrays.sort(words, Comparator.comparingInt(String::length));
        words[0] = words[0].substring(0, 1).toUpperCase() + words[0].substring(1);
        return String.join(" ", words);
    }
}
```

#### C++

```cpp
class Solution {
public:
    string arrangeWords(string text) {
        vector<string> words;
        stringstream ss(text);
        string t;
        while (ss >> t) {
            words.push_back(t);
        }
        words[0][0] = tolower(words[0][0]);
        stable_sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });
        string ans = "";
        for (auto& s : words) {
            ans += s + " ";
        }
        ans.pop_back();
        ans[0] = toupper(ans[0]);
        return ans;
    }
};
```

#### Go

```go
func arrangeWords(text string) string {
	words := strings.Split(text, " ")
	words[0] = strings.ToLower(words[0])
	sort.SliceStable(words, func(i, j int) bool { return len(words[i]) < len(words[j]) })
	words[0] = strings.Title(words[0])
	return strings.Join(words, " ")
}
```

#### TypeScript

```ts
function arrangeWords(text: string): string {
    let words: string[] = text.split(' ');
    words[0] = words[0].toLowerCase();
    words.sort((a, b) => a.length - b.length);
    words[0] = words[0].charAt(0).toUpperCase() + words[0].slice(1);
    return words.join(' ');
}
```

#### JavaScript

```js
/**
 * @param {string} text
 * @return {string}
 */
var arrangeWords = function (text) {
    let arr = text.split(' ');
    arr[0] = arr[0].toLocaleLowerCase();
    arr.sort((a, b) => a.length - b.length);
    arr[0] = arr[0][0].toLocaleUpperCase() + arr[0].substr(1);
    return arr.join(' ');
};
```

#### PHP

```php
class Solution {
    /**
     * @param String $text
     * @return String
     */
    function arrangeWords($text) {
        $text = lcfirst($text);
        $arr = explode(' ', $text);
        for ($i = 0; $i < count($arr); $i++) {
            $hashtable[$i] = strlen($arr[$i]);
        }
        asort($hashtable);
        $key = array_keys($hashtable);
        $rs = [];
        for ($j = 0; $j < count($key); $j++) {
            array_push($rs, $arr[$key[$j]]);
        }
        return ucfirst(implode(' ', $rs));
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1452. 收藏清单](https://leetcode.cn/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list){#1452}

{{< tabs "1452" >}}

{{% tab "python" %}}
```python
class Solution:
    def peopleIndexes(self, favoriteCompanies: List[List[str]]) -> List[int]:
        idx = 0
        d = {}
        n = len(favoriteCompanies)
        nums = [set() for _ in range(n)]
        for i, ss in enumerate(favoriteCompanies):
            for s in ss:
                if s not in d:
                    d[s] = idx
                    idx += 1
                nums[i].add(d[s])
        ans = []
        for i in range(n):
            if not any(i != j and (nums[i] & nums[j]) == nums[i] for j in range(n)):
                ans.append(i)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> peopleIndexes(List<List<String>> favoriteCompanies) {
        int n = favoriteCompanies.size();
        Map<String, Integer> d = new HashMap<>();
        int idx = 0;
        Set<Integer>[] nums = new Set[n];
        Arrays.setAll(nums, i -> new HashSet<>());
        for (int i = 0; i < n; ++i) {
            var ss = favoriteCompanies.get(i);
            for (var s : ss) {
                if (!d.containsKey(s)) {
                    d.put(s, idx++);
                }
                nums[i].add(d.get(s));
            }
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            boolean ok = true;
            for (int j = 0; j < n && ok; ++j) {
                if (i != j && nums[j].containsAll(nums[i])) {
                    ok = false;
                }
            }
            if (ok) {
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
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        int n = favoriteCompanies.size();
        unordered_map<string, int> d;
        int idx = 0;
        vector<unordered_set<int>> nums(n);

        for (int i = 0; i < n; ++i) {
            for (const auto& s : favoriteCompanies[i]) {
                if (!d.contains(s)) {
                    d[s] = idx++;
                }
                nums[i].insert(d[s]);
            }
        }

        auto check = [](const unordered_set<int>& a, const unordered_set<int>& b) {
            for (int x : a) {
                if (!b.contains(x)) {
                    return false;
                }
            }
            return true;
        };

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            bool ok = true;
            for (int j = 0; j < n && ok; ++j) {
                if (i != j && check(nums[i], nums[j])) {
                    ok = false;
                }
            }
            if (ok) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func peopleIndexes(favoriteCompanies [][]string) (ans []int) {
	n := len(favoriteCompanies)
	d := make(map[string]int)
	idx := 0
	nums := make([]map[int]struct{}, n)

	for i := 0; i < n; i++ {
		nums[i] = make(map[int]struct{})
		for _, s := range favoriteCompanies[i] {
			if _, ok := d[s]; !ok {
				d[s] = idx
				idx++
			}
			nums[i][d[s]] = struct{}{}
		}
	}

	check := func(a, b map[int]struct{}) bool {
		for x := range a {
			if _, ok := b[x]; !ok {
				return false
			}
		}
		return true
	}
	for i := 0; i < n; i++ {
		ok := true
		for j := 0; j < n && ok; j++ {
			if i != j && check(nums[i], nums[j]) {
				ok = false
			}
		}
		if ok {
			ans = append(ans, i)
		}
	}

	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function peopleIndexes(favoriteCompanies: string[][]): number[] {
    const n = favoriteCompanies.length;
    const d: Map<string, number> = new Map();
    let idx = 0;
    const nums: Set<number>[] = Array.from({ length: n }, () => new Set<number>());

    for (let i = 0; i < n; i++) {
        for (const s of favoriteCompanies[i]) {
            if (!d.has(s)) {
                d.set(s, idx++);
            }
            nums[i].add(d.get(s)!);
        }
    }

    const check = (a: Set<number>, b: Set<number>): boolean => {
        for (const x of a) {
            if (!b.has(x)) {
                return false;
            }
        }
        return true;
    };

    const ans: number[] = [];
    for (let i = 0; i < n; i++) {
        let ok = true;
        for (let j = 0; j < n && ok; j++) {
            if (i !== j && check(nums[i], nums[j])) {
                ok = false;
            }
        }
        if (ok) {
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

<p>给你一个数组 <code>favoriteCompanies</code> ，其中 <code>favoriteCompanies[i]</code> 是第 <code>i</code> 名用户收藏的公司清单（<strong>下标从 0 开始</strong>）。</p>

<p>请找出不是其他任何人收藏的公司清单的子集的收藏清单，并返回该清单下标<em>。</em>下标需要按升序排列<em>。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>favoriteCompanies = [[&quot;leetcode&quot;,&quot;google&quot;,&quot;facebook&quot;],[&quot;google&quot;,&quot;microsoft&quot;],[&quot;google&quot;,&quot;facebook&quot;],[&quot;google&quot;],[&quot;amazon&quot;]]
<strong>输出：</strong>[0,1,4] 
<strong>解释：</strong>
favoriteCompanies[2]=[&quot;google&quot;,&quot;facebook&quot;] 是 favoriteCompanies[0]=[&quot;leetcode&quot;,&quot;google&quot;,&quot;facebook&quot;] 的子集。
favoriteCompanies[3]=[&quot;google&quot;] 是 favoriteCompanies[0]=[&quot;leetcode&quot;,&quot;google&quot;,&quot;facebook&quot;] 和 favoriteCompanies[1]=[&quot;google&quot;,&quot;microsoft&quot;] 的子集。
其余的收藏清单均不是其他任何人收藏的公司清单的子集，因此，答案为 [0,1,4] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>favoriteCompanies = [[&quot;leetcode&quot;,&quot;google&quot;,&quot;facebook&quot;],[&quot;leetcode&quot;,&quot;amazon&quot;],[&quot;facebook&quot;,&quot;google&quot;]]
<strong>输出：</strong>[0,1] 
<strong>解释：</strong>favoriteCompanies[2]=[&quot;facebook&quot;,&quot;google&quot;] 是 favoriteCompanies[0]=[&quot;leetcode&quot;,&quot;google&quot;,&quot;facebook&quot;] 的子集，因此，答案为 [0,1] 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>favoriteCompanies = [[&quot;leetcode&quot;],[&quot;google&quot;],[&quot;facebook&quot;],[&quot;amazon&quot;]]
<strong>输出：</strong>[0,1,2,3]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;=&nbsp;favoriteCompanies.length &lt;= 100</code></li>
	<li><code>1 &lt;=&nbsp;favoriteCompanies[i].length &lt;= 500</code></li>
	<li><code>1 &lt;=&nbsp;favoriteCompanies[i][j].length &lt;= 20</code></li>
	<li><code>favoriteCompanies[i]</code> 中的所有字符串 <strong>各不相同</strong> 。</li>
	<li>用户收藏的公司清单也 <strong>各不相同</strong> ，也就是说，即便我们按字母顺序排序每个清单， <code>favoriteCompanies[i] != favoriteCompanies[j] </code>仍然成立。</li>
	<li>所有字符串仅包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们可以将每个公司映射到一个唯一的整数，然后对于每个人，我们将他们收藏的公司转换为整数集合，最后判断是否存在一个人的收藏公司是另一个人的子集。

时间复杂度 $(n \times m \times k + n^2 \times m)$，空间复杂度 $O(n \times m)$。其中 $n$ 和 $m$ 分别是 `favoriteCompanies` 的长度和每个公司清单的平均长度，而 $k$ 是每个公司的平均长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def peopleIndexes(self, favoriteCompanies: List[List[str]]) -> List[int]:
        idx = 0
        d = {}
        n = len(favoriteCompanies)
        nums = [set() for _ in range(n)]
        for i, ss in enumerate(favoriteCompanies):
            for s in ss:
                if s not in d:
                    d[s] = idx
                    idx += 1
                nums[i].add(d[s])
        ans = []
        for i in range(n):
            if not any(i != j and (nums[i] & nums[j]) == nums[i] for j in range(n)):
                ans.append(i)
        return ans
```

#### Java

```java
class Solution {
    public List<Integer> peopleIndexes(List<List<String>> favoriteCompanies) {
        int n = favoriteCompanies.size();
        Map<String, Integer> d = new HashMap<>();
        int idx = 0;
        Set<Integer>[] nums = new Set[n];
        Arrays.setAll(nums, i -> new HashSet<>());
        for (int i = 0; i < n; ++i) {
            var ss = favoriteCompanies.get(i);
            for (var s : ss) {
                if (!d.containsKey(s)) {
                    d.put(s, idx++);
                }
                nums[i].add(d.get(s));
            }
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            boolean ok = true;
            for (int j = 0; j < n && ok; ++j) {
                if (i != j && nums[j].containsAll(nums[i])) {
                    ok = false;
                }
            }
            if (ok) {
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
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        int n = favoriteCompanies.size();
        unordered_map<string, int> d;
        int idx = 0;
        vector<unordered_set<int>> nums(n);

        for (int i = 0; i < n; ++i) {
            for (const auto& s : favoriteCompanies[i]) {
                if (!d.contains(s)) {
                    d[s] = idx++;
                }
                nums[i].insert(d[s]);
            }
        }

        auto check = [](const unordered_set<int>& a, const unordered_set<int>& b) {
            for (int x : a) {
                if (!b.contains(x)) {
                    return false;
                }
            }
            return true;
        };

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            bool ok = true;
            for (int j = 0; j < n && ok; ++j) {
                if (i != j && check(nums[i], nums[j])) {
                    ok = false;
                }
            }
            if (ok) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
```

#### Go

```go
func peopleIndexes(favoriteCompanies [][]string) (ans []int) {
	n := len(favoriteCompanies)
	d := make(map[string]int)
	idx := 0
	nums := make([]map[int]struct{}, n)

	for i := 0; i < n; i++ {
		nums[i] = make(map[int]struct{})
		for _, s := range favoriteCompanies[i] {
			if _, ok := d[s]; !ok {
				d[s] = idx
				idx++
			}
			nums[i][d[s]] = struct{}{}
		}
	}

	check := func(a, b map[int]struct{}) bool {
		for x := range a {
			if _, ok := b[x]; !ok {
				return false
			}
		}
		return true
	}
	for i := 0; i < n; i++ {
		ok := true
		for j := 0; j < n && ok; j++ {
			if i != j && check(nums[i], nums[j]) {
				ok = false
			}
		}
		if ok {
			ans = append(ans, i)
		}
	}

	return
}
```

#### TypeScript

```ts
function peopleIndexes(favoriteCompanies: string[][]): number[] {
    const n = favoriteCompanies.length;
    const d: Map<string, number> = new Map();
    let idx = 0;
    const nums: Set<number>[] = Array.from({ length: n }, () => new Set<number>());

    for (let i = 0; i < n; i++) {
        for (const s of favoriteCompanies[i]) {
            if (!d.has(s)) {
                d.set(s, idx++);
            }
            nums[i].add(d.get(s)!);
        }
    }

    const check = (a: Set<number>, b: Set<number>): boolean => {
        for (const x of a) {
            if (!b.has(x)) {
                return false;
            }
        }
        return true;
    };

    const ans: number[] = [];
    for (let i = 0; i < n; i++) {
        let ok = true;
        for (let j = 0; j < n && ok; j++) {
            if (i !== j && check(nums[i], nums[j])) {
                ok = false;
            }
        }
        if (ok) {
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

# [1453. 圆形靶内的最大飞镖数量](https://leetcode.cn/problems/maximum-number-of-darts-inside-of-a-circular-dartboard){#1453}

{{< tabs "1453" >}}

{{% tab "python" %}}
```python
class Solution:
    def numPoints(self, darts: list[list[int]], r: int) -> int:
        def countDarts(x, y):
            count = 0
            for x1, y1 in darts:
                if dist((x, y), (x1, y1)) <= r + 1e-7:
                    count += 1
            return count

        def possibleCenters(x1, y1, x2, y2):
            dx, dy = x2 - x1, y2 - y1
            d = sqrt(dx * dx + dy * dy)
            if d > 2 * r:
                return []
            mid_x, mid_y = (x1 + x2) / 2, (y1 + y2) / 2
            dist_to_center = sqrt(r * r - (d / 2) * (d / 2))
            offset_x = dist_to_center * dy / d
            offset_y = dist_to_center * -dx / d
            return [
                (mid_x + offset_x, mid_y + offset_y),
                (mid_x - offset_x, mid_y - offset_y),
            ]

        n = len(darts)
        max_darts = 1

        for i in range(n):
            for j in range(i + 1, n):
                centers = possibleCenters(
                    darts[i][0], darts[i][1], darts[j][0], darts[j][1]
                )
                for center in centers:
                    max_darts = max(max_darts, countDarts(center[0], center[1]))

        return max_darts
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numPoints(int[][] darts, int r) {
        int n = darts.length;
        int maxDarts = 1;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                List<double[]> centers
                    = possibleCenters(darts[i][0], darts[i][1], darts[j][0], darts[j][1], r);
                for (double[] center : centers) {
                    maxDarts = Math.max(maxDarts, countDarts(center[0], center[1], darts, r));
                }
            }
        }
        return maxDarts;
    }

    private List<double[]> possibleCenters(int x1, int y1, int x2, int y2, int r) {
        List<double[]> centers = new ArrayList<>();
        double dx = x2 - x1;
        double dy = y2 - y1;
        double d = Math.sqrt(dx * dx + dy * dy);
        if (d > 2 * r) {
            return centers;
        }
        double midX = (x1 + x2) / 2.0;
        double midY = (y1 + y2) / 2.0;
        double distToCenter = Math.sqrt(r * r - (d / 2.0) * (d / 2.0));
        double offsetX = distToCenter * dy / d;
        double offsetY = distToCenter * -dx / d;

        centers.add(new double[] {midX + offsetX, midY + offsetY});
        centers.add(new double[] {midX - offsetX, midY - offsetY});
        return centers;
    }

    private int countDarts(double x, double y, int[][] darts, int r) {
        int count = 0;
        for (int[] dart : darts) {
            if (Math.sqrt(Math.pow(dart[0] - x, 2) + Math.pow(dart[1] - y, 2)) <= r + 1e-7) {
                count++;
            }
        }
        return count;
    }
}
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

<p>Alice 向一面非常大的墙上掷出 <code>n</code> 支飞镖。给你一个数组 <code>darts</code> ，其中 <code>darts[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> 表示 Alice 掷出的第 <code>i</code> 支飞镖落在墙上的位置。</p>

<p>Bob 知道墙上所有 <code>n</code> 支飞镖的位置。他想要往墙上放置一个半径为 <code>r</code> 的圆形靶。使 Alice 掷出的飞镖尽可能多地落在靶上。</p>

<p>给你整数 <code>r</code> ，请返回能够落在 <strong>任意</strong> 半径为 <code>r</code> 的圆形靶内或靶上的最大飞镖数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1 ：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1453.Maximum%20Number%20of%20Darts%20Inside%20of%20a%20Circular%20Dartboard/images/sample_1_1806.png" style="width: 248px; height: 211px;" />
<pre>
<strong>输入：</strong>darts = [[-2,0],[2,0],[0,2],[0,-2]], r = 2
<strong>输出：</strong>4
<strong>解释：</strong>如果圆形靶的圆心为 (0,0) ，半径为 2 ，所有的飞镖都落在靶上，此时落在靶上的飞镖数最大，值为 4 。
</pre>

<p><strong class="example">示例 2 ：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1453.Maximum%20Number%20of%20Darts%20Inside%20of%20a%20Circular%20Dartboard/images/sample_2_1806.png" style="width: 306px; height: 244px;" />
<pre>
<strong>输入：</strong>darts = [[-3,0],[3,0],[2,6],[5,4],[0,9],[7,8]], r = 5
<strong>输出：</strong>5
<strong>解释：</strong>如果圆形靶的圆心为 (0,4) ，半径为 5 ，则除了 (7,8) 之外的飞镖都落在靶上，此时落在靶上的飞镖数最大，值为 5 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= darts.length &lt;= 100</code></li>
	<li><code>darts[i].length == 2</code></li>
	<li><code>-10<sup>4</sup> &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= 10<sup>4</sup></code></li>
	<li><code>darts</code> 中的元素互不相同</li>
	<li><code>1 &lt;= r &lt;= 5000</code></li>
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
    def numPoints(self, darts: list[list[int]], r: int) -> int:
        def countDarts(x, y):
            count = 0
            for x1, y1 in darts:
                if dist((x, y), (x1, y1)) <= r + 1e-7:
                    count += 1
            return count

        def possibleCenters(x1, y1, x2, y2):
            dx, dy = x2 - x1, y2 - y1
            d = sqrt(dx * dx + dy * dy)
            if d > 2 * r:
                return []
            mid_x, mid_y = (x1 + x2) / 2, (y1 + y2) / 2
            dist_to_center = sqrt(r * r - (d / 2) * (d / 2))
            offset_x = dist_to_center * dy / d
            offset_y = dist_to_center * -dx / d
            return [
                (mid_x + offset_x, mid_y + offset_y),
                (mid_x - offset_x, mid_y - offset_y),
            ]

        n = len(darts)
        max_darts = 1

        for i in range(n):
            for j in range(i + 1, n):
                centers = possibleCenters(
                    darts[i][0], darts[i][1], darts[j][0], darts[j][1]
                )
                for center in centers:
                    max_darts = max(max_darts, countDarts(center[0], center[1]))

        return max_darts
```

#### Java

```java
class Solution {
    public int numPoints(int[][] darts, int r) {
        int n = darts.length;
        int maxDarts = 1;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                List<double[]> centers
                    = possibleCenters(darts[i][0], darts[i][1], darts[j][0], darts[j][1], r);
                for (double[] center : centers) {
                    maxDarts = Math.max(maxDarts, countDarts(center[0], center[1], darts, r));
                }
            }
        }
        return maxDarts;
    }

    private List<double[]> possibleCenters(int x1, int y1, int x2, int y2, int r) {
        List<double[]> centers = new ArrayList<>();
        double dx = x2 - x1;
        double dy = y2 - y1;
        double d = Math.sqrt(dx * dx + dy * dy);
        if (d > 2 * r) {
            return centers;
        }
        double midX = (x1 + x2) / 2.0;
        double midY = (y1 + y2) / 2.0;
        double distToCenter = Math.sqrt(r * r - (d / 2.0) * (d / 2.0));
        double offsetX = distToCenter * dy / d;
        double offsetY = distToCenter * -dx / d;

        centers.add(new double[] {midX + offsetX, midY + offsetY});
        centers.add(new double[] {midX - offsetX, midY - offsetY});
        return centers;
    }

    private int countDarts(double x, double y, int[][] darts, int r) {
        int count = 0;
        for (int[] dart : darts) {
            if (Math.sqrt(Math.pow(dart[0] - x, 2) + Math.pow(dart[1] - y, 2)) <= r + 1e-7) {
                count++;
            }
        }
        return count;
    }
}
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

# [1454. 活跃用户 🔒](https://leetcode.cn/problems/active-users){#1454}

{{< tabs "1454" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT DISTINCT *
        FROM
            Logins
            JOIN Accounts USING (id)
    ),
    P AS (
        SELECT
            *,
            DATE_SUB(
                login_date,
                INTERVAL ROW_NUMBER() OVER (
                    PARTITION BY id
                    ORDER BY login_date
                ) DAY
            ) g
        FROM T
    )
SELECT DISTINCT id, name
FROM P
GROUP BY id, g
HAVING COUNT(*) >= 5
ORDER BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表 <code>Accounts</code>:</p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| name          | varchar |
+---------------+---------+
id 是该表主键（具有唯一值的列）
该表包含账户 id 和账户的用户名.
</pre>

<p>&nbsp;</p>

<p>表 <code>Logins</code>:</p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| login_date    | date    |
+---------------+---------+
该表可能包含重复项.
该表包含登录用户的账户 id 和登录日期. 用户也许一天内登录多次.
</pre>

<p>&nbsp;</p>

<p><strong>活跃用户</strong> 是指那些至少连续&nbsp;5 天登录账户的用户。</p>

<p>编写解决方案,&nbsp; 找到 <strong>活跃用户</strong> 的 id 和 name。</p>

<p>返回的结果表按照 <code>id</code> <strong>排序&nbsp;</strong>。</p>

<p>结果表格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Accounts 表:
+----+----------+
| id | name     |
+----+----------+
| 1  | Winston  |
| 7  | Jonathan |
+----+----------+

Logins 表:
+----+------------+
| id | login_date |
+----+------------+
| 7  | 2020-05-30 |
| 1  | 2020-05-30 |
| 7  | 2020-05-31 |
| 7  | 2020-06-01 |
| 7  | 2020-06-02 |
| 7  | 2020-06-02 |
| 7  | 2020-06-03 |
| 1  | 2020-06-07 |
| 7  | 2020-06-10 |
+----+------------+
<strong>输出：</strong>
+----+----------+
| id | name     |
+----+----------+
| 7  | Jonathan |
+----+----------+
<strong>解释：</strong>
id = 1 的用户 Winston 仅仅在不同的 2 天内登录了 2 次, 所以, Winston 不是活跃用户.
id = 7 的用户 Jonathon 在不同的 6 天内登录了 7 次, , 6 天中有 5 天是连续的, 所以, Jonathan 是活跃用户.
</pre>

<p>&nbsp;</p>

<p><strong>进阶问题:</strong><br />
如果活跃用户是那些至少连续&nbsp;<code>n</code>&nbsp;天登录账户的用户,&nbsp;你能否写出通用的解决方案?</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一: 使用窗口函数

我们先将 `Logins` 表和 `Accounts` 表连接起来，并且去重，得到临时表 `T`。

然后我们使用窗口函数 `ROW_NUMBER()`，计算出每个用户 `id` 的登录日期的基准日期 `g`，如果用户连续登录 5 天，那么他们的 `g` 值是相同的。

最后，我们按照 `id` 和 `g` 进行分组，统计每个用户的登录次数，如果登录次数大于等于 5，那么这个用户就是活跃用户。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT DISTINCT *
        FROM
            Logins
            JOIN Accounts USING (id)
    ),
    P AS (
        SELECT
            *,
            DATE_SUB(
                login_date,
                INTERVAL ROW_NUMBER() OVER (
                    PARTITION BY id
                    ORDER BY login_date
                ) DAY
            ) g
        FROM T
    )
SELECT DISTINCT id, name
FROM P
GROUP BY id, g
HAVING COUNT(*) >= 5
ORDER BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1455. 检查单词是否为句中其他单词的前缀](https://leetcode.cn/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence){#1455}

{{< tabs "1455" >}}

{{% tab "python" %}}
```python
class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        for i, s in enumerate(sentence.split(), 1):
            if s.startswith(searchWord):
                return i
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int isPrefixOfWord(String sentence, String searchWord) {
        String[] words = sentence.split(" ");
        for (int i = 0; i < words.length; ++i) {
            if (words[i].startsWith(searchWord)) {
                return i + 1;
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
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string s;
        for (int i = 1; ss >> s; ++i) {
            if (s.find(searchWord) == 0) {
                return i;
            }
        }
        return -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isPrefixOfWord(sentence string, searchWord string) int {
	for i, s := range strings.Split(sentence, " ") {
		if strings.HasPrefix(s, searchWord) {
			return i + 1
		}
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isPrefixOfWord(sentence: string, searchWord: string): number {
    const ss = sentence.split(/\s/);
    const n = ss.length;
    for (let i = 0; i < n; i++) {
        if (ss[i].startsWith(searchWord)) {
            return i + 1;
        }
    }
    return -1;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn is_prefix_of_word(sentence: String, search_word: String) -> i32 {
        let ss = sentence.split_whitespace().collect::<Vec<&str>>();
        for i in 0..ss.len() {
            if ss[i].starts_with(&search_word) {
                return (i + 1) as i32;
            }
        }
        -1
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param String $sentence
     * @param String $searchWord
     * @return Integer
     */
    function isPrefixOfWord($sentence, $searchWord) {
        $words = explode(' ', $sentence);
        for ($i = 0; $i < count($words); ++$i) {
            if (strpos($words[$i], $searchWord) === 0) {
                return $i + 1;
            }
        }
        return -1;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>sentence</code> 作为句子并指定检索词为 <code>searchWord</code> ，其中句子由若干用 <strong>单个空格</strong> 分隔的单词组成。请你检查检索词 <code>searchWord</code> 是否为句子 <code>sentence</code> 中任意单词的前缀。</p>

<p>如果&nbsp;<code>searchWord</code> 是某一个单词的前缀，则返回句子&nbsp;<code>sentence</code> 中该单词所对应的下标（<strong>下标从 1 开始</strong>）。如果 <code>searchWord</code> 是多个单词的前缀，则返回匹配的第一个单词的下标（<strong>最小下标</strong>）。如果 <code>searchWord</code> 不是任何单词的前缀，则返回 <code>-1</code><strong> </strong>。</p>

<p>字符串 <code>s</code> 的 <strong>前缀</strong> 是 <code>s</code> 的任何前导连续子字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>sentence = "i love eating burger", searchWord = "burg"
<strong>输出：</strong>4
<strong>解释：</strong>"burg" 是 "burger" 的前缀，而 "burger" 是句子中第 4 个单词。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>sentence = "this problem is an easy problem", searchWord = "pro"
<strong>输出：</strong>2
<strong>解释：</strong>"pro" 是 "problem" 的前缀，而 "problem" 是句子中第 2 个也是第 6 个单词，但是应该返回最小下标 2 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>sentence = "i am tired", searchWord = "you"
<strong>输出：</strong>-1
<strong>解释：</strong>"you" 不是句子中任何单词的前缀。

</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= sentence.length &lt;= 100</code></li>
	<li><code>1 &lt;= searchWord.length &lt;= 10</code></li>
	<li><code>sentence</code> 由小写英文字母和空格组成。</li>
	<li><code>searchWord</code> 由小写英文字母组成。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：字符串分割

我们将 $\textit{sentence}$ 按空格分割为 $\textit{words}$，然后遍历 $\textit{words}$，检查 $\textit{words}[i]$ 是否是 $\textit{searchWord}$ 的前缀，是则返回 $i+1$。若遍历结束，所有单词都不满足，返回 $-1$。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m)$。其中 $m$ 和 $n$ 分别是 $\textit{sentence}$ 和 $\textit{searchWord}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        for i, s in enumerate(sentence.split(), 1):
            if s.startswith(searchWord):
                return i
        return -1
```

#### Java

```java
class Solution {
    public int isPrefixOfWord(String sentence, String searchWord) {
        String[] words = sentence.split(" ");
        for (int i = 0; i < words.length; ++i) {
            if (words[i].startsWith(searchWord)) {
                return i + 1;
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
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string s;
        for (int i = 1; ss >> s; ++i) {
            if (s.find(searchWord) == 0) {
                return i;
            }
        }
        return -1;
    }
};
```

#### Go

```go
func isPrefixOfWord(sentence string, searchWord string) int {
	for i, s := range strings.Split(sentence, " ") {
		if strings.HasPrefix(s, searchWord) {
			return i + 1
		}
	}
	return -1
}
```

#### TypeScript

```ts
function isPrefixOfWord(sentence: string, searchWord: string): number {
    const ss = sentence.split(/\s/);
    const n = ss.length;
    for (let i = 0; i < n; i++) {
        if (ss[i].startsWith(searchWord)) {
            return i + 1;
        }
    }
    return -1;
}
```

#### Rust

```rust
impl Solution {
    pub fn is_prefix_of_word(sentence: String, search_word: String) -> i32 {
        let ss = sentence.split_whitespace().collect::<Vec<&str>>();
        for i in 0..ss.len() {
            if ss[i].starts_with(&search_word) {
                return (i + 1) as i32;
            }
        }
        -1
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param String $sentence
     * @param String $searchWord
     * @return Integer
     */
    function isPrefixOfWord($sentence, $searchWord) {
        $words = explode(' ', $sentence);
        for ($i = 0; $i < count($words); ++$i) {
            if (strpos($words[$i], $searchWord) === 0) {
                return $i + 1;
            }
        }
        return -1;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1456. 定长子串中元音的最大数目](https://leetcode.cn/problems/maximum-number-of-vowels-in-a-substring-of-given-length){#1456}

{{< tabs "1456" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        vowels = set("aeiou")
        ans = cnt = sum(c in vowels for c in s[:k])
        for i in range(k, len(s)):
            cnt += int(s[i] in vowels) - int(s[i - k] in vowels)
            ans = max(ans, cnt)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxVowels(String s, int k) {
        int cnt = 0;
        for (int i = 0; i < k; ++i) {
            if (isVowel(s.charAt(i))) {
                ++cnt;
            }
        }
        int ans = cnt;
        for (int i = k; i < s.length(); ++i) {
            if (isVowel(s.charAt(i))) {
                ++cnt;
            }
            if (isVowel(s.charAt(i - k))) {
                --cnt;
            }
            ans = Math.max(ans, cnt);
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
    int maxVowels(string s, int k) {
        auto isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        int cnt = count_if(s.begin(), s.begin() + k, isVowel);
        int ans = cnt;
        for (int i = k; i < s.size(); ++i) {
            cnt += isVowel(s[i]) - isVowel(s[i - k]);
            ans = max(ans, cnt);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxVowels(s string, k int) int {
	isVowel := func(c byte) bool {
		return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
	}
	cnt := 0
	for i := 0; i < k; i++ {
		if isVowel(s[i]) {
			cnt++
		}
	}
	ans := cnt
	for i := k; i < len(s); i++ {
		if isVowel(s[i-k]) {
			cnt--
		}
		if isVowel(s[i]) {
			cnt++
		}
		ans = max(ans, cnt)
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxVowels(s: string, k: number): number {
    const vowels = new Set(['a', 'e', 'i', 'o', 'u']);
    let cnt = 0;
    for (let i = 0; i < k; i++) {
        if (vowels.has(s[i])) {
            cnt++;
        }
    }
    let ans = cnt;
    for (let i = k; i < s.length; i++) {
        if (vowels.has(s[i])) {
            cnt++;
        }
        if (vowels.has(s[i - k])) {
            cnt--;
        }
        ans = Math.max(ans, cnt);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param String $s
     * @param Integer $k
     * @return Integer
     */
    function isVowel($c) {
        return $c === 'a' || $c === 'e' || $c === 'i' || $c === 'o' || $c === 'u';
    }
    function maxVowels($s, $k) {
        $cnt = 0;
        for ($i = 0; $i < $k; $i++) {
            if ($this->isVowel($s[$i])) {
                $cnt++;
            }
        }
        $ans = $cnt;
        for ($j = $k; $j < strlen($s); $j++) {
            if ($this->isVowel($s[$j - $k])) {
                $cnt--;
            }
            if ($this->isVowel($s[$j])) {
                $cnt++;
            }
            $ans = max($ans, $cnt);
        }
        return $ans;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你字符串 <code>s</code> 和整数 <code>k</code> 。</p>

<p>请返回字符串 <code>s</code> 中长度为 <code>k</code> 的单个子字符串中可能包含的最大元音字母数。</p>

<p>英文中的 <strong>元音字母 </strong>为（<code>a</code>, <code>e</code>, <code>i</code>, <code>o</code>, <code>u</code>）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = &quot;abciiidef&quot;, k = 3
<strong>输出：</strong>3
<strong>解释：</strong>子字符串 &quot;iii&quot; 包含 3 个元音字母。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = &quot;aeiou&quot;, k = 2
<strong>输出：</strong>2
<strong>解释：</strong>任意长度为 2 的子字符串都包含 2 个元音字母。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = &quot;leetcode&quot;, k = 3
<strong>输出：</strong>2
<strong>解释：</strong>&quot;lee&quot;、&quot;eet&quot; 和 &quot;ode&quot; 都包含 2 个元音字母。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>s = &quot;rhythms&quot;, k = 4
<strong>输出：</strong>0
<strong>解释：</strong>字符串 s 中不含任何元音字母。
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>s = &quot;tryhard&quot;, k = 4
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10^5</code></li>
	<li><code>s</code> 由小写英文字母组成</li>
	<li><code>1 &lt;= k &lt;= s.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：滑动窗口

我们首先统计前 $k$ 个字符中元音字母的个数，记为 $cnt$，初始化答案 $ans$ 为 $cnt$。

然后我们从 $k$ 开始遍历字符串，每次遍历时，我们将当前字符加入窗口，如果当前字符是元音字母，则 $cnt$ 加一；将窗口第一个字符移出窗口，如果移除的字符是元音字母，则 $cnt$ 减一。然后，我们更新答案 $ans = \max(ans, cnt)$。

遍历结束后，返回答案即可。

时间复杂度 $O(n)$，其中 $n$ 为字符串 $s$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        vowels = set("aeiou")
        ans = cnt = sum(c in vowels for c in s[:k])
        for i in range(k, len(s)):
            cnt += int(s[i] in vowels) - int(s[i - k] in vowels)
            ans = max(ans, cnt)
        return ans
```

#### Java

```java
class Solution {
    public int maxVowels(String s, int k) {
        int cnt = 0;
        for (int i = 0; i < k; ++i) {
            if (isVowel(s.charAt(i))) {
                ++cnt;
            }
        }
        int ans = cnt;
        for (int i = k; i < s.length(); ++i) {
            if (isVowel(s.charAt(i))) {
                ++cnt;
            }
            if (isVowel(s.charAt(i - k))) {
                --cnt;
            }
            ans = Math.max(ans, cnt);
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
    int maxVowels(string s, int k) {
        auto isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        int cnt = count_if(s.begin(), s.begin() + k, isVowel);
        int ans = cnt;
        for (int i = k; i < s.size(); ++i) {
            cnt += isVowel(s[i]) - isVowel(s[i - k]);
            ans = max(ans, cnt);
        }
        return ans;
    }
};
```

#### Go

```go
func maxVowels(s string, k int) int {
	isVowel := func(c byte) bool {
		return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
	}
	cnt := 0
	for i := 0; i < k; i++ {
		if isVowel(s[i]) {
			cnt++
		}
	}
	ans := cnt
	for i := k; i < len(s); i++ {
		if isVowel(s[i-k]) {
			cnt--
		}
		if isVowel(s[i]) {
			cnt++
		}
		ans = max(ans, cnt)
	}
	return ans
}
```

#### TypeScript

```ts
function maxVowels(s: string, k: number): number {
    const vowels = new Set(['a', 'e', 'i', 'o', 'u']);
    let cnt = 0;
    for (let i = 0; i < k; i++) {
        if (vowels.has(s[i])) {
            cnt++;
        }
    }
    let ans = cnt;
    for (let i = k; i < s.length; i++) {
        if (vowels.has(s[i])) {
            cnt++;
        }
        if (vowels.has(s[i - k])) {
            cnt--;
        }
        ans = Math.max(ans, cnt);
    }
    return ans;
}
```

#### PHP

```php
class Solution {
    /**
     * @param String $s
     * @param Integer $k
     * @return Integer
     */
    function isVowel($c) {
        return $c === 'a' || $c === 'e' || $c === 'i' || $c === 'o' || $c === 'u';
    }
    function maxVowels($s, $k) {
        $cnt = 0;
        for ($i = 0; $i < $k; $i++) {
            if ($this->isVowel($s[$i])) {
                $cnt++;
            }
        }
        $ans = $cnt;
        for ($j = $k; $j < strlen($s); $j++) {
            if ($this->isVowel($s[$j - $k])) {
                $cnt--;
            }
            if ($this->isVowel($s[$j])) {
                $cnt++;
            }
            $ans = max($ans, $cnt);
        }
        return $ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1457. 二叉树中的伪回文路径](https://leetcode.cn/problems/pseudo-palindromic-paths-in-a-binary-tree){#1457}

{{< tabs "1457" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pseudoPalindromicPaths(self, root: Optional[TreeNode]) -> int:
        def dfs(root: Optional[TreeNode], mask: int):
            if root is None:
                return 0
            mask ^= 1 << root.val
            if root.left is None and root.right is None:
                return int((mask & (mask - 1)) == 0)
            return dfs(root.left, mask) + dfs(root.right, mask)

        return dfs(root, 0)
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
    public int pseudoPalindromicPaths(TreeNode root) {
        return dfs(root, 0);
    }

    private int dfs(TreeNode root, int mask) {
        if (root == null) {
            return 0;
        }
        mask ^= 1 << root.val;
        if (root.left == null && root.right == null) {
            return (mask & (mask - 1)) == 0 ? 1 : 0;
        }
        return dfs(root.left, mask) + dfs(root.right, mask);
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
    int pseudoPalindromicPaths(TreeNode* root) {
        function<int(TreeNode*, int)> dfs = [&](TreeNode* root, int mask) {
            if (!root) {
                return 0;
            }
            mask ^= 1 << root->val;
            if (!root->left && !root->right) {
                return (mask & (mask - 1)) == 0 ? 1 : 0;
            }
            return dfs(root->left, mask) + dfs(root->right, mask);
        };
        return dfs(root, 0);
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
func pseudoPalindromicPaths(root *TreeNode) int {
	var dfs func(*TreeNode, int) int
	dfs = func(root *TreeNode, mask int) int {
		if root == nil {
			return 0
		}
		mask ^= 1 << root.Val
		if root.Left == nil && root.Right == nil {
			if mask&(mask-1) == 0 {
				return 1
			}
			return 0
		}
		return dfs(root.Left, mask) + dfs(root.Right, mask)
	}
	return dfs(root, 0)
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

function pseudoPalindromicPaths(root: TreeNode | null): number {
    const dfs = (root: TreeNode | null, mask: number): number => {
        if (!root) {
            return 0;
        }
        mask ^= 1 << root.val;
        if (!root.left && !root.right) {
            return (mask & (mask - 1)) === 0 ? 1 : 0;
        }
        return dfs(root.left, mask) + dfs(root.right, mask);
    };
    return dfs(root, 0);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::cell::RefCell;
use std::rc::Rc;

impl Solution {
    pub fn pseudo_palindromic_paths(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        fn dfs(root: Option<Rc<RefCell<TreeNode>>>, mask: i32) -> i32 {
            if let Some(node) = root {
                let mut mask = mask;
                let val = node.borrow().val;
                mask ^= 1 << val;

                if node.borrow().left.is_none() && node.borrow().right.is_none() {
                    return if (mask & (mask - 1)) == 0 { 1 } else { 0 };
                }

                return (dfs(node.borrow().left.clone(), mask)
                    + dfs(node.borrow().right.clone(), mask));
            }
            0
        }

        dfs(root, 0)
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一棵二叉树，每个节点的值为 1 到 9 。我们称二叉树中的一条路径是 「<strong>伪回文</strong>」的，当它满足：路径经过的所有节点值的排列中，存在一个回文序列。</p>

<p>请你返回从根到叶子节点的所有路径中&nbsp;<strong>伪回文&nbsp;</strong>路径的数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1457.Pseudo-Palindromic%20Paths%20in%20a%20Binary%20Tree/images/palindromic_paths_1.png" style="height: 201px; width: 300px;" /></p>

<pre>
<strong>输入：</strong>root = [2,3,1,3,1,null,1]
<strong>输出：</strong>2 
<strong>解释：</strong>上图为给定的二叉树。总共有 3 条从根到叶子的路径：红色路径 [2,3,3] ，绿色路径 [2,1,1] 和路径 [2,3,1] 。
     在这些路径中，只有红色和绿色的路径是伪回文路径，因为红色路径 [2,3,3] 存在回文排列 [3,2,3] ，绿色路径 [2,1,1] 存在回文排列 [1,2,1] 。
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1457.Pseudo-Palindromic%20Paths%20in%20a%20Binary%20Tree/images/palindromic_paths_2.png" style="height: 314px; width: 300px;" /></strong></p>

<pre>
<strong>输入：</strong>root = [2,1,1,1,3,null,null,null,null,null,1]
<strong>输出：</strong>1 
<strong>解释：</strong>上图为给定二叉树。总共有 3 条从根到叶子的路径：绿色路径 [2,1,1] ，路径 [2,1,3,1] 和路径 [2,1] 。
     这些路径中只有绿色路径是伪回文路径，因为 [2,1,1] 存在回文排列 [1,2,1] 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>root = [9]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>给定二叉树的节点数目在范围&nbsp;<code>[1, 10<sup>5</sup>]</code> 内</li>
	<li><code>1 &lt;= Node.val &lt;= 9</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS + 位运算

一条路径是伪回文路径，当且仅当该路径经过的节点值的出现次数为奇数的数字为 $0$ 个或 $1$ 个。

由于二叉树节点值的范围为 $1$ 到 $9$，因此对于每一条从根到叶子的路径，我们可以用一个长度为 $10$ 的二进制数 $mask$ 表示当前路径经过的节点值的出现状态，其中 $mask$ 的第 $i$ 位为 $1$，表示当前路径上节点值 $i$ 的出现次数为奇数，否则表示其出现次数为偶数。那么，如果一条路径是伪回文路径，需要满足 $mask \&(mask - 1) = 0$，其中 $\&$ 表示按位与运算。

基于以上分析，我们可以使用深度优先搜索的方法计算路径数。我们定义一个函数 $dfs(root, mask)$，表示从当前 $root$ 节点开始，且当前节点的状态为 $mask$ 的所有伪回文路径的个数。那么答案就是 $dfs(root, 0)$。

函数 $dfs(root, mask)$ 的执行逻辑如下：

如果 $root$ 为空，则返回 $0$；

否则，令 $mask = mask \oplus 2^{root.val}$，其中 $\oplus$ 表示按位异或运算。

如果 $root$ 是叶子节点，那么如果 $mask \&(mask - 1) = 0$，返回 $1$，否则返回 $0$；

如果 $root$ 不是叶子节点，返回 $dfs(root.left, mask) + dfs(root.right, mask)$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是二叉树的节点数。

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
    def pseudoPalindromicPaths(self, root: Optional[TreeNode]) -> int:
        def dfs(root: Optional[TreeNode], mask: int):
            if root is None:
                return 0
            mask ^= 1 << root.val
            if root.left is None and root.right is None:
                return int((mask & (mask - 1)) == 0)
            return dfs(root.left, mask) + dfs(root.right, mask)

        return dfs(root, 0)
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
    public int pseudoPalindromicPaths(TreeNode root) {
        return dfs(root, 0);
    }

    private int dfs(TreeNode root, int mask) {
        if (root == null) {
            return 0;
        }
        mask ^= 1 << root.val;
        if (root.left == null && root.right == null) {
            return (mask & (mask - 1)) == 0 ? 1 : 0;
        }
        return dfs(root.left, mask) + dfs(root.right, mask);
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
    int pseudoPalindromicPaths(TreeNode* root) {
        function<int(TreeNode*, int)> dfs = [&](TreeNode* root, int mask) {
            if (!root) {
                return 0;
            }
            mask ^= 1 << root->val;
            if (!root->left && !root->right) {
                return (mask & (mask - 1)) == 0 ? 1 : 0;
            }
            return dfs(root->left, mask) + dfs(root->right, mask);
        };
        return dfs(root, 0);
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
func pseudoPalindromicPaths(root *TreeNode) int {
	var dfs func(*TreeNode, int) int
	dfs = func(root *TreeNode, mask int) int {
		if root == nil {
			return 0
		}
		mask ^= 1 << root.Val
		if root.Left == nil && root.Right == nil {
			if mask&(mask-1) == 0 {
				return 1
			}
			return 0
		}
		return dfs(root.Left, mask) + dfs(root.Right, mask)
	}
	return dfs(root, 0)
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

function pseudoPalindromicPaths(root: TreeNode | null): number {
    const dfs = (root: TreeNode | null, mask: number): number => {
        if (!root) {
            return 0;
        }
        mask ^= 1 << root.val;
        if (!root.left && !root.right) {
            return (mask & (mask - 1)) === 0 ? 1 : 0;
        }
        return dfs(root.left, mask) + dfs(root.right, mask);
    };
    return dfs(root, 0);
}
```

#### Rust

```rust
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::cell::RefCell;
use std::rc::Rc;

impl Solution {
    pub fn pseudo_palindromic_paths(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        fn dfs(root: Option<Rc<RefCell<TreeNode>>>, mask: i32) -> i32 {
            if let Some(node) = root {
                let mut mask = mask;
                let val = node.borrow().val;
                mask ^= 1 << val;

                if node.borrow().left.is_none() && node.borrow().right.is_none() {
                    return if (mask & (mask - 1)) == 0 { 1 } else { 0 };
                }

                return (dfs(node.borrow().left.clone(), mask)
                    + dfs(node.borrow().right.clone(), mask));
            }
            0
        }

        dfs(root, 0)
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1458. 两个子序列的最大点积](https://leetcode.cn/problems/max-dot-product-of-two-subsequences){#1458}

{{< tabs "1458" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        m, n = len(nums1), len(nums2)
        f = [[-inf] * (n + 1) for _ in range(m + 1)]
        for i, x in enumerate(nums1, 1):
            for j, y in enumerate(nums2, 1):
                v = x * y
                f[i][j] = max(f[i - 1][j], f[i][j - 1], max(0, f[i - 1][j - 1]) + v)
        return f[m][n]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxDotProduct(int[] nums1, int[] nums2) {
        int m = nums1.length, n = nums2.length;
        int[][] f = new int[m + 1][n + 1];
        for (var g : f) {
            Arrays.fill(g, Integer.MIN_VALUE);
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int v = nums1[i - 1] * nums2[j - 1];
                f[i][j] = Math.max(f[i - 1][j], f[i][j - 1]);
                f[i][j] = Math.max(f[i][j], Math.max(f[i - 1][j - 1], 0) + v);
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
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int f[m + 1][n + 1];
        memset(f, 0xc0, sizeof f);
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int v = nums1[i - 1] * nums2[j - 1];
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                f[i][j] = max(f[i][j], max(0, f[i - 1][j - 1]) + v);
            }
        }
        return f[m][n];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxDotProduct(nums1 []int, nums2 []int) int {
	m, n := len(nums1), len(nums2)
	f := make([][]int, m+1)
	for i := range f {
		f[i] = make([]int, n+1)
		for j := range f[i] {
			f[i][j] = math.MinInt32
		}
	}
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			v := nums1[i-1] * nums2[j-1]
			f[i][j] = max(f[i-1][j], f[i][j-1])
			f[i][j] = max(f[i][j], max(0, f[i-1][j-1])+v)
		}
	}
	return f[m][n]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxDotProduct(nums1: number[], nums2: number[]): number {
    const m = nums1.length;
    const n = nums2.length;
    const f = Array.from({ length: m + 1 }, () => Array.from({ length: n + 1 }, () => -Infinity));
    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            const v = nums1[i - 1] * nums2[j - 1];
            f[i][j] = Math.max(f[i - 1][j], f[i][j - 1]);
            f[i][j] = Math.max(f[i][j], Math.max(0, f[i - 1][j - 1]) + v);
        }
    }
    return f[m][n];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn max_dot_product(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
        let m = nums1.len();
        let n = nums2.len();
        let mut f = vec![vec![i32::MIN; n + 1]; m + 1];

        for i in 1..=m {
            for j in 1..=n {
                let v = nums1[i - 1] * nums2[j - 1];
                f[i][j] = f[i][j].max(f[i - 1][j]).max(f[i][j - 1]);
                f[i][j] = f[i][j].max(f[i - 1][j - 1].max(0) + v);
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

<p>给你两个数组&nbsp;<code>nums1</code>&nbsp;和&nbsp;<code>nums2</code>&nbsp;。</p>

<p>请你返回 <code>nums1</code> 和 <code>nums2</code> 中两个长度相同的 <strong>非空</strong> 子序列的最大点积。</p>

<p>数组的非空子序列是通过删除原数组中某些元素（可能一个也不删除）后剩余数字组成的序列，但不能改变数字间相对顺序。比方说，<code>[2,3,5]</code>&nbsp;是&nbsp;<code>[1,2,3,4,5]</code>&nbsp;的一个子序列而&nbsp;<code>[1,5,3]</code>&nbsp;不是。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [2,1,-2,5], nums2 = [3,0,-6]
<strong>输出：</strong>18
<strong>解释：</strong>从 nums1 中得到子序列 [2,-2] ，从 nums2 中得到子序列 [3,-6] 。
它们的点积为 (2*3 + (-2)*(-6)) = 18 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [3,-2], nums2 = [2,-6,7]
<strong>输出：</strong>21
<strong>解释：</strong>从 nums1 中得到子序列 [3] ，从 nums2 中得到子序列 [7] 。
它们的点积为 (3*7) = 21 。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [-1,-1], nums2 = [1,1]
<strong>输出：</strong>-1
<strong>解释：</strong>从 nums1 中得到子序列 [-1] ，从 nums2 中得到子序列 [1] 。
它们的点积为 -1 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length, nums2.length &lt;= 500</code></li>
	<li><code>-1000 &lt;= nums1[i], nums2[i] &lt;= 100</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>点积：</strong></p>

<pre>
定义 <code><strong>a</strong>&nbsp;= [<em>a</em><sub>1</sub>,&nbsp;<em>a</em><sub>2</sub>,…,&nbsp;<em>a</em><sub><em>n</em></sub>]</code> 和<strong> <code>b</code></strong><code>&nbsp;= [<em>b</em><sub>1</sub>,&nbsp;<em>b</em><sub>2</sub>,…,&nbsp;<em>b</em><sub><em>n</em></sub>]</code> 的点积为：

<img alt="\mathbf{a}\cdot \mathbf{b} = \sum_{i=1}^n a_ib_i = a_1b_1 + a_2b_2 + \cdots + a_nb_n " class="tex" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1458.Max%20Dot%20Product%20of%20Two%20Subsequences/images/1666164309-PBJMQp-image.png" />

这里的 <strong>Σ</strong> 指示总和符号。
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示 $\textit{nums1}$ 的前 $i$ 个元素和 $\textit{nums2}$ 的前 $j$ 个元素构成的两个子序列的最大点积。初始时 $f[i][j] = -\infty$。

对于 $f[i][j]$，我们有以下几种情况：

1. 不选 $\textit{nums1}[i-1]$ 或者不选 $\textit{nums2}[j-1]$，即 $f[i][j] = \max(f[i-1][j], f[i][j-1])$；
2. 选 $\textit{nums1}[i-1]$ 和 $\textit{nums2}[j-1]$，即 $f[i][j] = \max(f[i][j], \max(0, f[i-1][j-1]) + \textit{nums1}[i-1] \times \textit{nums2}[j-1])$。

最终答案即为 $f[m][n]$。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是数组 $\textit{nums1}$ 和 $\textit{nums2}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        m, n = len(nums1), len(nums2)
        f = [[-inf] * (n + 1) for _ in range(m + 1)]
        for i, x in enumerate(nums1, 1):
            for j, y in enumerate(nums2, 1):
                v = x * y
                f[i][j] = max(f[i - 1][j], f[i][j - 1], max(0, f[i - 1][j - 1]) + v)
        return f[m][n]
```

#### Java

```java
class Solution {
    public int maxDotProduct(int[] nums1, int[] nums2) {
        int m = nums1.length, n = nums2.length;
        int[][] f = new int[m + 1][n + 1];
        for (var g : f) {
            Arrays.fill(g, Integer.MIN_VALUE);
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int v = nums1[i - 1] * nums2[j - 1];
                f[i][j] = Math.max(f[i - 1][j], f[i][j - 1]);
                f[i][j] = Math.max(f[i][j], Math.max(f[i - 1][j - 1], 0) + v);
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
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int f[m + 1][n + 1];
        memset(f, 0xc0, sizeof f);
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int v = nums1[i - 1] * nums2[j - 1];
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                f[i][j] = max(f[i][j], max(0, f[i - 1][j - 1]) + v);
            }
        }
        return f[m][n];
    }
};
```

#### Go

```go
func maxDotProduct(nums1 []int, nums2 []int) int {
	m, n := len(nums1), len(nums2)
	f := make([][]int, m+1)
	for i := range f {
		f[i] = make([]int, n+1)
		for j := range f[i] {
			f[i][j] = math.MinInt32
		}
	}
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			v := nums1[i-1] * nums2[j-1]
			f[i][j] = max(f[i-1][j], f[i][j-1])
			f[i][j] = max(f[i][j], max(0, f[i-1][j-1])+v)
		}
	}
	return f[m][n]
}
```

#### TypeScript

```ts
function maxDotProduct(nums1: number[], nums2: number[]): number {
    const m = nums1.length;
    const n = nums2.length;
    const f = Array.from({ length: m + 1 }, () => Array.from({ length: n + 1 }, () => -Infinity));
    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            const v = nums1[i - 1] * nums2[j - 1];
            f[i][j] = Math.max(f[i - 1][j], f[i][j - 1]);
            f[i][j] = Math.max(f[i][j], Math.max(0, f[i - 1][j - 1]) + v);
        }
    }
    return f[m][n];
}
```

#### Rust

```rust
impl Solution {
    pub fn max_dot_product(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
        let m = nums1.len();
        let n = nums2.len();
        let mut f = vec![vec![i32::MIN; n + 1]; m + 1];

        for i in 1..=m {
            for j in 1..=n {
                let v = nums1[i - 1] * nums2[j - 1];
                f[i][j] = f[i][j].max(f[i - 1][j]).max(f[i][j - 1]);
                f[i][j] = f[i][j].max(f[i - 1][j - 1].max(0) + v);
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

# [1459. 矩形面积 🔒](https://leetcode.cn/problems/rectangles-area){#1459}

{{< tabs "1459" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    p1.id AS p1,
    p2.id AS p2,
    ABS(p1.x_value - p2.x_value) * ABS(p1.y_value - p2.y_value) AS area
FROM
    Points AS p1
    JOIN Points AS p2 ON p1.id < p2.id
WHERE p1.x_value != p2.x_value AND p1.y_value != p2.y_value
ORDER BY area DESC, p1, p2;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Points</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| x_value       | int     |
| y_value       | int     |
+---------------+---------+
id 是该表中具有唯一值的列。
每个点都用二维坐标 (x_value, y_value) 表示。</pre>

<p>&nbsp;</p>

<p>编写解决方案，报告由表中任意两点可以形成的所有<strong> 边与坐标轴平行 </strong>且 <strong>面积不为零</strong> 的矩形。</p>

<p>结果表中的每一行包含三列 <code>(p1, p2, area)</code>&nbsp;如下:</p>

<ul>
	<li><code>p1</code>&nbsp;和&nbsp;<code>p2</code>&nbsp;是矩形两个对角的 <code>id</code></li>
	<li>矩形的面积由列&nbsp;<code>area</code><strong>&nbsp;</strong>表示</li>
</ul>

<p>返回结果表请按照面积&nbsp;<code>area</code> 大小 <strong>降序排列</strong>；如果面积相同的话, 则按照&nbsp;<code>p1</code>&nbsp;<strong>升序排序</strong>；若仍相同，则按 <code>p2</code> <strong>升序排列</strong>。</p>

<p>返回结果格式如下例所示：</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1459.Rectangles%20Area/images/rect.png" style="width: 200px; height: 330px;" /></p>

<pre>
<strong>输入：</strong>
Points 表:
+----------+-------------+-------------+
| id       | x_value     | y_value     |
+----------+-------------+-------------+
| 1        | 2           | 7           |
| 2        | 4           | 8           |
| 3        | 2           | 10          |
+----------+-------------+-------------+
<strong>输出：</strong>
+----------+-------------+-------------+
| p1       | p2          | area        |
+----------+-------------+-------------+
| 2        | 3           | 4           |
| 1        | 2           | 2           |
+----------+-------------+-------------+
<strong>解释：</strong>
p1 = 2 且 p2 = 3 时, 面积等于 |4-2| * |8-10| = 4
p1 = 1 且 p2 = 2 时, 面积等于 ||2-4| * |7-8| = 2 
p1 = 1 且 p2 = 3 时, 是不可能为矩形的, 面积等于 0
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
    p1.id AS p1,
    p2.id AS p2,
    ABS(p1.x_value - p2.x_value) * ABS(p1.y_value - p2.y_value) AS area
FROM
    Points AS p1
    JOIN Points AS p2 ON p1.id < p2.id
WHERE p1.x_value != p2.x_value AND p1.y_value != p2.y_value
ORDER BY area DESC, p1, p2;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
