all: help
c_release:
	gcc task1.c util.c -o task1
c_debug:
	gcc task1.c util.c -o task1 -g
cpp_release:
	g++ task1.cpp util.c -o task1
cpp_debug:
	g++ task1.cpp util.c -o task1 -g
wc_release:
	i586-mingw32msvc-gcc task1.c util.c -o task1.exe
wc_debug:
	i586-mingw32msvc-gcc task1.c util.c -o task1.exe -g
wcpp_release:
	i586-mingw32msvc-g++ task1.cpp util.c -o task1.exe
wcpp_debug:
	i586-mingw32msvc-g++ task1.cpp util.c -o task1.exe -g
debug:
	gdb ./task1
run:
	./task1
clear:
	rm ./task1
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