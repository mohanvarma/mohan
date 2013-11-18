Files:
======
hex_board.h    - Contains class declarations
hex_board.cpp  - Contains method definitions and main.

Please rename the copied files as above.

Compiling:
==========
I compiled this program in Linux.
Copy both files to same directory and compile with the following command.
g++ -std=c++11 -o hex

To run the program,

./hex

Approach:
=========
Before proceeding to solve this assignment, I considered different board designs suggested my community TA at this link - https://class.coursera.org/cplusplus4c-002/forum/thread?thread_id=676

I chose the simpler design which represents empty positions as '.'
Board uses capital letters (A,B,C,D..) on the north and south sides, digits (1,2,3,4..) on the east and west sides to identify coordinates of a location.

So, an empty hexboard of size 4x4 looks as follows.

  A B C D         

1 . . . . 1      

 2 . . . . 2      

  3 . . . . 3      

   4 . . . . 4      

     A B C D 

Now, there are 2 players.

BLUE player(or player0) plays in the direction of EAST<->WEST (horizontally).
RED player(or player1) playes in the direction of NORTH<->SOUTH (vertically).

Locations chosen by the BLUE player are represented with 'O'.
Locations chosen by the RED player are represented with 'X'.

Each player has his own graph object with n*n + 2 vertices.
Those additional 2 are invisible virtual vertices, 1 on each playing side.
Each virtual vertex connects to all the vertices on the edge in it's end.

So, initially, these virtual vertices are connected like this(Sorry for this representation but couldn't create a better one for now).
	  
	   v1_RED         
           / | | \
	 1 . . . . 1 \     
       /
	/ 2 . . . . 2 \       
v1_BLUE                  v2_BLUE
	\  3 . . . . 3 /     
        \
	   4 . . . . 4 /    
             \ | | /
	     v2_RED 

As the game proceeds, we add edges to respective graphs if neghbors are already occupied in the board.
We constantly check if a path exists between the corresponding virutal vertices. If yes, that player wins. Otherwise, game continues.

To make things simple, each coordinate is represented by <row><column> manner. And letter should always be a cap letter.
So, 1A is a valid position, but A1 is not.
So please enter this way.

Sample game:
=============
This is the game generated on a 7x7 hexboard using my program.


$ ./hex
Enter HexBoard side length:7

Creating a hexboard of size7 X 7
Blue player(Player 0) direction is EAST<->WEST. Occupied position is shown with O

Red player(Player 1) direction is NORTH<->SOUTH. Occupied position is shown with X

  A B C D E F G               

1 . . . . . . . 1            

 2 . . . . . . . 2            

  3 . . . . . . . 3            

   4 . . . . . . . 4            

    5 . . . . . . . 5            

     6 . . . . . . . 6            

      7 . . . . . . . 7            

        A B C D E F G 


Always enter ROW COLUMN(without space and in capital letters)
So, row would always be a number and column would be a char
Example: 5B is correct, but B5 is wrong
Example: 5B is correct, but 5b is wrong


===================================================================
Game is starting now

===================================================================

Player: Blue(0)is playing
Move number:0
Enter move:2B
Move 2B SUCCESS


  A B C D E F G               

1 . . . . . . . 1            

 2 . O . . . . . 2            

  3 . . . . . . . 3            

   4 . . . . . . . 4            

    5 . . . . . . . 5            

     6 . . . . . . . 6            

      7 . . . . . . . 7            

        A B C D E F G 

Player: Red(1)is playing
Move number:1
Enter move:1C
Move 1C SUCCESS

  A B C D E F G               

1 . . X . . . . 1            

 2 . O . . . . . 2            

  3 . . . . . . . 3            

   4 . . . . . . . 4            

    5 . . . . . . . 5            

     6 . . . . . . . 6            

      7 . . . . . . . 7            

        A B C D E F G 

Player: Blue(0)is playing
Move number:2
Enter move:1A
Move 1A SUCCESS


  A B C D E F G               

1 O . X . . . . 1            

 2 . O . . . . . 2            

  3 . . . . . . . 3            

   4 . . . . . . . 4            

    5 . . . . . . . 5            

     6 . . . . . . . 6            

      7 . . . . . . . 7            

        A B C D E F G 

Player: Red(1)is playing
Move number:3
Enter move:1H
Move 1H ERROR: Invalid 2nd coordinate


  A B C D E F G               

1 O . X . . . . 1            

 2 . O . . . . . 2            

  3 . . . . . . . 3            

   4 . . . . . . . 4            

    5 . . . . . . . 5            

     6 . . . . . . . 6            

      7 . . . . . . . 7            

        A B C D E F G 

Player: Red(1)is playing
Move number:3
Enter move:2C
Move 2C SUCCESS


  A B C D E F G               

1 O . X . . . . 1            

 2 . O X . . . . 2            

  3 . . . . . . . 3            

   4 . . . . . . . 4            

    5 . . . . . . . 5            

     6 . . . . . . . 6            

      7 . . . . . . . 7            

        A B C D E F G 

Player: Blue(0)is playing
Move number:4
Enter move:3B
Move 3B SUCCESS


  A B C D E F G               

1 O . X . . . . 1            

 2 . O X . . . . 2            

  3 . O . . . . . 3            

   4 . . . . . . . 4            

    5 . . . . . . . 5            

     6 . . . . . . . 6            

      7 . . . . . . . 7            

        A B C D E F G 

Player: Red(1)is playing
Move number:5
Enter move:7B
Move 7B SUCCESS


  A B C D E F G               

1 O . X . . . . 1            

 2 . O X . . . . 2            

  3 . O . . . . . 3            

   4 . . . . . . . 4            

    5 . . . . . . . 5            

     6 . . . . . . . 6            

      7 . X . . . . . 7            

        A B C D E F G 

Player: Blue(0)is playing
Move number:6
Enter move:3C
Move 3C SUCCESS


  A B C D E F G               

1 O . X . . . . 1            

 2 . O X . . . . 2            

  3 . O O . . . . 3            

   4 . . . . . . . 4            

    5 . . . . . . . 5            

     6 . . . . . . . 6            

      7 . X . . . . . 7            

        A B C D E F G 

Player: Red(1)is playing
Move number:7
Enter move:6B
Move 6B SUCCESS


  A B C D E F G               

1 O . X . . . . 1            

 2 . O X . . . . 2            

  3 . O O . . . . 3            

   4 . . . . . . . 4            

    5 . . . . . . . 5            

     6 . X . . . . . 6            

      7 . X . . . . . 7            

        A B C D E F G 

Player: Blue(0)is playing
Move number:8
Enter move:3D
Move 3D SUCCESS


  A B C D E F G               

1 O . X . . . . 1            

 2 . O X . . . . 2            

  3 . O O O . . . 3            

   4 . . . . . . . 4            

    5 . . . . . . . 5            

     6 . X . . . . . 6            

      7 . X . . . . . 7            

        A B C D E F G 

Player: Red(1)is playing
Move number:9
Enter move:5B
Move 5B SUCCESS


  A B C D E F G               

1 O . X . . . . 1            

 2 . O X . . . . 2            

  3 . O O O . . . 3            

   4 . . . . . . . 4            

    5 . X . . . . . 5            

     6 . X . . . . . 6            

      7 . X . . . . . 7            

        A B C D E F G 

Player: Blue(0)is playing
Move number:10
Enter move:4D
Move 4D SUCCESS


  A B C D E F G               

1 O . X . . . . 1            

 2 . O X . . . . 2            

  3 . O O O . . . 3            

   4 . . . O . . . 4            

    5 . X . . . . . 5            

     6 . X . . . . . 6            

      7 . X . . . . . 7            

        A B C D E F G 

Player: Red(1)is playing
Move number:11
Enter move:4B
Move 4B SUCCESS


  A B C D E F G               

1 O . X . . . . 1            

 2 . O X . . . . 2            

  3 . O O O . . . 3            

   4 . X . O . . . 4            

    5 . X . . . . . 5            

     6 . X . . . . . 6            

      7 . X . . . . . 7            

        A B C D E F G 

Player: Blue(0)is playing
Move number:12
Enter move:4D
Move 4D ERROR: Already occupied by blue player/ player 0

  A B C D E F G               

1 O . X . . . . 1            

 2 . O X . . . . 2            

  3 . O O O . . . 3            

   4 . X . O . . . 4            

    5 . X . . . . . 5            

     6 . X . . . . . 6            

      7 . X . . . . . 7            

        A B C D E F G 

Player: Blue(0)is playing
Move number:12
Enter move:4E
Move 4E SUCCESS


  A B C D E F G               

1 O . X . . . . 1            

 2 . O X . . . . 2            

  3 . O O O . . . 3            

   4 . X . O O . . 4            

    5 . X . . . . . 5            

     6 . X . . . . . 6            

      7 . X . . . . . 7            

        A B C D E F G 

Player: Red(1)is playing
Move number:13
Enter move:3A
Move 3A SUCCESS


  A B C D E F G               

1 O . X . . . . 1            

 2 . O X . . . . 2            

  3 X O O O . . . 3            

   4 . X . O O . . 4            

    5 . X . . . . . 5            

     6 . X . . . . . 6            

      7 . X . . . . . 7            

        A B C D E F G 

Player: Blue(0)is playing
Move number:14
Enter move:4F
Move 4F SUCCESS


  A B C D E F G               

1 O . X . . . . 1            

 2 . O X . . . . 2            

  3 X O O O . . . 3            

   4 . X . O O O . 4            

    5 . X . . . . . 5            

     6 . X . . . . . 6            

      7 . X . . . . . 7            

        A B C D E F G 

Player: Red(1)is playing
Move number:15
Enter move:2A
Move 2A SUCCESS


  A B C D E F G               

1 O . X . . . . 1            

 2 X O X . . . . 2            

  3 X O O O . . . 3            

   4 . X . O O O . 4            

    5 . X . . . . . 5            

     6 . X . . . . . 6            

      7 . X . . . . . 7            

        A B C D E F G 

Player: Blue(0)is playing
Move number:16
Enter move:4G
Move 4G SUCCESS


  A B C D E F G               

1 O . X . . . . 1            

 2 X O X . . . . 2            

  3 X O O O . . . 3            

   4 . X . O O O O 4            

    5 . X . . . . . 5            

     6 . X . . . . . 6            

      7 . X . . . . . 7            

        A B C D E F G 

Player: Red(1)is playing
Move number:17
Enter move:1B
Move 1B SUCCESS


  A B C D E F G               

1 O X X . . . . 1            

 2 X O X . . . . 2            

  3 X O O O . . . 3            

   4 . X . O O O O 4            

    5 . X . . . . . 5            

     6 . X . . . . . 6            

      7 . X . . . . . 7            

        A B C D E F G 

Player: Blue(0)is playing
Move number:18
Enter move:2D
Move 2D SUCCESS


  A B C D E F G               

1 O X X . . . . 1            

 2 X O X O . . . 2            

  3 X O O O . . . 3            

   4 . X . O O O O 4            

    5 . X . . . . . 5            

     6 . X . . . . . 6            

      7 . X . . . . . 7            

        A B C D E F G 

Player: Red(1)is playing
Move number:19
Enter move:4A
Move 4A SUCCESS


  A B C D E F G               

1 O X X . . . . 1            

 2 X O X O . . . 2            

  3 X O O O . . . 3            

   4 X X . O O O O 4            

    5 . X . . . . . 5            

     6 . X . . . . . 6            

      7 . X . . . . . 7            

        A B C D E F G 


PLAYER RED (Player 1) just won the game

 Exiting the game
 
