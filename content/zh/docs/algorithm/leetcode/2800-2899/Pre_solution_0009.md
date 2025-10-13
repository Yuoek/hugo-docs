---
title: "2880_数据选取"
date: 2025-10-08T18:39:37+08:00
weight: 9
tags: [Pandas]
---

{{< markmap >}}
### [2880_数据选取](#2880)
#### [Pandas](#2880)
### [2881_创建新列](#2881)
#### [Pandas](#2881)
### [2882_删去重复的行](#2882)
#### [Pandas](#2882)
### [2883_删去丢失的数据](#2883)
#### [Pandas](#2883)
### [2884_修改列](#2884)
#### [Pandas](#2884)
### [2885_重命名列](#2885)
#### [Pandas](#2885)
### [2886_改变数据类型](#2886)
#### [Pandas](#2886)
### [2887_填充缺失值](#2887)
#### [Pandas](#2887)
### [2888_重塑数据：连结](#2888)
#### [Pandas](#2888)
### [2889_数据重塑：透视](#2889)
#### [Pandas](#2889)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2880_数据选取
___
#### Pandas
---
### 2881_创建新列
___
#### Pandas
---
### 2882_删去重复的行
___
#### Pandas
---
### 2883_删去丢失的数据
___
#### Pandas
---
### 2884_修改列
___
#### Pandas
---
### 2885_重命名列
___
#### Pandas
---
### 2886_改变数据类型
___
#### Pandas
---
### 2887_填充缺失值
___
#### Pandas
---
### 2888_重塑数据：连结
___
#### Pandas
---
### 2889_数据重塑：透视
___
#### Pandas
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| Pandas |  |  |

# [2880. 数据选取](https://leetcode.cn/problems/select-data){#2880}

{{< tabs "2880" >}}

{{% tab "python" %}}
```python
import pandas as pd


def selectData(students: pd.DataFrame) -> pd.DataFrame:
    return students[students['student_id'] == 101][['name', 'age']]
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<pre>
DataFrame students
+-------------+--------+
| Column Name | Type   |
+-------------+--------+
| student_id  | int    |
| name        | object |
| age         | int    |
+-------------+--------+

</pre>

<p>编写一个解决方案，选择&nbsp;<code>student_id = 101</code>&nbsp;的学生的 name 和 age 并输出。</p>

<p>返回结果格式如下示例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<b>输入：</b>
+------------+---------+-----+
| student_id | name    | age |
+------------+---------+-----+
| 101        | Ulysses | 13  |
| 53         | William | 10  |
| 128        | Henry   | 6   |
| 3          | Henry   | 11  |
+------------+---------+-----+
<b>输出：</b>
+---------+-----+
| name    | age | 
+---------+-----+
| Ulysses | 13  |
+---------+-----+
<strong>解释：
</strong>学生 Ulysses 的 student_id = 101，所以我们输出了他的 name 和 age。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### Python3

```python
import pandas as pd


def selectData(students: pd.DataFrame) -> pd.DataFrame:
    return students[students['student_id'] == 101][['name', 'age']]
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2881. 创建新列](https://leetcode.cn/problems/create-a-new-column){#2881}

{{< tabs "2881" >}}

{{% tab "python" %}}
```python
import pandas as pd


def createBonusColumn(employees: pd.DataFrame) -> pd.DataFrame:
    employees['bonus'] = employees['salary'] * 2
    return employees
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<pre>
DataFrame <code>employees</code>
+-------------+--------+
| Column Name | Type.  |
+-------------+--------+
| name        | object |
| salary      | int.   |
+-------------+--------+
</pre>

<p>一家公司计划为员工提供奖金。</p>

<p>编写一个解决方案，创建一个名为&nbsp;<code>bonus</code>&nbsp;的新列，其中包含&nbsp;<code>salary</code>&nbsp;值的&nbsp;<strong>两倍</strong>。</p>

<p>返回结果格式如下示例所示。</p>

<p>&nbsp;</p>

<p><b>示例 1:</b></p>

<pre>
<b>输入：</b>
DataFrame employees
+---------+--------+
| name    | salary |
+---------+--------+
| Piper   | 4548   |
| Grace   | 28150  |
| Georgia | 1103   |
| Willow  | 6593   |
| Finn    | 74576  |
| Thomas  | 24433  |
+---------+--------+
<b>输出：</b>
+---------+--------+--------+
| name    | salary | bonus  |
+---------+--------+--------+
| Piper   | 4548   | 9096   |
| Grace   | 28150  | 56300  |
| Georgia | 1103   | 2206   |
| Willow  |  593   | 13186  |
| Finn    | 74576  | 149152 |
| Thomas  | 24433  | 48866  |
+---------+--------+--------+
<b>解释：</b>
通过将 salary 列中的值加倍创建了一个新的 bonus 列。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：直接计算

我们可以直接计算 `salary` 的两倍，然后将结果存入 `bonus` 列。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
import pandas as pd


def createBonusColumn(employees: pd.DataFrame) -> pd.DataFrame:
    employees['bonus'] = employees['salary'] * 2
    return employees
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2882. 删去重复的行](https://leetcode.cn/problems/drop-duplicate-rows){#2882}

{{< tabs "2882" >}}

{{% tab "python" %}}
```python
import pandas as pd


def dropDuplicateEmails(customers: pd.DataFrame) -> pd.DataFrame:
    return customers.drop_duplicates(subset=['email'])
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<pre>
DataFrame customers
+-------------+--------+
| Column Name | Type   |
+-------------+--------+
| customer_id | int    |
| name        | object |
| email       | object |
+-------------+--------+
</pre>

<p>在 DataFrame 中基于&nbsp;<code>email</code>&nbsp;列存在一些重复行。</p>

<p>编写一个解决方案，删除这些重复行，仅保留第一次出现的行。</p>

<p>返回结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<b>输入：</b>
+-------------+---------+---------------------+
| customer_id | name    | email               |
+-------------+---------+---------------------+
| 1           | Ella    | emily@example.com   |
| 2           | David   | michael@example.com |
| 3           | Zachary | sarah@example.com   |
| 4           | Alice   | john@example.com    |
| 5           | Finn    | john@example.com    |
| 6           | Violet  | alice@example.com   |
+-------------+---------+---------------------+
<b>输出：</b>
+-------------+---------+---------------------+
| customer_id | name    | email               |
+-------------+---------+---------------------+
| 1           | Ella    | emily@example.com   |
| 2           | David   | michael@example.com |
| 3           | Zachary | sarah@example.com   |
| 4           | Alice   | john@example.com    |
| 6           | Violet  | alice@example.com   |
+-------------+---------+---------------------+
<b>解释：</b>
Alice (customer_id = 4) 和 Finn (customer_id = 5) 都使用 john@example.com，因此只保留该邮箱地址的第一次出现。
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### Python3

```python
import pandas as pd


def dropDuplicateEmails(customers: pd.DataFrame) -> pd.DataFrame:
    return customers.drop_duplicates(subset=['email'])
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2883. 删去丢失的数据](https://leetcode.cn/problems/drop-missing-data){#2883}

{{< tabs "2883" >}}

{{% tab "python" %}}
```python
import pandas as pd


def dropMissingData(students: pd.DataFrame) -> pd.DataFrame:
    return students[students['name'].notnull()]
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<pre>
DataFrame students
+-------------+--------+
| Column Name | Type   |
+-------------+--------+
| student_id  | int    |
| name        | object |
| age         | int    |
+-------------+--------+
</pre>

<p>在 <code>name</code> 列里有一些具有缺失值的行。</p>

<p>编写一个解决方案，删除具有缺失值的行。</p>

<p>返回结果格式如下示例所示。</p>

<p>&nbsp;</p>

<p><b>示例 1:</b></p>

<pre>
<strong>输入：
</strong>+------------+---------+-----+
| student_id | name    | age |
+------------+---------+-----+
| 32         | Piper   | 5   |
| 217        | None    | 19  |
| 779        | Georgia | 20  |
| 849        | Willow  | 14  |
+------------+---------+-----+
<strong>输出：
</strong>+------------+---------+-----+
| student_id | name    | age |
+------------+---------+-----+
| 32         | Piper   | 5   |
| 779        | Georgia | 20  | 
| 849        | Willow  | 14  | 
+------------+---------+-----+
<b>解释：
</b>学号为 217 的学生所在行在 name 列中有空值，因此这一行将被删除。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### Python3

```python
import pandas as pd


def dropMissingData(students: pd.DataFrame) -> pd.DataFrame:
    return students[students['name'].notnull()]
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2884. 修改列](https://leetcode.cn/problems/modify-columns){#2884}

{{< tabs "2884" >}}

{{% tab "python" %}}
```python
import pandas as pd


def modifySalaryColumn(employees: pd.DataFrame) -> pd.DataFrame:
    employees['salary'] *= 2
    return employees
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<pre>
DataFrame <code>employees</code>
+-------------+--------+
| Column Name | Type   |
+-------------+--------+
| name        | object |
| salary      | int    |
+-------------+--------+
</pre>

<p>一家公司决定增加员工的薪水。</p>

<p>编写一个解决方案，将每个员工的薪水乘以2来 <strong>修改</strong>&nbsp;<code>salary</code>&nbsp;列。</p>

<p>返回结果格式如下示例所示。</p>

<p>&nbsp;</p>

<p><b>示例 1:</b></p>

<pre>
<strong>输入：
</strong>DataFrame employees
+---------+--------+
| name    | salary |
+---------+--------+
| Jack    | 19666  |
| Piper   | 74754  |
| Mia     | 62509  |
| Ulysses | 54866  |
+---------+--------+
<strong>输出：
</strong>+---------+--------+
| name    | salary |
+---------+--------+
| Jack    | 39332  |
| Piper   | 149508 |
| Mia     | 125018 |
| Ulysses | 109732 |
+---------+--------+
<strong>解释：
</strong>每个人的薪水都被加倍。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### Python3

```python
import pandas as pd


def modifySalaryColumn(employees: pd.DataFrame) -> pd.DataFrame:
    employees['salary'] *= 2
    return employees
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2885. 重命名列](https://leetcode.cn/problems/rename-columns){#2885}

{{< tabs "2885" >}}

{{% tab "python" %}}
```python
import pandas as pd


def renameColumns(students: pd.DataFrame) -> pd.DataFrame:
    students.rename(
        columns={
            'id': 'student_id',
            'first': 'first_name',
            'last': 'last_name',
            'age': 'age_in_years',
        },
        inplace=True,
    )
    return students
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<pre>
DataFrame <code>students</code>
+-------------+--------+
| Column Name | Type   |
+-------------+--------+
| id          | int    |
| first       | object |
| last        | object |
| age         | int    |
+-------------+--------+
</pre>

<p>编写一个解决方案，按以下方式重命名列：</p>

<ul>
	<li><code>id</code>&nbsp;重命名为&nbsp;<code>student_id</code></li>
	<li><code>first</code>&nbsp;重命名为&nbsp;<code>first_name</code></li>
	<li><code>last</code>&nbsp;重命名为&nbsp;<code>last_name</code></li>
	<li><code>age</code>&nbsp;重命名为&nbsp;<code>age_in_years</code></li>
</ul>

<p>返回结果格式如下示例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入：
</strong>+----+---------+----------+-----+
| id | first   | last     | age |
+----+---------+----------+-----+
| 1  | Mason   | King     | 6   |
| 2  | Ava     | Wright   | 7   |
| 3  | Taylor  | Hall     | 16  |
| 4  | Georgia | Thompson | 18  |
| 5  | Thomas  | Moore    | 10  |
+----+---------+----------+-----+
<b>输出：</b>
+------------+------------+-----------+--------------+
| student_id | first_name | last_name | age_in_years |
+------------+------------+-----------+--------------+
| 1          | Mason      | King      | 6            |
| 2          | Ava        | Wright    | 7            |
| 3          | Taylor     | Hall      | 16           |
| 4          | Georgia    | Thompson  | 18           |
| 5          | Thomas     | Moore     | 10           |
+------------+------------+-----------+--------------+
<b>解释：</b>
列名已相应更换。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### Python3

```python
import pandas as pd


def renameColumns(students: pd.DataFrame) -> pd.DataFrame:
    students.rename(
        columns={
            'id': 'student_id',
            'first': 'first_name',
            'last': 'last_name',
            'age': 'age_in_years',
        },
        inplace=True,
    )
    return students
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2886. 改变数据类型](https://leetcode.cn/problems/change-data-type){#2886}

{{< tabs "2886" >}}

{{% tab "python" %}}
```python
import pandas as pd


def changeDatatype(students: pd.DataFrame) -> pd.DataFrame:
    students['grade'] = students['grade'].astype(int)
    return students
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<pre>
DataFrame <code>students</code>
+-------------+--------+
| Column Name | Type   |
+-------------+--------+
| student_id  | int    |
| name        | object |
| age         | int    |
| grade       | float  |
+-------------+--------+
</pre>

<p>编写一个解决方案来纠正以下错误：</p>

<p>&nbsp;<code>grade</code>&nbsp;列被存储为浮点数，将它转换为整数。</p>

<p>返回结果格式如下示例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入：
</strong>DataFrame students:
+------------+------+-----+-------+
| student_id | name | age | grade |
+------------+------+-----+-------+
| 1          | Ava  | 6   | 73.0  |
| 2          | Kate | 15  | 87.0  |
+------------+------+-----+-------+
<strong>输出：
</strong>+------------+------+-----+-------+
| student_id | name | age | grade |
+------------+------+-----+-------+
| 1          | Ava  | 6   | 73    |
| 2          | Kate | 15  | 87    |
+------------+------+-----+-------+
<b>解释：</b>
grade 列的数据类型已转换为整数。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### Python3

```python
import pandas as pd


def changeDatatype(students: pd.DataFrame) -> pd.DataFrame:
    students['grade'] = students['grade'].astype(int)
    return students
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2887. 填充缺失值](https://leetcode.cn/problems/fill-missing-data){#2887}

{{< tabs "2887" >}}

{{% tab "python" %}}
```python
import pandas as pd


def fillMissingValues(products: pd.DataFrame) -> pd.DataFrame:
    products['quantity'] = products['quantity'].fillna(0)
    return products
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<pre>
DataFrame <code>products</code>
+-------------+--------+
| Column Name | Type   |
+-------------+--------+
| name        | object |
| quantity    | int    |
| price       | int    |
+-------------+--------+
</pre>

<p>编写一个解决方案，在 <code>quantity</code> 列中将缺失的值填充为&nbsp;<code><strong>0</strong></code>。</p>

<p>返回结果如下示例所示。</p>

<p>&nbsp;</p>
<strong class="example">示例 1：</strong>

<pre>
<strong>输入：
</strong>+-----------------+----------+-------+
| name            | quantity | price |
+-----------------+----------+-------+
| Wristwatch      | 32       | 135   |
| WirelessEarbuds | None     | 821   |
| GolfClubs       | None     | 9319  |
| Printer         | 849      | 3051  |
+-----------------+----------+-------+
<strong>输出：
</strong>+-----------------+----------+-------+
| name            | quantity | price |
+-----------------+----------+-------+
| Wristwatch      | 32       | 135   |
| WirelessEarbuds | 0        | 821   |
| GolfClubs       | 0        | 9319  |
| Printer         | 849      | 3051  |
+-----------------+----------+-------+
<b>解释：</b>
Toaster 和 Headphones 的数量被填充为 0。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### Python3

```python
import pandas as pd


def fillMissingValues(products: pd.DataFrame) -> pd.DataFrame:
    products['quantity'] = products['quantity'].fillna(0)
    return products
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2888. 重塑数据：连结](https://leetcode.cn/problems/reshape-data-concatenate){#2888}

{{< tabs "2888" >}}

{{% tab "python" %}}
```python
import pandas as pd


def concatenateTables(df1: pd.DataFrame, df2: pd.DataFrame) -> pd.DataFrame:
    return pd.concat([df1, df2], ignore_index=True)
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<pre>
DataFrame <code>df1</code>
+-------------+--------+
| Column Name | Type   |
+-------------+--------+
| student_id  | int    |
| name        | object |
| age         | int    |
+-------------+--------+

DataFrame <code>df2</code>
+-------------+--------+
| Column Name | Type   |
+-------------+--------+
| student_id  | int    |
| name        | object |
| age         | int    |
+-------------+--------+

</pre>

<p>编写一个解决方案，将两个&nbsp;DataFrames <b>垂直 </b>连接成一个&nbsp;DataFrame。</p>

<p>结果格式如下示例所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：
df1</strong>
+------------+---------+-----+
| student_id | name    | age |
+------------+---------+-----+
| 1          | Mason   | 8   |
| 2          | Ava     | 6   |
| 3          | Taylor  | 15  |
| 4          | Georgia | 17  |
+------------+---------+-----+
<strong>df2
</strong>+------------+------+-----+
| student_id | name | age |
+------------+------+-----+
| 5          | Leo  | 7   |
| 6          | Alex | 7   |
+------------+------+-----+
<b>输出：</b>
+------------+---------+-----+
| student_id | name    | age |
+------------+---------+-----+
| 1          | Mason   | 8   |
| 2          | Ava     | 6   |
| 3          | Taylor  | 15  |
| 4          | Georgia | 17  |
| 5          | Leo     | 7   |
| 6          | Alex    | 7   |
+------------+---------+-----+
<strong>解释：
</strong>两个 DataFrame 被垂直堆叠，它们的行被合并。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### Python3

```python
import pandas as pd


def concatenateTables(df1: pd.DataFrame, df2: pd.DataFrame) -> pd.DataFrame:
    return pd.concat([df1, df2], ignore_index=True)
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2889. 数据重塑：透视](https://leetcode.cn/problems/reshape-data-pivot){#2889}

{{< tabs "2889" >}}

{{% tab "python" %}}
```python
import pandas as pd


def pivotTable(weather: pd.DataFrame) -> pd.DataFrame:
    return weather.pivot(index='month', columns='city', values='temperature')
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<pre>
DataFrame <code>weather</code>
+-------------+--------+
| Column Name | Type   |
+-------------+--------+
| city        | object |
| month       | object |
| temperature | int    |
+-------------+--------+
</pre>

<p>编写一个解决方案，以便将数据&nbsp;<strong>旋转</strong>，使得每一行代表特定月份的温度，而每个城市都是一个单独的列。</p>

<p>输出结果格式如下示例所示。</p>

<p>&nbsp;</p>
<b>示例 1:</b>

<pre>
<b>输入：</b>
+--------------+----------+-------------+
| city         | month    | temperature |
+--------------+----------+-------------+
| Jacksonville | January  | 13          |
| Jacksonville | February | 23          |
| Jacksonville | March    | 38          |
| Jacksonville | April    | 5           |
| Jacksonville | May      | 34          |
| ElPaso       | January  | 20          |
| ElPaso       | February | 6           |
| ElPaso       | March    | 26          |
| ElPaso       | April    | 2           |
| ElPaso       | May      | 43          |
+--------------+----------+-------------+
<code><b>输出：</b>
+----------+--------+--------------+
| month    | ElPaso | Jacksonville |
+----------+--------+--------------+
| April    | 2      | 5            |
| February | 6      | 23           |
| January  | 20     | 13           |
| March    | 26     | 38           |
| May      | 43     | 34           |
+----------+--------+--------------+</code>
<strong>解释：
</strong>表格被旋转，每一列代表一个城市，每一行代表特定的月份。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### Python3

```python
import pandas as pd


def pivotTable(weather: pd.DataFrame) -> pd.DataFrame:
    return weather.pivot(index='month', columns='city', values='temperature')
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
