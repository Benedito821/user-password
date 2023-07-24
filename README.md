# user-password
  user-password is a PC application that simulates a database using dynamic memory allocation. The project is compound of 4 modules:
command_handle: it is basically a parser that gets the input commands and call the respective routines.
resource_control: allocates memory when adding a new user structure and reallocates it when deleting a user. It also generates a unique ID 
for the user and determine the size of que database.
input: allocates mamory for the user's name and password, as well as masking the password while the user types it in.
output: outputs system feedback messages on the screen. 

  The executable can be found at bin > Debug > user_password.exe or even building and running the code. User data are: name and password. After 
  typing in a unique ID is assigned to the user. Maximal size of the database: as bigger as how much memory is available. After closing the terminal
  all the data is losen. The code can be further improved according the needs (save the user data in a text file, for instance). Last edited time 2018.
  It was writen and built in codeblocks, but the scr and inc files can be imported to any other IDEs.


# user-password terminal demo

![](https://github.com/Benedito821/user-password/blob/master/user_psw_.gif)
