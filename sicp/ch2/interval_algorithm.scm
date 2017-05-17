#lang racket

(define (max-val a b)
	(if (> a b)
		a
		b))

(define (min-val a b)
	(if (< a b)
		a
		b))

(define (make-interval a b) (cons a b))

(define (low-bound x) (car x))

(define (high-bound x) (cdr x))

(define (display-interval x)
	(display (low-bound x))
	(display "-")
	(display (high-bound x))
	(newline)
)

(define (add-interval x y)
	(make-interval 	(+ (low-bound x) (low-bound y))
					(+ (high-bound x) (high-bound y)))
)

(define (sub-interval x y)
	(let 	( 	(low-b-val (- (low-bound x) (low-bound y)))
				(high-b-val (- (high-bound x) (high-bound y))))
		(make-interval 	(min-val low-b-val high-b-val)
						(max-val low-b-val high-b-val))
	)
)

(define (mul-interval x y)
	(let ( 	(p1 (* (low-bound x) (low-bound y)))
			(p2 (* (low-bound x) (high-bound y)))
			(p3 (* (high-bound x) (high-bound y)))
			(p4 (* (high-bound x) (high-bound y))))
	(make-interval 	(min p1 p2 p3 p4)
					(max p1 p2 p3 p4))))

(define (div-interval x y)
	(mul-interval x
		(make-interval (/ 1.0 (high-bound y)) (/ 1.0 (low-bound y))))
)

(let ( 	(a (make-interval 3 10))
		(b (make-interval 4 17)))
	(display-interval (div-interval a b))
)