import os

def process_wubi_file():
    # 读取wubi.md文件
    with open('wubi.md', 'r', encoding='utf-8') as f:
        lines = f.readlines()
    
    # 分离表头和数据行
    header = lines[:2]  # 前两行是表头
    data_lines = lines[2:]  # 从第三行开始是数据
    
    # 解析数据行
    data = []
    for line in data_lines:
        if line.strip():  # 跳过空行
            parts = line.strip().split(' | ')
            if len(parts) >= 2:  # 确保有足够的数据
                chinese_char = parts[0].strip()
                full_pinyin = parts[1].strip()
                data.append((full_pinyin, line.strip()))
    
    # 按照全拼排序
    data.sort(key=lambda x: x[0])
    
    # 按首字母分组
    grouped_data = {}
    for pinyin, line in data:
        first_char = pinyin[0].lower() if pinyin else 'other'
        if first_char not in grouped_data:
            grouped_data[first_char] = []
        grouped_data[first_char].append(line)
    
    # 为每个字母创建对应的文件
    for letter in 'abcdefghijklmnopqrstuvwxyz':
        filename = f"{letter}.md"
        with open(filename, 'w', encoding='utf-8') as f:
            # 写入表头
            f.writelines(header)
            # 写入该字母对应的数据行
            if letter in grouped_data:
                for line in grouped_data[letter]:
                    f.write(line + '\n')
    
    print("文件分割完成！")

# 执行程序
if __name__ == "__main__":
    process_wubi_file()
