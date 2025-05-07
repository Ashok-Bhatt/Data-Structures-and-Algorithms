for i in range(int(input())):
    balloon = input()
    if balloon.count("a") >= balloon.count("b"):
        print(balloon.count("b"))
    else:
        print(balloon.count("a"))