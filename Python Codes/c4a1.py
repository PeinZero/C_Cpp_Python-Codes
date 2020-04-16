import sqlite3

conn = sqlite3.connect('c4a1.sqlite')
cur = conn.cursor()

cur.execute('DROP TABLE IF EXISTS Counts')
cur.execute('CREATE TABLE Counts (org TEXT, count INTEGER)')

fname = "mbox.txt"
fhand = open(fname)
for line in fhand:
    #if line.startswith('From:') : continue
    if line.find('@'):
        if not line.startswith('From:') : continue
        line = line.rstrip()
        words = line.split()
        email = words[1]
        words2 = email.split('@')
        dname = words2[1]
        cur.execute('SELECT count FROM Counts WHERE org = ?' , (dname,))
        row = cur.fetchone()

        if row == None :
            cur.execute('INSERT INTO Counts(org,count) VALUES (?,1)' , (dname,))
        else:
            cur.execute('UPDATE Counts SET count = count + 1 WHERE org = ?',(dname,))

conn.commit()
cur.close()
