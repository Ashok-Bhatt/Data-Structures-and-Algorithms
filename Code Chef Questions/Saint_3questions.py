for i in range(int(input())):
    a,b,c = map(lambda x:int(x), input().split())
    d,e,f = map(lambda x:int(x), input().split())
    if a+b+c == d+e+f:
        print("Pass")
    else:
        print("Fail")