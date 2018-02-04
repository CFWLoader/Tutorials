# Title     : TODO
# Objective : TODO
# Created by: CFWLoader
# Created on: 2/4/18

# Create vector objects.
city <- c("Tampa","Seattle","Hartford","Denver")
state <- c("FL","WA","CT","CO")
zipcode <- c(33602,98104,06161,80294)

# Combine above three vectors into one data frame.
addresses <- cbind(city,state,zipcode)

# Print the data frame.
# print(addresses)

# Create another data frame with similar columns
new.address <- data.frame(
   city = c("Lowry","Charlotte"),
   state = c("CO","FL"),
   zipcode = c("80230","33949"),
   stringsAsFactors = FALSE            # parameters for suggesting building process
)

# Print the data frame.
# print(new.address)

# Combine rows form both the data frames.
all.addresses <- rbind(addresses,new.address)

# Print the result.
# print(all.addresses)

# Load MASS for providing dataset.
# Pima is dataset of diabetes of Pima Indian Women.
library(MASS)

# x be Pima.te dataset, y be Pima.tr dataset.
# Extract bp(blood pressure) and bmi(body mass index) as matching parameters.
# If x.bp == y.bp and x.bmi == y.bmi then single row in x and corresponding row in y will
# be merge into a new row.
merged.Pima <- merge(x = Pima.te, y = Pima.tr,
    by.x = c("bp", "bmi"),
    by.y = c("bp", "bmi")
)
# print(merged.Pima)
# nrow(merged.Pima)

# Ships dataset is also integrated in MASS datasets.
print(ships)

# melt function is in reshape2 package.
library(reshape2)

# Choosing columns "type" and "year" and forming new dataset.
# The left 3 columns will be separately combine with chosen columns to form 3 new sub-dataset
# then form a final dataset will 3 times rows to old dataset.
molten.ships <- melt(ships, id = c("type", "year"))

print(molten.ships)

# Inverse the result of melt().
# acast() will transform data into an vector/matrix/array
# dcast() will convert data into a dataframe
recaseted.ships <- dcast(molten.ships, type+year~variable, sum)

print(recaseted.ships)