var.1 = 1		# variable composite with alpha, digits, '_; and '.', must start with alpha
# variable will be hidded when its name starts with dot

445.5 -> var.1		# -> means right assigment

var.1 <- 48.51

myyyki <- 'ianmdsf'

print(var.1)

print(ls())			# show all variables in context

print(ls(pattern = "ar"))	# search variables with name containing pattern 'ar'

var3 <- c('in', 'out')

print(ls(pattern = "ar3"))

rm(var3)			# remove variables in the context

rm(list = ls())		# work with ls() function

print(ls())