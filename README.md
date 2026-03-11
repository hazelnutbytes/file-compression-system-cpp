# File Compression & Decompression System (C++)

This project is a simple **File Compression and Decompression tool written in C++**.  
It demonstrates how basic algorithms and file handling can be used to reduce file size and restore the original data.

The program uses **Run-Length Encoding (RLE)**, a basic compression technique that replaces repeated characters with the character followed by the number of times it appears.

Example:

```
Input:  aaaabbbcc
Output: a4b3c2
```

The compressed file can later be decompressed to recreate the original content.

---

## Features

- Compress text files
- Decompress previously compressed files
- Simple command-line interface
- Uses C++ file handling (`ifstream`, `ofstream`)
- Demonstrates a basic compression algorithm

---

## How It Works

### Compression
The program reads characters from a file and counts consecutive repeated characters.  
Instead of writing the same character multiple times, it writes the character followed by the number of occurrences.

Example:

```
Original text:  aaaaabbbbcc
Compressed:     a5b4c2
```

### Decompression
The decompression function reads the compressed format and reconstructs the original sequence of characters.

Example:

```
Compressed: a5b4c2
Output:     aaaaabbbbcc
```

---

## Project Structure

```
project/
│
├── compression.cpp
├── input.txt
├── compressed.txt
├── decompressed.txt
└── README.md
```

---

## How to Run the Program

### 1. Compile the code

```
g++ compression.cpp -o compression
```

### 2. Run the program

```
./compression
```

### 3. Choose an option

```
1. Compress File
2. Decompress File
```

Then enter the input and output file names when prompted.

---

## Example

Input file:

```
aaaaabbbbccccdd
```

Compressed file:

```
a5b4c4d2
```

Decompressed file:

```
aaaaabbbbccccdd
```

---

## Technologies Used

- C++
- Standard libraries:
  - `iostream`
  - `fstream`
  - `string`
