#!/bin/bash
gcc fizzbuzz.s -c && ld -e main fizzbuzz.o && ./a.out