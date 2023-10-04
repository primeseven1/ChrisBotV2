Build instructions
==================
- This does assume you already have gcc and g++, and GNU make installed on your system

- Download dpp from here: https://dpp.dev/
- Once you get the files you need, follow the instructions to build it: https://dpp.dev/buildlinux.html, personally I would recommend installing it to a different directory than the default
- After that, copy the contents of the include directory, and paste it into the project root include directory, and then copy and paste the lib directory into the project root lib directory
- In the private directory in the include folder of the project, put a bot_info.h file into it, and put your bot token, and client id as a macro like this:
    - Make sure to add an include guard, either #pragma once or ifndef
    - #define TOKEN "Your token here"
    - #define CLIENT_ID "Your client ID here"
- Then run "make" in project root, and it will build the project
- To build a release build with optimizations, run "make TARGET=release"