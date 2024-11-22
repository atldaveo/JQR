# Following Python Style Guides

## Style Guides and Code Standards for Python

In this course, we follow the Python Google Style Guide. This lesson content goes over why to adhere to style guides and how to catch violations of our chosen guide.

???+ note "Importance of Following a Style Guide"

    A style guide, in software development, is a set of standards for the writing and design of code. These standards aim to ensure that code is consistent, readable, and maintainable, regardless of who writes or reads it.

## Why is it Important?

1. **Consistency**: Consistent code is easier to read and understand. When all developers in a team adhere to the same standards, the codebase looks as if it was written by one person.
2. **Readability**: Consistency brings readability, which reduces the time taken to understand and debug code.
3. **Teamwork**: Adhering to a style guide indicates that a developer is ready to work in a team. It shows respect for colleagues and ensures smoother collaboration.

## Examples of Code - Compliant and Non-Compliant

=== "Compliant Code"

    ```python
    def add_numbers(num1, num2):
        """Add two numbers."""
        return num1 + num2
    ```

=== "Non-Compliant Code"

    ```python
    def add(num1,num2):
      return num1+num2;
    ```

??? note "Spot the differences"

    The second example lacks a docstring, has inconsistent spacing, and has an unnecessary semicolon.

## What are Linters?

Linters are tools used to analyze code for potential errors and ensure that the code adheres to a style guide. Think of them as grammar checkers for code.

???+ info

    Linters not only identify aesthetic issues but also functional ones, potentially catching errors before they cause problems during execution.

## Using `pylint` with a Custom Configuration

`pylint` is a popular linter for Python. It analyzes Python code against a vast collection of coding standards and heuristics. You can also use a custom configuration file, typically named `pylintrc`, to enforce specific standards like the Google Style Guide.

### How to use `pylint` with `pylintrc`:

1. Install `pylint`:

   ```sh
   pip install pylint
   ```

2. Download the [pylintrc file](_assets/pylintrc) that configures `pylint` for the Google Style Guide.

3. Run `pylint` with the configuration file:

   ```sh
   pylint --rcfile=path_to_pylintrc your_file.py
   ```

## Applicable Exercises

PE 01 in [Fundementals of Python](..//07_Python_Programming/01_Python_Fundamentals/08_Practical_Exercise.md) contains an exercise for students to practice linting and correcting a python script.

## Conclusion & Further Resources

Adhering to a style guide is crucial for any professional developer. It ensures code consistency, readability, and indicates a developer's readiness to work in a team environment.

### Further Reading

- [Google Python Style Guide](https://google.github.io/styleguide/pyguide.html)
- [Pylint Documentation](https://pylint.pycqa.org/en/latest/)

!!! tip

    Regularly practicing code linting and adhering to standards will naturally improve your coding style over time. Stay consistent, and always strive for clear, maintainable code. Whenever possible you should automate this linting process as part of your build pipeline.
