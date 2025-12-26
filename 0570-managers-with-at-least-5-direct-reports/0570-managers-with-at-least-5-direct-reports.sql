# Write your MySQL query statement below
select t.name
from ( select a.id, a.name
    from Employee as a
    left join Employee as b
    on a.id = b.managerId
    where b.managerId is not null ) t
group by t.id
HAVING COUNT(*) >= 5;