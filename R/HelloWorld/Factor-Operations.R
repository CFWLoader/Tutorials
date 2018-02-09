# Title     : TODO
# Objective : TODO
# Created by: CFWLoader
# Created on: 2/9/18

# Factor type can store integer and string data.
# Most important is that, Factor provides basic statistic for this data.

# Create a vector as input.
data <- c("East","West","East","North","North","East","West","West","West","East","North")

print(data)

print(is.factor(data))

# Apply the factor function.
factor_data <- factor(data)

print(factor_data)

print(is.factor(factor_data))

# Apply the factor function with required order of the level.
new_order_data <- factor(factor_data,levels = c("East","West","North"))

print(new_order_data)


# Create the vectors for data frame.
# Once column has only text type data, this column will be set as Factor type.
height <- c(132,151,162,139,166,147,122)
weight <- c(48,49,66,53,67,52,40)
gender <- c("male","male","female","female","male","female","male")

# Create the data frame.
input_data <- data.frame(height,weight,gender)

print(input_data)

# Test if the gender column is a factor.
print(is.factor(input_data$gender))

# Print the gender column so see the levels.
print(input_data$gender)

# gl(n, k, labels)
# n - number of levels, k - create k elements for each level, labels - label for levels.
v <- gl(3, 4, labels = c("Tampa", "Seattle","Boston"))

print(v)