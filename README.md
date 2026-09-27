# Color Blindness Color Picker

## Description: This program prompts the user for two colors and calculates the WCAG contrast ratio to determine if they are accessible to those with colorblindness.

**version 1.0**

## Fiona Wicks

## Example

Here is an example of the program running:

```
browser.cpp:~$ Compilation successful.
browser.cpp:~$ 
Enter First Color RGB values (0-255):
R: 0
G: 25
B: 32

Enter Second Color RGB values (0-255):
R: 45
G: 12
B: 13

--- Color Contrast Check ---
Contrast Ratio: 1.00868:1
Results: FAIL - These colors do not meet the AAA contrast standards
Try picking a new combination of colors. Would you like to test another set of colors? (y/n): 
y
Enter First Color RGB values (0-255):
R: 255
G: 0
B: 0

Enter Second Color RGB values (0-255):
R: 0
G: 255
B: 0

--- Color Contrast Check ---
Contrast Ratio: 2.91394:1
Results: FAIL - These colors do not meet the AAA contrast standards
Try picking a new combination of colors. Would you like to test another set of colors? (y/n): 
y
Enter First Color RGB values (0-255):
R: 255
G: 0
B: 0

Enter Second Color RGB values (0-255):
R: 0
G: 0
B: 255

--- Color Contrast Check ---
Contrast Ratio: 2.14894:1
Results: FAIL - These colors do not meet the AAA contrast standards
Try picking a new combination of colors. Would you like to test another set of colors? (y/n): 
n
```
