# Title     : TODO
# Objective : TODO
# Created by: CFWLoader
# Created on: 2/4/18

a = "Welcome"
b = "to use"
c = "R language"

# Concate strings into a new string.
print(paste(a, b, c))

print(paste(a, b, c, sep = "-"))

# collapse is used to elimate spaces between strings, not spaces in a single string.
print(paste(a, b, c, sep = "", collapse = ""))

# Total number of digits displayed. Last digit rounded off.
result <- format(23.123456789, digits = 9)
print(result)

# Display numbers in scientific notation.
result <- format(c(6, 13.14521), scientific = TRUE)
print(result)

# The minimum number of digits to the right of the decimal point.
result <- format(23.47, nsmall = 5)
print(result)

# Format treats everything as a string.
result <- format(6)
print(result)

# Numbers are padded with blank in the beginning for width.
result <- format(13.7, width = 6)
print(result)

# Left justify strings.
result <- format("Hello", width = 8, justify = "l")
print(result)

# Justfy string with center.
result <- format("Hello", width = 8, justify = "c")
print(result)

# Count number of characters.
print(nchar("asdnfaiungadg"))

# toupper()
# tolower()
print(substring("aisdnfasinfd", 3, 4))