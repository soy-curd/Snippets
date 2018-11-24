#!/usr/bin/env python
# -*- coding: utf-8 -*-

import random

learning_late = 0.01
loop_max = 1000

def main():
    
    initial = random.uniform(-10, 10)
    old = initial
    new = 0.0
    for _ in range(1000):
        
        # 更新式
        new = old - learning_late * diff_func(old)
        
        # 目的関数の値を確認
        y = object_func(new)
        print(y)
        
        # 値を更新
        old = new
        
    print(new, y)
        
    
# 目的関数
def object_func(x):
    return x * x + x
    
# x ^ 2 + 1 の微分
def diff_func(x):
    return 2 * x + 1

if  __name__=='__main__':
    main()
