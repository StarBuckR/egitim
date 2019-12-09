
def collatz(sayi):
    print(sayi, end=" ")
    if sayi==1 or sayi==0:
        return 0;
    elif sayi%2==0:
        return collatz(int(sayi/2))
    else:
        return collatz(sayi*3+1)
    
gelen = int(input("bir sayı gir"))
collatz(gelen)