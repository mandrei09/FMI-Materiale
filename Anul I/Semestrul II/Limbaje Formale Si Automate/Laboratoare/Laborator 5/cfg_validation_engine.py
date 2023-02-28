import random as rd
import sys

#generating the rules for the CFG

# filename=sys.argv[1]
# file = open(filename, 'r')

file=open("cfg_config_file.txt","r")

rules={}
for line in file:
    index=0
    words=line.split()
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

#

def generate_items(items):
    for item in items:
        if isinstance(item, list):
            for subitem in generate_items(item):
                yield subitem
        else:
            yield item       

def expansion(start):
    for element in start:
        if element in rules:
            loc = start.index(element)
            start[loc] = rd.choice(rules[element])
        result = [item for item in generate_items(start) if item!="NULL"]
        
    for item in result:
        if not isinstance(item, list):
            if item in rules:
                result = expansion(result)
    
    return result

def to_string(result):
    return ' '.join(result)

result = ["S"]
result = expansion(result) 
final = to_string(result)

# print(rules)

print('\n',final,'\n',sep="")

    