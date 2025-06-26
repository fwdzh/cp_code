# 以下三行代码不要修改
a = int(input('请输入一个整数：'))    
b = int(input('请再输入一个整数：')) 
sign = input('请输入运算符号')
# 补充你的代码
# eval()函数把字符串f"{a}{sign}{b}"转为计算表达式
# 字符串里包含引号时，内部引号与边界应用不同的引号


s = f"{a}{sign}{b}"
print(f"{s}={eval(s)}")