
cd bin
del LinkedList.exe
cd..
cl raylib/lib/raylib.lib src/*.c /I raylib/include /I include
move *.obj obj
move *.exe bin
"bin/LinkedList.exe"
