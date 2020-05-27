#!/bin/bash

#cd "$(dirname "$0")" || exit
#cd "${0%/*}" || echo "cannot change dir!"; exit

# if one arg - cd to dir
if [ $# -eq 1 ]
then
    if [ -n "$1" ]
    then
        cd "$1" || echo "cannot change dir!"; exit
    fi
fi

C_FILES=$(find src     -type f -name '*.c' | sed 'N;N;s/\n/ /g' | sed 's/$/ \\\\\\/'| sed '$s/\\\\\\//' | column -t)
H_FILES=$(find include -type f -name '*.h' | sed 'N;N;s/\n/ /g' | sed 's/$/ \\\\\\/'| sed '$s/\\\\\\//' | column -t)

UPDATED=$(sed ':a; /\\$/N; s/\\\n//; ta' Makefile |
sed "s|SRC_FILES = .*\.c$|SRC_FILES = \\\\\n$C_FILES|g" |
sed "s|HEADER_FILES = .*\.h$|HEADER_FILES = \\\\\n$H_FILES|g")

echo "$UPDATED" > Makefile
echo "Done."



