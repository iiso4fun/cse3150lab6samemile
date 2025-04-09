# cse3150lab6samemile

---

## Overview

This lab builds a Tokenizer app in C++ that reads text from a file, breaks it into words using regular expressions, and assigns each unique word a number (called a token). The app lets you quickly look up a word’s token or find the word by its token.

---

### Compile and Run

```bash
g++ -std=c++11 -Wall -o tokenizer tokenizer.cpp
./tokenizer input.txt
```

---

## How the App is Built

---

### Main Parts

- Handling Input:

  - Command-Line Arguments: 
    Reads the file name passed in when the program runs.

  - Reading the File: 
    Opens the file and loads all its text into one big string.

---

- Tokenizing the Text:

  - Tokenizer Class: 
    Handles the logic for finding words and assigning tokens.

    - Using Regex: 
      Uses C++11’s `<regex>` with the pattern `\\b\\w+\\b` to grab whole words.  
      Uses `std::sregex_iterator` to go through each match.

    - Data Structures:
      - `std::unordered_map<std::string, int>`:  
        Lets you find a token number quickly by looking up the word.
      - `std::vector<std::string>`:  
        Stores words by token number so you can easily go from number to word.

  - Design Patterns Used:
    - Facade Pattern: 
      The `Tokenizer` class brings everything—file reading, regex, and word mapping—into one easy-to-use interface.

    - Iterator Pattern:  
      Used with `std::sregex_iterator` to loop through the found words.

    - Clear Separation:  
      File handling, tokenizing, and output are kept in separate parts for clarity.

    - Encapsulation:  
      The inner details (like the map and vector) stay hidden behind the class’s public methods.

---

- Showing Results:

  - Console Output:  
    Displays the list of tokens and their words. Also supports searching for a token or a word.

---

## How the App Works (Step-by-Step)

```plaintext
   +--------------------------+
   |         Start            |
   +--------------------------+
              |
              v
   +--------------------------+
   | Run the App with         |
   | a Text File as Input     |
   +--------------------------+
              |
              v
   +--------------------------+
   | Read the File Name       |
   | from the Command Line    |
   +--------------------------+
              |
              v
   +--------------------------+
   | Open the File and        |
   | Read its Contents        |
   +--------------------------+
              |
              v
   +--------------------------+
   | Use Regex to Find Words  |
   | in the Text              |
   +--------------------------+
              |
              v
   +--------------------------+
   | Assign a Number to       |
   | Each Unique Word         |
   +--------------------------+
              |
              v
   +--------------------------+
   | Print and Search Tokens  |
   +--------------------------+
              |
              v
   +--------------------------+
   |           End            |
   +--------------------------+
```

---
