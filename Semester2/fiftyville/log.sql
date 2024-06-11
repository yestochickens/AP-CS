-- Keep a log of any SQL queries you execute as you solve the mystery.

--To look at the logs of the crime scene
SELECT * FROM crime_scene_reports;

--To look at the logs of who entered and exited the store on the day of the robbery
SELECT * FROM bakery_security_logs WHERE day = 28;

--Interviews from the day of the theft
SELECT * FROM interviews WHERE day = 28;

--I found all the license_plate numbers that left the store within 10 minutes of robbery because the interviewer said
SELECT license_plate FROM bakery_security_logs WHERE (day = 28) AND (hour = 10) AND (15 <= minute AND minute <= 25);

--Track the phone calls that were made less that 60 seconds on that day
SELECT * FROM phone_calls WHERE DAY = 28 AND duration <= 60;

--Finds the first flight out of fiftyville on the 29th
SELECT * FROM flights WHERE origin_airport_id IN(SELECT id FROM airports WHERE city = "Fiftyville" and day = 29) ORDER BY hour LIMIT 1;

--Finds the city they are landing in
SELECT city FROM airports WHERE id = 4;
--City is New York

--find the people that called for less than 60 seconds that day and left 10 minutes after the robbery
SELECT name FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE (day = 28) AND (hour = 10) AND (15 <= minute AND minute <= 25)) AND phone_number IN (SELECT caller FROM phone_calls WHERE DAY = 28 AND duration <= 60);
-- Possible people are Sofia, Diana, Kelsey, Bruce

--Look at who withdrew money on that day
SELECT name FROM people WHERE id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE day = 28 and atm_location = "Leggett Street"));
--Diana and Bruce were the only ones that matched from the searches before

--Withdrew money on that day, drive away within 10 miutes, is flying out on the flight on the 29th (id 36), called for less than 60 seconds
SELECT name FROM people
WHERE id IN
(SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE day = 28 and atm_location = "Leggett Street"))
AND
license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE (day = 28) AND (hour = 10) AND (15 <= minute AND minute <= 25))
AND
phone_number IN (SELECT caller FROM phone_calls WHERE DAY = 28 AND duration <= 60)
and passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = 36);
--Outputs Bruce

--Find out whats bruce's phone number is
SELECT phone_number FROM people WHERE name = "Bruce";
--Outputs (367) 555-5533

--Find out who he was calling for less than 60 seconds on the 28th
SELECT * FROM phone_calls WHERE caller = "(367) 555-5533" AND day = 28 AND duration <= 60;
--Receiver is (375) 555-8161

-- Find out their name
SELECT name FROM people WHERE phone_number = "(375) 555-8161";
-- Output Robin
