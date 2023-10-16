import csv
f = csv.reader(open('3b'), delimiter='"')
mydict = {}
for row in f:
    if row[3] not in mydict.keys():
        mydict[row[3]] = float(row[-2])
    else:
        mydict[row[3]] += float(row[-2])

count = 0
for value in mydict.values():
    if value > 0:
        count += 1
        
print(count)