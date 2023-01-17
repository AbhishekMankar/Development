from sklearn import metrics
from sklearn import datasets
from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import train_test_split


def winepredictor():
    wine=datasets.load_wine()
    print(wine.feature_names)
    print(wine.target_names)
    print(wine.target)

    X_train,X_test,Y_train,Y_test=train_test_split(wine.data,wine.target,test_size=0.3)
    knn=KNeighborsClassifier(n_neighbors=3)
    knn.fit(X_train,Y_train)
    y_pred=knn.predict(X_test)

    print("Accuracy Score : ",metrics.accuracy_score(y_pred,Y_test))



def main():
    print("Machine Learning Algorithm")
    print("Wine Predictor")
    winepredictor()

if __name__=="__main__":
    main()