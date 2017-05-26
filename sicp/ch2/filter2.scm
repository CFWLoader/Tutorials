#lang racket

(define (fib n)
	(fib-iter 1 0 n))

(define (fib-iter a b count)
	(if (= count 0)
		b
		(fib-iter (+ a b) a (- count 1))))

(define (square x) (* x x))

(define (enumerate-tree tree)
	(cond 	((null? tree) null)
			((not (pair? tree)) (list tree))
			(else (append 	(enumerate-tree (car tree))
							(enumerate-tree (cdr tree))))))

(define (enumerate-interval low high)
	(if (> low high)
		null
		(cons low (enumerate-interval (+ low 1) high))))

(define (accumulate op initial sequence)
	(if (null? sequence) initial
		(op (car sequence) (accumulate op initial (cdr sequence)))))

(define (sum-odd-squares tree)
	(accumulate +
				0
				(map 	square
						(filter odd?
							(enumerate-tree tree)))))

(define (even-fibs n)
	(accumulate cons
				null
				(filter even?
						(map fib
							(enumerate-interval 0 n)))))

(define (list-fib-squares n)
	(accumulate cons 
				null
				(map square
					(map fib
						(enumerate-interval 0 n)))))

(define (product-of-squares-of-odd-elements sequence)
	(accumulate *
				1
				(map square
					(filter odd? sequence))))

(list-fib-squares 10)

(product-of-squares-of-odd-elements (list 1 2 3 4 5))