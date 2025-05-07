test = int(input())

for i in range(test):
    length = int(input())
    word = input()
    if length < 4:
        print("Yes")
    else:
        for index,letters in enumerate(word[:-3]):
            if letters not in "aeiou":
                for i in range(1,4):
                    if word[index+i] in "aeiou":
                        break
                    else:
                        continue
                else:
                    print("No")
                    break
            else:
                continue
        else:
            print("Yes")