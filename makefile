args=-lraylib
name=./build/main.out
debug=false

files=$(shell find $(SRC_DIR) -name "*.cpp")

ifeq ($(DEBUG),true)
    CFLAGS += -d
endif

run: $(name)
	$(name)

$(name): $(files)
	clang++ -d -o $@ $(files) $(args)

clean:
	rm -rf $(name)
