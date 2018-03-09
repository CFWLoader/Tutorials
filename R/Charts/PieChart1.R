# Title     : TODO
# Objective : TODO
# Created by: Evan
# Created on: 2018/3/9

# pie(x, labels, radius, main, col, clockwise)
# x - data vector.
# labels - labels for each slices.
# radius - radius of pie.
# main - title of plot.
# col - colors for each slices.
# clockwise - clockwise or anticlockwise.

# Create data for the graph.
x <- c(21, 62, 10, 53)
labels <- c("London", "New York", "Singapore", "Mumbai")

# Give the chart file a name.
png(file = "pie1_city.jpg")

# Plot the chart.
pie(x,labels)

# Save the file.
dev.off()