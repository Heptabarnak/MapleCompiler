#!/usr/bin/env bash

cd "${0%/*}"

EXE="$1/MapleCompiler"

echo "Exe path: $EXE"

# We test everything in PresentationTests & ValidPrograms

for filename in ValidPrograms/*.c; do
    "$EXE" "$filename" -c
done


for filename in PresentationTests/*.c; do
    "$EXE" "$filename" -c
done

exit 0