v1 <- c(2, 3.555555, 676)

v2 <- c(8, 54, 879)

# Arithmetic Operations

# Plus each corresponding items in vectors.
print(v1 + v2)

# Minus
print(v2 - v1)

# Multiply
print(v1 * v2)

# Division
print(v2 / v1)

# Modulo
print(v2 %% v1)

# Division for Integer part
print(v2 %/% v1)

# Each items in v2 will be exponent of corresponding item in v1
print(v2 ^ v1)

# Relational Operations

v1 <- c(2, 3.555555, 676, 3)

v2 <- c(8, 54, 879, 3)

# Examine "Greater" relationship for each items in vectors.
print(v1 > v2)

# "Less" relationship
print(v1 < v2)

# "Equal" relationship
print(v1 == v2)

# "Not-Equal" relationship
print(v1 != v2)

# Logical Relationship
# And <- &, or <- |, not <- !
# All not False or not Zero will be true

print(v1 & v2)

print(v1 | v2)

print(!v1)

# && and || only compute first item in vectors

print(v1 && v2)

print(v1 || v2)

# Assignment
# <- and <<- mean =, called left assignment
# -> and ->> mean =, called right assignment

# Other operators

# Create sequence
6:10 ->> seq1

print(seq1)

# Check if item is in vector or not.
print(30 %in% seq1)

print(7 %in% seq1)

# Matrix Multiply
mat1 = matrix(c(1,2,3,4,5,6), nrow = 2, ncol = 3, byrow <- TRUE)

mat2 = matrix(c(6,5,4,3,2,1), nrow = 3, ncol = 2, byrow <- TRUE)

print(mat1 %*% mat2)