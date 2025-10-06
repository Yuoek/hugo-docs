---
title: "3491_PhoneNumberPrefix"
date: 2025-10-06T00:42:37+08:00
weight: 3491
tags: [字典树, 数组, 字符串, 排序]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [3491. 电话号码前缀 🔒](https://leetcode.cn/problems/phone-number-prefix)

[English Version](../en/3491-91/3491_PhoneNumberPrefix)

## 题目描述

<!-- description:start -->

<p>给定一个字符串数组&nbsp;<code>numbers</code>&nbsp;表示电话号码。如果没有电话号码是任何其他电话号码的前缀，则返回 <code>true</code>；否则，返回 <code>false</code>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">numbers = ["1","2","4","3"]</span></p>

<p><span class="example-io"><b>输出：</b>true</span></p>

<p><strong>解释：</strong></p>

<p>没有数字是其它数字的前缀，所以输出为&nbsp;<code>true</code>。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>numbers = ["001","007","15","00153"]</span></p>

<p><span class="example-io"><b>输出：</b>false</span></p>

<p><b>解释：</b></p>

<p>字符串&nbsp;<code>"001"</code>&nbsp;是字符串&nbsp;<code>"00153"</code>&nbsp;的前缀。因此，输出是&nbsp;<code>false</code>。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= numbers.length &lt;= 50</code></li>
	<li><code>1 &lt;= numbers[i].length &lt;= 50</code></li>
	<li>所有数字只包含&nbsp;<code>'0'</code> 到&nbsp;<code>'9'</code>&nbsp;的数位。</li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：排序 + 前缀判断

我们可以先对 $\textit{numbers}$ 数组按照字符串长度进行排序，然后遍历数组中的每一个字符串 $\textit{s}$，判断此前是否有字符串 $\textit{t}$ 是 $\textit{s}$ 的前缀，如果有，说明存在一个字符串是另一个字符串的前缀，返回 $\textit{false}$。如果遍历完所有字符串都没有找到前缀关系，返回 $\textit{true}$。

时间复杂度 $(n^2 \times m + n \times \log n)$，空间复杂度 $(m + \log n)$，其中 $n$ 是 $\textit{numbers}$ 数组的长度，而 $m$ 是 $\textit{numbers}$ 数组中字符串的平均长度。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def phonePrefix(self, numbers: List[str]) -> bool:
        numbers.sort(key=len)
        for i, s in enumerate(numbers):
            if any(s.startswith(t) for t in numbers[:i]):
                return False
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean phonePrefix(String[] numbers) {
        Arrays.sort(numbers, (a, b) -> Integer.compare(a.length(), b.length()));
        for (int i = 0; i < numbers.length; i++) {
            String s = numbers[i];
            for (int j = 0; j < i; j++) {
                if (s.startsWith(numbers[j])) {
                    return false;
                }
            }
        }
        return true;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
#include <ranges>

class Solution {
public:
    bool phonePrefix(vector<string>& numbers) {
        ranges::sort(numbers, [](const string& a, const string& b) {
            return a.size() < b.size();
        });
        for (int i = 0; i < numbers.size(); i++) {
            if (ranges::any_of(numbers | views::take(i), [&](const string& t) {
                    return numbers[i].starts_with(t);
                })) {
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
func phonePrefix(numbers []string) bool {
	sort.Slice(numbers, func(i, j int) bool {
		return len(numbers[i]) < len(numbers[j])
	})
	for i, s := range numbers {
		for _, t := range numbers[:i] {
			if strings.HasPrefix(s, t) {
				return false
			}
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function phonePrefix(numbers: string[]): boolean {
    numbers.sort((a, b) => a.length - b.length);
    for (let i = 0; i < numbers.length; i++) {
        for (let j = 0; j < i; j++) {
            if (numbers[i].startsWith(numbers[j])) {
                return false;
            }
        }
    }
    return true;
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def phonePrefix(self, numbers: List[str]) -> bool:
        numbers.sort(key=len)
        for i, s in enumerate(numbers):
            if any(s.startswith(t) for t in numbers[:i]):
                return False
        return True
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public boolean phonePrefix(String[] numbers) {
        Arrays.sort(numbers, (a, b) -> Integer.compare(a.length(), b.length()));
        for (int i = 0; i < numbers.length; i++) {
            String s = numbers[i];
            for (int j = 0; j < i; j++) {
                if (s.startsWith(numbers[j])) {
                    return false;
                }
            }
        }
        return true;
    }
}
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "cpp 可视化" %}}
{{< pythontutor width="100%" height="800" language="cpp" >}}
#include <ranges>

class Solution {
public:
    bool phonePrefix(vector<string>& numbers) {
        ranges::sort(numbers, [](const string& a, const string& b) {
            return a.size() < b.size();
        });
        for (int i = 0; i < numbers.size(); i++) {
            if (ranges::any_of(numbers | views::take(i), [&](const string& t) {
                    return numbers[i].starts_with(t);
                })) {
                return false;
            }
        }
        return true;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}