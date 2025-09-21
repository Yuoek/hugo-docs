---
title: "day_0175 "
date: 2025-09-21T08:38:20+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0175 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
import pandas as pd


def combine_two_tables(person: pd.DataFrame, address: pd.DataFrame) -> pd.DataFrame:
    return pd.merge(left=person, right=address, how="left", on="personId")[
        ["firstName", "lastName", "city", "state"]
    ] 
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

## LeetCode_0175  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
import pandas as pd  # 导入pandas数据处理库，并简写为pd


def combine_two_tables(person: pd.DataFrame, address: pd.DataFrame) -> pd.DataFrame:
    # 使用左连接合并两个数据表，以personId作为连接键
    # 左连接保留person表的所有记录，address表中没有匹配的记录则填充为NaN
    return pd.merge(left=person, right=address, how="left", on="personId")[
        ["firstName", "lastName", "city", "state"]  # 从合并结果中只选择需要的四列
    ] 
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

## LeetCode_0175  数学解释

```python 
import pandas as pd


def combine_two_tables(person: pd.DataFrame, address: pd.DataFrame) -> pd.DataFrame:
    return pd.merge(left=person, right=address, how="left", on="personId")[
        ["firstName", "lastName", "city", "state"]
    ] 
```


这段代码体现了**关系代数中的左外连接（Left Outer Join）** 思想：

## 数学思想解释

设：
- 表 P (person) = {p | p ∈ Person 表的所有记录}
- 表 A (address) = {a | a ∈ Address 表的所有记录}
- 连接条件：P.personId = A.personId

左外连接的数学表达式为：
```
P ⟕ P.personId = A.personId A = { (p, a) | p ∈ P ∧ (∃a ∈ A: p.personId = a.personId ∨ a = null) }
```

## 具体解释：

1. **左外连接 (Left Outer Join)**：保留左表（person）的所有记录，即使右表（address）中没有匹配的记录

2. **投影操作 (Projection)**：从连接结果中只选择需要的列：
   - `["firstName", "lastName", "city", "state"]`
   - 数学上表示为：π(firstName, lastName, city, state)

3. **空值处理**：当 person 表中某人在 address 表中没有地址记录时，city 和 state 字段会自动填充为 NULL

## 数学意义：
这实现了两个关系的连接操作，确保左表的所有元组都出现在结果中，体现了**集合论中的并集思想**（保留所有左表元素）与**关系代数中的连接操作**的结合。


