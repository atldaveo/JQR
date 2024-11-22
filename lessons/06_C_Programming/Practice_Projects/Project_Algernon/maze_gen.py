import random

"""   
The script should generate mazes of size `level * 10` x `level * 10` and save them as `maze_level_X.txt`, where `X` is the level number (1-20).

This script generates mazes of increasing size for each level and saves them as separate text files. You can run this script to generate the maze files before distributing the assignment to the students.

Note: Make sure to provide the generated maze files along with the assignment for the students to use in their maze runner program.
"""
def generate_maze(width, height):
    maze = [['#' for _ in range(width)] for _ in range(height)]
    
    def find_neighbors(row, col):
        neighbors = []
        for dr, dc in [(0, 2), (2, 0), (0, -2), (-2, 0)]:
            new_row, new_col = row + dr, col + dc
            # Check bounds for rows and columns to keep all borders intact
            if 1 <= new_row < height - 1 and 1 <= new_col < width - 1 and maze[new_row][new_col] == '#':
                neighbors.append((new_row, new_col))
        return neighbors
    
    # Adjust starting and ending points to be within the inner area, away from all edges
    start_row, start_col = random.randint(1, height - 2), random.randint(1, width - 2)
    end_row, end_col = random.randint(1, height - 2), random.randint(1, width - 2)

    stack = [(start_row, start_col)]
    visited = set([(start_row, start_col)])

    while stack:
        row, col = stack[-1]  # Use the last item but don't remove it yet
        neighbors = find_neighbors(row, col)
        if not neighbors:
            stack.pop()  # No unvisited neighbors, backtrack
            continue

        new_row, new_col = random.choice(neighbors)
        maze[(row + new_row) // 2][(col + new_col) // 2] = ' '  # Break the wall between cells
        maze[new_row][new_col] = ' '
        stack.append((new_row, new_col))
        visited.add((new_row, new_col))

    maze[start_row][start_col] = 'S'
    maze[end_row][end_col] = 'E'

    return maze

def save_maze(maze, filename):
    with open(filename, 'w') as file:
        for row in maze:
            file.write(''.join(row) + '\n')

"""Mazes 1-19"""
for level in range(1, 20):
    size = level * 10
    maze = generate_maze(size, size)
    save_maze(maze, f'level_{level:03d}.txt')

"""Mazes 20-100 (increments of 10)"""
for level in range(20, 101, 10):
    size = level * 10
    maze = generate_maze(size, size)
    save_maze(maze, f'level_{level:03d}.txt')