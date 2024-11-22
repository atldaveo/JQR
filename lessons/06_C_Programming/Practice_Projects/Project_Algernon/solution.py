import argparse
from collections import deque

def read_maze_from_file(filename):
    with open(filename, 'r') as file:
        maze = [list(line.strip()) for line in file.readlines()]
    return maze

def solve_maze(maze, verbose=False):
    start_row, start_col = next(((r, c) for r, row in enumerate(maze) for c, val in enumerate(row) if val == 'S'), None)
    if start_row is None or start_col is None:
        return "Start position not found"

    directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]
    queue = deque([((start_row, start_col), 0, [(start_row, start_col)])])  # Path tracking included
    visited = set([(start_row, start_col)])

    while queue:
        (row, col), steps, path = queue.popleft()
        if maze[row][col] == 'E':
            if verbose:
                for pr, pc in path:
                    if maze[pr][pc] not in "SE":  # Mark the path with '*'
                        maze[pr][pc] = '*'
                for line in maze:
                    print(''.join(line))
            return steps
        for dr, dc in directions:
            new_row, new_col = row + dr, col + dc
            if (0 <= new_row < len(maze) and 0 <= new_col < len(maze[0])
                and maze[new_row][new_col] != '#' and (new_row, new_col) not in visited):
                visited.add((new_row, new_col))
                queue.append(((new_row, new_col), steps + 1, path + [(new_row, new_col)]))

    return "End position not reachable"

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Solve a maze and optionally display the path.")
    parser.add_argument("maze_file", type=str, help="The path to the maze file.")
    parser.add_argument("-v", "--verbose", action="store_true", help="Display the solved maze with the path.")

    args = parser.parse_args()

    maze = read_maze_from_file(args.maze_file)
    steps = solve_maze(maze, args.verbose)
    if not args.verbose:
        print(f"Steps taken: {steps}")
