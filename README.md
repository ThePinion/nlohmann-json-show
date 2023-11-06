# JSON for Modern C++ Show

This repository contains a collection of examples showcasing the usage of the [`nlohmann/json`](https://github.com/nlohmann/json) library, also known as JSON for Modern C++. The library provides a simple and intuitive way to handle JSON data in C++. It is a header-only library that uses the latest features of the C++ standard to offer both ease of use and performance.

## Features

Here are some of the features of `nlohmann/json` that are demonstrated in this repository:

- Parsing and serializing JSON
- Working with JSON values, objects, and arrays
- Using JSON pointers for direct element access
- Computing and applying JSON patches and diffs
- Error handling in JSON operations
- Converting standard STL containers to/from JSON
- Using custom types with JSON

## Getting Started

To use these examples, you'll need to have a C++ compiler that supports C++11 or higher. No additional installation is required, as `nlohmann/json` is a header-only library.

## Running Specific Examples

In the `build/` directory, compiled programs are prefixed with numbers for identification. To run a specific example, use the `run.sh` script followed by the number of the program you wish to execute. The script will locate the corresponding program and run it for you.

### Usage

To run a program, navigate to the project root directory and use the following command:

```bash
./run.sh <number>
```
