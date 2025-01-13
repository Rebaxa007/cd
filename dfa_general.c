#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STATES 100
#define MAX_SYMBOLS 10

// Structure to define a DFA
typedef struct {
    int num_states;                    // Number of states
    char alphabet[MAX_SYMBOLS];        // Input alphabet
    int num_symbols;                   // Number of symbols in the alphabet
    int transition[MAX_STATES][MAX_SYMBOLS]; // Transition table
    int start_state;                   // Start state
    int final_states[MAX_STATES];      // Final states
    int num_final_states;              // Number of final states
} DFA;

// Function to get the index of a symbol in the alphabet
int get_symbol_index(char symbol, char alphabet[], int num_symbols) {
    for (int i = 0; i < num_symbols; i++) {
        if (alphabet[i] == symbol) {
            return i;
        }
    }
    return -1; // Symbol not found
}

// Function to check if a state is a final state
bool is_final_state(int state, int final_states[], int num_final_states) {
    for (int i = 0; i < num_final_states; i++) {
        if (final_states[i] == state) {
            return true;
        }
    }
    return false;
}

int main() {
    DFA dfa;

    // Input DFA details
    printf("Enter the number of states: ");
    scanf("%d", &dfa.num_states);

    printf("Enter the number of symbols in the alphabet: ");
    scanf("%d", &dfa.num_symbols);

    printf("Enter the alphabet (space-separated symbols): ");
    for (int i = 0; i < dfa.num_symbols; i++) {
        scanf(" %c", &dfa.alphabet[i]);
    }

    printf("Enter the transition table:\n");
    printf("(Enter the next state for each state-symbol pair)\n");
    for (int i = 0; i < dfa.num_states; i++) {
        for (int j = 0; j < dfa.num_symbols; j++) {
            printf("delta(q%d, %c) = ", i, dfa.alphabet[j]);
            scanf("%d", &dfa.transition[i][j]);
        }
    }

    printf("Enter the start state: ");
    scanf("%d", &dfa.start_state);

    printf("Enter the number of final states: ");
    scanf("%d", &dfa.num_final_states);

    printf("Enter the final states (space-separated): ");
    for (int i = 0; i < dfa.num_final_states; i++) {
        scanf("%d", &dfa.final_states[i]);
    }

    // Display DFA details
    printf("\nDFA Details:\n");
    printf("States: %d\n", dfa.num_states);
    printf("Alphabet: ");
    for (int i = 0; i < dfa.num_symbols; i++) {
        printf("%c ", dfa.alphabet[i]);
    }
    printf("\nTransition Table:\n");
    for (int i = 0; i < dfa.num_states; i++) {
        for (int j = 0; j < dfa.num_symbols; j++) {
            printf("delta(q%d, %c) = q%d\n", i, dfa.alphabet[j], dfa.transition[i][j]);
        }
    }
    printf("Start State: q%d\n", dfa.start_state);
    printf("Final States: ");
    for (int i = 0; i < dfa.num_final_states; i++) {
        printf("q%d ", dfa.final_states[i]);
    }
    printf("\n\n");

    // Input string to check
    char input_string[100];
    printf("Enter the input string: ");
    scanf("%s", input_string);

    // Simulate the DFA
    int current_state = dfa.start_state;
    for (int i = 0; i < strlen(input_string); i++) {
        int symbol_index = get_symbol_index(input_string[i], dfa.alphabet, dfa.num_symbols);
        if (symbol_index == -1) {
            printf("Invalid symbol '%c' in the input string.\n", input_string[i]);
            return 1;
        }
        current_state = dfa.transition[current_state][symbol_index];
    }

    // Check if the current state is a final state
    if (is_final_state(current_state, dfa.final_states, dfa.num_final_states)) {
        printf("The string '%s' is accepted by the DFA.\n", input_string);
    } else {
        printf("The string '%s' is rejected by the DFA.\n", input_string);
    }

    return 0;
}
