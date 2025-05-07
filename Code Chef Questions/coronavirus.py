for cases in range(int(input())):
    number = int(input())
    peoples = list(map(int, input().split()))
    
    infected_people = []
    
    count = 0
    for index,people in enumerate(peoples):
        for left in range(0,index+1):
            if abs(peoples[left]-people) <= 2:
                count += 1
            else:
                continue
        for right in range(index,len(peoples)):
            if abs(peoples[left]-people) <= 2:
                count += 1
                
        infected_people.append(count)
    
    print(min(infected_people),max(infected_people))