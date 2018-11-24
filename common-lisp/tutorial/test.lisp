#!/usr/bin/sbcl --script
(princ "hoge")
(loop for item in '(this list will get printed in titlecase) do
(format t "~@(~A~) " item))
(princ (apply #'+ 1 2 3 4 '(5 6)))
