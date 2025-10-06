---
title: "1781_SumofBeautyofAllSubstrings"
date: 2025-10-06T00:42:37+08:00
weight: 1781
tags: [Hash Table, String, Counting]
---


{{< katex />}}

{{< badge title="Difficulty" value="Medium" >}}

<!-- problem:start -->

# [1781. Sum of Beauty of All Substrings](https://leetcode.com/problems/sum-of-beauty-of-all-substrings)

[中文文档](/solution/1700-1799/1781.Sum%20of%20Beauty%20of%20All%20Substrings/README.md)

## Description

<!-- description:start -->

<p>The <strong>beauty</strong> of a string is the difference in frequencies between the most frequent and least frequent characters.</p>

<ul>
	<li>For example, the beauty of <code>&quot;abaacc&quot;</code> is <code>3 - 1 = 2</code>.</li>
</ul>

<p>Given a string <code>s</code>, return <em>the sum of <strong>beauty</strong> of all of its substrings.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;aabcb&quot;
<strong>Output:</strong> 5
<strong>Explanation: </strong>The substrings with non-zero beauty are [&quot;aab&quot;,&quot;aabc&quot;,&quot;aabcb&quot;,&quot;abcb&quot;,&quot;bcb&quot;], each with beauty equal to 1.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;aabcbaa&quot;
<strong>Output:</strong> 17
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;=<sup> </sup>500</code></li>
	<li><code>s</code> consists of only lowercase English letters.</li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: Enumeration + Counting

Enumerate the starting position $i$ of each substring, find all substrings with the character at this starting position as the left endpoint, then calculate the beauty value of each substring, and accumulate it to the answer.

The time complexity is $O(n^2 \times C)$, and the space complexity is $O(C)$. Here, $n$ is the length of the string, and $C$ is the size of the character set. In this problem, $C = 26$.

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### Rust



#### JavaScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### Solution 2

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### JavaScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def beautySum(self, s: str) -> int:
        ans, n = 0, len(s)
        for i in range(n):
            cnt = Counter()
            freq = Counter()
            mi = mx = 1
            for j in range(i, n):
                freq[cnt[s[j]]] -= 1
                cnt[s[j]] += 1
                freq[cnt[s[j]]] += 1

                if cnt[s[j]] == 1:
                    mi = 1
                if freq[mi] == 0:
                    mi += 1
                if cnt[s[j]] > mx:
                    mx = cnt[s[j]]

                ans += mx - mi
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int beautySum(String s) {
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int[] cnt = new int[26];
            Map<Integer, Integer> freq = new HashMap<>();
            int mi = 1, mx = 1;
            for (int j = i; j < n; ++j) {
                int k = s.charAt(j) - 'a';
                freq.merge(cnt[k], -1, Integer::sum);
                ++cnt[k];
                freq.merge(cnt[k], 1, Integer::sum);

                if (cnt[k] == 1) {
                    mi = 1;
                }
                if (freq.getOrDefault(mi, 0) == 0) {
                    ++mi;
                }
                if (cnt[k] > mx) {
                    mx = cnt[k];
                }
                ans += mx - mi;
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
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int cnt[26]{};
            unordered_map<int, int> freq;
            int mi = 1, mx = 1;
            for (int j = i; j < n; ++j) {
                int k = s[j] - 'a';
                --freq[cnt[k]];
                ++cnt[k];
                ++freq[cnt[k]];

                if (cnt[k] == 1) {
                    mi = 1;
                }
                if (freq[mi] == 0) {
                    ++mi;
                }
                if (cnt[k] > mx) {
                    mx = cnt[k];
                }
                ans += mx - mi;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func beautySum(s string) (ans int) {
	n := len(s)
	for i := 0; i < n; i++ {
		cnt := [26]int{}
		freq := map[int]int{}
		mi, mx := 1, 1
		for j := i; j < n; j++ {
			k := int(s[j] - 'a')
			freq[cnt[k]]--
			cnt[k]++
			freq[cnt[k]]++

			if cnt[k] == 1 {
				mi = 1
			}
			if freq[mi] == 0 {
				mi++
			}
			if cnt[k] > mx {
				mx = cnt[k]
			}
			ans += mx - mi
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function beautySum(s: string): number {
    let ans = 0;
    for (let i = 0; i < s.length; ++i) {
        const cnt = new Map();
        for (let j = i; j < s.length; ++j) {
            cnt.set(s[j], (cnt.get(s[j]) || 0) + 1);
            const t = Array.from(cnt.values());
            ans += Math.max(...t) - Math.min(...t);
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn beauty_sum(s: String) -> i32 {
        let mut ans = 0;
        let n = s.len();
        let s: Vec<char> = s.chars().collect();

        for i in 0..n {
            let mut cnt = vec![0; 26];
            for j in i..n {
                cnt[s[j] as usize - 'a' as usize] += 1;
                let mut mi = 1000;
                let mut mx = 0;
                for &v in &cnt {
                    if v > 0 {
                        mi = mi.min(v);
                        mx = mx.max(v);
                    }
                }
                ans += mx - mi;
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
 * @param {string} s
 * @return {number}
 */
var beautySum = function (s) {
    const n = s.length;
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        const cnt = Array(26).fill(0);
        const freq = new Map();
        let [mi, mx] = [1, 1];
        for (let j = i; j < n; ++j) {
            const k = s[j].charCodeAt() - 97;
            freq.set(cnt[k], (freq.get(cnt[k]) || 0) - 1);
            ++cnt[k];
            freq.set(cnt[k], (freq.get(cnt[k]) || 0) + 1);
            if (cnt[k] === 1) {
                mi = 1;
            }
            if (freq.get(mi) === 0) {
                ++mi;
            }
            if (cnt[k] > mx) {
                mx = cnt[k];
            }
            ans += mx - mi;
        }
    }
    return ans;
};
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def beautySum(self, s: str) -> int:
        ans, n = 0, len(s)
        for i in range(n):
            cnt = Counter()
            freq = Counter()
            mi = mx = 1
            for j in range(i, n):
                freq[cnt[s[j]]] -= 1
                cnt[s[j]] += 1
                freq[cnt[s[j]]] += 1

                if cnt[s[j]] == 1:
                    mi = 1
                if freq[mi] == 0:
                    mi += 1
                if cnt[s[j]] > mx:
                    mx = cnt[s[j]]

                ans += mx - mi
        return ans
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int beautySum(String s) {
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int[] cnt = new int[26];
            Map<Integer, Integer> freq = new HashMap<>();
            int mi = 1, mx = 1;
            for (int j = i; j < n; ++j) {
                int k = s.charAt(j) - 'a';
                freq.merge(cnt[k], -1, Integer::sum);
                ++cnt[k];
                freq.merge(cnt[k], 1, Integer::sum);

                if (cnt[k] == 1) {
                    mi = 1;
                }
                if (freq.getOrDefault(mi, 0) == 0) {
                    ++mi;
                }
                if (cnt[k] > mx) {
                    mx = cnt[k];
                }
                ans += mx - mi;
            }
        }
        return ans;
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
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int cnt[26]{};
            unordered_map<int, int> freq;
            int mi = 1, mx = 1;
            for (int j = i; j < n; ++j) {
                int k = s[j] - 'a';
                --freq[cnt[k]];
                ++cnt[k];
                ++freq[cnt[k]];

                if (cnt[k] == 1) {
                    mi = 1;
                }
                if (freq[mi] == 0) {
                    ++mi;
                }
                if (cnt[k] > mx) {
                    mx = cnt[k];
                }
                ans += mx - mi;
            }
        }
        return ans;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}