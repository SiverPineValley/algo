-- 프로그래머스
-- SQL - 고양이와 개는 몇마리 있을까
SELECT ANIMAL_TYPE, count(*) AS count from ANIMAL_INS
group by ANIMAL_TYPE
order by ANIMAL_TYPE asc;