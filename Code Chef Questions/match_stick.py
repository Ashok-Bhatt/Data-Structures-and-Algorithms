matches = {1:2, 2:5, 3:5, 4:4, 5:5, 6:6, 7:3, 8:7, 9:6, 0:6}

for i in range(int(input())):
    num1, num2 = map(int, input().split())
    sum = num1 + num2
    total_matches = 0
    while sum >=1:
        total_matches += matches[sum%10]
        sum //= 10
        
    print(total_matches)