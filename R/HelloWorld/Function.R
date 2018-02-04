# Title     : TODO
# Objective : TODO
# Created by: CFWLoader
# Created on: 2/4/18

# Function in R is implemented according to Lazy Evaluation.

# Define new function.
mynew.function <- function(para)
{
    for(i in 1:para)
    {
        print(2^i)
    }
}

# Call it.
mynew.function(3)

# Default parameter value.
mynew.function = function(a = 3, b = 4, c = 5)
{
    print(a^2 + b^2 - c^2)
}

mynew.function()

# Assign parameter in order.
mynew.function(2)

# Assign parameter value by parameter name.
mynew.function(b <- 7)