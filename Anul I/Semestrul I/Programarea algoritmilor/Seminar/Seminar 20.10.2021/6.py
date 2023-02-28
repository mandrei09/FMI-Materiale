s=input()
if s==s[::-1]:
    print("Palindrom")
else:
    l=len(s)
    if s[:l//2]==s[l//2:]:
        print("Semipalindrom")
    else:
        print("Nu este nici palindrom, nici semipalindrom")