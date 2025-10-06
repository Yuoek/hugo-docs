---
title: "1048_LongestStringChain"
date: 2025-10-06T00:42:37+08:00
weight: 1048
tags: [数组, 哈希表, 双指针, 字符串, 动态规划, 排序]
---


{{< katex />}}

{{< badge title="Difficulty" value="中等" >}}

<!-- problem:start -->

# [1048. 最长字符串链](https://leetcode.cn/problems/longest-string-chain)

[English Version](../en/1048-48/1048_LongestStringChain)

## 题目描述

<!-- description:start -->

<p>给出一个单词数组&nbsp;<code>words</code>&nbsp;，其中每个单词都由小写英文字母组成。</p>

<p>如果我们可以&nbsp;<strong>不改变其他字符的顺序&nbsp;</strong>，在 <code>word<sub>A</sub></code>&nbsp;的任何地方添加 <strong>恰好一个</strong> 字母使其变成&nbsp;<code>word<sub>B</sub></code>&nbsp;，那么我们认为&nbsp;<code>word<sub>A</sub></code>&nbsp;是&nbsp;<code>word<sub>B</sub></code>&nbsp;的 <strong>前身</strong> 。</p>

<ul>
	<li>例如，<code>"abc"</code>&nbsp;是&nbsp;<code>"abac"</code>&nbsp;的 <strong>前身</strong>&nbsp;，而&nbsp;<code>"cba"</code>&nbsp;不是&nbsp;<code>"bcad"</code>&nbsp;的 <strong>前身</strong></li>
</ul>

<p><strong>词链</strong>是单词&nbsp;<code>[word_1, word_2, ..., word_k]</code>&nbsp;组成的序列，<code>k &gt;= 1</code>，其中&nbsp;<code>word<sub>1</sub></code>&nbsp;是&nbsp;<code>word<sub>2</sub></code>&nbsp;的前身，<code>word<sub>2</sub></code>&nbsp;是&nbsp;<code>word<sub>3</sub></code>&nbsp;的前身，依此类推。一个单词通常是 <code>k == 1</code> 的 <strong>单词链</strong>&nbsp;。</p>

<p>从给定单词列表 <code>words</code> 中选择单词组成词链，返回 词链的&nbsp;<strong>最长可能长度</strong> 。<br />
&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>words = ["a","b","ba","bca","bda","bdca"]
<strong>输出：</strong>4
<strong>解释：</strong>最长单词链之一为 ["a","<u>b</u>a","b<u>d</u>a","bd<u>c</u>a"]
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<b>输入：</b>words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
<b>输出：</b>5
<b>解释：</b>所有的单词都可以放入单词链 ["xb", "xb<u>c</u>", "<u>c</u>xbc", "<u>p</u>cxbc", "pcxbc<u>f</u>"].
</pre>

<p><strong>示例&nbsp;3:</strong></p>

<pre>
<b>输入：</b>words = ["abcd","dbqca"]
<strong>输出：</strong>1
<b>解释：</b>字链["abcd"]是最长的字链之一。
["abcd"，"dbqca"]不是一个有效的单词链，因为字母的顺序被改变了。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 1000</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 16</code></li>
	<li><code>words[i]</code>&nbsp;仅由小写英文字母组成。</li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### Rust



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Python3



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        words.sort(key=lambda x: len(x))
        res = 0
        mp = {}
        for word in words:
            x = 1
            for i in range(len(word)):
                pre = word[:i] + word[i + 1 :]
                x = max(x, mp.get(pre, 0) + 1)
            mp[word] = x
            res = max(res, x)
        return res
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int longestStrChain(String[] words) {
        Arrays.sort(words, Comparator.comparingInt(String::length));
        int res = 0;
        Map<String, Integer> map = new HashMap<>();
        for (String word : words) {
            int x = 1;
            for (int i = 0; i < word.length(); ++i) {
                String pre = word.substring(0, i) + word.substring(i + 1);
                x = Math.max(x, map.getOrDefault(pre, 0) + 1);
            }
            map.put(word, x);
            res = Math.max(res, x);
        }
        return res;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [&](string a, string b) { return a.size() < b.size(); });
        int res = 0;
        unordered_map<string, int> map;
        for (auto word : words) {
            int x = 1;
            for (int i = 0; i < word.size(); ++i) {
                string pre = word.substr(0, i) + word.substr(i + 1);
                x = max(x, map[pre] + 1);
            }
            map[word] = x;
            res = max(res, x);
        }
        return res;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func longestStrChain(words []string) int {
	sort.Slice(words, func(i, j int) bool { return len(words[i]) < len(words[j]) })
	res := 0
	mp := make(map[string]int)
	for _, word := range words {
		x := 1
		for i := 0; i < len(word); i++ {
			pre := word[0:i] + word[i+1:len(word)]
			x = max(x, mp[pre]+1)
		}
		mp[word] = x
		res = max(res, x)
	}
	return res
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function longestStrChain(words: string[]): number {
    words.sort((a, b) => a.length - b.length);
    let ans = 0;
    let hashTable = new Map();
    for (let word of words) {
        let c = 1;
        for (let i = 0; i < word.length; i++) {
            let pre = word.substring(0, i) + word.substring(i + 1);
            c = Math.max(c, (hashTable.get(pre) || 0) + 1);
        }
        hashTable.set(word, c);
        ans = Math.max(ans, c);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    #[allow(dead_code)]
    pub fn longest_str_chain(words: Vec<String>) -> i32 {
        let mut words = words;
        let mut ret = 0;
        let mut map: HashMap<String, i32> = HashMap::new();

        // Sort the words vector first
        words.sort_by(|lhs, rhs| lhs.len().cmp(&rhs.len()));

        // Begin the "dp" process
        for w in words.iter() {
            let n = w.len();
            let mut x = 1;

            for i in 0..n {
                let s = w[..i].to_string() + &w[i + 1..];
                let v = map.entry(s.clone()).or_default();
                x = std::cmp::max(x, *v + 1);
            }

            map.insert(w.clone(), x);

            ret = std::cmp::max(ret, x);
        }

        ret
    }
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        words.sort(key=lambda x: len(x))
        res = 0
        mp = {}
        for word in words:
            x = 1
            for i in range(len(word)):
                pre = word[:i] + word[i + 1 :]
                x = max(x, mp.get(pre, 0) + 1)
            mp[word] = x
            res = max(res, x)
        return res
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int longestStrChain(String[] words) {
        Arrays.sort(words, Comparator.comparingInt(String::length));
        int res = 0;
        Map<String, Integer> map = new HashMap<>();
        for (String word : words) {
            int x = 1;
            for (int i = 0; i < word.length(); ++i) {
                String pre = word.substring(0, i) + word.substring(i + 1);
                x = Math.max(x, map.getOrDefault(pre, 0) + 1);
            }
            map.put(word, x);
            res = Math.max(res, x);
        }
        return res;
    }
}
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "cpp 可视化" %}}
{{< pythontutor width="100%" height="800" language="cpp" >}}
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [&](string a, string b) { return a.size() < b.size(); });
        int res = 0;
        unordered_map<string, int> map;
        for (auto word : words) {
            int x = 1;
            for (int i = 0; i < word.size(); ++i) {
                string pre = word.substr(0, i) + word.substr(i + 1);
                x = max(x, map[pre] + 1);
            }
            map[word] = x;
            res = max(res, x);
        }
        return res;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}