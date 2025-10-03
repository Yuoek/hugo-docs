
# Pythondatatypebasic

### 整型 (int)
```python
a = 10        # 十进制
b = 0b1010    # 二进制 (前缀0b)
c = 0o12      # 八进制 (前缀0o)
d = 0xA       # 十六进制 (前缀0x)
```

### 浮点型 (float)
```python
a = 3.14
b = 2.0
c = 3e5       # 科学计数法: 3×10⁵
```

### 复数 (complex)
```python
a = 3 + 4j
b = complex(3, 4)  # 等价于 3+4j
```

### 二、python 布尔类型 (Boolean Type)
- **取值**: `True` 和 `False`
- **本质**: `bool` 是 `int` 的子类，`True=1`, `False=0`
- **布尔运算**: `and`, `or`, `not`

## 三、序列类型 (Sequence Types)

### 1. 字符串 (str)
- **特点**: 不可变序列，支持索引和切片
- **表示方法**:
  ```python
  s1 = 'hello'
  s2 = "world"
  s3 = '''多行
  字符串'''
  s4 = r"原始字符串\n不转义"  # 原始字符串
  ```

### 2. 列表 (list)
- **特点**: 可变序列，元素可修改
- **表示方法**:
  ```python
  lst = [1, 2, 'a', True]
  lst[0] = 10  # 可修改
  ```

### 3. 元组 (tuple)
- **特点**: 不可变序列，元素不可修改
- **表示方法**:
  ```python
  tup = (1, 2, 'a')
  tup = 1, 2, 'a'  # 括号可省略
  ```

## 四、映射类型 (Mapping Type)

### 字典 (dict)
- **特点**: 键值对集合，键必须可哈希
- **表示方法**:
  ```python
  d = {'name': 'Alice', 'age': 20}
  d = dict(name='Alice', age=20)
  ```

## 五、集合类型 (Set Types)

### 1. 集合 (set)
- **特点**: 无序、不重复元素集合
- **表示方法**:
  ```python
  s = {1, 2, 3}
  s = set([1, 2, 2, 3])  # {1, 2, 3}
  ```

### 2. 冻结集合 (frozenset)
- **特点**: 不可变版本的集合
- **表示方法**:
  ```python
  fs = frozenset([1, 2, 3])
  ```

## 六、特殊类型

### 1. None 类型
- **特点**: 表示空值或无值
- **唯一值**: `None`

### 2. 字节类型 (bytes)
- **特点**: 不可变的字节序列
- **表示方法**:
  ```python
  b = b'hello'
  b = bytes([104, 101, 108, 108, 111])
  ```

### 3. 字节数组 (bytearray)
- **特点**: 可变的字节序列
- **表示方法**:
  ```python
  ba = bytearray(b'hello')
  ```

## 七、类型检查与转换

### 类型检查
```python
type(obj)        # 返回类型对象
isinstance(obj, type)  # 检查类型
```

### 类型转换
```python
int(x)      # 转换为整数
float(x)    # 转换为浮点数
str(x)      # 转换为字符串
list(x)     # 转换为列表
tuple(x)    # 转换为元组
dict(x)     # 转换为字典
set(x)      # 转换为集合
bool(x)     # 转换为布尔值
```

## 八、重要特性总结

| 类型 | 可变性 | 有序性 | 元素要求 | 示例 |
|------|--------|--------|----------|------|
| int | 不可变 | - | - | 123 |
| float | 不可变 | - | - | 3.14 |
| str | 不可变 | 有序 | 字符 | "hello" |
| list | 可变 | 有序 | 任意 | [1, 'a'] |
| tuple | 不可变 | 有序 | 任意 | (1, 'a') |
| dict | 可变 | 无序 | 键可哈希 | {'a': 1} |
| set | 可变 | 无序 | 可哈希 | {1, 2} |
| frozenset | 不可变 | 无序 | 可哈希 | frozenset([1,2]) |

这个归纳涵盖了Python的主要基本数据类型及其核心特性，是学习Python编程的基础。


