#!/bin/bash

ch1=$1"hg"
ch2=$2"hg"

printf "\nedit distance $1 $2\t\t:" 
./edp $1 $2

printf "\nEdit distance changed  $ch1 $ch2\t:"
./edp $ch1 $ch2

printf "\nSherlock $1 $2\t\t\t:"
./sherlock $1 $2

printf "\nSherlock changed $ch1 $ch2\t:"
./sherlock $ch1 $ch2
