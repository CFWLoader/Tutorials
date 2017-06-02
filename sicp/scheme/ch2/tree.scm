#lang racket

(define (scale-tree tree factor)
	(cond ( (null? tree) null)
			((not (pair? tree)) (* tree factor))
			(else (cons (scale-tree (car tree) factor)
						(scale-tree (cdr tree) factor)))))

(define (scale-tree-m tree factor)
	(map (lambda (sub-tree)
			(if (pair? sub-tree)
				(scale-tree-m sub-tree factor)
				(* sub-tree factor)))
	tree))

(scale-tree (list 1 (list 2 (list 3 4) 5) (list 6 7)) 10)

(scale-tree-m (list 1 (list 2 (list 3 4) 5) (list 6 7)) 10)