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

(define (accumulate op initial sequence)
	(if (null? sequence) initial
		(op (car sequence) (accumulate op initial (cdr sequence)))))

(define (filter predicate sequence)
	(cond 	((null? sequence) null)
			((predicate (car sequence))
				(cons (car sequence) (filter predicate (cdr sequence))))
			(else (filter predicate (cdr sequence)))))

(define (enumerate-interval low high)
	(if (> low high)
		null
		(cons low (enumerate-interval (+ low 1) high))))

(define (enumerate-tree tree)
	(cond 	((null? tree) null)
			((not (pair? tree)) (list tree))
			(else (append 	(enumerate-tree (car tree))
							(enumerate-tree (cdr tree))))))

; (map square (list 1 2 3 4 5))

; (filter odd? (list 1 2 3 4 5))

; (accumulate + 0 (list 1 2 3 4 5))

; (accumulate * 1 (list 1 2 3 4 5))

; (accumulate cons null (list 1 2 3 4 5))

; (enumerate-interval 2 7)

(enumerate-tree (list 1 (list 2 (list 3 4)) 5))