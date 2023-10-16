import csv
f = csv.reader(open('3c'), delimiter='"')
mydict = {}
for row in f:
    if row[1] not in mydict.keys():
        mydict[row[1]] = float(row[-2])
    else:
        mydict[row[1]] += float(row[-2])

count = 0
for value in mydict.values():
    if value > 0:
        count += 1

print(count)