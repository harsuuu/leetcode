# Write your MySQL query statement below
select firstName,lastName,city,state from Person P left join Address A on P.personId=A.personId;