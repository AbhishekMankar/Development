from sklearn.datasets import load_iris
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import accuracy_score
from sklearn.model_selection import train_test_split
from scipy.spatial import distance


def euc(a,b):
    return distance.euclidean(a,b)

class MarvellousKNeighborsClassifier:
    def fit(self,training_data,training_target):
        self.trainingdata=training_data
        self.trainingtarget=training_target

    def closest(self,row):
        minimumdistance=euc(row,self.trainingdata[0])
        minimumindex=0

        for i in range(1,len(self.trainingdata)):
            Distance=euc(row,self.trainingdata[i])
            if Distance<minimumdistance:
                minimumdistance=Distance
                minimumindex=i
        return self.trainingdata[minimumindex]

    def predict(self,testdata):
        predictions=[]
        for value in testdata:
            result=self.closest(value)
            predictions.append(result)

        return predictions





def MarvellousML():
    Dataset=load_iris()  #load the data
    Data=Dataset.data
    Target=Dataset.target

    #manipulate data
    Data_train , Data_test , Target_train , Target_test = train_test_split(Data,Target,test_size=0.5)

    Classifier=KNeighborsClassifier()

    #build the model
    Classifier.fit(Data_train,Target_train)


    #test the model
    Prediction=Classifier.predict(Data_test)

    Accuracy=accuracy_score(Target_test,Prediction)

    return Accuracy



def main():
    ret=MarvellousML()
    print("Accuracy is : ",ret*100)


if __name__=="__main__":
    main()