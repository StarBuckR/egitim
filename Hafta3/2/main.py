
def bastanGetir(sayi, indis):
    return int(str(sayi)[:indis])

def sondanGetir(sayi, indis):
    return int(str(sayi)[indis:])

def carpimlari(sayi):
    carpimi = 1
    for rakam in str(sayi):
        carpimi *= int(rakam)
    return carpimi

def zipirMi(sayi):
    for i in range(1,len(str(sayi))):
        #print("bastan : ",bastanGetir(sayi, i))
        #print("sondan : ", sondanGetir(sayi, i))
        if carpimlari(bastanGetir(sayi, i)) == sondanGetir(sayi,i):
            return True
    return False

sinir = int(input("sayi giriniz: "))

for sayi in range(sinir):
    if zipirMi(sayi):
        print(sayi, end=" ")

print("")

