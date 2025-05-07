for cases in range(int(input('Enter no. of test cases:'))):
    order=int(input("Enter the order of square matrix:"))

    matrix = []
    matrix1 = []
    element =1

    for i in range(order):
        matrix1.append(0)
    
    for i in range(order):
        matrix.append(matrix1)

    for i in range(2*order-1):
        for j in range(i):
            for k in range(i):
                if j+k==i:
                    matrix[j][k]==order
                    order = order + 1
                else:
                    continue
    
    for i in matrix:
        for j in i:
            print(j,end=" ")
        print("\n")