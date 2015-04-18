#!/bin/sh

#Notice that the bash grammer:
#If you want to define a variable, the = operator 
# ,variable name and value is successive without space.
#Emphasizing that space can't appear in the line of define clauses.
myvar="Hi there"

echo $myvar

echo "$myvar"

echo '$myvar'

echo \$myvar

echo Enter some text

read myvar

echo '$myvar' now equals $myvar
exit 0
