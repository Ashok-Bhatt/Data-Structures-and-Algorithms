# test_case is the variable that will hold no of text cases
test_case = int(input())

for i in range(test_case):
    x, y = map(int, input().split())
    if x+y > 6:
        print("YES")
    else:
        print("NO")