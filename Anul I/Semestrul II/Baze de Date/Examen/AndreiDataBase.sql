create table CALATORIE (
    calatorie_id integer primary key,
    Destinatie varchar2(20) NOT NULL,
    Durata_zile integer not null,
    Numar_calatori integer,
    Numar_bilete integer,
    Bilet_id integer,
    CONSTRAINT calatorie_fk FOREIGN KEY(bilet_id) REFERENCES BILET(bilet_id)
);

create table NATIONALA(
    calatorie_id integer references CALATORIE(calatorie_id),
    primary key (calatorie_id),
    Opriri integer,
    check (Opriri in (1,0)),
    Destinatie varchar2(20) NOT NULL,
    Durata_zile integer not null,
    Numar_calatori integer,
    Numar_bilete integer,
    CONSTRAINT nationala_fk FOREIGN KEY(calatorie_id) REFERENCES CALATORIE(calatorie_id)
);

create table INTERNATIONALA(
    calatorie_id integer references CALATORIE(calatorie_id),
    primary key (calatorie_id),
    Opriri integer,
    check (Opriri in (1,0)),
    Destinatie varchar2(20) NOT NULL,
    Durata_zile integer not null,
    Numar_calatori integer,
    Numar_bilete integer,
    CONSTRAINT internationala_fk FOREIGN KEY(calatorie_id) REFERENCES CALATORIE(calatorie_id)
);

create table FIRMA(
    firma_id integer primary key,
    Tip_firma varchar2(10) NOT NULL,
    check (Tip_firma in ('Stat','Privat')),
    Ofera_reducere integer
);

create table OPERATOR(
    operator_id integer primary key,
    Nume varchar2(20) not NULL,
    Perioada_contract integer,
    Numar_conturi_acces integer,
    Experienta_ani integer,
    firma_id integer,
    CONSTRAINT operator_fk FOREIGN KEY(firma_id) REFERENCES FIRMA(firma_id)
);

create table CONT(
    cont_id integer primary key,
    Numar_bilete integer default '0',
    Data_creare date not null,
    Username varchar2(20) unique
);

create table CALATOR(
    calator_id integer primary key,
    Nume varchar2(20),
    Varsta integer not null,
    Categorie_varsta_reducere varchar2(20) not null
);

create table CATEGORIE(
    categorie_id integer primary key,
    Tip_categorie varchar2(20) unique,
    calator_id integer,
    CONSTRAINT categorie_fk FOREIGN KEY(calator_id) REFERENCES CALATOR(calator_id)
);

create table BILET(
    bilet_id integer primary key,
    Pret FLOAT,
    Data_eliberare date not null,
    Reducere integer,
    Valabilitate_zile integer default '31',
    Are_reducere integer,
    check (Are_reducere in (0,1))
);


insert into BILET
values(1,2,to_date('19.06.2022'),3,2,1);

insert into BILET
values(2,10,to_date('20.01.2002'),10,11,1);

insert into BILET
values(3,20,to_date('03.10.2009'),0,5,0);

insert into BILET
values(4,7.5,to_date('20.12.2021'),0,1,0);

insert into BILET
values(5,2.5,to_date('10.03.2012'),10,15,1);


insert into CALATOR
values(1,'Cheval Chevrolet',12,'Elev');

insert into CALATOR
values(2,'Pateu Ion',42,'Student');

insert into CALATOR
values(3,'Alexandrion Alcool',20,'Student');

insert into CALATOR
values(4,'Harry Potter',20,'Pensionar');

insert into CALATOR
values(5,'Podani Teodora',19,'Student');


insert into FIRMA
values (1,'Stat',0);

insert into FIRMA
values (2,'Privat',1);

insert into FIRMA
values (3,'Stat',0);

insert into FIRMA
values (4,'Stat',1);

insert into FIRMA
values (5,'Privat',1);


insert into CONT
values(1,2,to_date('19.06.2022'),'Miclaus');

insert into CONT
values(2,10,to_date('20.01.2002'),'Chevy');

insert into CONT
values(3,20,to_date('03.10.2009'),'Cercel');

insert into CONT
values(4,7.5,to_date('20.12.2021'),'CFR BOSS');

insert into CONT
values(5,2.5,to_date('10.03.2012'),'Miclaus');


insert into OPERATOR
VALUES(1,'Miclaus',2,10,10,1);

insert into OPERATOR
VALUES(2,'Alex Velea',3,15,2,2);

insert into OPERATOR
VALUES(3,'Little Poof',10,10,10,3);

insert into OPERATOR
VALUES(4,'Florinel Coman',2,10,10,1);

insert into OPERATOR
VALUES(5,'Gabriel',3,7,10,1);


insert into CATEGORIE
VALUES(1,'Student',3);

insert into CATEGORIE
VALUES(2,'Pensionar',1);

insert into CATEGORIE
VALUES(3,'Elev',3);

insert into CATEGORIE
VALUES(4,'Adult',2);

insert into CATEGORIE
VALUES(5,'Student',4);


insert into CALATORIE
values(1,'Iasi',3,10,8,1);

insert into CALATORIE
values(2,'Hawaii',2,1,5,2);

insert into CALATORIE
values(3,'Toronto',1,5,2,7);

insert into CALATORIE
values(4,'Isis',1,1,2,3);

insert into CALATORIE
values(5,'Bucharest',1,2,3,4);

insert into CALATORIE
values(6,'Praga',2,5,3,1);

insert into CALATORIE
values(7,'Cluj',1,5,8,1);

insert into CALATORIE
values(8,'Ibitza',2,1,2,4);

insert into CALATORIE
values(9,'Memetel',1,5,8,1);

insert into CALATORIE
values(10,'Slobozia',4,3,2,1);


insert into NATIONALA
values(1,0,'Isis',1,1,2);

insert into NATIONALA
values(2,1,'Bucharest',1,2,1);

insert into NATIONALA
values(6,1,'Praga',2,5,3);

insert into NATIONALA
values(4,0,'Cluj',1,5,8);

insert into NATIONALA
values(5,1,'Ibitza',2,1,2);


insert into INTERNATIONALA
values(6,0,'Isis',1,1,2);

insert into INTERNATIONALA
values(7,1,'Budapesta',1,2,1);

insert into INTERNATIONALA
values(8,1,'Paris',2,5,3);

insert into INTERNATIONALA
values(9,0,'Londra',1,5,8);

insert into INTERNATIONALA
values(10,1,'Stockholm',2,1,2);

--Afisarea primei litere din numele operatorilor care lucreaza la o firma de stat cu ID-ul 1. Sa se specifice daca
--initiala operatorului este 'M'

select distinct SUBSTR(Nume,1,1) as initiala,UPPER(Nume) Nume,
CASE WHEN SUBSTR(Nume,1,1)='M' then 'Initiala este M'
else 'Initiala nu este M'
end as VerficareInitiala
from OPERATOR o, FIRMA f
where o.firma_id=1 AND f.tip_firma='Stat' order by UPPER(Nume);

--Afisarea destinatiei calatoriilor, data eliberarii de pe bilet si numarul de luni de cand biletul s-a eliberat  
--in care pretul este maxim si reducerea nu se aplica pe bilet. Sa se verifice daca biletul a fost eliberat in data curenta.

select NVL(destinatie,'Nu exista'),data_eliberare, ROUND(MONTHS_BETWEEN(sysdate,data_eliberare)) as Luni, 
DECODE(data_eliberare,sysdate,'Eliberat astazi', 'Nu a fost eliberat astazi') Verificare
from CALATORIE c join BILET b on c.bilet_id = b.bilet_id
where b.pret in (select MAX(pret) from BILET b join CALATORIE C on c.bilet_id = b.bilet_id) and b.reducere=0;

select * from CALATOR;
select * from CATEGORIE;

--Afisarea numelui calatorilor lor pentru calatorii care sunt studenti.

with tabelaTemporara as
    (select c1.nume AS rezultat
    from CALATOR c1,CATEGORIE c2
    where c1.calator_id=c2.calator_id and c2.tip_categorie='Student'
    Group by c1.nume,c1.calator_id)

select rezultat from tabelaTemporara;

--Afisarea anului din data de eliberare a unui bilet unde durata calatoriei este mai mare decat 3.

select EXTRACT(year from b.data_eliberare) Anul_eliberarii
from CALATORIE c join BILET b on c.bilet_id = b.bilet_id
where c.durata_zile>3;

--Afisarea pretului biletelui unde destinatia este Bucuresti.

select b.pret Pret
from CALATORIE c join BILET b on c.bilet_id = b.bilet_id
where c.destinatie='Bucharest';

update BILET set pret = pret-reducere*pret/100;

update BILET set pret = pret+ (select avg(pret) from BILET); 

update BILET set reducere = reducere + (select count(*) from BILET);

CREATE SEQUENCE seq_calatorie
start with 100
INCREMENT BY 1
NOMAXVALUE
NOCYCLE
NOCACHE;
INSERT INTO CALATORIE VALUES (seq_calatorie.nextval, 'Alexandria', 3,4,1,2);
INSERT INTO CALATORIE VALUES (seq_calatorie.nextval, 'Campina', 10,2,3,1);
INSERT INTO CALATORIE VALUES (seq_calatorie.nextval, 'Galati', 7,1,2,1);
SELECT * FROM CALATORIE;

CREATE VIEW pret_mediu as
select pret,bilet_id 
from BILET
where pret >(select avg(pret) from bilet);

select * from pret_mediu;
