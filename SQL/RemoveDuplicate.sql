-- 프로그래머스
-- SQL - 동물 수 구하기
SELECT count(*) AS count
from (
    SELECT NAME from ANIMAL_INS
    group by NAME
    having NAME is not NULL
) AS NAME_TABLE;