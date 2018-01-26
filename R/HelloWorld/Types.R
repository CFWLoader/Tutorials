val <- TRUE		# Logical class(TRUE/FALSE)

print(class(val))

val <- 2.35		# Numeric class

print(class(val))

val <- 40+32i	# Complex class

print(class(val))

val <- 'chtype'	# double quotation marks also work

print(class(val))

val <- charToRaw('Hello')	# raw class

print(class(val))

vec <- c('ele1', 'ele2', 'ele3')	# vector class, using c() function

print(vec)

print(class(vec))

print(vec[1])				# Notice index starts from 1, not 0

list1 <- list(c(2,5,3.44444), 21.3, sin)	# list class, allow mutli classes
# sin() is a function object.

print(list1)

print(class(list1))

# matrix class
mat <- matrix(c(1,2,3,4,5,6), nrow <- 2, ncol <- 3, byrow <- TRUE)	
# mat = matrix(c(1,2,3,4,5,6), nrow = 2, ncol = 3, byrow = TRUE)

print(mat)

print(class(mat))

print(mat[1, 2])		# visit element with index (1,2)

# array class
a <- array(c('green', 'yellow'), dim <- c(3, 3, 2)) # this array has 2 elements, every element is a 3*3 matrix.

print(a)

print(class(a))

print(a[2, 2, 1])		# visit element with index (2,2) in 1st matrix

# factor
# It can be used for statistic
factor_obj <- factor(c('ele1', 'ele1', 'ele2', 'ele2', 'ele3', 'ele3', 'ele1'))

print(factor_obj)

print(class(factor_obj))

print(nlevels(factor_obj))		# Sum different element values

# data frame, like a data table, every parameter is a vector and becomes column in data frame
BMI <- data.frame(
	gender = c('Male', 'Male', 'Female'),
	height = c(152, 171.5, 165),
	weight = c(81, 93, 78),
	age = c(42, 38, 26)
	)

print(BMI)

print(class(BMI))