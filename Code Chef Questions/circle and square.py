for cases in range(int(input())):
    n = int(input())
    
    squares = 0
    
    while n>0:
        i = 1
        while i*i<=n:
            i = i+1
        n = n-(i*i)
        squares = squares+1
        
    print(squares)