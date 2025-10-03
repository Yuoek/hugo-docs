## pythontuple 
### 创建元组
```python
# 方法1：使用圆括号
tuple1 = (1, 2, 3, 4, 5)
tuple2 = ('a', 'b', 'c')

# 方法2：使用tuple()构造函数
tuple3 = tuple([1, 2, 3])  # (1, 2, 3)
tuple4 = tuple('hello')    # ('h', 'e', 'l', 'l', 'o')

# 单元素元组（注意逗号）
single_tuple = (1,)        # 正确
not_tuple = (1)            # 错误，这是整数1
```

### 访问元素
```python
my_tuple = (10, 20, 30, 40, 50)
print(my_tuple[0])     # 10
print(my_tuple[-1])    # 50
print(my_tuple[1:3])   # (20, 30)
```

### 元组拆包
```python
# 基本拆包
a, b, c = (1, 2, 3)
print(a, b, c)  # 1 2 3

# 使用*收集剩余元素
first, *middle, last = (1, 2, 3, 4, 5)
print(first)    # 1
print(middle)   # [2, 3, 4]
print(last)     # 5
```

### 计数 count()
```python
my_tuple = (1, 2, 2, 3, 2, 4)
print(my_tuple.count(2))  # 3
```

### 查找索引 index()
```python
my_tuple = ('a', 'b', 'c', 'b')
print(my_tuple.index('b'))    # 1
print(my_tuple.index('b', 2)) # 3（从索引2开始查找）
```

### 数据完整性
```python
# 坐标点（不希望被修改）
point = (100, 200)
# point[0] = 150  # 报错：元组不可修改
```

### 字典键
```python
# 元组可作为字典键（列表不行）
coordinates_dict = {(1, 2): 'A点', (3, 4): 'B点'}
```

### 函数多返回值
```python
def get_user_info():
    return '张三', 25, '北京'

name, age, city = get_user_info()
```

### 交换变量值
```python
a, b = 10, 20
a, b = b, a  # 交换a和b的值
print(a, b)  # 20 10
```

### 命名元组
```python
from collections import namedtuple

# 创建命名元组类型
Point = namedtuple('Point', ['x', 'y'])
p = Point(10, 20)
print(p.x, p.y)  # 10 20
```


### 可变对象可修改
```python
my_tuple = (1, 2, [3, 4])
my_tuple[2].append(5)  # 允许：修改的是列表内容
print(my_tuple)        # (1, 2, [3, 4, 5])
```

