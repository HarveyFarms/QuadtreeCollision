d:	main.cpp
	g++ main.cpp src/*.cpp src/*.c classes/*.cpp `sdl-config --cflags --libs` -lSDL_image -lSDL_mixer -lSDL_ttf -Iincludes -Iclasses; ./a.out

a asan:	main.cpp
	g++ main.cpp src/*.cpp src/*.c -g -fsanitize=address classes/*.cpp `sdl-config --cflags --libs` -lSDL_image -lSDL_mixer -lSDL_ttf -Iincludes -Iclasses
r:
	./a.out

c:
	rm ./a.out

g:
	git add -A ; git commit -m "sync" ; git push

p:
	git pull
