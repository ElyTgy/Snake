# Snake

A game of Snake implemented using the ncurses library. Some parts of the code are from my past projects.

---
## Expected Behavior
![2021-05-03 13-51-55](https://user-images.githubusercontent.com/57841857/116932457-229ef480-ac17-11eb-9272-d89dfd0cb02a.gif)

## ncurses
[ncurses](https://www.gnu.org/software/ncurses/) is a library that facilitates text-based graphical output in the terminal. This project relies on ncurses for display output.

## Make
This project can be run using make and cmake as well as viusal studio
* Make sure you have installed the curses library
	* linux: Use the command line ```sudo apt install libncurses5-dev``` to install the curses library
	* Windows: Install the [curses library](https://invisible-island.net/ncurses/#downloads). Then link the files [statically](https://www.youtube.com/watch?v=or1dAmUO8k0&t=622s) and [dynamically](https://www.youtube.com/watch?v=pLy69V2F_8M&t=385s).
* Make/cmake
	1. Create a build directory inside the project directory and navigate to it
	2. When building with cmake and make comment out the line ```#include <windows.h>``` in the snake.h file
	3. You can compile your code now, using the command cmake .. && make
* Visual Studio
	* You should be able to run the program as it is in visual studio.

## Gameplay instructions
Dont resize the window! Doing so will break the game.
Use up, down, left, right keys in order to moves around.
Eating each apple makes the snake longer, but be careful to not 
collide with yourself and collect as mant points as possible!!

## File Class Structure
* Game class 
The clas that contains the logic and game loop of the game.
It keeps track score and game state

* Snake class 
It encasulates the behaviors and data associated with snake/player
Snake itself is represented as a list of positions. The class provides functions for accessing the snakes state
and modifying its length

* Score class
Score class is an item that can be collected by the player in order to gain points.
Its position is determined at random

* Scores class
Score class is a container for Score s. It automatically creates more of them once their number 
reached a certain threshold.

* Utils.cpp and Utils.h
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
