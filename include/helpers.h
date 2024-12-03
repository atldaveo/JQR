/**
 * @file helpers.h
 * @author David Chung
 * @brief A series of function prototypes for miscellaneous helper functions
 * to be used throughout the main program simple-calc.
 * 
 * @version 2.1
 * @date 2024-11-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef HELPERS_H
#define HELPERS_H

/**
 * @brief Prints instructions on what the CMD Line input
 * for simple-calc ought to be. 
 * 
 * @param Passes the name of the program (ie. the first CMD Line
 * input) as argv[0] as a const char pointer so that it can't be
 * altered. 
 */

void print_help(const char *program_name);

/**
 * @brief Prints the version information for simple-calc.
 * 
 */

void print_version();

#endif