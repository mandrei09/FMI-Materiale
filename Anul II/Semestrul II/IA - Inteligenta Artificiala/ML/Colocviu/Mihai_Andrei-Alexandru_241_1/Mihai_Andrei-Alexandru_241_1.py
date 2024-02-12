# Mihai Andrei-Alexandru, grupa 241, subiectul 1

import numpy as np

# Citirea datelor

def readData(pathTrainImages,pathTrainLabels,pathTestImages):
    trainImages=np.load(pathTrainImages)
    trainLabels=np.load(pathTrainLabels)
    testImages=np.load(pathTestImages)
    return trainImages,trainLabels,testImages

trainImages,trainLabels,testImages=readData("trainImages.npy","trainLabels.npy","testImages.npy")

    