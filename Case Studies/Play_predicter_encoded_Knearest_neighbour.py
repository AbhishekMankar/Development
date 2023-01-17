import numpy as np
import pandas as pd
from sklearn import preprocessing
from sklearn.neighbors import KNeighborsClassifier

def MarvellousPredictor(data_path):
    data=pd.read_csv(data_path,index_col=0)

    feature_names=['whether','Temperature']
    print("Name of features : ",feature_names)

    Whether=data.Whether
    Temperature=data.Temperature
    play=data.Play

    le=preprocessing.LabelEncoder()

    weather_encoded=le.fit_transform(Whether)
    print(weather_encoded)

    temp_encoded = le.fit_transform(Temperature)
    print(temp_encoded)

    label=le.fit_transform(play)

    features=list(zip(weather_encoded,temp_encoded))

    model=KNeighborsClassifier(n_neighbors=3)

    model.fit(features,label)

    predicted=model.predict([[0,2]])
    print(predicted)




def main():
    print("Label encoding")
    print("Machine learning algorithm")
    MarvellousPredictor("PlayPredictor.csv")

if __name__=="__main__":
    main()