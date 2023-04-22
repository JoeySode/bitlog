BitLog

BitLog is a command-line tool for displaying the binary representation of various numeric types, including unsigned and signed integers, single-precision and double-precision floating-point numbers. It provides a convenient way to visualize the binary representation of numbers in different formats for debugging, analysis, or educational purposes.

Features

BitLog supports the following features:

Displaying binary representation in different formats: unsigned integers (u64), signed integers (i64), single-precision floating-point numbers (f32), and double-precision floating-point numbers (f64).
Reading numeric input from command-line arguments: BitLog takes one or more numeric values as command-line arguments and displays their binary representation.
Support for hexadecimal output: In addition to binary representation, BitLog also displays the hexadecimal representation of input values.
Customizable output format: BitLog provides options to switch between unsigned integer (u64), signed integer (i64), single-precision floating-point (f32), and double-precision floating-point (f64) formats, allowing users to choose the format that suits their needs.

Usage

bitlog [options] [values]
BitLog takes the following options:

-u: Interpret input values as unsigned integers (default).
-s: Interpret input values as signed integers.
-f: Interpret input values as single-precision floating-point numbers.
-d: Interpret input values as double-precision floating-point numbers.
If no options are provided, BitLog interprets input values as unsigned integers by default.

Input values are provided as command-line arguments, separated by spaces. BitLog can accept multiple input values at once, and it will display the binary representation of each value in the specified format.

Examples

./bitlog 100 4 -s 65 -1000 -f 3.14159 1.414 -d 2.718 1.618

This will print 100 and 4's binary and hexadecimal values as unsigned 64 bit integers, 65 and -1000's binary and hexadecimal values as singed 64 bit integers, 3.14159 and 1.414's values as binary and hexadecimal values as a 32 bit floating point number, and the same is done for 2.718 and 1.618 but as 64 bit doubles.
Real output:

u64:
100     0b1100100       0x64
4       0b100   0x4

i64:
65      0b1000001       0x41
-1000   0b1111111111111111111111111111111111111111111111111111110000011000      0xfffffffffffffc18

f32:
3.141590        0b1000000010010010000111111010000       0x40490fd0
1.414000        0b111111101101001111110111110100        0x3fb4fdf4

f64:
2.718000        0b100000000000101101111100111011011001000101101000011100101011000       0x4005be76c8b43958
1.618000        0b11111111111001111000110101001111110111110011101101100100010111        0x3ff9e353f7ced917

License

BitLog is open source software released under the MIT License.

Contributions

Contributions to BitLog are welcome. If you find any issues or have suggestions for improvement, please feel free to open an issue or submit a pull request on the BitLog GitHub repository.