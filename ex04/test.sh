#!/bin/bash

DIV='################################################################################'

echo $DIV
echo "./ft_sed $1 $2 $3"
echo $DIV
./ft_sed $1 $2 $3

if [[ $? -ne 0 ]]; then
	exit 1
fi

FILENAME=$1
S1=$2
S2=$3

echo $DIV
echo "cat $FILENAME"
echo $DIV
cat $FILENAME

echo $DIV
echo "cat $FILENAME.replace"
echo $DIV
cat $FILENAME.replace
