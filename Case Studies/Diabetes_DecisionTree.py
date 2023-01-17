import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier
import matplotlib.pyplot as plt


def decision_tree():
    diabetes=pd.read_csv('diabetes.csv')

    print("Coloumns of datasets : ")
    print(diabetes.columns)

    print("First five records ",diabetes.head())

    print("Dimension of datasets are : {}".format(diabetes.shape))



    X_train,X_test,Y_train,Y_test=train_test_split(diabetes.loc[:,diabetes.columns!='Outcome'],diabetes['Outcome'],stratify=diabetes['Outcome'],random_state=66)

    tree=DecisionTreeClassifier(random_state=0)
    tree.fit(X_train,Y_train)

    print("Accuracy on training set : {:.3f}".format(tree.score(X_train,Y_train)))

    print("Accuracy on testing set : {:.3f}".format(tree.score(X_test, Y_test)))

    tree=DecisionTreeClassifier(max_depth=3,random_state=0)

    tree.fit(X_train,Y_train)

    print("Accuracy on training set : {:.3f}".format(tree.score(X_train, Y_train)))

    print("Accuracy on testing set : {:.3f}".format(tree.score(X_test, Y_test)))

    print("Feature Importances :\n {}".format(tree.feature_importances_))

    def plot_feature_importances_diabetes(model):
        plt.figure(figsize=(8,6))
        n_features=8
        plt.barh(range(n_features),model.feature_importances_,align='center')
        diabetes_features=[x for i,x in enumerate(diabetes.columns) if i!=8]
        plt.yticks(np.arange(n_features),diabetes_features)
        plt.xlabel="Feature Importanace"
        plt.ylabel="Features"
        plt.ylim(-1,n_features)
        plt.show()

    plot_feature_importances_diabetes(tree)




def main():
    print("Diabetes prediction using Decision Tree")
    decision_tree()

if __name__=="__main__":
    main()