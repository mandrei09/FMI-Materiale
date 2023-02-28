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

# deleting unreachable states
for argument in transition_states:
    if argument not in transitions_dictionary.values():
        transition_states.remove(argument)
        for letter in alphabet:
            transitions_dictionary.pop((argument, letter), None)

# marking (p,q) pairs where p is in F and q isn't in F
marked_pairs = []
unmarked_pairs = []
for state1 in transition_states:
    for state2 in transition_states:
        if state1 != state2:
            if state1 in final_states and state2 not in final_states:
                marked_pairs.append([state1, state2])
            else:
                unmarked_pairs.append([state1, state2])

'''
r e p e a t
    for all non-marked pairs [p, q] do:
        for each letter a do:
            if the pair [d(p,a), d(q, a)] is marked:
                then mark [p, q]
until no new pairs are marked
'''

# marking other pairs
counter = True

while counter:
    counter = False
    for pair in unmarked_pairs:
        for letter in alphabet:
            if (pair[0], letter) in transitions_dictionary and (pair[1], letter) in transitions_dictionary:
                if [transitions_dictionary[(pair[0], letter)], transitions_dictionary[(pair[1], letter)]] in marked_pairs:
                    marked_pairs.append(pair)
                    if pair in unmarked_pairs:
                        unmarked_pairs.remove(pair)
                    counter = True

for pair in unmarked_pairs:
    if pair[::-1] in unmarked_pairs:
        unmarked_pairs.remove(pair)
                
# reduced autonom A'

# pairs of final and non-final states:
new_states = []

for pair in unmarked_pairs:
    if pair[0] in transition_states:
        transition_states.remove(pair[0])
    if pair[1] in transition_states:
        transition_states.remove(pair[1])

new_states.extend(unmarked_pairs)
new_states.extend(transition_states)

# new_states = [[A,E], [B,H], C, F, G]

# new initial state
new_initial_state = ''
for state in new_states:
    if initial_state in state:
        new_initial_state = state
        break

new_transitions_dictionary = {}

for pair in unmarked_pairs:
    for key, value in transitions_dictionary.items():
        if value in pair:
            new_transitions_dictionary[key] = pair

        if key[0] in pair:
            if key in new_transitions_dictionary.keys():
                new_transitions_dictionary[(tuple(pair), key[1])] = new_transitions_dictionary.pop(key)
            else:
                new_transitions_dictionary[(tuple(pair), key[1])] = value

for key, value in transitions_dictionary.items():                    
    if value in transition_states and key[0] in transition_states:
        new_transitions_dictionary[key]=value

print(new_initial_state)
print()
print(new_states)
print()
print(new_transitions_dictionary)