--5
select employee_id, first_name,job_id,hire_date from employees;

--6
select employee_id as cod, first_name as nume,job_id as cod_job,hire_date as data_angajarii 
from employees;

--7
select unique job_id from employees;

--8
select first_name || ', ' || job_id as "Angajat si titlu" from employees;

--9 (cu ce mai trebuie)
select employee_id || ', ' || first_name || ', ' || last_name as "Date complete"
from employees;

--10
select first_name, last_name, salary from employees
where salary>2850;

--11
select first_name,department_id from employees where employee_id=104;

--12
select first_name,salary from employees where salary<1500 and salary>2850;

--13
select first_name,job_id,hire_date
from employees
where hire_date between '20.02.1987' and '1-05.1989'
order by hire_date;

--14
select first_name,department_id
from employees
where department_id=10 or department_id=30 or department_id=50
order by first_name;

select first_name as "Angajat", salary as "salariu lunar"
from employees
where salary>1500 and department_id in (10,30,50);

--15
select sysdate from dual;

--17
select first_name,hire_date
from employees
where hire_date like '%87%';

--18
select first_name,last_name,hire_date
from employees
where to_char(hire_date,'MM')=to_char(sysdate,'MM');

--19
select first_name,job_id
from employees
where manager_id is null;

--20
select first_name,salary,commission_pct
from employees
where commission_pct is not null
order by salary,commission_pct desc;

--22
select first_name
from employees
where first_name like '__a%';

--23
select first_name
from employees
where first_name like '%l%l%' and department_id=30 and manager_id=102;

--24
select first_name, job_id, salary
from employees
where job_id like('%CLERK%') OR job_id like('%REP%') AND salary not in (1000,2000,3000);

--25
select department_id
from employees
where manager_id is null;