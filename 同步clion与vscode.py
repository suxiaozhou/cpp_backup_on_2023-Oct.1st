import sys
import os as o
printname=[]
filenames=o.listdir(r'/home/sxz/small_code')
for i in filenames:
    if i[-1]=='p'and i[-2]=='p'and i[-3]=='c'and i[-4]=='.':
        printname.append(i)
file_path = 'small_code/CMakeLists.txt'
text='cmake_minimum_required(VERSION 3.23)\nproject(code)\nset(CMAKE_CXX_STANDARD 14)\nadd_executable(code'
for i in printname:
    text=text+' '+i
text+=')'
with open(file_path, mode='w', encoding='utf-8') as file_do:
    file_do.write(text)

