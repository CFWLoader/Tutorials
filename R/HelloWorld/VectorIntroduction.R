# Title     : TODO
# Objective : TODO
# Created by: CFWLoader
# Created on: 2/5/18

# Vector is fundamental data object in R.
# Logical, Integer, Double, Complex, Character and Raw are 6 types of Atomic Vector.

# Sequence only increase 1 integer unit for next element in the sequence.
v <- 3.8 : 11.7

# Last element in this sequence is 10.8
print(v)

# Control step of sequence.
v2 <- seq(3.8, 11.7, by = 0.4)

print(v2)

# Once there is a Character object in the vector, them c() function will
# convert all elements into Character type.
s <- c('apple', 'Green', 5.55, FALSE)

print(s)

# R supports using operator[] to visit element. Index starts from 1.

# Accessing vector elements using position.
t <- c("Sun","Mon","Tue","Wed","Thurs","Fri","Sat")

# Accessing multiple elements with specified indexes.
u <- t[c(2,3,6)]

print(u)

# Accessing multiple elements with TRUE-FALSE.
u <- t[c(TRUE, FALSE, FALSE, FALSE, FALSE, TRUE, FALSE)]

print(u)

# Negative Indexes means the corresponding element will be erased access.
u <- t[c(-2, -5)]

print(u)

# Vectors with different lengths.
v1 <- c(3,8,4,5,0,11)

v2 <- c(4,11)

# V2 becomes c(4,11,4,11,4,11) if v2 to be operated with v1
print(v1 - v2)

# Use sort() to sort elements in a vector.
v <- c(3,8,4,5,0,11, -9, 304)

# Sort the elements of the vector.
sort.result <- sort(v)
print(sort.result)

# Sort the elements in the reverse order.
revsort.result <- sort(v, decreasing = TRUE)
print(revsort.result)

# Sorting character vectors.
v <- c("Red","Blue","yellow","violet")
sort.result <- sort(v)
print(sort.result)

# Sorting character vectors in reverse order.
revsort.result <- sort(v, decreasing = TRUE)
print(revsort.result)