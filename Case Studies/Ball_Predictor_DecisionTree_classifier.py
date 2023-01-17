from sklearn import tree


#rough 1
#smooth 0

#tennis 1
#cricket 2

def BallPredictor(weight,surface):

    Features=[[35,1],[47,1],[90,0],[48,1],[90,0],[35,1],[92,0],[35,1],[35,1],[35,1],[96,0],[43,1],[110,0],[35,1],[95,0]]
    Labels=[1,1,2,1,2,1,2,1,1,1,2,1,2,1,2]

    obj=tree.DecisionTreeClassifier()

    obj=obj.fit(Features,Labels)

    ret=obj.predict([[weight,surface]])

    if ret==1:
        print("Tennis Ball")
    else:
        print("Cricket Ball")

def main():
    print("------Ball predictor case study------")
    print("Enter the weight of your object in grams")
    weight=int(input())
    print("Enter the type of surface of your object (Rough/Smooth)")
    surface=input()

    if surface.lower()=="rough":
        surface=1
    elif surface.lower()=="smooth":
        surface=1
    else:
        print("Invalid Input")
        exit()
    BallPredictor(weight,surface)

if __name__=="__main__":
    main()