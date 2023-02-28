#reprezentam solutia x0,...,x6 si fiecare xk ia valori 1...n
#cond de continuare - xk sa fie diferit de x0,..,xk-1

def back(k):
    if k==7:
        paritate=x[1]%2
        for i in range(1,7):
            if x[i]%2!=paritate:
                print(*x[1:])
                break
    else:
        for i in range(x[k-1]+1,n+1):
            x[k]=i
            if x[k-1]+1!=x[k] and x[k]!=13:
                back(k+1)

n=int(input())
x=[0 for i in range (0,7)]
x[0]=-1
back(1)