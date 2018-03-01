# Title     : TODO
# Objective : TODO
# Created by: Evan
# Created on: 2018/3/1

# plot(v,type,col,xlab,ylab)

# v - data vector.
# type - p: point only, l: line only, o: both point and line.
# xlab - label for x axis.
# ylab - label for y axis.
# main - title for chart.
# col - color for point and line.

# Create the data for the chart.
v <- c(7,12,28,3,41)

# Give the chart file a name.
png(file = "line_chart1.jpg")

# Plot the bar chart.
plot(v,type = "o")

# Save the file.
dev.off()