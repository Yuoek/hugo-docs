---
title: "0017_LetterCombinationsofaPhoneNumber"
date: 2025-10-06T00:42:37+08:00
weight: 0017
tags: [哈希表, 字符串, 回溯]
---


{{< katex />}}

{{< badge title="Difficulty" value="中等" >}}

<!-- problem:start -->

# [17. 电话号码的字母组合](https://leetcode.cn/problems/letter-combinations-of-a-phone-number)

[English Version](../en/0017-17/0017_LetterCombinationsofaPhoneNumber)

## 题目描述

<!-- description:start -->

<p>给定一个仅包含数字&nbsp;<code>2-9</code>&nbsp;的字符串，返回所有它能表示的字母组合。答案可以按 <strong>任意顺序</strong> 返回。</p>

<p>给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。</p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0000-0099/0017.Letter%20Combinations%20of%20a%20Phone%20Number/images/1752723054-mfIHZs-image.png" style="width: 200px;" /></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>digits = "23"
<strong>输出：</strong>["ad","ae","af","bd","be","bf","cd","ce","cf"]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>digits = ""
<strong>输出：</strong>[]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>digits = "2"
<strong>输出：</strong>["a","b","c"]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= digits.length &lt;= 4</code></li>
	<li><code>digits[i]</code> 是范围 <code>['2', '9']</code> 的一个数字。</li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：遍历

我们先用一个数组或者哈希表存储每个数字对应的字母，然后遍历每个数字，将其对应的字母与之前的结果进行组合，得到新的结果。

时间复杂度 $O(4^n)$。空间复杂度 $O(4^n)$。其中 $n$ 是输入数字的长度。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### Rust



#### JavaScript



#### C#



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：DFS

我们可以使用深度优先搜索的方法，枚举所有可能的字母组合。假设当前已经产生了一部分字母组合，但是还有一些数字没有被穷举到，此时我们取出下一个数字所对应的字母，然后依次枚举这个数字所对应的每一个字母，将它们添加到前面已经产生的字母组合后面，形成所有可能的组合。

时间复杂度 $O(4^n)$。空间复杂度 $O(n)$。其中 $n$ 是输入数字的长度。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### Rust



#### JavaScript



#### C#



#### PHP



#### C



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        def dfs(i: int):
            if i >= len(digits):
                ans.append("".join(t))
                return
            for c in d[int(digits[i]) - 2]:
                t.append(c)
                dfs(i + 1)
                t.pop()

        if not digits:
            return []
        d = ["abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        ans = []
        t = []
        dfs(0)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private final String[] d = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    private String digits;
    private List<String> ans = new ArrayList<>();
    private StringBuilder t = new StringBuilder();

    public List<String> letterCombinations(String digits) {
        if (digits.length() == 0) {
            return ans;
        }
        this.digits = digits;
        dfs(0);
        return ans;
    }

    private void dfs(int i) {
        if (i >= digits.length()) {
            ans.add(t.toString());
            return;
        }
        String s = d[digits.charAt(i) - '2'];
        for (char c : s.toCharArray()) {
            t.append(c);
            dfs(i + 1);
            t.deleteCharAt(t.length() - 1);
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        vector<string> d = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string t;
        function<void(int)> dfs = [&](int i) {
            if (i >= digits.size()) {
                ans.push_back(t);
                return;
            }
            for (auto& c : d[digits[i] - '2']) {
                t.push_back(c);
                dfs(i + 1);
                t.pop_back();
            }
        };
        dfs(0);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func letterCombinations(digits string) (ans []string) {
	d := []string{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}
	t := []rune{}
	var dfs func(int)
	dfs = func(i int) {
		if i >= len(digits) {
			ans = append(ans, string(t))
			return
		}
		for _, c := range d[digits[i]-'2'] {
			t = append(t, c)
			dfs(i + 1)
			t = t[:len(t)-1]
		}
	}
	if len(digits) == 0 {
		return
	}
	dfs(0)
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function letterCombinations(digits: string): string[] {
    if (digits.length === 0) {
        return [];
    }
    const ans: string[] = [];
    const t: string[] = [];
    const d = ['abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz'];
    const dfs = (i: number) => {
        if (i >= digits.length) {
            ans.push(t.join(''));
            return;
        }
        const s = d[+digits[i] - 2];
        for (const c of s) {
            t.push(c);
            dfs(i + 1);
            t.pop();
        }
    };
    dfs(0);
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn letter_combinations(digits: String) -> Vec<String> {
        let d = ["abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"];
        let mut ans = Vec::new();
        let mut t = String::new();
        if digits.is_empty() {
            return ans;
        }
        Solution::dfs(&digits, &d, &mut t, &mut ans, 0);
        ans
    }

    fn dfs(digits: &String, d: &[&str; 8], t: &mut String, ans: &mut Vec<String>, i: usize) {
        if i >= digits.len() {
            ans.push(t.clone());
            return;
        }
        let s = d[((digits.chars().nth(i).unwrap() as u8) - b'2') as usize];
        for c in s.chars() {
            t.push(c);
            Solution::dfs(digits, d, t, ans, i + 1);
            t.pop();
        }
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function (digits) {
    if (digits.length === 0) {
        return [];
    }
    const ans = [];
    const t = [];
    const d = ['abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz'];
    const dfs = i => {
        if (i >= digits.length) {
            ans.push(t.join(''));
            return;
        }
        const s = d[+digits[i] - 2];
        for (const c of s) {
            t.push(c);
            dfs(i + 1);
            t.pop();
        }
    };
    dfs(0);
    return ans;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    private readonly string[] d = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    private string digits;
    private List<string> ans = new List<string>();
    private System.Text.StringBuilder t = new System.Text.StringBuilder();

    public IList<string> LetterCombinations(string digits) {
        if (digits.Length == 0) {
            return ans;
        }
        this.digits = digits;
        Dfs(0);
        return ans;
    }

    private void Dfs(int i) {
        if (i >= digits.Length) {
            ans.Add(t.ToString());
            return;
        }
        string s = d[digits[i] - '2'];
        foreach (char c in s) {
            t.Append(c);
            Dfs(i + 1);
            t.Remove(t.Length - 1, 1);
        }
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param string $digits
     * @return string[]
     */

    function letterCombinations($digits) {
        $digitMap = [
            '2' => ['a', 'b', 'c'],
            '3' => ['d', 'e', 'f'],
            '4' => ['g', 'h', 'i'],
            '5' => ['j', 'k', 'l'],
            '6' => ['m', 'n', 'o'],
            '7' => ['p', 'q', 'r', 's'],
            '8' => ['t', 'u', 'v'],
            '9' => ['w', 'x', 'y', 'z'],
        ];

        $combinations = [];

        backtrack($digits, '', 0, $digitMap, $combinations);

        return $combinations;
    }

    function backtrack($digits, $current, $index, $digitMap, &$combinations) {
        if ($index === strlen($digits)) {
            if ($current !== '') {
                $combinations[] = $current;
            }
            return;
        }

        $digit = $digits[$index];
        $letters = $digitMap[$digit];

        foreach ($letters as $letter) {
            backtrack($digits, $current . $letter, $index + 1, $digitMap, $combinations);
        }
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
char* d[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

char** letterCombinations(char* digits, int* returnSize) {
    if (!*digits) {
        *returnSize = 0;
        return NULL;
    }

    int size = 1;
    char** ans = (char**) malloc(sizeof(char*));
    ans[0] = strdup("");

    for (int x = 0; digits[x]; ++x) {
        char* s = d[digits[x] - '2'];
        int len = strlen(s);
        char** t = (char**) malloc(sizeof(char*) * size * len);
        int tSize = 0;

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < len; ++j) {
                int oldLen = strlen(ans[i]);
                char* tmp = (char*) malloc(oldLen + 2);
                strcpy(tmp, ans[i]);
                tmp[oldLen] = s[j];
                tmp[oldLen + 1] = '\0';
                t[tSize++] = tmp;
            }
            free(ans[i]);
        }
        free(ans);
        ans = t;
        size = tSize;
    }

    *returnSize = size;
    return ans;
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        def dfs(i: int):
            if i >= len(digits):
                ans.append("".join(t))
                return
            for c in d[int(digits[i]) - 2]:
                t.append(c)
                dfs(i + 1)
                t.pop()

        if not digits:
            return []
        d = ["abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        ans = []
        t = []
        dfs(0)
        return ans
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    private final String[] d = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    private String digits;
    private List<String> ans = new ArrayList<>();
    private StringBuilder t = new StringBuilder();

    public List<String> letterCombinations(String digits) {
        if (digits.length() == 0) {
            return ans;
        }
        this.digits = digits;
        dfs(0);
        return ans;
    }

    private void dfs(int i) {
        if (i >= digits.length()) {
            ans.add(t.toString());
            return;
        }
        String s = d[digits.charAt(i) - '2'];
        for (char c : s.toCharArray()) {
            t.append(c);
            dfs(i + 1);
            t.deleteCharAt(t.length() - 1);
        }
    }
}
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "c 可视化" %}}
{{< pythontutor width="100%" height="800" language="c" >}}
char* d[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

char** letterCombinations(char* digits, int* returnSize) {
    if (!*digits) {
        *returnSize = 0;
        return NULL;
    }

    int size = 1;
    char** ans = (char**) malloc(sizeof(char*));
    ans[0] = strdup("");

    for (int x = 0; digits[x]; ++x) {
        char* s = d[digits[x] - '2'];
        int len = strlen(s);
        char** t = (char**) malloc(sizeof(char*) * size * len);
        int tSize = 0;

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < len; ++j) {
                int oldLen = strlen(ans[i]);
                char* tmp = (char*) malloc(oldLen + 2);
                strcpy(tmp, ans[i]);
                tmp[oldLen] = s[j];
                tmp[oldLen + 1] = '\0';
                t[tSize++] = tmp;
            }
            free(ans[i]);
        }
        free(ans);
        ans = t;
        size = tSize;
    }

    *returnSize = size;
    return ans;
}
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "cpp 可视化" %}}
{{< pythontutor width="100%" height="800" language="cpp" >}}
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        vector<string> d = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string t;
        function<void(int)> dfs = [&](int i) {
            if (i >= digits.size()) {
                ans.push_back(t);
                return;
            }
            for (auto& c : d[digits[i] - '2']) {
                t.push_back(c);
                dfs(i + 1);
                t.pop_back();
            }
        };
        dfs(0);
        return ans;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}