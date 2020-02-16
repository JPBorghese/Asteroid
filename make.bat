cd bin
del Asteroid.exe
cd ..
cl /Fe"bin/Asteroid" raylib/lib/raylib.lib src/*.c /I raylib/include /I include
move *.obj obj
"bin/Asteroid.exe"
