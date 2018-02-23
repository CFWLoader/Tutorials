# Title     : TODO
# Objective : TODO
# Created by: CFWLoader
# Created on: 2/26/18

# hist(v,main,xlab,xlim,ylim,breaks,col,border)
# v - vectors of input.
# main - title.
# xlab - label for x axis.
# xlim - range of x axis.
# ylim - range of y axis.
# break - width for bars.

# Create data for the graph.
v <-  c(9,13,21,8,36,22,12,41,31,33,19)

# Give the chart file a name.
png(file = "histogram1.png")

# Create the histogram.
hist(v,xlab = "Weight",col = "green",border = "blue")

# Save the file.
dev.off()