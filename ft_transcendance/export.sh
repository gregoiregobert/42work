#!/bin/bash

if [ ! -d "/goinfre/ggobert/trans_volume" ]; then
	mkdir /goinfre/ggobert/trans_volume
fi



my_copy()
{
	while :; do
		echo -n "copie .\r"
		sleep 1
		echo -n "copie ..\r"
		sleep 1
		echo -n "copie ...\r"
		sleep 1
		echo -n "           \r"
	done
}

tput civis
my_copy &

cp -r snapface /goinfre/ggobert/trans_volume

kill $!
tput cnorm
