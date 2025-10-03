
## pythondictionary
### 创建字典
```python
# 空字典
dict1 = {}
dict2 = dict()

# 直接赋值
person = {'name': 'Alice', 'age': 25, 'city': 'Beijing'}

# 使用dict()构造函数
person = dict(name='Alice', age=25, city='Beijing')

# 从键值对序列
items = [('name', 'Alice'), ('age', 25)]
person = dict(items)
```

### 基本操作
```python
# 访问值
name = person['name']  # 'Alice'
age = person.get('age')  # 25

# 修改值
person['age'] = 26

# 添加新键值对
person['gender'] = 'female'

# 删除键值对
del person['city']
removed_value = person.pop('age')
```

### 常用方法
```python
person = {'name': 'Alice', 'age': 25, 'city': 'Beijing'}

# 获取所有键
keys = person.keys()  # dict_keys(['name', 'age', 'city'])

# 获取所有值
values = person.values()  # dict_values(['Alice', 25, 'Beijing'])

# 获取所有键值对
items = person.items()  # dict_items([('name', 'Alice'), ('age', 25), ('city', 'Beijing')])

# 检查键是否存在
if 'name' in person:
    print("键存在")

# 获取字典长度
length = len(person)  # 3
```

### 更新和合并
```python
# 更新字典
person.update({'age': 26, 'job': 'Engineer'})

# 合并字典 (Python 3.9+)
dict1 = {'a': 1, 'b': 2}
dict2 = {'b': 3, 'c': 4}
merged = dict1 | dict2  # {'a': 1, 'b': 3, 'c': 4}
```

### 字典推导式
```python
# 基本推导式
squares = {x: x**2 for x in range(1, 6)}  # {1: 1, 2: 4, 3: 9, 4: 16, 5: 25}

# 带条件的推导式
even_squares = {x: x**2 for x in range(1, 6) if x % 2 == 0}  # {2: 4, 4: 16}

# 键值互换
original = {'a': 1, 'b': 2, 'c': 3}
swapped = {v: k for k, v in original.items()}  # {1: 'a', 2: 'b', 3: 'c'}
```

### defaultdict
```python
from collections import defaultdict

# 设置默认值类型
word_count = defaultdict(int)
words = ['apple', 'banana', 'apple', 'orange']
for word in words:
    word_count[word] += 1

# 默认值为列表
grouped_data = defaultdict(list)
data = [('a', 1), ('b', 2), ('a', 3)]
for key, value in data:
    grouped_data[key].append(value)
```

### OrderedDict (保持插入顺序)
```python
from collections import OrderedDict

ordered_dict = OrderedDict()
ordered_dict['z'] = 1
ordered_dict['a'] = 2
ordered_dict['m'] = 3
# 保持插入顺序: z -> a -> m
```

### Counter (计数专用)
```python
from collections import Counter

words = ['apple', 'banana', 'apple', 'orange', 'banana', 'apple']
word_count = Counter(words)
# Counter({'apple': 3, 'banana': 2, 'orange': 1})

# 最常见元素
most_common = word_count.most_common(2)  # [('apple', 3), ('banana', 2)]
```

### 字典遍历技巧
```python
person = {'name': 'Alice', 'age': 25, 'city': 'Beijing'}

# 遍历键
for key in person:
    print(key)

# 遍历值
for value in person.values():
    print(value)

# 遍历键值对
for key, value in person.items():
    print(f"{key}: {value}")

# 同时获取索引和键值对
for idx, (key, value) in enumerate(person.items()):
    print(f"索引{idx}: {key} = {value}")
```

### 字典解包
```python
def print_person_info(name, age, city):
    print(f"{name} is {age} years old, living in {city}")

person = {'name': 'Alice', 'age': 25, 'city': 'Beijing'}
print_person_info(**person)  # 解包字典作为参数
```

### 设置默认值
```python
# 使用setdefault
person = {'name': 'Alice'}
age = person.setdefault('age', 25)  # 如果age不存在，设置为25

# 使用get设置默认值
city = person.get('city', 'Unknown')
```

### 字典排序
```python
scores = {'Alice': 85, 'Bob': 92, 'Charlie': 78}

# 按键排序
sorted_by_key = dict(sorted(scores.items()))

# 按值排序
sorted_by_value = dict(sorted(scores.items(), key=lambda x: x[1]))

# 按值降序排序
sorted_desc = dict(sorted(scores.items(), key=lambda x: x[1], reverse=True))
```

