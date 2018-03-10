# Title     : TODO
# Objective : TODO
# Created by: Evan
# Created on: 2018/3/10

# Create data for the graph.
x <-  c(21, 62, 10,53)
labels <-  c("London","New York","Singapore","Mumbai")

piepercent<- round(100*x/sum(x), 1)

# Give the chart file a name.
png(file = "pie3_city_percentage_legends.jpg")

# Plot the chart.
# Create a pie chart and use percentage as labels.
pie(x, labels = piepercent, main = "City pie chart",col = rainbow(length(x)))

# Then add a legend at topright.
legend("topright", labels, cex = 0.8, fill = rainbow(length(x)))

# Save the file.
dev.off()