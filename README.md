# Push Swap

This project has been created as part of the 42 curriculum by mekaraca.

## Overview

`push_swap` is a sorting algorithm project that sorts a list of integers using two stacks (A and B) and a minimal set of operations. The goal is to sort stack A in ascending order using the fewest moves possible.

## Algorithm: Turk Sort

This implementation uses the **Turk sorting algorithm**, a variant of the Turkish algorithm optimized for 42's push_swap constraints.

### How It Works

1. **Initialization**: Parse input numbers into stack A
2. **Index Assignment**: Assign a rank (0–n) to each number based on its value
3. **Push Phase**: Move all but 3 elements from stack A to stack B
4. **Sort Remainder**: Sort the remaining 3 elements in stack A using basic operations
5. **Insertion Phase**: For each element in stack B:
   - Calculate rotation costs to bring it to stack B's top
   - Calculate rotation costs to position its target in stack A
   - Find the cheapest element to reinsert
   - Execute rotations using combined moves when beneficial
   - Push back to stack A
6. **Final Rotation**: Rotate stack A so the smallest element is on top

### Allowed Operations

- `sa` / `sb`: Swap top 2 elements of stack A or B
- `ra` / `rb`: Rotate stack A or B (top element moves to bottom)
- `rra` / `rrb`: Reverse rotate stack A or B (bottom element moves to top)
- `rr` / `rrr`: Combined rotations on both stacks
- `pa` / `pb`: Push top element from one stack to another

## Building & Running

### Compile
```bash
make
```

### Run
```bash
./push_swap <numbers>
```

**Examples:**
```bash
./push_swap "3 2 1 0"          # Single string with spaces
./push_swap 3 2 1 0            # Multiple arguments
./push_swap "42"               # Already sorted
```

The program outputs the sequence of operations needed to sort the stack.

### Clean
```bash
make clean      # Remove object files
make fclean     # Remove all generated files
make re         # Rebuild
```

## Project Structure

```
push_swap/
├── push_swap.c              # Main entry point
├── push_swap.h              # Header with struct definitions
├── stack.c                  # Stack initialization and management
├── index.c                  # Index assignment (ranking)
├── init_stack_a.c           # Parse and validate input
├── parse_utils.c            # Validation helpers
├── split.c                  # String parsing utility
├── operations/              # Stack operation implementations
│   ├── push.c               # pa, pb operations
│   ├── rotate.c             # ra, rb, rr operations
│   ├── rev_rotate.c         # rra, rrb, rrr operations
│   └── swap.c               # sa, sb, ss operations
└── algorithm/               # Turk sort implementation
    ├── turk_sort.c          # Main algorithm orchestration
    ├── turk_calc.c          # Cost calculation for each element
    ├── turk_exec.c          # Execute calculated rotations
    └── turk_utils.c         # Helper utilities
```

## Core Data Structures

### `t_node`
Represents an element in the stack:
```c
typedef struct s_node {
    int value;              // Original number
    int index;              // Rank (0 = smallest)
    int cost_a;             // Rotations needed in stack A
    int cost_b;             // Rotations needed in stack B
    int cost_total;         // Total moves for reinsertion
    int target;             // Target position in stack A
    t_node *next, *prev;    // Doubly-linked list pointers
} t_node;
```

### `t_stack`
Represents a stack:
```c
typedef struct s_stack {
    t_node *top;            // First element
    t_node *bottom;         // Last element
    size_t size;            // Number of elements
} t_stack;
```

## Key Features

- **Efficient Reinsertion**: Calculates optimal paths using combined rotations (rr/rrr) when rotations overlap
- **Memory Safe**: Clears allocated memory on validation errors
- **Norminette Compliant**: Adheres to 42 coding standards
- **Input Validation**: Checks for duplicates, integer overflow, and invalid syntax

## Implementation Notes

- No external libraries used (no libft, no ft_printf)
- All operations write to stdout for evaluation compatibility
- Uses doubly-linked lists for O(1) insertions during reinsertion
- Cost calculation is O(n²) per reinsertion, scaling reasonably for typical push_swap inputs

## AI Usage Disclosure

**Transparency Statement:**
- AI was used for code organization, project planning, and creating edge-case test functions
- AI was used to understand and explain the Turk algorithm
- AI was used in writing this README

**Original Contributions:**
- Main algorithm implementation written by project owner
- Turk algorithm reference: Yigit Ogun

## Author

**mekaraca** - 42 Warsaw

## License

This project is part of the 42 curriculum and subject to its evaluation guidelines.
