def tower_of_hanoi(n, source, auxiliary, destination, moves):
    if n == 1:
        moves.append((source, destination))
        return
    
    # Move n-1 disks from source to auxiliary
    tower_of_hanoi(n-1, source, destination, auxiliary, moves)
    
    # Move the largest disk from source to destination
    moves.append((source, destination))
    
    # Move n-1 disks from auxiliary to destination
    tower_of_hanoi(n-1, auxiliary, source, destination, moves)

def main():
    n = int(input().strip())
    
    # Calculate minimum number of moves: 2^n - 1
    min_moves = (1 << n) - 1  # Same as 2^n - 1
    
    # Generate all moves
    moves = []
    tower_of_hanoi(n, 1, 2, 3, moves)
    
    # Output results
    print(min_moves)
    for a, b in moves:
        print(f"{a} {b}")

if __name__ == "__main__":
    main()