#  Voting System in C++

A simple console-based Voting System implemented in C++, demonstrating core object-oriented programming concepts like classes, file handling, and user interaction.

---

##  Features

-  Candidate data is loaded from a file (`candidates.txt`)
-  Each voter can only vote once (based on a unique voter ID)
-  Displays all candidates in a tabular format
-  Tracks and displays vote counts
-  Declares winner(s) at the end

---

##  Project Structure
VotingSystem/
├── main.cpp # Source code for the voting system
├── candidates.txt # Input file with candidate info
└── README.md # Project overview and instructions


---

##  Sample `candidates.txt` Format

Each line contains: <id>|<full name>|<party name>

Example:
101|Rebel Gandhi|Congress Party
102|Damodar Godi|BJP
105|Shivgami Devi|AITC
107|Raj Thokrey|MNS

> Make sure the file is placed in the **same directory as `main.cpp`** when running the program.
---

##  How to Compile and Run

###  Using Terminal
```bash
g++ main.cpp -o voting
./voting

*Sample*
=== Welcome to the Voting System ===

Menu:
1. View Candidates
2. Cast Vote
3. Show Results
4. Exit
Enter your choice: 1

--- Candidate List ---
ID: 101 | Name: Rahul Kumar | Party: Congress Party | Votes: 0
...

Enter your choice: 2
Enter your Voter ID: 1001
Enter Candidate ID to vote: 101
Your vote has been recorded.


##Concepts Used:
---------------------------------------------------
1.Object-Oriented Programming (OOP)
2.File I/O using ifstream
3.STL containers: vector, map, set
4.Basic data validation
5.Simple CLI menu navigation
