## Data Structures and Algorithms Lab Manual

This lab manual is designed to provide you with hands-on experience with Python for implementing data structures and algorithms. The manual covers mathematical functions, string operations, and plotting graphs.

**Software:** Python 3 (or later), [Matplotlib](https://matplotlib.org/) library

**Note:** Make sure you have Python and Matplotlib installed before starting these labs.

In windows command prompt type `python --version` to check which version of python is installed.

- Here is how take input from user and convert it to a floating point number

```python
# the input function takes a number and stores it as a string
str_number = input("Enter a number")
# following line convert the value of str_number to a floating point
float_number = float(str_number)
``` 

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

**Exercise:**

One Pakistani Rupee consists of 100 Paisas. But coins of 1 paisa, 5 paisas, 10 paisas, 25 paisas, 50 paisas, 75 paisas, are not in circulation. You might have noticed that in daily shopping some other coins and notes are hardly exchanged, e.g. currency note or coin of 5 Rupees. 

In daily exchange people usually ignore small amounts above or below certain limits e.g. if a bill is of PKR 171, the actuall amount paid may be 170 and if the bill is of 169 the amount paid may be 170. 

* Write code to use a function to generate random number and calculate what amount will acutally be paid. Your code should logically use both ceil and floor functions.

- Suppose that people do not agree on paying more or less than their billing amount and a rule has to be introduced so that any amount above 5 Rupees will be treated as 10 PKR, and any amount below 5 Rupees will not be charged.

* Write code to use a function to generate random number between 1 and 10 and calculate what amount will acutally be paid. 

**1.2 Logarithms**

```python
import math

number = 10
base_2 = math.log2(number)
base_10 = math.log10(number)

print("Logarithm of", number, "to base 2:", base_2)
print("Logarithm of", number, "to base 10:", base_10)
```

**Exercise:**

*  Write a program to calculate logarithms (base 2) for the 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768

* Write a program to calculate logarithms (base 10) for the values 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000

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

**Exercise:**

* Write a program to find the length of different user-entered strings.
* Extract substrings based on user-provided starting and ending indexes.


**2.2 String Concatenation and Trimming**

```python
string1 = "     Hello"
string2 = " World!   "

# Concatenate strings
combined_string = string1 + string2

# Trim whitespaces
trimmed_string = combined_string.strip()

print("Combined String:", combined_string)
print("Trimmed String:", trimmed_string)
```

**Exercise:**

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

**Exercise:**

* Plot graphs for other linear functions (e.g., y = x, y = mx + c).
* Change the plot appearance by modifying elements like labels, title, and grid.

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

**Exercise:**

*  Plot graphs for different logarithmic and quadratic functions by modifying the function definitions.
*  Experiment with additional functionalities of Matplotlib like markers, line styles, and colors to customize the plot appearance.


This revised response completes the code snippet for plotting logarithmic and quadratic functions and provides additional to-do suggestions for students to explore further functionalities of Matplotlib.