# import re
# with open("transformer_cpp/vocabulary.txt",'r') as file:
#     content=file.read()
# new_content=re.sub(r'[A-Z]','',content)


# with open("transformer_cpp/vocabulary.txt", 'r', encoding='utf-8') as file:
#     lines = file.readlines()
    
#     # 处理每一行，删除第一个空格后的所有内容
#     processed_lines = []
#     for line in lines:
#         # 找到第一个空格的位置
#         space_index = line.find(' ')
#         if space_index != -1:
#             # 如果找到空格，截取空格之前的部分
#             processed_line = line[:space_index]
#         else:
#             # 如果没有空格，保留整行
#             processed_line = line.strip()
#         processed_lines.append(processed_line + '\n')
#         new_content=''.join(processed_lines)
        

# with open("transformer_cpp/vocabulary.txt",'w') as file:
#     file.write(new_content)

