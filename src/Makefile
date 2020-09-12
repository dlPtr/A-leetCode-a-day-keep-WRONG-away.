# run this to make latest cpp
SHELL=/bin/bash
CC=g++
TAR=$(shell ls ${t})
PREFIX=$(shell sh ../scripts/util_get_filename_prefix.sh $(TAR))

.PHONY: run clean
run:
	@echo "We will compile this guy ${TAR}."
	@$(CC) "$(TAR)" -o $(PREFIX)
clean:
	@rm -f $(PREFIX)