f_name=input("请输入文件名绝对路径")

f_old=open(f_name,'r')
s=f_old.readlines()
f_old.close()

str=''

for each_line in s:
    if (each_line[:2]!='\n' and each_line[0]!='*'and each_line[-2]!='\\' ):
        each_line=each_line[:-1]+r'\\'+each_line[-1:]
    str+=each_line
print(str)

with open(f_name,'w') as file_new:
    file_new.write(str)
    


        



