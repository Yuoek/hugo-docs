---
title: "day_0183 "
date: 2025-09-21T08:23:36+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0183 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
import pandas as pd


def find_customers(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    # Select the customers whose 'id' is not present in the orders DataFrame's 'customerId' column.
    df = customers[~customers["id"].isin(orders["customerId"])]

    # Build a DataFrame that only contains the 'name' column and rename it as 'Customers'.
    df = df[["name"]].rename(columns={"name": "Customers"})

    return df 
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

## LeetCode_0183  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
import pandas as pd  # 导入pandas库，用于数据处理和分析


def find_customers(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    # 选择那些在orders表的'customerId'列中不存在的客户
    # 使用~符号进行取反操作，筛选出没有下过订单的客户
    df = customers[~customers["id"].isin(orders["customerId"])]

    # 从结果中只保留'name'列，并将其重命名为'Customers'
    # 构建一个只包含客户姓名的最终结果DataFrame
    df = df[["name"]].rename(columns={"name": "Customers"})

    return df  # 返回包含未下单客户姓名的DataFrame
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

## LeetCode_0183  数学解释

```python 
import pandas as pd


def find_customers(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    # Select the customers whose 'id' is not present in the orders DataFrame's 'customerId' column.
    df = customers[~customers["id"].isin(orders["customerId"])]

    # Build a DataFrame that only contains the 'name' column and rename it as 'Customers'.
    df = df[["name"]].rename(columns={"name": "Customers"})

    return df 
```


这段代码的数学思想可以用**集合论**来解释：

设：
- 所有客户集合：C = {c.id | c ∈ customers}
- 下过订单的客户集合：O = {o.customerId | o ∈ orders}

代码实现的是集合的**差集运算**：
- 结果 = C - O = {x | x ∈ C 且 x ∉ O}

具体数学操作：
1. `customers["id"].isin(orders["customerId"])` 相当于判断元素是否属于集合 O
2. `~` 运算符相当于取补集（非运算）
3. 最终得到的就是集合 C 中不属于集合 O 的元素

这体现了**集合的补集概念**，即找出那些从未下过订单的客户（存在于客户集合但不存在于订单客户集合中的元素）。

从关系代数的角度看，这相当于执行了一个**反连接（anti-join）**操作，返回左表中不与右表匹配的所有行。

