#  testing acceptance of a DFA - loaded from a DFA config file

import sys

filename, word_to_test = sys.argv[1:] 
file = open(filename, 'r')

alphabet = []
initial_state = ''
transition_states = []
final_states = []
transitions_dictionary = {}
'''
dictionary = {
    (q0, 'a'): q1
    (q0, 'b'): q2
    (q0, 'c'): q3
    ...
}
'''

# citire
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
            transitions_dictionary[(current_line[0].strip(), current_line[1])] = current_line[2].strip()
            current_line = file.readline()

    loop_number += 1

file.close()

current_state = initial_state

validation = True

for letter in word_to_test:
    if (current_state, letter) in transitions_dictionary.keys():
        current_state = transitions_dictionary[(current_state, letter)]
    else:
        validation = False
        break

if validation == False or current_state not in final_states:
    print("Test Acceptance of DFA - FALSE. Word not supported;")
else:
    print("Test Acceptance of DFA - TRUE.")


