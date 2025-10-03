---
title: "day_0180 "
date: 2025-09-21T08:28:53+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0180 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
import pandas as pd


def consecutive_numbers(logs: pd.DataFrame) -> pd.DataFrame:
    all_the_same = lambda lst: lst.nunique() == 1
    logs["is_consecutive"] = (
        logs["num"].rolling(window=3, center=True, min_periods=3).apply(all_the_same)
    )
    return (
        logs.query("is_consecutive == 1.0")[["num"]]
        .drop_duplicates()
        .rename(columns={"num": "ConsecutiveNums"})
    ) 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0180  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
import pandas as pd  # 导入pandas数据处理库

def consecutive_numbers(logs: pd.DataFrame) -> pd.DataFrame:
    # 定义辅助函数：检查列表中所有元素是否相同
    all_the_same = lambda lst: lst.nunique() == 1
    
    # 使用滚动窗口计算连续3个相同数字的标识
    # rolling(window=3): 创建大小为3的滑动窗口
    # center=True: 窗口居中，当前行位于窗口中间
    # min_periods=3: 至少需要3个有效值才进行计算
    logs["is_consecutive"] = (
        logs["num"].rolling(window=3, center=True, min_periods=3).apply(all_the_same)
    )
    
    # 返回结果DataFrame
    return (
        logs.query("is_consecutive == 1.0")[["num"]]  # 筛选出连续3个相同数字的行
        .drop_duplicates()  # 去除重复值
        .rename(columns={"num": "ConsecutiveNums"})  # 重命名列
    ) 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0180  数学解释

```python 
import pandas as pd


def consecutive_numbers(logs: pd.DataFrame) -> pd.DataFrame:
    all_the_same = lambda lst: lst.nunique() == 1
    logs["is_consecutive"] = (
        logs["num"].rolling(window=3, center=True, min_periods=3).apply(all_the_same)
    )
    return (
        logs.query("is_consecutive == 1.0")[["num"]]
        .drop_duplicates()
        .rename(columns={"num": "ConsecutiveNums"})
    ) 
```


这段代码使用了**滑动窗口（Rolling Window）**的数学思想来检测连续出现的数字。

具体数学原理：
1. **滑动窗口统计**：对每个位置，考虑其前后各一个元素（共3个元素的窗口）
2. **中心对齐**：`center=True`确保窗口以当前元素为中心
3. **唯一性检验**：`nunique() == 1`检查窗口内所有数字是否相同

数学表达：
对于序列中的每个位置 i，检查窗口 [i-1, i, i+1] 是否满足：
num[i-1] = num[i] = num[i+1]

这等价于寻找所有满足以下条件的数字 x：
∃ i 使得 ∀ j ∈ {i-1, i, i+1}, num[j] = x

代码通过滑动窗口的数学方法高效地识别了所有连续出现至少3次的数字，体现了**离散数学中的序列模式识别**思想。

