all: help
c_release:
	gcc counttest.c util.c -o counttest
c_debug:
	gcc counttest.c util.c -o counttest -g
cpp_release:
	g++ counttest.cpp util.c countable.cpp -o counttest
cpp_debug:
	g++ counttest.cpp util.c -o counttest -g
wc_release:
	i586-mingw32msvc-gcc counttest.c util.c -o counttest.exe
wc_debug:
	i586-mingw32msvc-gcc counttest.c util.c -o counttest.exe -g
wcpp_release:
	i586-mingw32msvc-g++ counttest.cpp util.c -o counttest.exe
wcpp_debug:
	i586-mingw32msvc-g++ counttest.cpp util.c -o counttest.exe -g
debug:
	gdb ./counttest
run:
	./counttest
clear:
	rm ./counttest
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
