---
title: "day_0030 "
date: 2025-09-14T10:47:30+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0030 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        cnt = Counter(words)
        m, n = len(s), len(words)
        k = len(words[0])
        ans = []
        for i in range(k):
            l = r = i
            cnt1 = Counter()
            while r + k <= m:
                t = s[r : r + k]
                r += k
                if cnt[t] == 0:
                    l = r
                    cnt1.clear()
                    continue
                cnt1[t] += 1
                while cnt1[t] > cnt[t]:
                    rem = s[l : l + k]
                    l += k
                    cnt1[rem] -= 1
                if r - l == n * k:
                    ans.append(l)
        return ans 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> cnt;
        for (const auto& w : words) {
            cnt[w]++;
        }

        vector<int> ans;
        int m = s.length(), n = words.size(), k = words[0].length();

        for (int i = 0; i < k; ++i) {
            int l = i, r = i;
            unordered_map<string, int> cnt1;
            while (r + k <= m) {
                string t = s.substr(r, k);
                r += k;

                if (!cnt.contains(t)) {
                    cnt1.clear();
                    l = r;
                    continue;
                }

                cnt1[t]++;

                while (cnt1[t] > cnt[t]) {
                    string w = s.substr(l, k);
                    if (--cnt1[w] == 0) {
                        cnt1.erase(w);
                    }
                    l += k;
                }

                if (r - l == n * k) {
                    ans.push_back(l);
                }
            }
        }

        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        Map<String, Integer> cnt = new HashMap<>();
        for (var w : words) {
            cnt.merge(w, 1, Integer::sum);
        }
        List<Integer> ans = new ArrayList<>();
        int m = s.length(), n = words.length, k = words[0].length();
        for (int i = 0; i < k; ++i) {
            int l = i, r = i;
            Map<String, Integer> cnt1 = new HashMap<>();
            while (r + k <= m) {
                var t = s.substring(r, r + k);
                r += k;
                if (!cnt.containsKey(t)) {
                    cnt1.clear();
                    l = r;
                    continue;
                }
                cnt1.merge(t, 1, Integer::sum);
                while (cnt1.get(t) > cnt.get(t)) {
                    String w = s.substring(l, l + k);
                    if (cnt1.merge(w, -1, Integer::sum) == 0) {
                        cnt1.remove(w);
                    }
                    l += k;
                }
                if (r - l == n * k) {
                    ans.add(l);
                }
            }
        }
        return ans;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0030  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        cnt = Counter(words)  # 统计words中每个单词的出现次数
        m, n = len(s), len(words)  # m是字符串s的长度，n是单词列表words的长度
        k = len(words[0])  # 每个单词的长度（假设所有单词长度相同）
        ans = []  # 存储结果的列表
        
        # 遍历所有可能的起始位置（按单词长度k的余数分组）
        for i in range(k):
            l = r = i  # 初始化左右指针，l表示窗口左边界，r表示窗口右边界
            cnt1 = Counter()  # 当前窗口内单词的计数器
            
            # 滑动窗口遍历字符串
            while r + k <= m:
                t = s[r : r + k]  # 从当前位置截取长度为k的子串
                r += k  # 右指针向右移动k个位置
                
                # 如果当前单词不在words中，重置窗口
                if cnt[t] == 0:
                    l = r  # 左指针移动到右指针位置
                    cnt1.clear()  # 清空计数器
                    continue
                
                cnt1[t] += 1  # 当前单词计数加1
                
                # 如果当前单词出现次数超过words中的次数，移动左指针直到符合要求
                while cnt1[t] > cnt[t]:
                    rem = s[l : l + k]  # 获取窗口最左边的单词
                    l += k  # 左指针向右移动k个位置
                    cnt1[rem] -= 1  # 移除的单词计数减1
                
                # 如果窗口大小正好等于所有单词总长度，记录起始位置
                if r - l == n * k:
                    ans.append(l)  # 将左指针位置加入结果
        
        return ans  # 返回所有符合条件的起始位置
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> cnt;
        for (const auto& w : words) {
            cnt[w]++;
        }

        vector<int> ans;
        int m = s.length(), n = words.size(), k = words[0].length();

        for (int i = 0; i < k; ++i) {
            int l = i, r = i;
            unordered_map<string, int> cnt1;
            while (r + k <= m) {
                string t = s.substr(r, k);
                r += k;

                if (!cnt.contains(t)) {
                    cnt1.clear();
                    l = r;
                    continue;
                }

                cnt1[t]++;

                while (cnt1[t] > cnt[t]) {
                    string w = s.substr(l, k);
                    if (--cnt1[w] == 0) {
                        cnt1.erase(w);
                    }
                    l += k;
                }

                if (r - l == n * k) {
                    ans.push_back(l);
                }
            }
        }

        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        Map<String, Integer> cnt = new HashMap<>();
        for (var w : words) {
            cnt.merge(w, 1, Integer::sum);
        }
        List<Integer> ans = new ArrayList<>();
        int m = s.length(), n = words.length, k = words[0].length();
        for (int i = 0; i < k; ++i) {
            int l = i, r = i;
            Map<String, Integer> cnt1 = new HashMap<>();
            while (r + k <= m) {
                var t = s.substring(r, r + k);
                r += k;
                if (!cnt.containsKey(t)) {
                    cnt1.clear();
                    l = r;
                    continue;
                }
                cnt1.merge(t, 1, Integer::sum);
                while (cnt1.get(t) > cnt.get(t)) {
                    String w = s.substring(l, l + k);
                    if (cnt1.merge(w, -1, Integer::sum) == 0) {
                        cnt1.remove(w);
                    }
                    l += k;
                }
                if (r - l == n * k) {
                    ans.add(l);
                }
            }
        }
        return ans;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0030  数学解释

```python 
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        cnt = Counter(words)
        m, n = len(s), len(words)
        k = len(words[0])
        ans = []
        for i in range(k):
            l = r = i
            cnt1 = Counter()
            while r + k <= m:
                t = s[r : r + k]
                r += k
                if cnt[t] == 0:
                    l = r
                    cnt1.clear()
                    continue
                cnt1[t] += 1
                while cnt1[t] > cnt[t]:
                    rem = s[l : l + k]
                    l += k
                    cnt1[rem] -= 1
                if r - l == n * k:
                    ans.append(l)
        return ans 
```


这段代码使用了**滑动窗口**和**哈希计数**的数学思想来解决字符串匹配问题。

## 数学思想解析：

### 1. 滑动窗口思想
- 将问题转化为在字符串s中寻找一个固定长度的窗口（长度为n*k）
- 窗口从左向右滑动，每次移动k个单位（单词长度）
- 通过调整窗口左右边界来维护有效子串

### 2. 哈希计数思想
- 使用Counter统计words中每个单词的出现频率（目标频率）
- 使用另一个Counter统计当前窗口中每个单词的出现频率（实际频率）
- 通过比较两个频率分布来判断当前窗口是否满足条件

### 3. 模运算思想
- 由于所有单词长度相同（k），使用模k的起始位置分类
- 从0到k-1共k种起始位置，确保覆盖所有可能的子串起始位置

### 4. 双指针优化
- 左指针l和右指针r协同工作
- 当遇到不在words中的单词时，重置窗口
- 当某个单词出现次数超过目标值时，移动左指针直到满足条件

## 算法复杂度：
- 时间复杂度：O(k × m) = O(m)，其中m为字符串s的长度
- 空间复杂度：O(n)，用于存储单词频率

这种解法巧妙地利用了单词长度相同的特性，通过滑动窗口和哈希计数高效地解决了子串匹配问题。


