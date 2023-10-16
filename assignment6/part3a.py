import csv
f = csv.reader(open('3a'), delimiter='"')
mydict = {}
for row in f:
    if row[3] not in mydict.keys():
        mydict[row[3]] = float(row[-2])
    else:
        if row[-2] > mydict[row[3]]:
            mydict[row[3]] = float(row[-2])

max = 0
for value in mydict.values():
    if value > max:
        max = value
        
print(max)