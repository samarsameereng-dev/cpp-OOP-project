# cpp-OOP-project
A course project, C++ using OOP principles 
This project is a simple C++ application that simulates a pizza ordering system using object-oriented programming principles, including inheritance and method overriding.

Structure

1. Item Class

Base class representing a general product.
Attributes (private):
Item number
Price
Includes:
Constructors and destructor
Getter and setter methods
Method to display item information

2. Pizza Class (inherits Item)

Represents a specific product type: pizza.
Additional attributes:
Size (M or L)
Topping sauce (YES or NO)
Includes:
Constructors and destructor
Getter and setter methods
Overridden display method to show full pizza details
Program Functionality (main)
Reads data for up to 50 pizzas from user input.
Stores pizzas in an array.
Displays information for all pizzas.
Calculates and displays total order cost, including:
20% VAT applied to the final price
Additional 2.50 BGN (before VAT) for each pizza with topping
Displays only pizzas with size L.
Purpose

The project demonstrates:

Class design and encapsulation
Inheritance and polymorphism
Array processing
Basic pricing logic and VAT calculation
