## Data Structures and Algorithms Lab Manual

This lab manual is designed to provide you with hands-on experience with Python for implementing data structures and algorithms. The manual covers mathematical functions, string operations, and plotting graphs.

**Software:** Python 3 (or later), [Matplotlib](https://matplotlib.org/) library

**Note:** Make sure you have Python and Matplotlib installed before starting these labs.

In windows command prompt type `python --version` to check which version of python is installed.


### Lab 1: Mathematical Functions with Python

This lab explores built-in Python functions for common mathematical operations.

**1.1  Ceiling, Floor and Absolute**

```python
import math

number = 3.14159

print("Ceiling of", number, ":", math.ceil(number))
print("Floor of", number, ":", math.floor(number))
print("Absolute value of", number, ":", math.fabs(number))
```

**ToDo:**

* Write a program to find the ceiling, floor and absolute value of 5 different user inputs.
* Extend the program to identify if a number is positive, negative or zero.
* here is how to tak input in python  

```python
name = input("Enter your name: ")
print("Hello", name)
``` 

**1.2 Logarithms**

```python
import math

number = 10
base_2 = math.log2(number)
base_10 = math.log10(number)

print("Logarithm of", number, "to base 2:", base_2)
print("Logarithm of", number, "to base 10:", base_10)
```

**ToDo:**

*  Write a program to calculate logarithms (base 2 and 10) for different user inputs.
*  Plot a graph (using Matplotlib) that shows the change in value of logarithm with increasing base values (e.g., base 2 to base 10).


### Lab 2: Working with Strings

This lab covers basic string operations in Python.

**2.1 String Length and Slicing**

```python
text = "Data Structures and Algorithms"

# Get string length
string_length = len(text)

# Get substring
substring = text[0:10] 

print("Length of the string:", string_length)
print("Substring:", substring)
```

**ToDo:**

* Write a program to find the length of different user-entered strings.
*  Extract substrings based on user-provided starting and ending indexes.


**2.2 String Concatenation and Trimming**

```python
string1 = "Hello"
string2 = " World!"

# Concatenate strings
combined_string = string1 + string2

# Trim whitespaces
trimmed_string = combined_string.strip()

print("Combined String:", combined_string)
print("Trimmed String:", trimmed_string)
```

**ToDo:**

* Write a program to concatenate user-provided strings.
*  Implement functions to remove leading/trailing whitespaces from a string.


### Lab 3: Plotting Graphs with Matplotlib

This lab introduces Matplotlib for creating basic graphs.

**3.1 Plotting Linear Functions**

```python
import matplotlib.pyplot as plt

# Define linear function
def linear_function(x):
  return 2 * x + 5

x_values = range(1, 11)
y_values = [linear_function(i) for i in x_values]

# Plot the graph
plt.plot(x_values, y_values)
plt.xlabel("X-axis")
plt.ylabel("Y-axis")
plt.title("Linear Function (y = 2x + 5)")
plt.grid(True)
plt.show()
```

**ToDo:**

* Plot graphs for other linear functions (e.g., y = x, y = mx + c).
*  Change the plot appearance by modifying elements like labels, title, and grid.

**3.2 Plotting Logarithmic and Quadratic Functions (Continued)**

```python
import matplotlib.pyplot as plt
import math

# Define functions
def logarithmic_function(x):
  return math.log2(x)

def quadratic_function(x):
  return x**2 + 2 * x

x_values = range(1, 11)
log_y_values = [logarithmic_function(i) for i in x_values]
quad_y_values = [quadratic_function(i) for i in x_values]

# Plot multiple graphs on the same plot
plt.plot(x_values, log_y_values, label="Logarithmic")
plt.plot(x_values, quad_y_values, label="Quadratic")
plt.xlabel("X-axis")
plt.ylabel("Y-axis")
plt.title("Logarithmic and Quadratic Functions")
plt.grid(True)
plt.legend()  # Add legend to identify each line
plt.show()
```

**ToDo:**

*  Plot graphs for different logarithmic and quadratic functions by modifying the function definitions.
*  Experiment with additional functionalities of Matplotlib like markers, line styles, and colors to customize the plot appearance.


This revised response completes the code snippet for plotting logarithmic and quadratic functions and provides additional to-do suggestions for students to explore further functionalities of Matplotlib.