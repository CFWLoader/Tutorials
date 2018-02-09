# Title     : TODO
# Objective : TODO
# Created by: CFWLoader
# Created on: 2/9/18

# Create the data frame.
emp.data <- data.frame(
   emp_id = c (1:5),
   emp_name = c("Rick","Dan","Michelle","Ryan","Gary"),
   salary = c(623.3,515.2,611.0,729.0,843.25),

   start_date = as.Date(c("2012-01-01", "2013-09-23", "2014-11-15", "2014-05-11",
      "2015-03-27")),
   stringsAsFactors = FALSE
)

# Print the data frame.
print(emp.data)

# Get the structure of the data frame.
str(emp.data)

# Print the summary of data frame.
print(summary(emp.data))

# Extract Specific columns.
result <- data.frame(emp.data$emp_name,emp.data$salary)

print(result)

# Extract first two rows.
result <- emp.data[1:2,]

print(result)

# Add the "dept" coulmn.
emp.data$dept <- c("IT","Operations","IT","HR","Finance")

v <- emp.data

print(v)

# Create the second data frame
emp.newdata <- 	data.frame(
   emp_id = c (6:8),
   emp_name = c("Rasmi","Pranab","Tusar"),
   salary = c(578.0,722.5,632.8),
   start_date = as.Date(c("2013-05-21","2013-07-30","2014-06-17")),
   dept = c("IT","Operations","Fianance"),
   stringsAsFactors = FALSE
)

# Bind the two data frames.
emp.finaldata <- rbind(emp.data,emp.newdata)

print(emp.finaldata)

# print(factor(emp.data$emp_id))