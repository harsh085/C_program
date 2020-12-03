# C program
Design, implement and test a C-program that allows the user to generate a text file containing the first Name, job title and phone number Of the selected employee. use an array Of structure that contains full name, job title and phone number. populate the Structure array with 4 different employees. Ask the user for the name Of the employee that he/she Wishes to copy to a text file. Name the text file With the same name Of the employee.
#
Here's the proper c code for the following question--

Some pre-knowledge about code...

Microsoft has deprecated lots of calls which use buffers to improve code security. However, the solutions they're providing aren't portable. Anyway, you need to place a definition of _CRT_SECURE_NO_WARNINGS before your included header files. For example:

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

1.

char buf[0x100];
snprintf(buf, sizeof(buf), "%s.txt", xyz_string);
FILE *f = fopen(buf, "r");
The above statements are used to insert the textfile name dynamically (as given in official manual of c)...

2.

#include <string.h> is required because it contains strcmp() method used to compare array of char (string)...
