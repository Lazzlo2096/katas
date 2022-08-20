# https://www.codewars.com/kata/52b7ed099cdc285c300001cd/train/python

def sum_of_intervals(intervals):
    
    new_intervals = []
    
    for i in intervals :
        for j in intervals :
            if ( i[0] <= j[0] and j[0] <= i[1] )
                new_intervals.append( (i[0], j[1]) ) # joing
                
    for i in new_intervals :       
        i[1] - i[0]
