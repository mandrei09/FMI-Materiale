# Biblioteci necesare.
import os
import numpy as np
from PIL import Image

# Functie definita pentru citirea datelor de antranare.
# Aceasta primeste ca parametru path-ul catre date.
def readTrainImages(path):
    train_images = []
    # Iteram prin primele 15000 de poze pentru a adauga la train_images
    for filename in sorted(os.listdir(path))[:15000]:
        
        # Incarcam imaginea curenta
        image = Image.open(path + "/" + filename)
    
        # Convertim imaginea curenta intr-o imagine grayscale, apoi convertim la un array 1D
        image_array = np.array(image.convert("L")).flatten()
        
        # Adaugam imaginea curenta la vectorul de imagini, daca imaginea nu este facuta doar din pixeli negrii
        train_images.append(image_array)
        
    # Convertim array-ul imaginilor intr-o np.array si il returnam
    return np.array(train_images)

# Functie definita pentru citirea datelor de validare
# Aceeasi functionalitate ca cea de sus.
def readValidationImages(path):
    valiadation_images = []

    for filename in sorted(os.listdir(path))[15000:17000]:
        
        image = Image.open(path + "/" + filename)
        
        image_array = np.array(image.convert("L")).flatten()
        
        valiadation_images.append(image_array)
        
    return np.array(valiadation_images)

# Functie definita pentru citirea datelor de testare - aceeasi functionalitate ca prima
def readTestImages(path):
    test_images = []
    
    for filename in sorted(os.listdir(path))[17000:]:
    
        image = Image.open(path + "/" + filename)
        
        image_array = np.array(image.convert("L")).flatten()
        
        test_images.append(image_array)
        
    return np.array(test_images)

def readLabels(path):
    
    f = open(path)
    
    # Citim prima linie din fisier, care nu contine un label
    f.readline()
    
    labels=[]
    
    # Dintr-o linie memoram doar labelul
    for linie in f.readlines():
        labels.append(int(linie.split(',')[1]))
    f.close()
    
    return labels

pathImages = "/kaggle/input/unibuc-brain-ad/data/data"
pathLabels = "/kaggle/input/unibuc-brain-ad/data"

train_images=readTrainImages(pathImages)
validation_images=readValidationImages(pathImages)
test_images=readTestImages(pathImages)

train_labels=np.array(readLabels(pathLabels + "/train_labels.txt"))
validation_labels=np.array(readLabels(pathLabels + "/validation_labels.txt"))

# Genereaza un numar de numarIntervale in care valorile curpinse 
# intre 0 si Max sunt distribuite uniform. 
def generareIntervale(numarIntervale,Max):
    intervale = np.linspace(start=0, stop=Max, num=numarIntervale)
    return intervale

# Transforma matricea x intr-o matrice de aceeasi dimensiune, in care 
# pixelii sunt inlocuiti cu label-urile intervalului de care apartine.
def valori_intervale(matrice,intervale):
    newMatix = np.zeros(matrice.shape)
    for i, elem in enumerate(matrice):
        newMatix[i] = np.digitize(elem, intervale)
    return newMatix - 1

# Transformam valorile cu ajutorul functiilor definite mai sus
intervale=generareIntervale(4,224)
train=valori_intervale(train_images,intervale)
validation=valori_intervale(validation_images,intervale)
test=valori_intervale(test_images,intervale)

from sklearn.naive_bayes import MultinomialNB
from sklearn.metrics import f1_score

# Definirea modelului, antrenarea acestuia si prezicerea label-urilor corespunzatoare.

bayes = MultinomialNB()
bayes.fit(train, train_labels)

scor = bayes.score(validation, validation_labels)
print("Acuratetea pe datele de validare este: ",scor)

test_labels = bayes.predict(validation)
f1 = f1_score(test_labels, validation_labels)
print("F1 score: ",f1)

test_labels = bayes.predict(test)

stringLabels = []

for i in range(17001, 22150):
    label='0' + str(i) + ',' + str(test_labels[i - 17001])
    stringLabels.append(label)
    
np.savetxt('rezultat.csv', stringLabels, fmt='%s', header="id,class", comments='')

from sklearn.metrics import confusion_matrix
cm = confusion_matrix(validation_labels, test_labels)
print(cm)