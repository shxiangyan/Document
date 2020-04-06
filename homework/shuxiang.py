def counnt():
    type_shuxiang=['鼠','牛','虎','兔','龙','蛇','马','羊','猴','鸡','狗','猪']
    year=int(input("请输入年份,输入0退出:"))
    while(year!=0):
      print(type_shuxiang[year%12-4])
      year=int(input("请输入年份,输入0退出:"))
counnt()
