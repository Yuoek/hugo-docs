---
title: "day_0017 "
date: 2025-09-14T11:16:59+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0017 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        d = ["abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        ans = [""]
        for i in digits:
            s = d[int(i) - 2]
            ans = [a + b for a in ans for b in s]
        return ans 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        vector<string> d = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans = {""};
        for (auto& i : digits) {
            string s = d[i - '2'];
            vector<string> t;
            for (auto& a : ans) {
                for (auto& b : s) {
                    t.push_back(a + b);
                }
            }
            ans = move(t);
        }
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public List<String> letterCombinations(String digits) {
        List<String> ans = new ArrayList<>();
        if (digits.length() == 0) {
            return ans;
        }
        ans.add("");
        String[] d = new String[] {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for (char i : digits.toCharArray()) {
            String s = d[i - '2'];
            List<String> t = new ArrayList<>();
            for (String a : ans) {
                for (String b : s.split("")) {
                    t.add(a + b);
                }
            }
            ans = t;
        }
        return ans;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0017  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python 
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:  # 如果输入为空字符串
            return []  # 返回空列表
        d = ["abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]  # 数字到字母的映射表
        ans = [""]  # 初始化结果列表，包含一个空字符串
        for i in digits:  # 遍历输入的数字字符串
            s = d[int(i) - 2]  # 获取当前数字对应的字母字符串
            ans = [a + b for a in ans for b in s]  # 组合已有结果和当前字母，生成新的组合
        return ans  # 返回所有可能的字母组合
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        vector<string> d = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans = {""};
        for (auto& i : digits) {
            string s = d[i - '2'];
            vector<string> t;
            for (auto& a : ans) {
                for (auto& b : s) {
                    t.push_back(a + b);
                }
            }
            ans = move(t);
        }
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public List<String> letterCombinations(String digits) {
        List<String> ans = new ArrayList<>();
        if (digits.length() == 0) {
            return ans;
        }
        ans.add("");
        String[] d = new String[] {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for (char i : digits.toCharArray()) {
            String s = d[i - '2'];
            List<String> t = new ArrayList<>();
            for (String a : ans) {
                for (String b : s.split("")) {
                    t.add(a + b);
                }
            }
            ans = t;
        }
        return ans;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0017  数学解释

```python 
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        d = ["abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        ans = [""]
        for i in digits:
            s = d[int(i) - 2]
            ans = [a + b for a in ans for b in s]
        return ans 
```


这段代码使用了**组合数学**和**笛卡尔积**的数学思想来解决电话号码字母组合问题。

## 数学思想解释：

1. **组合数学**：每个数字对应多个字母，需要找出所有可能的字母组合
2. **笛卡尔积**：每次迭代都是将当前结果集与新的字母集做笛卡尔积运算
3. **乘法原理**：总组合数 = 各数字对应字母数的乘积

## 具体实现：

- **初始化**：从空字符串 `[""]` 开始
- **迭代处理**：对每个数字：
  - 获取对应的字母字符串 `s`
  - 执行笛卡尔积：`[a + b for a in ans for b in s]`
  - 更新结果集 `ans`

## 数学表示：

设数字序列为 d₁d₂...dₙ，每个数字 dᵢ 对应字母集 Sᵢ
则所有组合 = S₁ × S₂ × ... × Sₙ （笛卡尔积）

## 示例：
对于 "23"：
- 第一次迭代：["a","b","c"] × [""] = ["a","b","c"]
- 第二次迭代：["d","e","f"] × ["a","b","c"] = ["ad","ae","af","bd","be","bf","cd","ce","cf"]

这种算法优雅地利用了笛卡尔积的数学性质，通过迭代构建所有可能的组合。
