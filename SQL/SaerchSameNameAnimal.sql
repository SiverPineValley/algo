-- 프로그래머스
-- SQL - 동명 동물 수 찾기
SELECT NAME, count(*) AS count from ANIMAL_INS
where NAME is not NULL
group by NAME
having count(NAME) >= 2
order by NAME asc;