args=-lraylib
name=./build/main.out

files=$(shell find $(SRC_DIR) -name "*.cpp")


run: $(name)
	$(name)

$(name): $(files)
	clang++ -o $@ $(files) $(args)

clean:
	rm -rf $(name)
