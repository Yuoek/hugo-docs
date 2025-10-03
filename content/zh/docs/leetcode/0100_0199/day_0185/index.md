---
title: "day_0185 "
date: 2025-09-21T08:15:55+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0185 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
import pandas as pd


def top_three_salaries(
    employee: pd.DataFrame, department: pd.DataFrame
) -> pd.DataFrame:
    salary_cutoff = (
        employee.drop_duplicates(["salary", "departmentId"])
        .groupby("departmentId")["salary"]
        .nlargest(3)
        .groupby("departmentId")
        .min()
    )
    employee["Department"] = department.set_index("id")["name"][
        employee["departmentId"]
    ].values
    employee["cutoff"] = salary_cutoff[employee["departmentId"]].values
    return employee[employee["salary"] >= employee["cutoff"]].rename(
        columns={"name": "Employee", "salary": "Salary"}
    )[["Department", "Employee", "Salary"]] 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int x = 0;
        for (int v : nums) {
            x = (x << 1 | v) % 5;
            ans.push_back(x == 0);
        }
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public List<Boolean> prefixesDivBy5(int[] nums) {
        List<Boolean> ans = new ArrayList<>();
        int x = 0;
        for (int v : nums) {
            x = (x << 1 | v) % 5;
            ans.add(x == 0);
        }
        return ans;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0185  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
import pandas as pd  # 导入pandas库，用于数据处理和分析


def top_three_salaries(
    employee: pd.DataFrame, department: pd.DataFrame
) -> pd.DataFrame:
    # 计算每个部门排名前三的薪资阈值
    salary_cutoff = (
        employee.drop_duplicates(["salary", "departmentId"])  # 去除相同部门和薪资的重复记录
        .groupby("departmentId")["salary"]  # 按部门分组，选择薪资列
        .nlargest(3)  # 获取每个部门薪资排名前三的值
        .groupby("departmentId")  # 再次按部门分组
        .min()  # 取每个部门前三薪资中的最小值（即第三高的薪资）
    )
    
    # 将部门名称映射到员工表中
    employee["Department"] = department.set_index("id")["name"][
        employee["departmentId"]
    ].values
    
    # 将每个部门的薪资阈值映射到对应的员工记录
    employee["cutoff"] = salary_cutoff[employee["departmentId"]].values
    
    # 筛选出薪资大于等于部门前三薪资阈值的员工
    return employee[employee["salary"] >= employee["cutoff"]].rename(
        columns={"name": "Employee", "salary": "Salary"}  # 重命名列名
    )[["Department", "Employee", "Salary"]]  # 选择需要的列返回
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int x = 0;
        for (int v : nums) {
            x = (x << 1 | v) % 5;
            ans.push_back(x == 0);
        }
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}
class Solution {
    public List<Boolean> prefixesDivBy5(int[] nums) {
        List<Boolean> ans = new ArrayList<>();
        int x = 0;
        for (int v : nums) {
            x = (x << 1 | v) % 5;
            ans.add(x == 0);
        }
        return ans;
    }
}
{{% /tab %}}{{< /tabs>}}

## LeetCode_0185  数学解释

```python 
import pandas as pd


def top_three_salaries(
    employee: pd.DataFrame, department: pd.DataFrame
) -> pd.DataFrame:
    salary_cutoff = (
        employee.drop_duplicates(["salary", "departmentId"])
        .groupby("departmentId")["salary"]
        .nlargest(3)
        .groupby("departmentId")
        .min()
    )
    employee["Department"] = department.set_index("id")["name"][
        employee["departmentId"]
    ].values
    employee["cutoff"] = salary_cutoff[employee["departmentId"]].values
    return employee[employee["salary"] >= employee["cutoff"]].rename(
        columns={"name": "Employee", "salary": "Salary"}
    )[["Department", "Employee", "Salary"]] 
```


这段代码使用了多种数学思想来解决"每个部门前三高工资"的问题：

## 1. 集合思想（去重处理）
`drop_duplicates(["salary", "departmentId"])` 体现了集合的唯一性概念，确保每个部门内的相同工资只计算一次。

## 2. 排序与选择思想
`nlargest(3)` 使用了排序算法中的top-k选择思想，找出每个部门的前三大工资值。

## 3. 极值思想
`.min()` 应用了极值理论，对于每个部门的前三大工资，取最小值作为临界值（即第三高的工资）。

## 4. 映射思想
通过`department.set_index("id")["name"][employee["departmentId"]].values`实现部门ID到部门名称的映射，这是函数映射概念的体现。

## 5. 不等式筛选
`employee[employee["salary"] >= employee["cutoff"]]` 使用不等式条件进行数据筛选，这是数学中条件判断的体现。

## 6. 分组聚合思想
`groupby("departmentId")` 体现了数据分组的数学概念，将问题分解为各个独立的子问题（按部门处理）。

## 算法复杂度分析：
- 去重操作：O(n)
- 分组和排序：O(n log n) 最坏情况
- 映射操作：O(n)
- 筛选操作：O(n)

总体时间复杂度约为 O(n log n)，空间复杂度为 O(n)。

