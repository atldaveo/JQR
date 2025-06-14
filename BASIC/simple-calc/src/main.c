/**
 * @file main.c
 * @author David Chung 
 * @brief Main entry point for simple-calc
 * 
 * This program performs simple arithmetic calculations given user input via CLI.
 * 
 * @date 2024-01-06
 * @version Last updated 2025-04-09
 * 
 */
                                                                            
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>                 
#include <unistd.h>
#include "operations.h"
#include "validations.h"
#include "arithmetic.h"

#define ARGCOUNT                4
#define FLAG_COND               2
#define END_FLAG                (-1)
#define HELP                    "h"
#define NAME_INDEX              0
#define FIRST_OPND_INDEX        1
#define OPTR_INDEX              2
#define SECOND_OPND_INDEX       3

int
main(int argc, char *argv[])
{ 
    bool return_code = false;                   /**< Initiate 'return_code' as false - enable single exit point */
    int32_t first_operand = 0;                  /**< Parsed first_operand */
    int32_t second_operand = 0;                 /**< Parsed second_operand */
    char* p_num_end1 = NULL;                    /**< Pointer to the end of first_operand */
    char* p_num_end2 = NULL;                    /**< Pointer to the end of second_operand */                   
    Operation operation = {0};                  /**< Operation default initialization to 0 */           
    int opt = 0;

    void flush_terminal();
    
    while(END_FLAG != (opt = getopt(argc, argv, HELP)))
    {
        switch (opt)
        {
            case 'h':
                print_help();
                goto end;
            default:
                print_error(INVALID_OPN);
                goto end;
        }
    }

    // Check number of arguments
    return_code = count_check(argc, ARGCOUNT);
    
    if (false == return_code)
    {
        print_error(ARG_ERROR);
        printf("Likely encountered wildcard expansion. Precede CLI command with 'set -f'\n"); 
        goto end;
    }
    
    // Check first operand
    return_code = check_opnd(argv[optind], p_num_end1, &first_operand);

    if (false == return_code)                       
    {
        print_error(INVALID_OPND);
        //printf("'%s'\n", argv[optind]);
        print_help();
        goto end;
    }
    optind++;
    
    // Check operator
    operation = get_operator(argv[optind]);
    return_code = check_operator(operation);
    if (false == return_code)
    {
        print_error(INVALID_OPTR);
        printf("'%s'\n", argv[optind]);
        print_help();
        goto end;
    }    
    optind++;

    // Check second operand
    return_code = check_opnd(argv[optind], p_num_end2, &second_operand);
    if (false == return_code)
    {
        print_error(INVALID_OPND);
        printf("'%s'\n", argv[optind]);
        print_help();
        goto end;
    } 

    // Execute operation
    execute_opn(first_operand, second_operand, operation);

// Single Exit Point
end:
    return return_code;
}

/* END OF FILE */