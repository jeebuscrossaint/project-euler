CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -O2

# Find all problem folders
PROBLEM_DIRS := $(wildcard [1-9]*00)

# Find all .cc files in the problem folders
SOURCES := $(foreach dir,$(PROBLEM_DIRS),$(wildcard $(dir)/*.cc))

# Extract problem numbers from the source file names
PROBLEM_NUMS := $(patsubst %.cc,%,$(notdir $(SOURCES)))

# Determine the latest problem (highest number)
LATEST_NUM := $(shell echo "$(PROBLEM_NUMS)" | tr ' ' '\n' | sort -n | tail -1)

# Find the source file for the latest problem
LATEST_SOURCE := $(shell find . -name "$(LATEST_NUM).cc")

# The target name for the latest problem's executable
LATEST_TARGET := $(LATEST_NUM)

.PHONY: all clean run latest list

# Default target: build the latest problem
all: $(LATEST_TARGET)

# Rule to compile the latest problem
$(LATEST_TARGET): $(LATEST_SOURCE)
	@echo "Compiling $< ..."
	$(CXX) $(CXXFLAGS) -o $@ $<

# Run the latest compiled problem
run: $(LATEST_TARGET)
	@echo "Running problem $(LATEST_TARGET) ..."
	@./$(LATEST_TARGET)

# Show the latest detected problem
latest:
	@echo "Latest problem detected: $(LATEST_NUM) ($(LATEST_SOURCE))"

# List all available problem numbers
list:
	@echo "Available problems:"
	@for num in $(sort $(PROBLEM_NUMS)); do \
		echo "  $$num"; \
	done

# Clean up all compiled executables
clean:
	@echo "Cleaning up..."
	@rm -f *.exe
	@echo "Done."