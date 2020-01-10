# run this to make latest cpp
SHELL=/bin/bash
CC=g++
TAR=$(shell lc_get_latest_filename.sh)
PREFIX=$(shell util_get_filename_prefix.sh $(TAR))

.PHONY: run clean
run:
	@echo "Newest file is < ${TAR} >, We will compile this guy."
	@$(CC) "$(TAR)" -o $(PREFIX)
clean:
	@rm -f $(PREFIX)