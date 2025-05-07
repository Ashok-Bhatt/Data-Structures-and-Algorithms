test = int(input())

for i in range(test):
    features = list(map(int, input().split()))
    
    req_features = features[0:2]
    features1 = features[2:4]
    features2 = features[4:6]
    
    if (req_features[0] in features1 and req_features[1] in features1):
        print(1)
    elif (req_features[0] in features2 and req_features[1] in features2):
        print(2)
    else:
        print(0)