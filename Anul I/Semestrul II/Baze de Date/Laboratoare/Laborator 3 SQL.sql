--1
select
    first_name,
    hire_date,
    department_id
from employees
where department_id= (
    select 
        department_id
    from employees
    where 
        last_name='Gates')
    and lower(first_name) like ('%a%');

--2
select
    e.employee_id,
    e.first_name,
    d.department_id,
    d.department_name
from
    employees e,
    departments d
where
    d.department_id=e.department_id 
    and e.department_id in (
        select
            department_id
        from employees
        where
            lower(first_name) like ('%t%'))
order by e.first_name;

--3
select
    e.first_name,
    e.salary,
    j.job_title,
    l.city,
    l.state_province
from
    employees e, 
    jobs j, 
    locations l,
    departments d
where
    e.job_id=j.job_id 
    and d.department_id=e.department_id 
    and d.location_id=l.location_id
    and e.manager_id in
        (select
            employee_id
        from 
            employees
        where
            lower(last_name)='king');
            
--4
select
    d.department_id,
    d.department_name,
    e.first_name,
    j.job_title,
    concat('$',e.salary) as SALARY
from 
    employees e,
    departments d,
    jobs j
where
    e.department_id=d.department_id
    and e.job_id=j.job_id
    and d.department_name in 
        (select 
            department_name
        from 
            departments
        where 
            department_name like ('%ti%'))
order by
    d.department_name,e.first_name;
    
--5
select
    e.first_name,
    d.department_id,
    d.department_name,
    l.city,
    j.job_title
from
    employees e, 
    departments d, 
    locations l, 
    jobs j
where
    d.department_id=e.department_id
    and e.job_id=j.job_id 
    and d.location_id=l.location_id
    and d.location_id in(
        select 
            location_id
        from 
            locations
        where
            lower(city)='oxford');
            
--6
select
    employee_id,
    first_name,
    salary
from
    employees 
where
    salary>  (
        select
            round(avg(salary))
        from employees)
    and department_id in 
        (select 
            department_id
        from employees
        where
            lower(first_name) like ('%t%'))
order by first_name;

--7
select 
    e.first_name,
    d.department_name
from
    employees e
left outer join 
    departments d on 
        e.department_id=d.department_id;

--9
select 
    e.first_name,
    d.department_name
from
    employees e
right outer join 
    departments d on 
        e.department_id=d.department_id;
        
--11
select
    department_id
from 
    departments
where
    lower(department_name) like('%re%')
union
select
    d.department_id
from 
    departments d, 
    employees e
where 
    e.department_id=d.department_id 
    and e.job_id='SA_REP';
    
--12
select
    department_id
from 
    departments
where
    lower(department_name) like('%re%')
union ALL
select
    d.department_id
from 
    departments d, 
    employees e
where 
    e.department_id=d.department_id 
    and e.job_id='SA_REP';
    
--13??
--select
--    department_id
--from 
--    departments
--where

--14 la fel ca la 12 doar ca are intersect

--18
select
    

    
            
    