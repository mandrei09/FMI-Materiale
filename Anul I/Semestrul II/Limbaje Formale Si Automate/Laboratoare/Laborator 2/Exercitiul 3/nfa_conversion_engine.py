import sys

filename = sys.argv[1]
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

new_states = []
dfa_states = [(initial_state,)]
dfa_transitions = {}
transition_to_check = ()

# step 1: operating the transitions from the 1st stage
for letter in alphabet:
    transition_to_check = (initial_state, letter)

    if tuple(sorted(transitions_dictionary[transition_to_check])) not in dfa_states:
        new_states.append(tuple(sorted(transitions_dictionary[transition_to_check])))
        dfa_states.append(tuple(sorted(transitions_dictionary[transition_to_check])))
    dfa_transitions[transition_to_check] = tuple(sorted(transitions_dictionary[transition_to_check]))


# step 2: operating states until there will be no new states
while len(new_states) != 0:
    for letter in alphabet:
        new_transition = (new_states[0], letter)

        tmp_state_list = [] # temporary list of states
        for state in new_states[0]:
            tmp = (state, letter)
            if tmp in transitions_dictionary.keys():
                for element in transitions_dictionary[tmp]:
                    if element not in tmp_state_list:
                        tmp_state_list.append(element)

        tmp_state_list = tuple(sorted(tmp_state_list))
        # checking if tmp_state_list already exists in DFA
        if tmp_state_list not in dfa_states:
            dfa_states.append(tmp_state_list)
            new_states.append(tmp_state_list)

        dfa_transitions[new_transition] = tmp_state_list
    new_states.remove(new_states[0])

dfa_final_states = []

for tuple in dfa_states:
    for element in tuple:
        if element in final_states:
            dfa_final_states.append(tuple)

print(dfa_final_states)