# Navy
Battleship_project

This project is a battleship between two terminals.

The file passed as parameter must contain lines formatted the following way:
LENGTH : FIRST_SQUARE : LAST_SQUARE
where LENGTH is the length of the ship, FIRST_SQUARE and LAST_SQUARE its first and last positions.
In this file, you must have 4 ships (of lengths 2,3,4 and 5).
If the navy file is invalid, the program will consider it as an error.

To use this project you firstly need to compile it with command: make

The first player must use the command as the following: ./navy pos1_file

The program will gives you it PID. So now, the second player must use the command as the following: ./navy [PID given before] pos2_file

After that, if it succed to connect the two terminals, you just have to follow instructions givent by the program.

If you want to launch the existing unit tests, you must use the folling command: make tests_run
To clean them, you must use the following command: make tests_fclean