import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression



def logisticreg():
    diabetes=pd.read_csv('diabetes.csv')

    print("Coloumns of datasets : ")
    print(diabetes.columns)

    print("First five records ",diabetes.head())

    print("Dimension of datasets are : {}".format(diabetes.shape))

    X_train,X_test,Y_train,Y_test=train_test_split(diabetes.loc[:,diabetes.columns!='Outcome'],diabetes['Outcome'],stratify=diabetes['Outcome'],random_state=66)


    logreg = LogisticRegression()

    logreg.fit(X_train, Y_train)

    print("Accuracy on training set : {:.3f}".format(logreg.score(X_train,Y_train)))

    print("Accuracy on testing set : {:.3f}".format(logreg.score(X_test, Y_test)))

    logreg001=LogisticRegression(C=0.01).fit(X_train,Y_train)

    print("Accuracy on training set : {:.3f}".format(logreg001.score(X_train, Y_train)))

    print("Accuracy on testing set : {:.3f}".format(logreg001.score(X_test, Y_test)))


def main():
    print("Diabetes prediction using Logistic Regression")
    logisticreg()

if __name__=="__main__":
    main()