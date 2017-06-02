#lang racket

(define (gcd a b)
	(if (= b 0)
		a
		(gcd b (remainder a b))))

(gcd 3 6)

(gcd 10000 10000000)