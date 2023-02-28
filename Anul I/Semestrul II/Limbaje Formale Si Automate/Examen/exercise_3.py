# grupa 141, Mihai Andrei-Alexandru ,Furdui Vlad-Rares, Horceag Cristian-Andrei

import sys

def parse(name, continut):
    ok = 0
    rez = []
    for line in continut:  # identificam sectiunea
        if name + ":" == line:  # verificam numele sectiunii
            ok = 1
            continue
        if line == "End":  # final de sectiune
            ok = 0
        if ok == 1:  # adaugam elementele dintr-o sectiune
            rez.append(line)
    return rez

def Turing_Machine_config(file_name):
    
    f = open(file_name)
    # facem strip la tot documentul si-l salvam in continut 
    
    continut = []
    for line in f:

        line = line.strip()
        continut.append(line)

    # salvam multimea state-urilor
    stari = parse("states", continut)
    
    # salvam alfabetul sigma
    sigma = parse("sigma", continut)
    
    # salvam alfabetul benzilor
    gamma = parse("gamma", continut)
    
    # salvam tranzitiile
    transitions = parse("transitions", continut)

    # salvam starile speciale 
    stari_speciale = parse("special_states", continut)

    error = 0
    text = "valid config file"
    
    # verificare incluziune alfabet
    for caracter in sigma:

        if caracter not in gamma:
            # verificam daca sigma este in gamma
            error = 1
            text = "Alfabet gresit !"
            return error, text, stari, sigma, gamma, transitions, stari_speciale

    # verificare tranzitii
    for transition in transitions:

        error = 0
        transition = transition.split(" ")
        if len(transition) == 5:

            if transition[0] not in stari or transition[1] not in stari: 
                
                # verificam existenta starilor din tranzitie
                error = 1
                text = "Tranzitie gresita, starea introdusa este invalida !"
                return error, text, stari, sigma, gamma, transitions, stari_speciale
            
            head_input = transition[2]
            
            if head_input not in gamma:  
                
                # verificam daca simbolul e corect
                error = 1
                text = "Tranzitie gresita, simbolul introdus este invalid !"
                return error, text, stari, sigma, gamma, transitions, stari_speciale

            head_output = transition[3].split("/")

            for output in head_output:
                if output not in gamma:  
                    # verificam daca simbolul e corect
                    error = 1
                    text = "Tranzitie gresita, simbolul introdus este invalid !"
                    return error, text, stari, sigma, gamma, transitions, stari_speciale
            
            head_direction = transition[4]
            
            if (head_direction != 'R' and head_direction != 'L' and head_direction != 'S'):  
                
                # verificam ca directiile sa fie R - dreapta, L - stanga sau S - capatul sta pe loc
                error = 1
                text = "Tranzitie gresita, Directia este invalida !"
                return error, text, stari, sigma, gamma, transitions, stari_speciale

        else:
            
            error = 1
            text = "Tranzitie gresita !"
            return error, text, stari, sigma, gamma, transitions, stari_speciale
    return error, text, stari, sigma, gamma, transitions, stari_speciale


def Turing_Machine(transitions, stari_speciale):

    # inputul dat de la terminal
    input = sys.argv[2]  

    # starea curenta, initial este stare de inceput
    stare_curenta = stari_speciale[0]  

    solutii_1 = []  # lista cu continutul benzii
    solutii_2 = []  # lista cu continutul benzii de back-up

    # punem in aceasta lista unde se afla capatul benzii si caracterele inputului
    
    head = "(h)"
    solutii_1.append(head)
    solutii_2.append(head)

    for character in input:
        solutii_1.append(character)
        solutii_2.append(character)
        
    head_pos = 0

    while stare_curenta != 'qaccept' and stare_curenta != "qreject":
        
        input_sol1 = "".join(solutii_1)
        input_sol1 = input_sol1.replace("s", "_")  # s = space/blank 

        input_sol2 = "".join(solutii_2)
        input_sol2 = input_sol2.replace("s", "_")  # s = space/blank 
        
        print(input_sol1 + " (" + stare_curenta + ")")  # afisam continutul benzii dupa fiecare tranzitie + (starea curenta)
        
        for transition in transitions:

            transition = transition.split(" ")
            head_symbol_trans = transition[2]

            head_output=transition[3].split("/") #contine output-ul pentru ambele tape-uri

            if transition[0] == stare_curenta and solutii_1[head_pos] == head_symbol_trans :  # daca starea de inceput a tranzitiei coincide cu starea curenta si daca simbolurile de la capetele benzii coincid cu simbolurile de pe banda ale tranzitiei
               
                stare_curenta = transition[1]  # starea curenta devine starea urmatoare din tranzitie
                if len(transition) == 5 :  
                   
                    head_direction = transition[4]
                    if head_direction == 'R':  # in cazul in care directia este dreapta pentru capat
                      
                        solutii_1[head_pos], solutii_1[head_pos + 1] = solutii_1[head_pos + 1], solutii_1[head_pos]  # interschimbam capatul cu simbolul de pe pozitia urmatoare
                        solutii_2[head_pos], solutii_2[head_pos + 1] = solutii_2[head_pos + 1], solutii_2[head_pos]  # interschimbam capatul cu simbolul de pe pozitia urmatoare
                        
                        head_pos = head_pos + 1  # crestem pozitia capat
                        
                        if (head_pos == len(solutii_1) - 1 ) :
                            solutii_1.append("s")
                        if (head_pos == len(solutii_2) - 1) :
                            solutii_2.append("s")   # daca ne aflam pe pozitia finala din lista cu continutul benzii, adaugam un ' ' pentru a simula conceptul de infinitate din partea dreapta a benzii
                        
                        solutii_1[head_pos] = head  # schimbam pozitia head-ului pe banda1
                        solutii_2[head_pos] = head  # schimbam pozitia head-ului pe banda2
                    
                    if head_direction == 'L' and head_pos > 0:  # in cazul in care directia este stanga pentru capat
                        
                        solutii_1[head_pos], solutii_1[head_pos - 1] = solutii_1[head_pos - 1], solutii_1[head_pos]  # interschimbam capatul cu simbolul de pe pozitia urmatoare
                        solutii_2[head_pos], solutii_2[head_pos - 1] = solutii_2[head_pos - 1], solutii_2[head_pos]  # interschimbam capatul cu simbolul de pe pozitia anterioara
                        
                        head_pos = head_pos - 1  # scadem pozitia capatului
                        
                        solutii_1[head_pos] = head # modificam pozitia pe banda
                        solutii_2[head_pos] = head # modificam pozitia pe banda
                    break
                
        solutii_1[head_pos] = head
        solutii_2[head_pos] = head
    
    input_sol1 = "".join(solutii_1)
    input_sol1 = input_sol1.replace("s", "_")
    print(input_sol1 + " (" + stare_curenta + ")")  # afisam ultima configuratie a benzii + (starea finala - qaccept sau qreject)

    input_sol2 = "".join(solutii_2)
    input_sol2 = input_sol2.replace("s", "_")

    if stare_curenta == 'qaccept':
        print("Input corect !")
    else:
        print("Input gresit !")

    #exercise 3

    for i in range(0,len(solutii_1)):
        if solutii_1[i]!=solutii_2[i]:
            return 0
    return 1

    #

file = sys.argv[1]

error, text, stari, sigma, gamma, transitions, stari_speciale = Turing_Machine_config(file)

if error == 1:
    print(text)
else:
    print("Starile : ", stari)
    print("Sigma : ", sigma)
    print("Gamma : ", gamma)
    print("Tranzitii : ", transitions)
    print("Stari speciale : ", stari_speciale)

    #exercise 3
    if Turing_Machine(transitions, stari_speciale)==1:
        print("Benzile sunt identice.")
    else:
        print("Benzile nu sunt identice")
    #

