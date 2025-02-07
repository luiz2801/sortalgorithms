import numpy as np
import math as mth


def leftChild(i: int):
    return np.floor(i/2+1)



def rightChild(i: int):
    return np.floor(i/2+2)

def heapfy(A: list, i: int ):
    l = leftChild(i)
    r = rightChild(i)
    