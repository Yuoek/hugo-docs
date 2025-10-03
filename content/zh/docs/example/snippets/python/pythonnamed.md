## pythonnamed
### 合法命名
```python
# 允许的命名
name = "张三"
age = 25
_user_id = 123
count2 = 10
my_variable = "值"
```

### 非法命名
```python
# 不允许的命名
2count = 10      # 不能以数字开头
my-variable = 1  # 不能包含连字符
class = "test"   # 不能使用关键字
```

### 命名规范（PEP 8）
- 使用小写字母，单词间用下划线连接：`student_name`
- 避免使用单字符（除了计数器i, j, k）
- 使用有意义的名称


### 基本赋值
```python
# 单个变量赋值
x = 10
name = "Python"

# 同时给多个变量赋值
a = b = c = 100
x, y, z = 1, 2, 3
```

### 动态类型特性
```python
# 变量类型可以改变
var = 10        # 现在是整数
var = "hello"   # 现在是字符串
var = [1,2,3]   # 现在是列表
```


### 基本数据类型
```python
# 整数
age = 25

# 浮点数
price = 19.99

# 字符串
name = "Alice"

# 布尔值
is_valid = True

# 空值
result = None
```

### 容器类型
```python
# 列表
numbers = [1, 2, 3, 4]

# 元组
coordinates = (10, 20)

# 字典
person = {"name": "Bob", "age": 30}

# 集合
unique_numbers = {1, 2, 3}
```


### 局部变量
```python
def my_function():
    local_var = "我在函数内部"  # 局部变量
    print(local_var)

my_function()
# print(local_var)  # 错误：局部变量在外部不可访问
```

### 全局变量
```python
global_var = "我是全局变量"    # 全局变量

def test_function():
    print(global_var)         # 可以访问全局变量

test_function()
```

### 修改全局变量
```python
count = 0

def increment():
    global count              # 声明使用全局变量
    count += 1

increment()
print(count)  # 输出: 1
```

### 链式赋值
```python
a = b = c = 0  # 三个变量都赋值为0
```

### 序列解包
```python
# 元组解包
x, y = (10, 20)

# 列表解包
name, age = ["Tom", 25]

# 交换变量值
a, b = 1, 2
a, b = b, a  # 交换a和b的值
```

### 带星号的解包
```python
# 收集多余的值
first, *middle, last = [1, 2, 3, 4, 5]
# first=1, middle=[2,3,4], last=5
```


### 引用计数
```python
import sys

a = [1, 2, 3]
print(sys.getrefcount(a))  # 查看引用计数
```

### 标识符检查
```python
a = [1, 2, 3]
b = a
c = [1, 2, 3]

print(a is b)  # True，指向同一个对象
print(a is c)  # False，内容相同但不是同一个对象
```


### 变量命名
```python
# 好的命名
student_count = 50
user_name = "john_doe"
is_logged_in = True

# 避免的命名
sc = 50        # 不明确
un = "john"    # 缩写不清晰
flag = True    # 含义不明确
```

### 常量命名
```python
# 常量通常使用全大写
MAX_CONNECTIONS = 100
PI = 3.14159
DATABASE_URL = "postgresql://localhost:5432/mydb"
```


### 未定义变量
```python
# print(undefined_var)  # NameError: name 'undefined_var' is not defined
```

### 拼写错误
```python
count = 10
# print(coutn)  # 拼写错误导致NameError
```

### 作用域混淆
```python
def bad_function():
    # 这里试图修改全局变量但没有声明global
    # count += 1  # UnboundLocalError
    pass
```
