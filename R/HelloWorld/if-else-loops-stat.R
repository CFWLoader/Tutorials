# Title     : TODO
# Objective : TODO
# Created by: CFWLoader
# Created on: 2/3/18

# if-else
var.3 <- FALSE

if (var.3)
{
    print("var.3 == TRUE")
} else # "else" must follow right brace
{
    print("var.3 == FALSE")
}

# switch
# Only support integer and match cases by integer
x <- switch(
2,
"first",
"second",
"third",
"fourth"
)
print(x)

# Repeat
v <- c("Hello", "loop")
cnt <- 2

repeat
{
    print(v[cnt %% 2 + 1])

    cnt <- cnt + 1

    if (cnt > 5) {
        break
    }
}

# While
print("While Loop Region")
v <- c("Hello", "while loop")

cnt <- 2

while (cnt < 7)
{
    print(v[cnt %% 2 + 1])

    cnt = cnt + 1
}

# For, can be used for iteratable objects
print("For Loop Region")

v <- LETTERS[1 : 4]

for (i in v)
{
    if(i == 'D')next           # next is equivalent to continue in C/C++

    print(i)
}