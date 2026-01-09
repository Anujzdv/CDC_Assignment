# Write your MySQL query statement below
SELECT
    t.Request_at as day,
    round(
        sum(case
            when t.Status in ('cancelled_by_client', 'cancelled_by_driver')
            then 1 else 0
            end
        ) / count(*),
        2
    ) as "Cancellation Rate"
from Trips t 
join Users c on t.Client_Id = c.Users_Id and c.Banned = 'No'
join Users d on t.Driver_id = d.Users_Id and d.Banned = 'No'
where t.Request_at between '2013-10-01' AND '2013-10-03'
group by t.Request_at;