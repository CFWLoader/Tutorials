#lang racket

(define (square x) (* x x))

(define (sum-odd-squares tree)
	(cond 	((null? tree) 0)
			((not (pair? tree))
				(if (odd? tree) (square tree) 0))
			(else (+ 	(sum-odd-squares (car tree))
						(sum-odd-squares (cdr tree))))))

;(define (even-fibs n)
;	(define (next k)
;		(if (> k n)
;			nil
;			(let ((f (fib k)))
;				(if (even? f)
;					(cons f (next (+ k 1)))
;					(next (+ k 1)))))))

(define (filter predicate sequence)
	(cond 	((null? sequence) null)
			((predicate (car sequence))
				(cons (car sequence) (filter predicate (cdr sequence))))
			(else (filter predicate (cdr sequence)))))

(map square (list 1 2 3 4 5))

(filter odd? (list 1 2 3 4 5))