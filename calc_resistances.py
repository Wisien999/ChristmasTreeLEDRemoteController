hFE = 230

sourceV = 3.2
#sourceV = 7.5

Ic = 0.2

baseV = 3.1


R1 = sourceV / Ic

Ib = Ic / hFE
R2 = baseV / Ib

print("R1:", R1)
print("Ib:", Ib)
print("R2:", R2)
