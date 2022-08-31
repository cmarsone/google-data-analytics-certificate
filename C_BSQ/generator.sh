#!/bin/bash
rm -rf maps
mkdir maps
for i in `seq 1 100`;
do
        ./generator.perl 100 100 2 > maps/$i
done