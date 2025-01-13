#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STATES 10
#define MAX_ALPHABET 2

// Transition table
int transition[MAX_STATES][MAX_ALPHABET];

// DFA components
int num_states;
int num_final_states;
int final_states[MAX_STATES];
int start_state;

// Function to simulate DFA
bool simulate_dfa(char *input) {
    int current_state = start_state;

    for (int i = 0; i < strlen(input); i++) {
        char symbol = input[i];

        // Map 'a' -> 0, 'b' -> 1
        int symbol_index = (symbol == 'a') ? 0 : (symbol == 'b') ? 1 : -1;

        if (symbol_index == -1) {
            printf("Invalid character '%c' in input.\n", symbol);
            return false;
        }

        current_state = transition[current_state][symbol_index];
    }

    // Check if the current state is a final state
    for (int i = 0; i < num_final_states; i++) {
        if (current_state == final_states[i]) {
            return true;
        }
    }

    return false;
}

int main() {
    // Input number of states
    printf("Enter the number of states: ");
    scanf("%d", &num_states);

    // Input start state
    printf("Enter the start state: ");
    scanf("%d", &start_state);

    // Input number of final states
    printf("Enter the number of final states: ");
    scanf("%d", &num_final_states);

    // Input final states
    printf("Enter the final states: ");
    for (int i = 0; i < num_final_states; i++) {
        scanf("%d", &final_states[i]);
    }

    // Input DFA transition table
    printf("Enter the DFA transition table:\n");
    printf("Format: current_state input_symbol next_state\n");

    for (int i = 0; i < num_states * 2; i++) { // Assuming 2 symbols ('a' and 'b')
        int current_state, next_state;
        char input_symbol;

        scanf("%d %c %d", &current_state, &input_symbol, &next_state);

        // Map 'a' -> 0, 'b' -> 1
        int symbol_index = (input_symbol == 'a') ? 0 : 1;

        transition[current_state][symbol_index] = next_state;
    }

    // Display the transition table
    printf("\nDFA Transition Table:\n");
    printf("State\t'a'\t'b'\n");
    for (int i = 0; i < num_states; i++) {
        printf("%d\t%d\t%d\n", i, transition[i][0], transition[i][1]);
    }

    // Input string to check
    char input[100];
    printf("Enter the string to check: ");
    scanf("%s", input);

    // Simulate DFA
    if (simulate_dfa(input)) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }

    return 0;
}
