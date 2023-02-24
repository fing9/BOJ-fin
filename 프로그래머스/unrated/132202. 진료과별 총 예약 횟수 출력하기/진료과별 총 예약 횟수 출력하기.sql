-- 코드를 입력하세요
SELECT  MCDP_CD AS 진료과코드,
        COUNT(*) AS 5월예약건수
FROM    APPOINTMENT
WHERE   APNT_YMD like "2022-05-%"
GROUP BY    진료과코드
ORDER BY    5월예약건수,
            진료과코드