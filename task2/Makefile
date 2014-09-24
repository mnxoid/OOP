all: help
c_release:
	gcc task2.c util.c -o task2
c_debug:
	gcc task2.c util.c -o task2 -g
cpp_release:
	g++ task2.cpp util.c -o task2 
cpp_debug:
	g++ task2.cpp util.c -o task2 -g 
wc_release:
	i586-mingw32msvc-gcc task2.c util.c -o task2.exe
wc_debug:
	i586-mingw32msvc-gcc task2.c util.c -o task2.exe -g
wcpp_release:
	i586-mingw32msvc-g++ task2.cpp util.c -o task2.exe
wcpp_debug:
	i586-mingw32msvc-g++ task2.cpp util.c -o task2.exe -g
debug:
	gdb ./task2
run:
	./task2
clear:
	rm ./task2
commit:
	git commit -a
	git push GL
help:
	@echo "Options:"
	@echo "	c_release"
	@echo "	cpp_release"
	@echo "	c_debug"
	@echo "	cpp_debug"
	@echo "	wc_release"
	@echo "	wc_debug"
	@echo "	wcpp_release"
	@echo "	wcpp_debug"
	@echo "	run"
	@echo "	debug"
	@echo "	clear"
	@echo "	commit"
	@echo "	help"
