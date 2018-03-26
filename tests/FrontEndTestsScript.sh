#!/bin/bash

for filename in ValidPrograms/*.c; do
    ../cmake-build-debug/MapleCompiler "$filename" 2> "Logs/$(basename "$filename" .txt)_Log$i.txt"
done

for filename in SemanticError/*.c; do
    ../cmake-build-debug/MapleCompiler "$filename" 2> "Logs/$(basename "$filename" .txt)_Log$i.txt"
done

for filename in SyntaxError/*.c; do
    ../cmake-build-debug/MapleCompiler "$filename" 2> "Logs/$(basename "$filename" .txt)_Log$i.txt"
done

for filename in LexError/*.c; do
    ../cmake-build-debug/MapleCompiler "$filename" 2> "Logs/$(basename "$filename" .txt)_Log$i.txt"
done


# Delete all logs that don't have output
find ./ -size  0 -print0 |xargs -0 rm