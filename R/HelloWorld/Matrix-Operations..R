# Title     : TODO
# Objective : TODO
# Created by: Evan
# Created on: 2018/2/6

# Create a matrix by
# matrix(data, nrow, ncol, byrow, dimnames)
# nrow - number of rows; ncol - number of columns; byrow - (T/F) arrange element by row; dimnames - names of dimensions.

# Elements are arranged sequentially by row.
M <- matrix(c(3:18), nrow = 4, byrow = TRUE)

print(M)

# Elements are arranged sequentially by column.
N <- matrix(c(3:14), nrow = 4, byrow = FALSE)

print(N)

# Define the column and row names.
rownames = c("row1", "row2", "row3", "row4")

colnames = c("col1", "col2", "col3")

P <- matrix(c(3:14), nrow = 4, byrow = TRUE, dimnames = list(rownames, colnames))

print(P)

# Access the element at 3rd column and 1st row.
print(P[1,3])

# Access the element at 2nd column and 4th row.
print(P[4,2])

# Access only the  2nd row.
print(P[2,])

# Access only the 3rd column.
print(P[,3])

# +-*/ for matrix.

# Create two 2x3 matrices.
matrix1 <- matrix(c(3, 9, -1, 4, 2, 6), nrow = 2)

print(matrix1)

matrix2 <- matrix(c(5, 2, 0, 9, 3, 4), nrow = 2)

print(matrix2)

# Add the matrices.
result <- matrix1 + matrix2

print(result)

# Subtract the matrices
result <- matrix1 - matrix2

print(result)

# Multiply the matrices.
result <- matrix1 * matrix2

print(result)

# Divide the matrices
result <- matrix1 / matrix2

print(result)