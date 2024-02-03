args=-lraylib
name=./build/main.out
debug=false

files=$(shell find $(SRC_DIR) -name "*.cpp")

ifeq ($(debug),true)
    args += -d
endif

run: $(name)
	$(name)

$(name): $(files)
	clang++ -o $@ $(files) $(args)

clean:
	rm -rf $(name)
