from sklearn import datasets
from sklearn.model_selection import train_test_split
from sklearn import svm
from sklearn import metrics


def SVM():
    cancer=datasets.load_breast_cancer()
    print("Features of Breast cancer dataset : ",cancer.feature_names)

    print("Labels of Breast cancer dataset : ", cancer.target_names)

    print("Shape of cancer dataset : ",cancer.data.shape)

    print("First five records are : ",cancer.data[0:5])

    X_train,X_test,Y_train,Y_test=train_test_split(cancer.data,cancer.target,test_size=0.3,random_state=109)

    clf=svm.SVC(kernel='linear')

    clf.fit(X_train,Y_train)

    y_pred=clf.predict(X_test)

    print("Accuracy of the model is : ",metrics.accuracy_score(Y_test,y_pred)*100)



def main():
    print("Support Vector Machine")
    SVM()

if __name__=="__main__":
    main()