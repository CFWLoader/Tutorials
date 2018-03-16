# Get and print current working directory.
# print(getwd())

# Set current working directory.
# setwd("E:/Project/Tutorials/R")

# Get and print current working directory.
# print(getwd())

data <- read.csv("input.csv")

print(is.data.frame(data))
print(ncol(data))
print(nrow(data))

print(data)