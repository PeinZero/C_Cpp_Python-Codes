text = "X-DSPAM-Confidence:    0.8475"
pos = text.find("0")
pos2 = text.find("5")
num = float (text[pos:pos2+1])
print(num)
