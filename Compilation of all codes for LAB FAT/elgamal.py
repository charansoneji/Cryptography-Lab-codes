import random
from math import pow
a = random.randint(2, 10)
def powerof(a, b, c):
x = 1
y = a
while b > 0:
if b % 2 == 0:
x = (x * y) % c;
y = (y * y) % c
b = int(b / 2)
return x % c
def gcd(a, b):
if a < b:
return gcd(b, a)
elif a % b == 0:
return b;
else:
return gcd(b, a % b)
def keygen(q):
key = random.randint(pow(10, 20), q)
while gcd(q, key) != 1:
key = random.randint(pow(10, 20), q)
return key
def eMessage(msg, q, h, g):
en_msg = []
k = keygen(q)
s = powerof(h, k, q)
p = powerof(g, k, q)
for i in range(0, len(msg)):
en_msg.append(msg[i])
print("g^k used : ", p)
print("g^ak used : ", s)
for i in range(0, len(en_msg)):
en_msg[i] = s * ord(en_msg[i])
return en_msg, p
def dMessage(en_msg, p, key, q):
dr_msg = []
h = powerof(p, key, q)
for i in range(0, len(en_msg)):
dr_msg.append(chr(int(en_msg[i]/h)))
return dr_msg
def main():
print("Enter message:")
msg=input()
print("Original Message :", msg)
q = random.randint(pow(10, 20), pow(10, 50))
g = random.randint(2, q)
key = keygen(q)
h = powerof(g, key, q)
print("g used : ", g)
print("g^a used : ", h)
en_msg, p = eMessage(msg, q, h, g)
dr_msg = dMessage(en_msg, p, key, q)
dmsg = ''.join(dr_msg)
print("Decrypted Message :", dmsg);
if __name__ == '__main__':
main()
