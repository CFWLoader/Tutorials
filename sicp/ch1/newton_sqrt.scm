#lang racket

(define (sqrt-iter guess x)
	(if (good-enough? guess x)
		guess
		(sqrt-iter (improve guess x)
			x)))

(define (improve guess x)
	(average guess (/ x guess)))
