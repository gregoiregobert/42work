#!/bin/bash

cp -r snapface /goinfre/ggobert/trans_volume

if [$? -ne 0]; then 
	echo "erreur: cp n'a pas fonctionné."
fi