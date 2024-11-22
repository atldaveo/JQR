#!/bin/bash

#USAGE: for a single file, run as ./rosetta_code.sh -f <file>. This will work for either .c or .py files
#for a directory, run as ./rosetta_code.sh <directory>. This will work for all .c and .py files in the directory
#The -v flag can be used to enable verbose mode, this will print the full results of clang-tidy and cppcheck
#without this flag, only a summary is printed
#Clang-format is automatically run on all .c files and they are changed in place.
# pylint is run on all .py files, but they are not changed in place a vscode extention may be useful for this.


# Specifies the executables and format file paths. Change these to match your system/specific version requriements

clang_tidy_executable="clang-tidy"
clang_format_executable="clang-format"
cpp_check_executable="cppcheck"
pylint_executable="pylint"
CLANG_FORMAT_FILE="clang-format"
PYLINT_FORMAT_FILE=".pylintrc"

# Check for the verbosity and single file flags

verbose=false

single_file=false


# Function used to display results for clang-tidy
display_results() {
    local tmp_file="$1"
    local base_dir="$2"
    echo -e "\n\n"
    echo -e "- Use after free:            \t$(($(grep -c "Use of memory after it is freed" "$tmp_file") / 2))"
    sed -E "s|$base_dir/||" "$tmp_file" | grep -E "Use of memory after it is freed" | cut -d':' -f1-2 | sort -u
    echo -e "- Double frees:              \t$(($(grep -c "free released memory" "$tmp_file") / 2))"
    sed -E "s|$base_dir/||" "$tmp_file" | grep -E "free released memory" | cut -d':' -f1-2 | sort -u
    echo -e "- Null pointer dereferences: \t$(($(grep -c "dereference of a null pointer" "$tmp_file") / 2))"
    sed -E "s|$base_dir/||" "$tmp_file" | grep -E "dereference of a null pointer" | cut -d':' -f1-2 | sort -u
    echo -e "- Undefined or garbage value:\t$(grep -c "garbage value" "$tmp_file")"
    sed -E "s|$base_dir/||" "$tmp_file" | grep -E "garbage value" | cut -d':' -f1-2 | sort -u
    echo -e "- Magic number:              \t$(grep -c "magic number" "$tmp_file")"
    sed -E "s|$base_dir/||" "$tmp_file" | grep -E "magic number" | cut -d':' -f1-2 | sort -u
    echo -e "- Leak of memory:            \t$(grep -c "leak of memory" "$tmp_file")"
    sed -E "s|$base_dir/||" "$tmp_file" | grep -E "leak of memory" | cut -d':' -f1-2 | sort -u
    echo -e "- Global variable:           \t$(grep -c globally "$tmp_file")"
    sed -E "s|$base_dir/||" "$tmp_file" | grep -E "globally" | cut -d':' -f1-2 | sort -u
    echo -e "- Narrowing conversion:      \t$(grep -c "narrowing conversion" "$tmp_file")"
    sed -E "s|$base_dir/||" "$tmp_file" | grep -E "narrowing conversion" | cut -d':' -f1-2 | sort -u
    echo -e "- Implicit conversion:       \t$(grep -c "implicitly converted" "$tmp_file")"
    sed -E "s|$base_dir/||" "$tmp_file" | grep -E "implicitly converted" | cut -d':' -f1-2 | sort -u
    echo -e "- Param name too short:      \t$(grep -c "is too short" "$tmp_file")"
    sed -E "s|$base_dir/||" "$tmp_file" | grep -E "is too short" | cut -d':' -f1-2 | sort -u
    echo -e "- Unused Returns:            \t$(grep -c "value returned by this function" "$tmp_file")"
    sed -E "s|$base_dir/||" "$tmp_file" | grep -E "value returned by this function" | cut -d':' -f1-2 | sort -u
    echo -e "- Differing parameter names: \t$(grep -c "differing parameters" "$tmp_file")"
    sed -E "s|$base_dir/||" "$tmp_file" | grep -E "differing parameters" | cut -d':' -f1-2 | sort -u
    echo -e "\n\n"
}


display_cppcheck_results() {
    local tmp_file="$1"

    echo -e "\n\n"

    echo -e "Cppcheck error count: \t$(grep -c ":" "$tmp_file")"
    sed -E "s|$base_dir/||" "$tmp_file" | grep -E ":" | cut -d':' -f1-2 | sort -u
    echo -e "\n"
}


display_pylint_results() {
    local tmp_file="$1"

    echo -e "\n"

    grep "Your code has been rated" "$tmp_file"
}
# Parse through arguments

while getopts ":vf" opt; do

    case $opt in

    v) verbose=true ;;

    f) single_file=true ;;

    \?)

        echo "Invalid option: -$OPTARG" >&2

        exit 1

        ;;

    esac

done



# Shift the positional parameters to skip past the processed options

shift $((OPTIND - 1))



# Check if a directory argument is provided

if [ "$single_file" = false ] && [ -z "$1" ]; then

    echo "Usage: $0 [-v] [-s <file>] <directory>"

    echo "-v: Enable verbose mode"

    echo "-f: Specify single file"

    exit 1

fi



# Run clang-tidy for a single file or all files in the directory

directory="$1"

tmp_file=$(mktemp)

cpp_temp_file=$(mktemp)

pylint_temp_file=$(mktemp)


if [ "$single_file" = true ]; then

    # Process a single file

    if [ -z "$directory" ]; then

        echo "Usage: $0 [-v] [-f] <file>"

        exit 1

    fi

    file_extension="${directory##*.}"

    if [ "$file_extension" = "py" ]; then
        if [ "$verbose" = false ]; then
        echo "pylint summary for $directory"
        $pylint_executable --rcfile="$PYLINT_FORMAT_FILE" "$directory" >"$pylint_temp_file"
        display_pylint_results "$pylint_temp_file"
        else
        echo "pylint full results for $directory"
        $pylint_executable --rcfile="$PYLINT_FORMAT_FILE" "$directory"
        fi

    elif [ "$file_extension" = "c" ]; then

        if [ "$verbose" = true ]; then

            $clang_tidy_executable --checks="cert*, bugprone*, misc*, readability*" "$directory" -- -std=gnu99
            $clang_format_executable -i -style="file:$CLANG_FORMAT_FILE" "$directory"
            $cpp_check_executable --enable=all "$directory"

        else
            $clang_tidy_executable --checks="cert*, bugprone*, misc*, readability*" "$directory" -- -std=gnu99 >"$tmp_file"
            display_results "$tmp_file"
            $clang_format_executable -i -style="file:$CLANG_FORMAT_FILE" "$directory"
            $cpp_check_executable --enable=all "$directory" >"$cpp_temp_file" 2>&1
            display_cppcheck_results "$cpp_temp_file"

        fi

    fi

else

    # Process all files in the directory

    if [ "$verbose" = true ]; then

        find "$directory" -type f -name '*.c' -exec $clang_tidy_executable --checks="cert*, bugprone*, misc*, readability*" {} +
        find "$directory" -type f -name '*.c' -exec $clang_format_executable -i -style="file:$CLANG_FORMAT_FILE" {} \;
        find "$directory" -type f -name '*.c' -exec $cpp_check_executable --enable=all {} +
        find "$directory" -type f -name '*.py' -exec pylint --rcfile="$PYLINT_FORMAT_FILE" {} +

    else
        find "$directory" -type f -name '*.c' -exec $clang_tidy_executable --checks="cert*, bugprone*, misc*, readability*" {} + >"$tmp_file"
        display_results "$tmp_file"
        echo "running clang format"
        find "$directory" -type f -name '*.c' -exec $clang_format_executable -i -style="file:$CLANG_FORMAT_FILE" {} \;
        find "$directory" -type f -name '*.c' -exec $cpp_check_executable --enable=all {} + >"$cpp_temp_file" 2>&1
        display_cppcheck_results "$cpp_temp_file"
        find "$directory" -type f -name '*.py' -exec pylint --rcfile="$PYLINT_FORMAT_FILE" {} + >"$pylint_temp_file"
        display_pylint_results "$pylint_temp_file"

    fi

fi







# Remove the temporary file (if not in verbose mode)

[ "$verbose" = false ] && rm "$tmp_file" "$cpp_temp_file" "$pylint_temp_file"