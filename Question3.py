def ballEnergy(arr):
    height=0
    ballEnergy = int(input("--> Enter value BallEnergy : "))
    minBallEnergy = ballEnergy

    for i in range(len(arr)):
        height = arr[i]
        delta = ballEnergy - height
        print("TopEnergy : {}  --  Height : {}  --  Delta : {}".format(ballEnergy, height, delta))
        if(ballEnergy < arr[i]):
            ballEnergy = ballEnergy - (height - ballEnergy)
            if(ballEnergy < minBallEnergy):
                minBallEnergy = ballEnergy
        else:
            ballEnergy = ballEnergy + (ballEnergy - height )
            if(ballEnergy < minBallEnergy):
                minBallEnergy = ballEnergy

        

    return minBallEnergy
    

def main():
    
    print(" -- Please enter array size --" )
    n = int(input("--> n : "))
    arr = []
    for i in range(n):
        deger = int(input("--> arr[{}] : ".format(i)))
        if(deger>=1 and deger<10**n):
            arr += [deger]
        else:
            print("Please enter a value between 1 and 10**len(array)!!")
            return

    print("\n -- ARRAY : ", arr)
    minBallEnergy = ballEnergy(arr)
    print("\n --------------------------- \n")
    print("MinBallEnergy : ", minBallEnergy)
    print("\n --------------------------- \n")

main()
