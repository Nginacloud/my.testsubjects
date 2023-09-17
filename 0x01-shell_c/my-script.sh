#! /bin/bash
echo $0 $1 $2 $3 '> echo $1 $2 $3'

argc=("$@")
#echo ${argc[0]} ${argc[1]} ${argc[2]} ${argc[3]}
echo $@
echo $#
