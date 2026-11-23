 # Student Attendance Analyser

## 1. Project Title

**Student Attendance Analyser Using C**

---

## 2. Problem Statement

Students need to regularly monitor their subject-wise attendance to ensure that they meet the minimum attendance requirement. Manually calculating attendance and determining how attending or missing the next class will affect the attendance percentage can be time-consuming.

The **Student Attendance Analyser** is a menu-driven C program that allows students to enter their subject-wise attendance details and analyse their current attendance. The program predicts the effect of attending or missing the next class, calculates the rate of change in attendance, determines how many consecutive upcoming classes can be missed while maintaining the minimum attendance requirement, and identifies subjects in which the student is debarred.

A student having **less than 75% attendance in a particular subject is considered debarred in that subject**.

---

## 3. Team Name:

**Team Name: Code Blooded**

---

## 4. Batch

**Batch:** 19

---

## 5. Team Members

1. **Ekansh Gupta** — SAP ID: **590033730**
2. **Partha Sarathi Mahato** — SAP ID: **590033033**
3. **Anushka Anil Nair** — SAP ID: **590032073**

---

## 6. Objectives

- To calculate the current attendance percentage for each subject.
- To determine whether a student is **Eligible or Debarred** in each subject.
- To predict the new attendance percentage if the student attends the next class.
- To calculate the **rate of increase** in attendance after attending the next class.
- To predict the new attendance percentage if the student misses the next class.
- To calculate the **rate of decrease** in attendance after missing the next class.
- To determine how many consecutive upcoming classes a student can miss without attendance falling below 75%.
- To display all subjects in which the student is debarred.
- To calculate the student's overall attendance across all subjects.

---

## 7. Features

### Subject-wise Attendance Analysis

The program analyses attendance for the following subjects:

1. Advanced Engineering Mathematics
2. Physics for Computer Science
3. Problem Solving
4. Programming in C
5. Environment, Sustainability and Climate Change

For every subject, the student enters:

- Total number of classes conducted
- Number of classes attended

The program calculates:

- Current attendance percentage
- Eligibility/debarment status
- Attendance after attending the next class
- Rate of change after attending the next class
- Attendance after missing the next class
- Rate of change after missing the next class
- Number of consecutive upcoming classes that can be missed while maintaining at least 75% attendance
- Overall attendance across all subjects

### Menu-Driven Interface

```text
========== STUDENT ATTENDANCE ANALYSER ==========

1. Enter Attendance Details
2. View Current Attendance
3. Next Class Impact Analysis
4. Check How Many Classes Can Be Missed
5. View Debarred Subjects
6. View Overall Attendance
7. Exit
```

### Input Validation

The program ensures that:

- Total classes conducted are greater than zero.
- Classes attended cannot be negative.
- Classes attended cannot be greater than classes conducted.
- Invalid attendance values are not accepted.

### Debarment Analysis

For every subject:

```text
Attendance >= 75%  -> ELIGIBLE
Attendance < 75%   -> DEBARRED
```

Debarment is determined independently for each subject.

---

## 8. Algorithm / Pseudocode

### Algorithm

1. Start the program.

2. Store the names of the five subjects.

3. Display the main menu.

4. Ask the user to enter a menu choice.

5. If the user selects **Enter Attendance Details**:

   - Enter the total classes conducted for every subject.
   - Enter the number of classes attended.
   - Validate the entered values.
   - Store valid attendance details.

6. Calculate current attendance using:

   **Attendance % = (Classes Attended / Classes Conducted) × 100**

7. Compare the calculated attendance with 75%.

8. If attendance is greater than or equal to 75%, display **ELIGIBLE**.

9. Otherwise, display **DEBARRED**.

10. For next-class impact analysis:

    - Calculate the new attendance if the next class is attended.
    - Calculate the rate of increase.
    - Calculate the new attendance if the next class is missed.
    - Calculate the rate of decrease.

11. Determine how many consecutive upcoming classes can be missed while keeping attendance greater than or equal to 75%.

12. Display all subjects in which attendance is below 75%.

13. Calculate overall attendance using the total attended and conducted classes across all subjects.

14. Return to the main menu.

15. Repeat until the user selects **Exit**.

16. Stop the program.

### Pseudocode

```text
START

Store subject names

REPEAT

    Display Main Menu
    Read choice

    SWITCH(choice)

        CASE 1:
            FOR each subject
                Input total classes conducted
                Input classes attended

                WHILE input is invalid
                    Ask user to enter values again
                END WHILE
            END FOR

        CASE 2:
            FOR each subject
                Calculate attendance percentage

                IF attendance >= 75
                    Display "ELIGIBLE"
                ELSE
                    Display "DEBARRED"
                END IF
            END FOR

        CASE 3:
            FOR each subject
                Calculate current attendance

                Calculate attendance if next class is attended
                Calculate rate of increase

                Calculate attendance if next class is missed
                Calculate rate of decrease

                Display results
            END FOR

        CASE 4:
            FOR each subject
                IF attendance < 75
                    Display 0 classes can be missed
                ELSE
                    Calculate maximum consecutive classes
                    that can be missed while attendance >= 75
                END IF
            END FOR

        CASE 5:
            Display subjects having attendance < 75

        CASE 6:
            Add conducted classes of all subjects
            Add attended classes of all subjects

            Calculate overall attendance
            Display overall attendance

        CASE 7:
            Exit program

        DEFAULT:
            Display "Invalid Choice"

    END SWITCH

UNTIL choice = 7

STOP
```

---

## 9. Flowchart

```text
                         +-------------+
                         |    START    |
                         +------+------+
                                |
                                v
                    +-----------------------+
                    |   Display Main Menu   |
                    +-----------+-----------+
                                |
                                v
                    +-----------------------+
                    |     Enter Choice      |
                    +-----------+-----------+
                                |
                                v
                       < Is Choice = 7? >
                          /            \
                        YES             NO
                         |               |
                         v               v
                    +---------+   +------------------+
                    |   END   |   | Execute Selected |
                    +---------+   |   Menu Option    |
                                  +--------+---------+
                                           |
            +------------------------------+------------------------------+
            |                 |                 |             |           |
            v                 v                 v             v           v
      Enter Attendance    View Current     Next Class     Debarred    Overall
          Details          Attendance       Analysis      Subjects   Attendance
            |                 |                 |             |           |
            v                 v                 v             v           v
     Enter Conducted      Calculate       Calculate      Find Subjects   Add All
      & Attended             %           Current %        Below 75%      Classes
            |                 |                 |             |           |
            v                 v                 v             v           v
      Validate Input     Check >=75%      Attend/Miss    Display       Calculate
            |                 |            Analysis      Results          %
            v                 v                 |                         |
       Store Data       Display Status          v                         v
            |                              New Attendance              Display
            |                              + Rate Change               Overall
            |                                   |
            +----------------+------------------+-------------------------+
                             |
                             v
                    +--------------------+
                    | Return to Main Menu|
                    +--------------------+
```

---

## 10. C Concepts Used

The project demonstrates the following C programming concepts:

- **Variables and Data Types** — `int`, `float`, etc.
- **Arrays** — storing attendance details for multiple subjects.
- **Character Arrays / Strings** — storing subject names.
- **Functions** — dividing the program into separate modules.
- **User-defined Functions** — attendance calculation and different menu operations.
- **Conditional Statements** — `if`, `if-else`.
- **Switch Case** — implementing the menu-driven interface.
- **For Loops** — processing all five subjects.
- **While Loops** — input validation and attendance calculations.
- **Do-While Loop** — repeating the main menu until Exit is selected.
- **Arithmetic Operators** — calculating attendance percentages and rate of change.
- **Type Casting** — obtaining accurate floating-point attendance percentages.
- **Constants** — defining the minimum attendance requirement using `#define`.

---

## 11. Compilation and Execution Instructions

### Requirements

A C compiler such as **GCC** is required to compile and execute the program.

### Compilation

Save the source code as:

```text
student_attendance_analyser.c
```

Compile the program using:

```bash
gcc student_attendance_analyser.c -o attendance
```

### Execution

For Linux/macOS:

```bash
./attendance
```

For Windows:

```bash
attendance.exe
```

After execution, the **Student Attendance Analyser** menu will be displayed. Enter the attendance details and select the required analysis option.

---

## 12. Conclusion

The **Student Attendance Analyser** is a menu-driven C program designed to help students understand and monitor their subject-wise attendance.

The program calculates the current attendance percentage and analyses how attending or missing the next class affects the student's attendance. It also displays the corresponding rate of change, identifies subjects in which attendance falls below the required 75%, and determines how many consecutive upcoming classes can be missed while maintaining eligibility.

The project demonstrates the practical application of fundamental C programming concepts such as arrays, functions, loops, conditional statements, switch-case, input validation, and arithmetic calculations to solve a real-world student attendance problem.
