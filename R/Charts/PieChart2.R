# Title     : TODO
# Objective : TODO
# Created by: Evan
# Created on: 2018/3/10

# Create data for the graph.
x <- c(21, 62, 10, 53)
labels <- c("London", "New York", "Singapore", "Mumbai")

# Give the chart file a name.
png(file = "pie2_city_title_colours.jpg")

# print(rainbow(4))

# Plot the chart with title and rainbow color pallet.
pie(x, labels, main = "City pie chart", col = rainbow(length(x)))

# Save the file.
dev.off()