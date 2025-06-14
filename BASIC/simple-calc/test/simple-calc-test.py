import random
import subprocess

def generate_random_argument():
    """Generate random 32-bit integers and an operator."""
    int32_min = -2**31
    int32_max = 2**31 - 1
    num1 = random.randint(int32_min, int32_max)
    num2 = random.randint(int32_min, int32_max)
    operator = random.choice(['+', '-', '*', '/', '>>', '<<', 'x'])
    return num1, operator, num2

def run_simple_calc(executable_path):
    """Generate random arguments, run the C program, and capture its output."""
    # Generate random arguments
    num1, operator, num2 = generate_random_argument()
    print(f"Running command: {executable_path} {num1} '{operator}' {num2}")
    
    try:
        # Run the C program with the generated arguments
        result = subprocess.run(
            [executable_path, str(num1), operator, str(num2)],
            text=True,  # Capture output as a string
            stdout=subprocess.PIPE,  # Redirect stdout
            stderr=subprocess.PIPE   # Redirect stderr
        )
        
        # Print the output of the program
        if result.returncode == 0:
            print("Output:", result.stdout.strip())
        else:
            print("Error:", result.stderr.strip())
    except FileNotFoundError:
        print(f"Error: Could not find executable at {executable_path}. Ensure it is built and accessible.")
    except Exception as e:
        print(f"An unexpected error occurred: {e}")

if __name__ == "__main__":
    # Path to your compiled C program
    executable_path = "../build/simple-calc"
    
    # Run the program with random arguments
    run_simple_calc(executable_path)

# END OF FILE