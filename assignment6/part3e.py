import csv
from operator import itemgetter

file1 = csv.reader(open('3e_sample1'), delimiter='"')
sample1 = {}
for row in file1:
    if row[1] not in sample1.keys():
        sample1[row[1]] = float(row[-2])
    else:
        sample1[row[1]] += float(row[-2])
res1 = sorted(sample1.items(), key = lambda x:x[1], reverse = True)[:10]
print("SRR47952")
for i in res1:
    print i[0], "\t", i[1]
print

file2 = csv.reader(open('3e_sample2'), delimiter='"')
sample2 = {}
for row in file2:
    if row[1] not in sample2.keys():
        sample2[row[1]] = float(row[-2])
    else:
        sample2[row[1]] += float(row[-2])
res2 = sorted(sample2.items(), key = lambda x:x[1], reverse = True)[:10]
print("SRR47954")
for i in res2:
    print i[0], "\t", i[1]
print
for i in range(10):
    print res1[i][0], "\t", res1[i][1] - res2[i][1]
