---
title: "0181_EmployeesEarningMoreThanTheirManagers"
date: 2025-10-06T00:42:37+08:00
weight: 0181
tags: [数据库]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [181. 超过经理收入的员工](https://leetcode.cn/problems/employees-earning-more-than-their-managers)

[English Version](../en/0181-81/0181_EmployeesEarningMoreThanTheirManagers)

## 题目描述

<!-- description:start -->

<p>表：<code>Employee</code>&nbsp;</p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
| salary      | int     |
| managerId   | int     |
+-------------+---------+
id 是该表的主键（具有唯一值的列）。
该表的每一行都表示雇员的ID、姓名、工资和经理的ID。
</pre>

<p>&nbsp;</p>

<p>编写解决方案，找出收入比经理高的员工。</p>

<p>以 <strong>任意顺序</strong> 返回结果表。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
Employee 表:
+----+-------+--------+-----------+
| id | name  | salary | managerId |
+----+-------+--------+-----------+
| 1  | Joe   | 70000  | 3         |
| 2  | Henry | 80000  | 4         |
| 3  | Sam   | 60000  | Null      |
| 4  | Max   | 90000  | Null      |
+----+-------+--------+-----------+
<strong>输出:</strong> 
+----------+
| Employee |
+----------+
| Joe      |
+----------+
<strong>解释:</strong> Joe 是唯一挣得比经理多的雇员。</pre>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：自连接 + 条件筛选

我们可以通过自连接 `Employee` 表，找出员工的工资以及其经理的工资，然后筛选出工资比经理高的员工。

<!-- tabs:start -->

#### Python3



#### MySQL



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
import pandas as pd


def find_employees(employee: pd.DataFrame) -> pd.DataFrame:
    merged = employee.merge(
        employee, left_on="managerId", right_on="id", suffixes=("", "_manager")
    )
    result = merged[merged["salary"] > merged["salary_manager"]][["name"]]
    result.columns = ["Employee"]
    return result
```
{{% /tab %}}
{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT e1.name Employee
FROM
    Employee e1
    JOIN Employee e2 ON e1.managerId = e2.id
WHERE e1.salary > e2.salary;
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
import pandas as pd


def find_employees(employee: pd.DataFrame) -> pd.DataFrame:
    merged = employee.merge(
        employee, left_on="managerId", right_on="id", suffixes=("", "_manager")
    )
    result = merged[merged["salary"] > merged["salary_manager"]][["name"]]
    result.columns = ["Employee"]
    return result
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}