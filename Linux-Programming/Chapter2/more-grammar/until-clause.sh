#!/bin/sh

read var

until [ "$var" = "accept" ]; do
	echo Fight for your way!
	read var
done
