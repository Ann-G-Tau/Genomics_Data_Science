import csv
from operator import itemgetter

file1 = csv.reader(open('merged.stringtie_merged.gtf.tmap'), delimiter='\t')
tmap = []
for row in file1:
    if row[2] != "u" and row[2] != "=":
        tmap.append(row[1])

file2 = csv.reader(open('part2b_file2'), delimiter='"')
CHESS = []
for row in file2:
    CHESS.append(row[1])

count = 0
for i in tmap:
    if i in CHESS:
        count += 1
print(count)

