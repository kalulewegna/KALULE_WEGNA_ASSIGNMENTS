# Rectangle Assignment

This program creates a Rectangle class that stores a width and a length. It can work out the area and the perimeter of the rectangle.

## How the class is put together

The class has two private data members, width and length. They are private, which means code outside the class cannot read or change them directly. That is the whole point of encapsulation.

Inside the class there are two private getter functions, getWidth and getLength. They are private because only the class itself needs them. Outside code cannot call them.

There are also two public setters, setWidth and setLength. These are the only way for outside code to change the dimensions. Each one takes a double and stores it.

There is a default constructor that sets both width and length to 0.0. That way a Rectangle object is never left with uninitialised values.

Finally there are two public functions that do the actual math, getArea and getPerimeter. They do not touch width and length directly. Instead they call the private getters. This keeps the calculation in one place and follows the design the assignment asked for.

## Why the getters are private

The assignment says width and length should be reached only through methods. By making the getters private, the class is saying these values are ours, and only our own functions get to look at them.

The public things (setters, getArea, getPerimeter) are the only parts outside code can call. That is what the assignment is testing.

## What main does

main creates one Rectangle. It uses the setters to give it a width of 5.5 and a length of 10.0. Then it calls getArea and getPerimeter and prints the results.

## Running it

Compile with g++:

g++ rectangle.cpp -o rectangle

Then run it:

./rectangle

Output:

Rectangle Dimensions: 5.5 x 10.0
Area: 55
Perimeter: 31
