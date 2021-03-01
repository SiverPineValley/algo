-- 프로그래머스
-- SQL - 아픈 동물 찾기
SELECT ANIMAL_ID, NAME from ANIMAL_INS
where INTAKE_CONDITION like '%Sick'
order by ANIMAL_ID