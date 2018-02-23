# Title     : TODO
# Objective : TODO
# Created by: CFWLoader
# Created on: 2/9/18

# boxplot(x, data, notch, varwidth, names, main)
# x - vector or formula.
# data - data or dataframe.
# notch - TRUE/FALSE value, allowing notch or not.
# varwidth - TRUE/FALSE value, TRUE for scalable frame.
# names - Group label for box charts.
# main - title for Charts.

# Load data input.
input <- mtcars[,c('mpg','cyl')]

# print(mtcars)
print(head(input))

# Give the chart file a name.
png(file = "boxplot1.png")

# Plot the chart.
boxplot(mpg ~ cyl, data = mtcars, xlab = "Number of Cylinders",
   ylab = "Miles Per Gallon", main = "Mileage Data")

# Save the file.
dev.off()