# load and validate a DFA input file

import sys

filename=sys.argv[1]
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
            else:
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