---
title: "1781_SumofBeautyofAllSubstrings"
date: 2025-10-06T00:42:37+08:00
weight: 1781
tags: [哈希表, 字符串, 计数]
---


{{< katex />}}

{{< badge title="Difficulty" value="中等" >}}

<!-- problem:start -->

# [1781. 所有子字符串美丽值之和](https://leetcode.cn/problems/sum-of-beauty-of-all-substrings)

[English Version](../en/1781-81/1781_SumofBeautyofAllSubstrings)

## 题目描述

<!-- description:start -->

<p>一个字符串的 <strong>美丽值</strong> 定义为：出现频率最高字符与出现频率最低字符的出现次数之差。</p>

<ul>
	<li>比方说，<code>"abaacc"</code> 的美丽值为 <code>3 - 1 = 2</code> 。</li>
</ul>

<p>给你一个字符串 <code>s</code> ，请你返回它所有子字符串的 <strong>美丽值</strong> 之和。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>s = "aabcb"
<b>输出：</b>5
<strong>解释：</strong>美丽值不为零的字符串包括 ["aab","aabc","aabcb","abcb","bcb"] ，每一个字符串的美丽值都为 1 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>s = "aabcbaa"
<b>输出：</b>17
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= s.length <=<sup> </sup>500</code></li>
	<li><code>s</code> 只包含小写英文字母。</li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：枚举 + 计数

枚举每个子串的起点位置 $i$，找到以该起点位置的字符为左端点的所有子串，然后计算每个子串的美丽值，累加到答案中。

时间复杂度 $O(n^2 \times C)$，空间复杂度 $O(C)$。其中 $n$ 为字符串的长度，而 $C$ 为字符集的大小。本题中 $C = 26$。

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

### 方法二

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