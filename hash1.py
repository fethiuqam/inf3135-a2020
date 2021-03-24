import hashlib

compt = 0
base = "Elias de Kelliwic'h "
res = "677518040b2d9c39757588205910bcab"
caracteres = "0123456789abcdef"
c1 = "1" # le caractere a changer
for c2 in caracteres:
    for c3 in caracteres:
        for c4 in caracteres:
            for c5 in caracteres:
                for c6 in caracteres:
                    for c7 in caracteres:
                        for c8 in caracteres:
                            for c9 in caracteres:
                                for c10 in caracteres:
                                    suffixe = c1 + c2 + c3 + c4 + c5 + c6 + c7 + c8 + c9 + c10
                                    compt += 1
                                    h = hashlib.md5((base + suffixe).encode('utf-8'))
                                    print(compt)
                                    if h.hexdigest() == res:
                                        print("crack = ", suffixe)
                                        quit()