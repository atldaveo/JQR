# Following C Style Guides

## Why Standardize Code Style

Standardizing code style across an organization promotes efficient collaboration by increasing readability and maintainability and reducing chances for error. CCDs are expected to follow the coding standards and style set by their organization. Furthermore, students will complete the BSLE and CCD JQR as pass/fail items, but their code in these events will be reviewed in a code review. Part of the code reviews should assess their compliance code styling guides for C and Python.

## The Barr Group Embedded C Code Standard

Barr Group Embedded C Coding Standard is archived [here](https://barrgroup.com/embedded-systems/books/embedded-c-coding-standard).

Students and the Instructor will spend time reading through the entire coding standard. As they go through, instructors should emphasize to students the following items.

**High level overview:**

- Line width max of 80 characters - Barr 1.2.a.
- Braces - 1.3.a. & 1.3.b.
- Operator precedence - 1.4.a.
- Surround logic operators with parenthesis - 1.4.b.
- Abbreviations - 1.5.a. & 1.5.b.
- Comment cast’ed variable types - 1.6.a.
- Keywords to avoid - 1.7.a to 1.7.d.
- Keywords to use - 1.8.a to 1.8.c
- Commenting format and uses - 2.1 & 2.2
- White spaces - 3.1 to 3.6
- Module rules - 4.1 to 4.4
- Data and variable naming - 5.1 to 5.5
- Function naming 6.1 to 6.5
- Variable naming - 7.1 & 7.2
- Statement rules - 8.1 to 8.6

!!! note "Key Note"

    For the sake of clarity and readability, the course will emphasize, when possible, the following notes that are somewhat ambiguous in the Barr style guide:

    - All variables should be declared and initialized together at the beginning of function.
    - When cleaning up, all variables should be cleaned together in a group prior to returning once. In this instance, a `goto` may be appropriate.

For example:

```c
void example()
{
    // initialization
    char user_ch = 0;
    char * var = NULL;


    // body of function
    user_ch = getch();

    if(0x42 == user_ch)
    {
        var = malloc(10);
        goto exit;
    }

    user_ch = getch();

    if(0x43 == user_ch)
    {
        var = malloc(10);
    }


    // cleanup
    label: exit;
        free(var); // free on NULL is OK
        return;

}
```

After reading through the guide, ask students to identify style mistakes within the following source code.

### Example

Identify the violations of styling in the following example:

```c
int main(void){
    int x, y, z = 0;
    char * message;
    if (x == 0) {
        char * hello
        printf("x is zero");
    }
    label: ask;
    y = getch;
    if (y ==41) {
        return 1;
    }
    goto ask;
    message = "hello!";
    printf("Where's the mistake?\n");
    return 0;
}
```

## Automated Testing

There are many automated styling tools available for both python and C. These tools can help developers match their code to a particular style guide and avoid security concerns. The [rosetta_code.sh](rosetta_code/rosetta_code.sh) script can be used to run clang-tidy, clang-format and cppcheck on all C code in a directory with `./rosetta_code <dir>` or on an individual life with `./rosetta_code -f <file_name>`. The script can also be used to run pylint on python code in a similar manner. While this script will not check for everything and it may need to be modified depending on the specific use-case, when developing projects, especially in this course, it would be wise to first run this script on all projects and code before submitting them. Note, the [pylintrc](rosetta_code/pylintrc) and [clang-format](rosetta_code/clang-format) files are required in the same directory as the rosetta_code script for it to work.

## Outcome

Students will understand how to properly style C code in accordance with the Barr Group's Embedded C Coding Standard.

## Admin Information

| attribute | value |
| --- | --- |
| mode_of_delivery | RI - Resident Instructor |
| time_of_instruction_mins | 15 |
| media_type | Actual Equipment, Live Demonstration |
| method_of_instruction | GRT - Guided Reading and Thinking |
| instructor_type | Military/Civilian |
| title | c_coding_standards |
| other_media_type | None |
| ratio | 1:10 |
| content_security_classification |  |
| review_summary |  |
| time_of_instruction_hrs | 1 |
| lsa_title | Understand how to properly style C code in accordance with the Barr Group's Embedded C Coding Standard. |
