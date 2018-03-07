# Title     : TODO
# Objective : TODO
# Created by: Evan
# Created on: 2018/3/7

# plot(x, y, main, xlab, ylab, xlim, ylim, axes)
# x - vector data for x axis.
# y - vector data for y axis.
# main - title for plot.
# xlab - label for x axis.
# ylab - label for y axis.
# xlim - max value of x axis.
# ylim - max value of y axis.
# axes - display axises or not.

# Extract 'wt' and 'mpg' columns from mtcars dataset.
input <- mtcars[, c('wt', 'mpg')]
# print(head(input))

# Get the input values.
input <- mtcars[, c('wt', 'mpg')]

# Give the chart file a name.
png(file = "scatterplot1.png")

# Plot the chart for cars with weight between 2.5 to 5 and mileage between 15 and 30.
plot(x = input$wt, y = input$mpg,
    xlab = "Weight",
    ylab = "Milage",
    xlim = c(2.5, 5),
    ylim = c(15, 30),
    main = "Weight vs Milage",
    # axes = FALSE
)

# Save the file.
dev.off()