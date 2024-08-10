# Write your MySQL query statement below
select name as Employee from employee as e where managerId is not null and salary > (select salary from employee where id = e.managerId);