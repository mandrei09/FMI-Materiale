#include <bits/stdc++.h>
using namespace std;

//Structura pentru Punct 
struct Punct {
	long long x, y;
};


//Functie care verifica daca un punct este pe o dreapta
bool PeLinie(Punct p1,Punct p2, Punct p)
{
	if (p.x <= max(p1.x, p2.x) && p.x >= min(p1.x, p2.x)
        && (p.y <= max(p1.y, p2.y) && p.y >= min(p1.y, p2.y)))
		    return true;

	return false;
}

//Functie care ne precizeaza orientarea unui punct fata de o dreapta
int Directie(Punct a, Punct b, Punct c)
{
	long long rez = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);

	if (rez == 0) return 0; //Coliniare
	else if (rez < 0) return 2; //Punctul este la stanga
	return 1; //Punctul este la dreapta
}

//Functie care verifica daca 2 drepte se intersecteaza
int Intersecteaza(Punct a,Punct b,Punct c,Punct d)
{
    //Se intersecreaza intr-un punct de pe un segment
    if(Directie(a,b,c)==0)
        return -1;
    if(Directie(a,b,d)==0)
        return -1;
    if(Directie(c,d,a)==0)
        return -1;
    if(Directie(c,d,b)==0)
        return -1;

    //Verificam daca C AB D sau D AB C SI A CD B sau B CD A
    if ((Directie(a,b,c)==1 && Directie(a,b,d)==2) || (Directie(a,b,c)==2 && Directie(a,b,d)==1))
        if((Directie(c,d,a)==1 && Directie(c,d,b)==2) || (Directie(c,d,a)==2 && Directie(c,d,b)==1))
            return 1;
    return 0;
}

string LocatiePunct(Punct poly[], int n, Punct p) {

    //Un poligon are minim 3 laturi
    if (n < 3) {
        return "OUTSIDE\n";
    }

    int i,contor=0;
    Punct M ={10000000,-10000000}; //punctul din care trasam segmente pentru a verifica intersectiile

    //Pentru fiecare punct verificam daca p este pe dreapta poly[i],poly[i+1] si daca este si pe segmentul poly[i],poly[i+1]
    for(i=0;i<n-1;i++)
        if(Intersecteaza(poly[i],poly[i+1],p,M)==-1 && PeLinie(poly[i],poly[i+1],p)==true)
            return "BOUNDARY\n";
    //verificam si ultimul punct
    if(Intersecteaza(poly[n-1],poly[0],p,M)==-1 && PeLinie(poly[n-1],poly[0],p)==true)
        return "BOUNDARY\n";

    //Controrizam numarul de intersectii 
    for(i=0;i<n-1;i++)
        if(Intersecteaza(poly[i],poly[i+1],p,M)==1)
            contor++;
    
    if(Intersecteaza(poly[n-1],poly[0],p,M)==1)
            contor++;
    
    if(contor%2==0)
        return "OUTSIDE\n";
    else
        return "INSIDE\n";
    
}

int main()
{
    int n,m,i;
	Punct poligon[1001];
    cin>>n;
    for (i = 0; i < n; i++)
        cin >> poligon[i].x >> poligon[i].y;
    Punct puncte[1001];
    cin >> m;
    for (i = 0; i < m; i++)
        cin >> puncte[i].x >> puncte[i].y;
	// Function call
    for (i = 0; i < m; i++)
	    cout<<LocatiePunct(poligon, n, puncte[i]);
	return 0;
}