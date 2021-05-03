# Snake

A game of Snake implemented using the ncurses library. 

This project is a submission for the Udacity C++ Nanodegree program capstone project.

---
## Expected Behavior

add image

## Dependencies for Running Locally
add later

## Basic Build Instructions
add later

## Gameplay instructions

Use up, down, left, right keys in order to moves around.
Eating each apple makes the snake longer, but be careful to not 
collide with yourself and collect as mant points as possible!!

## File Class Structure
*Game class 
The clas that contains the logic and game loop of the game.
It keeps track score and game state

*Snake class 
It encasulates the behaviors and data associated with snake/player
Snake itself is represented as a list of positions. The class provides functions for accessing the snakes state
and modifying its length

*Score class
Score class is an item that can be collected by the player in order to gain points.
Its position is determined at random

*Scores class
Score class is a container for Score s. It automatically creates more of them once their number 
reached a certain threshold.

*Utils.cpp and Utils.h
These files have some common functionality that doesn't belong to any class or is used by most of them.
It also contains the namespace Settings which I created in order to avoid magic numbers and make it easier to 
modify the settings of the game easier.
This file also contains struct Pos, namespace Dir, and namespace State.


## Rubric points addressed

* The project demonstrates an understanding of C++ functions and control structures.
	* Game.cpp line 18
* The project uses Object Oriented Programming techniques.
	* Game.h
* Classes use appropriate access specifiers for class members.
	* Game.h, Snake.h, Scores.h
* The project accepts user input and processes the input.
	* Game.cpp line 106
* Class constructors utilize member initialization lists.
	* Snake.cpp line 8
