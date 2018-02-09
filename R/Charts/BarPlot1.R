# Title     : TODO
# Objective : TODO
# Created by: CFWLoader
# Created on: 2/9/18

# barplot(H, xlab, ylab, main, names.arg, col)
# H - input vector or matrix.
# xlab - label of x-axis.
# ylab - label of y-axis.
# main - title of this plot.
# names.arg - name vector of each bar title.
# col - colors for each bars.

# Create the data for the chart.
H <- c(7,12,28,3,41)

# Give the chart file a name.
png(file = "barchart1.png")

# Plot the bar chart.
barplot(H)

# Save the file.
dev.off()