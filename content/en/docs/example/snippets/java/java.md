
## pythonlist
### 创建列表
```python
# 空列表
def listdemo():
    print("Hello")
empty_list = []
empty_list = list()


# 包含元素的列表
numbers = [1, 2, 3, 4, 5]
mixed = [1, "hello", 3.14, True]
nested = [[1, 2], [3, 4]]
```

### 列表特性
- **有序**：元素按插入顺序存储
- **可变**：可以修改、添加、删除元素
- **可重复**：允许包含重复元素
- **异构**：可以包含不同类型的元素


### 访问元素
```python
my_list = [10, 20, 30, 40, 50]

# 索引访问
print(my_list[0])    # 10
print(my_list[-1])   # 50（最后一个元素）

# 切片操作
print(my_list[1:3])  # [20, 30]
print(my_list[:3])   # [10, 20, 30]
print(my_list[2:])   # [30, 40, 50]
print(my_list[::2])  # [10, 30, 50]（步长为2）
```

### 修改元素
```python
my_list = [1, 2, 3, 4]
my_list[0] = 100     # [100, 2, 3, 4]
my_list[1:3] = [200, 300]  # [100, 200, 300, 4]
```


### 添加元素
```python
my_list = [1, 2, 3]

# 末尾添加
my_list.append(4)        # [1, 2, 3, 4]

# 指定位置插入
my_list.insert(1, 1.5)   # [1, 1.5, 2, 3, 4]

# 合并列表
my_list.extend([5, 6])   # [1, 1.5, 2, 3, 4, 5, 6]
```

### 删除元素
```python
my_list = [1, 2, 3, 2, 4]

# 按值删除（第一个匹配项）
my_list.remove(2)        # [1, 3, 2, 4]

# 按索引删除
del my_list[0]           # [3, 2, 4]
popped = my_list.pop()   # 返回4，列表变为[3, 2]
popped = my_list.pop(0)  # 返回3，列表变为[2]

# 清空列表
my_list.clear()          # []
```

### 查找和统计
```python
my_list = [1, 2, 3, 2, 4]

# 查找索引
index = my_list.index(2)     # 1
index = my_list.index(2, 2)  # 3（从索引2开始查找）

# 统计出现次数
count = my_list.count(2)     # 2

# 检查存在
exists = 3 in my_list        # True
```

### 排序和反转
```python
my_list = [3, 1, 4, 1, 5]

# 排序（原地修改）
my_list.sort()              # [1, 1, 3, 4, 5]
my_list.sort(reverse=True)  # [5, 4, 3, 1, 1]

# 创建排序副本
sorted_list = sorted(my_list)

# 反转
my_list.reverse()           # [1, 1, 3, 4, 5] → [5, 4, 3, 1, 1]
```


### 列表复制
```python
original = [1, 2, 3]

# 浅拷贝
shallow_copy = original.copy()
shallow_copy = original[:]
shallow_copy = list(original)

# 深拷贝（用于嵌套列表）
import copy
deep_copy = copy.deepcopy(original)
```

### 列表运算
```python
list1 = [1, 2]
list2 = [3, 4]

# 拼接
combined = list1 + list2    # [1, 2, 3, 4]

# 重复
repeated = list1 * 3        # [1, 2, 1, 2, 1, 2]

# 比较
result = list1 == list2     # False
```

### 列表推导式
```python
# 创建平方数列表
squares = [x**2 for x in range(5)]  # [0, 1, 4, 9, 16]

# 带条件的推导式
even_squares = [x**2 for x in range(10) if x % 2 == 0]

# 嵌套循环
pairs = [(x, y) for x in range(3) for y in range(3)]
```

### 常用函数
```python
my_list = [1, 2, 3, 4, 5]

# 长度
length = len(my_list)       # 5

# 最值
maximum = max(my_list)      # 5
minimum = min(my_list)      # 1
total = sum(my_list)        # 15

# 枚举
for index, value in enumerate(my_list):
    print(f"索引{index}: 值{value}")

# 映射
doubled = list(map(lambda x: x*2, my_list))  # [2, 4, 6, 8, 10]

# 过滤
evens = list(filter(lambda x: x % 2 == 0, my_list))  # [2, 4]
```

### 解包操作
```python
# 基本解包
a, b, c = [1, 2, 3]

# 扩展解包
first, *middle, last = [1, 2, 3, 4, 5]  # first=1, middle=[2,3,4], last=5
```

### 生成器表达式
```python
# 节省内存（惰性求值）
gen = (x**2 for x in range(1000000))
```

### 时间复杂度
- **访问元素**：O(1)
- **追加元素**：O(1)（平均情况）
- **插入/删除元素**：O(n)
- **查找元素**：O(n)
- **排序**：O(n log n)

### 内存优化
- 列表会预分配额外空间以支持快速追加
- 对于大量数据，考虑使用生成器或NumPy数组

### 列表扁平化
```python
nested = [[1, 2], [3, 4], [5, 6]]
flat = [item for sublist in nested for item in sublist]  # [1, 2, 3, 4, 5, 6]
```

### 去重（保持顺序）
```python
original = [3, 1, 2, 1, 4, 3]
unique = list(dict.fromkeys(original))  # [3, 1, 2, 4]
```

### 分组
```python
data = [1, 2, 3, 4, 5, 6]
grouped = [data[i:i+2] for i in range(0, len(data), 2)]  # [[1, 2], [3, 4], [5, 6]]
```

