# Created 2022-03-27

src := $(wildcard *.cc */*.cc)
obj := $(patsubst %.cc, %.o, $(src))
lib := 
flags := -std=c++17 -Wall -Wextra -Wshadow -pedantic -fno-diagnostics-show-caret -O3 # -g3 -fsanitize=leak
out := wordle
c++ := g++
rm := rm

all: $(obj)
	$(c++) $(obj) -o $(out) $(lib) $(flags)

$(obj): %.o : %.cc
	$(c++) -c $(patsubst %.o, %.cc, $@) -o $@ $(flags)

clean:
	$(rm) -f $(obj)
