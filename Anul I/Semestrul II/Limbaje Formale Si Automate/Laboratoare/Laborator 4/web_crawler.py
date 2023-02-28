import requests
import re
import os

try:
    import requests
except ImportError:
    os.system('cmd /c "pip install requests"')
    import requests

site = 'https://www.olx.ro'
category = '/locuri-de-munca'
offers = '/oferta/loc-de-munca'

number_of_pages = 1
# CATEGORIES : 
# 1. sofer - sofer, curier, 'tractorist'
# 2. constructie - zidar, tamplar, stivuitorist, 'buldoexcavatorist', 'macaragiu', 'lucrator', 'muncitor(i)"
# 3. meserii tehnice - 'electrician', 'mecanic', 'sudor(i)', 'lacatus', 'tehnician', 'montator'
# 4. delivery - livrator(i), 'postas', 'distribuitor', 'manipulanti marfa', 'descarcator'
# 5. make-up & beauty - 'coafeza', 'manichiurista', 'pedichiurista',
# 6. food & drinks - 'pizzer', "bucatar", 'barman', 'ospatar', 'macelar',
# 7. sanitary - 'menajera', 'ingrijitor', 'infirmiera', 'hostess'
# 8. social - 'operator', 'casier/a', "agent", 'dispecer', 'vanzatoare', 'lucrator comercial','receptioner'
# 9. kids - 'bona', 'educator / educatoare', 
# 10. desk jobs - 'contabil', 'consilier', 'croitor', 'inspector', 'translator', 'operator'

# RegEX:
regex = {
    'driver': r'(soferi?|curieri?|tractoristi?)',
    'constructions': r'(zidari?|tamplari?|stivuitoristi?|buldoexcavatoristi?|macaragi(u|i)|lucratori?|muncitori?)',
    'tech': r'(electici(an|eni)|mecanici?|sudori?|lacatusi?|tehnici(an|eni)|montatori?)',
    'delivery': r'(livratori?|posta(s|rita)?|distribuito(ri?|are)|manipulanti?|descarcato(ri?|oare))',
    'cosmetics': r'(coafez(a|e)?|manichiurist(a|e)?|pedichiurist(a|e)?)',
    'food': r'(pizzeri?|bucatar(i|e(se|asa))|barmani?|ospatar(i|e(se|asa))|macelar(i|e(se|asa)))',
    'sanitary': r'(menajer(a|e|i)?|ingrijito(ri?|are)|infirmier(a|e|i)?|hostess(a|es?))',
    'social': r'(operato(ri?|are)|casier(a|e|i)?|agent(a|e|i)?|dispecer(a|e|i)?|vanzato(ri?|are)|lucrato(ri?|are) comercial(i|a)?|receptioner(i|a|e)?)',
    'kids': r'(bon(a|e)|educato(ri?|are))',
    'desk': r'(contabil(a|e|i)?|consilier(a|e|i)?|croitor(i|e(asa|se))?|inspecto(ri?|are)|translator(a|e|i)?|operato(ri?|are))'
}

'''
    keys = {
    # driver = []
    # constructions = []
    ...
    *will add links later
} 
'''
keys = {key: [] for key in regex.keys()}

while True:
    if number_of_pages == 1:
        url = site + category
    else: 
        url = site + category + f'/?page={number_of_pages}'
    current_page = requests.get(url, allow_redirects = False)

    # looking for sites having the href type and a 10-letters/digits code at the end
    pattern = re.compile(r'href=\"(.*\.html\#[a-z0-9]{1,10})\"')
    response = requests.get(url, allow_redirects = False)
    if response.text == "":
        break

    patterns = pattern.findall(response.text)
    # adding links in a list
    for p in patterns:
        # links sort
        for key in keys.keys():
            if re.search(regex[key], p):
                keys[key].append(p)
                break

    print(f"current page: {number_of_pages}")

    number_of_pages = number_of_pages+1

category_number = 1

file = open('output.html', 'w')

file.write('''
    <!DOCTYPE html>
        <head>
            <h1> <b> OLX - Locuri de munca </b> </h1>
        </head>

        <body>
    ''')

for key in keys.keys():
    file.write(f"<br><br><h2><i> {category_number}. {key} </i></h2> <br>")
    for link in keys[key]:
        file.write(f"<a href={link}> {link} </a> <br>")
    category_number += 1

file.write('''
            <footer>
                <br>
                <hr>
                    <sub>
                        This project was made by: <br>
                                - Filimon Ioana-Andreea <br>
                                - Popescu Mihaela-Maria <br>
                                - Mihai Andrei-Alexandru <br>
                        <center> <i> University of Bucharest - Faculty of Mathematics and Informatics </i> -<b> Course CS112 </b> </center>
                    </sub>
            </footer>

        </body>
    </html>
    ''')
file.close()

os.system('cmd /c "output.html"')