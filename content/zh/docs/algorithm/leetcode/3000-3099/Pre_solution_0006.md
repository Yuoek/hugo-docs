---
title: "3050_披萨配料成本分析 🔒"
date: 2025-10-08T18:39:55+08:00
weight: 6
tags: [数据库]
---

{{< markmap >}}
### [3050_披萨配料成本分析 🔒](#3050)
#### [数据库](#3050)
### [3051_寻找数据科学家职位的候选人 🔒](#3051)
#### [数据库](#3051)
### [3052_最大化商品 🔒](#3052)
#### [数据库](#3052)
### [3053_根据长度分类三角形 🔒](#3053)
#### [数据库](#3053)
### [3054_二叉树节点 🔒](#3054)
#### [数据库](#3054)
### [3055_最高欺诈百分位数 🔒](#3055)
#### [数据库](#3055)
### [3056_快照分析 🔒](#3056)
#### [数据库](#3056)
### [3057_员工项目分配 🔒](#3057)
#### [数据库](#3057)
### [3058_没有共同朋友的朋友 🔒](#3058)
#### [数据库](#3058)
### [3059_找到所有不同的邮件域名 🔒](#3059)
#### [数据库](#3059)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 3050_披萨配料成本分析 🔒
___
#### 数据库
---
### 3051_寻找数据科学家职位的候选人 🔒
___
#### 数据库
---
### 3052_最大化商品 🔒
___
#### 数据库
---
### 3053_根据长度分类三角形 🔒
___
#### 数据库
---
### 3054_二叉树节点 🔒
___
#### 数据库
---
### 3055_最高欺诈百分位数 🔒
___
#### 数据库
---
### 3056_快照分析 🔒
___
#### 数据库
---
### 3057_员工项目分配 🔒
___
#### 数据库
---
### 3058_没有共同朋友的朋友 🔒
___
#### 数据库
---
### 3059_找到所有不同的邮件域名 🔒
___
#### 数据库
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 数据库 |  |  |

# [3050. 披萨配料成本分析 🔒](https://leetcode.cn/problems/pizza-toppings-cost-analysis){#3050}

{{< tabs "3050" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT *, RANK() OVER (ORDER BY topping_name) AS rk
        FROM Toppings
    )
SELECT
    CONCAT(t1.topping_name, ',', t2.topping_name, ',', t3.topping_name) AS pizza,
    t1.cost + t2.cost + t3.cost AS total_cost
FROM
    T AS t1
    JOIN T AS t2 ON t1.rk < t2.rk
    JOIN T AS t3 ON t2.rk < t3.rk
ORDER BY 2 DESC, 1 ASC;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code><font face="monospace">Toppings</font></code></p>

<pre>
+--------------+---------+ 
| Column Name  | Type    | 
+--------------+---------+ 
| topping_name | varchar | 
| cost         | decimal |
+--------------+---------+
topping_name 是这张表的主键。
这张表的每一行包含配料名和配料的花费。
</pre>

<p>编写一个解决方案根据给定的配料表来计算 <strong>所有可能的&nbsp;<code>3</code>&nbsp;种配料&nbsp;</strong>披萨组合的 <strong>总花费</strong>。总花费必须 <strong>舍入</strong> 到 <code>2</code> 位 <strong>整数</strong>。</p>

<p><strong>注意：</strong></p>

<ul>
	<li><strong>不要</strong>&nbsp;包含 <strong>重复</strong> 配料的披萨。例如，‘Pepperoni, Pepperoni, Onion Pizza’。</li>
	<li>配料 <strong>必须</strong> 以 <strong>字母顺序</strong> 排序。例如，'Chicken, Onions, Sausage'。'Onion, Sausage, Chicken' 不会被通过。</li>
</ul>

<p>返回结果表，以总花费 <strong>降序</strong> 排序，配料的组合 <strong>升序</strong> 排序。</p>

<p>返回格式如下所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong> 
Toppings 表：
+--------------+------+
| topping_name | cost |
+--------------+------+
| Pepperoni    | 0.50 |
| Sausage      | 0.70 |
| Chicken      | 0.55 |
| Extra Cheese | 0.40 |
+--------------+------+
<strong>输出：</strong> 
+--------------------------------+------------+
| pizza                          | total_cost | 
+--------------------------------+------------+
| Chicken,Pepperoni,Sausage      | 1.75       |  
| Chicken,Extra Cheese,Sausage   | 1.65       |
| Extra Cheese,Pepperoni,Sausage | 1.60       |
| Chicken,Extra Cheese,Pepperoni | 1.45       | 
+--------------------------------+------------+
<strong>解释：</strong> 
这三种配料只有四种不同的组合：
- Chicken, Pepperoni, Sausage：总花费是 $1.75 (Chicken $0.55，Pepperoni $0.50，Sausage $0.70)。
- Chicken, Extra Cheese, Sausage：总花费是 $1.65 (Chicken $0.55，Extra Cheese $0.40，Sausage $0.70)。
- Extra Cheese, Pepperoni, Sausage：总花费是 $1.60 (Extra Cheese $0.40，Pepperoni $0.50，Sausage $0.70)。
- Chicken, Extra Cheese, Pepperoni：总花费是 $1.45 (Chicken $0.55，Extra Cheese $0.40，Pepperoni $0.50)。
输出表根据总花费降序排序。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：窗口函数 + 条件连接

我们先使用窗口函数，按照 `topping_name` 字段对表进行排序，并为每一行添加一个 `rk` 字段，表示当前行的排名。

然后我们使用条件连接，连接三次表 `T`，分别为 `t1`, `t2`, `t3`。连接条件是 `t1.rk < t2.rk` 和 `t2.rk < t3.rk`。然后我们计算三个配料的总价，按照总价降序排序，再按照配料名升序排序。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT *, RANK() OVER (ORDER BY topping_name) AS rk
        FROM Toppings
    )
SELECT
    CONCAT(t1.topping_name, ',', t2.topping_name, ',', t3.topping_name) AS pizza,
    t1.cost + t2.cost + t3.cost AS total_cost
FROM
    T AS t1
    JOIN T AS t2 ON t1.rk < t2.rk
    JOIN T AS t3 ON t2.rk < t3.rk
ORDER BY 2 DESC, 1 ASC;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3051. 寻找数据科学家职位的候选人 🔒](https://leetcode.cn/problems/find-candidates-for-data-scientist-position){#3051}

{{< tabs "3051" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT candidate_id
FROM Candidates
WHERE skill IN ('Python', 'Tableau', 'PostgreSQL')
GROUP BY 1
HAVING COUNT(1) = 3
ORDER BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<font face="monospace"><code>Candidates</code></font></p>

<pre>
+--------------+---------+ 
| Column Name  | Type    | 
+--------------+---------+ 
| candidate_id | int     | 
| skill        | varchar |
+--------------+---------+
(candidate_id, skill) 是这张表的主键（有不同值的列）。
每一行包括 candidate_id 和 skill。
</pre>

<p>编写一个查询来找到最适合数据科学家职位的 <strong>候选人</strong>。应聘者必须精通 <strong>Python</strong>，<strong>Tableau </strong>和&nbsp;<strong>PostgreSQL</strong>。</p>

<p>返回结果表，以<em>&nbsp;</em><code>candidate_id</code>&nbsp;<strong>升序</strong> 排序。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong> 
Candidates 表：
+---------------+--------------+
| candidate_id  | skill        | 
+---------------+--------------+
| 123           | Python       |
| 234           | R            | 
| 123           | Tableau      | 
| 123           | PostgreSQL   | 
| 234           | PowerBI      | 
| 234           | SQL Server   | 
| 147           | Python       | 
| 147           | Tableau      | 
| 147           | Java         |
| 147           | PostgreSQL   |
| 256           | Tableau      |
| 102           | DataAnalysis |
+---------------+--------------+
<strong>输出：</strong> 
+--------------+
| candidate_id |  
+--------------+
| 123          |  
| 147          | 
+--------------+
<strong>解释：</strong> 
- 候选人 123 和 147 具备数据科学家职位必要的 Python，Tableau 和 PostgreSQL 技能。
- 候选人 234 和 102 不具备该职位所需的任何技能。
- 候选人 256 精通 Tableau 但没有掌握 Python 和 PostgreSQL。
输出表以 candidate_id 升序排序。
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：条件筛选 + 分组统计

我们首先筛选出具备 `Python`, `Tableau`, `PostgreSQL` 这三个技能的候选人，然后按照 `candidate_id` 进行分组统计，统计每个候选人具备的技能数量，最后筛选出具备这三个技能的候选人，并且按照 `candidate_id` 进行升序排序。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT candidate_id
FROM Candidates
WHERE skill IN ('Python', 'Tableau', 'PostgreSQL')
GROUP BY 1
HAVING COUNT(1) = 3
ORDER BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3052. 最大化商品 🔒](https://leetcode.cn/problems/maximize-items){#3052}

{{< tabs "3052" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT SUM(square_footage) AS s
        FROM Inventory
        WHERE item_type = 'prime_eligible'
    )
SELECT
    'prime_eligible' AS item_type,
    COUNT(1) * FLOOR(500000 / s) AS item_count
FROM
    Inventory
    JOIN T
WHERE item_type = 'prime_eligible'
UNION ALL
SELECT
    'not_prime',
    IFNULL(COUNT(1) * FLOOR(IF(s = 0, 500000, 500000 % s) / SUM(square_footage)), 0)
FROM
    Inventory
    JOIN T
WHERE item_type = 'not_prime';
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<font face="monospace"><code>Inventory</code></font></p>

<pre>
+----------------+---------+ 
| Column Name    | Type    | 
+----------------+---------+ 
| item_id        | int     | 
| item_type      | varchar |
| item_category  | varchar |
| square_footage | decimal |
+----------------+---------+
item_id 是这张表中有不同值的列。
每一行包含 item id，item type，item category 和 sqaure footage。
</pre>

<p>Leetcode 仓库想要最大化它能够在&nbsp;<code>500,000</code> 平方英尺的仓库中储存的商品数。他想要尽可能多地存储 <strong>主要</strong> 商品，然后用 <strong>剩下</strong> 的空间存储最大数量的 <strong>非主要</strong> 商品。</p>

<p>编写一个解决方案来找到能够在&nbsp;<code>500,000</code>&nbsp;平方英尺的仓库中存储&nbsp;<b>主要</b>&nbsp;和&nbsp;<strong>非主要</strong>&nbsp;商品的数量。输出商品类型&nbsp;<code>prime_eligible</code>&nbsp;和&nbsp;<code>not_prime</code>，以及能储存商品的最大数量。</p>

<p><strong>注意：</strong></p>

<ul>
	<li>商品 <strong>数</strong> 必须是一个整数。</li>
	<li>如果&nbsp;<strong>not_prime</strong>&nbsp;分类的数量是&nbsp;<code>0</code>，你应当对这部分分类 <strong>输出</strong>&nbsp;<code>0</code>&nbsp;。</li>
</ul>

<p>返回结果表，以商品数 <strong>升序</strong> 排序。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong> 
Inventory 表：
+---------+----------------+---------------+----------------+
| item_id | item_type      | item_category | square_footage | 
+---------+----------------+---------------+----------------+
| 1374    | prime_eligible | Watches       | 68.00          | 
| 4245    | not_prime      | Art           | 26.40          | 
| 5743    | prime_eligible | Software      | 325.00         | 
| 8543    | not_prime      | Clothing      | 64.50          |  
| 2556    | not_prime      | Shoes         | 15.00          |
| 2452    | prime_eligible | Scientific    | 85.00          |
| 3255    | not_prime      | Furniture     | 22.60          | 
| 1672    | prime_eligible | Beauty        | 8.50           |  
| 4256    | prime_eligible | Furniture     | 55.50          |
| 6325    | prime_eligible | Food          | 13.20          | 
+---------+----------------+---------------+----------------+
<strong>输出：</strong> 
+----------------+-------------+
| item_type      | item_count  | 
+----------------+-------------+
| prime_eligible | 5400        | 
| not_prime      | 8           | 
+----------------+-------------+
<strong>解释：</strong> 
- prime-eligible 分类包括总计 6 件商品，总面积为 555.20 (68 + 325 + 85 + 8.50 + 55.50 + 13.20) 平方英尺。可以存放这 6 种物品的 900 件组合，总计 5400 件，占地 499,680 平方英尺。
- 对于 not_prime 分类，共有 4 件商品，总面积为 128.50 平方英尺。在减去 prime-eligible 商品使用的空间之后 (500,000 - 499,680 = 320)，还有放 2 件 non-prime 商品的空间，在320平方英尺的面积内，共容纳 8 个 non-prime 商品。
输出表以商品数量降序排序。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：连接查询 + 合并

我们先计算出所有 prime_eligible 类型的物品的总面积，记录在 `T` 表的 `s` 字段中。

接下来，我们分别计算 prime_eligible 和 not_prime 类型的物品的数量。对于 prime_eligible 类型的物品，我们可以存储的份数是 $\lfloor \frac{500000}{s} \rfloor$，对于 not_prime 类型的物品，我们可以存储的份数是 $\lfloor \frac{500000 \mod s}{\sum \textit{s1}} \rfloor$。其中 $\sum \textit{s1}$ 是所有 not_prime 类型的物品的总面积。再分别乘上 prime_eligible 和 not_prime 类型的物品的数量，就是我们的结果。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT SUM(square_footage) AS s
        FROM Inventory
        WHERE item_type = 'prime_eligible'
    )
SELECT
    'prime_eligible' AS item_type,
    COUNT(1) * FLOOR(500000 / s) AS item_count
FROM
    Inventory
    JOIN T
WHERE item_type = 'prime_eligible'
UNION ALL
SELECT
    'not_prime',
    IFNULL(COUNT(1) * FLOOR(IF(s = 0, 500000, 500000 % s) / SUM(square_footage)), 0)
FROM
    Inventory
    JOIN T
WHERE item_type = 'not_prime';
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3053. 根据长度分类三角形 🔒](https://leetcode.cn/problems/classifying-triangles-by-lengths){#3053}

{{< tabs "3053" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    CASE
        WHEN A + B <= C
        OR A + C <= B
        OR B + C <= A THEN 'Not A Triangle'
        WHEN A = B
        AND B = c THEN 'Equilateral'
        WHEN (A = B) + (B = C) + (A = C) = 1 THEN 'Isosceles'
        ELSE 'Scalene'
    END AS triangle_type
FROM Triangles;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<font face="monospace"><code>Triangles</code></font></p>

<pre>
+-------------+------+ 
| Column Name | Type | 
+-------------+------+ 
| A           | int  | 
| B           | int  |
| C           | int  |
+-------------+------+
(A, B, C) 是这张表的主键。
每一行包含三角形三边的长度。
</pre>

<p>编写一个查询来找到 <strong>三角形</strong> 的类型。对于每一行输出下面的其中一个：</p>

<ul>
	<li><strong>Equilateral</strong>：<code>3</code>&nbsp;边长度相同的三角形。</li>
	<li><strong>Isosceles</strong>：<code>2</code>&nbsp;边长度相同的三角形。</li>
	<li><strong>Scalene</strong>：<code>3</code>&nbsp;边长度不同的三角形。</li>
	<li><strong>Not A Triangle</strong>：给定的&nbsp;<code>A</code>&nbsp;，<code>B</code>，<code>C</code>&nbsp;的值不能形成三角形。</li>
</ul>

<p>以 <strong>任何顺序</strong> 返回结果表。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入:</strong> 
Triangles 表：
+----+----+----+
| A  | B  | C  |
+----+----+----+
| 20 | 20 | 23 |
| 20 | 20 | 20 |
| 20 | 21 | 22 |
| 13 | 14 | 30 |
+----+----+----+
<strong>输出：</strong> 
+----------------+
| triangle_type  | 
+----------------+
| Isosceles      | 
| Equilateral    |
| Scalene        |
| Not A Triangle |
+----------------+
<strong>解释：</strong> 
- 第一行的值形成了等腰三角形，因为 A = B。
- 第二行的值形成了等边三角形，因为 A = B = C.
- 第三行的值形成了斜三角形，因为 A != B != C.
- 第四行中的值不能形成三角形，因为边 A 和边 B 的和不大于边 C。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：使用 CASE WHEN 语句

我们可以使用 `CASE WHEN` 语句来判断三角形的类型。

首先，我们需要判断三个边是否能够构成一个三角形。如果不能，我们返回 `Not A Triangle`。

然后，我们判断三个边的长度是否相等。如果相等，我们返回 `Equilateral`。

接着，我们判断是否有两个边的长度相等。如果有，我们返回 `Isosceles`。

否则，说明三个边的长度都不相等，我们返回 `Scalene`。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    CASE
        WHEN A + B <= C
        OR A + C <= B
        OR B + C <= A THEN 'Not A Triangle'
        WHEN A = B
        AND B = c THEN 'Equilateral'
        WHEN (A = B) + (B = C) + (A = C) = 1 THEN 'Isosceles'
        ELSE 'Scalene'
    END AS triangle_type
FROM Triangles;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3054. 二叉树节点 🔒](https://leetcode.cn/problems/binary-tree-nodes){#3054}

{{< tabs "3054" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT DISTINCT
    t1.N AS N,
    IF(t1.P IS NULL, 'Root', IF(t2.P IS NULL, 'Leaf', 'Inner')) AS Type
FROM
    Tree AS t1
    LEFT JOIN Tree AS t2 ON t1.N = t2.p
ORDER BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<font face="monospace"><code>Tree</code></font></p>

<pre>
+-------------+------+ 
| Column Name | Type | 
+-------------+------+ 
| N           | int  | 
| P           | int  |
+-------------+------+
N 是这张表中具有不同值的列。
每一行中包含 N 和 P，其中 N 表示二叉树中节点的值，P 是 N 的父亲。
</pre>

<p>编写一个解决方案来找到二进制树节点的类型。对于每个节点输出：</p>

<ul>
	<li><strong>Root</strong>：如果节点是根节点。</li>
	<li><strong>Leaf</strong>：如果节点是叶子节点。</li>
	<li><strong>Inner</strong>: 如果节点既不是根节点，也不是叶子节点。</li>
</ul>

<p>返回结果表，根据节点值 <strong>升序排序</strong>。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Tree 表：
+---+------+
| N | P    | 
+---+------+
| 1 | 2    |
| 3 | 2    | 
| 6 | 8    | 
| 9 | 8    | 
| 2 | 5    | 
| 8 | 5    | 
| 5 | null | 
+---+------+
<strong>输出：</strong>
+---+-------+
| N | Type  | 
+---+-------+
| 1 | Leaf  | 
| 2 | Inner |
| 3 | Leaf  |
| 5 | Root  |
| 6 | Leaf  |
| 8 | Inner |
| 9 | Leaf  |    
+---+-------+
<strong>解释：</strong>
- 节点 5 是根节点，因为它没有父节点。
- 节点 1，3，6 和 8 是叶节点，因为它们没有任何子节点。
- 节点 2，4，7 是内部节点，因为它们充当结构中某些节点的父节点。
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：左连接

如果一个节点的父节点为空，则它是根节点；如果一个节点不是任何节点的父节点，则它是叶子节点；否则它是内部节点。

因此，我们使用左连接来连接两次 `Tree` 表，连接条件是 `t1.N = t2.P`。那么如果 `t1.P` 为空，则 `t1.N` 是根节点；如果 `t2.P` 为空，则 `t1.N` 是叶子节点；否则 `t1.N` 是内部节点。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT DISTINCT
    t1.N AS N,
    IF(t1.P IS NULL, 'Root', IF(t2.P IS NULL, 'Leaf', 'Inner')) AS Type
FROM
    Tree AS t1
    LEFT JOIN Tree AS t2 ON t1.N = t2.p
ORDER BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3055. 最高欺诈百分位数 🔒](https://leetcode.cn/problems/top-percentile-fraud){#3055}

{{< tabs "3055" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            *,
            RANK() OVER (
                PARTITION BY state
                ORDER BY fraud_score DESC
            ) AS rk
        FROM Fraud
    )
SELECT policy_id, state, fraud_score
FROM T
WHERE rk = 1
ORDER BY 2, 3 DESC, 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Fraud</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| policy_id   | int     |
| state       | varchar |
| fraud_score | int     |
+-------------+---------+
policy_id 是这张表中具有不同值的列。
这张表包含 policy id，state 和 fraud score。
</pre>

<p>Leetcode 保险公司开发了一个 ML 驱动的 <strong>预测模型</strong> 来检测欺诈索赔的 <strong>可能性</strong>。因此，他们分配了经验最丰富的理赔员来处理前 <code>5%</code> <strong>被标记</strong> 的索赔。</p>

<p>编写一个解决方案来找出 <strong>每个州</strong> 索赔的前 <code>5</code> <strong>百分位数</strong>。</p>

<p>返回结果表，以&nbsp;<code>state</code>&nbsp;<strong>升序&nbsp;</strong>排序，<code>fraud_score</code>&nbsp;<strong>降序</strong> 排序，<code>policy_id</code>&nbsp;<strong>升序</strong> 排序。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Fraud 表：
+-----------+------------+-------------+
| policy_id | state      | fraud_score | 
+-----------+------------+-------------+
| 1         | California | 0.92        | 
| 2         | California | 0.68        |   
| 3         | California | 0.17        | 
| 4         | New York   | 0.94        | 
| 5         | New York   | 0.81        | 
| 6         | New York   | 0.77        |  
| 7         | Texas      | 0.98        |  
| 8         | Texas      | 0.97        | 
| 9         | Texas      | 0.96        | 
| 10        | Florida    | 0.97        |  
| 11        | Florida    | 0.98        | 
| 12        | Florida    | 0.78        | 
| 13        | Florida    | 0.88        | 
| 14        | Florida    | 0.66        | 
+-----------+------------+-------------+
<strong>输出：</strong> 
+-----------+------------+-------------+
| policy_id | state      | fraud_score |
+-----------+------------+-------------+
| 1         | California | 0.92        | 
| 11        | Florida    | 0.98        | 
| 4         | New York   | 0.94        | 
| 7         | Texas      | 0.98        |  
+-----------+------------+-------------+
<strong>解释：</strong>
- 对于 California 州，只有 ID 为 1 的保单的欺诈分数为 0.92，属于该州的前 5%。
- 对于 Florida 州，只有 ID 为 11 的保单的欺诈分数为 0.98，属于该州的前 5%。
- 对于 New York 州，只有 ID 为 4 的保单的欺诈分数为 0.94，属于该州的前 5%。
- 对于 Texas 州，只有 ID 为 7 的保单的欺诈分数为 0.98，属于该州的前 5%。
输出表以&nbsp;<code>state</code>&nbsp;升序排序，<code>fraud_score</code>&nbsp;降序排序，<code>policy_id</code>&nbsp;升序排序。
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：使用窗口函数

我们可以使用 `RANK()` 窗口函数来计算每个州的欺诈分数的排名，然后筛选出排名为 1 的记录，并且按照题目要求排序。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            *,
            RANK() OVER (
                PARTITION BY state
                ORDER BY fraud_score DESC
            ) AS rk
        FROM Fraud
    )
SELECT policy_id, state, fraud_score
FROM T
WHERE rk = 1
ORDER BY 2, 3 DESC, 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3056. 快照分析 🔒](https://leetcode.cn/problems/snaps-analysis){#3056}

{{< tabs "3056" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    age_bucket,
    ROUND(100 * SUM(IF(activity_type = 'send', time_spent, 0)) / SUM(time_spent), 2) AS send_perc,
    ROUND(100 * SUM(IF(activity_type = 'open', time_spent, 0)) / SUM(time_spent), 2) AS open_perc
FROM
    Activities
    JOIN Age USING (user_id)
GROUP BY 1;
```
{{% /tab %}}
{{% tab "python" %}}
```python
import pandas as pd


def snap_analysis(activities: pd.DataFrame, age: pd.DataFrame) -> pd.DataFrame:
    merged_df = pd.merge(activities, age, on="user_id")
    total_time_per_age_activity = (
        merged_df.groupby(["age_bucket", "activity_type"])["time_spent"]
        .sum()
        .reset_index()
    )
    pivot_df = total_time_per_age_activity.pivot(
        index="age_bucket", columns="activity_type", values="time_spent"
    ).reset_index()
    pivot_df = pivot_df.fillna(0)
    pivot_df["send_perc"] = round(
        100 * pivot_df["send"] / (pivot_df["send"] + pivot_df["open"]), 2
    )
    pivot_df["open_perc"] = round(
        100 * pivot_df["open"] / (pivot_df["send"] + pivot_df["open"]), 2
    )
    return pivot_df[["age_bucket", "send_perc", "open_perc"]]
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Activities</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| activity_id   | int     |
| user_id       | int     |
| activity_type | enum    |
| time_spent    | decimal |
+---------------+---------+
activity_id 是这张表中值互不相同的列。
activity_type 是一个 ('send', 'open') 的 ENUM (category)。
这张表包含 activity id，user id，activity type 和 time spent。
</pre>

<p>表：<code>Age</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| user_id     | int  |
| age_bucket  | enum |
+-------------+------+
user_id 是这张表中有不同值的列。
age_bucket 是一个 ('21-25', '26-30', '31-35') 的 ENUM (category)。
这张表包含 user id 和 age 组。</pre>

<p>编写一个解决方案来计算 <strong>每个年龄组</strong> <strong>发送</strong> 和 <strong>打开快照</strong> 所花费的总时间 <strong>百分比</strong>。百分比应 <strong>四舍五入</strong> 至小数点后 <code>2</code> 位。</p>

<p>以 <strong>任何</strong> 顺序返回结果表。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong> 
Activities 表：
+-------------+---------+---------------+------------+
| activity_id | user_id | activity_type | time_spent |
+-------------+---------+---------------+------------+
| 7274        | 123     | open          | 4.50       | 
| 2425        | 123     | send          | 3.50       | 
| 1413        | 456     | send          | 5.67       | 
| 2536        | 456     | open          | 3.00       | 
| 8564        | 456     | send          | 8.24       | 
| 5235        | 789     | send          | 6.24       | 
| 4251        | 123     | open          | 1.25       | 
| 1435        | 789     | open          | 5.25       | 
+-------------+---------+---------------+------------+
Age 表：
+---------+------------+
| user_id | age_bucket | 
+---------+------------+
| 123     | 31-35      | 
| 789     | 21-25      | 
| 456     | 26-30      | 
+---------+------------+
<strong>输出：</strong> 
+------------+-----------+-----------+
| age_bucket | send_perc | open_perc |
+------------+-----------+-----------+
| 31-35      | 37.84     | 62.16     |
| 26-30      | 82.26     | 17.74     |
| 21-25      | 54.31     | 45.69     |
+------------+-----------+-----------+
<strong>解释：</strong> 
对于年龄组 31-35：
  - 只有一个用户属于该组，用户 ID 为 123。
  - 该用户花费在发送快照上的总时间为 3.50，并且花费在打开快照上的时间为 4.50 + 1.25 = 5.75。
  - 用户花费的总时间为 3.50 + 5.75 = 9.25。
  - 因此，发送快照百分比为 (3.50 / 9.25) * 100 = 37.84，并且打开快照百分比为 (5.75 / 9.25) * 100 = 62.16。
对于年龄组 26-30：
  - 只有一个用户属于该组，用户 ID 为 456。
  - 该用户花费在发送快照上的总时间为 5.67 + 8.24 = 13.91，并且花费在打开快照上的时间为 3.00。
  - 用户花费的总时间为 13.91 + 3.00 = 16.91。
  - 因此，发送快照百分比为 (13.91 / 16.91) * 100 = 82.26，并且打开快照百分比为 (3.00 / 16.91) * 100 = 17.74。
对于年龄组 21-25：
  - 只有一个用户属于该组，用户 ID 为 789。
  - 该用户花费在发送快照上的总时间为 6.24，并且花费在打开快照上的时间为 5.25。
  - 用户花费的总时间为 6.24 + 5.25 = 11.49。
  - 因此，发送快照百分比为 (6.24 / 11.49) * 100 = 54.31，并且打开快照百分比为 (5.25 / 11.49) * 100 = 45.69。
输出表中的所有百分比舍入到两位。
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：等值连接 + 分组求和

我们可以通过等值连接，将 `Activities` 表和 `Age` 表按照 `user_id` 进行连接，然后再按照 `age_bucket` 进行分组，最后计算每个年龄段的发送和打开的百分比。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    age_bucket,
    ROUND(100 * SUM(IF(activity_type = 'send', time_spent, 0)) / SUM(time_spent), 2) AS send_perc,
    ROUND(100 * SUM(IF(activity_type = 'open', time_spent, 0)) / SUM(time_spent), 2) AS open_perc
FROM
    Activities
    JOIN Age USING (user_id)
GROUP BY 1;
```

#### Python3

```python
import pandas as pd


def snap_analysis(activities: pd.DataFrame, age: pd.DataFrame) -> pd.DataFrame:
    merged_df = pd.merge(activities, age, on="user_id")
    total_time_per_age_activity = (
        merged_df.groupby(["age_bucket", "activity_type"])["time_spent"]
        .sum()
        .reset_index()
    )
    pivot_df = total_time_per_age_activity.pivot(
        index="age_bucket", columns="activity_type", values="time_spent"
    ).reset_index()
    pivot_df = pivot_df.fillna(0)
    pivot_df["send_perc"] = round(
        100 * pivot_df["send"] / (pivot_df["send"] + pivot_df["open"]), 2
    )
    pivot_df["open_perc"] = round(
        100 * pivot_df["open"] / (pivot_df["send"] + pivot_df["open"]), 2
    )
    return pivot_df[["age_bucket", "send_perc", "open_perc"]]
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3057. 员工项目分配 🔒](https://leetcode.cn/problems/employees-project-allocation){#3057}

{{< tabs "3057" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT team, AVG(workload) AS avg_workload
        FROM
            Project
            JOIN Employees USING (employee_id)
        GROUP BY 1
    )
SELECT
    employee_id,
    project_id,
    name AS employee_name,
    workload AS project_workload
FROM
    Project
    JOIN Employees USING (employee_id)
    JOIN T USING (team)
WHERE workload > avg_workload
ORDER BY 1, 2;
```
{{% /tab %}}
{{% tab "python" %}}
```python
import pandas as pd


def employees_with_above_avg_workload(
    project: pd.DataFrame, employees: pd.DataFrame
) -> pd.DataFrame:
    merged_df = pd.merge(project, employees, on="employee_id")
    avg_workload_per_team = merged_df.groupby("team")["workload"].mean().reset_index()
    merged_df = pd.merge(
        merged_df, avg_workload_per_team, on="team", suffixes=("", "_avg")
    )
    ans = merged_df[merged_df["workload"] > merged_df["workload_avg"]]
    ans = ans[["employee_id", "project_id", "name", "workload"]]
    ans = ans.rename(columns={"name": "employee_name", "workload": "project_workload"})
    return ans.sort_values(by=["employee_id", "project_id"])
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Project</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| project_id  | int     |
| employee_id | int     |
| workload    | int     |
+-------------+---------+
employee_id 是这张表的主键（有不同值的列）。
employee_id 是 Employee 表的外键（引用列）。
这张表的每一行表示 employee_id 所指的员工正在 project_id 所指的项目上工作，以及项目的工作量。
</pre>

<p>表：<code>Employees</code></p>

<pre>
+------------------+---------+
| Column Name      | Type    |
+------------------+---------+
| employee_id      | int     |
| name             | varchar |
| team             | varchar |
+------------------+---------+
employee_id 是这张表的主键（有不同值的列）。
这张表的每一行包含一个员工的信息。
</pre>

<p>编写一个解决方案，找出分配给项目的工作量 <strong>超过各自团队</strong> 所有员工 <strong>平均工作量</strong> 的 <strong>员工</strong>。</p>

<p>返回结果表，以&nbsp;<code>employee_id</code>，<code>project_id</code>&nbsp;<strong>升序</strong> 排序。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong> 
Project 表：
+-------------+-------------+----------+
| project_id  | employee_id | workload |
+-------------+-------------+----------+
| 1           | 1           |  45      |
| 1           | 2           |  90      | 
| 2           | 3           |  12      |
| 2           | 4           |  68      |
+-------------+-------------+----------+
Employees 表：
+-------------+--------+------+
| employee_id | name   | team |
+-------------+--------+------+
| 1           | Khaled | A    |
| 2           | Ali    | B    |
| 3           | John   | B    |
| 4           | Doe    | A    |
+-------------+--------+------+
<strong>输出：</strong> 
+-------------+------------+---------------+------------------+
| employee_id | project_id | employee_name | project_workload |
+-------------+------------+---------------+------------------+  
| 2           | 1          | Ali           | 90               | 
| 4           | 2          | Doe           | 68               | 
+-------------+------------+---------------+------------------+
<strong>解释：</strong> 
- ID 为 1 的员工项目工作量为 45 并属于 Team A，其中平均工作量为 56.50。因为这个项目工作量没有超过小组的平均工作量，他将被排除。
- ID 为 2 的员工项目工作量为 90 并属于 Team B，其中平均工作量为 51.00。因为这个项目工作量超过小组的平均工作量，他将包含在结果中。
- ID 为 3 的员工项目工作量为 12 并属于 Team B，其中平均工作量为 51.00。因为这个项目工作量没有超过小组的平均工作量，他将被排除。
- ID 为 4 的员工项目工作量为 68 并属于 Team A，其中平均工作量为 56.50。因为这个项目工作量超过小组的平均工作量，他将包含在结果中。
结果表以 employee_id，project_id 升序排序。
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分组统计 + 等值连接

我们先根据 `employee_id` 连接 `Project` 表和 `Employees` 表，然后再根据 `team` 分组统计每个团队的平均工作量，记录在临时表 `T` 中。

然后，我们再次连接 `Project` 表和 `Employees` 表，同时连接 `T` 表，找出工作量大于团队平均工作量的员工，并且按照 `employee_id` 和 `project_id` 排序。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT team, AVG(workload) AS avg_workload
        FROM
            Project
            JOIN Employees USING (employee_id)
        GROUP BY 1
    )
SELECT
    employee_id,
    project_id,
    name AS employee_name,
    workload AS project_workload
FROM
    Project
    JOIN Employees USING (employee_id)
    JOIN T USING (team)
WHERE workload > avg_workload
ORDER BY 1, 2;
```

#### Python3

```python
import pandas as pd


def employees_with_above_avg_workload(
    project: pd.DataFrame, employees: pd.DataFrame
) -> pd.DataFrame:
    merged_df = pd.merge(project, employees, on="employee_id")
    avg_workload_per_team = merged_df.groupby("team")["workload"].mean().reset_index()
    merged_df = pd.merge(
        merged_df, avg_workload_per_team, on="team", suffixes=("", "_avg")
    )
    ans = merged_df[merged_df["workload"] > merged_df["workload_avg"]]
    ans = ans[["employee_id", "project_id", "name", "workload"]]
    ans = ans.rename(columns={"name": "employee_name", "workload": "project_workload"})
    return ans.sort_values(by=["employee_id", "project_id"])
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3058. 没有共同朋友的朋友 🔒](https://leetcode.cn/problems/friends-with-no-mutual-friends){#3058}

{{< tabs "3058" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT user_id1, user_id2 FROM Friends
        UNION ALL
        SELECT user_id2, user_id1 FROM Friends
    )
SELECT user_id1, user_id2
FROM Friends
WHERE
    (user_id1, user_id2) NOT IN (
        SELECT t1.user_id1, t2.user_id1
        FROM
            T AS t1
            JOIN T AS t2 ON t1.user_id2 = t2.user_id2
    )
ORDER BY 1, 2;
```
{{% /tab %}}
{{% tab "python" %}}
```python
import pandas as pd


def friends_with_no_mutual_friends(friends: pd.DataFrame) -> pd.DataFrame:
    cp = friends.copy()
    t = cp[["user_id1", "user_id2"]].copy()
    t = pd.concat(
        [
            t,
            cp[["user_id2", "user_id1"]].rename(
                columns={"user_id2": "user_id1", "user_id1": "user_id2"}
            ),
        ]
    )
    merged = t.merge(t, left_on="user_id2", right_on="user_id2")
    ans = cp[
        ~cp.apply(
            lambda x: (x["user_id1"], x["user_id2"])
            in zip(merged["user_id1_x"], merged["user_id1_y"]),
            axis=1,
        )
    ]
    return ans.sort_values(by=["user_id1", "user_id2"])
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Friends</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| user_id1    | int  |
| user_id2    | int  |
+-------------+------+
(user_id1, user_id2) 是这张表的主键（有不同值的列组合）。
每一行包含 user id1, user id2，两人都是朋友。
</pre>

<p>编写一个解决方案来找到彼此是朋友但 <strong>没有共同 </strong>朋友的 <strong>所有用户对</strong>。</p>

<p>以&nbsp;<code>user_id1,</code> <code>user_id2</code><em>&nbsp;<strong>升序</strong> </em>返回结果表。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Friends 表：
+----------+----------+
| user_id1 | user_id2 | 
+----------+----------+
| 1        | 2        | 
| 2        | 3        | 
| 2        | 4        | 
| 1        | 5        | 
| 6        | 7        | 
| 3        | 4        | 
| 2        | 5        | 
| 8        | 9        | 
+----------+----------+
<strong>输出：</strong>
+----------+----------+
| user_id1 | user_id2 | 
+----------+----------+
| 6        | 7        | 
| 8        | 9        | 
+----------+----------+
<strong>解释：</strong> 
- 用户 1 和 2 是彼此的好友，但他们有一个用户 ID 为 5 的共同好友，因此结果不包含这一对。
- 用户 2 和 3 是朋友，他们有一个用户 ID 为 4 的共同好友，因此排除，类似地，对于具有用户 ID 为 3 的共同朋友的用户 2 和 4，也因此不包括在内。
- 用户 1 和 5 是彼此的好友，但他们有一个用户 ID 为 2 的共同好友，所以结果不包含这一对。
- 用户 6 和 7，与用户 8 和 9 一样，是彼此的好友，同时他们没有共同的好友，因此包含在结果中。
- 用户 3 和 4 是彼此的朋友，但他们有用户 ID 为 2 的共同好友，与用户 2 和 5 有用户 ID 为 1 的共同好友一样，因此被排除。
输出表以 user_id1 升序排列。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：子查询

我们先把所有的朋友关系都列出来，记录在 `T` 表中。然后再找出 没有共同朋友的朋友 🔒 对。

接下来，我们可以使用子查询来找出没有共同朋友的朋友 🔒 对，即这个朋友对不属于其他某个人的朋友。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT user_id1, user_id2 FROM Friends
        UNION ALL
        SELECT user_id2, user_id1 FROM Friends
    )
SELECT user_id1, user_id2
FROM Friends
WHERE
    (user_id1, user_id2) NOT IN (
        SELECT t1.user_id1, t2.user_id1
        FROM
            T AS t1
            JOIN T AS t2 ON t1.user_id2 = t2.user_id2
    )
ORDER BY 1, 2;
```

#### Python3

```python
import pandas as pd


def friends_with_no_mutual_friends(friends: pd.DataFrame) -> pd.DataFrame:
    cp = friends.copy()
    t = cp[["user_id1", "user_id2"]].copy()
    t = pd.concat(
        [
            t,
            cp[["user_id2", "user_id1"]].rename(
                columns={"user_id2": "user_id1", "user_id1": "user_id2"}
            ),
        ]
    )
    merged = t.merge(t, left_on="user_id2", right_on="user_id2")
    ans = cp[
        ~cp.apply(
            lambda x: (x["user_id1"], x["user_id2"])
            in zip(merged["user_id1_x"], merged["user_id1_y"]),
            axis=1,
        )
    ]
    return ans.sort_values(by=["user_id1", "user_id2"])
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3059. 找到所有不同的邮件域名 🔒](https://leetcode.cn/problems/find-all-unique-email-domains){#3059}

{{< tabs "3059" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT SUBSTRING_INDEX(email, '@', -1) AS email_domain, COUNT(1) AS count
FROM Emails
WHERE email LIKE '%.com'
GROUP BY 1
ORDER BY 1;
```
{{% /tab %}}
{{% tab "python" %}}
```python
import pandas as pd


def find_unique_email_domains(emails: pd.DataFrame) -> pd.DataFrame:
    emails["email_domain"] = emails["email"].str.split("@").str[-1]
    emails = emails[emails["email"].str.contains(".com")]
    return (
        emails.groupby("email_domain")
        .size()
        .reset_index(name="count")
        .sort_values(by="email_domain")
    )
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Emails</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| email       | varchar |
+-------------+---------+
id 是这张表的主键（有不同值的列）。
这张表的每一行包含一个电子邮件地址。电子邮件地址不包含大写字母。
</pre>

<p>编写一个解决方案来找到所有 <strong>不同的电子邮件域名</strong> 并且计数与每个域名相关联的 <strong>记录</strong>。<strong>只考虑</strong> 以 <strong>.com</strong> <strong>结尾</strong> 的域名。</p>

<p>返回结果表以 email_domains <strong>升序</strong> 排列。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>

<pre>
<strong>输入：</strong> 
Emails 表：
+-----+-----------------------+
| id  | email                 |
+-----+-----------------------+
| 336 | hwkiy@test.edu        |
| 489 | adcmaf@outlook.com    |
| 449 | vrzmwyum@yahoo.com    |
| 95  | tof@test.edu          |
| 320 | jxhbagkpm@example.org |
| 411 | zxcf@outlook.com      |
+----+------------------------+
<strong>输出：</strong> 
+--------------+-------+
| email_domain | count |
+--------------+-------+
| outlook.com  | 2     |
| yahoo.com    | 1     |  
+--------------+-------+
<strong>解释：</strong> 
- 以“.com”结束的合法域名只有“outlook.com”和“yahoo.com”，数量分别为 2 和 1。
输出表以 email_domains 升序排列。
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：使用 `SUBSTRING_INDEX` 函数 + 分组统计

我们先筛选出所有以 `.com` 结尾的邮箱，然后使用 `SUBSTRING_INDEX` 函数提取出邮箱的域名，最后使用 `GROUP BY` 统计每个域名的个数。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT SUBSTRING_INDEX(email, '@', -1) AS email_domain, COUNT(1) AS count
FROM Emails
WHERE email LIKE '%.com'
GROUP BY 1
ORDER BY 1;
```

#### Python3

```python
import pandas as pd


def find_unique_email_domains(emails: pd.DataFrame) -> pd.DataFrame:
    emails["email_domain"] = emails["email"].str.split("@").str[-1]
    emails = emails[emails["email"].str.contains(".com")]
    return (
        emails.groupby("email_domain")
        .size()
        .reset_index(name="count")
        .sort_values(by="email_domain")
    )
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
