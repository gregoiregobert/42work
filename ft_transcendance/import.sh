#!/bin/bash

mv "snapface" "old_snapface"

if [ $? -ne 0 ]; then
	echo "error on mv"
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

my_suppr()
{
	while :; do
		echo -n "suppression .\r"
		sleep 1
		echo -n "suppression ..\r"
		sleep 1
		echo -n "suppression ...\r"
		sleep 1
		echo -n "                \r"
	done
}
tput civis
my_copy &

cp -r "/goinfre/ggobert/trans_volume/snapface" "./snapface" 

kill $!
echo -n "           \r"
if [ -d "snapface" ]; then
	my_suppr &
	rm -rf old_snapface
	kill $!
else
	echo "pas de fichier snapface dans le goinfre"
fi
tput cnorm

