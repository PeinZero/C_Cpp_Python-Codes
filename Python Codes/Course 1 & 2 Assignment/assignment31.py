hrs = float ( input ("Enter Hours:"))
rph = float ( input ("Enter Rate per Hour:"))
if hrs <= 40:
    pay = hrs * rph
elif hrs > 40:
    pay = 40 * rph
    hrs = hrs - 40
    pay = pay + (hrs * (rph * 1.5))
print (pay)
