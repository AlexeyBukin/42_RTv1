#!/bin/bash

VAR="LIB_SDL_COMPILER=CC\=clang LIB_SDL_EXTENSION=.so"

if [ "$1" = "" ]; then
        echo "making..."
        make $VAR
elif  [ "$1" = "all" ]; then
        echo "making all..."
        make $VAR all
elif  [ "$1" = "re" ]; then
        echo "recompiling..."
        make $VAR re
elif  [ "$1" = "lre" ]; then
        echo "local recompiling..."
        make $VAR lre
elif  [ "$1" = "clean" ]; then
        echo "cleaning..."
        make $VAR clean
elif  [ "$1" = "fclean" ]; then
        echo "full cleaning..."
        make $VAR fclean
elif  [ "$1" = "lclean" ]; then
        echo "local cleaning..."
        make $VAR lclean
elif  [ "$1" = "lfclean" ]; then
        echo "local full cleaning..."
        make $VAR lfclean
fi
