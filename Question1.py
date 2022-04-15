def compareTriplets(a, b):

    aliceScore = 0
    bobScore = 0
    i=0

    for i in range(0, len(a)):

        if(a[i] > b[i]):
            aliceScore += 1
        elif(b[i] > a[i]):
            bobScore += 1
        else : pass


    return [aliceScore, bobScore]

def main():
    a = [0,0,0]
    b = [0,0,0]
    i=0
    j=0 

    print(" -- Enter three values ​​for Alice --")
    for i in range (0, 3):
        a[i] = int(input("--> a{} : ".format(i)))
        if(a[i]>100 or a[i]<0):
            print("\n ERROR : Please enter values between 0 and 100 !!\n")
            return

    print(" -- Enter three values ​​for Bob --")
    for j in range (0, 3):
        b[j] = int(input("--> b{} : ".format(j)))
        if(b[j]>100 or b[j]<0):
            print("\n ERROR : Please enter values between 0 and 100 !!\n")
            return


    outcome = compareTriplets(a,b)

    print("\n ----------------- \n\n")
    print(" - Alice Score : {}\n - Bob Score : {}".format(outcome[0], outcome[1]))
    print(outcome)
    print("\n\n ----------------- \n")




main()
