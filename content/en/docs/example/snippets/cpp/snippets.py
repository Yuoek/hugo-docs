import os
import re
import json
from glob import glob

def md_to_json(md_file_path):
    """将 Markdown 文件转换为 JSON 格式"""
    
    with open(md_file_path, 'r', encoding='utf-8') as f:
        content = f.read()
    
    # 获取二级标题作为前缀
    h2_match = re.search(r'^##\s+(.+)$', content, re.MULTILINE)
    if not h2_match:
        return None
    
    prefix = h2_match.group(1).strip()
    
    # 匹配三级标题和代码块
    pattern = r'^###\s+(.+?)$(.*?)^```(?:\w+)?$(.*?)^```$'
    matches = re.findall(pattern, content, re.MULTILINE | re.DOTALL)
    
    result = {}
    counter = 1
    
    for match in matches:
        title = match[0].strip()
        code_content = match[2].strip()
        
        # 处理代码内容，每行用引号包围
        code_lines = []
        for line in code_content.split('\n'):
            # 转义双引号
            escaped_line = line.replace('"', '\"')
            code_lines.append(f'{escaped_line}')
        
        # 构建 JSON 结构
        result[title] = {
            "prefix": f"{prefix}{counter}",
            "body": code_lines,
            "description": [""]
        }
        counter += 1
    
    return result

def convert_all_md_to_json():
    """转换当前目录下所有 .md 文件为 .json 文件"""
    
    md_files = glob('./*.md')
    
    for md_file in md_files:
        json_data = md_to_json(md_file)
        
        if json_data:
            # 生成对应的 JSON 文件名
            json_file = md_file.replace('.md', '.json')
            
            # 写入 JSON 文件
            with open(json_file, 'w', encoding='utf-8') as f:
                json.dump(json_data, f, ensure_ascii=False, indent=4)
            
            print(f"已转换: {md_file} -> {json_file}")
        else:
            print(f"跳过文件（未找到有效内容）: {md_file}")

if __name__ == "__main__":
    convert_all_md_to_json()
