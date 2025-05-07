for cases in range(int(input())):
    position1, position2 = map(int, input().split())
    
    if position2 > position1:
        print("No")
    else:
        # Short-cut logic: For any case in which position1 is greater than position 2, the two friends will always meet each other
        while position2 <= position1:
            if position2 == position1:
                print("Yes")
                break
            else:
                position1 = position1 + 1
                position2 = position2 + 2
        else:
            print("No")