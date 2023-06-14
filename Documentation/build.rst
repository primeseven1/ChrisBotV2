Build instructions
==================
- This does assume you already have gcc and g++, and GNU make installed on your system

- Download dpp from here: https://dpp.dev/
- Once you get the files you need, put the include stuff in the include directory of the project, and put the lib stuff in the lib directory of the project
- In the private directory in the include folder of the project, put a bot_info.h file into it, and put your bot token, and client id as a macro like this:
    #define TOKEN "Your token here"
    #define CLIENT_ID "Your client ID here"

- After that, just run the makefile, and it should work, if you're on windows, make sure the output variable is a .exe extention in the makefile