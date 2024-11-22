# Project Algernon

In a world where intelligence is highly valued, a group of scientists has developed Project [Algernon](https://en.wikipedia.org/wiki/Flowers_for_Algernon), a series of intricate mazes designed to enhance human cognitive abilities. The participants, known as "Pathfinders," navigate through the mazes of increasing complexity, testing their mental agility and problem-solving skills. Among them is Charlie Gordon, a young man eager to expand his intellect and contribute to the advancement of human knowledge.

As the Pathfinders progress through the mazes, they face challenges that mirror the complexities of their own minds, forcing them to confront their fears and limitations. Charlie finds himself on a transformative journey, questioning the true nature of intelligence and the price of knowledge. With each solved maze, the Pathfinders' minds expand, but the final and most challenging maze looms ahead, holding the key to the success of Project Algernon.

In this project, you will embark on a journey as a Pathfinder, navigating through the Maze of Enlightenment. Your goal is to implement advanced search algorithms, such as depth-first search (DFS) and breadth-first search (BFS), to find the optimal path to intellectual greatness. By comparing the efficiency and effectiveness of these algorithms, you will gain insights into the workings of the human mind and the strategies we employ to solve complex problems.

## Rubric

| Area | Requirement | Points |
|---|---|---|
| Functionality | DFS and BFS algorithms implemented correctly | 30 |
| Functionality | Maze solving functionality works as expected | 25 |
| Functionality | Program handles error cases gracefully | 10 |
| Code Quality | Code is modular and well-organized | 10 |
| Code Quality | Appropriate data structures are used | 10 |
| Code Quality | Code is properly indented and commented | 5 |
| User Interface | Program displays solved paths clearly | 10 |
| Total | | 100 |

## Requirements

1. The program should accept a command-line argument specifying the level of the maze to solve (1-20). If no argument is provided, the program should solve all the mazes in the `mazes` directory in order.
   - The maze files will be provided in the format `level_XXX.txt`, where `XXX` is the level number. Numbers are left-padded with `0` to make ordering easier (i.e. `level_001.txt`)
   - It should also allow for an optional verbose flag (`-v`)

2. Implement a search algorithm to solve the maze.
   - The program should read the maze from the corresponding file based on the specified level.
   - The program shall display the distance it took to solve. 
   - If the `verbose` flag is specified, then the solved maze should be displayed, showing the path taken by the algorithm

3. Handle error cases gracefully:
   - Invalid command-line arguments (e.g., non-integer level, level out of range).
   - Missing maze files.
   - Unsolvable mazes

4. Design the program in a modular fashion:
   - Separate the maze solving and display functionality into different functions or modules.
   - Use appropriate data structures to represent the maze and efficiently perform the search algorithms.

5. Follow good coding practices:
   - Use meaningful variable names and function names.
   - Indent the code properly and use consistent formatting.
   - Add comments to explain complex or important parts of the code.

## Samples

### Maze 2

#### Input:  

```
####################
####################
#   #   #         ##
# # # # # ### ### ##
# # # # #   #   # ##
# # # # ### ### # ##
# # # #   #   # # ##
# ### ### ### # # ##
#     #   #   # # ##
##### # ### ### # ##
#   # #     #   # ##
# # ### ##### ### ##
# #   # # E #   # ##
# ### ### # ### # ##
#   #     #     # ##
# # ############# ##
# #   # #   #   # ##
# ### # # # # # # ##
#S    #   #   #   ##
####################
```

#### Output:

```
$ ./algernon 2
Steps taken: 23
```

#### Output (Verbose):

```
$ ./algernon 2 -v
Steps taken: 23

####################
####################
#   #   #         ##
# # # # # ### ### ##
# # # # #   #   # ##
# # # # ### ### # ##
# # # #   #   # # ##
# ### ### ### # # ##
#     #   #   # # ##
##### # ### ### # ##
#***# #     #   # ##
#*#*### ##### ### ##
#*#***# #*E #   # ##
#*###*###*# ### # ##
#*  #*****#     # ##
#*# ############# ##
#*#   # #   #   # ##
#*### # # # # # # ##
#S    #   #   #   ##
####################
```

### Maze 3

#### Input:
```
##############################
##############################
#     #       #             ##
# ### # ####### ########E## ##
#   # # #     #   #         ##
# # # # # ### ### # ##########
# # #   # # #     #       # ##
# # ##### # ############# # ##
# # #             # #   # # ##
### # ########### # # # # # ##
#   #   #       #   # #   # ##
# ##### # ##### ##### ##### ##
# #     # #   #       #     ##
# # ##### # # ######### ### ##
#   #   #   # #         # # ##
# ### ####### ##### ##### # ##
# #         #S  #   #   #   ##
# ### ##### ##### ### # # ####
#   #   #   #     #   # # # ##
### # ### # # ### ### # # # ##
#   # #   # #   #   # #   # ##
# ### # ### ####### # ##### ##
# #   #   #     #   #       ##
# # ##### ##### # ############
# #     # #     #   #       ##
# ##### # ### ##### # ##### ##
#   #   #   # #   #     #   ##
### ####### # # # ####### # ##
#           #   #         # ##
##############################
```

#### Output:

```
$ ./algernon 3
Steps taken: 56
```

#### Output (Verbose):

```
$ ./algernon 3 -v
Steps taken: 56

##############################
##############################
#     #       #             ##
# ### # ####### ########E## ##
#   # # #     #   #******   ##
# # # # # ### ### #*##########
# # #   # # #     #*******# ##
# # ##### # #############*# ##
# # #             # #***#*# ##
### # ########### # #*#*#*# ##
#   #   #*******#   #*#***# ##
# ##### #*#####*#####*##### ##
# #     #*#***#*******#     ##
# # #####*#*#*######### ### ##
#   #   #***#*#         # # ##
# ### #######*##### ##### # ##
# #         #S  #   #   #   ##
# ### ##### ##### ### # # ####
#   #   #   #     #   # # # ##
### # ### # # ### ### # # # ##
#   # #   # #   #   # #   # ##
# ### # ### ####### # ##### ##
# #   #   #     #   #       ##
# # ##### ##### # ############
# #     # #     #   #       ##
# ##### # ### ##### # ##### ##
#   #   #   # #   #     #   ##
### ####### # # # ####### # ##
#           #   #         # ##
##############################
```

## Mazes

- The Mazes can be [downloaded here](mazes.zip)