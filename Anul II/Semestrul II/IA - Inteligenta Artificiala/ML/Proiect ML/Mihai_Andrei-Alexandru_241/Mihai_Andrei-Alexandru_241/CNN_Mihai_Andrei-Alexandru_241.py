import os, sys, random
import numpy as np
from PIL import Image
import matplotlib.pyplot as plt
import matplotlib.image as img 
import torchvision.transforms as transforms
import tensorflow as tf
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Conv2D, MaxPooling2D, Dense, Flatten, Lambda
from tensorflow.keras.metrics import Precision, Recall, BinaryAccuracy
from sklearn.metrics import f1_score,confusion_matrix

#Specificam sistemului sa nu foloseasca tot VRAM-ul pentru a evita anumite erori de sistem.
#Alocarea memoriei creste dinamic in functie de cerinte.
gpus = tf.config.experimental.list_physical_devices('GPU')
for gpu in gpus: 
    tf.config.experimental.set_memory_growth(gpu, True)
    
# Functie definita pentru citirea datelor de antranare
def readTrainImages(path):
    train_images = []
    # Iteram prin primele 15000 de poze pentru a adauga la train_images
    for filename in sorted(os.listdir(path))[:15000]:
        # print((i,filename))
        
        # Incarcam imaginea curenta
        image = Image.open(path + "/" + filename)
        
        # Adaugam imaginea curenta la vectorul de imagini.
        train_images.append(np.array(image))
        
    # Convertim array-ul imaginilor intr-o np.array si il returnam
    return np.array(train_images)

# Functie definita pentru citirea datelor de validare - aceeasi functionalitate ca prima
def readValidationImages(path):
    valiadation_images = []

    for filename in sorted(os.listdir(path))[15000:17000]:
        # print((i,filename))
        image = Image.open(path + "/" + filename)
        valiadation_images.append(np.array(image))
        
    return np.array(valiadation_images)

# Functie definita pentru citirea datelor de testare - aceeasi functionalitate ca prima
def readTestImages(path):
    test_images = []
    
    for filename in sorted(os.listdir(path))[17000:]:
        # print((i,filename))
        image = Image.open(path + "/" + filename)
        test_images.append(np.array(image))
        
    return np.array(test_images)

# Functie care citeste din fisier label-urile pozelor. 
def readLabels(path,trainData=False):
    
    f = open(path)
    
    # Citim prima linie din fisier, care nu contine un label
    f.readline()
    
    labels=[]
    
    # Dintr-o linie memoram doar labelul
    for linie in f.readlines():
        labels.append(int(linie.split(',')[1]))
    f.close()
    
    return labels

# Ne definim cai pentru a citi datele de intrare.
pathImages = "/kaggle/input/unibuc-brain-ad/data/data"
pathLabels = "/kaggle/input/unibuc-brain-ad/data"

# pathImages = "D:/Chestii/Facultate/Anul II/Semestrul II/IA - Inteligenta Artificiala/Proiect ML/data/data"
# pathLabels = "D:/Chestii/Facultate/Anul II/Semestrul II/IA - Inteligenta Artificiala/Proiect ML/data"

#Citire date
train_images=readTrainImages(pathImages)
validation_images=readValidationImages(pathImages)
test_images=readTestImages(pathImages)
train_labels=np.array(readLabels(pathLabels + "/train_labels.txt"))
validation_labels=np.array(readLabels(pathLabels + "/validation_labels.txt"))

#Definirea modelului
CNN = Sequential([
    Lambda(lambda x: x / 255.0, input_shape=(224, 224, 3)), #normalizam datele printr-un layer lambda
    Conv2D(16, (3,3), 1, activation='relu', input_shape=(224,224,3)),
    MaxPooling2D(),
    Conv2D(32, (3,3), 1, activation='relu'),
    MaxPooling2D(),
    Conv2D(16, (3,3), 1, activation='relu'),
    MaxPooling2D(),
    Flatten(),
    Dense(256, activation='relu'),
    Dense(1, activation='sigmoid') #avem un singur rezultat, anume probabilitatea ca imaginea curenta sa apartina clasei 
                                   #1 sau 0. Folosim functia de activare sigmoid tocmai pentru ca trebuie sa ne decidem 
                                   #intre 2 clase. Daca trebuia sa decidem intre mai multe clase am fi folosit softmax.
                                   #Functia sigmoid transforma input-ul in o valoare [0,1], adica o probabilitate.
])

# Compilam  programul
CNN.compile('adam', loss=tf.losses.BinaryCrossentropy(), metrics=['accuracy'])
CNN.summary()

# Pentru debug - putem vizualiza procesul de antranre al modelului pas cu
steps='logs'
tensorboard_callback = tf.keras.callbacks.TensorBoard(log_dir=steps)

# Antrenarea modelului
hist = CNN.fit(train_images,train_labels,validation_data=(validation_images,validation_labels),epochs=20,callbacks=[tensorboard_callback])

# Dam predict pe datele de validare pentru a calcula f1 score
test_labels = CNN.predict(validation_images)

test=[]

for lab in test_labels:
    if lab > 0.5:
        label=1
    else:
        label=0
    test.append(label)

f1 = f1_score(test, validation_labels)
print("F1 score: ",f1)

# Predict pe datele de test.
test_labels = CNN.predict(test_images)

# Generam matricea de confuzie
cm = confusion_matrix(validation_labels, test)
print(cm)

# Generam CSV-ul care contine label-urile la care s-a dat predict.
stringLabels = []

# Formam lista de stringuri care se va scrie in CSV.
i=17001
for lab in test_labels:
    if lab > 0.5:
        label='0' + str(i) + ',' + str(1)
    else:
        label='0' + str(i) + ',' + str(0)
    stringLabels.append(label)
    i+=1
    
# Generam fisierul csv care contine label-urile prezise.
np.savetxt('rezultat.csv', stringLabels, fmt='%s', header="id,class", comments='')