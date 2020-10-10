#!/bin/bash
if [ -f Makefile ]; then
	make
	./tp1 | grep 'passed$' | cut -d' ' -f4
fi
