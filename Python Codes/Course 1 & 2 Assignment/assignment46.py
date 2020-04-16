def computepay(h,r):
    if h <= 40:
        pay = h * r
    elif h > 40:
        pay = 40 * r
        h = h - 40
        pay = pay + (h * (r * 1.5))
    return pay

hrs = float ( input ("Enter Hours:"))
rph = float ( input ("Enter Rate per Hour:"))
p = computepay(hrs,rph)
print("Pay",p)
