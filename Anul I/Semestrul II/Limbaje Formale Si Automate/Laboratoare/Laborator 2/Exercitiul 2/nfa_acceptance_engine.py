# testing acceptance of a NFA - loaded from a  NFA config file

import sys

filename, word_to_test = sys.argv[1:]
file = open(filename, 'r')

alphabet = []
initial_state = ''
transition_states = []
final_states = []
transitions_dictionary = {}

'''
transitions_dictionary = {
    (state, 'letter'): [state1, state2, ...]
    ...
}
'''

loop_number = 0

while loop_number < 3:
    line = file.readline()
    current_line = ''
    if "Sigma" in line:
        current_line = file.readline()
        while current_line.strip() != "End":
            alphabet.append(current_line.strip())
            current_line = file.readline()
    elif "States" in line:
        current_line = file.readline()
        while current_line.strip() != "End":
            if 'F' in current_line:
                final_states.append(current_line.split(',')[0].strip()) 
            elif 'S' in current_line:
                initial_state = current_line.split(',')[0].strip()
            transition_states.append(current_line.split(',')[0].strip()) 
            current_line = file.readline()
    elif "Transitions" in line:
        current_line = file.readline()
        while current_line.strip() != "End":
            current_line = current_line.split(',')
            if (current_line[0].strip(), current_line[1].strip()) not in transitions_dictionary:
                transitions_dictionary[(current_line[0].strip(), current_line[1])] = []
            transitions_dictionary[(current_line[0].strip(), current_line[1])].append(current_line[2].strip())
            current_line = file.readline()

    loop_number += 1    

file.close()

current_state = [initial_state]

'''
    'a'
    q0, a -> q1 , q2
    current_state = [q0, q1]

'''

for letter in word_to_test:
    states = []
    for state in current_state:
        if(state, letter) in transitions_dictionary.keys():
            for element in transitions_dictionary[(state, letter)]:
                if element not in states:
                    states.append(element)
    current_state = states.copy()
        

validation = False
for state in current_state:
    if state in final_states:
        validation = True

if validation == False:
    print("Test Acceptance of NFA - FALSE. Word not supported;")
else:
    print("Test Acceptance of NFA - TRUE.")