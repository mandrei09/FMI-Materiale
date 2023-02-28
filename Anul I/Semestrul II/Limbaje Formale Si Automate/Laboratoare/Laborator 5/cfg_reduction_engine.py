import sys

def printRules(rules):
    print("\n")
    for key in rules.keys():
        ok=0
        print(key,"->",end=" ")
        for value in rules[key]:
            if ok!=0:
                print(" | ",end="")
            ok=1
            for subvalue in value:
                for item in subvalue:
                    print(item,end=" ")
        print("")
    print("\n")


#generating the rules for the CFG

# filename=sys.argv[1]
# file = open(filename, 'r')

file = open("cfg_config_file.txt", 'r')

rules={}

ok=False

for line in file:
    index=0
    words=line.split()
    if ok==False:
        ok=True
        first=words[0]
    rules[words[0]]=[]
    for i in range(2,len(words)):
        if words[i]!="|":
            if rules[words[0]]==[]:
                rules[words[0]].append([words[i]])
            else:
                rules[words[0]][index].append(words[i])
        else:
            index+=1
            rules[words[0]].append([])

file.close()

#1. Useless Reduction

#productions that can never take part in derivation of any string

toBeDeleted=[]

for variable in rules.keys():
    ok=False
    for terminal in rules.values():
        for value in terminal:
            for subvalue in value:
                if variable==subvalue:
                    ok=True
                    break
    if ok==False and variable!=first:
        toBeDeleted.append(variable)

#infinite cycle
for variable in rules.keys():
    for value in rules[variable]:
        for subvalue in value:
            if variable==subvalue:
                toBeDeleted.append(variable)
                break

for variable in toBeDeleted:
    rules.pop(variable)

#2. Null reduction

nullable=[]

#selectam variabilele

#initial doar cele care au NULL

for variable in reversed(rules.keys()):
    index=0
    for value in rules[variable]:
        for subvalue in value:
            if subvalue=="NULL":
                nullable.append(variable)
                del rules[variable][index];
        index+=1

#apoi restul

for rule in reversed(rules.keys()):
    for null in reversed(nullable):
        for value in rules[rule]:
            if null in value:
                if rule not in nullable:
                    nullable.append(rule)

#generam toate combinatiile 

for rule in nullable:
    index=len(rules[rule])-1
    for value in rules[rule]:
        for subvalue in value:
            if subvalue in nullable:
                index+=1
                rules[rule].append([])
                for subv in value:
                    if subv!=rule and subv!=subvalue:
                        rules[rule][index].append(subv)

                #eliminam duplicatele + []

                if rules[rule][index]==[]:
                    del rules[rule][index]
                    index-=1

                nr=0
                for items in rules[rule]:
                    if rules[rule][index]==items:
                        nr+=1
                if nr>1:
                    del rules[rule][index]
                    index-=1
                
#3. Unit reduction


printRules(rules)







        
            


