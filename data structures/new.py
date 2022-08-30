def compareList(l1,l2):
   if(len(l1)==len(l2) and len(l1)==sum([1 for i,j in zip(l1,l2) if i==j])):
      return True
   else:
      return False
def swapPositions(list, pos1, pos2):
    list[pos1], list[pos2] = list[pos2], list[pos1]
    return list
    
num1 = int(input("Enter the number of frogs :"))
num2 = int(input("Enter the number of toads:"))

list1=[]

for i in range(num1):
    list1.append('frog')
list1.append(' ')
for i in range(num2):
    list1.append('toad')
     
print(list1)
list2 = list1[::-1]


while(True):
    if(list1[len(list1)-1]==' ' and list1[len(list1)-2]=='toad' and list1[len(list1)-3]=='toad'):
        print('sorry, you have lost')
        break
    if(list1[0]==' ' and list1[1]=='frog' and list1[2]=='frog'):
        print('sorry, you have lost')
        break
    check = compareList(list1,list2)        
    if(check==True):
        print("Congratuations! you've won. ")
        break
    n = input("Enter move : ")
    if(n=='quit'):
        break
    else:
        n=int(n)
        
    if(list1[n-1]=='frog'):
        if(list1[n]==' '):
            list1=swapPositions(list1,n-1,n)
            print(list1)
            continue
        if(list1[n]=='frog'):
            if(list1[n+1]==' '):
                list1=swapPositions(list1,n-1,n+1)
                print(list1)
                continue
            if(list1[n+1]=='toad'):
                print(list1)
                print('sorry, you have lost')
                break
        if(list1[n]=='toad'):
            if(list1[n+1]==' '):
                list1=swapPositions(list1,n-1,n+1)
                print(list1)
                continue
            if(list1[n+1]=='toad'):
                print(list1)
                print('sorry, you have lost')
                break    
    elif(list1[n-1]=='toad'):
        if(list1[n-2]==' '):
            list1=swapPositions(list1,n-1,n-2)
            print(list1)
            continue
        if(list1[n-2]=='toad'):
            if(list1[n-3]==' '):
                list1=swapPositions(list1,n-2,n-3)
                print(list1)
                continue
            if(list1[n-3]=='frog'):
                print(list1)
                print('sorry, you have lost')
                break
        if(list1[n-2]=='frog'):
            if(list1[n-3]==' '):
                list1=swapPositions(list1,n-1,n-3)
                print(list1)
                continue
            if(list1[n-3]=='frog'):
                print(list1)
                print('sorry, you have lost')
                break 