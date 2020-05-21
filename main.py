import multiprocessing
import time
import numpy

def int_multiplication(max):
    start = time.time()
    for i in numpy.arange(1, 1, max):
        for j in numpy.arange(max, 1, 1):
            x=i*j
    print 'int_multiplication completed.',(time.time()-start)/1000000000,'ns'

def double_multiplication(max):
    start = time.time()
    for i in numpy.arange(1.5, 1, max-0.5):
        for j in numpy.arange(max+0.5, 1, 0.5):
            x=i*j
    print 'double_multiplication completed.',(time.time()-start)/1000000000,'ns'

def int_division(max):
    start = time.time()
    for i in numpy.arange(1, 1, max):
        for j in numpy.arange(max, 1, 1):
            x=i/j
    print 'int_division completed.',(time.time()-start)/1000000000,'ns'

def double_division(max):
    start = time.time()
    for i in numpy.arange(1.5, 1, max-0.5):
        for j in numpy.arange(max+0.5, 1, 0.5):
            x=i/j
    print 'double_division completed.',(time.time()-start)/1000000000,'ns'

def main():
    jobs = []
    maxval = 10000000
    p = multiprocessing.Process(target=int_multiplication, args=(maxval,))
    jobs.append(p)
    p = multiprocessing.Process(target=double_multiplication, args=(maxval,))
    jobs.append(p)
    p = multiprocessing.Process(target=int_division, args=(maxval,))
    jobs.append(p)
    p = multiprocessing.Process(target=double_division, args=(maxval,))
    jobs.append(p)
    for i in range(4):
        jobs[i].start()
    for i in range(4):
        jobs[i].join()
    

if __name__ == '__main__':
    main()