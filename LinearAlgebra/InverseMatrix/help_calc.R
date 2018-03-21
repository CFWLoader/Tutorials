library(MASS)

matrix.det <- function(mat)
{
    if(nrow(mat) != ncol(mat))
    {
        return(NULL)
    }

    len = nrow(mat)

    det.val = 0

    for(col in c(1:len))
    {
        dr_sum = 1              # sum value for down right direction

        tr_sum = 1              # sum value for top right direction

        dr_col = col            # heading down right direction.

        tr_col = col            # heading top right direction.

        tr_inverse_sum = 0

        tr_col_inverse_count = 0

        for(row in c(1:len))
        {
            dr_sum = dr_sum * mat[row, dr_col]

            tr_sum = tr_sum * mat[row, tr_col]

            tr_inverse_sum = tr_inverse_sum + tr_col_inverse_count

            tr_col_inverse_count = tr_col_inverse_count + 1

            dr_col = dr_col + 1

            if(dr_col > len)
            {
                dr_col = 1
            }

            tr_col = tr_col - 1

            if(tr_col < 1)
            {
                tr_col = len

                tr_col_inverse_count = 0
            }
        }

        dr_inverse_sum = (col - 1) * (len + 1 - col)

        # print(paste("C=", col, "DRIS=", dr_inverse_sum, "TRIS=", tr_inverse_sum))

        if(dr_inverse_sum %% 2 == 1)
        {
            det.val = det.val - dr_sum
        }
        else 
        {
            det.val = det.val + dr_sum
        }

        if(tr_inverse_sum %% 2 == 1)
        {
            det.val = det.val - tr_sum
        }
        else 
        {
            det.val = det.val + tr_sum
        }

        # print(det.val)
    }

    return(det.val)
}

# the_mat = matrix(c(1,2,3,4), nrow = 2)

# print(ginv(the_mat))

# the_mat = matrix(c(1:4), nrow = 2)
tlen = 20

the_mat = matrix(runif(tlen ** 2), nrow = tlen)

print(det(the_mat))

print(matrix.det(the_mat))

# print(1*5*9 + 2*6*7 + 3*4*8 - 7*5*3 - 8*6*1 - 9*4*2)