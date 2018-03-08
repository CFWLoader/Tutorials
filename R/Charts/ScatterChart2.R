# Title     : TODO
# Objective : TODO
# Created by: Evan
# Created on: 2018/3/8

# Plotting scatter matrix.

# pairs(formula, data)
# formula - a pair of relative variables.
# data - dataset.

# Give the chart file a name.
png(file = "scatterplot_matrices.png")

# Plot the matrices between 4 variables giving 12 plots.

# One variable with 3 others and total 4 variables.

# pairs(~wt+mpg+disp+cyl,data = mtcars, main = "Scatterplot Matrix")
pairs(wt~mpg, data = mtcars, main = "wt~mpg")

# Save the file.
dev.off()