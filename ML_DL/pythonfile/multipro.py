import multiprocessing as mp
def job(x):
    return x*x

def multicore():
    pool=mp.Pool()
    res=pool.map(job,range(10))
    print(res)
    print(type(res))

if __name__=="__main__":
    multicore()

    
