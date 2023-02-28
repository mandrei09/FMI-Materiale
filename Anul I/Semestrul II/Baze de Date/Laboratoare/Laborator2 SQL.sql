--1
select concat(last_name,concat(' ',concat(first_name,concat(' castiga ',concat(salary, concat(' lunar dar doreste ',salary*3)))))) as "Salariu ideal"
from employees;

--2 
select 
    initcap(first_name) as col1,
    --initiala este majuscula in rest minuscule
    upper(last_name) as col2
    --,lenght(last_name)
from 
    employees
where  
    last_name like ('J%')  
    or last_name like ('M%') 
    or last_name not like('__a%');
--order by len(last_name) desc;

--3
select 
    employee_id as cod,
    last_name as nume
from 
    employees
where 
    upper(first_name)='STEVEN';

--4
select
    employee_id as cod, 
    last_name as nume,
    --lenght(last_name) as lungime,
    instr(lower(last_name),'a',1) as pozitie 
        --a cata pozitie o ocupa 'a' in last_name
from 
    employees
where 
    lower(last_name) like ('%e');

--5
select 
    first_name as nume
from 
    employees
where 
    mod(round(sysdate-hire_date),7)=0;

--6
select 
    employee_id,
    first_name,
    salary,
    round(salary+(salary*15)/100,2) as "Salariu nou",
    round(mod(salary,1000),2) as "Numar sute"
from 
    employees
where 
    mod(salary,1000)!=0;
    
--7
select
    first_name as "Nume angajat",
    hire_date as "Data angajarii"
from 
    employees
where 
    commission_pct is not null;
    
--8???
--select
--    month(sysdate)
--from
--    dual;

--9
select
    round(to_date('31.12.2022')-sysdate)
from 
    dual;
    
--10

--11
select
    concat(first_name,concat(' ',last_name)),
    hire_date,
    next_day(add_months(hire_date,6),'Luni') as negociere
from employees;

--12
select
    first_name,
    floor((sysdate-hire_date)/30) as "Luni lucrate"
from employees
order by floor((sysdate-hire_date)/30);

--13?

--17
select
    e.first_name,
    e.employee_id,
    d.department_name
from 
    employees e,departments d
where 
    e.department_id=d.department_id;
    
--18
select
    e.job_id,
    j.job_title
from
    jobs j, employees e
where
    e.job_id=j.job_id and e.department_id=30;
    
--19
select
    e.first_name,
    d.department_name,
    d.location_id
from departments d, employees e
where d.department_id=e.department_id;

--20
select
    e.first_name,
    d.department_name
from departments d, employees e
where 
    d.department_id=e.department_id
    and lower(e.first_name) like ('%a%');
    
--21
select
    e.first_name,
    j.job_title,
    d.department_name
from 
    departments d, 
    employees e, 
    jobs j, 
    locations l
where 
    d.department_id=e.department_id 
    and e.job_id=j.job_id
    and l.location_id=d.location_id
    and l.city='Oxford';
    
--22
select
    e.employee_id as "Ang#",
    e.first_name as "Angajat",
    e.manager_id as "Mgr#",
    m.first_name as "Mangager"
from 
    employees e,
    employees m
where
    e.manager_id=m.employee_id;
    
--23
select
    e.employee_id as "Ang#",
    e.first_name as "Angajat",
    e.manager_id as "Mgr#",
    m.first_name as "Mangager"
from 
    employees e, employees m
full outer join 
    employees on e.manager_id=m.employee_id;

--24
select
    e.first_name,
    e.department_id,
    d.first_name
from 
    employees e,
    employees d
where e.department_id=d.department_id;

--25 ??
select
    e.first_name,
    j.job_id,
    j.job_title,
    d.department_name,
    e.salary
from
    employees e, jobs j,departments d
full outer join employees on
    e.job_id=j.job_id
full outer join departments on
    d.department_id=e.department_id;
    
--26
select
    first_name,
    hire_date
from 
    employees
where
    hire_date>(
    select
        hire_date
    from employees
    where 
        last_name='Gates');
        
--27
select
    e.first_name as "Angajat",
    e.hire_date as "Data_ang",
    m.first_name as "Manager",
    m.hire_date as "Data_mgr"
from 
    employees e,
    employees m
where
    e.manager_id=m.employee_id and e.hire_date<m.hire_date;

    
    
    

    





    
    
