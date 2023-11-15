cmake_minimum_required(VERSION 3.26)
project(_PRINTF C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(_PRINTF
        _printf.c
        _put.c
        convert_number.c
        main.h
        number.c
        params.c
        print_functions.c
        print_number.c
        simple_printers.c
        specifier.c
        string_fields.c
        main.c)
